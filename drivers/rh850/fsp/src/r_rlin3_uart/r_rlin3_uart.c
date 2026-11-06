/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rlin3_uart.h"              /* PRQA S 0380 # DP_MSR_D-1.1_C99 & DP_MSR_D-1.1_C11 */
#include <string.h>

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define RLIN3_UART_OPEN                                (0x524C4E33U)
#define BSP_FEATURE_RLIN323_CHANNEL                    (23U)
#define RLIN3_UART_MAX_READ_WRITE                      (0xFFFFFFFFU)
#define RLIN3_UART_MAX_CLKDIV_SEL                      (8U)
#define RLIN3_UART_MAX_BITSAMPLING                     (16U)
#define RLIN3_UART_MIN_BITSAMPLING                     (5U)
#define RLIN3_UART_MAX_BAUDRATE_PRESCALER              (0xFFFFU)
#define RLIN3_UART_ALIGN_2_BYTES                       (0x01U)
#define RLIN3_UART_DATA_2_BYTES                        (2U)
#define RLIN3_UART_DATA_2_BYTES_MASK                   (0x11U)
#define RLIN3_UART_CLEAR_ERR_REG_MASK                  (0x82U)
#define RLIN3_RESET_MODE                               (0U)
#define RLIN3_UART_MODE                                (1U)
#define RLIN3_UART_ENABLE_EXPANSION_BIT_COMPARISION    (0x07U)
#define RLIN3_UART_ENABLE_EXPANSION_BIT                (0x03U)
#define RLIN3_UART_TX_ENABLE                           (0x1U)
#define RLIN3_UART_RX_ENABLE                           (0x2U)
#define RLIN3_UART_TX_RX_ENABLE                        (0x3U)
#define RLIN3_UART_NUM_TRANSFER_RESET                  (0U)
#define RLIN3_UART_PAIR_SIZE                           (2U)

/* Offset between RLIN3 register groups (even 32-30, odd 33-31) */
#define RLIN3_REG_SIZE(channel)    (((R_RLN32_BASE - R_RLN30_BASE) *      \
                                     (!(channel % RLIN3_UART_PAIR_SIZE))) \
                                    +                                     \
                                    ((R_RLN33_BASE - R_RLN31_BASE) *      \
                                     ((channel % RLIN3_UART_PAIR_SIZE))))

/* Gap between two UART channels in the same RLIN3 group */
#define RLIN3_REG_GROUP_GAP    (R_RLN31_BASE - R_RLN30_BASE)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void      r_rlin3_uart_config_set(rlin3_uart_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg);
static void      r_rlin3_uart_baud_set(R_RLN30_Type * p_rlin3_reg, baud_setting_t const * const p_baud_setting);
static void      r_rlin3_uart_buffer_transmission(rlin3_uart_instance_ctrl_t * const p_ctrl, uint8_t buffer_size);
static void      r_rlin3_uart_call_callback(rlin3_uart_instance_ctrl_t * p_ctrl, uint32_t data, uart_event_t event);
static fsp_err_t r_rlin3_uart_baudcalculate(rlin3_uart_instance_ctrl_t * const p_ctrl,
                                            baud_setting_t * const             p_baud_setting);

#if (R_RLIN3_UART_CFG_TRANSFER_SUPPORT_ENABLE)
void             rlin3_uart_txi_transfer_callback(transfer_callback_args_t * p_args);
void             rlin3_uart_rxi_transfer_callback(transfer_callback_args_t * p_args);
static fsp_err_t r_rlin3_uart_transfer_open(rlin3_uart_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg);

static fsp_err_t r_rlin3_uart_transfer_transmit_configure(rlin3_uart_instance_ctrl_t * const p_ctrl,
                                                          transfer_instance_t const        * p_transfer,
                                                          uart_cfg_t const * const           p_cfg);

static fsp_err_t r_rlin3_uart_transfer_receive_configure(rlin3_uart_instance_ctrl_t * const p_ctrl,
                                                         transfer_instance_t const        * p_transfer,
                                                         uart_cfg_t const * const           p_cfg);

#endif

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
static fsp_err_t r_rlin3_uart_read_write_param_check(rlin3_uart_instance_ctrl_t const * const p_ctrl,
                                                     uint8_t const * const                    addr,
                                                     uint32_t const                           bytes);

#endif
BSP_INTERRUPT_ATTRIBUTE void rlin3_uart_txi_isr(void);             /* PRQA S 3451, 3449 # DP_MSR_R-8.5_UC1 */
BSP_INTERRUPT_ATTRIBUTE void rlin3_uart_rxi_isr(void);             /* PRQA S 3451, 3449 # DP_MSR_R-8.5_UC1 */
BSP_INTERRUPT_ATTRIBUTE void rlin3_uart_eri_isr(void);             /* PRQA S 3451, 3449 # DP_MSR_R-8.5_UC1 */

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
static const uint32_t UART_MAX_BAUD_RATE_ERROR_X_1000 = 15000;     /* PRQA S 3218 # DP_MSR_R-8.9_UC1 */
#endif
static const int32_t  UART_100_PERCENT_X_1000 = 100000;            /* PRQA S 3218 # DP_MSR_R-8.9_UC1 */
static const int32_t  UART_PERCENT_X_1000     = 1000;              /* PRQA S 3218 # DP_MSR_R-8.9_UC1 */
static const uint16_t clock_prescaler[RLIN3_UART_MAX_CLKDIV_SEL] = /* PRQA S 3218 # DP_MSR_R-8.9_UC1 */
{
    1U,
    2U,
    4U,
    8U,
    16U,
    32U,
    64U,
    128U,
};

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/
const uart_api_t g_uart_on_rlin3 =                     /* PRQA S 1502 # DP_MSR_R-2.8_UC1 */
{
    .open               = R_RLIN3_UART_Open,           /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
    .read               = R_RLIN3_UART_Read,           /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
    .write              = R_RLIN3_UART_Write,          /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
    .baudSet            = R_RLIN3_UART_BaudSet,        /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
    .infoGet            = R_RLIN3_UART_InfoGet,        /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
    .communicationAbort = R_RLIN3_UART_Abort,          /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
    .callbackSet        = R_RLIN3_UART_CallbackSet,    /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
    .close              = R_RLIN3_UART_Close,          /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
    .readStop           = R_RLIN3_UART_ReadStop,       /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
    .receiveSuspend     = R_RLIN3_UART_ReceiveSuspend, /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
    .receiveResume      = R_RLIN3_UART_ReceiveResume,  /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
};

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup RLIN3_UART
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configures the UART driver based on the input configurations.  If reception is enabled at compile time, reception is
 * enabled at the end of this function. Implements @ref uart_api_t::open
 *
 *
 * @retval  FSP_SUCCESS                    Channel opened successfully.
 * @retval  FSP_ERR_ASSERTION              Pointer to UART control block or configuration structure is NULL.
 * @retval  FSP_ERR_ALREADY_OPEN           Control block has already been opened or channel is being used by another
 *                                         instance. Call close() then open() to reconfigure.
 **********************************************************************************************************************/
