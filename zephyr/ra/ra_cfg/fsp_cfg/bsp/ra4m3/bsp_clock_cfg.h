/*
 * Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <zephyr/devicetree.h>
#include <zephyr/drivers/clock_control/renesas_ra_cgc.h>

#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_

#define BSP_CFG_CLOCKS_SECURE   (0)
#define BSP_CFG_CLOCKS_OVERRIDE (0)

#define BSP_CFG_XTAL_HZ (RA_CGC_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(xtal), clock_frequency, 0))

#if DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 16000000
#define BSP_CFG_HOCO_FREQUENCY 0 /* HOCO 16MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 18000000
#define BSP_CFG_HOCO_FREQUENCY 1 /* HOCO 18MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 20000000
#define BSP_CFG_HOCO_FREQUENCY 2 /* HOCO 20MHz */
#else
#error "Invalid HOCO frequency, only can be set to 16MHz, 18MHz, and 20MHz"
#endif

#define BSP_CFG_PLL_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(pll)))
#define BSP_CFG_PLL_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(pll), div, 3)
#if DT_NODE_HAS_STATUS(DT_NODELABEL(pll), okay)
#define BSP_CFG_PLL_MUL                                                                            \
	BSP_CLOCKS_PLL_MUL(DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 0),                              \
			   DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 1))
#else
#define BSP_CFG_PLL_MUL BSP_CLOCKS_PLL_MUL(0, 0)
#endif

#define BSP_CFG_PLL2_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(pll2)))
#define BSP_CFG_PLL2_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(pll2), div, 2)
#if DT_NODE_HAS_STATUS(DT_NODELABEL(pll2), okay)
#define BSP_CFG_PLL2_MUL                                                                           \
	BSP_CLOCKS_PLL_MUL(DT_PROP_BY_IDX(DT_NODELABEL(pll2), mul, 0),                             \
			   DT_PROP_BY_IDX(DT_NODELABEL(pll2), mul, 1))
#else
#define BSP_CFG_PLL2_MUL BSP_CLOCKS_PLL_MUL(0, 0)
#endif

#define BSP_CFG_CLOCK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(pclkblock)))

#define BSP_CFG_ICLK_DIV  RA_CGC_CLK_DIV(DT_NODELABEL(iclk), div, 2)
#define BSP_CFG_PCLKA_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pclka), div, 2)
#define BSP_CFG_PCLKB_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pclkb), div, 4)
#define BSP_CFG_PCLKC_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pclkc), div, 4)
#define BSP_CFG_PCLKD_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pclkd), div, 2)
#define BSP_CFG_FCLK_DIV  RA_CGC_CLK_DIV(DT_NODELABEL(fclk), div, 4)

#define BSP_CFG_UCLK_SOURCE   RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(uclk)))
#define BSP_CFG_UCLK_DIV      RA_CGC_CLK_DIV(DT_NODELABEL(uclk), div, 1)
#define BSP_CFG_CLKOUT_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(clkout)))
#define BSP_CFG_CLKOUT_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(clkout), div, 1)

#endif /* BSP_CLOCK_CFG_H_ */
