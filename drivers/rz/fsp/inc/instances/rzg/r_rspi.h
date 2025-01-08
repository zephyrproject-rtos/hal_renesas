/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RSPI_H
#define R_RSPI_H

/*******************************************************************************************************************//**
 * @addtogroup RSPI
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_spi_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/*************************************************************************************************
 * Type defines for the RSPI interface API
 *************************************************************************************************/

/** Slave Select Polarity. */
typedef enum e_rspi_ssl_polarity
{
    RSPI_SSLP_LOW,                     ///< SSLP signal polarity active low
    RSPI_SSLP_HIGH                     ///< SSLP signal polarity active high
} rspi_ssl_polarity_t;

/** MOSI Idle Behavior. */
typedef enum e_rspi_mosi_idle_value_fixing
{
    RSPI_MOSI_IDLE_VALUE_FIXING_DISABLE, ///< MOSI output value=value set in MOIFV bit
    RSPI_MOSI_IDLE_VALUE_FIXING_LOW,     ///< MOSIn level low during MOSI idling
    RSPI_MOSI_IDLE_VALUE_FIXING_HIGH     ///< MOSIn level high during MOSI idling
} rspi_mosi_idle_value_fixing_t;

/** SSL Signal Level Keeping Enable/Disable. */
typedef enum e_rspi_ssl_level_keep
{
    RSPI_SSL_LEVEL_KEEP_DISABLE,       ///< Disable SSL Level Keep Mode
    RSPI_SSL_LEVEL_KEEP_ENABLE         ///< Enable SSL Level Keep Mode
} rspi_ssl_level_keep_t;

/** Delay count for SPI delay settings. */
typedef enum e_rspi_delay_count
{
    RSPI_DELAY_COUNT_1,                ///< Set RSPCK delay count to 1 RSPCK
    RSPI_DELAY_COUNT_2,                ///< Set RSPCK delay count to 2 RSPCK
    RSPI_DELAY_COUNT_3,                ///< Set RSPCK delay count to 3 RSPCK
    RSPI_DELAY_COUNT_4,                ///< Set RSPCK delay count to 4 RSPCK
    RSPI_DELAY_COUNT_5,                ///< Set RSPCK delay count to 5 RSPCK
    RSPI_DELAY_COUNT_6,                ///< Set RSPCK delay count to 6 RSPCK
    RSPI_DELAY_COUNT_7,                ///< Set RSPCK delay count to 7 RSPCK
    RSPI_DELAY_COUNT_8                 ///< Set RSPCK delay count to 8 RSPCK
} rspi_delay_count_t;

/** Transmitter FIFO trigger level. */
typedef enum
{
    RSPI_TX_TRIGGER_7,                 ///< Trigger when 7 or less bytes in TX FIFO
    RSPI_TX_TRIGGER_6,                 ///< Trigger when 6 or less bytes in TX FIFO
    RSPI_TX_TRIGGER_4,                 ///< Trigger when 4 or less bytes in TX FIFO
    RSPI_TX_TRIGGER_0,                 ///< Trigger when TX FIFO is empty
} rspi_tx_trigger_level_t;

/** Receiver FIFO trigger level. */
typedef enum
{
    RSPI_RX_TRIGGER_1,                 ///< Trigger when 1 or more bytes in RX FIFO
    RSPI_RX_TRIGGER_2,                 ///< Trigger when 2 or more bytes in RX FIFO
    RSPI_RX_TRIGGER_4,                 ///< Trigger when 4 or more bytes in RX FIFO
    RSPI_RX_TRIGGER_8,                 ///< Trigger when 8 or more bytes in RX FIFO
    RSPI_RX_TRIGGER_16,                ///< Trigger when 16 or more bytes in RX FIFO
    RSPI_RX_TRIGGER_24,                ///< Trigger when 24 or more bytes in RX FIFO
    RSPI_RX_TRIGGER_32,                ///< Trigger when 32 or more bytes in RX FIFO
    RSPI_RX_TRIGGER_5,                 ///< Trigger when 5 or more bytes in RX FIFO
} rspi_rx_trigger_level_t;

