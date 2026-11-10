/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_gcc_g4.h
 * @brief    RH850 G4 GCC function
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#ifndef __RH850_GCC_G4_H
#define __RH850_GCC_G4_H

/** @defgroup RH850_CoreAccess_FunctionInterface RH850-Core Access Functions
 * @brief Access to the dedicated core access function.
 * @{
 */

/** @defgroup RH850_Core_AtomicFunctions RH850-Core Atomic Access Functions
 * @ingroup RH850_CoreAccess_FunctionInterface
 * @brief RH850-Core Atomic Access Functions
 * @{
 */

/** @defgroup GCC_RH850_Core_AtomicFunctions GCC RH850-Core Atomic Access Functions
 * @brief GCC RH850-Core Atomic Access Functions
 * @ingroup RH850_Core_AtomicFunctions
 * @{
 */

/* ########################################  Atomic Function Access  ################################################ */

/**
 * @brief   Release a spinlock
 * @details Clear the lock by storing 0 to the given address.
 *          On RH850, this uses a normal store to memory, releasing the lock held by another core/task.
 * @param[in]  LpAddr   Pointer to the spinlock variable in memory.
 * @pre     \p Addr must be aligned to word size and visible to all participating cores.
 */
__STATIC_INLINE void RH850_SpinlockRelease (volatile uint32_t * LpAddr)
{
    __ASM volatile ("st.w r0, 0[%0]" : : "r" (LpAddr) : "memory");
}

/**
 * @brief   Acquire a spinlock (blocking)
 * @details Attempt to acquire the spinlock using LL/SC (load-linked/store-conditional) primitive:
 *          - Load-linked the current value at \p Addr.
 *          - If unlocked (0), try store-conditional of 1.
 *          - If SC succeeds, the lock is acquired and the function returns.
 *          - Otherwise, enter low-power wait (snooze) and retry.
 * @param[in]  LpAddr   Pointer to the spinlock variable in memory.
 * @pre     \p Addr must be aligned to word size and shared/uncached or properly coherent across cores.
 */
__STATIC_INLINE void RH850_SpinlockGet (volatile uint32_t * LpAddr)
{
    __ASM volatile (
        "_L_SpinlockGet_Lock_Loop%=:                                   \n"
        "    ldl.w      [%0], r20                                      \n" /* LpAddr */
        "    cmp        r0, r20                                        \n" /* is *LpAddr == 0 ? */
        "    bnz        _L_SpinlockGet_Lock_Wait%=                     \n" /* Lock_wait */
        "    mov        1, r20                                         \n"
        "    stc.w      r20, [%0]                                      \n" /* try to set *LpAddr = 1 (conditional) */
        "    cmp        r0, r20                                        \n" /* stc.w result (0/1); nonzero => success */
        "    bnz        _L_SpinlockGet_Lock_Success%=                  \n"
        "                                                              \n"
        "_L_SpinlockGet_Lock_Wait%=:                                   \n"
        "    snooze                                                    \n"
        "    br         _L_SpinlockGet_Lock_Loop%=                     \n"
        "                                                              \n"
        "_L_SpinlockGet_Lock_Success%=:                                \n"
        :
        : "r" (LpAddr)
        : "memory", "r20"
        );
}

/** @} */ /* end of GCC_RH850_Core_AtomicFunctions */
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
__STATIC_INLINE void RH850_FPU_Init (void)
{
    __ASM volatile (
        "    stsr   6, r15, 1                   \n" /* r10 <- PID */
        "    shl    21, r15                     \n"
        "    shr    30, r15                     \n"
        "    bz     _L_FPU_Init_End%=           \n" /* detecting FPU */
        "    stsr   5, r15, 0                   \n" /* r10 < -PSW */
        "    movhi  0x0001, r0, r16             \n"
        "    or     r16, r15                    \n"
        "    ldsr   r15, 5, 0                   \n" /* enable FPU */
        "                                       \n"
        "    movhi  0x0002, r0, r16             \n"
        "    ldsr   r16, 6, 0                   \n" /* initialize FPSR */
        "    ldsr   r0, 7, 0                    \n" /* initialize FPEPC */
        "_L_FPU_Init_End%=:                     \n"
        :
        :
        : "r15", "r16", "memory"
        );
}

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
 */
__STATIC_INLINE void RH850_FXU_Init (void)
{
    __ASM volatile (
        "    stsr    6, r15, 1                          \n" /* r10 <- PID */
        "    shl     20, r15                            \n"
        "    shr     31, r15                            \n"
        "    bz      _L_FXU_Init_End%=                  \n" /* detecting FXU */
        "    stsr    5, r15, 0                          \n" /* r10 <- PSW */
        "    movhi   0x0002, r0, r16                    \n"
        "    or      r16, r15                           \n"
        "    ldsr    r15, 5, 0                          \n" /* enable FXU */
        "                                               \n"
        "    movhi   0x0002, r0, r16                    \n"
        "    ldsr    r16, 6, 10                         \n" /* initialize FXSR */
        "    ldsr    r0, 8, 10                          \n" /* initialize FXST */
        "    ldsr    r0, 10, 10                         \n" /* initialize FXCFG */
        "_L_FXU_Init_End%=:                             \n"
        :
        :
        : "r15", "r16", "memory"
        );
}

/** @} */ /* end of RH850_FXU_API */
#endif                                 /* #if defined(__FXU_PRESENT) && (__FXU_PRESENT == 1U) */

/** @} */ /* end of RH850_Core_intrinsics */
/** @} */ /* end of RH850_CoreAccess_FunctionInterface */

#endif                                 /* __RH850_GCC_G4_H */
