/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"                   /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */
#include "bsp_guard_driver.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/** Array of all PBG groups base address */
const uint32_t g_pbgprot_baseaddress[] =
{
    [BSP_PBG_GROUP_PBG00]   = (uint32_t) R_PBG00_BASE,
    [BSP_PBG_GROUP_PBG01]   = (uint32_t) R_PBG01_BASE,
    [BSP_PBG_GROUP_PBG10]   = (uint32_t) R_PBG10_BASE,
    [BSP_PBG_GROUP_PBG20]   = (uint32_t) R_PBG20_BASE,
    [BSP_PBG_GROUP_PBG21]   = (uint32_t) R_PBG21_BASE,
    [BSP_PBG_GROUP_PBG22]   = (uint32_t) R_PBG22_BASE,
    [BSP_PBG_GROUP_PBG23]   = (uint32_t) R_PBG23_BASE,
    [BSP_PBG_GROUP_PBG24]   = (uint32_t) R_PBG24_BASE,
    [BSP_PBG_GROUP_PBG30]   = (uint32_t) R_PBG30_BASE,
    [BSP_PBG_GROUP_PBG31]   = (uint32_t) R_PBG31_BASE,
    [BSP_PBG_GROUP_PBG32]   = (uint32_t) R_PBG32_BASE,
    [BSP_PBG_GROUP_PBG40]   = (uint32_t) R_PBG40_BASE,
    [BSP_PBG_GROUP_PBG41]   = (uint32_t) R_PBG41_BASE,
    [BSP_PBG_GROUP_PBG50]   = (uint32_t) R_PBG50_BASE,
    [BSP_PBG_GROUP_PBG51]   = (uint32_t) R_PBG51_BASE,
    [BSP_PBG_GROUP_PBG52]   = (uint32_t) R_PBG52_BASE,
    [BSP_PBG_GROUP_PBG60]   = (uint32_t) R_PBG60_BASE,
    [BSP_PBG_GROUP_PBG61]   = (uint32_t) R_PBG61_BASE,
    [BSP_PBG_GROUP_PBG62]   = (uint32_t) R_PBG62_BASE,
    [BSP_PBG_GROUP_PBG70]   = (uint32_t) R_PBG70_BASE,
    [BSP_PBG_GROUP_PBG71]   = (uint32_t) R_PBG71_BASE,
    [BSP_PBG_GROUP_PBG8H0]  = (uint32_t) R_PBG8H0_BASE,
    [BSP_PBG_GROUP_PBG8L0]  = (uint32_t) R_PBG8L0_BASE,
    [BSP_PBG_GROUP_PBG90]   = (uint32_t) R_PBG90_BASE,
    [BSP_PBG_GROUP_PBG91]   = (uint32_t) R_PBG91_BASE,
    [BSP_PBG_GROUP_PBG92]   = (uint32_t) R_PBG92_BASE,
    [BSP_PBG_GROUP_PBG100]  = (uint32_t) R_PBG100_BASE,
    [BSP_PBG_GROUP_PBG101]  = (uint32_t) R_PBG101_BASE,
    [BSP_PBG_GROUP_PBG11H0] = (uint32_t) R_PBG11H0_BASE,
    [BSP_PBG_GROUP_PBG11H1] = (uint32_t) R_PBG11H1_BASE,
    [BSP_PBG_GROUP_PBG11H2] = (uint32_t) R_PBG11H2_BASE,
    [BSP_PBG_GROUP_PBG11L0] = (uint32_t) R_PBG11L0_BASE,
    [BSP_HBG_GROUP_HBG90]   = (uint32_t) R_HBG90_BASE,
    [BSP_HBG_GROUP_HBG92]   = (uint32_t) R_HBG92_BASE,
    [BSP_HBG_GROUP_HBG94]   = (uint32_t) R_HBG94_BASE
};

