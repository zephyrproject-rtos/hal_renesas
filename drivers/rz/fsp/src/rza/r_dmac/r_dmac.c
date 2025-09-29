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
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
 #include "hal_data.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Driver ID (DMAC in ASCII) */
#define DMAC_ID                                  (0x444d4143)

/** Byte limited to 2^32-1 byte */
#define DMAC_BLOCK_MAX_LENGTH                    (0xFFFFFFFF)
#define DMAC_BLOCK_COUNT_MAX_LENGTH              (0xFFFFFFFF)

#define DMAC_PRV_DCTRL_DEFAULT_VALUE             (0x00000000U)
#define DMAC_PRV_CHCFG_DEFAULT_VALUE             (0x00000000U)

/* Calculate the mask bits for byte alignment from the transfer_size_t. */
#define DMAC_PRV_MASK_ALIGN_N_BYTES(x)    ((1U << (x)) - 1U)
#define DMAC_PRV_MASK_ALIGN_4_BYTES              (0x2U)

/* Channel Configuration Register Bit Field Definitions */
#define DMAC_PRV_CHCFG_SEL_VALUE_MASK            (0x07U)
#define DMAC_PRV_CHCFG_REQD_VALUE_MASK           (0x01U)
#define DMAC_PRV_CHCFG_DETECT_MODE_VALUE_MASK    (0x07U)
#define DMAC_PRV_CHCFG_AM_VALUE_MASK             (0x07U)
#define DMAC_PRV_CHCFG_SDS_OFFSET                (12U)
#define DMAC_PRV_CHCFG_SDS_VALUE_MASK            (0x0FU)
#define DMAC_PRV_CHCFG_DDS_OFFSET                (16U)
#define DMAC_PRV_CHCFG_DDS_VALUE_MASK            (0x0FU)
#define DMAC_PRV_CHCFG_SAD_OFFSET                (20U)
#define DMAC_PRV_CHCFG_SAD_VALUE_MASK            (0x01U)
#define DMAC_PRV_CHCFG_DAD_OFFSET                (21U)
#define DMAC_PRV_CHCFG_DAD_VALUE_MASK            (0x01U)
#define DMAC_PRV_CHCFG_TM_VALUE_MASK             (0x02U)
#define DMAC_PRV_NEXT_REG_VALUE_MASK             (0x03U)

/* DMA Control Register Bit Field Definitions */
#define DMAC_PRV_DCTRL_PR_OFFSET                 (0U)
#define DMAC_PRV_DCTRL_PR_VALUE_MASK             (0x01U)

/* DMAC Resource Select Register Bit Field Definitions */
#define DMAC_PRV_DMARS_MID_RID_OFFSET            (16U)
#define DMAC_PRV_DMARS_MID_RID_MASK              (0x3FFU)
#define DMAC_PRV_ACTIVATION_SOURCE_VALUE_MASK    (0xFFFU)
#define DMAC_PRV_CHCFG_TM_VALUE_POS              (0x01U)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void dmac_int_isr(IRQn_Type const irq);
void dmac_err_isr(IRQn_Type const irq);

static fsp_err_t r_dmac_prv_enable(dmac_instance_ctrl_t * p_ctrl);
static void      r_dmac_prv_disable(dmac_instance_ctrl_t * p_ctrl);
static void      r_dmac_config_transfer_info_register_mode(dmac_instance_ctrl_t * p_ctrl, transfer_info_t * p_info);
static void      r_dmac_config_transfer_info_link_mode(dmac_instance_ctrl_t * p_ctrl);
static void      r_dmac_activation_trigger_enable(dmac_extended_cfg_t const * const p_extend);
static void      r_dmac_activation_trigger_disable(dmac_extended_cfg_t const * const p_extend);

#if DMAC_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_dma_open_parameter_checking(dmac_instance_ctrl_t * const p_ctrl, transfer_cfg_t const * const p_cfg);
static fsp_err_t r_dmac_reconfigure_parameter_checking(transfer_info_t const * const p_info);
static fsp_err_t r_dmac_enable_parameter_checking(dmac_instance_ctrl_t * const p_ctrl);
static fsp_err_t r_dmac_enable_parameter_checking_register_mode(dmac_instance_ctrl_t * const p_ctrl);
static fsp_err_t r_dmac_enable_parameter_checking_link_mode(dmac_instance_ctrl_t * const p_ctrl);
static fsp_err_t r_dmac_link_descriptor_parameter_checking(dmac_link_cfg_t const * p_descriptor);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
R_DMA_EX_Type  * p_reg_ex;
R_DMA0_7_Type  * p_reg0_7;
R_DMA8_15_Type * p_reg8_15;

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

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
    .close         = R_DMAC_Close,
    .reload        = R_DMAC_Reload,
    .callbackSet   = R_DMAC_CallbackSet,
};

