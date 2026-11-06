/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_qos.h"                   /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */

#if (BSP_FEATURE_QOS_IS_AVAILABLE)

/***********************************************************************************************************************
 * Variables and functions
 **********************************************************************************************************************/

const IRQn_Type bsp_qos_irq_num_lookup[BSP_QOS_IRQ_NUM_TOTAL] = /* PRQA S 3408, 1514 # DP_MSR_R-8.4_UC1, Advisory R-8.7 & Advisory R-8.9 */
{
    INTQOS0_0_IRQn,                                             /* PRQA S 4332 # Advisory R-10.5 */
    INTQOS1_0_IRQn,                                             /* PRQA S 4332 # Advisory R-10.5 */
    INTQOS2_0_IRQn,                                             /* PRQA S 4332 # Advisory R-10.5 */
    INTQOS3_0_IRQn,                                             /* PRQA S 4332 # Advisory R-10.5 */
    INTQOS4_0_IRQn,                                             /* PRQA S 4332 # Advisory R-10.5 */
    INTQOS5_0_IRQn,                                             /* PRQA S 4332 # Advisory R-10.5 */
    INTQOS6_0_IRQn,                                             /* PRQA S 4332 # Advisory R-10.5 */
    INTQOS7_0_IRQn                                              /* PRQA S 4332 # Advisory R-10.5 */
};

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_QOS
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/*******************************************************************************************************************//**
 * This function enables all the QoS configurations which are Configured in MDF.
 *
 * @retval  None
 **********************************************************************************************************************/
void R_BSP_QoSEnableAll (void)
{
    uint8_t unit_idx;

    for (unit_idx = 0U; unit_idx < (uint8_t) BSP_QOS_UNIT_NUM; unit_idx++)
    {
        R_BSP_QoSBandwidthRegulatorEnable(&g_qos_config_table[unit_idx].bandwidth_regulator_cfg); /* PRQA S 3200 # DP_MSR_R-17.7_UC1 */
        R_BSP_QoSLatencyMonitorEnable(&g_qos_config_table[unit_idx].latency_monitor_cfg);         /* PRQA S 3200 # DP_MSR_R-17.7_UC1 */
    }
}

/*******************************************************************************************************************//**
 * This function disables all the QoS configurations.
 *
 * @retval  None
 **********************************************************************************************************************/
void R_BSP_QoSDisableAll (void)        /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    uint8_t unit_idx;

    for (unit_idx = 0U; unit_idx < (uint8_t) BSP_QOS_UNIT_NUM; unit_idx++)
    {
        R_BSP_QoSBandwidthRegulatorDisable((bsp_qos_unit_t) unit_idx); /* PRQA S 4342 # Advisory R-10.5 */
        R_BSP_QoSLatencyMonitorDisable((bsp_qos_unit_t) unit_idx,      /* PRQA S 4342 # Advisory R-10.5 */
                                       g_qos_config_table[unit_idx].latency_monitor_cfg.channel);
    }
}

/*******************************************************************************************************************//**
 * This function enables the Bandwidth Regulator feature with user input configuration.
 *
 * @param[in]  p_cfg                 Pointer to Bandwidth Regulator configuration structure.
 *
 * @retval  FSP_SUCCESS              Configure Bandwidth Regulator successfully.
 * @retval  FSP_ERR_ASSERTION        A critical assertion has failed.
 **********************************************************************************************************************/
