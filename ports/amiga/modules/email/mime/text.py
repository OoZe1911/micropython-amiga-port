# email.mime.text -- MIMEText for text/* parts.

import base64
from email.mime.base import MIMEBase


def _is_ascii(s):
    # MicroPython 1.28's str.encode("ascii") does NOT validate -- check
    # codepoints directly.
    for ch in s:
        if ord(ch) > 127:
            return False
    return True


class MIMEText(MIMEBase):
    def __init__(self, _text, _subtype="plain", _charset=None, *, policy=None):
        if _charset is None:
            _charset = "us-ascii" if _is_ascii(_text) else "utf-8"
        MIMEBase.__init__(self, "text", _subtype,
                          policy=policy, charset=_charset)
        if _charset == "us-ascii":
            self.set_payload(_text)
            self["Content-Transfer-Encoding"] = "7bit"
        else:
            # base64-encode UTF-8 so transport is safe whatever the relay
            # is willing to push (Gmail is happy with 8bit, others aren't).
            enc = base64.b64encode(
                _text.encode(_charset)).decode("ascii")
            wrapped = "\r\n".join(
                enc[i:i + 76] for i in range(0, len(enc), 76))
            self.set_payload(wrapped)
            self["Content-Transfer-Encoding"] = "base64"
