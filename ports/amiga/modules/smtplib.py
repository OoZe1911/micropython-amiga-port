# smtplib -- SMTP client for the MicroPython AmigaOS port.
#
# Implements the subset of CPython's smtplib needed for sending mail:
# SMTP and SMTP_SSL with EHLO/HELO, STARTTLS, AUTH PLAIN / AUTH LOGIN,
# sendmail() and send_message(), context-manager support, debug tracing.
#
# Designed against MicroPython 1.28 limitations:
#   - no socket.makefile() -> internal _LineReader
#   - no socket.create_connection() -> getaddrinfo() + socket() + connect()
#   - no ssl.SSLContext -> ssl.wrap_socket(sock, server_hostname=...)
#
# Phase 1: no CRAM-MD5, no DIGEST-MD5, no XOAUTH2, no LMTP, no quoted
# pipelining.

import socket
import base64


SMTP_PORT = 25
SMTP_SSL_PORT = 465
CRLF = "\r\n"
_MAXLINE = 8192


# -- Exceptions -------------------------------------------------------------

class SMTPException(OSError):
    pass


class SMTPNotSupportedError(SMTPException):
    pass


class SMTPServerDisconnected(SMTPException):
    pass


class SMTPResponseException(SMTPException):
    def __init__(self, code, msg):
        self.smtp_code = code
        self.smtp_error = msg
        self.args = (code, msg)


class SMTPSenderRefused(SMTPResponseException):
    def __init__(self, code, msg, sender):
        self.smtp_code = code
        self.smtp_error = msg
        self.sender = sender
        self.args = (code, msg, sender)


class SMTPRecipientsRefused(SMTPException):
    def __init__(self, recipients):
        self.recipients = recipients
        self.args = (recipients,)


class SMTPDataError(SMTPResponseException):
    pass


class SMTPConnectError(SMTPResponseException):
    pass


class SMTPHeloError(SMTPResponseException):
    pass


class SMTPAuthenticationError(SMTPResponseException):
    pass


# -- Line buffered reader (no socket.makefile()) ---------------------------

class _LineReader:
    def __init__(self, sock):
        self.sock = sock
        self.buf = b""

    def readline(self, max_len=_MAXLINE):
        while b"\r\n" not in self.buf:
            if len(self.buf) > max_len:
                raise SMTPException("got more than %d bytes" % max_len)
            try:
                chunk = self.sock.recv(1024)
            except OSError as e:
                raise SMTPServerDisconnected("connection lost: %s" % e)
            if not chunk:
                # Server closed the connection mid-line.
                line, self.buf = self.buf, b""
                if not line:
                    raise SMTPServerDisconnected("connection closed by server")
                return line
            self.buf += chunk
        line, _, rest = self.buf.partition(b"\r\n")
        self.buf = rest
        return line + b"\r\n"


# -- Helpers ---------------------------------------------------------------

def _quotedata(data):
    # Dot-stuff and CRLF-normalize before sending the DATA payload.
    out = []
    for line in data.split("\n"):
        if line.endswith("\r"):
            line = line[:-1]
        if line.startswith("."):
            line = "." + line
        out.append(line)
    return CRLF.join(out)


def _default_local_hostname():
    if hasattr(socket, "gethostname"):
        try:
            h = socket.gethostname()
            if h:
                return h
        except Exception:
            pass
    return "amiga.localdomain"


def _addr_only(addr):
    # "Name <a@b>" -> "a@b" ; "<a@b>" -> "a@b" ; "a@b" -> "a@b"
    if not addr:
        return addr
    s = addr.strip()
    lt = s.rfind("<")
    gt = s.rfind(">")
    if lt >= 0 and gt > lt:
        return s[lt + 1:gt].strip()
    return s


# -- SMTP class ------------------------------------------------------------

