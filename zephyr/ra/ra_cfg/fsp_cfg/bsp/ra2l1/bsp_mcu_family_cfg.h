/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_FAMILY_CFG_H_
#define BSP_MCU_FAMILY_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "bsp_mcu_device_pn_cfg.h"
#include "bsp_mcu_device_cfg.h"
#include "bsp_mcu_info.h"
#include "bsp_clock_cfg.h"
#define BSP_MCU_GROUP_RA2L1 (1)
#define BSP_LOCO_HZ                 (DT_PROP_OR(DT_NODELABEL(loco), clock_frequency, 0))
#define BSP_MOCO_HZ                 (DT_PROP_OR(DT_NODELABEL(moco), clock_frequency, 0))
#define BSP_SUB_CLOCK_HZ            (DT_PROP_OR(DT_NODELABEL(subclk), clock_frequency, 0))
#if   BSP_CFG_HOCO_FREQUENCY == 0
#define BSP_HOCO_HZ             (24000000)
#elif BSP_CFG_HOCO_FREQUENCY == 2
#define BSP_HOCO_HZ             (32000000)
#elif BSP_CFG_HOCO_FREQUENCY == 4
#define BSP_HOCO_HZ             (48000000)
#elif BSP_CFG_HOCO_FREQUENCY == 5
#define BSP_HOCO_HZ             (64000000)
#else
#error "Invalid HOCO frequency chosen (BSP_CFG_HOCO_FREQUENCY) in bsp_clock_cfg.h"
#endif

#define BSP_CORTEX_VECTOR_TABLE_ENTRIES    (16U)
#define BSP_VECTOR_TABLE_MAX_ENTRIES       (48U)
#define BSP_CFG_INLINE_IRQ_FUNCTIONS       (0)

/* OFS0 WDT configurations */
#ifdef CONFIG_WDT_RENESAS_RA_START_IN_BOOT
#define WDTSTRT    (0)
#else
#define WDTSTRT    (1)
#endif

#define OFS_SEQ1 0xA001A001 | (1 << 1) | (3 << 2)
#define OFS_SEQ2 (15 << 4) | (3 << 8) | (3 << 10)
#define OFS_SEQ3 (1 << 12) | (1 << 14) | (WDTSTRT << 17)
#define OFS_SEQ4 (3 << 18) | (15 << 20) | (3 << 24) | (3 << 26)
#define OFS_SEQ5 (1 << 28) | (1 << 30)
#define BSP_CFG_USE_LOW_VOLTAGE_MODE (0)
#define BSP_CFG_ROM_REG_OFS0 (OFS_SEQ1 | OFS_SEQ2 | OFS_SEQ3 | OFS_SEQ4 | OFS_SEQ5)
#define BSP_CFG_ROM_REG_OFS1_ICSATS (1 << 31)
#define BSP_CFG_ROM_REG_OFS1 (0x7FFFFEC3 | (1 << 2) | (3 << 3) | (0 << 8) | (BSP_CFG_ROM_REG_OFS1_ICSATS))
#define BSP_CFG_ROM_REG_MPU_PC0_ENABLE (1)
#define BSP_CFG_ROM_REG_MPU_PC0_START (0x000FFFFC)
#define BSP_CFG_ROM_REG_MPU_PC0_END (0x000FFFFF)
#define BSP_CFG_ROM_REG_MPU_PC1_ENABLE (1)
#define BSP_CFG_ROM_REG_MPU_PC1_START (0x000FFFFC)
#define BSP_CFG_ROM_REG_MPU_PC1_END (0x000FFFFF)
#define BSP_CFG_ROM_REG_MPU_REGION0_ENABLE (1)
#define BSP_CFG_ROM_REG_MPU_REGION0_START (0x000FFFFC)
#define BSP_CFG_ROM_REG_MPU_REGION0_END (0x000FFFFF)
#define BSP_CFG_ROM_REG_MPU_REGION1_ENABLE (1)
#define BSP_CFG_ROM_REG_MPU_REGION1_START (0x200FFFFC)
#define BSP_CFG_ROM_REG_MPU_REGION1_END (0x200FFFFF)
#define BSP_CFG_ROM_REG_MPU_REGION2_ENABLE (1)
#define BSP_CFG_ROM_REG_MPU_REGION2_START (0x407FFFFC)
#define BSP_CFG_ROM_REG_MPU_REGION2_END (0x407FFFFF)
#define BSP_CFG_ROM_REG_MPU_REGION3_ENABLE (1)
#define BSP_CFG_ROM_REG_MPU_REGION3_START (0x400DFFFC)
#define BSP_CFG_ROM_REG_MPU_REGION3_END (0x400DFFFF)

#ifndef BSP_CLOCK_CFG_MAIN_OSC_WAIT
#define BSP_CLOCK_CFG_MAIN_OSC_WAIT (9)
#endif
/* Used to create IELS values for the interrupt initialization table g_interrupt_event_link_select. */
#define BSP_PRV_IELS_ENUM(vector)    CONCAT(ICU_, vector)

#define BSP_CFG_DCDC_ENABLE          (0)
#define BSP_CFG_DCDC_VOLTAGE_RANGE   (BSP_POWER_MODE_DCDC_2V7_TO_3V6)
/*
 ID Code
 Note: To lock and disable the debug interface define BSP_ID_CODE_LOCKED in compiler settings.
 WARNING: This will disable debug access to the part. However, ALeRASE command will be accepted, which will clear (reset) the ID code. After clearing ID code, debug access will be enabled.
 Please read the HWM for full details of the clearing process.
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

#if (0)
#define BSP_SECTION_FLASH_GAP BSP_PLACE_IN_SECTION(".flash_gap")
#endif

#ifdef __cplusplus
}
#endif
#endif /* BSP_MCU_FAMILY_CFG_H_ */
