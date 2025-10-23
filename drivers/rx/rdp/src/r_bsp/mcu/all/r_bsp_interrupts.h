/*
* Copyright (c) 2011 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/***********************************************************************************************************************
* File Name    : r_bsp_interrupts.h
* Description  : This module allows for callbacks to be registered for certain interrupts. 
*                And handle exception interrupts.
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 28.02.2019 1.00     First Release
*         : 18.05.2021 1.01     Added definition for Address exceptions.
*         : 26.02.2025 1.02     Changed the disclaimer.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "platform.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Multiple inclusion prevention macro */
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/
void R_BSP_InterruptRequestEnable(uint32_t vector);
void R_BSP_InterruptRequestDisable(uint32_t vector);
bsp_int_err_t R_BSP_InterruptWrite(bsp_int_src_t vector,  bsp_int_cb_t callback);
#if defined(BSP_MCU_RX26T)    
bsp_int_err_t R_BSP_InterruptWrite_EX(bsp_int_src_t vector,  bsp_int_cb_t callback, void *context);
#endif
bsp_int_err_t R_BSP_InterruptRead(bsp_int_src_t vector, bsp_int_cb_t * callback);
bsp_int_err_t R_BSP_InterruptControl(bsp_int_src_t vector, bsp_int_cmd_t cmd, void * pdata);

void bsp_interrupt_open(void); //r_bsp internal function. DO NOT CALL.

#ifdef BSP_MCU_EXCEP_SUPERVISOR_INST_ISR
R_BSP_PRAGMA_INTERRUPT_FUNCTION(excep_supervisor_inst_isr)
#endif
#ifdef BSP_MCU_EXCEP_ACCESS_ISR
R_BSP_PRAGMA_INTERRUPT_FUNCTION(excep_access_isr)
#endif
#ifdef BSP_MCU_EXCEP_UNDEFINED_INST_ISR
R_BSP_PRAGMA_INTERRUPT_FUNCTION(excep_undefined_inst_isr)
#endif
#ifdef BSP_MCU_EXCEP_FLOATING_POINT_ISR
R_BSP_PRAGMA_INTERRUPT_FUNCTION(excep_floating_point_isr)
#endif
#ifdef BSP_MCU_EXCEP_ADDRESS_ISR
R_BSP_PRAGMA_INTERRUPT_FUNCTION(excep_address_isr)
#endif
#ifdef BSP_MCU_NON_MASKABLE_ISR
R_BSP_PRAGMA_INTERRUPT_FUNCTION(non_maskable_isr)
#endif
#ifdef BSP_MCU_UNDEFINED_INTERRUPT_SOURCE_ISR
R_BSP_PRAGMA_INTERRUPT_DEFAULT(undefined_interrupt_source_isr)
#endif
#ifdef BSP_MCU_BUS_ERROR_ISR
R_BSP_PRAGMA_INTERRUPT(bus_error_isr, VECT(BSC,BUSERR))
#endif

#endif  /* End of multiple inclusion prevention macro */

