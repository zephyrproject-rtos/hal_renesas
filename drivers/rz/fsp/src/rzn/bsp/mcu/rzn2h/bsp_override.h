/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RZN2H
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RZN2H) */

#ifndef BSP_OVERRIDE_H
#define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* BSP Common Includes. */
#include "bsp_common.h"

/* BSP MPU Specific Includes. */
#include "bsp_register_protection.h"
#include "bsp_irq.h"
#include "bsp_io.h"
#include "bsp_clocks.h"
#include "bsp_module_stop.h"
#include "bsp_semaphore.h"
#include "bsp_reset.h"
#include "bsp_cache.h"
#include "bsp_slave_stop.h"

/*BSP MMU Includes*/
#ifdef BSP_CFG_CORE_CA55
 #include "ca/bsp_mmu_core.h"
#endif

/* Factory MPU information. */
#include "fsp_features.h"

/* BSP Common Includes (Other than bsp_common.h) */
#include "bsp_delay.h"
#include "bsp_mcu_api.h"

/* BSP TFU Includes. */
#if BSP_FEATURE_TFU_SUPPORTED
 #include "bsp_tfu.h"
#endif

/* BSP TZC400 Includes. */
#if BSP_FEATURE_TZC400_SUPPORTED
 #include "bsp_tzc400.h"
#endif

/* BSP Address Expander Includes. */
#if BSP_FEATURE_ADDRESS_EXPANDER_SUPPORTED
 #include "bsp_address_expander.h"
#endif

/* BSP DDR Includes. */
#if BSP_FEATURE_DDR_SUPPORTED
 #include "bsp_ddr.h"
#endif

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Define overrides required for this MPU. */
#define BSP_OVERRIDE_ADC_INFO_T
#define BSP_OVERRIDE_ADC_CHANNEL_T
#define BSP_OVERRIDE_CGC_CLOCK_T
#define BSP_OVERRIDE_CGC_PLL_CFG_T
#define BSP_OVERRIDE_CGC_DIVIDER_CFG_T
#define BSP_OVERRIDE_CGC_CLOCK_CHANGE_T
#define BSP_OVERRIDE_CGC_CLOCKS_CFG_T
#define BSP_OVERRIDE_ELC_PERIPHERAL_T
#define BSP_OVERRIDE_ERROR_EVENT_T
#define BSP_OVERRIDE_ETHER_EVENT_T
#define BSP_OVERRIDE_ETHER_CALLBACK_ARGS_T
#define BSP_OVERRIDE_ETHER_PHY_LSI_TYPE_T
#define BSP_OVERRIDE_ETHER_SWITCH_CALLBACK_ARGS_T
#define BSP_OVERRIDE_POEG_STATE_T
#define BSP_OVERRIDE_POEG_TRIGGER_T
#define BSP_OVERRIDE_POE3_STATE_T

#define BSP_OVERRIDE_TRANSFER_MODE_T
#define BSP_OVERRIDE_TRANSFER_SIZE_T
#define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
#define BSP_OVERRIDE_TRANSFER_CALLBACK_ARGS_T
#define BSP_OVERRIDE_TRANSFER_INFO_T

/* Override definitions. */

#define ELC_PERIPHERAL_NUM     (194U)

/* Private definition to set enumeration values. */
#define IOPORT_P_OFFSET        (0U)
#define IOPORT_PM_OFFSET       (1U)
#define IOPORT_PMC_OFFSET      (3U)
#define IOPORT_PFC_OFFSET      (4U)
#define IOPORT_DRCTL_OFFSET    (10U)
#define IOPORT_RSELP_OFFSET    (16U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/*==============================================
 * ADC API Overrides
 *==============================================*/

/** ADC channels */
typedef enum e_adc_channel
{
    ADC_CHANNEL_0                 = 0,     ///< ADC channel 0
    ADC_CHANNEL_1                 = 1,     ///< ADC channel 1
    ADC_CHANNEL_2                 = 2,     ///< ADC channel 2
    ADC_CHANNEL_3                 = 3,     ///< ADC channel 3
    ADC_CHANNEL_4                 = 4,     ///< ADC channel 4
    ADC_CHANNEL_5                 = 5,     ///< ADC channel 5
    ADC_CHANNEL_6                 = 6,     ///< ADC channel 6
    ADC_CHANNEL_7                 = 7,     ///< ADC channel 7
    ADC_CHANNEL_8                 = 8,     ///< ADC channel 8
    ADC_CHANNEL_9                 = 9,     ///< ADC channel 9
    ADC_CHANNEL_10                = 10,    ///< ADC channel 10
    ADC_CHANNEL_11                = 11,    ///< ADC channel 11
    ADC_CHANNEL_12                = 12,    ///< ADC channel 12
    ADC_CHANNEL_13                = 13,    ///< ADC channel 13
    ADC_CHANNEL_14                = 14,    ///< ADC channel 14
    ADC_CHANNEL_15                = 15,    ///< ADC channel 15
    ADC_CHANNEL_16                = 16,    ///< ADC channel 16
    ADC_CHANNEL_17                = 17,    ///< ADC channel 17
    ADC_CHANNEL_18                = 18,    ///< ADC channel 18
    ADC_CHANNEL_19                = 19,    ///< ADC channel 19
    ADC_CHANNEL_20                = 20,    ///< ADC channel 20
    ADC_CHANNEL_21                = 21,    ///< ADC channel 21
    ADC_CHANNEL_22                = 22,    ///< ADC channel 22
    ADC_CHANNEL_23                = 23,    ///< ADC channel 23
    ADC_CHANNEL_24                = 24,    ///< ADC channel 24
    ADC_CHANNEL_25                = 25,    ///< ADC channel 25
    ADC_CHANNEL_26                = 26,    ///< ADC channel 26
    ADC_CHANNEL_27                = 27,    ///< ADC channel 27
    ADC_CHANNEL_28                = 28,    ///< ADC channel 28
    ADC_CHANNEL_DUPLEX_A          = 50,    ///< Data duplexing register A
    ADC_CHANNEL_DUPLEX_B          = 51,    ///< Data duplexing register B
    ADC_CHANNEL_DUPLEX            = -4,    ///< Data duplexing register
    ADC_CHANNEL_TEMPERATURE       = -3,    ///< Temperature sensor output
    ADC_CHANNEL_VOLT              = -2,    ///< Internal reference voltage
    ADC_CHANNEL_0_DSMIF_CAPTURE_A = 0x100, ///< ADC channel 0 Capture Current Data Register A
    ADC_CHANNEL_0_DSMIF_CAPTURE_B = 0x200, ///< ADC channel 0 Capture Current Data Register B
    ADC_CHANNEL_1_DSMIF_CAPTURE_A = 0x101, ///< ADC channel 1 Capture Current Data Register A
    ADC_CHANNEL_1_DSMIF_CAPTURE_B = 0x201, ///< ADC channel 1 Capture Current Data Register B
    ADC_CHANNEL_2_DSMIF_CAPTURE_A = 0x102, ///< ADC channel 2 Capture Current Data Register A
    ADC_CHANNEL_2_DSMIF_CAPTURE_B = 0x202, ///< ADC channel 2 Capture Current Data Register B
} adc_channel_t;

/*==============================================
 * CGC API Overrides
 *==============================================*/

/** Divider values of clock provided to xSPI */
typedef enum e_cgc_fsel_xspi_clock_div
{
    CGC_FSEL_XSPI_CLOCK_DIV_6  = 0x02, ///< XSPI_CLKn 133.3MHz (XSPI base clock divided by 3)
    CGC_FSEL_XSPI_CLOCK_DIV_8  = 0x03, ///< XSPI_CLKn 100.0MHz / 75.0MHz (XSPI base clock divided by 3 / divided by 4)
    CGC_FSEL_XSPI_CLOCK_DIV_16 = 0x04, ///< XSPI_CLKn 50.0MHz / 37.5MHz (XSPI base clock divided by 3 / divided by 4)
    CGC_FSEL_XSPI_CLOCK_DIV_32 = 0x05, ///< XSPI_CLKn 25.0MHz (XSPI base clock divided by 3)
    CGC_FSEL_XSPI_CLOCK_DIV_64 = 0x06, ///< XSPI_CLKn 12.5MHz (XSPI base clock divided by 3)
} cgc_fsel_xspi_clock_div_t;

/** Divider values of base clock generated for xSPI */
typedef enum e_cgc_divsel_xspi_clock_div
{
    CGC_DIVSEL_XSPI_CLOCK_DIV_3 = 0x00, ///< XSPI base clock divided by 3
    CGC_DIVSEL_XSPI_CLOCK_DIV_4 = 0x01, ///< XSPI base clock divided by 4
} cgc_divsel_xspi_clock_div_t;

/** Clock output divider values */
typedef enum e_cgc_clock_out_clock_div
{
    CGC_CLOCK_OUT_CLOCK_DIV_2 = 0,     ///< CKIO 100.0MHz / 75.0MHz (Base clock divided by 3 / divided by 4)
    CGC_CLOCK_OUT_CLOCK_DIV_3 = 1,     ///< CKIO 66.7MHz / 50.0MHz (Base clock divided by 3 / divided by 4)
    CGC_CLOCK_OUT_CLOCK_DIV_4 = 2,     ///< CKIO 50.0MHz / 37.5MHz (Base clock divided by 3 / divided by 4)
    CGC_CLOCK_OUT_CLOCK_DIV_5 = 3,     ///< CKIO 40.0MHz / 30.0MHz (Base clock divided by 3 / divided by 4)
    CGC_CLOCK_OUT_CLOCK_DIV_6 = 4,     ///< CKIO 33.3MHz / 25.0MHz (Base clock divided by 3 / divided by 4)
    CGC_CLOCK_OUT_CLOCK_DIV_7 = 5,     ///< CKIO 28.6MHz / 21.4MHz (Base clock divided by 3 / divided by 4)
    CGC_CLOCK_OUT_CLOCK_DIV_8 = 6,     ///< CKIO 25.0MHz / 18.75MHz (Base clock divided by 3 / divided by 4)
} cgc_clock_out_clock_div_t;

/** CANFD clock divider values */
typedef enum e_cgc_canfd_clock_div
{
    CGC_CANFD_CLOCK_DIV_10 = 0,        ///< CANFD clock 80.0MHz
    CGC_CANFD_CLOCK_DIV_20 = 1,        ///< CANFD clock 40.0MHz
} cgc_canfd_clock_div_t;

/** PHY clock source identifiers */
typedef enum e_cgc_phy_clock
{
    CGC_PHY_CLOCK_PLL1     = 0,        ///< PLL1 divider clock
    CGC_PHY_CLOCK_MAIN_OSC = 1,        ///< Main clock oscillator
} cgc_phy_clock_t;

/** SPI asynchronous serial clock frequency */
typedef enum e_cgc_spi_async_clock
{
    CGC_SPI_ASYNC_CLOCK_75MHZ  = 0,    ///< SPI asynchronous serial clock 75MHz
    CGC_SPI_ASYNC_CLOCK_80MHZ  = 1,    ///< SPI asynchronous serial clock 80MHz
    CGC_SPI_ASYNC_CLOCK_96MHZ  = 2,    ///< SPI asynchronous serial clock 96MHz
    CGC_SPI_ASYNC_CLOCK_100MHZ = 3,    ///< SPI asynchronous serial clock 100MHz
} cgc_spi_async_clock_t;

/** SCI asynchronous serial clock frequency */
typedef enum e_cgc_sci_async_clock
{
    CGC_SCI_ASYNC_CLOCK_75MHZ  = 0,    ///< SCI asynchronous serial clock 75MHz
    CGC_SCI_ASYNC_CLOCK_80MHZ  = 1,    ///< SCI asynchronous serial clock 80MHz
    CGC_SCI_ASYNC_CLOCK_96MHZ  = 2,    ///< SCI asynchronous serial clock 96MHz
    CGC_SCI_ASYNC_CLOCK_100MHZ = 3,    ///< SCI asynchronous serial clock 100MHz
} cgc_sci_async_clock_t;

/** LCDC clock divider values */
typedef enum e_cgc_lcdc_div
{
    CGC_LCDC_DIV_2  = 0,               ///< PLL3 output clock divided by 2
    CGC_LCDC_DIV_4  = 1,               ///< PLL3 output clock divided by 4
    CGC_LCDC_DIV_6  = 2,               ///< PLL3 output clock divided by 6
    CGC_LCDC_DIV_8  = 3,               ///< PLL3 output clock divided by 8
    CGC_LCDC_DIV_10 = 4,               ///< PLL3 output clock divided by 10
    CGC_LCDC_DIV_12 = 5,               ///< PLL3 output clock divided by 12
    CGC_LCDC_DIV_14 = 6,               ///< PLL3 output clock divided by 14
    CGC_LCDC_DIV_16 = 7,               ///< PLL3 output clock divided by 16
    CGC_LCDC_DIV_18 = 8,               ///< PLL3 output clock divided by 18
    CGC_LCDC_DIV_20 = 9,               ///< PLL3 output clock divided by 20
    CGC_LCDC_DIV_22 = 10,              ///< PLL3 output clock divided by 22
    CGC_LCDC_DIV_24 = 11,              ///< PLL3 output clock divided by 24
    CGC_LCDC_DIV_26 = 12,              ///< PLL3 output clock divided by 26
    CGC_LCDC_DIV_28 = 13,              ///< PLL3 output clock divided by 28
    CGC_LCDC_DIV_30 = 14,              ///< PLL3 output clock divided by 30
    CGC_LCDC_DIV_32 = 15,              ///< PLL3 output clock divided by 32s
} cgc_lcdc_div_t;

/** SCIE asynchronous serial clock frequency */
typedef enum e_cgc_scie_async_clock
{
    CGC_SCIE_ASYNC_CLOCK_75MHZ  = 0,   ///< SCI asynchronous serial clock 75MHz
    CGC_SCIE_ASYNC_CLOCK_80MHZ  = 1,   ///< SCI asynchronous serial clock 80MHz
    CGC_SCIE_ASYNC_CLOCK_96MHZ  = 2,   ///< SCI asynchronous serial clock 96MHz
    CGC_SCIE_ASYNC_CLOCK_100MHZ = 3,   ///< SCI asynchronous serial clock 100MHz
} cgc_scie_async_clock_t;

/** ENCOUT clock frequency */
typedef enum e_cgc_encout_clock
{
    CGC_ENCOUT_CLOCK_20MHZ = 0,        ///< ENCOUT provided clock 20MHz
    CGC_ENCOUT_CLOCK_80MHZ = 1,        ///< ENCOUT provided clock 80MHz
} cgc_encout_clock_t;

/** CPU clock divider values */
typedef enum e_cgc_cpu_clock_div
{
    CGC_CPU_CLOCK_DIV_2 = 0,           ///< CR52/DSU 500MHz, CA55 600MHz
    CGC_CPU_CLOCK_DIV_1 = 1,           ///< CR52/DSU 1000MHz, CA55 1200MHz
} cgc_cpu_clock_div_t;

/** System clock source identifiers */
typedef enum e_cgc_clock
{
    CGC_CLOCK_LOCO = 0,                       ///< The low speed on chip oscillator
    CGC_CLOCK_PLL0 = 1,                       ///< The PLL0 oscillator
    CGC_CLOCK_PLL1 = 2,                       ///< The PLL1 oscillator
    CGC_CLOCK_PLL2 = 3,                       ///< The PLL2 oscillator
    CGC_CLOCK_PLL3 = 4,                       ///< The PLL3 oscillator
    CGC_CLOCK_PLL4 = 5,                       ///< The PLL4 oscillator
} cgc_clock_t;
typedef struct st_cgc_pll_ssc_cfg
{
    uint8_t pll_ssc_enable : 1;               ///< SSC function enable
    uint8_t pll_ssc_modulation_freq_ctrl;     ///< Modulation frequency control parameter for SSC
    uint8_t pll_ssc_modulation_rate_ctrl : 6; ///< Modulation rate control parameter for SSC
} cgc_pll_ssc_cfg_t;

typedef struct st_cgc_pll_vco_cfg
{
    uint8_t  pll_divider_p : 6;                 ///< PLL P-divider
    uint16_t pll_divider_m : 10;                ///< PLL M-divider
    uint8_t  pll_divider_s : 3;                 ///< PLL S-divider
    uint16_t pll_divider_delta_sigma_modulator; ///< PLL Delta-Sigma Modulator
} cgc_pll_vco_cfg_t;

/** Clock configuration structure - Dummy definition because it is not used in this MPU.
 * Set NULL as an input parameter to the @ref cgc_api_t::clockStart function for the PLL clock. */
typedef struct st_cgc_pll_cfg
{
    cgc_pll_ssc_cfg_t pll0_ssc_cfg;
    cgc_pll_ssc_cfg_t pll2_ssc_cfg;
    cgc_pll_vco_cfg_t pll3_vco_cfg;
} cgc_pll_cfg_t;

/** Clock configuration structure */
typedef struct st_cgc_divider_cfg
{
    union
    {
        uint32_t sckcr_w;                                ///< System Clock Control Register

        struct
        {
            cgc_fsel_xspi_clock_div_t fselxspi0     : 3; ///< Divider value for XSPI_CLK0
            uint32_t                                : 3;
            cgc_divsel_xspi_clock_div_t divselxspi0 : 1; ///< Divider base value for XSPI_CLK0
            uint32_t                                : 1;
            cgc_fsel_xspi_clock_div_t fselxspi1     : 3; ///< Divider value for XSPI_CLK1
            uint32_t                                : 3;
            cgc_divsel_xspi_clock_div_t divselxspi1 : 1; ///< Divider base value for XSPI_CLK1
            uint32_t                                : 1;
            cgc_clock_out_clock_div_t ckio_div      : 3; ///< Divider value for CKIO
            uint32_t                                : 1;
            cgc_canfd_clock_div_t fselcanfd_div     : 1; ///< Divider value for CANFD clock
            cgc_phy_clock_t       phy_sel           : 1; ///< Ethernet PHY reference clock output
            uint32_t                                : 10;
        } sckcr_b;
    };

    union
    {
        uint32_t sckcr2_w;                            ///< System Clock Control Register 2

        struct
        {
            cgc_cpu_clock_div_t cr52cpu0         : 2; ///< Divider value for Cortex-R52 CPU0
            cgc_cpu_clock_div_t cr52cpu1         : 2; ///< Divider value for Cortex-R52 CPU1
            uint32_t                             : 4;
            cgc_cpu_clock_div_t ca55core0        : 1; ///< Divider value for Cortex-A55 Core0
            cgc_cpu_clock_div_t ca55core1        : 1; ///< Divider value for Cortex-A55 Core1
            cgc_cpu_clock_div_t ca55core2        : 1; ///< Divider value for Cortex-A55 Core2
            cgc_cpu_clock_div_t ca55core3        : 1; ///< Divider value for Cortex-A55 Core3
            cgc_cpu_clock_div_t ca55sclk         : 1; ///< Divider value for Cortex-A55 DSU
            uint32_t                             : 3;
            cgc_spi_async_clock_t spi3_async_sel : 2; ///< SPI3 asynchronous serial clock
            cgc_sci_async_clock_t sci5_async_sel : 2; ///< SCI5 asynchronous serial clock
            uint32_t                             : 12;
        } sckcr2_b;
    };

    union
    {
        uint32_t sckcr3_w;                            ///< System Clock Control Register 3

        struct
        {
            cgc_spi_async_clock_t spi0_async_sel : 2; ///< SPI0 asynchronous serial clock
            cgc_spi_async_clock_t spi1_async_sel : 2; ///< SPI1 asynchronous serial clock
            cgc_spi_async_clock_t spi2_async_sel : 2; ///< SPI2 asynchronous serial clock
            cgc_sci_async_clock_t sci0_async_sel : 2; ///< SCI0 asynchronous serial clock
            cgc_sci_async_clock_t sci1_async_sel : 2; ///< SCI1 asynchronous serial clock
            cgc_sci_async_clock_t sci2_async_sel : 2; ///< SCI2 asynchronous serial clock
            cgc_sci_async_clock_t sci3_async_sel : 2; ///< SCI3 asynchronous serial clock
            cgc_sci_async_clock_t sci4_async_sel : 2; ///< SCI4 asynchronous serial clock
            uint32_t                             : 4;
            cgc_lcdc_div_t lcdc_div_sel          : 4; ///< Divider value for LCDC
            uint32_t                             : 8;
        } sckcr3_b;
    };

    union
    {
        uint32_t sckcr4_w;                               ///< System Clock Control Register 4

        struct
        {
            cgc_scie_async_clock_t scie0_async_sel  : 2; ///< SCIE0 asynchronous serial clock
            cgc_scie_async_clock_t scie1_async_sel  : 2; ///< SCIE1 asynchronous serial clock
            cgc_scie_async_clock_t scie2_async_sel  : 2; ///< SCIE2 asynchronous serial clock
            cgc_scie_async_clock_t scie3_async_sel  : 2; ///< SCIE3 asynchronous serial clock
            cgc_scie_async_clock_t scie4_async_sel  : 2; ///< SCIE4 asynchronous serial clock
            cgc_scie_async_clock_t scie5_async_sel  : 2; ///< SCIE5 asynchronous serial clock
            cgc_scie_async_clock_t scie6_async_sel  : 2; ///< SCIE6 asynchronous serial clock
            cgc_scie_async_clock_t scie7_async_sel  : 2; ///< SCIE7 asynchronous serial clock
            cgc_scie_async_clock_t scie8_async_sel  : 2; ///< SCIE8 asynchronous serial clock
            cgc_scie_async_clock_t scie9_async_sel  : 2; ///< SCIE9 asynchronous serial clock
            cgc_scie_async_clock_t scie10_async_sel : 2; ///< SCIE10 asynchronous serial clock
            cgc_scie_async_clock_t scie11_async_sel : 2; ///< SCIE11 asynchronous serial clock
            cgc_encout_clock_t     encoutclk        : 1; ///< ENCOUT provided clock
            uint32_t                                : 7;
        } sckcr4_b;
    };
} cgc_divider_cfg_t;

/** Clock options */
typedef enum e_cgc_clock_change
{
    CGC_CLOCK_CHANGE_START = 0,        ///< Start the clock
    CGC_CLOCK_CHANGE_STOP  = 1,        ///< Stop the clock
    CGC_CLOCK_CHANGE_NONE  = 2,        ///< No change to the clock
} cgc_clock_change_t;

/** Clock configuration */
typedef struct st_cgc_clocks_cfg
{
    cgc_divider_cfg_t  divider_cfg;    ///< Clock dividers structure
    cgc_pll_ssc_cfg_t  pll0_ssc_cfg;   ///< Configuration of PLL0 SSC function setting
    cgc_pll_ssc_cfg_t  pll2_ssc_cfg;   ///< Configuration of PLL2 SSC function setting
    cgc_pll_vco_cfg_t  pll3_vco_cfg;   ///< Configuration of PLL3 VCO setting
    cgc_clock_change_t loco_state;     ///< State of LOCO
    cgc_clock_change_t pll0_state;     ///< State of PLL0
    cgc_clock_change_t pll2_state;     ///< State of PLL2
    cgc_clock_change_t pll3_state;     ///< State of PLL3
} cgc_clocks_cfg_t;

/*==============================================
 * ELC API Overrides
 *==============================================*/

/** Possible peripherals to be linked to event signals (not all available on all MPUs) */
typedef enum e_elc_peripheral
{
    ELC_PERIPHERAL_MTU0           = (0),
    ELC_PERIPHERAL_MTU3           = (1),
    ELC_PERIPHERAL_MTU4           = (2),
    ELC_PERIPHERAL_GPT00_A        = (3),
    ELC_PERIPHERAL_GPT00_B        = (4),
    ELC_PERIPHERAL_GPT00_C        = (5),
    ELC_PERIPHERAL_GPT00_D        = (6),
    ELC_PERIPHERAL_GPT00_E        = (7),
    ELC_PERIPHERAL_GPT00_F        = (8),
    ELC_PERIPHERAL_GPT01_A        = (9),
    ELC_PERIPHERAL_GPT01_B        = (10),
    ELC_PERIPHERAL_GPT01_C        = (11),
    ELC_PERIPHERAL_GPT01_D        = (12),
    ELC_PERIPHERAL_GPT01_E        = (13),
    ELC_PERIPHERAL_GPT01_F        = (14),
    ELC_PERIPHERAL_GPT02_A        = (15),
    ELC_PERIPHERAL_GPT02_B        = (16),
    ELC_PERIPHERAL_GPT02_C        = (17),
    ELC_PERIPHERAL_GPT02_D        = (18),
    ELC_PERIPHERAL_GPT02_E        = (19),
    ELC_PERIPHERAL_GPT02_F        = (20),
    ELC_PERIPHERAL_GPT03_A        = (21),
    ELC_PERIPHERAL_GPT03_B        = (22),
    ELC_PERIPHERAL_GPT03_C        = (23),
    ELC_PERIPHERAL_GPT03_D        = (24),
    ELC_PERIPHERAL_GPT03_E        = (25),
    ELC_PERIPHERAL_GPT03_F        = (26),
    ELC_PERIPHERAL_GPT04_A        = (27),
    ELC_PERIPHERAL_GPT04_B        = (28),
    ELC_PERIPHERAL_GPT04_C        = (29),
    ELC_PERIPHERAL_GPT04_D        = (30),
    ELC_PERIPHERAL_GPT04_E        = (31),
    ELC_PERIPHERAL_GPT04_F        = (32),
    ELC_PERIPHERAL_GPT05_A        = (33),
    ELC_PERIPHERAL_GPT05_B        = (34),
    ELC_PERIPHERAL_GPT05_C        = (35),
    ELC_PERIPHERAL_GPT05_D        = (36),
    ELC_PERIPHERAL_GPT05_E        = (37),
    ELC_PERIPHERAL_GPT05_F        = (38),
    ELC_PERIPHERAL_GPT06_A        = (39),
    ELC_PERIPHERAL_GPT06_B        = (40),
    ELC_PERIPHERAL_GPT06_C        = (41),
    ELC_PERIPHERAL_GPT06_D        = (42),
    ELC_PERIPHERAL_GPT06_E        = (43),
    ELC_PERIPHERAL_GPT06_F        = (44),
    ELC_PERIPHERAL_GPT07_A        = (45),
    ELC_PERIPHERAL_GPT07_B        = (46),
    ELC_PERIPHERAL_GPT07_C        = (47),
    ELC_PERIPHERAL_GPT07_D        = (48),
    ELC_PERIPHERAL_GPT07_E        = (49),
    ELC_PERIPHERAL_GPT07_F        = (50),
    ELC_PERIPHERAL_GPT08_A        = (51),
    ELC_PERIPHERAL_GPT08_B        = (52),
    ELC_PERIPHERAL_GPT08_C        = (53),
    ELC_PERIPHERAL_GPT08_D        = (54),
    ELC_PERIPHERAL_GPT08_E        = (55),
    ELC_PERIPHERAL_GPT08_F        = (56),
    ELC_PERIPHERAL_GPT09_A        = (57),
    ELC_PERIPHERAL_GPT09_B        = (58),
    ELC_PERIPHERAL_GPT09_C        = (59),
    ELC_PERIPHERAL_GPT09_D        = (60),
    ELC_PERIPHERAL_GPT09_E        = (61),
    ELC_PERIPHERAL_GPT09_F        = (62),
    ELC_PERIPHERAL_GPT09_G        = (63),
    ELC_PERIPHERAL_GPT09_H        = (64),
    ELC_PERIPHERAL_ADC0_A         = (65),
    ELC_PERIPHERAL_ADC0_B         = (66),
    ELC_PERIPHERAL_ADC1_A         = (67),
    ELC_PERIPHERAL_ADC1_B         = (68),
    ELC_PERIPHERAL_ADC2_A         = (69),
    ELC_PERIPHERAL_ADC2_B         = (70),
    ELC_PERIPHERAL_DSMIF0_CAP0    = (71),
    ELC_PERIPHERAL_DSMIF0_CAP1    = (72),
    ELC_PERIPHERAL_DSMIF0_CAP2    = (73),
    ELC_PERIPHERAL_DSMIF0_CAP3    = (74),
    ELC_PERIPHERAL_DSMIF0_CAP4    = (75),
    ELC_PERIPHERAL_DSMIF0_CAP5    = (76),
    ELC_PERIPHERAL_DSMIF0_CDCNT0  = (77),
    ELC_PERIPHERAL_DSMIF0_CDCNT1  = (78),
    ELC_PERIPHERAL_DSMIF0_CDCNT2  = (79),
    ELC_PERIPHERAL_DSMIF1_CAP0    = (80),
    ELC_PERIPHERAL_DSMIF1_CAP1    = (81),
    ELC_PERIPHERAL_DSMIF1_CAP2    = (82),
    ELC_PERIPHERAL_DSMIF1_CAP3    = (83),
    ELC_PERIPHERAL_DSMIF1_CAP4    = (84),
    ELC_PERIPHERAL_DSMIF1_CAP5    = (85),
    ELC_PERIPHERAL_DSMIF1_CDCNT0  = (86),
    ELC_PERIPHERAL_DSMIF1_CDCNT1  = (87),
    ELC_PERIPHERAL_DSMIF1_CDCNT2  = (88),
    ELC_PERIPHERAL_DSMIF2_CAP0    = (89),
    ELC_PERIPHERAL_DSMIF2_CAP1    = (90),
    ELC_PERIPHERAL_DSMIF2_CAP2    = (91),
    ELC_PERIPHERAL_DSMIF2_CAP3    = (92),
    ELC_PERIPHERAL_DSMIF2_CAP4    = (93),
    ELC_PERIPHERAL_DSMIF2_CAP5    = (94),
    ELC_PERIPHERAL_DSMIF2_CDCNT0  = (95),
    ELC_PERIPHERAL_DSMIF2_CDCNT1  = (96),
    ELC_PERIPHERAL_DSMIF2_CDCNT2  = (97),
    ELC_PERIPHERAL_DSMIF3_CAP0    = (98),
    ELC_PERIPHERAL_DSMIF3_CAP1    = (99),
    ELC_PERIPHERAL_DSMIF3_CAP2    = (100),
    ELC_PERIPHERAL_DSMIF3_CAP3    = (101),
    ELC_PERIPHERAL_DSMIF3_CAP4    = (102),
    ELC_PERIPHERAL_DSMIF3_CAP5    = (103),
    ELC_PERIPHERAL_DSMIF3_CDCNT0  = (104),
    ELC_PERIPHERAL_DSMIF3_CDCNT1  = (105),
    ELC_PERIPHERAL_DSMIF3_CDCNT2  = (106),
    ELC_PERIPHERAL_DSMIF4_CAP0    = (107),
    ELC_PERIPHERAL_DSMIF4_CAP1    = (108),
    ELC_PERIPHERAL_DSMIF4_CAP2    = (109),
    ELC_PERIPHERAL_DSMIF4_CAP3    = (110),
    ELC_PERIPHERAL_DSMIF4_CAP4    = (111),
    ELC_PERIPHERAL_DSMIF4_CAP5    = (112),
    ELC_PERIPHERAL_DSMIF4_CDCNT0  = (113),
    ELC_PERIPHERAL_DSMIF4_CDCNT1  = (114),
    ELC_PERIPHERAL_DSMIF4_CDCNT2  = (115),
    ELC_PERIPHERAL_DSMIF5_CAP0    = (116),
    ELC_PERIPHERAL_DSMIF5_CAP1    = (117),
    ELC_PERIPHERAL_DSMIF5_CAP2    = (118),
    ELC_PERIPHERAL_DSMIF5_CAP3    = (119),
    ELC_PERIPHERAL_DSMIF5_CAP4    = (120),
    ELC_PERIPHERAL_DSMIF5_CAP5    = (121),
    ELC_PERIPHERAL_DSMIF5_CDCNT0  = (122),
    ELC_PERIPHERAL_DSMIF5_CDCNT1  = (123),
    ELC_PERIPHERAL_DSMIF5_CDCNT2  = (124),
    ELC_PERIPHERAL_DSMIF7_CAP0    = (134),
    ELC_PERIPHERAL_DSMIF7_CAP1    = (135),
    ELC_PERIPHERAL_DSMIF7_CAP2    = (136),
    ELC_PERIPHERAL_DSMIF7_CAP3    = (137),
    ELC_PERIPHERAL_DSMIF7_CAP4    = (138),
    ELC_PERIPHERAL_DSMIF7_CAP5    = (139),
    ELC_PERIPHERAL_DSMIF7_CDCNT0  = (140),
    ELC_PERIPHERAL_DSMIF7_CDCNT1  = (141),
    ELC_PERIPHERAL_DSMIF7_CDCNT2  = (142),
    ELC_PERIPHERAL_DSMIF8_CAP0    = (143),
    ELC_PERIPHERAL_DSMIF8_CAP1    = (144),
    ELC_PERIPHERAL_DSMIF8_CAP2    = (145),
    ELC_PERIPHERAL_DSMIF8_CAP3    = (146),
    ELC_PERIPHERAL_DSMIF8_CAP4    = (147),
    ELC_PERIPHERAL_DSMIF8_CAP5    = (148),
    ELC_PERIPHERAL_DSMIF8_CDCNT0  = (149),
    ELC_PERIPHERAL_DSMIF8_CDCNT1  = (150),
    ELC_PERIPHERAL_DSMIF8_CDCNT2  = (151),
    ELC_PERIPHERAL_ENCIF_SS_TRG0  = (161),
    ELC_PERIPHERAL_ENCIF_SS_TRG1  = (162),
    ELC_PERIPHERAL_ENCIF_SS_TRG2  = (163),
    ELC_PERIPHERAL_ENCIF_SS_TRG3  = (164),
    ELC_PERIPHERAL_ENCIF_SS_TRG4  = (165),
    ELC_PERIPHERAL_ENCIF_SS_TRG5  = (166),
    ELC_PERIPHERAL_ENCIF_SS_TRG6  = (167),
    ELC_PERIPHERAL_ENCIF_SS_TRG7  = (168),
    ELC_PERIPHERAL_ENCIF_SS_TRG9  = (170),
    ELC_PERIPHERAL_ENCIF_SS_TRG10 = (171),
    ELC_PERIPHERAL_ENCIF_SS_TRG11 = (172),
    ELC_PERIPHERAL_ENCIF_SS_TRG12 = (173),
    ELC_PERIPHERAL_ENCIF_SS_TRG13 = (174),
    ELC_PERIPHERAL_ENCIF_SS_TRG14 = (175),
    ELC_PERIPHERAL_ESC0           = (177),
    ELC_PERIPHERAL_ESC1           = (178),
    ELC_PERIPHERAL_GMAC0_CAP0     = (179),
    ELC_PERIPHERAL_GMAC0_CAP1     = (180),
    ELC_PERIPHERAL_GMAC1_CAP0     = (181),
    ELC_PERIPHERAL_GMAC1_CAP1     = (182),
    ELC_PERIPHERAL_GMAC2_CAP0     = (183),
    ELC_PERIPHERAL_GMAC2_CAP1     = (184),
    ELC_PERIPHERAL_OUTPORTGR1     = (185),
    ELC_PERIPHERAL_OUTPORTGR2     = (186),
    ELC_PERIPHERAL_INPORTGR1      = (187),
    ELC_PERIPHERAL_INPORTGR2      = (188),
    ELC_PERIPHERAL_SINGLEPORT0    = (189),
    ELC_PERIPHERAL_SINGLEPORT1    = (190),
    ELC_PERIPHERAL_SINGLEPORT2    = (191),
    ELC_PERIPHERAL_SINGLEPORT3    = (192),
    ELC_PERIPHERAL_ENCOUT_TRIGGER = (193)
} elc_peripheral_t;

/*==============================================
 * ERROR API Overrides
 *==============================================*/

/** Error event source. */
typedef enum e_error_event
{
    ERROR_EVENT_CPU0,                  ///< Error event from CR520
    ERROR_EVENT_CPU1,                  ///< Error event from CR521
    ERROR_EVENT_CA55,                  ///< Error event from CA55
    ERROR_EVENT_PERIPHERAL_0,          ///< Error event from Peripheral 0
    ERROR_EVENT_PERIPHERAL_1,          ///< Error event from Peripheral 1
    ERROR_EVENT_PERIPHERAL_2,          ///< Error event from Peripheral 2
    ERROR_EVENT_DSMIF_0,               ///< Error event from DSMIF 0
    ERROR_EVENT_DSMIF_1,               ///< Error event from DSMIF 1
    ERROR_EVENT_DSMIF_2,               ///< Error event from DSMIF 2
    ERROR_EVENT_DSMIF_3,               ///< Error event from DSMIF 3
    ERROR_EVENT_DSMIF_4,               ///< Error event from DSMIF 4
    ERROR_EVENT_DSMIF_5,               ///< Error event from DSMIF 5
    ERROR_EVENT_DSMIF_7,               ///< Error event from DSMIF 7
    ERROR_EVENT_DSMIF_8,               ///< Error event from DSMIF 8
    ERROR_EVENT_DSMIF_10,              ///< Error event from DSMIF 10
    ERROR_EVENT_DSMIF_11,              ///< Error event from DSMIF 11
    ERROR_EVENT_ENCIF_0,               ///< Error event from ENCIF 0
    ERROR_EVENT_ENCIF_1,               ///< Error event from ENCIF 1
    ERROR_EVENT_ENCIF_2,               ///< Error event from ENCIF 2
    ERROR_EVENT_ENCIF_3,               ///< Error event from ENCIF 3
    ERROR_EVENT_ENCIF_4,               ///< Error event from ENCIF 4
} error_event_t;

/*==============================================
 * IOPORT API Overrides
 *==============================================*/

/** Superset of all peripheral functions.  */
typedef enum e_ioport_pin_pfc
{
    IOPORT_PIN_P000_PFC_00_SEI             = (0x00U << IOPORT_PFC_OFFSET), ///< P00_0 / IRQ / SEI
    IOPORT_PIN_P000_PFC_04_D0              = (0x04U << IOPORT_PFC_OFFSET), ///< P00_0 / BSC / D0
    IOPORT_PIN_P000_PFC_06_MTIOC3B         = (0x06U << IOPORT_PFC_OFFSET), ///< P00_0 / MTU3 / MTIOC3B
    IOPORT_PIN_P000_PFC_09_GTIOC00_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P00_0 / GPT / GTIOC00_0A
    IOPORT_PIN_P000_PFC_0F_ETH3_TXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P00_0 / ETHER_ETHn / ETH3_TXER
    IOPORT_PIN_P000_PFC_13_USB_VBUSEN      = (0x13U << IOPORT_PFC_OFFSET), ///< P00_0 / USB / USB_VBUSEN
    IOPORT_PIN_P000_PFC_24_DUEI00          = (0x24U << IOPORT_PFC_OFFSET), ///< P00_0 / ENDATn / DUEI00
    IOPORT_PIN_P000_PFC_25_HDSL00_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P00_0 / HDSLn / HDSL00_LINK
    IOPORT_PIN_P001_PFC_00_IRQ0            = (0x00U << IOPORT_PFC_OFFSET), ///< P00_1 / IRQ / IRQ0
    IOPORT_PIN_P001_PFC_04_D1              = (0x04U << IOPORT_PFC_OFFSET), ///< P00_1 / BSC / D1
    IOPORT_PIN_P001_PFC_06_MTIOC3D         = (0x06U << IOPORT_PFC_OFFSET), ///< P00_1 / MTU3 / MTIOC3D
    IOPORT_PIN_P001_PFC_09_GTIOC00_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P00_1 / GPT / GTIOC00_0B
    IOPORT_PIN_P001_PFC_0F_ETH3_RXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P00_1 / ETHER_ETHn / ETH3_RXER
    IOPORT_PIN_P001_PFC_13_USB_OVRCUR      = (0x13U << IOPORT_PFC_OFFSET), ///< P00_1 / USB / USB_OVRCUR
    IOPORT_PIN_P001_PFC_24_TST_OUT00       = (0x24U << IOPORT_PFC_OFFSET), ///< P00_1 / ENDATn / TST_OUT00
    IOPORT_PIN_P001_PFC_25_HDSL00_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P00_1 / HDSLn / HDSL00_SMPL
    IOPORT_PIN_P002_PFC_00_IRQ1            = (0x00U << IOPORT_PFC_OFFSET), ///< P00_2 / IRQ / IRQ1
    IOPORT_PIN_P002_PFC_04_D2              = (0x04U << IOPORT_PFC_OFFSET), ///< P00_2 / BSC / D2
    IOPORT_PIN_P002_PFC_06_MTIOC4A         = (0x06U << IOPORT_PFC_OFFSET), ///< P00_2 / MTU3 / MTIOC4A
    IOPORT_PIN_P002_PFC_09_GTIOC00_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P00_2 / GPT / GTIOC00_1A
    IOPORT_PIN_P002_PFC_0F_ETH3_CRS        = (0x0FU << IOPORT_PFC_OFFSET), ///< P00_2 / ETHER_ETHn / ETH3_CRS
    IOPORT_PIN_P002_PFC_13_USB_EXICEN      = (0x13U << IOPORT_PFC_OFFSET), ///< P00_2 / USB / USB_EXICEN
    IOPORT_PIN_P002_PFC_1F_ADTRG0          = (0x1FU << IOPORT_PFC_OFFSET), ///< P00_2 / ADCn / ADTRG0
    IOPORT_PIN_P002_PFC_24_SI00            = (0x24U << IOPORT_PFC_OFFSET), ///< P00_2 / ENDATn / SI00
    IOPORT_PIN_P002_PFC_25_HDSL00_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P00_2 / HDSLn / HDSL00_CLK1
    IOPORT_PIN_P003_PFC_00_IRQ2            = (0x00U << IOPORT_PFC_OFFSET), ///< P00_3 / IRQ / IRQ2
    IOPORT_PIN_P003_PFC_04_D3              = (0x04U << IOPORT_PFC_OFFSET), ///< P00_3 / BSC / D3
    IOPORT_PIN_P003_PFC_06_MTIOC4C         = (0x06U << IOPORT_PFC_OFFSET), ///< P00_3 / MTU3 / MTIOC4C
    IOPORT_PIN_P003_PFC_09_GTIOC00_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P00_3 / GPT / GTIOC00_1B
    IOPORT_PIN_P003_PFC_0F_ETH3_COL        = (0x0FU << IOPORT_PFC_OFFSET), ///< P00_3 / ETHER_ETHn / ETH3_COL
    IOPORT_PIN_P003_PFC_1F_ADTRG1          = (0x1FU << IOPORT_PFC_OFFSET), ///< P00_3 / ADCn / ADTRG1
    IOPORT_PIN_P003_PFC_24_DUEI01          = (0x24U << IOPORT_PFC_OFFSET), ///< P00_3 / ENDATn / DUEI01
    IOPORT_PIN_P003_PFC_25_HDSL00_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P00_3 / HDSLn / HDSL00_SEL1
    IOPORT_PIN_P004_PFC_00_IRQ3            = (0x00U << IOPORT_PFC_OFFSET), ///< P00_4 / IRQ / IRQ3
    IOPORT_PIN_P004_PFC_04_D4              = (0x04U << IOPORT_PFC_OFFSET), ///< P00_4 / BSC / D4
    IOPORT_PIN_P004_PFC_06_MTIOC4B         = (0x06U << IOPORT_PFC_OFFSET), ///< P00_4 / MTU3 / MTIOC4B
    IOPORT_PIN_P004_PFC_09_GTIOC00_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P00_4 / GPT / GTIOC00_2A
    IOPORT_PIN_P004_PFC_1F_ADTRG2          = (0x1FU << IOPORT_PFC_OFFSET), ///< P00_4 / ADCn / ADTRG2
    IOPORT_PIN_P004_PFC_24_TST_OUT01       = (0x24U << IOPORT_PFC_OFFSET), ///< P00_4 / ENDATn / TST_OUT01
    IOPORT_PIN_P004_PFC_25_HDSL00_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P00_4 / HDSLn / HDSL00_MISO1
    IOPORT_PIN_P005_PFC_06_MTIOC4D         = (0x06U << IOPORT_PFC_OFFSET), ///< P00_5 / MTU3 / MTIOC4D
    IOPORT_PIN_P005_PFC_07_MTIOC8C         = (0x07U << IOPORT_PFC_OFFSET), ///< P00_5 / MTU3 / MTIOC8C
    IOPORT_PIN_P005_PFC_09_GTIOC00_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P00_5 / GPT / GTIOC00_2B
    IOPORT_PIN_P005_PFC_13_USB_VBUSEN      = (0x13U << IOPORT_PFC_OFFSET), ///< P00_5 / USB / USB_VBUSEN
    IOPORT_PIN_P005_PFC_24_SI01            = (0x24U << IOPORT_PFC_OFFSET), ///< P00_5 / ENDATn / SI01
    IOPORT_PIN_P005_PFC_25_HDSL00_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P00_5 / HDSLn / HDSL00_MOSI1
    IOPORT_PIN_P006_PFC_00_IRQ4            = (0x00U << IOPORT_PFC_OFFSET), ///< P00_6 / IRQ / IRQ4
    IOPORT_PIN_P006_PFC_06_MTCLKA          = (0x06U << IOPORT_PFC_OFFSET), ///< P00_6 / MTU3 / MTCLKA
    IOPORT_PIN_P006_PFC_07_MTIOC8D         = (0x07U << IOPORT_PFC_OFFSET), ///< P00_6 / MTU3 / MTIOC8D
    IOPORT_PIN_P006_PFC_09_GTIOC00_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P00_6 / GPT / GTIOC00_3A
    IOPORT_PIN_P006_PFC_13_USB_OVRCUR      = (0x13U << IOPORT_PFC_OFFSET), ///< P00_6 / USB / USB_OVRCUR
    IOPORT_PIN_P006_PFC_15_SCKE00          = (0x15U << IOPORT_PFC_OFFSET), ///< P00_6 / SCIEn / SCKE00
    IOPORT_PIN_P006_PFC_16_SCKE04          = (0x16U << IOPORT_PFC_OFFSET), ///< P00_6 / SCIEn / SCKE04
    IOPORT_PIN_P006_PFC_17_IIC_SCL0        = (0x17U << IOPORT_PFC_OFFSET), ///< P00_6 / IICn / IIC_SCL0
    IOPORT_PIN_P006_PFC_22_ENCIFCK00       = (0x22U << IOPORT_PFC_OFFSET), ///< P00_6 / ENCIFn / ENCIFCK00
    IOPORT_PIN_P006_PFC_23_ENCIFCK04       = (0x23U << IOPORT_PFC_OFFSET), ///< P00_6 / ENCIFn / ENCIFCK04
    IOPORT_PIN_P006_PFC_25_HDSL00_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P00_6 / HDSLn / HDSL00_CLK2
    IOPORT_PIN_P007_PFC_00_IRQ5            = (0x00U << IOPORT_PFC_OFFSET), ///< P00_7 / IRQ / IRQ5
    IOPORT_PIN_P007_PFC_06_MTCLKB          = (0x06U << IOPORT_PFC_OFFSET), ///< P00_7 / MTU3 / MTCLKB
    IOPORT_PIN_P007_PFC_07_MTIOC1B         = (0x07U << IOPORT_PFC_OFFSET), ///< P00_7 / MTU3 / MTIOC1B
    IOPORT_PIN_P007_PFC_09_GTIOC00_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P00_7 / GPT / GTIOC00_3B
    IOPORT_PIN_P007_PFC_13_USB_EXICEN      = (0x13U << IOPORT_PFC_OFFSET), ///< P00_7 / USB / USB_EXICEN
    IOPORT_PIN_P007_PFC_15_DEE00           = (0x15U << IOPORT_PFC_OFFSET), ///< P00_7 / SCIEn / DEE00
    IOPORT_PIN_P007_PFC_16_DEE04           = (0x16U << IOPORT_PFC_OFFSET), ///< P00_7 / SCIEn / DEE04
    IOPORT_PIN_P007_PFC_17_IIC_SDA0        = (0x17U << IOPORT_PFC_OFFSET), ///< P00_7 / IICn / IIC_SDA0
    IOPORT_PIN_P007_PFC_22_ENCIFOE00       = (0x22U << IOPORT_PFC_OFFSET), ///< P00_7 / ENCIFn / ENCIFOE00
    IOPORT_PIN_P007_PFC_23_ENCIFOE04       = (0x23U << IOPORT_PFC_OFFSET), ///< P00_7 / ENCIFn / ENCIFOE04
    IOPORT_PIN_P007_PFC_25_HDSL00_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P00_7 / HDSLn / HDSL00_SEL2
    IOPORT_PIN_P010_PFC_00_IRQ6            = (0x00U << IOPORT_PFC_OFFSET), ///< P01_0 / IRQ / IRQ6
    IOPORT_PIN_P010_PFC_06_MTIOC3A         = (0x06U << IOPORT_PFC_OFFSET), ///< P01_0 / MTU3 / MTIOC3A
    IOPORT_PIN_P010_PFC_07_MTIOC1A         = (0x07U << IOPORT_PFC_OFFSET), ///< P01_0 / MTU3 / MTIOC1A
    IOPORT_PIN_P010_PFC_09_GTIOC00_4A      = (0x09U << IOPORT_PFC_OFFSET), ///< P01_0 / GPT / GTIOC00_4A
    IOPORT_PIN_P010_PFC_0A_GTIOC00_2B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P01_0 / GPT / GTIOC00_2B
    IOPORT_PIN_P010_PFC_15_TXDE00          = (0x15U << IOPORT_PFC_OFFSET), ///< P01_0 / SCIEn / TXDE00
    IOPORT_PIN_P010_PFC_16_TXDE04          = (0x16U << IOPORT_PFC_OFFSET), ///< P01_0 / SCIEn / TXDE04
    IOPORT_PIN_P010_PFC_17_IIC_SCL1        = (0x17U << IOPORT_PFC_OFFSET), ///< P01_0 / IICn / IIC_SCL1
    IOPORT_PIN_P010_PFC_1C_XSPI1_CKP       = (0x1CU << IOPORT_PFC_OFFSET), ///< P01_0 / xSPIn / XSPI1_CKP
    IOPORT_PIN_P010_PFC_22_ENCIFDO00       = (0x22U << IOPORT_PFC_OFFSET), ///< P01_0 / ENCIFn / ENCIFDO00
    IOPORT_PIN_P010_PFC_23_ENCIFDO04       = (0x23U << IOPORT_PFC_OFFSET), ///< P01_0 / ENCIFn / ENCIFDO04
    IOPORT_PIN_P010_PFC_25_HDSL00_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P01_0 / HDSLn / HDSL00_MISO2
    IOPORT_PIN_P011_PFC_06_MTIOC3C         = (0x06U << IOPORT_PFC_OFFSET), ///< P01_1 / MTU3 / MTIOC3C
    IOPORT_PIN_P011_PFC_07_MTIOC8A         = (0x07U << IOPORT_PFC_OFFSET), ///< P01_1 / MTU3 / MTIOC8A
    IOPORT_PIN_P011_PFC_09_GTIOC00_4B      = (0x09U << IOPORT_PFC_OFFSET), ///< P01_1 / GPT / GTIOC00_4B
    IOPORT_PIN_P011_PFC_15_RXDE00          = (0x15U << IOPORT_PFC_OFFSET), ///< P01_1 / SCIEn / RXDE00
    IOPORT_PIN_P011_PFC_16_RXDE04          = (0x16U << IOPORT_PFC_OFFSET), ///< P01_1 / SCIEn / RXDE04
    IOPORT_PIN_P011_PFC_1C_XSPI1_CS0       = (0x1CU << IOPORT_PFC_OFFSET), ///< P01_1 / xSPIn / XSPI1_CS0
    IOPORT_PIN_P011_PFC_1D_MCLK20          = (0x1DU << IOPORT_PFC_OFFSET), ///< P01_1 / DSMIFn / MCLK20
    IOPORT_PIN_P011_PFC_22_ENCIFDI00       = (0x22U << IOPORT_PFC_OFFSET), ///< P01_1 / ENCIFn / ENCIFDI00
    IOPORT_PIN_P011_PFC_23_ENCIFDI04       = (0x23U << IOPORT_PFC_OFFSET), ///< P01_1 / ENCIFn / ENCIFDI04
    IOPORT_PIN_P011_PFC_25_HDSL00_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P01_1 / HDSLn / HDSL00_MOSI2
    IOPORT_PIN_P012_PFC_06_MTIOC6B         = (0x06U << IOPORT_PFC_OFFSET), ///< P01_2 / MTU3 / MTIOC6B
    IOPORT_PIN_P012_PFC_07_MTIOC8B         = (0x07U << IOPORT_PFC_OFFSET), ///< P01_2 / MTU3 / MTIOC8B
    IOPORT_PIN_P012_PFC_09_GTIOC01_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P01_2 / GPT / GTIOC01_0A
    IOPORT_PIN_P012_PFC_0A_GTIOC04_0A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P01_2 / GPT / GTIOC04_0A
    IOPORT_PIN_P012_PFC_1C_XSPI1_CS1       = (0x1CU << IOPORT_PFC_OFFSET), ///< P01_2 / xSPIn / XSPI1_CS1
    IOPORT_PIN_P012_PFC_24_DUEI02          = (0x24U << IOPORT_PFC_OFFSET), ///< P01_2 / ENDATn / DUEI02
    IOPORT_PIN_P012_PFC_25_HDSL01_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P01_2 / HDSLn / HDSL01_LINK
    IOPORT_PIN_P013_PFC_06_MTIOC6D         = (0x06U << IOPORT_PFC_OFFSET), ///< P01_3 / MTU3 / MTIOC6D
    IOPORT_PIN_P013_PFC_07_MTIC5U          = (0x07U << IOPORT_PFC_OFFSET), ///< P01_3 / MTU3 / MTIC5U
    IOPORT_PIN_P013_PFC_09_GTIOC01_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P01_3 / GPT / GTIOC01_0B
    IOPORT_PIN_P013_PFC_0A_GTIOC04_0B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P01_3 / GPT / GTIOC04_0B
    IOPORT_PIN_P013_PFC_1C_XSPI1_DS        = (0x1CU << IOPORT_PFC_OFFSET), ///< P01_3 / xSPIn / XSPI1_DS
    IOPORT_PIN_P013_PFC_24_TST_OUT02       = (0x24U << IOPORT_PFC_OFFSET), ///< P01_3 / ENDATn / TST_OUT02
    IOPORT_PIN_P013_PFC_25_HDSL01_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P01_3 / HDSLn / HDSL01_SMPL
    IOPORT_PIN_P014_PFC_06_MTIOC7A         = (0x06U << IOPORT_PFC_OFFSET), ///< P01_4 / MTU3 / MTIOC7A
    IOPORT_PIN_P014_PFC_07_MTIC5V          = (0x07U << IOPORT_PFC_OFFSET), ///< P01_4 / MTU3 / MTIC5V
    IOPORT_PIN_P014_PFC_09_GTIOC01_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P01_4 / GPT / GTIOC01_1A
    IOPORT_PIN_P014_PFC_0A_GTIOC04_1A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P01_4 / GPT / GTIOC04_1A
    IOPORT_PIN_P014_PFC_1C_XSPI1_IO0       = (0x1CU << IOPORT_PFC_OFFSET), ///< P01_4 / xSPIn / XSPI1_IO0
    IOPORT_PIN_P014_PFC_24_SI02            = (0x24U << IOPORT_PFC_OFFSET), ///< P01_4 / ENDATn / SI02
    IOPORT_PIN_P014_PFC_25_HDSL01_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P01_4 / HDSLn / HDSL01_CLK1
    IOPORT_PIN_P015_PFC_06_MTIOC7C         = (0x06U << IOPORT_PFC_OFFSET), ///< P01_5 / MTU3 / MTIOC7C
    IOPORT_PIN_P015_PFC_07_MTIC5W          = (0x07U << IOPORT_PFC_OFFSET), ///< P01_5 / MTU3 / MTIC5W
    IOPORT_PIN_P015_PFC_09_GTIOC01_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P01_5 / GPT / GTIOC01_1B
    IOPORT_PIN_P015_PFC_0A_GTIOC04_1B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P01_5 / GPT / GTIOC04_1B
    IOPORT_PIN_P015_PFC_1C_XSPI1_IO1       = (0x1CU << IOPORT_PFC_OFFSET), ///< P01_5 / xSPIn / XSPI1_IO1
    IOPORT_PIN_P015_PFC_24_DUEI03          = (0x24U << IOPORT_PFC_OFFSET), ///< P01_5 / ENDATn / DUEI03
    IOPORT_PIN_P015_PFC_25_HDSL01_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P01_5 / HDSLn / HDSL01_SEL1
    IOPORT_PIN_P016_PFC_06_MTIOC7B         = (0x06U << IOPORT_PFC_OFFSET), ///< P01_6 / MTU3 / MTIOC7B
    IOPORT_PIN_P016_PFC_07_MTIOC0A         = (0x07U << IOPORT_PFC_OFFSET), ///< P01_6 / MTU3 / MTIOC0A
    IOPORT_PIN_P016_PFC_09_GTIOC01_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P01_6 / GPT / GTIOC01_2A
    IOPORT_PIN_P016_PFC_0A_GTIOC04_2A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P01_6 / GPT / GTIOC04_2A
    IOPORT_PIN_P016_PFC_1C_XSPI1_IO2       = (0x1CU << IOPORT_PFC_OFFSET), ///< P01_6 / xSPIn / XSPI1_IO2
    IOPORT_PIN_P016_PFC_24_TST_OUT03       = (0x24U << IOPORT_PFC_OFFSET), ///< P01_6 / ENDATn / TST_OUT03
    IOPORT_PIN_P016_PFC_25_HDSL01_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P01_6 / HDSLn / HDSL01_MISO1
    IOPORT_PIN_P017_PFC_06_MTIOC7D         = (0x06U << IOPORT_PFC_OFFSET), ///< P01_7 / MTU3 / MTIOC7D
    IOPORT_PIN_P017_PFC_07_MTIOC0B         = (0x07U << IOPORT_PFC_OFFSET), ///< P01_7 / MTU3 / MTIOC0B
    IOPORT_PIN_P017_PFC_09_GTIOC01_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P01_7 / GPT / GTIOC01_2B
    IOPORT_PIN_P017_PFC_0A_GTIOC04_2B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P01_7 / GPT / GTIOC04_2B
    IOPORT_PIN_P017_PFC_1C_XSPI1_IO3       = (0x1CU << IOPORT_PFC_OFFSET), ///< P01_7 / xSPIn / XSPI1_IO3
    IOPORT_PIN_P017_PFC_24_SI03            = (0x24U << IOPORT_PFC_OFFSET), ///< P01_7 / ENDATn / SI03
    IOPORT_PIN_P017_PFC_25_HDSL01_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P01_7 / HDSLn / HDSL01_MOSI1
    IOPORT_PIN_P020_PFC_00_IRQ7            = (0x00U << IOPORT_PFC_OFFSET), ///< P02_0 / IRQ / IRQ7
    IOPORT_PIN_P020_PFC_06_MTCLKC          = (0x06U << IOPORT_PFC_OFFSET), ///< P02_0 / MTU3 / MTCLKC
    IOPORT_PIN_P020_PFC_07_MTIOC0C         = (0x07U << IOPORT_PFC_OFFSET), ///< P02_0 / MTU3 / MTIOC0C
    IOPORT_PIN_P020_PFC_09_GTIOC01_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P02_0 / GPT / GTIOC01_3A
    IOPORT_PIN_P020_PFC_0F_ETH3_TXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P02_0 / ETHER_ETHn / ETH3_TXER
    IOPORT_PIN_P020_PFC_15_SCKE01          = (0x15U << IOPORT_PFC_OFFSET), ///< P02_0 / SCIEn / SCKE01
    IOPORT_PIN_P020_PFC_17_IIC_SDA1        = (0x17U << IOPORT_PFC_OFFSET), ///< P02_0 / IICn / IIC_SDA1
    IOPORT_PIN_P020_PFC_1C_XSPI1_IO4       = (0x1CU << IOPORT_PFC_OFFSET), ///< P02_0 / xSPIn / XSPI1_IO4
    IOPORT_PIN_P020_PFC_1D_MCLK21          = (0x1DU << IOPORT_PFC_OFFSET), ///< P02_0 / DSMIFn / MCLK21
    IOPORT_PIN_P020_PFC_22_ENCIFCK01       = (0x22U << IOPORT_PFC_OFFSET), ///< P02_0 / ENCIFn / ENCIFCK01
    IOPORT_PIN_P020_PFC_25_HDSL01_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P02_0 / HDSLn / HDSL01_CLK2
    IOPORT_PIN_P021_PFC_00_IRQ8            = (0x00U << IOPORT_PFC_OFFSET), ///< P02_1 / IRQ / IRQ8
    IOPORT_PIN_P021_PFC_06_MTCLKD          = (0x06U << IOPORT_PFC_OFFSET), ///< P02_1 / MTU3 / MTCLKD
    IOPORT_PIN_P021_PFC_07_MTIOC0D         = (0x07U << IOPORT_PFC_OFFSET), ///< P02_1 / MTU3 / MTIOC0D
    IOPORT_PIN_P021_PFC_09_GTIOC01_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P02_1 / GPT / GTIOC01_3B
    IOPORT_PIN_P021_PFC_0F_ETH3_RXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P02_1 / ETHER_ETHn / ETH3_RXER
    IOPORT_PIN_P021_PFC_15_DEE01           = (0x15U << IOPORT_PFC_OFFSET), ///< P02_1 / SCIEn / DEE01
    IOPORT_PIN_P021_PFC_17_IIC_SCL2        = (0x17U << IOPORT_PFC_OFFSET), ///< P02_1 / IICn / IIC_SCL2
    IOPORT_PIN_P021_PFC_1C_XSPI1_IO5       = (0x1CU << IOPORT_PFC_OFFSET), ///< P02_1 / xSPIn / XSPI1_IO5
    IOPORT_PIN_P021_PFC_1D_MDAT21          = (0x1DU << IOPORT_PFC_OFFSET), ///< P02_1 / DSMIFn / MDAT21
    IOPORT_PIN_P021_PFC_22_ENCIFOE01       = (0x22U << IOPORT_PFC_OFFSET), ///< P02_1 / ENCIFn / ENCIFOE01
    IOPORT_PIN_P021_PFC_25_HDSL01_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P02_1 / HDSLn / HDSL01_SEL2
    IOPORT_PIN_P022_PFC_00_IRQ9            = (0x00U << IOPORT_PFC_OFFSET), ///< P02_2 / IRQ / IRQ9
    IOPORT_PIN_P022_PFC_06_MTIOC6A         = (0x06U << IOPORT_PFC_OFFSET), ///< P02_2 / MTU3 / MTIOC6A
    IOPORT_PIN_P022_PFC_07_MTIOC1A         = (0x07U << IOPORT_PFC_OFFSET), ///< P02_2 / MTU3 / MTIOC1A
    IOPORT_PIN_P022_PFC_09_GTIOC01_4A      = (0x09U << IOPORT_PFC_OFFSET), ///< P02_2 / GPT / GTIOC01_4A
    IOPORT_PIN_P022_PFC_0F_ETH3_CRS        = (0x0FU << IOPORT_PFC_OFFSET), ///< P02_2 / ETHER_ETHn / ETH3_CRS
    IOPORT_PIN_P022_PFC_13_USB_VBUSEN      = (0x13U << IOPORT_PFC_OFFSET), ///< P02_2 / USB / USB_VBUSEN
    IOPORT_PIN_P022_PFC_15_TXDE01          = (0x15U << IOPORT_PFC_OFFSET), ///< P02_2 / SCIEn / TXDE01
    IOPORT_PIN_P022_PFC_17_IIC_SDA2        = (0x17U << IOPORT_PFC_OFFSET), ///< P02_2 / IICn / IIC_SDA2
    IOPORT_PIN_P022_PFC_1C_XSPI1_IO6       = (0x1CU << IOPORT_PFC_OFFSET), ///< P02_2 / xSPIn / XSPI1_IO6
    IOPORT_PIN_P022_PFC_1D_MCLK22          = (0x1DU << IOPORT_PFC_OFFSET), ///< P02_2 / DSMIFn / MCLK22
    IOPORT_PIN_P022_PFC_22_ENCIFDO01       = (0x22U << IOPORT_PFC_OFFSET), ///< P02_2 / ENCIFn / ENCIFDO01
    IOPORT_PIN_P022_PFC_25_HDSL01_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P02_2 / HDSLn / HDSL01_MISO2
    IOPORT_PIN_P023_PFC_00_IRQ10           = (0x00U << IOPORT_PFC_OFFSET), ///< P02_3 / IRQ / IRQ10
    IOPORT_PIN_P023_PFC_06_MTIOC6C         = (0x06U << IOPORT_PFC_OFFSET), ///< P02_3 / MTU3 / MTIOC6C
    IOPORT_PIN_P023_PFC_07_MTIOC1B         = (0x07U << IOPORT_PFC_OFFSET), ///< P02_3 / MTU3 / MTIOC1B
    IOPORT_PIN_P023_PFC_09_GTIOC01_4B      = (0x09U << IOPORT_PFC_OFFSET), ///< P02_3 / GPT / GTIOC01_4B
    IOPORT_PIN_P023_PFC_0F_ETH3_COL        = (0x0FU << IOPORT_PFC_OFFSET), ///< P02_3 / ETHER_ETHn / ETH3_COL
    IOPORT_PIN_P023_PFC_13_USB_OVRCUR      = (0x13U << IOPORT_PFC_OFFSET), ///< P02_3 / USB / USB_OVRCUR
    IOPORT_PIN_P023_PFC_15_RXDE01          = (0x15U << IOPORT_PFC_OFFSET), ///< P02_3 / SCIEn / RXDE01
    IOPORT_PIN_P023_PFC_17_IIC_SCL0        = (0x17U << IOPORT_PFC_OFFSET), ///< P02_3 / IICn / IIC_SCL0
    IOPORT_PIN_P023_PFC_18_IIC_SCL2        = (0x18U << IOPORT_PFC_OFFSET), ///< P02_3 / IICn / IIC_SCL2
    IOPORT_PIN_P023_PFC_1C_XSPI1_IO7       = (0x1CU << IOPORT_PFC_OFFSET), ///< P02_3 / xSPIn / XSPI1_IO7
    IOPORT_PIN_P023_PFC_1D_MDAT22          = (0x1DU << IOPORT_PFC_OFFSET), ///< P02_3 / DSMIFn / MDAT22
    IOPORT_PIN_P023_PFC_22_ENCIFDI01       = (0x22U << IOPORT_PFC_OFFSET), ///< P02_3 / ENCIFn / ENCIFDI01
    IOPORT_PIN_P023_PFC_25_HDSL01_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P02_3 / HDSLn / HDSL01_MOSI2
    IOPORT_PIN_P024_PFC_00_IRQ11           = (0x00U << IOPORT_PFC_OFFSET), ///< P02_4 / IRQ / IRQ11
    IOPORT_PIN_P024_PFC_08_POE0            = (0x08U << IOPORT_PFC_OFFSET), ///< P02_4 / POE3 / POE0
    IOPORT_PIN_P024_PFC_13_USB_EXICEN      = (0x13U << IOPORT_PFC_OFFSET), ///< P02_4 / USB / USB_EXICEN
    IOPORT_PIN_P024_PFC_17_IIC_SDA0        = (0x17U << IOPORT_PFC_OFFSET), ///< P02_4 / IICn / IIC_SDA0
    IOPORT_PIN_P024_PFC_1D_MDAT20          = (0x1DU << IOPORT_PFC_OFFSET), ///< P02_4 / DSMIFn / MDAT20
    IOPORT_PIN_P024_PFC_21_MBX_HINT        = (0x21U << IOPORT_PFC_OFFSET), ///< P02_4 / MBXSEM / MBX_HINT
    IOPORT_PIN_P024_PFC_25_HDSL02_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P02_4 / HDSLn / HDSL02_LINK
    IOPORT_PIN_P025_PFC_04_D5              = (0x04U << IOPORT_PFC_OFFSET), ///< P02_5 / BSC / D5
    IOPORT_PIN_P025_PFC_06_MTIOC3B         = (0x06U << IOPORT_PFC_OFFSET), ///< P02_5 / MTU3 / MTIOC3B
    IOPORT_PIN_P025_PFC_07_MTIOC8A         = (0x07U << IOPORT_PFC_OFFSET), ///< P02_5 / MTU3 / MTIOC8A
    IOPORT_PIN_P025_PFC_09_GTIOC02_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P02_5 / GPT / GTIOC02_0A
    IOPORT_PIN_P025_PFC_0A_GTADSM06_0      = (0x0AU << IOPORT_PFC_OFFSET), ///< P02_5 / GPT / GTADSM06_0
    IOPORT_PIN_P025_PFC_0D_CMTW0_TIC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P02_5 / CMTW / CMTW0_TIC0
    IOPORT_PIN_P025_PFC_17_IIC_SCL0        = (0x17U << IOPORT_PFC_OFFSET), ///< P02_5 / IICn / IIC_SCL0
    IOPORT_PIN_P025_PFC_1D_MCLK00          = (0x1DU << IOPORT_PFC_OFFSET), ///< P02_5 / DSMIFn / MCLK00
    IOPORT_PIN_P025_PFC_25_HDSL02_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P02_5 / HDSLn / HDSL02_SMPL
    IOPORT_PIN_P025_PFC_26_POUTA           = (0x26U << IOPORT_PFC_OFFSET), ///< P02_5 / ENCOUT / POUTA
    IOPORT_PIN_P025_PFC_29_SD0_PWEN        = (0x29U << IOPORT_PFC_OFFSET), ///< P02_5 / SDHI / SD0_PWEN
    IOPORT_PIN_P026_PFC_04_D6              = (0x04U << IOPORT_PFC_OFFSET), ///< P02_6 / BSC / D6
    IOPORT_PIN_P026_PFC_06_MTIOC3D         = (0x06U << IOPORT_PFC_OFFSET), ///< P02_6 / MTU3 / MTIOC3D
    IOPORT_PIN_P026_PFC_07_MTIOC8B         = (0x07U << IOPORT_PFC_OFFSET), ///< P02_6 / MTU3 / MTIOC8B
    IOPORT_PIN_P026_PFC_09_GTIOC02_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P02_6 / GPT / GTIOC02_0B
    IOPORT_PIN_P026_PFC_0A_GTADSM06_1      = (0x0AU << IOPORT_PFC_OFFSET), ///< P02_6 / GPT / GTADSM06_1
    IOPORT_PIN_P026_PFC_0D_CMTW0_TOC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P02_6 / CMTW / CMTW0_TOC0
    IOPORT_PIN_P026_PFC_1D_MDAT00          = (0x1DU << IOPORT_PFC_OFFSET), ///< P02_6 / DSMIFn / MDAT00
    IOPORT_PIN_P026_PFC_25_HDSL02_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P02_6 / HDSLn / HDSL02_CLK1
    IOPORT_PIN_P026_PFC_26_POUTB           = (0x26U << IOPORT_PFC_OFFSET), ///< P02_6 / ENCOUT / POUTB
    IOPORT_PIN_P026_PFC_29_SD0_IOVS        = (0x29U << IOPORT_PFC_OFFSET), ///< P02_6 / SDHI / SD0_IOVS
    IOPORT_PIN_P027_PFC_04_D7              = (0x04U << IOPORT_PFC_OFFSET), ///< P02_7 / BSC / D7
    IOPORT_PIN_P027_PFC_06_MTIOC4A         = (0x06U << IOPORT_PFC_OFFSET), ///< P02_7 / MTU3 / MTIOC4A
    IOPORT_PIN_P027_PFC_07_MTIC5U          = (0x07U << IOPORT_PFC_OFFSET), ///< P02_7 / MTU3 / MTIC5U
    IOPORT_PIN_P027_PFC_09_GTIOC02_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P02_7 / GPT / GTIOC02_1A
    IOPORT_PIN_P027_PFC_0A_GTADSM07_0      = (0x0AU << IOPORT_PFC_OFFSET), ///< P02_7 / GPT / GTADSM07_0
    IOPORT_PIN_P027_PFC_0D_CMTW0_TIC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P02_7 / CMTW / CMTW0_TIC1
    IOPORT_PIN_P027_PFC_1D_MCLK01          = (0x1DU << IOPORT_PFC_OFFSET), ///< P02_7 / DSMIFn / MCLK01
    IOPORT_PIN_P027_PFC_25_HDSL02_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P02_7 / HDSLn / HDSL02_SEL1
    IOPORT_PIN_P027_PFC_26_POUTZ           = (0x26U << IOPORT_PFC_OFFSET), ///< P02_7 / ENCOUT / POUTZ
    IOPORT_PIN_P030_PFC_04_D8              = (0x04U << IOPORT_PFC_OFFSET), ///< P03_0 / BSC / D8
    IOPORT_PIN_P030_PFC_06_MTIOC4C         = (0x06U << IOPORT_PFC_OFFSET), ///< P03_0 / MTU3 / MTIOC4C
    IOPORT_PIN_P030_PFC_07_MTIC5V          = (0x07U << IOPORT_PFC_OFFSET), ///< P03_0 / MTU3 / MTIC5V
    IOPORT_PIN_P030_PFC_09_GTIOC02_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P03_0 / GPT / GTIOC02_1B
    IOPORT_PIN_P030_PFC_0A_GTADSM07_1      = (0x0AU << IOPORT_PFC_OFFSET), ///< P03_0 / GPT / GTADSM07_1
    IOPORT_PIN_P030_PFC_0D_CMTW0_TOC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P03_0 / CMTW / CMTW0_TOC1
    IOPORT_PIN_P030_PFC_1D_MDAT01          = (0x1DU << IOPORT_PFC_OFFSET), ///< P03_0 / DSMIFn / MDAT01
    IOPORT_PIN_P030_PFC_25_HDSL02_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P03_0 / HDSLn / HDSL02_MISO1
    IOPORT_PIN_P031_PFC_04_D9              = (0x04U << IOPORT_PFC_OFFSET), ///< P03_1 / BSC / D9
    IOPORT_PIN_P031_PFC_06_MTIOC4B         = (0x06U << IOPORT_PFC_OFFSET), ///< P03_1 / MTU3 / MTIOC4B
    IOPORT_PIN_P031_PFC_07_MTIOC1B         = (0x07U << IOPORT_PFC_OFFSET), ///< P03_1 / MTU3 / MTIOC1B
    IOPORT_PIN_P031_PFC_09_GTIOC02_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P03_1 / GPT / GTIOC02_2A
    IOPORT_PIN_P031_PFC_0A_GTADSM08_0      = (0x0AU << IOPORT_PFC_OFFSET), ///< P03_1 / GPT / GTADSM08_0
    IOPORT_PIN_P031_PFC_0D_CMTW1_TIC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P03_1 / CMTW / CMTW1_TIC0
    IOPORT_PIN_P031_PFC_15_TXDE02          = (0x15U << IOPORT_PFC_OFFSET), ///< P03_1 / SCIEn / TXDE02
    IOPORT_PIN_P031_PFC_22_ENCIFDO02       = (0x22U << IOPORT_PFC_OFFSET), ///< P03_1 / ENCIFn / ENCIFDO02
    IOPORT_PIN_P031_PFC_25_HDSL02_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P03_1 / HDSLn / HDSL02_MOSI1
    IOPORT_PIN_P032_PFC_00_IRQ12           = (0x00U << IOPORT_PFC_OFFSET), ///< P03_2 / IRQ / IRQ12
    IOPORT_PIN_P032_PFC_04_D10             = (0x04U << IOPORT_PFC_OFFSET), ///< P03_2 / BSC / D10
    IOPORT_PIN_P032_PFC_06_MTIOC4D         = (0x06U << IOPORT_PFC_OFFSET), ///< P03_2 / MTU3 / MTIOC4D
    IOPORT_PIN_P032_PFC_07_MTIOC1A         = (0x07U << IOPORT_PFC_OFFSET), ///< P03_2 / MTU3 / MTIOC1A
    IOPORT_PIN_P032_PFC_09_GTIOC02_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P03_2 / GPT / GTIOC02_2B
    IOPORT_PIN_P032_PFC_0A_GTADSM08_1      = (0x0AU << IOPORT_PFC_OFFSET), ///< P03_2 / GPT / GTADSM08_1
    IOPORT_PIN_P032_PFC_0D_CMTW1_TOC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P03_2 / CMTW / CMTW1_TOC0
    IOPORT_PIN_P032_PFC_15_RXDE02          = (0x15U << IOPORT_PFC_OFFSET), ///< P03_2 / SCIEn / RXDE02
    IOPORT_PIN_P032_PFC_22_ENCIFDI02       = (0x22U << IOPORT_PFC_OFFSET), ///< P03_2 / ENCIFn / ENCIFDI02
    IOPORT_PIN_P032_PFC_25_HDSL02_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P03_2 / HDSLn / HDSL02_CLK2
    IOPORT_PIN_P033_PFC_00_IRQ13           = (0x00U << IOPORT_PFC_OFFSET), ///< P03_3 / IRQ / IRQ13
    IOPORT_PIN_P033_PFC_04_D11             = (0x04U << IOPORT_PFC_OFFSET), ///< P03_3 / BSC / D11
    IOPORT_PIN_P033_PFC_06_MTCLKA          = (0x06U << IOPORT_PFC_OFFSET), ///< P03_3 / MTU3 / MTCLKA
    IOPORT_PIN_P033_PFC_07_MTIOC8C         = (0x07U << IOPORT_PFC_OFFSET), ///< P03_3 / MTU3 / MTIOC8C
    IOPORT_PIN_P033_PFC_09_GTIOC02_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P03_3 / GPT / GTIOC02_3A
    IOPORT_PIN_P033_PFC_0A_GTADSM09_0      = (0x0AU << IOPORT_PFC_OFFSET), ///< P03_3 / GPT / GTADSM09_0
    IOPORT_PIN_P033_PFC_0D_CMTW1_TIC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P03_3 / CMTW / CMTW1_TIC1
    IOPORT_PIN_P033_PFC_15_SCKE02          = (0x15U << IOPORT_PFC_OFFSET), ///< P03_3 / SCIEn / SCKE02
    IOPORT_PIN_P033_PFC_17_IIC_SCL1        = (0x17U << IOPORT_PFC_OFFSET), ///< P03_3 / IICn / IIC_SCL1
    IOPORT_PIN_P033_PFC_22_ENCIFCK02       = (0x22U << IOPORT_PFC_OFFSET), ///< P03_3 / ENCIFn / ENCIFCK02
    IOPORT_PIN_P033_PFC_25_HDSL02_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P03_3 / HDSLn / HDSL02_SEL2
    IOPORT_PIN_P034_PFC_00_IRQ14           = (0x00U << IOPORT_PFC_OFFSET), ///< P03_4 / IRQ / IRQ14
    IOPORT_PIN_P034_PFC_04_D12             = (0x04U << IOPORT_PFC_OFFSET), ///< P03_4 / BSC / D12
    IOPORT_PIN_P034_PFC_06_MTCLKB          = (0x06U << IOPORT_PFC_OFFSET), ///< P03_4 / MTU3 / MTCLKB
    IOPORT_PIN_P034_PFC_07_MTIOC8D         = (0x07U << IOPORT_PFC_OFFSET), ///< P03_4 / MTU3 / MTIOC8D
    IOPORT_PIN_P034_PFC_09_GTIOC02_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P03_4 / GPT / GTIOC02_3B
    IOPORT_PIN_P034_PFC_0A_GTADSM09_1      = (0x0AU << IOPORT_PFC_OFFSET), ///< P03_4 / GPT / GTADSM09_1
    IOPORT_PIN_P034_PFC_0D_CMTW1_TOC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P03_4 / CMTW / CMTW1_TOC1
    IOPORT_PIN_P034_PFC_0E_RTCAT1HZ        = (0x0EU << IOPORT_PFC_OFFSET), ///< P03_4 / RTC / RTCAT1HZ
    IOPORT_PIN_P034_PFC_15_DEE02           = (0x15U << IOPORT_PFC_OFFSET), ///< P03_4 / SCIEn / DEE02
    IOPORT_PIN_P034_PFC_17_IIC_SDA1        = (0x17U << IOPORT_PFC_OFFSET), ///< P03_4 / IICn / IIC_SDA1
    IOPORT_PIN_P034_PFC_22_ENCIFOE02       = (0x22U << IOPORT_PFC_OFFSET), ///< P03_4 / ENCIFn / ENCIFOE02
    IOPORT_PIN_P034_PFC_25_HDSL02_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P03_4 / HDSLn / HDSL02_MISO2
    IOPORT_PIN_P035_PFC_00_IRQ15           = (0x00U << IOPORT_PFC_OFFSET), ///< P03_5 / IRQ / IRQ15
    IOPORT_PIN_P035_PFC_06_MTIOC3A         = (0x06U << IOPORT_PFC_OFFSET), ///< P03_5 / MTU3 / MTIOC3A
    IOPORT_PIN_P035_PFC_07_MTIC5W          = (0x07U << IOPORT_PFC_OFFSET), ///< P03_5 / MTU3 / MTIC5W
    IOPORT_PIN_P035_PFC_09_GTIOC02_4A      = (0x09U << IOPORT_PFC_OFFSET), ///< P03_5 / GPT / GTIOC02_4A
    IOPORT_PIN_P035_PFC_15_TXDE02          = (0x15U << IOPORT_PFC_OFFSET), ///< P03_5 / SCIEn / TXDE02
    IOPORT_PIN_P035_PFC_17_IIC_SCL2        = (0x17U << IOPORT_PFC_OFFSET), ///< P03_5 / IICn / IIC_SCL2
    IOPORT_PIN_P035_PFC_22_ENCIFDO02       = (0x22U << IOPORT_PFC_OFFSET), ///< P03_5 / ENCIFn / ENCIFDO02
    IOPORT_PIN_P035_PFC_25_HDSL02_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P03_5 / HDSLn / HDSL02_MOSI2
    IOPORT_PIN_P036_PFC_06_MTIOC3C         = (0x06U << IOPORT_PFC_OFFSET), ///< P03_6 / MTU3 / MTIOC3C
    IOPORT_PIN_P036_PFC_07_MTIOC1A         = (0x07U << IOPORT_PFC_OFFSET), ///< P03_6 / MTU3 / MTIOC1A
    IOPORT_PIN_P036_PFC_09_GTIOC02_4B      = (0x09U << IOPORT_PFC_OFFSET), ///< P03_6 / GPT / GTIOC02_4B
    IOPORT_PIN_P036_PFC_15_RXDE02          = (0x15U << IOPORT_PFC_OFFSET), ///< P03_6 / SCIEn / RXDE02
    IOPORT_PIN_P036_PFC_17_IIC_SDA2        = (0x17U << IOPORT_PFC_OFFSET), ///< P03_6 / IICn / IIC_SDA2
    IOPORT_PIN_P036_PFC_22_ENCIFDI02       = (0x22U << IOPORT_PFC_OFFSET), ///< P03_6 / ENCIFn / ENCIFDI02
    IOPORT_PIN_P036_PFC_25_HDSL03_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P03_6 / HDSLn / HDSL03_LINK
    IOPORT_PIN_P037_PFC_06_MTIOC6B         = (0x06U << IOPORT_PFC_OFFSET), ///< P03_7 / MTU3 / MTIOC6B
    IOPORT_PIN_P037_PFC_07_MTIOC1B         = (0x07U << IOPORT_PFC_OFFSET), ///< P03_7 / MTU3 / MTIOC1B
    IOPORT_PIN_P037_PFC_09_GTIOC03_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P03_7 / GPT / GTIOC03_0A
    IOPORT_PIN_P037_PFC_0D_CMTW0_TIC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P03_7 / CMTW / CMTW0_TIC0
    IOPORT_PIN_P037_PFC_24_DUEI04          = (0x24U << IOPORT_PFC_OFFSET), ///< P03_7 / ENDATn / DUEI04
    IOPORT_PIN_P037_PFC_25_HDSL03_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P03_7 / HDSLn / HDSL03_SMPL
    IOPORT_PIN_P040_PFC_06_MTIOC6D         = (0x06U << IOPORT_PFC_OFFSET), ///< P04_0 / MTU3 / MTIOC6D
    IOPORT_PIN_P040_PFC_09_GTIOC03_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P04_0 / GPT / GTIOC03_0B
    IOPORT_PIN_P040_PFC_0D_CMTW0_TOC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P04_0 / CMTW / CMTW0_TOC0
    IOPORT_PIN_P040_PFC_24_TST_OUT04       = (0x24U << IOPORT_PFC_OFFSET), ///< P04_0 / ENDATn / TST_OUT04
    IOPORT_PIN_P040_PFC_25_HDSL03_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P04_0 / HDSLn / HDSL03_CLK1
    IOPORT_PIN_P041_PFC_06_MTIOC7A         = (0x06U << IOPORT_PFC_OFFSET), ///< P04_1 / MTU3 / MTIOC7A
    IOPORT_PIN_P041_PFC_09_GTIOC03_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P04_1 / GPT / GTIOC03_1A
    IOPORT_PIN_P041_PFC_0D_CMTW0_TIC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P04_1 / CMTW / CMTW0_TIC1
    IOPORT_PIN_P041_PFC_24_SI04            = (0x24U << IOPORT_PFC_OFFSET), ///< P04_1 / ENDATn / SI04
    IOPORT_PIN_P041_PFC_25_HDSL03_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P04_1 / HDSLn / HDSL03_SEL1
    IOPORT_PIN_P042_PFC_06_MTIOC7C         = (0x06U << IOPORT_PFC_OFFSET), ///< P04_2 / MTU3 / MTIOC7C
    IOPORT_PIN_P042_PFC_09_GTIOC03_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P04_2 / GPT / GTIOC03_1B
    IOPORT_PIN_P042_PFC_0D_CMTW0_TOC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P04_2 / CMTW / CMTW0_TOC1
    IOPORT_PIN_P042_PFC_24_DUEI05          = (0x24U << IOPORT_PFC_OFFSET), ///< P04_2 / ENDATn / DUEI05
    IOPORT_PIN_P042_PFC_25_HDSL03_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P04_2 / HDSLn / HDSL03_MISO1
    IOPORT_PIN_P043_PFC_06_MTIOC7B         = (0x06U << IOPORT_PFC_OFFSET), ///< P04_3 / MTU3 / MTIOC7B
    IOPORT_PIN_P043_PFC_09_GTIOC03_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P04_3 / GPT / GTIOC03_2A
    IOPORT_PIN_P043_PFC_0D_CMTW1_TIC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P04_3 / CMTW / CMTW1_TIC0
    IOPORT_PIN_P043_PFC_24_TST_OUT05       = (0x24U << IOPORT_PFC_OFFSET), ///< P04_3 / ENDATn / TST_OUT05
    IOPORT_PIN_P043_PFC_25_HDSL03_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P04_3 / HDSLn / HDSL03_MOSI1
    IOPORT_PIN_P044_PFC_06_MTIOC7D         = (0x06U << IOPORT_PFC_OFFSET), ///< P04_4 / MTU3 / MTIOC7D
    IOPORT_PIN_P044_PFC_09_GTIOC03_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P04_4 / GPT / GTIOC03_2B
    IOPORT_PIN_P044_PFC_0D_CMTW1_TOC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P04_4 / CMTW / CMTW1_TOC0
    IOPORT_PIN_P044_PFC_1F_ADTRG0          = (0x1FU << IOPORT_PFC_OFFSET), ///< P04_4 / ADCn / ADTRG0
    IOPORT_PIN_P044_PFC_24_SI05            = (0x24U << IOPORT_PFC_OFFSET), ///< P04_4 / ENDATn / SI05
    IOPORT_PIN_P044_PFC_25_HDSL03_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P04_4 / HDSLn / HDSL03_CLK2
    IOPORT_PIN_P045_PFC_00_SEI             = (0x00U << IOPORT_PFC_OFFSET), ///< P04_5 / IRQ / SEI
    IOPORT_PIN_P045_PFC_06_MTCLKC          = (0x06U << IOPORT_PFC_OFFSET), ///< P04_5 / MTU3 / MTCLKC
    IOPORT_PIN_P045_PFC_07_MTIOC0C         = (0x07U << IOPORT_PFC_OFFSET), ///< P04_5 / MTU3 / MTIOC0C
    IOPORT_PIN_P045_PFC_09_GTIOC03_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P04_5 / GPT / GTIOC03_3A
    IOPORT_PIN_P045_PFC_0D_CMTW1_TIC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P04_5 / CMTW / CMTW1_TIC1
    IOPORT_PIN_P045_PFC_15_SCKE03          = (0x15U << IOPORT_PFC_OFFSET), ///< P04_5 / SCIEn / SCKE03
    IOPORT_PIN_P045_PFC_17_IIC_SCL0        = (0x17U << IOPORT_PFC_OFFSET), ///< P04_5 / IICn / IIC_SCL0
    IOPORT_PIN_P045_PFC_1F_ADTRG1          = (0x1FU << IOPORT_PFC_OFFSET), ///< P04_5 / ADCn / ADTRG1
    IOPORT_PIN_P045_PFC_22_ENCIFCK03       = (0x22U << IOPORT_PFC_OFFSET), ///< P04_5 / ENCIFn / ENCIFCK03
    IOPORT_PIN_P045_PFC_25_HDSL03_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P04_5 / HDSLn / HDSL03_SEL2
    IOPORT_PIN_P046_PFC_00_IRQ0            = (0x00U << IOPORT_PFC_OFFSET), ///< P04_6 / IRQ / IRQ0
    IOPORT_PIN_P046_PFC_06_MTCLKD          = (0x06U << IOPORT_PFC_OFFSET), ///< P04_6 / MTU3 / MTCLKD
    IOPORT_PIN_P046_PFC_07_MTIOC0D         = (0x07U << IOPORT_PFC_OFFSET), ///< P04_6 / MTU3 / MTIOC0D
    IOPORT_PIN_P046_PFC_09_GTIOC03_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P04_6 / GPT / GTIOC03_3B
    IOPORT_PIN_P046_PFC_0D_CMTW1_TOC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P04_6 / CMTW / CMTW1_TOC1
    IOPORT_PIN_P046_PFC_15_DEE03           = (0x15U << IOPORT_PFC_OFFSET), ///< P04_6 / SCIEn / DEE03
    IOPORT_PIN_P046_PFC_17_IIC_SDA0        = (0x17U << IOPORT_PFC_OFFSET), ///< P04_6 / IICn / IIC_SDA0
    IOPORT_PIN_P046_PFC_1F_ADTRG2          = (0x1FU << IOPORT_PFC_OFFSET), ///< P04_6 / ADCn / ADTRG2
    IOPORT_PIN_P046_PFC_21_MBX_HINT        = (0x21U << IOPORT_PFC_OFFSET), ///< P04_6 / MBXSEM / MBX_HINT
    IOPORT_PIN_P046_PFC_22_ENCIFOE03       = (0x22U << IOPORT_PFC_OFFSET), ///< P04_6 / ENCIFn / ENCIFOE03
    IOPORT_PIN_P046_PFC_25_HDSL03_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P04_6 / HDSLn / HDSL03_MISO2
    IOPORT_PIN_P047_PFC_00_IRQ1            = (0x00U << IOPORT_PFC_OFFSET), ///< P04_7 / IRQ / IRQ1
    IOPORT_PIN_P047_PFC_06_MTIOC6A         = (0x06U << IOPORT_PFC_OFFSET), ///< P04_7 / MTU3 / MTIOC6A
    IOPORT_PIN_P047_PFC_07_MTIOC0A         = (0x07U << IOPORT_PFC_OFFSET), ///< P04_7 / MTU3 / MTIOC0A
    IOPORT_PIN_P047_PFC_09_GTIOC03_4A      = (0x09U << IOPORT_PFC_OFFSET), ///< P04_7 / GPT / GTIOC03_4A
    IOPORT_PIN_P047_PFC_15_TXDE03          = (0x15U << IOPORT_PFC_OFFSET), ///< P04_7 / SCIEn / TXDE03
    IOPORT_PIN_P047_PFC_17_IIC_SCL1        = (0x17U << IOPORT_PFC_OFFSET), ///< P04_7 / IICn / IIC_SCL1
    IOPORT_PIN_P047_PFC_22_ENCIFDO03       = (0x22U << IOPORT_PFC_OFFSET), ///< P04_7 / ENCIFn / ENCIFDO03
    IOPORT_PIN_P047_PFC_25_HDSL03_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P04_7 / HDSLn / HDSL03_MOSI2
    IOPORT_PIN_P050_PFC_00_IRQ2            = (0x00U << IOPORT_PFC_OFFSET), ///< P05_0 / IRQ / IRQ2
    IOPORT_PIN_P050_PFC_06_MTIOC6C         = (0x06U << IOPORT_PFC_OFFSET), ///< P05_0 / MTU3 / MTIOC6C
    IOPORT_PIN_P050_PFC_07_MTIOC0B         = (0x07U << IOPORT_PFC_OFFSET), ///< P05_0 / MTU3 / MTIOC0B
    IOPORT_PIN_P050_PFC_09_GTIOC03_4B      = (0x09U << IOPORT_PFC_OFFSET), ///< P05_0 / GPT / GTIOC03_4B
    IOPORT_PIN_P050_PFC_15_RXDE03          = (0x15U << IOPORT_PFC_OFFSET), ///< P05_0 / SCIEn / RXDE03
    IOPORT_PIN_P050_PFC_17_IIC_SDA1        = (0x17U << IOPORT_PFC_OFFSET), ///< P05_0 / IICn / IIC_SDA1
    IOPORT_PIN_P050_PFC_22_ENCIFDI03       = (0x22U << IOPORT_PFC_OFFSET), ///< P05_0 / ENCIFn / ENCIFDI03
    IOPORT_PIN_P050_PFC_25_HDSL04_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P05_0 / HDSLn / HDSL04_LINK
    IOPORT_PIN_P051_PFC_00_IRQ3            = (0x00U << IOPORT_PFC_OFFSET), ///< P05_1 / IRQ / IRQ3
    IOPORT_PIN_P051_PFC_1C_XSPI0_CKP       = (0x1CU << IOPORT_PFC_OFFSET), ///< P05_1 / xSPIn / XSPI0_CKP
    IOPORT_PIN_P051_PFC_24_DUEI06          = (0x24U << IOPORT_PFC_OFFSET), ///< P05_1 / ENDATn / DUEI06
    IOPORT_PIN_P051_PFC_25_HDSL04_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P05_1 / HDSLn / HDSL04_SMPL
    IOPORT_PIN_P052_PFC_00_IRQ4            = (0x00U << IOPORT_PFC_OFFSET), ///< P05_2 / IRQ / IRQ4
    IOPORT_PIN_P052_PFC_17_IIC_SCL2        = (0x17U << IOPORT_PFC_OFFSET), ///< P05_2 / IICn / IIC_SCL2
    IOPORT_PIN_P052_PFC_1C_XSPI0_CKN       = (0x1CU << IOPORT_PFC_OFFSET), ///< P05_2 / xSPIn / XSPI0_CKN
    IOPORT_PIN_P052_PFC_24_TST_OUT06       = (0x24U << IOPORT_PFC_OFFSET), ///< P05_2 / ENDATn / TST_OUT06
    IOPORT_PIN_P052_PFC_25_HDSL04_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P05_2 / HDSLn / HDSL04_CLK1
    IOPORT_PIN_P053_PFC_00_IRQ5            = (0x00U << IOPORT_PFC_OFFSET), ///< P05_3 / IRQ / IRQ5
    IOPORT_PIN_P053_PFC_1C_XSPI0_CS0       = (0x1CU << IOPORT_PFC_OFFSET), ///< P05_3 / xSPIn / XSPI0_CS0
    IOPORT_PIN_P053_PFC_24_SI06            = (0x24U << IOPORT_PFC_OFFSET), ///< P05_3 / ENDATn / SI06
    IOPORT_PIN_P053_PFC_25_HDSL04_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P05_3 / HDSLn / HDSL04_SEL1
    IOPORT_PIN_P054_PFC_00_IRQ6            = (0x00U << IOPORT_PFC_OFFSET), ///< P05_4 / IRQ / IRQ6
    IOPORT_PIN_P054_PFC_17_IIC_SDA2        = (0x17U << IOPORT_PFC_OFFSET), ///< P05_4 / IICn / IIC_SDA2
    IOPORT_PIN_P054_PFC_1C_XSPI0_CS1       = (0x1CU << IOPORT_PFC_OFFSET), ///< P05_4 / xSPIn / XSPI0_CS1
    IOPORT_PIN_P054_PFC_24_DUEI07          = (0x24U << IOPORT_PFC_OFFSET), ///< P05_4 / ENDATn / DUEI07
    IOPORT_PIN_P054_PFC_25_HDSL04_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P05_4 / HDSLn / HDSL04_MISO1
    IOPORT_PIN_P055_PFC_1C_XSPI0_DS        = (0x1CU << IOPORT_PFC_OFFSET), ///< P05_5 / xSPIn / XSPI0_DS
    IOPORT_PIN_P055_PFC_24_TST_OUT07       = (0x24U << IOPORT_PFC_OFFSET), ///< P05_5 / ENDATn / TST_OUT07
    IOPORT_PIN_P055_PFC_25_HDSL04_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P05_5 / HDSLn / HDSL04_MOSI1
    IOPORT_PIN_P056_PFC_1C_XSPI0_IO0       = (0x1CU << IOPORT_PFC_OFFSET), ///< P05_6 / xSPIn / XSPI0_IO0
    IOPORT_PIN_P056_PFC_24_SI07            = (0x24U << IOPORT_PFC_OFFSET), ///< P05_6 / ENDATn / SI07
    IOPORT_PIN_P056_PFC_25_HDSL04_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P05_6 / HDSLn / HDSL04_CLK2
    IOPORT_PIN_P057_PFC_1C_XSPI0_IO1       = (0x1CU << IOPORT_PFC_OFFSET), ///< P05_7 / xSPIn / XSPI0_IO1
    IOPORT_PIN_P057_PFC_24_DUEI08          = (0x24U << IOPORT_PFC_OFFSET), ///< P05_7 / ENDATn / DUEI08
    IOPORT_PIN_P057_PFC_25_HDSL04_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P05_7 / HDSLn / HDSL04_SEL2
    IOPORT_PIN_P060_PFC_1C_XSPI0_IO2       = (0x1CU << IOPORT_PFC_OFFSET), ///< P06_0 / xSPIn / XSPI0_IO2
    IOPORT_PIN_P060_PFC_24_TST_OUT08       = (0x24U << IOPORT_PFC_OFFSET), ///< P06_0 / ENDATn / TST_OUT08
    IOPORT_PIN_P060_PFC_25_HDSL04_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P06_0 / HDSLn / HDSL04_MISO2
    IOPORT_PIN_P061_PFC_1C_XSPI0_IO3       = (0x1CU << IOPORT_PFC_OFFSET), ///< P06_1 / xSPIn / XSPI0_IO3
    IOPORT_PIN_P061_PFC_24_SI08            = (0x24U << IOPORT_PFC_OFFSET), ///< P06_1 / ENDATn / SI08
    IOPORT_PIN_P061_PFC_25_HDSL04_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P06_1 / HDSLn / HDSL04_MOSI2
    IOPORT_PIN_P062_PFC_00_IRQ8            = (0x00U << IOPORT_PFC_OFFSET), ///< P06_2 / IRQ / IRQ8
    IOPORT_PIN_P062_PFC_17_IIC_SCL0        = (0x17U << IOPORT_PFC_OFFSET), ///< P06_2 / IICn / IIC_SCL0
    IOPORT_PIN_P062_PFC_1C_XSPI0_IO4       = (0x1CU << IOPORT_PFC_OFFSET), ///< P06_2 / xSPIn / XSPI0_IO4
    IOPORT_PIN_P062_PFC_24_DUEI09          = (0x24U << IOPORT_PFC_OFFSET), ///< P06_2 / ENDATn / DUEI09
    IOPORT_PIN_P062_PFC_25_HDSL05_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P06_2 / HDSLn / HDSL05_LINK
    IOPORT_PIN_P063_PFC_00_IRQ9            = (0x00U << IOPORT_PFC_OFFSET), ///< P06_3 / IRQ / IRQ9
    IOPORT_PIN_P063_PFC_0C_GTETRGA         = (0x0CU << IOPORT_PFC_OFFSET), ///< P06_3 / POEG / GTETRGA
    IOPORT_PIN_P063_PFC_17_IIC_SDA0        = (0x17U << IOPORT_PFC_OFFSET), ///< P06_3 / IICn / IIC_SDA0
    IOPORT_PIN_P063_PFC_1C_XSPI0_IO5       = (0x1CU << IOPORT_PFC_OFFSET), ///< P06_3 / xSPIn / XSPI0_IO5
    IOPORT_PIN_P063_PFC_24_TST_OUT09       = (0x24U << IOPORT_PFC_OFFSET), ///< P06_3 / ENDATn / TST_OUT09
    IOPORT_PIN_P063_PFC_25_HDSL05_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P06_3 / HDSLn / HDSL05_SMPL
    IOPORT_PIN_P064_PFC_00_IRQ10           = (0x00U << IOPORT_PFC_OFFSET), ///< P06_4 / IRQ / IRQ10
    IOPORT_PIN_P064_PFC_0C_GTETRGB         = (0x0CU << IOPORT_PFC_OFFSET), ///< P06_4 / POEG / GTETRGB
    IOPORT_PIN_P064_PFC_17_IIC_SCL1        = (0x17U << IOPORT_PFC_OFFSET), ///< P06_4 / IICn / IIC_SCL1
    IOPORT_PIN_P064_PFC_1C_XSPI0_IO6       = (0x1CU << IOPORT_PFC_OFFSET), ///< P06_4 / xSPIn / XSPI0_IO6
    IOPORT_PIN_P064_PFC_24_SI09            = (0x24U << IOPORT_PFC_OFFSET), ///< P06_4 / ENDATn / SI09
    IOPORT_PIN_P064_PFC_25_HDSL05_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P06_4 / HDSLn / HDSL05_CLK1
    IOPORT_PIN_P065_PFC_00_IRQ11           = (0x00U << IOPORT_PFC_OFFSET), ///< P06_5 / IRQ / IRQ11
    IOPORT_PIN_P065_PFC_0C_GTETRGC         = (0x0CU << IOPORT_PFC_OFFSET), ///< P06_5 / POEG / GTETRGC
    IOPORT_PIN_P065_PFC_17_IIC_SDA1        = (0x17U << IOPORT_PFC_OFFSET), ///< P06_5 / IICn / IIC_SDA1
    IOPORT_PIN_P065_PFC_1C_XSPI0_IO7       = (0x1CU << IOPORT_PFC_OFFSET), ///< P06_5 / xSPIn / XSPI0_IO7
    IOPORT_PIN_P065_PFC_25_HDSL05_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P06_5 / HDSLn / HDSL05_SEL1
    IOPORT_PIN_P066_PFC_1C_XSPI0_RESET0    = (0x1CU << IOPORT_PFC_OFFSET), ///< P06_6 / xSPIn / XSPI0_RESET0
    IOPORT_PIN_P067_PFC_00_IRQ12           = (0x00U << IOPORT_PFC_OFFSET), ///< P06_7 / IRQ / IRQ12
    IOPORT_PIN_P067_PFC_08_POE4            = (0x08U << IOPORT_PFC_OFFSET), ///< P06_7 / POE3 / POE4
    IOPORT_PIN_P067_PFC_0C_GTETRGD         = (0x0CU << IOPORT_PFC_OFFSET), ///< P06_7 / POEG / GTETRGD
    IOPORT_PIN_P067_PFC_10_GMAC1_MDC       = (0x10U << IOPORT_PFC_OFFSET), ///< P06_7 / ETHER_GMACn / GMAC1_MDC
    IOPORT_PIN_P067_PFC_17_IIC_SCL2        = (0x17U << IOPORT_PFC_OFFSET), ///< P06_7 / IICn / IIC_SCL2
    IOPORT_PIN_P067_PFC_25_HDSL05_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P06_7 / HDSLn / HDSL05_MISO1
    IOPORT_PIN_P070_PFC_00_IRQ13           = (0x00U << IOPORT_PFC_OFFSET), ///< P07_0 / IRQ / IRQ13
    IOPORT_PIN_P070_PFC_10_GMAC1_MDIO      = (0x10U << IOPORT_PFC_OFFSET), ///< P07_0 / ETHER_GMACn / GMAC1_MDIO
    IOPORT_PIN_P070_PFC_17_IIC_SDA2        = (0x17U << IOPORT_PFC_OFFSET), ///< P07_0 / IICn / IIC_SDA2
    IOPORT_PIN_P070_PFC_1C_XSPI0_RESET1    = (0x1CU << IOPORT_PFC_OFFSET), ///< P07_0 / xSPIn / XSPI0_RESET1
    IOPORT_PIN_P070_PFC_25_HDSL05_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P07_0 / HDSLn / HDSL05_MOSI1
    IOPORT_PIN_P071_PFC_00_IRQ14           = (0x00U << IOPORT_PFC_OFFSET), ///< P07_1 / IRQ / IRQ14
    IOPORT_PIN_P071_PFC_08_POE8            = (0x08U << IOPORT_PFC_OFFSET), ///< P07_1 / POE3 / POE8
    IOPORT_PIN_P071_PFC_15_SCKE04          = (0x15U << IOPORT_PFC_OFFSET), ///< P07_1 / SCIEn / SCKE04
    IOPORT_PIN_P071_PFC_16_SCKE08          = (0x16U << IOPORT_PFC_OFFSET), ///< P07_1 / SCIEn / SCKE08
    IOPORT_PIN_P071_PFC_17_IIC_SCL0        = (0x17U << IOPORT_PFC_OFFSET), ///< P07_1 / IICn / IIC_SCL0
    IOPORT_PIN_P071_PFC_1C_XSPI0_RSTO0     = (0x1CU << IOPORT_PFC_OFFSET), ///< P07_1 / xSPIn / XSPI0_RSTO0
    IOPORT_PIN_P071_PFC_1D_MCLK00          = (0x1DU << IOPORT_PFC_OFFSET), ///< P07_1 / DSMIFn / MCLK00
    IOPORT_PIN_P071_PFC_22_ENCIFCK04       = (0x22U << IOPORT_PFC_OFFSET), ///< P07_1 / ENCIFn / ENCIFCK04
    IOPORT_PIN_P071_PFC_23_ENCIFCK12       = (0x23U << IOPORT_PFC_OFFSET), ///< P07_1 / ENCIFn / ENCIFCK12
    IOPORT_PIN_P071_PFC_25_HDSL05_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P07_1 / HDSLn / HDSL05_CLK2
    IOPORT_PIN_P072_PFC_00_IRQ15           = (0x00U << IOPORT_PFC_OFFSET), ///< P07_2 / IRQ / IRQ15
    IOPORT_PIN_P072_PFC_08_POE10           = (0x08U << IOPORT_PFC_OFFSET), ///< P07_2 / POE3 / POE10
    IOPORT_PIN_P072_PFC_15_DEE04           = (0x15U << IOPORT_PFC_OFFSET), ///< P07_2 / SCIEn / DEE04
    IOPORT_PIN_P072_PFC_16_DEE08           = (0x16U << IOPORT_PFC_OFFSET), ///< P07_2 / SCIEn / DEE08
    IOPORT_PIN_P072_PFC_17_IIC_SDA0        = (0x17U << IOPORT_PFC_OFFSET), ///< P07_2 / IICn / IIC_SDA0
    IOPORT_PIN_P072_PFC_1C_XSPI0_RSTO1     = (0x1CU << IOPORT_PFC_OFFSET), ///< P07_2 / xSPIn / XSPI0_RSTO1
    IOPORT_PIN_P072_PFC_1D_MDAT00          = (0x1DU << IOPORT_PFC_OFFSET), ///< P07_2 / DSMIFn / MDAT00
    IOPORT_PIN_P072_PFC_22_ENCIFOE04       = (0x22U << IOPORT_PFC_OFFSET), ///< P07_2 / ENCIFn / ENCIFOE04
    IOPORT_PIN_P072_PFC_23_ENCIFOE12       = (0x23U << IOPORT_PFC_OFFSET), ///< P07_2 / ENCIFn / ENCIFOE12
    IOPORT_PIN_P072_PFC_25_HDSL05_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P07_2 / HDSLn / HDSL05_SEL2
    IOPORT_PIN_P073_PFC_08_POE11           = (0x08U << IOPORT_PFC_OFFSET), ///< P07_3 / POE3 / POE11
    IOPORT_PIN_P073_PFC_15_TXDE04          = (0x15U << IOPORT_PFC_OFFSET), ///< P07_3 / SCIEn / TXDE04
    IOPORT_PIN_P073_PFC_16_TXDE08          = (0x16U << IOPORT_PFC_OFFSET), ///< P07_3 / SCIEn / TXDE08
    IOPORT_PIN_P073_PFC_17_IIC_SCL1        = (0x17U << IOPORT_PFC_OFFSET), ///< P07_3 / IICn / IIC_SCL1
    IOPORT_PIN_P073_PFC_1C_XSPI0_INT0      = (0x1CU << IOPORT_PFC_OFFSET), ///< P07_3 / xSPIn / XSPI0_INT0
    IOPORT_PIN_P073_PFC_1D_MCLK01          = (0x1DU << IOPORT_PFC_OFFSET), ///< P07_3 / DSMIFn / MCLK01
    IOPORT_PIN_P073_PFC_22_ENCIFDO04       = (0x22U << IOPORT_PFC_OFFSET), ///< P07_3 / ENCIFn / ENCIFDO04
    IOPORT_PIN_P073_PFC_23_ENCIFDO12       = (0x23U << IOPORT_PFC_OFFSET), ///< P07_3 / ENCIFn / ENCIFDO12
    IOPORT_PIN_P073_PFC_25_HDSL05_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P07_3 / HDSLn / HDSL05_MISO2
    IOPORT_PIN_P074_PFC_15_RXDE04          = (0x15U << IOPORT_PFC_OFFSET), ///< P07_4 / SCIEn / RXDE04
    IOPORT_PIN_P074_PFC_16_RXDE08          = (0x16U << IOPORT_PFC_OFFSET), ///< P07_4 / SCIEn / RXDE08
    IOPORT_PIN_P074_PFC_17_IIC_SDA1        = (0x17U << IOPORT_PFC_OFFSET), ///< P07_4 / IICn / IIC_SDA1
    IOPORT_PIN_P074_PFC_1C_XSPI0_INT1      = (0x1CU << IOPORT_PFC_OFFSET), ///< P07_4 / xSPIn / XSPI0_INT1
    IOPORT_PIN_P074_PFC_1D_MDAT01          = (0x1DU << IOPORT_PFC_OFFSET), ///< P07_4 / DSMIFn / MDAT01
    IOPORT_PIN_P074_PFC_22_ENCIFDI04       = (0x22U << IOPORT_PFC_OFFSET), ///< P07_4 / ENCIFn / ENCIFDI04
    IOPORT_PIN_P074_PFC_23_ENCIFDI12       = (0x23U << IOPORT_PFC_OFFSET), ///< P07_4 / ENCIFn / ENCIFDI12
    IOPORT_PIN_P074_PFC_25_HDSL05_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P07_4 / HDSLn / HDSL05_MOSI2
    IOPORT_PIN_P075_PFC_15_SCKE05          = (0x15U << IOPORT_PFC_OFFSET), ///< P07_5 / SCIEn / SCKE05
    IOPORT_PIN_P075_PFC_17_IIC_SCL2        = (0x17U << IOPORT_PFC_OFFSET), ///< P07_5 / IICn / IIC_SCL2
    IOPORT_PIN_P075_PFC_1C_XSPI0_ECS0      = (0x1CU << IOPORT_PFC_OFFSET), ///< P07_5 / xSPIn / XSPI0_ECS0
    IOPORT_PIN_P075_PFC_1D_MCLK02          = (0x1DU << IOPORT_PFC_OFFSET), ///< P07_5 / DSMIFn / MCLK02
    IOPORT_PIN_P075_PFC_22_ENCIFCK05       = (0x22U << IOPORT_PFC_OFFSET), ///< P07_5 / ENCIFn / ENCIFCK05
    IOPORT_PIN_P075_PFC_25_HDSL06_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P07_5 / HDSLn / HDSL06_LINK
    IOPORT_PIN_P076_PFC_15_DEE05           = (0x15U << IOPORT_PFC_OFFSET), ///< P07_6 / SCIEn / DEE05
    IOPORT_PIN_P076_PFC_17_IIC_SDA2        = (0x17U << IOPORT_PFC_OFFSET), ///< P07_6 / IICn / IIC_SDA2
    IOPORT_PIN_P076_PFC_1C_XSPI0_ECS1      = (0x1CU << IOPORT_PFC_OFFSET), ///< P07_6 / xSPIn / XSPI0_ECS1
    IOPORT_PIN_P076_PFC_1D_MDAT02          = (0x1DU << IOPORT_PFC_OFFSET), ///< P07_6 / DSMIFn / MDAT02
    IOPORT_PIN_P076_PFC_22_ENCIFOE05       = (0x22U << IOPORT_PFC_OFFSET), ///< P07_6 / ENCIFn / ENCIFOE05
    IOPORT_PIN_P076_PFC_25_HDSL06_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P07_6 / HDSLn / HDSL06_SMPL
    IOPORT_PIN_P077_PFC_15_TXDE05          = (0x15U << IOPORT_PFC_OFFSET), ///< P07_7 / SCIEn / TXDE05
    IOPORT_PIN_P077_PFC_17_IIC_SCL0        = (0x17U << IOPORT_PFC_OFFSET), ///< P07_7 / IICn / IIC_SCL0
    IOPORT_PIN_P077_PFC_1C_XSPI0_WP0       = (0x1CU << IOPORT_PFC_OFFSET), ///< P07_7 / xSPIn / XSPI0_WP0
    IOPORT_PIN_P077_PFC_1D_MCLK10          = (0x1DU << IOPORT_PFC_OFFSET), ///< P07_7 / DSMIFn / MCLK10
    IOPORT_PIN_P077_PFC_22_ENCIFDO05       = (0x22U << IOPORT_PFC_OFFSET), ///< P07_7 / ENCIFn / ENCIFDO05
    IOPORT_PIN_P077_PFC_25_HDSL06_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P07_7 / HDSLn / HDSL06_CLK1
    IOPORT_PIN_P080_PFC_0E_RTCAT1HZ        = (0x0EU << IOPORT_PFC_OFFSET), ///< P08_0 / RTC / RTCAT1HZ
    IOPORT_PIN_P080_PFC_15_RXDE05          = (0x15U << IOPORT_PFC_OFFSET), ///< P08_0 / SCIEn / RXDE05
    IOPORT_PIN_P080_PFC_17_IIC_SDA0        = (0x17U << IOPORT_PFC_OFFSET), ///< P08_0 / IICn / IIC_SDA0
    IOPORT_PIN_P080_PFC_1C_XSPI0_WP1       = (0x1CU << IOPORT_PFC_OFFSET), ///< P08_0 / xSPIn / XSPI0_WP1
    IOPORT_PIN_P080_PFC_1D_MDAT10          = (0x1DU << IOPORT_PFC_OFFSET), ///< P08_0 / DSMIFn / MDAT10
    IOPORT_PIN_P080_PFC_21_MBX_HINT        = (0x21U << IOPORT_PFC_OFFSET), ///< P08_0 / MBXSEM / MBX_HINT
    IOPORT_PIN_P080_PFC_22_ENCIFDI05       = (0x22U << IOPORT_PFC_OFFSET), ///< P08_0 / ENCIFn / ENCIFDI05
    IOPORT_PIN_P080_PFC_25_HDSL06_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P08_0 / HDSLn / HDSL06_SEL1
    IOPORT_PIN_P081_PFC_01_TMS             = (0x01U << IOPORT_PFC_OFFSET), ///< P08_1 / JTAG/SWD / TMS
    IOPORT_PIN_P081_PFC_24_DUEI10          = (0x24U << IOPORT_PFC_OFFSET), ///< P08_1 / ENDATn / DUEI10
    IOPORT_PIN_P081_PFC_25_HDSL06_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P08_1 / HDSLn / HDSL06_MISO1
    IOPORT_PIN_P082_PFC_01_TDI             = (0x01U << IOPORT_PFC_OFFSET), ///< P08_2 / JTAG/SWD / TDI
    IOPORT_PIN_P082_PFC_24_TST_OUT10       = (0x24U << IOPORT_PFC_OFFSET), ///< P08_2 / ENDATn / TST_OUT10
    IOPORT_PIN_P082_PFC_25_HDSL06_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P08_2 / HDSLn / HDSL06_MOSI1
    IOPORT_PIN_P083_PFC_01_TCK             = (0x01U << IOPORT_PFC_OFFSET), ///< P08_3 / JTAG/SWD / TCK
    IOPORT_PIN_P083_PFC_24_SI10            = (0x24U << IOPORT_PFC_OFFSET), ///< P08_3 / ENDATn / SI10
    IOPORT_PIN_P083_PFC_25_HDSL06_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P08_3 / HDSLn / HDSL06_CLK2
    IOPORT_PIN_P084_PFC_01_TDO             = (0x01U << IOPORT_PFC_OFFSET), ///< P08_4 / JTAG/SWD / TDO
    IOPORT_PIN_P084_PFC_25_HDSL06_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P08_4 / HDSLn / HDSL06_SEL2
    IOPORT_PIN_P085_PFC_00_IRQ8            = (0x00U << IOPORT_PFC_OFFSET), ///< P08_5 / IRQ / IRQ8
    IOPORT_PIN_P085_PFC_01_RSTOUT          = (0x01U << IOPORT_PFC_OFFSET), ///< P08_5 / JTAG/SWD / RSTOUT
    IOPORT_PIN_P085_PFC_0C_GTETRGSA        = (0x0CU << IOPORT_PFC_OFFSET), ///< P08_5 / POEG / GTETRGSA
    IOPORT_PIN_P085_PFC_17_IIC_SCL1        = (0x17U << IOPORT_PFC_OFFSET), ///< P08_5 / IICn / IIC_SCL1
    IOPORT_PIN_P085_PFC_1D_MCLK02          = (0x1DU << IOPORT_PFC_OFFSET), ///< P08_5 / DSMIFn / MCLK02
    IOPORT_PIN_P085_PFC_25_HDSL06_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P08_5 / HDSLn / HDSL06_MISO2
    IOPORT_PIN_P085_PFC_29_SD1_PWEN        = (0x29U << IOPORT_PFC_OFFSET), ///< P08_5 / SDHI / SD1_PWEN
    IOPORT_PIN_P086_PFC_00_SEI             = (0x00U << IOPORT_PFC_OFFSET), ///< P08_6 / IRQ / SEI
    IOPORT_PIN_P086_PFC_02_CKIO            = (0x02U << IOPORT_PFC_OFFSET), ///< P08_6 / BSC / CKIO
    IOPORT_PIN_P086_PFC_0B_GTIOC08_3A      = (0x0BU << IOPORT_PFC_OFFSET), ///< P08_6 / GPT / GTIOC08_3A
    IOPORT_PIN_P086_PFC_0C_GTETRGSB        = (0x0CU << IOPORT_PFC_OFFSET), ///< P08_6 / POEG / GTETRGSB
    IOPORT_PIN_P086_PFC_17_IIC_SDA1        = (0x17U << IOPORT_PFC_OFFSET), ///< P08_6 / IICn / IIC_SDA1
    IOPORT_PIN_P086_PFC_1D_MDAT02          = (0x1DU << IOPORT_PFC_OFFSET), ///< P08_6 / DSMIFn / MDAT02
    IOPORT_PIN_P086_PFC_1E_MCLK11          = (0x1EU << IOPORT_PFC_OFFSET), ///< P08_6 / DSMIFn / MCLK11
    IOPORT_PIN_P086_PFC_24_DUEI11          = (0x24U << IOPORT_PFC_OFFSET), ///< P08_6 / ENDATn / DUEI11
    IOPORT_PIN_P086_PFC_25_HDSL06_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P08_6 / HDSLn / HDSL06_MOSI2
    IOPORT_PIN_P086_PFC_29_SD1_IOVS        = (0x29U << IOPORT_PFC_OFFSET), ///< P08_6 / SDHI / SD1_IOVS
    IOPORT_PIN_P087_PFC_00_IRQ0            = (0x00U << IOPORT_PFC_OFFSET), ///< P08_7 / IRQ / IRQ0
    IOPORT_PIN_P087_PFC_04_A0              = (0x04U << IOPORT_PFC_OFFSET), ///< P08_7 / BSC / A0
    IOPORT_PIN_P087_PFC_0B_GTIOC08_3B      = (0x0BU << IOPORT_PFC_OFFSET), ///< P08_7 / GPT / GTIOC08_3B
    IOPORT_PIN_P087_PFC_17_IIC_SCL2        = (0x17U << IOPORT_PFC_OFFSET), ///< P08_7 / IICn / IIC_SCL2
    IOPORT_PIN_P087_PFC_18_IIC_SCL1        = (0x18U << IOPORT_PFC_OFFSET), ///< P08_7 / IICn / IIC_SCL1
    IOPORT_PIN_P087_PFC_1E_MDAT11          = (0x1EU << IOPORT_PFC_OFFSET), ///< P08_7 / DSMIFn / MDAT11
    IOPORT_PIN_P087_PFC_24_TST_OUT11       = (0x24U << IOPORT_PFC_OFFSET), ///< P08_7 / ENDATn / TST_OUT11
    IOPORT_PIN_P087_PFC_25_HDSL07_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P08_7 / HDSLn / HDSL07_LINK
    IOPORT_PIN_P090_PFC_17_IIC_SDA2        = (0x17U << IOPORT_PFC_OFFSET), ///< P09_0 / IICn / IIC_SDA2
    IOPORT_PIN_P090_PFC_1D_MCLK12          = (0x1DU << IOPORT_PFC_OFFSET), ///< P09_0 / DSMIFn / MCLK12
    IOPORT_PIN_P090_PFC_24_SI11            = (0x24U << IOPORT_PFC_OFFSET), ///< P09_0 / ENDATn / SI11
    IOPORT_PIN_P090_PFC_25_HDSL07_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P09_0 / HDSLn / HDSL07_SMPL
    IOPORT_PIN_P091_PFC_1D_MDAT12          = (0x1DU << IOPORT_PFC_OFFSET), ///< P09_1 / DSMIFn / MDAT12
    IOPORT_PIN_P091_PFC_24_DUEI12          = (0x24U << IOPORT_PFC_OFFSET), ///< P09_1 / ENDATn / DUEI12
    IOPORT_PIN_P091_PFC_25_HDSL07_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P09_1 / HDSLn / HDSL07_CLK1
    IOPORT_PIN_P092_PFC_1D_MCLK20          = (0x1DU << IOPORT_PFC_OFFSET), ///< P09_2 / DSMIFn / MCLK20
    IOPORT_PIN_P092_PFC_24_TST_OUT12       = (0x24U << IOPORT_PFC_OFFSET), ///< P09_2 / ENDATn / TST_OUT12
    IOPORT_PIN_P092_PFC_25_HDSL07_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P09_2 / HDSLn / HDSL07_SEL1
    IOPORT_PIN_P093_PFC_1D_MDAT20          = (0x1DU << IOPORT_PFC_OFFSET), ///< P09_3 / DSMIFn / MDAT20
    IOPORT_PIN_P093_PFC_24_SI12            = (0x24U << IOPORT_PFC_OFFSET), ///< P09_3 / ENDATn / SI12
    IOPORT_PIN_P093_PFC_25_HDSL07_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P09_3 / HDSLn / HDSL07_MISO1
    IOPORT_PIN_P094_PFC_04_D13             = (0x04U << IOPORT_PFC_OFFSET), ///< P09_4 / BSC / D13
    IOPORT_PIN_P094_PFC_06_MTIOC6B         = (0x06U << IOPORT_PFC_OFFSET), ///< P09_4 / MTU3 / MTIOC6B
    IOPORT_PIN_P094_PFC_09_GTIOC04_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P09_4 / GPT / GTIOC04_0A
    IOPORT_PIN_P094_PFC_0A_GTIOC10_0A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P09_4 / GPT / GTIOC10_0A
    IOPORT_PIN_P094_PFC_1D_MCLK70          = (0x1DU << IOPORT_PFC_OFFSET), ///< P09_4 / DSMIFn / MCLK70
    IOPORT_PIN_P094_PFC_24_DUEI13          = (0x24U << IOPORT_PFC_OFFSET), ///< P09_4 / ENDATn / DUEI13
    IOPORT_PIN_P094_PFC_25_HDSL07_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P09_4 / HDSLn / HDSL07_MOSI1
    IOPORT_PIN_P094_PFC_28_DISP_CLK        = (0x28U << IOPORT_PFC_OFFSET), ///< P09_4 / LCDC / DISP_CLK
    IOPORT_PIN_P095_PFC_04_D14             = (0x04U << IOPORT_PFC_OFFSET), ///< P09_5 / BSC / D14
    IOPORT_PIN_P095_PFC_06_MTIOC6D         = (0x06U << IOPORT_PFC_OFFSET), ///< P09_5 / MTU3 / MTIOC6D
    IOPORT_PIN_P095_PFC_09_GTIOC04_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P09_5 / GPT / GTIOC04_0B
    IOPORT_PIN_P095_PFC_0A_GTIOC10_0B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P09_5 / GPT / GTIOC10_0B
    IOPORT_PIN_P095_PFC_1D_MDAT70          = (0x1DU << IOPORT_PFC_OFFSET), ///< P09_5 / DSMIFn / MDAT70
    IOPORT_PIN_P095_PFC_24_TST_OUT13       = (0x24U << IOPORT_PFC_OFFSET), ///< P09_5 / ENDATn / TST_OUT13
    IOPORT_PIN_P095_PFC_25_HDSL07_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P09_5 / HDSLn / HDSL07_CLK2
    IOPORT_PIN_P095_PFC_28_DISP_HSYNC      = (0x28U << IOPORT_PFC_OFFSET), ///< P09_5 / LCDC / DISP_HSYNC
    IOPORT_PIN_P096_PFC_04_D15             = (0x04U << IOPORT_PFC_OFFSET), ///< P09_6 / BSC / D15
    IOPORT_PIN_P096_PFC_06_MTIOC7A         = (0x06U << IOPORT_PFC_OFFSET), ///< P09_6 / MTU3 / MTIOC7A
    IOPORT_PIN_P096_PFC_09_GTIOC04_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P09_6 / GPT / GTIOC04_1A
    IOPORT_PIN_P096_PFC_0A_GTIOC10_1A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P09_6 / GPT / GTIOC10_1A
    IOPORT_PIN_P096_PFC_1D_MCLK71          = (0x1DU << IOPORT_PFC_OFFSET), ///< P09_6 / DSMIFn / MCLK71
    IOPORT_PIN_P096_PFC_24_SI13            = (0x24U << IOPORT_PFC_OFFSET), ///< P09_6 / ENDATn / SI13
    IOPORT_PIN_P096_PFC_25_HDSL07_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P09_6 / HDSLn / HDSL07_SEL2
    IOPORT_PIN_P096_PFC_28_DISP_VSYNC      = (0x28U << IOPORT_PFC_OFFSET), ///< P09_6 / LCDC / DISP_VSYNC
    IOPORT_PIN_P097_PFC_04_WE0             = (0x04U << IOPORT_PFC_OFFSET), ///< P09_7 / BSC / WE0
    IOPORT_PIN_P097_PFC_06_MTIOC7C         = (0x06U << IOPORT_PFC_OFFSET), ///< P09_7 / MTU3 / MTIOC7C
    IOPORT_PIN_P097_PFC_09_GTIOC04_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P09_7 / GPT / GTIOC04_1B
    IOPORT_PIN_P097_PFC_0A_GTIOC10_1B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P09_7 / GPT / GTIOC10_1B
    IOPORT_PIN_P097_PFC_1D_MDAT71          = (0x1DU << IOPORT_PFC_OFFSET), ///< P09_7 / DSMIFn / MDAT71
    IOPORT_PIN_P097_PFC_24_DUEI14          = (0x24U << IOPORT_PFC_OFFSET), ///< P09_7 / ENDATn / DUEI14
    IOPORT_PIN_P097_PFC_25_HDSL07_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P09_7 / HDSLn / HDSL07_MISO2
    IOPORT_PIN_P097_PFC_28_DISP_DE         = (0x28U << IOPORT_PFC_OFFSET), ///< P09_7 / LCDC / DISP_DE
    IOPORT_PIN_P100_PFC_00_IRQ4            = (0x00U << IOPORT_PFC_OFFSET), ///< P10_0 / IRQ / IRQ4
    IOPORT_PIN_P100_PFC_04_WE1             = (0x04U << IOPORT_PFC_OFFSET), ///< P10_0 / BSC / WE1
    IOPORT_PIN_P100_PFC_06_MTIOC7B         = (0x06U << IOPORT_PFC_OFFSET), ///< P10_0 / MTU3 / MTIOC7B
    IOPORT_PIN_P100_PFC_09_GTIOC04_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P10_0 / GPT / GTIOC04_2A
    IOPORT_PIN_P100_PFC_0A_GTIOC10_2A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P10_0 / GPT / GTIOC10_2A
    IOPORT_PIN_P100_PFC_1D_MCLK72          = (0x1DU << IOPORT_PFC_OFFSET), ///< P10_0 / DSMIFn / MCLK72
    IOPORT_PIN_P100_PFC_24_TST_OUT14       = (0x24U << IOPORT_PFC_OFFSET), ///< P10_0 / ENDATn / TST_OUT14
    IOPORT_PIN_P100_PFC_25_HDSL07_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P10_0 / HDSLn / HDSL07_MOSI2
    IOPORT_PIN_P100_PFC_28_DISP_DATAR0     = (0x28U << IOPORT_PFC_OFFSET), ///< P10_0 / LCDC / DISP_DATAR0
    IOPORT_PIN_P101_PFC_00_IRQ7            = (0x00U << IOPORT_PFC_OFFSET), ///< P10_1 / IRQ / IRQ7
    IOPORT_PIN_P101_PFC_04_WAIT            = (0x04U << IOPORT_PFC_OFFSET), ///< P10_1 / BSC / WAIT
    IOPORT_PIN_P101_PFC_06_MTIOC7D         = (0x06U << IOPORT_PFC_OFFSET), ///< P10_1 / MTU3 / MTIOC7D
    IOPORT_PIN_P101_PFC_09_GTIOC04_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P10_1 / GPT / GTIOC04_2B
    IOPORT_PIN_P101_PFC_0A_GTIOC10_2B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P10_1 / GPT / GTIOC10_2B
    IOPORT_PIN_P101_PFC_14_SCK0            = (0x14U << IOPORT_PFC_OFFSET), ///< P10_1 / SCIn / SCK0
    IOPORT_PIN_P101_PFC_1D_MDAT72          = (0x1DU << IOPORT_PFC_OFFSET), ///< P10_1 / DSMIFn / MDAT72
    IOPORT_PIN_P101_PFC_24_SI14            = (0x24U << IOPORT_PFC_OFFSET), ///< P10_1 / ENDATn / SI14
    IOPORT_PIN_P101_PFC_25_HDSL08_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P10_1 / HDSLn / HDSL08_LINK
    IOPORT_PIN_P101_PFC_28_DISP_DATAR1     = (0x28U << IOPORT_PFC_OFFSET), ///< P10_1 / LCDC / DISP_DATAR1
    IOPORT_PIN_P102_PFC_00_IRQ1            = (0x00U << IOPORT_PFC_OFFSET), ///< P10_2 / IRQ / IRQ1
    IOPORT_PIN_P102_PFC_04_CS0             = (0x04U << IOPORT_PFC_OFFSET), ///< P10_2 / BSC / CS0
    IOPORT_PIN_P102_PFC_06_MTCLKC          = (0x06U << IOPORT_PFC_OFFSET), ///< P10_2 / MTU3 / MTCLKC
    IOPORT_PIN_P102_PFC_07_MTIOC2A         = (0x07U << IOPORT_PFC_OFFSET), ///< P10_2 / MTU3 / MTIOC2A
    IOPORT_PIN_P102_PFC_09_GTIOC04_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P10_2 / GPT / GTIOC04_3A
    IOPORT_PIN_P102_PFC_0A_GTIOC10_3A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P10_2 / GPT / GTIOC10_3A
    IOPORT_PIN_P102_PFC_14_RXD0_SCL0_MISO0 = (0x14U << IOPORT_PFC_OFFSET), ///< P10_2 / SCIn / RXD0_SCL0_MISO0
    IOPORT_PIN_P102_PFC_15_SCKE04          = (0x15U << IOPORT_PFC_OFFSET), ///< P10_2 / SCIEn / SCKE04
    IOPORT_PIN_P102_PFC_1D_MCLK10          = (0x1DU << IOPORT_PFC_OFFSET), ///< P10_2 / DSMIFn / MCLK10
    IOPORT_PIN_P102_PFC_1E_MCLK00          = (0x1EU << IOPORT_PFC_OFFSET), ///< P10_2 / DSMIFn / MCLK00
    IOPORT_PIN_P102_PFC_22_ENCIFCK04       = (0x22U << IOPORT_PFC_OFFSET), ///< P10_2 / ENCIFn / ENCIFCK04
    IOPORT_PIN_P102_PFC_25_HDSL08_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P10_2 / HDSLn / HDSL08_SMPL
    IOPORT_PIN_P102_PFC_28_DISP_DATAR2     = (0x28U << IOPORT_PFC_OFFSET), ///< P10_2 / LCDC / DISP_DATAR2
    IOPORT_PIN_P103_PFC_00_IRQ2            = (0x00U << IOPORT_PFC_OFFSET), ///< P10_3 / IRQ / IRQ2
    IOPORT_PIN_P103_PFC_04_RD              = (0x04U << IOPORT_PFC_OFFSET), ///< P10_3 / BSC / RD
    IOPORT_PIN_P103_PFC_06_MTCLKD          = (0x06U << IOPORT_PFC_OFFSET), ///< P10_3 / MTU3 / MTCLKD
    IOPORT_PIN_P103_PFC_07_MTIOC2B         = (0x07U << IOPORT_PFC_OFFSET), ///< P10_3 / MTU3 / MTIOC2B
    IOPORT_PIN_P103_PFC_09_GTIOC04_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P10_3 / GPT / GTIOC04_3B
    IOPORT_PIN_P103_PFC_0A_GTIOC10_3B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P10_3 / GPT / GTIOC10_3B
    IOPORT_PIN_P103_PFC_14_TXD0_SDA0_MOSI0 = (0x14U << IOPORT_PFC_OFFSET), ///< P10_3 / SCIn / TXD0_SDA0_MOSI0
    IOPORT_PIN_P103_PFC_15_DEE04           = (0x15U << IOPORT_PFC_OFFSET), ///< P10_3 / SCIEn / DEE04
    IOPORT_PIN_P103_PFC_1D_MDAT10          = (0x1DU << IOPORT_PFC_OFFSET), ///< P10_3 / DSMIFn / MDAT10
    IOPORT_PIN_P103_PFC_1E_MDAT00          = (0x1EU << IOPORT_PFC_OFFSET), ///< P10_3 / DSMIFn / MDAT00
    IOPORT_PIN_P103_PFC_22_ENCIFOE04       = (0x22U << IOPORT_PFC_OFFSET), ///< P10_3 / ENCIFn / ENCIFOE04
    IOPORT_PIN_P103_PFC_25_HDSL08_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P10_3 / HDSLn / HDSL08_CLK1
    IOPORT_PIN_P103_PFC_28_DISP_DATAR3     = (0x28U << IOPORT_PFC_OFFSET), ///< P10_3 / LCDC / DISP_DATAR3
    IOPORT_PIN_P104_PFC_00_IRQ3            = (0x00U << IOPORT_PFC_OFFSET), ///< P10_4 / IRQ / IRQ3
    IOPORT_PIN_P104_PFC_04_A1              = (0x04U << IOPORT_PFC_OFFSET), ///< P10_4 / BSC / A1
    IOPORT_PIN_P104_PFC_06_MTIOC1A         = (0x06U << IOPORT_PFC_OFFSET), ///< P10_4 / MTU3 / MTIOC1A
    IOPORT_PIN_P104_PFC_09_GTIOC04_4A      = (0x09U << IOPORT_PFC_OFFSET), ///< P10_4 / GPT / GTIOC04_4A
    IOPORT_PIN_P104_PFC_14_SS0_CTS0_RTS0   = (0x14U << IOPORT_PFC_OFFSET), ///< P10_4 / SCIn / SS0_CTS0_RTS0
    IOPORT_PIN_P104_PFC_15_TXDE04          = (0x15U << IOPORT_PFC_OFFSET), ///< P10_4 / SCIEn / TXDE04
    IOPORT_PIN_P104_PFC_1D_MCLK11          = (0x1DU << IOPORT_PFC_OFFSET), ///< P10_4 / DSMIFn / MCLK11
    IOPORT_PIN_P104_PFC_1E_MCLK01          = (0x1EU << IOPORT_PFC_OFFSET), ///< P10_4 / DSMIFn / MCLK01
    IOPORT_PIN_P104_PFC_22_ENCIFDO04       = (0x22U << IOPORT_PFC_OFFSET), ///< P10_4 / ENCIFn / ENCIFDO04
    IOPORT_PIN_P104_PFC_25_HDSL08_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P10_4 / HDSLn / HDSL08_SEL1
    IOPORT_PIN_P104_PFC_28_DISP_DATAR4     = (0x28U << IOPORT_PFC_OFFSET), ///< P10_4 / LCDC / DISP_DATAR4
    IOPORT_PIN_P105_PFC_04_A2              = (0x04U << IOPORT_PFC_OFFSET), ///< P10_5 / BSC / A2
    IOPORT_PIN_P105_PFC_06_MTIOC1B         = (0x06U << IOPORT_PFC_OFFSET), ///< P10_5 / MTU3 / MTIOC1B
    IOPORT_PIN_P105_PFC_07_MTIOC0A         = (0x07U << IOPORT_PFC_OFFSET), ///< P10_5 / MTU3 / MTIOC0A
    IOPORT_PIN_P105_PFC_09_GTIOC04_4B      = (0x09U << IOPORT_PFC_OFFSET), ///< P10_5 / GPT / GTIOC04_4B
    IOPORT_PIN_P105_PFC_14_CTS0            = (0x14U << IOPORT_PFC_OFFSET), ///< P10_5 / SCIn / CTS0
    IOPORT_PIN_P105_PFC_15_RXDE04          = (0x15U << IOPORT_PFC_OFFSET), ///< P10_5 / SCIEn / RXDE04
    IOPORT_PIN_P105_PFC_1D_MDAT11          = (0x1DU << IOPORT_PFC_OFFSET), ///< P10_5 / DSMIFn / MDAT11
    IOPORT_PIN_P105_PFC_1E_MDAT01          = (0x1EU << IOPORT_PFC_OFFSET), ///< P10_5 / DSMIFn / MDAT01
    IOPORT_PIN_P105_PFC_22_ENCIFDI04       = (0x22U << IOPORT_PFC_OFFSET), ///< P10_5 / ENCIFn / ENCIFDI04
    IOPORT_PIN_P105_PFC_25_HDSL08_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P10_5 / HDSLn / HDSL08_MISO1
    IOPORT_PIN_P105_PFC_28_DISP_DATAR5     = (0x28U << IOPORT_PFC_OFFSET), ///< P10_5 / LCDC / DISP_DATAR5
    IOPORT_PIN_P106_PFC_00_IRQ0            = (0x00U << IOPORT_PFC_OFFSET), ///< P10_6 / IRQ / IRQ0
    IOPORT_PIN_P106_PFC_04_A3              = (0x04U << IOPORT_PFC_OFFSET), ///< P10_6 / BSC / A3
    IOPORT_PIN_P106_PFC_07_MTIOC0B         = (0x07U << IOPORT_PFC_OFFSET), ///< P10_6 / MTU3 / MTIOC0B
    IOPORT_PIN_P106_PFC_09_GTIOC05_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P10_6 / GPT / GTIOC05_0A
    IOPORT_PIN_P106_PFC_14_DE0             = (0x14U << IOPORT_PFC_OFFSET), ///< P10_6 / SCIn / DE0
    IOPORT_PIN_P106_PFC_1D_MCLK21          = (0x1DU << IOPORT_PFC_OFFSET), ///< P10_6 / DSMIFn / MCLK21
    IOPORT_PIN_P106_PFC_25_HDSL08_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P10_6 / HDSLn / HDSL08_MOSI1
    IOPORT_PIN_P106_PFC_26_POUTA           = (0x26U << IOPORT_PFC_OFFSET), ///< P10_6 / ENCOUT / POUTA
    IOPORT_PIN_P106_PFC_28_DISP_DATAR6     = (0x28U << IOPORT_PFC_OFFSET), ///< P10_6 / LCDC / DISP_DATAR6
    IOPORT_PIN_P107_PFC_00_IRQ9            = (0x00U << IOPORT_PFC_OFFSET), ///< P10_7 / IRQ / IRQ9
    IOPORT_PIN_P107_PFC_04_A4              = (0x04U << IOPORT_PFC_OFFSET), ///< P10_7 / BSC / A4
    IOPORT_PIN_P107_PFC_07_MTIC5U          = (0x07U << IOPORT_PFC_OFFSET), ///< P10_7 / MTU3 / MTIC5U
    IOPORT_PIN_P107_PFC_09_GTIOC05_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P10_7 / GPT / GTIOC05_0B
    IOPORT_PIN_P107_PFC_0B_GTIOC00_3A      = (0x0BU << IOPORT_PFC_OFFSET), ///< P10_7 / GPT / GTIOC00_3A
    IOPORT_PIN_P107_PFC_14_SCK1            = (0x14U << IOPORT_PFC_OFFSET), ///< P10_7 / SCIn / SCK1
    IOPORT_PIN_P107_PFC_1D_MDAT21          = (0x1DU << IOPORT_PFC_OFFSET), ///< P10_7 / DSMIFn / MDAT21
    IOPORT_PIN_P107_PFC_25_HDSL08_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P10_7 / HDSLn / HDSL08_CLK2
    IOPORT_PIN_P107_PFC_26_POUTB           = (0x26U << IOPORT_PFC_OFFSET), ///< P10_7 / ENCOUT / POUTB
    IOPORT_PIN_P107_PFC_28_DISP_DATAR7     = (0x28U << IOPORT_PFC_OFFSET), ///< P10_7 / LCDC / DISP_DATAR7
    IOPORT_PIN_P110_PFC_00_IRQ13           = (0x00U << IOPORT_PFC_OFFSET), ///< P11_0 / IRQ / IRQ13
    IOPORT_PIN_P110_PFC_04_A5              = (0x04U << IOPORT_PFC_OFFSET), ///< P11_0 / BSC / A5
    IOPORT_PIN_P110_PFC_0B_GTIOC00_3B      = (0x0BU << IOPORT_PFC_OFFSET), ///< P11_0 / GPT / GTIOC00_3B
    IOPORT_PIN_P110_PFC_12_ESC_RESETOUT_N  = (0x12U << IOPORT_PFC_OFFSET), ///< P11_0 / ETHER_ESC / ESC_RESETOUT_N
    IOPORT_PIN_P110_PFC_14_RXD1_SCL1_MISO1 = (0x14U << IOPORT_PFC_OFFSET), ///< P11_0 / SCIn / RXD1_SCL1_MISO1
    IOPORT_PIN_P110_PFC_1D_MCLK22          = (0x1DU << IOPORT_PFC_OFFSET), ///< P11_0 / DSMIFn / MCLK22
    IOPORT_PIN_P110_PFC_25_HDSL08_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P11_0 / HDSLn / HDSL08_SEL2
    IOPORT_PIN_P110_PFC_26_POUTZ           = (0x26U << IOPORT_PFC_OFFSET), ///< P11_0 / ENCOUT / POUTZ
    IOPORT_PIN_P110_PFC_28_DISP_DATAG0     = (0x28U << IOPORT_PFC_OFFSET), ///< P11_0 / LCDC / DISP_DATAG0
    IOPORT_PIN_P111_PFC_00_IRQ4            = (0x00U << IOPORT_PFC_OFFSET), ///< P11_1 / IRQ / IRQ4
    IOPORT_PIN_P111_PFC_12_ESC_LEDRUN      = (0x12U << IOPORT_PFC_OFFSET), ///< P11_1 / ETHER_ESC / ESC_LEDRUN
    IOPORT_PIN_P111_PFC_14_TXD1_SDA1_MOSI1 = (0x14U << IOPORT_PFC_OFFSET), ///< P11_1 / SCIn / TXD1_SDA1_MOSI1
    IOPORT_PIN_P111_PFC_1D_MDAT22          = (0x1DU << IOPORT_PFC_OFFSET), ///< P11_1 / DSMIFn / MDAT22
    IOPORT_PIN_P111_PFC_24_DUEI15          = (0x24U << IOPORT_PFC_OFFSET), ///< P11_1 / ENDATn / DUEI15
    IOPORT_PIN_P111_PFC_25_HDSL08_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P11_1 / HDSLn / HDSL08_MISO2
    IOPORT_PIN_P112_PFC_00_IRQ5            = (0x00U << IOPORT_PFC_OFFSET), ///< P11_2 / IRQ / IRQ5
    IOPORT_PIN_P112_PFC_14_SS1_CTS1_RTS1   = (0x14U << IOPORT_PFC_OFFSET), ///< P11_2 / SCIn / SS1_CTS1_RTS1
    IOPORT_PIN_P112_PFC_1D_MCLK30          = (0x1DU << IOPORT_PFC_OFFSET), ///< P11_2 / DSMIFn / MCLK30
    IOPORT_PIN_P112_PFC_24_TST_OUT15       = (0x24U << IOPORT_PFC_OFFSET), ///< P11_2 / ENDATn / TST_OUT15
    IOPORT_PIN_P112_PFC_25_HDSL08_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P11_2 / HDSLn / HDSL08_MOSI2
    IOPORT_PIN_P113_PFC_00_IRQ6            = (0x00U << IOPORT_PFC_OFFSET), ///< P11_3 / IRQ / IRQ6
    IOPORT_PIN_P113_PFC_14_CTS1            = (0x14U << IOPORT_PFC_OFFSET), ///< P11_3 / SCIn / CTS1
    IOPORT_PIN_P113_PFC_1D_MDAT30          = (0x1DU << IOPORT_PFC_OFFSET), ///< P11_3 / DSMIFn / MDAT30
    IOPORT_PIN_P113_PFC_24_SI15            = (0x24U << IOPORT_PFC_OFFSET), ///< P11_3 / ENDATn / SI15
    IOPORT_PIN_P113_PFC_25_HDSL09_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P11_3 / HDSLn / HDSL09_LINK
    IOPORT_PIN_P114_PFC_00_IRQ7            = (0x00U << IOPORT_PFC_OFFSET), ///< P11_4 / IRQ / IRQ7
    IOPORT_PIN_P114_PFC_14_DE1             = (0x14U << IOPORT_PFC_OFFSET), ///< P11_4 / SCIn / DE1
    IOPORT_PIN_P114_PFC_1D_MCLK31          = (0x1DU << IOPORT_PFC_OFFSET), ///< P11_4 / DSMIFn / MCLK31
    IOPORT_PIN_P114_PFC_25_HDSL09_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P11_4 / HDSLn / HDSL09_SMPL
    IOPORT_PIN_P115_PFC_1D_MDAT31          = (0x1DU << IOPORT_PFC_OFFSET), ///< P11_5 / DSMIFn / MDAT31
    IOPORT_PIN_P115_PFC_24_DUEI00          = (0x24U << IOPORT_PFC_OFFSET), ///< P11_5 / ENDATn / DUEI00
    IOPORT_PIN_P115_PFC_25_HDSL09_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P11_5 / HDSLn / HDSL09_CLK1
    IOPORT_PIN_P116_PFC_09_GTIOC05_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P11_6 / GPT / GTIOC05_0A
    IOPORT_PIN_P116_PFC_24_TST_OUT00       = (0x24U << IOPORT_PFC_OFFSET), ///< P11_6 / ENDATn / TST_OUT00
    IOPORT_PIN_P116_PFC_25_HDSL09_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P11_6 / HDSLn / HDSL09_SEL1
    IOPORT_PIN_P117_PFC_09_GTIOC05_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P11_7 / GPT / GTIOC05_0B
    IOPORT_PIN_P117_PFC_24_SI00            = (0x24U << IOPORT_PFC_OFFSET), ///< P11_7 / ENDATn / SI00
    IOPORT_PIN_P117_PFC_25_HDSL09_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P11_7 / HDSLn / HDSL09_MISO1
    IOPORT_PIN_P120_PFC_04_D16             = (0x04U << IOPORT_PFC_OFFSET), ///< P12_0 / BSC / D16
    IOPORT_PIN_P120_PFC_07_MTIC5V          = (0x07U << IOPORT_PFC_OFFSET), ///< P12_0 / MTU3 / MTIC5V
    IOPORT_PIN_P120_PFC_09_GTIOC05_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P12_0 / GPT / GTIOC05_1A
    IOPORT_PIN_P120_PFC_0D_CMTW0_TIC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P12_0 / CMTW / CMTW0_TIC0
    IOPORT_PIN_P120_PFC_19_CANRX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P12_0 / CANFDn / CANRX1
    IOPORT_PIN_P120_PFC_24_DUEI01          = (0x24U << IOPORT_PFC_OFFSET), ///< P12_0 / ENDATn / DUEI01
    IOPORT_PIN_P120_PFC_25_HDSL09_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P12_0 / HDSLn / HDSL09_MOSI1
    IOPORT_PIN_P120_PFC_29_SD0_CLK         = (0x29U << IOPORT_PFC_OFFSET), ///< P12_0 / SDHI / SD0_CLK
    IOPORT_PIN_P121_PFC_04_D17             = (0x04U << IOPORT_PFC_OFFSET), ///< P12_1 / BSC / D17
    IOPORT_PIN_P121_PFC_07_MTIC5W          = (0x07U << IOPORT_PFC_OFFSET), ///< P12_1 / MTU3 / MTIC5W
    IOPORT_PIN_P121_PFC_09_GTIOC05_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P12_1 / GPT / GTIOC05_1B
    IOPORT_PIN_P121_PFC_0D_CMTW0_TOC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P12_1 / CMTW / CMTW0_TOC0
    IOPORT_PIN_P121_PFC_19_CANTX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P12_1 / CANFDn / CANTX1
    IOPORT_PIN_P121_PFC_24_TST_OUT01       = (0x24U << IOPORT_PFC_OFFSET), ///< P12_1 / ENDATn / TST_OUT01
    IOPORT_PIN_P121_PFC_25_HDSL09_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P12_1 / HDSLn / HDSL09_CLK2
    IOPORT_PIN_P121_PFC_29_SD0_CMD         = (0x29U << IOPORT_PFC_OFFSET), ///< P12_1 / SDHI / SD0_CMD
    IOPORT_PIN_P122_PFC_04_D18             = (0x04U << IOPORT_PFC_OFFSET), ///< P12_2 / BSC / D18
    IOPORT_PIN_P122_PFC_09_GTIOC05_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P12_2 / GPT / GTIOC05_2A
    IOPORT_PIN_P122_PFC_0D_CMTW0_TIC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P12_2 / CMTW / CMTW0_TIC1
    IOPORT_PIN_P122_PFC_19_CANRXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P12_2 / CANFDn / CANRXDP1
    IOPORT_PIN_P122_PFC_24_SI01            = (0x24U << IOPORT_PFC_OFFSET), ///< P12_2 / ENDATn / SI01
    IOPORT_PIN_P122_PFC_25_HDSL09_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P12_2 / HDSLn / HDSL09_SEL2
    IOPORT_PIN_P122_PFC_29_SD0_DATA0       = (0x29U << IOPORT_PFC_OFFSET), ///< P12_2 / SDHI / SD0_DATA0
    IOPORT_PIN_P123_PFC_04_D19             = (0x04U << IOPORT_PFC_OFFSET), ///< P12_3 / BSC / D19
    IOPORT_PIN_P123_PFC_09_GTIOC05_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P12_3 / GPT / GTIOC05_2B
    IOPORT_PIN_P123_PFC_0D_CMTW0_TOC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P12_3 / CMTW / CMTW0_TOC1
    IOPORT_PIN_P123_PFC_14_SCK2            = (0x14U << IOPORT_PFC_OFFSET), ///< P12_3 / SCIn / SCK2
    IOPORT_PIN_P123_PFC_19_CANTXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P12_3 / CANFDn / CANTXDP1
    IOPORT_PIN_P123_PFC_25_HDSL09_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P12_3 / HDSLn / HDSL09_MISO2
    IOPORT_PIN_P123_PFC_29_SD0_DATA1       = (0x29U << IOPORT_PFC_OFFSET), ///< P12_3 / SDHI / SD0_DATA1
    IOPORT_PIN_P124_PFC_00_IRQ1            = (0x00U << IOPORT_PFC_OFFSET), ///< P12_4 / IRQ / IRQ1
    IOPORT_PIN_P124_PFC_04_D20             = (0x04U << IOPORT_PFC_OFFSET), ///< P12_4 / BSC / D20
    IOPORT_PIN_P124_PFC_09_GTIOC05_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P12_4 / GPT / GTIOC05_3A
    IOPORT_PIN_P124_PFC_0D_CMTW1_TIC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P12_4 / CMTW / CMTW1_TIC0
    IOPORT_PIN_P124_PFC_14_RXD2_SCL2_MISO2 = (0x14U << IOPORT_PFC_OFFSET), ///< P12_4 / SCIn / RXD2_SCL2_MISO2
    IOPORT_PIN_P124_PFC_15_SCKE05          = (0x15U << IOPORT_PFC_OFFSET), ///< P12_4 / SCIEn / SCKE05
    IOPORT_PIN_P124_PFC_1D_MCLK02          = (0x1DU << IOPORT_PFC_OFFSET), ///< P12_4 / DSMIFn / MCLK02
    IOPORT_PIN_P124_PFC_22_ENCIFCK05       = (0x22U << IOPORT_PFC_OFFSET), ///< P12_4 / ENCIFn / ENCIFCK05
    IOPORT_PIN_P124_PFC_25_HDSL09_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P12_4 / HDSLn / HDSL09_MOSI2
    IOPORT_PIN_P124_PFC_29_SD0_DATA2       = (0x29U << IOPORT_PFC_OFFSET), ///< P12_4 / SDHI / SD0_DATA2
    IOPORT_PIN_P125_PFC_04_D21             = (0x04U << IOPORT_PFC_OFFSET), ///< P12_5 / BSC / D21
    IOPORT_PIN_P125_PFC_09_GTIOC05_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P12_5 / GPT / GTIOC05_3B
    IOPORT_PIN_P125_PFC_0B_GTIOC01_3A      = (0x0BU << IOPORT_PFC_OFFSET), ///< P12_5 / GPT / GTIOC01_3A
    IOPORT_PIN_P125_PFC_0D_CMTW1_TOC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P12_5 / CMTW / CMTW1_TOC0
    IOPORT_PIN_P125_PFC_14_TXD2_SDA2_MOSI2 = (0x14U << IOPORT_PFC_OFFSET), ///< P12_5 / SCIn / TXD2_SDA2_MOSI2
    IOPORT_PIN_P125_PFC_15_DEE05           = (0x15U << IOPORT_PFC_OFFSET), ///< P12_5 / SCIEn / DEE05
    IOPORT_PIN_P125_PFC_1D_MDAT02          = (0x1DU << IOPORT_PFC_OFFSET), ///< P12_5 / DSMIFn / MDAT02
    IOPORT_PIN_P125_PFC_22_ENCIFOE05       = (0x22U << IOPORT_PFC_OFFSET), ///< P12_5 / ENCIFn / ENCIFOE05
    IOPORT_PIN_P125_PFC_25_HDSL10_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P12_5 / HDSLn / HDSL10_LINK
    IOPORT_PIN_P125_PFC_29_SD0_DATA3       = (0x29U << IOPORT_PFC_OFFSET), ///< P12_5 / SDHI / SD0_DATA3
    IOPORT_PIN_P126_PFC_04_D22             = (0x04U << IOPORT_PFC_OFFSET), ///< P12_6 / BSC / D22
    IOPORT_PIN_P126_PFC_09_GTIOC05_4A      = (0x09U << IOPORT_PFC_OFFSET), ///< P12_6 / GPT / GTIOC05_4A
    IOPORT_PIN_P126_PFC_0B_GTIOC01_3B      = (0x0BU << IOPORT_PFC_OFFSET), ///< P12_6 / GPT / GTIOC01_3B
    IOPORT_PIN_P126_PFC_0D_CMTW1_TIC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P12_6 / CMTW / CMTW1_TIC1
    IOPORT_PIN_P126_PFC_14_SS2_CTS2_RTS2   = (0x14U << IOPORT_PFC_OFFSET), ///< P12_6 / SCIn / SS2_CTS2_RTS2
    IOPORT_PIN_P126_PFC_15_TXDE05          = (0x15U << IOPORT_PFC_OFFSET), ///< P12_6 / SCIEn / TXDE05
    IOPORT_PIN_P126_PFC_1D_MCLK10          = (0x1DU << IOPORT_PFC_OFFSET), ///< P12_6 / DSMIFn / MCLK10
    IOPORT_PIN_P126_PFC_22_ENCIFDO05       = (0x22U << IOPORT_PFC_OFFSET), ///< P12_6 / ENCIFn / ENCIFDO05
    IOPORT_PIN_P126_PFC_25_HDSL10_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P12_6 / HDSLn / HDSL10_SMPL
    IOPORT_PIN_P126_PFC_29_SD0_DATA4       = (0x29U << IOPORT_PFC_OFFSET), ///< P12_6 / SDHI / SD0_DATA4
    IOPORT_PIN_P127_PFC_00_IRQ2            = (0x00U << IOPORT_PFC_OFFSET), ///< P12_7 / IRQ / IRQ2
    IOPORT_PIN_P127_PFC_04_D23             = (0x04U << IOPORT_PFC_OFFSET), ///< P12_7 / BSC / D23
    IOPORT_PIN_P127_PFC_09_GTIOC05_4B      = (0x09U << IOPORT_PFC_OFFSET), ///< P12_7 / GPT / GTIOC05_4B
    IOPORT_PIN_P127_PFC_0D_CMTW1_TOC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P12_7 / CMTW / CMTW1_TOC1
    IOPORT_PIN_P127_PFC_14_CTS2            = (0x14U << IOPORT_PFC_OFFSET), ///< P12_7 / SCIn / CTS2
    IOPORT_PIN_P127_PFC_15_RXDE05          = (0x15U << IOPORT_PFC_OFFSET), ///< P12_7 / SCIEn / RXDE05
    IOPORT_PIN_P127_PFC_1D_MDAT10          = (0x1DU << IOPORT_PFC_OFFSET), ///< P12_7 / DSMIFn / MDAT10
    IOPORT_PIN_P127_PFC_22_ENCIFDI05       = (0x22U << IOPORT_PFC_OFFSET), ///< P12_7 / ENCIFn / ENCIFDI05
    IOPORT_PIN_P127_PFC_25_HDSL10_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P12_7 / HDSLn / HDSL10_CLK1
    IOPORT_PIN_P127_PFC_29_SD0_DATA5       = (0x29U << IOPORT_PFC_OFFSET), ///< P12_7 / SDHI / SD0_DATA5
    IOPORT_PIN_P130_PFC_04_D24             = (0x04U << IOPORT_PFC_OFFSET), ///< P13_0 / BSC / D24
    IOPORT_PIN_P130_PFC_0B_GTIOC02_3A      = (0x0BU << IOPORT_PFC_OFFSET), ///< P13_0 / GPT / GTIOC02_3A
    IOPORT_PIN_P130_PFC_14_DE2             = (0x14U << IOPORT_PFC_OFFSET), ///< P13_0 / SCIn / DE2
    IOPORT_PIN_P130_PFC_15_SCKE08          = (0x15U << IOPORT_PFC_OFFSET), ///< P13_0 / SCIEn / SCKE08
    IOPORT_PIN_P130_PFC_16_SCKE03          = (0x16U << IOPORT_PFC_OFFSET), ///< P13_0 / SCIEn / SCKE03
    IOPORT_PIN_P130_PFC_1A_SPI_RSPCK3      = (0x1AU << IOPORT_PFC_OFFSET), ///< P13_0 / SPIn / SPI_RSPCK3
    IOPORT_PIN_P130_PFC_1D_MCLK00          = (0x1DU << IOPORT_PFC_OFFSET), ///< P13_0 / DSMIFn / MCLK00
    IOPORT_PIN_P130_PFC_22_ENCIFCK12       = (0x22U << IOPORT_PFC_OFFSET), ///< P13_0 / ENCIFn / ENCIFCK12
    IOPORT_PIN_P130_PFC_23_ENCIFCK03       = (0x23U << IOPORT_PFC_OFFSET), ///< P13_0 / ENCIFn / ENCIFCK03
    IOPORT_PIN_P130_PFC_25_HDSL10_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P13_0 / HDSLn / HDSL10_SEL1
    IOPORT_PIN_P130_PFC_29_SD0_DATA6       = (0x29U << IOPORT_PFC_OFFSET), ///< P13_0 / SDHI / SD0_DATA6
    IOPORT_PIN_P131_PFC_04_D25             = (0x04U << IOPORT_PFC_OFFSET), ///< P13_1 / BSC / D25
    IOPORT_PIN_P131_PFC_0B_GTIOC02_3B      = (0x0BU << IOPORT_PFC_OFFSET), ///< P13_1 / GPT / GTIOC02_3B
    IOPORT_PIN_P131_PFC_15_DEE08           = (0x15U << IOPORT_PFC_OFFSET), ///< P13_1 / SCIEn / DEE08
    IOPORT_PIN_P131_PFC_16_DEE03           = (0x16U << IOPORT_PFC_OFFSET), ///< P13_1 / SCIEn / DEE03
    IOPORT_PIN_P131_PFC_1A_SPI_MOSI3       = (0x1AU << IOPORT_PFC_OFFSET), ///< P13_1 / SPIn / SPI_MOSI3
    IOPORT_PIN_P131_PFC_1D_MDAT00          = (0x1DU << IOPORT_PFC_OFFSET), ///< P13_1 / DSMIFn / MDAT00
    IOPORT_PIN_P131_PFC_22_ENCIFOE12       = (0x22U << IOPORT_PFC_OFFSET), ///< P13_1 / ENCIFn / ENCIFOE12
    IOPORT_PIN_P131_PFC_23_ENCIFOE03       = (0x23U << IOPORT_PFC_OFFSET), ///< P13_1 / ENCIFn / ENCIFOE03
    IOPORT_PIN_P131_PFC_25_HDSL10_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P13_1 / HDSLn / HDSL10_MISO1
    IOPORT_PIN_P131_PFC_29_SD0_DATA7       = (0x29U << IOPORT_PFC_OFFSET), ///< P13_1 / SDHI / SD0_DATA7
    IOPORT_PIN_P132_PFC_00_IRQ3            = (0x00U << IOPORT_PFC_OFFSET), ///< P13_2 / IRQ / IRQ3
    IOPORT_PIN_P132_PFC_04_D26             = (0x04U << IOPORT_PFC_OFFSET), ///< P13_2 / BSC / D26
    IOPORT_PIN_P132_PFC_15_TXDE08          = (0x15U << IOPORT_PFC_OFFSET), ///< P13_2 / SCIEn / TXDE08
    IOPORT_PIN_P132_PFC_16_TXDE03          = (0x16U << IOPORT_PFC_OFFSET), ///< P13_2 / SCIEn / TXDE03
    IOPORT_PIN_P132_PFC_1A_SPI_MISO3       = (0x1AU << IOPORT_PFC_OFFSET), ///< P13_2 / SPIn / SPI_MISO3
    IOPORT_PIN_P132_PFC_1D_MCLK01          = (0x1DU << IOPORT_PFC_OFFSET), ///< P13_2 / DSMIFn / MCLK01
    IOPORT_PIN_P132_PFC_22_ENCIFDO12       = (0x22U << IOPORT_PFC_OFFSET), ///< P13_2 / ENCIFn / ENCIFDO12
    IOPORT_PIN_P132_PFC_23_ENCIFDO03       = (0x23U << IOPORT_PFC_OFFSET), ///< P13_2 / ENCIFn / ENCIFDO03
    IOPORT_PIN_P132_PFC_25_HDSL10_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P13_2 / HDSLn / HDSL10_MOSI1
    IOPORT_PIN_P132_PFC_29_SD0_RST         = (0x29U << IOPORT_PFC_OFFSET), ///< P13_2 / SDHI / SD0_RST
    IOPORT_PIN_P133_PFC_04_D27             = (0x04U << IOPORT_PFC_OFFSET), ///< P13_3 / BSC / D27
    IOPORT_PIN_P133_PFC_0B_GTIOC03_3A      = (0x0BU << IOPORT_PFC_OFFSET), ///< P13_3 / GPT / GTIOC03_3A
    IOPORT_PIN_P133_PFC_14_SCK3            = (0x14U << IOPORT_PFC_OFFSET), ///< P13_3 / SCIn / SCK3
    IOPORT_PIN_P133_PFC_15_RXDE08          = (0x15U << IOPORT_PFC_OFFSET), ///< P13_3 / SCIEn / RXDE08
    IOPORT_PIN_P133_PFC_16_RXDE03          = (0x16U << IOPORT_PFC_OFFSET), ///< P13_3 / SCIEn / RXDE03
    IOPORT_PIN_P133_PFC_1A_SPI_SSL30       = (0x1AU << IOPORT_PFC_OFFSET), ///< P13_3 / SPIn / SPI_SSL30
    IOPORT_PIN_P133_PFC_1D_MDAT01          = (0x1DU << IOPORT_PFC_OFFSET), ///< P13_3 / DSMIFn / MDAT01
    IOPORT_PIN_P133_PFC_22_ENCIFDI12       = (0x22U << IOPORT_PFC_OFFSET), ///< P13_3 / ENCIFn / ENCIFDI12
    IOPORT_PIN_P133_PFC_23_ENCIFDI03       = (0x23U << IOPORT_PFC_OFFSET), ///< P13_3 / ENCIFn / ENCIFDI03
    IOPORT_PIN_P133_PFC_25_HDSL10_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P13_3 / HDSLn / HDSL10_CLK2
    IOPORT_PIN_P134_PFC_04_D28             = (0x04U << IOPORT_PFC_OFFSET), ///< P13_4 / BSC / D28
    IOPORT_PIN_P134_PFC_0B_GTIOC03_3B      = (0x0BU << IOPORT_PFC_OFFSET), ///< P13_4 / GPT / GTIOC03_3B
    IOPORT_PIN_P134_PFC_14_RXD3_SCL3_MISO3 = (0x14U << IOPORT_PFC_OFFSET), ///< P13_4 / SCIn / RXD3_SCL3_MISO3
    IOPORT_PIN_P134_PFC_15_SCKE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P13_4 / SCIEn / SCKE09
    IOPORT_PIN_P134_PFC_1A_SPI_SSL31       = (0x1AU << IOPORT_PFC_OFFSET), ///< P13_4 / SPIn / SPI_SSL31
    IOPORT_PIN_P134_PFC_1D_MCLK40          = (0x1DU << IOPORT_PFC_OFFSET), ///< P13_4 / DSMIFn / MCLK40
    IOPORT_PIN_P134_PFC_22_ENCIFCK13       = (0x22U << IOPORT_PFC_OFFSET), ///< P13_4 / ENCIFn / ENCIFCK13
    IOPORT_PIN_P134_PFC_25_HDSL10_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P13_4 / HDSLn / HDSL10_SEL2
    IOPORT_PIN_P135_PFC_00_IRQ4            = (0x00U << IOPORT_PFC_OFFSET), ///< P13_5 / IRQ / IRQ4
    IOPORT_PIN_P135_PFC_04_D29             = (0x04U << IOPORT_PFC_OFFSET), ///< P13_5 / BSC / D29
    IOPORT_PIN_P135_PFC_09_GTIOC06_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P13_5 / GPT / GTIOC06_3A
    IOPORT_PIN_P135_PFC_14_TXD3_SDA3_MOSI3 = (0x14U << IOPORT_PFC_OFFSET), ///< P13_5 / SCIn / TXD3_SDA3_MOSI3
    IOPORT_PIN_P135_PFC_15_DEE09           = (0x15U << IOPORT_PFC_OFFSET), ///< P13_5 / SCIEn / DEE09
    IOPORT_PIN_P135_PFC_1A_SPI_SSL32       = (0x1AU << IOPORT_PFC_OFFSET), ///< P13_5 / SPIn / SPI_SSL32
    IOPORT_PIN_P135_PFC_1D_MDAT40          = (0x1DU << IOPORT_PFC_OFFSET), ///< P13_5 / DSMIFn / MDAT40
    IOPORT_PIN_P135_PFC_22_ENCIFOE13       = (0x22U << IOPORT_PFC_OFFSET), ///< P13_5 / ENCIFn / ENCIFOE13
    IOPORT_PIN_P135_PFC_25_HDSL10_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P13_5 / HDSLn / HDSL10_MISO2
    IOPORT_PIN_P136_PFC_04_D30             = (0x04U << IOPORT_PFC_OFFSET), ///< P13_6 / BSC / D30
    IOPORT_PIN_P136_PFC_09_GTIOC06_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P13_6 / GPT / GTIOC06_3B
    IOPORT_PIN_P136_PFC_0B_GTIOC04_3A      = (0x0BU << IOPORT_PFC_OFFSET), ///< P13_6 / GPT / GTIOC04_3A
    IOPORT_PIN_P136_PFC_14_SS3_CTS3_RTS3   = (0x14U << IOPORT_PFC_OFFSET), ///< P13_6 / SCIn / SS3_CTS3_RTS3
    IOPORT_PIN_P136_PFC_15_TXDE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P13_6 / SCIEn / TXDE09
    IOPORT_PIN_P136_PFC_1A_SPI_SSL23       = (0x1AU << IOPORT_PFC_OFFSET), ///< P13_6 / SPIn / SPI_SSL23
    IOPORT_PIN_P136_PFC_1D_MCLK41          = (0x1DU << IOPORT_PFC_OFFSET), ///< P13_6 / DSMIFn / MCLK41
    IOPORT_PIN_P136_PFC_22_ENCIFDO13       = (0x22U << IOPORT_PFC_OFFSET), ///< P13_6 / ENCIFn / ENCIFDO13
    IOPORT_PIN_P136_PFC_25_HDSL10_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P13_6 / HDSLn / HDSL10_MOSI2
    IOPORT_PIN_P137_PFC_00_IRQ14           = (0x00U << IOPORT_PFC_OFFSET), ///< P13_7 / IRQ / IRQ14
    IOPORT_PIN_P137_PFC_04_D31             = (0x04U << IOPORT_PFC_OFFSET), ///< P13_7 / BSC / D31
    IOPORT_PIN_P137_PFC_09_GTIOC06_4A      = (0x09U << IOPORT_PFC_OFFSET), ///< P13_7 / GPT / GTIOC06_4A
    IOPORT_PIN_P137_PFC_0B_GTIOC04_3B      = (0x0BU << IOPORT_PFC_OFFSET), ///< P13_7 / GPT / GTIOC04_3B
    IOPORT_PIN_P137_PFC_14_CTS3            = (0x14U << IOPORT_PFC_OFFSET), ///< P13_7 / SCIn / CTS3
    IOPORT_PIN_P137_PFC_15_RXDE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P13_7 / SCIEn / RXDE09
    IOPORT_PIN_P137_PFC_1D_MDAT41          = (0x1DU << IOPORT_PFC_OFFSET), ///< P13_7 / DSMIFn / MDAT41
    IOPORT_PIN_P137_PFC_22_ENCIFDI13       = (0x22U << IOPORT_PFC_OFFSET), ///< P13_7 / ENCIFn / ENCIFDI13
    IOPORT_PIN_P137_PFC_25_HDSL11_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P13_7 / HDSLn / HDSL11_LINK
    IOPORT_PIN_P140_PFC_00_IRQ5            = (0x00U << IOPORT_PFC_OFFSET), ///< P14_0 / IRQ / IRQ5
    IOPORT_PIN_P140_PFC_04_A0              = (0x04U << IOPORT_PFC_OFFSET), ///< P14_0 / BSC / A0
    IOPORT_PIN_P140_PFC_09_GTIOC06_4B      = (0x09U << IOPORT_PFC_OFFSET), ///< P14_0 / GPT / GTIOC06_4B
    IOPORT_PIN_P140_PFC_11_ETHSW_PTPOUT2   = (0x11U << IOPORT_PFC_OFFSET), ///< P14_0 / ETHER_ETHSW / ETHSW_PTPOUT2
    IOPORT_PIN_P140_PFC_12_ESC_SYNC0       = (0x12U << IOPORT_PFC_OFFSET), ///< P14_0 / ETHER_ESC / ESC_SYNC0
    IOPORT_PIN_P140_PFC_14_DE3             = (0x14U << IOPORT_PFC_OFFSET), ///< P14_0 / SCIn / DE3
    IOPORT_PIN_P140_PFC_1D_MCLK42          = (0x1DU << IOPORT_PFC_OFFSET), ///< P14_0 / DSMIFn / MCLK42
    IOPORT_PIN_P140_PFC_25_HDSL11_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P14_0 / HDSLn / HDSL11_SMPL
    IOPORT_PIN_P141_PFC_04_RD_WR           = (0x04U << IOPORT_PFC_OFFSET), ///< P14_1 / BSC / RD_WR
    IOPORT_PIN_P141_PFC_09_GTIOC06_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P14_1 / GPT / GTIOC06_0A
    IOPORT_PIN_P141_PFC_0A_GTIOC09_0A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P14_1 / GPT / GTIOC09_0A
    IOPORT_PIN_P141_PFC_0B_GTIOC05_3A      = (0x0BU << IOPORT_PFC_OFFSET), ///< P14_1 / GPT / GTIOC05_3A
    IOPORT_PIN_P141_PFC_0E_RTCAT1HZ        = (0x0EU << IOPORT_PFC_OFFSET), ///< P14_1 / RTC / RTCAT1HZ
    IOPORT_PIN_P141_PFC_14_SCK4            = (0x14U << IOPORT_PFC_OFFSET), ///< P14_1 / SCIn / SCK4
    IOPORT_PIN_P141_PFC_1D_MDAT42          = (0x1DU << IOPORT_PFC_OFFSET), ///< P14_1 / DSMIFn / MDAT42
    IOPORT_PIN_P141_PFC_24_DUEI02          = (0x24U << IOPORT_PFC_OFFSET), ///< P14_1 / ENDATn / DUEI02
    IOPORT_PIN_P141_PFC_25_HDSL11_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P14_1 / HDSLn / HDSL11_CLK1
    IOPORT_PIN_P141_PFC_28_DISP_DATAG1     = (0x28U << IOPORT_PFC_OFFSET), ///< P14_1 / LCDC / DISP_DATAG1
    IOPORT_PIN_P141_PFC_29_SD0_CD          = (0x29U << IOPORT_PFC_OFFSET), ///< P14_1 / SDHI / SD0_CD
    IOPORT_PIN_P142_PFC_04_BS              = (0x04U << IOPORT_PFC_OFFSET), ///< P14_2 / BSC / BS
    IOPORT_PIN_P142_PFC_09_GTIOC06_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P14_2 / GPT / GTIOC06_0B
    IOPORT_PIN_P142_PFC_0A_GTIOC09_0B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P14_2 / GPT / GTIOC09_0B
    IOPORT_PIN_P142_PFC_0B_GTIOC05_3B      = (0x0BU << IOPORT_PFC_OFFSET), ///< P14_2 / GPT / GTIOC05_3B
    IOPORT_PIN_P142_PFC_14_RXD4_SCL4_MISO4 = (0x14U << IOPORT_PFC_OFFSET), ///< P14_2 / SCIn / RXD4_SCL4_MISO4
    IOPORT_PIN_P142_PFC_15_SCKE00          = (0x15U << IOPORT_PFC_OFFSET), ///< P14_2 / SCIEn / SCKE00
    IOPORT_PIN_P142_PFC_22_ENCIFCK00       = (0x22U << IOPORT_PFC_OFFSET), ///< P14_2 / ENCIFn / ENCIFCK00
    IOPORT_PIN_P142_PFC_25_HDSL11_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P14_2 / HDSLn / HDSL11_SEL1
    IOPORT_PIN_P142_PFC_28_DISP_DATAG2     = (0x28U << IOPORT_PFC_OFFSET), ///< P14_2 / LCDC / DISP_DATAG2
    IOPORT_PIN_P142_PFC_29_SD0_WP          = (0x29U << IOPORT_PFC_OFFSET), ///< P14_2 / SDHI / SD0_WP
    IOPORT_PIN_P143_PFC_00_IRQ6            = (0x00U << IOPORT_PFC_OFFSET), ///< P14_3 / IRQ / IRQ6
    IOPORT_PIN_P143_PFC_05_DREQ            = (0x05U << IOPORT_PFC_OFFSET), ///< P14_3 / DMAC / DREQ
    IOPORT_PIN_P143_PFC_08_POE0            = (0x08U << IOPORT_PFC_OFFSET), ///< P14_3 / POE3 / POE0
    IOPORT_PIN_P143_PFC_09_GTIOC06_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P14_3 / GPT / GTIOC06_1A
    IOPORT_PIN_P143_PFC_0A_GTIOC09_1A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P14_3 / GPT / GTIOC09_1A
    IOPORT_PIN_P143_PFC_12_ESC_LINKACT2    = (0x12U << IOPORT_PFC_OFFSET), ///< P14_3 / ETHER_ESC / ESC_LINKACT2
    IOPORT_PIN_P143_PFC_14_TXD4_SDA4_MOSI4 = (0x14U << IOPORT_PFC_OFFSET), ///< P14_3 / SCIn / TXD4_SDA4_MOSI4
    IOPORT_PIN_P143_PFC_15_DEE00           = (0x15U << IOPORT_PFC_OFFSET), ///< P14_3 / SCIEn / DEE00
    IOPORT_PIN_P143_PFC_22_ENCIFOE00       = (0x22U << IOPORT_PFC_OFFSET), ///< P14_3 / ENCIFn / ENCIFOE00
    IOPORT_PIN_P143_PFC_25_HDSL11_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P14_3 / HDSLn / HDSL11_MISO1
    IOPORT_PIN_P143_PFC_28_DISP_DATAG3     = (0x28U << IOPORT_PFC_OFFSET), ///< P14_3 / LCDC / DISP_DATAG3
    IOPORT_PIN_P143_PFC_29_SD1_CD          = (0x29U << IOPORT_PFC_OFFSET), ///< P14_3 / SDHI / SD1_CD
    IOPORT_PIN_P144_PFC_05_DACK            = (0x05U << IOPORT_PFC_OFFSET), ///< P14_4 / DMAC / DACK
    IOPORT_PIN_P144_PFC_08_POE4            = (0x08U << IOPORT_PFC_OFFSET), ///< P14_4 / POE3 / POE4
    IOPORT_PIN_P144_PFC_09_GTIOC06_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P14_4 / GPT / GTIOC06_1B
    IOPORT_PIN_P144_PFC_0A_GTIOC09_1B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P14_4 / GPT / GTIOC09_1B
    IOPORT_PIN_P144_PFC_0B_GTIOC06_3A      = (0x0BU << IOPORT_PFC_OFFSET), ///< P14_4 / GPT / GTIOC06_3A
    IOPORT_PIN_P144_PFC_0D_CMTW0_TIC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P14_4 / CMTW / CMTW0_TIC0
    IOPORT_PIN_P144_PFC_12_ESC_IRQ         = (0x12U << IOPORT_PFC_OFFSET), ///< P14_4 / ETHER_ESC / ESC_IRQ
    IOPORT_PIN_P144_PFC_14_SS4_CTS4_RTS4   = (0x14U << IOPORT_PFC_OFFSET), ///< P14_4 / SCIn / SS4_CTS4_RTS4
    IOPORT_PIN_P144_PFC_15_TXDE00          = (0x15U << IOPORT_PFC_OFFSET), ///< P14_4 / SCIEn / TXDE00
    IOPORT_PIN_P144_PFC_21_MBX_HINT        = (0x21U << IOPORT_PFC_OFFSET), ///< P14_4 / MBXSEM / MBX_HINT
    IOPORT_PIN_P144_PFC_22_ENCIFDO00       = (0x22U << IOPORT_PFC_OFFSET), ///< P14_4 / ENCIFn / ENCIFDO00
    IOPORT_PIN_P144_PFC_25_HDSL11_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P14_4 / HDSLn / HDSL11_MOSI1
    IOPORT_PIN_P144_PFC_28_DISP_DATAG4     = (0x28U << IOPORT_PFC_OFFSET), ///< P14_4 / LCDC / DISP_DATAG4
    IOPORT_PIN_P144_PFC_29_SD1_WP          = (0x29U << IOPORT_PFC_OFFSET), ///< P14_4 / SDHI / SD1_WP
    IOPORT_PIN_P145_PFC_05_TEND            = (0x05U << IOPORT_PFC_OFFSET), ///< P14_5 / DMAC / TEND
    IOPORT_PIN_P145_PFC_08_POE8            = (0x08U << IOPORT_PFC_OFFSET), ///< P14_5 / POE3 / POE8
    IOPORT_PIN_P145_PFC_09_GTIOC06_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P14_5 / GPT / GTIOC06_2A
    IOPORT_PIN_P145_PFC_0A_GTIOC09_2A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P14_5 / GPT / GTIOC09_2A
    IOPORT_PIN_P145_PFC_0B_GTIOC06_3B      = (0x0BU << IOPORT_PFC_OFFSET), ///< P14_5 / GPT / GTIOC06_3B
    IOPORT_PIN_P145_PFC_0D_CMTW0_TOC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P14_5 / CMTW / CMTW0_TOC0
    IOPORT_PIN_P145_PFC_12_ESC_RESETOUT_N  = (0x12U << IOPORT_PFC_OFFSET), ///< P14_5 / ETHER_ESC / ESC_RESETOUT_N
    IOPORT_PIN_P145_PFC_14_CTS4            = (0x14U << IOPORT_PFC_OFFSET), ///< P14_5 / SCIn / CTS4
    IOPORT_PIN_P145_PFC_15_RXDE00          = (0x15U << IOPORT_PFC_OFFSET), ///< P14_5 / SCIEn / RXDE00
    IOPORT_PIN_P145_PFC_22_ENCIFDI00       = (0x22U << IOPORT_PFC_OFFSET), ///< P14_5 / ENCIFn / ENCIFDI00
    IOPORT_PIN_P145_PFC_25_HDSL11_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P14_5 / HDSLn / HDSL11_CLK2
    IOPORT_PIN_P145_PFC_28_DISP_DATAG5     = (0x28U << IOPORT_PFC_OFFSET), ///< P14_5 / LCDC / DISP_DATAG5
    IOPORT_PIN_P146_PFC_00_IRQ8            = (0x00U << IOPORT_PFC_OFFSET), ///< P14_6 / IRQ / IRQ8
    IOPORT_PIN_P146_PFC_08_POE10           = (0x08U << IOPORT_PFC_OFFSET), ///< P14_6 / POE3 / POE10
    IOPORT_PIN_P146_PFC_09_GTIOC06_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P14_6 / GPT / GTIOC06_2B
    IOPORT_PIN_P146_PFC_0A_GTIOC09_2B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P14_6 / GPT / GTIOC09_2B
    IOPORT_PIN_P146_PFC_0D_CMTW0_TIC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P14_6 / CMTW / CMTW0_TIC1
    IOPORT_PIN_P146_PFC_12_ESC_I2CCLK      = (0x12U << IOPORT_PFC_OFFSET), ///< P14_6 / ETHER_ESC / ESC_I2CCLK
    IOPORT_PIN_P146_PFC_14_DE4             = (0x14U << IOPORT_PFC_OFFSET), ///< P14_6 / SCIn / DE4
    IOPORT_PIN_P146_PFC_17_IIC_SCL0        = (0x17U << IOPORT_PFC_OFFSET), ///< P14_6 / IICn / IIC_SCL0
    IOPORT_PIN_P146_PFC_24_TST_OUT02       = (0x24U << IOPORT_PFC_OFFSET), ///< P14_6 / ENDATn / TST_OUT02
    IOPORT_PIN_P146_PFC_25_HDSL11_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P14_6 / HDSLn / HDSL11_SEL2
    IOPORT_PIN_P146_PFC_28_DISP_DATAG6     = (0x28U << IOPORT_PFC_OFFSET), ///< P14_6 / LCDC / DISP_DATAG6
    IOPORT_PIN_P146_PFC_29_SD0_PWEN        = (0x29U << IOPORT_PFC_OFFSET), ///< P14_6 / SDHI / SD0_PWEN
    IOPORT_PIN_P147_PFC_00_IRQ9            = (0x00U << IOPORT_PFC_OFFSET), ///< P14_7 / IRQ / IRQ9
    IOPORT_PIN_P147_PFC_08_POE11           = (0x08U << IOPORT_PFC_OFFSET), ///< P14_7 / POE3 / POE11
    IOPORT_PIN_P147_PFC_0A_GTIOC09_3A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P14_7 / GPT / GTIOC09_3A
    IOPORT_PIN_P147_PFC_0D_CMTW0_TOC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P14_7 / CMTW / CMTW0_TOC1
    IOPORT_PIN_P147_PFC_12_ESC_I2CDATA     = (0x12U << IOPORT_PFC_OFFSET), ///< P14_7 / ETHER_ESC / ESC_I2CDATA
    IOPORT_PIN_P147_PFC_17_IIC_SDA0        = (0x17U << IOPORT_PFC_OFFSET), ///< P14_7 / IICn / IIC_SDA0
    IOPORT_PIN_P147_PFC_1D_MCLK32          = (0x1DU << IOPORT_PFC_OFFSET), ///< P14_7 / DSMIFn / MCLK32
    IOPORT_PIN_P147_PFC_24_SI02            = (0x24U << IOPORT_PFC_OFFSET), ///< P14_7 / ENDATn / SI02
    IOPORT_PIN_P147_PFC_25_HDSL11_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P14_7 / HDSLn / HDSL11_MISO2
    IOPORT_PIN_P147_PFC_29_SD0_IOVS        = (0x29U << IOPORT_PFC_OFFSET), ///< P14_7 / SDHI / SD0_IOVS
    IOPORT_PIN_P150_PFC_0A_GTIOC09_3B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P15_0 / GPT / GTIOC09_3B
    IOPORT_PIN_P150_PFC_15_SCKE06          = (0x15U << IOPORT_PFC_OFFSET), ///< P15_0 / SCIEn / SCKE06
    IOPORT_PIN_P150_PFC_1D_MDAT32          = (0x1DU << IOPORT_PFC_OFFSET), ///< P15_0 / DSMIFn / MDAT32
    IOPORT_PIN_P150_PFC_22_ENCIFCK06       = (0x22U << IOPORT_PFC_OFFSET), ///< P15_0 / ENCIFn / ENCIFCK06
    IOPORT_PIN_P150_PFC_25_HDSL11_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P15_0 / HDSLn / HDSL11_MOSI2
    IOPORT_PIN_P151_PFC_0A_GTIOC09_4A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P15_1 / GPT / GTIOC09_4A
    IOPORT_PIN_P151_PFC_15_DEE06           = (0x15U << IOPORT_PFC_OFFSET), ///< P15_1 / SCIEn / DEE06
    IOPORT_PIN_P151_PFC_1D_MCLK40          = (0x1DU << IOPORT_PFC_OFFSET), ///< P15_1 / DSMIFn / MCLK40
    IOPORT_PIN_P151_PFC_22_ENCIFOE06       = (0x22U << IOPORT_PFC_OFFSET), ///< P15_1 / ENCIFn / ENCIFOE06
    IOPORT_PIN_P151_PFC_25_HDSL12_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P15_1 / HDSLn / HDSL12_LINK
    IOPORT_PIN_P152_PFC_0A_GTIOC09_4B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P15_2 / GPT / GTIOC09_4B
    IOPORT_PIN_P152_PFC_15_TXDE06          = (0x15U << IOPORT_PFC_OFFSET), ///< P15_2 / SCIEn / TXDE06
    IOPORT_PIN_P152_PFC_1D_MDAT40          = (0x1DU << IOPORT_PFC_OFFSET), ///< P15_2 / DSMIFn / MDAT40
    IOPORT_PIN_P152_PFC_22_ENCIFDO06       = (0x22U << IOPORT_PFC_OFFSET), ///< P15_2 / ENCIFn / ENCIFDO06
    IOPORT_PIN_P152_PFC_25_HDSL12_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P15_2 / HDSLn / HDSL12_SMPL
    IOPORT_PIN_P153_PFC_0A_GTIOC09_5A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P15_3 / GPT / GTIOC09_5A
    IOPORT_PIN_P153_PFC_15_RXDE06          = (0x15U << IOPORT_PFC_OFFSET), ///< P15_3 / SCIEn / RXDE06
    IOPORT_PIN_P153_PFC_1D_MCLK41          = (0x1DU << IOPORT_PFC_OFFSET), ///< P15_3 / DSMIFn / MCLK41
    IOPORT_PIN_P153_PFC_22_ENCIFDI06       = (0x22U << IOPORT_PFC_OFFSET), ///< P15_3 / ENCIFn / ENCIFDI06
    IOPORT_PIN_P153_PFC_25_HDSL12_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P15_3 / HDSLn / HDSL12_CLK1
    IOPORT_PIN_P154_PFC_0A_GTIOC09_5B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P15_4 / GPT / GTIOC09_5B
    IOPORT_PIN_P154_PFC_15_SCKE07          = (0x15U << IOPORT_PFC_OFFSET), ///< P15_4 / SCIEn / SCKE07
    IOPORT_PIN_P154_PFC_1D_MDAT41          = (0x1DU << IOPORT_PFC_OFFSET), ///< P15_4 / DSMIFn / MDAT41
    IOPORT_PIN_P154_PFC_22_ENCIFCK07       = (0x22U << IOPORT_PFC_OFFSET), ///< P15_4 / ENCIFn / ENCIFCK07
    IOPORT_PIN_P154_PFC_25_HDSL12_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P15_4 / HDSLn / HDSL12_SEL1
    IOPORT_PIN_P155_PFC_00_IRQ0            = (0x00U << IOPORT_PFC_OFFSET), ///< P15_5 / IRQ / IRQ0
    IOPORT_PIN_P155_PFC_0A_GTIOC09_6A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P15_5 / GPT / GTIOC09_6A
    IOPORT_PIN_P155_PFC_15_DEE07           = (0x15U << IOPORT_PFC_OFFSET), ///< P15_5 / SCIEn / DEE07
    IOPORT_PIN_P155_PFC_1D_MCLK42          = (0x1DU << IOPORT_PFC_OFFSET), ///< P15_5 / DSMIFn / MCLK42
    IOPORT_PIN_P155_PFC_22_ENCIFOE07       = (0x22U << IOPORT_PFC_OFFSET), ///< P15_5 / ENCIFn / ENCIFOE07
    IOPORT_PIN_P155_PFC_25_HDSL12_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P15_5 / HDSLn / HDSL12_MISO1
    IOPORT_PIN_P156_PFC_00_IRQ1            = (0x00U << IOPORT_PFC_OFFSET), ///< P15_6 / IRQ / IRQ1
    IOPORT_PIN_P156_PFC_0A_GTIOC09_6B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P15_6 / GPT / GTIOC09_6B
    IOPORT_PIN_P156_PFC_15_TXDE07          = (0x15U << IOPORT_PFC_OFFSET), ///< P15_6 / SCIEn / TXDE07
    IOPORT_PIN_P156_PFC_1D_MDAT42          = (0x1DU << IOPORT_PFC_OFFSET), ///< P15_6 / DSMIFn / MDAT42
    IOPORT_PIN_P156_PFC_22_ENCIFDO07       = (0x22U << IOPORT_PFC_OFFSET), ///< P15_6 / ENCIFn / ENCIFDO07
    IOPORT_PIN_P156_PFC_25_HDSL12_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P15_6 / HDSLn / HDSL12_MOSI1
    IOPORT_PIN_P157_PFC_14_SS5_CTS5_RTS5   = (0x14U << IOPORT_PFC_OFFSET), ///< P15_7 / SCIn / SS5_CTS5_RTS5
    IOPORT_PIN_P157_PFC_15_RXDE07          = (0x15U << IOPORT_PFC_OFFSET), ///< P15_7 / SCIEn / RXDE07
    IOPORT_PIN_P157_PFC_1D_MCLK50          = (0x1DU << IOPORT_PFC_OFFSET), ///< P15_7 / DSMIFn / MCLK50
    IOPORT_PIN_P157_PFC_22_ENCIFDI07       = (0x22U << IOPORT_PFC_OFFSET), ///< P15_7 / ENCIFn / ENCIFDI07
    IOPORT_PIN_P157_PFC_25_HDSL12_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P15_7 / HDSLn / HDSL12_CLK2
    IOPORT_PIN_P160_PFC_00_IRQ2            = (0x00U << IOPORT_PFC_OFFSET), ///< P16_0 / IRQ / IRQ2
    IOPORT_PIN_P160_PFC_14_CTS5            = (0x14U << IOPORT_PFC_OFFSET), ///< P16_0 / SCIn / CTS5
    IOPORT_PIN_P160_PFC_15_TXDE07          = (0x15U << IOPORT_PFC_OFFSET), ///< P16_0 / SCIEn / TXDE07
    IOPORT_PIN_P160_PFC_1D_MDAT50          = (0x1DU << IOPORT_PFC_OFFSET), ///< P16_0 / DSMIFn / MDAT50
    IOPORT_PIN_P160_PFC_24_DUEI03          = (0x24U << IOPORT_PFC_OFFSET), ///< P16_0 / ENDATn / DUEI03
    IOPORT_PIN_P160_PFC_25_HDSL12_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P16_0 / HDSLn / HDSL12_SEL2
    IOPORT_PIN_P161_PFC_14_DE5             = (0x14U << IOPORT_PFC_OFFSET), ///< P16_1 / SCIn / DE5
    IOPORT_PIN_P161_PFC_1D_MCLK51          = (0x1DU << IOPORT_PFC_OFFSET), ///< P16_1 / DSMIFn / MCLK51
    IOPORT_PIN_P161_PFC_24_TST_OUT03       = (0x24U << IOPORT_PFC_OFFSET), ///< P16_1 / ENDATn / TST_OUT03
    IOPORT_PIN_P161_PFC_25_HDSL12_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P16_1 / HDSLn / HDSL12_MISO2
    IOPORT_PIN_P162_PFC_14_SCK5            = (0x14U << IOPORT_PFC_OFFSET), ///< P16_2 / SCIn / SCK5
    IOPORT_PIN_P162_PFC_1D_MDAT51          = (0x1DU << IOPORT_PFC_OFFSET), ///< P16_2 / DSMIFn / MDAT51
    IOPORT_PIN_P162_PFC_24_SI03            = (0x24U << IOPORT_PFC_OFFSET), ///< P16_2 / ENDATn / SI03
    IOPORT_PIN_P162_PFC_25_HDSL12_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P16_2 / HDSLn / HDSL12_MOSI2
    IOPORT_PIN_P163_PFC_00_IRQ10           = (0x00U << IOPORT_PFC_OFFSET), ///< P16_3 / IRQ / IRQ10
    IOPORT_PIN_P163_PFC_0C_GTETRGSA        = (0x0CU << IOPORT_PFC_OFFSET), ///< P16_3 / POEG / GTETRGSA
    IOPORT_PIN_P163_PFC_12_ESC_LINKACT0    = (0x12U << IOPORT_PFC_OFFSET), ///< P16_3 / ETHER_ESC / ESC_LINKACT0
    IOPORT_PIN_P163_PFC_14_RXD5_SCL5_MISO5 = (0x14U << IOPORT_PFC_OFFSET), ///< P16_3 / SCIn / RXD5_SCL5_MISO5
    IOPORT_PIN_P163_PFC_24_DUEI04          = (0x24U << IOPORT_PFC_OFFSET), ///< P16_3 / ENDATn / DUEI04
    IOPORT_PIN_P163_PFC_25_HDSL13_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P16_3 / HDSLn / HDSL13_LINK
    IOPORT_PIN_P164_PFC_00_IRQ11           = (0x00U << IOPORT_PFC_OFFSET), ///< P16_4 / IRQ / IRQ11
    IOPORT_PIN_P164_PFC_0C_GTETRGSB        = (0x0CU << IOPORT_PFC_OFFSET), ///< P16_4 / POEG / GTETRGSB
    IOPORT_PIN_P164_PFC_12_ESC_LINKACT1    = (0x12U << IOPORT_PFC_OFFSET), ///< P16_4 / ETHER_ESC / ESC_LINKACT1
    IOPORT_PIN_P164_PFC_14_TXD5_SDA5_MOSI5 = (0x14U << IOPORT_PFC_OFFSET), ///< P16_4 / SCIn / TXD5_SDA5_MOSI5
    IOPORT_PIN_P164_PFC_24_TST_OUT04       = (0x24U << IOPORT_PFC_OFFSET), ///< P16_4 / ENDATn / TST_OUT04
    IOPORT_PIN_P164_PFC_25_HDSL13_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P16_4 / HDSLn / HDSL13_SMPL
    IOPORT_PIN_P165_PFC_09_GTIOC03_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P16_5 / GPT / GTIOC03_0A
    IOPORT_PIN_P165_PFC_24_SI04            = (0x24U << IOPORT_PFC_OFFSET), ///< P16_5 / ENDATn / SI04
    IOPORT_PIN_P165_PFC_25_HDSL13_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P16_5 / HDSLn / HDSL13_CLK1
    IOPORT_PIN_P165_PFC_29_SD1_CLK         = (0x29U << IOPORT_PFC_OFFSET), ///< P16_5 / SDHI / SD1_CLK
    IOPORT_PIN_P166_PFC_09_GTIOC03_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P16_6 / GPT / GTIOC03_0B
    IOPORT_PIN_P166_PFC_24_DUEI05          = (0x24U << IOPORT_PFC_OFFSET), ///< P16_6 / ENDATn / DUEI05
    IOPORT_PIN_P166_PFC_25_HDSL13_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P16_6 / HDSLn / HDSL13_SEL1
    IOPORT_PIN_P166_PFC_29_SD1_CMD         = (0x29U << IOPORT_PFC_OFFSET), ///< P16_6 / SDHI / SD1_CMD
    IOPORT_PIN_P167_PFC_09_GTIOC03_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P16_7 / GPT / GTIOC03_1A
    IOPORT_PIN_P167_PFC_24_TST_OUT05       = (0x24U << IOPORT_PFC_OFFSET), ///< P16_7 / ENDATn / TST_OUT05
    IOPORT_PIN_P167_PFC_25_HDSL13_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P16_7 / HDSLn / HDSL13_MISO1
    IOPORT_PIN_P167_PFC_29_SD1_DATA0       = (0x29U << IOPORT_PFC_OFFSET), ///< P16_7 / SDHI / SD1_DATA0
    IOPORT_PIN_P170_PFC_00_IRQ12           = (0x00U << IOPORT_PFC_OFFSET), ///< P17_0 / IRQ / IRQ12
    IOPORT_PIN_P170_PFC_09_GTIOC03_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P17_0 / GPT / GTIOC03_1B
    IOPORT_PIN_P170_PFC_24_SI05            = (0x24U << IOPORT_PFC_OFFSET), ///< P17_0 / ENDATn / SI05
    IOPORT_PIN_P170_PFC_25_HDSL13_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P17_0 / HDSLn / HDSL13_MOSI1
    IOPORT_PIN_P170_PFC_29_SD1_DATA1       = (0x29U << IOPORT_PFC_OFFSET), ///< P17_0 / SDHI / SD1_DATA1
    IOPORT_PIN_P171_PFC_00_IRQ13           = (0x00U << IOPORT_PFC_OFFSET), ///< P17_1 / IRQ / IRQ13
    IOPORT_PIN_P171_PFC_09_GTIOC03_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P17_1 / GPT / GTIOC03_2A
    IOPORT_PIN_P171_PFC_24_DUEI06          = (0x24U << IOPORT_PFC_OFFSET), ///< P17_1 / ENDATn / DUEI06
    IOPORT_PIN_P171_PFC_25_HDSL13_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P17_1 / HDSLn / HDSL13_CLK2
    IOPORT_PIN_P171_PFC_29_SD1_DATA2       = (0x29U << IOPORT_PFC_OFFSET), ///< P17_1 / SDHI / SD1_DATA2
    IOPORT_PIN_P172_PFC_00_IRQ14           = (0x00U << IOPORT_PFC_OFFSET), ///< P17_2 / IRQ / IRQ14
    IOPORT_PIN_P172_PFC_09_GTIOC03_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P17_2 / GPT / GTIOC03_2B
    IOPORT_PIN_P172_PFC_24_TST_OUT06       = (0x24U << IOPORT_PFC_OFFSET), ///< P17_2 / ENDATn / TST_OUT06
    IOPORT_PIN_P172_PFC_25_HDSL13_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P17_2 / HDSLn / HDSL13_SEL2
    IOPORT_PIN_P172_PFC_29_SD1_DATA3       = (0x29U << IOPORT_PFC_OFFSET), ///< P17_2 / SDHI / SD1_DATA3
    IOPORT_PIN_P173_PFC_00_IRQ15           = (0x00U << IOPORT_PFC_OFFSET), ///< P17_3 / IRQ / IRQ15
    IOPORT_PIN_P173_PFC_0C_GTETRGA         = (0x0CU << IOPORT_PFC_OFFSET), ///< P17_3 / POEG / GTETRGA
    IOPORT_PIN_P173_PFC_24_SI06            = (0x24U << IOPORT_PFC_OFFSET), ///< P17_3 / ENDATn / SI06
    IOPORT_PIN_P173_PFC_25_HDSL13_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P17_3 / HDSLn / HDSL13_MISO2
    IOPORT_PIN_P174_PFC_04_A6              = (0x04U << IOPORT_PFC_OFFSET), ///< P17_4 / BSC / A6
    IOPORT_PIN_P174_PFC_05_DREQ            = (0x05U << IOPORT_PFC_OFFSET), ///< P17_4 / DMAC / DREQ
    IOPORT_PIN_P174_PFC_0A_GTADSM00_0      = (0x0AU << IOPORT_PFC_OFFSET), ///< P17_4 / GPT / GTADSM00_0
    IOPORT_PIN_P174_PFC_0C_GTETRGB         = (0x0CU << IOPORT_PFC_OFFSET), ///< P17_4 / POEG / GTETRGB
    IOPORT_PIN_P174_PFC_0D_CMTW1_TIC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P17_4 / CMTW / CMTW1_TIC0
    IOPORT_PIN_P174_PFC_14_DE0             = (0x14U << IOPORT_PFC_OFFSET), ///< P17_4 / SCIn / DE0
    IOPORT_PIN_P174_PFC_19_CANRX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P17_4 / CANFDn / CANRX0
    IOPORT_PIN_P174_PFC_24_DUEI07          = (0x24U << IOPORT_PFC_OFFSET), ///< P17_4 / ENDATn / DUEI07
    IOPORT_PIN_P174_PFC_25_HDSL13_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P17_4 / HDSLn / HDSL13_MOSI2
    IOPORT_PIN_P174_PFC_29_SD1_CD          = (0x29U << IOPORT_PFC_OFFSET), ///< P17_4 / SDHI / SD1_CD
    IOPORT_PIN_P175_PFC_04_A7              = (0x04U << IOPORT_PFC_OFFSET), ///< P17_5 / BSC / A7
    IOPORT_PIN_P175_PFC_05_DACK            = (0x05U << IOPORT_PFC_OFFSET), ///< P17_5 / DMAC / DACK
    IOPORT_PIN_P175_PFC_0A_GTADSM00_1      = (0x0AU << IOPORT_PFC_OFFSET), ///< P17_5 / GPT / GTADSM00_1
    IOPORT_PIN_P175_PFC_0C_GTETRGC         = (0x0CU << IOPORT_PFC_OFFSET), ///< P17_5 / POEG / GTETRGC
    IOPORT_PIN_P175_PFC_0D_CMTW1_TOC0      = (0x0DU << IOPORT_PFC_OFFSET), ///< P17_5 / CMTW / CMTW1_TOC0
    IOPORT_PIN_P175_PFC_14_SCK0            = (0x14U << IOPORT_PFC_OFFSET), ///< P17_5 / SCIn / SCK0
    IOPORT_PIN_P175_PFC_19_CANTX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P17_5 / CANFDn / CANTX0
    IOPORT_PIN_P175_PFC_24_TST_OUT07       = (0x24U << IOPORT_PFC_OFFSET), ///< P17_5 / ENDATn / TST_OUT07
    IOPORT_PIN_P175_PFC_25_HDSL14_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P17_5 / HDSLn / HDSL14_LINK
    IOPORT_PIN_P175_PFC_29_SD1_WP          = (0x29U << IOPORT_PFC_OFFSET), ///< P17_5 / SDHI / SD1_WP
    IOPORT_PIN_P176_PFC_04_WE2             = (0x04U << IOPORT_PFC_OFFSET), ///< P17_6 / BSC / WE2
    IOPORT_PIN_P176_PFC_0A_GTADSM01_0      = (0x0AU << IOPORT_PFC_OFFSET), ///< P17_6 / GPT / GTADSM01_0
    IOPORT_PIN_P176_PFC_0C_GTETRGD         = (0x0CU << IOPORT_PFC_OFFSET), ///< P17_6 / POEG / GTETRGD
    IOPORT_PIN_P176_PFC_0D_CMTW1_TIC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P17_6 / CMTW / CMTW1_TIC1
    IOPORT_PIN_P176_PFC_11_ETHSW_PTPOUT0   = (0x11U << IOPORT_PFC_OFFSET), ///< P17_6 / ETHER_ETHSW / ETHSW_PTPOUT0
    IOPORT_PIN_P176_PFC_12_ESC_SYNC0       = (0x12U << IOPORT_PFC_OFFSET), ///< P17_6 / ETHER_ESC / ESC_SYNC0
    IOPORT_PIN_P176_PFC_14_RXD0_SCL0_MISO0 = (0x14U << IOPORT_PFC_OFFSET), ///< P17_6 / SCIn / RXD0_SCL0_MISO0
    IOPORT_PIN_P176_PFC_24_SI07            = (0x24U << IOPORT_PFC_OFFSET), ///< P17_6 / ENDATn / SI07
    IOPORT_PIN_P176_PFC_25_HDSL14_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P17_6 / HDSLn / HDSL14_SMPL
    IOPORT_PIN_P176_PFC_28_DISP_DATAG7     = (0x28U << IOPORT_PFC_OFFSET), ///< P17_6 / LCDC / DISP_DATAG7
    IOPORT_PIN_P176_PFC_29_SD1_PWEN        = (0x29U << IOPORT_PFC_OFFSET), ///< P17_6 / SDHI / SD1_PWEN
    IOPORT_PIN_P177_PFC_04_WE3_AH          = (0x04U << IOPORT_PFC_OFFSET), ///< P17_7 / BSC / WE3_AH
    IOPORT_PIN_P177_PFC_0A_GTADSM01_1      = (0x0AU << IOPORT_PFC_OFFSET), ///< P17_7 / GPT / GTADSM01_1
    IOPORT_PIN_P177_PFC_0D_CMTW1_TOC1      = (0x0DU << IOPORT_PFC_OFFSET), ///< P17_7 / CMTW / CMTW1_TOC1
    IOPORT_PIN_P177_PFC_11_ETHSW_PTPOUT1   = (0x11U << IOPORT_PFC_OFFSET), ///< P17_7 / ETHER_ETHSW / ETHSW_PTPOUT1
    IOPORT_PIN_P177_PFC_12_ESC_SYNC1       = (0x12U << IOPORT_PFC_OFFSET), ///< P17_7 / ETHER_ESC / ESC_SYNC1
    IOPORT_PIN_P177_PFC_14_TXD0_SDA0_MOSI0 = (0x14U << IOPORT_PFC_OFFSET), ///< P17_7 / SCIn / TXD0_SDA0_MOSI0
    IOPORT_PIN_P177_PFC_24_DUEI08          = (0x24U << IOPORT_PFC_OFFSET), ///< P17_7 / ENDATn / DUEI08
    IOPORT_PIN_P177_PFC_25_HDSL14_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P17_7 / HDSLn / HDSL14_CLK1
    IOPORT_PIN_P177_PFC_28_DISP_DATAB0     = (0x28U << IOPORT_PFC_OFFSET), ///< P17_7 / LCDC / DISP_DATAB0
    IOPORT_PIN_P177_PFC_29_SD1_IOVS        = (0x29U << IOPORT_PFC_OFFSET), ///< P17_7 / SDHI / SD1_IOVS
    IOPORT_PIN_P180_PFC_00_IRQ7            = (0x00U << IOPORT_PFC_OFFSET), ///< P18_0 / IRQ / IRQ7
    IOPORT_PIN_P180_PFC_04_A8              = (0x04U << IOPORT_PFC_OFFSET), ///< P18_0 / BSC / A8
    IOPORT_PIN_P180_PFC_05_TEND            = (0x05U << IOPORT_PFC_OFFSET), ///< P18_0 / DMAC / TEND
    IOPORT_PIN_P180_PFC_0A_GTADSM02_0      = (0x0AU << IOPORT_PFC_OFFSET), ///< P18_0 / GPT / GTADSM02_0
    IOPORT_PIN_P180_PFC_12_ESC_LEDRUN      = (0x12U << IOPORT_PFC_OFFSET), ///< P18_0 / ETHER_ESC / ESC_LEDRUN
    IOPORT_PIN_P180_PFC_14_SS0_CTS0_RTS0   = (0x14U << IOPORT_PFC_OFFSET), ///< P18_0 / SCIn / SS0_CTS0_RTS0
    IOPORT_PIN_P180_PFC_19_CANRXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P18_0 / CANFDn / CANRXDP0
    IOPORT_PIN_P180_PFC_24_TST_OUT08       = (0x24U << IOPORT_PFC_OFFSET), ///< P18_0 / ENDATn / TST_OUT08
    IOPORT_PIN_P180_PFC_25_HDSL14_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P18_0 / HDSLn / HDSL14_SEL1
    IOPORT_PIN_P180_PFC_28_DISP_DATAB1     = (0x28U << IOPORT_PFC_OFFSET), ///< P18_0 / LCDC / DISP_DATAB1
    IOPORT_PIN_P180_PFC_29_SD1_PWEN        = (0x29U << IOPORT_PFC_OFFSET), ///< P18_0 / SDHI / SD1_PWEN
    IOPORT_PIN_P181_PFC_00_IRQ15           = (0x00U << IOPORT_PFC_OFFSET), ///< P18_1 / IRQ / IRQ15
    IOPORT_PIN_P181_PFC_04_A9              = (0x04U << IOPORT_PFC_OFFSET), ///< P18_1 / BSC / A9
    IOPORT_PIN_P181_PFC_0A_GTADSM02_1      = (0x0AU << IOPORT_PFC_OFFSET), ///< P18_1 / GPT / GTADSM02_1
    IOPORT_PIN_P181_PFC_0B_GTIOC07_3A      = (0x0BU << IOPORT_PFC_OFFSET), ///< P18_1 / GPT / GTIOC07_3A
    IOPORT_PIN_P181_PFC_12_ESC_LEDERR      = (0x12U << IOPORT_PFC_OFFSET), ///< P18_1 / ETHER_ESC / ESC_LEDERR
    IOPORT_PIN_P181_PFC_14_CTS0            = (0x14U << IOPORT_PFC_OFFSET), ///< P18_1 / SCIn / CTS0
    IOPORT_PIN_P181_PFC_19_CANTXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P18_1 / CANFDn / CANTXDP0
    IOPORT_PIN_P181_PFC_24_SI08            = (0x24U << IOPORT_PFC_OFFSET), ///< P18_1 / ENDATn / SI08
    IOPORT_PIN_P181_PFC_25_HDSL14_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P18_1 / HDSLn / HDSL14_MISO1
    IOPORT_PIN_P181_PFC_28_DISP_DATAB2     = (0x28U << IOPORT_PFC_OFFSET), ///< P18_1 / LCDC / DISP_DATAB2
    IOPORT_PIN_P181_PFC_29_SD1_IOVS        = (0x29U << IOPORT_PFC_OFFSET), ///< P18_1 / SDHI / SD1_IOVS
    IOPORT_PIN_P182_PFC_00_SEI             = (0x00U << IOPORT_PFC_OFFSET), ///< P18_2 / IRQ / SEI
    IOPORT_PIN_P182_PFC_04_A10             = (0x04U << IOPORT_PFC_OFFSET), ///< P18_2 / BSC / A10
    IOPORT_PIN_P182_PFC_0A_GTADSM03_0      = (0x0AU << IOPORT_PFC_OFFSET), ///< P18_2 / GPT / GTADSM03_0
    IOPORT_PIN_P182_PFC_0B_GTIOC07_3B      = (0x0BU << IOPORT_PFC_OFFSET), ///< P18_2 / GPT / GTIOC07_3B
    IOPORT_PIN_P182_PFC_0F_ETH1_CRS        = (0x0FU << IOPORT_PFC_OFFSET), ///< P18_2 / ETHER_ETHn / ETH1_CRS
    IOPORT_PIN_P182_PFC_10_GMAC1_MDC       = (0x10U << IOPORT_PFC_OFFSET), ///< P18_2 / ETHER_GMACn / GMAC1_MDC
    IOPORT_PIN_P182_PFC_14_SCK1            = (0x14U << IOPORT_PFC_OFFSET), ///< P18_2 / SCIn / SCK1
    IOPORT_PIN_P182_PFC_19_CANRX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P18_2 / CANFDn / CANRX0
    IOPORT_PIN_P182_PFC_1D_MCLK10          = (0x1DU << IOPORT_PFC_OFFSET), ///< P18_2 / DSMIFn / MCLK10
    IOPORT_PIN_P182_PFC_25_HDSL14_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P18_2 / HDSLn / HDSL14_MOSI1
    IOPORT_PIN_P182_PFC_28_DISP_DATAB3     = (0x28U << IOPORT_PFC_OFFSET), ///< P18_2 / LCDC / DISP_DATAB3
    IOPORT_PIN_P182_PFC_29_SD1_PWEN        = (0x29U << IOPORT_PFC_OFFSET), ///< P18_2 / SDHI / SD1_PWEN
    IOPORT_PIN_P183_PFC_00_IRQ0            = (0x00U << IOPORT_PFC_OFFSET), ///< P18_3 / IRQ / IRQ0
    IOPORT_PIN_P183_PFC_04_A11             = (0x04U << IOPORT_PFC_OFFSET), ///< P18_3 / BSC / A11
    IOPORT_PIN_P183_PFC_0A_GTADSM03_1      = (0x0AU << IOPORT_PFC_OFFSET), ///< P18_3 / GPT / GTADSM03_1
    IOPORT_PIN_P183_PFC_0E_RTCAT1HZ        = (0x0EU << IOPORT_PFC_OFFSET), ///< P18_3 / RTC / RTCAT1HZ
    IOPORT_PIN_P183_PFC_0F_ETH1_COL        = (0x0FU << IOPORT_PFC_OFFSET), ///< P18_3 / ETHER_ETHn / ETH1_COL
    IOPORT_PIN_P183_PFC_10_GMAC1_MDIO      = (0x10U << IOPORT_PFC_OFFSET), ///< P18_3 / ETHER_GMACn / GMAC1_MDIO
    IOPORT_PIN_P183_PFC_14_RXD1_SCL1_MISO1 = (0x14U << IOPORT_PFC_OFFSET), ///< P18_3 / SCIn / RXD1_SCL1_MISO1
    IOPORT_PIN_P183_PFC_19_CANTX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P18_3 / CANFDn / CANTX0
    IOPORT_PIN_P183_PFC_1D_MDAT10          = (0x1DU << IOPORT_PFC_OFFSET), ///< P18_3 / DSMIFn / MDAT10
    IOPORT_PIN_P183_PFC_25_HDSL14_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P18_3 / HDSLn / HDSL14_CLK2
    IOPORT_PIN_P183_PFC_28_DISP_DATAB4     = (0x28U << IOPORT_PFC_OFFSET), ///< P18_3 / LCDC / DISP_DATAB4
    IOPORT_PIN_P183_PFC_29_SD1_IOVS        = (0x29U << IOPORT_PFC_OFFSET), ///< P18_3 / SDHI / SD1_IOVS
    IOPORT_PIN_P184_PFC_00_IRQ1            = (0x00U << IOPORT_PFC_OFFSET), ///< P18_4 / IRQ / IRQ1
    IOPORT_PIN_P184_PFC_04_A12             = (0x04U << IOPORT_PFC_OFFSET), ///< P18_4 / BSC / A12
    IOPORT_PIN_P184_PFC_09_GTIOC07_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P18_4 / GPT / GTIOC07_3A
    IOPORT_PIN_P184_PFC_0A_GTADSM04_0      = (0x0AU << IOPORT_PFC_OFFSET), ///< P18_4 / GPT / GTADSM04_0
    IOPORT_PIN_P184_PFC_12_ESC_LEDSTER     = (0x12U << IOPORT_PFC_OFFSET), ///< P18_4 / ETHER_ESC / ESC_LEDSTER
    IOPORT_PIN_P184_PFC_14_TXD1_SDA1_MOSI1 = (0x14U << IOPORT_PFC_OFFSET), ///< P18_4 / SCIn / TXD1_SDA1_MOSI1
    IOPORT_PIN_P184_PFC_15_SCKE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P18_4 / SCIEn / SCKE09
    IOPORT_PIN_P184_PFC_16_SCKE10          = (0x16U << IOPORT_PFC_OFFSET), ///< P18_4 / SCIEn / SCKE10
    IOPORT_PIN_P184_PFC_19_CANRX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P18_4 / CANFDn / CANRX1
    IOPORT_PIN_P184_PFC_1D_MCLK11          = (0x1DU << IOPORT_PFC_OFFSET), ///< P18_4 / DSMIFn / MCLK11
    IOPORT_PIN_P184_PFC_22_ENCIFCK13       = (0x22U << IOPORT_PFC_OFFSET), ///< P18_4 / ENCIFn / ENCIFCK13
    IOPORT_PIN_P184_PFC_23_ENCIFCK14       = (0x23U << IOPORT_PFC_OFFSET), ///< P18_4 / ENCIFn / ENCIFCK14
    IOPORT_PIN_P184_PFC_25_HDSL14_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P18_4 / HDSLn / HDSL14_SEL2
    IOPORT_PIN_P184_PFC_28_DISP_DATAB5     = (0x28U << IOPORT_PFC_OFFSET), ///< P18_4 / LCDC / DISP_DATAB5
    IOPORT_PIN_P185_PFC_00_IRQ2            = (0x00U << IOPORT_PFC_OFFSET), ///< P18_5 / IRQ / IRQ2
    IOPORT_PIN_P185_PFC_04_A13             = (0x04U << IOPORT_PFC_OFFSET), ///< P18_5 / BSC / A13
    IOPORT_PIN_P185_PFC_09_GTIOC07_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P18_5 / GPT / GTIOC07_3B
    IOPORT_PIN_P185_PFC_0A_GTADSM04_1      = (0x0AU << IOPORT_PFC_OFFSET), ///< P18_5 / GPT / GTADSM04_1
    IOPORT_PIN_P185_PFC_14_SS1_CTS1_RTS1   = (0x14U << IOPORT_PFC_OFFSET), ///< P18_5 / SCIn / SS1_CTS1_RTS1
    IOPORT_PIN_P185_PFC_15_DEE09           = (0x15U << IOPORT_PFC_OFFSET), ///< P18_5 / SCIEn / DEE09
    IOPORT_PIN_P185_PFC_16_DEE10           = (0x16U << IOPORT_PFC_OFFSET), ///< P18_5 / SCIEn / DEE10
    IOPORT_PIN_P185_PFC_19_CANTX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P18_5 / CANFDn / CANTX1
    IOPORT_PIN_P185_PFC_1D_MDAT11          = (0x1DU << IOPORT_PFC_OFFSET), ///< P18_5 / DSMIFn / MDAT11
    IOPORT_PIN_P185_PFC_22_ENCIFOE13       = (0x22U << IOPORT_PFC_OFFSET), ///< P18_5 / ENCIFn / ENCIFOE13
    IOPORT_PIN_P185_PFC_23_ENCIFOE14       = (0x23U << IOPORT_PFC_OFFSET), ///< P18_5 / ENCIFn / ENCIFOE14
    IOPORT_PIN_P185_PFC_25_HDSL14_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P18_5 / HDSLn / HDSL14_MISO2
    IOPORT_PIN_P185_PFC_28_DISP_DATAB6     = (0x28U << IOPORT_PFC_OFFSET), ///< P18_5 / LCDC / DISP_DATAB6
    IOPORT_PIN_P186_PFC_00_IRQ3            = (0x00U << IOPORT_PFC_OFFSET), ///< P18_6 / IRQ / IRQ3
    IOPORT_PIN_P186_PFC_04_A14             = (0x04U << IOPORT_PFC_OFFSET), ///< P18_6 / BSC / A14
    IOPORT_PIN_P186_PFC_09_GTIOC07_4A      = (0x09U << IOPORT_PFC_OFFSET), ///< P18_6 / GPT / GTIOC07_4A
    IOPORT_PIN_P186_PFC_0A_GTADSM05_0      = (0x0AU << IOPORT_PFC_OFFSET), ///< P18_6 / GPT / GTADSM05_0
    IOPORT_PIN_P186_PFC_14_CTS1            = (0x14U << IOPORT_PFC_OFFSET), ///< P18_6 / SCIn / CTS1
    IOPORT_PIN_P186_PFC_15_TXDE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P18_6 / SCIEn / TXDE09
    IOPORT_PIN_P186_PFC_16_TXDE10          = (0x16U << IOPORT_PFC_OFFSET), ///< P18_6 / SCIEn / TXDE10
    IOPORT_PIN_P186_PFC_19_CANRXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P18_6 / CANFDn / CANRXDP1
    IOPORT_PIN_P186_PFC_1D_MCLK12          = (0x1DU << IOPORT_PFC_OFFSET), ///< P18_6 / DSMIFn / MCLK12
    IOPORT_PIN_P186_PFC_22_ENCIFDO13       = (0x22U << IOPORT_PFC_OFFSET), ///< P18_6 / ENCIFn / ENCIFDO13
    IOPORT_PIN_P186_PFC_23_ENCIFDO14       = (0x23U << IOPORT_PFC_OFFSET), ///< P18_6 / ENCIFn / ENCIFDO14
    IOPORT_PIN_P186_PFC_25_HDSL14_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P18_6 / HDSLn / HDSL14_MOSI2
    IOPORT_PIN_P186_PFC_28_DISP_DATAB7     = (0x28U << IOPORT_PFC_OFFSET), ///< P18_6 / LCDC / DISP_DATAB7
    IOPORT_PIN_P187_PFC_00_IRQ4            = (0x00U << IOPORT_PFC_OFFSET), ///< P18_7 / IRQ / IRQ4
    IOPORT_PIN_P187_PFC_04_A15             = (0x04U << IOPORT_PFC_OFFSET), ///< P18_7 / BSC / A15
    IOPORT_PIN_P187_PFC_09_GTIOC07_4B      = (0x09U << IOPORT_PFC_OFFSET), ///< P18_7 / GPT / GTIOC07_4B
    IOPORT_PIN_P187_PFC_0A_GTADSM05_1      = (0x0AU << IOPORT_PFC_OFFSET), ///< P18_7 / GPT / GTADSM05_1
    IOPORT_PIN_P187_PFC_11_ETHSW_PTPOUT3   = (0x11U << IOPORT_PFC_OFFSET), ///< P18_7 / ETHER_ETHSW / ETHSW_PTPOUT3
    IOPORT_PIN_P187_PFC_12_ESC_SYNC1       = (0x12U << IOPORT_PFC_OFFSET), ///< P18_7 / ETHER_ESC / ESC_SYNC1
    IOPORT_PIN_P187_PFC_14_DE1             = (0x14U << IOPORT_PFC_OFFSET), ///< P18_7 / SCIn / DE1
    IOPORT_PIN_P187_PFC_15_RXDE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P18_7 / SCIEn / RXDE09
    IOPORT_PIN_P187_PFC_16_RXDE10          = (0x16U << IOPORT_PFC_OFFSET), ///< P18_7 / SCIEn / RXDE10
    IOPORT_PIN_P187_PFC_19_CANTXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P18_7 / CANFDn / CANTXDP1
    IOPORT_PIN_P187_PFC_1D_MDAT12          = (0x1DU << IOPORT_PFC_OFFSET), ///< P18_7 / DSMIFn / MDAT12
    IOPORT_PIN_P187_PFC_22_ENCIFDI13       = (0x22U << IOPORT_PFC_OFFSET), ///< P18_7 / ENCIFn / ENCIFDI13
    IOPORT_PIN_P187_PFC_23_ENCIFDI14       = (0x23U << IOPORT_PFC_OFFSET), ///< P18_7 / ENCIFn / ENCIFDI14
    IOPORT_PIN_P187_PFC_25_HDSL15_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P18_7 / HDSLn / HDSL15_LINK
    IOPORT_PIN_P190_PFC_09_GTIOC07_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P19_0 / GPT / GTIOC07_0A
    IOPORT_PIN_P190_PFC_24_DUEI09          = (0x24U << IOPORT_PFC_OFFSET), ///< P19_0 / ENDATn / DUEI09
    IOPORT_PIN_P190_PFC_25_HDSL15_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P19_0 / HDSLn / HDSL15_SMPL
    IOPORT_PIN_P191_PFC_09_GTIOC07_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P19_1 / GPT / GTIOC07_0B
    IOPORT_PIN_P191_PFC_24_TST_OUT09       = (0x24U << IOPORT_PFC_OFFSET), ///< P19_1 / ENDATn / TST_OUT09
    IOPORT_PIN_P191_PFC_25_HDSL15_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P19_1 / HDSLn / HDSL15_CLK1
    IOPORT_PIN_P192_PFC_09_GTIOC07_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P19_2 / GPT / GTIOC07_1A
    IOPORT_PIN_P192_PFC_24_SI09            = (0x24U << IOPORT_PFC_OFFSET), ///< P19_2 / ENDATn / SI09
    IOPORT_PIN_P192_PFC_25_HDSL15_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P19_2 / HDSLn / HDSL15_SEL1
    IOPORT_PIN_P193_PFC_09_GTIOC07_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P19_3 / GPT / GTIOC07_1B
    IOPORT_PIN_P193_PFC_24_DUEI10          = (0x24U << IOPORT_PFC_OFFSET), ///< P19_3 / ENDATn / DUEI10
    IOPORT_PIN_P193_PFC_25_HDSL15_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P19_3 / HDSLn / HDSL15_MISO1
    IOPORT_PIN_P194_PFC_09_GTIOC07_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P19_4 / GPT / GTIOC07_2A
    IOPORT_PIN_P194_PFC_24_TST_OUT10       = (0x24U << IOPORT_PFC_OFFSET), ///< P19_4 / ENDATn / TST_OUT10
    IOPORT_PIN_P194_PFC_25_HDSL15_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P19_4 / HDSLn / HDSL15_MOSI1
    IOPORT_PIN_P195_PFC_09_GTIOC07_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P19_5 / GPT / GTIOC07_2B
    IOPORT_PIN_P195_PFC_24_SI10            = (0x24U << IOPORT_PFC_OFFSET), ///< P19_5 / ENDATn / SI10
    IOPORT_PIN_P195_PFC_25_HDSL15_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P19_5 / HDSLn / HDSL15_CLK2
    IOPORT_PIN_P196_PFC_1D_MCLK52          = (0x1DU << IOPORT_PFC_OFFSET), ///< P19_6 / DSMIFn / MCLK52
    IOPORT_PIN_P196_PFC_25_HDSL15_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P19_6 / HDSLn / HDSL15_SEL2
    IOPORT_PIN_P197_PFC_1D_MDAT52          = (0x1DU << IOPORT_PFC_OFFSET), ///< P19_7 / DSMIFn / MDAT52
    IOPORT_PIN_P197_PFC_25_HDSL15_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P19_7 / HDSLn / HDSL15_MISO2
    IOPORT_PIN_P200_PFC_0F_ETH0_TXCLK      = (0x0FU << IOPORT_PFC_OFFSET), ///< P20_0 / ETHER_ETHn / ETH0_TXCLK
    IOPORT_PIN_P200_PFC_25_HDSL15_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P20_0 / HDSLn / HDSL15_MOSI2
    IOPORT_PIN_P201_PFC_0F_ETH0_TXD0       = (0x0FU << IOPORT_PFC_OFFSET), ///< P20_1 / ETHER_ETHn / ETH0_TXD0
    IOPORT_PIN_P202_PFC_0F_ETH0_TXD1       = (0x0FU << IOPORT_PFC_OFFSET), ///< P20_2 / ETHER_ETHn / ETH0_TXD1
    IOPORT_PIN_P203_PFC_0F_ETH0_TXD2       = (0x0FU << IOPORT_PFC_OFFSET), ///< P20_3 / ETHER_ETHn / ETH0_TXD2
    IOPORT_PIN_P203_PFC_19_CANRX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P20_3 / CANFDn / CANRX0
    IOPORT_PIN_P204_PFC_0F_ETH0_TXD3       = (0x0FU << IOPORT_PFC_OFFSET), ///< P20_4 / ETHER_ETHn / ETH0_TXD3
    IOPORT_PIN_P204_PFC_19_CANTX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P20_4 / CANFDn / CANTX0
    IOPORT_PIN_P205_PFC_0F_ETH0_TXEN       = (0x0FU << IOPORT_PFC_OFFSET), ///< P20_5 / ETHER_ETHn / ETH0_TXEN
    IOPORT_PIN_P205_PFC_24_DUEI11          = (0x24U << IOPORT_PFC_OFFSET), ///< P20_5 / ENDATn / DUEI11
    IOPORT_PIN_P205_PFC_25_HDSL00_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P20_5 / HDSLn / HDSL00_LINK
    IOPORT_PIN_P206_PFC_0F_ETH0_RXCLK      = (0x0FU << IOPORT_PFC_OFFSET), ///< P20_6 / ETHER_ETHn / ETH0_RXCLK
    IOPORT_PIN_P206_PFC_24_TST_OUT11       = (0x24U << IOPORT_PFC_OFFSET), ///< P20_6 / ENDATn / TST_OUT11
    IOPORT_PIN_P206_PFC_25_HDSL00_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P20_6 / HDSLn / HDSL00_SMPL
    IOPORT_PIN_P207_PFC_0F_ETH0_RXD0       = (0x0FU << IOPORT_PFC_OFFSET), ///< P20_7 / ETHER_ETHn / ETH0_RXD0
    IOPORT_PIN_P207_PFC_24_SI11            = (0x24U << IOPORT_PFC_OFFSET), ///< P20_7 / ENDATn / SI11
    IOPORT_PIN_P207_PFC_25_HDSL00_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P20_7 / HDSLn / HDSL00_CLK1
    IOPORT_PIN_P210_PFC_0F_ETH0_RXD1       = (0x0FU << IOPORT_PFC_OFFSET), ///< P21_0 / ETHER_ETHn / ETH0_RXD1
    IOPORT_PIN_P210_PFC_24_DUEI12          = (0x24U << IOPORT_PFC_OFFSET), ///< P21_0 / ENDATn / DUEI12
    IOPORT_PIN_P210_PFC_25_HDSL00_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P21_0 / HDSLn / HDSL00_SEL1
    IOPORT_PIN_P211_PFC_0F_ETH0_RXD2       = (0x0FU << IOPORT_PFC_OFFSET), ///< P21_1 / ETHER_ETHn / ETH0_RXD2
    IOPORT_PIN_P211_PFC_19_CANRXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P21_1 / CANFDn / CANRXDP0
    IOPORT_PIN_P211_PFC_24_TST_OUT12       = (0x24U << IOPORT_PFC_OFFSET), ///< P21_1 / ENDATn / TST_OUT12
    IOPORT_PIN_P211_PFC_25_HDSL00_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P21_1 / HDSLn / HDSL00_MISO1
    IOPORT_PIN_P212_PFC_0F_ETH0_RXD3       = (0x0FU << IOPORT_PFC_OFFSET), ///< P21_2 / ETHER_ETHn / ETH0_RXD3
    IOPORT_PIN_P212_PFC_19_CANTXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P21_2 / CANFDn / CANTXDP0
    IOPORT_PIN_P212_PFC_24_SI12            = (0x24U << IOPORT_PFC_OFFSET), ///< P21_2 / ENDATn / SI12
    IOPORT_PIN_P212_PFC_25_HDSL00_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P21_2 / HDSLn / HDSL00_MOSI1
    IOPORT_PIN_P213_PFC_0F_ETH0_RXDV       = (0x0FU << IOPORT_PFC_OFFSET), ///< P21_3 / ETHER_ETHn / ETH0_RXDV
    IOPORT_PIN_P213_PFC_24_DUEI13          = (0x24U << IOPORT_PFC_OFFSET), ///< P21_3 / ENDATn / DUEI13
    IOPORT_PIN_P213_PFC_25_HDSL00_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P21_3 / HDSLn / HDSL00_CLK2
    IOPORT_PIN_P214_PFC_10_GMAC0_MDC       = (0x10U << IOPORT_PFC_OFFSET), ///< P21_4 / ETHER_GMACn / GMAC0_MDC
    IOPORT_PIN_P214_PFC_11_ETHSW_MDC       = (0x11U << IOPORT_PFC_OFFSET), ///< P21_4 / ETHER_ETHSW / ETHSW_MDC
    IOPORT_PIN_P214_PFC_12_ESC_MDC         = (0x12U << IOPORT_PFC_OFFSET), ///< P21_4 / ETHER_ESC / ESC_MDC
    IOPORT_PIN_P214_PFC_19_CANRX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P21_4 / CANFDn / CANRX1
    IOPORT_PIN_P214_PFC_24_TST_OUT13       = (0x24U << IOPORT_PFC_OFFSET), ///< P21_4 / ENDATn / TST_OUT13
    IOPORT_PIN_P214_PFC_25_HDSL00_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P21_4 / HDSLn / HDSL00_SEL2
    IOPORT_PIN_P215_PFC_10_GMAC0_MDIO      = (0x10U << IOPORT_PFC_OFFSET), ///< P21_5 / ETHER_GMACn / GMAC0_MDIO
    IOPORT_PIN_P215_PFC_11_ETHSW_MDIO      = (0x11U << IOPORT_PFC_OFFSET), ///< P21_5 / ETHER_ETHSW / ETHSW_MDIO
    IOPORT_PIN_P215_PFC_12_ESC_MDIO        = (0x12U << IOPORT_PFC_OFFSET), ///< P21_5 / ETHER_ESC / ESC_MDIO
    IOPORT_PIN_P215_PFC_19_CANTX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P21_5 / CANFDn / CANTX1
    IOPORT_PIN_P215_PFC_24_SI13            = (0x24U << IOPORT_PFC_OFFSET), ///< P21_5 / ENDATn / SI13
    IOPORT_PIN_P215_PFC_25_HDSL00_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P21_5 / HDSLn / HDSL00_MISO2
    IOPORT_PIN_P216_PFC_11_ETHSW_PHYLINK0  = (0x11U << IOPORT_PFC_OFFSET), ///< P21_6 / ETHER_ETHSW / ETHSW_PHYLINK0
    IOPORT_PIN_P216_PFC_12_ESC_PHYLINK0    = (0x12U << IOPORT_PFC_OFFSET), ///< P21_6 / ETHER_ESC / ESC_PHYLINK0
    IOPORT_PIN_P216_PFC_19_CANRXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P21_6 / CANFDn / CANRXDP1
    IOPORT_PIN_P216_PFC_25_HDSL00_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P21_6 / HDSLn / HDSL00_MOSI2
    IOPORT_PIN_P217_PFC_02_ETH0_REFCLK     = (0x02U << IOPORT_PFC_OFFSET), ///< P21_7 / ETHER_ETHn / ETH0_REFCLK
    IOPORT_PIN_P217_PFC_03_RMII0_REFCLK    = (0x03U << IOPORT_PFC_OFFSET), ///< P21_7 / ETHER_ETHn / RMII0_REFCLK
    IOPORT_PIN_P217_PFC_19_CANTXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P21_7 / CANFDn / CANTXDP1
    IOPORT_PIN_P217_PFC_25_HDSL01_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P21_7 / HDSLn / HDSL01_LINK
    IOPORT_PIN_P220_PFC_00_IRQ11           = (0x00U << IOPORT_PFC_OFFSET), ///< P22_0 / IRQ / IRQ11
    IOPORT_PIN_P220_PFC_25_HDSL01_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P22_0 / HDSLn / HDSL01_SMPL
    IOPORT_PIN_P221_PFC_0C_GTETRGA         = (0x0CU << IOPORT_PFC_OFFSET), ///< P22_1 / POEG / GTETRGA
    IOPORT_PIN_P221_PFC_0F_ETH0_TXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P22_1 / ETHER_ETHn / ETH0_TXER
    IOPORT_PIN_P221_PFC_14_TXD5_SDA5_MOSI5 = (0x14U << IOPORT_PFC_OFFSET), ///< P22_1 / SCIn / TXD5_SDA5_MOSI5
    IOPORT_PIN_P221_PFC_19_CANTX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P22_1 / CANFDn / CANTX0
    IOPORT_PIN_P221_PFC_25_HDSL01_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P22_1 / HDSLn / HDSL01_CLK1
    IOPORT_PIN_P222_PFC_04_A23             = (0x04U << IOPORT_PFC_OFFSET), ///< P22_2 / BSC / A23
    IOPORT_PIN_P222_PFC_0C_GTETRGB         = (0x0CU << IOPORT_PFC_OFFSET), ///< P22_2 / POEG / GTETRGB
    IOPORT_PIN_P222_PFC_0F_ETH0_RXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P22_2 / ETHER_ETHn / ETH0_RXER
    IOPORT_PIN_P222_PFC_14_RXD5_SCL5_MISO5 = (0x14U << IOPORT_PFC_OFFSET), ///< P22_2 / SCIn / RXD5_SCL5_MISO5
    IOPORT_PIN_P222_PFC_19_CANRX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P22_2 / CANFDn / CANRX0
    IOPORT_PIN_P222_PFC_25_HDSL01_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P22_2 / HDSLn / HDSL01_SEL1
    IOPORT_PIN_P223_PFC_00_IRQ5            = (0x00U << IOPORT_PFC_OFFSET), ///< P22_3 / IRQ / IRQ5
    IOPORT_PIN_P223_PFC_04_A22             = (0x04U << IOPORT_PFC_OFFSET), ///< P22_3 / BSC / A22
    IOPORT_PIN_P223_PFC_0C_GTETRGC         = (0x0CU << IOPORT_PFC_OFFSET), ///< P22_3 / POEG / GTETRGC
    IOPORT_PIN_P223_PFC_0F_ETH0_CRS        = (0x0FU << IOPORT_PFC_OFFSET), ///< P22_3 / ETHER_ETHn / ETH0_CRS
    IOPORT_PIN_P223_PFC_14_SCK5            = (0x14U << IOPORT_PFC_OFFSET), ///< P22_3 / SCIn / SCK5
    IOPORT_PIN_P223_PFC_19_CANRXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P22_3 / CANFDn / CANRXDP0
    IOPORT_PIN_P223_PFC_24_DUEI14          = (0x24U << IOPORT_PFC_OFFSET), ///< P22_3 / ENDATn / DUEI14
    IOPORT_PIN_P223_PFC_25_HDSL01_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P22_3 / HDSLn / HDSL01_MISO1
    IOPORT_PIN_P224_PFC_00_IRQ6            = (0x00U << IOPORT_PFC_OFFSET), ///< P22_4 / IRQ / IRQ6
    IOPORT_PIN_P224_PFC_04_A21             = (0x04U << IOPORT_PFC_OFFSET), ///< P22_4 / BSC / A21
    IOPORT_PIN_P224_PFC_0C_GTETRGD         = (0x0CU << IOPORT_PFC_OFFSET), ///< P22_4 / POEG / GTETRGD
    IOPORT_PIN_P224_PFC_0F_ETH0_COL        = (0x0FU << IOPORT_PFC_OFFSET), ///< P22_4 / ETHER_ETHn / ETH0_COL
    IOPORT_PIN_P224_PFC_14_SS5_CTS5_RTS5   = (0x14U << IOPORT_PFC_OFFSET), ///< P22_4 / SCIn / SS5_CTS5_RTS5
    IOPORT_PIN_P224_PFC_19_CANTXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P22_4 / CANFDn / CANTXDP0
    IOPORT_PIN_P224_PFC_24_TST_OUT14       = (0x24U << IOPORT_PFC_OFFSET), ///< P22_4 / ENDATn / TST_OUT14
    IOPORT_PIN_P224_PFC_25_HDSL01_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P22_4 / HDSLn / HDSL01_MOSI1
    IOPORT_PIN_P225_PFC_00_IRQ7            = (0x00U << IOPORT_PFC_OFFSET), ///< P22_5 / IRQ / IRQ7
    IOPORT_PIN_P225_PFC_04_A20             = (0x04U << IOPORT_PFC_OFFSET), ///< P22_5 / BSC / A20
    IOPORT_PIN_P225_PFC_0C_GTETRGSA        = (0x0CU << IOPORT_PFC_OFFSET), ///< P22_5 / POEG / GTETRGSA
    IOPORT_PIN_P225_PFC_10_GMAC0_PTPTRG0   = (0x10U << IOPORT_PFC_OFFSET), ///< P22_5 / ETHER_GMACn / GMAC0_PTPTRG0
    IOPORT_PIN_P225_PFC_12_ESC_LATCH0      = (0x12U << IOPORT_PFC_OFFSET), ///< P22_5 / ETHER_ESC / ESC_LATCH0
    IOPORT_PIN_P225_PFC_14_CTS5            = (0x14U << IOPORT_PFC_OFFSET), ///< P22_5 / SCIn / CTS5
    IOPORT_PIN_P225_PFC_19_CANRX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P22_5 / CANFDn / CANRX1
    IOPORT_PIN_P225_PFC_24_SI14            = (0x24U << IOPORT_PFC_OFFSET), ///< P22_5 / ENDATn / SI14
    IOPORT_PIN_P225_PFC_25_HDSL01_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P22_5 / HDSLn / HDSL01_CLK2
    IOPORT_PIN_P225_PFC_29_SD0_CD          = (0x29U << IOPORT_PFC_OFFSET), ///< P22_5 / SDHI / SD0_CD
    IOPORT_PIN_P226_PFC_00_IRQ8            = (0x00U << IOPORT_PFC_OFFSET), ///< P22_6 / IRQ / IRQ8
    IOPORT_PIN_P226_PFC_04_A19             = (0x04U << IOPORT_PFC_OFFSET), ///< P22_6 / BSC / A19
    IOPORT_PIN_P226_PFC_0C_GTETRGSB        = (0x0CU << IOPORT_PFC_OFFSET), ///< P22_6 / POEG / GTETRGSB
    IOPORT_PIN_P226_PFC_10_GMAC0_PTPTRG1   = (0x10U << IOPORT_PFC_OFFSET), ///< P22_6 / ETHER_GMACn / GMAC0_PTPTRG1
    IOPORT_PIN_P226_PFC_12_ESC_LATCH1      = (0x12U << IOPORT_PFC_OFFSET), ///< P22_6 / ETHER_ESC / ESC_LATCH1
    IOPORT_PIN_P226_PFC_14_DE5             = (0x14U << IOPORT_PFC_OFFSET), ///< P22_6 / SCIn / DE5
    IOPORT_PIN_P226_PFC_19_CANTX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P22_6 / CANFDn / CANTX1
    IOPORT_PIN_P226_PFC_24_DUEI15          = (0x24U << IOPORT_PFC_OFFSET), ///< P22_6 / ENDATn / DUEI15
    IOPORT_PIN_P226_PFC_25_HDSL01_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P22_6 / HDSLn / HDSL01_SEL2
    IOPORT_PIN_P226_PFC_29_SD0_WP          = (0x29U << IOPORT_PFC_OFFSET), ///< P22_6 / SDHI / SD0_WP
    IOPORT_PIN_P227_PFC_00_IRQ9            = (0x00U << IOPORT_PFC_OFFSET), ///< P22_7 / IRQ / IRQ9
    IOPORT_PIN_P227_PFC_04_A18             = (0x04U << IOPORT_PFC_OFFSET), ///< P22_7 / BSC / A18
    IOPORT_PIN_P227_PFC_09_GTIOC06_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P22_7 / GPT / GTIOC06_0A
    IOPORT_PIN_P227_PFC_0F_ETH1_CRS        = (0x0FU << IOPORT_PFC_OFFSET), ///< P22_7 / ETHER_ETHn / ETH1_CRS
    IOPORT_PIN_P227_PFC_11_ETHSW_TDMAOUT2  = (0x11U << IOPORT_PFC_OFFSET), ///< P22_7 / ETHER_ETHSW / ETHSW_TDMAOUT2
    IOPORT_PIN_P227_PFC_12_ESC_LINKACT0    = (0x12U << IOPORT_PFC_OFFSET), ///< P22_7 / ETHER_ESC / ESC_LINKACT0
    IOPORT_PIN_P227_PFC_19_CANRXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P22_7 / CANFDn / CANRXDP1
    IOPORT_PIN_P227_PFC_24_TST_OUT15       = (0x24U << IOPORT_PFC_OFFSET), ///< P22_7 / ENDATn / TST_OUT15
    IOPORT_PIN_P227_PFC_25_HDSL01_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P22_7 / HDSLn / HDSL01_MISO2
    IOPORT_PIN_P230_PFC_00_IRQ10           = (0x00U << IOPORT_PFC_OFFSET), ///< P23_0 / IRQ / IRQ10
    IOPORT_PIN_P230_PFC_04_A17             = (0x04U << IOPORT_PFC_OFFSET), ///< P23_0 / BSC / A17
    IOPORT_PIN_P230_PFC_09_GTIOC06_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P23_0 / GPT / GTIOC06_0B
    IOPORT_PIN_P230_PFC_0F_ETH1_COL        = (0x0FU << IOPORT_PFC_OFFSET), ///< P23_0 / ETHER_ETHn / ETH1_COL
    IOPORT_PIN_P230_PFC_11_ETHSW_TDMAOUT3  = (0x11U << IOPORT_PFC_OFFSET), ///< P23_0 / ETHER_ETHSW / ETHSW_TDMAOUT3
    IOPORT_PIN_P230_PFC_12_ESC_LINKACT1    = (0x12U << IOPORT_PFC_OFFSET), ///< P23_0 / ETHER_ESC / ESC_LINKACT1
    IOPORT_PIN_P230_PFC_19_CANTXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P23_0 / CANFDn / CANTXDP1
    IOPORT_PIN_P230_PFC_24_SI15            = (0x24U << IOPORT_PFC_OFFSET), ///< P23_0 / ENDATn / SI15
    IOPORT_PIN_P230_PFC_25_HDSL01_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P23_0 / HDSLn / HDSL01_MOSI2
    IOPORT_PIN_P231_PFC_09_GTIOC06_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P23_1 / GPT / GTIOC06_1A
    IOPORT_PIN_P231_PFC_12_ESC_IRQ         = (0x12U << IOPORT_PFC_OFFSET), ///< P23_1 / ETHER_ESC / ESC_IRQ
    IOPORT_PIN_P231_PFC_24_DUEI00          = (0x24U << IOPORT_PFC_OFFSET), ///< P23_1 / ENDATn / DUEI00
    IOPORT_PIN_P231_PFC_25_HDSL02_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P23_1 / HDSLn / HDSL02_LINK
    IOPORT_PIN_P232_PFC_09_GTIOC06_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P23_2 / GPT / GTIOC06_1B
    IOPORT_PIN_P232_PFC_12_ESC_RESETOUT_N  = (0x12U << IOPORT_PFC_OFFSET), ///< P23_2 / ETHER_ESC / ESC_RESETOUT_N
    IOPORT_PIN_P232_PFC_24_TST_OUT00       = (0x24U << IOPORT_PFC_OFFSET), ///< P23_2 / ENDATn / TST_OUT00
    IOPORT_PIN_P232_PFC_25_HDSL02_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P23_2 / HDSLn / HDSL02_SMPL
    IOPORT_PIN_P233_PFC_09_GTIOC06_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P23_3 / GPT / GTIOC06_2A
    IOPORT_PIN_P233_PFC_12_ESC_I2CCLK      = (0x12U << IOPORT_PFC_OFFSET), ///< P23_3 / ETHER_ESC / ESC_I2CCLK
    IOPORT_PIN_P233_PFC_17_IIC_SCL0        = (0x17U << IOPORT_PFC_OFFSET), ///< P23_3 / IICn / IIC_SCL0
    IOPORT_PIN_P233_PFC_24_SI00            = (0x24U << IOPORT_PFC_OFFSET), ///< P23_3 / ENDATn / SI00
    IOPORT_PIN_P233_PFC_25_HDSL02_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P23_3 / HDSLn / HDSL02_CLK1
    IOPORT_PIN_P234_PFC_09_GTIOC06_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P23_4 / GPT / GTIOC06_2B
    IOPORT_PIN_P234_PFC_12_ESC_I2CDATA     = (0x12U << IOPORT_PFC_OFFSET), ///< P23_4 / ETHER_ESC / ESC_I2CDATA
    IOPORT_PIN_P234_PFC_17_IIC_SDA0        = (0x17U << IOPORT_PFC_OFFSET), ///< P23_4 / IICn / IIC_SDA0
    IOPORT_PIN_P234_PFC_24_DUEI01          = (0x24U << IOPORT_PFC_OFFSET), ///< P23_4 / ENDATn / DUEI01
    IOPORT_PIN_P234_PFC_25_HDSL02_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P23_4 / HDSLn / HDSL02_SEL1
    IOPORT_PIN_P235_PFC_12_ESC_LINKACT2    = (0x12U << IOPORT_PFC_OFFSET), ///< P23_5 / ETHER_ESC / ESC_LINKACT2
    IOPORT_PIN_P235_PFC_1D_MCLK60          = (0x1DU << IOPORT_PFC_OFFSET), ///< P23_5 / DSMIFn / MCLK60
    IOPORT_PIN_P235_PFC_24_TST_OUT01       = (0x24U << IOPORT_PFC_OFFSET), ///< P23_5 / ENDATn / TST_OUT01
    IOPORT_PIN_P235_PFC_25_HDSL02_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P23_5 / HDSLn / HDSL02_MISO1
    IOPORT_PIN_P236_PFC_11_ETHSW_LPI0      = (0x11U << IOPORT_PFC_OFFSET), ///< P23_6 / ETHER_ETHSW / ETHSW_LPI0
    IOPORT_PIN_P236_PFC_1D_MDAT60          = (0x1DU << IOPORT_PFC_OFFSET), ///< P23_6 / DSMIFn / MDAT60
    IOPORT_PIN_P236_PFC_24_SI01            = (0x24U << IOPORT_PFC_OFFSET), ///< P23_6 / ENDATn / SI01
    IOPORT_PIN_P236_PFC_25_HDSL02_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P23_6 / HDSLn / HDSL02_MOSI1
    IOPORT_PIN_P237_PFC_11_ETHSW_LPI1      = (0x11U << IOPORT_PFC_OFFSET), ///< P23_7 / ETHER_ETHSW / ETHSW_LPI1
    IOPORT_PIN_P237_PFC_1D_MCLK61          = (0x1DU << IOPORT_PFC_OFFSET), ///< P23_7 / DSMIFn / MCLK61
    IOPORT_PIN_P237_PFC_24_DUEI02          = (0x24U << IOPORT_PFC_OFFSET), ///< P23_7 / ENDATn / DUEI02
    IOPORT_PIN_P237_PFC_25_HDSL02_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P23_7 / HDSLn / HDSL02_CLK2
    IOPORT_PIN_P240_PFC_00_IRQ11           = (0x00U << IOPORT_PFC_OFFSET), ///< P24_0 / IRQ / IRQ11
    IOPORT_PIN_P240_PFC_11_ETHSW_LPI2      = (0x11U << IOPORT_PFC_OFFSET), ///< P24_0 / ETHER_ETHSW / ETHSW_LPI2
    IOPORT_PIN_P240_PFC_1D_MDAT61          = (0x1DU << IOPORT_PFC_OFFSET), ///< P24_0 / DSMIFn / MDAT61
    IOPORT_PIN_P240_PFC_24_TST_OUT02       = (0x24U << IOPORT_PFC_OFFSET), ///< P24_0 / ENDATn / TST_OUT02
    IOPORT_PIN_P240_PFC_25_HDSL02_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P24_0 / HDSLn / HDSL02_SEL2
    IOPORT_PIN_P241_PFC_00_IRQ12           = (0x00U << IOPORT_PFC_OFFSET), ///< P24_1 / IRQ / IRQ12
    IOPORT_PIN_P241_PFC_1D_MCLK62          = (0x1DU << IOPORT_PFC_OFFSET), ///< P24_1 / DSMIFn / MCLK62
    IOPORT_PIN_P241_PFC_24_SI02            = (0x24U << IOPORT_PFC_OFFSET), ///< P24_1 / ENDATn / SI02
    IOPORT_PIN_P241_PFC_25_HDSL02_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P24_1 / HDSLn / HDSL02_MISO2
    IOPORT_PIN_P242_PFC_00_IRQ13           = (0x00U << IOPORT_PFC_OFFSET), ///< P24_2 / IRQ / IRQ13
    IOPORT_PIN_P242_PFC_1D_MDAT62          = (0x1DU << IOPORT_PFC_OFFSET), ///< P24_2 / DSMIFn / MDAT62
    IOPORT_PIN_P242_PFC_25_HDSL02_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P24_2 / HDSLn / HDSL02_MOSI2
    IOPORT_PIN_P243_PFC_00_IRQ14           = (0x00U << IOPORT_PFC_OFFSET), ///< P24_3 / IRQ / IRQ14
    IOPORT_PIN_P243_PFC_12_ESC_I2CCLK      = (0x12U << IOPORT_PFC_OFFSET), ///< P24_3 / ETHER_ESC / ESC_I2CCLK
    IOPORT_PIN_P243_PFC_17_IIC_SCL1        = (0x17U << IOPORT_PFC_OFFSET), ///< P24_3 / IICn / IIC_SCL1
    IOPORT_PIN_P243_PFC_19_CANRX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P24_3 / CANFDn / CANRX0
    IOPORT_PIN_P243_PFC_1D_MCLK70          = (0x1DU << IOPORT_PFC_OFFSET), ///< P24_3 / DSMIFn / MCLK70
    IOPORT_PIN_P243_PFC_25_HDSL03_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P24_3 / HDSLn / HDSL03_LINK
    IOPORT_PIN_P244_PFC_00_IRQ15           = (0x00U << IOPORT_PFC_OFFSET), ///< P24_4 / IRQ / IRQ15
    IOPORT_PIN_P244_PFC_12_ESC_I2CDATA     = (0x12U << IOPORT_PFC_OFFSET), ///< P24_4 / ETHER_ESC / ESC_I2CDATA
    IOPORT_PIN_P244_PFC_17_IIC_SDA1        = (0x17U << IOPORT_PFC_OFFSET), ///< P24_4 / IICn / IIC_SDA1
    IOPORT_PIN_P244_PFC_19_CANTX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P24_4 / CANFDn / CANTX0
    IOPORT_PIN_P244_PFC_1D_MDAT70          = (0x1DU << IOPORT_PFC_OFFSET), ///< P24_4 / DSMIFn / MDAT70
    IOPORT_PIN_P244_PFC_25_HDSL03_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P24_4 / HDSLn / HDSL03_SMPL
    IOPORT_PIN_P245_PFC_0F_ETH1_TXCLK      = (0x0FU << IOPORT_PFC_OFFSET), ///< P24_5 / ETHER_ETHn / ETH1_TXCLK
    IOPORT_PIN_P245_PFC_25_HDSL03_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P24_5 / HDSLn / HDSL03_CLK1
    IOPORT_PIN_P246_PFC_0F_ETH1_TXD0       = (0x0FU << IOPORT_PFC_OFFSET), ///< P24_6 / ETHER_ETHn / ETH1_TXD0
    IOPORT_PIN_P247_PFC_0F_ETH1_TXD1       = (0x0FU << IOPORT_PFC_OFFSET), ///< P24_7 / ETHER_ETHn / ETH1_TXD1
    IOPORT_PIN_P250_PFC_0F_ETH1_TXD2       = (0x0FU << IOPORT_PFC_OFFSET), ///< P25_0 / ETHER_ETHn / ETH1_TXD2
    IOPORT_PIN_P250_PFC_19_CANRXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P25_0 / CANFDn / CANRXDP0
    IOPORT_PIN_P251_PFC_0F_ETH1_TXD3       = (0x0FU << IOPORT_PFC_OFFSET), ///< P25_1 / ETHER_ETHn / ETH1_TXD3
    IOPORT_PIN_P251_PFC_19_CANTXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P25_1 / CANFDn / CANTXDP0
    IOPORT_PIN_P252_PFC_0F_ETH1_TXEN       = (0x0FU << IOPORT_PFC_OFFSET), ///< P25_2 / ETHER_ETHn / ETH1_TXEN
    IOPORT_PIN_P253_PFC_0F_ETH1_RXCLK      = (0x0FU << IOPORT_PFC_OFFSET), ///< P25_3 / ETHER_ETHn / ETH1_RXCLK
    IOPORT_PIN_P253_PFC_24_DUEI03          = (0x24U << IOPORT_PFC_OFFSET), ///< P25_3 / ENDATn / DUEI03
    IOPORT_PIN_P253_PFC_25_HDSL03_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P25_3 / HDSLn / HDSL03_SEL1
    IOPORT_PIN_P254_PFC_0F_ETH1_RXD0       = (0x0FU << IOPORT_PFC_OFFSET), ///< P25_4 / ETHER_ETHn / ETH1_RXD0
    IOPORT_PIN_P254_PFC_24_TST_OUT03       = (0x24U << IOPORT_PFC_OFFSET), ///< P25_4 / ENDATn / TST_OUT03
    IOPORT_PIN_P254_PFC_25_HDSL03_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P25_4 / HDSLn / HDSL03_MISO1
    IOPORT_PIN_P255_PFC_0F_ETH1_RXD1       = (0x0FU << IOPORT_PFC_OFFSET), ///< P25_5 / ETHER_ETHn / ETH1_RXD1
    IOPORT_PIN_P255_PFC_24_SI03            = (0x24U << IOPORT_PFC_OFFSET), ///< P25_5 / ENDATn / SI03
    IOPORT_PIN_P255_PFC_25_HDSL03_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P25_5 / HDSLn / HDSL03_MOSI1
    IOPORT_PIN_P256_PFC_0F_ETH1_RXD2       = (0x0FU << IOPORT_PFC_OFFSET), ///< P25_6 / ETHER_ETHn / ETH1_RXD2
    IOPORT_PIN_P256_PFC_19_CANRX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P25_6 / CANFDn / CANRX1
    IOPORT_PIN_P256_PFC_24_DUEI04          = (0x24U << IOPORT_PFC_OFFSET), ///< P25_6 / ENDATn / DUEI04
    IOPORT_PIN_P256_PFC_25_HDSL03_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P25_6 / HDSLn / HDSL03_CLK2
    IOPORT_PIN_P257_PFC_0F_ETH1_RXD3       = (0x0FU << IOPORT_PFC_OFFSET), ///< P25_7 / ETHER_ETHn / ETH1_RXD3
    IOPORT_PIN_P257_PFC_19_CANTX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P25_7 / CANFDn / CANTX1
    IOPORT_PIN_P257_PFC_24_TST_OUT04       = (0x24U << IOPORT_PFC_OFFSET), ///< P25_7 / ENDATn / TST_OUT04
    IOPORT_PIN_P257_PFC_25_HDSL03_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P25_7 / HDSLn / HDSL03_SEL2
    IOPORT_PIN_P260_PFC_0F_ETH1_RXDV       = (0x0FU << IOPORT_PFC_OFFSET), ///< P26_0 / ETHER_ETHn / ETH1_RXDV
    IOPORT_PIN_P260_PFC_24_SI04            = (0x24U << IOPORT_PFC_OFFSET), ///< P26_0 / ENDATn / SI04
    IOPORT_PIN_P260_PFC_25_HDSL03_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P26_0 / HDSLn / HDSL03_MISO2
    IOPORT_PIN_P261_PFC_10_GMAC1_MDC       = (0x10U << IOPORT_PFC_OFFSET), ///< P26_1 / ETHER_GMACn / GMAC1_MDC
    IOPORT_PIN_P261_PFC_11_ETHSW_MDC       = (0x11U << IOPORT_PFC_OFFSET), ///< P26_1 / ETHER_ETHSW / ETHSW_MDC
    IOPORT_PIN_P261_PFC_12_ESC_MDC         = (0x12U << IOPORT_PFC_OFFSET), ///< P26_1 / ETHER_ESC / ESC_MDC
    IOPORT_PIN_P261_PFC_19_CANRXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P26_1 / CANFDn / CANRXDP1
    IOPORT_PIN_P261_PFC_25_HDSL03_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P26_1 / HDSLn / HDSL03_MOSI2
    IOPORT_PIN_P262_PFC_10_GMAC1_MDIO      = (0x10U << IOPORT_PFC_OFFSET), ///< P26_2 / ETHER_GMACn / GMAC1_MDIO
    IOPORT_PIN_P262_PFC_11_ETHSW_MDIO      = (0x11U << IOPORT_PFC_OFFSET), ///< P26_2 / ETHER_ETHSW / ETHSW_MDIO
    IOPORT_PIN_P262_PFC_12_ESC_MDIO        = (0x12U << IOPORT_PFC_OFFSET), ///< P26_2 / ETHER_ESC / ESC_MDIO
    IOPORT_PIN_P262_PFC_19_CANTXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P26_2 / CANFDn / CANTXDP1
    IOPORT_PIN_P262_PFC_25_HDSL04_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P26_2 / HDSLn / HDSL04_LINK
    IOPORT_PIN_P263_PFC_11_ETHSW_PHYLINK1  = (0x11U << IOPORT_PFC_OFFSET), ///< P26_3 / ETHER_ETHSW / ETHSW_PHYLINK1
    IOPORT_PIN_P263_PFC_12_ESC_PHYLINK1    = (0x12U << IOPORT_PFC_OFFSET), ///< P26_3 / ETHER_ESC / ESC_PHYLINK1
    IOPORT_PIN_P263_PFC_25_HDSL04_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P26_3 / HDSLn / HDSL04_SMPL
    IOPORT_PIN_P264_PFC_02_ETH1_REFCLK     = (0x02U << IOPORT_PFC_OFFSET), ///< P26_4 / ETHER_ETHn / ETH1_REFCLK
    IOPORT_PIN_P264_PFC_03_RMII1_REFCLK    = (0x03U << IOPORT_PFC_OFFSET), ///< P26_4 / ETHER_ETHn / RMII1_REFCLK
    IOPORT_PIN_P265_PFC_00_IRQ12           = (0x00U << IOPORT_PFC_OFFSET), ///< P26_5 / IRQ / IRQ12
    IOPORT_PIN_P265_PFC_15_SCKE01          = (0x15U << IOPORT_PFC_OFFSET), ///< P26_5 / SCIEn / SCKE01
    IOPORT_PIN_P265_PFC_19_CANTX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P26_5 / CANFDn / CANTX0
    IOPORT_PIN_P265_PFC_22_ENCIFCK01       = (0x22U << IOPORT_PFC_OFFSET), ///< P26_5 / ENCIFn / ENCIFCK01
    IOPORT_PIN_P265_PFC_25_HDSL04_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P26_5 / HDSLn / HDSL04_CLK1
    IOPORT_PIN_P266_PFC_00_SEI             = (0x00U << IOPORT_PFC_OFFSET), ///< P26_6 / IRQ / SEI
    IOPORT_PIN_P266_PFC_04_CS2             = (0x04U << IOPORT_PFC_OFFSET), ///< P26_6 / BSC / CS2
    IOPORT_PIN_P266_PFC_0F_ETH1_TXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P26_6 / ETHER_ETHn / ETH1_TXER
    IOPORT_PIN_P266_PFC_12_ESC_RESETOUT_N  = (0x12U << IOPORT_PFC_OFFSET), ///< P26_6 / ETHER_ESC / ESC_RESETOUT_N
    IOPORT_PIN_P266_PFC_15_DEE01           = (0x15U << IOPORT_PFC_OFFSET), ///< P26_6 / SCIEn / DEE01
    IOPORT_PIN_P266_PFC_19_CANRX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P26_6 / CANFDn / CANRX0
    IOPORT_PIN_P266_PFC_22_ENCIFOE01       = (0x22U << IOPORT_PFC_OFFSET), ///< P26_6 / ENCIFn / ENCIFOE01
    IOPORT_PIN_P266_PFC_25_HDSL04_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P26_6 / HDSLn / HDSL04_SEL1
    IOPORT_PIN_P267_PFC_00_IRQ0            = (0x00U << IOPORT_PFC_OFFSET), ///< P26_7 / IRQ / IRQ0
    IOPORT_PIN_P267_PFC_04_CS3             = (0x04U << IOPORT_PFC_OFFSET), ///< P26_7 / BSC / CS3
    IOPORT_PIN_P267_PFC_0F_ETH1_RXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P26_7 / ETHER_ETHn / ETH1_RXER
    IOPORT_PIN_P267_PFC_12_ESC_LEDSTER     = (0x12U << IOPORT_PFC_OFFSET), ///< P26_7 / ETHER_ESC / ESC_LEDSTER
    IOPORT_PIN_P267_PFC_15_TXDE01          = (0x15U << IOPORT_PFC_OFFSET), ///< P26_7 / SCIEn / TXDE01
    IOPORT_PIN_P267_PFC_19_CANRXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P26_7 / CANFDn / CANRXDP0
    IOPORT_PIN_P267_PFC_1A_SPI_SSL01       = (0x1AU << IOPORT_PFC_OFFSET), ///< P26_7 / SPIn / SPI_SSL01
    IOPORT_PIN_P267_PFC_22_ENCIFDO01       = (0x22U << IOPORT_PFC_OFFSET), ///< P26_7 / ENCIFn / ENCIFDO01
    IOPORT_PIN_P267_PFC_25_HDSL04_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P26_7 / HDSLn / HDSL04_MISO1
    IOPORT_PIN_P270_PFC_00_IRQ1            = (0x00U << IOPORT_PFC_OFFSET), ///< P27_0 / IRQ / IRQ1
    IOPORT_PIN_P270_PFC_04_CS5             = (0x04U << IOPORT_PFC_OFFSET), ///< P27_0 / BSC / CS5
    IOPORT_PIN_P270_PFC_0F_ETH1_CRS        = (0x0FU << IOPORT_PFC_OFFSET), ///< P27_0 / ETHER_ETHn / ETH1_CRS
    IOPORT_PIN_P270_PFC_15_RXDE01          = (0x15U << IOPORT_PFC_OFFSET), ///< P27_0 / SCIEn / RXDE01
    IOPORT_PIN_P270_PFC_19_CANTXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P27_0 / CANFDn / CANTXDP0
    IOPORT_PIN_P270_PFC_1A_SPI_SSL02       = (0x1AU << IOPORT_PFC_OFFSET), ///< P27_0 / SPIn / SPI_SSL02
    IOPORT_PIN_P270_PFC_20_HSPI_INT        = (0x20U << IOPORT_PFC_OFFSET), ///< P27_0 / SHOSTIF / HSPI_INT
    IOPORT_PIN_P270_PFC_22_ENCIFDI01       = (0x22U << IOPORT_PFC_OFFSET), ///< P27_0 / ENCIFn / ENCIFDI01
    IOPORT_PIN_P270_PFC_25_HDSL04_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P27_0 / HDSLn / HDSL04_MOSI1
    IOPORT_PIN_P271_PFC_00_IRQ2            = (0x00U << IOPORT_PFC_OFFSET), ///< P27_1 / IRQ / IRQ2
    IOPORT_PIN_P271_PFC_0A_GTIOC02_0A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P27_1 / GPT / GTIOC02_0A
    IOPORT_PIN_P271_PFC_0F_ETH1_COL        = (0x0FU << IOPORT_PFC_OFFSET), ///< P27_1 / ETHER_ETHn / ETH1_COL
    IOPORT_PIN_P271_PFC_19_CANRX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P27_1 / CANFDn / CANRX1
    IOPORT_PIN_P271_PFC_1A_SPI_SSL03       = (0x1AU << IOPORT_PFC_OFFSET), ///< P27_1 / SPIn / SPI_SSL03
    IOPORT_PIN_P271_PFC_20_HSPI_CS         = (0x20U << IOPORT_PFC_OFFSET), ///< P27_1 / SHOSTIF / HSPI_CS
    IOPORT_PIN_P271_PFC_25_HDSL04_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P27_1 / HDSLn / HDSL04_CLK2
    IOPORT_PIN_P272_PFC_00_IRQ3            = (0x00U << IOPORT_PFC_OFFSET), ///< P27_2 / IRQ / IRQ3
    IOPORT_PIN_P272_PFC_0A_GTIOC02_0B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P27_2 / GPT / GTIOC02_0B
    IOPORT_PIN_P272_PFC_10_GMAC1_PTPTRG0   = (0x10U << IOPORT_PFC_OFFSET), ///< P27_2 / ETHER_GMACn / GMAC1_PTPTRG0
    IOPORT_PIN_P272_PFC_12_ESC_LEDERR      = (0x12U << IOPORT_PFC_OFFSET), ///< P27_2 / ETHER_ESC / ESC_LEDERR
    IOPORT_PIN_P272_PFC_19_CANTX1          = (0x19U << IOPORT_PFC_OFFSET), ///< P27_2 / CANFDn / CANTX1
    IOPORT_PIN_P272_PFC_1A_SPI_RSPCK0      = (0x1AU << IOPORT_PFC_OFFSET), ///< P27_2 / SPIn / SPI_RSPCK0
    IOPORT_PIN_P272_PFC_20_HSPI_IO0        = (0x20U << IOPORT_PFC_OFFSET), ///< P27_2 / SHOSTIF / HSPI_IO0
    IOPORT_PIN_P272_PFC_25_HDSL04_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P27_2 / HDSLn / HDSL04_SEL2
    IOPORT_PIN_P273_PFC_06_MTIOC2A         = (0x06U << IOPORT_PFC_OFFSET), ///< P27_3 / MTU3 / MTIOC2A
    IOPORT_PIN_P273_PFC_09_GTIOC08_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P27_3 / GPT / GTIOC08_3A
    IOPORT_PIN_P273_PFC_0A_GTIOC02_1A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P27_3 / GPT / GTIOC02_1A
    IOPORT_PIN_P273_PFC_10_GMAC1_PTPTRG1   = (0x10U << IOPORT_PFC_OFFSET), ///< P27_3 / ETHER_GMACn / GMAC1_PTPTRG1
    IOPORT_PIN_P273_PFC_14_SCK0            = (0x14U << IOPORT_PFC_OFFSET), ///< P27_3 / SCIn / SCK0
    IOPORT_PIN_P273_PFC_15_SCKE10          = (0x15U << IOPORT_PFC_OFFSET), ///< P27_3 / SCIEn / SCKE10
    IOPORT_PIN_P273_PFC_19_CANRXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P27_3 / CANFDn / CANRXDP1
    IOPORT_PIN_P273_PFC_1A_SPI_MOSI0       = (0x1AU << IOPORT_PFC_OFFSET), ///< P27_3 / SPIn / SPI_MOSI0
    IOPORT_PIN_P273_PFC_20_HSPI_IO1        = (0x20U << IOPORT_PFC_OFFSET), ///< P27_3 / SHOSTIF / HSPI_IO1
    IOPORT_PIN_P273_PFC_22_ENCIFCK14       = (0x22U << IOPORT_PFC_OFFSET), ///< P27_3 / ENCIFn / ENCIFCK14
    IOPORT_PIN_P273_PFC_25_HDSL04_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P27_3 / HDSLn / HDSL04_MISO2
    IOPORT_PIN_P274_PFC_06_MTIOC2B         = (0x06U << IOPORT_PFC_OFFSET), ///< P27_4 / MTU3 / MTIOC2B
    IOPORT_PIN_P274_PFC_09_GTIOC08_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P27_4 / GPT / GTIOC08_3B
    IOPORT_PIN_P274_PFC_0A_GTIOC02_1B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P27_4 / GPT / GTIOC02_1B
    IOPORT_PIN_P274_PFC_14_RXD0_SCL0_MISO0 = (0x14U << IOPORT_PFC_OFFSET), ///< P27_4 / SCIn / RXD0_SCL0_MISO0
    IOPORT_PIN_P274_PFC_15_DEE10           = (0x15U << IOPORT_PFC_OFFSET), ///< P27_4 / SCIEn / DEE10
    IOPORT_PIN_P274_PFC_19_CANTXDP1        = (0x19U << IOPORT_PFC_OFFSET), ///< P27_4 / CANFDn / CANTXDP1
    IOPORT_PIN_P274_PFC_1A_SPI_MISO0       = (0x1AU << IOPORT_PFC_OFFSET), ///< P27_4 / SPIn / SPI_MISO0
    IOPORT_PIN_P274_PFC_20_HSPI_IO2        = (0x20U << IOPORT_PFC_OFFSET), ///< P27_4 / SHOSTIF / HSPI_IO2
    IOPORT_PIN_P274_PFC_22_ENCIFOE14       = (0x22U << IOPORT_PFC_OFFSET), ///< P27_4 / ENCIFn / ENCIFOE14
    IOPORT_PIN_P274_PFC_25_HDSL04_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P27_4 / HDSLn / HDSL04_MOSI2
    IOPORT_PIN_P275_PFC_06_MTIOC1A         = (0x06U << IOPORT_PFC_OFFSET), ///< P27_5 / MTU3 / MTIOC1A
    IOPORT_PIN_P275_PFC_09_GTIOC08_4A      = (0x09U << IOPORT_PFC_OFFSET), ///< P27_5 / GPT / GTIOC08_4A
    IOPORT_PIN_P275_PFC_0A_GTIOC02_2A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P27_5 / GPT / GTIOC02_2A
    IOPORT_PIN_P275_PFC_14_TXD0_SDA0_MOSI0 = (0x14U << IOPORT_PFC_OFFSET), ///< P27_5 / SCIn / TXD0_SDA0_MOSI0
    IOPORT_PIN_P275_PFC_15_TXDE10          = (0x15U << IOPORT_PFC_OFFSET), ///< P27_5 / SCIEn / TXDE10
    IOPORT_PIN_P275_PFC_1A_SPI_SSL00       = (0x1AU << IOPORT_PFC_OFFSET), ///< P27_5 / SPIn / SPI_SSL00
    IOPORT_PIN_P275_PFC_20_HSPI_IO3        = (0x20U << IOPORT_PFC_OFFSET), ///< P27_5 / SHOSTIF / HSPI_IO3
    IOPORT_PIN_P275_PFC_22_ENCIFDO14       = (0x22U << IOPORT_PFC_OFFSET), ///< P27_5 / ENCIFn / ENCIFDO14
    IOPORT_PIN_P275_PFC_25_HDSL05_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P27_5 / HDSLn / HDSL05_LINK
    IOPORT_PIN_P276_PFC_06_MTIOC1B         = (0x06U << IOPORT_PFC_OFFSET), ///< P27_6 / MTU3 / MTIOC1B
    IOPORT_PIN_P276_PFC_09_GTIOC08_4B      = (0x09U << IOPORT_PFC_OFFSET), ///< P27_6 / GPT / GTIOC08_4B
    IOPORT_PIN_P276_PFC_0A_GTIOC02_2B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P27_6 / GPT / GTIOC02_2B
    IOPORT_PIN_P276_PFC_15_RXDE10          = (0x15U << IOPORT_PFC_OFFSET), ///< P27_6 / SCIEn / RXDE10
    IOPORT_PIN_P276_PFC_20_HSPI_CK         = (0x20U << IOPORT_PFC_OFFSET), ///< P27_6 / SHOSTIF / HSPI_CK
    IOPORT_PIN_P276_PFC_22_ENCIFDI14       = (0x22U << IOPORT_PFC_OFFSET), ///< P27_6 / ENCIFn / ENCIFDI14
    IOPORT_PIN_P276_PFC_25_HDSL05_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P27_6 / HDSLn / HDSL05_SMPL
    IOPORT_PIN_P277_PFC_00_IRQ4            = (0x00U << IOPORT_PFC_OFFSET), ///< P27_7 / IRQ / IRQ4
    IOPORT_PIN_P277_PFC_09_GTIOC08_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P27_7 / GPT / GTIOC08_0A
    IOPORT_PIN_P277_PFC_11_ETHSW_TDMAOUT0  = (0x11U << IOPORT_PFC_OFFSET), ///< P27_7 / ETHER_ETHSW / ETHSW_TDMAOUT0
    IOPORT_PIN_P277_PFC_1A_SPI_RSPCK1      = (0x1AU << IOPORT_PFC_OFFSET), ///< P27_7 / SPIn / SPI_RSPCK1
    IOPORT_PIN_P277_PFC_24_DUEI05          = (0x24U << IOPORT_PFC_OFFSET), ///< P27_7 / ENDATn / DUEI05
    IOPORT_PIN_P277_PFC_25_HDSL05_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P27_7 / HDSLn / HDSL05_CLK1
    IOPORT_PIN_P280_PFC_00_IRQ5            = (0x00U << IOPORT_PFC_OFFSET), ///< P28_0 / IRQ / IRQ5
    IOPORT_PIN_P280_PFC_09_GTIOC08_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P28_0 / GPT / GTIOC08_0B
    IOPORT_PIN_P280_PFC_11_ETHSW_TDMAOUT1  = (0x11U << IOPORT_PFC_OFFSET), ///< P28_0 / ETHER_ETHSW / ETHSW_TDMAOUT1
    IOPORT_PIN_P280_PFC_1A_SPI_MOSI1       = (0x1AU << IOPORT_PFC_OFFSET), ///< P28_0 / SPIn / SPI_MOSI1
    IOPORT_PIN_P280_PFC_24_TST_OUT05       = (0x24U << IOPORT_PFC_OFFSET), ///< P28_0 / ENDATn / TST_OUT05
    IOPORT_PIN_P280_PFC_25_HDSL05_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P28_0 / HDSLn / HDSL05_SEL1
    IOPORT_PIN_P281_PFC_00_IRQ6            = (0x00U << IOPORT_PFC_OFFSET), ///< P28_1 / IRQ / IRQ6
    IOPORT_PIN_P281_PFC_09_GTIOC08_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P28_1 / GPT / GTIOC08_1A
    IOPORT_PIN_P281_PFC_11_ETHSW_TDMAOUT2  = (0x11U << IOPORT_PFC_OFFSET), ///< P28_1 / ETHER_ETHSW / ETHSW_TDMAOUT2
    IOPORT_PIN_P281_PFC_1A_SPI_MISO1       = (0x1AU << IOPORT_PFC_OFFSET), ///< P28_1 / SPIn / SPI_MISO1
    IOPORT_PIN_P281_PFC_24_SI05            = (0x24U << IOPORT_PFC_OFFSET), ///< P28_1 / ENDATn / SI05
    IOPORT_PIN_P281_PFC_25_HDSL05_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P28_1 / HDSLn / HDSL05_MISO1
    IOPORT_PIN_P282_PFC_00_IRQ7            = (0x00U << IOPORT_PFC_OFFSET), ///< P28_2 / IRQ / IRQ7
    IOPORT_PIN_P282_PFC_09_GTIOC08_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P28_2 / GPT / GTIOC08_1B
    IOPORT_PIN_P282_PFC_11_ETHSW_TDMAOUT3  = (0x11U << IOPORT_PFC_OFFSET), ///< P28_2 / ETHER_ETHSW / ETHSW_TDMAOUT3
    IOPORT_PIN_P282_PFC_1A_SPI_SSL10       = (0x1AU << IOPORT_PFC_OFFSET), ///< P28_2 / SPIn / SPI_SSL10
    IOPORT_PIN_P282_PFC_24_DUEI06          = (0x24U << IOPORT_PFC_OFFSET), ///< P28_2 / ENDATn / DUEI06
    IOPORT_PIN_P282_PFC_25_HDSL05_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P28_2 / HDSLn / HDSL05_MOSI1
    IOPORT_PIN_P283_PFC_09_GTIOC08_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P28_3 / GPT / GTIOC08_2A
    IOPORT_PIN_P283_PFC_1A_SPI_SSL11       = (0x1AU << IOPORT_PFC_OFFSET), ///< P28_3 / SPIn / SPI_SSL11
    IOPORT_PIN_P283_PFC_24_TST_OUT06       = (0x24U << IOPORT_PFC_OFFSET), ///< P28_3 / ENDATn / TST_OUT06
    IOPORT_PIN_P283_PFC_25_HDSL05_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P28_3 / HDSLn / HDSL05_CLK2
    IOPORT_PIN_P284_PFC_09_GTIOC08_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P28_4 / GPT / GTIOC08_2B
    IOPORT_PIN_P284_PFC_1A_SPI_SSL12       = (0x1AU << IOPORT_PFC_OFFSET), ///< P28_4 / SPIn / SPI_SSL12
    IOPORT_PIN_P284_PFC_24_SI06            = (0x24U << IOPORT_PFC_OFFSET), ///< P28_4 / ENDATn / SI06
    IOPORT_PIN_P284_PFC_25_HDSL05_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P28_4 / HDSLn / HDSL05_SEL2
    IOPORT_PIN_P285_PFC_15_SCKE08          = (0x15U << IOPORT_PFC_OFFSET), ///< P28_5 / SCIEn / SCKE08
    IOPORT_PIN_P285_PFC_16_SCKE00          = (0x16U << IOPORT_PFC_OFFSET), ///< P28_5 / SCIEn / SCKE00
    IOPORT_PIN_P285_PFC_19_CANRX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P28_5 / CANFDn / CANRX0
    IOPORT_PIN_P285_PFC_1A_SPI_SSL13       = (0x1AU << IOPORT_PFC_OFFSET), ///< P28_5 / SPIn / SPI_SSL13
    IOPORT_PIN_P285_PFC_1D_MCLK71          = (0x1DU << IOPORT_PFC_OFFSET), ///< P28_5 / DSMIFn / MCLK71
    IOPORT_PIN_P285_PFC_22_ENCIFCK08       = (0x22U << IOPORT_PFC_OFFSET), ///< P28_5 / ENCIFn / ENCIFCK08
    IOPORT_PIN_P285_PFC_23_ENCIFCK00       = (0x23U << IOPORT_PFC_OFFSET), ///< P28_5 / ENCIFn / ENCIFCK00
    IOPORT_PIN_P285_PFC_25_HDSL05_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P28_5 / HDSLn / HDSL05_MISO2
    IOPORT_PIN_P286_PFC_15_DEE08           = (0x15U << IOPORT_PFC_OFFSET), ///< P28_6 / SCIEn / DEE08
    IOPORT_PIN_P286_PFC_16_DEE00           = (0x16U << IOPORT_PFC_OFFSET), ///< P28_6 / SCIEn / DEE00
    IOPORT_PIN_P286_PFC_19_CANTX0          = (0x19U << IOPORT_PFC_OFFSET), ///< P28_6 / CANFDn / CANTX0
    IOPORT_PIN_P286_PFC_1D_MDAT71          = (0x1DU << IOPORT_PFC_OFFSET), ///< P28_6 / DSMIFn / MDAT71
    IOPORT_PIN_P286_PFC_22_ENCIFOE08       = (0x22U << IOPORT_PFC_OFFSET), ///< P28_6 / ENCIFn / ENCIFOE08
    IOPORT_PIN_P286_PFC_23_ENCIFOE00       = (0x23U << IOPORT_PFC_OFFSET), ///< P28_6 / ENCIFn / ENCIFOE00
    IOPORT_PIN_P286_PFC_25_HDSL05_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P28_6 / HDSLn / HDSL05_MOSI2
    IOPORT_PIN_P287_PFC_15_TXDE08          = (0x15U << IOPORT_PFC_OFFSET), ///< P28_7 / SCIEn / TXDE08
    IOPORT_PIN_P287_PFC_16_TXDE00          = (0x16U << IOPORT_PFC_OFFSET), ///< P28_7 / SCIEn / TXDE00
    IOPORT_PIN_P287_PFC_19_CANRXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P28_7 / CANFDn / CANRXDP0
    IOPORT_PIN_P287_PFC_1D_MCLK72          = (0x1DU << IOPORT_PFC_OFFSET), ///< P28_7 / DSMIFn / MCLK72
    IOPORT_PIN_P287_PFC_22_ENCIFDO08       = (0x22U << IOPORT_PFC_OFFSET), ///< P28_7 / ENCIFn / ENCIFDO08
    IOPORT_PIN_P287_PFC_23_ENCIFDO00       = (0x23U << IOPORT_PFC_OFFSET), ///< P28_7 / ENCIFn / ENCIFDO00
    IOPORT_PIN_P287_PFC_25_HDSL06_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P28_7 / HDSLn / HDSL06_LINK
    IOPORT_PIN_P290_PFC_15_RXDE08          = (0x15U << IOPORT_PFC_OFFSET), ///< P29_0 / SCIEn / RXDE08
    IOPORT_PIN_P290_PFC_16_RXDE00          = (0x16U << IOPORT_PFC_OFFSET), ///< P29_0 / SCIEn / RXDE00
    IOPORT_PIN_P290_PFC_19_CANTXDP0        = (0x19U << IOPORT_PFC_OFFSET), ///< P29_0 / CANFDn / CANTXDP0
    IOPORT_PIN_P290_PFC_1D_MDAT72          = (0x1DU << IOPORT_PFC_OFFSET), ///< P29_0 / DSMIFn / MDAT72
    IOPORT_PIN_P290_PFC_22_ENCIFDI08       = (0x22U << IOPORT_PFC_OFFSET), ///< P29_0 / ENCIFn / ENCIFDI08
    IOPORT_PIN_P290_PFC_23_ENCIFDI00       = (0x23U << IOPORT_PFC_OFFSET), ///< P29_0 / ENCIFn / ENCIFDI00
    IOPORT_PIN_P290_PFC_25_HDSL06_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P29_0 / HDSLn / HDSL06_SMPL
    IOPORT_PIN_P291_PFC_09_GTIOC09_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P29_1 / GPT / GTIOC09_0A
    IOPORT_PIN_P291_PFC_0F_ETH2_TXCLK      = (0x0FU << IOPORT_PFC_OFFSET), ///< P29_1 / ETHER_ETHn / ETH2_TXCLK
    IOPORT_PIN_P291_PFC_15_SCKE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P29_1 / SCIEn / SCKE09
    IOPORT_PIN_P291_PFC_22_ENCIFCK09       = (0x22U << IOPORT_PFC_OFFSET), ///< P29_1 / ENCIFn / ENCIFCK09
    IOPORT_PIN_P291_PFC_25_HDSL06_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P29_1 / HDSLn / HDSL06_CLK1
    IOPORT_PIN_P292_PFC_09_GTIOC09_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P29_2 / GPT / GTIOC09_0B
    IOPORT_PIN_P292_PFC_0F_ETH2_TXD0       = (0x0FU << IOPORT_PFC_OFFSET), ///< P29_2 / ETHER_ETHn / ETH2_TXD0
    IOPORT_PIN_P292_PFC_15_DEE09           = (0x15U << IOPORT_PFC_OFFSET), ///< P29_2 / SCIEn / DEE09
    IOPORT_PIN_P292_PFC_22_ENCIFOE09       = (0x22U << IOPORT_PFC_OFFSET), ///< P29_2 / ENCIFn / ENCIFOE09
    IOPORT_PIN_P292_PFC_25_HDSL06_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P29_2 / HDSLn / HDSL06_SEL1
    IOPORT_PIN_P293_PFC_09_GTIOC09_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P29_3 / GPT / GTIOC09_1A
    IOPORT_PIN_P293_PFC_0F_ETH2_TXD1       = (0x0FU << IOPORT_PFC_OFFSET), ///< P29_3 / ETHER_ETHn / ETH2_TXD1
    IOPORT_PIN_P293_PFC_15_TXDE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P29_3 / SCIEn / TXDE09
    IOPORT_PIN_P293_PFC_22_ENCIFDO09       = (0x22U << IOPORT_PFC_OFFSET), ///< P29_3 / ENCIFn / ENCIFDO09
    IOPORT_PIN_P293_PFC_25_HDSL06_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P29_3 / HDSLn / HDSL06_MISO1
    IOPORT_PIN_P294_PFC_00_IRQ8            = (0x00U << IOPORT_PFC_OFFSET), ///< P29_4 / IRQ / IRQ8
    IOPORT_PIN_P294_PFC_09_GTIOC09_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P29_4 / GPT / GTIOC09_1B
    IOPORT_PIN_P294_PFC_0F_ETH2_TXD2       = (0x0FU << IOPORT_PFC_OFFSET), ///< P29_4 / ETHER_ETHn / ETH2_TXD2
    IOPORT_PIN_P294_PFC_15_RXDE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P29_4 / SCIEn / RXDE09
    IOPORT_PIN_P294_PFC_1A_SPI_SSL20       = (0x1AU << IOPORT_PFC_OFFSET), ///< P29_4 / SPIn / SPI_SSL20
    IOPORT_PIN_P294_PFC_22_ENCIFDI09       = (0x22U << IOPORT_PFC_OFFSET), ///< P29_4 / ENCIFn / ENCIFDI09
    IOPORT_PIN_P294_PFC_25_HDSL06_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P29_4 / HDSLn / HDSL06_MOSI1
    IOPORT_PIN_P295_PFC_00_IRQ9            = (0x00U << IOPORT_PFC_OFFSET), ///< P29_5 / IRQ / IRQ9
    IOPORT_PIN_P295_PFC_09_GTIOC09_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P29_5 / GPT / GTIOC09_2A
    IOPORT_PIN_P295_PFC_0F_ETH2_TXD3       = (0x0FU << IOPORT_PFC_OFFSET), ///< P29_5 / ETHER_ETHn / ETH2_TXD3
    IOPORT_PIN_P295_PFC_15_SCKE10          = (0x15U << IOPORT_PFC_OFFSET), ///< P29_5 / SCIEn / SCKE10
    IOPORT_PIN_P295_PFC_1A_SPI_SSL21       = (0x1AU << IOPORT_PFC_OFFSET), ///< P29_5 / SPIn / SPI_SSL21
    IOPORT_PIN_P295_PFC_22_ENCIFCK10       = (0x22U << IOPORT_PFC_OFFSET), ///< P29_5 / ENCIFn / ENCIFCK10
    IOPORT_PIN_P295_PFC_25_HDSL06_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P29_5 / HDSLn / HDSL06_CLK2
    IOPORT_PIN_P296_PFC_09_GTIOC09_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P29_6 / GPT / GTIOC09_2B
    IOPORT_PIN_P296_PFC_0F_ETH2_TXEN       = (0x0FU << IOPORT_PFC_OFFSET), ///< P29_6 / ETHER_ETHn / ETH2_TXEN
    IOPORT_PIN_P296_PFC_15_DEE10           = (0x15U << IOPORT_PFC_OFFSET), ///< P29_6 / SCIEn / DEE10
    IOPORT_PIN_P296_PFC_1A_SPI_SSL22       = (0x1AU << IOPORT_PFC_OFFSET), ///< P29_6 / SPIn / SPI_SSL22
    IOPORT_PIN_P296_PFC_22_ENCIFOE10       = (0x22U << IOPORT_PFC_OFFSET), ///< P29_6 / ENCIFn / ENCIFOE10
    IOPORT_PIN_P296_PFC_25_HDSL06_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P29_6 / HDSLn / HDSL06_SEL2
    IOPORT_PIN_P297_PFC_09_GTIOC09_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P29_7 / GPT / GTIOC09_3A
    IOPORT_PIN_P297_PFC_0F_ETH2_RXCLK      = (0x0FU << IOPORT_PFC_OFFSET), ///< P29_7 / ETHER_ETHn / ETH2_RXCLK
    IOPORT_PIN_P297_PFC_15_TXDE10          = (0x15U << IOPORT_PFC_OFFSET), ///< P29_7 / SCIEn / TXDE10
    IOPORT_PIN_P297_PFC_1A_SPI_SSL23       = (0x1AU << IOPORT_PFC_OFFSET), ///< P29_7 / SPIn / SPI_SSL23
    IOPORT_PIN_P297_PFC_22_ENCIFDO10       = (0x22U << IOPORT_PFC_OFFSET), ///< P29_7 / ENCIFn / ENCIFDO10
    IOPORT_PIN_P297_PFC_25_HDSL06_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P29_7 / HDSLn / HDSL06_MISO2
    IOPORT_PIN_P300_PFC_09_GTIOC09_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P30_0 / GPT / GTIOC09_3B
    IOPORT_PIN_P300_PFC_0F_ETH2_RXD0       = (0x0FU << IOPORT_PFC_OFFSET), ///< P30_0 / ETHER_ETHn / ETH2_RXD0
    IOPORT_PIN_P300_PFC_15_RXDE10          = (0x15U << IOPORT_PFC_OFFSET), ///< P30_0 / SCIEn / RXDE10
    IOPORT_PIN_P300_PFC_22_ENCIFDI10       = (0x22U << IOPORT_PFC_OFFSET), ///< P30_0 / ENCIFn / ENCIFDI10
    IOPORT_PIN_P300_PFC_25_HDSL06_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P30_0 / HDSLn / HDSL06_MOSI2
    IOPORT_PIN_P301_PFC_09_GTIOC09_4A      = (0x09U << IOPORT_PFC_OFFSET), ///< P30_1 / GPT / GTIOC09_4A
    IOPORT_PIN_P301_PFC_0F_ETH2_RXD1       = (0x0FU << IOPORT_PFC_OFFSET), ///< P30_1 / ETHER_ETHn / ETH2_RXD1
    IOPORT_PIN_P301_PFC_15_SCKE11          = (0x15U << IOPORT_PFC_OFFSET), ///< P30_1 / SCIEn / SCKE11
    IOPORT_PIN_P301_PFC_22_ENCIFCK11       = (0x22U << IOPORT_PFC_OFFSET), ///< P30_1 / ENCIFn / ENCIFCK11
    IOPORT_PIN_P301_PFC_25_HDSL07_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P30_1 / HDSLn / HDSL07_LINK
    IOPORT_PIN_P302_PFC_00_IRQ10           = (0x00U << IOPORT_PFC_OFFSET), ///< P30_2 / IRQ / IRQ10
    IOPORT_PIN_P302_PFC_09_GTIOC09_4B      = (0x09U << IOPORT_PFC_OFFSET), ///< P30_2 / GPT / GTIOC09_4B
    IOPORT_PIN_P302_PFC_0F_ETH2_RXD2       = (0x0FU << IOPORT_PFC_OFFSET), ///< P30_2 / ETHER_ETHn / ETH2_RXD2
    IOPORT_PIN_P302_PFC_15_DEE11           = (0x15U << IOPORT_PFC_OFFSET), ///< P30_2 / SCIEn / DEE11
    IOPORT_PIN_P302_PFC_1A_SPI_MOSI2       = (0x1AU << IOPORT_PFC_OFFSET), ///< P30_2 / SPIn / SPI_MOSI2
    IOPORT_PIN_P302_PFC_22_ENCIFOE11       = (0x22U << IOPORT_PFC_OFFSET), ///< P30_2 / ENCIFn / ENCIFOE11
    IOPORT_PIN_P302_PFC_25_HDSL07_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P30_2 / HDSLn / HDSL07_SMPL
    IOPORT_PIN_P303_PFC_00_IRQ11           = (0x00U << IOPORT_PFC_OFFSET), ///< P30_3 / IRQ / IRQ11
    IOPORT_PIN_P303_PFC_09_GTIOC09_5A      = (0x09U << IOPORT_PFC_OFFSET), ///< P30_3 / GPT / GTIOC09_5A
    IOPORT_PIN_P303_PFC_0F_ETH2_RXD3       = (0x0FU << IOPORT_PFC_OFFSET), ///< P30_3 / ETHER_ETHn / ETH2_RXD3
    IOPORT_PIN_P303_PFC_15_TXDE11          = (0x15U << IOPORT_PFC_OFFSET), ///< P30_3 / SCIEn / TXDE11
    IOPORT_PIN_P303_PFC_1A_SPI_MISO2       = (0x1AU << IOPORT_PFC_OFFSET), ///< P30_3 / SPIn / SPI_MISO2
    IOPORT_PIN_P303_PFC_22_ENCIFDO11       = (0x22U << IOPORT_PFC_OFFSET), ///< P30_3 / ENCIFn / ENCIFDO11
    IOPORT_PIN_P303_PFC_25_HDSL07_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P30_3 / HDSLn / HDSL07_CLK1
    IOPORT_PIN_P304_PFC_09_GTIOC09_5B      = (0x09U << IOPORT_PFC_OFFSET), ///< P30_4 / GPT / GTIOC09_5B
    IOPORT_PIN_P304_PFC_0F_ETH2_RXDV       = (0x0FU << IOPORT_PFC_OFFSET), ///< P30_4 / ETHER_ETHn / ETH2_RXDV
    IOPORT_PIN_P304_PFC_15_RXDE11          = (0x15U << IOPORT_PFC_OFFSET), ///< P30_4 / SCIEn / RXDE11
    IOPORT_PIN_P304_PFC_22_ENCIFDI11       = (0x22U << IOPORT_PFC_OFFSET), ///< P30_4 / ENCIFn / ENCIFDI11
    IOPORT_PIN_P304_PFC_25_HDSL07_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P30_4 / HDSLn / HDSL07_SEL1
    IOPORT_PIN_P305_PFC_09_GTIOC09_6A      = (0x09U << IOPORT_PFC_OFFSET), ///< P30_5 / GPT / GTIOC09_6A
    IOPORT_PIN_P305_PFC_10_GMAC2_MDC       = (0x10U << IOPORT_PFC_OFFSET), ///< P30_5 / ETHER_GMACn / GMAC2_MDC
    IOPORT_PIN_P305_PFC_11_ETHSW_MDC       = (0x11U << IOPORT_PFC_OFFSET), ///< P30_5 / ETHER_ETHSW / ETHSW_MDC
    IOPORT_PIN_P305_PFC_12_ESC_MDC         = (0x12U << IOPORT_PFC_OFFSET), ///< P30_5 / ETHER_ESC / ESC_MDC
    IOPORT_PIN_P305_PFC_1A_SPI_RSPCK3      = (0x1AU << IOPORT_PFC_OFFSET), ///< P30_5 / SPIn / SPI_RSPCK3
    IOPORT_PIN_P305_PFC_24_DUEI07          = (0x24U << IOPORT_PFC_OFFSET), ///< P30_5 / ENDATn / DUEI07
    IOPORT_PIN_P305_PFC_25_HDSL07_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P30_5 / HDSLn / HDSL07_MISO1
    IOPORT_PIN_P306_PFC_09_GTIOC09_6B      = (0x09U << IOPORT_PFC_OFFSET), ///< P30_6 / GPT / GTIOC09_6B
    IOPORT_PIN_P306_PFC_10_GMAC2_MDIO      = (0x10U << IOPORT_PFC_OFFSET), ///< P30_6 / ETHER_GMACn / GMAC2_MDIO
    IOPORT_PIN_P306_PFC_11_ETHSW_MDIO      = (0x11U << IOPORT_PFC_OFFSET), ///< P30_6 / ETHER_ETHSW / ETHSW_MDIO
    IOPORT_PIN_P306_PFC_12_ESC_MDIO        = (0x12U << IOPORT_PFC_OFFSET), ///< P30_6 / ETHER_ESC / ESC_MDIO
    IOPORT_PIN_P306_PFC_1A_SPI_MOSI3       = (0x1AU << IOPORT_PFC_OFFSET), ///< P30_6 / SPIn / SPI_MOSI3
    IOPORT_PIN_P306_PFC_24_TST_OUT07       = (0x24U << IOPORT_PFC_OFFSET), ///< P30_6 / ENDATn / TST_OUT07
    IOPORT_PIN_P306_PFC_25_HDSL07_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P30_6 / HDSLn / HDSL07_MOSI1
    IOPORT_PIN_P307_PFC_00_IRQ14           = (0x00U << IOPORT_PFC_OFFSET), ///< P30_7 / IRQ / IRQ14
    IOPORT_PIN_P307_PFC_11_ETHSW_PHYLINK2  = (0x11U << IOPORT_PFC_OFFSET), ///< P30_7 / ETHER_ETHSW / ETHSW_PHYLINK2
    IOPORT_PIN_P307_PFC_12_ESC_PHYLINK2    = (0x12U << IOPORT_PFC_OFFSET), ///< P30_7 / ETHER_ESC / ESC_PHYLINK2
    IOPORT_PIN_P307_PFC_1A_SPI_MISO3       = (0x1AU << IOPORT_PFC_OFFSET), ///< P30_7 / SPIn / SPI_MISO3
    IOPORT_PIN_P307_PFC_1E_MCLK30          = (0x1EU << IOPORT_PFC_OFFSET), ///< P30_7 / DSMIFn / MCLK30
    IOPORT_PIN_P307_PFC_24_SI07            = (0x24U << IOPORT_PFC_OFFSET), ///< P30_7 / ENDATn / SI07
    IOPORT_PIN_P307_PFC_25_HDSL07_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P30_7 / HDSLn / HDSL07_CLK2
    IOPORT_PIN_P307_PFC_29_SD1_IOVS        = (0x29U << IOPORT_PFC_OFFSET), ///< P30_7 / SDHI / SD1_IOVS
    IOPORT_PIN_P310_PFC_02_ETH2_REFCLK     = (0x02U << IOPORT_PFC_OFFSET), ///< P31_0 / ETHER_ETHn / ETH2_REFCLK
    IOPORT_PIN_P310_PFC_03_RMII2_REFCLK    = (0x03U << IOPORT_PFC_OFFSET), ///< P31_0 / ETHER_ETHn / RMII2_REFCLK
    IOPORT_PIN_P310_PFC_0C_GTETRGSA        = (0x0CU << IOPORT_PFC_OFFSET), ///< P31_0 / POEG / GTETRGSA
    IOPORT_PIN_P310_PFC_1A_SPI_SSL30       = (0x1AU << IOPORT_PFC_OFFSET), ///< P31_0 / SPIn / SPI_SSL30
    IOPORT_PIN_P310_PFC_25_HDSL07_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P31_0 / HDSLn / HDSL07_SEL2
    IOPORT_PIN_P311_PFC_00_IRQ13           = (0x00U << IOPORT_PFC_OFFSET), ///< P31_1 / IRQ / IRQ13
    IOPORT_PIN_P311_PFC_0C_GTETRGSB        = (0x0CU << IOPORT_PFC_OFFSET), ///< P31_1 / POEG / GTETRGSB
    IOPORT_PIN_P311_PFC_0F_ETH2_RXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P31_1 / ETHER_ETHn / ETH2_RXER
    IOPORT_PIN_P311_PFC_1A_SPI_SSL31       = (0x1AU << IOPORT_PFC_OFFSET), ///< P31_1 / SPIn / SPI_SSL31
    IOPORT_PIN_P311_PFC_25_HDSL07_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P31_1 / HDSLn / HDSL07_MISO2
    IOPORT_PIN_P312_PFC_08_POE0            = (0x08U << IOPORT_PFC_OFFSET), ///< P31_2 / POE3 / POE0
    IOPORT_PIN_P312_PFC_0F_ETH2_TXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P31_2 / ETHER_ETHn / ETH2_TXER
    IOPORT_PIN_P312_PFC_15_SCKE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P31_2 / SCIEn / SCKE09
    IOPORT_PIN_P312_PFC_1A_SPI_SSL32       = (0x1AU << IOPORT_PFC_OFFSET), ///< P31_2 / SPIn / SPI_SSL32
    IOPORT_PIN_P312_PFC_1D_MCLK80          = (0x1DU << IOPORT_PFC_OFFSET), ///< P31_2 / DSMIFn / MCLK80
    IOPORT_PIN_P312_PFC_1E_MDAT30          = (0x1EU << IOPORT_PFC_OFFSET), ///< P31_2 / DSMIFn / MDAT30
    IOPORT_PIN_P312_PFC_20_HSPI_IO4        = (0x20U << IOPORT_PFC_OFFSET), ///< P31_2 / SHOSTIF / HSPI_IO4
    IOPORT_PIN_P312_PFC_22_ENCIFCK09       = (0x22U << IOPORT_PFC_OFFSET), ///< P31_2 / ENCIFn / ENCIFCK09
    IOPORT_PIN_P312_PFC_25_HDSL07_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P31_2 / HDSLn / HDSL07_MOSI2
    IOPORT_PIN_P312_PFC_26_POUTA           = (0x26U << IOPORT_PFC_OFFSET), ///< P31_2 / ENCOUT / POUTA
    IOPORT_PIN_P313_PFC_08_POE4            = (0x08U << IOPORT_PFC_OFFSET), ///< P31_3 / POE3 / POE4
    IOPORT_PIN_P313_PFC_0F_ETH2_RXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P31_3 / ETHER_ETHn / ETH2_RXER
    IOPORT_PIN_P313_PFC_11_ETHSW_TDMAOUT1  = (0x11U << IOPORT_PFC_OFFSET), ///< P31_3 / ETHER_ETHSW / ETHSW_TDMAOUT1
    IOPORT_PIN_P313_PFC_12_ESC_LEDERR      = (0x12U << IOPORT_PFC_OFFSET), ///< P31_3 / ETHER_ESC / ESC_LEDERR
    IOPORT_PIN_P313_PFC_15_DEE09           = (0x15U << IOPORT_PFC_OFFSET), ///< P31_3 / SCIEn / DEE09
    IOPORT_PIN_P313_PFC_1A_SPI_SSL33       = (0x1AU << IOPORT_PFC_OFFSET), ///< P31_3 / SPIn / SPI_SSL33
    IOPORT_PIN_P313_PFC_1D_MDAT80          = (0x1DU << IOPORT_PFC_OFFSET), ///< P31_3 / DSMIFn / MDAT80
    IOPORT_PIN_P313_PFC_1E_MCLK31          = (0x1EU << IOPORT_PFC_OFFSET), ///< P31_3 / DSMIFn / MCLK31
    IOPORT_PIN_P313_PFC_20_HSPI_IO5        = (0x20U << IOPORT_PFC_OFFSET), ///< P31_3 / SHOSTIF / HSPI_IO5
    IOPORT_PIN_P313_PFC_22_ENCIFOE09       = (0x22U << IOPORT_PFC_OFFSET), ///< P31_3 / ENCIFn / ENCIFOE09
    IOPORT_PIN_P313_PFC_25_HDSL08_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P31_3 / HDSLn / HDSL08_LINK
    IOPORT_PIN_P314_PFC_05_DREQ            = (0x05U << IOPORT_PFC_OFFSET), ///< P31_4 / DMAC / DREQ
    IOPORT_PIN_P314_PFC_08_POE8            = (0x08U << IOPORT_PFC_OFFSET), ///< P31_4 / POE3 / POE8
    IOPORT_PIN_P314_PFC_0F_ETH2_CRS        = (0x0FU << IOPORT_PFC_OFFSET), ///< P31_4 / ETHER_ETHn / ETH2_CRS
    IOPORT_PIN_P314_PFC_11_ETHSW_PTPOUT2   = (0x11U << IOPORT_PFC_OFFSET), ///< P31_4 / ETHER_ETHSW / ETHSW_PTPOUT2
    IOPORT_PIN_P314_PFC_12_ESC_SYNC0       = (0x12U << IOPORT_PFC_OFFSET), ///< P31_4 / ETHER_ESC / ESC_SYNC0
    IOPORT_PIN_P314_PFC_15_TXDE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P31_4 / SCIEn / TXDE09
    IOPORT_PIN_P314_PFC_1A_SPI_RSPCK0      = (0x1AU << IOPORT_PFC_OFFSET), ///< P31_4 / SPIn / SPI_RSPCK0
    IOPORT_PIN_P314_PFC_1B_SPI_SSL30       = (0x1BU << IOPORT_PFC_OFFSET), ///< P31_4 / SPIn / SPI_SSL30
    IOPORT_PIN_P314_PFC_1D_MCLK81          = (0x1DU << IOPORT_PFC_OFFSET), ///< P31_4 / DSMIFn / MCLK81
    IOPORT_PIN_P314_PFC_1E_MDAT31          = (0x1EU << IOPORT_PFC_OFFSET), ///< P31_4 / DSMIFn / MDAT31
    IOPORT_PIN_P314_PFC_20_HSPI_IO6        = (0x20U << IOPORT_PFC_OFFSET), ///< P31_4 / SHOSTIF / HSPI_IO6
    IOPORT_PIN_P314_PFC_22_ENCIFDO09       = (0x22U << IOPORT_PFC_OFFSET), ///< P31_4 / ENCIFn / ENCIFDO09
    IOPORT_PIN_P314_PFC_25_HDSL08_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P31_4 / HDSLn / HDSL08_SMPL
    IOPORT_PIN_P314_PFC_26_POUTB           = (0x26U << IOPORT_PFC_OFFSET), ///< P31_4 / ENCOUT / POUTB
    IOPORT_PIN_P315_PFC_05_DACK            = (0x05U << IOPORT_PFC_OFFSET), ///< P31_5 / DMAC / DACK
    IOPORT_PIN_P315_PFC_08_POE10           = (0x08U << IOPORT_PFC_OFFSET), ///< P31_5 / POE3 / POE10
    IOPORT_PIN_P315_PFC_0F_ETH2_COL        = (0x0FU << IOPORT_PFC_OFFSET), ///< P31_5 / ETHER_ETHn / ETH2_COL
    IOPORT_PIN_P315_PFC_11_ETHSW_PTPOUT3   = (0x11U << IOPORT_PFC_OFFSET), ///< P31_5 / ETHER_ETHSW / ETHSW_PTPOUT3
    IOPORT_PIN_P315_PFC_12_ESC_SYNC1       = (0x12U << IOPORT_PFC_OFFSET), ///< P31_5 / ETHER_ESC / ESC_SYNC1
    IOPORT_PIN_P315_PFC_15_RXDE09          = (0x15U << IOPORT_PFC_OFFSET), ///< P31_5 / SCIEn / RXDE09
    IOPORT_PIN_P315_PFC_1A_SPI_MOSI0       = (0x1AU << IOPORT_PFC_OFFSET), ///< P31_5 / SPIn / SPI_MOSI0
    IOPORT_PIN_P315_PFC_1B_SPI_SSL31       = (0x1BU << IOPORT_PFC_OFFSET), ///< P31_5 / SPIn / SPI_SSL31
    IOPORT_PIN_P315_PFC_1D_MDAT81          = (0x1DU << IOPORT_PFC_OFFSET), ///< P31_5 / DSMIFn / MDAT81
    IOPORT_PIN_P315_PFC_1E_MCLK32          = (0x1EU << IOPORT_PFC_OFFSET), ///< P31_5 / DSMIFn / MCLK32
    IOPORT_PIN_P315_PFC_20_HSPI_IO7        = (0x20U << IOPORT_PFC_OFFSET), ///< P31_5 / SHOSTIF / HSPI_IO7
    IOPORT_PIN_P315_PFC_22_ENCIFDI09       = (0x22U << IOPORT_PFC_OFFSET), ///< P31_5 / ENCIFn / ENCIFDI09
    IOPORT_PIN_P315_PFC_25_HDSL08_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P31_5 / HDSLn / HDSL08_CLK1
    IOPORT_PIN_P315_PFC_26_POUTZ           = (0x26U << IOPORT_PFC_OFFSET), ///< P31_5 / ENCOUT / POUTZ
    IOPORT_PIN_P316_PFC_04_A16             = (0x04U << IOPORT_PFC_OFFSET), ///< P31_6 / BSC / A16
    IOPORT_PIN_P316_PFC_05_TEND            = (0x05U << IOPORT_PFC_OFFSET), ///< P31_6 / DMAC / TEND
    IOPORT_PIN_P316_PFC_08_POE11           = (0x08U << IOPORT_PFC_OFFSET), ///< P31_6 / POE3 / POE11
    IOPORT_PIN_P316_PFC_10_GMAC2_PTPTRG0   = (0x10U << IOPORT_PFC_OFFSET), ///< P31_6 / ETHER_GMACn / GMAC2_PTPTRG0
    IOPORT_PIN_P316_PFC_11_ETHSW_TDMAOUT0  = (0x11U << IOPORT_PFC_OFFSET), ///< P31_6 / ETHER_ETHSW / ETHSW_TDMAOUT0
    IOPORT_PIN_P316_PFC_12_ESC_LEDRUN      = (0x12U << IOPORT_PFC_OFFSET), ///< P31_6 / ETHER_ESC / ESC_LEDRUN
    IOPORT_PIN_P316_PFC_15_SCKE11          = (0x15U << IOPORT_PFC_OFFSET), ///< P31_6 / SCIEn / SCKE11
    IOPORT_PIN_P316_PFC_16_SCKE01          = (0x16U << IOPORT_PFC_OFFSET), ///< P31_6 / SCIEn / SCKE01
    IOPORT_PIN_P316_PFC_1A_SPI_MISO0       = (0x1AU << IOPORT_PFC_OFFSET), ///< P31_6 / SPIn / SPI_MISO0
    IOPORT_PIN_P316_PFC_1E_MDAT32          = (0x1EU << IOPORT_PFC_OFFSET), ///< P31_6 / DSMIFn / MDAT32
    IOPORT_PIN_P316_PFC_22_ENCIFCK15       = (0x22U << IOPORT_PFC_OFFSET), ///< P31_6 / ENCIFn / ENCIFCK15
    IOPORT_PIN_P316_PFC_23_ENCIFCK01       = (0x23U << IOPORT_PFC_OFFSET), ///< P31_6 / ENCIFn / ENCIFCK01
    IOPORT_PIN_P316_PFC_25_HDSL08_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P31_6 / HDSLn / HDSL08_SEL1
    IOPORT_PIN_P317_PFC_10_GMAC2_PTPTRG1   = (0x10U << IOPORT_PFC_OFFSET), ///< P31_7 / ETHER_GMACn / GMAC2_PTPTRG1
    IOPORT_PIN_P317_PFC_15_DEE11           = (0x15U << IOPORT_PFC_OFFSET), ///< P31_7 / SCIEn / DEE11
    IOPORT_PIN_P317_PFC_16_DEE01           = (0x16U << IOPORT_PFC_OFFSET), ///< P31_7 / SCIEn / DEE01
    IOPORT_PIN_P317_PFC_1A_SPI_SSL00       = (0x1AU << IOPORT_PFC_OFFSET), ///< P31_7 / SPIn / SPI_SSL00
    IOPORT_PIN_P317_PFC_22_ENCIFOE15       = (0x22U << IOPORT_PFC_OFFSET), ///< P31_7 / ENCIFn / ENCIFOE15
    IOPORT_PIN_P317_PFC_23_ENCIFOE01       = (0x23U << IOPORT_PFC_OFFSET), ///< P31_7 / ENCIFn / ENCIFOE01
    IOPORT_PIN_P317_PFC_25_HDSL08_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P31_7 / HDSLn / HDSL08_MISO1
    IOPORT_PIN_P320_PFC_15_TXDE11          = (0x15U << IOPORT_PFC_OFFSET), ///< P32_0 / SCIEn / TXDE11
    IOPORT_PIN_P320_PFC_16_TXDE01          = (0x16U << IOPORT_PFC_OFFSET), ///< P32_0 / SCIEn / TXDE01
    IOPORT_PIN_P320_PFC_1A_SPI_SSL01       = (0x1AU << IOPORT_PFC_OFFSET), ///< P32_0 / SPIn / SPI_SSL01
    IOPORT_PIN_P320_PFC_22_ENCIFDO15       = (0x22U << IOPORT_PFC_OFFSET), ///< P32_0 / ENCIFn / ENCIFDO15
    IOPORT_PIN_P320_PFC_23_ENCIFDO01       = (0x23U << IOPORT_PFC_OFFSET), ///< P32_0 / ENCIFn / ENCIFDO01
    IOPORT_PIN_P320_PFC_25_HDSL08_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P32_0 / HDSLn / HDSL08_MOSI1
    IOPORT_PIN_P321_PFC_15_RXDE11          = (0x15U << IOPORT_PFC_OFFSET), ///< P32_1 / SCIEn / RXDE11
    IOPORT_PIN_P321_PFC_16_RXDE01          = (0x16U << IOPORT_PFC_OFFSET), ///< P32_1 / SCIEn / RXDE01
    IOPORT_PIN_P321_PFC_1A_SPI_SSL02       = (0x1AU << IOPORT_PFC_OFFSET), ///< P32_1 / SPIn / SPI_SSL02
    IOPORT_PIN_P321_PFC_22_ENCIFDI15       = (0x22U << IOPORT_PFC_OFFSET), ///< P32_1 / ENCIFn / ENCIFDI15
    IOPORT_PIN_P321_PFC_23_ENCIFDI01       = (0x23U << IOPORT_PFC_OFFSET), ///< P32_1 / ENCIFn / ENCIFDI01
    IOPORT_PIN_P321_PFC_25_HDSL08_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P32_1 / HDSLn / HDSL08_CLK2
    IOPORT_PIN_P322_PFC_09_GTIOC10_0A      = (0x09U << IOPORT_PFC_OFFSET), ///< P32_2 / GPT / GTIOC10_0A
    IOPORT_PIN_P322_PFC_0A_GTIOC01_0A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P32_2 / GPT / GTIOC01_0A
    IOPORT_PIN_P322_PFC_15_SCKE10          = (0x15U << IOPORT_PFC_OFFSET), ///< P32_2 / SCIEn / SCKE10
    IOPORT_PIN_P322_PFC_1A_SPI_SSL03       = (0x1AU << IOPORT_PFC_OFFSET), ///< P32_2 / SPIn / SPI_SSL03
    IOPORT_PIN_P322_PFC_22_ENCIFCK10       = (0x22U << IOPORT_PFC_OFFSET), ///< P32_2 / ENCIFn / ENCIFCK10
    IOPORT_PIN_P322_PFC_25_HDSL08_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P32_2 / HDSLn / HDSL08_SEL2
    IOPORT_PIN_P323_PFC_09_GTIOC10_0B      = (0x09U << IOPORT_PFC_OFFSET), ///< P32_3 / GPT / GTIOC10_0B
    IOPORT_PIN_P323_PFC_0A_GTIOC01_0B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P32_3 / GPT / GTIOC01_0B
    IOPORT_PIN_P323_PFC_15_DEE10           = (0x15U << IOPORT_PFC_OFFSET), ///< P32_3 / SCIEn / DEE10
    IOPORT_PIN_P323_PFC_1A_SPI_RSPCK1      = (0x1AU << IOPORT_PFC_OFFSET), ///< P32_3 / SPIn / SPI_RSPCK1
    IOPORT_PIN_P323_PFC_22_ENCIFOE10       = (0x22U << IOPORT_PFC_OFFSET), ///< P32_3 / ENCIFn / ENCIFOE10
    IOPORT_PIN_P323_PFC_25_HDSL08_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P32_3 / HDSLn / HDSL08_MISO2
    IOPORT_PIN_P324_PFC_09_GTIOC10_1A      = (0x09U << IOPORT_PFC_OFFSET), ///< P32_4 / GPT / GTIOC10_1A
    IOPORT_PIN_P324_PFC_0A_GTIOC01_1A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P32_4 / GPT / GTIOC01_1A
    IOPORT_PIN_P324_PFC_15_TXDE10          = (0x15U << IOPORT_PFC_OFFSET), ///< P32_4 / SCIEn / TXDE10
    IOPORT_PIN_P324_PFC_1A_SPI_MOSI1       = (0x1AU << IOPORT_PFC_OFFSET), ///< P32_4 / SPIn / SPI_MOSI1
    IOPORT_PIN_P324_PFC_22_ENCIFDO10       = (0x22U << IOPORT_PFC_OFFSET), ///< P32_4 / ENCIFn / ENCIFDO10
    IOPORT_PIN_P324_PFC_25_HDSL08_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P32_4 / HDSLn / HDSL08_MOSI2
    IOPORT_PIN_P325_PFC_09_GTIOC10_1B      = (0x09U << IOPORT_PFC_OFFSET), ///< P32_5 / GPT / GTIOC10_1B
    IOPORT_PIN_P325_PFC_0A_GTIOC01_1B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P32_5 / GPT / GTIOC01_1B
    IOPORT_PIN_P325_PFC_15_RXDE10          = (0x15U << IOPORT_PFC_OFFSET), ///< P32_5 / SCIEn / RXDE10
    IOPORT_PIN_P325_PFC_1A_SPI_MISO1       = (0x1AU << IOPORT_PFC_OFFSET), ///< P32_5 / SPIn / SPI_MISO1
    IOPORT_PIN_P325_PFC_22_ENCIFDI10       = (0x22U << IOPORT_PFC_OFFSET), ///< P32_5 / ENCIFn / ENCIFDI10
    IOPORT_PIN_P325_PFC_25_HDSL09_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P32_5 / HDSLn / HDSL09_LINK
    IOPORT_PIN_P326_PFC_09_GTIOC10_2A      = (0x09U << IOPORT_PFC_OFFSET), ///< P32_6 / GPT / GTIOC10_2A
    IOPORT_PIN_P326_PFC_0A_GTIOC01_2A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P32_6 / GPT / GTIOC01_2A
    IOPORT_PIN_P326_PFC_15_SCKE11          = (0x15U << IOPORT_PFC_OFFSET), ///< P32_6 / SCIEn / SCKE11
    IOPORT_PIN_P326_PFC_1A_SPI_SSL10       = (0x1AU << IOPORT_PFC_OFFSET), ///< P32_6 / SPIn / SPI_SSL10
    IOPORT_PIN_P326_PFC_22_ENCIFCK11       = (0x22U << IOPORT_PFC_OFFSET), ///< P32_6 / ENCIFn / ENCIFCK11
    IOPORT_PIN_P326_PFC_25_HDSL09_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P32_6 / HDSLn / HDSL09_SMPL
    IOPORT_PIN_P327_PFC_09_GTIOC10_2B      = (0x09U << IOPORT_PFC_OFFSET), ///< P32_7 / GPT / GTIOC10_2B
    IOPORT_PIN_P327_PFC_0A_GTIOC01_2B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P32_7 / GPT / GTIOC01_2B
    IOPORT_PIN_P327_PFC_15_DEE11           = (0x15U << IOPORT_PFC_OFFSET), ///< P32_7 / SCIEn / DEE11
    IOPORT_PIN_P327_PFC_1A_SPI_SSL11       = (0x1AU << IOPORT_PFC_OFFSET), ///< P32_7 / SPIn / SPI_SSL11
    IOPORT_PIN_P327_PFC_22_ENCIFOE11       = (0x22U << IOPORT_PFC_OFFSET), ///< P32_7 / ENCIFn / ENCIFOE11
    IOPORT_PIN_P327_PFC_25_HDSL09_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P32_7 / HDSLn / HDSL09_CLK1
    IOPORT_PIN_P330_PFC_09_GTIOC10_3A      = (0x09U << IOPORT_PFC_OFFSET), ///< P33_0 / GPT / GTIOC10_3A
    IOPORT_PIN_P330_PFC_15_TXDE11          = (0x15U << IOPORT_PFC_OFFSET), ///< P33_0 / SCIEn / TXDE11
    IOPORT_PIN_P330_PFC_1A_SPI_SSL12       = (0x1AU << IOPORT_PFC_OFFSET), ///< P33_0 / SPIn / SPI_SSL12
    IOPORT_PIN_P330_PFC_1D_MCLK82          = (0x1DU << IOPORT_PFC_OFFSET), ///< P33_0 / DSMIFn / MCLK82
    IOPORT_PIN_P330_PFC_22_ENCIFDO11       = (0x22U << IOPORT_PFC_OFFSET), ///< P33_0 / ENCIFn / ENCIFDO11
    IOPORT_PIN_P330_PFC_25_HDSL09_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P33_0 / HDSLn / HDSL09_SEL1
    IOPORT_PIN_P331_PFC_09_GTIOC10_3B      = (0x09U << IOPORT_PFC_OFFSET), ///< P33_1 / GPT / GTIOC10_3B
    IOPORT_PIN_P331_PFC_15_RXDE11          = (0x15U << IOPORT_PFC_OFFSET), ///< P33_1 / SCIEn / RXDE11
    IOPORT_PIN_P331_PFC_1A_SPI_SSL13       = (0x1AU << IOPORT_PFC_OFFSET), ///< P33_1 / SPIn / SPI_SSL13
    IOPORT_PIN_P331_PFC_1D_MDAT82          = (0x1DU << IOPORT_PFC_OFFSET), ///< P33_1 / DSMIFn / MDAT82
    IOPORT_PIN_P331_PFC_22_ENCIFDI11       = (0x22U << IOPORT_PFC_OFFSET), ///< P33_1 / ENCIFn / ENCIFDI11
    IOPORT_PIN_P331_PFC_25_HDSL09_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P33_1 / HDSLn / HDSL09_MISO1
    IOPORT_PIN_P332_PFC_04_A16             = (0x04U << IOPORT_PFC_OFFSET), ///< P33_2 / BSC / A16
    IOPORT_PIN_P332_PFC_09_GTADSM00_0      = (0x09U << IOPORT_PFC_OFFSET), ///< P33_2 / GPT / GTADSM00_0
    IOPORT_PIN_P332_PFC_0F_ETH3_TXCLK      = (0x0FU << IOPORT_PFC_OFFSET), ///< P33_2 / ETHER_ETHn / ETH3_TXCLK
    IOPORT_PIN_P332_PFC_14_SCK1            = (0x14U << IOPORT_PFC_OFFSET), ///< P33_2 / SCIn / SCK1
    IOPORT_PIN_P332_PFC_15_SCKE01          = (0x15U << IOPORT_PFC_OFFSET), ///< P33_2 / SCIEn / SCKE01
    IOPORT_PIN_P332_PFC_1A_SPI_RSPCK1      = (0x1AU << IOPORT_PFC_OFFSET), ///< P33_2 / SPIn / SPI_RSPCK1
    IOPORT_PIN_P332_PFC_1B_SPI_SSL30       = (0x1BU << IOPORT_PFC_OFFSET), ///< P33_2 / SPIn / SPI_SSL30
    IOPORT_PIN_P332_PFC_1D_MCLK50          = (0x1DU << IOPORT_PFC_OFFSET), ///< P33_2 / DSMIFn / MCLK50
    IOPORT_PIN_P332_PFC_22_ENCIFCK01       = (0x22U << IOPORT_PFC_OFFSET), ///< P33_2 / ENCIFn / ENCIFCK01
    IOPORT_PIN_P332_PFC_25_HDSL09_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P33_2 / HDSLn / HDSL09_MOSI1
    IOPORT_PIN_P333_PFC_00_IRQ12           = (0x00U << IOPORT_PFC_OFFSET), ///< P33_3 / IRQ / IRQ12
    IOPORT_PIN_P333_PFC_04_A17             = (0x04U << IOPORT_PFC_OFFSET), ///< P33_3 / BSC / A17
    IOPORT_PIN_P333_PFC_09_GTADSM00_1      = (0x09U << IOPORT_PFC_OFFSET), ///< P33_3 / GPT / GTADSM00_1
    IOPORT_PIN_P333_PFC_0F_ETH3_TXD0       = (0x0FU << IOPORT_PFC_OFFSET), ///< P33_3 / ETHER_ETHn / ETH3_TXD0
    IOPORT_PIN_P333_PFC_14_RXD1_SCL1_MISO1 = (0x14U << IOPORT_PFC_OFFSET), ///< P33_3 / SCIn / RXD1_SCL1_MISO1
    IOPORT_PIN_P333_PFC_15_DEE01           = (0x15U << IOPORT_PFC_OFFSET), ///< P33_3 / SCIEn / DEE01
    IOPORT_PIN_P333_PFC_1A_SPI_MOSI1       = (0x1AU << IOPORT_PFC_OFFSET), ///< P33_3 / SPIn / SPI_MOSI1
    IOPORT_PIN_P333_PFC_1B_SPI_RSPCK0      = (0x1BU << IOPORT_PFC_OFFSET), ///< P33_3 / SPIn / SPI_RSPCK0
    IOPORT_PIN_P333_PFC_1D_MDAT50          = (0x1DU << IOPORT_PFC_OFFSET), ///< P33_3 / DSMIFn / MDAT50
    IOPORT_PIN_P333_PFC_22_ENCIFOE01       = (0x22U << IOPORT_PFC_OFFSET), ///< P33_3 / ENCIFn / ENCIFOE01
    IOPORT_PIN_P333_PFC_25_HDSL09_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P33_3 / HDSLn / HDSL09_CLK2
    IOPORT_PIN_P333_PFC_27_PCIE_RSTOUT0B   = (0x27U << IOPORT_PFC_OFFSET), ///< P33_3 / PCIE / PCIE_RSTOUT0B
    IOPORT_PIN_P334_PFC_00_IRQ13           = (0x00U << IOPORT_PFC_OFFSET), ///< P33_4 / IRQ / IRQ13
    IOPORT_PIN_P334_PFC_04_A18             = (0x04U << IOPORT_PFC_OFFSET), ///< P33_4 / BSC / A18
    IOPORT_PIN_P334_PFC_09_GTADSM01_0      = (0x09U << IOPORT_PFC_OFFSET), ///< P33_4 / GPT / GTADSM01_0
    IOPORT_PIN_P334_PFC_0F_ETH3_TXD1       = (0x0FU << IOPORT_PFC_OFFSET), ///< P33_4 / ETHER_ETHn / ETH3_TXD1
    IOPORT_PIN_P334_PFC_14_TXD1_SDA1_MOSI1 = (0x14U << IOPORT_PFC_OFFSET), ///< P33_4 / SCIn / TXD1_SDA1_MOSI1
    IOPORT_PIN_P334_PFC_15_TXDE01          = (0x15U << IOPORT_PFC_OFFSET), ///< P33_4 / SCIEn / TXDE01
    IOPORT_PIN_P334_PFC_1A_SPI_MISO1       = (0x1AU << IOPORT_PFC_OFFSET), ///< P33_4 / SPIn / SPI_MISO1
    IOPORT_PIN_P334_PFC_1B_SPI_MOSI0       = (0x1BU << IOPORT_PFC_OFFSET), ///< P33_4 / SPIn / SPI_MOSI0
    IOPORT_PIN_P334_PFC_1D_MCLK51          = (0x1DU << IOPORT_PFC_OFFSET), ///< P33_4 / DSMIFn / MCLK51
    IOPORT_PIN_P334_PFC_22_ENCIFDO01       = (0x22U << IOPORT_PFC_OFFSET), ///< P33_4 / ENCIFn / ENCIFDO01
    IOPORT_PIN_P334_PFC_25_HDSL09_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P33_4 / HDSLn / HDSL09_SEL2
    IOPORT_PIN_P334_PFC_27_PCIE_RSTOUT1B   = (0x27U << IOPORT_PFC_OFFSET), ///< P33_4 / PCIE / PCIE_RSTOUT1B
    IOPORT_PIN_P335_PFC_00_IRQ14           = (0x00U << IOPORT_PFC_OFFSET), ///< P33_5 / IRQ / IRQ14
    IOPORT_PIN_P335_PFC_04_A19             = (0x04U << IOPORT_PFC_OFFSET), ///< P33_5 / BSC / A19
    IOPORT_PIN_P335_PFC_09_GTADSM01_1      = (0x09U << IOPORT_PFC_OFFSET), ///< P33_5 / GPT / GTADSM01_1
    IOPORT_PIN_P335_PFC_0F_ETH3_TXD2       = (0x0FU << IOPORT_PFC_OFFSET), ///< P33_5 / ETHER_ETHn / ETH3_TXD2
    IOPORT_PIN_P335_PFC_14_RXD2_SCL2_MISO2 = (0x14U << IOPORT_PFC_OFFSET), ///< P33_5 / SCIn / RXD2_SCL2_MISO2
    IOPORT_PIN_P335_PFC_15_RXDE01          = (0x15U << IOPORT_PFC_OFFSET), ///< P33_5 / SCIEn / RXDE01
    IOPORT_PIN_P335_PFC_1A_SPI_SSL10       = (0x1AU << IOPORT_PFC_OFFSET), ///< P33_5 / SPIn / SPI_SSL10
    IOPORT_PIN_P335_PFC_1B_SPI_MISO0       = (0x1BU << IOPORT_PFC_OFFSET), ///< P33_5 / SPIn / SPI_MISO0
    IOPORT_PIN_P335_PFC_1D_MDAT51          = (0x1DU << IOPORT_PFC_OFFSET), ///< P33_5 / DSMIFn / MDAT51
    IOPORT_PIN_P335_PFC_22_ENCIFDI01       = (0x22U << IOPORT_PFC_OFFSET), ///< P33_5 / ENCIFn / ENCIFDI01
    IOPORT_PIN_P335_PFC_25_HDSL09_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P33_5 / HDSLn / HDSL09_MISO2
    IOPORT_PIN_P336_PFC_00_IRQ15           = (0x00U << IOPORT_PFC_OFFSET), ///< P33_6 / IRQ / IRQ15
    IOPORT_PIN_P336_PFC_04_A20             = (0x04U << IOPORT_PFC_OFFSET), ///< P33_6 / BSC / A20
    IOPORT_PIN_P336_PFC_09_GTADSM02_0      = (0x09U << IOPORT_PFC_OFFSET), ///< P33_6 / GPT / GTADSM02_0
    IOPORT_PIN_P336_PFC_0F_ETH3_TXD3       = (0x0FU << IOPORT_PFC_OFFSET), ///< P33_6 / ETHER_ETHn / ETH3_TXD3
    IOPORT_PIN_P336_PFC_14_TXD2_SDA2_MOSI2 = (0x14U << IOPORT_PFC_OFFSET), ///< P33_6 / SCIn / TXD2_SDA2_MOSI2
    IOPORT_PIN_P336_PFC_15_SCKE06          = (0x15U << IOPORT_PFC_OFFSET), ///< P33_6 / SCIEn / SCKE06
    IOPORT_PIN_P336_PFC_1A_SPI_SSL11       = (0x1AU << IOPORT_PFC_OFFSET), ///< P33_6 / SPIn / SPI_SSL11
    IOPORT_PIN_P336_PFC_1B_SPI_SSL00       = (0x1BU << IOPORT_PFC_OFFSET), ///< P33_6 / SPIn / SPI_SSL00
    IOPORT_PIN_P336_PFC_1D_MCLK52          = (0x1DU << IOPORT_PFC_OFFSET), ///< P33_6 / DSMIFn / MCLK52
    IOPORT_PIN_P336_PFC_22_ENCIFCK06       = (0x22U << IOPORT_PFC_OFFSET), ///< P33_6 / ENCIFn / ENCIFCK06
    IOPORT_PIN_P336_PFC_25_HDSL09_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P33_6 / HDSLn / HDSL09_MOSI2
    IOPORT_PIN_P337_PFC_04_A21             = (0x04U << IOPORT_PFC_OFFSET), ///< P33_7 / BSC / A21
    IOPORT_PIN_P337_PFC_09_GTADSM02_1      = (0x09U << IOPORT_PFC_OFFSET), ///< P33_7 / GPT / GTADSM02_1
    IOPORT_PIN_P337_PFC_0F_ETH3_TXEN       = (0x0FU << IOPORT_PFC_OFFSET), ///< P33_7 / ETHER_ETHn / ETH3_TXEN
    IOPORT_PIN_P337_PFC_15_DEE06           = (0x15U << IOPORT_PFC_OFFSET), ///< P33_7 / SCIEn / DEE06
    IOPORT_PIN_P337_PFC_1A_SPI_RSPCK2      = (0x1AU << IOPORT_PFC_OFFSET), ///< P33_7 / SPIn / SPI_RSPCK2
    IOPORT_PIN_P337_PFC_1D_MDAT52          = (0x1DU << IOPORT_PFC_OFFSET), ///< P33_7 / DSMIFn / MDAT52
    IOPORT_PIN_P337_PFC_22_ENCIFOE06       = (0x22U << IOPORT_PFC_OFFSET), ///< P33_7 / ENCIFn / ENCIFOE06
    IOPORT_PIN_P337_PFC_25_HDSL10_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P33_7 / HDSLn / HDSL10_LINK
    IOPORT_PIN_P340_PFC_04_A22             = (0x04U << IOPORT_PFC_OFFSET), ///< P34_0 / BSC / A22
    IOPORT_PIN_P340_PFC_09_GTADSM03_0      = (0x09U << IOPORT_PFC_OFFSET), ///< P34_0 / GPT / GTADSM03_0
    IOPORT_PIN_P340_PFC_0A_GTIOC03_0A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P34_0 / GPT / GTIOC03_0A
    IOPORT_PIN_P340_PFC_0F_ETH3_RXCLK      = (0x0FU << IOPORT_PFC_OFFSET), ///< P34_0 / ETHER_ETHn / ETH3_RXCLK
    IOPORT_PIN_P340_PFC_15_TXDE06          = (0x15U << IOPORT_PFC_OFFSET), ///< P34_0 / SCIEn / TXDE06
    IOPORT_PIN_P340_PFC_1A_SPI_MOSI2       = (0x1AU << IOPORT_PFC_OFFSET), ///< P34_0 / SPIn / SPI_MOSI2
    IOPORT_PIN_P340_PFC_22_ENCIFDO06       = (0x22U << IOPORT_PFC_OFFSET), ///< P34_0 / ENCIFn / ENCIFDO06
    IOPORT_PIN_P340_PFC_25_HDSL10_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P34_0 / HDSLn / HDSL10_SMPL
    IOPORT_PIN_P341_PFC_04_A23             = (0x04U << IOPORT_PFC_OFFSET), ///< P34_1 / BSC / A23
    IOPORT_PIN_P341_PFC_09_GTADSM03_1      = (0x09U << IOPORT_PFC_OFFSET), ///< P34_1 / GPT / GTADSM03_1
    IOPORT_PIN_P341_PFC_0A_GTIOC03_0B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P34_1 / GPT / GTIOC03_0B
    IOPORT_PIN_P341_PFC_0F_ETH3_RXD0       = (0x0FU << IOPORT_PFC_OFFSET), ///< P34_1 / ETHER_ETHn / ETH3_RXD0
    IOPORT_PIN_P341_PFC_15_RXDE06          = (0x15U << IOPORT_PFC_OFFSET), ///< P34_1 / SCIEn / RXDE06
    IOPORT_PIN_P341_PFC_1A_SPI_MISO2       = (0x1AU << IOPORT_PFC_OFFSET), ///< P34_1 / SPIn / SPI_MISO2
    IOPORT_PIN_P341_PFC_22_ENCIFDI06       = (0x22U << IOPORT_PFC_OFFSET), ///< P34_1 / ENCIFn / ENCIFDI06
    IOPORT_PIN_P341_PFC_25_HDSL10_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P34_1 / HDSLn / HDSL10_CLK1
    IOPORT_PIN_P342_PFC_04_A24             = (0x04U << IOPORT_PFC_OFFSET), ///< P34_2 / BSC / A24
    IOPORT_PIN_P342_PFC_09_GTADSM04_0      = (0x09U << IOPORT_PFC_OFFSET), ///< P34_2 / GPT / GTADSM04_0
    IOPORT_PIN_P342_PFC_0A_GTIOC03_1A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P34_2 / GPT / GTIOC03_1A
    IOPORT_PIN_P342_PFC_0F_ETH3_RXD1       = (0x0FU << IOPORT_PFC_OFFSET), ///< P34_2 / ETHER_ETHn / ETH3_RXD1
    IOPORT_PIN_P342_PFC_15_SCKE07          = (0x15U << IOPORT_PFC_OFFSET), ///< P34_2 / SCIEn / SCKE07
    IOPORT_PIN_P342_PFC_1A_SPI_SSL20       = (0x1AU << IOPORT_PFC_OFFSET), ///< P34_2 / SPIn / SPI_SSL20
    IOPORT_PIN_P342_PFC_22_ENCIFCK07       = (0x22U << IOPORT_PFC_OFFSET), ///< P34_2 / ENCIFn / ENCIFCK07
    IOPORT_PIN_P342_PFC_25_HDSL10_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P34_2 / HDSLn / HDSL10_SEL1
    IOPORT_PIN_P343_PFC_04_A25             = (0x04U << IOPORT_PFC_OFFSET), ///< P34_3 / BSC / A25
    IOPORT_PIN_P343_PFC_09_GTADSM04_1      = (0x09U << IOPORT_PFC_OFFSET), ///< P34_3 / GPT / GTADSM04_1
    IOPORT_PIN_P343_PFC_0A_GTIOC03_1B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P34_3 / GPT / GTIOC03_1B
    IOPORT_PIN_P343_PFC_0F_ETH3_RXD2       = (0x0FU << IOPORT_PFC_OFFSET), ///< P34_3 / ETHER_ETHn / ETH3_RXD2
    IOPORT_PIN_P343_PFC_15_DEE07           = (0x15U << IOPORT_PFC_OFFSET), ///< P34_3 / SCIEn / DEE07
    IOPORT_PIN_P343_PFC_1A_SPI_SSL21       = (0x1AU << IOPORT_PFC_OFFSET), ///< P34_3 / SPIn / SPI_SSL21
    IOPORT_PIN_P343_PFC_22_ENCIFOE07       = (0x22U << IOPORT_PFC_OFFSET), ///< P34_3 / ENCIFn / ENCIFOE07
    IOPORT_PIN_P343_PFC_25_HDSL10_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P34_3 / HDSLn / HDSL10_MISO1
    IOPORT_PIN_P343_PFC_29_SD1_PWEN        = (0x29U << IOPORT_PFC_OFFSET), ///< P34_3 / SDHI / SD1_PWEN
    IOPORT_PIN_P344_PFC_04_CS2             = (0x04U << IOPORT_PFC_OFFSET), ///< P34_4 / BSC / CS2
    IOPORT_PIN_P344_PFC_09_GTADSM05_0      = (0x09U << IOPORT_PFC_OFFSET), ///< P34_4 / GPT / GTADSM05_0
    IOPORT_PIN_P344_PFC_0A_GTIOC03_2A      = (0x0AU << IOPORT_PFC_OFFSET), ///< P34_4 / GPT / GTIOC03_2A
    IOPORT_PIN_P344_PFC_0F_ETH3_RXD3       = (0x0FU << IOPORT_PFC_OFFSET), ///< P34_4 / ETHER_ETHn / ETH3_RXD3
    IOPORT_PIN_P344_PFC_14_RXD3_SCL3_MISO3 = (0x14U << IOPORT_PFC_OFFSET), ///< P34_4 / SCIn / RXD3_SCL3_MISO3
    IOPORT_PIN_P344_PFC_15_TXDE07          = (0x15U << IOPORT_PFC_OFFSET), ///< P34_4 / SCIEn / TXDE07
    IOPORT_PIN_P344_PFC_1A_SPI_SSL22       = (0x1AU << IOPORT_PFC_OFFSET), ///< P34_4 / SPIn / SPI_SSL22
    IOPORT_PIN_P344_PFC_1F_ADTRG0          = (0x1FU << IOPORT_PFC_OFFSET), ///< P34_4 / ADCn / ADTRG0
    IOPORT_PIN_P344_PFC_22_ENCIFDO07       = (0x22U << IOPORT_PFC_OFFSET), ///< P34_4 / ENCIFn / ENCIFDO07
    IOPORT_PIN_P344_PFC_25_HDSL10_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P34_4 / HDSLn / HDSL10_MOSI1
    IOPORT_PIN_P344_PFC_29_SD1_IOVS        = (0x29U << IOPORT_PFC_OFFSET), ///< P34_4 / SDHI / SD1_IOVS
    IOPORT_PIN_P345_PFC_04_CS3             = (0x04U << IOPORT_PFC_OFFSET), ///< P34_5 / BSC / CS3
    IOPORT_PIN_P345_PFC_09_GTADSM05_1      = (0x09U << IOPORT_PFC_OFFSET), ///< P34_5 / GPT / GTADSM05_1
    IOPORT_PIN_P345_PFC_0A_GTIOC03_2B      = (0x0AU << IOPORT_PFC_OFFSET), ///< P34_5 / GPT / GTIOC03_2B
    IOPORT_PIN_P345_PFC_0F_ETH3_RXDV       = (0x0FU << IOPORT_PFC_OFFSET), ///< P34_5 / ETHER_ETHn / ETH3_RXDV
    IOPORT_PIN_P345_PFC_12_ESC_I2CCLK      = (0x12U << IOPORT_PFC_OFFSET), ///< P34_5 / ETHER_ESC / ESC_I2CCLK
    IOPORT_PIN_P345_PFC_14_TXD3_SDA3_MOSI3 = (0x14U << IOPORT_PFC_OFFSET), ///< P34_5 / SCIn / TXD3_SDA3_MOSI3
    IOPORT_PIN_P345_PFC_15_RXDE07          = (0x15U << IOPORT_PFC_OFFSET), ///< P34_5 / SCIEn / RXDE07
    IOPORT_PIN_P345_PFC_17_IIC_SCL1        = (0x17U << IOPORT_PFC_OFFSET), ///< P34_5 / IICn / IIC_SCL1
    IOPORT_PIN_P345_PFC_1A_SPI_SSL23       = (0x1AU << IOPORT_PFC_OFFSET), ///< P34_5 / SPIn / SPI_SSL23
    IOPORT_PIN_P345_PFC_1F_ADTRG1          = (0x1FU << IOPORT_PFC_OFFSET), ///< P34_5 / ADCn / ADTRG1
    IOPORT_PIN_P345_PFC_22_ENCIFDI07       = (0x22U << IOPORT_PFC_OFFSET), ///< P34_5 / ENCIFn / ENCIFDI07
    IOPORT_PIN_P345_PFC_25_HDSL10_CLK2     = (0x25U << IOPORT_PFC_OFFSET), ///< P34_5 / HDSLn / HDSL10_CLK2
    IOPORT_PIN_P346_PFC_02_ETH3_REFCLK     = (0x02U << IOPORT_PFC_OFFSET), ///< P34_6 / ETHER_ETHn / ETH3_REFCLK
    IOPORT_PIN_P346_PFC_03_RMII3_REFCLK    = (0x03U << IOPORT_PFC_OFFSET), ///< P34_6 / ETHER_ETHn / RMII3_REFCLK
    IOPORT_PIN_P346_PFC_04_CS5             = (0x04U << IOPORT_PFC_OFFSET), ///< P34_6 / BSC / CS5
    IOPORT_PIN_P346_PFC_0F_ETH1_RXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P34_6 / ETHER_ETHn / ETH1_RXER
    IOPORT_PIN_P346_PFC_12_ESC_I2CDATA     = (0x12U << IOPORT_PFC_OFFSET), ///< P34_6 / ETHER_ESC / ESC_I2CDATA
    IOPORT_PIN_P346_PFC_17_IIC_SDA1        = (0x17U << IOPORT_PFC_OFFSET), ///< P34_6 / IICn / IIC_SDA1
    IOPORT_PIN_P346_PFC_1A_SPI_RSPCK3      = (0x1AU << IOPORT_PFC_OFFSET), ///< P34_6 / SPIn / SPI_RSPCK3
    IOPORT_PIN_P346_PFC_1F_ADTRG2          = (0x1FU << IOPORT_PFC_OFFSET), ///< P34_6 / ADCn / ADTRG2
    IOPORT_PIN_P346_PFC_24_DUEI08          = (0x24U << IOPORT_PFC_OFFSET), ///< P34_6 / ENDATn / DUEI08
    IOPORT_PIN_P346_PFC_25_HDSL10_SEL2     = (0x25U << IOPORT_PFC_OFFSET), ///< P34_6 / HDSLn / HDSL10_SEL2
    IOPORT_PIN_P347_PFC_00_IRQ14           = (0x00U << IOPORT_PFC_OFFSET), ///< P34_7 / IRQ / IRQ14
    IOPORT_PIN_P347_PFC_05_DREQ            = (0x05U << IOPORT_PFC_OFFSET), ///< P34_7 / DMAC / DREQ
    IOPORT_PIN_P347_PFC_09_GTADSM06_0      = (0x09U << IOPORT_PFC_OFFSET), ///< P34_7 / GPT / GTADSM06_0
    IOPORT_PIN_P347_PFC_0F_ETH3_TXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P34_7 / ETHER_ETHn / ETH3_TXER
    IOPORT_PIN_P347_PFC_12_ESC_RESETOUT_N  = (0x12U << IOPORT_PFC_OFFSET), ///< P34_7 / ETHER_ESC / ESC_RESETOUT_N
    IOPORT_PIN_P347_PFC_1A_SPI_MOSI3       = (0x1AU << IOPORT_PFC_OFFSET), ///< P34_7 / SPIn / SPI_MOSI3
    IOPORT_PIN_P347_PFC_24_TST_OUT08       = (0x24U << IOPORT_PFC_OFFSET), ///< P34_7 / ENDATn / TST_OUT08
    IOPORT_PIN_P347_PFC_25_HDSL10_MISO2    = (0x25U << IOPORT_PFC_OFFSET), ///< P34_7 / HDSLn / HDSL10_MISO2
    IOPORT_PIN_P350_PFC_05_DACK            = (0x05U << IOPORT_PFC_OFFSET), ///< P35_0 / DMAC / DACK
    IOPORT_PIN_P350_PFC_09_GTADSM06_1      = (0x09U << IOPORT_PFC_OFFSET), ///< P35_0 / GPT / GTADSM06_1
    IOPORT_PIN_P350_PFC_0F_ETH3_RXER       = (0x0FU << IOPORT_PFC_OFFSET), ///< P35_0 / ETHER_ETHn / ETH3_RXER
    IOPORT_PIN_P350_PFC_1A_SPI_MISO3       = (0x1AU << IOPORT_PFC_OFFSET), ///< P35_0 / SPIn / SPI_MISO3
    IOPORT_PIN_P350_PFC_24_SI08            = (0x24U << IOPORT_PFC_OFFSET), ///< P35_0 / ENDATn / SI08
    IOPORT_PIN_P350_PFC_25_HDSL10_MOSI2    = (0x25U << IOPORT_PFC_OFFSET), ///< P35_0 / HDSLn / HDSL10_MOSI2
    IOPORT_PIN_P351_PFC_05_TEND            = (0x05U << IOPORT_PFC_OFFSET), ///< P35_1 / DMAC / TEND
    IOPORT_PIN_P351_PFC_09_GTADSM07_0      = (0x09U << IOPORT_PFC_OFFSET), ///< P35_1 / GPT / GTADSM07_0
    IOPORT_PIN_P351_PFC_0F_ETH3_CRS        = (0x0FU << IOPORT_PFC_OFFSET), ///< P35_1 / ETHER_ETHn / ETH3_CRS
    IOPORT_PIN_P351_PFC_1A_SPI_SSL30       = (0x1AU << IOPORT_PFC_OFFSET), ///< P35_1 / SPIn / SPI_SSL30
    IOPORT_PIN_P351_PFC_1B_SPI_MISO1       = (0x1BU << IOPORT_PFC_OFFSET), ///< P35_1 / SPIn / SPI_MISO1
    IOPORT_PIN_P351_PFC_1D_MCLK90          = (0x1DU << IOPORT_PFC_OFFSET), ///< P35_1 / DSMIFn / MCLK90
    IOPORT_PIN_P351_PFC_24_DUEI09          = (0x24U << IOPORT_PFC_OFFSET), ///< P35_1 / ENDATn / DUEI09
    IOPORT_PIN_P351_PFC_25_HDSL11_LINK     = (0x25U << IOPORT_PFC_OFFSET), ///< P35_1 / HDSLn / HDSL11_LINK
    IOPORT_PIN_P352_PFC_09_GTADSM07_1      = (0x09U << IOPORT_PFC_OFFSET), ///< P35_2 / GPT / GTADSM07_1
    IOPORT_PIN_P352_PFC_0F_ETH3_COL        = (0x0FU << IOPORT_PFC_OFFSET), ///< P35_2 / ETHER_ETHn / ETH3_COL
    IOPORT_PIN_P352_PFC_1A_SPI_SSL31       = (0x1AU << IOPORT_PFC_OFFSET), ///< P35_2 / SPIn / SPI_SSL31
    IOPORT_PIN_P352_PFC_1B_SPI_SSL10       = (0x1BU << IOPORT_PFC_OFFSET), ///< P35_2 / SPIn / SPI_SSL10
    IOPORT_PIN_P352_PFC_1D_MDAT90          = (0x1DU << IOPORT_PFC_OFFSET), ///< P35_2 / DSMIFn / MDAT90
    IOPORT_PIN_P352_PFC_1F_ADTRG2          = (0x1FU << IOPORT_PFC_OFFSET), ///< P35_2 / ADCn / ADTRG2
    IOPORT_PIN_P352_PFC_24_TST_OUT09       = (0x24U << IOPORT_PFC_OFFSET), ///< P35_2 / ENDATn / TST_OUT09
    IOPORT_PIN_P352_PFC_25_HDSL11_SMPL     = (0x25U << IOPORT_PFC_OFFSET), ///< P35_2 / HDSLn / HDSL11_SMPL
    IOPORT_PIN_P353_PFC_09_GTADSM08_0      = (0x09U << IOPORT_PFC_OFFSET), ///< P35_3 / GPT / GTADSM08_0
    IOPORT_PIN_P353_PFC_1A_SPI_SSL32       = (0x1AU << IOPORT_PFC_OFFSET), ///< P35_3 / SPIn / SPI_SSL32
    IOPORT_PIN_P353_PFC_1B_SPI_MOSI1       = (0x1BU << IOPORT_PFC_OFFSET), ///< P35_3 / SPIn / SPI_MOSI1
    IOPORT_PIN_P353_PFC_1D_MCLK91          = (0x1DU << IOPORT_PFC_OFFSET), ///< P35_3 / DSMIFn / MCLK91
    IOPORT_PIN_P353_PFC_1F_ADTRG0          = (0x1FU << IOPORT_PFC_OFFSET), ///< P35_3 / ADCn / ADTRG0
    IOPORT_PIN_P353_PFC_24_SI09            = (0x24U << IOPORT_PFC_OFFSET), ///< P35_3 / ENDATn / SI09
    IOPORT_PIN_P353_PFC_25_HDSL11_CLK1     = (0x25U << IOPORT_PFC_OFFSET), ///< P35_3 / HDSLn / HDSL11_CLK1
    IOPORT_PIN_P354_PFC_09_GTADSM08_1      = (0x09U << IOPORT_PFC_OFFSET), ///< P35_4 / GPT / GTADSM08_1
    IOPORT_PIN_P354_PFC_1A_SPI_SSL33       = (0x1AU << IOPORT_PFC_OFFSET), ///< P35_4 / SPIn / SPI_SSL33
    IOPORT_PIN_P354_PFC_1B_SPI_SSL11       = (0x1BU << IOPORT_PFC_OFFSET), ///< P35_4 / SPIn / SPI_SSL11
    IOPORT_PIN_P354_PFC_1D_MDAT91          = (0x1DU << IOPORT_PFC_OFFSET), ///< P35_4 / DSMIFn / MDAT91
    IOPORT_PIN_P354_PFC_1F_ADTRG1          = (0x1FU << IOPORT_PFC_OFFSET), ///< P35_4 / ADCn / ADTRG1
    IOPORT_PIN_P354_PFC_24_DUEI10          = (0x24U << IOPORT_PFC_OFFSET), ///< P35_4 / ENDATn / DUEI10
    IOPORT_PIN_P354_PFC_25_HDSL11_SEL1     = (0x25U << IOPORT_PFC_OFFSET), ///< P35_4 / HDSLn / HDSL11_SEL1
    IOPORT_PIN_P355_PFC_09_GTADSM09_0      = (0x09U << IOPORT_PFC_OFFSET), ///< P35_5 / GPT / GTADSM09_0
    IOPORT_PIN_P355_PFC_14_RXD4_SCL4_MISO4 = (0x14U << IOPORT_PFC_OFFSET), ///< P35_5 / SCIn / RXD4_SCL4_MISO4
    IOPORT_PIN_P355_PFC_1B_SPI_RSPCK1      = (0x1BU << IOPORT_PFC_OFFSET), ///< P35_5 / SPIn / SPI_RSPCK1
    IOPORT_PIN_P355_PFC_1D_MCLK92          = (0x1DU << IOPORT_PFC_OFFSET), ///< P35_5 / DSMIFn / MCLK92
    IOPORT_PIN_P355_PFC_24_TST_OUT10       = (0x24U << IOPORT_PFC_OFFSET), ///< P35_5 / ENDATn / TST_OUT10
    IOPORT_PIN_P355_PFC_25_HDSL11_MISO1    = (0x25U << IOPORT_PFC_OFFSET), ///< P35_5 / HDSLn / HDSL11_MISO1
    IOPORT_PIN_P356_PFC_09_GTADSM09_1      = (0x09U << IOPORT_PFC_OFFSET), ///< P35_6 / GPT / GTADSM09_1
    IOPORT_PIN_P356_PFC_14_TXD4_SDA4_MOSI4 = (0x14U << IOPORT_PFC_OFFSET), ///< P35_6 / SCIn / TXD4_SDA4_MOSI4
    IOPORT_PIN_P356_PFC_1B_SPI_SSL12       = (0x1BU << IOPORT_PFC_OFFSET), ///< P35_6 / SPIn / SPI_SSL12
    IOPORT_PIN_P356_PFC_1D_MDAT92          = (0x1DU << IOPORT_PFC_OFFSET), ///< P35_6 / DSMIFn / MDAT92
    IOPORT_PIN_P356_PFC_24_SI10            = (0x24U << IOPORT_PFC_OFFSET), ///< P35_6 / ENDATn / SI10
    IOPORT_PIN_P356_PFC_25_HDSL11_MOSI1    = (0x25U << IOPORT_PFC_OFFSET), ///< P35_6 / HDSLn / HDSL11_MOSI1

    /** Marks end of enum - used by parameter checking */
    IOPORT_PERIPHERAL_END
} ioport_pin_pfc_t;

/** Options to configure pin functions  */
typedef enum e_ioport_cfg_options
{
    IOPORT_CFG_PORT_DIRECTION_HIZ          = 0x00000000 << IOPORT_PM_OFFSET, ///< Sets the pin direction to Hi-Z
    IOPORT_CFG_PORT_DIRECTION_INPUT        = 0x00000001 << IOPORT_PM_OFFSET, ///< Sets the pin direction to input (default)
    IOPORT_CFG_PORT_DIRECTION_OUTPUT       = 0x00000002 << IOPORT_PM_OFFSET, ///< Sets the pin direction to output
    IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT = 0x00000003 << IOPORT_PM_OFFSET, ///< Sets the pin direction to output (data is input to input buffer)
    IOPORT_CFG_PORT_OUTPUT_LOW             = 0x00000000 << IOPORT_P_OFFSET,  ///< Sets the pin level to low
    IOPORT_CFG_PORT_OUTPUT_HIGH            = 0x00000001 << IOPORT_P_OFFSET,  ///< Sets the pin level to high
    IOPORT_CFG_PORT_GPIO               = 0x00000000 << IOPORT_PMC_OFFSET,    ///< Enables pin to operate as an GPIO pin
    IOPORT_CFG_PORT_PERI               = 0x00000001 << IOPORT_PMC_OFFSET,    ///< Enables pin to operate as a peripheral pin
    IOPORT_CFG_DRIVE_LOW               = 0x00000000 << IOPORT_DRCTL_OFFSET,  ///< Sets pin drive output to low
    IOPORT_CFG_DRIVE_MID               = 0x00000001 << IOPORT_DRCTL_OFFSET,  ///< Sets pin drive output to medium
    IOPORT_CFG_DRIVE_HIGH              = 0x00000002 << IOPORT_DRCTL_OFFSET,  ///< Sets pin drive output to high
    IOPORT_CFG_DRIVE_UHIGH             = 0x00000003 << IOPORT_DRCTL_OFFSET,  ///< Sets pin drive output to ultra high
    IOPORT_CFG_PULLUP_DOWN_DISABLE     = 0x00000000 << IOPORT_DRCTL_OFFSET,  ///< Disables the pin's pull-up / pull-down
    IOPORT_CFG_PULLUP_ENABLE           = 0x00000004 << IOPORT_DRCTL_OFFSET,  ///< Enables the pin's internal pull-up
    IOPORT_CFG_PULLDOWN_ENABLE         = 0x00000008 << IOPORT_DRCTL_OFFSET,  ///< Enables the pin's pull-down
    IOPORT_CFG_SCHMITT_TRIGGER_DISABLE = 0x00000000 << IOPORT_DRCTL_OFFSET,  ///< Disables schmitt trigger input
    IOPORT_CFG_SCHMITT_TRIGGER_ENABLE  = 0x00000010 << IOPORT_DRCTL_OFFSET,  ///< Enables schmitt trigger input
    IOPORT_CFG_SLEW_RATE_SLOW          = 0x00000000 << IOPORT_DRCTL_OFFSET,  ///< Sets the slew rate to slow
    IOPORT_CFG_SLEW_RATE_FAST          = 0x00000020 << IOPORT_DRCTL_OFFSET,  ///< Sets the slew rate to fast
    IOPORT_CFG_REGION_SAFETY           = 0x00000000 << IOPORT_RSELP_OFFSET,  ///< Selects safety region
    IOPORT_CFG_REGION_NSAFETY          = 0x00000001 << IOPORT_RSELP_OFFSET,  ///< Selects non safety region
    IOPORT_CFG_PIM_TTL                 = 0x00000020,                         ///< This macro has been unsupported
    IOPORT_CFG_NMOS_ENABLE             = 0x00000040,                         ///< This macro has been unsupported
    IOPORT_CFG_PMOS_ENABLE             = 0x00000080,                         ///< This macro has been unsupported
    IOPORT_CFG_DRIVE_HS_HIGH           = 0x00000800,                         ///< This macro has been unsupported
    IOPORT_CFG_DRIVE_MID_IIC           = 0x00000C00,                         ///< This macro has been unsupported
    IOPORT_CFG_EVENT_RISING_EDGE       = 0x00001000,                         ///< This macro has been unsupported
    IOPORT_CFG_EVENT_FALLING_EDGE      = 0x00002000,                         ///< This macro has been unsupported
    IOPORT_CFG_EVENT_BOTH_EDGES        = 0x00003000,                         ///< This macro has been unsupported
    IOPORT_CFG_IRQ_ENABLE              = 0x00004000,                         ///< This macro has been unsupported
    IOPORT_CFG_ANALOG_ENABLE           = 0x00008000,                         ///< This macro has been unsupported
    IOPORT_CFG_PERIPHERAL_PIN          = 0x00010000                          ///< This macro has been unsupported
} ioport_cfg_options_t;

/*==============================================
 * ETHER API Overrides
 *==============================================*/

/** Event code of callback function */
typedef enum e_ether_event
{
    ETHER_EVENT_WAKEON_LAN,            ///< Magic packet detection event
    ETHER_EVENT_LINK_ON,               ///< Link up detection event
    ETHER_EVENT_LINK_OFF,              ///< Link down detection event
    ETHER_EVENT_SBD_INTERRUPT,         ///< SBD Interrupt event
    ETHER_EVENT_PMT_INTERRUPT          ///< PMT Interrupt event
} ether_event_t;

/** Ether Callback function parameter data */
typedef struct st_ether_callback_args
{
    uint32_t      channel;             ///< Device channel number
    ether_event_t event;               ///< Event code
    uint32_t      status_ether;        ///< Interrupt status of SDB or PMT
    uint32_t      status_link;         ///< Link status
    void const  * p_context;           ///< Placeholder for user data.
} ether_callback_args_t;

/*==============================================
 * ETHER SWITCH API Overrides
 *==============================================*/

/** Ether Switch Event code of callback function */
typedef enum e_ether_switch_event
{
    ETHER_SWITCH_EVENT_LINK_CHANGE     ///< Change Link status
} ether_switch_event_t;

/** Ether Switch Callback function parameter data */
typedef struct st_ether_switch_callback_args
{
    uint32_t             channel;      ///< Device channel number
    ether_switch_event_t event;        ///< Event code

    uint32_t status_link;              ///< Link status bit0:port0. bit1:port1. bit2:port2, bit3:port3

    void const * p_context;            ///< Placeholder for user data.
} ether_switch_callback_args_t;

/*==============================================
 * ETHER PHY API Overrides
 *==============================================*/

/** Phy LSI */
typedef enum e_ether_phy_lsi_type
{
    ETHER_PHY_LSI_TYPE_DEFAULT = 0,     ///< Select default configuration. This type dose not change Phy LSI default setting by strapping option.
    ETHER_PHY_LSI_TYPE_VSC8541 = 1,     ///< Select configuration forVSC8541
    ETHER_PHY_LSI_TYPE_KSZ9131 = 2,     ///< Select configuration forKSZ9131
    ETHER_PHY_LSI_TYPE_KSZ9031 = 3,     ///< Select configuration forKSZ9031
    ETHER_PHY_LSI_TYPE_KSZ8081 = 4,     ///< Select configuration forKSZ8081
    ETHER_PHY_LSI_TYPE_KSZ8041 = 5,     ///< Select configuration forKSZ8041
    ETHER_PHY_LSI_TYPE_CUSTOM  = 0xFFU, ///< Select configuration for User custom.
} ether_phy_lsi_type_t;

/*==============================================
 * POEG API Overrides
 *==============================================*/

/** POEG states. */
typedef enum e_poeg_state
{
    POEG_STATE_NO_DISABLE_REQUEST                = 0,       ///< GPT output is not disabled by POEG
    POEG_STATE_PIN_DISABLE_REQUEST               = 1U << 0, ///< GPT output disabled due to GTETRG pin level
    POEG_STATE_GPT_OR_COMPARATOR_DISABLE_REQUEST = 1U << 1, ///< GPT output disabled due to high speed analog comparator or GPT
    POEG_STATE_OSCILLATION_STOP_DISABLE_REQUEST  = 1U << 2, ///< GPT output disabled due to main oscillator stop
    POEG_STATE_SOFTWARE_STOP_DISABLE_REQUEST     = 1U << 3, ///< GPT output disabled due to poeg_api_t::outputDisable()

    POEG_STATE_DSMIF0_DISABLE_REQUEST = 1U << 4,            ///< GPT output disabled due to DSMIF0 error 0
    POEG_STATE_DSMIF1_DISABLE_REQUEST = 1U << 5,            ///< GPT output disabled due to DSMIF1 error 0
    POEG_STATE_DSMIF2_DISABLE_REQUEST = 1U << 6,            ///< GPT output disabled due to DSMIF2 error 0
    POEG_STATE_DSMIF3_DISABLE_REQUEST = 1U << 7,            ///< GPT output disabled due to DSMIF3 error 0
    POEG_STATE_DSMIF4_DISABLE_REQUEST = 1U << 8,            ///< GPT output disabled due to DSMIF4 error 0
    POEG_STATE_DSMIF5_DISABLE_REQUEST = 1U << 9,            ///< GPT output disabled due to DSMIF5 error 0
    POEG_STATE_DSMIF7_DISABLE_REQUEST = 1U << 11,           ///< GPT output disabled due to DSMIF7 error 0
    POEG_STATE_DSMIF8_DISABLE_REQUEST = 1U << 12,           ///< GPT output disabled due to DSMIF8 error 0

    /** GPT output disable request active from the GTETRG pin. If a filter is used, this flag represents the state of
     * the filtered input. */
    POEG_STATE_PIN_DISABLE_REQUEST_ACTIVE = 1U << 16,

    POEG_STATE_DSMIF0_1_DISABLE_REQUEST = 1U << 20, ///< GPT output disabled due to DSMIF0 error 1
    POEG_STATE_DSMIF1_1_DISABLE_REQUEST = 1U << 21, ///< GPT output disabled due to DSMIF1 error 1
    POEG_STATE_DSMIF2_1_DISABLE_REQUEST = 1U << 22, ///< GPT output disabled due to DSMIF2 error 1
    POEG_STATE_DSMIF3_1_DISABLE_REQUEST = 1U << 23, ///< GPT output disabled due to DSMIF3 error 1
    POEG_STATE_DSMIF4_1_DISABLE_REQUEST = 1U << 24, ///< GPT output disabled due to DSMIF4 error 1
    POEG_STATE_DSMIF5_1_DISABLE_REQUEST = 1U << 25, ///< GPT output disabled due to DSMIF5 error 1
    POEG_STATE_DSMIF7_1_DISABLE_REQUEST = 1U << 27, ///< GPT output disabled due to DSMIF7 error 1
    POEG_STATE_DSMIF8_1_DISABLE_REQUEST = 1U << 28, ///< GPT output disabled due to DSMIF8 error 1
} poeg_state_t;

/** Triggers that will disable GPT output pins. */
typedef enum e_poeg_trigger
{
    /** Software disable is always supported with POEG. Select this option if no other triggers are used. */
    POEG_TRIGGER_SOFTWARE         = 0U,
    POEG_TRIGGER_PIN              = 1U << 0, ///< Disable GPT output based on GTETRG input level(PIDE)
    POEG_TRIGGER_GPT_OUTPUT_LEVEL = 1U << 1, ///< Disable GPT output based on GPT output pin levels(IOCE)
    POEG_TRIGGER_OSCILLATION_STOP = 1U << 2, ///< Disable GPT output based on main oscillator stop(OSPTE)
    POEG_TRIGGER_ACMPHS0          = 1U << 4, ///< Disable GPT output based on ACMPHS0 comparator result
    POEG_TRIGGER_ACMPHS1          = 1U << 5, ///< Disable GPT output based on ACMPHS1 comparator result
    POEG_TRIGGER_ACMPHS2          = 1U << 6, ///< Disable GPT output based on ACMPHS2 comparator result
    POEG_TRIGGER_ACMPHS3          = 1U << 7, ///< Disable GPT output based on ACMPHS3 comparator result
    POEG_TRIGGER_ACMPHS4          = 1U << 8, ///< Disable GPT output based on ACMPHS4 comparator result
    POEG_TRIGGER_ACMPHS5          = 1U << 9, ///< Disable GPT output based on ACMPHS5 comparator result

    /** The GPT output pins can be disabled when DSMIF error occurs (LLPP only). */
    POEG_TRIGGER_D0ERR0E = 1U << 10,         ///< Permit output disabled by DSMIF0 error detection
    POEG_TRIGGER_D1ERR0E = 1U << 11,         ///< Permit output disabled by DSMIF1 error detection
    POEG_TRIGGER_D2ERR0E = 1U << 12,         ///< Permit output disabled by DSMIF2 error detection
    POEG_TRIGGER_D3ERR0E = 1U << 13,         ///< Permit output disabled by DSMIF3 error detection
    POEG_TRIGGER_D4ERR0E = 1U << 14,         ///< Permit output disabled by DSMIF4 error detection
    POEG_TRIGGER_D5ERR0E = 1U << 15,         ///< Permit output disabled by DSMIF5 error detection
    POEG_TRIGGER_D7ERR0E = 1U << 17,         ///< Permit output disabled by DSMIF7 error detection
    POEG_TRIGGER_D8ERR0E = 1U << 18,         ///< Permit output disabled by DSMIF8 error detection
    POEG_TRIGGER_D0ERR1E = 1U << 20,         ///< Permit output disabled by DSMIF0 error 1 detection
    POEG_TRIGGER_D1ERR1E = 1U << 21,         ///< Permit output disabled by DSMIF1 error 1 detection
    POEG_TRIGGER_D2ERR1E = 1U << 22,         ///< Permit output disabled by DSMIF2 error 1 detection
    POEG_TRIGGER_D3ERR1E = 1U << 23,         ///< Permit output disabled by DSMIF3 error 1 detection
    POEG_TRIGGER_D4ERR1E = 1U << 24,         ///< Permit output disabled by DSMIF4 error 1 detection
    POEG_TRIGGER_D5ERR1E = 1U << 25,         ///< Permit output disabled by DSMIF5 error 1 detection
    POEG_TRIGGER_D7ERR1E = 1U << 27,         ///< Permit output disabled by DSMIF7 error 1 detection
    POEG_TRIGGER_D8ERR1E = 1U << 28,         ///< Permit output disabled by DSMIF8 error 1 detection
} poeg_trigger_t;

/*==============================================
 * POE3 API Overrides
 *==============================================*/

/** POE3 states. */
typedef enum e_poe3_state
{
    POE3_STATE_NO_DISABLE_REQUEST           = 0,                ///< Timer output is not disabled by POE3
    POE3_STATE_POE0_HIGH_IMPEDANCE_REQUEST  = 1U,               ///< Timer output disabled due to POE0# pin
    POE3_STATE_POE4_HIGH_IMPEDANCE_REQUEST  = 1U << 1,          ///< Timer output disabled due to POE4# pin
    POE3_STATE_POE8_HIGH_IMPEDANCE_REQUEST  = 1U << 2,          ///< Timer output disabled due to POE8# pin
    POE3_STATE_POE10_HIGH_IMPEDANCE_REQUEST = 1U << 3,          ///< Timer output disabled due to POE10# pin
    POE3_STATE_POE11_HIGH_IMPEDANCE_REQUEST = 1U << 4,          ///< Timer output disabled due to POE11# pin

    POE3_STATE_SOFTWARE_STOP_DISABLE_REQUEST = 1U << 5,         ///< Timer output disabled due to poe3_api_t::outputDisable()

    POE3_STATE_OSCILLATION_STOP_DISABLE_REQUEST = 1U << 6,      ///< Timer output disabled due to main oscillator stop

    POE3_STATE_OUTPUT_SHORT_CIRCUIT_1_ERROR_REQUEST = 1U << 9,  ///< Timer output disabled due to output short circuit 1
    POE3_STATE_OUTPUT_SHORT_CIRCUIT_2_ERROR_REQUEST = 1U << 10, ///< Timer output disabled due to output short circuit 2

    POE3_STATE_DSMIF0_ERROR_REQUEST   = 1U << 11,               ///< Timer output disabled due to DSMIF0 Error0
    POE3_STATE_DSMIF1_ERROR_REQUEST   = 1U << 12,               ///< Timer output disabled due to DSMIF1 Error0
    POE3_STATE_DSMIF2_ERROR_REQUEST   = 1U << 13,               ///< Timer output disabled due to DSMIF2 Error0
    POE3_STATE_DSMIF3_ERROR_REQUEST   = 1U << 14,               ///< Timer output disabled due to DSMIF3 Error0
    POE3_STATE_DSMIF4_ERROR_REQUEST   = 1U << 15,               ///< Timer output disabled due to DSMIF4 Error0
    POE3_STATE_DSMIF5_ERROR_REQUEST   = 1U << 16,               ///< Timer output disabled due to DSMIF5 Error0
    POE3_STATE_DSMIF7_ERROR_REQUEST   = 1U << 18,               ///< Timer output disabled due to DSMIF7 Error0
    POE3_STATE_DSMIF8_ERROR_REQUEST   = 1U << 19,               ///< Timer output disabled due to DSMIF8 Error0
    POE3_STATE_DSMIF0_1_ERROR_REQUEST = 1U << 21,               ///< Timer output disabled due to DSMIF0 Error1
    POE3_STATE_DSMIF1_1_ERROR_REQUEST = 1U << 22,               ///< Timer output disabled due to DSMIF1 Error1
    POE3_STATE_DSMIF2_1_ERROR_REQUEST = 1U << 23,               ///< Timer output disabled due to DSMIF2 Error1
    POE3_STATE_DSMIF3_1_ERROR_REQUEST = 1U << 24,               ///< Timer output disabled due to DSMIF3 Error1
    POE3_STATE_DSMIF4_1_ERROR_REQUEST = 1U << 25,               ///< Timer output disabled due to DSMIF4 Error1
    POE3_STATE_DSMIF5_1_ERROR_REQUEST = 1U << 26,               ///< Timer output disabled due to DSMIF5 Error1
    POE3_STATE_DSMIF7_1_ERROR_REQUEST = 1U << 28,               ///< Timer output disabled due to DSMIF7 Error1
    POE3_STATE_DSMIF8_1_ERROR_REQUEST = 1U << 29,               ///< Timer output disabled due to DSMIF8 Error1
} poe3_state_t;

/*==============================================
 * Transfer API Overrides
 *==============================================*/

/** Events that can trigger a callback function. */
typedef enum e_transfer_event
{
    TRANSFER_EVENT_TRANSFER_END   = 0, ///< Transfer has completed.
    TRANSFER_EVENT_TRANSFER_ERROR = 1, ///< Transfer error has occurred.
} transfer_event_t;

/** Transfer mode describes what will happen when a transfer request occurs. */
typedef enum e_transfer_mode
{
    /** Normal mode. */
    TRANSFER_MODE_NORMAL = 0,

    /** Block mode. */
    TRANSFER_MODE_BLOCK = 1
} transfer_mode_t;

/** Transfer size specifies the size of each individual transfer. */
typedef enum e_transfer_size
{
    TRANSFER_SIZE_1_BYTE  = 0,         ///< Each transfer transfers a 8-bit value
    TRANSFER_SIZE_2_BYTE  = 1,         ///< Each transfer transfers a 16-bit value
    TRANSFER_SIZE_4_BYTE  = 2,         ///< Each transfer transfers a 32-bit value
    TRANSFER_SIZE_8_BYTE  = 3,         ///< Each transfer transfers a 64-bit value
    TRANSFER_SIZE_16_BYTE = 4,         ///< Each transfer transfers a 128-bit value
    TRANSFER_SIZE_32_BYTE = 5,         ///< Each transfer transfers a 256-bit value
    TRANSFER_SIZE_64_BYTE = 6          ///< Each transfer transfers a 512-bit value
} transfer_size_t;

/** Address mode specifies whether to modify (increment or decrement) pointer after each transfer. */
typedef enum e_transfer_addr_mode
{
    /** Address pointer is incremented by associated @ref transfer_size_t after each transfer. */
    TRANSFER_ADDR_MODE_INCREMENTED = 0,

    /** Address pointer remains fixed after each transfer. */
    TRANSFER_ADDR_MODE_FIXED = 1
} transfer_addr_mode_t;

/** Callback function parameter data. */
typedef struct st_transfer_callback_args_t
{
    transfer_event_t event;            ///< Event code
    void const     * p_context;        ///< Placeholder for user data. Set in transfer_api_t::open function in ::transfer_cfg_t.
} transfer_callback_args_t;

/** This structure specifies the properties of the transfer. */
typedef struct st_transfer_info
{
    /** Select what happens to destination pointer after each transfer. */
    transfer_addr_mode_t dest_addr_mode;

    /** Select what happens to source pointer after each transfer. */
    transfer_addr_mode_t src_addr_mode;

    /** Select mode from @ref transfer_mode_t. */
    transfer_mode_t mode;

    /** Source pointer. */
    void const * volatile p_src;

    /** Destination pointer. */
    void * volatile p_dest;

    /** Length of each transfer. */
    volatile uint32_t length;

    /** Select number of source bytes to transfer at once. */
    transfer_size_t src_size;

    /** Select number of destination bytes to transfer at once. */
    transfer_size_t dest_size;

    /** Next1 Register set settings */
    void const * p_next1_src;
    void       * p_next1_dest;
    uint32_t     next1_length;
} transfer_info_t;

/*=========================================================
 * ADC API Override using other override definitions
 *=========================================================*/

/** ADC Information Structure for Transfer Interface */
typedef struct st_adc_info
{
    volatile const void * p_address;         ///< The address to start reading the data from
    uint32_t              length;            ///< The total number of transfers to read
    transfer_size_t       transfer_size;     ///< The size of each transfer
    elc_peripheral_t      elc_peripheral;    ///< Name of the peripheral in the ELC list
    elc_event_t           elc_event;         ///< Name of the ELC event for the peripheral
    uint32_t              calibration_data1; ///< Temperature sensor calibration data1
    uint32_t              calibration_data2; ///< Temperature sensor calibration data2
    int16_t               slope_microvolts;  ///< Temperature sensor slope in microvolts/degrees C
    bool calibration_ongoing;                ///< Calibration is in progress.
} adc_info_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