/** Array of all PBG control groups base address */
const uint32_t g_pbgprot_control_baseaddress[] = /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_PBG_GROUP_PBG00]   = R_PBG00_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG01]   = R_PBG00_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG10]   = R_PBG10_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG20]   = R_PBG20_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG21]   = R_PBG20_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG22]   = R_PBG20_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG23]   = R_PBG20_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG24]   = R_PBG20_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG30]   = R_PBG30_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG31]   = R_PBG30_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG32]   = R_PBG30_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG40]   = R_PBG40_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG41]   = R_PBG40_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG50]   = R_PBG50_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG51]   = R_PBG50_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG52]   = R_PBG50_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG60]   = R_PBG60_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG61]   = R_PBG60_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG62]   = R_PBG62_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG70]   = R_PBG70_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG71]   = R_PBG70_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG8H0]  = R_PBG8H0_BASE,     /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG8L0]  = R_PBG8L0_BASE,     /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG90]   = R_PBG90_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG91]   = R_PBG91_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG92]   = R_PBG90_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG100]  = R_PBG100_BASE,     /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG101]  = R_PBG100_BASE,     /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG11H0] = R_PBG11H0_BASE,    /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG11H1] = R_PBG11H0_BASE,    /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG11H2] = R_PBG11H0_BASE,    /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_PBG_GROUP_PBG11L0] = R_PBG11L0_BASE,    /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_HBG_GROUP_HBG90]   = R_HBG90_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_HBG_GROUP_HBG92]   = R_HBG92_BASE,      /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    [BSP_HBG_GROUP_HBG94]   = R_HBG94_BASE       /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
};

/** Array of all PBG Key protection groups base address */
const uint32_t g_pbgkcprot_baseaddress[] =
{
    [BSP_PBG_GROUP_PBG00]   = (uint32_t) R_PBGERRSLV00_BASE,
    [BSP_PBG_GROUP_PBG01]   = (uint32_t) R_PBGERRSLV00_BASE,
    [BSP_PBG_GROUP_PBG10]   = (uint32_t) R_PBGERRSLV10_BASE,
    [BSP_PBG_GROUP_PBG20]   = (uint32_t) R_PBGERRSLV20_BASE,
    [BSP_PBG_GROUP_PBG21]   = (uint32_t) R_PBGERRSLV20_BASE,
    [BSP_PBG_GROUP_PBG22]   = (uint32_t) R_PBGERRSLV20_BASE,
    [BSP_PBG_GROUP_PBG23]   = (uint32_t) R_PBGERRSLV20_BASE,
    [BSP_PBG_GROUP_PBG24]   = (uint32_t) R_PBGERRSLV20_BASE,
    [BSP_PBG_GROUP_PBG30]   = (uint32_t) R_PBGERRSLV30_BASE,
    [BSP_PBG_GROUP_PBG31]   = (uint32_t) R_PBGERRSLV30_BASE,
    [BSP_PBG_GROUP_PBG32]   = (uint32_t) R_PBGERRSLV30_BASE,
    [BSP_PBG_GROUP_PBG40]   = (uint32_t) R_PBGERRSLV40_BASE,
    [BSP_PBG_GROUP_PBG41]   = (uint32_t) R_PBGERRSLV40_BASE,
    [BSP_PBG_GROUP_PBG50]   = (uint32_t) R_PBGERRSLV50_BASE,
    [BSP_PBG_GROUP_PBG51]   = (uint32_t) R_PBGERRSLV50_BASE,
    [BSP_PBG_GROUP_PBG52]   = (uint32_t) R_PBGERRSLV50_BASE,
    [BSP_PBG_GROUP_PBG60]   = (uint32_t) R_PBGERRSLV60_BASE,
    [BSP_PBG_GROUP_PBG61]   = (uint32_t) R_PBGERRSLV60_BASE,
    [BSP_PBG_GROUP_PBG62]   = (uint32_t) R_PBGERRSLV62_BASE,
    [BSP_PBG_GROUP_PBG70]   = (uint32_t) R_PBGERRSLV70_BASE,
    [BSP_PBG_GROUP_PBG71]   = (uint32_t) R_PBGERRSLV70_BASE,
    [BSP_PBG_GROUP_PBG8H0]  = (uint32_t) R_PBGERRSLV8H0_BASE,
    [BSP_PBG_GROUP_PBG8L0]  = (uint32_t) R_PBGERRSLV8L0_BASE,
    [BSP_PBG_GROUP_PBG90]   = (uint32_t) R_PBGERRSLV90_BASE,
    [BSP_PBG_GROUP_PBG91]   = (uint32_t) R_PBGERRSLV91_BASE,
    [BSP_PBG_GROUP_PBG92]   = (uint32_t) R_PBGERRSLV90_BASE,
    [BSP_PBG_GROUP_PBG100]  = (uint32_t) R_PBGERRSLV100_BASE,
    [BSP_PBG_GROUP_PBG101]  = (uint32_t) R_PBGERRSLV100_BASE,
    [BSP_PBG_GROUP_PBG11H0] = (uint32_t) R_PBGERRSLV11H0_BASE,
    [BSP_PBG_GROUP_PBG11H1] = (uint32_t) R_PBGERRSLV11H0_BASE,
    [BSP_PBG_GROUP_PBG11H2] = (uint32_t) R_PBGERRSLV11H0_BASE,
    [BSP_PBG_GROUP_PBG11L0] = (uint32_t) R_PBGERRSLV11L0_BASE,
    [BSP_HBG_GROUP_HBG90]   = (uint32_t) R_HBGERRSLV90_BASE,
    [BSP_HBG_GROUP_HBG92]   = (uint32_t) R_HBGERRSLV92_BASE,
    [BSP_HBG_GROUP_HBG94]   = (uint32_t) R_HBGERRSLV94_BASE
};

