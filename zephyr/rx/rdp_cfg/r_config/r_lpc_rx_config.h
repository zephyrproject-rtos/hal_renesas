/***********************************************************************************************************************
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_lpc_rx_config.h
* Description  : Configures this code
************************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 01.10.2016 1.00    First Release
 *         : 14.11.2019 2.00    Removed RX210.
 *         : 15.03.2025 2.51    Updated disclaimer.
***********************************************************************************************************************/
#ifndef LPC_CONFIG_HEADER_FILE
#define LPC_CONFIG_HEADER_FILE

/***********************************************************************************************************************
Configuration Options
***********************************************************************************************************************/
/* SPECIFY WHETHER TO INCLUDE CODE FOR API PARAMETER CHECKING */
/* Setting to BSP_CFG_PARAM_CHECKING_ENABLE utilizes the system default setting */
/* Setting to 1 includes parameter checking; 0 compiles out parameter checking */
#define LPC_CFG_PARAM_CHECKING_ENABLE       (BSP_CFG_PARAM_CHECKING_ENABLE)

#endif /* LPC_CONFIG_HEADER_FILE */
