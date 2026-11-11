/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_mram.h"

/* Configuration for this package. */
#include "r_mram_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "MRAM" in ASCII, used to avoid multiple open. */
#define MRAM_PRV_OPEN                                (0x4D52414DU)

#define MRAM_AREA_OFFSET                             (BSP_ROM_SIZE_BYTES / 2)

#define MRAM_PRV_CMD_BASE                            (0x87080000U)

/** R_MRAM Commands */
#define MRAM_PRV_MACI_CMD_STATUS_CLEAR               (0x50U)
#define MRAM_PRV_MACI_CMD_FORCED_STOP                (0xB3U)
#define MRAM_PRV_MACI_CMD_CONFIG_SET_1               (0x40U)
#define MRAM_PRV_MACI_CMD_CONFIG_SET_2               (0x08U)
#define MRAM_PRV_MACI_CMD_INCREMENT_COUNTER          (0x35U)
#define MRAM_PRV_MACI_CMD_READ_COUNTER               (0x39U)
#define MRAM_PRV_MACI_CMD_FINAL                      (0xD0U)

#ifndef MRAM_PRV_OFS_ARCCS_ADDR
 #define MRAM_PRV_OFS_ARCCS_ADDR                     (0x86E30E30U)
#endif
#ifndef MRAM_PRV_OFS_ARC_SEC_ADDR
 #define MRAM_PRV_OFS_ARC_SEC_ADDR                   (0x86F41D00U)
#endif
#ifndef MRAM_PRV_OFS_ARC_NSEC_ADDR
 #define MRAM_PRV_OFS_ARC_NSEC_ADDR                  (0x86F41E00U)
#endif
#define MRAM_PRV_OFS_ARCCS_ARCS_Msk                  (0x3U)
#define MRAM_PRV_OFS_ARCCS_ARCS_OFFSET               (24U)
#define MRAM_PRV_OFS_ARCCS_ARCNS_Msk                 (0x3U)
#define MRAM_PRV_OFS_ARCCS_ARCNS_OFFSET              (16U)

/* 8 words need to be written for code MRAM */
#define MRAM_PRV_CONFIG_SET_ACCESS_WORD_CNT          (8U)

/** Register masks */
#define MRAM_PRV_MENTRYR_PE_MODE                     (0x0080U) // Bits indicating that MRAM is in P/E mode.
#define MRAM_PRV_MENTRYR_TRANSITION_TO_PE            (0xAA80U) // Key Code to transition to P/E mode.
#define MRAM_PRV_MENTRYR_PE_MODE_BITS                (0x0080U)
#define MRAM_PRV_MENTRYR_READ_MODE                   (0xAA00U)

#define MRAM_PRV_FREQUENCY_IN_HZ                     (1000000U)

#define MRAM_PRV_MAX_MRAM_WRITE_US                   (100U)
#define MRAM_PRV_MAX_ARC_INCREMENT_US                (2000U)
#define MRAM_PRV_MAX_ARC_READ_US                     (1U)
#define MRAM_PRV_MAX_CONFIGURATION_SET_US            (10000U)
#define MRAM_PRV_MAX_MACI_COMMAND_US                 (4U)

#define MRAM_PRV_ARCS_MODE2                          (0U) // ARCMD setting for Mode2
#define MRAM_PRV_ARCS_MODE1                          (1U) // ARCMD setting for Mode1
#define MRAM_PRV_ARCNS_SINGLE                        (1U) // ARCNS setting for single ARC_NSEC counter
#define MRAM_PRV_ARCNS_MULTIPLE                      (0U) // ARCNS setting for multiple ARC_NSEC counters
#define MRAM_PRV_ARC_MCNTSELR_OEMBL                  (2U)
#define MRAM_PRV_ARC_MCNTSELR_SEC                    (1U)
#define MRAM_PRV_ARC_MCNTSELR_NSEC_0                 (4U)
#define MRAM_PRV_64_BITS                             (64U)

#define MRAM_PRV_MRCPCNS_KEY                         (0x8600U)
#define MRAM_PRV_MRCPCS_KEY                          (0x6800U)

#define MRAM_PRV_MRCFLR_FLUSH                        (0xC301U)
#define MRAM_PRV_MRCBFLR_FLUSH                       (0xC302U)

#define MRAM_PRV_MRC_AREA_A                          (0U)
#define MRAM_PRV_MRC_AREA_B                          (1U)

#define MRAM_PRV_MRDFLR_FLUSH                        (0xC401U)

/* The number of CPU cycles per each timeout loop. */
#ifndef MRAM_PRV_MINIMUM_CYCLES_PER_TIMEOUT_LOOP
 #define MRAM_PRV_MINIMUM_CYCLES_PER_TIMEOUT_LOOP    (1U)
#endif

/* =========================================================================================================================== */
/* ================                                       MRAM_PRV_CMD                                       ================ */
/* =========================================================================================================================== */

/**
 * @brief Flash Application Command Interface Command-Issuing Area (MRAM_PRV_CMD)
 */

#define MRAM_PRV_CMD    ((R_MRAM_CMD_Type *) MRAM_PRV_CMD_BASE)

typedef struct                         /*!< (@ 0x87080000) MRAM_PRV_CMD Structure                                    */
{
    union
    {
        __IOM uint16_t MACI_CMD16;     /*!< (@ 0x00000000) MACI Command Issuing Area (halfword access)             */
        __IOM uint8_t  MACI_CMD8;      /*!< (@ 0x00000000) MACI Command Issuing Area (byte access)                 */
    };
} R_MRAM_CMD_Type;

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static const flash_block_info_t g_code_mram_macro_info[] =
{
    {
        .block_section_st_addr  = BSP_MRAM_REGION_CODE_A_START_ADDRESS,
        .block_section_end_addr =
            (uint32_t) (BSP_MRAM_REGION_CODE_A_START_ADDRESS + (BSP_ROM_SIZE_BYTES / 2) - 1),
        .block_size       = BSP_FEATURE_MRAM_PROGRAMMING_SIZE_BYTES,
        .block_size_write = 1
    },
    {
        .block_section_st_addr  = BSP_MRAM_REGION_CODE_B_START_ADDRESS,
        .block_section_end_addr =
            (uint32_t) (BSP_MRAM_REGION_CODE_B_START_ADDRESS + (BSP_ROM_SIZE_BYTES / 2) - 1),
        .block_size       = BSP_FEATURE_MRAM_PROGRAMMING_SIZE_BYTES,
        .block_size_write = 1
    }
};

static const flash_regions_t g_mram_code_region =
{
    .num_regions   = 1,
    .p_block_array = g_code_mram_macro_info
};

static const flash_regions_t g_mram_data_region =
{
    .num_regions   = 0,
    .p_block_array = NULL
};

typedef struct st_mram_program_info
{
    uint8_t  mrcps_abufemp_mask;
    uint8_t  mrcps_abuffull_mask;
    uint8_t  mrcps_prgbsyc_mask;
    uint16_t mrcflr_flush_code;
} mram_program_info_t;

static const mram_program_info_t g_mram_program_info[] =
{
#if BSP_FEATURE_MRAM_HAS_CODE_MRAM_REGION_A
    {
        .mrcps_abufemp_mask  = R_MRAM_MRCPS_ABUFEMP_Msk,
        .mrcps_abuffull_mask = R_MRAM_MRCPS_ABUFFULL_Msk,
        .mrcps_prgbsyc_mask  = R_MRAM_MRCPS_PRGBSYC_Msk,
        .mrcflr_flush_code   = MRAM_PRV_MRCFLR_FLUSH,
    },
#endif

#if BSP_FEATURE_MRAM_HAS_CODE_MRAM_REGION_B
    {
        .mrcps_abufemp_mask  = R_MRAM_MRCPS_ABUFEMPB_Msk,
        .mrcps_abuffull_mask = R_MRAM_MRCPS_ABUFFULLB_Msk,
        .mrcps_prgbsyc_mask  = R_MRAM_MRCPS_PRGBSYCB_Msk,
        .mrcflr_flush_code   = MRAM_PRV_MRCBFLR_FLUSH,
    }
#endif
};

static int clz (uint32_t val) {
    int i;
    for (i = 0; i < 32; i++)           // NOLINT(readability-magic-numbers)
    {
        if (val & (1U << (31 - i)))    // NOLINT(readability-magic-numbers)
        {
            break;
        }
    }

    return i;
}

