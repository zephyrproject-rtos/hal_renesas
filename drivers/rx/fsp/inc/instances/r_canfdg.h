/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CANFDG_H
#define R_CANFDG_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include "bsp_api.h"
#include "r_canfdg_cfg.h"
#include "r_can_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup CANFDG
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define R_CANFDG_NUM_COMMON_FIFOS    (6U)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** CANFDG Status */
typedef enum e_canfdg_status
{
    CANFDG_STATUS_RESET_MODE    = 0x001, ///< Channel in Reset mode
    CANFDG_STATUS_HALT_MODE     = 0x002, ///< Channel in Halt mode
    CANFDG_STATUS_SLEEP_MODE    = 0x004, ///< Channel in Sleep mode
    CANFDG_STATUS_ERROR_PASSIVE = 0x008, ///< Channel in error-passive state
    CANFDG_STATUS_BUS_OFF       = 0x010, ///< Channel in bus-off state
    CANFDG_STATUS_TRANSMITTING  = 0x020, ///< Channel is transmitting
    CANFDG_STATUS_RECEIVING     = 0x040, ///< Channel is receiving
    CANFDG_STATUS_READY         = 0x080, ///< Channel is ready for communication
    CANFDG_STATUS_ESI           = 0x100, ///< At least one CAN-FD message was received with the ESI flag set
} canfdg_status_t;

/** CANFDG Error Code */
typedef enum e_canfdg_error
{
    CANFDG_ERROR_CHANNEL_BUS              = 0x00000001, ///< Bus Error
    CANFDG_ERROR_CHANNEL_WARNING          = 0x00000002, ///< Error Warning (TX/RX error count over 0x5F)
    CANFDG_ERROR_CHANNEL_PASSIVE          = 0x00000004, ///< Error Passive (TX/RX error count over 0x7F)
    CANFDG_ERROR_CHANNEL_BUS_OFF_ENTRY    = 0x00000008, ///< Bus-Off State Entry
    CANFDG_ERROR_CHANNEL_BUS_OFF_RECOVERY = 0x00000010, ///< Recovery from Bus-Off State
    CANFDG_ERROR_CHANNEL_OVERLOAD         = 0x00000020, ///< Overload
    CANFDG_ERROR_CHANNEL_BUS_LOCK         = 0x00000040, ///< Bus Locked
    CANFDG_ERROR_CHANNEL_ARBITRATION_LOSS = 0x00000080, ///< Arbitration Lost
    CANFDG_ERROR_CHANNEL_STUFF            = 0x00000100, ///< Stuff Error
    CANFDG_ERROR_CHANNEL_FORM             = 0x00000200, ///< Form Error
    CANFDG_ERROR_CHANNEL_ACK              = 0x00000400, ///< ACK Error
    CANFDG_ERROR_CHANNEL_CRC              = 0x00000800, ///< CRC Error
    CANFDG_ERROR_CHANNEL_BIT_RECESSIVE    = 0x00001000, ///< Bit Error (recessive) Error
    CANFDG_ERROR_CHANNEL_BIT_DOMINANT     = 0x00002000, ///< Bit Error (dominant) Error
    CANFDG_ERROR_CHANNEL_ACK_DELIMITER    = 0x00004000, ///< ACK Delimiter Error
    CANFDG_ERROR_GLOBAL_DLC               = 0x00010000, ///< DLC Error
    CANFDG_ERROR_GLOBAL_MESSAGE_LOST      = 0x00020000, ///< Message Lost
    CANFDG_ERROR_GLOBAL_PAYLOAD_OVERFLOW  = 0x00080000, ///< FD Payload Overflow
    CANFDG_ERROR_GLOBAL_TXQ_OVERWRITE     = 0x00100000, ///< TX Queue Message Overwrite
    CANFDG_ERROR_GLOBAL_TXQ_MESSAGE_LOST  = 0x00400000, ///< TX Queue Message Lost
    CANFDG_ERROR_GLOBAL_CH0_SCAN_FAIL     = 0x01000000, ///< Channel 0 RX Scan Failure
    CANFDG_ERROR_GLOBAL_CH1_SCAN_FAIL     = 0x02000000, ///< Channel 1 RX Scan Failure
    CANFDG_ERROR_GLOBAL_CH0_ECC           = 0x10000000, ///< Channel 0 ECC Error
    CANFDG_ERROR_GLOBAL_CH1_ECC           = 0x20000000, ///< Channel 1 ECC Error
} canfdg_error_t;

