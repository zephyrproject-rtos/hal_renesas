/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_select_irq.h
 * Version      : 1.00
 * Description  : bsp_select_irq header
 *********************************************************************************************************************/

#ifndef BSP_SELECT_IRQ_H
#define BSP_SELECT_IRQ_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "fsp_features.h"

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZG
{
  #endif
 #endif

/******************************************************************************************************************//**
 * @addtogroup RZG_BSP_MCU
 *
 * @{
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/** Cause of Interrupt used to change the setting of the INTPMSEL register. */
typedef enum e_intsel_cause
{
    GPT_CMPE                    = 0,   /* DEPRECATED */
    GPT_CMPF                    = 1,   /* DEPRECATED */
    GPT_ADTRGA                  = 2,   /* DEPRECATED */
    GPT_ADTRGB                  = 3,   /* DEPRECATED */
    GPT_OVF                     = 4,   /* DEPRECATED */
    GPT_UNF                     = 5,   /* DEPRECATED */
    GPT_CAUSE_NUM               = 6,   /* DEPRECATED */
    MTU3_TGIA                   = 0,   /* DEPRECATED */
    MTU3_TGIB                   = 1,   /* DEPRECATED */
    MTU3_TGIC                   = 2,   /* DEPRECATED */
    MTU3_TGID                   = 3,   /* DEPRECATED */
    MTU3_TGIE                   = 4,   /* DEPRECATED */
    MTU3_TGIF                   = 5,   /* DEPRECATED */
    MTU3_TGIU                   = 6,   /* DEPRECATED */
    MTU3_TGIV                   = 7,   /* DEPRECATED */
    MTU3_TGIW                   = 8,   /* DEPRECATED */
    MTU3_TCIU                   = 9,   /* DEPRECATED */
    MTU3_TCIV                   = 10,  /* DEPRECATED */
    MTU3_CAUSE_NUM              = 11,  /* DEPRECATED */
    INTSEL_CAUSE_GPT_CMPE       = 0,   ///< GTCCRE compare match
    INTSEL_CAUSE_GPT_CMPF       = 1,   ///< GTCCRF compare match
    INTSEL_CAUSE_GPT_ADTRGA     = 2,   ///< GTADTRA compare match
    INTSEL_CAUSE_GPT_ADTRGB     = 3,   ///< GTADTRB compare match
    INTSEL_CAUSE_GPT_OVF        = 4,   ///< GTCNT overflow (GTPR compare match)
    INTSEL_CAUSE_GPT_UNF        = 5,   ///< GTCNT underflow
    INTSEL_CAUSE_GPT_CAUSE_NUM  = 6,   ///< The number of cause of interrupt of GPT
    INTSEL_CAUSE_MTU3_TGIA      = 0,   ///< TGRA input capture/compare match
    INTSEL_CAUSE_MTU3_TGIB      = 1,   ///< TGRB input capture/compare match
    INTSEL_CAUSE_MTU3_TGIC      = 2,   ///< TGRC input capture/compare match
    INTSEL_CAUSE_MTU3_TGID      = 3,   ///< TGRD input capture/compare match
    INTSEL_CAUSE_MTU3_TGIE      = 4,   ///< TGRE compare match
    INTSEL_CAUSE_MTU3_TGIF      = 5,   ///< TGRF compare match
    INTSEL_CAUSE_MTU3_TGIU      = 6,   ///< TGRU input capture/compare match
    INTSEL_CAUSE_MTU3_TGIV      = 7,   ///< TGRV input capture/compare match
    INTSEL_CAUSE_MTU3_TGIW      = 8,   ///< TGRW input capture/compare match
    INTSEL_CAUSE_MTU3_TCIU      = 9,   ///< TCNT underflow
    INTSEL_CAUSE_MTU3_TCIV      = 10,  ///< TCNT overflow
    INTSEL_CAUSE_MTU3_CAUSE_NUM = 11,  ///< The number of cause of interrupt of MTU3
    INTSEL_CAUSE_TINT           = 0,   ///< TINT's cause of interrupt (interrupt signal from GPIO pin)
    INTSEL_CAUSE_TINT_CAUSE_NUM = 1,   ///< The number of cause of interrupt of TINT
    INTSEL_CAUSE_IRQ            = 0,   ///< IRQ's cause of interrupt (interrupt signal from IRQ pin)
    INTSEL_CAUSE_IRQ_CAUSE_NUM  = 1,   ///< The number of cause of interrupt of IRQ
} intsel_cause_t;

/** @} (end addtogroup BSP_MCU) */

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

#if defined(BSP_FEATURE_ICU_HAS_SELECT_INT)
fsp_err_t R_BSP_CM33SelectIrqSet(IRQn_Type irq, IRQSELn_Type irqsel);

#endif

 #if defined(BSP_FEATURE_ICU_HAS_INTPMSEL_REG) || defined(BSP_FEATURE_ICU_HAS_INTTSEL_REG)
fsp_err_t R_BSP_IntCauseSelectionSet(fsp_ip_t ip, uint8_t channel, intsel_cause_t cause);

#endif

uint32_t  R_BSP_IntStatusControlGet(fsp_ip_t ip, uint8_t channel, IRQn_Type irq);
fsp_err_t R_BSP_IntStatusControlClear(fsp_ip_t ip, uint8_t channel, IRQn_Type irq, uint32_t int_source);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_SELECT_IRQ_H */
