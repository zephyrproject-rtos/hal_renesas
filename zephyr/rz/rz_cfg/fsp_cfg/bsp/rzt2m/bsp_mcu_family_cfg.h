/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_FAMILY_CFG_H_
#define BSP_MCU_FAMILY_CFG_H_
#include "bsp_mcu_device_pn_cfg.h"
#include "bsp_mcu_device_cfg.h"
#include "bsp_mcu_device_memory_cfg.h"
#include "bsp_mcu_info.h"
#include "bsp_clock_cfg.h"
#define BSP_API_OVERRIDE "bsp_override.h"
#define BSP_MCU_GROUP_RZT2M (1)
#define BSP_LOCO_HZ (240000)
#define BSP_GLOBAL_SYSTEM_COUNTER_CLOCK_HZ  (25000000)
#define BSP_CORTEX_VECTOR_TABLE_ENTRIES (32)
#define BSP_VECTOR_TABLE_MAX_ENTRIES (448)
#endif /* BSP_MCU_FAMILY_CFG_H_ */
