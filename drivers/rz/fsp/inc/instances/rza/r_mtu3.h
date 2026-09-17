/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MTU3_H
#define R_MTU3_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_timer_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZA
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_MTU3
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** I/O Level Select */
typedef enum e_mtu3_io_pin_level
{
    MTU3_IO_PIN_LEVEL_NO_OUTPUT                   = 0,  ///< Output prohibited
    MTU3_IO_PIN_LEVEL_INITIAL_LOW_COMPARE_LOW     = 1,  ///< Initial output is low. Low output at compare match.
    MTU3_IO_PIN_LEVEL_INITIAL_LOW_COMPARE_HIGH    = 2,  ///< Initial output is low. High output at compare match.
    MTU3_IO_PIN_LEVEL_INITIAL_LOW_COMPARE_TOGGLE  = 3,  ///< Initial output is low. Toggle output at compare match.
    MTU3_IO_PIN_LEVEL_INITIAL_HIGH_COMPARE_LOW    = 5,  ///< Initial output is high. Low output at compare match.
    MTU3_IO_PIN_LEVEL_INITIAL_HIGH_COMPARE_HIGH   = 6,  ///< Initial output is high. High output at compare match.
    MTU3_IO_PIN_LEVEL_INITIAL_HIGH_COMPARE_TOGGLE = 7,  ///< Initial output is high. Toggle output at compare match.
    MTU3_IO_PIN_LEVEL_INPUT_RISING_EDGE           = 8,  ///< Input capture at rising edge.
    MTU3_IO_PIN_LEVEL_INPUT_FALLING_EDGE          = 9,  ///< Input capture at falling edge.
    MTU3_IO_PIN_LEVEL_INPUT_BOTH_EDGE             = 10, ///< Input capture at both edges.
} mtu3_io_pin_level_t;

/** Clock Edge Select */
typedef enum e_mtu3_clock_edge
{
    MTU3_CLOCK_EDGE_RISING  = 0x0,     ///< Count at rising edge
    MTU3_CLOCK_EDGE_FALLING = 0x1,     ///< Count at falling edge
    MTU3_CLOCK_EDGE_BOTH    = 0x2,     ///< Count at both edges
} mtu3_clock_edge_t;

