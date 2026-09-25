/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#include "bsp_cfg.h"

                .syntax unified
                .arch   armv8-m.main


/* FIXME: remove temporary local configuration */
#define dg_configUSE_HW_MPU                     1

                .equ RESET_STAT_REG,                     0x401000BC
                .equ PDC_BASE,                           0x40100200
#if defined(BSP_MCU_GROUP_RA6B1) || defined(BSP_MCU_GROUP_RA6U1)
                .equ ICU_IELSR_REG,                      0x25000300
                .equ ELC_ELCR_REG,                       0x25020000
                .equ ELC_ELSR_REG,                       0x25020010
                .equ ELC_ELGRP_REG,                      0x25020090
#elif defined(BSP_MCU_GROUP_RA6B2)
                .equ ICU_IELSR_REG,                      0x2B000300
                .equ ELC_ELCR_REG,                       0x2D000000
                .equ ELC_ELSR_REG,                       0x2D000010
                .equ ELC_ELGRP_REG,                      0x2D000090
#else
                .equ ICU_IELSR_REG,                      0x2C100300
                .equ ELC_ELCR_REG,                       0x2C000000
                .equ ELC_ELSR_REG,                       0x2C000010
                .equ ELC_ELGRP_REG,                      0x2C000090
#endif
                .equ SCB_SHCSR_xFAULTENA_MASK,           ((1<<19) | (1<<18) | (1<<17) | (1<<16))

                .equ SCB_BASE,  0xE000ED00
                .equ CPACR,     0xE000ED88

                .equ FPCCR,     0xE000EF34
                .equ FPDSCR,    0xE000EF3C

#if (BSP_CFG_SLEEP_TRACE_VIA_GPIO)
 #if defined(BSP_MCU_GROUP_RA6B1) || defined(BSP_MCU_GROUP_RA6U1) || (BSP_MCU_GROUP_RA6B2)
                .equ GPIO_P0_SET_DATA_REG,0x40300C0C
                .equ P0_00_MODE_REG,0x40300C24
                .equ GPIO_P0_RESET_DATA_REG,0x40300C18
 #endif
#endif

#if (dg_configUSE_HW_MPU)
                .equ MPU_NUM_REGIONS,           0x8
                .equ MPU_BASE,                  0xE000ED90
#endif

#if (BSP_CFG_MTB_ENABLE)
                .equ MTB_POSITION_REG,          0xE0043000
                .equ MTB_MASTER_REG,            0xE0043004
                .equ MTB_FLOW_REG,              0xE0043008
#endif
#if defined(BSP_MCU_GROUP_RA6B1) || defined(BSP_MCU_GROUP_RA6U1) || (BSP_MCU_GROUP_RA6B2)
                .equ PDC_CHANGE_PDSYS_POWER_MODE_OFFSET, 0xD0
#endif

/*
 *  The processor state is stored here before going to deep sleep,
 *  so that it is restored after wakeup.
 */
                .section .bss
                .align 3
                .globl  __retained_state

                /* reserve space for stacking, in case an exception occurs while restoring the state */
                .space  64
__retained_state:
.stored_PRIMASK:
                .space  4
.stored_R4:
                .space  4
.stored_R5:
                .space  4
.stored_R6:
                .space  4
.stored_R7:
                .space  4
.stored_R8:
                .space  4
.stored_R9:
                .space  4
.stored_R10:
                .space  4
.stored_R11:
                .space  4
.stored_R12:
                .space  4
.stored_LR:
                .space  4
.stored_MSP:
                .space  4
.stored_PSP:
                .space  4
.stored_CONTROL:
                .space  4
.stored_ISER:
                .space  4
.stored_ISER1:
                .space  4
.stored_PRIORITY0:
                .space  4
.stored_PRIORITY1:
                .space  4
.stored_PRIORITY2:
                .space  4
.stored_PRIORITY3:
                .space  4
.stored_PRIORITY4:
                .space  4
.stored_PRIORITY5:
                .space  4
.stored_PRIORITY6:
                .space  4
.stored_PRIORITY7:
                .space  4
.stored_PRIORITY8:
                .space  4
.stored_PRIORITY9:
                .space  4
.stored_PRIORITY10:
                .space  4
.stored_PRIORITY11:
                .space  4
.stored_PRIORITY12:
                .space  4
