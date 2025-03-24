/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*
 * @file     R9A07G044L.h
 * @brief    CMSIS HeaderFile
 */

/** @addtogroup Renesas
 * @{
 */

/** @addtogroup R9A07G044L
 * @{
 */

#ifndef R9A07G044L_H
 #define R9A07G044L_H

 #ifdef __cplusplus
extern "C" {
 #endif

/** @addtogroup Configuration_of_CMSIS
 * @{
 */

/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ==========================  Configuration of the ARM Cortex-M33 Processor and Core Peripherals  =========================== */
 #define __CM33_REV                0x0004U /*!< CM33 Core Revision                                                        */
 #define __NVIC_PRIO_BITS          7       /*!< Number of Bits used for Priority Levels                                   */
 #define __Vendor_SysTickConfig    0       /*!< Set to 1 if different SysTick Config is used                          */
 #define __VTOR_PRESENT            1       /*!< Set to 1 if CPU supports Vector Table Offset Register                     */
 #define __MPU_PRESENT             1       /*!< MPU present                                                               */
 #define __FPU_PRESENT             0       /*!< FPU present                                                               */
 #define __FPU_DP                  0       /*!< Double Precision FPU                                                      */
 #define __DSP_PRESENT             0       /*!< DSP extension present                                                     */
 #define __SAUREGION_PRESENT       0       /*!< SAU region present                                                        */

/** @} */ /* End of group Configuration_of_CMSIS */

 #include "core_cm33.h"                    /*!< ARM Cortex-M33 processor and core peripherals                             */
 #include "system.h"                       /*!< R9A07G044L System                                                          */

 #ifndef __IM                              /*!< Fallback for older CMSIS versions                                         */
  #define __IM     __I
 #endif
 #ifndef __OM                              /*!< Fallback for older CMSIS versions                                         */
  #define __OM     __O
 #endif
 #ifndef __IOM                             /*!< Fallback for older CMSIS versions                                         */
  #define __IOM    __IO
 #endif

/* ========================================  Start of section using anonymous unions  ======================================== */
 #if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
 #elif defined(__ICCARM__)
  #pragma language=extended
 #elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
  #pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
  #pragma clang diagnostic ignored "-Wnested-anon-types"
 #elif defined(__GNUC__)

/* anonymous unions are enabled by default */
 #elif defined(__TMS470__)

/* anonymous unions are enabled by default */
 #elif defined(__TASKING__)
  #pragma warning 586
 #elif defined(__CSMC__)

/* anonymous unions are enabled by default */
 #else
  #warning Not supported compiler type
 #endif

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */
 #include "R9A07G044L/iodefine.h"

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================  End of section using anonymous unions  =============================== */
 #if defined(__CC_ARM)
  #pragma pop
 #elif defined(__ICCARM__)

/* leave anonymous unions enabled */
 #elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
 #elif defined(__GNUC__)

/* anonymous unions are enabled by default */
 #elif defined(__TMS470__)

/* anonymous unions are enabled by default */
 #elif defined(__TASKING__)
  #pragma warning restore
 #elif defined(__CSMC__)

/* anonymous unions are enabled by default */
 #endif

/* =========================================================================================================================== */
/* ================                                 Pos/Mask Cluster Section                        ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_clusters
 * @{
 */
 #include "R9A07G044L/iobitmask.h"

/** @} */ /* End of group PosMask_clusters */

 #ifdef __cplusplus
}
 #endif

#endif                                 /* R9A07G044L_H */

/** @} */ /* End of group R9A07G044L */

/** @} */ /* End of group Renesas */
