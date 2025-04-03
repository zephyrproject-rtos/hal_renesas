/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_FLASH_HP_CFG_H_
#define R_FLASH_HP_CFG_H_
#ifdef __cplusplus
         extern "C" {
         #endif

#define FLASH_HP_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define FLASH_HP_CFG_CODE_FLASH_PROGRAMMING_ENABLE ((DT_PROP(DT_NODELABEL(flash0), programming_enable)))
#define FLASH_HP_CFG_DATA_FLASH_PROGRAMMING_ENABLE ((DT_PROP(DT_NODELABEL(flash1), programming_enable)))

#ifdef __cplusplus
         }
         #endif
#endif /* R_FLASH_HP_CFG_H_ */
