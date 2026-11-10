/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/** @} (end addtogroup BSP_MCU) */

#ifndef BSP_EXCEPTIONS_H
 #define BSP_EXCEPTIONS_H

 #ifdef __cplusplus
extern "C" {
 #endif

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #if defined(__CCRH__)

/** Pragma to support for interrupt function */
  #define BSP_INTERRUPT_ATTRIBUTE                                              ///< Interrupt attribute placeholder for CCRH
  #define BSP_FEINT_INTERRUPT_ATTRIBUTE                                        ///< FEINT interrupt attribute placeholder for CCRH
  #define BSP_FENMI_INTERRUPT_ATTRIBUTE                                        ///< FENMI interrupt attribute placeholder for CCRH
  #define BSP_DIRECT_INTERRUPT_ATTRIBUTE    /* PRQA S 1534 # Advisory R-2.5 */ ///< Direct Vector Interrupt attribute placeholder for CCRH

 #elif defined(__ghs__)

/** Pragma to support for interrupt function */
  #if (BSP_INTERRUPT_TABLE_REFERENCE_METHOD == 1)
   #define BSP_INTERRUPT_ATTRIBUTE           __interrupt                  ///< Interrupt attribute placeholder for GHS
   #define BSP_DIRECT_INTERRUPT_ATTRIBUTE                                 ///< Direct Vector Interrupt attribute placeholder for GHS
  #else
   #define BSP_INTERRUPT_ATTRIBUTE                                        ///< Interrupt attribute placeholder for GHS
   #define BSP_DIRECT_INTERRUPT_ATTRIBUTE    __interrupt                  ///< Direct Vector Interrupt attribute placeholder for GHS
  #endif

  #define BSP_FEINT_INTERRUPT_ATTRIBUTE      _Pragma("ghs interrupt(FE)") ///< FEINT interrupt attribute placeholder for GHS
  #define BSP_FENMI_INTERRUPT_ATTRIBUTE      _Pragma("ghs interrupt(FE)") ///< FENMI interrupt attribute placeholder for GHS

 #elif defined(__GNUC__)

/** Pragma to support for interrupt function */
  #define BSP_INTERRUPT_ATTRIBUTE                                         ///< General interrupt attribute for GCC
  #define BSP_FEINT_INTERRUPT_ATTRIBUTE                                   ///< FEINT interrupt attribute for GCC
  #define BSP_FENMI_INTERRUPT_ATTRIBUTE                                   ///< FENMI interrupt attribute for GCC
  #define BSP_DIRECT_INTERRUPT_ATTRIBUTE                                  ///< Direct Vector Interrupt attribute placeholder for GCC

 #elif (__ICCRH850__)

/** Pragma to support for interrupt function */
  #define BSP_INTERRUPT_ATTRIBUTE                                ///< Interrupt attribute placeholder for IAR
  #define BSP_DIRECT_INTERRUPT_ATTRIBUTE                         ///< Direct Vector Interrupt attribute placeholder for IAR
  #define BSP_FEINT_INTERRUPT_ATTRIBUTE                          ///< FEINT interrupt attribute placeholder for IAR
  #define BSP_FENMI_INTERRUPT_ATTRIBUTE                          ///< FENMI interrupt attribute placeholder for IAR

 #endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** This list includes only Arm standard exceptions. Renesas interrupts are defined in vector_data.h. */
typedef enum IRQn                                                           /* PRQA S 1536 # Advisory R-2.4 */
{
    SHARED_PERIPHERAL_INTERRUPTS_MAX_ENTRIES = BSP_VECTOR_TABLE_MAX_ENTRIES ///< Max IRQ number
} IRQn_Type;

/** @} (end addtogroup BSP_MCU) */

 #ifdef __cplusplus
}
 #endif

#endif
