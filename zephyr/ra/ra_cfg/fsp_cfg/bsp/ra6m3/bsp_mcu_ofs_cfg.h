/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <zephyr/devicetree.h>

#ifndef BSP_MCU_OFS_CFG_H_
#define BSP_MCU_OFS_CFG_H_

/* OFS0 WDT configurations */
#ifdef CONFIG_WDT_RENESAS_RA_START_IN_BOOT
#define WDTSTRT    (0)
#else
#define WDTSTRT    (1)
#endif /* CONFIG_WDT_RENESAS_RA_START_IN_BOOT */

#define OFS_IWDT (0xA001A001 | 1 << 1 | 3 << 2 | 15 << 4 | 3 << 8 | 3 << 10 | 1 << 12 | 1 << 14)
#define OFS_WDT  (WDTSTRT << 17 | 3 << 18 | 15 << 20 | 3 << 24 | 3 << 26 | 1 << 28 | 1 << 30)
#define BSP_CFG_OPTION_SETTING_OFS0  (OFS_IWDT | OFS_WDT)
#define BSP_CFG_OPTION_SETTING_OFS1_NO_HOCOFRQ (0xFFFFF8F8 | (1 <<2) | (3) | (1 << 8))

#define BSP_CFG_OPTION_SETTING_OFS1  ((uint32_t) BSP_CFG_OPTION_SETTING_OFS1_NO_HOCOFRQ | ((uint32_t) BSP_CFG_HOCO_FREQUENCY << BSP_FEATURE_BSP_OFS1_HOCOFRQ_OFFSET))

#ifndef BSP_CFG_OPTION_SETTING_SECMPU 
#define BSP_CFG_OPTION_SETTING_SECMPU 0xFFFFFFFC,0xFFFFFFFF,0xFFFFFFFC,0xFFFFFFFF,0x001FFFFC,0x001FFFFF,0x2007FFFC,0x2007FFFF,0x400DFFFC,0x400DFFFF,0x400DFFFC,0x400DFFFF,0xFFFFFCF0
#endif

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(option_setting_osis))
/*
 ID Code
 Note: To permanently lock and disable the debug interface define the BSP_ID_CODE_PERMANENTLY_LOCKED in the compiler settings.
 WARNING: This will disable debug access to the part and cannot be reversed by a debug probe.
 */
#if defined(BSP_ID_CODE_PERMANENTLY_LOCKED)
/*
ID Code
Note: To lock and disable the debug interface define BSP_ID_CODE_LOCKED in compiler settings.
WARNING: This will disable debug access to the part. However, ALeRASE command will be accepted, which will clear (reset) the ID code. After clearing ID code, debug access will be enabled.
Please read the HWM for full details of the clearing process.
*/
#define BSP_CFG_ID_CODE_LONG_1 (0x00000000)
#define BSP_CFG_ID_CODE_LONG_2 (0x00000000)
#define BSP_CFG_ID_CODE_LONG_3 (0x00000000)
#define BSP_CFG_ID_CODE_LONG_4 (0x00000000)
#else
/* ID Code: FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF */
#define BSP_CFG_ID_CODE_LONG_1 (0xFFFFFFFF)
#define BSP_CFG_ID_CODE_LONG_2 (0xFFFFFFFF)
#define BSP_CFG_ID_CODE_LONG_3 (0xFFFFFFFF)
#define BSP_CFG_ID_CODE_LONG_4 (0xffFFFFFF)
#endif
#define BSP_CFG_OPTION_SETTING_OSIS   BSP_CFG_ID_CODE_LONG_1, BSP_CFG_ID_CODE_LONG_2, BSP_CFG_ID_CODE_LONG_3, BSP_CFG_ID_CODE_LONG_4
#endif /* option_setting_osis */

#endif /* BSP_MCU_OFS_CFG_H_ */
