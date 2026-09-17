/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZV
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_BSP_MPU_RZV2L
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup RZV_BSP_MPU_RZV2L) */

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

#ifndef BSP_API_OVERRIDE_H
#define BSP_API_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* BSP Common Includes. */
#if defined(BSP_SUPPORT_CORE_CM33)
 #include "cm/bsp_common.h"
#elif defined(BSP_SUPPORT_CORE_CR8)
 #include "cr/bsp_common.h"
#endif

/* BSP MPU Specific Includes. */
#include "bsp_io.h"
#include "bsp_group_irq.h"
#include "bsp_clocks.h"
#include "bsp_module_stop.h"
#include "bsp_io_register.h"
#if defined(BSP_SUPPORT_CORE_CM33)
 #include "cm/bsp_irq.h"
 #include "bsp_security.h"
#elif defined(BSP_SUPPORT_CORE_CR8)
 #include "bsp_irq_gic.h"
 #include "cr/bsp_irq.h"
 #include "bsp_cache.h"
 #include "bsp_security.h"
//  #include "bsp_mpu.h" /* This file no porting */
#endif

/* Factory MPU information. */
#include "fsp_features.h"

/* BSP Common Includes (Other than bsp_common.h) */
#include "bsp_delay.h"
#include "bsp_mcu_api.h"

#endif
