/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_intc_nmi.h"
#include "r_intc_nmi_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "NMI" in ASCII, used to determine if channel is open. */
#define INTC_NMI_OPEN    (0x00004e4d49U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * intc_nmi_prv_ns_callback)(external_irq_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile intc_nmi_prv_ns_callback)(external_irq_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void r_intc_nmi_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* INTC_NMI implementation of External IRQ API. */
const external_irq_api_t g_external_irq_on_intc_nmi =
{
    .open        = R_INTC_NMI_ExternalIrqOpen,
    .enable      = R_INTC_NMI_ExternalIrqEnable,
    .disable     = R_INTC_NMI_ExternalIrqDisable,
    .callbackSet = R_INTC_NMI_ExternalIrqCallbackSet,
    .close       = R_INTC_NMI_ExternalIrqClose,
};

/*******************************************************************************************************************//**
 * @addtogroup INTC_NMI
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configure a NMI pin for use with the external interrupt interface. Implements @ref external_irq_api_t::open.
 *
 * The Open function is responsible for preparing a NMI pin for operation.
 *
 * @retval FSP_SUCCESS                    Open successful.
 * @retval FSP_ERR_ASSERTION              One of the following is invalid:
 *                                          - p_ctrl or p_cfg is NULL.
 * @retval FSP_ERR_ALREADY_OPEN           The channel specified has already been opened. No configurations were changed.
 *                                        Call the associated Close function to reconfigure the channel.
 * @retval FSP_ERR_INVALID_ARGUMENT       p_cfg->trigger is invalid.
 *
 * @note This function is reentrant for different channels. It is not reentrant for the same channel.
 **********************************************************************************************************************/