.stored_PRIORITY13:
                .space  4
.stored_SCR:
                .space  4
.stored_SHPR1:
                .space  4
.stored_SHPR2:
                .space  4
.stored_SHPR3:
                .space  4
.stored_SHCSR_xFAULTENA:
                .space  4

.stored_CPACR:          .space  4
.stored_FPCCR:          .space  4
.stored_FPDSCR:         .space  4

#if (dg_configUSE_HW_MPU)
.stored_MPU_CTRL:       .space  4
.stored_MPU_REGIONS:    .space  64
.stored_MPU_MAIR0:      .space  4
.stored_MPU_MAIR1:      .space  4
#endif

#if (BSP_CFG_MTB_ENABLE)
.stored_MTB_POSITION:   .space  4
.stored_MTB_MASTER:     .space  4
.stored_MTB_FLOW:       .space  4
#endif

/* Reserve space for storing the 44 non-retained IELSR registers of ICU.
 * Only IELSR[44...59] are retained when PD_MEM is powered off.
 */
.stored_ICU_IELSR:
                .space 176
/* Reserve space for storing the ELCR register of ELC. */
.stored_ELC_ELCR:
                .space 4
/* Reserve space for storing the 30 ELSR registers of ELC. */
.stored_ELC_ELSR:
                .space 120
/* Reserve space for storing the 10 ELGRP registers of ELC. */
.stored_ELC_ELCGRP:
                .space 40

                .size   __retained_state, . - __retained_state


/* Store processor state and attempt to enter sleep mode.
 *
 * This function stores processor state in retained memory and uses WFI to
 * enter sleep mode (processor registers are not retained during sleep).
 *
 * It returns a value inidicating whether sleep mode was entered or not.
 *
 * The return to the context of its caller is performed indirectly through
 * function goto_deepsleep_return:
 *
 *   - If sleep mode is not entered then goto_deepsleep() will call
 *     goto_deepsleep_return(0) to return to its caller.
 *
 *   - If sleep mode is entered then upon wake-up the reset handler will jump
 *     to wakeup_from_deepsleep() which will restore processor state and then
 *     call goto_deepsleep_return(1) to return to the context which originally
 *     called goto_deepsleep().
 *
 * As a last step before executing the WFI instruction, this function resets
 * RESET_STAT_REG so that upon wake-up the reset handler will be able to detect
 * that we have a wake-up instead of a reset.
 *
 * Processor state is stored at __retained_state. The stack is not modified.
 */
                .section .ram_code_from_flash
                .thumb
                .thumb_func
                .align  1
                .globl  goto_deepsleep
                .type   goto_deepsleep, %function
