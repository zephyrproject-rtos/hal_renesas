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

/** @addtogroup RA
 * @{
 */

#ifndef RA_H
 #define RA_H

 #ifdef __cplusplus
extern "C" {
 #endif

/* Workaround for LLVM. __ARM_ARCH_8_1M_MAIN__ is defined for CM85 parts. But CMSIS_5 does not support this */
 #if defined(__llvm__) && !defined(__CLANG_TIDY__) && defined(__ARM_ARCH_8_1M_MAIN__)
  #undef __ARM_ARCH_8_1M_MAIN__
  #define __ARM_ARCH_8M_MAIN__    1
 #endif
 #include "cmsis_compiler.h"

/* Workaround for compilers that are not defining __ARM_ARCH_8_1M_MAIN__ for CM85 parts. Search CM85_WORKAROUND for related code changes */
 #if BSP_CFG_MCU_PART_SERIES == 8
  #undef __ARM_ARCH_8M_MAIN__
  #define __ARM_ARCH_8_1M_MAIN__    1
 #endif

/** @addtogroup Configuration_of_CMSIS
 * @{
 */

/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */
/* IRQn_Type is provided in bsp_exceptions.h. Vectors generated by the FSP Configuration tool are in vector_data.h */

/** @} */ /* End of group Configuration_of_CMSIS */

/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

 #if BSP_MCU_GROUP_RA2A1
  #include "R7FA2A1AB.h"
 #elif BSP_MCU_GROUP_RA2E1
  #include "R7FA2E1A9.h"
 #elif BSP_MCU_GROUP_RA2E2
  #include "R7FA2E2A7.h"
 #elif BSP_MCU_GROUP_RA2E3
  #include "R7FA2E307.h"
 #elif BSP_MCU_GROUP_RA2L1
  #include "R7FA2L1AB.h"
 #elif BSP_MCU_GROUP_RA4E1
  #include "R7FA4E10D.h"
 #elif BSP_MCU_GROUP_RA4E2
  #include "R7FA4E2B9.h"
 #elif BSP_MCU_GROUP_RA4M1
  #include "R7FA4M1AB.h"
 #elif BSP_MCU_GROUP_RA4M2
  #include "R7FA4M2AD.h"
 #elif BSP_MCU_GROUP_RA4M3
  #include "R7FA4M3AF.h"
 #elif BSP_MCU_GROUP_RA4T1
  #include "R7FA4T1BB.h"
 #elif BSP_MCU_GROUP_RA4W1
  #include "R7FA4W1AD.h"
 #elif BSP_MCU_GROUP_RA6E1
  #include "R7FA6E10F.h"
 #elif BSP_MCU_GROUP_RA6E2
  #include "R7FA6E2BB.h"
 #elif BSP_MCU_GROUP_RA6M1
  #include "R7FA6M1AD.h"
 #elif BSP_MCU_GROUP_RA6M2
  #include "R7FA6M2AF.h"
 #elif BSP_MCU_GROUP_RA6M3
  #include "R7FA6M3AH.h"
 #elif BSP_MCU_GROUP_RA6M4
  #include "R7FA6M4AF.h"
 #elif BSP_MCU_GROUP_RA6M5
  #include "R7FA6M5BH.h"
 #elif BSP_MCU_GROUP_RA6T1
  #include "R7FA6T1AD.h"
 #elif BSP_MCU_GROUP_RA6T2
  #include "R7FA6T2BD.h"
 #elif BSP_MCU_GROUP_RA6T3
  #include "R7FA6T3BB.h"
 #elif BSP_MCU_GROUP_RA8M1
  #include "R7FA8M1AH.h"
 #elif BSP_MCU_GROUP_RA8D1
  #include "R7FA8D1BH.h"
 #elif BSP_MCU_GROUP_RA8T1
  #include "R7FA8T1AH.h"
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

#endif                                 /* RA_H */

/** @} */ /* End of group RA */

/** @} */ /* End of group Renesas */