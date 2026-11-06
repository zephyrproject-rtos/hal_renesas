/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MODULE_STANDBY_DRIVER_H
#define BSP_MODULE_STANDBY_DRIVER_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_MODULE_STANDBY_RSCFD_DEFAULT_VALUE         0x00000007UL                                    ///< Default standby value for RSCFD module
#define BSP_MODULE_STANDBY_FLXA_DEFAULT_VALUE          0x00000003UL                                    ///< Default standby value for FLXA module
#define BSP_MODULE_STANDBY_GTM_DEFAULT_VALUE           0x00000001UL                                    ///< Default standby value for GTM module
#define BSP_MODULE_STANDBY_ETN_DEFAULT_VALUE           0x00000017UL                                    ///< Default standby value for ETN module
#define BSP_MODULE_STANDBY_RSENT_DEFAULT_VALUE         0x3FFFFFFFUL                                    ///< Default standby value for RSENT module
#define BSP_MODULE_STANDBY_MSPI_DEFAULT_VALUE          0x000003FFUL                                    ///< Default standby value for MSPI module
#define BSP_MODULE_STANDBY_RLIN3_DEFAULT_VALUE         0x00FFFFFFUL                                    ///< Default standby value for RLIN3 module
#define BSP_MODULE_STANDBY_DSADC_CADC_DEFAULT_VALUE    0x00000000UL                                    ///< Default standby value for DSADC/CADC module
#define BSP_MODULE_STANDBY_ADCK_ISO_DEFAULT_VALUE      0x000000FFUL                                    ///< Default standby value for ADCK (ISO) module
#define BSP_MODULE_STANDBY_MMCA_DEFAULT_VALUE          0x00000001UL /* PRQA S 1534 # Advisory R-2.5 */ ///< Default standby value for MMCA module
#define BSP_MODULE_STANDBY_ENCA_DEFAULT_VALUE          0x00000003UL                                    ///< Default standby value for ENCA module
#define BSP_MODULE_STANDBY_PSI5_DEFAULT_VALUE          0x0000003FUL /* PRQA S 1534 # Advisory R-2.5 */ ///< Default standby value for PSI5 module
#define BSP_MODULE_STANDBY_PSI5S_DEFAULT_VALUE         0x00000003UL /* PRQA S 1534 # Advisory R-2.5 */ ///< Default standby value for PSI5S module
#define BSP_MODULE_STANDBY_RHSIF_DEFAULT_VALUE         0x00000003UL /* PRQA S 1534 # Advisory R-2.5 */ ///< Default standby value for RHSIF module
#define BSP_MODULE_STANDBY_RHSB_DEFAULT_VALUE          0x0000000FUL                                    ///< Default standby value for RHSB module
#define BSP_MODULE_STANDBY_RIIC_DEFAULT_VALUE          0x00000003UL /* PRQA S 1534 # Advisory R-2.5 */ ///< Default standby value for RIIC module
#define BSP_MODULE_STANDBY_SFMA_DEFAULT_VALUE          0x00000001UL                                    ///< Default standby value for SFMA module
#define BSP_MODULE_STANDBY_TAPA_DEFAULT_VALUE          0x0000003FUL                                    ///< Default standby value for TAPA module
#define BSP_MODULE_STANDBY_TAUD_DEFAULT_VALUE          0x0000000FUL                                    ///< Default standby value for TAUD module
#define BSP_MODULE_STANDBY_TPBA_DEFAULT_VALUE          0x00000003UL                                    ///< Default standby value for TPBA module
#define BSP_MODULE_STANDBY_TSG3_DEFAULT_VALUE          0x00000007UL                                    ///< Default standby value for TSG3 module
#define BSP_MODULE_STANDBY_OSTM_DEFAULT_VALUE          0x000003FFUL                                    ///< Default standby value for OSTM module
#define BSP_MODULE_STANDBY_ATU_DEFAULT_VALUE           0x00000001UL                                    ///< Default standby value for ATU module
#define BSP_MODULE_STANDBY_DFE_DEFAULT_VALUE           0x00000001UL                                    ///< Default standby value for DFE module
#define BSP_MODULE_STANDBY_DFP_DEFAULT_VALUE           0x00000000UL /* PRQA S 1534 # Advisory R-2.5 */ ///< Default standby value for DFP module
#define BSP_MODULE_STANDBY_RDC_DEFAULT_VALUE           0x0000000FUL                                    ///< Default standby value for RDC module
#define BSP_MODULE_STANDBY_FCOMP_DEFAULT_VALUE         0x000007FFUL                                    ///< Default standby value for FCOMP module
#define BSP_MODULE_STANDBY_EMU_DEFAULT_VALUE           0x00000003UL /* PRQA S 1534 # Advisory R-2.5 */ ///< Default standby value for EMU module
#define BSP_MODULE_STANDBY_HRPWM_DEFAULT_VALUE         0x00000001UL                                    ///< Default standby value for HRPWM module
#define BSP_MODULE_STANDBY_DSMIF_DEFAULT_VALUE         0x00000003UL /* PRQA S 1534 # Advisory R-2.5 */ ///< Default standby value for DSMIF module

