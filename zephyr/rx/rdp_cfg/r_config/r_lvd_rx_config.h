/***********************************************************************************************************************
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_lvd_rx_config.h
* Description  : Configures the LVD FIT module.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History      : DD.MM.YYYY Version  Description
*              : 15.06.2016 2.00     First Release
*              : 01.10.2016 2.10     Deleted Tool-Chain version.
*              : 19.12.2016 2.20     Deleted unnecessary header information.
*              : 09.06.2017 2.30     Added support for RX130-512K, RX65N-2M.
*              : 28.09.2018 2.40     Added support for RX66T.
*                                    Corrected file name.
*              : 01.02.2019 2.50     Added support for RX72T, RX65N-64pin.
*              : 28.06.2024 4.80     Added Nested interrupt support.
*              : 15.03.2025 4.81     Updated disclaimer.
***********************************************************************************************************************/
#ifndef LVD_CONFIG_HEADER_FILE
#define LVD_CONFIG_HEADER_FILE

/***********************************************************************************************************************
Includes <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* Includes board and MCU related header files. */
#include "platform.h"

#define BSP_PROP_HAS_STATUS_OKAY_OR(node_id, prop, default_value) \
    (COND_CODE_1(DT_NODE_HAS_STATUS(node_id, okay), (DT_PROP(node_id, prop)), (default_value)))

#define BSP_PROP_HAS_STATUS_OKAY_ENUM(node_id, prop, default_value)            \
  (COND_CODE_1(DT_NODE_HAS_STATUS(node_id, okay),                              \
               (DT_ENUM_IDX(node_id, prop)), (default_value)))

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Specifies whether to include parameter checking in the code.                     */
/* 0 : Omit parameter checking from the build.                                      */
/* 1 : Include parameter checking in the build.                                     */
/* BSP_CFG_PARAM_CHECKING_ENABLE: Use the system default setting. (default value)   */
/* Note: Code size can be reduced by excluding parameter checking from the build.   */
#define LVD_CFG_PARAM_CHECKING_ENABLE       (BSP_CFG_PARAM_CHECKING_ENABLE)

/* Specifies whether to use the corresponding channel.                              */
/* 0: The corresponding channel is not used.                                        */
/* 1: The corresponding channel is used. (default value)                            */
#define LVD_CFG_CHANNEL_1_USED DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(lvd0))
#define LVD_CFG_CHANNEL_2_USED DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(lvd1))

/* Specifies the target to be monitored for each channel.                           */
/* 0: VCC (default value)                                                           */
/* 1: CMPA2 pin                                                                     */
#define LVD_CFG_VDET_TARGET_CHANNEL_1                                                              \
	BSP_PROP_HAS_STATUS_OKAY_ENUM(DT_NODELABEL(lvd0), vdet_target, 0)
#define LVD_CFG_VDET_TARGET_CHANNEL_2                                                              \
	BSP_PROP_HAS_STATUS_OKAY_ENUM(DT_NODELABEL(lvd1), vdet_target, 0)

/* Specifies the voltage detection level for each channel. Set an integer value     */
/* which expresses the number up to two decimal places.                             */
/* The default value is with reference to the hardware initial value, thus it       */
/* varies depending on the product used.                                            */
/* Example:                                                                         */
/* To set the voltage detection level to 3.00 V, specify '300'.                     */
/* To set the voltage detection level to 4.29 V, specify '429'.                     */
/* To set the voltage detection level to default value, specify '0xFFFF' .          */

#define LVD_CFG_VOLTAGE_LEVEL_CHANNEL_1                                                            \
	BSP_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(lvd0), voltage_level, 0)
#define LVD_CFG_VOLTAGE_LEVEL_CHANNEL_2                                                            \
	BSP_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(lvd1), voltage_level, 0)

