#
# Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

APPLOAD?=RZ_NOFIP
$(eval $(call add_define,APPLOAD))
include plat/renesas/rz/common/rz_common.mk
include plat/renesas/rz/board/${BOARD}/rz_board.mk
include plat/renesas/rz/soc/${PLAT}/rz_xspi.mk

PLAT_INCLUDES	+=	-Iplat/renesas/rz/soc/a3m/include

DDR_SOURCES += plat/renesas/rz/soc/a3m/drivers/ddr/ddr_a3m.c

RZA3 := 1
RZA3M := 1
DEVICE_TYPE := 1
ARCH_TYPE := ARMv8A
LOG_LEVEL := 10
ifeq (${SOC_TYPE},2)
DEVICE_TYPE := 2
endif
RZA3_XSPI_MEMORY_BASE := 0x20000000

$(eval $(call add_define,RZA3))
$(eval $(call add_define,RZA3M))
$(eval $(call add_define,DEVICE_TYPE))
$(eval $(call add_define,ARCH_TYPE))
$(eval $(call add_define,RZA3_XSPI_MEMORY_BASE))

# set file name
RZ_ELF:=$(BUILD_PLAT)/rz$(BOARD)_ipl.elf
BL2_ELF:=$(BUILD_PLAT)/bl2/bl2.elf
RZ_BIN:=$(BUILD_PLAT)/rz$(BOARD)_ipl.bin
BL2_BIN:=$(BUILD_PLAT)/bl2.bin
RZ_MAP:=$(BUILD_PLAT)/rz$(BOARD)_ipl.map
BL2_MAP:=$(BUILD_PLAT)/bl2/bl2.map
RZ_DUMP:=$(BUILD_PLAT)/rz$(BOARD)_ipl.dump
BL2_DUMP:=$(BUILD_PLAT)/bl2/bl2.dump
RZ_SREC:=$(BUILD_PLAT)/rz$(BOARD)_ipl.srec

bl2: $(RZ_ELF) $(RZ_BIN) $(RZ_LINKER) $(RZ_MAP) $(RZ_DUMP) $(RZ_SREC)

$(RZ_ELF): $(BL2_ELF)
	$(call SHELL_COPY,$<,$@)

$(RZ_BIN): $(BL2_BIN)
	@echo "  IMG     $@"
ifeq ($(NAND),1)
	$(Q)/usr/bin/perl ./plat/renesas/rz/soc/a3m/rz_image_nand.pl "$<" "$@"
else
	$(Q)/usr/bin/perl ./plat/renesas/rz/soc/a3m/rz_image.pl "$<" "$@"
endif

$(BL2_MAP): $(BL2_ELF)
$(RZ_MAP): $(BL2_MAP)
	$(call SHELL_COPY,$<,$@)

$(RZ_DUMP): $(BL2_DUMP)
	$(call SHELL_COPY,$<,$@)

$(RZ_SREC): $(RZ_BIN)
	@echo "  SREC    $@"
	$(Q)$(OC) -I binary -O srec --adjust-vma=0x20000000 --srec-forceS3 "$<" "$@"

ifeq (${RZ_TEST},1)
-include plat/renesas/rz/common/drivers/tests/rz_test.mk
endif
