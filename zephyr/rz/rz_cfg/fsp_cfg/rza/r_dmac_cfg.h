/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DMAC_CFG_H_
#define R_DMAC_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define DMAC_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define DMAC_CFG_DACK_ACTIVE_LEVEL      ((DMAC_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_NO_OUTPUT) | \
                                         (DMAC_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_NO_OUTPUT << 1U) | \
                                         (DMAC_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_NO_OUTPUT << 2U) | \
                                         (DMAC_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_NO_OUTPUT << 3U) | \
                                         (DMAC_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_NO_OUTPUT << 4U))
#define DMAC_CFG_TEND_ACTIVE_LEVEL      ((DMAC_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_NO_OUTPUT) | \
                                         (DMAC_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_NO_OUTPUT << 1U) | \
                                         (DMAC_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_NO_OUTPUT << 2U) | \
                                         (DMAC_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_NO_OUTPUT << 3U) | \
                                         (DMAC_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_NO_OUTPUT << 4U))

#ifdef __cplusplus
}
#endif
#endif /* R_DMAC_CFG_H_ */
