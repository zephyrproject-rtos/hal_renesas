/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_canfdg.h"
#include "r_canfdg_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define CANFDG_OPEN                        (0x43464447U) // "CFDG" in ASCII

#define CANFDG_BAUD_RATE_PRESCALER_MIN     (1U)
#define CANFDG_BAUD_RATE_PRESCALER_MAX     (1024U)

#define CANFDG_PRV_CTR_MODE_MASK           (R_CANFDG_GCR_SLPRQ_Msk + R_CANFDG_GCR_MDC_Msk)
#define CANFDG_PRV_CTR_RESET_BIT           (1U)
#define CANFDG_PRV_RXMB_MAX                (32U)
#define CANFDG_PRV_TXMB_OFFSET             (32U)
#define CANFDG_PRV_TXMB_CHANNEL_OFFSET     (64U)
#define CANFDG_PRV_STANDARD_ID_MAX         (0x7FFU)

#define CANFDG_PRV_CFIFO_CHANNEL_OFFSET    (3U)

#define R_CANFDG_CFDRM_RM_TYPE             R_CANFDG_RMB_Type

#define CANFDG_PRV_RXMB_PTR(buffer)    (&p_reg->RMB[buffer])
#define CANFDG_PRV_RX_FIFO_MAX             (8U)
#define CANFDG_PRV_COMMON_FIFO_MAX         (3U)
#define CANFDG_PRV_CFDTMIEC_LENGTH         (2)
#define CANFDG_PRV_RMID_POSITION           (R_CANFDG_RMB_HF0_ID_Pos)
#define CANFDG_PRV_RMID_MASK               (R_CANFDG_RMB_HF0_ID_Msk)
#define CANFDG_PRV_RMRTR_POSITION          (R_CANFDG_RMB_HF0_RTR_Pos)
#define CANFDG_PRV_RMRTR_MASK              (R_CANFDG_RMB_HF0_RTR_Msk)
#define CANFDG_PRV_RMIDE_POSITION          (R_CANFDG_RMB_HF0_IDE_Pos)
#define CANFDG_PRV_RMIDE_MASK              (R_CANFDG_RMB_HF0_IDE_Msk)
#define CANFDG_PRV_RMDLC_POSITION          (R_CANFDG_RMB_HF1_DLC_Pos)
#define CANFDG_PRV_RMDLC_MASK              (R_CANFDG_RMB_HF1_DLC_Msk)
#define CANFDG_PRV_FESR_RFEMPX_MASK        (0xFFU)
#define CANFDG_PRV_FESR_CFEMPX_MASK        (0x3F00U)

#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
 #define CANFDG_INTER_CH(channel)                  (0U)
#else
 #define CANFDG_INTER_CH(channel)                  (channel)
#endif

#define CANFDG_PRV_CFIFO_INDEX(buffer, channel)    ((buffer) + ((channel) * CANFDG_PRV_CFIFO_CHANNEL_OFFSET))
#define CANFDG_WORD_DATA_BITS_LENGTH    (32U)
#define CANFDG_PRV_BIT_MASK_VALUE       (0x80000000U)

#define CANFDG_PRV_CFRISRF_Msk          (0x3FUL)

/***********************************************************************************************************************
 * Const data
 **********************************************************************************************************************/

/* LUT to convert DLC values to payload size in bytes */
static const uint8_t dlc_to_bytes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};

#if CANFDG_CFG_PARAM_CHECKING_ENABLE

/* LUT to determine the hierarchy of can_operation_mode_t modes. */
static const uint8_t g_mode_order[] = {0, 2, 1, 0, 0, 3};
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
#if CANFDG_CFG_PARAM_CHECKING_ENABLE
static bool r_canfdg_bit_timing_parameter_check(can_bit_timing_cfg_t * p_bit_timing, bool is_data_phase);

#endif

#if BSP_FEATURE_CANFD_FD_SUPPORT
static uint8_t r_canfdg_bytes_to_dlc(uint8_t bytes);

#endif

static void     r_canfdg_global_error_handler(uint32_t instance);
static void     r_canfdg_rx_fifo_handler(uint32_t instance);
static void     r_canfdg_mb_read(R_CANFDG_Type * p_reg, uint32_t buffer, can_frame_t * const frame);
static void     r_canfdg_call_callback(canfdg_instance_ctrl_t * p_ctrl, can_callback_args_t * p_args);
static void     r_canfdg_mode_transition(canfdg_instance_ctrl_t * p_ctrl, can_operation_mode_t operation_mode);
static void     r_canfdg_mode_ctr_set(volatile uint32_t * p_ctr_reg, can_operation_mode_t operation_mode);
static uint32_t r_canfdg_reverse_bit_order(uint32_t val);
static uint8_t  r_canfdg_count_leading_zeros(uint32_t val);
void            canfdg_error_isr(void);
void            canfdg_rx_fifo_isr(void);
void            canfdg_common_fifo_rx_isr(void);
void            canfdg_channel_tx_isr(void);

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* Channel control struct array */
static canfdg_instance_ctrl_t * gp_ctrl[BSP_FEATURE_CANFD_NUM_INSTANCES * BSP_FEATURE_CANFDG_NUM_CHANNELS] = {NULL};

/* CAN function pointers   */
const can_api_t g_canfd_on_canfdg =
{
    .open           = R_CANFDG_Open,
    .close          = R_CANFDG_Close,
    .write          = R_CANFDG_Write,
    .read           = R_CANFDG_Read,
    .modeTransition = R_CANFDG_ModeTransition,
    .infoGet        = R_CANFDG_InfoGet,
    .callbackSet    = R_CANFDG_CallbackSet,
};

/*******************************************************************************************************************//**
 * @addtogroup CANFDG
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***************************************************************************************************************//**
 * Open and configure the CANFDG channel for operation.
 *
 * Example:
 * @snippet r_canfdg_example.c R_CANFDG_Open
 *
 * @retval FSP_SUCCESS                            Channel opened successfully.
 * @retval FSP_ERR_ALREADY_OPEN                   Driver already open.
 * @retval FSP_ERR_IN_USE                         Channel is already in use.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT         Channel does not exist on this MCU.
 * @retval FSP_ERR_ASSERTION                      A required pointer was NULL.
 * @retval FSP_ERR_CAN_INIT_FAILED                The provided nominal or data bitrate is invalid.
 * @retval FSP_ERR_CLOCK_INACTIVE                 CANFD source clock is disabled (PLL or PLL2).
 *****************************************************************************************************************/
