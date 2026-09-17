/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZT
{
#endif
#endif

/*******************************************************************************************************************//**
 * @ingroup RZT_BSP_MCU
 * @defgroup RZT_BSP_MCU_RZT2H RZT2H
 * @includedoc config_bsp_rzt2h_fsp.html
 * @{
 **********************************************************************************************************************/

/** @} (end defgroup BSP_MCU_RZT2H) */
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
#include "bsp_feature.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#if ((1 != _RZ_ORDINAL) && (1 == BSP_CFG_DDR_INIT_ENABLE))
 #error "DDR setting is prohibited except for primary core project. Please disable DDR setting in the BSP properties."
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef elc_event_t bsp_interrupt_event_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
