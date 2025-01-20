/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_dmac_b.h"
#include "r_dmac_b_cfg.h"
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
 #include "hal_data.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Driver ID (DMAC in ASCII) */
#define DMAC_B_ID                                  (0x444d4143)

/** Byte limited to 2^32-1 byte */
#define DMAC_B_BLOCK_MAX_LENGTH                    (0xFFFFFFFF)
#define DMAC_B_BLOCK_COUNT_MAX_LENGTH              (0xFFFFFFFF)

#define DMAC_B_PRV_CHANNEL(channel)    (channel % 8)
#define DMAC_B_PRV_GROUP(channel)      (channel / 8)

#define DMAC_B_PRV_DCTRL_DEFAULT_VALUE             (0x00000000U)
#define DMAC_B_PRV_CHCFG_DEFAULT_VALUE             (0x00000000U)

/* Channel Configuration Register Bit Field Definitions */
#define DMAC_B_PRV_CHCFG_SEL_VALUE_MASK            (0x07U)
#define DMAC_B_PRV_CHCFG_REQD_VALUE_MASK           (0x01U)
#define DMAC_B_PRV_CHCFG_DETECT_MODE_VALUE_MASK    (0x07U)
#define DMAC_B_PRV_CHCFG_AM_VALUE_MASK             (0x07U)
#define DMAC_B_PRV_CHCFG_SDS_VALUE_MASK            (0x0FU)
#define DMAC_B_PRV_CHCFG_DDS_VALUE_MASK            (0x0FU)
#define DMAC_B_PRV_CHCFG_SAD_VALUE_MASK            (0x01U)
#define DMAC_B_PRV_CHCFG_DAD_VALUE_MASK            (0x01U)
#define DMAC_B_PRV_CHCFG_TM_VALUE_MASK             (0x01U)
#define DMAC_B_PRV_NEXT_REG_VALUE_MASK             (0x03U)
#define DMAC_B_PRV_ACTIVATION_SOURCE_VALUE_MASK    (0xFFFU)

#define DMAC_B_PRV_ACK_MODE_VALUE_POS              (0x10U)
#define DMAC_B_PRV_DETECT_MODE_VALUE_POS           (0x18U)

/* DMA Control Register Bit Field Definitions */
#define DMAC_B_PRV_DCTRL_PR_OFFSET                 (0U)
#define DMAC_B_PRV_DCTRL_PR_VALUE_MASK             (0x01U)

/* DMAC Resource Select Register Bit Field Definitions */
#define DMAC_B_PRV_DMARS_MID_RID_OFFSET            (16U)
#define DMAC_B_PRV_DMARS_MID_RID_MASK              (0x3FFU)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void dmac_b_int_isr(void);
void dmac_b_err_isr(void);

static fsp_err_t r_dmac_b_prv_enable(dmac_b_instance_ctrl_t * p_ctrl);
static void      r_dmac_b_prv_disable(dmac_b_instance_ctrl_t * p_ctrl);
static void      r_dmac_b_config_transfer_info(dmac_b_instance_ctrl_t * p_ctrl, transfer_info_t * p_info);

#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_dmac_b_open_parameter_checking(dmac_b_instance_ctrl_t * const p_ctrl,
                                                  transfer_cfg_t const * const   p_cfg);