fsp_err_t R_BSP_QoSBandwidthRegulatorEnable (const bsp_bandwidth_regulator_cfg_t * p_cfg) /* PRQA S 1505 # Advisory R-8.7 */
{
    fsp_err_t err = FSP_SUCCESS;
    volatile R_QOSCNT_FL_PE0CL0_Type * p_qos_reg;

    FSP_ASSERT(p_cfg);
    FSP_ASSERT((uint8_t) (p_cfg->unit) < (uint8_t) (BSP_QOS_UNIT_NUM));
    FSP_ASSERT((p_cfg->read_access != BSP_QOS_RW_THRESHOLD_FORBID_1) && \
               (p_cfg->read_access != BSP_QOS_RW_THRESHOLD_FORBID_2));
    FSP_ASSERT((p_cfg->write_access != BSP_QOS_RW_THRESHOLD_FORBID_1) && \
               (p_cfg->write_access != BSP_QOS_RW_THRESHOLD_FORBID_2));

    p_qos_reg = g_qos_info_table[(uint8_t) (p_cfg->unit)];

    /* Set period for Bandwidth Regulator */
    p_qos_reg->BR_PERIOD = p_cfg->period;                            /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(p_cfg->period, p_qos_reg->BR_PERIOD); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Clear total read access and write access */
    p_qos_reg->BR_ACCNTCLR_b.CLRTW = 1U;                             /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(0U, p_qos_reg->BR_ACCNTTOTAL_W);      /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    p_qos_reg->BR_ACCNTCLR_b.CLRTR = 1U;                             /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(0U, p_qos_reg->BR_ACCNTTOTAL_R);      /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    if (BSP_BANDWIDTH_REGULATOR_MODE_THRESHOLD == p_cfg->mode)
    {
        /* Set number of read / write access */
        p_qos_reg->BR_ACCNTTH_R = p_cfg->read_access;                                                                    /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
        FSP_HARDWARE_REGISTER_WAIT(p_qos_reg->BR_ACCNTTH_R, p_cfg->read_access);                                         /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        p_qos_reg->BR_ACCNTTH_W = p_cfg->write_access;                                                                   /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
        FSP_HARDWARE_REGISTER_WAIT(p_qos_reg->BR_ACCNTTH_W, p_cfg->write_access);                                        /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Clear min/max read access and min/max write access */
        p_qos_reg->BR_ACCNTCLR_b.CLRMW = 1U;                                                                             /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
        FSP_HARDWARE_REGISTER_WAIT((uint16_t) (BSP_QOS_MAX_ACCESS_COUNT_DEFAULT_VALUE), p_qos_reg->BR_ACCNTMAX_W_b.CNT); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
        FSP_HARDWARE_REGISTER_WAIT((uint16_t) (BSP_QOS_MIN_ACCESS_COUNT_DEFAULT_VALUE), p_qos_reg->BR_ACCNTMIN_W_b.CNT); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        p_qos_reg->BR_ACCNTCLR_b.CLRMR = 1U;                                                                             /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
        FSP_HARDWARE_REGISTER_WAIT((uint16_t) (BSP_QOS_MAX_ACCESS_COUNT_DEFAULT_VALUE), p_qos_reg->BR_ACCNTMAX_R_b.CNT); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
        FSP_HARDWARE_REGISTER_WAIT((uint16_t) (BSP_QOS_MIN_ACCESS_COUNT_DEFAULT_VALUE), p_qos_reg->BR_ACCNTMIN_R_b.CNT); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }

    /* Set mode */
    p_qos_reg->BR_MODE = (uint8_t) p_cfg->mode;                                                                          /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(p_qos_reg->BR_MODE, (uint8_t) p_cfg->mode);                                               /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    return err;
}

/*******************************************************************************************************************//**
 * This function disables the Bandwidth Regulator feature.
 *
 * @param[in]  unit          QoS unit that need to be disabled.
 *
 * @retval     None
 **********************************************************************************************************************/
