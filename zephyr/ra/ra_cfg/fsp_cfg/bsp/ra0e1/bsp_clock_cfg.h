/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <zephyr/devicetree.h>
#include <zephyr/drivers/clock_control/renesas_ra_cgc.h>

#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_

#define BSP_CFG_CLOCKS_SECURE (0)
#define BSP_CFG_CLOCKS_OVERRIDE (0)

#define BSP_CFG_XTAL_HZ (RA_CGC_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(xtal), clock_frequency, 0))
#define BSP_CFG_XTAL_DIV (RA_CGC_CLK_DIV(DT_NODELABEL(xtaldiv_clk), clock_div, 1))

#if DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 24000000
#define BSP_CFG_HOCO_FREQUENCY 0 /* HOCO 24MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 32000000
#define BSP_CFG_HOCO_FREQUENCY 2 /* HOCO 32MHz */
#else
#error "Invalid HOCO frequency, only can be set to 24MHz, 32MHz"
#endif
#define BSP_CFG_HOCO_DIV (RA_CGC_CLK_DIV(DT_NODELABEL(hocodiv_clk), clock_div, 1))

#define BSP_CFG_MOCO_DIV (RA_CGC_CLK_DIV(DT_NODELABEL(mocodiv_clk), clock_div, 1))
#define BSP_CFG_CLOCK_SOURCE  RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(iclk)))

#define BSP_CFG_TAU_CK00 (RA_CGC_CLK_DIV(DT_NODELABEL(tau_ck00), div, 1))
#define BSP_CFG_TAU_CK01 (RA_CGC_CLK_DIV(DT_NODELABEL(tau_ck01), div, 1))
#define BSP_CFG_TAU_CK02 (RA_CGC_CLK_DIV(DT_NODELABEL(tau_ck02), div, 2))
#define BSP_CFG_TAU_CK03 (RA_CGC_CLK_DIV(DT_NODELABEL(tau_ck03), div, 256))
#define BSP_CFG_SAU_CK00_DIV (RA_CGC_CLK_DIV(DT_NODELABEL(sau_ck00), div, 2))
#define BSP_CFG_SAU_CK01_DIV (RA_CGC_CLK_DIV(DT_NODELABEL(sau_ck01), div, 1))
#define BSP_CFG_SAU_CK10_DIV (RA_CGC_CLK_DIV(DT_NODELABEL(sau_ck10), div, 2))
#define BSP_CFG_SAU_CK11_DIV (RA_CGC_CLK_DIV(DT_NODELABEL(sau_ck11), div, 1))
#define BSP_CFG_CLKOUT_SOURCE (RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(clkout))))
#define BSP_CFG_CLKOUT_DIV    (RA_CGC_CLK_DIV(DT_NODELABEL(clkout), div, 1))
#define BSP_CFG_UARTA0_CLOCK_SOURCE (RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(uarta0))))
#define BSP_CFG_FSXP_SOURCE (RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(fsxp))))
#define BSP_CFG_TML_FITL0_SOURCE (BSP_CLOCKS_CLOCK_DISABLED) /* TML FITL0 Src: ELC event/No BSP Source Clock */
#define BSP_CFG_TML_FITL1_SOURCE (BSP_CLOCKS_CLOCK_DISABLED) /* TML FITL1 Src: ELC event/No BSP Source Clock */
#define BSP_CFG_TML_FITL2_SOURCE (BSP_CLOCKS_CLOCK_DISABLED) /* TML FITL2 Disabled/No BSP Source Clock */
#endif /* BSP_CLOCK_CFG_H_ */