/** CANFDG Transmit Buffer (MB + CFIFO) */
typedef enum e_canfdg_tx_buffer
{
    CANFDG_TX_BUFFER_0             = 0,
    CANFDG_TX_BUFFER_1             = 1,
    CANFDG_TX_BUFFER_2             = 2,
    CANFDG_TX_BUFFER_3             = 3,
    CANFDG_TX_BUFFER_4             = 4,
    CANFDG_TX_BUFFER_5             = 5,
    CANFDG_TX_BUFFER_6             = 6,
    CANFDG_TX_BUFFER_7             = 7,
    CANFDG_TX_BUFFER_32            = 32,
    CANFDG_TX_BUFFER_33            = 33,
    CANFDG_TX_BUFFER_34            = 34,
    CANFDG_TX_BUFFER_35            = 35,
    CANFDG_TX_BUFFER_36            = 36,
    CANFDG_TX_BUFFER_37            = 37,
    CANFDG_TX_BUFFER_38            = 38,
    CANFDG_TX_BUFFER_39            = 39,
    CANFDG_TX_BUFFER_FIFO_COMMON_0 = 40,
    CANFDG_TX_BUFFER_FIFO_COMMON_1 = 41,
    CANFDG_TX_BUFFER_FIFO_COMMON_2 = 42,
} canfdg_tx_buffer_t;

/** CANFDG Transmit Message Buffer (TX MB) */
typedef enum e_canfdg_tx_mb
{
    CANFDG_TX_MB_0  = 0,
    CANFDG_TX_MB_1  = 1,
    CANFDG_TX_MB_2  = 2,
    CANFDG_TX_MB_3  = 3,
    CANFDG_TX_MB_4  = 4,
    CANFDG_TX_MB_5  = 5,
    CANFDG_TX_MB_6  = 6,
    CANFDG_TX_MB_7  = 7,
    CANFDG_TX_MB_32 = 32,
    CANFDG_TX_MB_33 = 33,
    CANFDG_TX_MB_34 = 34,
    CANFDG_TX_MB_35 = 35,
    CANFDG_TX_MB_36 = 36,
    CANFDG_TX_MB_37 = 37,
    CANFDG_TX_MB_38 = 38,
    CANFDG_TX_MB_39 = 39,
} canfdg_tx_mb_t;