/** Time Prescaler Select */
typedef enum e_mtu3_clock_div
{
    MTU3_CLOCK_DIV_1  = 0x0,                  ///< CLOCK divided by 1  (common ch)
    MTU3_CLOCK_DIV_4  = 0x1,                  ///< CLOCK divided by 4  (common ch)
    MTU3_CLOCK_DIV_16 = 0x2,                  ///< CLOCK divided by 16 (common ch)
    MTU3_CLOCK_DIV_64 = 0x3,                  ///< CLOCK divided by 64 (common ch)
    MTU3_CLOCK_DIV_2  = 0x8,                  ///< CLOCK divided by 2 (common ch)
    MTU3_CLOCK_DIV_8  = 0x10,                 ///< CLOCK divided by 8 (common ch)
    MTU3_CLOCK_DIV_32 = 0x18,                 ///< CLOCK divided by 32 (common ch)

    MTU3_CLOCK_DIV_MTCLKA_CH_0  = 0x4,        ///< External clock: counts on MTCLKA pin input (ch0)
    MTU3_CLOCK_DIV_MTCLKB_CH_0  = 0x5,        ///< External clock: counts on MTCLKB pin input (ch0)
    MTU3_CLOCK_DIV_MTCLKC_CH_0  = 0x6,        ///< External clock: counts on MTCLKC pin input (ch0)
    MTU3_CLOCK_DIV_MTCLKD_CH_0  = 0x7,        ///< External clock: counts on MTCLKD pin input (ch0)
    MTU3_CLOCK_DIV_256_CH_0     = 0x20,       ///< CLOCK divided by 256 (ch0)
    MTU3_CLOCK_DIV_1024_CH_0    = 0x28,       ///< CLOCK divided by 1024 (ch0)
    MTU3_CLOCK_DIV_MTIOC1A_CH_0 = 0x38,       ///< External clock: counts on MTIOC1A pin input (ch0)

    MTU3_CLOCK_DIV_MTCLKA_CH_1 = 0x4,         ///< External clock: counts on MTCLKA pin input (ch1)
    MTU3_CLOCK_DIV_MTCLKB_CH_1 = 0x5,         ///< External clock: counts on MTCLKB pin input (ch1)
    MTU3_CLOCK_DIV_256_CH_1    = 0x6,         ///< CLOCK divided by 256 (ch1)
    MTU3_CLOCK_DIV_TCNT_CH1    = 0x7,         ///< Overflow/underflow of MTU2.TCNT
    MTU3_CLOCK_DIV_1024_CH_1   = 0x20,        ///< CLOCK divided by 1024 (ch1)

    MTU3_CLOCK_DIV_MTCLKA_CH_2 = 0x4,         ///< External clock: counts on MTCLKA pin input (ch2)
    MTU3_CLOCK_DIV_MTCLKB_CH_2 = 0x5,         ///< External clock: counts on MTCLKB pin input (ch2)
    MTU3_CLOCK_DIV_MTCLKC_CH_2 = 0x6,         ///< External clock: counts on MTCLKC pin input (ch2)
    MTU3_CLOCK_DIV_1024_CH_2   = 0x7,         ///< CLOCK divided by 1024 (ch2)
    MTU3_CLOCK_DIV_256_CH_2    = 0x20,        ///< CLOCK divided by 256 (ch2)

    MTU3_CLOCK_DIV_256_CH_3_4_6_7_8    = 0x4, ///< CLOCK divided by 256 (ch3-4, 6-8)
    MTU3_CLOCK_DIV_1024_CH_3_4_6_7_8   = 0x5, ///< CLOCK divided by 1024 (ch3-4, 6-8)
    MTU3_CLOCK_DIV_MTCLKA_CH_3_4_6_7_8 = 0x6, ///< External clock: counts on MTCLKA pin input (ch3-4, 6-8)
    MTU3_CLOCK_DIV_MTCLKB_CH_3_4_6_7_8 = 0x7, ///< External clock: counts on MTCLKB pin input (ch3-4, 6-8)
} mtu3_clock_div_t;

/** Counter Clear Source Select */
typedef enum e_mtu3_tcnt_clear
{
    MTU3_TCNT_CLEAR_DISABLE = 0x0,     ///< TCNT clearing disabled
    MTU3_TCNT_CLEAR_TGRA    = 0x1,     ///< TCNT cleared by TGRA compare match/input capture
    MTU3_TCNT_CLEAR_TGRB    = 0x2,     ///< TCNT cleared by TGRB compare match/input capture
    MTU3_TCNT_CLEAR_TGRC    = 0x5,     ///< TCNT cleared by TGRC compare match/input capture
    MTU3_TCNT_CLEAR_TGRD    = 0x6,     ///< TCNT cleared by TGRD compare match/input capture
} mtu3_tcnt_clear_t;