fsp_err_t R_CANFDG_Open (can_ctrl_t * const p_api_ctrl, can_cfg_t const * const p_cfg)
{
    canfdg_instance_ctrl_t * p_ctrl = (canfdg_instance_ctrl_t *) p_api_ctrl;

#if CANFDG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_cfg);
    FSP_ASSERT(p_cfg->p_extend);
    FSP_ASSERT(p_cfg->p_callback);
    FSP_ASSERT(p_cfg->p_bit_timing);

    uint32_t channel = p_cfg->channel;

    /* Check that the module is not open, the channel is present and that it is not in use */
    FSP_ERROR_RETURN(CANFDG_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ERROR_RETURN(channel < BSP_FEATURE_CANFDG_NUM_CHANNELS * BSP_FEATURE_CANFD_NUM_INSTANCES,
                     FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    FSP_ERROR_RETURN(NULL == gp_ctrl[channel], FSP_ERR_IN_USE);

    /* Check that mandatory interrupts are enabled */
    FSP_ERROR_RETURN(VECTOR_NUMBER_CANFDG0_RFRI >= 0, FSP_ERR_CAN_INIT_FAILED);
    FSP_ERROR_RETURN(VECTOR_NUMBER_CANFDG0_GLEI >= 0, FSP_ERR_CAN_INIT_FAILED);

    /* Check that the global config is present */
    canfdg_extended_cfg_t * p_extend = (canfdg_extended_cfg_t *) p_cfg->p_extend;
    FSP_ASSERT(p_extend->p_global_cfg);

 #if BSP_CFG_CANFDCLK_SOURCE != BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC
  #if (BSP_FEATURE_CGC_PLL1_NUM_OUTPUT_CLOCKS > 1U) || (BSP_FEATURE_CGC_PLL2_NUM_OUTPUT_CLOCKS > 1U)
   #if (BSP_FEATURE_CGC_PLL1_NUM_OUTPUT_CLOCKS == 3U) /* PLL1 has 3 possible outputs that can be used for DLL */
    uint8_t canFdClockSelect = R_SYSTEM->CANFDCKCR;

    /* Check that PLL1 is running when it is selected as the DLL source clock */
    FSP_ERROR_RETURN(0U ==
                     (((canFdClockSelect == BSP_CLOCKS_SOURCE_CLOCK_PLL1P) ||
                       (canFdClockSelect == BSP_CLOCKS_SOURCE_CLOCK_PLL1Q) ||
                       (canFdClockSelect == BSP_CLOCKS_SOURCE_CLOCK_PLL1R)) ?
                      R_SYSTEM->PLLCR : 0),
                     FSP_ERR_CLOCK_INACTIVE);
   #endif
   #if (BSP_FEATURE_CGC_PLL2_NUM_OUTPUT_CLOCKS == 3U) /* PLL2 has 3 possible outputs that can be used for DLL */
    /* Check that PLL2 is running when it is selected as the DLL source clock */
    FSP_ERROR_RETURN(0U ==
                     (((canFdClockSelect == BSP_CLOCKS_SOURCE_CLOCK_PLL2P) ||
                       (canFdClockSelect == BSP_CLOCKS_SOURCE_CLOCK_PLL2Q) ||
                       (canFdClockSelect == BSP_CLOCKS_SOURCE_CLOCK_PLL2R)) ?
                      R_SYSTEM->PLL2CR : 0),
                     FSP_ERR_CLOCK_INACTIVE);
   #endif
  #else
   #if (BSP_FEATURE_CGC_PLL2_NUM_OUTPUT_CLOCKS == 1U)

    /* PLL/PLL2 has 1 possible output that can be used for DLL */

    /* Check that PLL/PLL2 is running when it is selected as the DLL source clock */
    FSP_ERROR_RETURN(0U ==
                     (FSP_STYPE3_REG8_READ(R_SYSTEM->CANFDCKCR,
                                           !R_SYSTEM->CGFSAR_b.NONSEC18) == BSP_CLOCKS_SOURCE_CLOCK_PLL ?
                      FSP_STYPE3_REG8_READ(R_SYSTEM->PLLCR, !R_SYSTEM->CGFSAR_b.NONSEC08) :
                      FSP_STYPE3_REG8_READ(R_SYSTEM->PLL2CR, !R_SYSTEM->CGFSAR_b.NONSEC09)),
                     FSP_ERR_CLOCK_INACTIVE);
   #elif BSP_FEATURE_CGC_HAS_PLLCR2

    /* The PLL is available and it has 1 possible output that can be used for DLL */

    /* Check that PLL is running when it is seclected as the DLL source clock */
    uint8_t pll_state = R_SYSTEM->PLLCR2;

    FSP_ERROR_RETURN(0U == (R_SYSTEM->SCKCR3 == BSP_CLOCKS_SOURCE_CLOCK_PLL ? pll_state : 0U), FSP_ERR_CLOCK_INACTIVE);
   #else
    FSP_ERROR_RETURN(0U ==
                     (FSP_STYPE3_REG8_READ(R_SYSTEM->CANFDCKCR,
                                           !R_SYSTEM->CGFSAR_b.NONSEC18) == BSP_CLOCKS_SOURCE_CLOCK_PLL ?
                      FSP_STYPE3_REG8_READ(R_SYSTEM->PLLCR, !R_SYSTEM->CGFSAR_b.NONSEC08) : 0),
                     FSP_ERR_CLOCK_INACTIVE);
   #endif
  #endif
 #endif

    /* Check nominal bit timing parameters for correctness */
    FSP_ERROR_RETURN(r_canfdg_bit_timing_parameter_check(p_cfg->p_bit_timing, false), FSP_ERR_CAN_INIT_FAILED);

 #if BSP_FEATURE_CANFD_FD_SUPPORT

    /* Check that bit timing for FD bitrate switching is present and correct */
    can_bit_timing_cfg_t * p_data_timing = p_extend->p_data_timing;
    FSP_ASSERT(p_data_timing);
    FSP_ERROR_RETURN(r_canfdg_bit_timing_parameter_check(p_data_timing, true), FSP_ERR_CAN_INIT_FAILED);

    can_bit_timing_cfg_t * p_bit_timing = p_cfg->p_bit_timing;

    /* Check that data rate > nominal rate */
    uint32_t data_rate_clocks = p_data_timing->baud_rate_prescaler *
                                (p_data_timing->time_segment_1 + p_data_timing->time_segment_2 + 1U);
    uint32_t nominal_rate_clocks = p_bit_timing->baud_rate_prescaler *
                                   (p_bit_timing->time_segment_1 + p_bit_timing->time_segment_2 + 1U);
    FSP_ERROR_RETURN(data_rate_clocks <= nominal_rate_clocks, FSP_ERR_CAN_INIT_FAILED);
 #endif
#else
    uint32_t channel = p_cfg->channel;

    /* Get extended config */
    canfdg_extended_cfg_t * p_extend = (canfdg_extended_cfg_t *) p_cfg->p_extend;
#endif

    fsp_err_t err = FSP_SUCCESS;

    /* Save the base register for this channel. */
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
    R_CANFDG_Type * p_reg =
        (R_CANFDG_Type *) ((uint32_t) R_CANFDG0 + (channel * ((uint32_t) R_CANFDG1 - (uint32_t) R_CANFDG0)));
#else
    R_CANFDG_Type * p_reg = R_CANFDG;
#endif
    p_ctrl->p_reg = p_reg;

    /* Initialize the control block */
    p_ctrl->p_cfg = p_cfg;

    /* Set callback and context pointers, if configured */
    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;

    /* Get global config */
    canfdg_global_cfg_t * p_global_cfg = p_extend->p_global_cfg;

    /* Start module */
    R_BSP_MODULE_START(FSP_IP_CANFDG, 0);

    /* Perform global config only if the module is in Global Sleep or Global Reset */
    if (p_reg->GSR & R_CANFDG_GSR_RSTST_Msk)
    {
        /* Wait for RAM initialization (see Note of "Timing of Global Mode Change" in the CANFD section of the relevant hardware manual) ) */
        FSP_HARDWARE_REGISTER_WAIT((p_reg->GSR & R_CANFDG_GSR_RAMST_Msk), 0);

        /* Cancel Global Sleep and wait for transition to Global Reset */
        r_canfdg_mode_transition(p_ctrl, CAN_OPERATION_MODE_GLOBAL_RESET);

        /* Configure global TX priority, DLC check/replace functions, external/internal clock select and payload
         * overflow behavior */
        p_reg->GCFG = p_global_cfg->global_config;

        /* Configure rule count for both channels */
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
        p_reg->AFCFG = (CANFDG_CFG_AFL_CH0_RULE_NUM << R_CANFDG_AFCFG_RN0_Pos);
#else
        p_reg->AFCFG = (CANFDG_CFG_AFL_CH0_RULE_NUM << R_CANFDG_AFCFG_RN0_Pos) |
                       CANFDG_CFG_AFL_CH1_RULE_NUM;
#endif

        /* Set CAN FD Protocol Exception response (ISO exception state or send error frame) */
        p_reg->GFDCFG = CANFDG_CFG_FD_PROTOCOL_EXCEPTION;

        /* Set number and size of RX message buffers */
        p_reg->RMCR = p_global_cfg->rx_mb_config;

        /* Configure RX FIFOs and interrupt */
        for (uint32_t i = 0; i < CANFDG_PRV_RX_FIFO_MAX; i++)
        {
            p_reg->RFCR[i] = p_global_cfg->rx_fifo_config[i];
        }

        R_BSP_IrqCfgEnable(VECTOR_NUMBER_CANFDG0_RFRI, (uint32_t) p_global_cfg->rx_fifo_ipl, NULL);

        /* Set global error interrupts */
        p_reg->GCR = p_global_cfg->global_interrupts;

        /* Configure Common FIFOs */
        for (uint32_t i = 0; i < R_CANFDG_NUM_COMMON_FIFOS; i++)
        {
            /* Configure the Common FIFOs. Mask out the enable bit because it can only be set once operating.
             * See "Common FIFO n Configuration Register" description in the CANFD section of the relevant hardware manual */
            p_reg->CFCR[i] = p_global_cfg->common_fifo_config[i] & ~R_CANFDG_CFCR_CFE_Msk;
        }
    }

#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
    if (CANFDG_CFG_GLOBAL_ERROR_CH == channel)
#endif
    {
        /* Configure global error interrupt */
        R_BSP_IrqCfgEnable(VECTOR_NUMBER_CANFDG0_GLEI, (uint32_t) p_global_cfg->global_err_ipl, p_ctrl);
    }

    /* Track ctrl struct */
    gp_ctrl[channel] = p_ctrl;

    /* Get AFL entry and limit */
    uint32_t afl_entry = 0;
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
    uint32_t afl_max = CANFDG_CFG_AFL_CH0_RULE_NUM;
    if (1U == channel)
    {
        afl_max = CANFDG_CFG_AFL_CH1_RULE_NUM;
    }

#else
    uint32_t afl_max = CANFDG_CFG_AFL_CH0_RULE_NUM;
    if (1U == channel)
    {
        afl_entry += CANFDG_CFG_AFL_CH0_RULE_NUM;
        afl_max   += CANFDG_CFG_AFL_CH1_RULE_NUM;
    }
#endif

    /* Unlock AFL */
    p_reg->AFCR = R_CANFDG_AFCR_AFLWE_Msk;

    /* Write all configured AFL entries */
    R_CANFDG_AFL_Type * p_afl = (R_CANFDG_AFL_Type *) p_extend->p_afl;
    for ( ; afl_entry < afl_max; afl_entry++)
    {
        /* AFL register access is performed through a page window comprised of 16 entries. See "Entering
         * Entries in the AFL" in the CANFD section of the relevant hardware manual. */

        /* Set AFL page */
        p_reg->AFCR = (afl_entry >> 4) | R_CANFDG_AFCR_AFLWE_Msk;

        /* Get pointer to current AFL rule and set it to the rule pointed to by p_afl */
        volatile R_CANFDG_AFL_Type * afl = &p_reg->AFL[afl_entry & 0xF];
        *afl = *p_afl++;

        /* Set Information Label 0 to the channel being configured */
        afl->PTR0_b.IFL0 = (p_cfg->channel) & 1U;
    }

    /* Lock AFL */
    p_reg->AFCR = 0;

    /* Cancel Channel Sleep and wait for transition to Channel Reset */
    r_canfdg_mode_transition(p_ctrl, CAN_OPERATION_MODE_RESET);

    uint32_t interlaced_channel = CANFDG_INTER_CH(channel);

    /* Configure bitrate */
    p_reg->CFDC[interlaced_channel].NBCR =
        (uint32_t) (((p_cfg->p_bit_timing->baud_rate_prescaler - 1) & R_CANFDG_CFDC_NBCR_BRP_Msk) <<
                    R_CANFDG_CFDC_NBCR_BRP_Pos) |
        ((p_cfg->p_bit_timing->time_segment_1 - 1U) << R_CANFDG_CFDC_NBCR_TSEG1_Pos) |
        ((p_cfg->p_bit_timing->time_segment_2 - 1U) << R_CANFDG_CFDC_NBCR_TSEG2_Pos) |
        ((p_cfg->p_bit_timing->synchronization_jump_width - 1U) << R_CANFDG_CFDC_NBCR_SJW_Pos);

#if BSP_FEATURE_CANFD_FD_SUPPORT

    /* Configure data bitrate for rate switching on FD frames */
    p_reg->CFDC2[interlaced_channel].DBCR =
        (uint32_t) (((p_extend->p_data_timing->baud_rate_prescaler - 1) & R_CANFDG_CFDC2_DBCR_BRP_Msk) <<
                    R_CANFDG_CFDC2_DBCR_BRP_Pos) |
        ((p_extend->p_data_timing->time_segment_1 - 1U) << R_CANFDG_CFDC2_DBCR_TSEG1_Pos) |
        ((p_extend->p_data_timing->time_segment_2 - 1U) << R_CANFDG_CFDC2_DBCR_TSEG2_Pos) |
        ((p_extend->p_data_timing->synchronization_jump_width - 1U) << R_CANFDG_CFDC2_DBCR_SJW_Pos);

    /* Ensure transceiver delay offset is not larger than 8 bits */
    uint32_t tdco = p_extend->p_data_timing->time_segment_1;
    if (tdco > UINT8_MAX)
    {
        tdco = UINT8_MAX;
    }

    /* Configure transceiver delay compensation; allow user to set ESI bit manually */
    p_reg->CFDC2[interlaced_channel].FDCFG =
        (tdco << R_CANFDG_CFDC2_FDCFG_TDCO_Pos) |
        (uint32_t) (p_extend->delay_compensation << R_CANFDG_CFDC2_FDCFG_TDCE_Pos) |
        R_CANFDG_CFDC2_FDCFG_TESI_Msk | 1U;
#endif

    /* Write TX message buffer interrupt enable bits */
    for (uint32_t i = 0; i < CANFDG_PRV_CFDTMIEC_LENGTH; i++)
    {
        p_reg->TMIER[(interlaced_channel * CANFDG_PRV_CFDTMIEC_LENGTH) + i] =
            (uint32_t) (p_extend->txmb_txi_enable >> (i * CANFDG_WORD_DATA_BITS_LENGTH));
    }

    /* Configure channel error interrupts */
    p_reg->CFDC[interlaced_channel].CHCR = p_extend->error_interrupts | R_CANFDG_CFDC_CHCR_MDC_Msk;

    /* Enable channel interrupts */

    if (p_cfg->error_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->error_irq, (uint32_t) p_cfg->ipl, p_ctrl);
    }

    if (p_cfg->tx_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->tx_irq, (uint32_t) p_cfg->ipl, p_ctrl);
    }

    /* Use the CAN RX IRQ for Common FIFO RX. */
    if (p_cfg->rx_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->rx_irq, (uint32_t) p_cfg->ipl, p_ctrl);
    }

    /* Set global mode to Operation and wait for transition */
    r_canfdg_mode_transition(p_ctrl, CAN_OPERATION_MODE_GLOBAL_OPERATION);

    /* Transition to Channel Operation */
    r_canfdg_mode_transition(p_ctrl, CAN_OPERATION_MODE_NORMAL);

    /* Set current operation modes */
    p_ctrl->operation_mode = CAN_OPERATION_MODE_NORMAL;
    p_ctrl->test_mode      = CAN_TEST_MODE_DISABLED;

    /* Set driver to open */
    p_ctrl->open = CANFDG_OPEN;

    return err;
}

