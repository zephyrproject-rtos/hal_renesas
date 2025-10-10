/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "bsp_api.h"

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_xspi_qspi.h"

#if XSPI_QSPI_CFG_OTFD_SUPPORT_ENABLE
 #include "r_rsip.h"
#endif

#if XSPI_QSPI_CFG_DMAC_SUPPORT_ENABLE
 #include "r_dmac.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define XSPI_QSPI_PRV_OPEN                               (0x51535049)

#define XSPI_QSPI_PRV_LIOCFGCS_PRTMD_OFFSET              (0U)
#define XSPI_QSPI_PRV_LIOCFGCS_PRTMD_VALUE_MASK          (0x3FFU)
#define XSPI_QSPI_PRV_LIOCFGCS_PRTMD_MASK                (0x3FFU << XSPI_QSPI_PRV_LIOCFGCS_PRTMD_OFFSET)
#define XSPI_QSPI_PRV_LIOCFGCS_CSMIN_OFFSET              (16U)
#define XSPI_QSPI_PRV_LIOCFGCS_CSMIN_VALUE_MASK          (0x0FU)
#define XSPI_QSPI_PRV_LIOCFGCS_CSASTEX_OFFSET            (20U)
#define XSPI_QSPI_PRV_LIOCFGCS_CSASTEX_VALUE_MASK        (0x01U)
#define XSPI_QSPI_PRV_LIOCFGCS_CSENGEX_OFFSET            (21U)
#define XSPI_QSPI_PRV_LIOCFGCS_CSENGEX_VALUE_MASK        (0x01U)

#define XSPI_QSPI_PRV_CMCFG0_FFMT_OFFSET                 (0U)
#define XSPI_QSPI_PRV_CMCFG0_ADDSIZE_OFFSET              (2U)
#define XSPI_QSPI_PRV_CMCFG0_ADDSIZE_VALUE_MASK          (0x03U)
#define XSPI_QSPI_PRV_CMCFG1_RDCMD_UPPER_OFFSET          (8U)
#define XSPI_QSPI_PRV_CMCFG1_RDCMD_VALUE_MASK            (0xFFU)
#define XSPI_QSPI_PRV_CMCFG1_RDLATE_OFFSET               (16U)
#define XSPI_QSPI_PRV_CMCFG1_RDLATE_VALUE_MASK           (0x1FU)

#define XSPI_QSPI_PRV_CMCFG2_WRCMD_UPPER_OFFSET          (8U)
#define XSPI_QSPI_PRV_CMCFG1_WRCMD_VALUE_MASK            (0xFFU)
#define XSPI_QSPI_PRV_CMCFG2_WRLATE_OFFSET               (16U)

#define XSPI_QSPI_PRV_BMCFG_WRMD_OFFSET                  (0U)
#define XSPI_QSPI_PRV_BMCFG_MWRCOMB_OFFSET               (7U)
#define XSPI_QSPI_PRV_BMCFG_MWRSIZE_OFFSET               (8U)
#define XSPI_QSPI_PRV_BMCFG_PREEN_OFFSET                 (16U)
#define XSPI_QSPI_PRV_BMCFG_PREEN_VALUE_MASK             (0x01U)

#define XSPI_QSPI_PRV_BMCTL_DEFAULT_VALUE                (0x000000FFUL)

#define XSPI_QSPI_PRV_BMCTL_CSNACC_R_ENABLE              (0x01U)
#define XSPI_QSPI_PRV_BMCTL_CSNACC_R_W_ENABLE            (0x03U)

#define XSPI_QSPI_PRV_CDTBUF_CMDSIZE_OFFSET              (0U)
#define XSPI_QSPI_PRV_CDTBUF_CMDSIZE_VALUE_MASK          (0x03U)
#define XSPI_QSPI_PRV_CDTBUF_ADDSIZE_OFFSET              (2U)
#define XSPI_QSPI_PRV_CDTBUF_ADDSIZE_VALUE_MASK          (0x07U)
#define XSPI_QSPI_PRV_CDTBUF_DATASIZE_OFFSET             (5U)
#define XSPI_QSPI_PRV_CDTBUF_DATASIZE_VALUE_MASK         (0x0FU)
#define XSPI_QSPI_PRV_CDTBUF_LATE_OFFSET                 (9U)
#define XSPI_QSPI_PRV_CDTBUF_LATE_VALUE_MASK             (0x1FU)
#define XSPI_QSPI_PRV_CDTBUF_TRTYPE_OFFSET               (15U)
#define XSPI_QSPI_PRV_CDTBUF_TRTYPE_VALUE_MASK           (0x01U)
#define XSPI_QSPI_PRV_CDTBUF_CMD_UPPER_OFFSET            (24U)
#define XSPI_QSPI_PRV_CDTBUF_CMD_VALUE_MASK              (0xFFU)

#define XSPI_QSPI_PRV_COMSTT_MEMACC_OFFSET               (0U)
#define XSPI_QSPI_PRV_COMSTT_MEMACC_VALUE_MASK           (0x01U)
#define XSPI_QSPI_PRV_COMSTT_WRBUFNE_OFFSET              (6U)
#define XSPI_QSPI_PRV_COMSTT_WRBUFNE_VALUE_MASK          (0x01U)

#define XSPI_QSPI_PRV_INTC_CMDCMPC_OFFSET                (0U)

#define XSPI_QSPI_PRV_DEVICE_WRITE_STATUS_BIT_MASK       (1U)

#define XSPI_QSPI_PRV_MAX_COMBINE_SIZE                   (64U)

#define XSPI_QSPI_PRV_WORD_ACCESS_SIZE                   (4U)
#define XSPI_QSPI_PRV_HALF_WORD_ACCESS_SIZE              (2U)

#define XSPI_QSPI_PRV_1MB_MEMORY_SPACE                   (0xFFFFFU)
#define XSPI_QSPI_PRV_MEMORY_SIZE_SHIFT                  (20U)
#define XSPI_QSPI_PRV_DIRECT_TRANSFER_MAX_BYTES          (8U)

#define XSPI_QSPI_PRV_UINT32_BITS                        (32U)
#define XSPI_QSPI_UNIT_FLAG_MASK                         (3U)

#define XSPI_QSPI_BUFFER_WRITE_WAIT_CYCLE                (5U)

#if BSP_FEATURE_XSPI_OTFD_SUPPORTED
 #define XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET             (16U)
 #define XSPI_QSPI_PRV_MSTP_CTRL_BUS_STOP_MASK           (0x01U)
 #define XSPI_QSPI_PRV_MSTP_CTRL_BUS_STOP_ACK_MASK       (0x02U)
 #define XSPI_QSPI_PRV_MSTP_CTRL_MODULE_STOP_MASK        (0x10U)
 #define XSPI_QSPI_PRV_MSTP_CTRL_MODULE_STOP_ACK_MASK    (0x20U)
#endif

#define XSPI_QSPI_PRV_OTFD_REG00_RESET_VALUE             (0x22000000)
#define XSPI_QSPI_PRV_OTFD_SEED_1_SEED_MASK              (0x3)
#define XSPI_QSPI_PRV_OTFD_SEED_1_ENABLE_MASK            (0xC)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Number of address bytes in 4 byte address mode. */
#define QSPI_4_BYTE_ADDRESS                              (4U)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void      r_xspi_qspi_write_enable(xspi_qspi_instance_ctrl_t * p_instance_ctrl);
static bool      r_xspi_qspi_status_sub(xspi_qspi_instance_ctrl_t * p_instance_ctrl);
static fsp_err_t r_xspi_qspi_xip(xspi_qspi_instance_ctrl_t * p_instance_ctrl, uint8_t code, bool enter_mode);
static void      r_xspi_qspi_direct_transfer(xspi_qspi_instance_ctrl_t         * p_instance_ctrl,
                                             spi_flash_direct_transfer_t * const p_transfer,
                                             spi_flash_direct_transfer_dir_t     direction);

#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_xspi_qspi_param_checking_dcom(xspi_qspi_instance_ctrl_t * p_instance_ctrl);
static fsp_err_t r_xspi_qspi_program_param_check(xspi_qspi_instance_ctrl_t * p_instance_ctrl,
                                                 uint8_t const * const       p_src,
                                                 uint8_t * const             p_dest,
                                                 uint32_t                    byte_count);

#endif

#if XSPI_QSPI_CFG_OTFD_SUPPORT_ENABLE
static fsp_err_t r_xspi_qspi_otfd_side_channal_seed_init(uint32_t p_seed[]);
static fsp_err_t r_xspi_qspi_otfd_setup(xspi_qspi_instance_ctrl_t * p_instance_ctrl);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* Bit-flags specifying which channels are open so the module can be stopped when all are closed. */
static uint32_t g_xspi_qspi_channels_open_flags = 0;

