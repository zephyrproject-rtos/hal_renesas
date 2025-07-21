/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_sci_spi.h"
#include "r_sci_spi_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function declarations.
 **********************************************************************************************************************/
static fsp_err_t rp_sci_spi_write_read_polling(spi_ctrl_t * const p_api_ctrl,
                                               uint8_t const    * p_tx_data,
                                               uint8_t          * p_rx_data,
                                               uint32_t const     bytes);
static fsp_err_t rp_sci_spi_write_one_byte_polling(sci_spi_instance_ctrl_t * p_ctrl, const uint8_t tx_byte);
static fsp_err_t rp_sci_spi_read_one_byte_polling(sci_spi_instance_ctrl_t * p_ctrl, uint8_t * p_rx_byte);

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief  Perform a full-duplex SPI transfer in polling mode.
 *
 * Transmits and receives @p length bytes, blocking until each byte is completed. If either buffer is NULL,
 * dummy data is used for TX (0x00) and/or received data is discarded accordingly.
 *
 * @param[in]  p_ctrl   Pointer to the SCI SPI instance control block.
 * @param[in]  tx_buf   Pointer to transmit buffer. If NULL, 0x00 is shifted out for each byte.
 * @param[out] rx_buf   Pointer to receive buffer. If NULL, incoming bytes are read and discarded.
 * @param[in]  length   Number of bytes to transfer.
 *
 * @pre  @ref RP_SCI_SPI_StartTransferPolling must have been called to enable TE/RE and reset FIFOs.
 * @post No state is changed beyond data movement; to stop the peripheral call @ref RP_SCI_SPI_EndTransferPolling.
 *
 * @retval FSP_SUCCESS        Operation completed.
 * @retval FSP_ERR_ASSERTION  @p p_ctrl is NULL (when parameter checking is enabled).
 **********************************************************************************************************************/
fsp_err_t RP_SCI_SPI_WriteReadPolling (sci_spi_instance_ctrl_t * p_ctrl,
                                       const uint8_t           * tx_buf,
                                       uint8_t                 * rx_buf,
                                       size_t                    length)
{
#if SCI_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != tx_buf || NULL != rx_buf);
    FSP_ASSERT(length > 0);
#endif

    return rp_sci_spi_write_read_polling(p_ctrl, tx_buf, rx_buf, length);
}

/*******************************************************************************************************************//**
 * @brief  Transmit a buffer in polling mode.
 *
 * Shifts out @p length bytes from @p tx_buf. Received bytes are read and discarded to keep the peripheral in sync.
 *
 * @param[in] p_ctrl   Pointer to the SCI SPI instance control block.
 * @param[in] tx_buf   Pointer to transmit buffer (must not be NULL).
 * @param[in] length   Number of bytes to transmit.
 *
 * @pre  @ref RP_SCI_SPI_StartTransferPolling must have been called to enable TE/RE and reset FIFOs.
 * @post To stop the peripheral after the session, call @ref RP_SCI_SPI_EndTransferPolling.
 *
 * @retval FSP_SUCCESS        Operation completed.
 * @retval FSP_ERR_ASSERTION  @p p_ctrl is NULL (when parameter checking is enabled).
 **********************************************************************************************************************/
fsp_err_t RP_SCI_SPI_WritePolling (sci_spi_instance_ctrl_t * p_ctrl, const uint8_t * tx_buf, size_t length)
{
#if SCI_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != tx_buf);
    FSP_ASSERT(length > 0);
#endif

    return rp_sci_spi_write_read_polling(p_ctrl, tx_buf, NULL, length);
}

