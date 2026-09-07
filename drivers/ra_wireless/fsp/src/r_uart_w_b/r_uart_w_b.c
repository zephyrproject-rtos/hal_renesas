/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_uart_w_b.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#ifndef UART_W_B_CFG_RX_ENABLE
 #define UART_W_B_CFG_RX_ENABLE                    (1)
#endif
#ifndef UART_W_B_CFG_TX_ENABLE
 #define UART_W_B_CFG_TX_ENABLE                    (1)
#endif

/* Number of divisors in the data table used for baud rate calculation. */
#define UART_W_B_NUM_DIVISORS_ASYNC_LPCLK          (14U)
#define UART_W_B_NUM_DIVISORS_ASYNC_HPCLK          (16U)

/* No limit to the number of bytes to read or write if DTC or DMAC is not used. */
#define UART_W_B_MAX_READ_WRITE_NO_TRANSFER_API    (0xFFFFFFFFU)

/* Mask of invalid data bits in 9-bit mode. */
#define UART_W_B_ALIGN_2_BYTES                     (0x1U)

/* "UART" in ASCII.  Used to determine if the control block is open. */
#define UART_W_B_OPEN                              (0x55415254U)

#define UART_W_B_REG_SIZE                          (UART2_BASE - UART_BASE)

#if UART_W_B_CFG_DTC_SUPPORTED
 #define UART_W_B_MAX_TRANSFER_BYTES               (0x10000U)
#elif UART_W_B_CFG_DMA_SUPPORTED
 #define UART_W_B_MAX_TRANSFER_BYTES               (0xFFFFU)
#endif

#define UART_W_B_RX_TRANSFER_SETTINGS              ((TRANSFER_MODE_NORMAL << TRANSFER_SETTINGS_MODE_BITS) |         \
                                                    (TRANSFER_SIZE_1_BYTE << TRANSFER_SETTINGS_SIZE_BITS) |         \
                                                    (TRANSFER_ADDR_MODE_FIXED << TRANSFER_SETTINGS_SRC_ADDR_BITS) | \
                                                    (TRANSFER_IRQ_END << TRANSFER_SETTINGS_IRQ_BITS) |              \
                                                    (TRANSFER_ADDR_MODE_INCREMENTED <<                              \
                                                     TRANSFER_SETTINGS_DEST_ADDR_BITS))
#define UART_W_B_TX_TRANSFER_SETTINGS              ((TRANSFER_MODE_NORMAL << TRANSFER_SETTINGS_MODE_BITS) | \
                                                    (TRANSFER_SIZE_1_BYTE << TRANSFER_SETTINGS_SIZE_BITS) | \
                                                    (TRANSFER_ADDR_MODE_INCREMENTED <<                      \
                                                     TRANSFER_SETTINGS_SRC_ADDR_BITS) |                     \
                                                    (TRANSFER_IRQ_END << TRANSFER_SETTINGS_IRQ_BITS) |      \
                                                    (TRANSFER_ADDR_MODE_FIXED << TRANSFER_SETTINGS_DEST_ADDR_BITS))

#define UART_W_B_HALF_BYTE_MASK                    (0xF)
#define UART_W_B_BYTE_MASK                         (0xFF)

#define UART_W_B_FREQ_128MHZ                       (128000000)
#define UART_W_B_FREQ_64MHZ                        (64000000)
#define UART_W_B_FREQ_32MHZ                        (32000000)

/***********************************************************************************************************************
 * Private constants
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * uart_w_b_prv_ns_callback)(uart_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile uart_w_b_prv_ns_callback)(uart_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

#if UART_W_B_CFG_PARAM_CHECKING_ENABLE

static fsp_err_t r_uart_w_b_read_write_param_check(uart_w_b_instance_ctrl_t const * const p_ctrl,
                                                   uint8_t const * const                  p_addr,
                                                   uint32_t const                         bytes);

#endif

static void r_uart_w_b_config_set(uart_w_b_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg);

#if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
static fsp_err_t r_uart_w_b_transfer_configure(uart_w_b_instance_ctrl_t * const p_ctrl,
                                               transfer_instance_t const      * p_transfer,
                                               uint32_t                       * p_transfer_reg,
                                               uint32_t                         address);

static fsp_err_t r_uart_w_b_transfer_open(uart_w_b_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg);
static void      r_uart_w_b_transfer_close(uart_w_b_instance_ctrl_t * p_ctrl);

#endif

static void r_uart_w_b_clk_sel_set(UART2_Type * p_uart_reg, uart_w_b_baud_setting_t const * const p_baud_setting);
static void r_uart_w_b_baud_set(UART2_Type * p_uart_reg, uart_w_b_baud_setting_t const * const p_baud_setting);
static void r_uart_w_b_call_callback(uart_w_b_instance_ctrl_t * p_ctrl, uint32_t data, uart_event_t event);

#if UART_W_B_CFG_FIFO_SUPPORT
static void r_uart_w_b_fifo_cfg(uart_w_b_instance_ctrl_t * const p_ctrl);

#endif

static void r_uart_w_b_irq_cfg(uart_w_b_instance_ctrl_t * const p_ctrl, uint8_t const ipl, IRQn_Type const p_irq);

static void r_uart_w_b_irqs_cfg(uart_w_b_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg);

#if (UART_W_B_CFG_RX_ENABLE)
static void r_uart_w_b_rxi_handler(uart_w_b_instance_ctrl_t * const p_ctrl);
static void r_uart_w_b_rx_timeout_handler(uart_w_b_instance_ctrl_t * const p_ctrl);

static void         r_uart_w_b_error_handler(uart_w_b_instance_ctrl_t * const p_ctrl);
static uart_event_t r_uart_w_b_lsr_to_event(uint32_t lsr);

void uart_w_b_rx_ded_isr(void);

#endif

#if (UART_W_B_CFG_TX_ENABLE)
static void r_uart_w_b_txi_handler(uart_w_b_instance_ctrl_t * const p_ctrl);

void uart_w_b_tei_isr(void);

void uart_w_b_tx_ded_isr(void);

#endif

#if UART_W_B_CFG_DMA_SUPPORTED
extern void uart_w_b_dma_cb_tx(uart_w_b_instance_ctrl_t * p_ctrl);
extern void uart_w_b_dma_cb_rx(uart_w_b_instance_ctrl_t * p_ctrl);

#endif

void uart_w_b_gen_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* Name of module used by error logger macro */
#if BSP_CFG_ERROR_LOG != 0
static const char g_module_name[] = "uart_w_b";
#endif

/* UART_W_B HAL API mapping for UART interface */
const uart_api_t g_uart_on_uart_w_b =
{
    .open               = R_UART_W_B_Open,
    .close              = R_UART_W_B_Close,
    .write              = R_UART_W_B_Write,
    .read               = R_UART_W_B_Read,
    .infoGet            = R_UART_W_B_InfoGet,
    .baudSet            = R_UART_W_B_BaudSet,
    .communicationAbort = R_UART_W_B_Abort,
    .callbackSet        = R_UART_W_B_CallbackSet,
    .readStop           = R_UART_W_B_ReadStop,
};

