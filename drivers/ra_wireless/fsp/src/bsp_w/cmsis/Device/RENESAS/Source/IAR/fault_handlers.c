/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "bsp_api.h"
#include "bsp_cfg.h"

#pragma language=extended

#define STR2(x)                                 #x
#define STR(x)                                  STR2(x)

#define SYS_CTRL_REG                            (0x40100024 + (BASE_NS_OFFSET))
#define SYS_CTRL_REG_DEBUGGER_ENABLE_MSK        (0x80)

#define WATCHDOG_CTRL_REG                       (0x40100304 + (BASE_NS_OFFSET))
#define WATCHDOG_CTRL_REG_WDOG_FREEZE_EN_MSK    (0x4)

#define RESET_FREEZE_REG                        (0x40700104 + (BASE_NS_OFFSET))
#define RESET_FREEZE_REG_FRZ_SYS_WDOG_MSK       (0x04)

#define SET_FREEZE_REG                          (0x40700100 + (BASE_NS_OFFSET))
#define SET_FREEZE_REG_FRZ_SYS_WDOG_MSK         (0x04)

extern void NMI_HandlerC(unsigned long * exception_args);

#pragma location=".ram_code_from_flash"
BSP_ATTRIBUTE_STACKLESS void NMI_Handler(void)
{
    __asm volatile(
        "LDR     r1, =NMI_HandlerC      \n"
        "MOVS    r0, #4                 \n"
        "MOV     r2, lr                 \n"
        "TST     r0, r2                 \n"
        "BEQ     NMI_stacking_using_MSP \n"
        "MRS     r0, psp                \n"
        "B.W     stack_check            \n"
        "NMI_stacking_using_MSP:        \n"
        "MRS     r0, msp                \n"
        "B.W     stack_check            \n"
    );
}

extern uint32_t __ddsc_RAM_START;
extern uint32_t __ddsc_RAM_END;
extern void HardFault_HandlerC(unsigned long * exception_args);

#pragma location=".ram_code_from_flash"
BSP_ATTRIBUTE_STACKLESS void HardFault_Handler(void)
{
    __asm volatile(
        "LDR     r1, =HardFault_HandlerC    \n"
        "MOVS    r0, #4                     \n"
        "MOV     r2, lr                     \n"
        "TST     r0, r2                     \n"
        "BEQ     HF_stacking_using_MSP      \n"
        "MRS     r0, psp                    \n"
        "B.W     stack_check                \n"
        "HF_stacking_using_MSP:             \n"
        "MRS     r0, msp                    \n"
   );
}

#pragma location=".ram_code_from_flash"
BSP_ATTRIBUTE_STACKLESS void stack_check(void)
{
    __asm volatile(
        "LDR     r2, =__ddsc_RAM_START  \n"
        "CMP     r0, r2                 \n"
        "BLT     Wrong_SP               \n"
        "LDR     r2, =__ddsc_RAM_END    \n"
        "SUBS    r2, r2, #32            \n"
        "CMP     r0, r2                 \n"
        "BGT     Wrong_SP               \n"
        "BX      r1                     \n" /* Valid SP */
    );
}

#pragma location=".ram_code_from_flash"
BSP_ATTRIBUTE_STACKLESS void Wrong_SP(void)
{
    __asm volatile(
#if (0 == BSP_CFG_PRODUCTION_BUILD)
        /*
        * Set       WATCHDOG_CTRL_REG[WDOG_FREEZE_EN]
        * and reset WATCHDOG_CTRL_REG[NMI_RST]
        * so that watchdog can be frozen.
        */
 #if !BSP_MCU_GROUP_RA6W1
        "LDR     r0, ="STR(WATCHDOG_CTRL_REG)"                      \n"
        "LDR     r1, ="STR(WATCHDOG_CTRL_REG_WDOG_FREEZE_EN_MSK)"   \n"
        "STR     r1, [r0]                                           \n"
 #endif
        /* Freeze WDog at all times */
        "LDR     r0, ="STR(SET_FREEZE_REG)"                         \n"
        "LDR     r1, ="STR(SET_FREEZE_REG_FRZ_SYS_WDOG_MSK)"        \n"
        "STRH    r1, [r0, #0]                                       \n"
        /* Enable debugger at all times */
        "LDR     r4, ="STR(SYS_CTRL_REG)"                           \n"
        "LDRH    r0, [r4, #0]                                       \n"
        "MOVS    r1, #"STR(SYS_CTRL_REG_DEBUGGER_ENABLE_MSK)"       \n"
        "ORRS    r0, r0, r1                                         \n"
        /* Update SYS_CTRL_REG */
        "STRH    r0, [r4, #0]                                       \n"
#else
        /* Unfreeze WDog at all times */
        "LDR     r0, ="STR(RESET_FREEZE_REG)"                       \n"
        "LDR     r1, ="STR(RESET_FREEZE_REG_FRZ_SYS_WDOG_MSK)"      \n"
        "STRH    r1, [r0, #0]                                       \n"
 #if (1 == BSP_CFG_DEBUGGER_ENABLE)
        /* Enable debugger */
        "LDR     r4, ="STR(SYS_CTRL_REG)"                           \n"
        "LDRH    r0, [r4, #0]                                       \n"
        "MOVS    r1, #"STR(SYS_CTRL_REG_DEBUGGER_ENABLE_MSK)"       \n"
        "ORRS    r0, r0, r1                                         \n"
        /* Update SYS_CTRL_REG */
        "STRH    r0, [r4, #0]                                       \n"
 #endif
#endif /* (0 == BSP_CFG_PRODUCTION_BUILD) */
        /* Wait for the WDog to hit or a debug session to start */
        "B       .                                                  \n"
    );
}

extern void SecureFault_HandlerC(unsigned long * exception_args);

#pragma location=".ram_code_from_flash"
BSP_ATTRIBUTE_STACKLESS void SecureFault_Handler(void)
{
    __asm volatile(
        "LDR     r1, =SecureFault_HandlerC      \n"
        "MOVS    r0, #4                         \n"
        "MOV     r2, lr                         \n"
        "TST     r0, r2                         \n"
        "BEQ     SecureFault_stacking_using_MSP \n"
        "MRS     r0, psp                        \n"
        "B.W     stack_check                    \n"
        "SecureFault_stacking_using_MSP:        \n"
        "MRS     r0, msp                        \n"
        "B.W     stack_check                    \n"
    );
}
