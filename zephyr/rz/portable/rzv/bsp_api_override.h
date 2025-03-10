/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RZV2L
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RZV2L) */

#ifndef BSP_API_OVERRIDE_H
#define BSP_API_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* BSP Common Includes. */
#include "bsp_common.h"

/* BSP MCU Specific Includes. */
#include "bsp_io.h"
#include "bsp_group_irq.h"
#include "bsp_clocks.h"
#include "bsp_module_stop.h"
#include "bsp_io_register.h"
#include "bsp_irq.h"
#include "bsp_security.h"

/* Factory MCU information. */
#include "fsp_features.h"

/* BSP Common Includes (Other than bsp_common.h) */
#include "bsp_delay.h"
#include "bsp_mcu_api.h"

#endif
