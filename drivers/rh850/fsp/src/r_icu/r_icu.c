/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_icu_cfg.h"
#include "r_icu.h"                     /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "ICU" in ASCII, used to determine if channel is open. */
#define ICU_OPEN    (0x00494355U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
BSP_INTERRUPT_ATTRIBUTE void  r_icu_isr(void); /* PRQA S 3449, 3451 # DP_MSR_R-8.5_UC1 , DP_MSR_R-8.5_UC1 */
static void                   r_icu_nmi(bsp_grp_irq_t irq);
static ioport_filter_signal_t r_icu_mapping_signal(e_icu_channel_t channel);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static volatile icu_instance_ctrl_t * gp_icu_ctrl = NULL;

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* ICU implementation of External IRQ API. */
const external_irq_api_t g_external_irq_on_icu = /* PRQA S 1502 # Published object */
{
    .open        = R_ICU_ExternalIrqOpen,        /* PRQA S 3635 # Advisory R-17.12 */
    .enable      = R_ICU_ExternalIrqEnable,      /* PRQA S 3635 # Advisory R-17.12 */
    .disable     = R_ICU_ExternalIrqDisable,     /* PRQA S 3635 # Advisory R-17.12 */
    .callbackSet = R_ICU_ExternalIrqCallbackSet, /* PRQA S 3635 # Advisory R-17.12 */
    .close       = R_ICU_ExternalIrqClose,       /* PRQA S 3635 # Advisory R-17.12 */
};

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup ICU
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configure an IRQ input pin for use with the external interrupt interface.  Implements @ref external_irq_api_t::open.
 *
 * The Open function is responsible for preparing an external IRQ pin for operation.
 *
 * @retval FSP_SUCCESS                    Open successful.
 * @retval FSP_ERR_ASSERTION              One of the following is invalid:
 *                                          - p_ctrl or p_cfg is NULL
 * @retval FSP_ERR_ALREADY_OPEN           The channel specified has already been opened. No configurations were changed.
 *                                        Call the associated Close function to reconfigure the channel.
 * @retval FSP_ERR_INVALID_CHANNEL The channel requested in p_cfg is not available on the device selected in
 *                                        r_bsp_cfg.h.
 * @retval FSP_ERR_INVALID_ARGUMENT       p_cfg->p_callback is not NULL, but ISR is not enabled. ISR must be enabled to
 *                                        use callback function.
 *
 * @note This function is reentrant for different channels.  It is not reentrant for the same channel.
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqOpen (external_irq_ctrl_t * const p_api_ctrl, external_irq_cfg_t const * const p_cfg) /* PRQA S 1505 # Published API */
{
    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) p_api_ctrl;                                           /* PRQA S 0316 # Advisory R-11.5 */

#if ICU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(ICU_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    icu_extended_cfg_t const * p_icu_extend_cfg = (icu_extended_cfg_t const *) p_cfg->p_extend; /* PRQA S 0316 # Advisory R-11.5 */
    FSP_ASSERT(NULL != p_icu_extend_cfg->p_ioport_instance);
    ioport_instance_t const * p_ioport_instance = p_icu_extend_cfg->p_ioport_instance;

    /* Callback must be used with a valid interrupt priority otherwise it will never be called. */
    FSP_ASSERT(p_cfg->p_callback);                                                               /* PRQA S 3344 # DP_MSR_R-14.4_UC1 */
    FSP_ERROR_RETURN(BSP_IRQ_DISABLED != p_cfg->ipl, FSP_ERR_INVALID_ARGUMENT);
#else
    icu_extended_cfg_t const * p_icu_extend_cfg  = (icu_extended_cfg_t const *) p_cfg->p_extend; /* PRQA S 0316 # Advisory R-11.5 */
    ioport_instance_t const  * p_ioport_instance = (ioport_instance_t *) p_icu_extend_cfg->p_ioport_instance;