/*******************************************************************************************************************//**
 * @addtogroup DMAC
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
fsp_err_t R_DMAC_Open (transfer_ctrl_t * const p_api_ctrl, transfer_cfg_t const * const p_cfg)
{
#if DMAC_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = FSP_SUCCESS;
    err = r_dma_open_parameter_checking(p_api_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    dmac_instance_ctrl_t * p_ctrl   = (dmac_instance_ctrl_t *) p_api_ctrl;
    dmac_extended_cfg_t  * p_extend = (dmac_extended_cfg_t *) p_cfg->p_extend;

    /* Calculate base address for registers on this channel. */
    uintptr_t base_address = (uintptr_t) R_DMA0_NS +
                             (p_extend->channel * ((uintptr_t) R_DMA1_NS - (uintptr_t) R_DMA0_NS));
    R_DMA0_Type * p_reg = (R_DMA0_Type *) base_address;
    p_reg_ex = R_DMA_EX_NS;
    if (p_extend->channel < 8)
    {
        p_reg0_7 = R_DMA0_7_NS;
    }
    else
    {
        p_reg8_15 = R_DMA8_15_NS;
    }

    p_ctrl->p_cfg = p_cfg;
    p_ctrl->p_reg = p_reg;

    /* Set callback and context pointers, if configured */
    p_ctrl->p_callback        = p_extend->p_callback;
    p_ctrl->p_context         = p_extend->p_context;
    p_ctrl->p_callback_memory = NULL;

    /* Supply clock to DMAC module. */
    R_BSP_MODULE_START(FSP_IP_DMAC_NS, p_extend->channel);

    /* Configure the transfer settings. */
    if (DMAC_MODE_SELECT_REGISTER == p_extend->dmac_mode)
    {
        r_dmac_config_transfer_info_register_mode(p_ctrl, p_cfg->p_info);
    }
    else if (DMAC_MODE_SELECT_LINK == p_extend->dmac_mode)
    {
        r_dmac_config_transfer_info_link_mode(p_ctrl);
    }
    else
    {
        /* Do nothing. */
    }

    /* Mark driver as open by initializing "DMAC" in its ASCII equivalent.*/
    p_ctrl->open = DMAC_ID;

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
fsp_err_t R_DMAC_Reconfigure (transfer_ctrl_t * const p_api_ctrl, transfer_info_t * p_info)
{
    fsp_err_t              err;
    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) p_api_ctrl;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
    err = r_dmac_reconfigure_parameter_checking(p_info);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(p_ctrl->p_cfg->p_extend != NULL);
    FSP_ASSERT(p_info->p_extend_info != NULL);
    dmac_extended_cfg_t  * p_extend      = (dmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;
    dmac_extended_info_t * p_extend_info = (dmac_extended_info_t *) p_info->p_extend_info;
    if (DMAC_CONTINUOUS_SETTING_TRANSFER_NEXT0_ONCE != p_extend->continuous_setting)
    {
        FSP_ASSERT(NULL != p_extend_info->p_next1_register_setting);
    }
#endif

    /* Reconfigure the transfer settings. */
    r_dmac_config_transfer_info_register_mode(p_ctrl, p_info);

    /* Enable the transfer configuration. */
    err = r_dmac_prv_enable(p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_NOT_ENABLED);

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
fsp_err_t R_DMAC_LinkDescriptorSet (transfer_ctrl_t * const p_api_ctrl, dmac_link_cfg_t * p_descriptor)
{
    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) p_api_ctrl;

    fsp_err_t err = FSP_SUCCESS;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(p_descriptor != NULL);
    err = r_dmac_link_descriptor_parameter_checking(p_descriptor);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_ctrl->p_reg->CHCFG_b.DMS == 1U, FSP_ERR_INVALID_MODE);
#endif

    /* Store current descriptor */
    p_ctrl->p_descriptor = p_descriptor;

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)

    /* Set address of the link destination */
    va = (uint64_t) p_descriptor;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    p_ctrl->p_reg->NXLA = (uint32_t) pa;
