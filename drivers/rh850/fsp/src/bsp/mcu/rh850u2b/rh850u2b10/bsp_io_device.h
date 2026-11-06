/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IO_DEVICE_H
#define BSP_IO_DEVICE_H

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU_RH850U2B10
 * @defgroup BSP_IO_U2B10 BSP I/O access
 * @brief This module provides basic read/write access to port pins.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define R_BSP_JPORT                ((R_PORT_Type *) 0xFFDA0000) ///< Base address of JPORT instance
#define R_BSP_APORT                ((R_PORT_Type *) NULL)       ///< APORT instance not available (NULL)

#define BSP_PACKAGE_PINS_BGA468    (468U)                       ///< Package pin count: BGA468
#define BSP_PACKAGE_PINS_BGA373    (373U)                       ///< Package pin count: BGA373
#define BSP_PACKAGE_PINS_BGA292    (292U)                       ///< Package pin count: BGA292

#define BSP_IO_PORT_P00_PWE        (0)                          ///< PWE value for P00
#define BSP_IO_PORT_P01_PWE        (1)                          ///< PWE value for P01
#define BSP_IO_PORT_P02_PWE        (2)                          ///< PWE value for P02
#define BSP_IO_PORT_P10_PWE        (3)                          ///< PWE value for P10
#define BSP_IO_PORT_P11_PWE        (4)                          ///< PWE value for P11
#define BSP_IO_PORT_P12_PWE        (5)                          ///< PWE value for P12
#define BSP_IO_PORT_P13_PWE        (6)                          ///< PWE value for P13
#define BSP_IO_PORT_P14_PWE        (7)                          ///< PWE value for P14
#define BSP_IO_PORT_P15_PWE        (8)                          ///< PWE value for P15

#define BSP_IO_PORT_P20_PWE        (9)                          ///< PWE value for P20
#define BSP_IO_PORT_P21_PWE        (10)                         ///< PWE value for P21
#define BSP_IO_PORT_P22_PWE        (11)                         ///< PWE value for P22
#define BSP_IO_PORT_P23_PWE        (12)                         ///< PWE value for P23
#define BSP_IO_PORT_P24_PWE        (13)                         ///< PWE value for P24
#define BSP_IO_PORT_P25_PWE        (14)                         ///< PWE value for P25
#define BSP_IO_PORT_P27_PWE        (16)                         ///< PWE value for P27

#define BSP_IO_PORT_P30_PWE        (17)                         ///< PWE value for P30
#define BSP_IO_PORT_P31_PWE        (18)                         ///< PWE value for P31
#define BSP_IO_PORT_P32_PWE        (19)                         ///< PWE value for P32
#define BSP_IO_PORT_P33_PWE        (20)                         ///< PWE value for P33
#define BSP_IO_PORT_P34_PWE        (21)                         ///< PWE value for P34

