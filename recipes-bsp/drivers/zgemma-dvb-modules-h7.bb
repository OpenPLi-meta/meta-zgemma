KV = "4.10.12"
SRCDATE = "20190405"

PROVIDES = "virtual/blindscan-dvbs"

require zgemma-dvb-modules.inc

SRC_URI[arm.md5sum] = "b780fddcc2dc6b831fe27e5fea61a353"
SRC_URI[arm.sha256sum] = "841a04aa481c20eb1c972c0a169ceb65f910a10724b4a0ed6324fefcdcfb8f71"

COMPATIBLE_MACHINE = "h7"