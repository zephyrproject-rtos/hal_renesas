/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup DMAC_B
 * @{
 **********************************************************************************************************************/

#ifndef R_DMAC_B_H
#define R_DMAC_B_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_transfer_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Max configurable number of transfers in TRANSFER_MODE_NORMAL. */
#define DMAC_B_MAX_NORMAL_TRANSFER_LENGTH    (0xFFFFFFFF)

/** Max number of transfers per block in TRANSFER_MODE_BLOCK */
#define DMAC_B_MAX_BLOCK_TRANSFER_LENGTH     (0xFFFFFFFF)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Events that can trigger a callback function. */
typedef enum e_dmac_b_event
{
    DMAC_B_EVENT_TRANSFER_END   = 0,     ///< DMA transfer has completed.
    DMAC_B_EVENT_TRANSFER_ERROR = 1,     ///< A bus error occurred during DMA transfer.
} dmac_b_event_t;

/** Callback function parameter data. */
typedef struct st_dmac_b_callback_args_t
{
    dmac_b_event_t event;                ///< Event code
    void const * p_context;            ///< Placeholder for user data.  Set in r_transfer_t::open function in ::transfer_cfg_t.
} dmac_b_callback_args_t;

/** Transfer size specifies the size of each individual transfer. */
typedef enum e_dmac_b_transfer_size
{
    DMAC_B_TRANSFER_SIZE_1_BYTE   = 0,   ///< Each transfer transfers a 8-bit value.
    DMAC_B_TRANSFER_SIZE_2_BYTE   = 1,   ///< Each transfer transfers a 16-bit value.
    DMAC_B_TRANSFER_SIZE_4_BYTE   = 2,   ///< Each transfer transfers a 32-bit value.
    DMAC_B_TRANSFER_SIZE_8_BYTE   = 3,   ///< Each transfer transfers a 64-bit value.
    DMAC_B_TRANSFER_SIZE_16_BYTE  = 4,   ///< Each transfer transfers a 128-bit value.
    DMAC_B_TRANSFER_SIZE_32_BYTE  = 5,   ///< Each transfer transfers a 256-bit value.
    DMAC_B_TRANSFER_SIZE_64_BYTE  = 6,   ///< Each transfer transfers a 512-bit value.
    DMAC_B_TRANSFER_SIZE_128_BYTE = 7,   ///< Each transfer transfers a 1024-bit value.
} dmac_b_transfer_size_t;

/** DACK output mode. See RZ/T2M hardware manual Table 14.19 DMA Transfer Request Detection Operation Setting Table. */
typedef enum e_dmac_b_ack_mode
{
    DMAC_B_ACK_MODE_LEVEL_MODE       = 1, ///< Level mode.
    DMAC_B_ACK_MODE_BUS_CYCLE_MODE   = 2, ///< Bus cycle mode.
    DMAC_B_ACK_MODE_MASK_DACK_OUTPUT = 4, ///< Output is masked.
} dmac_b_ack_mode_t;

#ifndef BSP_OVERRIDE_DMAC_B_EXTERNAL_DETECTION_T

/** Detection method of the external DMA request signal. See RZ/T2M hardware manual Table 14.19 DMA Transfer Request Detection Operation Setting Table. */
typedef enum e_dmac_b_external_detection
{
    DMAC_B_EXTERNAL_DETECTION_LOW_LEVEL           = 0,   ///< Low level detection.
    DMAC_B_EXTERNAL_DETECTION_FALLING_EDGE        = 1,   ///< Falling edge detection.
    DMAC_B_EXTERNAL_DETECTION_RISING_EDGE         = 2,   ///< Rising edge detection.
    DMAC_B_EXTERNAL_DETECTION_FALLING_RISING_EDGE = 3,   ///< Falling/Rising edge detection.
} dmac_b_external_detection_t;

#endif

/** Detection method of the internal DMA request signal. See RZ/T2M hardware manual Table 14.19 DMA Transfer Request Detection Operation Setting Table. */
typedef enum e_dmac_b_internal_detection
{
    DMAC_B_INTERNAL_DETECTION_NO_DETECTION = 0,   ///< Not using hardware detection.
    DMAC_B_INTERNAL_DETECTION_FALLING_EDGE = 1,   ///< Falling edge detection.
    DMAC_B_INTERNAL_DETECTION_RISING_EDGE  = 2,   ///< Rising edge detection.
    DMAC_B_INTERNAL_DETECTION_LOW_LEVEL    = 5,   ///< Low level detection.
    DMAC_B_INTERNAL_DETECTION_HIGH_LEVEL   = 6,   ///< High level detection.
} dmac_b_internal_detection_t;

/** DMA activation request source select. See RZ/T2M hardware manual Table 14.19 DMA Transfer Request Detection Operation Setting Table. */
typedef enum e_dmac_b_request_direction
{
    DMAC_B_REQUEST_DIRECTION_SOURCE_MODULE      = 0, ///< Requested by a transfer source module.
    DMAC_B_REQUEST_DIRECTION_DESTINATION_MODULE = 1, ///< Requested by a transfer destination module.
} dmac_b_request_direction_t;

/** Select the Next register set to be executed next. */
typedef enum e_dmac_b_continuous_setting
{
    DMAC_B_CONTINUOUS_SETTING_TRANSFER_ONCE        = 0x0, ///< Transfer only once using the Next0 register set.
    DMAC_B_CONTINUOUS_SETTING_TRANSFER_ALTERNATELY = 0x3, ///< Transfers are performed alternately with the Next0 register set and the Next1 register set.
} dmac_b_continuous_setting_t;

/** Register set settings. */
typedef struct st_dmac_b_register_set_setting_t
{
    void const * p_src;                ///< Source pointer.
    void       * p_dest;               ///< Destination pointer.
    uint32_t     length;               ///< Transfer byte.
} dmac_b_register_set_setting_t;

/** DMAC channel scheduling. */
typedef enum e_dmac_b_channel_scheduling
{
    DMAC_B_CHANNEL_SCHEDULING_FIXED       = 0, ///< Fixed priority mode.
    DMAC_B_CHANNEL_SCHEDULING_ROUND_ROBIN = 1, ///< Round-robin mode.
} dmac_b_channel_scheduling_t;

/** DMAC mode setting. */
typedef enum e_dmac_b_mode_select
{
    DMAC_B_MODE_SELECT_REGISTER = 0,     ///< Register mode.
    DMAC_B_MODE_SELECT_LINK     = 1,     ///< Link mode.
} dmac_b_mode_select_t;

/** Control block used by driver. DO NOT INITIALIZE - this structure will be initialized in @ref transfer_api_t::open. */
typedef struct st_dmac_b_instance_ctrl
{
    uint32_t open;                     // Driver ID

    transfer_cfg_t const * p_cfg;

    /* Pointer to base register. */
    R_DMAC_B0_Type * p_reg;
} dmac_b_instance_ctrl_t;

/** DMAC transfer configuration extension. This extension is required. */
typedef struct st_dmac_b_extended_cfg
{
    uint8_t   unit;                     ///< Unit number
    uint8_t   channel;                  ///< Channel number
    IRQn_Type dmac_int_irq;             ///< DMAC interrupt number
    uint8_t   dmac_int_ipl;             ///< DMAC interrupt priority

    /** Select which event will trigger the transfer. */
    dmac_trigger_event_t activation_source;

    dmac_b_ack_mode_t           ack_mode;                         ///< DACK output mode
	dmac_b_external_detection_t external_detection_mode;          ///< DMAC request detection method for external pin
    dmac_b_internal_detection_t internal_detection_mode;          ///< DMAC request detection method for internal pin
    dmac_b_request_direction_t  activation_request_source_select; ///< DMAC activation request source

    dmac_b_mode_select_t dmac_mode;                      ///< DMAC Mode
    dmac_b_continuous_setting_t continuous_setting;      ///< Next register operation settings
    uint16_t transfer_interval;                        ///< DMA transfer interval
    dmac_b_channel_scheduling_t channel_scheduling;      ///< DMA channel scheduling

    /** Callback for transfer end interrupt. */
    void (* p_callback)(dmac_b_callback_args_t * cb_data);

    /** Placeholder for user data.  Passed to the user p_callback in ::dmac_b_callback_args_t. */
    void const * p_context;
} dmac_b_extended_cfg_t;

/** DMAC transfer information configuration extension. This extension is required. */
typedef struct st_dmac_b_extended_info
{
    /** Select number of source bytes to transfer at once. */
    dmac_b_transfer_size_t src_size;

    /** Select number of destination bytes to transfer at once. */
    dmac_b_transfer_size_t dest_size;

    /** Next1 Register set settings */
    dmac_b_register_set_setting_t * p_next1_register_setting;
} dmac_b_extended_info_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const transfer_api_t g_transfer_on_dmac_b;

/** @endcond */

/***********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t R_DMAC_B_Open(transfer_ctrl_t * const p_api_ctrl, transfer_cfg_t const * const p_cfg);
fsp_err_t R_DMAC_B_Reconfigure(transfer_ctrl_t * const p_api_ctrl, transfer_info_t * p_info);
fsp_err_t R_DMAC_B_Reset(transfer_ctrl_t * const p_api_ctrl,
                         void const * volatile   p_src,
                         void * volatile         p_dest,
                         uint16_t const          num_transfers);
fsp_err_t R_DMAC_B_SoftwareStart(transfer_ctrl_t * const p_api_ctrl, transfer_start_mode_t mode);
fsp_err_t R_DMAC_B_SoftwareStop(transfer_ctrl_t * const p_api_ctrl);
fsp_err_t R_DMAC_B_Enable(transfer_ctrl_t * const p_api_ctrl);
fsp_err_t R_DMAC_B_Disable(transfer_ctrl_t * const p_api_ctrl);
fsp_err_t R_DMAC_B_InfoGet(transfer_ctrl_t * const p_api_ctrl, transfer_properties_t * const p_info);
fsp_err_t R_DMAC_B_Close(transfer_ctrl_t * const p_api_ctrl);
fsp_err_t R_DMAC_B_Reload(transfer_ctrl_t * const p_api_ctrl,
                          void const            * p_src,
                          void                  * p_dest,
                          uint32_t const          num_transfers);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup DMAC)
 **********************************************************************************************************************/