/***************************************************************************************************************//**
 * Close the CANFDG channel.
 *
 * @retval FSP_SUCCESS               Channel closed successfully.
 * @retval FSP_ERR_NOT_OPEN          Control block not open.
 * @retval FSP_ERR_ASSERTION         Null pointer presented.
 *****************************************************************************************************************/
fsp_err_t R_CANFDG_Close (can_ctrl_t * const p_api_ctrl)
{
    canfdg_instance_ctrl_t * p_ctrl = (canfdg_instance_ctrl_t *) p_api_ctrl;

#if CANFDG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == CANFDG_OPEN, FSP_ERR_NOT_OPEN);
#endif

    /* Set driver to closed */
    p_ctrl->open = 0U;

    /* Get config struct */
    can_cfg_t * p_cfg = (can_cfg_t *) p_ctrl->p_cfg;

    /* Disable channel interrupts */

    if (p_cfg->error_irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->error_irq);
    }

    if (p_cfg->tx_irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->tx_irq);
    }

    if (p_cfg->rx_irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->rx_irq);
    }

    /* Disable Global Error interrupt if the handler channel is being closed */
    if (CANFDG_CFG_GLOBAL_ERROR_CH == p_cfg->channel)
    {
        R_BSP_IrqDisable(VECTOR_NUMBER_CANFDG0_GLEI);

#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1

        /* Disable RX FIFO interrupt */
        R_BSP_IrqDisable(VECTOR_NUMBER_CANFDG0_RFRI);
#endif
    }

    /* Set channel to Sleep if other is open, otherwise reset/stop CANFD module */
    if (gp_ctrl[!p_cfg->channel])
    {
        r_canfdg_mode_transition(p_ctrl, CAN_OPERATION_MODE_SLEEP);
    }
    else
    {
#if BSP_FEATURE_CANFD_NUM_INSTANCES == 1

        /* Disable RX FIFO interrupt */
        R_BSP_IrqDisable(VECTOR_NUMBER_CANFDG0_RFRI);
#endif

        /* Transition to Global Sleep */
        r_canfdg_mode_transition(p_ctrl, CAN_OPERATION_MODE_GLOBAL_RESET);
        r_canfdg_mode_transition(p_ctrl, CAN_OPERATION_MODE_GLOBAL_SLEEP);

        /* Stop CANFD module */
        R_BSP_MODULE_STOP(FSP_IP_CANFDG, 0);
    }

    /* Reset global control struct pointer */
    gp_ctrl[p_cfg->channel] = NULL;

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Write data to the CANFDG channel.
 *
 * Example:
 * @snippet r_canfdg_example.c R_CANFDG_Write
 *
 * @retval FSP_SUCCESS                      Operation succeeded.
 * @retval FSP_ERR_NOT_OPEN                 Control block not open.
 * @retval FSP_ERR_CAN_TRANSMIT_NOT_READY   Transmit in progress, cannot write data at this time.
 * @retval FSP_ERR_INVALID_ARGUMENT         Data length or buffer number invalid.
 * @retval FSP_ERR_INVALID_MODE             An FD option was set on a non-FD frame.
 * @retval FSP_ERR_ASSERTION                One or more pointer arguments is NULL.
 * @retval FSP_ERR_UNSUPPORTED              FD is not supported on this MCU.
 *****************************************************************************************************************/
