/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_bod.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Distance between the MASK and DISABLE bitfields in BOD_CTRL_REG. */
#define BSP_BOD_BIT_DISTANCE_MASK_DISABLE        (6)

/** Scaler for threshold level calculation of the channel in millivolts. */
#define BSP_BOD_VDD_CHANNEL_OFFSET_MILLIVOLTS    (-30) /* VDD */
#define BSP_BOD_V10_CHANNEL_OFFSET_MILLIVOLTS    (-30) /* V10 */
#define BSP_BOD_V18_CHANNEL_OFFSET_MILLIVOLTS    (-40) /* V18 and V18_EXT */

/** Step for threshold level calculation of the channel in millivolts. */
#define BSP_BOD_CHANNEL_STEP_MILLIVOLTS          (-10) /* VDD, V10, V18 and V18_EXT */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Deactivate all BOD channels.
 **********************************************************************************************************************/
void bsp_bod_deactivate (void)
{
    /* Mask POR. */
    uint32_t mask = FSP_REG_MSK(PMU_ANA, BOD_CTRL_REG, BOD_VDD_MASK) |
                    FSP_REG_MSK(PMU_ANA, BOD_CTRL_REG, BOD_V10_MASK) |
                    FSP_REG_MSK(PMU_ANA, BOD_CTRL_REG, BOD_V18_MASK) |
                    FSP_REG_MSK(PMU_ANA, BOD_CTRL_REG, BOD_V18EXT_MASK) |
                    FSP_REG_MSK(PMU_ANA, BOD_CTRL_REG, BOD_VBAT_MASK);
    FSP_REG_SET_MASKED(PMU_ANA, BOD_CTRL_REG, mask, mask);

    /* A stabilization delay is required between the mask and disable sequence.
     * Otherwise, an unexpected POR may be triggered. */
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);

    /* Disable comparator. */
    mask = FSP_REG_MSK(PMU_ANA, BOD_CTRL_REG, COMP_VDD_DISABLE) |
           FSP_REG_MSK(PMU_ANA, BOD_CTRL_REG, COMP_V10_DISABLE) |
           FSP_REG_MSK(PMU_ANA, BOD_CTRL_REG, COMP_V18_DISABLE) |
           FSP_REG_MSK(PMU_ANA, BOD_CTRL_REG, COMP_V18EXT_DISABLE) |
           FSP_REG_MSK(PMU_ANA, BOD_CTRL_REG, COMP_VBAT_DISABLE);
    FSP_REG_SET_MASKED(PMU_ANA, BOD_CTRL_REG, mask, mask);
}

/*******************************************************************************************************************//**
 * Activate BOD for a specific channel.
 *
 * @param[in] channel  BOD channel to activate.
 **********************************************************************************************************************/
void bsp_bod_activate_channel (bsp_bod_channel_t channel)
{
    BSP_CHECK_FATAL(channel >= BSP_BOD_CHANNEL_VDD && channel <= BSP_BOD_CHANNEL_VBAT);

    /* Enable comparator. */
    PMU_ANA->BOD_CTRL_REG &= ~(1U << (channel + BSP_BOD_BIT_DISTANCE_MASK_DISABLE));

    /* A stabilization delay is required between the enable and unmask sequence.
     * Otherwise, an unexpected POR may be triggered. */
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);

    /* Unmask POR. */
    PMU_ANA->BOD_CTRL_REG &= ~(1U << channel);
}

/*******************************************************************************************************************//**
 * Deactivate BOD for a specific channel.
 *
 * @param[in] channel  BOD channel to deactivate.
 **********************************************************************************************************************/
void bsp_bod_deactivate_channel (bsp_bod_channel_t channel)
{
    BSP_CHECK_FATAL(channel >= BSP_BOD_CHANNEL_VDD && channel <= BSP_BOD_CHANNEL_VBAT);

    /* Mask POR. */
    PMU_ANA->BOD_CTRL_REG |= 1U << channel;

    /* A stabilization delay is required between the mask and disable sequence.
     * Otherwise, an unexpected POR may be triggered. */
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);

    /* Disable comparator. */
    PMU_ANA->BOD_CTRL_REG |= 1U << (channel + BSP_BOD_BIT_DISTANCE_MASK_DISABLE);
}

/*******************************************************************************************************************//**
 * Get the configured voltage offset for a BOD channel.
 *
 * @param[in] channel  BOD channel excluding VBAT.
 *
 * @return Voltage offset compared to the nominal output voltage of the corresponding rail in millivolts.
 *
 * @note To get the configured VBAT voltage level, use bsp_bod_vbat_comparator_level_get().
 **********************************************************************************************************************/
