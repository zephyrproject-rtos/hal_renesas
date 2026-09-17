/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_CFG_H_
#define BSP_CFG_H_
#include "bsp_clock_cfg.h"
#include "bsp_mcu_family_cfg.h"

#ifndef BSP_CFG_RTOS
 #define BSP_CFG_RTOS (0)
#endif

#define BSP_CFG_MCU_VCC_MV (3300)

#define BSP_CFG_PARAM_CHECKING_ENABLE (0)
#define BSP_CFG_ASSERT (0)
#define BSP_CFG_ERROR_LOG (0)

#define BSP_CFG_PORT_PROTECT (1)

#define BSP_CFG_SOFT_RESET_SUPPORTED (0)
#define BSP_CFG_EARLY_INIT (0)

#define BSP_CFG_MULTIPLEX_INTERRUPT_SUPPORTED (0) // DEPRECATED
#if BSP_CFG_MULTIPLEX_INTERRUPT_SUPPORTED
 #define BSP_CFG_MULTIPLEX_INTERRUPT_ENABLE         BSP_INTERRUPT_ENABLE  // DEPRECATED
 #define BSP_CFG_MULTIPLEX_INTERRUPT_DISABLE        BSP_INTERRUPT_DISABLE // DEPRECATED
#else
 #define BSP_CFG_MULTIPLEX_INTERRUPT_ENABLE  // DEPRECATED
 #define BSP_CFG_MULTIPLEX_INTERRUPT_DISABLE // DEPRECATED
#endif

#define BSP_CFG_PROTRCT_REG_POLLING_COUNT (0xFFFFFFFF)
#endif /* BSP_CFG_H_ */
