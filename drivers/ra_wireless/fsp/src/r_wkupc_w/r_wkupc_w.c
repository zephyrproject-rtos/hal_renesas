/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_wkupc_w.h"
#include "r_wkupc_w_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "WKUPC" in ASCII, used to determine if device is open. */
#define WKUPC_W_OPEN                        (0x574B5550)
#define WKUPC_W_MAX_INSTANCE_COUNT          (12)
#define WKUPC_W_MAX_KEY_DEBOUNCE_TIME_MS    (63)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * wkupc_w_prv_ns_callback)(external_irq_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile wkupc_w_prv_ns_callback)(external_irq_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_wkupc_w_reset(wkupc_w_instance_ctrl_t * p_ctrl);
static void r_wkupc_w_key_setup(wkupc_w_instance_ctrl_t * p_ctrl);
static void r_wkupc_w_gpio_setup(wkupc_w_instance_ctrl_t * p_ctrl);
static void r_wkupc_w_wakeup_pins_get(wkupc_w_instance_ctrl_t * p_ctrl, uint32_t * pins);

#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_wkupc_w_parameter_check(external_irq_cfg_t const * const p_cfg);

#endif

void r_wkupc_w_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* As multiple instances of the module are expected to be used concurrently, there should be a way to
 * determine when all instances are closed, and only then disable the clock of the IP.
 */
static uint8_t g_instance_count = 0;

static uint32_t g_port_state[BSP_FEATURE_IO_PORT_COUNT] = {0};
static uint32_t g_key_state[BSP_FEATURE_IO_PORT_COUNT]  = {0};

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* WKUPC_W implementation of External IRQ API. */
const external_irq_api_t g_external_irq_on_wkupc_w =
{
    .open        = R_WKUPC_W_Open,
    .enable      = R_WKUPC_W_Enable,
    .disable     = R_WKUPC_W_Disable,
    .callbackSet = R_WKUPC_W_CallbackSet,
    .close       = R_WKUPC_W_Close,
};

/*******************************************************************************************************************//**
 * @addtogroup WKUPC_W
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Opens and configures the WKUPC_W driver module. Implements @ref external_irq_api_t::open.
 *
 * @retval FSP_SUCCESS               Initialization was successful.
 * @retval FSP_ERR_ASSERTION         Invalid p_api_ctrl or p_cfg pointer.
 * @retval FSP_ERR_ALREADY_OPEN      Module is already open.
 * @retval FSP_ERR_INVALID_POINTER   Invalid p_pin_cfg, p_channel or p_trigger pointer.
 * @retval FSP_ERR_INVALID_ARGUMENT  One of the following:
 *                                   - Invalid size of triggering channel
 *                                   - Invalid IRQ or priority
 *                                   - Invalid callback pointer
 *                                   - Debounce time is out of bounds.
 * @retval FSP_ERR_INVALID_MODE      One of the following:
 *                                   - Inconsistent trigger settings and debounce time. Triggers should be edge-sensitive
 *                                     for zero debounce time, and level-sensitive otherwise. Applies only to GPIO Key IRQ.
 *                                   - Inconsistent channels and external IRQ event. For GPIO_Px_IRQ interrupts, all channels
 *                                     must belong to the corresponding GPIO port.
 *
 * @note This function is reentrant for different channels.  It is not reentrant for the same channel.
 **********************************************************************************************************************/