class SMTP:
    default_port = SMTP_PORT

    def __init__(self, host="", port=0, local_hostname=None, timeout=None):
        self.sock = None
        self.file = None
        self.debuglevel = 0
        self.helo_resp = None
        self.ehlo_resp = None
        self.does_esmtp = False
        self.esmtp_features = {}
        self.timeout = timeout  # accepted but not enforced (always blocking)
        if local_hostname is None:
            local_hostname = _default_local_hostname()
        self.local_hostname = local_hostname
        if host:
            code, msg = self.connect(host, port)
            if code != 220:
                self.close()
                raise SMTPConnectError(code, msg)

    # -- Context manager -------------------------------------------------

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        try:
            code, _ = self.docmd("QUIT")
            if code != 221:
                raise SMTPResponseException(code, _)
        except (OSError, SMTPException):
            pass
        finally:
            self.close()

    # -- Debug / I/O primitives -----------------------------------------

    def set_debuglevel(self, level):
        self.debuglevel = level

    def _log_send(self, data):
        if self.debuglevel > 0:
            try:
                printable = data.decode("ascii", "replace")
            except AttributeError:
                printable = str(data)
            print("send:", repr(printable))

    def _log_reply(self, line):
        if self.debuglevel > 0:
            try:
                printable = line.decode("ascii", "replace")
            except AttributeError:
                printable = str(line)
            print("reply:", repr(printable))

    def send(self, s):
        if self.sock is None:
            raise SMTPServerDisconnected("please run connect() first")
        if isinstance(s, str):
            s = s.encode("ascii")
        self._log_send(s)
        try:
            self.sock.send(s)
        except OSError as e:
            self.close()
            raise SMTPServerDisconnected("connection lost: %s" % e)

    def putcmd(self, cmd, args=""):
        if args:
            line = "%s %s%s" % (cmd, args, CRLF)
        else:
            line = "%s%s" % (cmd, CRLF)
        self.send(line)

    def getreply(self):
        if self.file is None:
            raise SMTPServerDisconnected("not connected")
        resp = []
        code = -1
        while True:
            line = self.file.readline()
            if not line:
                raise SMTPServerDisconnected("connection closed by server")
            self._log_reply(line)
            line = line.rstrip(b"\r\n")
            if len(line) < 4:
                raise SMTPResponseException(-1, b"short response: " + line)
            try:
                code = int(line[:3])
            except ValueError:
                raise SMTPResponseException(-1, b"bad response: " + line)
            resp.append(line[4:])
            # 4th char: '-' means continuation, ' ' or anything else means last.
            if len(line) < 4 or line[3:4] != b"-":
                break
        full = b"\n".join(resp)
        return code, full

    def docmd(self, cmd, args=""):
        self.putcmd(cmd, args)
        return self.getreply()

    # -- Connection ------------------------------------------------------

    def _get_socket(self, host, port):
        addr = socket.getaddrinfo(host, port)[0][-1]
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect(addr)
        return s

    def connect(self, host=None, port=0):
        if host is None:
            host = "localhost"
        if not port:
            port = self.default_port
        if self.debuglevel > 0:
            print("connect:", (host, port))
        self.sock = self._get_socket(host, port)
        self.file = _LineReader(self.sock)
        code, msg = self.getreply()
        if self.debuglevel > 0:
            print("connect: server greeting:", code)
        return code, msg

    def close(self):
        try:
            if self.sock is not None:
                self.sock.close()
        finally:
            self.sock = None
            self.file = None

    # -- Hello, capabilities --------------------------------------------

    def helo(self, name=None):
        self.putcmd("HELO", name or self.local_hostname)
        code, msg = self.getreply()
        self.helo_resp = msg
        return code, msg

    def ehlo(self, name=None):
        self.esmtp_features = {}
        self.putcmd("EHLO", name or self.local_hostname)
        code, msg = self.getreply()
        if code != 250:
            self.ehlo_resp = msg
            return code, msg
        self.ehlo_resp = msg
        self.does_esmtp = True
        # Parse capabilities. First line is the greeting; subsequent lines
        # are feature names + optional params.
        try:
            text = msg.decode("ascii", "replace")
        except AttributeError:
            text = msg
        lines = text.split("\n")
        for line in lines[1:]:
            line = line.strip()
            if not line:
                continue
            parts = line.split(None, 1)
            name_ = parts[0].lower()
            param = parts[1] if len(parts) > 1 else ""
            self.esmtp_features[name_] = param
        return code, msg

    def has_extn(self, name):
        return name.lower() in self.esmtp_features

    def ehlo_or_helo_if_needed(self):
        if self.helo_resp is None and self.ehlo_resp is None:
            code, msg = self.ehlo()
            if not (200 <= code < 300):
                code2, msg2 = self.helo()
                if not (200 <= code2 < 300):
                    raise SMTPHeloError(code2, msg2)

    # -- STARTTLS -------------------------------------------------------

    def starttls(self, server_hostname=None):
        self.ehlo_or_helo_if_needed()
        if not self.has_extn("starttls"):
            raise SMTPNotSupportedError(
                "STARTTLS extension not supported by server.")
        code, msg = self.docmd("STARTTLS")
        if code != 220:
            raise SMTPResponseException(code, msg)
        import ssl
        if server_hostname is None:
            server_hostname = getattr(self, "_starttls_host", None)
        self.sock = ssl.wrap_socket(
            self.sock, server_hostname=server_hostname)
        self.file = _LineReader(self.sock)
        # RFC 3207: after a successful STARTTLS, the previous EHLO must
        # be discarded -- the server's capability list usually changes.
        self.helo_resp = None
        self.ehlo_resp = None
        self.esmtp_features = {}
        self.does_esmtp = False
        return code, msg

    # -- AUTH ------------------------------------------------------------

    def _auth_plain(self, user, password):
        token = "\0%s\0%s" % (user, password)
        encoded = base64.b64encode(token.encode("utf-8")).decode("ascii")
        return self.docmd("AUTH", "PLAIN " + encoded)

    def _auth_login(self, user, password):
        code, msg = self.docmd("AUTH", "LOGIN")
        if code != 334:
            raise SMTPAuthenticationError(code, msg)
        u_b64 = base64.b64encode(user.encode("utf-8")).decode("ascii")
        code, msg = self.docmd(u_b64)
        if code != 334:
            raise SMTPAuthenticationError(code, msg)
        p_b64 = base64.b64encode(password.encode("utf-8")).decode("ascii")
        return self.docmd(p_b64)

    def login(self, user, password):
        self.ehlo_or_helo_if_needed()
        if not self.has_extn("auth"):
            raise SMTPNotSupportedError(
                "SMTP AUTH extension not supported by server.")
        methods = self.esmtp_features.get("auth", "").upper().split()
        last = None
        if "PLAIN" in methods:
            code, msg = self._auth_plain(user, password)
            if 200 <= code < 300:
                return code, msg
            last = (code, msg)
        if "LOGIN" in methods:
            code, msg = self._auth_login(user, password)
            if 200 <= code < 300:
                return code, msg
            last = (code, msg)
        if last is None:
            raise SMTPNotSupportedError(
                "No supported authentication method in: " + ",".join(methods))
        raise SMTPAuthenticationError(last[0], last[1])

    # -- Envelope --------------------------------------------------------

    def mail(self, sender, options=()):
        opts = ""
        if options:
            opts = " " + " ".join(options)
        return self.docmd("MAIL", "FROM:<%s>%s" % (sender, opts))

    def rcpt(self, recip, options=()):
        opts = ""
        if options:
            opts = " " + " ".join(options)
        return self.docmd("RCPT", "TO:<%s>%s" % (recip, opts))

    def data(self, msg):
        # `msg` may be str or bytes. Always sent CRLF-terminated.
        if isinstance(msg, bytes):
            try:
                msg = msg.decode("utf-8")
            except UnicodeError:
                msg = msg.decode("latin-1")
        code, repl = self.docmd("DATA")
        if code != 354:
            raise SMTPDataError(code, repl)
        quoted = _quotedata(msg)
        if not quoted.endswith(CRLF):
            quoted += CRLF
        quoted += "." + CRLF
        self.send(quoted)
        return self.getreply()

    def noop(self):
        return self.docmd("NOOP")

    def rset(self):
        return self.docmd("RSET")

    def quit(self):
        try:
            res = self.docmd("QUIT")
        finally:
            self.close()
        return res

    # -- Sending ---------------------------------------------------------

    def sendmail(self, from_addr, to_addrs, msg,
                 mail_options=(), rcpt_options=()):
        self.ehlo_or_helo_if_needed()
        if isinstance(to_addrs, str):
            to_addrs = [to_addrs]
        from_addr = _addr_only(from_addr)
        to_addrs = [_addr_only(a) for a in to_addrs]

        code, resp = self.mail(from_addr, mail_options)
        if code != 250:
            self.rset()
            if code == 421:
                raise SMTPSenderRefused(code, resp, from_addr)
            raise SMTPSenderRefused(code, resp, from_addr)

        refused = {}
        senderrs = {}
        for each in to_addrs:
            code, resp = self.rcpt(each, rcpt_options)
            if code not in (250, 251):
                refused[each] = (code, resp)
        if len(refused) == len(to_addrs):
            self.rset()
            raise SMTPRecipientsRefused(refused)

        code, resp = self.data(msg)
        if code != 250:
            self.rset()
            raise SMTPDataError(code, resp)
        return refused

    def send_message(self, msg, from_addr=None, to_addrs=None):
        # Resolve envelope. CPython's logic: prefer explicit args, else
        # read Sender/From and To/Cc; Bcc is read for envelope, then
        # stripped from the headers before transmission.
        from email.utils import getaddresses

        if from_addr is None:
            from_addr = (msg["Sender"] or msg["From"] or "")
            from_addr = _addr_only(str(from_addr))
        if to_addrs is None:
            tos = []
            for hdr in ("To", "Cc", "Bcc"):
                v = msg.get_all(hdr)
                if v:
                    tos.extend(v)
            to_addrs = [a for _, a in getaddresses(tos) if a]
        # Strip Bcc and Resent-Bcc from the header set before sending.
        # Make a shallow copy of the header list so the caller's Message
        # is left unmodified.
        original_headers = msg._headers
        msg._headers = [(k, v) for (k, v) in original_headers
                        if k.lower() not in ("bcc", "resent-bcc")]
        try:
            return self.sendmail(from_addr, to_addrs, msg.as_string(),
                                 (), ())
        finally:
            msg._headers = original_headers


# -- SMTP_SSL --------------------------------------------------------------

class SMTP_SSL(SMTP):
    default_port = SMTP_SSL_PORT

    def __init__(self, host="", port=0, local_hostname=None, timeout=None):
        SMTP.__init__(self, host, port, local_hostname, timeout)

    def _get_socket(self, host, port):
        import ssl
        addr = socket.getaddrinfo(host, port)[0][-1]
        raw = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        raw.connect(addr)
        return ssl.wrap_socket(raw, server_hostname=host)
