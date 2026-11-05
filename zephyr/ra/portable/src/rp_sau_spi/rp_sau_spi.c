/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_sau_spi.h"
#include "r_sau_spi_cfg.h"
#include "rp_sau_spi.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Data shifted out while receiving, matching the value r_sau_spi sends on a read. */
#define RP_SAU_SPI_PRV_DUMMY_DATA    (0xFFU)

/** Distance between the register blocks of two SAU units. */
#define RP_SAU_SPI_PRV_UNIT_SIZE     (R_SAU1_BASE - R_SAU0_BASE)

/***********************************************************************************************************************
 * Private function declarations.
 **********************************************************************************************************************/
static R_SAU0_Type * rp_sau_spi_reg_get(sau_spi_instance_ctrl_t * p_ctrl);
static fsp_err_t     rp_sau_spi_frame_polling(sau_spi_instance_ctrl_t * p_ctrl,
                                              uint8_t                   tx_byte,
                                              uint8_t                 * p_rx_byte);

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief  Enable the channel for a polled transfer session.
 *
 * Stops the channel so that SCR may be written, applies the data length, and starts the channel. The transmit end
 * interrupt is masked for the duration of the session: r_sau_spi enables it in @ref R_SAU_SPI_Open, but a polled
 * transfer services the channel from the calling context and must not enter the FSP callback.
 *
 * @param[in] p_api_ctrl   Pointer to the SAU SPI instance control block.
 * @param[in] bit_width    Frame width, 7 or 8 bits.
 *
 * @retval FSP_SUCCESS        Channel enabled.
 * @retval FSP_ERR_ASSERTION  @p p_api_ctrl is NULL (when parameter checking is enabled).
 * @retval FSP_ERR_NOT_OPEN   The instance has not been opened.
 **********************************************************************************************************************/
