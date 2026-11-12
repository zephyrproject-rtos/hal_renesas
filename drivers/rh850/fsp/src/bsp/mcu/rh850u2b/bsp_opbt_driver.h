/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_OPBT_DRIVER_H
#define BSP_OPBT_DRIVER_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_OPBT_SWAF_BASE                                    (0xFF373800U)                                                                          ///< SWA valid side base address
#define BSP_OPBT_SWAB_BASE                                    (0xFF374000U)                                                                          ///< SWA invalid side base address

/* PRQA S 1534 ++ # Advisory R-2.5 */
#define BSP_OPBT_CVA_VALID_SIDE                               *((const volatile uint32_t *) (BSP_OPBT_SWAF_BASE + \
                                                                                             0x200U))                                                ///< CVA register in valid side

/* PRQA S 1534 -- */
#define BSP_OPBT_CVA_INVALID_SIDE                             *((volatile uint32_t *) (BSP_OPBT_SWAB_BASE + 0x200U))                                 ///< CVA register in invalid side
#define BSP_OPBT_A0PC_F                                       *((const volatile uint32_t *) (BSP_OPBT_SWAF_BASE)) /* PRQA S 1534 # Advisory R-2.5 */ ///< AnPC register in valid side
#define BSP_OPBT_A0PC_B                                       *((const volatile uint32_t *) (BSP_OPBT_SWAB_BASE))                                    ///< AnPC register in invalid side
#define BSP_OPBT_SVA_F                                        *((const volatile uint32_t *) (BSP_OPBT_SWAF_BASE + \
                                                                                             0x204U))                                                ///< SVA register in valid side

/* PRQA S 1534 ++ # Advisory R-2.5 */
#define BSP_OPBT_SVA_B                                        *((const volatile uint32_t *) (BSP_OPBT_SWAB_BASE + \
                                                                                             0x204U))                                                ///< SVA register in invalid side

/* PRQA S 1534 -- */
#define BSP_OPBT_BVA0_F                                       *((const volatile uint32_t *) (BSP_OPBT_SWAF_BASE + \
                                                                                             0x208U))                                                ///< BVA0 register in valid side

/* PRQA S 1534 ++ # Advisory R-2.5 */
#define BSP_OPBT_BVA0_B                                       *((const volatile uint32_t *) (BSP_OPBT_SWAB_BASE + \
                                                                                             0x208U))                                                ///< BVA0 register in invalid side

/* PRQA S 1534 -- */
#if (BSP_FEATURE_OPBT_BVA1_AREA_IS_AVAILABLE)
 #define BSP_OPBT_BVA1_F                                      *((const volatile uint32_t *) (BSP_OPBT_SWAF_BASE + \
                                                                                             0x20CU))                                                   ///< BVA1 register in valid side
 #define BSP_OPBT_BVA1_B                                      *((const volatile uint32_t *) (BSP_OPBT_SWAB_BASE + \
                                                                                             0x20CU))                                                   ///< BVA1 register in invalid side
#endif

#define BSP_OPBT_CSAF_BASE                                    (0xFF320800U)                                                                             ///< CSAF valid side base address
#define BSP_OPBT_CSAB_BASE                                    (0xFF321000U)                                                                             ///< CSAF invalid side base address
#define BSP_OPBT_CSAVOFCn(n)    *((volatile uint32_t *) (BSP_OPBT_CSAF_BASE + \
                                                         ((uint32_t) 0x100U + (uint32_t) (4U * n))))                                                    ///< CSAVOFCn (n = 0, 8 to 19) register in invalid side

