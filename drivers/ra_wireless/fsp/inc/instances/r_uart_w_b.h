/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_UART_W_B_H
#define R_UART_W_B_H

/*******************************************************************************************************************//**
 * @addtogroup UART_W_B
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_uart_api.h"
#include "r_uart_w_b_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Offset to make the UART HW channels 0-based for the r_uart_w_b driver. */
#if (BSP_FEATURE_UART_VALID_CHANNEL_MASK & 0x1)
 #define UART_W_B_CHANNEL_OFFSET      0
#elif (BSP_FEATURE_UART_VALID_CHANNEL_MASK & 0x2)
 #define UART_W_B_CHANNEL_OFFSET      1
#endif

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** UART instance control block. */
typedef struct st_uart_w_b_instance_ctrl
{
    /* Parameters to control UART peripheral device */
    uint8_t  fifo_depth;               // FIFO depth of the UART channel
    uint8_t  data_bytes         : 2;   // 1 byte for 7 or 8 bit data, 2 bytes for 9 bit data
    uint8_t  bitrate_modulation : 1;   // 1 if bit rate modulation is enabled, 0 otherwise
    uint32_t open;                     // Used to determine if the channel is configured

    /* Source buffer pointer used to fill hardware FIFO from transmit ISR. */
    uint8_t const * p_tx_src;

    /* Size of source buffer pointer used to fill hardware FIFO from transmit ISR. */
    uint32_t tx_src_bytes;

    /* Destination buffer pointer used for receiving data. */
    uint8_t const * p_rx_dest;

    /* Size of destination buffer pointer used for receiving data. */
    uint32_t rx_dest_bytes;

    /* Pointer to the configuration block. */
    uart_cfg_t const * p_cfg;

    /* Base register for this channel */
    UART2_Type * p_reg;

    void (* p_callback)(uart_callback_args_t *); // Pointer to callback that is called when a uart_event_t occurs.
    uart_callback_args_t * p_callback_memory;    // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.

    /* Pointer to context to be passed into callback function */
    void * p_context;
} uart_w_b_instance_ctrl_t;

/** Receive FIFO trigger configuration. */
typedef enum e_uart_w_b_rx_fifo_data_avl_trigger
{
    UART_W_B_RX_FIFO_1BYTE_TRIGGER           = 0x0, ///< 1 byte FIFO level for rx interrupt
    UART_W_B_RX_FIFO_QUARTERLY_FULL_TRIGGER  = 0x1, ///< 1/4 FULL FIFO level for rx interrupt
    UART_W_B_RX_FIFO_HALF_FULL_TRIGGER       = 0x2, ///< 1/2 FULL FIFO level for rx interrupt
    UART_W_B_RX_FIFO_2LESS_THAN_FULL_TRIGGER = 0x3, ///< 2 bytes less than FULL FIFO level for rx interrupt
} uart_w_b_rx_fifo_trigger_t;

/** Transmit FIFO trigger configuration. */
typedef enum e_uart_w_b_tx_fifo_empty_trigger
{
    UART_W_B_TX_FIFO_EMPTY_TRIGGER          = 0x0, ///< 0 bytes FIFO level for tx interrupt
    UART_W_B_TX_FIFO_2CHAR_TRIGGER          = 0x1, ///< 2 bytes FIFO level for tx interrupt
    UART_W_B_TX_FIFO_QUARTERLY_FULL_TRIGGER = 0x2, ///< 1/4 FULL FIFO level for tx interrupt
    UART_W_B_TX_FIFO_HALF_FULL_TRIGGER      = 0x3, ///< 1/2 FULL FIFO level for tx interrupt
} uart_w_b_tx_fifo_trigger_t;

/** Interrupt sources for generic isr. */
typedef enum e_uart_w_b_interrupt_source
{
    UART_W_B_INT_MODEM_STAT         = 0,  ///< Modem status interrupt
    UART_W_B_INT_NO_INT_PEND        = 1,  ///< No interrupt pending
    UART_W_B_INT_THR_EMPTY          = 2,  ///< Transmit holding register empty interrupt
    UART_W_B_INT_RECEIVED_AVAILABLE = 4,  ///< Receiver data available interrupt
    UART_W_B_INT_RECEIVE_LINE_STAT  = 6,  ///< Error interrupt
    UART_W_B_INT_BUSY_DETECTED      = 7,  ///< Busy interrupt
    UART_W_B_INT_TIMEOUT            = 12, ///< Rx timeout interrupt
} uart_w_b_interrupt_source_t;

typedef enum e_uart_w_b_clk_sel_div
{
    UART_W_B_DIVN = 0,                 ///< Use DIVN as clock source
    UART_W_B_DIV1 = 1,                 ///< Use DIV1 as clock source
} uart_w_b_clk_sel_div_t;

/** Register settings to achieve a desired baud rate and modulation duty. */
typedef struct st_uart_w_b_baud_setting
{
    uart_w_b_clk_sel_div_t uart_clk_sel_div : 1; ///< Divider setting
    uint8_t                ier_dlh          : 8; ///< High byte of baud rate
    uint8_t                thr_dll          : 8; ///< Low byte of baud rate
    uint8_t                dlf              : 8; ///< Fraction byte of baud rate
} uart_w_b_baud_setting_t;

