/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_GUARD_DRIVER_H
#define BSP_GUARD_DRIVER_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_GUARD_READ_WRITE_ACCESS              0x153U                                                            ///< Full read/write access in Supervisor & User modes

#define BSP_GUARD_CHANNEL_DEFAULT                (0U)                                                              ///< Default guard channel index
#define BSP_GUARD_DATAFLOW_BASE_ADDRESS          (0x00U) /* PRQA S 1534 # Advisory R-2.5 */                        ///< Dataflow processor base address

#define BSP_GUARD_KCPROT_ADDRESS_OFFSET          0x18U                                                             ///< Offset to KCPROT register

#define BSP_PBG_CHANNEL_ADDRESS_OFFSET           0x08U                                                             ///< Offset to PBG channel
#define BSP_PBG_KCPROT_ADDRESS_OFFSET            0x18U                                                             ///< Offset to PBG KCPROT

#define BSP_IBG_IPIR_PROT_CHANNEL_OFFSET         0x10U                                                             ///< IBG IPIR protection channel offset
#define BSP_IBG_BARR_TPTM_PROT_CHANNEL_OFFSET    0x08U                                                             ///< IBG BARR/TPTM protection channel offset

#define R_GUARD_PE0_LRAM_BASE                    0xFDC00000UL                                                      ///< PE0 local RAM base
#define R_GUARD_PE1_LRAM_BASE                    0xFDA00000UL                                                      ///< PE1 local RAM base
#define R_GUARD_PE2_LRAM_BASE                    0xFD800000UL                                                      ///< PE2 local RAM base
#define R_GUARD_PE3_LRAM_BASE                    0xFD600000UL /* PRQA S 1534 # Advisory R-2.5 */                   ///< PE3 local RAM base

#define R_GUARD_CRG_CRAM0_BASE                   0xFE000000UL                                                      ///< CRG shared RAM0 base
#define R_GUARD_CRG_CRAM1_BASE                   0xFE080000UL /* PRQA S 1534 # Advisory R-2.5 */                   ///< CRG shared RAM1 base

#define R_IBG00_IPIGPROT0_Rn_BASE                0xFFC6A280UL                                                      ///< IBG00 IPIGPROT0 Rn base
#define R_IBG00_IPIGPROT0_Tn_BASE                0xFFC6A288UL                                                      ///< IBG00 IPIGPROT0 Tn base
#define R_IBG00_IPIGPROT0_4_BASE                 0xFFC6A2C0UL                                                      ///< IBG00 IPIGPROT0 4 base

#define R_IBG01_BRGPROT0_n_BASE                  0xFFC6A080UL                                                      ///< IBG01 BRGPROT0 n base
#define R_IBG01_BRGPROT0_16_BASE                 0xFFC6A100UL                                                      ///< IBG01 BRGPROT0 16 base

#define R_IBG02_TPTGPROT0_IFn_BASE               0xFFC6A680UL                                                      ///< IBG02 TPTGPROT0 IFn base
#define R_IBG02_TPTGPROT0_Un_BASE                0xFFC6A6C0UL                                                      ///< IBG02 TPTGPROT0 Un base
#define R_IBG02_TPTGPROT0_U8_BASE                0xFFC6A700UL                                                      ///< IBG02 TPTGPROT0 U8 base
#define R_IBG02_TPTGPROT0_U9_BASE                0xFFC6A708UL                                                      ///< IBG02 TPTGPROT0 U9 base

#define BSP_GUARD_MAX_32BITS                     0xFFFFFFFFUL                                                      ///< Max 32-bit mask value

#define BSP_GUARD_DATAFLOW_WRITE_PROTECTION      BSP_GUARD_DFP_WRITE_PROTECTION /* PRQA S 1534 # Advisory R-2.5 */ ///< Dataflow write-protection alias

#define BSP_GUARD_GET_BIT(value)    ((uint32_t) __SCH1R(value) - 1U) /* PRQA S 3472 # Advisory D-4.9 */            ///< Search bit 1 from the LSB

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU_RH850U2BX
 * @defgroup BSP_GUARD_U2BX BSP Guard Protection
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** PBus and HBus Guard group */
typedef enum e_bsp_pbg_group           /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_PBG_GROUP_PBG00 = 0,           ///< PBG group PBG00
    BSP_PBG_GROUP_PBG01,               ///< PBG group PBG01
    BSP_PBG_GROUP_PBG10,               ///< PBG group PBG10
    BSP_PBG_GROUP_PBG20,               ///< PBG group PBG20
    BSP_PBG_GROUP_PBG21,               ///< PBG group PBG21
    BSP_PBG_GROUP_PBG22,               ///< PBG group PBG22
    BSP_PBG_GROUP_PBG23,               ///< PBG group PBG23
    BSP_PBG_GROUP_PBG24,               ///< PBG group PBG24
    BSP_PBG_GROUP_PBG30,               ///< PBG group PBG30
    BSP_PBG_GROUP_PBG31,               ///< PBG group PBG31
    BSP_PBG_GROUP_PBG32,               ///< PBG group PBG32
    BSP_PBG_GROUP_PBG40,               ///< PBG group PBG40
    BSP_PBG_GROUP_PBG41,               ///< PBG group PBG41
    BSP_PBG_GROUP_PBG50,               ///< PBG group PBG50
    BSP_PBG_GROUP_PBG51,               ///< PBG group PBG51
    BSP_PBG_GROUP_PBG52,               ///< PBG group PBG52
    BSP_PBG_GROUP_PBG60,               ///< PBG group PBG60
    BSP_PBG_GROUP_PBG61,               ///< PBG group PBG61
    BSP_PBG_GROUP_PBG62,               ///< PBG group PBG62
    BSP_PBG_GROUP_PBG70,               ///< PBG group PBG70
    BSP_PBG_GROUP_PBG71,               ///< PBG group PBG71
    BSP_PBG_GROUP_PBG8H0,              ///< PBG group PBG8H0
    BSP_PBG_GROUP_PBG8L0,              ///< PBG group PBG8L0
    BSP_PBG_GROUP_PBG90,               ///< PBG group PBG90
    BSP_PBG_GROUP_PBG91,               ///< PBG group PBG91
    BSP_PBG_GROUP_PBG92,               ///< PBG group PBG92
    BSP_PBG_GROUP_PBG100,              ///< PBG group PBG100
    BSP_PBG_GROUP_PBG101,              ///< PBG group PBG101
    BSP_PBG_GROUP_PBG11H0,             ///< PBG group PBG11H0
    BSP_PBG_GROUP_PBG11H1,             ///< PBG group PBG11H1
    BSP_PBG_GROUP_PBG11H2,             ///< PBG group PBG11H2
    BSP_PBG_GROUP_PBG11L0,             ///< PBG group PBG11L0

    BSP_HBG_GROUP_HBG90,               ///< HBG group HBG90
    BSP_HBG_GROUP_HBG92,               ///< HBG group HBG92
    BSP_HBG_GROUP_HBG94,               ///< HBG group HBG94

    BSP_PBG_GROUP_NUM                  ///< Number of PBG/HBG groups
} bsp_pbg_group_t;

