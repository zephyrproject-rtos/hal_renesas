/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#if BSP_TZ_SECURE_BUILD
 #define BSP_TZ_STACK_SEAL_SIZE    (8U)
#else
 #define BSP_TZ_STACK_SEAL_SIZE    (0U)
#endif

extern void __start(void);
BSP_PLACE_CODE_IN_RAM void Wakeup_Reset_Handler(void) __attribute__((naked, noreturn));
void wakeup_from_deepsleep(void);
/* Added __USED to make sure LTO will keep gp_reset_stat_reg */
__USED uintptr_t gp_reset_stat_reg = (uintptr_t) &(CRG_TOP->RESET_STAT_REG);

BSP_PLACE_CODE_IN_RAM void Wakeup_Reset_Handler (void)
{
	__ASM volatile (
		/*
		 *  Determine if this is a cold reset (e.g. POR, watchdog reset etc.) or
		 *  a wakeup from deep sleep.
		 *
		 *  If RESET_STAT_REG = 0, it is a wakeup from deep sleep without
		 *   state retention since RESET_STAT_REG is zeroed by goto_deepsleep().
		 *  In that case, the Wakeup_Reset_Handler jumps to wakeup_from_deepsleep,
		 *  instead of going through the normal startup procedure.
		 */
		"	ldr	r2, =gp_reset_stat_reg		\n"
		"	ldr	r1, [r2]			\n"
		"	ldr	r2, [r1]			\n"
			/* if RESET_STAT_REG != 0 then jump to .cold_reset */
		"	cbnz	r2, .cold_reset			\n"
		"	ldr	r3, =wakeup_from_deepsleep 	\n"
		"	bx	r3				\n"
		".cold_reset:					\n"
		"	ldr	r3, =__start			\n"
		"	bx	r3				\n"
	);
}

/** @} (end addtogroup BSP_MCU) */
