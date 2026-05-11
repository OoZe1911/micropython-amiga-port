# MicroPython for AmigaOS (m68k)

A port of [MicroPython](https://micropython.org/) v1.28 to AmigaOS, targeting
Motorola 68020+ processors. Runs on classic Amiga hardware (A1200, A3000, A4000)
and emulators (WinUAE, FS-UAE).

## About This Port

This port is developed by **Fabrice** with coding assistance from **Claude**
(Anthropic's AI). Claude writes and modifies the code under Fabrice's direct
supervision: Fabrice defines the architecture, chooses the implementation
strategy, tests every build on real Amiga hardware or emulator, and provides
detailed feedback and bug reports that guide the development. Every change is
reviewed and validated by a human before being committed.

## No need to build

The Amiga binary executable can be found in [micropython](ports/amiga/build/micropython) (`ports/amiga/build/`)

## Features

- **Full Python compatibility** (ROM_LEVEL_EVERYTHING): f-strings, set operations,
  OrderedDict, advanced slicing, descriptors, async/await, and more
- **Interactive REPL** with readline support (cursor keys, command history)
- **Script execution**: `micropython script.py [args...]`
- **Inline execution**: `micropython -c "print('hello')"`
- **Configurable heap**: `micropython -m 1024` for 1 MB heap (default 128 KB)
- **File I/O**: full `open()`/`read()`/`write()`/`close()` via VFS_POSIX
- **Precompiled modules**: import and execute `.mpy` bytecode files (compiled with `mpy-cross`)
- **AmigaOS filesystem**: `os.listdir`, `os.getcwd`, `os.chdir`, `os.mkdir`,
  `os.rmdir`, `os.remove`, `os.rename`, `os.stat`, `os.chmod`, `os.getprotect`,
  `os.makedirs`, `os.walk`, `os.getenv`, `os.putenv`, `os.unsetenv`
- **os.path**: join, split, basename, dirname, exists, isfile, isdir, abspath,
  normpath (with AmigaOS volume:path conventions)
- **Modules**: re, json, math, struct, binascii, base64, time, datetime,
  random, hashlib (sha256), errno, platform, socket, ssl, urequests, smtplib,
  email, deflate, gzip, zlib, zipfile, arexx, gc, sys, io
- **Networking**: TCP/UDP sockets, DNS resolution via bsdsocket.library
- **TLS/SSL**: HTTPS support via AmiSSL (requires amissl.library on Amiga)
- **HTTP client**: `urequests.get()`, `post()`, `put()`, `delete()` with HTTP/1.1,
  chunked transfer encoding, gzip decompression, HTTP and HTTPS
- **SMTP client**: `smtplib.SMTP` (with `STARTTLS`) and `smtplib.SMTP_SSL` (port
  465 implicit TLS), `AUTH PLAIN` and `AUTH LOGIN`, `sendmail()` and
  `send_message()`, context-manager and `set_debuglevel()` support
- **Email composition**: CPython-compatible `email` sub-package
  (`email.mime.text.MIMEText`, `email.mime.multipart.MIMEMultipart`,
  `email.mime.application.MIMEApplication`, `email.utils.formatdate` /
  `formataddr`, `email.header.Header`) — full UTF-8 support (subject and body
  with accents, `€` and other non-Latin-1 codepoints survive intact)
- **ARexx IPC**: `arexx.send()`, `arexx.exists()`, `arexx.ports()`, and
  `arexx.Port()` persistent client with context manager for inter-process
  communication with AmigaOS applications
- **Intuition GUI**: `amiga.intuition` native sub-package — `easy_request(title,
  body, buttons)` modal Workbench requester returning a 0-based button index,
  plus two convenience wrappers `auto_request(body, yes="Yes", no="No") -> bool`
  (two-button yes/no dialog) and `message(body, button="OK") -> None`
  (single-button notice). Latin-1 aware and printf-injection safe
- **ASL file requester**: `amiga.asl.file_request(**kwargs)` wraps
  `asl.library`'s native file chooser — supports initial drawer/file/pattern,
  save mode, multi-select (returns `list[str]`), and directories-only mode
  (returns the drawer path). Latin-1 aware, paths joined via dos.library
  `AddPart()`
- **Platform detection**: `platform.amiga_info()` shows CPU, FPU, chipset,
  Kickstart version, and available memory

## Quick Start

### Requirements

- [bebbo's m68k-amigaos-gcc toolchain](https://franke.ms/git/bebbo/amiga-gcc)
  installed at `/opt/amiga/`
- GNU Make (`gmake`)
- [AmiSSL SDK](https://github.com/jens-maus/amissl)
  installed in `/opt/amiga/m68k-amigaos/ndk-include` (.h files) and in `/opt/amiga/m68k-amigaos/lib` for `libamisslauto.a` and `libamisslstubs.a`

### Build

```sh
cd mpy-cross && gmake          # one-time: build the bytecode cross-compiler
cd ../ports/amiga && gmake     # build the Amiga binary
```

The binary `build/micropython` is ready to copy to your Amiga.

### Run

```
micropython                          ; interactive REPL
micropython script.py                ; run a script
micropython -c "print(2**32)"        ; run inline code
micropython -m 512 script.py         ; run with 512 KB heap
```

## AmigaOS Path Conventions

AmigaOS uses `:` to separate volumes from paths and `/` for subdirectories:

```python
>>> import os
>>> os.getcwd()
'DH0:Work'
>>> os.path.join("DH0:", "work", "scripts")
'DH0:work/scripts'
>>> os.path.isabs("DH0:file.py")
True
```

## Known Limitations

- `time.ticks_ms()` returns 0 (no high-resolution timer yet)
- Ctrl-C (KeyboardInterrupt) works during execution with ~20ms latency
- `hashlib` only supports SHA256 (MD5/SHA1 require TLS library)
- Sockets are always blocking (no non-blocking mode)
- No multithreading
- re module: {n} quantifiers are not supported (use explicit repeated characters instead, e.g. "..." instead of ".{3}")

## License

MicroPython is licensed under the MIT License. See the [LICENSE](LICENSE)
file in the repository root.