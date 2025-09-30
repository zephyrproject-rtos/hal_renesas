/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup XSPI_QSPI
 * @{
 **********************************************************************************************************************/

#ifndef R_XSPI_QSPI_H
#define R_XSPI_QSPI_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include <string.h>
#include "r_xspi_qspi_cfg.h"
#include "r_spi_flash_api.h"

#if XSPI_QSPI_CFG_DMAC_SUPPORT_ENABLE
 #include "r_transfer_api.h"
#endif

#if XSPI_QSPI_CFG_OTFD_SUPPORT_ENABLE
 #include "r_rsip_api.h"
 #include "r_rsip_reg.h"
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* QSPI Flash chip select */
typedef enum e_xspi_qspi_chip_select
{
    XSPI_QSPI_CHIP_SELECT_0,           ///< Device connected to Chip-Select 0
    XSPI_QSPI_CHIP_SELECT_1,           ///< Device connected to Chip-Select 1
} xspi_qspi_chip_select_t;

/* QSPI Flash memory size */
typedef enum e_xspi_qspi_memory_size
{
    XSPI_QSPI_MEMORY_SIZE_1MB  = 0x00, ///< Memory size 1MB
    XSPI_QSPI_MEMORY_SIZE_2MB  = 0x01, ///< Memory size 2MB
    XSPI_QSPI_MEMORY_SIZE_4MB  = 0x03, ///< Memory size 4MB
    XSPI_QSPI_MEMORY_SIZE_8MB  = 0x07, ///< Memory size 8MB
    XSPI_QSPI_MEMORY_SIZE_16MB = 0x0F, ///< Memory size 16MB
    XSPI_QSPI_MEMORY_SIZE_32MB = 0x1F, ///< Memory size 32MB
    XSPI_QSPI_MEMORY_SIZE_64MB = 0x3F, ///< Memory size 64MB
} xspi_qspi_memory_size_t;

/* QSPI command to command interval*/
typedef enum e_xspi_qspi_command_interval_clocks
{
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_1,  ///< 1 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_2,  ///< 2 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_3,  ///< 3 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_4,  ///< 4 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_5,  ///< 5 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_6,  ///< 6 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_7,  ///< 7 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_8,  ///< 8 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_9,  ///< 9 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_10, ///< 10 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_11, ///< 11 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_12, ///< 12 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_13, ///< 13 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_14, ///< 14 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_15, ///< 15 interval clocks
    XSPI_QSPI_COMMAND_INTERVAL_CLOCKS_16, ///< 16 interval clocks
} xspi_qspi_command_interval_clocks_t;

/* QSPI chip select de-assertion duration */
typedef enum e_xspi_qspi_cs_pullup_clocks
{
    XSPI_QSPI_CS_PULLUP_CLOCKS_NO_EXTENSION = 0, ///< CS asserting No extension
    XSPI_QSPI_CS_PULLUP_CLOCKS_1,                ///< CS asserting Extend 1 cycle
} xspi_qspi_cs_pullup_clocks_t;

/* QSPI chip select assertion duration */
typedef enum e_xspi_qspi_cs_pulldown_clocks
{
    XSPI_QSPI_CS_PULLDOWN_CLOCKS_NO_EXTENSION = 0, ///< CS negating No extension
    XSPI_QSPI_CS_PULLDOWN_CLOCKS_1,                ///< CS negating Extend 1 cycle
} xspi_qspi_cs_pulldown_clocks_t;

/* Memory mapped timing */
typedef struct st_qspi_timing_setting
{
    xspi_qspi_command_interval_clocks_t command_to_command_interval; ///< Interval between 2 consecutive commands
    xspi_qspi_cs_pullup_clocks_t        cs_pullup_lag;               ///< Duration to de-assert CS line after the last command
    xspi_qspi_cs_pulldown_clocks_t      cs_pulldown_lead;            ///< Duration to assert CS line before the first command
} xspi_qspi_timing_setting_t;

/* Prefetch function settings */
typedef enum e_xspi_qspi_prefetch_function
{
    XSPI_QSPI_PREFETCH_FUNCTION_DISABLE = 0x00, ///< Prefetch function disable
    XSPI_QSPI_PREFETCH_FUNCTION_ENABLE  = 0x01, ///< Prefetch function enable
} xspi_qspi_prefetch_function_t;

/* IO voltage settings */
typedef enum e_xspi_qspi_io_voltage
{
    XSPI_QSPI_IO_VOLTAGE_1_8V = 0x00,  ///< IO voltage 1.8V
    XSPI_QSPI_IO_VOLTAGE_3_3V = 0x01,  ///< IO voltage 3.3V
} xspi_qspi_io_voltage_t;

/* Address space settings */
typedef struct st_qspi_address_space
{
    uint32_t unit0_cs0_end_address;    ///< xSPI unit0 cs0 end address
    uint32_t unit0_cs1_start_address;  ///< xSPI unit0 cs1 start address
    uint32_t unit0_cs1_end_address;    ///< xSPI unit0 cs1 end address
    uint32_t unit1_cs0_end_address;    ///< xSPI unit1 cs0 end address
    uint32_t unit1_cs1_start_address;  ///< xSPI unit1 cs1 start address
    uint32_t unit1_cs1_end_address;    ///< xSPI unit1 cs1 end address
} xspi_qspi_address_space_t;

/* OTFD AES Type. */
typedef enum e_xspi_qspi_otfd_aes_key_type
{
    XSPI_QSPI_OTFD_AES_KEY_TYPE_128 = 0U,
    XSPI_QSPI_OTFD_AES_KEY_TYPE_256 = 2U,
} xspi_qspi_otfd_aes_key_type_t;

/* This structure is used to hold all the OTFD related configuration. */
typedef struct st_xspi_qspi_otfd_cfg
{
    xspi_qspi_otfd_aes_key_type_t key_type;
    uint32_t * p_start_addr;
    uint32_t * p_end_addr;
    uint32_t * p_key;
    uint32_t * p_iv;
} xspi_qspi_otfd_cfg_t;

/* Extended configuration. */
typedef struct st_xspi_qspi_extended_cfg
{
    uint8_t                            unit;              ///< Unit number of xSPI
    xspi_qspi_chip_select_t            chip_select;       ///< Device number to be used for memory device
    xspi_qspi_memory_size_t            memory_size;       ///< Size of memory device
    xspi_qspi_timing_setting_t const * p_timing_settings; ///< Memory mapped timing settings
    xspi_qspi_prefetch_function_t      prefetch_en;       ///< Prefetch function settings
    xspi_qspi_io_voltage_t             io_voltage;        ///< Voltage setting of xSPI IO domain
    xspi_qspi_address_space_t const  * p_address_space;   ///< Address space settings when custom address space enabled

#if XSPI_QSPI_CFG_DMAC_SUPPORT_ENABLE
    transfer_instance_t const * p_lower_lvl_transfer;     ///< DMAC Transfer instance used for data transmission
#endif

#if XSPI_QSPI_CFG_OTFD_SUPPORT_ENABLE
    xspi_qspi_otfd_cfg_t const * p_otfd_cfg;              ///< OTFD Configuration. Set to NULL if unused.
#endif
} xspi_qspi_extended_cfg_t;

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref spi_flash_api_t::open is called */
typedef struct st_xspi_qspi_instance_ctrl
{
    spi_flash_cfg_t const * p_cfg;            // Pointer to initial configuration
    spi_flash_data_lines_t  data_lines;       // Data lines
    uint32_t                total_size_bytes; // Total size of the flash in bytes
    uint32_t                open;             // Whether or not driver is open
    R_XSPI0_Type          * p_reg;            // Base register for this channel

#if XSPI_QSPI_CFG_OTFD_SUPPORT_ENABLE
    R_OTFD0_Type * p_otfd_reg;                // Base OTFD register for this channel
#endif

    spi_flash_protocol_t spi_protocol;        // Current SPI protocol selected
} xspi_qspi_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const spi_flash_api_t g_spi_flash_on_xspi_qspi;

/** @endcond */

fsp_err_t R_XSPI_QSPI_Open(spi_flash_ctrl_t * p_ctrl, spi_flash_cfg_t const * const p_cfg);
fsp_err_t R_XSPI_QSPI_Close(spi_flash_ctrl_t * p_ctrl);
fsp_err_t R_XSPI_QSPI_DirectWrite(spi_flash_ctrl_t    * p_ctrl,
                                  uint8_t const * const p_src,
                                  uint32_t const        bytes,
                                  bool const            read_after_write);
fsp_err_t R_XSPI_QSPI_DirectRead(spi_flash_ctrl_t * p_ctrl, uint8_t * const p_dest, uint32_t const bytes);
fsp_err_t R_XSPI_QSPI_SpiProtocolSet(spi_flash_ctrl_t * p_ctrl, spi_flash_protocol_t spi_protocol);
fsp_err_t R_XSPI_QSPI_XipEnter(spi_flash_ctrl_t * p_ctrl);
fsp_err_t R_XSPI_QSPI_XipExit(spi_flash_ctrl_t * p_ctrl);
fsp_err_t R_XSPI_QSPI_Write(spi_flash_ctrl_t    * p_ctrl,
                            uint8_t const * const p_src,
                            uint8_t * const       p_dest,
                            uint32_t              byte_count);
fsp_err_t R_XSPI_QSPI_Erase(spi_flash_ctrl_t * p_ctrl, uint8_t * const p_device_address, uint32_t byte_count);
fsp_err_t R_XSPI_QSPI_StatusGet(spi_flash_ctrl_t * p_ctrl, spi_flash_status_t * const p_status);
fsp_err_t R_XSPI_QSPI_BankSet(spi_flash_ctrl_t * p_ctrl, uint32_t bank);
fsp_err_t R_XSPI_QSPI_DirectTransfer(spi_flash_ctrl_t                  * p_ctrl,
                                     spi_flash_direct_transfer_t * const p_transfer,
                                     spi_flash_direct_transfer_dir_t     direction);
fsp_err_t R_XSPI_QSPI_AutoCalibrate(spi_flash_ctrl_t * p_ctrl);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup XSPI_QSPI)
 **********************************************************************************************************************/
