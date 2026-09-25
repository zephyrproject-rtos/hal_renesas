/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RA6B1
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RA6B1) */

#ifndef BSP_OVERRIDE_H
#define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <stdint.h>

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Define overrides required for this MCU. */
#define BSP_OVERRIDE_ADC_CHANNEL_T
#define BSP_OVERRIDE_ADC_EVENT_T
#define BSP_OVERRIDE_ADC_INCLUDE
#define BSP_OVERRIDE_ADC_INFO_T
#define BSP_OVERRIDE_ADC_MODE_T
#define BSP_OVERRIDE_ADC_RESOLUTION_T
#define BSP_OVERRIDE_CAC_CLOCK_SOURCE_T
#define BSP_OVERRIDE_CGC_CLOCKS_CFG_T
#define BSP_OVERRIDE_CGC_CLOCK_CHANGE_T
#define BSP_OVERRIDE_CGC_CLOCK_T
#define BSP_OVERRIDE_CGC_DIVIDER_CFG_T
#define BSP_OVERRIDE_CGC_PLL_CFG_T
#define BSP_OVERRIDE_CGC_SYS_CLOCK_DIV_T
#define BSP_OVERRIDE_COMPARATOR_TRIGGER_T
#define BSP_OVERRIDE_ELC_PERIPHERAL_T
#define BSP_OVERRIDE_EXTERNAL_IRQ_TRIGGER_T
#define BSP_OVERRIDE_IOPORT_SIZE_T
#define BSP_OVERRIDE_LVD_PERIPHERAL_T
#define BSP_OVERRIDE_RTC_EVENT_T
#define BSP_OVERRIDE_RTC_PERIODIC_IRQ_SELECT_T
#define BSP_OVERRIDE_RTC_TIME_CAPTURE_SOURCE_T
#define BSP_OVERRIDE_TIMER_EVENT_T
#define BSP_OVERRIDE_TIMER_MODE_T
#define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
#define BSP_OVERRIDE_TRANSFER_CHAIN_MODE_T
#define BSP_OVERRIDE_TRANSFER_INFO_T
#define BSP_OVERRIDE_TRANSFER_IRQ_T
#define BSP_OVERRIDE_TRANSFER_MODE_T
#define BSP_OVERRIDE_TRANSFER_REPEAT_AREA_T
#define BSP_OVERRIDE_TRANSFER_SIZE_T
#define BSP_OVERRIDE_UART_DATA_BITS_T
#define BSP_OVERRIDE_UART_EVENT_T
#define BSP_OVERRIDE_UART_PARITY_T
#define BSP_OVERRIDE_WDT_TIMEOUT_T
#define BSP_OVERRIDE_WDT_WINDOW_START_END_T

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** ADC channels */
typedef enum e_adc_channel
{
    ADC_CHANNEL_0            = 0,      ///< ADC channel 0
    ADC_CHANNEL_1            = 1,      ///< ADC channel 1
    ADC_CHANNEL_2            = 2,      ///< ADC channel 2
    ADC_CHANNEL_3            = 3,      ///< ADC channel 3
    ADC_CHANNEL_4            = 4,      ///< ADC channel 4
    ADC_CHANNEL_5            = 5,      ///< ADC channel 5
    ADC_CHANNEL_6            = 6,      ///< ADC channel 6
    ADC_CHANNEL_7            = 7,      ///< ADC channel 7
    ADC_CHANNEL_VBAT         = 8,      ///< ADC VBAT channel
    ADC_CHANNEL_VDDA_1V8     = 9,      ///< ADC VDDA_1V8 channel
    ADC_CHANNEL_VDDA_EXT_1V8 = 10,     ///< ADC VDDA_EXT_1V8 channel
    ADC_CHANNEL_VDDA_1V0     = 11,     ///< ADC VDDA_1V0 channel
    ADC_CHANNEL_VDD          = 12,     ///< ADC VDD channel
    ADC_CHANNEL_NONE         = 13,
} adc_channel_t;

/** ADC callback event definitions  */
typedef enum e_adc_event
{
    ADC_EVENT_SCAN_COMPLETE,           ///< Scan completed
    ADC_EVENT_WINDOW_COMPARE_UPPER,    ///< Window compare upper threshold crossed
    ADC_EVENT_WINDOW_COMPARE_LOWER,    ///< Window compare lower threshold crossed
    ADC_EVENT_WINDOW_COMPARE_WITHIN,   ///< Window compare value within range
} adc_event_t;

/** ADC calibration data structure */
typedef struct st_adc_w_b_calibration_info
{
    uint8_t  trim_ldo_lvl;             ///< LDO level trim value
    uint16_t trim_off_n;               ///< Negative offset trim value
    uint16_t trim_off_p;               ///< Positive offset trim value
    uint8_t  trim_gain;                ///< Gain trim value
    uint16_t trim_cmp_n;               ///< Negative comparator trim value
    uint16_t trim_cmp_p;               ///< Positive comparator trim value
} adc_w_b_calibration_info_t;

