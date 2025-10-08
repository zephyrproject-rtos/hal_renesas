/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_dmac.h"
#include "r_dmac_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Driver ID (DMAC in ASCII) */
#define DMAC_ID                        (0x444d4143)

/** Byte limited to 2^32-1 byte */
#define DMAC_BLOCK_MAX_LENGTH          (0xFFFFFFFF)
#define DMAC_BLOCK_COUNT_MAX_LENGTH    (0xFFFFFFFF)

#define DMAC_PRV_MASK_ALIGN_2_BYTES    (0x1U)
#define DMAC_PRV_MASK_ALIGN_4_BYTES    (0x2U)

/* Calculate the mask bits for byte alignment from the transfer_size_t. */
#define DMAC_PRV_MASK_ALIGN_N_BYTES(x)    ((1U << (x)) - 1U)

#define DMAC_PRV_REG(unit)                ((R_DMAC0_Type *) (((uintptr_t) R_DMAC1 - (uintptr_t) R_DMAC0) * unit + \
                                                             (uintptr_t) R_DMAC0))

#define DMAC_PRV_CHANNEL(channel)         (channel % 8)
#define DMAC_PRV_GROUP(channel)           (channel / 8)

#define DMAC_PRV_ATCM_END_ADDRESS          (0x0007FFFF)
#define DMAC_PRV_BTCM_START_ADDRESS        (0x00100000)
#define DMAC_PRV_BTCM_END_ADDRESS          (0x0010FFFF)
#define DMAC_PRV_CPU0_TCM_BASE_ADDRESS     (0x20000000)
#define DMAC_PRV_CPU1_TCM_BASE_ADDRESS     (0x21000000)

#define DMAC_PRV_DCTRL_DEFAULT_VALUE       (0x00000000U)
#define DMAC_PRV_CHCFG_DEFAULT_VALUE       (0x00000000U)

/* Channel Extension Register Bit Field Definitions */
#define DMAC_PRV_CHEXT_SCA_OFFSET          (4U)
#define DMAC_PRV_CHEXT_DCA_OFFSET          (12U)

/* Channel Control Register Bit Field Definitions */
#define DMAC_PRV_CHCTRL_SETEN_OFFSET       (0U)
#define DMAC_PRV_CHCTRL_SETEN_MASK         (1U << DMAC_PRV_CHCTRL_SETEN_OFFSET)
#define DMAC_PRV_CHCTRL_CLREN_OFFSET       (1U)
#define DMAC_PRV_CHCTRL_CLREN_MASK         (1U << DMAC_PRV_CHCTRL_CLREN_OFFSET)
#define DMAC_PRV_CHCTRL_STG_OFFSET         (2U)
#define DMAC_PRV_CHCTRL_STG_MASK           (1U << DMAC_PRV_CHCTRL_STG_OFFSET)
#define DMAC_PRV_CHCTRL_SWRST_OFFSET       (3U)
#define DMAC_PRV_CHCTRL_SWRST_MASK         (1U << DMAC_PRV_CHCTRL_SWRST_OFFSET)
#define DMAC_PRV_CHCTRL_CLREND_OFFSET      (5U)
#define DMAC_PRV_CHCTRL_CLREND_MASK        (1U << DMAC_PRV_CHCTRL_CLREND_OFFSET)
#define DMAC_PRV_CHCTRL_SETSUS_OFFSET      (8U)
#define DMAC_PRV_CHCTRL_SETSUS_MASK        (1U << DMAC_PRV_CHCTRL_SETSUS_OFFSET)

/* Channel Configuration Register Bit Field Definitions */
#define DMAC_PRV_CHCFG_SEL_OFFSET          (0U)
#define DMAC_PRV_CHCFG_REQD_OFFSET         (3U)
#define DMAC_PRV_CHCFG_LOEN_OFFSET         (4U)
#define DMAC_PRV_CHCFG_AM_OFFSET           (8U)
#define DMAC_PRV_CHCFG_SDS_OFFSET          (12U)
#define DMAC_PRV_CHCFG_SDS_VALUE_MASK      (0x0FU)
#define DMAC_PRV_CHCFG_DDS_OFFSET          (16U)
#define DMAC_PRV_CHCFG_DDS_VALUE_MASK      (0x0FU)
#define DMAC_PRV_CHCFG_SAD_OFFSET          (20U)
#define DMAC_PRV_CHCFG_SAD_VALUE_MASK      (0x01U)
#define DMAC_PRV_CHCFG_DAD_OFFSET          (21U)
#define DMAC_PRV_CHCFG_DAD_VALUE_MASK      (0x01U)
#define DMAC_PRV_CHCFG_TM_OFFSET           (22U)
#define DMAC_PRV_CHCFG_DEM_OFFSET          (24U)
#define DMAC_PRV_CHCFG_DEM_MASK            (1U << DMAC_PRV_CHCFG_DEM_OFFSET)
#define DMAC_PRV_CHCFG_RSW_OFFSET          (29U)
#define DMAC_PRV_NEXT_REG_VALUE_MASK       (0x03U)

/* DMA Control Register Bit Field Definitions */
#define DMAC_PRV_DCTRL_PR_OFFSET           (0U)
#define DMAC_PRV_DCTRL_PR_VALUE_MASK       (0x01U)
#define DMAC_PRV_DCTRL_LVINT_OFFSET        (1U)
#define DMAC_PRV_DCTRL_LVINT_VALUE_MASK    (0x01U)

/* DMAC Resource Select Register Bit Field Definitions */
#define DMAC_PRV_RSSEL_REQ_SEL_OFFSET      (10U)
#define DMAC_PRV_RSSEL_REQ_SEL_MASK        (0x3FFU)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void dmac_int_isr(void);
void dmac_err_int_isr(uint32_t id);

static fsp_err_t r_dmac_prv_enable(dmac_instance_ctrl_t * p_instance_ctrl);
static void      r_dmac_prv_disable(dmac_instance_ctrl_t * p_instance_ctrl);
static void      r_dmac_config_transfer_info_register_mode(dmac_instance_ctrl_t * p_instance_ctrl,
                                                           transfer_info_t      * p_info);
static void     r_dmac_config_transfer_info_link_mode(dmac_instance_ctrl_t * p_instance_ctrl);
static uint32_t r_dmac_config_chext(uint32_t src_address, uint32_t dest_address);
static bool     r_dmac_address_tcm_check(uint32_t address);

#if DMAC_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_dma_open_parameter_checking(dmac_instance_ctrl_t * const p_instance_ctrl,
                                               transfer_cfg_t const * const p_cfg);
static fsp_err_t r_dmac_info_paramter_checking(transfer_info_t const * const p_info);
static fsp_err_t r_dmac_link_descriptor_paramter_checking(dmac_link_cfg_t const * p_descriptor);
static fsp_err_t r_dmac_enable_parameter_checking(dmac_instance_ctrl_t * const p_instance_ctrl);
static fsp_err_t r_dmac_enable_parameter_checking_register_mode(dmac_instance_ctrl_t * const p_instance_ctrl);
static fsp_err_t r_dmac_enable_parameter_checking_link_mode(dmac_instance_ctrl_t * const p_instance_ctrl);

static bool r_dmac_address_tcm_via_axis_check(uint32_t address);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/* Channel control struct array */
static dmac_instance_ctrl_t * gp_ctrl[BSP_FEATURE_DMAC_MAX_UNIT * BSP_FEATURE_DMAC_MAX_CHANNEL] = {NULL};

