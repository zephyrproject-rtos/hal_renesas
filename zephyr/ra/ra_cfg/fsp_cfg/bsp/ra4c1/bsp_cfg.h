/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BSP_CFG_H_
#define BSP_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "soc.h"
#include "bsp_clock_cfg.h"
#include "bsp_mcu_family_cfg.h"
#include "bsp_mcu_ofs_cfg.h"

#define SUBCLOCK_STABILIZATION_MAX(x) ((x < 10000) ? x : 10000)

/* Disable BSP_CFG_PARAM_CHECKING_ENABLE as default to reduce code size */
#define BSP_CFG_PARAM_CHECKING_ENABLE (0)

#define BSP_CFG_PFS_PROTECT ((1))

/* Add for zephyr porting */
#define BSP_CFG_INTERRUPT_INIT 0

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
	SUBCLOCK_STABILIZATION_MAX((DT_PROP_OR(DT_NODELABEL(subclk), stabilization_time, 500)))
#endif

#ifdef __cplusplus
}
#endif
#endif /* BSP_CFG_H_ */