#define BSP_MODULE_MSR_STPMSK_Pos                      (31U)                                           ///< Position of STPMSK bit in MSR register

#define BSP_PRV_MSRKCPROT_RESET                        0x00000000 /* PRQA S 1534 # Advisory R-2.5 */   ///< Reset value of MSRKCPROT register

/* Macro used for wake up enum */
/* Wake-up factor range end positions */
#define BSP_STANDBY_WAKE_UP_FACTOR_A0_END              32U /* PRQA S 1534 # Advisory R-2.5 */          ///< End index of wake-up factors for register A0
#define BSP_STANDBY_WAKE_UP_FACTOR_A1_END              64U /* PRQA S 1534 # Advisory R-2.5 */          ///< End index of wake-up factors for register A1
#define BSP_STANDBY_WAKE_UP_FACTOR_A2_END              96U /* PRQA S 1534 # Advisory R-2.5 */          ///< End index of wake-up factors for register A2
#define BSP_STANDBY_WAKE_UP_FACTOR_I0_END              128U /* PRQA S 1534 # Advisory R-2.5 */         ///< End index of wake-up factors for register I0
#define BSP_STANDBY_WAKE_UP_FACTOR_I1_END              160U /* PRQA S 1534 # Advisory R-2.5 */         ///< End index of wake-up factors for register I1
#define BSP_STANDBY_WAKE_UP_FACTOR_I2_END              192U /* PRQA S 1534 # Advisory R-2.5 */         ///< End index of wake-up factors for register I2
#define BSP_STANDBY_WAKE_UP_FACTOR_I3_END              224U /* PRQA S 1534 # Advisory R-2.5 */         ///< End index of wake-up factors for register I3

/* Wake-up factor start positions */
#define BSP_STANDBY_WAKE_UP_FACTOR_A0_START            0U                                              ///< Start index of wake-up factors for register A0
#define BSP_STANDBY_WAKE_UP_FACTOR_A1_START            32U                                             ///< Start index of wake-up factors for register A1
#define BSP_STANDBY_WAKE_UP_FACTOR_A2_START            64U                                             ///< Start index of wake-up factors for register A2
#define BSP_STANDBY_WAKE_UP_FACTOR_I0_START            96U                                             ///< Start index of wake-up factors for register I0
#define BSP_STANDBY_WAKE_UP_FACTOR_I1_START            128U                                            ///< Start index of wake-up factors for register I1
#define BSP_STANDBY_WAKE_UP_FACTOR_I2_START            160U                                            ///< Start index of wake-up factors for register I2
#define BSP_STANDBY_WAKE_UP_FACTOR_I3_START            192U                                            ///< Start index of wake-up factors for register I3

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU_RH850U2BX
 * @defgroup BSP_MODULE_STANDBY_U2BX BSP Module Standby
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Standby Module */
typedef enum e_bsp_module_standby                                            /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_MODULE_STANDBY_MSR_RSCFD,                                            ///< Standby module RSCFD (ISO)
    BSP_MODULE_STANDBY_MSR_FLXA,                                             ///< Standby module FLXA (ISO)
    BSP_MODULE_STANDBY_MSR_GTM,                                              ///< Standby module GTM (ISO)
    BSP_MODULE_STANDBY_MSR_ETN,                                              ///< Standby module ETN (ISO)
    BSP_MODULE_STANDBY_MSR_RSENT,                                            ///< Standby module RSENT (ISO)
    BSP_MODULE_STANDBY_MSR_MSPI,                                             ///< Standby module MSPI (ISO)
    BSP_MODULE_STANDBY_MSR_RLIN3,                                            ///< Standby module RLIN3 (ISO)
    BSP_MODULE_STANDBY_MSR_DSADC_CADC,                                       ///< Standby module DSADC/CADC (ISO)
    BSP_MODULE_STANDBY_MSR_ADCK_ISO,                                         ///< Standby module ADCK (ISO)