fsp_err_t R_RLIN3_UART_Open (uart_ctrl_t * const p_api_ctrl, uart_cfg_t const * const p_cfg) /* PRQA S 1505 # DP_MSR_R-8.7_UC1 */
{
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl;         /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters. */
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_cfg);
    FSP_ASSERT(p_cfg->p_callback);                                                          /* PRQA S 3344 # DP_MSR_R-14.4_UC1 */
    FSP_ASSERT(p_cfg->p_extend);
    FSP_ASSERT(((rlin3_uart_extended_cfg_t *) p_cfg->p_extend)->p_baud_setting);            /* PRQA S 0311, 0316 # DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1 */
    FSP_ERROR_RETURN(RLIN3_UART_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    rlin3_uart_extended_cfg_t * p_extend = ((rlin3_uart_extended_cfg_t *) p_cfg->p_extend); /* PRQA S 0310, 0311, 0316, 3678 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1, DP_MSR_R-8.13_UC1 */

    /* Initialize control block */
#if (BSP_FEATURE_RLIN3_RLIN323_HAS_PBUS_GROUP_8L)
    if (BSP_FEATURE_RLIN323_CHANNEL == p_cfg->channel)
    {
        p_ctrl->p_reg = (R_RLN30_Type *) (R_RLN323_BASE); /* PRQA S 0306 # DP_MSR_R-11.4_UC1 */
    }
    else
#endif
    {
        p_ctrl->p_reg =
            ((R_RLN30_Type *) (R_RLN30_BASE + (RLIN3_REG_GROUP_GAP * (p_cfg->channel % RLIN3_UART_PAIR_SIZE)) + /* PRQA S 1891, 3432, 0306 # DP_MSR_R-10.7_UC1, DP_MSR_R-20.7_UC1, DP_MSR_R-11.4_UC1 */
                               (RLIN3_REG_SIZE(p_cfg->channel) * (p_cfg->channel / RLIN3_UART_PAIR_SIZE))));    /* PRQA S 1891, 4501, 4558, 3432 # DP_MSR_R-10.7_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-20.7_UC1 */
    }

    p_ctrl->p_cfg             = p_cfg;
    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;
    p_ctrl->rx_suspended      = false;

    p_ctrl->data_bytes = 1U;
    if (UART_DATA_BITS_9 == p_cfg->data_bits)
    {
        p_ctrl->data_bytes = RLIN3_UART_DATA_2_BYTES;
    }

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_TX))
    {
        R_BSP_IrqDisable(p_cfg->txi_irq);
    }

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_RX))
    {
        R_BSP_IrqDisable(p_cfg->rxi_irq);
        R_BSP_IrqDisable(p_cfg->eri_irq);
    }

    p_ctrl->p_reg->LCUC = RLIN3_RESET_MODE;                            /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->LMST, RLIN3_RESET_MODE); /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */

    r_rlin3_uart_config_set(p_ctrl, p_cfg);

#if (R_RLIN3_UART_CFG_TRANSFER_SUPPORT_ENABLE)

    /* Configure the transfer interface for transmission and reception if provided. */
    fsp_err_t err = r_rlin3_uart_transfer_open(p_ctrl, p_cfg);

    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    p_ctrl->p_tx_src      = NULL;
    p_ctrl->tx_src_bytes  = 0U;
    p_ctrl->p_rx_dest     = NULL;
    p_ctrl->rx_dest_bytes = 0U;

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_TX))
    {
        R_BSP_IrqCfgEnable(p_ctrl->p_cfg->txi_irq, p_ctrl->p_cfg->txi_ipl, p_ctrl);
    }

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_RX))
    {
        R_BSP_IrqCfgEnable(p_ctrl->p_cfg->rxi_irq, p_ctrl->p_cfg->rxi_ipl, p_ctrl);
        R_BSP_IrqCfgEnable(p_ctrl->p_cfg->eri_irq, p_ctrl->p_cfg->eri_ipl, p_ctrl);
    }

#if (BSP_FEATURE_DEVICE_HAS_INTSEL_IRQ)
    if (BSP_INTSEL_DISABLED != p_extend->intsel_irq_cfg) /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
    {
        R_BSP_IntSel_CfgEnable(p_extend->intsel_irq_cfg);
    }
#endif

    /* Check if interrupt select is selected*/
    p_ctrl->open = RLIN3_UART_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provides the driver information, including the maximum number of bytes that can be received or transmitted at a time.
 * Implements @ref uart_api_t::infoGet
 *
 * @retval  FSP_SUCCESS                  Information stored in provided p_info.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_RLIN3_UART_InfoGet (uart_ctrl_t * const p_api_ctrl, uart_info_t * const p_info) /* PRQA S 3673, 1505 # DP_MSR_R-8.13_UC1, DP_MSR_R-8.7_UC1 */
{
#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl;        /* PRQA S 0310, 0311, 0316, 3678 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1, DP_MSR_R-8.13_UC1 */
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_info);
    FSP_ERROR_RETURN(RLIN3_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    p_info->read_bytes_max  = RLIN3_UART_MAX_READ_WRITE;
    p_info->write_bytes_max = RLIN3_UART_MAX_READ_WRITE;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Aborts any in progress transfers. Disables interrupts, receiver, and transmitter.  Closes lower level transfer
 * drivers if used. Removes power. Implements @ref uart_api_t::close
 *
 * @retval  FSP_SUCCESS              Channel successfully closed.
 * @retval  FSP_ERR_ASSERTION        Pointer to UART control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN         The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_RLIN3_UART_Close (uart_ctrl_t * const p_api_ctrl)                        /* PRQA S 1505 # DP_MSR_R-8.7_UC1 */
{
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl; /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(RLIN3_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    rlin3_uart_extended_cfg_t * p_extend = ((rlin3_uart_extended_cfg_t *) p_ctrl->p_cfg->p_extend); /* PRQA S 0310, 0311, 0316, 3678 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1, DP_MSR_R-8.13_UC1 */

    p_ctrl->p_reg->LUOER = 0x00U;                                                                   /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_TX))
    {
#if BSP_FEATURE_DEVICE_HAS_INTSEL_IRQ
        if (BSP_INTSEL_DISABLED != p_extend->intsel_irq_cfg) /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
        {
            R_BSP_IntSel_CfgDisable(p_extend->intsel_irq_cfg);
        }
#endif
        R_BSP_IrqDisable(p_ctrl->p_cfg->txi_irq);
    }

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_RX))
    {
        R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);
        R_BSP_IrqDisable(p_ctrl->p_cfg->eri_irq);
    }

#if (R_RLIN3_UART_CFG_TRANSFER_SUPPORT_ENABLE)
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        p_ctrl->p_cfg->p_transfer_rx->p_api->disable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
        p_ctrl->p_cfg->p_transfer_rx->p_api->close(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
    }

    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        p_ctrl->p_cfg->p_transfer_tx->p_api->disable(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);
        p_ctrl->p_cfg->p_transfer_tx->p_api->close(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);
    }
