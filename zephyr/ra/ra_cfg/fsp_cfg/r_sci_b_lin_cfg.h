/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_SCI_B_LIN_CFG_H_
#define R_SCI_B_LIN_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define SCI_B_LIN_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define SCI_B_LIN_CHECKSUM_SUPPORT_ENABLE (1)
#define SCI_B_LIN_AUTO_SYNC_SUPPORT_ENABLE (IS_ENABLED(CONFIG_LIN_AUTO_SYNCHRONIZATION))

#ifdef __cplusplus
}
#endif
#endif /* R_SCI_B_LIN_CFG_H_ */
