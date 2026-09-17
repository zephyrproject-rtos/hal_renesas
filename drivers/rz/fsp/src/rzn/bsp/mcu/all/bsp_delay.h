/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_DELAY_H
#define BSP_DELAY_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#if defined(BSP_CFG_CORE_CR52)
 #include "cr/bsp_delay_core.h"
#elif defined(BSP_CFG_CORE_CA55)
 #include "ca/bsp_delay_core.h"
#endif

#include "bsp_compiler_support.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZN
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Available delay units for R_BSP_SoftwareDelay(). These are ultimately used to calculate a total # of microseconds */
typedef enum
{
    BSP_DELAY_UNITS_SECONDS      = 1000000, ///< Requested delay amount is in seconds
    BSP_DELAY_UNITS_MILLISECONDS = 1000,    ///< Requested delay amount is in milliseconds
    BSP_DELAY_UNITS_MICROSECONDS = 1        ///< Requested delay amount is in microseconds
} bsp_delay_units_t;

/** @} (end addtogroup BSP_MCU) */

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void bsp_prv_software_delay_loop(uint32_t loop_cnt);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
