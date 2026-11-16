/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_MCU_RH850 BSP MCU
 * @brief
 * RH850 MCU Feature Overview
 *
 * This BSP provides core MCU functionalities, including:
 *  - Barrier synchronization and guard protection.
 *  - Interrupt management (standard, INTSEL, ORED IRQ).
 *  - I/O port configuration and control.
 *  - Clock configuration and distribution.
 *  - Module stop, standby, reset, and cyclic-run operations.
 *  - CPU system features (MPU and hardware spinlock).
 *  - Factory MCU information and delay utilities.
 *
 * These components form the fundamental hardware-level support for applications running on RH850 devices.
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

#ifndef BSP_API_OVERRIDE_H_
#define BSP_API_OVERRIDE_H_

/* BSP Common Includes. */
#include "bsp_common.h"

/* BSP MCU Specific Includes. */
#include "bsp_compiler_support.h"
#include "bsp_barr.h"
#include "bsp_guard.h"
#include "bsp_irq.h"
#include "bsp_io.h"
#include "bsp_clocks.h"
#include "bsp_module_stop.h"
#include "bsp_module_standby.h"
#if (BSP_FEATURE_DEVICE_HAS_INTSEL_IRQ)
 #include "bsp_intsel_irq.h"
#endif
#if (BSP_FEATURE_DEVICE_HAS_ORED_IRQ)
 #include "bsp_ored_irq.h"
#endif
#include "bsp_mcu_reset.h"
#include "bsp_mpu.h"
#include "bsp_icache.h"
#include "bsp_spinlock.h"
#if (BSP_CYCLICRUN_MODE_ENABLE)
 #include "bsp_mcu_standby_cyclicrun.h"
#endif
#include "bsp_opbt.h"

#if (BSP_FEATURE_QOS_IS_AVAILABLE)
 #include "bsp_qos.h"
#endif

#include "bsp_fault_trace.h"

/* Factory MCU information. */
#include "fsp_features.h"

/* BSP Common Includes (Other than bsp_common.h) */
#include "bsp_delay.h"
#endif                                 /* BSP_API_OVERRIDE_H_ */

/** @} (end addtogroup BSP_MCU) */