/*******************************************************************************************************************//**
 * @addtogroup UART_W_B
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configures the UART_W_B driver based on the input configurations.  If reception is enabled at compile time,
 * reception is enabled at the end of this function. Implements @ref uart_api_t::open.
 *
 * @param[out] p_api_ctrl                  Pointer to the instance control structure.
 * @param[in]  p_cfg                       Configuration structure which contains all the user provided configurations.
 *
 * @retval  FSP_SUCCESS                    Channel opened successfully.
 * @retval  FSP_ERR_ASSERTION              Pointer to UART_W_B control block or configuration structure is NULL.
 * @retval  FSP_ERR_IP_CHANNEL_NOT_PRESENT The requested channel does not exist on this MCU.
 * @retval  FSP_ERR_INVALID_ARGUMENT       Flow control is enabled but flow control pin is not defined or selected
 *                                         channel does not support "Hardware CTS and Hardware RTS" flow control.
 * @retval  FSP_ERR_ALREADY_OPEN           Control block has already been opened or channel is being used by another
 *                                         instance. Call close() then open() to reconfigure.
 *
 * @return                       See @ref RENESAS_ERROR_CODES or functions called by this function for other possible
 *                               return codes. This function calls:
 *                                   * @ref transfer_api_t::open
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_Open (uart_ctrl_t * const p_api_ctrl, uart_cfg_t const * const p_cfg)
{
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) p_api_ctrl;

#if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters. */
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_cfg);

    FSP_ASSERT(p_cfg->p_extend);
    FSP_ASSERT(((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->p_baud_setting);
    FSP_ERROR_RETURN(3 >= (((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->rx_fifo_trigger), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(3 >= (((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->tx_fifo_trigger), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(bsp_pd_is_up_check(BSP_PD_COM), FSP_ERR_INVALID_HW_CONDITION);
    FSP_ERROR_RETURN(UART_W_B_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Make sure this channel exists. */
    FSP_ERROR_RETURN(BSP_FEATURE_UART_CHANNEL_MAX > p_cfg->channel, FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    /* If iso7816 mode is already opened by r_smci_w, UART3 cannot be used. */
    if ((2 == p_cfg->channel) && (1 == UART3->UART3_CONFIG_REG_b.ISO7816_ENABLE))
    {
        FSP_RETURN(FSP_ERR_INVALID_MODE);
    }

 #if (UART_W_B_CFG_FLOW_CONTROL_SUPPORT)

    /* Only UART2 ,UART3 & UART4 support auto flow control */
    if (((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->flow_control)
    {
        /* Only UART2 ,UART3 & UART4 support auto flow control */
        FSP_ERROR_RETURN(0 == ((1 << p_cfg->channel) & BSP_FEATURE_UART_CHANNELS_WITHOUT_FLOW_CTRL),
                         FSP_ERR_INVALID_ARGUMENT);
    }
 #endif
 #if UART_W_B_CFG_DTC_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        FSP_ASSERT(p_cfg->rxi_irq >= 0);
    }

    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        FSP_ASSERT(p_cfg->txi_irq >= 0);
    }
 #endif
    FSP_ASSERT(p_cfg->tei_irq >= 0);
    FSP_ASSERT(((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->gen_irq >= 0);
#endif

    p_ctrl->p_reg = ((UART2_Type *) (UART_BASE + (UART_W_B_REG_SIZE * p_cfg->channel)));

#if UART_W_B_CFG_FIFO_SUPPORT
    p_ctrl->fifo_depth = BSP_FEATURE_UART_FIFO_DEPTH;
#else
#if UART_CFG_FLOW_CONTROL_SUPPORT
    if (((uart_extended_cfg_t *) p_cfg->p_extend)->flow_control) {
        p_ctrl->fifo_depth = BSP_FEATURE_UART_FIFO_DEPTH;
    } else  {
        p_ctrl->fifo_depth = 0U;
    }
#else
    p_ctrl->fifo_depth = 0U;
#endif /* UART_CFG_FLOW_CONTROL_SUPPORT */
#endif /* UART_CFG_FIFO_SUPPORT */

    p_ctrl->p_cfg = p_cfg;

    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;

    p_ctrl->data_bytes = 1U;

    /* Configure the interrupts. */
    r_uart_w_b_irqs_cfg(p_ctrl, p_cfg);

#if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED

    /* Configure the transfer interface for transmission and reception if provided. */
    fsp_err_t err = r_uart_w_b_transfer_open(p_ctrl, p_cfg);

    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    /* Enable the UART_W_B channel and reset the registers to their initial state. */
    uint32_t srr_reg_val = p_ctrl->p_reg->UART2_SRR_REG;

    /* Tx fifo flush */
    FSP_REG_VAR_FIELD_SET(UART2, UART2_SRR_REG, UART_XFR, srr_reg_val, 1);

    /* Rx fifo flush */
    FSP_REG_VAR_FIELD_SET(UART2, UART2_SRR_REG, UART_RFR, srr_reg_val, 1);
    p_ctrl->p_reg->UART2_SRR_REG = srr_reg_val;

    /* Read also RBR in order to make sure that the character timeout IRQ (if any) is cleared. */
    uint32_t data = p_ctrl->p_reg->UART2_RBR_THR_DLL_REG;
    (void) data;

    /* Select the baud clock source (CLK_SEL in CRG_COM) while the UART baud clock is still disabled.
     * This must be done before setting UART_ENABLE because changing CLK_SEL while UART_ENABLE is already
     * set causes a clock glitch on the UART peripheral that corrupts subsequent DLAB/DLL/DLH register
     * writes, leaving the baud rate divisors unchanged from their reset values. */
    r_uart_w_b_clk_sel_set(p_ctrl->p_reg, ((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->p_baud_setting);

    if (0 == p_cfg->channel)
    {
        CRG_COM->SET_CLK_COM_REG = CRG_COM_SET_CLK_COM_REG_UART_ENABLE_Msk;
    }
    else if (1 == p_cfg->channel)
    {
        CRG_COM->SET_CLK_COM_REG = CRG_COM_SET_CLK_COM_REG_UART2_ENABLE_Msk;
    }
    else if (2 == p_cfg->channel)
    {
        CRG_COM->SET_CLK_COM_REG = CRG_COM_SET_CLK_COM_REG_UART3_ENABLE_Msk;
    }

#if !BSP_MCU_GROUP_RA6B2
    else if (3 == p_cfg->channel)
    {
        CRG_COM->SET_CLK_COM_REG = CRG_COM_SET_CLK_COM_REG_UART4_ENABLE_Msk;
    }
#endif
    else
    {
        /* No more channel number is available */
    }

    /* Read UART_USR_REG to clear any pending busy interrupt */
    uint32_t usr_val = p_ctrl->p_reg->UART2_USR_REG_b.UART_TFE;
    (void) usr_val;

    /* Set the UART_W_B configuration settings provided in ::uart_cfg_t and ::uart_w_b_extended_cfg_t.
     * This must be done after UART_ENABLE is set so that the UART baud clock is running when the
     * DLAB/DLL/DLH/DLF and LCR registers are written. CLK_SEL was already set above, so the
     * r_uart_w_b_baud_set() call within config_set writes CLK_SEL to the same value (no-op),
     * preventing any clock glitch. */
    r_uart_w_b_config_set(p_ctrl, p_cfg);
#if UART_W_B_CFG_FLOW_CONTROL_SUPPORT
    p_ctrl->p_reg->UART2_MCR_REG_b.UART_AFCE = ((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->flow_control;
    p_ctrl->p_reg->UART2_MCR_REG_b.UART_RTS  = ((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->flow_control;
#endif
    p_ctrl->p_tx_src      = NULL;
    p_ctrl->tx_src_bytes  = 0U;
    p_ctrl->p_rx_dest     = NULL;
    p_ctrl->rx_dest_bytes = 0;

    R_BSP_IrqEnable(((uart_w_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend)->gen_irq);

#if (UART_W_B_CFG_RX_ENABLE)

    /* NOTE: In DTC mode Rx-dedicated irq is enabled in R_UART_W_B_Read() through NVIC */
    /* Enable Rx-dedicated mask to specifically notify ELC for out of band reception events */
    p_ctrl->p_reg->UART2_MASK_REG_b.UART_RX_IRQ_MASK = 1;

    /* Enable receiver interrupts through generic IRQ to serve out of band reception */
    p_ctrl->p_reg->UART2_IER_DLH_REG_b.ERBFI_DLH0 = 1;
#endif

#if (UART_W_B_CFG_TX_ENABLE)
 #if UART_W_B_CFG_DTC_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        R_BSP_IrqEnable(p_ctrl->p_cfg->txi_irq);
    }
 #endif
    R_BSP_IrqEnable(p_ctrl->p_cfg->tei_irq);
#endif

    p_ctrl->open = UART_W_B_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Aborts any in progress transfers. Disables interrupts, receiver, and transmitter.  Closes lower level transfer
 * drivers if used. Removes power. Implements @ref uart_api_t::close.
 *
 * @param[in] p_api_ctrl             Pointer to the instance control structure.
 *
 * @retval  FSP_SUCCESS              Channel successfully closed.
 * @retval  FSP_ERR_ASSERTION        Pointer to UART_W_B control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN         The control block has not been opened
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_Close (uart_ctrl_t * const p_api_ctrl)
{
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) p_api_ctrl;
#if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(UART_W_B_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Mark the channel not open so other APIs cannot use it. */
    p_ctrl->open = 0U;

    /* Disable receiver, transmitter and line status interrupts.
     * Also disable baud clock.*/
    p_ctrl->p_reg->UART2_IER_DLH_REG = 0;
    p_ctrl->p_reg->UART2_MASK_REG    = 0;

    /* Reset the controller */
    p_ctrl->p_reg->UART2_SRR_REG_b.UART_UR = 1;
    p_ctrl->p_reg->UART2_SRR_REG_b.UART_UR = 0;

    if (0 == p_ctrl->p_cfg->channel)
    {
        CRG_COM->RESET_CLK_COM_REG = CRG_COM_RESET_CLK_COM_REG_UART_ENABLE_Msk;
    }
    else if (1 == p_ctrl->p_cfg->channel)
    {
        CRG_COM->RESET_CLK_COM_REG = CRG_COM_RESET_CLK_COM_REG_UART2_ENABLE_Msk;
    }
    else if (2 == p_ctrl->p_cfg->channel)
    {
        CRG_COM->RESET_CLK_COM_REG = CRG_COM_RESET_CLK_COM_REG_UART3_ENABLE_Msk;
    }

#if !BSP_MCU_GROUP_RA6B2
    else if (3 == p_ctrl->p_cfg->channel)
    {
        CRG_COM->RESET_CLK_COM_REG = CRG_COM_RESET_CLK_COM_REG_UART4_ENABLE_Msk;
    }
#endif
    else
    {
        /* No more channel number is available */
    }

    R_BSP_IrqDisable(((uart_w_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend)->gen_irq);

#if (UART_W_B_CFG_RX_ENABLE)
 #if UART_W_B_CFG_DTC_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        /* If reception is enabled at build time, disable reception irqs. */
        R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);
    }
 #endif
#endif
#if (UART_W_B_CFG_TX_ENABLE)
    R_BSP_IrqDisable(p_ctrl->p_cfg->tei_irq);
 #if UART_W_B_CFG_DTC_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        /* If transmission is enabled at build time, disable transmission irqs. */
        R_BSP_IrqDisable(p_ctrl->p_cfg->txi_irq);
    }
 #endif
#endif

#if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED

    /* Close the lower level transfer instances. */
    r_uart_w_b_transfer_close(p_ctrl);
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Receives user specified number of bytes into destination buffer pointer. Implements @ref uart_api_t::read
 *
 * @param[in] p_api_ctrl                 Pointer to the instance control structure.
 * @param[in] p_dest                     Pointer to the destination buffer.
 * @param[in] bytes                      Number of bytes to read.
 *
 * @retval  FSP_SUCCESS                  Data reception successfully ends.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART_W_B control block is NULL.
 *                                       Number of transfers outside the max or min boundary when transfer instance used
 * @retval  FSP_ERR_INVALID_ARGUMENT     Destination address or data size is not valid for 9-bit mode.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened
 * @retval  FSP_ERR_IN_USE               A previous read operation is still in progress.
 * @retval  FSP_ERR_UNSUPPORTED          UART_W_B_CFG_RX_ENABLE is set to 0
 *
 * @return                       See @ref RENESAS_ERROR_CODES or functions called by this function for other possible
 *                               return codes. This function calls:
 *                                   * @ref transfer_api_t::reset
 *
 * @note If 9-bit data length is specified at R_UART_W_B_Open call, p_dest must be aligned 16-bit boundary.
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_Read (uart_ctrl_t * const p_api_ctrl, uint8_t * const p_dest, uint32_t const bytes)
{
#if (UART_W_B_CFG_RX_ENABLE)
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t err = FSP_SUCCESS;
 #if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
    uint32_t num_transfers;
 #endif

 #if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    err = r_uart_w_b_read_write_param_check(p_ctrl, p_dest, bytes);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ERROR_RETURN(0U == p_ctrl->rx_dest_bytes, FSP_ERR_IN_USE);
  #if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
    num_transfers = bytes >> (p_ctrl->data_bytes - 1);
    FSP_ASSERT(num_transfers <= UART_W_B_MAX_TRANSFER_BYTES);
  #endif
 #else
  #if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
    num_transfers = bytes >> (p_ctrl->data_bytes - 1);
  #endif
 #endif

    /* Disable Rx-generic and line-status interrupts before applying read configuration */
    uint32_t ier_reg_val = p_ctrl->p_reg->UART2_IER_DLH_REG;
    FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, ERBFI_DLH0, ier_reg_val, 0);
    FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, ELSI_DLH2, ier_reg_val, 0);
    p_ctrl->p_reg->UART2_IER_DLH_REG                 = ier_reg_val;
    p_ctrl->p_reg->UART2_MASK_REG_b.UART_RX_IRQ_MASK = 0;

    /* Store the destination address and size in control block */
    p_ctrl->p_rx_dest     = p_dest;
    p_ctrl->rx_dest_bytes = bytes;

 #if UART_W_B_CFG_DTC_SUPPORTED

    /* Configure transfer instance to receive the requested number of bytes if transfer is used for reception. */
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        err =
            p_ctrl->p_cfg->p_transfer_rx->p_api->reset(p_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                       NULL,
                                                       (void *) p_ctrl->p_rx_dest,
                                                       (uint16_t) num_transfers);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

        /* Enable Rx-dedicated interrupts through NVIC, mask is always open */
        R_BSP_IrqEnable(p_ctrl->p_cfg->rxi_irq);
    }

 #elif UART_W_B_CFG_DMA_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        /* Reset receiver FIFO */
        p_ctrl->p_reg->UART2_SRR_REG_b.UART_RFR = 1;
        FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->UART2_SRR_REG_b.UART_RFR, 0U);

        /* Clear DMA request */
        p_ctrl->p_reg->UART2_DMASA_REG_b.UART_DMASA = 1;

        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_dest = (uint8_t *) p_ctrl->p_rx_dest;
        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->length = (uint16_t) num_transfers;

        err = p_ctrl->p_cfg->p_transfer_rx->p_api->reconfigure(p_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                               p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        err = p_ctrl->p_cfg->p_transfer_rx->p_api->enable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);

        /* Enable line status interrupts for error handling */
        p_ctrl->p_reg->UART2_IER_DLH_REG_b.ELSI_DLH2 = 1;

        /* Restore Rx-dedicated interrupts after read configuration has finished */
        p_ctrl->p_reg->UART2_MASK_REG_b.UART_RX_IRQ_MASK = 1;

        return err;
    }
 #endif

    /* Restore Rx-dedicated masks after read configuration has finished:
     * for DTC required for triggering
     * for non transfer mode,needed for notifying ELC for out of band reception events */
    p_ctrl->p_reg->UART2_MASK_REG_b.UART_RX_IRQ_MASK = 1;

    /* For DTC and non transfer mode */
    ier_reg_val = p_ctrl->p_reg->UART2_IER_DLH_REG;

    /* Enable Rx-generic irqs */
    FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, ERBFI_DLH0, ier_reg_val, 1);

    /* Enable line status IRQs for error handling */
    FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, ELSI_DLH2, ier_reg_val, 1);
    p_ctrl->p_reg->UART2_IER_DLH_REG = ier_reg_val;

    return err;
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_dest);
    FSP_PARAMETER_NOT_USED(bytes);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Transmits user specified number of bytes from the source buffer pointer. Implements @ref uart_api_t::write
 *
 * @param[in] p_api_ctrl                 Pointer to the instance control structure.
 * @param[in] p_src                      Pointer to the source buffer.
 * @param[in] bytes                      Number of bytes to write.
 *
 * @retval  FSP_SUCCESS                  Data transmission finished successfully.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART_W_B control block is NULL.
 *                                       Number of transfers outside the max or min boundary when transfer instance used
 * @retval  FSP_ERR_INVALID_ARGUMENT     Source address or data size is not valid for 9-bit mode.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened
 * @retval  FSP_ERR_IN_USE               A UART_W_B transmission is in progress
 * @retval  FSP_ERR_UNSUPPORTED          UART_W_B_CFG_TX_ENABLE is set to 0
 *
 * @return                       See @ref RENESAS_ERROR_CODES or functions called by this function for other possible
 *                               return codes. This function calls:
 *                                   * @ref transfer_api_t::reset
 *
 * @note If 9-bit data length is specified at R_UART_W_B_Open call, p_src must be aligned on a 16-bit boundary.
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_Write (uart_ctrl_t * const p_api_ctrl, uint8_t const * const p_src, uint32_t const bytes)
{
#if (UART_W_B_CFG_TX_ENABLE)
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t err = FSP_SUCCESS;
 #if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
    uint32_t num_transfers;
 #endif

 #if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    err = r_uart_w_b_read_write_param_check(p_ctrl, p_src, bytes);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ERROR_RETURN(0U == p_ctrl->tx_src_bytes, FSP_ERR_IN_USE);
  #if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
    num_transfers = bytes >> (p_ctrl->data_bytes - 1);
    FSP_ASSERT(num_transfers <= UART_W_B_MAX_TRANSFER_BYTES);
  #endif
 #else
  #if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
    num_transfers = bytes >> (p_ctrl->data_bytes - 1);
  #endif
 #endif

    /* Disable Transmit interrupts */
    uint32_t ier_reg_val = p_ctrl->p_reg->UART2_IER_DLH_REG;
    FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, ETBEI_DLH1, ier_reg_val, 0);
    FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, PTIME_DLH7, ier_reg_val, 0);
    p_ctrl->p_reg->UART2_IER_DLH_REG = ier_reg_val;

    uint32_t irq_mask_reg_val = p_ctrl->p_reg->UART2_MASK_REG;

    FSP_REG_VAR_FIELD_SET(UART2, UART2_MASK_REG, UART_TXE_IRQ_MASK, irq_mask_reg_val, 0);
    FSP_REG_VAR_FIELD_SET(UART2, UART2_MASK_REG, UART_TXR_IRQ_MASK, irq_mask_reg_val, 0);

    p_ctrl->p_reg->UART2_MASK_REG = irq_mask_reg_val;

    /* Store the source address and size in control block */
    p_ctrl->p_tx_src     = p_src;
    p_ctrl->tx_src_bytes = bytes;

 #if UART_W_B_CFG_DTC_SUPPORTED

    /* If a transfer instance is used for transmission, reset the transfer instance to transmit the requested
     * data. */
    if ((NULL != p_ctrl->p_cfg->p_transfer_tx) && p_ctrl->tx_src_bytes)
    {
        err = p_ctrl->p_cfg->p_transfer_tx->p_api->reset(p_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                         (void const *) p_ctrl->p_tx_src,
                                                         NULL,
                                                         (uint16_t) num_transfers);
        p_ctrl->p_reg->UART2_MASK_REG_b.UART_TXE_IRQ_MASK = 1;

        return err;
    }

 #elif UART_W_B_CFG_DMA_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        /* Clear DMA request */
        p_ctrl->p_reg->UART2_DMASA_REG_b.UART_DMASA = 1;

        p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->p_src  = (uint8_t *) p_ctrl->p_tx_src;
        p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->length = (uint16_t) num_transfers;

        /* Enable Tx-dedicated irq to notify ELC */
        p_ctrl->p_reg->UART2_MASK_REG_b.UART_TXE_IRQ_MASK = 1;

        err = p_ctrl->p_cfg->p_transfer_tx->p_api->reconfigure(p_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                               p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        err = p_ctrl->p_cfg->p_transfer_tx->p_api->enable(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);

        return err;
    }
 #endif

    /* non transfer mode */

    /* Enable Tx-dedicated irq to notify ELC */

    p_ctrl->p_reg->UART2_MASK_REG_b.UART_TXE_IRQ_MASK = 1;

    /* Enable Transmit interrupts in non DTC mode*/
    ier_reg_val = p_ctrl->p_reg->UART2_IER_DLH_REG;
    FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, ETBEI_DLH1, ier_reg_val, 1);
    FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, PTIME_DLH7, ier_reg_val, 1);
    p_ctrl->p_reg->UART2_IER_DLH_REG = ier_reg_val;

    err = FSP_SUCCESS;

    return err;
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_src);
    FSP_PARAMETER_NOT_USED(bytes);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements uart_api_t::callbackSet.
 *
 * @param[in] p_api_ctrl                 Pointer to the instance control structure.
 * @param[in] p_callback                 Pointer to callback.
 * @param[in] p_context                  Pointer to context to be passed into callback function.
 * @param[in] p_callback_memory          Pointer to non-secure memory.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_CallbackSet (uart_ctrl_t * const          p_api_ctrl,
                                  void (                     * p_callback)(uart_callback_args_t *),
                                  void * const                 p_context,
                                  uart_callback_args_t * const p_callback_memory)
{
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) p_api_ctrl;

#if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(UART_W_B_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if UART_W_B_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    uart_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                       CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif
#endif

    /* Store callback and context */
#if BSP_TZ_SECURE_BUILD
    p_ctrl->p_callback = callback_is_secure ? p_callback :
                         (void (*)(uart_callback_args_t *))cmse_nsfptr_create(p_callback);
#else
    p_ctrl->p_callback = p_callback;
#endif
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the baud rate using the clock selected in Open. p_baud_setting is a pointer to a uart_w_b_baud_setting_t
 * structure.Implements @ref uart_api_t::baudSet.
 *
 * @param[in] p_api_ctrl                 Pointer to the instance control structure.
 * @param[in] p_baud_setting             Register settings for a desired baud rate.
 *
 * @warning This terminates any in-progress transmission.
 *
 * @retval  FSP_SUCCESS                  Baud rate was successfully changed.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART_W_B control block is NULL or the UART_W_B is not configured to use the
 *                                       internal clock.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_BaudSet (uart_ctrl_t * const p_api_ctrl, void const * const p_baud_setting)
{
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) p_api_ctrl;

#if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(UART_W_B_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store ier,lcr and mask reg values to be restore after baud set */
    uint32_t previous_ier_reg      = p_ctrl->p_reg->UART2_IER_DLH_REG;
    uint32_t previous_lcr_reg      = p_ctrl->p_reg->UART2_LCR_REG;
    uint32_t previous_mask_reg_val = p_ctrl->p_reg->UART2_MASK_REG;

    /* Disables transmitter and receiver. This terminates any in-progress transmission. */
    p_ctrl->p_reg->UART2_IER_DLH_REG = 0;
    p_ctrl->p_reg->UART2_MASK_REG    = 0;

    p_ctrl->p_tx_src  = NULL;
    p_ctrl->p_rx_dest = NULL;

    /* Apply new baud rate register settings. */
    r_uart_w_b_baud_set(p_ctrl->p_reg, p_baud_setting);

    /* Restore previous ier mask and lcr register values */
    p_ctrl->p_reg->UART2_IER_DLH_REG = previous_ier_reg;
    p_ctrl->p_reg->UART2_LCR_REG     = previous_lcr_reg;
    p_ctrl->p_reg->UART2_MASK_REG    = previous_mask_reg_val;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provides the driver information, including the maximum number of bytes that can be received or transmitted
 * at a time.Implements @ref uart_api_t::infoGet.
 *
 * @param[in] p_api_ctrl                 Pointer to the instance control structure.
 * @param[in] p_info                     Maximum number of byte information .
 *
 * @retval  FSP_SUCCESS                  Information stored in provided p_info.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART_W_B control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_InfoGet (uart_ctrl_t * const p_api_ctrl, uart_info_t * const p_info)
{
#if UART_W_B_CFG_PARAM_CHECKING_ENABLE || UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) p_api_ctrl;
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
#endif

#if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_info);
    FSP_ERROR_RETURN(UART_W_B_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_info->read_bytes_max  = UART_W_B_MAX_READ_WRITE_NO_TRANSFER_API;
    p_info->write_bytes_max = UART_W_B_MAX_READ_WRITE_NO_TRANSFER_API;

#if (UART_W_B_CFG_RX_ENABLE)

    /* Store number of bytes that can be read at a time. */
 #if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        p_info->read_bytes_max = UART_W_B_MAX_TRANSFER_BYTES;
    }
 #endif
#endif

#if (UART_W_B_CFG_TX_ENABLE)

    /* Store number of bytes that can be written at a time. */
 #if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        p_info->write_bytes_max = UART_W_B_MAX_TRANSFER_BYTES;
    }
 #endif
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provides API to abort ongoing transfer. Transmission is aborted after the current character is transmitted.
 * Reception is still enabled after abort(). Any characters received after abort() and before the transfer
 * is reset in the next call to read(), will arrive via the callback function with event UART_W_B_EVENT_RX_CHAR.
 * Implements @ref uart_api_t::communicationAbort.
 *
 * @param[in] p_api_ctrl                 Pointer to the instance control structure.
 * @param[in] communication_to_abort     Abort direction .
 *
 * @retval  FSP_SUCCESS                  UART_W_B transaction aborted successfully.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART_W_B control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_UNSUPPORTED          The requested Abort direction is unsupported.
 *
 * @return                       See @ref RENESAS_ERROR_CODES or functions called by this function for other possible
 *                               return codes. This function calls:
 *                                   * @ref transfer_api_t::disable
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_Abort (uart_ctrl_t * const p_api_ctrl, uart_dir_t communication_to_abort)
{
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t err = FSP_ERR_UNSUPPORTED;

#if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(UART_W_B_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if (UART_W_B_CFG_TX_ENABLE)
    if (UART_DIR_TX & communication_to_abort)
    {
        err = FSP_SUCCESS;

        /* Disable Tx-dedicated masks for all modes */
        uint32_t irq_mask_reg_val = p_ctrl->p_reg->UART2_MASK_REG;

        FSP_REG_VAR_FIELD_SET(UART2, UART2_MASK_REG, UART_TXE_IRQ_MASK, irq_mask_reg_val, 0);
        FSP_REG_VAR_FIELD_SET(UART2, UART2_MASK_REG, UART_TXR_IRQ_MASK, irq_mask_reg_val, 0);

        p_ctrl->p_reg->UART2_MASK_REG = irq_mask_reg_val;

 #if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
        if (NULL == p_ctrl->p_cfg->p_transfer_tx)
        {
 #endif

        /* Disable Tx-generic interrupt in non DTC/DMA mode */
        uint32_t ier_reg_val = p_ctrl->p_reg->UART2_IER_DLH_REG;
        FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, ETBEI_DLH1, ier_reg_val, 0);
        FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, PTIME_DLH7, ier_reg_val, 0);
        p_ctrl->p_reg->UART2_IER_DLH_REG = ier_reg_val;
 #if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED
    }
    else
    {
        transfer_properties_t transfer_info;

        err = p_ctrl->p_cfg->p_transfer_tx->p_api->disable(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        err = p_ctrl->p_cfg->p_transfer_tx->p_api->infoGet(p_ctrl->p_cfg->p_transfer_tx->p_ctrl, &transfer_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        p_ctrl->p_tx_src += (p_ctrl->tx_src_bytes - transfer_info.transfer_length_remaining);
    }
 #endif

 #if UART_W_B_CFG_FIFO_SUPPORT
        if (0U != p_ctrl->fifo_depth)
        {
            FSP_CRITICAL_SECTION_DEFINE;
            FSP_CRITICAL_SECTION_ENTER;
            p_ctrl->p_tx_src -= p_ctrl->p_reg->UART2_TFL_REG;

            /* Reset the transmit fifo */
            p_ctrl->p_reg->UART2_SRR_REG_b.UART_XFR = 1;
            FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->UART2_SRR_REG_b.UART_XFR, 0U);
            FSP_CRITICAL_SECTION_EXIT;
        }
 #endif
        p_ctrl->tx_src_bytes = 0U;
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
#endif
#if (UART_W_B_CFG_RX_ENABLE)
    if (UART_DIR_RX & communication_to_abort)
    {
        err = FSP_SUCCESS;

        p_ctrl->rx_dest_bytes = 0U;

 #if UART_W_B_CFG_DTC_SUPPORTED
        if (NULL != p_ctrl->p_cfg->p_transfer_rx)
        {
            err = p_ctrl->p_cfg->p_transfer_rx->p_api->disable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);

            /* In DTC mode disable Rx-dedicated irqs through NVIC */
            R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);
        }

 #elif UART_W_B_CFG_DMA_SUPPORTED
        if (NULL != p_ctrl->p_cfg->p_transfer_rx)
        {
            err = p_ctrl->p_cfg->p_transfer_rx->p_api->disable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);

            /* Restore Rx-generic irq in DMA mode for servicing out-of-band reception */
            p_ctrl->p_reg->UART2_IER_DLH_REG_b.ERBFI_DLH0 = 1;
        }
 #endif
 #if UART_W_B_CFG_FIFO_SUPPORT
        if (0U != p_ctrl->fifo_depth)
        {
            /* Reset the receive fifo */
            p_ctrl->p_reg->UART2_SRR_REG_b.UART_RFR = 1;
            FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->UART2_SRR_REG_b.UART_RFR, 0U);
        }
 #endif
    }
#endif

    return err;
}

/*******************************************************************************************************************//**
 * Provides API to abort ongoing read. Reception is still enabled after abort(). Any characters received
 * after abort() and before the transfer is reset in the next call to read(), will arrive via the callback
 * function with event UART_W_B_EVENT_RX_CHAR.
 * Implements @ref uart_api_t::readStop
 *
 * @param[in]  p_api_ctrl                Pointer to the instance control structure.
 * @param[out] remaining_bytes         Pointer to the remaining bytes.
 *
 * @retval  FSP_SUCCESS                  UART_W_B transaction aborted successfully.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART_W_B control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_UNSUPPORTED          The requested Abort direction is unsupported.
 *
 * @return                       See @ref RENESAS_ERROR_CODES or functions called by this function for other possible
 *                               return codes. This function calls:
 *                                   * @ref transfer_api_t::disable
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_ReadStop (uart_ctrl_t * const p_api_ctrl, uint32_t * remaining_bytes)
{
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) p_api_ctrl;

#if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(UART_W_B_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if (UART_W_B_CFG_RX_ENABLE)
    *remaining_bytes      = p_ctrl->rx_dest_bytes;
    p_ctrl->rx_dest_bytes = 0U;
 #if UART_W_B_CFG_DTC_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        fsp_err_t err = p_ctrl->p_cfg->p_transfer_rx->p_api->disable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

        /* Disable Rx-dedicated irqs through NVIC */
        R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);

        transfer_properties_t transfer_info;
        err = p_ctrl->p_cfg->p_transfer_rx->p_api->infoGet(p_ctrl->p_cfg->p_transfer_rx->p_ctrl, &transfer_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        *remaining_bytes = transfer_info.transfer_length_remaining;
    }
 #endif

 #if UART_W_B_CFG_DMA_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        fsp_err_t err = p_ctrl->p_cfg->p_transfer_rx->p_api->disable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

        /* Restore Rx-generic interrupts in DMA mode for out-of-band reception*/
        p_ctrl->p_reg->UART2_IER_DLH_REG_b.ERBFI_DLH0 = 1;
        transfer_properties_t transfer_info;
        err = p_ctrl->p_cfg->p_transfer_rx->p_api->infoGet(p_ctrl->p_cfg->p_transfer_rx->p_ctrl, &transfer_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        *remaining_bytes = transfer_info.transfer_length_remaining;
    }
 #endif