static fsp_err_t r_dmac_b_info_paramter_checking(transfer_info_t const * const p_info);
static fsp_err_t r_dmac_b_enable_parameter_checking(dmac_b_instance_ctrl_t * const p_ctrl);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* DMAC_B base address */
static const uint32_t volatile * p_dmac_b_base_address[BSP_FEATURE_DMAC_MAX_UNIT] =
{
    (uint32_t *) R_DMAC_B0,
#if BSP_FEATURE_DMAC_MAX_UNIT > 1
    (uint32_t *) R_DMAC_B1,
 #if BSP_FEATURE_DMAC_MAX_UNIT > 2
    (uint32_t *) R_DMAC_B2,
  #if BSP_FEATURE_DMAC_MAX_UNIT > 3
    (uint32_t *) R_DMAC_B3,
   #if BSP_FEATURE_DMAC_MAX_UNIT > 4
    (uint32_t *) R_DMAC_B4,
   #endif
  #endif
 #endif
#endif
};

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** DMAC implementation of transfer API. */
const transfer_api_t g_transfer_on_dmac_b =
{
    .open          = R_DMAC_B_Open,
    .reconfigure   = R_DMAC_B_Reconfigure,
    .reset         = R_DMAC_B_Reset,
    .infoGet       = R_DMAC_B_InfoGet,
    .softwareStart = R_DMAC_B_SoftwareStart,
    .softwareStop  = R_DMAC_B_SoftwareStop,
    .enable        = R_DMAC_B_Enable,
    .disable       = R_DMAC_B_Disable,
    .close         = R_DMAC_B_Close,
    .reload        = R_DMAC_B_Reload,
};

/*******************************************************************************************************************//**
 * @addtogroup DMAC_B
 * @{
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
fsp_err_t R_DMAC_B_Open (transfer_ctrl_t * const p_api_ctrl, transfer_cfg_t const * const p_cfg)
{
#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = FSP_SUCCESS;
    err = r_dmac_b_open_parameter_checking(p_api_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    dmac_b_instance_ctrl_t * p_ctrl   = (dmac_b_instance_ctrl_t *) p_api_ctrl;
    dmac_b_extended_cfg_t  * p_extend = (dmac_b_extended_cfg_t *) p_cfg->p_extend;

    p_ctrl->p_cfg = p_cfg;
    p_ctrl->p_reg = (R_DMAC_B0_Type *) p_dmac_b_base_address[p_extend->unit];

    /* Supply clock to DMAC module. */
    R_BSP_MODULE_START(FSP_IP_DMAC, p_extend->unit);

    /* Configure the transfer settings. */
    r_dmac_b_config_transfer_info(p_ctrl, p_cfg->p_info);

    /* Mark driver as open by initializing "DMAC" in its ASCII equivalent.*/
    p_ctrl->open = DMAC_B_ID;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reconfigure the transfer with new transfer info.
 *
 * @retval FSP_SUCCESS              Transfer is configured and will start when trigger occurs.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_ENABLED      DMAC is not enabled. The current configuration must not be valid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_B_Reconfigure (transfer_ctrl_t * const p_api_ctrl, transfer_info_t * p_info)
{
    fsp_err_t                err;
    dmac_b_instance_ctrl_t * p_ctrl = (dmac_b_instance_ctrl_t *) p_api_ctrl;

#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_B_ID, FSP_ERR_NOT_OPEN);
    err = r_dmac_b_info_paramter_checking(p_info);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(p_ctrl->p_cfg->p_extend != NULL);
    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;
    if (DMAC_B_CONTINUOUS_SETTING_TRANSFER_ONCE != p_extend->continuous_setting)
    {
        FSP_ASSERT(NULL != p_info->p_next1_src);
        FSP_ASSERT(NULL != p_info->p_next1_dest);
        FSP_ASSERT(0 != p_info->next1_length);
    }
#endif

    /* Reconfigure the transfer settings. */
    r_dmac_b_config_transfer_info(p_ctrl, p_info);

    /* Enable the transfer configuration. */
    err = r_dmac_b_prv_enable(p_api_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_NOT_ENABLED);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reset transfer source, destination, and number of transfers.
 *
 * @retval FSP_ERR_UNSUPPORTED              API not supported.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_B_Reset (transfer_ctrl_t * const p_api_ctrl,
                          void const * volatile   p_src,
                          void * volatile         p_dest,
                          uint16_t const          num_transfers)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_src);
    FSP_PARAMETER_NOT_USED(p_dest);
    FSP_PARAMETER_NOT_USED(num_transfers);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * If the mode is TRANSFER_START_MODE_SINGLE initiate a single transfer with software. If the mode is
 * TRANSFER_START_MODE_REPEAT continue triggering transfers until all of the transfers are completed.
 *
 * @retval FSP_SUCCESS              Transfer started written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_B_SoftwareStart (transfer_ctrl_t * const p_api_ctrl, transfer_start_mode_t mode)
{
    dmac_b_instance_ctrl_t * p_ctrl = (dmac_b_instance_ctrl_t *) p_api_ctrl;

#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_B_ID, FSP_ERR_NOT_OPEN);
#endif

    FSP_PARAMETER_NOT_USED(mode);

    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

    /* Set auto clear bit and software start bit. */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_STG_Msk;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stop software transfers if they were started with TRANSFER_START_MODE_REPEAT.
 *
 * @retval FSP_SUCCESS              Transfer stopped written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_B_SoftwareStop (transfer_ctrl_t * const p_api_ctrl)
{
    dmac_b_instance_ctrl_t * p_ctrl = (dmac_b_instance_ctrl_t *) p_api_ctrl;

#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_B_ID, FSP_ERR_NOT_OPEN);
#endif

    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

    /* Set Suspend. */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_SETSUS_Msk;

    /* Transfer is already stopped. */
    if (!(p_ctrl->p_reg->GRP[group].CH[channel].CHSTAT & R_DMAC_B0_GRP_CH_CHSTAT_EN_Msk))
    {
        /* Software Reset */
        p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_SWRST_Msk;

        return FSP_SUCCESS;
    }

    /* Check whether a transfer is suspended. */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.SUS, 1);

    /* Set clear enable and software stop bit. */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_CLREN_Msk;

    /* Check whether a transfer is stopped. */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.TACT, 0);

    /* Software Reset */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL_b.SWRST = 1;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable transfers for the configured activation source.
 *
 * @retval FSP_SUCCESS              Counter value written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_B_Enable (transfer_ctrl_t * const p_api_ctrl)
{
    dmac_b_instance_ctrl_t * p_ctrl = (dmac_b_instance_ctrl_t *) p_api_ctrl;
#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_B_ID, FSP_ERR_NOT_OPEN);
#endif

    return r_dmac_b_prv_enable(p_ctrl);
}

