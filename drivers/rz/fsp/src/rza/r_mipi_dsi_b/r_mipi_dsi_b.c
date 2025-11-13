/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <string.h>
#include "r_mipi_dsi_b.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define MIPI_DSI_OPEN                                (0x4D504944)
#define MIPI_MAX_CH0_CMD                             (128)
#define MIPI_MAX_CH1_CMD                             (1024)
#define MIPI_DSI_RSTSR_RESET_BITS                    (R_MIPI_DSI_RSTSR_SWRSTHS_Msk |  \
                                                      R_MIPI_DSI_RSTSR_SWRSTLP_Msk |  \
                                                      R_MIPI_DSI_RSTSR_SWRSTAPB_Msk | \
                                                      R_MIPI_DSI_RSTSR_SWRSTIB_Msk |  \
                                                      R_MIPI_DSI_RSTSR_SWRSTV1_Msk)

#define CAST_TO_UINT32                               (0xFFFFFFFFU)

#define DSI_TX_PACKET_PAYLOAD_DATA_WORD_COUNT        (4)
#define DSI_TX_PACKET_PAYLOAD_DATA_WORD_BIT_SIZE     (8)
#define DSI_TX_PACKET_PAYLOAD_DATA_WORD_COUNT_MAX    (16)

#define DSI_PACKET_FORMAT_IS_SHORT(cmd_id)    ((cmd_id & 0x0F) <= 0x08)
#define DSI_PACKET_FORMAT_IS_LONG(cmd_id)     ((cmd_id & 0x0F) > 0x08)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * mipi_dsi_prv_ns_callback)(mipi_dsi_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile mipi_dsi_prv_ns_callback)(mipi_dsi_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

const mipi_dsi_api_t g_mipi_dsi =
{
    .open      = R_MIPI_DSI_B_Open,
    .close     = R_MIPI_DSI_B_Close,
    .start     = R_MIPI_DSI_B_Start,
    .stop      = R_MIPI_DSI_B_Stop,
    .ulpsEnter = R_MIPI_DSI_B_UlpsEnter,
    .ulpsExit  = R_MIPI_DSI_B_UlpsExit,
    .command   = R_MIPI_DSI_B_Command,
    .statusGet = R_MIPI_DSI_B_StatusGet,
};

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void mipi_dsi_seq0(IRQn_Type const irq);
void mipi_dsi_seq1(IRQn_Type const irq);
void mipi_dsi_vin1(IRQn_Type const irq);
void mipi_dsi_rcv(IRQn_Type const irq);
void mipi_dsi_ferr(IRQn_Type const irq);
void mipi_dsi_ppi(IRQn_Type const irq);

static void dsi_isr_enable(mipi_dsi_b_irq_cfg_t const * irq_cfg, mipi_dsi_b_instance_ctrl_t * p_ctrl);
static void dsi_isr_disable(mipi_dsi_b_irq_cfg_t const * irq_cfg);

static void    dsi_enter_reset(void);
static uint8_t dsi_pow(uint8_t base, uint8_t expon);
static void    dsi_init_timing(mipi_dsi_cfg_t const * const p_cfg);
static void    dsi_exit_reset(mipi_dsi_cfg_t const * const p_cfg);
static void    dsi_hs_clock_start(mipi_dsi_b_instance_ctrl_t * p_ctrl);
static void    dsi_hs_clock_stop(mipi_dsi_b_instance_ctrl_t * p_ctrl);

static void dsi_init_video(mipi_dsi_cfg_t const * p_cfg);

static void dsi_call_callback(mipi_dsi_b_instance_ctrl_t * p_ctrl, mipi_dsi_callback_args_t * p_args);

static fsp_err_t dsi_stop(mipi_dsi_b_instance_ctrl_t * p_ctrl);
static uint32_t  dsi_cmd_sequence_register_a(mipi_dsi_cmd_t * p_cmd);
static uint32_t  dsi_cmd_sequence_register_b(mipi_dsi_cmd_t * p_cmd);
static uint32_t  dsi_cmd_sequence_register_c(mipi_dsi_cmd_t * p_cmd);
static uint32_t  dsi_cmd_sequence_register_d(mipi_dsi_cmd_t * p_cmd);

/*******************************************************************************************************************//**
 * @addtogroup MIPI_DSI_B
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/******************************************************************************************************************//**
 * Initialize the MIPI DSI peripheral.
 *
 * @retval FSP_SUCCESS                     The channel was successfully opened.
 * @retval FSP_ERR_ASSERTION               One or both of the parameters was NULL.
 * @retval FSP_ERR_ALREADY_OPEN            The instance is already opened.
 * @retval FSP_ERR_INVALID_STATE           Display module must be opened before DSI.
 **********************************************************************************************************************/
fsp_err_t R_MIPI_DSI_B_Open (mipi_dsi_ctrl_t * const p_api_ctrl, mipi_dsi_cfg_t const * const p_cfg)
{
    fsp_err_t err;
    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) p_api_ctrl;

