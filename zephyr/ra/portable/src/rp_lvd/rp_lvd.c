/*
 * Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "rp_lvd.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define LVD_STABILIZATION_TIME_US    20U

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

#if (1U == BSP_FEATURE_LVD_VERSION)

/* Look-up tables for writing to monitor 1 and monitor 2 registers. */
static uint8_t volatile * const g_lvdncr0_lut[] = {&(R_SYSTEM->LVD1CR0), &(R_SYSTEM->LVD2CR0)};
static uint8_t volatile * const g_lvdncr1_lut[] = {&(R_SYSTEM->LVD1CR1), &(R_SYSTEM->LVD2CR1)};
static uint8_t volatile * const g_lvdnsr_lut[]  = {&(R_SYSTEM->LVD1SR), &(R_SYSTEM->LVD2SR)};
#elif (2U == BSP_FEATURE_LVD_VERSION)
static uint8_t volatile * const g_lvdnsr_lut[] = {&(R_SYSTEM->LVD1SR)};
#elif (3U == BSP_FEATURE_LVD_VERSION)

/* Look-up tables for writing to monitor 1, monitor 2, monitor 4, monitor 5, registers. monitor 3
 * registers are dummy variables. */
static uint8_t volatile * const g_lvdncr0_lut[] =
{
    &(R_SYSTEM->LVD1CR0), &(R_SYSTEM->LVD2CR0),
    &(R_SYSTEM->LVD3CR0), &(R_SYSTEM->LVD4CR0),
    &(R_SYSTEM->LVD5CR0)
};
static uint8_t volatile * const g_lvdncr1_lut[] =
{
    &(R_SYSTEM->LVD1CR1), &(R_SYSTEM->LVD2CR1),
    &(R_SYSTEM->LVD3CR1), &(R_SYSTEM->LVD4CR1),
    &(R_SYSTEM->LVD5CR1)
};
static uint8_t volatile * const g_lvdnsr_lut[] = {&(R_SYSTEM->LVD1SR), &(R_SYSTEM->LVD2SR)};
#endif

#if BSP_FEATURE_LVD_SUPPORT_RESET_ON_RISING_EDGE
 #if (3U == BSP_FEATURE_LVD_VERSION)
static uint8_t volatile * const g_lvdnfcr_lut[] =
{
    &(R_SYSTEM->LVD1FCR), &(R_SYSTEM->LVD2FCR),
    &(R_SYSTEM->LVD3FCR), &(R_SYSTEM->LVD4FCR),
    &(R_SYSTEM->LVD5FCR)
};
 #else
static uint8_t volatile * const g_lvdnfcr_lut[] = {&(R_SYSTEM->LVD1FCR), &(R_SYSTEM->LVD2FCR)};
 #endif
#endif

#if (BSP_FEATURE_LVD_HAS_LVDLVLR == 1)
static uint32_t const g_lvdlvlr_offset_lut[] =
{
    R_SYSTEM_LVDLVLR_LVD1LVL_Pos,
    R_SYSTEM_LVDLVLR_LVD2LVL_Pos
};
static uint32_t const g_lvdlvlr_mask_lut[] =
{
    R_SYSTEM_LVDLVLR_LVD1LVL_Msk,
    R_SYSTEM_LVDLVLR_LVD2LVL_Msk
};
#elif (1U == BSP_FEATURE_LVD_VERSION)
static uint8_t volatile * const g_lvdncmpcr_lut[] = {&(R_SYSTEM->LVD1CMPCR), &(R_SYSTEM->LVD2CMPCR)};
#elif (3U == BSP_FEATURE_LVD_VERSION)
static uint8_t volatile * const g_lvdncmpcr_lut[] =
{
    &(R_SYSTEM->LVD1CMPCR), &(R_SYSTEM->LVD2CMPCR),
    &(R_SYSTEM->LVD3CMPCR), &(R_SYSTEM->LVD4CMPCR),
    &(R_SYSTEM->LVD5CMPCR)
};
#endif

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable or disable LVD interrupt/reset response.
 *
 * @retval FSP_SUCCESS             Enable/Disable was successful.
 * @retval FSP_ERR_ASSERTION       p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Module not opened.
 **********************************************************************************************************************/
