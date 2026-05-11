# MicroPython AmigaOS m68k Port

## Build

Cross-compiler: `/opt/amiga/bin/m68k-amigaos-gcc` (GCC 6.5.0b, bebbo toolchain).

Prerequisites: mpy-cross must be compiled first (one-time):

```
cd mpy-cross && gmake       # builds the .py -> .mpy cross-compiler
```

Then:

```
cd ports/amiga
gmake              # incremental build
gmake clean        # full clean
gmake V=1          # verbose build
```

The binary `build/micropython` is an AmigaOS hunk executable (magic `0x000003f3`),
directly runnable on Amiga 68020+ or in an emulator.

Build number auto-increments on each compilation (stored in `.build_number`).
Banner example: `MicroPython v1.28.0 on 2026-04-10 18:00 build 42; Amiga with M68020`

Compiler flags:
- `-noixemul`: uses libnix instead of ixemul.library (no POSIX emulation)
- `-m68020`: minimum 68020 instruction set
- `-O2`: standard optimization
- `-fdata-sections -ffunction-sections` + `-Wl,--gc-sections`: dead code elimination

## Port Architecture

### Files

| File | Role |
|------|------|
| `Makefile` | Cross-compiled build, py.mk + extmod.mk inclusion, build number |
| `mpconfigport.h` | MicroPython feature configuration for AmigaOS |
| `mphalport.h` | HAL: ticks stubs, delays, time_ns, raw/cooked mode switch, MP_HAL_RETRY_SYSCALL |
| `main.c` | Entry point, custom REPL with readline, dynamic heap via AllocMem, -c/-m options, VFS mount, curdir save/restore |
| `amiga_mphal.c` | Console I/O: raw mode Read(Input())/Write(Output()), CSI-to-ANSI translation, delays via usleep |
| `modamigaos.c` | Low-level `uos` C module (listdir, getcwd, chdir, mkdir, rmdir, remove, rename, stat, system, _stat_type) |
| `modsocket.c` | BSD socket module (socket, connect, bind, send, recv, getaddrinfo) via libsocket/bsdsocket.library |
| `modssl.c` | SSL/TLS module via AmiSSL (wrap_socket, custom BIO with saveds callbacks) |
| `modarexx.c` | ARexx IPC module (send, exists, ports) via rexxsyslib.library |
| `modintuition.c` | `amiga.intuition` sub-package: `easy_request()` / `auto_request()` / `message()` wrappers around EasyRequestArgs(); also hosts the parent `amiga` package registration |
| `modasl.c` | `amiga.asl` sub-package: `file_request()` wrapper around asl.library's FileRequester (open/save/multi-select/drawers-only) |
| `modzlib.c` | Native _zlib module with CRC32 for the frozen zlib module |
| `modtime.c` | Time implementation for AmigaOS (gmtime/localtime/time via libnix) |
| `qstrdefsport.h` | Port-specific qstrings (empty) |
| `manifest.py` | Frozen Python module declarations (base64, datetime, _ospath, os) |
| `modules/datetime.py` | Patched local copy of datetime (fixed __repr__, added strftime) |
| `modules/_ospath.py` | os.path implementation for AmigaOS path conventions |
| `modules/os.py` | Frozen os module: re-exports uos, adds makedirs() and walk(), imports _ospath as path |
| `modules/platform.py` | Frozen platform module: CPU/FPU/chipset/Kickstart detection via uos C helpers |
| `modules/urequests.py` | Frozen HTTP/1.1 client (GET, POST, PUT, DELETE, HEAD, chunked TE) |
| `modules/gzip.py` | Frozen gzip module: CPython-compatible compress()/decompress() |
| `modules/smtplib.py` | Frozen SMTP client: SMTP / SMTP_SSL, STARTTLS, AUTH PLAIN/LOGIN, sendmail/send_message |
| `modules/email/` | Frozen email package: Message, MIME{Base,Text,Multipart,Application}, Header, encoders, utils |
| `patches/` | Patches to upstream MicroPython files (alignment, iter_buf heap alloc, VFS POSIX Latin-1) |
| `run_tests.py` | Test runner: runs each test in a separate micropython process |

### Architecture Decisions

**Latin-1 ↔ UTF-8 encoding.** AmigaOS uses Latin-1 (ISO-8859-1) for filenames
and terminal output. MicroPython stores strings as UTF-8 internally. Bidirectional
conversion is implemented:
- `mp_obj_new_str_from_latin1()` (modamigaos.c): Latin-1 → UTF-8 for listdir/getcwd
- `get_latin1_path()` / `amiga_utf8_to_latin1()` (amiga_mphal.c): UTF-8 → Latin-1
  for all path-taking functions (Lock, CreateDir, SetProtection, etc.)
- `mp_hal_stdout_tx_strn()`: UTF-8 → Latin-1 for terminal output (print)
- `MICROPY_PY_OS_DUPTERM=1`: redirects VFS POSIX stdout/stderr through mphal
- `MICROPY_VFS_POSIX_CONVERT_PATH`: hook in vfs_posix.c/vfs_posix_file.c for
  open() and import path resolution

**No POSIX.** AmigaOS is not POSIX. All POSIX code from the unix port was removed:
no fork, no pthreads, no mmap, no POSIX signals, no termios, no select/poll.

**libnix (-noixemul).** Uses libnix which provides a minimal libc (malloc, stdio,
string, setjmp, time, gmtime, open, read, write, stat, opendir...) without
depending on ixemul.library. Consequence: `shared/libc/printf.c` and
`shared/libc/abort_.c` are excluded from the build via
`SRC_EXTMOD_C := $(filter-out shared/libc/%.c,$(SRC_EXTMOD_C))` in the Makefile,
since libnix already provides these symbols.

**NLR setjmp.** m68k has no native NLR implementation in MicroPython. The
`setjmp`/`longjmp` fallback is used (`MICROPY_NLR_SETJMP=1`). The GC also uses
setjmp to capture registers (`MICROPY_GCREGS_SETJMP=1`).

**Arbitrary-precision integers (MPZ).** `MICROPY_LONGINT_IMPL` is set to `MPZ`.
Required by the frozen `datetime` module which uses 64-bit integer constants for
epoch calculations.

**No native emitters.** All native emitters (x64, x86, thumb, ARM) are disabled.
MicroPython bytecode is interpreted only.

