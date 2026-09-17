/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_WDT_CFG_H_
#define R_WDT_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define WDT_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define WDT_CFG_MULTIPLEX_INTERRUPT_SUPPORTED (0) // DEPRECATED
#if WDT_CFG_MULTIPLEX_INTERRUPT_SUPPORTED
 #define WDT_CFG_MULTIPLEX_INTERRUPT_ENABLE         BSP_INTERRUPT_ENABLE  // DEPRECATED
 #define WDT_CFG_MULTIPLEX_INTERRUPT_DISABLE        BSP_INTERRUPT_DISABLE // DEPRECATED
#else
 #define WDT_CFG_MULTIPLEX_INTERRUPT_ENABLE  // DEPRECATED
 #define WDT_CFG_MULTIPLEX_INTERRUPT_DISABLE // DEPRECATED
#endif

#ifdef __cplusplus
}
#endif
#endif /* R_WDT_CFG_H_ */
