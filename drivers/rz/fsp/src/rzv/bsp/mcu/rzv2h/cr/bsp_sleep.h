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
#define R_BSP_WARMRESET_REQ()

#define BSP_SLEEP_REQ_BIT_CR8_CORE0    (0x000000001U << 0)
#define BSP_SLEEP_REQ_BIT_CR8_CORE1    (0x000000001U << 1)

#if (0 == BSP_CR8_CORE_NUM)

/* Set core0 bit of sleep request bit field of CR8 cores */
 #define BSP_SLEEP_SET_SLEEP_REQ()    {R_CPG->CPG_LP_CTL1_b.CR8SLEEP_REQ = BSP_SLEEP_REQ_BIT_CR8_CORE0 | \
                                                                           R_CPG->CPG_LP_CTL1_b.CR8SLEEP_REQ;}
#else

/* Set core1 bit of sleep request bit field of CR8 cores */
 #define BSP_SLEEP_SET_SLEEP_REQ()    {R_CPG->CPG_LP_CTL1_b.CR8SLEEP_REQ = BSP_SLEEP_REQ_BIT_CR8_CORE1 | \
                                                                           R_CPG->CPG_LP_CTL1_b.CR8SLEEP_REQ;}
#endif

#if (0 == BSP_CR8_CORE_NUM)

/* Take the AND of the sleep request bit field of the CR8 cores and the core1 bit, and then clear only the core0 bit */
 #define BSP_SLEEP_CLEAR_SLEEP_REQ()    {R_CPG->CPG_LP_CTL1_b.CR8SLEEP_REQ = BSP_SLEEP_REQ_BIT_CR8_CORE1 & \
                                                                             R_CPG->CPG_LP_CTL1_b.CR8SLEEP_REQ;}
#else

/* Take the AND of the sleep request bit field of the CR8 cores and the core0 bit, and then clear only the core1 bit */
 #define BSP_SLEEP_CLEAR_SLEEP_REQ()    {R_CPG->CPG_LP_CTL1_b.CR8SLEEP_REQ = BSP_SLEEP_REQ_BIT_CR8_CORE0 & \
                                                                             R_CPG->CPG_LP_CTL1_b.CR8SLEEP_REQ;}
#endif

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
