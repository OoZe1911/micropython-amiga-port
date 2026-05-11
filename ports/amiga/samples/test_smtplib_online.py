# Online smoke test for smtplib on the MicroPython AmigaOS port.
#
# Reads credentials from mail_credentials.txt (in the current directory)
# OR from environment variables MAIL_USER / MAIL_PASS / MAIL_TO.
# The file format is one key=value per line:
#
#     user=monadresse@gmail.com
#     pass=xxxxxxxxxxxxxxxx
#     to=destinataire@example.com
#
# (Add mail_credentials.txt to .gitignore -- do NOT commit your password.)
#
# Two scenarios are exercised:
#   A) SMTP() + ehlo() + starttls() + login() + send_message()  (port 587)
#   B) SMTP_SSL() + login() + send_message()                    (port 465)
#
# Run with the larger heap recommended for TLS handshakes:
#     micropython -m 1024 samples/test_smtplib_online.py [A|B]

import os
import sys
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication
from email.header import Header
from email.utils import formatdate, formataddr
import smtplib


def load_credentials():
    creds = {}
    try:
        with open("mail_credentials.txt", "r") as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                if "=" in line:
                    k, v = line.split("=", 1)
                    creds[k.strip()] = v.strip()
    except OSError:
        pass
    user = creds.get("user") or os.getenv("MAIL_USER")
    pwd = creds.get("pass") or os.getenv("MAIL_PASS")
    to = creds.get("to") or os.getenv("MAIL_TO")
    host = creds.get("host", "smtp.gmail.com")
    if not (user and pwd and to):
        raise SystemExit(
            "missing credentials: need user/pass/to in mail_credentials.txt "
            "or MAIL_USER/MAIL_PASS/MAIL_TO env vars")
    return user, pwd, to, host


def build_message(user, to):
    msg = MIMEMultipart()
    msg["From"] = formataddr(("Amiga MicroPython", user))
    msg["To"] = to
    msg["Subject"] = Header(
        "Bonjour depuis l'Amiga - test smtplib", "utf-8").encode()
    msg["Date"] = formatdate(localtime=True)
    body = (
        "Salut !\r\n"
        "\r\n"
        "Ce message a été envoyé depuis MicroPython sur AmigaOS.\r\n"
        "Caractères accentués : é, è, ç, à, œ.\r\n"
        "Symbole hors Latin-1 (€) pour vérifier l'UTF-8 complet.\r\n"
    )
    msg.attach(MIMEText(body, "plain", "utf-8"))

    # A small binary attachment to exercise base64 encoding.
    payload = bytes(range(32, 128)) + b"\x00\x01\x02\xff" * 4
    att = MIMEApplication(payload, "octet-stream")
    att.add_header("Content-Disposition", "attachment", filename="probe.bin")
    msg.attach(att)
    return msg


def scenario_starttls(user, pwd, to, host):
    print("== Scenario A: STARTTLS on %s:587 ==" % host)
    msg = build_message(user, to)
    with smtplib.SMTP(host, 587) as s:
        s.set_debuglevel(1)
        s.ehlo()
        s.starttls()
        s.login(user, pwd)
        rejected = s.send_message(msg)
    if rejected:
        print("rejected:", rejected)
    else:
        print("delivered (no rejected recipients).")


def scenario_ssl(user, pwd, to, host):
    print("== Scenario B: SMTP_SSL on %s:465 ==" % host)
    msg = build_message(user, to)
    with smtplib.SMTP_SSL(host, 465) as s:
        s.set_debuglevel(1)
        s.login(user, pwd)
        rejected = s.send_message(msg)
    if rejected:
        print("rejected:", rejected)
    else:
        print("delivered (no rejected recipients).")


def main():
    user, pwd, to, host = load_credentials()
    choice = sys.argv[1].upper() if len(sys.argv) > 1 else "A"
    if choice == "A":
        scenario_starttls(user, pwd, to, host)
    elif choice == "B":
        scenario_ssl(user, pwd, to, host)
    elif choice == "BOTH":
        scenario_starttls(user, pwd, to, host)
        scenario_ssl(user, pwd, to, host)
    else:
        raise SystemExit("usage: test_smtplib_online.py [A|B|BOTH]")


if __name__ == "__main__":
    main()
