# Test runner for MicroPython AmigaOS port.
# Runs each .py test file in a separate micropython process
# to avoid qstr pool pollution between tests.
#
# Usage (on AmigaOS):
#   micropython run_tests.py tests/
#
# Usage (with explicit file list):
#   micropython run_tests.py tests/test_math.py tests/test_string.py

import sys
import os

def find_tests(path):
    """Find all .py test files in a directory."""
    tests = []
    entries = os.listdir(path)
    for name in sorted(entries):
        if name.endswith(".py") and name.startswith("test_"):
            tests.append(path.rstrip("/") + "/" + name)
    return tests

def run_test(filepath):
    """Run a single test file in a separate micropython process."""
    ret = os.system("micropython " + filepath)
    return ret == 0

def main():
    if len(sys.argv) < 2:
        print("Usage: micropython run_tests.py <test_dir_or_file> [...]")
        sys.exit(1)

    tests = []
    for arg in sys.argv[1:]:
        try:
            entries = os.listdir(arg)
            # It's a directory
            tests.extend(find_tests(arg))
        except OSError:
            # It's a file
            tests.append(arg)

    passed = 0
    failed = 0
    errors = []

    for test in tests:
        print("RUN  " + test + " ... ", end="")
        ok = run_test(test)
        if ok:
            print("OK")
            passed += 1
        else:
            print("FAIL")
            failed += 1
            errors.append(test)

    print()
    print("{} passed, {} failed, {} total".format(passed, failed, passed + failed))
    if errors:
        print("Failed tests:")
        for e in errors:
            print("  " + e)
        sys.exit(1)

main()
