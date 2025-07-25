/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup ADC_C
 * @{
 **********************************************************************************************************************/

#ifndef R_ADC_C_H
#define R_ADC_C_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include "r_adc_c_cfg.h"
#include "r_adc_api.h"
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** For ADC Scan configuration adc_channel_cfg_t::scan_mask.
 * Use bitwise OR to combine these masks for desired channels.   */
typedef enum e_adc_c_mask
{
    ADC_C_MASK_OFF           = (0U),            ///< No channels selected
    ADC_C_MASK_CHANNEL_0     = (1U << 0U),      ///< Channel 0 mask
    ADC_C_MASK_CHANNEL_1     = (1U << 1U),      ///< Channel 1 mask
    ADC_C_MASK_CHANNEL_2     = (1U << 2U),      ///< Channel 2 mask
    ADC_C_MASK_CHANNEL_3     = (1U << 3U),      ///< Channel 3 mask
    ADC_C_MASK_CHANNEL_4     = (1U << 4U),      ///< Channel 4 mask
    ADC_C_MASK_CHANNEL_5     = (1U << 5U),      ///< Channel 5 mask
    ADC_C_MASK_CHANNEL_6     = (1U << 6U),      ///< Channel 6 mask
    ADC_C_MASK_CHANNEL_7     = (1U << 7U),      ///< Channel 7 mask
    ADC_C_MASK_CHANNEL_8     = (1U << 8U),      ///< Channel 8 mask (Temperature sensor channel mask)
} adc_c_mask_t;

/** ADC trigger mode select */
typedef enum e_adc_c_trigger_mode
{
    ADC_C_TRIGGER_MODE_SOFTWARE = 0U,          ///< Software trigger mode
    ADC_C_TRIGGER_MODE_HARDWARE = 1U,          ///< Hardware trigger mode
} adc_c_trigger_mode_t;

/** ADC hardware trigger source select */
typedef enum e_adc_c_active_trigger
{
    ADC_C_ACTIVE_TRIGGER_EXTERNAL    = 0U,            ///< External trigger input
    ADC_C_ACTIVE_TRIGGER_TRGA0N      = 1U,            ///< Compare match with or input capture to MTU0.TGRA
    ADC_C_ACTIVE_TRIGGER_TRGA1N      = 2U,            ///< Compare match with or input capture to MTU1.TGRA
    ADC_C_ACTIVE_TRIGGER_TRGA2N      = 3U,            ///< Compare match with or input capture to MTU2.TGRA
    ADC_C_ACTIVE_TRIGGER_TRGA3N      = 4U,            ///< Compare match with or input capture to MTU3.TGRA
    ADC_C_ACTIVE_TRIGGER_TRGA4N      = 5U,            ///< Compare match with or input capture to MTU4.TGRA
    ADC_C_ACTIVE_TRIGGER_TRGA6N      = 6U,            ///< Compare match with or input capture to MTU6.TGRA
    ADC_C_ACTIVE_TRIGGER_TRGA7N      = 7U,            ///< Compare match with or input capture to MTU7.TGRA
    ADC_C_ACTIVE_TRIGGER_TRG0N       = 8U,            ///< Compare match with MTU0.TGRE
    ADC_C_ACTIVE_TRIGGER_TRG4AN      = 9U,            ///< Compare match between MTU4.TADCORA and MTU4.TCNT
    ADC_C_ACTIVE_TRIGGER_TRG4BN      = 10U,           ///< Compare match between MTU4.TADCORB and MTU4.TCNT
    ADC_C_ACTIVE_TRIGGER_TRG4AN_BN   = 11U,           ///< Compare match between MTU4.TADCORA and MTU4.TCNT, or between MTU4.TADCORB and MTU4.TCNT
    ADC_C_ACTIVE_TRIGGER_TRG4ABN     = 12U,           ///< Compare match between MTU4.TADCORA and MTU4.TCNT, and between MTU4.TADCORB and MTU4.TCNT (when interrupt skipping function 2 is in use)
    ADC_C_ACTIVE_TRIGGER_TRG7AN      = 13U,           ///< Compare match between MTU7.TADCORA and MTU7.TCNT
    ADC_C_ACTIVE_TRIGGER_TRG7BN      = 14U,           ///< Compare match between MTU7.TADCORB and MTU7.TCNT
    ADC_C_ACTIVE_TRIGGER_TRG7AN_BN   = 15U,           ///< Compare match between MTU7.TADCORA and MTU7.TCNT, or between MTU7.TADCORB and MTU7.TCNT
    ADC_C_ACTIVE_TRIGGER_TRG7ABN     = 16U,           ///< Compare match between MTU7.TADCORA and MTU7.TCNT, and between MTU7.TADCORB and MTU7.TCNT
    ADC_C_ACTIVE_TRIGGER_ADTRGA0     = 17U,           ///< Compare match with GPT0.GTADTRA
    ADC_C_ACTIVE_TRIGGER_ADTRGB0     = 18U,           ///< Compare match with GPT0.GTADTRB
    ADC_C_ACTIVE_TRIGGER_ADTRGA1     = 19U,           ///< Compare match with GPT1.GTADTRA
    ADC_C_ACTIVE_TRIGGER_ADTRGB1     = 20U,           ///< Compare match with GPT1.GTADTRB
    ADC_C_ACTIVE_TRIGGER_ADTRGA2     = 21U,           ///< Compare match with GPT2.GTADTRA
    ADC_C_ACTIVE_TRIGGER_ADTRGB2     = 22U,           ///< Compare match with GPT2.GTADTRB
    ADC_C_ACTIVE_TRIGGER_ADTRGA3     = 23U,           ///< Compare match with GPT3.GTADTRA
    ADC_C_ACTIVE_TRIGGER_ADTRGB3     = 24U,           ///< Compare match with GPT3.GTADTRB
    ADC_C_ACTIVE_TRIGGER_ADTRGA0_B0  = 25U,           ///< Compare match with GPT0.GTADTRA or GPT0.GTADTRB
    ADC_C_ACTIVE_TRIGGER_ADTRGA1_B1  = 26U,           ///< Compare match with GPT1.GTADTRA or GPT1.GTADTRB
    ADC_C_ACTIVE_TRIGGER_ADTRGA2_B2  = 27U,           ///< Compare match with GPT2.GTADTRA or GPT2.GTADTRB
    ADC_C_ACTIVE_TRIGGER_ADTRGA3_B3  = 28U,           ///< Compare match with GPT3.GTADTRA or GPT3.GTADTRB
} adc_c_active_trigger_t;

/** valid edge of the trigger select */
typedef enum e_adc_c_trigger_edge
{
    ADC_C_TRIGGER_EDGE_FALLING   = 1U,         ///< Falling edge
    ADC_C_TRIGGER_EDGE_RISING    = 2U,         ///< Rising edge
    ADC_C_TRIGGER_EDGE_BOTH      = 3U,         ///< Both edges
} adc_c_trigger_edge_t;

/** ADC trigger input mode select */
typedef enum e_adc_c_input_mode
{
    ADC_C_INPUT_MODE_AUTO   = 0U,              ///< Auto mode
    ADC_C_INPUT_MODE_STEP   = 1U,              ///< Step mode
} adc_c_input_mode_t;

/** ADC operating mode select */
typedef enum e_adc_c_operating_mode
{
    ADC_C_OPERATING_MODE_SCAN    = 0U,         ///< Scan mode
    ADC_C_OPERATING_MODE_SELECT  = 1U,         ///< Select mode
} adc_c_operating_mode_t;

/** ADC buffer mode select */
typedef enum e_adc_c_buffer_mode
{
    ADC_C_BUFFER_MODE_1  = 0U,                 ///< 1-buffer mode
    ADC_C_BUFFER_MODE_4  = 1U,                 ///< 4-buffer mode
} adc_c_buffer_mode_t;

/** Select the number of stages of the AD external trigger pin filter. */
typedef enum e_adc_c_filter_stage_setting_t
{
    ADC_C_FILTER_STAGE_SETTING_DISABLE            = 0U,      ///< Filter is disabled.
    ADC_C_FILTER_STAGE_SETTING_4                  = 1U,      ///< 12.5 ns (80 MHz) x 4 stages
    ADC_C_FILTER_STAGE_SETTING_8                  = 2U,      ///< 12.5 ns (80 MHz) x 8 stages
    ADC_C_FILTER_STAGE_SETTING_12                 = 3U,      ///< 12.5 ns (80 MHz) x 12 stages
    ADC_C_FILTER_STAGE_SETTING_16                 = 4U,      ///< 12.5 ns (80 MHz) x 16 stages
} adc_c_filter_stage_setting_t;

/** Enable or disable the conversion end interrupt of channel */
typedef enum e_adc_c_interrupt_channel_setting
{
    ADC_C_INTERRUPT_CHANNEL_SETTING_DISABLE    = 0,            ///< Interrupt output is disabled.
    ADC_C_INTERRUPT_CHANNEL_SETTING_ENABLE     = 1,            ///< Interrupt output is enabled.
} adc_c_interrupt_channel_setting_t;

/** Extended configuration structure for ADC. */
typedef struct st_adc_c_extended_cfg
{
    adc_c_trigger_mode_t                      trigger_mode;                   ///< Trigger mode.
    adc_c_active_trigger_t                    trigger_source;                 ///< Hardware trigger source.
    adc_c_trigger_edge_t                      trigger_edge;                   ///< Valid edge of the trigger source.
    adc_c_input_mode_t                        input_mode;                     ///< Trigger input mode.
    adc_c_operating_mode_t                    operating_mode;                 ///< Operating mode.
    adc_c_buffer_mode_t                       buffer_mode;                    ///< Buffer mode.
    uint16_t                                  sampling_time;                  ///< Sampling period. (6~2800)
    adc_c_filter_stage_setting_t              external_trigger_filter;        ///< AD external trigger pin filter.
} adc_c_extended_cfg_t;

/** ADC channel(s) configuration       */
typedef struct st_adc_c_channel_cfg
{
    uint32_t                                  scan_mask;                      ///< Channels/bits: bit 0 is ch0; bit 1 is ch1.
    adc_c_interrupt_channel_setting_t         interrupt_setting;              ///< Interrupt setting.
} adc_c_channel_cfg_t;

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** ADC instance control block. DO NOT INITIALIZE.  Initialized in @ref adc_api_t::open(). */
typedef struct
{
    R_ADC_C_Type      * p_reg;                    // Base register
    adc_cfg_t const * p_cfg;
    uint32_t          opened;                   // Boolean to verify that the Unit has been initialized
    uint32_t          initialized;              // Initialized status of ADC
    uint32_t          scan_mask;                // Scan mask used for Normal scan
    uint32_t          scan_start;
    uint32_t          operating_mode;
    uint32_t          buffer_mode;

    void (* p_callback)(adc_callback_args_t *); // Pointer to callback that is called when an adc_event_t occurs.
    adc_callback_args_t * p_callback_memory;    // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.

    /* Pointer to context to be passed into callback function */
    void const * p_context;
} adc_c_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Interface Structure for user access */
extern const adc_api_t g_adc_on_adc_c;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_ADC_C_Open(adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg);
fsp_err_t R_ADC_C_ScanCfg(adc_ctrl_t * p_ctrl, void const * const p_channel_cfg);
fsp_err_t R_ADC_C_InfoGet(adc_ctrl_t * p_ctrl, adc_info_t * p_adc_info);
fsp_err_t R_ADC_C_ScanStart(adc_ctrl_t * p_ctrl);
fsp_err_t R_ADC_C_ScanGroupStart(adc_ctrl_t * p_ctrl, adc_group_mask_t group_id);
fsp_err_t R_ADC_C_ScanStop(adc_ctrl_t * p_ctrl);
fsp_err_t R_ADC_C_StatusGet(adc_ctrl_t * p_ctrl, adc_status_t * p_status);
fsp_err_t R_ADC_C_Read(adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint16_t * const p_data);
fsp_err_t R_ADC_C_Read32(adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint32_t * const p_data);
fsp_err_t R_ADC_C_SampleStateCountSet(adc_ctrl_t * p_ctrl, uint16_t num_states);
fsp_err_t R_ADC_C_Close(adc_ctrl_t * p_ctrl);
fsp_err_t R_ADC_C_OffsetSet(adc_ctrl_t * const p_ctrl, adc_channel_t const reg_id, int32_t offset);
fsp_err_t R_ADC_C_Calibrate(adc_ctrl_t * const p_ctrl, void const * p_extend);
fsp_err_t R_ADC_C_CallbackSet(adc_ctrl_t * const          p_api_ctrl,
                            void (                    * p_callback)(adc_callback_args_t *),
                            void const * const          p_context,
                            adc_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end defgroup ADC_C)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
