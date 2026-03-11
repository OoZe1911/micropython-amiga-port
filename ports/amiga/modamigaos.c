// Standalone 'os' module for the AmigaOS port.
// Replaces the generic extmod os module (MICROPY_PY_OS=0).
// Uses dos.library for filesystem operations.

#include <stdlib.h>
#include <string.h>

#include "py/runtime.h"
#include "py/objstr.h"
#include "py/mperrno.h"

#include <proto/dos.h>
#include <dos/dos.h>

// os.listdir([path]) — list directory contents using Examine/ExNext.
static mp_obj_t mod_os_listdir(size_t n_args, const mp_obj_t *args) {
    const char *path = (n_args == 0) ? "" : mp_obj_str_get_str(args[0]);

    BPTR lock = Lock((CONST_STRPTR)path, SHARED_LOCK);
    if (lock == 0) {
        mp_raise_OSError(MP_ENOENT);
    }

    struct FileInfoBlock *fib = AllocDosObject(DOS_FIB, NULL);
    if (fib == NULL) {
        UnLock(lock);
        mp_raise_OSError(MP_ENOMEM);
    }

    mp_obj_t list = mp_obj_new_list(0, NULL);

    if (Examine(lock, fib)) {
        while (ExNext(lock, fib)) {
            const char *name = (const char *)fib->fib_FileName;
            mp_obj_list_append(list, mp_obj_new_str(name, strlen(name)));
        }
    }

    FreeDosObject(DOS_FIB, fib);
    UnLock(lock);

    return list;
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mod_os_listdir_obj, 0, 1, mod_os_listdir);

// os.getcwd() — return current directory name.
static mp_obj_t mod_os_getcwd(void) {
    char buf[256];
    // Use NameFromLock on the actual current dir lock set by CurrentDir().
    // GetCurrentDirName() reads the CLI structure which is NOT updated
    // by CurrentDir(), so it would return a stale value after chdir().
    BPTR lock = CurrentDir(0);
    CurrentDir(lock); // restore
    if (lock && NameFromLock(lock, (STRPTR)buf, sizeof(buf))) {
        return mp_obj_new_str(buf, strlen(buf));
    }
    // lock==0 means boot volume root
    if (lock == 0) {
        return mp_obj_new_str("SYS:", 4);
    }
    mp_raise_OSError(MP_ENOENT);
}
static MP_DEFINE_CONST_FUN_OBJ_0(mod_os_getcwd_obj, mod_os_getcwd);

// os.chdir(path) — change current directory.
static mp_obj_t mod_os_chdir(mp_obj_t path_in) {
    const char *path = mp_obj_str_get_str(path_in);
    BPTR new_lock = Lock((CONST_STRPTR)path, SHARED_LOCK);
    if (new_lock == 0) {
        mp_raise_OSError(MP_ENOENT);
    }
    CurrentDir(new_lock);
    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_1(mod_os_chdir_obj, mod_os_chdir);

// os.system(cmd) — execute a shell command.
static mp_obj_t mod_os_system(mp_obj_t cmd_in) {
    const char *cmd = mp_obj_str_get_str(cmd_in);
    int r = system(cmd);
    return MP_OBJ_NEW_SMALL_INT(r);
}
static MP_DEFINE_CONST_FUN_OBJ_1(mod_os_system_obj, mod_os_system);

static const mp_rom_map_elem_t os_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_os) },
    { MP_ROM_QSTR(MP_QSTR_listdir), MP_ROM_PTR(&mod_os_listdir_obj) },
    { MP_ROM_QSTR(MP_QSTR_getcwd), MP_ROM_PTR(&mod_os_getcwd_obj) },
    { MP_ROM_QSTR(MP_QSTR_chdir), MP_ROM_PTR(&mod_os_chdir_obj) },
    { MP_ROM_QSTR(MP_QSTR_system), MP_ROM_PTR(&mod_os_system_obj) },
    { MP_ROM_QSTR(MP_QSTR_sep), MP_ROM_QSTR(MP_QSTR__slash_) },
};
static MP_DEFINE_CONST_DICT(os_module_globals, os_module_globals_table);

const mp_obj_module_t mp_module_amiga_os = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&os_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_os, mp_module_amiga_os);