#endif

    ioport_filter_cfg_t noisefilter_cfg =
    {
        IOPORT_FILTER_SAMPLE_2,
        IOPORT_FILTER_CLOCK_DIV_1,
        IOPORT_FILTER_DETECTION_DISABLE_EDGE,
        IOPORT_FILTER_SELECT_SIGNAL,
    };

    p_ctrl->channel = (e_icu_channel_t) p_cfg->channel; /* PRQA S 4342 # Advisory R-10.5 */
    p_ctrl->irq     = p_cfg->irq;

    /* Initialize control block. */
    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;

    /* Setting detection mode for NMI external pin */
    if (ICU_CHANNEL_NMI == p_ctrl->channel)
    {
        /* Initialize global pointer to ICU for NMI callback use.  */
        gp_icu_ctrl = (icu_instance_ctrl_t *) p_ctrl;

        gp_icu_ctrl->p_callback = p_cfg->p_callback;
        gp_icu_ctrl->p_context  = p_cfg->p_context;

        /* Set NMI callback function */
        R_BSP_GroupIrqWrite(BSP_GRP_IRQ_EXTERNAL_NMI, r_icu_nmi); /* PRQA S 3200, 3635 # DP_MSR_R-17.7_UC1, Advisory R-17.12 */
    }
    else
    {
        /* Do nothing */
    }

    /* Configure Interrupt only if valid vector number is provided */
    if ((p_ctrl->irq >= 0) && (p_ctrl->irq < FSP_INVALID_VECTOR)) /* PRQA S 1880 # DP_MSR_R-10.4_UC1 */
    {
        /* Configure interrupt controller */
        R_BSP_IrqCfg(p_ctrl->irq, p_cfg->ipl, p_ctrl);
    }

    /* Map the selected ICU channel to its corresponding IOPORT filter signal.
     * If the channel is not found in the mapping table, the function returns
     * IOPORT_FILTER_SIGNAL_MAX to indicate an invalid or unsupported signal. */
    ioport_filter_signal_t signal = r_icu_mapping_signal(p_ctrl->channel);       /* PRQA S 4603 # DP_MSR_R-21.2_UC1 */

    /* Call noise filter configure of IOPORT */
    noisefilter_cfg.detection_mode = (ioport_filter_detection_t) p_cfg->trigger; /* PRQA S 4322 # Advisory R-10.5 */
    p_ioport_instance->p_api->noiseFilterCfg(p_ioport_instance->p_ctrl, signal, &noisefilter_cfg);

    /* Synchronization after setting registers */
    SYNCP();                                                                     /* PRQA S 3469 # Advisory D-4.9 */

    /* Mark the control block as open */
    p_ctrl->open = ICU_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable external interrupt for specified channel. Implements @ref external_irq_api_t::enable.
 *
 * @retval FSP_SUCCESS                 Interrupt Enabled successfully.
 * @retval FSP_ERR_ASSERTION           The p_ctrl parameter was null.
 * @retval FSP_ERR_NOT_OPEN            The channel is not opened.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    Requested IRQ is not defined in this system
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqEnable (external_irq_ctrl_t * const p_api_ctrl) /* PRQA S 1505, 3673 # Published API, Advisory R-8.13 */
{
    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) p_api_ctrl;     /* PRQA S 3678, 0316 # Advisory R-8.13, Advisory R-11.5 */