#define BSP_OPBT_FACI0_BASE                                   (0xFFA10000U)                                                                             ///< FACI0 base address
#define BSP_OPBT_FSWASTAT_0                                   *((volatile uint32_t *) (BSP_OPBT_FACI0_BASE + 0xA8U))                                    ///< FSWASTAT_0 register
#define BSP_OPBT_FSADDR_0                                     *((volatile uint32_t *) (BSP_OPBT_FACI0_BASE + 0x30U))                                    ///< FSADDR_0 register
#define BSP_OPBT_FEADDR_0                                     *((volatile uint32_t *) (BSP_OPBT_FACI0_BASE + 0x34U)) /* PRQA S 1534 # Advisory R-2.5 */ ///< FEADDR_0 register
#define BSP_OPBT_FSTATR_0                                     *((volatile uint32_t *) (BSP_OPBT_FACI0_BASE + 0x80U))                                    ///< FSTATR_0 register
#define BSP_OPBT_FASTAT_0                                     *((volatile uint8_t *) (BSP_OPBT_FACI0_BASE + 0x10U))                                     ///< FASTAT_0 register
#define BSP_OPBT_FENTRYR_0                                    *((volatile uint16_t *) (BSP_OPBT_FACI0_BASE + 0x84U))                                    ///< FENTRYR_0 register
#define BSP_OPBT_FSUINITR_0                                   *((volatile uint16_t *) (BSP_OPBT_FACI0_BASE + 0x8CU)) /* PRQA S 1534 # Advisory R-2.5 */ ///< FSUINITR_0 register

#define BSP_OPBT_TAG_BASE                                     (0xFF374800U)                                                                             ///< TAG base address
#define BSP_OPBT_VAPC                                         *((const volatile uint32_t *) (BSP_OPBT_TAG_BASE))                                        ///< VAPC register
#define BSP_OPBT_VAF                                          *((const volatile uint32_t *) (BSP_OPBT_TAG_BASE + \
                                                                                             0x200U))                                                   ///< VAF register

#define BSP_OPBT_FACI0_COMMAND_ISSUING_AREA_BASE              (0xFFA20000U)                                                                             ///< FACI0 command issue base address

#define BSP_OPBT_SWITCH_AREA_IS_PROGRAMMED                    (0x5AA5A55AU)                                                                             ///< Value indicates that the Switch Area is programmed

#define BSP_OPBT_BSP_CONFIGURATION_SETTING_AREA_0_VALID       (0xA55A5AA5U)                                                                             ///< Configuration Setting Area 0 will be chosen as valid area
#define BSP_OPBT_BSP_CONFIGURATION_SETTING_AREA_1_VALID       (0x5AA5A55AU)                                                                             ///< Configuration Setting Area 1 will be chosen as valid area

#define BSP_OPBT_FHVE_BASE                                    (0xFF984800U)                                                                             ///< FHVE base address
#define BSP_OPBT_FHVE3FP_0                                    *((volatile uint32_t *) (BSP_OPBT_FHVE_BASE))                                             ///< FHVE3FP_0 register
#define BSP_OPBT_FHVE15FP_0                                   *((volatile uint32_t *) (BSP_OPBT_FHVE_BASE + 0x04U))                                     ///< FHVE15FP_0 register

#define BSP_OPBT_NUMBER_OF_OPBT_REGS                          96U                                                                                       ///< Number of OPBT registers need to be flashed (must be divided by 8)
#define BSP_OPBT_NUMBER_OF_OTP_REGS                           8U                                                                                        ///< Number of OTP registers need to be flashed (must be divided by 8)
#define BSP_OPBT_REGISTER_OFFSET                              40U                                                                                       ///< Offset applied for OPBT register

#define BSP_OPBT_FASTAT_0_CFAE_BIT_MSK                        ((uint32_t) 1U << 7)                                                                      ///< CFAE bit Mask of FASTAT_0 register
#define BSP_OPBT_FASTAT_0_CMDLK_BIT_MSK                       ((uint32_t) 1U << 4)                                                                      ///< CMDLK bit Mask of FASTAT_0 register
#define BSP_OPBT_FASTAT_0_DFAE_BIT_MSK                        ((uint32_t) 1U << 3)                                                                      ///< DFAE bit Mask of FASTAT_0 register
#define BSP_OPBT_FSTATR_0_FRDY_BIT_MSK                        ((uint32_t) 1U << 15)                                                                     ///< FRDY bit Mask of FSTATR_0 register
#define BSP_OPBT_FSTATR_0_ILGLERR_BIT_MSK                     ((uint32_t) 1U << 14)                                                                     ///< ILGLERR bit Mask of FSTATR_0 register
#define BSP_OPBT_FSWASTAT_0_CFGVA_BIT_MSK                     ((uint32_t) 1U << 2)                                                                      ///< CFGVA bit Mask of FSWASTAT_0 register
#define BSP_OPBT_FENTRYR_0_FENTRYD_BIT_MSK                    ((uint32_t) 1U << 7)                                                                      ///< FENTRYD bit Mask of FENTRYR_0 register