#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(MIPI_DSI_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    FSP_ERROR_RETURN(R_LCDC->DU_MCR0_b.DI_EN, FSP_ERR_INVALID_STATE);

    /* Initialize internal state */
    p_ctrl->clock_state   = MIPI_DSI_CLOCK_STATE_IDLE;
    p_ctrl->video_started = false;
    p_ctrl->p_cfg         = p_cfg;

    /* Start clocks to the MIPI DSI peripheral */
    R_BSP_MODULE_START(FSP_IP_MIPI_DSI, 0);

    err = r_mipi_phy_b_open(p_cfg->p_mipi_phy_instance->p_ctrl, p_cfg->p_mipi_phy_instance->p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Set LINK registers */
    dsi_enter_reset();
    dsi_init_timing(p_cfg);
    dsi_exit_reset(p_cfg);

    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);

    /* Configure interrupt sources */
    mipi_dsi_b_extended_cfg_t * p_extend = (mipi_dsi_b_extended_cfg_t *) p_cfg->p_extend;
    R_MIPI_DSI->RXIER    = p_extend->dsi_rxie;
    R_MIPI_DSI->FERRIER  = p_extend->dsi_ferrie;
    R_MIPI_DSI->PLIER    = p_extend->dsi_plie;
    R_MIPI_DSI->VICH1IER = p_extend->dsi_vmie;
    R_MIPI_DSI->SQCH0IER = p_extend->dsi_sqch0ie;
    R_MIPI_DSI->SQCH1IER = p_extend->dsi_sqch1ie;

    /* Clear any active status bits */
    R_MIPI_DSI->SQCH0SCR = R_MIPI_DSI_SQCH0SCR_AACTFIN_Msk |
                           R_MIPI_DSI_SQCH0SCR_ADESFIN_Msk |
                           R_MIPI_DSI_SQCH0SCR_PKTBIGERR_Msk |
                           R_MIPI_DSI_SQCH0SCR_TXIBERR_Msk |
                           R_MIPI_DSI_SQCH0SCR_RXFATALERR_Msk |
                           R_MIPI_DSI_SQCH0SCR_RXFAIL_Msk |
                           R_MIPI_DSI_SQCH0SCR_RXPKTDFAIL_Msk |
                           R_MIPI_DSI_SQCH0SCR_RXCORERR_Msk |
                           R_MIPI_DSI_SQCH0SCR_RXAKE_Msk;
    R_MIPI_DSI->SQCH1SCR = R_MIPI_DSI_SQCH1SCR_AACTFIN_Msk |
                           R_MIPI_DSI_SQCH1SCR_ADESFIN_Msk |
                           R_MIPI_DSI_SQCH1SCR_PKTBIGERR_Msk |
                           R_MIPI_DSI_SQCH1SCR_TXIBERR_Msk |
                           R_MIPI_DSI_SQCH1SCR_RXFATALERR_Msk |
                           R_MIPI_DSI_SQCH1SCR_RXFAIL_Msk |
                           R_MIPI_DSI_SQCH1SCR_RXPKTDFAIL_Msk |
                           R_MIPI_DSI_SQCH1SCR_RXCORERR_Msk |
                           R_MIPI_DSI_SQCH1SCR_RXAKE_Msk;
    R_MIPI_DSI->VICH1SCR = R_MIPI_DSI_VICH1SCR_START_Msk |
                           R_MIPI_DSI_VICH1SCR_STOP_Msk |
                           R_MIPI_DSI_VICH1SCR_VIRDY_Msk |
                           R_MIPI_DSI_VICH1SCR_TIMERR_Msk |
                           R_MIPI_DSI_VICH1SCR_VBUFUDF_Msk |
                           R_MIPI_DSI_VICH1SCR_VBUFOVF_Msk;
    R_MIPI_DSI->RXSCR = R_MIPI_DSI_RXSCR_BTAREQEND_Msk |
                        R_MIPI_DSI_RXSCR_LRXHTO_Msk |
                        R_MIPI_DSI_RXSCR_TATO_Msk |
                        R_MIPI_DSI_RXSCR_RXRESP_Msk |
                        R_MIPI_DSI_RXSCR_RXEOTP_Msk |
                        R_MIPI_DSI_RXSCR_RXUK5TRG_Msk |
                        R_MIPI_DSI_RXSCR_RXRTRG_Msk |
                        R_MIPI_DSI_RXSCR_RXTE_Msk |
                        R_MIPI_DSI_RXSCR_RXACK_Msk |
                        R_MIPI_DSI_RXSCR_EXTTEDET_Msk |
                        R_MIPI_DSI_RXSCR_MLFERR_Msk |
                        R_MIPI_DSI_RXSCR_ECCERR_Msk |
                        R_MIPI_DSI_RXSCR_UEXPKTERR_Msk |
                        R_MIPI_DSI_RXSCR_WCERR_Msk |
                        R_MIPI_DSI_RXSCR_CRCERR_Msk |
                        R_MIPI_DSI_RXSCR_IBERR_Msk |
                        R_MIPI_DSI_RXSCR_RXOVFERR_Msk |
                        R_MIPI_DSI_RXSCR_PRESPTOERR_Msk |
                        R_MIPI_DSI_RXSCR_NORETERR_Msk |
                        R_MIPI_DSI_RXSCR_MAXRPSZERR_Msk |
                        R_MIPI_DSI_RXSCR_ECCERR1B_Msk |
                        R_MIPI_DSI_RXSCR_RXAKE_Msk;

    p_ctrl->p_callback_memory = NULL;
    p_ctrl->p_callback        = p_cfg->p_callback;

    /* Enable interrupts */
    p_ctrl->p_context = p_cfg->p_context;
    dsi_isr_enable(&p_extend->dsi_seq0, p_ctrl);
    dsi_isr_enable(&p_extend->dsi_seq1, p_ctrl);
    dsi_isr_enable(&p_extend->dsi_ferr, p_ctrl);
    dsi_isr_enable(&p_extend->dsi_ppi, p_ctrl);
    dsi_isr_enable(&p_extend->dsi_rcv, p_ctrl);
    dsi_isr_enable(&p_extend->dsi_vin1, p_ctrl);

    /* Mark control block as opened */
    p_ctrl->open = MIPI_DSI_OPEN;

    /* Start high-speed clock */
    dsi_hs_clock_start(p_ctrl);

    /* Notify application that DSI is now open */
    mipi_dsi_callback_args_t callback_args;
    callback_args.event     = MIPI_DSI_EVENT_POST_OPEN;
    callback_args.p_context = p_ctrl->p_context;
    dsi_call_callback(p_ctrl, &callback_args);

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Close MIPI DSI and display data instances, disable interrupts, and power-off the module.
 *
 * @retval   FSP_SUCCESS           The channel is successfully closed.
 * @retval   FSP_ERR_ASSERTION     p_api_ctrl is NULL.
 * @retval   FSP_ERR_NOT_OPEN      Instance is not open.
 * @retval   FSP_ERR_IN_USE        Operation in progress and must be stopped before closing.
 **********************************************************************************************************************/
fsp_err_t R_MIPI_DSI_B_Close (mipi_dsi_ctrl_t * const p_api_ctrl)
{
    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) p_api_ctrl;

