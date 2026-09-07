/*
 * Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


/*******************************************************************************************************************//**
 * @ingroup BSP_CONFIG_RA6B1
 * @defgroup BSP_CONFIG_RA6B1_CLOCKS Build Time Configurations - Clock
 *
 * This file contains build-time clock configuration options. The BSP will use these macros to setup the MCU's clocks
 * for the user before main() is executed.
 *
 * Clock configuration options.
 * The input clock frequency is specified and then the system clocks are set by specifying the multipliers used.
 *
 * @{
 **********************************************************************************************************************/

#ifndef BSP_CLOCK_CFG_RA6B1_H
#define BSP_CLOCK_CFG_RA6B1_H

#include <zephyr/devicetree.h>

/***********************************************************************************************************************
 * Configuration Options
 **********************************************************************************************************************/

/** Clock source select (SYS_CLK_SEL). The chosen clock will be the base clock provided for the system clock and DIV1
 * peripheral clocks.
 *
 * Set the macro to one of the enumerations shown.
 *
 * <PRE>
 * Clock                                -   Enumeration to use for macro
 * XTAL32M external oscillator          -   BSP_CLOCKS_SOURCE_CLOCK_XTALM
 * XTAL64M                              -   BSP_CLOCKS_SOURCE_CLOCK_XTALM_DBLR
 * RC32M/RCHS internal oscillator       -   BSP_CLOCKS_SOURCE_CLOCK_RCHS
 * RCLP internal oscillator             -   BSP_CLOCKS_SOURCE_SYS_CLK_RCLP
 * PLL                                  -   BSP_CLOCKS_SOURCE_CLOCK_PLL
 * </PRE>
 */
#ifndef BSP_CFG_CLOCK_SOURCE
 #if DT_SAME_NODE(DT_PHANDLE(DT_NODELABEL(sys_clk), clock_src), DT_NODELABEL(xtal32m))
  #define BSP_CFG_CLOCK_SOURCE                (BSP_CLOCKS_SOURCE_CLOCK_XTALM)
 #elif DT_SAME_NODE(DT_PHANDLE(DT_NODELABEL(sys_clk), clock_src), DT_NODELABEL(xtal64m))
  #define BSP_CFG_CLOCK_SOURCE                (BSP_CLOCKS_SOURCE_CLOCK_XTALM_DBLR)
 #elif DT_SAME_NODE(DT_PHANDLE(DT_NODELABEL(sys_clk), clock_src), DT_NODELABEL(sys_pll))
  #define BSP_CFG_CLOCK_SOURCE                (BSP_CLOCKS_SOURCE_CLOCK_PLL)
 #elif DT_SAME_NODE(DT_PHANDLE(DT_NODELABEL(sys_clk), clock_src), DT_NODELABEL(rchs))
  #define BSP_CFG_CLOCK_SOURCE                (BSP_CLOCKS_SOURCE_CLOCK_RCHS)
 #endif
#endif

/** LP Clock source select (LP_CLK_SEL). The chosen clock will be the base clock provided for the low-power clock.
 *
 * Set the macro to one of the enumerations shown.
 *
 * <PRE>
 * Clock                                -   Enumeration to use for macro
 * RCLP internal oscillator             -   BSP_CLOCKS_SOURCE_CLOCK_RCLP
 * RCX internal oscillator              -   BSP_CLOCKS_SOURCE_CLOCK_RCX
 * XTAL32K external oscillator          -   BSP_CLOCKS_SOURCE_CLOCK_XTALK
 * External square wave clock           -   BSP_CLOCKS_SOURCE_CLOCK_DIGITAL
 * </PRE>
 */
#ifndef BSP_CFG_LP_CLOCK_SOURCE
 #define BSP_CFG_LP_CLOCK_SOURCE             (BSP_CLOCKS_SOURCE_CLOCK_RCX)
#endif

/** XTAL32M - Input clock frequency in Hz */
#ifndef BSP_CFG_XTALM_HZ
 #define BSP_CFG_XTALM_HZ                    (32000000)