/** ADC calibration status  */
typedef enum e_adc_w_b_calibration_status
{
    ADC_W_B_CALIBRATION_STATUS_WITHIN_RANGE,  ///< Calibration result is within valid range (refer to MCUs datasheet)
    ADC_W_B_CALIBRATION_STATUS_OUTSIDE_RANGE, ///< Calibration result is outside valid range (refer to MCUs datasheet)
} adc_w_b_calibration_status_t;

/** ADC calibration information */
typedef struct st_adc_info
{
    adc_w_b_calibration_status_t calibration_status; ///< Calibration status
    adc_w_b_calibration_info_t   calibration_data;   ///< Calibration trim data
} adc_info_t;

/** ADC operation mode definitions  */
typedef enum e_adc_mode
{
    ADC_MODE_SINGLE_SCAN           = 0, ///< Standard Single Scan of a channel
    ADC_MODE_CONTINUOUS_SCAN       = 1, ///< Standard Continuous Scan of a channel
    ADC_MODE_GROUP_SINGLE_SCAN     = 2, ///< Group Single Scan of one or more channels
    ADC_MODE_GROUP_CONTINUOUS_SCAN = 3, ///< Group Continuous Scan of one or more channels
} adc_mode_t;

/** ADC data resolution definitions */
typedef enum e_adc_resolution
{
    ADC_RESOLUTION_9_BIT  = 0,         ///< 9 bit resolution
    ADC_RESOLUTION_10_BIT = 1,         ///< 10 bit resolution
    ADC_RESOLUTION_11_BIT = 2,         ///< 11 bit resolution
} adc_resolution_t;

/** Enumeration of the possible clock sources for both the reference and measurement clocks. */
typedef enum e_cac_clock_source
{
    CAC_CLOCK_SOURCE_RCLP     = 0x00,  ///< RCLP clock
    CAC_CLOCK_SOURCE_RCHS     = 0x01,  ///< RCHS clock
    CAC_CLOCK_SOURCE_RCX      = 0x02,  ///< RCX clock
    CAC_CLOCK_SOURCE_XTAL32K  = 0x03,  ///< XTAL32K clock
    CAC_CLOCK_SOURCE_XTAL32M  = 0x04,  ///< XTAL32M clock
    CAC_CLOCK_SOURCE_XTAL64M  = 0x05,  ///< XTAL64M clock
    CAC_CLOCK_SOURCE_EXTERNAL = 0x06,  ///< Externally supplied reference clock
    CAC_CLOCK_SOURCE_DIVN     = 0x07,  ///< DIVN clock
} cac_clock_source_t;

/** Clock options */
typedef enum e_cgc_clock_change
{
    CGC_CLOCK_CHANGE_NONE  = 0,        ///< No change to the clock
    CGC_CLOCK_CHANGE_START = 1,        ///< Start the clock
    CGC_CLOCK_CHANGE_STOP  = 2,        ///< Stop the clock
} cgc_clock_change_t;

/** System clock source identifiers */
typedef enum e_cgc_clock
{
    CGC_CLOCK_RCHS = 0,                ///< The high-speed on-chip oscillator (RCHS) configured at 32 MHz
    CGC_CLOCK_RCHS_64M,                ///< The high-speed on-chip oscillator (RCHS) configured at 64 MHz
    CGC_CLOCK_RCLP,                    ///< The middle-speed on-chip oscillator (RCLP) configured at  32 kHz
    CGC_CLOCK_RCLP_512K,               ///< The middle-speed on-chip oscillator (RCLP) configured at 512 kHz
    CGC_CLOCK_RCX,                     ///< The low-speed on-chip oscillator (RCX)
    CGC_CLOCK_XTALM,                   ///< The main oscillator (XTAL32M)
    CGC_CLOCK_XTALM_64M,               ///< The main oscillator at doubled frequency (XTAL64M)
    CGC_CLOCK_XTALK,                   ///< The subclock oscillator (XTAL32K)
    CGC_CLOCK_DIGITAL,                 ///< The subclock external oscillator (externally supplied digital clock) (XTAL32K_EXT)
    CGC_CLOCK_PLL,                     ///< The PLL oscillator (PLL128M)
} cgc_clock_t;

/** Clock configuration structure - Used as an input parameter to the @ref cgc_api_t::systemClockSet and @ref cgc_api_t::systemClockGet
 * functions. */
typedef struct st_cgc_divider_cfg
{
    union
    {
        uint32_t clk_amba_reg_div;     ///< The divider values only of CLK_AMBA_REG

        struct
        {
            uint32_t reserved1    : 4;
            uint32_t pclk_div     : 2; ///< Divider value for APB interface clock (Cascaded with HCLK)
            uint32_t reserved2    : 4;
            uint32_t qspi_sdr_div : 1; ///< QSPI divider when in SDR mode
        } clk_amba_reg_div_b;
    };
} cgc_divider_cfg_t;

