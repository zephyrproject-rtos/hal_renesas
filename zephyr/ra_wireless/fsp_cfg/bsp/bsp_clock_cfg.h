/*
 * Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef BSP_CLOCK_CFG_H
#define BSP_CLOCK_CFG_H

/***********************************************************************************************************************
 * Choose pin configuration file for current build
 **********************************************************************************************************************/
#if defined(CONFIG_SOC_SERIES_RA6B1)
 #include "bsp_clock_cfg_ra6b1.h"
#elif defined(CONFIG_SOC_SERIES_RA6W_COMMON)
 #include "bsp_clock_cfg_ra6w1.h"
#endif

#endif
