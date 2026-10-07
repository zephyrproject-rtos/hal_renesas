/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "bsp_api.h"
#include "bsp_cfg.h"

#pragma language=extended

#define STR2(x)                                #x
#define STR(x)                                 STR2(x)

/* FIXME: remove temporary local configuration */
#define dg_configENABLE_MTB                    (1)
#define dg_configUSE_HW_MPU                    (0)

#define RESET_STAT_REG                         (0x401000BCu)
#define ICU_IELSR_REG                          (0x25000300u)
#define ELC_ELCR_REG                           (0x25020000u)
#define ELC_ELSR_REG                           (0x25020010u)
#define ELC_ELGRP_REG                          (0x25020090u)
#define SCB_SHCSR_xFAULTENA_MASK               ((1 << 19) | (1 << 18) | (1 << 17) | (1 << 16))

#define CPACR                                  (0xE000ED88u)

#define FPCCR                                  (0xE000EF34u)
#define FPDSCR                                 (0xE000EF3Cu)

#if (BSP_CFG_SLEEP_TRACE_VIA_GPIO)
 #define GPIO_P0_SET_DATA_REG                  (0x40100C0C)
 #define P0_00_MODE_REG                        (0x40100C24)
 #define GPIO_P0_RESET_DATA_REG                (0x40100C18)
#endif

#if (dg_configUSE_HW_MPU)
 #define MPU_NUM_REGIONS                       (0x8)
 #define MPU_BASE                              (0xE000ED90)
#endif

#if (dg_configENABLE_MTB)
 #define MTB_POSITION_REG                      (0xE0043000)
 #define MTB_MASTER_REG                        (0xE0043004)
 #define MTB_FLOW_REG                          (0xE0043008)
#endif

#if defined(BOARD_RA6B1_PRODK) || defined(BOARD_RA6U1_EK)
 #define PDC_CHANGE_PDSYS_POWER_MODE_OFFSET    (0xD0)
#endif

#define CPACR_OFF                              (CPACR - SCB_BASE)
#define FPCCR_OFF                              (FPCCR - SCB_BASE)
#define FPDSCR_OFF                             (FPDSCR - SCB_BASE)

#define OFF_STORED_PRIMASK                     (64)
#define OFF_STORED_R4                          (68)
#define OFF_STORED_MSP                         (108)
#define OFF_STORED_ISER                        (120)
#define OFF_STORED_SCR                         (184)

/*
 *  The processor state is stored here before going to deep sleep,
 *  so that it is restored after wakeup.
 */
typedef struct
{
    uint8_t  pad[64];
    uint32_t stored_PRIMASK;
    uint32_t stored_R4;
    uint32_t stored_R5;
    uint32_t stored_R6;
    uint32_t stored_R7;
    uint32_t stored_R8;
    uint32_t stored_R9;
    uint32_t stored_R10;
    uint32_t stored_R11;
    uint32_t stored_R12;
    uint32_t stored_LR;
    uint32_t stored_MSP;
    uint32_t stored_PSP;
    uint32_t stored_CONTROL;
    uint32_t stored_ISER;
    uint32_t stored_ISER1;
    uint32_t stored_PRIORITY0;
    uint32_t stored_PRIORITY1;
    uint32_t stored_PRIORITY2;
    uint32_t stored_PRIORITY3;
    uint32_t stored_PRIORITY4;
    uint32_t stored_PRIORITY5;
    uint32_t stored_PRIORITY6;
    uint32_t stored_PRIORITY7;
    uint32_t stored_PRIORITY8;
    uint32_t stored_PRIORITY9;
    uint32_t stored_PRIORITY10;
    uint32_t stored_PRIORITY11;
    uint32_t stored_PRIORITY12;
    uint32_t stored_PRIORITY13;
    uint32_t stored_SCR;
    uint32_t stored_SHPR1;
    uint32_t stored_SHPR2;
    uint32_t stored_SHPR3;
    uint32_t stored_SHCSR_xFAULTENA;

    uint32_t stored_CPACR;
    uint32_t stored_FPCCR;
    uint32_t stored_FPDSCR;

#if (dg_configUSE_HW_MPU)
    uint32_t stored_MPU_CTRL;
    uint32_t stored_MPU_REGIONS[16];
    uint32_t stored_MPU_MAIR0;
    uint32_t stored_MPU_MAIR1;
#endif

#if (dg_configENABLE_MTB)
    uint32_t stored_MTB_POSITION;
    uint32_t stored_MTB_MASTER;
    uint32_t stored_MTB_FLOW;
#endif

    /* Reserve space for storing the 44 non-retained IELSR registers of ICU.
    * Only IELSR[44...59] are retained when PD_MEM is powered off.
    */
    uint32_t stored_ICU_IELSR[44];      /* 44 * 4 = 176 bytes */

    /* Reserve space for storing the ELCR register of ELC. */
    uint32_t stored_ELC_ELCR;

    /* Reserve space for storing the 30 ELSR registers of ELC. */
    uint32_t stored_ELC_ELSR[30];       /* 30 * 4 = 120 bytes */

    /* Reserve space for storing the 10 ELGRP registers of ELC. */
    uint32_t stored_ELC_ELCGRP[10];     /* 10 * 4 = 40 bytes */
} retained_state_t;