#if (BSP_FEATURE_MMCA_IS_AVAILABLE)
    BSP_MODULE_STANDBY_MSR_MMCA,                                             ///< Standby module MMCA (ISO)
#endif                                                                       /* BSP_FEATURE_MMCA_IS_AVAILABLE */
    BSP_MODULE_STANDBY_MSR_ENCA,                                             ///< Standby module ENCA (ISO)
#if (BSP_FEATURE_PSI5_IS_AVAILABLE)
    BSP_MODULE_STANDBY_MSR_PSI5,                                             ///< Standby module PSI5 (ISO)
#endif                                                                       /* BSP_FEATURE_PSI5_IS_AVAILABLE */
#if (BSP_FEATURE_PSI5S_IS_AVAILABLE)
    BSP_MODULE_STANDBY_MSR_PSI5S,                                            ///< Standby module PSI5S (ISO)
#endif                                                                       /* BSP_FEATURE_PSI5S_IS_AVAILABLE */
#if (BSP_FEATURE_RHSIF_IS_AVAILABLE)
    BSP_MODULE_STANDBY_MSR_RHSIF,                                            ///< Standby module RHSIF (ISO)
#endif                                                                       /* BSP_FEATURE_RHSIF_IS_AVAILABLE */
    BSP_MODULE_STANDBY_MSR_RHSB,                                             ///< Standby module RHSB (ISO)
#if (BSP_FEATURE_RIIC_IS_AVAILABLE)
    BSP_MODULE_STANDBY_MSR_RIIC,                                             ///< Standby module RIIC (ISO)
#endif                                                                       /* BSP_FEATURE_RIIC_IS_AVAILABLE */
    BSP_MODULE_STANDBY_MSR_SFMA,                                             ///< Standby module SFMA (ISO)
    BSP_MODULE_STANDBY_MSR_TAPA,                                             ///< Standby module TAPA (ISO)
    BSP_MODULE_STANDBY_MSR_TAUD,                                             ///< Standby module TAUD (ISO)
    BSP_MODULE_STANDBY_MSR_TPBA,                                             ///< Standby module TPBA (ISO)
    BSP_MODULE_STANDBY_MSR_TSG3,                                             ///< Standby module TSG3 (ISO)
    BSP_MODULE_STANDBY_MSR_OSTM,                                             ///< Standby module OSTM (ISO)
    BSP_MODULE_STANDBY_MSR_ATU,                                              ///< Standby module ATU (ISO)
    BSP_MODULE_STANDBY_MSR_DFE,                                              ///< Standby module DFE (ISO)
#if (BSP_FEATURE_DFP_IS_AVAILABLE)
    BSP_MODULE_STANDBY_MSR_DFP,                                              ///< Standby module DFP (ISO)
#endif                                                                       /* BSP_FEATURE_DFP_IS_AVAILABLE */
    BSP_MODULE_STANDBY_MSR_RDC,                                              ///< Standby module RDC (ISO)
    BSP_MODULE_STANDBY_MSR_FCOMP,                                            ///< Standby module FCOMP (ISO)
#if (BSP_FEATURE_EMU_IS_AVAILABLE)
    BSP_MODULE_STANDBY_MSR_EMU,                                              ///< Standby module EMU (ISO)
#endif
    BSP_MODULE_STANDBY_MSR_HRPWM,                                            ///< Standby module HRPWM (ISO)
#if (BSP_FEATURE_DSMIF_IS_AVAILABLE)
    BSP_MODULE_STANDBY_MSR_DSMIF,                                            ///< Standby module DSMIF (ISO)
#endif                                                                       /* BSP_FEATURE_DSMIF_IS_AVAILABLE */
    BSP_MODULE_STANDBY_TOTAL_INDEX_END                                       ///< End marker for standby module indices
} bsp_module_standby_t;

