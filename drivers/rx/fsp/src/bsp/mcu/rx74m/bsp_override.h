/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RX74M
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RX74M) */

#ifndef BSP_OVERRIDE_H
#define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "../all/endian/bsp_transfer_endian_override.h"
#include "../all/endian/bsp_sdmmc_endian_override.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Private definition to set enumeration values. */
#define IOPORT_PRV_PFS_PSEL_OFFSET    (24)

/* Define overrides required for this MCU. */
#define BSP_OVERRIDE_EXTERNAL_IRQ_PCLK_DIV_T
#define BSP_OVERRIDE_EXTERNAL_IRQ_TRIGGER_T
#define BSP_OVERRIDE_IOPORT_CFG_OPTIONS_T
#define BSP_OVERRIDE_IOPORT_PERIPHERAL_T
#define BSP_OVERRIDE_CAC_CLOCK_SOURCE_T
#define BSP_OVERRIDE_CGC_DIVIDER_CFG_T
#define BSP_OVERRIDE_CGC_SYS_CLOCK_DIV_T
#define BSP_OVERRIDE_POEG_STATE_T
#define BSP_OVERRIDE_POEG_TRIGGER_T
#define BSP_OVERRIDE_DAC_B_OUTPUT_T
#define BSP_OVERRIDE_VOLTAGE_DETECTION_PERIPHERAL_T

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Enumeration of the possible clock sources for both the reference and measurement clocks. */
typedef enum e_cac_clock_source
{
    CAC_CLOCK_SOURCE_MAIN_OSC = 0x00,  ///< Main clock oscillator
    CAC_CLOCK_SOURCE_SUBCLOCK = 0x01,  ///< Sub-clock
    CAC_CLOCK_SOURCE_PLL1P    = 0X01,  ///< PLL1 output clock P (divided by 16)
    CAC_CLOCK_SOURCE_PLL2P    = 0X01,  ///< PLL2 output clock P (divided by 16)
    CAC_CLOCK_SOURCE_HOCO     = 0x02,  ///< HOCO (High speed on chip oscillator)
    CAC_CLOCK_SOURCE_MOCO     = 0x03,  ///< MOCO (Middle speed on chip oscillator)
    CAC_CLOCK_SOURCE_LOCO     = 0x04,  ///< LOCO (Low speed on chip oscillator)
    CAC_CLOCK_SOURCE_PLL1Q    = 0X04,  ///< PLL1 output clock Q (divided by 16)
    CAC_CLOCK_SOURCE_PLL2Q    = 0X04,  ///< PLL2 output clock Q (divided by 16)
    CAC_CLOCK_SOURCE_PCLKB    = 0x05,  ///< PCLKB (Peripheral Clock B)
    CAC_CLOCK_SOURCE_PLL1R    = 0X06,  ///< PLL1 output clock R (divided by 16)
    CAC_CLOCK_SOURCE_PLL2R    = 0X06,  ///< PLL2 output clock R (divided by 16)
    CAC_CLOCK_SOURCE_EXTERNAL = 0x07,  ///< Externally supplied measurement clock on CACREF pin
} cac_clock_source_t;

/*==============================================
 * EXTERNAL_IRQ Overrides
 *==============================================*/

/** Condition that will trigger an interrupt when detected. */
typedef enum e_external_irq_trigger
{
    EXTERNAL_IRQ_TRIG_FALLING   = 0,   ///< Falling edge trigger
    EXTERNAL_IRQ_TRIG_RISING    = 1,   ///< Rising edge trigger
    EXTERNAL_IRQ_TRIG_BOTH_EDGE = 2,   ///< Both edges trigger
    EXTERNAL_IRQ_TRIG_LEVEL_LOW = 3,   ///< Low level trigger
} external_irq_trigger_t;

/** External IRQ input pin digital filtering sample clock divisor settings. The digital filter rejects trigger
 * conditions that are shorter than 3 periods of the filter clock.
 */