/*******************************************************************************************************************//**
 * Disable transfers so that they are no longer triggered by the activation source.
 *
 * @retval FSP_SUCCESS              Counter value written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_B_Disable (transfer_ctrl_t * const p_api_ctrl)
{
    dmac_b_instance_ctrl_t * p_ctrl = (dmac_b_instance_ctrl_t *) p_api_ctrl;
#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_B_ID, FSP_ERR_NOT_OPEN);
#endif

    r_dmac_b_prv_disable(p_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set driver specific information in provided pointer.
 *
 * @retval FSP_SUCCESS              Information has been written to p_info.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_B_InfoGet (transfer_ctrl_t * const p_api_ctrl, transfer_properties_t * const p_info)
{
    dmac_b_instance_ctrl_t * p_ctrl = (dmac_b_instance_ctrl_t *) p_api_ctrl;

#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_B_ID, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_info);
#endif

    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

    p_info->transfer_length_max = DMAC_B_MAX_NORMAL_TRANSFER_LENGTH;
    p_info->block_count_max     = DMAC_B_BLOCK_COUNT_MAX_LENGTH;

    p_info->block_count_remaining     = DMAC_B_MAX_BLOCK_TRANSFER_LENGTH;
    p_info->transfer_length_remaining = (p_ctrl->p_reg->GRP[group].CH[channel].CRTB);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable transfer and clean up internal data. Implements @ref transfer_api_t::close.
 *
 * @retval FSP_SUCCESS           Successful close.
 * @retval FSP_ERR_ASSERTION     An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN      Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_B_Close (transfer_ctrl_t * const p_api_ctrl)
{
    dmac_b_instance_ctrl_t * p_ctrl = (dmac_b_instance_ctrl_t *) p_api_ctrl;
#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_B_ID, FSP_ERR_NOT_OPEN);
#endif

    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

    /* Disable DMAC transfers on this channel. */
    R_BSP_DMAC_ACTIVATION_SOURCE_DISABLE(p_extend->unit, p_extend->channel);

    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_CLREN_Msk;
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.TACT, 0);

    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_SWRST_Msk;

    if (NULL != p_extend->p_callback)
    {
        R_BSP_IrqDisable(p_extend->dmac_int_irq);
        R_FSP_IsrContextSet(p_extend->dmac_int_irq, NULL);
    }

    /* Clear ID so control block can be reused. */
    p_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Make the following transfer settings to continue the transfer.
 *
 * @retval FSP_SUCCESS           Successful continuous transfer settings.
 * @retval FSP_ERR_ASSERTION     An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN      Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_B_Reload (transfer_ctrl_t * const p_api_ctrl,
                           void const * volatile   p_src,
                           void * volatile         p_dest,
                           uint32_t const          num_transfers)
{
    dmac_b_instance_ctrl_t * p_ctrl = (dmac_b_instance_ctrl_t *) p_api_ctrl;

    uint32_t * p_src_cast;
    uint32_t * p_dest_cast;

#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_B_ID, FSP_ERR_NOT_OPEN);
#endif

    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#elif  (BSP_FEATURE_BSP_SLAVE_ADDRESS_CONVERSION_SUPPORT)
    uint32_t original_addr;            /* Address before conversion */
    uint32_t converted_addr;           /* Address after conversion */
#endif

    if ((1 == p_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.EN) &&
        (0 == p_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.REN))
    {
        p_src_cast  = (uint32_t *) &p_src;
        p_dest_cast = (uint32_t *) &p_dest;
        if (0 == p_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.SR)
        {
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
            va = *p_src_cast;
            R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
            p_ctrl->p_reg->GRP[group].CH[channel].N[1].SA = (uint32_t) pa;

            va = *p_dest_cast;
            R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
            p_ctrl->p_reg->GRP[group].CH[channel].N[1].DA = (uint32_t) pa;
#elif (BSP_FEATURE_BSP_SLAVE_ADDRESS_CONVERSION_SUPPORT)
            original_addr  = *p_src_cast;
            converted_addr = R_BSP_SlaveAddressConversion(original_addr);
            p_ctrl->p_reg->GRP[group].CH[channel].N[1].SA = converted_addr;

            original_addr  = *p_dest_cast;
            converted_addr = R_BSP_SlaveAddressConversion(original_addr);
            p_ctrl->p_reg->GRP[group].CH[channel].N[1].DA = converted_addr;
#else
            p_ctrl->p_reg->GRP[group].CH[channel].N[1].SA = *p_src_cast;
            p_ctrl->p_reg->GRP[group].CH[channel].N[1].DA = *p_dest_cast;
#endif
            p_ctrl->p_reg->GRP[group].CH[channel].N[1].TB = num_transfers;
        }
        else
        {
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
            va = *p_src_cast;
            R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
            p_ctrl->p_reg->GRP[group].CH[channel].N[0].SA = (uint32_t) pa;

            va = *p_dest_cast;
            R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
            p_ctrl->p_reg->GRP[group].CH[channel].N[0].DA = (uint32_t) pa;
#elif (BSP_FEATURE_BSP_SLAVE_ADDRESS_CONVERSION_SUPPORT)
            original_addr  = *p_src_cast;
            converted_addr = R_BSP_SlaveAddressConversion(original_addr);
            p_ctrl->p_reg->GRP[group].CH[channel].N[0].SA = converted_addr;

            original_addr  = *p_dest_cast;
            converted_addr = R_BSP_SlaveAddressConversion(original_addr);
            p_ctrl->p_reg->GRP[group].CH[channel].N[0].DA = converted_addr;
#else
            p_ctrl->p_reg->GRP[group].CH[channel].N[0].SA = *p_src_cast;
            p_ctrl->p_reg->GRP[group].CH[channel].N[0].DA = *p_dest_cast;
#endif
            p_ctrl->p_reg->GRP[group].CH[channel].N[0].TB = num_transfers;
        }

        p_ctrl->p_reg->GRP[group].CH[channel].CHCFG |= R_DMAC_B0_GRP_CH_CHCFG_REN_Msk;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup DMAC_B)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable transfers for the channel.
 *
 * @param[in]  p_ctrl             Pointer to control structure.
 *
 * @retval     FSP_SUCCESS        Successful close.
 * @retval     FSP_ERR_ASSERTION  An input parameter is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_b_prv_enable (dmac_b_instance_ctrl_t * p_ctrl)
{
#if DMAC_B_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_dmac_b_enable_parameter_checking(p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

    if (DMAC_TRIGGER_EVENT_SOFTWARE_TRIGGER != p_extend->activation_source)
    {
        FSP_CRITICAL_SECTION_DEFINE;
        FSP_CRITICAL_SECTION_ENTER;

        /* DMAC trigger source set. */
        R_BSP_DMAC_ACTIVATION_SOURCE_ENABLE(p_extend->unit, p_extend->channel, p_extend->activation_source);

        FSP_CRITICAL_SECTION_EXIT;
    }

    if ((NULL != p_extend->p_callback) || (DMAC_TRIGGER_EVENT_SOFTWARE_TRIGGER == p_extend->activation_source))
    {
        /* Enable transfer end interrupt requests. */
        p_ctrl->p_reg->GRP[group].CH[channel].CHCFG &= ~((uint32_t) R_DMAC_B0_GRP_CH_CHCFG_DEM_Msk);

        /* Enable the IRQ in the GIC. */
        R_BSP_IrqCfgEnable(p_extend->dmac_int_irq, p_extend->dmac_int_ipl, p_ctrl);

        /* Set detect type of DMAC end interrupt */
        if (p_extend->dmac_int_irq >= 0)
        {
            R_BSP_DMAC_B_TRANSFER_END_DETECT_METHOD_SELECT(p_extend->unit, p_extend->channel, 1);
        }
    }
    else
    {
        /* Disable transfer end interrupt requests. */
        p_ctrl->p_reg->GRP[group].CH[channel].CHCFG |= R_DMAC_B0_GRP_CH_CHCFG_DEM_Msk;
    }

    /* Resets the channel status register. */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_SWRST_Msk;

    /* Enable transfer. */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_SETEN_Msk;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable transfers for the channel.
 *
 * @param      p_ctrl          Pointer to the control structure
 **********************************************************************************************************************/
static void r_dmac_b_prv_disable (dmac_b_instance_ctrl_t * p_ctrl)
{
    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

    /* Disable DMA transfer. */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_CLREN_Msk;

    /* Wait DMA stop */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.TACT, 0);

    /* Software Reset */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_SWRST_Msk;

    /* Disable DMAC transfers on this channel. */
    R_BSP_DMAC_ACTIVATION_SOURCE_DISABLE(p_extend->unit, p_extend->channel);

    /* Set DMA transfer end interrupt mask */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCFG |= R_DMAC_B0_GRP_CH_CHCFG_DEM_Msk;
}

/*******************************************************************************************************************//**
 * Write the transfer info to the hardware registers.
 *
 * @param[in]   p_ctrl         Pointer to control structure.
 * @param       p_info         Pointer to transfer info.
 **********************************************************************************************************************/
static void r_dmac_b_config_transfer_info (dmac_b_instance_ctrl_t * p_ctrl, transfer_info_t * p_info)
{
    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

    uint32_t * p_src_cast;
    uint32_t * p_dest_cast;

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#elif  (BSP_FEATURE_BSP_SLAVE_ADDRESS_CONVERSION_SUPPORT)
    uint32_t original_addr;            /* Address before conversion */
    uint32_t converted_addr;           /* Address after conversion */
#endif

    uint32_t dctrl = DMAC_B_PRV_DCTRL_DEFAULT_VALUE;
    uint32_t chcfg = DMAC_B_PRV_CHCFG_DEFAULT_VALUE;

    /* Disable transfers if they are currently enabled. */
    r_dmac_b_prv_disable(p_ctrl);

    /* Priority control select */
    dctrl |= ((p_extend->channel_scheduling) & DMAC_B_PRV_DCTRL_PR_VALUE_MASK) << R_DMAC_B0_GRP_DCTRL_PR_Pos;

    /* Configure channel */
    chcfg = ((p_extend->channel % 8 & DMAC_B_PRV_CHCFG_SEL_VALUE_MASK) << R_DMAC_B0_GRP_CH_CHCFG_SEL_Pos) |
            ((p_extend->activation_request_source_select & DMAC_B_PRV_CHCFG_REQD_VALUE_MASK) <<
             R_DMAC_B0_GRP_CH_CHCFG_REQD_Pos) |
            ((p_extend->internal_detection_mode & DMAC_B_PRV_CHCFG_DETECT_MODE_VALUE_MASK) << R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos) |
            ((p_extend->ack_mode & DMAC_B_PRV_CHCFG_AM_VALUE_MASK) << R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) |
            ((p_info->src_size & DMAC_B_PRV_CHCFG_SDS_VALUE_MASK) << R_DMAC_B0_GRP_CH_CHCFG_SDS_Pos) |
            ((p_info->dest_size & DMAC_B_PRV_CHCFG_DDS_VALUE_MASK) << R_DMAC_B0_GRP_CH_CHCFG_DDS_Pos) |
            ((p_info->src_addr_mode & DMAC_B_PRV_CHCFG_SAD_VALUE_MASK) << R_DMAC_B0_GRP_CH_CHCFG_SAD_Pos) |
            ((p_info->dest_addr_mode & DMAC_B_PRV_CHCFG_DAD_VALUE_MASK) << R_DMAC_B0_GRP_CH_CHCFG_DAD_Pos) |
            ((p_info->mode & DMAC_B_PRV_CHCFG_TM_VALUE_MASK) << R_DMAC_B0_GRP_CH_CHCFG_TM_Pos);

    R_BSP_DMAC_DREQ_DETECT_METHOD_SELECT(p_extend->external_detection_mode, p_extend->activation_source);

    if (DMAC_B_CONTINUOUS_SETTING_TRANSFER_ONCE != p_extend->continuous_setting)
    {
        /* Transfer end interrupt mask. */
        chcfg |= R_DMAC_B0_GRP_CH_CHCFG_DEM_Msk;

        /* Configure Register Set Reverse Select */
        chcfg |= ((p_extend->continuous_setting & DMAC_B_PRV_NEXT_REG_VALUE_MASK) << R_DMAC_B0_GRP_CH_CHCFG_RSW_Pos);
    }

    p_ctrl->p_reg->GRP[group].DCTRL = dctrl;

    p_src_cast  = (uint32_t *) &p_info->p_src;
    p_dest_cast = (uint32_t *) &p_info->p_dest;

    /* Next0 transfer setting. */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = *p_src_cast;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    p_ctrl->p_reg->GRP[group].CH[channel].N[0].SA = (uint32_t) pa;

    va = *p_dest_cast;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    p_ctrl->p_reg->GRP[group].CH[channel].N[0].DA = (uint32_t) pa;
#elif (BSP_FEATURE_BSP_SLAVE_ADDRESS_CONVERSION_SUPPORT)
    original_addr  = *p_src_cast;
    converted_addr = R_BSP_SlaveAddressConversion(original_addr);
    p_ctrl->p_reg->GRP[group].CH[channel].N[0].SA = converted_addr;

    original_addr  = *p_dest_cast;
    converted_addr = R_BSP_SlaveAddressConversion(original_addr);
    p_ctrl->p_reg->GRP[group].CH[channel].N[0].DA = converted_addr;
#else
    p_ctrl->p_reg->GRP[group].CH[channel].N[0].SA = *p_src_cast;
    p_ctrl->p_reg->GRP[group].CH[channel].N[0].DA = *p_dest_cast;
#endif

    p_ctrl->p_reg->GRP[group].CH[channel].N[0].TB = p_info->length;

    p_ctrl->p_reg->GRP[group].CH[channel].CHCFG  = chcfg;
    p_ctrl->p_reg->GRP[group].CH[channel].CHITVL = p_extend->transfer_interval;

    if (DMAC_B_CONTINUOUS_SETTING_TRANSFER_ONCE != p_extend->continuous_setting)
    {
        p_src_cast  = (uint32_t *) &p_info->p_next1_src;
        p_dest_cast = (uint32_t *) &p_info->p_next1_dest;

        /* Next1 transfer setting. */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        va = *p_src_cast;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        p_ctrl->p_reg->GRP[group].CH[channel].N[1].SA = (uint32_t) pa;

        va = *p_dest_cast;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        p_ctrl->p_reg->GRP[group].CH[channel].N[1].DA = (uint32_t) pa;
#elif (BSP_FEATURE_BSP_SLAVE_ADDRESS_CONVERSION_SUPPORT)
        original_addr  = *p_src_cast;
        converted_addr = R_BSP_SlaveAddressConversion(original_addr);
        p_ctrl->p_reg->GRP[group].CH[channel].N[1].SA = converted_addr;

        original_addr  = *p_dest_cast;
        converted_addr = R_BSP_SlaveAddressConversion(original_addr);
        p_ctrl->p_reg->GRP[group].CH[channel].N[1].DA = converted_addr;
#else
        p_ctrl->p_reg->GRP[group].CH[channel].N[1].SA = *p_src_cast;
        p_ctrl->p_reg->GRP[group].CH[channel].N[1].DA = *p_dest_cast;
#endif
        p_ctrl->p_reg->GRP[group].CH[channel].N[1].TB = p_info->next1_length;
    }
}

#if DMAC_B_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking of R_DMAC_B_Open.
 *
 * @param[in]   p_ctrl                    Pointer to control structure.
 * @param[in]   p_cfg                     Pointer to configuration structure. All elements of the structure must be
 *                                        set by user.
 *
 * @retval FSP_SUCCESS                    Input Parameters are Valid.
 * @retval FSP_ERR_ASSERTION              An input parameter is invalid.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The configured channel is invalid.
 * @retval FSP_ERR_IRQ_BSP_DISABLED       Callback is NULL and the DMAC IRQ is not enabled.
 * @retval FSP_ERR_ALREADY_OPEN           The control structure is already opened.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_b_open_parameter_checking (dmac_b_instance_ctrl_t * const p_ctrl,
                                                   transfer_cfg_t const * const   p_cfg)
{
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open != DMAC_B_ID, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_cfg->p_extend;
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(p_extend->channel < BSP_FEATURE_DMAC_MAX_CHANNEL, FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    if (DMAC_B_CONTINUOUS_SETTING_TRANSFER_ONCE != p_extend->continuous_setting)
    {
        FSP_ASSERT(NULL != p_cfg->p_info->p_next1_src);
        FSP_ASSERT(NULL != p_cfg->p_info->p_next1_dest);
        FSP_ASSERT(0 != p_cfg->p_info->next1_length);
    }

    if (NULL != p_extend->p_callback)
    {
        FSP_ERROR_RETURN(p_extend->dmac_int_irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
    }

    fsp_err_t err = r_dmac_b_info_paramter_checking(p_cfg->p_info);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

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
static fsp_err_t r_dmac_b_info_paramter_checking (transfer_info_t const * const p_info)
{
    FSP_ASSERT(p_info != NULL);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Parameter checking for r_dmac_b_prv_enable.
 *
 * @param[in]   p_ctrl                 Pointer to control structure.
 *
 * @retval      FSP_SUCCESS            Alignment on source and destination pointers is valid.
 * @retval      FSP_ERR_ASSERTION      The current configuration is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_b_enable_parameter_checking (dmac_b_instance_ctrl_t * const p_ctrl)
{
    dmac_b_extended_cfg_t * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

    uint32_t   * p_src_cast  = (uint32_t *) &p_ctrl->p_reg->GRP[group].CH[channel].N[1].SA;
    uint32_t   * p_dest_cast = (uint32_t *) &p_ctrl->p_reg->GRP[group].CH[channel].N[1].DA;
    void const * p_src       = (void const *) p_src_cast;
    void const * p_dest      = (void const *) p_dest_cast;

    /* The source and destination pointers cannot be NULL. */
    FSP_ASSERT(NULL != p_src);
    FSP_ASSERT(NULL != p_dest);

    if (1 == p_ctrl->p_reg->GRP[group].CH[channel].CHCFG_b.RSW)
    {
        void const * p_src_next1;
        void const * p_dest_next1;
        p_src_cast   = (uint32_t *) &p_ctrl->p_reg->GRP[group].CH[channel].N[1].SA;
        p_dest_cast  = (uint32_t *) &p_ctrl->p_reg->GRP[group].CH[channel].N[1].DA;
        p_src_next1  = (void const *) p_src_cast;
        p_dest_next1 = (void const *) p_dest_cast;

        /* The next1 register set source and destination pointers cannot be NULL. */
        FSP_ASSERT(NULL != p_src_next1);
        FSP_ASSERT(NULL != p_dest_next1);
    }

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * DMAC ISR
 **********************************************************************************************************************/
void dmac_b_int_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type                irq      = R_FSP_CurrentIrqGet();
    dmac_b_instance_ctrl_t * p_ctrl   = (dmac_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    dmac_b_extended_cfg_t  * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

    if (DMAC_TRIGGER_EVENT_SOFTWARE_TRIGGER != p_extend->activation_source)
    {
        /* Activation source disabled */
        if (1 != p_ctrl->p_reg->GRP[group].CH[channel].CHSTAT_b.EN)
        {
            R_BSP_DMAC_ACTIVATION_SOURCE_DISABLE(p_extend->unit, p_extend->channel);
        }
    }

    /* Clear the DREQ request status. */
    R_BSP_DMAC_DREQ_STATUS_CLEAR(p_extend->activation_source);

    /* Clear interrupt condition. */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL = R_DMAC_B0_GRP_CH_CHCTRL_CLREND_Msk;

    /* Dummy read to ensure that interrupt event is cleared. */
    volatile uint32_t dummy = p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL;
    FSP_PARAMETER_NOT_USED(dummy);

    /* Call user callback */
    if (NULL != p_extend->p_callback)
    {
        dmac_b_callback_args_t args;
        args.p_context = p_extend->p_context;
        args.event     = DMAC_B_EVENT_TRANSFER_END;
        p_extend->p_callback(&args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * DMAC ERR ISR
 **********************************************************************************************************************/
void dmac_b_err_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type                irq      = R_FSP_CurrentIrqGet();
    dmac_b_instance_ctrl_t * p_ctrl   = (dmac_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    dmac_b_extended_cfg_t  * p_extend = (dmac_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint8_t group   = DMAC_B_PRV_GROUP(p_extend->channel);
    uint8_t channel = DMAC_B_PRV_CHANNEL(p_extend->channel);

    /* Clear the error bit and software reset. */
    p_ctrl->p_reg->GRP[group].CH[channel].CHCTRL_b.SWRST = 1;

    /* Call user callback */
    dmac_b_callback_args_t args;
    args.p_context = p_extend->p_context;
    args.event     = DMAC_B_EVENT_TRANSFER_ERROR;
    p_extend->p_callback(&args);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