#if XSPI_QSPI_CFG_OTFD_SUPPORT_ENABLE
static rsip_instance_ctrl_t g_xspi_qspi_rsip_ctrl;
static const rsip_cfg_t     g_xspi_qspi_rsip_cfg;

#endif

/*******************************************************************************************************************//**
 * @addtogroup XSPI_QSPI
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

const spi_flash_api_t g_spi_flash_on_xspi_qspi =
{
    .open           = R_XSPI_QSPI_Open,
    .directWrite    = R_XSPI_QSPI_DirectWrite,
    .directRead     = R_XSPI_QSPI_DirectRead,
    .directTransfer = R_XSPI_QSPI_DirectTransfer,
    .spiProtocolSet = R_XSPI_QSPI_SpiProtocolSet,
    .write          = R_XSPI_QSPI_Write,
    .erase          = R_XSPI_QSPI_Erase,
    .statusGet      = R_XSPI_QSPI_StatusGet,
    .xipEnter       = R_XSPI_QSPI_XipEnter,
    .xipExit        = R_XSPI_QSPI_XipExit,
    .bankSet        = R_XSPI_QSPI_BankSet,
    .autoCalibrate  = R_XSPI_QSPI_AutoCalibrate,
    .close          = R_XSPI_QSPI_Close,
};

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Open the QSPI driver module. After the driver is open, the QSPI can be accessed like internal flash memory starting
 * at address 0x60000000 or 0x40000000.
 *
 * Implements @ref spi_flash_api_t::open.
 *
 * @retval FSP_SUCCESS                    Configuration was successful.
 * @retval FSP_ERR_ASSERTION              The parameter p_instance_ctrl or p_cfg is NULL.
 * @retval FSP_ERR_ALREADY_OPEN           Driver has already been opened with the same p_instance_ctrl.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The requested channel does not exist on this MCU.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_Open (spi_flash_ctrl_t * p_ctrl, spi_flash_cfg_t const * const p_cfg)
{
    xspi_qspi_instance_ctrl_t * p_instance_ctrl = (xspi_qspi_instance_ctrl_t *) p_ctrl;

#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(XSPI_QSPI_PRV_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Make sure this unit exists. */
    FSP_ERROR_RETURN(BSP_FEATURE_XSPI_CHANNELS & (1U << ((xspi_qspi_extended_cfg_t *) p_cfg->p_extend)->unit),
                     FSP_ERR_IP_CHANNEL_NOT_PRESENT);
#endif

    xspi_qspi_extended_cfg_t * p_cfg_extend = (xspi_qspi_extended_cfg_t *) p_cfg->p_extend;

#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(
        (g_xspi_qspi_channels_open_flags & (1U << ((p_cfg_extend->unit << 1U) + p_cfg_extend->chip_select))) == 0,
        FSP_ERR_ALREADY_OPEN);
#endif

    /* Enable clock to the QSPI block */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_XSPI, p_cfg_extend->unit);
    if (0U == p_cfg_extend->unit)
    {
        R_BSP_ModuleResetDisable(BSP_MODULE_RESET_XSPI0);
    }
    else
    {
        R_BSP_ModuleResetDisable(BSP_MODULE_RESET_XSPI1);
    }

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);

#if BSP_FEATURE_BSP_SLAVE_STOP_SUPPORTED

    /* Release from slave stop. */
    if (0U == p_cfg_extend->unit)
    {
        R_BSP_SlaveStopRelease(BSP_BUS_SLAVE_XSPI0);
    }
    else
    {
        R_BSP_SlaveStopRelease(BSP_BUS_SLAVE_XSPI1);
    }
#endif

#if XSPI_QSPI_CFG_OTFD_SUPPORT_ENABLE
    if (NULL != p_cfg_extend->p_otfd_cfg)
    {
        /* OTFD enable. */
        R_XSPI_MISC2->OTFD_ENABLE |=
            (uint32_t) (R_XSPI_MISC2_OTFD_ENABLE_OTFD0E_Msk <<
                        (R_XSPI_MISC2_OTFD_ENABLE_OTFD1E_Pos * p_cfg_extend->unit));
    }
    else
    {
        /* OTFD disable. */
        R_XSPI_MISC2->OTFD_ENABLE &=
            (uint32_t) ~(R_XSPI_MISC2_OTFD_ENABLE_OTFD0E_Msk <<
                         (R_XSPI_MISC2_OTFD_ENABLE_OTFD1E_Pos * p_cfg_extend->unit));
    }
#endif

#if BSP_FEATURE_XSPI_OTFD_SUPPORTED

    /* Bus release request */
    R_XSPI_MISC2->MSTP_CTRL_XSPI &=
        ~(XSPI_QSPI_PRV_MSTP_CTRL_BUS_STOP_MASK << (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit));
    FSP_HARDWARE_REGISTER_WAIT(((R_XSPI_MISC2->MSTP_CTRL_XSPI >>
                                 (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit)) &
                                XSPI_QSPI_PRV_MSTP_CTRL_BUS_STOP_ACK_MASK),
                               0U);

    /* Module release request */
    R_XSPI_MISC2->MSTP_CTRL_XSPI &=
        ~(XSPI_QSPI_PRV_MSTP_CTRL_MODULE_STOP_MASK << (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit));
    FSP_HARDWARE_REGISTER_WAIT(((R_XSPI_MISC2->MSTP_CTRL_XSPI >>
                                 (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit)) &
                                XSPI_QSPI_PRV_MSTP_CTRL_MODULE_STOP_ACK_MASK),
                               0U);
#endif
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);

    uintptr_t base_address = (uintptr_t) R_XSPI0 + (p_cfg_extend->unit * ((uintptr_t) R_XSPI1 - (uintptr_t) R_XSPI0));
    p_instance_ctrl->p_reg = (R_XSPI0_Type *) base_address;

    /* Initialize control block. */
    p_instance_ctrl->p_cfg = p_cfg;

#if XSPI_QSPI_CFG_OTFD_SUPPORT_ENABLE
    if (NULL != p_cfg_extend->p_otfd_cfg)
    {
        uintptr_t base_otfd_address = (uintptr_t) R_OTFD0 +
                                      (p_cfg_extend->unit * ((uintptr_t) R_OTFD1 - (uintptr_t) R_OTFD0));
        p_instance_ctrl->p_otfd_reg = (R_OTFD0_Type *) base_otfd_address;

        fsp_err_t otfd_ret = r_xspi_qspi_otfd_setup(p_instance_ctrl);
        if (FSP_SUCCESS != otfd_ret)
        {
            R_RSIP_Close(&g_xspi_qspi_rsip_ctrl);

 #if BSP_FEATURE_XSPI_OTFD_SUPPORTED
            R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);

            /* Module stop request */
            R_XSPI_MISC2->MSTP_CTRL_XSPI |= XSPI_QSPI_PRV_MSTP_CTRL_MODULE_STOP_MASK <<
                                            (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit);
            FSP_HARDWARE_REGISTER_WAIT(((R_XSPI_MISC2->MSTP_CTRL_XSPI >>
                                         (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit)) &
                                        XSPI_QSPI_PRV_MSTP_CTRL_MODULE_STOP_ACK_MASK),
                                       XSPI_QSPI_PRV_MSTP_CTRL_MODULE_STOP_ACK_MASK);

            /* Bus stop request */
            R_XSPI_MISC2->MSTP_CTRL_XSPI |= XSPI_QSPI_PRV_MSTP_CTRL_BUS_STOP_MASK <<
                                            (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit);
            FSP_HARDWARE_REGISTER_WAIT(((R_XSPI_MISC2->MSTP_CTRL_XSPI >>
                                         (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit)) &
                                        XSPI_QSPI_PRV_MSTP_CTRL_BUS_STOP_ACK_MASK),
                                       XSPI_QSPI_PRV_MSTP_CTRL_BUS_STOP_ACK_MASK);
            R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);
 #endif

            /* If the OTFD initialization fails, stop the module. */
            R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
            R_BSP_MODULE_STOP(FSP_IP_XSPI, p_cfg_extend->unit);
            R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

            return otfd_ret;
        }
    }
#endif

#if XSPI_QSPI_CFG_DMAC_SUPPORT_ENABLE
    transfer_instance_t const * p_transfer = p_cfg_extend->p_lower_lvl_transfer;
 #if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_transfer);
 #endif

    /* Initialize transfer instance */
    p_transfer->p_api->open(p_transfer->p_ctrl, p_transfer->p_cfg);
