/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_SCI_B_SPI_CFG_H_
#define R_SCI_B_SPI_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_SPI_RENESAS_RA_SCI_B_DTC
#define SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE (1)
#else
#define SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE (0)
#endif

#define SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)

/* DEPRECATED: Use SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE instead. */
#define SCI_B_SPI_DTC_SUPPORT_ENABLE (SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE)

#ifdef __cplusplus
}
#endif
#endif /* R_SCI_B_SPI_CFG_H_ */