#else

    /* Set address of the link destination */
    p_ctrl->p_reg->NXLA = (uint32_t) p_descriptor;
#endif

    err = r_dmac_prv_enable(p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_NOT_ENABLED);

    /* Wait descriptor load */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->CHSTAT_b.DL, 0);

    return err;
}

/*******************************************************************************************************************//**
 * Reset transfer source, destination, and number of transfers.
 *
 * @retval FSP_ERR_UNSUPPORTED              API not supported.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Reset (transfer_ctrl_t * const p_api_ctrl,
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
fsp_err_t R_DMAC_SoftwareStart (transfer_ctrl_t * const p_api_ctrl, transfer_start_mode_t mode)
{
    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) p_api_ctrl;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
#endif

    FSP_PARAMETER_NOT_USED(mode);

    /* Set auto clear bit and software start bit. */
    p_ctrl->p_reg->CHCTRL = R_DMA_CHCTRL_STG_Msk;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stop software transfers if they were started with TRANSFER_START_MODE_REPEAT.
 *
 * @retval FSP_SUCCESS              Transfer stopped written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_SoftwareStop (transfer_ctrl_t * const p_api_ctrl)
{
    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) p_api_ctrl;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
#endif

    /* Set Suspend. */
    p_ctrl->p_reg->CHCTRL = R_DMA_CHCTRL_SETSUS_Msk;

    /* Transfer is already stopped. */
    if (1 != p_ctrl->p_reg->CHSTAT_b.EN)
    {
        /* Software Reset */
        p_ctrl->p_reg->CHCTRL = R_DMA_CHCTRL_SWRST_Msk;

        return FSP_SUCCESS;
    }

    /* Check whether a transfer is suspended. */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->CHSTAT_b.SUS, 1);

    /* Set clear enable and software stop bit. */
    p_ctrl->p_reg->CHCTRL = R_DMA_CHCTRL_CLREN_Msk;

    /* Check whether a transfer is stopped. */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->CHSTAT_b.TACT, 0);

    /* Software Reset */
    p_ctrl->p_reg->CHCTRL_b.SWRST = 1;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable transfers for the configured activation source.
 *
 * @retval FSP_SUCCESS              Counter value written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Enable (transfer_ctrl_t * const p_api_ctrl)
{
    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) p_api_ctrl;
#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
#endif

    return r_dmac_prv_enable(p_ctrl);
}

/*******************************************************************************************************************//**
 * Disable transfers so that they are no longer triggered by the activation source.
 *
 * @retval FSP_SUCCESS              Counter value written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Disable (transfer_ctrl_t * const p_api_ctrl)
{
    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) p_api_ctrl;
#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
#endif

    r_dmac_prv_disable(p_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set driver specific information in provided pointer.
 *
 * @retval FSP_SUCCESS              Information has been written to p_info.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_InfoGet (transfer_ctrl_t * const p_api_ctrl, transfer_properties_t * const p_info)
{
    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) p_api_ctrl;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_info);
#endif

    p_info->transfer_length_max = DMAC_MAX_NORMAL_TRANSFER_LENGTH;
    p_info->block_count_max     = DMAC_BLOCK_COUNT_MAX_LENGTH;

    p_info->block_count_remaining     = DMAC_MAX_BLOCK_TRANSFER_LENGTH;
    p_info->transfer_length_remaining = (p_ctrl->p_reg->CRTB);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable transfer and clean up internal data. Implements @ref transfer_api_t::close.
 *
 * @retval FSP_SUCCESS           Successful close.
 * @retval FSP_ERR_ASSERTION     An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN      Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Close (transfer_ctrl_t * const p_api_ctrl)
{
    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) p_api_ctrl;
#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
#endif

    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    /* Disable DMAC transfers on this channel. */
    r_dmac_activation_trigger_disable(p_extend);

    p_ctrl->p_reg->CHCTRL = R_DMA_CHCTRL_CLREN_Msk;
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->CHSTAT_b.TACT, 0);

    p_ctrl->p_reg->CHCTRL = R_DMA_CHCTRL_SWRST_Msk;

    if (p_extend->dmac_int_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->dmac_int_irq);
        R_FSP_IsrContextSet(p_extend->dmac_int_irq, NULL);
    }

    /* Clear ID so control block can be reused. */
    p_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Make the following transfer settings to continue the transfer. Implements @ref transfer_api_t::reload.
 *
 * @retval FSP_SUCCESS           Successful continuous transfer settings.
 * @retval FSP_ERR_ASSERTION     An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN      Handle is not initialized.  Call R_DMAC_Open to initialize the control block.
 * @retval FSP_ERR_INVALID_MODE  This API cannot be called during link mode operation or setting not to use the Next1 register.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_Reload (transfer_ctrl_t * const p_api_ctrl,
                         void const * volatile   p_src,
                         void * volatile         p_dest,
                         uint32_t const          num_transfers)
{
    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) p_api_ctrl;

    uint32_t * p_src_cast;
    uint32_t * p_dest_cast;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;
    FSP_ASSERT(NULL != p_extend);
    FSP_ERROR_RETURN(p_extend->dmac_mode == DMAC_MODE_SELECT_REGISTER, FSP_ERR_INVALID_MODE);
