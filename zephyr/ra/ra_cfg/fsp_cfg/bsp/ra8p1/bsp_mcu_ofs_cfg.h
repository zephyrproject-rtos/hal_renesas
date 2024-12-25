/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <zephyr/devicetree.h>

#ifndef BSP_MCU_OFS_CFG_H_
#define BSP_MCU_OFS_CFG_H_

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs0))
#ifdef CONFIG_WDT_RENESAS_RA_START_IN_BOOT
#define WDTSTRT    (0)
#else
#define WDTSTRT    (1)
#endif /* CONFIG_WDT_RENESAS_RA_START_IN_BOOT */

#define OFS_IWDT (0xA001A001 | 1 << 1 | 3 << 2 | 15 << 4 | 3 << 8 | 3 << 10 | 1 << 12 | 1 << 14)
#define OFS_WDT  (WDTSTRT << 17 | 3 << 18 | 15 << 20 | 3 << 24 | 3 << 26 | 1 << 28 | 1 << 30)
#define BSP_CFG_OPTION_SETTING_OFS0  (OFS_IWDT | OFS_WDT)
#endif /* option_setting_ofs0 */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs2))
#define BSP_CFG_OPTION_SETTING_OFS2  ((1 << 0) | (0 << 1) | (0 << 2) | (1 << 3) | (0xFFFFFFE0))
#endif /* option_setting_ofs2 */

/* Startup Area Setting Register */
#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_sas))
#define BSP_CFG_OPTION_SETTING_SAS  (0x9FFFFFFF | (3 << 29))
#endif /* option_setting_sas */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs1))
#define BSP_CFG_OPTION_SETTING_OFS1_NO_HOCOFRQ (0xFCFFF0D0 | 1 <<3 | 7 | 1 << 5 | 1 << 8 | 1 << 24 | 0 << 25)
#define BSP_CFG_OPTION_SETTING_OFS1  ((uint32_t) BSP_CFG_OPTION_SETTING_OFS1_NO_HOCOFRQ | ((uint32_t) BSP_CFG_HOCO_FREQUENCY << BSP_FEATURE_BSP_OFS1_HOCOFRQ_OFFSET))
#endif /* option_setting_ofs1 */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs1_sec))
#define BSP_CFG_OPTION_SETTING_OFS1_SEC_NO_HOCOFRQ (0xFCFFF0D0 | 1 <<3 | 7 | 1 << 5 | 1 << 8 | 1 << 24 | 0 << 25)
#define BSP_CFG_OPTION_SETTING_OFS1_SEC  ((uint32_t) BSP_CFG_OPTION_SETTING_OFS1_SEC_NO_HOCOFRQ | ((uint32_t) BSP_CFG_HOCO_FREQUENCY << BSP_FEATURE_BSP_OFS1_HOCOFRQ_OFFSET))
#endif /* option_setting_ofs1_sec */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs1_sel))
#if defined(_RA_TZ_SECURE) || defined(_RA_TZ_NONSECURE)
  #define BSP_CFG_OPTION_SETTING_OFS1_SEL  (0 | ((0U << 0U)) | ((0U << 3U)) | ((0U << 5U)) | ((BSP_CFG_CLOCKS_SECURE == 0) ? 0xF00 : 0U) | ((0U << 24U)) | ((0U << 25U)))
#else
#define BSP_CFG_OPTION_SETTING_OFS1_SEL  (0)
#endif
#endif /* option_setting_ofs1_sel */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs3))
#define BSP_CFG_OPTION_SETTING_OFS3  (0xA001FFFFU | (1 << 17) | (3 << 18) | (15 << 20) |  (3 << 24) | (3 << 26) | (1 << 28))
#endif /* option_setting_ofs3 */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs3_sec))
#define BSP_CFG_OPTION_SETTING_OFS3_SEC  (0xA001FFFFU | (1 << 17) | (3 << 18) | (15 << 20) |  (3 << 24) | (3 << 26) | (1 << 28))
#endif /* option_setting_ofs3_sec */

/* Option Function Select Register 3 Security Attribution */
#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs3_sel))
#if defined(_RA_TZ_SECURE) || defined(_RA_TZ_NONSECURE)
#define BSP_CFG_OPTION_SETTING_OFS3_SEL  ((0 << 17) | (0 << 18) | (0 << 20) | (0 << 24) | (0 << 26) | (0 << 28) | (0 << 30))
#else
#define BSP_CFG_OPTION_SETTING_OFS3_SEL  (0x00000000U)
#endif
#endif /* option_setting_ofs3_sel */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_bps))
#define BSP_CFG_OPTION_SETTING_BPS 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_bps */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_bps_sec))
#define BSP_CFG_OPTION_SETTING_BPS_SEC 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_bps_sec */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_otp_pbps_sec))
#define BSP_CFG_OPTION_SETTING_OTP_PBPS_SEC 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_pbps_sec */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_otp_pbps))
#define BSP_CFG_OPTION_SETTING_OTP_PBPS 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_otp_pbps */

#endif /* BSP_MCU_OFS_CFG_H_ */