#else

    return FSP_ERR_UNSUPPORTED;
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Calculates baud rate register settings. Evaluates and determines the best possible settings set to the
 * baud rate related registers.
 *
 * @param[in]  baudrate                  Baud rate [bps]. For example, 19200, 57600, 115200, etc.
 * @param[out] p_baud_setting            Baud setting information stored here if successful.
 *
 * @retval     FSP_SUCCESS               Baud rate is set successfully.
 * @retval     FSP_ERR_ASSERTION         Null pointer or invalid system clock.
 * @retval     FSP_ERR_INVALID_ARGUMENT  Baud rate is '0',or invalid.
 *
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_BaudCalculate (uart_w_b_baud_rate_t baudrate, uart_w_b_baud_setting_t * const p_baud_setting)
{
#if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_baud_setting);
    FSP_ERROR_RETURN((0U != baudrate), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((UART_W_B_BAUD_INVALID != baudrate), FSP_ERR_INVALID_ARGUMENT);
#endif

    fsp_err_t err = FSP_SUCCESS;
    uint32_t freq_hz;

    /* Baud rates up-to 2Mbps are forced to use 32MHz peripheral clock */
    if (baudrate >= UART_W_B_BAUDRATE_2000000)
    {
        p_baud_setting->uart_clk_sel_div = UART_W_B_DIVN;
        freq_hz = UART_W_B_FREQ_32MHZ;
    }
    else
    {
        p_baud_setting->uart_clk_sel_div = UART_W_B_DIV1;
        freq_hz = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_SYS_CLK);

        if (UART_W_B_BAUDRATE_3000000 == baudrate)
        {
            FSP_ASSERT((UART_W_B_FREQ_128MHZ == freq_hz) || (UART_W_B_FREQ_64MHZ == freq_hz));

            if (UART_W_B_FREQ_128MHZ == freq_hz)
            {
                baudrate = (uart_w_b_baud_rate_t) 0x0000020B;
            }
            else if (UART_W_B_FREQ_64MHZ == freq_hz)
            {
                baudrate = (uart_w_b_baud_rate_t) 0x00000105;
            }
        }
        else if (UART_W_B_BAUDRATE_6000000 == baudrate)
        {
            FSP_ASSERT(UART_W_B_FREQ_128MHZ == freq_hz);
            baudrate = (uart_w_b_baud_rate_t) 0x00000105;
        }
    }

    p_baud_setting->dlf     = UART_W_B_HALF_BYTE_MASK & baudrate;
    p_baud_setting->thr_dll = UART_W_B_BYTE_MASK & (baudrate >> 8);
    p_baud_setting->ier_dlh = UART_W_B_BYTE_MASK & (baudrate >> 16);

    return err;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup UART_W_B)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)