/** DMAC implementation of transfer API. */
const transfer_api_t g_transfer_on_dmac =
{
    .open          = R_DMAC_Open,
    .reconfigure   = R_DMAC_Reconfigure,
    .reset         = R_DMAC_Reset,
    .infoGet       = R_DMAC_InfoGet,
    .softwareStart = R_DMAC_SoftwareStart,
    .softwareStop  = R_DMAC_SoftwareStop,
    .enable        = R_DMAC_Enable,
    .disable       = R_DMAC_Disable,
    .reload        = R_DMAC_Reload,
    .callbackSet   = R_DMAC_CallbackSet,
    .close         = R_DMAC_Close,
};

/*******************************************************************************************************************//**
 * @addtogroup DMAC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configure a DMAC channel.
 *
 * @retval FSP_SUCCESS                    Successful open.
 * @retval FSP_ERR_ASSERTION              An input parameter is invalid.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The configured channel is invalid.
 * @retval FSP_ERR_IRQ_BSP_DISABLED       The IRQ associated with the activation source is not enabled in the BSP.
 * @retval FSP_ERR_ALREADY_OPEN           The control structure is already opened.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Open (transfer_ctrl_t * const p_ctrl, transfer_cfg_t const * const p_cfg)
{
#if DMAC_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = FSP_SUCCESS;
    err = r_dma_open_parameter_checking(p_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    dmac_instance_ctrl_t * p_instance_ctrl = (dmac_instance_ctrl_t *) p_ctrl;
    dmac_extended_cfg_t  * p_extend        = (dmac_extended_cfg_t *) p_cfg->p_extend;

    p_instance_ctrl->p_cfg = p_cfg;
    p_instance_ctrl->p_reg = DMAC_PRV_REG(p_extend->unit);

    /* Configure the transfer settings. */
    if (DMAC_MODE_SELECT_REGISTER == p_extend->dmac_mode)
    {
        p_instance_ctrl->dmac_mode = DMAC_MODE_SELECT_REGISTER;
        r_dmac_config_transfer_info_register_mode(p_instance_ctrl, p_cfg->p_info);
    }
    else if (DMAC_MODE_SELECT_LINK == p_extend->dmac_mode)
    {
        p_instance_ctrl->dmac_mode = DMAC_MODE_SELECT_LINK;
        r_dmac_config_transfer_info_link_mode(p_instance_ctrl);
    }
    else
    {
        /* Do nothing. */
    }

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_extend->p_callback;
    p_instance_ctrl->p_context         = p_extend->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Mark driver as open by initializing "DMAC" in its ASCII equivalent.*/
    p_instance_ctrl->open = DMAC_ID;

    /* Track ctrl struct */
    gp_ctrl[(p_extend->unit) * BSP_FEATURE_DMAC_MAX_CHANNEL + (p_extend->channel)] = p_instance_ctrl;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reconfigure the transfer descriptor information with new transfer descriptor.
 *
 * @retval FSP_SUCCESS              Transfer is configured and will start when trigger occurs.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_ENABLED      DMAC is not enabled. The current configuration must not be valid.
 * @retval FSP_ERR_INVALID_MODE     DMA mode is register mode. This function can only be used when the DMA mode is link mode.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_LinkDescriptorSet (transfer_ctrl_t * const p_ctrl, dmac_link_cfg_t * p_descriptor)
{
    dmac_instance_ctrl_t * p_instance_ctrl = (dmac_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = FSP_SUCCESS;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ERROR_RETURN(p_instance_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(p_descriptor != NULL);
    err = r_dmac_link_descriptor_paramter_checking(p_descriptor);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

#if defined(BSP_CFG_CORE_CA55)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.DMS == 1U, FSP_ERR_INVALID_MODE);
#endif

    /* Store current descriptor */
    p_instance_ctrl->p_descriptor = p_descriptor;

#if defined(BSP_CFG_CORE_CA55)

    /* Set address of the link destination */
    va = (uint64_t) p_descriptor;
    R_BSP_MmuVatoPa(va, &pa);
    p_instance_ctrl->p_reg->GRP[group].CH[channel].NXLA = (uint32_t) pa;
#else

    /* Set address of the link destination */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].NXLA = (uint32_t) p_descriptor;
#endif

    err = r_dmac_prv_enable(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_NOT_ENABLED);

    /* Wait descriptor load */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.DL, 0);

    return err;
}

