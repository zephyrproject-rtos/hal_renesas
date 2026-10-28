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

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* SSIOFR.OMOD value of the monaural format. */
#define RP_SSI_PRV_SSIOFR_OMOD_MONAURAL    (2U)

/* Number of words a transfer moves per request in the monaural format. */
#define RP_SSI_PRV_MONAURAL_TRANSFER_BLOCK_SIZE    (1U)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
#if SSI_CFG_DTC_ENABLE
static fsp_err_t rp_ssi_transfer_reopen(transfer_instance_t const * const p_transfer);
static bool      rp_ssi_monaural(ssi_instance_ctrl_t * const p_instance_ctrl);
static void      rp_ssi_monaural_state_set(ssi_instance_ctrl_t * const p_instance_ctrl,
                                           void const * const          p_src,
                                           void * const                p_dest,
                                           uint32_t const              bytes);

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
 * Opens the SSI with the selected audio format.
 *
 * This function calls @ref R_SSI_Open, which leaves the SSIE stopped and configured for the I2S format. For the
 * monaural format it then sets SSIOFR.OMOD to the monaural format, SSICR.BCKP to change the data on the rising edge
 * of the bit clock, SSICR.LRCKP so that the frame sync idles low and a frame starts on its rising edge, and SSICR.DEL
 * to select the short frame (DEL = 0) or the long frame (DEL = 1). SSICR.FRM stays 0
 * (one word per frame in the monaural format). These bits are written while the SSIE is idle, as required by the
 * SSICR and SSIOFR descriptions in the SSIE section of the relevant hardware manual.
 *
 * In the monaural format a block can hold an odd number of words. SSISCR.RDFS is set so that one received word raises
 * the receive interrupt, and the transfer instances are reopened to move one word per request. Start transfers with
 * @ref RP_SSI_Write, @ref RP_SSI_Read and @ref RP_SSI_WriteRead.
 *
 * Close the SSI with @ref R_SSI_Close.
 *
 * @retval FSP_SUCCESS                     Ready for communication.
 * @retval FSP_ERR_ASSERTION               The audio format is not supported.
 * @return                                 See @ref R_SSI_Open and @ref transfer_api_t::open for other possible return
 *                                         codes.
 **********************************************************************************************************************/
fsp_err_t RP_SSI_Open (i2s_ctrl_t * const p_ctrl, i2s_cfg_t const * const p_cfg, rp_ssi_audio_format_t format)
{
    ssi_instance_ctrl_t * p_instance_ctrl = (ssi_instance_ctrl_t *) p_ctrl;

#if SSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT((RP_SSI_AUDIO_FORMAT_I2S == format) || (RP_SSI_AUDIO_FORMAT_MONAURAL_SHORT_FRAME == format) ||
               (RP_SSI_AUDIO_FORMAT_MONAURAL_LONG_FRAME == format));
