/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <zephyr/devicetree.h>

#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_
#define BSP_CFG_CLOCKS_SECURE           (0)                                                          /* Secure clock config */
#define BSP_CFG_CLOCKS_OVERRIDE         (0)                                                          /* Override clock config */
#define BSP_CFG_CLOCK_OSCCLK_HZ         DT_PROP_OR(DT_NODELABEL(oscclk), clock_frequency, 24000000)  /* OSC 24000000Hz */
#define BSP_CFG_CLOCK_PLL1_HZ           (1100000000)                                                 /* PLL1 1100000000Hz */
#define BSP_CFG_DIVPL1_SET_DIV          (BSP_CLOCKS_PL1_DIV_1)                                       /* ICLK Div /1 */
#define BSP_CFG_CLOCK_ICLK_HZ           DT_PROP_OR(DT_NODELABEL(iclk), clock_frequency, 1100000000)  /* ICLK 1100000000Hz */
#define BSP_CFG_CLOCK_PLL2_1600_HZ      (1600000000)                                                 /* PLL2 1600000000Hz */
#define BSP_CFG_DIVPL2B_SET_DIV         (BSP_CLOCKS_PL2B_DIV_1)                                      /* P0CLK Div /1 */
#define BSP_CFG_CLOCK_P0CLK_HZ          DT_PROP_OR(DT_NODELABEL(p0clk), clock_frequency, 100000000)  /* P0CLK 100000000Hz */
#define BSP_CFG_CLOCK_P4CLK_HZ          DT_PROP_OR(DT_NODELABEL(p4clk), clock_frequency, 160000000)  /* P4CLK 160000000Hz */
#define BSP_CFG_CLOCK_P5CLK_HZ          DT_PROP_OR(DT_NODELABEL(p5clk), clock_frequency, 200000000)  /* P5CLK 200000000Hz */
#define BSP_CFG_CLOCK_TSUCLK_HZ         DT_PROP_OR(DT_NODELABEL(tsuclk), clock_frequency, 100000000) /* TSUCLK 100000000Hz */
#define BSP_CFG_SEL_SDHI0_SET_SOURCE    (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266)                           /* SD0CLK Sel: 266MHz */
#define BSP_CFG_DIVSDHI0_SET_DIV        (BSP_CLOCKS_SDHI0_DIV_2)                                     /* SD0CLK Div /2 */
#define BSP_CFG_CLOCK_SD0CLK_HZ         DT_PROP_OR(DT_NODELABEL(sd0clk), clock_frequency, 133333333) /* SD0CLK 133333333Hz */
#define BSP_CFG_SEL_SDHI1_SET_SOURCE    (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266)                           /* SD1CLK Sel: 266MHz */
#define BSP_CFG_DIVSDHI1_SET_DIV        (BSP_CLOCKS_SDHI1_DIV_2)                                     /* SD1CLK Div /2 */
#define BSP_CFG_CLOCK_SD1CLK_HZ         DT_PROP_OR(DT_NODELABEL(sd1clk), clock_frequency, 133333333) /* SD1CLK 133333333Hz */
#define BSP_CFG_SEL_SDHI2_SET_SOURCE    (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266)                           /* SD2CLK Sel: 266MHz */
#define BSP_CFG_DIVSDHI2_SET_DIV        (BSP_CLOCKS_SDHI2_DIV_2)                                     /* SD2CLK Div /2 */
#define BSP_CFG_CLOCK_SD2CLK_HZ         DT_PROP_OR(DT_NODELABEL(sd2clk), clock_frequency, 133333333) /* SD2CLK 133333333Hz */
#define BSP_CFG_CLOCK_PLL3_HZ           (1600000000)                                                 /* PLL3 1600000000Hz */
#define BSP_CFG_CLOCK_M0CLK_HZ          DT_PROP_OR(DT_NODELABEL(m0clk), clock_frequency, 200000000)  /* M0CLK 200000000Hz */
#define BSP_CFG_DIVPL3A_SET_DIV         (BSP_CLOCKS_PL3A_DIV_1)                                      /* P1CLK Div /1 */
#define BSP_CFG_CLOCK_P1CLK_HZ          DT_PROP_OR(DT_NODELABEL(p1clk), clock_frequency, 200000000)  /* P1CLK 200000000Hz */
#define BSP_CFG_DIVPL3B_SET_DIV         (BSP_CLOCKS_PL3B_DIV_1)                                      /* P2CLK Div /1 */
#define BSP_CFG_CLOCK_P2CLK_HZ          DT_PROP_OR(DT_NODELABEL(p2clk), clock_frequency, 100000000)  /* P2CLK 100000000Hz */
#define BSP_CFG_DIVPL3C_SET_DIV         (BSP_CLOCKS_PL3C_DIV_1)                                      /* P3CLK Div /1 */
#define BSP_CFG_CLOCK_P3CLK_HZ          DT_PROP_OR(DT_NODELABEL(p3clk), clock_frequency, 200000000)  /* P3CLK 200000000Hz */
#define BSP_CFG_CLOCK_ATCLK_HZ          DT_PROP_OR(DT_NODELABEL(atclk), clock_frequency, 400000000)  /* ATCLK 400000000Hz */
#define BSP_CFG_CLOCK_ZTCLK_HZ          DT_PROP_OR(DT_NODELABEL(ztclk), clock_frequency, 100000000)  /* ZTCLK 100000000Hz */
#define BSP_CFG_SELOCTA_SET_SOURCE      (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266)                           /* OCCLK Sel: 266MHz */
#define BSP_CFG_DIVOCTA_SET_DIV         (BSP_CLOCKS_OCTA_DIV_8)                                      /* OCCLK Div /8 */
#define BSP_CFG_CLOCK_OC0CLK_HZ         DT_PROP_OR(DT_NODELABEL(oc0clk), clock_frequency, 33333333)  /* OC0CLK 33333333Hz */
#define BSP_CFG_CLOCK_OC1CLK_HZ         DT_PROP_OR(DT_NODELABEL(oc1clk), clock_frequency, 16666666)  /* OC1CLK 16666666Hz */
#define BSP_CFG_SELSPI_SET_SOURCE       (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400)                           /* SPICLK Sel: 400MHz */
#define BSP_CFG_DIVSPI_SET_DIV          (BSP_CLOCKS_SPI_DIV_4)                                       /* SPICLK Div /4 */
#define BSP_CFG_CLOCK_SPI0CLK_HZ        DT_PROP_OR(DT_NODELABEL(spi0clk), clock_frequency, 33333333) /* SPI0CLK 33333333Hz */
#define BSP_CFG_CLOCK_SPI1CLK_HZ        DT_PROP_OR(DT_NODELABEL(spi1clk), clock_frequency, 16666666) /* SPI1CLK 16666666Hz */
#define BSP_CFG_CLOCK_PLL4_HZ           (800000000)                                                  /* PLL4 800MHz */
#define BSP_CFG_SELPL4_SET_SOURCE       (BSP_CLOCKS_SOURCE_CLOCK_PLL4)                               /* Sel: PLL4 */
#define BSP_CFG_CLOCK_S0CLK_HZ          DT_PROP_OR(DT_NODELABEL(s0clk), clock_frequency, 400000000)  /* S0CLK 400000000Hz */
#define BSP_CFG_CLOCK_PLL6_HZ           (500000000)                                                  /* PLL6 500000000Hz */
#define BSP_CFG_DIVPL6A_SET_DIV         (BSP_CLOCKS_PL6A_DIV_1)                                      /* I2CLK Div /1 */
#define BSP_CFG_CLOCK_I2CLK_HZ          DT_PROP_OR(DT_NODELABEL(i2clk), clock_frequency, 250000000)  /* I2CLK 250000000Hz */
#define BSP_CFG_DIVPL6B_SET_DIV         (BSP_CLOCKS_PL6B_DIV_1)                                      /* I3CLK Div /1 */
#define BSP_CFG_CLOCK_I3CLK_HZ          DT_PROP_OR(DT_NODELABEL(i3clk), clock_frequency, 250000000)  /* I3CLK 250000000Hz */
#define BSP_CFG_CLOCK_HPCLK_HZ          DT_PROP_OR(DT_NODELABEL(hpclk), clock_frequency, 250000000)  /* HPCLK 250000000Hz */
#define BSP_CFG_CLOCK_OSCCLK2_HZ        DT_PROP_OR(DT_NODELABEL(osc2clk), clock_frequency, 8000000)  /* OSC2 8000000Hz */
#endif /* BSP_CLOCK_CFG_H_ */