/*******************************************************************************************************************//**
 * Reconfigure the transfer with new transfer info.
 *
 * @retval FSP_SUCCESS              Transfer is configured and will start when trigger occurs.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_ENABLED      DMAC is not enabled. The current configuration must not be valid.
 * @retval FSP_ERR_INVALID_MODE     DMA mode is link mode. This function can only be used when the DMA mode is register mode.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Reconfigure (transfer_ctrl_t * const p_ctrl, transfer_info_t * p_info)
{
    dmac_instance_ctrl_t * p_instance_ctrl = (dmac_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = FSP_SUCCESS;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ERROR_RETURN(p_instance_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
    err = r_dmac_info_paramter_checking(p_info);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

    FSP_ERROR_RETURN(p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.DMS == 0U, FSP_ERR_INVALID_MODE);
#endif

    /* Reconfigure the transfer settings. */
    r_dmac_config_transfer_info_register_mode(p_instance_ctrl, p_info);

    err = r_dmac_prv_enable(p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_NOT_ENABLED);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reset transfer source, destination, and number of transfers.
 *
 * @retval FSP_ERR_UNSUPPORTED              API not supported.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Reset (transfer_ctrl_t * const p_ctrl,
                        void const * volatile   p_src,
                        void * volatile         p_dest,
                        uint16_t const          num_transfers)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_src);
    FSP_PARAMETER_NOT_USED(p_dest);
    FSP_PARAMETER_NOT_USED(num_transfers);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Set a transfer request by software.
 *
 * @retval FSP_SUCCESS              Transfer started written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_SoftwareStart (transfer_ctrl_t * const p_ctrl, transfer_start_mode_t mode)
{
    dmac_instance_ctrl_t * p_instance_ctrl = (dmac_instance_ctrl_t *) p_ctrl;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_instance_ctrl->p_cfg);
    FSP_ASSERT(NULL != p_instance_ctrl->p_cfg->p_extend);
    FSP_ERROR_RETURN(p_instance_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
#endif

    FSP_PARAMETER_NOT_USED(mode);

    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

    /* Set auto clear bit and software start bit. */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = DMAC_PRV_CHCTRL_STG_MASK;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stop software transfers if they were started with TRANSFER_START_MODE_REPEAT.
 *
 * @retval FSP_ERR_UNSUPPORTED              API not supported.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_SoftwareStop (transfer_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Enable transfers for the configured activation source.
 *
 * @retval FSP_SUCCESS              Counter value written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Enable (transfer_ctrl_t * const p_ctrl)
{
    dmac_instance_ctrl_t * p_instance_ctrl = (dmac_instance_ctrl_t *) p_ctrl;
#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(p_instance_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
#endif

    return r_dmac_prv_enable(p_instance_ctrl);
}

/*******************************************************************************************************************//**
 * Disable transfers so that they are no longer triggered by the activation source.
 *
 * @retval FSP_SUCCESS              Counter value written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Disable (transfer_ctrl_t * const p_ctrl)
{
    dmac_instance_ctrl_t * p_instance_ctrl = (dmac_instance_ctrl_t *) p_ctrl;
#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(p_instance_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
#endif

    r_dmac_prv_disable(p_instance_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set driver specific information in provided pointer.
 *
 * @retval FSP_SUCCESS              Information has been written to p_info.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_InfoGet (transfer_ctrl_t * const p_ctrl, transfer_properties_t * const p_info)
{
    dmac_instance_ctrl_t * p_instance_ctrl = (dmac_instance_ctrl_t *) p_ctrl;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(p_instance_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_info);
#endif

    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    p_info->transfer_length_max = DMAC_MAX_NORMAL_TRANSFER_LENGTH;
    p_info->block_count_max     = DMAC_BLOCK_COUNT_MAX_LENGTH;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

    p_info->block_count_remaining     = DMAC_MAX_BLOCK_TRANSFER_LENGTH;
    p_info->transfer_length_remaining = (p_instance_ctrl->p_reg->GRP[group].CH[channel].CRTB);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Make the following transfer settings to continue the transfer.
 *
 * @retval FSP_SUCCESS           Successful continuous transfer settings.
 * @retval FSP_ERR_ASSERTION     An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN      Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 * @retval FSP_ERR_INVALID_MODE  This API cannot be called during link mode operation or setting not to use the Next1 register.
 * @retval FSP_ERR_INVALID_CALL  Invalid call. The series of transfer processing has finished.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Reload (transfer_ctrl_t * const p_ctrl,
                         void const * volatile   p_src,
                         void * volatile         p_dest,
                         uint32_t const          num_transfers)
{
    dmac_instance_ctrl_t * p_instance_ctrl = (dmac_instance_ctrl_t *) p_ctrl;

    uint32_t * p_src_cast;
    uint32_t * p_dest_cast;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(p_instance_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(p_instance_ctrl->dmac_mode == DMAC_MODE_SELECT_REGISTER, FSP_ERR_INVALID_MODE);
#endif

#if defined(BSP_CFG_CORE_CA55)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

#if DMAC_CFG_PARAM_CHECKING_ENABLE

    /* Reload API is only available when using both Next0/1 register sets. */
    FSP_ERROR_RETURN(p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.RSW == 1, FSP_ERR_INVALID_MODE);
#endif

    fsp_err_t err = FSP_SUCCESS;

    /* Confirm that DMA transaction is in progress and one of the register set transfers has completed.
     * Every time a DMA transfer of a register set completes, the REN bit in the CHCFG_n register is cleared to 0 automatically. */
    if ((1 == p_instance_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.EN) &&
        (0 == p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.REN))
    {
        p_src_cast  = (uint32_t *) p_src;
        p_dest_cast = (uint32_t *) p_dest;

        /* Obtain register set currently in use */
        if (1 == p_instance_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.SR)
        {
#if defined(BSP_CFG_CORE_CA55)

            /* Register set currently in use is the Next1 register. Set the Next0 register for the next transfer. */
            va = (uint64_t) p_src_cast;
            R_BSP_MmuVatoPa(va, &pa);
            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].SA = (uint32_t) pa;

            va = (uint64_t) p_dest_cast;
            R_BSP_MmuVatoPa(va, &pa);
            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].DA = (uint32_t) pa;
#elif ((1 == BSP_CFG_CORE_CR52) && (1 == BSP_FEATURE_DMAC_HAS_CPU1_TCM_AREA))

            /* Register set currently in use is the Next1 register. Set the Next0 register for the next transfer. */
            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].SA =
                (true == r_dmac_address_tcm_check((uint32_t) p_src_cast)) ?
                ((uint32_t) p_src_cast + DMAC_PRV_CPU1_TCM_BASE_ADDRESS) : ((uint32_t) p_src_cast);

            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].DA =
                (true == r_dmac_address_tcm_check((uint32_t) p_dest_cast)) ?
                ((uint32_t) p_dest_cast + DMAC_PRV_CPU1_TCM_BASE_ADDRESS) : ((uint32_t) p_dest_cast);
#else

            /* Register set currently in use is the Next1 register. Set the Next0 register for the next transfer. */
            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].SA =
                (true == r_dmac_address_tcm_check((uint32_t) p_src_cast)) ?
                ((uint32_t) p_src_cast +
                 DMAC_PRV_CPU0_TCM_BASE_ADDRESS) : ((uint32_t) p_src_cast);

            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].DA =
                (true == r_dmac_address_tcm_check((uint32_t) p_dest_cast)) ?
                ((uint32_t) p_dest_cast +
                 DMAC_PRV_CPU0_TCM_BASE_ADDRESS) : ((uint32_t) p_dest_cast);
#endif
            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].TB = num_transfers;
        }
        else
        {
#if defined(BSP_CFG_CORE_CA55)

            /* Register set currently in use is the Next1 register. Set the Next0 register for the next transfer. */
            va = (uint64_t) p_src_cast;
            R_BSP_MmuVatoPa(va, &pa);
            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].SA = (uint32_t) pa;

            va = (uint64_t) p_dest_cast;
            R_BSP_MmuVatoPa(va, &pa);
            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].DA = (uint32_t) pa;
#elif ((1 == BSP_CFG_CORE_CR52) && (1 == BSP_FEATURE_DMAC_HAS_CPU1_TCM_AREA))

            /* Register set currently in use is the Next0 register. Set the Next1 register for the next transfer. */
            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].SA =
                (true == r_dmac_address_tcm_check((uint32_t) p_src)) ?
                ((uint32_t) p_src + DMAC_PRV_CPU1_TCM_BASE_ADDRESS) : ((uint32_t) p_src);

            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].DA =
                (true == r_dmac_address_tcm_check((uint32_t) p_dest)) ?
                ((uint32_t) p_dest + DMAC_PRV_CPU1_TCM_BASE_ADDRESS) : ((uint32_t) p_dest);
#else

            /* Register set currently in use is the Next0 register. Set the Next1 register for the next transfer. */
            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].SA =
                (true == r_dmac_address_tcm_check((uint32_t) p_src)) ?
                ((uint32_t) p_src + DMAC_PRV_CPU0_TCM_BASE_ADDRESS) : ((uint32_t) p_src);

            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].DA =
                (true == r_dmac_address_tcm_check((uint32_t) p_dest)) ?
                ((uint32_t) p_dest + DMAC_PRV_CPU0_TCM_BASE_ADDRESS) : ((uint32_t) p_dest);