/** Level of MTU3 pin */
typedef enum e_mtu3_io_pin
{
    MTU3_IO_PIN_MTIOCA            = 0, ///< MTIOCA
    MTU3_IO_PIN_MTIOCB            = 1, ///< MTIOCB
    MTU3_IO_PIN_MTIOCA_AND_MTIOCB = 2, ///< MTIOCA and MTIOCB
    MTU3_IO_PIN_MTIOCC                                  = 3,  ///< MTIOCC
    MTU3_IO_PIN_MTIOCD                                  = 4,  ///< MTIOCD
    MTU3_IO_PIN_MTIOCA_AND_MTIOCC                       = 5,  ///< MTIOCA and MTIOCC
    MTU3_IO_PIN_MTIOCA_AND_MTIOCD                       = 6,  ///< MTIOCA and MTIOCD
    MTU3_IO_PIN_MTIOCB_AND_MTIOCC                       = 7,  ///< MTIOCB and MTIOCC
    MTU3_IO_PIN_MTIOCB_AND_MTIOCD                       = 8,  ///< MTIOCB and MTIOCD
    MTU3_IO_PIN_MTIOCC_AND_MTIOCD                       = 9,  ///< MTIOCC and MTIOCD
    MTU3_IO_PIN_MTIOCA_AND_MTIOCB_AND_MTIOCC            = 10, ///< MTIOCA, MTIOCB and MTIOCC
    MTU3_IO_PIN_MTIOCA_AND_MTIOCB_AND_MTIOCD            = 11, ///< MTIOCA, MTIOCB and MTIOCD
    MTU3_IO_PIN_MTIOCA_AND_MTIOCC_AND_MTIOCD            = 12, ///< MTIOCA, MTIOCC and MTIOCD
    MTU3_IO_PIN_MTIOCB_AND_MTIOCC_AND_MTIOCD            = 13, ///< MTIOCB, MTIOCC and MTIOCD
    MTU3_IO_PIN_MTIOCA_AND_MTIOCB_AND_MTIOCC_AND_MTIOCD = 14, ///< MTIOCA, MTIOCB, MTIOCC and MTIOCD
} mtu3_io_pin_t;

/** Level of MTU3 pin */
typedef enum e_mtu3_pin_level
{
    MTU3_PIN_LEVEL_LOW  = 0,           ///< Pin level low
    MTU3_PIN_LEVEL_HIGH = 1,           ///< Pin level high
} mtu3_pin_level_t;

/** Configurations for output pins. */
struct st_mtu3_output_pin
{
    mtu3_io_pin_level_t output_pin_level_a; ///< I/O Control A
    mtu3_io_pin_level_t output_pin_level_b; ///< I/O Control B
    mtu3_io_pin_level_t output_pin_level_c; ///< I/O Control C
    mtu3_io_pin_level_t output_pin_level_d; ///< I/O Control D
    bool                output_enabled_a;   ///< Set to true to enable output, false to disable output
    mtu3_pin_level_t    stop_level_a;       ///< Select a stop level from ::mtu3_pin_level_t
    mtu3_pin_level_t    initial_level;      ///< Select a initial level from ::mtu3_pin_level_t
    bool                output_enabled_b;   ///< Set to true to enable output, false to disable output
    mtu3_pin_level_t    stop_level_b;       ///< Select a stop level from ::mtu3_pin_level_t
    bool                retain_level;       ///< Set to true to retain output, false to not retain output
    bool                output_enabled_c;   ///< Set to true to enable output, false to disable output
    mtu3_pin_level_t    stop_level_c;       ///< Select a stop level from ::mtu3_pin_level_t
    bool                output_enabled_d;   ///< Set to true to enable output, false to disable output
    mtu3_pin_level_t    stop_level_d;       ///< Select a stop level from ::mtu3_pin_level_t
};

/** Configurations for output pins. Please refer to the struct st_mtu3_output_pin. */
typedef struct st_mtu3_output_pin mtu3_output_pin_t;

/** Disables or enables the noise filter for input from the MTIOCnA pin */
typedef enum e_mtu3_noise_filter
{
    MTU3_NOISE_FILTER_DISABLE  = 0U,   ///< The noise filter for the MTIOC pin is disabled
    MTU3_NOISE_FILTER_A_ENABLE = 1U,   ///< The noise filter for the MTIOCA pin is enabled
    MTU3_NOISE_FILTER_B_ENABLE = 2U,   ///< The noise filter for the MTIOCB pin is enabled
    MTU3_NOISE_FILTER_C_ENABLE = 4U,   ///< The noise filter for the MTIOCC pin is enabled
    MTU3_NOISE_FILTER_D_ENABLE = 8U,   ///< The noise filter for the MTIOCD pin is enabled
} mtu3_noise_filter_t;

