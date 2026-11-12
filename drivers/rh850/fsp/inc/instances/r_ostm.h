/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_OSTM_H
#define R_OSTM_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER
#include "r_ostm_cfg.h"
#include "r_timer_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#if (BSP_FEATURE_OSTM_EXTENDED_CHANNEL_LAYOUT_AVAILABLE == 1U)
typedef R_OSTM0_Type     R_OSTMn_Type;
typedef R_IC0CKSEL8_Type R_IC0CKSELn_Type;
 #define R_OSTMn_OSTMnCTL_OSTMnMD0_Msk           R_OSTM0_OSTMnCTL_OSTMnMD0_Msk
 #define R_OSTMn_OSTMnCTL_OSTMnMD1_Msk           R_OSTM0_OSTMnCTL_OSTMnMD1_Msk
 #define R_OSTMn_OSTMnCTL_OSTMnMD2_Msk           R_OSTM0_OSTMnCTL_OSTMnMD2_Msk
 #define R_OSTMn_OSTMnCTL_OSTMnIE_Msk            R_OSTM0_OSTMnCTL_OSTMnIE_Msk
 #define R_IC0CKSELn_IC0CKSELn_IC0TMENn_Pos      R_IC0CKSEL8_IC0CKSEL8_IC0TMEN8_Pos
 #define R_IC0CKSELn_IC0CKSELn_IC0TMSELn_Pos     R_IC0CKSEL8_IC0CKSEL8_IC0TMSEL8_Pos
 #define R_IC0CKSELn_IC0CKSELn_IC0CKSELn3_Pos    R_IC0CKSEL8_IC0CKSEL8_IC0CKSEL83_Pos
 #define R_IC0CKSELn_IC0CKSELn_IC0CKSELn2_Pos    R_IC0CKSEL8_IC0CKSEL8_IC0CKSEL82_Pos
 #define R_IC0CKSELn_IC0CKSELn_IC0CKSELn1_Pos    R_IC0CKSEL8_IC0CKSEL8_IC0CKSEL81_Pos
 #define R_IC0CKSELn_IC0CKSELn_IC0CKSELn0_Pos    R_IC0CKSEL8_IC0CKSEL8_IC0CKSEL80_Pos
 #define IC0CKSELn                               IC0CKSEL8

#else
typedef R_OSTM1_Type R_OSTMn_Type;
 #define R_OSTMn_OSTMnCTL_OSTMnMD0_Msk           R_OSTM1_OSTMnCTL_OSTMnMD0_Msk
 #define R_OSTMn_OSTMnCTL_OSTMnMD1_Msk           R_OSTM1_OSTMnCTL_OSTMnMD1_Msk
 #define R_OSTMn_OSTMnCTL_OSTMnMD2_Msk           R_OSTM1_OSTMnCTL_OSTMnMD2_Msk
 #define R_OSTMn_OSTMnCTL_OSTMnIE_Msk            R_OSTM1_OSTMnCTL_OSTMnIE_Msk
#endif

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup OSTM
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Optional OSTM interrupt setting */
typedef enum e_ostm_giws_type          /* PRQA S 1536 EOF # Advisory R-2.4 */
{
    OSTM_GIWS_TYPE_DISABLED = 0,       ///< Do not generate interrupt when timer started
    OSTM_GIWS_TYPE_ENABLED  = 1,       ///< Generates interrupt when timer started
} ostm_giws_type_t;

/** Optional OSTM timer mode setting */
typedef enum e_ostm_timer_mode
{
    OSTM_TIMER_MODE_INTERVAL = 0,      ///< Use interval timer mode
    OSTM_TIMER_MODE_FREERUN  = 1,      ///< Use free-running comparison mode
} ostm_timer_mode_t;

/** Specifies/reads the level of OSTM output signals. */
typedef enum e_ostm_output_level
{
    OSTM_OUTPUT_LOW  = 0,              ///< Low Level
    OSTM_OUTPUT_HIGH = 1,              ///< High Level
} ostm_output_level_t;

/** Specifies the OSTM output mode. */
typedef enum e_ostm_output_setting
{
    OSTM_OUTPUT_SOFTWARE_CONTROL_MODE = 0, ///< Software control mode
    OSTM_OUTPUT_TOGGLE_MODE           = 1, ///< Timer-output toggling mode:
} ostm_output_setting_t;

/** Reload Counter at counter operation start*/
typedef enum e_ostm_counter_start
{
    OSTM_COUNTER_START_RELOAD_ENABLE  = 0, ///< OSTMnCNT is loaded into at counter operation start
    OSTM_COUNTER_START_RELOAD_DISABLE = 1, ///< OSTMnCNT is not loaded into at counter operation start
} ostm_counter_start_t;

#if (BSP_FEATURE_OSTM_EXTENDED_CHANNEL_LAYOUT_AVAILABLE == 1U)

