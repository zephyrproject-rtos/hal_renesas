/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BSP_MCU_DEVICE_PN_CFG_H_
#define BSP_MCU_DEVICE_PN_CFG_H_
#define BSP_MCU_FEATURE_SET ('B')
#define BSP_NUMBER_OF_CORES (1)
#define BSP_ROM_SIZE_BYTES (DT_REG_SIZE(DT_NODELABEL(flash0)))
#define BSP_RAM_SIZE_BYTES (DT_REG_SIZE(DT_NODELABEL(sram0)))
#define BSP_DATA_FLASH_SIZE_BYTES (DT_REG_SIZE(DT_NODELABEL(flash1)))

#if defined(CONFIG_SOC_R7FA4T1BB3CFM) || defined(CONFIG_SOC_R7FA4T1B93CFM)
#define BSP_PACKAGE_LQFP
#define BSP_PACKAGE_PINS (64)
#elif defined(CONFIG_SOC_R7FA4T1BB3CFL) || defined(CONFIG_SOC_R7FA4T1B93CFL)
#define BSP_PACKAGE_LQFP
#define BSP_PACKAGE_PINS (48)
#elif defined(CONFIG_SOC_R7FA4T1BB3CFJ) || defined(CONFIG_SOC_R7FA4T1B93CFJ)
#define BSP_PACKAGE_LQFP
#define BSP_PACKAGE_PINS (32)
#elif defined(CONFIG_SOC_R7FA4T1BB3CNE) || defined(CONFIG_SOC_R7FA4T1B93CNE)
#define BSP_PACKAGE_QFN
#define BSP_PACKAGE_PINS (48)
#elif defined(CONFIG_SOC_R7FA4T1BB3CNH) || defined(CONFIG_SOC_R7FA4T1B93CNH)
#define BSP_PACKAGE_QFN
#define BSP_PACKAGE_PINS (32)
#else
#error "Invalid MCU Package pin"
#endif

#endif /* BSP_MCU_DEVICE_PN_CFG_H_ */