/** Disables or enables the noise filter for the external clock input pins of the MTU */
typedef enum e_mtu3_noise_filter_mtclk
{
    MTU3_NOISE_FILTER_MTCLK_DISABLE  = 0U, ///< The noise filter for the MTCLK pin is disabled
    MTU3_NOISE_FILTER_MTCLK_A_ENABLE = 1U, ///< The noise filter for the MTCLKA pin is enabled.
    MTU3_NOISE_FILTER_MTCLK_B_ENABLE = 2U, ///< The noise filter for the MTCLKB pin is enabled.
    MTU3_NOISE_FILTER_MTCLK_C_ENABLE = 4U, ///< The noise filter for the MTCLKC pin is enabled.
    MTU3_NOISE_FILTER_MTCLK_D_ENABLE = 8U, ///< The noise filter for the MTCLKD pin is enabled.
} mtu3_noise_filter_mtclk_t;

typedef enum e_mtu3_noise_filter_clock
{
    MTU3_NOISE_FILTER_CLOCK_DIV_1  = 0U, ///< CLK/1 - fast sampling
    MTU3_NOISE_FILTER_CLOCK_DIV_8  = 1U, ///< CLK/8
    MTU3_NOISE_FILTER_CLOCK_DIV_32 = 2U, ///< CLK/32 - slow sampling
    MTU3_NOISE_FILTER_CLOCK_SOURCE = 3U, ///< Clock source for counting
} mtu3_noise_filter_clock_t;

typedef enum e_mtu3_noise_filter_external_clock
{
    MTU3_NOISE_FILTER_EXTERNAL_CLOCK_DIV_1  = 0U, ///< CLK/1 - fast sampling
    MTU3_NOISE_FILTER_EXTERNAL_CLOCK_DIV_2  = 1U, ///< CLK/2
    MTU3_NOISE_FILTER_EXTERNAL_CLOCK_DIV_8  = 2U, ///< CLK/8
    MTU3_NOISE_FILTER_EXTERNAL_CLOCK_DIV_32 = 3U, ///< CLK/32 - slow sampling
} mtu3_noise_filter_external_clock_t;

/** Interrupt Skipping Function Select */
typedef enum e_mtu3_interrupt_skip_mode
{
    MTU3_INTERRUPT_SKIP_MODE_1 = 0U,   ///< Setting the TITCR1A or TITCR1B register enables
    MTU3_INTERRUPT_SKIP_MODE_2 = 1U,   ///< Setting the TITCR2A or TITCR2B register enables
} mtu3_interrupt_skip_mode_t;

/** Number of interrupts to skip between events */
typedef enum e_mtu3_interrupt_skip_count
{
    MTU3_INTERRUPT_SKIP_COUNT_0 = 0U,  ///< Do not skip interrupts
    MTU3_INTERRUPT_SKIP_COUNT_1,       ///< Skip one interrupt
    MTU3_INTERRUPT_SKIP_COUNT_2,       ///< Skip two interrupts
    MTU3_INTERRUPT_SKIP_COUNT_3,       ///< Skip three interrupts
    MTU3_INTERRUPT_SKIP_COUNT_4,       ///< Skip four interrupts
    MTU3_INTERRUPT_SKIP_COUNT_5,       ///< Skip five interrupts
    MTU3_INTERRUPT_SKIP_COUNT_6,       ///< Skip six interrupts
    MTU3_INTERRUPT_SKIP_COUNT_7,       ///< Skip seven interrupts
} mtu3_interrupt_skip_count_t;

