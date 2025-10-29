/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/device.h>
#include <bsp_reset.h>

#if defined(BSP_CFG_VBATT_MANUAL_CONFIGURATION)
extern uint8_t vbtbpsr_state_at_boot;
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */

/* RSTSR0 Reset FLag*/
#define BSP_PRV_RSTSR0_PORF_Msk                (1 << 0)
#define BSP_PRV_RSTSR0_LVD0RF_Msk              (1 << 1)
#define BSP_PRV_RSTSR0_LVD1RF_Msk              (1 << 2)
#define BSP_PRV_RSTSR0_LVD2RF_Msk              (1 << 3)
#define BSP_PRV_RSTSR0_LVD4RF_Msk              (1 << 5)
#define BSP_PRV_RSTSR0_LVD5RF_Msk              (1 << 6)
#define BSP_PRV_RSTSR0_DPSRSTF_Msk             (1 << 7)

/* RSTSR1 Reset Flag */
#define BSP_PRV_RSTSR1_IWDTRF_Msk              (1 << 0)
#define BSP_PRV_RSTSR1_WDTRF_Msk               (1 << 1)
#define BSP_PRV_RSTSR1_SWRF_Msk                (1 << 2)
#define BSP_PRV_RSTSR1_CLU0RF_Msk              (1 << 4)
#define BSP_PRV_RSTSR1_LM0RF_Msk               (1 << 5)
#define BSP_PRV_RSTSR1_RPERF_Msk               (1 << 8)
#define BSP_PRV_RSTSR1_REERF_Msk               (1 << 9)
#define BSP_PRV_RSTSR1_BUSSRF_Msk              (1 << 10)
#define BSP_PRV_RSTSR1_BUSMRF_Msk              (1 << 11)
#define BSP_PRV_RSTSR1_SPERF_Msk               (1 << 12)
#define BSP_PRV_RSTSR1_TZERF_Msk               (1 << 13)
#define BSP_PRV_RSTSR1_CMRF_Msk                (1 << 14)
#define BSP_PRV_RSTSR1_CPERF_Msk               (1 << 15)
#define BSP_PRV_RSTSR1_WDT1RF_Msk              (1 << 17)
#define BSP_PRV_RSTSR1_CLU1RF_Msk              (1 << 20)
#define BSP_PRV_RSTSR1_LM1RF_Msk               (1 << 21)

#if BSP_CFG_VBATT_MANUAL_CONFIGURATION
/* VBTBPSR Status Flag */
#define BSP_PRV_VBTBPSR_VBPORF_Msk		(1 << 0)
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */

/*******************************************************************************************************************//**
 * Get MCU reset type
 *
 * @return  MCU reset type
 **********************************************************************************************************************/
bsp_reset_type_t R_BSP_ResetStatusGet(void)
{
	bsp_reset_type_t event = 0;

	if (R_SYSTEM->RSTSR0 & BSP_PRV_RSTSR0_PORF_Msk) {
		event |= BSP_RESET_TYPE_POR;
	}

	if (R_SYSTEM->RSTSR0 & BSP_PRV_RSTSR0_LVD0RF_Msk) {
		event |= BSP_RESET_TYPE_PVD0;
	}

	if (R_SYSTEM->RSTSR0 & BSP_PRV_RSTSR0_LVD1RF_Msk) {
		event |= BSP_RESET_TYPE_PVD1;
	}

	if (R_SYSTEM->RSTSR0 & BSP_PRV_RSTSR0_LVD2RF_Msk) {
		event |= BSP_RESET_TYPE_PVD2;
	}

	if (R_SYSTEM->RSTSR0 & BSP_PRV_RSTSR0_LVD4RF_Msk) {
		event |= BSP_RESET_TYPE_PVD4;
	}

	if (R_SYSTEM->RSTSR0 & BSP_PRV_RSTSR0_LVD5RF_Msk) {
		event |= BSP_RESET_TYPE_PVD5;
	}

	if (R_SYSTEM->RSTSR0 & BSP_PRV_RSTSR0_DPSRSTF_Msk) {
		event |= BSP_RESET_TYPE_DPSRST;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_IWDTRF_Msk) {
		event |= BSP_RESET_TYPE_IWDT;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_WDTRF_Msk) {
		event |= BSP_RESET_TYPE_WDT0;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_SWRF_Msk) {
		event |= BSP_RESET_TYPE_SWR;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_CLU0RF_Msk) {
		event |= BSP_RESET_TYPE_CLU0RF;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_LM0RF_Msk) {
		event |= BSP_RESET_TYPE_LM0;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_RPERF_Msk) {
		event |= BSP_RESET_TYPE_RPE;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_REERF_Msk) {
		event |= BSP_RESET_TYPE_REE;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_BUSSRF_Msk) {
		event |= BSP_RESET_TYPE_BUS;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_BUSMRF_Msk) {
		event |= BSP_RESET_TYPE_BUSM;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_SPERF_Msk) {
		event |= BSP_RESET_TYPE_SPE;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_TZERF_Msk) {
		event |= BSP_RESET_TYPE_TZE;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_CMRF_Msk) {
		event |= BSP_RESET_TYPE_CMR;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_CPERF_Msk) {
		event |= BSP_RESET_TYPE_CPE;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_WDT1RF_Msk) {
		event |= BSP_RESET_TYPE_WDT1;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_CLU1RF_Msk) {
		event |= BSP_RESET_TYPE_CLU1RF;
	}

	if (R_SYSTEM->RSTSR1 & BSP_PRV_RSTSR1_LM1RF_Msk) {
		event |= BSP_RESET_TYPE_LM1;
	}

#if BSP_CFG_VBATT_MANUAL_CONFIGURATION
	if (vbtbpsr_state_at_boot & BSP_PRV_VBTBPSR_VBPORF_Msk) {
		event |= BSP_RESET_TYPE_VBATPOR;
	}
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */

	return event;
}
