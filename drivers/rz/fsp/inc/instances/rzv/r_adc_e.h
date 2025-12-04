/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ADC_E_H
#define R_ADC_E_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdlib.h>

/* Fixed width integer support. */
#include <stdint.h>

/* bool support */
#include <stdbool.h>
#include "bsp_api.h"
#include "r_adc_e_cfg.h"
#include "r_adc_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup ADC_E
 * @{
 **********************************************************************************************************************/

/** For ADC Scan configuration adc_channel_cfg_t::scan_mask, adc_channel_cfg_t::scan_mask_group_b,
 *  adc_channel_cfg_t::add_mask and adc_channel_cfg_t::sample_hold_mask.
 *  Use bitwise OR to combine these masks for desired channels and sensors.    */
typedef enum e_adc_e_mask
{
    ADC_E_MASK_OFF        = (0U),        ///< No channels selected
    ADC_E_MASK_CHANNEL_0  = (1U << 0U),  ///< Channel 0 mask
    ADC_E_MASK_CHANNEL_1  = (1U << 1U),  ///< Channel 1 mask
    ADC_E_MASK_CHANNEL_2  = (1U << 2U),  ///< Channel 2 mask
    ADC_E_MASK_CHANNEL_3  = (1U << 3U),  ///< Channel 3 mask
    ADC_E_MASK_CHANNEL_4  = (1U << 4U),  ///< Channel 4 mask
    ADC_E_MASK_CHANNEL_5  = (1U << 5U),  ///< Channel 5 mask
    ADC_E_MASK_CHANNEL_6  = (1U << 6U),  ///< Channel 6 mask
    ADC_E_MASK_CHANNEL_7  = (1U << 7U),  ///< Channel 7 mask
} adc_e_mask_t;

/** ADC data sample addition and averaging options */
typedef enum e_adc_e_add
{
    ADC_E_ADD_OFF             = 0,       ///< Addition turned off for channels/sensors
    ADC_E_ADD_TWO             = 1,       ///< Add two samples
    ADC_E_ADD_THREE           = 2,       ///< Add three samples
    ADC_E_ADD_FOUR            = 3,       ///< Add four samples
    ADC_E_ADD_SIXTEEN         = 5,       ///< Add sixteen samples
    ADC_E_ADD_AVERAGE_TWO     = 0x81,    ///< Average two samples
    ADC_E_ADD_AVERAGE_FOUR    = 0x83,    ///< Average four samples
} adc_e_add_t;

/** ADC clear after read definitions */
typedef enum e_adc_e_clear
{
    ADC_E_CLEAR_AFTER_READ_OFF = 0,      ///< Clear after read off
    ADC_E_CLEAR_AFTER_READ_ON  = 1       ///< Clear after read on
} adc_e_clear_t;

/** ADC action for group A interrupts group B scan.
 * This enumeration is used to specify the priority between Group A and B in group mode.  */
typedef enum e_adc_e_group_a
{
    ADC_E_GRPA_PRIORITY_OFF                         = 0,                ///< Group A ignored and does not interrupt Group B and Group C
    ADC_E_GRPA_GRPB_GRPC_WAIT_TRIG                  = 1,                ///< Group B and Group C restart at next trigger
    ADC_E_GRPA_GRPB_GRPC_TOP_RESTART_SCAN           = 3,                ///< Group B and Group C restart immediately and scans from the head of the channel
    ADC_E_GRPA_GRPB_GRPC_RESTART_SCAN               = 0x4003,           ///< Group B and Group C restart immediately and scans
    ADC_E_GRPA_GRPB_GRPC_TOP_CONT_SCAN              = 0x8001,           ///< Group B and Group C restart and scans continuously from the head of the channel
    ADC_E_GRPA_GRPB_GRPC_RESTART_TOP_CONT_SCAN      = 0x8003,           ///< Group B and Group C restart immediately and scans continuously from the head of the channel
    ADC_E_GRPA_GRPB_GRPC_RESTART_CONT_SCAN          = 0xC003,           ///< Group B and Group C restart immediately and scans continuously
} adc_e_grpa_t;

/** Defines the registers settings for the ADC trigger. */
typedef enum e_adc_e_active_trigger
{
    ADC_E_ACTIVE_TRIGGER_EXTERNAL           = (0x00U),  ///< Input pin for the trigger
    ADC_E_ACTIVE_TRIGGER_GTADTRA0N          = (0x01U),  ///< Compare match with GPT00.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB0N          = (0x02U),  ///< Compare match with GPT00.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA1N          = (0x03U),  ///< Compare match with GPT01.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB1N          = (0x04U),  ///< Compare match with GPT01.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA2N          = (0x05U),  ///< Compare match with GPT02.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB2N          = (0x06U),  ///< Compare match with GPT02.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA3N          = (0x07U),  ///< Compare match with GPT03.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB3N          = (0x08U),  ///< Compare match with GPT03.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA4N          = (0x09U),  ///< Compare match with GPT04.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB4N          = (0x0AU),  ///< Compare match with GPT04.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA5N          = (0x0BU),  ///< Compare match with GPT05.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB5N          = (0x0CU),  ///< Compare match with GPT05.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA6N          = (0x0DU),  ///< Compare match with GPT06.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB6N          = (0x0EU),  ///< Compare match with GPT06.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA7N          = (0x0FU),  ///< Compare match with GPT07.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB7N          = (0x10U),  ///< Compare match with GPT07.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA8N          = (0x11U),  ///< Compare match with GPT08.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB8N          = (0x12U),  ///< Compare match with GPT08.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA9N          = (0x13U),  ///< Compare match with GPT09.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB9N          = (0x14U),  ///< Compare match with GPT09.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA10N         = (0x15U),  ///< Compare match with GPT10.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB10N         = (0x16U),  ///< Compare match with GPT10.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA11N         = (0x17U),  ///< Compare match with GPT11.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB11N         = (0x18U),  ///< Compare match with GPT11.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA12N         = (0x19U),  ///< Compare match with GPT12.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB12N         = (0x1AU),  ///< Compare match with GPT12.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA13N         = (0x1BU),  ///< Compare match with GPT13.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB13N         = (0x1CU),  ///< Compare match with GPT13.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA14N         = (0x1DU),  ///< Compare match with GPT14.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB14N         = (0x1EU),  ///< Compare match with GPT14.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA15N         = (0x1FU),  ///< Compare match with GPT15.GTADTRA
    ADC_E_ACTIVE_TRIGGER_GTADTRB15N         = (0x20U),  ///< Compare match with GPT15.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA0N_B0N      = (0x21U),  ///< Compare match with GPT00.GTADTRA or Compare match with GPT00.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA1N_B1N      = (0x22U),  ///< Compare match with GPT01.GTADTRA or Compare match with GPT01.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA2N_B2N      = (0x23U),  ///< Compare match with GPT02.GTADTRA or Compare match with GPT02.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA3N_B3N      = (0x24U),  ///< Compare match with GPT03.GTADTRA or Compare match with GPT03.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA4N_B4N      = (0x25U),  ///< Compare match with GPT04.GTADTRA or Compare match with GPT04.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA5N_B5N      = (0x26U),  ///< Compare match with GPT05.GTADTRA or Compare match with GPT05.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA6N_B6N      = (0x27U),  ///< Compare match with GPT06.GTADTRA or Compare match with GPT06.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA7N_B7N      = (0x28U),  ///< Compare match with GPT07.GTADTRA or Compare match with GPT07.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA8N_B8N      = (0x29U),  ///< Compare match with GPT08.GTADTRA or Compare match with GPT08.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA9N_B9N      = (0x2AU),  ///< Compare match with GPT09.GTADTRA or Compare match with GPT09.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA10N_B10N    = (0x2BU),  ///< Compare match with GPT10.GTADTRA or Compare match with GPT10.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA11N_B11N    = (0x2CU),  ///< Compare match with GPT11.GTADTRA or Compare match with GPT11.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA12N_B12N    = (0x2DU),  ///< Compare match with GPT12.GTADTRA or Compare match with GPT12.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA13N_B13N    = (0x2EU),  ///< Compare match with GPT13.GTADTRA or Compare match with GPT13.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA14N_B14N    = (0x2FU),  ///< Compare match with GPT14.GTADTRA or Compare match with GPT14.GTADTRB
    ADC_E_ACTIVE_TRIGGER_GTADTRA15N_B15N    = (0x30U),  ///< Compare match with GPT15.GTADTRA or Compare match with GPT15.GTADTRB
    ADC_E_ACTIVE_TRIGGER_ELCTRG0            = (0x31U),  ///< ELC trigger
    ADC_E_ACTIVE_TRIGGER_DISABLED           = (0x3FU),  ///< Trigger source de-selection state
} adc_e_active_trigger_t;

/** ADC double-trigger mode definitions */
typedef enum e_adc_e_double_trigger
{
    ADC_E_DOUBLE_TRIGGER_DISABLED         = 0, ///< Double-triggering disabled
    ADC_E_DOUBLE_TRIGGER_ENABLED          = 1, ///< Double-triggering enabled
    ADC_E_DOUBLE_TRIGGER_ENABLED_EXTENDED = 2, ///< Double-triggering enabled on both ADC ELC events
} adc_e_double_trigger_t;

/** ADC comparison settings */
typedef enum e_adc_e_compare_cfg
{
    ADC_E_COMPARE_CFG_EVENT_OUTPUT_OR  = 0,
    ADC_E_COMPARE_CFG_EVENT_OUTPUT_XOR = 1,
    ADC_E_COMPARE_CFG_EVENT_OUTPUT_AND = 2,
    ADC_E_COMPARE_CFG_A_ENABLE         = R_ADC_E_ADCMPCR_CMPAE_Msk | R_ADC_E_ADCMPCR_CMPAIE_Msk,
    ADC_E_COMPARE_CFG_B_ENABLE         = R_ADC_E_ADCMPCR_CMPBE_Msk | R_ADC_E_ADCMPCR_CMPBIE_Msk,
    ADC_E_COMPARE_CFG_WINDOW_ENABLE    = R_ADC_E_ADCMPCR_WCMPE_Msk,
} adc_e_compare_cfg_t;

/** ADC Window B channel */
typedef enum e_adc_e_window_b_channel
{
    ADC_E_WINDOW_B_CHANNEL_0 = 0,
    ADC_E_WINDOW_B_CHANNEL_1,
    ADC_E_WINDOW_B_CHANNEL_2,
    ADC_E_WINDOW_B_CHANNEL_3,
    ADC_E_WINDOW_B_CHANNEL_4,
    ADC_E_WINDOW_B_CHANNEL_5,
    ADC_E_WINDOW_B_CHANNEL_6,
    ADC_E_WINDOW_B_CHANNEL_7,
    ADC_E_WINDOW_B_CHANNEL_NONE = 63,
} adc_e_window_b_channel_t;

/** ADC Window B comparison mode */
typedef enum e_adc_e_window_b_mode
{
    ADC_E_WINDOW_B_MODE_LESS_THAN_OR_OUTSIDE   = 0,
    ADC_E_WINDOW_B_MODE_GREATER_THAN_OR_INSIDE = R_ADC_E_ADCMPBNSR_CMPLB_Msk,
} adc_e_window_b_mode_t;

/** AD event link control definitions. */
typedef enum e_adc_e_elc
{
    ADC_E_ELC_GROUP_A_SCAN     = 0x00U,  ///< At the end of a group_a scan   GCELC = 0b, ELCC[1:0] = 00b
    ADC_E_ELC_GROUP_B_SCAN     = 0x01U,  ///< At the end of a group_b scan   GCELC = 0b, ELCC[1:0] = 01b
    ADC_E_ELC_GROUP_A_B_C_SCAN = 0x02U,  ///< At the end of a group_abc scan GCELC = 0b, ELCC[1:0] = 1xb
    ADC_E_ELC_GROUP_C_SCAN     = 0x04U,  ///< At the end of a group_c scan   GCELC = 1b, ELCC[1:0] = 00b
} adc_e_elc_t;

/** Extended configuration structure for ADC. */
typedef struct st_adc_e_extended_cfg
{
    adc_e_add_t            add_average_count;           ///< Add or average samples
    adc_e_clear_t          clearing;                    ///< Clear after read
    adc_trigger_t          trigger_group_b;             ///< Group B trigger source; valid only for group mode
    adc_e_double_trigger_t double_trigger_mode;         ///< Double-trigger mode setting
    adc_e_active_trigger_t adc_start_trigger_a;         ///< A/D Conversion Start Trigger Group A
    adc_e_active_trigger_t adc_start_trigger_b;         ///< A/D Conversion Start Trigger Group B
    bool                   adc_start_trigger_c_enabled; ///< Set to true to enable Group C, false to disable Group C
    adc_e_active_trigger_t adc_start_trigger_c;         ///< A/D Conversion Start Trigger Group C
    adc_e_elc_t            adc_elc_ctrl;                ///< A/D Event Link Control
    IRQn_Type              window_a_irq;                ///< IRQ number for Window Compare A interrupts
    IRQn_Type              window_b_irq;                ///< IRQ number for Window Compare B interrupts
    uint8_t                window_a_ipl;                ///< Priority for Window Compare A interrupts
    uint8_t                window_b_ipl;                ///< Priority for Window Compare B interrupts
} adc_e_extended_cfg_t;

/** ADC Window Compare configuration */
typedef struct st_adc_e_window_cfg
{
    uint32_t                 compare_mask;       ///< Channel mask to compare with Window A
    uint32_t                 compare_mode_mask;  ///< Per-channel condition mask for Window A
    adc_e_compare_cfg_t      compare_cfg;        ///< Window Compare configuration
    uint16_t                 compare_ref_low;    ///< Window A lower reference value
    uint16_t                 compare_ref_high;   ///< Window A upper reference value
    uint16_t                 compare_b_ref_low;  ///< Window B lower reference value
    uint16_t                 compare_b_ref_high; ///< Window A upper reference value
    adc_e_window_b_channel_t compare_b_channel;  ///< Window B channel
    adc_e_window_b_mode_t    compare_b_mode;     ///< Window B condition setting
} adc_e_window_cfg_t;

/** ADC channel(s) configuration       */
typedef struct st_adc_e_channel_cfg
{
    uint32_t            scan_mask;           ///< Channels/bits: bit 0 is ch0; bit 15 is ch15.
    uint32_t            scan_mask_group_b;   ///< Valid for group modes.
    uint32_t            scan_mask_group_c;   ///< Valid for group modes.
    uint32_t            add_mask;            ///< Valid if add enabled in Open().
    adc_e_window_cfg_t * p_window_cfg;       ///< Pointer to Window Compare configuration
    adc_e_grpa_t        priority_group_a;    ///< Valid for group modes.
} adc_e_channel_cfg_t;

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** ADC instance control block. DO NOT INITIALIZE.  Initialized in @ref adc_api_t::open(). */
typedef struct
{
    R_ADC_E0_Type     * p_reg;                  // Base register for this unit
    adc_cfg_t const   * p_cfg;
    uint32_t          opened;                   // Boolean to verify that the Unit has been initialized
    uint32_t          initialized;              // Initialized status of ADC
    uint32_t          scan_mask;                // Scan mask used for Normal scan.
    uint16_t          scan_start_adcsr;
    uint16_t          scan_start_adstrgr;
    uint8_t           scan_start_adgctrgr;

    void (* p_callback)(adc_callback_args_t *); // Pointer to callback that is called when an adc_event_t occurs.
    adc_callback_args_t * p_callback_memory;    // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.

    /* Pointer to context to be passed into callback function */
    void const * p_context;
} adc_e_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Interface Structure for user access */
extern const adc_api_t g_adc_on_adc_e;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_ADC_E_Open(adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg);
fsp_err_t R_ADC_E_ScanCfg(adc_ctrl_t * p_ctrl, void const * const p_channel_cfg);
fsp_err_t R_ADC_E_InfoGet(adc_ctrl_t * p_ctrl, adc_info_t * p_adc_info);
fsp_err_t R_ADC_E_ScanStart(adc_ctrl_t * p_ctrl);
fsp_err_t R_ADC_E_ScanGroupStart(adc_ctrl_t * p_ctrl, adc_group_mask_t group_id);
fsp_err_t R_ADC_E_ScanStop(adc_ctrl_t * p_ctrl);
fsp_err_t R_ADC_E_StatusGet(adc_ctrl_t * p_ctrl, adc_status_t * p_status);
fsp_err_t R_ADC_E_Read(adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint16_t * const p_data);
fsp_err_t R_ADC_E_Read32(adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint32_t * const p_data);
fsp_err_t R_ADC_E_Close(adc_ctrl_t * p_ctrl);
fsp_err_t R_ADC_E_OffsetSet(adc_ctrl_t * const p_ctrl, adc_channel_t const reg_id, int32_t offset);
fsp_err_t R_ADC_E_Calibrate(adc_ctrl_t * const p_ctrl, void const * p_extend);
fsp_err_t R_ADC_E_CallbackSet(adc_ctrl_t * const          p_api_ctrl,
                            void (                    * p_callback)(adc_callback_args_t *),
                            void const * const          p_context,
                            adc_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end defgroup ADC_E)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
