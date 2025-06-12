/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : intc_gic_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for intc_gic.
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
        __IOM uint32_t GICC_ICCICR;
        struct
        {
            __IOM uint32_t EN : 1;
            uint32_t          : 31;
        } GICC_ICCICR_b;
    };
    union
    {
        __IOM uint32_t GICC_ICCPMR;
        struct
        {
            __IOM uint32_t P : 8;
            uint32_t         : 24;
        } GICC_ICCPMR_b;
    };
    union
    {
        __IOM uint32_t GICC_ICCBPR;
        struct
        {
            __IOM uint32_t BP : 3;
            uint32_t          : 29;
        } GICC_ICCBPR_b;
    };
    union
    {
        __IM uint32_t GICC_ICCIAR;
        struct
        {
            __IM uint32_t ACKINTID : 10;
            __IM uint32_t CPUID    : 3;
            uint32_t               : 19;
        } GICC_ICCIAR_b;
    };
    union
    {
        __IOM uint32_t GICC_ICCEOIR;
        struct
        {
            __OM uint32_t EOIINTID : 10;
            __OM uint32_t CPUID    : 3;
            uint32_t               : 19;
        } GICC_ICCEOIR_b;
    };
    union
    {
        __IM uint32_t GICC_ICCRPR;
        struct
        {
            __IM uint32_t P : 8;
            uint32_t        : 24;
        } GICC_ICCRPR_b;
    };
    union
    {
        __IM uint32_t GICC_ICCHPIR;
        struct
        {
            __IM uint32_t PENDINTID : 10;
            __IM uint32_t CPUID     : 3;
            uint32_t                : 19;
        } GICC_ICCHPIR_b;
    };
    __IM uint8_t RESERVED[224];
    union
    {
        __IM uint32_t GICC_ICCIIDR;
        struct
        {
            __IM uint32_t I  : 12;
            __IM uint32_t RN : 4;
            __IM uint32_t AV : 4;
            __IM uint32_t P  : 12;
        } GICC_ICCIIDR_b;
    };
    __IM uint8_t RESERVED1[3584];
    union
    {
        __IOM uint32_t GICD_ICDDCR;
        struct
        {
            __IOM uint32_t EN : 1;
            uint32_t          : 31;
        } GICD_ICDDCR_b;
    };
    union
    {
        __IM uint32_t GICD_ICDICTR;
        struct
        {
            __IM uint32_t IT : 5;
            __IM uint32_t CN : 3;
            uint32_t         : 24;
        } GICD_ICDICTR_b;
    };
    union
    {
        __IM uint32_t GICD_ICDIIDR;
        struct
        {
            __IM uint32_t IN : 12;
            __IM uint32_t RN : 12;
            __IM uint32_t IV : 8;
        } GICD_ICDIIDR_b;
    };
    __IM uint8_t RESERVED2[244];
    union
    {
        __IOM uint32_t GICD_ICDISERn;
        struct
        {
            __IOM uint32_t SEB : 32;
        } GICD_ICDISERn_b;
    };
    __IM uint8_t RESERVED3[124];
    union
    {
        __IOM uint32_t GICD_ICDICERn;
        struct
        {
            __IOM uint32_t CEB : 32;
        } GICD_ICDICERn_b;
    };
    __IM uint8_t RESERVED4[124];
    union
    {
        __IOM uint32_t GICD_ICDISPRn;
        struct
        {
            __IOM uint32_t CPB : 32;
        } GICD_ICDISPRn_b;
    };
    __IM uint8_t RESERVED5[124];
    union
    {
        __IOM uint32_t GICD_ICDICPRn;
        struct
        {
            __IOM uint32_t CPB : 32;
        } GICD_ICDICPRn_b;
    };
    __IM uint8_t RESERVED6[124];
    union
    {
        __IM uint32_t GICD_ICDABRn;
        struct
        {
            __IM uint32_t AB : 32;
        } GICD_ICDABRn_b;
    };
    __IM uint8_t RESERVED7[252];
    union
    {
        __IOM uint32_t GICD_ICDIPRn;
        struct
        {
            __IOM uint32_t PBO0 : 8;
            __IOM uint32_t PBO1 : 8;
            __IOM uint32_t PBO2 : 8;
            __IOM uint32_t PBO3 : 8;
        } GICD_ICDIPRn_b;
    };
    __IM uint8_t RESERVED8[1020];
    union
    {
        __IOM uint32_t GICD_ICDIPTRn;
        struct
        {
            __IOM uint32_t CPU_TBO0 : 8;
            __IOM uint32_t CPU_TBO1 : 8;
            __IOM uint32_t CPU_TBO2 : 8;
            __IOM uint32_t CPU_TBO3 : 8;
        } GICD_ICDIPTRn_b;
    };
    __IM uint8_t RESERVED9[1020];
    union
    {
        __IOM uint32_t GICD_ICDICFRn;
        struct
        {
            __IOM uint32_t INT_CON0  : 2;
            __IOM uint32_t INT_CON1  : 2;
            __IOM uint32_t INT_CON2  : 2;
            __IOM uint32_t INT_CON3  : 2;
            __IOM uint32_t INT_CON4  : 2;
            __IOM uint32_t INT_CON5  : 2;
            __IOM uint32_t INT_CON6  : 2;
            __IOM uint32_t INT_CON7  : 2;
            __IOM uint32_t INT_CON8  : 2;
            __IOM uint32_t INT_CON9  : 2;
            __IOM uint32_t INT_CON10 : 2;
            __IOM uint32_t INT_CON11 : 2;
            __IOM uint32_t INT_CON12 : 2;
            __IOM uint32_t INT_CON13 : 2;
            __IOM uint32_t INT_CON14 : 2;
            __IOM uint32_t INT_CON15 : 2;
        } GICD_ICDICFRn_b;
    };
    __IM uint8_t RESERVED10[252];
    union
    {
        __IOM uint32_t GICD_PPI;
        struct
        {
            uint32_t            : 11;
            __IOM uint32_t PPI0 : 1;
            __IOM uint32_t PPI1 : 1;
            __IOM uint32_t PPI2 : 1;
            __IOM uint32_t PPI3 : 1;
            __IOM uint32_t PPI4 : 1;
            uint32_t            : 16;
        } GICD_PPI_b;
    };
    union
    {
        __IM uint32_t GICD_SPI;
        struct
        {
            __IM uint32_t SPI : 32;
        } GICD_SPI_b;
    };
    __IM uint8_t RESERVED11[504];
    union
    {
        __IOM uint32_t GICD_ICDSGIR;
        struct
        {
            __IOM uint32_t SGIINTID : 4;
            uint32_t                : 11;
            __IOM uint32_t SATT     : 1;
            __IOM uint32_t CPUTL    : 8;
            __IOM uint32_t TLF      : 2;
            uint32_t                : 6;
        } GICD_ICDSGIR_b;
    };
    __IM uint8_t RESERVED12[204];
    union
    {
        __IM uint8_t GICD_PIR4;
        struct
        {
            __IM uint8_t ID : 8;
        } GICD_PIR4_b;
    };
    __IM uint8_t RESERVED13[15];
    union
    {
        __IM uint8_t GICD_PIR0;
        struct
        {
            __IM uint8_t ID : 8;
        } GICD_PIR0_b;
    };
    __IM uint8_t RESERVED14[3];
    union
    {
        __IM uint8_t GICD_PIR1;
        struct
        {
            __IM uint8_t ID : 8;
        } GICD_PIR1_b;
    };
    __IM uint8_t RESERVED15[3];
    union
    {
        __IM uint8_t GICD_PIR2;
        struct
        {
            __IM uint8_t ID : 8;
        } GICD_PIR2_b;
    };
    __IM uint8_t RESERVED16[3];
    union
    {
        __IM uint8_t GICD_PIR3;
        struct
        {
            __IM uint8_t ID : 8;
        } GICD_PIR3_b;
    };
    __IM uint8_t RESERVED17[3];
    union
    {
        __IM uint8_t GICD_CIR0;
        struct
        {
            __IM uint8_t ID : 8;
        } GICD_CIR0_b;
    };
    __IM uint8_t RESERVED18[3];
    union
    {
        __IM uint8_t GICD_CIR1;
        struct
        {
            __IM uint8_t ID : 8;
        } GICD_CIR1_b;
    };
    __IM uint8_t RESERVED19[3];
    union
    {
        __IM uint8_t GICD_CIR2;
        struct
        {
            __IM uint8_t ID : 8;
        } GICD_CIR2_b;
    };
    __IM uint8_t RESERVED20[3];
    union
    {
        __IM uint8_t GICD_CIR3;
        struct
        {
            __IM uint8_t ID : 8;
        } GICD_CIR3_b;
    };
} R_INTC_GIC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_INTC_GIC_BASE    0x12C10100

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_INTC_GIC    ((R_INTC_GIC_Type *) R_INTC_GIC_BASE)

#endif
