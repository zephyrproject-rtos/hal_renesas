/*
 * Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BSP_MCU_DEVICE_PN_CFG_H_
#define BSP_MCU_DEVICE_PN_CFG_H_
#define BSP_ROM_SIZE_BYTES DT_REG_SIZE(DT_NODELABEL(flash0))
#define BSP_DATA_FLASH_SIZE_BYTES DT_REG_SIZE(DT_NODELABEL(flash1))
#if defined(CONFIG_SOC_R7FA4E10D2CFM)
#define BSP_PACKAGE_PINS (64)
#elif defined(CONFIG_SOC_R7FA4E10D2CNE)
#define BSP_PACKAGE_PINS (48)
#endif

#endif /* BSP_MCU_DEVICE_PN_CFG_H_ */
