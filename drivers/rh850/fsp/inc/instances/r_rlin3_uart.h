/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RLIN3_UART_H
#define R_RLIN3_UART_H

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup RLIN3_UART
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_uart_api.h"
#include "r_rlin3_uart_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Noise cancellation configuration. */
typedef enum e_rlin3_uart_noise_cancellation     /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    RLIN3_UART_NOISE_CANCELLATION_DISABLE = 0x1, ///< Disable noise cancellation
    RLIN3_UART_NOISE_CANCELLATION_ENABLE  = 0x0  ///< Enable noise cancellation
} rlin3_uart_noise_cancellation_t;

/** Transmission Interrupt Generation Timing Select */
typedef enum e_uart_timing_select                /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    UART_TRANSMISSION = 0U,                      ///< The transmission interrupt is generated at the start of transmission
    UART_COMPLETION   = 1U                       ///< The transmission interrupt is generated at the completion of transmission
} uart_timing_select_t;

/** UART Input Polarity Switch */
typedef enum e_uart_invert_input                 /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    UART_NORMAL_INPUT = 0U,                      ///< Reception data normal output
    UART_INVERT_INPUT = 1U                       ///< Reception data with inverted output
} uart_invert_input_t;

/** UART Output Polarity Switch */
typedef enum e_uart_invert_output                /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    UART_NORMAL_OUTPUT = 0U,                     ///< Transmission data normal output
    UART_INVERT_OUTPUT = 1U                      ///< Transmission data with inverted output
} uart_invert_output_t;

/** UART Transfer Format Order Select */
typedef enum e_uart_order                        /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    UART_LSB_FIRST = 0U,                         ///< LSB First
    UART_MSB_FIRST = 1U                          ///< MSB First
} uart_order_t;

/** UART instance control block. */
typedef struct st_rlin3_uart_instance_ctrl       /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    /* Parameters to control UART peripheral device */
    /* PRQA S 0635 ++ # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC4 & DP_MSR_R-1.2_UC2 */
    uint8_t data_bytes : 2;                      ///< Set to 2 when UART 9bit transmit

    /* PRQA S 0635 -- */
    uint32_t      open;                          ///< Used to determine if the channel is configured
    volatile bool rx_suspended;                  ///< Busy flag

    /* Source buffer pointer used to fill transmit ISR. */
    uint8_t const * p_tx_src;

    /* Size of source buffer pointer used to fill transmit ISR. */
    uint32_t tx_src_bytes;

    /* Destination buffer pointer used for receiving data. */
    uint8_t * p_rx_dest;

    /* Size of destination buffer pointer used for receiving data. */
    uint32_t rx_dest_bytes;

    /* Pointer to the configuration block. */
    uart_cfg_t const * p_cfg;

    /* Base register for this channel */
    R_RLN30_Type * p_reg;

    void (* p_callback)(uart_callback_args_t *); /* PRQA S 1336 # DP_MSR_R-8.2_UC1 */ // Pointer to callback that is called when a uart_event_t occurs.
    uart_callback_args_t * p_callback_memory;                                         ///< Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.

    /* Pointer to context to be passed into callback function */
    void * p_context;
} rlin3_uart_instance_ctrl_t;

/** Register settings to acheive a desired baud rate */
typedef struct st_baud_setting                                      /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    /* PRQA S 0635 ++ # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC4 & DP_MSR_R-1.2_UC2 */
    uint8_t bit_sampling    : 4;                                    ///< Set value (5-15) for (6-16) bit sampling
    uint8_t prescaler_clock : 3;                                    ///< Prescaler clock select

    /* PRQA S 0635 -- */
    uint16_t prescaler;                                             ///< UART Baud Rate Prescaler
    uint32_t baudrate;                                              ///< UART Baud Rate
} baud_setting_t;

/** Baud Rate Calculate Enable */
typedef enum e_rlin3_uart_baud_rate_calculation                     /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    RLIN3_UART_BAUD_RATE_CALCULATION_ENABLE  = 0x1,                 ///< Baud rate calculate enable.
    RLIN3_UART_BAUD_RATE_CALCULATION_DISABLE = 0x0                  ///< Baud rate calculate disable.
} rlin3_uart_baud_rate_calculation_t;

/** Expansion Bit Comparison Disable */
typedef enum e_rlin3_uart_expansion_bit_comparison                  /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    RLIN3_UART_EXPANSION_BIT_COMPARISON_DISABLE = 0x1,              ///< Disables expansion bit comparison.
    RLIN3_UART_EXPANSION_BIT_COMPARISON_ENABLE  = 0x0               ///< Enables expansion bit comparison.
} rlin3_uart_expansion_bit_comparison_t;

