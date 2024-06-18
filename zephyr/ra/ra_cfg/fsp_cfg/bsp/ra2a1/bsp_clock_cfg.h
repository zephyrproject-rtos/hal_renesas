/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
* Copyright (c) 2024 TOKITA Hiroshi
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

#if DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 24000000
#define BSP_CFG_HOCO_FREQUENCY 0 /* HOCO 24MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 32000000
#define BSP_CFG_HOCO_FREQUENCY 2 /* HOCO 32MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 48000000
#define BSP_CFG_HOCO_FREQUENCY 4 /* HOCO 48MHz */
#elif DT_PROP(DT_NODELABEL(hoco), clock_frequency) == 64000000
#define BSP_CFG_HOCO_FREQUENCY 5 /* HOCO 64MHz */
#else
#error "Invalid HOCO frequency, only can be set to 24MHz, 32MHz, 48MHz, 64MHz"
#endif
#define BSP_CFG_CLOCK_SOURCE                                                                       \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkblock), sysclock_src,                   \
					  RA_PLL_SOURCE_DISABLE)
#define BSP_CFG_ICLK_DIV                                                                           \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(iclk), clk_div, RA_SYS_CLOCK_DIV_1)
#define BSP_CFG_PCLKB_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkb), clk_div, RA_SYS_CLOCK_DIV_2)
#define BSP_CFG_PCLKD_DIV                                                                          \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(pclkd), clk_div, RA_SYS_CLOCK_DIV_1)
#define BSP_CFG_FCLK_DIV                                                                           \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(fclk), clk_div, RA_SYS_CLOCK_DIV_2)

#define BSP_CFG_SDADCCLK_SOURCE                                                                      \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(sdadcclk), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_SDADCCLK_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(sdadcclk), clk_div, 0)

#define BSP_CFG_CLKOUT_SOURCE                                                                      \
	BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(clkout), clk_src, RA_CLOCK_SOURCE_DISABLE)
#define BSP_CFG_CLKOUT_DIV BSP_CLOCK_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(clkout), clk_div, 0)

#endif /* BSP_CLOCK_CFG_H_ */
