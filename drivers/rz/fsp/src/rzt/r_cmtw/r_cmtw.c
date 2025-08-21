/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_cmtw.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "CMTW" in ASCII, used to determine if channel is open. */
#define CMTW_OPEN                          (0x434D5457ULL)

/** CMTW register bit offsets */
#define CMTW_PRV_CMWSTR_STOP_TIMER         (0x00U)
#define CMTW_PRV_CMWSTR_START_TIMER        (0x01U)

#define CMTW_PRV_CMWCR_CKS_OFFSET          (0U)
#define CMTW_PRV_CMWCR_CKS_VALUE_MASK      (0x3U)
#define CMTW_PRV_CMWCR_CMWIE_OFFSET        (3U)
#define CMTW_PRV_CMWCR_IC0IE_OFFSET        (4U)
#define CMTW_PRV_CMWCR_IC0IE_VALUE_MASK    (0x01U)
#define CMTW_PRV_CMWCR_IC1IE_OFFSET        (5U)
#define CMTW_PRV_CMWCR_IC1IE_VALUE_MASK    (0x01U)
#define CMTW_PRV_CMWCR_OC0IE_OFFSET        (6U)
#define CMTW_PRV_CMWCR_OC0IE_VALUE_MASK    (0x01U)
#define CMTW_PRV_CMWCR_OC1IE_OFFSET        (7U)
#define CMTW_PRV_CMWCR_OC1IE_VALUE_MASK    (0x01U)
#define CMTW_PRV_CMWCR_CMS_OFFSET          (9U)
#define CMTW_PRV_CMWCR_CMS_VALUE_MASK      (0x01U)
#define CMTW_PRV_CMWCR_CCLR_OFFSET         (13U)
#define CMTW_PRV_CMWCR_CCLR_VALUE_MASK     (0x07U)
#define CMTW_PRV_CMWCR_MASK                (0xFFFFU)

#define CMTW_PRV_CMWIOR_IC0_OFFSET         (0U)
#define CMTW_PRV_CMWIOR_IC0_VALUE_MASK     (0x03U)
#define CMTW_PRV_CMWIOR_IC1_OFFSET         (2U)
#define CMTW_PRV_CMWIOR_IC1_VALUE_MASK     (0x03U)
#define CMTW_PRV_CMWIOR_IC0E_OFFSET        (4U)
#define CMTW_PRV_CMWIOR_IC0E_VALUE_MASK    (1U)
#define CMTW_PRV_CMWIOR_IC1E_OFFSET        (5U)
#define CMTW_PRV_CMWIOR_IC1E_VALUE_MASK    (1U)
#define CMTW_PRV_CMWIOR_OC0_OFFSET         (8U)
#define CMTW_PRV_CMWIOR_OC0_VALUE_MASK     (0x03U)
#define CMTW_PRV_CMWIOR_OC1_OFFSET         (10U)
#define CMTW_PRV_CMWIOR_OC0E_OFFSET        (12U)
#define CMTW_PRV_CMWIOR_OC0E_VALUE_MASK    (1U)
#define CMTW_PRV_CMWIOR_OC1E_OFFSET        (13U)
#define CMTW_PRV_CMWIOR_OC1E_VALUE_MASK    (1U)
#define CMTW_PRV_CMWIOR_OC1_VALUE_MASK     (0x03U)
#define CMTW_PRV_CMWIOR_CMWE_OFFSET        (15U)
#define CMTW_PRV_CMWIOR_MASK               (0xFFFFU)

#define CMTW_PRV_CMWIOR_OC_MASK            (3U)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void     r_cmtw_period_register_set(cmtw_instance_ctrl_t * p_instance_ctrl, uint32_t period_counts);
static void     r_cmtw_hardware_cfg(cmtw_instance_ctrl_t * const p_instance_ctrl, timer_cfg_t const * const p_cfg);
static uint32_t r_cmtw_clock_frequency_get(R_CMTW0_Type * p_cmtw_regs);
static void     r_cmtw_enable_irq(IRQn_Type const irq, uint32_t priority, void * p_context);
static void     r_cmtw_disable_irq(IRQn_Type irq);
static void     r_cmtw_call_callback(cmtw_instance_ctrl_t * p_instance_ctrl, timer_event_t event, uint32_t capture);