int32_t bsp_bod_get_channel_voltage_level (bsp_bod_channel_t channel)
{
    uint32_t level;
    int32_t  voltage = 0;

    switch (channel)
    {
        case BSP_BOD_CHANNEL_VDD:
        {
            level   = PMU_ANA->BOD_CTRL_REG_b.BOD_LVL_VDD;
            voltage = (int32_t) level * BSP_BOD_CHANNEL_STEP_MILLIVOLTS + BSP_BOD_VDD_CHANNEL_OFFSET_MILLIVOLTS;
            break;
        }

        case BSP_BOD_CHANNEL_V10:
        {
            level   = PMU_ANA->BOD_CTRL_REG_b.BOD_LVL_V10;
            voltage = (int32_t) level * BSP_BOD_CHANNEL_STEP_MILLIVOLTS + BSP_BOD_V10_CHANNEL_OFFSET_MILLIVOLTS;
            break;
        }

        case BSP_BOD_CHANNEL_V18:
        {
            level   = PMU_ANA->BOD_CTRL_REG_b.BOD_LVL_V18;
            voltage = (int32_t) level * BSP_BOD_CHANNEL_STEP_MILLIVOLTS + BSP_BOD_V18_CHANNEL_OFFSET_MILLIVOLTS;
            break;
        }

        case BSP_BOD_CHANNEL_V18EXT:
        {
            level   = PMU_ANA->BOD_CTRL_REG_b.BOD_LVL_V18EXT;
            voltage = (int32_t) level * BSP_BOD_CHANNEL_STEP_MILLIVOLTS + BSP_BOD_V18_CHANNEL_OFFSET_MILLIVOLTS;
            break;
        }

        default:
        {
            BSP_CHECK_FATAL(0);
            break;
        }
    }

    return voltage;
}

/*******************************************************************************************************************//**
 * Set the voltage offset for a BOD channel.
 *
 * Valid ranges depend on the channel:
 *     VDD, V10: -100, -90, ..., -30 mV
 *     V18, V18EXT: -110, -100, ..., -40 mV
 *
 * @param[in] channel  BOD channel excluding VBAT.
 * @param[in] offset   Voltage offset compared to the nominal output voltage of the corresponding rail in millivolts.
 *
 * @note To set the VBAT voltage level, use bsp_bod_vbat_comparator_level_set().
 **********************************************************************************************************************/
void bsp_bod_set_channel_voltage_level (bsp_bod_channel_t channel, int32_t offset)
{
    uint32_t level;

    switch (channel)
    {
        case BSP_BOD_CHANNEL_VDD:
        {
            level = (uint32_t) ((offset - BSP_BOD_VDD_CHANNEL_OFFSET_MILLIVOLTS) / BSP_BOD_CHANNEL_STEP_MILLIVOLTS);
            BSP_CHECK_FATAL(level <= PMU_ANA_BOD_CTRL_REG_BOD_LVL_VDD_Msk >> PMU_ANA_BOD_CTRL_REG_BOD_LVL_VDD_Pos);
            PMU_ANA->BOD_CTRL_REG_b.BOD_LVL_VDD = level &
                                                  (PMU_ANA_BOD_CTRL_REG_BOD_LVL_VDD_Msk >>
                                                   PMU_ANA_BOD_CTRL_REG_BOD_LVL_VDD_Pos);
            break;
        }

        case BSP_BOD_CHANNEL_V10:
        {
            level = (uint32_t) ((offset - BSP_BOD_V10_CHANNEL_OFFSET_MILLIVOLTS) / BSP_BOD_CHANNEL_STEP_MILLIVOLTS);
            BSP_CHECK_FATAL(level <= PMU_ANA_BOD_CTRL_REG_BOD_LVL_V10_Msk >> PMU_ANA_BOD_CTRL_REG_BOD_LVL_V10_Pos);
            PMU_ANA->BOD_CTRL_REG_b.BOD_LVL_V10 = level &
                                                  (PMU_ANA_BOD_CTRL_REG_BOD_LVL_V10_Msk >>
                                                   PMU_ANA_BOD_CTRL_REG_BOD_LVL_V10_Pos);
            break;
        }

        case BSP_BOD_CHANNEL_V18:
        {
            level = (uint32_t) ((offset - BSP_BOD_V18_CHANNEL_OFFSET_MILLIVOLTS) / BSP_BOD_CHANNEL_STEP_MILLIVOLTS);
            BSP_CHECK_FATAL(level <= PMU_ANA_BOD_CTRL_REG_BOD_LVL_V18_Msk >> PMU_ANA_BOD_CTRL_REG_BOD_LVL_V18_Pos);
            PMU_ANA->BOD_CTRL_REG_b.BOD_LVL_V18 = level &
                                                  (PMU_ANA_BOD_CTRL_REG_BOD_LVL_V18_Msk >>
                                                   PMU_ANA_BOD_CTRL_REG_BOD_LVL_V18_Pos);
            break;
        }

        case BSP_BOD_CHANNEL_V18EXT:
        {
            level = (uint32_t) ((offset - BSP_BOD_V18_CHANNEL_OFFSET_MILLIVOLTS) / BSP_BOD_CHANNEL_STEP_MILLIVOLTS);
            BSP_CHECK_FATAL(level <=
                            PMU_ANA_BOD_CTRL_REG_BOD_LVL_V18EXT_Msk >> PMU_ANA_BOD_CTRL_REG_BOD_LVL_V18EXT_Pos);
            PMU_ANA->BOD_CTRL_REG_b.BOD_LVL_V18EXT = level &
                                                     (PMU_ANA_BOD_CTRL_REG_BOD_LVL_V18EXT_Msk >>
                                                      PMU_ANA_BOD_CTRL_REG_BOD_LVL_V18EXT_Pos);
            break;
        }

        default:
        {
            BSP_CHECK_FATAL(0);
            break;
        }
    }
}

/** @} (end addtogroup BSP_MCU) */
