/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SCI_UART_CFG_H_
#define R_SCI_UART_CFG_H_
#define SCI_UART_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define SCI_UART_CFG_FIFO_SUPPORT (1)
#define SCI_UART_CFG_DMAC_SUPPORTED (0)
#define SCI_UART_CFG_FLOW_CONTROL_SUPPORT (0)
#define SCI_UART_CFG_MULTIPLEX_INTERRUPT_SUPPORTED (0)
#if SCI_UART_CFG_MULTIPLEX_INTERRUPT_SUPPORTED
 #define SCI_UART_CFG_MULTIPLEX_INTERRUPT_ENABLE         BSP_INTERRUPT_ENABLE
 #define SCI_UART_CFG_MULTIPLEX_INTERRUPT_DISABLE        BSP_INTERRUPT_DISABLE
#else
#define SCI_UART_CFG_MULTIPLEX_INTERRUPT_ENABLE
#define SCI_UART_CFG_MULTIPLEX_INTERRUPT_DISABLE
#endif
#endif /* R_SCI_UART_CFG_H_ */
