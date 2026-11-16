/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_COMMON_CFG_U2B6_H_
#define BSP_COMMON_CFG_U2B6_H_

/* BSP OPBT Setting */
#ifndef BSP_OPBT_CFG_SETTING_ENABLE
 #define BSP_OPBT_CFG_SETTING_ENABLE             (0)
#endif

/* BSP OPBT enable Erase/Program/Verify API */
#ifndef BSP_OPBT_API_USED_ENABLE
 #define BSP_OPBT_API_USED_ENABLE                (0)
#endif

/* BSP Interrupt Vector Reference Method */
#ifndef BSP_INTERRUPT_TABLE_REFERENCE_METHOD
 #define BSP_INTERRUPT_TABLE_REFERENCE_METHOD    (1)
#endif

/* BSP Reduced Interrupt Handler Address */
#ifndef BSP_INTERRUPT_REDUCTION
 #define BSP_INTERRUPT_REDUCTION                 (0)
#endif

/* BSP Nested Interrupt Enable */
#ifndef BSP_NESTED_INTERRUPT
 #define BSP_NESTED_INTERRUPT                    (0)
#endif

/* BSP Interrupt Config (common - BSP CPU Config) */
#ifndef BSP_INTERRUPT_CONFIG
 #define BSP_INTERRUPT_CONFIG                    (1)
#endif
#endif                                 /* BSP_COMMON_CFG_H_ */
