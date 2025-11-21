/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
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

typedef transfer_callback_args_t dmac_b_callback_args_t;

/** Transfer size specifies the size of each individual transfer. */
typedef enum e_dmac_b_transfer_size
{
    DMAC_B_TRANSFER_SIZE_1_BYTE   = 0, ///< Each transfer transfers a 8-bit value.
    DMAC_B_TRANSFER_SIZE_2_BYTE   = 1, ///< Each transfer transfers a 16-bit value.
    DMAC_B_TRANSFER_SIZE_4_BYTE   = 2, ///< Each transfer transfers a 32-bit value.
    DMAC_B_TRANSFER_SIZE_8_BYTE   = 3, ///< Each transfer transfers a 64-bit value.
    DMAC_B_TRANSFER_SIZE_16_BYTE  = 4, ///< Each transfer transfers a 128-bit value.
    DMAC_B_TRANSFER_SIZE_32_BYTE  = 5, ///< Each transfer transfers a 256-bit value.
    DMAC_B_TRANSFER_SIZE_64_BYTE  = 6, ///< Each transfer transfers a 512-bit value.
    DMAC_B_TRANSFER_SIZE_128_BYTE = 7, ///< Each transfer transfers a 1024-bit value.
} dmac_b_transfer_size_t;

/** DACK output mode. */
typedef enum e_dmac_b_ack_mode
{
    DMAC_B_ACK_MODE_LEVEL_MODE       = 1, ///< Level mode.
    DMAC_B_ACK_MODE_BUS_CYCLE_MODE   = 2, ///< Bus cycle mode.
    DMAC_B_ACK_MODE_MASK_DACK_OUTPUT = 4, ///< Output is masked.
} dmac_b_ack_mode_t;

#ifndef BSP_OVERRIDE_DMAC_B_EXTERNAL_DETECTION_T

/** Detection method of the external DMA request signal. */
typedef enum e_dmac_b_external_detection
{
    DMAC_B_EXTERNAL_DETECTION_LOW_LEVEL           = 0, ///< Low level detection.
    DMAC_B_EXTERNAL_DETECTION_FALLING_EDGE        = 1, ///< Falling edge detection.
    DMAC_B_EXTERNAL_DETECTION_RISING_EDGE         = 2, ///< Rising edge detection.
    DMAC_B_EXTERNAL_DETECTION_FALLING_RISING_EDGE = 3, ///< Falling/Rising edge detection.
} dmac_b_external_detection_t;

#endif

/** Detection method of the internal DMA request signal. */
typedef enum e_dmac_b_internal_detection
{
    DMAC_B_INTERNAL_DETECTION_NO_DETECTION = 0, ///< Not using hardware detection.
    DMAC_B_INTERNAL_DETECTION_FALLING_EDGE = 1, ///< Falling edge detection.
    DMAC_B_INTERNAL_DETECTION_RISING_EDGE  = 2, ///< Rising edge detection.
    DMAC_B_INTERNAL_DETECTION_LOW_LEVEL    = 5, ///< Low level detection.
    DMAC_B_INTERNAL_DETECTION_HIGH_LEVEL   = 6, ///< High level detection.
} dmac_b_internal_detection_t;

/** DMA activation request source select. */
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
    DMAC_B_MODE_SELECT_REGISTER = 0,   ///< Register mode.
    DMAC_B_MODE_SELECT_LINK     = 1,   ///< Link mode.
} dmac_b_mode_select_t;

/** Indicates the descriptor is enabled or disabled. */
typedef enum e_dmac_b_link_valid
{
    DMAC_B_LINK_VALID_DESCRIPTOR_DISABLE = 0, ///< The Descriptor is disabled.
    DMAC_B_LINK_VALID_DESCRIPTOR_ENABLE  = 1, ///< The Descriptor is enabled.
} dmac_b_link_valid_t;

/** Indicates that the link ends during DMA transfer of this descriptor. */
typedef enum e_dmac_b_link_end
{
    DMAC_B_LINK_END_DISABLE = 0,       ///< The link continues.
    DMAC_B_LINK_END_ENABLE  = 1,       ///< The link ends.
} dmac_b_link_end_t;

/** Masks write back execution of the dmac_b_link_cfg_t::link_valid. When disable, DMAC does not perform write-back operation. */
typedef enum e_dmac_b_link_write_back
{
    DMAC_B_LINK_WRITE_BACK_ENABLE  = 0, ///< Set dmac_b_link_cfg_t::link_valid to disable after the DMA transfer ends.
    DMAC_B_LINK_WRITE_BACK_DISABLE = 1, ///< Remain dmac_b_link_cfg_t::link_valid after DMA transfer ends.
} dmac_b_link_write_back_t;

/** When dmac_b_link_cfg_t::link_valid is DMAC_B_LINK_VALID_DESCRIPTOR_DISABLE at loading of header, specifies whether DMA transfer completion interrupt mask or not. */
typedef enum e_dmac_b_link_interrupt_mask
{
    DMAC_B_LINK_INTERRUPT_MASK_DISABLE = 0, ///< DMA transfer completion interrupt is asserted.
    DMAC_B_LINK_INTERRUPT_MASK_ENABLE  = 1, ///< DMA transfer completion interrupt is masked.
} dmac_b_link_interrupt_mask_t;

