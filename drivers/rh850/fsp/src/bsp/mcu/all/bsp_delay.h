/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_DELAY_H
#define BSP_DELAY_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "fsp_common_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_COMMON
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** The number of cycles required per software delay loop. */
#define BSP_DELAY_LOOP_CYCLES    (4)

/* Calculates the number of delay loops to pass to bsp_prv_software_delay_loop to achieve at least the requested cycle
 * count delay. This is 1 loop longer than optimal if cycles is a multiple of BSP_DELAY_LOOP_CYCLES, but it ensures
 * the requested number of loops is at least 1 since bsp_prv_software_delay_loop cannot be called with a loop count
 * of 0. */
#define BSP_DELAY_LOOPS_CALCULATE(cycles)    (((cycles) / BSP_DELAY_LOOP_CYCLES) + 1U) /* PRQA S 1534 # Advisory R-2.5 */

/** Available delay units for R_BSP_SoftwareDelay(). These are ultimately used to calculate a total # of microseconds */
typedef enum e_bsp_delay_units                                                         /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_DELAY_UNITS_MICROSECONDS = 1,                                                  ///< Requested delay amount is in microseconds
    BSP_DELAY_UNITS_MILLISECONDS = 1000,                                               ///< Requested delay amount is in milliseconds
    BSP_DELAY_UNITS_SECONDS      = 1000000                                             ///< Requested delay amount is in seconds
} bsp_delay_units_t;

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_COMMON)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void R_BSP_SoftwareDelay(uint32_t delay, bsp_delay_units_t units);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_DELAY_H */
