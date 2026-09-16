/*
* Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_OFS_CFG_H_
#define BSP_MCU_OFS_CFG_H_

#ifndef BSP_CFG_OPTION_SETTING_OFS0
#define OFS_IWDT (0xA001A001U | 1U << 1U | 3U << 2U | 15U << 4U | 3U << 8U | 3 << 10U | 1U << 12U | 1U << 14U)
#define OFS_WDT  (1U << 17U | 3U << 18U | 15U << 20U | 3U << 24U | 3U << 26U | 1U << 28U | 1U << 30U)
#define BSP_CFG_OPTION_SETTING_OFS0  (OFS_IWDT | OFS_WDT)
#endif

#ifndef BSP_CFG_OPTION_SETTING_OFS2
#define BSP_CFG_OPTION_SETTING_OFS2  ((1U << 1U) | (0xFFFFFFFDU))
#endif

#ifndef BSP_CFG_OPTION_SETTING_OFS1_NS

#define BSP_CFG_OPTION_SETTING_OFS1_NS_NO_HOCOFRQ (0x0FFFF0D0U | 1U << 3U | 7U | 1U << 5U | 1U << 8U | 7U << 28U | 1U << 31U)
#define BSP_CFG_OPTION_SETTING_OFS1_NS  ((uint32_t) BSP_CFG_OPTION_SETTING_OFS1_NS_NO_HOCOFRQ | ((uint32_t) BSP_CFG_HOCO_FREQUENCY << BSP_FEATURE_BSP_OFS1_HOCOFRQ_OFFSET))
#endif

#ifndef BSP_CFG_OPTION_SETTING_OFS1_SEL
#define BSP_CFG_OPTION_SETTING_OFS1_SEL  (0x0FFFF0D0U  | ((7U << 0U)) | ((1U << 3U)) | ((1U << 5U)) | ((1U << 8U)) | ((7U << 9U)) | ((7U << 28U)) | ((1U << 31U)))
#endif

#endif /* BSP_MCU_OFS_CFG_H_ */
