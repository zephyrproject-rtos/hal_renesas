/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_CFG_U2B10_H_
#define BSP_CFG_U2B10_H_
#include "bsp_clock_cfg.h"
#include "bsp_mcu_family_cfg.h"
#include "board_cfg.h"
#include "bsp_common_cfg.h"
#include "bsp_mcu_cpu_memory_cfg.h"
#include "memory_regions.h"
#ifndef BSP_API_OVERRIDE
 #define BSP_API_OVERRIDE    "bsp_api_override.h"
#endif

#ifndef FSP_NOT_DEFINED
 #define FSP_NOT_DEFINED     0
#endif

#ifndef BSP_CFG_RTOS
 #if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)
  #define BSP_CFG_RTOS       (2)
 #elif (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)
  #define BSP_CFG_RTOS       (1)
 #else
  #define BSP_CFG_RTOS       (0)
 #endif
#endif
#undef FSP_NOT_DEFINED

#ifndef BSP_CFG_PARAM_CHECKING_ENABLE
 #define BSP_CFG_PARAM_CHECKING_ENABLE    (0)
#endif

#ifndef BSP_CFG_ASSERT
 #define BSP_CFG_ASSERT                   (0)
#endif

#ifndef BSP_CFG_ERROR_LOG
 #define BSP_CFG_ERROR_LOG                (0)
#endif

#ifndef BSP_CFG_STACK_MAIN_BYTES
 #define BSP_CFG_STACK_MAIN_BYTES         (0x400)
#endif

#ifndef BSP_CFG_HEAP_SIZE_BYTES
 #define BSP_CFG_HEAP_SIZE_BYTES          (0)
#endif

#ifndef BSP_CFG_MEV_SIZE_BYTES
 #define BSP_CFG_MEV_SIZE_BYTES           (0)
#endif

#endif                                 /* BSP_CFG_H_ */
