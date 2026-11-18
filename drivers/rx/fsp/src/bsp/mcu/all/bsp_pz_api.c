/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_pz_hypervisor.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

#if BSP_PZ_NONSECURE_BUILD

/*******************************************************************************************************************//**
 * Transition entry point for SSC calls.
 *
 * Passes SSC arguments and an SSC ID to the Root world.
 **********************************************************************************************************************/
bsp_ssc_err_t R_BSP_CallSSCFromNonSecure (intptr_t par1, intptr_t par2, intptr_t par3, intptr_t par4, uint32_t ssc_id) {
 #if !defined(__clang__)

    /* Added to fix build error "Parameter "*" was never referenced.". */
    FSP_PARAMETER_NOT_USED(par1);
    FSP_PARAMETER_NOT_USED(par2);
    FSP_PARAMETER_NOT_USED(par3);
    FSP_PARAMETER_NOT_USED(par4);
    FSP_PARAMETER_NOT_USED(ssc_id);

    /* Transition to the Root world to invoke the specified SSC. */
    __asm volatile (

  #if defined(__CCRX__)
        "push.l r5    \n"
  #else
        "push r5    \n"
  #endif
        "mov.l  8[r0], r5  \n"
  #if defined(__CCRX__)
        "trcall #0      \n"            /* BSP_PZ_TRCALL_VECTOR_CALL_SSC defined 0. */
  #else
        "trcall %0      \n"
  #endif
        "pop r5         \n"
        "rts            \n"
  #if defined(__GNUC__) || defined(__ICCRX__)
        : : "i" (BSP_PZ_TRCALL_VECTOR_CALL_SSC)
   #if defined(__GNUC__)
        : "memory"
   #endif
  #endif
        );

    return BSP_SSC_SUCCESS;
 #endif
}

#endif

/** @} (end addtogroup BSP_MCU) */
