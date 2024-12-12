/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_INTERFACES
 * @defgroup EXTERNAL_IRQ_API External IRQ Interface
 * @brief Interface for detecting external interrupts.
 *
 * @section EXTERNAL_IRQ_API_Summary Summary
 * The External IRQ Interface is for configuring interrupts to fire when a trigger condition is detected on an
 * external IRQ pin.
 *
 * The  External IRQ Interface can be implemented by:
 * - @ref INTC_NMI
 * - @ref INTC_IRQ
 *
 * @{
 **********************************************************************************************************************/

#ifndef R_EXTERNAL_IRQ_API_H
#define R_EXTERNAL_IRQ_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Includes board and MCU related header files. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/** Callback function parameter data */
typedef struct st_external_irq_callback_args
{
    /** Placeholder for user data. Set in @ref external_irq_api_t::open function in @ref external_irq_cfg_t. */
    void const * p_context;
    uint32_t     channel;              ///< The physical hardware channel that caused the interrupt.
} external_irq_callback_args_t;

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
typedef enum e_external_irq_pclk_div
{
    EXTERNAL_IRQ_PCLK_DIV_BY_1  = 0,   ///< Filter using PCLK divided by 1
    EXTERNAL_IRQ_PCLK_DIV_BY_8  = 1,   ///< Filter using PCLK divided by 8
    EXTERNAL_IRQ_PCLK_DIV_BY_32 = 2,   ///< Filter using PCLK divided by 32
    EXTERNAL_IRQ_PCLK_DIV_BY_64 = 3,   ///< Filter using PCLK divided by 64
} external_irq_pclk_div_t;

/** User configuration structure, used in open function */
typedef struct st_external_irq_cfg
{
    uint8_t                 channel;   ///< Hardware channel used.
    uint8_t                 ipl;       ///< Interrupt priority
    IRQn_Type               irq;       ///< NVIC interrupt number assigned to this instance
    external_irq_trigger_t  trigger;   ///< Trigger setting.
    external_irq_pclk_div_t pclk_div;  ///< Digital filter clock divisor setting.
    bool filter_enable;                ///< Digital filter enable/disable setting.

    /** Callback provided external input trigger occurs. */
    void (* p_callback)(external_irq_callback_args_t * p_args);

    /** Placeholder for user data.  Passed to the user callback in @ref external_irq_callback_args_t. */
    void const * p_context;
    void const * p_extend;             ///< External IRQ hardware dependent configuration.
} external_irq_cfg_t;

/** External IRQ control block.  Allocate an instance specific control block to pass into the external IRQ API calls.
 * @par Implemented as
 * - intc_nmi_instance_ctrl_t
 * - intc_irq_instance_ctrl_t
 */
typedef void external_irq_ctrl_t;

/** External interrupt driver structure. External interrupt functions implemented at the HAL layer will follow this API. */
typedef struct st_external_irq_api
{
    /** Initial configuration.
     * @par Implemented as
     * - @ref R_INTC_NMI_ExternalIrqOpen()
     * - @ref R_INTC_IRQ_ExternalIrqOpen()
     *
     * @param[out]  p_ctrl  Pointer to control block. Must be declared by user. Value set here.
     * @param[in]   p_cfg   Pointer to configuration structure. All elements of the structure must be set by user.
     */
    fsp_err_t (* open)(external_irq_ctrl_t * const p_ctrl, external_irq_cfg_t const * const p_cfg);

    /** Enable callback when an external trigger condition occurs.
     * @par Implemented as
     * - @ref R_INTC_NMI_ExternalIrqEnable()
     * - @ref R_INTC_IRQ_ExternalIrqEnable()
     *
     * @param[in]  p_ctrl      Control block set in Open call for this external interrupt.
     */
    fsp_err_t (* enable)(external_irq_ctrl_t * const p_ctrl);

    /** Disable callback when external trigger condition occurs.
     * @par Implemented as
     * - @ref R_INTC_NMI_ExternalIrqDisable()
     * - @ref R_INTC_IRQ_ExternalIrqDisable()
     *
     * @param[in]  p_ctrl      Control block set in Open call for this external interrupt.
     */
    fsp_err_t (* disable)(external_irq_ctrl_t * const p_ctrl);

    /**
     * Specify callback function and optional context pointer and working memory pointer.
     * @par Implemented as
     * - R_INTC_NMI_ExternalIrqCallbackSet()
     * - R_INTC_IRQ_ExternalIrqCallbackSet()
     *
     * @param[in]   p_ctrl                   Pointer to the Extneral IRQ control block.
     * @param[in]   p_callback               Callback function
     * @param[in]   p_context                Pointer to send to callback function
     * @param[in]   p_working_memory         Pointer to volatile memory where callback structure can be allocated.
     *                                       Callback arguments allocated here are only valid during the callback.
     */
    fsp_err_t (* callbackSet)(external_irq_ctrl_t * const          p_api_ctrl,
                              void (                             * p_callback)(external_irq_callback_args_t *),
                              void const * const                   p_context,
                              external_irq_callback_args_t * const p_callback_memory);

    /** Allow driver to be reconfigured. May reduce power consumption.
     * @par Implemented as
     * - @ref R_INTC_NMI_ExternalIrqClose()
     * - @ref R_INTC_IRQ_ExternalIrqClose()
     *
     * @param[in]  p_ctrl      Control block set in Open call for this external interrupt.
     */
    fsp_err_t (* close)(external_irq_ctrl_t * const p_ctrl);
} external_irq_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_external_irq_instance
{
    external_irq_ctrl_t      * p_ctrl; ///< Pointer to the control structure for this instance
    external_irq_cfg_t const * p_cfg;  ///< Pointer to the configuration structure for this instance
    external_irq_api_t const * p_api;  ///< Pointer to the API structure for this instance
} external_irq_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

/*******************************************************************************************************************//**
 * @} (end defgroup EXTERNAL_IRQ_API)
 **********************************************************************************************************************/

#endif
