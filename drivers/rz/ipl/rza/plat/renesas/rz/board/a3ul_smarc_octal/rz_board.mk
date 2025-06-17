#
# Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

XSPI1_DEVICE?=octaflash_mx66uw
XSPI1_IF_OPTION?=.device_size=128*1024*1024
XSPI2_DEVICE?=octaram_apsxx
XSPI2_IF_OPTION?=.device_size=64*1024*1024
XSPI_DEVICE_TYPE:=OCTA

NAND:=0
RZ_FLASH_SIZE ?= 134217728 # 128MB
$(eval $(call add_define,RZ_FLASH_SIZE))

ifneq (${USE_SDRAM},0)
DDR_SOURCES	+=	plat/renesas/rz/soc/${PLAT}/drivers/ddr/param_mc_C-011_D4-01-2.c	\
				plat/renesas/rz/common/drivers/ddr/param_swizzle_T3bcud2.c

DDR_PLL4	:= 1600
$(eval $(call add_define,DDR_PLL4))
endif
$(eval $(call add_define_val,XSPI_DEVICE_TYPE,\"${XSPI_DEVICE_TYPE}\"))
