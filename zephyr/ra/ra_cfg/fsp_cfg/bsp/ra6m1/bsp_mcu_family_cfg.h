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

#include "bsp_clock_cfg.h"
#include "bsp_mcu_device_cfg.h"
#include "bsp_mcu_device_pn_cfg.h"
#include "bsp_mcu_info.h"
#define BSP_MCU_GROUP_RA6M1 (1)
#define BSP_LOCO_HZ (DT_PROP_OR(DT_NODELABEL(loco), clock_frequency, 0))
#define BSP_MOCO_HZ (DT_PROP_OR(DT_NODELABEL(moco), clock_frequency, 0))
#define BSP_SUB_CLOCK_HZ (DT_PROP_OR(DT_NODELABEL(subclk), clock_frequency, 0))
#if BSP_CFG_HOCO_FREQUENCY == 0
#define BSP_HOCO_HZ (16000000)
#elif BSP_CFG_HOCO_FREQUENCY == 1
#define BSP_HOCO_HZ (18000000)
#elif BSP_CFG_HOCO_FREQUENCY == 2
#define BSP_HOCO_HZ (20000000)
#else
#error                                                                         \
    "Invalid HOCO frequency chosen (BSP_CFG_HOCO_FREQUENCY) in bsp_clock_cfg.h"
#endif

#define BSP_CFG_FLL_ENABLE (0)
#ifndef BSP_CLOCK_CFG_AUTODRVEN
#define BSP_CLOCK_CFG_AUTODRVEN (0)
#endif
#ifndef BSP_CLOCK_CFG_MAIN_OSC_WAIT
#define BSP_CLOCK_CFG_MAIN_OSC_WAIT (9)
#endif

#define BSP_CORTEX_VECTOR_TABLE_ENTRIES (16U)
#define BSP_VECTOR_TABLE_MAX_ENTRIES (112U)
#define BSP_CFG_INLINE_IRQ_FUNCTIONS (1)

/* Used to create IELS values for the interrupt initialization table
 * g_interrupt_event_link_select. */
#define BSP_PRV_IELS_ENUM(vector)    CONCAT(ELC_, vector)

#ifdef __cplusplus
}
#endif
#endif /* BSP_MCU_FAMILY_CFG_H_ */
