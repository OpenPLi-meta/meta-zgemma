SUMMARY = "${MACHINE} parameters files"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
PR = "${SRCDATE}"
PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit deploy

SRC_URI = "http://downloads.openpli.org/archive/zgemma/zgemma-recovery-${HICHIPSET}-${SRCDATE}.zip"

S = "${WORKDIR}"

ALLOW_EMPTY_${PN} = "1"
do_configure[nostamp] = "1"

do_deploy() {
    install -d ${DEPLOY_DIR_IMAGE}/zgemma-partitions-${MACHINE}/${MACHINE}
    install -m 0755 ${WORKDIR}/recovery-${MACHINE}.bin ${DEPLOY_DIR_IMAGE}/zgemma-partitions-${MACHINE}/${MACHINE}/recovery.bin
}

addtask deploy before do_build after do_install

INSANE_SKIP_${PN} += "already-stripped"