#endif

    /* xSPI configuration (see RZ microprocessor User's Manual section "Flow of Configuration"). */
    p_instance_ctrl->p_reg->LIOCFGCS[p_cfg_extend->chip_select] = (p_cfg->spi_protocol) <<
                                                                  XSPI_QSPI_PRV_LIOCFGCS_PRTMD_OFFSET;
    p_instance_ctrl->spi_protocol = p_cfg->spi_protocol;

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);

    /* Set xSPI IO voltage */
#if BSP_FEATURE_XSPI_VOLTAGE_SETTING_SUPPORTED
    if (0 == p_cfg_extend->unit)
    {
        R_XSPI0_MISC->IOVOLCTL = p_cfg_extend->io_voltage;
    }
    else
    {
        R_XSPI1_MISC->IOVOLCTL = p_cfg_extend->io_voltage;
    }
#endif

    /* Set xSPI CSn address space. */
#if XSPI_QSPI_CFG_CUSTOM_ADDR_SPACE_ENABLE
    uint32_t mirror_address_delta;
 #if 0 == BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS
    mirror_address_delta = 0;
 #else
    mirror_address_delta = BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS;
 #endif
    R_XSPI0_MISC->CS0ENDAD = p_cfg_extend->p_address_space->unit0_cs0_end_address - mirror_address_delta;
    R_XSPI0_MISC->CS1STRAD = p_cfg_extend->p_address_space->unit0_cs1_start_address - mirror_address_delta;
    R_XSPI0_MISC->CS1ENDAD = p_cfg_extend->p_address_space->unit0_cs1_end_address - mirror_address_delta;
    R_XSPI1_MISC->CS0ENDAD = p_cfg_extend->p_address_space->unit1_cs0_end_address - mirror_address_delta;
    R_XSPI1_MISC->CS1STRAD = p_cfg_extend->p_address_space->unit1_cs1_start_address - mirror_address_delta;
    R_XSPI1_MISC->CS1ENDAD = p_cfg_extend->p_address_space->unit1_cs1_end_address - mirror_address_delta;
#else
 #if 1 == BSP_FEATURE_XSPI_CS_ADDRESS_SPACE_SETTING_TYPE

    /* Set xSPI CSn slave memory size. */
    if (XSPI_QSPI_CHIP_SELECT_0 == p_cfg_extend->chip_select)
    {
        p_instance_ctrl->p_reg->CSSCTL_b.CS0SIZE = p_cfg_extend->memory_size;
    }
    else
    {
        p_instance_ctrl->p_reg->CSSCTL_b.CS1SIZE = p_cfg_extend->memory_size;
    }

 #elif 2 == BSP_FEATURE_XSPI_CS_ADDRESS_SPACE_SETTING_TYPE
    uint32_t mirror_address_delta;
  #if 0 == BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS
    mirror_address_delta = 0U;
  #else
    mirror_address_delta = BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS;
  #endif

    if (XSPI_QSPI_CHIP_SELECT_0 == p_cfg_extend->chip_select)
    {
        if (0 == p_cfg_extend->unit)
        {
            R_XSPI0_MISC->CS0ENDAD = BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - mirror_address_delta +
                                     (uint32_t) (p_cfg_extend->memory_size << XSPI_QSPI_PRV_MEMORY_SIZE_SHIFT) +
                                     XSPI_QSPI_PRV_1MB_MEMORY_SPACE;
        }
        else
        {
            R_XSPI1_MISC->CS0ENDAD = BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS - mirror_address_delta +
                                     (uint32_t) (p_cfg_extend->memory_size << XSPI_QSPI_PRV_MEMORY_SIZE_SHIFT) +
                                     XSPI_QSPI_PRV_1MB_MEMORY_SPACE;
        }
    }
    else
    {
        if (0 == p_cfg_extend->unit)
        {
            R_XSPI0_MISC->CS1STRAD = BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS +
                                     BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2U - mirror_address_delta;

            R_XSPI0_MISC->CS1ENDAD = BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS +
                                     BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2U - mirror_address_delta +
                                     (uint32_t) (p_cfg_extend->memory_size << XSPI_QSPI_PRV_MEMORY_SIZE_SHIFT) +
                                     XSPI_QSPI_PRV_1MB_MEMORY_SPACE;
        }
        else
        {
            R_XSPI1_MISC->CS1STRAD = BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS +
                                     BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2U - mirror_address_delta;

            R_XSPI1_MISC->CS1ENDAD = BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS +
                                     BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2U - mirror_address_delta +
                                     (uint32_t) (p_cfg_extend->memory_size << XSPI_QSPI_PRV_MEMORY_SIZE_SHIFT) +
                                     XSPI_QSPI_PRV_1MB_MEMORY_SPACE;
        }
    }
 #endif
