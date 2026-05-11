# email.header -- RFC 2047 encoded-word builder.
#
# Phase 1: encoding only. Decoding of received headers will arrive with
# the parser in Phase 2.

import base64


def _is_ascii(s):
    # MicroPython 1.28's str.encode("ascii") does NOT validate -- check
    # codepoints directly.
    for ch in s:
        if ord(ch) > 127:
            return False
    return True


def _b_encode_chunk(text, charset):
    # Produce a single =?charset?B?base64?= encoded-word for `text`.
    raw = text.encode(charset)
    enc = base64.b64encode(raw).decode("ascii")
    return "=?%s?B?%s?=" % (charset, enc)


class Header:
    def __init__(self, s=None, charset=None, maxlinelen=None,
                 header_name=None, continuation_ws=" ", errors="strict"):
        self._chunks = []
        if s is not None:
            self.append(s, charset, errors)
        self._maxlinelen = maxlinelen if maxlinelen is not None else 76
        self._continuation_ws = continuation_ws

    def append(self, s, charset=None, errors="strict"):
        if charset is None:
            charset = "us-ascii" if _is_ascii(s) else "utf-8"
        self._chunks.append((s, charset))

    def encode(self, splitchars=";, \t", maxlinelen=None, linesep="\n"):
        if maxlinelen is None:
            maxlinelen = self._maxlinelen
        out = []
        for text, charset in self._chunks:
            if charset == "us-ascii" or _is_ascii(text):
                out.append(text)
                continue
            # Split into chunks small enough that the encoded-word stays
            # under maxlinelen. Encoded UTF-8 base64 grows ~4/3 of byte
            # length; we account for the =?utf-8?B??= wrapper (12 chars).
            wrapper = 12 + len(charset)
            budget = maxlinelen - wrapper
            if budget < 16:
                budget = 16
            # Decode budget back to bytes (3 bytes -> 4 b64 chars).
            byte_budget = (budget // 4) * 3
            data = text.encode(charset)
            i = 0
            pieces = []
            while i < len(data):
                # Find a UTF-8 boundary so we don't split mid-codepoint.
                end = i + byte_budget
                if end >= len(data):
                    end = len(data)
                else:
                    # Back up while top bits indicate continuation byte.
                    while end > i and (data[end] & 0xC0) == 0x80:
                        end -= 1
                    if end == i:
                        end = i + byte_budget
                pieces.append(_b_encode_chunk(
                    data[i:end].decode(charset), charset))
                i = end
            out.append(" ".join(pieces))
        return " ".join(out)

    def __str__(self):
        return self.encode()
