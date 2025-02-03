/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rspi.h"
#include "r_rspi_cfg.h"

#if RSPI_CFG_DMAC_ENABLE
 #include "r_dmac_b.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "RSPI" in ASCII, used to determine if channel is open. */
#define RSPI_OPEN                    (0x52535049ULL)

/** RSPI base register access macro.  */

#define RSPI_CLK_N_DIV_MULTIPLIER    (512U) ///< Maximum divider for N=0

/** RSPI parameter */
#define RSPI_TX_FIFO_SIZE            (8)    ///< TX FIFO size
#define RSPI_SPDCR_WIDTH_8BIT        (1 << R_RSPI0_SPDCR_SPLW_Pos)
#define RSPI_SPDCR_WIDTH_16BIT       (2 << R_RSPI0_SPDCR_SPLW_Pos)
#define RSPI_SPDCR_WIDTH_32BIT       (3 << R_RSPI0_SPDCR_SPLW_Pos)
#define RSPI_SPCMD_WIDTH_8BIT        (7 << R_RSPI0_SPCMD0_SPB_Pos)
#define RSPI_SPCMD_WIDTH_16BIT       (15 << R_RSPI0_SPCMD0_SPB_Pos)
#define RSPI_SPCMD_WIDTH_32BIT       (3 << R_RSPI0_SPCMD0_SPB_Pos)
#define RSPI_RXTRG_32BYTE            (6)
#define RSPI_RXTRG_24BYTE            (5)
#define RSPI_RXTRG_16BYTE            (4)
#define RSPI_RXTRG_8BYTE             (3)
#define RSPI_RXTRG_5BYTE             (7)
#define RSPI_RXTRG_4BYTE             (2)
#define RSPI_RXTRG_2BYTE             (1)
#define RSPI_RXTRG_1BYTE             (0)
#define RSPI_RXTRG_32BYTE_COUNT      (32)
#define RSPI_RXTRG_24BYTE_COUNT      (24)
#define RSPI_RXTRG_16BYTE_COUNT      (16)
#define RSPI_RXTRG_8BYTE_COUNT       (8)
#define RSPI_RXTRG_5BYTE_COUNT       (5)
#define RSPI_RXTRG_4BYTE_COUNT       (4)
#define RSPI_RXTRG_2BYTE_COUNT       (2)
#define RSPI_RXTRG_1BYTE_COUNT       (1)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * spi_prv_ns_callback)(spi_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile spi_prv_ns_callback)(spi_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private function declarations
 **********************************************************************************************************************/
static void      r_rspi_init_control_structure(rspi_instance_ctrl_t * p_ctrl, spi_cfg_t const * const p_cfg);
static void      r_rspi_hw_config(rspi_instance_ctrl_t * p_ctrl);
static void      r_rspi_nvic_config(rspi_instance_ctrl_t * p_ctrl);
static void      r_rspi_bit_width_config(rspi_instance_ctrl_t * p_ctrl);
static void      r_rspi_set_rx_fifo_hint(rspi_instance_ctrl_t * p_ctrl);
static void      r_rspi_set_rxtrg(rspi_instance_ctrl_t * p_ctrl, rspi_rx_trigger_level_t level);
static void      r_rspi_set_rx_fifo_level(rspi_instance_ctrl_t * p_ctrl);
static fsp_err_t r_rspi_write_read_common(spi_ctrl_t * const    p_api_ctrl,
                                          void const          * p_src,
                                          void                * p_dest,
                                          uint32_t const        length,
                                          spi_bit_width_t const bit_width);
static void r_rspi_receive(rspi_instance_ctrl_t * p_ctrl);
static void r_rspi_transmit(rspi_instance_ctrl_t * p_ctrl);
static void r_rspi_call_callback(rspi_instance_ctrl_t * p_ctrl, spi_event_t event);

#if RSPI_CFG_DMAC_ENABLE

static fsp_err_t r_rspi_transfer_config(rspi_instance_ctrl_t * p_ctrl, spi_cfg_t const * const p_cfg);
void             rspi_tx_dmac_callback(rspi_instance_ctrl_t * p_ctrl);
void             rspi_rx_dmac_callback(rspi_instance_ctrl_t * p_ctrl);

#endif

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/
void rspi_rxi_isr(void);
void rspi_txi_isr(void);
void rspi_eri_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/* RSPI implementation of SPI interface. */
const spi_api_t g_spi_on_rspi =
{
    .open        = R_RSPI_Open,
    .read        = R_RSPI_Read,
    .write       = R_RSPI_Write,
    .writeRead   = R_RSPI_WriteRead,
    .close       = R_RSPI_Close,
    .callbackSet = R_RSPI_CallbackSet
};

/*******************************************************************************************************************//**
 * @addtogroup RSPI
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * This functions initializes a channel for SPI communication mode. Implements @ref spi_api_t::open.
 *
 * This function performs the following tasks:
 * - Performs parameter checking and processes error conditions.
 * - Configures the pperipheral registers acording to the configuration.
 * - Initialize the control structure for use in other @ref SPI_API functions.
 *
 * @retval     FSP_SUCCESS                     Channel initialized successfully.
 * @retval     FSP_ERR_ALREADY_OPEN            Instance was already initialized.
 * @retval     FSP_ERR_ASSERTION               An invalid argument was given in the configuration structure.
 * @retval     FSP_ERR_IP_CHANNEL_NOT_PRESENT  The channel number is invalid.
 * @return     See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes.
 * @note       This function is reentrant.
 **********************************************************************************************************************/
