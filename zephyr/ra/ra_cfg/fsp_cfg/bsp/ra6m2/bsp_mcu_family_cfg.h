/*
 * Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BSP_MCU_FAMILY_CFG_H_
#define BSP_MCU_FAMILY_CFG_H_
#include "bsp_mcu_device_pn_cfg.h"
#include "bsp_mcu_device_cfg.h"
#include "bsp_clock_cfg.h"
#include "bsp_mcu_info.h"
#define BSP_MCU_GROUP_RA6M2 (1)
#define BSP_LOCO_HZ                 (DT_PROP_OR(DT_NODELABEL(loco), clock_frequency, 0))
#define BSP_MOCO_HZ                 (DT_PROP_OR(DT_NODELABEL(moco), clock_frequency, 0))
#define BSP_SUB_CLOCK_HZ 			(DT_PROP_OR(DT_NODELABEL(subclk), clock_frequency, 0))
#if BSP_CFG_HOCO_FREQUENCY == 0
#define BSP_HOCO_HZ (16000000)
#elif BSP_CFG_HOCO_FREQUENCY == 1
#define BSP_HOCO_HZ (18000000)
#elif BSP_CFG_HOCO_FREQUENCY == 2
#define BSP_HOCO_HZ (20000000)
#else
#error "Invalid HOCO frequency chosen (BSP_CFG_HOCO_FREQUENCY) in bsp_clock_cfg.h"
#endif

#define BSP_CFG_FLL_ENABLE (0)

#define BSP_CORTEX_VECTOR_TABLE_ENTRIES (16U)
#define BSP_VECTOR_TABLE_MAX_ENTRIES	(112U)
#define BSP_CFG_INLINE_IRQ_FUNCTIONS	(1)

#define OFS_SEQ1			   0xA001A001 | (1 << 1) | (3 << 2)
#define OFS_SEQ2			   (15 << 4) | (3 << 8) | (3 << 10)
#define OFS_SEQ3			   (1 << 12) | (1 << 14) | (1 << 17)
#define OFS_SEQ4			   (3 << 18) | (15 << 20) | (3 << 24) | (3 << 26)
#define OFS_SEQ5			   (1 << 28) | (1 << 30)
#define BSP_CFG_ROM_REG_OFS0		   (OFS_SEQ1 | OFS_SEQ2 | OFS_SEQ3 | OFS_SEQ4 | OFS_SEQ5)
#define BSP_CFG_ROM_REG_OFS1		   (0xFFFFFEF8 | (1 << 2) | (3) | (1 << 8))
#define BSP_CFG_ROM_REG_MPU_PC0_ENABLE	   (1)
#define BSP_CFG_ROM_REG_MPU_PC0_START	   (0xFFFFFFFC)
#define BSP_CFG_ROM_REG_MPU_PC0_END	   (0xFFFFFFFF)
#define BSP_CFG_ROM_REG_MPU_PC1_ENABLE	   (1)
#define BSP_CFG_ROM_REG_MPU_PC1_START	   (0xFFFFFFFC)
#define BSP_CFG_ROM_REG_MPU_PC1_END	   (0xFFFFFFFF)
#define BSP_CFG_ROM_REG_MPU_REGION0_ENABLE (1)
#define BSP_CFG_ROM_REG_MPU_REGION0_START  (0x00FFFFFC)
#define BSP_CFG_ROM_REG_MPU_REGION0_END	   (0x00FFFFFF)
#define BSP_CFG_ROM_REG_MPU_REGION1_ENABLE (1)
#define BSP_CFG_ROM_REG_MPU_REGION1_START  (0x200FFFFC)
#define BSP_CFG_ROM_REG_MPU_REGION1_END	   (0x200FFFFF)
#define BSP_CFG_ROM_REG_MPU_REGION2_ENABLE (1)
#define BSP_CFG_ROM_REG_MPU_REGION2_START  (0x407FFFFC)
#define BSP_CFG_ROM_REG_MPU_REGION2_END	   (0x407FFFFF)
#define BSP_CFG_ROM_REG_MPU_REGION3_ENABLE (1)
#define BSP_CFG_ROM_REG_MPU_REGION3_START  (0x400DFFFC)
#define BSP_CFG_ROM_REG_MPU_REGION3_END	   (0x400DFFFF)
#ifndef BSP_CLOCK_CFG_MAIN_OSC_WAIT
#define BSP_CLOCK_CFG_MAIN_OSC_WAIT (9)
#endif
/* Used to create IELS values for the interrupt initialization table g_interrupt_event_link_select.
 */
#define BSP_PRV_IELS_ENUM(vector) (ELC_##vector)

/*
 * ID Code
 * Note: To lock and disable the debug interface define BSP_ID_CODE_LOCKED in compiler settings.
 * WARNING: This will disable debug access to the part. However, ALeRASE command will be accepted,
 * which will clear (reset) the ID code. After clearing ID code, debug access will be enabled.
 */
