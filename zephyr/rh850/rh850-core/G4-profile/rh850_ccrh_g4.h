/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_ccrh_g4.h
 * @brief    RH850 G4 CCRH function
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#ifndef __RH850_CCRH_G4_H
#define __RH850_CCRH_G4_H

#ifndef __RH850_CCRH_H
 #error "This file must not be included directly"
#endif

/** @defgroup RH850_CoreAccess_FunctionInterface RH850-Core Access Functions
 * @brief Access to the dedicated core access function.
 * @{
 */

/** @defgroup RH850_Core_AtomicFunctions RH850-Core Atomic Access Functions
 * @ingroup RH850_CoreAccess_FunctionInterface
 * @brief RH850-Core Atomic Access Functions
 * @{
 */

/** @defgroup CCRH_RH850_Core_AtomicFunctions CCRH RH850-Core Atomic Access Functions
 * @brief CCRH RH850-Core Atomic Access Functions
 * @ingroup RH850_Core_AtomicFunctions
 * @{
 */

/* ########################################  Atomic Function Access  ################################################ */

/**
 * @brief   Release a spinlock
 * @details Clear the lock by storing 0 to the given address.
 *          On RH850, this uses a normal store to memory, releasing the lock held by another core/task.
 * @param[in]  LpAddr   Pointer to the spinlock variable in memory.
 * @note    CC-RH inline assembly function; first parameter is passed in r6.
 *          Implementation: \code st.w r0, [r6] \endcode
 * @pre     \p Addr must be aligned to word size and visible to all participating cores.
 */
#pragma inline_asm RH850_SpinlockRelease
static void RH850_SpinlockRelease (uint32_t * LpAddr)
{
    st.w r0, 0[r6]
}

/**
 * @brief   Acquire a spinlock (blocking)
 * @details Attempt to acquire the spinlock using LL/SC (load-linked/store-conditional) primitive:
 *          - Load-linked the current value at \p Addr.
 *          - If unlocked (0), try store-conditional of 1.
 *          - If SC succeeds, the lock is acquired and the function returns.
 *          - Otherwise, enter low-power wait (snooze) and retry.
 * @param[in]  LpAddr   Pointer to the spinlock variable in memory.
 * @note    CC-RH inline assembly function; first parameter is passed in r6 (ABI).
 *          Uses the LL/SC pair \code ldl.w \endcode and \code stc.w \endcode with a wait loop using \code snooze \endcode.
 * @pre     \p Addr must be aligned to word size and shared/uncached or properly coherent across cores.
 */
#pragma inline_asm RH850_SpinlockGet
static void RH850_SpinlockGet (uint32_t * LpAddr)
{
    .local _L_SpinlockGet_Lock_Loop
    .local _L_SpinlockGet_Lock_Wait
    .local _L_SpinlockGet_Lock_Success

_L_SpinlockGet_Lock_Loop:
    ldl.w[r6], r7;                     /* r7 = *LpAddr (linked) */
    cmp r0, r7;                        /* is *LpAddr == 0 ? */
    bnz _L_SpinlockGet_Lock_Wait;      /* Lock_wait */
    mov      1, r7;
    stc.w r7, [r6];                    /* try to set *LpAddr = 1 (conditional) */
    cmp   r0, r7;                      /* stc.w result (0/1) in r7 on RH850; nonzero => success */
    bnz _L_SpinlockGet_Lock_Success

_L_SpinlockGet_Lock_Wait:
    snooze
    br _L_SpinlockGet_Lock_Loop

_L_SpinlockGet_Lock_Success:
}

/** @} */ /* end of CCRH_RH850_Core_AtomicFunctions */
/** @} */ /* end of RH850_Core_AtomicFunctions */

#if defined(__FPU_PRESENT) && (__FPU_PRESENT == 1U)

/* ##########################################  FPU Function Access  ################################################# */

/**
 * @ingroup RH850_FPU_API
 * @{
 */

