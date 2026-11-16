/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"                   /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */
#include "bsp_opbt_driver.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * OPBT setting
 **********************************************************************************************************************/
#if BSP_OPBT_CFG_SETTING_ENABLE
BSP_PRAGMA_PLACE_IN_SECTION(BSP_PRAGMA_SECTION_ROM_DATA, BSP_PRAGMA_SECTION_OPTION_BYTE)
const bsp_opbt_setting_t g_bsp_OPBT_setting =
{
/* SOFTWARE CONFIGURATION OPBT 0 **********************************************/
    .SW_CFG_OPBT_0_setting            = BSP_OPBT_SW_CFG_OPTION_0,

/* SOFTWARE CONFIGURATION OPBT 1 **********************************************/
    .SW_CFG_OPBT_1_setting            = BSP_OPBT_SW_CFG_OPTION_1,

/* SOFTWARE CONFIGURATION OPBT 2 **********************************************/
    .SW_CFG_OPBT_2_setting            = BSP_OPBT_SW_CFG_OPTION_2,

/* SOFTWARE CONFIGURATION OPBT 3 **********************************************/
    .SW_CFG_OPBT_3_setting            = BSP_OPBT_SW_CFG_OPTION_3,

/* SOFTWARE CONFIGURATION OPBT 4 **********************************************/
    .SW_CFG_OPBT_4_setting            = BSP_OPBT_SW_CFG_OPTION_4,

/* SOFTWARE CONFIGURATION OPBT 5 **********************************************/
    .SW_CFG_OPBT_5_setting            = BSP_OPBT_SW_CFG_OPTION_5,

/* SOFTWARE CONFIGURATION OPBT 6 **********************************************/
    .SW_CFG_OPBT_6_setting            = BSP_OPBT_SW_CFG_OPTION_6,

/* SOFTWARE CONFIGURATION OPBT 7 **********************************************/
    .SW_CFG_OPBT_7_setting            = BSP_OPBT_SW_CFG_OPTION_7,

/* SOFTWARE CONFIGURATION OPBT 8 **********************************************/
    .SW_CFG_OPBT_8_setting            = BSP_OPBT_SW_CFG_OPTION_8,

/* SOFTWARE CONFIGURATION OPBT 9 **********************************************/
    .SW_CFG_OPBT_9_setting            = BSP_OPBT_SW_CFG_OPTION_9,

/* SOFTWARE CONFIGURATION OPBT 10 *********************************************/
    .SW_CFG_OPBT_10_setting           = BSP_OPBT_SW_CFG_OPTION_10,

/* SOFTWARE CONFIGURATION OPBT 11 *********************************************/
    .SW_CFG_OPBT_11_setting           = BSP_OPBT_SW_CFG_OPTION_11,

/* SOFTWARE CONFIGURATION OPBT 12 *********************************************/
    .SW_CFG_OPBT_12_setting           = BSP_OPBT_SW_CFG_OPTION_12,

/* SOFTWARE CONFIGURATION OPBT 13 *********************************************/
    .SW_CFG_OPBT_13_setting           = BSP_OPBT_SW_CFG_OPTION_13,

/* SOFTWARE CONFIGURATION OPBT 14 *********************************************/
    .SW_CFG_OPBT_14_setting           = BSP_OPBT_SW_CFG_OPTION_14,

/* SOFTWARE CONFIGURATION OPBT 15 *********************************************/
    .SW_CFG_OPBT_15_setting           = BSP_OPBT_SW_CFG_OPTION_15,

/* SOFTWARE CONFIGURATION OPBT 16 *********************************************/
    .SW_CFG_OPBT_16_setting           = BSP_OPBT_SW_CFG_OPTION_16,

/* SOFTWARE CONFIGURATION OPBT 17 *********************************************/
    .SW_CFG_OPBT_17_setting           = BSP_OPBT_SW_CFG_OPTION_17,

/* SOFTWARE CONFIGURATION OPBT 18 *********************************************/
    .SW_CFG_OPBT_18_setting           = BSP_OPBT_SW_CFG_OPTION_18,

/* SOFTWARE CONFIGURATION OPBT 19 *********************************************/
    .SW_CFG_OPBT_19_setting           = BSP_OPBT_SW_CFG_OPTION_19,

/* SOFTWARE CONFIGURATION OPBT 20 *********************************************/
    .SW_CFG_OPBT_20_setting           = BSP_OPBT_SW_CFG_OPTION_20,

/* SOFTWARE CONFIGURATION OPBT 21 *********************************************/
    .SW_CFG_OPBT_21_setting           = BSP_OPBT_SW_CFG_OPTION_21,

/* SOFTWARE CONFIGURATION OPBT 22 *********************************************/
    .SW_CFG_OPBT_22_setting           = BSP_OPBT_SW_CFG_OPTION_22,

/* SOFTWARE CONFIGURATION OPBT 23 *********************************************/
    .SW_CFG_OPBT_23_setting           = BSP_OPBT_SW_CFG_OPTION_23,

/* SOFTWARE CONFIGURATION OPBT 24 *********************************************/
    .SW_CFG_OPBT_24_setting           = BSP_OPBT_SW_CFG_OPTION_24,

/* SOFTWARE CONFIGURATION OPBT 25 *********************************************/
    .SW_CFG_OPBT_25_setting           = BSP_OPBT_SW_CFG_OPTION_25,

/* SOFTWARE CONFIGURATION OPBT 26 *********************************************/
    .SW_CFG_OPBT_26_setting           = BSP_OPBT_SW_CFG_OPTION_26,

/* SOFTWARE CONFIGURATION OPBT 27 *********************************************/
    .SW_CFG_OPBT_27_setting           = BSP_OPBT_SW_CFG_OPTION_27,

/* SOFTWARE CONFIGURATION OPBT 28 *********************************************/
    .SW_CFG_OPBT_28_setting           = BSP_OPBT_SW_CFG_OPTION_28,

/* SOFTWARE CONFIGURATION OPBT 29 *********************************************/
    .SW_CFG_OPBT_29_setting           = BSP_OPBT_SW_CFG_OPTION_29,

/* SOFTWARE CONFIGURATION OPBT 30 *********************************************/
    .SW_CFG_OPBT_30_setting           = BSP_OPBT_SW_CFG_OPTION_30,

/* SOFTWARE CONFIGURATION OPBT 31 *********************************************/
    .SW_CFG_OPBT_31_setting           = BSP_OPBT_SW_CFG_OPTION_31,

/* RESET VECTOR ADDRESS PE0 ********************************************/
    .RESET_VECTOR_ADDRESS_PE0_setting = BSP_RESET_VECTOR_ADDRESS_PE0,

/* RESET VECTOR ADDRESS PE1 ********************************************/
    .RESET_VECTOR_ADDRESS_PE1_setting = BSP_RESET_VECTOR_ADDRESS_PE1,

/* RESET VECTOR ADDRESS PE2 ********************************************/
    .RESET_VECTOR_ADDRESS_PE2_setting = BSP_RESET_VECTOR_ADDRESS_PE2,

/* RESET VECTOR ADDRESS PE3 ********************************************/
    .RESET_VECTOR_ADDRESS_PE3_setting = BSP_RESET_VECTOR_ADDRESS_PE3,

/* RESET VECTOR ADDRESS PE4 ********************************************/
    .RESET_VECTOR_ADDRESS_PE4_setting = BSP_RESET_VECTOR_ADDRESS_PE4,

/* RESET VECTOR ADDRESS PE5 ********************************************/
    .RESET_VECTOR_ADDRESS_PE5_setting = BSP_RESET_VECTOR_ADDRESS_PE5,
    .Reserved_0 = BSP_OPBT_RESERVED_VALUE, /* Reserved */
    .Reserved_1 = BSP_OPBT_RESERVED_VALUE, /* Reserved */

/* OPBT0 **********************************************************************/
    .OPBT_OPBT0_setting               = BSP_OPBT_SETTING_OPBT0,

/* OPBT1 **********************************************************************/
    .OPBT_OPBT1_setting               = BSP_OPBT_SETTING_OPBT1,

/* OPBT2 **********************************************************************/
    .OPBT_OPBT2_setting               = BSP_OPBT_SETTING_OPBT2,

/* OPBT3 **********************************************************************/
    .OPBT_OPBT3_setting               = BSP_OPBT_SETTING_OPBT3,

/* OPBT4 **********************************************************************/
    .OPBT_OPBT4_setting               = BSP_OPBT_SETTING_OPBT4,

/* OPBT5 **********************************************************************/
    .OPBT_OPBT5_setting               = BSP_OPBT_SETTING_OPBT5,

/* OPBT6 **********************************************************************/
    .OPBT_OPBT6_setting               = BSP_OPBT_SETTING_OPBT6,

/* OPBT7 **********************************************************************/
    .OPBT_OPBT7_setting               = BSP_OPBT_SETTING_OPBT7,

/* OPBT8 **********************************************************************/
    .OPBT_OPBT8_setting               = BSP_OPBT_SETTING_OPBT8,

/* OPBT9 **********************************************************************/
    .OPBT_OPBT9_setting               = BSP_OPBT_SETTING_OPBT9,

/* OPBT10 *********************************************************************/
    .OPBT_OPBT10_setting              = BSP_OPBT_SETTING_OPBT10,

/* OPBT11 *********************************************************************/
    .OPBT_OPBT11_setting              = BSP_OPBT_SETTING_OPBT11,

/* OPBT12 *********************************************************************/
    .OPBT_OPBT12_setting              = BSP_OPBT_SETTING_OPBT12,

/* OPBT13 *********************************************************************/
    .OPBT_OPBT13_setting              = BSP_OPBT_SETTING_OPBT13,

/* OPBT14 **********************************************************************/
    .OPBT_OPBT14_setting              = BSP_OPBT_SETTING_OPBT14,

/* OPBT15 **********************************************************************/
    .OPBT_OPBT15_setting              = BSP_OPBT_SETTING_OPBT15,

/* OPBT16 **********************************************************************/
    .OPBT_OPBT16_setting              = BSP_OPBT_SETTING_OPBT16,

/* OPBT17 **********************************************************************/
    .OPBT_OPBT17_setting              = BSP_OPBT_SETTING_OPBT17,

/* OPBT18 **********************************************************************/
    .OPBT_OPBT18_setting              = BSP_OPBT_SETTING_OPBT18,

/* OPBT19 **********************************************************************/
    .OPBT_OPBT19_setting              = BSP_OPBT_SETTING_OPBT19,

/* OPBT20 **********************************************************************/
    .OPBT_OPBT20_setting              = BSP_OPBT_SETTING_OPBT20,

/* OPBT21 **********************************************************************/
    .OPBT_OPBT21_setting              = BSP_OPBT_SETTING_OPBT21,

/* OPBT22 **********************************************************************/
    .OPBT_OPBT22_setting              = BSP_OPBT_SETTING_OPBT22,

/* OPBT23 **********************************************************************/
    .OPBT_OPBT23_setting              = BSP_OPBT_SETTING_OPBT23,

/* OPBT24 **********************************************************************/
    .OPBT_OPBT24_setting              = BSP_OPBT_SETTING_OPBT24,

/* OPBT25 **********************************************************************/
    .OPBT_OPBT25_setting              = BSP_OPBT_SETTING_OPBT25,

/* OPBT26 *********************************************************************/
    .OPBT_OPBT26_setting              = BSP_OPBT_SETTING_OPBT26,

/* OPBT27 *********************************************************************/
    .OPBT_OPBT27_setting              = BSP_OPBT_SETTING_OPBT27,

/* OPBT28 **********************************************************************/
    .OPBT_OPBT28_setting              = BSP_OPBT_SETTING_OPBT28,

/* OPBT29 **********************************************************************/
    .OPBT_OPBT29_setting              = BSP_OPBT_SETTING_OPBT29,

/* OPBT30 **********************************************************************/
    .OPBT_OPBT30_setting              = BSP_OPBT_SETTING_OPBT30,

/* OPBT31 **********************************************************************/
    .OPBT_OPBT31_setting              = BSP_OPBT_SETTING_OPBT31,

/* OPBT32 **********************************************************************/
    .OPBT_OPBT32_setting              = BSP_OPBT_SETTING_OPBT32,

/* OPBT33 **********************************************************************/
    .OPBT_OPBT33_setting              = BSP_OPBT_SETTING_OPBT33,

/* OPBT34 **********************************************************************/
    .OPBT_OPBT34_setting              = BSP_OPBT_SETTING_OPBT34,

/* OPBT35 **********************************************************************/
    .OPBT_OPBT35_setting              = BSP_OPBT_SETTING_OPBT35,

/* OPBT36 **********************************************************************/
    .OPBT_OPBT36_setting              = BSP_OPBT_SETTING_OPBT36,

/* OPBT37 **********************************************************************/
    .OPBT_OPBT37_setting              = BSP_OPBT_SETTING_OPBT37,

/* OPBT38 **********************************************************************/
    .OPBT_OPBT38_setting              = BSP_OPBT_SETTING_OPBT38,

/* OPBT39 **********************************************************************/
    .OPBT_OPBT39_setting              = BSP_OPBT_SETTING_OPBT39,

/* OPBT40 **********************************************************************/
    .OPBT_OPBT40_setting              = BSP_OPBT_SETTING_OPBT40
};
BSP_PRAGMA_PLACE_IN_SECTION(BSP_PRAGMA_SECTION_ROM_DATA, BSP_PRAGMA_SECTION_DEFAULT)
#endif