typedef struct st_cgc_clocks_cfg
{
    cgc_clock_t        system_clock;   ///< System clock source enumeration
    cgc_clock_t        lp_clock;       ///< Low power clock source enumeration
    cgc_divider_cfg_t  divider_cfg;    ///< Clock dividers structure
    cgc_clock_change_t rcx_state;      ///< State of LOCO (RCX)
    cgc_clock_change_t rclp_state;     ///< State of MOCO (RCLP)
    cgc_clock_change_t rchs_state;     ///< State of HOCO (RCHS)
    cgc_clock_change_t xtalm_state;    ///< State of Main oscillator (XTALM)
    cgc_clock_change_t pll_state;      ///< State of PLL
    cgc_clock_change_t xtalk_state;    ///< State of subclock oscillator (XTALK)
    cgc_clock_change_t digital_state;  ///< State of External Sub oscillator (XTAL32K_EXT)
} cgc_clocks_cfg_t;

/** PLL clock configuration type - Used as an input parameter to the @ref cgc_api_t::clockStart function for the PLL clock. */
typedef void * cgc_pll_cfg_t;

/** System clock divider values - The individually selectable divider of certain internal clocks signals of the system,
 *                                i.e. HCLK, PCLK, etc. */
typedef enum e_cgc_sys_clock_div
{
    CGC_SYS_CLOCK_DIV_1  = 0,          ///< System clock divided by 1
    CGC_SYS_CLOCK_DIV_2  = 1,          ///< System clock divided by 2
    CGC_SYS_CLOCK_DIV_4  = 2,          ///< System clock divided by 4 (only applicable to PCLK and HCLK)
    CGC_SYS_CLOCK_DIV_8  = 3,          ///< System clock divided by 8 (only applicable to PCLK and HCLK)
    CGC_SYS_CLOCK_DIV_16 = 4,          ///< System clock divided by 16 (only applicable to HCLK)
} cgc_sys_clock_div_t;

/** Trigger type: rising edge, falling edge, rising and level, falling and level. */
typedef enum e_comparator_trigger
{
    COMPARATOR_TRIGGER_RISING        = 0, ///< Rising edge trigger
    COMPARATOR_TRIGGER_FALLING       = 1, ///< Falling edge trigger
    COMPARATOR_TRIGGER_RISING_LEVEL  = 2, ///< Rising edge or high level trigger
    COMPARATOR_TRIGGER_FALLING_LEVEL = 3, ///< Falling edge or low level trigger
} comparator_trigger_t;

#define ELC_PERIPHERAL_NUM    (30U)

/** Possible peripherals to be linked to event signals */
typedef enum e_elc_peripheral
{
    ELC_PERIPHERAL_TIMW1     = (0),
    ELC_PERIPHERAL_TIMW2     = (1),
    ELC_PERIPHERAL_TIMW3     = (2),
    ELC_PERIPHERAL_TIMW4     = (3),
    ELC_PERIPHERAL_TIMW5     = (4),
    ELC_PERIPHERAL_TIMW6     = (5),
    ELC_PERIPHERAL_TIMW7     = (6),
    ELC_PERIPHERAL_TIMW8     = (7),
    ELC_PERIPHERAL_TIMW9     = (8),
    ELC_PERIPHERAL_TIMW10    = (9),
    ELC_PERIPHERAL_IRGEN     = (10),
    ELC_PERIPHERAL_ADCWB     = (11),
    ELC_PERIPHERAL_ACOMP     = (12),
    ELC_PERIPHERAL_CMAC0     = (13),
    ELC_PERIPHERAL_CMAC1     = (14),
    ELC_PERIPHERAL_CMAC2     = (15),
    ELC_PERIPHERAL_CMAC3     = (16),
    ELC_PERIPHERAL_CMAC4     = (17),
    ELC_PERIPHERAL_PDC       = (18),
    ELC_PERIPHERAL_GPIOW0    = (19),
    ELC_PERIPHERAL_GPIOW1    = (20),
    ELC_PERIPHERAL_GPIOW2    = (21),
    ELC_PERIPHERAL_GPIOW3    = (22),
    ELC_PERIPHERAL_GPIOW4    = (23),
    ELC_PERIPHERAL_GPIOW5    = (24),
    ELC_PERIPHERAL_GPIOW6    = (25),
    ELC_PERIPHERAL_GPIOW7    = (26),
    ELC_PERIPHERAL_TEMPSENSE = (27),
    ELC_PERIPHERAL_RTCWB     = (29),
} elc_peripheral_t;

/** Condition that will trigger an interrupt when detected.
 * Bit 0 defines trigger sensitivity.
 * Bit 1 defines trigger polarity.
 */
