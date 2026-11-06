/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef SYSTEM_RENESAS_RH850_H
 #define SYSTEM_RENESAS_RH850_H

 #ifdef __cplusplus
extern "C" {
 #endif

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include <stdint.h>

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/* Address Access Mutual Exclusion Mechanism */
 #if (BSP_CFG_MEV_SIZE_BYTES > 0)
extern uint32_t g_mev_cpusync_address;
  #if (BSP_CFG_RTOS != 0)
extern uint32_t g_mev_rtos_cpusync_address;
  #endif
extern uint32_t g_mev_address[BSP_CFG_MEV_SIZE_BYTES >> 2];
 #else
extern uint32_t g_mev_cpusync_address;
  #if (BSP_CFG_RTOS != 0)

extern uint32_t g_mev_rtos_cpusync_address; /* PRQA S 1752 # DP_MSR_R-8.6_UC1 */

  #endif
 #endif

/* Extern declarations and BSP_STACKS_LIST for enabled CPUs */
 #if (BSP_PE0_USED)

extern uint32_t g_main_stack_pe0[];    /* PRQA S 3684 # Advisory R-8.11 */

/* PRQA S 1534 ++ # Advisory R-2.5 */
  #define PE0_STACK_ENTRY    (UBaseType_t) (uintptr_t) &g_main_stack_pe0[BSP_CFG_STACK_MAIN_BYTES >> 2],

/* PRQA S 1534 -- */
 #else
  #define PE0_STACK_ENTRY
 #endif
 #if (BSP_PE1_USED)
extern uint32_t g_main_stack_pe1[];
  #define PE1_STACK_ENTRY    (UBaseType_t) (uintptr_t) &g_main_stack_pe1[BSP_CFG_STACK_MAIN_BYTES >> 2],
 #else

/* PRQA S 1534 ++ # Advisory R-2.5 */
  #define PE1_STACK_ENTRY

/* PRQA S 1534 -- */
 #endif
 #if (BSP_PE2_USED)
extern uint32_t g_main_stack_pe2[];
  #define PE2_STACK_ENTRY    (UBaseType_t) (uintptr_t) &g_main_stack_pe2[BSP_CFG_STACK_MAIN_BYTES >> 2],
 #else

/* PRQA S 1534 ++ # Advisory R-2.5 */
  #define PE2_STACK_ENTRY

/* PRQA S 1534 -- */
 #endif
 #if (BSP_PE3_USED)
extern uint32_t g_main_stack_pe3[];
  #define PE3_STACK_ENTRY    (UBaseType_t) (uintptr_t) &g_main_stack_pe3[BSP_CFG_STACK_MAIN_BYTES >> 2],
 #else

/* PRQA S 1534 ++ # Advisory R-2.5 */
  #define PE3_STACK_ENTRY

/* PRQA S 1534 -- */
 #endif
 #if (BSP_PE4_USED)
extern uint32_t g_main_stack_pe4[];
  #define PE4_STACK_ENTRY    (UBaseType_t) (uintptr_t) &g_main_stack_pe4[BSP_CFG_STACK_MAIN_BYTES >> 2],
 #else

/* PRQA S 1534 ++ # Advisory R-2.5 */
  #define PE4_STACK_ENTRY

/* PRQA S 1534 -- */
 #endif
 #if (BSP_PE5_USED)
extern uint32_t g_main_stack_pe5[];
  #define PE5_STACK_ENTRY    (UBaseType_t) (uintptr_t) &g_main_stack_pe5[BSP_CFG_STACK_MAIN_BYTES >> 2],
 #else

/* PRQA S 1534 ++ # Advisory R-2.5 */
  #define PE5_STACK_ENTRY

/* PRQA S 1534 -- */
 #endif
 #if (BSP_PE6_USED)
extern uint32_t g_main_stack_pe6[];
  #define PE6_STACK_ENTRY    (UBaseType_t) (uintptr_t) &g_main_stack_pe6[BSP_CFG_STACK_MAIN_BYTES >> 2],
 #else

/* PRQA S 1534 ++ # Advisory R-2.5 */
  #define PE6_STACK_ENTRY

/* PRQA S 1534 -- */
 #endif

/* PRQA S 1534 ++ # Advisory R-2.5 */
 #define BSP_STACKS_LIST    { \
        PE0_STACK_ENTRY       \
        PE1_STACK_ENTRY       \
        PE2_STACK_ENTRY       \
        PE3_STACK_ENTRY       \
        PE4_STACK_ENTRY       \
        PE5_STACK_ENTRY       \
            PE6_STACK_ENTRY   \
}

/* PRQA S 1534 -- */

 #ifdef __cplusplus
}
 #endif

#endif