fsp_err_t RP_LVD_Enable (lvd_ctrl_t * const p_api_ctrl, bool enable)
{
    lvd_instance_ctrl_t * p_ctrl = (lvd_instance_ctrl_t *) p_api_ctrl;
    int channel_index            = p_ctrl->p_cfg->monitor_number - 1;

#if LVD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LVD);

    if (enable)
    {
        *g_lvdncr0_lut[channel_index] |= (R_SYSTEM_LVD1CR0_RIE_Msk);
    }
    else
    {
        *g_lvdncr0_lut[channel_index] &= ~(R_SYSTEM_LVD1CR0_RIE_Msk);
        *g_lvdnsr_lut[channel_index]  &= ~(R_SYSTEM_LVD1SR_DET_Msk);
    }

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LVD);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get the current status of the LVD response (reset/interrupt enabled).
 *
 * @retval FSP_SUCCESS             Get status was successful.
 * @retval FSP_ERR_ASSERTION       p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Module not opened.
 **********************************************************************************************************************/
fsp_err_t RP_LVD_IsEnable (lvd_ctrl_t * const p_api_ctrl, bool * is_enabled)
{
    lvd_instance_ctrl_t * p_ctrl = (lvd_instance_ctrl_t *) p_api_ctrl;
    int channel_index            = p_ctrl->p_cfg->monitor_number - 1;

#if LVD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(is_enabled);
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    *(is_enabled) = (bool) (*g_lvdncr0_lut[channel_index] & R_SYSTEM_LVD1CR0_RIE_Msk);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set LVD trigger edge.
 *
 * @retval FSP_SUCCESS                     Setting was successful.
 * @retval FSP_ERR_ASSERTION               p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN                Module not opened.
 * @retval FSP_ERR_INVALID_ARGUMENT        Trigger both edge when in reset action.
 **********************************************************************************************************************/
fsp_err_t RP_LVD_TriggerSet (lvd_ctrl_t * const p_api_ctrl, bool reset_action, lvd_voltage_slope_t voltage_slope)
{
    lvd_instance_ctrl_t * p_ctrl = (lvd_instance_ctrl_t *) p_api_ctrl;
    int channel_index            = p_ctrl->p_cfg->monitor_number - 1;

#if LVD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Reset response is not accepted in case voltage slope is both edges */
    FSP_ERROR_RETURN((reset_action == false) || (voltage_slope != LVD_VOLTAGE_SLOPE_BOTH),
                     FSP_ERR_INVALID_ARGUMENT);
#endif

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LVD);

    if (reset_action)
    {
        *g_lvdncmpcr_lut[channel_index] &= ~(R_SYSTEM_LVD1CMPCR_LVDE_Msk);
        *g_lvdnfcr_lut[channel_index]    = (voltage_slope == LVD_VOLTAGE_SLOPE_RISING);
        *g_lvdncmpcr_lut[channel_index] |= R_SYSTEM_LVD1CMPCR_LVDE_Msk;
        R_BSP_SoftwareDelay(LVD_STABILIZATION_TIME_US, BSP_DELAY_UNITS_MICROSECONDS);
    }
    else
    {
        *g_lvdncr1_lut[channel_index] &= ~(R_SYSTEM_LVD1CR1_IDTSEL_Msk);
        *g_lvdncr1_lut[channel_index] |=
            ((voltage_slope << R_SYSTEM_LVD1CR1_IDTSEL_Pos) & R_SYSTEM_LVD1CR1_IDTSEL_Msk);
    }

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LVD);

    return FSP_SUCCESS;
}