#endif
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);

    p_instance_ctrl->p_reg->LIOCFGCS[p_cfg_extend->chip_select] =
        ((p_cfg->spi_protocol & XSPI_QSPI_PRV_LIOCFGCS_PRTMD_VALUE_MASK) << XSPI_QSPI_PRV_LIOCFGCS_PRTMD_OFFSET) |
        ((p_cfg_extend->p_timing_settings->command_to_command_interval &
          XSPI_QSPI_PRV_LIOCFGCS_CSMIN_VALUE_MASK) << XSPI_QSPI_PRV_LIOCFGCS_CSMIN_OFFSET) |
        ((p_cfg_extend->p_timing_settings->cs_pulldown_lead & XSPI_QSPI_PRV_LIOCFGCS_CSASTEX_VALUE_MASK) <<
            XSPI_QSPI_PRV_LIOCFGCS_CSASTEX_OFFSET) |
        ((p_cfg_extend->p_timing_settings->cs_pullup_lag & XSPI_QSPI_PRV_LIOCFGCS_CSENGEX_VALUE_MASK) <<
            XSPI_QSPI_PRV_LIOCFGCS_CSENGEX_OFFSET);

    /* Specifies the read/write commands and Read dummy clocks for Device
     * (see RZ microprocessor User's Manual section "Flow of Memory-mapping"). */
    p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG0 =
        (0U << XSPI_QSPI_PRV_CMCFG0_FFMT_OFFSET) |
        ((p_cfg->address_bytes & XSPI_QSPI_PRV_CMCFG0_ADDSIZE_VALUE_MASK) << XSPI_QSPI_PRV_CMCFG0_ADDSIZE_OFFSET);

    p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG1 =
        ((p_cfg->read_command & XSPI_QSPI_PRV_CMCFG1_RDCMD_VALUE_MASK) << XSPI_QSPI_PRV_CMCFG1_RDCMD_UPPER_OFFSET) |
        ((p_cfg->dummy_clocks & XSPI_QSPI_PRV_CMCFG1_RDLATE_VALUE_MASK) << XSPI_QSPI_PRV_CMCFG1_RDLATE_OFFSET);

    p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG2 =
        ((p_cfg->page_program_command & XSPI_QSPI_PRV_CMCFG1_WRCMD_VALUE_MASK) <<
            XSPI_QSPI_PRV_CMCFG2_WRCMD_UPPER_OFFSET) |
        (0U << XSPI_QSPI_PRV_CMCFG2_WRLATE_OFFSET);

    p_instance_ctrl->p_reg->BMCTL0 = XSPI_QSPI_PRV_BMCTL_DEFAULT_VALUE;

    /* Return response after issuing write transaction to xSPI bus, Enable prefetch function. */
    p_instance_ctrl->p_reg->BMCFG = (0 << XSPI_QSPI_PRV_BMCFG_WRMD_OFFSET) |
                                    (1 << XSPI_QSPI_PRV_BMCFG_MWRCOMB_OFFSET) |
                                    (0x0F << XSPI_QSPI_PRV_BMCFG_MWRSIZE_OFFSET) |
                                    ((p_cfg_extend->prefetch_en & XSPI_QSPI_PRV_BMCFG_PREEN_VALUE_MASK) <<
                                     XSPI_QSPI_PRV_BMCFG_PREEN_OFFSET);

    /* Set use Channel. */
    p_instance_ctrl->p_reg->CDCTL0_b.CSSEL = p_cfg_extend->chip_select;

    /* The memory size is read from the device if needed. */
    p_instance_ctrl->total_size_bytes = 0U;

    p_instance_ctrl->open            = XSPI_QSPI_PRV_OPEN;
    g_xspi_qspi_channels_open_flags |= (1U << ((p_cfg_extend->unit << 1U) + p_cfg_extend->chip_select));

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Writes raw data directly to the QSPI.
 *
 * Implements @ref spi_flash_api_t::directWrite.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_DirectWrite (spi_flash_ctrl_t    * p_ctrl,
                                   uint8_t const * const p_src,
                                   uint32_t const        bytes,
                                   bool const            read_after_write)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_src);
    FSP_PARAMETER_NOT_USED(bytes);
    FSP_PARAMETER_NOT_USED(read_after_write);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Reads raw data directly from the QSPI.
 *
 * Implements @ref spi_flash_api_t::directRead.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_DirectRead (spi_flash_ctrl_t * p_ctrl, uint8_t * const p_dest, uint32_t const bytes)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_dest);
    FSP_PARAMETER_NOT_USED(bytes);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Read/Write raw data directly with the SerialFlash.
 *
 * Implements @ref spi_flash_api_t::directTransfer.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function must be called after R_XSPI_QSPI_DirectWrite with read_after_write set
 *                                     to true.
 * @retval FSP_ERR_DEVICE_BUSY         The device is busy.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_DirectTransfer (spi_flash_ctrl_t                  * p_ctrl,
                                      spi_flash_direct_transfer_t * const p_transfer,
                                      spi_flash_direct_transfer_dir_t     direction)
{
    xspi_qspi_instance_ctrl_t * p_instance_ctrl = (xspi_qspi_instance_ctrl_t *) p_ctrl;
#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_xspi_qspi_param_checking_dcom(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_transfer);
    FSP_ASSERT(0 != p_transfer->command_length);
    FSP_ERROR_RETURN(XSPI_QSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    r_xspi_qspi_direct_transfer(p_instance_ctrl, p_transfer, direction);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enters XIP (execute in place) mode.
 * @note If the xSPI address space is cache-enabled, cache should be invalidated before executing XipEnter. Otherwise, it is not guaranteed that the slave device will be in XiP mode immediately after XipEnter is executed.
 *
 * Implements @ref spi_flash_api_t::xipEnter.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_XipEnter (spi_flash_ctrl_t * p_ctrl)
{
    xspi_qspi_instance_ctrl_t * p_instance_ctrl = (xspi_qspi_instance_ctrl_t *) p_ctrl;
#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(XSPI_QSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    fsp_err_t err;

    err = r_xspi_qspi_xip(p_instance_ctrl, p_instance_ctrl->p_cfg->xip_enter_command, true);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Exits XIP (execute in place) mode.
 * @note If the xSPI address space is cache-enabled, cache should be invalidated before executing XipExit. Otherwise, it is not guaranteed that the slave device will exit XiP mode immediately after XipEnter is executed.
 *
 * Implements @ref spi_flash_api_t::xipExit.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_XipExit (spi_flash_ctrl_t * p_ctrl)
{
    xspi_qspi_instance_ctrl_t * p_instance_ctrl = (xspi_qspi_instance_ctrl_t *) p_ctrl;
#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(XSPI_QSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    fsp_err_t err;

    err = r_xspi_qspi_xip(p_instance_ctrl, p_instance_ctrl->p_cfg->xip_exit_command, false);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Program a page of data to the flash.
 *
 * Implements @ref spi_flash_api_t::write.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           p_instance_ctrl, p_dest or p_src is NULL, or byte_count crosses a page boundary.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 * @retval FSP_ERR_DEVICE_BUSY         The device is busy.
 *
 * @note In this API, data can be written up to 64 bytes at a time if DMAC support is enabled.
 * Otherwise, the number of bytes that can be written at one time depends on the MCU :
 * 64bytes for RZ/T2M and RZ/T2L, 8bytes for RZ/T2ME and RZ/T2H.
 * @note This API performs page program operations to the device. Writing across pages is not supported.
 * Please set the write address and write size according to the page size of your device.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_Write (spi_flash_ctrl_t    * p_ctrl,
                             uint8_t const * const p_src,
                             uint8_t * const       p_dest,
                             uint32_t              byte_count)
{
    xspi_qspi_instance_ctrl_t * p_instance_ctrl = (xspi_qspi_instance_ctrl_t *) p_ctrl;

#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_xspi_qspi_program_param_check(p_instance_ctrl, p_src, p_dest, byte_count);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif
    FSP_ERROR_RETURN(false == r_xspi_qspi_status_sub(p_instance_ctrl), FSP_ERR_DEVICE_BUSY);

    r_xspi_qspi_write_enable(p_instance_ctrl);

#if XSPI_QSPI_CFG_DMAC_SUPPORT_ENABLE
    xspi_qspi_extended_cfg_t * p_cfg_extend = (xspi_qspi_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Setup and start DMAC transfer. */
    transfer_instance_t const * p_transfer = p_cfg_extend->p_lower_lvl_transfer;

    p_transfer->p_cfg->p_info->src_size       = TRANSFER_SIZE_1_BYTE;
    p_transfer->p_cfg->p_info->dest_size      = TRANSFER_SIZE_1_BYTE;
    p_transfer->p_cfg->p_info->src_addr_mode  = TRANSFER_ADDR_MODE_INCREMENTED;
    p_transfer->p_cfg->p_info->dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED;
    p_transfer->p_cfg->p_info->p_src          = p_src;
    p_transfer->p_cfg->p_info->p_dest         = p_dest;
    p_transfer->p_cfg->p_info->length         = byte_count;
    fsp_err_t dmac_err = p_transfer->p_api->reconfigure(p_transfer->p_ctrl, p_transfer->p_cfg->p_info);
    FSP_ERROR_RETURN(FSP_SUCCESS == dmac_err, dmac_err);

    /* Start DMA */
    dmac_err = p_transfer->p_api->softwareStart(p_transfer->p_ctrl, TRANSFER_START_MODE_SINGLE);
    FSP_ERROR_RETURN(FSP_SUCCESS == dmac_err, dmac_err);

    /* Wait for DMAC to complete to maintain deterministic processing and backward compatability */
    volatile transfer_properties_t transfer_properties = {0U};
    dmac_err = p_transfer->p_api->infoGet(p_transfer->p_ctrl, (transfer_properties_t *) &transfer_properties);
    FSP_ERROR_RETURN(FSP_SUCCESS == dmac_err, dmac_err);
    while (FSP_SUCCESS == dmac_err && transfer_properties.transfer_length_remaining > 0)
    {
        dmac_err = p_transfer->p_api->infoGet(p_transfer->p_ctrl, (transfer_properties_t *) &transfer_properties);
        FSP_ERROR_RETURN(FSP_SUCCESS == dmac_err, dmac_err);
    }

    /* Request to push the pending data */
    if (XSPI_QSPI_PRV_MAX_COMBINE_SIZE > byte_count)
    {
        /* Push the pending data. */
        p_instance_ctrl->p_reg->BMCTL1_b.MWRPUSH = 1;
    }

#elif BSP_FEATURE_XSPI_HAS_AXI_BRIDGE
    xspi_qspi_extended_cfg_t * p_cfg_extend = (xspi_qspi_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
    uint32_t chip_address;
    uint32_t chip_select = p_cfg_extend->chip_select;
    uint32_t unit        = p_cfg_extend->unit;
    uint32_t mirror_address_delta;

 #ifdef BSP_CFG_CORE_CA55
    uintptr_t dest_va = (uintptr_t) p_dest;
    uintptr_t dest_pa = 0U;

    fsp_err_t mmu_err;
    mmu_err = R_BSP_MmuVatoPa(dest_va, &dest_pa);
    FSP_ERROR_RETURN(FSP_SUCCESS == mmu_err, mmu_err);
 #else
    uintptr_t dest_pa = (uintptr_t) p_dest;
 #endif

    /* Get device start address. */
 #if 0 == BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS
    mirror_address_delta = 0U;
 #else
    mirror_address_delta = ((uintptr_t) p_dest < BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS) ?
                           0U :
                           BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS;
 #endif

    chip_address = (0 == chip_select) ?
                   (0 == unit) ?
                   (uint32_t) dest_pa - (BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - mirror_address_delta) : // unit0 cs0
                   (uint32_t) dest_pa - (BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS - mirror_address_delta) : // unit1 cs0
                   (0 == unit)
 #if XSPI_QSPI_CFG_CUSTOM_ADDR_SPACE_ENABLE
                   ? (uint32_t) dest_pa -
                   (p_cfg_extend->p_address_space->unit0_cs1_start_address - mirror_address_delta) :       // unit0 cs1
                   (uint32_t) dest_pa -
                   (p_cfg_extend->p_address_space->unit1_cs1_start_address - mirror_address_delta);        // unit1 cs1
 #else
                   ? (uint32_t) dest_pa -
                   (BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS + BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2 -
                    mirror_address_delta) :                                                                // unit0 cs1
                   (uint32_t) dest_pa -
                   (BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS + BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2 -
                    mirror_address_delta);                                                                 // unit1 cs1
 #endif

    spi_flash_direct_transfer_t write_transfer;
    write_transfer.data_u64       = *(uint64_t *) p_src;
    write_transfer.data_length    = (uint8_t) byte_count;
    write_transfer.address        = chip_address;
    write_transfer.address_length = (p_instance_ctrl->p_cfg->address_bytes == SPI_FLASH_ADDRESS_BYTES_4) ? 4U : 3U;
    write_transfer.dummy_cycles   = 0;

    write_transfer.command        = p_instance_ctrl->p_cfg->page_program_command;
    write_transfer.command_length = 1U;

    r_xspi_qspi_direct_transfer(p_instance_ctrl, &write_transfer, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);

    /* If prefetch is enabled, make sure the banks aren't being used and flush the prefetch caches after an erase. */
    if (p_cfg_extend->prefetch_en == XSPI_QSPI_PREFETCH_FUNCTION_ENABLE)
    {
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->COMSTT_b.MEMACC, 0);
        p_instance_ctrl->p_reg->BMCTL1_b.PBUFCLR = 1;
    }

#else
    uint32_t i = 0;

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* Word access */
    if (0 == byte_count % XSPI_QSPI_PRV_WORD_ACCESS_SIZE)
    {
        uint32_t * p_word_aligned_dest = (uint32_t *) p_dest;
        uint32_t * p_word_aligned_src  = (uint32_t *) p_src;
        for (i = 0; i < byte_count / XSPI_QSPI_PRV_WORD_ACCESS_SIZE; i++)
        {
            *p_word_aligned_dest = *p_word_aligned_src;
            p_word_aligned_dest++;
            p_word_aligned_src++;
        }
    }
    /* Half Word access */
    else if (0 == byte_count % XSPI_QSPI_PRV_HALF_WORD_ACCESS_SIZE)
    {
        uint16_t * p_half_word_aligned_dest = (uint16_t *) p_dest;
        uint16_t * p_half_word_aligned_src  = (uint16_t *) p_src;
        for (i = 0; i < byte_count / XSPI_QSPI_PRV_HALF_WORD_ACCESS_SIZE; i++)
        {
            *p_half_word_aligned_dest = *p_half_word_aligned_src;
            p_half_word_aligned_dest++;
            p_half_word_aligned_src++;
        }
    }
    /* Byte access */
    else
    {
        for (i = 0; i < byte_count; i++)
        {
            p_dest[i] = p_src[i];
        }
    }

    /* Protect the order between access to the xSPI external memory space and the xSPI peripheral space. */
    __DSB();

    /* Request to push the pending data */
    if (XSPI_QSPI_PRV_MAX_COMBINE_SIZE > byte_count)
    {
        /* Do dummy read for wait.
         * To ensure that all write data is stored in the xSPI internal write buffer before issuing a push request,
         * it is necessary to wait a few cycles. */
        volatile uint32_t dummy;
        for (uint32_t wait_cycle = 0; wait_cycle < XSPI_QSPI_BUFFER_WRITE_WAIT_CYCLE; wait_cycle++)
        {
            dummy = p_instance_ctrl->p_reg->COMCFG;
            FSP_PARAMETER_NOT_USED(dummy);
        }

        /* Push the pending data. */
        p_instance_ctrl->p_reg->BMCTL1_b.MWRPUSH = 1;
    }

    /* Wait until memory access starts in write API. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->COMSTT_b.MEMACC, 1);

    FSP_CRITICAL_SECTION_EXIT;
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Erase a block or sector of flash.  The byte_count must exactly match one of the erase sizes defined in spi_flash_cfg_t.
 * For chip erase, byte_count must be SPI_FLASH_ERASE_SIZE_CHIP_ERASE.
 *
 * Implements @ref spi_flash_api_t::erase.
 *
 * @retval FSP_SUCCESS                 The command to erase the flash was executed successfully.
 * @retval FSP_ERR_ASSERTION           p_instance_ctrl or p_device_address is NULL, or byte_count doesn't match an erase
 *                                     size defined in spi_flash_cfg_t, or device is in XIP mode.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 * @retval FSP_ERR_DEVICE_BUSY         The device is busy.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_Erase (spi_flash_ctrl_t * p_ctrl, uint8_t * const p_device_address, uint32_t byte_count)
{
    xspi_qspi_instance_ctrl_t * p_instance_ctrl = (xspi_qspi_instance_ctrl_t *) p_ctrl;

#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_xspi_qspi_param_checking_dcom(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(NULL != p_device_address);
#endif

    xspi_qspi_extended_cfg_t * p_cfg_extend =
        (xspi_qspi_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t unit        = p_cfg_extend->unit;
    uint8_t chip_select = p_cfg_extend->chip_select;

    uint16_t  erase_command = 0;
    uintptr_t chip_address  = 0;
    bool      send_address  = true;

    if (SPI_FLASH_ERASE_SIZE_CHIP_ERASE != byte_count)
    {
        uint32_t mirror_address_delta;

#ifdef BSP_CFG_CORE_CA55
        uintptr_t device_address_va = (uintptr_t) p_device_address;
        uintptr_t device_address_pa = 0U;

        fsp_err_t mmu_err;
        mmu_err = R_BSP_MmuVatoPa(device_address_va, &device_address_pa);
        FSP_ERROR_RETURN(FSP_SUCCESS == mmu_err, mmu_err);
#else
        uintptr_t device_address_pa = (uintptr_t) p_device_address;
#endif

        /* Get device start address. */
#if 0 == BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS
        mirror_address_delta = 0U;
#else
        mirror_address_delta = (device_address_pa < BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS) ?
                               0U :
                               BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS;
#endif

        chip_address = (0 == chip_select) ?
                       (0 == unit) ?
                       device_address_pa - (BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - mirror_address_delta) : // unit0 cs0
                       device_address_pa - (BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS - mirror_address_delta) : // unit1 cs0
                       (0 == unit)
#if XSPI_QSPI_CFG_CUSTOM_ADDR_SPACE_ENABLE
                       ? device_address_pa -
                       (p_cfg_extend->p_address_space->unit0_cs1_start_address - mirror_address_delta) :      // unit0 cs1
                       device_address_pa -
                       (p_cfg_extend->p_address_space->unit1_cs1_start_address - mirror_address_delta);       // unit1 cs1
#else
                       ? device_address_pa -
                       (BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS + BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2 -
                        mirror_address_delta) :                                                               // unit0 cs1
                       device_address_pa -
                       (BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS + BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2 -
                        mirror_address_delta);                                                                // unit1 cs1
#endif
    }

    for (uint32_t index = 0; index < p_instance_ctrl->p_cfg->erase_command_list_length; index++)
    {
        /* If requested byte_count is supported by underlying flash, store the command. */
        if (byte_count == p_instance_ctrl->p_cfg->p_erase_command_list[index].size)
        {
            if (SPI_FLASH_ERASE_SIZE_CHIP_ERASE == byte_count)
            {
                /* Don't send address for chip erase. */
                send_address = false;
            }

            erase_command = p_instance_ctrl->p_cfg->p_erase_command_list[index].command;
            break;
        }
    }

#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(0U != erase_command);
#endif

    r_xspi_qspi_write_enable(p_instance_ctrl);

    spi_flash_direct_transfer_t direct_command = {0};
    direct_command.command        = erase_command;
    direct_command.address        = (uint32_t) chip_address;
    direct_command.address_length = (true == send_address) ?
                                    (((p_instance_ctrl->p_cfg->address_bytes) + 1U)) &
                                    XSPI_QSPI_PRV_CDTBUF_ADDSIZE_VALUE_MASK : 0U;
    direct_command.command_length = 1U;

    r_xspi_qspi_direct_transfer(p_instance_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);

    /* If prefetch is enabled, make sure the banks aren't being used and flush the prefetch caches after an erase. */
    if (p_cfg_extend->prefetch_en == XSPI_QSPI_PREFETCH_FUNCTION_ENABLE)
    {
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->COMSTT_b.MEMACC, 0);
        p_instance_ctrl->p_reg->BMCTL1_b.PBUFCLR = 1;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Gets the write or erase status of the flash.
 *
 * Implements @ref spi_flash_api_t::statusGet.
 *
 * @retval FSP_SUCCESS                 The write status is in p_status.
 * @retval FSP_ERR_ASSERTION           p_instance_ctrl or p_status is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_StatusGet (spi_flash_ctrl_t * p_ctrl, spi_flash_status_t * const p_status)
{
    xspi_qspi_instance_ctrl_t * p_instance_ctrl = (xspi_qspi_instance_ctrl_t *) p_ctrl;

#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(XSPI_QSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(0U == p_instance_ctrl->p_reg->CMCTL_b.XIPEN, FSP_ERR_INVALID_MODE);
#endif

    uint32_t comstt  = p_instance_ctrl->p_reg->COMSTT;
    bool     memacc  = (bool) ((comstt >> XSPI_QSPI_PRV_COMSTT_MEMACC_OFFSET) & XSPI_QSPI_PRV_COMSTT_MEMACC_VALUE_MASK);
    bool     wrbufne =
        (bool) ((comstt >> XSPI_QSPI_PRV_COMSTT_WRBUFNE_OFFSET) & XSPI_QSPI_PRV_COMSTT_WRBUFNE_VALUE_MASK);

    if ((true == memacc) || (true == wrbufne))
    {
        /* If the xSPI is accessing memory or data is in the write buffer,
         * it is judged a "write in progress" without access to QSPI. */
        p_status->write_in_progress = (bool) (wrbufne | memacc);
    }
    else
    {
        /* Read device status. */
        p_status->write_in_progress = r_xspi_qspi_status_sub(p_instance_ctrl);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Selects the bank to access.
 *
 * Implements @ref spi_flash_api_t::bankSet.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_BankSet (spi_flash_ctrl_t * p_ctrl, uint32_t bank)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(bank);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Sets the SPI protocol.
 *
 * Implements @ref spi_flash_api_t::spiProtocolSet.
 *
 * @retval FSP_SUCCESS                SPI protocol updated on MCU peripheral.
 * @retval FSP_ERR_ASSERTION          A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN           Driver is not opened.
 * @retval FSP_ERR_INVALID_ARGUMENT   Invalid SPI protocol requested.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_SpiProtocolSet (spi_flash_ctrl_t * p_ctrl, spi_flash_protocol_t spi_protocol)
{
    xspi_qspi_instance_ctrl_t * p_instance_ctrl = (xspi_qspi_instance_ctrl_t *) p_ctrl;

#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(XSPI_QSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Not allow the following arguremnts with this IP. */
    FSP_ERROR_RETURN(SPI_FLASH_PROTOCOL_QPI != spi_protocol, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(SPI_FLASH_PROTOCOL_SOPI != spi_protocol, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(SPI_FLASH_PROTOCOL_DOPI != spi_protocol, FSP_ERR_INVALID_ARGUMENT);

    /* Not allow the following arguremnts with QSPI HAL Driver. */
    FSP_ERROR_RETURN(SPI_FLASH_PROTOCOL_8D_8D_8D != spi_protocol, FSP_ERR_INVALID_ARGUMENT);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    spi_flash_cfg_t          * p_cfg        = (spi_flash_cfg_t *) p_instance_ctrl->p_cfg;
    xspi_qspi_extended_cfg_t * p_cfg_extend = (xspi_qspi_extended_cfg_t *) p_cfg->p_extend;

    p_instance_ctrl->spi_protocol = spi_protocol;

    /* Update the SPI protocol. */
    p_instance_ctrl->p_reg->LIOCFGCS_b[p_cfg_extend->chip_select].PRTMD = spi_protocol &
                                                                          XSPI_QSPI_PRV_LIOCFGCS_PRTMD_MASK;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Auto-calibrate the OctaRAM device using the preamble pattern. Unsupported by XSPI_QSPI.
 * Implements @ref spi_flash_api_t::autoCalibrate.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by XSPI_QSPI
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_AutoCalibrate (spi_flash_ctrl_t * p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Close the QSPI driver module.
 *
 * Implements @ref spi_flash_api_t::close.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       p_instance_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Driver is not opened.
 *
 * @note If another chip select of the same unit is used by other drivers,
 * the other chip select operation will also stop when this function is executed.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_QSPI_Close (spi_flash_ctrl_t * p_ctrl)
{
    xspi_qspi_instance_ctrl_t * p_instance_ctrl = (xspi_qspi_instance_ctrl_t *) p_ctrl;
#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(XSPI_QSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    spi_flash_cfg_t          * p_cfg        = (spi_flash_cfg_t *) p_instance_ctrl->p_cfg;
    xspi_qspi_extended_cfg_t * p_cfg_extend = (xspi_qspi_extended_cfg_t *) p_cfg->p_extend;

    p_instance_ctrl->open            = 0U;
    g_xspi_qspi_channels_open_flags &= ~(1U << ((p_cfg_extend->unit << 1U) + p_cfg_extend->chip_select));

    if ((g_xspi_qspi_channels_open_flags & (XSPI_QSPI_UNIT_FLAG_MASK << (p_cfg_extend->unit << 1U))) == 0)
    {
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);

#if BSP_FEATURE_XSPI_OTFD_SUPPORTED

        /* Module stop request */
        R_XSPI_MISC2->MSTP_CTRL_XSPI |= XSPI_QSPI_PRV_MSTP_CTRL_MODULE_STOP_MASK <<
                                        (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit);
        FSP_HARDWARE_REGISTER_WAIT(((R_XSPI_MISC2->MSTP_CTRL_XSPI >>
                                     (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit)) &
                                    XSPI_QSPI_PRV_MSTP_CTRL_MODULE_STOP_ACK_MASK),
                                   XSPI_QSPI_PRV_MSTP_CTRL_MODULE_STOP_ACK_MASK);

        /* Bus stop request */
        R_XSPI_MISC2->MSTP_CTRL_XSPI |= XSPI_QSPI_PRV_MSTP_CTRL_BUS_STOP_MASK <<
                                        (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit);
        FSP_HARDWARE_REGISTER_WAIT(((R_XSPI_MISC2->MSTP_CTRL_XSPI >>
                                     (XSPI_QSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit)) &
                                    XSPI_QSPI_PRV_MSTP_CTRL_BUS_STOP_ACK_MASK),
                                   XSPI_QSPI_PRV_MSTP_CTRL_BUS_STOP_ACK_MASK);
#endif

#if BSP_FEATURE_BSP_SLAVE_STOP_SUPPORTED

        /* Slave stop request */
        if (0U == p_cfg_extend->unit)
        {
            R_BSP_SlaveStop(BSP_BUS_SLAVE_XSPI0);
        }
        else
        {
            R_BSP_SlaveStop(BSP_BUS_SLAVE_XSPI1);
        }
#endif
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);

        /* Disable clock to the QSPI block */
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);

        /* Enable reset */
        if (0U == p_cfg_extend->unit)
        {
            R_BSP_ModuleResetEnable(BSP_MODULE_RESET_XSPI0);
        }
        else
        {
            R_BSP_ModuleResetEnable(BSP_MODULE_RESET_XSPI1);
        }

        R_BSP_MODULE_STOP(FSP_IP_XSPI, p_cfg_extend->unit);
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup XSPI_QSPI)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Send Write enable command to the SerialFlash
 *
 * @param[in]   p_instance_ctrl    Pointer to QSPI specific control structure
 **********************************************************************************************************************/
static void r_xspi_qspi_write_enable (xspi_qspi_instance_ctrl_t * p_instance_ctrl)
{
    spi_flash_direct_transfer_t direct_command = {0};
    spi_flash_cfg_t const     * p_cfg          = p_instance_ctrl->p_cfg;

    direct_command.command        = p_cfg->write_enable_command;
    direct_command.command_length = 1U;

    r_xspi_qspi_direct_transfer(p_instance_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);
}

/*******************************************************************************************************************//**
 * Enters or exits XIP (execute in place) mode.
 *
 * @param[in]  p_instance_ctrl         Pointer to a driver handle
 * @param[in]  code                    Code to place in M7-M0
 * @param[in]  enter_mode              True to enter, false to exit
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
static fsp_err_t r_xspi_qspi_xip (xspi_qspi_instance_ctrl_t * p_instance_ctrl, uint8_t code, bool enter_mode)
{
#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE

    /* FSP_ASSERT(NULL != p_instance_ctrl) is optimized out when it shouldn't be.  It appears to be affected by GCC bug
     * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90949. */
    xspi_qspi_instance_ctrl_t * volatile p_volatile_ctrl = p_instance_ctrl;
    FSP_ASSERT(NULL != p_volatile_ctrl);
    FSP_ERROR_RETURN(XSPI_QSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    xspi_qspi_extended_cfg_t * p_cfg_extend =
        (xspi_qspi_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t unit        = p_cfg_extend->unit;
    uint8_t chip_select = p_cfg_extend->chip_select;

    volatile uint8_t dummy = 0;
    FSP_PARAMETER_NOT_USED(dummy);

    /* XiP configuration (see RZ microprocessor User's Manual section "Flow of XiP"). */
    if (true == enter_mode)
    {
        if (XSPI_QSPI_CHIP_SELECT_0 == chip_select)
        {
            p_instance_ctrl->p_reg->BMCTL0_b.CS0ACC = XSPI_QSPI_PRV_BMCTL_CSNACC_R_ENABLE;
        }
        else
        {
            p_instance_ctrl->p_reg->BMCTL0_b.CS1ACC = XSPI_QSPI_PRV_BMCTL_CSNACC_R_ENABLE;
        }
    }

    p_instance_ctrl->p_reg->CMCTL_b.XIPENCODE = code;
    p_instance_ctrl->p_reg->CMCTL_b.XIPEXCODE = code;
    p_instance_ctrl->p_reg->CMCTL_b.XIPEN     = enter_mode;

    /* Read from QSPI to send the XIP entry request.
     * Read via a cache-invalid mirror area to ensure access to QSPI. */

    uint32_t mirror_address_delta;
#if 0 == BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS
    mirror_address_delta = 0;
#else
    mirror_address_delta = BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS;
#endif

    uintptr_t dummy_address = (0 == chip_select) ?
                              (0 == unit) ?
                              BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - mirror_address_delta :                  // unit0 cs0
                              BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS - mirror_address_delta :                  // unit1 cs0
                              (0 == unit)
#if XSPI_QSPI_CFG_CUSTOM_ADDR_SPACE_ENABLE
                              ? p_cfg_extend->p_address_space->unit0_cs1_start_address - mirror_address_delta : // unit0 cs1
                              p_cfg_extend->p_address_space->unit1_cs1_start_address - mirror_address_delta;    // unit1 cs1
#else
                              ? BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS + BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE /
                              2 - mirror_address_delta :                                                        // unit0 cs1
                              BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS + BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2 -
                              mirror_address_delta;                                                             // unit1 cs1
#endif

#ifdef BSP_CFG_CORE_CA55
    uintptr_t dummy_address_va = 0U;
    R_BSP_MmuPatoVa(dummy_address, &dummy_address_va, BSP_MMU_CONVERSION_NON_CACHE);
    if (0U == dummy_address_va)
    {
        R_BSP_MmuPatoVa(dummy_address, &dummy_address_va, BSP_MMU_CONVERSION_CACHE);
    }
    dummy_address = dummy_address_va;
#endif

    dummy = *(uint8_t *) dummy_address;

    if (false == enter_mode)
    {
        if (XSPI_QSPI_CHIP_SELECT_0 == chip_select)
        {
            p_instance_ctrl->p_reg->BMCTL0_b.CS0ACC = XSPI_QSPI_PRV_BMCTL_CSNACC_R_W_ENABLE;
        }
        else
        {
            p_instance_ctrl->p_reg->BMCTL0_b.CS1ACC = XSPI_QSPI_PRV_BMCTL_CSNACC_R_W_ENABLE;
        }
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Gets device status.
 *
 * @param[in]  p_instance_ctrl         Pointer to a driver handle
 *
 * @return True if busy, false if not.
 **********************************************************************************************************************/
static bool r_xspi_qspi_status_sub (xspi_qspi_instance_ctrl_t * p_instance_ctrl)
{
    spi_flash_cfg_t const    * p_cfg        = p_instance_ctrl->p_cfg;
    xspi_qspi_extended_cfg_t * p_cfg_extend = (xspi_qspi_extended_cfg_t *) p_cfg->p_extend;

    spi_flash_direct_transfer_t direct_command = {0};

    bool                 restore_spi_protocol = false;
    spi_flash_protocol_t setting_protocol     = (spi_flash_protocol_t) 0x00;

    direct_command.command        = p_cfg->status_command;
    direct_command.command_length = 1U;
    direct_command.data_length    = 1U;

    /* For most devices, the Read Status Register instruction is executed with the 1S-1S-1S instruction,
     * even if it assumes 1S-2S-2S or 1S-4S-4S Write instruction.
     * Therefore, the communication protocol is temporarily switched. */
    if ((SPI_FLASH_PROTOCOL_1S_4S_4S == p_instance_ctrl->spi_protocol) ||
        (SPI_FLASH_PROTOCOL_1S_2S_2S == p_instance_ctrl->spi_protocol))
    {
        setting_protocol = p_instance_ctrl->spi_protocol;
        p_instance_ctrl->p_reg->LIOCFGCS_b[p_cfg_extend->chip_select].PRTMD = SPI_FLASH_PROTOCOL_1S_1S_1S;
        p_instance_ctrl->spi_protocol = SPI_FLASH_PROTOCOL_1S_1S_1S;
        restore_spi_protocol          = true;
    }

    r_xspi_qspi_direct_transfer(p_instance_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_READ);

    /* Restore communication protocol. */
    if (true == restore_spi_protocol)
    {
        p_instance_ctrl->p_reg->LIOCFGCS_b[p_cfg_extend->chip_select].PRTMD = setting_protocol;
        p_instance_ctrl->spi_protocol = setting_protocol;
    }

    return (bool) ((direct_command.data >> p_instance_ctrl->p_cfg->write_status_bit) &
                   XSPI_QSPI_PRV_DEVICE_WRITE_STATUS_BIT_MASK);
}

/*******************************************************************************************************************//**
 * Performs direct data transfer with the SerialFlash
 *
 * @param[in]   p_instance_ctrl    Pointer to QSPI specific control structure
 * @param[in]   p_transfer             Pointer to transfer parameters
 * @param[in]   direction          Read/Write
 **********************************************************************************************************************/
static void r_xspi_qspi_direct_transfer (xspi_qspi_instance_ctrl_t         * p_instance_ctrl,
                                         spi_flash_direct_transfer_t * const p_transfer,
                                         spi_flash_direct_transfer_dir_t     direction)
{
    p_instance_ctrl->p_reg->CDCTL0_b.TRNUM = 0;

    /* Direct Read/Write settings
     * (see RZ microprocessor User's Manual section "Flow of Manual-command Procedure"). */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CDCTL0_b.TRREQ, 0);

    p_instance_ctrl->p_reg->BUF[0].CDT =
        ((p_transfer->command_length & XSPI_QSPI_PRV_CDTBUF_CMDSIZE_VALUE_MASK) <<
            XSPI_QSPI_PRV_CDTBUF_CMDSIZE_OFFSET) |
        ((p_transfer->address_length & XSPI_QSPI_PRV_CDTBUF_ADDSIZE_VALUE_MASK) <<
            XSPI_QSPI_PRV_CDTBUF_ADDSIZE_OFFSET) |
        ((p_transfer->data_length & XSPI_QSPI_PRV_CDTBUF_DATASIZE_VALUE_MASK) <<
            XSPI_QSPI_PRV_CDTBUF_DATASIZE_OFFSET) |
        ((p_transfer->dummy_cycles & XSPI_QSPI_PRV_CDTBUF_LATE_VALUE_MASK) <<
            XSPI_QSPI_PRV_CDTBUF_LATE_OFFSET) |
        ((direction & XSPI_QSPI_PRV_CDTBUF_TRTYPE_VALUE_MASK) <<
            XSPI_QSPI_PRV_CDTBUF_TRTYPE_OFFSET) |
        ((p_transfer->command & XSPI_QSPI_PRV_CDTBUF_CMD_VALUE_MASK) <<
            XSPI_QSPI_PRV_CDTBUF_CMD_UPPER_OFFSET);

    p_instance_ctrl->p_reg->BUF[0].CDA = p_transfer->address;

    if (SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE == direction)
    {
        p_instance_ctrl->p_reg->BUF[0].CDD0 = (uint32_t) p_transfer->data_u64 & UINT32_MAX;
        if (p_transfer->data_length > sizeof(uint32_t))
        {
            p_instance_ctrl->p_reg->BUF[0].CDD1 = (uint32_t) (p_transfer->data_u64 >> XSPI_QSPI_PRV_UINT32_BITS) &
                                                  UINT32_MAX;
        }
    }

    p_instance_ctrl->p_reg->CDCTL0_b.TRREQ = 1;
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->INTS_b.CMDCMP, 1);

    if (SPI_FLASH_DIRECT_TRANSFER_DIR_READ == direction)
    {
        p_transfer->data_u64 = p_instance_ctrl->p_reg->BUF[0].CDD0;
        if (p_transfer->data_length > sizeof(uint32_t))
        {
            p_transfer->data_u64 |= (uint64_t) (p_instance_ctrl->p_reg->BUF[0].CDD1) << XSPI_QSPI_PRV_UINT32_BITS;
        }
    }

    p_instance_ctrl->p_reg->INTC = 1 << XSPI_QSPI_PRV_INTC_CMDCMPC_OFFSET;
}

#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking.
 *
 * @param[in]  p_instance_ctrl         Pointer to a driver handle
 *
 * @retval FSP_SUCCESS                 Device size stored in p_device_size_bytes
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_DEVICE_BUSY         The device is busy.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 **********************************************************************************************************************/
static fsp_err_t r_xspi_qspi_param_checking_dcom (xspi_qspi_instance_ctrl_t * p_instance_ctrl)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(XSPI_QSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    FSP_ERROR_RETURN(0U == p_instance_ctrl->p_reg->CMCTL_b.XIPEN, FSP_ERR_INVALID_MODE);

    /* Verify device is not busy. */
    FSP_ERROR_RETURN(!r_xspi_qspi_status_sub(p_instance_ctrl), FSP_ERR_DEVICE_BUSY);

    return FSP_SUCCESS;
}

#endif

#if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking for R_XSPI_QSPI_Write.
 *
 * @param[in] p_instance_ctrl          Pointer to a driver handle
 * @param[in] p_src                    The source of the data to write to QSPI
 * @param[in] p_dest                   The address in QSPI to write to
 * @param[in] byte_count               The number of bytes to write
 *
 * @retval FSP_SUCCESS                 Parameters are valid.
 * @retval FSP_ERR_ASSERTION           p_instance_ctrl,p_device_address or p_memory_address is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when XIP mode is enabled.
 * @retval FSP_ERR_DEVICE_BUSY         The device is busy.
 **********************************************************************************************************************/
static fsp_err_t r_xspi_qspi_program_param_check (xspi_qspi_instance_ctrl_t * p_instance_ctrl,
                                                  uint8_t const * const       p_src,
                                                  uint8_t * const             p_dest,
                                                  uint32_t                    byte_count)
{
    fsp_err_t err = r_xspi_qspi_param_checking_dcom(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(NULL != p_src);
    FSP_ASSERT(NULL != p_dest);

    /* Check if byte_count is valid */
    uintptr_t page_size_bytes    = p_instance_ctrl->p_cfg->page_size_bytes;
    uintptr_t bytes_left_in_page = page_size_bytes - ((uintptr_t) p_dest % page_size_bytes);
    FSP_ASSERT(byte_count <= bytes_left_in_page);

 #if !XSPI_QSPI_CFG_DMAC_SUPPORT_ENABLE && BSP_FEATURE_XSPI_HAS_AXI_BRIDGE
    FSP_ASSERT(XSPI_QSPI_PRV_DIRECT_TRANSFER_MAX_BYTES >= byte_count);
 #else
    FSP_ASSERT(XSPI_QSPI_PRV_MAX_COMBINE_SIZE >= byte_count);
 #endif

    return FSP_SUCCESS;
}

#endif

#if XSPI_QSPI_CFG_OTFD_SUPPORT_ENABLE

/*******************************************************************************************************************//**
 * Configures OTFD side channel seed information.
 *
 * @param[out]  p_seed                            Pointer to seed array.
 * @retval      FSP_SUCCESS                       OTFD seed initialization completed successfully.
 * @return      See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes.
 *              This function calls:
 *                  * @ref R_RSIP_RandomNumberGenerate
 **********************************************************************************************************************/
static fsp_err_t r_xspi_qspi_otfd_side_channal_seed_init (uint32_t p_seed[])
{
    uint32_t  random_number[4U] = {0};
    fsp_err_t err               = R_RSIP_RandomNumberGenerate(&g_xspi_qspi_rsip_ctrl, (uint8_t *) &random_number[0]);

    if (FSP_SUCCESS == err)
    {
        p_seed[0] = random_number[0];
        p_seed[1] = (random_number[1] & XSPI_QSPI_PRV_OTFD_SEED_1_SEED_MASK) | XSPI_QSPI_PRV_OTFD_SEED_1_ENABLE_MASK;
    }

    return err;
}

/*******************************************************************************************************************//**
 * Configures the device for OTFD operation.
 *
 * @param[in]   p_instance_ctrl                   Pointer to the instance ctrl struct.
 * @retval      FSP_SUCCESS                       OTFD configuration completed successfully.
 * @retval      FSP_ERR_INVALID_ARGUMENT          Invalid key type argument or invalid OTFD conversion area.
 * @return      See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes.
 *              This function calls:
 *                  * @ref R_RSIP_Open
 *                  * @ref R_RSIP_InjectedKeyImport
 *                  * @ref R_RSIP_OTF_Init
 *                  * @ref R_RSIP_Close
 **********************************************************************************************************************/
static fsp_err_t r_xspi_qspi_otfd_setup (xspi_qspi_instance_ctrl_t * p_instance_ctrl)
{
    fsp_err_t rsip_ret             = FSP_SUCCESS;
    uint32_t  mirror_address_delta = BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS -
                                     BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS;
    uint32_t seed[2] = {0};
    uint8_t  wrapped_key[RSIP_BYTE_SIZE_WRAPPED_KEY_AES_256] = {0};

    xspi_qspi_extended_cfg_t * p_cfg_extend = (xspi_qspi_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
    xspi_qspi_otfd_cfg_t     * p_otfd_cfg   = (xspi_qspi_otfd_cfg_t *) p_cfg_extend->p_otfd_cfg;

    rsip_key_type_t key_type = RSIP_KEY_TYPE_AES_128;

    if (XSPI_QSPI_OTFD_AES_KEY_TYPE_128 == p_otfd_cfg->key_type)
    {
        key_type = RSIP_KEY_TYPE_AES_128;
    }
    else if (XSPI_QSPI_OTFD_AES_KEY_TYPE_256 == p_otfd_cfg->key_type)
    {
        key_type = RSIP_KEY_TYPE_AES_256;
    }
    else
    {
        return FSP_ERR_INVALID_ARGUMENT;
    }

 #if XSPI_QSPI_CFG_PARAM_CHECKING_ENABLE

    /* Verify OTFD conversion area. */
    FSP_ERROR_RETURN((uint32_t) p_otfd_cfg->p_end_addr >= (uint32_t) p_otfd_cfg->p_start_addr,
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((uint32_t) p_otfd_cfg->p_start_addr >=
                     (uint32_t) (BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS + (p_cfg_extend->unit) *
                                 BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE),
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((uint32_t) p_otfd_cfg->p_end_addr <
                     (uint32_t) (BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS + (p_cfg_extend->unit + 1U) *
                                 BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE),
                     FSP_ERR_INVALID_ARGUMENT);
 #endif

    /* Set the start and end area for OTFD conversion. */
    p_instance_ctrl->p_otfd_reg->CONVAREAST = ((uint32_t) p_otfd_cfg->p_start_addr - mirror_address_delta) &
                                              R_OTFD0_CONVAREAST_CONVAREAST_Msk;
    p_instance_ctrl->p_otfd_reg->CONVAREAED = ((uint32_t) p_otfd_cfg->p_end_addr - mirror_address_delta) &
                                              R_OTFD0_CONVAREAED_CONVAREAED_Msk;

    /* Open RSIP. */
    rsip_ret = R_RSIP_Open(&g_xspi_qspi_rsip_ctrl, &g_xspi_qspi_rsip_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == rsip_ret, rsip_ret);

    rsip_wrapped_key_t * p_wrapped_key = (rsip_wrapped_key_t *) wrapped_key;

    /* Generates structure data "rsip_wrapped_key_t". */
    rsip_ret = R_RSIP_InjectedKeyImport(key_type,
                                        (uint8_t *) p_otfd_cfg->p_key,
                                        p_wrapped_key,
                                        RSIP_BYTE_SIZE_WRAPPED_KEY_AES_256);
    FSP_ERROR_RETURN(FSP_SUCCESS == rsip_ret, rsip_ret);

    rsip_ret = r_xspi_qspi_otfd_side_channal_seed_init(seed);
    FSP_ERROR_RETURN(FSP_SUCCESS == rsip_ret, rsip_ret);

    /* Init OTFD. */
    rsip_ret =
        R_RSIP_OTF_Init(&g_xspi_qspi_rsip_ctrl,
                        (rsip_otf_channel_t) p_cfg_extend->unit,
                        p_wrapped_key,
                        (uint8_t *) &seed[0]);
    FSP_ERROR_RETURN(FSP_SUCCESS == rsip_ret, rsip_ret);

    if (FSP_SUCCESS == rsip_ret)
    {
        /* Disable byte order conversion. */
        p_instance_ctrl->p_otfd_reg->REG00 = (XSPI_QSPI_PRV_OTFD_REG00_RESET_VALUE | R_OTFD0_REG00_B09_Msk);

        /* Load the IV. */
        p_instance_ctrl->p_otfd_reg->REG03 = p_otfd_cfg->p_iv[0];
        p_instance_ctrl->p_otfd_reg->REG03 = p_otfd_cfg->p_iv[1];
        p_instance_ctrl->p_otfd_reg->REG03 = p_otfd_cfg->p_iv[2];
        p_instance_ctrl->p_otfd_reg->REG03 = p_otfd_cfg->p_iv[3];
    }

    /* Close RSIP. */
    rsip_ret = R_RSIP_Close(&g_xspi_qspi_rsip_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == rsip_ret, rsip_ret);

    return rsip_ret;
}

#endif