/** Operation mode in STOP mode */
typedef enum e_bsp_module_stopmode                                           /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_MODULE_OPERATION_MODE_RSCFD_ISO = BSP_MODULE_STANDBY_MSR_RSCFD,      ///< Operation mode RSCFD (ISO)
    BSP_MODULE_OPERATION_MODE_RLIN3_ISO = BSP_MODULE_STANDBY_MSR_RLIN3,      ///< Operation mode RLIN3 (ISO)
} bsp_module_stopmode_t;

/** Chip Standby Mode */
typedef enum e_bsp_module_stopmode_config                                    /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_MODULE_CLOCK_STOPPED  = 0U,                                          ///< Clock stopped for module
    BSP_MODULE_CLOCK_SUPPLIED = 1U                                           ///< Clock supplied for module
} bsp_module_stopmode_config_t;

/** Wake-up Factor for DeepStop */
typedef enum e_bsp_wk_factor                                                 /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_WK_FACTOR_NONE = 255U,                                               ///< No wake-up factor

    /* Wake-up factor for register A0 */
    BSP_WK_FACTOR_TNMI       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 0U,     ///< Wake-up source: TNMI
    BSP_WK_FACTOR_INTCLMATI0 = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 1U,     ///< Wake-up source: INTCLMATI0
    BSP_WK_FACTOR_INTCLMATI1 = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 2U,     ///< Wake-up source: INTCLMATI1
    BSP_WK_FACTOR_INTCLMATI2 = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 3U,     ///< Wake-up source: INTCLMATI2
    BSP_WK_FACTOR_INTWDTBA   = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 5U,     ///< Wake-up source: INTWDTBA
    BSP_WK_FACTOR_IRQ0       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 6U,     ///< Wake-up source: IRQ0
    BSP_WK_FACTOR_IRQ1       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 7U,     ///< Wake-up source: IRQ1
    BSP_WK_FACTOR_IRQ2       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 8U,     ///< Wake-up source: IRQ2
    BSP_WK_FACTOR_IRQ3       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 9U,     ///< Wake-up source: IRQ3
    BSP_WK_FACTOR_IRQ4       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 10U,    ///< Wake-up source: IRQ4
    BSP_WK_FACTOR_IRQ5       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 11U,    ///< Wake-up source: IRQ5
    BSP_WK_FACTOR_IRQ6       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 12U,    ///< Wake-up source: IRQ6
    BSP_WK_FACTOR_IRQ7       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 13U,    ///< Wake-up source: IRQ7
    BSP_WK_FACTOR_IRQ8       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 14U,    ///< Wake-up source: IRQ8
    BSP_WK_FACTOR_IRQ9       = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 15U,    ///< Wake-up source: IRQ9
    BSP_WK_FACTOR_IRQ10      = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 16U,    ///< Wake-up source: IRQ10
    BSP_WK_FACTOR_IRQ11      = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 17U,    ///< Wake-up source: IRQ11
    BSP_WK_FACTOR_IRQ12      = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 18U,    ///< Wake-up source: IRQ12
    BSP_WK_FACTOR_IRQ13      = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 19U,    ///< Wake-up source: IRQ13
    BSP_WK_FACTOR_IRQ14      = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 20U,    ///< Wake-up source: IRQ14
    BSP_WK_FACTOR_IRQ15      = BSP_STANDBY_WAKE_UP_FACTOR_A0_START + 21U,    ///< Wake-up source: IRQ15

    /* Wake-up factor for register A1 */
    BSP_WK_FACTOR_IRQ16 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 0U,          ///< Wake-up source: IRQ16
    BSP_WK_FACTOR_IRQ17 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 1U,          ///< Wake-up source: IRQ17
    BSP_WK_FACTOR_IRQ18 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 2U,          ///< Wake-up source: IRQ18
    BSP_WK_FACTOR_IRQ19 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 3U,          ///< Wake-up source: IRQ19
    BSP_WK_FACTOR_IRQ20 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 4U,          ///< Wake-up source: IRQ20
    BSP_WK_FACTOR_IRQ21 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 5U,          ///< Wake-up source: IRQ21
    BSP_WK_FACTOR_IRQ22 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 6U,          ///< Wake-up source: IRQ22
    BSP_WK_FACTOR_IRQ23 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 7U,          ///< Wake-up source: IRQ23
    BSP_WK_FACTOR_IRQ24 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 8U,          ///< Wake-up source: IRQ24
    BSP_WK_FACTOR_IRQ25 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 9U,          ///< Wake-up source: IRQ25
    BSP_WK_FACTOR_IRQ26 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 10U,         ///< Wake-up source: IRQ26
    BSP_WK_FACTOR_IRQ27 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 11U,         ///< Wake-up source: IRQ27
    BSP_WK_FACTOR_IRQ28 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 12U,         ///< Wake-up source: IRQ28
    BSP_WK_FACTOR_IRQ29 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 13U,         ///< Wake-up source: IRQ29
    BSP_WK_FACTOR_IRQ30 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 14U,         ///< Wake-up source: IRQ30
    BSP_WK_FACTOR_IRQ31 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 15U,         ///< Wake-up source: IRQ31
    BSP_WK_FACTOR_IRQ32 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 16U,         ///< Wake-up source: IRQ32
    BSP_WK_FACTOR_IRQ33 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 17U,         ///< Wake-up source: IRQ33
    BSP_WK_FACTOR_IRQ34 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 18U,         ///< Wake-up source: IRQ34
    BSP_WK_FACTOR_IRQ35 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 19U,         ///< Wake-up source: IRQ35
    BSP_WK_FACTOR_IRQ36 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 20U,         ///< Wake-up source: IRQ36
    BSP_WK_FACTOR_IRQ37 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 21U,         ///< Wake-up source: IRQ37
    BSP_WK_FACTOR_IRQ38 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 22U,         ///< Wake-up source: IRQ38
    BSP_WK_FACTOR_IRQ39 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 23U,         ///< Wake-up source: IRQ39
    BSP_WK_FACTOR_IRQ40 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 24U,         ///< Wake-up source: IRQ40
    BSP_WK_FACTOR_IRQ41 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 25U,         ///< Wake-up source: IRQ41
    BSP_WK_FACTOR_IRQ42 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 26U,         ///< Wake-up source: IRQ42
    BSP_WK_FACTOR_IRQ43 = BSP_STANDBY_WAKE_UP_FACTOR_A1_START + 27U,         ///< Wake-up source: IRQ43

    /* Wake-up factor for register A2 */
    BSP_WK_FACTOR_WUTRG0     = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 0U,     ///< Wake-up source: WUTRG0
    BSP_WK_FACTOR_WUTRG1     = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 1U,     ///< Wake-up source: WUTRG1
    BSP_WK_FACTOR_INTDCUTDI  = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 2U,     ///< Wake-up source: INTDCUTDI
    BSP_WK_FACTOR_INTTAUJ2I0 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 3U,     ///< Wake-up source: INTTAUJ2I0
    BSP_WK_FACTOR_INTTAUJ2I1 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 4U,     ///< Wake-up source: INTTAUJ2I1
    BSP_WK_FACTOR_INTTAUJ2I2 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 5U,     ///< Wake-up source: INTTAUJ2I2
    BSP_WK_FACTOR_INTTAUJ2I3 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 6U,     ///< Wake-up source: INTTAUJ2I3
    BSP_WK_FACTOR_INTTAUJ3I0 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 7U,     ///< Wake-up source: INTTAUJ3I0
    BSP_WK_FACTOR_INTTAUJ3I1 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 8U,     ///< Wake-up source: INTTAUJ3I1
    BSP_WK_FACTOR_INTTAUJ3I2 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 9U,     ///< Wake-up source: INTTAUJ3I2
    BSP_WK_FACTOR_INTTAUJ3I3 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 10U,    ///< Wake-up source: INTTAUJ3I3
    BSP_WK_FACTOR_INTRTCA01S = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 11U,    ///< Wake-up source: INTRTCA01S
    BSP_WK_FACTOR_INTRTCA0AL = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 12U,    ///< Wake-up source: INTRTCA0AL
    BSP_WK_FACTOR_INTRTCA0R  = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 13U,    ///< Wake-up source: INTRTCA0R
    BSP_WK_FACTOR_INTADCKAI0 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 14U,    ///< Wake-up source: INTADCKAI0
    BSP_WK_FACTOR_INTADCKAI1 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 15U,    ///< Wake-up source: INTADCKAI1
    BSP_WK_FACTOR_INTADCKAI2 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 16U,    ///< Wake-up source: INTADCKAI2
    BSP_WK_FACTOR_INTADCKAI3 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 17U,    ///< Wake-up source: INTADCKAI3
    BSP_WK_FACTOR_INTADCKAI4 = BSP_STANDBY_WAKE_UP_FACTOR_A2_START + 18U,    ///< Wake-up source: INTADCKAI4

    /* Wake-up factor for register I0 */
    BSP_WK_FACTOR_INTRCANGRECC0 = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 0U,  ///< Wake-up source: INTRCANGRECC0
    BSP_WK_FACTOR_INTRCAN0REC   = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 1U,  ///< Wake-up source: INTRCAN0REC
    BSP_WK_FACTOR_INTRCAN1REC   = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 2U,  ///< Wake-up source: INTRCAN1REC
    BSP_WK_FACTOR_INTRCAN2REC   = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 3U,  ///< Wake-up source: INTRCAN2REC
    BSP_WK_FACTOR_INTRCAN3REC   = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 4U,  ///< Wake-up source: INTRCAN3REC
    BSP_WK_FACTOR_INTRCAN4REC   = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 5U,  ///< Wake-up source: INTRCAN4REC
    BSP_WK_FACTOR_INTRCAN5REC   = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 6U,  ///< Wake-up source: INTRCAN5REC
    BSP_WK_FACTOR_INTRCAN6REC   = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 7U,  ///< Wake-up source: INTRCAN6REC
    BSP_WK_FACTOR_INTRCAN7REC   = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 8U,  ///< Wake-up source: INTRCAN7REC
    BSP_WK_FACTOR_INTRCANGRECC1 = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 9U,  ///< Wake-up source: INTRCANGRECC1
    BSP_WK_FACTOR_INTRCAN8REC   = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 10U, ///< Wake-up source: INTRCAN8REC
    BSP_WK_FACTOR_INTRCAN9REC   = BSP_STANDBY_WAKE_UP_FACTOR_I0_START + 11U, ///< Wake-up source: INTRCAN9REC

    /* Wake-up factor for register I1 */
    BSP_WK_FACTOR_INTRLIN30  = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 0U,     ///< Wake-up source: INTRLIN30
    BSP_WK_FACTOR_INTRLIN31  = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 1U,     ///< Wake-up source: INTRLIN31
    BSP_WK_FACTOR_INTRLIN32  = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 2U,     ///< Wake-up source: INTRLIN32
    BSP_WK_FACTOR_INTRLIN33  = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 3U,     ///< Wake-up source: INTRLIN33
    BSP_WK_FACTOR_INTRLIN34  = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 4U,     ///< Wake-up source: INTRLIN34
    BSP_WK_FACTOR_INTRLIN35  = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 5U,     ///< Wake-up source: INTRLIN35
    BSP_WK_FACTOR_INTRLIN36  = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 6U,     ///< Wake-up source: INTRLIN36
    BSP_WK_FACTOR_INTRLIN37  = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 7U,     ///< Wake-up source: INTRLIN37
    BSP_WK_FACTOR_INTRLIN38  = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 8U,     ///< Wake-up source: INTRLIN38
    BSP_WK_FACTOR_INTRLIN39  = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 9U,     ///< Wake-up source: INTRLIN39
    BSP_WK_FACTOR_INTRLIN310 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 10U,    ///< Wake-up source: INTRLIN310
    BSP_WK_FACTOR_INTRLIN311 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 11U,    ///< Wake-up source: INTRLIN311
    BSP_WK_FACTOR_INTRLIN312 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 12U,    ///< Wake-up source: INTRLIN312
    BSP_WK_FACTOR_INTRLIN313 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 13U,    ///< Wake-up source: INTRLIN313
    BSP_WK_FACTOR_INTRLIN314 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 14U,    ///< Wake-up source: INTRLIN314
    BSP_WK_FACTOR_INTRLIN315 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 15U,    ///< Wake-up source: INTRLIN315
    BSP_WK_FACTOR_INTRLIN316 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 16U,    ///< Wake-up source: INTRLIN316
    BSP_WK_FACTOR_INTRLIN317 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 17U,    ///< Wake-up source: INTRLIN317
    BSP_WK_FACTOR_INTRLIN318 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 18U,    ///< Wake-up source: INTRLIN318
    BSP_WK_FACTOR_INTRLIN319 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 19U,    ///< Wake-up source: INTRLIN319
    BSP_WK_FACTOR_INTRLIN320 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 20U,    ///< Wake-up source: INTRLIN320
    BSP_WK_FACTOR_INTRLIN321 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 21U,    ///< Wake-up source: INTRLIN321
    BSP_WK_FACTOR_INTRLIN322 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 22U,    ///< Wake-up source: INTRLIN322
    BSP_WK_FACTOR_INTRLIN323 = BSP_STANDBY_WAKE_UP_FACTOR_I1_START + 23U,    ///< Wake-up source: INTRLIN323

    /* Wake-up factor for register I2 */
    BSP_WK_FACTOR_INTRCAN0VMRX = BSP_STANDBY_WAKE_UP_FACTOR_I2_START + 1U,   ///< Wake-up source: INTRCAN0VMRX
    BSP_WK_FACTOR_INTRCAN1VMRX = BSP_STANDBY_WAKE_UP_FACTOR_I2_START + 2U,   ///< Wake-up source: INTRCAN1VMRX
    BSP_WK_FACTOR_INTRCAN2VMRX = BSP_STANDBY_WAKE_UP_FACTOR_I2_START + 3U,   ///< Wake-up source: INTRCAN2VMRX
    BSP_WK_FACTOR_INTRCAN3VMRX = BSP_STANDBY_WAKE_UP_FACTOR_I2_START + 4U,   ///< Wake-up source: INTRCAN3VMRX
    BSP_WK_FACTOR_INTRCAN4VMRX = BSP_STANDBY_WAKE_UP_FACTOR_I2_START + 5U,   ///< Wake-up source: INTRCAN4VMRX
    BSP_WK_FACTOR_INTRCAN5VMRX = BSP_STANDBY_WAKE_UP_FACTOR_I2_START + 6U,   ///< Wake-up source: INTRCAN5VMRX
    BSP_WK_FACTOR_INTRCAN6VMRX = BSP_STANDBY_WAKE_UP_FACTOR_I2_START + 7U,   ///< Wake-up source: INTRCAN6VMRX
    BSP_WK_FACTOR_INTRCAN7VMRX = BSP_STANDBY_WAKE_UP_FACTOR_I2_START + 8U,   ///< Wake-up source: INTRCAN7VMRX
    BSP_WK_FACTOR_INTRCAN8VMRX = BSP_STANDBY_WAKE_UP_FACTOR_I2_START + 10U,  ///< Wake-up source: INTRCAN8VMRX
    BSP_WK_FACTOR_INTRCAN9VMRX = BSP_STANDBY_WAKE_UP_FACTOR_I2_START + 11U,  ///< Wake-up source: INTRCAN9VMRX

    /* Wake-up factor for register I3 */
    BSP_WK_FACTOR_INTETNE05 = BSP_STANDBY_WAKE_UP_FACTOR_I3_START + 0U,      ///< Wake-up source: INTETNE05
    BSP_WK_FACTOR_INTETNE06 = BSP_STANDBY_WAKE_UP_FACTOR_I3_START + 2U       ///< Wake-up source: INTETNE06
} bsp_wk_factor_t;

