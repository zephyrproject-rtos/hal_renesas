/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdlib.h>
#include "bsp_api.h"
#include "r_spibsc.h"
#include "r_spibsc_private.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define SPIBSC_PRV_OPEN                         (0x53504942)
#ifndef SPIBSC_CFG_PARAM_CHECKING_ENABLE
 #define SPIBSC_CFG_PARAM_CHECKING_ENABLE       true
#endif
#ifndef SPIBSC_CFG_ALREADY_INITIALIZED
 #define SPIBSC_CFG_ALREADY_INITIALIZED         1
#endif
#ifndef SPIBSC_CFG_CODE_SECTION
 #define SPIBSC_CFG_CODE_SECTION                ".text.spibsc"
#endif
#ifndef SPIBSC_CFG_MMAP_BASE
 #define SPIBSC_CFG_MMAP_BASE                   0x20000000UL
#endif
#ifndef SPIBSC_CFG_WRITE_BUFFER_OFFSET
 #define SPIBSC_CFG_WRITE_BUFFER_OFFSET         0x10000UL
#endif
#ifndef SPIBSC_CFG_STOP_ON_CLOSE
 #define SPIBSC_CFG_STOP_ON_CLOSE               0
#endif

/* Driver settings */
#define SPIBSC_PRV_RESET_DURATION_US            (10)
#define SPIBSC_PRV_DEFAULT_VOLTAGE_IS_1800MV    (1)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum e_xspi_transfer_form
{
    SPI_FORM_1_1_1,                    /* Command executes at 1-1-1 form */
    SPI_FORM_1_1_2,                    /* Command executes at 1-1-2 form */
    SPI_FORM_1_2_2,                    /* Command executes at 1-2-2 form */
    SPI_FORM_2_2_2,                    /* Command executes at 2-2-2 form */
    SPI_FORM_1_1_4,                    /* Command executes at 1-1-4 form */
    SPI_FORM_1_4_4,                    /* Command executes at 1-4-4 form */
    SPI_FORM_4_4_4,                    /* Command executes at 4-4-4 form */
    SPI_FORM_1_1_8,                    /* Command executes at 1-1-8 form */
    SPI_FORM_1_8_8,                    /* Command executes at 1-8-8 form */
    SPI_FORM_8_8_8,                    /* Command executes at 8-8-8 form */
} xspi_transfer_form_t;

typedef struct st_xspi_op
{
    xspi_transfer_form_t form;                   ///< Transfer form
    uint16_t             op;                     ///< Operation code (for 2 byte op, highside used as 1st byte)
    uint8_t              op_size;                ///< Operation code size (0 to 2)
    uint32_t             address;                ///< Address (ignored for configuring in-place access)
    uint8_t              address_size;           ///< Address size (0 to 4)
    uint8_t              additional_size;        ///< Additional data size
    uint32_t             additional_value;       ///< Additional data value
    uint8_t              dummy_cycles;           ///< Dummy cycle count (as clocks)
    size_t               transfer_size;          ///< Transfer size by bytes (ignored for configuring in-place access)
    void               * transfer_buffer;        ///< Transfer buffer pointer (ignored for configuring in-place access)
    uint8_t              force_idle_level_mask;  ///< Whether or not to force each IO level during the idle state
    uint8_t              force_idle_level_value; ///< IO level during the idle state
    uint8_t              slch_value;             ///< Clock delay after select (SLCH)
    uint8_t              clsh_value;             ///< De-select delay after clock stopped (CLSH)
    uint8_t              shsl_value;             ///< Cycle delay between transaction (SHSL)
} xspi_op_t;

typedef struct st_spibsc_mmap_cfg
{
    /* Search indexes */
    spi_flash_protocol_t      spi_protocol;  ///< The protocol
    spi_flash_read_mode_t     read_mode;     ///< The read mode
    spi_flash_address_bytes_t address_bytes; ///< The address bytes

    /* The parameters */
    xspi_transfer_form_t form;               ///< Transfer form
    uint8_t              op;                 ///< Operation code
    uint8_t              address_size;       ///< Address size (0 to 4)
    uint8_t              additional_size;    ///< Additional data size
    uint8_t              dummy_cycles;       ///< Dummy cycle count (as clocks)
} spibsc_mmap_cfg_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static fsp_err_t spibsc_configure_mmap_sub(spibsc_instance_ctrl_t * p_ctrl,
                                           xspi_op_t const * const  rop) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static void spibsc_start_mmap_internal(spibsc_instance_ctrl_t * p_ctrl) BSP_PLACE_IN_SECTION(
    SPIBSC_CFG_CODE_SECTION);
static void      spibsc_test_tend(spibsc_instance_ctrl_t * p_ctrl) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static fsp_err_t spibsc_exec_op(spibsc_instance_ctrl_t * p_ctrl, xspi_op_t const * const op,
                                bool is_write) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static int spibsc_stop_mmap_internal(spibsc_instance_ctrl_t * p_ctrl) BSP_PLACE_IN_SECTION(
    SPIBSC_CFG_CODE_SECTION);
static fsp_err_t spibsc_configure_mmap(spibsc_instance_ctrl_t * p_ctrl) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static void      spibsc_select_spim(spibsc_instance_ctrl_t * p_ctrl) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static fsp_err_t spibsc_write_enable(spibsc_instance_ctrl_t * p_ctrl) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static void      spibsc_init_phy(spibsc_instance_ctrl_t * p_ctrl) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static void      spibsc_ip_init(spibsc_instance_ctrl_t * p_ctrl) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static uint32_t  spibsc_cmncr_set(uint8_t mask, uint8_t value, int pos) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static void      spibsc_set_idlelevel(spibsc_instance_ctrl_t * p_ctrl, const xspi_op_t * const op) BSP_PLACE_IN_SECTION(
    SPIBSC_CFG_CODE_SECTION);
static void test_sslf(spibsc_instance_ctrl_t * p_ctrl) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static void send_256(spibsc_instance_ctrl_t * p_ctrl, xspi_transfer_form_t form, uintptr_t buffer,
                     uint32_t smenr) BSP_PLACE_IN_SECTION(SPIBSC_CFG_CODE_SECTION);
static void send_4(spibsc_instance_ctrl_t * p_ctrl, uintptr_t buffer, uint32_t smenr) BSP_PLACE_IN_SECTION(
    SPIBSC_CFG_CODE_SECTION);
static void send_2(spibsc_instance_ctrl_t * p_ctrl, uintptr_t buffer, uint32_t smenr) BSP_PLACE_IN_SECTION(
    SPIBSC_CFG_CODE_SECTION);
static void send_1(spibsc_instance_ctrl_t * p_ctrl, uintptr_t buffer, uint32_t smenr) BSP_PLACE_IN_SECTION(
    SPIBSC_CFG_CODE_SECTION);
static void receive(spibsc_instance_ctrl_t * p_ctrl, uintptr_t buffer, uint32_t smenr) BSP_PLACE_IN_SECTION(
    SPIBSC_CFG_CODE_SECTION);
static void no_data(spibsc_instance_ctrl_t * p_ctrl, uintptr_t buffer, uint32_t smenr) BSP_PLACE_IN_SECTION(
    SPIBSC_CFG_CODE_SECTION);
static bool spibsc_stop_mmap_temporarily(spibsc_instance_ctrl_t * p_ctrl) BSP_PLACE_IN_SECTION(
    SPIBSC_CFG_CODE_SECTION);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
static const spibsc_mmap_cfg_t g_mmap_cfg[] =
{
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI, // 1-x-x
        SPI_FLASH_READ_MODE_STANDARD,    // 1-1-1 (Max 50MHz or above, depends on flash device)
        SPI_FLASH_ADDRESS_BYTES_3,       // 3-byte address

        SPI_FORM_1_1_1,
        0x03,
        3,
        0,
        0
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI, // 1-x-x
        SPI_FLASH_READ_MODE_STANDARD,    // 1-1-1 (Max 50MHz or above, depends on flash device)
        SPI_FLASH_ADDRESS_BYTES_4,       // 4-byte address (needs EN4B command or similar operation)

        SPI_FORM_1_1_1,
        0x03,
        4,
        0,
        0
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI,           // 1-x-x
        SPI_FLASH_READ_MODE_STANDARD,              // 1-1-1 (Max 50MHz or above, depends on flash device)
        SPI_FLASH_ADDRESS_BYTES_4_4BYTE_READ_CODE, // 4-byte address

        SPI_FORM_1_1_1,
        0x13,
        4,
        0,
        0
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI, // 1-x-x
        SPI_FLASH_READ_MODE_FAST_READ,   // 1-1-1 (Allows beyond 50MHz)
        SPI_FLASH_ADDRESS_BYTES_3,       // 3-byte address

        SPI_FORM_1_1_1,
        0x0B,
        3,
        0,
        8
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI, // 1-x-x
        SPI_FLASH_READ_MODE_FAST_READ,   // 1-1-1 (Allows beyond 50MHz)
        SPI_FLASH_ADDRESS_BYTES_4,       // 4-byte address (needs EN4B command or similar operation)

        SPI_FORM_1_1_1,
        0x0B,
        4,
        0,
        8
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI,           // 1-x-x
        SPI_FLASH_READ_MODE_FAST_READ,             // 1-1-1 (Allows beyond 50MHz)
        SPI_FLASH_ADDRESS_BYTES_4_4BYTE_READ_CODE, // 4-byte address

        SPI_FORM_1_1_1,
        0x0C,
        4,
        0,
        8
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI,           // 1-x-x
        SPI_FLASH_READ_MODE_FAST_READ_QUAD_OUTPUT, // x-1-4 (Allows beyond 50MHz)
        SPI_FLASH_ADDRESS_BYTES_3,                 // 3-byte address

        SPI_FORM_1_1_4,
        0x6B,
        3,
        0,
        8
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI,           // 1-x-x
        SPI_FLASH_READ_MODE_FAST_READ_QUAD_OUTPUT, // x-1-4 (Allows beyond 50MHz)
        SPI_FLASH_ADDRESS_BYTES_4,                 // 4-byte address (needs EN4B command or similar operation)

        SPI_FORM_1_1_4,
        0x6B,
        4,
        0,
        8
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI,           // 1-x-x
        SPI_FLASH_READ_MODE_FAST_READ_QUAD_OUTPUT, // x-1-4 (Allows beyond 50MHz)
        SPI_FLASH_ADDRESS_BYTES_4_4BYTE_READ_CODE, // 4-byte address

        SPI_FORM_1_1_4,
        0x6C,
        4,
        0,
        8
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI,       // 1-x-x
        SPI_FLASH_READ_MODE_FAST_READ_QUAD_IO, // x-4-4 (Allows beyond 50MHz)
        SPI_FLASH_ADDRESS_BYTES_3,             // 3-byte address

        SPI_FORM_1_4_4,
        0xEB,
        3,
        1,
        4
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI,       // 1-x-x
        SPI_FLASH_READ_MODE_FAST_READ_QUAD_IO, // x-4-4 (Allows beyond 50MHz)
        SPI_FLASH_ADDRESS_BYTES_4,             // 4-byte address (needs EN4B command or similar operation)

        SPI_FORM_1_4_4,
        0xEB,
        4,
        1,
        4
    },
    {
        SPI_FLASH_PROTOCOL_EXTENDED_SPI,           // 1-x-x
        SPI_FLASH_READ_MODE_FAST_READ_QUAD_IO,     // x-4-4 (Allows beyond 50MHz)
        SPI_FLASH_ADDRESS_BYTES_4_4BYTE_READ_CODE, // 4-byte address

        SPI_FORM_1_4_4,
        0xEC,
        4,
        1,
        4
    },
};