void R_BSP_QoSBandwidthRegulatorDisable (bsp_qos_unit_t unit)                                                        /* PRQA S 1505 # Advisory R-8.7 */
{
    volatile R_QOSCNT_FL_PE0CL0_Type * p_qos_reg = g_qos_info_table[unit];
    p_qos_reg->BR_MODE = 0U;                                                                                         /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(p_qos_reg->BR_MODE, 0U);                                                              /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * This function returns total read access of a specific QoS unit.
 *
 * @param[in]  unit          QoS unit
 *
 * @retval     Total read access of the unit.
 **********************************************************************************************************************/
uint16_t R_BSP_QoSTotalReadAccessGet (bsp_qos_unit_t unit)                                                           /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    volatile R_QOSCNT_FL_PE0CL0_Type * p_qos_reg = g_qos_info_table[unit];                                           /* PRQA S 3678 # Advisory R-8.13 */

    return p_qos_reg->BR_ACCNTTOTAL_R;                                                                               /* PRQA S 0662, 4461 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.3_UC1 */
}

/*******************************************************************************************************************//**
 * This function returns total write access of a specific QoS unit.
 *
 * @param[in]  unit          QoS unit
 *
 * @retval     Total write access of the unit.
 **********************************************************************************************************************/
uint16_t R_BSP_QoSTotalWriteAccessGet (bsp_qos_unit_t unit)                                                          /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    volatile R_QOSCNT_FL_PE0CL0_Type * p_qos_reg = g_qos_info_table[unit];                                           /* PRQA S 3678 # Advisory R-8.13 */

    return p_qos_reg->BR_ACCNTTOTAL_W;                                                                               /* PRQA S 0662, 4461 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.3_UC1 */
}

/*******************************************************************************************************************//**
 * This function clears total number of read/write access and maximum/minimum of read/write access of a specific unit.
 *
 * @param[in]  unit          QoS unit that need to be cleared.
 *
 * @retval     None
 **********************************************************************************************************************/
void R_BSP_QoSNumberofAccessClear (bsp_qos_unit_t unit)                                                              /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    volatile R_QOSCNT_FL_PE0CL0_Type * p_qos_reg = g_qos_info_table[unit];
    p_qos_reg->BR_ACCNTCLR_b.CLRTW = 1U;                                                                             /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(0U, p_qos_reg->BR_ACCNTTOTAL_W);                                                      /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    p_qos_reg->BR_ACCNTCLR_b.CLRTR = 1U;                                                                             /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(0U, p_qos_reg->BR_ACCNTTOTAL_R);                                                      /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    p_qos_reg->BR_ACCNTCLR_b.CLRMW = 1U;                                                                             /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT((uint16_t) (BSP_QOS_MAX_ACCESS_COUNT_DEFAULT_VALUE), p_qos_reg->BR_ACCNTMAX_W_b.CNT); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT((uint16_t) (BSP_QOS_MIN_ACCESS_COUNT_DEFAULT_VALUE), p_qos_reg->BR_ACCNTMIN_W_b.CNT); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    p_qos_reg->BR_ACCNTCLR_b.CLRMR = 1U;                                                                             /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT((uint16_t) (BSP_QOS_MAX_ACCESS_COUNT_DEFAULT_VALUE), p_qos_reg->BR_ACCNTMAX_R_b.CNT); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    FSP_HARDWARE_REGISTER_WAIT((uint16_t) (BSP_QOS_MIN_ACCESS_COUNT_DEFAULT_VALUE), p_qos_reg->BR_ACCNTMIN_R_b.CNT); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * This function enables the Latency Monitor feature with user input configuration.
 *
 * @param[in]  p_cfg                 Pointer to Latency Monitor configuration structure.
 *
 * @retval  FSP_SUCCESS              Configure Latency Monitor successfully.
 * @retval  FSP_ERR_ASSERTION        A critical assertion has failed.
 **********************************************************************************************************************/