fsp_err_t R_WKUPC_W_Open (external_irq_ctrl_t * const p_api_ctrl, external_irq_cfg_t const * const p_cfg)
{
    wkupc_w_instance_ctrl_t * p_instance_ctrl = (wkupc_w_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t                 err             = FSP_SUCCESS;
    FSP_CRITICAL_SECTION_DEFINE;

    /* Parameter checking */
#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);

    FSP_ERROR_RETURN(WKUPC_W_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ERROR_RETURN(g_instance_count < WKUPC_W_MAX_INSTANCE_COUNT, FSP_ERR_IN_USE);

    err = r_wkupc_w_parameter_check(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif
    wkupc_w_extended_cfg_t const * p_extend = p_cfg->p_extend;

    /* Save the configuration  */
    p_instance_ctrl->irq        = p_cfg->irq;
    p_instance_ctrl->p_callback = p_cfg->p_callback;
    p_instance_ctrl->p_context  = p_cfg->p_context;
    p_instance_ctrl->p_cfg      = p_cfg;

    /* Disable interrupt, then configure it. */
    if (p_instance_ctrl->irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->irq);
        R_BSP_IrqCfg(p_cfg->irq, p_cfg->ipl, p_instance_ctrl);
    }

    FSP_CRITICAL_SECTION_ENTER;
    if (!g_instance_count)
    {
        /* Enable clock for the first instance of the driver. */
        CRG_TOP->CLK_PD_SLP_REG_b.WAKEUPCT_ENABLE = 1;
    }

    g_instance_count++;
    FSP_CRITICAL_SECTION_EXIT;

    if (WKUPC_W_EVENT_KEY == p_extend->event)
    {
        r_wkupc_w_key_setup(p_instance_ctrl);
    }
    else
    {
        r_wkupc_w_gpio_setup(p_instance_ctrl);
    }

    p_instance_ctrl->open = WKUPC_W_OPEN;

    return err;
}

/*******************************************************************************************************************//**
 * Enable the generation of the requested interrupt and enable it at NVIC, if possible.
 * Implements @ref external_irq_api_t::enable.
 *
 * @retval FSP_SUCCESS          Interrupt was successfully enabled.
 * @retval FSP_ERR_ASSERTION    Invalid p_api_ctrl or p_extend.
 * @retval FSP_ERR_NOT_OPEN     The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_WKUPC_W_Enable (external_irq_ctrl_t * const p_api_ctrl)
{
    wkupc_w_instance_ctrl_t * p_instance_ctrl = (wkupc_w_instance_ctrl_t *) p_api_ctrl;
    external_irq_cfg_t      * p_cfg;
    FSP_CRITICAL_SECTION_DEFINE;

    /* Parameter checking */
#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
#endif
    p_cfg = (external_irq_cfg_t *) p_instance_ctrl->p_cfg;
#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(WKUPC_W_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    wkupc_w_extended_cfg_t * p_extend = (wkupc_w_extended_cfg_t *) p_cfg->p_extend;

    /* TODO: PARAMETER CHECKING FOR P_PIN_CFG */

    if (WKUPC_W_EVENT_KEY == p_extend->event)
    {
        uint32_t pins[BSP_FEATURE_IO_PORT_COUNT];

        r_wkupc_w_wakeup_pins_get(p_instance_ctrl, pins);

        for (uint32_t port_idx = 0; port_idx < BSP_FEATURE_IO_PORT_COUNT; port_idx++)
        {
            FSP_CRITICAL_SECTION_ENTER;

            /* Reserved bits are configured. */
            *(&WAKEUP->WKUP_P0_SEL_REG + port_idx) |= pins[port_idx];

            FSP_CRITICAL_SECTION_EXIT;
        }
    }
    else
    {
        uint32_t port_idx = (p_extend->event < WKUPC_W_EVENT_PORT0) ? p_cfg->channel >> BSP_IO_PORT_OFFSET :
                            p_extend->p_pin_cfg->p_channel[0] >> BSP_IO_PORT_OFFSET;
        uint32_t pins;

        r_wkupc_w_wakeup_pins_get(p_instance_ctrl, &pins);

        FSP_CRITICAL_SECTION_ENTER;

        *(&WAKEUP->WKUP_P0_SEL_REG + port_idx) |= pins;

        FSP_CRITICAL_SECTION_EXIT;
    }

    /* IRQ may not be set in NVIC for GPIOx interrupts that are only used to trigger DTC/ELC. */
    if (p_instance_ctrl->irq >= 0)
    {
        R_BSP_IrqEnable(p_instance_ctrl->irq);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable the generation of the requested interrupt and disable it at NVIC, if possible.
 * Implements @ref external_irq_api_t::disable.
 *
 * @retval FSP_SUCCESS          Interrupts were successfully disabled.
 * @retval FSP_ERR_ASSERTION    Invalid p_api_ctrl or p_extend.
 * @retval FSP_ERR_NOT_OPEN     The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_WKUPC_W_Disable (external_irq_ctrl_t * const p_api_ctrl)
{
    wkupc_w_instance_ctrl_t * p_instance_ctrl = (wkupc_w_instance_ctrl_t *) p_api_ctrl;
    external_irq_cfg_t      * p_cfg;
    FSP_CRITICAL_SECTION_DEFINE;

    /* Parameter checking */
#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
#endif
    p_cfg = (external_irq_cfg_t *) p_instance_ctrl->p_cfg;
#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(WKUPC_W_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    wkupc_w_extended_cfg_t * p_extend = (wkupc_w_extended_cfg_t *) p_cfg->p_extend;

    /* TODO: PARAMETER CHECKING FOR P_PIN_CFG */

    if (WKUPC_W_EVENT_KEY == p_extend->event)
    {
        uint32_t pins[BSP_FEATURE_IO_PORT_COUNT];

        r_wkupc_w_wakeup_pins_get(p_instance_ctrl, pins);

        for (uint32_t port_idx = 0; port_idx < BSP_FEATURE_IO_PORT_COUNT; port_idx++)
        {
            FSP_CRITICAL_SECTION_ENTER;

            /* Reserved bits are cleared. */
            *(&WAKEUP->WKUP_P0_SEL_REG + port_idx) &= ~pins[port_idx];

            FSP_CRITICAL_SECTION_EXIT;
        }
    }
    else
    {
        uint32_t port_idx = (p_extend->event < WKUPC_W_EVENT_PORT0) ? p_cfg->channel >> BSP_IO_PORT_OFFSET :
                            p_extend->p_pin_cfg->p_channel[0] >> BSP_IO_PORT_OFFSET;
        uint32_t pins;

        r_wkupc_w_wakeup_pins_get(p_instance_ctrl, &pins);

        FSP_CRITICAL_SECTION_ENTER;

        /* Reserved bits are cleared. */
        *(&WAKEUP->WKUP_P0_SEL_REG + port_idx) &= ~pins;

        FSP_CRITICAL_SECTION_EXIT;
    }

    /* Disable interrupts */
    if (p_instance_ctrl->irq >= 0)
    {
        R_BSP_IrqDisable(p_instance_ctrl->irq);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements @ref external_irq_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_WKUPC_W_CallbackSet (external_irq_ctrl_t * const          p_api_ctrl,
                                 void (                             * p_callback)(external_irq_callback_args_t *),
                                 void * const                         p_context,
                                 external_irq_callback_args_t * const p_callback_memory)
{
    wkupc_w_instance_ctrl_t * p_instance_ctrl = (wkupc_w_instance_ctrl_t *) p_api_ctrl;

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));
#else
    FSP_PARAMETER_NOT_USED(p_callback_memory);
#endif

#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(WKUPC_W_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_callback);

 #if BSP_TZ_SECURE_BUILD

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    wkupc_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                        CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif
#endif

    /* Store callback and context */
#if BSP_TZ_SECURE_BUILD
    p_ctrl->p_callback_memory   = p_callback_memory;
    p_instance_ctrl->p_callback = callback_is_secure ? p_callback :
                                  (void (*)(wkupc_callback_args_t *))cmse_nsfptr_create(p_callback);
#else
    p_instance_ctrl->p_callback = p_callback;
#endif
    p_instance_ctrl->p_context = p_context;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Close the WKUPC_W driver.
 * Implements @ref external_irq_api_t::close.
 *
 * @retval FSP_SUCCESS          De-Initialization was successful and WKUPC_W driver closed.
 * @retval FSP_ERR_ASSERTION    Invalid p_api_ctrl or p_extend.
 * @retval FSP_ERR_NOT_OPEN     The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_WKUPC_W_Close (external_irq_ctrl_t * const p_api_ctrl)
{
    wkupc_w_instance_ctrl_t * p_instance_ctrl = (wkupc_w_instance_ctrl_t *) p_api_ctrl;

    /* Parameter checking */
#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_instance_ctrl->p_cfg);
    FSP_ERROR_RETURN(WKUPC_W_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    FSP_CRITICAL_SECTION_DEFINE;

    /* Disable interrupt */
    if (p_instance_ctrl->irq >= 0)
    {
        R_BSP_IrqDisable(p_instance_ctrl->irq);
    }

    /* Reset configuration */
    r_wkupc_w_reset(p_instance_ctrl);

    /* Latched IRQ was cleared. Clear pending IRQ in NVIC as well. */
    if (p_instance_ctrl->irq >= 0)
    {
        R_BSP_IrqClearPending(p_instance_ctrl->irq);
    }

    FSP_CRITICAL_SECTION_ENTER;
    g_instance_count--;
    if (!g_instance_count)
    {
        /* Only disable the clock, if this is the only module instance. */
        CRG_TOP->CLK_PD_SLP_REG_b.WAKEUPCT_ENABLE = 0;
    }

    FSP_CRITICAL_SECTION_EXIT;

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get the status of a GPIO Port.
 *
 * @retval FSP_SUCCESS          Operation was successful.
 * @retval FSP_ERR_ASSERTION    Invalid p_api_ctrl or p_extend.
 * @retval FSP_ERR_NOT_OPEN     The control block has not been opened.
 * @retval FSP_ERR_UNSUPPORTED  Unsupported for specific external event type. Only supported for Port and Key events.
 **********************************************************************************************************************/
fsp_err_t R_WKUPC_W_PortStatusGet (external_irq_ctrl_t * const p_api_ctrl, uint32_t * status)
{
    wkupc_w_instance_ctrl_t * p_instance_ctrl = (wkupc_w_instance_ctrl_t *) p_api_ctrl;
    external_irq_cfg_t      * p_cfg;

    /* Parameter checking */
#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
#endif
    p_cfg = (external_irq_cfg_t *) p_instance_ctrl->p_cfg;
#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(WKUPC_W_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    wkupc_w_extended_cfg_t * p_extend = (wkupc_w_extended_cfg_t *) p_cfg->p_extend;

    switch (p_extend->event)
    {
        case WKUPC_W_EVENT_PORT0:
        case WKUPC_W_EVENT_PORT1:
#if !BSP_MCU_GROUP_RA6B2
        case WKUPC_W_EVENT_PORT2:
#endif
            {
                *status = g_port_state[p_extend->event - WKUPC_W_EVENT_PORT0];

                return FSP_SUCCESS;
            }

        case WKUPC_W_EVENT_KEY:
        {
            memcpy(status, g_key_state, BSP_FEATURE_IO_PORT_COUNT * sizeof(uint32_t));

            return FSP_SUCCESS;
        }

        default:
        {
            return FSP_ERR_UNSUPPORTED;
        }
    }
}

/*******************************************************************************************************************//**
 * @} (end addtpgroup WKUPC_W)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Reset the configuration of the Wakeup controller.
 *
 * Calling this function will reset all the configurations for the GPIO pins reserved by the driver instance,
 * without modifying the state of the rest of them.
 *
 * @param [in] p_ctrl    Pointer to an instance's control structure.
 **********************************************************************************************************************/
static void r_wkupc_w_reset (wkupc_w_instance_ctrl_t * p_ctrl)
{
    external_irq_cfg_t     * p_cfg    = (external_irq_cfg_t *) p_ctrl->p_cfg;
    wkupc_w_extended_cfg_t * p_extend = (wkupc_w_extended_cfg_t *) p_cfg->p_extend;
    FSP_CRITICAL_SECTION_DEFINE;

    if (WKUPC_W_EVENT_KEY == p_extend->event)
    {
        FSP_CRITICAL_SECTION_ENTER;
        WAKEUP->WKUP_CTRL_REG = 0;
        FSP_CRITICAL_SECTION_EXIT;

        uint32_t pins[BSP_FEATURE_IO_PORT_COUNT];

        r_wkupc_w_wakeup_pins_get(p_ctrl, pins);

        for (uint32_t port_idx = 0; port_idx < BSP_FEATURE_IO_PORT_COUNT; port_idx++)
        {
            FSP_CRITICAL_SECTION_ENTER;

            /* Reserved bits are set to 0. */
            *(&WAKEUP->WKUP_P0_POL_REG + port_idx) &= ~pins[port_idx];
            *(&WAKEUP->WKUP_P0_SEL_REG + port_idx) &= ~pins[port_idx];
            FSP_CRITICAL_SECTION_EXIT;
        }

        WAKEUP->WKUP_KEY_IRQ_STATUS_REG = 1;

        for (uint8_t port_idx = 0; port_idx < BSP_FEATURE_IO_PORT_COUNT; port_idx++)
        {
            *(&WAKEUP->WKUP_P0_STATUS_REG + port_idx) = pins[port_idx];
        }
    }
    else
    {
        uint32_t port_idx = (p_extend->event < WKUPC_W_EVENT_PORT0) ? p_cfg->channel >> BSP_IO_PORT_OFFSET :
                            p_extend->p_pin_cfg->p_channel[0] >> BSP_IO_PORT_OFFSET;
        uint32_t pins;

        r_wkupc_w_wakeup_pins_get(p_ctrl, &pins);

        FSP_CRITICAL_SECTION_ENTER;

        /* Reserved bits are set to 0. */
        *(&WAKEUP->WKUP_P0_POL_REG + port_idx)        &= ~pins;
        *(&WAKEUP->WKUP_P0_EDGE_EN_REG + port_idx)    &= ~pins;
        *(&WAKEUP->WKUP_P0_IRQ_ENABLE_REG + port_idx) &= ~pins;
        *(&WAKEUP->WKUP_P0_SEL_REG + port_idx)        &= ~pins;
        FSP_CRITICAL_SECTION_EXIT;

        uint32_t event_idx;

        if (p_extend->event < WKUPC_W_EVENT_PORT0)
        {
            event_idx = p_extend->event - WKUPC_W_EVENT_EXT_IRQ0;
            *(&WAKEUP->WKUP_GPIO0_IRQ_REG + event_idx) = 0;
        }

        *(&WAKEUP->WKUP_P0_STATUS_REG + port_idx) = pins;
    }
}

/*******************************************************************************************************************//**
 * WKUPC_W Callback ISR for GPIOx, GPIO_Px and Key IRQs.
 **********************************************************************************************************************/
void r_wkupc_w_isr (void)
{
    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE;

    IRQn_Type                 irq      = R_FSP_CurrentIrqGet();
    wkupc_w_instance_ctrl_t * p_ctrl   = (wkupc_w_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    external_irq_cfg_t      * p_cfg    = (external_irq_cfg_t *) p_ctrl->p_cfg;
    wkupc_w_extended_cfg_t  * p_extend = (wkupc_w_extended_cfg_t *) p_cfg->p_extend;

    /* Clear the latched interrupts. */
    if (WKUPC_W_EVENT_KEY == p_extend->event)
    {
        uint32_t pins[BSP_FEATURE_IO_PORT_COUNT];

        r_wkupc_w_wakeup_pins_get(p_ctrl, pins);

        for (uint8_t idx = 0; idx < BSP_FEATURE_IO_PORT_COUNT; idx++)
        {
            g_key_state[idx] = *(&WAKEUP->WKUP_P0_STATUS_REG + idx) & pins[idx];
        }

        WAKEUP->WKUP_KEY_IRQ_STATUS_REG = 1;
    }
    else if (p_extend->event < WKUPC_W_EVENT_PORT0)
    {
        /* Nothing to be done, status cleared by ICU automatically. */
    }
    else
    {
        uint32_t port_idx           = p_extend->event - WKUPC_W_EVENT_PORT0;
        uint32_t wkup_p0_status     = *(&WAKEUP->WKUP_P0_STATUS_REG + port_idx);
        uint32_t wkup_p0_irq_enable = *(&WAKEUP->WKUP_P0_IRQ_ENABLE_REG + port_idx);
        g_port_state[port_idx] = wkup_p0_status & wkup_p0_irq_enable;

        /* Reset the status of the pins that triggered the GPIO Px interrupt. */
        *(&WAKEUP->WKUP_P0_STATUS_REG + port_idx) = g_port_state[port_idx];
    }

    /* Clear the IR flag in the ICU */
    R_BSP_IrqStatusClear(irq);

    if ((NULL != p_ctrl) && (NULL != p_ctrl->p_callback))
    {
#if BSP_TZ_SECURE_BUILD

        /* p_callback can point to a secure function or a non-secure function. */
        external_irq_callback_args_t args;
        if (!cmse_is_nsfptr(p_ctrl->p_callback))
        {
            /* If p_callback is secure, then the project does not need to change security state. */
            args.p_context = p_ctrl->p_context;
            p_ctrl->p_callback(&args);
        }
        else
        {
            /* Save current state of p_callback_args so that it can be shared between interrupts. */
            args = *p_ctrl->p_callback_memory;

            /* Set the callback args passed to the Non-secure callback. */
            p_ctrl->p_callback_memory->p_context = p_ctrl->p_context;

            /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
            icu_prv_ns_callback p_callback = (icu_prv_ns_callback) (p_ctrl->p_callback);
            p_callback(p_ctrl->p_callback_memory);

            /* Restore the state of p_callback_args. */
            *p_ctrl->p_callback_memory = args;
        }

#else

        /* Set data to identify callback to user, then call user callback. */
        external_irq_callback_args_t args;
        args.p_context = p_ctrl->p_context;
        p_ctrl->p_callback(&args);
#endif
    }

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;
}

/*******************************************************************************************************************//**
 * Configure the Wakeup Controller for a Key event.
 *
 * @param [in] p_ctrl    Pointer to an instance's control structure.
 **********************************************************************************************************************/
static void r_wkupc_w_key_setup (wkupc_w_instance_ctrl_t * p_ctrl)
{
    external_irq_cfg_t      * p_cfg     = (external_irq_cfg_t *) p_ctrl->p_cfg;
    wkupc_w_extended_cfg_t  * p_extend  = (wkupc_w_extended_cfg_t *) p_cfg->p_extend;
    wkupc_w_pin_cfg_t const * p_pin_cfg = p_extend->p_pin_cfg;
    FSP_CRITICAL_SECTION_DEFINE;

    uint32_t pin_polarity[BSP_FEATURE_IO_PORT_COUNT];
    uint32_t pins[BSP_FEATURE_IO_PORT_COUNT];

    r_wkupc_w_wakeup_pins_get(p_ctrl, pins);

    memset(pin_polarity, 0x0, sizeof(uint32_t) * BSP_FEATURE_IO_PORT_COUNT);

    for (uint32_t idx = 0; idx < p_pin_cfg->channel_size; idx++)
    {
        uint32_t port_idx = (p_pin_cfg->p_channel[idx] & BSP_IO_PORT_BITS) >> BSP_IO_PORT_OFFSET;

        pin_polarity[port_idx] |= (p_pin_cfg->p_trigger[idx] >> 1) << (p_pin_cfg->p_channel[idx] & BSP_IO_PIN_BITS);
    }

    for (uint32_t port_idx = 0; port_idx < BSP_FEATURE_IO_PORT_COUNT; port_idx++)
    {
        FSP_CRITICAL_SECTION_ENTER;

        uint32_t old_pol = *(&WAKEUP->WKUP_P0_POL_REG + port_idx);

        /* Reserved bits are set to 0. */
        old_pol &= ~pins[port_idx];

        /* Reserved bits are configured. */
        *(&WAKEUP->WKUP_P0_POL_REG + port_idx) = pin_polarity[port_idx] | old_pol;

        FSP_CRITICAL_SECTION_EXIT;
    }

    FSP_CRITICAL_SECTION_ENTER;
    WAKEUP->WKUP_CTRL_REG = (p_extend->key_debounce & WAKEUP_WKUP_CTRL_REG_WKUP_DEB_VALUE_Msk) |
                            WAKEUP_WKUP_CTRL_REG_WKUP_KEY_IRQ_ENABLE_Msk;
    FSP_CRITICAL_SECTION_EXIT;
}

/*******************************************************************************************************************//**
 * Configure the Wakeup Controller for a GPIO event.
 *
 * @param [in] p_ctrl    Pointer to an instance's control structure.
 **********************************************************************************************************************/
static void r_wkupc_w_gpio_setup (wkupc_w_instance_ctrl_t * p_ctrl)
{
    external_irq_cfg_t     * p_cfg    = (external_irq_cfg_t *) p_ctrl->p_cfg;
    wkupc_w_extended_cfg_t * p_extend = (wkupc_w_extended_cfg_t *) p_cfg->p_extend;

    FSP_CRITICAL_SECTION_DEFINE;

    uint32_t pins_polarity = 0;
    uint32_t pins_edge     = 0;
    uint32_t pins;
    uint32_t port_idx;

    r_wkupc_w_wakeup_pins_get(p_ctrl, &pins);

    if (p_extend->event < WKUPC_W_EVENT_PORT0)
    {
        port_idx       = p_cfg->channel >> BSP_IO_PORT_OFFSET;
        pins_polarity |= (p_cfg->trigger >> 1) << (p_cfg->channel & BSP_IO_PIN_BITS);
        pins_edge     |= (p_cfg->trigger & 0x1) << (p_cfg->channel & BSP_IO_PIN_BITS);
    }
    else
    {
        wkupc_w_pin_cfg_t const * p_pin_cfg = p_extend->p_pin_cfg;

        port_idx = (p_pin_cfg->p_channel[0] & BSP_IO_PORT_BITS) >> BSP_IO_PORT_OFFSET;

        for (uint32_t idx = 0; idx < p_pin_cfg->channel_size; idx++)
        {
            pins_polarity |= (p_pin_cfg->p_trigger[idx] >> 1) << (p_pin_cfg->p_channel[idx] & BSP_IO_PIN_BITS);
            pins_edge     |= (p_pin_cfg->p_trigger[idx] & 0x1) << (p_pin_cfg->p_channel[idx] & BSP_IO_PIN_BITS);
        }
    }

    FSP_CRITICAL_SECTION_ENTER;

    /* Reserved bits are set to 0. */
    uint32_t old_edge = *(&WAKEUP->WKUP_P0_EDGE_EN_REG + port_idx);
    uint32_t old_pol  = *(&WAKEUP->WKUP_P0_POL_REG + port_idx);

    /* Reserved bits are set to 0. */
    old_edge &= ~pins;
    old_pol  &= ~pins;

    /* Reserved bits are configured. */
    *(&WAKEUP->WKUP_P0_POL_REG + port_idx)     = pins_polarity | old_pol;
    *(&WAKEUP->WKUP_P0_EDGE_EN_REG + port_idx) = pins_edge | old_edge;

    FSP_CRITICAL_SECTION_EXIT;

    if (p_extend->event < WKUPC_W_EVENT_PORT0)
    {
        uint32_t event_idx = p_extend->event - WKUPC_W_EVENT_EXT_IRQ0;

        *(&WAKEUP->WKUP_GPIO0_IRQ_REG + event_idx) = (port_idx << WAKEUP_WKUP_GPIO0_IRQ_REG_GPIO_IRQ_PORT_Pos) |
                                                     (p_cfg->channel & BSP_IO_PIN_BITS) |
                                                     WAKEUP_WKUP_GPIO0_IRQ_REG_GPIO_IRQ_ENABLE_Msk;
    }
    else
    {
        *(&WAKEUP->WKUP_P0_IRQ_ENABLE_REG + port_idx) = pins;
    }
}

/*******************************************************************************************************************//**
 * Return a bitmap of the GPIO pins used by the current driver instance.
 *
 * @param [in]  p_ctrl         Pointer to an instance's control structure.
 * @param [out] pins           Pointer to the generated bitmap.
 **********************************************************************************************************************/
static void r_wkupc_w_wakeup_pins_get (wkupc_w_instance_ctrl_t * p_ctrl, uint32_t * pins)
{
    external_irq_cfg_t      * p_cfg     = (external_irq_cfg_t *) p_ctrl->p_cfg;
    wkupc_w_extended_cfg_t  * p_extend  = (wkupc_w_extended_cfg_t *) p_cfg->p_extend;
    wkupc_w_pin_cfg_t const * p_pin_cfg = p_extend->p_pin_cfg;

    if (WKUPC_W_EVENT_KEY == p_extend->event)
    {
        memset(pins, 0, sizeof(uint32_t) * BSP_FEATURE_IO_PORT_COUNT);

        for (uint32_t idx = 0; idx < p_pin_cfg->channel_size; idx++)
        {
            uint32_t port_idx = (p_pin_cfg->p_channel[idx] & BSP_IO_PORT_BITS) >> BSP_IO_PORT_OFFSET;

            pins[port_idx] |= 1 << (p_pin_cfg->p_channel[idx] & BSP_IO_PIN_BITS);
        }
    }
    else if (p_extend->event < WKUPC_W_EVENT_PORT0)
    {
        *pins = 1 << (p_cfg->channel & BSP_IO_PIN_BITS);
    }
    else
    {
        *pins = 0;

        for (uint32_t idx = 0; idx < p_pin_cfg->channel_size; idx++)
        {
            *pins |= 1 << (p_pin_cfg->p_channel[idx] & BSP_IO_PIN_BITS);
        }
    }
}

#if WKUPC_W_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Perform basic parameter checking for the configuration provided by the user.
 *
 * @param [in]  p_cfg         Pointer to configuration structure.
 **********************************************************************************************************************/
static fsp_err_t r_wkupc_w_parameter_check (external_irq_cfg_t const * const p_cfg)
{
    wkupc_w_extended_cfg_t  * p_extend  = (wkupc_w_extended_cfg_t *) p_cfg->p_extend;
    wkupc_w_pin_cfg_t const * p_pin_cfg = p_extend->p_pin_cfg;

    if (p_extend->event < WKUPC_W_EVENT_PORT0)
    {
        FSP_ERROR_RETURN(NULL == p_pin_cfg, FSP_ERR_INVALID_ARGUMENT);

        if (NULL != p_cfg->p_callback)
        {
            FSP_ERROR_RETURN(p_cfg->irq >= 0, FSP_ERR_INVALID_ARGUMENT);
            FSP_ERROR_RETURN(BSP_IRQ_DISABLED != p_cfg->ipl, FSP_ERR_INVALID_ARGUMENT);
        }
    }
    else
    {
        FSP_ERROR_RETURN(NULL != p_pin_cfg, FSP_ERR_INVALID_POINTER);
        FSP_ERROR_RETURN(NULL != p_pin_cfg->p_channel, FSP_ERR_INVALID_POINTER);
        FSP_ERROR_RETURN(NULL != p_pin_cfg->p_trigger, FSP_ERR_INVALID_POINTER);

        FSP_ERROR_RETURN(p_cfg->irq >= 0, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(BSP_IRQ_DISABLED != p_cfg->ipl, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(NULL != p_cfg->p_callback, FSP_ERR_INVALID_ARGUMENT);

        FSP_ERROR_RETURN(p_pin_cfg->channel_size > 0, FSP_ERR_INVALID_ARGUMENT);

        if (WKUPC_W_EVENT_KEY == p_extend->event)
        {
            FSP_ERROR_RETURN(p_extend->key_debounce <= WKUPC_W_MAX_KEY_DEBOUNCE_TIME_MS, FSP_ERR_INVALID_ARGUMENT);

            /* If no debouncing is set, all triggers should be EDGE. Otherwise, all triggers should LEVEL.*/
            for (uint32_t idx = 0; idx < p_pin_cfg->channel_size; idx++)
            {
                bool isEdge = p_pin_cfg->p_trigger[idx] & 0x1;

                FSP_ERROR_RETURN(p_extend->key_debounce > 0 ? !isEdge : isEdge, FSP_ERR_INVALID_MODE);
            }
        }
        else
        {
            uint32_t port_idx = p_extend->event - WKUPC_W_EVENT_PORT0;

            for (uint32_t idx = 0; idx < p_pin_cfg->channel_size; idx++)
            {
                FSP_ERROR_RETURN(((p_pin_cfg->p_channel[idx] & BSP_IO_PORT_BITS) >> BSP_IO_PORT_OFFSET) == port_idx,
                                 FSP_ERR_INVALID_MODE);
            }
        }
    }

    return FSP_SUCCESS;
}

#endif
