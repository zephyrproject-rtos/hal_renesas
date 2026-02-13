/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_SAU_UART_CFG_H_
#define R_SAU_UART_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define SAU_UART_CFG_CRITICAL_SECTION_ENABLE (0)
#define SAU_UART_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define SAU_UART_CFG_DTC_SUPPORT_ENABLE (0)

#if (DT_NUM_INST_STATUS_OKAY(renesas_ra_uart_sau) == 1)
#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(uart0))
#define SAU_UART_CFG_SINGLE_CHANNEL (1)
#elif DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(uart1))
#define SAU_UART_CFG_SINGLE_CHANNEL (2)
#elif DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(uart2))
#define SAU_UART_CFG_SINGLE_CHANNEL (3)
#endif /* DT_NODE_HAS_STATUS_OKAY */
#else
#define SAU_UART_CFG_SINGLE_CHANNEL (0)
#endif /* DT_NUM_INST_STATUS_OKAY */

#define SAU_UART_CFG_FIXED_BAUDRATE_ENABLE (1)
#define SAU_UART_CFG_IRQ_CONFIG (0)

#ifdef __cplusplus
}
#endif
#endif /* R_SAU_UART_CFG_H_ */