#pragma data_alignment=8
__no_init __root retained_state_t __retained_state;

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

#pragma location=".ram_code_from_flash"
BSP_ATTRIBUTE_STACKLESS void goto_deepsleep (void)
{
    __asm volatile (

        /* TODO: we also need to store BASEPRI */

        /* Store PRIMASK and disable interrupts */
        "MRS     r0, PRIMASK                         \n"
        "CPSID   i                                   \n"
        "LDR     r3, =__retained_state               \n"
        "ADDS    r3, r3,#"STR (OFF_STORED_PRIMASK) " \n"
        "STM     r3!, {r0}                           \n"

        /* store R4-R12, LR */
        "STM     r3!, {r4-r12, lr}                  \n"

        /* Store MSP, PSP, CONTROL */
        "MRS     r0, MSP                            \n"
        "MRS     r1, PSP                            \n"
        "MRS     r2, CONTROL                        \n"
        "STM     r3!, {r0-r2}                       \n"

        /* Store NVIC->ISER[0..1] */
        "LDR     r0, =0xE000E100                    \n"
        "LDM     r0, {r4-r5}                        \n"
        "STM     r3!, {r4-r5}                       \n"

        /* Save values of NVIC->IPR[0..55] */
        "LDR     r0, =0xE000E400                    \n" // NVIC->IPR[] base address
        "LDM     r0!, {r2, r4-r12}                  \n"
        "STM     r3!, {r2, r4-r12}                  \n"
        "LDM     r0, {r4-r7}                        \n"
        "STM     r3!, {r4-r7}                       \n"

        /*
         * Store
         *      SCB->SCR
         *      SCB->SHPR1..3
         *      SCB->SHCSR (<x>FAULTENA fields only)
         */
        "LDR     r0, =" STR(SCB_BASE) "                     \n"
        "LDR     r4, [r0, #0x10]                            \n" // value of SCB->SCR
        "LDR     r5, [r0, #0x18]                            \n" // value of SCB->SHPR1
        "LDR     r6, [r0, #0x1C]                            \n" // value of SCB->SHPR2
        "LDR     r7, [r0, #0x20]                            \n" // value of SCB->SHPR3
        "LDR     r8, [r0, #0x24]                            \n" // value of SCB->SHCSR
        "LDR     r12, =" STR(SCB_SHCSR_xFAULTENA_MASK) "    \n" // keep only the <x>FAULTENA fields
        "AND     r8, r8, r12                                \n"
        "STM     r3!, {r4-r8}                               \n"

        /* Store CPACR, FPCCR, FPDSCR */
        "LDR     r4, [r0, #"STR (CPACR_OFF) "]      \n"     // load CPACR
        "LDR     r12, =(0xF << 20)                  \n"     // keep only CP11 and CP10
        "AND     r4, r4, r12                        \n"
        "LDR     r5, [r0, #"STR (FPCCR_OFF) "]      \n"     // load FPCCR
        "LDR     r12, =(0xF << 28)                  \n"     // keep only ASPEN, LSPEN, CLRONRET
        "AND     r5, r5, r12                        \n"
        "LDR     r6, [r0, #"STR (FPDSCR_OFF) "]     \n"     // load FPDSCR
        "STM     r3!, {r4-r6}                       \n"

#if (dg_configUSE_HW_MPU)

        /* Store MPU_CTRL  */
        "LDR     r0, =" STR(MPU_BASE) "             \n" // load MPU_CTRL address
        "LDR     r4, [r0, #0x4]                     \n" // value of MPU_CTRL
        "STM     r3!, {r4}                          \n" // store value of MPU_CTRL

        /* Store MPU_RBAR and MPU_RLAR for every region */
        "MOVS    r4, #0                             \n"
        "mpu_store_loop:                            \n"
        "STR     r4, [r0, #0x8]                     \n" // set MPU_RNR
        "LDR     r6, [r0, #0xC]                     \n" // read MPU_RBAR
        "LDR     r7, [r0, #0x10]                    \n" // read MPU_RLAR
        "STM     r3!, {r6-r7}                       \n"
        "ADDS    r4, r4, #1                         \n"
        "CMP     r4, #" STR(MPU_NUM_REGIONS) "      \n"
        "BLT     mpu_store_loop                     \n"

        /* Store MPU_MAIR0 and MPU_MAIR1  */
        "LDR     r6, [r0, #0x30]                    \n" // value of MPU_MAIR0
        "LDR     r7, [r0, #0x34]                    \n" // value of MPU_MAIR1
        "STM     r3!, {r6-r7}                       \n" // store values of MPU_MAIR0 and MPU_MAIR1
#endif

#if (dg_configENABLE_MTB)

        /* Store MTB  */
        "LDR     r0, =" STR(MTB_POSITION_REG) "     \n" // load MTB_POSITION_REG address
        "LDM     r0, {r4-r6}                        \n" // value of MTB_POSITION_REG MTB_MASTER_REG, MTB_FLOW_REG
        "STM     r3!, {r4-r6}                       \n"
#endif

        /* Store non-retained IELSR entries of ICU. */
        "LDR     r1, =" STR(ICU_IELSR_REG) "        \n" // r1 = &ICU->ICU_IELSR0_REG
        "MOVS    r0, #0                             \n"
        "icu_store_loop:                            \n"
        "LDM     r1!, {r2, r4-r12}                  \n"
        "STM     r3!, {r2, r4-r12}                  \n"
        "ADDS    r0, r0, #1                         \n"
        "CMP     r0, #4                             \n"
        "BLT     icu_store_loop                     \n"
        "LDM     r1!, {r4-r7}                       \n" // store ICU_IELSR_REG[40...43]
        "STM     r3!, {r4-r7}                       \n"

        /* Store ELCR register of ELC. */
        "LDR     r0, =" STR(ELC_ELCR_REG) "         \n"
        "LDR     r1, [r0]                           \n"
        "STM     r3!, {r1}                          \n"

        /* Store non-retained ELSR entries of ELC. */
        "LDR     r1, =" STR(ELC_ELSR_REG) "         \n"
        "MOVS    r0, #0                             \n"
        "elc_elsr_store_loop:                       \n"
        "LDM     r1!, {r2, r4-r12}                  \n"
        "STM     r3!, {r2, r4-r12}                  \n"
        "ADDS    r0, r0, #1                         \n"
        "CMP     r0, #3                             \n"
        "BLT     elc_elsr_store_loop                \n"

        /* Store ELC Groups' configuration. */
        "LDR     r1, ="STR(ELC_ELGRP_REG) "         \n"
        "LDM     r1!, {r2, r4-r12}                  \n"
        "STM     r3!, {r2, r4-r12}                  \n"
        "clear_reset_stat_reg:                      \n"

        /*
         *  Set RESET_STAT_REG = 0
         */
        "LDR     r1, ="STR(RESET_STAT_REG) "        \n"
        "MOVS    r0, #0                             \n"
        "STR     r0, [r1]                           \n"

        /* Set SCR.SLEEPDEEP */
        "LDR     r9, ="STR(SCB_BASE) "              \n" // address of SCB
        "LDR     r0, =__retained_state              \n"
        "ADDS    r0, r0, #"STR(OFF_STORED_SCR) "    \n"
        "LDR     r10, [r0]                          \n" // stored value of SCB->SCR
        "MOV     r0, r10                            \n"
        "ORR     r0, r0, #4                         \n"
        "STR     r0, [r9, #0x10]                    \n"
        "WFI                                        \n"

        /* we reach this point if deep sleep didn't actually happen */

        /* Restore SCR.SLEEPDEEP */
        "STR     r10, [r9, #0x10]                   \n"
         
        /* Return 0 to the caller of goto_deepsleep() */
        "MOVS    r0, #0                             \n"
        "B.W     goto_deepsleep_return              \n"
    );
}

