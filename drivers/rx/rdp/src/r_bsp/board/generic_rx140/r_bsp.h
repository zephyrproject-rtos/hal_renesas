/*
* Copyright (c) 2011 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/***********************************************************************************************************************
* File Name    : r_bsp.h
* H/W Platform : GENERIC_RX140
* Description  : Has the header files that should be included for this platform.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 30.06.2021 1.00     First release
*         : 30.11.2021 1.01     Modified the include file.
*         : 26.02.2025 1.02     Changed the disclaimer.
***********************************************************************************************************************/

/* Make sure that no other platforms have already been defined. Do not touch this! */
#ifdef  PLATFORM_DEFINED
#error  "Error - Multiple platforms defined in platform.h!"
#else
#define PLATFORM_DEFINED
#endif

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
INCLUDE APPROPRIATE MCU AND BOARD FILES
***********************************************************************************************************************/
#include    "r_bsp_config.h"
#include    "mcu/all/r_bsp_common.h"
#include    "mcu/all/r_rx_compiler.h"

#if defined(__CCRX__)
#include    "mcu/rx140/register_access/ccrx/iodefine.h"
#elif defined(__GNUC__)
#include    "mcu/rx140/register_access/gnuc/iodefine.h"
#elif defined(__ICCRX__)
#include    "mcu/rx140/register_access/iccrx/iodefine.h"
#endif /* defined(__CCRX__), defined(__GNUC__), defined(__ICCRX__) */
#include    "mcu/rx140/r_bsp_cpu.h"
#include    "mcu/rx140/r_bsp_locking.h"
#include    "mcu/rx140/mcu_clocks.h"
#include    "mcu/rx140/mcu_info.h"
#include    "mcu/rx140/mcu_init.h"
#include    "mcu/rx140/mcu_interrupts.h"
#include    "mcu/rx140/mcu_locks.h"
#include    "mcu/rx140/vecttbl.h"

#include    "mcu/all/r_bsp_interrupts.h"
#include    "mcu/all/r_bsp_software_interrupt.h"
#include    "mcu/all/r_rx_intrinsic_functions.h"

#ifdef __cplusplus
}
#endif

#ifndef BSP_BOARD_GENERIC_RX140
#define BSP_BOARD_GENERIC_RX140

#endif /* BSP_BOARD_GENERIC_RX140 */