/** Guard module IDs*/
typedef enum e_bsp_module_pbg_id       /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_BSP_MODULE,              ///< Guard module BSP
    BSP_GUARD_BIST_MODULE,             ///< Guard module BIST
    BSP_GUARD_DMA_MODULE,              ///< Guard module DMA
    BSP_GUARD_DTS_MODULE,              ///< Guard module DTS
    BSP_GUARD_QOS_MODULE,              ///< Guard module QOS
    BSP_GUARD_IOPORT_MODULE,           ///< Guard module IOPORT
    BSP_GUARD_DFE_MODULE,              ///< Guard module DFE

#if (BSP_FEATURE_MMCA_IS_AVAILABLE)
    BSP_GUARD_MMCA_MODULE,             ///< Guard module MMCA
#endif

#if (BSP_FEATURE_RDC3AS_IS_AVAILABLE)
    BSP_GUARD_RDC3AS_MODULE,           ///< Guard module RDC3AS
#endif

#if (BSP_FEATURE_RDC3AL_IS_AVAILABLE)
    BSP_GUARD_RDC3AL_MODULE,           ///< Guard module RDC3AL
#endif

    BSP_GUARD_KCRC_MODULE,             ///< Guard module KCRC
    BSP_GUARD_MSPI_MODULE,             ///< Guard module MSPI

#if (BSP_FEATURE_PSI5_IS_AVAILABLE)
    BSP_GUARD_PSI5_MODULE,             ///< Guard module PSI5
#endif

#if (BSP_FEATURE_PSI5S_IS_AVAILABLE)
    BSP_GUARD_PSI5S_MODULE,            ///< Guard module PSI5S
#endif

    BSP_GUARD_RSENT_MODULE,            ///< Guard module RSENT
    BSP_GUARD_PIC_MODULE,              ///< Guard module PIC
    BSP_GUARD_LTSC_MODULE,             ///< Guard module LTSC
    BSP_GUARD_SWDT_MODULE,             ///< Guard module SWDT
    BSP_GUARD_ECM_MODULE,              ///< Guard module ECM
    BSP_GUARD_TAUD_MODULE,             ///< Guard module TAUD
    BSP_GUARD_TAPA_MODULE,             ///< Guard module TAPA
    BSP_GUARD_WDTB_MODULE,             ///< Guard module WDTB
    BSP_GUARD_OSTM_MODULE,             ///< Guard module OSTM
    BSP_GUARD_RLIN3_MODULE,            ///< Guard module RLIN3
    BSP_GUARD_OTS_MODULE,              ///< Guard module OTS
    BSP_GUARD_EINT_MODULE,             ///< Guard module EINT
    BSP_GUARD_FLMD_MODULE,             ///< Guard module FLMD
    BSP_GUARD_RHSB_MODULE,             ///< Guard module RHSB
    BSP_GUARD_FCMP_MODULE,             ///< Guard module FCMP
    BSP_GUARD_ADCK_MODULE,             ///< Guard module ADCK
    BSP_GUARD_IFC_MODULE,              ///< Guard module IFC
    BSP_GUARD_ABFG_MODULE,             ///< Guard module ABFG
    BSP_GUARD_AIR_MODULE,              ///< Guard module AIR
    BSP_GUARD_FCMPC_MODULE,            ///< Guard module FCMPC
    BSP_GUARD_DSADC_MODULE,            ///< Guard module DSADC
    BSP_GUARD_GTM_MODULE,              ///< Guard module GTM
    BSP_GUARD_ETHTSN_MODULE,           ///< Guard module ETHTSN
    BSP_GUARD_GPTP_MODULE,             ///< Guard module GPTP

#if (BSP_FEATURE_DSMIF_IS_AVAILABLE)
    BSP_GUARD_DSMIF_MODULE,            ///< Guard module DSMIF
#endif

#if (BSP_FEATURE_RHSIF_IS_AVAILABLE)
    BSP_GUARD_RHSIF_MODULE,            ///< Guard module RHSIF
#endif

    BSP_GUARD_ICUM_MODULE,             ///< Guard module ICUM
    BSP_GUARD_SPIDCTL_MODULE,          ///< Guard module SPIDCTL
    BSP_GUARD_INTIF_MODULE,            ///< Guard module INTIF

#if (BSP_FEATURE_TSG3_EMU3S_IS_AVAILABLE)
    BSP_GUARD_INTIF_EMU3S_MODULE,      ///< Guard module INTIF_EMU3S
#endif

#if BSP_FEATURE_DFP_IS_AVAILABLE
    BSP_GUARD_DFP_MODULE,              ///< Guard module DFP
#endif

    BSP_GUARD_RSCAN_MODULE,            ///< Guard module RSCAN
    BSP_GUARD_TSG3_MODULE,             ///< Guard module TSG3
    BSP_GUARD_ENCA_MODULE,             ///< Guard module ENCA
    BSP_GUARD_TPBA_MODULE,             ///< Guard module TPBA
    BSP_GUARD_ATU_VI_MODULE,           ///< Guard module ATU_VI

#if (BSP_FEATURE_RIIC_IS_AVAILABLE)
    BSP_GUARD_RIIC_MODULE,             ///< Guard module RIIC
#endif

    BSP_GUARD_XBAR_MODULE,             ///< Guard module XBAR
    BSP_GUARD_HRPWM_MODULE,            ///< Guard module HRPWM
    BSP_GUARD_FLXA_MODULE,             ///< Guard module FLXA
    BSP_GUARD_SFMA_MODULE,             ///< Guard module SFMA

    BSP_MODULE_PBG_TOTAL_INDEX_END     ///< Total PBG guard module count
} bsp_module_pbg_id_t;                 /* PRQA S 1535 # Advisory R-2.3 */

/** Guard types for configuring/status protection */
typedef enum e_bsp_guard_type          /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_TYPE_PE_GUARD,           ///< PE Guard: Protects PE Local RAM and INTC1 registers
    BSP_GUARD_TYPE_CRAM_GUARD,         ///< Cluster RAM Guard: Protects Cluster RAM area
    BSP_GUARD_TYPE_IBUS_GUARD,         ///< I-Bus Guard: Protects I-Bus modules
    BSP_GUARD_TYPE_PBUS_GUARD,         ///< Peripheral Bus Guard: Protects PBG/HBG groups
    BSP_GUARD_TYPE_INTC2_GUARD,        ///< INTC2 Guard: Protects INTC2 registers
    BSP_GUARD_TYPE_DTS_GUARD,          ///< DTS Guard: Protects DTS registers
    BSP_GUARD_TYPE_DMAC_GUARD,         ///< sDMAC Guard: Protects sDMAC registers
    BSP_GUARD_TYPE_DFP_GUARD,          ///< DFP Guard: Protects Data Flow Processor resources
    BSP_GUARD_TYPE_NUM                 ///< Number of guard types
} bsp_guard_type_t;

