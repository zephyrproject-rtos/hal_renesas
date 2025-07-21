/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SCI_SPI_CFG_H_
#define R_SCI_SPI_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define SCI_SPI_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define SCI_SPI_DTC_SUPPORT_ENABLE IS_ENABLED(CONFIG_SPI_RENESAS_RA_SCI_DTC)

#ifdef __cplusplus
}
#endif
#endif /* R_SCI_SPI_CFG_H_ */
