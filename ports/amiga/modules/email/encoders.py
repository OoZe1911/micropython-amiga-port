# email.encoders -- Content-Transfer-Encoding helpers.
#
# Each function takes a Message, mutates its payload in place, and sets
# the Content-Transfer-Encoding header.

import base64


def _wrap(data, cols=76):
    # data is str -- wrap at `cols` characters with \r\n.
    out = []
    for i in range(0, len(data), cols):
        out.append(data[i:i + cols])
    return "\r\n".join(out)


def encode_base64(msg):
    payload = msg.get_payload()
    if isinstance(payload, str):
        raw = payload.encode("utf-8")
    elif payload is None:
        raw = b""
    else:
        raw = bytes(payload)
    enc = base64.b64encode(raw).decode("ascii")
    msg.set_payload(_wrap(enc))
    if "Content-Transfer-Encoding" in msg:
        msg.replace_header("Content-Transfer-Encoding", "base64")
    else:
        msg["Content-Transfer-Encoding"] = "base64"


def _qp_encode_bytes(raw):
    # Minimal quoted-printable: bytes >= 128, '=', and trailing whitespace
    # on a line get encoded; everything else passes through. Lines wrap at
    # 76 chars with soft-break `=\r\n`.
    out = []
    line = []
    line_len = 0
    for b in raw:
        if b == 0x0A:  # LF -- emit a hard line break
            # Drop a trailing space/tab before the newline: must be encoded
            # to survive transport.
            if line and line[-1] in (" ", "\t"):
                ch = line.pop()
                line_len -= 1
                line.append("=%02X" % ord(ch))
                line_len += 3
            out.append("".join(line))
            line = []
            line_len = 0
            continue
        if b == 0x0D:
            # Skip stray CR -- LF will produce the newline.
            continue
        if b == 0x3D or b < 32 or b > 126:
            piece = "=%02X" % b
        else:
            piece = chr(b)
        if line_len + len(piece) > 75:
            line.append("=")
            out.append("".join(line))
            line = []
            line_len = 0
        line.append(piece)
        line_len += len(piece)
    if line:
        out.append("".join(line))
    return "\r\n".join(out)


def encode_quopri(msg):
    payload = msg.get_payload()
    if isinstance(payload, str):
        raw = payload.encode("utf-8")
    elif payload is None:
        raw = b""
    else:
        raw = bytes(payload)
    try:
        import binascii
        qp = binascii.b2a_qp(raw).decode("ascii")
    except (AttributeError, ImportError):
        qp = _qp_encode_bytes(raw)
    msg.set_payload(qp)
    if "Content-Transfer-Encoding" in msg:
        msg.replace_header("Content-Transfer-Encoding", "quoted-printable")
    else:
        msg["Content-Transfer-Encoding"] = "quoted-printable"


def encode_7or8bit(msg):
    payload = msg.get_payload()
    if isinstance(payload, str):
        raw = payload.encode("utf-8")
    elif payload is None:
        raw = b""
    else:
        raw = bytes(payload)
    cte = "7bit"
    for b in raw:
        if b >= 128:
            cte = "8bit"
            break
    if "Content-Transfer-Encoding" in msg:
        msg.replace_header("Content-Transfer-Encoding", cte)
    else:
        msg["Content-Transfer-Encoding"] = cte


def encode_noop(msg):
    pass