/** Guard control register types */
typedef enum e_bsp_guard_ctr_reg       /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_REG_PROT = 0,            ///< Protection control register
    BSP_GUARD_REG_SPID,                ///< SPID setting register
    BSP_GUARD_REG_BAD,                 ///< Base address register
    BSP_GUARD_REG_ADV,                 ///< Address valid setting register
    BSP_GUARD_REG_COUNT                ///< Total number of guard control registers
} bsp_guard_ctr_reg_t;                 /* PRQA S 1535 # Advisory R-2.3 */

/** I-Bus guard control target */
typedef enum e_bsp_ibg_control         /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_IBG_CONTROL_IPIR_Rn = 0,       ///< I-Bus group0 registers (Rn)
    BSP_IBG_CONTROL_IPIR_Tn,           ///< I-Bus group0 registers (Tn)
    BSP_IBG_CONTROL_IPIR_4,            ///< I-Bus group0 register (4)
    BSP_IBG_CONTROL_BARR_n,            ///< I-Bus group1 registers (n)
    BSP_IBG_CONTROL_BARR_16,           ///< I-Bus group1 register (16)
    BSP_IBG_CONTROL_TPTM_IFn,          ///< I-Bus group2 registers (IFn)
    BSP_IBG_CONTROL_TPTM_Un,           ///< I-Bus group2 registers (Un)
    BSP_IBG_CONTROL_TPTM_U8,           ///< I-Bus group2 register (U8)
    BSP_IBG_CONTROL_TPTM_U9,           ///< I-Bus group2 register (U9)
    BSP_IBG_CONTROL_NUM
} bsp_ibg_control_t;

/** I-Bus guard module IDs */
typedef enum e_bsp_module_ibg_id       /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_IPIR_MODULE = 0,         ///< IPIR module
    BSP_GUARD_BARR_MODULE,             ///< BARR module
    BSP_GUARD_TPTM_MODULE,             ///< TPTM module
    BSP_MODULE_IBG_TOTAL_INDEX_END
} bsp_module_ibg_id_t;

/** PE guard control targets */
typedef enum e_bsp_peg_control         /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_PEG_CONTROL_PE0 = 0,           ///< Guard for PE0 Local RAM area & INTC1 register area
    BSP_PEG_CONTROL_PE1,               ///< Guard for PE1 Local RAM area & INTC1 register area
    BSP_PEG_CONTROL_PE2,               ///< Guard for PE2 Local RAM area & INTC1 register area
#if (BSP_FEATURE_PE3_GUARD_IS_AVAILABLE)
    BSP_PEG_CONTROL_PE3,               ///< Guard for PE3 Local RAM area & INTC1 register area
#endif
    BSP_PEG_CONTROL_NUM
} bsp_peg_control_t;

/** Cluster RAM guard control targets */
typedef enum e_bsp_crg_control         /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_CRG_CONTROL_CRAM0 = 0,         ///< Guard for Cluster 0 RAM
#if (BSP_FEATURE_CRAM1_GUARD_IS_AVAILABLE)
    BSP_CRG_CONTROL_CRAM1,             ///< Guard for Cluster 1 RAM
#endif
    BSP_CRG_CONTROL_NUM
} bsp_crg_control_t;

/** INTC2 guard control targets (Group register) */
typedef enum e_bsp_intc2g_control       /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_INTC2G_CONTROL_EIBD_I2EIBG = 0, ///< Guard access to EIBDn/I2EIBGn register
    BSP_INTC2G_CONTROL_IMR,             ///< Guard access to IMRn register
    BSP_INTC2G_CONTROL_EIC_EEIC,        ///< Guard access to EICn/EEICn register
    BSP_INTC2G_CONTROL_NUM
} bsp_intc2g_control_t;

/** DTS guard control targets (Group register) */
typedef enum e_bsp_dtsg_control        /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_DTSG_CONTROL_COMMON_REG = 0,   ///< Guard access to DTS common registers
    BSP_DTSG_CONTROL_CHANNEL_REG,      ///< Guard access to DTS channel registers
    BSP_DTSG_CONTROL_NUM
} bsp_dtsg_control_t;

/** DMA guard control targets (Group register) */
typedef enum e_bsp_dmag_control        /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_DMAG_CONTROL_GLOBAL_REG = 0,   ///< Guard access to sDMAC global registers
    BSP_DMAG_CONTROL_DRAM_REG,         ///< Guard access to sDMAC descriptor RAM
    BSP_DMAG_CONTROL_REDUNDANT_REG,    ///< Guard access to sDMAC redundant channel register
    BSP_DMAG_CONTROL_CHANNEL_REG,      ///< Guard access to sDMAC channel registers
    BSP_DMAG_CONTROL_NUM
} bsp_dmag_control_t;

/** sDMAC guard control targets (Units) */
typedef enum e_bsp_dmag_unit           /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_DMAG_UNIT_0 = 0,               ///< sDMAC Unit 0
#if (BSP_FEATURE_DMAC_MAX_UNIT == 2)
    BSP_DMAG_UNIT_1,                   ///< sDMAC Unit 1
#endif
    BSP_DMAG_UNIT_NUM
} bsp_dmag_unit_t;

/** Guard enable setting */
typedef enum e_bsp_guard_setting                                                                    /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_SETTING_DISABLE = 0U,                                                                 ///< Disable guard setting
    BSP_GUARD_SETTING_ENABLE  = 1U                                                                  ///< Enable guard setting
} bsp_guard_setting_t;

/** Guard debug access control */
typedef enum e_bsp_guard_debug                                                                      /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_DEBUG_DEPENDS = 0U,                                                                   ///< R/W depends on other protection settings
    BSP_GUARD_DEBUG_ENABLE  = 1U                                                                    ///< R/W enabled for debug master
} bsp_guard_debug_t;

/** Guard user mode access control */
typedef enum e_bsp_guard_um                                                                         /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_UM_DISABLE = 0U,                                                                      ///< Disable user mode access (R/W)
    BSP_GUARD_UM_ENABLE  = 1U                                                                       ///< Enable user mode access (R/W depends on protection settings)
} bsp_guard_um_t;

/** Guard write access control */
typedef enum e_bsp_guard_write                                                                      /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_WRITE_USE_SPID  = 0U,                                                                 ///< Write uses SPID check (SPID is used as judgment condition)
    BSP_GUARD_WRITE_ALLOW_ALL = 1U                                                                  ///< Write allows all (SPID is NOT used as judgment condition)
} bsp_guard_write_t;