/** Array of all IBG control base address */
const uint32_t g_ibg_baseaddress[] =   /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_IBG_CONTROL_IPIR_Rn]  = (uint32_t) R_GUARD_IBG_IPIR_BASE,
    [BSP_IBG_CONTROL_IPIR_Tn]  = (uint32_t) R_GUARD_IBG_IPIR_BASE,
    [BSP_IBG_CONTROL_IPIR_4]   = (uint32_t) R_GUARD_IBG_IPIR_BASE,
    [BSP_IBG_CONTROL_BARR_n]   = (uint32_t) R_GUARD_IBG_BARR_BASE,
    [BSP_IBG_CONTROL_BARR_16]  = (uint32_t) R_GUARD_IBG_BARR_BASE,
    [BSP_IBG_CONTROL_TPTM_IFn] = (uint32_t) R_GUARD_IBG_TPTM_BASE,
    [BSP_IBG_CONTROL_TPTM_Un]  = (uint32_t) R_GUARD_IBG_TPTM_BASE,
    [BSP_IBG_CONTROL_TPTM_U8]  = (uint32_t) R_GUARD_IBG_TPTM_BASE,
    [BSP_IBG_CONTROL_TPTM_U9]  = (uint32_t) R_GUARD_IBG_TPTM_BASE,
};

/** Array of all IBG protection control base address */
const uint32_t g_ibgprot_baseaddress[] = /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_IBG_CONTROL_IPIR_Rn]  = (uint32_t) R_IBG00_IPIGPROT0_Rn_BASE,
    [BSP_IBG_CONTROL_IPIR_Tn]  = (uint32_t) R_IBG00_IPIGPROT0_Tn_BASE,
    [BSP_IBG_CONTROL_IPIR_4]   = (uint32_t) R_IBG00_IPIGPROT0_4_BASE,
    [BSP_IBG_CONTROL_BARR_n]   = (uint32_t) R_IBG01_BRGPROT0_n_BASE,
    [BSP_IBG_CONTROL_BARR_16]  = (uint32_t) R_IBG01_BRGPROT0_16_BASE,
    [BSP_IBG_CONTROL_TPTM_IFn] = (uint32_t) R_IBG02_TPTGPROT0_IFn_BASE,
    [BSP_IBG_CONTROL_TPTM_Un]  = (uint32_t) R_IBG02_TPTGPROT0_Un_BASE,
    [BSP_IBG_CONTROL_TPTM_U8]  = (uint32_t) R_IBG02_TPTGPROT0_U8_BASE,
    [BSP_IBG_CONTROL_TPTM_U9]  = (uint32_t) R_IBG02_TPTGPROT0_U9_BASE,
};

/** Array of all IBG module base address */
const uint32_t g_ibg_module_baseaddress[] = /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_GUARD_IPIR_MODULE] = (uint32_t) R_GUARD_IBG_IPIR_BASE,
    [BSP_GUARD_BARR_MODULE] = (uint32_t) R_GUARD_IBG_BARR_BASE,
    [BSP_GUARD_TPTM_MODULE] = (uint32_t) R_GUARD_IBG_TPTM_BASE,
};

/** Array of all PEG base address */
/* PRQA S 1510 ++ # DP_MSR_R-1.3_UC1 */
const uint32_t g_peg_baseaddress[] =   /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_PEG_CONTROL_PE0] = (uint32_t) R_GUARD_PE0_BASE,
    [BSP_PEG_CONTROL_PE1] = (uint32_t) R_GUARD_PE1_BASE,
    [BSP_PEG_CONTROL_PE2] = (uint32_t) R_GUARD_PE2_BASE,
#if (BSP_FEATURE_PE3_GUARD_IS_AVAILABLE)
    [BSP_PEG_CONTROL_PE3] = (uint32_t) R_GUARD_PE3_BASE,