#define BSP_OPBT_OPTION_BYTE_OFFSET                           (0x3A0U)                                                                                  ///< Offset applied for Option Byte base address
#define BSP_OPBT_SOFTWARE_CONFIGURATION_OPTION_BYTE_OFFSET    (0x300U)                                                                                  ///< Offset applied for Software Configuration Option Byte base address
#define BSP_OPBT_OTP_SETTING_OFFSET                           (0x200U)                                                                                  ///< Offset applied for OPT Setting base address
#define BSP_OPBT_CVA_OFFSET                                   (0x200U)                                                                                  ///< Offset applied for CVA register base address
#define BSP_OPBT_VAF_OFFSET                                   (0x200U)                                                                                  ///< Offset applied for VAF register base address

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU_RH850U2BX
 * @defgroup BSP_OPBT_U2BX BSP Option Bytes
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** OPBT Configuration Enum Definition */
typedef enum e_bsp_configuration_area                /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_0,          ///< SOFTWARE CONFIGURATION OPBT 0
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_1,          ///< SOFTWARE CONFIGURATION OPBT 1
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_2,          ///< SOFTWARE CONFIGURATION OPBT 2
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_3,          ///< SOFTWARE CONFIGURATION OPBT 3
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_4,          ///< SOFTWARE CONFIGURATION OPBT 4
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_5,          ///< SOFTWARE CONFIGURATION OPBT 5
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_6,          ///< SOFTWARE CONFIGURATION OPBT 6
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_7,          ///< SOFTWARE CONFIGURATION OPBT 7
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_8,          ///< SOFTWARE CONFIGURATION OPBT 8
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_9,          ///< SOFTWARE CONFIGURATION OPBT 9
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_10,         ///< SOFTWARE CONFIGURATION OPBT 10
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_11,         ///< SOFTWARE CONFIGURATION OPBT 11
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_12,         ///< SOFTWARE CONFIGURATION OPBT 12
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_13,         ///< SOFTWARE CONFIGURATION OPBT 13
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_14,         ///< SOFTWARE CONFIGURATION OPBT 14
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_15,         ///< SOFTWARE CONFIGURATION OPBT 15
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_16,         ///< SOFTWARE CONFIGURATION OPBT 16
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_17,         ///< SOFTWARE CONFIGURATION OPBT 17
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_18,         ///< SOFTWARE CONFIGURATION OPBT 18
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_19,         ///< SOFTWARE CONFIGURATION OPBT 19
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_20,         ///< SOFTWARE CONFIGURATION OPBT 20
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_21,         ///< SOFTWARE CONFIGURATION OPBT 21
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_22,         ///< SOFTWARE CONFIGURATION OPBT 22
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_23,         ///< SOFTWARE CONFIGURATION OPBT 23
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_24,         ///< SOFTWARE CONFIGURATION OPBT 24
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_25,         ///< SOFTWARE CONFIGURATION OPBT 25
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_26,         ///< SOFTWARE CONFIGURATION OPBT 26
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_27,         ///< SOFTWARE CONFIGURATION OPBT 27
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_28,         ///< SOFTWARE CONFIGURATION OPBT 28
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_29,         ///< SOFTWARE CONFIGURATION OPBT 29
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_30,         ///< SOFTWARE CONFIGURATION OPBT 30
    BSP_CONFIGURATION_AREA_SW_CFG_OPTION_31,         ///< SOFTWARE CONFIGURATION OPBT 31
    BSP_CONFIGURATION_AREA_RESET_VECTOR_ADDRESS_PE0, ///< RESET VECTOR ADDRESS PE0
    BSP_CONFIGURATION_AREA_RESET_VECTOR_ADDRESS_PE1, ///< RESET VECTOR ADDRESS PE1
    BSP_CONFIGURATION_AREA_RESET_VECTOR_ADDRESS_PE2, ///< RESET VECTOR ADDRESS PE2
    BSP_CONFIGURATION_AREA_RESET_VECTOR_ADDRESS_PE3, ///< RESET VECTOR ADDRESS PE3
    BSP_CONFIGURATION_AREA_RESET_VECTOR_ADDRESS_PE4, ///< RESET VECTOR ADDRESS PE4
    BSP_CONFIGURATION_AREA_RESET_VECTOR_ADDRESS_PE5, ///< RESET VECTOR ADDRESS PE5
    BSP_CONFIGURATION_AREA_RESERVED_0,               ///< Reserved 0
    BSP_CONFIGURATION_AREA_RESERVED_1,               ///< Reserved 1
    BSP_CONFIGURATION_AREA_SETTING_OPBT0,            ///< OPBT0
    BSP_CONFIGURATION_AREA_SETTING_OPBT1,            ///< OPBT1
    BSP_CONFIGURATION_AREA_SETTING_OPBT2,            ///< OPBT2
    BSP_CONFIGURATION_AREA_SETTING_OPBT3,            ///< OPBT3
    BSP_CONFIGURATION_AREA_SETTING_OPBT4,            ///< OPBT4
    BSP_CONFIGURATION_AREA_SETTING_OPBT5,            ///< OPBT5
    BSP_CONFIGURATION_AREA_SETTING_OPBT6,            ///< OPBT6
    BSP_CONFIGURATION_AREA_SETTING_OPBT7,            ///< OPBT7
    BSP_CONFIGURATION_AREA_SETTING_OPBT8,            ///< OPBT8
    BSP_CONFIGURATION_AREA_SETTING_OPBT9,            ///< OPBT9
    BSP_CONFIGURATION_AREA_SETTING_OPBT10,           ///< OPBT10
    BSP_CONFIGURATION_AREA_SETTING_OPBT11,           ///< OPBT11
    BSP_CONFIGURATION_AREA_SETTING_OPBT12,           ///< OPBT12
    BSP_CONFIGURATION_AREA_SETTING_OPBT13,           ///< OPBT13
    BSP_CONFIGURATION_AREA_SETTING_OPBT14,           ///< OPBT14
    BSP_CONFIGURATION_AREA_SETTING_OPBT15,           ///< OPBT15
    BSP_CONFIGURATION_AREA_SETTING_OPBT16,           ///< OPBT16
    BSP_CONFIGURATION_AREA_SETTING_OPBT17,           ///< OPBT17
    BSP_CONFIGURATION_AREA_SETTING_OPBT18,           ///< OPBT18
    BSP_CONFIGURATION_AREA_SETTING_OPBT19,           ///< OPBT19
    BSP_CONFIGURATION_AREA_SETTING_OPBT20,           ///< OPBT20
    BSP_CONFIGURATION_AREA_SETTING_OPBT21,           ///< OPBT21
    BSP_CONFIGURATION_AREA_SETTING_OPBT22,           ///< OPBT22
    BSP_CONFIGURATION_AREA_SETTING_OPBT23,           ///< OPBT23
    BSP_CONFIGURATION_AREA_SETTING_OPBT24,           ///< OPBT24
    BSP_CONFIGURATION_AREA_SETTING_OPBT25,           ///< OPBT25
    BSP_CONFIGURATION_AREA_SETTING_OPBT26,           ///< OPBT26
    BSP_CONFIGURATION_AREA_SETTING_OPBT27,           ///< OPBT27
    BSP_CONFIGURATION_AREA_SETTING_OPBT28,           ///< OPBT28
    BSP_CONFIGURATION_AREA_SETTING_OPBT29,           ///< OPBT29
    BSP_CONFIGURATION_AREA_SETTING_OPBT30,           ///< OPBT30
    BSP_CONFIGURATION_AREA_SETTING_OPBT31,           ///< OPBT31
    BSP_CONFIGURATION_AREA_SETTING_OPBT32,           ///< OPBT32
    BSP_CONFIGURATION_AREA_SETTING_OPBT33,           ///< OPBT33
    BSP_CONFIGURATION_AREA_SETTING_OPBT34,           ///< OPBT34
    BSP_CONFIGURATION_AREA_SETTING_OPBT35,           ///< OPBT35
    BSP_CONFIGURATION_AREA_SETTING_OPBT36,           ///< OPBT36
    BSP_CONFIGURATION_AREA_SETTING_OPBT37,           ///< OPBT37
    BSP_CONFIGURATION_AREA_SETTING_OPBT38,           ///< OPBT38
    BSP_CONFIGURATION_AREA_SETTING_OPBT39,           ///< OPBT39
    BSP_CONFIGURATION_AREA_SETTING_OPBT40,           ///< OPBT40
    BSP_CONFIGURATION_AREA_NUMS
} bsp_configuration_area_t;

