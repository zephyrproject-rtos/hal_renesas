/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <zephyr/devicetree.h>

#ifndef BSP_MCU_OFS_CFG_H_
#define BSP_MCU_OFS_CFG_H_

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs0))
/* OFS0 WDT configurations */
#ifdef CONFIG_WDT_RENESAS_RA_START_IN_BOOT
#define WDTSTRT    (0)
#else
#define WDTSTRT    (1)
#endif /* CONFIG_WDT_RENESAS_RA_START_IN_BOOT */

#define OFS_IWDT (0xA001A001 | 1 << 1 | 3 << 2 | 15 << 4 | 3 << 8 | 3 << 10 | 1 << 12 | 1 << 14)
#define OFS_WDT  (WDTSTRT << 17 | 3 << 18 | 15 << 20 | 3 << 24 | 3 << 26 | 1 << 28 | 1 << 30)
#define BSP_CFG_OPTION_SETTING_OFS0  (OFS_IWDT | OFS_WDT)
#endif /* option_setting_ofs0 */

/* Dual Mode Select Register */
#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_dualsel))
#define BSP_CFG_OPTION_SETTING_DUALSEL  (0xFFFFFFF8U | 0x7U)
#endif /* option_setting_dualsel */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs1))
#define BSP_CFG_OPTION_SETTING_OFS1_NO_HOCOFRQ (0xFFFFF8F8 | (1 <<2) | (3) | (1 << 8))
#define BSP_CFG_OPTION_SETTING_OFS1  ((uint32_t) BSP_CFG_OPTION_SETTING_OFS1_NO_HOCOFRQ | ((uint32_t) BSP_CFG_HOCO_FREQUENCY << BSP_FEATURE_BSP_OFS1_HOCOFRQ_OFFSET))
#endif /* option_setting_ofs1 */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_banksel))
#define BSP_CFG_OPTION_SETTING_BANKSEL  ( 0xFFFFU | (0xFFFFU << 16))
#endif /* option_setting_banksel */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_bps))
#define BSP_CFG_OPTION_SETTING_BPS 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_bps */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_pbps))
#define BSP_CFG_OPTION_SETTING_PBPS 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_pbps */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs1_sec))
#define BSP_CFG_OPTION_SETTING_OFS1_SEC_NO_HOCOFRQ (0xFFFFF8F8 | (1 <<2) | (3) | (1 << 8))
#define BSP_CFG_OPTION_SETTING_OFS1_SEC  ((uint32_t) BSP_CFG_OPTION_SETTING_OFS1_SEC_NO_HOCOFRQ | ((uint32_t) BSP_CFG_HOCO_FREQUENCY << BSP_FEATURE_BSP_OFS1_HOCOFRQ_OFFSET))
#endif /* option_setting_ofs1_sec */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_banksel_sec))
#define BSP_CFG_OPTION_SETTING_BANKSEL_SEC  ( 0xFFFFU | (0xFFFFU << 16))
#endif /* option_setting_banksel_sec */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_bps_sec))
#define BSP_CFG_OPTION_SETTING_BPS_SEC 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_bps_sec */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_pbps_sec))
#define BSP_CFG_OPTION_SETTING_PBPS_SEC 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_pbps_sec */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs1_sel))
#if defined(_RA_TZ_SECURE) || defined(_RA_TZ_NONSECURE)
  #define BSP_CFG_OPTION_SETTING_OFS1_SEL  (0xFFFFF8F8U | ((0U << 0U)) | ((0U << 2U)) | ((BSP_CFG_CLOCKS_SECURE == 0) ? 0xF00 : 0U))
#else
#define BSP_CFG_OPTION_SETTING_OFS1_SEL  (0xFFFFF8F8U)
#endif
#endif /* option_setting_ofs1_sel */

/* Security Attribution for Bank Select Register */
#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_banksel_sel))
#define BSP_CFG_OPTION_SETTING_BANKSEL_SEL  (0xFFFFFFFFU)
#endif /* option_setting_banksel_sel */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_bps_sel))
#define BSP_CFG_OPTION_SETTING_BPS_SEL 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_bps_sel */

#endif /* BSP_MCU_OFS_CFG_H_ */
