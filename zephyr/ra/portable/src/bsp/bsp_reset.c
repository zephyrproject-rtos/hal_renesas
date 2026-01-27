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

/*******************************************************************************************************************//**
 * Get MCU reset type
 *
 * @return  MCU reset type
 **********************************************************************************************************************/
bsp_reset_type_t R_BSP_ResetStatusGet(void)
{
	bsp_reset_type_t event = 0;

#ifdef R_SYSTEM_RSTSR0_PORF_Msk
	if (R_SYSTEM->RSTSR0 & R_SYSTEM_RSTSR0_PORF_Msk) {
		event |= BSP_RESET_TYPE_POR;
	}
#endif /* R_SYSTEM_RSTSR0_PORF_Msk */

#ifdef R_SYSTEM_RSTSR0_LVD0RF_Msk
	if (R_SYSTEM->RSTSR0 & R_SYSTEM_RSTSR0_LVD0RF_Msk) {
		event |= BSP_RESET_TYPE_PVD0;
	}
#endif /* R_SYSTEM_RSTSR0_LVD0RF_Msk */

#ifdef R_SYSTEM_RSTSR0_LVD1RF_Msk
	if (R_SYSTEM->RSTSR0 & R_SYSTEM_RSTSR0_LVD1RF_Msk) {
		event |= BSP_RESET_TYPE_PVD1;
	}
#endif /* R_SYSTEM_RSTSR0_LVD1RF_Msk */

#ifdef R_SYSTEM_RSTSR0_LVD2RF_Msk
	if (R_SYSTEM->RSTSR0 & R_SYSTEM_RSTSR0_LVD2RF_Msk) {
		event |= BSP_RESET_TYPE_PVD2;
	}
#endif /* R_SYSTEM_RSTSR0_LVD2RF_Msk */

#ifdef R_SYSTEM_RSTSR0_LVD4RF_Msk
	if (R_SYSTEM->RSTSR0 & R_SYSTEM_RSTSR0_LVD4RF_Msk) {
		event |= BSP_RESET_TYPE_PVD4;
	}
#endif /* R_SYSTEM_RSTSR0_LVD4RF_Msk */

#ifdef R_SYSTEM_RSTSR0_LVD5RF_Msk
	if (R_SYSTEM->RSTSR0 & R_SYSTEM_RSTSR0_LVD5RF_Msk) {
		event |= BSP_RESET_TYPE_PVD5;
	}
#endif /* R_SYSTEM_RSTSR0_LVD5RF_Msk */

#ifdef R_SYSTEM_RSTSR0_DPSRSTF_Msk
	if (R_SYSTEM->RSTSR0 & R_SYSTEM_RSTSR0_DPSRSTF_Msk) {
		event |= BSP_RESET_TYPE_DPSRST;
	}
#endif /* R_SYSTEM_RSTSR0_DPSRSTF_Msk */

#ifdef R_SYSTEM_RSTSR1_IWDTRF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_IWDTRF_Msk) {
		event |= BSP_RESET_TYPE_IWDT;
	}
#endif /* R_SYSTEM_RSTSR1_IWDTRF_Msk */

#ifdef R_SYSTEM_RSTSR1_WDTRF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_WDTRF_Msk) {
		event |= BSP_RESET_TYPE_WDT0;
	}
#endif /* R_SYSTEM_RSTSR1_WDTRF_Msk */

#ifdef R_SYSTEM_RSTSR1_SWRF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_SWRF_Msk) {
		event |= BSP_RESET_TYPE_SWR;
	}
#endif /* R_SYSTEM_RSTSR1_SWRF_Msk */

#ifdef R_SYSTEM_RSTSR1_CLU0RF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_CLU0RF_Msk) {
		event |= BSP_RESET_TYPE_CLU0RF;
	}
#endif /* R_SYSTEM_RSTSR1_CLU0RF_Msk */

#ifdef R_SYSTEM_RSTSR1_LM0RF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_LM0RF_Msk) {
		event |= BSP_RESET_TYPE_LM0;
	}
#endif /* R_SYSTEM_RSTSR1_LM0RF_Msk */

#ifdef R_SYSTEM_RSTSR1_RPERF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_RPERF_Msk) {
		event |= BSP_RESET_TYPE_RPE;
	}
#endif /* R_SYSTEM_RSTSR1_RPERF_Msk */

#ifdef R_SYSTEM_RSTSR1_REERF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_REERF_Msk) {
		event |= BSP_RESET_TYPE_REE;
	}
#endif /* R_SYSTEM_RSTSR1_REERF_Msk */

#ifdef R_SYSTEM_RSTSR1_BUSSRF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_BUSSRF_Msk) {
		event |= BSP_RESET_TYPE_BUS;
	}
#endif /* R_SYSTEM_RSTSR1_BUSSRF_Msk */

#ifdef R_SYSTEM_RSTSR1_BUSMRF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_BUSMRF_Msk) {
		event |= BSP_RESET_TYPE_BUSM;
	}
#endif /* R_SYSTEM_RSTSR1_BUSMRF_Msk */

#ifdef R_SYSTEM_RSTSR1_SPERF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_SPERF_Msk) {
		event |= BSP_RESET_TYPE_SPE;
	}
#endif /* R_SYSTEM_RSTSR1_SPERF_Msk */

#ifdef R_SYSTEM_RSTSR1_TZERF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_TZERF_Msk) {
		event |= BSP_RESET_TYPE_TZE;
	}
#endif /* R_SYSTEM_RSTSR1_TZERF_Msk */

#ifdef R_SYSTEM_RSTSR1_CMRF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_CMRF_Msk) {
		event |= BSP_RESET_TYPE_CMR;
	}
#endif /* R_SYSTEM_RSTSR1_CMRF_Msk */

#ifdef R_SYSTEM_RSTSR1_CPERF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_CPERF_Msk) {
		event |= BSP_RESET_TYPE_CPE;
	}
#endif /* R_SYSTEM_RSTSR1_CPERF_Msk */

#ifdef R_SYSTEM_RSTSR1_WDT1RF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_WDT1RF_Msk) {
		event |= BSP_RESET_TYPE_WDT1;
	}
#endif /* R_SYSTEM_RSTSR1_WDT1RF_Msk */

#ifdef R_SYSTEM_RSTSR1_CLU1RF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_CLU1RF_Msk) {
		event |= BSP_RESET_TYPE_CLU1RF;
	}
#endif /* R_SYSTEM_RSTSR1_CLU1RF_Msk */

#ifdef R_SYSTEM_RSTSR1_LM1RF_Msk
	if (R_SYSTEM->RSTSR1 & R_SYSTEM_RSTSR1_LM1RF_Msk) {
		event |= BSP_RESET_TYPE_LM1;
	}
#endif /* R_SYSTEM_RSTSR1_LM1RF_Msk */

#if BSP_CFG_VBATT_MANUAL_CONFIGURATION
  #ifdef R_SYSTEM_VBTBPSR_VBPORF_Msk
	if (vbtbpsr_state_at_boot & R_SYSTEM_VBTBPSR_VBPORF_Msk) {
		event |= BSP_RESET_TYPE_VBATPOR;
	}
  #endif /* R_SYSTEM_VBTBPSR_VBPORF_Msk */
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */

	return event;
}