/** IO Hold */
typedef enum e_bsp_io_hold                                                   /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_IO_HOLD_P00 = (0U),                                                  ///< IO hold for P00
    BSP_IO_HOLD_P01 = (1U),                                                  ///< IO hold for P01
    BSP_IO_HOLD_P02 = (2U),                                                  ///< IO hold for P02
    BSP_IO_HOLD_P03 = (3U),                                                  ///< IO hold for P03

    BSP_IO_HOLD_P10 = (10U),                                                 ///< IO hold for P10
    BSP_IO_HOLD_P11 = (11U),                                                 ///< IO hold for P11
    BSP_IO_HOLD_P12 = (12U),                                                 ///< IO hold for P12
    BSP_IO_HOLD_P13 = (13U),                                                 ///< IO hold for P13
    BSP_IO_HOLD_P14 = (14U),                                                 ///< IO hold for P14
    BSP_IO_HOLD_P15 = (15U),                                                 ///< IO hold for P15

    BSP_IO_HOLD_P20 = (20U),                                                 ///< IO hold for P20
    BSP_IO_HOLD_P21 = (21U),                                                 ///< IO hold for P21
    BSP_IO_HOLD_P22 = (22U),                                                 ///< IO hold for P22
    BSP_IO_HOLD_P23 = (23U),                                                 ///< IO hold for P23
    BSP_IO_HOLD_P24 = (24U),                                                 ///< IO hold for P24
    BSP_IO_HOLD_P25 = (25U),                                                 ///< IO hold for P25

    BSP_IO_HOLD_P30 = (30U),                                                 ///< IO hold for P30
    BSP_IO_HOLD_P32 = (32U),                                                 ///< IO hold for P32
    BSP_IO_HOLD_P34 = (34U),                                                 ///< IO hold for P34

    BSP_IO_HOLD_CLEAR_ALL = 0xFFU                                            ///< Clear IO hold for all pins
} bsp_io_hold_t;                                                             /* PRQA S 1535 # Advisory R-2.3 */

