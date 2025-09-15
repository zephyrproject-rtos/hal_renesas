/*
* Copyright (c) 2018 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/***********************************************************************************************************************
 * File Name    : rm_touch_qe_config.h
 * Description  : Configures the QE Touch API module.
 ***********************************************************************************************************************/
#ifndef TOUCH_CONFIG_HEADER_FILE
#define TOUCH_CONFIG_HEADER_FILE


/***********************************************************************************************************************
 Configuration Options
 ***********************************************************************************************************************/
#define TOUCH_CFG_PARAM_CHECKING_ENABLE   (BSP_CFG_PARAM_CHECKING_ENABLE)

#define TOUCH_CFG_UART_MONITOR_SUPPORT    (0)

#define TOUCH_CFG_UART_TUNING_SUPPORT     (0)

#define TOUCH_CFG_UART_MODULE_TYPE        (0)

#define TOUCH_CFG_UART_NUMBER             (0)

#define TOUCH_CFG_UART_BAUDRATE           (115200)

#define TOUCH_CFG_UART_PRIORITY           (0)

#define TOUCH_CFG_CHATTERING_SUPPRESSION_TYPE (0)

#ifndef QE_TOUCH_CONFIGURATION
#define TOUCH_CFG_NUM_BUTTONS             (DT_NUM_INST_STATUS_OKAY(renesas_rx_ctsu_button))
#define TOUCH_CFG_NUM_SLIDERS             (DT_NUM_INST_STATUS_OKAY(renesas_rx_ctsu_slider))
#define TOUCH_CFG_NUM_WHEELS              (DT_NUM_INST_STATUS_OKAY(renesas_rx_ctsu_wheel))
#if (BSP_FEATURE_CTSU_VERSION == 2)
#define TOUCH_CFG_PAD_ENABLE             (0)
#endif
#endif
#endif /* TOUCH_CONFIG_HEADER_FILE */
