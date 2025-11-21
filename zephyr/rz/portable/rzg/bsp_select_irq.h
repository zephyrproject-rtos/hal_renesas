/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
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

/******************************************************************************************************************//**
 * @addtogroup BSP_MCU
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
    GPT_CMPE       = 0,
    GPT_CMPF       = 1,
    GPT_ADTRGA     = 2,
    GPT_ADTRGB     = 3,
    GPT_OVF        = 4,
    GPT_UNF        = 5,
    GPT_CAUSE_NUM  = 6,
    MTU3_TGIA      = 0,
    MTU3_TGIB      = 1,
    MTU3_TGIC      = 2,
    MTU3_TGID      = 3,
    MTU3_TGIE      = 4,
    MTU3_TGIF      = 5,
    MTU3_TGIU      = 6,
    MTU3_TGIV      = 7,
    MTU3_TGIW      = 8,
    MTU3_TCIU      = 9,
    MTU3_TCIV      = 10,
    MTU3_CAUSE_NUM = 11,
} intsel_cause_t;

/** @} (end addtogroup BSP_MCU) */

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

#if defined(BSP_FEATURE_ICU_HAS_SELECT_INT)
fsp_err_t R_BSP_CM33SelectIrqSet(IRQn_Type irq, IRQSELn_Type irqsel);

#endif

#if defined(BSP_FEATURE_ICU_HAS_INTPMSEL_REG)
fsp_err_t R_BSP_IntCauseSelectionSet(fsp_ip_t ip, uint8_t channel, intsel_cause_t cause);

#endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_SELECT_IRQ_H */