#endif
};

/** Array of all PEGCAP_S base address */
const uint32_t g_pegcap_s_baseaddress[] = /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_PEG_CONTROL_PE0] = (uint32_t) R_PEGCAP_S_PE0CL0_BASE,
    [BSP_PEG_CONTROL_PE1] = (uint32_t) R_PEGCAP_S_PE1CL0_BASE,
    [BSP_PEG_CONTROL_PE2] = (uint32_t) R_PEGCAP_S_PE2CL1_BASE,
#if (BSP_FEATURE_PE3_GUARD_IS_AVAILABLE)
    [BSP_PEG_CONTROL_PE3] = (uint32_t) R_PEGCAP_S_PE3CL1_BASE,
#endif
};

/** Array of all PEGCAP_M base address */
const uint32_t g_pegcap_m_baseaddress[] = /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_PEG_CONTROL_PE0] = (uint32_t) R_PEGCAP_M_PE0CL0_BASE,
    [BSP_PEG_CONTROL_PE1] = (uint32_t) R_PEGCAP_M_PE1CL0_BASE,
    [BSP_PEG_CONTROL_PE2] = (uint32_t) R_PEGCAP_M_PE2CL1_BASE,
#if (BSP_FEATURE_PE3_GUARD_IS_AVAILABLE)
    [BSP_PEG_CONTROL_PE3] = (uint32_t) R_PEGCAP_M_PE3CL1_BASE,
#endif
};

/** Array of all Local Ram base address */
const uint32_t g_peg_lram_baseaddress[] = /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_PEG_CONTROL_PE0] = (uint32_t) R_GUARD_PE0_LRAM_BASE,
    [BSP_PEG_CONTROL_PE1] = (uint32_t) R_GUARD_PE1_LRAM_BASE,
    [BSP_PEG_CONTROL_PE2] = (uint32_t) R_GUARD_PE2_LRAM_BASE,
#if (BSP_FEATURE_PE3_GUARD_IS_AVAILABLE)
    [BSP_PEG_CONTROL_PE3] = (uint32_t) R_GUARD_PE3_LRAM_BASE,
#endif
};

/** Array of all CRG base address */
const uint32_t g_crg_baseaddress[] =   /* PRQA S 1533 # Advisory R-8.9 */
{
#if (BSP_FEATURE_CRAM0_GUARD_IS_AVAILABLE)
    [BSP_CRG_CONTROL_CRAM0] = (uint32_t) R_GUARD_CRAMCRG0_BASE,
#endif
#if (BSP_FEATURE_CRAM1_GUARD_IS_AVAILABLE)
    [BSP_CRG_CONTROL_CRAM1] = (uint32_t) R_GUARD_CRAMCRG1_BASE
#endif
};

/** Array of all Cluster Ram base address */
const uint32_t g_crg_cram_baseaddress[] = /* PRQA S 1533 # Advisory R-8.9 */
{
#if (BSP_FEATURE_CRAM0_GUARD_IS_AVAILABLE)
    [BSP_CRG_CONTROL_CRAM0] = (uint32_t) R_GUARD_CRG_CRAM0_BASE,
#endif
#if (BSP_FEATURE_CRAM1_GUARD_IS_AVAILABLE)
    [BSP_CRG_CONTROL_CRAM1] = (uint32_t) R_GUARD_CRG_CRAM1_BASE
#endif
};

/** Array of all CRG_CAP base address */
const uint32_t g_crgcap_baseaddress[][BSP_FEATURE_CRAM_GUARD_STATUS_MAX] = /* PRQA S 1533 # Advisory R-8.9 */
{
#if (BSP_FEATURE_CRAM0_GUARD_IS_AVAILABLE)
    [BSP_CRG_CONTROL_CRAM0] =
    {
    R_CRGCAP_CRAMHCL0_BASE,            /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_CRAMLCL0_BASE,            /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_SX2MBHCL0_BASE,           /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_SX2MBLCL0_BASE,           /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_PE0CL0_BASE,              /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_PE1CL0_BASE,              /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_PE2CL1_BASE,              /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
 #if (BSP_FEATURE_PE3_GUARD_IS_AVAILABLE)
    R_CRGCAP_PE3CL1_BASE               /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
 #endif
    },
#endif
#if (BSP_FEATURE_CRAM1_GUARD_IS_AVAILABLE)
    [BSP_CRG_CONTROL_CRAM1] =
    {
    R_CRGCAP_CRAMHCL1_BASE,            /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_CRAMLCL1_BASE,            /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_SX2MBHCL1_BASE,           /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_SX2MBLCL1_BASE,           /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_PE0CL0_BASE,              /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_PE1CL0_BASE,              /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
    R_CRGCAP_PE2CL1_BASE,              /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
 #if (BSP_FEATURE_PE3_GUARD_IS_AVAILABLE)
    R_CRGCAP_PE3CL1_BASE               /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
 #endif
    },
#endif
};

