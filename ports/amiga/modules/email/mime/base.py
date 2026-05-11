# email.mime.base -- MIMEBase, the root of MIME container types.

from email.message import Message


class MIMEBase(Message):
    def __init__(self, _maintype, _subtype, *, policy=None, **_params):
        Message.__init__(self, policy)
        self["MIME-Version"] = "1.0"
        ctype = "%s/%s" % (_maintype, _subtype)
        self.add_header("Content-Type", ctype, **_params)