#if defined(BSP_ID_CODE_LOCKED)
#define BSP_CFG_ID_CODE_LONG_1 (0x00000000)
#define BSP_CFG_ID_CODE_LONG_2 (0x00000000)
#define BSP_CFG_ID_CODE_LONG_3 (0x00000000)
#define BSP_CFG_ID_CODE_LONG_4 (0x00000000)
#else
/* ID CODE: FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF */
#define BSP_CFG_ID_CODE_LONG_1 (0xFFFFFFFF)
#define BSP_CFG_ID_CODE_LONG_2 (0xFFFFFFFF)
#define BSP_CFG_ID_CODE_LONG_3 (0xFFFFFFFF)
#define BSP_CFG_ID_CODE_LONG_4 (0xffFFFFFF)
#endif

/* SDRAM controller configuration */
#if DT_NODE_HAS_STATUS_OKAY(DT_INST(0, renesas_ra_sdram))
#define BSP_CFG_SDRAM_TRAS                                                                         \
	DT_PROP_BY_IDX(DT_CHILD(DT_INST(0, renesas_ra_sdram), bank_0), renesas_ra_sdram_timing, 0)
#define BSP_CFG_SDRAM_TRCD                                                                         \
	DT_PROP_BY_IDX(DT_CHILD(DT_INST(0, renesas_ra_sdram), bank_0), renesas_ra_sdram_timing, 1)
#define BSP_CFG_SDRAM_TRP                                                                          \
	DT_PROP_BY_IDX(DT_CHILD(DT_INST(0, renesas_ra_sdram), bank_0), renesas_ra_sdram_timing, 2)
#define BSP_CFG_SDRAM_TWR                                                                          \
	DT_PROP_BY_IDX(DT_CHILD(DT_INST(0, renesas_ra_sdram), bank_0), renesas_ra_sdram_timing, 3)
#define BSP_CFG_SDRAM_TCL                                                                          \
	DT_PROP_BY_IDX(DT_CHILD(DT_INST(0, renesas_ra_sdram), bank_0), renesas_ra_sdram_timing, 4)
#define BSP_CFG_SDRAM_TRFC                                                                         \
	DT_PROP_BY_IDX(DT_CHILD(DT_INST(0, renesas_ra_sdram), bank_0), renesas_ra_sdram_timing, 5)
#define BSP_CFG_SDRAM_TREFW                                                                        \
	DT_PROP_BY_IDX(DT_CHILD(DT_INST(0, renesas_ra_sdram), bank_0), renesas_ra_sdram_timing, 6)
#define BSP_CFG_SDRAM_INIT_ARFI            DT_PROP(DT_INST(0, renesas_ra_sdram), auto_refresh_interval)
#define BSP_CFG_SDRAM_INIT_ARFC            DT_PROP(DT_INST(0, renesas_ra_sdram), auto_refresh_count)
#define BSP_CFG_SDRAM_INIT_PRC             DT_PROP(DT_INST(0, renesas_ra_sdram), precharge_cycle_count)
#define BSP_CFG_SDRAM_MULTIPLEX_ADDR_SHIFT DT_ENUM_IDX(DT_INST(0, renesas_ra_sdram), multiplex_addr_shift)
#define BSP_CFG_SDRAM_ENDIAN_MODE          DT_ENUM_IDX(DT_INST(0, renesas_ra_sdram), edian_mode)
#define BSP_CFG_SDRAM_ACCESS_MODE          DT_PROP(DT_INST(0, renesas_ra_sdram), continuous_access)
#define BSP_CFG_SDRAM_BUS_WIDTH            DT_ENUM_IDX(DT_INST(0, renesas_ra_sdram), bus_width)
#else
#define BSP_CFG_SDRAM_TRAS 					(0)
#define BSP_CFG_SDRAM_TRCD 					(0)
#define BSP_CFG_SDRAM_TRP 					(0)
#define BSP_CFG_SDRAM_TWR 					(0)
#define BSP_CFG_SDRAM_TCL 					(0)
#define BSP_CFG_SDRAM_TRFC 					(0)
#define BSP_CFG_SDRAM_TREFW 				(0)
#define BSP_CFG_SDRAM_INIT_ARFI 			(0)
#define BSP_CFG_SDRAM_INIT_ARFC 			(0)
#define BSP_CFG_SDRAM_INIT_PRC 				(0)
#define BSP_CFG_SDRAM_MULTIPLEX_ADDR_SHIFT 	(0)
#define BSP_CFG_SDRAM_ENDIAN_MODE 			(0)
#define BSP_CFG_SDRAM_ACCESS_MODE 			(0)
#define BSP_CFG_SDRAM_BUS_WIDTH 			(0)
#endif	/* DT_NODE_HAS_STATUS_OKAY(DT_INST(0, renesas_ra_sdram)) */

#endif /* BSP_MCU_FAMILY_CFG_H_ */
