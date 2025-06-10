/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_FAMILY_CFG_H_
#define BSP_MCU_FAMILY_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define BSP_MCU_GROUP_RZV2H (1)
#define BSP_SUPPORT_CORE_CR8 (1)
#define BSP_CR8_CORE_NUM (0)
#define BSP_CORTEX_VECTOR_TABLE_ENTRIES    (32U)
#define BSP_VECTOR_TABLE_MAX_ENTRIES       (480U)
#define BSP_CFG_INLINE_IRQ_FUNCTIONS       (1)
#define BSP_NONSECURE_TRANSITION       (0)
#define BSP_SELECT_INT_START_ELEMENT   (0)
#define BSP_SELECT_INT_NUM             (85)

#include "bsp_mcu_device_pn_cfg.h"
#include "bsp_mcu_device_cfg.h"
#include "bsp_override.h"
#include "bsp_mcu_info.h"
#include "bsp_clock_cfg.h"

#ifdef __cplusplus
}
#endif
#endif /* BSP_MCU_FAMILY_CFG_H_ */