/** RSPI Clock Divider settings. */
typedef struct
{
    uint8_t spbr;                      ///< SPBR register setting
    uint8_t brdv : 2;                  ///< BRDV setting in SPCMD0
} rspi_rspck_div_setting_t;

/** Extended RSPI interface configuration */
typedef struct st_rspi_extended_cfg
{
    rspi_ssl_polarity_t           ssl_polarity;       ///< Select SSLn signal polarity
    rspi_mosi_idle_value_fixing_t mosi_idle;          ///< Select MOSI idle fixed value and selection
    rspi_rspck_div_setting_t      spck_div;           ///< Register values for configuring the RSPI Clock Divider.
    rspi_delay_count_t            spck_delay;         ///< SPI Clock Delay Register Setting
    rspi_delay_count_t            ssl_negation_delay; ///< SPI Slave Select Negation Delay Register Setting
    rspi_delay_count_t            next_access_delay;  ///< SPI Next-Access Delay Register Setting
    rspi_ssl_level_keep_t         ssl_level_keep;     ///< Select SSL signal level keep mode
    rspi_rx_trigger_level_t       rx_trigger_level;   ///< Receiver FIFO trigger level
    rspi_tx_trigger_level_t       tx_trigger_level;   ///< Transmitter FIFO trigger level
} rspi_extended_cfg_t;

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref spi_api_t::open is called. */
typedef struct st_rspi_instance_ctrl
{
    uint32_t              open;        ///< Indicates whether the open() API has been successfully called.
    spi_cfg_t const     * p_cfg;       ///< Pointer to instance configuration
    rspi_extended_cfg_t * p_ext;       ///< Pointer to extended configuration
    R_RSPI0_Type        * p_regs;      ///< Base register for this channel
    void const          * p_tx_data;   ///< Buffer to transmit
    void                * p_rx_data;   ///< Buffer to receive
    uint32_t              tx_count;    ///< Number of Data Frames to transfer (8-bit, 16-bit, 32-bit)
    uint32_t              rx_count;    ///< Number of Data Frames to transfer (8-bit, 16-bit, 32-bit)
    spi_bit_width_t       bit_width;   ///< Bits per Data frame (8-bit, 16-bit, 32-bit)

    /* Pointer to callback and optional working memory */
    void (* p_callback)(spi_callback_args_t *);
    spi_callback_args_t * p_callback_memory;

    /* Pointer to context to be passed into callback function */
    void const  * p_context;
    uint32_t      rxfifo_trigger_bytes; ///< Receive buffer data triggering number
    volatile bool transfer_is_pending;  ///< Transfer is pending
} rspi_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const spi_api_t g_spi_on_rspi;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_RSPI_Open(spi_ctrl_t * p_api_ctrl, spi_cfg_t const * const p_cfg);

fsp_err_t R_RSPI_Read(spi_ctrl_t * const    p_api_ctrl,
                      void                * p_dest,
                      uint32_t const        length,
                      spi_bit_width_t const bit_width);

fsp_err_t R_RSPI_Write(spi_ctrl_t * const    p_api_ctrl,
                       void const          * p_src,
                       uint32_t const        length,
                       spi_bit_width_t const bit_width);

fsp_err_t R_RSPI_WriteRead(spi_ctrl_t * const    p_api_ctrl,
                           void const          * p_src,
                           void                * p_dest,
                           uint32_t const        length,
                           spi_bit_width_t const bit_width);

fsp_err_t R_RSPI_Close(spi_ctrl_t * const p_api_ctrl);

fsp_err_t R_RSPI_CalculateBitrate(uint32_t bitrate, rspi_rspck_div_setting_t * spck_div);

fsp_err_t R_RSPI_CallbackSet(spi_ctrl_t * const          p_api_ctrl,
                             void (                    * p_callback)(spi_callback_args_t *),
                             void const * const          p_context,
                             spi_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end ingroup RSPI)
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* R_RSPI_H */