#endif

#ifndef BSP_CFG_PLL_FREQUENCY_HZ
 #define BSP_CFG_PLL_FREQUENCY_HZ             (128000000)
#endif

/** XTAL32K - Input clock frequency in Hz */
#ifndef BSP_CFG_XTALK_HZ
 #define BSP_CFG_XTALK_HZ                    (32768)
#endif

/** RCHS speed select (RCHS_SPEED). The chosen speed of the RCHS output, to be set only when RCHS is the system clock.
 *
 * Set the macro to one of the enumerations shown.
 *
 * <PRE>
 * Clock Frequency                      -   Enumeration to use for macro
 * 32 MHz                               -   BSP_RCHS_32M_SPEED_MODE
 * 64 MHz                               -   BSP_RCHS_64M_SPEED_MODE
 * </PRE>
 */
#ifndef BSP_CFG_RCHS_FREQUENCY
 #define BSP_CFG_RCHS_FREQUENCY              (BSP_RCHS_32M_SPEED_MODE)
#endif

/** RCLP Oscillator mode of operation.
 *
 * Set the macro to one of the enumerations shown.
 *
 * <PRE>
 * Operation Speed                      -   Enumeration to use for macro
 * High Speed (512kHz)                  -   BSP_RCLP_512K_SPEED_MODE
 * Low Speed  (32kHz)                   -   BSP_RCLP_32K_SPEED_MODE
 * </PRE>
 */
#ifndef BSP_CFG_RCLP_FREQUENCY
 #define BSP_CFG_RCLP_FREQUENCY              (BSP_RCLP_DEFAULT_SPEED_MODE)
#endif

/** Number of cycles of measured RC clock, for which calibration will be performed.
 *  Default is 25 cycles which introduces a delay of ~781us in the startup code.
 */
#ifndef BSP_CFG_CLOCK_CALIBRATION_CYCLES
 #define BSP_CFG_CLOCK_CALIBRATION_CYCLES    (25)
#endif

/** APB Interface Clock Divider (PCLK).
 *
 * Available divisors = /1 (no division), /2, /4, /8
 *
 * @note Set macro definition to 'BSP_CLOCKS_SYS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PCLK_DIV
 #define BSP_CFG_PCLK_DIV                    (BSP_CLOCKS_SYS_CLOCK_DIV_1)
#endif

/** QSPI Clock Output Frequency Divider (QSPI_DIV).
 *
 * Available divisors = /1, /2, /4, /8
 *
 * @note Set macro definition to 'BSP_CLOCKS_QSPI_CLK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_QSPICLK_DIV
 #define BSP_CFG_QSPICLK_DIV                 (BSP_CLOCKS_QSPI_CLK_DIV_1)
#endif

/**
 * The SPI Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIV1
 */
#ifndef BSP_CFG_SPI_CLK_SOURCE
 #define BSP_CFG_SPI_CLK_SOURCE              (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/** SPI Clock Output Frequency Divider (SPI_DIV).
 *
 * Available divisors = /2, /4, /8, /14
 *
 * @note Set macro definition to 'BSP_CLOCKS_SPI_CLK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_SPI_DIV
 #define BSP_CFG_SPI_DIV                     (BSP_CLOCKS_SPI_CLK_DIV_8)
#endif

/**
 * The SPI2 Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIV1
 */
#ifndef BSP_CFG_SPI2_CLK_SOURCE
 #define BSP_CFG_SPI2_CLK_SOURCE             (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/** SPI2 Clock Output Frequency Divider (SPI2_DIV).
 *
 * Available divisors = /2, /4, /8, /14
 *
 * @note Set macro definition to 'BSP_CLOCKS_SPI_CLK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_SPI2_DIV
 #define BSP_CFG_SPI2_DIV                    (BSP_CLOCKS_SPI2_CLK_DIV_8)
#endif

/**
 * The SPI3 Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIV1
 */
