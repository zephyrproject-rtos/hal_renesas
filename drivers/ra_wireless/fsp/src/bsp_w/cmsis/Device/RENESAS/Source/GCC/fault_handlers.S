/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#include "bsp_cfg.h"

#if !BSP_MCU_GROUP_RA6W1
 #if BSP_TZ_NONSECURE_BUILD
  #define BASE_NS_OFFSET     (0x10000000)
 #else
  #define BASE_NS_OFFSET     (0)
 #endif

#if BSP_MCU_GROUP_RA6W3
#define SYS_CTRL_REG                            (0x40400024 + (BASE_NS_OFFSET))
#else
#define SYS_CTRL_REG                            (0x40100024 + (BASE_NS_OFFSET))
#endif
#define SYS_CTRL_REG_DEBUGGER_ENABLE_MSK        0x80

#define WATCHDOG_CTRL_REG                       (0x40100304 + (BASE_NS_OFFSET))
#define WATCHDOG_CTRL_REG_WDOG_FREEZE_EN_MSK    0x4

#define RESET_FREEZE_REG                        (0x40700104 + (BASE_NS_OFFSET))
#define RESET_FREEZE_REG_FRZ_SYS_WDOG_MSK       0x04

#define SET_FREEZE_REG                          (0x40700100 + (BASE_NS_OFFSET))
#define SET_FREEZE_REG_FRZ_SYS_WDOG_MSK         0x04
#else

#define SYS_CTRL_REG                            0x400C0018
#define SYS_CTRL_REG_DEBUGGER_ENABLE_MSK        0x10

#define WATCHDOG_CTRL_REG                       0x400C0704
#define WATCHDOG_CTRL_REG_WDOG_FREEZE_EN_MSK    0x4

#define RESET_FREEZE_REG                        0x400C0008
#define RESET_FREEZE_REG_FRZ_SYS_WDOG_MSK       0x200

#define SET_FREEZE_REG                          0x400C0004
#define SET_FREEZE_REG_FRZ_SYS_WDOG_MSK         0x200
#endif

            .syntax  unified
            .arch    armv8-m.main

            .thumb
            .section .ram_code_from_flash
            .align  2

            .thumb_func
            .type   NMI_Handler, %function
            .globl  NMI_Handler
NMI_Handler:
            ldr     r1, =NMI_HandlerC
            movs    r0, #4
            mov     r2, lr
            tst     r0, r2
            beq     NMI_stacking_using_MSP
            mrs     r0, psp
            b       stack_check
NMI_stacking_using_MSP:
            mrs     r0, msp
            b       stack_check

            .pool
            .size   NMI_Handler, . - NMI_Handler


            .thumb_func
            .extern __ddsc_RAM_START
            .extern __ddsc_RAM_END
            .type   HardFault_Handler, %function
            .globl  HardFault_Handler
HardFault_Handler:
            ldr     r1, =HardFault_HandlerC
            movs    r0, #4
            mov     r2, lr
            tst     r0, r2
            beq     HF_stacking_using_MSP
            mrs     r0, psp
            b       stack_check
HF_stacking_using_MSP:
            mrs     r0, msp

stack_check:
            ldr     r2, =__ddsc_RAM_START
            cmp     r0, r2
            blt     Wrong_SP
            ldr     r2, =__ddsc_RAM_END-32
            cmp     r0, r2
            bgt     Wrong_SP
            bx      r1 /* Valid SP */

Wrong_SP:
#if (0 == BSP_CFG_PRODUCTION_BUILD)
            /*
             * Set       WATCHDOG_CTRL_REG[WDOG_FREEZE_EN]
             * and reset WATCHDOG_CTRL_REG[NMI_RST]
             * so that watchdog can be frozen.
             */
#if !BSP_MCU_GROUP_RA6W1
            ldr     r0, =WATCHDOG_CTRL_REG
            ldr     r1, =WATCHDOG_CTRL_REG_WDOG_FREEZE_EN_MSK
            str     r1, [r0]
#endif
            /* Freeze WDog at all times */
            ldr     r0, =SET_FREEZE_REG
            ldr     r1, =SET_FREEZE_REG_FRZ_SYS_WDOG_MSK
            strh    r1, [r0, #0]
            /* Enable debugger at all times */
            ldr     r4, =SYS_CTRL_REG
            ldrh    r0, [r4, #0]
            movs    r1, #SYS_CTRL_REG_DEBUGGER_ENABLE_MSK
            orrs    r0, r0, r1
            /* Update SYS_CTRL_REG */
            strh    r0, [r4, #0]
#else
            /* Unfreeze WDog at all times */
            ldr     r0, =RESET_FREEZE_REG
            ldr     r1, =RESET_FREEZE_REG_FRZ_SYS_WDOG_MSK
            strh    r1, [r0, #0]
#if (1 == BSP_CFG_DEBUGGER_ENABLE)
            /* Enable debugger */
            ldr     r4, =SYS_CTRL_REG
            ldrh    r0, [r4, #0]
            movs    r1, #SYS_CTRL_REG_DEBUGGER_ENABLE_MSK
            orrs    r0, r0, r1
            /* Update SYS_CTRL_REG */
            strh    r0, [r4, #0]
#endif
#endif /* (0 == BSP_CFG_PRODUCTION_BUILD) */
            /* Wait for the WDog to hit or a debug session to start */
            b       .

            .pool
            .size   HardFault_Handler, . - HardFault_Handler

            .thumb
            .section .ram_code_from_flash
            .align  2

            .thumb_func
            .type   SecureFault_Handler, %function
            .globl  SecureFault_Handler

SecureFault_Handler:
            ldr     r1, =SecureFault_HandlerC
            movs    r0, #4
            mov     r2, lr
            tst     r0, r2
            beq     SecureFault_stacking_using_MSP
            mrs     r0, psp
            b       stack_check
SecureFault_stacking_using_MSP:
            mrs     r0, msp
            b       stack_check

            .pool
            .size   SecureFault_Handler, . - SecureFault_Handler

#if BSP_MCU_GROUP_RA6W3
            .thumb_func
            .type   BusFault_Handler, %function
            .globl  BusFault_Handler
            .weak   BusFault_HandlerC
BusFault_Handler:
            ldr     r1, =BusFault_HandlerC
            movs    r0, #4
            mov     r2, lr
            tst     r0, r2
            beq     BusFault_stacking_using_MSP
            mrs     r0, psp
            b       stack_check
BusFault_stacking_using_MSP:
            mrs     r0, msp
            b       stack_check

            .pool
            .size   BusFault_Handler, . - BusFault_Handler
#endif /* BSP_MCU_GROUP_RA6W3 */

            .end
