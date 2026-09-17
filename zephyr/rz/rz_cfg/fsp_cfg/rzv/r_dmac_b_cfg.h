/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DMAC_B_CFG_H_
#define R_DMAC_B_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define DMAC_B_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define DMAC_B_CFG_DACK_ACTIVE_LEVEL    ((DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE) | \
                                         (DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE << 1U) | \
                                         (DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE << 2U) | \
                                         (DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE << 3U) | \
                                         (DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE << 4U))
#define DMAC_B_CFG_TEND_ACTIVE_LEVEL    ((DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE) | \
                                         (DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE << 1U) | \
                                         (DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE << 2U) | \
                                         (DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE << 3U) | \
                                         (DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE << 4U))

#ifdef __cplusplus
}
#endif
#endif /* R_DMAC_B_CFG_H_ */
