/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CMTW_H
#define R_CMTW_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_cmtw_cfg.h"
#include "r_timer_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Maximum number of clock counts in 16 bit timer. */
#define CMTW_MAX_CLOCK_COUNTS    (UINT32_MAX)

/** Maximum period value allowed for CMTW. */
#define CMTW_MAX_PERIOD_32BIT    (UINT32_MAX + 1U)
#define CMTW_MAX_PERIOD_16BIT    (UINT16_MAX + 1U)

/*******************************************************************************************************************//**
 * @addtogroup CMTW
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Trigger edge for Input capture function. */
typedef enum e_cmtw_source_edge
{
    CMTW_SOURCE_EDGE_RISING  = 0U,     ///< Input capture trigger on rising edge
    CMTW_SOURCE_EDGE_FALLING = 1U,     ///< Input capture trigger on falling edge
    CMTW_SOURCE_EDGE_BOTH    = 2U,     ///< Input capture trigger on both edge
} cmtw_source_edge_t;

/** Level of CMTW pin */
typedef enum e_cmtw_output_pin
{
    CMTW_OUTPUT_PIN_RETAIN           = 0U, ///< Retain output value
    CMTW_OUTPUT_PIN_START_LEVEL_LOW  = 1U, ///< Pin level low
    CMTW_OUTPUT_PIN_START_LEVEL_HIGH = 2U, ///< Pin level high
} cmtw_output_pin_t;

/** Clear source of CMWCNT */
typedef enum e_cmtw_clear_source
{
    CMTW_CLEAR_SOURCE_COMPARE_MATCH_CMWCOR  = 0U, ///< Counter is cleared by CMWCOR compare match
    CMTW_CLEAR_SOURCE_DISABLED              = 1U, ///< Counter is not cleared
    CMTW_CLEAR_SOURCE_INPUT_CAPTURE_CMWICR0 = 4U, ///< Counter is cleared by CMWICR0 input capture
    CMTW_CLEAR_SOURCE_INPUT_CAPTURE_CMWICR1 = 5U, ///< Counter is cleared by CMWICR1 input capture
    CMTW_CLEAR_SOURCE_COMPARE_MATCH_CMWOCR0 = 6U, ///< Counter is cleared by CMWOCR0 output compare
    CMTW_CLEAR_SOURCE_COMPARE_MATCH_CMWOCR1 = 7U, ///< Counter is cleared by CMWOCR1 output compare
} cmtw_clear_source_t;

/** Output pins, used to select */
typedef enum e_cmtw_io_pin
{
    CMTW_IO_PIN_TOC0          = 0,     ///< TOC0
    CMTW_IO_PIN_TOC1          = 1,     ///< TOC1
    CMTW_IO_PIN_TOC0_AND_TOC1 = 2,     ///< TOC0 and TOC1
} cmtw_io_pin_t;

typedef enum e_cmtw_output_control
{
    CMTW_OUTPUT_CONTROL_DISABLED = 0U, ///< OutputCompare disabled
    CMTW_OUTPUT_CONTROL_ENABLED  = 1U, ///< OutputCompare enabled
} cmtw_output_control_t;

typedef enum e_cmtw_input_control
{
    CMTW_INPUT_CONTROL_DISABLED = 0U,  ///< InputCapture disabled
    CMTW_INPUT_CONTROL_ENABLED  = 1U,  ///< InputCapture enabled
} cmtw_input_control_t;

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref timer_api_t::open is called. */
typedef struct st_cmtw_instance_ctrl
{
    uint32_t            open;                     // Whether or not channel is open
    const timer_cfg_t * p_cfg;                    // Pointer to initial configurations
    R_CMTW0_Type      * p_reg;                    // Base register for this channel
    uint32_t            period;                   // Current timer period (counts)
    uint32_t            output_channel_mask;      // Output channel bitmask

    void (* p_callback)(timer_callback_args_t *); // Pointer to callback that is called when a timer_event_t occurs.
    timer_callback_args_t * p_callback_memory;    // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.
    void const            * p_context;            // Pointer to context to be passed into callback function
} cmtw_instance_ctrl_t;

/** Optional CMTW extension data structure.*/
typedef struct st_cmtw_extended_cfg
{
    cmtw_output_pin_t     toc0;               ///< Configure TOC0 pin
    cmtw_output_pin_t     toc1;               ///< Configure TOC1 pin
    cmtw_output_control_t toc0_control;       ///< OutputCompare0 enable setting
    cmtw_output_control_t toc1_control;       ///< OutputCompare1 enable setting
    cmtw_source_edge_t    capture_ic0_source; ///< Event sources that trigger capture of TIC0
    cmtw_source_edge_t    capture_ic1_source; ///< Event sources that trigger capture of TIC1
    cmtw_input_control_t  ic0_control;        ///< InputCapture0 enable setting
    cmtw_input_control_t  ic1_control;        ///< InputCapture1 enable setting
    cmtw_clear_source_t   clear_source;       ///< Counter clear source
    timer_variant_t       counter_size;       ///< Timer counter size

    uint8_t   capture_ic0_ipl;                ///< InputCapture 0 interrupt priority
    uint8_t   capture_ic1_ipl;                ///< InputCapture 1 interrupt priority
    IRQn_Type capture_ic0_irq;                ///< InputCapture 0 interrupt
    IRQn_Type capture_ic1_irq;                ///< InputCapture 1 interrupt
    uint8_t   compare_oc0_ipl;                ///< OutputCompare 0 interrupt priority
    uint8_t   compare_oc1_ipl;                ///< OutputCompare 1 interrupt priority
    IRQn_Type compare_oc0_irq;                ///< OutputCompare 0 interrupt
    IRQn_Type compare_oc1_irq;                ///< OutputCompare 1 interrupt
} cmtw_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const timer_api_t g_timer_on_cmtw;

/** @endcond */

fsp_err_t R_CMTW_Close(timer_ctrl_t * const p_ctrl);
fsp_err_t R_CMTW_PeriodSet(timer_ctrl_t * const p_ctrl, uint32_t const period_counts);
fsp_err_t R_CMTW_DutyCycleSet(timer_ctrl_t * const p_ctrl, uint32_t const duty_cycle_counts, uint32_t const pin);
fsp_err_t R_CMTW_Reset(timer_ctrl_t * const p_ctrl);
fsp_err_t R_CMTW_Start(timer_ctrl_t * const p_ctrl);
fsp_err_t R_CMTW_Enable(timer_ctrl_t * const p_ctrl);
fsp_err_t R_CMTW_Disable(timer_ctrl_t * const p_ctrl);
fsp_err_t R_CMTW_InfoGet(timer_ctrl_t * const p_ctrl, timer_info_t * const p_info);
fsp_err_t R_CMTW_StatusGet(timer_ctrl_t * const p_ctrl, timer_status_t * const p_status);
fsp_err_t R_CMTW_Stop(timer_ctrl_t * const p_ctrl);
fsp_err_t R_CMTW_Open(timer_ctrl_t * const p_ctrl, timer_cfg_t const * const p_cfg);
fsp_err_t R_CMTW_OutputEnable(timer_ctrl_t * const p_ctrl, cmtw_io_pin_t pin);
fsp_err_t R_CMTW_OutputDisable(timer_ctrl_t * const p_ctrl, cmtw_io_pin_t pin);
fsp_err_t R_CMTW_CallbackSet(timer_ctrl_t * const          p_ctrl,
                             void (                      * p_callback)(timer_callback_args_t *),
                             void const * const            p_context,
                             timer_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end defgroup CMTW)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */

FSP_FOOTER

#endif                                 // R_CMTW_H