/**
 * @brief Initialize the Floating Point Unit (FPU).
 * @details
 * This function enables the FPU and initializes its status registers.
 *
 * **Operation steps:**
 *  - Detect if FPU is present using PID register (SR6,1).
 *  - Enable FPU by setting the appropriate bit in PSW (SR5,0).
 *  - Initialize FPSR (SR6,0) and FPEPC (SR7,0) registers.
 *
 * **Registers used:**
 *  - PID: Processor Identification (SR6,1)
 *  - PSW: Program Status Word (SR5,0)
 *  - FPSR: Floating Point Status Register (SR6,0)
 *  - FPEPC: Floating Point Exception Program Counter (SR7,0)
 */
 #pragma inline_asm RH850_FPU_Init
static void RH850_FPU_Init (void)
{
    .local _L_FPU_Init_End
    ;                                  /* enable FPU */
    stsr  6, r10, 1;                   /* r10 <- PID */
    shl   21, r10;
    shr   30, r10;
    bz _L_FPU_Init_End;                /* detecting FPU */
    stsr  5, r10, 0;                   /* r10 < -PSW */
    movhi 0x0001, r0, r11;
    or   r11, r10;
    ldsr r10, 5, 0;                    /* enable FPU */

    movhi 0x0002, r0, r11;
    ldsr r11, 6, 0;                    /* initialize FPSR */
    ldsr r0, 7, 0;                     /* initialize FPEPC */
_L_FPU_Init_End:
}

/** @} */ /* end of RH850_FPU_API */
#endif                                 /* #if defined(__FPU_PRESENT) && (__FPU_PRESENT == 1U) */

#if defined(__FXU_PRESENT) && (__FXU_PRESENT == 1U)

/* ##########################################  FXU Function Access  ################################################# */

/**
 * @ingroup RH850_FXU_API
 * @{
 */

/**
 * @brief Initialize the Fixed-Point Unit (FXU).
 * @details
 * This function enables the FXU and initializes its configuration and status registers.
 *
 * **Operation steps:**
 *  - Detect FXU presence using the PID register (SR6,1) by checking the relevant capability bits.
 *  - Enable FXU by setting the appropriate bit(s) in PSW (SR5,0).
 *  - Initialize FXU control/status registers: FXSR, FXST, FXCFG (bank 10).
 *
 * **Registers used:**
 *  - PID: Processor Identification (SR6,1) — capability detection
 *  - PSW: Program Status Word (SR5,0) — enable FXU in status word
 *  - FXSR: FXU Status Register (SR6,10)
 *  - FXST: FXU Status (SR8,10)
 *  - FXCFG: FXU Configuration (SR10,10)
 *
 * @note This function uses CC-RH inline assembly syntax and assumes the ABI/register usage as written.
 */
 #pragma inline_asm RH850_FXU_Init
static void RH850_FXU_Init (void)
{
    .local _L_FXU_Init_End
    stsr  6, r10, 1;                   /* r10 <- PID */
    shl   20, r10;
    shr   31, r10;
    bz _L_FXU_Init_End;                /* detecting FXU */
    stsr  5, r10, 0;                   /* r10 <- PSW */
    movhi 0x0002, r0, r11
    or r11, r10;
    ldsr r10, 5, 0;                    /* enable FXU */

    movhi 0x0002, r0, r11;
    ldsr r11, 6, 10;                   /* initialize FXSR */
    ldsr r0, 8, 10;                    /* initialize FXST */
    ldsr r0, 10, 10;                   /* initialize FXCFG */
_L_FXU_Init_End:
}

/** @} */ /* end of RH850_FXU_API */
#endif                                 /* #if defined(__FXU_PRESENT) && (__FXU_PRESENT == 1U) */

/** @} */ /* end of RH850_Core_intrinsics */
/** @} */ /* end of RH850_CoreAccess_FunctionInterface */

#endif                                 /* __RH850_CCRH_G4_H */