**ROM level EVERYTHING.** Maximum Python compatibility: f-strings, set operations,
OrderedDict, advanced slicing, descriptors, async/await, generators, and more.
Features not available on AmigaOS (threading, networking stack, native emitters,
machine module, alternative VFS, etc.) are explicitly disabled in mpconfigport.h.
`mp_stack_set_limit(40000)` is called in `vm_init()` (required because EVERYTHING
enables `MICROPY_STACK_CHECK`).

**VFS_POSIX for file I/O.** `MICROPY_VFS=1` and `MICROPY_VFS_POSIX=1` enable
full `open()`/`read()`/`write()`/`close()` support. The POSIX VFS is mounted at
`/` during `vm_init()`. libnix provides all required POSIX symbols (open, close,
read, write, stat, lseek, mkdir, rmdir, unlink, opendir, readdir, etc.).
`mp_lexer_new_from_file()` and `mp_import_stat()` are provided by VFS.
`MICROPY_PERSISTENT_CODE_LOAD=1` enables importing precompiled `.mpy` bytecode
files (produced by `mpy-cross`), which load faster and use less RAM than `.py`.

**sys.path enabled.** `MICROPY_PY_SYS_PATH=1` is required for frozen module imports.
At startup, `mp_init()` creates `sys.path = ["", ".frozen"]`. The `.frozen/` virtual
path triggers lookup in `mp_find_frozen_module()`.

**Two-layer os module (uos + os.py).** The C module `modamigaos.c` is registered
as `uos` (via `MP_REGISTER_MODULE(MP_QSTR_uos, ...)`). A frozen `os.py` does
`from uos import *` and adds `makedirs()`, `walk()`, and `import _ospath as path`.
This allows extending os with Python functions while keeping C functions fast.

**No binascii frozen shim.** `manifest.py` freezes `base64.py` directly (via
`freeze()` instead of `require()`) to avoid pulling the Python `binascii.py` shim
from micropython-lib, which shadows the C binascii module.

**Patched datetime.py.** The `__repr__` of `date` in micropython-lib displays the
internal ordinal instead of year/month/day. The local copy in `modules/datetime.py`
fixes this. The time module import uses `__import__("time")` to work around the
name collision with `class time` defined in the same file.

**Dynamic heap via AllocMem.** The GC heap (default 128 KB) is allocated dynamically
via `AllocMem(heap_size, MEMF_ANY | MEMF_CLEAR)`. Size is configurable via the
`-m` command line option. `FreeMem()` is called on normal exit and in crash handlers
(`nlr_jump_fail`, `__assert_func`). Available RAM is checked before allocation.

