DESCRIPTION = "V3DDRIVER for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
PACKAGE_ARCH = "${MACHINE_ARCH}"
DEPENDS = "libdrm mesa patchelf-native"
PV = "${SRCDATE}"
PR = "r1"

PROVIDES = "virtual/libgles2 virtual/libgles1 virtual/egl virtual/libgbm"
RPROVIDES_${PN} = "libnxpl.so libnexus.so libv3ddriver.so libEGL.so.1.4 libEGL.so.1 libEGL.so libGLESv1_CM.so.1.1 libGLESv1_CM.so.1 libGLESv1_CM.so libGLESv2.so.2.0 libGLESv2.so.2 libGLESv2.so libgbm.so libgbm.so.1"

SRC_URI = "http://downloads.openpli.org/archive/zgemma/${MACHINE}-v3ddrivers-${SRCDATE}.zip"

S = "${WORKDIR}"

# The driver is a set of binary libraries to install
# there's nothing to configure or compile
do_configure[noexec] = "1"

do_install_append() {
    install -d ${D}${libdir}
    install -m 0755 ${S}/libnxpl.so ${D}${libdir}/
    install -m 0755 ${S}/libnexus.so ${D}${libdir}/
    install -m 0755 ${S}/libv3ddriver.so ${D}${libdir}/
    (cd ${D}/${libdir} && ln -sf libv3ddriver.so libEGL.so.1.4 \
    && ln -sf libEGL.so.1.4 libEGL.so.1 \
    && ln -sf libEGL.so.1 libEGL.so)
    (cd ${D}/${libdir} && ln -sf libv3ddriver.so libGLESv1_CM.so.1.1 \
    && ln -sf libGLESv1_CM.so.1.1 libGLESv1_CM.so.1 \
    && ln -sf libGLESv1_CM.so.1 libGLESv1_CM.so)
    (cd ${D}/${libdir} && ln -sf libv3ddriver.so libGLESv2.so.2.0 \
    && ln -sf libGLESv2.so.2.0 libGLESv2.so.2 \
    && ln -sf libGLESv2.so.2 libGLESv2.so)
    (cd ${D}/${libdir} && ln -sf libv3ddriver.so libgbm.so.1 \
    && ln -sf libgbm.so.1 libgbm.so)
}

do_package_qa() {
}

FILES_${PN} = "${libdir}"
FILES_${PN}-dev = "${incdir}"

INSANE_SKIP_${PN} += "already-stripped dev-so ldflags"

# The driver is missing EGL/GLES headers and pkgconfig files. Handle
# the conflicts as mesa and the driver are both providing the same shared libraries.
RREPLACES_${PN} = "libegl libegl1 libgles1 libglesv1-cm1 libgles2 libglesv2-2 libgbm"
RPROVIDES_${PN} = "libegl libegl1 libgles1 libglesv1-cm1 libgles2 libglesv2-2 libgbm"
RCONFLICTS_${PN} = "libegl libegl1 libgles1 libglesv1-cm1 libgles2 libglesv2-2 libgbm"
