/*
* Copyright (c) 2011 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/***********************************************************************************************************************
* File Name    : mcu_interrupts.c
* Description  : This module is the control of the interrupt enable.
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 30.06.2021 1.00     First Release
*         : 21.11.2023 1.01     Added timeout detection processing to bus error processing.
*                               Added processing to control only illegal address access detection to bus error 
*                               processing.
*                               Added processing to control only timeout detection to bus error processing.
*         : 26.02.2025 1.02     Changed the disclaimer.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* Access to r_bsp. */
#include "platform.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Let FPSW EV, EO, EZ, EU, EX=1 (FPU exceptions enabled.) */
#define BSP_PRV_FPU_EXCEPTIONS_ENABLE       (0x00007C00)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: bsp_interrupt_enable_disable
* Description  : Either enables or disables an interrupt.
* Arguments    : vector -
*                    Which vector to enable or disable.
*                enable -
*                    Whether to enable or disable the interrupt.
* Return Value : BSP_INT_SUCCESS -
*                    Interrupt enabled or disabled.
*                BSP_INT_ERR_UNSUPPORTED -
*                    API does not support enabling/disabling for this vector.
***********************************************************************************************************************/
bsp_int_err_t bsp_interrupt_enable_disable (bsp_int_src_t vector, bool enable)
{
#ifdef __FPU
    uint32_t      tmp_fpsw;
#endif
    bsp_int_err_t err = BSP_INT_SUCCESS;

    switch (vector)
    {
        case (BSP_INT_SRC_BUS_ERROR):
            if (true == enable)
            {
                /* Enable the bus error interrupt to catch accesses to illegal/reserved areas of memory */
                /* Clear any pending interrupts */
                IR(BSC,BUSERR) = 0;

                /* Make this the highest priority interrupt (adjust as necessary for your application */
                IPR(BSC,BUSERR) = 0x0F;

                /* Enable the interrupt in the ICU*/
                R_BSP_InterruptRequestEnable(VECT(BSC,BUSERR));

                /* Enable illegal address interrupt in the BSC */
                BSC.BEREN.BIT.IGAEN = 1;

                /* Enable timeout detection enable. */
                BSC.BEREN.BIT.TOEN = 1;
            }
            else
            {
                /* Disable the bus error interrupt. */
                /* Disable the interrupt in the ICU*/
                R_BSP_InterruptRequestDisable(VECT(BSC,BUSERR));

                /* Disable illegal address interrupt in the BSC */
                BSC.BEREN.BIT.IGAEN = 0;

                /* Disable timeout detection enable. */
                BSC.BEREN.BIT.TOEN = 0;
            }
            break;

        case (BSP_INT_SRC_BUS_ERROR_ILLEGAL_ACCESS):
            if (true == enable)
            {
                /* Check the bus error monitoring status. */
                if (0 == BSC.BEREN.BYTE)
                {
                    /* Enable the bus error interrupt to catch accesses to illegal/reserved areas of memory */
                    /* Clear any pending interrupts */
                    IR(BSC,BUSERR) = 0;

                    /* Make this the highest priority interrupt (adjust as necessary for your application */
                    IPR(BSC,BUSERR) = 0x0F;

                    /* Enable the interrupt in the ICU. */
                    R_BSP_InterruptRequestEnable(VECT(BSC,BUSERR));
                }

                /* Enable illegal address interrupt in the BSC */
                BSC.BEREN.BIT.IGAEN = 1;
            }
            else
            {
                /* Disable illegal address interrupt in the BSC */
                BSC.BEREN.BIT.IGAEN = 0;

                /* Check the bus error monitoring status. */
                if (0 == BSC.BEREN.BYTE)
                {
                    /* Disable the bus error interrupt in the ICU. */
                    R_BSP_InterruptRequestDisable(VECT(BSC,BUSERR));
                }
            }
            break;

        case (BSP_INT_SRC_BUS_ERROR_TIMEOUT):
            if (true == enable)
            {
                /* Check the bus error monitoring status. */
                if (0 == BSC.BEREN.BYTE)
                {
                    /* Enable the bus error interrupt to catch accesses to illegal/reserved areas of memory */
                    /* Clear any pending interrupts */
                    IR(BSC,BUSERR) = 0;

                    /* Make this the highest priority interrupt (adjust as necessary for your application */
                    IPR(BSC,BUSERR) = 0x0F;

                    /* Enable the interrupt in the ICU. */
                    R_BSP_InterruptRequestEnable(VECT(BSC,BUSERR));
                }

                /* Enable timeout detection enable. */
                BSC.BEREN.BIT.TOEN = 1;
            }
            else
            {
                /* Disable timeout detection enable. */
                BSC.BEREN.BIT.TOEN = 0;

                /* Check the bus error monitoring status. */
                if (0 == BSC.BEREN.BYTE)
                {
                    /* Disable the bus error interrupt in the ICU. */
                    R_BSP_InterruptRequestDisable(VECT(BSC,BUSERR));
                }
            }
            break;

#ifdef __FPU
        case (BSP_INT_SRC_EXC_FPU):

            /* Get current FPSW. */
            tmp_fpsw = (uint32_t)R_BSP_GET_FPSW();

            if (true == enable)
            {
                /* Set the FPU exception flags. */
                R_BSP_SET_FPSW(tmp_fpsw | (uint32_t)BSP_PRV_FPU_EXCEPTIONS_ENABLE);
            }
            else
            {
                /* Clear only the FPU exception flags. */
                R_BSP_SET_FPSW(tmp_fpsw & (uint32_t)~BSP_PRV_FPU_EXCEPTIONS_ENABLE);
            }
            break;
#endif

        case (BSP_INT_SRC_EXC_NMI_PIN):
            if (true == enable)
            {
                /* Enable NMI pin interrupt (cannot undo!) */
                ICU.NMIER.BIT.NMIEN = 1;
            }
            else
            {
                /* NMI pin interrupts cannot be disabled after being enabled. */
                err = BSP_INT_ERR_UNSUPPORTED;
            }
            break;

        default:
            err = BSP_INT_ERR_UNSUPPORTED;
            break;
    }

    return err;
} /* End of function bsp_interrupt_enable_disable() */

