/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_CFG_H_
#define BSP_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "bsp_clock_cfg.h"
#include "bsp_mcu_family_cfg.h"

#ifndef BSP_CFG_RTOS
#define BSP_CFG_RTOS (0)
#endif

#define BSP_CFG_MCU_VCC_MV (3300)
#define BSP_CFG_STACK_FIQ_BYTES (0x1000)
#define BSP_CFG_STACK_IRQ_BYTES (0x1000)
#define BSP_CFG_STACK_ABT_BYTES (0x1000)
#define BSP_CFG_STACK_UND_BYTES (0x1000)
#define BSP_CFG_STACK_SYS_BYTES (0x1000)
#define BSP_CFG_STACK_SVC_BYTES (0x1000)
#define BSP_CFG_HEAP_BYTES (0x8000)
#define BSP_CFG_PARAM_CHECKING_ENABLE (0)
#define BSP_CFG_ASSERT (0)
#define BSP_CFG_ERROR_LOG (0)

#define BSP_CFG_PFS_PROTECT ((1))

#define BSP_CFG_C_RUNTIME_INIT ((1))
#define BSP_CFG_EARLY_INIT     ((0))

#ifdef __cplusplus
}
#endif
#endif /* BSP_CFG_H_ */