/*******************************************************************************************************************//**
 * @brief  Receive a buffer in polling mode.
 *
 * Receives @p length bytes into @p rx_buf. Dummy 0x00 is shifted out on MOSI to generate clock.
 *
 * @param[in]  p_ctrl   Pointer to the SCI SPI instance control block.
 * @param[out] rx_buf   Pointer to receive buffer (must not be NULL).
 * @param[in]  length   Number of bytes to receive.
 *
 * @pre  @ref RP_SCI_SPI_StartTransferPolling must have been called to enable TE/RE and reset FIFOs.
 * @post To stop the peripheral after the session, call @ref RP_SCI_SPI_EndTransferPolling.
 *
 * @retval FSP_SUCCESS        Operation completed.
 * @retval FSP_ERR_ASSERTION  @p p_ctrl is NULL (when parameter checking is enabled).
 **********************************************************************************************************************/
fsp_err_t RP_SCI_SPI_ReadPolling (sci_spi_instance_ctrl_t * p_ctrl, uint8_t * rx_buf, size_t length)
{
#if SCI_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != rx_buf);
    FSP_ASSERT(length > 0);
#endif

    return rp_sci_spi_write_read_polling(p_ctrl, NULL, rx_buf, length);
}

/*******************************************************************************************************************//**
 * @brief  Start a SPI transfer session in polling mode.
 *
 * Resets the TX/RX FIFOs and enables the transmitter and receiver (TE/RE) bits to prepare for subsequent calls to
 * @ref RP_SCI_SPI_WriteReadPolling, @ref RP_SCI_SPI_WritePolling, or @ref RP_SCI_SPI_ReadPolling.
 *
 * @param[in] p_api_ctrl  Generic pointer to the SCI SPI instance control block.
 *
 * @retval FSP_SUCCESS          Operation completed.
 * @retval FSP_ERR_ASSERTION    @p p_api_ctrl is NULL (when parameter checking is enabled).
 **********************************************************************************************************************/