/** Guard read access control */
typedef enum e_bsp_guard_read                                                                       /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_READ_USE_SPID  = 0U,                                                                  ///< Read uses SPID check (SPID is used as judgment condition)
    BSP_GUARD_READ_ALLOW_ALL = 1U                                                                   ///< Read allows all (SPID is NOT used as judgment condition)
} bsp_guard_read_t;

/** Guard secure access control */
typedef enum e_bsp_guard_secure                                                                     /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_SECURE_DISABLE = 0U,                                                                  ///< R/W disabled for non-secure master
    BSP_GUARD_SECURE_ENABLE  = 1U                                                                   ///< R/W depends on other protection settings
} bsp_guard_secure_t;

/** Guard lock setting control */
typedef enum e_bsp_guard_lock                                                                       /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_LOCK_DISABLE = 0U,                                                                    ///< Allow re-configure protect setting rewrite
    BSP_GUARD_LOCK_ENABLE  = 1U                                                                     ///< Block further writes until reset
} bsp_guard_lock_t;

/** MPID permissions for SPID entries */
typedef enum e_bsp_guard_mpid                                                                       /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_MPID_NONE = 0,                                                                        ///< No SPID permitted (MPID[7:0] = 00000000B)

    BSP_GUARD_MPID_0 = ((uint8_t) 1U << 0),                                                         ///< Permit SPID set in MPID0 (MPID[0] = 1)
    BSP_GUARD_MPID_1 = ((uint8_t) 1U << 1),                                                         ///< Permit SPID set in MPID1 (MPID[1] = 1)
    BSP_GUARD_MPID_2 = ((uint8_t) 1U << 2),                                                         ///< Permit SPID set in MPID2 (MPID[2] = 1)
    BSP_GUARD_MPID_3 = ((uint8_t) 1U << 3),                                                         ///< Permit SPID set in MPID3 (MPID[3] = 1)
    BSP_GUARD_MPID_4 = ((uint8_t) 1U << 4),                                                         ///< Permit SPID set in MPID4 (MPID[4] = 1)
    BSP_GUARD_MPID_5 = ((uint8_t) 1U << 5),                                                         ///< Permit SPID set in MPID5 (MPID[5] = 1)
    BSP_GUARD_MPID_6 = ((uint8_t) 1U << 6),                                                         ///< Permit SPID set in MPID6 (MPID[6] = 1)
    BSP_GUARD_MPID_7 = ((uint8_t) 1U << 7),                                                         ///< Permit SPID set in MPID7 (MPID[7] = 1)
} bsp_guard_mpid_t;                                                                                 /* PRQA S 1535 # Advisory R-2.3 */

/** SPID access permissions (0-31) */
typedef enum e_bsp_guard_set_spid                                                                   /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_GUARD_SET_SPID_NONE = 0U,                                                                   ///< No SPID access

    BSP_GUARD_SET_SPID0  = ((uint32_t) 1U << 0),                                                    ///< Enable access for SPID = 0
    BSP_GUARD_SET_SPID1  = ((uint32_t) 1U << 1),                                                    ///< Enable access for SPID = 1
    BSP_GUARD_SET_SPID2  = ((uint32_t) 1U << 2),                                                    ///< Enable access for SPID = 2
    BSP_GUARD_SET_SPID3  = ((uint32_t) 1U << 3),                                                    ///< Enable access for SPID = 3
    BSP_GUARD_SET_SPID4  = ((uint32_t) 1U << 4),                                                    ///< Enable access for SPID = 4
    BSP_GUARD_SET_SPID5  = ((uint32_t) 1U << 5),                                                    ///< Enable access for SPID = 5
    BSP_GUARD_SET_SPID6  = ((uint32_t) 1U << 6),                                                    ///< Enable access for SPID = 6
    BSP_GUARD_SET_SPID7  = ((uint32_t) 1U << 7),                                                    ///< Enable access for SPID = 7
    BSP_GUARD_SET_SPID8  = ((uint32_t) 1U << 8),                                                    ///< Enable access for SPID = 8
    BSP_GUARD_SET_SPID9  = ((uint32_t) 1U << 9),                                                    ///< Enable access for SPID = 9
    BSP_GUARD_SET_SPID10 = ((uint32_t) 1U << 10),                                                   ///< Enable access for SPID = 10
    BSP_GUARD_SET_SPID11 = ((uint32_t) 1U << 11),                                                   ///< Enable access for SPID = 11
    BSP_GUARD_SET_SPID12 = ((uint32_t) 1U << 12),                                                   ///< Enable access for SPID = 12
    BSP_GUARD_SET_SPID13 = ((uint32_t) 1U << 13),                                                   ///< Enable access for SPID = 13
    BSP_GUARD_SET_SPID14 = ((uint32_t) 1U << 14),                                                   ///< Enable access for SPID = 14
    BSP_GUARD_SET_SPID15 = ((uint32_t) 1U << 15),                                                   ///< Enable access for SPID = 15
    BSP_GUARD_SET_SPID16 = ((uint32_t) 1U << 16),                                                   ///< Enable access for SPID = 16
    BSP_GUARD_SET_SPID17 = ((uint32_t) 1U << 17),                                                   ///< Enable access for SPID = 17
    BSP_GUARD_SET_SPID18 = ((uint32_t) 1U << 18),                                                   ///< Enable access for SPID = 18
    BSP_GUARD_SET_SPID19 = ((uint32_t) 1U << 19),                                                   ///< Enable access for SPID = 19
    BSP_GUARD_SET_SPID20 = ((uint32_t) 1U << 20),                                                   ///< Enable access for SPID = 20
    BSP_GUARD_SET_SPID21 = ((uint32_t) 1U << 21),                                                   ///< Enable access for SPID = 21
    BSP_GUARD_SET_SPID22 = ((uint32_t) 1U << 22),                                                   ///< Enable access for SPID = 22
    BSP_GUARD_SET_SPID23 = ((uint32_t) 1U << 23),                                                   ///< Enable access for SPID = 23
    BSP_GUARD_SET_SPID24 = ((uint32_t) 1U << 24),                                                   ///< Enable access for SPID = 24
    BSP_GUARD_SET_SPID25 = ((uint32_t) 1U << 25),                                                   ///< Enable access for SPID = 25
    BSP_GUARD_SET_SPID26 = ((uint32_t) 1U << 26),                                                   ///< Enable access for SPID = 26
    BSP_GUARD_SET_SPID27 = ((uint32_t) 1U << 27),                                                   ///< Enable access for SPID = 27
    BSP_GUARD_SET_SPID28 = ((uint32_t) 1U << 28),                                                   ///< Enable access for SPID = 28
    BSP_GUARD_SET_SPID29 = ((uint32_t) 1U << 29),                                                   ///< Enable access for SPID = 29
    BSP_GUARD_SET_SPID30 = ((uint32_t) 1U << 30),                                                   ///< Enable access for SPID = 30
    BSP_GUARD_SET_SPID31 = (1 << 31) /* PRQA S 0499, 4543 # DP_MSR_R-12.2_UC1, DP_MSR_R-10.1_UC1 */ ///< Enable access for SPID = 31
} bsp_guard_set_spid_t;                                                                             /* PRQA S 1535 # Advisory R-2.3 */

