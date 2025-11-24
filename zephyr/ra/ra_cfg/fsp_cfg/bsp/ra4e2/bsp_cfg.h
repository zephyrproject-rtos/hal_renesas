/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BSP_CFG_H_
#define BSP_CFG_H_

#include "soc.h"
#include "bsp_clock_cfg.h"
#include "bsp_mcu_family_cfg.h"
#include "bsp_mcu_ofs_cfg.h"

#define BSP_CFG_RTC_USED IS_ENABLED(CONFIG_RTC_RENESAS_RA)

#define SUBCLOCK_STABILIZATION_MAX(x) ((x < 10000) ? x : 10000)

/* Disable BSP_CFG_PARAM_CHECKING_ENABLE as default to reduce code size */
#define BSP_CFG_PARAM_CHECKING_ENABLE (0)

/* Add for zephyr porting */
#define BSP_CFG_INTERRUPT_INIT 0
#define BSP_CFG_SP_MON_INIT    0

#ifndef BSP_CLOCK_CFG_MAIN_OSC_POPULATED
#define BSP_CLOCK_CFG_MAIN_OSC_POPULATED (DT_NODE_HAS_STATUS(DT_NODELABEL(xtal), okay))
#endif

#ifndef BSP_CLOCK_CFG_MAIN_OSC_CLOCK_SOURCE
#define BSP_CLOCK_CFG_MAIN_OSC_CLOCK_SOURCE (DT_PROP_OR(DT_NODELABEL(xtal), mosel, 0))
#endif

/* Keep 0 as default as LPM is not supported */
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


#define BSP_CFG_PFS_PROTECT (1)

/* 0: No RTOS, 1: Azure, 2: FreeRTOS, 3: Zephyr */
#define BSP_CFG_RTOS	3

/* Disable due to it initial in Zephyr kernel */
#define BSP_CFG_C_RUNTIME_INIT	(BSP_CFG_RTOS != 3)

/* Enable early init due to some global resource will be use for device init before z_cstart */
#define BSP_CFG_EARLY_INIT	(1)

#endif /* BSP_CFG_H_ */
