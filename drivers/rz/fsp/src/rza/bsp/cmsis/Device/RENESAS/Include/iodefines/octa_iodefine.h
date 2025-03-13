/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : octa_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for octa.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef OCTA_IODEFINE_H
#define OCTA_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t DCR;
        struct
        {
            __IOM uint32_t DVCMD0 : 8;
            __IOM uint32_t DVCMD1 : 8;
            uint32_t              : 16;
        } DCR_b;
    };
    union
    {
        __IOM uint32_t DAR;
        struct
        {
            __IOM uint32_t DVAD0 : 8;
            __IOM uint32_t DVAD1 : 8;
            __IOM uint32_t DVAD2 : 8;
            __IOM uint32_t DVAD3 : 8;
        } DAR_b;
    };
    union
    {
        __IOM uint32_t DCSR;
        struct
        {
            __IOM uint32_t DALEN  : 8;
            __IOM uint32_t DMLEN  : 8;
            uint32_t              : 3;
            __IOM uint32_t ACDV   : 1;
            __IOM uint32_t CMDLEN : 3;
            __IOM uint32_t DAOR   : 1;
            __IOM uint32_t ADLEN  : 3;
            __IOM uint32_t DOPI   : 1;
            __IOM uint32_t ACDA   : 1;
            uint32_t              : 3;
        } DCSR_b;
    };
    union
    {
        __IOM uint32_t DSR0;
        struct
        {
            __IOM uint32_t DV0SZ  : 30;
            __IOM uint32_t DV0TYP : 2;
        } DSR0_b;
    };
    union
    {
        __IOM uint32_t DSR1;
        struct
        {
            __IOM uint32_t DV1SZ  : 30;
            __IOM uint32_t DV1TYP : 2;
        } DSR1_b;
    };
    union
    {
        __IOM uint32_t MDTR;
        struct
        {
            __IOM uint32_t DV0DEL   : 8;
            __IOM uint32_t DQSERAM  : 4;
            __IOM uint32_t DQSESOPI : 4;
            __IOM uint32_t DV1DEL   : 8;
            __IOM uint32_t DQSEDOPI : 4;
            uint32_t                : 4;
        } MDTR_b;
    };
    union
    {
        __IOM uint32_t ACTR;
        struct
        {
            __IOM uint32_t CTP : 32;
        } ACTR_b;
    };
    union
    {
        __IOM uint32_t ACAR0;
        struct
        {
            __IOM uint32_t CAD0 : 32;
        } ACAR0_b;
    };
    union
    {
        __IOM uint32_t ACAR1;
        struct
        {
            __IOM uint32_t CAD1 : 32;
        } ACAR1_b;
    };
    __IM uint8_t RESERVED[16];
    union
    {
        __IOM uint32_t DRCSTR;
        struct
        {
            __IOM uint32_t CTRW0    : 7;
            __IOM uint32_t CTR0     : 1;
            __IOM uint32_t DVRDCMD0 : 3;
            __IOM uint32_t DVRDHI0  : 3;
            __IOM uint32_t DVRDLO0  : 2;
            uint32_t                : 8;
            __IOM uint32_t DVRDCMD1 : 3;
            __IOM uint32_t DVRDHI1  : 3;
            __IOM uint32_t DVRDLO1  : 2;
        } DRCSTR_b;
    };
    union
    {
        __IOM uint32_t DWCSTR;
        struct
        {
            uint32_t               : 8;
            __IOM uint32_t DVWCMD0 : 3;
            __IOM uint32_t DVWHI0  : 3;
            __IOM uint32_t DVWLO0  : 2;
            uint32_t               : 8;
            __IOM uint32_t DVWCMD1 : 3;
            __IOM uint32_t DVWHI1  : 3;
            __IOM uint32_t DVWLO1  : 2;
        } DWCSTR_b;
    };
    union
    {
        __IOM uint32_t DCSTR;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t DVSELCMD : 3;
            __IOM uint32_t DVSELHI  : 3;
            __IOM uint32_t DVSELLO  : 2;
            uint32_t                : 16;
        } DCSTR_b;
    };
    union
    {
        __IOM uint32_t CDSR;
        struct
        {
            __IOM uint32_t DV0TTYP : 2;
            __IOM uint32_t DV1TTYP : 2;
            __IOM uint32_t DV0PC   : 1;
            __IOM uint32_t DV1PC   : 1;
            uint32_t               : 4;
            __IOM uint32_t ACMEME  : 2;
            __IOM uint32_t ACMODE  : 2;
            uint32_t               : 17;
            __IOM uint32_t DLFT    : 1;
        } CDSR_b;
    };
    union
    {
        __IOM uint32_t MDLR;
        struct
        {
            __IOM uint32_t DV0RDL : 8;
            __IOM uint32_t DV0WDL : 8;
            __IOM uint32_t DV1RDL : 8;
            __IOM uint32_t DV1WDL : 8;
        } MDLR_b;
    };
    union
    {
        __IOM uint32_t MRWCR0;
        struct
        {
            __IOM uint32_t D0MRCMD0 : 8;
            __IOM uint32_t D0MRCMD1 : 8;
            __IOM uint32_t D0MWCMD0 : 8;
            __IOM uint32_t D0MWCMD1 : 8;
        } MRWCR0_b;
    };
    union
    {
        __IOM uint32_t MRWCR1;
        struct
        {
            __IOM uint32_t D1MRCMD0 : 8;
            __IOM uint32_t D1MRCMD1 : 8;
            __IOM uint32_t D1MWCMD0 : 8;
            __IOM uint32_t D1MWCMD1 : 8;
        } MRWCR1_b;
    };
    union
    {
        __IOM uint32_t MRWCSR;
        struct
        {
            __IOM uint32_t MRAL0 : 3;
            __IOM uint32_t MRCL0 : 3;
            __IOM uint32_t MRO0  : 1;
            uint32_t             : 1;
            __IOM uint32_t MWAL0 : 3;
            __IOM uint32_t MWCL0 : 3;
            __IOM uint32_t MWO0  : 1;
            uint32_t             : 1;
            __IOM uint32_t MRAL1 : 3;
            __IOM uint32_t MRCL1 : 3;
            __IOM uint32_t MRO1  : 1;
            uint32_t             : 1;
            __IOM uint32_t MWAL1 : 3;
            __IOM uint32_t MWCL1 : 3;
            __IOM uint32_t MWO1  : 1;
            uint32_t             : 1;
        } MRWCSR_b;
    };
    union
    {
        __IM uint32_t ESR;
        struct
        {
            __IM uint32_t MRESR : 8;
            __IM uint32_t MWESR : 8;
            uint32_t            : 16;
        } ESR_b;
    };
    __OM uint32_t CWNDR;
    union
    {
        __OM uint32_t CWDR;
        struct
        {
            __OM uint32_t WD0 : 8;
            __OM uint32_t WD1 : 8;
            __OM uint32_t WD2 : 8;
            __OM uint32_t WD3 : 8;
        } CWDR_b;
    };
    union
    {
        __IM uint32_t CRR;
        struct
        {
            __IM uint32_t RD0 : 8;
            __IM uint32_t RD1 : 8;
            __IM uint32_t RD2 : 8;
            __IM uint32_t RD3 : 8;
        } CRR_b;
    };
    __IM uint8_t RESERVED1[28];
    union
    {
        __IOM uint32_t RSTCNT;
        struct
        {
            __IOM uint32_t RSTVAL : 1;
            uint32_t              : 31;
        } RSTCNT_b;
    };
    union
    {
        __IOM uint32_t AER;
        struct
        {
            __IOM uint32_t AAS : 3;
            uint32_t           : 29;
        } AER_b;
    };
} R_OCTA_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_OCTA_BASE    0x10080000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_OCTA    ((R_OCTA_Type *) R_OCTA_BASE)

#endif
