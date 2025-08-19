/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <zephyr/devicetree.h>

#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_

#define RZ_CPG_DIV(id)            DT_PROP_OR(DT_NODELABEL(id), div, 1)
#define RZ_CPG_PLL_POSTSCALER(id) DT_CLOCKS_CELL(DT_NODELABEL(id), postscaler)
#define RZ_CPG_CLK_SRC(id)        DT_PROP(DT_CLOCKS_CTLR(DT_NODELABEL(id)), clock_frequency)

#define RZ_CPG_GET_CLOCK(id) (RZ_CPG_CLK_SRC(id) / RZ_CPG_PLL_POSTSCALER(id) / RZ_CPG_DIV(id))

/* Helper macro */
#define RZ_CPG_CLK_DIV(clk)                                                                        \
	UTIL_CAT(RZ_CPG_DIV_, DT_NODE_FULL_NAME_UPPER_TOKEN(clk))                                  \
	(DT_PROP(clk, div))

#define RZ_CPG_DIV_ICLK(n)    UTIL_CAT(BSP_CLOCKS_PL1_DIV_, n)
#define RZ_CPG_DIV_P0CLK(n)   UTIL_CAT(BSP_CLOCKS_PL2A_DIV_, n)
#define RZ_CPG_DIV_I2CLK(n)   UTIL_CAT(BSP_CLOCKS_PL3CLK200FIX_DIV_, n)
#define RZ_CPG_DIV_P1CLK(n)   UTIL_CAT(BSP_CLOCKS_PL3B_DIV_, n)
#define RZ_CPG_DIV_P2CLK(n)   UTIL_CAT(BSP_CLOCKS_PL3A_DIV_, n)
#define RZ_CPG_DIV_SPI0CLK(n) UTIL_CAT(BSP_CLOCKS_PL3C_DIV_, n)
#define RZ_CPG_DIV_OC0CLK(n)  UTIL_CAT(BSP_CLOCKS_PL3F_DIV_, n)
#define RZ_CPG_DIV_M3CLK(n)   UTIL_CAT(BSP_CLOCKS_DSIA_DIV_, n)