/** Array of all DMA Guard base address */
const uint32_t g_dmacg_baseaddress[] =
{
    [BSP_DMAG_UNIT_0] = (uint32_t) R_GUARD_DMAC0_BASE,
#if (BSP_FEATURE_DMAC_MAX_UNIT == 2)
    [BSP_DMAG_UNIT_1] = (uint32_t) R_GUARD_DMAC1_BASE
#endif
};

const bsp_module_pbg_info_t g_bsp_module_pbg_info_table[] = /* PRQA S 1533 # Advisory R-8.9 */
/* PRQA S 1510 -- */
{
    [BSP_GUARD_BSP_MODULE] =
            {
            .no_of_element     = 16,
            .initial_cfg_value = BSP_GUARD_BSP_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG00,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 |
                            BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_07)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG01,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 |
                            BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG10,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG20,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 |
                            BSP_PBG_CHANNEL_08) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG30,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG40,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG50,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG60,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG62,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG70,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG8H0,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG8L0,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG90,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG100,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11H0,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11L0,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            }
            }
            },
    [BSP_GUARD_BIST_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_BIST_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG20,
            .pbg_channel = (BSP_PBG_CHANNEL_04)
            }
            }
            },
    [BSP_GUARD_DMA_MODULE] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_DMA_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG00,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG90,
            .pbg_channel = (BSP_PBG_CHANNEL_06)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG40,
            .pbg_channel = (BSP_PBG_CHANNEL_15) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_DTS_MODULE] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_DTS_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG00,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG90,
            .pbg_channel = (BSP_PBG_CHANNEL_06)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG40,
            .pbg_channel = (BSP_PBG_CHANNEL_15) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_QOS_MODULE] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_QOS_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG00,
            .pbg_channel = (BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10)                       /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG01,
            .pbg_channel = (BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13)                                            /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG8L0,
            .pbg_channel = (BSP_PBG_CHANNEL_10)                                                                 /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_IOPORT_MODULE] =
            {
            .no_of_element     = 5,
            .initial_cfg_value = BSP_GUARD_IOPORT_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG20,
            .pbg_channel = (BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG21,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 |
                            BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07 |
                            BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15)  /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG22,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 |
                            BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07 |
                            BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15)  /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG23,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 |
                            BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07 |
                            BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15)  /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG24,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            }
            },
    [BSP_GUARD_DFE_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_DFE_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG30,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG40,
            .pbg_channel = (BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            }
            }
            },
#if (BSP_FEATURE_MMCA_IS_AVAILABLE)
    [BSP_GUARD_MMCA_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_MMCA_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG30,
            .pbg_channel = (BSP_PBG_CHANNEL_03)
            }
            }
            },
#endif                                 /* BSP_FEATURE_MMCA_IS_AVAILABLE */
#if (BSP_FEATURE_RDC3AS_IS_AVAILABLE)
    [BSP_GUARD_RDC3AS_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_RDC_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG30,
            .pbg_channel = (BSP_PBG_CHANNEL_05)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG40,
            .pbg_channel = (BSP_PBG_CHANNEL_04)
            }
            }
            },
#endif                                 /* #if (BSP_FEATURE_RDC3AS_IS_AVAILABLE) */ /* PRQA S 2053 # Advisory D-4.4 */
#if (BSP_FEATURE_RDC3AL_IS_AVAILABLE)
    [BSP_GUARD_RDC3AL_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_RDC_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG30,
            .pbg_channel = (BSP_PBG_CHANNEL_04)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG40,
            .pbg_channel = (BSP_PBG_CHANNEL_05)
            }
            }
            },
