/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "../all/internal/bsp_device_definitions_internal.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/**
 * @brief Get the SLEEP/IS_UP register-field masks of a power domain.
 *
 * @param [in]  power_domain    power domain
 * @param [out] sleep_mask      mask for the power domain's SLEEP status bit
 * @param [out] is_up_mask      mask for the power domain's IS_UP status bit
 *
 * @note    If \p power_domain is invalid, 0 is returned for both masks
 */
void bsp_prv_pd_masks_get (bsp_power_domain_t power_domain, uint32_t * sleep_mask, uint32_t * is_up_mask)
{
    switch (power_domain)
    {
        case BSP_PD_PER:
        {
            *sleep_mask = CRG_TOP_PMU_CTRL_REG_PERIPH_SLEEP_Msk;
            *is_up_mask = CRG_TOP_SYS_STAT_REG_PER_IS_UP_Msk;
            break;
        }

        case BSP_PD_RAD:
        {
            *sleep_mask = CRG_TOP_PMU_CTRL_REG_RADIO_SLEEP_Msk;
            *is_up_mask = CRG_TOP_SYS_STAT_REG_RAD_IS_UP_Msk;
            break;
        }

        case BSP_PD_TMR:
        {
            *sleep_mask = CRG_TOP_PMU_CTRL_REG_TIM_SLEEP_Msk;
            *is_up_mask = CRG_TOP_SYS_STAT_REG_TIM_IS_UP_Msk;
            break;
        }

        case BSP_PD_COM:
        {
            *sleep_mask = CRG_TOP_PMU_CTRL_REG_COM_SLEEP_Msk;
            *is_up_mask = CRG_TOP_SYS_STAT_REG_COM_IS_UP_Msk;
            break;
        }

        case BSP_PD_MEM:
        {
            *sleep_mask = 0;
            *is_up_mask = CRG_TOP_SYS_STAT_REG_MEM_IS_UP_Msk;
            break;
        }

        case BSP_PD_SYS:
        {
            *sleep_mask = CRG_TOP_PMU_CTRL_REG_SYS_SLEEP_Msk;
            *is_up_mask = CRG_TOP_SYS_STAT_REG_SYS_IS_UP_Msk;
            break;
        }

        case BSP_PD_AUDIO:
        {
            *sleep_mask = CRG_TOP_PMU_CTRL_REG_AUD_SLEEP_Msk;
            *is_up_mask = CRG_TOP_SYS_STAT_REG_AUD_IS_UP_Msk;
            break;
        }

        case BSP_PD_RTC:
        {
            *sleep_mask = CRG_AON_PMU_AON_CTRL_REG_RTC_SLEEP_Msk;
            *is_up_mask = CRG_AON_PMU_AON_CTRL_REG_RTC_IS_UP_Msk;
            break;
        }

        default:
        {
            *sleep_mask = 0;
            *is_up_mask = 0;
            break;
        }
    }
}

uint32_t bsp_pd_id_get (bsp_power_domain_t power_domain)
{
    uint32_t pd_id = (uint32_t) power_domain;

    BSP_CHECK_DEBUG(pd_id < BSP_PD_ID_COUNT);

    return pd_id;
}

/** @} (end addtogroup BSP_MCU) */
