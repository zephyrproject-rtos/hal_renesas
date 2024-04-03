/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DTC_CFG_H
#define R_DTC_CFG_H

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Specify whether to include code for API parameter checking. Valid settings include:
 *    - BSP_CFG_PARAM_CHECKING_ENABLE : Utilizes the system default setting from bsp_cfg.h
 *    - 1 : Includes parameter checking
 *    - 0 : Compiles out parameter checking
 */
#ifndef DTC_CFG_PARAM_CHECKING_ENABLE
 #define DTC_CFG_PARAM_CHECKING_ENABLE        (BSP_CFG_PARAM_CHECKING_ENABLE)
#endif

/** Specify whether to include code for software start.  Valid settings include:
 *    - 1 : Includes code for software start.
 *          @note Requires the ELC software start functions from the ELC module.
 *    - 0 : Compiles out code for software start
 */
#ifndef DTC_CFG_SOFTWARE_START_ENABLE
 #define DTC_CFG_SOFTWARE_START_ENABLE        (0)
#endif

/** To put the vector table in a specific linker section, set DTC_CFG_VECTOR_TABLE_SECTION_NAME to
 *  the name of the section you want to use (i.e. ".mysection"). To use the default section, comment
 *  out this definition
 */
#ifndef DTC_CFG_VECTOR_TABLE_SECTION_NAME
 #define DTC_CFG_VECTOR_TABLE_SECTION_NAME    BSP_UNINIT_SECTION_PREFIX ".fsp_dtc_vector_table"
#endif

#endif
