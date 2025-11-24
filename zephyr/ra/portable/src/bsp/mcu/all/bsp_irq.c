/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/** ELC event definitions. */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_IRQ_UINT32_MAX       (0xFFFFFFFFU)
#define BSP_PRV_BITS_PER_WORD    (32)

#if (BSP_CFG_CPU_CORE == 1)
 #ifndef BSP_EVENT_NUM_TO_INTSELR
  #define BSP_EVENT_NUM_TO_INTSELR(x)         (x >> 5)
 #endif

 #ifndef BSP_EVENT_NUM_TO_INTSELR_MASK
  #define BSP_EVENT_NUM_TO_INTSELR_MASK(x)    (1 << (x % 32))
 #endif
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

void bsp_irq_cfg (void)
{
#if FSP_PRIV_TZ_USE_SECURE_REGS
 #if (BSP_FEATURE_TZ_VERSION == 2 && BSP_TZ_SECURE_BUILD == 0)
    /* On MCUs with this implementation of TrustZone, IRQ security attribution is set to secure by default.
     * This means that flat projects do not need to set security attribution to secure. */
 #else
    /* Unprotect security registers. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SAR);

  #if !BSP_TZ_SECURE_BUILD
    /* Set the DMAC channels to secure access. */
   #ifdef BSP_TZ_CFG_ICUSARC
    R_CPSCU->ICUSARC = ~R_CPSCU_ICUSARC_SADMACn_Msk;
   #endif
  #endif

    /* The Secure Attribute managed within the ARM CPU NVIC must match the security attribution of IELSEn
     * (Refer "ICUSARI : Interrupt Controller Unit Security Attribution Register I" description in the ICU section of the relevant hardware manual). */
  #if (BSP_CFG_CPU_CORE == 1)
    uint32_t volatile * p_icusarg = &R_CPSCU->ICUSARJ;
  #else
    uint32_t volatile * p_icusarg = &R_CPSCU->ICUSARG;
  #endif
    for (uint32_t i = 0U; i < BSP_ICU_VECTOR_MAX_ENTRIES / BSP_PRV_BITS_PER_WORD; i++)
    {
        p_icusarg[i]  = 0;
        NVIC->ITNS[i] = 0;
    }

    /* Protect security registers. */
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SAR);
 #endif
#endif
}