goto_deepsleep:

                /* TODO: we also need to store BASEPRI */

                /* Store PRIMASK and disable interrupts */
                mrs     r0, PRIMASK
                cpsid   i
                ldr     r3, =.stored_PRIMASK
                stm     r3!, {r0}

                /* store R4-R12, LR */
                stm     r3!, {r4-r12, lr}

                /* Store MSP, PSP, CONTROL */
                mrs     r0, msp
                mrs     r1, psp
                mrs     r2, control
                stm     r3!, {r0-r2}

                /* Store NVIC->ISER[0..1] */
                ldr     r0, =0xE000E100
                ldm     r0, {r4-r5}
                stm     r3!, {r4-r5}

                /* Save values of NVIC->IPR[0..55] */
                ldr     r0, =0xE000E400         // NVIC->IPR[] base address
                ldm     r0!, {r2, r4-r12}
                stm     r3!, {r2, r4-r12}
                ldm     r0, {r4-r7}
                stm     r3!, {r4-r7}


                /*
                 * Store
                 *      SCB->SCR
                 *      SCB->SHPR1..3
                 *      SCB->SHCSR (<x>FAULTENA fields only)
                 */
                ldr     r0, =SCB_BASE           // address of SCB
                ldr     r4, [r0, #0x10]         // value of SCB->SCR
                ldr     r5, [r0, #0x18]         // value of SCB->SHPR1
                ldr     r6, [r0, #0x1C]         // value of SCB->SHPR2
                ldr     r7, [r0, #0x20]         // value of SCB->SHPR3
                ldr     r8, [r0, #0x24]         // value of SCB->SHCSR
                and     r8, SCB_SHCSR_xFAULTENA_MASK // keep only the <x>FAULTENA fields
                stm     r3!, {r4-r8}

                /* Store CPACR, FPCCR, FPDSCR */
                ldr     r4, [r0, #(CPACR - SCB_BASE)]   // load CPACR
                and     r4, (0xF << 20)                 // keep only CP11 and CP10
                ldr     r5, [r0, #(FPCCR - SCB_BASE)]   // load FPCCR
                and     r5, (0xF << 28)                 // keep only ASPEN, LSPEN, CLRONRET
                ldr     r6, [r0, #(FPDSCR - SCB_BASE)]  // load FPDSCR
                stm     r3!, {r4-r6}

#if (dg_configUSE_HW_MPU)
                /* Store MPU_CTRL  */
                ldr     r0, =#MPU_BASE                  // load MPU_CTRL address
                ldr     r4, [r0, #0x4]                  // value of MPU_CTRL
                stm     r3!, {r4}                       // store value of MPU_CTRL

                /* Store MPU_RBAR and MPU_RLAR for every region */
                movs    r4, 0
.mpu_store_loop:
                str     r4, [r0, #0x8]                  // set MPU_RNR
                ldr     r6, [r0, #0xC]                  // value of MPU_RBAR
                ldr     r7, [r0, #0x10]                 // value of MPU_RLAR
                stm     r3!, {r6-r7}
                adds    r4, #1
                cmp     r4, #MPU_NUM_REGIONS
                blt     .mpu_store_loop                 // if all region registers have been accessed exit loop

                /* Store MPU_MAIR0 and MPU_MAIR1  */
                ldr     r6, [r0, #0x30]                 // value of MPU_MAIR0
                ldr     r7, [r0, #0x34]                 // value of MPU_MAIR1
                stm     r3!, {r6-r7}                    // store values of MPU_MAIR0 and MPU_MAIR1
#endif

#if (BSP_CFG_MTB_ENABLE)
                /* Store MTB  */
                ldr     r0, =#MTB_POSITION_REG          // load MTB_POSITION_REG address
                ldm     r0, {r4-r6}                     // value of MTB_POSITION_REG MTB_MASTER_REG, MTB_FLOW_REG
                stm     r3!, {r4-r6}
#endif

                /* Store non-retained IELSR entries of ICU. */
                ldr     r1, =ICU_IELSR_REG              // r1 = &ICU->ICU_IELSR0_REG
                movs    r0, #0
.icu_store_loop:                                        // loop to store ICU_IELSR_REG[0...39]
                ldm     r1!, {r2, r4-r12}
                stm     r3!, {r2, r4-r12}
                adds    r0, #1
                cmp     r0, #4
                blt    .icu_store_loop

                ldm     r1!, {r4-r7}                   // store ICU_IELSR_REG[40...43]
                stm     r3!, {r4-r7}

                /* Store ELCR register of ELC. */
                ldr     r0, =ELC_ELCR_REG
                ldr     r1, [r0]
                stm     r3!, {r1}

                /* Store non-retained ELSR entries of ELC. */
                ldr     r1, =ELC_ELSR_REG
                movs    r0, #0
.elc_elsr_store_loop:
                ldm     r1!, {r2, r4-r12}
                stm     r3!, {r2, r4-r12}
                adds    r0, #1
                cmp     r0, #3
                blt    .elc_elsr_store_loop

                /* Store ELC Groups' configuration. */
                ldr     r1, =ELC_ELGRP_REG
                ldm     r1!, {r2, r4-r12}
                stm     r3!, {r2, r4-r12}

.clear_reset_stat_reg:
                /*
                 *  Set RESET_STAT_REG = 0
                 */
                ldr     r1, =RESET_STAT_REG
                movs    r0, 0
                str     r0, [r1]

                /* Set SCR.SLEEPDEEP */
                ldr     r9, =SCB_BASE           // address of SCB
                ldr     r0, =.stored_SCR
                ldr     r10, [r0]                // stored value of SCB->SCR
                mov     r0, r10
                orr     r0, #4
                str     r0, [r9, #0x10]

                wfi

                /* we reach this point if deep sleep didn't actually happen */

                /* Restore SCR.SLEEPDEEP */
                str     r10, [r9, #0x10]

                /* Return 0 to the caller of goto_deepsleep() */
                mov     r0, #0
                b       goto_deepsleep_return

                .pool
                .size   goto_deepsleep, . - goto_deepsleep


/* Restore processor state and return to the caller of goto_deepsleep().
 *
 * The reset handler jumps to this function if it detects a wake-up instead of
 * a reset.
 */
                .thumb
                .thumb_func
                .align  1
                .globl  wakeup_from_deepsleep
                .type   wakeup_from_deepsleep, %function

wakeup_from_deepsleep:
#if (BSP_CFG_SLEEP_TRACE_VIA_GPIO )
 #if defined(BSP_MCU_GROUP_RA6B1) || defined(BSP_MCU_GROUP_RA6U1) || (BSP_MCU_GROUP_RA6B2)
                /* Configure up P0_00 */
                ldr     r0, =P0_00_MODE_REG
                movs    r1, #0x300
                str     r1, [r0]
                /* Set P0_00 */
                ldr     r0, =GPIO_P0_SET_DATA_REG
                movs    r1, #1
                str     r1, [r0]
 #endif
#endif
                /* disable interrupts, final state will be set when PRIMASK is restored */
                cpsid   i

                /* set SP to a safe value, we have reserved some space for this case */
                ldr     r0, =__retained_state
                mov     sp, r0

                /*
                 * restore values of NVIC->ISER, NVIC->PRIORITY{0,1,2},
                 *                   SCB->SCR, SCB->SHR[0] (SHPR2) and SCB->SHR[1] (SHPR3)
                 */

                ldr     r0, =.stored_ISER

                /* Restore NVIC->ISER[0..1] */
                ldm     r0!, {r4-r5}
                ldr     r1, =0xE000E100         // address of NVIC->ISER[0]
                stm     r1, {r4-r5}

                /* Restore values of NVIC->IPR[0..55] */
                ldm     r0!, {r2, r4-r12}
                ldr     r1, =0xE000E400         // NVIC->IPR[] base address
                stm     r1!, {r2, r4-r12}
                ldm     r0!, {r4-r7}
                stm     r1, {r4-r7}

                /* Restore
                 *      SCB->SCR,
                 *      SCB->SHRPR1..3
                 *      SCB->SHCSR (<x>FAULTENA fields only)
                 */
                ldm     r0!, {r4-r8}
                ldr     r1, =SCB_BASE
                str     r4, [r1, #0x10]         // SCB->SCR
                str     r5, [r1, #0x18]         // SCB->SHPR1
                str     r6, [r1, #0x1C]         // SCB->SHPR2
                str     r7, [r1, #0x20]         // SCB->SHPR3
                // r8 = saved SHCSR.<x>FAULTENA fields
                ldr     r2, [r1, #0x24]         // read SCB->SHCSR
                orr     r2, r8                  // modify
                str     r2, [r1, #0x24]         // write SCB->SHCSR

                /* r1 = SCB_BASE */

                /* Restore
                 *      CPACR
                 *      FPCCR
                 *      FPDSCR
                 */
                ldm     r0!, {r4-r6}
                /* r4 = .stored_CPACR */
                ldr     r2, [r1, #(CPACR - SCB_BASE)]   // read CPACR
                orr     r2, r4                          // CPACR |= .stored_CPACR
                str     r2, [r1, #(CPACR - SCB_BASE)]   // write back
                /* r5 = .stored_FPCCR */
                ldr     r2, [r1, #(FPCCR - SCB_BASE)]   // read FPCCR
                orr     r2, r5                          // FPCCR |= .stored_FPCCR
                str     r2, [r1, #(FPCCR - SCB_BASE)]   // write back
                /* r6 = .stored_FPDSCR */
                str     r6, [r1, #(FPDSCR - SCB_BASE)]

#if (dg_configUSE_HW_MPU)
                ldr     r1, =#MPU_BASE
                ldm     r0!, {r3}                       // load MPU_CTRL

                /* Disable MPU */
                dmb     0xF
                mov     r2, r3
                and     r2, 0xFFFFFFFE
                str     r2, [r1, #0x4]
                isb     0xF

                /* Restore MPU_RBAR and MPU_RLAR for every region */
                movs    r2, 0
.mpu_restore_loop:
                str     r2, [r1, #0x8]                  // set MPU_RNR
                ldm     r0!, {r4-r5}
                str     r4, [r1, #0xC]                  // load MPU_RBAR
                str     r5, [r1, #0x10]                 // load MPU_RLAR
                adds    r2, #1
                cmp     r2, #MPU_NUM_REGIONS
                blt     .mpu_restore_loop               // if all region registers have been accessed exit loop

                /* Restore MPU_MAIR0 and MPU_MAIR1  */
                ldm     r0!, {r4-r5}
                str     r4, [r1, #0x30]                 // load MPU_MAIR0
                str     r5, [r1, #0x34]                 // load MPU_MAIR1

                /* Restore MPU_CTRL */
                str     r3, [r1, #0x4]
                dsb     0xF
                isb     0XF
#endif

#if (BSP_CFG_MTB_ENABLE)
                /* restore MTB */
                ldm     r0!, {r4-r6}
                ldr     r2, =#MTB_MASTER_REG
                str     r5, [r2]
                ldr     r2, =#MTB_POSITION_REG
                str     r4, [r2]
                ldr     r2, =#MTB_FLOW_REG
                str     r6, [r2]
#endif

#if defined(BSP_MCU_GROUP_RA6B1) || defined(BSP_MCU_GROUP_RA6U1) || (BSP_MCU_GROUP_RA6B2)
                ldr     r1, =PDC_BASE
                ldr     r1, [r1, PDC_CHANGE_PDSYS_POWER_MODE_OFFSET]
                cmp     r1, #0
                beq     .restore_msp_psp_control
#endif

                ldr     r1, =ICU_IELSR_REG              // r1 = &ICU->ICU_IELSR0_REG
                movs    r2, #0
.icu_restore_loop:                                      // loop to restore ICU_IELSR_REG[0...39]
                ldm     r0!, {r3-r12}
                stm     r1!, {r3-r12}
                adds    r2, #1
                cmp     r2, #4
                blt     .icu_restore_loop

                ldm     r0!, {r3-r6}                    // restore ICU_IELSR_REG[40...43]
                stm     r1!, {r3-r6}

                /* Restore ELCR register of ELC. */
                ldm     r0!, {r2}
                ldr     r1, =ELC_ELCR_REG
                stm     r1, {r2}

                /* Restore non-retained ELSR entries of ELC. */
                ldr     r1, =ELC_ELSR_REG
                movs    r2, #0
.elc_elsr_restore_loop:
                ldm     r0!, {r3-r12}
                stm     r1!, {r3-r12}
                adds    r2, #1
                cmp     r2, #3
                blt    .elc_elsr_restore_loop

                /* Retore ELC Groups' configuration. */
                ldr     r1, =ELC_ELGRP_REG
                ldm     r0!, {r3-r12}
                stm     r1!, {r3-r12}

.restore_msp_psp_control:
                /* restore MSP, PSP, CONTROL */
                ldr     r0, =.stored_MSP
                ldm     r0, {r1-r3}
                msr     msp, r1
                msr     psp, r2
                msr     control, r3

                /* Return 1 to the caller of goto_deepsleep() */
                mov     r0, #1
                b       goto_deepsleep_return

                .pool
                .size   wakeup_from_deepsleep, . - wakeup_from_deepsleep

/*
 * Return to the caller of goto_deepsleep().
 *
 * Parameters:
 *      int sleep_was_entered: the value to be returned by goto_deepsleep() to its caller
 */
                .thumb
                .thumb_func
                .align  1
                .type   goto_deepsleep_return, %function

goto_deepsleep_return:
                /* restore R4-R12, LR */
                ldr     r1, =.stored_R4
                ldm     r1, {r4-r12, lr}

                /* Restore PRIMASK */
                ldr     r2, [r1, #(.stored_PRIMASK - .stored_R4)]
                msr     PRIMASK, r2

                /* Interrupts might be enabled now */

#if (BSP_CFG_SLEEP_TRACE_VIA_GPIO )
 #if defined(BSP_MCU_GROUP_RA6B1) || defined(BSP_MCU_GROUP_RA6U1) || (BSP_MCU_GROUP_RA6B2)
                /* Reset GPIO P0_00 */
                ldr     r2, =GPIO_P0_RESET_DATA_REG
                movs    r1, #1
                str     r1, [r2]
 #endif
#endif
                bx      lr

                .pool
                .size   goto_deepsleep_return, . - goto_deepsleep_return
