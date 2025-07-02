/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

#include "r_adc_c.h"

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define ADC_C_OPEN                               (0x41444343U)

/* A/D converter stabilization wait time. */
#define ADC_C_STABILIZATION_DELAY_US             (1U)
#define ADC_C_FRQ_DIV_RATIO                      (4U)
#define ADC_C_IDLE_TIME                          (0U)
#define ADC_C_PRV_ADM0_CLEAR_ADCE                (~R_ADC_C_ADM0_ADCE_Msk)
#define ADC_C_DATA_SIZE_BUFFER_MODE_4            (4U)
#define ADC_C_INTERRUPT_CHANNEL_BUFFER_MODE_4    (0x8U)
#define ADC_C_4_BUFFER_CHANNEL_MASK              (0xFU)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * adc_prv_ns_callback)(adc_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile adc_prv_ns_callback)(adc_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

static void r_adc_c_open_sub(adc_c_instance_ctrl_t * const p_instance_ctrl, adc_cfg_t const * const p_cfg);
static void r_adc_c_scan_cfg(adc_c_instance_ctrl_t * const     p_instance_ctrl,
                             adc_c_channel_cfg_t const * const p_channel_cfg);
void            adc_c_scan_end_isr(void);
static void     r_adc_c_irq_enable(IRQn_Type irq, uint8_t ipl, void * p_context);
static void     r_adc_c_irq_disable(IRQn_Type irq);
static uint32_t r_adc_c_lowest_channel_get(uint32_t adc_mask);
static uint32_t r_adc_c_highest_channel_get(uint32_t adc_mask);

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** ADC Implementation of ADC. */
const adc_api_t g_adc_on_adc_c =
{
    .open           = R_ADC_C_Open,
    .scanCfg        = R_ADC_C_ScanCfg,
    .infoGet        = R_ADC_C_InfoGet,
    .scanStart      = R_ADC_C_ScanStart,
    .scanGroupStart = R_ADC_C_ScanGroupStart,
    .scanStop       = R_ADC_C_ScanStop,
    .scanStatusGet  = R_ADC_C_StatusGet,
    .read           = R_ADC_C_Read,
    .read32         = R_ADC_C_Read32,
    .close          = R_ADC_C_Close,
    .calibrate      = R_ADC_C_Calibrate,
    .offsetSet      = R_ADC_C_OffsetSet,
    .callbackSet    = R_ADC_C_CallbackSet,
};

/*******************************************************************************************************************//**
 * @addtogroup ADC_C
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the ADC module and applies configurations.
 *
 * @retval FSP_SUCCESS                     Module is ready for use.
 * @retval FSP_ERR_ASSERTION               An input argument is invalid.
 * @retval FSP_ERR_ALREADY_OPEN            The instance control structure has already been opened.
 * @retval FSP_ERR_IRQ_BSP_DISABLED        A callback is provided, but the interrupt is not enabled.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_Open (adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg)
{
    adc_c_instance_ctrl_t * p_instance_ctrl = (adc_c_instance_ctrl_t *) p_ctrl;

    /*  Perform parameter checking */
#if ADC_C_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);

    /* Verify the configuration parameters are valid   */
    FSP_ASSERT(NULL != p_cfg);

    /* Verify this unit has not already been initialized   */
    FSP_ERROR_RETURN(ADC_C_OPEN != p_instance_ctrl->opened, FSP_ERR_ALREADY_OPEN);

    /* If a callback is used, then make sure an interrupt is enabled */
    if (NULL != p_cfg->p_callback)
    {
        FSP_ERROR_RETURN((p_cfg->scan_end_irq >= 0), FSP_ERR_IRQ_BSP_DISABLED);
    }
