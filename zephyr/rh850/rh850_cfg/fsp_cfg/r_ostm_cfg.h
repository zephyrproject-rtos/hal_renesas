/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef R_OSTM_CFG_H_
#define R_OSTM_CFG_H_

#if defined(CONFIG_SOC_SERIES_RH850U2A)
 #define OSTM_CFG_CLOCK    (BSP_CFG_CLOCK_CLK_HSB_HZ)
#else
 #define OSTM_CFG_CLOCK    (BSP_CFG_CLOCK_CLKC_HSB_HZ)
#endif

#endif                                 /* R_OSTM_CFG_H_ */
