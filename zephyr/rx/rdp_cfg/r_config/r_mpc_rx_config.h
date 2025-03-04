/***********************************************************************************************************************
* Copyright (c) 2013 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_mpc_rx_config.h
* Description  : Configuration options for the r_mpc_rx module.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version Description           
*         : 17.07.2013 1.00    First Release
*         : 15.03.2025 5.01    Updated disclaimer.
***********************************************************************************************************************/
#ifndef MPC_RX_CONFIG_HEADER_FILE
#define MPC_RX_CONFIG_HEADER_FILE

/***********************************************************************************************************************
Configuration Options
***********************************************************************************************************************/
/* SPECIFY WHETHER TO INCLUDE CODE FOR API PARAMETER CHECKING
   Available settings:
   BSP_CFG_PARAM_CHECKING_ENABLE:
       Utilizes the system default setting
   1:
       Includes parameter checking
   0:
       Compiles out parameter checking
*/
#define MPC_CFG_PARAM_CHECKING_ENABLE      (BSP_CFG_PARAM_CHECKING_ENABLE)

#endif /* MPC_RX_CONFIG_HEADER_FILE */


