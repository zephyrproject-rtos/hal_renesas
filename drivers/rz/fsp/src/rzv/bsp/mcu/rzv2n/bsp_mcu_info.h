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
 * @ingroup RZV_BSP_MCU
 * @defgroup RZV_BSP_MPU_RZV2N RZV2N
 * @includedoc config_bsp_rzv2n_fsp.html
 * @{
 **********************************************************************************************************************/

/** @} (end defgroup RZV_BSP_MPU_RZV2N) */

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

#ifndef BSP_MCU_INFO_H
#define BSP_MCU_INFO_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* BSP MPU Specific Includes. */
#include "bsp_elc.h"
#include "bsp_dmac.h"
#include "bsp_mhu_b.h"
#include "bsp_crc_snoop.h"
#include "bsp_wdt.h"
#include "bsp_tsu_b.h"
#if defined(BSP_SUPPORT_CORE_CM33)
 #include "bsp_feature.h"
 #include "bsp_irq_id.h"
 #include "bsp_sleep.h"
 #include "bsp_slave_address.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
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

#endif                                 /* BSP_MCU_INFO_H */
