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

/*
 * OFS0 IWDT configuration. Derived from the renesas,ra-iwdt devicetree node and Kconfig
 * when such a node is enabled; otherwise IWDT stays disabled (IWDTSTRT = 1).
 */
#if DT_HAS_COMPAT_STATUS_OKAY(renesas_ra_iwdt)

#define IWDT_DT_NODE DT_COMPAT_GET_ANY_STATUS_OKAY(renesas_ra_iwdt)

#define IWDT_OFS_STRT    (IS_ENABLED(CONFIG_WDT_RENESAS_RA_IWDT_AUTO_START_MODE) ? 0 : 1)
#define IWDT_OFS_RSTIRQS (IS_ENABLED(CONFIG_WDT_RENESAS_RA_IWDT_NMI) ? 0 : 1)

/*
 * IWDTTOPS[1:0]: timeout period, in IWDTCLK cycles.
 */
#define IWDT_OFS_TOPS                                                                            \
	(COND_CODE_1(DT_NODE_HAS_PROP(IWDT_DT_NODE, timeout_period),                              \
		(DT_PROP(IWDT_DT_NODE, timeout_period) == 128    ? 0                              \
		 : DT_PROP(IWDT_DT_NODE, timeout_period) == 512  ? 1                              \
		 : DT_PROP(IWDT_DT_NODE, timeout_period) == 1024 ? 2                              \
								  : 3),                            \
		(3)))

/* IWDTCKS[3:0]: divisor applied to IWDTCLK. Defaults to the longest period. */
#define IWDT_OFS_CKS                                                                              \
	(COND_CODE_1(DT_NODE_HAS_PROP(IWDT_DT_NODE, clock_division),                              \
		(DT_PROP(IWDT_DT_NODE, clock_division) == 1     ? 0x0                            \
		 : DT_PROP(IWDT_DT_NODE, clock_division) == 16  ? 0x2                            \
		 : DT_PROP(IWDT_DT_NODE, clock_division) == 32  ? 0x3                            \
		 : DT_PROP(IWDT_DT_NODE, clock_division) == 64  ? 0x4                            \
		 : DT_PROP(IWDT_DT_NODE, clock_division) == 128 ? 0xF                            \
								  : 0x5),                          \
		(0x5)))

/* IWDTRPES[1:0]: window end position. Defaults to the window open for the whole period. */
#define IWDT_OFS_RPES                                                                             \
	(COND_CODE_1(DT_NODE_HAS_PROP(IWDT_DT_NODE, window_end),                                  \
		(DT_PROP(IWDT_DT_NODE, window_end) == 75   ? 0                                   \
		 : DT_PROP(IWDT_DT_NODE, window_end) == 50 ? 1                                   \
		 : DT_PROP(IWDT_DT_NODE, window_end) == 25 ? 2                                   \
							     : 3),                                \
		(3)))

/* IWDTRPSS[1:0]: window start position. Defaults to the window open for the whole period. */
#define IWDT_OFS_RPSS                                                                             \
	(COND_CODE_1(DT_NODE_HAS_PROP(IWDT_DT_NODE, window_start),                                \
		(DT_PROP(IWDT_DT_NODE, window_start) == 25   ? 0                                 \
		 : DT_PROP(IWDT_DT_NODE, window_start) == 50 ? 1                                 \
		 : DT_PROP(IWDT_DT_NODE, window_start) == 75 ? 2                                 \
							       : 3),                              \
		(3)))

#else /* !DT_HAS_COMPAT_STATUS_OKAY(renesas_ra_iwdt) */

#define IWDT_OFS_STRT    (1)
#define IWDT_OFS_RSTIRQS (1)
#define IWDT_OFS_TOPS    (3)
#define IWDT_OFS_CKS     (0x5)
#define IWDT_OFS_RPES    (3)
#define IWDT_OFS_RPSS    (3)

#endif /* DT_HAS_COMPAT_STATUS_OKAY(renesas_ra_iwdt) */

#define OFS_IWDT                                                                                  \
	(0xA001A001 | IWDT_OFS_STRT << 1 | IWDT_OFS_TOPS << 2 | IWDT_OFS_CKS << 4 |                \
	 IWDT_OFS_RPES << 8 | IWDT_OFS_RPSS << 10 | IWDT_OFS_RSTIRQS << 12 | 1 << 14)
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
#define BSP_CFG_OPTION_SETTING_BPS 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_bps */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_pbps))
#define BSP_CFG_OPTION_SETTING_PBPS 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_pbps */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_ofs1_sec))
#define BSP_CFG_OPTION_SETTING_OFS1_SEC_NO_HOCOFRQ (0xFFFFF8F8 | (1 <<2) | (3) | (1 << 8))
#define BSP_CFG_OPTION_SETTING_OFS1_SEC  ((uint32_t) BSP_CFG_OPTION_SETTING_OFS1_SEC_NO_HOCOFRQ | ((uint32_t) BSP_CFG_HOCO_FREQUENCY << BSP_FEATURE_BSP_OFS1_HOCOFRQ_OFFSET))
#endif /* option_setting_ofs1_sec */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_banksel_sec))
#define BSP_CFG_OPTION_SETTING_BANKSEL_SEC  ( 0xFFFFU | (0xFFFFU << 16))
#endif /* option_setting_banksel_sec */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_bps_sec))
#define BSP_CFG_OPTION_SETTING_BPS_SEC 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_bps_sec */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_pbps_sec))
#define BSP_CFG_OPTION_SETTING_PBPS_SEC 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
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
#define BSP_CFG_OPTION_SETTING_BPS_SEL 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
#endif /* option_setting_bps_sel */

#endif /* BSP_MCU_OFS_CFG_H_ */
