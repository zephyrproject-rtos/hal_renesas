/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <zephyr/drivers/clock_control/renesas_rz_cgc.h>

#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_
#define BSP_CFG_CLOCKS_SECURE (0)
#define BSP_CFG_CLOCKS_OVERRIDE (0)
#define BSP_CFG_MAIN_CLOCK_HZ (DT_PROP(DT_NODELABEL(osc), clock_frequency)) /* Main Clock: 25MHz */
BUILD_ASSERT(BSP_CFG_MAIN_CLOCK_HZ == 25000000, "The main clock must be 25MHz!");

/* LOCO Enable/Disable */
#define BSP_CFG_LOCO_ENABLE                                                                        \
	((DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(loco)) == 1) ? BSP_CLOCKS_LOCO_ENABLE               \
							    : BSP_CLOCKS_LOCO_DISABLE)

/* PLL1 initial state */
#define BSP_CFG_PLL1                                                                               \
	((DT_ENUM_IDX(DT_NODELABEL(pll1), state) == 0)  ? BSP_CLOCKS_PLL1_INITIAL                  \
	: (DT_ENUM_IDX(DT_NODELABEL(pll1), state) == 1) ? BSP_CLOCKS_PLL1_STANDBY                  \
							: BSP_CLOCKS_PLL1_NORMAL)

/* Ethernet Clock src */
#define BSP_CFG_PHYSEL	DT_ENUM_IDX(DT_NODELABEL(eth_refclk), eth_phy_source)

#define BSP_CFG_CLMA0_ENABLE 	(BSP_CLOCKS_CLMA0_ENABLE) 	  /* CLMA0 Enabled */
#define BSP_CFG_CLMA0MASK 	(BSP_CLOCKS_CLMA0_ERROR_NOT_MASK) /* CLMA0 error not mask */
#define BSP_CFG_CLMA3MASK 	(BSP_CLOCKS_CLMA3_ERROR_NOT_MASK) /* CLMA3 error not mask */
#define BSP_CFG_CLMA1MASK 	(BSP_CLOCKS_CLMA1_ERROR_MASK) 	  /* CLMA1 error mask */
#define BSP_CFG_CLMA3_ENABLE 	(BSP_CLOCKS_CLMA3_ENABLE) 	  /* CLMA3 Enabled */
#define BSP_CFG_CLMA1_ENABLE 	(BSP_CLOCKS_CLMA1_ENABLE) 	  /* CLMA1 Enabled */
#define BSP_CFG_CLMA2_ENABLE 	(BSP_CLOCKS_CLMA2_ENABLE) 	  /* CLMA2 Enabled */
#define BSP_CFG_CLMA0_CMPL 	(1) 				  /* CLMA0 CMPL 1 */
#define BSP_CFG_CLMA1_CMPL 	(1) 				  /* CLMA1 CMPL 1 */
#define BSP_CFG_CLMA2_CMPL 	(1) 				  /* CLMA2 CMPL 1 */
#define BSP_CFG_CLMA3_CMPL 	(1) 				  /* CLMA3 CMPL 1 */
#define BSP_CFG_CLMASEL 	(BSP_CLOCKS_CLMASEL_LOCO) 	  /* Alternative clock: LOCO */
#define BSP_CFG_CLMA0_CMPH 	(1023) 				  /* CLMA0 CMPH 1023 */
#define BSP_CFG_CLMA1_CMPH 	(1023) 				  /* CLMA1 CMPH 1023 */
#define BSP_CFG_CLMA2_CMPH 	(1023) 				  /* CLMA2 CMPH 1023 */
#define BSP_CFG_CLMA3_CMPH 	(1023) 				  /* CLMA3 CMPH 1023 */

#define BSP_CFG_DIVSELSUB 	DT_ENUM_IDX(DT_NODELABEL(iclk), clock_frequency)	 /* ICLK */
#define BSP_CFG_CKIO 		RZ_CGC_SUBCLK_DIV(DT_NODELABEL(ckio))			 /* CKIO Div */
#define BSP_CFG_FSELCPU0 	RZ_CGC_SUBCLK_MUL(DT_NODELABEL(cpu0clk))		 /* CPU0CLK Mul */
#define BSP_CFG_SCI0ASYNCCLK 	DT_ENUM_IDX(DT_NODELABEL(sci0asyncclk), clock_frequency) /* SCI0ASYNCCLK */
#define BSP_CFG_SCI1ASYNCCLK 	DT_ENUM_IDX(DT_NODELABEL(sci1asyncclk), clock_frequency) /* SCI1ASYNCCLK */
#define BSP_CFG_SCI2ASYNCCLK 	DT_ENUM_IDX(DT_NODELABEL(sci2asyncclk), clock_frequency) /* SCI2ASYNCCLK */
#define BSP_CFG_SCI3ASYNCCLK 	DT_ENUM_IDX(DT_NODELABEL(sci3asyncclk), clock_frequency) /* SCI3ASYNCCLK */
#define BSP_CFG_SCI4ASYNCCLK 	DT_ENUM_IDX(DT_NODELABEL(sci4asyncclk), clock_frequency) /* SCI4ASYNCCLK */
#define BSP_CFG_SCI5ASYNCCLK 	DT_ENUM_IDX(DT_NODELABEL(sci5asyncclk), clock_frequency) /* SCI5ASYNCCLK */
#define BSP_CFG_SPI0ASYNCCLK 	DT_ENUM_IDX(DT_NODELABEL(spi0asyncclk), clock_frequency) /* SPI0ASYNCCLK */
#define BSP_CFG_SPI1ASYNCCLK 	DT_ENUM_IDX(DT_NODELABEL(spi1asyncclk), clock_frequency) /* SPI1ASYNCCLK */
#define BSP_CFG_SPI2ASYNCCLK 	DT_ENUM_IDX(DT_NODELABEL(spi2asyncclk), clock_frequency) /* SPI2ASYNCCLK */
#define BSP_CFG_SPI3ASYNCCLK 	DT_ENUM_IDX(DT_NODELABEL(spi3asyncclk), clock_frequency) /* SPI3ASYNCCLK */

