/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BSP_MCU_DEVICE_PN_CFG_H_
#define BSP_MCU_DEVICE_PN_CFG_H_

#define BSP_MCU_FEATURE_SET ('B')
#define BSP_ROM_SIZE_BYTES DT_REG_SIZE(DT_NODELABEL(flash0))
#define BSP_RAM_SIZE_BYTES (40960)
#define BSP_DATA_FLASH_SIZE_BYTES DT_REG_SIZE(DT_NODELABEL(flash1))
#define BSP_NUMBER_OF_CORES (1)

#if (CONFIG_RENESAS_PN_PACKAGE_TYPE == 1)
#define BSP_PACKAGE_LQFP
#define BSP_PACKAGE_PINS (64)
#elif (CONFIG_RENESAS_PN_PACKAGE_TYPE == 2)
#define BSP_PACKAGE_QFN
#define BSP_PACKAGE_PINS (48)
#elif (CONFIG_RENESAS_PN_PACKAGE_TYPE == 3)
#define BSP_PACKAGE_QFN
#define BSP_PACKAGE_PINS (32)
#elif (CONFIG_RENESAS_PN_PACKAGE_TYPE == 4)
#define BSP_PACKAGE_BGA
#define BSP_PACKAGE_PINS (64)
#elif (CONFIG_RENESAS_PN_PACKAGE_TYPE == 5)
#define BSP_PACKAGE_BGA
#define BSP_PACKAGE_PINS (36)
#else
#error "Invalid Package type"
#endif

#endif /* BSP_MCU_DEVICE_PN_CFG_H_ */
