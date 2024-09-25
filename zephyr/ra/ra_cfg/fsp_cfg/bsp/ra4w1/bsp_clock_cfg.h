/*
 * Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <zephyr/devicetree.h>
#include <zephyr/drivers/clock_control/renesas_ra_cgc.h>

#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_

#define BSP_CFG_CLOCKS_SECURE	(0)
#define BSP_CFG_CLOCKS_OVERRIDE (0)

#define BSP_CFG_XTAL_HZ BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(xtal), clock_frequency, 0)

#if DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 24000000
#define BSP_CFG_HOCO_FREQUENCY 0 /* HOCO 24MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 32000000
#define BSP_CFG_HOCO_FREQUENCY 2 /* HOCO 32MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 48000000
#define BSP_CFG_HOCO_FREQUENCY 4 /* HOCO 48MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 64000000
#define BSP_CFG_HOCO_FREQUENCY 5 /* HOCO 64MHz */
#else
#error "Invalid HOCO frequency, only can be set to 24MHz, 32MHz, 48MHz and 64MHz"
#endif

#define BSP_CFG_PLL_SOURCE                                                                         \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll), source, RA_PLL_SOURCE_DISABLE)
#define BSP_CFG_PLL_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll), div, RA_PLL_DIV_2)
#if DT_NODE_HAS_STATUS(DT_NODELABEL(pll), okay)
#define BSP_CFG_PLL_MUL                                                                            \
	BSP_CLOCKS_PLL_MUL(DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 0),                            \
			DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 1))
#else
#define BSP_CFG_PLL_MUL BSP_CLOCKS_PLL_MUL(0, 0)
#endif

#define BSP_CFG_CLOCK_SOURCE                                                                       \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkblock), sysclock_src,                  \
					  RA_PLL_SOURCE_DISABLE)

#define BSP_CFG_ICLK_DIV                                                                           \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(iclk), clk_div, RA_SYS_CLOCK_DIV_1)
#define BSP_CFG_PCLKA_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclka), clk_div, RA_SYS_CLOCK_DIV_1)
#define BSP_CFG_PCLKB_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkb), clk_div, RA_SYS_CLOCK_DIV_2)
#define BSP_CFG_PCLKC_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkc), clk_div, RA_SYS_CLOCK_DIV_1)
#define BSP_CFG_PCLKD_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkd), clk_div, RA_SYS_CLOCK_DIV_1)
#define BSP_CFG_FCLK_DIV                                                                           \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(fclk), clk_div, RA_SYS_CLOCK_DIV_2)

#define BSP_CFG_UCK_SOURCE                                                                         \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(uclk), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_UCK_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(uclk), clk_div, 0)
#define BSP_CFG_CLKOUT_SOURCE                                                                      \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(clkout), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_CLKOUT_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(clkout), clk_div, 0)

#endif /* BSP_CLOCK_CFG_H_ */