fsp_err_t RP_SAU_SPI_StartTransferPolling (spi_ctrl_t * const p_api_ctrl, spi_bit_width_t const bit_width)
{
    sau_spi_instance_ctrl_t * p_ctrl = (sau_spi_instance_ctrl_t *) p_api_ctrl;

#if SAU_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(0U != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    R_SAU0_Type * p_reg   = rp_sau_spi_reg_get(p_ctrl);
    uint8_t       channel = p_ctrl->p_cfg->channel;

    R_BSP_IrqDisable(p_ctrl->p_cfg->tei_irq);

    /* Writing to SCR is prohibited while the channel is enabled. See in hardware manual:
     * SAU > Register Descriptions > SCRmn */
    p_reg->ST = (uint16_t) (1U << channel);

    /* Bit width is configured in SCR::DLS[1:0]: 7bit is 0b10, 8bit is 0b11. */
    uint16_t scr = p_reg->SCR[channel];
    p_reg->SCR[channel] = (uint16_t) ((scr & (uint16_t) ~1U) | (SPI_BIT_WIDTH_8_BITS == bit_width));

    p_reg->SS = (uint16_t) (1U << channel);

    p_ctrl->transfer_in_progress = true;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief  Disable the channel at the end of a polled transfer session.
 *
 * @param[in] p_api_ctrl   Pointer to the SAU SPI instance control block.
 *
 * @retval FSP_SUCCESS        Channel disabled.
 * @retval FSP_ERR_ASSERTION  @p p_api_ctrl is NULL (when parameter checking is enabled).
 * @retval FSP_ERR_NOT_OPEN   The instance has not been opened.
 **********************************************************************************************************************/
fsp_err_t RP_SAU_SPI_EndTransferPolling (spi_ctrl_t * const p_api_ctrl)
{
    sau_spi_instance_ctrl_t * p_ctrl = (sau_spi_instance_ctrl_t *) p_api_ctrl;

#if SAU_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(0U != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    R_SAU0_Type * p_reg = rp_sau_spi_reg_get(p_ctrl);

    p_reg->ST = (uint16_t) (1U << p_ctrl->p_cfg->channel);

    p_ctrl->transfer_in_progress = false;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief  Perform a full-duplex transfer in polling mode.
 *
 * @param[in]  p_ctrl   Pointer to the SAU SPI instance control block.
 * @param[in]  tx_buf   Transmit buffer.
 * @param[out] rx_buf   Receive buffer.
 * @param[in]  length   Number of frames to transfer.
 *
 * @pre  @ref RP_SAU_SPI_StartTransferPolling must have been called to enable the channel.
 *
 * @retval FSP_SUCCESS        Operation completed.
 * @retval FSP_ERR_ASSERTION  A pointer argument is NULL (when parameter checking is enabled).
 * @retval FSP_ERR_OVERFLOW   A receive overrun was detected.
 **********************************************************************************************************************/
fsp_err_t RP_SAU_SPI_WriteReadPolling (sau_spi_instance_ctrl_t * p_ctrl,
                                       const uint8_t           * tx_buf,
                                       uint8_t                 * rx_buf,
                                       size_t                    length)
{
#if SAU_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != tx_buf);
    FSP_ASSERT(NULL != rx_buf);
#endif

    fsp_err_t err = FSP_SUCCESS;

    for (size_t i = 0U; (i < length) && (FSP_SUCCESS == err); i++)
    {
        err = rp_sau_spi_frame_polling(p_ctrl, tx_buf[i], &rx_buf[i]);
    }

    return err;
}

/*******************************************************************************************************************//**
 * @brief  Transmit a buffer in polling mode. Received frames are read and discarded.
 *
 * @param[in] p_ctrl   Pointer to the SAU SPI instance control block.
 * @param[in] tx_buf   Transmit buffer.
 * @param[in] length   Number of frames to transmit.
 *
 * @pre  @ref RP_SAU_SPI_StartTransferPolling must have been called to enable the channel.
 *
 * @retval FSP_SUCCESS        Operation completed.
 * @retval FSP_ERR_ASSERTION  A pointer argument is NULL (when parameter checking is enabled).
 * @retval FSP_ERR_OVERFLOW   A receive overrun was detected.
 **********************************************************************************************************************/
fsp_err_t RP_SAU_SPI_WritePolling (sau_spi_instance_ctrl_t * p_ctrl, const uint8_t * tx_buf, size_t length)
{
#if SAU_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != tx_buf);
#endif

    fsp_err_t err = FSP_SUCCESS;

    for (size_t i = 0U; (i < length) && (FSP_SUCCESS == err); i++)
    {
        err = rp_sau_spi_frame_polling(p_ctrl, tx_buf[i], NULL);
    }

    return err;
}

/*******************************************************************************************************************//**
 * @brief  Receive into a buffer in polling mode, shifting out dummy data.
 *
 * @param[in]  p_ctrl   Pointer to the SAU SPI instance control block.
 * @param[out] rx_buf   Receive buffer.
 * @param[in]  length   Number of frames to receive.
 *
 * @pre  @ref RP_SAU_SPI_StartTransferPolling must have been called to enable the channel.
 *
 * @retval FSP_SUCCESS        Operation completed.
 * @retval FSP_ERR_ASSERTION  A pointer argument is NULL (when parameter checking is enabled).
 * @retval FSP_ERR_OVERFLOW   A receive overrun was detected.
 **********************************************************************************************************************/
fsp_err_t RP_SAU_SPI_ReadPolling (sau_spi_instance_ctrl_t * p_ctrl, uint8_t * rx_buf, size_t length)
{
#if SAU_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != rx_buf);
#endif

    fsp_err_t err = FSP_SUCCESS;

    for (size_t i = 0U; (i < length) && (FSP_SUCCESS == err); i++)
    {
        err = rp_sau_spi_frame_polling(p_ctrl, RP_SAU_SPI_PRV_DUMMY_DATA, &rx_buf[i]);
    }

    return err;
}

/*******************************************************************************************************************//**
 * Returns the register block of the unit this instance belongs to.
 *
 * r_sau_spi only stores it in the control block when its single channel configuration is disabled, so it is derived
 * from the extended configuration here instead.
 *
 * @param[in] p_ctrl   Pointer to the SAU SPI instance control block.
 **********************************************************************************************************************/
static R_SAU0_Type * rp_sau_spi_reg_get (sau_spi_instance_ctrl_t * p_ctrl)
{
#ifdef R_SAU1
    sau_spi_extended_cfg_t const * p_extend = (sau_spi_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    return (R_SAU0_Type *) (R_SAU0_BASE + (RP_SAU_SPI_PRV_UNIT_SIZE * p_extend->sau_unit));
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return R_SAU0;
#endif
}

/*******************************************************************************************************************//**
 * Shifts one frame out and one frame in.
 *
 * Writing SDR starts the frame. SSR::TSF stays set while the frame is in progress, and SSR::BFF marks the received
 * data valid; reading SDR clears it. Writing SDR while BFF is set discards the frame and raises an overrun, so the
 * write must follow the poll.
 *
 * @param[in]  p_ctrl      Pointer to the SAU SPI instance control block.
 * @param[in]  tx_byte     Frame to transmit.
 * @param[out] p_rx_byte   Where to store the received frame, or NULL to discard it.
 **********************************************************************************************************************/
static fsp_err_t rp_sau_spi_frame_polling (sau_spi_instance_ctrl_t * p_ctrl, uint8_t tx_byte, uint8_t * p_rx_byte)
{
    R_SAU0_Type * p_reg   = rp_sau_spi_reg_get(p_ctrl);
    uint8_t       channel = p_ctrl->p_cfg->channel;

    p_reg->SDR[channel] = tx_byte;

    FSP_HARDWARE_REGISTER_WAIT((p_reg->SSR[channel] & R_SAU0_SSR_TSF_Msk), 0U);

    if (0U != (p_reg->SSR[channel] & R_SAU0_SSR_OVF_Msk))
    {
        p_reg->SIR[channel] = R_SAU0_SSR_OVF_Msk;

        return FSP_ERR_OVERFLOW;
    }

    uint8_t rx_byte = (uint8_t) p_reg->SDR[channel];

    if (NULL != p_rx_byte)
    {
        *p_rx_byte = rx_byte;
    }

    return FSP_SUCCESS;
}
