/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SCIF_UART_H
#define R_SCIF_UART_H

/*******************************************************************************************************************//**
 * @addtogroup SCIF_UART
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_uart_api.h"
#include "r_scif_uart_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define SCIF_UART_INVALID_16BIT_PARAM    (0xFFFFU)
#define SCIF_UART_INVALID_8BIT_PARAM     (0xFFU)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Enumeration for SCIF clock source */
typedef enum e_scif_clk_src
{
    SCIF_UART_CLOCK_INT,                      ///< Use internal clock for baud generation
    SCIF_UART_CLOCK_INT_WITH_BAUDRATE_OUTPUT, ///< Use internal clock for baud generation and output on SCK
    SCIF_UART_CLOCK_EXT8X,                    ///< Use external clock 8x baud rate
    SCIF_UART_CLOCK_EXT16X                    ///< Use external clock 16x baud rate
} scif_clk_src_t;

/** UART communication mode definition */
typedef enum e_scif_uart_mode
{
    SCIF_UART_MODE_RS232,              ///< Enables RS232 communication mode
    SCIF_UART_MODE_RS485_HD,           ///< Enables RS485 half duplex communication mode
    SCIF_UART_MODE_RS485_FD,           ///< Enables RS485 full duplex communication mode
} scif_uart_mode_t;

/** UART automatic flow control definition */
typedef enum e_scif_uart_flow_control
{
    SCIF_UART_FLOW_CONTROL_NONE,       ///< Disables flow control
    SCIF_UART_FLOW_CONTROL_AUTO,       ///< Enables automatic RTS/CTS flow control
} scif_uart_flow_control_t;

/** Noise cancellation configuration. */
typedef enum e_scif_uart_noise_cancellation
{
    SCIF_UART_NOISE_CANCELLATION_DISABLE, ///< Disable noise cancellation
    SCIF_UART_NOISE_CANCELLATION_ENABLE,  ///< Enable noise cancellation
} scif_uart_noise_cancellation_t;

/** RS-485 Enable/Disable. */
typedef enum e_scif_uart_rs485_enable
{
    SCIF_UART_RS485_DISABLE = 0,        ///< RS-485 disabled.
    SCIF_UART_RS485_ENABLE  = 1,        ///< RS-485 enabled.
} scif_uart_rs485_enable_t;

/** The polarity of the RS-485 DE signal. */
typedef enum e_scif_uart_rs485_de_polarity
{
    SCIF_UART_RS485_DE_POLARITY_HIGH = 0, ///< The DE signal is high when a write transfer is in progress.
    SCIF_UART_RS485_DE_POLARITY_LOW  = 1, ///< The DE signal is low when a write transfer is in progress.
} scif_uart_rs485_de_polarity_t;

/** Receive FIFO trigger configuration. */
typedef enum e_scif_uart_rx_fifo_trigger
{
    SCIF_UART_RX_FIFO_TRIGGER_ONE,     ///< Interrupt at least one byte is in FIFO
    SCIF_UART_RX_FIFO_TRIGGER_QUARTER, ///< Interrupt at least quarter of FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_HALF,    ///< Interrupt at least half of FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_MAX,     ///< Interrupt at almost full in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_1,       ///< Interrupt at least 1 byte is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_2,       ///< Interrupt at least 2 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_3,       ///< Interrupt at least 3 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_4,       ///< Interrupt at least 4 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_5,       ///< Interrupt at least 5 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_6,       ///< Interrupt at least 6 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_7,       ///< Interrupt at least 7 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_8,       ///< Interrupt at least 8 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_9,       ///< Interrupt at least 9 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_10,      ///< Interrupt at least 10 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_11,      ///< Interrupt at least 11 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_12,      ///< Interrupt at least 12 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_13,      ///< Interrupt at least 13 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_14,      ///< Interrupt at least 14 bytes is in FIFO or 15ETU past from last receive
    SCIF_UART_RX_FIFO_TRIGGER_15,      ///< Interrupt at least 15 bytes is in FIFO or 15ETU past from last receive
} scif_uart_rx_fifo_trigger_t;

/** RTS trigger level. */
typedef enum e_scif_uart_rts_trigger
{
    SCIF_UART_RTS_TRIGGER_1,           ///< RTS trigger level = 1
    SCIF_UART_RTS_TRIGGER_4,           ///< RTS trigger level = 4
    SCIF_UART_RTS_TRIGGER_6,           ///< RTS trigger level = 6
    SCIF_UART_RTS_TRIGGER_8,           ///< RTS trigger level = 8
    SCIF_UART_RTS_TRIGGER_10,          ///< RTS trigger level = 10
    SCIF_UART_RTS_TRIGGER_12,          ///< RTS trigger level = 12
    SCIF_UART_RTS_TRIGGER_14,          ///< RTS trigger level = 14
    SCIF_UART_RTS_TRIGGER_15,          ///< RTS trigger level = 15
    SCIF_UART_RTS_TRIGGER_DISABLE,     ///< Disable RTS trigger
} scif_uart_rts_trigger_t;