#define BSP_CFG_CLOCKS_SECURE             (0)
#define BSP_CFG_CLOCKS_OVERRIDE           (0)
#define BSP_CFG_CLOCK_OSCCLK_HZ           DT_PROP_OR(DT_NODELABEL(osc), clock_frequency, 24000000)              /* OSC 24000000Hz */
#define BSP_CFG_CLOCK_PLL1_HZ             DT_PROP_OR(DT_NODELABEL(ppl1), clock_frequency, 1000000000)           /* PLL1 1000000000Hz */
#define BSP_CFG_CLOCK_ICLK_HZ             RZ_CPG_GET_CLOCK(iclk)                                                /* ICLK */
#define BSP_CFG_CLOCK_PLL2_1600_HZ        DT_PROP_OR(DT_NODELABEL(pll2_1600), clock_frequency, 1600000000)      /* PLL2 1600000000Hz */
#define BSP_CFG_CLOCK_PLL2_533_HZ         DT_PROP_OR(DT_NODELABEL(pll2_533), clock_frequency, 533000000)        /* PLL2 533000000Hz */
#define BSP_CFG_CLOCK_SD0CLK_HZ           RZ_CPG_GET_CLOCK(sd0clk)                                              /* SD0CLK */
#define BSP_CFG_CLOCK_SD1CLK_HZ           RZ_CPG_GET_CLOCK(sd1clk)                                              /* SD1CLK */
#define BSP_CFG_CLOCK_P0CLK_HZ            RZ_CPG_GET_CLOCK(p0clk)                                               /* P0CLK */
#define BSP_CFG_CLOCK_TSUCLK_HZ           RZ_CPG_GET_CLOCK(tsuclk)                                              /* TSUCLK */
#define BSP_CFG_CLOCK_PLL3_1600_HZ        DT_PROP_OR(DT_NODELABEL(pll3_1600), clock_frequency, 1600000000)      /* PLL3 1600000000Hz */
#define BSP_CFG_CLOCK_ATCLK_HZ            RZ_CPG_GET_CLOCK(atclk)                                               /* ATCLK */
#define BSP_CFG_CLOCK_I2CLK_HZ            RZ_CPG_GET_CLOCK(i2clk)                                               /* I2CLK */
#define BSP_CFG_CLOCK_P1CLK_HZ            RZ_CPG_GET_CLOCK(p1clk)                                               /* P1CLK */
#define BSP_CFG_CLOCK_M0CLK_HZ            RZ_CPG_GET_CLOCK(m0clk)                                               /* M0CLK */
#define BSP_CFG_CLOCK_ZTCLK_HZ            RZ_CPG_GET_CLOCK(ztclk)                                               /* ZTCLK */
#define BSP_CFG_CLOCK_P2CLK_HZ            RZ_CPG_GET_CLOCK(p2clk)                                               /* P2CLK */
#define BSP_CFG_CLOCK_PLL3_533_HZ         DT_PROP_OR(DT_NODELABEL(pll3_533), clock_frequency, 533000000)        /* PLL3 533000000Hz */
#define BSP_CFG_CLOCK_SPI0CLK_HZ          RZ_CPG_GET_CLOCK(spi0clk)                                             /* SPI0CLK */
#define BSP_CFG_CLOCK_SPI_QSPI0_SPCLK_HZ  (RZ_CPG_GET_CLOCK(spi0clk) >> 1)                                      /* SPI QSPI0_SPCLK */
#define BSP_CFG_CLOCK_PLL3_400_HZ         DT_PROP_OR(DT_NODELABEL(pll3_400), clock_frequency, 400000000)        /* PLL3 400000000Hz */
#define BSP_CFG_CLOCK_SPI1CLK_HZ          RZ_CPG_GET_CLOCK(spi1clk)                                             /* SPI1CLK */
#define BSP_CFG_CLOCK_M2CLK_HZ            RZ_CPG_GET_CLOCK(m2clk)                                               /* M2CLK */
#define BSP_CFG_CLOCK_OC0CLK_HZ           RZ_CPG_GET_CLOCK(oc0clk)                                              /* OC0CLK */
#define BSP_CFG_CLOCK_OCTA_QSPI0_SPCLK_HZ (RZ_CPG_GET_CLOCK(oc0clk) >> 1)                                       /* Octa QSPI0_SPCLK */
#define BSP_CFG_CLOCK_OC1CLK_HZ           RZ_CPG_GET_CLOCK(oc1clk)                                              /* OC1CLK */
#define BSP_CFG_CLOCK_PLL4_HZ             DT_PROP_OR(DT_NODELABEL(pll4), clock_frequency, 1600000000)           /* PLL4 1600MHz */
#define BSP_CFG_CLOCK_S0CLK_HZ            RZ_CPG_GET_CLOCK(s0clk)                                               /* S0CLK */
#define BSP_CFG_CLOCK_PLL5_1500_HZ        DT_PROP_OR(DT_NODELABEL(pll5_1500), clock_frequency, 1500000000)      /* PLL5 1500000000Hz */
#define BSP_CFG_DIVDSIB_SET_DIV           (BSP_CLOCKS_DSIB_DIV_1)                                               /* DSI_B Div /1 */
#define BSP_CFG_CLOCK_M3CLK_HZ            RZ_CPG_GET_CLOCK(m3clk)                                               /* M3CLK */
#define BSP_CFG_CLOCK_PLL5_500_HZ         DT_PROP_OR(DT_NODELABEL(pll5_500), clock_frequency, 500000000)        /* PLL5 500000000Hz */
#define BSP_CFG_CLOCK_PLL6_HZ             DT_PROP_OR(DT_NODELABEL(pll6), clock_frequency, 500000000)            /* PLL6 500000000Hz */
#define BSP_CFG_SEL_PLL6_2_SET_SOURCE     (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250)                                    /* PLL6_2 Sel: 250MHz (from PLL6) */
#define BSP_CFG_CLOCK_HPCLK_HZ            RZ_CPG_GET_CLOCK(hpclk)                                               /* HPCLK */

