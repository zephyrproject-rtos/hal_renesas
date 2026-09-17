/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_INFO_H
#define BSP_MCU_INFO_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* BSP MCU Specific Includes. */
#include "bsp_elc.h"
#include "bsp_dmac.h"
#include "bsp_mhu_b.h"
#include "bsp_crc_snoop.h"
#include "bsp_feature.h"
#include "bsp_irq_id.h"
#include "bsp_reset.h"
#include "bsp_slave_address.h"
#include "bsp_tsu_b.h"
#include "bsp_wdt.h"
#include "bsp_riic.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZG
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @ingroup RZG_BSP_MCU
 * @defgroup RZG_BSP_MPU_RZG3E RZG3E
 * @includedoc config_bsp_rzg3e_fsp.html
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef IRQSELn_Type bsp_interrupt_event_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** @} (end defgroup BSP_MPU_RZG3E) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

#endif                                 /* BSP_MCU_INFO_H */