/** Trigger options to start A/D conversion. */
typedef enum e_mtu3_adc_compare_match
{
    MTU3_ADC_COMPARE_MATCH_ADC_A = 0x1U, ///< Set A/D conversion start request value for MTU3 A/D converter start request A
    MTU3_ADC_COMPARE_MATCH_ADC_B = 0x2U, ///< Set A/D conversion start request value for MTU3 A/D converter start request B
} mtu3_adc_compare_match_t;

typedef enum e_mtu3_adc_tgra_compare_match
{
    MTU3_ADC_TGRA_COMPARE_MATCH_DISABLE = 0U, ///< A/D Converter Activation by TGRA Input Capture/Compare Match Disable
    MTU3_ADC_TGRA_COMPARE_MATCH_ENABLE  = 1U, ///< A/D Converter Activation by TGRA Input Capture/Compare Match Enable
} mtu3_adc_activation_tgra_compare_match_t;

typedef enum e_mtu3_buffer_mode
{
    MTU3_BUFFER_MODE_ENABLE  = 1U,     ///< Buffer mode enable
    MTU3_BUFFER_MODE_DISABLE = 0U,     ///< Buffer mode disabled
} mtu3_buffer_mode_t;

typedef enum e_mtu3_phase_counting_mode
{
    MTU3_PHASE_COUNTING_MODE_NONE,     ///< Disable Counting Mode
    MTU3_PHASE_COUNTING_MODE_1,        ///< Mode 1
    MTU3_PHASE_COUNTING_MODE_200,      ///< Mode 2 (00)
    MTU3_PHASE_COUNTING_MODE_201,      ///< Mode 2 (01)
    MTU3_PHASE_COUNTING_MODE_210,      ///< Mode 2 (1x)
    MTU3_PHASE_COUNTING_MODE_300,      ///< Mode 3 (00)
    MTU3_PHASE_COUNTING_MODE_301,      ///< Mode 3 (01)
    MTU3_PHASE_COUNTING_MODE_310,      ///< Mode 3 (1x)
    MTU3_PHASE_COUNTING_MODE_4,        ///< Mode 4
    MTU3_PHASE_COUNTING_MODE_50,       ///< Mode 5 (0x)
    MTU3_PHASE_COUNTING_MODE_51,       ///< Mode 5 (1x)
} mtu3_phase_counting_mode_t;

typedef enum e_mtu3_bit_mode
{
    MTU3_BIT_MODE_NORMAL_16BIT,        ///< normal mode(16bit mode)
    MTU3_BIT_MODE_NORMAL_32BIT,        ///< normal mode(32bit mode)
} mtu3_bit_mode_t;

typedef enum e_mtu3_external_clock
{
    MTU3_EXTERNAL_CLOCK_MTCLKA_B = 0x0, ///< MTCLKA, MTCLKB
    MTU3_EXTERNAL_CLOCK_MTCLKC_D = 0x1, ///< MTCLKC, MTCLKD
} mtu3_external_clock_t;

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref timer_api_t::open is called. */
struct st_mtu3_instance_ctrl
{
    uint32_t            open;                     ///< Whether or not channel is open
    const timer_cfg_t * p_cfg;                    ///< Pointer to initial configurations
    void              * p_reg;                    ///< Base register for this channel
    R_MTU_Type        * p_reg_com;                ///< Base register for this channel(common ch)
    void              * p_reg_nf;                 ///< Base register for this channel(noise fileter)
    uint32_t            channel_mask;             ///< Channel bitmask
    bool                oneshot_interrupt_flag;   ///< Interrupt flag when One-Shot mode
    uint8_t             tior_ioa;                 ///< TIOR.IOA register value
    uint8_t             tior_iob;                 ///< TIOR.IOB register value
    uint8_t             tior_ioc;                 ///< TIOR.IOC register value
    uint8_t             tior_iod;                 ///< TIOR.IOD register value

