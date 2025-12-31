/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
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
 * @addtogroup BSP_MPU_RZG2UL
 * @{
 *********************************************************************************************************************/

/* Enable or disable WDT Counting */
#define R_BSP_WDT_COUNTING_ENABLE(ch, en)          \
    do {                                           \
        if (0 == ch) {                             \
            R_SYSC->SYS_WDT0_CTRL_b.WDTSTOP = !en; \
        }                                          \
        else {                                     \
            R_SYSC->SYS_WDT2_CTRL_b.WDTSTOP = !en; \
        }                                          \
    } while (0)

/* Enable or disable WDT System Reset */
#define R_BSP_WDT_SYSTEM_RESET_ENABLE(ch, en)                                                       \
    do {                                                                                            \
        if (en) {                                                                                   \
            R_CPG->CPG_WDTRST_SEL |= (en << (R_CPG_CPG_WDTRST_SEL_WDTRSTSEL0_Pos + ch));            \
        }                                                                                           \
        else {                                                                                      \
            R_CPG->CPG_WDTRST_SEL &= ~(uint32_t) (1 << (R_CPG_CPG_WDTRST_SEL_WDTRSTSEL0_Pos + ch)); \
        }                                                                                           \
    } while (0)

/* Enable or disable WDT Pin Assertion */
#define R_BSP_WDT_PIN_ASSERTION_ENABLE(ch, en)                                                      \
    do {                                                                                            \
        if (en) {                                                                                   \
            R_CPG->CPG_WDTRST_SEL |= (en << (R_CPG_CPG_WDTRST_SEL_WDTRSTSEL4_Pos + ch));            \
        }                                                                                           \
        else {                                                                                      \
            R_CPG->CPG_WDTRST_SEL &= ~(uint32_t) (1 << (R_CPG_CPG_WDTRST_SEL_WDTRSTSEL4_Pos + ch)); \
        }                                                                                           \
    } while (0)

/* Enable or disable WDT Cold Reset */
#define R_BSP_WDT_COLD_RESET_ENABLE(ch, en)                                                         \
    do {                                                                                            \
        if (en) {                                                                                   \
            R_CPG->CPG_WDTRST_SEL |= (en << (R_CPG_CPG_WDTRST_SEL_WDTRSTSEL8_Pos + ch));            \
        }                                                                                           \
        else {                                                                                      \
            R_CPG->CPG_WDTRST_SEL &= ~(uint32_t) (1 << (R_CPG_CPG_WDTRST_SEL_WDTRSTSEL8_Pos + ch)); \
        }                                                                                           \
    } while (0)

/** @} (end addtogroup BSP_MPU_RZG2UL) */

#endif                                 /* BSP_WDT_H */