/** Wake-up register */
typedef enum e_bsp_wk_reg                                                    /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_WK_REG_WUFMSK_A0,                                                    ///< Wake-up mask register A0
    BSP_WK_REG_WUFMSK_A1,                                                    ///< Wake-up mask register A1
    BSP_WK_REG_WUFMSK_A2,                                                    ///< Wake-up mask register A2
    BSP_WK_REG_WUFMSK_I0,                                                    ///< Wake-up mask register I0
    BSP_WK_REG_WUFMSK_I1,                                                    ///< Wake-up mask register I1
    BSP_WK_REG_WUFMSK_I2,                                                    ///< Wake-up mask register I2
    BSP_WK_REG_WUFMSK_I3,                                                    ///< Wake-up mask register I3

    BSP_WK_REG_WUFC_A0,                                                      ///< Wake-up flag clear register A0
    BSP_WK_REG_WUFC_A1,                                                      ///< Wake-up flag clear register A1
    BSP_WK_REG_WUFC_A2,                                                      ///< Wake-up flag clear register A2
    BSP_WK_REG_WUFC_I0,                                                      ///< Wake-up flag clear register I0
    BSP_WK_REG_WUFC_I1,                                                      ///< Wake-up flag clear register I1
    BSP_WK_REG_WUFC_I2,                                                      ///< Wake-up flag clear register I2
    BSP_WK_REG_WUFC_I3,                                                      ///< Wake-up flag clear register I3

    BSP_WK_REG_WUF_A0,                                                       ///< Wake-up flag register A0
    BSP_WK_REG_WUF_A1,                                                       ///< Wake-up flag register A1
    BSP_WK_REG_WUF_A2,                                                       ///< Wake-up flag register A2
    BSP_WK_REG_WUF_I0,                                                       ///< Wake-up flag register I0
    BSP_WK_REG_WUF_I1,                                                       ///< Wake-up flag register I1
    BSP_WK_REG_WUF_I2,                                                       ///< Wake-up flag register I2
    BSP_WK_REG_WUF_I3                                                        ///< Wake-up flag register I3
} bsp_wk_reg_t;                                                              /* PRQA S 1535 # Advisory R-2.3 */

