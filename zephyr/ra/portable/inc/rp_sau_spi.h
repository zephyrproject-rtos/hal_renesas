/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RP_SAU_SPI_H
#define RP_SAU_SPI_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_spi_api.h"
#include "r_sau_spi.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*****************************************************************************************************************//**
 * @ingroup SAU_SPI
 * @{
 ********************************************************************************************************************/

/***********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

fsp_err_t RP_SAU_SPI_StartTransferPolling(spi_ctrl_t * const p_api_ctrl, spi_bit_width_t const bit_width);
fsp_err_t RP_SAU_SPI_WriteReadPolling(sau_spi_instance_ctrl_t * p_ctrl,
                                      const uint8_t           * tx_buf,
                                      uint8_t                 * rx_buf,
                                      size_t                    length);
fsp_err_t RP_SAU_SPI_WritePolling(sau_spi_instance_ctrl_t * p_ctrl, const uint8_t * tx_buf, size_t length);
fsp_err_t RP_SAU_SPI_ReadPolling(sau_spi_instance_ctrl_t * p_ctrl, uint8_t * rx_buf, size_t length);
fsp_err_t RP_SAU_SPI_EndTransferPolling(spi_ctrl_t * const p_api_ctrl);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* RP_SAU_SPI_H */

/*******************************************************************************************************************//**
 * @} (end ingroup SAU_SPI)
 **********************************************************************************************************************/