#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(MIPI_DSI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Ensure video has stopped first */
    fsp_err_t err = dsi_stop(p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    dsi_hs_clock_stop(p_ctrl);

    mipi_dsi_cfg_t const      * p_cfg    = p_ctrl->p_cfg;
    mipi_dsi_b_extended_cfg_t * p_extend = (mipi_dsi_b_extended_cfg_t *) p_cfg->p_extend;
    dsi_isr_disable(&p_extend->dsi_seq0);
    dsi_isr_disable(&p_extend->dsi_seq1);
    dsi_isr_disable(&p_extend->dsi_ferr);
    dsi_isr_disable(&p_extend->dsi_ppi);
    dsi_isr_disable(&p_extend->dsi_rcv);
    dsi_isr_disable(&p_extend->dsi_vin1);

    /* Close MIPI PHY */
    err = r_mipi_phy_b_close(p_cfg->p_mipi_phy_instance->p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Set control block to closed */
    p_ctrl->open = 0U;

    /* Stop clocks to the MIPI DSI peripheral */
    R_BSP_MODULE_STOP(FSP_IP_MIPI_DSI, 0);

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Start video output.
 * Initialize Video Output Registers
 * Perform sequence steps from section 34.4.2.4.(1) in RZ/A3M hardware manual.
 *
 * @retval   FSP_SUCCESS                Data is successfully written to the D/A Converter.
 * @retval   FSP_ERR_ASSERTION          p_api_ctrl is NULL.
 * @retval   FSP_ERR_NOT_OPEN           Instance is not open.
 * @retval   FSP_ERR_IN_USE             The physical interface is currently in use.
 * @retval   FSP_ERR_INVALID_STATE      DSI is already in video mode.
 **********************************************************************************************************************/
fsp_err_t R_MIPI_DSI_B_Start (mipi_dsi_ctrl_t * const p_api_ctrl)
{
    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) p_api_ctrl;

#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(MIPI_DSI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(!p_ctrl->video_started, FSP_ERR_INVALID_STATE);
#endif

    /* Notify application that DSI is now open */
    mipi_dsi_callback_args_t callback_args;
    callback_args.event     = MIPI_DSI_EVENT_PRE_START;
    callback_args.p_context = p_ctrl->p_context;
    dsi_call_callback(p_ctrl, &callback_args);

    /* Do not start video if sequence operation is in progress */
    FSP_ERROR_RETURN(!(R_MIPI_DSI->LINKSR_b.SQCHRUN0) && !(R_MIPI_DSI->LINKSR_b.SQCHRUN1), FSP_ERR_IN_USE);

    mipi_dsi_cfg_t const * p_cfg = p_ctrl->p_cfg;

    /* Initialize Video Output Registers */
    dsi_init_video(p_cfg);

    while ((R_MIPI_DSI->VICH1SR_b.VIRDY != 1) && !p_ctrl->video_started)
    {
        /* Wait for video mode ready status
         *  NOTE: VICH1SR may be modified in isr */
    }

    p_ctrl->video_started = true;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Stop video output.
 *
 * @retval   FSP_SUCCESS                Data is successfully written to the D/A Converter.
 * @retval   FSP_ERR_ASSERTION          p_api_ctrl is NULL.
 * @retval   FSP_ERR_NOT_OPEN           Instance is not open.
 * @retval   FSP_ERR_IN_USE             DSI cannot be closed while ULPS is active.
 **********************************************************************************************************************/
fsp_err_t R_MIPI_DSI_B_Stop (mipi_dsi_ctrl_t * const p_api_ctrl)
{
    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) p_api_ctrl;

#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(MIPI_DSI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    return dsi_stop(p_ctrl);
}

/******************************************************************************************************************//**
 * Enter Ultra-low Power State (ULPS).
 *
 * @retval   FSP_SUCCESS               Information read successfully.
 * @retval   FSP_ERR_ASSERTION         p_api_ctrl is NULL.
 * @retval   FSP_ERR_NOT_OPEN          Instance is not open.
 * @retval   FSP_ERR_INVALID_MODE      Invalid mode for transition.
 * @retval   FSP_ERR_INVALID_ARGUMENT  Invalid input parameter.
 **********************************************************************************************************************/
fsp_err_t R_MIPI_DSI_B_UlpsEnter (mipi_dsi_ctrl_t * const p_api_ctrl, mipi_dsi_lane_t lane)
{
    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) p_api_ctrl;

#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(MIPI_DSI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Clock lane cannot enter ULPS when Continuous CLock mode is active */
    FSP_ERROR_RETURN(!((MIPI_DSI_LANE_CLOCK & lane) && R_MIPI_DSI->HSCLKSETR_b.HSCLKMODE), FSP_ERR_INVALID_MODE);

    FSP_ERROR_RETURN(MIPI_DSI_LANE_CLOCK == lane || MIPI_DSI_LANE_DATA_ALL == lane ||
                     (MIPI_DSI_LANE_CLOCK | MIPI_DSI_LANE_DATA_ALL) == lane,
                     FSP_ERR_INVALID_ARGUMENT);
#endif

    /* Do not set 'enter ULPS' bit if lane is already in ULPS */
    uint32_t ulpscr =
        ((MIPI_DSI_LANE_DATA_ALL & lane) && !p_ctrl->data_ulps_active) ? R_MIPI_DSI_ULPSCR_DLULPSENT_Msk : 0;
    ulpscr |=
        ((MIPI_DSI_LANE_CLOCK & lane) && !p_ctrl->clock_ulps_active) ? R_MIPI_DSI_ULPSCR_CLULPSENT_Msk : 0;

    p_ctrl->ulps_status |= lane;

    p_ctrl->clock_ulps_active = p_ctrl->clock_ulps_active || (MIPI_DSI_LANE_CLOCK & lane);
    p_ctrl->data_ulps_active  = p_ctrl->data_ulps_active || (MIPI_DSI_LANE_DATA_ALL & lane);

    R_MIPI_DSI->ULPSCR = ulpscr;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Exit Ultra-low Power State (ULPS).
 *
 * @retval   FSP_SUCCESS               Information read successfully.
 * @retval   FSP_ERR_ASSERTION         p_api_ctrl is NULL.
 * @retval   FSP_ERR_NOT_OPEN          Instance is not open.
 * @retval   FSP_ERR_INVALID_ARGUMENT  Invalid input parameter.
 **********************************************************************************************************************/
fsp_err_t R_MIPI_DSI_B_UlpsExit (mipi_dsi_ctrl_t * const p_api_ctrl, mipi_dsi_lane_t lane)
{
    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) p_api_ctrl;
#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(MIPI_DSI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(MIPI_DSI_LANE_CLOCK == lane || MIPI_DSI_LANE_DATA_ALL == lane ||
                     (MIPI_DSI_LANE_CLOCK | MIPI_DSI_LANE_DATA_ALL) == lane,
                     FSP_ERR_INVALID_ARGUMENT);
#endif

    /* Do not set 'exit ULPS' bit if lane is not in ULPS */
    uint32_t ulpscr =
        ((MIPI_DSI_LANE_DATA_ALL & lane) && p_ctrl->data_ulps_active) ? R_MIPI_DSI_ULPSCR_DLULPSEXT_Msk : 0;
    ulpscr |=
        ((MIPI_DSI_LANE_CLOCK & lane) && p_ctrl->clock_ulps_active) ? R_MIPI_DSI_ULPSCR_CLULPSEXT_Msk : 0;

    p_ctrl->clock_ulps_active = p_ctrl->clock_ulps_active && !(MIPI_DSI_LANE_CLOCK & lane);
    p_ctrl->data_ulps_active  = p_ctrl->data_ulps_active && !(MIPI_DSI_LANE_DATA_ALL & lane);

    R_MIPI_DSI->ULPSCR   = ulpscr;
    p_ctrl->ulps_status &= ~lane;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Send a command to the peripheral device.
 *
 * @note p_data will be used as either write data or a read buffer depending on the data id.
 * @note p_data memory must not be updated until sequence operation is complete if byte_count is greater than 16.
 *
 * @retval   FSP_SUCCESS                Command(s) queued successfully.
 * @retval   FSP_ERR_ASSERTION          p_api_ctrl is NULL.
 *                                      cmd_id specifies a long packet but p_data is NULL.
 * @retval   FSP_ERR_NOT_OPEN           Instance is not open.
 * @retval   FSP_ERR_IN_USE             The physical interface is currently in use or video mode is in operation.
 * @retval   FSP_ERR_INVALID_POINTER    Invalid pointer provided
 * @retval   FSP_ERR_INVALID_ARGUMENT   Invalid message configuration
 * @retval   FSP_ERR_INVALID_CHANNEL    Invalid channel for provided message configuration
 **********************************************************************************************************************/
