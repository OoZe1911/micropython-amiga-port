# email.utils -- helpers for RFC 2822 dates, addresses and message IDs.

import time


_DAYS = ("Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun")
_MONTHS = ("Jan", "Feb", "Mar", "Apr", "May", "Jun",
           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec")


def _format_date(t, zone):
    # t is a 9-tuple from gmtime() / localtime()
    # (year, mon, mday, hour, min, sec, wday, yday, isdst)
    return "%s, %02d %s %04d %02d:%02d:%02d %s" % (
        _DAYS[t[6]], t[2], _MONTHS[t[1] - 1], t[0],
        t[3], t[4], t[5], zone,
    )


def formatdate(timeval=None, localtime=False, usegmt=False):
    if timeval is None:
        timeval = time.time()
    if usegmt:
        return _format_date(time.gmtime(timeval), "GMT")
    if localtime:
        try:
            lt = time.localtime(timeval)
            gt = time.gmtime(timeval)
        except Exception:
            return _format_date(time.gmtime(timeval), "+0000")
        # Compute offset from the difference between local and gmt tuples.
        # On AmigaOS time.localtime applies loc_GMTOffset, so this gives
        # the correct sign and magnitude without relying on time.timezone.
        offset = _tuple_to_secs(lt) - _tuple_to_secs(gt)
        sign = "+" if offset >= 0 else "-"
        offset = abs(offset)
        hh = offset // 3600
        mm = (offset % 3600) // 60
        return _format_date(lt, "%s%02d%02d" % (sign, hh, mm))
    return _format_date(time.gmtime(timeval), "+0000")


def _tuple_to_secs(t):
    # Rough seconds-since-epoch using the calendar formula. Good enough
    # for differencing localtime and gmtime to extract the UTC offset --
    # we don't need timezone-correct epochs here.
    y, m, d, hh, mm, ss = t[0], t[1], t[2], t[3], t[4], t[5]
    if m <= 2:
        y -= 1
        m += 12
    era = y // 400
    yoe = y - era * 400
    doy = (153 * (m - 3) + 2) // 5 + d - 1
    doe = yoe * 365 + yoe // 4 - yoe // 100 + doy
    days = era * 146097 + doe - 719468
    return days * 86400 + hh * 3600 + mm * 60 + ss


_SPECIALS = '()<>@,;:\\"[].'


def _quote_phrase(name):
    needs = False
    for ch in name:
        if ch in _SPECIALS:
            needs = True
            break
    if not needs:
        return name
    out = ['"']
    for ch in name:
        if ch == '"' or ch == "\\":
            out.append("\\")
        out.append(ch)
    out.append('"')
    return "".join(out)


def _is_ascii(s):
    # MicroPython 1.28's str.encode("ascii") does NOT validate -- it just
    # returns the UTF-8 bytes regardless. So we check codepoints directly.
    for ch in s:
        if ord(ch) > 127:
            return False
    return True


def formataddr(pair, charset="utf-8"):
    name, addr = pair
    if not name:
        return addr
    if _is_ascii(name):
        encoded = _quote_phrase(name)
    else:
        from email.header import Header
        encoded = Header(name, charset).encode()
    return "%s <%s>" % (encoded, addr)


def parseaddr(addr):
    # Minimal parser: handles "Name <addr>", "<addr>", "addr", and
    # "\"Quoted Name\" <addr>". Returns (realname, email).
    if not addr:
        return ("", "")
    s = addr.strip()
    lt = s.rfind("<")
    gt = s.rfind(">")
    if lt >= 0 and gt > lt:
        name = s[:lt].strip()
        email = s[lt + 1:gt].strip()
        if len(name) >= 2 and name[0] == '"' and name[-1] == '"':
            # Unquote and unescape backslash sequences.
            inner = name[1:-1]
            out = []
            i = 0
            while i < len(inner):
                c = inner[i]
                if c == "\\" and i + 1 < len(inner):
                    out.append(inner[i + 1])
                    i += 2
                else:
                    out.append(c)
                    i += 1
            name = "".join(out)
        return (name, email)
    return ("", s)


def getaddresses(fieldvalues):
    result = []
    for fv in fieldvalues:
        if not fv:
            continue
        # Split on commas at depth 0 (outside <...> and "...").
        parts = []
        buf = []
        depth_angle = 0
        in_quote = False
        i = 0
        while i < len(fv):
            c = fv[i]
            if c == '"' and (i == 0 or fv[i - 1] != "\\"):
                in_quote = not in_quote
                buf.append(c)
            elif not in_quote and c == "<":
                depth_angle += 1
                buf.append(c)
            elif not in_quote and c == ">":
                depth_angle -= 1
                buf.append(c)
            elif not in_quote and depth_angle == 0 and c == ",":
                parts.append("".join(buf))
                buf = []
            else:
                buf.append(c)
            i += 1
        if buf:
            parts.append("".join(buf))
        for p in parts:
            p = p.strip()
            if p:
                result.append(parseaddr(p))
    return result


def make_msgid(idstring=None, domain=None):
    # Unique id from time + a small counter; mixed with idstring if given.
    try:
        u = time.ticks_us()
    except AttributeError:
        u = int(time.time() * 1000000)
    global _MSGID_COUNTER
    try:
        _MSGID_COUNTER += 1
    except NameError:
        _MSGID_COUNTER = 1
    unique = "%d.%d" % (u, _MSGID_COUNTER)
    if idstring:
        unique = "%s.%s" % (unique, idstring)
    if domain is None:
        domain = _default_domain()
    return "<%s@%s>" % (unique, domain)


_MSGID_COUNTER = 0


def _default_domain():
    try:
        import socket
        if hasattr(socket, "gethostname"):
            h = socket.gethostname()
            if h:
                return h
    except Exception:
        pass
    return "amiga.localdomain"