typedef enum e_external_irq_trigger
{
    EXTERNAL_IRQ_TRIG_LEVEL_HIGH = 0,  ///< High level trigger
    EXTERNAL_IRQ_TRIG_EDGE_HIGH  = 1,  ///< Rising edge trigger
    EXTERNAL_IRQ_TRIG_LEVEL_LOW  = 2,  ///< Low level trigger
    EXTERNAL_IRQ_TRIG_EDGE_LOW   = 3,  ///< Falling edge trigger
} external_irq_trigger_t;

typedef uint32_t ioport_size_t;

/** The thresholds supported by each MCU are in the MCU User's Manual as well as
 *  in the r_lvd_w module description on the stack tab of the RA project. */
typedef enum
{
    LVD_THRESHOLD_VBAT_1_5V = 0,       ///< 1.5 V
    LVD_THRESHOLD_VBAT_1_6V = 1,       ///< 1.6 V
    LVD_THRESHOLD_VBAT_1_7V = 2,       ///< 1.7 V
    LVD_THRESHOLD_VBAT_1_8V = 3,       ///< 1.8 V
    LVD_THRESHOLD_VBAT_1_9V = 4,       ///< 1.9 V
    LVD_THRESHOLD_VBAT_2_0V = 5,       ///< 2.0 V
    LVD_THRESHOLD_VBAT_2_1V = 6,       ///< 2.1 V
    LVD_THRESHOLD_VBAT_2_2V = 7,       ///< 2.2 V
    LVD_THRESHOLD_VBAT_2_3V = 8,       ///< 2.3 V
    LVD_THRESHOLD_VBAT_2_4V = 9,       ///< 2.4 V
    LVD_THRESHOLD_VBAT_2_5V = 10,      ///< 2.5 V
    LVD_THRESHOLD_VBAT_2_6V = 11,      ///< 2.6 V
    LVD_THRESHOLD_VBAT_2_7V = 12,      ///< 2.7 V
    LVD_THRESHOLD_VBAT_2_8V = 13,      ///< 2.8 V
    LVD_THRESHOLD_VBAT_2_9V = 14,      ///< 2.9 V
    LVD_THRESHOLD_VBAT_3_0V = 15,      ///< 3.0 V
    LVD_THRESHOLD_VBAT_3_1V = 16,      ///< 3.1 V
    LVD_THRESHOLD_VBAT_3_2V = 17,      ///< 3.2 V
    LVD_THRESHOLD_VBAT_3_3V = 18,      ///< 3.3 V
    LVD_THRESHOLD_VBAT_3_4V = 19,      ///< 3.4 V
    LVD_THRESHOLD_VBAT_3_5V = 20,      ///< 3.5 V
    LVD_THRESHOLD_VBAT_3_6V = 21,      ///< 3.6 V
    LVD_THRESHOLD_VBAT_3_7V = 22,      ///< 3.7 V
    LVD_THRESHOLD_VBAT_3_8V = 23,      ///< 3.8 V
    LVD_THRESHOLD_VBAT_3_9V = 24,      ///< 3.9 V
    LVD_THRESHOLD_VBAT_4_0V = 25,      ///< 4.0 V
    LVD_THRESHOLD_VBAT_4_1V = 26,      ///< 4.1 V
    LVD_THRESHOLD_VBAT_4_2V = 27,      ///< 4.2 V
    LVD_THRESHOLD_VBAT_4_3V = 28,      ///< 4.3 V
    LVD_THRESHOLD_VBAT_4_4V = 29,      ///< 4.4 V
    LVD_THRESHOLD_VBAT_4_5V = 30,      ///< 4.5 V
    LVD_THRESHOLD_VBAT_4_6V = 31,      ///< 4.6 V
} lvd_threshold_t;

/** Events that can trigger a callback function */
typedef enum e_rtc_event
{
    RTC_EVENT_PERIODIC_HOS_IRQ  = 0x1,   ///< Real Time Clock ROLL-OVER on HOS IRQ
    RTC_EVENT_PERIODIC_SEC_IRQ  = 0x2,   ///< Real Time Clock ROLL-OVER on SEC IRQ
    RTC_EVENT_PERIODIC_MIN_IRQ  = 0x4,   ///< Real Time Clock ROLL-OVER on MIN IRQ
    RTC_EVENT_PERIODIC_HOUR_IRQ = 0x8,   ///< Real Time Clock ROLL-OVER on HOUR IRQ
    RTC_EVENT_PERIODIC_DAY_IRQ  = 0x10,  ///< Real Time Clock ROLL-OVER on DAY IRQ
    RTC_EVENT_PERIODIC_MNTH_IRQ = 0x20,  ///< Real Time Clock ROLL-OVER on MNTH IRQ
    RTC_EVENT_ALARM_IRQ         = 0x40,  ///< Real Time Clock ALARM IRQ
    RTC_EVENT_PERIODIC_IRQ      = 0x80,  ///< Real Time Clock ROLL-OVER IRQ
    RTC_EVENT_CAPTURE_IRQ       = 0x100, ///< Real Time Clock CAPTURE IRQ
} rtc_event_t;

