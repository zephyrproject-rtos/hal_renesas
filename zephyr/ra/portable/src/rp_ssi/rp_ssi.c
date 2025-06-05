/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_i2s_api.h"
#include "r_ssi.h"
#include "rp_ssi.h"
#include "r_ssi_cfg.h"
#if SSI_CFG_DTC_ENABLE
 #include "r_dtc.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define SSI_PRV_SSIFCR_AUCKE_BIT           (31U)
#define SSI_PRV_SSIFCR_SSIRST_BIT          (16U)

#define SSI_PRV_SSICR_CKS_BIT              (30U)
#define SSI_PRV_SSICR_SWL_BIT              (16U)
#define SSI_PRV_SSICR_DWL_BIT              (19U)
#define SSI_PRV_SSICR_MST_BIT              (14U)
#define SSI_PRV_SSICR_PDTA_BIT             (9U)
#define SSI_PRV_SSICR_CKDV_BIT             (4U)

#define SSI_PRV_SSIOFR_LRCONT_BIT          (8U)
#define SSI_PRV_TRANSFER_BLOCK_SIZE        (2U)

/* "SSI" in ASCII, used to determine if driver is open. */
#define SSI_PRV_OPEN                       (0x535349U)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/* Open subroutines */


#if SSI_CFG_DTC_ENABLE
static fsp_err_t r_ssi_dependent_drivers_configure(R_SSI0_Type           * p_reg,
                                                   i2s_cfg_t const * const p_cfg,
                                                   transfer_size_t         fifo_access_size);

#endif



/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup SSI
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Opens the SSI. Implements @ref i2s_api_t::open.
 *
 * This function sets this clock divisor and the configurations specified in i2s_cfg_t.  It also opens the timer and
 * transfer instances if they are provided.
 *
 * @retval FSP_SUCCESS                     Ready for I2S communication.
 * @retval FSP_ERR_ASSERTION               The pointer to p_ctrl or p_cfg is null.
 * @retval FSP_ERR_ALREADY_OPEN            The control block has already been opened.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Channel number is not available on this MCU.
 * @return                                 See @ref RENESAS_ERROR_CODES or functions called by this function for other
 *                                         possible return codes.
 **********************************************************************************************************************/