/** Selects the counter-clock-enable signal */
typedef enum e_ostm_counter_clock_enable_signal
{
    OSTM_COUNTER_SELECT_CLOCK_SIGNAL_DEFAULT    = 0, ///< PCLK is selected as the source of the clock signal for counting
    OSTM_COUNTER_SELECT_CLOCK_SIGNAL_PERIPHERAL = 1, ///< Selects the peripheral module selected by IC0TMSEL8[1:0] as the counterclock-enable signal
} ostm_counter_clock_enable_signal_t;

/** Select the counter-clock-enable signal for counter */
typedef enum e_ostm_counter_select_clock
{
    OSTM_COUNTER_SELECT_CLOCK_SIGNAL_TAUD0_DEFAULT = 0, ///< Select clock from TAUD0
    OSTM_COUNTER_SELECT_CLOCK_SIGNAL_TAUD1         = 1, ///< Select clock from TAUD1
    OSTM_COUNTER_SELECT_CLOCK_SIGNAL_TAUJ0         = 2, ///< Select clock from TAUJ0
    OSTM_COUNTER_SELECT_CLOCK_SIGNAL_TAUJ1         = 3, ///< Select clock from TAUJ1
} ostm_counter_select_clock_t;

/** Select TAUJ1 channel */
typedef enum e_ostm_counter_select_tauj1_channel
{
    OSTM_COUNTER_SELECT_CLOCK_TAUJ1_CHANNEL0_DEFAULT = 0, ///< Select clock from TAUJ1 channel 0
    OSTM_COUNTER_SELECT_CLOCK_TAUJ1_CHANNEL1         = 1, ///< Select clock from TAUJ1 channel 1
    OSTM_COUNTER_SELECT_CLOCK_TAUJ1_CHANNEL2         = 2, ///< Select clock from TAUJ1 channel 2
    OSTM_COUNTER_SELECT_CLOCK_TAUJ1_CHANNEL3         = 3, ///< Select clock from TAUJ1 channel 3
} ostm_counter_clock_select_tauj1_channel_t;

/** Select TAUJ0 channel */
typedef enum e_ostm_counter_select_tauj0_channel
{
    OSTM_COUNTER_SELECT_CLOCK_TAUJ0_CHANNEL0_DEFAULT = 0, ///< Select clock from TAUJ0 channel 0
    OSTM_COUNTER_SELECT_CLOCK_TAUJ0_CHANNEL1         = 1, ///< Select clock from TAUJ0 channel 1
    OSTM_COUNTER_SELECT_CLOCK_TAUJ0_CHANNEL2         = 2, ///< Select clock from TAUJ0 channel 2
    OSTM_COUNTER_SELECT_CLOCK_TAUJ0_CHANNEL3         = 3, ///< Select clock from TAUJ0 channel 3
} ostm_counter_clock_select_tauj0_channel_t;

/** Select TAUD1 channel */
typedef enum e_ostm_counter_select_taud1_channel
{
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL0_DEFAULT = 0,  ///< Select clock from TAUD1 channel 0
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL1         = 1,  ///< Select clock from TAUD1 channel 1
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL2         = 2,  ///< Select clock from TAUD1 channel 2
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL3         = 3,  ///< Select clock from TAUD1 channel 3
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL4         = 4,  ///< Select clock from TAUD1 channel 4
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL5         = 5,  ///< Select clock from TAUD1 channel 5
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL6         = 6,  ///< Select clock from TAUD1 channel 6
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL7         = 7,  ///< Select clock from TAUD1 channel 7
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL8         = 8,  ///< Select clock from TAUD1 channel 8
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL9         = 9,  ///< Select clock from TAUD1 channel 9
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL10        = 10, ///< Select clock from TAUD1 channel 10
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL11        = 11, ///< Select clock from TAUD1 channel 11
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL12        = 12, ///< Select clock from TAUD1 channel 12
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL13        = 13, ///< Select clock from TAUD1 channel 13
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL14        = 14, ///< Select clock from TAUD1 channel 14
    OSTM_COUNTER_SELECT_CLOCK_TAUD1_CHANNEL15        = 15, ///< Select clock from TAUD1 channel 15
} ostm_counter_clock_select_taud1_channel_t;

