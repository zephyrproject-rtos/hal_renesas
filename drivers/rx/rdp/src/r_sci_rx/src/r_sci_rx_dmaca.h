/***********************************************************************************************************************
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_sci_rx_dmaca.h
* Description  : 
************************************************************************************************************************
* History : DD.MM.YYYY Version Description
*           25.08.2020 1.00    Initial Release
*           31.03.2023 4.80    Fixed to comply with GSCE Coding Standards Rev.6.5.0.
*           29.05.2023 4.90    Fixed to comply with GSCE Coding Standards Rev.6.5.0.
*           15.03.2025 5.41    Updated disclaimer
***********************************************************************************************************************/

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

/**********************************************************************************************************************
 External global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Exported global functions
 *********************************************************************************************************************/
/******************************************************************************
 * Function Name: sci_txfifo_dmaca_create
 * Description  : .
 * Arguments    : hdl
 *              : p_src
 *              : length
 * Return Value : .
 *****************************************************************************/
sci_err_t sci_txfifo_dmaca_create (sci_hdl_t const hdl, uint8_t *p_src, uint16_t const length);

/******************************************************************************
 * Function Name: sci_rxfifo_dmaca_create
 * Description  : .
 * Arguments    : hdl
 *              : p_dst
 *              : length
 * Return Value : .
 *****************************************************************************/
sci_err_t sci_rxfifo_dmaca_create (sci_hdl_t const hdl, uint8_t *p_dst, uint16_t const length);

/******************************************************************************
 * Function Name: sci_tx_dmaca_create
 * Description  : .
 * Arguments    : hdl
 *              : p_src
 *              : length
 * Return Value : .
 *****************************************************************************/
sci_err_t sci_tx_dmaca_create (sci_hdl_t const hdl, uint8_t *p_src, uint16_t const length);

/******************************************************************************
 * Function Name: sci_rx_dmaca_create
 * Description  : .
 * Arguments    : hdl
 *              : p_dst
 *              : length
 * Return Value : .
 *****************************************************************************/
sci_err_t sci_rx_dmaca_create (sci_hdl_t const hdl, uint8_t *p_dst, uint16_t const length);