typedef enum e_external_irq_clock_source_div
{
    EXTERNAL_IRQ_CLOCK_SOURCE_DIV_1   = 0, ///< Filter using clock source divided by 1
    EXTERNAL_IRQ_CLOCK_SOURCE_DIV_8   = 1, ///< Filter using clock source divided by 8
    EXTERNAL_IRQ_CLOCK_SOURCE_DIV_32  = 2, ///< Filter using clock source divided by 32
    EXTERNAL_IRQ_CLOCK_SOURCE_DIV_64  = 3, ///< Filter using clock source divided by 64
    EXTERNAL_IRQ_CLOCK_SOURCE_DIV_128 = 4, ///< Filter using clock source divided by 128
    EXTERNAL_IRQ_CLOCK_SOURCE_DIV_4   = 5, ///< Filter using clock source divided by 4
    EXTERNAL_IRQ_CLOCK_SOURCE_DIV_16  = 6, ///< Filter using clock source divided by 16
} external_irq_clock_source_div_t;

/** Superset of all peripheral functions.  */

/** System clock divider values - The individually selectable divider of each of the system clocks, ICLK, BCLK, FCLK,
 * PCLKS A-D.  */
typedef enum e_cgc_sys_clock_div
{
    CGC_SYS_CLOCK_DIV_1  = 0,          ///< System clock divided by 1
    CGC_SYS_CLOCK_DIV_2  = 1,          ///< System clock divided by 2
    CGC_SYS_CLOCK_DIV_4  = 2,          ///< System clock divided by 4
    CGC_SYS_CLOCK_DIV_8  = 3,          ///< System clock divided by 8
    CGC_SYS_CLOCK_DIV_16 = 4,          ///< System clock divided by 16
    CGC_SYS_CLOCK_DIV_32 = 5,          ///< System clock divided by 32
    CGC_SYS_CLOCK_DIV_64 = 6,          ///< System clock divided by 64
    CGC_SYS_CLOCK_DIV_3  = 8,          ///< System clock divided by 3
    CGC_SYS_CLOCK_DIV_6  = 9,          ///< System clock divided by 6
    CGC_SYS_CLOCK_DIV_12 = 10,         ///< System clock divided by 12
    CGC_SYS_CLOCK_DIV_24 = 11,         ///< System clock divided by 24
} cgc_sys_clock_div_t;