/** Periodic Interrupt select */
typedef enum e_rtc_periodic_irq_select
{
    RTC_PERIODIC_IRQ_SELECT_DISABLE             = 0x00UL, ///< Disable periodic interrupts
    RTC_PERIODIC_IRQ_SELECT_1_DIV_BY_100_SECOND = 0x01UL, ///< A periodic irq is generated every 1/100 second
    RTC_PERIODIC_IRQ_SELECT_1_SECOND            = 0x02UL, ///< A periodic irq is generated every 1 second
    RTC_PERIODIC_IRQ_SELECT_1_MINUTE            = 0x04UL, ///< A periodic irq is generated every 1 minute
    RTC_PERIODIC_IRQ_SELECT_1_HOUR              = 0x08UL, ///< A periodic irq is generated every 1 hour
    RTC_PERIODIC_IRQ_SELECT_1_DAY               = 0x10UL, ///< A periodic irq is generated every 1 day
    RTC_PERIODIC_IRQ_SELECT_1_MONTH             = 0x20UL, ///< A periodic irq is generated every 1 month
} rtc_periodic_irq_select_t;

/** Time capture trigger source */
typedef enum e_rtc_time_capture_source
{
    RTC_TIME_CAPTURE_SOURCE_DISABLED    = 0x0, ///< Disable trigger
    RTC_TIME_CAPTURE_SOURCE_SOFTWARE    = 0x1, ///< Software trigger
    RTC_TIME_CAPTURE_SOURCE_PIN_RISING  = 0x2, ///< Rising edge pin trigger
    RTC_TIME_CAPTURE_SOURCE_ELC_EVENT   = 0x4, ///< ELC event trigger
    RTC_TIME_CAPTURE_SOURCE_PIN_FALLING = 0x8, ///< Falling edge pin trigger
} rtc_time_capture_source_t;

/** Events that can trigger a callback function */
typedef enum e_timer_event
{
    TIMER_EVENT_CYCLE_END,                    ///< Requested timer delay has expired or timer has wrapped around
    TIMER_EVENT_PULSE_CNT_CYCLE_END,          ///< Requested number of pulses were triggered
    TIMER_EVENT_SEQUENTIAL_CAPTURE_CYCLE_END, ///< Requested number of captures were triggered
    TIMER_EVENT_OVERFLOW,                     ///< Timer overflow event (counter reached 32-bit value)
    TIMER_EVENT_UNDERFLOW,                    ///< Timer underflow event (counter went under zero (0) value)
    TIMER_EVENT_CAPTURE_A,                    ///< A capture has occurred on signal A
    TIMER_EVENT_CAPTURE_B,                    ///< A capture has occurred on signal B
    TIMER_EVENT_CAPTURE_C,                    ///< A capture has occurred on signal C
    TIMER_EVENT_CAPTURE_D,                    ///< A capture has occurred on signal D
    TIMER_EVENT_CAPTURE_E,                    ///< A capture has occurred on signal E
    TIMER_EVENT_CAPTURE_F,                    ///< A capture has occurred on signal F
    TIMER_EVENT_CAPTURE_G,                    ///< A capture has occurred on signal G
    TIMER_EVENT_CAPTURE_H,                    ///< A capture has occurred on signal H
    TIMER_EVENT_COMPARE_A,                    ///< A compare has occurred on signal A
    TIMER_EVENT_COMPARE_B,                    ///< A compare has occurred on signal B
    TIMER_EVENT_COMPARE_C,                    ///< A compare has occurred on signal C
    TIMER_EVENT_COMPARE_D,                    ///< A compare has occurred on signal D
    TIMER_EVENT_COMPARE_E,                    ///< A compare has occurred on signal E
    TIMER_EVENT_COMPARE_F,                    ///< A compare has occurred on signal F
    TIMER_EVENT_COMPARE_G,                    ///< A compare has occurred on signal G
    TIMER_EVENT_COMPARE_H,                    ///< A compare has occurred on signal H
} timer_event_t;

/** Timer operational modes */
typedef enum e_timer_mode
{
    TIMER_MODE_PERIODIC,               ///< Timer restarts after period elapses.
    TIMER_MODE_ONE_SHOT,               ///< Timer stops after period elapses.
    TIMER_MODE_PWM,                    ///< Timer generates square-wave PWM output.
    TIMER_MODE_EDGE_DETECT,            ///< Timer asynchronously counts up edges.
} timer_mode_t;

