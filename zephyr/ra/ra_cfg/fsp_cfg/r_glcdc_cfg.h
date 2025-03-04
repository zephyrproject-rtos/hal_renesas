/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_GLCDC_CFG_H_
#define R_GLCDC_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define GLCDC_CFG_PARAM_CHECKING_ENABLE      (BSP_CFG_PARAM_CHECKING_ENABLE)
#define GLCDC_CFG_COLOR_CORRECTION_ENABLE    (true)

/* Disable DSI function handling */
#ifdef GLCDC_CFG_USING_DSI
 #undef GLCDC_CFG_USING_DSI
#endif

#ifdef __cplusplus
}
#endif
#endif /* R_GLCDC_CFG_H_ */
