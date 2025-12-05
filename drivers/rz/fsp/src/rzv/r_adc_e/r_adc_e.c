/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

#include "bsp_api.h"

/* Configuration for this package. */
#include "r_adc_e_cfg.h"

/* Private header file for this package. */
#include "r_adc_e.h"

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define ADC_E_PRV_USEC_PER_SEC             (1000000U)
#define ADC_E_PRV_MIN_ADCLK_HZ             (5000000U)
#define ADC_E_PRV_HZ_PER_KHZ               (1000U)
#define ADC_E_SHIFT_LEFT_ALIGNED_32_BIT    (16U)
#define ADC_E_OPEN                         (0x41444345U)

#define ADC_E_PRV_ADCSR_ADST_TRGE_MASK     (R_ADC_E_ADCSR_ADST_Msk | R_ADC_E_ADCSR_TRGE_Msk)
#define ADC_E_PRV_ADCSR_CLEAR_ADST_TRGE    (~ADC_E_PRV_ADCSR_ADST_TRGE_MASK)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
#if ADC_E_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_adc_e_open_cfg_check(adc_cfg_t const * const p_cfg);
static fsp_err_t r_adc_e_open_cfg_resolution_check(adc_cfg_t const * const p_cfg);

#endif

static void r_adc_e_open_sub(adc_e_instance_ctrl_t * const p_instance_ctrl, adc_cfg_t const * const p_cfg);
static void r_adc_e_stop_sub(adc_e_instance_ctrl_t * const p_instance_ctrl);

#if ADC_E_CFG_PARAM_CHECKING_ENABLE

static fsp_err_t r_adc_e_scan_cfg_check(adc_e_instance_ctrl_t * const     p_instance_ctrl,
                                        adc_e_channel_cfg_t const * const p_channel_cfg);

#endif

static void r_adc_e_scan_cfg(adc_e_instance_ctrl_t * const     p_instance_ctrl,
                             adc_e_channel_cfg_t const * const p_channel_cfg);
void            adc_e_scan_end_b_isr(void);
void            adc_e_scan_end_c_isr(void);
void            adc_e_scan_end_isr(void);
void            adc_e_window_compare_isr(void);
static void     r_adc_e_irq_enable(IRQn_Type irq, uint8_t ipl, void * p_context);
static void     r_adc_e_irq_disable(IRQn_Type irq);
static uint32_t r_adc_e_lowest_channel_get(uint32_t adc_mask);
static void     r_adc_e_scan_end_common_isr(adc_event_t event);

#if ADC_E_CFG_PARAM_CHECKING_ENABLE

/** Mask of valid channels on this MCU. */
static const uint32_t g_adc_valid_channels[] =
{
    BSP_FEATURE_ADC_E_UNIT_0_CHANNELS,
};
#endif

/* ADC_E base address */
static const uint32_t volatile * p_adc_e_base_address[BSP_FEATURE_ADC_E_MAX_UNIT] =
{
    (uint32_t *) R_ADC_E0,
#if BSP_FEATURE_ADC_E_MAX_UNIT > 1
    (uint32_t *) R_ADC_E1,
 #if BSP_FEATURE_ADC_E_MAX_UNIT > 2
    (uint32_t *) R_ADC_E2,
 #endif
#endif
};

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** ADC Implementation of ADC_E. */
const adc_api_t g_adc_on_adc_e =
{
    .open           = R_ADC_E_Open,
    .scanCfg        = R_ADC_E_ScanCfg,
    .infoGet        = R_ADC_E_InfoGet,
    .scanStart      = R_ADC_E_ScanStart,
    .scanGroupStart = R_ADC_E_ScanGroupStart,
    .scanStop       = R_ADC_E_ScanStop,
    .scanStatusGet  = R_ADC_E_StatusGet,
    .read           = R_ADC_E_Read,
    .read32         = R_ADC_E_Read32,
    .close          = R_ADC_E_Close,
    .calibrate      = R_ADC_E_Calibrate,
    .offsetSet      = R_ADC_E_OffsetSet,
    .callbackSet    = R_ADC_E_CallbackSet,
};

/*******************************************************************************************************************//**
 * @addtogroup ADC_E
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Sets the operational mode, trigger sources, interrupt  priority, and configurations for the peripheral as a whole.
 * If interrupt is enabled, the function registers a callback function pointer for notifying the user whenever a scan
 * has completed.
 *
 * @retval FSP_SUCCESS                     Module is ready for use.
 * @retval FSP_ERR_ASSERTION               An input argument is invalid.
 * @retval FSP_ERR_ALREADY_OPEN            The instance control structure has already been opened.
 * @retval FSP_ERR_IRQ_BSP_DISABLED        A callback is provided, but the interrupt is not enabled.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  The requested unit does not exist on this MCU.
 * @retval FSP_ERR_INVALID_HW_CONDITION    The ADC clock must be at least 1 MHz
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_Open (adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg)
{
    adc_e_instance_ctrl_t * p_instance_ctrl = (adc_e_instance_ctrl_t *) p_ctrl;

    /*  Perform parameter checking */