#endif

    fsp_err_t err = R_SSI_Open(p_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    if (RP_SSI_AUDIO_FORMAT_I2S != format)
    {
        uint32_t ssicr = p_instance_ctrl->p_reg->SSICR;
        ssicr &= ~(R_SSI0_SSICR_DEL_Msk | R_SSI0_SSICR_FRM_Msk);
        ssicr |= R_SSI0_SSICR_BCKP_Msk | R_SSI0_SSICR_LRCKP_Msk;
        if (RP_SSI_AUDIO_FORMAT_MONAURAL_LONG_FRAME == format)
        {
            ssicr |= R_SSI0_SSICR_DEL_Msk;
        }

        uint32_t ssiofr = p_instance_ctrl->p_reg->SSIOFR;
        ssiofr &= ~R_SSI0_SSIOFR_OMOD_Msk;
        ssiofr |= RP_SSI_PRV_SSIOFR_OMOD_MONAURAL << R_SSI0_SSIOFR_OMOD_Pos;

        p_instance_ctrl->p_reg->SSICR  = ssicr;
        p_instance_ctrl->p_reg->SSIOFR = ssiofr;

        /* Raise the receive data full flag at one word so that the last word of a block with an odd number of words
         * also generates the receive interrupt. */
        p_instance_ctrl->p_reg->SSISCR &= ~R_SSI0_SSISCR_RDFS_Msk;

#if SSI_CFG_DTC_ENABLE

        /* R_SSI_Open opened the transfers to move two words per request. Reopen them to move one word, so that a block
         * can hold an odd number of words. */
        err = rp_ssi_transfer_reopen(p_cfg->p_transfer_tx);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        err = rp_ssi_transfer_reopen(p_cfg->p_transfer_rx);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Writes data buffer to SSI. Calls @ref R_SSI_Write.
 *
 * R_SSI_Write sizes the transmit transfer for two words per request. In the monaural format the transfer moves one
 * word per request, so this function passes twice the length to R_SSI_Write and the transfer moves every word of the
 * buffer. Interrupts are disabled until the ISR state is set.
 *
 * @retval FSP_SUCCESS                 Write initiated successfully.
 * @return                             See @ref R_SSI_Write for other possible return codes.
 **********************************************************************************************************************/
fsp_err_t RP_SSI_Write (i2s_ctrl_t * const p_ctrl, void const * const p_src, uint32_t const bytes)
{
#if SSI_CFG_DTC_ENABLE
    ssi_instance_ctrl_t * p_instance_ctrl = (ssi_instance_ctrl_t *) p_ctrl;

    if (!rp_ssi_monaural(p_instance_ctrl))
    {
        return R_SSI_Write(p_ctrl, p_src, bytes);
    }

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    fsp_err_t err = R_SSI_Write(p_ctrl, p_src, bytes << 1);
    if (FSP_SUCCESS == err)
    {
        rp_ssi_monaural_state_set(p_instance_ctrl, p_src, NULL, bytes);
    }

    FSP_CRITICAL_SECTION_EXIT;

    return err;
#else

    return R_SSI_Write(p_ctrl, p_src, bytes);
#endif
}

/*******************************************************************************************************************//**
 * Reads data into provided buffer. Calls @ref R_SSI_Read.
 *
 * R_SSI_Read sizes the receive transfer for two words per request and leaves the last two words to the receive ISR.
 * In the monaural format the transfer moves one word per request, so this function passes twice the length to
 * R_SSI_Read: the transfer moves all but the last word, and the receive ISR reads the last word, so that a buffer of
 * any number of words completes with I2S_EVENT_RX_FULL. Interrupts are disabled until the ISR state is set.
 *
 * @retval FSP_SUCCESS                 Read initiated successfully.
 * @return                             See @ref R_SSI_Read for other possible return codes.
 **********************************************************************************************************************/
fsp_err_t RP_SSI_Read (i2s_ctrl_t * const p_ctrl, void * const p_dest, uint32_t const bytes)
{
#if SSI_CFG_DTC_ENABLE
    ssi_instance_ctrl_t * p_instance_ctrl = (ssi_instance_ctrl_t *) p_ctrl;

    if (!rp_ssi_monaural(p_instance_ctrl))
    {
        return R_SSI_Read(p_ctrl, p_dest, bytes);
    }

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    fsp_err_t err = R_SSI_Read(p_ctrl, p_dest, bytes << 1);
    if (FSP_SUCCESS == err)
    {
        rp_ssi_monaural_state_set(p_instance_ctrl, NULL, p_dest, bytes);
    }

    FSP_CRITICAL_SECTION_EXIT;

    return err;
#else

    return R_SSI_Read(p_ctrl, p_dest, bytes);
#endif
}

/*******************************************************************************************************************//**
 * Writes from source buffer and reads data into destination buffer. Calls @ref R_SSI_WriteRead.
 *
 * In the monaural format, passes twice the length to R_SSI_WriteRead as @ref RP_SSI_Write and @ref RP_SSI_Read do.
 *
 * @retval FSP_SUCCESS                 Write and read initiated successfully.
 * @return                             See @ref R_SSI_WriteRead for other possible return codes.
 **********************************************************************************************************************/
fsp_err_t RP_SSI_WriteRead (i2s_ctrl_t * const p_ctrl,
                            void const * const p_src,
                            void * const       p_dest,
                            uint32_t const     bytes)
{
#if SSI_CFG_DTC_ENABLE
    ssi_instance_ctrl_t * p_instance_ctrl = (ssi_instance_ctrl_t *) p_ctrl;

    if (!rp_ssi_monaural(p_instance_ctrl))
    {
        return R_SSI_WriteRead(p_ctrl, p_src, p_dest, bytes);
    }

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    fsp_err_t err = R_SSI_WriteRead(p_ctrl, p_src, p_dest, bytes << 1);
    if (FSP_SUCCESS == err)
    {
        rp_ssi_monaural_state_set(p_instance_ctrl, p_src, p_dest, bytes);
    }

    FSP_CRITICAL_SECTION_EXIT;

    return err;
#else

    return R_SSI_WriteRead(p_ctrl, p_src, p_dest, bytes);
#endif
}

/*******************************************************************************************************************//**
 * @} (end addtogroup SSI)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
#if SSI_CFG_DTC_ENABLE

/*******************************************************************************************************************//**
 * Reopens a transfer instance to move one word per request.
 *
 * @param[in] p_transfer               Transfer instance, or NULL if the direction does not use a transfer.
 *
 * @retval FSP_SUCCESS                 The transfer is reopened, or no transfer instance is used.
 * @return                             See @ref transfer_api_t::open for other possible return codes.
 **********************************************************************************************************************/
static fsp_err_t rp_ssi_transfer_reopen (transfer_instance_t const * const p_transfer)
{
    if (NULL == p_transfer)
    {
        return FSP_SUCCESS;
    }

    (void) p_transfer->p_api->close(p_transfer->p_ctrl);
    p_transfer->p_cfg->p_info->length = RP_SSI_PRV_MONAURAL_TRANSFER_BLOCK_SIZE;

    return p_transfer->p_api->open(p_transfer->p_ctrl, p_transfer->p_cfg);
}

/*******************************************************************************************************************//**
 * Checks whether the SSIE uses the monaural format.
 *
 * @param[in] p_instance_ctrl          Pointer to the control block.
 *
 * @retval true                        SSIOFR.OMOD selects the monaural format.
 * @retval false                       Any other format.
 **********************************************************************************************************************/
static bool rp_ssi_monaural (ssi_instance_ctrl_t * const p_instance_ctrl)
{
    uint32_t omod = (p_instance_ctrl->p_reg->SSIOFR & R_SSI0_SSIOFR_OMOD_Msk) >> R_SSI0_SSIOFR_OMOD_Pos;

    return RP_SSI_PRV_SSIOFR_OMOD_MONAURAL == omod;
}

/*******************************************************************************************************************//**
 * Sets the ISR state after an R_SSI function was called with twice the length in the monaural format.
 *
 * With a transfer instance, the R_SSI function sized the transfer for the buffer: the transmit transfer moves every
 * word and the receive transfer moves all but the last word, which the receive ISR reads. Without a transfer
 * instance, the ISR moves every word of the buffer.
 *
 * @param[in] p_instance_ctrl          Pointer to the control block.
 * @param[in] p_src                    Pointer to the source buffer, or NULL if nothing is written.
 * @param[in] p_dest                   Pointer to the destination buffer, or NULL if nothing is read.
 * @param[in] bytes                    Length of the buffers.
 **********************************************************************************************************************/
static void rp_ssi_monaural_state_set (ssi_instance_ctrl_t * const p_instance_ctrl,
                                       void const * const          p_src,
                                       void * const                p_dest,
                                       uint32_t const              bytes)
{
    uint32_t samples = bytes >> p_instance_ctrl->fifo_access_size;

    if ((NULL != p_src) && (NULL == p_instance_ctrl->p_cfg->p_transfer_tx))
    {
        p_instance_ctrl->p_tx_src       = p_src;
        p_instance_ctrl->tx_src_samples = samples;
    }

    if (NULL == p_dest)
    {
        return;
    }

    transfer_instance_t const * const p_transfer = p_instance_ctrl->p_cfg->p_transfer_rx;
    if (NULL == p_transfer)
    {
        p_instance_ctrl->p_rx_dest       = p_dest;
        p_instance_ctrl->rx_dest_samples = samples;

        return;
    }

    /* R_SSI_Read does not reset the transfer for a one-word buffer, so a transfer left armed by a previous, longer
     * buffer would take the word. Disable it so that the receive ISR reads the word. The Zephyr driver reopens the
     * transfer whenever the block size changes, so this only matters for other callers. */
    if (1U == samples)
    {
        (void) p_transfer->p_api->disable(p_transfer->p_ctrl);
    }

    p_instance_ctrl->p_rx_dest = (void *) ((uint32_t) p_dest + ((samples - 1U) << p_instance_ctrl->fifo_access_size));
    p_instance_ctrl->rx_dest_samples = 1U;
}

#endif
