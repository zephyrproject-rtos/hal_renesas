/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_TOUCH_CFG_H_
#define RM_TOUCH_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define TOUCH_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define TOUCH_CFG_UART_MONITOR_SUPPORT (0)
#define TOUCH_CFG_UART_TUNING_SUPPORT (0)
#define TOUCH_CFG_CHATTERING_SUPPRESSION_TYPE                                  \
  (!IS_ENABLED(CONFIG_INPUT_RENESAS_RA_CTSU_CHATTERING_SUPPRESSION_TYPE_A))
#ifndef QE_TOUCH_CONFIGURATION
#define TOUCH_CFG_NUM_BUTTONS (DT_NUM_INST_STATUS_OKAY(renesas_ra_ctsu_button))
#define TOUCH_CFG_NUM_SLIDERS (DT_NUM_INST_STATUS_OKAY(renesas_ra_ctsu_slider))
#define TOUCH_CFG_NUM_WHEELS (DT_NUM_INST_STATUS_OKAY(renesas_ra_ctsu_wheel))
#if (BSP_FEATURE_CTSU_VERSION == 2)
#define TOUCH_CFG_PAD_ENABLE (0)
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif /* RM_TOUCH_CFG_H_ */
