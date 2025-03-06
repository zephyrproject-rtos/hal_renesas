/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_scif_uart.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#ifndef SCIF_UART_CFG_RX_ENABLE
 #define SCIF_UART_CFG_RX_ENABLE           1
#endif
#ifndef SCIF_UART_CFG_TX_ENABLE
 #define SCIF_UART_CFG_TX_ENABLE           1
#endif

/** Number of divisors in the data table used for baud rate calculation. */
#define SCIF_UART_NUM_DIVISORS_ASYNC       (9U)

/** Valid range of values for the modulation duty register is 128 - 256 (256 = modulation disabled). */
#define SCIF_UART_MDDR_MIN                 (128U)
#define SCIF_UART_MDDR_MAX                 (256U)

/** The bit rate register is 8-bits, so the maximum value is 255. */
#define SCIF_UART_BRR_MAX                  (255U)

/** No limit to the number of bytes to read or write. */
#define SCIF_UART_MAX_READ_WRITE           (0xFFFFFFFFU)

/** "SCFU" in ASCIFAI.  Used to determine if the control block is open. */
#define SCIF_UART_OPEN                     (0x53434655U)

#define SCIF_UART_BRR_DEFAULT_VALUE        (0xFFU)

#define SCIF_UART_DMAC_RX_TRIGGER_LEVEL    (1U)

#define SCIF_UART_DMAC_MAX_TRANSFER        (0xFFFFFFFFU)

#define SCIF_UART_INVALID_16BIT_PARAM      (0xFFFFU)

/***********************************************************************************************************************
 * Private constants
 **********************************************************************************************************************/
static const uint32_t SCIF_UART_TX_FIFO_STAGES     = 16;
static const int32_t  SCIF_UART_100_PERCENT_X_1000 = 100000;
static const int32_t  SCIF_UART_MDDR_DIVISOR       = 256;

