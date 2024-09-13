/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_DEVICE_PN_CFG_H_
#define BSP_MCU_DEVICE_PN_CFG_H_
#define BSP_ROM_SIZE_BYTES DT_REG_SIZE(DT_NODELABEL(flash0))
#define BSP_DATA_FLASH_SIZE_BYTES DT_REG_SIZE(DT_NODELABEL(flash1))
#define BSP_PACKAGE_PINS (176)
#endif /* BSP_MCU_DEVICE_PN_CFG_H_ */