fsp_err_t R_BSP_QoSLatencyMonitorEnable (const bsp_latency_monitor_cfg_t * p_cfg)                                    /* PRQA S 1505 # Advisory R-8.7 */
{
    fsp_err_t err = FSP_SUCCESS;
    volatile R_QOSCNT_FL_PE0CL0_Type * p_qos_reg;

    FSP_ASSERT(p_cfg);
    FSP_ASSERT((uint8_t) (p_cfg->unit) < (uint8_t) (BSP_QOS_UNIT_NUM));
    FSP_ASSERT(p_cfg->channel < BSP_QOS_LATENCY_MONITOR_MAX_NUM_CHANNEL);
    FSP_ASSERT((p_cfg->minimum_address_0 % 4U) == 0x00U);
    FSP_ASSERT((p_cfg->maximum_address_0 % 4U) == 0x00U);
    FSP_ASSERT((p_cfg->minimum_address_1 % 4U) == 0x00U);
    FSP_ASSERT((p_cfg->maximum_address_1 % 4U) == 0x00U);

    /* Configure Latency Monitor Channel Interrupt Bind */
    BSP_QOS_LMn_INTBD((uint8_t) (p_cfg->unit), p_cfg->channel) |=                            /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                                                                  (1U << (p_cfg->interrupt_port_bind_bit));

    /* Configure Cycle Threshold for read/write access of unit */
    BSP_QOS_LMn_LTTH_R((uint8_t) (p_cfg->unit), p_cfg->channel) =                            /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                                                                  p_cfg->cycle_read_latency_threshold;
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_LTTH_R((uint8_t) (p_cfg->unit), p_cfg->channel),  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                               p_cfg->cycle_read_latency_threshold);

    BSP_QOS_LMn_LTTH_W((uint8_t) (p_cfg->unit), p_cfg->channel) =                            /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                                                                  p_cfg->cycle_write_latency_threshold;
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_LTTH_W((uint8_t) (p_cfg->unit), p_cfg->channel),  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                               p_cfg->cycle_write_latency_threshold);

    /* Configure Overflow Count Threshold for read/write access of unit */
    BSP_QOS_LMn_OVFTH_R((uint8_t) (p_cfg->unit), p_cfg->channel) =                           /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                                                                   p_cfg->read_latency_overflow_count_threshold;
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_OVFTH_R((uint8_t) (p_cfg->unit), p_cfg->channel), /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                               p_cfg->read_latency_overflow_count_threshold);

    BSP_QOS_LMn_OVFTH_W((uint8_t) (p_cfg->unit), p_cfg->channel) =                           /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                                                                   p_cfg->write_latency_overflow_count_threshold;
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_OVFTH_W((uint8_t) (p_cfg->unit), p_cfg->channel), /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                               p_cfg->write_latency_overflow_count_threshold);

    /* Configure minimum/maximum address 0/1 for unit */
    BSP_QOS_LMn_LADDR0((uint8_t) (p_cfg->unit), p_cfg->channel) =                            /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                                                                  p_cfg->minimum_address_0;
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_LADDR0((uint8_t) (p_cfg->unit), p_cfg->channel),  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                               p_cfg->minimum_address_0);

    BSP_QOS_LMn_UADDR0((uint8_t) (p_cfg->unit), p_cfg->channel) =                            /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                                                                  p_cfg->maximum_address_0;
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_UADDR0((uint8_t) (p_cfg->unit), p_cfg->channel),  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                               p_cfg->maximum_address_0);

    BSP_QOS_LMn_LADDR1((uint8_t) (p_cfg->unit), p_cfg->channel) =                            /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                                                                  p_cfg->minimum_address_1;
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_LADDR1((uint8_t) (p_cfg->unit), p_cfg->channel),  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                               p_cfg->minimum_address_1);

    BSP_QOS_LMn_UADDR1((uint8_t) (p_cfg->unit), p_cfg->channel) =                            /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                                                                  p_cfg->maximum_address_1;
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_UADDR1((uint8_t) (p_cfg->unit), p_cfg->channel),  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                               p_cfg->maximum_address_1);

    BSP_QOS_LMn_SPID((uint8_t) (p_cfg->unit), p_cfg->channel) = (p_cfg->spid);               /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_SPID((uint8_t) (p_cfg->unit),                     /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
                                                p_cfg->channel),
                               (p_cfg->spid));

    /* Set up Interrupt */
    if (BSP_IRQ_DISABLED != p_cfg->ipl)
    {
        R_BSP_IrqCfgEnable(bsp_qos_irq_num_lookup[p_cfg->interrupt_port_bind_bit], p_cfg->ipl, NULL);

        g_qos_context_table[(uint8_t) g_qos_irq_index_table[(uint8_t) (p_cfg->unit)]] =
            (bsp_latency_monitor_cfg_t *) p_cfg; /* PRQA S 0311 # DP_MSR_R-11.8_UC1 */

        R_BSP_QoSLatencyOverflowIrqEnable(p_cfg->unit, p_cfg->interrupt_port_bind_bit);
    }

    /* Disable irq */
    else
    {
        g_qos_context_table[(uint8_t) g_qos_irq_index_table[(uint8_t) (p_cfg->unit)]] = NULL;

        R_BSP_QoSLatencyOverflowIrqDisable(p_cfg->unit, p_cfg->interrupt_port_bind_bit);
    }

    p_qos_reg            = g_qos_info_table[(uint8_t) (p_cfg->unit)];
    p_qos_reg->LM_CNTCLR =                                       /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                           ((uint32_t) R_QOSCNT_FL_PE0CL0_LM_CNTCLR_CLRW_Msk |
                            (uint32_t) R_QOSCNT_FL_PE0CL0_LM_CNTCLR_CLRR_Msk);
    p_qos_reg->LM_INTCLR = R_QOSCNT_FL_PE0CL0_LM_INTCLR_CLR_Msk; /* PRQA S 0662, 1257 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.3_UC1 */

    /* Wait for completion of the instruction, then refetch the subsequent instructions*/
    __SYNCI();                                                   /* PRQA S 3469 # Advisory D-4.9 */

    return err;
}