/** PE guard region size settings */
typedef enum e_bsp_peg_region_size                                                                  /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_PEG_REGION_SIZE_4KB  = 0x3FFF,                                                              ///< 4KB   - Requires Address 4KB alignment
    BSP_PEG_REGION_SIZE_8KB  = 0x3FFE,                                                              ///< 8KB   - Requires Address 8KB alignment
    BSP_PEG_REGION_SIZE_16KB = 0x3FFC,                                                              ///< 16KB  - Requires Address 16KB alignment
    BSP_PEG_REGION_SIZE_32KB = 0x3FF8,                                                              ///< 32KB  - Requires Address 32KB alignment
    BSP_PEG_REGION_SIZE_64KB = 0x3FF0,                                                              ///< 64KB  - Requires Address 64KB alignment
    BSP_PEG_REGION_SIZE_MAX  = 0x0000                                                               ///< MAX    - Protects entire Local RAM region
} bsp_peg_region_size_t;                                                                            /* PRQA S 1535 # Advisory R-2.3 */

/** Cluster RAM guard region size settings */
typedef enum e_bsp_crg_region_size                                                                  /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_CRG_REGION_SIZE_256B  = 0x7FF,                                                              ///< 256B  - Requires Address 256B alignment
    BSP_CRG_REGION_SIZE_512B  = 0x7FE,                                                              ///< 512B  - Requires Address 512B alignment
    BSP_CRG_REGION_SIZE_1KB   = 0x7FC,                                                              ///< 1KB   - Requires Address 1KB alignment
    BSP_CRG_REGION_SIZE_2KB   = 0x7F8,                                                              ///< 2KB   - Requires Address 2KB alignment
    BSP_CRG_REGION_SIZE_4KB   = 0x7F0,                                                              ///< 4KB   - Requires Address 4KB alignment
    BSP_CRG_REGION_SIZE_8KB   = 0x7E0,                                                              ///< 8KB   - Requires Address 8KB alignment
    BSP_CRG_REGION_SIZE_16KB  = 0x7C0,                                                              ///< 16KB  - Requires Address 16KB alignment
    BSP_CRG_REGION_SIZE_32KB  = 0x780,                                                              ///< 32KB  - Requires Address 32KB alignment
    BSP_CRG_REGION_SIZE_64KB  = 0x700,                                                              ///< 64KB  - Requires Address 64KB alignment
    BSP_CRG_REGION_SIZE_128KB = 0x600,                                                              ///< 128KB - Requires Address 128KB alignment
    BSP_CRG_REGION_SIZE_256KB = 0x400,                                                              ///< 256KB - Requires Address 256KB alignment
    BSP_CRG_REGION_SIZE_512KB = 0x000,                                                              ///< 512KB - Protects entire Cluster RAM region
} bsp_crg_region_size_t;                                                                            /* PRQA S 1535 # Advisory R-2.3 */

/** PE guard protection configuration */
typedef struct st_bsp_peg_protection_setting                                                        /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Specifies which PE's Local RAM and INTC1 areas to protect */
    bsp_peg_control_t control;

    /** Channel number (0-7) to configure protection region */
    uint8_t channel;

    /** Protection Control setting */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        struct
        {
            bsp_guard_read_t  read_global    : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Read Global Enable
            bsp_guard_write_t write_global   : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Write Global Enable
            uint32_t                         : 2;
            bsp_guard_um_t user_mode         : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< User Mode setting
            uint32_t                         : 1;
            bsp_guard_debug_t debug_mode     : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Debug Master Enable
            uint32_t                         : 1;
            bsp_guard_setting_t guard_enable : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Guard Enable
            uint32_t                         : 23;
        } protect_setting_b;                                                                                                                                                                    ///< Protection attribute setting

        uint32_t protect_setting;                                                                                                                                                               ///< Direct access to all protection control settings
    };                                                                                                                                                                                          /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */

    uint32_t spid;                                                                                                                                                                              ///< SPIDs permitted to access this region
    uint32_t base_address;                                                                                                                                                                      ///< Start address of protected region (4KB aligned)
    uint32_t valid_address;                                                                                                                                                                     ///< Address mask defining region size
} bsp_peg_protection_setting_t;

/** Cluster RAM guard protection configuration */
typedef struct st_bsp_crg_protection_setting                                                                                                                                                    /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Specifies which Cluster RAM areas to protect */
    bsp_crg_control_t control;

    /** Channel number (0-7) to configure protection region */
    uint8_t channel;

    /** Protection Control setting */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        struct
        {
            bsp_guard_read_t  read_global    : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Read Global Enable
            bsp_guard_write_t write_global   : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Write Global Enable
            uint32_t                         : 2;
            bsp_guard_um_t user_mode         : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< User Mode setting
            uint32_t                         : 1;
            bsp_guard_debug_t debug_mode     : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Debug Master Enable
            uint32_t                         : 1;
            bsp_guard_setting_t guard_enable : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Guard Enable
            uint32_t                         : 23;
        }        protect_setting_b;                                                                                                                                                             ///< Protection attribute setting
        uint32_t protect_setting;                                                                                                                                                               ///< Direct access to all protection control settings
    };                                                                                                                                                                                          /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */

    uint32_t spid;                                                                                                                                                                              ///< SPIDs permitted to access this region
    uint32_t base_address;                                                                                                                                                                      ///< Start address of protected region (256B aligned)
    uint32_t valid_address;                                                                                                                                                                     ///< Address mask defining region size
} bsp_crg_protection_setting_t;