/** UART device Configuration */
typedef struct st_uart_w_b_extended_cfg
{
    uart_w_b_baud_setting_t  * p_baud_setting;  ///< Register settings for a desired baud rate.
    uart_w_b_rx_fifo_trigger_t rx_fifo_trigger; ///< Receive FIFO data available trigger level, unused if channel has no FIFO or if DTC is used.
    uart_w_b_tx_fifo_trigger_t tx_fifo_trigger; ///< Transmit FIFO empty trigger level, unused if channel has no FIFO or if DTC is used.
    bool      flow_control;                     ///< CTS/RTS flow controlled enabled
    uint8_t   gen_ipl;                          ///< Generic interrupt priority
    IRQn_Type gen_irq;                          ///< Generic interrupt IRQ number
} uart_w_b_extended_cfg_t;

/**
 * \brief Baud rates dividers
 *
 * The defined values comprise the values of 3 registers: DLH, DLL, DLF.
 * The encoding of the values for each register is:
 *
 * +--------+--------+--------+--------+
 * | unused |   DLH  |   DLL  |   DLF  |
 * +--------+--------+--------+--------+
 *
 * \note Baud rate values higher than 2000000 can only be selected when clock source is either 64MHz or 128 MHz is used as system clock!
 *       Otherwise, a warning-assertion will be triggered!
 *
 * \note In the case of high baud rates (the ones greater than 2000000), the enumerated values do not represent the actual
 *       values that are applied to the divider registers (DLH, DLL, DLF). They are internally translated to a different
 *       set of divider values based on the type of high speed clock that is used.
 *
 */
typedef enum e_uart_w_b_baud_rate
{
    UART_W_B_BAUDRATE_6000000 = 0x00000005, /**< Requires either PLL128M or RCHS@64MHz! */
    UART_W_B_BAUDRATE_3000000 = 0x0000000B, /**< Requires either PLL128M or RCHS@64MHz! */
    UART_W_B_BAUDRATE_2000000 = 0x00000100,
    UART_W_B_BAUDRATE_1000000 = 0x00000200,
    UART_W_B_BAUDRATE_921600  = 0x00000203,
    UART_W_B_BAUDRATE_500000  = 0x00000400,
    UART_W_B_BAUDRATE_460800  = 0x00000405,
    UART_W_B_BAUDRATE_256000  = 0x0000070D,
    UART_W_B_BAUDRATE_230400  = 0x0000080b,
    UART_W_B_BAUDRATE_115200  = 0x00001106,
    UART_W_B_BAUDRATE_57600   = 0x0000220c,
    UART_W_B_BAUDRATE_38400   = 0x00003401,
    UART_W_B_BAUDRATE_28800   = 0x00004507,
    UART_W_B_BAUDRATE_19200   = 0x00006803,
    UART_W_B_BAUDRATE_14400   = 0x00008a0e,
    UART_W_B_BAUDRATE_9600    = 0x0000d005,
    UART_W_B_BAUDRATE_4800    = 0x0001a00b,
    UART_W_B_BAUDRATE_2400    = 0x00034105,
    UART_W_B_BAUDRATE_1200    = 0x0006820B,
    UART_W_B_BAUD_INVALID     = 0xFFFFFFFF,
} uart_w_b_baud_rate_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const uart_api_t g_uart_on_uart_w_b;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_Open(uart_ctrl_t * const p_api_ctrl, uart_cfg_t const * const p_cfg);
fsp_err_t R_UART_W_B_Read(uart_ctrl_t * const p_api_ctrl, uint8_t * const p_dest, uint32_t const bytes);
fsp_err_t R_UART_W_B_Write(uart_ctrl_t * const p_api_ctrl, uint8_t const * const p_src, uint32_t const bytes);
fsp_err_t R_UART_W_B_BaudSet(uart_ctrl_t * const p_api_ctrl, void const * const p_baud_setting);
fsp_err_t R_UART_W_B_InfoGet(uart_ctrl_t * const p_api_ctrl, uart_info_t * const p_info);
fsp_err_t R_UART_W_B_Close(uart_ctrl_t * const p_api_ctrl);
fsp_err_t R_UART_W_B_Abort(uart_ctrl_t * const p_api_ctrl, uart_dir_t communication_to_abort);
fsp_err_t R_UART_W_B_BaudCalculate(uart_w_b_baud_rate_t baudrate, uart_w_b_baud_setting_t * const p_baud_setting);
fsp_err_t R_UART_W_B_CallbackSet(uart_ctrl_t * const          p_api_ctrl,
                                 void (                     * p_callback)(uart_callback_args_t *),
                                 void * const                 p_context,
                                 uart_callback_args_t * const p_callback_memory);
fsp_err_t R_UART_W_B_ReadStop(uart_ctrl_t * const p_api_ctrl, uint32_t * remaining_bytes);

fsp_err_t R_UART_W_B_TxReady(uart_ctrl_t * const p_api_ctrl, bool * tx_is_ready);

/*******************************************************************************************************************//**
 * @} (end addtogroup UART_W_B)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