#endif

    p_ctrl->rx_suspended = false;
    p_ctrl->open         = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the baud rate using the clock selected in Open. p_baud_setting is a pointer to a baud_setting_t structure.
 * Implements @ref uart_api_t::baudSet
 *
 * @warning This terminates any in-progress transmission.
 *
 * @retval  FSP_SUCCESS                  Baud rate was successfully changed.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART control block is NULL or the UART is not configured to use the
 *                                       internal clock.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_RLIN3_UART_BaudSet (uart_ctrl_t * const p_api_ctrl, void const * const p_baud_setting) /* PRQA S 1505 # DP_MSR_R-8.7_UC1 */
{
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl;               /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(RLIN3_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    rlin3_uart_extended_cfg_t const * p_extend = (rlin3_uart_extended_cfg_t const *) p_ctrl->p_cfg->p_extend; /* PRQA S 0310, 0311, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1 */

    fsp_err_t              err              = FSP_SUCCESS;
    baud_setting_t const * p_baud_input     = (baud_setting_t const *) p_baud_setting;                        /* PRQA S 0316 # DP_MSR_R-11.5_UC1 */
    baud_setting_t         p_baud_calculate = *p_baud_input;

    /* Save registers that have been reset in LIN Reset Mode */
    uint8_t pre_ltrc  = (uint8_t) p_ctrl->p_reg->LTRC;                                                        /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    uint8_t pre_luoer = (uint8_t) p_ctrl->p_reg->LUOER;                                                       /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */

    /* Checking baud rate calculate enable*/
    if (RLIN3_UART_BAUD_RATE_CALCULATION_ENABLE == p_extend->baud_calculate)
    {
        err = r_rlin3_uart_baudcalculate(p_ctrl, &p_baud_calculate);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    p_ctrl->p_reg->LCUC = RLIN3_RESET_MODE;                            /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->LMST, RLIN3_RESET_MODE); /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    r_rlin3_uart_baud_set(p_ctrl->p_reg, &p_baud_calculate);

    p_ctrl->p_reg->LCUC = RLIN3_UART_MODE;                             /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->LMST, RLIN3_UART_MODE);  /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */

    /* Restore saved register */
    p_ctrl->p_reg->LUOER = pre_luoer;                                  /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    p_ctrl->p_reg->LTRC  = pre_ltrc;                                   /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Receives user specified number of bytes into destination buffer pointer. Implements @ref uart_api_t::read
 *
 * @retval  FSP_SUCCESS                  Data reception successfully ends.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART control block is NULL.
 *                                       Number of transfers outside the max or min boundary when transfer instance used.
 * @retval  FSP_ERR_INVALID_ARGUMENT     Destination address or data size is not valid for 9-bit mode.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_IN_USE               A previous read operation is still in progress.
 * @retval  FSP_ERR_UNSUPPORTED          p_extend->operation_enable is set to 0.
 **********************************************************************************************************************/
fsp_err_t R_RLIN3_UART_Read (uart_ctrl_t * const p_api_ctrl, uint8_t * const p_dest, uint32_t const bytes) /* PRQA S 1505 # DP_MSR_R-8.7_UC1 */
{
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl;                       /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */

    fsp_err_t err = FSP_SUCCESS;

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    err = r_rlin3_uart_read_write_param_check(p_ctrl, p_dest, bytes);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ERROR_RETURN(0U == p_ctrl->rx_dest_bytes, FSP_ERR_IN_USE);
    FSP_ERROR_RETURN(false == p_ctrl->rx_suspended, FSP_ERR_IN_USE);
#endif

    rlin3_uart_extended_cfg_t * p_extend = ((rlin3_uart_extended_cfg_t *) p_ctrl->p_cfg->p_extend); /* PRQA S 0310, 0311, 0316, 3678 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1, DP_MSR_R-8.13_UC1 */
#if (R_RLIN3_UART_CFG_TRANSFER_SUPPORT_ENABLE)

    /* Configure transfer instance to receive the requested number of bytes if transfer is used for reception. */
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_dest = (void *) p_dest;

        if (UART_DATA_BITS_9 == p_ctrl->p_cfg->data_bits)
        {
            uint32_t transfer_count = bytes / RLIN3_UART_DATA_2_BYTES;

            /* Each 9 bit word occupies 2 bytes, divide total bytes by 2 to get transfer count. */
            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->number_transfer = transfer_count;
        }
        else
        {
            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->number_transfer = bytes;
        }

        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_src = (void *) &(p_ctrl->p_reg->LURDR); /* PRQA S 0312, 0311, 0662 # DP_MSR_R-11.8_UC1, DP_MSR_R-1.1_UC1 */

        /* Disable the corresponding IRQ when transferring using transfer API. */
        R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);

        /* Disable the interrupt selection by calling the configuration disable function. */
 #if BSP_FEATURE_DEVICE_HAS_INTSEL_IRQ
        if (BSP_INTSEL_DISABLED != p_extend->intsel_irq_cfg) /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
        {
            R_BSP_IntSel_CfgDisable(p_extend->intsel_irq_cfg);
        }
 #endif

        err = p_ctrl->p_cfg->p_transfer_rx->p_api->reconfigure(p_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                               p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        err = p_ctrl->p_cfg->p_transfer_rx->p_api->enable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
#endif
    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_RX))
    {
        if (0U == (p_ctrl->p_reg->LST & R_RLN30_LST_URS_Msk)) /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
        {
            p_ctrl->p_rx_dest     = p_dest;
            p_ctrl->rx_dest_bytes = bytes;
        }
        else
        {
            err = FSP_ERR_IN_USE;
        }
    }
    else
    {
        err = FSP_ERR_UNSUPPORTED;
    }

    return err;
}

/*******************************************************************************************************************//**
 * Transmits user specified number of bytes from the source buffer pointer. Implements @ref uart_api_t::write
 *
 * @retval  FSP_SUCCESS                  Data transmission finished successfully.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART control block is NULL.
 *                                       Number of transfers outside the max or min boundary when transfer instance used.
 * @retval  FSP_ERR_INVALID_ARGUMENT     Source address or data size is not valid for 9-bit mode.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_IN_USE               A UART transmission is in progress.
 * @retval  FSP_ERR_UNSUPPORTED          p_extend->operation_enable is set to 0.
 **********************************************************************************************************************/
