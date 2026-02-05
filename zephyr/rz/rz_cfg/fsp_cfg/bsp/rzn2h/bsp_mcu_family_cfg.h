/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_FAMILY_CFG_H_
#define BSP_MCU_FAMILY_CFG_H_
#include "bsp_mcu_device_pn_cfg.h"
#include "bsp_mcu_device_memory_cfg.h"
#include "bsp_mcu_device_cfg.h"
#include "bsp_mcu_info.h"
#include "bsp_clock_cfg.h"
#define BSP_MCU_GROUP_RZN2H (1)
#define BSP_API_OVERRIDE "bsp_override.h"
#define BSP_LOCO_HZ (1000000)
#define BSP_GLOBAL_SYSTEM_COUNTER_CLOCK_HZ  (25000000)
#define BSP_CORTEX_VECTOR_TABLE_ENTRIES (32)

/* Used to create CR52_SEL values for the interrupt initialization table g_interrupt_event_link_select. */
#define BSP_PRV_CR52_SEL_ENUM(vector)    (ELC_ ## vector)
#endif /* BSP_MCU_FAMILY_CFG_H_ */