/* Validate the CPU0 multiplier */
BUILD_ASSERT(IN_RANGE(LOG2(DT_PROP(DT_NODELABEL(cpu0clk), mul)), 0, 1) == 1,
			"The CPU0 multiplier must be 1 or 2!");

/* CANFDCLK Src */
#define BSP_CFG_FSELCANFD                                                                          \
	((DT_ENUM_IDX(DT_NODELABEL(canfdclk), canfd_source) == 0) ? BSP_CLOCKS_CANFD_CLOCK_80_MHZ  \
	: (DT_ENUM_IDX(DT_NODELABEL(canfdclk), canfd_source) == 1) ? BSP_CLOCKS_CANFD_CLOCK_40_MHZ \
								   : BSP_CLOCKS_CANFD_CLOCK_PCLKM)

/* XSPI_CLK0 */
#define BSP_CFG_FSELXSPI0_DIVSELXSPI0                                                                                 \
	((DT_PROP(DT_NODELABEL(xspi_clk0), xspi_clk_frequency) == 133333333)  ? BSP_CLOCKS_XSPI0_CLOCK_DIV0_133_3_MHZ \
	: (DT_PROP(DT_NODELABEL(xspi_clk0), xspi_clk_frequency) == 100000000) ? BSP_CLOCKS_XSPI0_CLOCK_DIV0_100_0_MHZ \
	: (DT_PROP(DT_NODELABEL(xspi_clk0), xspi_clk_frequency) == 50000000)  ? BSP_CLOCKS_XSPI0_CLOCK_DIV0_50_0_MHZ  \
	: (DT_PROP(DT_NODELABEL(xspi_clk0), xspi_clk_frequency) == 25000000)  ? BSP_CLOCKS_XSPI0_CLOCK_DIV0_25_0_MHZ  \
	: (DT_PROP(DT_NODELABEL(xspi_clk0), xspi_clk_frequency) == 12500000)  ? BSP_CLOCKS_XSPI0_CLOCK_DIV0_12_5_MHZ  \
	: (DT_PROP(DT_NODELABEL(xspi_clk0), xspi_clk_frequency) == 75000000)  ? BSP_CLOCKS_XSPI0_CLOCK_DIV1_75_0_MHZ  \
									      : BSP_CLOCKS_XSPI0_CLOCK_DIV1_37_5_MHZ)

/* XSPI_CLK1 */
#define BSP_CFG_FSELXSPI1_DIVSELXSPI1                                                                                 \
	((DT_PROP(DT_NODELABEL(xspi_clk1), xspi_clk_frequency) == 133333333)  ? BSP_CLOCKS_XSPI1_CLOCK_DIV0_133_3_MHZ \
	: (DT_PROP(DT_NODELABEL(xspi_clk1), xspi_clk_frequency) == 100000000) ? BSP_CLOCKS_XSPI1_CLOCK_DIV0_100_0_MHZ \
	: (DT_PROP(DT_NODELABEL(xspi_clk1), xspi_clk_frequency) == 50000000)  ? BSP_CLOCKS_XSPI1_CLOCK_DIV0_50_0_MHZ  \
	: (DT_PROP(DT_NODELABEL(xspi_clk1), xspi_clk_frequency) == 25000000)  ? BSP_CLOCKS_XSPI1_CLOCK_DIV0_25_0_MHZ  \
	: (DT_PROP(DT_NODELABEL(xspi_clk1), xspi_clk_frequency) == 12500000)  ? BSP_CLOCKS_XSPI1_CLOCK_DIV0_12_5_MHZ  \
	: (DT_PROP(DT_NODELABEL(xspi_clk1), xspi_clk_frequency) == 75000000)  ? BSP_CLOCKS_XSPI1_CLOCK_DIV1_75_0_MHZ  \
									      : BSP_CLOCKS_XSPI1_CLOCK_DIV1_37_5_MHZ)

#endif /* BSP_CLOCK_CFG_H_ */
