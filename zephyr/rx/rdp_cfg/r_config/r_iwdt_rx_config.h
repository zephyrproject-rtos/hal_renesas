/***********************************************************************************************************************
* Copyright (c) 2013 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name     : r_iwdt_rx_config.h
* Description   : Configures the IWDT drivers
************************************************************************************************************************
* History : DD.MM.YYYY Version Description           
*           07.06.2013 1.00    First Release     
*           06.09.2013 1.10    Move internal macro checking to private header file
*           19.03.2014 1.20    Removed equates relative to OFS0 settings.
*           21.07.2017 1.80    Update the 'Copyright' year           
*           15.03.2025 4.51    Updated disclaimer
***********************************************************************************************************************/
#ifndef IWDT_RX_CONFIG_H
#define IWDT_RX_CONFIG_H

/***********************************************************************************************************************
Configuration Options
***********************************************************************************************************************/

/* SPECIFY WHETHER TO INCLUDE CODE FOR API PARAMETER CHECKING 
   Setting to BSP_CFG_PARAM_CHECKING_ENABLE utilizes the system default setting (default)
   Setting to 1 includes parameter checking; 0 compiles out parameter checking */
#define IWDT_CFG_PARAM_CHECKING_ENABLE   (BSP_CFG_PARAM_CHECKING_ENABLE)


/* NOTE:
 * To have the IWDT start automatically at powerup instead of using an Open() call,
 * change the BSP_CFG_OFS0_REG_VALUE mask to the desired settings in r_bsp_config.h.
 */


#endif /* IWDT_RX_CONFIG_H */
