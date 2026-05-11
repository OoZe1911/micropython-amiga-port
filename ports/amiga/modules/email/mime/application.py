# email.mime.application -- MIMEApplication for binary attachments.

from email.mime.base import MIMEBase


class MIMEApplication(MIMEBase):
    def __init__(self, _data, _subtype="octet-stream",
                 _encoder=None, *, policy=None, **_params):
        if _encoder is None:
            from email.encoders import encode_base64
            _encoder = encode_base64
        MIMEBase.__init__(self, "application", _subtype,
                          policy=policy, **_params)
        self.set_payload(_data)
        _encoder(self)
