/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/** Used for holding reference counters for protection bits. */
volatile uint16_t g_protect_counters[4] BSP_SECTION_EARLY_INIT;

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/** Masks for setting or clearing the PRCR register. Use -1 for size because PWPR in MPC is used differently. */
static const uint16_t g_prcr_masks[] =
{
    0x0001U,                           /* PRC0. */
    0x0002U,                           /* PRC1. */
    0x0004U,                           /* PRC2. */
    0x0008U,                           /* PRC3. */
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_BSP_MCU
 *
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 *        Enable register protection. Registers that are protected cannot be written to. Register protection is
 *          enabled by using the Protect Register (PRCR) and the MPC's Write-Protect Register (PWPR).
 *
 * @param[in] regs_to_protect Registers which have write protection enabled.
 **********************************************************************************************************************/
void R_BSP_RegisterProtectEnable (bsp_reg_protect_t regs_to_protect)
{
    /** Get/save the current state of interrupts */
    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    FSP_HARDWARE_REGISTER_WAIT(BSP_SEMAPHORE_INTERNAL_CPU_STATE_READ_FOR_PROTECTION, BSP_RESOURCE_STATE_NOT_BEING_USED);

    /* Is it safe to disable write access? */
    if (0U != g_protect_counters[regs_to_protect])
    {
        /* Decrement the protect counter */
        g_protect_counters[regs_to_protect]--;
    }

    /* Is it safe to disable write access? */
    if (0U == g_protect_counters[regs_to_protect])
    {
        /** Enable protection using PRCR register.
         * When writing to the PRCR register the upper 8-bits must be the correct key.
         * Set lower bits to 0 to disable writes. */
        R_RWP_NS->PRCRN = ((R_RWP_NS->PRCRN | BSP_REG_PROTECT_PRCR_KEY) & (uint16_t) (~g_prcr_masks[regs_to_protect]));
        R_RWP_S->PRCRS  = ((R_RWP_S->PRCRS | BSP_REG_PROTECT_PRCR_KEY) & (uint16_t) (~g_prcr_masks[regs_to_protect]));
    }

    BSP_SEMAPHORE_INTERNAL_CPU_RELEASE_FOR_PROTECTION;

    /** Restore the interrupt state */
    FSP_CRITICAL_SECTION_EXIT;
}

/*******************************************************************************************************************//**
 *        Disable register protection. Registers that are protected cannot be written to. Register protection is
 *          disabled by using the Protect Register (PRCR) and the MPC's Write-Protect Register (PWPR).
 *
 * @param[in] regs_to_unprotect Registers which have write protection disabled.
 **********************************************************************************************************************/
void R_BSP_RegisterProtectDisable (bsp_reg_protect_t regs_to_unprotect)
{
    /** Get/save the current state of interrupts */
    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

#if !BSP_CFG_PORT_PROTECT

    /* If BSP_CFG_PORT_PROTECT is 0, GPIO protection is already disabled. In this case,
     * the function returns without doing anything. */
    if (BSP_REG_PROTECT_GPIO == regs_to_unprotect)
    {
        if ((R_RWP_NS->PRCRN & g_prcr_masks[regs_to_unprotect]) || (R_RWP_S->PRCRS & g_prcr_masks[regs_to_unprotect]))
        {
            /** Restore the interrupt state */
            FSP_CRITICAL_SECTION_EXIT;

            return;
        }
    }
#endif

    /* If g_protect_counters is 0, verify that the protect register is enabled before acquiring the semaphore. */
    if (0U == g_protect_counters[regs_to_unprotect])
    {
        bsp_regiser_protect_semaphore_take(g_prcr_masks[regs_to_unprotect]);
    }
    else
    {
        FSP_HARDWARE_REGISTER_WAIT(BSP_SEMAPHORE_INTERNAL_CPU_STATE_READ_FOR_PROTECTION,
                                   BSP_RESOURCE_STATE_NOT_BEING_USED);
    }

    /* If this is first entry then disable protection. */
    if (0U == g_protect_counters[regs_to_unprotect])
    {
        /** Disable protection using PRCR register.
         * When writing to the PRCR register the upper 8-bits must be the correct key.
         * Set lower bits to 0 to disable writes. */
        R_RWP_NS->PRCRN = ((R_RWP_NS->PRCRN | BSP_REG_PROTECT_PRCR_KEY) | g_prcr_masks[regs_to_unprotect]);
        R_RWP_S->PRCRS  = ((R_RWP_S->PRCRS | BSP_REG_PROTECT_PRCR_KEY) | g_prcr_masks[regs_to_unprotect]);
    }

    /** Increment the protect counter */
    g_protect_counters[regs_to_unprotect]++;

    BSP_SEMAPHORE_INTERNAL_CPU_RELEASE_FOR_PROTECTION;

    /** Restore the interrupt state */
    FSP_CRITICAL_SECTION_EXIT;
}

/** @} (end addtogroup BSP_MCU) */
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/*******************************************************************************************************************//**
 * Check the status of PRCRN and PRCRS, and then acquire the semaphore.
 *
 * @param[in]       prcr_masks          Mask the PRCR register.
 **********************************************************************************************************************/
void bsp_regiser_protect_semaphore_take (uint16_t prcr_masks)
{
    uint32_t timeout = BSP_CFG_PROTRCT_REG_POLLING_COUNT;

    do
    {
        /* If the protect register is "Write enabled", polling will continue because another core is operating. */
        if ((0U == (R_RWP_NS->PRCRN & prcr_masks)) && (0U == (R_RWP_S->PRCRS & prcr_masks)))
        {
            /* The semaphore will be acquired if it is available.
             * If not, polling of the protect register will be resumed. */
            if (BSP_RESOURCE_STATE_NOT_BEING_USED == BSP_SEMAPHORE_INTERNAL_CPU_STATE_READ_FOR_PROTECTION)
            {
                break;
            }
        }

        timeout--;
    } while (0U != timeout);

    if (0U == timeout)
    {
        FSP_HARDWARE_REGISTER_WAIT(BSP_SEMAPHORE_INTERNAL_CPU_STATE_READ_FOR_PROTECTION,
                                   BSP_RESOURCE_STATE_NOT_BEING_USED);
    }
}
