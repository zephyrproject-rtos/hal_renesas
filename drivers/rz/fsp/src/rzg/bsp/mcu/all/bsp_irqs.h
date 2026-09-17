/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_irqs.h
 * Version      : 1.00
 * Description  : bsp_irq (secure) header
 *********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU) */

#ifndef BSP_IRQS_H
#define BSP_IRQS_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZG
{
 #endif
#endif

/* Public functions defined in bsp.h */
void bsp_irq_cfg_s(void);              // Used internally by BSP

/** @} (end addtogroup BSP_MCU_PRV) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_IRQS_H */