fsp_err_t R_CANFDG_Write (can_ctrl_t * const p_api_ctrl, uint32_t buffer, can_frame_t * const p_frame)
{
#if CANFDG_CFG_PARAM_CHECKING_ENABLE
    canfdg_instance_ctrl_t * p_ctrl = (canfdg_instance_ctrl_t *) p_api_ctrl;

    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_frame);
    FSP_ERROR_RETURN(p_ctrl->open == CANFDG_OPEN, FSP_ERR_NOT_OPEN);

    /* CANFD channels have 16 TX message buffers + 3 common FIFOs each (0-7, 32-39, 40-42) */
    FSP_ERROR_RETURN((buffer <= 7U) ||
                     (buffer - 32U <= 7U) ||
                     (buffer - (uint32_t) CANFDG_TX_BUFFER_FIFO_COMMON_0 <= 2U),
                     FSP_ERR_INVALID_ARGUMENT);

    /* Check DLC field */
 #if BSP_FEATURE_CANFD_FD_SUPPORT
    if (!(p_frame->options & CANFDG_FRAME_OPTION_FD))
    {
        FSP_ERROR_RETURN(p_frame->data_length_code <= 8, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(p_frame->options == 0, FSP_ERR_INVALID_MODE);
    }
    else if (p_frame->data_length_code > 0)
    {
        /* Make sure the supplied data size corresponds to a valid DLC value */
        FSP_ERROR_RETURN(0U != r_canfdg_bytes_to_dlc(p_frame->data_length_code), FSP_ERR_INVALID_ARGUMENT);
    }
    else
    {
        /* Do nothing. */
    }

 #else
    FSP_ERROR_RETURN(p_frame->data_length_code <= 8, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_frame->options == 0, FSP_ERR_UNSUPPORTED);
 #endif
#else
    canfdg_instance_ctrl_t * p_ctrl = (canfdg_instance_ctrl_t *) p_api_ctrl;
#endif

    /* Provide variables to store common values. */
    const bool     is_cfifo           = (bool) (buffer >= (uint32_t) CANFDG_TX_BUFFER_FIFO_COMMON_0);
    const uint32_t interlaced_channel = CANFDG_INTER_CH(p_ctrl->p_cfg->channel);

    const uint32_t id = p_frame->id | ((uint32_t) p_frame->type << R_CANFDG_TMB_HF0_RTR_Pos) |
                        ((uint32_t) p_frame->id_mode << R_CANFDG_TMB_HF0_IDE_Pos);

    uint32_t  buffer_idx = 0;
    uint8_t * p_dest     = NULL;

    if (!is_cfifo)
    {
        /* Calculate global TX message buffer number */
        buffer_idx = buffer + (interlaced_channel * CANFDG_PRV_TXMB_CHANNEL_OFFSET);

        /* Ensure MB is ready */
        FSP_ERROR_RETURN(0U == p_ctrl->p_reg->TMSR_b[buffer_idx].TXRQS, FSP_ERR_CAN_TRANSMIT_NOT_READY);

        /* Set ID */
        p_ctrl->p_reg->TMB[buffer_idx].HF0 = id;
#if BSP_FEATURE_CANFD_FD_SUPPORT

        /* Set DLC */
        p_ctrl->p_reg->TMB[buffer_idx].HF1 = (uint32_t) r_canfdg_bytes_to_dlc(p_frame->data_length_code) <<
                                             R_CANFDG_TMB_HF1_DLC_Pos;

        /* Set FD bits (ESI, BRS and FDF) */
        p_ctrl->p_reg->TMB[buffer_idx].HF2 = p_frame->options & 7U;
#else

        /* Set DLC */
        p_ctrl->p_reg->TMB[buffer_idx].HF1 = (uint32_t) p_frame->data_length_code << R_CANFDG_TMB_HF1_DLC_Pos;
#endif

        /* Store the data pointer. */
        p_dest = (uint8_t *) p_ctrl->p_reg->TMB[buffer_idx].DF;
    }
    else
    {
        /* Calculate the Common FIFO index. */
        buffer_idx = buffer - (uint32_t) CANFDG_TX_BUFFER_FIFO_COMMON_0 +
                     (interlaced_channel * CANFDG_PRV_CFIFO_CHANNEL_OFFSET);

        /* Set ID. */
        p_ctrl->p_reg->CFB[buffer_idx].HF0 = id;

#if BSP_FEATURE_CANFD_FD_SUPPORT

        /* Set DLC. */
        p_ctrl->p_reg->CFB[buffer_idx].HF1 = (uint32_t) r_canfdg_bytes_to_dlc(p_frame->data_length_code) <<
                                             R_CANFDG_CFB_HF1_DLC_Pos;

        /* Set the FD bits (ESI, BRS and FDF). */
        p_ctrl->p_reg->CFB[buffer_idx].HF2 = p_frame->options & 7U;
#else

        /* Set DLC. */
        p_ctrl->p_reg->TMB[buffer_idx].HF1 = (uint32_t) p_frame->data_length_code << R_CANFDG_CFB_HF1_DLC_Pos;
#endif

        /* Store the data poitner. */
        p_dest = (uint8_t *) p_ctrl->p_reg->CFB[buffer_idx].DF;
    }

    /* Copy data to register buffer */
    uint32_t  len   = p_frame->data_length_code;
    uint8_t * p_src = p_frame->data;
    while (len--)
    {
        *p_dest++ = *p_src++;
    }

    if (!is_cfifo)
    {
        /* Request transmission */
        p_ctrl->p_reg->TMCR[buffer_idx] = 1;
    }
    else
    {
        /* Increment the FIFO pointer by writing 0xFF to CFPC. */
        p_ctrl->p_reg->CFPCR[buffer_idx] = R_CANFDG_CFPCR_CFPCR_Msk;
    }

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Read data from a CANFDG Message Buffer or FIFO.
 *
 * Example:
 * snippet r_canfdg_example.c R_CANFDG_Read
 *
 * @retval FSP_SUCCESS                      Operation succeeded.
 * @retval FSP_ERR_NOT_OPEN                 Control block not open.
 * @retval FSP_ERR_INVALID_ARGUMENT         Buffer number invalid.
 * @retval FSP_ERR_ASSERTION                p_api_ctrl or p_frame is NULL.
 * @retval FSP_ERR_BUFFER_EMPTY             Buffer or FIFO is empty.
 *****************************************************************************************************************/
fsp_err_t R_CANFDG_Read (can_ctrl_t * const p_api_ctrl, uint32_t buffer, can_frame_t * const p_frame)
{
    canfdg_instance_ctrl_t * p_ctrl = (canfdg_instance_ctrl_t *) p_api_ctrl;
#if CANFDG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_frame);
    FSP_ERROR_RETURN(p_ctrl->open == CANFDG_OPEN, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((buffer < CANFDG_PRV_RXMB_MAX + CANFDG_PRV_RX_FIFO_MAX) ||
                     ((buffer >= CANFDG_RX_BUFFER_FIFO_COMMON_0) &&
                      (buffer < CANFDG_RX_BUFFER_FIFO_COMMON_0 + CANFDG_PRV_COMMON_FIFO_MAX)),
                     FSP_ERR_INVALID_ARGUMENT);
#endif

    uint32_t not_empty;

    /* Return an error if the buffer or FIFO is empty */
    if (buffer < CANFDG_PRV_RXMB_MAX)
    {
        not_empty = p_ctrl->p_reg->RMNDR & (1U << buffer);
    }
    else if (buffer < (uint32_t) CANFDG_RX_BUFFER_FIFO_COMMON_0)
    {
        not_empty = !(p_ctrl->p_reg->FESR & (1U << (buffer - CANFDG_PRV_RXMB_MAX)));
    }
    else
    {
        /* Common FIFO status are grouped together and not channelized, so calculate the index based on the channel. */
        const uint32_t cfifo_idx = CANFDG_PRV_CFIFO_INDEX(buffer - (uint32_t) CANFDG_RX_BUFFER_FIFO_COMMON_0,
                                                          CANFDG_INTER_CH(p_ctrl->p_cfg->channel));

        /* Update the buffer to be effectively the cfifo index calculated above. */
        /* This is needed since r_canfdg_mb_read(...) doesn't take a channel number. */
        buffer = cfifo_idx + (uint32_t) CANFDG_RX_BUFFER_FIFO_COMMON_0;

        not_empty = (~p_ctrl->p_reg->FESR & (1U << (R_CANFDG_FESR_CFEMP0_Pos + cfifo_idx))) != 0;
    }

    FSP_ERROR_RETURN(not_empty, FSP_ERR_BUFFER_EMPTY);

    /* Retrieve message from buffer */
    r_canfdg_mb_read(p_ctrl->p_reg, buffer, p_frame);

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Switch to a different channel, global or test mode.
 *
 * Example:
 * @snippet r_canfdg_example.c R_CANFDG_ModeTransition
 *
 * @retval FSP_SUCCESS                      Operation succeeded.
 * @retval FSP_ERR_NOT_OPEN                 Control block not open.
 * @retval FSP_ERR_ASSERTION                Null pointer presented
 * @retval FSP_ERR_INVALID_MODE             Cannot change to the requested mode from the current global mode.
 *****************************************************************************************************************/
fsp_err_t R_CANFDG_ModeTransition (can_ctrl_t * const   p_api_ctrl,
                                   can_operation_mode_t operation_mode,
                                   can_test_mode_t      test_mode)
{
    canfdg_instance_ctrl_t * p_ctrl = (canfdg_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t                err    = FSP_SUCCESS;
#if CANFDG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == CANFDG_OPEN, FSP_ERR_NOT_OPEN);

    /* Get Global Status */
    uint32_t cfdgsts = p_ctrl->p_reg->GSR;

    /* Check to ensure the current mode is Global Halt when transitioning into or out of Internal Bus mode */
    FSP_ERROR_RETURN((cfdgsts & R_CANFDG_GSR_HLTST_Msk) || !((p_ctrl->test_mode != test_mode) &&
                                                             ((CAN_TEST_MODE_INTERNAL_BUS == p_ctrl->test_mode) ||
                                                              (CAN_TEST_MODE_INTERNAL_BUS == test_mode))),
                     FSP_ERR_INVALID_MODE);

    /* Check to ensure the current mode is Global Reset when transitioning into or out of Global Sleep (see
     * "Global Modes" in the CANFD 'Operating Mode' section of the relevant hardware manual) */
    FSP_ERROR_RETURN(((cfdgsts & R_CANFDG_GSR_RSTST_Msk) && (CAN_OPERATION_MODE_RESET & operation_mode)) ||
                     (!(cfdgsts & R_CANFDG_GSR_SLPST_Msk) && (CAN_OPERATION_MODE_GLOBAL_SLEEP != operation_mode)),
                     FSP_ERR_INVALID_MODE);

    /* Check to ensure the current Global mode supports the requested Channel mode, if applicable. The requested mode
     * and the current global mode are converted into a number 0-3 corresponding to Operation, Halt, Reset and Sleep
     * respectively. The channel mode cannot be switched to a mode with an index lower than the current global mode. */
    if (operation_mode < CAN_OPERATION_MODE_GLOBAL_OPERATION)
    {
        FSP_ERROR_RETURN(g_mode_order[operation_mode] >= g_mode_order[cfdgsts & CANFDG_PRV_CTR_MODE_MASK],
                         FSP_ERR_INVALID_MODE);
    }
#endif

    uint32_t interlaced_channel = CANFDG_INTER_CH(p_ctrl->p_cfg->channel);

    if (p_ctrl->test_mode != test_mode)
    {
        /* Follow the procedure for switching to Internal Bus mode given in "Internal CAN Bus
         * Communication Test Mode" in the CANFD section of the relevant hardware manual. */
        if (CAN_TEST_MODE_INTERNAL_BUS == test_mode)
        {
            /* Disable channel test mode */
            p_ctrl->p_reg->CFDC[interlaced_channel].CHCR_b.CTME = 0;

            /* Link channel to internal bus */
            p_ctrl->p_reg->GTMCR |= 1U << interlaced_channel;

            /* Enable internal bus test mode */
            p_ctrl->p_reg->GTMER = 1;
        }
        else
        {
            if (p_ctrl->test_mode == CAN_TEST_MODE_INTERNAL_BUS)
            {
                /* Unlink channel from internal bus */
                p_ctrl->p_reg->GTMCR &= ~(1U << interlaced_channel);

                /* Disable global test mode if no channels are linked */
                if (!p_ctrl->p_reg->GTMCR)
                {
                    p_ctrl->p_reg->GTMER = 0;
                }
            }

            /* Transition to Channel Halt when changing test modes */
            r_canfdg_mode_transition(p_ctrl, CAN_OPERATION_MODE_HALT);

            /* Set channel test mode */
            uint32_t chcr = p_ctrl->p_reg->CFDC[interlaced_channel].CHCR;
            chcr &= ~(R_CANFDG_CFDC_CHCR_CTME_Msk | R_CANFDG_CFDC_CHCR_CTMS_Msk);
            p_ctrl->p_reg->CFDC[interlaced_channel].CHCR = chcr |
                                                           ((uint32_t) test_mode << R_CANFDG_CFDC_CHCR_CTME_Pos);
        }

        p_ctrl->test_mode = test_mode;
    }

    if (p_ctrl->operation_mode != operation_mode)
    {
        r_canfdg_mode_transition(p_ctrl, operation_mode);
    }

    return err;
}

/***************************************************************************************************************//**
 * Get CANFDG state and status information for the channel.
 *
 * @retval  FSP_SUCCESS                     Operation succeeded.
 * @retval  FSP_ERR_NOT_OPEN                Control block not open.
 * @retval  FSP_ERR_ASSERTION               Null pointer presented
 *****************************************************************************************************************/
fsp_err_t R_CANFDG_InfoGet (can_ctrl_t * const p_api_ctrl, can_info_t * const p_info)
{
#if CANFDG_CFG_PARAM_CHECKING_ENABLE
    canfdg_instance_ctrl_t * p_ctrl = (canfdg_instance_ctrl_t *) p_api_ctrl;

    /* Check pointers for NULL values */
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_info);

    /* If channel is not open, return an error */
    FSP_ERROR_RETURN(p_ctrl->open == CANFDG_OPEN, FSP_ERR_NOT_OPEN);
#else
    canfdg_instance_ctrl_t * p_ctrl = (canfdg_instance_ctrl_t *) p_api_ctrl;
#endif

    uint32_t interlaced_channel = CANFDG_INTER_CH(p_ctrl->p_cfg->channel);

    uint32_t cfdcnsts = p_ctrl->p_reg->CFDC[interlaced_channel].CHSR;
    p_info->status               = cfdcnsts & UINT16_MAX;
    p_info->error_count_receive  = (uint8_t) ((cfdcnsts & R_CANFDG_CFDC_CHSR_REC_Msk) >> R_CANFDG_CFDC_CHSR_REC_Pos);
    p_info->error_count_transmit = (uint8_t) ((cfdcnsts & R_CANFDG_CFDC_CHSR_TEC_Msk) >> R_CANFDG_CFDC_CHSR_TEC_Pos);
    p_info->error_code           = p_ctrl->p_reg->CFDC[interlaced_channel].CHESR & UINT16_MAX;
    p_info->rx_mb_status         = p_ctrl->p_reg->RMNDR;
    p_info->rx_fifo_status       = (~p_ctrl->p_reg->FESR) &
                                   (CANFDG_PRV_FESR_RFEMPX_MASK | CANFDG_PRV_FESR_CFEMPX_MASK);

    /* Clear error flags if the error IRQ is not enabled. */
    if (p_ctrl->p_cfg->error_irq < 0)
    {
        p_ctrl->p_reg->CFDC[interlaced_channel].CHESR = 0;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref can_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_CANFDG_CallbackSet (can_ctrl_t * const          p_api_ctrl,
                                void (                    * p_callback)(can_callback_args_t *),
                                void * const                p_context,
                                can_callback_args_t * const p_callback_memory)
{
    canfdg_instance_ctrl_t * p_ctrl = (canfdg_instance_ctrl_t *) p_api_ctrl;

#if CANFDG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(CANFDG_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_ctrl->p_callback        = p_callback;
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup CAN)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
#if CANFDG_CFG_PARAM_CHECKING_ENABLE
static bool r_canfdg_bit_timing_parameter_check (can_bit_timing_cfg_t * const p_bit_timing, bool is_data_phase)
{
    /* Check that prescaler is in range */
    FSP_ERROR_RETURN((p_bit_timing->baud_rate_prescaler <= CANFDG_BAUD_RATE_PRESCALER_MAX) &&
                     (p_bit_timing->baud_rate_prescaler >= CANFDG_BAUD_RATE_PRESCALER_MIN),
                     false);

    /* Check that TSEG1 > TSEG2 >= SJW for nominal bitrate and that TSEG1 >= TSEG2 >= SJW for data bitrate per section
     * "Bit Timing Conditions" in the CANFD section of the relevant hardware manual.. */

 #if BSP_FEATURE_CANFD_FD_SUPPORT
    if (is_data_phase)
    {
        /* Check Time Segment 1 is greater than or equal to Time Segment 2 */
        FSP_ERROR_RETURN((uint32_t) p_bit_timing->time_segment_1 >= (uint32_t) p_bit_timing->time_segment_2, false);
    }
    else
 #else

    /* Data phase is only available for FD mode. */
    FSP_PARAMETER_NOT_USED(is_data_phase);
 #endif
    {
        /* Check Time Segment 1 is greater than Time Segment 2 */
        FSP_ERROR_RETURN((uint32_t) p_bit_timing->time_segment_1 > (uint32_t) p_bit_timing->time_segment_2, false);
    }

    /* Check Time Segment 2 is greater than or equal to the synchronization jump width */
    FSP_ERROR_RETURN((uint32_t) p_bit_timing->time_segment_2 >= (uint32_t) p_bit_timing->synchronization_jump_width,
                     false);

    return true;
}

#endif

/*******************************************************************************************************************//**
 * Read from a Message Buffer or FIFO.
 *
 * NOTE: Does not index FIFOs.
 *
 * @param[in]     p_reg      Pointer to the CANFD registers
 * @param[in]     buffer     Index of buffer to read from (MBs 0-31, FIFOs 32+)
 * @param[in]     frame      Pointer to CAN frame to write to
 **********************************************************************************************************************/
static void r_canfdg_mb_read (R_CANFDG_Type * p_reg, uint32_t buffer, can_frame_t * const frame)
{
    const bool is_mb    = (bool) (buffer < CANFDG_PRV_RXMB_MAX);
    const bool is_cfifo = (bool) (buffer >= (uint32_t) CANFDG_RX_BUFFER_FIFO_COMMON_0);

    /* Get pointer to message buffer (FIFOs use the same buffer structure) */
    volatile R_CANFDG_CFDRM_RM_TYPE * mb_regs;
    if (is_mb)
    {
        mb_regs = CANFDG_PRV_RXMB_PTR(buffer);
    }
    else if (is_cfifo)
    {
        mb_regs = (volatile R_CANFDG_CFDRM_RM_TYPE *) &(p_reg->CFB[buffer - (uint32_t) CANFDG_RX_BUFFER_FIFO_COMMON_0]);
    }
    else
    {
        mb_regs = (volatile R_CANFDG_CFDRM_RM_TYPE *) &(p_reg->RFB[buffer - CANFDG_PRV_RXMB_MAX]);
    }

    /* Get frame data. */
    uint32_t id = mb_regs->HF0;

    /* Get the frame type */
    frame->type = (can_frame_type_t) ((id & CANFDG_PRV_RMRTR_MASK) >> CANFDG_PRV_RMRTR_POSITION);

#if BSP_FEATURE_CANFD_FD_SUPPORT

    /* Get FD status bits (ESI, BRS and FDF) */
    frame->options = mb_regs->HF2 & 7U;
#else
    frame->options = 0U;
#endif

    /* Get the frame ID */
    frame->id = id & CANFDG_PRV_RMID_MASK;

    /* Get the frame ID mode (IDE bit) */
    frame->id_mode = (can_id_mode_t) (id >> CANFDG_PRV_RMIDE_POSITION);

    /* Get the frame data length code */
    frame->data_length_code = dlc_to_bytes[mb_regs->HF1 >> CANFDG_PRV_RMDLC_POSITION];

    /* Copy data to frame */
    uint32_t  len    = frame->data_length_code;
    uint8_t * p_dest = frame->data;
    uint8_t * p_src  = (uint8_t *) mb_regs->DF;
    while (len--)
    {
        *p_dest++ = *p_src++;
    }

    if (is_mb)
    {
        /* Clear RXMB New Data bit */
        p_reg->RMNDR &= ~(1U << buffer);
    }
    else if (is_cfifo)
    {
        /* Increment the Common FIFO pointer. */
        p_reg->CFPCR[buffer - (uint32_t) CANFDG_RX_BUFFER_FIFO_COMMON_0] = R_CANFDG_CFPCR_CFPCR_Msk;
    }
    else
    {
        /* Increment RX FIFO pointer */
        p_reg->RFPCR[buffer - CANFDG_PRV_RXMB_MAX] = UINT8_MAX;
    }
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to CAN instance control block
 * @param[in]     p_args     Pointer to arguments on stack
 **********************************************************************************************************************/
static void r_canfdg_call_callback (canfdg_instance_ctrl_t * p_ctrl, can_callback_args_t * p_args)
{
    can_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    can_callback_args_t * p_args_memory = p_ctrl->p_callback_memory;
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

    /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
    p_ctrl->p_callback(p_args_memory);

    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * Global Error Handler.
 *
 * Handles the Global Error IRQ for a given instance of CANFD.
 **********************************************************************************************************************/
static void r_canfdg_global_error_handler (uint32_t instance)
{
    canfdg_instance_ctrl_t * p_ctrl = gp_ctrl[instance];

    can_callback_args_t args = {0U};

    args.event = CAN_EVENT_ERR_GLOBAL;

    /* Read global error flags. */
    uint32_t cfdgerfl = p_ctrl->p_reg->GESR;

    /* Global errors are in the top halfword of canfd_error_t; move and preserve ECC error flags. */
    args.error = ((cfdgerfl & UINT16_MAX) << 16) + ((cfdgerfl >> 16) << 28);

    /* Clear global error flags. */
    p_ctrl->p_reg->GESR = 0;

    if (args.error & CANFDG_ERROR_GLOBAL_MESSAGE_LOST)
    {
        /* Get lowest RX FIFO with Message Lost condition and clear the flag */
        args.mb_u.buffer = r_canfdg_count_leading_zeros(r_canfdg_reverse_bit_order(p_ctrl->p_reg->FMLSR));
        if (args.mb_u.buffer < CANFDG_PRV_RX_FIFO_MAX)
        {
            p_ctrl->p_reg->RFSR[args.mb_u.buffer] &= ~R_CANFDG_RFSR_LOST_Msk;
        }
        else
        {
            p_ctrl->p_reg->CFSR[args.mb_u.buffer - R_CANFDG_FMLSR_CFML0_Pos] &= ~R_CANFDG_CFSR_LOST_Msk;
        }
    }

    /* Set channel and context based on selected global error handler channel. */
    args.channel   = CANFDG_CFG_GLOBAL_ERROR_CH;
    args.p_context = p_ctrl->p_context;

    /* Set remaining arguments and call callback */
    r_canfdg_call_callback(p_ctrl, &args);
}

/*******************************************************************************************************************//**
 * Error ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common error function, and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfdg_error_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    /* Get IRQ and context */
    IRQn_Type irq = R_FSP_CurrentIrqGet();

    if (VECTOR_NUMBER_CANFDG0_GLEI == irq)
    {
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1

        /* If there are seperate instances of CANFD, then loop over each instance to handle the source of the global
         * error IRQ. */
        for (uint32_t i = 0; i < BSP_FEATURE_CANFD_NUM_INSTANCES; i++)
        {
            if (NULL != gp_ctrl[i])
            {
                r_canfdg_global_error_handler(i);
            }
        }

#else
        r_canfdg_global_error_handler(CANFDG_CFG_GLOBAL_ERROR_CH);
#endif
    }
    else
    {
        canfdg_instance_ctrl_t * p_ctrl = (canfdg_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

        can_callback_args_t      args = {0U};
        canfdg_instance_ctrl_t * p_callback_ctrl;

        args.event = CAN_EVENT_ERR_CHANNEL;

        /* Read and clear channel error flags. */
        uint32_t interlaced_channel = CANFDG_INTER_CH(p_ctrl->p_cfg->channel);
        args.error = p_ctrl->p_reg->CFDC[interlaced_channel].CHESR & UINT16_MAX; // Upper halfword contains latest CRC
        p_ctrl->p_reg->CFDC[interlaced_channel].CHESR = 0;

        /* Choose the channel provided by the interrupt context. */
        p_callback_ctrl = p_ctrl;

        args.channel     = interlaced_channel;
        args.p_context   = p_ctrl->p_context;
        args.mb_u.buffer = 0U;

        /* Set remaining arguments and call callback */
        r_canfdg_call_callback(p_callback_ctrl, &args);
    }

    /* Clear IRQ */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * Receive FIFO handler.
 *
 * Handles the Receive IRQ for a given instance of CANFD.
 **********************************************************************************************************************/
static void r_canfdg_rx_fifo_handler (uint32_t instance)
{
    can_callback_args_t args;
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
    R_CANFDG_Type * p_reg =
        (R_CANFDG_Type *) ((uint32_t) R_CANFDG0 + (instance * ((uint32_t) R_CANFDG1 - (uint32_t) R_CANFDG0)));
#else
    FSP_PARAMETER_NOT_USED(instance);
    R_CANFDG_Type * p_reg = R_CANFDG;
#endif

    /* Get lowest FIFO requesting interrupt */
    uint32_t fifo = r_canfdg_count_leading_zeros(r_canfdg_reverse_bit_order(p_reg->RFISR));

    /* Only perform ISR duties if a FIFO has requested it */
    if (fifo < CANFDG_PRV_RX_FIFO_MAX)
    {
        /* Set static arguments */
        args.event       = CAN_EVENT_RX_COMPLETE;
        args.mb_u.buffer = fifo + CANFDG_PRV_RXMB_MAX;

        /* Read from the FIFO until it is empty */
        while (!(p_reg->FESR & (1U << fifo)))
        {
            /* Get channel associated with the AFL entry */
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
            args.channel = instance;
#else
            args.channel = p_reg->RFB[fifo].HF2_b.IFL;
#endif

            /* Read and index FIFO */
            r_canfdg_mb_read(p_reg, fifo + CANFDG_PRV_RXMB_MAX, &args.frame);

            /* Set the remaining callback arguments */
            args.p_context = gp_ctrl[args.channel]->p_context;
            r_canfdg_call_callback(gp_ctrl[args.channel], &args);
        }

        /* Clear RX FIFO Interrupt Flag */
        p_reg->RFSR[fifo] &= ~R_CANFDG_RFSR_RFIF_Msk;
    }

    if (!p_reg->RFISR)
    {
        /* Clear interrupt in NVIC if there are no pending RX FIFO IRQs */
        R_BSP_IrqStatusClear(VECTOR_NUMBER_CANFDG0_RFRI);
    }
}

/*******************************************************************************************************************//**
 * Receive ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common receive function
 * and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfdg_rx_fifo_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1

    /* If there are separate instances of CANFD, then loop over each instance to handle the source of the global
     * receive IRQ. */
    for (uint32_t i = 0; i < BSP_FEATURE_CANFDG_NUM_INSTANCES; i++)
    {
        if (NULL != gp_ctrl[i])
        {
            r_canfdg_rx_fifo_handler(i);
        }
    }

#else
    r_canfdg_rx_fifo_handler(0U);
#endif

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * Transmit ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common transmit function
 * and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfdg_channel_tx_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type                irq      = R_FSP_CurrentIrqGet();
    canfdg_instance_ctrl_t * p_ctrl   = (canfdg_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    canfdg_extended_cfg_t  * p_extend = (canfdg_extended_cfg_t *) p_ctrl->p_cfg->p_extend;
    uint32_t                 channel  = p_ctrl->p_cfg->channel;

    /* Set static arguments */
    can_callback_args_t args;
    args.channel   = channel;
    args.p_context = p_ctrl->p_context;

    uint32_t interlaced_channel = CANFDG_INTER_CH(channel);

    /* Check the byte of TISR that corresponds to the interrupting channel */
    volatile uint8_t * p_tisr = (((volatile uint8_t *) &p_ctrl->p_reg->TISR) + interlaced_channel);
    while (*p_tisr)
    {
        bool                is_cfifo = false;
        uint32_t            txmb;
        volatile uint32_t * p_cfdtm_sts;
        const uint32_t      tisr = *p_tisr;

        interlaced_channel <<= 1;

        /* Get relevant TX status register bank */
        if (tisr & R_CANFDG_TISR_TSIF0_Msk)
        {
            p_cfdtm_sts = (volatile uint32_t *) &p_ctrl->p_reg->TMTCSR[interlaced_channel];
            args.event  = CAN_EVENT_TX_COMPLETE;
        }
        else if (tisr & R_CANFDG_TISR_CFTIF0_Msk)
        {
            is_cfifo    = true;
            p_cfdtm_sts = &p_ctrl->p_reg->CFTISR;
            args.event  = (p_extend->p_global_cfg->common_fifo_config[interlaced_channel] & R_CANFDG_CFCR_CFIM_Msk) ?
                          CAN_EVENT_TX_COMPLETE : CAN_EVENT_TX_FIFO_EMPTY;
        }
        else
        {
            p_cfdtm_sts = (volatile uint32_t *) &p_ctrl->p_reg->TMTASR[interlaced_channel];
            args.event  = CAN_EVENT_TX_ABORTED;
        }

        interlaced_channel >>= 1;

        /* Calculate lowest TXMB with the specified event */
        if (!is_cfifo)
        {
            txmb = r_canfdg_count_leading_zeros(r_canfdg_reverse_bit_order(*p_cfdtm_sts));
            txmb =
                (txmb <
                 8) ? txmb : r_canfdg_count_leading_zeros(r_canfdg_reverse_bit_order(*(p_cfdtm_sts + 1))) +
                CANFDG_PRV_TXMB_OFFSET;

            /* Clear TX complete/abort flags */
            p_ctrl->p_reg->TMSR_b[txmb + (CANFDG_PRV_TXMB_CHANNEL_OFFSET * interlaced_channel)].TXRF = 0;
        }
        else
        {
            /* Adjust txmb with the lowest indexed Common FIFO that could have triggered this event.
             * Mask out only the Common FIFOs associated with this channel. */
            uint32_t cfdtm_mask = ((1U << CANFDG_PRV_COMMON_FIFO_MAX) - 1U) <<
                                  (interlaced_channel * CANFDG_PRV_COMMON_FIFO_MAX);
            txmb = r_canfdg_count_leading_zeros(r_canfdg_reverse_bit_order(*p_cfdtm_sts & cfdtm_mask));

            /* Clear the interrupt flag for Common FIFO TX. */
            p_ctrl->p_reg->CFSR[txmb] &= ~R_CANFDG_CFSR_CFTIF_Msk;

            /* Add the Common FIFO offset so the correct type of buffer will be available in the callback. */
            txmb += CANFDG_TX_BUFFER_FIFO_COMMON_0;
        }

        /* Set the callback arguments */
        args.mb_u.buffer = txmb;
        r_canfdg_call_callback(p_ctrl, &args);
    }

    /* Clear interrupt */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * Common FIFO Receive ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common receive function
 * and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfdg_common_fifo_rx_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type                irq     = R_FSP_CurrentIrqGet();
    canfdg_instance_ctrl_t * p_ctrl  = (canfdg_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    uint32_t                 channel = p_ctrl->p_cfg->channel;
    can_callback_args_t      args;

    /* Get lowest FIFO requesting interrupt */

    /* To satisfy clang-tidy mask out the index. A value of 32 only happens if no flag is set which shouldn't happen in
     * this ISR. If it does for some reason, the while loop below will be bypassed since the associated flag being
     * checked will be ignored. */
    uint32_t fifo = r_canfdg_count_leading_zeros(r_canfdg_reverse_bit_order(p_ctrl->p_reg->CFRISR &
                                                                            CANFDG_PRV_CFRISRF_Msk)) & 0x1FU;

    /* Set static arguments */
    args.event   = CAN_EVENT_RX_COMPLETE;
    args.channel = channel;

#if BSP_FEATURE_CANFDG_NUM_CHANNELS > 1

    /* Get the channel based fifo index to get the currect buffer value. */
    if (fifo > CANFDG_PRV_CFIFO_CHANNEL_OFFSET)
    {
        args.mb_u.buffer = fifo % (CANFDG_PRV_CFIFO_CHANNEL_OFFSET + 1);
    }
    else
    {
        args.mb_u.buffer = fifo;
    }

#else
    args.mb_u.buffer = fifo;
#endif

    /* Move buffer up to the correct range. */
    args.mb_u.buffer += (uint32_t) CANFDG_RX_BUFFER_FIFO_COMMON_0;

    /* Read from the FIFO until it is empty */
    while (!(p_ctrl->p_reg->FESR & (1U << (R_CANFDG_FESR_CFEMP0_Pos + fifo))))
    {
        /* Read and index FIFO */
        /* buffer is slightly different in this function since it operates globally. */
        r_canfdg_mb_read(p_ctrl->p_reg, fifo + (uint32_t) CANFDG_RX_BUFFER_FIFO_COMMON_0, &args.frame);

        /* Set the remaining callback arguments */
        args.p_context = gp_ctrl[args.channel]->p_context;
        r_canfdg_call_callback(gp_ctrl[args.channel], &args);
    }

    /* Clear Common FIFO RX Interrupt Flag */
    p_ctrl->p_reg->CFSR[fifo] &= ~R_CANFDG_CFSR_CFRIF_Msk;

    if (!p_ctrl->p_reg->CFRISR)
    {
        /* Clear interrupt in NVIC if there are no pending RX FIFO IRQs */
        R_BSP_IrqStatusClear(irq);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * This function is used to switch the CANFDG peripheral operation mode.
 * @param[in]  p_ctrl            - pointer to control structure
 * @param[in]  operation_mode    - destination operation mode
 **********************************************************************************************************************/
static void r_canfdg_mode_transition (canfdg_instance_ctrl_t * p_ctrl, can_operation_mode_t operation_mode)
{
    uint32_t interlaced_channel = CANFDG_INTER_CH(p_ctrl->p_cfg->channel);

    /* Get bit 7 from operation_mode to determine if this is a global mode change request */
    bool global_mode = (bool) (operation_mode >> 7);
    operation_mode &= 0xF;

    if (global_mode)
    {
        uint32_t cfdgctr = p_ctrl->p_reg->GCR;

        /* If CANFD is transitioning to Global Reset, make sure the FIFOs are disabled. */
        if (!(cfdgctr & R_CANFDG_GSR_RSTST_Msk) && (operation_mode & CAN_OPERATION_MODE_RESET))
        {
            /* Disable RX FIFOs */
            for (uint32_t i = 0; i < CANFDG_PRV_RX_FIFO_MAX; i++)
            {
                p_ctrl->p_reg->RFCR[i] &= ~R_CANFDG_RFCR_RFE_Msk;
            }

            /* Disable Common FIFOs */
            for (uint32_t i = 0; i < CANFDG_PRV_COMMON_FIFO_MAX * BSP_FEATURE_CANFDG_NUM_CHANNELS; i++)
            {
                p_ctrl->p_reg->CFCR[i] &= ~R_CANFDG_CFCR_CFE_Msk;
            }
        }

        r_canfdg_mode_ctr_set(&p_ctrl->p_reg->GCR, operation_mode);

        /* If CANFD is transitioning out of Reset the FIFOs need to be enabled. */
        if ((cfdgctr & R_CANFDG_GSR_RSTST_Msk) && !(operation_mode & CAN_OPERATION_MODE_RESET))
        {
            /* Get global config */
            canfdg_global_cfg_t * p_global_cfg =
                ((canfdg_extended_cfg_t *) p_ctrl->p_cfg->p_extend)->p_global_cfg;

            /* Enable RX FIFOs */
            for (uint32_t i = 0; i < CANFDG_PRV_RX_FIFO_MAX; i++)
            {
                p_ctrl->p_reg->RFCR[i] = p_global_cfg->rx_fifo_config[i];
            }
        }
    }
    else
    {
        uint32_t chcr = p_ctrl->p_reg->CFDC[interlaced_channel].CHCR;

        if (((chcr & R_CANFDG_CFDC_CHCR_SLPRQ_Msk) && (!(CAN_OPERATION_MODE_RESET & operation_mode))) ||
            ((!(chcr & CANFDG_PRV_CTR_RESET_BIT)) && (CAN_OPERATION_MODE_SLEEP == operation_mode)))
        {
            /* Transition channel to Reset if a transition to/from Sleep is requested (see "Channel
             * Modes" in the CANFD section of the relevant hardware manual) */
            r_canfdg_mode_ctr_set(&p_ctrl->p_reg->CFDC[interlaced_channel].CHCR, CAN_OPERATION_MODE_RESET);
        }

        /* Request transition to selected mode */
        r_canfdg_mode_ctr_set(&p_ctrl->p_reg->CFDC[interlaced_channel].CHCR, operation_mode);

        /* If CANFD is transitioning from Reset, make sure the Common FIFOs are enabled.
         * The FIFOs will be disabled automatically if configured for TX and the channel is transitioned to reset. */
        if ((chcr & R_CANFDG_CFDC_CHCR_MDC_Msk) && !(operation_mode & CAN_OPERATION_MODE_RESET))
        {
            /* Get global config */
            canfdg_global_cfg_t * p_global_cfg =
                ((canfdg_extended_cfg_t *) p_ctrl->p_cfg->p_extend)->p_global_cfg;

            const uint32_t ch_offset = interlaced_channel * CANFDG_PRV_COMMON_FIFO_MAX;

            /* Enable Common FIFOs */
            for (uint32_t i = 0; i < CANFDG_PRV_COMMON_FIFO_MAX; i++)
            {
                p_ctrl->p_reg->CFCR[ch_offset + i] |=
                    (p_global_cfg->common_fifo_config[ch_offset + i] & R_CANFDG_CFCR_CFE_Msk);
            }
        }
    }

    p_ctrl->operation_mode =
        (can_operation_mode_t) (p_ctrl->p_reg->CFDC[interlaced_channel].CHCR & CANFDG_PRV_CTR_MODE_MASK);
}

/*******************************************************************************************************************//**
 * Sets the provided CTR register to the requested mode and waits for the associated STS register to reflect the change
 * @param[in]  p_ctr_reg            - pointer to control register
 * @param[in]  operation_mode       - requested mode (not including global bits)
 **********************************************************************************************************************/
static void r_canfdg_mode_ctr_set (volatile uint32_t * p_ctr_reg, can_operation_mode_t operation_mode)
{
    volatile uint32_t * p_sts_reg = p_ctr_reg + 1;

    /* See definitions for CFDCnCTR, CFDCnSTS, GCR and GSR in the CANFD section of the relevant hardware manual */
    *p_ctr_reg = (*p_ctr_reg & ~CANFDG_PRV_CTR_MODE_MASK) | operation_mode;
    FSP_HARDWARE_REGISTER_WAIT((*p_sts_reg & CANFDG_PRV_CTR_MODE_MASK), operation_mode);
}

#if BSP_FEATURE_CANFD_FD_SUPPORT

/*******************************************************************************************************************//**
 * Converts bytes into a DLC value
 * @param[in]  bytes       Number of payload bytes
 **********************************************************************************************************************/
static uint8_t r_canfdg_bytes_to_dlc (uint8_t bytes)
{
    if (bytes <= 8)
    {
        return bytes;
    }

    if (bytes <= 24)
    {
        return (uint8_t) (8U + ((bytes - 8U) / 4U));
    }

    return (uint8_t) (0xDU + ((bytes / 16U) - 2U));
}

#endif

/*******************************************************************************************************************//**
 * Returns the reverse bits of val.
 *
 * @param[in]  val  scan mask of active channels retrieved from the control structure
 *
 * @retval  reverse_val  reverse bits of val
 **********************************************************************************************************************/
static uint32_t r_canfdg_reverse_bit_order (uint32_t val)
{
    /* Initialize the reverse mask result */
    uint32_t reverse_val = 0U;
    uint8_t  index;

    for (index = 0U; index < CANFDG_WORD_DATA_BITS_LENGTH; index++)
    {
        reverse_val |= ((val >> index) & 1U) << (31U - index);
    }

    return reverse_val;
}

/*******************************************************************************************************************//**
 * Counts the leading zeros of val.
 *
 * @param[in]  val  Number to be counted leading zeros
 *
 * @retval  leading_zeros_count  reverse bits of val
 **********************************************************************************************************************/
static uint8_t r_canfdg_count_leading_zeros (uint32_t val)
{
    uint8_t leading_zeros_count = 0;

    if (val != 0)
    {
        while ((val & CANFDG_PRV_BIT_MASK_VALUE) == 0)
        {
            leading_zeros_count++;
            val <<= 1;
        }
    }
    else
    {
        leading_zeros_count = CANFDG_WORD_DATA_BITS_LENGTH;
    }

    return leading_zeros_count;
}
