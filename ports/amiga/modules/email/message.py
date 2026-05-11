# email.message -- minimal Message class for CPython-compatible MIME
# composition. Phase 1: composition / serialization only; parsing of
# received messages will arrive in Phase 2.


def _parse_params(value):
    # Split "type/sub; key=val; key2=\"v 2\"" into (main, {key: val, ...}).
    parts = []
    buf = []
    in_quote = False
    for ch in value:
        if ch == '"':
            in_quote = not in_quote
            buf.append(ch)
        elif ch == ";" and not in_quote:
            parts.append("".join(buf))
            buf = []
        else:
            buf.append(ch)
    if buf:
        parts.append("".join(buf))
    head = parts[0].strip() if parts else ""
    params = {}
    for p in parts[1:]:
        p = p.strip()
        if "=" in p:
            k, v = p.split("=", 1)
            v = v.strip()
            if len(v) >= 2 and v[0] == '"' and v[-1] == '"':
                v = v[1:-1]
            params[k.strip().lower()] = v
        else:
            params[p.lower()] = ""
    return head, params


def _format_params(**params):
    # CPython uses "_underscore" -> "-hyphen" for kwargs. Standard params
    # are lowercase; values get quoted only if they contain special chars.
    out = []
    for k, v in params.items():
        key = k.replace("_", "-").lower()
        sv = str(v)
        needs_quote = any(c in sv for c in ' ;,"\\\t\r\n')
        if needs_quote:
            sv = '"%s"' % sv.replace("\\", "\\\\").replace('"', '\\"')
        out.append("%s=%s" % (key, sv))
    return out


class Message:
    def __init__(self, policy=None):
        # policy accepted for API compat, ignored.
        self._headers = []          # list of (name, value)
        self._payload = None        # str | bytes | list[Message] | None
        self._charset = None
        self._default_type = "text/plain"

    # --- mapping interface ------------------------------------------------

    def __setitem__(self, name, value):
        self._headers.append((name, value))

    def __getitem__(self, name):
        ln = name.lower()
        for k, v in self._headers:
            if k.lower() == ln:
                return v
        return None

    def __delitem__(self, name):
        ln = name.lower()
        self._headers = [(k, v) for k, v in self._headers if k.lower() != ln]

    def __contains__(self, name):
        ln = name.lower()
        for k, _ in self._headers:
            if k.lower() == ln:
                return True
        return False

    def __len__(self):
        return len(self._headers)

    def __iter__(self):
        for k, _ in self._headers:
            yield k

    def keys(self):
        return [k for k, _ in self._headers]

    def values(self):
        return [v for _, v in self._headers]

    def items(self):
        return list(self._headers)

    def get(self, name, failobj=None):
        v = self[name]
        return failobj if v is None else v

    def get_all(self, name, failobj=None):
        ln = name.lower()
        out = [v for k, v in self._headers if k.lower() == ln]
        return out if out else failobj

    # --- header helpers ---------------------------------------------------

    def add_header(self, name, value, **params):
        parts = [str(value)]
        parts.extend(_format_params(**params))
        self._headers.append((name, "; ".join(parts)))

    def replace_header(self, name, value):
        ln = name.lower()
        for i, (k, _) in enumerate(self._headers):
            if k.lower() == ln:
                self._headers[i] = (k, value)
                return
        raise KeyError(name)

    # --- payload helpers --------------------------------------------------

    def set_payload(self, payload, charset=None):
        self._payload = payload
        if charset is not None:
            self.set_charset(charset)

    def get_payload(self, i=None, decode=False):
        # Phase 1: decode=True is a no-op (parser-side concern).
        if i is None:
            return self._payload
        if not isinstance(self._payload, list):
            raise TypeError("Not a multipart message")
        return self._payload[i]

    def attach(self, payload):
        if self._payload is None:
            self._payload = [payload]
        elif isinstance(self._payload, list):
            self._payload.append(payload)
        else:
            raise TypeError("Cannot attach to a non-multipart message")

    def is_multipart(self):
        return isinstance(self._payload, list)

    def walk(self):
        yield self
        if isinstance(self._payload, list):
            for sub in self._payload:
                for x in sub.walk():
                    yield x

    # --- content-type helpers --------------------------------------------

    def get_content_type(self):
        ct = self["Content-Type"]
        if ct is None:
            return self._default_type
        head, _ = _parse_params(ct)
        return head.lower() if head else self._default_type

    def get_content_maintype(self):
        return self.get_content_type().split("/", 1)[0]

    def get_content_subtype(self):
        ct = self.get_content_type()
        if "/" in ct:
            return ct.split("/", 1)[1]
        return ""

    def set_type(self, type_, header="Content-Type", requote=True):
        existing = self[header]
        if existing is None:
            self[header] = type_
            return
        _, params = _parse_params(existing)
        parts = [type_]
        for k, v in params.items():
            if v == "":
                parts.append(k)
            else:
                sv = v
                needs_quote = any(c in sv for c in ' ;,"\\\t\r\n')
                if needs_quote and requote:
                    sv = '"%s"' % sv.replace("\\", "\\\\").replace('"', '\\"')
                parts.append("%s=%s" % (k, sv))
        self.replace_header(header, "; ".join(parts))

    def set_default_type(self, type_):
        self._default_type = type_

    def get_boundary(self, failobj=None):
        ct = self["Content-Type"]
        if ct is None:
            return failobj
        _, params = _parse_params(ct)
        return params.get("boundary", failobj)

    def set_boundary(self, boundary):
        ct = self["Content-Type"]
        if ct is None:
            self["Content-Type"] = 'multipart/mixed; boundary="%s"' % boundary
            return
        head, params = _parse_params(ct)
        params["boundary"] = boundary
        parts = [head]
        for k, v in params.items():
            if v == "":
                parts.append(k)
            else:
                sv = v
                if any(c in sv for c in ' ;,"\\\t\r\n') or k == "boundary":
                    sv = '"%s"' % sv.replace("\\", "\\\\").replace('"', '\\"')
                parts.append("%s=%s" % (k, sv))
        self.replace_header("Content-Type", "; ".join(parts))

    def get_charset(self):
        return self._charset

    def set_charset(self, charset):
        self._charset = charset

    # --- serialization ----------------------------------------------------

    def as_string(self, unixfrom=False, maxheaderlen=0):
        out = []
        for k, v in self._headers:
            out.append("%s: %s\r\n" % (k, str(v)))
        out.append("\r\n")
        if isinstance(self._payload, list):
            boundary = self.get_boundary("=" * 16 + "boundary" + "=" * 2)
            for part in self._payload:
                out.append("--%s\r\n" % boundary)
                out.append(part.as_string())
                if not out[-1].endswith("\r\n"):
                    out.append("\r\n")
            out.append("--%s--\r\n" % boundary)
        elif self._payload is None:
            pass
        elif isinstance(self._payload, (bytes, bytearray)):
            out.append(self._payload.decode("latin-1"))
        else:
            out.append(str(self._payload))
        return "".join(out)

    def as_bytes(self, unixfrom=False):
        return self.as_string(unixfrom).encode("utf-8")

    def __str__(self):
        return self.as_string()
