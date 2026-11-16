/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"                   /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */
#include "bsp_qos_driver.h"

#if (BSP_FEATURE_QOS_IS_AVAILABLE)
 #include "common_data.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/** Array contains the pointers to QoS configuration */
volatile bsp_latency_monitor_cfg_t * volatile g_qos_context_table[BSP_QOS_IRQ_INDEX_MAX];

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/** Array contains all QoS informations */
R_QOSCNT_FL_PE0CL0_Type * g_qos_info_table[BSP_QOS_UNIT_NUM] =
{
    [BSP_QOS_UNIT_FL_PE0CL0] = (R_QOSCNT_FL_PE0CL0), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_VC_PE0CL0] = (R_QOSCNT_VC_PE0CL0), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_MB_PE0CL0] = (R_QOSCNT_MB_PE0CL0), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_FL_PE1CL0] = (R_QOSCNT_FL_PE1CL0), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_VC_PE1CL0] = (R_QOSCNT_VC_PE1CL0), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_MB_PE1CL0] = (R_QOSCNT_MB_PE1CL0), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_FL_PE0CL1] = (R_QOSCNT_FL_PE0CL1), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_VC_PE0CL1] = (R_QOSCNT_VC_PE0CL1), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_MB_PE0CL1] = (R_QOSCNT_MB_PE0CL1), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_FL_PE1CL1] = (R_QOSCNT_FL_PE1CL1), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_VC_PE1CL1] = (R_QOSCNT_VC_PE1CL1), /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_MB_PE1CL1] = (R_QOSCNT_MB_PE1CL1), /* PRQA S 0306 # Advisory R-11.4 */
 #if (BSP_FEATURE_QOS_PE0CL2_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_FL_PE0CL2] = (R_QOSCNT_FL_PE0CL2),
    [BSP_QOS_UNIT_VC_PE0CL2] = (R_QOSCNT_VC_PE0CL2),
    [BSP_QOS_UNIT_MB_PE0CL2] = (R_QOSCNT_MB_PE0CL2),
 #endif                                /* BSP_FEATURE_QOS_PE0CL2_UNIT_AVAILABLE */
 #if (BSP_FEATURE_QOS_PE1CL2_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_FL_PE1CL2] = (R_QOSCNT_FL_PE1CL2),
    [BSP_QOS_UNIT_VC_PE1CL2] = (R_QOSCNT_VC_PE1CL2),
    [BSP_QOS_UNIT_MB_PE1CL2] = (R_QOSCNT_MB_PE1CL2),
 #endif                                            /* BSP_FEATURE_QOS_PE1CL2_UNIT_AVAILABLE */
    [BSP_QOS_UNIT_DTS]      = (R_QOSCNT_DTS),      /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_SDMAC0]   = (R_QOSCNT_SDMAC0),   /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_SDMAC1]   = (R_QOSCNT_SDMAC1),   /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_FL_ICUM]  = (R_QOSCNT_FL_ICUM),  /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_SYS_ICUM] = (R_QOSCNT_SYS_ICUM), /* PRQA S 0306 # Advisory R-11.4 */
 #if (BSP_FEATURE_QOS_ACEU0_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ACEU0] = (R_QOSCNT_ACEU0),
 #endif                                            /* BSP_FEATURE_QOS_ACEU0_UNIT_AVAILABLE */
 #if (BSP_FEATURE_QOS_ACEU1_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ACEU1] = (R_QOSCNT_ACEU1),
 #endif                                            /* BSP_FEATURE_QOS_ACEU1_UNIT_AVAILABLE */
    [BSP_QOS_UNIT_FL_DFP]  = (R_QOSCNT_FL_DFP),    /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_SYS_DFP] = (R_QOSCNT_SYS_DFP),   /* PRQA S 0306 # Advisory R-11.4 */
    [BSP_QOS_UNIT_GTM]     = (R_QOSCNT_GTM),       /* PRQA S 0306 # Advisory R-11.4 */
 #if (BSP_FEATURE_QOS_RHSIF0_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_RHSIF0] = (R_QOSCNT_RHSIF0),     /* PRQA S 0306 # Advisory R-11.4 */
 #endif                                            /* BSP_FEATURE_QOS_RHSIF0_UNIT_AVAILABLE */
 #if (BSP_FEATURE_QOS_RHSIF1_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_RHSIF1] = (R_QOSCNT_RHSIF1),
 #endif                                            /* BSP_FEATURE_QOS_RHSIF1_UNIT_AVAILABLE */
    [BSP_QOS_UNIT_FLXA0] = (R_QOSCNT_FLXA0),       /* PRQA S 0306 # Advisory R-11.4 */
 #if (BSP_FEATURE_QOS_ETHER0_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ETHER0] = (R_QOSCNT_ETHER0),     /* PRQA S 0306 # Advisory R-11.4 */
 #endif                                            /* BSP_FEATURE_QOS_ETHER0_UNIT_AVAILABLE */
 #if (BSP_FEATURE_QOS_ETHER1_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ETHER1] = (R_QOSCNT_ETHER1),
 #endif                                            /* BSP_FEATURE_QOS_ETHER1_UNIT_AVAILABLE */
 #if (BSP_FEATURE_QOS_R_SWITCH_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_R_SWITCH] = (R_QOSCNT_R_SWITCH)
 #endif                                            /* BSP_FEATURE_QOS_R_SWITCH_UNIT_AVAILABLE */
};