#endif                                 /* #if (BSP_FEATURE_RDC3AL_IS_AVAILABLE) */ /* PRQA S 2053 # Advisory D-4.4 */
    [BSP_GUARD_KCRC_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_KCRC_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG30,
            .pbg_channel = (BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG40,
            .pbg_channel = (BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07)
            }
            }
            },
    [BSP_GUARD_MSPI_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_MSPI_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG30,
            .pbg_channel = (BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 | BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_14)                                                                 /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG40,
            .pbg_channel = (BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 | BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15)                                            /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
#if (BSP_FEATURE_PSI5_IS_AVAILABLE)
    [BSP_GUARD_PSI5_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_PSI5_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG30,
            .pbg_channel = (BSP_PBG_CHANNEL_15) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG31,
            .pbg_channel = (BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 | BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05)
            }
            }
            },
#endif                                 /* BSP_FEATURE_PSI5_IS_AVAILABLE */
#if (BSP_FEATURE_PSI5S_IS_AVAILABLE)
    [BSP_GUARD_PSI5S_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_PSI5S_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG31,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            }
            }
            },
#endif                                 /* BSP_FEATURE_PSI5S_IS_AVAILABLE */
    [BSP_GUARD_RSENT_MODULE] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_RSENT_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG31,
            .pbg_channel = (BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_11 | BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_15)                                                                 /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG32,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 |
                            BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG41,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 |
                            BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07 |
                            BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 |                     /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_11 | BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_PIC_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_PIC_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG50,
            .pbg_channel = (BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            }
            }
            },
    [BSP_GUARD_LTSC_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_LTSC_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG50,
            .pbg_channel = (BSP_PBG_CHANNEL_05)
            }
            }
            },
    [BSP_GUARD_SWDT_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_SWDT_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG50,
            .pbg_channel = (BSP_PBG_CHANNEL_07)
            },
            }
            },
    [BSP_GUARD_ECM_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_ECM_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG50,
            .pbg_channel = (BSP_PBG_CHANNEL_08) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_TAUD_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_TAUD_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG50,
            .pbg_channel = (BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11H0,
            .pbg_channel = (BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06)
            }
            }
            },
    [BSP_GUARD_TAPA_MODULE] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_TAPA_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG50,
            .pbg_channel = (BSP_PBG_CHANNEL_15) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG51,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11H0,
            .pbg_channel = (BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            }
            },
    [BSP_GUARD_WDTB_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_WDTB_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG51,
            .pbg_channel = (BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11H0,
            .pbg_channel = (BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            }
            },
    [BSP_GUARD_OSTM_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_OSTM_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG51,
            .pbg_channel = (BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11H0,
            .pbg_channel = (BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_RLIN3_MODULE] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_RLIN3_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG51,
            .pbg_channel = (BSP_PBG_CHANNEL_11 | BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG8L0,
            .pbg_channel = (BSP_PBG_CHANNEL_06)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11H1,
            .pbg_channel = (BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_OTS_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_OTS_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG60,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            }
            }
            },
    [BSP_GUARD_EINT_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_EINT_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG60,
            .pbg_channel = (BSP_PBG_CHANNEL_03)
            }
            }
            },
    [BSP_GUARD_FLMD_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_FLMD_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG60,
            .pbg_channel = (BSP_PBG_CHANNEL_05)
            }
            }
            },
    [BSP_GUARD_RHSB_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_RHSB_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG60,
            .pbg_channel = (BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG70,
            .pbg_channel = (BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            }
            }
            },
    [BSP_GUARD_FCMP_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_FCMP_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG60,
            .pbg_channel = (BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 | BSP_PBG_CHANNEL_12 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_13)                                                                 /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_ADCK_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_ADCK_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG60,
            .pbg_channel = (BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG70,
            .pbg_channel = (BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07)
            }
            }
            },
    [BSP_GUARD_IFC_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_IFC_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG61,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG70,
            .pbg_channel = (BSP_PBG_CHANNEL_08) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_ABFG_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_ABFG_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG61,
            .pbg_channel = (BSP_PBG_CHANNEL_01)
            }
            }
            },
    [BSP_GUARD_AIR_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_AIR_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG61,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            }
            }
            },
    [BSP_GUARD_FCMPC_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_FCMPC_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG70,
            .pbg_channel = (BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 | BSP_PBG_CHANNEL_12 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14)                                            /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_DSADC_MODULE] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_DSADC_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG61,
            .pbg_channel = (BSP_PBG_CHANNEL_03 | BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_07 |
                            BSP_PBG_CHANNEL_08) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG70,
            .pbg_channel = (BSP_PBG_CHANNEL_15) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG71,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            }
            }
            },
    [BSP_GUARD_GTM_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_GTM_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG8H0,
            .pbg_channel = (BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 | BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 |
                            BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_10)                                                                 /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_ETHTSN_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_ETHTSN_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG8L0,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            }
            }
            },
    [BSP_GUARD_GPTP_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_GPTP_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG8L0,
            .pbg_channel = (BSP_PBG_CHANNEL_09) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
#if (BSP_FEATURE_DSMIF_IS_AVAILABLE)
    [BSP_GUARD_DSMIF_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_DSMIF_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG8L0,
            .pbg_channel = (BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
#endif                                                               /* BSP_FEATURE_DSMIF_IS_AVAILABLE */
#if (BSP_FEATURE_RHSIF_IS_AVAILABLE)
    [BSP_GUARD_RHSIF_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_RHSIF_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG90,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            {
            .pbg_group   = BSP_HBG_GROUP_HBG90,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            }
            }
            },
#endif                                 /* BSP_FEATURE_RHSIF_IS_AVAILABLE */
    [BSP_GUARD_ICUM_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_ICUM_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG90,
            .pbg_channel = (BSP_PBG_CHANNEL_04)
            }
            }
            },
    [BSP_GUARD_SPIDCTL_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_SPIDCTL_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG90,
            .pbg_channel = (BSP_PBG_CHANNEL_05)
            }
            }
            },
    [BSP_GUARD_INTIF_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_INTIF_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG90,
            .pbg_channel = (BSP_PBG_CHANNEL_06)
            }
            }
            },