/** INTC2 guard protection configuration */
typedef struct st_bsp_intc2g_protection_setting                                                                                                                                                 /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Specifies which INTC2 register group to protect (EIC/EEIC, EIBD/I2EIBG, or IMR) */
    bsp_intc2g_control_t control;

    /** Specifies channel number (32-1023 for EIC/EEIC, ignored for other groups) */
    uint16_t channel;

    /** Protection Control setting */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        struct
        {
            bsp_guard_read_t  read_global    : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Read Global enable
            bsp_guard_write_t write_global   : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Write Global enable
            uint32_t                         : 2;
            bsp_guard_um_t user_mode         : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< User Mode setting
            uint32_t                         : 1;
            bsp_guard_debug_t debug_mode     : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Debug Master setting
            uint32_t                         : 1;
            bsp_guard_setting_t guard_enable : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Guard Enable
            uint32_t                         : 7;
            uint32_t mpid_permit             : 8;                                                                                                                                               ///< MPID bitmap
            uint32_t                         : 8;
        }        protect_setting_b;                                                                                                                                                             ///< Protection attribute setting
        uint32_t protect_setting;                                                                                                                                                               ///< Direct access to all protection control settings
    };                                                                                                                                                                                          /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */

    /** SPID settings array (8 elements): Each element specifies one SPID value (0-31) that can be referenced by MPID bitmap */
    uint32_t spid[8];
} bsp_intc2g_protection_setting_t;

/** sDMAC guard protection configuration */
typedef struct st_bsp_dmag_protection_setting /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Specifies which sDMAC unit to protect */
    bsp_dmag_unit_t unit;

    /** sSpecifies which sDMAC register group to protect (global, DRAM, redundant, or channel) */
    bsp_dmag_control_t control;

    /** Specifies channel number (0-15 for channel registers, ignored for global/DRAM/redundant registers) */
    uint16_t channel;

    /** Protection Control setting */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        struct
        {
            bsp_guard_read_t  read_global    : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Read Global Enable
            bsp_guard_write_t write_global   : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Write Global Enable
            uint32_t                         : 2;
            bsp_guard_um_t user_mode         : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< User Mode setting
            uint32_t                         : 1;
            bsp_guard_debug_t debug_mode     : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Debug Master setting
            uint32_t                         : 1;
            bsp_guard_setting_t guard_enable : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Guard Enable
            uint32_t                         : 7;
            uint32_t mpid_permit             : 8;                                                                                                                                               ///< MPID bitmap
            uint32_t                         : 8;
        }        protect_setting_b;                                                                                                                                                             ///< Protection attribute setting
        uint32_t protect_setting;                                                                                                                                                               ///< Direct access to all protection control settings
    };                                                                                                                                                                                          /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */

    /** SPID settings array (8 elements): Each element specifies one SPID value (0-31) that can be referenced by MPID bitmap */
    uint32_t spid[8];
} bsp_dmag_protection_setting_t;

/** DTS guard protection configuration */
typedef struct st_bsp_dtsg_protection_setting /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Specifies which DTS register group to protect (common or channel-specific) */
    bsp_dtsg_control_t control;

    /** Specifies channel number (0-127 for channel registers, ignored for common registers) */
    uint16_t channel;

    /** Protection Control setting */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        struct
        {
            bsp_guard_read_t  read_global    : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Read Global Enable
            bsp_guard_write_t write_global   : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Write Global Enable
            uint32_t                         : 2;
            bsp_guard_um_t user_mode         : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< User Mode setting
            uint32_t                         : 1;
            bsp_guard_debug_t debug_mode     : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Debug Master setting
            uint32_t                         : 1;
            bsp_guard_setting_t guard_enable : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Guard Enable
            uint32_t                         : 7;
            uint32_t mpid_permit             : 8;                                                                                                                                               ///< MPID bitmap
            uint32_t                         : 8;
        }        protect_setting_b;                                                                                                                                                             ///< Protection attribute setting
        uint32_t protect_setting;                                                                                                                                                               ///< Direct access to all protection control settings
    };                                                                                                                                                                                          /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */

    /** SPID settings array (8 elements): Each element specifies one SPID value (0-31) that can be referenced by MPID bitmap */
    uint32_t spid[8];
} bsp_dtsg_protection_setting_t;

/** PBG/HBG guard protection configuration */
typedef struct st_bsp_pbg_protection_setting /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Bus group target: Specifies which PBG or HBG group to protect */
    bsp_pbg_group_t group;

    /** Specifies which channel number within PBG group */
    uint8_t channel;

    /** Protection Control setting */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        struct
        {
            bsp_guard_read_t  read_global     : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Read Global enable
            bsp_guard_write_t write_global    : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Write Global enable
            uint32_t                          : 2;
            bsp_guard_um_t user_mode          : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< User Mode setting
            uint32_t                          : 1;
            bsp_guard_debug_t   debug_mode    : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Debug Master setting
            bsp_guard_secure_t  secure_master : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Secure Master setting
            bsp_guard_setting_t guard_enable  : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Guard Enable: Disable
            uint32_t                          : 22;
            bsp_guard_lock_t lock             : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Lock Prevents modification when set
        }        protect_setting_b;                                                                                                                                                              ///< Protection attribute setting
        uint32_t protect_setting;                                                                                                                                                                ///< Direct access to all protection control settings
    };                                                                                                                                                                                           /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */

    uint32_t spid;                                                                                                                                                                               ///< SPIDs permitted to access this region
} bsp_pbg_protection_setting_t;

/** I-Bus guard protection configuration */
typedef struct st_bsp_ibg_protection_setting                                                                                                                                                     /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Specifies which I-Bus module register group to protect
     *  - IPIR (Rn/Tn/4), BarrierSync (n/16), or TPTM (IFn/Un/U8/U9)
     */
    bsp_ibg_control_t control;

    /** Specifies channel number for channel-based targets. Ignored for common targets (IPIR_4, BARR_16, TPTM_U8, TPTM_U9) */
    uint8_t channel;

    /** Protection Control setting */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        struct
        {
            bsp_guard_read_t  read_global    : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Read Global Enable
            bsp_guard_write_t write_global   : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Write Global Enable
            uint32_t                         : 2;
            bsp_guard_um_t user_mode         : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< User Mode setting
            uint32_t                         : 1;
            bsp_guard_debug_t debug_mode     : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Debug Master setting
            uint32_t                         : 1;
            bsp_guard_setting_t guard_enable : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Guard Enable
            uint32_t                         : 23;
        }        protect_setting_b;                                                                                                                                                             ///< Protection attribute setting
        uint32_t protect_setting;                                                                                                                                                               ///< Direct access to all protection control settings
    };                                                                                                                                                                                          /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */

    uint32_t spid;                                                                                                                                                                              ///< SPIDs permitted to access this region
} bsp_ibg_protection_setting_t;

/** Data flow processor guard protection configuration */
typedef struct st_bsp_dataflowgrd_protection_setting                                                                                                                                            /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Channel number (0-7) to configure protection region */
    uint8_t channel;

    /** Protection Control setting */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        struct
        {
            bsp_guard_read_t  read_global    : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Read Global Enable
            bsp_guard_write_t write_global   : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Write Global Enable
            uint32_t                         : 2;
            bsp_guard_um_t user_mode         : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< User Mode setting
            uint32_t                         : 1;
            bsp_guard_debug_t debug_mode     : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Debug Master setting
            uint32_t                         : 1;
            bsp_guard_setting_t guard_enable : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */ ///< Guard Enable
            uint32_t                         : 23;
        }        protect_setting_b;                                                                                                                                                             ///< Protection attribute setting
        uint32_t protect_setting;                                                                                                                                                               ///< Direct access to all protection control settings
    };                                                                                                                                                                                          /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */

    uint32_t spid;                                                                                                                                                                              ///< SPIDs permitted to access this region
    uint32_t base_address;                                                                                                                                                                      ///< Start address of protected region (4KB aligned)
    uint32_t valid_address;                                                                                                                                                                     ///< Address mask defining region size
} bsp_dataflowgrd_protection_setting_t;