    void (* p_callback)(timer_callback_args_t *); ///< Pointer to callback
    timer_callback_args_t * p_callback_memory;    ///< Pointer to optional callback argument memory
    void * p_context;                             ///< Pointer to context to be passed into callback function
};

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref timer_api_t::open is called. Please refer to the struct st_mtu3_instance_ctrl. */
typedef struct st_mtu3_instance_ctrl mtu3_instance_ctrl_t;

/** MTU3 extension for advanced PWM features. */
struct st_mtu3_extended_pwm_cfg
{
    mtu3_interrupt_skip_mode_t interrupt_skip_mode_a;           ///< Selects interrupt skipping function 1 or 2(TIMTRA)
    mtu3_interrupt_skip_mode_t interrupt_skip_mode_b;           ///< Selects interrupt skipping function 1 or 2(TIMTRB)
    uint16_t adc_a_compare_match;                               ///< Timer A/D Converter Start Request Cycle A (MTU4 or MTU7)
    uint16_t adc_b_compare_match;                               ///< Timer A/D Converter Start Request Cycle B (MTU4 or MTU7)
    mtu3_interrupt_skip_count_t interrupt_skip_count_tciv4;     ///< TCIV4 Interrupt Skipping Count Setting(TITCR1A)
    mtu3_interrupt_skip_count_t interrupt_skip_count_tgia3;     ///< TGIA3 Interrupt Skipping Count Setting(TITCR1A)
    mtu3_interrupt_skip_count_t interrupt_skip_count_tciv7;     ///< TCIV7 Interrupt Skipping Count Setting(TITCR1B)
    mtu3_interrupt_skip_count_t interrupt_skip_count_tgia6;     ///< TGIA6 Interrupt Skipping Count Setting(TITCR1B)
    mtu3_interrupt_skip_count_t interrupt_skip_count_tgr4an_bn; ///< TRG4AN/TRG4BN Interrupt Skipping Count Setting(TITCR2A)
    mtu3_interrupt_skip_count_t interrupt_skip_count_tgr7an_bn; ///< TRG7AN/TRG7BN Interrupt Skipping Count Setting(TITCR2B)
};

/** MTU3 extension for advanced PWM features. Please refer to the struct st_mtu3_extended_pwm_cfg. */
typedef struct st_mtu3_extended_pwm_cfg mtu3_extended_pwm_cfg_t;

/** The MTU3 extension constitutes a unique feature of MTU3. */
struct st_mtu3_extended_cfg
{
    uint32_t          tgra_val;           ///< Capture/Compare match A register
    uint32_t          tgrb_val;           ///< Capture/Compare match B register
    uint32_t          tgrc_val;           ///< Capture/Compare match C register (Does not exist in MTU ch1-2)
    uint32_t          tgrd_val;           ///< Capture/Compare match D register (Does not exist in MTU ch1-2)
    mtu3_clock_div_t  mtu3_clk_div;       ///< Time Prescaler Select
    mtu3_clock_edge_t clk_edge;           ///< Clock Edge Select
    mtu3_tcnt_clear_t mtu3_clear;         ///< Counter Clear Source Select
    mtu3_output_pin_t mtioc_ctrl_setting; ///< I/O Control A, B

    /* Set to true to enable custom waveform, false to disable custom waveform */
    bool custom_waveform_enabled;

    /* Debounce filter for MTIOCxA or MTIOCxB input signal pin. */
    mtu3_noise_filter_t       noise_filter_mtioc_setting;
    mtu3_noise_filter_clock_t noise_filter_mtioc_clk;

    /* Debounce filter for MTCLKx input signal pin. */
    mtu3_noise_filter_mtclk_t          noise_filter_mtclk_setting;
    mtu3_noise_filter_external_clock_t noise_filter_mtclk_clk;

    /* A/D Converter Activation by TGRA Input Capture/Compare Match. */
    mtu3_adc_activation_tgra_compare_match_t adc_activation_setting;