/*******************************************************************************************************************//**
 * This function disables the set up of the specific unit.
 *
 * @param[in]  unit          QoS unit that need to be cleared.
 * @param[in]  channel       QoS unit's Latency Monitor channel.
 *
 * @retval  None
 **********************************************************************************************************************/
void R_BSP_QoSLatencyMonitorDisable (bsp_qos_unit_t unit, uint8_t channel) /* PRQA S 1505 # Advisory R-8.7 */
{
    volatile R_QOSCNT_FL_PE0CL0_Type * p_qos_reg;

    /* Clear Latency Monitor Channel Interrupt Bind */
    BSP_QOS_LMn_INTBD((uint8_t) (unit), channel) = 0x00U;                              /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */

    /* Clear Cycle Threshold for read/write access of unit */
    BSP_QOS_LMn_LTTH_R((uint8_t) (unit), channel) = 0x00U;                             /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_LTTH_R((uint8_t) (unit), channel), 0x00U);  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */

    BSP_QOS_LMn_LTTH_W((uint8_t) (unit), channel) = 0x00U;                             /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_LTTH_W((uint8_t) (unit), channel), 0x00U);  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */

    /* Clear Overflow Count Threshold for read/write access of unit */
    BSP_QOS_LMn_OVFTH_R((uint8_t) (unit), channel) = 0x00U;                            /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_OVFTH_R((uint8_t) (unit), channel), 0x00U); /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */

    BSP_QOS_LMn_OVFTH_W((uint8_t) (unit), channel) = 0x00U;                            /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_OVFTH_W((uint8_t) (unit), channel), 0x00U); /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */

    /* Clear minimum/maximum address 0/1 for unit */
    BSP_QOS_LMn_LADDR0((uint8_t) (unit), channel) = 0x00U;                             /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_LADDR0((uint8_t) (unit), channel), 0x00U);  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */

    BSP_QOS_LMn_UADDR0((uint8_t) (unit), channel) = 0x00U;                             /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_UADDR0((uint8_t) (unit), channel), 0x00U);  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */

    BSP_QOS_LMn_LADDR1((uint8_t) (unit), channel) = 0x00U;                             /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_LADDR1((uint8_t) (unit), channel), 0x00U);  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */

    BSP_QOS_LMn_UADDR1((uint8_t) (unit), channel) = 0x00U;                             /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_UADDR1((uint8_t) (unit), channel), 0x00U);  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */

    BSP_QOS_LMn_SPID((uint8_t) (unit), channel) = (0x00U);                             /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */
    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LMn_SPID((uint8_t) (unit), channel), (0x00U));  /* PRQA S 0303, 0330, 0662, 3432 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-20.7_UC1 */

    g_qos_context_table[(uint8_t) g_qos_irq_index_table[(uint8_t) unit]] = NULL;

    p_qos_reg = g_qos_info_table[(uint8_t) (unit)];

    p_qos_reg->LM_CNTCLR =                                       /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                           ((uint32_t) R_QOSCNT_FL_PE0CL0_LM_CNTCLR_CLRW_Msk |
                            (uint32_t) R_QOSCNT_FL_PE0CL0_LM_CNTCLR_CLRR_Msk);
    p_qos_reg->LM_INTCLR = R_QOSCNT_FL_PE0CL0_LM_INTCLR_CLR_Msk; /* PRQA S 0662, 1257 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.3_UC1 */

    /* Wait for completion of the instruction, then refetch the subsequent instructions*/
    __SYNCI();                                                   /* PRQA S 3469 # Advisory D-4.9 */
}