fsp_err_t R_RLIN3_UART_Write (uart_ctrl_t * const p_api_ctrl, uint8_t const * const p_src, uint32_t const bytes) /* PRQA S 1505 # DP_MSR_R-8.7_UC1 */
{
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl;                             /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */

    fsp_err_t err = FSP_SUCCESS;

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    err = r_rlin3_uart_read_write_param_check(p_ctrl, p_src, bytes);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    FSP_ERROR_RETURN(0U == p_ctrl->tx_src_bytes, FSP_ERR_IN_USE);
    FSP_ERROR_RETURN(0U == (p_ctrl->p_reg->LST & R_RLN30_LST_UTS_Msk), FSP_ERR_IN_USE);             /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    rlin3_uart_extended_cfg_t * p_extend = ((rlin3_uart_extended_cfg_t *) p_ctrl->p_cfg->p_extend); /* PRQA S 0310, 0311, 0316, 3678 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1, DP_MSR_R-8.13_UC1 */

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_TX))
    {
        if (0U != p_extend->tx_buffer)
        {
            p_ctrl->tx_src_bytes = bytes;
            p_ctrl->p_tx_src     = p_src;

            /* Check transmission and buffer transmission flag */
            if (0U == (p_ctrl->p_reg->LST & (R_RLN30_LST_UTS_Msk | R_RLN30_LST_FTC_Msk))) /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
            {
                r_rlin3_uart_buffer_transmission(p_ctrl, p_extend->tx_buffer);
            }
        }
        else
        {
            p_ctrl->tx_src_bytes = bytes;
            p_ctrl->p_tx_src     = p_src;

            /* Check transmission flag */
            if (0U == (p_ctrl->p_reg->LST & R_RLN30_LST_UTS_Msk)) /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
            {
                /* Transmiss 8 or 9 bit */
                if (RLIN3_UART_DATA_2_BYTES == p_ctrl->data_bytes)
                {
                    p_ctrl->p_reg->LUTDR = *((uint16_t *) (p_ctrl->p_tx_src)); /* PRQA S 3305, 0311, 0310, 0662 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.8_UC1, DP_MSR_R-11.3_UC1, DP_MSR_R-1.1_UC1 */

                    /* Check Expansion Bit Comparison Enable */
                    if (1U == p_ctrl->p_reg->LUOR1_b.UEBDCE)                   /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
                    {
                        p_ctrl->p_reg->LIDB = *(p_ctrl->p_tx_src);             /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
                    }
                }
                else
                {
                    p_ctrl->p_reg->LUTDR = *(p_ctrl->p_tx_src); /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
                }

                /* Increase pointer of source data to transmit next data */
                p_ctrl->tx_src_bytes -= p_ctrl->data_bytes;
                p_ctrl->p_tx_src     += p_ctrl->data_bytes; /* PRQA S 0488 # DP_MSR_R-18.4_UC1 */
            }

#if R_RLIN3_UART_CFG_TRANSFER_SUPPORT_ENABLE

            /* If a transfer instance is used for transmission, reset the transfer instance to transmit the requested
             * data. */
            if ((NULL != p_ctrl->p_cfg->p_transfer_tx) && (0U != (p_ctrl->tx_src_bytes)))               /* PRQA S 4558 # DP_MSR_R-10.1_UC1 */
            {
                p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->p_src  = (void const *) p_ctrl->p_tx_src;
                p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->p_dest = (void *) &(p_ctrl->p_reg->LUTDR); /* PRQA S 0312, 0662 # DP_MSR_R-11.8_UC1, DP_MSR_R-1.1_UC1 */

                /* Initialize number transfers to the number of bytes to transfer */
                if (UART_DATA_BITS_9 == p_ctrl->p_cfg->data_bits)
                {
                    /* Adjust the number of transfers for data bits by subtracting 2 from total bytes. */
                    uint32_t num_transfers = (bytes - RLIN3_UART_DATA_2_BYTES) / RLIN3_UART_DATA_2_BYTES;

                    /* Calculate number of transfers */
                    p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->number_transfer = num_transfers;
                }
                else
                {
                    /* Adjust the number of transfers for configurations.*/
                    uint32_t num_transfers = bytes - 1; /* PRQA S 1840 # DP_MSR_R-10.4_UC1 */

                    /* Calculate number of transfers */
                    p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->number_transfer = num_transfers;
                }

                /* Disable the corresponding IRQ when transferring using transfer API. */
                R_BSP_IrqDisable(p_ctrl->p_cfg->txi_irq);

 #if BSP_FEATURE_DEVICE_HAS_INTSEL_IRQ
                if (BSP_INTSEL_DISABLED != p_extend->intsel_irq_cfg) /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
                {
                    /* Disable the interrupt selection by calling the configuration disable function. */
                    R_BSP_IntSel_CfgDisable(p_extend->intsel_irq_cfg);
                }
 #endif

                err = p_ctrl->p_cfg->p_transfer_tx->p_api->reconfigure(p_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                                       p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info);
                FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
                err = p_ctrl->p_cfg->p_transfer_tx->p_api->enable(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);
                FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
            }
#endif
        }
    }
    else
    {
        err = FSP_ERR_UNSUPPORTED;
    }

    return err;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements uart_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_RLIN3_UART_CallbackSet (uart_ctrl_t * const          p_api_ctrl,                          /* PRQA S 1505 # DP_MSR_R-8.7_UC1 */
                                    void (                     * p_callback)(uart_callback_args_t *), /* PRQA S 1336 # DP_MSR_R-8.2_UC1 */
                                    void                       * p_context,
                                    uart_callback_args_t * const p_callback_memory)
{
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl;                  /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);                                                                           /* PRQA S 3344 # DP_MSR_R-14.4_UC1 */
    FSP_ERROR_RETURN(RLIN3_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_ctrl->p_callback        = p_callback;
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provides API to abort ongoing read. Reception is still enabled after abort(). Any characters received after abort()
 * and before the transfer is reset in the next call to read(), will arrive via the callback function with event
 * UART_EVENT_RX_CHAR.
 * Implements @ref uart_api_t::readStop
 *
 * @retval  FSP_SUCCESS                  UART transaction aborted successfully.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_RLIN3_UART_ReadStop (uart_ctrl_t * const p_api_ctrl, uint32_t * remaining_bytes) /* PRQA S 1505 # DP_MSR_R-8.7_UC1 */
{
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl;         /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(remaining_bytes);
    FSP_ERROR_RETURN(RLIN3_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    *remaining_bytes      = p_ctrl->rx_dest_bytes;
    p_ctrl->rx_dest_bytes = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provides API to abort ongoing transfer. Transmission is aborted after the current character is transmitted.
 * Reception is still enabled after abort(). Any characters received after abort() and before the transfer
 * is reset in the next call to read(), will arrive via the callback function with event UART_EVENT_RX_CHAR.
 * Implements @ref uart_api_t::communicationAbort
 *
 * @retval  FSP_SUCCESS                  UART transaction aborted successfully.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_UNSUPPORTED          The requested Abort direction is unsupported.
 **********************************************************************************************************************/

fsp_err_t R_RLIN3_UART_Abort (uart_ctrl_t * const p_api_ctrl, uart_dir_t communication_to_abort) /* PRQA S 1505 # DP_MSR_R-8.7_UC1 */
{
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl;             /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */
    fsp_err_t err = FSP_ERR_UNSUPPORTED;

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(RLIN3_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    rlin3_uart_extended_cfg_t * p_extend = ((rlin3_uart_extended_cfg_t *) p_ctrl->p_cfg->p_extend); /* PRQA S 0310, 0311, 0316, 3678 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1, DP_MSR_R-8.13_UC1 */

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_TX))
    {
        if ((uint32_t) UART_DIR_TX == ((uint32_t) communication_to_abort & (uint32_t) UART_DIR_TX))
        {
            err = FSP_SUCCESS;
            p_ctrl->tx_src_bytes = 0U;
        }
    }

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_RX))
    {
        if ((uint32_t) UART_DIR_RX == ((uint32_t) UART_DIR_RX & (uint32_t) communication_to_abort))
        {
            err = FSP_SUCCESS;
            p_ctrl->rx_dest_bytes = 0U;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Suspend Reception
 * Implements @ref uart_api_t::receiveSuspend
 * @retval     FSP_SUCCESS             Reception suspended successfully.
 * @retval     FSP_ERR_NOT_OPEN        The channel is not open.
 * @retval     FSP_ERR_ASSERTION       Pointer to UART control block is NULL.
 **********************************************************************************************************************/
fsp_err_t R_RLIN3_UART_ReceiveSuspend (uart_ctrl_t * const p_api_ctrl)               /* PRQA S 1505 # DP_MSR_R-8.7_UC1 */
{
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl; /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */

#if RLIN3_UART_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(RLIN3_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Disable RX interrupt */
    R_BSP_IrqStatusClear(p_ctrl->p_cfg->rxi_irq);
    R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);

#if (R_RLIN3_UART_CFG_TRANSFER_SUPPORT_ENABLE)

    /* Disable RX transfer request (DMAC/DTC) if configured */
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        p_ctrl->p_cfg->p_transfer_rx->p_api->disable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
    }
#endif

    /* Suspend RX */
    p_ctrl->rx_suspended = true;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Resume Reception
 * Implements @ref uart_api_t::receiveResume
 *
 * @retval     FSP_SUCCESS             Reception resumed successfully.
 * @retval     FSP_ERR_NOT_OPEN        The channel is not open.
 * @retval     FSP_ERR_ASSERTION       Pointer to UART control block is NULL.
 **********************************************************************************************************************/
fsp_err_t R_RLIN3_UART_ReceiveResume (uart_ctrl_t * const p_api_ctrl)                /* PRQA S 1505 # DP_MSR_R-8.7_UC1 */
{
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_api_ctrl; /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */

#if RLIN3_UART_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(RLIN3_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    p_ctrl->p_rx_dest     = NULL;
    p_ctrl->rx_dest_bytes = 0U;

#if (R_RLIN3_UART_CFG_TRANSFER_SUPPORT_ENABLE)

    /* Enable RX transfer request */
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        p_ctrl->p_rx_dest     = NULL;
        p_ctrl->rx_dest_bytes = 0U;
        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->number_transfer = RLIN3_UART_NUM_TRANSFER_RESET;
        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_src           = (uint32_t *) NULL;
        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_dest          = (uint32_t *) NULL;
        p_ctrl->p_cfg->p_transfer_rx->p_api->disable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
        p_ctrl->p_cfg->p_transfer_rx->p_api->reconfigure(p_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                         p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info);
    }
#endif

    /* Enable RX interrupt */
    R_BSP_IrqStatusClear(p_ctrl->p_cfg->rxi_irq);
    R_BSP_IrqEnable(p_ctrl->p_cfg->rxi_irq);

    /* Release status */
    p_ctrl->rx_suspended = false;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RLIN3_UART)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Calculates baud rate register settings. Evaluates and determines the best possible settings set to the baud rate
 * related registers.
 *
 * @param[in]  p_ctrl                    Pointer to UART specific configuration structure
 * @param[out] p_baud_setting            Baud setting information stored here if successful.
 *
 * @retval     FSP_SUCCESS               Baud rate is set successfully.
 * @retval     FSP_ERR_ASSERTION         Null pointer.
 * @retval     FSP_ERR_UNSUPPORTED       Baud rate is '0', error in calculated baud rate is larger than requested
 *                                       max error, or requested max error in baud rate is larger than 15%.
 **********************************************************************************************************************/
static fsp_err_t r_rlin3_uart_baudcalculate (rlin3_uart_instance_ctrl_t * const p_ctrl,                       /* PRQA S 3673 # DP_MSR_R-8.13_UC1 */
                                             baud_setting_t * const             p_baud_setting)
{
    rlin3_uart_extended_cfg_t const * p_extend = (rlin3_uart_extended_cfg_t const *) p_ctrl->p_cfg->p_extend; /* PRQA S 0310, 0316 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.5_UC1 */

    /* Initialization for UART configuration parameters for baud rate calculation. */
    uint32_t lbrp        = 0UL;                                                                               /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    uint32_t divisor     = 0UL;                                                                               /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    uint32_t err_divisor = 0UL;                                                                               /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    int32_t  hit_bit_err = UART_100_PERCENT_X_1000;
    int32_t  bit_err     = UART_100_PERCENT_X_1000;
    uint8_t  lprs        = 0U;
    uint8_t  bit_samp    = 0U;
    uint32_t freq_hz     = 0U;
    uint32_t baudrate    = p_baud_setting->baudrate;

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_baud_setting);
    FSP_ERROR_RETURN(UART_MAX_BAUD_RATE_ERROR_X_1000 >= /* PRQA S 3397 # DP_MSR_R-12.1_UC1 */
                     (uint32_t) (p_extend->baudrate_max_err_percent) * (uint32_t) UART_PERCENT_X_1000,
                     FSP_ERR_UNSUPPORTED);
    FSP_ERROR_RETURN((0U != baudrate), FSP_ERR_UNSUPPORTED);
#endif

    /* Determine the UART clock frequency based on the channel number */
    if (BSP_FEATURE_RLIN323_CHANNEL != p_ctrl->p_cfg->channel)
    {
        freq_hz = RLIN3_UART_CFG_CLOCK;
    }
    else
    {
        freq_hz = RLIN3_UART_CFG_CLOCK_CH23;
    }

    p_baud_setting->prescaler       = RLIN3_UART_MAX_BAUDRATE_PRESCALER;
    p_baud_setting->prescaler_clock = RLIN3_UART_MAX_CLKDIV_SEL - 1;  /* PRQA S 1840 # DP_MSR_R-10.4_UC1 */
    p_baud_setting->bit_sampling    = RLIN3_UART_MAX_BITSAMPLING - 1; /* PRQA S 1840 # DP_MSR_R-10.4_UC1 */

    for (lprs = 0U; lprs < RLIN3_UART_MAX_CLKDIV_SEL; lprs++)
    {
        for (bit_samp = RLIN3_UART_MIN_BITSAMPLING; bit_samp < RLIN3_UART_MAX_BITSAMPLING; bit_samp++)
        {
            divisor = (uint32_t) (clock_prescaler[lprs]) * (bit_samp + 1U) * baudrate; /* PRQA S 1891 # DP_MSR_R-10.7_UC1 */
            lbrp    = freq_hz / divisor;
            if (lbrp > RLIN3_UART_MAX_BAUDRATE_PRESCALER)
            {
                continue;
            }

            if (((freq_hz % divisor) > (divisor / 2)) || (0U == lbrp))                  /* PRQA S 1840 # DP_MSR_R-10.4_UC1 */
            {
                lbrp += 1;                                                              /* PRQA S 1840 # DP_MSR_R-10.4_UC1 */
            }

            err_divisor = divisor * lbrp;
            bit_err     = (int32_t) (((((int64_t) freq_hz) * UART_100_PERCENT_X_1000) / /* PRQA S 1850 # DP_MSR_R-10.4_UC1 */
                                      err_divisor) - UART_100_PERCENT_X_1000);
            if (bit_err < 0)
            {
                bit_err = -bit_err;
            }

            if (bit_err <= hit_bit_err)
            {
                hit_bit_err = bit_err;
                p_baud_setting->bit_sampling    = bit_samp & 0xFU;
                p_baud_setting->prescaler_clock = lprs & 0x7U;
                p_baud_setting->prescaler       = (uint16_t) (lbrp - 1); /* PRQA S 1840 # DP_MSR_R-10.4_UC1 */
            }
        }
    }

    FSP_ERROR_RETURN((hit_bit_err <= (int32_t) p_extend->baudrate_max_err_percent * UART_PERCENT_X_1000), /* PRQA S 3397 # DP_MSR_R-12.1_UC1 */
                     FSP_ERR_UNSUPPORTED);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to UART instance control block
 * @param[in]     data       See uart_callback_args_t in r_uart_api.h
 * @param[in]     event      Event code
 **********************************************************************************************************************/
static void r_rlin3_uart_call_callback (rlin3_uart_instance_ctrl_t * p_ctrl, uint32_t data, uart_event_t event) /* PRQA S 3673 # DP_MSR_R-8.13_UC1 */
{
    uart_callback_args_t args;

    uart_callback_args_t * p_args = p_ctrl->p_callback_memory;
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

    p_args->channel   = p_ctrl->p_cfg->channel;
    p_args->data      = data;
    p_args->event     = event;
    p_args->p_context = p_ctrl->p_context;

    if (NULL != p_ctrl->p_callback)
    {
        p_ctrl->p_callback(p_args);
    }

    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

#if (R_RLIN3_UART_CFG_TRANSFER_SUPPORT_ENABLE)

/*******************************************************************************************************************//**
 * Transmit data empty interrupt routine called when the DMA transfer is completed.
 *
 * @param[in]     p_args     Pointer to callback.
 **********************************************************************************************************************/
void rlin3_uart_txi_transfer_callback (transfer_callback_args_t * p_args)                       /* PRQA S 3673, 1505 # DP_MSR_R-8.13_UC1, DP_MSR_R-8.7_UC1 */
{
    if ((TRANSFER_EVENT_TRANS_END_FLAG == p_args->event) || (TRANSFER_EVENT_TRANS_COMPLETION == p_args->event))
    {
        rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_args->p_context; /* PRQA S 0311, 0316 # DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1 */

        /* Call the user callback with the fast channel transmit complete event */
        r_rlin3_uart_call_callback(p_ctrl, 0U, UART_EVENT_TX_COMPLETE);

        /* Reset tx_src_bytes for next transfer*/
        p_ctrl->tx_src_bytes = 0U;
        p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->number_transfer = RLIN3_UART_NUM_TRANSFER_RESET;
        p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->p_src           = (uint32_t *) NULL;
        p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->p_dest          = (uint32_t *) NULL;
        p_ctrl->p_cfg->p_transfer_tx->p_api->disable(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);
        p_ctrl->p_cfg->p_transfer_tx->p_api->reconfigure(p_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                         p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info);
        R_BSP_IrqEnable(p_ctrl->p_cfg->txi_irq);
    }
}

/*******************************************************************************************************************//**
 * Receive data empty interrupt routine called when the DMA transfer is completed.
 *
 * @param[in]     p_args     Pointer to callback.
 **********************************************************************************************************************/
void rlin3_uart_rxi_transfer_callback (transfer_callback_args_t * p_args)                       /* PRQA S 3673, 1505 # DP_MSR_R-8.13_UC1, DP_MSR_R-8.7_UC1 */
{
    if ((TRANSFER_EVENT_TRANS_END_FLAG == p_args->event) || (TRANSFER_EVENT_TRANS_COMPLETION == p_args->event))
    {
        rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) p_args->p_context; /* PRQA S 0311, 0316 # DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1 */

        /* Reset rx_dest_bytes for next transfer*/
        p_ctrl->rx_dest_bytes = 0U;

        /* Call the user callback with the fast channel receive complete event */
        r_rlin3_uart_call_callback(p_ctrl, 0U, UART_EVENT_RX_COMPLETE);
    }
}

/*******************************************************************************************************************//**
 * Configures UART related transfer drivers (if enabled).
 *
 * @param[in]     p_ctrl  Pointer to UART control structure
 * @param[in]     p_cfg            Pointer to UART specific configuration structure
 *
 * @retval        FSP_SUCCESS        UART transfer drivers successfully configured
 * @retval        FSP_ERR_ASSERTION  Invalid pointer or required interrupt not enabled in vector table
 *
 * @return                       See @ref RENESAS_ERROR_CODES or functions called by this function for other possible
 *                               return codes. This function calls:
 *                                   * @ref transfer_api_t::open
 **********************************************************************************************************************/
static fsp_err_t r_rlin3_uart_transfer_open (rlin3_uart_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg)
{
    rlin3_uart_extended_cfg_t * p_extend = ((rlin3_uart_extended_cfg_t *) p_ctrl->p_cfg->p_extend); /* PRQA S 0310, 0311, 0316, 3678 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1, DP_MSR_R-8.13_UC1 */
    fsp_err_t err = FSP_SUCCESS;

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_RX))
    {
        /* If a transfer instance is used for reception, apply UART specific settings and open the transfer instance. */
        if (NULL != p_cfg->p_transfer_rx)
        {
            err = r_rlin3_uart_transfer_receive_configure(p_ctrl, p_cfg->p_transfer_rx, p_cfg);
            FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        }
    }

    if (0U != ((uint32_t) p_extend->operation_enable & (uint32_t) UART_DIR_TX))
    {
        /* If a transfer instance is used for transmission, apply UART specific settings and open the transfer instance. */
        if (NULL != p_cfg->p_transfer_tx)
        {
            err = r_rlin3_uart_transfer_transmit_configure(p_ctrl, p_cfg->p_transfer_tx, p_cfg);
            FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        }
    }

    return FSP_SUCCESS;
}