**Stack 128 KB + StackSwap.** `long __stack = 131072;` in main.c tells libnix to
allocate 128 KB of stack. Additionally, `ensure_stack()` checks the actual stack
at the start of `main()` and uses `StackSwap()` to allocate a 64 KB stack if the
shell didn't provide enough. After the swap, `stack_top` is set to the top of the
new stack (not main's frame on the old shell stack) — critical for GC stack
scanning. At exit, `restore_stack()` frees the allocation before `_exit()`.

**extmod.mk included.** The Makefile includes `extmod/extmod.mk` to compile C
extension modules (re, json, binascii, time, random, hashlib, errno...). Objects
go through `PY_O` (not `PY_CORE_O`) to include everything.

## m68k GC Alignment (Critical)

On m68k with `MICROPY_OBJ_REPR_A`, object pointers must be 4-byte aligned
(bits 1:0 == 0). Without the `_gc_lock_pad` fix,
the struct layout of `mp_state_thread_t` is:

```
char *stack_top;        // offset 0, 4 bytes
uint16_t gc_lock_depth; // offset 4, 2 bytes
// ROOT POINTER SECTION starts here at offset 6 (NOT aligned!)
```

This 2-byte misalignment causes two critical bugs:
1. **GC root scan corruption**: `gc_collect_start()` scans root pointers as 4-byte
   words starting from a 2-byte-shifted position, reading garbage values.
2. **sys.argv misidentified**: `mp_sys_argv_obj` ends up at an address with
   bits 1:0 != 0, making MicroPython interpret it as a qstr instead of an object.

**Fix**: `uint16_t _gc_lock_pad` added after `gc_lock_depth` in `py/mpstate.h`
(see `patches/mpstate_alignment.patch`). A `_Static_assert` in `main.c` catches
regressions at compile time.

The `gc.c:952` assertion was caused by `stack_top` pointing to the wrong stack
after `StackSwap()`. This is now fixed — `stack_top` is set to the top of the
swapped stack. Assertions are fully enabled (no `NDEBUG`).

## Command Line

```
micropython                          # launch interactive REPL
micropython script.py                # execute a script
micropython script.py arg1 arg2      # execute with sys.argv = ['script.py', 'arg1', 'arg2']
micropython -c "print('hello')"      # execute inline code
micropython -m 1024 script.py        # execute with 1024 KB heap
micropython -m 512                   # launch REPL with 512 KB heap
micropython script.mpy               # execute precompiled bytecode
```

The `-m <size_kb>` option must come first. Default heap is 128 KB.
The `-c <code>` option executes Python code and exits.

## Module uos / os (AmigaOS)

The C module `uos` (`modamigaos.c`) provides low-level filesystem operations
using dos.library. The frozen `os.py` re-exports everything from `uos` and adds
`makedirs()`, `walk()`, and `os.path`.

### C functions (uos / modamigaos.c)

- `listdir([path])`: directory contents via Lock/Examine/ExNext. Rejects files (ENOTDIR).
- `getcwd()`: current directory via NameFromLock on CurrentDir lock.
- `chdir(path)`: change directory, UnLocks old lock (preserves shell original_dir).
- `mkdir(path)`: create directory via CreateDir/UnLock.
- `rmdir(path)`: remove empty directory (verifies is dir, then DeleteFile).
- `remove(path)`: remove file (verifies is NOT dir, then DeleteFile).
- `rename(old, new)`: rename via dos.library Rename().
- `stat(path)`: 10-element tuple (mode, ino, dev, nlink, uid, gid, size, atime, mtime, ctime).
  st_mode reflects real permissions from fib_Protection (converted to Unix mode).
  DateStamp converted to Unix epoch (+252460800s offset).
- `system(cmd)`: execute shell command via libnix system().
- `_stat_type(path)`: 0=not found, 1=dir, 2=file (used by _ospath).
- `_cpu()`: CPU string from SysBase->AttnFlags (68000/68020/68030/68040/68060).
- `_fpu()`: FPU string from AttnFlags (none/68881/68882/68040-60 internal).
- `_chipset()`: "OCS", "ECS" or "AGA" from GfxBase->ChipRevBits0.
- `_kickstart()`: "version.revision" from SysBase (lib_Version + SoftVer).
- `_chipmem()`: available chip RAM in bytes (AvailMem).
- `_fastmem()`: available fast RAM in bytes (AvailMem).
- `getenv(key[, default])`: read environment variable via GetVar (GVF_GLOBAL_ONLY).
- `putenv(key, value)`: set environment variable via SetVar.
- `unsetenv(key)`: delete environment variable via DeleteVar.
- `chmod(path, mode)`: set permissions using Unix mode (0o755, 0o666, etc.),
  automatically converts to AmigaOS protection bits (inverted RWED + group/other).
- `getprotect(path)`: read protection bits via Lock/Examine/fib_Protection.
- Constants: `FIBF_DELETE`, `FIBF_EXECUTE`, `FIBF_WRITE`, `FIBF_READ`,
  `FIBF_ARCHIVE`, `FIBF_PURE`, `FIBF_SCRIPT`, `FIBF_HOLD`.
  Note: RWED bits (0-3) are INVERTED on AmigaOS (0=allowed, 1=denied).
- `sep`: `"/"`.

### Python extensions (os.py)

- `makedirs(name, exist_ok=False)`: recursive directory creation with AmigaOS path support.
- `walk(top, topdown=True)`: directory tree generator yielding (dirpath, dirnames, filenames).
- `path`: the `_ospath` module (join, split, basename, dirname, exists, isfile, isdir, etc.).

### Current directory management

`main.c` saves the shell's current directory lock at startup as a global:
```c
BPTR original_dir = 0;  // global
original_dir = CurrentDir(0);
CurrentDir(original_dir);
```
Restores it before exit: `CurrentDir(original_dir)`.

## Module os.path (AmigaOS -- _ospath.py)

Frozen Python module implementing os.path for AmigaOS path conventions.
Loaded via `import _ospath as path` in the frozen `os.py`.

### AmigaOS path conventions

- `":"` separates volume from path (e.g. `DH0:work/file`, `System:Libs`)
- `"/"` separates subdirectories
- A path is absolute if it contains `":"`
- No leading `"/"` for absolute paths
- `"."` is NOT valid as current directory -- use `""` (empty string)
- `join("DH0:", "work")` -> `"DH0:work"` (no slash after colon)

### Functions

- `sep`, `join`, `split`, `basename`, `dirname`, `splitext`
- `isabs`, `normpath`, `abspath`
- `exists`, `isfile`, `isdir` (via `uos._stat_type()`)

## Frozen Modules

Frozen modules are Python files compiled to bytecode (.mpy) by mpy-cross, then
embedded in the C binary via `frozen_content.c`. Importable without a filesystem.

### Current frozen modules

| Module | Source | Dependencies |
|--------|--------|-------------|
| `base64` | micropython-lib/python-stdlib/base64 | `binascii` (C extmod) |
| `datetime` | local copy `modules/datetime.py` | `time` (C extmod) |
| `_ospath` | local `modules/_ospath.py` | `uos` (C module) |
| `os` | local `modules/os.py` | `uos` (C module), `_ospath` |
| `platform` | local `modules/platform.py` | `uos` (C module), `sys` |
| `urequests` | local `modules/urequests.py` | `socket`, `ssl` (C modules), `json` |
| `gzip` | local `modules/gzip.py` | `deflate`, `io` |
| `zlib` | local `modules/zlib.py` | `_zlib` (C module), `deflate`, `io` |
| `zipfile` | local `modules/zipfile.py` | `zlib`, `deflate`, `struct`, `os`, `io` |
| `smtplib` | local `modules/smtplib.py` | `socket`, `ssl`, `base64`, `email` |
| `email` (+ `email.mime`) | local `modules/email/` | `base64`, `binascii`, `time` |

### Adding a frozen module

Edit `manifest.py` and add `freeze("path", "file.py")` or `require("name")`
(note: require pulls transitive dependencies). Available modules are in
`lib/micropython-lib/python-stdlib/` and `lib/micropython-lib/micropython/`.
Then `gmake clean && gmake`.

## Module socket (AmigaOS -- modsocket.c)

Native C module providing BSD sockets via libnix `libsocket.a`, which wraps
AmigaOS `bsdsocket.library`. Requires a TCP/IP stack (e.g. Roadshow, Miami,
AmiTCP) to be running.

### Functions and classes

- `socket.socket(family, type, proto)`: create a socket (defaults: AF_INET, SOCK_STREAM, 0)
- `socket.getaddrinfo(host, port)`: DNS resolution, returns list of 5-tuples
- Constants: `AF_INET`, `AF_INET6`, `SOCK_STREAM`, `SOCK_DGRAM`, `SOL_SOCKET`, `SO_REUSEADDR`

### Socket methods

- `connect(addr)`, `bind(addr)`, `listen([backlog])`, `accept()`
- `send(data)`, `recv(bufsize)`, `sendto(data, addr)`, `recvfrom(bufsize)`
- `setsockopt(level, optname, value)`, `setblocking(flag)` (no-op)
- `close()`, `fileno()`

### Ctrl-C handling in blocking socket calls

`socket_raise_io_error()` helper consumes SIGBREAKF_CTRL_C after any
blocking bsdsocket call (accept, connect, send, recv, sendto, recvfrom).
If the signal is set, it raises `KeyboardInterrupt` directly instead of
`OSError`, preventing a double-exception cascade that corrupted the VM stack.

Special case: `accept()` on WinUAE returns a "fake fd" (positive value with
garbage address) on break instead of -1. The helper closes it before raising.

### Cleanup

- Socket objects have a `__del__` finalizer that calls `close()` on the fd.
- `gc_sweep_all()` is called before `mp_deinit()` on all exit paths to ensure
  orphaned sockets are closed before shutdown.
- On crash (`nlr_jump_fail`, `__assert_func`), libnix closes bsdsocket.library
  via `exit()`, which releases all associated sockets.

### Limitations

- Sockets are always blocking (no non-blocking/timeout support)
- Linked with `-lsocket` in the Makefile

## Module arexx (AmigaOS -- modarexx.c)

Native C module providing ARexx inter-process communication via
`rexxsyslib.library`. Allows MicroPython scripts to send commands to any
ARexx-capable AmigaOS application.

### Functions

- `arexx.exists(portname)`: returns True if the named ARexx port exists
  (uses Forbid/FindPort/Permit for safe access)
- `arexx.send(portname, command, result=False)`: sends an ARexx command.
  Returns RC (int) if result=False, or (RC, result_string) tuple if result=True.
  Creates a private reply port, sends via PutMsg, waits with WaitPort.
  Result strings that aren't valid UTF-8 are returned as bytes (Latin-1 fallback).
- `arexx.ports()`: returns a list of all public port names (snapshot under Forbid)
- `arexx.Port(portname)`: persistent client class with reusable reply port.
  Methods: `send(command, result=False)`, `close()`. Properties: `portname`, `closed`.
  Context manager: `with arexx.Port("APP") as p: p.send("CMD")`
  `__del__` finalizer for GC cleanup. Open ports tracked in a linked list for
  `mod_arexx_deinit()` cleanup at exit.

### Cleanup

`mod_arexx_deinit()` is called before exit to close rexxsyslib.library.
The library is opened lazily on first `arexx.send()` call.

## Module amiga.intuition (AmigaOS -- modintuition.c)

Native C sub-package exposing `intuition.library` GUI primitives. Phase 1
covers three modal requester helpers built on `EasyRequestArgs()`; future
phases will add Window/Screen/Menu classes.

### Functions

All functions are keyword-only and share a single core engine
(`do_easy_request_impl()`) that performs argument validation, UTF-8 → Latin-1
conversion, label concatenation, and `EasyRequestArgs()` dispatch. The three
public entry points are thin wrappers that select the button list and the
return normalization.

- `amiga.intuition.easy_request(*, title, body, buttons) -> int`
  Generic N-button modal (1..8 buttons). Returns the 0-based index of the
  clicked button (left-to-right). `title` may be empty.

```python
import amiga.intuition as intuition
idx = intuition.easy_request(
    title="amigagames+",
    body="Update package found.\nInstall it?",
    buttons=["Install", "Cancel"])   # 0 = Install, 1 = Cancel
```

- `amiga.intuition.auto_request(*, body, yes="Yes", no="No") -> bool`
  Two-button yes/no wrapper. Returns `True` if the left (yes) button is
  clicked, `False` for the right (no) button. Title is empty.

```python
if intuition.auto_request(body="Delete file?"):
    os.remove(path)
```

- `amiga.intuition.message(*, body, button="OK") -> None`
  Single-button notice wrapper (acknowledgement dialog). Always returns
  `None`. Title is empty.

```python
intuition.message(body="Installation complete.")
```

While any requester is open the user must click a gadget — Ctrl-C pressed in
the launching shell is not intercepted by intuition.library and does not
abort the call.

### Implementation notes

- **IntuitionBase**: auto-opened by libnix startup through `libstubs.a`'s
  `intuition.o` stub (declares `"intuition.library"` in `___LIB_LIST__`).
  Auto-closed by `___exitlibraries` (inscribed in `___EXIT_LIST__`, iterated
  by `callfuncs` in `ncrt0.o` after `main()` returns). No manual
  `OpenLibrary`/`CloseLibrary` in the module — verified empirically by
  locating the `___exitlibraries` bytecode signature in `build/micropython`
  and the resolved `___LIB_LIST__` entry pointing to `"intuition.library"`.
- **printf-injection safe**: `es_TextFormat = "%s"` is fixed and the body
  is passed as the sole vararg via `EasyRequestArgs(..., args)`. A user body
  containing `%s`, `%d`, `%n` is rendered literally, never interpreted.
- **Latin-1 conversion**: title, body, and every label go through
  `amiga_utf8_to_latin1()` into fresh `m_new` buffers. A single concatenated
  gadgets buffer is built with `|` as separator (labels containing `|` are
  rejected at validation — EasyRequest has no escape mechanism).
- **Ctrl-C (defensive, not exercised)**: in practice intuition.library does
  not break out of an open EasyRequest on SIGBREAKF_CTRL_C, so the call
  always blocks until a gadget is clicked. The code still handles the
  documented `-1` return (`SetSignal(0, SIGBREAKF_CTRL_C)` + direct
  `mp_raise_type(&mp_type_KeyboardInterrupt)`, cascade-safe à la
  `modsocket.c`) as a guard if a future Intuition release changes that
  behaviour. Buffers are freed **before** raising so GC memory is not
  orphaned.
- **Return normalization**: `EasyRequestArgs` returns 0 for the rightmost
  button and 1..N-1 for the others (left-to-right, excluding rightmost).
  We remap to 0-based left-to-right: `raw==0 -> N-1`, `raw>=1 -> raw-1`,
  with single-button case clamped to 0.
- **Validation**: `title` any str (empty allowed — `easy_request` now accepts
  `""`, the two wrappers always pass `""`), `body` any str (empty allowed,
  `\n` allowed), each label a non-empty str with no `|`. `easy_request`
  enforces 1..8 buttons; `auto_request` always builds a 2-element list;
  `message` always builds a 1-element list.

### Sub-package mechanics

The module is exposed as `amiga.intuition`, not just `intuition`. Pattern:
- `MP_REGISTER_MODULE(MP_QSTR_amiga, mp_module_amiga)` registers only the
  parent package.
- `mp_module_amiga`'s globals dict contains
  `{MP_QSTR_intuition: &mp_module_amiga_intuition}`. Import resolution via
  `MICROPY_MODULE_BUILTIN_SUBPACKAGES` (enabled by ROM level EVERYTHING)
  finds the sub-module there.
- The sub-module's `__name__` must be the literal qstr `"amiga.intuition"`.
  The qstr scanner sees `MP_QSTR_amiga_dot_intuition` and emits
  `Q(amiga_dot_intuition)` — which would become the wrong string
  `"amiga_dot_intuition"`. To force the dotted qstr, **`qstrdefsport.h`
  contains an explicit `Q(amiga.intuition)`** which is processed first
  (cat order in py.mk: `$(PY_QSTR_DEFS) $(QSTR_DEFS) $(QSTR_DEFS_COLLECTED)`)
  and wins the deduplication in `makeqstrdata.py`.

### Test harness

Three sample scripts in `samples/` exercise each entry point:

- `test_easyrequest.py` — 7 cases for `easy_request()`: two buttons, four
  buttons (index order), multi-line body, printf-injection (body with
  `%s %d %n`), one button, Latin-1 accents in title/body/labels, Ctrl-C
  probe (kept for completeness — Ctrl-C does not abort an open EasyRequest).
- `test_auto_request.py` — 6 cases for `auto_request()`: default labels
  click-yes and click-no, Spanish labels (`Sí` / `No`), multi-line body,
  printf-injection guard, Ctrl-C probe.
- `test_message.py` — 6 cases for `message()`: default `OK`, custom
  `Continue` label, Spanish `Vale` with accented body, multi-line body,
  long body (>200 chars), and an `assert r is None` return-value check.

## Module amiga.asl (AmigaOS -- modasl.c)

Native C sub-package exposing `asl.library`'s requester primitives. Phase 1
covers the File requester; Font and ScreenMode requesters can be added
later using the same scaffolding (AllocAslRequest + AslRequest + tag list).

### Function

- `amiga.asl.file_request(*, title=None, initial_drawer=None,
  initial_file=None, initial_pattern=None, save_mode=False,
  multi_select=False, drawers_only=False, reject_icons=False)`
  All arguments are keyword-only and optional. Returns:
  - a `str` (joined drawer+file via `AddPart()`) in simple mode,
  - a `str` drawer path when `drawers_only=True`,
  - a `list[str]` of length N≥0 when `multi_select=True`,
  - `None` if the user cancels (in every mode).

```python
import amiga.asl as asl

path = asl.file_request(title="Open file", initial_drawer="PROGDIR:")
save = asl.file_request(title="Save as",
                        initial_file="untitled.txt",
                        save_mode=True)
paths = asl.file_request(multi_select=True)            # list[str] | None
dir_  = asl.file_request(drawers_only=True)            # str       | None
```

### Implementation notes

- **AslBase**: auto-opened by libnix startup through `libstubs.a`'s
  `asl.o` stub (declares `"asl.library"` in `___LIB_LIST__`). Auto-closed
  by `___exitlibraries` at process exit. No manual
  `OpenLibrary`/`CloseLibrary` in the module — doing so would cause a
  double-close at exit (same failure class as the AmiSSL `-lamisslauto`
  crash that produced error `#80000004`). Verified empirically:
  `asl.library` appears in `___LIB_LIST__` at `.data+0x298` with name
  pointer into the `.text` library-names block, alongside
  `intuition.library`, `dos.library`, etc. The ONLY include needed is
  `<proto/asl.h>`.
- **Ownership**: the module owns the `FileRequester` returned by
  `AllocAslRequest()` and always pairs it with `FreeAslRequest()` on
  every exit path (cancel, single-result, multi-select, exception via
  `mp_raise_*` — the allocation happens after all validation, so a raise
  before the alloc cannot leak).
- **CRITICAL — decode before free**: `rf_Dir`, `rf_File`, and every
  `wa_Name` in `rf_ArgList` point into the requester's own storage.
  `FreeAslRequest()` invalidates all of them. All Python string objects
  are therefore built BEFORE calling Free.
- **Latin-1 conversion**: every inbound string (`title`, `initial_drawer`,
  `initial_file`, `initial_pattern`) is converted UTF-8 → Latin-1 into a
  stack-allocated 512-byte buffer via `amiga_utf8_to_latin1()`. Every
  outbound string (`rf_Dir`, `rf_File`, `wa_Name`) is converted back
  Latin-1 → UTF-8 before returning to Python. The Latin-1 helper is
  duplicated as a small static function in modasl.c to keep the module
  self-contained (same 25-line helper as modamigaos.c).
- **Tag list**: stack-allocated `struct TagItem tags[12]` (9 optional
  tags + TAG_END + headroom). Tags are appended only when the caller
  passed a non-None, non-empty value for string kwargs, or a `True` for
  boolean kwargs. Empty strings are skipped so we don't clear a default
  inside asl.library. When `initial_pattern` is non-empty, the module
  also appends `ASLFR_DoPatterns=TRUE` so the pattern gadget becomes
  visible (otherwise the pattern filter is set but invisible).
- **Path joining**: done in C via dos.library `AddPart()` into a 512-byte
  stack buffer. For `drawers_only` mode, `AddPart()` is called with an
  empty filename and returns the drawer untouched (AmigaOS convention
  "this is the directory itself"). On truncation (should not happen with
  a 512-byte buffer at AmigaOS's ~255-char path limit) the module raises
  `OSError("joined path too long")` — there is no `MP_ENAMETOOLONG`
  constant in `py/mperrno.h`.
- **Validation**: mutually-exclusive flag combinations (`save_mode &&
  multi_select`, `save_mode && drawers_only`) are rejected with
  `ValueError` before any Amiga call. `AllocAslRequest() == NULL` raises
  `MemoryError` directly.
- **No Ctrl-C handling**: asl.library does not surface
  `SIGBREAKF_CTRL_C` while a requester has focus — same caveat as
  `amiga.intuition`. `AslRequest()` returns `TRUE` on OK, `FALSE` on
  Cancel only; a break is only seen after dismissal.

### Sub-package mechanics

Same scheme as `amiga.intuition`:
- The parent `amiga` package lives in `modintuition.c` (its globals
  dict is where all sub-modules attach). `modasl.c` declares
  `mp_module_amiga_asl` as non-static; `modintuition.c` has
  `extern const mp_obj_module_t mp_module_amiga_asl;` and adds it to
  `mp_module_amiga_globals_table` as `{MP_QSTR_asl, ...}`.
- `MICROPY_MODULE_BUILTIN_SUBPACKAGES` (enabled by ROM level
  EVERYTHING) resolves `import amiga.asl` by looking up `asl` in the
  parent's globals.
- The dotted `__name__` qstr is forced via an explicit `Q(amiga.asl)`
  line in `qstrdefsport.h` (same reason as `Q(amiga.intuition)`: the
  qstr scanner would otherwise emit the wrong string
  `"amiga_dot_asl"`).

### Test harness

`samples/test_asl.py` is a menu-driven harness covering seven scenarios:
simple open, pattern filter (`#?.py` in `PROGDIR:samples`), save mode,
multi-select, drawers-only, an explicit cancel probe with
`assert result is None`, and a Latin-1 accented title (`Café Français`)
that verifies UTF-8 → Latin-1 makes it to the ASL gadget labels.

## Module ssl (AmigaOS -- modssl.c)

Native C module providing TLS via AmiSSL (AmigaOS OpenSSL wrapper). Requires
`amisslmaster.library` and AmiSSL v4+ installed on the Amiga.

### Architecture

- Uses a custom BIO that routes I/O through libnix `send()`/`recv()` with
  `__attribute__((saveds))` callbacks (required for A4 register restoration
  when called from AmiSSL shared library).
- AmiSSL initialization is fully manual (`OpenLibrary` → `InitAmiSSLMaster` →
  `OpenAmiSSL` → `InitAmiSSL` with `SocketBase` and `errno` pointer).
  No `-lamisslauto` to avoid destructor conflicts at exit.
- A single global `SSL_CTX` is shared across all connections.
- `amissl_cleanup()` does full teardown: `SSL_CTX_free` → `CleanupAmiSSL` →
  `CloseAmiSSL` → `CloseLibrary`.
- SSLSocket `__del__` is GC-safe: calls `SSL_free` + `close(fd)` directly,
  skips `SSL_shutdown` (I/O unsafe during GC) and Python method calls.

### Functions

- `ssl.wrap_socket(sock, server_hostname=None)`: wraps a connected socket with TLS.
  Returns an `SSLSocket` with `send()`, `recv()`, `read()`, `write()`, `close()`.
- SSLSocket has a `__del__` finalizer for GC cleanup.

### Link flags

`-lamisslstubs` in the Makefile (after `-lsocket`). Note: `-lamisslauto` is NOT
used — it caused exit crashes due to its destructor double-closing AmiSSL
libraries. All AmiSSL open/close is done manually in `ensure_amissl_init()` and
`amissl_cleanup()`.

## Module smtplib + email package (frozen Python)

CPython-compatible email composition (`email/` sub-package) and SMTP client
(`smtplib`). Phase 1 covers emission only — receiving (`poplib` + parser)
is planned as Phase 2. Both modules are frozen Python (no C), built on top
of the existing `socket` and `ssl` C modules.

### smtplib

`SMTP(host, port=25, local_hostname=None, timeout=None)` and
`SMTP_SSL(host, port=465, ...)` classes. Both are context managers. Public
methods:

- `connect(host, port)` / `close()` / `quit()` — connection lifecycle.
- `helo(name=None)` / `ehlo(name=None)` — `ehlo` parses ESMTP capabilities
  into `self.esmtp_features` (dict of feature → param).
- `has_extn(name)` — case-insensitive ESMTP capability lookup.
- `starttls(server_hostname=None)` — wraps the socket with
  `ssl.wrap_socket(..., server_hostname=host)`, then resets `ehlo_resp` and
  `esmtp_features` (RFC 3207: capabilities must be re-queried under TLS).
- `login(user, password)` — tries `AUTH PLAIN` then `AUTH LOGIN` based on
  `esmtp_features['auth']`; raises `SMTPNotSupportedError` if neither is
  advertised. CRAM-MD5 / DIGEST-MD5 / XOAUTH2 not supported.
- `sendmail(from_addr, to_addrs, msg, mail_options=(), rcpt_options=())` —
  MAIL FROM / per-recipient RCPT TO / DATA. Returns `{}` if all recipients
  accepted, else `{recipient: (code, resp)}`.
- `send_message(msg, from_addr=None, to_addrs=None)` — extracts From/Sender
  and To/Cc/Bcc from the `Message`; strips Bcc/Resent-Bcc from headers
  before serialization (so they remain envelope-only), then calls
  `sendmail`. The caller's `Message` is left unmodified.
- `set_debuglevel(level)` — level ≥ 1 prints `send:` / `reply:` traces.
- Exceptions (all inherit `OSError` à la CPython 3.4+):
  `SMTPException`, `SMTPServerDisconnected`, `SMTPResponseException`,
  `SMTPSenderRefused`, `SMTPRecipientsRefused`, `SMTPDataError`,
  `SMTPConnectError`, `SMTPHeloError`, `SMTPAuthenticationError`,
  `SMTPNotSupportedError`.

### Implementation notes

- **No `socket.makefile()`** in MicroPython — `_LineReader` reads `recv(1024)`
  chunks into a buffer and slices off `\r\n`-terminated lines. Buffer cap is
  `_MAXLINE = 8192`.
- **No `socket.create_connection()`** — manual
  `getaddrinfo(host, port)[0][-1] + socket() + connect()`.
- **No `ssl.SSLContext`** — `ssl.wrap_socket(sock, server_hostname=host)` is
  used directly. `SMTP_SSL._get_socket()` wraps before any SMTP I/O so the
  server greeting (`220 ...`) is read over TLS.
- **`local_hostname`** defaults to `socket.gethostname()` if available, else
  `'amiga.localdomain'`. The same fallback is in `email.utils._default_domain`
  for `make_msgid()`.
- **Dot-stuffing** in `_quotedata`: lines starting with `.` get a leading
  `.` prefix so a stray `.\r\n` in the payload doesn't terminate DATA early.
- **`timeout`** is accepted for API compat but not enforced — sockets are
  always blocking on this port.
- **Ctrl-C** inside a blocking `recv()` is consumed by `modsocket.c` and
  surfaces as `KeyboardInterrupt`, not a partial OSError cascade.

### email package layout

```
modules/
├── smtplib.py
└── email/
    ├── __init__.py     (marker)
    ├── utils.py        formatdate, formataddr, parseaddr, getaddresses, make_msgid
    ├── header.py       Header (RFC 2047 =?utf-8?B?...?= encoding)
    ├── encoders.py     encode_base64 / encode_quopri / encode_7or8bit / encode_noop
    ├── message.py      Message: mapping interface, payload mgmt, walk(), as_string()
    └── mime/
        ├── __init__.py (marker)
        ├── base.py     MIMEBase(Message): sets MIME-Version + Content-Type
        ├── text.py     MIMEText: auto charset detect (ASCII->7bit, else UTF-8 base64)
        ├── multipart.py MIMEMultipart: boundary auto-gen via ticks_us + counter
        └── application.py MIMEApplication: defaults to encode_base64
```

### Encoding model

- **`MIMEText('...', 'utf-8')`** auto-encodes the payload in base64 with
  `Content-Transfer-Encoding: base64` so the body survives any relay,
  whether the relay advertises `8BITMIME` or not.
- **`Header(s, 'utf-8')`** produces RFC 2047 encoded-words
  `=?utf-8?B?...?=`. Splitting respects UTF-8 codepoint boundaries (the
  base64 chunker walks back over `0x80-0xBF` continuation bytes before
  cutting). The full Unicode range round-trips: subjects with `é è ç à œ`
  AND `€` (U+20AC, outside Latin-1) arrive intact in Gmail.
- **`formataddr(('Name', 'addr'))`** quote-phrases ASCII names containing
  `()<>@,;:\\"[].`, RFC 2047 encodes non-ASCII names, and returns
  `Name <addr>` (or just `addr` if name is empty).
- **`formatdate(localtime=True)`** computes the UTC offset by differencing
  `time.localtime()` and `time.gmtime()` at the same `timeval` — MicroPython
  doesn't expose `time.timezone`, so this is the portable path. On AmigaOS
  the offset is supplied by `modtime.c` via `locale.library`'s `loc_GMTOffset`.

### MicroPython 1.28 quirks the package works around

- **`str.encode("ascii")` does NOT validate** in MicroPython 1.28 — it's
  implemented via `bytes(s, "ascii")` and silently emits the UTF-8 bytes
  regardless of the encoding name. The classic CPython idiom
  `try: s.encode("ascii"); except UnicodeError:` is therefore unusable.
  All "is this ASCII?" checks in `email.utils._is_ascii`,
  `email.header._is_ascii` and `email.mime.text._is_ascii` iterate
  codepoints (`for ch in s: if ord(ch) > 127: return False`) instead.
- **`socket.makefile()` missing** — see `_LineReader` above.
- **`time.timezone` not guaranteed** — see `formatdate` UTC offset
  computation above.

### Test harness

`samples/test_smtplib_offline.py` — purely local, no network. Validates
`email.utils` (`formatdate`/`formataddr`/`parseaddr`/`make_msgid`), Header
RFC 2047 encoding, Message mapping interface, full multipart serialization
(MIME-Version, multipart/mixed boundary, Subject RFC 2047 encoded, base64
attachment, walk yields the right part tree), and MIMEText ASCII-vs-UTF-8
encoding selection.

`samples/test_smtplib_online.py [A|B|BOTH]` — network test, requires a
`mail_credentials.txt` next to the binary (gitignored) with `user=`, `pass=`,
`to=` lines, or `MAIL_USER`/`MAIL_PASS`/`MAIL_TO` env vars. Gmail needs an
**app password**, not the main password. Scenario A exercises STARTTLS on
port 587; Scenario B exercises SMTP_SSL on port 465. Both use
`set_debuglevel(1)` so the EHLO/AUTH/MAIL/RCPT/DATA exchange is visible
on stdout. Both have been validated against `smtp.gmail.com` on WinUAE.

Run with `-m 1024` (TLS handshake needs more heap than the default 128 KB).

## Module time (AmigaOS)

Implemented via `modtime.c` (included by extmod/modtime.c via
`MICROPY_PY_TIME_INCLUDEFILE`):

- `time.time()`: seconds since epoch 1970 via libnix `time()`
- `time.time_ns()`: nanoseconds since epoch (second resolution)
- `time.gmtime([secs])` / `time.localtime([secs])`: 8-element tuple
- `time.mktime(tuple)`: inverse conversion
- `time.sleep(secs)` / `time.sleep_ms(ms)` / `time.sleep_us(us)`: `usleep()` libnix
- `time.gmtime([secs])` / `time.localtime([secs])`: 8-element time tuple
- `time.mktime(tuple)`: inverse conversion
- `time.strftime(fmt[, t])`: format time tuple as string (%Y %m %d %H %M %S etc.)
  Implemented in C via MICROPY_PY_TIME_EXTRA_GLOBALS (not a frozen module).
- `time.ticks_ms()` / `time.ticks_us()` / `time.ticks_cpu()`: stubs (return 0)

Epoch is 1970 (`MICROPY_EPOCH_IS_1970=1`), matching libnix `time()`.
`time.localtime()` applies timezone offset from AmigaOS `locale.library`
(`loc_GMTOffset`). `time.gmtime()` always returns UTC.

## AmigaOS Specifics

### REPL (readline with raw mode)

The REPL uses `shared/readline/readline.c` (`MICROPY_USE_READLINE=1`) with
50-entry command history. The AmigaOS console is switched to raw mode via
`SetMode(Input(), 1)` for character-by-character input, and restored to cooked
mode via `SetMode(Input(), 0)` after each command execution and on exit.

Console I/O uses `Read(Input())` and `Write(Output())` from dos.library
(not stdio fgets/fwrite) for raw mode compatibility.

### CSI Translation

AmigaOS sends CSI (0x9B / 155) + letter for cursor keys, but MicroPython
readline expects ANSI ESC (27) + '[' (91) + letter. `mp_hal_stdin_rx_chr()`
translates on the fly: when it receives 155, it returns 27 (ESC) and queues
'[' for the next call.

### Exiting the REPL

- `quit()` or `exit()`: port-defined builtins, raise `SystemExit`
- `sys.exit()`: standard MicroPython (`MICROPY_PY_SYS_EXIT=1`)
- Ctrl-D: exit REPL cleanly
- Ctrl-C: cancel current input
- Ctrl-E: enter paste mode

Console is restored to cooked mode in crash handlers (`nlr_jump_fail`,
`__assert_func`) to avoid leaving the shell in raw mode.

## Enabled Modules

### Always active (EVERYTHING)

- `builtins`: basic Python functions (print, len, range, etc.)
- `gc`: garbage collector control
- `sys`: system info, `sys.exit()`, `sys.platform`, `sys.path`, `sys.argv`,
  `sys.stdin`, `sys.stdout`, `sys.stderr` (VFS_POSIX textio streams)
- `struct`: binary data pack/unpack
- `math`: math functions (single-precision float)
- `micropython`: MicroPython introspection
- `io`: StringIO, BytesIO

### Module os (uos C + frozen os.py)

- `os.listdir`, `os.getcwd`, `os.chdir`, `os.system`, `os.sep`
- `os.mkdir`, `os.rmdir`, `os.remove`, `os.rename`, `os.stat`
- `os.makedirs(name, exist_ok=False)`: recursive directory creation
- `os.walk(top, topdown=True)`: directory tree generator
- `os.path`: join, split, basename, dirname, exists, isfile, isdir, etc.

### Explicitly enabled (C extmod modules)

- `re`: regular expressions
- `json`: JSON encoding/decoding
- `binascii`: hexlify, unhexlify, a2b_base64, b2a_base64
- `time`: time, gmtime, localtime, mktime, sleep, ticks_ms/us/cpu
- `random`: random, randint, randrange, choice, uniform
- `hashlib`: sha256 (built-in, no TLS needed; MD5/SHA1 not available)
- `errno`: POSIX error constants
- `deflate`: compression/decompression (raw deflate, zlib, gzip via DeflateIO)
- `platform`: system/CPU/FPU/chipset/Kickstart detection (frozen, uses uos C helpers)
- `socket`: TCP/UDP sockets, DNS resolution (native C module via libsocket/bsdsocket.library)
- `ssl`: TLS via AmiSSL (native C module, custom BIO with saveds callbacks)
- `arexx`: ARexx IPC (send commands to AmigaOS apps, list ports, check existence)
- `amiga.intuition`: native sub-package, `easy_request()` / `auto_request()` / `message()` (Workbench modal dialogs)
- `amiga.asl`: native sub-package, `file_request()` (open/save/multi-select/drawers-only requester via asl.library)

### Frozen (Python modules embedded in binary)

- `base64`: base64, base32, base16 encoding/decoding
- `datetime`: date, time, datetime, timedelta (patched: fixed __repr__, added strftime,
  datetime.now() with microseconds via time_ns, timezone-aware localtime)
- `_ospath`: os.path for AmigaOS
- `os`: os module wrapper (makedirs, walk, path)
- `platform`: system, machine, processor, version, fpu, chipset, amiga_info
- `urequests`: HTTP/1.1 HTTPS client with chunked TE, gzip decompression, buffered I/O
- `deflate`: compression/decompression (raw deflate, zlib, gzip formats)
- `zlib`: CPython-compatible zlib API (compress, decompress, crc32) — native C crc32 + frozen Python
- `zipfile`: read/write ZIP archives (stored + deflated, CRC32 verification, extractall)
- `gzip`: CPython-compatible gzip.compress()/gzip.decompress() (frozen, wraps deflate)
- `smtplib`: SMTP/SMTP_SSL client (STARTTLS, AUTH PLAIN/LOGIN, sendmail, send_message)
- `email` (+ `email.mime`): CPython-compatible Message/MIME composition, Header (RFC 2047), utils

### Port-added builtins

- `quit([code])`: exit REPL (raise SystemExit)
- `exit([code])`: alias for quit()
- `input([prompt])`: line reading
- `open(file, mode)`: full file I/O via VFS_POSIX (read and write)
- `help()`, `help('modules')`: built-in help

### Disabled

- `_thread`: no multithreading (no pthreads on AmigaOS)
- `socket`: available (see below)
- `select`: no I/O multiplexing
- `signal`: no POSIX signals
- `ffi`: no FFI
- `termios`: no POSIX terminal control
- `hashlib.md5`, `hashlib.sha1`: require mbedTLS/axTLS (not available)

## Memory

- GC heap: 128 KB default, configurable via `-m <kb>` (e.g. `-m 1024` for 1 MB)
  Dynamic allocation via `AllocMem(heap_size, MEMF_ANY | MEMF_CLEAR)`,
  freed by `FreeMem()` on exit and in crash handlers
- Available RAM checked before allocation; warning if >80% requested
- Heap size and available RAM displayed in REPL banner
- Stack: 128 KB via libnix (`long __stack = 131072`), with StackSwap fallback to 64 KB
- Qstr: 2048-byte chunks, 2-byte length, 2-byte hash
- GC collect: `gc_helper_collect_regs_and_stack()` via `gchelper_generic.c`
  (setjmp-based register capture + stack scan)
- Stack control: `mp_stack_ctrl_init()` + `mp_stack_set_top()` called in `vm_init()`
- Types: `mp_int_t` = int32, `mp_uint_t` = uint32 (32-bit architecture)
- Long integers: MPZ (arbitrary precision)
- `mp_off_t` = long

## Known Bugs

- **GC assertion gc.c:952** (FIXED): was caused by two bugs — misaligned root
  pointers (fixed via `_gc_lock_pad` in `py/mpstate.h`) and `stack_top` pointing
  to the wrong stack after `StackSwap()` (fixed by setting `stack_top` to the top
  of the swapped stack). Assertions are now fully enabled.
- **VM assertion vm.c:1144 on Ctrl-C in socket calls** (FIXED): bsdsocket on
  AmigaOS wakes blocking syscalls on SIGBREAKF_CTRL_C without consuming the
  signal. This caused a double exception (OSError + KeyboardInterrupt) that
  corrupted the VM stack during `CANCEL_ACTIVE_FINALLY`. Fixed via
  `socket_raise_io_error()` in modsocket.c which consumes the signal and raises
  `KeyboardInterrupt` directly.

## Known Limitations

- `time.ticks_ms()` is a stub (no high-resolution clock yet)
- Ctrl-C (KeyboardInterrupt) works during execution via MICROPY_VM_HOOK_POLL
  polling SetSignal(SIGBREAKF_CTRL_C) every 64 bytecodes. time.sleep() is
  interruptible in 100ms chunks via Delay().
- `hashlib` only supports SHA256 (MD5/SHA1 require TLS library)
- `hashlib.sha256().digest()` can only be called once (MicroPython limitation)

## Future Work

- High-resolution clock via timer.device or ReadEClock() for ticks_ms/ticks_us
- Add more frozen modules (collections, etc.)