/*******************************************************************************************************************//**
 * This function starts Latnecy Monitor for the specific unit.
 *
 * @param[in]  unit          QoS unit that need to be started.
 *
 * @retval     None
 **********************************************************************************************************************/
void R_BSP_QoSLatencyMonitorStart (bsp_qos_unit_t unit)          /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    volatile R_QOSCNT_FL_PE0CL0_Type * p_qos_reg;

    p_qos_reg             = g_qos_info_table[(uint8_t) (unit)];
    p_qos_reg->LM_CNTSTRT = R_QOSCNT_FL_PE0CL0_LM_CNTSTRT_START_Msk;                  /* PRQA S 0662, 1257 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.3_UC1 */

    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LATENCY_MONITOR_START, p_qos_reg->LM_CNTSTAT); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * This function stops Latnecy Monitor for the specific unit.
 *
 * @param[in]  unit          QoS unit that need to be stopped.
 *
 * @retval     None
 **********************************************************************************************************************/
void R_BSP_QoSLatencyMonitorStop (bsp_qos_unit_t unit)                                /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    volatile R_QOSCNT_FL_PE0CL0_Type * p_qos_reg;

    p_qos_reg            = g_qos_info_table[(uint8_t) (unit)];
    p_qos_reg->LM_CNTSTP = R_QOSCNT_FL_PE0CL0_LM_CNTSTP_STOP_Msk;                    /* PRQA S 0662, 1257 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.3_UC1 */

    FSP_HARDWARE_REGISTER_WAIT(BSP_QOS_LATENCY_MONITOR_STOP, p_qos_reg->LM_CNTSTAT); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * This function clears the count registers of the specific unit.
 *
 * @param[in]  unit          QoS unit that registers need to be cleared.
 *
 * @retval     None
 **********************************************************************************************************************/
void R_BSP_QoSLatencyMonitorCountClear (bsp_qos_unit_t unit)                         /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    volatile R_QOSCNT_FL_PE0CL0_Type * p_qos_reg = g_qos_info_table[(uint8_t) (unit)];

    p_qos_reg->LM_CNTCLR =                                                           /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                           ((uint32_t) R_QOSCNT_FL_PE0CL0_LM_CNTCLR_CLRR_Msk |
                            (uint32_t) R_QOSCNT_FL_PE0CL0_LM_CNTCLR_CLRW_Msk);

    /* Wait for completion of the instruction, then refetch the subsequent instructions*/
    __SYNCI();                         /* PRQA S 3469 # Advisory D-4.9 */
}