#if (BSP_FEATURE_TSG3_EMU3S_IS_AVAILABLE)
    [BSP_GUARD_INTIF_EMU3S_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_EMU_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG90,
            .pbg_channel = (BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
#endif                                                               /* #if BSP_FEATURE_TSG3_EMU3S_IS_AVAILABLE */ /* PRQA S 2053 # Advisory D-4.4 */
#if (BSP_FEATURE_DFP_IS_AVAILABLE)
    [BSP_GUARD_DFP_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_DFP_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG90,
            .pbg_channel = (BSP_PBG_CHANNEL_09) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
#endif                                          /* BSP_FEATURE_DFP_IS_AVAILABLE */
    [BSP_GUARD_RSCAN_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_RSCAN_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG100,
            .pbg_channel = (BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 | BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 |
                            BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                            BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11)                                            /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_TSG3_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_TSG_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG50,
            .pbg_channel = (BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11H0,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            }
            }
            },
    [BSP_GUARD_ENCA_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_ENCA_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG50,
            .pbg_channel = (BSP_PBG_CHANNEL_04)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11H0,
            .pbg_channel = (BSP_PBG_CHANNEL_03)
            }
            }
            },
    [BSP_GUARD_TPBA_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_TPBA_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG50,
            .pbg_channel = (BSP_PBG_CHANNEL_06)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11H0,
            .pbg_channel = (BSP_PBG_CHANNEL_04)
            }
            }
            },
    [BSP_GUARD_ATU_VI_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_ATU_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11H1,
            .pbg_channel = (BSP_PBG_CHANNEL_03 | BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06)
            }
            }
            },
#if (BSP_FEATURE_RIIC_IS_AVAILABLE)
    [BSP_GUARD_RIIC_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_RIIC_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11L0,
            .pbg_channel = (BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            }
            }
            },
#endif                                 /* BSP_FEATURE_RIIC_IS_AVAILABLE */
    [BSP_GUARD_XBAR_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_XBAR_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11L0,
            .pbg_channel = (BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06)
            }
            }
            },
    [BSP_GUARD_HRPWM_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_HRPWM_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_PBG_GROUP_PBG11L0,
            .pbg_channel = (BSP_PBG_CHANNEL_08) /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            }
            }
            },
    [BSP_GUARD_FLXA_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_FLXA_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_HBG_GROUP_HBG92,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            }
            }
            },
    [BSP_GUARD_SFMA_MODULE] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_SFMA_WRITE_PROTECTION,
            .properties        = (bsp_module_pbg_properties_t[]) {
            {
            .pbg_group   = BSP_HBG_GROUP_HBG94,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            }
            }
            },
};

