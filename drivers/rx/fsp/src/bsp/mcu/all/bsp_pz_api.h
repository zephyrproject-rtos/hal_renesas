/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_PZ_ENTRY_H
#define BSP_PZ_ENTRY_H

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
#ifndef BSP_SSCID_SYSTEM_CLOCK_SET
 #define BSP_SSCID_SYSTEM_CLOCK_SET    (0U)
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** SSC error codes. */
typedef enum e_bsp_ssc_err
{
    BSP_SSC_SUCCESS = 0,                          ///< Successful completion

    /* System-level errors */
    BSP_SSC_ERR_PZ_NESTED_SSC           = -1,     ///< SSC call is nested within another SSC context
    BSP_SSC_ERR_PZ_INVALID_STATE        = -2,     ///< Invalid state for the SSC operation
    BSP_SSC_ERR_PZ_INVALID_ID           = -3,     ///< Invalid SSC ID provided
    BSP_SSC_ERR_PZ_UNREGISTERED_HANDLER = -4,     ///< No SSC handler registered for the specified SSC ID

    /* Function-level errors */
    BSP_SSC_ERR_FUNCTION_INVALID_ARGUMENT = -100, ///< Invalid input parameter
    BSP_SSC_ERR_FUNCTION_NOT_OPEN         = -101, ///< SSC function not initialized or opened
    BSP_SSC_ERR_FUNCTION_INVALID_POINTER  = -102, ///< Pointer points to invalid memory location
    BSP_SSC_ERR_FUNCTION_ASSERTION        = -103, ///< A critical assertion has failed
    BSP_SSC_ERR_FUNCTION_INVALID_STATE    = -104  ///< Function is in an invalid state for the requested operation
} bsp_ssc_err_t;

typedef bsp_ssc_err_t (* bsp_ssc_handler_t)(intptr_t arg0, intptr_t arg1, intptr_t arg2, intptr_t arg3);

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
#if BSP_PZ_SECURE_BUILD
void R_BSP_SecureEnter(uint32_t pc_adrs, uint32_t psw_data);

#elif BSP_PZ_NONSECURE_BUILD
 #if !defined(__ICCRX__)
bsp_ssc_err_t R_BSP_CallSSCFromNonSecure(intptr_t par1, intptr_t par2, intptr_t par3, intptr_t par4,
                                         uint32_t ssc_id) __attribute__((naked, noinline));

 #else
bsp_ssc_err_t R_BSP_CallSSCFromNonSecure(intptr_t par1, intptr_t par2, intptr_t par3, intptr_t par4,
                                         uint32_t ssc_id) __attribute__((noinline));

 #endif
#endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