/*******************************************************************************************************************//**
 * ISR called when read/write access of a bus master excesses the threshold value.
 **********************************************************************************************************************/
BSP_INTERRUPT_ATTRIBUTE void bsp_qos_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    /* Get current IRQ */
    IRQn_Type         irq = R_FSP_CurrentIrqGet();
    uint8_t           port;
    volatile uint32_t irq_flag_reg_value;
    uint8_t           irq_highest_priority = BSP_QOS_LOWEST_PRIORITY;
    uint8_t           bit_pos;
    const volatile bsp_latency_monitor_cfg_t * p_cfg = NULL;

    /* Get Latency Monitor interrupt port */
    BSP_QOS_GET_INTERRUPT_PORT(irq, port)                                         /* PRQA S 4332, 4393, 4521, 1820 # Advisory R-10.5, DP_MSR_R-10.8_UC1, DP_MSR_R-10.1_UC1, DP_MSR_R-10.4_UC1 */

    /* Make sure that the interrupt with highest priority is always triggered first */
    irq_flag_reg_value = BSP_QOS_INTQOSnMON0(port);                               /* PRQA S 0303, 3432, 3469 # Advisory R-11.4, DP_MSR_R-20.7_UC1, Advisory D-4.9 */

    while (0U != irq_flag_reg_value)
    {
        bit_pos = (uint8_t) __SCH1R(irq_flag_reg_value) - 1U;                     /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */

        if (NULL != g_qos_context_table[bit_pos])
        {
            uint8_t current_context_priority = g_qos_context_table[bit_pos]->ipl; /* PRQA S 0404 # DP_MSR_R-1.3_UC1 & DP_MSR_R-13.2_UC1 */

            if (current_context_priority < irq_highest_priority)
            {
                p_cfg                = (const volatile bsp_latency_monitor_cfg_t *) g_qos_context_table[bit_pos];
                irq_highest_priority = current_context_priority;
            }
        }

        irq_flag_reg_value &= ~((uint32_t) 1U << bit_pos);
    }

    irq_flag_reg_value = BSP_QOS_INTQOSnMON1(port);                     /* PRQA S 0303, 3432, 3469 # Advisory R-11.4, DP_MSR_R-20.7_UC1, Advisory D-4.9 */

    while (0U != irq_flag_reg_value)
    {
        uint8_t raw_bit = ((uint8_t) __SCH1R(irq_flag_reg_value) - 1U); /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */
        bit_pos = raw_bit + BSP_QOS_INTQOSnMON1_BIT_OFFSET;

        if (NULL != g_qos_context_table[bit_pos])
        {
            uint8_t current_context_priority = g_qos_context_table[bit_pos]->ipl; /* PRQA S 0404 # DP_MSR_R-1.3_UC1 & DP_MSR_R-13.2_UC1 */

            if (current_context_priority < irq_highest_priority)
            {
                p_cfg                = (const volatile bsp_latency_monitor_cfg_t *) g_qos_context_table[bit_pos];
                irq_highest_priority = current_context_priority;
            }
        }

        irq_flag_reg_value &= ~((uint32_t) 1U << raw_bit);
    }

    if ((NULL != p_cfg) && (NULL != p_cfg->p_callback))
    {
        /* Trigger user callback */
        p_cfg->p_callback();
    }

    if (NULL != p_cfg)
    {
        R_BSP_QoSLatencyMonitorInterruptFlagClear(p_cfg->unit);
    }

    /* Restore RTOS context */
    FSP_CONTEXT_RESTORE
}

#endif                                 /* BSP_FEATURE_QOS_IS_AVAILABLE */

/** @} (end addtogroup BSP_QOS) */

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
