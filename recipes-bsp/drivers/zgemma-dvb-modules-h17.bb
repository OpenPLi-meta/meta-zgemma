KV = "4.10.12"
SRCDATE = "20240626"

PROVIDES += "virtual/blindscan-dvbs"
RPROVIDES:${PN} += "virtual/blindscan-dvbs"

require zgemma-dvb-modules.inc

SRC_URI[arm.md5sum] = "d3da7bd69ab567fcc0773c8cb8af64d9"
SRC_URI[arm.sha256sum] = "aefbb682e90b2b80fd15e50d70f0e7e23615a303dcf7988cec6c687fc1225bae"

COMPATIBLE_MACHINE = "h17"
