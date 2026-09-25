/*
 * Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_UART_W_B_CFG_H
#define R_UART_W_B_CFG_H

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** SPECIFY WHETHER TO USE HARDWARE FIFO
 * 1 : use FIFO
 * 0 : do not use FIFO
 */
#ifndef UART_W_B_CFG_HW_FIFO_ENABLE
 #define UART_W_B_CFG_HW_FIFO_ENABLE            (1)
#endif

/** SPECIFY WHETHER TO USE one of GPIO pin as UART_W_B RTS pin
 *  This is the enhancement for UART_W_B functionality with additional GPIO support
 * 1 : use GPIO as RTS pin
 * 0 : do not use GPIO as RTS pin
 */
#ifndef UART_W_B_CFG_EXTERNAL_RTS_OPERATION
 #define UART_W_B_CFG_EXTERNAL_RTS_OPERATION    (1)
#endif

/** SPECIFY WHETHER TO SUPPORT RECEPTION
 * 1 : included
 * 0 : not included
 */
#ifndef UART_W_B_CFG_RX_ENABLE
 #define UART_W_B_CFG_RX_ENABLE                 (1)
#endif

/** SPECIFY WHETHER TO SUPPORT TRANSMISSION
 * 1 : included
 * 0 : not included
 */
#ifndef UART_W_B_CFG_TX_ENABLE
 #define UART_W_B_CFG_TX_ENABLE                 (1)
#endif

/** SPECIFY WHETHER TO INCLUDE CODE FOR API PARAMETER CHECKING
 * Setting to BSP_CFG_PARAM_CHECKING_ENABLE utilizes the system default setting
 * 1 : includes parameter checking
 * 0 : compiles out parameter checking
 */
#ifndef UART_W_B_CFG_PARAM_CHECKING_ENABLE
 #define UART_W_B_CFG_PARAM_CHECKING_ENABLE     (BSP_CFG_PARAM_CHECKING_ENABLE)
#endif

/** SPECIFY WHETHER TO INCLUDE CODE FOR CONTROLLING RS485 DE PIN.
 * Setting to BSP_CFG_PARAM_CHECKING_ENABLE utilizes the system default setting
 * 1 : includes RS485 code
 * 0 : compiles out RS485 code
 */
#ifndef UART_W_B_CFG_RS485_SUPPORT
 #define UART_W_B_CFG_RS485_SUPPORT             (0)
#endif

/** SPECIFY WHETHER TO INCLUDE CODE FOR DTC MODE.
 * 1 : DTC supported
 * 0 : DTC un-supported
 */
#ifndef UART_W_B_CFG_DTC_SUPPORTED
 #define UART_W_B_CFG_DTC_SUPPORTED             (0)
#endif

/** SPECIFY WHETHER TO INCLUDE CODE FOR DMA MODE.
 * 1 : DMA supported
 * 0 : DMA un-supported
 */
#ifndef UART_W_B_CFG_DMA_SUPPORTED
 #define UART_W_B_CFG_DMA_SUPPORTED             (CONFIG_UART_RA6B1_DMA)
#endif

#define UART_W_B_CFG_FIFO_SUPPORT		(CONFIG_UART_RA6B1_UART_FIFO_ENABLE)

#define UART_W_B_CFG_FLOW_CONTROL_SUPPORT       (1)

#endif /* R_UART_W_B_CFG_H */