/*******************************************************************************************************************//**
 * Parameter error check function for read/write.
 *
 * @param[in] p_ctrl Pointer to the control block for the channel.
 * @param[in] p_addr   Pointer to the buffer.
 * @param[in] bytes  Number of bytes to read or write.
 *
 * @retval  FSP_SUCCESS              No parameter error found
 * @retval  FSP_ERR_NOT_OPEN         The control block has not been opened
 * @retval  FSP_ERR_ASSERTION        Pointer to UART_W_B control block or configuration structure is NULL
 * @retval  FSP_ERR_INVALID_ARGUMENT Address is not aligned to 2-byte boundary or size is the odd number when the data
 *                                   length is 9-bit
 **********************************************************************************************************************/
static fsp_err_t r_uart_w_b_read_write_param_check (uart_w_b_instance_ctrl_t const * const p_ctrl,
                                                    uint8_t const * const                  p_addr,
                                                    uint32_t const                         bytes)
{
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_addr);
    FSP_ASSERT(0U != bytes);
    FSP_ERROR_RETURN(UART_W_B_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);

    if (2U == p_ctrl->data_bytes)
    {
        /* Do not allow odd buffer address if data length is 9 bits. */
        FSP_ERROR_RETURN((0U == ((uint32_t) p_addr & UART_W_B_ALIGN_2_BYTES)), FSP_ERR_INVALID_ARGUMENT);

        /* Do not allow odd number of data bytes if data length is 9 bits. */
        FSP_ERROR_RETURN(0U == (bytes % 2U), FSP_ERR_INVALID_ARGUMENT);
    }

    return FSP_SUCCESS;
}

#endif
#if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED

/*******************************************************************************************************************//**
 * Subroutine to apply common UART_W_B transfer settings.
 *
 * @param[in]  p_ctrl             Pointer to UART_W_B specific configuration structure.
 * @param[in]  p_transfer         Pointer to transfer instance to configure.
 * @param[in]  p_transfer_reg     Source or destination pointer passed.
 * @param[in]  uart_buffer_address Buffer address for source or destination.
 *
 * @retval     FSP_SUCCESS        UART_W_B transfer drivers successfully configured
 * @retval     FSP_ERR_ASSERTION  Invalid pointer
 **********************************************************************************************************************/