static const uint32_t cmncr_init_mask =
    R_SPIBSC_CMNCR_BSZ_Msk |
    R_SPIBSC_CMNCR_IO0FV_Msk |
    R_SPIBSC_CMNCR_IO2FV_Msk |
    R_SPIBSC_CMNCR_IO3FV_Msk |
    R_SPIBSC_CMNCR_MOIIO0_Msk |
    R_SPIBSC_CMNCR_MOIIO1_Msk |
    R_SPIBSC_CMNCR_MOIIO2_Msk |
    R_SPIBSC_CMNCR_MOIIO3_Msk;

/* IOn maintained as Hi-Z at idle
 * IO0 Value sets Hi-Z while dummy and 1-bit read transfer phase
 * IO2/IO3 Value sets high while 1-bit command/address/additional-data phase
 */
static const uint32_t cmncr_init_value =
    1U << R_SPIBSC_CMNCR_MD_Pos |
        SPIBSC_CMNCR_BSZ_SINGLE << R_SPIBSC_CMNCR_BSZ_Pos |
        SPIBSC_CMNCR_IO_HIZ << R_SPIBSC_CMNCR_IO0FV_Pos |
        SPIBSC_CMNCR_IO_HIGH << R_SPIBSC_CMNCR_IO2FV_Pos |
        SPIBSC_CMNCR_IO_HIGH << R_SPIBSC_CMNCR_IO3FV_Pos |
        SPIBSC_CMNCR_IO_HIZ << R_SPIBSC_CMNCR_MOIIO0_Pos |
        SPIBSC_CMNCR_IO_HIZ << R_SPIBSC_CMNCR_MOIIO1_Pos |
        SPIBSC_CMNCR_IO_HIZ << R_SPIBSC_CMNCR_MOIIO2_Pos |
        SPIBSC_CMNCR_IO_HIZ << R_SPIBSC_CMNCR_MOIIO3_Pos;

static const uint32_t ssldr_init_mask =
    R_SPIBSC_SSLDR_SCKDL_Msk |
    R_SPIBSC_SSLDR_SLNDL_Msk |
    R_SPIBSC_SSLDR_SPNDL_Msk;

static const uint32_t ssldr_init_value =
    0U << R_SPIBSC_SSLDR_SCKDL_Pos |
        0U << R_SPIBSC_SSLDR_SLNDL_Pos |
        0U << R_SPIBSC_SSLDR_SPNDL_Pos;

static const uint32_t drcr_init_mask =
    R_SPIBSC_DRCR_RBURST_Msk |
    R_SPIBSC_DRCR_RCF_Msk |
    R_SPIBSC_DRCR_RBE_Msk |
    R_SPIBSC_DRCR_SSLE_Msk;

static const uint32_t drcr_init_value =
    7U << R_SPIBSC_DRCR_RBURST_Pos |
        1U << R_SPIBSC_DRCR_RCF_Pos |
        1U << R_SPIBSC_DRCR_RBE_Pos |
        1U << R_SPIBSC_DRCR_SSLE_Pos;

static const uint32_t drear_init_mask =
    R_SPIBSC_DREAR_EAC_Msk |
    R_SPIBSC_DREAR_EAV_Msk;

static const uint32_t drear_init_value =
    3U << R_SPIBSC_DREAR_EAC_Pos |
        0U << R_SPIBSC_DREAR_EAV_Pos;

static const uint32_t drdrenr_init_mask =
    R_SPIBSC_DRDRENR_ADDRE_Msk |
    R_SPIBSC_DRDRENR_OPDRE_Msk |
    R_SPIBSC_DRDRENR_DRDRE_Msk;

static const uint32_t drdrenr_init_value =
    0U << R_SPIBSC_DRDRENR_ADDRE_Pos |
        0U << R_SPIBSC_DRDRENR_OPDRE_Pos |
        0U << R_SPIBSC_DRDRENR_DRDRE_Pos;

static const uint32_t phycnt_init_mask =
    R_SPIBSC_PHYCNT_CAL_Msk |
    R_SPIBSC_PHYCNT_CKSEL_Msk |
    R_SPIBSC_PHYCNT_HS_Msk |
    R_SPIBSC_PHYCNT_PHYMEM_Msk |
    R_SPIBSC_PHYCNT_WBUF2_Msk |
    R_SPIBSC_PHYCNT_WBUF_Msk;

static const uint32_t phycnt_init_value =
    0U << R_SPIBSC_PHYCNT_CAL_Pos |
        0U << R_SPIBSC_PHYCNT_CKSEL_Pos |
        0U << R_SPIBSC_PHYCNT_HS_Pos |
        0U << R_SPIBSC_PHYCNT_PHYMEM_Pos |
        0U << R_SPIBSC_PHYCNT_WBUF2_Pos |
        0U << R_SPIBSC_PHYCNT_WBUF_Pos;

static const uint32_t phyoffset1_init_mask = R_SPIBSC_PHYOFFSET1_DDRTMG_Msk;

static const uint32_t phyoffset1_init_value = SPIBSC_PHYOFFSET1_SDR << R_SPIBSC_PHYOFFSET1_DDRTMG_Pos;

static const uint32_t phyoffset2_init_mask = R_SPIBSC_PHYOFFSET2_OCTTMG_Msk;

static const uint32_t phyoffset2_init_value = SPIBSC_PHYOFFSET2_SPI << R_SPIBSC_PHYOFFSET2_OCTTMG_Pos;

static const uint32_t smcmr_clearmask =
    R_SPIBSC_SMCMR_CMD_Msk |
    R_SPIBSC_SMCMR_OCMD_Msk;

static const uint32_t smenr_clearmask =
    R_SPIBSC_SMENR_ADB_Msk |
    R_SPIBSC_SMENR_ADE_Msk |
    R_SPIBSC_SMENR_CDB_Msk |
    R_SPIBSC_SMENR_CDE_Msk |
    R_SPIBSC_SMENR_DME_Msk |
    R_SPIBSC_SMENR_SPIDB_Msk |
    R_SPIBSC_SMENR_OCDB_Msk |
    R_SPIBSC_SMENR_OCDE_Msk |
    R_SPIBSC_SMENR_OPDB_Msk |
    R_SPIBSC_SMENR_OPDE_Msk |
    R_SPIBSC_SMENR_SPIDE_Msk;

static const uint32_t smdrenr_clearmask =
    R_SPIBSC_SMDRENR_ADDRE_Msk |
    R_SPIBSC_SMDRENR_SPIDRE_Msk |
    R_SPIBSC_SMDRENR_OPDRE_Msk;

static const uint32_t smdmcr_clearmask =
    R_SPIBSC_SMDMCR_DMCYC_Msk;

static const uint32_t ssldr_clearmask =
    R_SPIBSC_SSLDR_SCKDL_Msk |
    R_SPIBSC_SSLDR_SLNDL_Msk |
    R_SPIBSC_SSLDR_SPNDL_Msk;

/* SMENR value for 1-1-1 command */
static const uint32_t smenr_form_111 =
    SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_CDB_Pos |
        SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_OCDB_Pos |
        SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_ADB_Pos |
        SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_OPDB_Pos |
        SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_SPIDB_Pos;

/* SMENR value for 1-1-4 command */
static const uint32_t smenr_form_114 =
    SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_CDB_Pos |
        SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_OCDB_Pos |
        SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_ADB_Pos |
        SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_OPDB_Pos |
        SPIBSC_SMENR_DB_4BIT << R_SPIBSC_SMENR_SPIDB_Pos;

/* SMENR value for 1-4-4 command */
static const uint32_t smenr_form_144 =
    SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_CDB_Pos |
        SPIBSC_SMENR_DB_1BIT << R_SPIBSC_SMENR_OCDB_Pos |
        SPIBSC_SMENR_DB_4BIT << R_SPIBSC_SMENR_ADB_Pos |
        SPIBSC_SMENR_DB_4BIT << R_SPIBSC_SMENR_OPDB_Pos |
        SPIBSC_SMENR_DB_4BIT << R_SPIBSC_SMENR_SPIDB_Pos;

/* SMENR value for no opcode */
static const uint32_t smenr_op_none =
    0U << R_SPIBSC_SMENR_CDE_Pos |
        0U << R_SPIBSC_SMENR_OCDE_Pos;

/* SMENR value for 1-byte opcode */
static const uint32_t smenr_op_1byte =
    1U << R_SPIBSC_SMENR_CDE_Pos |
        0U << R_SPIBSC_SMENR_OCDE_Pos;

/* SMENR value for 2-byte opcode */
static const uint32_t smenr_op_2byte =
    1U << R_SPIBSC_SMENR_CDE_Pos |
        1U << R_SPIBSC_SMENR_OCDE_Pos;

/* SMENR value for no address */
static const uint32_t smenr_addr_none =
    SPIBSC_SMENR_ADE_NONE << R_SPIBSC_SMENR_ADE_Pos;

/* SMENR value for 3-byte address */
static const uint32_t smenr_addr_3byte =
    SPIBSC_SMENR_ADE_3BYTE << R_SPIBSC_SMENR_ADE_Pos;

/* SMENR value for 4-byte address */
static const uint32_t smenr_addr_4byte =
    SPIBSC_SMENR_ADE_4BYTE << R_SPIBSC_SMENR_ADE_Pos;

/* SMENR value for no additional data */
static const uint32_t smenr_additional_none =
    SPIBSC_SMENR_OPDE_NONE << R_SPIBSC_SMENR_OPDE_Pos;

/* SMENR value for 1-byte additional data */
static const uint32_t smenr_additional_1byte =
    SPIBSC_SMENR_OPDE_1BYTE << R_SPIBSC_SMENR_OPDE_Pos;

/* SMENR value for 2-byte additional data */
static const uint32_t smenr_additional_2byte =
    SPIBSC_SMENR_OPDE_2BYTE << R_SPIBSC_SMENR_OPDE_Pos;

/* SMENR value for 3-byte additional data */
static const uint32_t smenr_additional_3byte =
    SPIBSC_SMENR_OPDE_3BYTE << R_SPIBSC_SMENR_OPDE_Pos;

/* SMENR value for 4-byte additional data */
static const uint32_t smenr_additional_4byte =
    SPIBSC_SMENR_OPDE_4BYTE << R_SPIBSC_SMENR_OPDE_Pos;

static const uint32_t drcmr_clearmask =
    R_SPIBSC_DRCMR_CMD_Msk |
    R_SPIBSC_DRCMR_OCMD_Msk;

static const uint32_t drenr_clearmask =
    R_SPIBSC_DRENR_ADB_Msk |
    R_SPIBSC_DRENR_ADE_Msk |
    R_SPIBSC_DRENR_CDB_Msk |
    R_SPIBSC_DRENR_CDE_Msk |
    R_SPIBSC_DRENR_DME_Msk |
    R_SPIBSC_DRENR_DRDB_Msk |
    R_SPIBSC_DRENR_OCDB_Msk |
    R_SPIBSC_DRENR_OCDE_Msk |
    R_SPIBSC_DRENR_OPDB_Msk |
    R_SPIBSC_DRENR_OPDE_Msk;

static const uint32_t drdrenr_clearmask =
    R_SPIBSC_DRDRENR_ADDRE_Msk |
    R_SPIBSC_DRDRENR_DRDRE_Msk |
    R_SPIBSC_DRDRENR_OPDRE_Msk;