/** Guard protection setting structure for all guard types. Use the appropriate member based on the target guard module. */
typedef struct st_bsp_guard_protection_setting                                                                                                                                                  /* PRQA S 3630, 1536 # Advisory D-4.8, Advisory R-2.4 */
{
    /** Guard module-specific protection settings */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        /** PE Guard settings */
        bsp_peg_protection_setting_t pegrd_setting;

        /** Cluster RAM Guard settings */
        bsp_crg_protection_setting_t cramgrd_setting;

        /** I-Bus Guard settings */
        bsp_ibg_protection_setting_t ibusgrd_setting;

        /** Peripheral Bus Guard settings */
        bsp_pbg_protection_setting_t pbusgrd_setting;

        /** INTC2 Guard settings */
        bsp_intc2g_protection_setting_t intc2grd_setting;

        /** DTS Guard settings */
        bsp_dtsg_protection_setting_t dtsgrd_setting;

        /** sDMAC Guard settings */
        bsp_dmag_protection_setting_t dmagrd_setting;

        /** DFP Guard settings */
        bsp_dataflowgrd_protection_setting_t dataflowgrd_setting;
    } slave_guard_protection;

    /* PRQA S 0750 -- */
} bsp_guard_protection_setting_t;

/** Guard protection status error codes */
typedef enum e_bsp_protection_status_error   /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_PROTECTION_STATUS_ERROR_NONE = 0,    ///< No guard error detected
    BSP_PROTECTION_STATUS_ERROR_DETECTED,    ///< Guard error detected
    BSP_PROTECTION_STATUS_ERROR_OVERFLOW     ///< Guard error overflow occurred (new error while previous error not cleared)
} bsp_protection_status_error_t;

/** Guard protection error status information */
typedef struct st_bsp_protection_status      /* PRQA S 1536 # Advisory R-2.4 */
{
    bsp_protection_status_error_t errstatus; ///< Guard error status

    uint32_t err_access_address;             ///< Address without access permission that caused the guard error

    /** Error access attributes */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        struct
        {
            bsp_guard_write_t write : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */                       ///< Access type (0=Read, 1=Write) when guard error occurred
            uint32_t                : 5;
            uint32_t           spid : 5;                                                                                                                                                                     ///< SPID[4:0] - Access attribute of SPID when guard error occurred
            bsp_guard_um_t     um   : 1; /* PRQA S 0634, 0635, 3660, 1710 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1, Advisory D-4.5 */ ///< UM - User Mode access attribute when guard error occurred
            bsp_guard_debug_t  dbg  : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */                       ///< DBG - Debug access attribute when guard error occurred
            bsp_guard_secure_t sec  : 1; /* PRQA S 0634, 0635, 3660 # DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1, DP_MSR_R-6.1_UC1 & DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-6.2_UC1 */                       ///< SEC - Secure access attribute when guard error occurred
            uint32_t                : 18;
        } err_attribute_b;                                                                                                                                                                                   ///< Error attribute fields

        uint32_t err_attribute;                                                                                                                                                                              ///< Direct access to error attribute register
    };                                                                                                                                                                                                       /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */

    uint32_t spid_error_status;                                                                                                                                                                              ///< SPID error status bitmap showing which SPID(s) caused guard errors
} bsp_protection_status_t;

/** PE Guard protection error status information */
typedef struct st_bsp_peg_protection_status                                                                                                                                                                  /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Specifies which PE's Local RAM and INTC1 areas to get protect status */
    bsp_peg_control_t control;

    /**
     * PEG protection status for PEx (x = 0,1,2,3,4,5):
     *
     * [0] = PEGCAP_S_PEx:     PEx INTC1 registers + PEx LRAM (Non-speculative/Fetch from other PEs)
     *
     * [1] = PEGCAP_M_PE0CLy:  PEx LRAM - Load from PE0 (If the device is available)
     * [2] = PEGCAP_M_PE1CLy:  PEx LRAM - Load from PE1 (If the device is available)
     * [3] = PEGCAP_M_PE2CLy:  PEx LRAM - Load from PE2 (If the device is available)
     * [4] = PEGCAP_M_PE3CLy:  PEx LRAM - Load from PE3 (If the device is available)
     *
     * Note:
     * - Non-speculative: STORE/STC/LDL/SET1/NOT1/CLR1/TST1/CAXI
     * - Fetch: Instruction fetch
     * - Load: LOAD instruction (speculative request)
     */
    bsp_protection_status_t peg_status[BSP_FEATURE_PE_GUARD_STATUS_MAX];
} bsp_peg_protection_status_t;

/** CLuster RAM Guard protection error status information */
typedef struct st_bsp_crg_protection_status /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Specifies which Cluster RAM areas to get protect status */
    bsp_crg_control_t control;

    /**
     * CRG protection status for Cluster RAM n (n = 0,1,2,4):
     *
     * [0] = CRGCAP_CRAMHCLn:    Store from all masters (odd words/bank1,3)
     * [1] = CRGCAP_CRAMLCLn:    Store from all masters (even words/bank0,2)
     *
     * [2] = CRGCAP_SX2MBHCLn:   Load/Fetch from other than PEs (odd words/bank1,3)
     * [3] = CRGCAP_SX2MBLCLn:   Load/Fetch from other than PEs (even words/bank0,2)
     *
     * [4] = CRGCAP_PE0CL0:      Load from PE0 to Cluster RAM (If the device is available)
     * [5] = CRGCAP_PE1CL0:      Load from PE1 to Cluster RAM (If the device is available)
     * [6] = CRGCAP_PE2CL1:      Load from PE2 to Cluster RAM (If the device is available)
     * [7] = CRGCAP_PE3CL1:      Load from PE3 to Cluster RAM (If the device is available)
     *
     * Note:
     * - Load: LOAD/LDL/TST1 instructions
     * - Store: STORE/STC/CLR1/NOT1/SET1/CAXI instructions
     * - Fetch: Instruction fetch from all PEs
     */
    bsp_protection_status_t crg_status[BSP_FEATURE_CRAM_GUARD_STATUS_MAX];
} bsp_crg_protection_status_t;