/** @} (end addtogroup BSP_MODULE_STANDBY) */

/** Module standby configuration */
typedef struct st_bsp_module_standby_info         /* PRQA S 1536 # Advisory R-2.4 */
{
    volatile uint32_t * msr_reg_address;          ///< Address of the Module Stop Register (MSR) for this module.
    const uint32_t      default_value;            /// Default value for module.
    const uint32_t      initial_cfg_value;        ///< Configured value in MDF used to enable Guard for all module.
} bsp_module_standby_info_t;

/** Assign Wake-up Factor for Run Mode and Cyclic RUN Mode */
typedef struct st_bsp_wk_factor_cfg               /* PRQA S 1536 # Advisory R-2.4 */
{
    bsp_wk_factor_t * wk_run;                     ///< Wake up Factors for RUN Mode
    uint8_t           num_of_wk_run_factor;       ///< Number of wake up factors for RUN Mode
    bsp_wk_factor_t * wk_cyclicrun;               ///< Wake-up Factors for Cyclic RUN Mode
    uint8_t           num_of_wk_cyclicrun_factor; ///< Number of wake-up factors for Cyclic RUN Mode
} bsp_wk_factor_cfg_t;

/***********************************************************************************************************************
 * Exported global variable (to be accessed by other files)
 **********************************************************************************************************************/
extern const bsp_module_standby_info_t g_msr_info_table[BSP_MODULE_STANDBY_TOTAL_INDEX_END];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif                                 /* BSP_MODULE_STANDBY_DRIVER_H */