#define BSP_IO_PORT_JP00_PWE       (255)                        ///< PWE value for JP00
#define BSP_IO_PORT_P40_PWE        (255)                        ///< PWE value for P40
#define BSP_IO_PORT_P37_PWE        (255)                        ///< PWE value for P37
#define BSP_IO_PORT_P38_PWE        (255)                        ///< PWE value for P38
#define BSP_IO_PORT_P39_PWE        (255)                        ///< PWE value for P39
#define BSP_IO_PORT_P41_PWE        (255)                        ///< PWE value for P41
#define BSP_IO_PORT_P42_PWE        (255)                        ///< PWE value for P42
#define BSP_IO_PORT_P43_PWE        (255)                        ///< PWE value for P43
#define BSP_IO_PORT_P44_PWE        (255)                        ///< PWE value for P44
#define BSP_IO_PORT_P45_PWE        (255)                        ///< PWE value for P45
#define BSP_IO_PORT_P46_PWE        (255)                        ///< PWE value for P46
#define BSP_IO_PORT_P47_PWE        (255)                        ///< PWE value for P47
#define BSP_IO_PORT_P48_PWE        (255)                        ///< PWE value for P48
#define BSP_IO_PORT_P49_PWE        (255)                        ///< PWE value for P49
#define BSP_IO_PORT_P50_PWE        (255)                        ///< PWE value for P50
#define BSP_IO_PORT_P51_PWE        (255)                        ///< PWE value for P51
#define BSP_IO_PORT_P52_PWE        (255)                        ///< PWE value for P52
#define BSP_IO_PORT_P53_PWE        (255)                        ///< PWE value for P53
#define BSP_IO_PORT_P54_PWE        (255)                        ///< PWE value for P54
#define BSP_IO_PORT_P55_PWE        (255)                        ///< PWE value for P55
#define BSP_IO_PORT_P56_PWE        (255)                        ///< PWE value for P56

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Superset list of all possible IO ports. */
/* BSP_IO_PORT_[TYPE][GROUP] = [PWE] << 24U | [TYPE] << 16U | [GROUP] << 8U | [PORT] */
/* PRQA S 1507 ++ # DP_MSR_R-5.6_UC1 */
typedef enum e_bsp_io_port_u2b10                                                                                                                                                                      /* PRQA S 1536 # Advisory R-2.4 */
{
#if (BSP_PACKAGE_PINS_BGA292 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00  = ((BSP_IO_PORT_P00_PWE << 24U) | (0 << 16U) | (0 << 8U) | 0),                                                                                                                   ///< IO port P00
    BSP_IO_PORT_P02  = ((BSP_IO_PORT_P02_PWE << 24U) | (0 << 16U) | (2 << 8U) | 0),                                                                                                                   ///< IO port P02
    BSP_IO_PORT_P10  = ((BSP_IO_PORT_P10_PWE << 24U) | (0 << 16U) | (10 << 8U) | 0),                                                                                                                  ///< IO port P10
    BSP_IO_PORT_P11  = ((BSP_IO_PORT_P11_PWE << 24U) | (0 << 16U) | (11 << 8U) | 0),                                                                                                                  ///< IO port P11
    BSP_IO_PORT_P12  = ((BSP_IO_PORT_P12_PWE << 24U) | (0 << 16U) | (12 << 8U) | 0),                                                                                                                  ///< IO port P12
    BSP_IO_PORT_P13  = ((BSP_IO_PORT_P13_PWE << 24U) | (0 << 16U) | (13 << 8U) | 0),                                                                                                                  ///< IO port P13
    BSP_IO_PORT_P14  = ((BSP_IO_PORT_P14_PWE << 24U) | (0 << 16U) | (14 << 8U) | 0),                                                                                                                  ///< IO port P14
    BSP_IO_PORT_P20  = ((BSP_IO_PORT_P20_PWE << 24U) | (0 << 16U) | (20 << 8U) | 0),                                                                                                                  ///< IO port P20
    BSP_IO_PORT_P21  = ((BSP_IO_PORT_P21_PWE << 24U) | (0 << 16U) | (21 << 8U) | 0),                                                                                                                  ///< IO port P21
    BSP_IO_PORT_P22  = ((BSP_IO_PORT_P22_PWE << 24U) | (0 << 16U) | (22 << 8U) | 0),                                                                                                                  ///< IO port P22
    BSP_IO_PORT_P23  = ((BSP_IO_PORT_P23_PWE << 24U) | (0 << 16U) | (23 << 8U) | 0),                                                                                                                  ///< IO port P23
    BSP_IO_PORT_P25  = ((BSP_IO_PORT_P25_PWE << 24U) | (0 << 16U) | (25 << 8U) | 0),                                                                                                                  ///< IO port P25
    BSP_IO_PORT_P32  = ((BSP_IO_PORT_P32_PWE << 24U) | (0 << 16U) | (32 << 8U) | 0),                                                                                                                  ///< IO port P32
    BSP_IO_PORT_P33  = ((BSP_IO_PORT_P33_PWE << 24U) | (0 << 16U) | (33 << 8U) | 0),                                                                                                                  ///< IO port P33
    BSP_IO_PORT_P34  = ((BSP_IO_PORT_P34_PWE << 24U) | (0 << 16U) | (34 << 8U) | 0),                                                                                                                  ///< IO port P34
    BSP_IO_PORT_P27  = ((BSP_IO_PORT_P27_PWE << 24U) | (0 << 16U) | (27 << 8U) | 0),                                                                                                                  ///< IO port P27
    BSP_IO_PORT_JP00 = ((BSP_IO_PORT_JP00_PWE << 24U) | (1 << 16U) | (0 << 8U) | 0),                                                                                                                  ///< IO port JP00
    BSP_IO_PORT_P40  = ((BSP_IO_PORT_P40_PWE << 24U) | (0 << 16U) | (40 << 8U) | 0),                                                                                                                  ///< IO port P40
    BSP_IO_PORT_P37  = ((BSP_IO_PORT_P37_PWE << 24U) | (0 << 16U) | (37 << 8U) | 0),                                                                                                                  ///< IO port P37
    BSP_IO_PORT_P38  = ((BSP_IO_PORT_P38_PWE << 24U) | (0 << 16U) | (38 << 8U) | 0),                                                                                                                  ///< IO port P38
    BSP_IO_PORT_P39  = ((BSP_IO_PORT_P39_PWE << 24U) | (0 << 16U) | (39 << 8U) | 0),                                                                                                                  ///< IO port P39
    BSP_IO_PORT_P41  = ((BSP_IO_PORT_P41_PWE << 24U) | (0 << 16U) | (41 << 8U) | 0),                                                                                                                  ///< IO port P41
    BSP_IO_PORT_P42  = ((BSP_IO_PORT_P42_PWE << 24U) | (0 << 16U) | (42 << 8U) | 0),                                                                                                                  ///< IO port P42
    BSP_IO_PORT_P43  = ((BSP_IO_PORT_P43_PWE << 24U) | (0 << 16U) | (43 << 8U) | 0),                                                                                                                  ///< IO port P43
    BSP_IO_PORT_P44  = ((BSP_IO_PORT_P44_PWE << 24U) | (0 << 16U) | (44 << 8U) | 0),                                                                                                                  ///< IO port P44
    BSP_IO_PORT_P45  = ((BSP_IO_PORT_P45_PWE << 24U) | (0 << 16U) | (45 << 8U) | 0),                                                                                                                  ///< IO port P45
    BSP_IO_PORT_P46  = ((BSP_IO_PORT_P46_PWE << 24U) | (0 << 16U) | (46 << 8U) | 0),                                                                                                                  ///< IO port P46
    BSP_IO_PORT_P47  = ((BSP_IO_PORT_P47_PWE << 24U) | (0 << 16U) | (47 << 8U) | 0),                                                                                                                  ///< IO port P47
    BSP_IO_PORT_P48  = ((BSP_IO_PORT_P48_PWE << 24U) | (0 << 16U) | (48 << 8U) | 0),                                                                                                                  ///< IO port P48
    BSP_IO_PORT_P49  = ((BSP_IO_PORT_P49_PWE << 24U) | (0 << 16U) | (49 << 8U) | 0),                                                                                                                  ///< IO port P49
    BSP_IO_PORT_P50  = ((BSP_IO_PORT_P50_PWE << 24U) | (0 << 16U) | (50 << 8U) | 0),                                                                                                                  ///< IO port P50
    BSP_IO_PORT_P51  = ((BSP_IO_PORT_P51_PWE << 24U) | (0 << 16U) | (51 << 8U) | 0),                                                                                                                  ///< IO port P51
    BSP_IO_PORT_P52  = ((BSP_IO_PORT_P52_PWE << 24U) | (0 << 16U) | (52 << 8U) | 0),                                                                                                                  ///< IO port P52
    BSP_IO_PORT_P53  = ((BSP_IO_PORT_P53_PWE << 24U) | (0 << 16U) | (53 << 8U) | 0),                                                                                                                  ///< IO port P53
    BSP_IO_PORT_P54  = ((BSP_IO_PORT_P54_PWE << 24U) | (0 << 16U) | (54 << 8U) | 0),                                                                                                                  ///< IO port P54
    BSP_IO_PORT_P55  = ((BSP_IO_PORT_P55_PWE << 24U) | (0 << 16U) | (55 << 8U) | 0),                                                                                                                  ///< IO port P55
    BSP_IO_PORT_P56  = ((BSP_IO_PORT_P56_PWE << 24U) | (0 << 16U) | (56 << 8U) | 0),                                                                                                                  ///< IO port P56
#elif (BSP_PACKAGE_PINS_BGA373 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00  = ((BSP_IO_PORT_P00_PWE << 24U) | (0 << 16U) | (0 << 8U) | 0),                                                                                                                   ///< IO port P00
    BSP_IO_PORT_P01  = ((BSP_IO_PORT_P01_PWE << 24U) | (0 << 16U) | (1 << 8U) | 0),                                                                                                                   ///< IO port P01
    BSP_IO_PORT_P02  = ((BSP_IO_PORT_P02_PWE << 24U) | (0 << 16U) | (2 << 8U) | 0),                                                                                                                   ///< IO port P02
    BSP_IO_PORT_P10  = ((BSP_IO_PORT_P10_PWE << 24U) | (0 << 16U) | (10 << 8U) | 0),                                                                                                                  ///< IO port P10
    BSP_IO_PORT_P11  = ((BSP_IO_PORT_P11_PWE << 24U) | (0 << 16U) | (11 << 8U) | 0),                                                                                                                  ///< IO port P11
    BSP_IO_PORT_P12  = ((BSP_IO_PORT_P12_PWE << 24U) | (0 << 16U) | (12 << 8U) | 0),                                                                                                                  ///< IO port P12
    BSP_IO_PORT_P13  = ((BSP_IO_PORT_P13_PWE << 24U) | (0 << 16U) | (13 << 8U) | 0),                                                                                                                  ///< IO port P13
    BSP_IO_PORT_P14  = ((BSP_IO_PORT_P14_PWE << 24U) | (0 << 16U) | (14 << 8U) | 0),                                                                                                                  ///< IO port P14
    BSP_IO_PORT_P20  = ((BSP_IO_PORT_P20_PWE << 24U) | (0 << 16U) | (20 << 8U) | 0),                                                                                                                  ///< IO port P20
    BSP_IO_PORT_P21  = ((BSP_IO_PORT_P21_PWE << 24U) | (0 << 16U) | (21 << 8U) | 0),                                                                                                                  ///< IO port P21
    BSP_IO_PORT_P22  = ((BSP_IO_PORT_P22_PWE << 24U) | (0 << 16U) | (22 << 8U) | 0),                                                                                                                  ///< IO port P22
    BSP_IO_PORT_P23  = ((BSP_IO_PORT_P23_PWE << 24U) | (0 << 16U) | (23 << 8U) | 0),                                                                                                                  ///< IO port P23
    BSP_IO_PORT_P24  = ((BSP_IO_PORT_P24_PWE << 24U) | (0 << 16U) | (24 << 8U) | 0),                                                                                                                  ///< IO port P24
    BSP_IO_PORT_P25  = ((BSP_IO_PORT_P25_PWE << 24U) | (0 << 16U) | (25 << 8U) | 0),                                                                                                                  ///< IO port P25
    BSP_IO_PORT_P30  = ((BSP_IO_PORT_P30_PWE << 24U) | (0 << 16U) | (30 << 8U) | 0),                                                                                                                  ///< IO port P30
    BSP_IO_PORT_P32  = ((BSP_IO_PORT_P32_PWE << 24U) | (0 << 16U) | (32 << 8U) | 0),                                                                                                                  ///< IO port P32
    BSP_IO_PORT_P33  = ((BSP_IO_PORT_P33_PWE << 24U) | (0 << 16U) | (33 << 8U) | 0),                                                                                                                  ///< IO port P33
    BSP_IO_PORT_P34  = ((BSP_IO_PORT_P34_PWE << 24U) | (0 << 16U) | (34 << 8U) | 0),                                                                                                                  ///< IO port P34
    BSP_IO_PORT_P27  = ((BSP_IO_PORT_P27_PWE << 24U) | (0 << 16U) | (27 << 8U) | 0),                                                                                                                  ///< IO port P27
    BSP_IO_PORT_JP00 = ((BSP_IO_PORT_JP00_PWE << 24U) | (1 << 16U) | (0 << 8U) | 0),                                                                                                                  ///< IO port JP00
    BSP_IO_PORT_P40  = ((BSP_IO_PORT_P40_PWE << 24U) | (0 << 16U) | (40 << 8U) | 0),                                                                                                                  ///< IO port P40
    BSP_IO_PORT_P37  = ((BSP_IO_PORT_P37_PWE << 24U) | (0 << 16U) | (37 << 8U) | 0),                                                                                                                  ///< IO port P37
    BSP_IO_PORT_P38  = ((BSP_IO_PORT_P38_PWE << 24U) | (0 << 16U) | (38 << 8U) | 0),                                                                                                                  ///< IO port P38
    BSP_IO_PORT_P39  = ((BSP_IO_PORT_P39_PWE << 24U) | (0 << 16U) | (39 << 8U) | 0),                                                                                                                  ///< IO port P39
    BSP_IO_PORT_P41  = ((BSP_IO_PORT_P41_PWE << 24U) | (0 << 16U) | (41 << 8U) | 0),                                                                                                                  ///< IO port P41
    BSP_IO_PORT_P42  = ((BSP_IO_PORT_P42_PWE << 24U) | (0 << 16U) | (42 << 8U) | 0),                                                                                                                  ///< IO port P42
    BSP_IO_PORT_P43  = ((BSP_IO_PORT_P43_PWE << 24U) | (0 << 16U) | (43 << 8U) | 0),                                                                                                                  ///< IO port P43
    BSP_IO_PORT_P44  = ((BSP_IO_PORT_P44_PWE << 24U) | (0 << 16U) | (44 << 8U) | 0),                                                                                                                  ///< IO port P44
    BSP_IO_PORT_P45  = ((BSP_IO_PORT_P45_PWE << 24U) | (0 << 16U) | (45 << 8U) | 0),                                                                                                                  ///< IO port P45
    BSP_IO_PORT_P46  = ((BSP_IO_PORT_P46_PWE << 24U) | (0 << 16U) | (46 << 8U) | 0),                                                                                                                  ///< IO port P46
    BSP_IO_PORT_P47  = ((BSP_IO_PORT_P47_PWE << 24U) | (0 << 16U) | (47 << 8U) | 0),                                                                                                                  ///< IO port P47
    BSP_IO_PORT_P48  = ((BSP_IO_PORT_P48_PWE << 24U) | (0 << 16U) | (48 << 8U) | 0),                                                                                                                  ///< IO port P48
    BSP_IO_PORT_P49  = ((BSP_IO_PORT_P49_PWE << 24U) | (0 << 16U) | (49 << 8U) | 0),                                                                                                                  ///< IO port P49
    BSP_IO_PORT_P50  = ((BSP_IO_PORT_P50_PWE << 24U) | (0 << 16U) | (50 << 8U) | 0),                                                                                                                  ///< IO port P50
    BSP_IO_PORT_P51  = ((BSP_IO_PORT_P51_PWE << 24U) | (0 << 16U) | (51 << 8U) | 0),                                                                                                                  ///< IO port P51
    BSP_IO_PORT_P52  = ((BSP_IO_PORT_P52_PWE << 24U) | (0 << 16U) | (52 << 8U) | 0),                                                                                                                  ///< IO port P52
    BSP_IO_PORT_P53  = ((BSP_IO_PORT_P53_PWE << 24U) | (0 << 16U) | (53 << 8U) | 0),                                                                                                                  ///< IO port P53
    BSP_IO_PORT_P54  = ((BSP_IO_PORT_P54_PWE << 24U) | (0 << 16U) | (54 << 8U) | 0),                                                                                                                  ///< IO port P54
    BSP_IO_PORT_P55  = ((BSP_IO_PORT_P55_PWE << 24U) | (0 << 16U) | (55 << 8U) | 0),                                                                                                                  ///< IO port P55
    BSP_IO_PORT_P56  = ((BSP_IO_PORT_P56_PWE << 24U) | (0 << 16U) | (56 << 8U) | 0),                                                                                                                  ///< IO port P56
#else
    BSP_IO_PORT_P00  = ((BSP_IO_PORT_P00_PWE << 24U) | (0 << 16U) | (0 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                           ///< IO port P00
    BSP_IO_PORT_P01  = ((BSP_IO_PORT_P01_PWE << 24U) | (0 << 16U) | (1 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                           ///< IO port P01
    BSP_IO_PORT_P02  = ((BSP_IO_PORT_P02_PWE << 24U) | (0 << 16U) | (2 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                           ///< IO port P02
    BSP_IO_PORT_P10  = ((BSP_IO_PORT_P10_PWE << 24U) | (0 << 16U) | (10 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P10
    BSP_IO_PORT_P11  = ((BSP_IO_PORT_P11_PWE << 24U) | (0 << 16U) | (11 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P11
    BSP_IO_PORT_P12  = ((BSP_IO_PORT_P12_PWE << 24U) | (0 << 16U) | (12 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P12
    BSP_IO_PORT_P13  = ((BSP_IO_PORT_P13_PWE << 24U) | (0 << 16U) | (13 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P13
    BSP_IO_PORT_P14  = ((BSP_IO_PORT_P14_PWE << 24U) | (0 << 16U) | (14 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P14
    BSP_IO_PORT_P15  = ((BSP_IO_PORT_P15_PWE << 24U) | (0 << 16U) | (15 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P15
    BSP_IO_PORT_P20  = ((BSP_IO_PORT_P20_PWE << 24U) | (0 << 16U) | (20 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P20
    BSP_IO_PORT_P21  = ((BSP_IO_PORT_P21_PWE << 24U) | (0 << 16U) | (21 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P21
    BSP_IO_PORT_P22  = ((BSP_IO_PORT_P22_PWE << 24U) | (0 << 16U) | (22 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P22
    BSP_IO_PORT_P23  = ((BSP_IO_PORT_P23_PWE << 24U) | (0 << 16U) | (23 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P23
    BSP_IO_PORT_P24  = ((BSP_IO_PORT_P24_PWE << 24U) | (0 << 16U) | (24 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P24
    BSP_IO_PORT_P25  = ((BSP_IO_PORT_P25_PWE << 24U) | (0 << 16U) | (25 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P25
    BSP_IO_PORT_P30  = ((BSP_IO_PORT_P30_PWE << 24U) | (0 << 16U) | (30 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P30
    BSP_IO_PORT_P31  = ((BSP_IO_PORT_P31_PWE << 24U) | (0 << 16U) | (31 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P31
    BSP_IO_PORT_P32  = ((BSP_IO_PORT_P32_PWE << 24U) | (0 << 16U) | (32 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P32
    BSP_IO_PORT_P33  = ((BSP_IO_PORT_P33_PWE << 24U) | (0 << 16U) | (33 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P33
    BSP_IO_PORT_P34  = ((BSP_IO_PORT_P34_PWE << 24U) | (0 << 16U) | (34 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P34
    BSP_IO_PORT_P27  = ((BSP_IO_PORT_P27_PWE << 24U) | (0 << 16U) | (27 << 8U) | 0), /* PRQA S 4543, 0499, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P27
    BSP_IO_PORT_JP00 = ((BSP_IO_PORT_JP00_PWE << 24U) | (1 << 16U) | (0 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port JP00
    BSP_IO_PORT_P40  = ((BSP_IO_PORT_P40_PWE << 24U) | (0 << 16U) | (40 << 8U) | 0), /* PRQA S 0499, 4532, 4543, 4542 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P40
    BSP_IO_PORT_P37  = ((BSP_IO_PORT_P37_PWE << 24U) | (0 << 16U) | (37 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P37
    BSP_IO_PORT_P38  = ((BSP_IO_PORT_P38_PWE << 24U) | (0 << 16U) | (38 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P38
    BSP_IO_PORT_P39  = ((BSP_IO_PORT_P39_PWE << 24U) | (0 << 16U) | (39 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P39
    BSP_IO_PORT_P41  = ((BSP_IO_PORT_P41_PWE << 24U) | (0 << 16U) | (41 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P41
    BSP_IO_PORT_P42  = ((BSP_IO_PORT_P42_PWE << 24U) | (0 << 16U) | (42 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P42
    BSP_IO_PORT_P43  = ((BSP_IO_PORT_P43_PWE << 24U) | (0 << 16U) | (43 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P43
    BSP_IO_PORT_P44  = ((BSP_IO_PORT_P44_PWE << 24U) | (0 << 16U) | (44 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P44
    BSP_IO_PORT_P45  = ((BSP_IO_PORT_P45_PWE << 24U) | (0 << 16U) | (45 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P45
    BSP_IO_PORT_P46  = ((BSP_IO_PORT_P46_PWE << 24U) | (0 << 16U) | (46 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P46
    BSP_IO_PORT_P47  = ((BSP_IO_PORT_P47_PWE << 24U) | (0 << 16U) | (47 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P47
    BSP_IO_PORT_P48  = ((BSP_IO_PORT_P48_PWE << 24U) | (0 << 16U) | (48 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P48
    BSP_IO_PORT_P49  = ((BSP_IO_PORT_P49_PWE << 24U) | (0 << 16U) | (49 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P49
    BSP_IO_PORT_P50  = ((BSP_IO_PORT_P50_PWE << 24U) | (0 << 16U) | (50 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P50
    BSP_IO_PORT_P51  = ((BSP_IO_PORT_P51_PWE << 24U) | (0 << 16U) | (51 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P51
    BSP_IO_PORT_P52  = ((BSP_IO_PORT_P52_PWE << 24U) | (0 << 16U) | (52 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P52
    BSP_IO_PORT_P53  = ((BSP_IO_PORT_P53_PWE << 24U) | (0 << 16U) | (53 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P53
    BSP_IO_PORT_P54  = ((BSP_IO_PORT_P54_PWE << 24U) | (0 << 16U) | (54 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P54
    BSP_IO_PORT_P55  = ((BSP_IO_PORT_P55_PWE << 24U) | (0 << 16U) | (55 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P55
    BSP_IO_PORT_P56  = ((BSP_IO_PORT_P56_PWE << 24U) | (0 << 16U) | (56 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P56
#endif
} bsp_io_port_t;

/** Superset list of all possible IO port pins. */
typedef enum e_bsp_io_port_pin_u2b10                                                                                  /* PRQA S 1536 # Advisory R-2.4 */
{
#if (BSP_PACKAGE_PINS_BGA292 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00_PIN_0 = (BSP_IO_PORT_P00 | 0x0),                                                                  ///< IO port P00 pin 0
    BSP_IO_PORT_P00_PIN_1 = (BSP_IO_PORT_P00 | 0x1),                                                                  ///< IO port P00 pin 1
    BSP_IO_PORT_P00_PIN_2 = (BSP_IO_PORT_P00 | 0x2),                                                                  ///< IO port P00 pin 2
    BSP_IO_PORT_P00_PIN_3 = (BSP_IO_PORT_P00 | 0x3),                                                                  ///< IO port P00 pin 3
    BSP_IO_PORT_P00_PIN_4 = (BSP_IO_PORT_P00 | 0x4),                                                                  ///< IO port P00 pin 4
    BSP_IO_PORT_P00_PIN_5 = (BSP_IO_PORT_P00 | 0x5),                                                                  ///< IO port P00 pin 5
    BSP_IO_PORT_P00_PIN_6 = (BSP_IO_PORT_P00 | 0x6),                                                                  ///< IO port P00 pin 6
    BSP_IO_PORT_P00_PIN_7 = (BSP_IO_PORT_P00 | 0x7),                                                                  ///< IO port P00 pin 7

    BSP_IO_PORT_P02_PIN_0  = (BSP_IO_PORT_P02 | 0x0),                                                                 ///< IO port P02 pin 0
    BSP_IO_PORT_P02_PIN_1  = (BSP_IO_PORT_P02 | 0x1),                                                                 ///< IO port P02 pin 1
    BSP_IO_PORT_P02_PIN_2  = (BSP_IO_PORT_P02 | 0x2),                                                                 ///< IO port P02 pin 2
    BSP_IO_PORT_P02_PIN_3  = (BSP_IO_PORT_P02 | 0x3),                                                                 ///< IO port P02 pin 3
    BSP_IO_PORT_P02_PIN_4  = (BSP_IO_PORT_P02 | 0x4),                                                                 ///< IO port P02 pin 4
    BSP_IO_PORT_P02_PIN_5  = (BSP_IO_PORT_P02 | 0x5),                                                                 ///< IO port P02 pin 5
    BSP_IO_PORT_P02_PIN_6  = (BSP_IO_PORT_P02 | 0x6),                                                                 ///< IO port P02 pin 6
    BSP_IO_PORT_P02_PIN_7  = (BSP_IO_PORT_P02 | 0x7),                                                                 ///< IO port P02 pin 7
    BSP_IO_PORT_P02_PIN_8  = (BSP_IO_PORT_P02 | 0x8),                                                                 ///< IO port P02 pin 8
    BSP_IO_PORT_P02_PIN_9  = (BSP_IO_PORT_P02 | 0x9),                                                                 ///< IO port P02 pin 9
    BSP_IO_PORT_P02_PIN_10 = (BSP_IO_PORT_P02 | 0xA),                                                                 ///< IO port P02 pin 10

    BSP_IO_PORT_P10_PIN_0 = (BSP_IO_PORT_P10 | 0x0),                                                                  ///< IO port P10 pin 0
    BSP_IO_PORT_P10_PIN_1 = (BSP_IO_PORT_P10 | 0x1),                                                                  ///< IO port P10 pin 1
    BSP_IO_PORT_P10_PIN_2 = (BSP_IO_PORT_P10 | 0x2),                                                                  ///< IO port P10 pin 2
    BSP_IO_PORT_P10_PIN_3 = (BSP_IO_PORT_P10 | 0x3),                                                                  ///< IO port P10 pin 3
    BSP_IO_PORT_P10_PIN_4 = (BSP_IO_PORT_P10 | 0x4),                                                                  ///< IO port P10 pin 4
    BSP_IO_PORT_P10_PIN_5 = (BSP_IO_PORT_P10 | 0x5),                                                                  ///< IO port P10 pin 5
    BSP_IO_PORT_P10_PIN_6 = (BSP_IO_PORT_P10 | 0x6),                                                                  ///< IO port P10 pin 6
    BSP_IO_PORT_P10_PIN_7 = (BSP_IO_PORT_P10 | 0x7),                                                                  ///< IO port P10 pin 7
    BSP_IO_PORT_P10_PIN_8 = (BSP_IO_PORT_P10 | 0x8),                                                                  ///< IO port P10 pin 8

    BSP_IO_PORT_P11_PIN_0  = (BSP_IO_PORT_P11 | 0x0),                                                                 ///< IO port P11 pin 0
    BSP_IO_PORT_P11_PIN_1  = (BSP_IO_PORT_P11 | 0x1),                                                                 ///< IO port P11 pin 1
    BSP_IO_PORT_P11_PIN_2  = (BSP_IO_PORT_P11 | 0x2),                                                                 ///< IO port P11 pin 2
    BSP_IO_PORT_P11_PIN_3  = (BSP_IO_PORT_P11 | 0x3),                                                                 ///< IO port P11 pin 3
    BSP_IO_PORT_P11_PIN_4  = (BSP_IO_PORT_P11 | 0x4),                                                                 ///< IO port P11 pin 4
    BSP_IO_PORT_P11_PIN_5  = (BSP_IO_PORT_P11 | 0x5),                                                                 ///< IO port P11 pin 5
    BSP_IO_PORT_P11_PIN_6  = (BSP_IO_PORT_P11 | 0x6),                                                                 ///< IO port P11 pin 6
    BSP_IO_PORT_P11_PIN_7  = (BSP_IO_PORT_P11 | 0x7),                                                                 ///< IO port P11 pin 7
    BSP_IO_PORT_P11_PIN_8  = (BSP_IO_PORT_P11 | 0x8),                                                                 ///< IO port P11 pin 8
    BSP_IO_PORT_P11_PIN_9  = (BSP_IO_PORT_P11 | 0x9),                                                                 ///< IO port P11 pin 9
    BSP_IO_PORT_P11_PIN_10 = (BSP_IO_PORT_P11 | 0xA),                                                                 ///< IO port P11 pin 10

    BSP_IO_PORT_P12_PIN_0 = (BSP_IO_PORT_P12 | 0x0),                                                                  ///< IO port P12 pin 0
    BSP_IO_PORT_P12_PIN_1 = (BSP_IO_PORT_P12 | 0x1),                                                                  ///< IO port P12 pin 1
    BSP_IO_PORT_P12_PIN_2 = (BSP_IO_PORT_P12 | 0x2),                                                                  ///< IO port P12 pin 2
    BSP_IO_PORT_P12_PIN_3 = (BSP_IO_PORT_P12 | 0x3),                                                                  ///< IO port P12 pin 3
    BSP_IO_PORT_P12_PIN_4 = (BSP_IO_PORT_P12 | 0x4),                                                                  ///< IO port P12 pin 4
    BSP_IO_PORT_P12_PIN_5 = (BSP_IO_PORT_P12 | 0x5),                                                                  ///< IO port P12 pin 5
    BSP_IO_PORT_P12_PIN_6 = (BSP_IO_PORT_P12 | 0x6),                                                                  ///< IO port P12 pin 6
    BSP_IO_PORT_P12_PIN_7 = (BSP_IO_PORT_P12 | 0x7),                                                                  ///< IO port P12 pin 7
    BSP_IO_PORT_P12_PIN_8 = (BSP_IO_PORT_P12 | 0x8),                                                                  ///< IO port P12 pin 8
    BSP_IO_PORT_P12_PIN_9 = (BSP_IO_PORT_P12 | 0x9),                                                                  ///< IO port P12 pin 9

    BSP_IO_PORT_P13_PIN_0 = (BSP_IO_PORT_P13 | 0x0),                                                                  ///< IO port P13 pin 0
    BSP_IO_PORT_P13_PIN_1 = (BSP_IO_PORT_P13 | 0x1),                                                                  ///< IO port P13 pin 1
    BSP_IO_PORT_P13_PIN_2 = (BSP_IO_PORT_P13 | 0x2),                                                                  ///< IO port P13 pin 2
    BSP_IO_PORT_P13_PIN_3 = (BSP_IO_PORT_P13 | 0x3),                                                                  ///< IO port P13 pin 3

    BSP_IO_PORT_P14_PIN_0 = (BSP_IO_PORT_P14 | 0x0),                                                                  ///< IO port P14 pin 0
    BSP_IO_PORT_P14_PIN_1 = (BSP_IO_PORT_P14 | 0x1),                                                                  ///< IO port P14 pin 1
    BSP_IO_PORT_P14_PIN_2 = (BSP_IO_PORT_P14 | 0x2),                                                                  ///< IO port P14 pin 2
    BSP_IO_PORT_P14_PIN_3 = (BSP_IO_PORT_P14 | 0x3),                                                                  ///< IO port P14 pin 3
    BSP_IO_PORT_P14_PIN_4 = (BSP_IO_PORT_P14 | 0x4),                                                                  ///< IO port P14 pin 4
    BSP_IO_PORT_P14_PIN_5 = (BSP_IO_PORT_P14 | 0x5),                                                                  ///< IO port P14 pin 5

    BSP_IO_PORT_P20_PIN_0 = (BSP_IO_PORT_P20 | 0x0),                                                                  ///< IO port P20 pin 0
    BSP_IO_PORT_P20_PIN_1 = (BSP_IO_PORT_P20 | 0x1),                                                                  ///< IO port P20 pin 1
    BSP_IO_PORT_P20_PIN_2 = (BSP_IO_PORT_P20 | 0x2),                                                                  ///< IO port P20 pin 2
    BSP_IO_PORT_P20_PIN_3 = (BSP_IO_PORT_P20 | 0x3),                                                                  ///< IO port P20 pin 3
    BSP_IO_PORT_P20_PIN_4 = (BSP_IO_PORT_P20 | 0x4),                                                                  ///< IO port P20 pin 4
    BSP_IO_PORT_P20_PIN_5 = (BSP_IO_PORT_P20 | 0x5),                                                                  ///< IO port P20 pin 5
    BSP_IO_PORT_P20_PIN_6 = (BSP_IO_PORT_P20 | 0x6),                                                                  ///< IO port P20 pin 6
    BSP_IO_PORT_P20_PIN_7 = (BSP_IO_PORT_P20 | 0x7),                                                                  ///< IO port P20 pin 7

    BSP_IO_PORT_P21_PIN_2 = (BSP_IO_PORT_P21 | 0x2),                                                                  ///< IO port P21 pin 2
    BSP_IO_PORT_P21_PIN_3 = (BSP_IO_PORT_P21 | 0x3),                                                                  ///< IO port P21 pin 3
    BSP_IO_PORT_P21_PIN_4 = (BSP_IO_PORT_P21 | 0x4),                                                                  ///< IO port P21 pin 4
    BSP_IO_PORT_P21_PIN_5 = (BSP_IO_PORT_P21 | 0x5),                                                                  ///< IO port P21 pin 5

    BSP_IO_PORT_P22_PIN_0  = (BSP_IO_PORT_P22 | 0x0),                                                                 ///< IO port P22 pin 0
    BSP_IO_PORT_P22_PIN_1  = (BSP_IO_PORT_P22 | 0x1),                                                                 ///< IO port P22 pin 1
    BSP_IO_PORT_P22_PIN_2  = (BSP_IO_PORT_P22 | 0x2),                                                                 ///< IO port P22 pin 2
    BSP_IO_PORT_P22_PIN_3  = (BSP_IO_PORT_P22 | 0x3),                                                                 ///< IO port P22 pin 3
    BSP_IO_PORT_P22_PIN_4  = (BSP_IO_PORT_P22 | 0x4),                                                                 ///< IO port P22 pin 4
    BSP_IO_PORT_P22_PIN_5  = (BSP_IO_PORT_P22 | 0x5),                                                                 ///< IO port P22 pin 5
    BSP_IO_PORT_P22_PIN_6  = (BSP_IO_PORT_P22 | 0x6),                                                                 ///< IO port P22 pin 6
    BSP_IO_PORT_P22_PIN_7  = (BSP_IO_PORT_P22 | 0x7),                                                                 ///< IO port P22 pin 7
    BSP_IO_PORT_P22_PIN_8  = (BSP_IO_PORT_P22 | 0x8),                                                                 ///< IO port P22 pin 8
    BSP_IO_PORT_P22_PIN_9  = (BSP_IO_PORT_P22 | 0x9),                                                                 ///< IO port P22 pin 9
    BSP_IO_PORT_P22_PIN_10 = (BSP_IO_PORT_P22 | 0xA),                                                                 ///< IO port P22 pin 10
    BSP_IO_PORT_P22_PIN_11 = (BSP_IO_PORT_P22 | 0xB),                                                                 ///< IO port P22 pin 11
    BSP_IO_PORT_P22_PIN_12 = (BSP_IO_PORT_P22 | 0xC),                                                                 ///< IO port P22 pin 12
    BSP_IO_PORT_P22_PIN_13 = (BSP_IO_PORT_P22 | 0xD),                                                                 ///< IO port P22 pin 13

    BSP_IO_PORT_P23_PIN_0 = (BSP_IO_PORT_P23 | 0x0),                                                                  ///< IO port P23 pin 0
    BSP_IO_PORT_P23_PIN_1 = (BSP_IO_PORT_P23 | 0x1),                                                                  ///< IO port P23 pin 1
    BSP_IO_PORT_P23_PIN_2 = (BSP_IO_PORT_P23 | 0x2),                                                                  ///< IO port P23 pin 2
    BSP_IO_PORT_P23_PIN_3 = (BSP_IO_PORT_P23 | 0x3),                                                                  ///< IO port P23 pin 3
    BSP_IO_PORT_P23_PIN_4 = (BSP_IO_PORT_P23 | 0x4),                                                                  ///< IO port P23 pin 4
    BSP_IO_PORT_P23_PIN_5 = (BSP_IO_PORT_P23 | 0x5),                                                                  ///< IO port P23 pin 5
    BSP_IO_PORT_P23_PIN_6 = (BSP_IO_PORT_P23 | 0x6),                                                                  ///< IO port P23 pin 6
    BSP_IO_PORT_P23_PIN_7 = (BSP_IO_PORT_P23 | 0x7),                                                                  ///< IO port P23 pin 7

    BSP_IO_PORT_P25_PIN_2 = (BSP_IO_PORT_P25 | 0x2),                                                                  ///< IO port P25 pin 2
    BSP_IO_PORT_P25_PIN_3 = (BSP_IO_PORT_P25 | 0x3),                                                                  ///< IO port P25 pin 3
    BSP_IO_PORT_P25_PIN_4 = (BSP_IO_PORT_P25 | 0x4),                                                                  ///< IO port P25 pin 4
    BSP_IO_PORT_P25_PIN_5 = (BSP_IO_PORT_P25 | 0x5),                                                                  ///< IO port P25 pin 5
    BSP_IO_PORT_P25_PIN_6 = (BSP_IO_PORT_P25 | 0x6),                                                                  ///< IO port P25 pin 6

    BSP_IO_PORT_P32_PIN_0 = (BSP_IO_PORT_P32 | 0x0),                                                                  ///< IO port P32 pin 0
    BSP_IO_PORT_P32_PIN_1 = (BSP_IO_PORT_P32 | 0x1),                                                                  ///< IO port P32 pin 1
    BSP_IO_PORT_P32_PIN_2 = (BSP_IO_PORT_P32 | 0x2),                                                                  ///< IO port P32 pin 2
    BSP_IO_PORT_P32_PIN_3 = (BSP_IO_PORT_P32 | 0x3),                                                                  ///< IO port P32 pin 3
    BSP_IO_PORT_P32_PIN_4 = (BSP_IO_PORT_P32 | 0x4),                                                                  ///< IO port P32 pin 4
    BSP_IO_PORT_P32_PIN_5 = (BSP_IO_PORT_P32 | 0x5),                                                                  ///< IO port P32 pin 5
    BSP_IO_PORT_P32_PIN_6 = (BSP_IO_PORT_P32 | 0x6),                                                                  ///< IO port P32 pin 6

    BSP_IO_PORT_P33_PIN_0 = (BSP_IO_PORT_P33 | 0x0),                                                                  ///< IO port P33 pin 0
    BSP_IO_PORT_P33_PIN_1 = (BSP_IO_PORT_P33 | 0x1),                                                                  ///< IO port P33 pin 1
    BSP_IO_PORT_P33_PIN_2 = (BSP_IO_PORT_P33 | 0x2),                                                                  ///< IO port P33 pin 2
    BSP_IO_PORT_P33_PIN_3 = (BSP_IO_PORT_P33 | 0x3),                                                                  ///< IO port P33 pin 3
    BSP_IO_PORT_P33_PIN_4 = (BSP_IO_PORT_P33 | 0x4),                                                                  ///< IO port P33 pin 4
    BSP_IO_PORT_P33_PIN_5 = (BSP_IO_PORT_P33 | 0x5),                                                                  ///< IO port P33 pin 5
    BSP_IO_PORT_P33_PIN_6 = (BSP_IO_PORT_P33 | 0x6),                                                                  ///< IO port P33 pin 6
    BSP_IO_PORT_P33_PIN_7 = (BSP_IO_PORT_P33 | 0x7),                                                                  ///< IO port P33 pin 7
    BSP_IO_PORT_P33_PIN_8 = (BSP_IO_PORT_P33 | 0x8),                                                                  ///< IO port P33 pin 8

    BSP_IO_PORT_P34_PIN_0 = (BSP_IO_PORT_P34 | 0x0),                                                                  ///< IO port P34 pin 0
    BSP_IO_PORT_P34_PIN_1 = (BSP_IO_PORT_P34 | 0x1),                                                                  ///< IO port P34 pin 1
    BSP_IO_PORT_P34_PIN_2 = (BSP_IO_PORT_P34 | 0x2),                                                                  ///< IO port P34 pin 2
    BSP_IO_PORT_P34_PIN_3 = (BSP_IO_PORT_P34 | 0x3),                                                                  ///< IO port P34 pin 3
    BSP_IO_PORT_P34_PIN_4 = (BSP_IO_PORT_P34 | 0x4),                                                                  ///< IO port P34 pin 4

    BSP_IO_PORT_P27_PIN_0 = (BSP_IO_PORT_P27 | 0x0),                                                                  ///< IO port P27 pin 0

    BSP_IO_PORT_JP00_PIN_0 = (BSP_IO_PORT_JP00 | 0x0),                                                                ///< IO port JP00 pin 0
    BSP_IO_PORT_JP00_PIN_1 = (BSP_IO_PORT_JP00 | 0x1),                                                                ///< IO port JP00 pin 1
    BSP_IO_PORT_JP00_PIN_2 = (BSP_IO_PORT_JP00 | 0x2),                                                                ///< IO port JP00 pin 2
    BSP_IO_PORT_JP00_PIN_3 = (BSP_IO_PORT_JP00 | 0x3),                                                                ///< IO port JP00 pin 3
    BSP_IO_PORT_JP00_PIN_5 = (BSP_IO_PORT_JP00 | 0x5),                                                                ///< IO port JP00 pin 5

    BSP_IO_PORT_P40_PIN_0  = (BSP_IO_PORT_P40 | 0x0),                                                                 ///< IO port P40 pin 0
    BSP_IO_PORT_P40_PIN_1  = (BSP_IO_PORT_P40 | 0x1),                                                                 ///< IO port P40 pin 1
    BSP_IO_PORT_P40_PIN_2  = (BSP_IO_PORT_P40 | 0x2),                                                                 ///< IO port P40 pin 2
    BSP_IO_PORT_P40_PIN_3  = (BSP_IO_PORT_P40 | 0x3),                                                                 ///< IO port P40 pin 3
    BSP_IO_PORT_P40_PIN_8  = (BSP_IO_PORT_P40 | 0x8),                                                                 ///< IO port P40 pin 8
    BSP_IO_PORT_P40_PIN_9  = (BSP_IO_PORT_P40 | 0x9),                                                                 ///< IO port P40 pin 9
    BSP_IO_PORT_P40_PIN_10 = (BSP_IO_PORT_P40 | 0xA),                                                                 ///< IO port P40 pin 10
    BSP_IO_PORT_P40_PIN_11 = (BSP_IO_PORT_P40 | 0xB),                                                                 ///< IO port P40 pin 11
    BSP_IO_PORT_P40_PIN_12 = (BSP_IO_PORT_P40 | 0xC),                                                                 ///< IO port P40 pin 12
    BSP_IO_PORT_P40_PIN_13 = (BSP_IO_PORT_P40 | 0xD),                                                                 ///< IO port P40 pin 13
    BSP_IO_PORT_P40_PIN_14 = (BSP_IO_PORT_P40 | 0xE),                                                                 ///< IO port P40 pin 14
    BSP_IO_PORT_P40_PIN_15 = (BSP_IO_PORT_P40 | 0xF),                                                                 ///< IO port P40 pin 15
    BSP_IO_PORT_P40_PIN_4  = (BSP_IO_PORT_P40 | 0x4),                                                                 ///< IO port P40 pin 4
    BSP_IO_PORT_P40_PIN_5  = (BSP_IO_PORT_P40 | 0x5),                                                                 ///< IO port P40 pin 5
    BSP_IO_PORT_P40_PIN_6  = (BSP_IO_PORT_P40 | 0x6),                                                                 ///< IO port P40 pin 6
    BSP_IO_PORT_P40_PIN_7  = (BSP_IO_PORT_P40 | 0x7),                                                                 ///< IO port P40 pin 7

    BSP_IO_PORT_P37_PIN_0  = (BSP_IO_PORT_P37 | 0x0),                                                                 ///< IO port P37 pin 0
    BSP_IO_PORT_P37_PIN_1  = (BSP_IO_PORT_P37 | 0x1),                                                                 ///< IO port P37 pin 1
    BSP_IO_PORT_P37_PIN_2  = (BSP_IO_PORT_P37 | 0x2),                                                                 ///< IO port P37 pin 2
    BSP_IO_PORT_P37_PIN_3  = (BSP_IO_PORT_P37 | 0x3),                                                                 ///< IO port P37 pin 3
    BSP_IO_PORT_P37_PIN_4  = (BSP_IO_PORT_P37 | 0x4),                                                                 ///< IO port P37 pin 4
    BSP_IO_PORT_P37_PIN_5  = (BSP_IO_PORT_P37 | 0x5),                                                                 ///< IO port P37 pin 5
    BSP_IO_PORT_P37_PIN_6  = (BSP_IO_PORT_P37 | 0x6),                                                                 ///< IO port P37 pin 6
    BSP_IO_PORT_P37_PIN_7  = (BSP_IO_PORT_P37 | 0x7),                                                                 ///< IO port P37 pin 7
    BSP_IO_PORT_P37_PIN_8  = (BSP_IO_PORT_P37 | 0x8),                                                                 ///< IO port P37 pin 8
    BSP_IO_PORT_P37_PIN_9  = (BSP_IO_PORT_P37 | 0x9),                                                                 ///< IO port P37 pin 9
    BSP_IO_PORT_P37_PIN_10 = (BSP_IO_PORT_P37 | 0xA),                                                                 ///< IO port P37 pin 10
    BSP_IO_PORT_P37_PIN_11 = (BSP_IO_PORT_P37 | 0xB),                                                                 ///< IO port P37 pin 11
    BSP_IO_PORT_P37_PIN_12 = (BSP_IO_PORT_P37 | 0xC),                                                                 ///< IO port P37 pin 12
    BSP_IO_PORT_P37_PIN_13 = (BSP_IO_PORT_P37 | 0xD),                                                                 ///< IO port P37 pin 13
    BSP_IO_PORT_P37_PIN_14 = (BSP_IO_PORT_P37 | 0xE),                                                                 ///< IO port P37 pin 14
    BSP_IO_PORT_P37_PIN_15 = (BSP_IO_PORT_P37 | 0xF),                                                                 ///< IO port P37 pin 15

    BSP_IO_PORT_P38_PIN_0  = (BSP_IO_PORT_P38 | 0x0),                                                                 ///< IO port P38 pin 0
    BSP_IO_PORT_P38_PIN_1  = (BSP_IO_PORT_P38 | 0x1),                                                                 ///< IO port P38 pin 1
    BSP_IO_PORT_P38_PIN_2  = (BSP_IO_PORT_P38 | 0x2),                                                                 ///< IO port P38 pin 2
    BSP_IO_PORT_P38_PIN_3  = (BSP_IO_PORT_P38 | 0x3),                                                                 ///< IO port P38 pin 3
    BSP_IO_PORT_P38_PIN_4  = (BSP_IO_PORT_P38 | 0x4),                                                                 ///< IO port P38 pin 4
    BSP_IO_PORT_P38_PIN_5  = (BSP_IO_PORT_P38 | 0x5),                                                                 ///< IO port P38 pin 5
    BSP_IO_PORT_P38_PIN_6  = (BSP_IO_PORT_P38 | 0x6),                                                                 ///< IO port P38 pin 6
    BSP_IO_PORT_P38_PIN_7  = (BSP_IO_PORT_P38 | 0x7),                                                                 ///< IO port P38 pin 7
    BSP_IO_PORT_P38_PIN_8  = (BSP_IO_PORT_P38 | 0x8),                                                                 ///< IO port P38 pin 8
    BSP_IO_PORT_P38_PIN_9  = (BSP_IO_PORT_P38 | 0x9),                                                                 ///< IO port P38 pin 9
    BSP_IO_PORT_P38_PIN_10 = (BSP_IO_PORT_P38 | 0xA),                                                                 ///< IO port P38 pin 10
    BSP_IO_PORT_P38_PIN_11 = (BSP_IO_PORT_P38 | 0xB),                                                                 ///< IO port P38 pin 11
    BSP_IO_PORT_P38_PIN_12 = (BSP_IO_PORT_P38 | 0xC),                                                                 ///< IO port P38 pin 12
    BSP_IO_PORT_P38_PIN_13 = (BSP_IO_PORT_P38 | 0xD),                                                                 ///< IO port P38 pin 13
    BSP_IO_PORT_P38_PIN_14 = (BSP_IO_PORT_P38 | 0xE),                                                                 ///< IO port P38 pin 14
    BSP_IO_PORT_P38_PIN_15 = (BSP_IO_PORT_P38 | 0xF),                                                                 ///< IO port P38 pin 15

    BSP_IO_PORT_P39_PIN_0  = (BSP_IO_PORT_P39 | 0x0),                                                                 ///< IO port P39 pin 0
    BSP_IO_PORT_P39_PIN_1  = (BSP_IO_PORT_P39 | 0x1),                                                                 ///< IO port P39 pin 1
    BSP_IO_PORT_P39_PIN_2  = (BSP_IO_PORT_P39 | 0x2),                                                                 ///< IO port P39 pin 2
    BSP_IO_PORT_P39_PIN_3  = (BSP_IO_PORT_P39 | 0x3),                                                                 ///< IO port P39 pin 3
    BSP_IO_PORT_P39_PIN_4  = (BSP_IO_PORT_P39 | 0x4),                                                                 ///< IO port P39 pin 4
    BSP_IO_PORT_P39_PIN_5  = (BSP_IO_PORT_P39 | 0x5),                                                                 ///< IO port P39 pin 5
    BSP_IO_PORT_P39_PIN_6  = (BSP_IO_PORT_P39 | 0x6),                                                                 ///< IO port P39 pin 6
    BSP_IO_PORT_P39_PIN_7  = (BSP_IO_PORT_P39 | 0x7),                                                                 ///< IO port P39 pin 7
    BSP_IO_PORT_P39_PIN_8  = (BSP_IO_PORT_P39 | 0x8),                                                                 ///< IO port P39 pin 8
    BSP_IO_PORT_P39_PIN_9  = (BSP_IO_PORT_P39 | 0x9),                                                                 ///< IO port P39 pin 9
    BSP_IO_PORT_P39_PIN_10 = (BSP_IO_PORT_P39 | 0xA),                                                                 ///< IO port P39 pin 10
    BSP_IO_PORT_P39_PIN_11 = (BSP_IO_PORT_P39 | 0xB),                                                                 ///< IO port P39 pin 11
    BSP_IO_PORT_P39_PIN_12 = (BSP_IO_PORT_P39 | 0xC),                                                                 ///< IO port P39 pin 12
    BSP_IO_PORT_P39_PIN_13 = (BSP_IO_PORT_P39 | 0xD),                                                                 ///< IO port P39 pin 13
    BSP_IO_PORT_P39_PIN_14 = (BSP_IO_PORT_P39 | 0xE),                                                                 ///< IO port P39 pin 14
    BSP_IO_PORT_P39_PIN_15 = (BSP_IO_PORT_P39 | 0xF),                                                                 ///< IO port P39 pin 15

    BSP_IO_PORT_P41_PIN_0  = (BSP_IO_PORT_P41 | 0x0),                                                                 ///< IO port P41 pin 0
    BSP_IO_PORT_P41_PIN_1  = (BSP_IO_PORT_P41 | 0x1),                                                                 ///< IO port P41 pin 1
    BSP_IO_PORT_P41_PIN_2  = (BSP_IO_PORT_P41 | 0x2),                                                                 ///< IO port P41 pin 2
    BSP_IO_PORT_P41_PIN_3  = (BSP_IO_PORT_P41 | 0x3),                                                                 ///< IO port P41 pin 3
    BSP_IO_PORT_P41_PIN_4  = (BSP_IO_PORT_P41 | 0x4),                                                                 ///< IO port P41 pin 4
    BSP_IO_PORT_P41_PIN_5  = (BSP_IO_PORT_P41 | 0x5),                                                                 ///< IO port P41 pin 5
    BSP_IO_PORT_P41_PIN_6  = (BSP_IO_PORT_P41 | 0x6),                                                                 ///< IO port P41 pin 6
    BSP_IO_PORT_P41_PIN_7  = (BSP_IO_PORT_P41 | 0x7),                                                                 ///< IO port P41 pin 7
    BSP_IO_PORT_P41_PIN_8  = (BSP_IO_PORT_P41 | 0x8),                                                                 ///< IO port P41 pin 8
    BSP_IO_PORT_P41_PIN_9  = (BSP_IO_PORT_P41 | 0x9),                                                                 ///< IO port P41 pin 9
    BSP_IO_PORT_P41_PIN_10 = (BSP_IO_PORT_P41 | 0xA),                                                                 ///< IO port P41 pin 10
    BSP_IO_PORT_P41_PIN_11 = (BSP_IO_PORT_P41 | 0xB),                                                                 ///< IO port P41 pin 11
    BSP_IO_PORT_P41_PIN_12 = (BSP_IO_PORT_P41 | 0xC),                                                                 ///< IO port P41 pin 12
    BSP_IO_PORT_P41_PIN_13 = (BSP_IO_PORT_P41 | 0xD),                                                                 ///< IO port P41 pin 13
    BSP_IO_PORT_P41_PIN_14 = (BSP_IO_PORT_P41 | 0xE),                                                                 ///< IO port P41 pin 14
    BSP_IO_PORT_P41_PIN_15 = (BSP_IO_PORT_P41 | 0xF),                                                                 ///< IO port P41 pin 15

    BSP_IO_PORT_P42_PIN_0  = (BSP_IO_PORT_P42 | 0x0),                                                                 ///< IO port P42 pin 0
    BSP_IO_PORT_P42_PIN_1  = (BSP_IO_PORT_P42 | 0x1),                                                                 ///< IO port P42 pin 1
    BSP_IO_PORT_P42_PIN_2  = (BSP_IO_PORT_P42 | 0x2),                                                                 ///< IO port P42 pin 2
    BSP_IO_PORT_P42_PIN_3  = (BSP_IO_PORT_P42 | 0x3),                                                                 ///< IO port P42 pin 3
    BSP_IO_PORT_P42_PIN_4  = (BSP_IO_PORT_P42 | 0x4),                                                                 ///< IO port P42 pin 4
    BSP_IO_PORT_P42_PIN_5  = (BSP_IO_PORT_P42 | 0x5),                                                                 ///< IO port P42 pin 5
    BSP_IO_PORT_P42_PIN_6  = (BSP_IO_PORT_P42 | 0x6),                                                                 ///< IO port P42 pin 6
    BSP_IO_PORT_P42_PIN_7  = (BSP_IO_PORT_P42 | 0x7),                                                                 ///< IO port P42 pin 7
    BSP_IO_PORT_P42_PIN_8  = (BSP_IO_PORT_P42 | 0x8),                                                                 ///< IO port P42 pin 8
    BSP_IO_PORT_P42_PIN_9  = (BSP_IO_PORT_P42 | 0x9),                                                                 ///< IO port P42 pin 9
    BSP_IO_PORT_P42_PIN_10 = (BSP_IO_PORT_P42 | 0xA),                                                                 ///< IO port P42 pin 10
    BSP_IO_PORT_P42_PIN_11 = (BSP_IO_PORT_P42 | 0xB),                                                                 ///< IO port P42 pin 11
    BSP_IO_PORT_P42_PIN_12 = (BSP_IO_PORT_P42 | 0xC),                                                                 ///< IO port P42 pin 12
    BSP_IO_PORT_P42_PIN_13 = (BSP_IO_PORT_P42 | 0xD),                                                                 ///< IO port P42 pin 13
    BSP_IO_PORT_P42_PIN_14 = (BSP_IO_PORT_P42 | 0xE),                                                                 ///< IO port P42 pin 14
    BSP_IO_PORT_P42_PIN_15 = (BSP_IO_PORT_P42 | 0xF),                                                                 ///< IO port P42 pin 15

    BSP_IO_PORT_P43_PIN_0  = (BSP_IO_PORT_P43 | 0x0),                                                                 ///< IO port P43 pin 0
    BSP_IO_PORT_P43_PIN_1  = (BSP_IO_PORT_P43 | 0x1),                                                                 ///< IO port P43 pin 1
    BSP_IO_PORT_P43_PIN_2  = (BSP_IO_PORT_P43 | 0x2),                                                                 ///< IO port P43 pin 2
    BSP_IO_PORT_P43_PIN_3  = (BSP_IO_PORT_P43 | 0x3),                                                                 ///< IO port P43 pin 3
    BSP_IO_PORT_P43_PIN_4  = (BSP_IO_PORT_P43 | 0x4),                                                                 ///< IO port P43 pin 4
    BSP_IO_PORT_P43_PIN_5  = (BSP_IO_PORT_P43 | 0x5),                                                                 ///< IO port P43 pin 5
    BSP_IO_PORT_P43_PIN_6  = (BSP_IO_PORT_P43 | 0x6),                                                                 ///< IO port P43 pin 6
    BSP_IO_PORT_P43_PIN_7  = (BSP_IO_PORT_P43 | 0x7),                                                                 ///< IO port P43 pin 7
    BSP_IO_PORT_P43_PIN_8  = (BSP_IO_PORT_P43 | 0x8),                                                                 ///< IO port P43 pin 8
    BSP_IO_PORT_P43_PIN_9  = (BSP_IO_PORT_P43 | 0x9),                                                                 ///< IO port P43 pin 9
    BSP_IO_PORT_P43_PIN_10 = (BSP_IO_PORT_P43 | 0xA),                                                                 ///< IO port P43 pin 10
    BSP_IO_PORT_P43_PIN_11 = (BSP_IO_PORT_P43 | 0xB),                                                                 ///< IO port P43 pin 11
    BSP_IO_PORT_P43_PIN_12 = (BSP_IO_PORT_P43 | 0xC),                                                                 ///< IO port P43 pin 12
    BSP_IO_PORT_P43_PIN_13 = (BSP_IO_PORT_P43 | 0xD),                                                                 ///< IO port P43 pin 13
    BSP_IO_PORT_P43_PIN_14 = (BSP_IO_PORT_P43 | 0xE),                                                                 ///< IO port P43 pin 14
    BSP_IO_PORT_P43_PIN_15 = (BSP_IO_PORT_P43 | 0xF),                                                                 ///< IO port P43 pin 15

    BSP_IO_PORT_P44_PIN_0  = (BSP_IO_PORT_P44 | 0x0),                                                                 ///< IO port P44 pin 0
    BSP_IO_PORT_P44_PIN_1  = (BSP_IO_PORT_P44 | 0x1),                                                                 ///< IO port P44 pin 1
    BSP_IO_PORT_P44_PIN_2  = (BSP_IO_PORT_P44 | 0x2),                                                                 ///< IO port P44 pin 2
    BSP_IO_PORT_P44_PIN_3  = (BSP_IO_PORT_P44 | 0x3),                                                                 ///< IO port P44 pin 3
    BSP_IO_PORT_P44_PIN_4  = (BSP_IO_PORT_P44 | 0x4),                                                                 ///< IO port P44 pin 4
    BSP_IO_PORT_P44_PIN_5  = (BSP_IO_PORT_P44 | 0x5),                                                                 ///< IO port P44 pin 5
    BSP_IO_PORT_P44_PIN_6  = (BSP_IO_PORT_P44 | 0x6),                                                                 ///< IO port P44 pin 6
    BSP_IO_PORT_P44_PIN_7  = (BSP_IO_PORT_P44 | 0x7),                                                                 ///< IO port P44 pin 7
    BSP_IO_PORT_P44_PIN_8  = (BSP_IO_PORT_P44 | 0x8),                                                                 ///< IO port P44 pin 8
    BSP_IO_PORT_P44_PIN_9  = (BSP_IO_PORT_P44 | 0x9),                                                                 ///< IO port P44 pin 9
    BSP_IO_PORT_P44_PIN_10 = (BSP_IO_PORT_P44 | 0xA),                                                                 ///< IO port P44 pin 10
    BSP_IO_PORT_P44_PIN_11 = (BSP_IO_PORT_P44 | 0xB),                                                                 ///< IO port P44 pin 11
    BSP_IO_PORT_P44_PIN_12 = (BSP_IO_PORT_P44 | 0xC),                                                                 ///< IO port P44 pin 12
    BSP_IO_PORT_P44_PIN_13 = (BSP_IO_PORT_P44 | 0xD),                                                                 ///< IO port P44 pin 13
    BSP_IO_PORT_P44_PIN_14 = (BSP_IO_PORT_P44 | 0xE),                                                                 ///< IO port P44 pin 14
    BSP_IO_PORT_P44_PIN_15 = (BSP_IO_PORT_P44 | 0xF),                                                                 ///< IO port P44 pin 15

    BSP_IO_PORT_P45_PIN_0  = (BSP_IO_PORT_P45 | 0x0),                                                                 ///< IO port P45 pin 0
    BSP_IO_PORT_P45_PIN_1  = (BSP_IO_PORT_P45 | 0x1),                                                                 ///< IO port P45 pin 1
    BSP_IO_PORT_P45_PIN_2  = (BSP_IO_PORT_P45 | 0x2),                                                                 ///< IO port P45 pin 2
    BSP_IO_PORT_P45_PIN_3  = (BSP_IO_PORT_P45 | 0x3),                                                                 ///< IO port P45 pin 3
    BSP_IO_PORT_P45_PIN_4  = (BSP_IO_PORT_P45 | 0x4),                                                                 ///< IO port P45 pin 4
    BSP_IO_PORT_P45_PIN_5  = (BSP_IO_PORT_P45 | 0x5),                                                                 ///< IO port P45 pin 5
    BSP_IO_PORT_P45_PIN_6  = (BSP_IO_PORT_P45 | 0x6),                                                                 ///< IO port P45 pin 6
    BSP_IO_PORT_P45_PIN_7  = (BSP_IO_PORT_P45 | 0x7),                                                                 ///< IO port P45 pin 7
    BSP_IO_PORT_P45_PIN_8  = (BSP_IO_PORT_P45 | 0x8),                                                                 ///< IO port P45 pin 8
    BSP_IO_PORT_P45_PIN_9  = (BSP_IO_PORT_P45 | 0x9),                                                                 ///< IO port P45 pin 9
    BSP_IO_PORT_P45_PIN_10 = (BSP_IO_PORT_P45 | 0xA),                                                                 ///< IO port P45 pin 10
    BSP_IO_PORT_P45_PIN_11 = (BSP_IO_PORT_P45 | 0xB),                                                                 ///< IO port P45 pin 11
    BSP_IO_PORT_P45_PIN_12 = (BSP_IO_PORT_P45 | 0xC),                                                                 ///< IO port P45 pin 12
    BSP_IO_PORT_P45_PIN_13 = (BSP_IO_PORT_P45 | 0xD),                                                                 ///< IO port P45 pin 13
    BSP_IO_PORT_P45_PIN_14 = (BSP_IO_PORT_P45 | 0xE),                                                                 ///< IO port P45 pin 14
    BSP_IO_PORT_P45_PIN_15 = (BSP_IO_PORT_P45 | 0xF),                                                                 ///< IO port P45 pin 15

    BSP_IO_PORT_P46_PIN_0  = (BSP_IO_PORT_P46 | 0x0),                                                                 ///< IO port P46 pin 0
    BSP_IO_PORT_P46_PIN_1  = (BSP_IO_PORT_P46 | 0x1),                                                                 ///< IO port P46 pin 1
    BSP_IO_PORT_P46_PIN_2  = (BSP_IO_PORT_P46 | 0x2),                                                                 ///< IO port P46 pin 2
    BSP_IO_PORT_P46_PIN_3  = (BSP_IO_PORT_P46 | 0x3),                                                                 ///< IO port P46 pin 3
    BSP_IO_PORT_P46_PIN_4  = (BSP_IO_PORT_P46 | 0x4),                                                                 ///< IO port P46 pin 4
    BSP_IO_PORT_P46_PIN_5  = (BSP_IO_PORT_P46 | 0x5),                                                                 ///< IO port P46 pin 5
    BSP_IO_PORT_P46_PIN_6  = (BSP_IO_PORT_P46 | 0x6),                                                                 ///< IO port P46 pin 6
    BSP_IO_PORT_P46_PIN_7  = (BSP_IO_PORT_P46 | 0x7),                                                                 ///< IO port P46 pin 7
    BSP_IO_PORT_P46_PIN_8  = (BSP_IO_PORT_P46 | 0x8),                                                                 ///< IO port P46 pin 8
    BSP_IO_PORT_P46_PIN_9  = (BSP_IO_PORT_P46 | 0x9),                                                                 ///< IO port P46 pin 9
    BSP_IO_PORT_P46_PIN_10 = (BSP_IO_PORT_P46 | 0xA),                                                                 ///< IO port P46 pin 10
    BSP_IO_PORT_P46_PIN_11 = (BSP_IO_PORT_P46 | 0xB),                                                                 ///< IO port P46 pin 11
    BSP_IO_PORT_P46_PIN_12 = (BSP_IO_PORT_P46 | 0xC),                                                                 ///< IO port P46 pin 12
    BSP_IO_PORT_P46_PIN_13 = (BSP_IO_PORT_P46 | 0xD),                                                                 ///< IO port P46 pin 13
    BSP_IO_PORT_P46_PIN_14 = (BSP_IO_PORT_P46 | 0xE),                                                                 ///< IO port P46 pin 14
    BSP_IO_PORT_P46_PIN_15 = (BSP_IO_PORT_P46 | 0xF),                                                                 ///< IO port P46 pin 15

    BSP_IO_PORT_P47_PIN_0  = (BSP_IO_PORT_P47 | 0x0),                                                                 ///< IO port P47 pin 0
    BSP_IO_PORT_P47_PIN_1  = (BSP_IO_PORT_P47 | 0x1),                                                                 ///< IO port P47 pin 1
    BSP_IO_PORT_P47_PIN_2  = (BSP_IO_PORT_P47 | 0x2),                                                                 ///< IO port P47 pin 2
    BSP_IO_PORT_P47_PIN_3  = (BSP_IO_PORT_P47 | 0x3),                                                                 ///< IO port P47 pin 3
    BSP_IO_PORT_P47_PIN_4  = (BSP_IO_PORT_P47 | 0x4),                                                                 ///< IO port P47 pin 4
    BSP_IO_PORT_P47_PIN_5  = (BSP_IO_PORT_P47 | 0x5),                                                                 ///< IO port P47 pin 5
    BSP_IO_PORT_P47_PIN_6  = (BSP_IO_PORT_P47 | 0x6),                                                                 ///< IO port P47 pin 6
    BSP_IO_PORT_P47_PIN_7  = (BSP_IO_PORT_P47 | 0x7),                                                                 ///< IO port P47 pin 7
    BSP_IO_PORT_P47_PIN_8  = (BSP_IO_PORT_P47 | 0x8),                                                                 ///< IO port P47 pin 8
    BSP_IO_PORT_P47_PIN_9  = (BSP_IO_PORT_P47 | 0x9),                                                                 ///< IO port P47 pin 9
    BSP_IO_PORT_P47_PIN_10 = (BSP_IO_PORT_P47 | 0xA),                                                                 ///< IO port P47 pin 10
    BSP_IO_PORT_P47_PIN_11 = (BSP_IO_PORT_P47 | 0xB),                                                                 ///< IO port P47 pin 11
    BSP_IO_PORT_P47_PIN_12 = (BSP_IO_PORT_P47 | 0xC),                                                                 ///< IO port P47 pin 12
    BSP_IO_PORT_P47_PIN_13 = (BSP_IO_PORT_P47 | 0xD),                                                                 ///< IO port P47 pin 13
    BSP_IO_PORT_P47_PIN_14 = (BSP_IO_PORT_P47 | 0xE),                                                                 ///< IO port P47 pin 14
    BSP_IO_PORT_P47_PIN_15 = (BSP_IO_PORT_P47 | 0xF),                                                                 ///< IO port P47 pin 15

    BSP_IO_PORT_P48_PIN_0  = (BSP_IO_PORT_P48 | 0x0),                                                                 ///< IO port P48 pin 0
    BSP_IO_PORT_P48_PIN_1  = (BSP_IO_PORT_P48 | 0x1),                                                                 ///< IO port P48 pin 1
    BSP_IO_PORT_P48_PIN_2  = (BSP_IO_PORT_P48 | 0x2),                                                                 ///< IO port P48 pin 2
    BSP_IO_PORT_P48_PIN_3  = (BSP_IO_PORT_P48 | 0x3),                                                                 ///< IO port P48 pin 3
    BSP_IO_PORT_P48_PIN_4  = (BSP_IO_PORT_P48 | 0x4),                                                                 ///< IO port P48 pin 4
    BSP_IO_PORT_P48_PIN_5  = (BSP_IO_PORT_P48 | 0x5),                                                                 ///< IO port P48 pin 5
    BSP_IO_PORT_P48_PIN_6  = (BSP_IO_PORT_P48 | 0x6),                                                                 ///< IO port P48 pin 6
    BSP_IO_PORT_P48_PIN_7  = (BSP_IO_PORT_P48 | 0x7),                                                                 ///< IO port P48 pin 7
    BSP_IO_PORT_P48_PIN_8  = (BSP_IO_PORT_P48 | 0x8),                                                                 ///< IO port P48 pin 8
    BSP_IO_PORT_P48_PIN_9  = (BSP_IO_PORT_P48 | 0x9),                                                                 ///< IO port P48 pin 9
    BSP_IO_PORT_P48_PIN_10 = (BSP_IO_PORT_P48 | 0xA),                                                                 ///< IO port P48 pin 10
    BSP_IO_PORT_P48_PIN_11 = (BSP_IO_PORT_P48 | 0xB),                                                                 ///< IO port P48 pin 11
    BSP_IO_PORT_P48_PIN_12 = (BSP_IO_PORT_P48 | 0xC),                                                                 ///< IO port P48 pin 12
    BSP_IO_PORT_P48_PIN_13 = (BSP_IO_PORT_P48 | 0xD),                                                                 ///< IO port P48 pin 13
    BSP_IO_PORT_P48_PIN_14 = (BSP_IO_PORT_P48 | 0xE),                                                                 ///< IO port P48 pin 14
    BSP_IO_PORT_P48_PIN_15 = (BSP_IO_PORT_P48 | 0xF),                                                                 ///< IO port P48 pin 15

    BSP_IO_PORT_P49_PIN_0  = (BSP_IO_PORT_P49 | 0x0),                                                                 ///< IO port P49 pin 0
    BSP_IO_PORT_P49_PIN_1  = (BSP_IO_PORT_P49 | 0x1),                                                                 ///< IO port P49 pin 1
    BSP_IO_PORT_P49_PIN_2  = (BSP_IO_PORT_P49 | 0x2),                                                                 ///< IO port P49 pin 2
    BSP_IO_PORT_P49_PIN_3  = (BSP_IO_PORT_P49 | 0x3),                                                                 ///< IO port P49 pin 3
    BSP_IO_PORT_P49_PIN_4  = (BSP_IO_PORT_P49 | 0x4),                                                                 ///< IO port P49 pin 4
    BSP_IO_PORT_P49_PIN_5  = (BSP_IO_PORT_P49 | 0x5),                                                                 ///< IO port P49 pin 5
    BSP_IO_PORT_P49_PIN_6  = (BSP_IO_PORT_P49 | 0x6),                                                                 ///< IO port P49 pin 6
    BSP_IO_PORT_P49_PIN_7  = (BSP_IO_PORT_P49 | 0x7),                                                                 ///< IO port P49 pin 7
    BSP_IO_PORT_P49_PIN_8  = (BSP_IO_PORT_P49 | 0x8),                                                                 ///< IO port P49 pin 8
    BSP_IO_PORT_P49_PIN_9  = (BSP_IO_PORT_P49 | 0x9),                                                                 ///< IO port P49 pin 9
    BSP_IO_PORT_P49_PIN_10 = (BSP_IO_PORT_P49 | 0xA),                                                                 ///< IO port P49 pin 10
    BSP_IO_PORT_P49_PIN_11 = (BSP_IO_PORT_P49 | 0xB),                                                                 ///< IO port P49 pin 11
    BSP_IO_PORT_P49_PIN_12 = (BSP_IO_PORT_P49 | 0xC),                                                                 ///< IO port P49 pin 12
    BSP_IO_PORT_P49_PIN_13 = (BSP_IO_PORT_P49 | 0xD),                                                                 ///< IO port P49 pin 13
    BSP_IO_PORT_P49_PIN_14 = (BSP_IO_PORT_P49 | 0xE),                                                                 ///< IO port P49 pin 14
    BSP_IO_PORT_P49_PIN_15 = (BSP_IO_PORT_P49 | 0xF),                                                                 ///< IO port P49 pin 15

    BSP_IO_PORT_P50_PIN_0  = (BSP_IO_PORT_P50 | 0x0),                                                                 ///< IO port P50 pin 0
    BSP_IO_PORT_P50_PIN_1  = (BSP_IO_PORT_P50 | 0x1),                                                                 ///< IO port P50 pin 1
    BSP_IO_PORT_P50_PIN_2  = (BSP_IO_PORT_P50 | 0x2),                                                                 ///< IO port P50 pin 2
    BSP_IO_PORT_P50_PIN_3  = (BSP_IO_PORT_P50 | 0x3),                                                                 ///< IO port P50 pin 3
    BSP_IO_PORT_P50_PIN_4  = (BSP_IO_PORT_P50 | 0x4),                                                                 ///< IO port P50 pin 4
    BSP_IO_PORT_P50_PIN_5  = (BSP_IO_PORT_P50 | 0x5),                                                                 ///< IO port P50 pin 5
    BSP_IO_PORT_P50_PIN_6  = (BSP_IO_PORT_P50 | 0x6),                                                                 ///< IO port P50 pin 6
    BSP_IO_PORT_P50_PIN_7  = (BSP_IO_PORT_P50 | 0x7),                                                                 ///< IO port P50 pin 7
    BSP_IO_PORT_P50_PIN_8  = (BSP_IO_PORT_P50 | 0x8),                                                                 ///< IO port P50 pin 8
    BSP_IO_PORT_P50_PIN_9  = (BSP_IO_PORT_P50 | 0x9),                                                                 ///< IO port P50 pin 9
    BSP_IO_PORT_P50_PIN_10 = (BSP_IO_PORT_P50 | 0xA),                                                                 ///< IO port P50 pin 10
    BSP_IO_PORT_P50_PIN_11 = (BSP_IO_PORT_P50 | 0xB),                                                                 ///< IO port P50 pin 11
    BSP_IO_PORT_P50_PIN_12 = (BSP_IO_PORT_P50 | 0xC),                                                                 ///< IO port P50 pin 12
    BSP_IO_PORT_P50_PIN_13 = (BSP_IO_PORT_P50 | 0xD),                                                                 ///< IO port P50 pin 13
    BSP_IO_PORT_P50_PIN_14 = (BSP_IO_PORT_P50 | 0xE),                                                                 ///< IO port P50 pin 14
    BSP_IO_PORT_P50_PIN_15 = (BSP_IO_PORT_P50 | 0xF),                                                                 ///< IO port P50 pin 15

    BSP_IO_PORT_P51_PIN_0  = (BSP_IO_PORT_P51 | 0x0),                                                                 ///< IO port P51 pin 0
    BSP_IO_PORT_P51_PIN_1  = (BSP_IO_PORT_P51 | 0x1),                                                                 ///< IO port P51 pin 1
    BSP_IO_PORT_P51_PIN_2  = (BSP_IO_PORT_P51 | 0x2),                                                                 ///< IO port P51 pin 2
    BSP_IO_PORT_P51_PIN_3  = (BSP_IO_PORT_P51 | 0x3),                                                                 ///< IO port P51 pin 3
    BSP_IO_PORT_P51_PIN_4  = (BSP_IO_PORT_P51 | 0x4),                                                                 ///< IO port P51 pin 4
    BSP_IO_PORT_P51_PIN_5  = (BSP_IO_PORT_P51 | 0x5),                                                                 ///< IO port P51 pin 5
    BSP_IO_PORT_P51_PIN_6  = (BSP_IO_PORT_P51 | 0x6),                                                                 ///< IO port P51 pin 6
    BSP_IO_PORT_P51_PIN_7  = (BSP_IO_PORT_P51 | 0x7),                                                                 ///< IO port P51 pin 7
    BSP_IO_PORT_P51_PIN_8  = (BSP_IO_PORT_P51 | 0x8),                                                                 ///< IO port P51 pin 8
    BSP_IO_PORT_P51_PIN_9  = (BSP_IO_PORT_P51 | 0x9),                                                                 ///< IO port P51 pin 9
    BSP_IO_PORT_P51_PIN_10 = (BSP_IO_PORT_P51 | 0xA),                                                                 ///< IO port P51 pin 10
    BSP_IO_PORT_P51_PIN_11 = (BSP_IO_PORT_P51 | 0xB),                                                                 ///< IO port P51 pin 11
    BSP_IO_PORT_P51_PIN_12 = (BSP_IO_PORT_P51 | 0xC),                                                                 ///< IO port P51 pin 12
    BSP_IO_PORT_P51_PIN_13 = (BSP_IO_PORT_P51 | 0xD),                                                                 ///< IO port P51 pin 13
    BSP_IO_PORT_P51_PIN_14 = (BSP_IO_PORT_P51 | 0xE),                                                                 ///< IO port P51 pin 14
    BSP_IO_PORT_P51_PIN_15 = (BSP_IO_PORT_P51 | 0xF),                                                                 ///< IO port P51 pin 15

    BSP_IO_PORT_P52_PIN_0  = (BSP_IO_PORT_P52 | 0x0),                                                                 ///< IO port P52 pin 0
    BSP_IO_PORT_P52_PIN_1  = (BSP_IO_PORT_P52 | 0x1),                                                                 ///< IO port P52 pin 1
    BSP_IO_PORT_P52_PIN_2  = (BSP_IO_PORT_P52 | 0x2),                                                                 ///< IO port P52 pin 2
    BSP_IO_PORT_P52_PIN_3  = (BSP_IO_PORT_P52 | 0x3),                                                                 ///< IO port P52 pin 3
    BSP_IO_PORT_P52_PIN_4  = (BSP_IO_PORT_P52 | 0x4),                                                                 ///< IO port P52 pin 4
    BSP_IO_PORT_P52_PIN_5  = (BSP_IO_PORT_P52 | 0x5),                                                                 ///< IO port P52 pin 5
    BSP_IO_PORT_P52_PIN_6  = (BSP_IO_PORT_P52 | 0x6),                                                                 ///< IO port P52 pin 6
    BSP_IO_PORT_P52_PIN_7  = (BSP_IO_PORT_P52 | 0x7),                                                                 ///< IO port P52 pin 7
    BSP_IO_PORT_P52_PIN_8  = (BSP_IO_PORT_P52 | 0x8),                                                                 ///< IO port P52 pin 8
    BSP_IO_PORT_P52_PIN_9  = (BSP_IO_PORT_P52 | 0x9),                                                                 ///< IO port P52 pin 9
    BSP_IO_PORT_P52_PIN_10 = (BSP_IO_PORT_P52 | 0xA),                                                                 ///< IO port P52 pin 10
    BSP_IO_PORT_P52_PIN_11 = (BSP_IO_PORT_P52 | 0xB),                                                                 ///< IO port P52 pin 11
    BSP_IO_PORT_P52_PIN_12 = (BSP_IO_PORT_P52 | 0xC),                                                                 ///< IO port P52 pin 12
    BSP_IO_PORT_P52_PIN_13 = (BSP_IO_PORT_P52 | 0xD),                                                                 ///< IO port P52 pin 13
    BSP_IO_PORT_P52_PIN_14 = (BSP_IO_PORT_P52 | 0xE),                                                                 ///< IO port P52 pin 14
    BSP_IO_PORT_P52_PIN_15 = (BSP_IO_PORT_P52 | 0xF),                                                                 ///< IO port P52 pin 15

    BSP_IO_PORT_P53_PIN_0  = (BSP_IO_PORT_P53 | 0x0),                                                                 ///< IO port P53 pin 0
    BSP_IO_PORT_P53_PIN_1  = (BSP_IO_PORT_P53 | 0x1),                                                                 ///< IO port P53 pin 1
    BSP_IO_PORT_P53_PIN_2  = (BSP_IO_PORT_P53 | 0x2),                                                                 ///< IO port P53 pin 2
    BSP_IO_PORT_P53_PIN_3  = (BSP_IO_PORT_P53 | 0x3),                                                                 ///< IO port P53 pin 3
    BSP_IO_PORT_P53_PIN_4  = (BSP_IO_PORT_P53 | 0x4),                                                                 ///< IO port P53 pin 4
    BSP_IO_PORT_P53_PIN_5  = (BSP_IO_PORT_P53 | 0x5),                                                                 ///< IO port P53 pin 5
    BSP_IO_PORT_P53_PIN_6  = (BSP_IO_PORT_P53 | 0x6),                                                                 ///< IO port P53 pin 6
    BSP_IO_PORT_P53_PIN_7  = (BSP_IO_PORT_P53 | 0x7),                                                                 ///< IO port P53 pin 7
    BSP_IO_PORT_P53_PIN_8  = (BSP_IO_PORT_P53 | 0x8),                                                                 ///< IO port P53 pin 8
    BSP_IO_PORT_P53_PIN_9  = (BSP_IO_PORT_P53 | 0x9),                                                                 ///< IO port P53 pin 9
    BSP_IO_PORT_P53_PIN_10 = (BSP_IO_PORT_P53 | 0xA),                                                                 ///< IO port P53 pin 10
    BSP_IO_PORT_P53_PIN_11 = (BSP_IO_PORT_P53 | 0xB),                                                                 ///< IO port P53 pin 11
    BSP_IO_PORT_P53_PIN_12 = (BSP_IO_PORT_P53 | 0xC),                                                                 ///< IO port P53 pin 12
    BSP_IO_PORT_P53_PIN_13 = (BSP_IO_PORT_P53 | 0xD),                                                                 ///< IO port P53 pin 13
    BSP_IO_PORT_P53_PIN_14 = (BSP_IO_PORT_P53 | 0xE),                                                                 ///< IO port P53 pin 14
    BSP_IO_PORT_P53_PIN_15 = (BSP_IO_PORT_P53 | 0xF),                                                                 ///< IO port P53 pin 15

    BSP_IO_PORT_P54_PIN_0  = (BSP_IO_PORT_P54 | 0x0),                                                                 ///< IO port P54 pin 0
    BSP_IO_PORT_P54_PIN_1  = (BSP_IO_PORT_P54 | 0x1),                                                                 ///< IO port P54 pin 1
    BSP_IO_PORT_P54_PIN_2  = (BSP_IO_PORT_P54 | 0x2),                                                                 ///< IO port P54 pin 2
    BSP_IO_PORT_P54_PIN_3  = (BSP_IO_PORT_P54 | 0x3),                                                                 ///< IO port P54 pin 3
    BSP_IO_PORT_P54_PIN_4  = (BSP_IO_PORT_P54 | 0x4),                                                                 ///< IO port P54 pin 4
    BSP_IO_PORT_P54_PIN_5  = (BSP_IO_PORT_P54 | 0x5),                                                                 ///< IO port P54 pin 5
    BSP_IO_PORT_P54_PIN_6  = (BSP_IO_PORT_P54 | 0x6),                                                                 ///< IO port P54 pin 6
    BSP_IO_PORT_P54_PIN_7  = (BSP_IO_PORT_P54 | 0x7),                                                                 ///< IO port P54 pin 7
    BSP_IO_PORT_P54_PIN_8  = (BSP_IO_PORT_P54 | 0x8),                                                                 ///< IO port P54 pin 8
    BSP_IO_PORT_P54_PIN_9  = (BSP_IO_PORT_P54 | 0x9),                                                                 ///< IO port P54 pin 9
    BSP_IO_PORT_P54_PIN_10 = (BSP_IO_PORT_P54 | 0xA),                                                                 ///< IO port P54 pin 10
    BSP_IO_PORT_P54_PIN_11 = (BSP_IO_PORT_P54 | 0xB),                                                                 ///< IO port P54 pin 11
    BSP_IO_PORT_P54_PIN_12 = (BSP_IO_PORT_P54 | 0xC),                                                                 ///< IO port P54 pin 12
    BSP_IO_PORT_P54_PIN_13 = (BSP_IO_PORT_P54 | 0xD),                                                                 ///< IO port P54 pin 13
    BSP_IO_PORT_P54_PIN_14 = (BSP_IO_PORT_P54 | 0xE),                                                                 ///< IO port P54 pin 14
    BSP_IO_PORT_P54_PIN_15 = (BSP_IO_PORT_P54 | 0xF),                                                                 ///< IO port P54 pin 15

    BSP_IO_PORT_P55_PIN_0  = (BSP_IO_PORT_P55 | 0x0),                                                                 ///< IO port P55 pin 0
    BSP_IO_PORT_P55_PIN_1  = (BSP_IO_PORT_P55 | 0x1),                                                                 ///< IO port P55 pin 1
    BSP_IO_PORT_P55_PIN_2  = (BSP_IO_PORT_P55 | 0x2),                                                                 ///< IO port P55 pin 2
    BSP_IO_PORT_P55_PIN_3  = (BSP_IO_PORT_P55 | 0x3),                                                                 ///< IO port P55 pin 3
    BSP_IO_PORT_P55_PIN_4  = (BSP_IO_PORT_P55 | 0x4),                                                                 ///< IO port P55 pin 4
    BSP_IO_PORT_P55_PIN_5  = (BSP_IO_PORT_P55 | 0x5),                                                                 ///< IO port P55 pin 5
    BSP_IO_PORT_P55_PIN_6  = (BSP_IO_PORT_P55 | 0x6),                                                                 ///< IO port P55 pin 6
    BSP_IO_PORT_P55_PIN_7  = (BSP_IO_PORT_P55 | 0x7),                                                                 ///< IO port P55 pin 7
    BSP_IO_PORT_P55_PIN_8  = (BSP_IO_PORT_P55 | 0x8),                                                                 ///< IO port P55 pin 8
    BSP_IO_PORT_P55_PIN_9  = (BSP_IO_PORT_P55 | 0x9),                                                                 ///< IO port P55 pin 9
    BSP_IO_PORT_P55_PIN_10 = (BSP_IO_PORT_P55 | 0xA),                                                                 ///< IO port P55 pin 10
    BSP_IO_PORT_P55_PIN_11 = (BSP_IO_PORT_P55 | 0xB),                                                                 ///< IO port P55 pin 11
    BSP_IO_PORT_P55_PIN_12 = (BSP_IO_PORT_P55 | 0xC),                                                                 ///< IO port P55 pin 12
    BSP_IO_PORT_P55_PIN_13 = (BSP_IO_PORT_P55 | 0xD),                                                                 ///< IO port P55 pin 13
    BSP_IO_PORT_P55_PIN_14 = (BSP_IO_PORT_P55 | 0xE),                                                                 ///< IO port P55 pin 14
    BSP_IO_PORT_P55_PIN_15 = (BSP_IO_PORT_P55 | 0xF),                                                                 ///< IO port P55 pin 15

    BSP_IO_PORT_P56_PIN_0  = (BSP_IO_PORT_P56 | 0x0),                                                                 ///< IO port P56 pin 0
    BSP_IO_PORT_P56_PIN_1  = (BSP_IO_PORT_P56 | 0x1),                                                                 ///< IO port P56 pin 1
    BSP_IO_PORT_P56_PIN_2  = (BSP_IO_PORT_P56 | 0x2),                                                                 ///< IO port P56 pin 2
    BSP_IO_PORT_P56_PIN_3  = (BSP_IO_PORT_P56 | 0x3),                                                                 ///< IO port P56 pin 3
    BSP_IO_PORT_P56_PIN_4  = (BSP_IO_PORT_P56 | 0x4),                                                                 ///< IO port P56 pin 4
    BSP_IO_PORT_P56_PIN_5  = (BSP_IO_PORT_P56 | 0x5),                                                                 ///< IO port P56 pin 5
    BSP_IO_PORT_P56_PIN_6  = (BSP_IO_PORT_P56 | 0x6),                                                                 ///< IO port P56 pin 6
    BSP_IO_PORT_P56_PIN_7  = (BSP_IO_PORT_P56 | 0x7),                                                                 ///< IO port P56 pin 7
    BSP_IO_PORT_P56_PIN_8  = (BSP_IO_PORT_P56 | 0x8),                                                                 ///< IO port P56 pin 8
    BSP_IO_PORT_P56_PIN_9  = (BSP_IO_PORT_P56 | 0x9),                                                                 ///< IO port P56 pin 9
    BSP_IO_PORT_P56_PIN_10 = (BSP_IO_PORT_P56 | 0xA),                                                                 ///< IO port P56 pin 10
    BSP_IO_PORT_P56_PIN_11 = (BSP_IO_PORT_P56 | 0xB),                                                                 ///< IO port P56 pin 11
    BSP_IO_PORT_P56_PIN_12 = (BSP_IO_PORT_P56 | 0xC),                                                                 ///< IO port P56 pin 12
    BSP_IO_PORT_P56_PIN_13 = (BSP_IO_PORT_P56 | 0xD),                                                                 ///< IO port P56 pin 13
    BSP_IO_PORT_P56_PIN_14 = (BSP_IO_PORT_P56 | 0xE),                                                                 ///< IO port P56 pin 14
    BSP_IO_PORT_P56_PIN_15 = (BSP_IO_PORT_P56 | 0xF),                                                                 ///< IO port P56 pin 15
#elif (BSP_PACKAGE_PINS_BGA373 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00_PIN_0  = (BSP_IO_PORT_P00 | 0x0),                                                                 ///< IO port P00 pin 0
    BSP_IO_PORT_P00_PIN_1  = (BSP_IO_PORT_P00 | 0x1),                                                                 ///< IO port P00 pin 1
    BSP_IO_PORT_P00_PIN_2  = (BSP_IO_PORT_P00 | 0x2),                                                                 ///< IO port P00 pin 2
    BSP_IO_PORT_P00_PIN_3  = (BSP_IO_PORT_P00 | 0x3),                                                                 ///< IO port P00 pin 3
    BSP_IO_PORT_P00_PIN_4  = (BSP_IO_PORT_P00 | 0x4),                                                                 ///< IO port P00 pin 4
    BSP_IO_PORT_P00_PIN_5  = (BSP_IO_PORT_P00 | 0x5),                                                                 ///< IO port P00 pin 5
    BSP_IO_PORT_P00_PIN_6  = (BSP_IO_PORT_P00 | 0x6),                                                                 ///< IO port P00 pin 6
    BSP_IO_PORT_P00_PIN_7  = (BSP_IO_PORT_P00 | 0x7),                                                                 ///< IO port P00 pin 7
    BSP_IO_PORT_P00_PIN_8  = (BSP_IO_PORT_P00 | 0x8),                                                                 ///< IO port P00 pin 8
    BSP_IO_PORT_P00_PIN_9  = (BSP_IO_PORT_P00 | 0x9),                                                                 ///< IO port P00 pin 9
    BSP_IO_PORT_P00_PIN_10 = (BSP_IO_PORT_P00 | 0xA),                                                                 ///< IO port P00 pin 10
    BSP_IO_PORT_P00_PIN_11 = (BSP_IO_PORT_P00 | 0xB),                                                                 ///< IO port P00 pin 11

    BSP_IO_PORT_P01_PIN_3 = (BSP_IO_PORT_P01 | 0x3),                                                                  ///< IO port P01 pin 3
    BSP_IO_PORT_P01_PIN_4 = (BSP_IO_PORT_P01 | 0x4),                                                                  ///< IO port P01 pin 4
    BSP_IO_PORT_P01_PIN_5 = (BSP_IO_PORT_P01 | 0x5),                                                                  ///< IO port P01 pin 5
    BSP_IO_PORT_P01_PIN_6 = (BSP_IO_PORT_P01 | 0x6),                                                                  ///< IO port P01 pin 6
    BSP_IO_PORT_P01_PIN_7 = (BSP_IO_PORT_P01 | 0x7),                                                                  ///< IO port P01 pin 7
    BSP_IO_PORT_P01_PIN_8 = (BSP_IO_PORT_P01 | 0x8),                                                                  ///< IO port P01 pin 8

    BSP_IO_PORT_P02_PIN_0  = (BSP_IO_PORT_P02 | 0x0),                                                                 ///< IO port P02 pin 0
    BSP_IO_PORT_P02_PIN_1  = (BSP_IO_PORT_P02 | 0x1),                                                                 ///< IO port P02 pin 1
    BSP_IO_PORT_P02_PIN_2  = (BSP_IO_PORT_P02 | 0x2),                                                                 ///< IO port P02 pin 2
    BSP_IO_PORT_P02_PIN_3  = (BSP_IO_PORT_P02 | 0x3),                                                                 ///< IO port P02 pin 3
    BSP_IO_PORT_P02_PIN_4  = (BSP_IO_PORT_P02 | 0x4),                                                                 ///< IO port P02 pin 4
    BSP_IO_PORT_P02_PIN_5  = (BSP_IO_PORT_P02 | 0x5),                                                                 ///< IO port P02 pin 5
    BSP_IO_PORT_P02_PIN_6  = (BSP_IO_PORT_P02 | 0x6),                                                                 ///< IO port P02 pin 6
    BSP_IO_PORT_P02_PIN_7  = (BSP_IO_PORT_P02 | 0x7),                                                                 ///< IO port P02 pin 7
    BSP_IO_PORT_P02_PIN_8  = (BSP_IO_PORT_P02 | 0x8),                                                                 ///< IO port P02 pin 8
    BSP_IO_PORT_P02_PIN_9  = (BSP_IO_PORT_P02 | 0x9),                                                                 ///< IO port P02 pin 9
    BSP_IO_PORT_P02_PIN_10 = (BSP_IO_PORT_P02 | 0xA),                                                                 ///< IO port P02 pin 10
    BSP_IO_PORT_P02_PIN_11 = (BSP_IO_PORT_P02 | 0xB),                                                                 ///< IO port P02 pin 11

    BSP_IO_PORT_P10_PIN_0  = (BSP_IO_PORT_P10 | 0x0),                                                                 ///< IO port P10 pin 0
    BSP_IO_PORT_P10_PIN_1  = (BSP_IO_PORT_P10 | 0x1),                                                                 ///< IO port P10 pin 1
    BSP_IO_PORT_P10_PIN_2  = (BSP_IO_PORT_P10 | 0x2),                                                                 ///< IO port P10 pin 2
    BSP_IO_PORT_P10_PIN_3  = (BSP_IO_PORT_P10 | 0x3),                                                                 ///< IO port P10 pin 3
    BSP_IO_PORT_P10_PIN_4  = (BSP_IO_PORT_P10 | 0x4),                                                                 ///< IO port P10 pin 4
    BSP_IO_PORT_P10_PIN_5  = (BSP_IO_PORT_P10 | 0x5),                                                                 ///< IO port P10 pin 5
    BSP_IO_PORT_P10_PIN_6  = (BSP_IO_PORT_P10 | 0x6),                                                                 ///< IO port P10 pin 6
    BSP_IO_PORT_P10_PIN_7  = (BSP_IO_PORT_P10 | 0x7),                                                                 ///< IO port P10 pin 7
    BSP_IO_PORT_P10_PIN_8  = (BSP_IO_PORT_P10 | 0x8),                                                                 ///< IO port P10 pin 8
    BSP_IO_PORT_P10_PIN_9  = (BSP_IO_PORT_P10 | 0x9),                                                                 ///< IO port P10 pin 9
    BSP_IO_PORT_P10_PIN_10 = (BSP_IO_PORT_P10 | 0xA),                                                                 ///< IO port P10 pin 10
    BSP_IO_PORT_P10_PIN_11 = (BSP_IO_PORT_P10 | 0xB),                                                                 ///< IO port P10 pin 11
    BSP_IO_PORT_P10_PIN_12 = (BSP_IO_PORT_P10 | 0xC),                                                                 ///< IO port P10 pin 12
    BSP_IO_PORT_P10_PIN_13 = (BSP_IO_PORT_P10 | 0xD),                                                                 ///< IO port P10 pin 13
    BSP_IO_PORT_P10_PIN_14 = (BSP_IO_PORT_P10 | 0xE),                                                                 ///< IO port P10 pin 14

    BSP_IO_PORT_P11_PIN_0  = (BSP_IO_PORT_P11 | 0x0),                                                                 ///< IO port P11 pin 0
    BSP_IO_PORT_P11_PIN_1  = (BSP_IO_PORT_P11 | 0x1),                                                                 ///< IO port P11 pin 1
    BSP_IO_PORT_P11_PIN_2  = (BSP_IO_PORT_P11 | 0x2),                                                                 ///< IO port P11 pin 2
    BSP_IO_PORT_P11_PIN_3  = (BSP_IO_PORT_P11 | 0x3),                                                                 ///< IO port P11 pin 3
    BSP_IO_PORT_P11_PIN_4  = (BSP_IO_PORT_P11 | 0x4),                                                                 ///< IO port P11 pin 4
    BSP_IO_PORT_P11_PIN_5  = (BSP_IO_PORT_P11 | 0x5),                                                                 ///< IO port P11 pin 5
    BSP_IO_PORT_P11_PIN_6  = (BSP_IO_PORT_P11 | 0x6),                                                                 ///< IO port P11 pin 6
    BSP_IO_PORT_P11_PIN_7  = (BSP_IO_PORT_P11 | 0x7),                                                                 ///< IO port P11 pin 7
    BSP_IO_PORT_P11_PIN_8  = (BSP_IO_PORT_P11 | 0x8),                                                                 ///< IO port P11 pin 8
    BSP_IO_PORT_P11_PIN_9  = (BSP_IO_PORT_P11 | 0x9),                                                                 ///< IO port P11 pin 9
    BSP_IO_PORT_P11_PIN_10 = (BSP_IO_PORT_P11 | 0xA),                                                                 ///< IO port P11 pin 10

    BSP_IO_PORT_P12_PIN_0 = (BSP_IO_PORT_P12 | 0x0),                                                                  ///< IO port P12 pin 0
    BSP_IO_PORT_P12_PIN_1 = (BSP_IO_PORT_P12 | 0x1),                                                                  ///< IO port P12 pin 1
    BSP_IO_PORT_P12_PIN_2 = (BSP_IO_PORT_P12 | 0x2),                                                                  ///< IO port P12 pin 2
    BSP_IO_PORT_P12_PIN_3 = (BSP_IO_PORT_P12 | 0x3),                                                                  ///< IO port P12 pin 3
    BSP_IO_PORT_P12_PIN_4 = (BSP_IO_PORT_P12 | 0x4),                                                                  ///< IO port P12 pin 4
    BSP_IO_PORT_P12_PIN_5 = (BSP_IO_PORT_P12 | 0x5),                                                                  ///< IO port P12 pin 5
    BSP_IO_PORT_P12_PIN_6 = (BSP_IO_PORT_P12 | 0x6),                                                                  ///< IO port P12 pin 6
    BSP_IO_PORT_P12_PIN_7 = (BSP_IO_PORT_P12 | 0x7),                                                                  ///< IO port P12 pin 7
    BSP_IO_PORT_P12_PIN_8 = (BSP_IO_PORT_P12 | 0x8),                                                                  ///< IO port P12 pin 8
    BSP_IO_PORT_P12_PIN_9 = (BSP_IO_PORT_P12 | 0x9),                                                                  ///< IO port P12 pin 9

    BSP_IO_PORT_P13_PIN_0  = (BSP_IO_PORT_P13 | 0x0),                                                                 ///< IO port P13 pin 0
    BSP_IO_PORT_P13_PIN_1  = (BSP_IO_PORT_P13 | 0x1),                                                                 ///< IO port P13 pin 1
    BSP_IO_PORT_P13_PIN_2  = (BSP_IO_PORT_P13 | 0x2),                                                                 ///< IO port P13 pin 2
    BSP_IO_PORT_P13_PIN_3  = (BSP_IO_PORT_P13 | 0x3),                                                                 ///< IO port P13 pin 3
    BSP_IO_PORT_P13_PIN_8  = (BSP_IO_PORT_P13 | 0x8),                                                                 ///< IO port P13 pin 8
    BSP_IO_PORT_P13_PIN_9  = (BSP_IO_PORT_P13 | 0x9),                                                                 ///< IO port P13 pin 9
    BSP_IO_PORT_P13_PIN_10 = (BSP_IO_PORT_P13 | 0xA),                                                                 ///< IO port P13 pin 10
    BSP_IO_PORT_P13_PIN_11 = (BSP_IO_PORT_P13 | 0xB),                                                                 ///< IO port P13 pin 11
    BSP_IO_PORT_P13_PIN_12 = (BSP_IO_PORT_P13 | 0xC),                                                                 ///< IO port P13 pin 12
    BSP_IO_PORT_P13_PIN_13 = (BSP_IO_PORT_P13 | 0xD),                                                                 ///< IO port P13 pin 13
    BSP_IO_PORT_P13_PIN_14 = (BSP_IO_PORT_P13 | 0xE),                                                                 ///< IO port P13 pin 14

    BSP_IO_PORT_P14_PIN_0  = (BSP_IO_PORT_P14 | 0x0),                                                                 ///< IO port P14 pin 0
    BSP_IO_PORT_P14_PIN_1  = (BSP_IO_PORT_P14 | 0x1),                                                                 ///< IO port P14 pin 1
    BSP_IO_PORT_P14_PIN_2  = (BSP_IO_PORT_P14 | 0x2),                                                                 ///< IO port P14 pin 2
    BSP_IO_PORT_P14_PIN_3  = (BSP_IO_PORT_P14 | 0x3),                                                                 ///< IO port P14 pin 3
    BSP_IO_PORT_P14_PIN_4  = (BSP_IO_PORT_P14 | 0x4),                                                                 ///< IO port P14 pin 4
    BSP_IO_PORT_P14_PIN_5  = (BSP_IO_PORT_P14 | 0x5),                                                                 ///< IO port P14 pin 5
    BSP_IO_PORT_P14_PIN_6  = (BSP_IO_PORT_P14 | 0x6),                                                                 ///< IO port P14 pin 6
    BSP_IO_PORT_P14_PIN_7  = (BSP_IO_PORT_P14 | 0x7),                                                                 ///< IO port P14 pin 7
    BSP_IO_PORT_P14_PIN_8  = (BSP_IO_PORT_P14 | 0x8),                                                                 ///< IO port P14 pin 8
    BSP_IO_PORT_P14_PIN_9  = (BSP_IO_PORT_P14 | 0x9),                                                                 ///< IO port P14 pin 9
    BSP_IO_PORT_P14_PIN_10 = (BSP_IO_PORT_P14 | 0xA),                                                                 ///< IO port P14 pin 10
    BSP_IO_PORT_P14_PIN_11 = (BSP_IO_PORT_P14 | 0xB),                                                                 ///< IO port P14 pin 11
    BSP_IO_PORT_P14_PIN_12 = (BSP_IO_PORT_P14 | 0xC),                                                                 ///< IO port P14 pin 12

    BSP_IO_PORT_P20_PIN_0 = (BSP_IO_PORT_P20 | 0x0),                                                                  ///< IO port P20 pin 0
    BSP_IO_PORT_P20_PIN_1 = (BSP_IO_PORT_P20 | 0x1),                                                                  ///< IO port P20 pin 1
    BSP_IO_PORT_P20_PIN_2 = (BSP_IO_PORT_P20 | 0x2),                                                                  ///< IO port P20 pin 2
    BSP_IO_PORT_P20_PIN_3 = (BSP_IO_PORT_P20 | 0x3),                                                                  ///< IO port P20 pin 3
    BSP_IO_PORT_P20_PIN_4 = (BSP_IO_PORT_P20 | 0x4),                                                                  ///< IO port P20 pin 4
    BSP_IO_PORT_P20_PIN_5 = (BSP_IO_PORT_P20 | 0x5),                                                                  ///< IO port P20 pin 5
    BSP_IO_PORT_P20_PIN_6 = (BSP_IO_PORT_P20 | 0x6),                                                                  ///< IO port P20 pin 6
    BSP_IO_PORT_P20_PIN_7 = (BSP_IO_PORT_P20 | 0x7),                                                                  ///< IO port P20 pin 7

    BSP_IO_PORT_P21_PIN_2 = (BSP_IO_PORT_P21 | 0x2),                                                                  ///< IO port P21 pin 2
    BSP_IO_PORT_P21_PIN_3 = (BSP_IO_PORT_P21 | 0x3),                                                                  ///< IO port P21 pin 3
    BSP_IO_PORT_P21_PIN_4 = (BSP_IO_PORT_P21 | 0x4),                                                                  ///< IO port P21 pin 4
    BSP_IO_PORT_P21_PIN_5 = (BSP_IO_PORT_P21 | 0x5),                                                                  ///< IO port P21 pin 5

    BSP_IO_PORT_P22_PIN_0  = (BSP_IO_PORT_P22 | 0x0),                                                                 ///< IO port P22 pin 0
    BSP_IO_PORT_P22_PIN_1  = (BSP_IO_PORT_P22 | 0x1),                                                                 ///< IO port P22 pin 1
    BSP_IO_PORT_P22_PIN_2  = (BSP_IO_PORT_P22 | 0x2),                                                                 ///< IO port P22 pin 2
    BSP_IO_PORT_P22_PIN_3  = (BSP_IO_PORT_P22 | 0x3),                                                                 ///< IO port P22 pin 3
    BSP_IO_PORT_P22_PIN_4  = (BSP_IO_PORT_P22 | 0x4),                                                                 ///< IO port P22 pin 4
    BSP_IO_PORT_P22_PIN_5  = (BSP_IO_PORT_P22 | 0x5),                                                                 ///< IO port P22 pin 5
    BSP_IO_PORT_P22_PIN_6  = (BSP_IO_PORT_P22 | 0x6),                                                                 ///< IO port P22 pin 6
    BSP_IO_PORT_P22_PIN_7  = (BSP_IO_PORT_P22 | 0x7),                                                                 ///< IO port P22 pin 7
    BSP_IO_PORT_P22_PIN_8  = (BSP_IO_PORT_P22 | 0x8),                                                                 ///< IO port P22 pin 8
    BSP_IO_PORT_P22_PIN_9  = (BSP_IO_PORT_P22 | 0x9),                                                                 ///< IO port P22 pin 9
    BSP_IO_PORT_P22_PIN_10 = (BSP_IO_PORT_P22 | 0xA),                                                                 ///< IO port P22 pin 10
    BSP_IO_PORT_P22_PIN_11 = (BSP_IO_PORT_P22 | 0xB),                                                                 ///< IO port P22 pin 11
    BSP_IO_PORT_P22_PIN_12 = (BSP_IO_PORT_P22 | 0xC),                                                                 ///< IO port P22 pin 12
    BSP_IO_PORT_P22_PIN_13 = (BSP_IO_PORT_P22 | 0xD),                                                                 ///< IO port P22 pin 13

    BSP_IO_PORT_P23_PIN_0  = (BSP_IO_PORT_P23 | 0x0),                                                                 ///< IO port P23 pin 0
    BSP_IO_PORT_P23_PIN_1  = (BSP_IO_PORT_P23 | 0x1),                                                                 ///< IO port P23 pin 1
    BSP_IO_PORT_P23_PIN_2  = (BSP_IO_PORT_P23 | 0x2),                                                                 ///< IO port P23 pin 2
    BSP_IO_PORT_P23_PIN_3  = (BSP_IO_PORT_P23 | 0x3),                                                                 ///< IO port P23 pin 3
    BSP_IO_PORT_P23_PIN_4  = (BSP_IO_PORT_P23 | 0x4),                                                                 ///< IO port P23 pin 4
    BSP_IO_PORT_P23_PIN_5  = (BSP_IO_PORT_P23 | 0x5),                                                                 ///< IO port P23 pin 5
    BSP_IO_PORT_P23_PIN_6  = (BSP_IO_PORT_P23 | 0x6),                                                                 ///< IO port P23 pin 6
    BSP_IO_PORT_P23_PIN_7  = (BSP_IO_PORT_P23 | 0x7),                                                                 ///< IO port P23 pin 7
    BSP_IO_PORT_P23_PIN_8  = (BSP_IO_PORT_P23 | 0x8),                                                                 ///< IO port P23 pin 8
    BSP_IO_PORT_P23_PIN_9  = (BSP_IO_PORT_P23 | 0x9),                                                                 ///< IO port P23 pin 9
    BSP_IO_PORT_P23_PIN_10 = (BSP_IO_PORT_P23 | 0xA),                                                                 ///< IO port P23 pin 10
    BSP_IO_PORT_P23_PIN_11 = (BSP_IO_PORT_P23 | 0xB),                                                                 ///< IO port P23 pin 11

    BSP_IO_PORT_P24_PIN_8  = (BSP_IO_PORT_P24 | 0x8),                                                                 ///< IO port P24 pin 8
    BSP_IO_PORT_P24_PIN_9  = (BSP_IO_PORT_P24 | 0x9),                                                                 ///< IO port P24 pin 9
    BSP_IO_PORT_P24_PIN_10 = (BSP_IO_PORT_P24 | 0xA),                                                                 ///< IO port P24 pin 10
    BSP_IO_PORT_P24_PIN_11 = (BSP_IO_PORT_P24 | 0xB),                                                                 ///< IO port P24 pin 11
    BSP_IO_PORT_P24_PIN_12 = (BSP_IO_PORT_P24 | 0xC),                                                                 ///< IO port P24 pin 12

    BSP_IO_PORT_P25_PIN_0 = (BSP_IO_PORT_P25 | 0x0),                                                                  ///< IO port P25 pin 0
    BSP_IO_PORT_P25_PIN_1 = (BSP_IO_PORT_P25 | 0x1),                                                                  ///< IO port P25 pin 1
    BSP_IO_PORT_P25_PIN_2 = (BSP_IO_PORT_P25 | 0x2),                                                                  ///< IO port P25 pin 2
    BSP_IO_PORT_P25_PIN_3 = (BSP_IO_PORT_P25 | 0x3),                                                                  ///< IO port P25 pin 3
    BSP_IO_PORT_P25_PIN_4 = (BSP_IO_PORT_P25 | 0x4),                                                                  ///< IO port P25 pin 4
    BSP_IO_PORT_P25_PIN_5 = (BSP_IO_PORT_P25 | 0x5),                                                                  ///< IO port P25 pin 5
    BSP_IO_PORT_P25_PIN_6 = (BSP_IO_PORT_P25 | 0x6),                                                                  ///< IO port P25 pin 6

    BSP_IO_PORT_P30_PIN_0 = (BSP_IO_PORT_P30 | 0x0),                                                                  ///< IO port P30 pin 0
    BSP_IO_PORT_P30_PIN_1 = (BSP_IO_PORT_P30 | 0x1),                                                                  ///< IO port P30 pin 1
    BSP_IO_PORT_P30_PIN_2 = (BSP_IO_PORT_P30 | 0x2),                                                                  ///< IO port P30 pin 2
    BSP_IO_PORT_P30_PIN_3 = (BSP_IO_PORT_P30 | 0x3),                                                                  ///< IO port P30 pin 3
    BSP_IO_PORT_P30_PIN_4 = (BSP_IO_PORT_P30 | 0x4),                                                                  ///< IO port P30 pin 4

    BSP_IO_PORT_P32_PIN_0 = (BSP_IO_PORT_P32 | 0x0),                                                                  ///< IO port P32 pin 0
    BSP_IO_PORT_P32_PIN_1 = (BSP_IO_PORT_P32 | 0x1),                                                                  ///< IO port P32 pin 1
    BSP_IO_PORT_P32_PIN_2 = (BSP_IO_PORT_P32 | 0x2),                                                                  ///< IO port P32 pin 2
    BSP_IO_PORT_P32_PIN_3 = (BSP_IO_PORT_P32 | 0x3),                                                                  ///< IO port P32 pin 3
    BSP_IO_PORT_P32_PIN_4 = (BSP_IO_PORT_P32 | 0x4),                                                                  ///< IO port P32 pin 4
    BSP_IO_PORT_P32_PIN_5 = (BSP_IO_PORT_P32 | 0x5),                                                                  ///< IO port P32 pin 5
    BSP_IO_PORT_P32_PIN_6 = (BSP_IO_PORT_P32 | 0x6),                                                                  ///< IO port P32 pin 6

    BSP_IO_PORT_P33_PIN_0  = (BSP_IO_PORT_P33 | 0x0),                                                                 ///< IO port P33 pin 0
    BSP_IO_PORT_P33_PIN_1  = (BSP_IO_PORT_P33 | 0x1),                                                                 ///< IO port P33 pin 1
    BSP_IO_PORT_P33_PIN_2  = (BSP_IO_PORT_P33 | 0x2),                                                                 ///< IO port P33 pin 2
    BSP_IO_PORT_P33_PIN_3  = (BSP_IO_PORT_P33 | 0x3),                                                                 ///< IO port P33 pin 3
    BSP_IO_PORT_P33_PIN_4  = (BSP_IO_PORT_P33 | 0x4),                                                                 ///< IO port P33 pin 4
    BSP_IO_PORT_P33_PIN_5  = (BSP_IO_PORT_P33 | 0x5),                                                                 ///< IO port P33 pin 5
    BSP_IO_PORT_P33_PIN_6  = (BSP_IO_PORT_P33 | 0x6),                                                                 ///< IO port P33 pin 6
    BSP_IO_PORT_P33_PIN_7  = (BSP_IO_PORT_P33 | 0x7),                                                                 ///< IO port P33 pin 7
    BSP_IO_PORT_P33_PIN_8  = (BSP_IO_PORT_P33 | 0x8),                                                                 ///< IO port P33 pin 8
    BSP_IO_PORT_P33_PIN_9  = (BSP_IO_PORT_P33 | 0x9),                                                                 ///< IO port P33 pin 9
    BSP_IO_PORT_P33_PIN_10 = (BSP_IO_PORT_P33 | 0xA),                                                                 ///< IO port P33 pin 10
    BSP_IO_PORT_P33_PIN_11 = (BSP_IO_PORT_P33 | 0xB),                                                                 ///< IO port P33 pin 11
    BSP_IO_PORT_P33_PIN_12 = (BSP_IO_PORT_P33 | 0xC),                                                                 ///< IO port P33 pin 12
    BSP_IO_PORT_P33_PIN_13 = (BSP_IO_PORT_P33 | 0xD),                                                                 ///< IO port P33 pin 13

    BSP_IO_PORT_P34_PIN_0 = (BSP_IO_PORT_P34 | 0x0),                                                                  ///< IO port P34 pin 0
    BSP_IO_PORT_P34_PIN_1 = (BSP_IO_PORT_P34 | 0x1),                                                                  ///< IO port P34 pin 1
    BSP_IO_PORT_P34_PIN_2 = (BSP_IO_PORT_P34 | 0x2),                                                                  ///< IO port P34 pin 2
    BSP_IO_PORT_P34_PIN_3 = (BSP_IO_PORT_P34 | 0x3),                                                                  ///< IO port P34 pin 3
    BSP_IO_PORT_P34_PIN_4 = (BSP_IO_PORT_P34 | 0x4),                                                                  ///< IO port P34 pin 4

    BSP_IO_PORT_P27_PIN_0 = (BSP_IO_PORT_P27 | 0x0),                                                                  ///< IO port P27 pin 0

    BSP_IO_PORT_JP00_PIN_0 = (BSP_IO_PORT_JP00 | 0x0),                                                                ///< IO port JP00 pin 0
    BSP_IO_PORT_JP00_PIN_1 = (BSP_IO_PORT_JP00 | 0x1),                                                                ///< IO port JP00 pin 1
    BSP_IO_PORT_JP00_PIN_2 = (BSP_IO_PORT_JP00 | 0x2),                                                                ///< IO port JP00 pin 2
    BSP_IO_PORT_JP00_PIN_3 = (BSP_IO_PORT_JP00 | 0x3),                                                                ///< IO port JP00 pin 3
    BSP_IO_PORT_JP00_PIN_5 = (BSP_IO_PORT_JP00 | 0x5),                                                                ///< IO port JP00 pin 5

    BSP_IO_PORT_P40_PIN_0  = (BSP_IO_PORT_P40 | 0x0),                                                                 ///< IO port P40 pin 0
    BSP_IO_PORT_P40_PIN_1  = (BSP_IO_PORT_P40 | 0x1),                                                                 ///< IO port P40 pin 1
    BSP_IO_PORT_P40_PIN_2  = (BSP_IO_PORT_P40 | 0x2),                                                                 ///< IO port P40 pin 2
    BSP_IO_PORT_P40_PIN_3  = (BSP_IO_PORT_P40 | 0x3),                                                                 ///< IO port P40 pin 3
    BSP_IO_PORT_P40_PIN_8  = (BSP_IO_PORT_P40 | 0x8),                                                                 ///< IO port P40 pin 8
    BSP_IO_PORT_P40_PIN_9  = (BSP_IO_PORT_P40 | 0x9),                                                                 ///< IO port P40 pin 9
    BSP_IO_PORT_P40_PIN_10 = (BSP_IO_PORT_P40 | 0xA),                                                                 ///< IO port P40 pin 10
    BSP_IO_PORT_P40_PIN_11 = (BSP_IO_PORT_P40 | 0xB),                                                                 ///< IO port P40 pin 11
    BSP_IO_PORT_P40_PIN_12 = (BSP_IO_PORT_P40 | 0xC),                                                                 ///< IO port P40 pin 12
    BSP_IO_PORT_P40_PIN_13 = (BSP_IO_PORT_P40 | 0xD),                                                                 ///< IO port P40 pin 13
    BSP_IO_PORT_P40_PIN_14 = (BSP_IO_PORT_P40 | 0xE),                                                                 ///< IO port P40 pin 14
    BSP_IO_PORT_P40_PIN_15 = (BSP_IO_PORT_P40 | 0xF),                                                                 ///< IO port P40 pin 15
    BSP_IO_PORT_P40_PIN_4  = (BSP_IO_PORT_P40 | 0x4),                                                                 ///< IO port P40 pin 4
    BSP_IO_PORT_P40_PIN_5  = (BSP_IO_PORT_P40 | 0x5),                                                                 ///< IO port P40 pin 5
    BSP_IO_PORT_P40_PIN_6  = (BSP_IO_PORT_P40 | 0x6),                                                                 ///< IO port P40 pin 6
    BSP_IO_PORT_P40_PIN_7  = (BSP_IO_PORT_P40 | 0x7),                                                                 ///< IO port P40 pin 7

    BSP_IO_PORT_P37_PIN_0  = (BSP_IO_PORT_P37 | 0x0),                                                                 ///< IO port P37 pin 0
    BSP_IO_PORT_P37_PIN_1  = (BSP_IO_PORT_P37 | 0x1),                                                                 ///< IO port P37 pin 1
    BSP_IO_PORT_P37_PIN_2  = (BSP_IO_PORT_P37 | 0x2),                                                                 ///< IO port P37 pin 2
    BSP_IO_PORT_P37_PIN_3  = (BSP_IO_PORT_P37 | 0x3),                                                                 ///< IO port P37 pin 3
    BSP_IO_PORT_P37_PIN_4  = (BSP_IO_PORT_P37 | 0x4),                                                                 ///< IO port P37 pin 4
    BSP_IO_PORT_P37_PIN_5  = (BSP_IO_PORT_P37 | 0x5),                                                                 ///< IO port P37 pin 5
    BSP_IO_PORT_P37_PIN_6  = (BSP_IO_PORT_P37 | 0x6),                                                                 ///< IO port P37 pin 6
    BSP_IO_PORT_P37_PIN_7  = (BSP_IO_PORT_P37 | 0x7),                                                                 ///< IO port P37 pin 7
    BSP_IO_PORT_P37_PIN_8  = (BSP_IO_PORT_P37 | 0x8),                                                                 ///< IO port P37 pin 8
    BSP_IO_PORT_P37_PIN_9  = (BSP_IO_PORT_P37 | 0x9),                                                                 ///< IO port P37 pin 9
    BSP_IO_PORT_P37_PIN_10 = (BSP_IO_PORT_P37 | 0xA),                                                                 ///< IO port P37 pin 10
    BSP_IO_PORT_P37_PIN_11 = (BSP_IO_PORT_P37 | 0xB),                                                                 ///< IO port P37 pin 11
    BSP_IO_PORT_P37_PIN_12 = (BSP_IO_PORT_P37 | 0xC),                                                                 ///< IO port P37 pin 12
    BSP_IO_PORT_P37_PIN_13 = (BSP_IO_PORT_P37 | 0xD),                                                                 ///< IO port P37 pin 13
    BSP_IO_PORT_P37_PIN_14 = (BSP_IO_PORT_P37 | 0xE),                                                                 ///< IO port P37 pin 14
    BSP_IO_PORT_P37_PIN_15 = (BSP_IO_PORT_P37 | 0xF),                                                                 ///< IO port P37 pin 15

    BSP_IO_PORT_P38_PIN_0  = (BSP_IO_PORT_P38 | 0x0),                                                                 ///< IO port P38 pin 0
    BSP_IO_PORT_P38_PIN_1  = (BSP_IO_PORT_P38 | 0x1),                                                                 ///< IO port P38 pin 1
    BSP_IO_PORT_P38_PIN_2  = (BSP_IO_PORT_P38 | 0x2),                                                                 ///< IO port P38 pin 2
    BSP_IO_PORT_P38_PIN_3  = (BSP_IO_PORT_P38 | 0x3),                                                                 ///< IO port P38 pin 3
    BSP_IO_PORT_P38_PIN_4  = (BSP_IO_PORT_P38 | 0x4),                                                                 ///< IO port P38 pin 4
    BSP_IO_PORT_P38_PIN_5  = (BSP_IO_PORT_P38 | 0x5),                                                                 ///< IO port P38 pin 5
    BSP_IO_PORT_P38_PIN_6  = (BSP_IO_PORT_P38 | 0x6),                                                                 ///< IO port P38 pin 6
    BSP_IO_PORT_P38_PIN_7  = (BSP_IO_PORT_P38 | 0x7),                                                                 ///< IO port P38 pin 7
    BSP_IO_PORT_P38_PIN_8  = (BSP_IO_PORT_P38 | 0x8),                                                                 ///< IO port P38 pin 8
    BSP_IO_PORT_P38_PIN_9  = (BSP_IO_PORT_P38 | 0x9),                                                                 ///< IO port P38 pin 9
    BSP_IO_PORT_P38_PIN_10 = (BSP_IO_PORT_P38 | 0xA),                                                                 ///< IO port P38 pin 10
    BSP_IO_PORT_P38_PIN_11 = (BSP_IO_PORT_P38 | 0xB),                                                                 ///< IO port P38 pin 11
    BSP_IO_PORT_P38_PIN_12 = (BSP_IO_PORT_P38 | 0xC),                                                                 ///< IO port P38 pin 12
    BSP_IO_PORT_P38_PIN_13 = (BSP_IO_PORT_P38 | 0xD),                                                                 ///< IO port P38 pin 13
    BSP_IO_PORT_P38_PIN_14 = (BSP_IO_PORT_P38 | 0xE),                                                                 ///< IO port P38 pin 14
    BSP_IO_PORT_P38_PIN_15 = (BSP_IO_PORT_P38 | 0xF),                                                                 ///< IO port P38 pin 15

    BSP_IO_PORT_P39_PIN_0  = (BSP_IO_PORT_P39 | 0x0),                                                                 ///< IO port P39 pin 0
    BSP_IO_PORT_P39_PIN_1  = (BSP_IO_PORT_P39 | 0x1),                                                                 ///< IO port P39 pin 1
    BSP_IO_PORT_P39_PIN_2  = (BSP_IO_PORT_P39 | 0x2),                                                                 ///< IO port P39 pin 2
    BSP_IO_PORT_P39_PIN_3  = (BSP_IO_PORT_P39 | 0x3),                                                                 ///< IO port P39 pin 3
    BSP_IO_PORT_P39_PIN_4  = (BSP_IO_PORT_P39 | 0x4),                                                                 ///< IO port P39 pin 4
    BSP_IO_PORT_P39_PIN_5  = (BSP_IO_PORT_P39 | 0x5),                                                                 ///< IO port P39 pin 5
    BSP_IO_PORT_P39_PIN_6  = (BSP_IO_PORT_P39 | 0x6),                                                                 ///< IO port P39 pin 6
    BSP_IO_PORT_P39_PIN_7  = (BSP_IO_PORT_P39 | 0x7),                                                                 ///< IO port P39 pin 7
    BSP_IO_PORT_P39_PIN_8  = (BSP_IO_PORT_P39 | 0x8),                                                                 ///< IO port P39 pin 8
    BSP_IO_PORT_P39_PIN_9  = (BSP_IO_PORT_P39 | 0x9),                                                                 ///< IO port P39 pin 9
    BSP_IO_PORT_P39_PIN_10 = (BSP_IO_PORT_P39 | 0xA),                                                                 ///< IO port P39 pin 10
    BSP_IO_PORT_P39_PIN_11 = (BSP_IO_PORT_P39 | 0xB),                                                                 ///< IO port P39 pin 11
    BSP_IO_PORT_P39_PIN_12 = (BSP_IO_PORT_P39 | 0xC),                                                                 ///< IO port P39 pin 12
    BSP_IO_PORT_P39_PIN_13 = (BSP_IO_PORT_P39 | 0xD),                                                                 ///< IO port P39 pin 13
    BSP_IO_PORT_P39_PIN_14 = (BSP_IO_PORT_P39 | 0xE),                                                                 ///< IO port P39 pin 14
    BSP_IO_PORT_P39_PIN_15 = (BSP_IO_PORT_P39 | 0xF),                                                                 ///< IO port P39 pin 15

    BSP_IO_PORT_P41_PIN_0  = (BSP_IO_PORT_P41 | 0x0),                                                                 ///< IO port P41 pin 0
    BSP_IO_PORT_P41_PIN_1  = (BSP_IO_PORT_P41 | 0x1),                                                                 ///< IO port P41 pin 1
    BSP_IO_PORT_P41_PIN_2  = (BSP_IO_PORT_P41 | 0x2),                                                                 ///< IO port P41 pin 2
    BSP_IO_PORT_P41_PIN_3  = (BSP_IO_PORT_P41 | 0x3),                                                                 ///< IO port P41 pin 3
    BSP_IO_PORT_P41_PIN_4  = (BSP_IO_PORT_P41 | 0x4),                                                                 ///< IO port P41 pin 4
    BSP_IO_PORT_P41_PIN_5  = (BSP_IO_PORT_P41 | 0x5),                                                                 ///< IO port P41 pin 5
    BSP_IO_PORT_P41_PIN_6  = (BSP_IO_PORT_P41 | 0x6),                                                                 ///< IO port P41 pin 6
    BSP_IO_PORT_P41_PIN_7  = (BSP_IO_PORT_P41 | 0x7),                                                                 ///< IO port P41 pin 7
    BSP_IO_PORT_P41_PIN_8  = (BSP_IO_PORT_P41 | 0x8),                                                                 ///< IO port P41 pin 8
    BSP_IO_PORT_P41_PIN_9  = (BSP_IO_PORT_P41 | 0x9),                                                                 ///< IO port P41 pin 9
    BSP_IO_PORT_P41_PIN_10 = (BSP_IO_PORT_P41 | 0xA),                                                                 ///< IO port P41 pin 10
    BSP_IO_PORT_P41_PIN_11 = (BSP_IO_PORT_P41 | 0xB),                                                                 ///< IO port P41 pin 11
    BSP_IO_PORT_P41_PIN_12 = (BSP_IO_PORT_P41 | 0xC),                                                                 ///< IO port P41 pin 12
    BSP_IO_PORT_P41_PIN_13 = (BSP_IO_PORT_P41 | 0xD),                                                                 ///< IO port P41 pin 13
    BSP_IO_PORT_P41_PIN_14 = (BSP_IO_PORT_P41 | 0xE),                                                                 ///< IO port P41 pin 14
    BSP_IO_PORT_P41_PIN_15 = (BSP_IO_PORT_P41 | 0xF),                                                                 ///< IO port P41 pin 15

    BSP_IO_PORT_P42_PIN_0  = (BSP_IO_PORT_P42 | 0x0),                                                                 ///< IO port P42 pin 0
    BSP_IO_PORT_P42_PIN_1  = (BSP_IO_PORT_P42 | 0x1),                                                                 ///< IO port P42 pin 1
    BSP_IO_PORT_P42_PIN_2  = (BSP_IO_PORT_P42 | 0x2),                                                                 ///< IO port P42 pin 2
    BSP_IO_PORT_P42_PIN_3  = (BSP_IO_PORT_P42 | 0x3),                                                                 ///< IO port P42 pin 3
    BSP_IO_PORT_P42_PIN_4  = (BSP_IO_PORT_P42 | 0x4),                                                                 ///< IO port P42 pin 4
    BSP_IO_PORT_P42_PIN_5  = (BSP_IO_PORT_P42 | 0x5),                                                                 ///< IO port P42 pin 5
    BSP_IO_PORT_P42_PIN_6  = (BSP_IO_PORT_P42 | 0x6),                                                                 ///< IO port P42 pin 6
    BSP_IO_PORT_P42_PIN_7  = (BSP_IO_PORT_P42 | 0x7),                                                                 ///< IO port P42 pin 7
    BSP_IO_PORT_P42_PIN_8  = (BSP_IO_PORT_P42 | 0x8),                                                                 ///< IO port P42 pin 8
    BSP_IO_PORT_P42_PIN_9  = (BSP_IO_PORT_P42 | 0x9),                                                                 ///< IO port P42 pin 9
    BSP_IO_PORT_P42_PIN_10 = (BSP_IO_PORT_P42 | 0xA),                                                                 ///< IO port P42 pin 10
    BSP_IO_PORT_P42_PIN_11 = (BSP_IO_PORT_P42 | 0xB),                                                                 ///< IO port P42 pin 11
    BSP_IO_PORT_P42_PIN_12 = (BSP_IO_PORT_P42 | 0xC),                                                                 ///< IO port P42 pin 12
    BSP_IO_PORT_P42_PIN_13 = (BSP_IO_PORT_P42 | 0xD),                                                                 ///< IO port P42 pin 13
    BSP_IO_PORT_P42_PIN_14 = (BSP_IO_PORT_P42 | 0xE),                                                                 ///< IO port P42 pin 14
    BSP_IO_PORT_P42_PIN_15 = (BSP_IO_PORT_P42 | 0xF),                                                                 ///< IO port P42 pin 15

    BSP_IO_PORT_P43_PIN_0  = (BSP_IO_PORT_P43 | 0x0),                                                                 ///< IO port P43 pin 0
    BSP_IO_PORT_P43_PIN_1  = (BSP_IO_PORT_P43 | 0x1),                                                                 ///< IO port P43 pin 1
    BSP_IO_PORT_P43_PIN_2  = (BSP_IO_PORT_P43 | 0x2),                                                                 ///< IO port P43 pin 2
    BSP_IO_PORT_P43_PIN_3  = (BSP_IO_PORT_P43 | 0x3),                                                                 ///< IO port P43 pin 3
    BSP_IO_PORT_P43_PIN_4  = (BSP_IO_PORT_P43 | 0x4),                                                                 ///< IO port P43 pin 4
    BSP_IO_PORT_P43_PIN_5  = (BSP_IO_PORT_P43 | 0x5),                                                                 ///< IO port P43 pin 5
    BSP_IO_PORT_P43_PIN_6  = (BSP_IO_PORT_P43 | 0x6),                                                                 ///< IO port P43 pin 6
    BSP_IO_PORT_P43_PIN_7  = (BSP_IO_PORT_P43 | 0x7),                                                                 ///< IO port P43 pin 7
    BSP_IO_PORT_P43_PIN_8  = (BSP_IO_PORT_P43 | 0x8),                                                                 ///< IO port P43 pin 8
    BSP_IO_PORT_P43_PIN_9  = (BSP_IO_PORT_P43 | 0x9),                                                                 ///< IO port P43 pin 9
    BSP_IO_PORT_P43_PIN_10 = (BSP_IO_PORT_P43 | 0xA),                                                                 ///< IO port P43 pin 10
    BSP_IO_PORT_P43_PIN_11 = (BSP_IO_PORT_P43 | 0xB),                                                                 ///< IO port P43 pin 11
    BSP_IO_PORT_P43_PIN_12 = (BSP_IO_PORT_P43 | 0xC),                                                                 ///< IO port P43 pin 12
    BSP_IO_PORT_P43_PIN_13 = (BSP_IO_PORT_P43 | 0xD),                                                                 ///< IO port P43 pin 13
    BSP_IO_PORT_P43_PIN_14 = (BSP_IO_PORT_P43 | 0xE),                                                                 ///< IO port P43 pin 14
    BSP_IO_PORT_P43_PIN_15 = (BSP_IO_PORT_P43 | 0xF),                                                                 ///< IO port P43 pin 15

    BSP_IO_PORT_P44_PIN_0  = (BSP_IO_PORT_P44 | 0x0),                                                                 ///< IO port P44 pin 0
    BSP_IO_PORT_P44_PIN_1  = (BSP_IO_PORT_P44 | 0x1),                                                                 ///< IO port P44 pin 1
    BSP_IO_PORT_P44_PIN_2  = (BSP_IO_PORT_P44 | 0x2),                                                                 ///< IO port P44 pin 2
    BSP_IO_PORT_P44_PIN_3  = (BSP_IO_PORT_P44 | 0x3),                                                                 ///< IO port P44 pin 3
    BSP_IO_PORT_P44_PIN_4  = (BSP_IO_PORT_P44 | 0x4),                                                                 ///< IO port P44 pin 4
    BSP_IO_PORT_P44_PIN_5  = (BSP_IO_PORT_P44 | 0x5),                                                                 ///< IO port P44 pin 5
    BSP_IO_PORT_P44_PIN_6  = (BSP_IO_PORT_P44 | 0x6),                                                                 ///< IO port P44 pin 6
    BSP_IO_PORT_P44_PIN_7  = (BSP_IO_PORT_P44 | 0x7),                                                                 ///< IO port P44 pin 7
    BSP_IO_PORT_P44_PIN_8  = (BSP_IO_PORT_P44 | 0x8),                                                                 ///< IO port P44 pin 8
    BSP_IO_PORT_P44_PIN_9  = (BSP_IO_PORT_P44 | 0x9),                                                                 ///< IO port P44 pin 9
    BSP_IO_PORT_P44_PIN_10 = (BSP_IO_PORT_P44 | 0xA),                                                                 ///< IO port P44 pin 10
    BSP_IO_PORT_P44_PIN_11 = (BSP_IO_PORT_P44 | 0xB),                                                                 ///< IO port P44 pin 11
    BSP_IO_PORT_P44_PIN_12 = (BSP_IO_PORT_P44 | 0xC),                                                                 ///< IO port P44 pin 12
    BSP_IO_PORT_P44_PIN_13 = (BSP_IO_PORT_P44 | 0xD),                                                                 ///< IO port P44 pin 13
    BSP_IO_PORT_P44_PIN_14 = (BSP_IO_PORT_P44 | 0xE),                                                                 ///< IO port P44 pin 14
    BSP_IO_PORT_P44_PIN_15 = (BSP_IO_PORT_P44 | 0xF),                                                                 ///< IO port P44 pin 15

    BSP_IO_PORT_P45_PIN_0  = (BSP_IO_PORT_P45 | 0x0),                                                                 ///< IO port P45 pin 0
    BSP_IO_PORT_P45_PIN_1  = (BSP_IO_PORT_P45 | 0x1),                                                                 ///< IO port P45 pin 1
    BSP_IO_PORT_P45_PIN_2  = (BSP_IO_PORT_P45 | 0x2),                                                                 ///< IO port P45 pin 2
    BSP_IO_PORT_P45_PIN_3  = (BSP_IO_PORT_P45 | 0x3),                                                                 ///< IO port P45 pin 3
    BSP_IO_PORT_P45_PIN_4  = (BSP_IO_PORT_P45 | 0x4),                                                                 ///< IO port P45 pin 4
    BSP_IO_PORT_P45_PIN_5  = (BSP_IO_PORT_P45 | 0x5),                                                                 ///< IO port P45 pin 5
    BSP_IO_PORT_P45_PIN_6  = (BSP_IO_PORT_P45 | 0x6),                                                                 ///< IO port P45 pin 6
    BSP_IO_PORT_P45_PIN_7  = (BSP_IO_PORT_P45 | 0x7),                                                                 ///< IO port P45 pin 7
    BSP_IO_PORT_P45_PIN_8  = (BSP_IO_PORT_P45 | 0x8),                                                                 ///< IO port P45 pin 8
    BSP_IO_PORT_P45_PIN_9  = (BSP_IO_PORT_P45 | 0x9),                                                                 ///< IO port P45 pin 9
    BSP_IO_PORT_P45_PIN_10 = (BSP_IO_PORT_P45 | 0xA),                                                                 ///< IO port P45 pin 10
    BSP_IO_PORT_P45_PIN_11 = (BSP_IO_PORT_P45 | 0xB),                                                                 ///< IO port P45 pin 11
    BSP_IO_PORT_P45_PIN_12 = (BSP_IO_PORT_P45 | 0xC),                                                                 ///< IO port P45 pin 12
    BSP_IO_PORT_P45_PIN_13 = (BSP_IO_PORT_P45 | 0xD),                                                                 ///< IO port P45 pin 13
    BSP_IO_PORT_P45_PIN_14 = (BSP_IO_PORT_P45 | 0xE),                                                                 ///< IO port P45 pin 14
    BSP_IO_PORT_P45_PIN_15 = (BSP_IO_PORT_P45 | 0xF),                                                                 ///< IO port P45 pin 15

    BSP_IO_PORT_P46_PIN_0  = (BSP_IO_PORT_P46 | 0x0),                                                                 ///< IO port P46 pin 0
    BSP_IO_PORT_P46_PIN_1  = (BSP_IO_PORT_P46 | 0x1),                                                                 ///< IO port P46 pin 1
    BSP_IO_PORT_P46_PIN_2  = (BSP_IO_PORT_P46 | 0x2),                                                                 ///< IO port P46 pin 2
    BSP_IO_PORT_P46_PIN_3  = (BSP_IO_PORT_P46 | 0x3),                                                                 ///< IO port P46 pin 3
    BSP_IO_PORT_P46_PIN_4  = (BSP_IO_PORT_P46 | 0x4),                                                                 ///< IO port P46 pin 4
    BSP_IO_PORT_P46_PIN_5  = (BSP_IO_PORT_P46 | 0x5),                                                                 ///< IO port P46 pin 5
    BSP_IO_PORT_P46_PIN_6  = (BSP_IO_PORT_P46 | 0x6),                                                                 ///< IO port P46 pin 6
    BSP_IO_PORT_P46_PIN_7  = (BSP_IO_PORT_P46 | 0x7),                                                                 ///< IO port P46 pin 7
    BSP_IO_PORT_P46_PIN_8  = (BSP_IO_PORT_P46 | 0x8),                                                                 ///< IO port P46 pin 8
    BSP_IO_PORT_P46_PIN_9  = (BSP_IO_PORT_P46 | 0x9),                                                                 ///< IO port P46 pin 9
    BSP_IO_PORT_P46_PIN_10 = (BSP_IO_PORT_P46 | 0xA),                                                                 ///< IO port P46 pin 10
    BSP_IO_PORT_P46_PIN_11 = (BSP_IO_PORT_P46 | 0xB),                                                                 ///< IO port P46 pin 11
    BSP_IO_PORT_P46_PIN_12 = (BSP_IO_PORT_P46 | 0xC),                                                                 ///< IO port P46 pin 12
    BSP_IO_PORT_P46_PIN_13 = (BSP_IO_PORT_P46 | 0xD),                                                                 ///< IO port P46 pin 13
    BSP_IO_PORT_P46_PIN_14 = (BSP_IO_PORT_P46 | 0xE),                                                                 ///< IO port P46 pin 14
    BSP_IO_PORT_P46_PIN_15 = (BSP_IO_PORT_P46 | 0xF),                                                                 ///< IO port P46 pin 15

    BSP_IO_PORT_P47_PIN_0  = (BSP_IO_PORT_P47 | 0x0),                                                                 ///< IO port P47 pin 0
    BSP_IO_PORT_P47_PIN_1  = (BSP_IO_PORT_P47 | 0x1),                                                                 ///< IO port P47 pin 1
    BSP_IO_PORT_P47_PIN_2  = (BSP_IO_PORT_P47 | 0x2),                                                                 ///< IO port P47 pin 2
    BSP_IO_PORT_P47_PIN_3  = (BSP_IO_PORT_P47 | 0x3),                                                                 ///< IO port P47 pin 3
    BSP_IO_PORT_P47_PIN_4  = (BSP_IO_PORT_P47 | 0x4),                                                                 ///< IO port P47 pin 4
    BSP_IO_PORT_P47_PIN_5  = (BSP_IO_PORT_P47 | 0x5),                                                                 ///< IO port P47 pin 5
    BSP_IO_PORT_P47_PIN_6  = (BSP_IO_PORT_P47 | 0x6),                                                                 ///< IO port P47 pin 6
    BSP_IO_PORT_P47_PIN_7  = (BSP_IO_PORT_P47 | 0x7),                                                                 ///< IO port P47 pin 7
    BSP_IO_PORT_P47_PIN_8  = (BSP_IO_PORT_P47 | 0x8),                                                                 ///< IO port P47 pin 8
    BSP_IO_PORT_P47_PIN_9  = (BSP_IO_PORT_P47 | 0x9),                                                                 ///< IO port P47 pin 9
    BSP_IO_PORT_P47_PIN_10 = (BSP_IO_PORT_P47 | 0xA),                                                                 ///< IO port P47 pin 10
    BSP_IO_PORT_P47_PIN_11 = (BSP_IO_PORT_P47 | 0xB),                                                                 ///< IO port P47 pin 11
    BSP_IO_PORT_P47_PIN_12 = (BSP_IO_PORT_P47 | 0xC),                                                                 ///< IO port P47 pin 12
    BSP_IO_PORT_P47_PIN_13 = (BSP_IO_PORT_P47 | 0xD),                                                                 ///< IO port P47 pin 13
    BSP_IO_PORT_P47_PIN_14 = (BSP_IO_PORT_P47 | 0xE),                                                                 ///< IO port P47 pin 14
    BSP_IO_PORT_P47_PIN_15 = (BSP_IO_PORT_P47 | 0xF),                                                                 ///< IO port P47 pin 15

    BSP_IO_PORT_P48_PIN_0  = (BSP_IO_PORT_P48 | 0x0),                                                                 ///< IO port P48 pin 0
    BSP_IO_PORT_P48_PIN_1  = (BSP_IO_PORT_P48 | 0x1),                                                                 ///< IO port P48 pin 1
    BSP_IO_PORT_P48_PIN_2  = (BSP_IO_PORT_P48 | 0x2),                                                                 ///< IO port P48 pin 2
    BSP_IO_PORT_P48_PIN_3  = (BSP_IO_PORT_P48 | 0x3),                                                                 ///< IO port P48 pin 3
    BSP_IO_PORT_P48_PIN_4  = (BSP_IO_PORT_P48 | 0x4),                                                                 ///< IO port P48 pin 4
    BSP_IO_PORT_P48_PIN_5  = (BSP_IO_PORT_P48 | 0x5),                                                                 ///< IO port P48 pin 5
    BSP_IO_PORT_P48_PIN_6  = (BSP_IO_PORT_P48 | 0x6),                                                                 ///< IO port P48 pin 6
    BSP_IO_PORT_P48_PIN_7  = (BSP_IO_PORT_P48 | 0x7),                                                                 ///< IO port P48 pin 7
    BSP_IO_PORT_P48_PIN_8  = (BSP_IO_PORT_P48 | 0x8),                                                                 ///< IO port P48 pin 8
    BSP_IO_PORT_P48_PIN_9  = (BSP_IO_PORT_P48 | 0x9),                                                                 ///< IO port P48 pin 9
    BSP_IO_PORT_P48_PIN_10 = (BSP_IO_PORT_P48 | 0xA),                                                                 ///< IO port P48 pin 10
    BSP_IO_PORT_P48_PIN_11 = (BSP_IO_PORT_P48 | 0xB),                                                                 ///< IO port P48 pin 11
    BSP_IO_PORT_P48_PIN_12 = (BSP_IO_PORT_P48 | 0xC),                                                                 ///< IO port P48 pin 12
    BSP_IO_PORT_P48_PIN_13 = (BSP_IO_PORT_P48 | 0xD),                                                                 ///< IO port P48 pin 13
    BSP_IO_PORT_P48_PIN_14 = (BSP_IO_PORT_P48 | 0xE),                                                                 ///< IO port P48 pin 14
    BSP_IO_PORT_P48_PIN_15 = (BSP_IO_PORT_P48 | 0xF),                                                                 ///< IO port P48 pin 15

    BSP_IO_PORT_P49_PIN_0  = (BSP_IO_PORT_P49 | 0x0),                                                                 ///< IO port P49 pin 0
    BSP_IO_PORT_P49_PIN_1  = (BSP_IO_PORT_P49 | 0x1),                                                                 ///< IO port P49 pin 1
    BSP_IO_PORT_P49_PIN_2  = (BSP_IO_PORT_P49 | 0x2),                                                                 ///< IO port P49 pin 2
    BSP_IO_PORT_P49_PIN_3  = (BSP_IO_PORT_P49 | 0x3),                                                                 ///< IO port P49 pin 3
    BSP_IO_PORT_P49_PIN_4  = (BSP_IO_PORT_P49 | 0x4),                                                                 ///< IO port P49 pin 4
    BSP_IO_PORT_P49_PIN_5  = (BSP_IO_PORT_P49 | 0x5),                                                                 ///< IO port P49 pin 5
    BSP_IO_PORT_P49_PIN_6  = (BSP_IO_PORT_P49 | 0x6),                                                                 ///< IO port P49 pin 6
    BSP_IO_PORT_P49_PIN_7  = (BSP_IO_PORT_P49 | 0x7),                                                                 ///< IO port P49 pin 7
    BSP_IO_PORT_P49_PIN_8  = (BSP_IO_PORT_P49 | 0x8),                                                                 ///< IO port P49 pin 8
    BSP_IO_PORT_P49_PIN_9  = (BSP_IO_PORT_P49 | 0x9),                                                                 ///< IO port P49 pin 9
    BSP_IO_PORT_P49_PIN_10 = (BSP_IO_PORT_P49 | 0xA),                                                                 ///< IO port P49 pin 10
    BSP_IO_PORT_P49_PIN_11 = (BSP_IO_PORT_P49 | 0xB),                                                                 ///< IO port P49 pin 11
    BSP_IO_PORT_P49_PIN_12 = (BSP_IO_PORT_P49 | 0xC),                                                                 ///< IO port P49 pin 12
    BSP_IO_PORT_P49_PIN_13 = (BSP_IO_PORT_P49 | 0xD),                                                                 ///< IO port P49 pin 13
    BSP_IO_PORT_P49_PIN_14 = (BSP_IO_PORT_P49 | 0xE),                                                                 ///< IO port P49 pin 14
    BSP_IO_PORT_P49_PIN_15 = (BSP_IO_PORT_P49 | 0xF),                                                                 ///< IO port P49 pin 15

    BSP_IO_PORT_P50_PIN_0  = (BSP_IO_PORT_P50 | 0x0),                                                                 ///< IO port P50 pin 0
    BSP_IO_PORT_P50_PIN_1  = (BSP_IO_PORT_P50 | 0x1),                                                                 ///< IO port P50 pin 1
    BSP_IO_PORT_P50_PIN_2  = (BSP_IO_PORT_P50 | 0x2),                                                                 ///< IO port P50 pin 2
    BSP_IO_PORT_P50_PIN_3  = (BSP_IO_PORT_P50 | 0x3),                                                                 ///< IO port P50 pin 3
    BSP_IO_PORT_P50_PIN_4  = (BSP_IO_PORT_P50 | 0x4),                                                                 ///< IO port P50 pin 4
    BSP_IO_PORT_P50_PIN_5  = (BSP_IO_PORT_P50 | 0x5),                                                                 ///< IO port P50 pin 5
    BSP_IO_PORT_P50_PIN_6  = (BSP_IO_PORT_P50 | 0x6),                                                                 ///< IO port P50 pin 6
    BSP_IO_PORT_P50_PIN_7  = (BSP_IO_PORT_P50 | 0x7),                                                                 ///< IO port P50 pin 7
    BSP_IO_PORT_P50_PIN_8  = (BSP_IO_PORT_P50 | 0x8),                                                                 ///< IO port P50 pin 8
    BSP_IO_PORT_P50_PIN_9  = (BSP_IO_PORT_P50 | 0x9),                                                                 ///< IO port P50 pin 9
    BSP_IO_PORT_P50_PIN_10 = (BSP_IO_PORT_P50 | 0xA),                                                                 ///< IO port P50 pin 10
    BSP_IO_PORT_P50_PIN_11 = (BSP_IO_PORT_P50 | 0xB),                                                                 ///< IO port P50 pin 11
    BSP_IO_PORT_P50_PIN_12 = (BSP_IO_PORT_P50 | 0xC),                                                                 ///< IO port P50 pin 12
    BSP_IO_PORT_P50_PIN_13 = (BSP_IO_PORT_P50 | 0xD),                                                                 ///< IO port P50 pin 13
    BSP_IO_PORT_P50_PIN_14 = (BSP_IO_PORT_P50 | 0xE),                                                                 ///< IO port P50 pin 14
    BSP_IO_PORT_P50_PIN_15 = (BSP_IO_PORT_P50 | 0xF),                                                                 ///< IO port P50 pin 15

    BSP_IO_PORT_P51_PIN_0  = (BSP_IO_PORT_P51 | 0x0),                                                                 ///< IO port P51 pin 0
    BSP_IO_PORT_P51_PIN_1  = (BSP_IO_PORT_P51 | 0x1),                                                                 ///< IO port P51 pin 1
    BSP_IO_PORT_P51_PIN_2  = (BSP_IO_PORT_P51 | 0x2),                                                                 ///< IO port P51 pin 2
    BSP_IO_PORT_P51_PIN_3  = (BSP_IO_PORT_P51 | 0x3),                                                                 ///< IO port P51 pin 3
    BSP_IO_PORT_P51_PIN_4  = (BSP_IO_PORT_P51 | 0x4),                                                                 ///< IO port P51 pin 4
    BSP_IO_PORT_P51_PIN_5  = (BSP_IO_PORT_P51 | 0x5),                                                                 ///< IO port P51 pin 5
    BSP_IO_PORT_P51_PIN_6  = (BSP_IO_PORT_P51 | 0x6),                                                                 ///< IO port P51 pin 6
    BSP_IO_PORT_P51_PIN_7  = (BSP_IO_PORT_P51 | 0x7),                                                                 ///< IO port P51 pin 7
    BSP_IO_PORT_P51_PIN_8  = (BSP_IO_PORT_P51 | 0x8),                                                                 ///< IO port P51 pin 8
    BSP_IO_PORT_P51_PIN_9  = (BSP_IO_PORT_P51 | 0x9),                                                                 ///< IO port P51 pin 9
    BSP_IO_PORT_P51_PIN_10 = (BSP_IO_PORT_P51 | 0xA),                                                                 ///< IO port P51 pin 10
    BSP_IO_PORT_P51_PIN_11 = (BSP_IO_PORT_P51 | 0xB),                                                                 ///< IO port P51 pin 11
    BSP_IO_PORT_P51_PIN_12 = (BSP_IO_PORT_P51 | 0xC),                                                                 ///< IO port P51 pin 12
    BSP_IO_PORT_P51_PIN_13 = (BSP_IO_PORT_P51 | 0xD),                                                                 ///< IO port P51 pin 13
    BSP_IO_PORT_P51_PIN_14 = (BSP_IO_PORT_P51 | 0xE),                                                                 ///< IO port P51 pin 14
    BSP_IO_PORT_P51_PIN_15 = (BSP_IO_PORT_P51 | 0xF),                                                                 ///< IO port P51 pin 15

    BSP_IO_PORT_P52_PIN_0  = (BSP_IO_PORT_P52 | 0x0),                                                                 ///< IO port P52 pin 0
    BSP_IO_PORT_P52_PIN_1  = (BSP_IO_PORT_P52 | 0x1),                                                                 ///< IO port P52 pin 1
    BSP_IO_PORT_P52_PIN_2  = (BSP_IO_PORT_P52 | 0x2),                                                                 ///< IO port P52 pin 2
    BSP_IO_PORT_P52_PIN_3  = (BSP_IO_PORT_P52 | 0x3),                                                                 ///< IO port P52 pin 3
    BSP_IO_PORT_P52_PIN_4  = (BSP_IO_PORT_P52 | 0x4),                                                                 ///< IO port P52 pin 4
    BSP_IO_PORT_P52_PIN_5  = (BSP_IO_PORT_P52 | 0x5),                                                                 ///< IO port P52 pin 5
    BSP_IO_PORT_P52_PIN_6  = (BSP_IO_PORT_P52 | 0x6),                                                                 ///< IO port P52 pin 6
    BSP_IO_PORT_P52_PIN_7  = (BSP_IO_PORT_P52 | 0x7),                                                                 ///< IO port P52 pin 7
    BSP_IO_PORT_P52_PIN_8  = (BSP_IO_PORT_P52 | 0x8),                                                                 ///< IO port P52 pin 8
    BSP_IO_PORT_P52_PIN_9  = (BSP_IO_PORT_P52 | 0x9),                                                                 ///< IO port P52 pin 9
    BSP_IO_PORT_P52_PIN_10 = (BSP_IO_PORT_P52 | 0xA),                                                                 ///< IO port P52 pin 10
    BSP_IO_PORT_P52_PIN_11 = (BSP_IO_PORT_P52 | 0xB),                                                                 ///< IO port P52 pin 11
    BSP_IO_PORT_P52_PIN_12 = (BSP_IO_PORT_P52 | 0xC),                                                                 ///< IO port P52 pin 12
    BSP_IO_PORT_P52_PIN_13 = (BSP_IO_PORT_P52 | 0xD),                                                                 ///< IO port P52 pin 13
    BSP_IO_PORT_P52_PIN_14 = (BSP_IO_PORT_P52 | 0xE),                                                                 ///< IO port P52 pin 14
    BSP_IO_PORT_P52_PIN_15 = (BSP_IO_PORT_P52 | 0xF),                                                                 ///< IO port P52 pin 15

    BSP_IO_PORT_P53_PIN_0  = (BSP_IO_PORT_P53 | 0x0),                                                                 ///< IO port P53 pin 0
    BSP_IO_PORT_P53_PIN_1  = (BSP_IO_PORT_P53 | 0x1),                                                                 ///< IO port P53 pin 1
    BSP_IO_PORT_P53_PIN_2  = (BSP_IO_PORT_P53 | 0x2),                                                                 ///< IO port P53 pin 2
    BSP_IO_PORT_P53_PIN_3  = (BSP_IO_PORT_P53 | 0x3),                                                                 ///< IO port P53 pin 3
    BSP_IO_PORT_P53_PIN_4  = (BSP_IO_PORT_P53 | 0x4),                                                                 ///< IO port P53 pin 4
    BSP_IO_PORT_P53_PIN_5  = (BSP_IO_PORT_P53 | 0x5),                                                                 ///< IO port P53 pin 5
    BSP_IO_PORT_P53_PIN_6  = (BSP_IO_PORT_P53 | 0x6),                                                                 ///< IO port P53 pin 6
    BSP_IO_PORT_P53_PIN_7  = (BSP_IO_PORT_P53 | 0x7),                                                                 ///< IO port P53 pin 7
    BSP_IO_PORT_P53_PIN_8  = (BSP_IO_PORT_P53 | 0x8),                                                                 ///< IO port P53 pin 8
    BSP_IO_PORT_P53_PIN_9  = (BSP_IO_PORT_P53 | 0x9),                                                                 ///< IO port P53 pin 9
    BSP_IO_PORT_P53_PIN_10 = (BSP_IO_PORT_P53 | 0xA),                                                                 ///< IO port P53 pin 10
    BSP_IO_PORT_P53_PIN_11 = (BSP_IO_PORT_P53 | 0xB),                                                                 ///< IO port P53 pin 11
    BSP_IO_PORT_P53_PIN_12 = (BSP_IO_PORT_P53 | 0xC),                                                                 ///< IO port P53 pin 12
    BSP_IO_PORT_P53_PIN_13 = (BSP_IO_PORT_P53 | 0xD),                                                                 ///< IO port P53 pin 13
    BSP_IO_PORT_P53_PIN_14 = (BSP_IO_PORT_P53 | 0xE),                                                                 ///< IO port P53 pin 14
    BSP_IO_PORT_P53_PIN_15 = (BSP_IO_PORT_P53 | 0xF),                                                                 ///< IO port P53 pin 15

    BSP_IO_PORT_P54_PIN_0  = (BSP_IO_PORT_P54 | 0x0),                                                                 ///< IO port P54 pin 0
    BSP_IO_PORT_P54_PIN_1  = (BSP_IO_PORT_P54 | 0x1),                                                                 ///< IO port P54 pin 1
    BSP_IO_PORT_P54_PIN_2  = (BSP_IO_PORT_P54 | 0x2),                                                                 ///< IO port P54 pin 2
    BSP_IO_PORT_P54_PIN_3  = (BSP_IO_PORT_P54 | 0x3),                                                                 ///< IO port P54 pin 3
    BSP_IO_PORT_P54_PIN_4  = (BSP_IO_PORT_P54 | 0x4),                                                                 ///< IO port P54 pin 4
    BSP_IO_PORT_P54_PIN_5  = (BSP_IO_PORT_P54 | 0x5),                                                                 ///< IO port P54 pin 5
    BSP_IO_PORT_P54_PIN_6  = (BSP_IO_PORT_P54 | 0x6),                                                                 ///< IO port P54 pin 6
    BSP_IO_PORT_P54_PIN_7  = (BSP_IO_PORT_P54 | 0x7),                                                                 ///< IO port P54 pin 7
    BSP_IO_PORT_P54_PIN_8  = (BSP_IO_PORT_P54 | 0x8),                                                                 ///< IO port P54 pin 8
    BSP_IO_PORT_P54_PIN_9  = (BSP_IO_PORT_P54 | 0x9),                                                                 ///< IO port P54 pin 9
    BSP_IO_PORT_P54_PIN_10 = (BSP_IO_PORT_P54 | 0xA),                                                                 ///< IO port P54 pin 10
    BSP_IO_PORT_P54_PIN_11 = (BSP_IO_PORT_P54 | 0xB),                                                                 ///< IO port P54 pin 11
    BSP_IO_PORT_P54_PIN_12 = (BSP_IO_PORT_P54 | 0xC),                                                                 ///< IO port P54 pin 12
    BSP_IO_PORT_P54_PIN_13 = (BSP_IO_PORT_P54 | 0xD),                                                                 ///< IO port P54 pin 13
    BSP_IO_PORT_P54_PIN_14 = (BSP_IO_PORT_P54 | 0xE),                                                                 ///< IO port P54 pin 14
    BSP_IO_PORT_P54_PIN_15 = (BSP_IO_PORT_P54 | 0xF),                                                                 ///< IO port P54 pin 15

    BSP_IO_PORT_P55_PIN_0  = (BSP_IO_PORT_P55 | 0x0),                                                                 ///< IO port P55 pin 0
    BSP_IO_PORT_P55_PIN_1  = (BSP_IO_PORT_P55 | 0x1),                                                                 ///< IO port P55 pin 1
    BSP_IO_PORT_P55_PIN_2  = (BSP_IO_PORT_P55 | 0x2),                                                                 ///< IO port P55 pin 2
    BSP_IO_PORT_P55_PIN_3  = (BSP_IO_PORT_P55 | 0x3),                                                                 ///< IO port P55 pin 3
    BSP_IO_PORT_P55_PIN_4  = (BSP_IO_PORT_P55 | 0x4),                                                                 ///< IO port P55 pin 4
    BSP_IO_PORT_P55_PIN_5  = (BSP_IO_PORT_P55 | 0x5),                                                                 ///< IO port P55 pin 5
    BSP_IO_PORT_P55_PIN_6  = (BSP_IO_PORT_P55 | 0x6),                                                                 ///< IO port P55 pin 6
    BSP_IO_PORT_P55_PIN_7  = (BSP_IO_PORT_P55 | 0x7),                                                                 ///< IO port P55 pin 7
    BSP_IO_PORT_P55_PIN_8  = (BSP_IO_PORT_P55 | 0x8),                                                                 ///< IO port P55 pin 8
    BSP_IO_PORT_P55_PIN_9  = (BSP_IO_PORT_P55 | 0x9),                                                                 ///< IO port P55 pin 9
    BSP_IO_PORT_P55_PIN_10 = (BSP_IO_PORT_P55 | 0xA),                                                                 ///< IO port P55 pin 10
    BSP_IO_PORT_P55_PIN_11 = (BSP_IO_PORT_P55 | 0xB),                                                                 ///< IO port P55 pin 11
    BSP_IO_PORT_P55_PIN_12 = (BSP_IO_PORT_P55 | 0xC),                                                                 ///< IO port P55 pin 12
    BSP_IO_PORT_P55_PIN_13 = (BSP_IO_PORT_P55 | 0xD),                                                                 ///< IO port P55 pin 13
    BSP_IO_PORT_P55_PIN_14 = (BSP_IO_PORT_P55 | 0xE),                                                                 ///< IO port P55 pin 14
    BSP_IO_PORT_P55_PIN_15 = (BSP_IO_PORT_P55 | 0xF),                                                                 ///< IO port P55 pin 15

    BSP_IO_PORT_P56_PIN_0  = (BSP_IO_PORT_P56 | 0x0),                                                                 ///< IO port P56 pin 0
    BSP_IO_PORT_P56_PIN_1  = (BSP_IO_PORT_P56 | 0x1),                                                                 ///< IO port P56 pin 1
    BSP_IO_PORT_P56_PIN_2  = (BSP_IO_PORT_P56 | 0x2),                                                                 ///< IO port P56 pin 2
    BSP_IO_PORT_P56_PIN_3  = (BSP_IO_PORT_P56 | 0x3),                                                                 ///< IO port P56 pin 3
    BSP_IO_PORT_P56_PIN_4  = (BSP_IO_PORT_P56 | 0x4),                                                                 ///< IO port P56 pin 4
    BSP_IO_PORT_P56_PIN_5  = (BSP_IO_PORT_P56 | 0x5),                                                                 ///< IO port P56 pin 5
    BSP_IO_PORT_P56_PIN_6  = (BSP_IO_PORT_P56 | 0x6),                                                                 ///< IO port P56 pin 6
    BSP_IO_PORT_P56_PIN_7  = (BSP_IO_PORT_P56 | 0x7),                                                                 ///< IO port P56 pin 7
    BSP_IO_PORT_P56_PIN_8  = (BSP_IO_PORT_P56 | 0x8),                                                                 ///< IO port P56 pin 8
    BSP_IO_PORT_P56_PIN_9  = (BSP_IO_PORT_P56 | 0x9),                                                                 ///< IO port P56 pin 9
    BSP_IO_PORT_P56_PIN_10 = (BSP_IO_PORT_P56 | 0xA),                                                                 ///< IO port P56 pin 10
    BSP_IO_PORT_P56_PIN_11 = (BSP_IO_PORT_P56 | 0xB),                                                                 ///< IO port P56 pin 11
    BSP_IO_PORT_P56_PIN_12 = (BSP_IO_PORT_P56 | 0xC),                                                                 ///< IO port P56 pin 12
    BSP_IO_PORT_P56_PIN_13 = (BSP_IO_PORT_P56 | 0xD),                                                                 ///< IO port P56 pin 13
    BSP_IO_PORT_P56_PIN_14 = (BSP_IO_PORT_P56 | 0xE),                                                                 ///< IO port P56 pin 14
    BSP_IO_PORT_P56_PIN_15 = (BSP_IO_PORT_P56 | 0xF),                                                                 ///< IO port P56 pin 15
#else
    BSP_IO_PORT_P00_PIN_0  = (BSP_IO_PORT_P00 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 0
    BSP_IO_PORT_P00_PIN_1  = (BSP_IO_PORT_P00 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 1
    BSP_IO_PORT_P00_PIN_2  = (BSP_IO_PORT_P00 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 2
    BSP_IO_PORT_P00_PIN_3  = (BSP_IO_PORT_P00 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 3
    BSP_IO_PORT_P00_PIN_4  = (BSP_IO_PORT_P00 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 4
    BSP_IO_PORT_P00_PIN_5  = (BSP_IO_PORT_P00 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 5
    BSP_IO_PORT_P00_PIN_6  = (BSP_IO_PORT_P00 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 6
    BSP_IO_PORT_P00_PIN_7  = (BSP_IO_PORT_P00 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 7
    BSP_IO_PORT_P00_PIN_8  = (BSP_IO_PORT_P00 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 8
    BSP_IO_PORT_P00_PIN_9  = (BSP_IO_PORT_P00 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 9
    BSP_IO_PORT_P00_PIN_10 = (BSP_IO_PORT_P00 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 10
    BSP_IO_PORT_P00_PIN_11 = (BSP_IO_PORT_P00 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P00 pin 11

    BSP_IO_PORT_P01_PIN_3  = (BSP_IO_PORT_P01 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 3
    BSP_IO_PORT_P01_PIN_4  = (BSP_IO_PORT_P01 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 4
    BSP_IO_PORT_P01_PIN_5  = (BSP_IO_PORT_P01 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 5
    BSP_IO_PORT_P01_PIN_6  = (BSP_IO_PORT_P01 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 6
    BSP_IO_PORT_P01_PIN_7  = (BSP_IO_PORT_P01 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 7
    BSP_IO_PORT_P01_PIN_8  = (BSP_IO_PORT_P01 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 8
    BSP_IO_PORT_P01_PIN_9  = (BSP_IO_PORT_P01 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 9
    BSP_IO_PORT_P01_PIN_10 = (BSP_IO_PORT_P01 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 10
    BSP_IO_PORT_P01_PIN_11 = (BSP_IO_PORT_P01 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 11
    BSP_IO_PORT_P01_PIN_12 = (BSP_IO_PORT_P01 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 12
    BSP_IO_PORT_P01_PIN_13 = (BSP_IO_PORT_P01 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 13
    BSP_IO_PORT_P01_PIN_14 = (BSP_IO_PORT_P01 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 14
    BSP_IO_PORT_P01_PIN_15 = (BSP_IO_PORT_P01 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P01 pin 15

    BSP_IO_PORT_P02_PIN_0  = (BSP_IO_PORT_P02 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 0
    BSP_IO_PORT_P02_PIN_1  = (BSP_IO_PORT_P02 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 1
    BSP_IO_PORT_P02_PIN_2  = (BSP_IO_PORT_P02 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 2
    BSP_IO_PORT_P02_PIN_3  = (BSP_IO_PORT_P02 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 3
    BSP_IO_PORT_P02_PIN_4  = (BSP_IO_PORT_P02 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 4
    BSP_IO_PORT_P02_PIN_5  = (BSP_IO_PORT_P02 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 5
    BSP_IO_PORT_P02_PIN_6  = (BSP_IO_PORT_P02 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 6
    BSP_IO_PORT_P02_PIN_7  = (BSP_IO_PORT_P02 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 7
    BSP_IO_PORT_P02_PIN_8  = (BSP_IO_PORT_P02 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 8
    BSP_IO_PORT_P02_PIN_9  = (BSP_IO_PORT_P02 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 9
    BSP_IO_PORT_P02_PIN_10 = (BSP_IO_PORT_P02 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 10
    BSP_IO_PORT_P02_PIN_11 = (BSP_IO_PORT_P02 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P02 pin 11

    BSP_IO_PORT_P10_PIN_0  = (BSP_IO_PORT_P10 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 0
    BSP_IO_PORT_P10_PIN_1  = (BSP_IO_PORT_P10 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 1
    BSP_IO_PORT_P10_PIN_2  = (BSP_IO_PORT_P10 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 2
    BSP_IO_PORT_P10_PIN_3  = (BSP_IO_PORT_P10 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 3
    BSP_IO_PORT_P10_PIN_4  = (BSP_IO_PORT_P10 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 4
    BSP_IO_PORT_P10_PIN_5  = (BSP_IO_PORT_P10 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 5
    BSP_IO_PORT_P10_PIN_6  = (BSP_IO_PORT_P10 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 6
    BSP_IO_PORT_P10_PIN_7  = (BSP_IO_PORT_P10 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 7
    BSP_IO_PORT_P10_PIN_8  = (BSP_IO_PORT_P10 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 8
    BSP_IO_PORT_P10_PIN_9  = (BSP_IO_PORT_P10 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 9
    BSP_IO_PORT_P10_PIN_10 = (BSP_IO_PORT_P10 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 10
    BSP_IO_PORT_P10_PIN_11 = (BSP_IO_PORT_P10 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 11
    BSP_IO_PORT_P10_PIN_12 = (BSP_IO_PORT_P10 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 12
    BSP_IO_PORT_P10_PIN_13 = (BSP_IO_PORT_P10 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 13
    BSP_IO_PORT_P10_PIN_14 = (BSP_IO_PORT_P10 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P10 pin 14

    BSP_IO_PORT_P11_PIN_0  = (BSP_IO_PORT_P11 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 0
    BSP_IO_PORT_P11_PIN_1  = (BSP_IO_PORT_P11 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 1
    BSP_IO_PORT_P11_PIN_2  = (BSP_IO_PORT_P11 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 2
    BSP_IO_PORT_P11_PIN_3  = (BSP_IO_PORT_P11 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 3
    BSP_IO_PORT_P11_PIN_4  = (BSP_IO_PORT_P11 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 4
    BSP_IO_PORT_P11_PIN_5  = (BSP_IO_PORT_P11 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 5
    BSP_IO_PORT_P11_PIN_6  = (BSP_IO_PORT_P11 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 6
    BSP_IO_PORT_P11_PIN_7  = (BSP_IO_PORT_P11 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 7
    BSP_IO_PORT_P11_PIN_8  = (BSP_IO_PORT_P11 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 8
    BSP_IO_PORT_P11_PIN_9  = (BSP_IO_PORT_P11 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 9
    BSP_IO_PORT_P11_PIN_10 = (BSP_IO_PORT_P11 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P11 pin 10

    BSP_IO_PORT_P12_PIN_0 = (BSP_IO_PORT_P12 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P12 pin 0
    BSP_IO_PORT_P12_PIN_1 = (BSP_IO_PORT_P12 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P12 pin 1
    BSP_IO_PORT_P12_PIN_2 = (BSP_IO_PORT_P12 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P12 pin 2
    BSP_IO_PORT_P12_PIN_3 = (BSP_IO_PORT_P12 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P12 pin 3
    BSP_IO_PORT_P12_PIN_4 = (BSP_IO_PORT_P12 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P12 pin 4
    BSP_IO_PORT_P12_PIN_5 = (BSP_IO_PORT_P12 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P12 pin 5
    BSP_IO_PORT_P12_PIN_6 = (BSP_IO_PORT_P12 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P12 pin 6
    BSP_IO_PORT_P12_PIN_7 = (BSP_IO_PORT_P12 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P12 pin 7
    BSP_IO_PORT_P12_PIN_8 = (BSP_IO_PORT_P12 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P12 pin 8
    BSP_IO_PORT_P12_PIN_9 = (BSP_IO_PORT_P12 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P12 pin 9

    BSP_IO_PORT_P13_PIN_0  = (BSP_IO_PORT_P13 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 0
    BSP_IO_PORT_P13_PIN_1  = (BSP_IO_PORT_P13 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 1
    BSP_IO_PORT_P13_PIN_2  = (BSP_IO_PORT_P13 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 2
    BSP_IO_PORT_P13_PIN_3  = (BSP_IO_PORT_P13 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 3
    BSP_IO_PORT_P13_PIN_8  = (BSP_IO_PORT_P13 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 8
    BSP_IO_PORT_P13_PIN_9  = (BSP_IO_PORT_P13 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 9
    BSP_IO_PORT_P13_PIN_10 = (BSP_IO_PORT_P13 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 10
    BSP_IO_PORT_P13_PIN_11 = (BSP_IO_PORT_P13 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 11
    BSP_IO_PORT_P13_PIN_12 = (BSP_IO_PORT_P13 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 12
    BSP_IO_PORT_P13_PIN_13 = (BSP_IO_PORT_P13 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 13
    BSP_IO_PORT_P13_PIN_14 = (BSP_IO_PORT_P13 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P13 pin 14

    BSP_IO_PORT_P14_PIN_0  = (BSP_IO_PORT_P14 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 0
    BSP_IO_PORT_P14_PIN_1  = (BSP_IO_PORT_P14 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 1
    BSP_IO_PORT_P14_PIN_2  = (BSP_IO_PORT_P14 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 2
    BSP_IO_PORT_P14_PIN_3  = (BSP_IO_PORT_P14 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 3
    BSP_IO_PORT_P14_PIN_4  = (BSP_IO_PORT_P14 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 4
    BSP_IO_PORT_P14_PIN_5  = (BSP_IO_PORT_P14 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 5
    BSP_IO_PORT_P14_PIN_6  = (BSP_IO_PORT_P14 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 6
    BSP_IO_PORT_P14_PIN_7  = (BSP_IO_PORT_P14 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 7
    BSP_IO_PORT_P14_PIN_8  = (BSP_IO_PORT_P14 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 8
    BSP_IO_PORT_P14_PIN_9  = (BSP_IO_PORT_P14 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 9
    BSP_IO_PORT_P14_PIN_10 = (BSP_IO_PORT_P14 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 10
    BSP_IO_PORT_P14_PIN_11 = (BSP_IO_PORT_P14 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 11
    BSP_IO_PORT_P14_PIN_12 = (BSP_IO_PORT_P14 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P14 pin 12

    BSP_IO_PORT_P15_PIN_0  = (BSP_IO_PORT_P15 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 0
    BSP_IO_PORT_P15_PIN_1  = (BSP_IO_PORT_P15 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 1
    BSP_IO_PORT_P15_PIN_2  = (BSP_IO_PORT_P15 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 2
    BSP_IO_PORT_P15_PIN_3  = (BSP_IO_PORT_P15 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 3
    BSP_IO_PORT_P15_PIN_4  = (BSP_IO_PORT_P15 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 4
    BSP_IO_PORT_P15_PIN_5  = (BSP_IO_PORT_P15 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 5
    BSP_IO_PORT_P15_PIN_6  = (BSP_IO_PORT_P15 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 6
    BSP_IO_PORT_P15_PIN_7  = (BSP_IO_PORT_P15 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 7
    BSP_IO_PORT_P15_PIN_8  = (BSP_IO_PORT_P15 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 8
    BSP_IO_PORT_P15_PIN_9  = (BSP_IO_PORT_P15 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 9
    BSP_IO_PORT_P15_PIN_10 = (BSP_IO_PORT_P15 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 10
    BSP_IO_PORT_P15_PIN_11 = (BSP_IO_PORT_P15 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 11
    BSP_IO_PORT_P15_PIN_12 = (BSP_IO_PORT_P15 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P15 pin 12

    BSP_IO_PORT_P20_PIN_0 = (BSP_IO_PORT_P20 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P20 pin 0
    BSP_IO_PORT_P20_PIN_1 = (BSP_IO_PORT_P20 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P20 pin 1
    BSP_IO_PORT_P20_PIN_2 = (BSP_IO_PORT_P20 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P20 pin 2
    BSP_IO_PORT_P20_PIN_3 = (BSP_IO_PORT_P20 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P20 pin 3
    BSP_IO_PORT_P20_PIN_4 = (BSP_IO_PORT_P20 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P20 pin 4
    BSP_IO_PORT_P20_PIN_5 = (BSP_IO_PORT_P20 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P20 pin 5
    BSP_IO_PORT_P20_PIN_6 = (BSP_IO_PORT_P20 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P20 pin 6
    BSP_IO_PORT_P20_PIN_7 = (BSP_IO_PORT_P20 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P20 pin 7

    BSP_IO_PORT_P21_PIN_2 = (BSP_IO_PORT_P21 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P21 pin 2
    BSP_IO_PORT_P21_PIN_3 = (BSP_IO_PORT_P21 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P21 pin 3
    BSP_IO_PORT_P21_PIN_4 = (BSP_IO_PORT_P21 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P21 pin 4
    BSP_IO_PORT_P21_PIN_5 = (BSP_IO_PORT_P21 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P21 pin 5

    BSP_IO_PORT_P22_PIN_0  = (BSP_IO_PORT_P22 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 0
    BSP_IO_PORT_P22_PIN_1  = (BSP_IO_PORT_P22 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 1
    BSP_IO_PORT_P22_PIN_2  = (BSP_IO_PORT_P22 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 2
    BSP_IO_PORT_P22_PIN_3  = (BSP_IO_PORT_P22 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 3
    BSP_IO_PORT_P22_PIN_4  = (BSP_IO_PORT_P22 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 4
    BSP_IO_PORT_P22_PIN_5  = (BSP_IO_PORT_P22 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 5
    BSP_IO_PORT_P22_PIN_6  = (BSP_IO_PORT_P22 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 6
    BSP_IO_PORT_P22_PIN_7  = (BSP_IO_PORT_P22 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 7
    BSP_IO_PORT_P22_PIN_8  = (BSP_IO_PORT_P22 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 8
    BSP_IO_PORT_P22_PIN_9  = (BSP_IO_PORT_P22 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 9
    BSP_IO_PORT_P22_PIN_10 = (BSP_IO_PORT_P22 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 10
    BSP_IO_PORT_P22_PIN_11 = (BSP_IO_PORT_P22 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 11
    BSP_IO_PORT_P22_PIN_12 = (BSP_IO_PORT_P22 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 12
    BSP_IO_PORT_P22_PIN_13 = (BSP_IO_PORT_P22 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P22 pin 13

    BSP_IO_PORT_P23_PIN_0  = (BSP_IO_PORT_P23 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 0
    BSP_IO_PORT_P23_PIN_1  = (BSP_IO_PORT_P23 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 1
    BSP_IO_PORT_P23_PIN_2  = (BSP_IO_PORT_P23 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 2
    BSP_IO_PORT_P23_PIN_3  = (BSP_IO_PORT_P23 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 3
    BSP_IO_PORT_P23_PIN_4  = (BSP_IO_PORT_P23 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 4
    BSP_IO_PORT_P23_PIN_5  = (BSP_IO_PORT_P23 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 5
    BSP_IO_PORT_P23_PIN_6  = (BSP_IO_PORT_P23 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 6
    BSP_IO_PORT_P23_PIN_7  = (BSP_IO_PORT_P23 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 7
    BSP_IO_PORT_P23_PIN_8  = (BSP_IO_PORT_P23 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 8
    BSP_IO_PORT_P23_PIN_9  = (BSP_IO_PORT_P23 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 9
    BSP_IO_PORT_P23_PIN_10 = (BSP_IO_PORT_P23 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 10
    BSP_IO_PORT_P23_PIN_11 = (BSP_IO_PORT_P23 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P23 pin 11

    BSP_IO_PORT_P24_PIN_0  = (BSP_IO_PORT_P24 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 0
    BSP_IO_PORT_P24_PIN_1  = (BSP_IO_PORT_P24 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 1
    BSP_IO_PORT_P24_PIN_2  = (BSP_IO_PORT_P24 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 2
    BSP_IO_PORT_P24_PIN_3  = (BSP_IO_PORT_P24 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 3
    BSP_IO_PORT_P24_PIN_4  = (BSP_IO_PORT_P24 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 4
    BSP_IO_PORT_P24_PIN_5  = (BSP_IO_PORT_P24 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 5
    BSP_IO_PORT_P24_PIN_6  = (BSP_IO_PORT_P24 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 6
    BSP_IO_PORT_P24_PIN_7  = (BSP_IO_PORT_P24 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 7
    BSP_IO_PORT_P24_PIN_8  = (BSP_IO_PORT_P24 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 8
    BSP_IO_PORT_P24_PIN_9  = (BSP_IO_PORT_P24 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 9
    BSP_IO_PORT_P24_PIN_10 = (BSP_IO_PORT_P24 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 10
    BSP_IO_PORT_P24_PIN_11 = (BSP_IO_PORT_P24 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 11
    BSP_IO_PORT_P24_PIN_12 = (BSP_IO_PORT_P24 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P24 pin 12

    BSP_IO_PORT_P25_PIN_0  = (BSP_IO_PORT_P25 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 0
    BSP_IO_PORT_P25_PIN_1  = (BSP_IO_PORT_P25 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 1
    BSP_IO_PORT_P25_PIN_2  = (BSP_IO_PORT_P25 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 2
    BSP_IO_PORT_P25_PIN_3  = (BSP_IO_PORT_P25 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 3
    BSP_IO_PORT_P25_PIN_4  = (BSP_IO_PORT_P25 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 4
    BSP_IO_PORT_P25_PIN_5  = (BSP_IO_PORT_P25 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 5
    BSP_IO_PORT_P25_PIN_6  = (BSP_IO_PORT_P25 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 6
    BSP_IO_PORT_P25_PIN_7  = (BSP_IO_PORT_P25 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 7
    BSP_IO_PORT_P25_PIN_8  = (BSP_IO_PORT_P25 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 8
    BSP_IO_PORT_P25_PIN_9  = (BSP_IO_PORT_P25 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 9
    BSP_IO_PORT_P25_PIN_10 = (BSP_IO_PORT_P25 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 10
    BSP_IO_PORT_P25_PIN_11 = (BSP_IO_PORT_P25 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 11
    BSP_IO_PORT_P25_PIN_12 = (BSP_IO_PORT_P25 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 12
    BSP_IO_PORT_P25_PIN_13 = (BSP_IO_PORT_P25 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 13
    BSP_IO_PORT_P25_PIN_14 = (BSP_IO_PORT_P25 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 14
    BSP_IO_PORT_P25_PIN_15 = (BSP_IO_PORT_P25 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P25 pin 15

    BSP_IO_PORT_P30_PIN_0  = (BSP_IO_PORT_P30 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 0
    BSP_IO_PORT_P30_PIN_1  = (BSP_IO_PORT_P30 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 1
    BSP_IO_PORT_P30_PIN_2  = (BSP_IO_PORT_P30 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 2
    BSP_IO_PORT_P30_PIN_3  = (BSP_IO_PORT_P30 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 3
    BSP_IO_PORT_P30_PIN_4  = (BSP_IO_PORT_P30 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 4
    BSP_IO_PORT_P30_PIN_5  = (BSP_IO_PORT_P30 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 5
    BSP_IO_PORT_P30_PIN_6  = (BSP_IO_PORT_P30 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 6
    BSP_IO_PORT_P30_PIN_7  = (BSP_IO_PORT_P30 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 7
    BSP_IO_PORT_P30_PIN_8  = (BSP_IO_PORT_P30 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 8
    BSP_IO_PORT_P30_PIN_9  = (BSP_IO_PORT_P30 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 9
    BSP_IO_PORT_P30_PIN_10 = (BSP_IO_PORT_P30 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 10
    BSP_IO_PORT_P30_PIN_11 = (BSP_IO_PORT_P30 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 11
    BSP_IO_PORT_P30_PIN_12 = (BSP_IO_PORT_P30 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P30 pin 12

    BSP_IO_PORT_P31_PIN_0  = (BSP_IO_PORT_P31 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 0
    BSP_IO_PORT_P31_PIN_1  = (BSP_IO_PORT_P31 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 1
    BSP_IO_PORT_P31_PIN_2  = (BSP_IO_PORT_P31 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 2
    BSP_IO_PORT_P31_PIN_3  = (BSP_IO_PORT_P31 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 3
    BSP_IO_PORT_P31_PIN_4  = (BSP_IO_PORT_P31 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 4
    BSP_IO_PORT_P31_PIN_5  = (BSP_IO_PORT_P31 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 5
    BSP_IO_PORT_P31_PIN_6  = (BSP_IO_PORT_P31 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 6
    BSP_IO_PORT_P31_PIN_7  = (BSP_IO_PORT_P31 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 7
    BSP_IO_PORT_P31_PIN_8  = (BSP_IO_PORT_P31 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 8
    BSP_IO_PORT_P31_PIN_9  = (BSP_IO_PORT_P31 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 9
    BSP_IO_PORT_P31_PIN_10 = (BSP_IO_PORT_P31 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 10
    BSP_IO_PORT_P31_PIN_11 = (BSP_IO_PORT_P31 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 11
    BSP_IO_PORT_P31_PIN_12 = (BSP_IO_PORT_P31 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 12
    BSP_IO_PORT_P31_PIN_13 = (BSP_IO_PORT_P31 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 13
    BSP_IO_PORT_P31_PIN_14 = (BSP_IO_PORT_P31 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 14
    BSP_IO_PORT_P31_PIN_15 = (BSP_IO_PORT_P31 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P31 pin 15

    BSP_IO_PORT_P32_PIN_0 = (BSP_IO_PORT_P32 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P32 pin 0
    BSP_IO_PORT_P32_PIN_1 = (BSP_IO_PORT_P32 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P32 pin 1
    BSP_IO_PORT_P32_PIN_2 = (BSP_IO_PORT_P32 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P32 pin 2
    BSP_IO_PORT_P32_PIN_3 = (BSP_IO_PORT_P32 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P32 pin 3
    BSP_IO_PORT_P32_PIN_4 = (BSP_IO_PORT_P32 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P32 pin 4
    BSP_IO_PORT_P32_PIN_5 = (BSP_IO_PORT_P32 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P32 pin 5
    BSP_IO_PORT_P32_PIN_6 = (BSP_IO_PORT_P32 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P32 pin 6

    BSP_IO_PORT_P33_PIN_0  = (BSP_IO_PORT_P33 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 0
    BSP_IO_PORT_P33_PIN_1  = (BSP_IO_PORT_P33 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 1
    BSP_IO_PORT_P33_PIN_2  = (BSP_IO_PORT_P33 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 2
    BSP_IO_PORT_P33_PIN_3  = (BSP_IO_PORT_P33 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 3
    BSP_IO_PORT_P33_PIN_4  = (BSP_IO_PORT_P33 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 4
    BSP_IO_PORT_P33_PIN_5  = (BSP_IO_PORT_P33 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 5
    BSP_IO_PORT_P33_PIN_6  = (BSP_IO_PORT_P33 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 6
    BSP_IO_PORT_P33_PIN_7  = (BSP_IO_PORT_P33 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 7
    BSP_IO_PORT_P33_PIN_8  = (BSP_IO_PORT_P33 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 8
    BSP_IO_PORT_P33_PIN_9  = (BSP_IO_PORT_P33 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 9
    BSP_IO_PORT_P33_PIN_10 = (BSP_IO_PORT_P33 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 10
    BSP_IO_PORT_P33_PIN_11 = (BSP_IO_PORT_P33 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 11
    BSP_IO_PORT_P33_PIN_12 = (BSP_IO_PORT_P33 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 12
    BSP_IO_PORT_P33_PIN_13 = (BSP_IO_PORT_P33 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P33 pin 13

    BSP_IO_PORT_P34_PIN_0 = (BSP_IO_PORT_P34 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P34 pin 0
    BSP_IO_PORT_P34_PIN_1 = (BSP_IO_PORT_P34 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P34 pin 1
    BSP_IO_PORT_P34_PIN_2 = (BSP_IO_PORT_P34 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P34 pin 2
    BSP_IO_PORT_P34_PIN_3 = (BSP_IO_PORT_P34 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P34 pin 3
    BSP_IO_PORT_P34_PIN_4 = (BSP_IO_PORT_P34 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P34 pin 4

    BSP_IO_PORT_P27_PIN_0 = (BSP_IO_PORT_P27 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */   ///< IO port P27 pin 0

    BSP_IO_PORT_JP00_PIN_0 = (BSP_IO_PORT_JP00 | 0x0), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port JP00 pin 0
    BSP_IO_PORT_JP00_PIN_1 = (BSP_IO_PORT_JP00 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port JP00 pin 1
    BSP_IO_PORT_JP00_PIN_2 = (BSP_IO_PORT_JP00 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port JP00 pin 2
    BSP_IO_PORT_JP00_PIN_3 = (BSP_IO_PORT_JP00 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port JP00 pin 3
    BSP_IO_PORT_JP00_PIN_5 = (BSP_IO_PORT_JP00 | 0x5), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port JP00 pin 5

    BSP_IO_PORT_P40_PIN_0  = (BSP_IO_PORT_P40 | 0x0), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 0
    BSP_IO_PORT_P40_PIN_1  = (BSP_IO_PORT_P40 | 0x1), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 1
    BSP_IO_PORT_P40_PIN_2  = (BSP_IO_PORT_P40 | 0x2), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 2
    BSP_IO_PORT_P40_PIN_3  = (BSP_IO_PORT_P40 | 0x3), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 3
    BSP_IO_PORT_P40_PIN_8  = (BSP_IO_PORT_P40 | 0x8), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 8
    BSP_IO_PORT_P40_PIN_9  = (BSP_IO_PORT_P40 | 0x9), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 9
    BSP_IO_PORT_P40_PIN_10 = (BSP_IO_PORT_P40 | 0xA), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 10
    BSP_IO_PORT_P40_PIN_11 = (BSP_IO_PORT_P40 | 0xB), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 11
    BSP_IO_PORT_P40_PIN_12 = (BSP_IO_PORT_P40 | 0xC), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 12
    BSP_IO_PORT_P40_PIN_13 = (BSP_IO_PORT_P40 | 0xD), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 13
    BSP_IO_PORT_P40_PIN_14 = (BSP_IO_PORT_P40 | 0xE), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 14
    BSP_IO_PORT_P40_PIN_15 = (BSP_IO_PORT_P40 | 0xF), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 15
    BSP_IO_PORT_P40_PIN_4  = (BSP_IO_PORT_P40 | 0x4), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 4
    BSP_IO_PORT_P40_PIN_5  = (BSP_IO_PORT_P40 | 0x5), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 5
    BSP_IO_PORT_P40_PIN_6  = (BSP_IO_PORT_P40 | 0x6), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 6
    BSP_IO_PORT_P40_PIN_7  = (BSP_IO_PORT_P40 | 0x7), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P40 pin 7

    BSP_IO_PORT_P37_PIN_0  = (BSP_IO_PORT_P37 | 0x0), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 0
    BSP_IO_PORT_P37_PIN_1  = (BSP_IO_PORT_P37 | 0x1), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 1
    BSP_IO_PORT_P37_PIN_2  = (BSP_IO_PORT_P37 | 0x2), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 2
    BSP_IO_PORT_P37_PIN_3  = (BSP_IO_PORT_P37 | 0x3), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 3
    BSP_IO_PORT_P37_PIN_4  = (BSP_IO_PORT_P37 | 0x4), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 4
    BSP_IO_PORT_P37_PIN_5  = (BSP_IO_PORT_P37 | 0x5), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 5
    BSP_IO_PORT_P37_PIN_6  = (BSP_IO_PORT_P37 | 0x6), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 6
    BSP_IO_PORT_P37_PIN_7  = (BSP_IO_PORT_P37 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 7
    BSP_IO_PORT_P37_PIN_8  = (BSP_IO_PORT_P37 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 8
    BSP_IO_PORT_P37_PIN_9  = (BSP_IO_PORT_P37 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 9
    BSP_IO_PORT_P37_PIN_10 = (BSP_IO_PORT_P37 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 10
    BSP_IO_PORT_P37_PIN_11 = (BSP_IO_PORT_P37 | 0xB), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 11
    BSP_IO_PORT_P37_PIN_12 = (BSP_IO_PORT_P37 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 12
    BSP_IO_PORT_P37_PIN_13 = (BSP_IO_PORT_P37 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 13
    BSP_IO_PORT_P37_PIN_14 = (BSP_IO_PORT_P37 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 14
    BSP_IO_PORT_P37_PIN_15 = (BSP_IO_PORT_P37 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P37 pin 15

    BSP_IO_PORT_P38_PIN_0  = (BSP_IO_PORT_P38 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 0
    BSP_IO_PORT_P38_PIN_1  = (BSP_IO_PORT_P38 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 1
    BSP_IO_PORT_P38_PIN_2  = (BSP_IO_PORT_P38 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 2
    BSP_IO_PORT_P38_PIN_3  = (BSP_IO_PORT_P38 | 0x3), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 3
    BSP_IO_PORT_P38_PIN_4  = (BSP_IO_PORT_P38 | 0x4), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 4
    BSP_IO_PORT_P38_PIN_5  = (BSP_IO_PORT_P38 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 5
    BSP_IO_PORT_P38_PIN_6  = (BSP_IO_PORT_P38 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 6
    BSP_IO_PORT_P38_PIN_7  = (BSP_IO_PORT_P38 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 7
    BSP_IO_PORT_P38_PIN_8  = (BSP_IO_PORT_P38 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 8
    BSP_IO_PORT_P38_PIN_9  = (BSP_IO_PORT_P38 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 9
    BSP_IO_PORT_P38_PIN_10 = (BSP_IO_PORT_P38 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 10
    BSP_IO_PORT_P38_PIN_11 = (BSP_IO_PORT_P38 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 11
    BSP_IO_PORT_P38_PIN_12 = (BSP_IO_PORT_P38 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 12
    BSP_IO_PORT_P38_PIN_13 = (BSP_IO_PORT_P38 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 13
    BSP_IO_PORT_P38_PIN_14 = (BSP_IO_PORT_P38 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 14
    BSP_IO_PORT_P38_PIN_15 = (BSP_IO_PORT_P38 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P38 pin 15

    BSP_IO_PORT_P39_PIN_0  = (BSP_IO_PORT_P39 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 0
    BSP_IO_PORT_P39_PIN_1  = (BSP_IO_PORT_P39 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 1
    BSP_IO_PORT_P39_PIN_2  = (BSP_IO_PORT_P39 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 2
    BSP_IO_PORT_P39_PIN_3  = (BSP_IO_PORT_P39 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 3
    BSP_IO_PORT_P39_PIN_4  = (BSP_IO_PORT_P39 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 4
    BSP_IO_PORT_P39_PIN_5  = (BSP_IO_PORT_P39 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 5
    BSP_IO_PORT_P39_PIN_6  = (BSP_IO_PORT_P39 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 6
    BSP_IO_PORT_P39_PIN_7  = (BSP_IO_PORT_P39 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 7
    BSP_IO_PORT_P39_PIN_8  = (BSP_IO_PORT_P39 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 8
    BSP_IO_PORT_P39_PIN_9  = (BSP_IO_PORT_P39 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 9
    BSP_IO_PORT_P39_PIN_10 = (BSP_IO_PORT_P39 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 10
    BSP_IO_PORT_P39_PIN_11 = (BSP_IO_PORT_P39 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 11
    BSP_IO_PORT_P39_PIN_12 = (BSP_IO_PORT_P39 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 12
    BSP_IO_PORT_P39_PIN_13 = (BSP_IO_PORT_P39 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 13
    BSP_IO_PORT_P39_PIN_14 = (BSP_IO_PORT_P39 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 14
    BSP_IO_PORT_P39_PIN_15 = (BSP_IO_PORT_P39 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P39 pin 15

    BSP_IO_PORT_P41_PIN_0  = (BSP_IO_PORT_P41 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 0
    BSP_IO_PORT_P41_PIN_1  = (BSP_IO_PORT_P41 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 1
    BSP_IO_PORT_P41_PIN_2  = (BSP_IO_PORT_P41 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 2
    BSP_IO_PORT_P41_PIN_3  = (BSP_IO_PORT_P41 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 3
    BSP_IO_PORT_P41_PIN_4  = (BSP_IO_PORT_P41 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 4
    BSP_IO_PORT_P41_PIN_5  = (BSP_IO_PORT_P41 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 5
    BSP_IO_PORT_P41_PIN_6  = (BSP_IO_PORT_P41 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 6
    BSP_IO_PORT_P41_PIN_7  = (BSP_IO_PORT_P41 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 7
    BSP_IO_PORT_P41_PIN_8  = (BSP_IO_PORT_P41 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 8
    BSP_IO_PORT_P41_PIN_9  = (BSP_IO_PORT_P41 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 9
    BSP_IO_PORT_P41_PIN_10 = (BSP_IO_PORT_P41 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 10
    BSP_IO_PORT_P41_PIN_11 = (BSP_IO_PORT_P41 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 11
    BSP_IO_PORT_P41_PIN_12 = (BSP_IO_PORT_P41 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 12
    BSP_IO_PORT_P41_PIN_13 = (BSP_IO_PORT_P41 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 13
    BSP_IO_PORT_P41_PIN_14 = (BSP_IO_PORT_P41 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 14
    BSP_IO_PORT_P41_PIN_15 = (BSP_IO_PORT_P41 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P41 pin 15

    BSP_IO_PORT_P42_PIN_0  = (BSP_IO_PORT_P42 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 0
    BSP_IO_PORT_P42_PIN_1  = (BSP_IO_PORT_P42 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 1
    BSP_IO_PORT_P42_PIN_2  = (BSP_IO_PORT_P42 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 2
    BSP_IO_PORT_P42_PIN_3  = (BSP_IO_PORT_P42 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 3
    BSP_IO_PORT_P42_PIN_4  = (BSP_IO_PORT_P42 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 4
    BSP_IO_PORT_P42_PIN_5  = (BSP_IO_PORT_P42 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 5
    BSP_IO_PORT_P42_PIN_6  = (BSP_IO_PORT_P42 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 6
    BSP_IO_PORT_P42_PIN_7  = (BSP_IO_PORT_P42 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 7
    BSP_IO_PORT_P42_PIN_8  = (BSP_IO_PORT_P42 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 8
    BSP_IO_PORT_P42_PIN_9  = (BSP_IO_PORT_P42 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 9
    BSP_IO_PORT_P42_PIN_10 = (BSP_IO_PORT_P42 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 10
    BSP_IO_PORT_P42_PIN_11 = (BSP_IO_PORT_P42 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 11
    BSP_IO_PORT_P42_PIN_12 = (BSP_IO_PORT_P42 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 12
    BSP_IO_PORT_P42_PIN_13 = (BSP_IO_PORT_P42 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 13
    BSP_IO_PORT_P42_PIN_14 = (BSP_IO_PORT_P42 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 14
    BSP_IO_PORT_P42_PIN_15 = (BSP_IO_PORT_P42 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P42 pin 15

    BSP_IO_PORT_P43_PIN_0  = (BSP_IO_PORT_P43 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 0
    BSP_IO_PORT_P43_PIN_1  = (BSP_IO_PORT_P43 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 1
    BSP_IO_PORT_P43_PIN_2  = (BSP_IO_PORT_P43 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 2
    BSP_IO_PORT_P43_PIN_3  = (BSP_IO_PORT_P43 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 3
    BSP_IO_PORT_P43_PIN_4  = (BSP_IO_PORT_P43 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 4
    BSP_IO_PORT_P43_PIN_5  = (BSP_IO_PORT_P43 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 5
    BSP_IO_PORT_P43_PIN_6  = (BSP_IO_PORT_P43 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 6
    BSP_IO_PORT_P43_PIN_7  = (BSP_IO_PORT_P43 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 7
    BSP_IO_PORT_P43_PIN_8  = (BSP_IO_PORT_P43 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 8
    BSP_IO_PORT_P43_PIN_9  = (BSP_IO_PORT_P43 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 9
    BSP_IO_PORT_P43_PIN_10 = (BSP_IO_PORT_P43 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 10
    BSP_IO_PORT_P43_PIN_11 = (BSP_IO_PORT_P43 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 11
    BSP_IO_PORT_P43_PIN_12 = (BSP_IO_PORT_P43 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 12
    BSP_IO_PORT_P43_PIN_13 = (BSP_IO_PORT_P43 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 13
    BSP_IO_PORT_P43_PIN_14 = (BSP_IO_PORT_P43 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 14
    BSP_IO_PORT_P43_PIN_15 = (BSP_IO_PORT_P43 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P43 pin 15

    BSP_IO_PORT_P44_PIN_0  = (BSP_IO_PORT_P44 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 0
    BSP_IO_PORT_P44_PIN_1  = (BSP_IO_PORT_P44 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 1
    BSP_IO_PORT_P44_PIN_2  = (BSP_IO_PORT_P44 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 2
    BSP_IO_PORT_P44_PIN_3  = (BSP_IO_PORT_P44 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 3
    BSP_IO_PORT_P44_PIN_4  = (BSP_IO_PORT_P44 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 4
    BSP_IO_PORT_P44_PIN_5  = (BSP_IO_PORT_P44 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 5
    BSP_IO_PORT_P44_PIN_6  = (BSP_IO_PORT_P44 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 6
    BSP_IO_PORT_P44_PIN_7  = (BSP_IO_PORT_P44 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 7
    BSP_IO_PORT_P44_PIN_8  = (BSP_IO_PORT_P44 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 8
    BSP_IO_PORT_P44_PIN_9  = (BSP_IO_PORT_P44 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 9
    BSP_IO_PORT_P44_PIN_10 = (BSP_IO_PORT_P44 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 10
    BSP_IO_PORT_P44_PIN_11 = (BSP_IO_PORT_P44 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 11
    BSP_IO_PORT_P44_PIN_12 = (BSP_IO_PORT_P44 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 12
    BSP_IO_PORT_P44_PIN_13 = (BSP_IO_PORT_P44 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 13
    BSP_IO_PORT_P44_PIN_14 = (BSP_IO_PORT_P44 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 14
    BSP_IO_PORT_P44_PIN_15 = (BSP_IO_PORT_P44 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P44 pin 15

    BSP_IO_PORT_P45_PIN_0  = (BSP_IO_PORT_P45 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 0
    BSP_IO_PORT_P45_PIN_1  = (BSP_IO_PORT_P45 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 1
    BSP_IO_PORT_P45_PIN_2  = (BSP_IO_PORT_P45 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 2
    BSP_IO_PORT_P45_PIN_3  = (BSP_IO_PORT_P45 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 3
    BSP_IO_PORT_P45_PIN_4  = (BSP_IO_PORT_P45 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 4
    BSP_IO_PORT_P45_PIN_5  = (BSP_IO_PORT_P45 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 5
    BSP_IO_PORT_P45_PIN_6  = (BSP_IO_PORT_P45 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 6
    BSP_IO_PORT_P45_PIN_7  = (BSP_IO_PORT_P45 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 7
    BSP_IO_PORT_P45_PIN_8  = (BSP_IO_PORT_P45 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 8
    BSP_IO_PORT_P45_PIN_9  = (BSP_IO_PORT_P45 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 9
    BSP_IO_PORT_P45_PIN_10 = (BSP_IO_PORT_P45 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 10
    BSP_IO_PORT_P45_PIN_11 = (BSP_IO_PORT_P45 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 11
    BSP_IO_PORT_P45_PIN_12 = (BSP_IO_PORT_P45 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 12
    BSP_IO_PORT_P45_PIN_13 = (BSP_IO_PORT_P45 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 13
    BSP_IO_PORT_P45_PIN_14 = (BSP_IO_PORT_P45 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 14
    BSP_IO_PORT_P45_PIN_15 = (BSP_IO_PORT_P45 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P45 pin 15

    BSP_IO_PORT_P46_PIN_0  = (BSP_IO_PORT_P46 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 0
    BSP_IO_PORT_P46_PIN_1  = (BSP_IO_PORT_P46 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 1
    BSP_IO_PORT_P46_PIN_2  = (BSP_IO_PORT_P46 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 2
    BSP_IO_PORT_P46_PIN_3  = (BSP_IO_PORT_P46 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 3
    BSP_IO_PORT_P46_PIN_4  = (BSP_IO_PORT_P46 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 4
    BSP_IO_PORT_P46_PIN_5  = (BSP_IO_PORT_P46 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 5
    BSP_IO_PORT_P46_PIN_6  = (BSP_IO_PORT_P46 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 6
    BSP_IO_PORT_P46_PIN_7  = (BSP_IO_PORT_P46 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 7
    BSP_IO_PORT_P46_PIN_8  = (BSP_IO_PORT_P46 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 8
    BSP_IO_PORT_P46_PIN_9  = (BSP_IO_PORT_P46 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 9
    BSP_IO_PORT_P46_PIN_10 = (BSP_IO_PORT_P46 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 10
    BSP_IO_PORT_P46_PIN_11 = (BSP_IO_PORT_P46 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 11
    BSP_IO_PORT_P46_PIN_12 = (BSP_IO_PORT_P46 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 12
    BSP_IO_PORT_P46_PIN_13 = (BSP_IO_PORT_P46 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 13
    BSP_IO_PORT_P46_PIN_14 = (BSP_IO_PORT_P46 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 14
    BSP_IO_PORT_P46_PIN_15 = (BSP_IO_PORT_P46 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P46 pin 15

    BSP_IO_PORT_P47_PIN_0  = (BSP_IO_PORT_P47 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 0
    BSP_IO_PORT_P47_PIN_1  = (BSP_IO_PORT_P47 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 1
    BSP_IO_PORT_P47_PIN_2  = (BSP_IO_PORT_P47 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 2
    BSP_IO_PORT_P47_PIN_3  = (BSP_IO_PORT_P47 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 3
    BSP_IO_PORT_P47_PIN_4  = (BSP_IO_PORT_P47 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 4
    BSP_IO_PORT_P47_PIN_5  = (BSP_IO_PORT_P47 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 5
    BSP_IO_PORT_P47_PIN_6  = (BSP_IO_PORT_P47 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 6
    BSP_IO_PORT_P47_PIN_7  = (BSP_IO_PORT_P47 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 7
    BSP_IO_PORT_P47_PIN_8  = (BSP_IO_PORT_P47 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 8
    BSP_IO_PORT_P47_PIN_9  = (BSP_IO_PORT_P47 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 9
    BSP_IO_PORT_P47_PIN_10 = (BSP_IO_PORT_P47 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 10
    BSP_IO_PORT_P47_PIN_11 = (BSP_IO_PORT_P47 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 11
    BSP_IO_PORT_P47_PIN_12 = (BSP_IO_PORT_P47 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 12
    BSP_IO_PORT_P47_PIN_13 = (BSP_IO_PORT_P47 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 13
    BSP_IO_PORT_P47_PIN_14 = (BSP_IO_PORT_P47 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 14
    BSP_IO_PORT_P47_PIN_15 = (BSP_IO_PORT_P47 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P47 pin 15

    BSP_IO_PORT_P48_PIN_0  = (BSP_IO_PORT_P48 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 0
    BSP_IO_PORT_P48_PIN_1  = (BSP_IO_PORT_P48 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 1
    BSP_IO_PORT_P48_PIN_2  = (BSP_IO_PORT_P48 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 2
    BSP_IO_PORT_P48_PIN_3  = (BSP_IO_PORT_P48 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 3
    BSP_IO_PORT_P48_PIN_4  = (BSP_IO_PORT_P48 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 4
    BSP_IO_PORT_P48_PIN_5  = (BSP_IO_PORT_P48 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 5
    BSP_IO_PORT_P48_PIN_6  = (BSP_IO_PORT_P48 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 6
    BSP_IO_PORT_P48_PIN_7  = (BSP_IO_PORT_P48 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 7
    BSP_IO_PORT_P48_PIN_8  = (BSP_IO_PORT_P48 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 8
    BSP_IO_PORT_P48_PIN_9  = (BSP_IO_PORT_P48 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 9
    BSP_IO_PORT_P48_PIN_10 = (BSP_IO_PORT_P48 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 10
    BSP_IO_PORT_P48_PIN_11 = (BSP_IO_PORT_P48 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 11
    BSP_IO_PORT_P48_PIN_12 = (BSP_IO_PORT_P48 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 12
    BSP_IO_PORT_P48_PIN_13 = (BSP_IO_PORT_P48 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 13
    BSP_IO_PORT_P48_PIN_14 = (BSP_IO_PORT_P48 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 14
    BSP_IO_PORT_P48_PIN_15 = (BSP_IO_PORT_P48 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P48 pin 15

    BSP_IO_PORT_P49_PIN_0  = (BSP_IO_PORT_P49 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 0
    BSP_IO_PORT_P49_PIN_1  = (BSP_IO_PORT_P49 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 1
    BSP_IO_PORT_P49_PIN_2  = (BSP_IO_PORT_P49 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 2
    BSP_IO_PORT_P49_PIN_3  = (BSP_IO_PORT_P49 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 3
    BSP_IO_PORT_P49_PIN_4  = (BSP_IO_PORT_P49 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 4
    BSP_IO_PORT_P49_PIN_5  = (BSP_IO_PORT_P49 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 5
    BSP_IO_PORT_P49_PIN_6  = (BSP_IO_PORT_P49 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 6
    BSP_IO_PORT_P49_PIN_7  = (BSP_IO_PORT_P49 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 7
    BSP_IO_PORT_P49_PIN_8  = (BSP_IO_PORT_P49 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 8
    BSP_IO_PORT_P49_PIN_9  = (BSP_IO_PORT_P49 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 9
    BSP_IO_PORT_P49_PIN_10 = (BSP_IO_PORT_P49 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 10
    BSP_IO_PORT_P49_PIN_11 = (BSP_IO_PORT_P49 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 11
    BSP_IO_PORT_P49_PIN_12 = (BSP_IO_PORT_P49 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 12
    BSP_IO_PORT_P49_PIN_13 = (BSP_IO_PORT_P49 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 13
    BSP_IO_PORT_P49_PIN_14 = (BSP_IO_PORT_P49 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 14
    BSP_IO_PORT_P49_PIN_15 = (BSP_IO_PORT_P49 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P49 pin 15

    BSP_IO_PORT_P50_PIN_0  = (BSP_IO_PORT_P50 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 0
    BSP_IO_PORT_P50_PIN_1  = (BSP_IO_PORT_P50 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 1
    BSP_IO_PORT_P50_PIN_2  = (BSP_IO_PORT_P50 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 2
    BSP_IO_PORT_P50_PIN_3  = (BSP_IO_PORT_P50 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 3
    BSP_IO_PORT_P50_PIN_4  = (BSP_IO_PORT_P50 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 4
    BSP_IO_PORT_P50_PIN_5  = (BSP_IO_PORT_P50 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 5
    BSP_IO_PORT_P50_PIN_6  = (BSP_IO_PORT_P50 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 6
    BSP_IO_PORT_P50_PIN_7  = (BSP_IO_PORT_P50 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 7
    BSP_IO_PORT_P50_PIN_8  = (BSP_IO_PORT_P50 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 8
    BSP_IO_PORT_P50_PIN_9  = (BSP_IO_PORT_P50 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 9
    BSP_IO_PORT_P50_PIN_10 = (BSP_IO_PORT_P50 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 10
    BSP_IO_PORT_P50_PIN_11 = (BSP_IO_PORT_P50 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 11
    BSP_IO_PORT_P50_PIN_12 = (BSP_IO_PORT_P50 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 12
    BSP_IO_PORT_P50_PIN_13 = (BSP_IO_PORT_P50 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 13
    BSP_IO_PORT_P50_PIN_14 = (BSP_IO_PORT_P50 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 14
    BSP_IO_PORT_P50_PIN_15 = (BSP_IO_PORT_P50 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P50 pin 15

    BSP_IO_PORT_P51_PIN_0  = (BSP_IO_PORT_P51 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 0
    BSP_IO_PORT_P51_PIN_1  = (BSP_IO_PORT_P51 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 1
    BSP_IO_PORT_P51_PIN_2  = (BSP_IO_PORT_P51 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 2
    BSP_IO_PORT_P51_PIN_3  = (BSP_IO_PORT_P51 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 3
    BSP_IO_PORT_P51_PIN_4  = (BSP_IO_PORT_P51 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 4
    BSP_IO_PORT_P51_PIN_5  = (BSP_IO_PORT_P51 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 5
    BSP_IO_PORT_P51_PIN_6  = (BSP_IO_PORT_P51 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 6
    BSP_IO_PORT_P51_PIN_7  = (BSP_IO_PORT_P51 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 7
    BSP_IO_PORT_P51_PIN_8  = (BSP_IO_PORT_P51 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 8
    BSP_IO_PORT_P51_PIN_9  = (BSP_IO_PORT_P51 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 9
    BSP_IO_PORT_P51_PIN_10 = (BSP_IO_PORT_P51 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 10
    BSP_IO_PORT_P51_PIN_11 = (BSP_IO_PORT_P51 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 11
    BSP_IO_PORT_P51_PIN_12 = (BSP_IO_PORT_P51 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 12
    BSP_IO_PORT_P51_PIN_13 = (BSP_IO_PORT_P51 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 13
    BSP_IO_PORT_P51_PIN_14 = (BSP_IO_PORT_P51 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 14
    BSP_IO_PORT_P51_PIN_15 = (BSP_IO_PORT_P51 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P51 pin 15

    BSP_IO_PORT_P52_PIN_0  = (BSP_IO_PORT_P52 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 0
    BSP_IO_PORT_P52_PIN_1  = (BSP_IO_PORT_P52 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 1
    BSP_IO_PORT_P52_PIN_2  = (BSP_IO_PORT_P52 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 2
    BSP_IO_PORT_P52_PIN_3  = (BSP_IO_PORT_P52 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 3
    BSP_IO_PORT_P52_PIN_4  = (BSP_IO_PORT_P52 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 4
    BSP_IO_PORT_P52_PIN_5  = (BSP_IO_PORT_P52 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 5
    BSP_IO_PORT_P52_PIN_6  = (BSP_IO_PORT_P52 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 6
    BSP_IO_PORT_P52_PIN_7  = (BSP_IO_PORT_P52 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 7
    BSP_IO_PORT_P52_PIN_8  = (BSP_IO_PORT_P52 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 8
    BSP_IO_PORT_P52_PIN_9  = (BSP_IO_PORT_P52 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 9
    BSP_IO_PORT_P52_PIN_10 = (BSP_IO_PORT_P52 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 10
    BSP_IO_PORT_P52_PIN_11 = (BSP_IO_PORT_P52 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 11
    BSP_IO_PORT_P52_PIN_12 = (BSP_IO_PORT_P52 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 12
    BSP_IO_PORT_P52_PIN_13 = (BSP_IO_PORT_P52 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 13
    BSP_IO_PORT_P52_PIN_14 = (BSP_IO_PORT_P52 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 14
    BSP_IO_PORT_P52_PIN_15 = (BSP_IO_PORT_P52 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P52 pin 15

    BSP_IO_PORT_P53_PIN_0  = (BSP_IO_PORT_P53 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 0
    BSP_IO_PORT_P53_PIN_1  = (BSP_IO_PORT_P53 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 1
    BSP_IO_PORT_P53_PIN_2  = (BSP_IO_PORT_P53 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 2
    BSP_IO_PORT_P53_PIN_3  = (BSP_IO_PORT_P53 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 3
    BSP_IO_PORT_P53_PIN_4  = (BSP_IO_PORT_P53 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 4
    BSP_IO_PORT_P53_PIN_5  = (BSP_IO_PORT_P53 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 5
    BSP_IO_PORT_P53_PIN_6  = (BSP_IO_PORT_P53 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 6
    BSP_IO_PORT_P53_PIN_7  = (BSP_IO_PORT_P53 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 7
    BSP_IO_PORT_P53_PIN_8  = (BSP_IO_PORT_P53 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 8
    BSP_IO_PORT_P53_PIN_9  = (BSP_IO_PORT_P53 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 9
    BSP_IO_PORT_P53_PIN_10 = (BSP_IO_PORT_P53 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 10
    BSP_IO_PORT_P53_PIN_11 = (BSP_IO_PORT_P53 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 11
    BSP_IO_PORT_P53_PIN_12 = (BSP_IO_PORT_P53 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 12
    BSP_IO_PORT_P53_PIN_13 = (BSP_IO_PORT_P53 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 13
    BSP_IO_PORT_P53_PIN_14 = (BSP_IO_PORT_P53 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 14
    BSP_IO_PORT_P53_PIN_15 = (BSP_IO_PORT_P53 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P53 pin 15

    BSP_IO_PORT_P54_PIN_0  = (BSP_IO_PORT_P54 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 0
    BSP_IO_PORT_P54_PIN_1  = (BSP_IO_PORT_P54 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 1
    BSP_IO_PORT_P54_PIN_2  = (BSP_IO_PORT_P54 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 2
    BSP_IO_PORT_P54_PIN_3  = (BSP_IO_PORT_P54 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 3
    BSP_IO_PORT_P54_PIN_4  = (BSP_IO_PORT_P54 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 4
    BSP_IO_PORT_P54_PIN_5  = (BSP_IO_PORT_P54 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 5
    BSP_IO_PORT_P54_PIN_6  = (BSP_IO_PORT_P54 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 6
    BSP_IO_PORT_P54_PIN_7  = (BSP_IO_PORT_P54 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 7
    BSP_IO_PORT_P54_PIN_8  = (BSP_IO_PORT_P54 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 8
    BSP_IO_PORT_P54_PIN_9  = (BSP_IO_PORT_P54 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 9
    BSP_IO_PORT_P54_PIN_10 = (BSP_IO_PORT_P54 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 10
    BSP_IO_PORT_P54_PIN_11 = (BSP_IO_PORT_P54 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 11
    BSP_IO_PORT_P54_PIN_12 = (BSP_IO_PORT_P54 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 12
    BSP_IO_PORT_P54_PIN_13 = (BSP_IO_PORT_P54 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 13
    BSP_IO_PORT_P54_PIN_14 = (BSP_IO_PORT_P54 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 14
    BSP_IO_PORT_P54_PIN_15 = (BSP_IO_PORT_P54 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P54 pin 15

    BSP_IO_PORT_P55_PIN_0  = (BSP_IO_PORT_P55 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 0
    BSP_IO_PORT_P55_PIN_1  = (BSP_IO_PORT_P55 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 1
    BSP_IO_PORT_P55_PIN_2  = (BSP_IO_PORT_P55 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 2
    BSP_IO_PORT_P55_PIN_3  = (BSP_IO_PORT_P55 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 3
    BSP_IO_PORT_P55_PIN_4  = (BSP_IO_PORT_P55 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 4
    BSP_IO_PORT_P55_PIN_5  = (BSP_IO_PORT_P55 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 5
    BSP_IO_PORT_P55_PIN_6  = (BSP_IO_PORT_P55 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 6
    BSP_IO_PORT_P55_PIN_7  = (BSP_IO_PORT_P55 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 7
    BSP_IO_PORT_P55_PIN_8  = (BSP_IO_PORT_P55 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 8
    BSP_IO_PORT_P55_PIN_9  = (BSP_IO_PORT_P55 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 9
    BSP_IO_PORT_P55_PIN_10 = (BSP_IO_PORT_P55 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 10
    BSP_IO_PORT_P55_PIN_11 = (BSP_IO_PORT_P55 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 11
    BSP_IO_PORT_P55_PIN_12 = (BSP_IO_PORT_P55 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 12
    BSP_IO_PORT_P55_PIN_13 = (BSP_IO_PORT_P55 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 13
    BSP_IO_PORT_P55_PIN_14 = (BSP_IO_PORT_P55 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 14
    BSP_IO_PORT_P55_PIN_15 = (BSP_IO_PORT_P55 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P55 pin 15

    BSP_IO_PORT_P56_PIN_0  = (BSP_IO_PORT_P56 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 0
    BSP_IO_PORT_P56_PIN_1  = (BSP_IO_PORT_P56 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 1
    BSP_IO_PORT_P56_PIN_2  = (BSP_IO_PORT_P56 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 2
    BSP_IO_PORT_P56_PIN_3  = (BSP_IO_PORT_P56 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 3
    BSP_IO_PORT_P56_PIN_4  = (BSP_IO_PORT_P56 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 4
    BSP_IO_PORT_P56_PIN_5  = (BSP_IO_PORT_P56 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 5
    BSP_IO_PORT_P56_PIN_6  = (BSP_IO_PORT_P56 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 6
    BSP_IO_PORT_P56_PIN_7  = (BSP_IO_PORT_P56 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 7
    BSP_IO_PORT_P56_PIN_8  = (BSP_IO_PORT_P56 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 8
    BSP_IO_PORT_P56_PIN_9  = (BSP_IO_PORT_P56 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 9
    BSP_IO_PORT_P56_PIN_10 = (BSP_IO_PORT_P56 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 10
    BSP_IO_PORT_P56_PIN_11 = (BSP_IO_PORT_P56 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 11
    BSP_IO_PORT_P56_PIN_12 = (BSP_IO_PORT_P56 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 12
    BSP_IO_PORT_P56_PIN_13 = (BSP_IO_PORT_P56 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 13
    BSP_IO_PORT_P56_PIN_14 = (BSP_IO_PORT_P56 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 14
    BSP_IO_PORT_P56_PIN_15 = (BSP_IO_PORT_P56 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */  ///< IO port P56 pin 15
#endif
} bsp_io_port_pin_t;

/* PRQA S 1507 -- */

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_IO) */

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_IO_DEVICE_H */