#if CMTW_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_cmtw_open_param_checking(cmtw_instance_ctrl_t * p_instance_ctrl, timer_cfg_t const * const p_cfg);

#endif

/* ISRs. */
void cmtw_cm_int_isr(void);
void cmtw_ic0_int_isr(void);
void cmtw_ic1_int_isr(void);
void cmtw_oc0_int_isr(void);
void cmtw_oc1_int_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** CMTW Implementation of General Timer Driver  */
const timer_api_t g_timer_on_cmtw =
{
    .open         = R_CMTW_Open,
    .stop         = R_CMTW_Stop,
    .start        = R_CMTW_Start,
    .reset        = R_CMTW_Reset,
    .enable       = R_CMTW_Enable,
    .disable      = R_CMTW_Disable,
    .periodSet    = R_CMTW_PeriodSet,
    .dutyCycleSet = R_CMTW_DutyCycleSet,
    .infoGet      = R_CMTW_InfoGet,
    .statusGet    = R_CMTW_StatusGet,
    .callbackSet  = R_CMTW_CallbackSet,
    .close        = R_CMTW_Close,
};

/*******************************************************************************************************************//**
 * @addtogroup CMTW
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the CMTW module instance. Implements @ref timer_api_t::open.
 *
 * The CMTW hardware does not support one-shot functionality natively.  The one-shot feature is therefore implemented in
 * the CMTW HAL layer. For a timer configured as a one-shot timer, the timer is stopped upon the first timer expiration.
 *
 * The CMTW implementation of the general timer can accept an optional cmtw_extended_cfg_t extension parameter.
 *
 * @retval FSP_SUCCESS                 Initialization was successful and timer has started.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL or the period is not in the valid range of
 *                                     1 to 0xFFFF in 16bit counter or 1 to 0xFFFFFFFF in 32bit counter.
 * @retval FSP_ERR_ALREADY_OPEN        R_CMTW_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    A required interrupt has not been enabled in the vector table.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Requested channel number is not available on CMTW.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_Open (timer_ctrl_t * const p_ctrl, timer_cfg_t const * const p_cfg)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_cmtw_open_param_checking(p_instance_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    uintptr_t base_address = (uintptr_t) R_CMTW0 + (p_cfg->channel * ((uintptr_t) R_CMTW1 - (uintptr_t) R_CMTW0));
    p_instance_ctrl->p_reg = (R_CMTW0_Type *) base_address;
    p_instance_ctrl->p_cfg = p_cfg;

    /* Power on the CMTW channel. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_CMTW, p_cfg->channel);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Set count source and divider and configure pins. */
    r_cmtw_hardware_cfg(p_instance_ctrl, p_cfg);

    /* Set callback and context pointers */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    p_instance_ctrl->open = CMTW_OPEN;

    /* All done.  */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Starts timer. Implements @ref timer_api_t::start.
 *
 * @retval FSP_SUCCESS                 Timer started.
 * @retval FSP_ERR_ASSERTION           p_ctrl is null.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_Start (timer_ctrl_t * const p_ctrl)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t cmwior = p_instance_ctrl->p_reg->CMWIOR;

    if (0 != p_instance_ctrl->output_channel_mask)
    {
        /* When One-shot operating, change the OCn bit to toggle the output signal at start API. */
        if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
        {
            if (0 != (p_instance_ctrl->output_channel_mask & (1U << CMTW_IO_PIN_TOC0)))
            {
                cmwior ^= CMTW_PRV_CMWIOR_OC_MASK << CMTW_PRV_CMWIOR_OC0_OFFSET;
            }

            if (0 != (p_instance_ctrl->output_channel_mask & (1U << CMTW_IO_PIN_TOC1)))
            {
                cmwior ^= CMTW_PRV_CMWIOR_OC_MASK << CMTW_PRV_CMWIOR_OC1_OFFSET;
            }
        }

        /* When using the output compare function, not use the compare match function. */
        cmwior &= (uint32_t) ~(1 << CMTW_PRV_CMWIOR_CMWE_OFFSET);
    }
    else
    {
        cmwior |= 1 << CMTW_PRV_CMWIOR_CMWE_OFFSET;
    }

    p_instance_ctrl->p_reg->CMWIOR = (uint16_t) cmwior & CMTW_PRV_CMWIOR_MASK;

    /* Start timer */
    p_instance_ctrl->p_reg->CMWSTR = (uint16_t) CMTW_PRV_CMWSTR_START_TIMER;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stops the timer.  Implements @ref timer_api_t::stop.
 *
 * @retval FSP_SUCCESS                 Timer stopped.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_Stop (timer_ctrl_t * const p_ctrl)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Stop timer */
    p_instance_ctrl->p_reg->CMWSTR = (uint16_t) CMTW_PRV_CMWSTR_STOP_TIMER;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Resets the counter value to 0. Implements @ref timer_api_t::reset.
 *
 * @retval FSP_SUCCESS                 Counter reset.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_Reset (timer_ctrl_t * const p_ctrl)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Reset counter. */
    p_instance_ctrl->p_reg->CMWCNT = (uint32_t) 0x00U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enables external event triggers that start, stop, clear, or capture the counter. Implements @ref timer_api_t::enable.
 *
 * @retval FSP_SUCCESS                 External events successfully enabled.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_Enable (timer_ctrl_t * const p_ctrl)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    cmtw_extended_cfg_t * p_extend = (cmtw_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint32_t cmwior = p_instance_ctrl->p_reg->CMWIOR;

    cmwior |= (p_extend->ic0_control & CMTW_PRV_CMWIOR_IC0E_VALUE_MASK) << CMTW_PRV_CMWIOR_IC0E_OFFSET;
    cmwior |= (p_extend->ic1_control & CMTW_PRV_CMWIOR_IC1E_VALUE_MASK) << CMTW_PRV_CMWIOR_IC1E_OFFSET;

    p_instance_ctrl->p_reg->CMWIOR = (uint16_t) cmwior & CMTW_PRV_CMWIOR_MASK;

    /* Start timer */
    p_instance_ctrl->p_reg->CMWSTR = (uint16_t) CMTW_PRV_CMWSTR_START_TIMER;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disables external event triggers that start, stop, clear, or capture the counter. Implements @ref timer_api_t::disable.
 *
 * @retval FSP_SUCCESS                 External events successfully disabled.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_Disable (timer_ctrl_t * const p_ctrl)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t cmwior = p_instance_ctrl->p_reg->CMWIOR;

    cmwior &= (uint32_t) ~(1 << CMTW_PRV_CMWIOR_IC0E_OFFSET);
    cmwior &= (uint32_t) ~(1 << CMTW_PRV_CMWIOR_IC1E_OFFSET);

    p_instance_ctrl->p_reg->CMWIOR = (uint16_t) cmwior & CMTW_PRV_CMWIOR_MASK;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates period. The new period is updated immediately. Implements
 * @ref timer_api_t::periodSet.
 *
 * @warning Stop the timer before calling this function if one-shot output is used.
 *
 * @retval FSP_SUCCESS                 Period value updated.
 * @retval FSP_ERR_ASSERTION           A required pointer was NULL, or the period was not in the valid range of
 *                                     1 to 0xFFFF in 16bit counter or 1 to 0xFFFFFFFF in 32bit counter.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_PeriodSet (timer_ctrl_t * const p_ctrl, uint32_t const period_counts)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    cmtw_extended_cfg_t * p_extend = (cmtw_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Validate period parameter. */
    FSP_ASSERT(0U != period_counts);
    if (p_extend->counter_size == TIMER_VARIANT_16_BIT)
    {
        FSP_ASSERT(period_counts <= CMTW_MAX_PERIOD_16BIT);
    }
#endif

    /* Set period. */
    r_cmtw_period_register_set(p_instance_ctrl, period_counts);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates duty cycle. If the timer is counting, the new duty cycle is reflected after the next counter underflow.
 * Implements @ref timer_api_t::dutyCycleSet.
 *
 * @retval FSP_ERR_UNSUPPORTED         CMTW duty cycle set is not supported.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_DutyCycleSet (timer_ctrl_t * const p_ctrl, uint32_t const duty_cycle_counts, uint32_t const pin)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(duty_cycle_counts);
    FSP_PARAMETER_NOT_USED(pin);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Gets timer information and store it in provided pointer p_info. Implements @ref timer_api_t::infoGet.
 *
 * @retval FSP_SUCCESS                 Period, count direction, and frequency stored in p_info.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_InfoGet (timer_ctrl_t * const p_ctrl, timer_info_t * const p_info)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_info);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Get and store period */
    p_info->period_counts = p_instance_ctrl->period;

    /* Get and store clock frequency */
    p_info->clock_frequency = r_cmtw_clock_frequency_get(p_instance_ctrl->p_reg);

    /* CMTW supports only counting up direction */
    p_info->count_direction = TIMER_DIRECTION_UP;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Retrieves the current state and counter value stores them in p_status. Implements @ref timer_api_t::statusGet.
 *
 * @retval FSP_SUCCESS                 Current status and counter value provided in p_status.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_StatusGet (timer_ctrl_t * const p_ctrl, timer_status_t * const p_status)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Read the state. */
    p_status->state = (timer_state_t) p_instance_ctrl->p_reg->CMWSTR_b.STR;

    /* Read counter value */
    p_status->counter = p_instance_ctrl->p_reg->CMWCNT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable output for TOC0 and/or TOC1.
 *
 * @retval FSP_SUCCESS                 Output is enabled.
 * @retval FSP_ERR_ASSERTION           p_ctrl or p_status was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_OutputEnable (timer_ctrl_t * const p_ctrl, cmtw_io_pin_t pin)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;
    fsp_err_t              err             = FSP_SUCCESS;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t cmwior = p_instance_ctrl->p_reg->CMWIOR;

    if ((CMTW_IO_PIN_TOC0 == pin) || (CMTW_IO_PIN_TOC0_AND_TOC1 == pin))
    {
        cmwior |= 1 << CMTW_PRV_CMWIOR_OC0E_OFFSET;
        p_instance_ctrl->output_channel_mask |= (uint32_t) (1 << CMTW_IO_PIN_TOC0);
    }

    if ((CMTW_IO_PIN_TOC1 == pin) || (CMTW_IO_PIN_TOC0_AND_TOC1 == pin))
    {
        cmwior |= 1 << CMTW_PRV_CMWIOR_OC1E_OFFSET;
        p_instance_ctrl->output_channel_mask |= (uint32_t) (1 << CMTW_IO_PIN_TOC1);
    }

    p_instance_ctrl->p_reg->CMWIOR = (uint16_t) cmwior & CMTW_PRV_CMWIOR_MASK;

    return err;
}