#endif

            p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].TB = num_transfers;
        }

        /* To perform transfers in series, write 1 to the REN bit in the CHCFG_n register.*/
        p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.REN = 1;
    }
    else
    {
        /* When reloading has been behind return error. */
        err = FSP_ERR_INVALID_CALL;
    }

    return err;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref transfer_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_CallbackSet (transfer_ctrl_t * const          p_ctrl,
                              void (                         * p_callback)(transfer_callback_args_t *),
                              void const * const               p_context,
                              transfer_callback_args_t * const p_callback_memory)
{
    dmac_instance_ctrl_t * p_instance_ctrl = (dmac_instance_ctrl_t *) p_ctrl;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(DMAC_ID == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback, context and callback memory */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable transfer and clean up internal data. Implements @ref transfer_api_t::close.
 *
 * @retval FSP_SUCCESS           Successful close.
 * @retval FSP_ERR_ASSERTION     An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN      Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Close (transfer_ctrl_t * const p_ctrl)
{
    dmac_instance_ctrl_t * p_instance_ctrl = (dmac_instance_ctrl_t *) p_ctrl;
#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(p_instance_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
#endif

    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

    /* Disable DMAC transfers on this channel. */
    uint32_t rssel_register_num = p_extend->channel / 3;
    uint32_t rssel_bit_bum      = p_extend->channel % 3;
    if (0 == p_extend->unit)
    {
        R_DMA->DMAC0_RSSEL[rssel_register_num] |=
            (uint32_t) (DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));
    }
    else if (1 == p_extend->unit)
    {
        R_DMA->DMAC1_RSSEL[rssel_register_num] |=
            (uint32_t) (DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));
    }

#if (3 == BSP_FEATURE_DMAC_MAX_UNIT)
    else if (2 == p_extend->unit)
    {
        R_DMA->DMAC2_RSSEL[rssel_register_num] |=
            (uint32_t) (DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));
    }
#endif
    else
    {
        /* Do nothing */
    }

    /* Disable DMA transfer */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = DMAC_PRV_CHCTRL_CLREN_MASK;

    /* Wait DMA stop */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.TACT, 0);

    /* DMA Software Reset. */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = DMAC_PRV_CHCTRL_SWRST_MASK;

    if (NULL != p_extend->p_callback)
    {
        R_BSP_IrqDisable(p_extend->dmac_int_irq);
        R_FSP_IsrContextSet(p_extend->dmac_int_irq, NULL);
    }

    /* Clear ID so control block can be reused. */
    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup DMAC)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable transfers for the channel.
 *
 * @param[in]  p_instance_ctrl             Pointer to control structure.
 *
 * @retval     FSP_SUCCESS          Successful close.
 * @retval     FSP_ERR_ASSERTION    An input parameter is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_prv_enable (dmac_instance_ctrl_t * p_instance_ctrl)
{
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
#if DMAC_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_dmac_enable_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

    /* DMA Software Reset. */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = DMAC_PRV_CHCTRL_SWRST_MASK;

    if (DMAC_MODE_SELECT_REGISTER == p_instance_ctrl->dmac_mode)
    {
        /* Does not mask DMA transfer end interrupt */
        p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG &= (~((uint32_t) DMAC_PRV_CHCFG_DEM_MASK));
    }

    /* Enable transfer. */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = DMAC_PRV_CHCTRL_SETEN_MASK;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable transfers for the channel.
 *
 * @param      p_instance_ctrl          Pointer to the control structure
 **********************************************************************************************************************/
static void r_dmac_prv_disable (dmac_instance_ctrl_t * p_instance_ctrl)
{
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

    /* Disable DMA transfer */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = DMAC_PRV_CHCTRL_CLREN_MASK;

    /* Wait DMA stop */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.TACT, 0);

    /* DMA Software Reset */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = DMAC_PRV_CHCTRL_SWRST_MASK;

    if (DMAC_MODE_SELECT_REGISTER == p_instance_ctrl->dmac_mode)
    {
        /* Set DMA transfer end interrupt mask */
        p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG |= DMAC_PRV_CHCFG_DEM_MASK;
    }
}

/*******************************************************************************************************************//**
 * Write the transfer info to the hardware registers for register mode operation.
 *
 * @param[in]   p_instance_ctrl         Pointer to control structure.
 * @param       p_info         Pointer to transfer info.
 *                             The structure of this argument will be changed in next major release to reflect the transfer
 *                             API replace.
 **********************************************************************************************************************/
static void r_dmac_config_transfer_info_register_mode (dmac_instance_ctrl_t * p_instance_ctrl, transfer_info_t * p_info)
{
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

    uint32_t * p_src_cast;
    uint32_t * p_dest_cast;

#if defined(BSP_CFG_CORE_CA55)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    uint32_t dctrl = DMAC_PRV_DCTRL_DEFAULT_VALUE;
    uint32_t chcfg = DMAC_PRV_CHCFG_DEFAULT_VALUE;

    /* Disable transfers if they are currently enabled. */
    r_dmac_prv_disable(p_instance_ctrl);

    /* Priority control select */
    dctrl |= ((p_extend->channel_scheduling) & DMAC_PRV_DCTRL_PR_VALUE_MASK) << DMAC_PRV_DCTRL_PR_OFFSET;

    /* Configure channel */
    /* Set source and destination size. */
    chcfg |= (uint32_t) p_info->src_size << DMAC_PRV_CHCFG_SDS_OFFSET;
    chcfg |= (uint32_t) p_info->dest_size << DMAC_PRV_CHCFG_DDS_OFFSET;

    /* Set source and destination address mode. */
    chcfg |= (uint32_t) p_info->src_addr_mode << DMAC_PRV_CHCFG_SAD_OFFSET;
    chcfg |= (uint32_t) p_info->dest_addr_mode << DMAC_PRV_CHCFG_DAD_OFFSET;

    /* Set transfer mode/ */
    chcfg |= (uint32_t) p_info->mode << DMAC_PRV_CHCFG_TM_OFFSET;

    chcfg |= (uint32_t) channel << DMAC_PRV_CHCFG_SEL_OFFSET;
    chcfg |= (uint32_t) p_extend->activation_request_source_select << DMAC_PRV_CHCFG_REQD_OFFSET;
    chcfg |= (uint32_t) p_extend->detection_mode << DMAC_PRV_CHCFG_LOEN_OFFSET;
    chcfg |= (uint32_t) p_extend->ack_mode << DMAC_PRV_CHCFG_AM_OFFSET;

    if (NULL != p_extend->p_callback)
    {
        /* Enable transfer end interrupt requests. */
        chcfg &= ~((uint32_t) DMAC_PRV_CHCFG_DEM_MASK);

        /* Set Level Output when the DMA interrupt is enabled. */
        dctrl |= (1U & DMAC_PRV_DCTRL_LVINT_VALUE_MASK) << DMAC_PRV_DCTRL_LVINT_OFFSET;

        /* Enable the IRQ in the GIC. */
        R_BSP_IrqDetectTypeSet(p_extend->dmac_int_irq, p_extend->dmac_int_irq_detect_type);
        R_BSP_IrqCfgEnable(p_extend->dmac_int_irq, p_extend->dmac_int_ipl, p_instance_ctrl);
    }
    else
    {
        /* Set DMA transfer end interrupt mask */
        chcfg |= DMAC_PRV_CHCFG_DEM_MASK;
    }

    if (DMAC_REGISTER_SELECT_REVERSE_DISABLE != p_extend->next_register_operaion)
    {
        /* Set DMA transfer end interrupt mask */
        chcfg |= DMAC_PRV_CHCFG_DEM_MASK;

        /* Configure Register Set Reverse Select */
        chcfg |= ((p_extend->next_register_operaion & DMAC_PRV_NEXT_REG_VALUE_MASK) << DMAC_PRV_CHCFG_RSW_OFFSET);
    }

    uint32_t rssel_register_num = p_extend->channel / 3;
    uint32_t rssel_bit_bum      = p_extend->channel % 3;
    if (0 == p_extend->unit)
    {
        /* DMAC0 trigger source set. */
        uint32_t rssel = R_DMA->DMAC0_RSSEL[rssel_register_num];
        rssel &=
            (uint32_t) ~(DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        rssel |= (ELC_EVENT_NONE != p_extend->activation_source) ?
                 (uint32_t) ((p_extend->activation_source) << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum)) :
                 (uint32_t) (DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        R_DMA->DMAC0_RSSEL[rssel_register_num] = rssel;
    }
    else if (1 == p_extend->unit)
    {
        /* DMAC1 trigger source set. */
        uint32_t rssel = R_DMA->DMAC1_RSSEL[rssel_register_num];
        rssel &=
            (uint32_t) ~(DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        rssel |= (ELC_EVENT_NONE != p_extend->activation_source) ?
                 (uint32_t) ((p_extend->activation_source) << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum)) :
                 (uint32_t) (DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        R_DMA->DMAC1_RSSEL[rssel_register_num] = rssel;
    }

#if (3 == BSP_FEATURE_DMAC_MAX_UNIT)
    else if (2 == p_extend->unit)
    {
        /* DMAC2 trigger source set. */
        uint32_t rssel = R_DMA->DMAC2_RSSEL[rssel_register_num];
        rssel &=
            (uint32_t) ~(DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        rssel |= (ELC_EVENT_NONE != p_extend->activation_source) ?
                 (uint32_t) ((p_extend->activation_source) << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum)) :
                 (uint32_t) (DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        R_DMA->DMAC2_RSSEL[rssel_register_num] = rssel;
    }
#endif
    else
    {
        /* Do nothing */
    }

    /* Get the current value of DCTRL.LVINT to avoid overwriting setting of another channel and OR it. */
    dctrl |= (uint32_t) (p_instance_ctrl->p_reg->GRP[group].DCTRL_b.LVINT << DMAC_PRV_DCTRL_LVINT_OFFSET);

    p_instance_ctrl->p_reg->GRP[group].DCTRL = dctrl;

    p_src_cast  = (uint32_t *) p_info->p_src;
    p_dest_cast = (uint32_t *) p_info->p_dest;

#if defined(BSP_CFG_CORE_CA55)
    va = (uint64_t) p_src_cast;
    R_BSP_MmuVatoPa(va, &pa);
    p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].SA = (uint32_t) pa;

    va = (uint64_t) p_dest_cast;
    R_BSP_MmuVatoPa(va, &pa);
    p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].DA = (uint32_t) pa;
#elif ((1 == BSP_CFG_CORE_CR52) && (1 == BSP_FEATURE_DMAC_HAS_CPU1_TCM_AREA))

    /* When DMAC accesses TCM, use CPU1ATCM(0x21000000 - 0x2107FFFF) / CPU1BTCM(0x21100000 - 0x2110FFFF) area. */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].SA =
        (true == r_dmac_address_tcm_check((uint32_t) p_src_cast)) ?
        ((uint32_t) p_src_cast + DMAC_PRV_CPU1_TCM_BASE_ADDRESS) : ((uint32_t) p_src_cast);

    p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].DA =
        (true == r_dmac_address_tcm_check((uint32_t) p_dest_cast)) ?
        ((uint32_t) p_dest_cast + DMAC_PRV_CPU1_TCM_BASE_ADDRESS) : ((uint32_t) p_dest_cast);
