/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SPI_B_CFG_H_
#define R_SPI_B_CFG_H_
#ifdef __cplusplus
        extern "C" {
        #endif

#define SPI_B_CFG_PARAM_CHECKING_ENABLE (1)
#if CONFIG_SPI_B_RA_DTC
#define SPI_B_DTC_SUPPORT_ENABLE (1)
#else
#define SPI_B_DTC_SUPPORT_ENABLE (0)
#endif
#define SPI_B_TRANSMIT_FROM_RXI_ISR (0)

#ifdef __cplusplus
        }
        #endif
#endif /* R_SPI_B_CFG_H_ */