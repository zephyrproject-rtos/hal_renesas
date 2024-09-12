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

#define BSP_CFG_CLOCK_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(pclkblock)))

#define BSP_CFG_ICLK_DIV  RA_CGC_CLK_DIV(DT_NODELABEL(iclk), div, 2)
#define BSP_CFG_PCLKB_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pclkb), div, 2)
#define BSP_CFG_PCLKD_DIV RA_CGC_CLK_DIV(DT_NODELABEL(pclkd), div, 1)

#define BSP_CFG_CLKOUT_SOURCE RA_CGC_CLK_SRC(DT_CLOCKS_CTLR(DT_NODELABEL(clkout)))
#define BSP_CFG_CLKOUT_DIV    RA_CGC_CLK_DIV(DT_NODELABEL(clkout), div, 1)

#endif /* BSP_CLOCK_CFG_H_ */