/** OPBT Configuration */
typedef const struct st_bsp_opbt_setting             /* PRQA S 1536 # Advisory R-2.4 */
{
    /* Software Configuration Option Byte (OPBT n = 0 to 31) */
    const uint32_t SW_CFG_OPBT_0_setting;            ///< Software configuration option byte 0
    const uint32_t SW_CFG_OPBT_1_setting;            ///< Software configuration option byte 1
    const uint32_t SW_CFG_OPBT_2_setting;            ///< Software configuration option byte 2
    const uint32_t SW_CFG_OPBT_3_setting;            ///< Software configuration option byte 3
    const uint32_t SW_CFG_OPBT_4_setting;            ///< Software configuration option byte 4
    const uint32_t SW_CFG_OPBT_5_setting;            ///< Software configuration option byte 5
    const uint32_t SW_CFG_OPBT_6_setting;            ///< Software configuration option byte 6
    const uint32_t SW_CFG_OPBT_7_setting;            ///< Software configuration option byte 7
    const uint32_t SW_CFG_OPBT_8_setting;            ///< Software configuration option byte 8
    const uint32_t SW_CFG_OPBT_9_setting;            ///< Software configuration option byte 9
    const uint32_t SW_CFG_OPBT_10_setting;           ///< Software configuration option byte 10
    const uint32_t SW_CFG_OPBT_11_setting;           ///< Software configuration option byte 11
    const uint32_t SW_CFG_OPBT_12_setting;           ///< Software configuration option byte 12
    const uint32_t SW_CFG_OPBT_13_setting;           ///< Software configuration option byte 13
    const uint32_t SW_CFG_OPBT_14_setting;           ///< Software configuration option byte 14
    const uint32_t SW_CFG_OPBT_15_setting;           ///< Software configuration option byte 15
    const uint32_t SW_CFG_OPBT_16_setting;           ///< Software configuration option byte 16
    const uint32_t SW_CFG_OPBT_17_setting;           ///< Software configuration option byte 17
    const uint32_t SW_CFG_OPBT_18_setting;           ///< Software configuration option byte 18
    const uint32_t SW_CFG_OPBT_19_setting;           ///< Software configuration option byte 19
    const uint32_t SW_CFG_OPBT_20_setting;           ///< Software configuration option byte 20
    const uint32_t SW_CFG_OPBT_21_setting;           ///< Software configuration option byte 21
    const uint32_t SW_CFG_OPBT_22_setting;           ///< Software configuration option byte 22
    const uint32_t SW_CFG_OPBT_23_setting;           ///< Software configuration option byte 23
    const uint32_t SW_CFG_OPBT_24_setting;           ///< Software configuration option byte 24
    const uint32_t SW_CFG_OPBT_25_setting;           ///< Software configuration option byte 25
    const uint32_t SW_CFG_OPBT_26_setting;           ///< Software configuration option byte 26
    const uint32_t SW_CFG_OPBT_27_setting;           ///< Software configuration option byte 27
    const uint32_t SW_CFG_OPBT_28_setting;           ///< Software configuration option byte 28
    const uint32_t SW_CFG_OPBT_29_setting;           ///< Software configuration option byte 29
    const uint32_t SW_CFG_OPBT_30_setting;           ///< Software configuration option byte 30
    const uint32_t SW_CFG_OPBT_31_setting;           ///< Software configuration option byte 31

    /* Reset Vector Address (PE0 to PE5) */
    const uint32_t RESET_VECTOR_ADDRESS_PE0_setting; ///< Reset vector address for PE0
    const uint32_t RESET_VECTOR_ADDRESS_PE1_setting; ///< Reset vector address for PE1
    const uint32_t RESET_VECTOR_ADDRESS_PE2_setting; ///< Reset vector address for PE2
    const uint32_t RESET_VECTOR_ADDRESS_PE3_setting; ///< Reset vector address for PE3
    const uint32_t RESET_VECTOR_ADDRESS_PE4_setting; ///< Reset vector address for PE4
    const uint32_t RESET_VECTOR_ADDRESS_PE5_setting; ///< Reset vector address for PE5

    const uint32_t Reserved_0;                       ///< Reserved field 0
    const uint32_t Reserved_1;                       ///< Reserved field 1

    /* OPBT setting values (OPBT0 to OPBT40) */
    const uint32_t OPBT_OPBT0_setting;               ///< Option byte setting 0
    const uint32_t OPBT_OPBT1_setting;               ///< Option byte setting 1
    const uint32_t OPBT_OPBT2_setting;               ///< Option byte setting 2
    const uint32_t OPBT_OPBT3_setting;               ///< Option byte setting 3
    const uint32_t OPBT_OPBT4_setting;               ///< Option byte setting 4
    const uint32_t OPBT_OPBT5_setting;               ///< Option byte setting 5
    const uint32_t OPBT_OPBT6_setting;               ///< Option byte setting 6
    const uint32_t OPBT_OPBT7_setting;               ///< Option byte setting 7
    const uint32_t OPBT_OPBT8_setting;               ///< Option byte setting 8
    const uint32_t OPBT_OPBT9_setting;               ///< Option byte setting 9
    const uint32_t OPBT_OPBT10_setting;              ///< Option byte setting 10
    const uint32_t OPBT_OPBT11_setting;              ///< Option byte setting 11
    const uint32_t OPBT_OPBT12_setting;              ///< Option byte setting 12
    const uint32_t OPBT_OPBT13_setting;              ///< Option byte setting 13
    const uint32_t OPBT_OPBT14_setting;              ///< Option byte setting 14
    const uint32_t OPBT_OPBT15_setting;              ///< Option byte setting 15
    const uint32_t OPBT_OPBT16_setting;              ///< Option byte setting 16
    const uint32_t OPBT_OPBT17_setting;              ///< Option byte setting 17
    const uint32_t OPBT_OPBT18_setting;              ///< Option byte setting 18
    const uint32_t OPBT_OPBT19_setting;              ///< Option byte setting 19
    const uint32_t OPBT_OPBT20_setting;              ///< Option byte setting 20
    const uint32_t OPBT_OPBT21_setting;              ///< Option byte setting 21
    const uint32_t OPBT_OPBT22_setting;              ///< Option byte setting 22
    const uint32_t OPBT_OPBT23_setting;              ///< Option byte setting 23
    const uint32_t OPBT_OPBT24_setting;              ///< Option byte setting 24
    const uint32_t OPBT_OPBT25_setting;              ///< Option byte setting 25
    const uint32_t OPBT_OPBT26_setting;              ///< Option byte setting 26
    const uint32_t OPBT_OPBT27_setting;              ///< Option byte setting 27
    const uint32_t OPBT_OPBT28_setting;              ///< Option byte setting 28
    const uint32_t OPBT_OPBT29_setting;              ///< Option byte setting 29
    const uint32_t OPBT_OPBT30_setting;              ///< Option byte setting 30
    const uint32_t OPBT_OPBT31_setting;              ///< Option byte setting 31
    const uint32_t OPBT_OPBT32_setting;              ///< Option byte setting 32
    const uint32_t OPBT_OPBT33_setting;              ///< Option byte setting 33
    const uint32_t OPBT_OPBT34_setting;              ///< Option byte setting 34
    const uint32_t OPBT_OPBT35_setting;              ///< Option byte setting 35
    const uint32_t OPBT_OPBT36_setting;              ///< Option byte setting 36
    const uint32_t OPBT_OPBT37_setting;              ///< Option byte setting 37
    const uint32_t OPBT_OPBT38_setting;              ///< Option byte setting 38
    const uint32_t OPBT_OPBT39_setting;              ///< Option byte setting 39
    const uint32_t OPBT_OPBT40_setting;              ///< Option byte setting 40
} bsp_opbt_setting_t;

/** @} (end addtogroup BSP_MCU_RH850U2BX) */

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
BSP_PRAGMA_PLACE_IN_SECTION(BSP_PRAGMA_SECTION_ROM_DATA, BSP_PRAGMA_SECTION_OPTION_BYTE)
extern const bsp_opbt_setting_t g_bsp_OPBT_setting; /* PRQA S 1752 # DP_MSR_R-8.6_UC1 */
BSP_PRAGMA_PLACE_IN_SECTION(BSP_PRAGMA_SECTION_ROM_DATA, BSP_PRAGMA_SECTION_DEFAULT)

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_OPBT_DRIVER_H */
