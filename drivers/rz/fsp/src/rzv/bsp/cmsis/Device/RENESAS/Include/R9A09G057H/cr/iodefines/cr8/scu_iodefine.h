/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : scu_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for scu.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef SCU_IODEFINE_H
#define SCU_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t SCUCR;
        struct
        {
            __IOM uint32_t SCUE        : 1;
            __IOM uint32_t AFE         : 1;
            __IOM uint32_t SCUREE      : 1;
            __IOM uint32_t SCUSLE      : 1;
            uint32_t                   : 1;
            __IOM uint32_t SCUSE       : 1;
            __IOM uint32_t ICSE        : 1;
            uint32_t                   : 5;
            __IOM uint32_t ECCCEM0     : 1;
            __IOM uint32_t ECCCEM1     : 1;
            __IOM uint32_t ECCCEMP     : 1;
            __IOM uint32_t ECCCEACP    : 1;
            __IOM uint32_t ECCCEC0FPP  : 1;
            __IOM uint32_t ECCCEC1FPP  : 1;
            __IOM uint32_t ECCCEC2FPP  : 1;
            __IOM uint32_t ECCCEC3FPP  : 1;
            __IOM uint32_t ECCCEAXITCM : 1;
            uint32_t                   : 11;
        } SCUCR_b;
    };
    union
    {
        __IOM uint32_t SCUCFR;
        struct
        {
            __IOM uint32_t NC   : 2;
            uint32_t            : 2;
            __IOM uint32_t CCM  : 4;
            __IOM uint32_t CSC0 : 4;
            __IOM uint32_t CSC1 : 4;
            __IOM uint32_t CSC2 : 4;
            __IOM uint32_t CSC3 : 4;
            uint32_t            : 7;
            __IOM uint32_t M    : 1;
        } SCUCFR_b;
    };
    union
    {
        __IOM uint32_t SCUCPSR;
        struct
        {
            __IOM uint32_t C0S : 2;
            uint32_t           : 6;
            __IOM uint32_t C1S : 2;
            uint32_t           : 6;
            __IOM uint32_t C2S : 2;
            uint32_t           : 6;
            __IOM uint32_t C3S : 2;
            uint32_t           : 6;
        } SCUCPSR_b;
    };
    union
    {
        __IOM uint32_t SCUIR;
        struct
        {
            __IOM uint32_t C0W : 4;
            __IOM uint32_t C1W : 4;
            __IOM uint32_t C2W : 4;
            __IOM uint32_t C3W : 4;
            uint32_t           : 16;
        } SCUIR_b;
    };
    __IM uint8_t RESERVED[48];
    union
    {
        __IOM uint32_t MFSAR;
        struct
        {
            uint32_t          : 20;
            __IM uint32_t FSA : 12;
        } MFSAR_b;
    };
    union
    {
        __IOM uint32_t MFEAR;
        struct
        {
            uint32_t          : 20;
            __IM uint32_t FEA : 12;
        } MFEAR_b;
    };
    union
    {
        __IOM uint32_t PFSAR;
        struct
        {
            uint32_t          : 20;
            __IM uint32_t FSA : 12;
        } PFSAR_b;
    };
    union
    {
        __IOM uint32_t PFEAR;
        struct
        {
            uint32_t          : 20;
            __IM uint32_t FEA : 12;
        } PFEAR_b;
    };
    union
    {
        __IOM uint32_t SCUACR;
        struct
        {
            __IOM uint32_t C0SCUA : 1;
            __IOM uint32_t C1SCUA : 1;
            __IOM uint32_t C2SCUA : 1;
            __IOM uint32_t C3SCUA : 1;
            uint32_t              : 28;
        } SCUACR_b;
    };
    __IM uint8_t RESERVED1[12];
    union
    {
        __IOM uint32_t SCUEBFER;
        struct
        {
            __IOM uint32_t STS  : 1;
            uint32_t            : 15;
            __IOM uint32_t WFC0 : 4;
            __IOM uint32_t WFC1 : 4;
            __IOM uint32_t WFC2 : 4;
            __IOM uint32_t WFC3 : 4;
        } SCUEBFER_b;
    };
    union
    {
        __IOM uint32_t SCUEBSER;
        struct
        {
            __IOM uint32_t STS   : 2;
            uint32_t             : 3;
            __IOM uint32_t INDEX : 9;
            uint32_t             : 2;
            __IOM uint32_t WAYS  : 16;
        } SCUEBSER_b;
    };
    __IM uint8_t RESERVED2[8];
    union
    {
        __IOM uint32_t SCUDTROR;
        struct
        {
            __IOM uint32_t RW    : 1;
            uint32_t             : 4;
            __IOM uint32_t SCURS : 9;
            uint32_t             : 10;
            __IOM uint32_t SCURC : 2;
            uint32_t             : 4;
            __IOM uint32_t SCURW : 2;
        } SCUDTROR_b;
    };
    union
    {
        __IOM uint32_t SCUDTRDVR;
        struct
        {
            uint32_t             : 17;
            __IOM uint32_t VM    : 5;
            __IOM uint32_t VALID : 1;
            uint32_t             : 9;
        } SCUDTRDVR_b;
    };
    union
    {
        __IOM uint32_t SCUDTRECR;
        struct
        {
            __IOM uint32_t CHUNK : 7;
            uint32_t             : 25;
        } SCUDTRECR_b;
    };
    union
    {
        __IOM uint32_t ECCFER;
        struct
        {
            __IOM uint32_t EFEDC0 : 1;
            __IOM uint32_t EFEDC1 : 1;
            __IOM uint32_t EFEDC2 : 1;
            __IOM uint32_t EFEDC3 : 1;
            uint32_t              : 4;
            __IOM uint32_t EFED   : 1;
            uint32_t              : 23;
        } ECCFER_b;
    };
    union
    {
        __IOM uint32_t FPPFSAR0;
        struct
        {
            uint32_t           : 20;
            __IOM uint32_t FSA : 12;
        } FPPFSAR0_b;
    };
    union
    {
        __IOM uint32_t FPPFEAR0;
        struct
        {
            uint32_t           : 20;
            __IOM uint32_t FEA : 12;
        } FPPFEAR0_b;
    };
    union
    {
        __IOM uint32_t FPPFSAR1;
        struct
        {
            uint32_t           : 20;
            __IOM uint32_t FSA : 12;
        } FPPFSAR1_b;
    };
    union
    {
        __IOM uint32_t FPPFEAR1;
        struct
        {
            uint32_t           : 20;
            __IOM uint32_t FEA : 12;
        } FPPFEAR1_b;
    };
    union
    {
        __IOM uint32_t FPPFSAR2;
        struct
        {
            uint32_t           : 20;
            __IOM uint32_t FSA : 12;
        } FPPFSAR2_b;
    };
    union
    {
        __IOM uint32_t FPPFEAR2;
        struct
        {
            uint32_t           : 20;
            __IOM uint32_t FEA : 12;
        } FPPFEAR2_b;
    };
    union
    {
        __IOM uint32_t FPPFSAR3;
        struct
        {
            uint32_t           : 20;
            __IOM uint32_t FSA : 12;
        } FPPFSAR3_b;
    };
    union
    {
        __IOM uint32_t FPPFEAR3;
        struct
        {
            uint32_t           : 20;
            __IOM uint32_t FEA : 12;
        } FPPFEAR3_b;
    };
} R_SCU_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_SCU_BASE    0x12C10000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_SCU    ((R_SCU_Type *) R_SCU_BASE)

#endif