#else

    /* When DMAC accesses TCM, use CPU0ATCM(0x20000000 - 0x2007FFFF) / CPU0BTCM(0x20100000 - 0x2010FFFF) area. */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].SA =
        (true == r_dmac_address_tcm_check((uint32_t) p_src_cast)) ?
        ((uint32_t) p_src_cast +
         DMAC_PRV_CPU0_TCM_BASE_ADDRESS) : ((uint32_t) p_src_cast);

    p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].DA =
        (true == r_dmac_address_tcm_check((uint32_t) p_dest_cast)) ?
        ((uint32_t) p_dest_cast +
         DMAC_PRV_CPU0_TCM_BASE_ADDRESS) : ((uint32_t) p_dest_cast);
#endif

    p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].TB       = p_info->length;
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG         = chcfg;
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHITVL_b.ITVL = p_extend->transfer_interval;

    uint32_t src_address  = (uint32_t) (uintptr_t) p_info->p_src;
    uint32_t dest_address = (uint32_t) (uintptr_t) p_info->p_dest;
    uint32_t chext        = r_dmac_config_chext(src_address, dest_address);

    if (DMAC_REGISTER_SELECT_REVERSE_DISABLE != p_extend->next_register_operaion)
    {
        p_src_cast  = (uint32_t *) p_info->p_next1_src;
        p_dest_cast = (uint32_t *) p_info->p_next1_dest;

#if defined(BSP_CFG_CORE_CA55)
        va = (uint64_t) p_src_cast;
        R_BSP_MmuVatoPa(va, &pa);
        p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].SA = (uint32_t) pa;

        va = (uint64_t) p_dest_cast;
        R_BSP_MmuVatoPa(va, &pa);
        p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].DA = (uint32_t) pa;
#elif ((1 == BSP_CFG_CORE_CR52) && (1 == BSP_FEATURE_DMAC_HAS_CPU1_TCM_AREA))

        /* When DMAC accesses TCM, use CPU0ATCM(0x20000000 - 0x2007FFFF) / CPU0BTCM(0x20100000 - 0x2010FFFF) area. */
        p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].SA =
            (true == r_dmac_address_tcm_check((uint32_t) p_src_cast)) ?
            ((uint32_t) p_src_cast + DMAC_PRV_CPU1_TCM_BASE_ADDRESS) :
            ((uint32_t) p_src_cast);

        p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].DA =
            (true == r_dmac_address_tcm_check((uint32_t) p_dest_cast)) ?
            ((uint32_t) p_dest_cast + DMAC_PRV_CPU1_TCM_BASE_ADDRESS) :
            ((uint32_t) p_dest_cast);
#else

        /* When DMAC accesses TCM, use CPU0ATCM(0x20000000 - 0x2007FFFF) / CPU0BTCM(0x20100000 - 0x2010FFFF) area. */
        p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].SA =
            (true == r_dmac_address_tcm_check((uint32_t) p_src_cast)) ?
            ((uint32_t) p_src_cast + DMAC_PRV_CPU0_TCM_BASE_ADDRESS) :
            ((uint32_t) p_src_cast);

        p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].DA =
            (true == r_dmac_address_tcm_check((uint32_t) p_dest_cast)) ?
            ((uint32_t) p_dest_cast + DMAC_PRV_CPU0_TCM_BASE_ADDRESS) :
            ((uint32_t) p_dest_cast);
#endif

        p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].TB = p_info->next1_length;

        src_address  = (uint32_t) (uintptr_t) p_info->p_next1_src;
        dest_address = (uint32_t) (uintptr_t) p_info->p_next1_dest;

        chext |= r_dmac_config_chext(src_address, dest_address);
    }

    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHEXT = chext;
}

/*******************************************************************************************************************//**
 * Set the hardware registers for link mode operation.
 *
 * @param[in]   p_instance_ctrl         Pointer to control structure.
 **********************************************************************************************************************/
