include ../../py/mkenv.mk

# Compiler and flags for AmigaOS m68k cross-compilation
CROSS_COMPILE = /opt/amiga/bin/m68k-amigaos-

QSTR_DEFS = qstrdefsport.h

MICROPY_ROM_TEXT_COMPRESSION ?= 1

# Frozen Python modules (base64, datetime)
FROZEN_MANIFEST ?= $(shell pwd)/manifest.py

include $(TOP)/py/py.mk
include $(TOP)/extmod/extmod.mk

INC += -I.
INC += -I$(TOP)
INC += -I$(BUILD)

CFLAGS += $(INC) -Wall -std=c99 -noixemul -m68020 -O2 $(COPT)
CFLAGS += -fdata-sections -ffunction-sections
CFLAGS += -Wno-error

LDFLAGS += -noixemul -m68020 -Wl,--gc-sections
LIB += -lm

CSUPEROPT = -Os

SRC_C = \
	main.c \
	amiga_mphal.c \
	modamigaos.c \
	shared/runtime/pyexec.c \
	shared/runtime/stdout_helpers.c \
	shared/timeutils/timeutils.c \

SRC_QSTR += shared/runtime/pyexec.c main.c modamigaos.c

# Exclude shared/libc sources — libnix already provides libc
SRC_EXTMOD_C := $(filter-out shared/libc/%.c,$(SRC_EXTMOD_C))

OBJ += $(PY_O)
OBJ += $(addprefix $(BUILD)/, $(SRC_C:.c=.o))

# Auto-incrementing build number and timestamp.
# .build_number persists across cleans (not in build/).
BUILD_NUMBER_FILE = .build_number
BUILD_VERSION_HDR = $(BUILD)/genhdr/amigaversion.h

$(BUILD_VERSION_HDR): FORCE | $(BUILD)/genhdr
	$(Q)if [ ! -f $(BUILD_NUMBER_FILE) ]; then echo 0 > $(BUILD_NUMBER_FILE); fi
	$(Q)echo $$(( $$(cat $(BUILD_NUMBER_FILE)) + 1 )) > $(BUILD_NUMBER_FILE)
	$(Q)echo "// Auto-generated — do not edit" > $@
	$(Q)echo "#define AMIGA_BUILD_NUM \"$$(cat $(BUILD_NUMBER_FILE))\"" >> $@
	$(Q)echo "#define AMIGA_BUILD_TIMESTAMP \"$$(date '+%Y-%m-%d %H:%M')\"" >> $@

# Use the PROG mechanism from mkrules.mk - it handles linking via $(CC)
PROG = micropython

include $(TOP)/py/mkrules.mk

# All objects include mpconfigport.h which includes amigaversion.h.
# Must be after mkrules.mk so $(OBJ) is fully expanded.
$(BUILD)/main.o: $(BUILD_VERSION_HDR)
$(BUILD)/genhdr/qstr.i.last: $(BUILD_VERSION_HDR)