#define __CLZ(x)    clz(x)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/* Internal functions. */
static void mram_init(mram_instance_ctrl_t * p_ctrl);

static fsp_err_t mram_transition_to_read_mode(mram_instance_ctrl_t * p_ctrl);

static fsp_err_t mram_stop(mram_instance_ctrl_t * p_ctrl);

static fsp_err_t mram_erase_blocks(uint32_t                          address,
                                   uint32_t                          num_blocks,
                                   mram_program_info_t const * const mram_program_info) PLACE_IN_RAM_SECTION;

static fsp_err_t mram_write_data(uint32_t                          src_address,
                                 uint32_t                          mram_address,
                                 uint32_t                          num_bytes,
                                 mram_program_info_t const * const mram_program_info) PLACE_IN_RAM_SECTION;

static void mram_program_control(uint32_t address, bool enable);

static fsp_err_t mram_check_errors(mram_instance_ctrl_t * const p_ctrl, fsp_err_t previous_error);

static void mram_enter_pe_mode(void);

#if (MRAM_CFG_PARAM_CHECKING_ENABLE == 1)

static fsp_err_t r_mram_common_parameter_checking(mram_instance_ctrl_t * const p_ctrl);

static fsp_err_t r_mram_write_erase_parameter_checking(mram_instance_ctrl_t * const p_ctrl,
                                                       uint32_t                     mram_address,
                                                       uint32_t const               num_bytes,
                                                       fsp_err_t                    size_err);

#endif

static uint8_t   mram_counter_to_mcntselr_convert(flash_arc_t counter);
static fsp_err_t mram_arc_read(mram_instance_ctrl_t * const p_ctrl, uint8_t mcntselr, uint32_t * const p_count);
static fsp_err_t mram_arc_cmd_execute(mram_instance_ctrl_t * const p_ctrl,
                                      uint8_t                      mcntselr,
                                      uint8_t                      cmd,
                                      volatile uint32_t            wait_count);

#if (MRAM_CFG_PARAM_CHECKING_ENABLE == 1)
static fsp_err_t r_mram_arc_common_parameter_checking(mram_instance_ctrl_t * const p_ctrl,
                                                      flash_arc_t                  counter,
                                                      uint8_t                      mcntselr);

#endif

static fsp_err_t mram_df_erase_blocks(uint32_t address, uint32_t num_blocks);

static fsp_err_t mram_df_write_data(uint32_t src_address, uint32_t mram_address, uint32_t num_bytes);

__STATIC_INLINE uint32_t mram_calc_operation_address(uint8_t    area,
                                                     uint32_t   mram_address,
                                                     uint32_t   num_bytes,
                                                     uint32_t * write_mram_address);

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

const flash_api_t g_flash_on_mram =
{
    .open                         = R_MRAM_Open,
    .close                        = R_MRAM_Close,
    .write                        = R_MRAM_Write,
    .erase                        = R_MRAM_Erase,
    .blankCheck                   = R_MRAM_BlankCheck,
    .statusGet                    = R_MRAM_StatusGet,
    .infoGet                      = R_MRAM_InfoGet,
    .accessWindowSet              = R_MRAM_AccessWindowSet,
    .accessWindowClear            = R_MRAM_AccessWindowClear,
    .idCodeSet                    = R_MRAM_IdCodeSet,
    .reset                        = R_MRAM_Reset,
    .startupAreaSelect            = R_MRAM_StartUpAreaSelect,
    .updateFlashClockFreq         = R_MRAM_UpdateFlashClockFreq,
    .bankSwap                     = R_MRAM_BankSwap,
    .callbackSet                  = R_MRAM_CallbackSet,
    .antiRollbackCounterIncrement = R_MRAM_AntiRollbackCounterIncrement,
    .antiRollbackCounterRefresh   = R_MRAM_AntiRollbackCounterRefresh,
    .antiRollbackCounterRead      = R_MRAM_AntiRollbackCounterRead,
    .userLockableAreaWrite        = R_MRAM_UserLockableAreaWrite,
};

/*******************************************************************************************************************//**
 * @addtogroup MRAM
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the MRAM peripheral. Implements @ref flash_api_t::open.
 *
 * The Open function initializes the MRAM.
 *
 * Example:
 * @snippet r_mram_example.c R_MRAM_Open
 *
 * @retval     FSP_SUCCESS               Initialization was successful.
 * @retval     FSP_ERR_ALREADY_OPEN      The MRAM control block is already open.
 * @retval     FSP_ERR_ASSERTION         NULL provided for p_ctrl or p_cfg.
 * @retval     FSP_ERR_IRQ_BSP_DISABLED  Caller is requesting BGO but the MRAM interrupts are not supported.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_Open (flash_ctrl_t * const p_api_ctrl, flash_cfg_t const * const p_cfg)
{
    mram_instance_ctrl_t * p_ctrl = (mram_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t              err    = FSP_SUCCESS;

#if (MRAM_CFG_PARAM_CHECKING_ENABLE)

    /* If null pointers return error. */
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_ctrl);

    /* If open return error. */
    FSP_ERROR_RETURN((MRAM_PRV_OPEN != p_ctrl->opened), FSP_ERR_ALREADY_OPEN);

    FSP_ERROR_RETURN(false == p_cfg->data_flash_bgo, FSP_ERR_IRQ_BSP_DISABLED);
    FSP_ERROR_RETURN(FSP_INVALID_VECTOR == p_cfg->irq, FSP_ERR_IRQ_BSP_DISABLED);
    FSP_ERROR_RETURN(FSP_INVALID_VECTOR == p_cfg->err_irq, FSP_ERR_IRQ_BSP_DISABLED);
    FSP_ERROR_RETURN(BSP_IRQ_DISABLED == p_cfg->ipl, FSP_ERR_IRQ_BSP_DISABLED);
    FSP_ERROR_RETURN(BSP_IRQ_DISABLED == p_cfg->err_ipl, FSP_ERR_IRQ_BSP_DISABLED);
    FSP_ERROR_RETURN(NULL == p_cfg->p_callback, FSP_ERR_IRQ_BSP_DISABLED);
#endif

    /* Calculate timeout values */
    mram_init(p_ctrl);

    p_ctrl->p_cfg = p_cfg;

    /* If successful mark the control block as open. */
    p_ctrl->opened = MRAM_PRV_OPEN;

    return err;
}

/*******************************************************************************************************************//**
 * Writes to the specified MRAM memory area. Implements @ref flash_api_t::write.
 *
 * Example:
 * @snippet r_mram_example.c R_MRAM_Write
 *
 * @retval     FSP_SUCCESS              Operation successful.
 * @retval     FSP_ERR_IN_USE           The MRAM peripheral is busy with a prior on-going transaction.
 * @retval     FSP_ERR_INVALID_SIZE     Number of bytes provided was invalid
 * @retval     FSP_ERR_INVALID_ADDRESS  Invalid address was input or address not on programming boundary.
 * @retval     FSP_ERR_NOT_OPEN         The MRAM API is not Open.
 * @retval     FSP_ERR_ASSERTION        NULL provided for p_ctrl.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_Write (flash_ctrl_t * const p_api_ctrl,
                        uint32_t const       src_address,
                        uint32_t             mram_address,
                        uint32_t const       num_bytes)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    fsp_err_t err = FSP_SUCCESS;

#if (MRAM_CFG_PARAM_CHECKING_ENABLE == 1)
    mram_instance_ctrl_t * p_ctrl = (mram_instance_ctrl_t *) p_api_ctrl;

    /* Verify write parameters. If failure return error. */
    err = r_mram_write_erase_parameter_checking(p_ctrl, mram_address, num_bytes, FSP_ERR_INVALID_SIZE);
    FSP_ERROR_RETURN((err == FSP_SUCCESS), err);
#endif
    FSP_ERROR_RETURN(0 == (R_MRAM->MRCPS & (R_MRAM_MRCPS_ABUFFULL_Msk | R_MRAM_MRCPS_PRGBSYC_Msk)), FSP_ERR_IN_USE);

    if (mram_address >= BSP_FLASH_CODE_FLASH_START_ADDRESS)
    {
        for (uint8_t area = 0; area < BSP_FEATURE_MRAM_REGION_CODE_AREA_NUM; area++)
        {
            uint32_t write_mram_address;
            uint32_t write_num_bytes = mram_calc_operation_address(area, mram_address, num_bytes, &write_mram_address);

            if (write_num_bytes > 0)
            {
                uint32_t write_src_address = src_address + (write_mram_address - mram_address);
                err =
                    mram_write_data(write_src_address, write_mram_address, write_num_bytes, &g_mram_program_info[area]);
            }
        }
    }
    else
    {
        err = mram_df_write_data(src_address, mram_address, num_bytes);
    }

    return err;
}

