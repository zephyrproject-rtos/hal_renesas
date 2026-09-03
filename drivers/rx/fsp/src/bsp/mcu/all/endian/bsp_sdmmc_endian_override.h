/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_SDMMC_ENDIAN_OVERRIDE_H
#define BSP_SDMMC_ENDIAN_OVERRIDE_H

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_OVERRIDE_SDMMC_R1_STATE_T
#define BSP_OVERRIDE_SDMMC_RESPONSE_T

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Card state when receiving the prior command. */
typedef enum e_sdmmc_r1_state
{
    SDMMC_R1_STATE_IDLE  = 0,          ///< Idle State
    SDMMC_R1_STATE_READY = 0,          ///< Ready State
    SDMMC_R1_STATE_IDENT = 0,          ///< Identification State
    SDMMC_R1_STATE_STBY  = 0,          ///< Stand-by State
    SDMMC_R1_STATE_TRAN  = 0,          ///< Transfer State
    SDMMC_R1_STATE_DATA  = 0,          ///< Sending-data State
    SDMMC_R1_STATE_RCV   = 0,          ///< Receive-data State
    SDMMC_R1_STATE_PRG   = 0,          ///< Programming State
    SDMMC_R1_STATE_DIS   = 0,          ///< Disconnect State (between programming and stand-by)
    SDMMC_R1_STATE_IO    = 15,         ///< This is an I/O card and memory states do not apply
} sdmmc_r1_state_t;