/** CANFDG Receive Buffer (MB + FIFO + CFIFO) */
typedef enum e_canfdg_rx_buffer
{
    CANFDG_RX_BUFFER_MB_0          = 0,
    CANFDG_RX_BUFFER_MB_1          = 1,
    CANFDG_RX_BUFFER_MB_2          = 2,
    CANFDG_RX_BUFFER_MB_3          = 3,
    CANFDG_RX_BUFFER_MB_4          = 4,
    CANFDG_RX_BUFFER_MB_5          = 5,
    CANFDG_RX_BUFFER_MB_6          = 6,
    CANFDG_RX_BUFFER_MB_7          = 7,
    CANFDG_RX_BUFFER_MB_8          = 8,
    CANFDG_RX_BUFFER_MB_9          = 9,
    CANFDG_RX_BUFFER_MB_10         = 10,
    CANFDG_RX_BUFFER_MB_11         = 11,
    CANFDG_RX_BUFFER_MB_12         = 12,
    CANFDG_RX_BUFFER_MB_13         = 13,
    CANFDG_RX_BUFFER_MB_14         = 14,
    CANFDG_RX_BUFFER_MB_15         = 15,
    CANFDG_RX_BUFFER_MB_16         = 16,
    CANFDG_RX_BUFFER_MB_17         = 17,
    CANFDG_RX_BUFFER_MB_18         = 18,
    CANFDG_RX_BUFFER_MB_19         = 19,
    CANFDG_RX_BUFFER_MB_20         = 20,
    CANFDG_RX_BUFFER_MB_21         = 21,
    CANFDG_RX_BUFFER_MB_22         = 22,
    CANFDG_RX_BUFFER_MB_23         = 23,
    CANFDG_RX_BUFFER_MB_24         = 24,
    CANFDG_RX_BUFFER_MB_25         = 25,
    CANFDG_RX_BUFFER_MB_26         = 26,
    CANFDG_RX_BUFFER_MB_27         = 27,
    CANFDG_RX_BUFFER_MB_28         = 28,
    CANFDG_RX_BUFFER_MB_29         = 29,
    CANFDG_RX_BUFFER_MB_30         = 30,
    CANFDG_RX_BUFFER_MB_31         = 31,
    CANFDG_RX_BUFFER_FIFO_0        = 32,
    CANFDG_RX_BUFFER_FIFO_1        = 33,
    CANFDG_RX_BUFFER_FIFO_2        = 34,
    CANFDG_RX_BUFFER_FIFO_3        = 35,
    CANFDG_RX_BUFFER_FIFO_4        = 36,
    CANFDG_RX_BUFFER_FIFO_5        = 37,
    CANFDG_RX_BUFFER_FIFO_6        = 38,
    CANFDG_RX_BUFFER_FIFO_7        = 39,
    CANFDG_RX_BUFFER_FIFO_COMMON_0 = 40,
    CANFDG_RX_BUFFER_FIFO_COMMON_1 = 41,
    CANFDG_RX_BUFFER_FIFO_COMMON_2 = 42,
} canfdg_rx_buffer_t;

/** CANFD Receive Message Buffer (RX MB) */
typedef enum e_canfdg_rx_mb
{
    CANFDG_RX_MB_NONE = 0,
    CANFDG_RX_MB_0    = 0x80,
    CANFDG_RX_MB_1    = 0x80 + 1,
    CANFDG_RX_MB_2    = 0x80 + 2,
    CANFDG_RX_MB_3    = 0x80 + 3,
    CANFDG_RX_MB_4    = 0x80 + 4,
    CANFDG_RX_MB_5    = 0x80 + 5,
    CANFDG_RX_MB_6    = 0x80 + 6,
    CANFDG_RX_MB_7    = 0x80 + 7,
    CANFDG_RX_MB_8    = 0x80 + 8,
    CANFDG_RX_MB_9    = 0x80 + 9,
    CANFDG_RX_MB_10   = 0x80 + 10,
    CANFDG_RX_MB_11   = 0x80 + 11,
    CANFDG_RX_MB_12   = 0x80 + 12,
    CANFDG_RX_MB_13   = 0x80 + 13,
    CANFDG_RX_MB_14   = 0x80 + 14,
    CANFDG_RX_MB_15   = 0x80 + 15,
    CANFDG_RX_MB_16   = 0x80 + 16,
    CANFDG_RX_MB_17   = 0x80 + 17,
    CANFDG_RX_MB_18   = 0x80 + 18,
    CANFDG_RX_MB_19   = 0x80 + 19,
    CANFDG_RX_MB_20   = 0x80 + 20,
    CANFDG_RX_MB_21   = 0x80 + 21,
    CANFDG_RX_MB_22   = 0x80 + 22,
    CANFDG_RX_MB_23   = 0x80 + 23,
    CANFDG_RX_MB_24   = 0x80 + 24,
    CANFDG_RX_MB_25   = 0x80 + 25,
    CANFDG_RX_MB_26   = 0x80 + 26,
    CANFDG_RX_MB_27   = 0x80 + 27,
    CANFDG_RX_MB_28   = 0x80 + 28,
    CANFDG_RX_MB_29   = 0x80 + 29,
    CANFDG_RX_MB_30   = 0x80 + 30,
    CANFDG_RX_MB_31   = 0x80 + 31,
} canfdg_rx_mb_t;

