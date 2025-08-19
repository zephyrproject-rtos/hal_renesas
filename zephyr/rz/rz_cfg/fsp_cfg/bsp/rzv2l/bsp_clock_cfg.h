/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <zephyr/devicetree.h>

#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_
#define BSP_CFG_CLOCKS_SECURE           (0)
#define BSP_CFG_CLOCKS_OVERRIDE         (0)
#define BSP_CFG_CLOCK_OSCCLK_HZ         DT_PROP_OR(DT_NODELABEL(oscclk), clock_frequency, 24000000)   /* OSC 24000000Hz */
#define BSP_CFG_CLOCK_ICLK_HZ           DT_PROP_OR(DT_NODELABEL(iclk), clock_frequency, 1200000000)   /* ICLK 1200000000Hz */
#define BSP_CFG_CLOCK_I2CLK_HZ          DT_PROP_OR(DT_NODELABEL(i2clk), clock_frequency, 200000000)   /* I2CLK 200000000Hz */
#define BSP_CFG_CLOCK_GCLK_HZ           DT_PROP_OR(DT_NODELABEL(gclk), clock_frequency, 500000000)    /* GCLK 500000000Hz */
#define BSP_CFG_CLOCK_S0CLK_HZ          DT_PROP_OR(DT_NODELABEL(s0clk), clock_frequency, 12000)       /* S0CLK 12000Hz */
#define BSP_CFG_CLOCK_SPI0CLK_HZ        DT_PROP_OR(DT_NODELABEL(spi0clk), clock_frequency, 200000000) /* SPI0CLK 200000000Hz */
#define BSP_CFG_CLOCK_SPI1CLK_HZ        DT_PROP_OR(DT_NODELABEL(spi1clk), clock_frequency, 100000000) /* SPI1CLK 100000000Hz */
#define BSP_CFG_CLOCK_SD0CLK_HZ         DT_PROP_OR(DT_NODELABEL(sd0clk), clock_frequency, 533000000)  /* SD0CLK 533000000Hz */
#define BSP_CFG_CLOCK_SD1CLK_HZ         DT_PROP_OR(DT_NODELABEL(sd1clk), clock_frequency, 533000000)  /* SD1CLK 533000000Hz */
#define BSP_CFG_CLOCK_M0CLK_HZ          DT_PROP_OR(DT_NODELABEL(m0clk), clock_frequency, 200000000)   /* M0CLK 200000000Hz */
#define BSP_CFG_CLOCK_M1CLK_HZ          DT_PROP_OR(DT_NODELABEL(m1clk), clock_frequency, 3000000000)  /* M1CLK 3000000000Hz */
#define BSP_CFG_CLOCK_M2CLK_HZ          DT_PROP_OR(DT_NODELABEL(m2clk), clock_frequency, 266500000)   /* M2CLK 266500000Hz */
#define BSP_CFG_CLOCK_M3CLK_HZ          DT_PROP_OR(DT_NODELABEL(m3clk), clock_frequency, 3000000000)  /* M3CLK 3000000000Hz */
#define BSP_CFG_CLOCK_M4CLK_HZ          DT_PROP_OR(DT_NODELABEL(m4clk), clock_frequency, 16656000)    /* M4CLK 16656000Hz */
#define BSP_CFG_CLOCK_HPCLK_HZ          DT_PROP_OR(DT_NODELABEL(hpclk), clock_frequency, 250000000)   /* HPCLK 250000000Hz */
#define BSP_CFG_CLOCK_TSUCLK_HZ         DT_PROP_OR(DT_NODELABEL(tsuclk), clock_frequency, 80000000)   /* TSUCLK 80000000Hz */
#define BSP_CFG_CLOCK_ZTCLK_HZ          DT_PROP_OR(DT_NODELABEL(ztclk), clock_frequency, 100000000)   /* ZTCLK 100000000Hz */
#define BSP_CFG_CLOCK_P0CLK_HZ          DT_PROP_OR(DT_NODELABEL(p0clk), clock_frequency, 100000000)   /* P0CLK 100000000Hz */
#define BSP_CFG_CLOCK_P1CLK_HZ          DT_PROP_OR(DT_NODELABEL(p1clk), clock_frequency, 200000000)   /* P1CLK 200000000Hz */
#define BSP_CFG_CLOCK_P2CLK_HZ          DT_PROP_OR(DT_NODELABEL(p2clk), clock_frequency, 100000000)   /* P2CLK 100000000Hz */
#define BSP_CFG_CLOCK_ATCLK_HZ          DT_PROP_OR(DT_NODELABEL(atclk), clock_frequency, 400000000)   /* ATCLK 400000000Hz */
#endif /* BSP_CLOCK_CFG_H_ */