/** sDMAC guard protection status for a specific DMA unit */
typedef struct st_bsp_dmac_guard_protection_status /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Specifies which sDMAC unit to get protect staus*/
    bsp_dmag_unit_t dma_guard_unit;

    /** DMAC Guard protection status for specific unit */
    bsp_protection_status_t status;
} bsp_dmac_guard_protection_status_t;

/** I-Bus guard protection status for a specific module */
typedef struct st_bsp_ibg_protection_status /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Specifies which I-Bus module to get protect staus*/
    bsp_module_ibg_id_t module;

    /** IBG protection status for specific module */
    bsp_protection_status_t status;
} bsp_ibg_protection_status_t;

/** PBG/HBG guard protection status for a specific group */
typedef struct st_bsp_pbg_protection_status /* PRQA S 1536 # Advisory R-2.4 */
{
    /**  Specifies which PBG or HBG group to get protect status*/
    bsp_pbg_group_t group;

    /** PBG protection status for specific group */
    bsp_protection_status_t status;
} bsp_pbg_protection_status_t;

/** Guard protection status structure for all guard types. Use the appropriate member based on the target guard module. */
typedef struct st_bsp_guard_protection_status /* PRQA S 3630, 1536 # Advisory D-4.8, Advisory R-2.4 */
{
    /** Guard module-specific protection status */
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        /** PE Guard status */
        bsp_peg_protection_status_t pegrd_status;

        /** Cluster RAM Guard status */
        bsp_crg_protection_status_t cramgrd_status;

        /** I-Bus Guard status */
        bsp_ibg_protection_status_t ibusgrd_status;

        /** Peripheral Bus Guard status */
        bsp_pbg_protection_status_t pbusgrd_status;

        /** INTC2 Guard status */
        bsp_protection_status_t intc2grd_status;

        /** DTS Guard status */
        bsp_protection_status_t dtsgrd_status;

        /** sDMAC Guard status */
        bsp_dmac_guard_protection_status_t dmagrd_status;

        /** DFP Guard status */
        bsp_protection_status_t dataflowgrd_status;
    };                                 /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */
} bsp_guard_protection_status_t;

/** Function pointer type for applying guard protection settings */
typedef void (* bsp_protection_setting)(const bsp_guard_protection_setting_t * p_setting);

/** Function pointer type for retrieving guard protection status */
typedef void (* bsp_protection_status)(bsp_guard_protection_status_t * p_status);

/** Properties of a PBG module including group and channel information */
typedef struct st_bsp_module_pbg_properties         /* PRQA S 3630, 1536 # Advisory D-4.8, Advisory R-2.4 */
{
    bsp_pbg_group_t pbg_group;                      ///< Guard group
    uint32_t        pbg_channel;                    ///< Guard channel, bit position indicate the channel.
} bsp_module_pbg_properties_t;

/** PBG module info */
typedef struct st_bsp_module_pbg_info               /* PRQA S 1536 # Advisory R-2.4 */
{
    uint8_t no_of_element;                          ///< Number of elements
    uint8_t initial_cfg_value;                      ///< Initial configuration value
    const bsp_module_pbg_properties_t * properties; ///< Pointer to PBG module properties
} bsp_module_pbg_info_t;

/** IBG module properties */
typedef struct st_bsp_module_ibg_properties         /* PRQA S 3630, 1536 # Advisory D-4.8, Advisory R-2.4 */
{
    bsp_ibg_control_t ibg_control;                  ///< IBGuard target
    uint16_t          ibg_channel;                  ///< IBGuard target channel, bit position indicate the channel.
} bsp_module_ibg_properties_t;

/** IBG module info */
typedef struct st_bsp_module_ibg_info               /* PRQA S 1536 # Advisory R-2.4 */
{
    uint8_t no_of_element;                          ///< Number of elements
    uint8_t initial_cfg_value;                      ///< Initial configuration value
    const bsp_module_ibg_properties_t * properties; ///< Pointer to IBG module properties
} bsp_module_ibg_info_t;

/** INTC1 & Local RAM protection info */
typedef struct st_bsp_intc1_lram_info               /* PRQA S 1536 # Advisory R-2.4 */
{
    uint8_t           initial_cfg_value;            ///< Initial configuration flag
    bsp_peg_control_t lram_peg;                     ///< protection control identifier for INTC1 and Local RAM protection
} bsp_intc1_lram_info_t;

/** Cluster RAM protection info */
typedef struct st_bsp_cram_info                     /* PRQA S 1536 # Advisory R-2.4 */
{
    uint8_t           initial_cfg_value;            ///< Initial configuration flag
    bsp_crg_control_t cram_crg;                     ///< protection control identifier for Cluster RAM protection
} bsp_cram_info_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern const bsp_module_pbg_info_t g_bsp_module_pbg_info_table[BSP_MODULE_PBG_TOTAL_INDEX_END];
extern const bsp_module_ibg_info_t g_bsp_module_ibg_info_table[BSP_MODULE_IBG_TOTAL_INDEX_END];
extern const uint32_t              g_pbgprot_baseaddress[BSP_PBG_GROUP_NUM];
extern const uint32_t              g_pbgkcprot_baseaddress[BSP_PBG_GROUP_NUM];
extern const uint32_t              g_pbgprot_control_baseaddress[BSP_PBG_GROUP_NUM];
extern const bsp_intc1_lram_info_t g_bsp_intc1_lram_info_table[BSP_PEG_CONTROL_NUM];
extern const bsp_cram_info_t       g_bsp_cram_info_table[BSP_CRG_CONTROL_NUM];
extern const uint32_t              g_peg_lram_baseaddress[BSP_PEG_CONTROL_NUM];
extern const uint32_t              g_ibg_baseaddress[BSP_IBG_CONTROL_NUM];
extern const uint32_t              g_ibgprot_baseaddress[BSP_IBG_CONTROL_NUM];
extern const uint32_t              g_ibg_module_baseaddress[BSP_MODULE_IBG_TOTAL_INDEX_END];
extern const uint32_t              g_peg_baseaddress[BSP_PEG_CONTROL_NUM];
extern const uint32_t              g_pegcap_s_baseaddress[BSP_PEG_CONTROL_NUM];
extern const uint32_t              g_pegcap_m_baseaddress[BSP_PEG_CONTROL_NUM];
extern const uint32_t              g_crg_baseaddress[BSP_CRG_CONTROL_NUM];
extern const uint32_t              g_crgcap_baseaddress[BSP_CRG_CONTROL_NUM][BSP_FEATURE_CRAM_GUARD_STATUS_MAX];
extern const uint32_t              g_crg_cram_baseaddress[BSP_CRG_CONTROL_NUM];
extern const uint32_t              g_dmacg_baseaddress[BSP_DMAG_UNIT_NUM];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RH850U2BX) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /** End of BSP_GUARD_DRIVER_H */