/* Restore processor state and return to the caller of goto_deepsleep().
 *
 * The reset handler jumps to this function if it detects a wake-up instead of
 * a reset.
 */

#pragma location=".ram_code_from_flash"
BSP_ATTRIBUTE_STACKLESS void wakeup_from_deepsleep (void)
{
    __asm volatile (
#if (BSP_CFG_SLEEP_TRACE_VIA_GPIO)

        /* Configure up P0_00 */
        "LDR     r0, =" STR(P0_00_MODE_REG) "       \n"
        "MOVW    r1, #0x300                         \n"
        "STR     r1, [r0]                           \n"

        /* Set P0_00 */
        "LDR     r0, =" STR(GPIO_P0_SET_DATA_REG) " \n"
        "MOVS    r1, #1                             \n"
        "STR     r1, [r0]                           \n"
#endif

        /* disable interrupts, final state will be set when PRIMASK is restored */
        "CPSID   i                                  \n"

        /* set SP to a safe value, we have reserved some space for this case */
        "LDR     r0, =__retained_state              \n"
        "MOV     sp, r0                             \n"

        /*
         * restore values of NVIC->ISER, NVIC->PRIORITY{0,1,2},
         *                   SCB->SCR, SCB->SHR[0] (SHPR2) and SCB->SHR[1] (SHPR3)
         */
        "LDR     r0, =__retained_state              \n"
        "ADDS    r0, r0, #" STR(OFF_STORED_ISER) "  \n"

        /* Restore NVIC->ISER[0..1] */
        "LDM     r0!, {r4-r5}                       \n"
        "LDR     r1, =0xE000E100                    \n" // address of NVIC->ISER[0]
        "STM     r1, {r4-r5}                        \n"

        /* Restore values of NVIC->IPR[0..55] */
        "LDM     r0!, {r2, r4-r12}                  \n"
        "LDR     r1, =0xE000E400                    \n" // NVIC->IPR[] base address
        "STM     r1!, {r2, r4-r12}                  \n"
        "LDM     r0!, {r4-r7}                       \n"
        "STM     r1, {r4-r7}                        \n"

        /* Restore
         *      SCB->SCR,
         *      SCB->SHRPR1..3
         *      SCB->SHCSR (<x>FAULTENA fields only)
         */
        "LDM     r0!, {r4-r8}                       \n"
        "LDR     r1, =" STR(SCB_BASE) "             \n"
        "STR     r4, [r1, #0x10]                    \n" // SCB->SCR
        "STR     r5, [r1, #0x18]                    \n" // SCB->SHPR1
        "STR     r6, [r1, #0x1C]                    \n" // SCB->SHPR2
        "STR     r7, [r1, #0x20]                    \n" // SCB->SHPR3
        // r8 = saved SHCSR.<x>FAULTENA fields
        "LDR     r2, [r1, #0x24]                    \n" // read SCB->SHCSR
        "ORR     r2, r2, r8                         \n" // modify
        "STR     r2, [r1, #0x24]                    \n" // write SCB->SHCSR

        /* r1 = SCB_BASE */

        /* Restore
         *      CPACR
         *      FPCCR
         *      FPDSCR
         */
        "LDM     r0!, {r4-r6}                       \n"

        /* r4 = .stored_CPACR */
        "LDR     r2, [r1, #" STR(CPACR_OFF) "]      \n" // read CPACR
        "ORR     r2, r2, r4                         \n" // CPACR |= .stored_CPACR
        "STR     r2, [r1, #" STR(CPACR_OFF) "]      \n" // write back

        /* r5 = .stored_FPCCR */
        "LDR     r2, [r1, #" STR(FPCCR_OFF) "]      \n" // read FPCCR
        "ORR     r2, r2, r5                         \n" // FPCCR |= .stored_FPCCR
        "STR     r2, [r1, #" STR(FPCCR_OFF) "]      \n" // write back

        /* r6 = .stored_FPDSCR */
        "STR     r6, [r1, #" STR(FPDSCR_OFF) "]     \n"

#if (dg_configUSE_HW_MPU)
        "LDR     r1, =" STR(MPU_BASE) "             \n"
        "LDM     r0!, {r3}                          \n" // load MPU_CTRL

        /* Disable MPU */
        "DMB     0xF                                \n"
        "MOV     r2, r3                             \n"
        "LDR     r12, 0xFFFFFFFE                    \n"
        "AND     r2, r2, r12                        \n"
        "STR     r2, [r1, #0x4]                     \n"
        "ISB     0xF                                \n"

        /* Restore MPU_RBAR and MPU_RLAR for every region */
        "MOVS    r2, #0                             \n"
        "mpu_restore_loop:                          \n"
        "STR     r2, [r1, #0x8]                     \n" // set MPU_RNR
        "LDM     r0!, {r4-r5}                       \n"
        "STR     r4, [r1, #0xC]                     \n" // load MPU_RBAR
        "STR     r5, [r1, #0x10]                    \n" // load MPU_RLAR
        "ADDS    r2, r2, #1                         \n"
        "CMP     r2, #" STR(MPU_NUM_REGIONS) "      \n"
        "BLT     mpu_restore_loop                   \n" // if all region registers have been accessed exit loop

        /* Restore MPU_MAIR0 and MPU_MAIR1  */
        "LDM     r0!, {r4-r5}                       \n"
        "STR     r4, [r1, #0x30]                    \n" // load MPU_MAIR0
        "STR     r5, [r1, #0x34]                    \n" // load MPU_MAIR1

        /* Restore MPU_CTRL */
        "STR     r3, [r1, #0x4]                     \n"
        "DSB     0xF                                \n"
        "ISB     0XF                                \n"
#endif

#if (dg_configENABLE_MTB)

        /* restore MTB */
        "LDM     r0!, {r4-r6}                       \n"
        "LDR     r2, =" STR(MTB_MASTER_REG) "       \n"
        "STR     r5, [r2]                           \n"
        "LDR     r2, =" STR(MTB_POSITION_REG) "     \n"
        "STR     r4, [r2]                           \n"
        "LDR     r2, =" STR(MTB_FLOW_REG) "         \n"
        "STR     r6, [r2]                           \n"
#endif

#if defined(BOARD_RA6B1_PRODK) || defined(BOARD_RA6U1_EK)
        "LDR     r1, =" STR(PDC_BASE) "                                 \n"
        "LDR     r1, [r1, #" STR(PDC_CHANGE_PDSYS_POWER_MODE_OFFSET) "] \n"
        "CMP     r1, #0                                                 \n"
        "BEQ     restore_msp_psp_control                                \n"
#endif

        "LDR     r1, =" STR(ICU_IELSR_REG) "        \n" // r1 = &ICU->ICU_IELSR0_REG
        "MOVS    r2, #0                             \n"
        "icu_restore_loop:                          \n" // loop to restore ICU_IELSR_REG[0...39]
        "LDM     r0!, {r3-r12}                      \n"
        "STM     r1!, {r3-r12}                      \n"
        "ADDS    r2, r2, #1                         \n"
        "CMP     r2, #4                             \n"
        "BLT     icu_restore_loop                   \n"
        "LDM     r0!, {r3-r6}                       \n" // restore ICU_IELSR_REG[40...43]
        "STM     r1!, {r3-r6}                       \n"

        /* Restore ELCR register of ELC. */
        "LDM     r0!, {r2}                          \n"
        "LDR     r1, =" STR(ELC_ELCR_REG) "         \n"
        "STM     r1, {r2}                           \n"

        /* Restore non-retained ELSR entries of ELC. */
        "LDR     r1, =" STR(ELC_ELSR_REG) "         \n"
        "MOVS    r2, #0                             \n"
        "elc_elsr_restore_loop:                     \n"
        "LDM     r0!, {r3-r12}                      \n"
        "STM     r1!, {r3-r12}                      \n"
        "ADDS    r2, r2, #1                         \n"
        "CMP     r2, #3                             \n"
        "BLT     elc_elsr_restore_loop              \n"

        /* Retore ELC Groups' configuration. */
        "LDR     r1, =" STR(ELC_ELGRP_REG) "        \n"
        "LDM     r0!, {r3-r12}                      \n"
        "STM     r1!, {r3-r12}                      \n"
        "restore_msp_psp_control:                   \n"

        /* restore MSP, PSP, CONTROL */
        "LDR     r0, =__retained_state              \n"
        "ADDS    r0, r0, #" STR(OFF_STORED_MSP) "   \n"
        "LDM     r0, {r1-r3}                        \n"
        "MSR     msp, r1                            \n"
        "MSR     psp, r2                            \n"
        "MSR     control, r3                        \n"

        /* Return 1 to the caller of goto_deepsleep() */
        "MOV     r0, #1                             \n"
        "B.W     goto_deepsleep_return              \n"
        );
}

