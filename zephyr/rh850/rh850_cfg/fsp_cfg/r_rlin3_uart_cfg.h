/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RLIN3_UART_CFG_H_
#define R_RLIN3_UART_CFG_H_

#define RLIN3_UART_CFG_CLOCK                        (BSP_CFG_CLOCK_CLK_RLIN3_HZ)
#if defined(CONFIG_SOC_SERIES_RH850U2B)
 #define RLIN3_UART_CFG_CLOCK_CH23                  (BSP_CFG_CLOCK_CLK_CH23_RLIN3_HZ)
#elif defined(CONFIG_SOC_SERIES_RH850U2C)
 #define RLIN3_UART_CFG_CLOCK_CH23                  (BSP_CFG_CLOCK_CLK_RLIN323_HZ)
#else
/* U2A has no RLIN323; value unused */
 #define RLIN3_UART_CFG_CLOCK_CH23                  (BSP_CFG_CLOCK_CLK_RLIN3_HZ)
#endif
#define R_RLIN3_UART_CFG_TRANSFER_SUPPORT_ENABLE    (1)
#endif                                 /* R_RLIN3_UART_CFG_H_ */