const bsp_module_ibg_info_t g_bsp_module_ibg_info_table[] = /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_GUARD_IPIR_MODULE] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_IBG_IPIR_WRITE_PROTECTION,
            .properties        = (bsp_module_ibg_properties_t[]) {
            {
            .ibg_control = BSP_IBG_CONTROL_IPIR_Rn,
            .ibg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            },
            {
            .ibg_control = BSP_IBG_CONTROL_IPIR_Tn,
            .ibg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            },
            {
            .ibg_control = BSP_IBG_CONTROL_IPIR_4,
            .ibg_channel = (BSP_PBG_CHANNEL_00)
            }
            }
            },
    [BSP_GUARD_BARR_MODULE] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_IBG_BARR_WRITE_PROTECTION,
            .properties        = (bsp_module_ibg_properties_t[]) {
            {
            .ibg_control = BSP_IBG_CONTROL_BARR_n,
            .ibg_channel =
                (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 |
                 BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07 |
                 BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 | /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
                 BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15)  /* PRQA S 0499 # DP_MSR_R-12.2_UC1 */
            },
            {
            .ibg_control = BSP_IBG_CONTROL_BARR_16,
            .ibg_channel = (BSP_PBG_CHANNEL_00)
            }
            }
            },
    [BSP_GUARD_TPTM_MODULE] =
            {
            .no_of_element     = 4,
            .initial_cfg_value = BSP_GUARD_IBG_TPTM_WRITE_PROTECTION,
            .properties        = (bsp_module_ibg_properties_t[]) {
#if (BSP_FEATURE_TPTMn_GUARD_MAX_CHANNEL == 3)
            {
            .ibg_control = BSP_IBG_CONTROL_TPTM_IFn,
            .ibg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02)
            },
            {
            .ibg_control = BSP_IBG_CONTROL_TPTM_Un,
            .ibg_channel =
                (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02)
            },
            {
            .ibg_control = BSP_IBG_CONTROL_TPTM_U8,
            .ibg_channel = (BSP_PBG_CHANNEL_00)
            },
            {
            .ibg_control = BSP_IBG_CONTROL_TPTM_U9,
            .ibg_channel = (BSP_PBG_CHANNEL_00)
            }
#elif (BSP_FEATURE_TPTMn_GUARD_MAX_CHANNEL == 4)
            {
            .ibg_control = BSP_IBG_CONTROL_TPTM_IFn,
            .ibg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            },
            {
            .ibg_control = BSP_IBG_CONTROL_TPTM_Un,
            .ibg_channel =
                (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            },
            {
            .ibg_control = BSP_IBG_CONTROL_TPTM_U8,
            .ibg_channel = (BSP_PBG_CHANNEL_00)
            },
            {
            .ibg_control = BSP_IBG_CONTROL_TPTM_U9,
            .ibg_channel = (BSP_PBG_CHANNEL_00)
            }
#endif
            }
            },
};

/* PRQA S 1510 ++ # DP_MSR_R-1.3_UC1 */
const bsp_intc1_lram_info_t g_bsp_intc1_lram_info_table[] = /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_PEG_CONTROL_PE0] =
    {
    .initial_cfg_value = BSP_GUARD_INTC1_LRAM_PE0_WRITE_PROTECTION,
    .lram_peg          = BSP_PEG_CONTROL_PE0,
    },
    [BSP_PEG_CONTROL_PE1] =
    {
    .initial_cfg_value = BSP_GUARD_INTC1_LRAM_PE1_WRITE_PROTECTION,
    .lram_peg          = BSP_PEG_CONTROL_PE1,
    },
    [BSP_PEG_CONTROL_PE2] =
    {
    .initial_cfg_value = BSP_GUARD_INTC1_LRAM_PE2_WRITE_PROTECTION,
    .lram_peg          = BSP_PEG_CONTROL_PE2,
    },
#if (BSP_FEATURE_PE3_GUARD_IS_AVAILABLE)
    [BSP_PEG_CONTROL_PE3] =
    {
    .initial_cfg_value = BSP_GUARD_INTC1_LRAM_PE3_WRITE_PROTECTION,
    .lram_peg          = BSP_PEG_CONTROL_PE3,
    }
#endif
};

const bsp_cram_info_t g_bsp_cram_info_table[] = /* PRQA S 1533 # Advisory R-8.9 */
{
    [BSP_CRG_CONTROL_CRAM0] =
    {
    .initial_cfg_value = BSP_GUARD_CRAM0_WRITE_PROTECTION,
    .cram_crg          = BSP_CRG_CONTROL_CRAM0,
    },
#if (BSP_FEATURE_CRAM1_GUARD_IS_AVAILABLE)
    [BSP_CRG_CONTROL_CRAM1] =
    {
    .initial_cfg_value = BSP_GUARD_CRAM1_WRITE_PROTECTION,
    .cram_crg          = BSP_CRG_CONTROL_CRAM1,
    },
#endif
};

/* PRQA S 1510 -- */
