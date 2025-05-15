/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_wdt.h
 * Version      : 1.00
 * Description  : bsp_wdt header
 *********************************************************************************************************************/

#ifndef BSP_WDT_H
#define BSP_WDT_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * @addtogroup BSP_MPU_RZV2N
 * @{
 *********************************************************************************************************************/

/* Enable or disable WDT Counting */
#define R_BSP_WDT_COUNTING_ENABLE(ch, en)            \
    do {                                             \
        if (0 == ch) {                               \
            R_SYSC->SYS_WDT0_CTRL_b.bp_halted = !en; \
        }                                            \
        else if (1 == ch) {                          \
            R_SYSC->SYS_WDT1_CTRL_b.bp_halted = !en; \
        }                                            \
        else if (2 == ch) {                          \
            R_SYSC->SYS_WDT2_CTRL_b.bp_halted = !en; \
        }                                            \
        else {                                       \
            R_SYSC->SYS_WDT3_CTRL_b.bp_halted = !en; \
        }                                            \
    } while (0)

/* Enable or disable WDT System Reset */
#define R_BSP_WDT_SYSTEM_RESET_ENABLE(ch, en)                                              \
    do {                                                                                   \
        R_CPG->CPG_ERRORRST_SEL2 = (en << (R_CPG_CPG_ERRORRST_SEL2_ERRRSTSEL0_Pos + ch)) | \
                                   (R_CPG_CPG_ERRORRST_SEL2_ERRRSTSEL0_WEN_Msk << ch);     \
    } while (0)

/* Enable or disable WDT Pin Assertion */
#define R_BSP_WDT_PIN_ASSERTION_ENABLE(ch, en)                                          \
    do {                                                                                \
        if (0 == ch) {                                                                  \
            R_CPG->CPG_ERRORRST_SEL1 = (en << R_CPG_CPG_ERRORRST_SEL1_ERRRSTSEL0_Pos) | \
                                       R_CPG_CPG_ERRORRST_SEL1_ERRRSTSEL0_WEN_Msk;      \
        }                                                                               \
    } while (0)

/* Enable or disable WDT Cold Reset */
#define R_BSP_WDT_COLD_RESET_ENABLE(ch, en)                                             \
    do {                                                                                \
        if (0 == ch) {                                                                  \
            R_CPG->CPG_ERRORRST_SEL1 = (en << R_CPG_CPG_ERRORRST_SEL1_ERRRSTSEL2_Pos) | \
                                       R_CPG_CPG_ERRORRST_SEL1_ERRRSTSEL2_WEN_Msk;      \
        }                                                                               \
    } while (0)

/** @} (end addtogroup BSP_MPU_RZV2N) */

#endif                                 /* BSP_WDT_H */
