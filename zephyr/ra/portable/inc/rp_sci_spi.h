/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RP_SCI_SPI_H
#define RP_SCI_SPI_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_spi_api.h"
#include "r_sci_spi.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*****************************************************************************************************************//**
 * @ingroup SCI_SPI
 * @{
 ********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

fsp_err_t RP_SCI_SPI_WriteReadPolling(sci_spi_instance_ctrl_t * p_ctrl,
                                      const uint8_t           * tx_buf,
                                      uint8_t                 * rx_buf,
                                      size_t                    length);
fsp_err_t RP_SCI_SPI_WritePolling(sci_spi_instance_ctrl_t * p_ctrl, const uint8_t * tx_buf, size_t length);
fsp_err_t RP_SCI_SPI_ReadPolling(sci_spi_instance_ctrl_t * p_ctrl, uint8_t * rx_buf, size_t length);
fsp_err_t RP_SCI_SPI_StartTransferPolling(spi_ctrl_t * const p_api_ctrl);
fsp_err_t RP_SCI_SPI_EndTransferPolling(spi_ctrl_t * const p_api_ctrl);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif /* RP_SCI_SPI_H */

/*******************************************************************************************************************//**
 * @} (end ingroup SCI_SPI)
 **********************************************************************************************************************/
