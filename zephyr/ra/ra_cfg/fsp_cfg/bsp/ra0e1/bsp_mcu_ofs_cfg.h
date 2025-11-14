/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <zephyr/devicetree.h>

#ifndef BSP_MCU_OFS_CFG_H_
#define BSP_MCU_OFS_CFG_H_
#ifndef BSP_CFG_OPTION_SETTING_OFS0
#define OFS_IWDT (0xFFFFA001 | 1 << 1 | 3 << 2 | 15 << 4 | 3 << 8 | 3 << 10 | 1 << 12 | 1 << 14)
#define BSP_CFG_OPTION_SETTING_OFS0  (OFS_IWDT)
#endif
#ifndef BSP_CFG_OPTION_SETTING_OFS1
#define BSP_CFG_OPTION_SETTING_OFS1_NO_HOCOFRQ  (0xE0000FC3 | (1 <<2) | (6 << 3)  \
                     | (1 << 15) | (0x3F << 22) | (0x01 << 16)  \
                     | (1 << 28))

#define BSP_CFG_OPTION_SETTING_OFS1  ((uint32_t) BSP_CFG_OPTION_SETTING_OFS1_NO_HOCOFRQ | ((uint32_t) BSP_CFG_HOCO_FREQUENCY << BSP_FEATURE_BSP_OFS1_HOCOFRQ_OFFSET))
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
#define BSP_CFG_OPTION_SETTING_OSIS   BSP_CFG_ID_CODE_LONG_1, 0xFFFFFFFF, BSP_CFG_ID_CODE_LONG_2, 0xFFFFFFFF, BSP_CFG_ID_CODE_LONG_3, 0xFFFFFFFF, BSP_CFG_ID_CODE_LONG_4
#endif /* option_setting_osis */
#endif /* BSP_MCU_OFS_CFG_H_ */
