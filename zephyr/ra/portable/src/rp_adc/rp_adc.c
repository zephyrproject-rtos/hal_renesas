/*
 * Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_adc.h"
#include "r_adc_cfg.h"
#include "rp_adc.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Calculate ADC sample state count based on desired sampling time (in ns).
 *
 * @param[in]  sampling_time_ns   Desired sampling time in nanoseconds, or UNSPECIFIED to use BSP default.
 * @param[out] p_sample_count     Pointer to store calculated sample state count.
 *
 * @retval FSP_SUCCESS                    Calculation successful.
 * @retval FSP_ERR_INVALID_ARGUMENT       p_sample_count is NULL.
 * @retval FSP_ERR_INVALID_HW_CONDITION   ADC clock frequency not available.
 **********************************************************************************************************************/
fsp_err_t RP_ADC_SampleStateCalculation(uint32_t sampling_time_ns, uint32_t *p_sample_count)
{
	if (NULL == p_sample_count) {
		return FSP_ERR_INVALID_ARGUMENT;
	}

	/* Get ADC clock frequency */
	uint32_t adc_clk_hz = R_FSP_SystemClockHzGet(BSP_FEATURE_ADC_CLOCK_SOURCE);
	if (0u == adc_clk_hz) {
		return FSP_ERR_INVALID_HW_CONDITION;
	}

	/* If user did not specify a sampling time, use the BSP-feature minimum value for ADC */
	if (UNSPECIFIED == sampling_time_ns) {
		sampling_time_ns = BSP_FEATURE_ADC_SENSOR_MIN_SAMPLING_TIME;
	}

	/* Calculate number of sample states with round-up */
	uint32_t sample_states =
		((sampling_time_ns * (adc_clk_hz / ADC_PRV_HZ_PER_KHZ)) / ADC_PRV_USEC_PER_SEC) +
		1U;

	/* Ensure the state count is not smaller than the minimum allowed */
	if (sample_states < ADC_SAMPLE_STATE_COUNT_MIN) {
		sample_states = ADC_SAMPLE_STATE_COUNT_MIN;
	}

	/* Clamp to hardware maximum (8-bit register, so max 255) */
	if (sample_states > ADC_SAMPLE_STATE_COUNT_MAX) {
		sample_states = ADC_SAMPLE_STATE_COUNT_MAX;
	}

	*p_sample_count = sample_states;

	return FSP_SUCCESS;
}
