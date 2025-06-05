/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_SSI_CFG_H_
#define R_SSI_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define SSI_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#ifdef CONFIG_I2S_RENESAS_RA_SSIE_DTC
#define SSI_CFG_DTC_ENABLE (1)
#else
#define SSI_CFG_DTC_ENABLE (0)
#endif

#ifdef __cplusplus
}
#endif
#endif /* R_SSI_CFG_H_ */
