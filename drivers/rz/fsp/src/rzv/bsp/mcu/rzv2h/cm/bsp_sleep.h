/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_sleep.h
 * Version      : 1.00
 * Description  : bsp_sleep header
 *********************************************************************************************************************/

/******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_MCU_RZV2H RZV2H
 * @includedoc config_bsp_rzv2h_fsp.html
 * @{
 *********************************************************************************************************************/

#ifndef BSP_SLEEP_H
#define BSP_SLEEP_H

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/
#define R_BSP_SECURE_VECTOR_SET(vector)    {__asm volatile ("str.w       %0, [%1]"                       \
                                                            :                                            \
                                                            : "r" (vector), "r" (&R_SYSC->SYS_MCPU_CFG2) \
                                                            :                                            \
                                                            );                                           \
}

#define R_BSP_WARMRESET_REQ()              {__asm volatile ("ldr.w r2, [%0];"                               \
                                                            "orr r2, r2, %1;"                               \
                                                            "str.w r2, [%0];"                               \
                                                            :                                               \
                                                            : "r" (&R_CPG->CPG_LP_CTL1),                    \
                                                            "r" (1 << R_CPG_CPG_LP_CTL1_CM33WRESET_REQ_Pos) \
                                                            : "r2"                                          \
                                                            );                                              \
}

#define R_BSP_IM33_DISABLE()               {__asm volatile ("str.w %0, [%1]"                     \
                                                            :                                    \
                                                            : "r" (1), "r" (&R_CPG->CPG_LP_CTL2) \
                                                            :                                    \
                                                            );                                   \
}

#define R_BSP_NVIC_CM33_RESET()            {__asm volatile ("ldr.w r2, [%0];"                                  \
                                                            "and   r2, r2, %1;"                                \
                                                            "orr   r2, r2, %2;"                                \
                                                            "orr   r2, r2, %3;"                                \
                                                            "str.w r2, [%0];"                                  \
                                                            :                                                  \
                                                            : "r" (&SCB->AIRCR), "r" (SCB_AIRCR_PRIGROUP_Msk), \
                                                            "r" (0x5FAUL << SCB_AIRCR_VECTKEY_Pos),            \
                                                            "r" (SCB_AIRCR_SYSRESETREQ_Msk)                    \
                                                            : "r2"                                             \
                                                            );                                                 \
}

#define R_BSP_WAIT_CM33_RESET()            {__asm volatile ("wait_cm33_reset:"                                \
                                                            "ldr.w r2, [%0];"                                 \
                                                            "and r2, r2, %1;"                                 \
                                                            "cmp r2, #0;"                                     \
                                                            "beq wait_cm33_reset;"                            \
                                                            :                                                 \
                                                            : "r" (&R_CPG->CPG_LP_CM33CTL0),                  \
                                                            "i" (R_CPG_CPG_LP_CM33CTL0_CM33_WARMRESETREQ_Msk) \
                                                            : "r2"                                            \
                                                            );                                                \
}

#define R_BSP_CM33_WARMRESET()             {R_BSP_WARMRESET_REQ();   \
                                            R_BSP_IM33_DISABLE();    \
                                            R_BSP_NVIC_CM33_RESET(); \
                                            R_BSP_WAIT_CM33_RESET(); \
}

#define BSP_SLEEP_SET_SLEEP_REQ()          {R_CPG->CPG_LP_CTL1_b.CM33SLEEP_REQ = 0x00000001;}
#define BSP_SLEEP_CLEAR_SLEEP_REQ()        {R_CPG->CPG_LP_CTL1_b.CM33SLEEP_REQ = 0x00000000;}

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

#endif                                 /* BSP_SLEEP_H */

/** @} (end defgroup BSP_MCU_RZV2H) */
