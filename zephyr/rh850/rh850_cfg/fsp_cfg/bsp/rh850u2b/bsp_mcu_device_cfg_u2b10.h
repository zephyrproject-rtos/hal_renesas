/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_MCU_DEVICE_CFG_U2B10_H_
#define BSP_MCU_DEVICE_CFG_U2B10_H_
#include "bsp_clock_cfg.h"
#ifndef BSP_MCU_GROUP_RH850U2Bx
 #define BSP_MCU_GROUP_RH850U2Bx         (1)
#endif

#ifndef BSP_FENMI_VECTOR_MAX_ENTRIES
 #define BSP_FENMI_VECTOR_MAX_ENTRIES    1UL
#endif

#ifndef BSP_FEINT_VECTOR_MAX_ENTRIES
 #define BSP_FEINT_VECTOR_MAX_ENTRIES    3UL
#endif

#ifndef BSP_INTC1_VECTOR_MAX_ENTRIES
 #define BSP_INTC1_VECTOR_MAX_ENTRIES    32UL
#endif

#ifndef BSP_INTC2_VECTOR_MAX_ENTRIES
 #define BSP_INTC2_VECTOR_MAX_ENTRIES    992UL
#endif

#ifndef BSP_INTC_INTBP_MAX_ENTRIES
 #define BSP_INTC_INTBP_MAX_ENTRIES      1024UL
#endif

#endif                                 /* BSP_MCU_DEVICE_CFG_H_ */