/** Select TAUD0 channel */
typedef enum e_ostm_counter_select_taud0_channel
{
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL0_DEFAULT = 0,  ///< Select clock from TAUD0 channel 0
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL1         = 1,  ///< Select clock from TAUD0 channel 1
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL2         = 2,  ///< Select clock from TAUD0 channel 2
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL3         = 3,  ///< Select clock from TAUD0 channel 3
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL4         = 4,  ///< Select clock from TAUD0 channel 4
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL5         = 5,  ///< Select clock from TAUD0 channel 5
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL6         = 6,  ///< Select clock from TAUD0 channel 6
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL7         = 7,  ///< Select clock from TAUD0 channel 7
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL8         = 8,  ///< Select clock from TAUD0 channel 8
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL9         = 9,  ///< Select clock from TAUD0 channel 9
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL10        = 10, ///< Select clock from TAUD0 channel 10
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL11        = 11, ///< Select clock from TAUD0 channel 11
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL12        = 12, ///< Select clock from TAUD0 channel 12
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL13        = 13, ///< Select clock from TAUD0 channel 13
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL14        = 14, ///< Select clock from TAUD0 channel 14
    OSTM_COUNTER_SELECT_CLOCK_TAUD0_CHANNEL15        = 15, ///< Select clock from TAUD0 channel 15
} ostm_counter_clock_select_taud0_channel_t;
#endif

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref timer_api_t::open is called. */
typedef struct st_ostm_instance_ctrl
{
    uint32_t            open;                            // Whether or not channel is open
    const timer_cfg_t * p_cfg;                           // Pointer to initial configurations
    R_OSTMn_Type      * p_reg;                           // Base register for this channel
#if (BSP_FEATURE_OSTM_EXTENDED_CHANNEL_LAYOUT_AVAILABLE == 1U)
    R_IC0CKSEL8_Type * p_reg_cksel;                      // Base clock select register for this channel
#endif
    uint32_t period;                                     // Current timer period (counts)
    void (* p_callback)(timer_callback_args_t * p_args); // Pointer to callback
    timer_callback_args_t * p_callback_memory;           // Pointer to pre-allocated callback argument
    void const            * p_context;                   // Pointer to context to be passed into callback function
} ostm_instance_ctrl_t;

/** Optional OSTM extension data structure.*/
typedef struct st_ostm_extended_cfg
{
    ostm_giws_type_t      generate_interrupt_when_starts;          // Controls enabling/disabling of interrupt requests when start
    ostm_timer_mode_t     ostm_mode;                               // Select OSTM timer mode
    ostm_counter_start_t  counter_load_at_start;                   // Controls enabling/disabling reload counter when start
    ostm_output_setting_t output_setting;                          // Select OSTM out setting
#if (BSP_FEATURE_OSTM_EXTENDED_CHANNEL_LAYOUT_AVAILABLE == 1U)
    ostm_counter_clock_enable_signal_t        enable_signal;       // Selects the counter-clock-enable signal
    ostm_counter_select_clock_t               select_clock;        // Select the counter-clock-enable signal for counter
    ostm_counter_clock_select_tauj1_channel_t clock_tauj1_channel; // Select clock from TAUJ1 channel
    ostm_counter_clock_select_tauj0_channel_t clock_tauj0_channel; // Select clock from TAUJ0 channel
    ostm_counter_clock_select_taud1_channel_t clock_taud1_channel; // Select clock from TAUD1 channel
    ostm_counter_clock_select_taud0_channel_t clock_taud0_channel; // Select clock from TAUD0 channel
#endif
} ostm_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const timer_api_t g_timer_on_ostm;

/** @endcond */

fsp_err_t R_OSTM_Close(timer_ctrl_t * const p_ctrl);
fsp_err_t R_OSTM_PeriodSet(timer_ctrl_t * const p_ctrl, uint32_t const period_counts);
fsp_err_t R_OSTM_DutyCycleSet(timer_ctrl_t * const p_ctrl, uint32_t const duty_cycle_counts, uint32_t const pin);
fsp_err_t R_OSTM_Reset(timer_ctrl_t * const p_ctrl);
fsp_err_t R_OSTM_Start(timer_ctrl_t * const p_ctrl);
fsp_err_t R_OSTM_Enable(timer_ctrl_t * const p_ctrl);
fsp_err_t R_OSTM_Disable(timer_ctrl_t * const p_ctrl);
fsp_err_t R_OSTM_InfoGet(timer_ctrl_t * const p_ctrl, timer_info_t * const p_info);
fsp_err_t R_OSTM_StatusGet(timer_ctrl_t * const p_ctrl, timer_status_t * const p_status);
fsp_err_t R_OSTM_Stop(timer_ctrl_t * const p_ctrl);
fsp_err_t R_OSTM_Open(timer_ctrl_t * const p_ctrl, timer_cfg_t const * const p_cfg);
fsp_err_t R_OSTM_CallbackSet(timer_ctrl_t * const          p_api_ctrl,
                             void (                      * p_callback)(timer_callback_args_t * p_args),
                             void * const                  p_context,
                             timer_callback_args_t * const p_callback_memory);
fsp_err_t R_OSTM_OutputControl(timer_ctrl_t * const p_ctrl, ostm_output_level_t output_level);

/*******************************************************************************************************************//**
 * @} (end defgroup OSTM)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */

FSP_FOOTER

#endif                                 /* R_OSTM_H */