fsp_err_t RP_SCI_SPI_StartTransferPolling (spi_ctrl_t * const p_api_ctrl)
{
    sci_spi_instance_ctrl_t * p_ctrl = (sci_spi_instance_ctrl_t *) p_api_ctrl;

#if SCI_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
#endif

    /* Set FCR. Reset FIFO/data registers. */
    p_ctrl->p_reg->FCR = (R_SCI0_FCR_TFRST_Msk | R_SCI0_FCR_RFRST_Msk);

    /* Enable transfer data bit */
    p_ctrl->p_reg->SCR |= (R_SCI0_SCR_TE_Msk | R_SCI0_SCR_RE_Msk);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief  End a SPI transfer session in polling mode.
 *
 * Waits until the transmission is complete (TEND = 1) and then clears the TE/RE bits to stop the peripheral.
 *
 * @param[in] p_api_ctrl  Generic pointer to the SCI SPI instance control block.
 *
 * @retval FSP_SUCCESS          Operation completed.
 * @retval FSP_ERR_ASSERTION    @p p_api_ctrl is NULL (when parameter checking is enabled).
 **********************************************************************************************************************/
fsp_err_t RP_SCI_SPI_EndTransferPolling (spi_ctrl_t * const p_api_ctrl)
{
    sci_spi_instance_ctrl_t * p_ctrl = (sci_spi_instance_ctrl_t *) p_api_ctrl;
    uint32_t scr_temp;

#if SCI_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
#endif

    /* Wait for transmision complete */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->SSR_b.TEND, 1U);

    /* Disable the transfer and receive bit */
    scr_temp           = p_ctrl->p_reg->SCR;
    scr_temp          &= (uint32_t) ~(R_SCI0_SCR_TE_Msk | R_SCI0_SCR_RE_Msk);
    p_ctrl->p_reg->SCR = scr_temp;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief  (Internal) Write one byte in polling mode.
 *
 * Waits for @c TDRE = 1 and writes the data to TDR.
 *
 * @param[in] p_ctrl   Pointer to the SCI SPI instance control block.
 * @param[in] tx_byte  Byte to transmit.
 *
 * @retval FSP_SUCCESS          Operation completed.
 **********************************************************************************************************************/
static fsp_err_t rp_sci_spi_write_one_byte_polling (sci_spi_instance_ctrl_t * p_ctrl, const uint8_t tx_byte)
{
    /* Wait the TDR data to empty */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->SSR_b.TDRE, 1U);

    /* Write data to TDR */
    p_ctrl->p_reg->TDR = tx_byte;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief  (Internal) Read one byte in polling mode.
 *
 * Waits for @c RDRF = 1 and then reads a byte from RDR.
 *
 * @param[in]  p_ctrl     Pointer to the SCI SPI instance control block.
 * @param[out] p_rx_byte  Pointer to destination byte.
 *
 * @retval FSP_SUCCESS        Operation completed.
 * @retval FSP_ERR_ASSERTION  @p p_rx_byte is NULL (when parameter checking is enabled).
 **********************************************************************************************************************/
static fsp_err_t rp_sci_spi_read_one_byte_polling (sci_spi_instance_ctrl_t * p_ctrl, uint8_t * p_rx_byte)
{
    /* Wait until data available in RDR */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->SSR_b.RDRF, 1U);

    /* Read the data in RDR register */
    *p_rx_byte = (uint8_t) (p_ctrl->p_reg->RDR);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief  (Internal) Byte-wise full-duplex transfer loop in polling mode.
 *
 * Performs a blocking transfer of @p bytes bytes. For each iteration, the function waits for @c TDRE, writes one
 * byte to TDR (using 0x00 if @p p_tx_data is NULL), then waits for @c RDRF and reads one byte from RDR into
 * @p p_rx_data if provided, otherwise the byte is read into a dummy variable and discarded.
 *
 * @param[in]  p_api_ctrl  Generic pointer to the SCI SPI instance control block.
 * @param[in]  p_tx_data   Pointer to TX buffer, or NULL to transmit 0x00 per byte.
 * @param[out] p_rx_data   Pointer to RX buffer, or NULL to discard received bytes.
 * @param[in]  bytes       Number of bytes to transfer.
 *
 * @pre  TE/RE must already be set and FIFOs reset, e.g. via @ref RP_SCI_SPI_StartTransferPolling.
 * @note This routine is synchronous and blocks the CPU until all bytes complete. It is intended for short
 *       transfers or bring-up; consider using interrupt/DMA driven APIs for longer transfers.
 *
 * @retval FSP_SUCCESS        Operation completed.
 * @retval FSP_ERR_ASSERTION  @p p_api_ctrl is NULL (when parameter checking is enabled).
 * @retval Others             Any error returned by internal helpers, if extended in the future.
 **********************************************************************************************************************/
static fsp_err_t rp_sci_spi_write_read_polling (spi_ctrl_t * const p_api_ctrl,
                                                uint8_t const    * p_tx_data,
                                                uint8_t          * p_rx_data,
                                                uint32_t const     bytes)
{
    sci_spi_instance_ctrl_t * p_ctrl = (sci_spi_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t                 err    = FSP_SUCCESS;

    for (uint32_t i = 0; i < bytes; i++)
    {
        uint8_t tx_byte = p_tx_data ? p_tx_data[i] : 0U; /* Use dummy byte if no TX */

        /* Write one byte */
        err = rp_sci_spi_write_one_byte_polling(p_ctrl, tx_byte);
        if (FSP_SUCCESS != err)
        {
            return err;
        }

        if (p_rx_data)
        {
            /* Read one byte */
            err = rp_sci_spi_read_one_byte_polling(p_ctrl, &p_rx_data[i]);
            if (FSP_SUCCESS != err)
            {
                return err;
            }
        }
        else
        {
            uint8_t dummy;

            /* Read and discard one byte */
            err = rp_sci_spi_read_one_byte_polling(p_ctrl, &dummy);
            if (FSP_SUCCESS != err)
            {
                return err;
            }
        }
    }

    return FSP_SUCCESS;
}
