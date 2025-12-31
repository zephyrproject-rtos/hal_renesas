/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_RESET_H
#define BSP_RESET_H

#include <bsp_api.h>

typedef enum e_bsp_reset_type {
	BSP_RESET_TYPE_POR	= (1 << 0),	/** Power-On Reset  */
	BSP_RESET_TYPE_PVD0	= (1 << 1),	/** Voltage Monitor 0 Reset */
	BSP_RESET_TYPE_PVD1	= (1 << 2),	/** Voltage Monitor 1 Reset */
	BSP_RESET_TYPE_PVD2	= (1 << 3),	/** Voltage Monitor 2  */
	BSP_RESET_TYPE_PVD4	= (1 << 4),	/** Voltage Monitor 4 Reset */
	BSP_RESET_TYPE_PVD5	= (1 << 5),	/** Voltage Monitor 5  */
	BSP_RESET_TYPE_DPSRST	= (1 << 6),	/** Deep Software Standby Reset */
	BSP_RESET_TYPE_IWDT	= (1 << 7),	/** Independent Watchdog Timer Reset  */
	BSP_RESET_TYPE_WDT0	= (1 << 8),	/** Watchdog Timer 0 Reset */
	BSP_RESET_TYPE_SWR	= (1 << 9),	/** Software Reset */
	BSP_RESET_TYPE_CLU0RF	= (1 << 10),	/** CPU0 Lockup Reset */
	BSP_RESET_TYPE_LM0	= (1 << 11),	/** Local memory 0 error Reset */
	BSP_RESET_TYPE_BUS	= (1 << 11),	/** Bus Error Reset Detect Flag */
	BSP_RESET_TYPE_CMR	= (1 << 12),	/** Common Memory Error Reset */
	BSP_RESET_TYPE_WDT1	= (1 << 13),	/** Watchdog Timer 1 Reset Detect  */
	BSP_RESET_TYPE_CLU1RF	= (1 << 14),	/** CPU0 Lockup Reset */
	BSP_RESET_TYPE_LM1	= (1 << 15),	/** Local memory 1 error Reset */
	BSP_RESET_TYPE_RPE	= (1 << 16),	/** SRAM Parity Error Reset */
	BSP_RESET_TYPE_REE	= (1 << 17),	/** SRAM ECC Error Reset Detect */
	BSP_RESET_TYPE_BUSM	= (1 << 18),	/** Bus Master MPU Error Reset */
	BSP_RESET_TYPE_TZE	= (1 << 19),	/** TrustZone Error Reset */
	BSP_RESET_TYPE_CPE	= (1 << 20),	/** Cache Parity Error Reset */
	BSP_RESET_TYPE_SPE	= (1 << 21),	/** CPU Stack Pointer Error Reset */
#if BSP_CFG_VBATT_MANUAL_CONFIGURATION
	BSP_RESET_TYPE_VBATPOR	= (1 << 22),	/** Battery Backup Domain Reset */
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */
} bsp_reset_type_t;

bsp_reset_type_t R_BSP_ResetStatusGet(void);

#endif /* BSP_RESET_H */
