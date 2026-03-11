#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "py/builtin.h"
#include "py/misc.h"
#include "py/compile.h"
#include "py/runtime.h"
#include "py/repl.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "py/mphal.h"
#include "shared/runtime/pyexec.h"
#include "genhdr/mpversion.h"
#include "genhdr/amigaversion.h"

#include <proto/dos.h>

// Tell AmigaOS/libnix to allocate a 128 KB stack for this process.
long __stack = 131072;

static char *stack_top;
static char heap[MICROPY_HEAP_SIZE];

// quit() and exit() builtins — raise SystemExit
static mp_obj_t mp_builtin_quit(size_t n_args, const mp_obj_t *args) {
    if (n_args == 0) {
        mp_raise_type(&mp_type_SystemExit);
    } else {
        mp_raise_type_arg(&mp_type_SystemExit, args[0]);
    }
}
MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mp_builtin_quit_obj, 0, 1, mp_builtin_quit);
MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mp_builtin_exit_obj, 0, 1, mp_builtin_quit);

// Line-buffered REPL using mp_hal_readline (fgets) + mp_repl_continue_with_input.
static void do_repl(void) {
    mp_hal_stdout_tx_str("MicroPython " MICROPY_GIT_TAG " on " AMIGA_BUILD_TIMESTAMP
        " build " AMIGA_BUILD_NUM "; " MICROPY_BANNER_MACHINE "\n");
    mp_hal_stdout_tx_str("Use quit() or Ctrl-C to exit\n");

    for (;;) {
        vstr_t line;
        vstr_init(&line, 32);
        int ret = mp_hal_readline(&line, ">>> ");
        if (ret == 4) {  // Ctrl-D / EOF
            vstr_clear(&line);
            break;
        }

        // Check for Ctrl-C
        if (line.len == 1 && vstr_str(&line)[0] == '\x03') {
            vstr_clear(&line);
            break;
        }

        // Multi-line input (if/for/def/class blocks)
        while (mp_repl_continue_with_input(vstr_null_terminated_str(&line))) {
            vstr_t extra;
            vstr_init(&extra, 32);
            ret = mp_hal_readline(&extra, "... ");
            if (ret == 4) {
                vstr_clear(&extra);
                break;
            }
            vstr_add_char(&line, '\n');
            vstr_add_strn(&line, vstr_str(&extra), extra.len);
            vstr_clear(&extra);
        }

        if (line.len > 0) {
            mp_lexer_t *lex = mp_lexer_new_from_str_len(
                MP_QSTR__lt_stdin_gt_,
                vstr_str(&line), line.len, 0);
            if (lex == NULL) {
                vstr_clear(&line);
                continue;
            }

            nlr_buf_t nlr;
            if (nlr_push(&nlr) == 0) {
                qstr source_name = lex->source_name;
                mp_parse_tree_t parse_tree = mp_parse(lex, MP_PARSE_SINGLE_INPUT);
                mp_obj_t module_fun = mp_compile(&parse_tree, source_name, true);
                mp_call_function_0(module_fun);
                nlr_pop();
            } else {
                if (mp_obj_is_subclass_fast(
                        MP_OBJ_FROM_PTR(((mp_obj_base_t *)nlr.ret_val)->type),
                        MP_OBJ_FROM_PTR(&mp_type_SystemExit))) {
                    vstr_clear(&line);
                    break;
                }
                mp_obj_print_exception(&mp_plat_print, (mp_obj_t)nlr.ret_val);
            }
        }
        vstr_clear(&line);
    }

    mp_hal_stdout_tx_str("Bye!\n");
}

// Execute a .py script file. Returns 0 on success, non-zero on error.
static int do_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: cannot open file '%s'\n", filename);
        return 1;
    }
    fclose(f);
    int ret = pyexec_file(filename);
    return ret == 0 ? 1 : 0; // pyexec_file returns 1 on success
}

// Initialise the VM and populate sys.argv.
static void vm_init(int argc, char **argv) {
    gc_init(heap, heap + sizeof(heap));
    mp_init();
    mp_obj_list_init(MP_OBJ_TO_PTR(mp_sys_argv), 0);
    for (int i = 0; i < argc; i++) {
        mp_obj_list_append(mp_sys_argv, MP_OBJ_NEW_QSTR(qstr_from_str(argv[i])));
    }
}

int main(int argc, char **argv) {
    int stack_dummy;
    stack_top = (char *)&stack_dummy;

    // Save the shell's current directory lock so we can restore it on exit.
    BPTR original_dir = CurrentDir(0);
    CurrentDir(original_dir);

    int ret = 0;
    if (argc > 1) {
        // Execute each .py file with a fresh VM to avoid qstr pool overflow.
        for (int i = 1; i < argc; i++) {
            vm_init(argc, argv);
            ret = do_file(argv[i]);
            mp_deinit();
            if (ret != 0) {
                break;
            }
        }
    } else {
        vm_init(argc, argv);
        do_repl();
        mp_deinit();
    }

    // Restore the shell's original directory.
    CurrentDir(original_dir);

    return ret;
}

void gc_collect(void) {
    void *dummy;
    gc_collect_start();
    gc_collect_root(&dummy, ((mp_uint_t)stack_top - (mp_uint_t)&dummy) / sizeof(mp_uint_t));
    gc_collect_end();
}

mp_lexer_t *mp_lexer_new_from_file(qstr filename) {
    const char *fname = qstr_str(filename);
    FILE *f = fopen(fname, "r");
    if (f == NULL) {
        mp_raise_OSError(MP_ENOENT);
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buf = m_new(char, size + 1);
    long got = fread(buf, 1, size, f);
    fclose(f);
    buf[got] = '\0';
    return mp_lexer_new_from_str_len(filename, buf, got, got + 1);
}

// Stub for open() — no filesystem support yet
mp_obj_t mp_builtin_open(size_t n_args, const mp_obj_t *args, mp_map_t *kwargs) {
    (void)n_args;
    (void)args;
    (void)kwargs;
    mp_raise_OSError(MP_ENOENT);
}
MP_DEFINE_CONST_FUN_OBJ_KW(mp_builtin_open_obj, 1, mp_builtin_open);

mp_import_stat_t mp_import_stat(const char *path) {
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        return MP_IMPORT_STAT_NO_EXIST;
    }
    fclose(f);
    return MP_IMPORT_STAT_FILE;
}

void nlr_jump_fail(void *val) {
    (void)val;
    printf("FATAL: uncaught NLR\n");
    exit(1);
}

#ifndef NDEBUG
void __assert_func(const char *file, int line, const char *func, const char *expr) {
    (void)func;
    printf("Assertion '%s' failed, at file %s:%d\n", expr, file, line);
    exit(1);
}
#endif
