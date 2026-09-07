/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_WKUPC_W_H
#define R_WKUPC_W_H

/*******************************************************************************************************************//**
 * @addtogroup WKUPC_W
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_external_irq_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef enum e_wkupc_w_event
{
    WKUPC_W_EVENT_EXT_IRQ0 = 0x0,      ///< GPIO0_IRQ External Event
    WKUPC_W_EVENT_EXT_IRQ1 = 0x1,      ///< GPIO1_IRQ External Event
    WKUPC_W_EVENT_EXT_IRQ2 = 0x2,      ///< GPIO2_IRQ External Event
    WKUPC_W_EVENT_EXT_IRQ3 = 0x3,      ///< GPIO3_IRQ External Event
    WKUPC_W_EVENT_EXT_IRQ4 = 0x4,      ///< GPIO4_IRQ External Event
    WKUPC_W_EVENT_EXT_IRQ5 = 0x5,      ///< GPIO5_IRQ External Event
    WKUPC_W_EVENT_EXT_IRQ6 = 0x6,      ///< GPIO6_IRQ External Event
    WKUPC_W_EVENT_EXT_IRQ7 = 0x7,      ///< GPIO7_IRQ External Event
    WKUPC_W_EVENT_PORT0    = 0x8,      ///< GPIO_P0_IRQ External Event
    WKUPC_W_EVENT_PORT1    = 0x9,      ///< GPIO_P1_IRQ External Event
    WKUPC_W_EVENT_PORT2    = 0xA,      ///< GPIO_P2_IRQ External Event
    WKUPC_W_EVENT_KEY      = 0xB,      ///< GPIO_KEY_IRQ External Event
} wkupc_w_event_t;

typedef struct st_wkupc_w_pin_cfg
{
    uint8_t                        channel_size; ///< Number of channels to be linked to generated IRQ.
    uint8_t const                * p_channel;    ///< Pointer to array of channels.
    external_irq_trigger_t const * p_trigger;    ///< Pointer to array of triggers per channel.
} wkupc_w_pin_cfg_t;

typedef struct st_wkupc_w_extended_cfg
{
    wkupc_w_event_t           event;     ///< Type of event associated with the generated IRQ.
    wkupc_w_pin_cfg_t const * p_pin_cfg; ///< Pointer to pin configuration structure for multi-channel events.
    uint8_t key_debounce;                ///< Debounce time for KEY_WAKEUP IRQ. Max value is 63.
} wkupc_w_extended_cfg_t;

/** WKUPC_W private control block. DO NOT MODIFY.  Initialization occurs when R_WKUPC_W_Open is called. */
typedef struct st_wkupc_w_instance_ctrl
{
    uint32_t  open;                                             ///< Used to determine if channel control block is in use
    IRQn_Type irq;                                              ///< NVIC interrupt number

#if BSP_TZ_SECURE_BUILD
    external_irq_callback_args_t * p_callback_memory;           ///< Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.
#endif
    void (* p_callback)(external_irq_callback_args_t * p_args); ///< Pointer to callback that is called when an edge is detected on the external irq pin.

    /** Placeholder for user data.  Passed to the user callback in ::external_irq_callback_args_t. */
    void       * p_context;
    void const * p_cfg;                                         ///< Pointer to WKUPC configuration.
} wkupc_w_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const external_irq_api_t g_external_irq_on_wkupc_w;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_WKUPC_W_Open(external_irq_ctrl_t * const p_api_ctrl, external_irq_cfg_t const * const p_cfg);
fsp_err_t R_WKUPC_W_Enable(external_irq_ctrl_t * const p_api_ctrl);
fsp_err_t R_WKUPC_W_Disable(external_irq_ctrl_t * const p_api_ctrl);
fsp_err_t R_WKUPC_W_CallbackSet(external_irq_ctrl_t * const          p_api_ctrl,
                                void (                             * p_callback)(external_irq_callback_args_t *),
                                void * const                         p_context,
                                external_irq_callback_args_t * const p_callback_memory);
fsp_err_t R_WKUPC_W_Close(external_irq_ctrl_t * const p_api_ctrl);
fsp_err_t R_WKUPC_W_PortStatusGet(external_irq_ctrl_t * const p_api_ctrl, uint32_t * status);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_WKUPC_W_H

/*******************************************************************************************************************//**
 * @} (end addtogroup WKUPC_W)
 **********************************************************************************************************************/