/* Specifies enable/disable of the digital filter for each channel.                 */
/* 0: Digital filter is disabled. (default value)                                   */
/* 1: Digital filter is enabled.                                                    */
#define LVD_CFG_DIGITAL_FILTER_CHANNEL_1    (0)
#define LVD_CFG_DIGITAL_FILTER_CHANNEL_2    (0)

/* With the digital filter enabled, specifies the division ratio of LOCO as the     */
/* sampling clock applied to each channel. Set an integer value which expresses     */
/* the division ratio.                                                              */
/* The default value is with reference to the hardware initial value, thus it       */
/* varies depending on the product used.                                            */
/* Example:                                                                         */
/* To set the division ratio to divided-by-1, specify '1'.                          */
/* To set the division ratio to divided-by-4, specify '4'.                          */
/* To set the division ratio to default value, specify '0xFFFF' .                   */
#define LVD_CFG_SAMPLING_CLOCK_CHANNEL_1    (0xFFFF)
#define LVD_CFG_SAMPLING_CLOCK_CHANNEL_2    (0xFFFF)

/* Specifies processing upon voltage detection for each channel.                    */
/* 0: Reset                                                                         */
/* 1: Non-maskable interrupt (default value)                                        */
/* 2: Maskable interrupt                                                            */
/* 3: No processing                                                                 */
/* Note: Reset here indicates device reset. When reset is selected as processing, a */
/* reset occurs when a monitored voltage is below the voltage detection level. When */
/* reset is selected with this definition, the operation of the reset is not        */
/* dependent on the voltage detection condition.                                    */

#define LVD_CFG_ACTION_CHANNEL_1 BSP_PROP_HAS_STATUS_OKAY_ENUM(DT_NODELABEL(lvd0), lvd_action, 0)
#define LVD_CFG_ACTION_CHANNEL_2 BSP_PROP_HAS_STATUS_OKAY_ENUM(DT_NODELABEL(lvd1), lvd_action, 0)

/* Specifies the interrupt priority level for each channel, with maskable interrupt */
/* selected as processing.                                                          */
/* Set the level with an integer value; setting 1 means that the priority level is  */
/* the lowest level and 15 means the highest level.                                 */
/* (default value = 3)                                                              */
/* Example:                                                                         */
/* To set the priority level to 3, specify '3'.                                     */
/* To set the priority level to 15, specify '15'.                                   */
#define LVD_CFG_INT_PRIORITY_CHANNEL_1 DT_IRQ_BY_IDX(DT_NODELABEL(lvd0), 0, priority)
#define LVD_CFG_INT_PRIORITY_CHANNEL_2 DT_IRQ_BY_IDX(DT_NODELABEL(lvd1), 0, priority)

/* Specifies the reset negation timing for each channel, with reset selected as     */
/* processing.                                                                      */
/* 0: After a LVD reset, negation occurs when a certain period elapses after the    */
/*    monitored voltage goes above the voltage detection level.                     */
/* 1: Negation occurs when a certain period elapses after the LVD reset assertion.  */
/* Note: "a certain period" here means a wait time after a voltage monitoring       */
/* reset. Refer to the User's Manual: Hardware for details.                         */
#define LVD_CFG_STABILIZATION_CHANNEL_1                                                            \
	BSP_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(lvd0), lvd_stabilization, 0)
#define LVD_CFG_STABILIZATION_CHANNEL_2                                                            \
	BSP_PROP_HAS_STATUS_OKAY_OR(DT_NODELABEL(lvd1), lvd_stabilization, 0)

/* Enable Nested Interrupt                                                          */
/* 0 : Disable nested interrupt.                                                    */
/* 1 : Enable nested interrupt.                                                     */
/* (default value = 0)                                                              */
#define LVD_CFG_EN_NESTED_INT               (0)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Imported global variables and functions (from other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables and functions (to be accessed by other files)
***********************************************************************************************************************/

#endif /* LVD_CONFIG_HEADER_FILE */

/* End of File */