fsp_err_t R_RSPI_Open (spi_ctrl_t * p_api_ctrl, spi_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;

    rspi_instance_ctrl_t * p_ctrl = (rspi_instance_ctrl_t *) p_api_ctrl;

#if RSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(RSPI_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(BSP_FEATURE_RSPI_VALID_CHANNELS_MASK & (1 << p_cfg->channel), FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    FSP_ASSERT(p_cfg->eri_irq >= 0);
#endif

    /* Initialize the control structure */
    r_rspi_init_control_structure(p_ctrl, p_cfg);

    /* Configure hardware registers according to the r_spi_api configuration structure. */
    r_rspi_hw_config(p_ctrl);

    /* Enable interrupts in NVIC. */
    r_rspi_nvic_config(p_ctrl);

#if RSPI_CFG_DMAC_ENABLE

    /* Configure transfers if they are provided in p_cfg. */
    err = r_rspi_transfer_config(p_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    p_ctrl->open = RSPI_OPEN;

    return err;
}

/*******************************************************************************************************************//**
 * This function receives data from a SPI device. Implements @ref spi_api_t::read.
 *
 * The function performs the following tasks:
 * - Performs parameter checking and processes error conditions.
 * - Sets up the instance to complete a SPI read operation.
 *
 * @retval  FSP_SUCCESS                   Read operation successfully completed.
 * @retval  FSP_ERR_ASSERTION             NULL pointer to control or destination parameters or transfer length is zero.
 * @retval  FSP_ERR_NOT_OPEN              The channel has not been opened. Open channel first.
 * @retval  FSP_ERR_IN_USE                A transfer is already in progress.
 * @retval  FSP_ERR_INVALID_ARGUMENT      A bit length not supported by this device was assigned to the argument.
 **********************************************************************************************************************/
fsp_err_t R_RSPI_Read (spi_ctrl_t * const    p_api_ctrl,
                       void                * p_dest,
                       uint32_t const        length,
                       spi_bit_width_t const bit_width)
{
#if RSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_dest != NULL);
#endif

    return r_rspi_write_read_common(p_api_ctrl, NULL, p_dest, length, bit_width);
}

/*******************************************************************************************************************//**
 * This function transmits data to a SPI device using the TX Only Communications Operation Mode.
 * Implements @ref spi_api_t::write.
 *
 * The function performs the following tasks:
 * - Performs parameter checking and processes error conditions.
 * - Sets up the instance to complete a SPI write operation.
 *
 * @retval  FSP_SUCCESS                     Write operation successfully completed.
 * @retval  FSP_ERR_ASSERTION               NULL pointer to control or source parameters or transfer length is zero.
 * @retval  FSP_ERR_NOT_OPEN                The channel has not been opened. Open the channel first.
 * @retval  FSP_ERR_IN_USE                  A transfer is already in progress.
 * @retval  FSP_ERR_INVALID_ARGUMENT        A bit length not supported by this device was assigned to the argument.
 **********************************************************************************************************************/
fsp_err_t R_RSPI_Write (spi_ctrl_t * const    p_api_ctrl,
                        void const          * p_src,
                        uint32_t const        length,
                        spi_bit_width_t const bit_width)
{
#if RSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_src != NULL);
#endif

    return r_rspi_write_read_common(p_api_ctrl, p_src, NULL, length, bit_width);
}

/*******************************************************************************************************************//**
 * This function simultaneously transmits and receive data. Implements @ref spi_api_t::writeRead.
 *
 * The function performs the following tasks:
 * - Performs parameter checking and processes error conditions.
 * - Sets up the instance to complete a SPI writeRead operation.
 *
 * @retval  FSP_SUCCESS                   Write operation successfully completed.
 * @retval  FSP_ERR_ASSERTION             NULL pointer to control, source or destination parameters or
 *                                        transfer length is zero.
 * @retval  FSP_ERR_NOT_OPEN              The channel has not been opened. Open the channel first.
 * @retval  FSP_ERR_IN_USE                A transfer is already in progress.
 * @retval  FSP_ERR_INVALID_ARGUMENT      A bit length not supported by this device was assigned to the argument.
 *********************************************************************************************************************/
fsp_err_t R_RSPI_WriteRead (spi_ctrl_t * const    p_api_ctrl,
                            void const          * p_src,
                            void                * p_dest,
                            uint32_t const        length,
                            spi_bit_width_t const bit_width)
{
#if RSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_src != NULL);
    FSP_ASSERT(p_dest != NULL);
#endif

    return r_rspi_write_read_common(p_api_ctrl, p_src, p_dest, length, bit_width);
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements spi_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_RSPI_CallbackSet (spi_ctrl_t * const          p_api_ctrl,
                              void (                    * p_callback)(spi_callback_args_t *),
                              void const * const          p_context,
                              spi_callback_args_t * const p_callback_memory)
{
    rspi_instance_ctrl_t * p_ctrl = (rspi_instance_ctrl_t *) p_api_ctrl;

#if (RSPI_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(RSPI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if RSPI_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    spi_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                      CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif
#endif

    /* Store callback and context */
#if BSP_TZ_SECURE_BUILD
    p_ctrl->p_callback = callback_is_secure ? p_callback :
                         (void (*)(spi_callback_args_t *))cmse_nsfptr_create(p_callback);
#else
    p_ctrl->p_callback = p_callback;
#endif
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * This function manages the closing of a channel by the following task. Implements @ref spi_api_t::close.
 *
 * Disables SPI operations by disabling the SPI bus.
 * - Disables the SPI peripheral.
 * - Disables all the associated interrupts.
 * - Update control structure so it will not work with @ref SPI_API functions.
 *
 * @retval  FSP_SUCCESS              Channel successfully closed.
 * @retval  FSP_ERR_ASSERTION        A required pointer argument is NULL.
 * @retval  FSP_ERR_NOT_OPEN         The channel has not been opened. Open the channel first.
 **********************************************************************************************************************/
fsp_err_t R_RSPI_Close (spi_ctrl_t * const p_api_ctrl)
{
    rspi_instance_ctrl_t * p_ctrl = (rspi_instance_ctrl_t *) p_api_ctrl;

#if RSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(RSPI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_ctrl->open = 0;

#if RSPI_CFG_DMAC_ENABLE
    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        p_ctrl->p_cfg->p_transfer_rx->p_api->close(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
    }

    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        p_ctrl->p_cfg->p_transfer_tx->p_api->close(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);
    }
#endif

    /* Disable interrupts in NVIC. */
    if (p_ctrl->p_cfg->txi_irq >= 0)
    {
        R_BSP_IrqDisable(p_ctrl->p_cfg->txi_irq);
    }

    if (p_ctrl->p_cfg->rxi_irq >= 0)
    {
        R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);
    }

    R_BSP_IrqDisable(p_ctrl->p_cfg->eri_irq);

    /* Disable the SPI Transfer. */
    p_ctrl->p_regs->SPCR_b.SPE = 0U;

    /* Clear the status register. */

    /* The status register must be read before cleared. */
    p_ctrl->p_regs->SPSR;
    p_ctrl->p_regs->SPSR = 0;

    /* Remove power to the channel. */
    R_BSP_MODULE_STOP(FSP_IP_RSPI, p_ctrl->p_cfg->channel);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Calculates the SPBR register value and the BRDV bits for a desired bitrate.
 * If the desired bitrate is faster than the maximum bitrate or slower than the minimum bitrate,
 * then an error is returned.
 *
 * @param[in] bitrate             Desired bitrate.
 * @param[out] spck_div           Memory location to store bitrate register settings.
 *
 * @retval FSP_SUCCESS            Valid spbr and brdv values were calculated.
 * @retval FSP_ERR_UNSUPPORTED    Bitrate is out of the settable range.
 **********************************************************************************************************************/
fsp_err_t R_RSPI_CalculateBitrate (uint32_t bitrate, rspi_rspck_div_setting_t * spck_div)
{
    /* desired_divider = Smallest integer greater than or equal to RSPI_CLOCK / bitrate. */
    uint32_t desired_divider = (R_FSP_SystemClockHzGet(BSP_FEATURE_RSPI_CLOCK) + bitrate - 1) / bitrate;

    /*
     * Possible SPI_CLK dividers for values of N:
     *   N = 0; div = [2,4,6,..,512]
     *   N = 1; div = [4,8,12,..,1024]
     *   N = 2; div = [8,16,32,..,2048]
     *   N = 3; div = [16,32,64,..,4096]
     */
    uint8_t i;
    for (i = 0; i < 4; i++)
    {
        /* Select smallest value for N possible. */

        /* div <= 512; N = 0
         * 512 < div <= 1024; N=1
         * ...
         */
        if (desired_divider <= (RSPI_CLK_N_DIV_MULTIPLIER << i))
        {
            break;
        }
    }

    spck_div->brdv = i & 0x03U;

    /*
     * desired_divider = 2 * (spbr + 1) * 2^i.
     *
     * With desired_divider and i known, solve for spbr.
     *
     * spbr = SPI_CLK_DIV / (2 * 2^i) - 1
     */
    uint32_t spbr_divisor = (2U * (1U << i));

    /* spbr = (Smallest integer greater than or equal to SPI_CLK_DIV / (2 * 2^i)) - 1. */
    spck_div->spbr = (uint8_t) (((desired_divider + spbr_divisor - 1U) / spbr_divisor) - 1U) & UINT8_MAX;

    /* Can't achieve bitrate faster or slower than desired. */
    if ((desired_divider > BSP_FEATURE_RSPI_CLK_MAX_DIV) ||
        ((R_FSP_SystemClockHzGet(BSP_FEATURE_RSPI_CLOCK) / bitrate) < BSP_FEATURE_RSPI_CLK_MIN_DIV))
    {
        return FSP_ERR_UNSUPPORTED;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RSPI)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Private Functions
 **********************************************************************************************************************/

#if RSPI_CFG_DMAC_ENABLE

/*******************************************************************************************************************//**
 * Configure the given transfer instances for receiving and transmitting data without CPU intervention.
 *
 * @param      p_cfg           Configuration structure with references to receive and transmit transfer instances.
 *
 * @retval     FSP_SUCCESS     The given transfer instances were configured successfully.
 * @return                     See @ref RENESAS_ERROR_CODES for other possible return codes. This function internally
 *                             calls @ref transfer_api_t::open.
 **********************************************************************************************************************/
static fsp_err_t r_rspi_transfer_config (rspi_instance_ctrl_t * p_ctrl, spi_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;

    const transfer_instance_t * p_transfer_tx = p_cfg->p_transfer_tx;
    void * p_spdr = (void *) &(p_ctrl->p_regs->SPDR);

    if (p_transfer_tx)
    {
        p_transfer_tx->p_cfg->p_info->p_dest = p_spdr;

        err = p_transfer_tx->p_api->open(p_transfer_tx->p_ctrl, p_transfer_tx->p_cfg);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    const transfer_instance_t * p_transfer_rx = p_cfg->p_transfer_rx;
    if (p_transfer_rx)
    {
        p_transfer_rx->p_cfg->p_info->p_src = p_spdr;

        err = p_transfer_rx->p_api->open(p_transfer_rx->p_ctrl, p_transfer_rx->p_cfg);

        if ((FSP_SUCCESS != err) && p_transfer_tx)
        {
            p_transfer_tx->p_api->close(p_transfer_tx->p_ctrl);
        }
    }

    return err;
}

#endif

/*******************************************************************************************************************//**
 * initialize control structure
 *
 * @param[in]  p_ctrl          pointer to control structure.
 * @param[in]  p_cfg           pointer to API configuration structure.
 **********************************************************************************************************************/
static void r_rspi_init_control_structure (rspi_instance_ctrl_t * p_ctrl, spi_cfg_t const * const p_cfg)
{
    /* initialize by config parameter */
    p_ctrl->p_cfg             = p_cfg;
    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_ext             = (rspi_extended_cfg_t *) p_cfg->p_extend;
    p_ctrl->p_callback_memory = NULL;

    /* register base address */
    ptrdiff_t size_of_regs = (ptrdiff_t) R_RSPI1 - (ptrdiff_t) R_RSPI0;
    p_ctrl->p_regs = (R_RSPI0_Type *) ((ptrdiff_t) R_RSPI0 + (size_of_regs * p_ctrl->p_cfg->channel));

    /* Clear flags */
    p_ctrl->transfer_is_pending = false;
}

/*******************************************************************************************************************//**
 * Hardware configuration for settings given by the configuration structure.
 *
 * @param[in]  p_ctrl          pointer to control structure.
 **********************************************************************************************************************/
static void r_rspi_hw_config (rspi_instance_ctrl_t * p_ctrl)
{
    uint32_t sslp   = 0;
    uint32_t sppcr  = 0;
    uint32_t spdcr  = 0;
    uint32_t spckd  = 0;
    uint32_t sslnd  = 0;
    uint32_t spnd   = 0;
    uint32_t spcmd0 = 0;
    uint32_t spbfcr = 0;
    uint32_t spcr   = 0;

    /* Enable IP */
    R_BSP_MODULE_START(FSP_IP_RSPI, p_ctrl->p_cfg->channel);

    /* Reset SPI controller */
    p_ctrl->p_regs->SPCR = (uint8_t) spcr;

    /* Enable Error interrupt only in slave mode. */
    if (SPI_MODE_SLAVE == p_ctrl->p_cfg->operating_mode)
    {
        spcr |= R_RSPI0_SPCR_SPEIE_Msk;
    }

    /* Configure Master Mode setting. */
    if (SPI_MODE_MASTER == p_ctrl->p_cfg->operating_mode)
    {
        spcr |= R_RSPI0_SPCR_MSTR_Msk;
    }

    /* Configure CPHA setting. */
    if (SPI_CLK_PHASE_EDGE_EVEN == p_ctrl->p_cfg->clk_phase)
    {
        spcmd0 |= R_RSPI0_SPCMD0_CPHA_Msk;
    }

    /* Configure CPOL setting. */
    if (SPI_CLK_POLARITY_HIGH == p_ctrl->p_cfg->clk_polarity)
    {
        spcmd0 |= R_RSPI0_SPCMD0_CPOL_Msk;
    }

    /* Configure Bit Order (MSB,LSB) */
    if (SPI_BIT_ORDER_LSB_FIRST == p_ctrl->p_cfg->bit_order)
    {
        spcmd0 |= R_RSPI0_SPCMD0_LSBF_Msk;
    }

    rspi_extended_cfg_t * p_extend = ((rspi_extended_cfg_t *) p_ctrl->p_cfg->p_extend);

    /* Configure SSL Level Keep Setting.(Can be set only in master mode)*/
    spcmd0 |=
        (uint32_t) (((!p_ctrl->p_cfg->operating_mode) & p_extend->ssl_level_keep) << R_RSPI0_SPCMD0_SSLKP_Pos);

    /* Configure SSLn polarity setting. */
    if (RSPI_SSLP_HIGH == p_extend->ssl_polarity)
    {
        sslp |= R_RSPI0_SSLP_SSL0P_Msk;
    }

    if (RSPI_MOSI_IDLE_VALUE_FIXING_DISABLE != p_extend->mosi_idle)
    {
        /* Enable mosi value fixing */
        sppcr |= R_RSPI0_SPPCR_MOIFE_Msk;

        if (RSPI_MOSI_IDLE_VALUE_FIXING_HIGH == p_extend->mosi_idle)
        {
            sppcr |= R_RSPI0_SPPCR_MOIFV_Msk;
        }
    }

    /* Configure the Bit Rate Division Setting */
    spcmd0 |= ((unsigned) p_extend->spck_div.brdv << R_RSPI0_SPCMD0_BRDV_Pos);

    /* Set 8bit transfer */
    spcmd0 |= RSPI_SPCMD_WIDTH_8BIT;

    /* Enable all delay settings. */
    if (SPI_MODE_MASTER == p_ctrl->p_cfg->operating_mode)
    {
        /* Note that disabling delay settings is same as setting delay to 1. */
        spcmd0 |= (R_RSPI0_SPCMD0_SPNDEN_Msk | R_RSPI0_SPCMD0_SLNDEN_Msk | R_RSPI0_SPCMD0_SCKDEN_Msk);

        spckd = p_extend->spck_delay;
        sslnd = p_extend->ssl_negation_delay;
        spnd  = p_extend->next_access_delay;
    }

    /* Pre-storing TX FIFO trigger level (not write at this time) */
    if (p_ctrl->p_cfg->p_transfer_tx)
    {
        spbfcr |= ((unsigned) RSPI_TX_TRIGGER_0 << R_RSPI0_SPBFCR_TXTRG_Pos);
    }
    else
    {
        spbfcr |= ((unsigned) p_extend->tx_trigger_level << R_RSPI0_SPBFCR_TXTRG_Pos);
    }

    /* Reset FIFOs */
    p_ctrl->p_regs->SPBFCR = (uint8_t) (spbfcr | R_RSPI0_SPBFCR_RXRST_Msk | R_RSPI0_SPBFCR_TXRST_Msk);

    /* Clear the status register. */
    p_ctrl->p_regs->SPSR;
    p_ctrl->p_regs->SPSR = 0;

    /* Write registers */
    p_ctrl->p_regs->SSLP   = (uint8_t) sslp;
    p_ctrl->p_regs->SPPCR  = (uint8_t) sppcr;
    p_ctrl->p_regs->SPBR   = p_extend->spck_div.spbr;
    p_ctrl->p_regs->SPDCR  = (uint8_t) spdcr;
    p_ctrl->p_regs->SPCKD  = (uint8_t) spckd;
    p_ctrl->p_regs->SSLND  = (uint8_t) sslnd;
    p_ctrl->p_regs->SPND   = (uint8_t) spnd;
    p_ctrl->p_regs->SPCMD0 = (uint16_t) spcmd0;
    p_ctrl->p_regs->SPSCR  = 0;
    p_ctrl->p_regs->SPBFCR = (uint8_t) spbfcr;
    p_ctrl->p_regs->SPCR   = (uint8_t) spcr;
}

/*******************************************************************************************************************//**
 * Enable Receive Buffer Full, Transmit Buffer Empty, and Error Interrupts in the NVIC.
 *
 * @param[in]  p_ctrl          pointer to control structure.
 **********************************************************************************************************************/
static void r_rspi_nvic_config (rspi_instance_ctrl_t * p_ctrl)
{
    if (p_ctrl->p_cfg->txi_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_ctrl->p_cfg->txi_irq, p_ctrl->p_cfg->txi_ipl, p_ctrl);
    }

    if (p_ctrl->p_cfg->rxi_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_ctrl->p_cfg->rxi_irq, p_ctrl->p_cfg->rxi_ipl, p_ctrl);
    }

    R_BSP_IrqCfgEnable(p_ctrl->p_cfg->eri_irq, p_ctrl->p_cfg->eri_ipl, p_ctrl);
}

/*******************************************************************************************************************//**
 * Setup the bit width configuration for a transfer.
 *
 * @param[in]  p_ctrl          pointer to control structure.
 *
 * Note: For 8-Bit wide data frames, the devices require the SPBYT bit to enable byte level access to the
 * data register. Although this register is not documented in some MCU hardware manuals, it does seem to be available
 * on all of them.
 **********************************************************************************************************************/
static void r_rspi_bit_width_config (rspi_instance_ctrl_t * p_ctrl)
{
    uint32_t spdcr  = p_ctrl->p_regs->SPDCR;
    uint32_t spcmd0 = p_ctrl->p_regs->SPCMD0;

    spdcr  &= (uint32_t) (~R_RSPI0_SPDCR_SPLW_Msk);
    spcmd0 &= (uint32_t) (~R_RSPI0_SPCMD0_SPB_Msk);
    if (SPI_BIT_WIDTH_8_BITS == p_ctrl->bit_width)
    {
        /* Configure byte access to data register. */
        spdcr |= RSPI_SPDCR_WIDTH_8BIT;

        /* Configure 8-Bit Mode.  */
        spcmd0 |= RSPI_SPCMD_WIDTH_8BIT;
    }
    else if (SPI_BIT_WIDTH_16_BITS == p_ctrl->bit_width)
    {
        /* Configure Half-Word access to data register. */
        spdcr |= RSPI_SPDCR_WIDTH_16BIT;

        /* Configure 16-Bit Mode. */
        spcmd0 |= RSPI_SPCMD_WIDTH_16BIT;
    }
    else                               /* SPI_BIT_WIDTH_32_BITS */
    {
        /* Configure Word access to data register. */
        spdcr |= RSPI_SPDCR_WIDTH_32BIT;

        /* Configure 32-Bit Mode. */
        spcmd0 |= RSPI_SPCMD_WIDTH_32BIT;
    }

    p_ctrl->p_regs->SPDCR  = (uint8_t) spdcr;
    p_ctrl->p_regs->SPCMD0 = (uint16_t) spcmd0;
}

/*******************************************************************************************************************//**
 * Setup hint of RX FIFO trigger level
 *
 * @param[in]  p_ctrl          pointer to control structure.
 **********************************************************************************************************************/
static void r_rspi_set_rx_fifo_hint (rspi_instance_ctrl_t * p_ctrl)
{
    rspi_rx_trigger_level_t level = p_ctrl->p_ext->rx_trigger_level;
    if (SPI_BIT_WIDTH_8_BITS == p_ctrl->bit_width)
    {
        /* No restrictions */
    }
    else if (SPI_BIT_WIDTH_16_BITS == p_ctrl->bit_width)
    {
        /* at least 2 bytes required, override as 2 byte */
        switch (level)
        {
            case RSPI_RX_TRIGGER_1:
            {
                level = RSPI_RX_TRIGGER_2;
                break;
            }

            default:
            {
                break;
            }
        }
    }
    else
    {
        /* at least 4 bytes required, override as 4 byte */
        switch (level)
        {
            case RSPI_RX_TRIGGER_1:
            case RSPI_RX_TRIGGER_2:
            {
                level = RSPI_RX_TRIGGER_4;
                break;
            }

            default:
            {
                break;
            }
        }
    }

    /* Save hint value */
    switch (level)
    {
        case RSPI_RX_TRIGGER_1:
        {
            p_ctrl->rxfifo_trigger_bytes = RSPI_RXTRG_1BYTE_COUNT;
            break;
        }

        case RSPI_RX_TRIGGER_2:
        {
            p_ctrl->rxfifo_trigger_bytes = RSPI_RXTRG_2BYTE_COUNT;
            break;
        }

        case RSPI_RX_TRIGGER_4:
        {
            p_ctrl->rxfifo_trigger_bytes = RSPI_RXTRG_4BYTE_COUNT;
            break;
        }

        case RSPI_RX_TRIGGER_8:
        {
            p_ctrl->rxfifo_trigger_bytes = RSPI_RXTRG_8BYTE_COUNT;
            break;
        }

        case RSPI_RX_TRIGGER_16:
        {
            p_ctrl->rxfifo_trigger_bytes = RSPI_RXTRG_16BYTE_COUNT;
            break;
        }

        case RSPI_RX_TRIGGER_24:
        {
            p_ctrl->rxfifo_trigger_bytes = RSPI_RXTRG_24BYTE_COUNT;
            break;
        }

        case RSPI_RX_TRIGGER_32:
        {
            p_ctrl->rxfifo_trigger_bytes = RSPI_RXTRG_32BYTE_COUNT;
            break;
        }

        default:
        {
            p_ctrl->rxfifo_trigger_bytes = RSPI_RXTRG_5BYTE_COUNT;
            break;
        }
    }

    r_rspi_set_rxtrg(p_ctrl, level);
}

/*******************************************************************************************************************//**
 * Setup RXTRG bit
 *
 * @param[in]  p_ctrl          pointer to control structure.
 * @param[in]  level           trigger level
 **********************************************************************************************************************/
static void r_rspi_set_rxtrg (rspi_instance_ctrl_t * p_ctrl, rspi_rx_trigger_level_t level)
{
    if (p_ctrl->p_cfg->p_transfer_rx)
    {
        level = RSPI_RX_TRIGGER_1;
    }

    uint8_t spbfcr = p_ctrl->p_regs->SPBFCR;
    spbfcr                &= (uint8_t) (~R_RSPI0_SPBFCR_RXTRG_Msk);
    spbfcr                |= (uint8_t) (level << R_RSPI0_SPBFCR_RXTRG_Pos);
    p_ctrl->p_regs->SPBFCR = spbfcr;
}

/*******************************************************************************************************************//**
 * Setup RX FIFO level for fitting in transfer progress.
 *
 * @param[in]  p_ctrl          pointer to control structure.
 **********************************************************************************************************************/
static void r_rspi_set_rx_fifo_level (rspi_instance_ctrl_t * p_ctrl)
{
    uint32_t bytes_remained = p_ctrl->rx_count * (p_ctrl->bit_width + 1) >> 3;
    if (bytes_remained >= p_ctrl->rxfifo_trigger_bytes)
    {
        /* More than FIFO trigger data left : do nothing */
    }
    else if (bytes_remained >= RSPI_RXTRG_24BYTE_COUNT)
    {
        /* more than or equal 24: to 24 bytes */
        r_rspi_set_rxtrg(p_ctrl, RSPI_RXTRG_24BYTE);
    }
    else if (bytes_remained >= RSPI_RXTRG_16BYTE_COUNT)
    {
        /* more than or equal 16: to 16 bytes */
        r_rspi_set_rxtrg(p_ctrl, RSPI_RXTRG_16BYTE);
    }
    else if (bytes_remained >= RSPI_RXTRG_8BYTE_COUNT)
    {
        /* more than or equal 8: to 8 bytes */
        r_rspi_set_rxtrg(p_ctrl, RSPI_RXTRG_8BYTE);
    }
    else if (bytes_remained >= RSPI_RXTRG_5BYTE_COUNT)
    {
        /* more than or equal 5: to 5 bytes */
        r_rspi_set_rxtrg(p_ctrl, RSPI_RXTRG_5BYTE);
    }
    else if (bytes_remained >= RSPI_RXTRG_4BYTE_COUNT)
    {
        /* more than or equal 4: to 4 bytes */
        r_rspi_set_rxtrg(p_ctrl, RSPI_RXTRG_4BYTE);
    }
    else if (bytes_remained >= RSPI_RXTRG_2BYTE_COUNT)
    {
        /* more than or equal 2: to 2 bytes */
        r_rspi_set_rxtrg(p_ctrl, RSPI_RXTRG_2BYTE);
    }
    else
    {
        /* 1: to 1 bytes */
        r_rspi_set_rxtrg(p_ctrl, RSPI_RXTRG_1BYTE);
    }
}

/*******************************************************************************************************************//**
 * Configures the driver state and initiates a SPI transfer for all modes of operation.
 *
 * @param[in]  p_api_ctrl                pointer to control structure.
 * @param      p_src                     Buffer to transmit data from.
 * @param      p_dest                    Buffer to store received data in.
 * @param[in]  length                    Number of transfers
 * @param[in]  bit_width                 Data frame size (8-Bit, 16-Bit, 32-Bit)
 *
 * @retval     FSP_SUCCESS               Transfer was started successfully.
 * @retval     FSP_ERR_ASSERTION         An argument is invalid.
 * @retval     FSP_ERR_NOT_OPEN          The instance has not been initialized.
 * @retval     FSP_ERR_IN_USE            A transfer is already in progress.
 * @retval     FSP_ERR_INVALID_ARGUMENT  A bit length not supported by this device was assigned to the argument.
 * @return                       See @ref RENESAS_ERROR_CODES for other possible return codes. This function internally
 *                               calls @ref transfer_api_t::reconfigure.
 **********************************************************************************************************************/
static fsp_err_t r_rspi_write_read_common (spi_ctrl_t * const    p_api_ctrl,
                                           void const          * p_src,
                                           void                * p_dest,
                                           uint32_t const        length,
                                           spi_bit_width_t const bit_width)
{
    rspi_instance_ctrl_t * p_ctrl = (rspi_instance_ctrl_t *) p_api_ctrl;

#if RSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(RSPI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(p_src || p_dest);
    FSP_ASSERT(0 != length);
#endif

    /* Reject bit width settings not compatible with R_RSPI */
    FSP_ERROR_RETURN(((SPI_BIT_WIDTH_8_BITS == bit_width) ||
                      (SPI_BIT_WIDTH_16_BITS == bit_width) ||
                      (SPI_BIT_WIDTH_32_BITS == bit_width)),
                     FSP_ERR_INVALID_ARGUMENT);

    FSP_ERROR_RETURN(false == p_ctrl->transfer_is_pending, FSP_ERR_IN_USE);

    /* Save transfer data */
    p_ctrl->p_tx_data = p_src;
    p_ctrl->p_rx_data = p_dest;
    p_ctrl->tx_count  = length;
    p_ctrl->rx_count  = length;
    p_ctrl->bit_width = bit_width;

#if RSPI_CFG_DMAC_ENABLE
    if (p_ctrl->p_cfg->p_transfer_rx)
    {
        /* When the rxi interrupt is called, all transfers will be finished. */
        p_ctrl->rx_count = 0;

        /* The number of bytes transferred by DMAC is specified here, but it varies depending on the data width. */
        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->length = length;

        /* Configure the receive DMA instance. */
        if (SPI_BIT_WIDTH_16_BITS < p_ctrl->bit_width)
        {
            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->length = length * 4;

            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->src_size  = TRANSFER_SIZE_4_BYTE;
            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->dest_size = TRANSFER_SIZE_4_BYTE;
        }
        else if (SPI_BIT_WIDTH_8_BITS >= p_ctrl->bit_width)
        {
            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->src_size  = TRANSFER_SIZE_1_BYTE;
            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->dest_size = TRANSFER_SIZE_1_BYTE;
        }
        else
        {
            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->length = length * 2;

            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->src_size  = TRANSFER_SIZE_2_BYTE;
            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->dest_size = TRANSFER_SIZE_2_BYTE;
        }

        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED;
        p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_dest         = p_dest;

        if (NULL == p_dest)
        {
            static uint32_t dummy_rx;
            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->dest_addr_mode = TRANSFER_ADDR_MODE_FIXED;
            p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_dest         = &dummy_rx;
        }

        fsp_err_t err = p_ctrl->p_cfg->p_transfer_rx->p_api->reconfigure(p_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                                         p_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info);

        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    if (p_ctrl->p_cfg->p_transfer_tx)
    {
        /* When the txi interrupt is called, all transfers will be finished. */
        p_ctrl->tx_count = 0;

        /* The number of bytes transferred by DMAC is specified here, but it varies depending on the data width. */
        p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->length = length;

        /* Configure the transmit DMA instance. */
        if (SPI_BIT_WIDTH_16_BITS < p_ctrl->bit_width)
        {
            p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->length = length * 4;

            p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->src_size  = TRANSFER_SIZE_4_BYTE;
            p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->dest_size = TRANSFER_SIZE_4_BYTE;
        }
        else if (SPI_BIT_WIDTH_8_BITS >= p_ctrl->bit_width)
        {
            p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->src_size  = TRANSFER_SIZE_1_BYTE;
            p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->dest_size = TRANSFER_SIZE_1_BYTE;
        }
        else
        {
            p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->length = length * 2;

            p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->src_size  = TRANSFER_SIZE_2_BYTE;
            p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->dest_size = TRANSFER_SIZE_2_BYTE;
        }

        p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED;
        p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->p_src         = p_src;

        if (NULL == p_src)
        {
            static uint32_t dummy_tx = 0;
            p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->src_addr_mode = TRANSFER_ADDR_MODE_FIXED;
            p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->p_src         = &dummy_tx;
        }

        /* Disable the TX buffer empty interrupt before enabling transfer. */
        p_ctrl->p_regs->SPCR_b.SPTIE = 0;

        fsp_err_t err = p_ctrl->p_cfg->p_transfer_tx->p_api->reconfigure(p_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                                         p_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info);

        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
#endif

    /* Set transfer width */
    r_rspi_bit_width_config(p_ctrl);

    /* Set hint value for RX FIFO level */
    r_rspi_set_rx_fifo_hint(p_ctrl);

    /* Update receiver FIFO trigger level */
    r_rspi_set_rx_fifo_level(p_ctrl);

    /* Preparing transmitter */
    r_rspi_transmit(p_ctrl);

    uint32_t spcr = p_ctrl->p_regs->SPCR;
    if (p_ctrl->tx_count || p_ctrl->p_cfg->p_transfer_tx)
    {
        /* More data remained */
        spcr |= R_RSPI0_SPCR_SPTIE_Msk;
    }

    /* Enable receiver interrupt */
    spcr |= R_RSPI0_SPCR_SPRIE_Msk;

    /* Set pending flag */
    p_ctrl->transfer_is_pending = true;

    /* Set spcr.SPE (may cleared by error interrupt) */
    spcr |= R_RSPI0_SPCR_SPE_Msk;

    /* Write register */
    p_ctrl->p_regs->SPCR = (uint8_t) spcr;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Receive and store
 * If the receive buffer is NULL, just read the RSPI data register.
 * If the total transfer length has already been received then do termination the transaction
 *
 * @param[in]  p_ctrl          pointer to control structure.
 **********************************************************************************************************************/
static void r_rspi_receive (rspi_instance_ctrl_t * p_ctrl)
{
    uint32_t rx_count   = p_ctrl->rx_count;
    uint32_t data_count = (p_ctrl->p_regs->SPBFDR & R_RSPI0_SPBFDR_R_Msk) >> R_RSPI0_SPBFDR_R_Pos;

    if (SPI_BIT_WIDTH_8_BITS == p_ctrl->bit_width)
    {
        uint8_t * p_rbuf = p_ctrl->p_rx_data;
        data_count /= 1;
        while (data_count && rx_count)
        {
            uint8_t data = p_ctrl->p_regs->SPDR_byte.LL;
            if (p_rbuf)
            {
                *p_rbuf = data;
                ++p_rbuf;
            }

            --data_count;
            --rx_count;
        }

        p_ctrl->p_rx_data = p_rbuf;
        p_ctrl->rx_count  = rx_count;
    }
    else if (SPI_BIT_WIDTH_16_BITS == p_ctrl->bit_width)
    {
        uint16_t * p_rbuf = p_ctrl->p_rx_data;
        data_count /= 2;
        while (data_count && rx_count)
        {
            uint16_t data = p_ctrl->p_regs->SPDR_hword.L;
            if (p_rbuf)
            {
                *p_rbuf = data;
                ++p_rbuf;
            }

            --data_count;
            --rx_count;
        }

        p_ctrl->p_rx_data = p_rbuf;
        p_ctrl->rx_count  = rx_count;
    }
    else                               /* SPI_BIT_WIDTH_32_BITS */
    {
        uint32_t * p_rbuf = p_ctrl->p_rx_data;
        data_count /= 4;
        while (data_count && rx_count)
        {
            uint32_t data = p_ctrl->p_regs->SPDR;
            if (p_rbuf)
            {
                *p_rbuf = data;
                ++p_rbuf;
            }

            --data_count;
            --rx_count;
        }

        p_ctrl->p_rx_data = p_rbuf;
        p_ctrl->rx_count  = rx_count;
    }

    /* Update RX FIFO trigger level */
    r_rspi_set_rx_fifo_level(p_ctrl);

    if (0 == rx_count)
    {
        /* Disable receive interrupt */
        p_ctrl->p_regs->SPCR &= (uint8_t) (~R_RSPI0_SPCR_SPRIE_Msk);

        /* Clear transfer pending flag */
        p_ctrl->transfer_is_pending = false;

        /* Signal that a transfer has completed. */
        r_rspi_call_callback(p_ctrl, SPI_EVENT_TRANSFER_COMPLETE);
    }
}

/*******************************************************************************************************************//**
 * Load and transmit
 * If the transmit buffer is NULL, than write zero to the RSPI data register.
 * If the total transfer length has already been transmitted then do nothing.
 *
 * @param[in]  p_ctrl          pointer to control structure.
 **********************************************************************************************************************/
static void r_rspi_transmit (rspi_instance_ctrl_t * p_ctrl)
{
    uint32_t data_count = (p_ctrl->p_regs->SPBFDR & R_RSPI0_SPBFDR_T_Msk) >> R_RSPI0_SPBFDR_T_Pos;
    data_count = RSPI_TX_FIFO_SIZE - data_count;
    uint32_t tx_count = p_ctrl->tx_count;

    if (SPI_BIT_WIDTH_8_BITS == p_ctrl->bit_width)
    {
        /* transfer by 8bit */
        uint8_t * p_tbuf = (uint8_t *) p_ctrl->p_tx_data;
        data_count /= 1;
        while (data_count && tx_count)
        {
            uint8_t data;
            if (p_tbuf)
            {
                data = *p_tbuf;
                ++p_tbuf;
            }
            else
            {
                data = 0;
            }

            p_ctrl->p_regs->SPDR_byte.LL = data;
            --data_count;
            --tx_count;
        }

        p_ctrl->p_tx_data = p_tbuf;
        p_ctrl->tx_count  = tx_count;
    }
    else if (SPI_BIT_WIDTH_16_BITS == p_ctrl->bit_width)
    {
        /* transfer by 16bit */
        uint16_t * p_tbuf = (uint16_t *) p_ctrl->p_tx_data;
        data_count /= 2;
        while (data_count && tx_count)
        {
            uint16_t data;
            if (p_tbuf)
            {
                data = *p_tbuf;
                ++p_tbuf;
            }
            else
            {
                data = 0;
            }

            p_ctrl->p_regs->SPDR_hword.L = data;
            --data_count;
            --tx_count;
        }

        p_ctrl->p_tx_data = p_tbuf;
        p_ctrl->tx_count  = tx_count;
    }
    else                               /* SPI_BIT_WIDTH_32_BITS */
    {
        /* transfer by 32bit */
        uint32_t * p_tbuf = (uint32_t *) p_ctrl->p_tx_data;
        data_count /= 4;
        while (data_count && tx_count)
        {
            uint32_t data;
            if (p_tbuf)
            {
                data = *p_tbuf;
                ++p_tbuf;
            }
            else
            {
                data = 0;
            }

            p_ctrl->p_regs->SPDR = data;
            --data_count;
            --tx_count;
        }

        p_ctrl->p_tx_data = p_tbuf;
        p_ctrl->tx_count  = tx_count;
    }

    if (0 == tx_count)
    {
        /* Disable transmit interrupt if no more transmit data */
        p_ctrl->p_regs->SPCR &= (uint8_t) (~R_RSPI0_SPCR_SPTIE_Msk);
    }
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to RSPI instance control block
 * @param[in]     event      Event code
 **********************************************************************************************************************/
static void r_rspi_call_callback (rspi_instance_ctrl_t * p_ctrl, spi_event_t event)
{
    spi_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    spi_callback_args_t * p_args = p_ctrl->p_callback_memory;
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
        spi_prv_ns_callback p_callback = (spi_prv_ns_callback) (p_ctrl->p_callback);
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

/*******************************************************************************************************************//**
 * ISR called when data is loaded into SPI data register from the shift register.
 **********************************************************************************************************************/
void rspi_rxi_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    R_BSP_IrqStatusClear(irq);

    rspi_instance_ctrl_t * p_ctrl = (rspi_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    r_rspi_receive(p_ctrl);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * ISR called when data is copied from the SPI data register into the SPI shift register.
 **********************************************************************************************************************/
void rspi_txi_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    R_BSP_IrqStatusClear(irq);

    rspi_instance_ctrl_t * p_ctrl = (rspi_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    r_rspi_transmit(p_ctrl);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * ISR called in the event that an error occurs (Ex: RX_OVERFLOW).
 **********************************************************************************************************************/
void rspi_eri_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type              irq    = R_FSP_CurrentIrqGet();
    rspi_instance_ctrl_t * p_ctrl = (rspi_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Disable the SPI Transfer. */
    p_ctrl->p_regs->SPCR_b.SPE = 0;

    /* Read the status register. */
    uint8_t status = p_ctrl->p_regs->SPSR;

    /* Clear the status register. */
    p_ctrl->p_regs->SPSR = 0;

    /* Check if the error is a Receive Buffer Overflow Error. */
    if (R_RSPI0_SPSR_OVRF_Msk & status)
    {
        r_rspi_call_callback(p_ctrl, SPI_EVENT_ERR_READ_OVERFLOW);
    }

    /* Check if the error is a Mode Fault Error. */
    if (R_RSPI0_SPSR_MODF_Msk & status)
    {
        r_rspi_call_callback(p_ctrl, SPI_EVENT_ERR_MODE_FAULT);
    }

    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

#if RSPI_CFG_DMAC_ENABLE

/*******************************************************************************************************************//**
 * Dedicated function for DMAC linkage at the time of transmission.
 **********************************************************************************************************************/
void rspi_tx_dmac_callback (rspi_instance_ctrl_t * p_ctrl)
{
    r_rspi_transmit(p_ctrl);
}

/*******************************************************************************************************************//**
 * Dedicated function for DMAC linkage at the time of reception.
 **********************************************************************************************************************/
void rspi_rx_dmac_callback (rspi_instance_ctrl_t * p_ctrl)
{
    r_rspi_receive(p_ctrl);
}

#endif

/* End of file R_SPI. */