#ifndef BSP_CFG_SPI3_CLK_SOURCE
 #define BSP_CFG_SPI3_CLK_SOURCE             (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/** SPI3 Clock Output Frequency Divider (SPI_DIV).
 *
 * Available divisors = /2, /4, /8, /14
 *
 * @note Set macro definition to 'BSP_CLOCKS_SPI3_CLK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_SPI3_DIV
 #define BSP_CFG_SPI3_DIV                    (BSP_CLOCKS_SPI3_CLK_DIV_8)
#endif

/**
 * The I2C Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIV1
 */
#ifndef BSP_CFG_I2C_CLK_SOURCE
 #define BSP_CFG_I2C_CLK_SOURCE              (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/**
 * The I2C2 Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIV1
 */
#ifndef BSP_CFG_I2C2_CLK_SOURCE
 #define BSP_CFG_I2C2_CLK_SOURCE             (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/**
 * The I2C3 Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIV1
 */
#ifndef BSP_CFG_I2C3_CLK_SOURCE
 #define BSP_CFG_I2C3_CLK_SOURCE             (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/**
 * The UART Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN
 */
#ifndef BSP_CFG_UART_CLK_SOURCE
 #define BSP_CFG_UART_CLK_SOURCE             (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/**
 * The UART2 Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIV1
 */
#ifndef BSP_CFG_UART2_CLK_SOURCE
 #define BSP_CFG_UART2_CLK_SOURCE            (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/**
 * The UART3 Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIV1
 */
#ifndef BSP_CFG_UART3_CLK_SOURCE
 #define BSP_CFG_UART3_CLK_SOURCE            (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/**
 * The UART4 Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN
 */
#ifndef BSP_CFG_UART4_CLK_SOURCE
 #define BSP_CFG_UART4_CLK_SOURCE            (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/**
 * The GPADC Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_DISABLED
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIVN_DIV2
 *   - BSP_CLOCKS_SOURCE_CLOCK_DIV1
 */
#ifndef BSP_CFG_GPADC_CLK_SOURCE
 #define BSP_CFG_GPADC_CLK_SOURCE            (BSP_CLOCKS_SOURCE_CLOCK_DISABLED)
#endif

/**
 * The USB Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CLOCKS_SOURCE_CLOCK_PLL (divided by 2)
 *   - BSP_CLOCKS_SOURCE_CLOCK_HCLK
 */
#ifndef BSP_CFG_UCK_SOURCE
 #define BSP_CFG_UCK_SOURCE                  (BSP_CLOCKS_SOURCE_CLOCK_PLL)
#endif

/**
 * The maximum CMAC Clock frequency in Hz, when the CMAC is running at system clock (sys_clk).
 * It is configured during startup.
 * Available vallues:
 *   - 32000000  - 32 MHz
 *   - 64000000  - 64 MHz
 *   - 128000000 - 128 MHz
 */
#ifndef BSP_CFG_CMACCLK_MAX_SPEED_HZ
 #define BSP_CFG_CMACCLK_MAX_SPEED_HZ        (64000000)
#endif

/**
 * The CMAC Clock source that is configured during startup.
 * Available clock sources:
 *   - BSP_CMAC_RAD_CLK_SYS      - sys_clk (limited to BSP_CFG_CMACCLK_MAX_SPEED_HZ)
 *   - BSP_CMAC_RAD_CLK_XTAL32M  - XTAL 32 MHz
 *   - BSP_CMAC_RAD_CLK_XTAL64M  - XTAL 64 MHz
 */
#ifndef BSP_CFG_CMACCLK_SOURCE
 #define BSP_CFG_CMACCLK_SOURCE              (BSP_CMAC_RAD_CLK_SYS)
#endif

/**
 * The CMAC Clock in Hz.
 * Available vallues:
 *   - 32000000  - 32 MHz
 *   - 64000000  - 64 MHz
 *   - 128000000 - 128 MHz
 */
#ifndef BSP_CFG_CMACCLK_HZ
 #define BSP_CFG_CMACCLK_HZ                  (64000000)
#endif

#endif

/** @} (end defgroup BSP_CONFIG_RA6B1_CLOCKS) */
