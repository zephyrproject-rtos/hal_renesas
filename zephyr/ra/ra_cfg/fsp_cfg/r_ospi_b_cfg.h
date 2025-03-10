/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its
 * affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_OSPI_B_CFG_H_
#define R_OSPI_B_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define OSPI_B_CFG_PARAM_CHECKING_ENABLE ((BSP_CFG_PARAM_CHECKING_ENABLE))
#define OSPI_B_CFG_DMAC_SUPPORT_ENABLE (0)
#define OSPI_B_CFG_XIP_SUPPORT_ENABLE (0)
#define OSPI_B_CFG_AUTOCALIBRATION_SUPPORT_ENABLE (1)
#define OSPI_B_CFG_PREFETCH_FUNCTION (1)
#define OSPI_B_CFG_COMBINATION_FUNCTION OSPI_B_COMBINATION_FUNCTION_64BYTE
#define OSPI_B_CFG_DOTF_SUPPORT_ENABLE (0)
#define OSPI_B_MAX_WRITE_ENABLE_LOOPS (0)
#ifdef __cplusplus
}
#endif
#endif /* R_OSPI_B_CFG_H_ */