/*******************************************************************************************************************//**
 * Disable output for TOC0 and/or TOC1.
 *
 * @retval FSP_SUCCESS                 Output is disabled.
 * @retval FSP_ERR_ASSERTION           p_ctrl or p_status was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_OutputDisable (timer_ctrl_t * const p_ctrl, cmtw_io_pin_t pin)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;
    fsp_err_t              err             = FSP_SUCCESS;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t cmwior = p_instance_ctrl->p_reg->CMWIOR;

    if ((CMTW_IO_PIN_TOC0 == pin) || (CMTW_IO_PIN_TOC0_AND_TOC1 == pin))
    {
        cmwior &= (uint32_t) ~(1 << CMTW_PRV_CMWIOR_OC0E_OFFSET);
        p_instance_ctrl->output_channel_mask &= (uint32_t) ~(1 << CMTW_IO_PIN_TOC0);
    }

    if ((CMTW_IO_PIN_TOC1 == pin) || (CMTW_IO_PIN_TOC0_AND_TOC1 == pin))
    {
        cmwior &= (uint32_t) ~(1 << CMTW_PRV_CMWIOR_OC1E_OFFSET);
        p_instance_ctrl->output_channel_mask &= (uint32_t) ~(1 << CMTW_IO_PIN_TOC1);
    }

    p_instance_ctrl->p_reg->CMWIOR = (uint16_t) cmwior & CMTW_PRV_CMWIOR_MASK;

    return err;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref timer_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_CallbackSet (timer_ctrl_t * const          p_ctrl,
                              void (                      * p_callback)(timer_callback_args_t *),
                              void const * const            p_context,
                              timer_callback_args_t * const p_callback_memory)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stops counter, disables interrupts, disables output pins, and clears internal driver data.  Implements
 * @ref timer_api_t::close.
 *
 *
 *
 * @retval FSP_SUCCESS                 Timer closed.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_CMTW_Close (timer_ctrl_t * const p_ctrl)
{
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) p_ctrl;

#if CMTW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CMTW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    timer_cfg_t         * p_cfg    = (timer_cfg_t *) p_instance_ctrl->p_cfg;
    cmtw_extended_cfg_t * p_extend = (cmtw_extended_cfg_t *) p_cfg->p_extend;

    /* Stop timer */
    p_instance_ctrl->p_reg->CMWSTR = CMTW_PRV_CMWSTR_STOP_TIMER;

    /* Disable interrupts. */
    r_cmtw_disable_irq(p_cfg->cycle_end_irq);
    r_cmtw_disable_irq(p_extend->capture_ic0_irq);
    r_cmtw_disable_irq(p_extend->capture_ic1_irq);
    r_cmtw_disable_irq(p_extend->compare_oc0_irq);
    r_cmtw_disable_irq(p_extend->compare_oc1_irq);

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_CMTW, p_cfg->channel);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/** @} (end addtogroup CMTW) */

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if CMTW_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking for R_CMTW_Open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 * @param[in]  p_cfg              Configuration structure for this instance
 *
 * @retval FSP_SUCCESS                 Initialization was successful and timer has started.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL or the period is not in the valid range of
 *                                     1 to 0xFFFF in 16bit counter or 1 to 0xFFFFFFFF in 32bit counter.
 * @retval FSP_ERR_ALREADY_OPEN        R_CMTW_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    A required interrupt has not been enabled in the vector table.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Requested channel number is not available on CMTW.
 **********************************************************************************************************************/
