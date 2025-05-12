/*
 * Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
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

#if DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 48000000
#define BSP_CFG_HOCO_FREQUENCY 0 /* HOCO 48MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 64000000
#define BSP_CFG_HOCO_FREQUENCY 1 /* HOCO 64MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 80000000
#define BSP_CFG_HOCO_FREQUENCY 2 /* HOCO 80MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 24000000
#define BSP_CFG_HOCO_FREQUENCY 4 /* HOCO 24MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 32000000
#define BSP_CFG_HOCO_FREQUENCY 5 /* HOCO 32MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 40000000
#define BSP_CFG_HOCO_FREQUENCY 6 /* HOCO 40MHz */
#else
#error "Invalid HOCO frequency, only can be set to 48MHz, 64MHz, 80MHz, 24MHz, 32MHz and 40MHz"
#endif


#define BSP_CFG_PLL_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(pll)))
#define BSP_CFG_PLL_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pll), div, 1)
#if DT_NODE_HAS_STATUS(DT_NODELABEL(pll), okay)
#define BSP_CFG_PLL_MUL                                                                           \
       BSP_CLOCKS_PLL_MUL(DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 0),                              \
                          DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 1))
#else
#define BSP_CFG_PLL_MUL BSP_CLOCKS_PLL_MUL(0, 0)
#endif

#define BSP_CFG_CLOCK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(pclkblock)))
#define BSP_CFG_CLKOUT_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(clkout)))
#define BSP_CFG_CANFDCLK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(canfdclk)))
#define BSP_CFG_I3CCLK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(i3cclk)))
#define BSP_CFG_UCLK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(uclk)))
#define BSP_CFG_ICLK_DIV RA_CGC_CLK_DIV(DT_NODELABEL(iclk), div, 1)
#define BSP_CFG_PCLKA_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pclka), div, 1)
#define BSP_CFG_PCLKB_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pclkb), div, 2)
#define BSP_CFG_PCLKC_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pclkc), div, 2)
#define BSP_CFG_PCLKD_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pclkd), div, 1)
#define BSP_CFG_FCLK_DIV RA_CGC_CLK_DIV(DT_NODELABEL(fclk), div, 2)
#define BSP_CFG_CLKOUT_DIV RA_CGC_CLK_DIV(DT_NODELABEL(clkout), div, 1)
#define BSP_CFG_CANFDCLK_DIV RA_CGC_CLK_DIV(DT_NODELABEL(canfdclk), div, 2)
#define BSP_CFG_I3CCLK_DIV RA_CGC_CLK_DIV(DT_NODELABEL(i3cclk), div, 1)
#define BSP_CFG_UCLK_DIV RA_CGC_CLK_DIV(DT_NODELABEL(uclk), div, 1)
#define BSP_CFG_UTASEL_CLOCK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(utasel)))
#define BSP_CFG_UARTA0_CLOCK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(uarta0)))
#define BSP_CFG_UARTA1_CLOCK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(uarta1)))
#endif /* BSP_CLOCK_CFG_H_ */