    /* Used for other than MTU5 */
    uint8_t   capture_a_ipl;                   ///< Capture/Compare match A interrupt priority
    uint8_t   capture_b_ipl;                   ///< Capture/Compare match B interrupt priority
    IRQn_Type capture_a_irq;                   ///< Capture/Compare match A interrupt
    IRQn_Type capture_b_irq;                   ///< Capture/Compare match B interrupt
    uint8_t   capture_c_ipl;                   ///< Capture/Compare match C interrupt priority
    uint8_t   capture_d_ipl;                   ///< Capture/Compare match D interrupt priority
    IRQn_Type capture_c_irq;                   ///< Capture/Compare match C interrupt
    IRQn_Type capture_d_irq;                   ///< Capture/Compare match D interrupt

    mtu3_extended_pwm_cfg_t const * p_pwm_cfg; ///< Advanced PWM features, optional

    void   * p_reg;                            ///< Register base address for specified channel
    uint32_t compare_match_value[2];           ///< Storing compare match value for channels
    uint8_t  compare_match_status;             ///< Storing the compare match register status

    mtu3_phase_counting_mode_t counting_mode;  ///< Select the counting mode.
    mtu3_bit_mode_t            bit_mode;       ///< Select bit mode
    mtu3_external_clock_t      external_clock; ///< Select External Clock Input Pins
    mtu3_buffer_mode_t         buffer_mode;    ///< Buffer mode enable
};

/** The MTU3 extension constitutes a unique feature of MTU3. Please refer to the struct st_mtu3_extended_cfg. */
typedef struct st_mtu3_extended_cfg mtu3_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const timer_api_t g_timer_on_mtu3;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_MTU3_Open(timer_ctrl_t * const p_ctrl, timer_cfg_t const * const p_cfg);
fsp_err_t R_MTU3_Stop(timer_ctrl_t * const p_ctrl);
fsp_err_t R_MTU3_Start(timer_ctrl_t * const p_ctrl);
fsp_err_t R_MTU3_Reset(timer_ctrl_t * const p_ctrl);
fsp_err_t R_MTU3_PeriodSet(timer_ctrl_t * const p_ctrl, uint32_t const period_counts);
fsp_err_t R_MTU3_DutyCycleSet(timer_ctrl_t * const p_ctrl, uint32_t const duty_cycle_counts, uint32_t const pin);
fsp_err_t R_MTU3_InfoGet(timer_ctrl_t * const p_ctrl, timer_info_t * const p_info);
fsp_err_t R_MTU3_StatusGet(timer_ctrl_t * const p_ctrl, timer_status_t * const p_status);
fsp_err_t R_MTU3_CounterSet(timer_ctrl_t * const p_ctrl, uint32_t counter);
fsp_err_t R_MTU3_OutputEnable(timer_ctrl_t * const p_ctrl, mtu3_output_pin_t pin_level);
fsp_err_t R_MTU3_OutputDisable(timer_ctrl_t * const p_ctrl, mtu3_io_pin_t pin);
fsp_err_t R_MTU3_Enable(timer_ctrl_t * const p_ctrl);
fsp_err_t R_MTU3_Disable(timer_ctrl_t * const p_ctrl);
fsp_err_t R_MTU3_AdcTriggerSet(timer_ctrl_t * const     p_ctrl,
                               mtu3_adc_compare_match_t which_compare_match,
                               uint16_t                 compare_match_value);
fsp_err_t R_MTU3_CallbackSet(timer_ctrl_t * const          p_api_ctrl,
                             void (                      * p_callback)(timer_callback_args_t *),
                             void * const                  p_context,
                             timer_callback_args_t * const p_callback_memory);
fsp_err_t R_MTU3_Close(timer_ctrl_t * const p_ctrl);
fsp_err_t R_MTU3_CompareMatchSet(timer_ctrl_t * const        p_ctrl,
                                 uint32_t const              compare_match_value,
                                 timer_compare_match_t const match_channel);

/*******************************************************************************************************************//**
 * @} (end defgroup MTU3)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