fsp_err_t RP_SSI_Reconfigure (i2s_ctrl_t * const p_ctrl, i2s_cfg_t const * const p_cfg)
{
    ssi_instance_ctrl_t * p_instance_ctrl = (ssi_instance_ctrl_t *) p_ctrl;

#if BSP_FEATURE_SSI_VALID_CHANNEL_MASK == 1
    uint32_t base_address = (uint32_t) R_SSI0;
#else

    /* Calculate base address for registers on this channel. */
    uint32_t base_address = (uint32_t) R_SSI0 + (p_cfg->channel * ((uint32_t) R_SSI1 - (uint32_t) R_SSI0));
#endif
    R_SSI0_Type * p_reg = (R_SSI0_Type *) base_address;

    /* Determine how to access the FIFO (1 byte, 2 byte, or 4 byte access). */
    transfer_size_t fifo_access_size = TRANSFER_SIZE_4_BYTE;
    if (I2S_PCM_WIDTH_8_BITS == p_cfg->pcm_width)
    {
        fifo_access_size = TRANSFER_SIZE_1_BYTE;
    }

    if (I2S_PCM_WIDTH_16_BITS == p_cfg->pcm_width)
    {
        fifo_access_size = TRANSFER_SIZE_2_BYTE;
    }

#if SSI_CFG_DTC_ENABLE

    /* Configure dependent timer and transfer drivers. */
    fsp_err_t err = r_ssi_dependent_drivers_configure(p_reg, p_cfg, fifo_access_size);
    FSP_ERROR_RETURN((FSP_SUCCESS == err), err);
#endif

    /* Initialize the control structure. */
    p_instance_ctrl->p_reg            = p_reg;
    p_instance_ctrl->p_cfg            = p_cfg;
    p_instance_ctrl->fifo_access_size = fifo_access_size;

    /* Configure operating mode. */
    uint32_t ssifcr = (uint32_t) p_cfg->operating_mode << SSI_PRV_SSIFCR_AUCKE_BIT;
    uint32_t ssicr  = (uint32_t) p_cfg->operating_mode << SSI_PRV_SSICR_MST_BIT;

    /* Configure sample size, and word length. */
    ssicr |= (uint32_t) p_cfg->word_length << SSI_PRV_SSICR_SWL_BIT;
    ssicr |= (uint32_t) p_cfg->pcm_width << SSI_PRV_SSICR_DWL_BIT;
    if ((p_cfg->pcm_width > I2S_PCM_WIDTH_16_BITS) && (p_cfg->pcm_width < I2S_PCM_WIDTH_32_BITS))
    {
        /* Right justify data for 18-bit, 20-bit, 22-bit, or 24-bit samples. This setting is prohibited for 8-bit,
         * 16-bit, and 32-bit samples  */
        ssicr |= (1U << SSI_PRV_SSICR_PDTA_BIT);
    }

    /* Configure audio clock and WS continue in master mode only. */
    uint32_t ssiofr = 0U;
    if (I2S_MODE_MASTER == p_cfg->operating_mode)
    {
        ssi_extended_cfg_t * p_extend = (ssi_extended_cfg_t *) p_cfg->p_extend;
        ssicr |= (uint32_t) p_extend->bit_clock_div << SSI_PRV_SSICR_CKDV_BIT;
        ssicr |= (uint32_t) p_extend->audio_clock << SSI_PRV_SSICR_CKS_BIT;

        if (I2S_WS_CONTINUE_ON == p_cfg->ws_continue)
        {
            ssiofr |= (1U << SSI_PRV_SSIOFR_LRCONT_BIT);
        }
    }

    /* Set SSIE receive FIFO watermark to exactly the DTC block size so the DTC triggers as soon as there is
     * a block of data in the FIFO. */
    uint32_t rx_fifo_setting = SSI_PRV_TRANSFER_BLOCK_SIZE - 1U;

    /* Set SSIE transmit FIFO watermark to trigger when 1/2 of the FIFO is empty so that read and write are less
     * likely to trigger at the same time. */
    uint32_t tx_fifo_setting = (BSP_FEATURE_SSI_FIFO_NUM_STAGES / 2U) - 1U;
    uint32_t ssiscr          = (tx_fifo_setting << 8) | rx_fifo_setting;

    /* Initialize the SSIE following the procedure in Figure 41.53 "Procedure to start communication (CPU operation
     * procedure)" of the RA6M3 manual R01UH0886EJ0100. This function follows this procedure except for enabling
     * interrupts and enabling communication, which are done before communication begins. */


    /* Configure master/slave mode and associated clock settings for master mode. */
    p_instance_ctrl->p_reg->SSICR = ssicr;

    /* Reset SSIE and set operating mode. Set SSIRST, then clear it and wait for it to clear. This operation resets
     * all interrupt flags in SSISR and empties the FIFOs. */
    p_instance_ctrl->p_reg->SSIFCR = ssifcr | (1U << SSI_PRV_SSIFCR_SSIRST_BIT);
    p_instance_ctrl->p_reg->SSIFCR = ssifcr;

    /* Wait for SSIRST to clear before continuing.  Reference SSIRST in section 41.4.3 "FIFO Control Register (SSIFCR)"
     * of the RA6M3 manual R01UH0886EJ0100. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->SSIFCR, ssifcr);

    p_instance_ctrl->p_reg->SSISCR = ssiscr;
    p_instance_ctrl->p_reg->SSIOFR = ssiofr;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Opens the SSI. Implements @ref i2s_api_t::open.
 *
 * This function sets this clock divisor and the configurations specified in i2s_cfg_t.  It also opens the timer and
 * transfer instances if they are provided.
 *
 * @retval FSP_SUCCESS                     Ready for I2S communication.
 * @retval FSP_ERR_ASSERTION               The pointer to p_ctrl or p_cfg is null.
 * @retval FSP_ERR_ALREADY_OPEN            The control block has already been opened.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Channel number is not available on this MCU.
 * @return                                 See @ref RENESAS_ERROR_CODES or functions called by this function for other
 *                                         possible return codes. This function calls:
 *                                             * @ref transfer_api_t::open
 **********************************************************************************************************************/
fsp_err_t RP_SSI_Open (i2s_ctrl_t * const p_ctrl, i2s_cfg_t const * const p_cfg)
{
    ssi_instance_ctrl_t * p_instance_ctrl = (ssi_instance_ctrl_t *) p_ctrl;

#if SSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_callback);
    FSP_ASSERT(p_cfg->int_irq >= 0);
    if (I2S_MODE_MASTER == p_cfg->operating_mode)
    {
        FSP_ASSERT(NULL != p_cfg->p_extend);
    }

 #if SSI_CFG_DTC_ENABLE
    if (NULL != p_cfg->p_transfer_rx)
    {
        dtc_extended_cfg_t * p_dtc_rx_cfg = (dtc_extended_cfg_t *) p_cfg->p_transfer_rx->p_cfg->p_extend;
        FSP_ASSERT(NULL != p_dtc_rx_cfg);
        FSP_ASSERT(p_cfg->rxi_irq == p_dtc_rx_cfg->activation_source);
    }

    if (NULL != p_cfg->p_transfer_tx)
    {
        dtc_extended_cfg_t * p_dtc_tx_cfg = (dtc_extended_cfg_t *) p_cfg->p_transfer_tx->p_cfg->p_extend;
        FSP_ASSERT(NULL != p_dtc_tx_cfg);
        FSP_ASSERT(p_cfg->txi_irq == p_dtc_tx_cfg->activation_source);
    }
 #endif

    FSP_ERROR_RETURN(SSI_PRV_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ERROR_RETURN(0U != ((1U << p_cfg->channel) & BSP_FEATURE_SSI_VALID_CHANNEL_MASK),
                     FSP_ERR_IP_CHANNEL_NOT_PRESENT);
#endif

#if BSP_FEATURE_SSI_VALID_CHANNEL_MASK == 1
    uint32_t base_address = (uint32_t) R_SSI0;
#else

    /* Calculate base address for registers on this channel. */
    uint32_t base_address = (uint32_t) R_SSI0 + (p_cfg->channel * ((uint32_t) R_SSI1 - (uint32_t) R_SSI0));
#endif
    R_SSI0_Type * p_reg = (R_SSI0_Type *) base_address;

    /* Determine how to access the FIFO (1 byte, 2 byte, or 4 byte access). */
    transfer_size_t fifo_access_size = TRANSFER_SIZE_4_BYTE;
    if (I2S_PCM_WIDTH_8_BITS == p_cfg->pcm_width)
    {
        fifo_access_size = TRANSFER_SIZE_1_BYTE;
    }

    if (I2S_PCM_WIDTH_16_BITS == p_cfg->pcm_width)
    {
        fifo_access_size = TRANSFER_SIZE_2_BYTE;
    }

#if SSI_CFG_DTC_ENABLE

    /* Configure dependent timer and transfer drivers. */
    fsp_err_t err = r_ssi_dependent_drivers_configure(p_reg, p_cfg, fifo_access_size);
    FSP_ERROR_RETURN((FSP_SUCCESS == err), err);
#endif

    /* Initialize the control structure. */
    p_instance_ctrl->p_reg            = p_reg;
    p_instance_ctrl->p_cfg            = p_cfg;
    p_instance_ctrl->fifo_access_size = fifo_access_size;

    /* Configure operating mode. */
    uint32_t ssifcr = (uint32_t) p_cfg->operating_mode << SSI_PRV_SSIFCR_AUCKE_BIT;
    uint32_t ssicr  = (uint32_t) p_cfg->operating_mode << SSI_PRV_SSICR_MST_BIT;

    /* Configure sample size, and word length. */
    ssicr |= (uint32_t) p_cfg->word_length << SSI_PRV_SSICR_SWL_BIT;
    ssicr |= (uint32_t) p_cfg->pcm_width << SSI_PRV_SSICR_DWL_BIT;
    if ((p_cfg->pcm_width > I2S_PCM_WIDTH_16_BITS) && (p_cfg->pcm_width < I2S_PCM_WIDTH_32_BITS))
    {
        /* Right justify data for 18-bit, 20-bit, 22-bit, or 24-bit samples. This setting is prohibited for 8-bit,
         * 16-bit, and 32-bit samples  */
        ssicr |= (1U << SSI_PRV_SSICR_PDTA_BIT);
    }

    /* Configure audio clock and WS continue in master mode only. */
    uint32_t ssiofr = 0U;
    if (I2S_MODE_MASTER == p_cfg->operating_mode)
    {
        ssi_extended_cfg_t * p_extend = (ssi_extended_cfg_t *) p_cfg->p_extend;
        ssicr |= (uint32_t) p_extend->bit_clock_div << SSI_PRV_SSICR_CKDV_BIT;
        ssicr |= (uint32_t) p_extend->audio_clock << SSI_PRV_SSICR_CKS_BIT;

        if (I2S_WS_CONTINUE_ON == p_cfg->ws_continue)
        {
            ssiofr |= (1U << SSI_PRV_SSIOFR_LRCONT_BIT);
        }
    }

    /* Set SSIE receive FIFO watermark to exactly the DTC block size so the DTC triggers as soon as there is
     * a block of data in the FIFO. */
    uint32_t rx_fifo_setting = SSI_PRV_TRANSFER_BLOCK_SIZE - 1U;

    /* Set SSIE transmit FIFO watermark to trigger when 1/2 of the FIFO is empty so that read and write are less
     * likely to trigger at the same time. */
    uint32_t tx_fifo_setting = (BSP_FEATURE_SSI_FIFO_NUM_STAGES / 2U) - 1U;
    uint32_t ssiscr          = (tx_fifo_setting << 8) | rx_fifo_setting;

    /* Initialize the SSIE following the procedure in Figure 41.53 "Procedure to start communication (CPU operation
     * procedure)" of the RA6M3 manual R01UH0886EJ0100. This function follows this procedure except for enabling
     * interrupts and enabling communication, which are done before communication begins. */

    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Configure master/slave mode and associated clock settings for master mode. */
    p_instance_ctrl->p_reg->SSICR = ssicr;

    /* Reset SSIE and set operating mode. Set SSIRST, then clear it and wait for it to clear. This operation resets
     * all interrupt flags in SSISR and empties the FIFOs. */
    p_instance_ctrl->p_reg->SSIFCR = ssifcr | (1U << SSI_PRV_SSIFCR_SSIRST_BIT);
    p_instance_ctrl->p_reg->SSIFCR = ssifcr;

    /* Wait for SSIRST to clear before continuing.  Reference SSIRST in section 41.4.3 "FIFO Control Register (SSIFCR)"
     * of the RA6M3 manual R01UH0886EJ0100. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->SSIFCR, ssifcr);

    p_instance_ctrl->p_reg->SSISCR = ssiscr;
    p_instance_ctrl->p_reg->SSIOFR = ssiofr;

    /* Initialization complete. */
    p_instance_ctrl->open = SSI_PRV_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Closes SSI. Implements @ref i2s_api_t::close.
 *
 * This function powers down the SSI and closes the lower level timer and transfer drivers if they are used.
 *
 * @retval FSP_SUCCESS           Device closed successfully.
 * @retval FSP_ERR_ASSERTION     The pointer to p_ctrl was null.
 * @retval FSP_ERR_NOT_OPEN      The channel is not opened.
 **********************************************************************************************************************/
fsp_err_t RP_SSI_Close (i2s_ctrl_t * const p_ctrl)
{
    ssi_instance_ctrl_t * p_instance_ctrl = (ssi_instance_ctrl_t *) p_ctrl;
#if SSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(SSI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_instance_ctrl->open = 0U;

    /* Stop SSIE. */
    p_instance_ctrl->p_reg->SSICR  = 0U;
    p_instance_ctrl->p_reg->SSIFCR = 0U;

#if SSI_CFG_DTC_ENABLE

    /* If transfer is used, disable transfer when stop is requested. */
    if (NULL != p_instance_ctrl->p_cfg->p_transfer_rx)
    {
        (void) p_instance_ctrl->p_cfg->p_transfer_rx->p_api->close(p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl);
    }

    if (NULL != p_instance_ctrl->p_cfg->p_transfer_tx)
    {
        (void) p_instance_ctrl->p_cfg->p_transfer_tx->p_api->close(p_instance_ctrl->p_cfg->p_transfer_tx->p_ctrl);
    }
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup R_SSI)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if SSI_CFG_DTC_ENABLE

/*******************************************************************************************************************//**
 * Configures any dependent drivers selected by the user, including transfer and timer drivers.
 *
 * @param[in] p_reg                    Pointer to SSIE base register address for this channel.
 * @param[in] p_cfg                    Pointer to the configuration structure.
 *
 * @retval FSP_SUCCESS                 Dependent drivers configured successfully.
 * @return                             See @ref RENESAS_ERROR_CODES or functions called by this function for other
 *                                     possible return codes. This function calls:
 *                                         * @ref transfer_api_t::open
 **********************************************************************************************************************/
static fsp_err_t r_ssi_dependent_drivers_configure (R_SSI0_Type           * p_reg,
                                                    i2s_cfg_t const * const p_cfg,
                                                    transfer_size_t         fifo_access_size)
{
    /* Prepare transfer configuration. */
    fsp_err_t err_transfer_tx = FSP_SUCCESS;
    fsp_err_t err_transfer_rx = FSP_SUCCESS;

    /* Use block mode to fill or empty half the FIFO at a time. Reference Figure 41.53 "Procedure to start
     * communication (CPU operation procedure)" in the RA6M3 manual R01UH0886EJ0100. */
    uint32_t transfer_settings = (uint32_t) TRANSFER_MODE_BLOCK << TRANSFER_SETTINGS_MODE_BITS;
    transfer_settings |= (uint32_t) fifo_access_size << TRANSFER_SETTINGS_SIZE_BITS;

    /* If a transfer instance is provided for write, open the transfer instance. */
    if (NULL != p_cfg->p_transfer_tx)
    {
        p_cfg->p_transfer_tx->p_cfg->p_info->p_dest = (void *) &(p_reg->SSIFTDR);
        uint32_t transfer_settings_tx = transfer_settings |
                                        (TRANSFER_ADDR_MODE_INCREMENTED << TRANSFER_SETTINGS_SRC_ADDR_BITS);
        p_cfg->p_transfer_tx->p_cfg->p_info->transfer_settings_word = transfer_settings_tx;
        p_cfg->p_transfer_tx->p_cfg->p_info->length                 = SSI_PRV_TRANSFER_BLOCK_SIZE;
        err_transfer_tx = p_cfg->p_transfer_tx->p_api->open(p_cfg->p_transfer_tx->p_ctrl, p_cfg->p_transfer_tx->p_cfg);
    }

 #if  SSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN((FSP_SUCCESS == err_transfer_tx), err_transfer_tx);
 #else
    FSP_PARAMETER_NOT_USED(err_transfer_tx);
 #endif

    /* If a transfer instance is provided for read, open the transfer instance. */
    if (NULL != p_cfg->p_transfer_rx)
    {
        p_cfg->p_transfer_rx->p_cfg->p_info->p_src = (void *) &(p_reg->SSIFRDR);
        uint32_t transfer_settings_rx = transfer_settings |
                                        (TRANSFER_ADDR_MODE_INCREMENTED << TRANSFER_SETTINGS_DEST_ADDR_BITS) |
                                        (TRANSFER_REPEAT_AREA_SOURCE << TRANSFER_SETTINGS_REPEAT_AREA_BITS);
        p_cfg->p_transfer_rx->p_cfg->p_info->transfer_settings_word = transfer_settings_rx;
        p_cfg->p_transfer_rx->p_cfg->p_info->length                 = SSI_PRV_TRANSFER_BLOCK_SIZE;
        err_transfer_rx = p_cfg->p_transfer_rx->p_api->open(p_cfg->p_transfer_rx->p_ctrl, p_cfg->p_transfer_rx->p_cfg);
    }

 #if  SSI_CFG_PARAM_CHECKING_ENABLE

    /* If there was an error opening the receive transfer, close the transmit transfer before returning. */
    if (FSP_SUCCESS != err_transfer_rx)
    {
        if (NULL != p_cfg->p_transfer_tx)
        {
            p_cfg->p_transfer_tx->p_api->close(p_cfg->p_transfer_tx->p_ctrl);
        }
    }

    FSP_ERROR_RETURN((FSP_SUCCESS == err_transfer_rx), err_transfer_rx);
 #else
    FSP_PARAMETER_NOT_USED(err_transfer_rx);
 #endif

    return FSP_SUCCESS;
}

#endif
