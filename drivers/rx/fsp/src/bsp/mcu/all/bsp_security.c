/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

#if BSP_FEATURE_PZ_HAS_PROTECTZONE

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #define BSP_PRV_MS_REG_KEY        (0xA500U)
 #define FSP_NOT_DEFINED           (0)

/* Branch Instruction (BRA.B pcdsp:8) */
 #define BSP_PRV_INFINITE_LOOP     (0x2E00)

/* Protect DMAST/DTCST from nonsecure write access. */
 #define DMACX_REGISTER_SHIFT      (0)
 #define DTCX_REGISTER_SHIFT       (0)
 #define EXDMACX_REGISTER_SHIFT    (0)

/* Use legacy tail-chaining to find NS */
 #define RAM_NS_START              ((uint32_t *) ((((uint32_t) gp_ddsc_RAM_START + (BSP_FEATURE_SRAM_SIZE / 2)) & \
                                                   0xFFFFE000) & (~BSP_FEATURE_PZ_S_OFFSET)))
 #define LRAM_NS_START             ((uint32_t *) ((((uint32_t) gp_ddsc_LRAM_START + (BSP_FEATURE_LRAM_SIZE / 2)) & \
                                                   0xFFFFE000) & (~BSP_FEATURE_PZ_S_OFFSET)))

 #define RAM_NS_START_S_ALIAS      (uint32_t *) ((uint32_t) RAM_NS_START)
 #define LRAM_NS_START_S_ALIAS     (uint32_t *) ((uint32_t) LRAM_NS_START)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
void R_BSP_SAUInit(void);
void R_BSP_SecurityInit(void);
void R_BSP_PinCfgSecurityInit(void);
void R_BSP_ElcCfgSecurityInit(void);

/***********************************************************************************************************************
 * External symbols
 **********************************************************************************************************************/

 #if BSP_PZ_SECURE_BUILD

/*******************************************************************************************************************//**
 * Initialize SRAM/LRAM regions for ProtectZone.
 *
 * This function initializes security attributes for SRAM and LRAM.
 *
 * @note IDAU settings must be configured to match project settings with a separate configuration tool.
 **********************************************************************************************************************/
void R_BSP_SAUInit (void)
{
    /* Divide the SRAM area into S/NS. */
    R_CPSCU->SRAMSABAR0 = (uint32_t) RAM_NS_START_S_ALIAS & R_CPSCU_SRAMSABAR0_SRAMSABAR_Msk;
    R_CPSCU->SRAMSABAR1 = (uint32_t) RAM_NS_START_S_ALIAS & R_CPSCU_SRAMSABAR1_SRAMSABAR_Msk;

  #if BSP_FEATURE_BSP_HAS_LRAM == 1
    R_CPSCU->LRMSABAR0 = (uint32_t) LRAM_NS_START_S_ALIAS & R_CPSCU_LRMSABAR0_LRMSABA_Msk;
    if (BSP_FEATURE_LRAM0_SIZE > R_CPSCU->LRMSABAR0)
    {
        R_CPSCU->LRMSABAR1 = 0x00000000;
    }
    else
    {
        R_CPSCU->LRMSABAR1 = R_CPSCU->LRMSABAR0 - BSP_FEATURE_LRAM0_SIZE;
    }
  #endif
}

/*******************************************************************************************************************//**
 * Initialize security features for ProtectZone.
 *
 * This function initializes Renesas Security registers for secure projects.
 *
 * @note IDAU settings must be configured to match project settings with a separate configuration tool.
 **********************************************************************************************************************/
