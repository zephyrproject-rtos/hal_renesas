/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_sci_b_spi.h"
#include "r_sci_b_spi_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define SCI_B_SPI_PRV_DATA_REG_MASK               (0xFFFFFF00)
#define SCI_B_SPI_PRV_RDAT_MASK                   (0xFFU)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function declarations.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup SCI_B_SPI
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable polling data transfer.
 *
 * @param      p_api_ctrl           Pointer to the control structure.
 *
 * @retval     FSP_SUCCESS          Read operation successfully completed.
 * @retval     FSP_ERR_ASSERTION    One of the following invalid parameters passed:
 *                                  - Pointer p_api_ctrl is NULL
 *
 * @return     See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes. This
 *             function calls:
 **********************************************************************************************************************/
fsp_err_t RP_SCI_B_SPI_StartTransferPolling (spi_ctrl_t * const p_api_ctrl)
{
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) p_api_ctrl;

#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
#endif

    /* Set FCR. Reset FIFO/data registers. */
    p_ctrl->p_reg->FCR = (R_SCI_B0_FCR_TFRST_Msk | R_SCI_B0_FCR_RFRST_Msk);

	/* Enable transfer data bit */
	p_ctrl->p_reg->CCR0 |= (R_SCI_B0_CCR0_TE_Msk | R_SCI_B0_CCR0_RE_Msk);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Transmit one byte data to a SPI  device by polling.
 *
 * @param      p_api_ctrl           Pointer to the control structure.
 * @param      p_tx_byte            Pointer to the source buffer.
 *
 * @retval     FSP_SUCCESS          Write operation successfully completed.
 * @retval     FSP_ERR_ASSERTION    One of the following invalid parameters passed:
 *                                  - Pointer p_api_ctrl is NULL
 *                                  - Pointer to source is NULL
 *
 * @return     See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes. This
 *             function calls:
 **********************************************************************************************************************/
fsp_err_t RP_SCI_B_SPI_WriteOneBytePolling (spi_ctrl_t * const p_api_ctrl,
                                            const uint8_t tx_byte)
{
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) p_api_ctrl;

#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
#endif

    /* Wait the TDR data to empty*/
    while (!p_ctrl->p_reg->CSR_b.TDRE) {
	}

    /* Write data to TDR */
	p_ctrl->p_reg->TDR = (SCI_B_SPI_PRV_DATA_REG_MASK | tx_byte);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read one byte data from a SPI  device by polling.
 *
 * @param      p_api_ctrl           Pointer to the control structure.
 * @param      p_rx_byte            Pointer to the source buffer.
 *
 * @retval     FSP_SUCCESS          Read operation successfully completed.
 * @retval     FSP_ERR_ASSERTION    One of the following invalid parameters passed:
 *                                  - Pointer p_api_ctrl is NULL
 *                                  - Pointer to source is NULL
 *
 * @return     See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes. This
 *             function calls:
 **********************************************************************************************************************/
fsp_err_t RP_SCI_B_SPI_ReadOneBytePolling (spi_ctrl_t * const p_api_ctrl,
                                           uint8_t * p_rx_byte)
{
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) p_api_ctrl;

#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_rx_byte);
#endif

    /* Wait until data available in RDR */
    while (!p_ctrl->p_reg->CSR_b.RDRF) {
	}

    /* Read the data in RDR register */
	*p_rx_byte = (uint8_t)(p_ctrl->p_reg->RDR & SCI_B_SPI_PRV_RDAT_MASK);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * End polling data transfer.
 *
 * @param      p_api_ctrl           Pointer to the control structure.
 *
 * @retval     FSP_SUCCESS          Read operation successfully completed.
 * @retval     FSP_ERR_ASSERTION    One of the following invalid parameters passed:
 *                                  - Pointer p_api_ctrl is NULL
 *
 * @return     See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes. This
 *             function calls:
 **********************************************************************************************************************/
fsp_err_t RP_SCI_B_SPI_EndTransferPolling (spi_ctrl_t * const p_api_ctrl)
{
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) p_api_ctrl;
    uint32_t ccr0_temp;

#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
#endif

    /* Wait for transmision complete */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->CSR_b.TEND, 1)

    /* Disable the transfer and receive bit */
	ccr0_temp = p_ctrl->p_reg->CCR0;
	ccr0_temp &= (uint32_t)~(R_SCI_B0_CCR0_TE_Msk | R_SCI_B0_CCR0_RE_Msk);
	p_ctrl->p_reg->CCR0 = ccr0_temp;

    return FSP_SUCCESS;
}
