/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_GTM_H
#define R_GTM_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_gtm_cfg.h"
#include "r_timer_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Maximum number of clock counts in 32 bit timer. */
#define GTM_MAX_CLOCK_COUNTS    (UINT32_MAX)

/** Maximum period value allowed for GTM. */
#define GTM_MAX_PERIOD          ((uint64_t) UINT32_MAX + 1ULL)

/*******************************************************************************************************************//**
 * @addtogroup GTM
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Optional GTM interrupt setting */
typedef enum e_gtm_giws_type
{
    GTM_GIWS_TYPE_DISABLED = 0,        ///< Do not generate interrupt when timer started
    GTM_GIWS_TYPE_ENABLED  = 1,        ///< Generates interrupt when timer started
} gtm_giws_type_t;

/** Optional GTM timer mode setting */
typedef enum e_gtm_timer_mode
{
    GTM_TIMER_MODE_INTERVAL = 0,       ///< Use interval timer mode
    GTM_TIMER_MODE_FREERUN  = 1,       ///< Use free-running comparison mode
} gtm_timer_mode_t;

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref timer_api_t::open is called. */
typedef struct st_gtm_instance_ctrl
{
    uint32_t            open;                           // Whether or not channel is open
    const timer_cfg_t * p_cfg;                          // Pointer to initial configurations
    R_GTM0_Type       * p_reg;                          // Base register for this channel
    uint32_t            period;                         // Current timer period (counts)

    void (* p_callback)(timer_callback_args_t * p_arg); // Pointer to callback
    timer_callback_args_t * p_callback_memory;          // Pointer to pre-allocated callback argument
    void const            * p_context;                  // Pointer to context to be passed into callback function
} gtm_instance_ctrl_t;

/** Optional GTM extension data structure.*/
typedef struct st_gtm_extended_cfg
{
    gtm_giws_type_t  generate_interrupt_when_starts; // Controls enabling/disabling of interrupt requests when start
    gtm_timer_mode_t gtm_mode;                       // Select GTM timer mode
} gtm_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const timer_api_t g_timer_on_gtm;

/** @endcond */

fsp_err_t R_GTM_Close(timer_ctrl_t * const p_ctrl);
fsp_err_t R_GTM_PeriodSet(timer_ctrl_t * const p_ctrl, uint32_t const period_counts);
fsp_err_t R_GTM_DutyCycleSet(timer_ctrl_t * const p_ctrl, uint32_t const duty_cycle_counts, uint32_t const pin);
fsp_err_t R_GTM_Reset(timer_ctrl_t * const p_ctrl);
fsp_err_t R_GTM_Start(timer_ctrl_t * const p_ctrl);
fsp_err_t R_GTM_Enable(timer_ctrl_t * const p_ctrl);
fsp_err_t R_GTM_Disable(timer_ctrl_t * const p_ctrl);
fsp_err_t R_GTM_InfoGet(timer_ctrl_t * const p_ctrl, timer_info_t * const p_info);
fsp_err_t R_GTM_StatusGet(timer_ctrl_t * const p_ctrl, timer_status_t * const p_status);
fsp_err_t R_GTM_Stop(timer_ctrl_t * const p_ctrl);
fsp_err_t R_GTM_Open(timer_ctrl_t * const p_ctrl, timer_cfg_t const * const p_cfg);
fsp_err_t R_GTM_CallbackSet(timer_ctrl_t * const          p_api_ctrl,
                            void (                      * p_callback)(timer_callback_args_t * p_arg),
                            void const * const            p_context,
                            timer_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end defgroup GTM)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */

FSP_FOOTER

#endif                                 /* R_GTM_H */