/* PLL3_3 Sel */
#define BSP_CFG_SEL_PLL3_3_SET_SOURCE                                                              \
        ((RZ_CPG_CLK_SRC(spi0clk) == 533000000) ? BSP_CLOCKS_SOURCE_CLOCK_PLL3_533                 \
                                                : BSP_CLOCKS_SOURCE_CLOCK_PLL3_400)

/* PLL3_5 Sel */
#define BSP_CFG_SEL_PLL3_5_SET_SOURCE                                                              \
        ((RZ_CPG_CLK_SRC(oc0clk) == 533000000) ? BSP_CLOCKS_SOURCE_CLOCK_PLL3_533                  \
                                               : BSP_CLOCKS_SOURCE_CLOCK_PLL3_400)

/* SD0CLK Sel */
#define BSP_CFG_SEL_SDHI0_SET_SOURCE                                                               \
        ((BSP_CFG_CLOCK_SD0CLK_HZ == 533000000)   ? BSP_CLOCKS_SOURCE_CLOCK_PLL2_533               \
         : (BSP_CFG_CLOCK_SD0CLK_HZ == 400000000) ? BSP_CLOCKS_SOURCE_CLOCK_PLL2_400               \
                                                  : BSP_CLOCKS_SOURCE_CLOCK_PLL2_266)

/* SD1CLK Sel */
#define BSP_CFG_SEL_SDHI1_SET_SOURCE                                                               \
        ((BSP_CFG_CLOCK_SD1CLK_HZ == 533000000)   ? BSP_CLOCKS_SOURCE_CLOCK_PLL2_533               \
         : (BSP_CFG_CLOCK_SD1CLK_HZ == 400000000) ? BSP_CLOCKS_SOURCE_CLOCK_PLL2_400               \
                                                  : BSP_CLOCKS_SOURCE_CLOCK_PLL2_266)

/* S0CLK Sel */
#define BSP_CFG_SEL_PLL4_SET_SOURCE                                                                \
        ((RZ_CPG_CLK_SRC(s0clk) == 1600000000) ? BSP_CLOCKS_SOURCE_CLOCK_PLL4_1600                 \
                                               : BSP_CLOCKS_SOURCE_CLOCK_OSC_0024)

#define BSP_CFG_DIVPL1_SET_DIV          RZ_CPG_CLK_DIV(DT_NODELABEL(iclk))              /* ICLK Div */
#define BSP_CFG_DIVPL2A_SET_DIV         RZ_CPG_CLK_DIV(DT_NODELABEL(p0clk))             /* P0CLK Div */
#define BSP_CFG_DIVPL3CLK200FIX_SET_DIV RZ_CPG_CLK_DIV(DT_NODELABEL(i2clk))             /* I2CLK Div */
#define BSP_CFG_DIVPL3B_SET_DIV         RZ_CPG_CLK_DIV(DT_NODELABEL(p1clk))             /* P1CLK Div */
#define BSP_CFG_DIVPL3A_SET_DIV         RZ_CPG_CLK_DIV(DT_NODELABEL(p2clk))             /* P2CLK Div */
#define BSP_CFG_DIVPL3C_SET_DIV         RZ_CPG_CLK_DIV(DT_NODELABEL(spi0clk))           /* PLL3_3 Div */
#define BSP_CFG_DIVPL3F_SET_DIV         RZ_CPG_CLK_DIV(DT_NODELABEL(oc0clk))            /* PLL3_5 Div */
#define BSP_CFG_DIVDSIA_SET_DIV         RZ_CPG_CLK_DIV(DT_NODELABEL(m3clk))             /* DSI_A Div */

#endif /* BSP_CLOCK_CFG_H_ */