fsp_err_t R_INTC_NMI_ExternalIrqOpen (external_irq_ctrl_t * const p_api_ctrl, external_irq_cfg_t const * const p_cfg)
{
    intc_nmi_instance_ctrl_t * p_ctrl = (intc_nmi_instance_ctrl_t *) p_api_ctrl;

#if INTC_NMI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(INTC_NMI_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(EXTERNAL_IRQ_TRIG_BOTH_EDGE != p_cfg->trigger, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(EXTERNAL_IRQ_TRIG_LEVEL_LOW != p_cfg->trigger, FSP_ERR_INVALID_ARGUMENT);
#endif

    p_ctrl->irq = p_cfg->irq;

#if BSP_TZ_SECURE_BUILD

    /* If this is a secure build, the callback provided in p_cfg must be secure. */
    p_ctrl->p_callback_memory = NULL;
#endif

    /* Initialize control block. */
    p_ctrl->p_callback = p_cfg->p_callback;
    p_ctrl->p_context  = p_cfg->p_context;
    p_ctrl->channel    = p_cfg->channel;

    /* Set the trigger. */
    R_INTC_IM33->NITSR_b.NTSEL = p_cfg->trigger;

    /* Dummy read the NSCR before clearing the NSTAT bit. */
    volatile uint32_t nscr = R_INTC_IM33->NSCR;
    FSP_PARAMETER_NOT_USED(nscr);

    /* Clear the NSTAT bit after changing the trigger setting to the edge type.
     * Reference section "Precaution when Changing Interrupt Settings" of the user's manual. */
    R_INTC_IM33->NSCR_b.NSTAT = 0;

    /* Dummy read the NSCR to prevent the interrupt cause that have been cleared from being accidentally accepted.
     * Reference section "Clear Timing of Interrupt Cause" of the user's manual. */
    nscr = R_INTC_IM33->NSCR;
    FSP_PARAMETER_NOT_USED(nscr);

    if (p_ctrl->irq >= 0)
    {
        R_BSP_IrqCfg(p_ctrl->irq, p_cfg->ipl, p_ctrl);
    }

    /* Mark the control block as open. */
    p_ctrl->open = INTC_NMI_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable external interrupt for specified channel at NVIC. Implements @ref external_irq_api_t::enable.
 *
 * @retval FSP_SUCCESS                 Interrupt Enabled successfully.
 * @retval FSP_ERR_ASSERTION           The p_ctrl parameter was null.
 * @retval FSP_ERR_NOT_OPEN            The channel is not opened.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    Requested IRQ is not defined in this system.
 **********************************************************************************************************************/
fsp_err_t R_INTC_NMI_ExternalIrqEnable (external_irq_ctrl_t * const p_api_ctrl)
{
    intc_nmi_instance_ctrl_t * p_ctrl = (intc_nmi_instance_ctrl_t *) p_api_ctrl;

#if INTC_NMI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(INTC_NMI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(p_ctrl->irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
#endif

    /* Clear the interrupt status and Pending bits, before the interrupt is enabled. */
    R_BSP_IrqEnable(p_ctrl->irq);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable external interrupt for specified channel at NVIC. Implements @ref external_irq_api_t::disable.
 *
 * @retval FSP_SUCCESS                 Interrupt disabled successfully.
 * @retval FSP_ERR_ASSERTION           The p_ctrl parameter was null.
 * @retval FSP_ERR_NOT_OPEN            The channel is not opened.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    Requested IRQ is not defined in this system.
 **********************************************************************************************************************/
fsp_err_t R_INTC_NMI_ExternalIrqDisable (external_irq_ctrl_t * const p_api_ctrl)
{
    intc_nmi_instance_ctrl_t * p_ctrl = (intc_nmi_instance_ctrl_t *) p_api_ctrl;

#if INTC_NMI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(INTC_NMI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(p_ctrl->irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
#endif

    /* Disable the interrupt, and then clear the interrupt pending bits and interrupt status. */
    R_BSP_IrqDisable(p_ctrl->irq);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements external_irq_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_INTC_NMI_ExternalIrqCallbackSet (external_irq_ctrl_t * const p_api_ctrl,
                                             void (                    * p_callback)(
                                                 external_irq_callback_args_t *),
                                             void const * const                   p_context,
                                             external_irq_callback_args_t * const p_callback_memory)
{
    intc_nmi_instance_ctrl_t * p_ctrl = p_api_ctrl;

#if BSP_TZ_SECURE_BUILD

    /* cmse_check_address_range returns NULL if p_callback is located in secure memory. */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));
#else
    FSP_PARAMETER_NOT_USED(p_callback_memory);
#endif

#if INTC_NMI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(INTC_NMI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_callback);

 #if BSP_TZ_SECURE_BUILD

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure. */
    external_irq_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                               CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif
#endif

#if BSP_TZ_SECURE_BUILD
    p_ctrl->p_callback_memory = p_callback_memory;
    p_ctrl->p_callback        = callback_is_secure ? p_callback :
                                (void (*)(external_irq_callback_args_t *))cmse_nsfptr_create(p_callback);
#else
    p_ctrl->p_callback = p_callback;
#endif
    p_ctrl->p_context = p_context;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Close the external interrupt channel. Implements @ref external_irq_api_t::close.
 *
 * @retval     FSP_SUCCESS          Successfully closed.
 * @retval     FSP_ERR_ASSERTION    The parameter p_ctrl is NULL.
 * @retval     FSP_ERR_NOT_OPEN     The channel is not opened.
 **********************************************************************************************************************/
fsp_err_t R_INTC_NMI_ExternalIrqClose (external_irq_ctrl_t * const p_api_ctrl)
{
    intc_nmi_instance_ctrl_t * p_ctrl = (intc_nmi_instance_ctrl_t *) p_api_ctrl;

#if INTC_NMI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(INTC_NMI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Cleanup. Disable interrupt. */
    if (p_ctrl->irq >= 0)
    {
        /* Disable the interrupt, and then clear the interrupt pending bits and interrupt status. */
        R_BSP_IrqDisable(p_ctrl->irq);
        R_FSP_IsrContextSet(p_ctrl->irq, NULL);
    }

    p_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup INTC_NMI)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * INTC_NMI External Interrupt ISR.
 **********************************************************************************************************************/
void r_intc_nmi_isr (void)
{
    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE

    IRQn_Type                  irq    = R_FSP_CurrentIrqGet();
    intc_nmi_instance_ctrl_t * p_ctrl = (intc_nmi_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Dummy read the NSCR before clearing the NSTAT bit. */
    volatile uint32_t nscr = R_INTC_IM33->NSCR;
    FSP_PARAMETER_NOT_USED(nscr);

    /* Clear the NSTAT bit before calling the user callback so that if an edge is detected while the ISR is active
     * it will not be missed. */
    R_INTC_IM33->NSCR_b.NSTAT = 0;

    /* Dummy read the NSCR to prevent the interrupt cause that should have been cleared from being accidentally
     * accepted again. Reference section "Clear Timing of Interrupt Cause" of the user's manual. */
    nscr = R_INTC_IM33->NSCR;
    FSP_PARAMETER_NOT_USED(nscr);

    if ((NULL != p_ctrl) && (NULL != p_ctrl->p_callback))
    {
#if BSP_TZ_SECURE_BUILD

        /* p_callback can point to a secure function or a non-secure function. */
        external_irq_callback_args_t args;
        if (!cmse_is_nsfptr(p_ctrl->p_callback))
        {
            /* If p_callback is secure, then the project does not need to change security state. */
            args.channel   = p_ctrl->channel;
            args.p_context = p_ctrl->p_context;
            p_ctrl->p_callback(&args);
        }
        else
        {
            /* Save current state of p_callback_args so that it can be shared between interrupts. */
            args = *p_ctrl->p_callback_memory;

            /* Set the callback args passed to the Non-secure callback. */
            p_ctrl->p_callback_memory->channel   = p_ctrl->channel;
            p_ctrl->p_callback_memory->p_context = p_ctrl->p_context;

            /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
            intc_nmi_prv_ns_callback p_callback = (intc_nmi_prv_ns_callback) (p_ctrl->p_callback);
            p_callback(p_ctrl->p_callback_memory);

            /* Restore the state of p_callback_args. */
            *p_ctrl->p_callback_memory = args;
        }

#else

        /* Set data to identify callback to user, then call user callback. */
        external_irq_callback_args_t args;
        args.channel   = p_ctrl->channel;
        args.p_context = p_ctrl->p_context;
        p_ctrl->p_callback(&args);
#endif
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