/*
 * Return to the caller of goto_deepsleep().
 *
 * Parameters:
 *      int sleep_was_entered: the value to be returned by goto_deepsleep() to its caller
 */

#pragma location=".ram_code_from_flash"
BSP_ATTRIBUTE_STACKLESS int goto_deepsleep_return (int sleep_was_entered)
{
    __asm volatile (

        /* restore R4-R12, LR */
        "LDR     r1, =__retained_state                  \n"
        "ADDS    r1, r1, #" STR(OFF_STORED_R4) "        \n"
        "LDM     r1, {r4-r12, lr}                       \n"

        /* Restore PRIMASK */
        "LDR     r2, =__retained_state                  \n"
        "ADDS    r2, r2, #" STR(OFF_STORED_PRIMASK) "   \n"
        "LDR     r2, [r2]                               \n"
        "MSR     PRIMASK, r2                            \n"

        /* Interrupts might be enabled now */

#if (BSP_CFG_SLEEP_TRACE_VIA_GPIO)

        /* Reset GPIO P0_00 */
        "LDR     r2, =" STR(GPIO_P0_RESET_DATA_REG) "   \n"
        "MOVS    r1, #1                                 \n"
        "STR     r1, [r2]                               \n"
#endif
        "BX      lr                                     \n"
        );

    return sleep_was_entered;
}
