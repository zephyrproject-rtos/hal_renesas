/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_FLASH_LP_CFG_H_
#define R_FLASH_LP_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define FLASH_LP_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define FLASH_LP_CFG_CODE_FLASH_PROGRAMMING_ENABLE ((DT_PROP(DT_NODELABEL(flash0), programming_enable)))
#define FLASH_LP_CFG_DATA_FLASH_PROGRAMMING_ENABLE ((DT_PROP(DT_NODELABEL(flash1), programming_enable)))
#define FLASH_LP_CFG_DATA_FLASH_BGO_SUPPORT_ENABLE (FLASH_LP_CFG_DATA_FLASH_PROGRAMMING_ENABLE)
#define FLASH_LP_CFG_CODE_FLASH_BANK_PROGRAMMING_ENABLE (0)

#ifdef __cplusplus
}
#endif
#endif /* R_FLASH_LP_CFG_H_ */