/** CANFDG Receive FIFO (RX FIFO) */
typedef enum e_canfdg_rx_fifo
{
    CANFDG_RX_FIFO_0        = (1U),
    CANFDG_RX_FIFO_1        = (1U << 1),
    CANFDG_RX_FIFO_2        = (1U << 2),
    CANFDG_RX_FIFO_3        = (1U << 3),
    CANFDG_RX_FIFO_4        = (1U << 4),
    CANFDG_RX_FIFO_5        = (1U << 5),
    CANFDG_RX_FIFO_6        = (1U << 6),
    CANFDG_RX_FIFO_7        = (1U << 7),
    CANFDG_RX_FIFO_COMMON_0 = (1U << 8),
    CANFDG_RX_FIFO_COMMON_1 = (1U << 9),
    CANFDG_RX_FIFO_COMMON_2 = (1U << 10),
    CANFDG_RX_FIFO_COMMON_3 = (1U << 11),
    CANFDG_RX_FIFO_COMMON_4 = (1U << 12),
    CANFDG_RX_FIFO_COMMON_5 = (1U << 13),
} canfdg_rx_fifo_t;

/** CANFDG AFL Minimum DLC settings */
typedef enum e_canfdg_minimum_dlc
{
    CANFDG_MINIMUM_DLC_0 = 0,
    CANFDG_MINIMUM_DLC_1,
    CANFDG_MINIMUM_DLC_2,
    CANFDG_MINIMUM_DLC_3,
    CANFDG_MINIMUM_DLC_4,
    CANFDG_MINIMUM_DLC_5,
    CANFDG_MINIMUM_DLC_6,
    CANFDG_MINIMUM_DLC_7,
    CANFDG_MINIMUM_DLC_8,
    CANFDG_MINIMUM_DLC_12,
    CANFDG_MINIMUM_DLC_16,
    CANFDG_MINIMUM_DLC_20,
    CANFDG_MINIMUM_DLC_24,
    CANFDG_MINIMUM_DLC_32,
    CANFDG_MINIMUM_DLC_48,
    CANFDG_MINIMUM_DLC_64,
} canfdg_minimum_dlc_t;

/** CANFDG Frame Options */
typedef enum e_canfdg_frame_option
{
    CANFDG_FRAME_OPTION_ERROR = 0x01,  ///< Error state set (ESI).
    CANFDG_FRAME_OPTION_BRS   = 0x02,  ///< Bit Rate Switching (BRS) enabled.
    CANFDG_FRAME_OPTION_FD    = 0x04,  ///< Flexible Data frame (FDF).
    // CANFDG_FRAME_OPTION_ONESHOT = 0x80, ///< One-shot mode (no retries).
} canfdg_frame_options_t;

/* CAN Instance Control Block   */
typedef struct st_canfdg_instance_ctrl
{
    R_CANFDG_Type * p_reg;                      // Pointer to register base address

    /* Parameters to control CAN peripheral device */
    can_cfg_t const    * p_cfg;                 // Pointer to the configuration structure
    uint32_t             open;                  // Open status of channel.
    can_operation_mode_t operation_mode;        // Can operation mode.
    can_test_mode_t      test_mode;             // Can operation mode.
    void (* p_callback)(can_callback_args_t *); // Pointer to callback
    can_callback_args_t * p_callback_memory;    // Pointer to optional callback argument memory
    void                * p_context;            // Pointer to context to be passed into callback function
} canfdg_instance_ctrl_t;

