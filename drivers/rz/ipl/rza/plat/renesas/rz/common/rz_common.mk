#
# Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

BL2_AT_EL3						:= 1
COLD_BOOT_SINGLE_CPU			:= 1
PROGRAMMABLE_RESET_ADDRESS		:= 1
WARMBOOT_ENABLE_DCACHE_EARLY	:= 1
GICV3_SUPPORT_GIC600			:= 1
HW_ASSISTED_COHERENCY			:= 1
USE_COHERENT_MEM				:= 0
TRUSTED_BOARD_BOOT				:= 0
PROTECTED_CHIPID				:= 1
DEBUG_RZG2L_FPGA				:= 0
$(eval $(call add_define,PROTECTED_CHIPID))
$(eval $(call add_define,DEBUG_RZG2L_FPGA))

WA_RZG2L_GIC64BIT				:= 1
$(eval $(call add_define,WA_RZG2L_GIC64BIT))

ifeq (${DEBUG_RZG2L_FPGA}, 0)
  USE_SDRAM ?= 1
else
  USE_SDRAM ?= 0
endif
$(eval $(call add_define,USE_SDRAM))

USE_EMMC?=0
$(eval $(call add_define,USE_EMMC))

# Enable workarounds for selected Cortex-A55 erratas.
ERRATA_A55_1530923				:= 1

ifeq (${APPLOAD},RZ_NOFIP)
FSP_BASE ?= 0x20020000
$(eval $(call add_define,FSP_BASE))
endif

PLAT_INCLUDES		:=	-Iplat/renesas/rz/common/include								\
						-Iplat/renesas/rz/common/drivers/emmc							\
						-Iplat/renesas/rz/common/drivers/io								\
						-Idrivers/renesas/common/io

RZ_TIMER_SOURCES	:=	drivers/delay_timer/generic_delay_timer.c		\
						drivers/delay_timer/delay_timer.c

ifneq (${USE_SDRAM}, 0)
DDR_SOURCES		:= plat/renesas/rz/common/drivers/ddr/ddr.c
endif

ifneq (${ARCH_TYPE}, 0)
MMU_SOURCE		:= plat/renesas/rz/common/drivers/rza_mmu/ARMv8A/rza_mmu.c
endif

BL2_SOURCES		+=	lib/cpus/aarch64/cortex_a55.S						\
					${RZ_TIMER_SOURCES}									\
					${DYN_CFG_SOURCES}									\
					common/desc_image_load.c							\
					drivers/io/io_storage.c								\
					drivers/io/io_memmap.c								\
					drivers/io/io_fip.c									\
					drivers/arm/tzc/tzc400.c							\
					plat/renesas/rz/common/drivers/io/io_emmcdrv.c		\
					plat/renesas/rz/common/drivers/emmc/emmc_interrupt.c\
					plat/renesas/rz/common/drivers/emmc/emmc_utility.c	\
					plat/renesas/rz/common/drivers/emmc/emmc_mount.c	\
					plat/renesas/rz/common/drivers/emmc/emmc_init.c		\
					plat/renesas/rz/common/drivers/emmc/emmc_read.c		\
					plat/renesas/rz/common/drivers/emmc/emmc_cmd.c		\
					plat/renesas/rz/common/bl2_plat_setup.c				\
					plat/renesas/rz/common/bl2_plat_mem_params_desc.c	\
					plat/renesas/rz/common/plat_image_load.c			\
					plat/renesas/rz/common/plat_storage.c				\
					plat/renesas/rz/common/plat_security.c				\
					plat/renesas/rz/common/aarch64/plat_helpers.S		\
					plat/renesas/rz/common/drivers/syc.c				\
					plat/renesas/rz/common/drivers/pfc.c				\
					plat/renesas/rz/common/drivers/cpg.c				\
					${DDR_SOURCES}										\
					${XSPI_SOURCES}							\
					${MMU_SOURCE}

# Include GICv3 driver files
GICV3_IMPL		:= GIC600
include drivers/arm/gic/v3/gicv3.mk

# BL2 only for RZ/A3UL
ifneq (${PLAT},a3ul)
ifneq (${PLAT},a3m)
BL31_SOURCES	+=	lib/cpus/aarch64/cortex_a55.S					\
					${GICV3_SOURCES}								\
					drivers/arm/tzc/tzc400.c						\
					plat/common/plat_gicv3.c						\
					plat/common/plat_psci_common.c					\
					plat/renesas/rz/common/bl31_plat_setup.c		\
					plat/renesas/rz/common/plat_pm.c				\
					plat/renesas/rz/common/plat_topology.c			\
					plat/renesas/rz/common/plat_gic.c				\
					plat/renesas/rz/common/plat_security.c			\
					plat/renesas/rz/common/rz_plat_sip_handler.c	\
					plat/renesas/rz/common/rz_sip_svc.c				\
					plat/renesas/rz/common/aarch64/plat_helpers.S	\
					plat/renesas/rz/common/drivers/syc.c
endif
endif

include lib/xlat_tables_v2/xlat_tables.mk
PLAT_BL_COMMON_SOURCES	+=	${XLAT_TABLES_LIB_SRCS}					\
							plat/renesas/rz/common/plat_rz_common.c	\
							plat/renesas/rz/common/drivers/scifa.S

ifneq (${TRUSTED_BOARD_BOOT},0)

	# Include common TBB sources
	AUTH_SOURCES	:=	drivers/auth/img_parser_mod.c

	# Include the selected chain of trust sources.
	ifeq (${COT},tbbr)
		AUTH_SOURCES	+=	plat/renesas/rz/common/drivers/auth/tbbr/tbbr_cot.c
	else
		$(error Unknown chain of trust ${COT})
	endif

	# Include RZ TBB sources
	AUTH_SOURCES	+=	plat/renesas/rz/common/drivers/auth/auth_mod.c				\
						plat/renesas/rz/common/drivers/auth/sblib/crypto_sblib.c	\
						plat/renesas/rz/common/drivers/auth/sblib/sblib_parser.c


	BL2_SOURCES		+=	${AUTH_SOURCES}

endif
