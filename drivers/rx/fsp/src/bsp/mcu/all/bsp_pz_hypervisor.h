/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_PZ_HYPERVISOR_H
#define BSP_PZ_HYPERVISOR_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <stdint.h>
#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#if BSP_PZ_SECURE_BUILD

 #define BSP_PZ_STACK_SEALING_VALUE          0xFEF5EDA5

/* Secure TRCALL vector numbers */
 #define BSP_PZ_TRCALL_VECTOR_ENTER_NS       (0)
 #define BSP_PZ_TRCALL_VECTOR_RETURN_SINT    (1)
 #define BSP_PZ_TRCALL_VECTOR_RETURN_SSC     (2)
 #define BSP_PZ_TRCALL_VECTOR_CALL_NSSC      (3)
#endif

#if (BSP_PZ_SECURE_BUILD || BSP_PZ_NONSECURE_BUILD)

/* Non-Secure TRCALL vector numbers */
 #define BSP_PZ_TRCALL_VECTOR_CALL_SSC         (0)
 #define BSP_PZ_TRCALL_VECTOR_RETURN_NS_INT    (1)
 #define BSP_PZ_TRCALL_VECTOR_RETURN_NS_SC     (2)
 #define BSP_PZ_TRCALL_VECTOR_RESERVED         (3)
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#if BSP_PZ_SECURE_BUILD

void R_BSP_SecureEnter(uint32_t pc_adrs, uint32_t psw_data);

 #if defined(__CCRX__)
void bsp_set_trctb(uint32_t x);
void bsp_set_wintb(uint32_t x);
void R_BSP_SecureEnter_ASM(uint32_t psw_data, uint32_t pc_adrs, uint32_t par3);

 #endif

#endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif
