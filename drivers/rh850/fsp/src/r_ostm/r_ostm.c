/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_ostm.h"                    /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "OSTM" in ASCII, used to determine if channel is open. */
#define OSTM_OPEN              (0x4F53544DU)

#if (BSP_FEATURE_OSTM_SIMPLE_CHANNEL_LAYOUT_AVAILABLE == 1U)
#elif (BSP_FEATURE_OSTM_EXTENDED_CHANNEL_LAYOUT_AVAILABLE == 1U)
 #define OSTM_REG              (R_OSTM2_BASE - R_OSTM0_BASE)
#else
 #define OSTM_REG              (R_OSTM3_BASE - R_OSTM1_BASE)
#endif

#if (BSP_FEATURE_OSTM_EXTENDED_CHANNEL_LAYOUT_AVAILABLE == 1U)
 #define OSTM_GROUP_GAP        (R_OSTM1_BASE - R_OSTM0_BASE)
 #define OSTM_GROUP_GAP_CLK    (R_IC0CKSEL9_BASE - R_IC0CKSEL8_BASE)
#else
 #define OSTM_GROUP_GAP        (R_OSTM0_BASE - R_OSTM1_BASE)
#endif

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_ostm_period_register_set(ostm_instance_ctrl_t * p_instance_ctrl, uint32_t period_counts);

static uint32_t r_ostm_clock_frequency_get(void);

#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
static fsp_err_t r_ostm_open_param_checking(ostm_instance_ctrl_t * p_instance_ctrl, timer_cfg_t const * const p_cfg);

