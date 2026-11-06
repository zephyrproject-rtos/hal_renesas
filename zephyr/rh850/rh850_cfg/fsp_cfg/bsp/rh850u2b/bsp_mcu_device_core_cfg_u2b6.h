/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_MCU_DEVICE_CORE_CFG_U2B6_H_
#define BSP_MCU_DEVICE_CORE_CFG_U2B6_H_

#ifndef BSP_CFG_CPU
 #define BSP_CFG_CPU                        (0)
#endif

#ifndef BSP_CFG_AMP_MODE_ENABLED
 #define BSP_CFG_AMP_MODE_ENABLED           (1U)
#endif

#ifndef BSP_SYSTEM_RAM_CPU0_SIZE_BYTES
 #define BSP_SYSTEM_RAM_CPU0_SIZE_BYTES     (65536)
#endif

/* Each bit represents a CPU core (e.g., CPU0 corresponds to bit 0) */
#ifndef BSP_DEVICE_CPU_AVAILABLE
 #define BSP_DEVICE_CPU_AVAILABLE           ((1 << 2U) | (1 << 1U) | (1 << 0U))
#endif

#ifndef BSP_DEVICE_MAX_CPU
 #define BSP_DEVICE_MAX_CPU                 (2U)
#endif

#ifndef BSP_ENABLE_FXU
 #define BSP_ENABLE_FXU                     (1U)
#endif

#ifndef BSP_FE_LEVEL_MASKABLE_INTERRUPT
 #define BSP_FE_LEVEL_MASKABLE_INTERRUPT    (0U)
#endif

#endif                                 /* BSP_MCU_DEVICE_CORE_CFG_U2B6_H_ */