static void r_dmac_config_transfer_info_link_mode (dmac_instance_ctrl_t * p_instance_ctrl)
{
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

#if defined(BSP_CFG_CORE_CA55)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    uint32_t dctrl = DMAC_PRV_DCTRL_DEFAULT_VALUE;

    /* Disable transfers if they are currently enabled. */
    r_dmac_prv_disable(p_instance_ctrl);

    /* Priority control select */
    dctrl |= ((p_extend->channel_scheduling) & DMAC_PRV_DCTRL_PR_VALUE_MASK) << DMAC_PRV_DCTRL_PR_OFFSET;

    if (NULL != p_extend->p_callback)
    {
        /* Set Level Output when the DMA interrupt is enabled. */
        dctrl |= (1U & DMAC_PRV_DCTRL_LVINT_VALUE_MASK) << DMAC_PRV_DCTRL_LVINT_OFFSET;

        /* Enable the IRQ in the GIC. */
        R_BSP_IrqDetectTypeSet(p_extend->dmac_int_irq, p_extend->dmac_int_irq_detect_type);
        R_BSP_IrqCfgEnable(p_extend->dmac_int_irq, p_extend->dmac_int_ipl, p_instance_ctrl);
    }

    uint32_t rssel_register_num = p_extend->channel / 3;
    uint32_t rssel_bit_bum      = p_extend->channel % 3;
    if (0 == p_extend->unit)
    {
        /* DMAC0 trigger source set. */
        uint32_t rssel = R_DMA->DMAC0_RSSEL[rssel_register_num];
        rssel &=
            (uint32_t) ~(DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        rssel |= (ELC_EVENT_NONE != p_extend->activation_source) ?
                 (uint32_t) ((p_extend->activation_source) << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum)) :
                 (uint32_t) (DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        R_DMA->DMAC0_RSSEL[rssel_register_num] = rssel;
    }
    else if (1 == p_extend->unit)
    {
        /* DMAC1 trigger source set. */
        uint32_t rssel = R_DMA->DMAC1_RSSEL[rssel_register_num];
        rssel &=
            (uint32_t) ~(DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        rssel |= (ELC_EVENT_NONE != p_extend->activation_source) ?
                 (uint32_t) ((p_extend->activation_source) << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum)) :
                 (uint32_t) (DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        R_DMA->DMAC1_RSSEL[rssel_register_num] = rssel;
    }

#if (3 == BSP_FEATURE_DMAC_MAX_UNIT)
    else if (2 == p_extend->unit)
    {
        /* DMAC2 trigger source set. */
        uint32_t rssel = R_DMA->DMAC2_RSSEL[rssel_register_num];
        rssel &=
            (uint32_t) ~(DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        rssel |= (ELC_EVENT_NONE != p_extend->activation_source) ?
                 (uint32_t) ((p_extend->activation_source) << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum)) :
                 (uint32_t) (DMAC_PRV_RSSEL_REQ_SEL_MASK << (DMAC_PRV_RSSEL_REQ_SEL_OFFSET * rssel_bit_bum));

        R_DMA->DMAC2_RSSEL[rssel_register_num] = rssel;
    }
#endif
    else
    {
        /* Do nothing */
    }
    p_instance_ctrl->p_reg->GRP[group].DCTRL = dctrl;

#if defined(BSP_CFG_CORE_CA55)

    /* Set address of the link destination */
    va = (uint64_t) (p_extend->p_descriptor);
    R_BSP_MmuVatoPa(va, &pa);
    p_instance_ctrl->p_reg->GRP[group].CH[channel].NXLA = (uint32_t) pa;
#else

    /* Set address of the link destination */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].NXLA = (uint32_t) (p_extend->p_descriptor);
#endif

    /* Store current descriptor. */
    p_instance_ctrl->p_descriptor = p_extend->p_descriptor;

    /* Set link mode */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.DMS = 1U;
}

/*******************************************************************************************************************//**
 * Determine CHEXT_n register value.
 *
 * @param[in]   src_address               Transfer source address
 * @param[in]   dest_address              Transfer destination address
 *
 * @retval CHEXT_n register value.
 **********************************************************************************************************************/
static uint32_t r_dmac_config_chext (uint32_t src_address, uint32_t dest_address)
{
    uint32_t chext = 0;

    /* The SCA[3:0] bits in CHEXT_n register should be set to 0x02 if source is TCM.
     * (see Section 'Channel Configuration Register n (CHCFG_n)' of the RZ microprocessor).
     */
    if (true == r_dmac_address_tcm_check(src_address))
    {
        chext |= (uint32_t) 0x02 << DMAC_PRV_CHEXT_SCA_OFFSET;
    }

    /* The DXA[3:0] bits in CHEXT_n register should be set to 0x02 if destination is TCM.
     * (see Section 'Channel Configuration Register n (CHCFG_n)' of the RZ microprocessor).
     */
    if (true == r_dmac_address_tcm_check(dest_address))
    {
        chext |= (uint32_t) 0x02 << DMAC_PRV_CHEXT_DCA_OFFSET;;
    }

    return chext;
}

/*******************************************************************************************************************//**
 * Checks if the address is in the TCM area
 *
 * @param[in]   address             Memory address
 *
 * @retval true if the address is in TCM area, false if not
 **********************************************************************************************************************/
static bool r_dmac_address_tcm_check (uint32_t address)
{
    return (bool) ((address <= DMAC_PRV_ATCM_END_ADDRESS) ||
                   ((DMAC_PRV_BTCM_START_ADDRESS <= address) && (address <= DMAC_PRV_BTCM_END_ADDRESS)));
}

#if DMAC_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking of R_DMAC_Open.
 *
 * @param[in]   p_instance_ctrl                    Pointer to control structure.
 * @param[in]   p_cfg                     Pointer to configuration structure. All elements of the structure must be
 *                                        set by user.
 *
 * @retval FSP_SUCCESS                    Input Parameters are Valid.
 * @retval FSP_ERR_ASSERTION              An input parameter is invalid.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The configured channel is invalid.
 * @retval FSP_ERR_IRQ_BSP_DISABLED       Callback is NULL and the DMAC IRQ is not enabled.
 * @retval FSP_ERR_ALREADY_OPEN           The control structure is already opened.
 **********************************************************************************************************************/
static fsp_err_t r_dma_open_parameter_checking (dmac_instance_ctrl_t * const p_instance_ctrl,
                                                transfer_cfg_t const * const p_cfg)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(p_instance_ctrl->open != DMAC_ID, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_cfg->p_extend;
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(p_extend->channel < BSP_FEATURE_DMAC_MAX_CHANNEL, FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    if (NULL != p_extend->p_callback)
    {
        FSP_ERROR_RETURN(p_extend->dmac_int_irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
    }

    fsp_err_t err = r_dmac_info_paramter_checking(p_cfg->p_info);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    if (DMAC_MODE_SELECT_LINK == p_extend->dmac_mode)
    {
        if (NULL != p_extend->p_descriptor)
        {
            err = r_dmac_link_descriptor_paramter_checking(p_extend->p_descriptor);
            FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        }
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Checks for errors in the transfer into structure.
 *
 * @param[in]   p_info              Pointer transfer info.
 *
 * @retval FSP_SUCCESS              The transfer info is valid.
 * @retval FSP_ERR_ASSERTION        A transfer info setting is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_info_paramter_checking (transfer_info_t const * const p_info)
{
    FSP_ASSERT(p_info != NULL);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Checks for errors in the transfer link mode descriptor structure.
 *
 * @param[in]   p_descriptor        Pointer link mode descriptor.
 *
 * @retval FSP_SUCCESS              The transfer info is valid.
 * @retval FSP_ERR_ASSERTION        A transfer info setting is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_link_descriptor_paramter_checking (dmac_link_cfg_t const * p_descriptor)
{
    dmac_link_cfg_t const * p_current_descriptor = p_descriptor;

    do
    {
        /* Start address of the link destination must be 4 byte align.
         * (See section 'Next Link Address Register n (NXLA_n)' of the RZ microprocessor manual) */
        FSP_ASSERT(0U == ((uintptr_t) p_current_descriptor & DMAC_PRV_MASK_ALIGN_N_BYTES(DMAC_PRV_MASK_ALIGN_4_BYTES)));

        /* Start address of the link destination must not be in TCM area.
         * (See section 'TCM Access via AXIS Interface of Cortex-R52' of the RZ microprocessor manual) */
        FSP_ERROR_RETURN(false == r_dmac_address_tcm_check((uint32_t) (uintptr_t) p_current_descriptor),
                         FSP_ERR_ASSERTION);
        FSP_ERROR_RETURN(false == r_dmac_address_tcm_via_axis_check((uint32_t) (uintptr_t) p_current_descriptor),
                         FSP_ERR_ASSERTION);

        if (DMAC_LINK_END_ENABLE == p_current_descriptor->header.link_end)
        {
            break;
        }

 #if defined(BSP_CFG_CORE_CA55)
        p_current_descriptor = (dmac_link_cfg_t *) (uintptr_t) (p_current_descriptor->next_link_addr);
 #else
        p_current_descriptor = (dmac_link_cfg_t *) (uintptr_t) (p_current_descriptor->p_next_link_addr);
 #endif
    } while (NULL != p_current_descriptor);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Parameter checking for r_dmac_prv_enable.
 *
 * @param[in]   p_instance_ctrl                 Pointer to control structure.
 *
 * @retval      FSP_SUCCESS            Alignment on source and destination pointers is valid.
 * @retval      FSP_ERR_ASSERTION      The current configuration is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_enable_parameter_checking (dmac_instance_ctrl_t * const p_instance_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;
    if (DMAC_MODE_SELECT_REGISTER == p_instance_ctrl->dmac_mode)
    {
        err = r_dmac_enable_parameter_checking_register_mode(p_instance_ctrl);
    }
    else if (DMAC_MODE_SELECT_LINK == p_instance_ctrl->dmac_mode)
    {
        err = r_dmac_enable_parameter_checking_link_mode(p_instance_ctrl);
    }
    else
    {
        /* Do nothing. */
    }

    return err;
}

/*******************************************************************************************************************//**
 * Parameter checking for r_dmac_prv_enable at register mode operation.
 *
 * @param[in]   p_instance_ctrl                 Pointer to control structure.
 *
 * @retval      FSP_SUCCESS            Alignment on source and destination pointers is valid.
 * @retval      FSP_ERR_ASSERTION      The current configuration is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_enable_parameter_checking_register_mode (dmac_instance_ctrl_t * const p_instance_ctrl)
{
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

    void const * p_src  = (void const *) (uintptr_t) p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].SA;
    void const * p_dest = (void const *) (uintptr_t) p_instance_ctrl->p_reg->GRP[group].CH[channel].N[0].DA;

    transfer_size_t src_size  = (transfer_size_t) p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.SDS;
    transfer_size_t dest_size = (transfer_size_t) p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.DDS;

    transfer_addr_mode_t src_addr_mode =
        (transfer_addr_mode_t) p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.SAD;
    transfer_addr_mode_t dest_addr_mode =
        (transfer_addr_mode_t) p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.DAD;

    /* When the transfer source address is beat-aligned, specify SAD = 0 (increment).
     * (See section 'Channel Configuration Register n (CHCFG_n)' of the RZ microprocessor manual) */
    if (0U != ((uintptr_t) p_src & DMAC_PRV_MASK_ALIGN_N_BYTES(src_size)))
    {
        FSP_ASSERT(TRANSFER_ADDR_MODE_INCREMENTED == src_addr_mode);
    }

    /* When the transfer destination address is beat-aligned, specify DAD = 0 (increment).
     * (See section 'Channel Configuration Register n (CHCFG_n)' of the RZ microprocessor manual) */
    if (0U != ((uintptr_t) p_dest & DMAC_PRV_MASK_ALIGN_N_BYTES(dest_size)))
    {
        FSP_ASSERT(TRANSFER_ADDR_MODE_INCREMENTED == dest_addr_mode);
    }

    if (1 == p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.RSW)
    {
        void const * p_src_next1  = (void const *) (uintptr_t) p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].SA;
        void const * p_dest_next1 = (void const *) (uintptr_t) p_instance_ctrl->p_reg->GRP[group].CH[channel].N[1].DA;

        /* The next1 register set source and destination pointers cannot be NULL. */
        FSP_ASSERT(NULL != p_src_next1);
        FSP_ASSERT(NULL != p_dest_next1);

        /* When the transfer source address is beat-aligned, specify SAD = 0 (increment).
         * (See section 'Channel Configuration Register n (CHCFG_n)' of the RZ microprocessor manual) */
        if (0U != ((uintptr_t) p_src_next1 & DMAC_PRV_MASK_ALIGN_N_BYTES(src_size)))
        {
            FSP_ASSERT(TRANSFER_ADDR_MODE_INCREMENTED == src_addr_mode);
        }

        /* When the transfer destination address is beat-aligned, specify DAD = 0 (increment).
         * (See section 'Channel Configuration Register n (CHCFG_n)' of the RZ microprocessor manual) */
        if (0U != ((uintptr_t) p_dest_next1 & DMAC_PRV_MASK_ALIGN_N_BYTES(dest_size)))
        {
            FSP_ASSERT(TRANSFER_ADDR_MODE_INCREMENTED == dest_addr_mode);
        }
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Parameter checking for r_dmac_prv_enable at link mode operation.
 *
 * @param[in]   p_instance_ctrl                 Pointer to control structure.
 *
 * @retval      FSP_SUCCESS            Alignment on source and destination pointers is valid.
 * @retval      FSP_ERR_ASSERTION      The current configuration is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_enable_parameter_checking_link_mode (dmac_instance_ctrl_t * const p_instance_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_ASSERT(NULL != p_instance_ctrl->p_descriptor);

    dmac_link_cfg_t const * p_current_descriptor = p_instance_ctrl->p_descriptor;
    do
    {
 #if defined(BSP_CFG_CORE_CA55)
        void const * p_src  = (void *) (uintptr_t) p_current_descriptor->src_addr;
        void const * p_dest = (void *) (uintptr_t) p_current_descriptor->dest_addr;
 #else
        void const * p_src  = p_current_descriptor->p_src;
        void const * p_dest = p_current_descriptor->p_dest;
 #endif

        uint32_t channel_cfg = p_current_descriptor->channel_cfg;

        transfer_size_t src_size =
            (transfer_size_t) ((channel_cfg >> DMAC_PRV_CHCFG_SDS_OFFSET) & DMAC_PRV_CHCFG_SDS_VALUE_MASK);
        transfer_size_t dest_size =
            (transfer_size_t) ((channel_cfg >> DMAC_PRV_CHCFG_DDS_OFFSET) & DMAC_PRV_CHCFG_DDS_VALUE_MASK);

        transfer_addr_mode_t src_addr_mode =
            (transfer_addr_mode_t) ((channel_cfg >> DMAC_PRV_CHCFG_SAD_OFFSET) & DMAC_PRV_CHCFG_SAD_VALUE_MASK);
        transfer_addr_mode_t dest_addr_mode =
            (transfer_addr_mode_t) ((channel_cfg >> DMAC_PRV_CHCFG_DAD_OFFSET) & DMAC_PRV_CHCFG_DAD_VALUE_MASK);

        /* When the transfer source address is beat-aligned, specify SAD = 0 (increment).
         * (See section 'Channel Configuration Register n (CHCFG_n)' of the RZ microprocessor manual) */
        if (0U != ((uintptr_t) p_src & DMAC_PRV_MASK_ALIGN_N_BYTES(src_size)))
        {
            FSP_ASSERT(TRANSFER_ADDR_MODE_INCREMENTED == src_addr_mode);
        }

        /* When the transfer destination address is beat-aligned, specify DAD = 0 (increment).
         * (See section 'Channel Configuration Register n (CHCFG_n)' of the RZ microprocessor manual) */
        if (0U != ((uintptr_t) p_dest & DMAC_PRV_MASK_ALIGN_N_BYTES(dest_size)))
        {
            FSP_ASSERT(TRANSFER_ADDR_MODE_INCREMENTED == dest_addr_mode);
        }

        if (DMAC_LINK_END_ENABLE == p_current_descriptor->header.link_end)
        {
            break;
        }

 #if defined(BSP_CFG_CORE_CA55)
        p_current_descriptor = (dmac_link_cfg_t *) (uintptr_t) (p_current_descriptor->next_link_addr);
 #else
        p_current_descriptor = (dmac_link_cfg_t *) (uintptr_t) (p_current_descriptor->p_next_link_addr);
 #endif
    } while (NULL != p_current_descriptor);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Checks if the address is in the TCM via AXIS area
 *
 * @param[in]   address             Memory address
 *
 * @retval true if the address is in TCM via AXIS area, false if not
 **********************************************************************************************************************/
static bool r_dmac_address_tcm_via_axis_check (uint32_t address)
{
 #if (1 == BSP_FEATURE_DMAC_HAS_CPU1_TCM_AREA)

    return (bool) (((DMAC_PRV_CPU0_TCM_BASE_ADDRESS <= address) &&
                    (address <= (DMAC_PRV_ATCM_END_ADDRESS + DMAC_PRV_CPU0_TCM_BASE_ADDRESS))) ||
                   (((DMAC_PRV_BTCM_START_ADDRESS + DMAC_PRV_CPU0_TCM_BASE_ADDRESS) <= address) &&
                    (address <= (DMAC_PRV_BTCM_END_ADDRESS + DMAC_PRV_CPU0_TCM_BASE_ADDRESS))) ||
                   (((DMAC_PRV_CPU1_TCM_BASE_ADDRESS) <= address) &&
                    (address <= (DMAC_PRV_ATCM_END_ADDRESS + DMAC_PRV_CPU1_TCM_BASE_ADDRESS))) ||
                   (((DMAC_PRV_BTCM_START_ADDRESS + DMAC_PRV_CPU1_TCM_BASE_ADDRESS) <= address) &&
                    (address <= (DMAC_PRV_BTCM_END_ADDRESS + DMAC_PRV_CPU1_TCM_BASE_ADDRESS))));
 #elif (0 == BSP_FEATURE_DMAC_HAS_CPU1_TCM_AREA)

    return (bool) (((DMAC_PRV_CPU0_TCM_BASE_ADDRESS <= address) &&
                    (address <= (DMAC_PRV_ATCM_END_ADDRESS + DMAC_PRV_CPU0_TCM_BASE_ADDRESS))) ||
                   (((DMAC_PRV_BTCM_START_ADDRESS + DMAC_PRV_CPU0_TCM_BASE_ADDRESS) <= address) &&
                    (address <= (DMAC_PRV_BTCM_END_ADDRESS + DMAC_PRV_CPU0_TCM_BASE_ADDRESS))));
 #endif
}

#endif

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_instance_ctrl     Pointer to DMAC instance control block
 * @param[in]     event      Event code
 **********************************************************************************************************************/
static void r_dmac_call_callback (dmac_instance_ctrl_t * p_instance_ctrl, transfer_event_t event)
{
    transfer_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    transfer_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->event     = event;
    p_args->p_context = p_instance_ctrl->p_context;

    p_instance_ctrl->p_callback(p_args);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * DMAC ISR
 **********************************************************************************************************************/
void dmac_int_isr (void)
{
    DMAC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    dmac_instance_ctrl_t * p_instance_ctrl = R_FSP_IsrContextGet(irq);
    dmac_extended_cfg_t  * p_extend        = (dmac_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_PRV_CHANNEL(p_extend->channel);

    /* Clear interrupt condition. */
    p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = DMAC_PRV_CHCTRL_CLREND_MASK;

    /* Dummy read to ensure that interrupt event is cleared. */
    volatile uint32_t dummy = p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCTRL;
    FSP_PARAMETER_NOT_USED(dummy);

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_dmac_call_callback(p_instance_ctrl, TRANSFER_EVENT_TRANSFER_END);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    DMAC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * DMAC ERROR ISR
 **********************************************************************************************************************/
void dmac_err_int_isr (uint32_t id)
{
    DMAC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Get the DMAC unit where the error occurred from the argument id. */
    uint8_t unit = (uint8_t) (id - BSP_FEATURE_DMAC_UNIT0_ERROR_NUM);

    /* Get the channel error information DSTAT_ER. */
    R_DMAC0_Type * p_base_reg      = DMAC_PRV_REG(unit);
    uint32_t       dstat_err_upper = p_base_reg->GRP[1].DSTAT_ER;
    uint32_t       dstat_err_lower = p_base_reg->GRP[0].DSTAT_ER;
    uint32_t       dstat_err_mask  = (dstat_err_upper << 8) | dstat_err_lower;

    uint32_t dmac_error_channel = 0;

    /* After going through the event scan, the interrupt handler ends */
    while (dstat_err_mask)
    {
        /* Scan and search for error factors one by one */
        uint32_t next_err = __CLZ(__RBIT(dstat_err_mask));
        dstat_err_mask    >>= next_err;
        dmac_error_channel += next_err;

        uint8_t group   = (uint8_t) DMAC_PRV_GROUP(dmac_error_channel);
        uint8_t channel = (uint8_t) DMAC_PRV_CHANNEL(dmac_error_channel);

        dmac_instance_ctrl_t * p_instance_ctrl = gp_ctrl[unit * BSP_FEATURE_DMAC_MAX_CHANNEL + dmac_error_channel];

        /* Call user registered callback */
        if (NULL != p_instance_ctrl)
        {
            /* When DMA transfer error occurred, after set the SWRST bit in the CHCTRL_n register to 1,
             * need to set transfer information again.
             * (See section 'DMA Error Interrupt' of the RZ microprocessor manual)
             *
             * Call the callback function after DMAC software reset.
             * This allows to reset the transfer information in user callback function.*/
            p_instance_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = DMAC_PRV_CHCTRL_SWRST_MASK;

            /* Invoke the callback function if it is set. */
            if (NULL != p_instance_ctrl->p_callback)
            {
                r_dmac_call_callback(p_instance_ctrl, TRANSFER_EVENT_TRANSFER_ERROR);
            }
        }

        /* Clear the scanned flags one by one */
        dstat_err_mask &= ~(uint32_t) (1UL);
    }

    DMAC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
