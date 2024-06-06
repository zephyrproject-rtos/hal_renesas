/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <zephyr/devicetree.h>

#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_

#define BSP_CFG_CLOCKS_SECURE   (0)
#define BSP_CFG_CLOCKS_OVERRIDE (0)

#define BSP_CFG_XTAL_HZ DT_PROP(DT_NODELABEL(xtal), clock_frequency)

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

#define BSP_CFG_PLL_SOURCE DT_PROP(DT_NODELABEL(clock), pll_source)
#define BSP_CFG_PLL_DIV    DT_PROP(DT_NODELABEL(clock), pll_div)
#define BSP_CFG_PLL_MUL                                                                            \
	BSP_CLOCKS_PLL_MUL(DT_PROP_BY_IDX(DT_NODELABEL(clock), pll_mul, 0),                        \
			   DT_PROP_BY_IDX(DT_NODELABEL(clock), pll_mul, 1))

#define BSP_CFG_PLODIVP            DT_PROP(DT_NODELABEL(clock), pll_divp)
#define BSP_CFG_PLL1P_FREQUENCY_HZ DT_PROP(DT_NODELABEL(clock), pll_freqp)
#define BSP_CFG_PLODIVQ            DT_PROP(DT_NODELABEL(clock), pll_divq)
#define BSP_CFG_PLL1Q_FREQUENCY_HZ DT_PROP(DT_NODELABEL(clock), pll_freqq)
#define BSP_CFG_PLODIVR            DT_PROP(DT_NODELABEL(clock), pll_divr)
#define BSP_CFG_PLL1R_FREQUENCY_HZ DT_PROP(DT_NODELABEL(clock), pll_freqr)

#define BSP_CFG_PLL2_SOURCE DT_PROP(DT_NODELABEL(clock), pll2_source)
#define BSP_CFG_PLL2_DIV    DT_PROP(DT_NODELABEL(clock), pll2_div)
#define BSP_CFG_PLL2_MUL                                                                           \
	BSP_CLOCKS_PLL_MUL(DT_PROP_BY_IDX(DT_NODELABEL(clock), pll2_mul, 0),                       \
			   DT_PROP_BY_IDX(DT_NODELABEL(clock), pll2_mul, 1))

#define BSP_CFG_PL2ODIVP           DT_PROP(DT_NODELABEL(clock), pll2_divp)
#define BSP_CFG_PLL2P_FREQUENCY_HZ DT_PROP(DT_NODELABEL(clock), pll2_freqp)
#define BSP_CFG_PL2ODIVQ           DT_PROP(DT_NODELABEL(clock), pll2_divq)
#define BSP_CFG_PLL2Q_FREQUENCY_HZ DT_PROP(DT_NODELABEL(clock), pll2_freqq)
#define BSP_CFG_PL2ODIVR           DT_PROP(DT_NODELABEL(clock), pll2_divr)
#define BSP_CFG_PLL2R_FREQUENCY_HZ DT_PROP(DT_NODELABEL(clock), pll2_freqr)

#define BSP_CFG_CLOCK_SOURCE DT_PROP(DT_NODELABEL(clock), sysclock_source)
#define BSP_CFG_CPUCLK_DIV   DT_PROP(DT_NODELABEL(clock), cpuclk_div)

#define BSP_CFG_ICLK_DIV     DT_PROP(DT_NODELABEL(clock), iclk_div)
#define BSP_CFG_PCLKA_DIV    DT_PROP(DT_NODELABEL(clock), pclka_div)
#define BSP_CFG_PCLKB_DIV    DT_PROP(DT_NODELABEL(clock), pclkb_div)
#define BSP_CFG_PCLKC_DIV    DT_PROP(DT_NODELABEL(clock), pclkc_div)
#define BSP_CFG_PCLKD_DIV    DT_PROP(DT_NODELABEL(clock), pclkd_div)
#define BSP_CFG_PCLKE_DIV    DT_PROP(DT_NODELABEL(clock), pclke_div)
#define BSP_CFG_BCLK_DIV     DT_PROP(DT_NODELABEL(clock), bclk_div)
#define BSP_CFG_BCLK_OUTPUT  DT_PROP(DT_NODELABEL(clock), bclk_out)
#define BSP_CFG_FCLK_DIV     DT_PROP(DT_NODELABEL(clock), fclk_div)
#define BSP_CFG_SDCLK_OUTPUT DT_PROP(DT_NODELABEL(clock), sdclk_out)

#define BSP_CFG_UCK_SOURCE      DT_PROP(DT_NODELABEL(clock), uclk_source)
#define BSP_CFG_UCK_DIV         DT_PROP(DT_NODELABEL(clock), uclk_div)
#define BSP_CFG_U60CK_SOURCE    DT_PROP(DT_NODELABEL(clock), u60clk_source)
#define BSP_CFG_U60CK_DIV       DT_PROP(DT_NODELABEL(clock), u60clk_div)
#define BSP_CFG_OCTA_SOURCE     DT_PROP(DT_NODELABEL(clock), octaspiclk_source)
#define BSP_CFG_OCTA_DIV        DT_PROP(DT_NODELABEL(clock), octaspiclk_div)
#define BSP_CFG_CANFDCLK_SOURCE DT_PROP(DT_NODELABEL(clock), canfdclk_source)
#define BSP_CFG_CANFDCLK_DIV    DT_PROP(DT_NODELABEL(clock), canfdclk_div)
#define BSP_CFG_CLKOUT_SOURCE   DT_PROP(DT_NODELABEL(clock), clkout_source)
#define BSP_CFG_CLKOUT_DIV      DT_PROP(DT_NODELABEL(clock), clkout_div)
#define BSP_CFG_SCICLK_SOURCE   DT_PROP(DT_NODELABEL(clock), sciclk_source)
#define BSP_CFG_SCICLK_DIV      DT_PROP(DT_NODELABEL(clock), sciclk_div)
#define BSP_CFG_SPICLK_SOURCE   DT_PROP(DT_NODELABEL(clock), spiclk_source)
#define BSP_CFG_SPICLK_DIV      DT_PROP(DT_NODELABEL(clock), spiclk_div)
#define BSP_CFG_ADCCLK_SOURCE   DT_PROP(DT_NODELABEL(clock), adcclk_source)
#define BSP_CFG_ADCCLK_DIV      DT_PROP(DT_NODELABEL(clock), adcclk_div)
#define BSP_CFG_I3CCLK_SOURCE   DT_PROP(DT_NODELABEL(clock), i3cclk_source)
#define BSP_CFG_I3CCLK_DIV      DT_PROP(DT_NODELABEL(clock), i3cclk_div)

#endif /* BSP_CLOCK_CFG_H_ */
