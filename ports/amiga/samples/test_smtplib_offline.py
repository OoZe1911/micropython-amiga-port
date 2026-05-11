# Offline tests for the email package.
#
# Builds a representative multipart message with a UTF-8 text body and a
# binary attachment, then asserts the serialized output has the expected
# headers and structure. No network, no smtplib. Run as:
#
#     micropython samples/test_smtplib_offline.py

from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication
from email.header import Header
from email.utils import formatdate, formataddr, parseaddr, make_msgid


def _check(cond, label):
    if cond:
        print("  OK  ", label)
    else:
        print("  FAIL", label)
        raise AssertionError(label)


def test_utils():
    print()
    print("== email.utils ==")
    d = formatdate()
    _check(len(d) >= 25 and d[3:5] == ", ", "formatdate default: %r" % d)
    d_gmt = formatdate(usegmt=True)
    _check(d_gmt.endswith(" GMT"), "formatdate(usegmt=True): %r" % d_gmt)
    d_local = formatdate(localtime=True)
    _check(d_local[-5] in "+-", "formatdate(localtime=True): %r" % d_local)

    ascii_addr = formataddr(("Fabrice", "me@amiga.fr"))
    _check(ascii_addr == "Fabrice <me@amiga.fr>", "formataddr ascii")
    quoted = formataddr(("Doe, John", "j@x.com"))
    _check(quoted.startswith('"Doe, John"'), "formataddr quoted: %r" % quoted)
    nonascii = formataddr(("Café", "c@x.com"))
    _check(nonascii.startswith("=?utf-8?B?") and " <c@x.com>" in nonascii,
           "formataddr non-ascii: %r" % nonascii)

    name, addr = parseaddr("Fabrice <me@amiga.fr>")
    _check(name == "Fabrice" and addr == "me@amiga.fr", "parseaddr basic")
    name, addr = parseaddr('"Doe, John" <j@x.com>')
    _check(name == "Doe, John" and addr == "j@x.com", "parseaddr quoted")
    name, addr = parseaddr("plain@x.com")
    _check(name == "" and addr == "plain@x.com", "parseaddr bare")

    mid = make_msgid()
    _check(mid.startswith("<") and mid.endswith(">") and "@" in mid,
           "make_msgid: %r" % mid)


def test_header():
    print()
    print("== email.header ==")
    h = Header("Hello", "us-ascii")
    _check(str(h) == "Hello", "ascii passthrough")
    h2 = Header("Bonjour é è ç à", "utf-8")
    enc = str(h2)
    _check(enc.startswith("=?utf-8?B?") and enc.endswith("?="),
           "utf-8 encoded-word: %r" % enc)


def test_message_basic():
    print()
    print("== email.message basic ==")
    from email.message import Message
    m = Message()
    m["Subject"] = "hi"
    m["X-Foo"] = "bar"
    _check(m["subject"] == "hi", "case-insensitive get")
    _check("X-FOO" in m, "case-insensitive contains")
    m.add_header("Content-Disposition", "attachment", filename="data.bin")
    cd = m["content-disposition"]
    _check('filename="data.bin"' not in cd and "filename=data.bin" in cd,
           "add_header param (unquoted, no specials): %r" % cd)
    m.add_header("X-Q", "v", filename="hello world.bin")
    _check('filename="hello world.bin"' in m["x-q"],
           "add_header param (quoted, has space): %r" % m["x-q"])
    m.replace_header("Subject", "hi2")
    _check(m["subject"] == "hi2", "replace_header")


def test_multipart_serialization():
    print()
    print("== multipart serialization ==")
    msg = MIMEMultipart()
    msg["From"] = formataddr(("Fabrice", "me@amiga.fr"))
    msg["To"] = "you@example.com"
    msg["Subject"] = Header("Bonjour é è", "utf-8").encode()
    msg["Date"] = formatdate(localtime=True)
    msg.attach(MIMEText("Salut !\nUn message UTF-8 avec é, è, ç, à.\n",
                        "plain", "utf-8"))
    bin_payload = bytes(range(0, 256))  # full byte range
    att = MIMEApplication(bin_payload, "octet-stream")
    att.add_header("Content-Disposition", "attachment", filename="bytes.bin")
    msg.attach(att)

    s = msg.as_string()
    print("---- serialized message ----")
    print(s)
    print("---- end ----")
    print("length:", len(s), "bytes")

    _check("MIME-Version: 1.0" in s, "outer MIME-Version present")
    _check("Content-Type: multipart/mixed; boundary=" in s,
           "outer multipart Content-Type")
    _check("Subject: =?utf-8?B?" in s, "Subject is RFC 2047")
    _check("Content-Transfer-Encoding: base64" in s,
           "binary attachment is base64")
    # Boundary appears at least twice (open) plus closing form.
    boundary = msg.get_boundary()
    _check(boundary is not None and ("--" + boundary) in s,
           "boundary open found")
    _check(("--" + boundary + "--") in s, "boundary close found")

    parts = list(msg.walk())
    _check(len(parts) == 3, "walk yields 3 parts (outer + 2)")
    _check(parts[1].get_content_type() == "text/plain", "first part is text/plain")
    _check(parts[2].get_content_type() == "application/octet-stream",
           "second part is application/octet-stream")


def test_8bit_text():
    print()
    print("== text/plain ASCII vs UTF-8 ==")
    a = MIMEText("plain ascii\n", "plain")
    s = a.as_string()
    _check("Content-Transfer-Encoding: 7bit" in s, "ascii -> 7bit")
    _check("plain ascii" in s, "ascii payload kept literal")

    b = MIMEText("café\n", "plain", "utf-8")
    s = b.as_string()
    _check("Content-Transfer-Encoding: base64" in s, "utf-8 -> base64")
    _check("charset=utf-8" in s, "charset=utf-8 in Content-Type")


def main():
    print("== email package offline tests ==")
    test_utils()
    test_header()
    test_message_basic()
    test_multipart_serialization()
    test_8bit_text()
    print()
    print("All offline tests passed.")


if __name__ == "__main__":
    main()
