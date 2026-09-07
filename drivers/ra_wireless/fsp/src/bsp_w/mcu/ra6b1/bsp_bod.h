/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_BOD_RA6B1_H
#define BSP_BOD_RA6B1_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** BOD channel identifier.
 *
 *  Each value corresponds to the bit position of the channel enable flag in PMU_ANA->BOD_CTRL_REG. */
typedef enum e_bsp_bod_channel
{
    BSP_BOD_CHANNEL_VDD    = 12,       ///< Core VDD
    BSP_BOD_CHANNEL_V10    = 13,       ///< 1.0 V IO rail
    BSP_BOD_CHANNEL_V18    = 14,       ///< 1.8 V IO rail
    BSP_BOD_CHANNEL_V18EXT = 15,       ///< 1.8 V IO to power external rail
    BSP_BOD_CHANNEL_VBAT   = 16,       ///< Battery supply
} bsp_bod_channel_t;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Deactivate all BOD channels.
 **********************************************************************************************************************/
void bsp_bod_deactivate(void);

/*******************************************************************************************************************//**
 * Activate BOD for a specific channel.
 *
 * @param[in] channel  BOD channel to activate.
 **********************************************************************************************************************/
void bsp_bod_activate_channel(bsp_bod_channel_t channel);

/*******************************************************************************************************************//**
 * Deactivate BOD for a specific channel.
 *
 * @param[in] channel  BOD channel to deactivate.
 **********************************************************************************************************************/
void bsp_bod_deactivate_channel(bsp_bod_channel_t channel);

/*******************************************************************************************************************//**
 * Get the configured voltage offset for a BOD channel.
 *
 * @param[in] channel  BOD channel excluding VBAT.
 *
 * @return Voltage offset compared to the nominal output voltage of the corresponding rail in millivolts.
 *
 * @note To get the configured VBAT voltage level, use bsp_bod_vbat_comparator_level_get().
 **********************************************************************************************************************/
int32_t bsp_bod_get_channel_voltage_level(bsp_bod_channel_t channel);

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
void bsp_bod_set_channel_voltage_level(bsp_bod_channel_t channel, int32_t offset);

/***********************************************************************************************************************
 * Inline Functions for VBAT comparator helpers — exclusive scope for r_lvd_w
 *
 *  The VBAT comparator shares bits in PMU_ANA->BOD_CTRL_REG with the BOD channel enable/disable bits.
 *  These helpers provide isolated access to the COMP_VBAT_* and BOD_VBAT_MASK fields so that r_lvd_w never touches
 *  BOD channel bits directly.
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable the VBAT BOD comparator.
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_bod_vbat_comparator_enable (void)
{
    PMU_ANA->BOD_CTRL_REG_b.COMP_VBAT_DISABLE = 0U;
}

/*******************************************************************************************************************//**
 * Disable the VBAT BOD comparator. Mask it before disabling, and insert a delay.
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_bod_vbat_comparator_disable (void)
{
    PMU_ANA->BOD_CTRL_REG_b.COMP_VBAT_DISABLE = 1U;
}

/*******************************************************************************************************************//**
 * Unmask the VBAT BOD channel.
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_bod_vbat_comparator_unmask (void)
{
    PMU_ANA->BOD_CTRL_REG_b.BOD_VBAT_MASK = 0U;
}

/*******************************************************************************************************************//**
 * Mask the VBAT BOD channel.
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_bod_vbat_comparator_mask (void)
{
    PMU_ANA->BOD_CTRL_REG_b.BOD_VBAT_MASK = 1U;
}

/*******************************************************************************************************************//**
 * Set the VBAT comparator threshold level.
 *
 * @param[in] level   Threshold level.
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_bod_vbat_comparator_level_set (lvd_threshold_t level)
{
    PMU_ANA->BOD_CTRL_REG_b.COMP_VBAT_LVL =
        level & (PMU_ANA_BOD_CTRL_REG_COMP_VBAT_LVL_Msk >> PMU_ANA_BOD_CTRL_REG_COMP_VBAT_LVL_Pos);
}

/*******************************************************************************************************************//**
 * Get the current VBAT comparator threshold level.
 **********************************************************************************************************************/
__STATIC_INLINE lvd_threshold_t bsp_bod_vbat_comparator_level_get (void)
{
    return (lvd_threshold_t) PMU_ANA->BOD_CTRL_REG_b.COMP_VBAT_LVL;
}

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_BOD_RA6B1_H */