static fsp_err_t r_cmtw_open_param_checking (cmtw_instance_ctrl_t * p_instance_ctrl, timer_cfg_t const * const p_cfg)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(CMTW_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    cmtw_extended_cfg_t * p_extend = (cmtw_extended_cfg_t *) p_cfg->p_extend;

    /* Enable IRQ if user supplied a callback function,
     *  or if the timer is a one-shot timer (so the driver is able to
     *  turn off the timer after one period. */
    if ((NULL != p_cfg->p_callback) || (TIMER_MODE_ONE_SHOT == p_cfg->mode))
    {
        if (CMTW_OUTPUT_CONTROL_ENABLED == p_extend->toc0_control)
        {
            /* Return error if IRQ is required and not in the vector table. */
            FSP_ERROR_RETURN(p_extend->compare_oc0_irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
        }

        if (CMTW_OUTPUT_CONTROL_ENABLED == p_extend->toc1_control)
        {
            /* Return error if IRQ is required and not in the vector table. */
            FSP_ERROR_RETURN(p_extend->compare_oc1_irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
        }

        if ((CMTW_OUTPUT_CONTROL_DISABLED == p_extend->toc0_control) &&
            (CMTW_OUTPUT_CONTROL_DISABLED == p_extend->toc1_control) &&
            (CMTW_INPUT_CONTROL_DISABLED == p_extend->ic0_control) &&
            (CMTW_INPUT_CONTROL_DISABLED == p_extend->ic1_control))
        {
            FSP_ERROR_RETURN(p_cfg->cycle_end_irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
        }
    }

    FSP_ASSERT(0U != p_cfg->period_counts);

    /* Validate period parameter. */
    if (p_extend->counter_size == TIMER_VARIANT_16_BIT)
    {
        FSP_ASSERT(p_cfg->period_counts <= CMTW_MAX_PERIOD_16BIT);
    }

    /* Validate channel number. */
    FSP_ERROR_RETURN(((1U << p_cfg->channel) & BSP_FEATURE_CMTW_VALID_CHANNEL_MASK), FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    /* Allowed dividers for PCLKL are 8, 32, 128, and 512. */
    FSP_ASSERT(p_cfg->source_div <= TIMER_SOURCE_DIV_512);
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_1);
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_2);
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_4);
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_16);
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_64);
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_256);

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * Sets count source and divider.
 *
 * @note Counter must be stopped before entering this function.
 *
 * @param[in]  p_instance_ctrl    Control block for this instance
 * @param[in]  p_cfg              Configuration structure for this instance
 **********************************************************************************************************************/