/** AFL Entry (based on R_CANFDG_AFL_Type in r_canfdg_reg.h) */
typedef struct st_canfdg_afl_entry_t
{
    union
    {
        uint32_t id_u32;

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            can_id_mode_t    id_mode    : 1;  ///< ID mode (Standard or Extended)
            can_frame_type_t frame_type : 1;  ///< Frame type (Data or Remote)
            uint32_t                    : 1;
            uint32_t id                 : 29; ///< ID to match against
#else
            uint32_t id                 : 29; ///< ID to match against
            uint32_t                    : 1;
            can_frame_type_t frame_type : 1;  ///< Frame type (Data or Remote)
            can_id_mode_t    id_mode    : 1;  ///< ID mode (Standard or Extended)
#endif
        } id;
    } id_u;

    union
    {
        uint32_t mask_u32;

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t mask_id_mode    : 1;  ///< Only accept frames with the configured ID mode
            uint32_t mask_frame_type : 1;  ///< Only accept frames with the configured frame type
            uint32_t                 : 1;
            uint32_t mask_id         : 29; ///< ID Mask
#else
            uint32_t mask_id         : 29; ///< ID Mask
            uint32_t                 : 1;
            uint32_t mask_frame_type : 1;  ///< Only accept frames with the configured frame type
            uint32_t mask_id_mode    : 1;  ///< Only accept frames with the configured ID mode
#endif
        } mask;
    } mask_u;

    union
    {
        uint32_t destination_u32[2];

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                         : 16;
            canfdg_rx_mb_t rx_buffer         : 8; ///< RX Message Buffer to receive messages accepted by this rule
            uint32_t                         : 4;
            canfdg_minimum_dlc_t minimum_dlc : 4; ///< Minimum DLC value to accept (valid when DLC Check is enabled)
#else
            canfdg_minimum_dlc_t minimum_dlc : 4; ///< Minimum DLC value to accept (valid when DLC Check is enabled)
            uint32_t                         : 4;
            canfdg_rx_mb_t rx_buffer         : 8; ///< RX Message Buffer to receive messages accepted by this rule
            uint32_t                         : 16;
#endif
            canfdg_rx_fifo_t fifo_select_flags;   ///< RX FIFO(s) to receive messages accepted by this rule
        } destination;
    } destination_u;
} canfdg_afl_entry_t;

/** CANFDG Global Configuration */
typedef struct st_canfdg_global_cfg
{
    uint32_t global_interrupts;                             ///< Global control options (GCR register setting)
    uint32_t global_config;                                 ///< Global configuration options (GCFG register setting)
    uint32_t rx_fifo_config[8];                             ///< RX FIFO configuration (RFCRn register settings)
    uint32_t rx_mb_config;                                  ///< Number and size of RX Message Buffers (RMCR register setting)
    uint8_t  global_err_ipl;                                ///< Global Error interrupt priority
    uint8_t  rx_fifo_ipl;                                   ///< RX FIFO interrupt priority
    uint32_t common_fifo_config[R_CANFDG_NUM_COMMON_FIFOS]; ///< Common FIFO configurations
} canfdg_global_cfg_t;

/** CANFD Extended Configuration */
typedef struct st_canfdg_extended_cfg
{
    canfdg_afl_entry_t const * p_afl;          ///< AFL rules list
    uint64_t               txmb_txi_enable;    ///< Array of TX Message Buffer enable bits
    uint32_t               error_interrupts;   ///< Error interrupt enable bits
    can_bit_timing_cfg_t * p_data_timing;      ///< FD Data Rate (when bitrate switching is used)
    uint8_t                delay_compensation; ///< FD Transceiver Delay Compensation (enable or disable)
    canfdg_global_cfg_t  * p_global_cfg;       ///< Global configuration (global error callback channel only)
} canfdg_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const can_api_t g_canfd_on_canfdg;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_CANFDG_Open(can_ctrl_t * const p_api_ctrl, can_cfg_t const * const p_cfg);
fsp_err_t R_CANFDG_Close(can_ctrl_t * const p_api_ctrl);
fsp_err_t R_CANFDG_Write(can_ctrl_t * const p_api_ctrl, uint32_t const buffer, can_frame_t * const p_frame);
fsp_err_t R_CANFDG_Read(can_ctrl_t * const p_api_ctrl, uint32_t const buffer, can_frame_t * const p_frame);
fsp_err_t R_CANFDG_ModeTransition(can_ctrl_t * const   p_api_ctrl,
                                  can_operation_mode_t operation_mode,
                                  can_test_mode_t      test_mode);
fsp_err_t R_CANFDG_InfoGet(can_ctrl_t * const p_api_ctrl, can_info_t * const p_info);
fsp_err_t R_CANFDG_CallbackSet(can_ctrl_t * const          p_api_ctrl,
                               void (                    * p_callback)(can_callback_args_t *),
                               void * const                p_context,
                               can_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end defgroup CAN)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
