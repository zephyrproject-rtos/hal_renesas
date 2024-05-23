/*
 * Copyright (c) 2024 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ZEPHYR_SOC_RENESAS_RA_COMMON_BSP_CFG_H_
#define ZEPHYR_SOC_RENESAS_RA_COMMON_BSP_CFG_H_

#include "soc.h"
#include "bsp_clock_cfg.h"
#include "bsp_mcu_family_cfg.h"

#define BSP_CFG_PARAM_CHECKING_ENABLE (0)

/* Add for zephyr porting */
#define BSP_CFG_INTERRUPT_INIT 0
#define BSP_CFG_SP_MON_INIT    0

#ifndef BSP_CLOCK_CFG_MAIN_OSC_POPULATED
#define BSP_CLOCK_CFG_MAIN_OSC_POPULATED (1)
#endif
#ifndef BSP_CLOCK_CFG_MAIN_OSC_CLOCK_SOURCE
#define BSP_CLOCK_CFG_MAIN_OSC_CLOCK_SOURCE (0)
#endif
#ifndef BSP_CLOCK_CFG_SUBCLOCK_DRIVE
#define BSP_CLOCK_CFG_SUBCLOCK_DRIVE (0)
#endif
#ifndef BSP_CLOCK_CFG_SUBCLOCK_POPULATED
#define BSP_CLOCK_CFG_SUBCLOCK_POPULATED (1)
#endif
#ifndef BSP_CLOCK_CFG_SUBCLOCK_STABILIZATION_MS
#define BSP_CLOCK_CFG_SUBCLOCK_STABILIZATION_MS 1000
#endif

#endif /* ZEPHYR_SOC_RENESAS_RA_COMMON_BSP_CFG_H_ */