/** Array contains all QoS configurations */
const bsp_qos_cfg_t g_qos_config_table[BSP_QOS_UNIT_NUM] =
{
    [BSP_QOS_UNIT_FL_PE0CL0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_FL_PE0CL0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_FL_PE0CL0,
        .period       = BSP_QOS_FL_PE0CL0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_FL_PE0CL0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_FL_PE0CL0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_FL_PE0CL0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_FL_PE0CL0
        }
        },
    [BSP_QOS_UNIT_VC_PE0CL0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_VC_PE0CL0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_VC_PE0CL0,
        .period       = BSP_QOS_VC_PE0CL0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_VC_PE0CL0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_VC_PE0CL0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_VC_PE0CL0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_VC_PE0CL0
        }
        },
    [BSP_QOS_UNIT_MB_PE0CL0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_MB_PE0CL0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_MB_PE0CL0,
        .period       = BSP_QOS_MB_PE0CL0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_MB_PE0CL0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_MB_PE0CL0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_MB_PE0CL0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_MB_PE0CL0
        }
        },
    [BSP_QOS_UNIT_FL_PE1CL0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_FL_PE1CL0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_FL_PE1CL0,
        .period       = BSP_QOS_FL_PE1CL0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_FL_PE1CL0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_FL_PE1CL0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_FL_PE1CL0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_FL_PE1CL0
        }
        },
    [BSP_QOS_UNIT_VC_PE1CL0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_VC_PE1CL0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_VC_PE1CL0,
        .period       = BSP_QOS_VC_PE1CL0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_VC_PE1CL0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_VC_PE1CL0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_VC_PE1CL0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_VC_PE1CL0
        }
        },
    [BSP_QOS_UNIT_MB_PE1CL0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_MB_PE1CL0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_MB_PE1CL0,
        .period       = BSP_QOS_MB_PE1CL0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_MB_PE1CL0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_MB_PE1CL0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_MB_PE1CL0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_MB_PE1CL0
        }
        },
    [BSP_QOS_UNIT_FL_PE0CL1] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_FL_PE0CL1_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_FL_PE0CL1,
        .period       = BSP_QOS_FL_PE0CL1_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_FL_PE0CL1_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_FL_PE0CL1_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_FL_PE0CL1_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_FL_PE0CL1
        }
        },
    [BSP_QOS_UNIT_VC_PE0CL1] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_VC_PE0CL1_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_VC_PE0CL1,
        .period       = BSP_QOS_VC_PE0CL1_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_VC_PE0CL1_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_VC_PE0CL1_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_VC_PE0CL1_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_VC_PE0CL1
        }
        },
    [BSP_QOS_UNIT_MB_PE0CL1] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_MB_PE0CL1_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_MB_PE0CL1,
        .period       = BSP_QOS_MB_PE0CL1_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_MB_PE0CL1_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_MB_PE0CL1_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_MB_PE0CL1_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_MB_PE0CL1
        }
        },
    [BSP_QOS_UNIT_FL_PE1CL1] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_FL_PE1CL1_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_FL_PE1CL1,
        .period       = BSP_QOS_FL_PE1CL1_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_FL_PE1CL1_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_FL_PE1CL1_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_FL_PE1CL1_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_FL_PE1CL1
        }
        },
    [BSP_QOS_UNIT_VC_PE1CL1] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_VC_PE1CL1_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_VC_PE1CL1,
        .period       = BSP_QOS_VC_PE1CL1_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_VC_PE1CL1_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_VC_PE1CL1_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_VC_PE1CL1_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_VC_PE1CL1
        }
        },
    [BSP_QOS_UNIT_MB_PE1CL1] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_MB_PE1CL1_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_MB_PE1CL1,
        .period       = BSP_QOS_MB_PE1CL1_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_MB_PE1CL1_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_MB_PE1CL1_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_MB_PE1CL1_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_MB_PE1CL1
        }
        },
 #if (BSP_FEATURE_QOS_PE0CL2_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_FL_PE0CL2] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_FL_PE0CL2_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_FL_PE0CL2,
        .period       = BSP_QOS_FL_PE0CL2_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_FL_PE0CL2_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_FL_PE0CL2_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_FL_PE0CL2_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_FL_PE0CL2
        }
        },
    [BSP_QOS_UNIT_VC_PE0CL2] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_VC_PE0CL2_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_VC_PE0CL2,
        .period       = BSP_QOS_VC_PE0CL2_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_VC_PE0CL2_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_VC_PE0CL2_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_VC_PE0CL2_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_VC_PE0CL2
        }
        },
    [BSP_QOS_UNIT_MB_PE0CL2] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_MB_PE0CL2_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_MB_PE0CL2,
        .period       = BSP_QOS_MB_PE0CL2_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_MB_PE0CL2_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_MB_PE0CL2_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_MB_PE0CL2_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_MB_PE0CL2
        }
        },
 #endif                                /* BSP_FEATURE_QOS_PE0CL2_UNIT_AVAILABLE */
 #if (BSP_FEATURE_QOS_PE1CL2_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_FL_PE1CL2] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_FL_PE1CL2_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_FL_PE1CL2,
        .period       = BSP_QOS_FL_PE1CL2_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_FL_PE1CL2_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_FL_PE1CL2_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_FL_PE1CL2_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_FL_PE1CL2
        }
        },
    [BSP_QOS_UNIT_VC_PE1CL2] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_VC_PE1CL2_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_VC_PE1CL2,
        .period       = BSP_QOS_VC_PE1CL2_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_VC_PE1CL2_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_VC_PE1CL2_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_VC_PE1CL2_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_VC_PE1CL2
        }
        },
    [BSP_QOS_UNIT_MB_PE1CL2] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_MB_PE1CL2_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_MB_PE1CL2,
        .period       = BSP_QOS_MB_PE1CL2_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_MB_PE1CL2_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_MB_PE1CL2_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_MB_PE1CL2_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_MB_PE1CL2
        }
        },
 #endif                                /* BSP_FEATURE_QOS_PE1CL2_UNIT_AVAILABLE */
    [BSP_QOS_UNIT_DTS] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_DTS_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_DTS,
        .period       = BSP_QOS_DTS_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_DTS_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_DTS_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_DTS_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_DTS_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_DTS_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_DTS_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_DTS_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_DTS_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_DTS_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_DTS_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_DTS_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_DTS_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_DTS_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_DTS_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_DTS_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_DTS
        }
        },
    [BSP_QOS_UNIT_SDMAC0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_SDMAC0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_SDMAC0,
        .period       = BSP_QOS_SDMAC0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_SDMAC0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_SDMAC0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_SDMAC0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_SDMAC0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_SDMAC0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_SDMAC0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_SDMAC0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_SDMAC0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_SDMAC0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_SDMAC0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_SDMAC0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_SDMAC0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_SDMAC0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_SDMAC0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_SDMAC0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_SDMAC0
        }
        },
    [BSP_QOS_UNIT_SDMAC1] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_SDMAC1_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_SDMAC1,
        .period       = BSP_QOS_SDMAC1_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_SDMAC1_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_SDMAC1_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_SDMAC1_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_SDMAC1_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_SDMAC1_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_SDMAC1_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_SDMAC1_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_SDMAC1_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_SDMAC1_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_SDMAC1_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_SDMAC1_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_SDMAC1_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_SDMAC1_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_SDMAC1_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_SDMAC1_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_SDMAC1
        }
        },
    [BSP_QOS_UNIT_FL_ICUM] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_FL_ICUM_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_FL_ICUM,
        .period       = BSP_QOS_FL_ICUM_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_FL_ICUM_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_FL_ICUM_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_FL_ICUM_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_FL_ICUM
        }
        },
    [BSP_QOS_UNIT_SYS_ICUM] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_SYS_ICUM_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_SYS_ICUM,
        .period       = BSP_QOS_SYS_ICUM_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_SYS_ICUM_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_SYS_ICUM_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_SYS_ICUM_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_SYS_ICUM
        }
        },
 #if (BSP_FEATURE_QOS_ACEU0_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ACEU0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_ACEU0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_ACEU0,
        .period       = BSP_QOS_ACEU0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_ACEU0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_ACEU0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_ACEU0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_ACEU0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_ACEU0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_ACEU0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_ACEU0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_ACEU0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_ACEU0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_ACEU0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_ACEU0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_ACEU0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_ACEU0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_ACEU0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_ACEU0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_ACEU0
        }
        },
 #endif                                /* BSP_FEATURE_QOS_ACEU0_UNIT_AVAILABLE */
 #if (BSP_FEATURE_QOS_ACEU1_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ACEU1] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_ACEU1_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_ACEU1,
        .period       = BSP_QOS_ACEU1_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_ACEU1_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_ACEU1_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_ACEU1_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_ACEU1_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_ACEU1_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_ACEU1_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_ACEU1_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_ACEU1_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_ACEU1_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_ACEU1_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_ACEU1_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_ACEU1_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_ACEU1_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_ACEU1_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_ACEU1_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_ACEU1
        }
        },
 #endif                                /* BSP_FEATURE_QOS_ACEU1_UNIT_AVAILABLE */
    [BSP_QOS_UNIT_FL_DFP] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_FL_DFP_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_FL_DFP,
        .period       = BSP_QOS_FL_DFP_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_FL_DFP_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_FL_DFP_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_FL_DFP_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_FL_DFP_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_FL_DFP_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_FL_DFP_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_FL_DFP_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_FL_DFP_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_FL_DFP_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_FL_DFP_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_FL_DFP_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_FL_DFP_LANTENCY_MONITOR_SPID, /* PRQA S 1281 # DP_MSR_R-7.2_UC1 */
        .interrupt_port_bind_bit = BSP_QOS_FL_DFP_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_FL_DFP_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_FL_DFP_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_FL_DFP
        }
        },
    [BSP_QOS_UNIT_SYS_DFP] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_SYS_DFP_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_SYS_DFP,
        .period       = BSP_QOS_SYS_DFP_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_SYS_DFP_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_SYS_DFP_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_SPID, /* PRQA S 1281 # DP_MSR_R-7.2_UC1 */
        .interrupt_port_bind_bit = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_SYS_DFP_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_SYS_DFP
        }
        },
    [BSP_QOS_UNIT_GTM] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_GTM_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_GTM,
        .period       = BSP_QOS_GTM_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_GTM_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_GTM_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_GTM_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_GTM_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_GTM_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_GTM_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_GTM_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_GTM_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_GTM_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_GTM_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_GTM_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_GTM_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_GTM_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_GTM_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_GTM_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_GTM
        }
        },
 #if (BSP_FEATURE_QOS_RHSIF0_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_RHSIF0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_RHSIF0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_RHSIF0,
        .period       = BSP_QOS_RHSIF0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_RHSIF0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_RHSIF0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_RHSIF0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_RHSIF0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_RHSIF0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_RHSIF0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_RHSIF0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_RHSIF0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_RHSIF0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_RHSIF0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_RHSIF0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_RHSIF0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_RHSIF0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_RHSIF0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_RHSIF0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_RHSIF0
        }
        },
 #endif                                /* BSP_FEATURE_QOS_RHSIF0_UNIT_AVAILABLE */
 #if (BSP_FEATURE_QOS_RHSIF1_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_RHSIF1] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_RHSIF1_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_RHSIF1,
        .period       = BSP_QOS_RHSIF1_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_RHSIF1_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_RHSIF1_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_RHSIF1_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_RHSIF1_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_RHSIF1_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_RHSIF1_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_RHSIF1_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_RHSIF1_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_RHSIF1_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_RHSIF1_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_RHSIF1_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_RHSIF1_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_RHSIF1_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_RHSIF1_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_RHSIF1_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_RHSIF1
        }
        },
 #endif                                /* BSP_FEATURE_QOS_RHSIF1_UNIT_AVAILABLE */
    [BSP_QOS_UNIT_FLXA0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_FLXA0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_FLXA0,
        .period       = BSP_QOS_FLXA0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_FLXA0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_FLXA0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_FLXA0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_FLXA0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_FLXA0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_FLXA0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_FLXA0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_FLXA0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_FLXA0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_FLXA0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_FLXA0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_FLXA0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_FLXA0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_FLXA0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_FLXA0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_FLXA0
        }
        },
 #if (BSP_FEATURE_QOS_ETHER0_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ETHER0] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_ETHER0_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_ETHER0,
        .period       = BSP_QOS_ETHER0_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_ETHER0_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_ETHER0_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_ETHER0_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_ETHER0_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_ETHER0_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_ETHER0_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_ETHER0_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_ETHER0_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_ETHER0_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_ETHER0_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_ETHER0_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_ETHER0_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_ETHER0_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_ETHER0_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_ETHER0_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_ETHER0
        }
        },
 #endif                                /* BSP_FEATURE_QOS_ETHER0_UNIT_AVAILABLE */
 #if (BSP_FEATURE_QOS_ETHER1_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ETHER1] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_ETHER1_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_ETHER1,
        .period       = BSP_QOS_ETHER1_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_ETHER1_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_ETHER1_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_ETHER1_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_ETHER1_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_ETHER1_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_ETHER1_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_ETHER1_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_ETHER1_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_ETHER1_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_ETHER1_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_ETHER1_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_ETHER1_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_ETHER1_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_ETHER1_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_ETHER1_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_ETHER1
        }
        },
 #endif                                /* BSP_FEATURE_QOS_ETHER1_UNIT_AVAILABLE */
 #if (BSP_FEATURE_QOS_R_SWITCH_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_R_SWITCH] =
        {
        .bandwidth_regulator_cfg                    =
        {
        .mode         = BSP_QOS_R_SWITCH_BANDWIDTH_REGULATOR_MODE,
        .unit         = BSP_QOS_UNIT_R_SWITCH,
        .period       = BSP_QOS_R_SWITCH_BANDWIDTH_REGULATOR_PERIOD,
        .read_access  = BSP_QOS_R_SWITCH_BANDWIDTH_REGULATOR_READ_ACCESS_THRESHOLD,
        .write_access = BSP_QOS_R_SWITCH_BANDWIDTH_REGULATOR_WRITE_ACCESS_THRESHOLD
        },
        .latency_monitor_cfg                        =
        {
        .minimum_address_0                      = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_MIN_ADDRESS_0,
        .maximum_address_0                      = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_MAX_ADDRESS_0,
        .minimum_address_1                      = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_MIN_ADDRESS_1,
        .maximum_address_1                      = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_MAX_ADDRESS_1,
        .cycle_read_latency_threshold           = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_CYCLE_READ_THRESHOLD,
        .cycle_write_latency_threshold          = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_CYCLE_WRITE_THRESHOLD,
        .read_latency_overflow_count_threshold  = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_READ_OVERFLOW_THRESHOLD,
        .write_latency_overflow_count_threshold = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_WRITE_OVERFLOW_THRESHOLD,
        .channel                 = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_CHANNEL,
        .spid                    = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_SPID,
        .interrupt_port_bind_bit = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_WRITE_INTERRUPT_BIND,
        .ipl        = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_IRQ_PRIORITY,
        .p_callback = BSP_QOS_R_SWITCH_LANTENCY_MONITOR_CALLBACK,
        .unit       = BSP_QOS_UNIT_R_SWITCH
        }
        }
 #endif                                /* BSP_FEATURE_QOS_R_SWITCH_UNIT_AVAILABLE */
};