#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
static const uint32_t SCIF_UART_MAX_BAUD_RATE_ERROR_X_1000 = 15000;
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef struct st_baud_setting_const_t
{
    uint8_t bgdm : 1;                  /**< BGDM value to get divisor */
    uint8_t abcs : 1;                  /**< ABCS value to get divisor */
    uint8_t cks  : 2;                  /**< CKS  value to get divisor (CKS = N) */
} baud_setting_const_t;

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * scif_uart_prv_ns_callback)(uart_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile scif_uart_prv_ns_callback)(uart_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_scif_negate_de_pin(scif_uart_instance_ctrl_t const * const p_ctrl);

#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)

static fsp_err_t r_scif_read_write_param_check(scif_uart_instance_ctrl_t const * const p_ctrl,
                                               uint8_t const * const                   addr,
                                               uint32_t const                          bytes);

#endif

static void r_scif_uart_config_set(scif_uart_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg);

static void r_scif_uart_baud_set(R_SCIFA0_Type * p_scif_reg, scif_baud_setting_t const * const p_baud_setting);
static void r_scif_uart_call_callback(scif_uart_instance_ctrl_t * p_ctrl, uint32_t data, uart_event_t event);

static void r_scif_uart_fifo_cfg(scif_uart_instance_ctrl_t * const p_ctrl);

static void r_scif_irq_cfg(scif_uart_instance_ctrl_t * const p_ctrl, uint8_t const ipl, IRQn_Type const p_irq);

static void r_scif_irqs_cfg(scif_uart_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg);

#if (SCIF_UART_CFG_RX_ENABLE)
static void scif_uart_receive_sub(scif_uart_instance_ctrl_t * const p_ctrl);
void        scif_uart_rxi_isr(void);

void scif_uart_eri_isr(void);
void scif_uart_bri_isr(void);

#endif

#if (SCIF_UART_CFG_TX_ENABLE)
void scif_uart_txi_isr(void);

#endif

#if (SCIF_UART_CFG_TX_ENABLE || SCIF_UART_CFG_RX_ENABLE)
void scif_uart_tei_isr(void);

#endif

#if SCIF_UART_CFG_DMAC_ENABLE
static fsp_err_t r_scif_uart_transfer_configure(transfer_instance_t const * p_transfer,
                                                uint32_t                  * p_transfer_reg,
                                                uint32_t                    address);

static fsp_err_t r_scif_uart_transfer_open(scif_uart_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg);

static void r_scif_uart_transfer_close(scif_uart_instance_ctrl_t * p_ctrl);

void scif_uart_tx_dmac_callback(scif_uart_instance_ctrl_t * p_ctrl);
void scif_uart_rx_dmac_callback(scif_uart_instance_ctrl_t * p_ctrl);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* SCIF_UART base address */
static const uint16_t volatile * p_scif_base_address[BSP_FEATURE_SCIF_MAX_CHANNEL] =
{
    (uint16_t *) R_SCIFA0,
#if BSP_FEATURE_SCIF_MAX_CHANNEL > 1
    (uint16_t *) R_SCIFA1,
 #if BSP_FEATURE_SCIF_MAX_CHANNEL > 2
    (uint16_t *) R_SCIFA2,
  #if BSP_FEATURE_SCIF_MAX_CHANNEL > 3
    (uint16_t *) R_SCIFA3,
   #if BSP_FEATURE_SCIF_MAX_CHANNEL > 4
    (uint16_t *) R_SCIFA4,
   #endif
  #endif
 #endif
#endif
};

/** Name of module used by error logger macro */
#if BSP_CFG_ERROR_LOG != 0
static const char g_module_name[] = "scif_uart";
#endif

/** Baud rate divisor information (UART mode) */
static const baud_setting_const_t g_async_baud[SCIF_UART_NUM_DIVISORS_ASYNC] =
{
    {1U, 1U, 0U},                      /* BGDM, ABCS, n */
    {1U, 0U, 0U},
    {0U, 0U, 0U},
    {1U, 0U, 1U},
    {0U, 0U, 1U},
    {1U, 0U, 2U},
    {0U, 0U, 2U},
    {1U, 0U, 3U},
    {0U, 0U, 3U}
};

static const uint16_t g_div_coefficient[SCIF_UART_NUM_DIVISORS_ASYNC] =
{
    8U,
    16U,
    32U,
    64U,
    128U,
    256U,
    512U,
    1024U,
    2048U,
};

/** UART on SCIF HAL API mapping for UART interface */
const uart_api_t g_uart_on_scif =
{
    .open               = R_SCIF_UART_Open,
    .close              = R_SCIF_UART_Close,
    .write              = R_SCIF_UART_Write,
    .read               = R_SCIF_UART_Read,
    .infoGet            = R_SCIF_UART_InfoGet,
    .baudSet            = R_SCIF_UART_BaudSet,
    .communicationAbort = R_SCIF_UART_Abort,
    .callbackSet        = R_SCIF_UART_CallbackSet,
    .readStop           = R_SCIF_UART_ReadStop,
};

/*******************************************************************************************************************//**
 * @addtogroup SCIF_UART
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configures the UART driver based on the input configurations.  If reception is enabled at compile time, reception is
 * enabled at the end of this function. Implements @ref uart_api_t::open
 *
 * @retval  FSP_SUCCESS                    Channel opened successfully.
 * @retval  FSP_ERR_ASSERTION              Pointer to UART control block or configuration structure is NULL.
 * @retval  FSP_ERR_IP_CHANNEL_NOT_PRESENT The requested channel does not exist on this MPU.
 * @retval  FSP_ERR_ALREADY_OPEN           Control block has already been opened or channel is being used by another
 *                                         instance. Call close() then open() to reconfigure.
 * @retval  FSP_ERR_INVALID_ARGUMENT       Setting for RS485 DE Control pin is invalid
 *
 * @return                       See @ref RENESAS_ERROR_CODES
 **********************************************************************************************************************/
fsp_err_t R_SCIF_UART_Open (uart_ctrl_t * const p_api_ctrl, uart_cfg_t const * const p_cfg)
{
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) p_api_ctrl;

#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters. */
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_cfg);
    FSP_ASSERT(p_cfg->p_extend);
    FSP_ASSERT(((scif_uart_extended_cfg_t *) p_cfg->p_extend)->p_baud_setting);
    FSP_ERROR_RETURN(SCIF_UART_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Make sure this channel exists. */
    FSP_ERROR_RETURN(BSP_FEATURE_SCIF_CHANNELS & (1U << p_cfg->channel), FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    FSP_ASSERT(p_cfg->rxi_irq >= 0);
    FSP_ASSERT(p_cfg->txi_irq >= 0);
    FSP_ASSERT(p_cfg->tei_irq >= 0);
    FSP_ASSERT(p_cfg->eri_irq >= 0);
    FSP_ASSERT(((scif_uart_extended_cfg_t *) p_cfg->p_extend)->bri_irq >= 0);
 #if (SCIF_UART_CFG_FLOW_CONTROL_SUPPORT)
    if (((scif_uart_extended_cfg_t *) p_cfg->p_extend)->uart_mode != SCIF_UART_MODE_RS232)
    {
        FSP_ERROR_RETURN(
            ((scif_uart_extended_cfg_t *) p_cfg->p_extend)->rs485_setting.de_control_pin != SCIF_UART_INVALID_16BIT_PARAM,
            FSP_ERR_INVALID_ARGUMENT);
    }
 #endif
#endif

    p_ctrl->p_reg = (R_SCIFA0_Type *) p_scif_base_address[p_cfg->channel];

    p_ctrl->p_cfg = p_cfg;

    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;

    /* Configure the interrupts. */
    r_scif_irqs_cfg(p_ctrl, p_cfg);

#if SCIF_UART_CFG_DMAC_ENABLE

    /* Configure the transfer interface for transmission and reception if provided. */
    fsp_err_t err = r_scif_uart_transfer_open(p_ctrl, p_cfg);

    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    scif_uart_extended_cfg_t * p_extend = (scif_uart_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    /* Enable the SCIF channel. */
    R_BSP_MODULE_START(FSP_IP_SCIF, p_cfg->channel);

    /* Initialize registers as defined in section "SCIFA Initialization in Asynchronous Mode" in the user's
     * manual or the relevant section for the MPU being used. */
    p_ctrl->p_reg->SCR = 0U;
    uint32_t fcr = p_ctrl->p_reg->FCR;
    fcr               |= (R_SCIFA0_FCR_TFRST_Msk | R_SCIFA0_FCR_RFRST_Msk);
    p_ctrl->p_reg->FCR = (uint16_t) fcr;
    p_ctrl->p_reg->FSR;
    p_ctrl->p_reg->FSR = 0;
    p_ctrl->p_reg->LSR;
    p_ctrl->p_reg->LSR = 0;

    uint32_t scr = 0;

    switch (p_extend->clock)
    {
        case SCIF_UART_CLOCK_INT:
        {
            scr = 0 << R_SCIFA0_SCR_CKE_Pos;
            break;
        }

        case SCIF_UART_CLOCK_INT_WITH_BAUDRATE_OUTPUT:
        {
            scr = 1 << R_SCIFA0_SCR_CKE_Pos;
            break;
        }

        default:
        {
            scr = 2 << R_SCIFA0_SCR_CKE_Pos;
        }
    }

    p_ctrl->p_reg->SCR = (uint16_t) scr;

    /* Set the UART configuration settings provided in ::uart_cfg_t and ::scif_uart_extended_cfg_t. */
    r_scif_uart_config_set(p_ctrl, p_cfg);

    /* Set the default level of the TX pin to 1. */
    p_ctrl->sptr = R_SCIFA0_SPTR_SPB2IO_Msk | R_SCIFA0_SPTR_SPB2DT_Msk;

    p_ctrl->p_tx_src      = NULL;
    p_ctrl->tx_src_bytes  = 0U;
    p_ctrl->p_rx_dest     = NULL;
    p_ctrl->rx_dest_bytes = 0;

#if (SCIF_UART_CFG_RX_ENABLE)

    /* If reception is enabled at build time, enable reception. */
    /* NOTE: Transmitter and its interrupt are enabled in R_SCIF_UART_Write(). */
    scr |= R_SCIFA0_SCR_RE_Msk;
    R_BSP_IrqEnable(p_ctrl->p_cfg->rxi_irq);
    R_BSP_IrqEnable(p_ctrl->p_cfg->eri_irq);
    R_BSP_IrqEnable(p_extend->bri_irq);

    scr |= R_SCIFA0_SCR_RIE_Msk;
#endif

#if (SCIF_UART_CFG_TX_ENABLE)

    /* To Acceptable transfer interrupts */
    R_BSP_IrqEnable(p_ctrl->p_cfg->txi_irq);
    R_BSP_IrqEnable(p_ctrl->p_cfg->tei_irq);
    scr |= R_SCIFA0_SCR_TE_Msk;
#endif
    p_ctrl->p_reg->SCR = (uint16_t) scr;

#if BSP_FEATURE_SCIF_RTSCTS_SUPPORT

    /* Automatic RTS/CTS control */
    if (p_extend->flow_control != SCIF_UART_FLOW_CONTROL_NONE)
    {
        /* Controlled by IP */
        p_ctrl->p_reg->FCR_b.MCE = 1;
    }
    else
    {
        /* Always RTS */
        p_ctrl->sptr            |= (R_SCIFA0_SPTR_RTS2IO_Msk | R_SCIFA0_SPTR_RTS2DT_Msk);
        p_ctrl->p_reg->FCR_b.MCE = 0;
    }
#endif

#if SCIF_UART_CFG_FLOW_CONTROL_SUPPORT
    if ((p_extend->rs485_setting.de_control_pin != SCIF_UART_INVALID_16BIT_PARAM) &&
        (p_extend->uart_mode != SCIF_UART_MODE_RS232))
    {
        if (p_extend->uart_mode == SCIF_UART_MODE_RS485_FD)
        {
            R_BSP_PinAccessEnable();

            /* Assert driver enable if RS-485 FullDuplex mode is enabled. */
            bsp_io_level_t level = SCIF_UART_RS485_DE_POLARITY_HIGH ==
                                   p_extend->rs485_setting.polarity ? BSP_IO_LEVEL_HIGH : BSP_IO_LEVEL_LOW;
            R_BSP_PinWrite(p_extend->rs485_setting.de_control_pin, level);

            R_BSP_PinAccessDisable();
        }
        else
        {
            /* Negate driver enable if RS-485 HalfDuplex mode is enabled. */
            r_scif_negate_de_pin(p_ctrl);
        }
    }
#endif

    p_ctrl->p_reg->SPTR = p_ctrl->sptr;

    p_ctrl->open = SCIF_UART_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Aborts any in progress transfers. Disables interrupts, receiver, and transmitter.  Closes lower level transfer
 * drivers if used. Removes power. Implements @ref uart_api_t::close
 *
 * @retval  FSP_SUCCESS              Channel successfully closed.
 * @retval  FSP_ERR_ASSERTION        Pointer to UART control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN         The control block has not been opened
 **********************************************************************************************************************/
fsp_err_t R_SCIF_UART_Close (uart_ctrl_t * const p_api_ctrl)
{
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) p_api_ctrl;
#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(SCIF_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Mark the channel not open so other APIs cannot use it. */
    p_ctrl->open = 0U;

    /* Disable interrupts, receiver, and transmitter. Disable baud clock output.*/
    p_ctrl->p_reg->SCR = 0U;

#if (SCIF_UART_CFG_RX_ENABLE)
    scif_uart_extended_cfg_t * p_extend = (scif_uart_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    /* If reception is enabled at build time, disable reception irqs. */
    R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);
    R_BSP_IrqDisable(p_ctrl->p_cfg->eri_irq);
    R_BSP_IrqDisable(p_extend->bri_irq);
#endif
#if (SCIF_UART_CFG_TX_ENABLE)

    /* If transmission is enabled at build time, disable transmission irqs. */
    R_BSP_IrqDisable(p_ctrl->p_cfg->txi_irq);
    R_BSP_IrqDisable(p_ctrl->p_cfg->tei_irq);
#endif

#if SCIF_UART_CFG_DMAC_ENABLE

    /* Close the lower level transfer instances. */
    r_scif_uart_transfer_close(p_ctrl);
#endif

    /* Remove power to the channel. */
    R_BSP_MODULE_STOP(FSP_IP_SCIF, p_ctrl->p_cfg->channel);

    /* Negate driver enable if RS-485 mode is enabled. */
    r_scif_negate_de_pin(p_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Receives user specified number of bytes into destination buffer pointer. Implements @ref uart_api_t::read
 *
 * @retval  FSP_SUCCESS                  Data reception successfully ends.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART control block is NULL.
 *                                       Number of transfers outside the max or min boundary when transfer instance used
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened
 * @retval  FSP_ERR_IN_USE               A previous read operation is still in progress.
 * @retval  FSP_ERR_UNSUPPORTED          SCIF_UART_CFG_RX_ENABLE is set to 0
 *
 * @return                       See @ref RENESAS_ERROR_CODES
 **********************************************************************************************************************/
fsp_err_t R_SCIF_UART_Read (uart_ctrl_t * const p_api_ctrl, uint8_t * const p_dest, uint32_t const bytes)
{
#if (SCIF_UART_CFG_RX_ENABLE)
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t err = FSP_SUCCESS;

 #if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
    err = r_scif_read_write_param_check(p_ctrl, p_dest, bytes);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ERROR_RETURN(0U == p_ctrl->rx_dest_bytes, FSP_ERR_IN_USE);
 #endif

 #if SCIF_UART_CFG_DMAC_ENABLE

    /* Configure transfer instance to receive the requested number of bytes if transfer is used for reception. */
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
  #if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)

        /* Check that the number of transfers is within the 16-bit limit. */
        FSP_ASSERT(bytes <= SCIF_UART_DMAC_MAX_TRANSFER);
  #endif
        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_dest = (void *) p_dest;
        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->length = (uint16_t) bytes;

        err =
            p_ctrl->p_cfg->p_transfer_rx->p_api->reconfigure(p_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                             p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

        p_ctrl->rx_dest_bytes = 0;
    }
 #endif

    /* Save the destination address and size for use in rxi_isr. */
    p_ctrl->p_rx_dest     = p_dest;
    p_ctrl->rx_dest_bytes = bytes;

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
 * @retval  FSP_SUCCESS                  Data transmission finished successfully.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART control block is NULL.
 *                                       Number of transfers outside the max or min boundary when transfer instance used
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened
 * @retval  FSP_ERR_IN_USE               A UART transmission is in progress
 * @retval  FSP_ERR_UNSUPPORTED          SCIF_UART_CFG_TX_ENABLE is set to 0
 *
 * @return                       See @ref RENESAS_ERROR_CODES
 **********************************************************************************************************************/
fsp_err_t R_SCIF_UART_Write (uart_ctrl_t * const p_api_ctrl, uint8_t const * const p_src, uint32_t const bytes)
{
#if (SCIF_UART_CFG_TX_ENABLE)
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) p_api_ctrl;

 #if SCIF_UART_CFG_PARAM_CHECKING_ENABLE || SCIF_UART_CFG_DMAC_ENABLE
    fsp_err_t err = FSP_SUCCESS;
 #endif

 #if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
    err = r_scif_read_write_param_check(p_ctrl, p_src, bytes);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ERROR_RETURN(0U == p_ctrl->tx_src_bytes, FSP_ERR_IN_USE);
 #endif

    /* Transmit interrupts must be disabled to start with. */
    p_ctrl->p_reg->SCR_b.TIE  = 0;
    p_ctrl->p_reg->SCR_b.TEIE = 0;

    p_ctrl->tx_src_bytes = bytes;
    p_ctrl->p_tx_src     = p_src;

 #if SCIF_UART_CFG_DMAC_ENABLE

    /* If a transfer instance is used for transmission, reset the transfer instance to transmit the requested
     * data. */
    if ((NULL != p_ctrl->p_cfg->p_transfer_tx) && p_ctrl->tx_src_bytes)
    {
        uint32_t num_transfer = p_ctrl->tx_src_bytes;
        p_ctrl->tx_src_bytes = 0;
  #if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)

        /* Check that the number of transfers is within the 16-bit limit. */
        FSP_ASSERT(num_transfer <= SCIF_UART_DMAC_MAX_TRANSFER);
  #endif

        p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->p_src  = (void const *) (p_ctrl->p_tx_src);
        p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->length = (uint16_t) num_transfer;

        err = p_ctrl->p_cfg->p_transfer_tx->p_api->reconfigure(p_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                               p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
 #endif

 #if (SCIF_UART_CFG_FLOW_CONTROL_SUPPORT)
    scif_uart_extended_cfg_t * p_extend = (scif_uart_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    /* If RS-485 is enabled, then assert the driver enable pin at the start of a write transfer. */
    if (p_extend->uart_mode == SCIF_UART_MODE_RS485_HD)
    {
        R_BSP_PinAccessEnable();

        bsp_io_level_t level = SCIF_UART_RS485_DE_POLARITY_HIGH ==
                               p_extend->rs485_setting.polarity ? BSP_IO_LEVEL_HIGH : BSP_IO_LEVEL_LOW;
        R_BSP_PinWrite(p_extend->rs485_setting.de_control_pin, level);

        R_BSP_PinAccessDisable();
    }
 #endif

    /* Trigger a TXI interrupt */
    p_ctrl->p_reg->SCR_b.TIE = 1;

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_src);
    FSP_PARAMETER_NOT_USED(bytes);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements uart_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_SCIF_UART_CallbackSet (uart_ctrl_t * const          p_api_ctrl,
                                   void (                     * p_callback)(uart_callback_args_t *),
                                   void const * const           p_context,
                                   uart_callback_args_t * const p_callback_memory)
{
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) p_api_ctrl;

#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(SCIF_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if SCIF_UART_CFG_PARAM_CHECKING_ENABLE

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
 * Updates the baud rate using the clock selected in Open. p_baud_setting is a pointer to a scif_baud_setting_t
 * structure.
 * Implements @ref uart_api_t::baudSet
 *
 * @warning This terminates any in-progress transmission.
 *
 * @retval  FSP_SUCCESS                  Baud rate was successfully changed.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART control block is NULL or the UART is not configured to use the
 *                                       internal clock.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened
 **********************************************************************************************************************/
fsp_err_t R_SCIF_UART_BaudSet (uart_ctrl_t * const p_api_ctrl, void const * const p_baud_setting)
{
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) p_api_ctrl;

#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(SCIF_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Verify that the On-Chip baud rate generator is currently selected. */
    FSP_ASSERT((p_ctrl->p_reg->SCR_b.CKE & 0x2) == 0U);
#endif

    /* Disables transmitter and receiver. This terminates any in-progress transmission. */
    uint32_t scr = p_ctrl->p_reg->SCR;
    scr &= (~(
                R_SCIFA0_SCR_TE_Msk |
                R_SCIFA0_SCR_TIE_Msk |
                R_SCIFA0_SCR_TEIE_Msk |
                R_SCIFA0_SCR_RE_Msk |
                R_SCIFA0_SCR_RIE_Msk));
    p_ctrl->p_reg->SCR = (uint16_t) scr;
    p_ctrl->p_tx_src   = NULL;

    /* Apply new baud rate register settings. */
    r_scif_uart_baud_set(p_ctrl->p_reg, p_baud_setting);

#if (SCIF_UART_CFG_RX_ENABLE)

    /* Enable receive. */
    scr |= (R_SCIFA0_SCR_RE_Msk | R_SCIFA0_SCR_RIE_Msk);
#endif
#if (SCIF_UART_CFG_TX_ENABLE)

    /* Enable transmit. */
    scr |= R_SCIFA0_SCR_TE_Msk;
#endif
    p_ctrl->p_reg->SCR = (uint16_t) scr;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provides the driver information, including the maximum number of bytes that can be received or transmitted at a time.
 * Implements @ref uart_api_t::infoGet
 *
 * @retval  FSP_SUCCESS                  Information stored in provided p_info.
 * @retval  FSP_ERR_ASSERTION            Pointer to UART control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened
 **********************************************************************************************************************/
fsp_err_t R_SCIF_UART_InfoGet (uart_ctrl_t * const p_api_ctrl, uart_info_t * const p_info)
{
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) p_api_ctrl;

#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_info);
    FSP_ERROR_RETURN(SCIF_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    p_info->read_bytes_max  = SCIF_UART_MAX_READ_WRITE;
    p_info->write_bytes_max = SCIF_UART_MAX_READ_WRITE;

#if (SCIF_UART_CFG_RX_ENABLE)

    /* Store number of bytes that can be read at a time. */
 #if SCIF_UART_CFG_DMAC_ENABLE
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        p_info->write_bytes_max = SCIF_UART_DMAC_MAX_TRANSFER;
    }
 #endif
#endif

#if (SCIF_UART_CFG_TX_ENABLE)

    /* Store number of bytes that can be written at a time. */
 #if SCIF_UART_CFG_DMAC_ENABLE
    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        p_info->read_bytes_max = SCIF_UART_DMAC_MAX_TRANSFER;
    }
 #endif
#endif

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
 *
 * @return                       See @ref RENESAS_ERROR_CODES or functions called by this function for other possible
 *                               return codes.
 **********************************************************************************************************************/
fsp_err_t R_SCIF_UART_Abort (uart_ctrl_t * const p_api_ctrl, uart_dir_t communication_to_abort)
{
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t err = FSP_ERR_UNSUPPORTED;

#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(SCIF_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if (SCIF_UART_CFG_TX_ENABLE)
    if (UART_DIR_TX & communication_to_abort)
    {
        err = FSP_SUCCESS;
        uint32_t scr = p_ctrl->p_reg->SCR;
        scr               &= (~(R_SCIFA0_SCR_TIE_Msk | R_SCIFA0_SCR_TEIE_Msk));
        p_ctrl->p_reg->SCR = (uint16_t) scr;
 #if SCIF_UART_CFG_DMAC_ENABLE
        if (NULL != p_ctrl->p_cfg->p_transfer_tx)
        {
            err = p_ctrl->p_cfg->p_transfer_tx->p_api->disable(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);
        }
 #endif
        p_ctrl->tx_src_bytes = 0U;

        /* Reset the transmit fifo */
        p_ctrl->p_reg->FCR_b.TFRST = 1U;

        /* Confirm that 1 can be written to TFRST. */
        FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->FCR_b.TFRST, 1);

        /* Clear the TFRST bit */
        p_ctrl->p_reg->FCR_b.TFRST = 0U;

        /* Negate driver enable if RS-485 mode is enabled. */
        r_scif_negate_de_pin(p_ctrl);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
#endif
#if (SCIF_UART_CFG_RX_ENABLE)
    if (UART_DIR_RX & communication_to_abort)
    {
        err = FSP_SUCCESS;

        p_ctrl->rx_dest_bytes = 0U;
 #if SCIF_UART_CFG_DMAC_ENABLE
        if (NULL != p_ctrl->p_cfg->p_transfer_rx)
        {
            err = p_ctrl->p_cfg->p_transfer_rx->p_api->disable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
        }
 #endif

        /* Reset the receive fifo */
        p_ctrl->p_reg->FCR_b.RFRST = 1U;

        /* Confirm that 1 can be written to RFRST. */
        FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->FCR_b.RFRST, 1);

        /* Clear the RFRST bit */
        p_ctrl->p_reg->FCR_b.RFRST = 0U;
    }
#endif

    return err;
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
 * @retval  FSP_ERR_UNSUPPORTED          The requested Abort direction is unsupported.
 *
 * @return                       See @ref RENESAS_ERROR_CODES or functions called by this function for other possible
 *                               return codes.
 **********************************************************************************************************************/
fsp_err_t R_SCIF_UART_ReadStop (uart_ctrl_t * const p_api_ctrl, uint32_t * remaining_bytes)
{
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) p_api_ctrl;

#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(SCIF_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if (SCIF_UART_CFG_RX_ENABLE)
    *remaining_bytes      = p_ctrl->rx_dest_bytes;
    p_ctrl->rx_dest_bytes = 0U;

    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        fsp_err_t err = p_ctrl->p_cfg->p_transfer_rx->p_api->disable(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

        transfer_properties_t transfer_info;
        err = p_ctrl->p_cfg->p_transfer_rx->p_api->infoGet(p_ctrl->p_cfg->p_transfer_rx->p_ctrl, &transfer_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        *remaining_bytes = transfer_info.transfer_length_remaining;
    }

    /* Reset the receive fifo */
    p_ctrl->p_reg->FCR_b.RFRST = 1U;

    /* Confirm that 1 can be written to RFRST. */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->FCR_b.RFRST, 1);

    /* Clear the RFRST bit */
    p_ctrl->p_reg->FCR_b.RFRST = 0U;
#else

    return FSP_ERR_UNSUPPORTED;
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Calculates baud rate register settings. Evaluates and determines the best possible settings set to the baud rate
 * related registers.
 *
 * @param[in]  p_api_ctrl                Pointer to the UART control block.
 * @param[in]  baudrate                  Baud rate [bps]. For example, 19200, 57600, 115200, etc.
 * @param[in]  bitrate_modulation        Enable bitrate modulation
 * @param[in]  baud_rate_error_x_1000    &lt;baud_rate_percent_error&gt; x 1000 required for module to function.
 *                                       Absolute max baud_rate_error is 15000 (15%).
 * @param[out] p_baud_setting            Baud setting information stored here if successful
 *
 * @retval     FSP_SUCCESS               Baud rate is set successfully
 * @retval     FSP_ERR_ASSERTION         Null pointer
 * @retval     FSP_ERR_INVALID_ARGUMENT  Baud rate is '0', source clock frequency could not be read, or error in
 *                                       calculated baud rate is larger than 10%.
 **********************************************************************************************************************/
fsp_err_t R_SCIF_UART_BaudCalculate (uart_ctrl_t * const         p_api_ctrl,
                                     uint32_t                    baudrate,
                                     bool                        bitrate_modulation,
                                     uint32_t                    baud_rate_error_x_1000,
                                     scif_baud_setting_t * const p_baud_setting)
{
#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_api_ctrl);
    FSP_ASSERT(p_baud_setting);
    FSP_ERROR_RETURN(SCIF_UART_MAX_BAUD_RATE_ERROR_X_1000 >= baud_rate_error_x_1000, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((0U != baudrate), FSP_ERR_INVALID_ARGUMENT);
#endif
#if BSP_FEATURE_SCIF_CKS2_LIMITATION
    scif_uart_instance_ctrl_t const * p_ctrl = (scif_uart_instance_ctrl_t const *) p_api_ctrl;
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
#endif
    p_baud_setting->brr = SCIF_UART_BRR_MAX;
    p_baud_setting->semr_baudrate_bits_b.brme = 0U;
    p_baud_setting->mddr = SCIF_UART_MDDR_MIN;

    /* Find the best BRR (bit rate register) value.
     *  In table g_async_baud, divisor values are stored for BGDM, ABCS, ABCSE and N values.  Each set of divisors
     *  is tried, and the settings with the lowest bit rate error are stored. The formula to calculate BRR is as
     *  follows and it must be 255 or less:
     *  BRR = (PCLK / (div_coefficient * baud)) - 1
     */
    int32_t  hit_bit_err = SCIF_UART_100_PERCENT_X_1000;
    uint8_t  hit_mddr    = 0U;
    uint32_t divisor     = 0U;

    uint32_t freq_hz = R_FSP_SystemClockHzGet(BSP_FEATURE_SCIF_CLOCK);

    for (uint32_t select_16_base_clk_cycles = 0U;
         (select_16_base_clk_cycles <= 1U) && (hit_bit_err > ((int32_t) baud_rate_error_x_1000));
         select_16_base_clk_cycles++)
    {
        for (uint32_t i = 0U; i < SCIF_UART_NUM_DIVISORS_ASYNC; i++)
        {
            /* if select_16_base_clk_cycles == true:  Skip this calculation for divisors that are not acheivable with
             *   16 base clk cycles per bit.
             *  if select_16_base_clk_cycles == false: Skip this calculation for divisors that are only acheivable
             *   without 16 base clk cycles per bit.
             */
            if (((uint8_t) select_16_base_clk_cycles) ^ (g_async_baud[i].abcs))
            {
                continue;
            }

#if BSP_FEATURE_SCIF_CKS2_LIMITATION
            if ((p_ctrl->p_cfg->channel == 0) && (g_async_baud[i].cks == 2))
            {
                /* Skip if channel eq 0 and cks eq 2 */
                continue;
            }
#endif
            divisor = (uint32_t) g_div_coefficient[i] * baudrate;
            uint32_t temp_brr = freq_hz / divisor;

            if (temp_brr <= (SCIF_UART_BRR_MAX + 1U))
            {
                while (temp_brr > 0U)
                {
                    temp_brr -= 1U;

                    /* Calculate the bit rate error. The formula is as follows:
                     *  bit rate error[%] = {(PCLK / (baud * div_coefficient * (BRR + 1)) - 1} x 100
                     *  calculates bit rate error[%] to three decimal places
                     */
                    int32_t err_divisor = (int32_t) (divisor * (temp_brr + 1U));

                    /* Promoting to 64 bits for calculation, but the final value can never be more than 32 bits, as
                     * described below, so this cast is safe.
                     *    1. (temp_brr + 1) can be off by an upper limit of 1 due to rounding from the calculation:
                     *       freq_hz / divisor, or:
                     *       freq_hz / divisor <= (temp_brr + 1) < (freq_hz / divisor) + 1
                     *    2. Solving for err_divisor:
                     *       freq_hz <= err_divisor < freq_hz + divisor
                     *    3. Solving for bit_err:
                     *       0 >= bit_err >= (freq_hz * 100000 / (freq_hz + divisor)) - 100000
                     *    4. freq_hz >= divisor (or temp_brr would be -1 and we would never enter this while loop), so:
                     *       0 >= bit_err >= 100000 / freq_hz - 100000
                     *    5. Larger frequencies yield larger bit errors (absolute value).  As the frequency grows,
                     *       the bit_err approaches -100000, so:
                     *       0 >= bit_err >= -100000
                     *    6. bit_err is between -100000 and 0.  This entire range fits in an int32_t type, so the cast
                     *       to (int32_t) is safe.
                     */
                    int32_t bit_err = (int32_t) ((((int64_t) freq_hz * SCIF_UART_100_PERCENT_X_1000) / err_divisor) -
                                                 SCIF_UART_100_PERCENT_X_1000);

                    uint8_t mddr = 0;
                    if (bitrate_modulation)
                    {
                        /* Calculate the MDDR (M) value if bit rate modulation is enabled,
                         * The formula to calculate MBBR (from the M and N relationship given in the hardware manual)
                         * is as follows and it must be between 128 and 255.
                         * MDDR = ((div_coefficient * baud * 256) * (BRR + 1)) / PCLK */
                        mddr = (uint8_t) ((uint32_t) err_divisor / (freq_hz / SCIF_UART_MDDR_MAX));

                        /* MDDR value must be greater than or equal to SCIF_UART_MDDR_MIN. */
                        if (mddr < SCIF_UART_MDDR_MIN)
                        {
                            break;
                        }

                        /* Adjust bit rate error for bit rate modulation. The following formula is used:
                         *  bit rate error [%] = ((bit rate error [%, no modulation] + 100) * MDDR / 256) - 100
                         */
                        bit_err =
                            (((bit_err + SCIF_UART_100_PERCENT_X_1000) * (int32_t) mddr) / SCIF_UART_MDDR_DIVISOR) -
                            SCIF_UART_100_PERCENT_X_1000;
                    }

                    /* Take the absolute value of the bit rate error. */
                    if (bit_err < 0)
                    {
                        bit_err = -bit_err;
                    }

                    /* If the absolute value of the bit rate error is less than the previous lowest absolute value of
                     *  bit rate error, then store these settings as the best value.
                     */
                    if (bit_err < hit_bit_err)
                    {
                        p_baud_setting->semr_baudrate_bits_b.bgdm = g_async_baud[i].bgdm;
                        p_baud_setting->semr_baudrate_bits_b.abcs = g_async_baud[i].abcs;
                        p_baud_setting->semr_baudrate_bits_b.cks  = g_async_baud[i].cks;
                        p_baud_setting->brr = (uint8_t) temp_brr;
                        hit_bit_err         = bit_err;
                        hit_mddr            = mddr;
                    }

                    if (bitrate_modulation)
                    {
                        p_baud_setting->semr_baudrate_bits_b.brme = 1U;
                        p_baud_setting->mddr = hit_mddr;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    /* Return an error if the percent error is larger than the maximum percent error allowed for this instance */
    FSP_ERROR_RETURN((hit_bit_err <= (int32_t) baud_rate_error_x_1000), FSP_ERR_INVALID_ARGUMENT);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup SCIF_UART)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Negate the DE pin if it is enabled.
 *
 * @param[in] p_ctrl Pointer to the control block for the channel.
 **********************************************************************************************************************/
static void r_scif_negate_de_pin (scif_uart_instance_ctrl_t const * const p_ctrl)
{
#if (SCIF_UART_CFG_FLOW_CONTROL_SUPPORT)
    scif_uart_extended_cfg_t * p_extend = (scif_uart_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    /* If RS-485 is enabled, then negate the driver enable pin at the end of a write transfer. */
    if (p_extend->uart_mode == SCIF_UART_MODE_RS485_HD)
    {
        R_BSP_PinAccessEnable();
        bsp_io_level_t level = SCIF_UART_RS485_DE_POLARITY_HIGH ==
                               p_extend->rs485_setting.polarity ? BSP_IO_LEVEL_LOW : BSP_IO_LEVEL_HIGH;
        R_BSP_PinWrite(p_extend->rs485_setting.de_control_pin, level);

        R_BSP_PinAccessDisable();
    }

#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif
}

#if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)

/*******************************************************************************************************************//**
 * Parameter error check function for read/write.
 *
 * @param[in] p_ctrl Pointer to the control block for the channel
 * @param[in] addr   Pointer to the buffer
 * @param[in] bytes  Number of bytes to read or write
 *
 * @retval  FSP_SUCCESS              No parameter error found
 * @retval  FSP_ERR_NOT_OPEN         The control block has not been opened
 * @retval  FSP_ERR_ASSERTION        Pointer to UART control block or configuration structure is NULL
 **********************************************************************************************************************/
static fsp_err_t r_scif_read_write_param_check (scif_uart_instance_ctrl_t const * const p_ctrl,
                                                uint8_t const * const                   addr,
                                                uint32_t const                          bytes)
{
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(addr);
    FSP_ASSERT(0U != bytes);
    FSP_ERROR_RETURN(SCIF_UART_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);

    return FSP_SUCCESS;
}

#endif

#if SCIF_UART_CFG_DMAC_ENABLE

/*******************************************************************************************************************//**
 * Subroutine to apply common UART transfer settings.
 *
 * @param[in]  p_cfg              Pointer to UART specific configuration structure
 * @param[in]  p_transfer         Pointer to transfer instance to configure
 *
 * @retval     FSP_SUCCESS        UART transfer drivers successfully configured
 * @retval     FSP_ERR_ASSERTION  Invalid pointer
 **********************************************************************************************************************/
static fsp_err_t r_scif_uart_transfer_configure (transfer_instance_t const * p_transfer,
                                                 uint32_t                  * p_transfer_reg,
                                                 uint32_t                    scif_buffer_address)
{
    /* Configure the transfer instance, if enabled. */
 #if (SCIF_UART_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_transfer->p_api);
    FSP_ASSERT(NULL != p_transfer->p_ctrl);
    FSP_ASSERT(NULL != p_transfer->p_cfg);
    FSP_ASSERT(NULL != p_transfer->p_cfg->p_info);
    FSP_ASSERT(NULL != p_transfer->p_cfg->p_extend);
 #endif

    /* Casting for compatibility with 7 or 8 bit mode. */
    *p_transfer_reg = scif_buffer_address;

    fsp_err_t err = p_transfer->p_api->open(p_transfer->p_ctrl, p_transfer->p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configures UART related transfer drivers (if enabled).
 *
 * @param[in]     p_ctrl  Pointer to UART control structure
 * @param[in]     p_cfg   Pointer to UART specific configuration structure
 *
 * @retval        FSP_SUCCESS        UART transfer drivers successfully configured
 * @retval        FSP_ERR_ASSERTION  Invalid pointer or required interrupt not enabled in vector table
 *
 * @return                       See @ref RENESAS_ERROR_CODES or functions called by this function for other possible
 *                               return codes. This function calls:
 *                                   * @ref transfer_api_t::open
 **********************************************************************************************************************/
static fsp_err_t r_scif_uart_transfer_open (scif_uart_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;

 #if (SCIF_UART_CFG_RX_ENABLE)

    /* If a transfer instance is used for reception, apply UART specific settings and open the transfer instance. */
    if (NULL != p_cfg->p_transfer_rx)
    {
        transfer_info_t * p_info = p_cfg->p_transfer_rx->p_cfg->p_info;

        err = r_scif_uart_transfer_configure(p_cfg->p_transfer_rx,
                                             (uint32_t *) &p_info->p_src,
                                             (uint32_t) (uintptr_t) &(p_ctrl->p_reg->FRDR));
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
 #endif
 #if (SCIF_UART_CFG_TX_ENABLE)

    /* If a transfer instance is used for transmission, apply UART specific settings and open the transfer instance. */
    if (NULL != p_cfg->p_transfer_tx)
    {
        transfer_info_t * p_info = p_cfg->p_transfer_tx->p_cfg->p_info;

        err = r_scif_uart_transfer_configure(p_cfg->p_transfer_tx,
                                             (uint32_t *) &p_info->p_dest,
                                             (uint32_t) (uintptr_t) &(p_ctrl->p_reg->FTDR));

  #if (SCIF_UART_CFG_RX_ENABLE)
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

/*******************************************************************************************************************//**
 * Closes transfer interfaces.
 *
 * @param[in]     p_ctrl     Pointer to UART instance control block
 **********************************************************************************************************************/
static void r_scif_uart_transfer_close (scif_uart_instance_ctrl_t * p_ctrl)
{
 #if (SCIF_UART_CFG_RX_ENABLE)
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        p_ctrl->p_cfg->p_transfer_rx->p_api->close(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
    }
 #endif
 #if (SCIF_UART_CFG_TX_ENABLE)
    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        p_ctrl->p_cfg->p_transfer_tx->p_api->close(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);
    }
 #endif
}

#endif

/*******************************************************************************************************************//**
 * Configures UART related registers based on user configurations.
 *
 * @param[in]     p_ctrl  Pointer to UART control structure
 * @param[in]     p_cfg   Pointer to UART specific configuration structure
 **********************************************************************************************************************/
static void r_scif_uart_config_set (scif_uart_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg)
{
    /* Configure SMR register (data size, parity and stop bits). */
    /* Note: CKS part is set by r_scif_uart_baud_set function. */
    uint32_t smr = 0;
    if (p_cfg->data_bits == UART_DATA_BITS_7)
    {
        smr |= R_SCIFA0_SMR_CHR_Msk;
    }

    if (p_cfg->parity != UART_PARITY_OFF)
    {
        smr |= R_SCIFA0_SMR_PE_Msk;
    }

    if (p_cfg->parity == UART_PARITY_ODD)
    {
        smr |= R_SCIFA0_SMR_PM_Msk;
    }

    if (p_cfg->stop_bits == UART_STOP_BITS_2)
    {
        smr |= R_SCIFA0_SMR_STOP_Msk;
    }

    /* Write to the SMR register. */
    p_ctrl->p_reg->SMR = (uint16_t) smr;

    scif_uart_extended_cfg_t * p_extend = (scif_uart_extended_cfg_t *) p_cfg->p_extend;
    if ((SCIF_UART_CLOCK_EXT8X == p_extend->clock) || (SCIF_UART_CLOCK_EXT16X == p_extend->clock))
    {
        /* Use external clock for baud rate */
        uint32_t semr = 0;

        if (SCIF_UART_CLOCK_EXT8X == p_extend->clock)
        {
            /* Set baud rate as (external clock / 8) */
            semr |= R_SCIFA0_SEMR_ABCS0_Msk;
        }

        p_ctrl->p_reg->SEMR = (uint8_t) semr;

        p_ctrl->p_reg->BRR = SCIF_UART_BRR_DEFAULT_VALUE;
    }
    else
    {
        /* Set the baud rate settings for the internal baud rate generator. */
        r_scif_uart_baud_set(p_ctrl->p_reg, p_extend->p_baud_setting);
    }

    /* Configure FIFO related registers. */
    r_scif_uart_fifo_cfg(p_ctrl);

    /* Enables the noise cancellation, fixed to the minimum level, if enabled in the extension. */
    if (p_extend->noise_cancel != SCIF_UART_NOISE_CANCELLATION_DISABLE)
    {
        p_ctrl->p_reg->SEMR_b.NFEN = 1;
    }
    else
    {
        p_ctrl->p_reg->SEMR_b.NFEN = 0;
    }
}

/*******************************************************************************************************************//**
 * Make RTRG register field value
 *
 * @param[in] rtrg  Parameter on configuration table
 * @return RTRG Field value
 **********************************************************************************************************************/
static uint32_t r_scif_uart_make_rtrg (scif_uart_rx_fifo_trigger_t rtrg)
{
    uint32_t value = 0;
    switch (rtrg)
    {
        case SCIF_UART_RX_FIFO_TRIGGER_ONE:
        {
            /* stay RTRG as 0 */
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_QUARTER:
        {
            value = 1 << R_SCIFA0_FCR_RTRG_Pos;
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_HALF:
        {
            value = 2 << R_SCIFA0_FCR_RTRG_Pos;
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_MAX:
        {
            value = 3 << R_SCIFA0_FCR_RTRG_Pos;
            break;
        }

        default:
        {
            /* stay RTRG as 0 */
            break;
        }
    }

    return value;
}

/*******************************************************************************************************************//**
 * Make RTRGS and RFTC register field value
 *
 * @param[in] rtrg  Parameter on configuration table
 * @return RFTC|RTRGS Field value
 **********************************************************************************************************************/
static uint32_t r_scif_uart_make_rftc (scif_uart_rx_fifo_trigger_t rtrg)
{
    uint32_t value = 0;
    switch (rtrg)
    {
        case SCIF_UART_RX_FIFO_TRIGGER_1:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (1 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_2:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (2 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_3:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (3 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_4:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (4 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_5:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (5 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_6:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (6 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_7:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (7 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_8:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (8 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_9:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (9 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_10:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (10 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_11:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (11 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_12:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (12 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_13:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (13 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_14:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (14 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        case SCIF_UART_RX_FIFO_TRIGGER_15:
        {
            value = R_SCIFA0_FTCR_RTRGS_Msk | (15 << R_SCIFA0_FTCR_RFTC_Pos);
            break;
        }

        default:
        {
            /* stay RFTC and RTRGS as 0 */
            break;
        }
    }

    return value;
}

#if BSP_FEATURE_SCIF_RTSCTS_SUPPORT

/*******************************************************************************************************************//**
 * Make RSTRG register field value
 *
 * @param[in] rstrg  Parameter on configuration table
 * @return RSTRG Field value
 **********************************************************************************************************************/
static uint32_t r_scif_uart_make_rstrg (scif_uart_rts_trigger_t rstrg)
{
    uint32_t value = 0;
    switch (rstrg)
    {
        case SCIF_UART_RTS_TRIGGER_1:
        {
            value = 1 << R_SCIFA0_FCR_RSTRG_Pos;
            break;
        }

        case SCIF_UART_RTS_TRIGGER_4:
        {
            value = 2 << R_SCIFA0_FCR_RSTRG_Pos;
            break;
        }

        case SCIF_UART_RTS_TRIGGER_6:
        {
            value = 3 << R_SCIFA0_FCR_RSTRG_Pos;
            break;
        }

        case SCIF_UART_RTS_TRIGGER_8:
        {
            value = 4 << R_SCIFA0_FCR_RSTRG_Pos;
            break;
        }

        case SCIF_UART_RTS_TRIGGER_10:
        {
            value = 5 << R_SCIFA0_FCR_RSTRG_Pos;
            break;
        }

        case SCIF_UART_RTS_TRIGGER_12:
        {
            value = 6 << R_SCIFA0_FCR_RSTRG_Pos;
            break;
        }

        case SCIF_UART_RTS_TRIGGER_14:
        {
            value = 7 << R_SCIFA0_FCR_RSTRG_Pos;
            break;
        }

        case SCIF_UART_RTS_TRIGGER_15:
        {
            /* Stay RSTRG as 0 */
            break;
        }

        default:
        {
            /* Stay RSTRG as 0 */
            break;
        }
    }

    return value;
}

#endif

/*******************************************************************************************************************//**
 * Resets FIFO related registers.
 *
 * @param[in] p_ctrl  Pointer to UART instance control
 **********************************************************************************************************************/
static void r_scif_uart_fifo_cfg (scif_uart_instance_ctrl_t * const p_ctrl)
{
    /* Enable the fifo and set the tx and rx reset bits */
    uint32_t fcr = p_ctrl->p_reg->FCR;
    fcr |= (R_SCIFA0_FCR_RFRST_Msk | R_SCIFA0_FCR_TFRST_Msk);
#if BSP_FEATURE_SCIF_RTSCTS_SUPPORT
    fcr &= (~(R_SCIFA0_FCR_RTRG_Msk | R_SCIFA0_FCR_TTRG_Msk | R_SCIFA0_FCR_RSTRG_Msk));
#else
    fcr &= (~(R_SCIFA0_FCR_RTRG_Msk | R_SCIFA0_FCR_TTRG_Msk));
#endif
    p_ctrl->p_reg->FCR = (uint16_t) fcr;
    uint32_t ftcr = 0U;

#if (SCIF_UART_CFG_RX_ENABLE)
    {
        /* Otherwise, set receive trigger number as configured by the user. */
        scif_uart_extended_cfg_t const * p_extend = p_ctrl->p_cfg->p_extend;

        /* RTRG(Receive FIFO Data Trigger Number) controls when the RXI interrupt will be generated. If data is
         * received but the trigger number is not met the RXI interrupt will be generated after 15 ETUs from
         * the last stop bit in asynchronous mode. For more information see the FIFO Selected section of "Serial Data
         * Reception in Asynchronous Mode" in the user's manual or the relevant section for the MPU being used. */
        ftcr = r_scif_uart_make_rftc(p_extend->rx_fifo_trigger);
        fcr |= r_scif_uart_make_rtrg(p_extend->rx_fifo_trigger);

 #if SCIF_UART_CFG_DMAC_ENABLE

        /* When using DMAC transfer, set the threshold of the interrupt generation condition to 0. */
        if (NULL != p_ctrl->p_cfg->p_transfer_rx)
        {
            ftcr |= R_SCIFA0_FTCR_RTRGS_Msk | (SCIF_UART_DMAC_RX_TRIGGER_LEVEL << R_SCIFA0_FTCR_RFTC_Pos);
        }

        if (NULL != p_ctrl->p_cfg->p_transfer_tx)
        {
            ftcr |= R_SCIFA0_FTCR_TTRGS_Msk;
        }
 #endif

 #if BSP_FEATURE_SCIF_RTSCTS_SUPPORT
        fcr |= r_scif_uart_make_rstrg(p_extend->rts_fifo_trigger);
 #endif
    }
#endif
    p_ctrl->p_reg->FTCR = (uint16_t) ftcr;

    /* Set the FCR for cancellation reset. */
    fcr               &= (~(R_SCIFA0_FCR_RFRST_Msk | R_SCIFA0_FCR_TFRST_Msk));
    p_ctrl->p_reg->FCR = (uint16_t) fcr;
}

/*******************************************************************************************************************//**
 * Sets interrupt priority and initializes vector info.
 *
 * @param[in]  p_ctrl                    Pointer to driver control block
 * @param[in]  ipl                       Interrupt priority level
 * @param[in]  irq                       IRQ number for this interrupt
 **********************************************************************************************************************/
static void r_scif_irq_cfg (scif_uart_instance_ctrl_t * const p_ctrl, uint8_t const ipl, IRQn_Type const irq)
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
 * @param[in]  p_ctrl                    Pointer to UART instance control block
 * @param[in]  p_cfg                     Pointer to UART specific configuration structure
 **********************************************************************************************************************/
static void r_scif_irqs_cfg (scif_uart_instance_ctrl_t * const p_ctrl, uart_cfg_t const * const p_cfg)
{
#if (SCIF_UART_CFG_RX_ENABLE)
    scif_uart_extended_cfg_t const * p_extend = (scif_uart_extended_cfg_t const *) p_ctrl->p_cfg->p_extend;

    /* ERI is optional. */
    r_scif_irq_cfg(p_ctrl, p_cfg->eri_ipl, p_cfg->eri_irq);
    r_scif_irq_cfg(p_ctrl, p_cfg->rxi_ipl, p_cfg->rxi_irq);
    r_scif_irq_cfg(p_ctrl, p_extend->bri_ipl, p_extend->bri_irq);
#endif
#if (SCIF_UART_CFG_TX_ENABLE)
    r_scif_irq_cfg(p_ctrl, p_cfg->txi_ipl, p_cfg->txi_irq);
    r_scif_irq_cfg(p_ctrl, p_cfg->tei_ipl, p_cfg->tei_irq);
#endif
}

/*******************************************************************************************************************//**
 * Changes baud rate based on predetermined register settings.
 *
 * @param[in]  p_scif_reg       Base pointer for SCIF registers
 * @param[in]  p_baud_setting  Pointer to other divisor related settings
 *
 * @note       The transmitter and receiver (TE and RE bits in SCR) must be disabled prior to calling this function.
 **********************************************************************************************************************/
static void r_scif_uart_baud_set (R_SCIFA0_Type * p_scif_reg, scif_baud_setting_t const * const p_baud_setting)
{
    /* Set BRR register value. */
    uint32_t semr = p_scif_reg->SEMR &
                    (~(R_SCIFA0_SEMR_MDDRS_Msk | R_SCIFA0_SEMR_ABCS0_Msk | R_SCIFA0_SEMR_BGDM_Msk |
                       R_SCIFA0_SEMR_BRME_Msk));
    p_scif_reg->SEMR = (uint8_t) semr;
    p_scif_reg->BRR  = p_baud_setting->brr;

    /* Set clock source for the on-chip baud rate generator. */
    p_scif_reg->SMR_b.CKS = p_baud_setting->semr_baudrate_bits_b.cks;

    /* Set MDDR register value. */
    if (p_baud_setting->semr_baudrate_bits_b.brme && (p_baud_setting->mddr >= SCIF_UART_MDDR_MIN))
    {
        p_scif_reg->SEMR = (uint8_t) semr | R_SCIFA0_SEMR_MDDRS_Msk;
        p_scif_reg->MDDR = p_baud_setting->mddr;
        semr            |= R_SCIFA0_SEMR_BRME_Msk;
    }

    /* Set clock divisor settings. */
    semr            |= ((unsigned) p_baud_setting->semr_baudrate_bits_b.abcs << R_SCIFA0_SEMR_ABCS0_Pos);
    semr            |= ((unsigned) p_baud_setting->semr_baudrate_bits_b.bgdm << R_SCIFA0_SEMR_BGDM_Pos);
    p_scif_reg->SEMR = (uint8_t) semr;
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to UART instance control block
 * @param[in]     data       See uart_callback_args_t in r_uart_api.h
 * @param[in]     event      Event code
 **********************************************************************************************************************/
static void r_scif_uart_call_callback (scif_uart_instance_ctrl_t * p_ctrl, uint32_t data, uart_event_t event)
{
    uart_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
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

#if BSP_TZ_SECURE_BUILD

    /* p_callback can point to a secure function or a non-secure function. */
    if (!cmse_is_nsfptr(p_ctrl->p_callback))
    {
        /* If p_callback is secure, then the project does not need to change security state. */
        p_ctrl->p_callback(p_args);
    }
    else
    {
        /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the
         * callback. */
        scif_uart_prv_ns_callback p_callback = (scif_uart_prv_ns_callback) (p_ctrl->p_callback);
        p_callback(p_args);
    }

#else

    /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the
     * callback. */
    p_ctrl->p_callback(p_args);
#endif
    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

#if (SCIF_UART_CFG_TX_ENABLE)

/*******************************************************************************************************************//**
 * TXI interrupt processing for UART mode. TXI interrupt fires when the data in the data register or FIFO register has
 * been transferred to the data shift register, and the next data can be written.  This interrupt writes the next data.
 * After the last data byte is written, this interrupt disables the TXI interrupt and enables the TEI (transmit end)
 * interrupt.
 **********************************************************************************************************************/
void scif_uart_txi_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    R_BSP_IrqStatusClear(irq);

    /* Recover ISR context saved in open. */
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if ((NULL == p_ctrl->p_cfg->p_transfer_tx) && (0U != p_ctrl->tx_src_bytes))
    {
        /* Write data until FIFO is full. */
        uint32_t fifo_count = (uint32_t) p_ctrl->p_reg->FDR_b.T;
        for (uint32_t cnt = fifo_count; (cnt < SCIF_UART_TX_FIFO_STAGES) && p_ctrl->tx_src_bytes; cnt++)
        {
            p_ctrl->p_reg->FTDR = *p_ctrl->p_tx_src;

            p_ctrl->tx_src_bytes -= 1;
            p_ctrl->p_tx_src     += 1;
        }

        /* Clear TDFE flag */
        p_ctrl->p_reg->FSR_b.TDFE = 0U;
    }

    if (0U == p_ctrl->tx_src_bytes)
    {
        /* After all data has been transmitted, disable transmit interrupts and enable the transmit end interrupt. */
        uint32_t scr_temp;
        scr_temp           = p_ctrl->p_reg->SCR;
        scr_temp          |= R_SCIFA0_SCR_TEIE_Msk;
        scr_temp          &= (~R_SCIFA0_SCR_TIE_Msk);
        p_ctrl->p_reg->SCR = (uint16_t) scr_temp;

        p_ctrl->p_tx_src = NULL;
        if (NULL != p_ctrl->p_callback)
        {
            r_scif_uart_call_callback(p_ctrl, 0U, UART_EVENT_TX_DATA_EMPTY);
        }
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

#endif

#if (SCIF_UART_CFG_RX_ENABLE)

/*******************************************************************************************************************//**
 * Common code for retrieving FIFO data on RXI and DRI.
 *
 * @param[in] p_ctrl Pointer to the control block for the channel
 * @retval    none
 **********************************************************************************************************************/
static void scif_uart_receive_sub (scif_uart_instance_ctrl_t * const p_ctrl)
{
    uint8_t      data;
    uint16_t     fsr;
    uart_event_t event;

    while (p_ctrl->p_reg->FDR_b.R > 0U)
    {
        event = 0;
        fsr   = p_ctrl->p_reg->FSR;
        data  = p_ctrl->p_reg->FRDR;

        /* Set error event */
        if (fsr & R_SCIFA0_FSR_FER_Msk)
        {
            event |= UART_EVENT_ERR_FRAMING;
        }

        if (fsr & R_SCIFA0_FSR_PER_Msk)
        {
            event |= UART_EVENT_ERR_PARITY;
        }

        if (0 == p_ctrl->rx_dest_bytes)
        {
            /* Call user callback with the data. */
            if (0 == event)
            {
                event |= UART_EVENT_RX_CHAR;
            }

            if (NULL != p_ctrl->p_callback)
            {
                r_scif_uart_call_callback(p_ctrl, (uint32_t) data, event);
            }
        }
        else
        {
            if (event)
            {
                if (NULL != p_ctrl->p_callback)
                {
                    r_scif_uart_call_callback(p_ctrl, (uint32_t) data, event);
                }
            }
            else
            {
                *p_ctrl->p_rx_dest     = data;
                p_ctrl->p_rx_dest     += 1;
                p_ctrl->rx_dest_bytes -= 1;

                if (0 == p_ctrl->rx_dest_bytes)
                {
                    if (NULL != p_ctrl->p_callback)
                    {
                        r_scif_uart_call_callback(p_ctrl, 0U, UART_EVENT_RX_COMPLETE);
                    }
                }
            }
        }
    }
}

/*******************************************************************************************************************//**
 * RXI interrupt processing for UART mode. RXI interrupt happens when data arrives to the data register or the FIFO
 * register.  This function calls callback function when it meets conditions below.
 *  - UART_EVENT_RX_COMPLETE: The number of data which has been read reaches to the number specified in R_SCIF_UART_Read()
 *    if a transfer instance is used for reception.
 *  - UART_EVENT_RX_CHAR: Data is received asynchronously (read has not been called)
 *
 * This interrupt also calls the callback function for RTS pin control if it is registered in R_SCIF_UART_Open(). This is
 * special functionality to expand SCIF hardware capability and make RTS/CTS hardware flow control possible. If macro
 * 'SCIF_UART_CFG_FLOW_CONTROL_SUPPORT' is set, it is called at the beginning in this function to set the RTS pin high,
 * then it is it is called again just before leaving this function to set the RTS pin low.
 * @retval    none
 **********************************************************************************************************************/
void scif_uart_rxi_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Recover ISR context saved in open. */
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* call common receive function */
    scif_uart_receive_sub(p_ctrl);

    /* Clear RDF flag */
    uint32_t fsr = p_ctrl->p_reg->FSR;
    fsr               &= (~R_SCIFA0_FSR_RDF_Msk);
    p_ctrl->p_reg->FSR = (uint16_t) fsr;

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

#endif

#if (SCIF_UART_CFG_TX_ENABLE || SCIF_UART_CFG_RX_ENABLE)

/*******************************************************************************************************************//**
 * TEI interrupt processing for UART mode. The TEI interrupt fires after the last byte is transmitted on the TX pin.
 * The user callback function is called with the UART_EVENT_TX_COMPLETE event code (if it is registered in
 * R_SCIF_UART_Open()).
 **********************************************************************************************************************/
void scif_uart_tei_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Obtaining FSR register */
    uint32_t fsr = (uint32_t) p_ctrl->p_reg->FSR;

    /* Clearing DRI and TEI */
    p_ctrl->p_reg->FSR = (uint16_t) (fsr & (~(R_SCIFA0_FSR_DR_Msk | R_SCIFA0_FSR_TEND_Msk)));

    /* Check if DRI */
    if (fsr & R_SCIFA0_FSR_DR_Msk)
    {
        /* call common receive function */
        scif_uart_receive_sub(p_ctrl);
    }

    /* Check if TEI */
    if (fsr & R_SCIFA0_FSR_TEND_Msk)
    {
        uint32_t scr = p_ctrl->p_reg->SCR;

        /* Clear TEIE */
        if (0U == p_ctrl->tx_src_bytes)
        {
            /* Also clear TIE if no more data */
            scr &= (~(R_SCIFA0_SCR_TIE_Msk | R_SCIFA0_SCR_TEIE_Msk));
        }
        else
        {
            scr &= (~(R_SCIFA0_SCR_TEIE_Msk));
        }

        p_ctrl->p_reg->SCR = (uint16_t) scr;

        if (NULL != p_ctrl->p_callback)
        {
            r_scif_uart_call_callback(p_ctrl, 0U, UART_EVENT_TX_COMPLETE);
        }
    }

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Negate driver enable if RS-485 mode is enabled. */
    r_scif_negate_de_pin(p_ctrl);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

#endif

#if (SCIF_UART_CFG_RX_ENABLE)

/*******************************************************************************************************************//**
 * ERI interrupt processing for UART mode. When an ERI interrupt fires, the user callback function is called if it is
 * registered in R_SCIF_UART_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void scif_uart_eri_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Determine cause of error. */
    uint32_t fsr = p_ctrl->p_reg->FSR;
    if (fsr & R_SCIFA0_FSR_ER_Msk)
    {
        fsr &= (~R_SCIFA0_FSR_ER_Msk);
    }

    /* Clear error condition. */
    p_ctrl->p_reg->FSR = (uint16_t) fsr;

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

/*******************************************************************************************************************//**
 * BRI interrupt processing for UART mode. When an BRI interrupt fires, the user callback function is called if it is
 * registered in R_SCIF_UART_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void scif_uart_bri_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    scif_uart_instance_ctrl_t * p_ctrl = (scif_uart_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    uint32_t     data = 0U;
    uart_event_t event;

    /* Determine cause of error. */
    event = 0;
    uint32_t fsr = p_ctrl->p_reg->FSR;
    uint32_t lsr = p_ctrl->p_reg->LSR;
    if (fsr & R_SCIFA0_FSR_BRK_Msk)
    {
        event |= UART_EVENT_BREAK_DETECT;
        fsr   &= (~R_SCIFA0_FSR_BRK_Msk);
    }

    if (lsr & R_SCIFA0_LSR_ORER_Msk)
    {
        event |= UART_EVENT_ERR_OVERFLOW;
        lsr   &= (~R_SCIFA0_LSR_ORER_Msk);
    }

    /* Clear error condition. */
    p_ctrl->p_reg->FSR = (uint16_t) fsr;
    p_ctrl->p_reg->LSR = (uint16_t) lsr;

    /* Call callback. */
    if (event)
    {
        if (NULL != p_ctrl->p_callback)
        {
            r_scif_uart_call_callback(p_ctrl, data, event);
        }
    }

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

#endif

#if SCIF_UART_CFG_DMAC_ENABLE

/*******************************************************************************************************************//**
 * Dedicated function for DMAC linkage at the time of transmission.
 **********************************************************************************************************************/
void scif_uart_tx_dmac_callback (scif_uart_instance_ctrl_t * p_ctrl)
{
    /* After all data has been transmitted, disable transmit interrupts and enable the transmit end interrupt. */
    uint32_t scr_temp;
    scr_temp           = p_ctrl->p_reg->SCR;
    scr_temp          |= R_SCIFA0_SCR_TEIE_Msk;
    scr_temp          &= (uint32_t) (~R_SCIFA0_SCR_TIE_Msk);
    p_ctrl->p_reg->SCR = (uint16_t) scr_temp;

    p_ctrl->p_tx_src = NULL;
    r_scif_uart_call_callback(p_ctrl, 0U, UART_EVENT_TX_DATA_EMPTY);
}

/*******************************************************************************************************************//**
 * Dedicated function for DMAC linkage at the time of receptions.
 **********************************************************************************************************************/
void scif_uart_rx_dmac_callback (scif_uart_instance_ctrl_t * p_ctrl)
{
    p_ctrl->rx_dest_bytes = 0;

    p_ctrl->p_rx_dest = NULL;

    /* Call callback */
    r_scif_uart_call_callback(p_ctrl, 0U, UART_EVENT_RX_COMPLETE);
}

#endif
