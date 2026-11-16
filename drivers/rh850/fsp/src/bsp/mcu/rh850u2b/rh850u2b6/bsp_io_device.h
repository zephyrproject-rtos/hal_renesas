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
 * @ingroup BSP_MCU_RH850U2B6
 * @defgroup BSP_IO_U2B6 BSP I/O access
 * @brief This module provides basic read/write access to port pins.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define R_BSP_JPORT             ((R_PORT_Type *) 0xFFDA0000) /* PRQA S 1534 # Advisory R-2.5 */ ///< Base address of JPORT instance
#define R_BSP_APORT             ((R_PORT_Type *) NULL) /* PRQA S 1534 # Advisory R-2.5 */       ///< APORT instance not available (NULL pointer)

#define BSP_IO_PORT_P00_PWE     (0)                                                             ///< PWE value for P00
#define BSP_IO_PORT_P02_PWE     (2)                                                             ///< PWE value for P02
#define BSP_IO_PORT_P10_PWE     (3)                                                             ///< PWE value for P10
#define BSP_IO_PORT_P11_PWE     (4)                                                             ///< PWE value for P11
#define BSP_IO_PORT_P12_PWE     (5)                                                             ///< PWE value for P12
#define BSP_IO_PORT_P13_PWE     (6)                                                             ///< PWE value for P13
#define BSP_IO_PORT_P14_PWE     (7)                                                             ///< PWE value for P14
#define BSP_IO_PORT_P20_PWE     (9)                                                             ///< PWE value for P20
#define BSP_IO_PORT_P21_PWE     (10)                                                            ///< PWE value for P21
#define BSP_IO_PORT_P22_PWE     (11)                                                            ///< PWE value for P22
#define BSP_IO_PORT_P23_PWE     (12)                                                            ///< PWE value for P23
#define BSP_IO_PORT_P25_PWE     (14)                                                            ///< PWE value for P25
#define BSP_IO_PORT_P32_PWE     (19)                                                            ///< PWE value for P32
#define BSP_IO_PORT_P33_PWE     (20)                                                            ///< PWE value for P33
#define BSP_IO_PORT_P34_PWE     (21)                                                            ///< PWE value for P34
#define BSP_IO_PORT_P27_PWE     (16)                                                            ///< PWE value for P27