/** Array contains the pointers to QoS configuration */
const bsp_qos_irq_index_t g_qos_irq_index_table[BSP_QOS_UNIT_NUM] =
{
    [BSP_QOS_UNIT_FL_PE0CL0] = BSP_QOS_IRQ_INDEX_0,
    [BSP_QOS_UNIT_VC_PE0CL0] = BSP_QOS_IRQ_INDEX_1,
    [BSP_QOS_UNIT_MB_PE0CL0] = BSP_QOS_IRQ_INDEX_2,
    [BSP_QOS_UNIT_FL_PE1CL0] = BSP_QOS_IRQ_INDEX_3,
    [BSP_QOS_UNIT_VC_PE1CL0] = BSP_QOS_IRQ_INDEX_4,
    [BSP_QOS_UNIT_MB_PE1CL0] = BSP_QOS_IRQ_INDEX_5,
    [BSP_QOS_UNIT_FL_PE0CL1] = BSP_QOS_IRQ_INDEX_6,
    [BSP_QOS_UNIT_VC_PE0CL1] = BSP_QOS_IRQ_INDEX_7,
    [BSP_QOS_UNIT_MB_PE0CL1] = BSP_QOS_IRQ_INDEX_8,
    [BSP_QOS_UNIT_FL_PE1CL1] = BSP_QOS_IRQ_INDEX_9,
    [BSP_QOS_UNIT_VC_PE1CL1] = BSP_QOS_IRQ_INDEX_10,
    [BSP_QOS_UNIT_MB_PE1CL1] = BSP_QOS_IRQ_INDEX_11,
 #if (BSP_FEATURE_QOS_PE0CL2_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_FL_PE0CL2] = BSP_QOS_IRQ_INDEX_12,
    [BSP_QOS_UNIT_VC_PE0CL2] = BSP_QOS_IRQ_INDEX_13,
    [BSP_QOS_UNIT_MB_PE0CL2] = BSP_QOS_IRQ_INDEX_14,
 #endif
 #if (BSP_FEATURE_QOS_PE1CL2_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_FL_PE1CL2] = BSP_QOS_IRQ_INDEX_15,
    [BSP_QOS_UNIT_VC_PE1CL2] = BSP_QOS_IRQ_INDEX_16,
    [BSP_QOS_UNIT_MB_PE1CL2] = BSP_QOS_IRQ_INDEX_17,
 #endif
    [BSP_QOS_UNIT_DTS]      = BSP_QOS_IRQ_INDEX_24,
    [BSP_QOS_UNIT_SDMAC0]   = BSP_QOS_IRQ_INDEX_25,
    [BSP_QOS_UNIT_SDMAC1]   = BSP_QOS_IRQ_INDEX_26,
    [BSP_QOS_UNIT_FL_ICUM]  = BSP_QOS_IRQ_INDEX_27,
    [BSP_QOS_UNIT_SYS_ICUM] = BSP_QOS_IRQ_INDEX_28,
 #if (BSP_FEATURE_QOS_ACEU0_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ACEU0] = BSP_QOS_IRQ_INDEX_29,
 #endif
 #if (BSP_FEATURE_QOS_ACEU1_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ACEU1] = BSP_QOS_IRQ_INDEX_30,
 #endif
    [BSP_QOS_UNIT_FL_DFP]  = BSP_QOS_IRQ_INDEX_31,
    [BSP_QOS_UNIT_SYS_DFP] = BSP_QOS_IRQ_INDEX_32,
    [BSP_QOS_UNIT_GTM]     = BSP_QOS_IRQ_INDEX_33,
 #if (BSP_FEATURE_QOS_RHSIF0_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_RHSIF0] = BSP_QOS_IRQ_INDEX_34,
 #endif
 #if (BSP_FEATURE_QOS_RHSIF1_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_RHSIF1] = BSP_QOS_IRQ_INDEX_35,
 #endif
    [BSP_QOS_UNIT_FLXA0] = BSP_QOS_IRQ_INDEX_36,
 #if (BSP_FEATURE_QOS_ETHER0_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ETHER0] = BSP_QOS_IRQ_INDEX_38,
 #endif
 #if (BSP_FEATURE_QOS_ETHER1_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_ETHER1] = BSP_QOS_IRQ_INDEX_39,
 #endif
 #if (BSP_FEATURE_QOS_R_SWITCH_UNIT_AVAILABLE)
    [BSP_QOS_UNIT_R_SWITCH] = BSP_QOS_IRQ_INDEX_40,
 #endif
};

#endif                                 /* BSP_FEATURE_QOS_IS_AVAILABLE */