/** UART instance control block. */
typedef struct st_scif_uart_instance_ctrl
{
    /* Parameters to control UART peripheral device */
    uint32_t open;                     // Used to determine if the channel is configured

    bsp_io_port_pin_t driver_enable_pin;

    /* Source buffer pointer used to fill hardware FIFO from transmit ISR. */
    uint8_t const * p_tx_src;

    /* Size of source buffer pointer used to fill hardware FIFO from transmit ISR. */
    uint32_t tx_src_bytes;

    /* Destination buffer pointer used for receiving data. */
    uint8_t * p_rx_dest;

    /* Size of destination buffer pointer used for receiving data. */
    uint32_t rx_dest_bytes;

    /* Pointer to the configuration block. */
    uart_cfg_t const * p_cfg;

    /* Base register for this channel */
    R_SCIFA0_Type * p_reg;

    /* Backup SPTR value for writing */
    uint16_t sptr;

    void (* p_callback)(uart_callback_args_t * p_arg); // Pointer to callback
    uart_callback_args_t * p_callback_memory;          // Pointer to pre-allocated callback argument

    /* Pointer to context to be passed into callback function */
    void const * p_context;
} scif_uart_instance_ctrl_t;

/** Register settings to achieve a desired baud rate and modulation duty. */
typedef struct st_scif_baud_setting
{
    struct
    {
        uint8_t abcs : 1;              ///< Asynchronous Mode Base Clock Select
        uint8_t brme : 1;              ///< Bit Rate Modulation Enable
        uint8_t bgdm : 1;              ///< Baud Rate Generator Double-Speed Mode Select
        uint8_t cks  : 2;              ///< CKS  value to get divisor (CKS = N)
    }       semr_baudrate_bits_b;
    uint8_t brr;                       ///< Bit Rate Register setting
    uint8_t mddr;                      ///< Modulation Duty Register setting
} scif_baud_setting_t;

/** Configuration settings for controlling the DE signal for RS-485. */
typedef struct st_scif_uart_rs485_setting
{
    scif_uart_rs485_enable_t      enable;         ///< Enable the DE signal.
    scif_uart_rs485_de_polarity_t polarity;       ///< DE signal polarity.
    bsp_io_port_pin_t            de_control_pin; ///< UART Driver Enable pin.
} scif_uart_rs485_setting_t;

/** UART on SCIF device Configuration */
typedef struct st_scif_uart_extended_cfg
{
    uint8_t                        bri_ipl;       ///< Break interrupt priority
    IRQn_Type                      bri_irq;       ///< Break interrupt IRQ number
    scif_clk_src_t                 clock;         ///< The source clock for the baud-rate generator.
    scif_uart_noise_cancellation_t noise_cancel;  ///< Noise cancellation setting

    scif_baud_setting_t * p_baud_setting;         ///< Register settings for a desired baud rate.

    scif_uart_rx_fifo_trigger_t rx_fifo_trigger;  ///< Receive FIFO trigger level.
    scif_uart_rts_trigger_t     rts_fifo_trigger; ///< RTS trigger level.

    scif_uart_mode_t         uart_mode;           ///< UART communication mode selection
    scif_uart_flow_control_t flow_control;        ///< CTS/RTS function
    scif_uart_rs485_setting_t rs485_setting;       ///< RS-485 settings.
} scif_uart_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const uart_api_t g_uart_on_scif;

/** @endcond */

fsp_err_t R_SCIF_UART_Open(uart_ctrl_t * const p_api_ctrl, uart_cfg_t const * const p_cfg);
fsp_err_t R_SCIF_UART_Read(uart_ctrl_t * const p_api_ctrl, uint8_t * const p_dest, uint32_t const bytes);
fsp_err_t R_SCIF_UART_Write(uart_ctrl_t * const p_api_ctrl, uint8_t const * const p_src, uint32_t const bytes);
fsp_err_t R_SCIF_UART_BaudSet(uart_ctrl_t * const p_api_ctrl, void const * const p_baud_setting);
fsp_err_t R_SCIF_UART_InfoGet(uart_ctrl_t * const p_api_ctrl, uart_info_t * const p_info);
fsp_err_t R_SCIF_UART_Close(uart_ctrl_t * const p_api_ctrl);
fsp_err_t R_SCIF_UART_Abort(uart_ctrl_t * const p_api_ctrl, uart_dir_t communication_to_abort);
fsp_err_t R_SCIF_UART_BaudCalculate(uart_ctrl_t * const         p_api_ctrl,
                                    uint32_t                    baudrate,
                                    bool                        bitrate_modulation,
                                    uint32_t                    baud_rate_error_x_1000,
                                    scif_baud_setting_t * const p_baud_setting);
fsp_err_t R_SCIF_UART_CallbackSet(uart_ctrl_t * const          p_api_ctrl,
                                  void (                     * p_callback)(uart_callback_args_t * p_arg),
                                  void const * const           p_context,
                                  uart_callback_args_t * const p_callback_memory);
fsp_err_t R_SCIF_UART_ReadStop(uart_ctrl_t * const p_api_ctrl, uint32_t * remaining_bytes);

/*******************************************************************************************************************//**
 * @} (end addtogroup SCIF_UART)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* R_SCIF_UART_H */