/** Address mode specifies whether to modify (increment or decrement) pointer after each transfer. */
typedef enum e_transfer_addr_mode
{
    /** Address pointer remains fixed after each transfer. */
    TRANSFER_ADDR_MODE_FIXED = 0,

    /** Offset is added to the address pointer after each transfer. */
    TRANSFER_ADDR_MODE_OFFSET = 1,

    /** Address pointer is incremented by associated @ref transfer_size_t after each transfer. */
    TRANSFER_ADDR_MODE_INCREMENTED = 2,

    /** Address pointer is decremented by associated @ref transfer_size_t after each transfer. */
    TRANSFER_ADDR_MODE_DECREMENTED = 3
} transfer_addr_mode_t;

/** Chain transfer mode options.
 *  @note Only applies for DTC. */
typedef enum e_transfer_chain_mode
{
    /** Chain mode not used. */
    TRANSFER_CHAIN_MODE_DISABLED = 0,

    /** Switch to next transfer after a single transfer from this @ref transfer_info_t. */
    TRANSFER_CHAIN_MODE_EACH = 2,

    /** Complete the entire transfer defined in this @ref transfer_info_t before chaining to next transfer. */
    TRANSFER_CHAIN_MODE_END = 3
} transfer_chain_mode_t;

/** Interrupt options. */
typedef enum e_transfer_irq
{
    /** Interrupt occurs only after last transfer. If this transfer is chained to a subsequent transfer,
     *  the interrupt will occur only after subsequent chained transfer(s) are complete.
     *  @warning  DTC triggers the interrupt of the activation source.  Choosing TRANSFER_IRQ_END with DTC will
     *            prevent activation source interrupts until the transfer is complete. */
    TRANSFER_IRQ_END = 0,

    /** Interrupt occurs after each transfer.
     *  @note     Not available in all HAL drivers.  See HAL driver for details. */
    TRANSFER_IRQ_EACH = 1
} transfer_irq_t;

/** Transfer mode describes what will happen when a transfer request occurs. */
typedef enum e_transfer_mode
{
    /** In normal mode, each transfer request causes a transfer of @ref transfer_size_t from the source pointer to
     *  the destination pointer.  The transfer length is decremented and the source and address pointers are
     *  updated according to @ref transfer_addr_mode_t.  After the transfer length reaches 0, transfer requests
     *  will not cause any further transfers. */
    TRANSFER_MODE_NORMAL = 0,

    /** Repeat mode is like normal mode, except that when the transfer length reaches 0, the pointer to the
     *  repeat area and the transfer length will be reset to their initial values.  If DMAC is used, the
     *  transfer repeats only transfer_info_t::num_blocks times.  After the transfer repeats
     *  transfer_info_t::num_blocks times, transfer requests will not cause any further transfers.  If DTC is
     *  used, the transfer repeats continuously (no limit to the number of repeat transfers). */
    TRANSFER_MODE_REPEAT = 1,

    /** In block mode, each transfer request causes transfer_info_t::length transfers of @ref transfer_size_t.
     *  After each individual transfer, the source and destination pointers are updated according to
     *  @ref transfer_addr_mode_t.  After the block transfer is complete, transfer_info_t::num_blocks is
     *  decremented.  After the transfer_info_t::num_blocks reaches 0, transfer requests will not cause any
     *  further transfers. */
    TRANSFER_MODE_BLOCK = 2,

    /** In addition to block mode features, repeat-block mode supports a ring buffer of blocks and offsets
     *  within a block (to split blocks into arrays of their first data, second data, etc.) */
    TRANSFER_MODE_REPEAT_BLOCK = 3
} transfer_mode_t;

/** Repeat area options (source or destination).  In @ref TRANSFER_MODE_REPEAT, the selected pointer returns to its
 *  original value after transfer_info_t::length transfers.  In @ref TRANSFER_MODE_BLOCK and @ref TRANSFER_MODE_REPEAT_BLOCK,
 *  the selected pointer returns to its original value after each transfer. */
typedef enum e_transfer_repeat_area
{
    /** Destination area repeated in @ref TRANSFER_MODE_REPEAT or @ref TRANSFER_MODE_BLOCK or @ref TRANSFER_MODE_REPEAT_BLOCK. */
    TRANSFER_REPEAT_AREA_DESTINATION = 0,

    /** Source area repeated in @ref TRANSFER_MODE_REPEAT or @ref TRANSFER_MODE_BLOCK or @ref TRANSFER_MODE_REPEAT_BLOCK. */
    TRANSFER_REPEAT_AREA_SOURCE = 1
} transfer_repeat_area_t;

/** Transfer size specifies the size of each individual transfer.
 *  Total transfer length = transfer_size_t * transfer_length_t
 */