#endif

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    if ((1 == p_ctrl->p_reg->CHSTAT_b.EN) && (0 == p_ctrl->p_reg->CHCFG_b.REN))
    {
        p_src_cast  = (uint32_t *) p_src;
        p_dest_cast = (uint32_t *) p_dest;
        if (0 == p_ctrl->p_reg->CHSTAT_b.SR)
        {
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
            va = (uint64_t) p_src_cast;
            R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
            p_ctrl->p_reg->N1SA = (uint32_t) pa;

            va = (uint64_t) p_dest_cast;
            R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
            p_ctrl->p_reg->N1DA = (uint32_t) pa;
#else
            p_ctrl->p_reg->N1SA = p_src_cast;
            p_ctrl->p_reg->N1DA = p_dest_cast;
#endif
            p_ctrl->p_reg->N1TB = num_transfers;
        }
        else
        {
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
            va = (uint64_t) p_src_cast;
            R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
            p_ctrl->p_reg->N0SA = (uint32_t) pa;

            va = (uint64_t) p_dest_cast;
            R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
            p_ctrl->p_reg->N0DA = (uint32_t) pa;
#else
            p_ctrl->p_reg->N0SA = p_src_cast;
            p_ctrl->p_reg->N0DA = p_dest_cast;
#endif
            p_ctrl->p_reg->N0TB = num_transfers;
        }

        p_ctrl->p_reg->CHCFG |= R_DMA_CHCFG_REN_Msk;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_DMAC_CallbackSet (transfer_ctrl_t * const      p_api_ctrl,
                              void (                     * p_callback)(dmac_callback_args_t *),
                              void const * const           p_context,
                              dmac_callback_args_t * const p_callback_memory)
{
    FSP_PARAMETER_NOT_USED(p_callback_memory);

    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) p_api_ctrl;

#if DMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(p_ctrl->open == DMAC_ID, FSP_ERR_NOT_OPEN);
#endif

    p_ctrl->p_callback = p_callback;
    p_ctrl->p_context  = p_context;

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
 * @param[in]  p_ctrl             Pointer to control structure.
 *
 * @retval     FSP_SUCCESS        Successful close.
 * @retval     FSP_ERR_ASSERTION  An input parameter is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_prv_enable (dmac_instance_ctrl_t * p_ctrl)
{
#if DMAC_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_dmac_enable_parameter_checking(p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    if (p_extend->activation_source)
    {
        /* DMAC trigger source set. */
        r_dmac_activation_trigger_enable(p_extend);
    }

    if (p_extend->dmac_int_irq >= 0)
    {
        /* Enable transfer end interrupt requests. */
        p_ctrl->p_reg->CHCFG &= ~((uint32_t) R_DMA_CHCFG_DEM_Msk);

        /* Enable the IRQ in the GIC. */
        R_BSP_IrqCfgEnable(p_extend->dmac_int_irq, p_extend->dmac_int_ipl, p_ctrl);
    }
    else
    {
        /* Disable transfer end interrupt requests. */
        p_ctrl->p_reg->CHCFG |= R_DMA_CHCFG_DEM_Msk;
    }

    /* Resets the channel status register. */
    p_ctrl->p_reg->CHCTRL = R_DMA_CHCTRL_SWRST_Msk;

    /* Enable transfer. */
    p_ctrl->p_reg->CHCTRL = R_DMA_CHCTRL_SETEN_Msk;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable transfers for the channel.
 *
 * @param      p_ctrl          Pointer to the control structure
 **********************************************************************************************************************/
static void r_dmac_prv_disable (dmac_instance_ctrl_t * p_ctrl)
{
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    /* Disable DMA transfer. */
    p_ctrl->p_reg->CHCTRL = R_DMA_CHCTRL_CLREN_Msk;

    /* Wait DMA stop */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->CHSTAT_b.TACT, 0);

    /* Software Reset */
    p_ctrl->p_reg->CHCTRL = R_DMA_CHCTRL_SWRST_Msk;

    /* Disable DMAC transfers on this channel. */
    r_dmac_activation_trigger_disable(p_extend);

    /* Set DMA transfer end interrupt mask */
    p_ctrl->p_reg->CHCFG |= R_DMA_CHCFG_DEM_Msk;
}

/*******************************************************************************************************************//**
 * Write the transfer info to the hardware registers.
 *
 * @param[in]   p_ctrl         Pointer to control structure.
 * @param       p_info         Pointer to transfer info.
 **********************************************************************************************************************/
static void r_dmac_config_transfer_info_register_mode (dmac_instance_ctrl_t * p_ctrl, transfer_info_t * p_info)
{
    dmac_extended_cfg_t  * p_extend      = (dmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;
    dmac_extended_info_t * p_extend_info = (dmac_extended_info_t *) p_info->p_extend_info;

    uint32_t * p_src_cast;
    uint32_t * p_dest_cast;

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    uint32_t dctrl = DMAC_PRV_DCTRL_DEFAULT_VALUE;
    uint32_t chcfg = DMAC_PRV_CHCFG_DEFAULT_VALUE;

    /* Disable transfers if they are currently enabled. */
    r_dmac_prv_disable(p_ctrl);

    /* Priority control select */
    dctrl |= ((p_extend->channel_scheduling) & DMAC_PRV_DCTRL_PR_VALUE_MASK) << R_DMA_DCTRL_PR_Pos;

    /* Configure channel */
    chcfg = ((p_extend->channel % 8 & DMAC_PRV_CHCFG_SEL_VALUE_MASK) << R_DMA_CHCFG_SEL_Pos) |
            ((p_extend->activation_request_source_select & DMAC_PRV_CHCFG_REQD_VALUE_MASK) << R_DMA_CHCFG_REQD_Pos) |
            ((p_extend->detection_mode & DMAC_PRV_CHCFG_DETECT_MODE_VALUE_MASK) << R_DMA_CHCFG_LOEN_Pos) |
            ((p_extend->ack_mode & DMAC_PRV_CHCFG_AM_VALUE_MASK) << R_DMA_CHCFG_AM_Pos) |
            ((p_extend_info->src_size & DMAC_PRV_CHCFG_SDS_VALUE_MASK) << R_DMA_CHCFG_SDS_Pos) |
            ((p_extend_info->dest_size & DMAC_PRV_CHCFG_DDS_VALUE_MASK) << R_DMA_CHCFG_DDS_Pos) |
            (((p_info->transfer_settings_word_b.mode & DMAC_PRV_CHCFG_TM_VALUE_MASK) >> DMAC_PRV_CHCFG_TM_VALUE_POS) <<
             R_DMA_CHCFG_TM_Pos);
    if (0 == (p_info->transfer_settings_word_b.src_addr_mode & p_info->transfer_settings_word_b.dest_addr_mode))
    {
        /* src or dest address mode is "address fixed mode" */
        if (TRANSFER_ADDR_MODE_FIXED == p_info->transfer_settings_word_b.src_addr_mode)
        {
            chcfg |= DMAC_PRV_CHCFG_SAD_VALUE_MASK << R_DMA_CHCFG_SAD_Pos;
        }

        if (TRANSFER_ADDR_MODE_FIXED == p_info->transfer_settings_word_b.dest_addr_mode)
        {
            chcfg |= DMAC_PRV_CHCFG_DAD_VALUE_MASK << R_DMA_CHCFG_DAD_Pos;
        }
    }

    if (DMAC_CONTINUOUS_SETTING_TRANSFER_NEXT0_ONCE != p_extend->continuous_setting)
    {
        /* Transfer end interrupt mask. */
        chcfg |= R_DMA_CHCFG_DEM_Msk;

        /* Configure Register Set Reverse Select */
        chcfg |= ((p_extend->continuous_setting & DMAC_PRV_NEXT_REG_VALUE_MASK) << R_DMA_CHCFG_RSW_Pos);
    }

    if (p_extend->channel < 8)
    {
        p_reg0_7->DCTRL = dctrl;
    }
    else
    {
        p_reg8_15->DCTRL = dctrl;
    }

    p_src_cast  = (uint32_t *) &p_info->p_src;
    p_dest_cast = (uint32_t *) &p_info->p_dest;

    /* Next0 transfer setting. */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = *p_src_cast;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    p_ctrl->p_reg->N0SA = (uint32_t) pa;

    va = *p_dest_cast;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    p_ctrl->p_reg->N0DA = (uint32_t) pa;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
    p_ctrl->p_reg->N0SA = *p_src_cast;
    p_ctrl->p_reg->N0DA = *p_dest_cast;
#endif

    p_ctrl->p_reg->N0TB = p_info->length;

    p_ctrl->p_reg->CHCFG  = chcfg;
    p_ctrl->p_reg->CHITVL = p_extend->transfer_interval;

    if (DMAC_CONTINUOUS_SETTING_TRANSFER_NEXT0_ONCE != p_extend->continuous_setting)
    {
        dmac_next1_register_setting_t * p_next1_register = p_extend_info->p_next1_register_setting;

        p_src_cast  = (uint32_t *) &p_next1_register->p_src;
        p_dest_cast = (uint32_t *) &p_next1_register->p_dest;

        /* Next1 transfer setting. */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        va = *p_src_cast;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        p_ctrl->p_reg->N1SA = (uint32_t) pa;

        va = *p_dest_cast;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        p_ctrl->p_reg->N1DA = (uint32_t) pa;
#else
        p_ctrl->p_reg->N1SA = *p_src_cast;
        p_ctrl->p_reg->N1DA = *p_dest_cast;
#endif
        p_ctrl->p_reg->N1TB = p_next1_register->length;
    }
}

/*******************************************************************************************************************//**
 * Set the hardware registers for link mode operation.
 *
 * @param[in]   p_ctrl         Pointer to control structure.
 **********************************************************************************************************************/
static void r_dmac_config_transfer_info_link_mode (dmac_instance_ctrl_t * p_ctrl)
{
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    uint32_t dctrl = DMAC_PRV_DCTRL_DEFAULT_VALUE;

    /* Disable transfers if they are currently enabled. */
    r_dmac_prv_disable(p_ctrl);

    /* Priority control select */
    dctrl |= ((p_extend->channel_scheduling) & DMAC_PRV_DCTRL_PR_VALUE_MASK) << DMAC_PRV_DCTRL_PR_OFFSET;

    if (p_extend->channel < 8)
    {
        p_reg0_7->DCTRL = dctrl;
    }
    else
    {
        p_reg8_15->DCTRL = dctrl;
    }

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)

    /* Set address of the link destination */
    va = (uint64_t) (p_extend->p_descriptor);
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    p_ctrl->p_reg->NXLA = (uint32_t) pa;
#else

    /* Set address of the link destination */
    p_ctrl->p_reg->NXLA = (uint32_t) (p_extend->p_descriptor);
#endif

    /* Store current descriptor. */
    p_ctrl->p_descriptor = p_extend->p_descriptor;

    /* Set link mode */
    p_ctrl->p_reg->CHCFG_b.DMS = 1U;
}

#if DMAC_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking of R_DMAC_Open.
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
static fsp_err_t r_dma_open_parameter_checking (dmac_instance_ctrl_t * const p_ctrl, transfer_cfg_t const * const p_cfg)
{
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open != DMAC_ID, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    dmac_extended_cfg_t  * p_extend      = (dmac_extended_cfg_t *) p_cfg->p_extend;
    dmac_extended_info_t * p_extend_info = (dmac_extended_info_t *) p_cfg->p_info->p_extend_info;
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(p_extend->channel < BSP_FEATURE_DMAC_MAX_CHANNEL, FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    if (DMAC_CONTINUOUS_SETTING_TRANSFER_NEXT0_ONCE != p_extend->continuous_setting)
    {
        FSP_ASSERT(NULL != p_extend_info->p_next1_register_setting);
    }

    if (NULL != p_extend->p_callback)
    {
        FSP_ERROR_RETURN(p_extend->dmac_int_irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
    }

    fsp_err_t err = r_dmac_reconfigure_parameter_checking(p_cfg->p_info);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    if (DMAC_MODE_SELECT_LINK == p_extend->dmac_mode)
    {
        if (NULL != p_extend->p_descriptor)
        {
            err = r_dmac_link_descriptor_parameter_checking(p_extend->p_descriptor);
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
static fsp_err_t r_dmac_reconfigure_parameter_checking (transfer_info_t const * const p_info)
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
static fsp_err_t r_dmac_link_descriptor_parameter_checking (dmac_link_cfg_t const * p_descriptor)
{
    dmac_link_cfg_t const * p_current_descriptor = p_descriptor;

    do
    {
        /* Start address of the link destination must be 4 byte align.
         * (See section 'Next Link Address Register n (NXLA_n)' of the RZ microprocessor manual) */
        FSP_ASSERT(0U == ((uintptr_t) p_current_descriptor & DMAC_PRV_MASK_ALIGN_N_BYTES(DMAC_PRV_MASK_ALIGN_4_BYTES)));

        if (DMAC_LINK_END_ENABLE == p_current_descriptor->header.link_end)
        {
            break;
        }

 #if (BSP_FEATURE_DMAC_64BIT_SYSTEM == 1)
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
 * @param[in]   p_ctrl                 Pointer to control structure.
 *
 * @retval      FSP_SUCCESS            Alignment on source and destination pointers is valid.
 * @retval      FSP_ERR_ASSERTION      The current configuration is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_enable_parameter_checking (dmac_instance_ctrl_t * const p_ctrl)
{
    dmac_extended_cfg_t * p_extend = (dmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;
    FSP_ASSERT(p_extend != NULL);

    fsp_err_t err = FSP_SUCCESS;
    if (DMAC_MODE_SELECT_REGISTER == p_extend->dmac_mode)
    {
        err = r_dmac_enable_parameter_checking_register_mode(p_ctrl);
    }
    else if (DMAC_MODE_SELECT_LINK == p_extend->dmac_mode)
    {
        err = r_dmac_enable_parameter_checking_link_mode(p_ctrl);
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
 * @param[in]   p_ctrl                 Pointer to control structure.
 *
 * @retval      FSP_SUCCESS            Alignment on source and destination pointers is valid.
 * @retval      FSP_ERR_ASSERTION      The current configuration is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_enable_parameter_checking_register_mode (dmac_instance_ctrl_t * const p_ctrl)
{
    uint32_t   * p_src_cast  = (uint32_t *) &p_ctrl->p_reg->N0SA;
    uint32_t   * p_dest_cast = (uint32_t *) &p_ctrl->p_reg->N0DA;
    void const * p_src       = (void const *) p_src_cast;
    void const * p_dest      = (void const *) p_dest_cast;

    /* The source and destination pointers cannot be NULL. */
    FSP_ASSERT(NULL != p_src);
    FSP_ASSERT(NULL != p_dest);

    if (1 == p_ctrl->p_reg->CHCFG_b.RSW)
    {
        void const * p_src_next1;
        void const * p_dest_next1;
        p_src_cast   = (uint32_t *) &p_ctrl->p_reg->N1SA;
        p_dest_cast  = (uint32_t *) &p_ctrl->p_reg->N1DA;
        p_src_next1  = (void const *) p_src_cast;
        p_dest_next1 = (void const *) p_dest_cast;

        /* The next1 register set source and destination pointers cannot be NULL. */
        FSP_ASSERT(NULL != p_src_next1);
        FSP_ASSERT(NULL != p_dest_next1);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Parameter checking for r_dmac_prv_enable at link mode operation.
 *
 * @param[in]   p_ctrl                 Pointer to control structure.
 *
 * @retval      FSP_SUCCESS            Alignment on source and destination pointers is valid.
 * @retval      FSP_ERR_ASSERTION      The current configuration is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_dmac_enable_parameter_checking_link_mode (dmac_instance_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_ASSERT(NULL != p_ctrl->p_descriptor);

    return FSP_SUCCESS;
}

#endif

static void r_dmac_activation_trigger_enable (dmac_extended_cfg_t const * const p_extend)
{
    if ((0 == p_extend->channel) || (1 == p_extend->channel))
    {
        p_reg_ex->DMARS0 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
        p_reg_ex->DMARS0 |=
            (uint32_t) ((p_extend->activation_source & DMAC_PRV_ACTIVATION_SOURCE_VALUE_MASK) <<
                        (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((2 == p_extend->channel) || (3 == p_extend->channel))
    {
        p_reg_ex->DMARS1 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
        p_reg_ex->DMARS1 |=
            (uint32_t) ((p_extend->activation_source & DMAC_PRV_ACTIVATION_SOURCE_VALUE_MASK) <<
                        (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((4 == p_extend->channel) || (5 == p_extend->channel))
    {
        p_reg_ex->DMARS2 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
        p_reg_ex->DMARS2 |=
            (uint32_t) ((p_extend->activation_source & DMAC_PRV_ACTIVATION_SOURCE_VALUE_MASK) <<
                        (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((6 == p_extend->channel) || (7 == p_extend->channel))
    {
        p_reg_ex->DMARS3 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
        p_reg_ex->DMARS3 |=
            (uint32_t) ((p_extend->activation_source & DMAC_PRV_ACTIVATION_SOURCE_VALUE_MASK) <<
                        (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((8 == p_extend->channel) || (9 == p_extend->channel))
    {
        p_reg_ex->DMARS4 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
        p_reg_ex->DMARS4 |=
            (uint32_t) ((p_extend->activation_source & DMAC_PRV_ACTIVATION_SOURCE_VALUE_MASK) <<
                        (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((10 == p_extend->channel) || (11 == p_extend->channel))
    {
        p_reg_ex->DMARS5 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
        p_reg_ex->DMARS5 |=
            (uint32_t) ((p_extend->activation_source & DMAC_PRV_ACTIVATION_SOURCE_VALUE_MASK) <<
                        (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((12 == p_extend->channel) || (13 == p_extend->channel))
    {
        p_reg_ex->DMARS6 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
        p_reg_ex->DMARS6 |=
            (uint32_t) ((p_extend->activation_source & DMAC_PRV_ACTIVATION_SOURCE_VALUE_MASK) <<
                        (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else
    {
        p_reg_ex->DMARS7 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
        p_reg_ex->DMARS7 |=
            (uint32_t) ((p_extend->activation_source & DMAC_PRV_ACTIVATION_SOURCE_VALUE_MASK) <<
                        (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
}

static void r_dmac_activation_trigger_disable (dmac_extended_cfg_t const * const p_extend)
{
    if ((0 == p_extend->channel) || (1 == p_extend->channel))
    {
        p_reg_ex->DMARS0 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((2 == p_extend->channel) || (3 == p_extend->channel))
    {
        p_reg_ex->DMARS1 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((4 == p_extend->channel) || (5 == p_extend->channel))
    {
        p_reg_ex->DMARS2 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((6 == p_extend->channel) || (7 == p_extend->channel))
    {
        p_reg_ex->DMARS3 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((8 == p_extend->channel) || (9 == p_extend->channel))
    {
        p_reg_ex->DMARS4 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((10 == p_extend->channel) || (11 == p_extend->channel))
    {
        p_reg_ex->DMARS5 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else if ((12 == p_extend->channel) || (13 == p_extend->channel))
    {
        p_reg_ex->DMARS6 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
    else
    {
        p_reg_ex->DMARS7 &=
            (uint32_t) ~(DMAC_PRV_DMARS_MID_RID_MASK << (DMAC_PRV_DMARS_MID_RID_OFFSET * (p_extend->channel % 2)));
    }
}

/*******************************************************************************************************************//**
 * DMAC ISR
 **********************************************************************************************************************/
void dmac_int_isr (IRQn_Type const irq)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    dmac_instance_ctrl_t * p_ctrl   = (dmac_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    dmac_extended_cfg_t  * p_extend = (dmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    if (p_extend->activation_source)
    {
        /* Activation source disabled */
        if (1 != p_ctrl->p_reg->CHSTAT_b.EN)
        {
            r_dmac_activation_trigger_disable(p_extend);
        }
    }

    /* Call the callback routine if one is available */
    if (NULL != p_ctrl->p_callback)
    {
        dmac_callback_args_t args;
        args.p_context = p_ctrl->p_context;
        p_ctrl->p_callback(&args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * DMAC ERR ISR
 **********************************************************************************************************************/
void dmac_err_isr (IRQn_Type const irq)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    dmac_instance_ctrl_t * p_ctrl = (dmac_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Clear the error bit and software reset. */
    p_ctrl->p_reg->CHCTRL_b.SWRST = 1;

    /* Call user callback */
    if (NULL != p_ctrl->p_callback)
    {
        dmac_callback_args_t args;
        args.p_context = p_ctrl->p_context;
        p_ctrl->p_callback(&args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