/** Expansion Bit Comparison Disable */
typedef enum e_rlin3_uart_expansion_enable                          /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    RLIN3_UART_EXPANSION_BIT_DISABLE = 0x0,                         ///< Disables expansion bit operation.
    RLIN3_UART_EXPANSION_BIT_ENABLE  = 0x1                          ///< Enables expansion bit operation.
} rlin3_uart_expansion_bit_enable_t;

/** UART on RLIN3 device Configuration */
typedef struct st_rlin3_uart_extended_cfg                           /* PRQA S 1536 # DP_MSR_R-2.4_UC1 */
{
    uart_dir_t           operation_enable;                          ///< TX, RX only or both RX_TX
    uart_invert_input_t  invert_input;                              ///< Invert input at RX pin
    uart_invert_output_t invert_output;                             ///< Invert output at TX pin
    uart_order_t         transfer_order;                            ///< LSB or MSB
    uint8_t              tx_buffer;                                 ///< Buffer transmission if tx_buffer >0

    /* PRQA S 0635 ++ # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC4 & DP_MSR_R-1.2_UC2 */
    uint8_t enb_bit_err      : 1;                                   ///< Bit error detection enable
    uint8_t enb_overrun_err  : 1;                                   ///< Overrun error detection enble
    uint8_t enb_frame_err    : 1;                                   ///< Framing error detection enable
    uint8_t inter_byte_space : 2;                                   ///< Width of the space between the UART frames in buffer transmission

    /* PRQA S 0635 -- */
    rlin3_uart_noise_cancellation_t    noise_cancel;                ///< Noise cancellation setting
    baud_setting_t                   * p_baud_setting;              ///< Register settings for a desired baud rate.
    rlin3_uart_baud_rate_calculation_t baud_calculate;              ///< Baud rate calculate enable
    uint8_t baudrate_max_err_percent;                               ///< Baud rate max erorr
    rlin3_uart_expansion_bit_comparison_t expansion_bit_comparison; ///< Expansion bit comparison setting
    rlin3_uart_expansion_bit_enable_t     expansion_bit_enable;     ///< Expansion bit enable setting
    uart_timing_select_t timing_select;                             ///< Select a timing select corresponding to the channel number of the hardware.
#if (BSP_FEATURE_DEVICE_HAS_INTSEL_IRQ)
    bsp_intsel_t intsel_irq_cfg;                                    ///< Interrupt source for UART
#endif
} rlin3_uart_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const uart_api_t g_uart_on_rlin3;

/** @endcond */

fsp_err_t R_RLIN3_UART_Open(uart_ctrl_t * const p_api_ctrl, uart_cfg_t const * const p_cfg);
fsp_err_t R_RLIN3_UART_Close(uart_ctrl_t * const p_api_ctrl);
fsp_err_t R_RLIN3_UART_Read(uart_ctrl_t * const p_api_ctrl, uint8_t * const p_dest, uint32_t const bytes);
fsp_err_t R_RLIN3_UART_Write(uart_ctrl_t * const p_api_ctrl, uint8_t const * const p_src, uint32_t const bytes);
fsp_err_t R_RLIN3_UART_BaudSet(uart_ctrl_t * const p_api_ctrl, void const * const p_baud_setting);   /* PRQA S 1710 # DP_MSR_R-4.5_UC1 */
fsp_err_t R_RLIN3_UART_InfoGet(uart_ctrl_t * const p_api_ctrl, uart_info_t * const p_info);
fsp_err_t R_RLIN3_UART_Abort(uart_ctrl_t * const p_api_ctrl, uart_dir_t communication_to_abort);
fsp_err_t R_RLIN3_UART_CallbackSet(uart_ctrl_t * const          p_api_ctrl,
                                   void (                     * p_callback)(uart_callback_args_t *), /* PRQA S 1336 # DP_MSR_R-8.2_UC1 */
                                   void                       * p_context,
                                   uart_callback_args_t * const p_callback_memory);
fsp_err_t R_RLIN3_UART_ReadStop(uart_ctrl_t * const p_api_ctrl, uint32_t * remaining_bytes);
fsp_err_t R_RLIN3_UART_ReceiveSuspend(uart_ctrl_t * const p_api_ctrl);
fsp_err_t R_RLIN3_UART_ReceiveResume(uart_ctrl_t * const p_api_ctrl);

/*******************************************************************************************************************//**
 * @} (end addtogroup RLIN3_UART)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /*R_RLIN3_UART_H*/
