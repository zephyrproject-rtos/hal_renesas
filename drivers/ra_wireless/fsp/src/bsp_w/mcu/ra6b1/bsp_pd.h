/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_PD_RA6B1_H
#define BSP_PD_RA6B1_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#ifdef UNIT_TESTING
 #include "fake_regs.h"
#endif

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**
 * Number of Power Domain IDs defined for this device
 */
#define BSP_PD_ID_COUNT    (10)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Hardware power domains.
 */
typedef enum e_bsp_power_domain
{
    BSP_PD_AON = 0,                    ///< Always-on power domain
    BSP_PD_SYS,                        ///< System power domain
    BSP_PD_COM,                        ///< Communication power domain
    BSP_PD_MEM,                        ///< Memory power domain
    BSP_PD_TMR,                        ///< Timers power domain
    BSP_PD_PER,                        ///< Peripherals power domain
    BSP_PD_RAD,                        ///< Radio power domain
    BSP_PD_AUDIO,                      ///< Audio power domain
    BSP_PD_RTC,                        ///< Real-Time clock power domain
    BSP_PD_SLP,                        ///< Sleep power domain
} bsp_power_domain_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

uint32_t bsp_pd_id_get(bsp_power_domain_t power_domain);
void     bsp_pd_preferred_values_apply(bsp_power_domain_t power_domain);

/* Used internaly by bsp_pd.c */
void bsp_prv_pd_masks_get(bsp_power_domain_t power_domain, uint32_t * sleep_mask, uint32_t * is_up_mask);

/**
 * @brief Enable a power domain by clearing its sleep status bit
 *
 * @param [in] sleep_mask   mask for the power domain's SLEEP status bit
 * @param [in] is_aon       whether the power domain is part of the AON domain group
 *
 * @note    Multiple power domains may be enabled if more than one bits are set in \p sleep_mask
 */
__STATIC_INLINE void bsp_prv_pd_enable (uint32_t sleep_mask, bool is_aon)
{
    if (is_aon)
    {
        CRG_AON->PMU_AON_CTRL_REG &= ~sleep_mask;
    }
    else
    {
        CRG_TOP->PMU_CTRL_REG &= ~sleep_mask;
    }
}

/**
 * @brief Disable a power domain by setting its sleep status bit
 *
 * @param [in] sleep_mask   mask for the power domain's SLEEP status bit
 * @param [in] is_aon       whether the power domain is part of the AON domain group
 *
 * @note    Multiple power domains may be disabled if more than one bits are set in \p sleep_mask
 */
__STATIC_INLINE void bsp_prv_pd_disable (uint32_t sleep_mask, bool is_aon)
{
    if (is_aon)
    {
        CRG_AON->PMU_AON_CTRL_REG |= sleep_mask;
    }
    else
    {
        CRG_TOP->PMU_CTRL_REG |= sleep_mask;
    }
}

/**
 * @brief Check if a power domain by checking its is-up status bit
 *
 * @param [in] is_up_mask   mask for the power domain's IS_UP status bit
 *
 * @return  True iff the power domains corresponding to the set bits in \p is_up_mask are up.
 *
 * @note    Multiple power domains may be checked if more than one bits are set in \p is_up_mask
 */
__STATIC_INLINE bool bsp_prv_pd_is_up_check (uint32_t is_up_mask)
{
    return (CRG_TOP->SYS_STAT_REG & is_up_mask) == is_up_mask;
}

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