static void r_cmtw_hardware_cfg (cmtw_instance_ctrl_t * const p_instance_ctrl, timer_cfg_t const * const p_cfg)
{
    cmtw_extended_cfg_t const * p_extend = (cmtw_extended_cfg_t const *) p_cfg->p_extend;

    /* For setting CMRCR.CKS, use formula (source_div - 3) / 2
     * TIMER_SOURCE_DIV_8   = 3 -> CMRCR.CKS = 0 (8 division)
     * TIMER_SOURCE_DIV_32  = 5 -> CMRCR.CKS = 1 (32 division)
     * TIMER_SOURCE_DIV_128 = 7 -> CMRCR.CKS = 2 (128 division)
     * TIMER_SOURCE_DIV_512 = 9 -> CMRCR.CKS = 3 (512 division) */
    uint32_t cmwcr = ((((p_cfg->source_div & 0x0FU) - 3) >> 1U) & CMTW_PRV_CMWCR_CKS_VALUE_MASK) <<
                     CMTW_PRV_CMWCR_CKS_OFFSET |
                     (p_extend->counter_size & CMTW_PRV_CMWCR_CMS_VALUE_MASK) << CMTW_PRV_CMWCR_CMS_OFFSET |
                     (p_extend->clear_source & CMTW_PRV_CMWCR_CCLR_VALUE_MASK) << CMTW_PRV_CMWCR_CCLR_OFFSET;

    uint32_t cmwior = 0x00000000;

    /* Each interrupt enable. */
    cmwcr |= (1U << CMTW_PRV_CMWCR_CMWIE_OFFSET) | (1U << CMTW_PRV_CMWCR_IC0IE_OFFSET) |
             (1U << CMTW_PRV_CMWCR_IC1IE_OFFSET) | (1U << CMTW_PRV_CMWCR_OC0IE_OFFSET) |
             (1U << CMTW_PRV_CMWCR_OC1IE_OFFSET);

    /* Set output if requested */
    cmwior |=
        ((p_extend->toc0 & CMTW_PRV_CMWIOR_OC0_VALUE_MASK) << CMTW_PRV_CMWIOR_OC0_OFFSET) |
        ((p_extend->toc1 & CMTW_PRV_CMWIOR_OC1_VALUE_MASK) << CMTW_PRV_CMWIOR_OC1_OFFSET);

    cmwior |=
        ((p_extend->toc0_control & CMTW_PRV_CMWIOR_OC0E_VALUE_MASK) << CMTW_PRV_CMWIOR_OC0E_OFFSET) |
        ((p_extend->toc1_control & CMTW_PRV_CMWIOR_OC1E_VALUE_MASK) << CMTW_PRV_CMWIOR_OC1E_OFFSET);

    /* Track current output enable pin. */
    p_instance_ctrl->output_channel_mask =
        (uint32_t) ((p_extend->toc0_control << CMTW_IO_PIN_TOC0) | (p_extend->toc1_control << CMTW_IO_PIN_TOC1));

    r_cmtw_enable_irq(p_extend->compare_oc0_irq, p_extend->compare_oc0_ipl, p_instance_ctrl);
    r_cmtw_enable_irq(p_extend->compare_oc1_irq, p_extend->compare_oc1_ipl, p_instance_ctrl);

    /* Set input capture if requested */
    cmwior |=
        ((p_extend->capture_ic0_source & CMTW_PRV_CMWIOR_IC0_VALUE_MASK) << CMTW_PRV_CMWIOR_IC0_OFFSET) |
        ((p_extend->capture_ic1_source & CMTW_PRV_CMWIOR_IC1_VALUE_MASK) << CMTW_PRV_CMWIOR_IC1_OFFSET);

    cmwior |=
        ((p_extend->ic0_control & CMTW_PRV_CMWIOR_IC0E_VALUE_MASK) << CMTW_PRV_CMWIOR_IC0E_OFFSET) |
        ((p_extend->ic1_control & CMTW_PRV_CMWIOR_IC1E_VALUE_MASK) << CMTW_PRV_CMWIOR_IC1E_OFFSET);

    r_cmtw_enable_irq(p_extend->capture_ic0_irq, p_extend->capture_ic0_ipl, p_instance_ctrl);
    r_cmtw_enable_irq(p_extend->capture_ic1_irq, p_extend->capture_ic1_ipl, p_instance_ctrl);

    /* Set period register and update duty cycle if output mode is used for one-shot or periodic mode. */
    r_cmtw_period_register_set(p_instance_ctrl, p_cfg->period_counts);

    r_cmtw_enable_irq(p_cfg->cycle_end_irq, p_cfg->cycle_end_ipl, p_instance_ctrl);

    p_instance_ctrl->p_reg->CMWIOR = (uint16_t) cmwior & CMTW_PRV_CMWIOR_MASK;
    p_instance_ctrl->p_reg->CMWCR  = (uint16_t) cmwcr & CMTW_PRV_CMWCR_MASK;

    /* Reset counter. */
    p_instance_ctrl->p_reg->CMWCNT = (uint32_t) 0x00000000U;
}