#if ICU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(ICU_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((p_ctrl->irq >= 0) && (p_ctrl->irq < FSP_INVALID_VECTOR), FSP_ERR_IRQ_BSP_DISABLED); /* PRQA S 1880 # DP_MSR_R-10.4_UC1 */
#endif

    /* Configure Interrupt only if valid vector number is provided */
    if ((p_ctrl->irq >= 0) && (p_ctrl->irq < FSP_INVALID_VECTOR))                                         /* PRQA S 1880 # DP_MSR_R-10.4_UC1 */
    {
        /* Clear the interrupt status and Pending bits, before the interrupt is enabled. */
        R_BSP_IrqEnable(p_ctrl->irq);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable external interrupt for specified channel. Implements @ref external_irq_api_t::disable.
 *
 * @retval FSP_SUCCESS                 Interrupt disabled successfully.
 * @retval FSP_ERR_ASSERTION           The p_ctrl parameter was null.
 * @retval FSP_ERR_NOT_OPEN            The channel is not opened.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    Requested IRQ is not defined in this system
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqDisable (external_irq_ctrl_t * const p_api_ctrl) /* PRQA S 1505, 3673 # Published API, Advisory R-8.13 */
{
    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) p_api_ctrl;      /* PRQA S 3678, 0316 # Advisory R-8.13, Advisory R-11.5 */

#if ICU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(ICU_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((p_ctrl->irq >= 0) && (p_ctrl->irq < FSP_INVALID_VECTOR), FSP_ERR_IRQ_BSP_DISABLED); /* PRQA S 1880 # DP_MSR_R-10.4_UC1 */
#endif

    /* Configure Interrupt only if valid vector number is provided */
    if ((p_ctrl->irq >= 0) && (p_ctrl->irq < FSP_INVALID_VECTOR))                                         /* PRQA S 1880 # DP_MSR_R-10.4_UC1 */
    {
        /* Disable the interrupt, and then clear the interrupt pending bits and interrupt status. */
        R_BSP_IrqDisable(p_ctrl->irq);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements external_irq_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqCallbackSet (external_irq_ctrl_t * const          p_api_ctrl, /* PRQA S 1505 # Published API */
                                        void (                             * p_callback)(
                                            external_irq_callback_args_t   * p_args),
                                        void * const                         p_context,
                                        external_irq_callback_args_t * const p_callback_memory)
{
    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) p_api_ctrl; /* PRQA S 0316 # Advisory R-11.5 */

#if ICU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_callback);
    FSP_ERROR_RETURN(ICU_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Configure callback function and context parameters */
    p_ctrl->p_callback        = p_callback;
    p_ctrl->p_callback_memory = p_callback_memory;
    p_ctrl->p_context         = p_context;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Close the external interrupt channel. Implements @ref external_irq_api_t::close.
 *
 * @retval     FSP_SUCCESS          Successfully closed.
 * @retval     FSP_ERR_ASSERTION    The parameter p_ctrl is NULL.
 * @retval     FSP_ERR_NOT_OPEN     The channel is not opened.
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqClose (external_irq_ctrl_t * const p_api_ctrl) /* PRQA S 1505 # Published API */
{
    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) p_api_ctrl;    /* PRQA S 0316 # Advisory R-11.5 */

#if ICU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(ICU_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Configure Interrupt only if valid vector number is provided */
    if ((p_ctrl->irq >= 0) && (p_ctrl->irq < FSP_INVALID_VECTOR)) /* PRQA S 1880 # DP_MSR_R-10.4_UC1 */
    {
        /* Disable the interrupt, and then clear the interrupt pending bits and interrupt status. */
        R_BSP_IrqDisable(p_ctrl->irq);
        R_FSP_IsrContextSet(p_ctrl->irq, NULL);
    }

    /* Mark the control block as close */
    p_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup ICU)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * ICU External Interrupt ISR.
 **********************************************************************************************************************/
BSP_INTERRUPT_ATTRIBUTE void r_icu_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Clear the IR bit after calling the user callback so that if the condition is cleared the ISR will not
     * be called again. */
    R_BSP_IrqStatusClear(irq);

    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) R_FSP_IsrContextGet(irq); /* PRQA S 3678, 0316 # Advisory R-8.13, Advisory R-11.5 */

    if ((NULL != p_ctrl) && (NULL != p_ctrl->p_callback))
    {
        /* Set data to identify callback to user, then call user callback. */
        external_irq_callback_args_t args;

        /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
         * stored in non-secure memory so they can be accessed by a non-secure callback function. */
        external_irq_callback_args_t * p_args = p_ctrl->p_callback_memory;

        if (NULL == p_args)
        {
            /* Store on stack */
            p_args = &args;
        }
        else
        {
            /* Save current arguments on the stack in case this is a nested interrupt. */
            args = *p_args;
        }

        p_args->channel   = p_ctrl->channel; /* PRQA S 4424 # DP_MSR_R-10.3_UC1 */
        p_args->p_context = p_ctrl->p_context;
        p_ctrl->p_callback(p_args);

        if (NULL != p_ctrl->p_callback_memory)
        {
            /* Restore callback memory in case this is a nested interrupt. */
            *p_ctrl->p_callback_memory = args;
        }
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * ICU External interrupt NMI.
 * Nested interrupt handling is not required because NMI cannot be
 * preempted by another interrupt source.
 **********************************************************************************************************************/
static void r_icu_nmi (bsp_grp_irq_t irq)
{
    FSP_PARAMETER_NOT_USED(irq);

    external_irq_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    external_irq_callback_args_t * p_args = gp_icu_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }

    p_args->channel   = gp_icu_ctrl->channel; /* PRQA S 4424 # DP_MSR_R-10.3_UC1 */
    p_args->p_context = (void *) gp_icu_ctrl->p_context;

    if (NULL != gp_icu_ctrl->p_callback)
    {
        gp_icu_ctrl->p_callback(p_args);
    }
}

/*******************************************************************************************************************//**
 * ICU mapping signals.
 **********************************************************************************************************************/
static ioport_filter_signal_t r_icu_mapping_signal (e_icu_channel_t channel)
{
    ioport_filter_signal_t signal;     /* PRQA S 4603 # DP_MSR_R-21.2_UC1 */
#if BSP_FEATURE_ICU_SIGNAL_INTP
    if (channel == ICU_CHANNEL_NMI)
    {
        signal = IOPORT_FILTER_SIGNAL_INTP_NMI;
    }
    else
    {
        signal = (ioport_filter_signal_t) ((uint32_t) IOPORT_FILTER_SIGNAL_INTP0 + (uint32_t) channel);
    }

#else
    if (channel == ICU_CHANNEL_NMI)
    {
        signal = IOPORT_FILTER_SIGNAL_NMI;
    }
    else
    {
        signal = (ioport_filter_signal_t) ((uint32_t) IOPORT_FILTER_SIGNAL_IRQ0 + (uint32_t) channel); /* PRQA S 4342, 4394 # Advisory R-10.5, DP_MSR_R-10.8_UC1 */
    }
#endif

    return signal;
}