typedef enum e_transfer_size
{
    TRANSFER_SIZE_1_BYTE = 0,          ///< Each transfer transfers a 8-bit value
    TRANSFER_SIZE_2_BYTE = 1,          ///< Each transfer transfers a 16-bit value
    TRANSFER_SIZE_4_BYTE = 2,          ///< Each transfer transfers a 32-bit value
    TRANSFER_SIZE_8_BYTE = 3           ///< Each transfer transfers a 64-bit value
} transfer_size_t;

/** Transfer burst mode specifies if burst mode is enabled and which is the burst size.
 *  @note Only applies for DMAC. */
typedef enum e_transfer_burst_mode
{
    TRANSFER_BURST_MODE_DISABLED = 0,  ///< Burst mode is disabled.
    TRANSFER_BURST_MODE_4X       = 1,  ///< Burst mode is enabled, burst size of 4 data units is used.
    TRANSFER_BURST_MODE_8X       = 2,  ///< Burst mode is enabled, burst size of 8 data units is used.
} transfer_burst_mode_t;

/** This structure specifies the properties of the transfer.
 *  @warning  When using DTC, this structure corresponds to the descriptor block registers required by the DTC.
 *            The following components may be modified by the driver: p_src, p_dest, num_blocks, and length.
 *  @warning  When using DTC, do NOT reuse this structure to configure multiple transfers.  Each transfer must
 *            have a unique transfer_info_t.
 *  @warning  When using DTC, this structure must not be allocated in a temporary location.  Any instance of this
 *            structure must remain in scope until the transfer it is used for is closed.
 *  @note     When using DTC, consider placing instances of this structure in a protected section of memory. */
typedef struct st_transfer_info
{
    union
    {
        struct
        {
            uint32_t : 16;

            /** Select if burst mode is enable and what the burst length will be. */
            transfer_burst_mode_t burst_mode : 2;

            /** Select what happens to destination pointer after each transfer. */
            transfer_addr_mode_t dest_addr_mode : 2;

            /** Select to repeat source or destination area, unused in @ref TRANSFER_MODE_NORMAL. */
            transfer_repeat_area_t repeat_area : 1;

            /** Select if interrupts should occur after each individual transfer or after the completion of all planned
             *  transfers. */
            transfer_irq_t irq : 1;

            /** Select when the chain transfer ends. */
            transfer_chain_mode_t chain_mode : 2;

            uint32_t : 2;

            /** Select what happens to source pointer after each transfer. */
            transfer_addr_mode_t src_addr_mode : 2;

            /** Select number of bytes to transfer at once. @see transfer_info_t::length. */
            transfer_size_t size : 2;

            /** Select mode from @ref transfer_mode_t. */
            transfer_mode_t mode : 2;
        } transfer_settings_word_b;

        uint32_t transfer_settings_word;
    };

    void const * volatile p_src;       ///< Source pointer
    void * volatile       p_dest;      ///< Destination pointer

    /** Number of blocks to transfer when using @ref TRANSFER_MODE_BLOCK (both DTC an DMAC) or
     * @ref TRANSFER_MODE_REPEAT (DMAC only) or
     * @ref TRANSFER_MODE_REPEAT_BLOCK (DMAC only), unused in other modes. */
    volatile uint16_t num_blocks;

    /** Length of each transfer.  Range limited for @ref TRANSFER_MODE_BLOCK, @ref TRANSFER_MODE_REPEAT,
     *  and @ref TRANSFER_MODE_REPEAT_BLOCK
     *  see HAL driver for details. */
    volatile uint16_t length;
} transfer_info_t;

/** UART Data bit length definition */
typedef enum e_uart_data_bits
{
    UART_DATA_BITS_5 = 0U,             ///< Data bits 5-bit
    UART_DATA_BITS_6 = 1U,             ///< Data bits 6-bit
    UART_DATA_BITS_7 = 2U,             ///< Data bits 7-bit
    UART_DATA_BITS_8 = 3U,             ///< Data bits 8-bit
    UART_DATA_BITS_9 = 255U,           ///< Invalid
} uart_data_bits_t;

/** UART errors */
typedef enum e_sf_event
{
    UART_ERR_NOERROR = 0,              ///< Νο-error
    UART_ERR_OE      = 2,              ///< Overrun error
    UART_ERR_PE      = 4,              ///< Parity error
    UART_ERR_FE      = 8,              ///< Framing error
    UART_ERR_BI      = 16,             ///< Break interrupt indication
    UART_ERR_RFE     = 128,            ///< Receive FIFO error

    UART_EVENT_TX_COMPLETE   = 17,     ///< Transmit complete event
    UART_EVENT_RX_COMPLETE   = 18,     ///< Receive complete event
    UART_EVENT_TX_DATA_EMPTY = 19,     ///< Last byte is transmitting, ready for more data
    UART_EVENT_RX_CHAR       = 20,     ///< Character received
    UART_EVENT_RX_TIMEOUT    = 21,     ///< Receive timeout event
} uart_event_t;