/*******************************************************************************************************************//**
 * Sets period register and updates compare match registers in one-shot and periodic mode.
 *
 * @param[in]  p_instance_ctrl    Control block for this instance
 * @param[in]  period_counts      CMTW period in counts
 **********************************************************************************************************************/
static void r_cmtw_period_register_set (cmtw_instance_ctrl_t * p_instance_ctrl, uint32_t period_counts)
{
    cmtw_extended_cfg_t * p_extend = (cmtw_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Store the period value so it can be retrieved later. */
    p_instance_ctrl->period = period_counts;

    uint32_t period_reg = (uint32_t) (period_counts - 1U);

    if ((CMTW_OUTPUT_CONTROL_ENABLED == p_extend->toc0_control) ||
        (CMTW_OUTPUT_CONTROL_ENABLED == p_extend->toc1_control))
    {
        uint32_t duty_cycle_counts = 0U;

        if (TIMER_MODE_PERIODIC == p_instance_ctrl->p_cfg->mode)
        {
            duty_cycle_counts = (period_counts >> 1);
        }
        else if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
        {
            duty_cycle_counts = period_reg;
        }
        else
        {
            /* Do nothing */
        }

        if (CMTW_OUTPUT_CONTROL_DISABLED != p_extend->toc0_control)
        {
            p_instance_ctrl->p_reg->CMWOCR0 = duty_cycle_counts;
        }

        if (CMTW_OUTPUT_CONTROL_DISABLED != p_extend->toc1_control)
        {
            p_instance_ctrl->p_reg->CMWOCR1 = duty_cycle_counts;
        }
    }

    p_instance_ctrl->p_reg->CMWCOR = period_reg;
}

/*******************************************************************************************************************//**
 * Obtains the clock frequency of CMTW for all clock sources with divisor applied.
 *
 * @param[in]  p_cmtw_regs         Registers of CMTW channel used
 *
 * @return Source clock frequency of CMTW in Hz, divider applied.
 **********************************************************************************************************************/
static uint32_t r_cmtw_clock_frequency_get (R_CMTW0_Type * p_cmtw_regs)
{
    uint32_t           clock_freq_hz = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_PCLKL);
    timer_source_div_t divider       = (timer_source_div_t) ((p_cmtw_regs->CMWCR_b.CKS * 2) + 3);

    clock_freq_hz >>= divider;

    return clock_freq_hz;
}