static const uint32_t drdmcr_clearmask =
    R_SPIBSC_DRDMCR_DMCYC_Msk;

/* DRENR value for 1-1-1 command */
static const uint32_t drenr_form_111 =
    SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_CDB_Pos |
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_OCDB_Pos |
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_ADB_Pos |
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_OPDB_Pos |
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_DRDB_Pos;

/* DRENR value for 1-1-4 command */
static const uint32_t drenr_form_114 =
    SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_CDB_Pos |
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_OCDB_Pos |
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_ADB_Pos |
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_OPDB_Pos |
        SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_DRDB_Pos;

/* DRENR value for 1-4-4 command */
static const uint32_t drenr_form_144 =
    SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_CDB_Pos |
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_OCDB_Pos |
        SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_ADB_Pos |
        SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_OPDB_Pos |
        SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_DRDB_Pos;

/* DRENR value for no opcode */
static const uint32_t drenr_op_none =
    0U << R_SPIBSC_DRENR_CDE_Pos |
        0U << R_SPIBSC_DRENR_OCDE_Pos;

/* DRENR value for 1-byte opcode */
static const uint32_t drenr_op_1byte =
    1U << R_SPIBSC_DRENR_CDE_Pos |
        0U << R_SPIBSC_DRENR_OCDE_Pos;

/* DRENR value for 2-byte opcode */
static const uint32_t drenr_op_2byte =
    1U << R_SPIBSC_DRENR_CDE_Pos |
        1U << R_SPIBSC_DRENR_OCDE_Pos;

/* DRENR value for no address */
static const uint32_t drenr_addr_none =
    SPIBSC_DRENR_ADE_NONE << R_SPIBSC_DRENR_ADE_Pos;

/* DRENR value for 3-byte address */
static const uint32_t drenr_addr_3byte =
    SPIBSC_DRENR_ADE_3BYTE << R_SPIBSC_DRENR_ADE_Pos;

/* DRENR value for 4-byte address */
static const uint32_t drenr_addr_4byte =
    SPIBSC_DRENR_ADE_4BYTE << R_SPIBSC_DRENR_ADE_Pos;

/* DRENR value for no additional data */
static const uint32_t drenr_additional_none =
    SPIBSC_DRENR_OPDE_NONE << R_SPIBSC_DRENR_OPDE_Pos;

/* DRENR value for 1-byte additional data */
static const uint32_t drenr_additional_1byte =
    SPIBSC_DRENR_OPDE_1BYTE << R_SPIBSC_DRENR_OPDE_Pos;

/* DRENR value for 2-byte additional data */
static const uint32_t drenr_additional_2byte =
    SPIBSC_DRENR_OPDE_2BYTE << R_SPIBSC_DRENR_OPDE_Pos;

/* DRENR value for 3-byte additional data */
static const uint32_t drenr_additional_3byte =
    SPIBSC_DRENR_OPDE_3BYTE << R_SPIBSC_DRENR_OPDE_Pos;

/* DRENR value for 4-byte additional data */
static const uint32_t drenr_additional_4byte =
    SPIBSC_DRENR_OPDE_4BYTE << R_SPIBSC_DRENR_OPDE_Pos;

/*******************************************************************************************************************//**
 * @addtogroup SPIBSC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

const spi_flash_api_t g_spi_flash_on_spibsc =
{
    .open           = R_SPIBSC_Open,
    .directWrite    = R_SPIBSC_DirectWrite,
    .directRead     = R_SPIBSC_DirectRead,
    .directTransfer = R_SPIBSC_DirectTransfer,
    .spiProtocolSet = R_SPIBSC_SpiProtocolSet,
    .write          = R_SPIBSC_Write,
    .erase          = R_SPIBSC_Erase,
    .statusGet      = R_SPIBSC_StatusGet,
    .xipEnter       = R_SPIBSC_XipEnter,
    .xipExit        = R_SPIBSC_XipExit,
    .bankSet        = R_SPIBSC_BankSet,
    .autoCalibrate  = R_SPIBSC_AutoCalibrate,
    .close          = R_SPIBSC_Close,
};

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Open the SPIBSC driver module.
 *
 * Implements @ref spi_flash_api_t::open.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       The parameter p_api_ctrl or p_cfg is NULL.
 * @retval FSP_ERR_UNSUPPORTED     One or more parameters in p_cfg are not supported by this implementation.
 * @retval FSP_ERR_OUT_OF_MEMORY   Memory allocation error.
 * @retval FSP_ERR_INVALID_SIZE    Page size is not specified.
 * @retval FSP_ERR_INVALID_POINTER Pointer points to invalid memory location.
 * @retval FSP_ERR_INVALID_MODE    This function can't be called when XIP mode is enabled.
 * @retval FSP_ERR_ALREADY_OPEN    Driver has already been opened with the same p_api_ctrl.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_Open (spi_flash_ctrl_t * p_api_ctrl, spi_flash_cfg_t const * const p_cfg)
{
    spibsc_instance_ctrl_t * p_ctrl = (spibsc_instance_ctrl_t *) p_api_ctrl;
    spibsc_instance_ctrl_t   ctrl;

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_api_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(SPIBSC_PRV_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Check configuration parameters */
    FSP_ERROR_RETURN(
        SPI_FLASH_DATA_LINES_1 == p_cfg->page_program_address_lines || SPI_FLASH_DATA_LINES_4 == p_cfg->page_program_address_lines,
        FSP_ERR_UNSUPPORTED);
    FSP_ERROR_RETURN((!p_cfg->page_program_command) || p_cfg->page_size_bytes, FSP_ERR_INVALID_SIZE)
    FSP_ERROR_RETURN((!p_cfg->erase_command_list_length) || p_cfg->p_erase_command_list, FSP_ERR_INVALID_POINTER)