#define BSP_IO_PORT_JP00_PWE    (255)                                                           ///< PWE value for JP00
#define BSP_IO_PORT_P40_PWE     (255)                                                           ///< PWE value for P40
#define BSP_IO_PORT_P37_PWE     (255)                                                           ///< PWE value for P37
#define BSP_IO_PORT_P38_PWE     (255)                                                           ///< PWE value for P38
#define BSP_IO_PORT_P41_PWE     (255)                                                           ///< PWE value for P41
#define BSP_IO_PORT_P42_PWE     (255)                                                           ///< PWE value for P42
#define BSP_IO_PORT_P43_PWE     (255)                                                           ///< PWE value for P43
#define BSP_IO_PORT_P44_PWE     (255)                                                           ///< PWE value for P44
#define BSP_IO_PORT_P45_PWE     (255)                                                           ///< PWE value for P45
#define BSP_IO_PORT_P46_PWE     (255)                                                           ///< PWE value for P46
#define BSP_IO_PORT_P47_PWE     (255)                                                           ///< PWE value for P47
#define BSP_IO_PORT_P48_PWE     (255)                                                           ///< PWE value for P48
#define BSP_IO_PORT_P49_PWE     (255)                                                           ///< PWE value for P49
#define BSP_IO_PORT_P50_PWE     (255)                                                           ///< PWE value for P50
#define BSP_IO_PORT_P51_PWE     (255)                                                           ///< PWE value for P51
#define BSP_IO_PORT_P52_PWE     (255)                                                           ///< PWE value for P52

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Superset list of all possible IO ports. */
/* BSP_IO_PORT_[TYPE][GROUP] = [PWE] << 24U | [TYPE] << 16U | [GROUP] << 8U | [PORT] */
typedef enum e_bsp_io_port_u2b6                                                                                                                                                                       /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_IO_PORT_P00  = ((BSP_IO_PORT_P00_PWE << 24U) | (0 << 16U) | (0 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                           ///< IO port P00
    BSP_IO_PORT_P02  = ((BSP_IO_PORT_P02_PWE << 24U) | (0 << 16U) | (2 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                           ///< IO port P02
    BSP_IO_PORT_P10  = ((BSP_IO_PORT_P10_PWE << 24U) | (0 << 16U) | (10 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P10
    BSP_IO_PORT_P11  = ((BSP_IO_PORT_P11_PWE << 24U) | (0 << 16U) | (11 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P11
    BSP_IO_PORT_P12  = ((BSP_IO_PORT_P12_PWE << 24U) | (0 << 16U) | (12 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P12
    BSP_IO_PORT_P13  = ((BSP_IO_PORT_P13_PWE << 24U) | (0 << 16U) | (13 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P13
    BSP_IO_PORT_P14  = ((BSP_IO_PORT_P14_PWE << 24U) | (0 << 16U) | (14 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P14
    BSP_IO_PORT_P20  = ((BSP_IO_PORT_P20_PWE << 24U) | (0 << 16U) | (20 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P20
    BSP_IO_PORT_P21  = ((BSP_IO_PORT_P21_PWE << 24U) | (0 << 16U) | (21 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P21
    BSP_IO_PORT_P22  = ((BSP_IO_PORT_P22_PWE << 24U) | (0 << 16U) | (22 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P22
    BSP_IO_PORT_P23  = ((BSP_IO_PORT_P23_PWE << 24U) | (0 << 16U) | (23 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P23
    BSP_IO_PORT_P25  = ((BSP_IO_PORT_P25_PWE << 24U) | (0 << 16U) | (25 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P25
    BSP_IO_PORT_P32  = ((BSP_IO_PORT_P32_PWE << 24U) | (0 << 16U) | (32 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P32
    BSP_IO_PORT_P33  = ((BSP_IO_PORT_P33_PWE << 24U) | (0 << 16U) | (33 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P33
    BSP_IO_PORT_P34  = ((BSP_IO_PORT_P34_PWE << 24U) | (0 << 16U) | (34 << 8U) | 0), /* PRQA S 0499, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P34
    BSP_IO_PORT_P27  = ((BSP_IO_PORT_P27_PWE << 24U) | (0 << 16U) | (27 << 8U) | 0), /* PRQA S 4543, 0499, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1 */                          ///< IO port P27
    BSP_IO_PORT_JP00 = ((BSP_IO_PORT_JP00_PWE << 24U) | (1 << 16U) | (0 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port JP00
    BSP_IO_PORT_P40  = ((BSP_IO_PORT_P40_PWE << 24U) | (0 << 16U) | (40 << 8U) | 0), /* PRQA S 0499, 4532, 4543, 4542 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P40
    BSP_IO_PORT_P37  = ((BSP_IO_PORT_P37_PWE << 24U) | (0 << 16U) | (37 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P37
    BSP_IO_PORT_P38  = ((BSP_IO_PORT_P38_PWE << 24U) | (0 << 16U) | (38 << 8U) | 0), /* PRQA S 0499, 4532, 4542, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */ ///< IO port P38
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
} bsp_io_port_t;

/** Superset list of all possible IO port pins. */
typedef enum e_bsp_io_port_pin_u2b6                                                                                                                                                                   /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_IO_PORT_P00_PIN_0 = (BSP_IO_PORT_P00 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P00 pin 0
    BSP_IO_PORT_P00_PIN_1 = (BSP_IO_PORT_P00 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P00 pin 1
    BSP_IO_PORT_P00_PIN_2 = (BSP_IO_PORT_P00 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P00 pin 2
    BSP_IO_PORT_P00_PIN_3 = (BSP_IO_PORT_P00 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P00 pin 3
    BSP_IO_PORT_P00_PIN_4 = (BSP_IO_PORT_P00 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P00 pin 4
    BSP_IO_PORT_P00_PIN_5 = (BSP_IO_PORT_P00 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P00 pin 5
    BSP_IO_PORT_P00_PIN_6 = (BSP_IO_PORT_P00 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P00 pin 6
    BSP_IO_PORT_P00_PIN_7 = (BSP_IO_PORT_P00 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P00 pin 7

    BSP_IO_PORT_P02_PIN_0  = (BSP_IO_PORT_P02 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 0
    BSP_IO_PORT_P02_PIN_1  = (BSP_IO_PORT_P02 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 1
    BSP_IO_PORT_P02_PIN_2  = (BSP_IO_PORT_P02 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 2
    BSP_IO_PORT_P02_PIN_3  = (BSP_IO_PORT_P02 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 3
    BSP_IO_PORT_P02_PIN_4  = (BSP_IO_PORT_P02 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 4
    BSP_IO_PORT_P02_PIN_5  = (BSP_IO_PORT_P02 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 5
    BSP_IO_PORT_P02_PIN_6  = (BSP_IO_PORT_P02 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 6
    BSP_IO_PORT_P02_PIN_7  = (BSP_IO_PORT_P02 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 7
    BSP_IO_PORT_P02_PIN_8  = (BSP_IO_PORT_P02 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 8
    BSP_IO_PORT_P02_PIN_9  = (BSP_IO_PORT_P02 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 9
    BSP_IO_PORT_P02_PIN_10 = (BSP_IO_PORT_P02 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P02 pin 10

    BSP_IO_PORT_P10_PIN_0 = (BSP_IO_PORT_P10 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P10 pin 0
    BSP_IO_PORT_P10_PIN_1 = (BSP_IO_PORT_P10 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P10 pin 1
    BSP_IO_PORT_P10_PIN_2 = (BSP_IO_PORT_P10 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P10 pin 2
    BSP_IO_PORT_P10_PIN_3 = (BSP_IO_PORT_P10 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P10 pin 3
    BSP_IO_PORT_P10_PIN_4 = (BSP_IO_PORT_P10 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P10 pin 4
    BSP_IO_PORT_P10_PIN_5 = (BSP_IO_PORT_P10 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P10 pin 5
    BSP_IO_PORT_P10_PIN_6 = (BSP_IO_PORT_P10 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P10 pin 6
    BSP_IO_PORT_P10_PIN_7 = (BSP_IO_PORT_P10 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P10 pin 7
    BSP_IO_PORT_P10_PIN_8 = (BSP_IO_PORT_P10 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P10 pin 8

    BSP_IO_PORT_P11_PIN_0  = (BSP_IO_PORT_P11 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 0
    BSP_IO_PORT_P11_PIN_1  = (BSP_IO_PORT_P11 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 1
    BSP_IO_PORT_P11_PIN_2  = (BSP_IO_PORT_P11 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 2
    BSP_IO_PORT_P11_PIN_3  = (BSP_IO_PORT_P11 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 3
    BSP_IO_PORT_P11_PIN_4  = (BSP_IO_PORT_P11 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 4
    BSP_IO_PORT_P11_PIN_5  = (BSP_IO_PORT_P11 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 5
    BSP_IO_PORT_P11_PIN_6  = (BSP_IO_PORT_P11 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 6
    BSP_IO_PORT_P11_PIN_7  = (BSP_IO_PORT_P11 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 7
    BSP_IO_PORT_P11_PIN_8  = (BSP_IO_PORT_P11 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 8
    BSP_IO_PORT_P11_PIN_9  = (BSP_IO_PORT_P11 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 9
    BSP_IO_PORT_P11_PIN_10 = (BSP_IO_PORT_P11 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P11 pin 10

    BSP_IO_PORT_P12_PIN_0 = (BSP_IO_PORT_P12 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P12 pin 0
    BSP_IO_PORT_P12_PIN_1 = (BSP_IO_PORT_P12 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P12 pin 1
    BSP_IO_PORT_P12_PIN_2 = (BSP_IO_PORT_P12 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P12 pin 2
    BSP_IO_PORT_P12_PIN_3 = (BSP_IO_PORT_P12 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P12 pin 3
    BSP_IO_PORT_P12_PIN_4 = (BSP_IO_PORT_P12 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P12 pin 4
    BSP_IO_PORT_P12_PIN_5 = (BSP_IO_PORT_P12 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P12 pin 5
    BSP_IO_PORT_P12_PIN_6 = (BSP_IO_PORT_P12 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P12 pin 6
    BSP_IO_PORT_P12_PIN_7 = (BSP_IO_PORT_P12 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P12 pin 7
    BSP_IO_PORT_P12_PIN_8 = (BSP_IO_PORT_P12 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P12 pin 8
    BSP_IO_PORT_P12_PIN_9 = (BSP_IO_PORT_P12 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P12 pin 9

    BSP_IO_PORT_P13_PIN_0 = (BSP_IO_PORT_P13 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P13 pin 0
    BSP_IO_PORT_P13_PIN_1 = (BSP_IO_PORT_P13 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P13 pin 1
    BSP_IO_PORT_P13_PIN_2 = (BSP_IO_PORT_P13 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P13 pin 2
    BSP_IO_PORT_P13_PIN_3 = (BSP_IO_PORT_P13 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P13 pin 3

    BSP_IO_PORT_P14_PIN_0 = (BSP_IO_PORT_P14 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P14 pin 0
    BSP_IO_PORT_P14_PIN_1 = (BSP_IO_PORT_P14 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P14 pin 1
    BSP_IO_PORT_P14_PIN_2 = (BSP_IO_PORT_P14 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P14 pin 2
    BSP_IO_PORT_P14_PIN_3 = (BSP_IO_PORT_P14 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P14 pin 3
    BSP_IO_PORT_P14_PIN_4 = (BSP_IO_PORT_P14 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P14 pin 4
    BSP_IO_PORT_P14_PIN_5 = (BSP_IO_PORT_P14 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P14 pin 5

    BSP_IO_PORT_P20_PIN_0 = (BSP_IO_PORT_P20 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P20 pin 0
    BSP_IO_PORT_P20_PIN_1 = (BSP_IO_PORT_P20 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P20 pin 1
    BSP_IO_PORT_P20_PIN_2 = (BSP_IO_PORT_P20 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P20 pin 2
    BSP_IO_PORT_P20_PIN_3 = (BSP_IO_PORT_P20 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P20 pin 3
    BSP_IO_PORT_P20_PIN_4 = (BSP_IO_PORT_P20 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P20 pin 4
    BSP_IO_PORT_P20_PIN_5 = (BSP_IO_PORT_P20 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P20 pin 5
    BSP_IO_PORT_P20_PIN_6 = (BSP_IO_PORT_P20 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P20 pin 6
    BSP_IO_PORT_P20_PIN_7 = (BSP_IO_PORT_P20 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P20 pin 7

    BSP_IO_PORT_P21_PIN_2 = (BSP_IO_PORT_P21 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P21 pin 2
    BSP_IO_PORT_P21_PIN_3 = (BSP_IO_PORT_P21 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P21 pin 3
    BSP_IO_PORT_P21_PIN_4 = (BSP_IO_PORT_P21 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P21 pin 4
    BSP_IO_PORT_P21_PIN_5 = (BSP_IO_PORT_P21 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P21 pin 5

    BSP_IO_PORT_P22_PIN_0  = (BSP_IO_PORT_P22 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 0
    BSP_IO_PORT_P22_PIN_1  = (BSP_IO_PORT_P22 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 1
    BSP_IO_PORT_P22_PIN_2  = (BSP_IO_PORT_P22 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 2
    BSP_IO_PORT_P22_PIN_3  = (BSP_IO_PORT_P22 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 3
    BSP_IO_PORT_P22_PIN_4  = (BSP_IO_PORT_P22 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 4
    BSP_IO_PORT_P22_PIN_5  = (BSP_IO_PORT_P22 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 5
    BSP_IO_PORT_P22_PIN_6  = (BSP_IO_PORT_P22 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 6
    BSP_IO_PORT_P22_PIN_7  = (BSP_IO_PORT_P22 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 7
    BSP_IO_PORT_P22_PIN_8  = (BSP_IO_PORT_P22 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 8
    BSP_IO_PORT_P22_PIN_9  = (BSP_IO_PORT_P22 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 9
    BSP_IO_PORT_P22_PIN_10 = (BSP_IO_PORT_P22 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 10
    BSP_IO_PORT_P22_PIN_11 = (BSP_IO_PORT_P22 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 11
    BSP_IO_PORT_P22_PIN_12 = (BSP_IO_PORT_P22 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 12
    BSP_IO_PORT_P22_PIN_13 = (BSP_IO_PORT_P22 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P22 pin 13

    BSP_IO_PORT_P23_PIN_0 = (BSP_IO_PORT_P23 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P23 pin 0
    BSP_IO_PORT_P23_PIN_1 = (BSP_IO_PORT_P23 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P23 pin 1
    BSP_IO_PORT_P23_PIN_2 = (BSP_IO_PORT_P23 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P23 pin 2
    BSP_IO_PORT_P23_PIN_3 = (BSP_IO_PORT_P23 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P23 pin 3
    BSP_IO_PORT_P23_PIN_4 = (BSP_IO_PORT_P23 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P23 pin 4
    BSP_IO_PORT_P23_PIN_5 = (BSP_IO_PORT_P23 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P23 pin 5
    BSP_IO_PORT_P23_PIN_6 = (BSP_IO_PORT_P23 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P23 pin 6
    BSP_IO_PORT_P23_PIN_7 = (BSP_IO_PORT_P23 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P23 pin 7

    BSP_IO_PORT_P25_PIN_2 = (BSP_IO_PORT_P25 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P25 pin 2
    BSP_IO_PORT_P25_PIN_3 = (BSP_IO_PORT_P25 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P25 pin 3
    BSP_IO_PORT_P25_PIN_4 = (BSP_IO_PORT_P25 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P25 pin 4
    BSP_IO_PORT_P25_PIN_5 = (BSP_IO_PORT_P25 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P25 pin 5
    BSP_IO_PORT_P25_PIN_6 = (BSP_IO_PORT_P25 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P25 pin 6

    BSP_IO_PORT_P32_PIN_0 = (BSP_IO_PORT_P32 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P32 pin 0
    BSP_IO_PORT_P32_PIN_1 = (BSP_IO_PORT_P32 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P32 pin 1
    BSP_IO_PORT_P32_PIN_2 = (BSP_IO_PORT_P32 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P32 pin 2
    BSP_IO_PORT_P32_PIN_3 = (BSP_IO_PORT_P32 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P32 pin 3
    BSP_IO_PORT_P32_PIN_4 = (BSP_IO_PORT_P32 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P32 pin 4
    BSP_IO_PORT_P32_PIN_5 = (BSP_IO_PORT_P32 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P32 pin 5
    BSP_IO_PORT_P32_PIN_6 = (BSP_IO_PORT_P32 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P32 pin 6

    BSP_IO_PORT_P33_PIN_0 = (BSP_IO_PORT_P33 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P33 pin 0
    BSP_IO_PORT_P33_PIN_1 = (BSP_IO_PORT_P33 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P33 pin 1
    BSP_IO_PORT_P33_PIN_2 = (BSP_IO_PORT_P33 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P33 pin 2
    BSP_IO_PORT_P33_PIN_3 = (BSP_IO_PORT_P33 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P33 pin 3
    BSP_IO_PORT_P33_PIN_4 = (BSP_IO_PORT_P33 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P33 pin 4
    BSP_IO_PORT_P33_PIN_5 = (BSP_IO_PORT_P33 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P33 pin 5
    BSP_IO_PORT_P33_PIN_6 = (BSP_IO_PORT_P33 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P33 pin 6
    BSP_IO_PORT_P33_PIN_7 = (BSP_IO_PORT_P33 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P33 pin 7
    BSP_IO_PORT_P33_PIN_8 = (BSP_IO_PORT_P33 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P33 pin 8

    BSP_IO_PORT_P34_PIN_0 = (BSP_IO_PORT_P34 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P34 pin 0
    BSP_IO_PORT_P34_PIN_1 = (BSP_IO_PORT_P34 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P34 pin 1
    BSP_IO_PORT_P34_PIN_2 = (BSP_IO_PORT_P34 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P34 pin 2
    BSP_IO_PORT_P34_PIN_3 = (BSP_IO_PORT_P34 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P34 pin 3
    BSP_IO_PORT_P34_PIN_4 = (BSP_IO_PORT_P34 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P34 pin 4

    BSP_IO_PORT_P27_PIN_0 = (BSP_IO_PORT_P27 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                   ///< IO port P27 pin 0

    BSP_IO_PORT_JP00_PIN_0 = (BSP_IO_PORT_JP00 | 0x0), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                 ///< IO port JP00 pin 0
    BSP_IO_PORT_JP00_PIN_1 = (BSP_IO_PORT_JP00 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                 ///< IO port JP00 pin 1
    BSP_IO_PORT_JP00_PIN_2 = (BSP_IO_PORT_JP00 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                 ///< IO port JP00 pin 2
    BSP_IO_PORT_JP00_PIN_3 = (BSP_IO_PORT_JP00 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                 ///< IO port JP00 pin 3
    BSP_IO_PORT_JP00_PIN_5 = (BSP_IO_PORT_JP00 | 0x5), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                 ///< IO port JP00 pin 5

    BSP_IO_PORT_P40_PIN_0  = (BSP_IO_PORT_P40 | 0x0), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 0
    BSP_IO_PORT_P40_PIN_1  = (BSP_IO_PORT_P40 | 0x1), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 1
    BSP_IO_PORT_P40_PIN_2  = (BSP_IO_PORT_P40 | 0x2), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 2
    BSP_IO_PORT_P40_PIN_3  = (BSP_IO_PORT_P40 | 0x3), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 3
    BSP_IO_PORT_P40_PIN_8  = (BSP_IO_PORT_P40 | 0x8), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 8
    BSP_IO_PORT_P40_PIN_9  = (BSP_IO_PORT_P40 | 0x9), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 9
    BSP_IO_PORT_P40_PIN_10 = (BSP_IO_PORT_P40 | 0xA), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 10
    BSP_IO_PORT_P40_PIN_11 = (BSP_IO_PORT_P40 | 0xB), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 11
    BSP_IO_PORT_P40_PIN_12 = (BSP_IO_PORT_P40 | 0xC), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 12
    BSP_IO_PORT_P40_PIN_13 = (BSP_IO_PORT_P40 | 0xD), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 13
    BSP_IO_PORT_P40_PIN_14 = (BSP_IO_PORT_P40 | 0xE), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 14
    BSP_IO_PORT_P40_PIN_15 = (BSP_IO_PORT_P40 | 0xF), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 15
    BSP_IO_PORT_P40_PIN_4  = (BSP_IO_PORT_P40 | 0x4), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 4
    BSP_IO_PORT_P40_PIN_5  = (BSP_IO_PORT_P40 | 0x5), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 5
    BSP_IO_PORT_P40_PIN_6  = (BSP_IO_PORT_P40 | 0x6), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 6
    BSP_IO_PORT_P40_PIN_7  = (BSP_IO_PORT_P40 | 0x7), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P40 pin 7

    BSP_IO_PORT_P37_PIN_0  = (BSP_IO_PORT_P37 | 0x0), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 0
    BSP_IO_PORT_P37_PIN_1  = (BSP_IO_PORT_P37 | 0x1), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 1
    BSP_IO_PORT_P37_PIN_2  = (BSP_IO_PORT_P37 | 0x2), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 2
    BSP_IO_PORT_P37_PIN_3  = (BSP_IO_PORT_P37 | 0x3), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 3
    BSP_IO_PORT_P37_PIN_4  = (BSP_IO_PORT_P37 | 0x4), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 4
    BSP_IO_PORT_P37_PIN_5  = (BSP_IO_PORT_P37 | 0x5), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 5
    BSP_IO_PORT_P37_PIN_6  = (BSP_IO_PORT_P37 | 0x6), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 6
    BSP_IO_PORT_P37_PIN_7  = (BSP_IO_PORT_P37 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 7
    BSP_IO_PORT_P37_PIN_8  = (BSP_IO_PORT_P37 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 8
    BSP_IO_PORT_P37_PIN_9  = (BSP_IO_PORT_P37 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 9
    BSP_IO_PORT_P37_PIN_10 = (BSP_IO_PORT_P37 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 10
    BSP_IO_PORT_P37_PIN_11 = (BSP_IO_PORT_P37 | 0xB), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 11
    BSP_IO_PORT_P37_PIN_12 = (BSP_IO_PORT_P37 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 12
    BSP_IO_PORT_P37_PIN_13 = (BSP_IO_PORT_P37 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 13
    BSP_IO_PORT_P37_PIN_14 = (BSP_IO_PORT_P37 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 14
    BSP_IO_PORT_P37_PIN_15 = (BSP_IO_PORT_P37 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P37 pin 15

    BSP_IO_PORT_P38_PIN_0  = (BSP_IO_PORT_P38 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 0
    BSP_IO_PORT_P38_PIN_1  = (BSP_IO_PORT_P38 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 1
    BSP_IO_PORT_P38_PIN_2  = (BSP_IO_PORT_P38 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 2
    BSP_IO_PORT_P38_PIN_3  = (BSP_IO_PORT_P38 | 0x3), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 3
    BSP_IO_PORT_P38_PIN_4  = (BSP_IO_PORT_P38 | 0x4), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 4
    BSP_IO_PORT_P38_PIN_5  = (BSP_IO_PORT_P38 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 5
    BSP_IO_PORT_P38_PIN_6  = (BSP_IO_PORT_P38 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 6
    BSP_IO_PORT_P38_PIN_7  = (BSP_IO_PORT_P38 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 7
    BSP_IO_PORT_P38_PIN_8  = (BSP_IO_PORT_P38 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 8
    BSP_IO_PORT_P38_PIN_9  = (BSP_IO_PORT_P38 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 9
    BSP_IO_PORT_P38_PIN_10 = (BSP_IO_PORT_P38 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 10
    BSP_IO_PORT_P38_PIN_11 = (BSP_IO_PORT_P38 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 11
    BSP_IO_PORT_P38_PIN_12 = (BSP_IO_PORT_P38 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 12
    BSP_IO_PORT_P38_PIN_13 = (BSP_IO_PORT_P38 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 13
    BSP_IO_PORT_P38_PIN_14 = (BSP_IO_PORT_P38 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 14
    BSP_IO_PORT_P38_PIN_15 = (BSP_IO_PORT_P38 | 0xF), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P38 pin 15

    BSP_IO_PORT_P41_PIN_0  = (BSP_IO_PORT_P41 | 0x0), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 0
    BSP_IO_PORT_P41_PIN_1  = (BSP_IO_PORT_P41 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 1
    BSP_IO_PORT_P41_PIN_2  = (BSP_IO_PORT_P41 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 2
    BSP_IO_PORT_P41_PIN_3  = (BSP_IO_PORT_P41 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 3
    BSP_IO_PORT_P41_PIN_4  = (BSP_IO_PORT_P41 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 4
    BSP_IO_PORT_P41_PIN_5  = (BSP_IO_PORT_P41 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 5
    BSP_IO_PORT_P41_PIN_6  = (BSP_IO_PORT_P41 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 6
    BSP_IO_PORT_P41_PIN_7  = (BSP_IO_PORT_P41 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 7
    BSP_IO_PORT_P41_PIN_8  = (BSP_IO_PORT_P41 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 8
    BSP_IO_PORT_P41_PIN_9  = (BSP_IO_PORT_P41 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 9
    BSP_IO_PORT_P41_PIN_10 = (BSP_IO_PORT_P41 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 10
    BSP_IO_PORT_P41_PIN_11 = (BSP_IO_PORT_P41 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 11
    BSP_IO_PORT_P41_PIN_12 = (BSP_IO_PORT_P41 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 12
    BSP_IO_PORT_P41_PIN_13 = (BSP_IO_PORT_P41 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 13
    BSP_IO_PORT_P41_PIN_14 = (BSP_IO_PORT_P41 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 14
    BSP_IO_PORT_P41_PIN_15 = (BSP_IO_PORT_P41 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P41 pin 15

    BSP_IO_PORT_P42_PIN_0  = (BSP_IO_PORT_P42 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 0
    BSP_IO_PORT_P42_PIN_1  = (BSP_IO_PORT_P42 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 1
    BSP_IO_PORT_P42_PIN_2  = (BSP_IO_PORT_P42 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 2
    BSP_IO_PORT_P42_PIN_3  = (BSP_IO_PORT_P42 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 3
    BSP_IO_PORT_P42_PIN_4  = (BSP_IO_PORT_P42 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 4
    BSP_IO_PORT_P42_PIN_5  = (BSP_IO_PORT_P42 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 5
    BSP_IO_PORT_P42_PIN_6  = (BSP_IO_PORT_P42 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 6
    BSP_IO_PORT_P42_PIN_7  = (BSP_IO_PORT_P42 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 7
    BSP_IO_PORT_P42_PIN_8  = (BSP_IO_PORT_P42 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 8
    BSP_IO_PORT_P42_PIN_9  = (BSP_IO_PORT_P42 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 9
    BSP_IO_PORT_P42_PIN_10 = (BSP_IO_PORT_P42 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 10
    BSP_IO_PORT_P42_PIN_11 = (BSP_IO_PORT_P42 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 11
    BSP_IO_PORT_P42_PIN_12 = (BSP_IO_PORT_P42 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 12
    BSP_IO_PORT_P42_PIN_13 = (BSP_IO_PORT_P42 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 13
    BSP_IO_PORT_P42_PIN_14 = (BSP_IO_PORT_P42 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 14
    BSP_IO_PORT_P42_PIN_15 = (BSP_IO_PORT_P42 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P42 pin 15

    BSP_IO_PORT_P43_PIN_0  = (BSP_IO_PORT_P43 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 0
    BSP_IO_PORT_P43_PIN_1  = (BSP_IO_PORT_P43 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 1
    BSP_IO_PORT_P43_PIN_2  = (BSP_IO_PORT_P43 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 2
    BSP_IO_PORT_P43_PIN_3  = (BSP_IO_PORT_P43 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 3
    BSP_IO_PORT_P43_PIN_4  = (BSP_IO_PORT_P43 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 4
    BSP_IO_PORT_P43_PIN_5  = (BSP_IO_PORT_P43 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 5
    BSP_IO_PORT_P43_PIN_6  = (BSP_IO_PORT_P43 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 6
    BSP_IO_PORT_P43_PIN_7  = (BSP_IO_PORT_P43 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 7
    BSP_IO_PORT_P43_PIN_8  = (BSP_IO_PORT_P43 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 8
    BSP_IO_PORT_P43_PIN_9  = (BSP_IO_PORT_P43 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 9
    BSP_IO_PORT_P43_PIN_10 = (BSP_IO_PORT_P43 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 10
    BSP_IO_PORT_P43_PIN_11 = (BSP_IO_PORT_P43 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 11
    BSP_IO_PORT_P43_PIN_12 = (BSP_IO_PORT_P43 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 12
    BSP_IO_PORT_P43_PIN_13 = (BSP_IO_PORT_P43 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 13
    BSP_IO_PORT_P43_PIN_14 = (BSP_IO_PORT_P43 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 14
    BSP_IO_PORT_P43_PIN_15 = (BSP_IO_PORT_P43 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P43 pin 15

    BSP_IO_PORT_P44_PIN_0  = (BSP_IO_PORT_P44 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 0
    BSP_IO_PORT_P44_PIN_1  = (BSP_IO_PORT_P44 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 1
    BSP_IO_PORT_P44_PIN_2  = (BSP_IO_PORT_P44 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 2
    BSP_IO_PORT_P44_PIN_3  = (BSP_IO_PORT_P44 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 3
    BSP_IO_PORT_P44_PIN_4  = (BSP_IO_PORT_P44 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 4
    BSP_IO_PORT_P44_PIN_5  = (BSP_IO_PORT_P44 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 5
    BSP_IO_PORT_P44_PIN_6  = (BSP_IO_PORT_P44 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 6
    BSP_IO_PORT_P44_PIN_7  = (BSP_IO_PORT_P44 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 7
    BSP_IO_PORT_P44_PIN_8  = (BSP_IO_PORT_P44 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 8
    BSP_IO_PORT_P44_PIN_9  = (BSP_IO_PORT_P44 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 9
    BSP_IO_PORT_P44_PIN_10 = (BSP_IO_PORT_P44 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 10
    BSP_IO_PORT_P44_PIN_11 = (BSP_IO_PORT_P44 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 11
    BSP_IO_PORT_P44_PIN_12 = (BSP_IO_PORT_P44 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 12
    BSP_IO_PORT_P44_PIN_13 = (BSP_IO_PORT_P44 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 13
    BSP_IO_PORT_P44_PIN_14 = (BSP_IO_PORT_P44 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 14
    BSP_IO_PORT_P44_PIN_15 = (BSP_IO_PORT_P44 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P44 pin 15

    BSP_IO_PORT_P45_PIN_0  = (BSP_IO_PORT_P45 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 0
    BSP_IO_PORT_P45_PIN_1  = (BSP_IO_PORT_P45 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 1
    BSP_IO_PORT_P45_PIN_2  = (BSP_IO_PORT_P45 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 2
    BSP_IO_PORT_P45_PIN_3  = (BSP_IO_PORT_P45 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 3
    BSP_IO_PORT_P45_PIN_4  = (BSP_IO_PORT_P45 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 4
    BSP_IO_PORT_P45_PIN_5  = (BSP_IO_PORT_P45 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 5
    BSP_IO_PORT_P45_PIN_6  = (BSP_IO_PORT_P45 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 6
    BSP_IO_PORT_P45_PIN_7  = (BSP_IO_PORT_P45 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 7
    BSP_IO_PORT_P45_PIN_8  = (BSP_IO_PORT_P45 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 8
    BSP_IO_PORT_P45_PIN_9  = (BSP_IO_PORT_P45 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 9
    BSP_IO_PORT_P45_PIN_10 = (BSP_IO_PORT_P45 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 10
    BSP_IO_PORT_P45_PIN_11 = (BSP_IO_PORT_P45 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 11
    BSP_IO_PORT_P45_PIN_12 = (BSP_IO_PORT_P45 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 12
    BSP_IO_PORT_P45_PIN_13 = (BSP_IO_PORT_P45 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 13
    BSP_IO_PORT_P45_PIN_14 = (BSP_IO_PORT_P45 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 14
    BSP_IO_PORT_P45_PIN_15 = (BSP_IO_PORT_P45 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P45 pin 15

    BSP_IO_PORT_P46_PIN_0  = (BSP_IO_PORT_P46 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 0
    BSP_IO_PORT_P46_PIN_1  = (BSP_IO_PORT_P46 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 1
    BSP_IO_PORT_P46_PIN_2  = (BSP_IO_PORT_P46 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 2
    BSP_IO_PORT_P46_PIN_3  = (BSP_IO_PORT_P46 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 3
    BSP_IO_PORT_P46_PIN_4  = (BSP_IO_PORT_P46 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 4
    BSP_IO_PORT_P46_PIN_5  = (BSP_IO_PORT_P46 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 5
    BSP_IO_PORT_P46_PIN_6  = (BSP_IO_PORT_P46 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 6
    BSP_IO_PORT_P46_PIN_7  = (BSP_IO_PORT_P46 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 7
    BSP_IO_PORT_P46_PIN_8  = (BSP_IO_PORT_P46 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 8
    BSP_IO_PORT_P46_PIN_9  = (BSP_IO_PORT_P46 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 9
    BSP_IO_PORT_P46_PIN_10 = (BSP_IO_PORT_P46 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 10
    BSP_IO_PORT_P46_PIN_11 = (BSP_IO_PORT_P46 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 11
    BSP_IO_PORT_P46_PIN_12 = (BSP_IO_PORT_P46 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 12
    BSP_IO_PORT_P46_PIN_13 = (BSP_IO_PORT_P46 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 13
    BSP_IO_PORT_P46_PIN_14 = (BSP_IO_PORT_P46 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 14
    BSP_IO_PORT_P46_PIN_15 = (BSP_IO_PORT_P46 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P46 pin 15

    BSP_IO_PORT_P47_PIN_0  = (BSP_IO_PORT_P47 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 0
    BSP_IO_PORT_P47_PIN_1  = (BSP_IO_PORT_P47 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 1
    BSP_IO_PORT_P47_PIN_2  = (BSP_IO_PORT_P47 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 2
    BSP_IO_PORT_P47_PIN_3  = (BSP_IO_PORT_P47 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 3
    BSP_IO_PORT_P47_PIN_4  = (BSP_IO_PORT_P47 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 4
    BSP_IO_PORT_P47_PIN_5  = (BSP_IO_PORT_P47 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 5
    BSP_IO_PORT_P47_PIN_6  = (BSP_IO_PORT_P47 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 6
    BSP_IO_PORT_P47_PIN_7  = (BSP_IO_PORT_P47 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 7
    BSP_IO_PORT_P47_PIN_8  = (BSP_IO_PORT_P47 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 8
    BSP_IO_PORT_P47_PIN_9  = (BSP_IO_PORT_P47 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 9
    BSP_IO_PORT_P47_PIN_10 = (BSP_IO_PORT_P47 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 10
    BSP_IO_PORT_P47_PIN_11 = (BSP_IO_PORT_P47 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 11
    BSP_IO_PORT_P47_PIN_12 = (BSP_IO_PORT_P47 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 12
    BSP_IO_PORT_P47_PIN_13 = (BSP_IO_PORT_P47 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 13
    BSP_IO_PORT_P47_PIN_14 = (BSP_IO_PORT_P47 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 14
    BSP_IO_PORT_P47_PIN_15 = (BSP_IO_PORT_P47 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P47 pin 15

    BSP_IO_PORT_P48_PIN_0  = (BSP_IO_PORT_P48 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 0
    BSP_IO_PORT_P48_PIN_1  = (BSP_IO_PORT_P48 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 1
    BSP_IO_PORT_P48_PIN_2  = (BSP_IO_PORT_P48 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 2
    BSP_IO_PORT_P48_PIN_3  = (BSP_IO_PORT_P48 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 3
    BSP_IO_PORT_P48_PIN_4  = (BSP_IO_PORT_P48 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 4
    BSP_IO_PORT_P48_PIN_5  = (BSP_IO_PORT_P48 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 5
    BSP_IO_PORT_P48_PIN_6  = (BSP_IO_PORT_P48 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 6
    BSP_IO_PORT_P48_PIN_7  = (BSP_IO_PORT_P48 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 7
    BSP_IO_PORT_P48_PIN_8  = (BSP_IO_PORT_P48 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 8
    BSP_IO_PORT_P48_PIN_9  = (BSP_IO_PORT_P48 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 9
    BSP_IO_PORT_P48_PIN_10 = (BSP_IO_PORT_P48 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 10
    BSP_IO_PORT_P48_PIN_11 = (BSP_IO_PORT_P48 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 11
    BSP_IO_PORT_P48_PIN_12 = (BSP_IO_PORT_P48 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 12
    BSP_IO_PORT_P48_PIN_13 = (BSP_IO_PORT_P48 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 13
    BSP_IO_PORT_P48_PIN_14 = (BSP_IO_PORT_P48 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 14
    BSP_IO_PORT_P48_PIN_15 = (BSP_IO_PORT_P48 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P48 pin 15

    BSP_IO_PORT_P49_PIN_0  = (BSP_IO_PORT_P49 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 0
    BSP_IO_PORT_P49_PIN_1  = (BSP_IO_PORT_P49 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 1
    BSP_IO_PORT_P49_PIN_2  = (BSP_IO_PORT_P49 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 2
    BSP_IO_PORT_P49_PIN_3  = (BSP_IO_PORT_P49 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 3
    BSP_IO_PORT_P49_PIN_4  = (BSP_IO_PORT_P49 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 4
    BSP_IO_PORT_P49_PIN_5  = (BSP_IO_PORT_P49 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 5
    BSP_IO_PORT_P49_PIN_6  = (BSP_IO_PORT_P49 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 6
    BSP_IO_PORT_P49_PIN_7  = (BSP_IO_PORT_P49 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 7
    BSP_IO_PORT_P49_PIN_8  = (BSP_IO_PORT_P49 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 8
    BSP_IO_PORT_P49_PIN_9  = (BSP_IO_PORT_P49 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 9
    BSP_IO_PORT_P49_PIN_10 = (BSP_IO_PORT_P49 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 10
    BSP_IO_PORT_P49_PIN_11 = (BSP_IO_PORT_P49 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 11
    BSP_IO_PORT_P49_PIN_12 = (BSP_IO_PORT_P49 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 12
    BSP_IO_PORT_P49_PIN_13 = (BSP_IO_PORT_P49 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 13
    BSP_IO_PORT_P49_PIN_14 = (BSP_IO_PORT_P49 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 14
    BSP_IO_PORT_P49_PIN_15 = (BSP_IO_PORT_P49 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P49 pin 15

    BSP_IO_PORT_P50_PIN_0  = (BSP_IO_PORT_P50 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 0
    BSP_IO_PORT_P50_PIN_1  = (BSP_IO_PORT_P50 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 1
    BSP_IO_PORT_P50_PIN_2  = (BSP_IO_PORT_P50 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 2
    BSP_IO_PORT_P50_PIN_3  = (BSP_IO_PORT_P50 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 3
    BSP_IO_PORT_P50_PIN_4  = (BSP_IO_PORT_P50 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 4
    BSP_IO_PORT_P50_PIN_5  = (BSP_IO_PORT_P50 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 5
    BSP_IO_PORT_P50_PIN_6  = (BSP_IO_PORT_P50 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 6
    BSP_IO_PORT_P50_PIN_7  = (BSP_IO_PORT_P50 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 7
    BSP_IO_PORT_P50_PIN_8  = (BSP_IO_PORT_P50 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 8
    BSP_IO_PORT_P50_PIN_9  = (BSP_IO_PORT_P50 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 9
    BSP_IO_PORT_P50_PIN_10 = (BSP_IO_PORT_P50 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 10
    BSP_IO_PORT_P50_PIN_11 = (BSP_IO_PORT_P50 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 11
    BSP_IO_PORT_P50_PIN_12 = (BSP_IO_PORT_P50 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 12
    BSP_IO_PORT_P50_PIN_13 = (BSP_IO_PORT_P50 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 13
    BSP_IO_PORT_P50_PIN_14 = (BSP_IO_PORT_P50 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 14
    BSP_IO_PORT_P50_PIN_15 = (BSP_IO_PORT_P50 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P50 pin 15

    BSP_IO_PORT_P51_PIN_0  = (BSP_IO_PORT_P51 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 0
    BSP_IO_PORT_P51_PIN_1  = (BSP_IO_PORT_P51 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 1
    BSP_IO_PORT_P51_PIN_2  = (BSP_IO_PORT_P51 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 2
    BSP_IO_PORT_P51_PIN_3  = (BSP_IO_PORT_P51 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 3
    BSP_IO_PORT_P51_PIN_4  = (BSP_IO_PORT_P51 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 4
    BSP_IO_PORT_P51_PIN_5  = (BSP_IO_PORT_P51 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 5
    BSP_IO_PORT_P51_PIN_6  = (BSP_IO_PORT_P51 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 6
    BSP_IO_PORT_P51_PIN_7  = (BSP_IO_PORT_P51 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 7
    BSP_IO_PORT_P51_PIN_8  = (BSP_IO_PORT_P51 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 8
    BSP_IO_PORT_P51_PIN_9  = (BSP_IO_PORT_P51 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 9
    BSP_IO_PORT_P51_PIN_10 = (BSP_IO_PORT_P51 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 10
    BSP_IO_PORT_P51_PIN_11 = (BSP_IO_PORT_P51 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 11
    BSP_IO_PORT_P51_PIN_12 = (BSP_IO_PORT_P51 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 12
    BSP_IO_PORT_P51_PIN_13 = (BSP_IO_PORT_P51 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 13
    BSP_IO_PORT_P51_PIN_14 = (BSP_IO_PORT_P51 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 14
    BSP_IO_PORT_P51_PIN_15 = (BSP_IO_PORT_P51 | 0xF), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P51 pin 15

    BSP_IO_PORT_P52_PIN_0  = (BSP_IO_PORT_P52 | 0x0), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 0
    BSP_IO_PORT_P52_PIN_1  = (BSP_IO_PORT_P52 | 0x1), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 1
    BSP_IO_PORT_P52_PIN_2  = (BSP_IO_PORT_P52 | 0x2), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 2
    BSP_IO_PORT_P52_PIN_3  = (BSP_IO_PORT_P52 | 0x3), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 3
    BSP_IO_PORT_P52_PIN_4  = (BSP_IO_PORT_P52 | 0x4), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 4
    BSP_IO_PORT_P52_PIN_5  = (BSP_IO_PORT_P52 | 0x5), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 5
    BSP_IO_PORT_P52_PIN_6  = (BSP_IO_PORT_P52 | 0x6), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 6
    BSP_IO_PORT_P52_PIN_7  = (BSP_IO_PORT_P52 | 0x7), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 7
    BSP_IO_PORT_P52_PIN_8  = (BSP_IO_PORT_P52 | 0x8), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 8
    BSP_IO_PORT_P52_PIN_9  = (BSP_IO_PORT_P52 | 0x9), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 9
    BSP_IO_PORT_P52_PIN_10 = (BSP_IO_PORT_P52 | 0xA), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 10
    BSP_IO_PORT_P52_PIN_11 = (BSP_IO_PORT_P52 | 0xB), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 11
    BSP_IO_PORT_P52_PIN_12 = (BSP_IO_PORT_P52 | 0xC), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 12
    BSP_IO_PORT_P52_PIN_13 = (BSP_IO_PORT_P52 | 0xD), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 13
    BSP_IO_PORT_P52_PIN_14 = (BSP_IO_PORT_P52 | 0xE), /* PRQA S 4522, 4542 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 14
    BSP_IO_PORT_P52_PIN_15 = (BSP_IO_PORT_P52 | 0xF), /* PRQA S 4542, 4522 # DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1 */                                                                                  ///< IO port P52 pin 15
} bsp_io_port_pin_t;

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