#if ADC_E_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);

    /* Verify the configuration parameters are valid   */
    fsp_err_t err = r_adc_e_open_cfg_check(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Check for valid argument values for options that are unique to the IP */
    err = r_adc_e_open_cfg_resolution_check(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Verify this unit has not already been initialized   */
    FSP_ERROR_RETURN(ADC_E_OPEN != p_instance_ctrl->opened, FSP_ERR_ALREADY_OPEN);

    /* If a callback is used, then make sure the scan end interrupt is enabled */
    adc_e_extended_cfg_t const * p_extend = (adc_e_extended_cfg_t const *) p_cfg->p_extend;
    if (NULL != p_cfg->p_callback)
    {
        FSP_ERROR_RETURN((p_cfg->scan_end_irq >= 0) || (p_extend->window_a_irq >= 0) || (p_extend->window_b_irq >= 0),
                         FSP_ERR_IRQ_BSP_DISABLED);

        /* Group B interrupts are never required since group B can be configured in continuous scan mode when group A
         * has priority over group B. */
    }

#else
    adc_e_extended_cfg_t const * p_extend = (adc_e_extended_cfg_t const *) p_cfg->p_extend;
#endif

    /* Save configurations. */
    p_instance_ctrl->p_cfg = p_cfg;

    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;
    p_instance_ctrl->p_reg             = (R_ADC_E0_Type *) p_adc_e_base_address[p_cfg->unit];

    /* Initialize the hardware based on the configuration. */
    r_adc_e_open_sub(p_instance_ctrl, p_cfg);

    /* Set the interrupt priorities. */
    r_adc_e_irq_enable(p_cfg->scan_end_irq, p_cfg->scan_end_ipl, p_instance_ctrl);
    r_adc_e_irq_enable(p_cfg->scan_end_b_irq, p_cfg->scan_end_b_ipl, p_instance_ctrl);
    r_adc_e_irq_enable(p_cfg->scan_end_c_irq, p_cfg->scan_end_c_ipl, p_instance_ctrl);
    r_adc_e_irq_enable(p_extend->window_a_irq, p_extend->window_a_ipl, p_instance_ctrl);
    r_adc_e_irq_enable(p_extend->window_b_irq, p_extend->window_b_ipl, p_instance_ctrl);

    /* Invalid scan mask (initialized for later). */
    p_instance_ctrl->scan_mask = 0U;

    /* Mark driver as opened by initializing it to "RADC" in its ASCII equivalent for this unit. */
    p_instance_ctrl->opened = ADC_E_OPEN;

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configures the ADC scan parameters. Channel specific settings are set in this function. Pass a pointer to
 * @ref adc_e_channel_cfg_t to p_channel_cfg.
 *
 * @retval FSP_SUCCESS                 Channel specific settings applied.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_ScanCfg (adc_ctrl_t * p_ctrl, void const * const p_channel_cfg)
{
    adc_e_channel_cfg_t const * p_adc_channel_cfg = (adc_e_channel_cfg_t const *) p_channel_cfg;
    adc_e_instance_ctrl_t     * p_instance_ctrl   = (adc_e_instance_ctrl_t *) p_ctrl;
    fsp_err_t err = FSP_SUCCESS;

#if ADC_E_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_adc_channel_cfg);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);

    err = r_adc_e_scan_cfg_check(p_instance_ctrl, p_adc_channel_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    /* Configure the hardware based on the configuration */
    r_adc_e_scan_cfg(p_instance_ctrl, p_adc_channel_cfg);

    /* Save the scan mask locally; this is required for the infoGet function. */
    p_instance_ctrl->scan_mask = p_adc_channel_cfg->scan_mask;

    /* Return the error code */
    return err;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements adc_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_CallbackSet (adc_ctrl_t * const          p_api_ctrl,
                               void (                    * p_callback)(adc_callback_args_t *),
                               void const * const          p_context,
                               adc_callback_args_t * const p_callback_memory)
{
    adc_e_instance_ctrl_t * p_ctrl = (adc_e_instance_ctrl_t *) p_api_ctrl;

#if (ADC_E_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_ctrl->p_callback        = p_callback;
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Starts a software scan or enables the hardware trigger for a scan depending on how the triggers were configured in
 * the R_ADC_E_Open call. If the unit was configured for ELC or external hardware triggering, then this function allows
 * the trigger signal to get to the ADC unit. The function is not able to control the generation of the trigger itself.
 * If the unit was configured for software triggering, then this function starts the software triggered scan.
 *
 * @pre Call R_ADC_E_ScanCfg after R_ADC_E_Open before starting a scan.
 *
 * @retval FSP_SUCCESS                 Scan started (software trigger) or hardware triggers enabled.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            ADC_E is not open.
 * @retval FSP_ERR_NOT_INITIALIZED     ADC_E is not initialized.
 * @retval FSP_ERR_IN_USE              Another scan is still in progress (software trigger).
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_ScanStart (adc_ctrl_t * p_ctrl)
{
    adc_e_instance_ctrl_t * p_instance_ctrl = (adc_e_instance_ctrl_t *) p_ctrl;

    /* Perform parameter checking  */
#if ADC_E_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);
    if (ADC_E_GRPA_GRPB_GRPC_TOP_CONT_SCAN != p_instance_ctrl->p_reg->ADGSPCR && ADC_E_GRPA_GRPB_GRPC_RESTART_TOP_CONT_SCAN != p_instance_ctrl->p_reg->ADGSPCR
            && ADC_E_GRPA_GRPB_GRPC_RESTART_CONT_SCAN != p_instance_ctrl->p_reg->ADGSPCR)
    {
        FSP_ERROR_RETURN(0U == p_instance_ctrl->p_reg->ADCSR_b.ADST, FSP_ERR_IN_USE);
    }
#endif

    /* Enable hardware trigger or start software scan depending on mode. */
    p_instance_ctrl->p_reg->ADSTRGR = p_instance_ctrl->scan_start_adstrgr;

    adc_e_extended_cfg_t * p_extend = (adc_e_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
    if (true == p_extend->adc_start_trigger_c_enabled)
    {
        p_instance_ctrl->p_reg->ADGCTRGR = p_instance_ctrl->scan_start_adgctrgr;
    }
    p_instance_ctrl->p_reg->ADCSR = p_instance_ctrl->scan_start_adcsr;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::scanStart is not supported on the ADCH. Use scanStart instead.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_ScanGroupStart (adc_ctrl_t * p_ctrl, adc_group_mask_t group_id)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(group_id);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Stops the software scan or disables the unit from being triggered by the hardware trigger (ELC or external) based on
 * what type of trigger the unit was configured for in the R_ADC_E_Open function. Stopping a hardware triggered scan via
 * this function does not abort an ongoing scan, but prevents the next scan from occurring. Stopping a software
 * triggered scan aborts an ongoing scan.
 *
 * @retval FSP_SUCCESS                 Scan stopped (software trigger) or hardware triggers disabled.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 * @retval FSP_ERR_NOT_INITIALIZED     Unit is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_ScanStop (adc_ctrl_t * p_ctrl)
{
    adc_e_instance_ctrl_t * p_instance_ctrl = (adc_e_instance_ctrl_t *) p_ctrl;

    /*  Perform parameter checking */
#if ADC_E_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);
#endif

    /* When using an external or internal trigger as the A/D conversion start condition, follow the procedure. */
    if (ADC_TRIGGER_SOFTWARE != p_instance_ctrl->p_cfg->trigger)
    {
        /* A/D conversion stop procedure. */
        r_adc_e_stop_sub(p_instance_ctrl);
    }

    /* Disable hardware trigger or stop software scan depending on mode. */
    p_instance_ctrl->p_reg->ADCSR = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provides the status of any scan process that was started, including scans started by ELC or external triggers.
 *
 * @retval FSP_SUCCESS                 Module status stored in the provided pointer p_status
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_StatusGet (adc_ctrl_t * p_ctrl, adc_status_t * p_status)
{
    adc_e_instance_ctrl_t * p_instance_ctrl = (adc_e_instance_ctrl_t *) p_ctrl;

#if ADC_E_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    /* Read the status of the ADST bit. ADST is set when a scan is in progress. */
    p_status->state = (adc_state_t) p_instance_ctrl->p_reg->ADCSR_b.ADST;

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads conversion results from a single channel or sensor.
 *
 * @retval FSP_SUCCESS                 Data read into provided p_data.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 * @retval FSP_ERR_NOT_INITIALIZED     Unit is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_Read (adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint16_t * const p_data)
{
    adc_e_instance_ctrl_t * p_instance_ctrl = (adc_e_instance_ctrl_t *) p_ctrl;

    /* Perform parameter checking. */
#if ADC_E_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_data);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);

    /* Verify that the channel is valid for this MCU */
    if ((reg_id >= ADC_CHANNEL_0) && ((uint32_t) reg_id <= 31U))
    {
        uint32_t requested_channel_mask = (1U << (uint32_t) reg_id);
        FSP_ASSERT(0 != (requested_channel_mask & g_adc_valid_channels[p_instance_ctrl->p_cfg->unit]));
    }
    else
    {
        FSP_ASSERT((reg_id == ADC_CHANNEL_DUPLEX) || (reg_id == ADC_CHANNEL_DUPLEX_A) ||
                   (reg_id == ADC_CHANNEL_DUPLEX_B));
    }
#endif

    /* Read the data from the requested ADC conversion register and return it */
    *p_data = *((uint16_t *) (&p_instance_ctrl->p_reg->ADDR0 + reg_id));

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads conversion results from a single channel or sensor register into a 32-bit result.
 *
 * @retval FSP_SUCCESS                 Data read into provided p_data.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 * @retval FSP_ERR_NOT_INITIALIZED     Unit is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_Read32 (adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint32_t * const p_data)
{
    uint16_t result    = 0U;
    uint32_t result_32 = 0U;

#if ADC_E_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_data);
#endif

    fsp_err_t err = R_ADC_E_Read(p_ctrl, reg_id, &result);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    result_32 = result;

    /* Left shift the result into the upper 16 bits if the unit is configured for left alignment. */
    adc_e_instance_ctrl_t * p_instance_ctrl = (adc_e_instance_ctrl_t *) p_ctrl;
    if (ADC_ALIGNMENT_LEFT == p_instance_ctrl->p_cfg->alignment)
    {
        result_32 <<= ADC_E_SHIFT_LEFT_ALIGNED_32_BIT;
    }

    *p_data = result_32;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Returns the address of the lowest number configured channel and the total number of bytes to be read in order to
 * read the results of the configured channels. If no channels are configured, then a length of 0 is returned.
 *
 * @note In group mode, information is returned for group A only.  Calculating information for group B is not currently
 * supported.
 *
 * @retval FSP_SUCCESS                 Information stored in p_adc_info.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_InfoGet (adc_ctrl_t * p_ctrl, adc_info_t * p_adc_info)
{
    adc_e_instance_ctrl_t * p_instance_ctrl = (adc_e_instance_ctrl_t *) p_ctrl;
    fsp_err_t               err             = FSP_SUCCESS;
    uint32_t                adc_mask        = 0;

#if ADC_E_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_adc_info);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    /* Retrieve the scan mask of active channels from the control structure */
    adc_mask = p_instance_ctrl->scan_mask;

    /* If at least one channel is configured, determine the highest and lowest configured channels. */
    if (adc_mask != 0U)
    {
        uint32_t lowest_channel = r_adc_e_lowest_channel_get(adc_mask);
        p_adc_info->p_address   = (uint32_t *) (&p_instance_ctrl->p_reg->ADDR0 + lowest_channel);

        /* Determine the highest channel that is configured. */
        uint32_t highest_channel = 31 - __CLZ(adc_mask);

        /* Determine the size of data that must be read to read all the channels between and including the
         * highest and lowest channels.*/
        p_adc_info->length = (uint32_t) ((highest_channel - lowest_channel) + 1);
    }
    else
    {
        /* If no channels are configured, set the return length 0. */
        p_adc_info->length = 0U;
    }

    p_adc_info->transfer_size = TRANSFER_SIZE_2_BYTE;

    return err;
}

/*******************************************************************************************************************//**
 * This function ends any scan in progress, disables interrupts, and removes power to the A/D peripheral.
 *
 * @retval FSP_SUCCESS                 Module closed.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_Close (adc_ctrl_t * p_ctrl)
{
    adc_e_instance_ctrl_t * p_instance_ctrl = (adc_e_instance_ctrl_t *) p_ctrl;

#if ADC_E_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ADC_E_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    /* Mark driver as closed   */
    p_instance_ctrl->opened      = 0U;
    p_instance_ctrl->initialized = 0U;

    /* A/D conversion stop procedure. */
    r_adc_e_stop_sub(p_instance_ctrl);

    /* Disable interrupts. */
    adc_e_extended_cfg_t * p_extend = (adc_e_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
    r_adc_e_irq_disable(p_instance_ctrl->p_cfg->scan_end_irq);
    r_adc_e_irq_disable(p_instance_ctrl->p_cfg->scan_end_b_irq);
    r_adc_e_irq_disable(p_instance_ctrl->p_cfg->scan_end_c_irq);
    r_adc_e_irq_disable(p_extend->window_a_irq);
    r_adc_e_irq_disable(p_extend->window_b_irq);

    /* Stop the ADC. */
    p_instance_ctrl->p_reg->ADCSR = 0U;

#if !(BSP_FEATURE_ADC_E_MAX_UNIT > 1)

    /* If the ADC does not have multiple units, turn off the power to the A/D converter. */
    R_SYSC->SYS_ADC_CFG = 1;
#endif

    R_BSP_MODULE_STOP(FSP_IP_ADC, 0);

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::calibrate is not supported on the ADC.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_Calibrate (adc_ctrl_t * const p_ctrl, void const * p_extend)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_extend);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::offsetSet is not supported on the ADC.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_OffsetSet (adc_ctrl_t * const p_ctrl, adc_channel_t const reg_id, int32_t offset)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(reg_id);
    FSP_PARAMETER_NOT_USED(offset);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup ADC_E)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if ADC_E_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Validates the configuration arguments for illegal combinations or options.
 *
 * @param[in]  p_cfg                   Pointer to configuration structure
 *
 * @retval FSP_SUCCESS                     No configuration errors detected
 * @retval FSP_ERR_ASSERTION               An input argument is invalid.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  ADC unit not present on this MCU
 * @retval FSP_ERR_INVALID_HW_CONDITION    The ADC clock must be at least 1 MHz
 **********************************************************************************************************************/
static fsp_err_t r_adc_e_open_cfg_check (adc_cfg_t const * const p_cfg)
{
    FSP_ASSERT(NULL != p_cfg);

    /* Verify the unit exists on the MCU. */
    FSP_ERROR_RETURN(((1U << p_cfg->unit) & BSP_FEATURE_ADC_E_VALID_UNIT_MASK), FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    /* Verify the ADC clock frequency is 5 MHz. (ADCCLK is fixed at 5MHz) */
    uint32_t freq_hz = R_FSP_SystemClockHzGet(BSP_FEATURE_ADC_E_CLOCK_SOURCE);
    FSP_ERROR_RETURN(freq_hz >= ADC_E_PRV_MIN_ADCLK_HZ, FSP_ERR_INVALID_HW_CONDITION);

    adc_e_extended_cfg_t const * p_cfg_extend = (adc_e_extended_cfg_t const *) p_cfg->p_extend;

    /* Only synchronous triggers (ELC) allowed in group scan mode (reference TRSA documentation in section
     * A/D conversion in Double Trigger Mode)" in the user's manual.  */
    if ((ADC_MODE_GROUP_SCAN == p_cfg->mode) || (ADC_E_DOUBLE_TRIGGER_DISABLED != p_cfg_extend->double_trigger_mode))
    {
        FSP_ASSERT(ADC_TRIGGER_SYNC_ELC == p_cfg->trigger);

        if ((ADC_MODE_GROUP_SCAN == p_cfg->mode))
        {
            FSP_ASSERT(ADC_TRIGGER_SYNC_ELC == p_cfg_extend->trigger_group_b);
        }
    }

    return FSP_SUCCESS;
}

#endif

#if ADC_E_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * This function validates the resolution configuration arguments for illegal combinations or options.
 *
 * @param[in]  p_cfg                   Pointer to configuration structure
 *
 * @retval FSP_SUCCESS                 No configuration errors detected
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_adc_e_open_cfg_resolution_check (adc_cfg_t const * const p_cfg)
{
    FSP_ASSERT((ADC_RESOLUTION_12_BIT == p_cfg->resolution) ||
               (ADC_RESOLUTION_8_BIT == p_cfg->resolution));

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * The Open function applies power to the A/D peripheral, sets the operational mode, trigger sources, and
 * configurations common to all channels and sensors.
 *
 * @param[in]  p_instance_ctrl         Pointer to instance control block
 * @param[in]  p_cfg                   Pointer to configuration structure
 **********************************************************************************************************************/
static void r_adc_e_open_sub (adc_e_instance_ctrl_t * const p_instance_ctrl, adc_cfg_t const * const p_cfg)
{
    adc_e_extended_cfg_t const * p_cfg_extend = (adc_e_extended_cfg_t const *) p_cfg->p_extend;

    /* Determine the value for ADCSR:
     *   * The configured mode is set in ADCSR.ADCS.
     *   * ADCSR.GBADIE is always set by this driver. It will only trigger an interrupt in group mode if the group B
     *     interrupt is enabled.
     *   * If double-trigger mode is selected ADCSR.DBLANS is set to the chosen double-trigger scan channel and
     *     ADCSR.DBLE is set to 1; otherwise, both are set to 0.
     *   * The configured trigger mode is set in ADCSR.EXTRG and ADCSR.TRGE.
     *   * The value to set in ADCSR to start a scan is stored in the control structure. ADCSR.ADST is set in
     *     R_ADC_ScanStart if software trigger mode is used.
     */
    uint16_t adcsr = (uint16_t) (p_cfg->mode << R_ADC_E_ADCSR_ADCS_Pos);
    adcsr |= R_ADC_E_ADCSR_GBADIE_Msk;
    adcsr |= R_ADC_E_ADCSR_ADIE_Msk;
    adcsr |= (uint16_t) (p_cfg->trigger << R_ADC_E_ADCSR_EXTRG_Pos);

    if (ADC_E_DOUBLE_TRIGGER_DISABLED != p_cfg_extend->double_trigger_mode)
    {
        adcsr |= R_ADC_E_ADCSR_TRGE_Msk | R_ADC_E_ADCSR_DBLE_Msk;
    }
    else if (ADC_TRIGGER_SOFTWARE == p_cfg->trigger)
    {
        adcsr |= R_ADC_E_ADCSR_ADST_Msk;
    }
    else
    {
        /* Do nothing. */
    }

    p_instance_ctrl->scan_start_adcsr = adcsr;

    /* Determine the value for ADCER:
     *   * The resolution is set as configured in ADCER.ADPRC (on MCUs that have this bitfield).
     *   * The alignment is set as configured in ADCER.ADFMT (on MCUs that have this bitfield).
     *   * The clearing option is set as configured in ADCER.ACE.
     *   * Always select data range of 0 - 32767 in ADCER.INV (on MCUs that have this bitfield).
     *   * Always disable self-diagnosis (unsupported in this module).
     */
    uint16_t adcer = 0U;

#if BSP_FEATURE_ADC_E_HAS_ADCER_ADPRC
    adcer |= (uint16_t) (p_cfg->resolution << R_ADC_E_ADCER_ADPRC_Pos);
#endif
#if BSP_FEATURE_ADC_E_HAS_ADCER_ADRFMT
    adcer |= (uint16_t) (p_cfg->alignment << R_ADC_E_ADCER_ADRFMT_Pos);
#endif
    adcer |= (uint16_t) (p_cfg_extend->clearing << R_ADC_E_ADCER_ACE_Pos);

    /* Determine the value for ADADC:
     *   * The addition/averaging modes are set as configured in ADADC.ADC and ADADC.AVEE.
     */
    uint8_t adadc = p_cfg_extend->add_average_count;

    /* Apply clock to peripheral. */
    R_BSP_MODULE_START(FSP_IP_ADC, 0);

    /* Leaving power-down mode. */
    R_SYSC->SYS_ADC_CFG = 0;

    /* Wait 20us after leaving power-down mode. */
    R_BSP_SoftwareDelay(BSP_FEATURE_ADC_E_STABILIZATION_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);

    /* Set the predetermined values for ADCSR, ADSTRGR, ADGCTRGR, ADCER, and ADADC without setting ADCSR.ADST or ADCSR.TRGE.
     * ADCSR.ADST or ADCSR.TRGE are set as configured in R_ADC_ScanStart. */
    p_instance_ctrl->p_reg->ADCSR   = (uint16_t) (adcsr & ADC_E_PRV_ADCSR_CLEAR_ADST_TRGE);
    uint16_t adstrgr = (uint16_t) (((uint16_t)p_cfg_extend->adc_start_trigger_a << R_ADC_E_ADSTRGR_TRSA_Pos) |
                                   ((uint16_t)p_cfg_extend->adc_start_trigger_b << R_ADC_E_ADSTRGR_TRSB_Pos));
    p_instance_ctrl->p_reg->ADSTRGR = adstrgr;
    p_instance_ctrl->scan_start_adstrgr = adstrgr;
    p_instance_ctrl->p_reg->ADCER   = adcer;
    p_instance_ctrl->p_reg->ADADC   = adadc;
    p_instance_ctrl->p_reg->ADELCCR = (uint8_t) p_cfg_extend->adc_elc_ctrl;

    if (true == p_cfg_extend->adc_start_trigger_c_enabled)
    {
        uint8_t adgctrgr =
             ((uint8_t) p_cfg_extend->adc_start_trigger_c) << R_ADC_E_ADGCTRGR_TRSC_Pos |
                       (uint8_t) (R_ADC_E_ADGCTRGR_GCADIE_Msk |
                                  R_ADC_E_ADGCTRGR_GRCE_Msk);
        p_instance_ctrl->p_reg->ADGCTRGR = adgctrgr;
        p_instance_ctrl->scan_start_adgctrgr = adgctrgr;
    }
}

/*******************************************************************************************************************//**
 * A/D conversion stop procedure.
 *
 * @param[in]  p_instance_ctrl         Pointer to instance control block
 **********************************************************************************************************************/
static void r_adc_e_stop_sub (adc_e_instance_ctrl_t * const p_instance_ctrl)
{
    adc_e_extended_cfg_t * p_extend = (adc_e_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    p_instance_ctrl->p_reg->ADGSPCR_b.PGS = 0;

    /* Disable triggers. */
    if (ADC_MODE_GROUP_SCAN == p_instance_ctrl->p_cfg->mode)
    {
        p_instance_ctrl->p_reg->ADSTRGR  = R_ADC_E_ADSTRGR_TRSA_Msk | R_ADC_E_ADSTRGR_TRSB_Msk;
        if (true == p_extend->adc_start_trigger_c_enabled)
        {
            p_instance_ctrl->p_reg->ADGCTRGR_b.TRSC = R_ADC_E_ADGCTRGR_TRSC_Msk;
            p_instance_ctrl->p_reg->ADGCTRGR_b.GCADIE = 0U;
            p_instance_ctrl->p_reg->ADGCTRGR_b.GRCE = 0U;
        }
        else
        {
            /* Do nothing. */
        }
        p_instance_ctrl->p_reg->ADCSR_b.GBADIE = 0U;
    }
    else
    {
        p_instance_ctrl->p_reg->ADSTRGR  = R_ADC_E_ADSTRGR_TRSA_Msk;
    }

    /* Disable interrupts. */
    p_instance_ctrl->p_reg->ADCSR_b.ADIE = 0U;
}

#if ADC_E_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Enforces constraints on Window Compare function usage per section  "Constraints on the compare function" in
 * User's Manual.
 *
 * @param[in]  p_window_cfg            Pointer to window compare configuration
 *
 * @retval FSP_SUCCESS                 No configuration errors detected
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_adc_e_scan_cfg_check_window_compare (adc_e_window_cfg_t const * const p_window_cfg)
{
    if (p_window_cfg)
    {
        uint32_t compare_cfg = p_window_cfg->compare_cfg;
        if (0U != compare_cfg)
        {
            if ((compare_cfg & R_ADC_E_ADCMPCR_CMPAE_Msk) && (compare_cfg & R_ADC_E_ADCMPCR_CMPBE_Msk))
            {
                /* Ensure channels selected for Window A do not conflict with Window B */
                uint32_t compare_b_ch = p_window_cfg->compare_b_channel;
                FSP_ASSERT(!(p_window_cfg->compare_mask & (uint32_t) (1 << compare_b_ch)));
            }

            if (compare_cfg & R_ADC_E_ADCMPCR_WCMPE_Msk)
            {
                /* Ensure lower reference values are less than or equal to the high reference values */
                FSP_ASSERT((p_window_cfg->compare_ref_low <= p_window_cfg->compare_ref_high) &&
                           (p_window_cfg->compare_b_ref_low <= p_window_cfg->compare_b_ref_high));
            }
        }
    }

    return FSP_SUCCESS;
}

#endif

#if ADC_E_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * This function does extensive checking on channel mask settings based upon operational mode.
 *
 * @param[in]  p_instance_ctrl         Pointer to instance control block
 * @param[in]  p_channel_cfg           Pointer to channel configuration
 *
 * @retval FSP_SUCCESS                 No configuration errors detected
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_adc_e_scan_cfg_check (adc_e_instance_ctrl_t * const     p_instance_ctrl,
                                         adc_e_channel_cfg_t const * const p_channel_cfg)
{
    fsp_err_t err;
    uint16_t  unit = p_instance_ctrl->p_cfg->unit;
    adc_e_extended_cfg_t const * p_cfg_extend = (adc_e_extended_cfg_t const *) p_instance_ctrl->p_cfg->p_extend;

    /* Verify at least one channel is selected for normal / group A. */
    uint32_t valid_channels = g_adc_valid_channels[unit];
    FSP_ASSERT((0U != p_channel_cfg->scan_mask) && (0U == (p_channel_cfg->scan_mask & (~valid_channels))));

    if (ADC_MODE_GROUP_SCAN == p_instance_ctrl->p_cfg->mode)
    {
        /* Verify at least one channel is selected for group B. */
        FSP_ASSERT((0U != p_channel_cfg->scan_mask_group_b) &&
                   (0U == (p_channel_cfg->scan_mask_group_b & (~valid_channels))));

        if (true == p_cfg_extend->adc_start_trigger_c_enabled)
        {
            /* Verify at least one channel is selected for group C. */
            FSP_ASSERT((0U != p_channel_cfg->scan_mask_group_c) &&
                       (0U == (p_channel_cfg->scan_mask_group_c & (~valid_channels))));
        }
    }
    else
    {
        /* If group mode is not enabled, no channels can be selected for group B. */
        FSP_ASSERT(ADC_E_MASK_OFF == p_channel_cfg->scan_mask_group_b);

        /* If group mode is not enabled, no channels can be selected for group C. */
        FSP_ASSERT(ADC_E_MASK_OFF == p_channel_cfg->scan_mask_group_c);
    }

    /* Verify that if addition is enabled, then at least one channel is selected. */
    if (ADC_E_ADD_OFF != p_cfg_extend->add_average_count)
    {
        /* Addition mask should not include bits from inactive channels.
         * This also serves as a check for valid channels in the addition mask */
        uint32_t tmp_mask = p_channel_cfg->scan_mask_group_b | p_channel_cfg->scan_mask;
        FSP_ASSERT((0U == (p_channel_cfg->add_mask & ~tmp_mask)) && (0U != p_channel_cfg->add_mask));
    }
    else
    {
        /* Channels cannot be selected for addition if addition is not used. */
        FSP_ASSERT(ADC_E_MASK_OFF == p_channel_cfg->add_mask);
    }

    /* Check window compare settings. */
    err = r_adc_e_scan_cfg_check_window_compare(p_channel_cfg->p_window_cfg);

    return err;
}

#endif

/*******************************************************************************************************************//**
 * This function does extensive checking on channel mask settings based upon operational mode. Mask registers are
 * initialized and interrupts enabled in peripheral. Interrupts are also enabled in ICU if corresponding priority
 * is not 0.
 *
 * @param[in]  p_instance_ctrl         Pointer to instance control block
 * @param[in]  p_channel_cfg           Pointer to channel configuration
 **********************************************************************************************************************/
static void r_adc_e_scan_cfg (adc_e_instance_ctrl_t * const     p_instance_ctrl,
                              adc_e_channel_cfg_t const * const p_channel_cfg)
{
    adc_e_extended_cfg_t const * p_cfg_extend = (adc_e_extended_cfg_t const *) p_instance_ctrl->p_cfg->p_extend;

    p_instance_ctrl->p_reg->ADANSA0 = (uint16_t) (p_channel_cfg->scan_mask);
    p_instance_ctrl->p_reg->ADANSB0 = (uint16_t) (p_channel_cfg->scan_mask_group_b);
    p_instance_ctrl->p_reg->ADANSC0 = (uint16_t) (p_channel_cfg->scan_mask_group_c);
    p_instance_ctrl->p_reg->ADADS0  = (uint16_t) (p_channel_cfg->add_mask);

    /* Get window compare configuration */
    adc_e_window_cfg_t * p_window_cfg = p_channel_cfg->p_window_cfg;

    uint16_t adcmpcr = 0;

    if (p_window_cfg)
    {
        /* Save window compare config */
        adcmpcr = (uint16_t) p_window_cfg->compare_cfg;

        if (p_window_cfg->compare_cfg & R_ADC_E_ADCMPCR_CMPAE_Msk)
        {
            /* Set Window A boundary values */
            p_instance_ctrl->p_reg->ADCMPCR  = p_window_cfg->compare_cfg & UINT16_MAX;
            p_instance_ctrl->p_reg->ADCMPDR0 = p_window_cfg->compare_ref_low;
            p_instance_ctrl->p_reg->ADCMPDR1 = p_window_cfg->compare_ref_high;

            /* Set Window A channel mask */
            p_instance_ctrl->p_reg->ADCMPANSR0 = p_window_cfg->compare_mask & UINT16_MAX;

            /* Set Window A channel inequality mode mask */
            p_instance_ctrl->p_reg->ADCMPLR0 = p_window_cfg->compare_mode_mask & UINT16_MAX;
        }

        if (p_window_cfg->compare_cfg & R_ADC_E_ADCMPCR_CMPBE_Msk)
        {
            /* Set Window B channel and mode */
            p_instance_ctrl->p_reg->ADCMPBNSR = (uint8_t) ((adc_e_window_b_mode_t) p_window_cfg->compare_b_channel |
                                                           p_window_cfg->compare_b_mode);

            /* Set Window B boundary values */
            p_instance_ctrl->p_reg->ADWINLLB = p_window_cfg->compare_b_ref_low;
            p_instance_ctrl->p_reg->ADWINULB = p_window_cfg->compare_b_ref_high;
        }
    }

    /* Set window compare config */
    p_instance_ctrl->p_reg->ADCMPCR = adcmpcr;

    /* Set group A priority action (not interrupt priority!)
     * This will also start the Group B scans if configured for ADC_GROUP_A_GROUP_B_CONTINUOUS_SCAN.
     */
    p_instance_ctrl->p_reg->ADGSPCR = (uint16_t) p_channel_cfg->priority_group_a;

    /* In double-trigger mode set the channel select bits to the highest selected channel number then return. */
    if (ADC_E_DOUBLE_TRIGGER_DISABLED != p_cfg_extend->double_trigger_mode)
    {
        uint32_t adcsr = p_instance_ctrl->p_reg->ADCSR;
        adcsr = (adcsr & ~R_ADC_E_ADCSR_DBLANS_Msk) + (31U - __CLZ(p_channel_cfg->scan_mask));
        p_instance_ctrl->p_reg->ADCSR      = (uint16_t) adcsr;
        p_instance_ctrl->scan_start_adcsr |= (uint16_t) adcsr;
    }

    p_instance_ctrl->initialized = ADC_E_OPEN;
}

/*******************************************************************************************************************//**
 * Enables requested IRQ.
 *
 * @param[in]  irq        IRQ to enable
 * @param[in]  ipl        Interrupt priority
 * @param[in]  p_context  Pointer to interrupt context
 **********************************************************************************************************************/
static void r_adc_e_irq_enable (IRQn_Type irq, uint8_t ipl, void * p_context)
{
    if (irq >= 0)
    {
        R_BSP_IrqCfgEnable(irq, ipl, p_context);
    }
}

/*******************************************************************************************************************//**
 * Disables and clears context for the requested IRQ.
 *
 * @param[in]  irq  IRQ to disable
 **********************************************************************************************************************/
static void r_adc_e_irq_disable (IRQn_Type irq)
{
    if (irq >= 0)
    {
        R_BSP_IrqDisable(irq);
        R_FSP_IsrContextSet(irq, NULL);
    }
}

/*******************************************************************************************************************//**
 * Returns the lowest channel index that is configured  in order to read the results of the configured channels.
 *
 * @param[in]  adc_mask  scan mask of active channels retrieved from the control structure
 *
 * @retval  adc_mask_count  index value of lowest channel
 **********************************************************************************************************************/
static uint32_t r_adc_e_lowest_channel_get (uint32_t adc_mask)
{
    /* Initialize the mask result */
    uint32_t adc_mask_result = 0U;
    int32_t  adc_mask_count  = -1;
    while (0U == adc_mask_result)
    {
        /* Increment channel until a channel is found in the mask. */
        adc_mask_count++;
        adc_mask_result = (uint32_t) (adc_mask & (1U << adc_mask_count));
    }

    return (uint32_t) adc_mask_count;
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to ADC instance control block
 * @param[in]     p_args     Pointer to arguments on stack
 **********************************************************************************************************************/
static void r_adc_e_call_callback (adc_e_instance_ctrl_t * p_ctrl, adc_callback_args_t * p_args)
{
    adc_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    adc_callback_args_t * p_args_memory = p_ctrl->p_callback_memory;
    if (NULL == p_args_memory)
    {
        /* Use provided args struct on stack */
        p_args_memory = p_args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args_memory;

        /* Copy the stacked args to callback memory */
        *p_args_memory = *p_args;
    }

#if BSP_TZ_SECURE_BUILD

    /* p_callback can point to a secure function or a non-secure function. */
    if (!cmse_is_nsfptr(p_ctrl->p_callback))
    {
        /* If p_callback is secure, then the project does not need to change security state. */
        p_ctrl->p_callback(p_args_memory);
    }
    else
    {
        /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
        adc_prv_ns_callback p_callback = (adc_prv_ns_callback) (p_ctrl->p_callback);
        p_callback(p_args_memory);
    }

#else

    /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
    p_ctrl->p_callback(p_args_memory);
#endif

    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * Clears interrupt flag and calls a callback to notify application of the event.
 *
 * @param[in]  event                   Event that triggered the ISR
 **********************************************************************************************************************/
static void r_adc_e_scan_end_common_isr (adc_event_t event)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    adc_e_instance_ctrl_t * p_instance_ctrl = (adc_e_instance_ctrl_t *) R_FSP_IsrContextGet(R_FSP_CurrentIrqGet());
    adc_callback_args_t     args;

    args.event = event;

    /* Store the unit number into the callback argument */
    args.unit = p_instance_ctrl->p_cfg->unit;

    /* Initialize the channel to 0.  It is not used in this implementation. */
    args.channel = ADC_CHANNEL_0;

    /* Populate the context field. */
    args.p_context = p_instance_ctrl->p_context;

    /* If a callback was provided, call it with the argument */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_adc_e_call_callback(p_instance_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

/*******************************************************************************************************************//**
 * This function implements the unit 0 interrupt handler for normal/Group A/double trigger scan complete.
 **********************************************************************************************************************/
void adc_e_scan_end_isr (void)
{
    r_adc_e_scan_end_common_isr(ADC_EVENT_SCAN_COMPLETE);
}

/*******************************************************************************************************************//**
 * This function implements the interrupt handler for Group B scan complete.
 **********************************************************************************************************************/
void adc_e_scan_end_b_isr (void)
{
    r_adc_e_scan_end_common_isr(ADC_EVENT_SCAN_COMPLETE_GROUP_B);
}

/*******************************************************************************************************************//**
 * This function implements the interrupt handler for Group C scan complete.
 **********************************************************************************************************************/
void adc_e_scan_end_c_isr (void)
{
    r_adc_e_scan_end_common_isr(ADC_EVENT_SCAN_COMPLETE_GROUP_C);
}

/*******************************************************************************************************************//**
 * This function implements the interrupt handler for window compare events.
 **********************************************************************************************************************/
void adc_e_window_compare_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    adc_e_instance_ctrl_t * p_instance_ctrl = (adc_e_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    adc_e_extended_cfg_t  * p_extend        = (adc_e_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    adc_callback_args_t args;
    args.event = (irq == p_extend->window_a_irq) ? ADC_EVENT_WINDOW_COMPARE_A : ADC_EVENT_WINDOW_COMPARE_B;

    /* Store the unit number into the callback argument */
    args.unit = p_instance_ctrl->p_cfg->unit;

    if (ADC_EVENT_WINDOW_COMPARE_A == args.event)
    {
        args.channel = (adc_channel_t) 0;

        R_ADC_E0_Type * p_reg = p_instance_ctrl->p_reg;

        /* Get Window A status registers */
        uint16_t adcmpsr0 = p_reg->ADCMPSR0;

        /* Get the lowest channel that meets Window A criteria */
        uint32_t lowest_channel = __CLZ(__RBIT(adcmpsr0));

        /* Clear the status flag corresponding to the lowest channel */
        p_reg->ADCMPSR0 = (uint16_t) (adcmpsr0 & ~(1 << (lowest_channel & 0xF)));

        args.channel = (adc_channel_t) lowest_channel;
    }
    else
    {
        /* Get channel selected for Window B */
        args.channel = (adc_channel_t) p_instance_ctrl->p_reg->ADCMPBNSR_b.CMPCHB;

        /* Clear IRQ */
        p_instance_ctrl->p_reg->ADCMPBSR_b.CMPSTB = 0;
    }

    /* Populate the context field. */
    args.p_context = p_instance_ctrl->p_context;

    /* If a callback was provided, call it with the argument */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_adc_e_call_callback(p_instance_ctrl, &args);
    }

    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}