/* Structure for decoding the response of a command.  For advanced use only. */
typedef union u_sdmmc_response
{
    uint32_t status;

    /** SDIO Card Status Register. */
    struct
    {
#if defined(__BIG) && defined(__GNUC__)
        uint32_t out_of_range              : 1; // Command argument is outside card range.
        uint32_t address_error             : 1; // Command address does not match block length.
        uint32_t block_len_error           : 1; // Transfer block length is invalid.
        uint32_t erase_seq_error           : 1; // Erase command sequence is invalid.
        uint32_t erase_param               : 1; // Erase block selection is invalid.
        uint32_t wp_violation              : 1; // Write attempted on a protected block.
        uint32_t device_is_locked          : 1; // Card is locked by the host.
        uint32_t lock_unlock_failed        : 1; // Lock or unlock sequence failed.
        uint32_t com_crc_error             : 1; // Previous command CRC check failed.
        uint32_t illegal_command           : 1; // Command is invalid for current card state.
        uint32_t card_ecc_failed           : 1; // Card ECC could not correct data.
        uint32_t cc_error                  : 1; // Card controller error occurred.
        uint32_t error                     : 1; // General or unknown error occurred.
        uint32_t                           : 2;
        uint32_t         csd_overwrite     : 1; // CSD does not match card content.
        uint32_t         wp_erase_skip     : 1; // Erase skipped protected blocks.
        uint32_t         card_ecc_disabled : 1; // Command executed without internal ECC.
        uint32_t         erase_reset       : 1; // Erase sequence was reset.
        sdmmc_r1_state_t current_state     : 4;
        uint32_t         ready_for_data    : 1; // Corresponds to the buffer empty signaling on the bus
        uint32_t         switch_error      : 1; //
        uint32_t         fx_event          : 1; // Card requests extension function handling.
        uint32_t         app_cmd           : 1; // Card expects or accepted an application command.
        uint32_t                           : 1;
        uint32_t ake_seq_error             : 1; // Authentication sequence error.
        uint32_t                           : 3;
#else
        uint32_t                           : 3;
        uint32_t ake_seq_error             : 1; // Authentication sequence error.
        uint32_t                           : 1;
        uint32_t         app_cmd           : 1; // Card expects or accepted an application command.
        uint32_t         fx_event          : 1; // Card requests extension function handling.
        uint32_t         switch_error      : 1; //
        uint32_t         ready_for_data    : 1; // Corresponds to the buffer empty signaling on the bus
        sdmmc_r1_state_t current_state     : 4;
        uint32_t         erase_reset       : 1; // Erase sequence was reset.
        uint32_t         card_ecc_disabled : 1; // Command executed without internal ECC.
        uint32_t         wp_erase_skip     : 1; // Erase skipped protected blocks.
        uint32_t         csd_overwrite     : 1; // CSD does not match card content.
        uint32_t                           : 2;
        uint32_t error                     : 1; // General or unknown error occurred.
        uint32_t cc_error                  : 1; // Card controller error occurred.
        uint32_t card_ecc_failed           : 1; // Card ECC could not correct data.
        uint32_t illegal_command           : 1; // Command is invalid for current card state.
        uint32_t com_crc_error             : 1; // Previous command CRC check failed.
        uint32_t lock_unlock_failed        : 1; // Lock or unlock sequence failed.
        uint32_t device_is_locked          : 1; // Card is locked by the host.
        uint32_t wp_violation              : 1; // Write attempted on a protected block.
        uint32_t erase_param               : 1; // Erase block selection is invalid.
        uint32_t erase_seq_error           : 1; // Erase command sequence is invalid.
        uint32_t block_len_error           : 1; // Transfer block length is invalid.
        uint32_t address_error             : 1; // Command address does not match block length.
        uint32_t out_of_range              : 1; // Command argument is outside card range.
#endif
    } status_b;

    struct
    {
#if defined(__BIG) && defined(__GNUC__)
        uint32_t power_up_status      : 1;
        uint32_t card_capacity_status : 1;
        uint32_t reserved_25          : 5;
        uint32_t s18A                 : 1;
        uint32_t v_35_36              : 1;
        uint32_t v_34_35              : 1;
        uint32_t v_33_34              : 1;
        uint32_t v_32_33              : 1;
        uint32_t v_31_32              : 1;
        uint32_t v_30_31              : 1;
        uint32_t v_29_30              : 1;
        uint32_t v_28_29              : 1;
        uint32_t v_27_28              : 1;
        uint32_t reserved_8           : 7;
        uint32_t reserved_lvr         : 1;
        uint32_t reserved_0           : 7;
#else
        uint32_t reserved_0           : 7;
        uint32_t reserved_lvr         : 1;
        uint32_t reserved_8           : 7;
        uint32_t v_27_28              : 1;
        uint32_t v_28_29              : 1;
        uint32_t v_29_30              : 1;
        uint32_t v_30_31              : 1;
        uint32_t v_31_32              : 1;
        uint32_t v_32_33              : 1;
        uint32_t v_33_34              : 1;
        uint32_t v_34_35              : 1;
        uint32_t v_35_36              : 1;
        uint32_t s18A                 : 1;
        uint32_t reserved_25          : 5;
        uint32_t card_capacity_status : 1;
        uint32_t power_up_status      : 1;
#endif
    } r3;

    struct
    {
#if defined(__BIG) && defined(__GNUC__)
        uint32_t ready        : 1;
        uint32_t io_functions : 3;
        uint32_t memory       : 1;
        uint32_t reserved_24  : 3;
        uint32_t ocr          : 24;
#else
        uint32_t ocr          : 24;
        uint32_t reserved_24  : 3;
        uint32_t memory       : 1;
        uint32_t io_functions : 3;
        uint32_t ready        : 1;
#endif
    } r4;

    struct
    {
#if defined(__BIG) && defined(__GNUC__)
        uint32_t reserved_16      : 16;
        uint32_t crc_error        : 1;
        uint32_t illegal_command  : 1;
        uint32_t current_state    : 2;
        uint32_t error            : 1;
        uint32_t rfu              : 1;
        uint32_t invalid_function : 1;
        uint32_t out_of_range     : 1;
        uint32_t read_write_data  : 8;
#else
        uint32_t read_write_data  : 8;
        uint32_t out_of_range     : 1;
        uint32_t invalid_function : 1;
        uint32_t rfu              : 1;
        uint32_t error            : 1;
        uint32_t current_state    : 2;
        uint32_t illegal_command  : 1;
        uint32_t crc_error        : 1;
        uint32_t reserved_16      : 16;
#endif
    } r5;

    struct
    {
#if defined(__BIG) && defined(__GNUC__)
        uint32_t         rca             : 16;
        uint32_t         com_crc_error   : 1;
        uint32_t         illegal_command : 1;
        uint32_t         error           : 1;
        sdmmc_r1_state_t current_state   : 4;
        uint32_t         ready_for_data  : 1;
        uint32_t         reserved_6      : 2;
        uint32_t         app_cmd         : 1;
        uint32_t         reserved_4      : 1;
        uint32_t         ake_seq_error   : 1;
        uint32_t         reserved_0      : 3;
#else
        uint32_t         reserved_0      : 3;
        uint32_t         ake_seq_error   : 1;
        uint32_t         reserved_4      : 1;
        uint32_t         app_cmd         : 1;
        uint32_t         reserved_6      : 2;
        uint32_t         ready_for_data  : 1;
        sdmmc_r1_state_t current_state   : 4;
        uint32_t         error           : 1;
        uint32_t         illegal_command : 1;
        uint32_t         com_crc_error   : 1;
        uint32_t         rca             : 16;
#endif
    } r6;

    struct
    {
#if defined(__BIG) && defined(__GNUC__)
        uint32_t reserved_11      : 20;
        uint32_t voltage_accepted : 4;
        uint32_t check_pattern    : 8;
#else
        uint32_t check_pattern    : 8;
        uint32_t voltage_accepted : 4;
        uint32_t reserved_11      : 20;
#endif
    } r7;
} sdmmc_response_t;

#endif
