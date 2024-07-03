/*
 * Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <zephyr/devicetree.h>
#include <zephyr/dt-bindings/clock/ra_clock.h>

#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_

#define BSP_CFG_CLOCKS_SECURE   (0)
#define BSP_CFG_CLOCKS_OVERRIDE (0)
#define BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(node_id, prop, default_value)                            \
	(COND_CODE_1(DT_NODE_HAS_STATUS(node_id, okay), (DT_PROP(node_id, prop)), (default_value)))

#define BSP_CFG_XTAL_HZ BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(xtal), clock_frequency, 0)

#if DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 16000000
#define BSP_CFG_HOCO_FREQUENCY 0 /* HOCO 16MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 18000000
#define BSP_CFG_HOCO_FREQUENCY 1 /* HOCO 18MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 20000000
#define BSP_CFG_HOCO_FREQUENCY 2 /* HOCO 20MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 32000000
#define BSP_CFG_HOCO_FREQUENCY 4 /* HOCO 32MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 48000000
#define BSP_CFG_HOCO_FREQUENCY 7 /* HOCO 48MHz */
#else
#error "Invalid HOCO frequency, only can be set to 16MHz, 18MHz, 20MHz, 32MHz, 48MHz"
#endif

#define BSP_CFG_PLL_SOURCE                                                                         \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll), source, RA_PLL_SOURCE_DISABLE)
#define BSP_CFG_PLL_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll), div, RA_PLL_DIV_1)

#if DT_NODE_HAS_STATUS(DT_NODELABEL(pll), okay)
#define BSP_CFG_PLL_MUL                                                                            \
	BSP_CLOCKS_PLL_MUL(DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 0),                              \
			   DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 1))
#else
#define BSP_CFG_PLL_MUL BSP_CLOCKS_PLL_MUL(0, 0)
#endif

#define BSP_CFG_PLODIVP            BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll), divp, RA_PLL_DIV_2)
#define BSP_CFG_PLL1P_FREQUENCY_HZ BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll), freqp, 0)
#define BSP_CFG_PLODIVQ            BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll), divq, RA_PLL_DIV_2)
#define BSP_CFG_PLL1Q_FREQUENCY_HZ BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll), freqq, 0)
#define BSP_CFG_PLODIVR            BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll), divr, RA_PLL_DIV_2)
#define BSP_CFG_PLL1R_FREQUENCY_HZ BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll), freqr, 0)

#define BSP_CFG_PLL2_SOURCE                                                                        \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2), source, RA_PLL_SOURCE_DISABLE)
#define BSP_CFG_PLL2_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2), div, RA_PLL_DIV_1)

#if DT_NODE_HAS_STATUS(DT_NODELABEL(pll2), okay)
#define BSP_CFG_PLL2_MUL                                                                           \
	BSP_CLOCKS_PLL_MUL(DT_PROP_BY_IDX(DT_NODELABEL(pll2), mul, 0),                             \
			   DT_PROP_BY_IDX(DT_NODELABEL(pll2), mul, 1))
#else
#define BSP_CFG_PLL2_MUL BSP_CLOCKS_PLL_MUL(0, 0)
#endif

#define BSP_CFG_PL2ODIVP           BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2), divp, RA_PLL_DIV_2)
#define BSP_CFG_PLL2P_FREQUENCY_HZ BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2), freqp, 0)
#define BSP_CFG_PL2ODIVQ           BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2), divq, RA_PLL_DIV_2)
#define BSP_CFG_PLL2Q_FREQUENCY_HZ BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2), freqq, 0)
#define BSP_CFG_PL2ODIVR           BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2), divr, RA_PLL_DIV_2)
#define BSP_CFG_PLL2R_FREQUENCY_HZ BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2), freqr, 0)

#define BSP_CFG_CLOCK_SOURCE                                                                       \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkblock), sysclock_src,                   \
					  RA_PLL_SOURCE_DISABLE)
#define BSP_CFG_CPUCLK_DIV                                                                         \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(cpuclk), clk_div, RA_SYS_CLOCK_DIV_1)

#define BSP_CFG_ICLK_DIV                                                                           \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(iclk), clk_div, RA_SYS_CLOCK_DIV_2)
#define BSP_CFG_PCLKA_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclka), clk_div, RA_SYS_CLOCK_DIV_4)
#define BSP_CFG_PCLKB_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkb), clk_div, RA_SYS_CLOCK_DIV_8)
#define BSP_CFG_PCLKC_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkc), clk_div, RA_SYS_CLOCK_DIV_8)
#define BSP_CFG_PCLKD_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkd), clk_div, RA_SYS_CLOCK_DIV_4)
#define BSP_CFG_PCLKE_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclke), clk_div, RA_SYS_CLOCK_DIV_2)
#define BSP_CFG_BCLK_DIV                                                                           \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(bclk), clk_div, RA_SYS_CLOCK_DIV_4)
#define BSP_CFG_SDCLK_OUTPUT BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(bclkout), sdclk, 1)
#define BSP_CFG_BCLK_OUTPUT  BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(bclkout), clk_out_div, 2)
#define BSP_CFG_FCLK_DIV                                                                           \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(fclk), clk_div, RA_SYS_CLOCK_DIV_8)

#define BSP_CFG_UCK_SOURCE                                                                         \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(uclk), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_UCK_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(uclk), clk_div, 0)
#define BSP_CFG_U60CK_SOURCE                                                                       \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(u60clk), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_U60CK_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(u60clk), clk_div, 0)
#define BSP_CFG_OCTA_SOURCE                                                                        \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(octaspiclk), clk_src,                       \
					  RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_OCTA_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(octaspiclk), clk_div, 0)
#define BSP_CFG_CANFDCLK_SOURCE                                                                    \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(canfdclk), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_CANFDCLK_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(canfdclk), clk_div, 0)
#define BSP_CFG_CLKOUT_SOURCE                                                                      \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(clkout), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_CLKOUT_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(clkout), clk_div, 0)
#define BSP_CFG_SCICLK_SOURCE                                                                      \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(sciclk), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_SCICLK_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(sciclk), clk_div, 0)
#define BSP_CFG_SPICLK_SOURCE                                                                      \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(spiclk), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_SPICLK_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(spiclk), clk_div, 0)
#define BSP_CFG_ADCCLK_SOURCE                                                                      \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(adcclk), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_ADCCLK_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(adcclk), clk_div, 0)
#define BSP_CFG_I3CCLK_SOURCE                                                                      \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(i3cclk), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_I3CCLK_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(i3cclk), clk_div, 0)
#define BSP_CFG_LCDCLK_SOURCE                                                                      \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(lcdclk), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_LCDCLK_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(lcdclk), clk_div, 0)

#endif /* BSP_CLOCK_CFG_H_ */