#endif

#if (R_RLIN3_UART_CFG_TRANSFER_SUPPORT_ENABLE)

/*******************************************************************************************************************//**
 * Subroutine to apply common UART transfer settings.
 *
 * @param[in]  p_cfg              Pointer to UART specific configuration structure
 * @param[in]  p_transfer         Pointer to transfer instance to configure
 *
 * @retval     FSP_SUCCESS        UART transfer drivers successfully configured
 * @retval     FSP_ERR_ASSERTION  Invalid pointer
 **********************************************************************************************************************/
static fsp_err_t r_rlin3_uart_transfer_receive_configure (rlin3_uart_instance_ctrl_t * const p_ctrl,
                                                          transfer_instance_t const        * p_transfer,
                                                          uart_cfg_t const * const           p_cfg)
{
    /* Configure the transfer instance, if enabled. */
 #if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_transfer->p_api);
    FSP_ASSERT(NULL != p_transfer->p_ctrl);
    FSP_ASSERT(NULL != p_transfer->p_cfg);
    FSP_ASSERT(NULL != p_transfer->p_cfg->p_info);
    FSP_ASSERT(NULL != p_transfer->p_cfg->p_extend);
 #endif

    /* Setting number data byte for transfer API*/
    transfer_info_t * p_info = p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info;
    if (UART_DATA_BITS_9 == p_ctrl->p_cfg->data_bits)
    {
        p_info->transfer_mode_cfg.transfer_mode_b.src_trans_size           = TRANSFER_SIZE_2_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
        p_info->transfer_mode_cfg.transfer_mode_b.des_trans_size           = TRANSFER_SIZE_2_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
        p_info->transfer_control_cfg.transfer_control_b.transfer_data_size = TRANSFER_SIZE_2_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
    }
    else
    {
        p_info->transfer_mode_cfg.transfer_mode_b.src_trans_size           = TRANSFER_SIZE_1_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
        p_info->transfer_mode_cfg.transfer_mode_b.des_trans_size           = TRANSFER_SIZE_1_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
        p_info->transfer_control_cfg.transfer_control_b.transfer_data_size = TRANSFER_SIZE_1_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
    }

    if (NULL != p_cfg->p_transfer_rx)
    {
        fsp_err_t err = p_ctrl->p_cfg->p_transfer_rx->p_api->open(p_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                                  p_cfg->p_transfer_rx->p_cfg);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        err = p_ctrl->p_cfg->p_transfer_rx->p_api->callbackSet(p_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                               rlin3_uart_rxi_transfer_callback, /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
                                                               p_ctrl,
                                                               NULL);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Subroutine to apply common UART transfer settings.
 *
 * @param[in]  p_cfg              Pointer to UART specific configuration structure
 * @param[in]  p_transfer         Pointer to transfer instance to configure
 *
 * @retval     FSP_SUCCESS        UART transfer drivers successfully configured
 * @retval     FSP_ERR_ASSERTION  Invalid pointer
 **********************************************************************************************************************/
static fsp_err_t r_rlin3_uart_transfer_transmit_configure (rlin3_uart_instance_ctrl_t * const p_ctrl,
                                                           transfer_instance_t const        * p_transfer,
                                                           uart_cfg_t const * const           p_cfg)
{
    /* Configure the transfer instance, if enabled. */
 #if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_transfer->p_api);
    FSP_ASSERT(NULL != p_transfer->p_ctrl);
    FSP_ASSERT(NULL != p_transfer->p_cfg);
    FSP_ASSERT(NULL != p_transfer->p_cfg->p_info);
    FSP_ASSERT(NULL != p_transfer->p_cfg->p_extend);
 #endif

    /* Setting number data byte for transfer API*/
    transfer_info_t * p_info = p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info;
    if (UART_DATA_BITS_9 == p_ctrl->p_cfg->data_bits)
    {
        p_info->transfer_mode_cfg.transfer_mode_b.src_trans_size           = TRANSFER_SIZE_2_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
        p_info->transfer_mode_cfg.transfer_mode_b.des_trans_size           = TRANSFER_SIZE_2_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
        p_info->transfer_control_cfg.transfer_control_b.transfer_data_size = TRANSFER_SIZE_2_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
    }
    else
    {
        p_info->transfer_mode_cfg.transfer_mode_b.src_trans_size           = TRANSFER_SIZE_1_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
        p_info->transfer_mode_cfg.transfer_mode_b.des_trans_size           = TRANSFER_SIZE_1_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
        p_info->transfer_control_cfg.transfer_control_b.transfer_data_size = TRANSFER_SIZE_1_BYTE; /* PRQA S 4423 # DP_MSR_R-10.3_UC1 */
    }

    if (NULL != p_cfg->p_transfer_tx)
    {
        fsp_err_t err = p_ctrl->p_cfg->p_transfer_tx->p_api->open(p_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                                  p_cfg->p_transfer_tx->p_cfg);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        err = p_ctrl->p_cfg->p_transfer_tx->p_api->callbackSet(p_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                               rlin3_uart_txi_transfer_callback, /* PRQA S 3635 # DP_MSR_R-17.12_UC1 */
                                                               p_ctrl,
                                                               NULL);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * Configures UART related registers based on user configurations.
 *
 * @param[in]     p_ctrl  Pointer to UART control structure
 * @param[in]     p_cfg   Pointer to UART specific configuration structure
 **********************************************************************************************************************/
static void r_rlin3_uart_config_set (rlin3_uart_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg) /* PRQA S 3673 # DP_MSR_R-8.13_UC1 */
{
    rlin3_uart_extended_cfg_t * p_extend = ((rlin3_uart_extended_cfg_t *) p_cfg->p_extend);                     /* PRQA S 0310, 0311, 0316, 3678 # DP_MSR_R-11.3_UC1, DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1, DP_MSR_R-8.13_UC1 */
    uint32_t lede = 0U;
    uint32_t lbfc = 0U;

    /* Setting UART configuration Register */
    lbfc = ((uint32_t) p_extend->invert_output << R_RLN30_LBFC_UTPS_Pos) |
           ((uint32_t) p_extend->invert_input << R_RLN30_LBFC_URPS_Pos) |
           (((uint32_t) p_cfg->parity << R_RLN30_LBFC_UPS_Pos) |
            ((uint32_t) p_cfg->stop_bits << R_RLN30_LBFC_USBLS_Pos)) |
           ((uint32_t) p_extend->transfer_order << R_RLN30_LBFC_UBOS_Pos);

    if (UART_DATA_BITS_7 == p_cfg->data_bits)
    {
        lbfc |= R_RLN30_LBFC_UBLS_Msk;
    }

    p_ctrl->p_reg->LUOR1 = 0x00U;      /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */

    if (RLIN3_UART_DATA_2_BYTES == p_ctrl->data_bytes)
    {
        if (RLIN3_UART_EXPANSION_BIT_DISABLE == p_extend->expansion_bit_enable)
        {
            p_ctrl->p_reg->LUOR1 |= RLIN3_UART_DATA_2_BYTES_MASK; /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
        }
        else
        {
            if (RLIN3_UART_EXPANSION_BIT_COMPARISON_ENABLE == p_extend->expansion_bit_comparison)
            {
                p_ctrl->p_reg->LUOR1 |= RLIN3_UART_ENABLE_EXPANSION_BIT_COMPARISION; /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
            }
            else
            {
                p_ctrl->p_reg->LUOR1 |= RLIN3_UART_ENABLE_EXPANSION_BIT;             /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
            }
        }
    }

    /* Setting UART Mode Register */
    p_ctrl->p_reg->LMD = 0x01U;                                              /* PRQA S 0662, 3108 # DP_MSR_R-1.1_UC1, DP_MSR_R-3.1_UC1 */
    if (RLIN3_UART_NOISE_CANCELLATION_DISABLE == p_extend->noise_cancel)
    {
        p_ctrl->p_reg->LMD_b.LRDNFS = RLIN3_UART_NOISE_CANCELLATION_DISABLE; /* PRQA S 4424, 0662 # DP_MSR_R-10.3_UC1, DP_MSR_R-1.1_UC1 */
    }
    else
    {
        p_ctrl->p_reg->LMD_b.LRDNFS = RLIN3_UART_NOISE_CANCELLATION_ENABLE;  /* PRQA S 4424, 0662 # DP_MSR_R-10.3_UC1, DP_MSR_R-1.1_UC1 */
    }

    /* Setting UART Error Detection Enable Register */
    lede = ((uint32_t) p_extend->enb_bit_err << R_RLN30_LEDE_BERE_Pos) |
           ((uint32_t) p_extend->enb_overrun_err << R_RLN30_LEDE_OERE_Pos) |
           ((uint32_t) p_extend->enb_frame_err << R_RLN30_LEDE_FERE_Pos);

    p_ctrl->p_reg->LEDE = (uint8_t) lede; /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    p_ctrl->p_reg->LBFC = (uint8_t) lbfc; /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */

    r_rlin3_uart_baud_set(p_ctrl->p_reg, p_extend->p_baud_setting);

    if (UART_TRANSMISSION == p_extend->timing_select)
    {
        p_ctrl->p_reg->LUOR1 &= (uint8_t) (~R_RLN30_LUOR1_UTIGTS_Msk); /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    }
    else
    {
        p_ctrl->p_reg->LUOR1 |= R_RLN30_LUOR1_UTIGTS_Msk;              /* PRQA S 4461, 0662 # DP_MSR_R-10.3_UC1, DP_MSR_R-1.1_UC1 */
    }

    /* Setting UART Buffer transmission */
    if ((0U != p_extend->tx_buffer) && (9U >= p_extend->tx_buffer) &&
        (RLIN3_UART_DATA_2_BYTES != p_ctrl->data_bytes))
    {
        p_ctrl->p_reg->LSC  = p_extend->inter_byte_space << R_RLN30_LSC_IBS_Pos; /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
        p_ctrl->p_reg->LDFC = p_extend->tx_buffer;                               /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    }

    p_ctrl->p_reg->LCUC = RLIN3_UART_MODE;                                       /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->LMST, RLIN3_UART_MODE);            /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    if (UART_DIR_TX == p_extend->operation_enable)
    {
        p_ctrl->p_reg->LUOER = RLIN3_UART_TX_ENABLE;                             /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    }
    else if (UART_DIR_RX == p_extend->operation_enable)
    {
        p_ctrl->p_reg->LUOER = RLIN3_UART_RX_ENABLE;                             /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    }
    else
    {
        p_ctrl->p_reg->LUOER = RLIN3_UART_TX_RX_ENABLE;                          /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    }
}

/*******************************************************************************************************************//**
 * Changes baud rate based on predetermined register settings.
 *
 * @param[in]  p_rlin3_reg       Base pointer for RLIN3 registers
 * @param[in]  p_baud_setting  Pointer to other divisor related settings
 *
 * @note       Must to be in reset mode (RLN3nLMST.OM0 = 0) when calling this function.
 **********************************************************************************************************************/
static void r_rlin3_uart_baud_set (R_RLN30_Type * p_rlin3_reg, baud_setting_t const * const p_baud_setting)
{
    if (0U != p_baud_setting->bit_sampling)
    {
        p_rlin3_reg->LWBR = (uint8_t) (((uint32_t) p_baud_setting->bit_sampling << R_RLN30_LWBR_NSPB_Pos) | /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
                                       ((uint32_t) p_baud_setting->prescaler_clock << R_RLN30_LWBR_LPRS_Pos));
    }
    else
    {
        p_rlin3_reg->LWBR = (uint8_t) ((uint32_t) p_baud_setting->prescaler_clock << R_RLN30_LWBR_LPRS_Pos); /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    }

    p_rlin3_reg->LBRP01 = p_baud_setting->prescaler;                                                         /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
}

/*******************************************************************************************************************//**
 * Enable Buffer Transmission.
 *
 * @param[in]  p_ctrl       Pointer to UART instance control block
 * @param[in]  buffer_size  Buffer size for buffer transmission
 *
 * @note       Buffer transmission is not available in 9 bit transmission.
 **********************************************************************************************************************/
static void r_rlin3_uart_buffer_transmission (rlin3_uart_instance_ctrl_t * const p_ctrl, uint8_t buffer_size)
{
    /* If buffer size = 9, LUDDB0 is used */
    if (9U == buffer_size)
    {
        p_ctrl->p_reg->LUDB0  = *(p_ctrl->p_tx_src);          /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
        p_ctrl->tx_src_bytes -= p_ctrl->data_bytes;
        p_ctrl->p_tx_src     += p_ctrl->data_bytes;           /* PRQA S 0488 # DP_MSR_R-18.4_UC1 */
        buffer_size           = (uint8_t) (buffer_size - 1U); /* PRQA S 1860, 1338 # DP_MSR_R-10.4_UC1, DP_MSR_R-17.8_UC1 */
    }

    for (uint8_t i = 0U; i < buffer_size; i++)
    {
        if (0U == p_ctrl->tx_src_bytes)
        {
            p_ctrl->p_reg->LDBR[i] = 0U;                  /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
        }
        else
        {
            p_ctrl->p_reg->LDBR[i] = *(p_ctrl->p_tx_src); /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
            p_ctrl->tx_src_bytes  -= p_ctrl->data_bytes;
            p_ctrl->p_tx_src      += p_ctrl->data_bytes;  /* PRQA S 0488 # DP_MSR_R-18.4_UC1 */
        }
    }

    p_ctrl->p_reg->LTRC |= 0x02U;                         /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
}

#if (RLIN3_UART_CFG_PARAM_CHECKING_ENABLE)

/*******************************************************************************************************************//**
 * Parameter error check function for read/write.
 *
 * @param[in] p_ctrl Pointer to the control block for the channel
 * @param[in] addr   Pointer to the buffer
 * @param[in] bytes  Number of bytes to read or write
 *
 * @retval  FSP_SUCCESS              No parameter error found.
 * @retval  FSP_ERR_NOT_OPEN         The control block has not been opened.
 * @retval  FSP_ERR_ASSERTION        Pointer to UART control block or configuration structure is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT Address is not aligned to 2-byte boundary or size is the odd number when the data
 *                                   length is 9-bit.
 **********************************************************************************************************************/
static fsp_err_t r_rlin3_uart_read_write_param_check (rlin3_uart_instance_ctrl_t const * const p_ctrl,
                                                      uint8_t const * const                    addr,
                                                      uint32_t const                           bytes)
{
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(addr);
    FSP_ASSERT(0U != bytes);
    FSP_ERROR_RETURN(RLIN3_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);

    rlin3_uart_extended_cfg_t const * p_extend = (rlin3_uart_extended_cfg_t const *) p_ctrl->p_cfg->p_extend; /* PRQA S 0316 # DP_MSR_R-11.5_UC1 */

    if (RLIN3_UART_DATA_2_BYTES == p_ctrl->data_bytes)
    {
        /* Do not allow odd buffer address if data length is 9 bits. */
        FSP_ERROR_RETURN((0U == ((uint32_t) addr & RLIN3_UART_ALIGN_2_BYTES)), FSP_ERR_INVALID_ARGUMENT); /* PRQA S 0329 # DP_MSR_R-11.4_UC1 */

        /* Do not allow odd number of data bytes if data length is 9 bits. */
        FSP_ERROR_RETURN(0U == (bytes % 2U), FSP_ERR_INVALID_ARGUMENT);

        /* Do not allow buffer transmission if data length is 9 bits. */
        FSP_ERROR_RETURN((0U == (p_extend->tx_buffer)), FSP_ERR_INVALID_ARGUMENT);
    }

    return FSP_SUCCESS;
}

#endif

/***********************************************************************************************************************
 * Interrupt service routines
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * TXI interrupt processing for UART mode. TXI interrupt fires when the data in the data register or all data bufffer
 * register transmit successfully, and the next data can be written. This interrupt writes the next data. In buffer
 * transmission, UART Buffer Transmission Flag has been clear after the last data byte is written
 **********************************************************************************************************************/
BSP_INTERRUPT_ATTRIBUTE void rlin3_uart_txi_isr (void) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    R_BSP_IrqStatusClear(irq);

    /* Recover ISR context saved in open. */
    rlin3_uart_instance_ctrl_t * p_ctrl   = (rlin3_uart_instance_ctrl_t *) R_FSP_IsrContextGet(irq); /* PRQA S 0316 # DP_MSR_R-11.5_UC1 */
    rlin3_uart_extended_cfg_t  * p_extend = ((rlin3_uart_extended_cfg_t *) p_ctrl->p_cfg->p_extend); /* PRQA S 0311, 0316, 3678 # DP_MSR_R-11.8_UC1, DP_MSR_R-11.5_UC1, DP_MSR_R-8.13_UC1 */
    if (0U != p_ctrl->tx_src_bytes)
    {
        if (0U != p_extend->tx_buffer)
        {
            p_ctrl->p_reg->LST_b.FTC = 0U; /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
            r_rlin3_uart_buffer_transmission(p_ctrl, p_extend->tx_buffer);
        }
        /* Check 8 or 9 bit data transmission */
        else if (RLIN3_UART_DATA_2_BYTES == p_ctrl->data_bytes)
        {
            p_ctrl->p_reg->LUTDR = *((uint16_t *) (p_ctrl->p_tx_src)); /* PRQA S 0311, 3305, 0310, 0662 # DP_MSR_R-11.8_UC1, DP_MSR_R-11.3_UC1, DP_MSR_R-11.3_UC1, DP_MSR_R-1.1_UC1 */

            /* Increase buffer receive pointer for next transmission */
            p_ctrl->tx_src_bytes -= p_ctrl->data_bytes;
            p_ctrl->p_tx_src     += p_ctrl->data_bytes;                /* PRQA S 0488 # DP_MSR_R-18.4_UC1 */
        }
        else
        {
            p_ctrl->p_reg->LUTDR = *(p_ctrl->p_tx_src);                /* PRQA S 4434, 0662 # DP_MSR_R-10.3_UC1, DP_MSR_R-1.1_UC1 */

            /* Increase buffer receive pointer for next transmission */
            p_ctrl->tx_src_bytes -= p_ctrl->data_bytes;
            p_ctrl->p_tx_src     += p_ctrl->data_bytes;                /* PRQA S 0488 # DP_MSR_R-18.4_UC1 */
        }
    }
    else
    {
        /* Clear buffer transmission flag */
        if (0U != (p_ctrl->p_reg->LST & R_RLN30_LST_FTC_Msk)) /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
        {
            p_ctrl->p_reg->LST_b.FTC = 0U;                    /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
        }

        p_ctrl->p_tx_src = NULL;

        r_rlin3_uart_call_callback(p_ctrl, 0U, UART_EVENT_TX_COMPLETE);
    }

    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * RXI interrupt processing for UART mode. RXI interrupt happens when data arrives to the data register. This function
 * calls callback function when it meets conditions below.
 *  - UART_EVENT_RX_COMPLETE: The number of data which has been read reaches to the number specified in
 *    R_RLIN3_UART_Read() if a transfer instance is used for reception.
 *  - UART_EVENT_RX_CHAR: Data is received asynchronously (read has not been called).
 **********************************************************************************************************************/
BSP_INTERRUPT_ATTRIBUTE void rlin3_uart_rxi_isr (void) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    R_BSP_IrqStatusClear(irq);

    /* Recover ISR context saved in open. */
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) R_FSP_IsrContextGet(irq); /* PRQA S 0316 # DP_MSR_R-11.5_UC1 */

    uint32_t data;

    if (RLIN3_UART_DATA_2_BYTES == p_ctrl->data_bytes)
    {
        data = p_ctrl->p_reg->LURDR;           /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    }
    else
    {
        data = (uint8_t) p_ctrl->p_reg->LURDR; /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    }

    if (0U == p_ctrl->rx_dest_bytes)
    {
        /* Call user callback with the data. */
        r_rlin3_uart_call_callback(p_ctrl, data, UART_EVENT_RX_CHAR);
    }
    else
    {
        memcpy(p_ctrl->p_rx_dest, &data, p_ctrl->data_bytes); /* PRQA S 1495, 3200 # DP_MSR_R-21.15_UC1, DP_MSR_R-17.7_UC1 */
        p_ctrl->p_rx_dest     += p_ctrl->data_bytes;          /* PRQA S 0488 # DP_MSR_R-18.4_UC1 */
        p_ctrl->rx_dest_bytes -= p_ctrl->data_bytes;

        if (0U == p_ctrl->rx_dest_bytes)
        {
            r_rlin3_uart_call_callback(p_ctrl, 0U, UART_EVENT_RX_COMPLETE);
        }
    }

    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * ERI interrupt processing for UART mode. When an ERI interrupt fires, the user callback function is called if it is
 * registered in R_RLIN3_UART_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
BSP_INTERRUPT_ATTRIBUTE void rlin3_uart_eri_isr (void) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    R_BSP_IrqStatusClear(irq);

    /* Recover ISR context saved in open. */
    rlin3_uart_instance_ctrl_t * p_ctrl = (rlin3_uart_instance_ctrl_t *) R_FSP_IsrContextGet(irq); /* PRQA S 0316 # DP_MSR_R-11.5_UC1 */

    uint32_t data;
    uint32_t err_event = 0;

    if (RLIN3_UART_DATA_2_BYTES == p_ctrl->data_bytes)
    {
        data = p_ctrl->p_reg->LURDR;                                        /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    }
    else
    {
        data = (uint8_t) p_ctrl->p_reg->LURDR;                              /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */
    }

    /* Read LEST error register and map hardware bits to uart_event_t flags */
    uint8_t lest = (uint8_t) p_ctrl->p_reg->LEST;                           /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */

    if (R_RLN30_LEST_BER_Msk == (lest & R_RLN30_LEST_BER_Msk))
    {
        err_event = UART_EVENT_ERR_BIT;                                     /* PRQA S 4424 # DP_MSR_R-10.3_UC1 */
        r_rlin3_uart_call_callback(p_ctrl, data, (uart_event_t) err_event); /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
    }

    if (R_RLN30_LEST_OER_Msk == (lest & R_RLN30_LEST_OER_Msk))
    {
        err_event = UART_EVENT_ERR_OVERRUN;                                 /* PRQA S 4424 # DP_MSR_R-10.3_UC1 */
        r_rlin3_uart_call_callback(p_ctrl, data, (uart_event_t) err_event); /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
    }

    if (R_RLN30_LEST_FER_Msk == (lest & R_RLN30_LEST_FER_Msk))
    {
        err_event = UART_EVENT_ERR_FRAMING;                                 /* PRQA S 4424 # DP_MSR_R-10.3_UC1 */
        r_rlin3_uart_call_callback(p_ctrl, data, (uart_event_t) err_event); /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
    }

    if (R_RLN30_LEST_IDMT_Msk == (lest & R_RLN30_LEST_IDMT_Msk))
    {
        err_event = UART_EVENT_ID_MATCH;                                    /* PRQA S 4424 # DP_MSR_R-10.3_UC1 */
        r_rlin3_uart_call_callback(p_ctrl, data, (uart_event_t) err_event); /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
    }

    if (R_RLN30_LEST_EXBT_Msk == (lest & R_RLN30_LEST_EXBT_Msk))
    {
        err_event = UART_EVENT_ERR_EXPAND;                                  /* PRQA S 4424 # DP_MSR_R-10.3_UC1 */
        r_rlin3_uart_call_callback(p_ctrl, data, (uart_event_t) err_event); /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
    }

    if (R_RLN30_LEST_IDMT_Msk == (lest & R_RLN30_LEST_IDMT_Msk))
    {
        err_event = UART_EVENT_ERR_ID;                                      /* PRQA S 4424 # DP_MSR_R-10.3_UC1 */
        r_rlin3_uart_call_callback(p_ctrl, data, (uart_event_t) err_event); /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
    }

    if (R_RLN30_LEST_UPER_Msk == (lest & R_RLN30_LEST_UPER_Msk))
    {
        err_event = UART_EVENT_ERR_PARITY;                                  /* PRQA S 4424 # DP_MSR_R-10.3_UC1 */
        r_rlin3_uart_call_callback(p_ctrl, data, (uart_event_t) err_event); /* PRQA S 4342 # DP_MSR_R-10.5_UC1 */
    }

    /* Clear error flags in hardware register */
    p_ctrl->p_reg->LEST &= RLIN3_UART_CLEAR_ERR_REG_MASK;                   /* PRQA S 0662 # DP_MSR_R-1.1_UC1 */

    FSP_CONTEXT_RESTORE
}