void R_BSP_SecurityInit (void)
{
    /* Disable PRCR for SARs. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SAR);

    /* Protected zone interrupts enabled */
    R_CPSCU->PRTZCR = 0x00000001;

    /* Prohibit Secure instruction access to Non-Secure area */
    R_SAU->AAS = 0x00000001;

    /* SAU initialization. */
    R_BSP_SAUInit();

    /* IVC Register setting(IVC.NSIC = 1) */
    /* Interrupts of level 15 or lower can only be accepted when the PSW.I bit is "1". */
    __asm volatile ("mvtc %0, ivc" : : "r" (0x01000000) :);

    /* Set ProtectZone filter exception response. */
    R_BUS->OAD.MSAPT  = BSP_PRV_MS_REG_KEY + 0U;
    R_BUS->OAD.MSAOAD = BSP_PRV_MS_REG_KEY + BSP_PZ_CFG_EXCEPTION_RESPONSE;
    R_BUS->OAD.MSAPT  = BSP_PRV_MS_REG_KEY + 1U;

    /* Initialize PSARs. */
    R_PSCU->PSARB = BSP_PZ_CFG_PSARB;
    FSP_HARDWARE_REGISTER_WAIT(R_PSCU->PSARB, BSP_PZ_CFG_PSARB);
    R_PSCU->PSARC = BSP_PZ_CFG_PSARC;
    FSP_HARDWARE_REGISTER_WAIT(R_PSCU->PSARC, BSP_PZ_CFG_PSARC);
    R_PSCU->PSARD = BSP_PZ_CFG_PSARD;
    FSP_HARDWARE_REGISTER_WAIT(R_PSCU->PSARD, BSP_PZ_CFG_PSARD);
    R_PSCU->PSARE = BSP_PZ_CFG_PSARE;
    FSP_HARDWARE_REGISTER_WAIT(R_PSCU->PSARE, BSP_PZ_CFG_PSARE);
    R_PSCU->PSARF = BSP_PZ_CFG_PSARF;
    FSP_HARDWARE_REGISTER_WAIT(R_PSCU->PSARF, BSP_PZ_CFG_PSARF);
    R_PSCU->MSSAR = BSP_PZ_CFG_MSSAR;
    FSP_HARDWARE_REGISTER_WAIT(R_PSCU->MSSAR, BSP_PZ_CFG_MSSAR);

    /* Initializing TFU security attributes */
  #ifdef __TFU_SECURE
    R_CPSCU->TFUSAR = 0x00000000;
  #else
    R_CPSCU->TFUSAR = 0x00000001;
  #endif

    /* Initializing EXDMAC security attributes */
    R_CPSCU->EXDMACCHSAR = BSP_PZ_CFG_EXDMACCHSAR;

    /* Initializing the security attributes of a cache. */
  #ifdef BSP_PZ_CFG_CACHESAR

    /* Cache Security Attribution. */
    R_CPSCU->CACHESAR = BSP_PZ_CFG_CACHESAR;
  #endif

  #ifdef BSP_PZ_CFG_IFUSAR

    /* Branch instruction processing accelerator Security Attribution. */
    R_CPSCU->IFUSAR = BSP_PZ_CFG_IFUSAR;
  #endif

    R_SYSTEM->RSTSAR = BSP_PZ_CFG_RSTSAR;                                 /* RSTSRn Security Attribution. */
    R_SYSTEM->PVDSAR = BSP_PZ_CFG_PVDSAR;                                 /* PVD Security Attribution. */
    R_SYSTEM->CGFSAR = BSP_PZ_CFG_CGFSAR;                                 /* CGC Security Attribution. */
    R_SYSTEM->LPMSAR = BSP_PZ_CFG_LPMSAR;                                 /* LPM Security Attribution. */

  #ifdef BSP_PZ_CFG_DPFSAR
    R_SYSTEM->DPFSAR = BSP_PZ_CFG_DPFSAR;                                 /* Deep Standby Interrupt Factor Security Attribution. */
  #endif

  #ifdef BSP_PZ_CFG_DPFSAR1
    R_SYSTEM->DPFSAR1 = BSP_PZ_CFG_DPFSAR1;                               /* Deep Standby Interrupt Factor Security Attribution. */
  #endif

  #ifdef BSP_PZ_CFG_RSCSAR
    R_SYSTEM->RSCSAR = BSP_PZ_CFG_RSCSAR;                                 /* RAM Standby Control Security Attribution. */
  #endif

  #ifdef BSP_PZ_CFG_PGCSAR
    R_SYSTEM->PGCSAR = BSP_PZ_CFG_PGCSAR;                                 /* Power Gating Control Security Attribution. */
  #endif

  #ifdef BSP_PZ_CFG_BKRSABR
    R_SYSTEM->BKRSABR = BSP_PZ_CFG_BKRSABR;                               /* Battery Backup Security Attribution. */
  #endif

  #ifdef BSP_PZ_CFG_VBSAR
    R_SYSTEM->VBSAR = BSP_PZ_CFG_VBSAR;                                   /* VBATT Backup register boundary address. */
  #endif

    R_CPSCU->ICUSARA = BSP_PZ_CFG_ICUSARA;                                /* External IRQ Security Attribution. */
    R_CPSCU->ICUSARB = BSP_PZ_CFG_ICUSARB;                                /* NMI Security Attribution. */
    R_CPSCU->ICUSARC = BSP_PZ_CFG_ICUSARC;                                /* CLPCR register Security Attribution. */
    R_CPSCU->ICUSARD = BSP_PZ_CFG_ICUSARD;                                /* Group IL0 Security Attribution. */

  #ifdef BSP_PZ_CFG_DMACCHSAR
    R_CPSCU->DMACCHSAR |= (BSP_PZ_CFG_DMACCHSAR << DMACX_REGISTER_SHIFT); /* DMAC Channel Security Attribution. */
  #endif

    R_CPSCU->ICU0SAR0 = BSP_PZ_CFG_ICU0SAR0;
    R_CPSCU->ICU0SAR1 = BSP_PZ_CFG_ICU0SAR1;
    R_CPSCU->ICU0SAR2 = BSP_PZ_CFG_ICU0SAR2;
    R_CPSCU->ICU0SAR3 = BSP_PZ_CFG_ICU0SAR3;
    R_CPSCU->ICU0SAR4 = BSP_PZ_CFG_ICU0SAR4;
    R_CPSCU->ICU0SAR5 = BSP_PZ_CFG_ICU0SAR5;
    R_CPSCU->ICU0SAR6 = BSP_PZ_CFG_ICU0SAR6;
    R_CPSCU->ICU0SAR7 = BSP_PZ_CFG_ICU0SAR7;

  #ifdef BSP_PZ_CFG_TEVTRCR
    R_CPSCU->TEVTRCR = BSP_PZ_CFG_TEVTRCR;   /* Trusted Event Route Enable. */
  #endif

  #ifdef BSP_PZ_CFG_ELCSARA
    R_ELC->ELCSARA = BSP_PZ_CFG_ELCSARA;     /* ELCR, ELSEGR0, ELSEGR1 Security Attribution. */
  #endif

  #ifdef BSP_PZ_CFG_MSAR
    R_MRAM->MSAR = BSP_PZ_CFG_MSAR;          /* MRAM Security Attribution. */
  #endif

    R_CPSCU->SRAMSAR = BSP_PZ_CFG_SRAMSAR;   /* SRAM Security Attribution. */

  #ifdef BSP_PZ_CFG_LRMSAR
    R_CPSCU->LRMSAR = BSP_PZ_CFG_LRMSAR;     /* LRAM Security Attribution. */
  #endif

    R_CPSCU->MMPUSARB = BSP_PZ_CFG_MMPUSARB; /* MMPUOAD, MMPUOADPT Security Attribution. */

    R_CPSCU->BUSSARA = BSP_PZ_CFG_BUSSARA;   /* Security Attribution Register A for the BUS Control Registers. */
    R_CPSCU->BUSSARB = BSP_PZ_CFG_BUSSARB;   /* Security Attribution Register B for the BUS Control Registers. */
    R_CPSCU->BUSSARC = BSP_PZ_CFG_BUSSARC;   /* Security Attribution Register C for the BUS Control Registers. */

  #if (defined(BSP_PZ_CFG_DMACCHSAR) && \
    ((BSP_PZ_CFG_DMACCHSAR & R_CPSCU_DMACCHSAR_all_Msk) != R_CPSCU_DMACCHSAR_all_Msk))
    R_BSP_MODULE_START(FSP_IP_DMAC, 0);

    /* If any DMAC channels are required by secure program, disable nonsecure write access to DMAST
     * in order to prevent the nonsecure program from disabling all DMAC channels. */
    R_CPSCU->DMACSAR &= ~(1U << DMACX_REGISTER_SHIFT); /* Protect DMAST from nonsecure write access. */

    /* Ensure that DMAST is set so that the nonsecure program can use DMA. */
    R_DMA->DMAST = 1U;
  #else

    /* On MCUs with this implementation of ProtectZone, DMACSAR security attribution is set to secure after reset.
     * If the DMAC is not used in the secure application,then configure DMAST security attribution to non-secure. */
    R_CPSCU->DMACSAR = 1U;
  #endif

  #if (defined(BSP_PZ_CFG_EXDMACCHSAR) &&                                                                \
    ((BSP_PZ_CFG_EXDMACCHSAR & (R_CPSCU_EXDMACCHSAR_SADMACX0_Msk | R_CPSCU_EXDMACCHSAR_SADMACX1_Msk)) != \
    (R_CPSCU_EXDMACCHSAR_SADMACX0_Msk | R_CPSCU_EXDMACCHSAR_SADMACX1_Msk)))
    R_BSP_MODULE_START(FSP_IP_EXDMAC, 0);

    /* If any EXDMAC channels are required by secure program, disable nonsecure write access to EDMAST
     * in order to prevent the nonsecure program from disabling all EXDMAC channels. */
    R_CPSCU->EXDMACSAR &= ~(1U << EXDMACX_REGISTER_SHIFT); /* Protect EDMAST from nonsecure write access. */

    /* Ensure that EDMAST is set so that the nonsecure program can use EXDMA. */
    R_EXDMA->EDMAST = 1U;
  #else

    /* On MCUs with this implementation of ProtectZone, EXDMACSAR security attribution is set to secure after reset.
     * If the EXDMAC is not used in the secure application,then configure EDMAST security attribution to non-secure. */
    R_CPSCU->EXDMACSAR = 1U;
  #endif

  #if BSP_PZ_CFG_DTC_USED
    R_BSP_MODULE_START(FSP_IP_DTC, 0);

    /* If the DTC is used by the secure program, disable nonsecure write access to DTCST
     * in order to prevent the nonsecure program from disabling all DTC transfers. */
    R_CPSCU->DTCSAR &= ~(1U << DTCX_REGISTER_SHIFT);

    /* Ensure that DTCST is set so that the nonsecure program can use DTC. */
    R_DTC->DTCST = 1U;
  #else

    /* On MCUs with this implementation of ProtectZone, DTCST security attribution is set to secure after reset.
     * If the DTC is not used in the secure application,then configure DTCST security attribution to non-secure. */
    R_CPSCU->DTCSAR |= (1U << DTCX_REGISTER_SHIFT);
  #endif

    /* Initialize security attribution registers for Pins. */
    R_BSP_PinCfgSecurityInit();

    /* Initialize security attribution registers for ELC. */
    R_BSP_ElcCfgSecurityInit();

    /* Reenable PRCR for SARs. */
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SAR);
}

/* This function is overridden by tooling. */
BSP_WEAK_REFERENCE void R_BSP_PinCfgSecurityInit (void)
{
}

/* This function is overridden by tooling. */
BSP_WEAK_REFERENCE void R_BSP_ElcCfgSecurityInit (void)
{
}

 #endif
#endif
