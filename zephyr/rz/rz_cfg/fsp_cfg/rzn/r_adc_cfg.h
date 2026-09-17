/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ADC_CFG_H_
#define R_ADC_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define ADC_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define ADC_CFG_MULTIPLEX_INTERRUPT_SUPPORTED (0) // DEPRECATED
#if ADC_CFG_MULTIPLEX_INTERRUPT_SUPPORTED
 #define ADC_CFG_MULTIPLEX_INTERRUPT_ENABLE         BSP_INTERRUPT_ENABLE  // DEPRECATED
 #define ADC_CFG_MULTIPLEX_INTERRUPT_DISABLE        BSP_INTERRUPT_DISABLE // DEPRECATED
#else
#define ADC_CFG_MULTIPLEX_INTERRUPT_ENABLE  // DEPRECATED
#define ADC_CFG_MULTIPLEX_INTERRUPT_DISABLE // DEPRECATED
#endif

#ifdef __cplusplus
}
#endif
#endif /* R_ADC_CFG_H_ */
