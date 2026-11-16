/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_SPINLOCK_H
#define BSP_SPINLOCK_H

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_COMMON
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/**
 * @brief   Release a spinlock
 * @details Clear the lock by storing 0 to the given address.
 *          On RH850, this uses a normal store to memory, releasing the lock held by another core/task.
 * @param[in]  LpAddr   Pointer to the spinlock variable in memory.
 * @pre     \p LpAddr must be aligned to word size and visible to all participating cores.
 */
extern void R_BSP_SpinLockRelease(uint32_t * LpAddr); /* PRQA S 1753 # DP_MSR_R-8.6_UC1 */

/**
 * @brief   Acquire a spinlock (blocking)
 * @details Attempt to acquire the spinlock using LL/SC (load-linked/store-conditional) primitive:
 *          - Load-linked the current value at \p LpAddr.
 *          - If unlocked (0), try store-conditional of 1.
 *          - If SC succeeds, the lock is acquired and the function returns.
 *          - Otherwise, enter low-power wait (snooze) and retry.
 * @param[in]  LpAddr   Pointer to the spinlock variable in memory.
 * @pre     \p LpAddr must be aligned to word size and shared/uncached or properly coherent across cores.
 */
extern void R_BSP_SpinlockGet(uint32_t * LpAddr);     /* PRQA S 1753 # DP_MSR_R-8.6_UC1 */

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_COMMON)
 **********************************************************************************************************************/

#endif                                                /* BSP_SPINLOCK_H */
