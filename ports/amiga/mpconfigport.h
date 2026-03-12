#include <stdint.h>

// Disable assertions (gc.c:952 triggers on m68k due to stack scan false positives)
#define NDEBUG

// MicroPython port configuration for AmigaOS m68k

// Use core features level - gives us a useful REPL without bloat
#define MICROPY_CONFIG_ROM_LEVEL        (MICROPY_CONFIG_ROM_LEVEL_CORE_FEATURES)

// Compiler and REPL
#define MICROPY_ENABLE_COMPILER         (1)
#define MICROPY_ENABLE_GC               (1)
#define MICROPY_HELPER_REPL             (1)
#define MICROPY_ENABLE_EXTERNAL_IMPORT  (1)
#define MICROPY_PY_BUILTINS_INPUT       (1)

// No readline for now; use line-buffered (cooked) input from AmigaOS console
#define MICROPY_USE_READLINE            (0)

// Use setjmp-based NLR (no native m68k NLR implementation)
#define MICROPY_NLR_SETJMP              (1)

// Frozen modules: controlled by FROZEN_MANIFEST in Makefile.
// When set, mkrules.mk defines MICROPY_MODULE_FROZEN_MPY and
// MICROPY_QSTR_EXTRA_POOL automatically via CFLAGS.

// Memory
#define MICROPY_ALLOC_PATH_MAX          (256)
#define MICROPY_ALLOC_PARSE_CHUNK_INIT  (16)
#define MICROPY_ALLOC_QSTR_CHUNK_INIT   (2048)
#define MICROPY_QSTR_BYTES_IN_LEN       (2)
#define MICROPY_QSTR_BYTES_IN_HASH      (2)
#define MICROPY_HEAP_SIZE               (512 * 1024) // 512 KB

// Disable features requiring POSIX or threading
#define MICROPY_PY_THREAD               (0)
#define MICROPY_EMIT_X64                (0)
#define MICROPY_EMIT_X86                (0)
#define MICROPY_EMIT_THUMB              (0)
#define MICROPY_EMIT_ARM                (0)
#define MICROPY_EMIT_INLINE_THUMB       (0)
#define MICROPY_EMIT_INLINE_THUMB_FLOAT (0)
#define MICROPY_VFS_POSIX               (0)
#define MICROPY_PY_FFI                  (0)
#define MICROPY_PY_SOCKET               (0)
#define MICROPY_PY_TERMIOS              (0)
#define MICROPY_PY_SELECT               (0)
#define MICROPY_PY_SIGNAL               (0)

// Disable sys features not useful on AmigaOS
#define MICROPY_PY_SYS_MODULES          (0)
#define MICROPY_PY_SYS_EXIT             (1)
// sys.path is required for frozen module imports (.frozen/ prefix)
#define MICROPY_PY_SYS_PATH             (1)
#define MICROPY_PY_SYS_ARGV             (1)
#define MICROPY_PY_SYS_PLATFORM         (1)

// Arbitrary-precision integers (needed by frozen datetime module)
#define MICROPY_LONGINT_IMPL            (MICROPY_LONGINT_IMPL_MPZ)

// Enable useful builtins and modules
#define MICROPY_PY_MATH                 (1)
#define MICROPY_FLOAT_IMPL              (MICROPY_FLOAT_IMPL_FLOAT)
#define MICROPY_PY_IO                   (1)
#define MICROPY_PY_OS                   (0)
#define MICROPY_PY_RE                   (1)
#define MICROPY_PY_JSON                 (1)
#define MICROPY_PY_BINASCII             (1)
#define MICROPY_PY_BUILTINS_BYTES_HEX  (1)
#define MICROPY_PY_TIME                 (1)
#define MICROPY_PY_TIME_GMTIME_LOCALTIME_MKTIME (1)
#define MICROPY_PY_TIME_TIME_TIME_NS    (1)
#define MICROPY_PY_TIME_INCLUDEFILE     "ports/amiga/modtime.c"
#define MICROPY_EPOCH_IS_1970           (1)

// quit() and exit() builtins
extern const struct _mp_obj_fun_builtin_var_t mp_builtin_quit_obj;
extern const struct _mp_obj_fun_builtin_var_t mp_builtin_exit_obj;
#define MICROPY_PORT_BUILTINS \
    { MP_ROM_QSTR(MP_QSTR_quit), MP_ROM_PTR(&mp_builtin_quit_obj) }, \
    { MP_ROM_QSTR(MP_QSTR_exit), MP_ROM_PTR(&mp_builtin_exit_obj) },

// GC uses setjmp to capture registers
#define MICROPY_GCREGS_SETJMP           (1)

// Type definitions for m68k
typedef int32_t mp_int_t;
typedef uint32_t mp_uint_t;
typedef long mp_off_t;

#define MP_SSIZE_MAX INT32_MAX

// We need alloca
#include <alloca.h>

#define MICROPY_HW_BOARD_NAME           "Amiga"
#define MICROPY_HW_MCU_NAME             "M68020"


#define MP_STATE_PORT MP_STATE_VM
