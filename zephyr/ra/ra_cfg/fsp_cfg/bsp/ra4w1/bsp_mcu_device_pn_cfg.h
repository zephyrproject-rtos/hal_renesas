/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BSP_MCU_DEVICE_PN_CFG_H_
#define BSP_MCU_DEVICE_PN_CFG_H_

#define BSP_MCU_FEATURE_SET ('A')
#define BSP_ROM_SIZE_BYTES DT_REG_SIZE(DT_NODELABEL(flash0))
#define BSP_RAM_SIZE_BYTES (98304)
#define BSP_DATA_FLASH_SIZE_BYTES DT_REG_SIZE(DT_NODELABEL(flash1))
#define BSP_NUMBER_OF_CORES (1)
#define BSP_PACKAGE_QFN
#define BSP_PACKAGE_PINS (56)

#endif /* BSP_MCU_DEVICE_PN_CFG_H_ */
