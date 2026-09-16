/*
* Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_CFG_H_
#define BSP_CFG_H_
#ifdef __cplusplus
            extern "C" {
            #endif

#include "bsp_clock_cfg.h"
#include "../../../rx/fsp/src/bsp/mcu/all/bsp_compiler_support.h"
#include "bsp_mcu_family_cfg.h"
#include <zephyr/devicetree.h>

#define SUBCLOCK_STABILIZATION_MAX(x) ((x < 10000) ? x : 10000)
#define FSP_NOT_DEFINED 0
#ifndef BSP_CFG_RTOS
#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)
              #define BSP_CFG_RTOS (2)
             #elif (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)
              #define BSP_CFG_RTOS (1)
             #else
#define BSP_CFG_RTOS (0)
#endif
#endif
#ifndef BSP_CFG_RTC_USED
#define BSP_CFG_RTC_USED (FSP_NOT_DEFINED)
#endif
#undef FSP_NOT_DEFINED
#if defined(_RX_BOOT_IMAGE)
             #define BSP_CFG_BOOT_IMAGE (1)
            #endif
#define BSP_CFG_MCU_VCC_MV (3300)
#define BSP_CFG_STACK_MAIN_BYTES (0x400)
#define BSP_CFG_HEAP_BYTES (0)
#define BSP_CFG_PARAM_CHECKING_ENABLE (0)
#define BSP_CFG_ASSERT (0)

#define BSP_CFG_PFS_PROTECT ((1))

#define BSP_CFG_C_RUNTIME_INIT ((1))
#define BSP_CFG_EARLY_INIT     ((0))

#define BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET ((0))

#ifndef BSP_CLOCK_CFG_MAIN_OSC_POPULATED
#define BSP_CLOCK_CFG_MAIN_OSC_POPULATED (DT_NODE_HAS_STATUS(DT_NODELABEL(xtal), okay))
#endif

#ifndef BSP_CLOCK_CFG_MAIN_OSC_CLOCK_SOURCE
#define BSP_CLOCK_CFG_MAIN_OSC_CLOCK_SOURCE (DT_PROP_OR(DT_NODELABEL(xtal), mosel, 0))
#endif
#ifndef BSP_CLOCK_CFG_SUBCLOCK_DRIVE
#define BSP_CLOCK_CFG_SUBCLOCK_DRIVE (DT_PROP_OR(DT_NODELABEL(subclk), drive_capability, 0))
#endif
#ifndef BSP_CLOCK_CFG_SUBCLOCK_POPULATED
#define BSP_CLOCK_CFG_SUBCLOCK_POPULATED (DT_NODE_HAS_STATUS(DT_NODELABEL(subclk), okay))
#endif
#ifndef BSP_CLOCK_CFG_SUBCLOCK_STABILIZATION_MS
#define BSP_CLOCK_CFG_SUBCLOCK_STABILIZATION_MS                                                    \
	SUBCLOCK_STABILIZATION_MAX((DT_PROP_OR(DT_NODELABEL(subclk), stabilization_time, 1000)))
#endif

#ifdef __cplusplus
            }
            #endif
#endif /* BSP_CFG_H_ */
