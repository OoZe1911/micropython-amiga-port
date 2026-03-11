# MicroPython AmigaOS m68k Port

## Build

Cross-compiler : `/opt/amiga/bin/m68k-amigaos-gcc` (GCC 6.5.0b, bebbo toolchain).

Prérequis : mpy-cross doit être compilé en premier (une seule fois) :

```
cd mpy-cross && gmake       # compile le cross-compilateur .py -> .mpy
```

Puis :

```
cd ports/amiga
gmake              # build incrémental
gmake clean        # nettoyage complet
gmake V=1          # build verbose
```

Le binaire `build/micropython` est un exécutable AmigaOS hunk (magic `0x000003f3`),
directement exécutable sur Amiga 68020+ ou dans un émulateur.

Le numéro de build s'incrémente à chaque compilation (stocké dans `.build_number`).
Le banner affiche : `MicroPython v1.27.0 on 2026-03-10 16:28 build 5; Amiga with M68020`

Flags de compilation :
- `-noixemul` : utilise libnix au lieu de ixemul.library (pas d'émulation POSIX)
- `-m68020` : jeu d'instructions 68020 minimum
- `-O2` : optimisation standard
- `-fdata-sections -ffunction-sections` + `-Wl,--gc-sections` : élimine le code mort

## Architecture du port

### Fichiers

| Fichier | Rôle |
|---------|------|
| `Makefile` | Build cross-compilé, inclusion de py.mk + extmod.mk, build number |
| `mpconfigport.h` | Configuration des features MicroPython pour AmigaOS |
| `mphalport.h` | HAL : ticks, delays, interrupt char, `mp_hal_readline` pour `input()` |
| `main.c` | Point d'entrée, REPL fgets, argv, builtins `quit()`/`exit()`, save/restore curdir |
| `amiga_mphal.c` | I/O console : `mp_hal_stdin_rx_chr`, `mp_hal_stdout_tx_strn`, `amiga_prompt` |
| `modamigaos.c` | Module `os` standalone (listdir, getcwd, chdir, system via dos.library) |
| `modtime.c` | Implémentation time pour AmigaOS (gmtime/localtime/time via libnix) |
| `qstrdefsport.h` | Qstrings spécifiques au port (vide pour l'instant) |
| `manifest.py` | Déclaration des modules Python frozen (base64, datetime) |
| `modules/datetime.py` | Copie locale patchée de datetime (repr corrigé) |
| `run_tests.py` | Test runner : lance chaque test dans un processus micropython séparé |

### Décisions d'architecture

**Pas de POSIX.** AmigaOS n'est pas POSIX. Tout le code POSIX du port unix a été
écarté : pas de fork, pas de pthreads, pas de mmap, pas de signaux POSIX, pas de
termios, pas de select/poll, pas de VFS POSIX.

**libnix (-noixemul).** On utilise libnix qui fournit une libc minimale (malloc,
stdio, string, setjmp, time, gmtime) sans dépendre de ixemul.library. Conséquence :
on exclut `shared/libc/printf.c` et `shared/libc/abort_.c` du build via le filtre
`SRC_EXTMOD_C := $(filter-out shared/libc/%.c,$(SRC_EXTMOD_C))` dans le Makefile,
car libnix fournit déjà ces symboles (printf, putchar, vprintf, abort).

**NLR setjmp.** Le m68k n'a pas d'implémentation NLR native dans MicroPython.
Le fallback `setjmp`/`longjmp` est utilisé (`MICROPY_NLR_SETJMP=1`). Le GC utilise
aussi setjmp pour capturer les registres (`MICROPY_GCREGS_SETJMP=1`).

**Entiers arbitraires (MPZ).** `MICROPY_LONGINT_IMPL` est réglé sur `MPZ`
(multi-precision integers). C'est requis par le module frozen `datetime` qui utilise
des constantes entières dépassant 32 bits pour les calculs d'epoch.

**Pas de native emitters.** Tous les emitters natifs (x64, x86, thumb, ARM) sont
désactivés. Le bytecode MicroPython est interprété uniquement.

**ROM level CORE_FEATURES.** Niveau de features intermédiaire qui donne un REPL
fonctionnel avec les builtins essentiels sans surcharger la RAM.

**sys.path activé.** `MICROPY_PY_SYS_PATH=1` est indispensable pour que l'import
trouve les modules frozen. Au démarrage, `mp_init()` crée `sys.path = ["", ".frozen"]`.
Le chemin virtuel `.frozen/` est le préfixe qui déclenche la recherche dans
`mp_find_frozen_module()`. Sans sys.path, les frozen modules sont invisibles.

**Pas de shim binascii frozen.** Le manifest.py freeze `base64.py` directement
(via `freeze()` au lieu de `require()`) pour éviter de tirer le shim Python
`binascii.py` de micropython-lib. Ce shim fait `from ubinascii import *` (nom
obsolète) et shadow le module C binascii. Le module C extmod fournit déjà toutes
les fonctions nécessaires : `a2b_base64`, `b2a_base64`, `hexlify`, `unhexlify`.

**datetime.py patchée.** Le `__repr__` de `date` dans micropython-lib affiche
l'ordinal interne (`datetime.date(0, 0, 724642)`) au lieu de year/month/day.
La copie locale dans `modules/datetime.py` corrige ce comportement pour afficher
`datetime.date(1985, 1, 1)` comme CPython.

**Module os standalone (modamigaos.c).** Le module `os` générique de extmod
(`MICROPY_PY_OS`) est désactivé. Un module natif `modamigaos.c` le remplace,
enregistré via `MP_REGISTER_MODULE(MP_QSTR_os, ...)`. Ce module utilise
dos.library directement pour les opérations filesystem. L'approche par
`MICROPY_MODULE_ATTR_DELEGATION` et `MICROPY_PY_OS_INCLUDEFILE` a été essayée
et abandonnée car elle ne fonctionnait pas (le module os chargeait mais
n'exposait aucune fonction).

**Stack 128 KB.** `long __stack = 131072;` dans main.c demande à libnix
d'allouer 128 KB de stack au lancement. Nécessaire pour le parser récursif
de Python et le GC collect.

**extmod.mk inclus.** Le Makefile inclut `extmod/extmod.mk` pour compiler les
modules C d'extension (re, json, binascii, time...). Les objets passent par
`PY_O` (et non `PY_CORE_O`) pour inclure le tout.

## Module os (AmigaOS — modamigaos.c)

Module standalone qui remplace le module os générique (`MICROPY_PY_OS=0`).
Enregistré via `MP_REGISTER_MODULE(MP_QSTR_os, mp_module_amiga_os)`.

### Fonctions

- `os.listdir([path])` : liste le contenu d'un répertoire via
  `Lock/Examine/ExNext/UnLock` + `AllocDosObject(DOS_FIB)`.
  Sans argument, liste le répertoire courant (path="").
- `os.getcwd()` : retourne le répertoire courant via `NameFromLock()` sur le
  lock courant (obtenu par `CurrentDir(0)` + restore). N'utilise PAS
  `GetCurrentDirName()` car cette fonction lit la structure CLI qui n'est pas
  mise à jour par `CurrentDir()`.
- `os.chdir(path)` : change de répertoire via `Lock(path)/CurrentDir(lock)`.
  Ne fait PAS `UnLock()` sur l'ancien lock retourné par `CurrentDir()` car
  c'est potentiellement le lock hérité du shell.
- `os.system(cmd)` : exécute une commande shell via `system()` libnix.
- `os.sep` : `"/"` (AmigaOS utilise `/` comme séparateur de chemin dans les
  paths relatifs, et `:` pour les volumes).

### Gestion du répertoire courant

`main.c` sauvegarde le lock du répertoire courant du shell au démarrage :
```c
BPTR original_dir = CurrentDir(0);
CurrentDir(original_dir);
```
Et le restaure avant de quitter : `CurrentDir(original_dir)`.
Cela garantit que le shell retrouve son répertoire après exécution de micropython,
même si des scripts ont utilisé `os.chdir()`.

## Modules frozen

Les modules frozen sont des fichiers Python compilés en bytecode (.mpy) par
mpy-cross, puis intégrés dans le binaire C via `frozen_content.c`. Ils sont
importables sans filesystem.

### Mécanisme

1. `manifest.py` déclare les modules à freezer via `freeze("chemin", "fichier.py")`
2. `FROZEN_MANIFEST` dans le Makefile pointe vers ce fichier
3. mkrules.mk appelle `tools/makemanifest.py` qui :
   - compile chaque `.py` en `.mpy` via mpy-cross
   - génère `build/frozen_content.c` contenant le bytecode
4. Ce fichier C est compilé et linké dans le binaire
5. mkrules.mk ajoute automatiquement les CFLAGS nécessaires :
   `-DMICROPY_MODULE_FROZEN_MPY -DMICROPY_MODULE_FROZEN_STR
    -DMICROPY_QSTR_EXTRA_POOL=mp_qstr_frozen_const_pool`

### Modules frozen actuels

| Module | Source | Dépendances |
|--------|--------|-------------|
| `base64` | micropython-lib/python-stdlib/base64 | `binascii` (module C extmod) |
| `datetime` | copie locale `modules/datetime.py` | `time` (module C extmod) |

### Ajouter un module frozen

Éditer `manifest.py` et ajouter un `freeze("chemin", "fichier.py")` ou
`require("nom")` (attention : require tire les dépendances transitives).
Les modules disponibles sont dans `lib/micropython-lib/python-stdlib/`
et `lib/micropython-lib/micropython/`. Puis `gmake clean && gmake`.

## Module time (AmigaOS)

Le module `time` est implémenté via `modtime.c` (inclus par extmod/modtime.c
via `MICROPY_PY_TIME_INCLUDEFILE`). Il fournit :

- `time.time()` : secondes depuis epoch 1970 via `time()` libnix
- `time.gmtime([secs])` / `time.localtime([secs])` : conversion en tuple 8 éléments
- `time.mktime(tuple)` : conversion inverse
- `time.sleep(secs)` / `time.sleep_ms(ms)` / `time.sleep_us(us)` : stubs (no-op)
- `time.ticks_ms()` / `time.ticks_us()` / `time.ticks_cpu()` : stubs (retournent 0)

L'epoch est 1970 (`MICROPY_EPOCH_IS_1970=1`), conforme au `time()` de libnix.
Les fonctions de conversion utilisent `shared/timeutils/timeutils.c`.

## Exécution de scripts

### Ligne de commande

```
micropython                  # lance le REPL interactif
micropython script.py        # exécute un script
micropython a.py b.py c.py   # exécute chaque script dans une VM fraîche
```

Quand plusieurs fichiers sont passés en arguments, chaque script s'exécute dans
une VM complètement réinitialisée (`mp_deinit()` + `gc_init()` + `mp_init()`)
pour éviter l'accumulation de qstrings entre les scripts.

`sys.argv` est peuplé avec tous les arguments avant l'exécution.

### Filesystem

`mp_lexer_new_from_file()` est implémenté (lit le fichier en mémoire via
`fopen/fseek/fread`), ce qui permet :
- Exécution de scripts `.py` depuis la ligne de commande
- `import` de modules `.py` depuis le filesystem AmigaOS

`mp_import_stat()` vérifie l'existence des fichiers via `fopen`.

### Test runner (run_tests.py)

Lance chaque fichier `test_*.py` dans un processus micropython séparé via
`os.system("micropython " + filepath)`. Cela garantit une VM fraîche par test,
sans pollution du pool qstr entre les tests.

```
micropython run_tests.py tests/
micropython run_tests.py tests/test_math.py tests/test_string.py
```

Note : sur AmigaOS, le test runner nécessite que `micropython` soit dans le PATH
du shell (ou dans C:). La syntaxe de boucle FOR du shell AmigaOS pour lancer les
tests directement depuis le CLI n'a pas été investiguée.

## Particularités AmigaOS

### Console en mode cooked (line-buffered)

AmigaOS n'a pas de mode raw terminal comme Unix. La console device fonctionne
en mode cooked : l'utilisateur édite sa ligne, et le programme ne la reçoit
qu'après appui sur Return.

Conséquences :
- `MICROPY_USE_READLINE` est à 0 (pas de readline char-par-char)
- `shared/readline/readline.c` n'est pas compilé
- La boucle REPL dans `main.c` (`do_repl()`) utilise `amiga_prompt()` qui lit
  une ligne complète via `fgets()`
- Le builtin `input()` passe aussi par `amiga_prompt()` via le macro
  `mp_hal_readline` défini dans `mphalport.h`

### Retour chariot CR vs LF

AmigaOS envoie CR (`\r`, 13) comme fin de ligne au lieu de LF (`\n`, 10).
- `amiga_prompt()` strip les CR et LF en fin de ligne
- `mp_hal_stdin_rx_chr()` convertit `\r` en `\n` (utile si du code lit char par char)

### Sortie du REPL

Quatre façons de quitter :
- `quit()` ou `exit()` : builtins définis dans le port, lèvent `SystemExit`
- `sys.exit()` : standard MicroPython (`MICROPY_PY_SYS_EXIT=1`)
- Ctrl-C : détecté comme `\x03` en début de ligne dans `do_repl()`
- EOF (fin de redirection fichier) : `amiga_prompt()` retourne NULL

Le REPL affiche "Bye!" avant de quitter.

### Debug des entrées

Si la variable d'environnement `MP_DEBUG_INPUT` est définie (setenv dans le Shell
AmigaOS), chaque caractère reçu par `mp_hal_stdin_rx_chr()` est affiché sur stderr
avec son code ASCII, avant la conversion CR->LF.

## Modules activés

### Toujours actifs (CORE_FEATURES)

- `builtins` : fonctions de base Python (print, len, range, etc.)
- `gc` : contrôle du garbage collector
- `sys` : informations système, `sys.exit()`, `sys.platform`, `sys.path`, `sys.argv`
- `struct` : pack/unpack de données binaires
- `math` : fonctions mathématiques (single-precision float)
- `micropython` : introspection MicroPython
- `io` : StringIO, BytesIO

### Module os (standalone natif — modamigaos.c)

- `os.listdir([path])` : contenu d'un répertoire (dos.library Examine/ExNext)
- `os.getcwd()` : répertoire courant (NameFromLock)
- `os.chdir(path)` : changer de répertoire (Lock/CurrentDir)
- `os.system(cmd)` : exécuter une commande shell
- `os.sep` : `"/"`

### Activés explicitement (modules C extmod)

- `re` : expressions régulières
- `json` : encodage/décodage JSON
- `binascii` : hexlify, unhexlify, a2b_base64, b2a_base64
- `time` : time, gmtime, localtime, mktime, sleep, ticks_ms/us/cpu

### Frozen (modules Python intégrés au binaire)

- `base64` : encodage/décodage base64, base32, base16
- `datetime` : date, time, datetime, timedelta (copie locale patchée)

### Builtins ajoutés par le port

- `quit([code])` : quitte le REPL (raise SystemExit)
- `exit([code])` : alias de quit()
- `input([prompt])` : lecture de ligne via `amiga_prompt()`
- `open(file)` : lecture de fichiers via fopen/fread (lecture seule)

### Désactivés

- `_thread` : pas de multithreading (pas de pthreads sur AmigaOS)
- `socket` : pas de réseau
- `select` : pas de multiplexage I/O
- `signal` : pas de signaux POSIX
- `ffi` : pas de FFI
- `termios` : pas de contrôle terminal POSIX
- VFS : pas de VFS MicroPython (filesystem géré directement via dos.library)

## Mémoire

- Heap GC : 512 KB (statique, dans le BSS)
- Stack : 128 KB minimum (déclaré via `long __stack = 131072` dans main.c)
- Qstr : chunks de 2048 octets, length sur 2 octets, hash sur 2 octets
  (`MICROPY_ALLOC_QSTR_CHUNK_INIT=2048`, `QSTR_BYTES_IN_LEN=2`,
  `QSTR_BYTES_IN_HASH=2`)
- Types : `mp_int_t` = int32, `mp_uint_t` = uint32 (architecture 32 bits)
- Entiers longs : MPZ (précision arbitraire)
- `mp_off_t` = long

## Bugs connus

- **Assertion qstr pool** : `'#q < pool->len' failed at qstr.c:198` se produit
  encore dans certains cas lors de l'exécution de scripts qui importent à la fois
  `os` et `sys`, ou lors d'appels `os.listdir()` sur des répertoires avec beaucoup
  de fichiers. Le heap a été doublé à 512 KB et les paramètres qstr augmentés mais
  le crash persiste. La cause racine n'est pas encore identifiée — il pourrait
  s'agir d'une corruption mémoire ou d'un problème de fragmentation du pool qstr.
  Contournement : exécuter chaque script dans un processus séparé (argv multiples
  ou `run_tests.py`).

## Limitations connues

- `time.ticks_ms()` et `time.sleep()` sont des stubs (pas encore d'horloge haute
  résolution ni de timer.device)
- `mp_hal_set_interrupt_char()` est un no-op
- La ligne d'entrée est limitée à 255 caractères (buffer `amiga_prompt`)
- `os.chdir()` ne libère pas les anciens locks (leak mineur, nettoyé à la sortie
  du processus par AmigaOS)
- `open()` fonctionne en lecture seule (pas d'écriture de fichiers)

## Pistes d'évolution

- Écriture de fichiers via `open()` mode "w" (dos.library Open/Write/Close)
- Horloge via timer.device ou ReadEClock() pour ticks_ms/ticks_us
- Sleep via timer.device (DoIO/WaitIO)
- Support Ctrl-C via `SetSignal()` / `CheckSignal()` (SIGBREAKF_CTRL_C)
- Augmenter le heap via `AllocMem()` au lieu du tableau statique BSS
- Investiguer le crash qstr pool (possible corruption mémoire)
- Ajouter `os.remove()`, `os.mkdir()`, `os.rename()` via dos.library
- Ajouter d'autres modules frozen (hashlib, collections, etc.)
- Investiguer la syntaxe FOR du shell AmigaOS pour le test runner
