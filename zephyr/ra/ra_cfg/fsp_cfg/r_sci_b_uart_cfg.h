/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SCI_B_UART_CFG_H_
#define R_SCI_B_UART_CFG_H_
#ifdef __cplusplus
            extern "C" {
            #endif

#define SCI_B_UART_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define SCI_B_UART_CFG_FIFO_SUPPORT (CONFIG_UART_RA_SCI_B_UART_FIFO_ENABLE)
#define SCI_B_UART_CFG_DTC_SUPPORTED (CONFIG_USE_RA_FSP_DTC)
#define SCI_B_UART_CFG_FLOW_CONTROL_SUPPORT (0)
#if CONFIG_UART_INTERRUPT_DRIVEN && !BSP_CFG_INTERRUPT_INIT
 #undef BSP_CFG_INTERRUPT_INIT
 #define BSP_CFG_INTERRUPT_INIT (CONFIG_UART_INTERRUPT_DRIVEN)
#endif

#ifdef __cplusplus
            }
            #endif
#endif /* R_SCI_B_UART_CFG_H_ */
