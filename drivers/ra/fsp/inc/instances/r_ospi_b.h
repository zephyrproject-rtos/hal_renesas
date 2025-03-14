/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup OSPI_B
 * @{
 **********************************************************************************************************************/

#ifndef R_OSPI_B_H
#define R_OSPI_B_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_ospi_b_cfg.h"
#include "r_spi_flash_api.h"

#if OSPI_B_CFG_DMAC_SUPPORT_ENABLE
 #include "r_transfer_api.h"
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** OSPI Flash chip select */
typedef enum e_ospi_b_chip_select
{
    OSPI_B_DEVICE_NUMBER_0 = 0U,       ///< Device connected to Chip-Select 0
    OSPI_B_DEVICE_NUMBER_1,            ///< Device connected to Chip-Select 1
} ospi_b_device_number_t;

/** OSPI flash number of command code bytes. */
typedef enum e_ospi_b_command_bytes
{
    OSPI_B_COMMAND_BYTES_1 = 1U,       ///< Command codes are 1 byte long.
    OSPI_B_COMMAND_BYTES_2 = 2U,       ///< Command codes are 2 bytes long.
} ospi_b_command_bytes_t;

/** OSPI frame to frame interval */
typedef enum e_ospi_b_frame_interval_clocks
{
    OSPI_B_COMMAND_INTERVAL_CLOCKS_1 = 0U, ///< 1 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_2,      ///< 2 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_3,      ///< 3 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_4,      ///< 4 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_5,      ///< 5 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_6,      ///< 6 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_7,      ///< 7 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_8,      ///< 8 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_9,      ///< 9 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_10,     ///< 10 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_11,     ///< 11 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_12,     ///< 12 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_13,     ///< 13 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_14,     ///< 14 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_15,     ///< 15 interval clocks
    OSPI_B_COMMAND_INTERVAL_CLOCKS_16,     ///< 16 interval clocks
} ospi_b_command_interval_clocks_t;

/** OSPI chip select de-assertion duration */
typedef enum e_ospi_b_cs_pullup_clocks
{
    OSPI_B_COMMAND_CS_PULLUP_CLOCKS_NO_EXTENSION = 0U, ///< CS asserting No extension
    OSPI_B_COMMAND_CS_PULLUP_CLOCKS_1,                 ///< CS asserting Extend 1 cycle
} ospi_b_command_cs_pullup_clocks_t;

/** OSPI chip select assertion duration */
typedef enum e_ospi_b_cs_pulldown_clocks
{
    OSPI_B_COMMAND_CS_PULLDOWN_CLOCKS_NO_EXTENSION = 0U, ///< CS negating No extension
    OSPI_B_COMMAND_CS_PULLDOWN_CLOCKS_1,                 ///< CS negating Extend 1 cycle
} ospi_b_command_cs_pulldown_clocks_t;

/** Prefetch function settings */
typedef enum e_ospi_b_prefetch_function
{
    OSPI_B_PREFETCH_FUNCTION_DISABLE = 0x00, ///< Prefetch function disable
    OSPI_B_PREFETCH_FUNCTION_ENABLE  = 0x01, ///< Prefetch function enable
} ospi_b_prefetch_function_t;

/** Combination function settings */
typedef enum e_ospi_b_combination_function
{
    OSPI_B_COMBINATION_FUNCTION_DISABLE = 0x00,  ///< Combination function disable
    OSPI_B_COMBINATION_FUNCTION_4BYTE   = 0x01,  ///< Combine up to 4 bytes
    OSPI_B_COMBINATION_FUNCTION_8BYTE   = 0x03,  ///< Combine up to 8 bytes
    OSPI_B_COMBINATION_FUNCTION_12BYTE  = 0x05,  ///< Combine up to 12 bytes
    OSPI_B_COMBINATION_FUNCTION_16BYTE  = 0x07,  ///< Combine up to 16 bytes
    OSPI_B_COMBINATION_FUNCTION_20BYTE  = 0x09,  ///< Combine up to 20 bytes
    OSPI_B_COMBINATION_FUNCTION_24BYTE  = 0x0B,  ///< Combine up to 24 bytes
    OSPI_B_COMBINATION_FUNCTION_28BYTE  = 0x0D,  ///< Combine up to 28 bytes
    OSPI_B_COMBINATION_FUNCTION_32BYTE  = 0x0F,  ///< Combine up to 32 bytes
    OSPI_B_COMBINATION_FUNCTION_36BYTE  = 0x11,  ///< Combine up to 36 bytes
    OSPI_B_COMBINATION_FUNCTION_40BYTE  = 0x13,  ///< Combine up to 40 bytes
    OSPI_B_COMBINATION_FUNCTION_44BYTE  = 0x15,  ///< Combine up to 44 bytes
    OSPI_B_COMBINATION_FUNCTION_48BYTE  = 0x17,  ///< Combine up to 48 bytes
    OSPI_B_COMBINATION_FUNCTION_52BYTE  = 0x19,  ///< Combine up to 52 bytes
    OSPI_B_COMBINATION_FUNCTION_56BYTE  = 0x1B,  ///< Combine up to 56 bytes
    OSPI_B_COMBINATION_FUNCTION_60BYTE  = 0x1D,  ///< Combine up to 60 bytes
    OSPI_B_COMBINATION_FUNCTION_64BYTE  = 0x1F,  ///< Combine up to 64 bytes
    OSPI_B_COMBINATION_FUNCTION_2BYTE   = 0x1FF, ///< Combine up to 2 bytes
} ospi_b_combination_function_t;

/** Simple array length table structure. */
typedef struct st_ospi_b_table
{
    void  * p_table;                   ///< Pointer to the table array.
    uint8_t length;                    ///< Number of entries in the table.
} ospi_b_table_t;

/** Memory mapped timing */
typedef struct st_ospi_b_timing_setting
{
    ospi_b_command_interval_clocks_t    command_to_command_interval; ///< Interval between 2 consecutive commands
    ospi_b_command_cs_pullup_clocks_t   cs_pullup_lag;               ///< Duration to de-assert CS line after the last command
    ospi_b_command_cs_pulldown_clocks_t cs_pulldown_lead;            ///< Duration to assert CS line before the first command
} ospi_b_timing_setting_t;

/** Command set used for a protocol mode other than normal (1S-1S-1S) SPI. */
typedef struct st_ospi_b_xspi_command_set
{
    spi_flash_protocol_t   protocol;             ///< Protocol mode associated with this command set.
    ospi_b_command_bytes_t command_bytes;        ///< Number of command bytes for each command code.
    uint16_t               read_command;         ///< Read command.
    uint16_t               page_program_command; ///< Page program/write command.
    uint16_t               write_enable_command; ///< Command to enable write or erase, set to 0x00 to ignore.
    uint16_t               status_command;       ///< Command to read the write status, set to 0x00 to ignore.
    uint8_t                read_dummy_cycles;    ///< Dummy cycles to be inserted for read commands.
    uint8_t                program_dummy_cycles; ///< Dummy cycles to be inserted for page program commands.
    uint8_t                status_dummy_cycles;  ///< Dummy cycles to be inserted for status read commands.
    ospi_b_table_t const * p_erase_commands;     ///< List of all erase commands and associated sizes
} ospi_b_xspi_command_set_t;

/** OSPI DOTF AES Key Lengths. */
typedef enum e_ospi_b_dotf_aes_key_length_words
{
    OSPI_B_DOTF_AES_KEY_LENGTH_WORDS_128 = 16U,
    OSPI_B_DOTF_AES_KEY_LENGTH_WORDS_192 = 24U,
    OSPI_B_DOTF_AES_KEY_LENGTH_WORDS_256 = 32U
} ospi_b_dotf_aes_key_length_words_t;

/** PSPI DOTF AES Type. */
typedef enum e_ospi_b_dotf_aes_key_type
{
    OSPI_B_DOTF_AES_KEY_TYPE_128 = 0U,
    OSPI_B_DOTF_AES_KEY_TYPE_192 = 1U,
    OSPI_B_DOTF_AES_KEY_TYPE_256 = 2U
} ospi_b_dotf_aes_key_type_t;

/** OSPI DOTF key Type. */
typedef enum e_ospi_b_dotf_key_format
{
    OSPI_B_DOTF_KEY_FORMAT_PLAINTEXT = 0U,
    OSPI_B_DOTF_KEY_FORMAT_WRAPPED   = 1U,
} ospi_b_dotf_key_format_t;

/** This structure is used to hold all the DOTF related configuration. */
typedef struct st_ospi_b_dotf_cfg
{
    ospi_b_dotf_aes_key_type_t key_type;
    ospi_b_dotf_key_format_t   format;
    uint32_t                 * p_start_addr;
    uint32_t                 * p_end_addr;
    uint32_t                 * p_key;
    uint32_t                 * p_iv;
} ospi_b_dotf_cfg_t;

/** OSPI_B Extended configuration. */
typedef struct st_ospi_b_extended_cfg
{
    uint8_t                         ospi_b_unit;                             ///< The OSPI_B unit corresponding to the selected channel.
    ospi_b_device_number_t          channel;                                 ///< Device number to be used for memory device
    ospi_b_timing_setting_t const * p_timing_settings;                       ///< Memory-mapped timing settings.
    ospi_b_table_t const          * p_xspi_command_set;                      ///< Additional protocol command sets; if additional protocol commands set are not used set this to NULL.
    uint8_t                       * p_autocalibration_preamble_pattern_addr; ///< OctaFlash memory address holding the preamble pattern
    uint8_t                         data_latch_delay_clocks;                 ///< Specify delay between OM_DQS and OM_DQS Strobe. Set to 0 to auto-calibrate. Typical value is 0x80.
#if OSPI_B_CFG_DMAC_SUPPORT_ENABLE
    transfer_instance_t const * p_lower_lvl_transfer;                        ///< DMA Transfer instance used for data transmission
#endif
#if OSPI_B_CFG_DOTF_SUPPORT_ENABLE
    ospi_b_dotf_cfg_t * p_dotf_cfg;                                          ///< DOTF Configuration
#endif
    uint8_t read_dummy_cycles;                                               ///< Dummy cycles to be inserted for read commands.
    uint8_t program_dummy_cycles;                                            ///< Dummy cycles to be inserted for page program commands.
    uint8_t status_dummy_cycles;                                             ///< Dummy cycles to be inserted for status read commands.
} ospi_b_extended_cfg_t;

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref spi_flash_api_t::open is called */
typedef struct st_ospi_b_instance_ctrl
{
    spi_flash_cfg_t const           * p_cfg;        ///< Pointer to initial configuration.
    uint32_t                          open;         ///< Whether or not driver is open.
    spi_flash_protocol_t              spi_protocol; ///< Current OSPI protocol selected.
    ospi_b_device_number_t            channel;      ///< Device number to be used for memory device.
    ospi_b_xspi_command_set_t const * p_cmd_set;    ///< Command set for the active protocol mode.
    R_XSPI0_Type                    * p_reg;        ///< Address for the OSPI peripheral associated with this channel.
} ospi_b_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const spi_flash_api_t g_ospi_b_on_spi_flash;

/** @endcond */

fsp_err_t R_OSPI_B_Open(spi_flash_ctrl_t * const p_ctrl, spi_flash_cfg_t const * const p_cfg);
fsp_err_t R_OSPI_B_Close(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_OSPI_B_DirectWrite(spi_flash_ctrl_t * const p_ctrl,
                               uint8_t const * const    p_src,
                               uint32_t const           bytes,
                               bool const               read_after_write);
fsp_err_t R_OSPI_B_DirectRead(spi_flash_ctrl_t * const p_ctrl, uint8_t * const p_dest, uint32_t const bytes);
fsp_err_t R_OSPI_B_DirectTransfer(spi_flash_ctrl_t * const            p_ctrl,
                                  spi_flash_direct_transfer_t * const p_transfer,
                                  spi_flash_direct_transfer_dir_t     direction);
fsp_err_t R_OSPI_B_SpiProtocolSet(spi_flash_ctrl_t * const p_ctrl, spi_flash_protocol_t spi_protocol);
fsp_err_t R_OSPI_B_XipEnter(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_OSPI_B_XipExit(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_OSPI_B_Write(spi_flash_ctrl_t * const p_ctrl,
                         uint8_t const * const    p_src,
                         uint8_t * const          p_dest,
                         uint32_t                 byte_count);
fsp_err_t R_OSPI_B_Erase(spi_flash_ctrl_t * const p_ctrl, uint8_t * const p_device_address, uint32_t byte_count);
fsp_err_t R_OSPI_B_StatusGet(spi_flash_ctrl_t * const p_ctrl, spi_flash_status_t * const p_status);
fsp_err_t R_OSPI_B_BankSet(spi_flash_ctrl_t * const _ctrl, uint32_t bank);
fsp_err_t R_OSPI_B_AutoCalibrate(spi_flash_ctrl_t * const p_ctrl);

fsp_err_t R_OSPI_B_DOTF_Configure(spi_flash_ctrl_t * const p_ctrl, ospi_b_dotf_cfg_t * const p_dotf_cfg);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup OSPI_B)
 **********************************************************************************************************************/