#endif

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/
BSP_INTERRUPT_ATTRIBUTE void ostm_int_isr(void); /* PRQA S 3449, 3451 # DP_MSR_R-8.5_UC1 */

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** OSTM Implementation of General Timer Driver  */
const timer_api_t g_timer_on_ostm =    /* PRQA S 1502 # Advisory R-2.8 */
{
    .open         = R_OSTM_Open,       /* PRQA S 3635 EOF # Advisory R-17.12 */
    .start        = R_OSTM_Start,
    .stop         = R_OSTM_Stop,
    .reset        = R_OSTM_Reset,
    .enable       = R_OSTM_Enable,
    .disable      = R_OSTM_Disable,
    .periodSet    = R_OSTM_PeriodSet,
    .dutyCycleSet = R_OSTM_DutyCycleSet,
    .infoGet      = R_OSTM_InfoGet,
    .statusGet    = R_OSTM_StatusGet,
    .callbackSet  = R_OSTM_CallbackSet,
    .close        = R_OSTM_Close
};

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup OSTM
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief Initializes the OSTM module instance.
 * Implements @ref timer_api_t::open.
 *
 * The OSTM hardware does not support one-shot functionality natively. The one-shot feature is therefore implemented in
 * the OSTM HAL layer. For a timer configured as a one-shot timer, the timer is stopped upon the first timer expiration.
 * The OSTM implementation of the general timer can accept an optional ostm_extended_cfg_t extension parameter. For
 * OSTM, the extension specifies the clock to be used as timer source and the output pin configurations. If the
 * extension parameter is not specified NULL, the default clock PCLK0 is used and the output pins are disabled.
 *
 * @retval FSP_SUCCESS                 Initialization was successful and timer has started.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL or the period is not in the valid range of
 *                                     1 to 0xFFFFFFFF.
 * @retval FSP_ERR_ALREADY_OPEN        R_OSTM_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    A required interrupt has not been enabled in the vector table.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Requested channel number is not available on OSTM.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_Open (timer_ctrl_t * const p_ctrl, timer_cfg_t const * const p_cfg) /* PRQA S 1505 EOF # Advisory R-8.7 */
{
    ostm_instance_ctrl_t * p_instance_ctrl = (ostm_instance_ctrl_t *) p_ctrl;        /* PRQA S 0316 EOF # Advisory R-11.5 */

    /* Set counter mode (OSTMnMD) */
    uint32_t ostmnmd = 0;
    const ostm_extended_cfg_t * p_ext;

#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
    FSP_ASSERT(NULL != p_instance_ctrl); /* PRQA S 3432 EOF # DP_MSR_R-20.7_UC1 */
    fsp_err_t err = r_ostm_open_param_checking(p_instance_ctrl, p_cfg);
    FSP_ERROR_RETURN((FSP_SUCCESS == err), err);
#endif

    p_ext = (const ostm_extended_cfg_t *) p_cfg->p_extend;

#if (BSP_FEATURE_OSTM_SIMPLE_CHANNEL_LAYOUT_AVAILABLE == 1U)
    p_instance_ctrl->p_reg = (R_OSTMn_Type *) (R_OSTM1_BASE +
                                               OSTM_GROUP_GAP * (((uint32_t) p_cfg->channel + 1U) % 2U));
#elif (BSP_FEATURE_OSTM_EXTENDED_CHANNEL_LAYOUT_AVAILABLE == 1U)

    /* calculate base address for specified channel */
    p_instance_ctrl->p_reg = (R_OSTMn_Type *) (R_OSTM0_BASE + /* PRQA S 0306, 3395 EOF # Advisory R-11.4, Advisory R-12.1 */
                                               OSTM_REG * ((uint32_t) p_cfg->channel / 2U) +
                                               OSTM_GROUP_GAP * ((uint32_t) p_cfg->channel % 2U));

    if (((p_cfg->channel) == 8U) || ((p_cfg->channel) == 9U))
    {
        /* calculate base address for specified channel */
        p_instance_ctrl->p_reg_cksel =
            (R_IC0CKSELn_Type *) (R_IC0CKSEL8_BASE +
                                  OSTM_GROUP_GAP_CLK * ((uint32_t) p_cfg->channel / 9U));
    }

#else
    if ((p_cfg->channel) <= 1U)
    {
        p_instance_ctrl->p_reg = (R_OSTMn_Type *) (R_OSTM1_BASE +
                                                   OSTM_GROUP_GAP * (((uint32_t) p_cfg->channel + 1U) % 2U));
    }
    else
    {
        /* calculate base address for specified channel */
        p_instance_ctrl->p_reg = (R_OSTMn_Type *) (R_OSTM1_BASE +
                                                   OSTM_REG * ((uint32_t) p_cfg->channel / 2U) +
                                                   OSTM_GROUP_GAP * (((uint32_t) p_cfg->channel + 1U) % 2U));
    }
#endif

    p_instance_ctrl->p_cfg = p_cfg;

    /* Forcibly stop timer. */
    p_instance_ctrl->p_reg->OSTMnTT = 1; /* PRQA S 0662 EOF # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Set period register */
    r_ostm_period_register_set(p_instance_ctrl, p_cfg->period_counts);

    if (OSTM_GIWS_TYPE_ENABLED == p_ext->generate_interrupt_when_starts)
    {
        ostmnmd |= R_OSTMn_OSTMnCTL_OSTMnMD0_Msk;
    }

    if (OSTM_TIMER_MODE_FREERUN == p_ext->ostm_mode)
    {
        ostmnmd |= R_OSTMn_OSTMnCTL_OSTMnMD1_Msk;
    }

    if (OSTM_COUNTER_START_RELOAD_DISABLE == p_ext->counter_load_at_start)
    {
        ostmnmd |= R_OSTMn_OSTMnCTL_OSTMnMD2_Msk;
    }

    /* Enable OSTM Interrupt */
    ostmnmd |= R_OSTMn_OSTMnCTL_OSTMnIE_Msk;

    p_instance_ctrl->p_reg->OSTMnCTL = (uint8_t) ostmnmd;

    p_instance_ctrl->p_reg->OSTMnTOE = (uint8_t) p_ext->output_setting;

    R_BSP_IrqCfgEnable(p_cfg->cycle_end_irq, p_cfg->cycle_end_ipl, p_instance_ctrl);

#if (1U == BSP_FEATURE_OSTM_EXTENDED_CHANNEL_LAYOUT_AVAILABLE)
    if (((p_cfg->channel) == 8U) || ((p_cfg->channel) == 9U))
    {
        /* Clock Select (OSTMncksel) */
        uint32_t OSTMncksel = 0;

        /* Selects the counter-clock-enable signal for OSTM8 or OSTM9. */
        OSTMncksel |= (((uint32_t) p_ext->enable_signal) << ((uint32_t) R_IC0CKSELn_IC0CKSELn_IC0TMENn_Pos));

        /* Select the counter-clock-enable signal for the OSTM8 or OSTM9 counter (Enabled only when IC0TMEN8 = 1). */
        OSTMncksel |= (((uint32_t) p_ext->select_clock) << ((uint32_t) R_IC0CKSELn_IC0CKSELn_IC0TMSELn_Pos));

        /* Select the counter-clock-enable signal for the OSTM8 or OSTM9 counter (Enabled only
         * when IC0TMEN8 = 1 and IC0TMSEL8[1:0] = 11B). */
        OSTMncksel |= (((uint32_t) p_ext->clock_tauj1_channel) << ((uint32_t) R_IC0CKSELn_IC0CKSELn_IC0CKSELn3_Pos));

        /* Select the counter-clock-enable signal for the OSTM8 or OSTM9 counter (Enabled only
         * when IC0TMEN8 = 1 and IC0TMSEL8[1:0] = 10B). */
        OSTMncksel |= (((uint32_t) p_ext->clock_tauj0_channel) << ((uint32_t) R_IC0CKSELn_IC0CKSELn_IC0CKSELn2_Pos));

        /* Select the counter-clock-enable signal for the OSTM8 or OSTM9 counter (Enabled only
         * when IC0TMEN8 = 1 and IC0TMSEL8[1:0] = 01B). */
        OSTMncksel |= (((uint32_t) p_ext->clock_taud1_channel) << ((uint32_t) R_IC0CKSELn_IC0CKSELn_IC0CKSELn1_Pos));

        /* Select the counter-clock-enable signal for the OSTM8 or OSTM9 counter (Enabled only
         * when IC0TMEN8 = 1 and IC0TMSEL8[1:0] = 00B). */
        OSTMncksel |= (((uint32_t) p_ext->clock_taud0_channel) << ((uint32_t) R_IC0CKSELn_IC0CKSELn_IC0CKSELn0_Pos));

        p_instance_ctrl->p_reg_cksel->IC0CKSELn = (uint16_t) OSTMncksel;
    }
#endif

    /* Set callback and context pointers */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    p_instance_ctrl->open = OSTM_OPEN;

    /* All done.  */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Starts timer.
 * Implements @ref timer_api_t::start.
 *
 * @retval FSP_SUCCESS                 Timer started.
 * @retval FSP_ERR_ASSERTION           p_ctrl is null.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_Start (timer_ctrl_t * const p_ctrl)                          /* PRQA S 3673 EOF # Rule-8.13 */
{
    ostm_instance_ctrl_t * p_instance_ctrl = (ostm_instance_ctrl_t *) p_ctrl; /* PRQA S 3678 EOF # Rule-8.13 */
#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN((OSTM_OPEN == (p_instance_ctrl->open)), FSP_ERR_NOT_OPEN);
#endif

    /* Start timer */
    p_instance_ctrl->p_reg->OSTMnTS = 1;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Stops the timer.
 * Implements @ref timer_api_t::stop.
 *
 * @retval FSP_SUCCESS                 Timer stopped.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_Stop (timer_ctrl_t * const p_ctrl)
{
    ostm_instance_ctrl_t * p_instance_ctrl = (ostm_instance_ctrl_t *) p_ctrl;
#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN((OSTM_OPEN == (p_instance_ctrl->open)), FSP_ERR_NOT_OPEN);
#endif

    /* Stop timer */
    p_instance_ctrl->p_reg->OSTMnTT = 1;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Updates period. The new period is updated immediately and the counter is reset to the maximum value.
 * Implements @ref timer_api_t::periodSet.
 *
 * @warning If periodic output is used, the duty cycle buffer registers are updated after the period buffer register.
 * If this function is called while the timer is running and an OSTM underflow occurs during processing, the duty cycle
 * will not be the desired 50% duty cycle until the counter underflow after processing completes.
 *
 * @warning Stop the timer before calling this function if one-shot output is used.
 *
 * @retval FSP_SUCCESS                 Period value updated.
 * @retval FSP_ERR_ASSERTION           A required pointer was NULL, or the period was not in the valid range of
 *                                     1 to 0xFFFFFFFF.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_PeriodSet (timer_ctrl_t * const p_ctrl, uint32_t const period_counts)
{
    ostm_instance_ctrl_t * p_instance_ctrl = (ostm_instance_ctrl_t *) p_ctrl;
#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)

    /* Validate period parameter. */
    FSP_ASSERT(0U != period_counts);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != (p_instance_ctrl->p_cfg));
    FSP_ASSERT(NULL != (p_instance_ctrl->p_cfg->p_extend));
    FSP_ERROR_RETURN((OSTM_OPEN == (p_instance_ctrl->open)), FSP_ERR_NOT_OPEN);
#endif

    /* Set period. */
    r_ostm_period_register_set(p_instance_ctrl, period_counts);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Gets timer information and store it in provided pointer p_info.
 * Implements @ref timer_api_t::infoGet.
 *
 * @retval FSP_SUCCESS                 Period, count direction, and frequency stored in p_info.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_InfoGet (timer_ctrl_t * const p_ctrl, timer_info_t * const p_info)
{
    ostm_instance_ctrl_t * p_instance_ctrl = (ostm_instance_ctrl_t *) p_ctrl;
#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
    FSP_ASSERT(NULL != p_info);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN((OSTM_OPEN == (p_instance_ctrl->open)), FSP_ERR_NOT_OPEN);
#endif

    /* Get and store period */
    p_info->period_counts = p_instance_ctrl->period;

    /* Get and store clock frequency */
    p_info->clock_frequency = r_ostm_clock_frequency_get();

    /* OSTM counting direction */
    p_info->count_direction =
        (0U != (p_instance_ctrl->p_reg->OSTMnCTL & R_OSTMn_OSTMnCTL_OSTMnMD1_Msk)) ?
        TIMER_DIRECTION_UP : TIMER_DIRECTION_DOWN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Retrieves the current state and counter value stores them in p_status.
 * Implements @ref timer_api_t::statusGet.
 *
 * @retval FSP_SUCCESS                 Current status and counter value provided in p_status.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_StatusGet (timer_ctrl_t * const p_ctrl, timer_status_t * const p_status)
{
    ostm_instance_ctrl_t * p_instance_ctrl = (ostm_instance_ctrl_t *) p_ctrl;

#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
    FSP_ASSERT(NULL != p_status);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN((OSTM_OPEN == (p_instance_ctrl->open)), FSP_ERR_NOT_OPEN);
#endif

    /* Read the state. */
    p_status->state = (0U != p_instance_ctrl->p_reg->OSTMnTE_b.OSTMnTE) ?
                      TIMER_STATE_COUNTING : TIMER_STATE_STOPPED;

    /* Read counter value */
    p_status->counter = p_instance_ctrl->p_reg->OSTMnCNT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref timer_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_CallbackSet (timer_ctrl_t * const          p_api_ctrl,
                              void (                      * p_callback)(timer_callback_args_t * p_args),
                              void * const                  p_context,
                              timer_callback_args_t * const p_callback_memory)
{
    ostm_instance_ctrl_t * p_ctrl = (ostm_instance_ctrl_t *) p_api_ctrl;

#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_callback);
    FSP_ERROR_RETURN((OSTM_OPEN == (p_ctrl->open)), FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */

    p_ctrl->p_callback = p_callback;

    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Stops counter, disables interrupts, disables output pins, and clears internal driver data.
 * Implements @ref timer_api_t::close.
 *
 * @retval FSP_SUCCESS                 Timer closed.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_Close (timer_ctrl_t * const p_ctrl)
{
    ostm_instance_ctrl_t * p_instance_ctrl = (ostm_instance_ctrl_t *) p_ctrl;
#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN((OSTM_OPEN == (p_instance_ctrl->open)), FSP_ERR_NOT_OPEN);
#endif

    /* Cleanup the device: Stop counter, disable interrupts, and power down if no other channels are in use. */

    /* Stop timer */
    p_instance_ctrl->p_reg->OSTMnTT            = 1U;
    p_instance_ctrl->p_reg->OSTMnCTL_b.OSTMnIE = 0U;
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->cycle_end_irq);

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Duty Cycle Set.
 * @ref timer_api_t::R_OSTM_DutyCycleSet is not supported on the U2x.
 *
 * @retval FSP_ERR_UNSUPPORTED            Function not supported in this implemention.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_DutyCycleSet (timer_ctrl_t * const p_ctrl, uint32_t const duty_cycle_counts, uint32_t const pin)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(duty_cycle_counts);
    FSP_PARAMETER_NOT_USED(pin);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @brief Reset OSTM Counter Register.
 * Implements @ref timer_api_t::reset.
 *
 * @retval FSP_SUCCESS                 Timer reset.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_Reset (timer_ctrl_t * const p_ctrl)
{
    ostm_instance_ctrl_t * p_instance_ctrl = (ostm_instance_ctrl_t *) p_ctrl;
#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN((OSTM_OPEN == (p_instance_ctrl->open)), FSP_ERR_NOT_OPEN);
#endif

    /* Reset timer counter with current period */
    r_ostm_period_register_set(p_instance_ctrl, p_instance_ctrl->period);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief OSTM Enable.
 * @ref timer_api_t::R_OSTM_Enable is not supported on the U2x.
 *
 * @retval FSP_ERR_UNSUPPORTED            Function not supported in this implemention.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_Enable (timer_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @brief OSTM Disable.
 * @ref timer_api_t::R_OSTM_Disable is not supported on the U2x.
 *
 * @retval FSP_ERR_UNSUPPORTED            Function not supported in this implemention.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_Disable (timer_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @brief OSTM Output Control Low/High Level, Only available for OSTM0 in software control mode
 *
 * @retval FSP_SUCCESS                 Output level set success.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 * @retval FSP_ERR_INVALID_CHANNEL     Only Available for OSTM0.
 * @retval FSP_ERR_INVALID_MODE        Current Mode is not Software Control.
 **********************************************************************************************************************/
fsp_err_t R_OSTM_OutputControl (timer_ctrl_t * const p_ctrl, ostm_output_level_t output_level) /* PRQA S 1503 # Rule-2.1 */
{
    ostm_instance_ctrl_t * p_instance_ctrl = (ostm_instance_ctrl_t *) p_ctrl;
#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN((OSTM_OPEN == (p_instance_ctrl->open)), FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(((p_instance_ctrl->p_cfg->channel) == 0U), FSP_ERR_INVALID_CHANNEL);
    FSP_ERROR_RETURN((0U == (p_instance_ctrl->p_reg->OSTMnTOE_b.OSTMnTOE)), FSP_ERR_INVALID_MODE);
#endif

    p_instance_ctrl->p_reg->OSTMnTO = (uint8_t) output_level;

    return FSP_SUCCESS;
}

/** @} (end addtogroup OSTM) */

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)

/*******************************************************************************************************************//**
 * Parameter checking for R_OSTM_Open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 * @param[in]  p_cfg              Configuration structure for this instance
 *
 * @retval FSP_SUCCESS                 Initialization was successful and timer has started.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL or the period is not in the valid range of
 *                                     1 to 0xFFFFFFFF.
 * @retval FSP_ERR_ALREADY_OPEN        R_OSTM_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    A required interrupt has not been enabled in the vector table.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Requested channel number is not available on OSTM.
 **********************************************************************************************************************/
static fsp_err_t r_ostm_open_param_checking (ostm_instance_ctrl_t * p_instance_ctrl, timer_cfg_t const * const p_cfg)
{
 #if (OSTM_CFG_PARAM_CHECKING_ENABLE == 1U)
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != (p_cfg->p_extend));
    FSP_ERROR_RETURN((OSTM_OPEN != (p_instance_ctrl->open)), FSP_ERR_ALREADY_OPEN);
 #endif

    /* Enable IRQ if user supplied a callback function,
     *  or if the timer is a one-shot timer (so the driver is able to
     *  turn off the timer after one period. */
    if ((NULL != p_cfg->p_callback) || (TIMER_MODE_ONE_SHOT == p_cfg->mode))
    {
        /* Return error if IRQ is required and not in the vector table. */
        FSP_ERROR_RETURN(((IRQn_Type) 0 <= (p_cfg->cycle_end_irq)), (FSP_ERR_IRQ_BSP_DISABLED)); /* PRQA S 4332 # Advisory R-10.5 */
    }

    FSP_ASSERT((((0U) != (p_cfg->period_counts))));

    /* Validate channel number. */
    FSP_ERROR_RETURN((0U != (((uint32_t) 1U << (uint32_t) (p_cfg->channel)) & BSP_FEATURE_OSTM_VALID_CHANNEL_MASK)),
                     (FSP_ERR_IP_CHANNEL_NOT_PRESENT));

    return FSP_SUCCESS;
}

#endif                                 /* OSTM_CFG_PARAM_CHECKING_ENABLE */

/*******************************************************************************************************************//**
 * Sets period register and updates compare match registers in one-shot and periodic mode.
 *
 * @param[in]  p_instance_ctrl    Control block for this instance
 * @param[in]  period_counts      OSTM period in counts
 **********************************************************************************************************************/
static void r_ostm_period_register_set (ostm_instance_ctrl_t * p_instance_ctrl, uint32_t period_counts)
{
    const ostm_extended_cfg_t * p_ext = (const ostm_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
    uint32_t timer_running            = 0U;
    if (1U == p_instance_ctrl->p_reg->OSTMnTE)
    {
        timer_running = 1U;
        p_instance_ctrl->p_reg->OSTMnTT = 1U;
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->OSTMnTE, 0U);
    }

    /* Store the period value so it can be retrieved later. */
    p_instance_ctrl->period = period_counts;

    /* Set counter to period. */
    p_instance_ctrl->p_reg->OSTMnCMP = period_counts;

    if (OSTM_TIMER_MODE_FREERUN == p_ext->ostm_mode)
    {
        p_instance_ctrl->p_reg->OSTMnCNT = 0U;
    }
    else
    {
        p_instance_ctrl->p_reg->OSTMnCNT = period_counts;
    }

    if (0U != timer_running)
    {
        p_instance_ctrl->p_reg->OSTMnTS = 1U;
    }
}

/*******************************************************************************************************************//**
 * Obtains the clock frequency of OSTM for all clock sources except OSTM0 underflow.
 *
 * @return Source clock frequency of OSTM in Hz.
 **********************************************************************************************************************/
static uint32_t r_ostm_clock_frequency_get (void)
{
    uint32_t clock_freq_hz = (0U);

    /* Get the OSTM clock source. */
#if (BSP_FEATURE_OSTM_EXTENDED_CHANNEL_LAYOUT_AVAILABLE == 1U)
    clock_freq_hz = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_CLK_HSB);
#else
    clock_freq_hz = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_CLKC_HSB);
#endif

    return clock_freq_hz;
}

/***********************************************************************************************************************
 * Interrupt service routines
 **********************************************************************************************************************/
BSP_INTERRUPT_ATTRIBUTE void ostm_int_isr (void) /* PRQA S 1503 # Rule-2.1 */
{
    /* Save context if RTOS is used */

    FSP_CONTEXT_SAVE

    /* Recover ISR context saved in open. */
    IRQn_Type              irq             = R_FSP_CurrentIrqGet();
    ostm_instance_ctrl_t * p_instance_ctrl = (ostm_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* If the channel is configured to be one-shot mode, stop the timer. */
    if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
    {
        /* Stop timer */
        p_instance_ctrl->p_reg->OSTMnTT = 1;
    }

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        /* Setup parameters for the user-supplied callback function. */
        timer_callback_args_t callback_args;

        /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
         * stored in non-secure memory so they can be accessed by a non-secure callback function. */
        timer_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
        if (NULL == p_args)
        {
            /* Store on stack */
            p_args = &callback_args;
        }
        else
        {
            /* Save current arguments on the stack in case this is a nested interrupt. */
            callback_args = *p_args;
        }

        p_args->event     = TIMER_EVENT_CYCLE_END;
        p_args->p_context = p_instance_ctrl->p_context;

        /* If the project is not Trustzone Secure, no need to change security state in order to call the callback. */
        p_instance_ctrl->p_callback(p_args);

        if (NULL != p_instance_ctrl->p_callback_memory)
        {
            /* Restore callback memory in case this is a nested interrupt. */
            *p_instance_ctrl->p_callback_memory = callback_args;
        }
    }

    /* Restore context if RTOS is used */

    FSP_CONTEXT_RESTORE
}
