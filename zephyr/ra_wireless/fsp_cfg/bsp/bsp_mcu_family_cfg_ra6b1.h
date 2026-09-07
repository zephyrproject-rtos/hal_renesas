/*
 * Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef BSP_MCU_FAMILY_CFG_RA6B1_H
#define BSP_MCU_FAMILY_CFG_RA6B1_H

#define BSP_API_OVERRIDE    "../../../fsp/src/bsp_w/mcu/all/bsp_api_override.h"

#ifndef __ASSEMBLER__
 #include "../../../fsp/src/bsp_w/mcu/ra6b1/bsp_mcu_info.h"
 #include "../../../fsp/src/bsp_w/mcu/ra6b1/bsp_override.h"
#endif
#include "bsp_clock_cfg.h"

#define BSP_MCU_GROUP_RA6B1                           (1)

#define BSP_RCX_HZ                                    (32000)
#define BSP_RCLP_HZ                                   (512000)
#define BSP_RCHS_HZ                                   (32000000)

#define BSP_CORTEX_VECTOR_TABLE_ENTRIES               (16U)
#define BSP_VECTOR_TABLE_MAX_ENTRIES                  (76U)

#ifndef BSP_CFG_PRODUCTION_BUILD
 #define BSP_CFG_PRODUCTION_BUILD                     (0)
#endif
#ifndef BSP_CFG_DEBUGGER_ENABLE
 #define BSP_CFG_DEBUGGER_ENABLE                      (1)
#endif
#ifndef BSP_CFG_CMAC_DEBUGGER_ENABLE
 #define BSP_CFG_CMAC_DEBUGGER_ENABLE                 (0)
#endif
#ifndef BSP_CFG_SNC_DEBUGGER_ENABLE
 #define BSP_CFG_SNC_DEBUGGER_ENABLE                  (0)
#endif
#ifndef BSP_CFG_DEBUG_CMN_TIMING
 #define BSP_CFG_DEBUG_CMN_TIMING                     (1)
#endif
#ifndef BSP_CFG_PFS_PROTECT
 #define BSP_CFG_PFS_PROTECT                          (0)
#endif
#ifndef BSP_CFG_TCS_CUSTOMER_CS_MAX_SIZE
 #define BSP_CFG_TCS_CUSTOMER_CS_MAX_SIZE             (256 * 4)
#endif
#ifndef BSP_CFG_SYS_CLK_RUNTIME_SWITCHING_SUPPORT
 #define BSP_CFG_SYS_CLK_RUNTIME_SWITCHING_SUPPORT    (0)
#endif

/* Used to create IELS values for the interrupt initialization table g_interrupt_event_link_select. */
#define BSP_PRV_IELS_ENUM(vector)    (ICU_ ## vector)
#endif