/*******************************************************************************************************************//**
 * Erases the specified MRAM blocks. Implements @ref flash_api_t::erase by the block_erase_address.
 *
 * Example:
 * @snippet r_mram_example.c R_MRAM_Erase
 *
 * @retval     FSP_SUCCESS              Successful open.
 * @retval     FSP_ERR_INVALID_BLOCKS   Invalid number of blocks specified
 * @retval     FSP_ERR_INVALID_ADDRESS  Invalid address specified.
 * @retval     FSP_ERR_IN_USE           Other MRAM operation in progress, or API not initialized
 * @retval     FSP_ERR_NOT_OPEN         The MRAM API is not Open.
 * @retval     FSP_ERR_ASSERTION        NULL provided for p_ctrl
 **********************************************************************************************************************/
fsp_err_t R_MRAM_Erase (flash_ctrl_t * const p_api_ctrl, uint32_t const address, uint32_t const num_blocks)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    fsp_err_t err = FSP_SUCCESS;
    uint8_t   mram_program_size;

    if ((address & BSP_FLASH_CODE_FLASH_START_ADDRESS) == BSP_FLASH_CODE_FLASH_START_ADDRESS)
    {
        mram_program_size = BSP_FEATURE_MRAM_PROGRAMMING_SIZE_BYTES;
    }
    else
    {
        mram_program_size = BSP_FEATURE_DATA_MRAM_PROGRAMMING_SIZE_BYTES;
    }

#if (MRAM_CFG_PARAM_CHECKING_ENABLE == 1)
    mram_instance_ctrl_t * p_ctrl = (mram_instance_ctrl_t *) p_api_ctrl;

    /* Verify parameters. */
    err =
        r_mram_write_erase_parameter_checking(p_ctrl, address, num_blocks * mram_program_size, FSP_ERR_INVALID_BLOCKS);
    FSP_ERROR_RETURN((err == FSP_SUCCESS), err);
    FSP_ERROR_RETURN(0 == address % mram_program_size, FSP_ERR_INVALID_ADDRESS);
#endif

    if (address >= BSP_FLASH_CODE_FLASH_START_ADDRESS)
    {
        for (uint8_t area = 0; area < BSP_FEATURE_MRAM_REGION_CODE_AREA_NUM; area++)
        {
            uint32_t erase_start;
            uint32_t erase_num_bytes  = num_blocks * mram_program_size;
            uint32_t erase_num_blocks = mram_calc_operation_address(area, address, erase_num_bytes, &erase_start) /
                                        mram_program_size;

            if (erase_num_blocks > 0)
            {
                err = mram_erase_blocks(erase_start, erase_num_blocks, &g_mram_program_info[area]);
            }
        }
    }
    else
    {
        err = mram_df_erase_blocks(address, num_blocks);
    }

    return err;
}

/*******************************************************************************************************************//**
 * Stub function
 * Implements @ref flash_api_t::blankCheck.
 *
 * @retval     FSP_ERR_UNSUPPORTED       Blank Check is not supported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_BlankCheck (flash_ctrl_t * const p_api_ctrl,
                             uint32_t const       address,
                             uint32_t             num_bytes,
                             flash_result_t     * p_blank_check_result)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(address);
    FSP_PARAMETER_NOT_USED(num_bytes);
    FSP_PARAMETER_NOT_USED(p_blank_check_result);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Query the MRAM peripheral for its status. Implements @ref flash_api_t::statusGet.
 *
 * @retval     FSP_SUCCESS        MRAM peripheral is ready to use.
 * @retval     FSP_ERR_ASSERTION  NULL provided for p_ctrl.
 * @retval     FSP_ERR_NOT_OPEN   The MRAM API is not Open.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_StatusGet (flash_ctrl_t * const p_api_ctrl, flash_status_t * const p_status)
{
#if (MRAM_CFG_PARAM_CHECKING_ENABLE == 1)
    mram_instance_ctrl_t * p_ctrl = (mram_instance_ctrl_t *) p_api_ctrl;

    /* If null pointer return error. */
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_status);

    /* If control block is not open return error. */
    FSP_ERROR_RETURN(!(MRAM_PRV_OPEN != p_ctrl->opened), FSP_ERR_NOT_OPEN);