#endif

    /* Duplicate erase command table */
    void * p_erase_list     = NULL;
    size_t erase_list_bytes = sizeof(spi_flash_erase_command_t) * p_cfg->erase_command_list_length;
    if (erase_list_bytes)
    {
        p_erase_list = malloc(erase_list_bytes);
        FSP_ERROR_RETURN(p_erase_list, FSP_ERR_OUT_OF_MEMORY);
        memcpy(p_erase_list, p_cfg->p_erase_command_list, erase_list_bytes);
    }

    fsp_err_t result = FSP_SUCCESS;

    /* Initialize instance control datas */
    ctrl     = *p_ctrl;
    ctrl.cfg = *p_cfg;
    ctrl.ext = *(spibsc_extended_cfg_t *) p_cfg->p_extend;
    ctrl.p_erase_command_list = (spi_flash_erase_command_t *) p_erase_list;
    ctrl.open                 = SPIBSC_PRV_OPEN;
    ctrl.is_xip_enabled       = false;
    ctrl.p_reg                = R_SPIBSC;

    if (!SPIBSC_CFG_ALREADY_INITIALIZED)
    {
        /* Initializes the SPIBSC for enabling memory-mapped (external address reading) access mode */
        result = spibsc_configure_mmap(&ctrl);
    }
    else
    {
        /* Obtaining the XIP (Suppressing the operation code phase) status from SPIBSC register */
        uint32_t drenr = MMIO_READ_32(p_ctrl->p_reg->DRENR);
        drenr &=
            (R_SPIBSC_DRENR_ADB_Msk | R_SPIBSC_DRENR_OPDB_Msk | R_SPIBSC_DRENR_DRDB_Msk | R_SPIBSC_DRENR_DME_Msk |
             R_SPIBSC_DRENR_CDE_Msk | R_SPIBSC_DRENR_OPDE_Msk);
        static const uint32_t drenr_expected = SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_ADB_Pos | SPIBSC_DRENR_DB_4BIT <<
                                               R_SPIBSC_DRENR_OPDB_Pos | SPIBSC_DRENR_DB_4BIT <<
                                               R_SPIBSC_DRENR_DRDB_Pos | R_SPIBSC_DRENR_DME_Msk |
                                               SPIBSC_DRENR_OPDE_1BYTE << R_SPIBSC_DRENR_OPDE_Pos;
        if (drenr == drenr_expected)
        {
            ctrl.is_xip_enabled = true;
        }
    }

    if (result != FSP_SUCCESS)
    {
        /* Cleanup allocated memory */
        if (ctrl.p_erase_command_list)
        {
            free(ctrl.p_erase_command_list);
        }
    }

    FSP_ERROR_RETURN(result == FSP_SUCCESS, result);

    /* Overwrite new instance ctrl object */
    *p_ctrl = ctrl;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * DEPRECATED: Writes raw data directly to the flash device.
 *
 * Implements @ref spi_flash_api_t::directWrite.
 *
 * @note After sending operations that change its contents, it may be inconsistent with cached contents.
 * @warning Its behavior is not guaranteed if the caller and/or the callee are stored in the same device
 *           you are trying to change its contents.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_UNSUPPORTED         Read-after-write is not supported by this implementation.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_DirectWrite (spi_flash_ctrl_t    * p_api_ctrl,
                                uint8_t const * const p_src,
                                uint32_t const        bytes,
                                bool const            read_after_write)
{
    spibsc_instance_ctrl_t * p_ctrl = (spibsc_instance_ctrl_t *) p_api_ctrl;

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(NULL != p_src);
    FSP_ASSERT(bytes > 0);
    FSP_ERROR_RETURN(SPIBSC_PRV_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    FSP_ERROR_RETURN(read_after_write == false, FSP_ERR_UNSUPPORTED);
    FSP_ERROR_RETURN(p_ctrl->is_xip_enabled == false, FSP_ERR_INVALID_MODE);

    xspi_op_t op;
    op.clsh_value             = p_ctrl->ext.delay.clsh;
    op.shsl_value             = p_ctrl->ext.delay.shsl;
    op.slch_value             = p_ctrl->ext.delay.slch;
    op.force_idle_level_mask  = p_ctrl->ext.io_fix_mask;
    op.force_idle_level_value = p_ctrl->ext.io_fix_value;
    op.transfer_buffer        = (void *) p_src;
    op.transfer_size          = bytes;
    op.additional_size        = 0;
    op.additional_value       = 0;
    op.address                = 0;
    op.address_size           = 0;
    op.dummy_cycles           = 0;
    switch (p_ctrl->cfg.spi_protocol)
    {
        case SPI_FLASH_PROTOCOL_EXTENDED_SPI:
        {
            op.form = SPI_FORM_1_1_1;
            break;
        }

        default:
        {
            FSP_ERROR_RETURN(p_ctrl->cfg.spi_protocol == SPI_FLASH_PROTOCOL_EXTENDED_SPI, FSP_ERR_UNSUPPORTED);
            break;
        }
    }

    fsp_err_t result = spibsc_exec_op(p_ctrl, &op, true);
    FSP_ERROR_RETURN(result == FSP_SUCCESS, result);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads raw data directly from the flash device. Unsupported by SPIBSC.
 *
 * Implements @ref spi_flash_api_t::directRead.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by SPIBSC.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_DirectRead (spi_flash_ctrl_t * p_api_ctrl, uint8_t * const p_dest, uint32_t const bytes)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_dest);
    FSP_PARAMETER_NOT_USED(bytes);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Read/Write raw data directly with the flash device.
 *
 * Implements @ref spi_flash_api_t::directTransfer.
 *
 * @note After sending operations that change its contents, it may be inconsistent with cached contents.
 * @warning Its behavior is not guaranteed if the caller and/or the callee are stored in the same device
 *           you are trying to change its contents.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_DirectTransfer (spi_flash_ctrl_t                  * p_api_ctrl,
                                   spi_flash_direct_transfer_t * const p_transfer,
                                   spi_flash_direct_transfer_dir_t     direction)
{
    spibsc_instance_ctrl_t * p_ctrl = (spibsc_instance_ctrl_t *) p_api_ctrl;

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_transfer);
    FSP_ERROR_RETURN(SPIBSC_PRV_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    FSP_ERROR_RETURN(p_ctrl->is_xip_enabled == false, FSP_ERR_INVALID_MODE);

    xspi_op_t op;
    memset(&op, 0, sizeof(op));
    op.clsh_value             = p_ctrl->ext.delay.clsh;
    op.shsl_value             = p_ctrl->ext.delay.shsl;
    op.slch_value             = p_ctrl->ext.delay.slch;
    op.force_idle_level_mask  = p_ctrl->ext.io_fix_mask;
    op.force_idle_level_value = p_ctrl->ext.io_fix_value;
    op.op              = p_transfer->command;
    op.op_size         = p_transfer->command_length;
    op.address         = p_transfer->address;
    op.address_size    = p_transfer->address_length;
    op.dummy_cycles    = p_transfer->dummy_cycles;
    op.transfer_buffer = &p_transfer->data;
    op.transfer_size   = p_transfer->data_length;
    op.form            = SPI_FORM_1_1_1;
    bool      is_write = (SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE == direction);
    fsp_err_t result   = spibsc_exec_op(p_ctrl, &op, is_write);

    FSP_ERROR_RETURN(result == FSP_SUCCESS, result);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enters XIP (execute in place) mode.
 *
 * Implements @ref spi_flash_api_t::xipEnter.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when already enabled or not 4-bit transfer.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_XipEnter (spi_flash_ctrl_t * p_api_ctrl)
{
    spibsc_instance_ctrl_t * p_ctrl = (spibsc_instance_ctrl_t *) p_api_ctrl;

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(SPIBSC_PRV_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    FSP_ERROR_RETURN(!p_ctrl->is_xip_enabled, FSP_ERR_INVALID_MODE);

    uint32_t drenr = MMIO_READ_32(p_ctrl->p_reg->DRENR) & (uint32_t) ~R_SPIBSC_SMENR_SPIDE_Msk;

    /*** Check if ready or not ***/
    /* Address phase must 4-bit */
    FSP_ERROR_RETURN(((drenr & R_SPIBSC_DRENR_ADB_Msk) >> R_SPIBSC_DRENR_ADB_Pos) == SPIBSC_DRENR_DB_4BIT,
                     FSP_ERR_INVALID_MODE);

    /* Stop memory-mapped read mode */
    spibsc_stop_mmap_internal(p_ctrl);

    /* Optional data */
    uint32_t opr = (uint32_t) p_ctrl->cfg.xip_enter_command << R_SPIBSC_SMOPR_OPD3_Pos;
    MMIO_WRITE_32(p_ctrl->p_reg->DROPR, opr);
    MMIO_WRITE_32(p_ctrl->p_reg->SMOPR, opr);

    /* Clone settings */
    MMIO_WRITE_32(p_ctrl->p_reg->SMCMR, MMIO_READ_32(p_ctrl->p_reg->DRCMR));
    MMIO_WRITE_32(p_ctrl->p_reg->SMENR, drenr | SPIBSC_SMENR_SPIDE_LONG << R_SPIBSC_SMENR_SPIDE_Pos);
    MMIO_WRITE_32(p_ctrl->p_reg->SMDMCR, MMIO_READ_32(p_ctrl->p_reg->DRDMCR));
    MMIO_WRITE_32(p_ctrl->p_reg->SMDRENR, MMIO_READ_32(p_ctrl->p_reg->DRDRENR));

    /* Execute command for start flash's XIP mode (suppressing op-code) */
    MMIO_WRITE_32(p_ctrl->p_reg->SMCR, R_SPIBSC_SMCR_SPIRE_Msk | R_SPIBSC_SMCR_SPIE_Msk);

    /* Wait complete (Read data will ignored) */
    spibsc_test_tend(p_ctrl);

    /* Set suppressing the op-code for memory-mapped read */
    drenr &= (uint32_t) ~R_SPIBSC_DRENR_CDE_Msk;
    MMIO_WRITE_32(p_ctrl->p_reg->DRENR, drenr);

    /* Change xip state */
    p_ctrl->is_xip_enabled = true;

    /* Enabling memory-mapped read mode */
    spibsc_start_mmap_internal(p_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Exits XIP (execute in place) mode.
 *
 * Implements @ref spi_flash_api_t::xipExit.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_XipExit (spi_flash_ctrl_t * p_api_ctrl)
{
    spibsc_instance_ctrl_t * p_ctrl = (spibsc_instance_ctrl_t *) p_api_ctrl;

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(SPIBSC_PRV_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    FSP_ERROR_RETURN(p_ctrl->is_xip_enabled, FSP_ERR_INVALID_MODE);

    /* Stop memory-mapped read mode */
    spibsc_stop_mmap_internal(p_ctrl);

    /* Optional data */
    uint32_t opr = (uint32_t) p_ctrl->cfg.xip_exit_command << R_SPIBSC_SMOPR_OPD3_Pos;
    MMIO_WRITE_32(p_ctrl->p_reg->DROPR, opr);
    MMIO_WRITE_32(p_ctrl->p_reg->SMOPR, opr);

    /* Clone settings */
    uint32_t drenr = MMIO_READ_32(p_ctrl->p_reg->DRENR);
    MMIO_WRITE_32(p_ctrl->p_reg->SMCMR, MMIO_READ_32(p_ctrl->p_reg->DRCMR));
    MMIO_WRITE_32(p_ctrl->p_reg->SMENR, drenr);
    MMIO_WRITE_32(p_ctrl->p_reg->SMDMCR, MMIO_READ_32(p_ctrl->p_reg->DRDMCR));
    MMIO_WRITE_32(p_ctrl->p_reg->SMDRENR, MMIO_READ_32(p_ctrl->p_reg->DRDRENR));

    /* Execute command for stop flash's XIP mode (enabling op-code) */
    MMIO_WRITE_32(p_ctrl->p_reg->SMCR, R_SPIBSC_SMCR_SPIRE_Msk | R_SPIBSC_SMCR_SPIE_Msk);

    /* Wait complete (Read data will ignored) */
    spibsc_test_tend(p_ctrl);

    /* Set enabling op-code for memory-mapped read */
    drenr |= R_SPIBSC_DRENR_CDE_Msk;
    MMIO_WRITE_32(p_ctrl->p_reg->DRENR, drenr);

    /* Enabling memory-mapped read mode */
    spibsc_start_mmap_internal(p_ctrl);

    /* Change xip state */
    p_ctrl->is_xip_enabled = false;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Program a page of data to the flash.
 *
 * Implements @ref spi_flash_api_t::write.
 *
 * @note After writing, it may be inconsistent with cached contents.
 * @warning Its behavior is not guaranteed if the caller and/or the callee are stored in the same device
 *           you are writing.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           p_api_ctrl, p_dest or p_src is NULL, or byte_count crosses a page boundary.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_Write (spi_flash_ctrl_t    * p_api_ctrl,
                          uint8_t const * const p_src,
                          uint8_t * const       p_dest,
                          uint32_t              byte_count)
{
    spibsc_instance_ctrl_t * p_ctrl = (spibsc_instance_ctrl_t *) p_api_ctrl;

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_src);
    FSP_ASSERT(p_dest);
    FSP_ERROR_RETURN(SPIBSC_PRV_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    FSP_ERROR_RETURN(p_ctrl->is_xip_enabled == false, FSP_ERR_INVALID_MODE);

    /* Enable write */
    fsp_err_t result = spibsc_write_enable(p_ctrl);
    FSP_ERROR_RETURN(result == FSP_SUCCESS, result);

    uint32_t chip_address = (uint32_t) ((ptrdiff_t) p_dest - (ptrdiff_t) SPIBSC_CFG_MMAP_BASE);

    /* Make operation structure */
    xspi_op_t op;
    memset(&op, 0, sizeof(op));
    op.clsh_value             = p_ctrl->ext.delay.clsh;
    op.shsl_value             = p_ctrl->ext.delay.shsl;
    op.slch_value             = p_ctrl->ext.delay.slch;
    op.force_idle_level_mask  = p_ctrl->ext.io_fix_mask;
    op.force_idle_level_value = p_ctrl->ext.io_fix_value;
    op.op      = p_ctrl->cfg.page_program_command;
    op.op_size = 1;
    op.address = chip_address;
    switch (p_ctrl->cfg.address_bytes)
    {
        case SPI_FLASH_ADDRESS_BYTES_4:                 // As 4-byte, fall through
        case SPI_FLASH_ADDRESS_BYTES_4_4BYTE_READ_CODE: // Also as 4-byte
        {
            op.address_size = 4;
            break;
        }

        case SPI_FLASH_ADDRESS_BYTES_3: // As 4-byte, fall through
        {
            op.address_size = 3;
            break;
        }

        default:                       // Invalid
            FSP_ERROR_RETURN(false, FSP_ERR_INVALID_MODE);
    }

    op.transfer_buffer = (void *) p_src;
    op.transfer_size   = byte_count;
    switch (p_ctrl->cfg.page_program_address_lines)
    {
        case SPI_FLASH_DATA_LINES_1:                            // As 1-bit. The transfer phase is same as "Read Mode" setting.
        {
            switch (p_ctrl->cfg.read_mode)
            {
                case SPI_FLASH_READ_MODE_FAST_READ_QUAD_OUTPUT: // 4-bit transfer, fall through
                case SPI_FLASH_READ_MODE_FAST_READ_QUAD_IO:     // 4-bit transfer, fall through
                {
                    op.form = SPI_FORM_1_1_4;
                    break;
                }

                default:               // 1-bit for others. (2-bit is blocked on open API)
                {
                    op.form = SPI_FORM_1_1_1;
                    break;
                }
            }

            break;
        }

        case SPI_FLASH_DATA_LINES_4:   // As 4-bit. The transfer phase also becomes 4-bit
        {
            op.form = SPI_FORM_1_4_4;
            break;
        }

        default:                       // Invalid
            FSP_ERROR_RETURN(false, FSP_ERR_INVALID_MODE);
    }

    /* Execute operation */
    bool is_write = true;
    result = spibsc_exec_op(p_ctrl, &op, is_write);

    FSP_ERROR_RETURN(result == FSP_SUCCESS, result);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Erase a block or sector of flash.  The byte_count must exactly match one of the erase sizes defined in spi_flash_cfg_t.
 * For chip erase, byte_count must be SPI_FLASH_ERASE_SIZE_CHIP_ERASE.
 *
 * Implements @ref spi_flash_api_t::erase.
 *
 * @note After erasing, it may be inconsistent with cached contents.
 * @warning Its behavior is not guaranteed if the caller and/or the callee are stored in the same device
 *           you are erasing.
 *
 * @retval FSP_SUCCESS                 The command to erase the flash was executed successfully.
 * @retval FSP_ERR_ASSERTION           p_api_ctrl or p_device_address is NULL, or byte_count doesn't match an erase
 *                                     size defined in spi_flash_cfg_t, or device is in XIP mode.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_Erase (spi_flash_ctrl_t * p_api_ctrl, uint8_t * const p_device_address, uint32_t byte_count)
{
    spibsc_instance_ctrl_t * p_ctrl = (spibsc_instance_ctrl_t *) p_api_ctrl;

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(NULL != p_device_address);
    FSP_ERROR_RETURN(SPIBSC_PRV_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    FSP_ERROR_RETURN(p_ctrl->is_xip_enabled == false, FSP_ERR_INVALID_MODE);

    /* Enable write */
    fsp_err_t result = spibsc_write_enable(p_ctrl);
    FSP_ERROR_RETURN(result == FSP_SUCCESS, result);

    uint16_t erase_command = 0;
    uint32_t chip_address  = (uint32_t) ((ptrdiff_t) p_device_address - (ptrdiff_t) SPIBSC_CFG_MMAP_BASE);
    bool     send_address  = true;

    for (uint32_t index = 0; index < p_ctrl->cfg.erase_command_list_length; index++)
    {
        /* If requested byte_count is supported by underlying flash, store the command. */
        if (byte_count == p_ctrl->cfg.p_erase_command_list[index].size)
        {
            if (SPI_FLASH_ERASE_SIZE_CHIP_ERASE == byte_count)
            {
                /* Don't send address for chip erase. */
                send_address = false;
            }

            erase_command = p_ctrl->cfg.p_erase_command_list[index].command;
            break;
        }
    }

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(0U != erase_command);
#endif

    /* Make operation structure */
    xspi_op_t op;
    memset(&op, 0, sizeof(op));
    op.clsh_value             = p_ctrl->ext.delay.clsh;
    op.shsl_value             = p_ctrl->ext.delay.shsl;
    op.slch_value             = p_ctrl->ext.delay.slch;
    op.force_idle_level_mask  = p_ctrl->ext.io_fix_mask;
    op.force_idle_level_value = p_ctrl->ext.io_fix_value;
    op.op      = erase_command;
    op.op_size = 1;
    op.address = chip_address;
    if (send_address)
    {
        switch (p_ctrl->cfg.address_bytes)
        {
            case SPI_FLASH_ADDRESS_BYTES_4:                 // As 4-byte, fall through
            case SPI_FLASH_ADDRESS_BYTES_4_4BYTE_READ_CODE: // Also as 4-byte
            {
                op.address_size = 4;
                break;
            }

            case SPI_FLASH_ADDRESS_BYTES_3: // As 4-byte, fall through
            {
                op.address_size = 3;
                break;
            }

            default:                   // Invalid
                FSP_ERROR_RETURN(false, FSP_ERR_INVALID_MODE);
        }
    }

    op.form = SPI_FORM_1_1_1;

    /* Execute operation */
    bool is_write = false;
    result = spibsc_exec_op(p_ctrl, &op, is_write);

    FSP_ERROR_RETURN(result == FSP_SUCCESS, result);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Gets the write or erase status of the flash.
 *
 * Implements @ref spi_flash_api_t::statusGet.
 *
 * @retval FSP_SUCCESS                 The write status is in p_status.
 * @retval FSP_ERR_ASSERTION           p_api_ctrl or p_status is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_StatusGet (spi_flash_ctrl_t * p_api_ctrl, spi_flash_status_t * const p_status)
{
    spibsc_instance_ctrl_t * p_ctrl = (spibsc_instance_ctrl_t *) p_api_ctrl;
    uint8_t status;

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(SPIBSC_PRV_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    FSP_ERROR_RETURN(p_ctrl->is_xip_enabled == false, FSP_ERR_INVALID_MODE);

    /* Make operation structure */
    xspi_op_t op;
    memset(&op, 0, sizeof(op));
    op.clsh_value             = p_ctrl->ext.delay.clsh;
    op.shsl_value             = p_ctrl->ext.delay.shsl;
    op.slch_value             = p_ctrl->ext.delay.slch;
    op.force_idle_level_mask  = p_ctrl->ext.io_fix_mask;
    op.force_idle_level_value = p_ctrl->ext.io_fix_value;
    op.op              = p_ctrl->cfg.status_command;
    op.op_size         = 1;
    op.form            = SPI_FORM_1_1_1;
    op.transfer_buffer = &status;
    op.transfer_size   = 1;

    bool      is_write = false;
    fsp_err_t result   = spibsc_exec_op(p_ctrl, &op, is_write);
    FSP_ERROR_RETURN(result == FSP_SUCCESS, result);

    /* Check the status and store it */
    uint8_t target = 1U << p_ctrl->cfg.write_status_bit;
    if (status & target)
    {
        p_status->write_in_progress = true;
    }
    else
    {
        p_status->write_in_progress = false;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Selects the bank to access. A bank is a 256Mega-byte access window into the SPI Multi area. To access
 * device address 0x10000000, select bank 1, then read from address 0x20000000(physical). To access device address
 * 0x20001000, select bank 2, then read from address 0x20001000(physical).
 *
 * This function is not required for memory devices less than or equal to 256Mega-byte.
 *
 * Implements @ref spi_flash_api_t::bankSet.
 *
 * @note After different bank selections, it becomes inconsistent with cache.
 * @warning Its behavior is not guaranteed if the caller and/or the callee are stored in the same device
 *           you are trying to select banks. After changing the bank, the contents (code, data, or more) of the
 *           previously selected bank will become inaccessible.
 *
 * @retval FSP_SUCCESS                 Bank successfully selected.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_INVALID_ARGUMENT    "bank" is invalid.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_BankSet (spi_flash_ctrl_t * p_api_ctrl, uint32_t bank)
{
    spibsc_instance_ctrl_t * p_ctrl = (spibsc_instance_ctrl_t *) p_api_ctrl;

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(SPIBSC_PRV_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Limit the parameter */
    FSP_ERROR_RETURN(16 > bank, FSP_ERR_INVALID_ARGUMENT);

    /* Set DREAR.EAV field */
    uint32_t drear = (bank << 3) << R_SPIBSC_DREAR_EAV_Pos;
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->DREAR, R_SPIBSC_DREAR_EAV_Msk, drear);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets the SPI protocol.
 *
 * Implements @ref spi_flash_api_t::spiProtocolSet.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by SPIBSC
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_SpiProtocolSet (spi_flash_ctrl_t * p_api_ctrl, spi_flash_protocol_t spi_protocol)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(spi_protocol);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Auto-calibrate the OctaRAM device using the preamble pattern. Unsupported by SPIBSC.
 *
 * Implements @ref spi_flash_api_t::autoCalibrate.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by SPIBSC
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_AutoCalibrate (spi_flash_ctrl_t * p_api_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Close the SPIBSC driver module.
 *
 * Implements @ref spi_flash_api_t::close.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       p_api_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_SPIBSC_Close (spi_flash_ctrl_t * p_api_ctrl)
{
    spibsc_instance_ctrl_t * p_ctrl = (spibsc_instance_ctrl_t *) p_api_ctrl;

#if SPIBSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(SPIBSC_PRV_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    if (SPIBSC_CFG_STOP_ON_CLOSE)
    {
        /* Stop SPIM clock */
        R_BSP_MODULE_STOP(FSP_IP_SPI_MULTI, 0);
    }

    p_ctrl->open = 0U;

    /* Cleanup allocated memory */
    if (p_ctrl->p_erase_command_list)
    {
        free(p_ctrl->p_erase_command_list);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup SPIBSC)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enabling write functionality of flash device (internally used).
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_INVALID_MODE    One or more values in configuration are not met the condition of the controller mode.
 **********************************************************************************************************************/
static fsp_err_t spibsc_write_enable (spibsc_instance_ctrl_t * p_ctrl)
{
    /* Make operation structure */
    xspi_op_t op;
    memset(&op, 0, sizeof(op));
    op.clsh_value             = p_ctrl->ext.delay.clsh;
    op.shsl_value             = p_ctrl->ext.delay.shsl;
    op.slch_value             = p_ctrl->ext.delay.slch;
    op.force_idle_level_mask  = p_ctrl->ext.io_fix_mask;
    op.force_idle_level_value = p_ctrl->ext.io_fix_value;
    op.op      = p_ctrl->cfg.write_enable_command;
    op.op_size = 1;
    op.form    = SPI_FORM_1_1_1;

    /* Execute operation */
    bool      is_write = false;
    fsp_err_t result   = spibsc_exec_op(p_ctrl, &op, is_write);

    FSP_ERROR_RETURN(result == FSP_SUCCESS, result);

    return FSP_SUCCESS;
}

static void spibsc_select_spim (spibsc_instance_ctrl_t * p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
#if (BSP_FEATURE_BSP_SUPPORT_OCTAL_MEMORY)

    /* Check if OCTA selected */
    uint32_t ipcont_spi_octa = R_SYSC->SYS_IPCONT_SEL_SPI_OCTA;
    if ((ipcont_spi_octa & R_SYSC_SYS_IPCONT_SEL_SPI_OCTA_SEL_SPI_OCTA_Msk) ==
        R_SYSC_SYS_IPCONT_SEL_SPI_OCTA_SEL_SPI_OCTA_Msk)
    {
        /* Reset the OCTA controller and the devices connected,
         *  required to change the device mode from OPI to SPI.
         * Otherwise, the octa devices can not communicate with the SPIM controller.
         *//* Assert reset line */
        R_OCTA->RSTCNT_b.RSTVAL = 0;

        /* Stop OCTA */
        R_BSP_MODULE_STOP(FSP_IP_OCTA, 0);
    }

    /* Wait for reset SPI device */
    R_BSP_SoftwareDelay(SPIBSC_PRV_RESET_DURATION_US, BSP_DELAY_UNITS_MICROSECONDS);
#endif

    /* force voltage setting
     * Note: This is required if the boot mode is neither 3 nor 4.
     */
    uint8_t voltage = SPIBSC_PRV_DEFAULT_VOLTAGE_IS_1800MV ? 1 : 0;
    R_GPIO->QSPI = voltage;
    R_GPIO->QSPI;

    /* Supply SPIM clock */
    R_BSP_MODULE_START(FSP_IP_SPI_MULTI, 0);
#if (BSP_FEATURE_BSP_SUPPORT_OCTAL_MEMORY)

    /* Select SPIM for SPI controller */
    ipcont_spi_octa                &= (uint32_t) ~R_SYSC_SYS_IPCONT_SEL_SPI_OCTA_SEL_SPI_OCTA_Msk;
    R_SYSC->SYS_IPCONT_SEL_SPI_OCTA = ipcont_spi_octa;
    R_SYSC->SYS_IPCONT_SEL_SPI_OCTA;
#endif
}

static void spibsc_test_tend (spibsc_instance_ctrl_t * p_ctrl)
{
    while (true)
    {
        if (p_ctrl->p_reg->CMNSR & R_SPIBSC_CMNSR_TEND_Msk)
        {
            break;
        }
    }
}

static void spibsc_init_phy (spibsc_instance_ctrl_t * p_ctrl)
{
    MMIO_WRITE_32(p_ctrl->p_reg->PHYADJ2, 0xa5390000UL);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYADJ1, 0x80000000UL);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYADJ2, 0x00008080UL);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYADJ1, 0x80000022UL);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYADJ2, 0x00008080UL);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYADJ1, 0x80000024UL);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYADJ2, 0x00000030UL);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYADJ1, 0x80000032UL);
}

static void spibsc_ip_init (spibsc_instance_ctrl_t * p_ctrl)
{
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->CMNCR, cmncr_init_mask, cmncr_init_value);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SSLDR, ssldr_init_mask, ssldr_init_value);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->DRCR, drcr_init_mask, drcr_init_value);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->DREAR, drear_init_mask, drear_init_value);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->DRDRENR, drdrenr_init_mask, drdrenr_init_value);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->PHYCNT, phycnt_init_mask, phycnt_init_value | R_SPIBSC_PHYCNT_CAL_Msk);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->PHYOFFSET1, phyoffset1_init_mask, phyoffset1_init_value);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->PHYOFFSET2, phyoffset2_init_mask, phyoffset2_init_value);
    spibsc_init_phy(p_ctrl);
}

/*******************************************************************************************************************//**
 * Configuring memory-mapped access (internally used).
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_UNSUPPORTED     One or more values in configuration are not supported.
 * @retval FSP_ERR_INVALID_MODE    One or more values in configuration are not met the condition of the controller mode.
 **********************************************************************************************************************/
static fsp_err_t spibsc_configure_mmap (spibsc_instance_ctrl_t * p_ctrl)
{
    /* Check parameters */
    FSP_ERROR_RETURN(SPI_FLASH_PROTOCOL_EXTENDED_SPI == p_ctrl->cfg.spi_protocol, FSP_ERR_UNSUPPORTED);
    FSP_ERROR_RETURN(
        SPI_FLASH_READ_MODE_STANDARD == p_ctrl->cfg.read_mode || SPI_FLASH_READ_MODE_FAST_READ == p_ctrl->cfg.read_mode || SPI_FLASH_READ_MODE_FAST_READ_QUAD_OUTPUT == p_ctrl->cfg.read_mode || SPI_FLASH_READ_MODE_FAST_READ_QUAD_IO == p_ctrl->cfg.read_mode,
        FSP_ERR_UNSUPPORTED);
    FSP_ERROR_RETURN(
        SPI_FLASH_ADDRESS_BYTES_3 == p_ctrl->cfg.address_bytes || SPI_FLASH_ADDRESS_BYTES_4 == p_ctrl->cfg.address_bytes || SPI_FLASH_ADDRESS_BYTES_4_4BYTE_READ_CODE == p_ctrl->cfg.address_bytes,
        FSP_ERR_UNSUPPORTED);

    spibsc_select_spim(p_ctrl);
    spibsc_ip_init(p_ctrl);

    /* Search mmap config table */
    int i;
    int max_cfg_index = sizeof(g_mmap_cfg) / sizeof(g_mmap_cfg[0]);
    const spibsc_mmap_cfg_t * p_mmap_cfg = NULL;
    for (i = 0; i < max_cfg_index && p_mmap_cfg == NULL; i++)
    {
        if (p_ctrl->cfg.spi_protocol == g_mmap_cfg[i].spi_protocol)
        {
            if (p_ctrl->cfg.read_mode == g_mmap_cfg[i].read_mode)
            {
                if (p_ctrl->cfg.address_bytes == g_mmap_cfg[i].address_bytes)
                {
                    p_mmap_cfg = &g_mmap_cfg[i];
                }
            }
        }
    }

    FSP_ERROR_RETURN(p_mmap_cfg, FSP_ERR_UNSUPPORTED);

    /* Create configuration structure */
    xspi_op_t rop;
    memset(&rop, 0, sizeof(rop));
    if (p_ctrl->cfg.read_command)
    {
        rop.op = p_ctrl->cfg.read_command;
    }
    else
    {
        rop.op = p_mmap_cfg->op;
    }

    switch (p_ctrl->cfg.dummy_clocks)
    {
        case SPI_FLASH_DUMMY_CLOCKS_DEFAULT:
        {
            rop.dummy_cycles = p_mmap_cfg->dummy_cycles;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_3:
        {
            rop.dummy_cycles = 3 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_4:
        {
            rop.dummy_cycles = 4 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_5:
        {
            rop.dummy_cycles = 5 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_6:
        {
            rop.dummy_cycles = 6 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_7:
        {
            rop.dummy_cycles = 7 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_8:
        {
            rop.dummy_cycles = 8 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_9:
        {
            rop.dummy_cycles = 9 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_10:
        {
            rop.dummy_cycles = 10 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_11:
        {
            rop.dummy_cycles = 11 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_12:
        {
            rop.dummy_cycles = 12 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_13:
        {
            rop.dummy_cycles = 13 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_14:
        {
            rop.dummy_cycles = 14 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_15:
        {
            rop.dummy_cycles = 15 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_16:
        {
            rop.dummy_cycles = 16 - p_mmap_cfg->additional_size;
            break;
        }

        case SPI_FLASH_DUMMY_CLOCKS_17:
        {
            rop.dummy_cycles = 17 - p_mmap_cfg->additional_size;
            break;
        }

        default:
            FSP_ERROR_RETURN(false && p_ctrl->cfg.dummy_clocks, FSP_ERR_UNSUPPORTED);
    }

    rop.op_size                = 1;
    rop.additional_size        = p_mmap_cfg->additional_size;
    rop.address_size           = p_mmap_cfg->address_size;
    rop.force_idle_level_mask  = p_ctrl->ext.io_fix_mask;
    rop.force_idle_level_value = p_ctrl->ext.io_fix_value;
    rop.form = p_mmap_cfg->form;

    return spibsc_configure_mmap_sub(p_ctrl, &rop);
}

static uint32_t spibsc_cmncr_set (uint8_t mask, uint8_t value, int pos)
{
    int      moiionpos = -1;
    int      ionfvpos  = -1;
    uint32_t cmncr_set = 0;
    uint32_t moiio     = 0;
    uint32_t ionfv     = 0;

    switch (pos)
    {
        case 1:
        {
            moiionpos = R_SPIBSC_CMNCR_MOIIO1_Pos;
            break;
        }

        case 2:
        {
            moiionpos = R_SPIBSC_CMNCR_MOIIO2_Pos;
            ionfvpos  = R_SPIBSC_CMNCR_IO2FV_Pos;
            break;
        }

        case 3:
        {
            moiionpos = R_SPIBSC_CMNCR_MOIIO3_Pos;
            ionfvpos  = R_SPIBSC_CMNCR_IO3FV_Pos;
            break;
        }
    }

    if (mask & 1 << pos)
    {
        moiio = value & 1 << pos ? SPIBSC_CMNCR_IO_HIGH : SPIBSC_CMNCR_IO_LOW;
        ionfv = SPIBSC_CMNCR_IO_KEEP;
    }
    else
    {
        moiio = SPIBSC_CMNCR_IO_HIZ;
        ionfv = SPIBSC_CMNCR_IO_HIZ;
    }

    if (moiionpos >= 0)
    {
        cmncr_set |= moiio << moiionpos;
    }

    if (ionfvpos >= 0)
    {
        cmncr_set |= ionfv << ionfvpos;
    }

    return cmncr_set;
}

static void spibsc_set_idlelevel (spibsc_instance_ctrl_t * p_ctrl, const xspi_op_t * const op)
{
    static const uint32_t cmncr_mask =
        R_SPIBSC_CMNCR_IO2FV_Msk |
        R_SPIBSC_CMNCR_IO3FV_Msk |
        R_SPIBSC_CMNCR_MOIIO1_Msk |
        R_SPIBSC_CMNCR_MOIIO2_Msk |
        R_SPIBSC_CMNCR_MOIIO3_Msk;

    uint32_t cmncr_set = 0;

    cmncr_set |= spibsc_cmncr_set(op->force_idle_level_mask, op->force_idle_level_value, 1);
    cmncr_set |= spibsc_cmncr_set(op->force_idle_level_mask, op->force_idle_level_value, 2);
    cmncr_set |= spibsc_cmncr_set(op->force_idle_level_mask, op->force_idle_level_value, 3);

    MMIO_CLRSETBITS_32(p_ctrl->p_reg->CMNCR, cmncr_mask, cmncr_set);
}

static void spibsc_start_mmap_internal (spibsc_instance_ctrl_t * p_ctrl)
{
    MMIO_CLRBITS_32(p_ctrl->p_reg->CMNCR, R_SPIBSC_CMNCR_MD_Msk);
    MMIO_READ_32(p_ctrl->p_reg->CMNCR);
}

static void test_sslf (spibsc_instance_ctrl_t * p_ctrl)
{
    while (true)
    {
        if ((MMIO_READ_32(p_ctrl->p_reg->CMNSR) & R_SPIBSC_CMNSR_SSLF_Msk) == 0)
        {
            break;
        }
    }
}

static int spibsc_stop_mmap_internal (spibsc_instance_ctrl_t * p_ctrl)
{
    int      result = 0;
    uint32_t drcr   = MMIO_READ_32(p_ctrl->p_reg->DRCR);
    if ((drcr & (R_SPIBSC_DRCR_RBE_Msk | R_SPIBSC_DRCR_SSLE_Msk)) == (R_SPIBSC_DRCR_RBE_Msk | R_SPIBSC_DRCR_SSLE_Msk))
    {
        /* Set SSLN and wait for sslf */
        MMIO_WRITE_32(p_ctrl->p_reg->DRCR, drcr | R_SPIBSC_DRCR_SSLN_Msk);
        test_sslf(p_ctrl);
    }

    spibsc_test_tend(p_ctrl);

    /* Set MD bit */
    MMIO_SETBITS_32(p_ctrl->p_reg->CMNCR, R_SPIBSC_CMNCR_MD_Msk);

    return result;
}

static bool spibsc_stop_mmap_temporarily (spibsc_instance_ctrl_t * p_ctrl)
{
    /* Stop XIP and return previous state*/
    bool state = !(MMIO_READ_32(p_ctrl->p_reg->CMNCR) & R_SPIBSC_CMNCR_MD_Msk);
    spibsc_stop_mmap_internal(p_ctrl);

    return state;
}

static void send_256 (spibsc_instance_ctrl_t * p_ctrl, xspi_transfer_form_t form, uintptr_t buffer, uint32_t smenr)
{
    /* Use wbuffer for transfer */
    MMIO_SETBITS_32(p_ctrl->p_reg->DRCR, R_SPIBSC_DRCR_RCF_Msk);
    MMIO_SETBITS_32(p_ctrl->p_reg->PHYCNT,
                    R_SPIBSC_PHYCNT_WBUF2_Msk | R_SPIBSC_PHYCNT_WBUF_Msk | R_SPIBSC_PHYCNT_CAL_Msk);
    if ((form == SPI_FORM_1_1_4) || (form == SPI_FORM_1_4_4))
    {
        uint32_t phyoffset2_msk = R_SPIBSC_PHYOFFSET2_OCTTMG_Msk;
        uint32_t phyoffset2_set = SPIBSC_PHYOFFSET2_SPI_WBUF << R_SPIBSC_PHYOFFSET2_OCTTMG_Pos;
        MMIO_CLRSETBITS_32(p_ctrl->p_reg->PHYOFFSET2, phyoffset2_msk, phyoffset2_set);
    }

    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SMENR, smenr_clearmask,
                       smenr | (SPIBSC_SMENR_SPIDE_LONG << R_SPIBSC_SMENR_SPIDE_Pos));

    /* Write data to buffer */
    uintptr_t write_buffer = (uintptr_t) p_ctrl->p_reg + SPIBSC_CFG_WRITE_BUFFER_OFFSET;
    for (uintptr_t bytes = 0; bytes < SPIBSC_BUFFER_SIZE; bytes += 8)
    {
        *(volatile uint64_t *) (write_buffer + bytes) = *(uint64_t *) (buffer + bytes);
    }
}

static void send_4 (spibsc_instance_ctrl_t * p_ctrl, uintptr_t buffer, uint32_t smenr)
{
    /* Set SPIDE */
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SMENR, smenr_clearmask,
                       smenr | (SPIBSC_SMENR_SPIDE_LONG << R_SPIBSC_SMENR_SPIDE_Pos));

    /* Write data to SMWDR */
    MMIO_WRITE_32(p_ctrl->p_reg->SMWDR0, *(uint32_t *) buffer);
}

static void send_2 (spibsc_instance_ctrl_t * p_ctrl, uintptr_t buffer, uint32_t smenr)
{
    /* Set SPIDE */
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SMENR, smenr_clearmask,
                       smenr | (SPIBSC_SMENR_SPIDE_WORD << R_SPIBSC_SMENR_SPIDE_Pos));

    /* Write data to SMWDR */
    MMIO_WRITE_16(p_ctrl->p_reg->SMWDR0_hword.L, *(uint16_t *) buffer);
}

static void send_1 (spibsc_instance_ctrl_t * p_ctrl, uintptr_t buffer, uint32_t smenr)
{
    /* Set SPIDE */
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SMENR, smenr_clearmask,
                       smenr | (SPIBSC_SMENR_SPIDE_BYTE << R_SPIBSC_SMENR_SPIDE_Pos));

    /* Write data to SMWDR */
    MMIO_WRITE_8(p_ctrl->p_reg->SMWDR0_byte.LL, *(uint8_t *) buffer);
}

static void receive (spibsc_instance_ctrl_t * p_ctrl, uintptr_t buffer, uint32_t smenr)
{
    FSP_PARAMETER_NOT_USED(buffer);

    /* Set SPIDE */
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SMENR, smenr_clearmask,
                       smenr | (SPIBSC_SMENR_SPIDE_LONG << R_SPIBSC_SMENR_SPIDE_Pos));
}

static void no_data (spibsc_instance_ctrl_t * p_ctrl, uintptr_t buffer, uint32_t smenr)
{
    FSP_PARAMETER_NOT_USED(buffer);

    /* No transfer data */
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SMENR, smenr_clearmask,
                       smenr | (SPIBSC_SMENR_SPIDE_NONE << R_SPIBSC_SMENR_SPIDE_Pos));
}

/*******************************************************************************************************************//**
 * Executing operation on flash device (internally used).
 *
 * @retval FSP_SUCCESS             Operation was successful.
 * @retval FSP_ERR_INVALID_MODE    One or more values in op are invalid.
 **********************************************************************************************************************/
static fsp_err_t spibsc_exec_op (spibsc_instance_ctrl_t * p_ctrl, xspi_op_t const * const op, bool is_write)
{
    bool     is_xip;
    uint32_t smcmr_set   = 0;
    uint32_t smenr_set   = 0;
    uint32_t smdrenr_set = 0;
    uint32_t smdmcr_set  = 0;
    uint32_t ssldr_set   = 0;
    uint32_t smopr       = 0;

    switch (op->form)
    {
        case SPI_FORM_1_1_1:
        case SPI_FORM_1_1_4:
        case SPI_FORM_1_4_4:
        {
            break;
        }

        default:
            FSP_ERROR_RETURN(false && op->form, FSP_ERR_INVALID_MODE);
    }

    /* Command form */
    switch (op->form)
    {
        case SPI_FORM_1_1_1:
        {
            smenr_set |= smenr_form_111;
            break;
        }

        case SPI_FORM_1_1_4:
        {
            smenr_set |= smenr_form_114;
            break;
        }

        case SPI_FORM_1_4_4:
        {
            smenr_set |= smenr_form_144;
            break;
        }

        default:
            FSP_ERROR_RETURN(false && op->form, FSP_ERR_INVALID_MODE);
    }

    /* Opcode */
    switch (op->op_size)
    {
        case 0:
        {
            smenr_set |= smenr_op_none;
            break;
        }

        case 1:
        {
            smenr_set |= smenr_op_1byte;
            smcmr_set |= PICK_LL(op->op) << R_SPIBSC_SMCMR_CMD_Pos;
            break;
        }

        case 2:
        {
            smenr_set |= smenr_op_2byte;
            smcmr_set |= PICK_LL(op->op) << R_SPIBSC_SMCMR_OCMD_Pos;
            smcmr_set |= PICK_LH(op->op) << R_SPIBSC_SMCMR_CMD_Pos;
            break;
        }

        default:
            FSP_ERROR_RETURN(false && op->op_size, FSP_ERR_INVALID_MODE);
    }

    /* Address */
    switch (op->address_size)
    {
        case 0:
        {
            smenr_set |= smenr_addr_none;
            break;
        }

        case 3:
        {
            smenr_set |= smenr_addr_3byte;
            break;
        }

        case 4:
        {
            smenr_set |= smenr_addr_4byte;
            break;
        }

        default:
            FSP_ERROR_RETURN(false && op->address_size, FSP_ERR_INVALID_MODE);
    }

    /* Additional data */
    switch (op->additional_size)
    {
        case 0:
        {
            smenr_set |= smenr_additional_none;
            break;
        }

        case 1:
        {
            smenr_set |= smenr_additional_1byte;
            smopr      = PICK_LL(op->additional_value) << R_SPIBSC_SMOPR_OPD3_Pos;
            break;
        }

        case 2:
        {
            smenr_set |= smenr_additional_2byte;
            smopr      = PICK_LL(op->additional_value) << R_SPIBSC_SMOPR_OPD2_Pos;
            smopr     |= PICK_LH(op->additional_value) << R_SPIBSC_SMOPR_OPD3_Pos;
            break;
        }

        case 3:
        {
            smenr_set |= smenr_additional_3byte;
            smopr      = PICK_LL(op->additional_value) << R_SPIBSC_SMOPR_OPD1_Pos;
            smopr     |= PICK_LH(op->additional_value) << R_SPIBSC_SMOPR_OPD2_Pos;
            smopr     |= PICK_HL(op->additional_value) << R_SPIBSC_SMOPR_OPD3_Pos;
            break;
        }

        case 4:
        {
            smenr_set |= smenr_additional_4byte;
            smopr      = PICK_LL(op->additional_value) << R_SPIBSC_SMOPR_OPD0_Pos;
            smopr     |= PICK_LH(op->additional_value) << R_SPIBSC_SMOPR_OPD1_Pos;
            smopr     |= PICK_HL(op->additional_value) << R_SPIBSC_SMOPR_OPD2_Pos;
            smopr     |= PICK_HH(op->additional_value) << R_SPIBSC_SMOPR_OPD3_Pos;
            break;
        }

        default:
            FSP_ERROR_RETURN(false && op->additional_size, FSP_ERR_INVALID_MODE);
    }

    /* Dummy cycle */
    if (op->dummy_cycles == 0)
    {
        smenr_set  |= 0U << R_SPIBSC_SMENR_DME_Pos;
        smdmcr_set |= 0U << R_SPIBSC_SMDMCR_DMCYC_Pos;
    }
    else if ((op->dummy_cycles == 1) || (op->dummy_cycles > 20))
    {
        FSP_ERROR_RETURN(false && op->dummy_cycles, FSP_ERR_INVALID_MODE);
    }
    else
    {
        smenr_set  |= 1U << R_SPIBSC_SMENR_DME_Pos;
        smdmcr_set |= (op->dummy_cycles - 1U) << R_SPIBSC_SMDMCR_DMCYC_Pos;
    }

    /* SLCH (SSL assert to CLK high) */
    if (op->slch_value < 8)
    {
        ssldr_set |= op->slch_value << R_SPIBSC_SSLDR_SCKDL_Pos;
    }
    else
    {
        FSP_ERROR_RETURN(false && op->slch_value, FSP_ERR_INVALID_MODE);
    }

    /* CLSH (CLK low tp SSL negative) */
    if (op->clsh_value < 8)
    {
        ssldr_set |= op->clsh_value << R_SPIBSC_SSLDR_SLNDL_Pos;
    }
    else
    {
        FSP_ERROR_RETURN(false && op->clsh_value, FSP_ERR_INVALID_MODE);
    }

    /* SHSL (SSL negative to SSL assert) */
    if (op->shsl_value < 8)
    {
        ssldr_set |= op->shsl_value << R_SPIBSC_SSLDR_SPNDL_Pos;
    }
    else
    {
        FSP_ERROR_RETURN(false && op->shsl_value, FSP_ERR_INVALID_MODE);
    }

    /* Save XIP state and stop XIP */
    is_xip = spibsc_stop_mmap_temporarily(p_ctrl);

    /* Wait for transaction end */
    spibsc_test_tend(p_ctrl);

    /* Change I/O level while idle state */
    spibsc_set_idlelevel(p_ctrl, op);

    /* Create values to write the registers */
    uint32_t smadr           = op->address;
    uint32_t save_ssldr      = MMIO_READ_32(p_ctrl->p_reg->SSLDR);
    uint32_t save_phyoffset1 = MMIO_READ_32(p_ctrl->p_reg->PHYOFFSET1);
    uint32_t save_phyoffset2 = MMIO_READ_32(p_ctrl->p_reg->PHYOFFSET2);
    uint32_t save_phycnt     = MMIO_READ_32(p_ctrl->p_reg->PHYCNT);

    /* PHYOFFSET1 setting */
    uint32_t phyoffset1_msk = R_SPIBSC_PHYOFFSET1_DDRTMG_Msk;
    uint32_t phyoffset1_set;
    phyoffset1_set = SPIBSC_PHYOFFSET1_SDR << R_SPIBSC_PHYOFFSET1_DDRTMG_Pos;

    /* PHYCNT setting */
    uint32_t phycnt_msk = R_SPIBSC_PHYCNT_PHYMEM_Msk;
    uint32_t phycnt_set;
    phycnt_set = SPIBSC_PHYCNT_SDR << R_SPIBSC_PHYCNT_PHYMEM_Pos;

    /* Write the register */
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SMCMR, smcmr_clearmask, smcmr_set);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SMDRENR, smdrenr_clearmask, smdrenr_set);
    MMIO_WRITE_32(p_ctrl->p_reg->SMADR, smadr);
    MMIO_WRITE_32(p_ctrl->p_reg->SMOPR, smopr);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SMDMCR, smdmcr_clearmask, smdmcr_set);
    MMIO_WRITE_32(p_ctrl->p_reg->SSLDR, (save_ssldr & ~ssldr_clearmask) | ssldr_set);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYOFFSET1, (save_phyoffset1 & ~phyoffset1_msk) | phyoffset1_set);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYCNT, (save_phycnt & ~phycnt_msk) | phycnt_set | R_SPIBSC_PHYCNT_CAL_Msk);

    int64_t   remain = (int64_t) op->transfer_size;
    uintptr_t buffer = (uintptr_t) op->transfer_buffer;
    uint32_t  smcr;

    /* Enable transmit */
    if (is_write && remain)
    {
        smcr = R_SPIBSC_SMCR_SPIWE_Msk | R_SPIBSC_SMCR_SPIE_Msk;
    }
    else if (remain)
    {
        smcr = R_SPIBSC_SMCR_SPIRE_Msk | R_SPIBSC_SMCR_SPIE_Msk;
    }
    else
    {
        smcr = R_SPIBSC_SMCR_SPIE_Msk;
    }

    do
    {
        uint32_t xfer_count;

        /* Block size per single transfer */
        if (is_write && (remain >= SPIBSC_BUFFER_SIZE))
        {
            send_256(p_ctrl, op->form, buffer, smenr_set);
            xfer_count = SPIBSC_BUFFER_SIZE;
        }
        else if (is_write && (remain >= 4))
        {
            send_4(p_ctrl, buffer, smenr_set);
            xfer_count = 4;
        }
        else if (is_write && (remain >= 2))
        {
            send_2(p_ctrl, buffer, smenr_set);
            xfer_count = 2;
        }
        else if (is_write && remain)
        {
            send_1(p_ctrl, buffer, smenr_set);
            xfer_count = 1;
        }
        else if (remain)
        {
            receive(p_ctrl, buffer, smenr_set);
            xfer_count = 4;
        }
        else
        {
            no_data(p_ctrl, buffer, smenr_set);
            xfer_count = 0;
        }

        /* Set SSLKP if transaction is remained and write transfer */
        if (is_write && (remain > xfer_count))
        {
            smcr |= R_SPIBSC_SMCR_SSLKP_Msk;
        }
        else
        {
            smcr &= (uint32_t) ~R_SPIBSC_SMCR_SSLKP_Msk;
        }

        /* Exec transaction */
        MMIO_WRITE_32(p_ctrl->p_reg->SMCR, smcr);
        spibsc_test_tend(p_ctrl);

        /* Store received data */
        if (!is_write && remain)
        {
            uint32_t smrdr = MMIO_READ_32(p_ctrl->p_reg->SMRDR0);
            if (remain > 3)
            {
                *(uint32_t *) buffer = smrdr;
            }
            else
            {
                *(uint8_t *) buffer = (uint8_t) PICK_LL(smrdr);
                if (remain > 1)
                {
                    *(uint8_t *) (buffer + 1) = (uint8_t) PICK_LH(smrdr);
                }

                if (remain > 2)
                {
                    *(uint8_t *) (buffer + 2) = (uint8_t) PICK_HL(smrdr);
                }
            }
        }

        remain -= xfer_count;
        buffer += xfer_count;

        /* Clear write buffer flag and restore OCTTMG */
        MMIO_CLRSETBITS_32(p_ctrl->p_reg->PHYCNT,
                           R_SPIBSC_PHYCNT_WBUF2_Msk | R_SPIBSC_PHYCNT_WBUF_Msk,
                           R_SPIBSC_PHYCNT_CAL_Msk);
        MMIO_WRITE_32(p_ctrl->p_reg->PHYOFFSET2, save_phyoffset2);

        if (remain > 0)
        {
            if (!is_write)
            {
                /* Increment address */
                smadr += xfer_count;
                MMIO_WRITE_32(p_ctrl->p_reg->SMADR, smadr);
            }
            else
            {
                /* Clear enabler bits for continuous write access */
                smenr_set &=
                    (uint32_t) ~(R_SPIBSC_SMENR_DME_Msk | R_SPIBSC_SMENR_CDE_Msk | R_SPIBSC_SMENR_OCDE_Msk |
                                 R_SPIBSC_SMENR_ADE_Msk |
                                 R_SPIBSC_SMENR_OPDE_Msk);
            }
        }
    } while (remain > 0);

    /* Resume regs */
    MMIO_WRITE_32(p_ctrl->p_reg->SSLDR, save_ssldr);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYCNT, save_phycnt | R_SPIBSC_PHYCNT_CAL_Msk);
    MMIO_WRITE_32(p_ctrl->p_reg->PHYOFFSET1, save_phyoffset1);

    if (is_xip)
    {
        /* Resume XIP state */
        spibsc_start_mmap_internal(p_ctrl);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configuring memory-mapped read (internally used).
 *
 * @retval FSP_SUCCESS             Operation was successful.
 * @retval FSP_ERR_INVALID_MODE    One or more values in op are invalid.
 **********************************************************************************************************************/
static fsp_err_t spibsc_configure_mmap_sub (spibsc_instance_ctrl_t * p_ctrl, xspi_op_t const * const rop)
{
    uint32_t drenr_set      = 0;
    uint32_t drcmr_set      = 0;
    uint32_t drdrenr_set    = 0;
    uint32_t drdmcr_set     = 0;
    uint32_t dropr          = 0;
    uint32_t ssldr_clear    = 0;
    uint32_t ssldr_set      = 0;
    uint32_t phyoffset1_msk = R_SPIBSC_PHYOFFSET1_DDRTMG_Msk;
    uint32_t phyoffset1_set = 0;
    uint32_t phyoffset2_msk = R_SPIBSC_PHYOFFSET2_OCTTMG_Msk;
    uint32_t phyoffset2_set = SPIBSC_PHYOFFSET2_SPI << R_SPIBSC_PHYOFFSET2_OCTTMG_Pos;
    uint32_t phycnt_msk     = R_SPIBSC_PHYCNT_PHYMEM_Msk;
    uint32_t phycnt_set     = 0;

    /* Command form */
    switch (rop->form)
    {
        case SPI_FORM_1_1_1:
        {
            drenr_set |= drenr_form_111;
            break;
        }

        case SPI_FORM_1_1_4:
        {
            drenr_set |= drenr_form_114;
            break;
        }

        case SPI_FORM_1_4_4:
        {
            drenr_set |= drenr_form_144;
            break;
        }

        default:
            FSP_ERROR_RETURN(false && rop->form, FSP_ERR_INVALID_MODE);
    }

    /* Opcode */
    switch (rop->op_size)
    {
        case 0:
        {
            drenr_set |= drenr_op_none;
            break;
        }

        case 1:
        {
            drenr_set |= drenr_op_1byte;
            drcmr_set |= PICK_LL(rop->op) << R_SPIBSC_DRCMR_CMD_Pos;
            break;
        }

        case 2:
        {
            drenr_set |= drenr_op_2byte;
            drcmr_set |= PICK_LL(rop->op) << R_SPIBSC_DRCMR_OCMD_Pos;
            drcmr_set |= PICK_LH(rop->op) << R_SPIBSC_DRCMR_CMD_Pos;
            break;
        }

        default:
            FSP_ERROR_RETURN(false && rop->op_size, FSP_ERR_INVALID_MODE);
    }

    /* Address */
    switch (rop->address_size)
    {
        case 0:
        {
            drenr_set |= drenr_addr_none;
            break;
        }

        case 3:
        {
            drenr_set |= drenr_addr_3byte;
            break;
        }

        case 4:
        {
            drenr_set |= drenr_addr_4byte;
            break;
        }

        default:
            FSP_ERROR_RETURN(false && rop->address_size, FSP_ERR_INVALID_MODE);
    }

    /* Additional data */
    switch (rop->additional_size)
    {
        case 0:
        {
            drenr_set |= drenr_additional_none;
            break;
        }

        case 1:
        {
            drenr_set |= drenr_additional_1byte;
            dropr     |= PICK_LL(rop->additional_value) << R_SPIBSC_DROPR_OPD3_Pos;
            break;
        }

        case 2:
        {
            drenr_set |= drenr_additional_2byte;
            dropr     |= PICK_LL(rop->additional_value) << R_SPIBSC_DROPR_OPD2_Pos;
            dropr     |= PICK_LH(rop->additional_value) << R_SPIBSC_DROPR_OPD3_Pos;
            break;
        }

        case 3:
        {
            drenr_set |= drenr_additional_3byte;
            dropr     |= PICK_LL(rop->additional_value) << R_SPIBSC_DROPR_OPD1_Pos;
            dropr     |= PICK_LH(rop->additional_value) << R_SPIBSC_DROPR_OPD2_Pos;
            dropr     |= PICK_HL(rop->additional_value) << R_SPIBSC_DROPR_OPD3_Pos;
            break;
        }

        case 4:
        {
            drenr_set |= drenr_additional_4byte;
            dropr     |= PICK_LL(rop->additional_value) << R_SPIBSC_DROPR_OPD0_Pos;
            dropr     |= PICK_LH(rop->additional_value) << R_SPIBSC_DROPR_OPD1_Pos;
            dropr     |= PICK_HL(rop->additional_value) << R_SPIBSC_DROPR_OPD2_Pos;
            dropr     |= PICK_HH(rop->additional_value) << R_SPIBSC_DROPR_OPD3_Pos;
            break;
        }

        default:
            FSP_ERROR_RETURN(false && rop->additional_size, FSP_ERR_INVALID_MODE);
    }

    /* Dummy cycle */
    if (rop->dummy_cycles == 0)
    {
        drenr_set  |= 0U << R_SPIBSC_DRENR_DME_Pos;
        drdmcr_set |= 0U << R_SPIBSC_DRDMCR_DMCYC_Pos;
    }
    else if ((rop->dummy_cycles == 1) || (rop->dummy_cycles > 20))
    {
        FSP_ERROR_RETURN(false && rop->dummy_cycles, FSP_ERR_INVALID_MODE);
    }
    else
    {
        drenr_set  |= 1U << R_SPIBSC_DRENR_DME_Pos;
        drdmcr_set |= (rop->dummy_cycles - 1U) << R_SPIBSC_DRDMCR_DMCYC_Pos;
    }

    /* Set operation timing for PHYOFFSET1 */
    phyoffset1_set = SPIBSC_PHYOFFSET1_SDR << R_SPIBSC_PHYOFFSET1_DDRTMG_Pos;

    /* Set data transfer mode for PHYCNT */
    phycnt_set = SPIBSC_PHYCNT_SDR << R_SPIBSC_PHYCNT_PHYMEM_Pos;

    /* SLCH (SSL assert to CLK high) */
    if (rop->slch_value < 8)
    {
        ssldr_clear |= R_SPIBSC_SSLDR_SCKDL_Msk;
        ssldr_set   |= rop->slch_value << R_SPIBSC_SSLDR_SCKDL_Pos;
    }
    else
    {
        FSP_ERROR_RETURN(false && rop->slch_value, FSP_ERR_INVALID_MODE);
    }

    /* CLSH (CLK low tp SSL negative) */
    if (rop->clsh_value < 8)
    {
        ssldr_clear |= R_SPIBSC_SSLDR_SLNDL_Msk;
        ssldr_set   |= rop->clsh_value << R_SPIBSC_SSLDR_SLNDL_Pos;
    }
    else
    {
        FSP_ERROR_RETURN(false && rop->clsh_value, FSP_ERR_INVALID_MODE);
    }

    /* SHSL (SSL negative to SSL assert) */
    if (rop->shsl_value < 8)
    {
        ssldr_clear |= R_SPIBSC_SSLDR_SPNDL_Msk;
        ssldr_set   |= rop->shsl_value << R_SPIBSC_SSLDR_SPNDL_Pos;
    }
    else
    {
        FSP_ERROR_RETURN(false && rop->shsl_value, FSP_ERR_INVALID_MODE);
    }

    /* Change I/O level while idle state */
    spibsc_set_idlelevel(p_ctrl, rop);

    /* Write the register */
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->DRCMR, drcmr_clearmask, drcmr_set);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->DRENR, drenr_clearmask, drenr_set);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->DRDRENR, drdrenr_clearmask, drdrenr_set);
    MMIO_WRITE_32(p_ctrl->p_reg->DROPR, dropr);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->DRDMCR, drdmcr_clearmask, drdmcr_set);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->SSLDR, ssldr_clear, ssldr_set);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->PHYOFFSET1, phyoffset1_msk, phyoffset1_set);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->PHYOFFSET2, phyoffset2_msk, phyoffset2_set);
    MMIO_CLRSETBITS_32(p_ctrl->p_reg->PHYCNT, phycnt_msk, phycnt_set | R_SPIBSC_PHYCNT_CAL_Msk);

    return FSP_SUCCESS;
}
