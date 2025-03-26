/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : intc_gic_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for GIC.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef INTC_GIC_IODEFINE_H
#define INTC_GIC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t GICD_CTLR;
        struct
        {
            __IOM uint32_t EnableGrp0   : 1;
            __IOM uint32_t EnableGrp1NS : 1;
            __IOM uint32_t EnableGrp1S  : 1;
            uint32_t                    : 1;
            __IOM uint32_t ARE_S        : 1;
            __IOM uint32_t ARE_NS       : 1;
            __IOM uint32_t DS           : 1;
            __IOM uint32_t E1NWF        : 1;
            uint32_t                    : 23;
            __IOM uint32_t RWP          : 1;
        } GICD_CTLR_b;
    };
    union
    {
        __IOM uint32_t GICD_TYPER;
        struct
        {
            __IOM uint32_t ITLineNumber : 5;
            __IOM uint32_t CPUNujmber   : 3;
            __IOM uint32_t ESPI         : 1;
            uint32_t                    : 1;
            __IOM uint32_t SecurityExtn : 1;
            __IOM uint32_t num_LPIs     : 5;
            __IOM uint32_t MBIS         : 1;
            __IOM uint32_t LPIS         : 1;
            __IOM uint32_t DVIS         : 1;
            __IOM uint32_t IDbits       : 5;
            __IOM uint32_t A3V          : 1;
            __IOM uint32_t No1N         : 1;
            __IOM uint32_t RSS          : 1;
            __IOM uint32_t ESPI_range   : 5;
        } GICD_TYPER_b;
    };
    union
    {
        __IOM uint32_t GICD_IIDR;
        struct
        {
            __IOM uint32_t Implementer : 12;
            __IOM uint32_t Revision    : 4;
            __IOM uint32_t Variant     : 4;
            uint32_t                   : 4;
            __IOM uint32_t ProductID   : 8;
        } GICD_IIDR_b;
    };
    __IM uint8_t RESERVED[20];
    union
    {
        __IOM uint32_t GICD_FCTLR;
        struct
        {
            __IOM uint32_t SIP   : 1;
            uint32_t             : 3;
            __IOM uint32_t CGO   : 10;
            uint32_t             : 2;
            __IOM uint32_t NSACR : 2;
            uint32_t             : 3;
            __IM uint32_t DCC    : 1;
            uint32_t             : 3;
            __IOM uint32_t QDENY : 1;
            __IOM uint32_t POS   : 1;
            uint32_t             : 5;
        } GICD_FCTLR_b;
    };
    union
    {
        __IOM uint32_t GICD_SAC;
        struct
        {
            __IOM uint32_t DSL    : 1;
            __IOM uint32_t GICTNS : 1;
            __IOM uint32_t GICPNS : 1;
            uint32_t              : 29;
        } GICD_SAC_b;
    };
    __IM uint8_t RESERVED1[24];
    union
    {
        __IOM uint32_t GICD_SETSPI_NSR;
        struct
        {
            __IOM uint32_t INTID : 13;
            uint32_t             : 19;
        } GICD_SETSPI_NSR_b;
    };
    __IM uint8_t RESERVED2[4];
    union
    {
        __IOM uint32_t GICD_CLRSPI_NSR;
        struct
        {
            __IOM uint32_t INTID : 13;
            uint32_t             : 19;
        } GICD_CLRSPI_NSR_b;
    };
    __IM uint8_t RESERVED3[4];
    union
    {
        __IOM uint32_t GICD_SETSPI_SR;
        struct
        {
            __IOM uint32_t INTID : 13;
            uint32_t             : 19;
        } GICD_SETSPI_SR_b;
    };
    __IM uint8_t RESERVED4[4];
    union
    {
        __IOM uint32_t GICD_CLRSPI_SR;
        struct
        {
            __IOM uint32_t INTID : 13;
            uint32_t             : 19;
        } GICD_CLRSPI_SR_b;
    };
    __IM uint8_t RESERVED5[36];
    union
    {
        __IOM uint32_t GICD_IGROUPR0;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR0_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR1;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR1_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR2;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR2_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR3;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR3_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR4;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR4_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR5;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR5_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR6;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR6_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR7;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR7_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR8;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR8_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR9;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR9_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR10;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR10_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR11;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR11_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR12;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR12_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR13;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR13_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR14;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR14_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR15;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR15_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR16;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR16_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR17;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR17_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR18;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR18_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR19;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR19_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR20;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR20_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR21;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR21_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR22;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR22_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR23;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR23_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR24;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR24_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR25;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR25_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR26;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR26_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR27;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR27_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR28;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR28_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR29;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR29_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR30;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR30_b;
    };
    union
    {
        __IOM uint32_t GICD_IGROUPR31;
        struct
        {
            __IOM uint32_t Group_status_bit : 32;
        } GICD_IGROUPR31_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER0;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER0_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER1;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER1_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER2;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER2_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER3;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER3_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER4;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER4_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER5;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER5_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER6;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER6_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER7;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER7_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER8;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER8_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER9;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER9_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER10;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER10_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER11;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER11_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER12;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER12_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER13;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER13_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER14;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER14_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER15;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER15_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER16;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER16_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER17;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER17_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER18;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER18_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER19;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER19_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER20;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER20_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER21;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER21_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER22;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER22_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER23;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER23_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER24;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER24_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER25;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER25_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER26;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER26_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER27;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER27_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER28;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER28_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER29;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER29_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER30;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER30_b;
    };
    union
    {
        __IOM uint32_t GICD_ISENABLER31;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICD_ISENABLER31_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER0;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER0_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER1;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER1_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER2;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER2_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER3;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER3_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER4;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER4_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER5;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER5_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER6;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER6_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER7;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER7_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER8;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER8_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER9;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER9_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER10;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER10_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER11;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER11_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER12;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER12_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER13;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER13_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER14;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER14_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER15;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER15_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER16;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER16_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER17;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER17_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER18;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER18_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER19;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER19_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER20;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER20_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER21;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER21_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER22;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER22_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER23;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER23_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER24;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER24_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER25;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER25_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER26;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER26_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER27;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER27_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER28;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER28_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER29;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER29_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER30;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER30_b;
    };
    union
    {
        __IOM uint32_t GICD_ICENABLER31;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICD_ICENABLER31_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR0;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR0_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR1;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR1_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR2;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR2_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR3;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR3_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR4;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR4_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR5;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR5_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR6;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR6_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR7;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR7_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR8;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR8_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR9;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR9_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR10;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR10_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR11;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR11_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR12;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR12_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR13;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR13_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR14;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR14_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR15;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR15_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR16;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR16_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR17;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR17_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR18;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR18_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR19;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR19_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR20;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR20_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR21;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR21_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR22;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR22_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR23;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR23_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR24;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR24_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR25;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR25_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR26;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR26_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR27;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR27_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR28;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR28_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR29;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR29_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR30;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR30_b;
    };
    union
    {
        __IOM uint32_t GICD_ISPENDR31;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICD_ISPENDR31_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR0;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR0_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR1;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR1_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR2;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR2_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR3;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR3_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR4;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR4_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR5;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR5_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR6;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR6_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR7;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR7_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR8;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR8_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR9;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR9_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR10;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR10_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR11;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR11_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR12;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR12_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR13;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR13_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR14;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR14_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR15;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR15_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR16;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR16_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR17;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR17_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR18;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR18_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR19;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR19_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR20;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR20_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR21;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR21_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR22;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR22_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR23;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR23_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR24;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR24_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR25;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR25_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR26;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR26_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR27;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR27_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR28;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR28_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR29;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR29_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR30;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR30_b;
    };
    union
    {
        __IOM uint32_t GICD_ICPENDR31;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICD_ICPENDR31_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER0;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER0_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER1;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER1_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER2;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER2_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER3;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER3_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER4;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER4_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER5;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER5_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER6;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER6_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER7;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER7_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER8;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER8_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER9;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER9_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER10;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER10_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER11;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER11_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER12;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER12_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER13;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER13_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER14;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER14_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER15;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER15_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER16;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER16_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER17;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER17_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER18;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER18_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER19;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER19_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER20;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER20_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER21;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER21_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER22;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER22_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER23;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER23_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER24;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER24_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER25;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER25_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER26;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER26_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER27;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER27_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER28;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER28_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER29;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER29_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER30;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER30_b;
    };
    union
    {
        __IOM uint32_t GICD_ISACTIVER31;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICD_ISACTIVER31_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER0;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER0_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER1;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER1_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER2;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER2_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER3;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER3_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER4;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER4_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER5;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER5_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER6;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER6_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER7;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER7_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER8;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER8_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER9;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER9_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER10;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER10_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER11;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER11_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER12;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER12_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER13;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER13_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER14;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER14_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER15;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER15_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER16;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER16_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER17;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER17_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER18;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER18_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER19;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER19_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER20;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER20_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER21;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER21_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER22;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER22_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER23;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER23_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER24;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER24_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER25;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER25_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER26;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER26_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER27;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER27_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER28;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER28_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER29;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER29_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER30;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER30_b;
    };
    union
    {
        __IOM uint32_t GICD_ICACTIVER31;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICD_ICACTIVER31_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR0;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR0_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR1;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR1_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR2;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR2_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR3;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR3_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR4;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR4_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR5;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR5_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR6;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR6_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR7;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR7_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR8;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR8_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR9;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR9_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR10;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR10_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR11;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR11_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR12;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR12_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR13;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR13_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR14;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR14_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR15;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR15_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR16;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR16_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR17;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR17_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR18;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR18_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR19;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR19_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR20;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR20_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR21;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR21_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR22;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR22_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR23;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR23_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR24;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR24_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR25;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR25_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR26;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR26_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR27;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR27_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR28;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR28_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR29;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR29_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR30;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR30_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR31;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR31_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR32;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR32_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR33;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR33_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR34;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR34_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR35;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR35_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR36;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR36_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR37;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR37_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR38;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR38_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR39;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR39_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR40;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR40_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR41;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR41_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR42;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR42_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR43;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR43_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR44;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR44_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR45;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR45_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR46;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR46_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR47;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR47_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR48;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR48_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR49;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR49_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR50;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR50_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR51;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR51_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR52;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR52_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR53;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR53_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR54;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR54_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR55;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR55_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR56;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR56_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR57;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR57_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR58;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR58_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR59;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR59_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR60;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR60_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR61;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR61_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR62;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR62_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR63;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR63_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR64;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR64_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR65;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR65_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR66;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR66_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR67;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR67_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR68;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR68_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR69;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR69_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR70;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR70_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR71;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR71_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR72;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR72_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR73;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR73_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR74;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR74_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR75;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR75_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR76;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR76_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR77;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR77_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR78;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR78_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR79;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR79_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR80;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR80_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR81;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR81_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR82;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR82_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR83;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR83_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR84;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR84_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR85;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR85_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR86;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR86_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR87;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR87_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR88;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR88_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR89;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR89_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR90;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR90_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR91;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR91_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR92;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR92_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR93;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR93_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR94;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR94_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR95;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR95_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR96;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR96_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR97;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR97_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR98;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR98_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR99;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR99_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR100;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR100_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR101;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR101_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR102;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR102_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR103;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR103_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR104;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR104_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR105;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR105_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR106;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR106_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR107;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR107_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR108;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR108_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR109;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR109_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR110;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR110_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR111;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR111_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR112;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR112_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR113;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR113_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR114;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR114_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR115;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR115_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR116;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR116_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR117;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR117_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR118;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR118_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR119;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR119_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR120;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR120_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR121;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR121_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR122;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR122_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR123;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR123_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR124;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR124_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR125;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR125_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR126;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR126_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR127;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR127_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR128;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR128_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR129;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR129_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR130;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR130_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR131;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR131_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR132;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR132_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR133;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR133_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR134;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR134_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR135;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR135_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR136;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR136_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR137;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR137_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR138;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR138_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR139;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR139_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR140;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR140_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR141;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR141_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR142;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR142_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR143;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR143_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR144;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR144_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR145;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR145_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR146;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR146_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR147;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR147_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR148;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR148_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR149;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR149_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR150;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR150_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR151;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR151_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR152;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR152_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR153;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR153_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR154;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR154_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR155;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR155_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR156;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR156_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR157;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR157_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR158;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR158_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR159;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR159_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR160;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR160_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR161;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR161_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR162;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR162_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR163;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR163_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR164;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR164_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR165;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR165_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR166;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR166_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR167;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR167_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR168;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR168_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR169;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR169_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR170;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR170_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR171;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR171_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR172;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR172_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR173;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR173_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR174;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR174_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR175;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR175_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR176;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR176_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR177;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR177_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR178;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR178_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR179;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR179_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR180;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR180_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR181;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR181_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR182;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR182_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR183;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR183_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR184;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR184_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR185;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR185_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR186;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR186_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR187;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR187_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR188;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR188_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR189;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR189_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR190;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR190_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR191;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR191_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR192;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR192_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR193;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR193_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR194;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR194_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR195;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR195_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR196;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR196_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR197;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR197_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR198;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR198_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR199;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR199_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR200;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR200_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR201;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR201_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR202;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR202_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR203;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR203_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR204;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR204_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR205;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR205_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR206;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR206_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR207;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR207_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR208;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR208_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR209;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR209_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR210;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR210_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR211;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR211_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR212;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR212_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR213;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR213_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR214;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR214_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR215;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR215_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR216;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR216_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR217;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR217_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR218;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR218_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR219;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR219_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR220;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR220_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR221;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR221_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR222;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR222_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR223;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR223_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR224;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR224_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR225;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR225_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR226;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR226_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR227;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR227_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR228;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR228_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR229;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR229_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR230;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR230_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR231;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR231_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR232;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR232_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR233;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR233_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR234;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR234_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR235;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR235_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR236;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR236_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR237;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR237_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR238;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR238_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR239;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR239_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR240;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR240_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR241;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR241_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR242;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR242_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR243;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR243_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR244;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR244_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR245;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR245_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR246;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR246_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR247;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR247_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR248;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR248_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR249;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR249_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR250;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR250_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR251;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR251_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR252;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR252_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR253;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR253_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR254;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR254_b;
    };
    union
    {
        __IOM uint32_t GICD_IPRIORITYR255;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICD_IPRIORITYR255_b;
    };
    __IM uint8_t RESERVED6[1024];
    union
    {
        __IOM uint32_t GICD_ICFGR0;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR0_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR1;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR1_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR2;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR2_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR3;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR3_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR4;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR4_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR5;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR5_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR6;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR6_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR7;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR7_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR8;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR8_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR9;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR9_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR10;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR10_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR11;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR11_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR12;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR12_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR13;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR13_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR14;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR14_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR15;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR15_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR16;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR16_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR17;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR17_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR18;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR18_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR19;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR19_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR20;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR20_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR21;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR21_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR22;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR22_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR23;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR23_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR24;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR24_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR25;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR25_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR26;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR26_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR27;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR27_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR28;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR28_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR29;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR29_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR30;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR30_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR31;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR31_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR32;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR32_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR33;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR33_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR34;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR34_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR35;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR35_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR36;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR36_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR37;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR37_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR38;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR38_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR39;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR39_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR40;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR40_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR41;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR41_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR42;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR42_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR43;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR43_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR44;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR44_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR45;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR45_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR46;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR46_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR47;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR47_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR48;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR48_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR49;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR49_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR50;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR50_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR51;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR51_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR52;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR52_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR53;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR53_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR54;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR54_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR55;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR55_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR56;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR56_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR57;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR57_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR58;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR58_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR59;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR59_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR60;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR60_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR61;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR61_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR62;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR62_b;
    };
    union
    {
        __IOM uint32_t GICD_ICFGR63;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICD_ICFGR63_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR0;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR0_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR1;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR1_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR2;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR2_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR3;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR3_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR4;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR4_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR5;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR5_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR6;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR6_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR7;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR7_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR8;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR8_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR9;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR9_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR10;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR10_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR11;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR11_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR12;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR12_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR13;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR13_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR14;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR14_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR15;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR15_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR16;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR16_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR17;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR17_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR18;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR18_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR19;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR19_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR20;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR20_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR21;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR21_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR22;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR22_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR23;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR23_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR24;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR24_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR25;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR25_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR26;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR26_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR27;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR27_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR28;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR28_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR29;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR29_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR30;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR30_b;
    };
    union
    {
        __IOM uint32_t GICD_IGRPMODR31;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICD_IGRPMODR31_b;
    };
    __IM uint8_t RESERVED7[128];
    union
    {
        __IOM uint32_t GICD_NSACR0;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR0_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR1;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR1_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR2;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR2_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR3;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR3_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR4;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR4_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR5;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR5_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR6;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR6_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR7;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR7_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR8;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR8_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR9;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR9_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR10;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR10_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR11;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR11_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR12;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR12_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR13;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR13_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR14;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR14_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR15;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR15_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR16;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR16_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR17;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR17_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR18;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR18_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR19;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR19_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR20;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR20_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR21;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR21_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR22;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR22_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR23;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR23_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR24;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR24_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR25;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR25_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR26;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR26_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR27;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR27_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR28;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR28_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR29;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR29_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR30;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR30_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR31;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR31_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR32;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR32_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR33;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR33_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR34;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR34_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR35;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR35_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR36;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR36_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR37;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR37_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR38;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR38_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR39;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR39_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR40;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR40_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR41;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR41_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR42;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR42_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR43;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR43_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR44;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR44_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR45;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR45_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR46;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR46_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR47;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR47_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR48;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR48_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR49;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR49_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR50;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR50_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR51;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR51_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR52;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR52_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR53;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR53_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR54;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR54_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR55;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR55_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR56;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR56_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR57;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR57_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR58;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR58_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR59;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR59_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR60;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR60_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR61;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR61_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR62;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR62_b;
    };
    union
    {
        __IOM uint32_t GICD_NSACR63;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICD_NSACR63_b;
    };
    __IM uint8_t RESERVED8[20992];
    union
    {
        __IOM uint64_t GICD_IROUTER32;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER32_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER33;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER33_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER34;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER34_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER35;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER35_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER36;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER36_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER37;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER37_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER38;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER38_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER39;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER39_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER40;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER40_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER41;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER41_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER42;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER42_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER43;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER43_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER44;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER44_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER45;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER45_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER46;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER46_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER47;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER47_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER48;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER48_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER49;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER49_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER50;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER50_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER51;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER51_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER52;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER52_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER53;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER53_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER54;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER54_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER55;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER55_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER56;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER56_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER57;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER57_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER58;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER58_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER59;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER59_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER60;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER60_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER61;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER61_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER62;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER62_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER63;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER63_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER64;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER64_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER65;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER65_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER66;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER66_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER67;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER67_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER68;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER68_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER69;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER69_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER70;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER70_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER71;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER71_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER72;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER72_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER73;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER73_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER74;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER74_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER75;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER75_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER76;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER76_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER77;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER77_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER78;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER78_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER79;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER79_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER80;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER80_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER81;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER81_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER82;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER82_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER83;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER83_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER84;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER84_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER85;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER85_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER86;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER86_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER87;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER87_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER88;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER88_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER89;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER89_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER90;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER90_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER91;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER91_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER92;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER92_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER93;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER93_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER94;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER94_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER95;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER95_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER96;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER96_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER97;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER97_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER98;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER98_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER99;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER99_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER100;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER100_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER101;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER101_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER102;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER102_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER103;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER103_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER104;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER104_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER105;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER105_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER106;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER106_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER107;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER107_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER108;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER108_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER109;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER109_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER110;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER110_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER111;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER111_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER112;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER112_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER113;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER113_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER114;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER114_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER115;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER115_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER116;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER116_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER117;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER117_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER118;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER118_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER119;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER119_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER120;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER120_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER121;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER121_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER122;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER122_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER123;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER123_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER124;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER124_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER125;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER125_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER126;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER126_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER127;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER127_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER128;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER128_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER129;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER129_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER130;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER130_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER131;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER131_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER132;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER132_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER133;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER133_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER134;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER134_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER135;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER135_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER136;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER136_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER137;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER137_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER138;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER138_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER139;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER139_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER140;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER140_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER141;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER141_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER142;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER142_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER143;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER143_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER144;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER144_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER145;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER145_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER146;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER146_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER147;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER147_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER148;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER148_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER149;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER149_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER150;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER150_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER151;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER151_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER152;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER152_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER153;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER153_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER154;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER154_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER155;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER155_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER156;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER156_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER157;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER157_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER158;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER158_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER159;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER159_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER160;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER160_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER161;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER161_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER162;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER162_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER163;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER163_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER164;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER164_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER165;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER165_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER166;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER166_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER167;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER167_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER168;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER168_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER169;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER169_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER170;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER170_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER171;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER171_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER172;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER172_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER173;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER173_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER174;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER174_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER175;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER175_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER176;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER176_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER177;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER177_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER178;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER178_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER179;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER179_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER180;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER180_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER181;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER181_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER182;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER182_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER183;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER183_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER184;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER184_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER185;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER185_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER186;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER186_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER187;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER187_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER188;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER188_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER189;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER189_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER190;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER190_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER191;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER191_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER192;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER192_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER193;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER193_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER194;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER194_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER195;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER195_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER196;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER196_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER197;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER197_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER198;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER198_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER199;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER199_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER200;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER200_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER201;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER201_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER202;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER202_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER203;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER203_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER204;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER204_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER205;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER205_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER206;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER206_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER207;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER207_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER208;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER208_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER209;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER209_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER210;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER210_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER211;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER211_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER212;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER212_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER213;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER213_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER214;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER214_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER215;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER215_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER216;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER216_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER217;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER217_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER218;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER218_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER219;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER219_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER220;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER220_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER221;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER221_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER222;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER222_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER223;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER223_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER224;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER224_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER225;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER225_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER226;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER226_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER227;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER227_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER228;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER228_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER229;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER229_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER230;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER230_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER231;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER231_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER232;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER232_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER233;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER233_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER234;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER234_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER235;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER235_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER236;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER236_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER237;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER237_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER238;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER238_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER239;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER239_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER240;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER240_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER241;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER241_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER242;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER242_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER243;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER243_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER244;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER244_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER245;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER245_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER246;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER246_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER247;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER247_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER248;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER248_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER249;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER249_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER250;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER250_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER251;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER251_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER252;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER252_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER253;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER253_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER254;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER254_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER255;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER255_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER256;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER256_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER257;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER257_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER258;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER258_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER259;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER259_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER260;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER260_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER261;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER261_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER262;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER262_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER263;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER263_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER264;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER264_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER265;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER265_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER266;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER266_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER267;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER267_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER268;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER268_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER269;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER269_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER270;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER270_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER271;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER271_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER272;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER272_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER273;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER273_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER274;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER274_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER275;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER275_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER276;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER276_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER277;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER277_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER278;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER278_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER279;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER279_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER280;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER280_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER281;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER281_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER282;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER282_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER283;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER283_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER284;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER284_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER285;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER285_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER286;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER286_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER287;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER287_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER288;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER288_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER289;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER289_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER290;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER290_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER291;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER291_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER292;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER292_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER293;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER293_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER294;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER294_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER295;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER295_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER296;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER296_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER297;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER297_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER298;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER298_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER299;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER299_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER300;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER300_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER301;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER301_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER302;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER302_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER303;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER303_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER304;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER304_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER305;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER305_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER306;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER306_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER307;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER307_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER308;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER308_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER309;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER309_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER310;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER310_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER311;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER311_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER312;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER312_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER313;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER313_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER314;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER314_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER315;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER315_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER316;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER316_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER317;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER317_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER318;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER318_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER319;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER319_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER320;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER320_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER321;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER321_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER322;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER322_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER323;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER323_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER324;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER324_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER325;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER325_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER326;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER326_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER327;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER327_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER328;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER328_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER329;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER329_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER330;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER330_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER331;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER331_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER332;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER332_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER333;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER333_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER334;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER334_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER335;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER335_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER336;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER336_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER337;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER337_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER338;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER338_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER339;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER339_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER340;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER340_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER341;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER341_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER342;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER342_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER343;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER343_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER344;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER344_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER345;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER345_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER346;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER346_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER347;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER347_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER348;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER348_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER349;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER349_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER350;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER350_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER351;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER351_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER352;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER352_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER353;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER353_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER354;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER354_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER355;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER355_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER356;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER356_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER357;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER357_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER358;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER358_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER359;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER359_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER360;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER360_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER361;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER361_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER362;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER362_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER363;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER363_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER364;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER364_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER365;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER365_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER366;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER366_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER367;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER367_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER368;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER368_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER369;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER369_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER370;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER370_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER371;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER371_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER372;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER372_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER373;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER373_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER374;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER374_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER375;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER375_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER376;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER376_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER377;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER377_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER378;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER378_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER379;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER379_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER380;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER380_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER381;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER381_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER382;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER382_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER383;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER383_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER384;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER384_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER385;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER385_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER386;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER386_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER387;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER387_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER388;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER388_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER389;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER389_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER390;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER390_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER391;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER391_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER392;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER392_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER393;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER393_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER394;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER394_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER395;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER395_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER396;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER396_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER397;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER397_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER398;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER398_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER399;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER399_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER400;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER400_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER401;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER401_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER402;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER402_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER403;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER403_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER404;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER404_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER405;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER405_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER406;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER406_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER407;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER407_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER408;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER408_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER409;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER409_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER410;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER410_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER411;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER411_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER412;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER412_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER413;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER413_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER414;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER414_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER415;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER415_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER416;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER416_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER417;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER417_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER418;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER418_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER419;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER419_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER420;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER420_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER421;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER421_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER422;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER422_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER423;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER423_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER424;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER424_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER425;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER425_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER426;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER426_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER427;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER427_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER428;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER428_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER429;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER429_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER430;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER430_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER431;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER431_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER432;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER432_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER433;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER433_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER434;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER434_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER435;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER435_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER436;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER436_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER437;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER437_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER438;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER438_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER439;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER439_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER440;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER440_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER441;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER441_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER442;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER442_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER443;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER443_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER444;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER444_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER445;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER445_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER446;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER446_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER447;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER447_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER448;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER448_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER449;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER449_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER450;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER450_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER451;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER451_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER452;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER452_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER453;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER453_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER454;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER454_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER455;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER455_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER456;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER456_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER457;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER457_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER458;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER458_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER459;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER459_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER460;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER460_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER461;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER461_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER462;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER462_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER463;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER463_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER464;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER464_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER465;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER465_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER466;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER466_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER467;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER467_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER468;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER468_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER469;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER469_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER470;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER470_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER471;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER471_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER472;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER472_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER473;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER473_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER474;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER474_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER475;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER475_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER476;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER476_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER477;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER477_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER478;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER478_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER479;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER479_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER480;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER480_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER481;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER481_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER482;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER482_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER483;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER483_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER484;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER484_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER485;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER485_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER486;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER486_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER487;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER487_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER488;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER488_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER489;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER489_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER490;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER490_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER491;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER491_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER492;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER492_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER493;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER493_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER494;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER494_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER495;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER495_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER496;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER496_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER497;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER497_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER498;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER498_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER499;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER499_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER500;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER500_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER501;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER501_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER502;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER502_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER503;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER503_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER504;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER504_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER505;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER505_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER506;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER506_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER507;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER507_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER508;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER508_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER509;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER509_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER510;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER510_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER511;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER511_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER512;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER512_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER513;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER513_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER514;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER514_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER515;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER515_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER516;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER516_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER517;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER517_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER518;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER518_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER519;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER519_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER520;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER520_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER521;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER521_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER522;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER522_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER523;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER523_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER524;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER524_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER525;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER525_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER526;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER526_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER527;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER527_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER528;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER528_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER529;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER529_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER530;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER530_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER531;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER531_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER532;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER532_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER533;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER533_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER534;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER534_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER535;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER535_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER536;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER536_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER537;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER537_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER538;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER538_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER539;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER539_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER540;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER540_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER541;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER541_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER542;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER542_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER543;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER543_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER544;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER544_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER545;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER545_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER546;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER546_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER547;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER547_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER548;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER548_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER549;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER549_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER550;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER550_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER551;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER551_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER552;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER552_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER553;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER553_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER554;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER554_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER555;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER555_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER556;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER556_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER557;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER557_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER558;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER558_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER559;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER559_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER560;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER560_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER561;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER561_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER562;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER562_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER563;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER563_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER564;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER564_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER565;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER565_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER566;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER566_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER567;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER567_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER568;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER568_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER569;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER569_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER570;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER570_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER571;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER571_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER572;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER572_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER573;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER573_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER574;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER574_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER575;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER575_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER576;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER576_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER577;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER577_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER578;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER578_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER579;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER579_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER580;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER580_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER581;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER581_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER582;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER582_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER583;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER583_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER584;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER584_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER585;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER585_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER586;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER586_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER587;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER587_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER588;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER588_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER589;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER589_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER590;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER590_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER591;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER591_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER592;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER592_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER593;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER593_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER594;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER594_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER595;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER595_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER596;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER596_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER597;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER597_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER598;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER598_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER599;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER599_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER600;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER600_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER601;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER601_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER602;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER602_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER603;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER603_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER604;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER604_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER605;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER605_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER606;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER606_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER607;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER607_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER608;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER608_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER609;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER609_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER610;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER610_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER611;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER611_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER612;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER612_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER613;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER613_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER614;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER614_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER615;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER615_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER616;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER616_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER617;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER617_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER618;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER618_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER619;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER619_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER620;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER620_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER621;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER621_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER622;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER622_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER623;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER623_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER624;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER624_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER625;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER625_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER626;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER626_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER627;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER627_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER628;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER628_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER629;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER629_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER630;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER630_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER631;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER631_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER632;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER632_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER633;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER633_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER634;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER634_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER635;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER635_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER636;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER636_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER637;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER637_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER638;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER638_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER639;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER639_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER640;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER640_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER641;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER641_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER642;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER642_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER643;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER643_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER644;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER644_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER645;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER645_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER646;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER646_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER647;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER647_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER648;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER648_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER649;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER649_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER650;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER650_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER651;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER651_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER652;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER652_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER653;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER653_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER654;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER654_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER655;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER655_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER656;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER656_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER657;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER657_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER658;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER658_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER659;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER659_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER660;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER660_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER661;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER661_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER662;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER662_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER663;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER663_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER664;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER664_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER665;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER665_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER666;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER666_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER667;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER667_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER668;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER668_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER669;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER669_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER670;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER670_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER671;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER671_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER672;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER672_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER673;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER673_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER674;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER674_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER675;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER675_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER676;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER676_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER677;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER677_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER678;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER678_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER679;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER679_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER680;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER680_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER681;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER681_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER682;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER682_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER683;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER683_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER684;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER684_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER685;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER685_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER686;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER686_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER687;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER687_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER688;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER688_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER689;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER689_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER690;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER690_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER691;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER691_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER692;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER692_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER693;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER693_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER694;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER694_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER695;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER695_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER696;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER696_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER697;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER697_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER698;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER698_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER699;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER699_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER700;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER700_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER701;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER701_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER702;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER702_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER703;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER703_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER704;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER704_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER705;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER705_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER706;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER706_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER707;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER707_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER708;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER708_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER709;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER709_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER710;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER710_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER711;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER711_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER712;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER712_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER713;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER713_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER714;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER714_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER715;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER715_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER716;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER716_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER717;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER717_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER718;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER718_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER719;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER719_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER720;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER720_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER721;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER721_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER722;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER722_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER723;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER723_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER724;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER724_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER725;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER725_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER726;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER726_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER727;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER727_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER728;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER728_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER729;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER729_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER730;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER730_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER731;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER731_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER732;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER732_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER733;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER733_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER734;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER734_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER735;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER735_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER736;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER736_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER737;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER737_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER738;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER738_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER739;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER739_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER740;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER740_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER741;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER741_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER742;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER742_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER743;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER743_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER744;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER744_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER745;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER745_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER746;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER746_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER747;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER747_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER748;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER748_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER749;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER749_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER750;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER750_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER751;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER751_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER752;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER752_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER753;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER753_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER754;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER754_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER755;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER755_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER756;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER756_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER757;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER757_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER758;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER758_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER759;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER759_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER760;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER760_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER761;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER761_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER762;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER762_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER763;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER763_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER764;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER764_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER765;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER765_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER766;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER766_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER767;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER767_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER768;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER768_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER769;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER769_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER770;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER770_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER771;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER771_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER772;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER772_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER773;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER773_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER774;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER774_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER775;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER775_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER776;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER776_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER777;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER777_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER778;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER778_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER779;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER779_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER780;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER780_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER781;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER781_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER782;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER782_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER783;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER783_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER784;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER784_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER785;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER785_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER786;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER786_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER787;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER787_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER788;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER788_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER789;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER789_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER790;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER790_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER791;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER791_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER792;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER792_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER793;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER793_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER794;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER794_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER795;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER795_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER796;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER796_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER797;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER797_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER798;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER798_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER799;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER799_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER800;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER800_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER801;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER801_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER802;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER802_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER803;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER803_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER804;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER804_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER805;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER805_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER806;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER806_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER807;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER807_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER808;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER808_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER809;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER809_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER810;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER810_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER811;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER811_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER812;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER812_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER813;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER813_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER814;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER814_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER815;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER815_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER816;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER816_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER817;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER817_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER818;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER818_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER819;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER819_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER820;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER820_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER821;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER821_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER822;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER822_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER823;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER823_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER824;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER824_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER825;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER825_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER826;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER826_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER827;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER827_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER828;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER828_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER829;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER829_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER830;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER830_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER831;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER831_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER832;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER832_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER833;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER833_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER834;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER834_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER835;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER835_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER836;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER836_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER837;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER837_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER838;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER838_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER839;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER839_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER840;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER840_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER841;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER841_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER842;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER842_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER843;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER843_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER844;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER844_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER845;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER845_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER846;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER846_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER847;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER847_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER848;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER848_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER849;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER849_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER850;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER850_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER851;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER851_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER852;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER852_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER853;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER853_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER854;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER854_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER855;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER855_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER856;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER856_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER857;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER857_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER858;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER858_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER859;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER859_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER860;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER860_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER861;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER861_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER862;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER862_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER863;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER863_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER864;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER864_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER865;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER865_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER866;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER866_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER867;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER867_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER868;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER868_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER869;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER869_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER870;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER870_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER871;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER871_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER872;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER872_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER873;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER873_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER874;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER874_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER875;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER875_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER876;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER876_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER877;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER877_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER878;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER878_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER879;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER879_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER880;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER880_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER881;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER881_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER882;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER882_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER883;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER883_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER884;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER884_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER885;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER885_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER886;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER886_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER887;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER887_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER888;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER888_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER889;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER889_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER890;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER890_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER891;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER891_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER892;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER892_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER893;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER893_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER894;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER894_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER895;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER895_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER896;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER896_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER897;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER897_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER898;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER898_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER899;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER899_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER900;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER900_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER901;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER901_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER902;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER902_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER903;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER903_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER904;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER904_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER905;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER905_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER906;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER906_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER907;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER907_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER908;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER908_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER909;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER909_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER910;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER910_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER911;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER911_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER912;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER912_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER913;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER913_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER914;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER914_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER915;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER915_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER916;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER916_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER917;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER917_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER918;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER918_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER919;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER919_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER920;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER920_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER921;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER921_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER922;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER922_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER923;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER923_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER924;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER924_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER925;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER925_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER926;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER926_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER927;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER927_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER928;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER928_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER929;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER929_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER930;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER930_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER931;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER931_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER932;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER932_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER933;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER933_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER934;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER934_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER935;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER935_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER936;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER936_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER937;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER937_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER938;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER938_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER939;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER939_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER940;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER940_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER941;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER941_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER942;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER942_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER943;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER943_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER944;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER944_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER945;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER945_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER946;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER946_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER947;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER947_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER948;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER948_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER949;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER949_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER950;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER950_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER951;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER951_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER952;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER952_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER953;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER953_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER954;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER954_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER955;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER955_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER956;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER956_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER957;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER957_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER958;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER958_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER959;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER959_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER960;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER960_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER961;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER961_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER962;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER962_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER963;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER963_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER964;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER964_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER965;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER965_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER966;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER966_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER967;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER967_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER968;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER968_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER969;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER969_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER970;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER970_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER971;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER971_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER972;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER972_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER973;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER973_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER974;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER974_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER975;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER975_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER976;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER976_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER977;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER977_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER978;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER978_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER979;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER979_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER980;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER980_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER981;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER981_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER982;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER982_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER983;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER983_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER984;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER984_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER985;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER985_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER986;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER986_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER987;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER987_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER988;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER988_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER989;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER989_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER990;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER990_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER991;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER991_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER992;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER992_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER993;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER993_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER994;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER994_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER995;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER995_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER996;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER996_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER997;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER997_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER998;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER998_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER999;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER999_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1000;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1000_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1001;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1001_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1002;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1002_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1003;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1003_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1004;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1004_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1005;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1005_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1006;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1006_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1007;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1007_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1008;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1008_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1009;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1009_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1010;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1010_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1011;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1011_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1012;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1012_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1013;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1013_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1014;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1014_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1015;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1015_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1016;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1016_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1017;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1017_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1018;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1018_b;
    };
    union
    {
        __IOM uint64_t GICD_IROUTER1019;
        struct
        {
            __IOM uint64_t Aff0                   : 8;
            __IOM uint64_t Aff1                   : 8;
            __IOM uint64_t Aff2                   : 8;
            uint64_t                              : 7;
            __IOM uint64_t Interrupt_Routing_Mode : 1;
            __IOM uint64_t Aff3                   : 8;
            uint64_t                              : 24;
        } GICD_IROUTER1019_b;
    };
    __IM uint8_t RESERVED9[16416];
    union
    {
        __IOM uint32_t GICD_CHIPSR;
        struct
        {
            __IOM uint32_t GTR : 1;
            __IOM uint32_t GTS : 1;
            __IOM uint32_t GTO : 1;
            uint32_t           : 1;
            __IOM uint32_t RTS : 2;
            uint32_t           : 26;
        } GICD_CHIPSR_b;
    };
    union
    {
        __IOM uint32_t GICD_DCHIPR;
        struct
        {
            __IOM uint32_t RUP      : 1;
            uint32_t                : 3;
            __IOM uint32_t rt_owner : 4;
            uint32_t                : 24;
        } GICD_DCHIPR_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR0;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR0_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR1;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR1_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR2;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR2_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR3;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR3_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR4;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR4_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR5;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR5_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR6;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR6_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR7;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR7_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR8;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR8_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR9;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR9_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR10;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR10_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR11;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR11_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR12;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR12_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR13;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR13_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR14;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR14_b;
    };
    union
    {
        __IOM uint64_t GICD_CHIPR15;
        struct
        {
            __IOM uint64_t SocketState   : 1;
            __IOM uint64_t RUP           : 1;
            uint64_t                     : 3;
            __IOM uint64_t SPI_BLOCKS    : 5;
            __IOM uint64_t SPI_BLOCK_MIN : 6;
            __IOM uint64_t ADDR          : 32;
            uint64_t                     : 16;
        } GICD_CHIPR15_b;
    };
    __IM uint8_t RESERVED10[8064];
    union
    {
        __IOM uint32_t GICD_ICLAR2;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR2_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR3;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR3_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR4;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR4_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR5;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR5_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR6;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR6_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR7;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR7_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR8;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR8_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR9;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR9_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR10;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR10_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR11;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR11_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR12;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR12_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR13;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR13_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR14;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR14_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR15;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR15_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR16;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR16_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR17;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR17_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR18;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR18_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR19;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR19_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR20;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR20_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR21;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR21_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR22;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR22_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR23;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR23_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR24;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR24_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR25;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR25_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR26;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR26_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR27;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR27_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR28;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR28_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR29;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR29_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR30;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR30_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR31;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR31_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR32;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR32_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR33;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR33_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR34;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR34_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR35;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR35_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR36;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR36_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR37;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR37_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR38;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR38_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR39;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR39_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR40;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR40_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR41;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR41_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR42;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR42_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR43;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR43_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR44;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR44_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR45;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR45_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR46;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR46_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR47;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR47_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR48;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR48_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR49;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR49_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR50;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR50_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR51;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR51_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR52;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR52_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR53;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR53_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR54;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR54_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR55;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR55_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR56;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR56_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR57;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR57_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR58;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR58_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR59;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR59_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR60;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR60_b;
    };
    union
    {
        __IOM uint32_t GICD_ICLAR61;
        struct
        {
            __IOM uint32_t Class0_0  : 1;
            __IOM uint32_t Class1_0  : 1;
            __IOM uint32_t Class0_1  : 1;
            __IOM uint32_t Class1_1  : 1;
            __IOM uint32_t Class0_2  : 1;
            __IOM uint32_t Class1_2  : 1;
            __IOM uint32_t Class0_3  : 1;
            __IOM uint32_t Class1_3  : 1;
            __IOM uint32_t Class0_4  : 1;
            __IOM uint32_t Class1_4  : 1;
            __IOM uint32_t Class0_5  : 1;
            __IOM uint32_t Class1_5  : 1;
            __IOM uint32_t Class0_6  : 1;
            __IOM uint32_t Class1_6  : 1;
            __IOM uint32_t Class0_7  : 1;
            __IOM uint32_t Class1_7  : 1;
            __IOM uint32_t Class0_8  : 1;
            __IOM uint32_t Class1_8  : 1;
            __IOM uint32_t Class0_9  : 1;
            __IOM uint32_t Class1_9  : 1;
            __IOM uint32_t Class0_10 : 1;
            __IOM uint32_t Class1_10 : 1;
            __IOM uint32_t Class0_11 : 1;
            __IOM uint32_t Class1_11 : 1;
            __IOM uint32_t Class0_12 : 1;
            __IOM uint32_t Class1_12 : 1;
            __IOM uint32_t Class0_13 : 1;
            __IOM uint32_t Class1_13 : 1;
            __IOM uint32_t Class0_14 : 1;
            __IOM uint32_t Class1_14 : 1;
            __IOM uint32_t Class0_15 : 1;
            __IOM uint32_t Class1_15 : 1;
        } GICD_ICLAR61_b;
    };
    __IM uint8_t RESERVED11[16];
    union
    {
        __IOM uint32_t GICD_IERRR1;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR1_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR2;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR2_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR3;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR3_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR4;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR4_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR5;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR5_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR6;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR6_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR7;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR7_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR8;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR8_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR9;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR9_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR10;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR10_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR11;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR11_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR12;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR12_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR13;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR13_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR14;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR14_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR15;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR15_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR16;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR16_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR17;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR17_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR18;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR18_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR19;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR19_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR20;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR20_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR21;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR21_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR22;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR22_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR23;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR23_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR24;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR24_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR25;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR25_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR26;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR26_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR27;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR27_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR28;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR28_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR29;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR29_b;
    };
    union
    {
        __IOM uint32_t GICD_IERRR30;
        struct
        {
            __IOM uint32_t Status : 32;
        } GICD_IERRR30_b;
    };
    __IM uint8_t RESERVED12[3712];
    union
    {
        __IOM uint64_t GICD_CFGID;
        struct
        {
            __IM uint64_t SO   : 1;
            uint64_t           : 3;
            __IM uint64_t SNUM : 4;
            uint64_t           : 4;
            __IM uint64_t AFSL : 1;
            __IM uint64_t DLPI : 1;
            __IM uint64_t LPIS : 1;
            __IM uint64_t SPIS : 6;
            uint64_t           : 11;
            __IM uint64_t Aff0 : 4;
            __IM uint64_t Aff1 : 4;
            __IM uint64_t Aff2 : 4;
            __IM uint64_t Aff3 : 4;
            __IM uint64_t PEW  : 5;
            uint64_t           : 11;
        } GICD_CFGID_b;
    };
    __IM uint8_t RESERVED13[4040];
    union
    {
        __IM uint32_t GICD_PIDR4;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICD_PIDR4_b;
    };
    union
    {
        __IM uint32_t GICD_PIDR5;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 3;
            uint32_t            : 25;
        } GICD_PIDR5_b;
    };
    union
    {
        __IM uint32_t GICD_PIDR6;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICD_PIDR6_b;
    };
    union
    {
        __IM uint32_t GICD_PIDR7;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICD_PIDR7_b;
    };
    union
    {
        __IM uint32_t GICD_PIDR0;
        struct
        {
            __IM uint32_t PART_0 : 8;
            uint32_t             : 24;
        } GICD_PIDR0_b;
    };
    union
    {
        __IM uint32_t GICD_PIDR1;
        struct
        {
            __IM uint32_t PART_1 : 4;
            __IM uint32_t DES_0  : 4;
            uint32_t             : 24;
        } GICD_PIDR1_b;
    };
    union
    {
        __IM uint32_t GICD_PIDR2;
        struct
        {
            __IM uint32_t DES_1   : 3;
            __IM uint32_t JEDEC   : 1;
            __IM uint32_t ArchRev : 4;
            uint32_t              : 24;
        } GICD_PIDR2_b;
    };
    union
    {
        __IM uint32_t GICD_PIDR3;
        struct
        {
            __IM uint32_t CMOD   : 4;
            __IM uint32_t REVAND : 4;
            uint32_t             : 24;
        } GICD_PIDR3_b;
    };
    __IM uint32_t GICD_CIDR0;
    __IM uint32_t GICD_CIDR1;
    __IM uint32_t GICD_CIDR2;
    __IM uint32_t GICD_CIDR3;
    __IM uint8_t  RESERVED14[64];
    union
    {
        __IOM uint32_t GICA_SETSPI_NSR;
        struct
        {
            __IOM uint32_t INTID : 13;
            uint32_t             : 19;
        } GICA_SETSPI_NSR_b;
    };
    __IM uint8_t RESERVED15[4];
    union
    {
        __IOM uint32_t GICA_CLRSPI_NSR;
        struct
        {
            __IOM uint32_t INTID : 13;
            uint32_t             : 19;
        } GICA_CLRSPI_NSR_b;
    };
    __IM uint8_t RESERVED16[4];
    union
    {
        __IOM uint32_t GICA_SETSPI_SR;
        struct
        {
            __IOM uint32_t INTID : 13;
            uint32_t             : 19;
        } GICA_SETSPI_SR_b;
    };
    __IM uint8_t RESERVED17[4];
    union
    {
        __IOM uint32_t GICA_CLRSPI_SR;
        struct
        {
            __IOM uint32_t INTID : 13;
            uint32_t             : 19;
        } GICA_CLRSPI_SR_b;
    };
    __IM uint8_t RESERVED18[65444];
    union
    {
        __IOM uint64_t GICT_ERR0FR;
        struct
        {
            __IM uint64_t ED  : 2;
            __IM uint64_t DE  : 2;
            __IM uint64_t UI  : 2;
            __IM uint64_t FI  : 2;
            __IM uint64_t UE  : 2;
            __IM uint64_t CFI : 2;
            __IM uint64_t CEC : 3;
            __IM uint64_t RP  : 1;
            uint64_t          : 48;
        } GICT_ERR0FR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR0CTLR;
        struct
        {
            uint64_t           : 2;
            __IOM uint64_t UI  : 1;
            __IOM uint64_t FI  : 1;
            __IOM uint64_t UE  : 1;
            uint64_t           : 3;
            __IOM uint64_t CFI : 1;
            uint64_t           : 6;
            __IOM uint64_t RP  : 1;
            uint64_t           : 48;
        } GICT_ERR0CTLR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR0STATUS;
        struct
        {
            __IOM uint64_t SERR : 8;
            __IOM uint64_t IERR : 8;
            uint64_t            : 4;
            __IOM uint64_t UET  : 2;
            uint64_t            : 2;
            __IOM uint64_t CE   : 2;
            __IOM uint64_t MV   : 1;
            __IOM uint64_t OF   : 1;
            __IOM uint64_t ER   : 1;
            __IOM uint64_t UE   : 1;
            __IOM uint64_t V    : 1;
            __IOM uint64_t AV   : 1;
            uint64_t            : 32;
        } GICT_ERR0STATUS_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR0ADDR;
        struct
        {
            __IOM uint64_t PADDR : 48;
            uint64_t             : 15;
            __IOM uint64_t NS    : 1;
        } GICT_ERR0ADDR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR0MISC0;
        struct
        {
            __IOM uint64_t Data     : 32;
            __IOM uint64_t Overflow : 1;
            __IOM uint64_t RE       : 1;
            uint64_t                : 30;
        } GICT_ERR0MISC0_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR0MISC1;
        struct
        {
            __IOM uint64_t INFO : 9;
            uint64_t            : 55;
        } GICT_ERR0MISC1_b;
    };
    __IM uint8_t RESERVED19[16];
    union
    {
        __IOM uint64_t GICT_ERR1FR;
        struct
        {
            __IM uint64_t ED  : 2;
            __IM uint64_t DE  : 2;
            __IM uint64_t UI  : 2;
            __IM uint64_t FI  : 2;
            __IM uint64_t UE  : 2;
            __IM uint64_t CFI : 2;
            __IM uint64_t CEC : 3;
            __IM uint64_t RP  : 1;
            uint64_t          : 48;
        } GICT_ERR1FR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR1CTLR;
        struct
        {
            uint64_t           : 2;
            __IOM uint64_t UI  : 1;
            __IOM uint64_t FI  : 1;
            __IOM uint64_t UE  : 1;
            uint64_t           : 3;
            __IOM uint64_t CFI : 1;
            uint64_t           : 6;
            __IOM uint64_t RP  : 1;
            uint64_t           : 48;
        } GICT_ERR1CTLR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR1STATUS;
        struct
        {
            __IOM uint64_t SERR : 8;
            __IOM uint64_t IERR : 8;
            uint64_t            : 4;
            __IOM uint64_t UET  : 2;
            uint64_t            : 2;
            __IOM uint64_t CE   : 2;
            __IOM uint64_t MV   : 1;
            __IOM uint64_t OF   : 1;
            __IOM uint64_t ER   : 1;
            __IOM uint64_t UE   : 1;
            __IOM uint64_t V    : 1;
            __IOM uint64_t AV   : 1;
            uint64_t            : 32;
        } GICT_ERR1STATUS_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR1ADDR;
        struct
        {
            __IOM uint64_t PADDR : 48;
            uint64_t             : 15;
            __IOM uint64_t NS    : 1;
        } GICT_ERR1ADDR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR1MISC0;
        struct
        {
            __IOM uint64_t Data     : 32;
            __IOM uint64_t Overflow : 1;
            __IOM uint64_t RE       : 1;
            uint64_t                : 30;
        } GICT_ERR1MISC0_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR1MISC1;
        struct
        {
            __IOM uint64_t INFO : 9;
            uint64_t            : 55;
        } GICT_ERR1MISC1_b;
    };
    __IM uint8_t RESERVED20[16];
    union
    {
        __IOM uint64_t GICT_ERR2FR;
        struct
        {
            __IM uint64_t ED  : 2;
            __IM uint64_t DE  : 2;
            __IM uint64_t UI  : 2;
            __IM uint64_t FI  : 2;
            __IM uint64_t UE  : 2;
            __IM uint64_t CFI : 2;
            __IM uint64_t CEC : 3;
            __IM uint64_t RP  : 1;
            uint64_t          : 48;
        } GICT_ERR2FR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR2CTLR;
        struct
        {
            uint64_t           : 2;
            __IOM uint64_t UI  : 1;
            __IOM uint64_t FI  : 1;
            __IOM uint64_t UE  : 1;
            uint64_t           : 3;
            __IOM uint64_t CFI : 1;
            uint64_t           : 6;
            __IOM uint64_t RP  : 1;
            uint64_t           : 48;
        } GICT_ERR2CTLR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR2STATUS;
        struct
        {
            __IOM uint64_t SERR : 8;
            __IOM uint64_t IERR : 8;
            uint64_t            : 4;
            __IOM uint64_t UET  : 2;
            uint64_t            : 2;
            __IOM uint64_t CE   : 2;
            __IOM uint64_t MV   : 1;
            __IOM uint64_t OF   : 1;
            __IOM uint64_t ER   : 1;
            __IOM uint64_t UE   : 1;
            __IOM uint64_t V    : 1;
            __IOM uint64_t AV   : 1;
            uint64_t            : 32;
        } GICT_ERR2STATUS_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR2ADDR;
        struct
        {
            __IOM uint64_t PADDR : 48;
            uint64_t             : 15;
            __IOM uint64_t NS    : 1;
        } GICT_ERR2ADDR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR2MISC0;
        struct
        {
            __IOM uint64_t Data     : 32;
            __IOM uint64_t Overflow : 1;
            __IOM uint64_t RE       : 1;
            uint64_t                : 30;
        } GICT_ERR2MISC0_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR2MISC1;
        struct
        {
            __IOM uint64_t INFO : 9;
            uint64_t            : 55;
        } GICT_ERR2MISC1_b;
    };
    __IM uint8_t RESERVED21[16];
    union
    {
        __IOM uint64_t GICT_ERR3FR;
        struct
        {
            __IM uint64_t ED  : 2;
            __IM uint64_t DE  : 2;
            __IM uint64_t UI  : 2;
            __IM uint64_t FI  : 2;
            __IM uint64_t UE  : 2;
            __IM uint64_t CFI : 2;
            __IM uint64_t CEC : 3;
            __IM uint64_t RP  : 1;
            uint64_t          : 48;
        } GICT_ERR3FR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR3CTLR;
        struct
        {
            uint64_t           : 2;
            __IOM uint64_t UI  : 1;
            __IOM uint64_t FI  : 1;
            __IOM uint64_t UE  : 1;
            uint64_t           : 3;
            __IOM uint64_t CFI : 1;
            uint64_t           : 6;
            __IOM uint64_t RP  : 1;
            uint64_t           : 48;
        } GICT_ERR3CTLR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR3STATUS;
        struct
        {
            __IOM uint64_t SERR : 8;
            __IOM uint64_t IERR : 8;
            uint64_t            : 4;
            __IOM uint64_t UET  : 2;
            uint64_t            : 2;
            __IOM uint64_t CE   : 2;
            __IOM uint64_t MV   : 1;
            __IOM uint64_t OF   : 1;
            __IOM uint64_t ER   : 1;
            __IOM uint64_t UE   : 1;
            __IOM uint64_t V    : 1;
            __IOM uint64_t AV   : 1;
            uint64_t            : 32;
        } GICT_ERR3STATUS_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR3ADDR;
        struct
        {
            __IOM uint64_t PADDR : 48;
            uint64_t             : 15;
            __IOM uint64_t NS    : 1;
        } GICT_ERR3ADDR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR3MISC0;
        struct
        {
            __IOM uint64_t Data     : 32;
            __IOM uint64_t Overflow : 1;
            __IOM uint64_t RE       : 1;
            uint64_t                : 30;
        } GICT_ERR3MISC0_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR3MISC1;
        struct
        {
            __IOM uint64_t INFO : 9;
            uint64_t            : 55;
        } GICT_ERR3MISC1_b;
    };
    __IM uint8_t RESERVED22[16];
    union
    {
        __IOM uint64_t GICT_ERR4FR;
        struct
        {
            __IM uint64_t ED  : 2;
            __IM uint64_t DE  : 2;
            __IM uint64_t UI  : 2;
            __IM uint64_t FI  : 2;
            __IM uint64_t UE  : 2;
            __IM uint64_t CFI : 2;
            __IM uint64_t CEC : 3;
            __IM uint64_t RP  : 1;
            uint64_t          : 48;
        } GICT_ERR4FR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR4CTLR;
        struct
        {
            uint64_t           : 2;
            __IOM uint64_t UI  : 1;
            __IOM uint64_t FI  : 1;
            __IOM uint64_t UE  : 1;
            uint64_t           : 3;
            __IOM uint64_t CFI : 1;
            uint64_t           : 6;
            __IOM uint64_t RP  : 1;
            uint64_t           : 48;
        } GICT_ERR4CTLR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR4STATUS;
        struct
        {
            __IOM uint64_t SERR : 8;
            __IOM uint64_t IERR : 8;
            uint64_t            : 4;
            __IOM uint64_t UET  : 2;
            uint64_t            : 2;
            __IOM uint64_t CE   : 2;
            __IOM uint64_t MV   : 1;
            __IOM uint64_t OF   : 1;
            __IOM uint64_t ER   : 1;
            __IOM uint64_t UE   : 1;
            __IOM uint64_t V    : 1;
            __IOM uint64_t AV   : 1;
            uint64_t            : 32;
        } GICT_ERR4STATUS_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR4ADDR;
        struct
        {
            __IOM uint64_t PADDR : 48;
            uint64_t             : 15;
            __IOM uint64_t NS    : 1;
        } GICT_ERR4ADDR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR4MISC0;
        struct
        {
            __IOM uint64_t Data     : 32;
            __IOM uint64_t Overflow : 1;
            __IOM uint64_t RE       : 1;
            uint64_t                : 30;
        } GICT_ERR4MISC0_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR4MISC1;
        struct
        {
            __IOM uint64_t INFO : 9;
            uint64_t            : 55;
        } GICT_ERR4MISC1_b;
    };
    __IM uint8_t RESERVED23[144];
    union
    {
        __IOM uint64_t GICT_ERR7FR;
        struct
        {
            __IM uint64_t ED  : 2;
            __IM uint64_t DE  : 2;
            __IM uint64_t UI  : 2;
            __IM uint64_t FI  : 2;
            __IM uint64_t UE  : 2;
            __IM uint64_t CFI : 2;
            __IM uint64_t CEC : 3;
            __IM uint64_t RP  : 1;
            uint64_t          : 48;
        } GICT_ERR7FR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR7CTLR;
        struct
        {
            uint64_t           : 2;
            __IOM uint64_t UI  : 1;
            __IOM uint64_t FI  : 1;
            __IOM uint64_t UE  : 1;
            uint64_t           : 3;
            __IOM uint64_t CFI : 1;
            uint64_t           : 6;
            __IOM uint64_t RP  : 1;
            uint64_t           : 48;
        } GICT_ERR7CTLR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR7STATUS;
        struct
        {
            __IOM uint64_t SERR : 8;
            __IOM uint64_t IERR : 8;
            uint64_t            : 4;
            __IOM uint64_t UET  : 2;
            uint64_t            : 2;
            __IOM uint64_t CE   : 2;
            __IOM uint64_t MV   : 1;
            __IOM uint64_t OF   : 1;
            __IOM uint64_t ER   : 1;
            __IOM uint64_t UE   : 1;
            __IOM uint64_t V    : 1;
            __IOM uint64_t AV   : 1;
            uint64_t            : 32;
        } GICT_ERR7STATUS_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR7ADDR;
        struct
        {
            __IOM uint64_t PADDR : 48;
            uint64_t             : 15;
            __IOM uint64_t NS    : 1;
        } GICT_ERR7ADDR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR7MISC0;
        struct
        {
            __IOM uint64_t Data     : 32;
            __IOM uint64_t Overflow : 1;
            __IOM uint64_t RE       : 1;
            uint64_t                : 30;
        } GICT_ERR7MISC0_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR7MISC1;
        struct
        {
            __IOM uint64_t INFO : 9;
            uint64_t            : 55;
        } GICT_ERR7MISC1_b;
    };
    __IM uint8_t RESERVED24[16];
    union
    {
        __IOM uint64_t GICT_ERR8FR;
        struct
        {
            __IM uint64_t ED  : 2;
            __IM uint64_t DE  : 2;
            __IM uint64_t UI  : 2;
            __IM uint64_t FI  : 2;
            __IM uint64_t UE  : 2;
            __IM uint64_t CFI : 2;
            __IM uint64_t CEC : 3;
            __IM uint64_t RP  : 1;
            uint64_t          : 48;
        } GICT_ERR8FR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR8CTLR;
        struct
        {
            uint64_t           : 2;
            __IOM uint64_t UI  : 1;
            __IOM uint64_t FI  : 1;
            __IOM uint64_t UE  : 1;
            uint64_t           : 3;
            __IOM uint64_t CFI : 1;
            uint64_t           : 6;
            __IOM uint64_t RP  : 1;
            uint64_t           : 48;
        } GICT_ERR8CTLR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR8STATUS;
        struct
        {
            __IOM uint64_t SERR : 8;
            __IOM uint64_t IERR : 8;
            uint64_t            : 4;
            __IOM uint64_t UET  : 2;
            uint64_t            : 2;
            __IOM uint64_t CE   : 2;
            __IOM uint64_t MV   : 1;
            __IOM uint64_t OF   : 1;
            __IOM uint64_t ER   : 1;
            __IOM uint64_t UE   : 1;
            __IOM uint64_t V    : 1;
            __IOM uint64_t AV   : 1;
            uint64_t            : 32;
        } GICT_ERR8STATUS_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR8ADDR;
        struct
        {
            __IOM uint64_t PADDR : 48;
            uint64_t             : 15;
            __IOM uint64_t NS    : 1;
        } GICT_ERR8ADDR_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR8MISC0;
        struct
        {
            __IOM uint64_t Data     : 32;
            __IOM uint64_t Overflow : 1;
            __IOM uint64_t RE       : 1;
            uint64_t                : 30;
        } GICT_ERR8MISC0_b;
    };
    union
    {
        __IOM uint64_t GICT_ERR8MISC1;
        struct
        {
            __IOM uint64_t INFO : 9;
            uint64_t            : 55;
        } GICT_ERR8MISC1_b;
    };
    __IM uint8_t RESERVED25[56784];
    union
    {
        __IM uint64_t GICT_ERRGSR;
        struct
        {
            __IM uint64_t Status : 64;
        } GICT_ERRGSR_b;
    };
    __IM uint8_t RESERVED26[2040];
    union
    {
        __IOM uint64_t GICT_ERRIRQCR0;
        struct
        {
            __IOM uint64_t SPID : 10;
            uint64_t            : 54;
        } GICT_ERRIRQCR0_b;
    };
    union
    {
        __IOM uint64_t GICT_ERRIRQCR1;
        struct
        {
            __IOM uint64_t SPID : 10;
            uint64_t            : 54;
        } GICT_ERRIRQCR1_b;
    };
    __IM uint8_t  RESERVED27[6060];
    __IM uint32_t GICT_DEVARCH;
    __IM uint8_t  RESERVED28[8];
    union
    {
        __IM uint32_t GICT_ERRIDR;
        struct
        {
            __IM uint32_t NUM : 16;
            uint32_t          : 16;
        } GICT_ERRIDR_b;
    };
    __IM uint8_t RESERVED29[4];
    union
    {
        __IM uint32_t GICT_PIDR4;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICT_PIDR4_b;
    };
    union
    {
        __IM uint32_t GICT_PIDR5;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 3;
            uint32_t            : 25;
        } GICT_PIDR5_b;
    };
    union
    {
        __IM uint32_t GICT_PIDR6;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICT_PIDR6_b;
    };
    union
    {
        __IM uint32_t GICT_PIDR7;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICT_PIDR7_b;
    };
    union
    {
        __IM uint32_t GICT_PIDR0;
        struct
        {
            __IM uint32_t PART_0 : 8;
            uint32_t             : 24;
        } GICT_PIDR0_b;
    };
    union
    {
        __IM uint32_t GICT_PIDR1;
        struct
        {
            __IM uint32_t PART_1 : 4;
            __IM uint32_t DES_0  : 4;
            uint32_t             : 24;
        } GICT_PIDR1_b;
    };
    union
    {
        __IM uint32_t GICT_PIDR2;
        struct
        {
            __IM uint32_t DES_1   : 3;
            __IM uint32_t JEDEC   : 1;
            __IM uint32_t ArchRev : 4;
            uint32_t              : 24;
        } GICT_PIDR2_b;
    };
    union
    {
        __IM uint32_t GICT_PIDR3;
        struct
        {
            __IM uint32_t CMOD   : 4;
            __IM uint32_t REVAND : 4;
            uint32_t             : 24;
        } GICT_PIDR3_b;
    };
    __IM uint32_t GICT_CIDR0;
    __IM uint32_t GICT_CIDR1;
    __IM uint32_t GICT_CIDR2;
    __IM uint32_t GICT_CIDR3;
    union
    {
        __IOM uint32_t GICP_EVCNTR0;
        struct
        {
            __IOM uint32_t COUNT : 32;
        } GICP_EVCNTR0_b;
    };
    union
    {
        __IOM uint32_t GICP_EVCNTR1;
        struct
        {
            __IOM uint32_t COUNT : 32;
        } GICP_EVCNTR1_b;
    };
    union
    {
        __IOM uint32_t GICP_EVCNTR2;
        struct
        {
            __IOM uint32_t COUNT : 32;
        } GICP_EVCNTR2_b;
    };
    union
    {
        __IOM uint32_t GICP_EVCNTR3;
        struct
        {
            __IOM uint32_t COUNT : 32;
        } GICP_EVCNTR3_b;
    };
    union
    {
        __IOM uint32_t GICP_EVCNTR4;
        struct
        {
            __IOM uint32_t COUNT : 32;
        } GICP_EVCNTR4_b;
    };
    __IM uint8_t RESERVED30[1004];
    union
    {
        __IOM uint32_t GICP_EVTYPER0;
        struct
        {
            __IOM uint32_t EVENT      : 8;
            uint32_t                  : 8;
            __IOM uint32_t EVENT_TYPE : 2;
            uint32_t                  : 13;
            __IOM uint32_t OVFCAP     : 1;
        } GICP_EVTYPER0_b;
    };
    union
    {
        __IOM uint32_t GICP_EVTYPER1;
        struct
        {
            __IOM uint32_t EVENT      : 8;
            uint32_t                  : 8;
            __IOM uint32_t EVENT_TYPE : 2;
            uint32_t                  : 13;
            __IOM uint32_t OVFCAP     : 1;
        } GICP_EVTYPER1_b;
    };
    union
    {
        __IOM uint32_t GICP_EVTYPER2;
        struct
        {
            __IOM uint32_t EVENT      : 8;
            uint32_t                  : 8;
            __IOM uint32_t EVENT_TYPE : 2;
            uint32_t                  : 13;
            __IOM uint32_t OVFCAP     : 1;
        } GICP_EVTYPER2_b;
    };
    union
    {
        __IOM uint32_t GICP_EVTYPER3;
        struct
        {
            __IOM uint32_t EVENT      : 8;
            uint32_t                  : 8;
            __IOM uint32_t EVENT_TYPE : 2;
            uint32_t                  : 13;
            __IOM uint32_t OVFCAP     : 1;
        } GICP_EVTYPER3_b;
    };
    union
    {
        __IOM uint32_t GICP_EVTYPER4;
        struct
        {
            __IOM uint32_t EVENT      : 8;
            uint32_t                  : 8;
            __IOM uint32_t EVENT_TYPE : 2;
            uint32_t                  : 13;
            __IOM uint32_t OVFCAP     : 1;
        } GICP_EVTYPER4_b;
    };
    __IM uint8_t RESERVED31[492];
    union
    {
        __IOM uint32_t GICP_SVR0;
        struct
        {
            __IOM uint32_t COUNT : 32;
        } GICP_SVR0_b;
    };
    union
    {
        __IOM uint32_t GICP_SVR1;
        struct
        {
            __IOM uint32_t COUNT : 32;
        } GICP_SVR1_b;
    };
    union
    {
        __IOM uint32_t GICP_SVR2;
        struct
        {
            __IOM uint32_t COUNT : 32;
        } GICP_SVR2_b;
    };
    union
    {
        __IOM uint32_t GICP_SVR3;
        struct
        {
            __IOM uint32_t COUNT : 32;
        } GICP_SVR3_b;
    };
    union
    {
        __IOM uint32_t GICP_SVR4;
        struct
        {
            __IOM uint32_t COUNT : 32;
        } GICP_SVR4_b;
    };
    __IM uint8_t RESERVED32[1004];
    union
    {
        __IOM uint32_t GICP_FR0;
        struct
        {
            __IOM uint32_t Filter         : 16;
            uint32_t                      : 13;
            __IOM uint32_t FilterEncoding : 1;
            __IOM uint32_t Filter_Type    : 2;
        } GICP_FR0_b;
    };
    union
    {
        __IOM uint32_t GICP_FR1;
        struct
        {
            __IOM uint32_t Filter         : 16;
            uint32_t                      : 13;
            __IOM uint32_t FilterEncoding : 1;
            __IOM uint32_t Filter_Type    : 2;
        } GICP_FR1_b;
    };
    union
    {
        __IOM uint32_t GICP_FR2;
        struct
        {
            __IOM uint32_t Filter         : 16;
            uint32_t                      : 13;
            __IOM uint32_t FilterEncoding : 1;
            __IOM uint32_t Filter_Type    : 2;
        } GICP_FR2_b;
    };
    union
    {
        __IOM uint32_t GICP_FR3;
        struct
        {
            __IOM uint32_t Filter         : 16;
            uint32_t                      : 13;
            __IOM uint32_t FilterEncoding : 1;
            __IOM uint32_t Filter_Type    : 2;
        } GICP_FR3_b;
    };
    union
    {
        __IOM uint32_t GICP_FR4;
        struct
        {
            __IOM uint32_t Filter         : 16;
            uint32_t                      : 13;
            __IOM uint32_t FilterEncoding : 1;
            __IOM uint32_t Filter_Type    : 2;
        } GICP_FR4_b;
    };
    __IM uint8_t RESERVED33[492];
    union
    {
        __IOM uint64_t GICP_CNTENSET0;
        struct
        {
            __IOM uint64_t CNTEN : 5;
            uint64_t             : 59;
        } GICP_CNTENSET0_b;
    };
    __IM uint8_t RESERVED34[24];
    union
    {
        __IOM uint64_t GICP_CNTENCLR0;
        struct
        {
            __IOM uint64_t CNTEN : 5;
            uint64_t             : 59;
        } GICP_CNTENCLR0_b;
    };
    __IM uint8_t RESERVED35[24];
    union
    {
        __IOM uint64_t GICP_INTENSET0;
        struct
        {
            __IOM uint64_t INTEN : 5;
            uint64_t             : 59;
        } GICP_INTENSET0_b;
    };
    __IM uint8_t RESERVED36[24];
    union
    {
        __IOM uint64_t GICP_INTENCLR0;
        struct
        {
            __IOM uint64_t INTEN : 5;
            uint64_t             : 59;
        } GICP_INTENCLR0_b;
    };
    __IM uint8_t RESERVED37[24];
    union
    {
        __IOM uint64_t GICP_OVSCLR0;
        struct
        {
            __IOM uint64_t OVS : 5;
            uint64_t           : 59;
        } GICP_OVSCLR0_b;
    };
    __IM uint8_t RESERVED38[56];
    union
    {
        __IOM uint64_t GICP_OVSSET0;
        struct
        {
            __IOM uint64_t OVS : 5;
            uint64_t           : 59;
        } GICP_OVSSET0_b;
    };
    __IM uint8_t RESERVED39[192];
    union
    {
        __IOM uint32_t GICP_CAPR;
        struct
        {
            __IOM uint32_t CAPTURE : 1;
            uint32_t               : 31;
        } GICP_CAPR_b;
    };
    __IM uint8_t RESERVED40[116];
    union
    {
        __IM uint32_t GICP_CFGR;
        struct
        {
            __IM uint32_t NCTR    : 6;
            uint32_t              : 2;
            __IM uint32_t SIZE    : 6;
            uint32_t              : 8;
            __IM uint32_t CAPTURE : 1;
            uint32_t              : 9;
        } GICP_CFGR_b;
    };
    union
    {
        __IOM uint32_t GICP_CR;
        struct
        {
            __IOM uint32_t E : 1;
            uint32_t         : 31;
        } GICP_CR_b;
    };
    __IM uint8_t RESERVED41[72];
    union
    {
        __IOM uint32_t GICP_IRQCR;
        struct
        {
            __IOM uint32_t SPID : 10;
            uint32_t            : 22;
        } GICP_IRQCR_b;
    };
    __IM uint8_t  RESERVED42[356];
    __IM uint32_t GICP_PMAUTHSTATUS;
    __IM uint32_t GICP_PMDEVARCH;
    __IM uint8_t  RESERVED43[12];
    __IM uint32_t GICP_PMDEVTYPE;
    union
    {
        __IM uint32_t GICP_PIDR4;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICP_PIDR4_b;
    };
    union
    {
        __IM uint32_t GICP_PIDR5;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 3;
            uint32_t            : 25;
        } GICP_PIDR5_b;
    };
    union
    {
        __IM uint32_t GICP_PIDR6;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICP_PIDR6_b;
    };
    union
    {
        __IM uint32_t GICP_PIDR7;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICP_PIDR7_b;
    };
    union
    {
        __IM uint32_t GICP_PIDR0;
        struct
        {
            __IM uint32_t PART_0 : 8;
            uint32_t             : 24;
        } GICP_PIDR0_b;
    };
    union
    {
        __IM uint32_t GICP_PIDR1;
        struct
        {
            __IM uint32_t PART_1 : 4;
            __IM uint32_t DES_0  : 4;
            uint32_t             : 24;
        } GICP_PIDR1_b;
    };
    union
    {
        __IM uint32_t GICP_PIDR2;
        struct
        {
            __IM uint32_t DES_1   : 3;
            __IM uint32_t JEDEC   : 1;
            __IM uint32_t ArchRev : 4;
            uint32_t              : 24;
        } GICP_PIDR2_b;
    };
    __IM uint8_t  RESERVED44[4];
    __IM uint32_t GICP_CIDR0;
    __IM uint32_t GICP_CIDR1;
    __IM uint32_t GICP_CIDR2;
    union
    {
        union
        {
            __IM uint32_t GICP_PIDR3;
            struct
            {
                __IM uint32_t CMOD   : 4;
                __IM uint32_t REVAND : 4;
                uint32_t             : 24;
            } GICP_PIDR3_b;
        };
        __IM uint32_t GICP_CIDR3;
    };
    __IM uint8_t RESERVED45[61440];
    union
    {
        __IOM uint32_t GICR_CTLR;
        struct
        {
            __IOM uint32_t EnableLPIs : 1;
            __IOM uint32_t CES        : 1;
            __IOM uint32_t IR         : 1;
            __IOM uint32_t RWP        : 1;
            uint32_t                  : 20;
            __IOM uint32_t DPG0       : 1;
            __IOM uint32_t DPG1NS     : 1;
            __IOM uint32_t DPG1S      : 1;
            uint32_t                  : 4;
            __IOM uint32_t UWP        : 1;
        } GICR_CTLR_b;
    };
    union
    {
        __IOM uint32_t GICR_IIDR;
        struct
        {
            __IOM uint32_t Implementer : 12;
            __IOM uint32_t Revision    : 4;
            __IOM uint32_t Variant     : 4;
            uint32_t                   : 4;
            __IOM uint32_t ProductID   : 8;
        } GICR_IIDR_b;
    };
    union
    {
        __IOM uint64_t GICR_TYPER;
        struct
        {
            __IOM uint64_t PLPIS           : 1;
            __IOM uint64_t VLPIS           : 1;
            uint64_t                       : 1;
            __IOM uint64_t DirectLPI       : 1;
            __IOM uint64_t Last            : 1;
            __IOM uint64_t DPGA            : 1;
            uint64_t                       : 2;
            __IOM uint64_t ProcessorNumber : 16;
            __IOM uint64_t CommonLPIAff    : 2;
            uint64_t                       : 6;
            __IOM uint64_t AffinityValue   : 32;
        } GICR_TYPER_b;
    };
    __IM uint8_t RESERVED46[4];
    union
    {
        __IOM uint32_t GICR_WAKER;
        struct
        {
            __IOM uint32_t Sleep          : 1;
            __IOM uint32_t ProcessorSleep : 1;
            __IOM uint32_t ChildrenAsleep : 1;
            uint32_t                      : 28;
            __IOM uint32_t Quiescent      : 1;
        } GICR_WAKER_b;
    };
    __IM uint8_t RESERVED47[8];
    union
    {
        __IOM uint32_t GICR_FCTLR;
        struct
        {
            __IOM uint32_t SIP : 1;
            uint32_t           : 3;
            __IOM uint32_t CGO : 3;
            uint32_t           : 24;
            __IOM uint32_t QD  : 1;
        } GICR_FCTLR_b;
    };
    union
    {
        __IOM uint32_t GICR_PWRR;
        struct
        {
            __IOM uint32_t RDPG : 1;
            __IOM uint32_t RDAG : 1;
            __IOM uint32_t RGPD : 1;
            __IM uint32_t  RGPO : 1;
            uint32_t            : 4;
            __IM uint32_t RDGO  : 8;
            __IM uint32_t RDG   : 8;
            uint32_t            : 8;
        } GICR_PWRR_b;
    };
    union
    {
        __IOM uint32_t GICR_CLASS;
        struct
        {
            __IOM uint32_t Class : 1;
            uint32_t             : 31;
        } GICR_CLASS_b;
    };
    __IM uint8_t RESERVED48[68];
    union
    {
        __IOM uint64_t GICR_PROPBASER;
        struct
        {
            __IOM uint64_t Idbits           : 5;
            uint64_t                        : 2;
            __IOM uint64_t InnerCache       : 3;
            __IOM uint64_t Shareability     : 2;
            __IOM uint64_t Physical_Address : 40;
            uint64_t                        : 4;
            __IOM uint64_t OuterCache       : 3;
            uint64_t                        : 5;
        } GICR_PROPBASER_b;
    };
    union
    {
        __IOM uint64_t GICR_PENDBASER;
        struct
        {
            uint64_t                        : 7;
            __IOM uint64_t InnerCache       : 3;
            __IOM uint64_t Shareability     : 2;
            uint64_t                        : 4;
            __IOM uint64_t Physical_Address : 36;
            uint64_t                        : 4;
            __IOM uint64_t OuterCache       : 3;
            uint64_t                        : 3;
            __IOM uint64_t PTZ              : 1;
            uint64_t                        : 1;
        } GICR_PENDBASER_b;
    };
    __IM uint8_t RESERVED49[65360];
    union
    {
        __IM uint32_t GICR_PIDR4;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICR_PIDR4_b;
    };
    union
    {
        __IM uint32_t GICR_PIDR5;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 3;
            uint32_t            : 25;
        } GICR_PIDR5_b;
    };
    union
    {
        __IM uint32_t GICR_PIDR6;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICR_PIDR6_b;
    };
    union
    {
        __IM uint32_t GICR_PIDR7;
        struct
        {
            __IM uint32_t DES_2 : 4;
            __IM uint32_t SIZE  : 4;
            uint32_t            : 24;
        } GICR_PIDR7_b;
    };
    union
    {
        __IM uint32_t GICR_PIDR0;
        struct
        {
            __IM uint32_t PART_0 : 8;
            uint32_t             : 24;
        } GICR_PIDR0_b;
    };
    union
    {
        __IM uint32_t GICR_PIDR1;
        struct
        {
            __IM uint32_t PART_1 : 4;
            __IM uint32_t DES_0  : 4;
            uint32_t             : 24;
        } GICR_PIDR1_b;
    };
    union
    {
        __IM uint32_t GICR_PIDR2;
        struct
        {
            __IM uint32_t DES_1   : 3;
            __IM uint32_t JEDEC   : 1;
            __IM uint32_t ArchRev : 4;
            uint32_t              : 24;
        } GICR_PIDR2_b;
    };
    union
    {
        __IM uint32_t GICR_PIDR3;
        struct
        {
            __IM uint32_t CMOD   : 4;
            __IM uint32_t REVAND : 4;
            uint32_t             : 24;
        } GICR_PIDR3_b;
    };
    __IM uint32_t GICR_CIDR0;
    __IM uint32_t GICR_CIDR1;
    __IM uint32_t GICR_CIDR2;
    __IM uint32_t GICR_CIDR3;
    __IM uint8_t  RESERVED50[128];
    union
    {
        __IOM uint32_t GICR_IGROUPR0;
        struct
        {
            __IOM uint32_t Redistributor_group_status_bit : 32;
        } GICR_IGROUPR0_b;
    };
    __IM uint8_t RESERVED51[124];
    union
    {
        __IOM uint32_t GICR_ISENABLER0;
        struct
        {
            __IOM uint32_t Set_enable_bit : 32;
        } GICR_ISENABLER0_b;
    };
    __IM uint8_t RESERVED52[124];
    union
    {
        __IOM uint32_t GICR_ICENABLER0;
        struct
        {
            __IOM uint32_t Clear_enable_bit : 32;
        } GICR_ICENABLER0_b;
    };
    __IM uint8_t RESERVED53[124];
    union
    {
        __IOM uint32_t GICR_ISPENDR0;
        struct
        {
            __IOM uint32_t Set_pending_bit : 32;
        } GICR_ISPENDR0_b;
    };
    __IM uint8_t RESERVED54[124];
    union
    {
        __IOM uint32_t GICR_ICPENDR0;
        struct
        {
            __IOM uint32_t Clear_pending_bit : 32;
        } GICR_ICPENDR0_b;
    };
    __IM uint8_t RESERVED55[124];
    union
    {
        __IOM uint32_t GICR_ISACTIVER0;
        struct
        {
            __IOM uint32_t Set_active_bit : 32;
        } GICR_ISACTIVER0_b;
    };
    __IM uint8_t RESERVED56[124];
    union
    {
        __IOM uint32_t GICR_ICACTIVER0;
        struct
        {
            __IOM uint32_t Clear_active_bit : 32;
        } GICR_ICACTIVER0_b;
    };
    __IM uint8_t RESERVED57[124];
    union
    {
        __IOM uint32_t GICR_IPRIORITYR0;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICR_IPRIORITYR0_b;
    };
    union
    {
        __IOM uint32_t GICR_IPRIORITYR1;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICR_IPRIORITYR1_b;
    };
    union
    {
        __IOM uint32_t GICR_IPRIORITYR2;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICR_IPRIORITYR2_b;
    };
    union
    {
        __IOM uint32_t GICR_IPRIORITYR3;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICR_IPRIORITYR3_b;
    };
    union
    {
        __IOM uint32_t GICR_IPRIORITYR4;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICR_IPRIORITYR4_b;
    };
    union
    {
        __IOM uint32_t GICR_IPRIORITYR5;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICR_IPRIORITYR5_b;
    };
    union
    {
        __IOM uint32_t GICR_IPRIORITYR6;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICR_IPRIORITYR6_b;
    };
    union
    {
        __IOM uint32_t GICR_IPRIORITYR7;
        struct
        {
            __IOM uint32_t Priority_offset0B : 8;
            __IOM uint32_t Priority_offset1B : 8;
            __IOM uint32_t Priority_offset2B : 8;
            __IOM uint32_t Priority_offset3B : 8;
        } GICR_IPRIORITYR7_b;
    };
    __IM uint8_t RESERVED58[2016];
    union
    {
        __IOM uint32_t GICR_ICFGR0;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICR_ICFGR0_b;
    };
    union
    {
        __IOM uint32_t GICR_ICFGR1;
        struct
        {
            __IOM uint32_t Int_config0  : 2;
            __IOM uint32_t Int_config1  : 2;
            __IOM uint32_t Int_config2  : 2;
            __IOM uint32_t Int_config3  : 2;
            __IOM uint32_t Int_config4  : 2;
            __IOM uint32_t Int_config5  : 2;
            __IOM uint32_t Int_config6  : 2;
            __IOM uint32_t Int_config7  : 2;
            __IOM uint32_t Int_config8  : 2;
            __IOM uint32_t Int_config9  : 2;
            __IOM uint32_t Int_config10 : 2;
            __IOM uint32_t Int_config11 : 2;
            __IOM uint32_t Int_config12 : 2;
            __IOM uint32_t Int_config13 : 2;
            __IOM uint32_t Int_config14 : 2;
            __IOM uint32_t Int_config15 : 2;
        } GICR_ICFGR1_b;
    };
    __IM uint8_t RESERVED59[248];
    union
    {
        __IOM uint32_t GICR_IGRPMODR0;
        struct
        {
            __IOM uint32_t Group_modifier_bit : 32;
        } GICR_IGRPMODR0_b;
    };
    __IM uint8_t RESERVED60[252];
    union
    {
        __IOM uint32_t GICR_NSACR;
        struct
        {
            __IOM uint32_t NS_access0  : 2;
            __IOM uint32_t NS_access1  : 2;
            __IOM uint32_t NS_access2  : 2;
            __IOM uint32_t NS_access3  : 2;
            __IOM uint32_t NS_access4  : 2;
            __IOM uint32_t NS_access5  : 2;
            __IOM uint32_t NS_access6  : 2;
            __IOM uint32_t NS_access7  : 2;
            __IOM uint32_t NS_access8  : 2;
            __IOM uint32_t NS_access9  : 2;
            __IOM uint32_t NS_access10 : 2;
            __IOM uint32_t NS_access11 : 2;
            __IOM uint32_t NS_access12 : 2;
            __IOM uint32_t NS_access13 : 2;
            __IOM uint32_t NS_access14 : 2;
            __IOM uint32_t NS_access15 : 2;
        } GICR_NSACR_b;
    };
    __IM uint8_t RESERVED61[45564];
    union
    {
        __IOM uint32_t GICR_MISCSTATUSR;
        struct
        {
            __IOM uint32_t EnableGrp0        : 1;
            __IOM uint32_t EnableGrp1NSecure : 1;
            __IOM uint32_t EnableGrp1Secure  : 1;
            uint32_t                         : 1;
            __IOM uint32_t AccessType        : 1;
            uint32_t                         : 25;
            __IOM uint32_t wake_request      : 1;
            __IOM uint32_t cpu_active        : 1;
        } GICR_MISCSTATUSR_b;
    };
    __IM uint8_t RESERVED62[4];
    union
    {
        __IOM uint32_t GICR_IERRVR;
        struct
        {
            __IOM uint32_t valid : 32;
        } GICR_IERRVR_b;
    };
    __IM uint8_t RESERVED63[4];
    union
    {
        __IOM uint64_t GICR_SGIDR;
        struct
        {
            __IOM uint64_t NSACR0   : 1;
            __IOM uint64_t GRP0     : 1;
            __IOM uint64_t GRPMOD0  : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR1   : 1;
            __IOM uint64_t GRP1     : 1;
            __IOM uint64_t GRPMOD1  : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR2   : 1;
            __IOM uint64_t GRP2     : 1;
            __IOM uint64_t GRPMOD2  : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR3   : 1;
            __IOM uint64_t GRP3     : 1;
            __IOM uint64_t GRPMOD3  : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR4   : 1;
            __IOM uint64_t GRP4     : 1;
            __IOM uint64_t GRPMOD4  : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR5   : 1;
            __IOM uint64_t GRP5     : 1;
            __IOM uint64_t GRPMOD5  : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR6   : 1;
            __IOM uint64_t GRP6     : 1;
            __IOM uint64_t GRPMOD6  : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR7   : 1;
            __IOM uint64_t GRP7     : 1;
            __IOM uint64_t GRPMOD7  : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR8   : 1;
            __IOM uint64_t GRP8     : 1;
            __IOM uint64_t GRPMOD8  : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR9   : 1;
            __IOM uint64_t GRP9     : 1;
            __IOM uint64_t GRPMOD9  : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR10  : 1;
            __IOM uint64_t GRP10    : 1;
            __IOM uint64_t GRPMOD10 : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR11  : 1;
            __IOM uint64_t GRP11    : 1;
            __IOM uint64_t GRPMOD11 : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR12  : 1;
            __IOM uint64_t GRP12    : 1;
            __IOM uint64_t GRPMOD12 : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR13  : 1;
            __IOM uint64_t GRP13    : 1;
            __IOM uint64_t GRPMOD13 : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR14  : 1;
            __IOM uint64_t GRP14    : 1;
            __IOM uint64_t GRPMOD14 : 1;
            uint64_t                : 1;
            __IOM uint64_t NSACR15  : 1;
            __IOM uint64_t GRP15    : 1;
            __IOM uint64_t GRPMOD15 : 1;
            uint64_t                : 1;
        } GICR_SGIDR_b;
    };
    __IM uint8_t RESERVED64[12264];
    union
    {
        __IOM uint32_t GICR_CFGID0;
        struct
        {
            __IOM uint32_t PPINumber     : 9;
            uint32_t                     : 2;
            __IOM uint32_t ECCSupport    : 1;
            __IOM uint32_t TGT0ListWidth : 4;
            __IOM uint32_t Af0Width      : 4;
            __IOM uint32_t Af1Width      : 4;
            __IOM uint32_t Af2Width      : 4;
            __IOM uint32_t Af3Width      : 4;
        } GICR_CFGID0_b;
    };
    union
    {
        __IOM uint32_t GICR_CFGID1;
        struct
        {
            uint32_t                         : 4;
            __IOM uint32_t NumCPUs           : 8;
            __IOM uint32_t DirectUpstream    : 1;
            uint32_t                         : 3;
            __IOM uint32_t PPIs_perProcessor : 4;
            uint32_t                         : 4;
            __IOM uint32_t UserValue         : 4;
            __IOM uint32_t Version           : 4;
        } GICR_CFGID1_b;
    };
} R_INTC_GIC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_INTC_GIC_BASE    0x11900000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_INTC_GIC    ((R_INTC_GIC_Type *) R_INTC_GIC_BASE)

#endif
