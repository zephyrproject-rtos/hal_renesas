/***********************************************************************************************************************
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_sci_rx_dtc.h
* Description  : 
************************************************************************************************************************
* History : DD.MM.YYYY Version Description
*           25.08.2020 1.00    Initial Release
*           31.03.2022 4.40    Fixed the issue with DTC mode which incorrectly uses the same transfer information 
*                              for all channels.
*           31.03.2023 4.80    Fixed to comply with GSCE Coding Standards Rev.6.5.0.
*           29.05.2023 4.90    Fixed to comply with GSCE Coding Standards Rev.6.5.0.
*           15.03.2025 5.41    Updated disclaimer
***********************************************************************************************************************/
#ifndef SCI_RX_DTC_H
#define SCI_RX_DTC_H

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "platform.h"
#include "r_sci_rx_if.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Global Typedef definitions
 *********************************************************************************************************************/
typedef struct st_sci_dtc_info_transfer
{
    uint8_t chan;                            /* Channel SCI is used */
    dtc_transfer_data_t tx_info_dtc;         /* Transfer data address for TX */
    dtc_transfer_data_t rx_info_dtc;         /* Transfer data address for RX */
    struct st_sci_dtc_info_transfer * next;  /* Pointer used to link one node to the next node */
} sci_dtc_info_transfer_t;

/**********************************************************************************************************************
 External global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Exported global functions
 *********************************************************************************************************************/
/******************************************************************************
 * Function Name: sci_txfifo_dtc_create
 * Description  : .
 * Arguments    : hdl
 *              : p_src
 *              : length
 * Return Value : .
 *****************************************************************************/
sci_err_t sci_txfifo_dtc_create (sci_hdl_t const hdl, uint8_t *p_src, uint16_t const length);

/******************************************************************************
 * Function Name: sci_rxfifo_dtc_create
 * Description  : .
 * Arguments    : hdl
 *              : p_dst
 *              : length
 * Return Value : .
 *****************************************************************************/
sci_err_t sci_rxfifo_dtc_create (sci_hdl_t const hdl, uint8_t *p_dst, uint16_t const length);

/******************************************************************************
 * Function Name: sci_tx_dtc_create
 * Description  : .
 * Arguments    : hdl
 *              : p_src
 *              : length
 * Return Value : .
 *****************************************************************************/
sci_err_t sci_tx_dtc_create (sci_hdl_t const hdl, uint8_t *p_src, uint16_t const length);

/******************************************************************************
 * Function Name: sci_rx_dtc_create
 * Description  : .
 * Arguments    : hdl
 *              : p_dst
 *              : length
 * Return Value : .
 *****************************************************************************/
sci_err_t sci_rx_dtc_create (sci_hdl_t const hdl, uint8_t *p_dst, uint16_t const length);

/******************************************************************************
 * Function Name: sci_dtc_info_transfer_delete
 * Description  : .
 * Argument     : hdl
 * Return Value : .
 *****************************************************************************/
void sci_dtc_info_transfer_delete (sci_hdl_t const hdl);

#endif /* SCI_RX_DTC_H */
