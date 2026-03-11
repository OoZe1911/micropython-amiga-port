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