typedef enum e_ioport_peripheral
{
    /** Pin will functions as an IO pin */
    IOPORT_PERIPHERAL_IO = 0x00,

    /** Pin will function as a DEBUG pin */
    IOPORT_PERIPHERAL_DEBUG = (0x00UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a RTC(RTCIC) pin */
    IOPORT_PERIPHERAL_RTCIC = (0x00UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a GPT peripheral pin */
    IOPORT_PERIPHERAL_GPT0 = (0x01UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a GPT peripheral pin */
    IOPORT_PERIPHERAL_GPT1 = (0x02UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a GPT peripheral pin */
    IOPORT_PERIPHERAL_GPT2 = (0x03UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a GPT peripheral pin */
    IOPORT_PERIPHERAL_GPT3 = (0x04UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a TMR peripheral pin */
    IOPORT_PERIPHERAL_TMR = (0x05UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a RTC(RTCOUT) peripheral pin */
    IOPORT_PERIPHERAL_RTC = (0x06UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a CAC peripheral pin */
    IOPORT_PERIPHERAL_CAC = (0x07UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a POEG peripheral pin */
    IOPORT_PERIPHERAL_POEG = (0x08UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a ADC (Digital input) peripheral pin */
    IOPORT_PERIPHERAL_ADC = (0x09UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Even RSCI peripheral pin */
    IOPORT_PERIPHERAL_SCI0_2_4_6_8_10_12_0A = (0x0AUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Even RSCI(CTS,DE) peripheral pin */
    IOPORT_PERIPHERAL_SCI0_2_4_6_8_10_12_0B = (0x0BUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Even RSCI HBS and others peripheral pin */
    IOPORT_PERIPHERAL_SCI0_2_4_6_8_10_12_0C = (0x0CUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Odd RSCI peripheral pin */
    IOPORT_PERIPHERAL_SCI1_3_5_7_9_11_0D = (0x0DUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Odd RSCI(CTS) peripheral pin */
    IOPORT_PERIPHERAL_SCI1_3_5_7_9_11_0E = (0x0EUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Odd RSCI HBS and others peripheral pin */
    IOPORT_PERIPHERAL_SCI1_3_5_7_9_11_0F = (0x0FUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a RSPI peripheral pin */
    IOPORT_PERIPHERAL_SPI = (0x10UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a RI3C peripheral pin */
    IOPORT_PERIPHERAL_I3C = (0x11UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a CANFD peripheral pin */
    IOPORT_PERIPHERAL_CANFD = (0x12UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a USB full speed peripheral pin */
    IOPORT_PERIPHERAL_USB0 = (0x13UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a USB high speed peripheral pin */
    IOPORT_PERIPHERAL_USBHS = (0x14UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a DSMIF peripheral pin */
    IOPORT_PERIPHERAL_DSMIF = (0x15UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a PDMIF peripheral pin */
    IOPORT_PERIPHERAL_PDMIF = (0x16UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an SSIE peripheral pin */
    IOPORT_PERIPHERAL_SSIE = (0x17UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an PCIF peripheral pin */
    IOPORT_PERIPHERAL_PCIF = (0x18UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an SDHI peripheral pin */
    IOPORT_PERIPHERAL_SDHI = (0x19UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a XSPI first peripheral pin */
    IOPORT_PERIPHERAL_XSPI0_1A = (0x1AUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a XSPI first peripheral pin */
    IOPORT_PERIPHERAL_XSPI0_1B = (0x1BUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a  XSPI second peripheral pin */
    IOPORT_PERIPHERAL_XSPI1_1A = (0x1AUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a  XSPI second peripheral pin */
    IOPORT_PERIPHERAL_XSPI1_1B = (0x1BUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a PDC peripheral pin */
    IOPORT_PERIPHERAL_PDC = (0x1CUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a CMTW peripheral pin */
    IOPORT_PERIPHERAL_CMTW = (0x1DUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a clock peripheral pin */
    IOPORT_PERIPHERAL_CLKOUT = (0x1FUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Ethernet GMII/MII peripheral pin */
    IOPORT_PERIPHERAL_ETHER_MII_GMII = (0x20UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Ethernet RMMI peripheral pin */
    IOPORT_PERIPHERAL_ETHER_RMII = (0x21UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Ethernet RGMMI peripheral pin */
    IOPORT_PERIPHERAL_ETHER_RGMII = (0x22UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Ethernet PTP peripheral pin */
    IOPORT_PERIPHERAL_ETHER_PTP = (0x23UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Ethernet EtherCAT first peripheral pin */
    IOPORT_PERIPHERAL_ESC0 = (0x24UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an Ethernet EtherCAT second peripheral pin */
    IOPORT_PERIPHERAL_ESC1 = (0x25UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an EXBUS/SDRAM first peripheral pin */
    IOPORT_PERIPHERAL_BUS0 = (0x3DUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an EXBUS/SDRAM second peripheral pin */
    IOPORT_PERIPHERAL_BUS1 = (0x3EUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as an 32-bit board function peripheral pin */
    IOPORT_PERIPHERAL_PIO = (0x40UL << IOPORT_PRV_PFS_PSEL_OFFSET),
} ioport_peripheral_t;

/** Options to configure pin functions  */
typedef enum e_ioport_cfg_options
{
    IOPORT_CFG_PORT_DIRECTION_INPUT  = 0x00000000, ///< Sets the pin direction to input (default)
    IOPORT_CFG_PORT_DIRECTION_OUTPUT = 0x00000004, ///< Sets the pin direction to output
    IOPORT_CFG_PORT_OUTPUT_LOW       = 0x00000000, ///< Sets the pin level to low
    IOPORT_CFG_PORT_OUTPUT_HIGH      = 0x00000001, ///< Sets the pin level to high
    IOPORT_CFG_PULLUP_ENABLE         = 0x00000010, ///< Enables the pin's internal pull-up
    IOPORT_CFG_NMOS_ENABLE           = 0x00000040, ///< Enables the pin's NMOS open-drain output
    IOPORT_CFG_DRIVE_1               = 0x00000000, ///< Sets pin drive output to DRV1
    IOPORT_CFG_DRIVE_2               = 0x00000100, ///< Sets pin drive output to DRV2
    IOPORT_CFG_DRIVE_3               = 0x00000200, ///< Sets pin drive output to DRV3
    IOPORT_CFG_DRIVE_4               = 0x00000300, ///< Sets pin drive output to DRV4
    IOPORT_CFG_DRIVE_5               = 0x00000400, ///< Sets pin drive output to DRV5
    IOPORT_CFG_DRIVE_6               = 0x00000500, ///< Sets pin drive output to DRV6
    IOPORT_CFG_DRIVE_7               = 0x00000600, ///< Sets pin drive output to DRV7
    IOPORT_CFG_DRIVE_8               = 0x00000700, ///< Sets pin drive output to DRV8
    IOPORT_CFG_EVENT_RISING_EDGE     = 0x00001000, ///< Sets pin event trigger to rising edge
    IOPORT_CFG_EVENT_FALLING_EDGE    = 0x00002000, ///< Sets pin event trigger to falling edge
    IOPORT_CFG_EVENT_BOTH_EDGES      = 0x00003000, ///< Sets pin event trigger to both edges
    IOPORT_CFG_IRQ_ENABLE            = 0x00004000, ///< Sets pin as an IRQ pin
    IOPORT_CFG_ANALOG_ENABLE         = 0x00008000, ///< Enables pin to operate as an analog pin
    IOPORT_CFG_PERIPHERAL_PIN        = 0x00010000  ///< Enables pin to operate as a peripheral pin
} ioport_cfg_options_t;

/* Clock configuration structure - Used as an input parameter to the @ref cgc_api_t::systemClockSet and @ref cgc_api_t::systemClockGet
 * functions. */
typedef struct st_cgc_divider_cfg
{
    union
    {
        uint32_t sckdivcr_w;           ///< System clock Division control register

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            cgc_sys_clock_div_t fclk_div  : 4; ///< Divider value for FCLK
            cgc_sys_clock_div_t iclk_div  : 4; ///< Divider value for ICLK
            cgc_sys_clock_div_t pclke_div : 4; ///< Divider value for PCLKE
            cgc_sys_clock_div_t bclk_div  : 4; ///< Divider value for BCLK
            cgc_sys_clock_div_t pclka_div : 4; ///< Divider value for PCLKA
            cgc_sys_clock_div_t pclkb_div : 4; ///< Divider value for PCLKB
            cgc_sys_clock_div_t pclkc_div : 4; ///< Divider value for PCLKC
            cgc_sys_clock_div_t pclkd_div : 4; ///< Divider value for PCLKD
#else
            cgc_sys_clock_div_t pclkd_div : 4; ///< Divider value for PCLKD
            cgc_sys_clock_div_t pclkc_div : 4; ///< Divider value for PCLKC
            cgc_sys_clock_div_t pclkb_div : 4; ///< Divider value for PCLKB
            cgc_sys_clock_div_t pclka_div : 4; ///< Divider value for PCLKA
            cgc_sys_clock_div_t bclk_div  : 4; ///< Divider value for BCLK
            cgc_sys_clock_div_t pclke_div : 4; ///< Divider value for PCLKE
            cgc_sys_clock_div_t iclk_div  : 4; ///< Divider value for ICLK
            cgc_sys_clock_div_t fclk_div  : 4; ///< Divider value for FCLK
#endif
        } sckdivcr_b;
    } sckdivcr_u;

    union
    {
        uint32_t sckdivcr2;            ///< System clock Division control register 2

        __PACKED_STRUCT
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                       : 16; // Padding to align 32bits
            cgc_sys_clock_div_t mriclk_div : 4;  ///< Divider value for MRICLK
            cgc_sys_clock_div_t reserved   : 8;
            cgc_sys_clock_div_t cpuclk_div : 4;  ///< Divider value for CPUCLK0
#else
            cgc_sys_clock_div_t cpuclk_div : 4;  ///< Divider value for CPUCLK0
            cgc_sys_clock_div_t reserved   : 8;
            cgc_sys_clock_div_t mriclk_div : 4;  ///< Divider value for MRICLK
            uint32_t                       : 16; // Padding to align 32bits
#endif
        } sckdivcr2_b;
    } sckdivcr2_u;
} cgc_divider_cfg_t;

typedef enum e_poeg_state
{
    POEG_STATE_NO_DISABLE_REQUEST                = 0,        ///< GPT output is not disabled by POEG
    POEG_STATE_PIN_DISABLE_REQUEST               = 1U << 0,  ///< GPT output disabled due to GTETRG pin level
    POEG_STATE_GPT_OR_COMPARATOR_DISABLE_REQUEST = 1U << 1,  ///< GPT output disabled due to high speed analog comparator or GPT
    POEG_STATE_OSCILLATION_STOP_DISABLE_REQUEST  = 1U << 2,  ///< GPT output disabled due to main oscillator stop
    POEG_STATE_SOFTWARE_STOP_DISABLE_REQUEST     = 1U << 3,  ///< GPT output disabled due to poeg_api_t::outputDisable()
    POEG_STATE_DSMIF0_DISABLE_REQUEST            = 1U << 24, ///< GPT output disabled due to DSMIF0
    POEG_STATE_DSMIF1_DISABLE_REQUEST            = 1U << 25, ///< GPT output disabled due to DSMIF1

    /** GPT output disable request active from the GTETRG pin. If a filter is used, this flag represents the state of
     * the filtered input. */
    POEG_STATE_PIN_DISABLE_REQUEST_ACTIVE = 1U << 16,
} poeg_state_t;

/** Triggers that will disable GPT output pins. */
typedef enum e_poeg_trigger
{
    /** Software disable is always supported with POEG. Select this option if no other triggers are used. */
    POEG_TRIGGER_SOFTWARE         = 0U,
    POEG_TRIGGER_PIN              = 1U << 0,  ///< Disable GPT output based on GTETRG input level
    POEG_TRIGGER_GPT_OUTPUT_LEVEL = 1U << 1,  ///< Disable GPT output based on GPT output pin levels
    POEG_TRIGGER_OSCILLATION_STOP = 1U << 2,  ///< Disable GPT output based on main oscillator stop
    POEG_TRIGGER_DSMIF0           = 1U << 22, ///< Disable GPT output based on DSMIF0 overcurrent detection window notification
    POEG_TRIGGER_DSMIF1           = 1U << 23, ///< Disable GPT output based on DSMIF1 overcurrent detection window notification
} poeg_trigger_t;
typedef enum e_dac_b_output
{
    DAC_B_OUTPUT_EXTERNAL = 0,                ///< DAOUTDIS = 0, DAOUTEN = 0
    DAC_B_OUTPUT_INTERNAL = 2,                ///< DAOUTDIS = 1, DAOUTEN = 0
    DAC_B_OUTPUT_BOTH     = 3,                ///< DAOUTDIS = 1, DAOUTEN = 1
} dac_b_output_t;

/** The thresholds supported by each MCU are in the MCU User's Manual as well as
 *  in the r_pvd module description on the stack tab of the RX project. */
typedef enum
{
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_3_86V = 0x03UL, ///< 3.86V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_3_14V = 0x04UL, ///< 3.14V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_3_10V = 0x05UL, ///< 3.10V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_3_08V = 0x06UL, ///< 3.08V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_2_85V = 0x07UL, ///< 2.85V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_2_83V = 0x08UL, ///< 2.83V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_2_80V = 0x09UL, ///< 2.80V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_2_62V = 0x0AUL, ///< 2.62V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_2_33V = 0x0BUL, ///< 2.33V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_1_90V = 0x0CUL, ///< 1.90V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_1_86V = 0x0DUL, ///< 1.86V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_1_74V = 0x0EUL, ///< 1.74V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_LEVEL_1_71V = 0x0FUL, ///< 1.71V
    VOLTAGE_DETECTION_THRESHOLD_NOT_AVAILABLE       = 0xFFUL, ///< Not Used
} voltage_detection_threshold_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif
