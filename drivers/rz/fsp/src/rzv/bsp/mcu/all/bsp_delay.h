/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_DELAY_H
#define BSP_DELAY_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER
#if defined(BSP_SUPPORT_CORE_CM33)
#include "cm/bsp_compiler_support.h"
#elif defined(BSP_SUPPORT_CORE_CR8)
#include "cr/bsp_compiler_support.h"
#endif

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
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

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
BSP_ATTRIBUTE_STACKLESS void bsp_prv_software_delay_loop(uint32_t loop_cnt);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_DELAY_H */
