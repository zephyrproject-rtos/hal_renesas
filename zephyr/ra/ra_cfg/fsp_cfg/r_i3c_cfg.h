/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_I3C_CFG_H_
#define R_I3C_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define I3C_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define I3C_CFG_UNALIGNED_BUFFER_SUPPORT (1)
#define I3C_CFG_MASTER_SUPPORT (1)
#define I3C_CFG_SLAVE_SUPPORT (0)
#define I3C_CFG_ERROR_RECOVERY_SUPPORT I3C_ERROR_RECOVERY_VERSION_2

#ifdef __cplusplus
}
#endif
#endif /* R_I3C_CFG_H_ */