#else

    /* Eliminate warning if parameter checking is disabled. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
#endif

    /* If the MRAM is currently in program/erase mode notify the caller that the MRAM is busy. */
    if ((R_MRAM->MENTRYR & MRAM_PRV_MENTRYR_PE_MODE_BITS) == 0x0000U)
    {
        *p_status = FLASH_STATUS_IDLE;
    }
    else
    {
        *p_status = FLASH_STATUS_BUSY;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stub function
 * Implements @ref flash_api_t::idCodeSet.
 *
 * @retval     FSP_ERR_UNSUPPORTED       ID Code is not supported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_IdCodeSet (flash_ctrl_t * const p_api_ctrl, uint8_t const * const p_id_code, flash_id_code_mode_t mode)
{
    /* Eliminate warning. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_id_code);
    FSP_PARAMETER_NOT_USED(mode);

    /* Return status. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Stub function
 * Implements @ref flash_api_t::accessWindowSet.
 *
 * @retval     FSP_ERR_UNSUPPORTED       Access window is not supported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_AccessWindowSet (flash_ctrl_t * const p_api_ctrl, uint32_t const start_addr, uint32_t const end_addr)
{
    /* Eliminate warning. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(start_addr);
    FSP_PARAMETER_NOT_USED(end_addr);

    /* Return status. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Stub function
 * Implements @ref flash_api_t::accessWindowClear.
 *
 * @retval     FSP_ERR_UNSUPPORTED       Access window is not supported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_AccessWindowClear (flash_ctrl_t * const p_api_ctrl)
{
    /* Eliminate warning. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Reset the MRAM peripheral. Implements @ref flash_api_t::reset.
 *
 * No attempt is made to check if the MRAM is busy before executing the reset since the assumption is that a reset will
 * terminate any existing operation.
 *
 * @retval     FSP_ERR_UNSUPPORTED       Reset is not supported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_Reset (flash_ctrl_t * const p_api_ctrl)
{
    /* Eliminate warning. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Selects which block, Default (Block 0) or Alternate (Block 1), is used as the startup area block. The provided
 * parameters determine which block will become the active startup block and whether that action will be immediate (but
 * temporary), or permanent subsequent to the next reset. Implements
 * @ref flash_api_t::startupAreaSelect.
 *
 * @retval     FSP_ERR_UNSUPPORTED       StartUpAreaSelect is not supported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_StartUpAreaSelect (flash_ctrl_t * const      p_api_ctrl,
                                    flash_startup_area_swap_t swap_type,
                                    bool                      is_temporary)
{
    /* Eliminate warning. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(swap_type);
    FSP_PARAMETER_NOT_USED(is_temporary);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Stub function
 * @ref flash_api_t::bankSwap.
 *
 * @retval     FSP_ERR_UNSUPPORTED       Bank Swap is not supported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_BankSwap (flash_ctrl_t * const p_api_ctrl)
{
    /* Eliminate warning. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Indicate to the MRAM module that the system clock has changed. Implements @ref flash_api_t::updateFlashClockFreq.
 *
 * This should be the case if the application has changed the system clock.
 *
 * @retval     FSP_ERR_UNSUPPORTED       UpdateFlashClockFreq is not supported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_UpdateFlashClockFreq (flash_ctrl_t * const p_api_ctrl)
{
    /* Eliminate warning. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Returns the information about the MRAM regions. Implements @ref flash_api_t::infoGet.
 *
 * @retval     FSP_SUCCESS        Successful retrieved the request information.
 * @retval     FSP_ERR_NOT_OPEN   The control block is not open.
 * @retval     FSP_ERR_ASSERTION  NULL provided for p_ctrl or p_info.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_InfoGet (flash_ctrl_t * const p_api_ctrl, flash_info_t * const p_info)
{
#if MRAM_CFG_PARAM_CHECKING_ENABLE

    /* If null pointers return error. */
    FSP_ASSERT(NULL != p_api_ctrl);
    FSP_ASSERT(NULL != p_info);

    mram_instance_ctrl_t * p_ctrl = (mram_instance_ctrl_t *) p_api_ctrl;

    /* If the MRAM api is not open return an error. */
    FSP_ERROR_RETURN(MRAM_PRV_OPEN == p_ctrl->opened, FSP_ERR_NOT_OPEN);
#else

    /* Eliminate warning if parameter checking is disabled. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
#endif

    /* Copy information about the MRAM to the user structure. */
    p_info->code_flash = g_mram_code_region;
    p_info->data_flash = g_mram_data_region;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Releases any resources that were allocated by the Open() or any subsequent MRAM operations. Implements
 * @ref flash_api_t::close.
 *
 * @retval     FSP_SUCCESS        Successful close.
 * @retval     FSP_ERR_NOT_OPEN   The control block is not open.
 * @retval     FSP_ERR_ASSERTION  NULL provided for p_ctrl or p_cfg.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_Close (flash_ctrl_t * const p_api_ctrl)
{
    mram_instance_ctrl_t * p_ctrl = (mram_instance_ctrl_t *) p_api_ctrl;

#if MRAM_CFG_PARAM_CHECKING_ENABLE

    /* If null pointer return error. */
    FSP_ASSERT(NULL != p_ctrl);

    /* If the MRAM api is not open return an error. */
    FSP_ERROR_RETURN(MRAM_PRV_OPEN == p_ctrl->opened, FSP_ERR_NOT_OPEN);
#else

    /* Eliminate warning if parameter checking is disabled. */
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Close the API */
    p_ctrl->opened = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stub function
 * Implements @ref flash_api_t::callbackSet.
 *
 * @retval     FSP_ERR_UNSUPPORTED       Interrupt driven operation is not supported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_CallbackSet (flash_ctrl_t * const          p_api_ctrl,
                              void (                      * p_callback)(flash_callback_args_t *),
                              void * const                  p_context,
                              flash_callback_args_t * const p_callback_memory)
{
    /* Eliminate warning. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_callback);
    FSP_PARAMETER_NOT_USED(p_context);
    FSP_PARAMETER_NOT_USED(p_callback_memory);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Increments the selected anti-rollback counter.
 *
 * @note The counter is read internally before increment.
 *
 * Implements @ref flash_api_t::antiRollbackCounterIncrement
 *
 * @retval     FSP_SUCCESS              Counter incremented successfully
 * @retval     FSP_ERR_ASSERTION        NULL provided for p_api_ctrl
 * @retval     FSP_ERR_NOT_OPEN         The MRAM module is not open.
 * @retval     FSP_ERR_IN_USE           The MRAM peripheral is busy with a prior on-going transaction.
 * @retval     FSP_ERR_NOT_ENABLED      The specified counter has not been configured (configuration is only required for ARC_NSEC)
 * @retval     FSP_ERR_OVERFLOW         The counter cannot be incremented because it is already at its max value
 * @retval     FSP_ERR_TIMEOUT          Timed out waiting for the MACI to become ready.
 * @retval     FSP_ERR_CMD_LOCKED       MRAM Application Command Interface is in locked state
 * @retval     FSP_ERR_HUK_ZEROIZATION  HUK ZEROIZATION command is executing
 * @retval     FSP_ERR_UNSUPPORTED      Selected anti-rollback counter is not supported on this MCU
 **********************************************************************************************************************/
fsp_err_t R_MRAM_AntiRollbackCounterIncrement (flash_ctrl_t * const p_api_ctrl, flash_arc_t counter)
{
    fsp_err_t err;

    mram_instance_ctrl_t * p_ctrl   = (mram_instance_ctrl_t *) p_api_ctrl;
    uint8_t                mcntselr = mram_counter_to_mcntselr_convert(counter);

#if MRAM_CFG_PARAM_CHECKING_ENABLE
    err = r_mram_arc_common_parameter_checking(p_ctrl, counter, mcntselr);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    /* Read the current counter value*/
    uint32_t count;
    err = mram_arc_read(p_ctrl, mcntselr, &count);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Check for overflow. */
    uint32_t max_count;
    if (counter >= FLASH_ARC_NSEC_0)
    {
        uint8_t arcns = (uint8_t) (*((uint32_t *) MRAM_PRV_OFS_ARCCS_ADDR) & MRAM_PRV_OFS_ARCCS_ARCNS_Msk);
        max_count = (arcns == MRAM_PRV_ARCNS_MULTIPLE) ?
                    BSP_FEATURE_FLASH_ARC_NSEC_MULTIPLE_MAX_COUNT : BSP_FEATURE_FLASH_ARC_NSEC_SINGLE_MAX_COUNT;
    }
    else if (counter == FLASH_ARC_OEMBL)
    {
        max_count = BSP_FEATURE_FLASH_ARC_OEMBL_MAX_COUNT;
    }
    else
    {
        max_count = BSP_FEATURE_FLASH_ARC_SEC_MAX_COUNT;
    }

    FSP_ERROR_RETURN((count + 1) <= max_count, FSP_ERR_OVERFLOW);

    /* Increment the counter */
    err =
        mram_arc_cmd_execute(p_ctrl, mcntselr, MRAM_PRV_MACI_CMD_INCREMENT_COUNTER, p_ctrl->timeout_arc_increment);

    return err;
}

/*******************************************************************************************************************//**
 * Stub function
 * Implements @ref flash_api_t::antiRollbackCounterRefresh
 *
 * @retval     FSP_ERR_UNSUPPORTED  Anti-Rollback counter refresh is not supported on this MCU
 **********************************************************************************************************************/
fsp_err_t R_MRAM_AntiRollbackCounterRefresh (flash_ctrl_t * const p_api_ctrl, flash_arc_t counter)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(counter);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Reads the selected anti-rollback counter and returns the number of counter bits set.
 *
 * Implements @ref flash_api_t::antiRollbackCounterRead
 *
 * @retval     FSP_SUCCESS          Counter read successfully into p_count
 * @retval     FSP_ERR_NOT_OPEN     The control block is not open.
 * @retval     FSP_ERR_ASSERTION    NULL provided for p_api_ctrl or p_count
 * @retval     FSP_ERR_NOT_ENABLED  The specified counter has not been configured (configuration is only required for ARC_NSEC)
 * @retval     FSP_ERR_TIMEOUT      Timed out waiting for the MACI to become ready.
 * @retval     FSP_ERR_CMD_LOCKED   MRAM Application Command Interface is in locked state
 * @retval     FSP_ERR_IN_USE       The MRAM peripheral is busy with a prior on-going transaction.
 * @retval     FSP_ERR_UNSUPPORTED  The Anti Rollback Counter requested is unsupported on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_MRAM_AntiRollbackCounterRead (flash_ctrl_t * const p_api_ctrl, flash_arc_t counter,
                                          uint32_t * const p_count)
{
    fsp_err_t err;

    mram_instance_ctrl_t * p_ctrl   = (mram_instance_ctrl_t *) p_api_ctrl;
    uint8_t                mcntselr = mram_counter_to_mcntselr_convert(counter);

#if MRAM_CFG_PARAM_CHECKING_ENABLE
    err = r_mram_arc_common_parameter_checking(p_ctrl, counter, mcntselr);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(p_count);
#endif

    /* Read the counter */
    err = mram_arc_read(p_ctrl, mcntselr, p_count);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return err;
}

/*******************************************************************************************************************//**
 * Stub function
 * Implements @ref flash_api_t::userLockableAreaWrite
 *
 * @retval     FSP_ERR_UNSUPPORTED  User Lockable Area is not supported on this MCU
 **********************************************************************************************************************/
fsp_err_t R_MRAM_UserLockableAreaWrite (flash_ctrl_t * const p_api_ctrl,
                                        uint32_t const       src_address,
                                        uint32_t             mram_address,
                                        uint32_t const       num_bytes)
{
    /* Eliminate warning. */
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(src_address);
    FSP_PARAMETER_NOT_USED(mram_address);
    FSP_PARAMETER_NOT_USED(num_bytes);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup MRAM)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Write data to the MRAM.
 *
 * @param[in]  src_address         Address of the data to be written
 * @param[in]  mram_address        Address of the MRAM to write
 * @param[in]  num_bytes           Number of bytes to write
 * @param[in]  mram_program_info   Structure of information written to MRAM
 *
 * @retval     FSP_SUCCESS         Write completed successfully
 **********************************************************************************************************************/
static fsp_err_t mram_write_data (uint32_t                          src_address,
                                  uint32_t                          mram_address,
                                  uint32_t                          num_bytes,
                                  mram_program_info_t const * const mram_program_info)
{
    fsp_err_t err = FSP_SUCCESS;

    uint8_t * p_dest_address       = (uint8_t *) (uintptr_t) mram_address;
    uint8_t * p_src_address        = (uint8_t *) (uintptr_t) src_address;
    uint32_t  operations_remaining = num_bytes;

    mram_program_control(mram_address, true);

    /* Follow the "Code MRAM programming procedure (smaller than 32-bytes programming)": Figure 66.4 of the
     * RX74M manual R01UH1055EJ0051. */
    while (operations_remaining > 0 && FSP_SUCCESS == err)
    {
        FSP_HARDWARE_REGISTER_WAIT((R_MRAM->MRCPS & mram_program_info->mrcps_prgbsyc_mask), 0);
        FSP_HARDWARE_REGISTER_WAIT((R_MRAM->MRCPS & mram_program_info->mrcps_abuffull_mask), 0);

        uint32_t arrignment_size = BSP_FEATURE_MRAM_PROGRAMMING_SIZE_BYTES -
                                   ((uint32_t) p_dest_address % BSP_FEATURE_MRAM_PROGRAMMING_SIZE_BYTES);
        uint32_t write_count = (arrignment_size <
                                operations_remaining) ? arrignment_size : operations_remaining;

        for (uint32_t i = 0; i < write_count; i++)
        {
            *p_dest_address = *p_src_address;
            p_dest_address += 1;
            p_src_address  += 1;
        }

        operations_remaining -= write_count;

        if (*p_dest_address != 0)
        {
            __NOP();
        }

        if (BSP_FEATURE_MRAM_PROGRAMMING_SIZE_BYTES != write_count)
        {
            R_MRAM->MRCFLR |= mram_program_info->mrcflr_flush_code;
        }

        FSP_HARDWARE_REGISTER_WAIT((R_MRAM->MRCPS & mram_program_info->mrcps_abufemp_mask),
                                   mram_program_info->mrcps_abufemp_mask);
        FSP_HARDWARE_REGISTER_WAIT((R_MRAM->MRCPS & mram_program_info->mrcps_prgbsyc_mask), 0);
    }

    mram_program_control(mram_address, false);

    return err;
}

/*******************************************************************************************************************//**
 * Erase the block at the start address in the control block.
 *
 * @param[in]  address          Address of the simulated block to start erasing
 * @param[in]  num_blocks       Number of simulated blocks to erase
 * @param[in]  mram_program_info   Structure of information written to MRAM
 *
 * @retval     FSP_SUCCESS     The erase completed successfully.
 **********************************************************************************************************************/
static fsp_err_t mram_erase_blocks (uint32_t                          address,
                                    uint32_t                          num_blocks,
                                    mram_program_info_t const * const mram_program_info)
{
    fsp_err_t err = FSP_SUCCESS;

    uint8_t * dest_address         = (uint8_t *) (uintptr_t) address;
    uint32_t  operations_remaining = num_blocks *
                                     (BSP_FEATURE_MRAM_PROGRAMMING_SIZE_BYTES /
                                      BSP_FEATURE_MRAM_PROGRAMMING_SIZE_BYTES);

    mram_program_control(address, true);

    /* Follow the "Code MRAM programming procedure (32-bytes programming)": Figure 67.3 of the
     * RX74M manual R01UH1055EJ0051. */
    while (0 < operations_remaining && FSP_SUCCESS == err)
    {
        FSP_HARDWARE_REGISTER_WAIT((R_MRAM->MRCPS & mram_program_info->mrcps_prgbsyc_mask), 0);
        FSP_HARDWARE_REGISTER_WAIT((R_MRAM->MRCPS & mram_program_info->mrcps_abuffull_mask), 0);

        for (uint32_t j = 0; j < BSP_FEATURE_MRAM_PROGRAMMING_SIZE_BYTES; j++)
        {
            *dest_address = UINT8_MAX;
            dest_address += 1;
        }

        operations_remaining--;

        FSP_HARDWARE_REGISTER_WAIT((R_MRAM->MRCPS & mram_program_info->mrcps_abufemp_mask),
                                   mram_program_info->mrcps_abufemp_mask);
        FSP_HARDWARE_REGISTER_WAIT((R_MRAM->MRCPS & mram_program_info->mrcps_prgbsyc_mask), 0);
    }

    mram_program_control(address, false);

    return err;
}

/*******************************************************************************************************************//**
 * Enable/Disable writing to MRAM
 *
 * @param[in]  address              Target address
 * @param[in]  enable               Enable/Disable flag
 **********************************************************************************************************************/
static void mram_program_control (uint32_t address, bool enable)
{
    FSP_PARAMETER_NOT_USED(address);
    if (enable)
    {
#if BSP_CFG_PREFETCH_BUFFER_ENABLE
        bsp_prv_clear_pfb();
#endif

        /* Enable highs-speed program mode. */
        R_MRAM->MRPSC = 1;
    }
    else
    {
        /* Disable high-speed program mode. */
        R_MRAM->MRPSC = 0;
        (void) R_MRAM->MRPSC;

#if BSP_CFG_PREFETCH_BUFFER_ENABLE
        bsp_prv_set_pfb();
#endif
    }

    /* Enable or Disable writing to Secure MRAM */
    R_MRAM->MRCPCS = (uint16_t) (MRAM_PRV_MRCPCS_KEY | enable);
}

/*******************************************************************************************************************//**
 * Check for errors after a MRAM operation
 *
 * @param[in]  p_ctrl              MRAM control block
 * @param[in]  previous_error      The previous error
 *
 * @retval     FSP_SUCCESS         Command completed successfully
 * @retval     FSP_ERR_CMD_LOCKED  MRAM entered command locked state
 * @retval     FSP_ERR_HUK_ZEROIZATION HUK ZEROIZATION command is executing.
 * @retval     FSP_ERR_TIMEOUT     Timeout executing the Forced Stop Command.
 **********************************************************************************************************************/
static fsp_err_t mram_check_errors (mram_instance_ctrl_t * const p_ctrl, fsp_err_t previous_error)
{
    /* See "Recovery from the Command-Locked State" in the MRAM section of the relevant hardware manual. */
    fsp_err_t err = FSP_SUCCESS;

    if (1U == R_MRAM->MASTAT_b.CMDLK)
    {
        err = FSP_ERR_CMD_LOCKED;
    }

    if (1U == R_MRAM->MREZS_b.WHUKEXE)
    {
        err = FSP_ERR_HUK_ZEROIZATION;
    }

    /* Return the first error code that was encountered. */
    if (FSP_SUCCESS != previous_error)
    {
        err = previous_error;
    }

    if (FSP_SUCCESS != err)
    {
        /* Stop the MRAM and return the previous error. */
        (void) mram_stop(p_ctrl);
    }

    return err;
}

#if (MRAM_CFG_PARAM_CHECKING_ENABLE == 1)

/*******************************************************************************************************************//**
 * This function performs the parameter checking required by the write, read and blank check functions.
 *
 * @param[in]  p_ctrl                   MRAM control block
 * @param[in]  mram_address             The MRAM address to be written to
 * @param[in]  num_bytes                The number bytes
 * @param[in]  size_err                 Error to report when the size is invalid.
 *
 * @retval     FSP_SUCCESS              Parameter checking completed without error.
 * @retval     FSP_ERR_IN_USE           The MRAM peripheral is busy with a prior on-going transaction.
 * @retval     FSP_ERR_NOT_OPEN         The MRAM API is not Open.
 * @retval     FSP_ERR_ASSERTION        Null pointer
 * @retval     FSP_ERR_INVALID_ADDRESS  Invalid address was input or address not on programming boundary.
 **********************************************************************************************************************/
static fsp_err_t r_mram_write_erase_parameter_checking (mram_instance_ctrl_t * const p_ctrl,
                                                        uint32_t                     mram_address,
                                                        uint32_t const               num_bytes,
                                                        fsp_err_t                    size_err)
{
    /* Verify the control block is not null and is opened. Verify the MRAM isn't in use. */
    fsp_err_t err = r_mram_common_parameter_checking(p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    if (mram_address >= BSP_FLASH_CODE_FLASH_START_ADDRESS)
    {
        FSP_ERROR_RETURN(BSP_FLASH_CODE_FLASH_START_ADDRESS <= mram_address, FSP_ERR_INVALID_ADDRESS);
        FSP_ERROR_RETURN(mram_address < (BSP_FLASH_CODE_FLASH_START_ADDRESS - 1) + BSP_ROM_SIZE_BYTES,
                         FSP_ERR_INVALID_ADDRESS);
        FSP_ERROR_RETURN(mram_address <= (((BSP_FLASH_CODE_FLASH_START_ADDRESS - 1) + BSP_ROM_SIZE_BYTES) - num_bytes),
                         size_err);
    }
    else
    {
        FSP_ERROR_RETURN(BSP_FEATURE_FLASH_DATA_FLASH_START <= mram_address, FSP_ERR_INVALID_ADDRESS);
        FSP_ERROR_RETURN(mram_address < (BSP_FEATURE_FLASH_DATA_FLASH_START - 1) + BSP_DATA_FLASH_SIZE_BYTES,
                         FSP_ERR_INVALID_ADDRESS);
        FSP_ERROR_RETURN(mram_address <= ((BSP_FEATURE_FLASH_DATA_FLASH_START + BSP_DATA_FLASH_SIZE_BYTES) - num_bytes),
                         size_err);
    }

    /* If invalid number of bytes return error. */
    FSP_ERROR_RETURN((0 != num_bytes), size_err);

    return FSP_SUCCESS;
}

#endif

#if (MRAM_CFG_PARAM_CHECKING_ENABLE == 1)

/*******************************************************************************************************************//**
 * This function performs the common parameter checking required by top level API functions.
 *
 * @param      p_ctrl             Pointer to the control block
 *
 * @retval     FSP_SUCCESS        Parameter checking completed without error.
 * @retval     FSP_ERR_ASSERTION  Null pointer
 * @retval     FSP_ERR_NOT_OPEN   The MRAM module is not open.
 * @retval     FSP_ERR_IN_USE     The MRAM peripheral is busy with a prior on-going transaction.
 **********************************************************************************************************************/
static fsp_err_t r_mram_common_parameter_checking (mram_instance_ctrl_t * const p_ctrl)
{
    /* If null control block return error. */
    FSP_ASSERT(p_ctrl);

    /* If control block is not open return error. */
    FSP_ERROR_RETURN((MRAM_PRV_OPEN == p_ctrl->opened), FSP_ERR_NOT_OPEN);

    /* If the MRAM is currently in program/erase mode return an error. */
    FSP_ERROR_RETURN((R_MRAM->MENTRYR & MRAM_PRV_MENTRYR_PE_MODE_BITS) == 0x0000U, FSP_ERR_IN_USE);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * This function performs the common parameter checking required by top level Anti Rollback Counter API functions.
 *
 * @param      p_ctrl                Pointer to the control block
 * @param      counter               The counter to be incremented or read
 * @param      mcntselr              The current setting of the MCNTSELR : MRAM Counter Select Register
 *
 * @retval     FSP_SUCCESS           Parameter checking completed without error.
 * @retval     FSP_ERR_ASSERTION     Null pointer
 * @retval     FSP_ERR_IN_USE        The MRAM peripheral is busy with a prior on-going transaction.
 * @retval     FSP_ERR_NOT_OPEN      The MRAM module is not open.
 * @retval     FSP_ERR_UNSUPPORTED   The Anti Rollback Counter requested is unsupported on this MCU.
 * @retval     FSP_ERR_NOT_ENABLED   The specified counter has not been configured.
 **********************************************************************************************************************/
static fsp_err_t r_mram_arc_common_parameter_checking (mram_instance_ctrl_t * const p_ctrl,
                                                       flash_arc_t                  counter,
                                                       uint8_t                      mcntselr)
{
    fsp_err_t err = r_mram_common_parameter_checking(p_ctrl);
    FSP_ERROR_RETURN(err == FSP_SUCCESS, err);

    uint8_t arcns =
        (uint8_t) ((*((uint32_t *) MRAM_PRV_OFS_ARCCS_ADDR) &
                    (MRAM_PRV_OFS_ARCCS_ARCNS_Msk << MRAM_PRV_OFS_ARCCS_ARCNS_OFFSET)) >>
                   MRAM_PRV_OFS_ARCCS_ARCNS_OFFSET);
    uint8_t target_counter_is_arc_ns  = (uint8_t) (mcntselr & 0x4);
    uint8_t target_counter_is_enabled = (uint8_t) ((MRAM_PRV_ARCNS_MULTIPLE == arcns) ||
                                                   ((MRAM_PRV_ARCNS_SINGLE == arcns) && (counter == FLASH_ARC_NSEC_0)));

    uint8_t arcs =
        (uint8_t) ((*((uint32_t *) MRAM_PRV_OFS_ARCCS_ADDR) &
                    (MRAM_PRV_OFS_ARCCS_ARCS_Msk << MRAM_PRV_OFS_ARCCS_ARCS_OFFSET)) >>
                   MRAM_PRV_OFS_ARCCS_ARCS_OFFSET);
    uint8_t target_counter_is_arc_s     = (uint8_t) (((mcntselr & 0x1U) != 0U) && ((mcntselr & 0x4U) == 0U));
    uint8_t target_counter_is_enabled_s = (uint8_t) ((MRAM_PRV_ARCS_MODE1 == arcs) || (MRAM_PRV_ARCS_MODE2 == arcs));

    /* Ensure that requested counter is supported by hardware. Some MCUs may not support all counter types. */
 #if (0 == BSP_FEATURE_FLASH_ARC_OEMBL_MAX_COUNT)
    FSP_ERROR_RETURN(counter != FLASH_ARC_OEMBL, FSP_ERR_UNSUPPORTED);
 #endif

 #if (0 == BSP_FEATURE_FLASH_ARC_SEC_MAX_COUNT)
    FSP_ERROR_RETURN(counter != FLASH_ARC_SEC, FSP_ERR_UNSUPPORTED);
    FSP_ERROR_RETURN(0 == target_counter_s_is_arc, FSP_ERR_UNSUPPORTED);
 #endif

 #if (0 == BSP_FEATURE_FLASH_ARC_NSEC_NUM_COUNTERS)
    FSP_ERROR_RETURN(0 == target_counter_is_arc_ns, FSP_ERR_UNSUPPORTED);
 #endif

    /* Ensure that requested NSEC counter has been configured when NSEC is the target counter */
    FSP_ERROR_RETURN(!target_counter_is_arc_ns || target_counter_is_enabled, FSP_ERR_NOT_ENABLED);

    /* Ensure that requested SEC counter has been configured when SEC is the target counter */
    FSP_ERROR_RETURN(!target_counter_is_arc_s || target_counter_is_enabled_s, FSP_ERR_NOT_ENABLED);

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * This function converts the MRAM API counter enumeration to the register value for MCNTSELR
 *
 * @param counter The API counter value
 *
 * @returns MCNTSELR value
 **********************************************************************************************************************/
static uint8_t mram_counter_to_mcntselr_convert (flash_arc_t counter)
{
    return (uint8_t) ((counter < FLASH_ARC_NSEC_0 ? counter + 1 : counter + 2) & R_MRAM_MCNTSELR_CNTSEL_Msk);
}

/*******************************************************************************************************************//**
 * This function reads the anti-rollback counter value
 *
 * ARC_OEMBL is read by MACI command because it is required to be read before increment to support RSIP-E50D comparison
 * by the MACI controller. The other counters are read by memory-mapped read.
 *
 * @param p_ctrl     MRAM control block
 * @param mcntselr   MCNTSELR register value
 * @param p_count    The counter value
 *
 * @returns mCNTSELR value
 **********************************************************************************************************************/
static fsp_err_t mram_arc_read (mram_instance_ctrl_t * const p_ctrl, uint8_t mcntselr, uint32_t * const p_count)
{
    fsp_err_t           err;
    volatile uint32_t * p_src;
    uint32_t            counter_num_words;
    uint32_t            arc_oembl[2];

    switch (mcntselr)
    {
        case MRAM_PRV_ARC_MCNTSELR_OEMBL:
        {
            err = mram_arc_cmd_execute(p_ctrl, mcntselr, MRAM_PRV_MACI_CMD_READ_COUNTER, p_ctrl->timeout_arc_read);
            FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

            /* Read the counter values after successful MACI read command */
            arc_oembl[0] = R_MRAM->MCNTDTR0;
            arc_oembl[1] = R_MRAM->MCNTDTR1;

            p_src             = arc_oembl;
            counter_num_words = BSP_FEATURE_FLASH_ARC_OEMBL_MAX_COUNT >> 5;
            break;
        }

        case MRAM_PRV_ARC_MCNTSELR_SEC:
        {
            p_src             = (uint32_t *) MRAM_PRV_OFS_ARC_SEC_ADDR;
            counter_num_words = BSP_FEATURE_FLASH_ARC_SEC_MAX_COUNT >> 5;
            break;
        }

        default:                       // ARC_NSEC
        {
            uint8_t arcns =
                (uint8_t) ((*((uint32_t *) MRAM_PRV_OFS_ARCCS_ADDR) & MRAM_PRV_OFS_ARCCS_ARCNS_Msk) >>
                           MRAM_PRV_OFS_ARCCS_ARCNS_OFFSET);
            p_src = (uint32_t *) MRAM_PRV_OFS_ARC_NSEC_ADDR;

            if (MRAM_PRV_ARCNS_MULTIPLE == arcns)
            {
                counter_num_words = BSP_FEATURE_FLASH_ARC_NSEC_MULTIPLE_MAX_COUNT >> 5; // bits to words
                uint32_t counter_index = ((uint32_t) mcntselr - MRAM_PRV_ARC_MCNTSELR_NSEC_0) * counter_num_words;
                p_src = &p_src[counter_index];
            }
            else if (MRAM_PRV_ARCNS_SINGLE == arcns)
            {
                counter_num_words = BSP_FEATURE_FLASH_ARC_NSEC_SINGLE_MAX_COUNT >> 5;
            }
            else
            {
                return FSP_ERR_NOT_ENABLED;
            }

            break;
        }
    }

    /* Determine the number of bits set in the counter data. This is the actual count value. */
    uint32_t count = 0;

    for (uint8_t word = 0; word < counter_num_words; word += 2)
    {
        uint32_t lo = p_src[word];
        uint32_t hi = p_src[1 + word];
        count += MRAM_PRV_64_BITS - ((uint32_t) __CLZ(hi) + (uint32_t) __CLZ(lo));
    }

    *p_count = count;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * This function executes an anti-rollback counter MACI operation (read and increment)
 *
 * @param[in]  p_ctrl                      MRAM control block
 * @param[in]  mcntselr                    Register value to write to mCNTSELR to select the target counter
 * @param[in]  cmd                         The MACI command to use
 * @param[in]  wait_count                  The command timeout
 *
 * @returns mCNTSELR value
 **********************************************************************************************************************/
static fsp_err_t mram_arc_cmd_execute (mram_instance_ctrl_t * const p_ctrl,
                                       uint8_t                      mcntselr,
                                       uint8_t                      cmd,
                                       volatile uint32_t            wait_count)
{
    fsp_err_t err = FSP_SUCCESS;

    /* Enter MRAM P/E mode. */
    mram_enter_pe_mode();

    /* Select target counter */
    R_MRAM->MCNTSELR = mcntselr;

    /* Issue 2-part command to the MACI command-issuing area */
    MRAM_PRV_CMD->MACI_CMD8 = cmd;
    MRAM_PRV_CMD->MACI_CMD8 = MRAM_PRV_MACI_CMD_FINAL;

    /* Wait for MRDY flag or timeout */
    while (1U != R_MRAM->MSTATR_b.MRDY)
    {
        if (wait_count == 0U)
        {
            err = FSP_ERR_TIMEOUT;
            break;
        }

        wait_count--;
    }

    /* Check for errors and issue forced stop if error occurred */
    err = mram_check_errors(p_ctrl, err);

    /* Return to read mode*/
    fsp_err_t pe_exit_err = mram_transition_to_read_mode(p_ctrl);

    if (FSP_SUCCESS == err)
    {
        err = pe_exit_err;
    }

    return err;
}

/*******************************************************************************************************************//**
 * This function switches the peripheral to P/E mode for Extra MRAM.
 * See "Transition to Extra MRAM Program Mode" in the MRAM section of the relevant hardware manual.
 **********************************************************************************************************************/
static void mram_enter_pe_mode (void)
{
#if BSP_CFG_PREFETCH_BUFFER_ENABLE

    /* While the MRAM API is in use we will disable the MRAM PFB. */
    bsp_prv_clear_pfb();
#endif

    /* Enter Extra MRAM PE mode */
    R_MRAM->MENTRYR = MRAM_PRV_MENTRYR_TRANSITION_TO_PE;

    /* Wait until MENTRYR has entered P/E mode. */
    FSP_HARDWARE_REGISTER_WAIT(R_MRAM->MENTRYR, MRAM_PRV_MENTRYR_PE_MODE);
}

/*******************************************************************************************************************//**
 * This function will initialize the internal timeout values based on the system clock frequency.
 *
 * @param      p_ctrl        Pointer to the instance control block
 * @retval     FSP_SUCCESS   Clock and timeouts configured successfully.
 **********************************************************************************************************************/
static void mram_init (mram_instance_ctrl_t * p_ctrl)
{
    uint32_t system_clock_freq_hz = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_CPUCLK);

    /* Round up the frequency to a whole number */
    uint32_t system_clock_freq_mhz = (system_clock_freq_hz + (MRAM_PRV_FREQUENCY_IN_HZ - 1)) /
                                     MRAM_PRV_FREQUENCY_IN_HZ;

    /* The calculation below calculates the number of ICLK ticks needed for the timeout delay. */

    /* According to RX74M manual R01UH1055EJ0051 the Max Programming Time for 32 bytes is 87.3us. */
    p_ctrl->timeout_mram_write = (uint32_t) (MRAM_PRV_MAX_MRAM_WRITE_US * system_clock_freq_mhz) /
                                 MRAM_PRV_MINIMUM_CYCLES_PER_TIMEOUT_LOOP;

    /* According to RX74M manual R01UH1055EJ0051 the max time for a MACI command is 3.7us. */
    p_ctrl->timeout_maci_command =
        (uint32_t) (MRAM_PRV_MAX_MACI_COMMAND_US * system_clock_freq_mhz) /
        MRAM_PRV_MINIMUM_CYCLES_PER_TIMEOUT_LOOP;

    /* According to RX74M manual R01UH1055EJ0051 the max time for a configuration set command is 9.42ms. */
    p_ctrl->timeout_configuration_set = (uint32_t) (MRAM_PRV_MAX_CONFIGURATION_SET_US * system_clock_freq_mhz) /
                                        MRAM_PRV_MINIMUM_CYCLES_PER_TIMEOUT_LOOP;

    /* According to table "MACI command Characteristics" in the Electrical Characteristics section of the relevant hardware manual the max time for ARC increment command is 1.61ms. */
    p_ctrl->timeout_arc_increment =
        (uint32_t) (MRAM_PRV_MAX_ARC_INCREMENT_US * system_clock_freq_mhz) /
        MRAM_PRV_MINIMUM_CYCLES_PER_TIMEOUT_LOOP;

    /* According to table "MACI command Characteristics" in the Electrical Characteristics section of the relevant hardware manual the max time for ARC read command is 0.27us. */
    p_ctrl->timeout_arc_read =
        (uint32_t) (MRAM_PRV_MAX_ARC_READ_US * system_clock_freq_mhz) /
        MRAM_PRV_MINIMUM_CYCLES_PER_TIMEOUT_LOOP;
}

/*******************************************************************************************************************//**
 * This function switches the peripheral from P/E mode for Extra MRAM to Read mode.
 * @param[in]  p_ctrl              Pointer to the MRAM instance control block.
 *
 * @retval     FSP_SUCCESS         Command completed successfully
 * @retval     FSP_ERR_TIMEOUT     Timeout executing the Forced Stop Command.
 * @retval     FSP_ERR_CMD_LOCKED  MRAM entered command locked state
 * @retval     FSP_ERR_HUK_ZEROIZATION HUK ZEROIZATION command executing
 **********************************************************************************************************************/
static fsp_err_t mram_transition_to_read_mode (mram_instance_ctrl_t * p_ctrl)
{
    /* See "Transition to Read Mode" in the MRAM section of the relevant hardware manual. */
    /* MRDY and CMDLK are checked after the previous commands complete and do not need to be checked again. */
    fsp_err_t err = FSP_SUCCESS;

    uint32_t wait_count = p_ctrl->timeout_maci_command;

    /* Wait for MRDY flag or timeout */
    while (1U != R_MRAM->MSTATR_b.MRDY)
    {
        if (wait_count == 0U)
        {
            err = FSP_ERR_TIMEOUT;
            break;
        }

        wait_count--;
    }

    err = mram_check_errors(p_ctrl, err);

    /* Transition to Read mode */
    R_MRAM->MENTRYR = MRAM_PRV_MENTRYR_READ_MODE;
    FSP_HARDWARE_REGISTER_WAIT(R_MRAM->MENTRYR, 0);

#if BSP_CFG_PREFETCH_BUFFER_ENABLE
    bsp_prv_set_pfb();
#endif

    return err;
}

/*******************************************************************************************************************//**
 * This function is used to force stop the MRAM during an ongoing operation.
 * @param[in]  p_ctrl              Pointer to the MRAM instance control block.
 *
 * @retval     FSP_SUCCESS         Successful stop.
 * @retval     FSP_ERR_TIMEOUT     Timeout executing the Forced Stop Command.
 * @retval     FSP_ERR_CMD_LOCKED  Peripheral in command locked state.
 * @retval     FSP_ERR_HUK_ZEROIZATION HUK ZEROIZATION command is executing
 **********************************************************************************************************************/
static fsp_err_t mram_stop (mram_instance_ctrl_t * p_ctrl)
{
    /* See "Forced Stop Command" in the MRAM section of the relevant hardware manual. If the CMDLK bit
     * is still set after issuing the force stop command return an error. */
    volatile uint32_t wait_count = p_ctrl->timeout_maci_command;

    MRAM_PRV_CMD->MACI_CMD8 = (uint8_t) MRAM_PRV_MACI_CMD_FORCED_STOP;

    while (1U != R_MRAM->MSTATR_b.MRDY)
    {
        if (wait_count == 0U)
        {
            return FSP_ERR_TIMEOUT;
        }

        wait_count--;
    }

    if (0U != R_MRAM->MASTAT_b.CMDLK)
    {
        return FSP_ERR_CMD_LOCKED;
    }

    if (1U == R_MRAM->MREZS_b.WHUKEXE)
    {
        return FSP_ERR_HUK_ZEROIZATION;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Write data to the DataMRAM.
 *
 * @param[in]  src_address         Address of the data to be written
 * @param[in]  mram_address        Address of the MRAM to write
 * @param[in]  num_bytes           Number of bytes to write
 *
 * @retval     FSP_SUCCESS         Write completed successfully
 **********************************************************************************************************************/
static fsp_err_t mram_df_write_data (uint32_t src_address, uint32_t mram_address, uint32_t num_bytes)
{
    fsp_err_t err = FSP_SUCCESS;

    uint8_t * p_dest_address       = (uint8_t *) (uintptr_t) mram_address;
    uint8_t * p_src_address        = (uint8_t *) (uintptr_t) src_address;
    uint32_t  operations_remaining = num_bytes;

    mram_program_control(mram_address, true);

    /* Follow the "Data MRAM programming procedure (smaller than 16-bytes programming)": Figure 67.3 of the
     * RX74M manual R01UH1055EJ0051. */
    while (operations_remaining > 0 && FSP_SUCCESS == err)
    {
        FSP_HARDWARE_REGISTER_WAIT(R_MRAM->MRDPS_b.PRGBSYD, 0);
        FSP_HARDWARE_REGISTER_WAIT(R_MRAM->MRDPS_b.ABUFFULLD, 0);
        uint32_t write_count =
            (operations_remaining <
             BSP_FEATURE_DATA_MRAM_PROGRAMMING_SIZE_BYTES) ? operations_remaining :
            BSP_FEATURE_DATA_MRAM_PROGRAMMING_SIZE_BYTES -
            ((uint32_t) p_dest_address % BSP_FEATURE_DATA_MRAM_PROGRAMMING_SIZE_BYTES);
        for (uint32_t i = 0; i < write_count; i++)
        {
            *p_dest_address = *p_src_address;
            p_dest_address += 1;
            p_src_address  += 1;
        }

        operations_remaining -= write_count;

        if (BSP_FEATURE_DATA_MRAM_PROGRAMMING_SIZE_BYTES != write_count)
        {
            R_MRAM->MRDFLR = MRAM_PRV_MRDFLR_FLUSH;
        }

        FSP_HARDWARE_REGISTER_WAIT(R_MRAM->MRDPS_b.ABUFEMPD, 1);
        FSP_HARDWARE_REGISTER_WAIT(R_MRAM->MRDPS_b.PRGBSYD, 0);
    }

    mram_program_control(mram_address, false);

    return err;
}

/*******************************************************************************************************************//**
 * Erase the block at the start address in the control block.
 *
 * @param[in]  address          Address of the simulated block to start erasing
 * @param[in]  num_blocks       Number of simulated blocks to erase
 *
 * @retval     FSP_SUCCESS     The erase completed successfully.
 **********************************************************************************************************************/
static fsp_err_t mram_df_erase_blocks (uint32_t address, uint32_t num_blocks)
{
    fsp_err_t err = FSP_SUCCESS;

    uint8_t * dest_address         = (uint8_t *) (uintptr_t) address;
    uint32_t  operations_remaining = num_blocks *
                                     (BSP_FEATURE_DATA_MRAM_PROGRAMMING_SIZE_BYTES /
                                      BSP_FEATURE_DATA_MRAM_PROGRAMMING_SIZE_BYTES);

    mram_program_control(address, true);

    /* Follow the "Data MRAM programming procedure (16-bytes programming)": Figure 67.3 of the
     * RX74M manual R01UH1055EJ0051. */
    while (0 < operations_remaining && FSP_SUCCESS == err)
    {
        FSP_HARDWARE_REGISTER_WAIT(R_MRAM->MRDPS_b.PRGBSYD, 0);
        FSP_HARDWARE_REGISTER_WAIT(R_MRAM->MRDPS_b.ABUFFULLD, 0);

        for (uint32_t j = 0; j < BSP_FEATURE_DATA_MRAM_PROGRAMMING_SIZE_BYTES; j++)
        {
            *dest_address = UINT8_MAX;
            dest_address += 1;
        }

        operations_remaining--;

        FSP_HARDWARE_REGISTER_WAIT(R_MRAM->MRDPS_b.ABUFEMPD, 1);
        FSP_HARDWARE_REGISTER_WAIT(R_MRAM->MRDPS_b.PRGBSYD, 0);
    }

    mram_program_control(address, false);

    return err;
}

/*******************************************************************************************************************//**
 * Calculate the operation start address in MRAM.
 *
 * @param[in]  area               write MRAM area number (0 = MRCA, 1 = MRCB)
 * @param[in]  mram_address       Operation start address
 * @param[in]  num_bytes          Operation size
 * @param[in]  write_mram_address Pointer to store the calculated operation start address within the target MRAM area.
 *
 * @retval     Operation data size in bytes.
 *             Returns 0 if there is no data to operate.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t mram_calc_operation_address (uint8_t    area,
                                                      uint32_t   mram_address,
                                                      uint32_t   num_bytes,
                                                      uint32_t * write_mram_address)
{
    /* Check if the data is within the valid range  */
    if ((mram_address < g_code_mram_macro_info[area].block_section_end_addr) &&
        ((mram_address + num_bytes - 1) >= g_code_mram_macro_info[area].block_section_st_addr))
    {
        /* Operation start address in each Code MRAM area */
        *write_mram_address =
            (g_code_mram_macro_info[area].block_section_st_addr >
             mram_address) ? g_code_mram_macro_info[area].block_section_st_addr : mram_address;

        /* End address of the operation requested by the API */
        uint32_t mram_end_address = (mram_address + num_bytes - 1);

        /* Returns the size used for the operation */
        return (g_code_mram_macro_info[area].block_section_end_addr >
                mram_end_address) ? (mram_end_address - *write_mram_address + 1) :
               (g_code_mram_macro_info[area].block_section_end_addr - *write_mram_address + 1);
    }

    return 0;
}
