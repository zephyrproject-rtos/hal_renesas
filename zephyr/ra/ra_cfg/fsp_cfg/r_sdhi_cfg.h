/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its
 * affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_SDHI_CFG_H_
#define R_SDHI_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define SDHI_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define SDMMC_CFG_UNALIGNED_ACCESS_ENABLE (1)
#define SDHI_CFG_SD_SUPPORT_ENABLE                                             \
  (DT_PROP_OR(DT_NODELABEL(sdhc0), sd_support, 0)) ||                         \
      (DT_PROP_OR(DT_NODELABEL(sdhc1), sd_support, 0))
#define SDHI_CFG_EMMC_SUPPORT_ENABLE                                           \
  (DT_PROP_OR(DT_NODELABEL(sdhc0), mmc_support, 0)) ||                        \
      (DT_PROP_OR(DT_NODELABEL(sdhc1), mmc_support, 0))

#ifdef __cplusplus
}
#endif
#endif /* R_SDHI_CFG_H_ */
