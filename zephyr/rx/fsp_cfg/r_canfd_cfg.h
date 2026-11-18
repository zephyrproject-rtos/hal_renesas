/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_CANFD_CFG_H_
#define R_CANFD_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define CANFD_CFG_PARAM_CHECKING_ENABLE ((BSP_CFG_PARAM_CHECKING_ENABLE))
#if BSP_FEATURE_CANFD_SUPPORT_2_TYPES
#define CANFD_CFG_AFL_CH2_RULE_NUM (16)
#else
#define CANFD_CFG_AFL_CH0_RULE_NUM (16)
#endif
#define CANFD_CFG_AFL_CH1_RULE_NUM (16)

#define CANFD_CFG_GLOBAL_ERROR_CH ((0U))

#define CANFD_CFG_FD_PROTOCOL_EXCEPTION ((0))
#define CANFD_CFG_GLOBAL_ERR_IPL ((2))
#define CANFD_CFG_RX_FIFO_IPL ((2))

#ifdef __cplusplus
}
#endif
#endif /* R_CANFD_CFG_H_ */