/** Descriptor structure used in DMAC link mode, and variables of dmac_b_link_cfg_t must be allocated in the memory area. */
#if (BSP_FEATURE_DMAC_B_64BIT_SYSTEM == 1)
typedef struct st_dmac_b_link_cfg
{
    union
    {
        uint32_t header_u32;                                     ///< Descriptor header
        struct
        {
            dmac_b_link_valid_t          link_valid         : 1; ///< The descriptor is valid or not.
            dmac_b_link_end_t            link_end           : 1; ///< The descriptor is end or not.
            dmac_b_link_write_back_t     write_back_disable : 1; ///< Write back enable or not.
            dmac_b_link_interrupt_mask_t interrupt_mask     : 1; ///< Interrupt mask is enable or not.
            uint32_t                                        : 28;
        } header;
    };
    volatile uint32_t src_addr;                                  ///< Source address.
    volatile uint32_t dest_addr;                                 ///< Destination address.
    volatile uint32_t transaction_byte;                          ///< Transaction byte.
    volatile uint32_t channel_cfg;                               ///< Channel configuration (Set value for CHCFG_n register).
    volatile uint32_t channel_interval;                          ///< Channel interval (Set value for CHITVL register).
    volatile uint32_t channel_extension_cfg;                     ///< Channel extension configuration (Set value for CHEXT_n register).
    volatile uint32_t next_link_addr;                            ///< Next link address.
} dmac_b_link_cfg_t;
#else
typedef struct st_dmac_b_link_cfg
{
    union
    {
        uint32_t header_u32;                                     ///< Descriptor header
        struct
        {
            dmac_b_link_valid_t          link_valid         : 1; ///< The descriptor is valid or not.
            dmac_b_link_end_t            link_end           : 1; ///< The descriptor is end or not.
            dmac_b_link_write_back_t     write_back_disable : 1; ///< Write back enable or not.
            dmac_b_link_interrupt_mask_t interrupt_mask     : 1; ///< Interrupt mask is enable or not.
            uint32_t                                        : 28;
        } header;
    };
    void const * volatile p_src;                                 ///< Source address.
    void * volatile       p_dest;                                ///< Destination address.
    volatile uint32_t     transaction_byte;                      ///< Transaction byte.
    volatile uint32_t     channel_cfg;                           ///< Channel configuration (Set value for CHCFG_n register).
    volatile uint32_t     channel_interval;                      ///< Channel interval (Set value for CHITVL register).
    volatile uint32_t     channel_extension_cfg;                 ///< Channel extension configuration (Set value for CHEXT_n register).
    void * volatile       p_next_link_addr;                      ///< Next link address.
} dmac_b_link_cfg_t;
#endif

/** Control block used by driver. DO NOT INITIALIZE - this structure will be initialized in @ref transfer_api_t::open. */
typedef struct st_dmac_b_instance_ctrl
{
    uint32_t open;                     // Driver ID

    transfer_cfg_t const * p_cfg;

    dmac_b_link_cfg_t const * p_descriptor;

    /* Pointer to base register. */
    R_DMAC_B0_Type * p_reg;

    void (* p_callback)(dmac_b_callback_args_t *); // Pointer to callback
    dmac_b_callback_args_t * p_callback_memory;    // Pointer to optional callback argument memory
    void const             * p_context;            // Pointer to context to be passed into callback function
} dmac_b_instance_ctrl_t;

/** DMAC transfer configuration extension. This extension is required. */
typedef struct st_dmac_b_extended_cfg
{
    uint8_t   unit;                                                ///< Unit number
    uint8_t   channel;                                             ///< Channel number
    IRQn_Type dmac_int_irq;                                        ///< DMAC interrupt number
    uint8_t   dmac_int_ipl;                                        ///< DMAC interrupt priority

    /** Select which event will trigger the transfer. */
    dmac_trigger_event_t         activation_source;
    dmac_b_ack_mode_t            ack_mode;                         ///< DACK output mode
    dmac_b_external_input_pin_t  dreq_input_pin;                   ///< DREQ input pin name
    dmac_b_external_output_pin_t ack_output_pin;                   ///< DACK output pin name
    dmac_b_external_output_pin_t tend_output_pin;                  ///< TEND output pin name
    dmac_b_external_detection_t  external_detection_mode;          ///< DMAC request detection method for external pin
    dmac_b_internal_detection_t  internal_detection_mode;          ///< DMAC request detection method for internal pin
    dmac_b_request_direction_t   activation_request_source_select; ///< DMAC activation request source

    dmac_b_mode_select_t        dmac_mode;                         ///< DMAC Mode
    dmac_b_link_cfg_t const   * p_descriptor;                      ///< The address of the descriptor (DMA Link Mode only)
    dmac_b_continuous_setting_t continuous_setting;                ///< Next register operation settings
    uint16_t transfer_interval;                                    ///< DMA transfer interval
    dmac_b_channel_scheduling_t channel_scheduling;                ///< DMA channel scheduling

    /** Callback for transfer end interrupt. */
    void (* p_callback)(dmac_b_callback_args_t * cb_data);

    /** Placeholder for user data.  Passed to the user p_callback in ::transfer_callback_args_t. */
    void const * p_context;

    void * p_reg;                      ///< Register base address for specified unit
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
fsp_err_t R_DMAC_B_CallbackSet(transfer_ctrl_t * const        p_api_ctrl,
                               void (                       * p_callback)(dmac_b_callback_args_t *),
                               void const * const             p_context,
                               dmac_b_callback_args_t * const p_callback_memory);
fsp_err_t R_DMAC_B_LinkDescriptorSet(transfer_ctrl_t * const p_api_ctrl, dmac_b_link_cfg_t * p_descriptor);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup DMAC_B)
 **********************************************************************************************************************/