/*******************************************************************************************************************//**
 * Disables interrupt if it is a valid vector number.
 *
 * @param[in]  irq                     Interrupt number
 **********************************************************************************************************************/
static void r_cmtw_disable_irq (IRQn_Type irq)
{
    /* Disable interrupts. */
    if (irq >= 0)
    {
        R_BSP_IrqDisable(irq);
        R_FSP_IsrContextSet(irq, NULL);
    }
}

/*******************************************************************************************************************//**
 * Configures and enables interrupt if it is a valid vector number.
 *
 * @param[in]  irq                     Interrupt number
 * @param[in]  priority                Interrupt controller priority of the interrupt
 * @param[in]  p_context               The interrupt context is a pointer to data required in the ISR.
 **********************************************************************************************************************/
static void r_cmtw_enable_irq (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    if (irq >= 0)
    {
        R_BSP_IrqCfgEnable(irq, priority, p_context);
    }
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_instance_ctrl     Pointer to CMTW instance control block
 * @param[in]     event               Event code
 * @param[in]     capture             Event capture counts (if applicable)
 **********************************************************************************************************************/
static void r_cmtw_call_callback (cmtw_instance_ctrl_t * p_instance_ctrl, timer_event_t event, uint32_t capture)
{
    timer_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    timer_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
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

    p_args->event     = event;
    p_args->capture   = capture;
    p_args->p_context = p_instance_ctrl->p_context;

    p_instance_ctrl->p_callback(p_args);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

void cmtw_cm_int_isr (void)
{
    CMTW_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
    {
        /* Stop timer */
        p_instance_ctrl->p_reg->CMWSTR = (uint16_t) CMTW_PRV_CMWSTR_STOP_TIMER;

        /* Reset counter. */
        p_instance_ctrl->p_reg->CMWCNT = (uint32_t) 0x00U;
    }

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_cmtw_call_callback(p_instance_ctrl, TIMER_EVENT_CYCLE_END, 0);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE

        CMTW_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

void cmtw_ic0_int_isr (void)
{
    CMTW_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
    {
        /* Stop timer */
        p_instance_ctrl->p_reg->CMWSTR = (uint16_t) CMTW_PRV_CMWSTR_STOP_TIMER;

        /* Reset counter. */
        p_instance_ctrl->p_reg->CMWCNT = (uint32_t) 0x00U;
    }

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        uint32_t counter = p_instance_ctrl->p_reg->CMWICR0;
        r_cmtw_call_callback(p_instance_ctrl, TIMER_EVENT_CAPTURE_A, counter);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE

        CMTW_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

void cmtw_ic1_int_isr (void)
{
    CMTW_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
    {
        /* Stop timer */
        p_instance_ctrl->p_reg->CMWSTR = (uint16_t) CMTW_PRV_CMWSTR_STOP_TIMER;

        /* Reset counter. */
        p_instance_ctrl->p_reg->CMWCNT = (uint32_t) 0x00U;
    }

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        uint32_t counter = p_instance_ctrl->p_reg->CMWICR1;
        r_cmtw_call_callback(p_instance_ctrl, TIMER_EVENT_CAPTURE_B, counter);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE

        CMTW_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

void cmtw_oc0_int_isr (void)
{
    CMTW_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
    {
        /* Stop timer */
        p_instance_ctrl->p_reg->CMWSTR = (uint16_t) CMTW_PRV_CMWSTR_STOP_TIMER;

        /* Reset counter. */
        p_instance_ctrl->p_reg->CMWCNT = (uint32_t) 0x00U;

        /* Reconfigure the settings changed in the Start API. */
        cmtw_extended_cfg_t * p_extend = (cmtw_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
        p_instance_ctrl->p_reg->CMWIOR_b.OC0 = p_extend->toc0;
    }

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_cmtw_call_callback(p_instance_ctrl, TIMER_EVENT_COMPARE_A, 0);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE

        CMTW_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

void cmtw_oc1_int_isr (void)
{
    CMTW_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    cmtw_instance_ctrl_t * p_instance_ctrl = (cmtw_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Disable if repeat not requested e.g. one-shot */
    if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
    {
        /* Stop timer */
        p_instance_ctrl->p_reg->CMWSTR = (uint16_t) CMTW_PRV_CMWSTR_STOP_TIMER;

        /* Reset counter. */
        p_instance_ctrl->p_reg->CMWCNT = (uint32_t) 0x00U;

        /* Reconfigure the settings changed in the Start API. */
        cmtw_extended_cfg_t * p_extend = (cmtw_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
        p_instance_ctrl->p_reg->CMWIOR_b.OC1 = p_extend->toc1;
    }

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_cmtw_call_callback(p_instance_ctrl, TIMER_EVENT_COMPARE_B, 0);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE

        CMTW_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