static fsp_err_t r_uart_w_b_transfer_configure (uart_w_b_instance_ctrl_t * const p_ctrl,
                                                transfer_instance_t const      * p_transfer,
                                                uint32_t                       * p_transfer_reg,
                                                uint32_t                         uart_buffer_address)
{
    /* Configure the transfer instance, if enabled. */
 #if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_transfer->p_api);
    FSP_ASSERT(NULL != p_transfer->p_ctrl);
    FSP_ASSERT(NULL != p_transfer->p_cfg);
    FSP_ASSERT(NULL != p_transfer->p_cfg->p_info);
    FSP_ASSERT(NULL != p_transfer->p_cfg->p_extend);
 #endif
    FSP_PARAMETER_NOT_USED(p_ctrl);

    /* Casting for compatibility with 7 or 8 bit mode. */
    *p_transfer_reg = uart_buffer_address;

    fsp_err_t err = p_transfer->p_api->open(p_transfer->p_ctrl, p_transfer->p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return FSP_SUCCESS;
}

#endif

#if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED

/*******************************************************************************************************************//**
 * Configures UART_W_B related transfer drivers (if enabled).
 *
 * @param[in]     p_ctrl  Pointer to UART_W_B control structure
 * @param[in]     p_cfg   Pointer to UART_W_B specific configuration structure
 *
 * @retval        FSP_SUCCESS        UART_W_B transfer drivers successfully configured
 * @retval        FSP_ERR_ASSERTION  Invalid pointer or required interrupt not enabled in vector table
 *
 * @return                       See @ref RENESAS_ERROR_CODES or functions called by this function for other possible
 *                               return codes. This function calls:
 *                                   * @ref transfer_api_t::open
 **********************************************************************************************************************/
static fsp_err_t r_uart_w_b_transfer_open (uart_w_b_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;

 #if (UART_W_B_CFG_RX_ENABLE)

    /* If a transfer instance is used for reception, apply UART_W_B specific settings and open the transfer instance. */
    if (NULL != p_cfg->p_transfer_rx)
    {
        transfer_info_t * p_info = p_cfg->p_transfer_rx->p_cfg->p_info;

        p_info->transfer_settings_word = UART_W_B_RX_TRANSFER_SETTINGS;

        err =
            r_uart_w_b_transfer_configure(p_ctrl, p_cfg->p_transfer_rx, (uint32_t *) &p_info->p_src,
                                          (uint32_t) &(p_ctrl->p_reg->UART2_RBR_THR_DLL_REG));
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
 #endif
 #if (UART_W_B_CFG_TX_ENABLE)

    /* If a transfer instance is used for transmission, apply UART_W_B specific settings and open the transfer instance. */
    if (NULL != p_cfg->p_transfer_tx)
    {
        transfer_info_t * p_info = p_cfg->p_transfer_tx->p_cfg->p_info;

        p_info->transfer_settings_word = UART_W_B_TX_TRANSFER_SETTINGS;

        err = r_uart_w_b_transfer_configure(p_ctrl,
                                            p_cfg->p_transfer_tx,
                                            (uint32_t *) &p_info->p_dest,
                                            (uint32_t) &p_ctrl->p_reg->UART2_RBR_THR_DLL_REG);

  #if (UART_W_B_CFG_RX_ENABLE)
        if ((err != FSP_SUCCESS) && (NULL != p_cfg->p_transfer_rx))
        {
            p_cfg->p_transfer_rx->p_api->close(p_cfg->p_transfer_rx->p_ctrl);
        }
  #endif
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
 #endif

    return err;
}

#endif

/*******************************************************************************************************************//**
 * Configures UART_W_B related registers based on user configurations.
 *
 * @param[in]     p_ctrl  Pointer to UART_W_B control structure
 * @param[in]     p_cfg   Pointer to UART_W_B specific configuration structure
 **********************************************************************************************************************/
static void r_uart_w_b_config_set (uart_w_b_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg)
{
#if UART_W_B_CFG_FIFO_SUPPORT

    /* Configure FIFO related registers. */
    r_uart_w_b_fifo_cfg(p_ctrl);
#else

    /* If fifo support is disabled since all channels support FIFO make sure it's disabled. */

    p_ctrl->p_reg->UART2_SFE_REG_b.UART_SHADOW_FIFO_ENABLE = 0;
#endif

    /* Set the baud rate settings for the internal baud rate generator. */
    r_uart_w_b_baud_set(p_ctrl->p_reg, ((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->p_baud_setting);

    uint32_t lcr_reg_val = p_ctrl->p_reg->UART2_LCR_REG;

    /* Set Parity */
    FSP_REG_VAR_FIELD_SET(UART2, UART2_LCR_REG, UART_PEN, lcr_reg_val, (p_cfg->parity) & 0b1);
    FSP_REG_VAR_FIELD_SET(UART2, UART2_LCR_REG, UART_EPS, lcr_reg_val, (p_cfg->parity >> 1) & 0b1);

    /* Set Stop Bits */
    FSP_REG_VAR_FIELD_SET(UART2, UART2_LCR_REG, UART_STOP, lcr_reg_val, p_cfg->stop_bits);

    /* Set Data Bits*/
    FSP_REG_VAR_FIELD_SET(UART2, UART2_LCR_REG, UART_DLS, lcr_reg_val, p_cfg->data_bits);
    p_ctrl->p_reg->UART2_LCR_REG = lcr_reg_val;
}

#if UART_W_B_CFG_FIFO_SUPPORT

/*******************************************************************************************************************//**
 * Configures FIFO related registers.
 *
 * @param[in] p_ctrl  Pointer to UART_W_B instance control
 **********************************************************************************************************************/
static void r_uart_w_b_fifo_cfg (uart_w_b_instance_ctrl_t * const p_ctrl)
{
    if (0U != p_ctrl->fifo_depth)
    {
        /* Enable the fifo and set the tx and rx reset bits */
        p_ctrl->p_reg->UART2_SFE_REG_b.UART_SHADOW_FIFO_ENABLE = 1;

 #if (UART_W_B_CFG_RX_ENABLE)
  #if UART_W_B_CFG_DTC_SUPPORTED

        /* If DTC is used keep the receive trigger at the default level of UART_W_B_RX_FIFO_1BYTE_TRIGGER. */
        if (NULL == p_ctrl->p_cfg->p_transfer_rx)
  #endif
        {
            /* Otherwise, set receive trigger level as configured by the user. */
            /* If no extended cfg is provided POR, keep POR values */
            if (NULL != p_ctrl->p_cfg->p_extend)
            {
                uint8_t rx_fifo_trigger = ((uart_w_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend)->rx_fifo_trigger;

                /* set rx fifo trigger level */
                p_ctrl->p_reg->UART2_SRT_REG_b.UART_SHADOW_RCVR_TRIGGER = rx_fifo_trigger &
                                                                          UART_UART_SRT_REG_UART_SHADOW_RCVR_TRIGGER_Msk;
                switch (rx_fifo_trigger)
                {
                    case UART_W_B_RX_FIFO_1BYTE_TRIGGER:
                    {
                        p_ctrl->p_reg->UART2_THLD_REG_b.FCR_RX_THLD = 1;
                        break;
                    }

                    case UART_W_B_RX_FIFO_QUARTERLY_FULL_TRIGGER:
                    {
                        p_ctrl->p_reg->UART2_THLD_REG_b.FCR_RX_THLD = 4;
                        break;
                    }

                    case UART_W_B_RX_FIFO_HALF_FULL_TRIGGER:
                    {
                        p_ctrl->p_reg->UART2_THLD_REG_b.FCR_RX_THLD = 8;
                        break;
                    }

                    case UART_W_B_RX_FIFO_2LESS_THAN_FULL_TRIGGER:
                    {
                        p_ctrl->p_reg->UART2_THLD_REG_b.FCR_RX_THLD = 14;
                        break;
                    }

                    default:
                    {
                        /* No more trigger cases for Rx_fifo. */
                        break;
                    }
                }
            }
        }
 #endif
 #if (UART_W_B_CFG_TX_ENABLE)
  #if UART_W_B_CFG_DTC_SUPPORTED

        /* If DTC is used keep the transmit trigger level at the default of UART_W_B_TX_FIFO_EMPTY_TRIGGER. */
        if (NULL == p_ctrl->p_cfg->p_transfer_tx)
  #endif
        {
            /* Otherwise, set transmit trigger level as configured by the user. */
            /* If no extended cfg is provided, keep POR values */
            if (NULL != p_ctrl->p_cfg->p_extend)
            {
                /* set tx fifo trigger level */
                uint8_t tx_fifo_trigger = ((uart_w_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend)->tx_fifo_trigger;
                p_ctrl->p_reg->UART2_STET_REG_b.UART_SHADOW_TX_EMPTY_TRIGGER = tx_fifo_trigger &
                                                                               UART_UART_STET_REG_UART_SHADOW_TX_EMPTY_TRIGGER_Msk;
                switch (tx_fifo_trigger)
                {
                    case UART_W_B_TX_FIFO_EMPTY_TRIGGER:
                    {
                        p_ctrl->p_reg->UART2_THLD_REG_b.FCR_TX_THLD = 0;
                        break;
                    }

                    case UART_W_B_TX_FIFO_2CHAR_TRIGGER:
                    {
                        p_ctrl->p_reg->UART2_THLD_REG_b.FCR_TX_THLD = 2;
                        break;
                    }

                    case UART_W_B_TX_FIFO_QUARTERLY_FULL_TRIGGER:
                    {
                        p_ctrl->p_reg->UART2_THLD_REG_b.FCR_TX_THLD = 4;
                        break;
                    }

                    case UART_W_B_TX_FIFO_HALF_FULL_TRIGGER:
                    {
                        p_ctrl->p_reg->UART2_THLD_REG_b.FCR_TX_THLD = 8;
                        break;
                    }

                    default:
                    {
                        /* No more trigger cases for Tx_fifo. */
                        break;
                    }
                }
            }
        }
 #endif
    }
    else
    {
        p_ctrl->p_reg->UART2_SFE_REG_b.UART_SHADOW_FIFO_ENABLE = 0;
    }
}

#endif

/*******************************************************************************************************************//**
 * Sets interrupt priority and initializes vector info.
 *
 * @param[in]  p_ctrl                    Pointer to driver control block
 * @param[in]  ipl                       Interrupt priority level
 * @param[in]  irq                       IRQ number for this interrupt
 **********************************************************************************************************************/
static void r_uart_w_b_irq_cfg (uart_w_b_instance_ctrl_t * const p_ctrl, uint8_t const ipl, IRQn_Type const irq)
{
    /* Disable interrupts, set priority, and store control block in the vector information so it can be accessed
     * from the callback. */
    R_BSP_IrqDisable(irq);
    R_BSP_IrqStatusClear(irq);
    R_BSP_IrqCfg(irq, ipl, p_ctrl);
}

/*******************************************************************************************************************//**
 * Sets interrupt priority and initializes vector info for all interrupts.
 *
 * @param[in]  p_ctrl                    Pointer to UART_W_B instance control block
 * @param[in]  p_cfg                     Pointer to UART_W_B specific configuration structure
 **********************************************************************************************************************/
static void r_uart_w_b_irqs_cfg (uart_w_b_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg)
{
    r_uart_w_b_irq_cfg(p_ctrl, ((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->gen_ipl,
                       ((uart_w_b_extended_cfg_t *) p_cfg->p_extend)->gen_irq);
#if (UART_W_B_CFG_RX_ENABLE)
 #if UART_W_B_CFG_DTC_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        r_uart_w_b_irq_cfg(p_ctrl, p_cfg->rxi_ipl, p_cfg->rxi_irq);
    }
 #endif
#endif

#if (UART_W_B_CFG_TX_ENABLE)
 #if UART_W_B_CFG_DTC_SUPPORTED
    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        r_uart_w_b_irq_cfg(p_ctrl, p_cfg->txi_ipl, p_cfg->txi_irq);
    }
 #endif

    r_uart_w_b_irq_cfg(p_ctrl, p_cfg->tei_ipl, p_cfg->tei_irq);
#endif
}

#if UART_W_B_CFG_DTC_SUPPORTED || UART_W_B_CFG_DMA_SUPPORTED

/*******************************************************************************************************************//**
 * Closes transfer interfaces.
 *
 * @param[in]     p_ctrl     Pointer to UART_W_B instance control block
 **********************************************************************************************************************/
static void r_uart_w_b_transfer_close (uart_w_b_instance_ctrl_t * p_ctrl)
{
 #if (UART_W_B_CFG_RX_ENABLE)
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        p_ctrl->p_cfg->p_transfer_rx->p_api->close(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
    }
 #endif
 #if (UART_W_B_CFG_TX_ENABLE)
    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        p_ctrl->p_cfg->p_transfer_tx->p_api->close(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);
    }
 #endif
}

#endif

/*******************************************************************************************************************//**
 * Sets only the baud clock source selection (CLK_SEL bits in CRG_COM) for the given UART channel.
 * This must be called while UART_ENABLE is 0 to prevent a clock glitch from corrupting DLL/DLH writes.
 *
 * @param[in]  p_uart_reg      Pointer to UART register base
 * @param[in]  p_baud_setting  Pointer to baud rate settings
 **********************************************************************************************************************/
static void r_uart_w_b_clk_sel_set (UART2_Type * p_uart_reg, uart_w_b_baud_setting_t const * const p_baud_setting)
{
    /* CRG_COM uses separate SET/RESET registers (write-1-to-set / write-1-to-clear).
     * Writing 0 to SET_CLK_COM_REG has no effect; to select DIVN (CLK_SEL=0) the
     * corresponding bit must be cleared via RESET_CLK_COM_REG instead. */
    if ((UART2_Type *) UART == p_uart_reg)
    {
        if (UART_W_B_DIVN == p_baud_setting->uart_clk_sel_div)
        {
            CRG_COM->RESET_CLK_COM_REG = CRG_COM_RESET_CLK_COM_REG_UART_CLK_SEL_Msk;
        }
        else
        {
            CRG_COM->SET_CLK_COM_REG = CRG_COM_SET_CLK_COM_REG_UART_CLK_SEL_Msk;
        }
    }
    else if ((UART2_Type *) UART2 == p_uart_reg)
    {
        if (UART_W_B_DIVN == p_baud_setting->uart_clk_sel_div)
        {
            CRG_COM->RESET_CLK_COM_REG = CRG_COM_RESET_CLK_COM_REG_UART2_CLK_SEL_Msk;
        }
        else
        {
            CRG_COM->SET_CLK_COM_REG = CRG_COM_SET_CLK_COM_REG_UART2_CLK_SEL_Msk;
        }
    }
    else if ((UART2_Type *) UART3 == p_uart_reg)
    {
        if (UART_W_B_DIVN == p_baud_setting->uart_clk_sel_div)
        {
            CRG_COM->RESET_CLK_COM_REG = CRG_COM_RESET_CLK_COM_REG_UART3_CLK_SEL_Msk;
        }
        else
        {
            CRG_COM->SET_CLK_COM_REG = CRG_COM_SET_CLK_COM_REG_UART3_CLK_SEL_Msk;
        }
    }

#if !BSP_MCU_GROUP_RA6B2
    else if ((UART2_Type *) UART4 == p_uart_reg)
    {
        if (UART_W_B_DIVN == p_baud_setting->uart_clk_sel_div)
        {
            CRG_COM->RESET_CLK_COM_REG = CRG_COM_RESET_CLK_COM_REG_UART4_CLK_SEL_Msk;
        }
        else
        {
            CRG_COM->SET_CLK_COM_REG = CRG_COM_SET_CLK_COM_REG_UART4_CLK_SEL_Msk;
        }
    }
#endif
    else
    {
        /* No more channel number is available */
    }
}

/*******************************************************************************************************************//**
 * Changes baud rate based on predetermined register settings.
 *
 * @param[in]  p_uart_reg      Base pointer for UART_W_B registers
 * @param[in]  p_baud_setting  Pointer to other divisor related settings
 *
 * @note       The transmitter and receiver interrupt masks in UART_IER_DLH_REG reg must be disabled prior to calling
 *             this function.
 **********************************************************************************************************************/
static void r_uart_w_b_baud_set (UART2_Type * p_uart_reg, uart_w_b_baud_setting_t const * const p_baud_setting)
{
    r_uart_w_b_clk_sel_set(p_uart_reg, p_baud_setting);

    /* Set Divisor Latch Access Bit in LCR register to access DLL & DLH registers */
    p_uart_reg->UART2_LCR_REG_b.UART_DLAB = 1;

    /* Set fraction byte (only 4 bit needed) of baud rate */
    p_uart_reg->UART2_DLF_REG_b.UART_DLF = (uint8_t) (UART_W_B_HALF_BYTE_MASK & p_baud_setting->dlf); // [3..0]

    /* Set low byte of baud rate */
    p_uart_reg->UART2_RBR_THR_DLL_REG_b.RBR_THR_DLL = p_baud_setting->thr_dll;                        // [7..0]

    /* Set high byte of baud rate */
    p_uart_reg->UART2_IER_DLH_REG = p_baud_setting->ier_dlh;                                          // [7..0]

    /* Reset Divisor Latch Access Bit in LCR register */
    p_uart_reg->UART2_LCR_REG_b.UART_DLAB = 0;

    /* DLAB will not reset if UART_W_B is busy, for example if UART_W_B Rx line
     * is LOW while UART_DLAB is SET. The caller could temporary disable any
     * UARTx_RX GPIOs to avoid LOW state on UART_W_B Rx. */
    BSP_CHECK_DEBUG(p_uart_reg->UART2_LCR_REG_b.UART_DLAB == 0);
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to UART_W_B instance control block
 * @param[in]     data       See uart_callback_args_t in r_uart_api.h
 * @param[in]     event      Event code
 **********************************************************************************************************************/
static void r_uart_w_b_call_callback (uart_w_b_instance_ctrl_t * p_ctrl, uint32_t data, uart_event_t event)
{
    uart_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.
     * This allows callback arguments to be stored in non-secure memory so
     * they can be accessed by a non-secure callback function. */
    uart_callback_args_t * p_args = p_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested
         * interrupt. */
        args = *p_args;
    }

    p_args->channel   = p_ctrl->p_cfg->channel;
    p_args->data      = data;
    p_args->event     = event;
    p_args->p_context = p_ctrl->p_context;

#if BSP_TZ_SECURE_BUILD

    /* p_callback can point to a secure function or a non-secure function. */
    if (!cmse_is_nsfptr(p_ctrl->p_callback))
    {
        /* If p_callback is secure, then the project does not need to change security state. */
        p_ctrl->p_callback(p_args);
    }
    else
    {
        /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
        uart_w_b_prv_ns_callback p_callback = (uart_w_b_prv_ns_callback) (p_ctrl->p_callback);
        p_callback(p_args);
    }

#else

    /* If the project is not Trustzone Secure, then it will never need to change security
     * state in order to call the callback. */
    p_ctrl->p_callback(p_args);
#endif
    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

/***********************************************************************************************************************
 * Interrupt service routines
 **********************************************************************************************************************/
#if (UART_W_B_CFG_TX_ENABLE)

 #if UART_W_B_CFG_FIFO_SUPPORT
static void r_uart_w_b_restore_tx_fifo_trigger (uart_w_b_instance_ctrl_t * p_ctrl)
{
    /* Restore the TX FIFO trigger level to the user-configured value before filling
     * the FIFO.  txi_handler temporarily lowers it to EMPTY for the last byte;
     * restoring it here (rather than in tei_isr) avoids writing the threshold
     * register while the FIFO is empty, which would immediately re-fire TXE. */
    if (NULL != p_ctrl->p_cfg->p_extend)
    {
        uint8_t tx_fifo_trigger = ((uart_w_b_extended_cfg_t *) p_ctrl->p_cfg->p_extend)->tx_fifo_trigger;
        p_ctrl->p_reg->UART2_STET_REG_b.UART_SHADOW_TX_EMPTY_TRIGGER = tx_fifo_trigger &
                                                                       UART_UART_STET_REG_UART_SHADOW_TX_EMPTY_TRIGGER_Msk;
        switch (tx_fifo_trigger)
        {
            case UART_W_B_TX_FIFO_EMPTY_TRIGGER:
            {
                p_ctrl->p_reg->UART2_THLD_REG_b.FCR_TX_THLD = 0;
                break;
            }

            case UART_W_B_TX_FIFO_2CHAR_TRIGGER:
            {
                p_ctrl->p_reg->UART2_THLD_REG_b.FCR_TX_THLD = 2;
                break;
            }

            case UART_W_B_TX_FIFO_QUARTERLY_FULL_TRIGGER:
            {
                p_ctrl->p_reg->UART2_THLD_REG_b.FCR_TX_THLD = 4;
                break;
            }

            case UART_W_B_TX_FIFO_HALF_FULL_TRIGGER:
            {
                p_ctrl->p_reg->UART2_THLD_REG_b.FCR_TX_THLD = 8;
                break;
            }

            default:
            {
                break;
            }
        }
    }
}

 #endif

/*******************************************************************************************************************//**
 * TXI interrupt processing for UART_W_B in no-DTC mode.Triggered through uart_w_b_gen_isr(), TXI interrupt fires when the
 * data in the data register or FIFO register has been transferred to the data shift register, and the next data can be
 * written.  This interrupt writes the next data. After the last data byte is written, this interrupt disables the
 * generic TXI interrupt and enables the TEI (transmit end) interrupt.
 * @param[in] p_ctrl Pointer to the control block for the channel
 **********************************************************************************************************************/
static void r_uart_w_b_txi_handler (uart_w_b_instance_ctrl_t * const p_ctrl)
{
    if (0U != p_ctrl->tx_src_bytes)
    {
 #if UART_W_B_CFG_FIFO_SUPPORT
        if (0U != p_ctrl->fifo_depth)
        {
            while ((1 == p_ctrl->p_reg->UART2_USR_REG_b.UART_TFNF) && (0U != p_ctrl->tx_src_bytes))
            {
                /* For tx FIFO level other than zero
                 * when last byte is about to be sent,
                 * trigger one more txe IRQ entry
                 * by setting tx fifo threshold to EMPTY and exiting */
                if ((1UL == p_ctrl->tx_src_bytes) && (0 != p_ctrl->p_reg->UART2_TFL_REG))
                {
                    p_ctrl->p_reg->UART2_STET_REG               = UART_W_B_TX_FIFO_EMPTY_TRIGGER;
                    p_ctrl->p_reg->UART2_THLD_REG_b.FCR_TX_THLD = 0;

                    return;
                }
                else if ((1UL == p_ctrl->tx_src_bytes) && (0 == p_ctrl->p_reg->UART2_TFL_REG)) /* Second time txe is triggered for the last remaining byte. */
                {
                    r_uart_w_b_restore_tx_fifo_trigger(p_ctrl);

                    /* enable Transmission-end IRQ as a workaround for overlapping TXR & TXE */
  #ifdef UART2_MASK_REG_UART3
                    p_ctrl->p_reg->UART2_MASK_REG_b.UART3_TXR_IRQ_MASK = 1;
  #else
                    p_ctrl->p_reg->UART2_MASK_REG_b.UART_TXR_IRQ_MASK = 1;
  #endif
                }

                /* Write data to data register */
                p_ctrl->p_reg->UART2_RBR_THR_DLL_REG = *(p_ctrl->p_tx_src);

                /* Update pointer to the next data and number of remaining bytes
                 * in the control block. */
                p_ctrl->tx_src_bytes -= p_ctrl->data_bytes;
                p_ctrl->p_tx_src     += p_ctrl->data_bytes;
            }
        }
        else
 #endif
        {
            while ((1 == p_ctrl->p_reg->UART2_LSR_REG_b.UART_THRE) && (0U != p_ctrl->tx_src_bytes))
            {
                /* enable Transmission-end IRQ as a workaround for overlapping TXR & TXE */
                if (1UL == p_ctrl->tx_src_bytes)
                {
 #ifdef UART2_MASK_REG_UART3
                    p_ctrl->p_reg->UART2_MASK_REG_b.UART3_TXR_IRQ_MASK = 1;
 #else
                    p_ctrl->p_reg->UART2_MASK_REG_b.UART_TXR_IRQ_MASK = 1;
 #endif
                }

                p_ctrl->p_reg->UART2_RBR_THR_DLL_REG = *(p_ctrl->p_tx_src);

                /* Update pointer to the next data and number of remaining bytes in
                 * the control block. */
                p_ctrl->tx_src_bytes -= p_ctrl->data_bytes;
                p_ctrl->p_tx_src     += p_ctrl->data_bytes;
            }
        }
    }

    if (0U == p_ctrl->tx_src_bytes)
    {
        /* After all data has been transmitted,
         * disable Tx-generic and Tx-dedicated interrupt. */

        uint32_t ier_reg_val = p_ctrl->p_reg->UART2_IER_DLH_REG;
        FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, ETBEI_DLH1, ier_reg_val, 0);
        FSP_REG_VAR_FIELD_SET(UART2, UART2_IER_DLH_REG, PTIME_DLH7, ier_reg_val, 0);

        uint32_t irq_mask_reg_val = p_ctrl->p_reg->UART2_MASK_REG;

        FSP_REG_VAR_FIELD_SET(UART2, UART2_MASK_REG, UART_TXE_IRQ_MASK, irq_mask_reg_val, 0);

        p_ctrl->p_reg->UART2_MASK_REG    = irq_mask_reg_val;
        p_ctrl->p_reg->UART2_IER_DLH_REG = ier_reg_val;

        p_ctrl->p_tx_src = NULL;

        /* If a callback was provided, call it with the argument */
        if (NULL != p_ctrl->p_callback)
        {
            r_uart_w_b_call_callback(p_ctrl, 0U, UART_EVENT_TX_DATA_EMPTY);
        }
    }
}

#endif

#if (UART_W_B_CFG_RX_ENABLE)

/*******************************************************************************************************************//**
 * Builds a uart_event_t error mask from an LSR register snapshot.
 *
 * @param[in]  lsr   Value read from UART2_LSR_REG
 * @return     Bitmask of UART_ERR_* flags; UART_ERR_NOERROR (0) if no error bits are set.
 **********************************************************************************************************************/
static uart_event_t r_uart_w_b_lsr_to_event (uint32_t lsr)
{
    uart_event_t event = UART_ERR_NOERROR;
    if (lsr & UART_UART_LSR_REG_UART_OE_Msk)
    {
        event |= UART_ERR_OE;
    }

    if (lsr & UART_UART_LSR_REG_UART_PE_Msk)
    {
        event |= UART_ERR_PE;
    }

    if (lsr & UART_UART_LSR_REG_UART_FE_Msk)
    {
        event |= UART_ERR_FE;
    }

    if (lsr & UART_UART_LSR_REG_UART_BI_Msk)
    {
        event |= UART_ERR_BI;
    }

    if (lsr & UART_UART_LSR_REG_UART_RFE_Msk)
    {
        event |= UART_ERR_RFE;
    }

    return event;
}

/*******************************************************************************************************************//**
 * RXI interrupt processing for UART_W_B in no-DTC mode.
 * @details Triggered through uart_w_b_gen_isr(), RXI interrupt happens when data arrives to the data register or the FIFO
 *          register.This function calls callback function when it meets conditions below.
 *          - UART_EVENT_RX_COMPLETE: The number of data which has been read reaches to the number specified in
 *          R_UART_Read() if a transfer instance is used for reception.
 *          - UART_EVENT_RX_CHAR: Data is received asynchronously (read has not been called)
 *
 *          This interrupt also calls the callback function for RTS pin control if it is registered in R_UART_Open().
 *          This is special functionality to expand SCI hardware capability and make RTS/CTS hardware flow control
 *          possible. If macro 'UART_W_B_CFG_FLOW_CONTROL_SUPPORT' is set, it is called at the beginning
 *          in this function to set the RTS pin high,then it is called again just before leaving this function
 *          to set the RTS pin low.
 * @param[in] p_ctrl Pointer to the control block for the channel
 **********************************************************************************************************************/
static void r_uart_w_b_rxi_handler (uart_w_b_instance_ctrl_t * const p_ctrl)
{
    uint32_t data;

    /* Out-of-band reception */
    if (0U == p_ctrl->rx_dest_bytes)
    {
        if (1 == p_ctrl->p_reg->UART2_LSR_REG_b.UART_DR)
        {
            data = p_ctrl->p_reg->UART2_RBR_THR_DLL_REG;
        }

        /* If a callback was provided, call it with the argument */
        if (NULL != p_ctrl->p_callback)
        {
            r_uart_w_b_call_callback(p_ctrl, data, UART_EVENT_RX_CHAR);
        }
    }
    else
    {
        /* Read LSR once per iteration to atomically capture DR and error flags
         * (OE/PE/FE/BI/RFE).  Reading LSR clears error bits, so a separate read
         * for each check would silently discard overrun events that arrive between
         * the while-condition check and the data read. */
        uint32_t lsr = p_ctrl->p_reg->UART2_LSR_REG;

        while ((lsr & UART_UART_LSR_REG_UART_DR_Msk) && (0 != p_ctrl->rx_dest_bytes))
        {
            data = p_ctrl->p_reg->UART2_RBR_THR_DLL_REG;

            /* Detect errors captured in the same LSR read as the DR flag. */
            if (lsr & (UART_UART_LSR_REG_UART_OE_Msk | UART_UART_LSR_REG_UART_PE_Msk |
                       UART_UART_LSR_REG_UART_FE_Msk | UART_UART_LSR_REG_UART_BI_Msk |
                       UART_UART_LSR_REG_UART_RFE_Msk))
            {
                /* Build the error event from the already-captured LSR snapshot and
                 * notify the application.  The stream is now corrupted, so return
                 * immediately without copying the erroneous byte to the rx buffer. */
                if (NULL != p_ctrl->p_callback)
                {
                    r_uart_w_b_call_callback(p_ctrl, data, r_uart_w_b_lsr_to_event(lsr));
                }

                return;
            }

            memcpy((uint8_t *) p_ctrl->p_rx_dest, &data, p_ctrl->data_bytes);
            p_ctrl->p_rx_dest     += p_ctrl->data_bytes;
            p_ctrl->rx_dest_bytes -= p_ctrl->data_bytes;

            /* Re-read LSR for the next iteration. */
            lsr = p_ctrl->p_reg->UART2_LSR_REG;
        }

        if (0 == p_ctrl->rx_dest_bytes)
        {
            p_ctrl->p_rx_dest = NULL;

            /* If a callback was provided, call it with the argument */
            if (NULL != p_ctrl->p_callback)
            {
                r_uart_w_b_call_callback(p_ctrl, 0U, UART_EVENT_RX_COMPLETE);
            }
        }
    }
}

#endif

#if (UART_W_B_CFG_RX_ENABLE)

/*******************************************************************************************************************//**
 * Error handler routine:Detects Error event from Uart Line status Register, reads data from UART_RBR
 *        and calls callback.
 *
 * @param[in] p_ctrl Pointer to the control block for the channel
 **********************************************************************************************************************/
static void r_uart_w_b_error_handler (uart_w_b_instance_ctrl_t * const p_ctrl)
{
    uint32_t data = 0U;

    /* Read Line Status Register once because errors are cleared after reading it. */
    uint32_t lsr = p_ctrl->p_reg->UART2_LSR_REG;

    /* Read data. */
    if (1 == p_ctrl->p_reg->UART2_LSR_REG_b.UART_DR)
    {
        data = p_ctrl->p_reg->UART2_RBR_THR_DLL_REG;
    }

    /* If a callback was provided, call it with the argument */
    if (NULL != p_ctrl->p_callback)
    {
        /* Call callback. */
        r_uart_w_b_call_callback(p_ctrl, data, r_uart_w_b_lsr_to_event(lsr));
    }
}

/*******************************************************************************************************************//**
 * Timeout interrupt processing for UART_W_B.
 * @details When an Timeout interrupt fires, the user callback function is called if it is registered in R_UART_Open()
 *          with the event code that triggered the interrupt.
 * @param[in] p_ctrl Pointer to the control block for the channel
 **********************************************************************************************************************/
static void r_uart_w_b_rx_timeout_handler (uart_w_b_instance_ctrl_t * const p_ctrl)
{
    /* Read LSR once per iteration (same rationale as rxi_handler: avoids clearing
     * error bits between the DR check and the subsequent error detection). */
    uint32_t lsr = p_ctrl->p_reg->UART2_LSR_REG;

    while ((lsr & UART_UART_LSR_REG_UART_DR_Msk) && (0 != p_ctrl->rx_dest_bytes))
    {
        uint32_t data = p_ctrl->p_reg->UART2_RBR_THR_DLL_REG;

        if (lsr & (UART_UART_LSR_REG_UART_OE_Msk | UART_UART_LSR_REG_UART_PE_Msk |
                   UART_UART_LSR_REG_UART_FE_Msk | UART_UART_LSR_REG_UART_BI_Msk |
                   UART_UART_LSR_REG_UART_RFE_Msk))
        {
            if (NULL != p_ctrl->p_callback)
            {
                r_uart_w_b_call_callback(p_ctrl, data, r_uart_w_b_lsr_to_event(lsr));
            }

            return;
        }

        memcpy((uint8_t *) p_ctrl->p_rx_dest, &data, p_ctrl->data_bytes);
        p_ctrl->p_rx_dest     += p_ctrl->data_bytes;
        p_ctrl->rx_dest_bytes -= p_ctrl->data_bytes;

        lsr = p_ctrl->p_reg->UART2_LSR_REG;
    }

 #if UART_W_B_CFG_DTC_SUPPORTED

    /* If DTC already moved all bytes but the dedicated RX complete ISR was missed,
     * treat the timeout as completion instead of a failure. */
    if ((0U != p_ctrl->rx_dest_bytes) && (NULL != p_ctrl->p_cfg->p_transfer_rx))
    {
        transfer_properties_t transfer_info;
        fsp_err_t err = p_ctrl->p_cfg->p_transfer_rx->p_api->infoGet(p_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                                     &transfer_info);

        if ((FSP_SUCCESS == err) && (0U == transfer_info.transfer_length_remaining))
        {
            p_ctrl->rx_dest_bytes = 0U;
        }
    }
 #endif

    /* If everything is received, reset handle and call callback with UART_EVENT_RX_COMPLETE */
    if (0 == p_ctrl->rx_dest_bytes)
    {
        p_ctrl->p_rx_dest = NULL;

        if (NULL != p_ctrl->p_callback)
        {
            r_uart_w_b_call_callback(p_ctrl, 0U, UART_EVENT_RX_COMPLETE);
        }
    }
    /* If not everything is received, reset handle and call callback with UART_EVENT_RX_TIMEOUT */
    else
    {
        if (NULL != p_ctrl->p_callback)
        {
            r_uart_w_b_call_callback(p_ctrl, 0U, UART_EVENT_RX_TIMEOUT);
        }
    }
}

#endif

#if (UART_W_B_CFG_TX_ENABLE)

/*******************************************************************************************************************//**
 * TEI interrupt processing for UART_W_B. The TEI interrupt fires after the last byte is transmitted on the TX pin.
 * The user callback function is called with the UART_EVENT_TX_COMPLETE event code (if it is registered in
 * R_UART_Open()).
 **********************************************************************************************************************/
void uart_w_b_tei_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Receiving TEI(transmit end interrupt) means the completion of transmission, so call callback function here. */
    /* Clear and disable TEI IRQ  to make sure it won't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Disable transmission-end interrupt */
    p_ctrl->p_reg->UART2_MASK_REG_b.UART_TXR_IRQ_MASK = 0;

    /* If a callback was provided, call it with the argument */
    if (NULL != p_ctrl->p_callback)
    {
        r_uart_w_b_call_callback(p_ctrl, 0U, UART_EVENT_TX_COMPLETE);
    }

 #if UART_W_B_CFG_FIFO_SUPPORT

    /* NOTE: TX FIFO trigger level is NOT restored here.
     * Writing the TX threshold register while the FIFO is empty (immediately
     * after transmission completes) re-fires the TXE interrupt, causing
     * txi_handler -> UART_TXR_IRQ_MASK=1 -> tei_isr to run a second time.
     * The trigger level is restored at the start of the next txi_handler
     * invocation, before the FIFO is re-filled. */
 #endif

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

#endif

/*******************************************************************************************************************//**
 * Generic interrupt processing for UART_W_B.
 * @details When a generic interrupt fires, the Interrupt identification register is read to define the interrupt
 *          source to call respective handler.
 **********************************************************************************************************************/
void uart_w_b_gen_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    uart_w_b_interrupt_source_t source;
    for ( ; ; )
    {
        /* Read Interrupt Identification Register to define interrupt source */
        source = (uart_w_b_interrupt_source_t) (p_ctrl->p_reg->UART2_IIR_FCR_REG & UART_W_B_HALF_BYTE_MASK);

        switch (source)
        {
            case UART_W_B_INT_TIMEOUT:
            {
#if (UART_W_B_CFG_RX_ENABLE)
                r_uart_w_b_rx_timeout_handler(p_ctrl);
#endif
                break;
            }

            case UART_W_B_INT_MODEM_STAT:
            {
                break;
            }

            case UART_W_B_INT_NO_INT_PEND:
            {
                /* Restore context if RTOS is used */
                FSP_CONTEXT_RESTORE;

                /* Exit the ISR since no interrupt is pending */
                return;
            }

            case UART_W_B_INT_THR_EMPTY:
            {
#if (UART_W_B_CFG_TX_ENABLE)
                r_uart_w_b_txi_handler(p_ctrl);
#endif
                break;
            }

            case UART_W_B_INT_RECEIVED_AVAILABLE:
            {
#if (UART_W_B_CFG_RX_ENABLE)
                r_uart_w_b_rxi_handler(p_ctrl);
#endif
                break;
            }

            case UART_W_B_INT_RECEIVE_LINE_STAT:
            {
#if (UART_W_B_CFG_RX_ENABLE)
                r_uart_w_b_error_handler(p_ctrl);
#endif
                break;
            }

            case UART_W_B_INT_BUSY_DETECTED:
            {
#if (UART_W_B_CFG_RX_ENABLE)
                r_uart_w_b_error_handler(p_ctrl);
#endif
                break;
            }

            default:
            {
                /* All the interrupt sources were handled above. */
                break;
            }
        }
    }
}

/*******************************************************************************************************************//**
 * TXE dedicated interrupt processing for UART_W_B. Used only if DTC is supported
 **********************************************************************************************************************/
void uart_w_b_tx_ded_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* In DTC with IRQ-end mode, this isr is called only when transfer has finished */
    /* After all data has been transmitted, disable Tx-dedicated interrupts and enable tei interrupts */
    uint32_t irq_mask_reg_val = p_ctrl->p_reg->UART2_MASK_REG;

    FSP_REG_VAR_FIELD_SET(UART2, UART2_MASK_REG, UART_TXE_IRQ_MASK, irq_mask_reg_val, 0);
    FSP_REG_VAR_FIELD_SET(UART2, UART2_MASK_REG, UART_TXR_IRQ_MASK, irq_mask_reg_val, 1);

    p_ctrl->p_reg->UART2_MASK_REG = irq_mask_reg_val;

    /* TXR is a pulse interrupt and may have already passed before UART_TXR_IRQ_MASK
     * was set above (the DTC writes the last byte directly to THR; on a small/empty
     * FIFO the shift register can drain almost immediately).  If the transmitter is
     * already empty, the TEI pulse will never fire on its own, so latch it manually
     * via the NVIC pending bit so uart_w_b_tei_isr() runs and the user callback gets
     * UART_EVENT_TX_COMPLETE.
     *
     * Guard with the mask-register read: if tei_irq has higher priority than this ISR
     * (tx_ded_isr) it may have already preempted us between the MASK write above and
     * this point, run tei_isr, and cleared UART_TXR_IRQ_MASK back to 0.  In that case
     * NVIC_SetPendingIRQ must NOT be called, otherwise tei_isr fires a second time and
     * UART_EVENT_TX_COMPLETE is delivered twice.
     * UART_TXR_IRQ_MASK == 1 means tei_isr has not yet run and it is safe to pend. */
    if ((1U == p_ctrl->p_reg->UART2_LSR_REG_b.UART_TEMT) &&
        (1U == p_ctrl->p_reg->UART2_MASK_REG_b.UART_TXR_IRQ_MASK))
    {
        NVIC_SetPendingIRQ(p_ctrl->p_cfg->tei_irq);
    }

    /* Reset driver buffers */
    p_ctrl->tx_src_bytes = 0;
    p_ctrl->p_tx_src     = NULL;

    /* If a callback was provided, call it with the argument */
    if (NULL != p_ctrl->p_callback)
    {
        r_uart_w_b_call_callback(p_ctrl, 0U, UART_EVENT_TX_DATA_EMPTY);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

/*******************************************************************************************************************//**
 * RX dedicated interrupt processing for UART_W_B. Used only if DTC is supported
 **********************************************************************************************************************/
void uart_w_b_rx_ded_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Disable Rx-dedicated irq through NVIC, while mask remains open to notify ELC for out of band reception events */
    R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);

    /* Reset driver buffers */
    p_ctrl->rx_dest_bytes = 0;
    p_ctrl->p_rx_dest     = NULL;

    /* If a callback was provided, call it with the argument */
    if (NULL != p_ctrl->p_callback)
    {
        r_uart_w_b_call_callback(p_ctrl, 0U, UART_EVENT_RX_COMPLETE);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

#if UART_W_B_CFG_DMA_SUPPORTED

/*******************************************************************************************************************//**
 * Required callback for DMA mode, called after tx transfer is complete.
 **********************************************************************************************************************/
void uart_w_b_dma_cb_tx (uart_w_b_instance_ctrl_t * p_ctrl)
{
    /* Enable TEI interrupt which will notify for tx_complete*/
    uint32_t irq_mask_reg_val = p_ctrl->p_reg->UART2_MASK_REG;

    FSP_REG_VAR_FIELD_SET(UART2, UART2_MASK_REG, UART_TXE_IRQ_MASK, irq_mask_reg_val, 0);
    FSP_REG_VAR_FIELD_SET(UART2, UART2_MASK_REG, UART_TXR_IRQ_MASK, irq_mask_reg_val, 1);

    p_ctrl->p_reg->UART2_MASK_REG = irq_mask_reg_val;

    /* De-init uart tx buffers */
    p_ctrl->p_tx_src     = NULL;
    p_ctrl->tx_src_bytes = 0;

    if (NULL != p_ctrl->p_callback)
    {
        r_uart_w_b_call_callback(p_ctrl, 0U, UART_EVENT_TX_DATA_EMPTY);
    }
}

/*******************************************************************************************************************//**
 * Required callback for DMA mode, called after rx transfer is complete.
 **********************************************************************************************************************/
void uart_w_b_dma_cb_rx (uart_w_b_instance_ctrl_t * p_ctrl)
{
    /* De-init uart rx buffers */
    p_ctrl->p_rx_dest     = NULL;
    p_ctrl->rx_dest_bytes = 0;

    /* Enable Rx-generic interrupts for out-of band reception */
    p_ctrl->p_reg->UART2_IER_DLH_REG_b.ERBFI_DLH0 = 1;

    if (NULL != p_ctrl->p_callback)
    {
        r_uart_w_b_call_callback(p_ctrl, 0U, UART_EVENT_RX_COMPLETE);
    }
}

#endif

#if (UART_W_B_CFG_TX_ENABLE)

/*******************************************************************************************************************//**
 * Checks if transmission is finished, or if tx line is ready for next transmission.
 *
 * @param[in] p_api_ctrl                 Pointer to the instance control structure.
 * @param[in] tx_is_ready                Maximum number of byte information .
 *
 * @retval  FSP_SUCCESS                  Information stored in provided p_info.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART_W_B control block or tx_is_ready is NULL.
 **********************************************************************************************************************/
fsp_err_t R_UART_W_B_TxReady (uart_ctrl_t * const p_api_ctrl, bool * tx_is_ready)
{
 #if (UART_W_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_api_ctrl);
    FSP_ASSERT(NULL != tx_is_ready);
 #endif
    uart_w_b_instance_ctrl_t * p_ctrl = (uart_w_b_instance_ctrl_t *) p_api_ctrl;

    *tx_is_ready = p_ctrl->p_reg->UART2_LSR_REG_b.UART_TEMT;

    return FSP_SUCCESS;
}

#endif