/** UART Parity definition */
typedef enum e_uart_parity
{
    UART_PARITY_OFF  = 0U,             ///< No parity
    UART_PARITY_ODD  = 1U,             ///< Odd parity
    UART_PARITY_EVEN = 3U,             ///< Even parity
} uart_parity_t;

/** Use numerical values for WDT time-out periods. */
typedef uint32_t wdt_timeout_t;
typedef uint32_t wdt_window_start_t;
typedef uint32_t wdt_window_end_t;

/** Options to configure pin functions  */
typedef enum e_gpio_w_cfg_options
{
    /* PUPD */
    GPIO_W_CFG_PERIPHERAL_PIN        = 0x00000000, ///< Enables pin to operate as a peripheral pin
    GPIO_W_CFG_PULLDOWN_ENABLE       = 0x00000200, ///< Enables pull down
    GPIO_W_CFG_PULLUP_ENABLE         = 0x00000100, ///< Enables pull up
    GPIO_W_CFG_PORT_DIRECTION_INPUT  = 0x00000000, ///< Sets the pin direction to input
    GPIO_W_CFG_PORT_DIRECTION_OUTPUT = 0x00000300, ///< Sets the pin direction to output

    /* PPOD */
    GPIO_W_CFG_OPEN_DRAIN_ENABLE = 0x00000400,     ///< Enables open-drain output

    /* Slew Rate control reduces the 'on' swing time of the pad */
    GPIO_W_CFG_SLW_NORMAL = 0x00000000,            ///< Normal
    GPIO_W_CFG_SLW_SLOWER = 0x00000800,            ///< Slower

    /* Drive Strength */
    GPIO_W_CFG_DRV_2mA = 0x00000000,               ///< 2mA
    GPIO_W_CFG_DRV_4mA = 0x00001000,               ///< 4mA
    GPIO_W_CFG_DRV_6mA = 0x00002000,               ///< 6mA
    GPIO_W_CFG_DRV_8mA = 0x00003000,               ///< 8mA

    /* Connect the pin to ELC_PERIPHERAL_GPIOWx (considered only if PUPD = 0b11, output). */
    GPIO_W_CFG_ELC_EVT_GPIO_DISABLED = 0x00000000, ///< ELC events disabled for the specific pin
    GPIO_W_CFG_ELC_EVT_GPIO_0        = 0x00010000, ///< ELC_PERIPHERAL_GPIOW0 selected (selected means that Px_yy acts on ELC trigger mapped to ELC_PERIPHERAL_GPIOWz output)
    GPIO_W_CFG_ELC_EVT_GPIO_1        = 0x00020000, ///< ELC_PERIPHERAL_GPIOW1  selected
    GPIO_W_CFG_ELC_EVT_GPIO_2        = 0x00030000, ///< ELC_PERIPHERAL_GPIOW2  selected
    GPIO_W_CFG_ELC_EVT_GPIO_3        = 0x00040000, ///< ELC_PERIPHERAL_GPIOW3  selected
    GPIO_W_CFG_ELC_EVT_GPIO_4        = 0x00050000, ///< ELC_PERIPHERAL_GPIOW4  selected
    GPIO_W_CFG_ELC_EVT_GPIO_5        = 0x00060000, ///< ELC_PERIPHERAL_GPIOW5  selected
    GPIO_W_CFG_ELC_EVT_GPIO_6        = 0x00070000, ///< ELC_PERIPHERAL_GPIOW6  selected
    GPIO_W_CFG_ELC_EVT_GPIO_7        = 0x00080000, ///< ELC_PERIPHERAL_GPIOW7  selected

    /* Action when ELC_PERIPHERAL_GPIOWx is triggered (considered only if ELC_GPIO_EVT event select != 0) */
    GPIO_W_CFG_ELC_TASK_GPIO_RESET  = 0x00000000,  ///< Reset (clear) output
    GPIO_W_CFG_ELC_TASK_GPIO_SET    = 0x00100000,  ///< Set output
    GPIO_W_CFG_ELC_TASK_GPIO_TOGGLE = 0x00200000,  ///< Toggle output

    /* PIN LEVEL */
    GPIO_W_CFG_PORT_OUTPUT_LOW  = 0x00000000,      ///< Sets the pin level to low
    GPIO_W_CFG_PORT_OUTPUT_HIGH = 0x00400000,      ///< Sets the pin level to high

    /* Low drive strength */
    GPIO_W_CFG_DRV_NORMAL  = 0,                    ///< Sets the weak pad strength to normal
    GPIO_W_CFG_DRV_REDUCED = 1,                    ///< Sets the weak pad strength to reduced

    /* PAD power */
    GPIO_W_CFG_SUPPLY_V30 = 0,                     ///< Sets port output powered by the V30 rail
    GPIO_W_CFG_SUPPLY_1V8 = 1,                     ///< Sets port output powered by the 1V8P rail
} gpio_w_cfg_options_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif
