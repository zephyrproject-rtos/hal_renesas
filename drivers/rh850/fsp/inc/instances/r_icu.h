/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup ICU
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */
#ifndef R_ICU_H
#define R_ICU_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_external_irq_api.h"
#include "r_ioport_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/*********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/** Supported ICU channel */
typedef enum e_icu_channel                                      /* PRQA S 1536 # Advisory R-2.4 */
{
    ICU_CHANNEL_0   = 0,                                        ///< Port IRQ0
    ICU_CHANNEL_1   = 1,                                        ///< Port IRQ1
    ICU_CHANNEL_2   = 2,                                        ///< Port IRQ2
    ICU_CHANNEL_3   = 3,                                        ///< Port IRQ3
    ICU_CHANNEL_4   = 4,                                        ///< Port IRQ4
    ICU_CHANNEL_5   = 5,                                        ///< Port IRQ5
    ICU_CHANNEL_6   = 6,                                        ///< Port IRQ6
    ICU_CHANNEL_7   = 7,                                        ///< Port IRQ7
    ICU_CHANNEL_8   = 8,                                        ///< Port IRQ8
    ICU_CHANNEL_9   = 9,                                        ///< Port IRQ9
    ICU_CHANNEL_10  = 10,                                       ///< Port IRQ10
    ICU_CHANNEL_11  = 11,                                       ///< Port IRQ11
    ICU_CHANNEL_12  = 12,                                       ///< Port IRQ12
    ICU_CHANNEL_13  = 13,                                       ///< Port IRQ13
    ICU_CHANNEL_14  = 14,                                       ///< Port IRQ14
    ICU_CHANNEL_15  = 15,                                       ///< Port IRQ15
    ICU_CHANNEL_16  = 16,                                       ///< Port IRQ16
    ICU_CHANNEL_17  = 17,                                       ///< Port IRQ17
    ICU_CHANNEL_18  = 18,                                       ///< Port IRQ18
    ICU_CHANNEL_19  = 19,                                       ///< Port IRQ19
    ICU_CHANNEL_20  = 20,                                       ///< Port IRQ20
    ICU_CHANNEL_21  = 21,                                       ///< Port IRQ21
    ICU_CHANNEL_22  = 22,                                       ///< Port IRQ22
    ICU_CHANNEL_23  = 23,                                       ///< Port IRQ23
    ICU_CHANNEL_24  = 24,                                       ///< Port IRQ24
    ICU_CHANNEL_25  = 25,                                       ///< Port IRQ25
    ICU_CHANNEL_26  = 26,                                       ///< Port IRQ26
    ICU_CHANNEL_27  = 27,                                       ///< Port IRQ27
    ICU_CHANNEL_28  = 28,                                       ///< Port IRQ28
    ICU_CHANNEL_29  = 29,                                       ///< Port IRQ29
    ICU_CHANNEL_30  = 30,                                       ///< Port IRQ30
    ICU_CHANNEL_31  = 31,                                       ///< Port IRQ31
    ICU_CHANNEL_32  = 32,                                       ///< Port IRQ32
    ICU_CHANNEL_33  = 33,                                       ///< Port IRQ33
    ICU_CHANNEL_34  = 34,                                       ///< Port IRQ34
    ICU_CHANNEL_35  = 35,                                       ///< Port IRQ35
    ICU_CHANNEL_36  = 36,                                       ///< Port IRQ36
    ICU_CHANNEL_37  = 37,                                       ///< Port IRQ37
    ICU_CHANNEL_38  = 38,                                       ///< Port IRQ38
    ICU_CHANNEL_39  = 39,                                       ///< Port IRQ39
    ICU_CHANNEL_40  = 40,                                       ///< Port IRQ40
    ICU_CHANNEL_41  = 41,                                       ///< Port IRQ41
    ICU_CHANNEL_42  = 42,                                       ///< Port IRQ42
    ICU_CHANNEL_43  = 43,                                       ///< Port IRQ43
    ICU_CHANNEL_44  = 44,                                       ///< Port IRQ44
    ICU_CHANNEL_45  = 45,                                       ///< Port IRQ45
    ICU_CHANNEL_NMI = 0xFF,                                     ///< Port NMI
} e_icu_channel_t;

/** ICU private control block. DO NOT MODIFY.  Initialization occurs when R_ICU_ExternalIrqOpen is called. */
typedef struct st_icu_instance_ctrl                             /* PRQA S 1536 # Advisory R-2.4 */
{
    uint32_t                       open;                        ///< Used to determine if channel control block is in use
    IRQn_Type                      irq;                         ///< Interrupt request number
    e_icu_channel_t                channel;                     ///< Channel
    external_irq_callback_args_t * p_callback_memory;           // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.
    void (* p_callback)(external_irq_callback_args_t * p_args); // Pointer to callback that is called when an edge is detected on the external irq pin.

    /** Placeholder for user data.  Passed to the user callback in ::external_irq_callback_args_t. */
    void * p_context;
} icu_instance_ctrl_t;

typedef struct st_icu_extended_cfg     /* PRQA S 1536 # Advisory R-2.4 */
{
    /* IOPORT Module Instance */
    ioport_instance_t const * p_ioport_instance;
} icu_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const external_irq_api_t g_external_irq_on_icu;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqOpen(external_irq_ctrl_t * const p_api_ctrl, external_irq_cfg_t const * const p_cfg);

fsp_err_t R_ICU_ExternalIrqEnable(external_irq_ctrl_t * const p_api_ctrl);

fsp_err_t R_ICU_ExternalIrqDisable(external_irq_ctrl_t * const p_api_ctrl);

fsp_err_t R_ICU_ExternalIrqCallbackSet(external_irq_ctrl_t * const          p_api_ctrl,
                                       void (                             * p_callback)(
                                           external_irq_callback_args_t   * p_args),
                                       void * const                         p_context,
                                       external_irq_callback_args_t * const p_callback_memory);

fsp_err_t R_ICU_ExternalIrqClose(external_irq_ctrl_t * const p_api_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup ICU)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_ICU_H