#endif

    /* Save configurations. */
    p_instance_ctrl->p_cfg             = p_cfg;
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Calculate the register base address. */
    p_instance_ctrl->p_reg = R_ADC_C;

    /* Initialize the hardware based on the configuration. */
    r_adc_c_open_sub(p_instance_ctrl, p_cfg);

    /* Enable interrupts */
    r_adc_c_irq_enable(p_cfg->scan_end_irq, p_cfg->scan_end_ipl, p_instance_ctrl);

    /* Invalid scan mask (initialized for later). */
    p_instance_ctrl->scan_mask = 0U;

    /* Mark driver as opened by initializing it to "ADCC" in its ASCII equivalent for this unit. */
    p_instance_ctrl->opened = ADC_C_OPEN;

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configures the ADC_C scan parameters. Channel specific settings are set in this function. Pass a pointer to
 * @ref adc_c_channel_cfg_t to p_channel_cfg.
 *
 *
 * @retval FSP_SUCCESS                 Channel specific settings applied.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_ScanCfg (adc_ctrl_t * p_ctrl, void const * const p_channel_cfg)
{
    adc_c_channel_cfg_t const * p_adc_channel_cfg = (adc_c_channel_cfg_t const *) p_channel_cfg;
    adc_c_instance_ctrl_t     * p_instance_ctrl   = (adc_c_instance_ctrl_t *) p_ctrl;
    fsp_err_t err = FSP_SUCCESS;

#if ADC_C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_adc_channel_cfg);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);

    /* Multiple analog input channel selection is prohibited in select mode. */
    FSP_ASSERT(!((ADC_C_OPERATING_MODE_SELECT == p_instance_ctrl->operating_mode) &&
                 ((ADC_C_MASK_CHANNEL_0 | ADC_C_MASK_CHANNEL_1) == p_adc_channel_cfg->scan_mask)));
#endif

    /* Configure the hardware based on the configuration. */
    r_adc_c_scan_cfg(p_instance_ctrl, p_adc_channel_cfg);

    /* Save the scan mask locally; this is required for the infoGet function. */
    p_instance_ctrl->scan_mask = p_adc_channel_cfg->scan_mask;

    /* Return the error code. */
    return err;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements adc_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_CallbackSet (adc_ctrl_t * const          p_api_ctrl,
                               void (                    * p_callback)(adc_callback_args_t *),
                               void const * const          p_context,
                               adc_callback_args_t * const p_callback_memory)
{
    adc_c_instance_ctrl_t * p_ctrl = (adc_c_instance_ctrl_t *) p_api_ctrl;

#if (ADC_C_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if ADC_C_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    adc_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                      CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif

    p_ctrl->p_callback = callback_is_secure ? p_callback :
                         (void (*)(adc_callback_args_t *))cmse_nsfptr_create(p_callback);
#else
    p_ctrl->p_callback = p_callback;
#endif

    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Start A/D conversion.
 *
 * @pre Call R_ADC_C_ScanCfg after R_ADC_C_Open before starting a scan.
 *
 * @retval FSP_SUCCESS                 Scan started (software trigger) or hardware triggers enabled.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 * @retval FSP_ERR_NOT_INITIALIZED     Unit is not initialized.
 * @retval FSP_ERR_IN_USE              Another scan is still in progress (software trigger).
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_ScanStart (adc_ctrl_t * p_ctrl)
{
    adc_c_instance_ctrl_t * p_instance_ctrl = (adc_c_instance_ctrl_t *) p_ctrl;

    /* Perform parameter checking  */
#if ADC_C_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);
    FSP_ERROR_RETURN(0U == p_instance_ctrl->p_reg->ADM0_b.ADCE, FSP_ERR_IN_USE);
#endif

    /* Start A/D conversion. */
    p_instance_ctrl->p_reg->ADM0 = p_instance_ctrl->scan_start;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::scanGroupStart is not supported. Use scanStart instead.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_ScanGroupStart (adc_ctrl_t * p_ctrl, adc_group_mask_t group_id)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(group_id);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Stop A/D conversion.
 *
 * @retval FSP_SUCCESS                 Scan stopped (software trigger) or hardware triggers disabled.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 * @retval FSP_ERR_NOT_INITIALIZED     Unit is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_ScanStop (adc_ctrl_t * p_ctrl)
{
    adc_c_instance_ctrl_t * p_instance_ctrl = (adc_c_instance_ctrl_t *) p_ctrl;

    /*  Perform parameter checking */
#if ADC_C_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);
#endif

    /* Stop A/D conversion. */
    p_instance_ctrl->p_reg->ADM0 = (uint32_t) (p_instance_ctrl->scan_start & ADC_C_PRV_ADM0_CLEAR_ADCE);

    /* Read ADM0 register to confirm that A/D conversion is stopped. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->ADM0_b.ADCE, 0U);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get current ADC_C status and store it in provided pointer p_status.
 *
 * @retval FSP_SUCCESS                 Module status stored in the provided pointer p_status
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_StatusGet (adc_ctrl_t * p_ctrl, adc_status_t * p_status)
{
    adc_c_instance_ctrl_t * p_instance_ctrl = (adc_c_instance_ctrl_t *) p_ctrl;

#if ADC_C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    /* Read the status of the ADBSY bit. ADBSY is set when a scan is in progress. */
    p_status->state = (adc_state_t) p_instance_ctrl->p_reg->ADM0_b.ADBSY;

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
fsp_err_t R_ADC_C_Read (adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint16_t * const p_data)
{
    adc_c_instance_ctrl_t * p_instance_ctrl = (adc_c_instance_ctrl_t *) p_ctrl;

    /* Perform parameter checking. */
#if ADC_C_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_data);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);

    /* Verify that the channel is valid for this MCU */
    uint32_t requested_channel_mask = (1U << (uint32_t) reg_id);
    FSP_ASSERT(0 != (requested_channel_mask & BSP_FEATURE_ADC_C_VALID_CHANNEL_MASK));
#endif

    /* Read the data from the requested ADC conversion register and return it */
    *p_data = *((uint16_t *) (&p_instance_ctrl->p_reg->ADCR0 + reg_id));

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
fsp_err_t R_ADC_C_Read32 (adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint32_t * const p_data)
{
    uint16_t result    = 0U;
    uint32_t result_32 = 0U;

#if ADC_C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_data);
#endif

    fsp_err_t err = R_ADC_C_Read(p_ctrl, reg_id, &result);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    result_32 = result;
    *p_data   = result_32;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets the sample state count for individual channels. This only needs to be set for special use cases. Normally, use
 * the default values out of reset.
 *
 * @note The sample states for the temperature and voltage sensor are set in R_ADC_C_ScanCfg.
 *
 * @retval FSP_SUCCESS                 Sample state count updated.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_INITIALIZED     Unit is not initialized.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 * @retval FSP_ERR_IN_USE              A/D conversion ongoing.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_SampleStateCountSet (adc_ctrl_t * p_ctrl, uint16_t num_states)
{
    adc_c_instance_ctrl_t * p_instance_ctrl = (adc_c_instance_ctrl_t *) p_ctrl;
    fsp_err_t               err             = FSP_SUCCESS;

    /* Perform parameter checking */
#if ADC_C_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);
    FSP_ERROR_RETURN(0 == p_instance_ctrl->p_reg->ADM0_b.ADBSY, FSP_ERR_IN_USE);

    /* Verify the arguments are within the expected range. */
    FSP_ASSERT((num_states >= BSP_FEATURE_ADC_C_SAMPLE_STATE_COUNT_MIN) &&
               (num_states <= BSP_FEATURE_ADC_C_SAMPLE_STATE_COUNT_MAX));
#endif

    /* Set the sample state count for the specified register */
    uint32_t adm3 = (uint32_t) (ADC_C_IDLE_TIME << R_ADC_C_ADM3_ADIL_Pos) |
                    (uint32_t) (BSP_FEATURE_ADC_C_CONVERSION_TIME << R_ADC_C_ADM3_ADCMP_Pos) |
                    (num_states << R_ADC_C_ADM3_ADSMP_Pos);
    p_instance_ctrl->p_reg->ADM3 = adm3;

    /* Return the error code */
    return err;
}

/*******************************************************************************************************************//**
 * Returns the address of the lowest number configured channel and the total number of bytes to be read in order to
 * read the results of the configured channels. If no channels are configured, then a length of 0 is returned.
 *
 *
 * @retval FSP_SUCCESS                 Information stored in p_adc_info.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_InfoGet (adc_ctrl_t * p_ctrl, adc_info_t * p_adc_info)
{
    adc_c_instance_ctrl_t * p_instance_ctrl = (adc_c_instance_ctrl_t *) p_ctrl;
    fsp_err_t               err             = FSP_SUCCESS;
    uint32_t                adc_mask        = 0;

#if ADC_C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_adc_info);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    adc_c_extended_cfg_t * p_extend = (adc_c_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Retrieve the scan mask of active channels from the control structure */
    adc_mask = p_instance_ctrl->scan_mask;

    if (ADC_C_BUFFER_MODE_4 == p_extend->buffer_mode)
    {
        p_adc_info->length    = ADC_C_DATA_SIZE_BUFFER_MODE_4;
        p_adc_info->p_address = &p_instance_ctrl->p_reg->ADCR0;
    }
    else
    {
        /* If at least one channel is configured, determine the highest and lowest configured channels. */
        if (adc_mask != 0U)
        {
            uint32_t adc_mask_in_order = adc_mask;
            uint32_t  lowest_channel   = r_adc_c_lowest_channel_get(adc_mask_in_order);

            p_adc_info->p_address = (uint32_t *) (&p_instance_ctrl->p_reg->ADCR0 + lowest_channel);

            /* Determine the highest channel that is configured. */
            uint32_t highest_channel = r_adc_c_highest_channel_get(adc_mask_in_order);

            /* Determine the size of data that must be read to read all the channels between and including the
             * highest and lowest channels.*/
            p_adc_info->length = (uint32_t) ((highest_channel - lowest_channel) + 1);
        }
        else
        {
            /* If no channels are configured, set the return length 0. */
            p_adc_info->length = 0U;
        }
    }

    p_adc_info->transfer_size = TRANSFER_SIZE_2_BYTE;

#if BSP_FEATURE_ADC_C_TSU_CONTROL_AVAILABLE

    /* Read into memory. */
    p_adc_info->calibration_data1 = R_TSU->OTPTSUTRIM0_REG_b.OTPTSUTRIM0;
    p_adc_info->calibration_data2 = R_TSU->OTPTSUTRIM1_REG_b.OTPTSUTRIM1;
#else

    /* Set Temp Sensor calibration data to invalid value */
    p_adc_info->calibration_data1 = UINT32_MAX;
    p_adc_info->calibration_data2 = UINT32_MAX;
#endif

    return err;
}

/*******************************************************************************************************************//**
 * This function ends any scan in progress, disables interrupts, and removes power to the A/D peripheral.
 *
 * @retval FSP_SUCCESS                 Module closed.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_Close (adc_ctrl_t * p_ctrl)
{
    adc_c_instance_ctrl_t * p_instance_ctrl = (adc_c_instance_ctrl_t *) p_ctrl;

#if ADC_C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ADC_C_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    /* Mark driver as closed   */
    p_instance_ctrl->opened      = 0U;
    p_instance_ctrl->initialized = 0U;

    /* Disable interrupts. */
    r_adc_c_irq_disable(p_instance_ctrl->p_cfg->scan_end_irq);

    /* Stop the ADC. */
    p_instance_ctrl->p_reg->ADM0 = 0U;

    /* Read ADM0 register to confirm that A/D conversion is stopped. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->ADM0_b.ADCE, 0U);

    /* Clear the interrupt cause flag and trigger detection flag.  */
    uint32_t adsts = (uint32_t) (1 << R_ADC_C_ADSTS_TRGS_Pos);
    adsts |= (uint32_t) (BSP_FEATURE_ADC_C_VALID_CHANNEL_MASK << R_ADC_C_ADSTS_INTST_Pos);
    p_instance_ctrl->p_reg->ADSTS = adsts;

    R_BSP_MODULE_STOP(FSP_IP_ADC, 0);

    if (p_instance_ctrl->scan_mask & ADC_C_MASK_CHANNEL_8)
    {
#if BSP_FEATURE_ADC_C_TSU_CONTROL_AVAILABLE

        /* Set the temperature sensor to place in the standby mode. */
        R_TSU->TSU_SM = 0;

        /* Stop the TSU. */
        R_BSP_MODULE_STOP(FSP_IP_TSU, 0);
#endif
    }

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::calibrate is not supported.
 *
 * @retval FSP_ERR_UNSUPPORTED         Calibration not supported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_Calibrate (adc_ctrl_t * const p_ctrl, void const * p_extend)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_extend);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::offsetSet is not supported.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_OffsetSet (adc_ctrl_t * const p_ctrl, adc_channel_t const reg_id, int32_t offset)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(reg_id);
    FSP_PARAMETER_NOT_USED(offset);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup ADC_C)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * The Open function applies power to the A/D peripheral, sets the value for ADM0, ADM1, ADM3, ADIVC, ADFIL.
 *
 * @param[in]  p_instance_ctrl         Pointer to instance control block
 * @param[in]  p_cfg                   Pointer to configuration structure
 **********************************************************************************************************************/
static void r_adc_c_open_sub (adc_c_instance_ctrl_t * const p_instance_ctrl, adc_cfg_t const * const p_cfg)
{
    adc_c_extended_cfg_t const * p_cfg_extend = (adc_c_extended_cfg_t const *) p_cfg->p_extend;

    /* Determine the value for ADM0, ADM1, ADM3, ADIVC, ADFIL.:
     * The value to set in ADCSR to start a scan is stored in the control structure.
     * ADM0.ADCE is set in R_ADC_ScanStart.
     */
     
    /* Sets the trigger mode. */
    uint32_t adm1 = (uint32_t) (p_cfg_extend->trigger_mode << R_ADC_C_ADM1_TRG_Pos);

    /* When using hardware trigger mode, set the hardware trigger signal parameter. */
    if (ADC_C_TRIGGER_MODE_HARDWARE == p_cfg_extend->trigger_mode)
    {
        adm1 |= (uint32_t) (p_cfg_extend->trigger_source << R_ADC_C_ADM1_TRGEN_Pos);
        adm1 |= (uint32_t) (p_cfg_extend->input_mode << R_ADC_C_ADM1_TRGIN_Pos);

        /* The trigger edge setting is valid only when the trigger source is ADC_TRG.
         * Reference section "A/D Converter Mode Register 1 (ADM1)" of the user's manual. */
        if (ADC_C_ACTIVE_TRIGGER_EXTERNAL == p_cfg_extend->trigger_source)
        {
            adm1 |= (uint32_t) (p_cfg_extend->trigger_edge << R_ADC_C_ADM1_EGA_Pos);
        }
        /* Otherwise falling edge is always valid. */
        else
        {
            adm1 |= (uint32_t) (ADC_C_TRIGGER_EDGE_FALLING << R_ADC_C_ADM1_EGA_Pos);
        }
    }
    else
    {
        /* Do nothing. */
    }

    /* Sets the operating mode and buffer mode. */
    adm1 |= (uint32_t) (p_cfg_extend->operating_mode << R_ADC_C_ADM1_MS_Pos);

    /* 1-Buffer mode and 4-Buffer mode can be set when using select mode. */
    if (ADC_C_OPERATING_MODE_SELECT == p_cfg_extend->operating_mode)
    {
        adm1 |= (uint32_t) (p_cfg_extend->buffer_mode << R_ADC_C_ADM1_BS_Pos);
    }

    /* Repeat mode corresponds to ADC_MODE_CONTINUOUS_SCAN of API,
     * but since the API value (=2) and repeat mode register setting value (=1) are different,
     * it is necessary to convert them.
     * Sets the conversion mode. */
    adm1 |= (uint32_t) ((p_cfg->mode >> 1U) << R_ADC_C_ADM1_RPS_Pos);

#if BSP_FEATURE_ADC_C_HAS_ADIVC

    /* Sets the frequency division ratio for dividing the frequency of ADC_ADCLK(TSUϕ). */
    uint32_t adivc = (uint32_t) (ADC_C_FRQ_DIV_RATIO << R_ADC_C_ADIVC_DIVADC_Pos);
#endif

    uint32_t adfil = 0;

    /* Enables or disables the AD external trigger pin filter. */
    if (ADC_C_FILTER_STAGE_SETTING_DISABLE != p_cfg_extend->external_trigger_filter)
    {
        adfil = (uint32_t) (1 << R_ADC_C_ADFIL_FILONOFF_Pos);

        /* Set the number of stages of the AD external trigger pin filter. */
        adfil |= (uint32_t) ((p_cfg_extend->external_trigger_filter - 1) << R_ADC_C_ADFIL_FILNUM_Pos);
    }
    else
    {
        /* Do nothing. */
    }

    /* Set the idle period. */
    uint32_t adm3 = (uint32_t) (ADC_C_IDLE_TIME << R_ADC_C_ADM3_ADIL_Pos);

    /* Set the conversion period and sampling period. */
    adm3 |= (uint32_t) (BSP_FEATURE_ADC_C_CONVERSION_TIME << R_ADC_C_ADM3_ADCMP_Pos);
    adm3 |= (uint32_t) (p_cfg_extend->sampling_time << R_ADC_C_ADM3_ADSMP_Pos);

    /* Apply clock to peripheral. */
    R_BSP_MODULE_START(FSP_IP_ADC, 0);

    /* The following series of steps refer to "A/D conversion start procedure" in the user's manual. */
    /* Release from software reset state. */
    uint32_t adm0 = (uint32_t) (1 << R_ADC_C_ADM0_SRESB_Pos);
    p_instance_ctrl->p_reg->ADM0 = adm0;

    /* The waiting time until the reset state of the A/D converter is released is 2 × ADC_ADCLK(TSUϕ) (80 MHz),
     * but since the minimum waiting time of R_BSP_SoftwareDelay is 1us,
     * processing is executed with a waiting time of 1us. */
    R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);

    /* Clear the interrupt cause flag and trigger detection flag.  */
    uint32_t adsts = (uint32_t) (1 << R_ADC_C_ADSTS_TRGS_Pos);
    adsts |= (uint32_t) (BSP_FEATURE_ADC_C_VALID_CHANNEL_MASK << R_ADC_C_ADSTS_INTST_Pos);
    p_instance_ctrl->p_reg->ADSTS = adsts;

    /* Set the predetermined values for ADM1, ADM3, ADINT, ADIVC, and ADFIL.
     * ADM0.ADCE are set as configured in R_ADC_ScanStart. */
    p_instance_ctrl->p_reg->ADM1 = adm1;
    p_instance_ctrl->p_reg->ADM3 = adm3;
#if BSP_FEATURE_ADC_C_HAS_ADIVC
    p_instance_ctrl->p_reg->ADIVC = adivc;
#endif
    p_instance_ctrl->p_reg->ADFIL = adfil;

    /* Change from power-saving mode to normal mode. */
    adm0 |= (uint32_t) (1 << R_ADC_C_ADM0_PWDWNB_Pos);
    p_instance_ctrl->p_reg->ADM0 = adm0;

    /* Secure the A/D converter stabilization wait time. */
    R_BSP_SoftwareDelay(ADC_C_STABILIZATION_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);

    /* Set the ADCE bit. */
    adm0 |= (uint32_t) (R_ADC_C_ADM0_ADCE_Msk);

    p_instance_ctrl->scan_start = adm0;

    /* Save the operating mode and buffer mode locally; this is required for the Scancfg function. */
    p_instance_ctrl->operating_mode = p_cfg_extend->operating_mode;
    p_instance_ctrl->buffer_mode    = p_cfg_extend->buffer_mode;
}

/*******************************************************************************************************************//**
 * This function does extensive checking on channel mask settings based upon operational mode. Mask registers are
 * initialized and interrupts enabled in peripheral. Interrupts are also enabled in ICU if corresponding priority
 * is not 0.
 *
 * @param[in]  p_instance_ctrl         Pointer to instance control block
 * @param[in]  p_channel_cfg           Pointer to channel configuration
 **********************************************************************************************************************/
static void r_adc_c_scan_cfg (adc_c_instance_ctrl_t * const     p_instance_ctrl,
                              adc_c_channel_cfg_t const * const p_channel_cfg)
{
    if (p_channel_cfg->scan_mask & ADC_C_MASK_CHANNEL_8)
    {
#if BSP_FEATURE_ADC_C_TSU_CONTROL_AVAILABLE

        /* Apply clock to peripheral. */
        R_BSP_MODULE_START(FSP_IP_TSU, 0);

        /* Set the temperature sensor to place in the normal operating mode. */
        R_TSU->TSU_SM = R_TSU_TSU_SM_EN_Msk;

        /* Wait 30us. See the TSU "Operation" section of the RZ microprocessor manual. */
        R_BSP_SoftwareDelay(BSP_FEATURE_ADC_C_TSU_ENABLE_STABILIZATION_TIME_US, BSP_DELAY_UNITS_MICROSECONDS);

        /* Enable the temperature sensor. */
        R_TSU->TSU_SM |= R_TSU_TSU_SM_OE_Msk;

        /* Wait 1000us. See the TSU "Operation" section of the RZ microprocessor manual. */
        R_BSP_SoftwareDelay(BSP_FEATURE_ADC_C_TSU_START_STABILIZATION_TIME_MS, BSP_DELAY_UNITS_MILLISECONDS);
#endif
    }

    /* Set mask for channels. */
    p_instance_ctrl->p_reg->ADM2 = (uint32_t) (p_channel_cfg->scan_mask & (uint32_t) R_ADC_C_ADM2_CHSEL_Msk);

    /* Disables the A/D conversion channel select error interrupt. */
    uint32_t adint = (uint32_t) (0 << R_ADC_C_ADINT_CSEEN_Pos);

    /* Enable or disable the conversion end interrupt of channel n (n = 0 to 3). */
    if (ADC_C_INTERRUPT_CHANNEL_SETTING_ENABLE == p_channel_cfg->interrupt_setting)
    {
        /* Channel 3 interrupt output is enabled in 4-buffer mode.
         * Reference section "Example of A/D Conversion in 4-Buffer Mode" of the user's manual.*/
        if (ADC_C_BUFFER_MODE_4 == p_instance_ctrl->buffer_mode)
        {
            if (p_channel_cfg->scan_mask & ADC_C_4_BUFFER_CHANNEL_MASK)
            {
                adint |= (uint32_t) (R_ADC_C_ADCR0_AD3_Msk << R_ADC_C_ADINT_INTEN_Pos);
            }
            else if (p_channel_cfg->scan_mask & (ADC_C_4_BUFFER_CHANNEL_MASK << 4))
            {
                adint |= (uint32_t) (R_ADC_C_ADCR0_AD7_Msk << R_ADC_C_ADINT_INTEN_Pos);
            }
            else
            {
                adint |= (uint32_t) (R_ADC_C_ADCR0_AD11_Msk << R_ADC_C_ADINT_INTEN_Pos);
            }
        }
        else
        {
            uint32_t adc_mask_in_order = p_channel_cfg->scan_mask;

            /* Determine the highest channel that is configured. */
            uint32_t highest_channel = r_adc_c_highest_channel_get(adc_mask_in_order);

            /* Highest channel interrupt output is enabled. */
            adint |= (uint32_t) (1U << highest_channel);
        }
    }
    else
    {
        /* Do nothing. */
    }

    p_instance_ctrl->p_reg->ADINT = adint;

    p_instance_ctrl->initialized = ADC_C_OPEN;
}

/*******************************************************************************************************************//**
 * Disables and clears context for the requested IRQ.
 *
 * @param[in]  irq        IRQ to enable
 * @param[in]  ipl        Interrupt priority
 * @param[in]  p_context  Pointer to interrupt context
 **********************************************************************************************************************/
static void r_adc_c_irq_enable (IRQn_Type irq, uint8_t ipl, void * p_context)
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
static void r_adc_c_irq_disable (IRQn_Type irq)
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
static uint32_t r_adc_c_lowest_channel_get (uint32_t adc_mask)
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
 * Returns the highest channel index that is configured  in order to read the results of the configured channels.
 *
 * @param[in]  adc_mask  scan mask of active channels retrieved from the control structure
 *
 * @retval  adc_mask_count  index value of highest channel
 **********************************************************************************************************************/
static uint32_t r_adc_c_highest_channel_get (uint32_t adc_mask)
{
    /* Initialize the mask result */
    uint32_t adc_mask_result = 0U;
    int32_t  adc_mask_count  = 31;
    while (0U == adc_mask_result)
    {
        /* Decrement channel until a channel is found in the mask. */
        adc_mask_count--;
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
static void r_adc_c_call_callback (adc_c_instance_ctrl_t * p_ctrl, adc_callback_args_t * p_args)
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
 * This function implements interrupt handler for scan complete.
 **********************************************************************************************************************/
void adc_c_scan_end_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type               irq             = R_FSP_CurrentIrqGet();
    adc_c_instance_ctrl_t * p_instance_ctrl = (adc_c_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    adc_c_extended_cfg_t  * p_extend        = (adc_c_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Clear the BSP IRQ Flag     */
    R_BSP_IrqStatusClear(irq);

    adc_callback_args_t args;
    args.event = ADC_EVENT_SCAN_COMPLETE;

    /* Populate the context field. */
    args.p_context = p_instance_ctrl->p_context;

    uint32_t adsts = 0;

    /* Clear the trigger detection flag.  */
    if (ADC_C_TRIGGER_MODE_HARDWARE == p_extend->trigger_mode)
    {
        adsts = (uint32_t) (1 << R_ADC_C_ADSTS_TRGS_Pos);
    }

    /* Clear the interrupt cause flag.  */
    adsts |= (uint32_t) (R_ADC_C_ADSTS_INTST_Msk << R_ADC_C_ADSTS_INTST_Pos);
    p_instance_ctrl->p_reg->ADSTS = adsts;

    /* Dummy read the ADSTS bit. */
    volatile uint32_t dummy = p_instance_ctrl->p_reg->ADSTS;
    FSP_PARAMETER_NOT_USED(dummy);

    /* Initialize the unit to 0.  It is not used in this implementation. */
    args.unit = 0U;

    /* Initialize the channel to 0.  It is not used in this implementation. */
    args.channel = ADC_CHANNEL_0;

    /* If a callback was provided, call it with the argument */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_adc_c_call_callback(p_instance_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}
