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
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 32000000
#define BSP_CFG_HOCO_FREQUENCY 4 /* HOCO 32MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 48000000
#define BSP_CFG_HOCO_FREQUENCY 7 /* HOCO 48MHz */
#else
#error "Invalid HOCO frequency, only can be set to 16MHz, 18MHz, 20MHz, 32MHz, 48MHz"
#endif

#define BSP_CFG_PLL_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(pll)))
#define BSP_CFG_PLL_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(pll), div, 1)

#if DT_NODE_HAS_STATUS(DT_NODELABEL(pll), okay)
#define BSP_CFG_PLL_MUL                                                                            \
	BSP_CLOCKS_PLL_MUL(DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 0),                              \
			   DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 1))
#else
#define BSP_CFG_PLL_MUL BSP_CLOCKS_PLL_MUL(0, 0)
#endif

#define BSP_CFG_PLODIVP            RA_CGC_CLK_DIV(DT_NODELABEL(pllp), div, 2)
#define BSP_CFG_PLL1P_FREQUENCY_HZ (RA_CGC_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pllp), freq, 0))
#define BSP_CFG_PLODIVQ            RA_CGC_CLK_DIV(DT_NODELABEL(pllq), div, 2)
#define BSP_CFG_PLL1Q_FREQUENCY_HZ (RA_CGC_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pllq), freq, 0))
#define BSP_CFG_PLODIVR            RA_CGC_CLK_DIV(DT_NODELABEL(pllr), div, 2)
#define BSP_CFG_PLL1R_FREQUENCY_HZ (RA_CGC_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pllr), freq, 0))

#define BSP_CFG_PLL2_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(pll2)))
#define BSP_CFG_PLL2_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(pll2), div, 1)

#if DT_NODE_HAS_STATUS(DT_NODELABEL(pll), okay)
#define BSP_CFG_PLL_MUL                                                                            \
	BSP_CLOCKS_PLL_MUL(DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 0),                              \
			   DT_PROP_BY_IDX(DT_NODELABEL(pll), mul, 1))
#else
#define BSP_CFG_PLL_MUL BSP_CLOCKS_PLL_MUL(0, 0)
#endif

#define BSP_CFG_PL2ODIVP           RA_CGC_CLK_DIV(DT_NODELABEL(pll2p), div, 2)
#define BSP_CFG_PLL2P_FREQUENCY_HZ (RA_CGC_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2p), freq, 0))
#define BSP_CFG_PL2ODIVQ           RA_CGC_CLK_DIV(DT_NODELABEL(pll2q), div, 2)
#define BSP_CFG_PLL2Q_FREQUENCY_HZ (RA_CGC_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2q), freq, 0))
#define BSP_CFG_PL2ODIVR           RA_CGC_CLK_DIV(DT_NODELABEL(pll2r), div, 2)
#define BSP_CFG_PLL2R_FREQUENCY_HZ (RA_CGC_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pll2r), freq, 0))

#define BSP_CFG_CLOCK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(pclkblock)))
#define BSP_CFG_CPUCLK_DIV   RA_CGC_CLK_DIV(DT_NODELABEL(cpuclk), div, 1)

#define BSP_CFG_ICLK_DIV     RA_CGC_CLK_DIV(DT_NODELABEL(iclk), div, 2)
#define BSP_CFG_PCLKA_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(pclka), div, 4)
#define BSP_CFG_PCLKB_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(pclkb), div, 8)
#define BSP_CFG_PCLKC_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(pclkc), div, 8)
#define BSP_CFG_PCLKD_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(pclkd), div, 4)
#define BSP_CFG_PCLKE_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(pclke), div, 2)
#define BSP_CFG_BCLK_DIV     RA_CGC_CLK_DIV(DT_NODELABEL(bclk), div, 4)
#define BSP_CFG_SDCLK_OUTPUT (RA_CGC_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(bclkout), sdclk, 1))
#define BSP_CFG_BCLK_OUTPUT  (RA_CGC_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(bclkout), clk_out_div, 2))
#define BSP_CFG_FCLK_DIV     RA_CGC_CLK_DIV(DT_NODELABEL(fclk), div, 8)

#define BSP_CFG_UCLK_SOURCE     RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(uclk)))
#define BSP_CFG_UCLK_DIV        RA_CGC_CLK_DIV(DT_NODELABEL(uclk), div, 1)
#define BSP_CFG_USB60CLK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(u60clk)))
#define BSP_CFG_USB60CLK_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(u60clk), div, 1)
#define BSP_CFG_OCTACLK_SOURCE  RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(octaspiclk)))
#define BSP_CFG_OCTACLK_DIV     RA_CGC_CLK_DIV(DT_NODELABEL(octaspiclk), div, 1)
#define BSP_CFG_CANFDCLK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(canfdclk)))
#define BSP_CFG_CANFDCLK_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(canfdclk), div, 1)
#define BSP_CFG_CLKOUT_SOURCE   RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(clkout)))
#define BSP_CFG_CLKOUT_DIV      RA_CGC_CLK_DIV(DT_NODELABEL(clkout), div, 1)
#define BSP_CFG_SCICLK_SOURCE   RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(sciclk)))
#define BSP_CFG_SCICLK_DIV      RA_CGC_CLK_DIV(DT_NODELABEL(sciclk), div, 1)
#define BSP_CFG_SPICLK_SOURCE   RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(spiclk)))
#define BSP_CFG_SPICLK_DIV      RA_CGC_CLK_DIV(DT_NODELABEL(spiclk), div, 1)
#define BSP_CFG_I3CCLK_SOURCE   RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(i3cclk)))
#define BSP_CFG_I3CCLK_DIV      RA_CGC_CLK_DIV(DT_NODELABEL(i3cclk), div, 1)
#define BSP_CFG_LCDCLK_SOURCE   RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(lcdclk)))
#define BSP_CFG_LCDCLK_DIV      RA_CGC_CLK_DIV(DT_NODELABEL(lcdclk), div, 1)

#endif /* BSP_CLOCK_CFG_H_ */
