# email.mime.multipart -- MIMEMultipart container.

import time
from email.mime.base import MIMEBase


_BOUNDARY_COUNTER = 0


def _generate_boundary():
    global _BOUNDARY_COUNTER
    _BOUNDARY_COUNTER += 1
    try:
        u = time.ticks_us()
    except AttributeError:
        u = int(time.time() * 1000000)
    return "===============%d.%d==" % (u, _BOUNDARY_COUNTER)


class MIMEMultipart(MIMEBase):
    def __init__(self, _subtype="mixed", boundary=None, _subparts=None,
                 *, policy=None, **_params):
        MIMEBase.__init__(self, "multipart", _subtype,
                          policy=policy, **_params)
        self._payload = []
        if boundary is None:
            boundary = _generate_boundary()
        self.set_boundary(boundary)
        if _subparts:
            for p in _subparts:
                self.attach(p)