fsp_err_t R_MIPI_DSI_B_Command (mipi_dsi_ctrl_t * const p_api_ctrl, mipi_dsi_cmd_t * p_cmd)
{
#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) p_api_ctrl;

    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_cmd, FSP_ERR_INVALID_POINTER);
    FSP_ERROR_RETURN(MIPI_DSI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(p_cmd->p_tx_buffer || (p_cmd->tx_len == 0), FSP_ERR_INVALID_ARGUMENT);                     // Tx buffer must be supplied for non-zero Tx length

    FSP_ERROR_RETURN(!((p_cmd->channel == 0) && (p_cmd->tx_len > MIPI_MAX_CH0_CMD)), FSP_ERR_INVALID_ARGUMENT); // Max Tx size is 128 for channel 0
    FSP_ERROR_RETURN(!((p_cmd->channel == 1) && (p_cmd->tx_len > MIPI_MAX_CH1_CMD)), FSP_ERR_INVALID_ARGUMENT); // Max Tx size is 1k for channel 1

    /* AUX Operation */
    bool aux = (p_cmd->flags & MIPI_DSI_CMD_FLAG_AUX_OPERATION);
    if (aux)
    {
        bool bta = p_cmd->flags &
                   (MIPI_DSI_CMD_FLAG_BTA | MIPI_DSI_CMD_FLAG_BTA_READ | MIPI_DSI_CMD_FLAG_BTA_NO_WRITE);
        bool initial_skew  = (p_cmd->flags & MIPI_DSI_CMD_FLAG_ACT_CODE_INITIAL_SKEW_CAL);
        bool periodic_skew = (p_cmd->flags & MIPI_DSI_CMD_FLAG_ACT_CODE_PERIODIC_SKEW_CAL);
        FSP_ERROR_RETURN(!bta && !p_cmd->tx_len, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(!R_MIPI_DSI->LINKSR_b.VICHRUN1, FSP_ERR_INVALID_ARGUMENT);                            // Aux operation is prohibited when video mode is running
        FSP_ERROR_RETURN(!(initial_skew || periodic_skew) || (p_cmd->channel != 0), FSP_ERR_INVALID_ARGUMENT); // Periodic and Initial skew must be HS
    }

    uint8_t lp = (0 != (p_cmd->flags & MIPI_DSI_CMD_FLAG_LOW_POWER));

    FSP_ERROR_RETURN(!(lp && R_MIPI_DSI->LINKSR_b.VICHRUN1), FSP_ERR_IN_USE);  // LP not allowed during video mode operation.
    FSP_ERROR_RETURN(!(lp && (p_cmd->channel != 0)), FSP_ERR_INVALID_CHANNEL); // LP only allowed on channel 0
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
#endif

    /* Do not modify registers if sequence operation is currently in progress */
    FSP_ERROR_RETURN(!(R_MIPI_DSI->LINKSR_b.SQCHRUN0) && !(R_MIPI_DSI->LINKSR_b.SQCHRUN1), FSP_ERR_IN_USE);

    R_MIPI_DSI->TXPPD0R = 0x00000000;                                     // initialize TXPPD0R
    R_MIPI_DSI->TXPPD1R = 0x00000000;                                     // initialize TXPPD1R
    R_MIPI_DSI->TXPPD2R = 0x00000000;                                     // initialize TXPPD2R
    R_MIPI_DSI->TXPPD3R = 0x00000000;                                     // initialize TXPPD3R

    uint32_t * p_sequence_reg = (uint32_t *) (&R_MIPI_DSI->SQCH0DSC00AR); // Sequence Channel 0

    if (p_cmd->channel == 1)
    {
        p_sequence_reg = (uint32_t *) (&R_MIPI_DSI->SQCH1DSC00AR);        // Sequence Channel 1
    }
    else
    {
        // do nothing
    }

    *p_sequence_reg++ = dsi_cmd_sequence_register_a(p_cmd);
    *p_sequence_reg++ = dsi_cmd_sequence_register_b(p_cmd);
    *p_sequence_reg++ = dsi_cmd_sequence_register_c(p_cmd);
    *p_sequence_reg++ = dsi_cmd_sequence_register_d(p_cmd);

    bool long_packet = DSI_PACKET_FORMAT_IS_LONG(p_cmd->cmd_id);

    if (long_packet && (p_cmd->tx_len <= DSI_TX_PACKET_PAYLOAD_DATA_WORD_COUNT_MAX))
    {
        for (uint8_t i = 0; i < p_cmd->tx_len; i++)
        {
            if (3 >= i)
            {
                R_MIPI_DSI->TXPPD0R |=
                    (uint32_t) (*(p_cmd->p_tx_buffer + i) <<
                                (DSI_TX_PACKET_PAYLOAD_DATA_WORD_BIT_SIZE *
                                 (i % DSI_TX_PACKET_PAYLOAD_DATA_WORD_COUNT))); // Long packet payload data 0 - 3
            }
            else if (7 >= i)
            {
                R_MIPI_DSI->TXPPD1R |=
                    (uint32_t) (*(p_cmd->p_tx_buffer + i) <<
                                (DSI_TX_PACKET_PAYLOAD_DATA_WORD_BIT_SIZE *
                                 (i % DSI_TX_PACKET_PAYLOAD_DATA_WORD_COUNT))); // Long packet payload data 4 - 7
            }
            else if (11 >= i)
            {
                R_MIPI_DSI->TXPPD2R |=
                    (uint32_t) (*(p_cmd->p_tx_buffer + i) <<
                                (DSI_TX_PACKET_PAYLOAD_DATA_WORD_BIT_SIZE *
                                 (i % DSI_TX_PACKET_PAYLOAD_DATA_WORD_COUNT))); // Long packet payload data 8 - 11
            }
            else if (15 >= i)
            {
                R_MIPI_DSI->TXPPD3R |=
                    (uint32_t) (*(p_cmd->p_tx_buffer + i) <<
                                (DSI_TX_PACKET_PAYLOAD_DATA_WORD_BIT_SIZE *
                                 (i % DSI_TX_PACKET_PAYLOAD_DATA_WORD_COUNT))); // Long packet payload data 12 - 15
            }
            else
            {
                // do nothing
            }
        }
    }
    else
    {
        // do nothing
    }

    /* Start sequence operation */
    R_MIPI_DSI->SQCH0SET0R = (bool) (0 == p_cmd->channel);
    R_MIPI_DSI->SQCH1SET0R = (bool) (1 == p_cmd->channel);

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Provide information about current MIPI DSI status.
 *
 * Note: Acknowledge and Error Status is only cleared when read by calling this function.
 *
 * @retval   FSP_SUCCESS               Information read successfully.
 * @retval   FSP_ERR_ASSERTION         p_api_ctrl is NULL.
 * @retval   FSP_ERR_NOT_OPEN          Instance is not open.
 *
 **********************************************************************************************************************/
fsp_err_t R_MIPI_DSI_B_StatusGet (mipi_dsi_ctrl_t * const p_api_ctrl, mipi_dsi_status_t * p_status)
{
#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) p_api_ctrl;
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(MIPI_DSI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
#endif

    p_status->link_status              = (mipi_dsi_link_status_t) R_MIPI_DSI->LINKSR;
    p_status->ack_err_latest.bits      = R_MIPI_DSI->AKEPLATIR;
    p_status->ack_err_accumulated.bits = R_MIPI_DSI->AKEPACMSR;

    /* Clear accumulated error bits after reading */
    R_MIPI_DSI->AKEPSCR = p_status->ack_err_accumulated.bits;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup MIPI_DSI_B)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Stop DSI operation. Basic parameter checking to be performed by caller.
 *
 * @param[in]     p_ctrl    Pointer to instance control structure
 *
 * @retval        FSP_SUCCESS               DSI stopped successfully.
 * @retval        FSP_ERR_IN_USE            DSI cannot be stopped in ULPS.
 **********************************************************************************************************************/
static fsp_err_t dsi_stop (mipi_dsi_b_instance_ctrl_t * p_ctrl)
{
#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(!p_ctrl->ulps_status, FSP_ERR_IN_USE);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Check if running first else the stop operation may stall indefinitely */
    if (R_MIPI_DSI->VICH1SR_b.RUNNING)
    {
        /* Initiate stop video output and wait  */
        R_MIPI_DSI->VICH1SET0R_b.VSTPAFT = 1U;

        while ((R_MIPI_DSI->VICH1SR_b.STOP != 1) && p_ctrl->video_started)
        {
            /* Wait for video mode stop
             *  - VICH1SR.STOP must be zero before proceeding to stop LCDC
             *  NOTE: VICH1SR may be modified in isr */
        }

        p_ctrl->video_started = false;

        /* Clear any stale VICH1SR status */
        R_MIPI_DSI->VICH1SCR = R_MIPI_DSI->VICH1SR;

        while (R_MIPI_DSI->LINKSR_b.HSBUSY != 0)
        {
            /* wait for LINKSR.HSBUSY to become 0 */
        }
    }

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Returns configuration values for Sequence Register A
 *
 * @param[in]     p_cmd     Pointer to formatted message structure
 **********************************************************************************************************************/
static uint32_t dsi_cmd_sequence_register_a (mipi_dsi_cmd_t * p_cmd)
{
    /*
     * Long write packets contain the word count in header bytes 1 and 2.
     * The payload follows the header and is word count bytes long.
     *
     * Short write packets encode up to two parameters in header bytes 1
     * and 2.
     */
    uint8_t short_data[2];
    bool    long_packet = DSI_PACKET_FORMAT_IS_LONG(p_cmd->cmd_id);
    if (long_packet)
    {
        short_data[0] =
            (uint8_t) ((p_cmd->tx_len & R_MIPI_DSI_SQCH0DSC00AR_DATA0_Msk) >> R_MIPI_DSI_SQCH0DSC00AR_DATA0_Pos);
        short_data[1] =
            (uint8_t) ((p_cmd->tx_len & R_MIPI_DSI_SQCH0DSC00AR_DATA1_Msk) >> R_MIPI_DSI_SQCH0DSC00AR_DATA1_Pos);
    }
    else
    {
        short_data[0] = (p_cmd->tx_len > 0) ? p_cmd->p_tx_buffer[0] : 0U;
        short_data[1] = (p_cmd->tx_len > 1) ? p_cmd->p_tx_buffer[1] : 0U;
    }

    uint8_t bta =
        (p_cmd->flags & (MIPI_DSI_CMD_FLAG_BTA | MIPI_DSI_CMD_FLAG_BTA_READ | MIPI_DSI_CMD_FLAG_BTA_NO_WRITE));

    uint8_t  lp = (0 != (p_cmd->flags & MIPI_DSI_CMD_FLAG_LOW_POWER));
    uint32_t sequence_register_a =
        (((uint32_t) short_data[0] << R_MIPI_DSI_SQCH0DSC00AR_DATA0_Pos) & R_MIPI_DSI_SQCH0DSC00AR_DATA0_Msk) |
        (((uint32_t) short_data[1] << R_MIPI_DSI_SQCH0DSC00AR_DATA1_Pos) & R_MIPI_DSI_SQCH0DSC00AR_DATA1_Msk) |
        (((uint32_t) p_cmd->cmd_id << R_MIPI_DSI_SQCH0DSC00AR_DT_Pos) & R_MIPI_DSI_SQCH0DSC00AR_DT_Msk) |
        (((uint32_t) p_cmd->channel << R_MIPI_DSI_SQCH0DSC00AR_VC_Pos) & R_MIPI_DSI_SQCH0DSC00AR_VC_Msk) |
        (((uint32_t) long_packet << R_MIPI_DSI_SQCH0DSC00AR_FMT_Pos) & R_MIPI_DSI_SQCH0DSC00AR_FMT_Msk) |
        (((uint32_t) lp << R_MIPI_DSI_SQCH0DSC00AR_SPD_Pos) & R_MIPI_DSI_SQCH0DSC00AR_SPD_Msk) |
        (((uint32_t) bta << R_MIPI_DSI_SQCH0DSC00AR_BTA_Pos) & R_MIPI_DSI_SQCH0DSC00AR_BTA_Msk) |
        (((uint32_t) 0 << R_MIPI_DSI_SQCH0DSC00AR_NXACT_Pos) & R_MIPI_DSI_SQCH0DSC00AR_NXACT_Msk);

    return sequence_register_a;
}

/***********************************************************************************************************************
 * Returns configuration values for Sequence Register B
 *
 * @param[in]     p_cmd     Pointer to formatted message structure
 **********************************************************************************************************************/
static uint32_t dsi_cmd_sequence_register_b (mipi_dsi_cmd_t * p_cmd)
{
    uint8_t dtsel = 0;
    if (p_cmd->tx_len > DSI_TX_PACKET_PAYLOAD_DATA_WORD_COUNT_MAX)
    {
        /* Use sequence RAM */
        dtsel = 1;
    }
    else
    {
        /* Use packet payload data register */
        dtsel = 0;
    }

    return (dtsel << R_MIPI_DSI_SQCH0DSC00BR_DTSEL_Pos) & R_MIPI_DSI_SQCH0DSC00BR_DTSEL_Msk;
}

/***********************************************************************************************************************
 * Returns configuration values for Sequence Register C
 *
 * @param[in]     p_cmd     Pointer to formatted message structure
 **********************************************************************************************************************/
static uint32_t dsi_cmd_sequence_register_c (mipi_dsi_cmd_t * p_cmd)
{
    bool     aux_operation       = (p_cmd->flags & MIPI_DSI_CMD_FLAG_AUX_OPERATION);
    bool     actcode             = aux_operation ? (p_cmd->flags & 0xF) : 0; // Always store Rx result in slot 0
    uint32_t sequence_register_c =
        (((uint32_t) 0 << R_MIPI_DSI_SQCH0DSC00CR_FINACT_Pos) & R_MIPI_DSI_SQCH0DSC00CR_FINACT_Msk) |
        (((uint32_t) aux_operation << R_MIPI_DSI_SQCH0DSC00CR_AUXOP_Pos) & R_MIPI_DSI_SQCH0DSC00CR_AUXOP_Msk) |
        (((uint32_t) actcode << R_MIPI_DSI_SQCH0DSC00CR_ACTCODE_Pos) & R_MIPI_DSI_SQCH0DSC00CR_ACTCODE_Msk);

    return sequence_register_c;
}

/***********************************************************************************************************************
 * Returns configuration values for Sequence Register D
 *
 * @param[in]     p_cmd     Pointer to formatted message structure
 **********************************************************************************************************************/
static uint32_t dsi_cmd_sequence_register_d (mipi_dsi_cmd_t * p_cmd)
{
    uint8_t bta =
        (p_cmd->flags & (MIPI_DSI_CMD_FLAG_BTA | MIPI_DSI_CMD_FLAG_BTA_READ | MIPI_DSI_CMD_FLAG_BTA_NO_WRITE));

    return (uint32_t) ((uintptr_t) (bta ? p_cmd->p_rx_buffer : p_cmd->p_tx_buffer) & CAST_TO_UINT32); // This buffer address is used for both Tx and Rx.
}

/*******************************************************************************************************************//**
 * Calls user callback
 *
 * @param[in]     p_ctrl     Pointer to MIPI DSI instance control block
 * @param[in]     p_args     Pointer to arguments on stack
 **********************************************************************************************************************/
static void dsi_call_callback (mipi_dsi_b_instance_ctrl_t * p_ctrl, mipi_dsi_callback_args_t * p_args)
{
    mipi_dsi_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    mipi_dsi_callback_args_t * p_args_memory = p_ctrl->p_callback_memory;

    if (NULL == p_args_memory)
    {
        /* Use provided args struct on stack */
        p_args_memory = p_args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args_memory;

        /* Copy the stacked args to callback memory */
        *p_args_memory = *p_args;
    }

#if BSP_TZ_SECURE_BUILD

    /* p_callback can point to a secure function or a non-secure function. */
    if (!cmse_is_nsfptr(p_ctrl->p_callback))
    {
        /* If p_callback is secure, then the project does not need to change security state. */
        p_ctrl->p_callback(p_args_memory);
    }
    else
    {
        /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
        mipi_dsi_prv_ns_callback p_callback = (mipi_dsi_prv_ns_callback) (p_ctrl->p_callback);
        p_callback(p_args_memory);
    }
#else

    /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
    p_ctrl->p_callback(p_args_memory);
#endif

    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * Private helper functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enter Reset
 * Perform sequence from section 34.4.2.1.(2) in RZ/A3M hardware manual.
 **********************************************************************************************************************/
static void dsi_enter_reset ()
{
    /* Enable clock lane */
    R_MIPI_DSI->TXSETR_b.CLEN = 1U;

    /* Enter the DSI Host software reset state */
    R_MIPI_DSI->RSTCR_b.SWRST = 1;

    /* Wait for reset process to start - Polling RSTSR is okay since it's not updated in interrupt.*/
    FSP_HARDWARE_REGISTER_WAIT((R_MIPI_DSI->RSTSR & MIPI_DSI_RSTSR_RESET_BITS), MIPI_DSI_RSTSR_RESET_BITS);
}

/*******************************************************************************************************************//**
 * Initialize timing registers from configuration data
 * - Perform sequence step (F) from section 34.4.2.1.(1) in RZ/A3M hardware manual.
 *
 * @param[in]     p_cfg     Pointer to MIPI DSI configuration structure
 **********************************************************************************************************************/
static void dsi_init_timing (mipi_dsi_cfg_t const * const p_cfg)
{
    /* Set common settings */
    /* Enable clock and data lanes and set number of lanes to use */
    R_MIPI_DSI->TXSETR = R_MIPI_DSI_TXSETR_DLEN_Msk | R_MIPI_DSI_TXSETR_CLEN_Msk | (uint32_t) (p_cfg->num_lanes - 1);

    /* Set ULPS wake-up period */
    R_MIPI_DSI->ULPSSETR_b.ULPSWKUP = p_cfg->ulps_wakeup_period;

    /* Set data scrambling and/or EoTp transmission */
    R_MIPI_DSI->DSISETR =
        ((p_cfg->max_return_packet_size << R_MIPI_DSI_DSISETR_MRPSZ_Pos) & R_MIPI_DSI_DSISETR_MRPSZ_Msk) |
        (((uint32_t) p_cfg->ecc_enable << R_MIPI_DSI_DSISETR_ECCEN_Pos) & R_MIPI_DSI_DSISETR_ECCEN_Msk) |
        (((uint32_t) p_cfg->crc_check_mask << R_MIPI_DSI_DSISETR_CRCEN_Pos) & R_MIPI_DSI_DSISETR_CRCEN_Msk) |
        (((uint32_t) p_cfg->scramble_enable << R_MIPI_DSI_DSISETR_SCREN_Pos) & R_MIPI_DSI_DSISETR_SCREN_Msk) |
        (((uint32_t) p_cfg->tearing_detect << R_MIPI_DSI_DSISETR_TEIDIR_Pos) & R_MIPI_DSI_DSISETR_TEIDIR_Msk) |
        (((uint32_t) p_cfg->eotp_enable << R_MIPI_DSI_DSISETR_EOTPEN_Pos) & R_MIPI_DSI_DSISETR_EOTPEN_Msk);

    /* Set LP lane transition timing */
    R_MIPI_DSI->CLSTPTSETR =
        ((p_cfg->p_timing->clock_stop_time << R_MIPI_DSI_CLSTPTSETR_CLKSTPT_Pos) &
         R_MIPI_DSI_CLSTPTSETR_CLKSTPT_Msk) |
        ((p_cfg->p_timing->clock_beforehand_time << R_MIPI_DSI_CLSTPTSETR_CLKBFHT_Pos) &
         R_MIPI_DSI_CLSTPTSETR_CLKBFHT_Msk) |
        ((p_cfg->p_timing->clock_keep_time << R_MIPI_DSI_CLSTPTSETR_CLKKPT_Pos) &
         R_MIPI_DSI_CLSTPTSETR_CLKKPT_Msk);
    R_MIPI_DSI->LPTRNSTSETR = p_cfg->p_timing->go_lp_and_back & R_MIPI_DSI_LPTRNSTSETR_GOLPBKT_Msk;

    /* Set timeout values */
    R_MIPI_DSI->PRESPTOBTASETR = p_cfg->bta_timeout;
    R_MIPI_DSI->PRESPTOLPSETR  = p_cfg->lprw_timeout;
    R_MIPI_DSI->PRESPTOHSSETR  = p_cfg->hsrw_timeout;
    R_MIPI_DSI->HSTXTOSETR     = p_cfg->hs_tx_timeout;
    R_MIPI_DSI->LRXHTOSETR     = p_cfg->lp_rx_timeout;
    R_MIPI_DSI->TATOSETR       = p_cfg->turnaround_timeout;
}

/*******************************************************************************************************************//**
 * Returns base to the power of expon
 *
 * @param[in]     base      Base number
 * @param[in]     expon     Exponent
 **********************************************************************************************************************/
static uint8_t dsi_pow (uint8_t base, uint8_t expon)
{
    uint8_t result = 1;
    for (uint8_t i = 0; i < expon; i++)
    {
        result *= base;
    }

    return result;
}

/*******************************************************************************************************************//**
 * Exit Reset
 * Perform sequence steps 34.4.2.1.(2) in RZ/A3M hardware manual.
 *
 * NOTE: Calling this function is prohibited without first calling dsi_enter_reset(), which sets RSTCR.SWRST to 1
 *
 * @param[in]     p_cfg     Pointer to MIPI DSI configuration structure
 **********************************************************************************************************************/
static void dsi_exit_reset (mipi_dsi_cfg_t const * const p_cfg)
{
    /* Transition data lanes to stop state */
    R_MIPI_DSI->RSTCR_b.FCETXSTP = 1U;

    /* Wait for data lanes transition to stop state */
    FSP_HARDWARE_REGISTER_WAIT((R_MIPI_DSI->RSTSR &
                                (R_MIPI_DSI_RSTSR_DL0DIR_Msk | R_MIPI_DSI_RSTSR_DLSTPST_Msk)),
                               (((uint32_t) (dsi_pow(2, p_cfg->num_lanes)) - 1) << R_MIPI_DSI_RSTSR_DLSTPST_Pos));

    /* Clear the Force Tx Stop and Software Reset bits */
    R_MIPI_DSI->RSTCR_b.FCETXSTP = 0U;
    R_MIPI_DSI->RSTCR_b.SWRST    = 0U;

    /* Wait for software reset to complete */
    FSP_HARDWARE_REGISTER_WAIT((R_MIPI_DSI->RSTSR & MIPI_DSI_RSTSR_RESET_BITS), 0);
}

/*******************************************************************************************************************//**
 * Initialize High Speed Clock
 * Perform sequence steps from section 34.4.2.2 in RZ/A3M hardware manual.
 *
 * @param[in]     p_ctrl     Pointer to MIPI DSI instance control block
 **********************************************************************************************************************/
static void dsi_hs_clock_start (mipi_dsi_b_instance_ctrl_t * p_ctrl)
{
    mipi_dsi_cfg_t const * p_cfg = p_ctrl->p_cfg;

    /* Enable clock lane */
    R_MIPI_DSI->TXSETR_b.CLEN = 1U;
    p_ctrl->clock_state       = MIPI_DSI_CLOCK_STATE_STARTING;

    R_MIPI_DSI->HSCLKSETR = R_MIPI_DSI_HSCLKSETR_HSCLKRUN_Msk |
                            (p_cfg->continuous_clock ? R_MIPI_DSI_HSCLKSETR_HSCLKMODE_Msk : 0U);

    while ((R_MIPI_DSI->PLSR_b.CLLP2HS != p_cfg->continuous_clock) &&
           (p_ctrl->clock_state != MIPI_DSI_CLOCK_STATE_STARTED))
    {
        /* Wait for HS clock notification bit set to 1. (only in the continuous clock mode)
         * NOTE: PLSR may be modified in ISR */
    }

    p_ctrl->clock_state = MIPI_DSI_CLOCK_STATE_STARTED;
}

/***********************************************************************************************************************
 * De-initialize High Speed Clock
 * Perform sequence steps from section 34.4.2.2 in RZ/A3M hardware manual.
 *
 * @param[in]     p_ctrl     Pointer to MIPI DSI instance control block
 **********************************************************************************************************************/
static void dsi_hs_clock_stop (mipi_dsi_b_instance_ctrl_t * p_ctrl)
{
    mipi_dsi_cfg_t const * p_cfg = p_ctrl->p_cfg;

    R_MIPI_DSI->HSCLKSETR_b.HSCLKRUN = 0;
    p_ctrl->clock_state              = MIPI_DSI_CLOCK_STATE_STOPPING;

    while ((R_MIPI_DSI->PLSR_b.CLHS2LP != p_cfg->continuous_clock) &&
           (p_ctrl->clock_state != MIPI_DSI_CLOCK_STATE_IDLE))
    {
        /* Wait for clock lane transition LP state.
         * NOTE: PLSR may be modified in ISR */
    }

    p_ctrl->clock_state = MIPI_DSI_CLOCK_STATE_IDLE;
}

/***********************************************************************************************************************
 * Initialize Video Output Registers
 * Perform sequence steps 4 and 6 from section 34.4.2.4.(1) in RZ/A3M hardware manual.
 *
 * @param[in]     p_cfg     Pointer to MIPI DSI configuration structure
 **********************************************************************************************************************/
static void dsi_init_video (mipi_dsi_cfg_t const * p_cfg)
{
    R_MIPI_DSI->VICH1PPSETR =
        (((uint32_t) p_cfg->sync_pulse << R_MIPI_DSI_VICH1PPSETR_TXESYNC_Pos) & R_MIPI_DSI_VICH1PPSETR_TXESYNC_Msk) |
        (((uint32_t) p_cfg->data_type << R_MIPI_DSI_VICH1PPSETR_DT_Pos) & R_MIPI_DSI_VICH1PPSETR_DT_Msk) |
        (((uint32_t) p_cfg->virtual_channel_id << R_MIPI_DSI_VICH1PPSETR_VC_Pos) &
         R_MIPI_DSI_VICH1PPSETR_VC_Msk);
    R_MIPI_DSI->VICH1VSSETR =
        ((p_cfg->vertical_sync_lines << R_MIPI_DSI_VICH1VSSETR_VSA_Pos) & R_MIPI_DSI_VICH1VSSETR_VSA_Msk) |
        (((uint32_t) p_cfg->vertical_sync_polarity << R_MIPI_DSI_VICH1VSSETR_VSPOL_Pos) &
         R_MIPI_DSI_VICH1VSSETR_VSPOL_Msk) |
        ((p_cfg->vertical_active_lines << R_MIPI_DSI_VICH1VSSETR_VACTIVE_Pos) &
         R_MIPI_DSI_VICH1VSSETR_VACTIVE_Msk);
    R_MIPI_DSI->VICH1VPSETR =
        ((p_cfg->vertical_back_porch << R_MIPI_DSI_VICH1VPSETR_VBP_Pos) & R_MIPI_DSI_VICH1VPSETR_VBP_Msk) |
        ((p_cfg->vertical_front_porch << R_MIPI_DSI_VICH1VPSETR_VFP_Pos) &
         R_MIPI_DSI_VICH1VPSETR_VFP_Msk);
    R_MIPI_DSI->VICH1HSSETR =
        ((p_cfg->horizontal_sync_lines << R_MIPI_DSI_VICH1HSSETR_HSA_Pos) & R_MIPI_DSI_VICH1HSSETR_HSA_Msk) |
        (((uint32_t) p_cfg->horizontal_sync_polarity << R_MIPI_DSI_VICH1HSSETR_HSPOL_Pos) &
         R_MIPI_DSI_VICH1HSSETR_HSPOL_Msk) |
        ((p_cfg->horizontal_active_lines << R_MIPI_DSI_VICH1HSSETR_HACTIVE_Pos) &
         R_MIPI_DSI_VICH1HSSETR_HACTIVE_Msk);
    R_MIPI_DSI->VICH1HPSETR =
        ((p_cfg->horizontal_back_porch << R_MIPI_DSI_VICH1HPSETR_HBP_Pos) & R_MIPI_DSI_VICH1HPSETR_HBP_Msk) |
        ((p_cfg->horizontal_front_porch << R_MIPI_DSI_VICH1HPSETR_HFP_Pos) &
         R_MIPI_DSI_VICH1HPSETR_HFP_Msk);
    R_MIPI_DSI->VICH1SET1R =
        ((p_cfg->video_mode_delay << R_MIPI_DSI_VICH1SET1R_DLY_Pos) & R_MIPI_DSI_VICH1SET1R_DLY_Msk);

    R_MIPI_DSI->VICH1SET0R          = p_cfg->hsa_no_lp | p_cfg->hbp_no_lp | p_cfg->hfp_no_lp;
    R_MIPI_DSI->VICH1SET0R_b.VSTART = (1U << R_MIPI_DSI_VICH1SET0R_VSTART_Pos) & R_MIPI_DSI_VICH1SET0R_VSTART_Msk;
}

/***********************************************************************************************************************
 * Enable the specified ISR and add the control structure to the ISR context lookup table.
 *
 * @param[in]     irq_cfg    Pointer to interrupt configuration structure
 * @param[in]     p_ctrl     Pointer to MIPI DSI instance control block
 **********************************************************************************************************************/
static void dsi_isr_enable (mipi_dsi_b_irq_cfg_t const * irq_cfg, mipi_dsi_b_instance_ctrl_t * p_ctrl)
{
    R_BSP_IrqCfgEnable(irq_cfg->irq, irq_cfg->ipl, p_ctrl);
}

/***********************************************************************************************************************
 * Disable the specified ISR
 *
 * @param[in]     irq_cfg    Pointer to interrupt configuration structure
 **********************************************************************************************************************/
static void dsi_isr_disable (mipi_dsi_b_irq_cfg_t const * irq_cfg)
{
    R_BSP_IrqDisable(irq_cfg->irq);
    R_FSP_IsrContextSet(irq_cfg->irq, NULL);
}

/***********************************************************************************************************************
 * Interrupt Service Routines
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Sequence 0 ISR
 *  - Process LP sequence command events and forward them to the user callback
 **********************************************************************************************************************/
void mipi_dsi_seq0 (IRQn_Type const irq) {
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    /* Clear sequence channel 0 status register bits */
    uint32_t sqch0sr_bits = R_MIPI_DSI->SQCH0SR;
    R_MIPI_DSI->SQCH0SCR = sqch0sr_bits;

    /* Clear the IR flag */
    R_BSP_IrqStatusClear(irq);

    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    mipi_dsi_callback_args_t     args;
    args.event     = MIPI_DSI_EVENT_SEQUENCE_0;
    args.tx_status = (mipi_dsi_sequence_status_t) sqch0sr_bits;
    args.p_context = p_ctrl->p_context;
    dsi_call_callback(p_ctrl, &args);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

/***********************************************************************************************************************
 * Sequence 1 ISR
 *  - Process HS sequence command events and forward them to the user callback
 **********************************************************************************************************************/
void mipi_dsi_seq1 (IRQn_Type const irq) {
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    /* Clear sequence channel 1 status register bits */
    uint32_t sqch1sr_bits = R_MIPI_DSI->SQCH1SR;
    R_MIPI_DSI->SQCH1SCR = sqch1sr_bits;

    /* Clear the IR flag */
    R_BSP_IrqStatusClear(irq);

    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    mipi_dsi_callback_args_t     args;
    args.event     = MIPI_DSI_EVENT_SEQUENCE_1;
    args.tx_status = (mipi_dsi_sequence_status_t) sqch1sr_bits;
    args.p_context = p_ctrl->p_context;
    dsi_call_callback(p_ctrl, &args);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

/***********************************************************************************************************************
 * Video Input ISR
 *  - Process DSI Video Input Events and forward them to the user callback
 **********************************************************************************************************************/
void mipi_dsi_vin1 (IRQn_Type const irq) {
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    /* Clear video mode status register bits */
    uint32_t vmsr_bits = R_MIPI_DSI->VICH1SR;
    R_MIPI_DSI->VICH1SCR = vmsr_bits;

    /* Clear the IR flag */
    R_BSP_IrqStatusClear(irq);

    /* Update internal state */
    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    if (vmsr_bits & R_MIPI_DSI_VICH1SR_VIRDY_Msk)
    {
        p_ctrl->video_started = true;
    }
    else if (vmsr_bits & R_MIPI_DSI_VICH1SR_STOP_Msk)
    {
        p_ctrl->video_started = false;
    }
    else
    {
        // do nothing
    }

    /* Pass data to user */
    mipi_dsi_callback_args_t args;
    args.event        = MIPI_DSI_EVENT_VIDEO;
    args.video_status = (mipi_dsi_video_status_t) vmsr_bits;
    args.p_context    = p_ctrl->p_context;
    dsi_call_callback(p_ctrl, &args);

    /* Perform reset according to RZA3M UM 34.4.2.6.(6) */
    if (vmsr_bits & (R_MIPI_DSI_VICH1SR_VBUFUDF_Msk | R_MIPI_DSI_VICH1SR_VBUFOVF_Msk | R_MIPI_DSI_VICH1SR_TIMERR_Msk))
    {
        dsi_enter_reset();
        dsi_exit_reset(p_ctrl->p_cfg);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

/***********************************************************************************************************************
 * Receive ISR
 *  - Process Receive Events and forward them to the user callback
 **********************************************************************************************************************/
void mipi_dsi_rcv (IRQn_Type const irq) {
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    /* Clear receive status register bits */
    uint32_t rxsr_bits = R_MIPI_DSI->RXSR;
    R_MIPI_DSI->RXSCR = rxsr_bits;

    /* Clear the IR flag */
    R_BSP_IrqStatusClear(irq);

    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    mipi_dsi_callback_args_t     args;
    args.event     = MIPI_DSI_EVENT_RECEIVE;
    args.rx_status = (mipi_dsi_receive_status_t) rxsr_bits;
    args.p_result  = (mipi_dsi_receive_result_t *) &R_MIPI_DSI->RXRSS0R;
    args.p_context = p_ctrl->p_context;
    dsi_call_callback(p_ctrl, &args);

    R_MIPI_DSI->RXRINFOOWSCR = R_MIPI_DSI_RXRINFOOWSCR_SLT0INFOOWC_Msk; // Clear slot 0 after reading

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

/***********************************************************************************************************************
 * Fatal Error ISR
 *  - Process Fatal Error Events and forward them to the user callback
 **********************************************************************************************************************/
void mipi_dsi_ferr (IRQn_Type const irq) {
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    /* Clear receive status register bits */
    uint32_t ferrsr_bits = R_MIPI_DSI->FERRSR;
    R_MIPI_DSI->FERRSCR = ferrsr_bits;

    /* Clear the IR flag */
    R_BSP_IrqStatusClear(irq);

    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    mipi_dsi_callback_args_t     args;
    args.event        = MIPI_DSI_EVENT_FATAL;
    args.fatal_status = (mipi_dsi_fatal_status_t) ferrsr_bits;
    args.p_context    = p_ctrl->p_context;
    dsi_call_callback(p_ctrl, &args);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}

/***********************************************************************************************************************
 * PHY-Protocol Interface ISR
 *  - Process Phy-Protocol Events and forward them to the user callback
 **********************************************************************************************************************/
void mipi_dsi_ppi (IRQn_Type const irq) {
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    /* Clear PLSR */
    uint32_t plsr_bits = R_MIPI_DSI->PLSR;
    R_MIPI_DSI->PLSCR = plsr_bits;

    /* Clear the IR flag */
    R_BSP_IrqStatusClear(irq);

    /* Update internal state */
    mipi_dsi_b_instance_ctrl_t * p_ctrl = (mipi_dsi_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    if ((p_ctrl->clock_state == MIPI_DSI_CLOCK_STATE_STARTING) &&
        (plsr_bits & R_MIPI_DSI_PLSR_CLLP2HS_Msk))
    {
        p_ctrl->clock_state = MIPI_DSI_CLOCK_STATE_STARTED;
    }
    else if ((p_ctrl->clock_state == MIPI_DSI_CLOCK_STATE_STOPPING) &&
             (plsr_bits & R_MIPI_DSI_PLSR_CLHS2LP_Msk))
    {
        p_ctrl->clock_state = MIPI_DSI_CLOCK_STATE_IDLE;
    }
    else
    {
        // do nothing
    }

    /* Pass data to user */
    mipi_dsi_callback_args_t args;
    args.event      = MIPI_DSI_EVENT_PHY;
    args.phy_status = (mipi_dsi_phy_status_t) plsr_bits;
    args.p_context  = p_ctrl->p_context;
    dsi_call_callback(p_ctrl, &args);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;
}
