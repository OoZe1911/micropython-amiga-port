# Frozen modules for the AmigaOS port.
# These are compiled to bytecode and embedded in the binary,
# so they can be imported without a filesystem.
#
# We freeze base64.py directly (not via require()) to avoid pulling
# the binascii.py shim which shadows the C module. The C extmod
# binascii already provides a2b_base64, b2a_base64, hexlify,
# unhexlify — everything base64.py needs.
#
# datetime.py is a local patched copy (from micropython-lib) with
# a fixed __repr__ that shows year/month/day instead of the ordinal.

freeze("$(MPY_LIB_DIR)/python-stdlib/base64", "base64.py")
freeze("$(PORT_DIR)/modules", "datetime.py")
freeze("$(PORT_DIR)/modules", "_ospath.py")
freeze("$(PORT_DIR)/modules", "os.py")
freeze("$(PORT_DIR)/modules", "platform.py")
freeze("$(PORT_DIR)/modules", "urequests.py")
freeze("$(PORT_DIR)/modules", "gzip.py")
freeze("$(PORT_DIR)/modules", "zlib.py")
freeze("$(PORT_DIR)/modules", "zipfile.py")

# email + smtplib (Phase 1: emission only)
freeze("$(PORT_DIR)/modules", "smtplib.py")
freeze("$(PORT_DIR)/modules", "email/__init__.py")
freeze("$(PORT_DIR)/modules", "email/utils.py")
freeze("$(PORT_DIR)/modules", "email/header.py")
freeze("$(PORT_DIR)/modules", "email/encoders.py")
freeze("$(PORT_DIR)/modules", "email/message.py")
freeze("$(PORT_DIR)/modules", "email/mime/__init__.py")
freeze("$(PORT_DIR)/modules", "email/mime/base.py")
freeze("$(PORT_DIR)/modules", "email/mime/text.py")
freeze("$(PORT_DIR)/modules", "email/mime/multipart.py")
freeze("$(PORT_DIR)/modules", "email/mime/application.py")
