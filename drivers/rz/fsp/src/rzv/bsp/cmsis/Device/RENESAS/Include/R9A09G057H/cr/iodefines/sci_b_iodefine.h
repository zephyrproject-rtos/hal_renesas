/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : sci_b_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for rsci.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef RSCI_IODEFINE_H
#define RSCI_IODEFINE_H

typedef struct
{
    union
    {
        union
        {
            __IM uint32_t RDR;
            struct
            {
                __IM uint32_t RDAT : 9;
                __IM uint32_t MPB  : 1;
                __IM uint32_t DR   : 1;
                __IM uint32_t FPER : 1;
                __IM uint32_t FFER : 1;
                uint32_t           : 11;
                __IM uint32_t ORER : 1;
                uint32_t           : 2;
                __IM uint32_t PER  : 1;
                __IM uint32_t FER  : 1;
                uint32_t           : 3;
            } RDR_b;
        };
        union
        {
            __IOM uint8_t RDR_BY;
            struct
            {
                __IOM uint8_t RDAT : 8;
            } RDR_BY_b;
        };
    };
    union
    {
        union
        {
            __IOM uint32_t TDR;
            struct
            {
                __IOM uint32_t TDAT : 9;
                __IOM uint32_t MPBT : 1;
                uint32_t            : 22;
            } TDR_b;
        };
        union
        {
            __IOM uint8_t TDR_BY;
            struct
            {
                __IOM uint8_t TDAT : 8;
            } TDR_BY_b;
        };
    };
    union
    {
        __IOM uint32_t CCR0;
        struct
        {
            __IOM uint32_t RE    : 1;
            uint32_t             : 3;
            __IOM uint32_t TE    : 1;
            uint32_t             : 3;
            __IOM uint32_t MPIE  : 1;
            __IOM uint32_t DCME  : 1;
            __IOM uint32_t IDSEL : 1;
            uint32_t             : 5;
            __IOM uint32_t RIE   : 1;
            uint32_t             : 3;
            __IOM uint32_t TIE   : 1;
            __IOM uint32_t TEIE  : 1;
            uint32_t             : 2;
            __IOM uint32_t SSE   : 1;
            uint32_t             : 7;
        } CCR0_b;
    };
    union
    {
        __IOM uint32_t CCR1;
        struct
        {
            __IOM uint32_t CTSE   : 1;
            __IOM uint32_t CTSPEN : 1;
            uint32_t              : 2;
            __IOM uint32_t SPB2DT : 1;
            __IOM uint32_t SPB2IO : 1;
            uint32_t              : 2;
            __IOM uint32_t PE     : 1;
            __IOM uint32_t PM     : 1;
            uint32_t              : 2;
            __IOM uint32_t TINV   : 1;
            __IOM uint32_t RINV   : 1;
            uint32_t              : 2;
            __IOM uint32_t SPLP   : 1;
            uint32_t              : 3;
            __IOM uint32_t SHARPS : 1;
            uint32_t              : 3;
            __IOM uint32_t NFCS   : 3;
            uint32_t              : 1;
            __IOM uint32_t NFEN   : 1;
            uint32_t              : 3;
        } CCR1_b;
    };
    union
    {
        __IOM uint32_t CCR2;
        struct
        {
            __IOM uint32_t BCP   : 3;
            uint32_t             : 1;
            __IOM uint32_t BGDM  : 1;
            __IOM uint32_t ABCS  : 1;
            __IOM uint32_t ABCSE : 1;
            uint32_t             : 1;
            __IOM uint32_t BRR   : 8;
            __IOM uint32_t BRME  : 1;
            uint32_t             : 3;
            __IOM uint32_t CKS   : 2;
            uint32_t             : 2;
            __IOM uint32_t MDDR  : 8;
        } CCR2_b;
    };
    union
    {
        __IOM uint32_t CCR3;
        struct
        {
            __IOM uint32_t CPHA    : 1;
            __IOM uint32_t CPOL    : 1;
            uint32_t               : 5;
            __IOM uint32_t BPEN    : 1;
            __IOM uint32_t CHR     : 2;
            uint32_t               : 2;
            __IOM uint32_t LSBF    : 1;
            __IOM uint32_t SINV    : 1;
            __IOM uint32_t STP     : 1;
            __IOM uint32_t RXDESEL : 1;
            __IOM uint32_t MOD     : 3;
            __IOM uint32_t MP      : 1;
            __IOM uint32_t FM      : 1;
            __IOM uint32_t DEN     : 1;
            uint32_t               : 2;
            __IOM uint32_t CKE     : 2;
            uint32_t               : 2;
            __IOM uint32_t GM      : 1;
            __IOM uint32_t BLK     : 1;
            uint32_t               : 2;
        } CCR3_b;
    };
    union
    {
        __IOM uint32_t CCR4;
        struct
        {
            __IOM uint32_t CMPD : 9;
            uint32_t            : 7;
            __IOM uint32_t ASEN : 1;
            __IOM uint32_t ATEN : 1;
            uint32_t            : 6;
            __IOM uint32_t AST  : 3;
            __IOM uint32_t AJD  : 1;
            __IOM uint32_t ATT  : 3;
            __IOM uint32_t AET  : 1;
        } CCR4_b;
    };
    union
    {
        __IM uint8_t CESR;
        struct
        {
            __IM uint8_t RIST : 1;
            uint8_t           : 3;
            __IM uint8_t TIST : 1;
            uint8_t           : 3;
        } CESR_b;
    };
    __IM uint8_t RESERVED[1];
    union
    {
        __IOM uint8_t HCR;
        struct
        {
            __IOM uint8_t HDEN : 1;
            uint8_t            : 7;
        } HCR_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint32_t ICR;
        struct
        {
            __IOM uint32_t IICDL      : 5;
            uint32_t                  : 3;
            __IOM uint32_t IICINTM    : 1;
            __IOM uint32_t IICCSC     : 1;
            uint32_t                  : 3;
            __IOM uint32_t IICACKT    : 1;
            uint32_t                  : 2;
            __IOM uint32_t IICSTAREQ  : 1;
            __IOM uint32_t IICRSTAREQ : 1;
            __IOM uint32_t IICSTPREQ  : 1;
            uint32_t                  : 1;
            __IOM uint32_t IICSDAS    : 2;
            __IOM uint32_t IICSCLS    : 2;
            uint32_t                  : 8;
        } ICR_b;
    };
    union
    {
        __IOM uint32_t FCR;
        struct
        {
            __IOM uint32_t DRES  : 1;
            uint32_t             : 7;
            __IOM uint32_t TTRG  : 5;
            uint32_t             : 2;
            __OM uint32_t  TFRST : 1;
            __IOM uint32_t RTRG  : 5;
            uint32_t             : 2;
            __OM uint32_t  RFRST : 1;
            __IOM uint32_t RSTRG : 5;
            uint32_t             : 3;
        } FCR_b;
    };
    __IM uint8_t RESERVED2[8];
    union
    {
        __IOM uint32_t DCR;
        struct
        {
            __IOM uint32_t DEPOL : 1;
            uint32_t             : 7;
            __IOM uint32_t DEAST : 5;
            uint32_t             : 3;
            __IOM uint32_t DENGT : 5;
            uint32_t             : 11;
        } DCR_b;
    };
    union
    {
        __IOM uint32_t XCR0;
        struct
        {
            __IOM uint32_t TCSS  : 2;
            uint32_t             : 6;
            __IOM uint32_t BFE   : 1;
            __IOM uint32_t CF0RE : 1;
            __IOM uint32_t CF1DS : 2;
            __IOM uint32_t PIBE  : 1;
            __IOM uint32_t PIBS  : 3;
            __IOM uint32_t BFOIE : 1;
            __IOM uint32_t BCDIE : 1;
            uint32_t             : 2;
            __IOM uint32_t BFDIE : 1;
            __IOM uint32_t COFIE : 1;
            __IOM uint32_t AEDIE : 1;
            uint32_t             : 1;
            __IOM uint32_t BCCS  : 2;
            uint32_t             : 6;
        } XCR0_b;
    };
    union
    {
        __IOM uint32_t XCR1;
        struct
        {
            __IOM uint32_t TCST  : 1;
            uint32_t             : 3;
            __IOM uint32_t SDST  : 1;
            __IOM uint32_t BMEN  : 1;
            uint32_t             : 2;
            __IOM uint32_t PCF1D : 8;
            __IOM uint32_t SCF1D : 8;
            __IOM uint32_t CF1CE : 8;
        } XCR1_b;
    };
    union
    {
        __IOM uint32_t XCR2;
        struct
        {
            __IOM uint32_t CF0D  : 8;
            __IOM uint32_t CF0CE : 8;
            __IOM uint32_t BFLW  : 16;
        } XCR2_b;
    };
    __IM uint8_t RESERVED3[8];
    union
    {
        __IM uint32_t CSR;
        struct
        {
            uint32_t             : 4;
            __IM uint32_t ERS    : 1;
            uint32_t             : 10;
            __IM uint32_t RXDMON : 1;
            __IM uint32_t DCMF   : 1;
            __IM uint32_t DPER   : 1;
            __IM uint32_t DFER   : 1;
            uint32_t             : 5;
            __IM uint32_t ORER   : 1;
            uint32_t             : 1;
            __IM uint32_t MFF    : 1;
            __IM uint32_t PER    : 1;
            __IM uint32_t FER    : 1;
            __IM uint32_t TDRE   : 1;
            __IM uint32_t TEND   : 1;
            __IM uint32_t RDRF   : 1;
        } CSR_b;
    };
    union
    {
        __IM uint32_t ISR;
        struct
        {
            __IM uint32_t IICACKR : 1;
            uint32_t              : 2;
            __IM uint32_t IICSTIF : 1;
            uint32_t              : 28;
        } ISR_b;
    };
    union
    {
        __IM uint32_t FRSR;
        struct
        {
            __IM uint32_t DR   : 1;
            uint32_t           : 7;
            __IM uint32_t R    : 6;
            uint32_t           : 2;
            __IM uint32_t PNUM : 6;
            uint32_t           : 2;
            __IM uint32_t FNUM : 6;
            uint32_t           : 2;
        } FRSR_b;
    };
    union
    {
        __IM uint32_t FTSR;
        struct
        {
            __IM uint32_t T : 6;
            uint32_t        : 26;
        } FTSR_b;
    };
    __IM uint8_t RESERVED4[4];
    union
    {
        __IM uint32_t XSR0;
        struct
        {
            __IM uint32_t SFSF  : 1;
            __IM uint32_t RXDSF : 1;
            uint32_t            : 6;
            __IM uint32_t BFOF  : 1;
            __IM uint32_t BCDF  : 1;
            __IM uint32_t BFDF  : 1;
            __IM uint32_t CF0MF : 1;
            __IM uint32_t CF1MF : 1;
            __IM uint32_t PIBDF : 1;
            __IM uint32_t COF   : 1;
            __IM uint32_t AEDF  : 1;
            __IM uint32_t CF0RD : 8;
            __IM uint32_t CF1RD : 8;
        } XSR0_b;
    };
    union
    {
        __IM uint32_t XSR1;
        struct
        {
            __IM uint32_t TCNT : 16;
            uint32_t           : 16;
        } XSR1_b;
    };
    __IM uint8_t RESERVED5[4];
    union
    {
        __OM uint32_t CFCLR;
        struct
        {
            uint32_t            : 4;
            __OM uint32_t ERSC  : 1;
            uint32_t            : 11;
            __OM uint32_t DCMFC : 1;
            __OM uint32_t DPERC : 1;
            __OM uint32_t DFERC : 1;
            uint32_t            : 5;
            __OM uint32_t ORERC : 1;
            uint32_t            : 1;
            __OM uint32_t MFFC  : 1;
            __OM uint32_t PERC  : 1;
            __OM uint32_t FERC  : 1;
            __OM uint32_t TDREC : 1;
            uint32_t            : 1;
            __OM uint32_t RDRFC : 1;
        } CFCLR_b;
    };
    union
    {
        __OM uint32_t ICFCLR;
        struct
        {
            uint32_t               : 3;
            __OM uint32_t IICSTIFC : 1;
            uint32_t               : 28;
        } ICFCLR_b;
    };
    union
    {
        __OM uint32_t FFCLR;
        struct
        {
            __OM uint32_t DRC : 1;
            uint32_t          : 31;
        } FFCLR_b;
    };
    __IM uint8_t RESERVED6[4];
    union
    {
        __OM uint32_t XFCLR;
        struct
        {
            uint32_t            : 8;
            __OM uint32_t BFOC  : 1;
            __OM uint32_t BCDC  : 1;
            __OM uint32_t BFDC  : 1;
            __OM uint32_t CF0MC : 1;
            __OM uint32_t CF1MC : 1;
            __OM uint32_t PIBDC : 1;
            __OM uint32_t COFC  : 1;
            __OM uint32_t AEDC  : 1;
            uint32_t            : 16;
        } XFCLR_b;
    };
} R_SCI_B0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_SCI0_BASE    0x12800C00
#define R_SCI1_BASE    0x12801000
#define R_SCI2_BASE    0x12801400
#define R_SCI3_BASE    0x12801800
#define R_SCI4_BASE    0x12801C00
#define R_SCI5_BASE    0x12802000
#define R_SCI6_BASE    0x12802400
#define R_SCI7_BASE    0x12802800
#define R_SCI8_BASE    0x12802C00
#define R_SCI9_BASE    0x12803000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_SCI0    ((R_SCI_B0_Type *) R_SCI0_BASE)
#define R_SCI1    ((R_SCI_B0_Type *) R_SCI1_BASE)
#define R_SCI2    ((R_SCI_B0_Type *) R_SCI2_BASE)
#define R_SCI3    ((R_SCI_B0_Type *) R_SCI3_BASE)
#define R_SCI4    ((R_SCI_B0_Type *) R_SCI4_BASE)
#define R_SCI5    ((R_SCI_B0_Type *) R_SCI5_BASE)
#define R_SCI6    ((R_SCI_B0_Type *) R_SCI6_BASE)
#define R_SCI7    ((R_SCI_B0_Type *) R_SCI7_BASE)
#define R_SCI8    ((R_SCI_B0_Type *) R_SCI8_BASE)
#define R_SCI9    ((R_SCI_B0_Type *) R_SCI9_BASE)

#endif
