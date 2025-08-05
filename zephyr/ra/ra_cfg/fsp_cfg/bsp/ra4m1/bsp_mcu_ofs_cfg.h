/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_OFS_CFG_H_
#define BSP_MCU_OFS_CFG_H_
#define OFS_IWDT (0xA001A001 | 1 << 1 | 3 << 2 | 15 << 4 | 3 << 8 | 3 << 10 | 1 << 12 | 1 << 14)
#define OFS_WDT  (1 << 17 | 3 << 18 | 15 << 20 | 3 << 24 | 3 << 26 | 1 << 28 | 1 << 30)
#define BSP_CFG_OPTION_SETTING_OFS0  (OFS_IWDT | OFS_WDT)
#define BSP_CFG_OPTION_SETTING_OFS1_NO_HOCOFRQ (0xFFFF8EC3 | (1 <<2) | (3 << 3) | (1 << 8))

#define BSP_CFG_OPTION_SETTING_OFS1  ((uint32_t) BSP_CFG_OPTION_SETTING_OFS1_NO_HOCOFRQ | ((uint32_t) BSP_CFG_HOCO_FREQUENCY << BSP_FEATURE_BSP_OFS1_HOCOFRQ_OFFSET))

#ifndef BSP_CFG_OPTION_SETTING_SECMPU 
#define BSP_CFG_OPTION_SETTING_SECMPU 0x0003FFFC,0x0003FFFF,0x0003FFFC,0x0003FFFF,0x0003FFFC,0x0003FFFF,0x20007FFC,0x20007FFF,0x400DFFFC,0x400DFFFF,0x400DFFFC,0x400DFFFF,0xFFFFFFFF
#endif
/*
 ID Code
 Note: To lock and disable the debug interface define BSP_ID_CODE_LOCKED in compiler settings.
 WARNING: This will disable debug access to the part. However, ALeRASE command will be accepted, which will clear (reset) the ID code. After clearing ID code, debug access will be enabled.
 Please read the HWM for full details of the clearing process.
 */
#if defined(BSP_ID_CODE_LOCKED)
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
#define BSP_CFG_OPTION_SETTING_OSIS   BSP_CFG_ID_CODE_LONG_1, 0xFFFFFFFF, BSP_CFG_ID_CODE_LONG_2, 0xFFFFFFFF, BSP_CFG_ID_CODE_LONG_3, 0xFFFFFFFF, BSP_CFG_ID_CODE_LONG_4, 0xFFFFFFFF
#endif /* BSP_MCU_OFS_CFG_H_ */
