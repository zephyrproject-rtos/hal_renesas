/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* Ensure Renesas MCU variation definitions are included to ensure MCU
 * specific register variations are handled correctly. */
#ifndef BSP_FEATURE_H
 #error "INTERNAL ERROR: bsp_feature.h must be included before renesas.h."
#endif

/** @addtogroup Renesas
 * @{
 */

/** @addtogroup RZG
 * @{
 */

#ifndef RZG_H
 #define RZG_H

 #ifdef __cplusplus
extern "C" {
 #endif

 #include "cmsis_compiler.h"

/** @addtogroup Configuration_of_CMSIS
 * @{
 */

/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */
/* IRQn_Type is provided in bsp_arm_exceptions.h. Vectors generated by the FSP Configuration tool are in vector_data.h */

/** @} */ /* End of group Configuration_of_CMSIS */

/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

 #if BSP_MCU_GROUP_RZG2L
  #include "R9A07G044L.h"
 #elif BSP_MCU_GROUP_RZG2UL
  #include "R9A07G043U.h"
 #elif BSP_MCU_GROUP_RZG3S
  #include "R9A08G045S.h"
 #else
  #if __has_include("renesas_internal.h")
   #include "renesas_internal.h"
  #else
   #warning "Unsupported MCU"
  #endif
 #endif

 #if   __ARM_ARCH_7EM__
  #define RENESAS_CORTEX_M4
 #elif __ARM_ARCH_6M__
  #define RENESAS_CORTEX_M0PLUS
 #elif __ARM_ARCH_8M_BASE__
  #define RENESAS_CORTEX_M23
 #elif __ARM_ARCH_8M_MAIN__
  #define RENESAS_CORTEX_M33
 #elif __ARM_ARCH_8_1M_MAIN__
  #define RENESAS_CORTEX_M85
 #else
  #warning Unsupported Architecture
 #endif

 #ifdef __cplusplus
}
 #endif

#endif                                 /* RZG_H */

/** @} */ /* End of group RZG */

/** @} */ /* End of group Renesas */