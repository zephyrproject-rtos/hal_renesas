/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_reset.h
 * Version      : 1.00
 * Description  : bsp_reset header
 *********************************************************************************************************************/

/******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_MCU_RZG3E RZG3E
 * @includedoc config_bsp_rzg3e_fsp.html
 * @{
 *********************************************************************************************************************/

#ifndef BSP_RESET_H
#define BSP_RESET_H

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/
#define BSP_PRV_SCB_AIRCR_VECTKEY    (0x5FAUL)

#define R_BSP_SECURE_VECTOR_SET(vector)    {R_SYSC->SYS_MCPU_CFG2 = (vector);}

#define R_BSP_WARMRESET_REQ()              {R_CPG->CPG_LP_CTL1 = R_CPG->CPG_LP_CTL1 | \
                                                                 (1 << R_CPG_CPG_LP_CTL1_CM33WRESET_REQ_Pos);}

#define R_BSP_NVIC_CM33_RESET()            {SCB->AIRCR =                                                           \
                                                (uint32_t) ((BSP_PRV_SCB_AIRCR_VECTKEY << SCB_AIRCR_VECTKEY_Pos) | \
                                                            (SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) |                \
                                                            SCB_AIRCR_SYSRESETREQ_Msk);                            \
}

#define R_BSP_WAIT_CM33_RESET()            {while ((R_CPG->CPG_LP_CM33CTL0 &                        \
                                                    R_CPG_CPG_LP_CM33CTL0_CM33_WARMRESETREQ_Msk) == \
                                                   0U)                                              \
                                            { /* wait */};                                          \
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

#endif                                 /* BSP_RESET_H */

/** @} (end defgroup BSP_MCU_RZG3E) */
