/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : tzc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for tzc.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef GBETH0_IODEFINE_H
#define GBETH0_IODEFINE_H
typedef struct
{
    union
    {
        __IOM uint32_t DCCR;
        struct
        {
            uint32_t             : 16;
            __IOM uint32_t PBLx8 : 1;
            uint32_t             : 1;
            __IOM uint32_t DSL   : 3;
            uint32_t             : 11;
        } DCCR_b;
    };
    union
    {
        __IOM uint32_t DCTCR;
        struct
        {
            __IOM uint32_t ST    : 1;
            __IOM uint32_t TCW   : 3;
            __IOM uint32_t OSF   : 1;
            uint32_t             : 10;
            __IOM uint32_t IPBL  : 1;
            __IOM uint32_t TxPBL : 6;
            uint32_t             : 2;
            __IOM uint32_t TQOS  : 4;
            uint32_t             : 4;
        } DCTCR_b;
    };
    union
    {
        __IOM uint32_t DCRCR;
        struct
        {
            __IOM uint32_t SR        : 1;
            __IOM uint32_t RBSZ_4_0  : 4;
            __IOM uint32_t RBSZ_13_5 : 10;
            uint32_t                 : 1;
            __IOM uint32_t RxPBL     : 6;
            uint32_t                 : 9;
            __IOM uint32_t RPF       : 1;
        } DCRCR_b;
    };
    __IM uint8_t RESERVED58[8];
    union
    {
        __IOM uint32_t DCTLAR;
        struct
        {
            uint32_t              : 4;
            __IOM uint32_t TDESLA : 28;
        } DCTLAR_b;
    };
    __IM uint8_t RESERVED59[4];
    union
    {
        __IOM uint32_t DCRLAR;
        struct
        {
            uint32_t              : 4;
            __IOM uint32_t RDESLA : 28;
        } DCRLAR_b;
    };
    union
    {
        __IOM uint32_t DCTTPR;
        struct
        {
            uint32_t            : 4;
            __IOM uint32_t TDTP : 28;
        } DCTTPR_b;
    };
    __IM uint8_t RESERVED60[4];
    union
    {
        __IOM uint32_t DCRTPR;
        struct
        {
            uint32_t            : 4;
            __IOM uint32_t RDTP : 28;
        } DCRTPR_b;
    };
    union
    {
        __IOM uint32_t DCTRLR;
        struct
        {
            __IOM uint32_t TDRL : 10;
            uint32_t            : 22;
        } DCTRLR_b;
    };
    union
    {
        __IOM uint32_t DCRC2R;
        struct
        {
            __IOM uint32_t RDRL : 10;
            uint32_t            : 8;
            __IOM uint32_t ARBS : 7;
            uint32_t            : 7;
        } DCRC2R_b;
    };
    union
    {
        __IOM uint32_t DCIER;
        struct
        {
            __IOM uint32_t TIE  : 1;
            __IOM uint32_t TXSE : 1;
            __IOM uint32_t TBUE : 1;
            uint32_t            : 3;
            __IOM uint32_t RIE  : 1;
            __IOM uint32_t RBUE : 1;
            __IOM uint32_t RSE  : 1;
            __IOM uint32_t RWTE : 1;
            __IOM uint32_t ETIE : 1;
            __IOM uint32_t ERIE : 1;
            __IOM uint32_t FBEE : 1;
            __IOM uint32_t CDEE : 1;
            __IOM uint32_t AIE  : 1;
            __IOM uint32_t NIE  : 1;
            uint32_t            : 16;
        } DCIER_b;
    };
    union
    {
        __IOM uint32_t DCRIWT;
        struct
        {
            __IOM uint32_t RWT  : 8;
            uint32_t            : 8;
            __IOM uint32_t RWTU : 2;
            uint32_t            : 14;
        } DCRIWT_b;
    };
    union
    {
        __IOM uint32_t DCSFCS;
        struct
        {
            __IOM uint32_t ESC : 1;
            __IOM uint32_t ASC : 1;
            uint32_t           : 2;
            __IOM uint32_t SIV : 12;
            __IM uint32_t  RSN : 4;
            uint32_t           : 12;
        } DCSFCS_b;
    };
    __IM uint8_t RESERVED61[4];
    union
    {
        __IM uint32_t DCCATDR;
        struct
        {
            __IM uint32_t CURTDESAPTR : 32;
        } DCCATDR_b;
    };
    __IM uint8_t RESERVED62[4];
    union
    {
        __IM uint32_t DCCARDR;
        struct
        {
            __IM uint32_t CURRDESAPTR : 32;
        } DCCARDR_b;
    };
    __IM uint8_t RESERVED63[4];
    union
    {
        __IM uint32_t DCCATBR;
        struct
        {
            __IM uint32_t CURTBUFAPTR : 32;
        } DCCATBR_b;
    };
    __IM uint8_t RESERVED64[4];
    union
    {
        __IM uint32_t DCCARBR;
        struct
        {
            __IM uint32_t CURRBUFAPTR : 32;
        } DCCARBR_b;
    };
    union
    {
        __IOM uint32_t DCSR;
        struct
        {
            __IOM uint32_t TI  : 1;
            __IOM uint32_t TPS : 1;
            __IOM uint32_t TBU : 1;
            uint32_t           : 3;
            __IOM uint32_t RI  : 1;
            __IOM uint32_t RBU : 1;
            __IOM uint32_t RPS : 1;
            __IOM uint32_t RWT : 1;
            __IOM uint32_t ETI : 1;
            __IOM uint32_t ERI : 1;
            __IOM uint32_t FBE : 1;
            __IOM uint32_t CDE : 1;
            __IOM uint32_t AIS : 1;
            __IOM uint32_t NIS : 1;
            __IM uint32_t  TEB : 3;
            __IM uint32_t  REB : 3;
            uint32_t           : 10;
        } DCSR_b;
    };
    union
    {
        __IM uint32_t DCMFCR;
        struct
        {
            __IM uint32_t MFC  : 11;
            uint32_t           : 4;
            __IM uint32_t MFCO : 1;
            uint32_t           : 16;
        } DCMFCR_b;
    };
    __IM uint8_t RESERVED65[24];
} R_GBETH_DMAC_Type;

typedef struct
{
    union
    {
        __IOM uint32_t MTLTOMR;
        struct
        {
            __IOM uint32_t FTQ   : 1;
            __IOM uint32_t TSF   : 1;
            __IOM uint32_t TXQEN : 2;
            __IOM uint32_t TTC   : 3;
            uint32_t             : 9;
            __IOM uint32_t TQS   : 5;
            uint32_t             : 11;
        } MTLTOMR_b;
    };
    union
    {
        __IM uint32_t MTLTUR;
        struct
        {
            __IM uint32_t UFFRMCNT : 11;
            __IM uint32_t UFCNTOVF : 1;
            uint32_t               : 20;
        } MTLTUR_b;
    };
    union
    {
        __IM uint32_t MTLTDR;
        struct
        {
            __IM uint32_t TXQPAUSED : 2;
            __IM uint32_t TRCSTS    : 1;
            __IM uint32_t TWCSTS    : 1;
            __IM uint32_t TXQSTS    : 1;
            __IM uint32_t TXSTSFSTS : 1;
            uint32_t                : 10;
            __IM uint32_t PTXQ      : 3;
            uint32_t                : 1;
            __IM uint32_t STXSTSF   : 3;
            uint32_t                : 9;
        } MTLTDR_b;
    };
    __IM uint8_t RESERVED49[4];
    union
    {
        __IOM uint32_t MTLTECR;
        struct
        {
            uint32_t             : 2;
            __IOM uint32_t AVALG : 1;
            __IOM uint32_t CC    : 1;
            __IOM uint32_t SLC   : 3;
            uint32_t             : 25;
        } MTLTECR_b;
    };
    union
    {
        __IM uint32_t MTLTESR;
        struct
        {
            __IM uint32_t ABS : 24;
            uint32_t          : 8;
        } MTLTESR_b;
    };
    union
    {
        __IOM uint32_t MTLTQWR;
        struct
        {
            __IOM uint32_t ISCQW : 21;
            uint32_t             : 11;
        } MTLTQWR_b;
    };
    union
    {
        __IOM uint32_t MTLTSR;
        struct
        {
            __IOM uint32_t SSC : 14;
            uint32_t           : 18;
        } MTLTSR_b;
    };
    union
    {
        __IOM uint32_t MTLTHR;
        struct
        {
            __IOM uint32_t HC : 29;
            uint32_t          : 3;
        } MTLTHR_b;
    };
    union
    {
        __IOM uint32_t MTLTLR;
        struct
        {
            __IOM uint32_t LC : 29;
            uint32_t          : 3;
        } MTLTLR_b;
    };
    __IM uint8_t RESERVED50[4];
    union
    {
        __IOM uint32_t MTLQICSR;
        struct
        {
            __IOM uint32_t TXUNFIS : 1;
            __IOM uint32_t ABPSIS  : 1;
            uint32_t               : 6;
            __IOM uint32_t TXUIE   : 1;
            __IOM uint32_t ABPSIE  : 1;
            uint32_t               : 6;
            __IOM uint32_t RXOVFIS : 1;
            uint32_t               : 7;
            __IOM uint32_t RXOIE   : 1;
            uint32_t               : 7;
        } MTLQICSR_b;
    };
    union
    {
        __IOM uint32_t MTLROMR;
        struct
        {
            __IOM uint32_t RTC        : 2;
            uint32_t                  : 1;
            __IOM uint32_t FUP        : 1;
            __IOM uint32_t FEP        : 1;
            __IOM uint32_t RSF        : 1;
            __IOM uint32_t DIS_TCP_EF : 1;
            __IOM uint32_t EHFC       : 1;
            __IOM uint32_t RFA        : 4;
            uint32_t                  : 2;
            __IOM uint32_t RFD        : 4;
            uint32_t                  : 2;
            __IOM uint32_t RQS        : 5;
            uint32_t                  : 7;
        } MTLROMR_b;
    };
    union
    {
        __IM uint32_t MTLRMPOC;
        struct
        {
            __IM uint32_t OVFPKTCNT : 11;
            __IM uint32_t OVFCNTOVF : 1;
            uint32_t                : 4;
            __IM uint32_t MISPKTCNT : 11;
            __IM uint32_t MISCNTOVF : 1;
            uint32_t                : 4;
        } MTLRMPOC_b;
    };
    union
    {
        __IM uint32_t MTLRDR;
        struct
        {
            __IM uint32_t RWCSTS : 1;
            __IM uint32_t RRCSTS : 2;
            uint32_t             : 1;
            __IM uint32_t RXQSTS : 2;
            uint32_t             : 10;
            __IM uint32_t PRXQ   : 14;
            uint32_t             : 2;
        } MTLRDR_b;
    };
    union
    {
        __IOM uint32_t MTLRCR;
        struct
        {
            __IOM uint32_t RXQ_WEGT : 3;
            uint32_t                : 29;
        } MTLRCR_b;
    };
} R_GBETH_MTL_Q_Type;

typedef struct
{
    union
    {
        __IOM uint32_t MACAHR;
        struct
        {
            __IOM uint32_t ADDRHI : 16;
            __IOM uint32_t DCS    : 4;
            uint32_t              : 4;
            __IOM uint32_t MBC    : 6;
            __IOM uint32_t SA     : 1;
            __IOM uint32_t AE     : 1;
        } MACAHR_b;
    };
    union
    {
        __IOM uint32_t MACALR;
        struct
        {
            __IOM uint32_t ADDRLO : 32;
        } MACALR_b;
    };
} R_GBETH_MAC_ADDRESS_Type;

typedef struct
{
    union
    {
        __IOM uint32_t MACCR;
        struct
        {
            __IOM uint32_t RE     : 1;
            __IOM uint32_t TE     : 1;
            __IOM uint32_t PRELEN : 2;
            __IOM uint32_t DC     : 1;
            __IOM uint32_t BL     : 2;
            uint32_t              : 1;
            __IOM uint32_t DR     : 1;
            __IOM uint32_t DCRS   : 1;
            __IOM uint32_t DO     : 1;
            __IOM uint32_t ECRSFD : 1;
            __IOM uint32_t LM     : 1;
            __IOM uint32_t DM     : 1;
            __IOM uint32_t FES    : 1;
            __IOM uint32_t PS     : 1;
            __IOM uint32_t JE     : 1;
            __IOM uint32_t JD     : 1;
            __IOM uint32_t BE     : 1;
            __IOM uint32_t WD     : 1;
            __IOM uint32_t ACS    : 1;
            __IOM uint32_t CST    : 1;
            __IOM uint32_t S2KP   : 1;
            __IOM uint32_t GPSLCE : 1;
            __IOM uint32_t IPG    : 3;
            __IOM uint32_t IPC    : 1;
            __IOM uint32_t SARC   : 3;
            __IOM uint32_t ARPEN  : 1;
        } MACCR_b;
    };
    union
    {
        __IOM uint32_t MACECR;
        struct
        {
            __IOM uint32_t GPSL   : 14;
            uint32_t              : 2;
            __IOM uint32_t DCRCC  : 1;
            __IOM uint32_t SPEN   : 1;
            __IOM uint32_t USP    : 1;
            __IOM uint32_t PDC    : 1;
            __IOM uint32_t HDSMS  : 3;
            uint32_t              : 1;
            __IOM uint32_t EIPGEN : 1;
            __IOM uint32_t EIPG   : 5;
            __IOM uint32_t APDIM  : 1;
            __IOM uint32_t FHE    : 1;
        } MACECR_b;
    };
    union
    {
        __IOM uint32_t MACPFR;
        struct
        {
            __IOM uint32_t PR   : 1;
            __IOM uint32_t HUC  : 1;
            __IOM uint32_t HMC  : 1;
            __IOM uint32_t DAIF : 1;
            __IOM uint32_t PM   : 1;
            __IOM uint32_t DBF  : 1;
            __IOM uint32_t PCF  : 2;
            __IOM uint32_t SAIF : 1;
            __IOM uint32_t SAF  : 1;
            __IOM uint32_t HPF  : 1;
            uint32_t            : 5;
            __IOM uint32_t VTFE : 1;
            uint32_t            : 3;
            __IOM uint32_t IPFE : 1;
            __IOM uint32_t DNTU : 1;
            uint32_t            : 9;
            __IOM uint32_t RA   : 1;
        } MACPFR_b;
    };
    union
    {
        __IOM uint32_t MACWTR;
        struct
        {
            __IOM uint32_t WTO : 4;
            uint32_t           : 4;
            __IOM uint32_t PWE : 1;
            uint32_t           : 23;
        } MACWTR_b;
    };
    union
    {
        __IOM uint32_t MACHTR0;
        struct
        {
            __IOM uint32_t HT31T0 : 32;
        } MACHTR0_b;
    };
    union
    {
        __IOM uint32_t MACHTR1;
        struct
        {
            __IOM uint32_t HT63T32 : 32;
        } MACHTR1_b;
    };
    union
    {
        __IOM uint32_t MACHTR2;
        struct
        {
            __IOM uint32_t HT95T64 : 32;
        } MACHTR2_b;
    };
    union
    {
        __IOM uint32_t MACHTR3;
        struct
        {
            __IOM uint32_t HT127T96 : 32;
        } MACHTR3_b;
    };
    union
    {
        __IOM uint32_t MACHTR4;
        struct
        {
            __IOM uint32_t HT159T128 : 32;
        } MACHTR4_b;
    };
    union
    {
        __IOM uint32_t MACHTR5;
        struct
        {
            __IOM uint32_t HT191T160 : 32;
        } MACHTR5_b;
    };
    union
    {
        __IOM uint32_t MACHTR6;
        struct
        {
            __IOM uint32_t HT223T192 : 32;
        } MACHTR6_b;
    };
    union
    {
        __IOM uint32_t MACHTR7;
        struct
        {
            __IOM uint32_t HT255T224 : 32;
        } MACHTR7_b;
    };
    __IM uint8_t RESERVED[32];
    union
    {
        __IOM uint32_t MACVTCR;
        struct
        {
            __IOM uint32_t OB      : 1;
            __IOM uint32_t CT      : 1;
            __IOM uint32_t OFS     : 2;
            uint32_t               : 12;
            __IOM uint32_t ETV     : 1;
            __IOM uint32_t VTIM    : 1;
            __IOM uint32_t ESVL    : 1;
            __IOM uint32_t ERSVLM  : 1;
            __IOM uint32_t DOVLTC  : 1;
            __IOM uint32_t EVLS    : 2;
            uint32_t               : 1;
            __IOM uint32_t EVLRXS  : 1;
            __IOM uint32_t VTHM    : 1;
            __IOM uint32_t EDVLP   : 1;
            __IOM uint32_t ERIVLT  : 1;
            __IOM uint32_t EIVLS   : 2;
            uint32_t               : 1;
            __IOM uint32_t EIVLRXS : 1;
        } MACVTCR_b;
    };
    union
    {
        union
        {
            __IOM uint32_t MACVTDR;
            struct
            {
                __IOM uint32_t VID     : 16;
                __IOM uint32_t VEN     : 1;
                __IOM uint32_t ETV     : 1;
                __IOM uint32_t DOVLTC  : 1;
                __IOM uint32_t ERSVLM  : 1;
                __IOM uint32_t ERIVLT  : 1;
                uint32_t               : 3;
                __IOM uint32_t DMACHEN : 1;
                __IOM uint32_t DMACHN  : 2;
                uint32_t               : 5;
            } MACVTDR_b;
        };
        union
        {
            __IOM uint32_t MACVTFR;
            struct
            {
                __IOM uint32_t VID     : 16;
                __IOM uint32_t VEN     : 1;
                __IOM uint32_t ETV     : 1;
                __IOM uint32_t DOVLTC  : 1;
                __IOM uint32_t ERSVLM  : 1;
                __IOM uint32_t ERIVLT  : 1;
                uint32_t               : 3;
                __IOM uint32_t DMACHEN : 1;
                __IOM uint32_t DMACHN  : 2;
                uint32_t               : 5;
            } MACVTFR_b;
        };
    };
    union
    {
        __IOM uint32_t MACVHTR;
        struct
        {
            __IOM uint32_t VLHT : 16;
            uint32_t            : 16;
        } MACVHTR_b;
    };
    __IM uint8_t RESERVED1[20];
    union
    {
        __IOM uint32_t MACQTFCR;
        struct
        {
            __IOM uint32_t FCB_BPA : 1;
            __IOM uint32_t TFE     : 1;
            uint32_t               : 2;
            __IOM uint32_t PLT     : 3;
            __IOM uint32_t DZPQ    : 1;
            uint32_t               : 8;
            __IOM uint32_t PT      : 16;
        } MACQTFCR_b;
    };
    __IM uint8_t RESERVED2[28];
    union
    {
        __IOM uint32_t MACRFCR;
        struct
        {
            __IOM uint32_t RFE  : 1;
            __IOM uint32_t UP   : 1;
            uint32_t            : 6;
            __IOM uint32_t PFCE : 1;
            uint32_t            : 23;
        } MACRFCR_b;
    };
    union
    {
        __IOM uint32_t MACRC4;
        struct
        {
            __IOM uint32_t UFFQE : 1;
            __IOM uint32_t UFFQ  : 2;
            uint32_t             : 5;
            __IOM uint32_t MFFQE : 1;
            __IOM uint32_t MFFQ  : 2;
            uint32_t             : 5;
            __IOM uint32_t VFFQE : 1;
            __IOM uint32_t VFFQ  : 2;
            uint32_t             : 13;
        } MACRC4_b;
    };
    __IM uint8_t RESERVED3[8];
    union
    {
        __IOM uint32_t MACRC0;
        struct
        {
            __IOM uint32_t RXQ0EN : 2;
            __IOM uint32_t RXQ1EN : 2;
            __IOM uint32_t RXQ2EN : 2;
            __IOM uint32_t RXQ3EN : 2;
            uint32_t              : 24;
        } MACRC0_b;
    };
    union
    {
        __IOM uint32_t MACRC1;
        struct
        {
            __IOM uint32_t AVCPQ   : 3;
            uint32_t               : 1;
            __IOM uint32_t PTPQ    : 3;
            uint32_t               : 5;
            __IOM uint32_t UPQ     : 3;
            uint32_t               : 1;
            __IOM uint32_t MCBCQ   : 3;
            uint32_t               : 1;
            __IOM uint32_t MCBCQEN : 1;
            __IOM uint32_t TACPQE  : 1;
            __IOM uint32_t TPQC    : 2;
            __IOM uint32_t FPRQ    : 3;
            uint32_t               : 1;
            __IOM uint32_t OMCBCQ  : 1;
            __IOM uint32_t TBRQE   : 1;
            uint32_t               : 2;
        } MACRC1_b;
    };
    union
    {
        __IOM uint32_t MACRC2;
        struct
        {
            __IOM uint32_t PSRQ0 : 8;
            __IOM uint32_t PSRQ1 : 8;
            __IOM uint32_t PSRQ2 : 8;
            __IOM uint32_t PSRQ3 : 8;
        } MACRC2_b;
    };
    __IM uint8_t RESERVED4[4];
    union
    {
        __IM uint32_t MACISR;
        struct
        {
            __IM uint32_t RGSMIIIS  : 1;
            uint32_t                : 2;
            __IM uint32_t PHYIS     : 1;
            __IM uint32_t PMTIS     : 1;
            __IM uint32_t LPIIS     : 1;
            uint32_t                : 2;
            __IM uint32_t MMCIS     : 1;
            __IM uint32_t MMCRXIS   : 1;
            __IM uint32_t MMCTXIS   : 1;
            __IM uint32_t MMCRXIPIS : 1;
            __IM uint32_t TSIS      : 1;
            __IM uint32_t TXSTSIS   : 1;
            __IM uint32_t RXSTSIS   : 1;
            __IM uint32_t GPIIS     : 1;
            uint32_t                : 1;
            __IM uint32_t FPEIS     : 1;
            __IM uint32_t MDIOIS    : 1;
            __IM uint32_t MFTIS     : 1;
            __IM uint32_t MFRIS     : 1;
            uint32_t                : 11;
        } MACISR_b;
    };
    union
    {
        __IOM uint32_t MACIER;
        struct
        {
            __IOM uint32_t RGSMIIIE : 1;
            uint32_t                : 2;
            __IOM uint32_t PHYIE    : 1;
            __IOM uint32_t PMTIE    : 1;
            __IOM uint32_t LPIIE    : 1;
            uint32_t                : 6;
            __IOM uint32_t TSIE     : 1;
            __IOM uint32_t TXSTSIE  : 1;
            __IOM uint32_t RXSTSIE  : 1;
            uint32_t                : 2;
            __IOM uint32_t FPEIE    : 1;
            __IOM uint32_t MDIOIE   : 1;
            uint32_t                : 13;
        } MACIER_b;
    };
    union
    {
        __IOM uint32_t MACRTSR;
        struct
        {
            __IOM uint32_t TJT   : 1;
            __IOM uint32_t NCARR : 1;
            __IOM uint32_t LCARR : 1;
            __IOM uint32_t EXDEF : 1;
            __IOM uint32_t LCOL  : 1;
            __IOM uint32_t EXCOL : 1;
            uint32_t             : 2;
            __IOM uint32_t RWT   : 1;
            uint32_t             : 23;
        } MACRTSR_b;
    };
    __IM uint8_t RESERVED5[4];
    union
    {
        __IOM uint32_t MACPCSR;
        struct
        {
            __IOM uint32_t PWRDWN     : 1;
            __IOM uint32_t MGKPKTEN   : 1;
            __IOM uint32_t RWKPKTEN   : 1;
            uint32_t                  : 2;
            __IOM uint32_t MGKPRCVD   : 1;
            __IOM uint32_t RWKPRCVD   : 1;
            uint32_t                  : 2;
            __IOM uint32_t GLBLUCAST  : 1;
            __IOM uint32_t RWKPFE     : 1;
            uint32_t                  : 13;
            __IM uint32_t RWKPTR      : 5;
            uint32_t                  : 2;
            __IOM uint32_t RWKFILTRST : 1;
        } MACPCSR_b;
    };
    union
    {
        union
        {
            __IOM uint32_t RFBMRi;
            struct
            {
                __IOM uint32_t Filter0_Byte_Mask : 32;
            } RFBMRi_b;
        };
        union
        {
            __IOM uint32_t RFCRCi;
            struct
            {
                __IOM uint32_t Filter0_CRC : 16;
                __IOM uint32_t Filter1_CRC : 16;
            } RFCRCi_b;
        };
        union
        {
            __IOM uint32_t RFORi;
            struct
            {
                __IOM uint32_t Filter0_Offset : 8;
                __IOM uint32_t Filter1_Offset : 8;
                __IOM uint32_t Filter2_Offset : 8;
                __IOM uint32_t Filter3_Offset : 8;
            } RFORi_b;
        };
        union
        {
            __IOM uint32_t RFCRi;
            struct
            {
                __IOM uint32_t Filter0_Command : 4;
                uint32_t                       : 4;
                __IOM uint32_t Filter1_Command : 4;
                uint32_t                       : 4;
                __IOM uint32_t Filter2_Command : 4;
                uint32_t                       : 4;
                __IOM uint32_t Filter3_Command : 4;
                uint32_t                       : 4;
            } RFCRi_b;
        };
        union
        {
            __IOM uint32_t MACRPFR;
            struct
            {
                __IOM uint32_t WKUPFRMFTR : 32;
            } MACRPFR_b;
        };
    };
    __IM uint8_t RESERVED6[8];
    union
    {
        __IOM uint32_t MACLCSR;
        struct
        {
            __IOM uint32_t TLPIEN  : 1;
            __IOM uint32_t TLPIEX  : 1;
            __IOM uint32_t RLPIEN  : 1;
            __IOM uint32_t RLPIEX  : 1;
            uint32_t               : 4;
            __IOM uint32_t TLPIST  : 1;
            __IOM uint32_t RLPIST  : 1;
            uint32_t               : 6;
            __IOM uint32_t LPIEN   : 1;
            __IOM uint32_t PLS     : 1;
            __IOM uint32_t PLSEN   : 1;
            __IOM uint32_t LPITXA  : 1;
            __IOM uint32_t LPIATE  : 1;
            __IOM uint32_t LPITCSE : 1;
            uint32_t               : 10;
        } MACLCSR_b;
    };
    union
    {
        __IOM uint32_t MACLTCR;
        struct
        {
            __IOM uint32_t TWT : 16;
            __IOM uint32_t LST : 10;
            uint32_t           : 6;
        } MACLTCR_b;
    };
    union
    {
        __IOM uint32_t MACLETR;
        struct
        {
            uint32_t             : 3;
            __IOM uint32_t LPIET : 17;
            uint32_t             : 12;
        } MACLETR_b;
    };
    union
    {
        __IOM uint32_t MAC1TCR;
        struct
        {
            __IOM uint32_t TIC_1US_CNTR : 12;
            uint32_t                    : 20;
        } MAC1TCR_b;
    };
    __IM uint8_t RESERVED7[24];
    union
    {
        __IOM uint32_t MACPHYCSR;
        struct
        {
            __IOM uint32_t TC        : 1;
            __IOM uint32_t LUD       : 1;
            __IOM uint32_t SFTERR    : 1;
            uint32_t                 : 1;
            __IOM uint32_t SMIDRXS   : 1;
            uint32_t                 : 11;
            __IM uint32_t LNKMOD     : 1;
            __IM uint32_t LNKSPEED   : 2;
            __IM uint32_t LNKSTS     : 1;
            __IM uint32_t JABTO      : 1;
            __IM uint32_t FALSCARDET : 1;
            uint32_t                 : 10;
        } MACPHYCSR_b;
    };
    __IM uint8_t RESERVED8[20];
    union
    {
        __IM uint32_t MACVR;
        struct
        {
            __IM uint32_t SNPSVER : 8;
            __IM uint32_t USERVER : 8;
            uint32_t              : 16;
        } MACVR_b;
    };
    union
    {
        __IM uint32_t MACDR;
        struct
        {
            __IM uint32_t RPESTS   : 1;
            __IM uint32_t RFCFCSTS : 2;
            uint32_t               : 13;
            __IM uint32_t TPESTS   : 1;
            __IM uint32_t TFCSTS   : 2;
            uint32_t               : 13;
        } MACDR_b;
    };
    __IM uint8_t RESERVED9[4];
    union
    {
        __IM uint32_t MACHF0;
        struct
        {
            __IM uint32_t MIISEL       : 1;
            __IM uint32_t GMIISEL      : 1;
            __IM uint32_t HDSEL        : 1;
            __IM uint32_t PCSSEL       : 1;
            __IM uint32_t VLHASH       : 1;
            __IM uint32_t SMASEL       : 1;
            __IM uint32_t RWKSEL       : 1;
            __IM uint32_t MGKSEL       : 1;
            __IM uint32_t MMCSEL       : 1;
            __IM uint32_t ARPOFFSEL    : 1;
            uint32_t                   : 2;
            __IM uint32_t TSSEL        : 1;
            __IM uint32_t EEESEL       : 1;
            __IM uint32_t TXCOESEL     : 1;
            uint32_t                   : 1;
            __IM uint32_t RXCOESEL     : 1;
            uint32_t                   : 1;
            __IM uint32_t ADDMACADRSEL : 5;
            __IM uint32_t MACADR32SEL  : 1;
            __IM uint32_t MACADR64SEL  : 1;
            __IM uint32_t TSSTSSEL     : 2;
            __IM uint32_t SAVLANINS    : 1;
            __IM uint32_t ACTPHYSEL    : 3;
            uint32_t                   : 1;
        } MACHF0_b;
    };
    union
    {
        __IM uint32_t MACHF1;
        struct
        {
            __IM uint32_t RXFIFOSIZE : 5;
            __IM uint32_t SPRAM      : 1;
            __IM uint32_t TXFIFOSIZE : 5;
            __IM uint32_t OSTEN      : 1;
            __IM uint32_t PTOEN      : 1;
            __IM uint32_t ADVTHWORD  : 1;
            __IM uint32_t ADDR64     : 2;
            __IM uint32_t DCBEN      : 1;
            __IM uint32_t SPHEN      : 1;
            __IM uint32_t TSOEN      : 1;
            __IM uint32_t DBGMEMA    : 1;
            __IM uint32_t AVSEL      : 1;
            __IM uint32_t RAVSEL     : 1;
            uint32_t                 : 1;
            __IM uint32_t POUOST     : 1;
            __IM uint32_t HASHTBLSZ  : 2;
            uint32_t                 : 1;
            __IM uint32_t L3L4FNUM   : 4;
            uint32_t                 : 1;
        } MACHF1_b;
    };
    union
    {
        __IM uint32_t MACHF2;
        struct
        {
            __IM uint32_t RXQCNT     : 4;
            uint32_t                 : 2;
            __IM uint32_t TXQCNT     : 4;
            uint32_t                 : 2;
            __IM uint32_t RXCHCNT    : 4;
            __IM uint32_t RDCSZ      : 2;
            __IM uint32_t TXCHCNT    : 4;
            __IM uint32_t TDCSZ      : 2;
            __IM uint32_t PPSOUTNUM  : 3;
            uint32_t                 : 1;
            __IM uint32_t AUXSNAPNUM : 3;
            uint32_t                 : 1;
        } MACHF2_b;
    };
    union
    {
        __IM uint32_t MACHF3;
        struct
        {
            __IM uint32_t NRVF    : 3;
            uint32_t              : 1;
            __IM uint32_t CBTISEL : 1;
            __IM uint32_t DVLAN   : 1;
            uint32_t              : 3;
            __IM uint32_t PDUPSEL : 1;
            __IM uint32_t FRPSEL  : 1;
            __IM uint32_t FRPBS   : 2;
            __IM uint32_t FRPES   : 2;
            uint32_t              : 1;
            __IM uint32_t ESTSEL  : 1;
            __IM uint32_t ESTDEP  : 3;
            __IM uint32_t ESTWID  : 2;
            uint32_t              : 4;
            __IM uint32_t FPESEL  : 1;
            __IM uint32_t TBSSEL  : 1;
            __IM uint32_t ASP     : 2;
            uint32_t              : 2;
        } MACHF3_b;
    };
    __IM uint8_t RESERVED10[212];
    union
    {
        __IOM uint32_t MACMAR;
        struct
        {
            __IOM uint32_t GB    : 1;
            __IOM uint32_t C45E  : 1;
            __IOM uint32_t GOC_0 : 1;
            __IOM uint32_t GOC_1 : 1;
            __IOM uint32_t SKAP  : 1;
            uint32_t             : 3;
            __IOM uint32_t CR    : 4;
            __IOM uint32_t NTC   : 3;
            uint32_t             : 1;
            __IOM uint32_t RDA   : 5;
            __IOM uint32_t PA    : 5;
            __IOM uint32_t BTB   : 1;
            __IOM uint32_t PSE   : 1;
            uint32_t             : 4;
        } MACMAR_b;
    };
    union
    {
        __IOM uint32_t MACMDR;
        struct
        {
            __IOM uint32_t GD : 16;
            __IOM uint32_t RA : 16;
        } MACMDR_b;
    };
    __IM uint8_t RESERVED11[8];
    union
    {
        __IOM uint32_t MACAAR;
        struct
        {
            __IOM uint32_t ARPPA : 32;
        } MACAAR_b;
    };
    __IM uint8_t RESERVED12[28];
    union
    {
        __IOM uint32_t MACCSCR;
        struct
        {
            __IOM uint32_t RCWE : 1;
            uint32_t            : 7;
            __IOM uint32_t SEEN : 1;
            uint32_t            : 23;
        } MACCSCR_b;
    };
    __IM uint8_t RESERVED13[12];
    union
    {
        __IM uint32_t MACPTNR;
        struct
        {
            __IM uint32_t MPTN : 32;
        } MACPTNR_b;
    };
    union
    {
        __IOM uint32_t MACPTUR;
        struct
        {
            __IOM uint32_t MPTU : 32;
        } MACPTUR_b;
    };
    __IM uint8_t             RESERVED14[184];
    R_GBETH_MAC_ADDRESS_Type MAC_ADDRESS[32];
    __IM uint8_t             RESERVED15[768];
    union
    {
        __IOM uint32_t MMCCR;
        struct
        {
            __IOM uint32_t CNTRST     : 1;
            __IOM uint32_t CNTSTOPRO  : 1;
            __IOM uint32_t RSTONRD    : 1;
            __IOM uint32_t CNTFREEZ   : 1;
            __IOM uint32_t CNTPRST    : 1;
            __IOM uint32_t CNTPRSTLVL : 1;
            uint32_t                  : 2;
            __IOM uint32_t UCDBC      : 1;
            uint32_t                  : 23;
        } MMCCR_b;
    };
    union
    {
        __IM uint32_t MMCRIR;
        struct
        {
            __IM uint32_t RXGBPKTIS          : 1;
            __IM uint32_t RXGBOCTIS          : 1;
            __IM uint32_t RXGOCTIS           : 1;
            __IM uint32_t RXBCGPIS           : 1;
            __IM uint32_t RXMCGPIS           : 1;
            __IM uint32_t RXCRCERPIS         : 1;
            __IM uint32_t RXALGNERPIS        : 1;
            __IM uint32_t RXRUNTPIS          : 1;
            __IM uint32_t RXJABERPIS         : 1;
            __IM uint32_t RXUSIZEGPIS        : 1;
            __IM uint32_t RXOSIZEGPIS        : 1;
            __IM uint32_t RX64OCTGBPIS       : 1;
            __IM uint32_t RX65T127OCTGBPIS   : 1;
            __IM uint32_t RX128T255OCTGBPIS  : 1;
            __IM uint32_t RX256T511OCTGBPIS  : 1;
            __IM uint32_t RX512T1023OCTGBPIS : 1;
            __IM uint32_t RX1024TMAXOCTGBPIS : 1;
            __IM uint32_t RXUCGPIS           : 1;
            __IM uint32_t RXLENERPIS         : 1;
            __IM uint32_t RXORANGEPIS        : 1;
            __IM uint32_t RXPAUSPIS          : 1;
            __IM uint32_t RXFOVPIS           : 1;
            __IM uint32_t RXVLANGBPIS        : 1;
            __IM uint32_t RXWDOGPIS          : 1;
            __IM uint32_t RXRCVERRPIS        : 1;
            __IM uint32_t RXCTRLPIS          : 1;
            __IM uint32_t RXLPIUSCIS         : 1;
            __IM uint32_t RXLPITRCIS         : 1;
            uint32_t                         : 4;
        } MMCRIR_b;
    };
    union
    {
        __IM uint32_t MMCTIR;
        struct
        {
            __IM uint32_t TXGBOCTIS          : 1;
            __IM uint32_t TXGBPKTIS          : 1;
            __IM uint32_t TXBCGPIS           : 1;
            __IM uint32_t TXMCGPIS           : 1;
            __IM uint32_t TX64OCTGBPIS       : 1;
            __IM uint32_t TX65T127OCTGBPIS   : 1;
            __IM uint32_t TX128T255OCTGBPIS  : 1;
            __IM uint32_t TX256T511OCTGBPIS  : 1;
            __IM uint32_t TX512T1023OCTGBPIS : 1;
            __IM uint32_t TX1024TMAXOCTGBPIS : 1;
            __IM uint32_t TXUCGBPIS          : 1;
            __IM uint32_t TXMCGBPIS          : 1;
            __IM uint32_t TXBCGBPIS          : 1;
            __IM uint32_t TXUFLOWERPIS       : 1;
            __IM uint32_t TXSCOLGPIS         : 1;
            __IM uint32_t TXMCOLGPIS         : 1;
            __IM uint32_t TXDEFPIS           : 1;
            __IM uint32_t TXLATCOLPIS        : 1;
            __IM uint32_t TXEXCOLPIS         : 1;
            __IM uint32_t TXCARERPIS         : 1;
            __IM uint32_t TXGOCTIS           : 1;
            __IM uint32_t TXGPKTIS           : 1;
            __IM uint32_t TXEXDEFPIS         : 1;
            __IM uint32_t TXPAUSPIS          : 1;
            __IM uint32_t TXVLANGPIS         : 1;
            __IM uint32_t TXOSIZEGPIS        : 1;
            __IM uint32_t TXLPIUSCIS         : 1;
            __IM uint32_t TXLPITRCIS         : 1;
            uint32_t                         : 4;
        } MMCTIR_b;
    };
    union
    {
        __IOM uint32_t MMCRIMR;
        struct
        {
            __IOM uint32_t RXGBPKTIM          : 1;
            __IOM uint32_t RXGBOCTIM          : 1;
            __IOM uint32_t RXGOCTIM           : 1;
            __IOM uint32_t RXBCGPIM           : 1;
            __IOM uint32_t RXMCGPIM           : 1;
            __IOM uint32_t RXCRCERPIM         : 1;
            __IOM uint32_t RXALGNERPIM        : 1;
            __IOM uint32_t RXRUNTPIM          : 1;
            __IOM uint32_t RXJABERPIM         : 1;
            __IOM uint32_t RXUSIZEGPIM        : 1;
            __IOM uint32_t RXOSIZEGPIM        : 1;
            __IOM uint32_t RX64OCTGBPIM       : 1;
            __IOM uint32_t RX65T127OCTGBPIM   : 1;
            __IOM uint32_t RX128T255OCTGBPIM  : 1;
            __IOM uint32_t RX256T511OCTGBPIM  : 1;
            __IOM uint32_t RX512T1023OCTGBPIM : 1;
            __IOM uint32_t RX1024TMAXOCTGBPIM : 1;
            __IOM uint32_t RXUCGPIM           : 1;
            __IOM uint32_t RXLENERPIM         : 1;
            __IOM uint32_t RXORANGEPIM        : 1;
            __IOM uint32_t RXPAUSPIM          : 1;
            __IOM uint32_t RXFOVPIM           : 1;
            __IOM uint32_t RXVLANGBPIM        : 1;
            __IOM uint32_t RXWDOGPIM          : 1;
            __IOM uint32_t RXRCVERRPIM        : 1;
            __IOM uint32_t RXCTRLPIM          : 1;
            __IOM uint32_t RXLPIUSCIM         : 1;
            __IOM uint32_t RXLPITRCIM         : 1;
            uint32_t                          : 4;
        } MMCRIMR_b;
    };
    union
    {
        __IOM uint32_t MMCTIMR;
        struct
        {
            __IOM uint32_t TXGBOCTIM          : 1;
            __IOM uint32_t TXGBPKTIM          : 1;
            __IOM uint32_t TXBCGPIM           : 1;
            __IOM uint32_t TXMCGPIM           : 1;
            __IOM uint32_t TX64OCTGBPIM       : 1;
            __IOM uint32_t TX65T127OCTGBPIM   : 1;
            __IOM uint32_t TX128T255OCTGBPIM  : 1;
            __IOM uint32_t TX256T511OCTGBPIM  : 1;
            __IOM uint32_t TX512T1023OCTGBPIM : 1;
            __IOM uint32_t TX1024TMAXOCTGBPIM : 1;
            __IOM uint32_t TXUCGBPIM          : 1;
            __IOM uint32_t TXMCGBPIM          : 1;
            __IOM uint32_t TXBCGBPIM          : 1;
            __IOM uint32_t TXUFLOWERPIM       : 1;
            __IOM uint32_t TXSCOLGPIM         : 1;
            __IOM uint32_t TXMCOLGPIM         : 1;
            __IOM uint32_t TXDEFPIM           : 1;
            __IOM uint32_t TXLATCOLPIM        : 1;
            __IOM uint32_t TXEXCOLPIM         : 1;
            __IOM uint32_t TXCARERPIM         : 1;
            __IOM uint32_t TXGOCTIM           : 1;
            __IOM uint32_t TXGPKTIM           : 1;
            __IOM uint32_t TXEXDEFPIM         : 1;
            __IOM uint32_t TXPAUSPIM          : 1;
            __IOM uint32_t TXVLANGPIM         : 1;
            __IOM uint32_t TXOSIZEGPIM        : 1;
            __IOM uint32_t TXLPIUSCIM         : 1;
            __IOM uint32_t TXLPITRCIM         : 1;
            uint32_t                          : 4;
        } MMCTIMR_b;
    };
    union
    {
        __IM uint32_t TOCGBR;
        struct
        {
            __IM uint32_t TXOCTGB : 32;
        } TOCGBR_b;
    };
    union
    {
        __IM uint32_t TPCGBR;
        struct
        {
            __IM uint32_t TXPKTGB : 32;
        } TPCGBR_b;
    };
    union
    {
        __IM uint32_t TBPGR;
        struct
        {
            __IM uint32_t TXBCASTG : 32;
        } TBPGR_b;
    };
    union
    {
        __IM uint32_t TMPGR;
        struct
        {
            __IM uint32_t TXMCASTG : 32;
        } TMPGR_b;
    };
    union
    {
        __IM uint32_t T64PGBR;
        struct
        {
            __IM uint32_t TX64OCTGB : 32;
        } T64PGBR_b;
    };
    union
    {
        __IM uint32_t T65PGBR;
        struct
        {
            __IM uint32_t TX65_127OCTGB : 32;
        } T65PGBR_b;
    };
    union
    {
        __IM uint32_t T128PGBR;
        struct
        {
            __IM uint32_t TX128_255OCTGB : 32;
        } T128PGBR_b;
    };
    union
    {
        __IM uint32_t T256PGBR;
        struct
        {
            __IM uint32_t TX256_511OCTGB : 32;
        } T256PGBR_b;
    };
    union
    {
        __IM uint32_t T512PGBR;
        struct
        {
            __IM uint32_t TX512_1023OCTGB : 32;
        } T512PGBR_b;
    };
    union
    {
        __IM uint32_t T1024PGBR;
        struct
        {
            __IM uint32_t TX1024_MAXOCTGB : 32;
        } T1024PGBR_b;
    };
    union
    {
        __IM uint32_t TUPGBR;
        struct
        {
            __IM uint32_t TXUCASTGB : 32;
        } TUPGBR_b;
    };
    union
    {
        __IM uint32_t TMPGBR;
        struct
        {
            __IM uint32_t TXMCASTGB : 32;
        } TMPGBR_b;
    };
    union
    {
        __IM uint32_t TBPGBR;
        struct
        {
            __IM uint32_t TXBCASTGB : 32;
        } TBPGBR_b;
    };
    union
    {
        __IM uint32_t TUEPR;
        struct
        {
            __IM uint32_t TXUNDRFLW : 32;
        } TUEPR_b;
    };
    union
    {
        __IM uint32_t TSCGPR;
        struct
        {
            __IM uint32_t TXSNGLCOLG : 32;
        } TSCGPR_b;
    };
    union
    {
        __IM uint32_t TMCGPR;
        struct
        {
            __IM uint32_t TXMULTCOLG : 32;
        } TMCGPR_b;
    };
    union
    {
        __IM uint32_t TDPR;
        struct
        {
            __IM uint32_t TXDEFRD : 32;
        } TDPR_b;
    };
    union
    {
        __IM uint32_t TLCPR;
        struct
        {
            __IM uint32_t TXLATECOL : 32;
        } TLCPR_b;
    };
    union
    {
        __IM uint32_t TECPR;
        struct
        {
            __IM uint32_t TXEXSCOL : 32;
        } TECPR_b;
    };
    union
    {
        __IM uint32_t TCEPR;
        struct
        {
            __IM uint32_t TXCARR : 32;
        } TCEPR_b;
    };
    union
    {
        __IM uint32_t TOCGR;
        struct
        {
            __IM uint32_t TXOCTG : 32;
        } TOCGR_b;
    };
    union
    {
        __IM uint32_t TPCGR;
        struct
        {
            __IM uint32_t TXPKTG : 32;
        } TPCGR_b;
    };
    union
    {
        __IM uint32_t TEDER;
        struct
        {
            __IM uint32_t TXEXSDEF : 32;
        } TEDER_b;
    };
    union
    {
        __IM uint32_t TPPR;
        struct
        {
            __IM uint32_t TXPAUSE : 32;
        } TPPR_b;
    };
    union
    {
        __IM uint32_t TVPGR;
        struct
        {
            __IM uint32_t TXVLANG : 32;
        } TVPGR_b;
    };
    union
    {
        __IM uint32_t TOPGR;
        struct
        {
            __IM uint32_t TXOSIZG : 32;
        } TOPGR_b;
    };
    __IM uint8_t RESERVED16[4];
    union
    {
        __IM uint32_t RPCGBR;
        struct
        {
            __IM uint32_t RXPKTGB : 32;
        } RPCGBR_b;
    };
    union
    {
        __IM uint32_t ROCGBR;
        struct
        {
            __IM uint32_t RXOCTGB : 32;
        } ROCGBR_b;
    };
    union
    {
        __IM uint32_t ROCGR;
        struct
        {
            __IM uint32_t RXOCTG : 32;
        } ROCGR_b;
    };
    union
    {
        __IM uint32_t RBPGR;
        struct
        {
            __IM uint32_t RXBCASTG : 32;
        } RBPGR_b;
    };
    union
    {
        __IM uint32_t RMPGR;
        struct
        {
            __IM uint32_t RXMCASTG : 32;
        } RMPGR_b;
    };
    union
    {
        __IM uint32_t RCEPR;
        struct
        {
            __IM uint32_t RXCRCERR : 32;
        } RCEPR_b;
    };
    union
    {
        __IM uint32_t RAEPR;
        struct
        {
            __IM uint32_t RXALGNERR : 32;
        } RAEPR_b;
    };
    union
    {
        __IM uint32_t RERRP;
        struct
        {
            __IM uint32_t RXRUNTERR : 32;
        } RERRP_b;
    };
    union
    {
        __IM uint32_t RJEPR;
        struct
        {
            __IM uint32_t RXJABERR : 32;
        } RJEPR_b;
    };
    union
    {
        __IM uint32_t RUSPGD;
        struct
        {
            __IM uint32_t RXUNDERSZG : 32;
        } RUSPGD_b;
    };
    union
    {
        __IM uint32_t ROPGR;
        struct
        {
            __IM uint32_t RXOVERSZG : 32;
        } ROPGR_b;
    };
    union
    {
        __IM uint32_t R64PGBR;
        struct
        {
            __IM uint32_t RX64OCTGB : 32;
        } R64PGBR_b;
    };
    union
    {
        __IM uint32_t R65PGBR;
        struct
        {
            __IM uint32_t RX65_127OCTGB : 32;
        } R65PGBR_b;
    };
    union
    {
        __IM uint32_t R128PGBR;
        struct
        {
            __IM uint32_t RX128_255OCTGB : 32;
        } R128PGBR_b;
    };
    union
    {
        __IM uint32_t R256PGBR;
        struct
        {
            __IM uint32_t RX256_511OCTGB : 32;
        } R256PGBR_b;
    };
    union
    {
        __IM uint32_t R512PGBR;
        struct
        {
            __IM uint32_t RX512_1023OCTGB : 32;
        } R512PGBR_b;
    };
    union
    {
        __IM uint32_t R1024PGBR;
        struct
        {
            __IM uint32_t RX1024_MAXOCTGB : 32;
        } R1024PGBR_b;
    };
    union
    {
        __IM uint32_t RUCPGD;
        struct
        {
            __IM uint32_t RXUCASTG : 32;
        } RUCPGD_b;
    };
    union
    {
        __IM uint32_t RLEPR;
        struct
        {
            __IM uint32_t RXLENERR : 32;
        } RLEPR_b;
    };
    union
    {
        __IM uint32_t ROORTP;
        struct
        {
            __IM uint32_t RXOUTOFRNG : 32;
        } ROORTP_b;
    };
    union
    {
        __IM uint32_t RPPR;
        struct
        {
            __IM uint32_t RXPAUSEPKT : 32;
        } RPPR_b;
    };
    union
    {
        __IM uint32_t RFOPR;
        struct
        {
            __IM uint32_t RXFIFOOVFL : 32;
        } RFOPR_b;
    };
    union
    {
        __IM uint32_t RVPGBR;
        struct
        {
            __IM uint32_t RXVLANPKTGB : 32;
        } RVPGBR_b;
    };
    union
    {
        __IM uint32_t RWEPR;
        struct
        {
            __IM uint32_t RXWDGERR : 32;
        } RWEPR_b;
    };
    union
    {
        __IM uint32_t RREPR;
        struct
        {
            __IM uint32_t RXRCVERR : 32;
        } RREPR_b;
    };
    union
    {
        __IM uint32_t RCPGR;
        struct
        {
            __IM uint32_t RXCTRLG : 32;
        } RCPGR_b;
    };
    __IM uint8_t RESERVED17[4];
    union
    {
        __IM uint32_t TLUCR;
        struct
        {
            __IM uint32_t TXLPIUSC : 32;
        } TLUCR_b;
    };
    union
    {
        __IM uint32_t TLTCR;
        struct
        {
            __IM uint32_t TXLPITRC : 32;
        } TLTCR_b;
    };
    union
    {
        __IM uint32_t RLUCR;
        struct
        {
            __IM uint32_t RXLPIUSC : 32;
        } RLUCR_b;
    };
    union
    {
        __IM uint32_t RLTCR;
        struct
        {
            __IM uint32_t RXLPITRC : 32;
        } RLTCR_b;
    };
    __IM uint8_t RESERVED18[4];
    union
    {
        __IOM uint32_t MMCIRIMR;
        struct
        {
            __IOM uint32_t RXIPV4GPIM     : 1;
            __IOM uint32_t RXIPV4HERPIM   : 1;
            __IOM uint32_t RXIPV4NOPAYPIM : 1;
            __IOM uint32_t RXIPV4FRAGPIM  : 1;
            __IOM uint32_t RXIPV4UDSBLPIM : 1;
            __IOM uint32_t RXIPV6GPIM     : 1;
            __IOM uint32_t RXIPV6HERPIM   : 1;
            __IOM uint32_t RXIPV6NOPAYPIM : 1;
            __IOM uint32_t RXUDPGPIM      : 1;
            __IOM uint32_t RXUDPERPIM     : 1;
            __IOM uint32_t RXTCPGPIM      : 1;
            __IOM uint32_t RXTCPERPIM     : 1;
            __IOM uint32_t RXICMPGPIM     : 1;
            __IOM uint32_t RXICMPERPIM    : 1;
            uint32_t                      : 2;
            __IOM uint32_t RXIPV4GOIM     : 1;
            __IOM uint32_t RXIPV4HEROIM   : 1;
            __IOM uint32_t RXIPV4NOPAYOIM : 1;
            __IOM uint32_t RXIPV4FRAGOIM  : 1;
            __IOM uint32_t RXIPV4UDSBLOIM : 1;
            __IOM uint32_t RXIPV6GOIM     : 1;
            __IOM uint32_t RXIPV6HEROIM   : 1;
            __IOM uint32_t RXIPV6NOPAYOIM : 1;
            __IOM uint32_t RXUDPGOIM      : 1;
            __IOM uint32_t RXUDPEROIM     : 1;
            __IOM uint32_t RXTCPGOIM      : 1;
            __IOM uint32_t RXTCPEROIM     : 1;
            __IOM uint32_t RXICMPGOIM     : 1;
            __IOM uint32_t RXICMPEROIM    : 1;
            uint32_t                      : 2;
        } MMCIRIMR_b;
    };
    __IM uint8_t RESERVED19[4];
    union
    {
        __IM uint32_t MMCIRIR;
        struct
        {
            __IM uint32_t RXIPV4GPIS     : 1;
            __IM uint32_t RXIPV4HERPIS   : 1;
            __IM uint32_t RXIPV4NOPAYPIS : 1;
            __IM uint32_t RXIPV4FRAGPIS  : 1;
            __IM uint32_t RXIPV4UDSBLPIS : 1;
            __IM uint32_t RXIPV6GPIS     : 1;
            __IM uint32_t RXIPV6HERPIS   : 1;
            __IM uint32_t RXIPV6NOPAYPIS : 1;
            __IM uint32_t RXUDPGPIS      : 1;
            __IM uint32_t RXUDPERPIS     : 1;
            __IM uint32_t RXTCPGPIS      : 1;
            __IM uint32_t RXTCPERPIS     : 1;
            __IM uint32_t RXICMPGPIS     : 1;
            __IM uint32_t RXICMPERPIS    : 1;
            uint32_t                     : 2;
            __IM uint32_t RXIPV4GOIS     : 1;
            __IM uint32_t RXIPV4HEROIS   : 1;
            __IM uint32_t RXIPV4NOPAYOIS : 1;
            __IM uint32_t RXIPV4FRAGOIS  : 1;
            __IM uint32_t RXIPV4UDSBLOIS : 1;
            __IM uint32_t RXIPV6GOIS     : 1;
            __IM uint32_t RXIPV6HEROIS   : 1;
            __IM uint32_t RXIPV6NOPAYOIS : 1;
            __IM uint32_t RXUDPGOIS      : 1;
            __IM uint32_t RXUDPEROIS     : 1;
            __IM uint32_t RXTCPGOIS      : 1;
            __IM uint32_t RXTCPEROIS     : 1;
            __IM uint32_t RXICMPGOIS     : 1;
            __IM uint32_t RXICMPEROIS    : 1;
            uint32_t                     : 2;
        } MMCIRIR_b;
    };
    __IM uint8_t RESERVED20[4];
    union
    {
        __IM uint32_t RV4GPR;
        struct
        {
            __IM uint32_t RXIPV4GDPKT : 32;
        } RV4GPR_b;
    };
    union
    {
        __IM uint32_t RV4HEPR;
        struct
        {
            __IM uint32_t RXIPV4HDRERRPKT : 32;
        } RV4HEPR_b;
    };
    union
    {
        __IM uint32_t RV4NPPR;
        struct
        {
            __IM uint32_t RXIPV4NOPAYPKT : 32;
        } RV4NPPR_b;
    };
    union
    {
        __IM uint32_t RV4FPR;
        struct
        {
            __IM uint32_t RXIPV4FRAGPKT : 32;
        } RV4FPR_b;
    };
    union
    {
        __IM uint32_t RV4UCDPR;
        struct
        {
            __IM uint32_t RXIPV4UDSBLPKT : 32;
        } RV4UCDPR_b;
    };
    union
    {
        __IM uint32_t RV6GPR;
        struct
        {
            __IM uint32_t RXIPV6GDPKT : 32;
        } RV6GPR_b;
    };
    union
    {
        __IM uint32_t RV6HEPR;
        struct
        {
            __IM uint32_t RXIPV6HDRERRPKT : 32;
        } RV6HEPR_b;
    };
    union
    {
        __IM uint32_t RV6NPPR;
        struct
        {
            __IM uint32_t RXIPV6NOPAYPKT : 32;
        } RV6NPPR_b;
    };
    union
    {
        __IM uint32_t RUDPGPR;
        struct
        {
            __IM uint32_t RXUDPGDPKT : 32;
        } RUDPGPR_b;
    };
    union
    {
        __IM uint32_t RUDPEPR;
        struct
        {
            __IM uint32_t RXUDPERRPKT : 32;
        } RUDPEPR_b;
    };
    union
    {
        __IM uint32_t RTCPGPR;
        struct
        {
            __IM uint32_t RXTCPGDPKT : 32;
        } RTCPGPR_b;
    };
    union
    {
        __IM uint32_t RTCPEPR;
        struct
        {
            __IM uint32_t RXTCPERRPKT : 32;
        } RTCPEPR_b;
    };
    union
    {
        __IM uint32_t RICMPGPR;
        struct
        {
            __IM uint32_t RXICMPGDPKT : 32;
        } RICMPGPR_b;
    };
    union
    {
        __IM uint32_t RICMPEPR;
        struct
        {
            __IM uint32_t RXICMPERRPKT : 32;
        } RICMPEPR_b;
    };
    __IM uint8_t RESERVED21[8];
    union
    {
        __IM uint32_t RV4GOR;
        struct
        {
            __IM uint32_t RXIPV4GDOCT : 32;
        } RV4GOR_b;
    };
    union
    {
        __IM uint32_t RV4HEOR;
        struct
        {
            __IM uint32_t RXIPV4HDRERROCT : 32;
        } RV4HEOR_b;
    };
    union
    {
        __IM uint32_t RV4NPOR;
        struct
        {
            __IM uint32_t RXIPV4NOPAYOCT : 32;
        } RV4NPOR_b;
    };
    union
    {
        __IM uint32_t RV4FOR;
        struct
        {
            __IM uint32_t RXIPV4FRAGOCT : 32;
        } RV4FOR_b;
    };
    union
    {
        __IM uint32_t RV4UCDOR;
        struct
        {
            __IM uint32_t RXIPV4UDSBLOCT : 32;
        } RV4UCDOR_b;
    };
    union
    {
        __IM uint32_t RV6GOR;
        struct
        {
            __IM uint32_t RXIPV6GDOCT : 32;
        } RV6GOR_b;
    };
    union
    {
        __IM uint32_t RV6HEOR;
        struct
        {
            __IM uint32_t RXIPV6HDRERROCT : 32;
        } RV6HEOR_b;
    };
    union
    {
        __IM uint32_t RV6NPOR;
        struct
        {
            __IM uint32_t RXIPV6NOPAYOCT : 32;
        } RV6NPOR_b;
    };
    union
    {
        __IM uint32_t RUDPGOR;
        struct
        {
            __IM uint32_t RXUDPGDOCT : 32;
        } RUDPGOR_b;
    };
    union
    {
        __IM uint32_t RUDPEOR;
        struct
        {
            __IM uint32_t RXUDPERROCT : 32;
        } RUDPEOR_b;
    };
    union
    {
        __IM uint32_t RTCPGOR;
        struct
        {
            __IM uint32_t RXTCPGDOCT : 32;
        } RTCPGOR_b;
    };
    union
    {
        __IM uint32_t RTCPEOR;
        struct
        {
            __IM uint32_t RXTCPERROCT : 32;
        } RTCPEOR_b;
    };
    union
    {
        __IM uint32_t RICMPGOR;
        struct
        {
            __IM uint32_t RXICMPGDOCT : 32;
        } RICMPGOR_b;
    };
    union
    {
        __IM uint32_t RICMPEOR;
        struct
        {
            __IM uint32_t RXICMPERROCT : 32;
        } RICMPEOR_b;
    };
    __IM uint8_t RESERVED22[120];
    union
    {
        __IOM uint32_t MACLCR0;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLCR0_b;
    };
    union
    {
        __IOM uint32_t MACLAR0;
        struct
        {
            __IOM uint32_t L4SP0 : 16;
            __IOM uint32_t L4DP0 : 16;
        } MACLAR0_b;
    };
    __IM uint8_t RESERVED23[8];
    union
    {
        __IOM uint32_t MACLARR00;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLARR00_b;
    };
    union
    {
        __IOM uint32_t MACLARR10;
        struct
        {
            __IOM uint32_t L3A10 : 32;
        } MACLARR10_b;
    };
    union
    {
        __IOM uint32_t MACLARR20;
        struct
        {
            __IOM uint32_t L3A20 : 32;
        } MACLARR20_b;
    };
    union
    {
        __IOM uint32_t MACLARR30;
        struct
        {
            __IOM uint32_t L3A30 : 32;
        } MACLARR30_b;
    };
    __IM uint8_t RESERVED24[16];
    union
    {
        __IOM uint32_t MACLCR1;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLCR1_b;
    };
    union
    {
        __IOM uint32_t MACLAR1;
        struct
        {
            __IOM uint32_t L4SP0 : 16;
            __IOM uint32_t L4DP0 : 16;
        } MACLAR1_b;
    };
    __IM uint8_t RESERVED25[8];
    union
    {
        __IOM uint32_t MACLARR01;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLARR01_b;
    };
    union
    {
        __IOM uint32_t MACLARR11;
        struct
        {
            __IOM uint32_t L3A10 : 32;
        } MACLARR11_b;
    };
    union
    {
        __IOM uint32_t MACLARR21;
        struct
        {
            __IOM uint32_t L3A20 : 32;
        } MACLARR21_b;
    };
    union
    {
        __IOM uint32_t MACLARR31;
        struct
        {
            __IOM uint32_t L3A30 : 32;
        } MACLARR31_b;
    };
    __IM uint8_t RESERVED26[16];
    union
    {
        __IOM uint32_t MACLCR2;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLCR2_b;
    };
    union
    {
        __IOM uint32_t MACLAR2;
        struct
        {
            __IOM uint32_t L4SP0 : 16;
            __IOM uint32_t L4DP0 : 16;
        } MACLAR2_b;
    };
    __IM uint8_t RESERVED27[8];
    union
    {
        __IOM uint32_t MACLARR02;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLARR02_b;
    };
    union
    {
        __IOM uint32_t MACLARR12;
        struct
        {
            __IOM uint32_t L3A10 : 32;
        } MACLARR12_b;
    };
    union
    {
        __IOM uint32_t MACLARR22;
        struct
        {
            __IOM uint32_t L3A20 : 32;
        } MACLARR22_b;
    };
    union
    {
        __IOM uint32_t MACLARR32;
        struct
        {
            __IOM uint32_t L3A30 : 32;
        } MACLARR32_b;
    };
    __IM uint8_t RESERVED28[16];
    union
    {
        __IOM uint32_t MACLCR3;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLCR3_b;
    };
    union
    {
        __IOM uint32_t MACLAR3;
        struct
        {
            __IOM uint32_t L4SP0 : 16;
            __IOM uint32_t L4DP0 : 16;
        } MACLAR3_b;
    };
    __IM uint8_t RESERVED29[8];
    union
    {
        __IOM uint32_t MACLARR03;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLARR03_b;
    };
    union
    {
        __IOM uint32_t MACLARR13;
        struct
        {
            __IOM uint32_t L3A10 : 32;
        } MACLARR13_b;
    };
    union
    {
        __IOM uint32_t MACLARR23;
        struct
        {
            __IOM uint32_t L3A20 : 32;
        } MACLARR23_b;
    };
    union
    {
        __IOM uint32_t MACLARR33;
        struct
        {
            __IOM uint32_t L3A30 : 32;
        } MACLARR33_b;
    };
    __IM uint8_t RESERVED30[16];
    union
    {
        __IOM uint32_t MACLCR4;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLCR4_b;
    };
    union
    {
        __IOM uint32_t MACLAR4;
        struct
        {
            __IOM uint32_t L4SP0 : 16;
            __IOM uint32_t L4DP0 : 16;
        } MACLAR4_b;
    };
    __IM uint8_t RESERVED31[8];
    union
    {
        __IOM uint32_t MACLARR04;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLARR04_b;
    };
    union
    {
        __IOM uint32_t MACLARR14;
        struct
        {
            __IOM uint32_t L3A10 : 32;
        } MACLARR14_b;
    };
    union
    {
        __IOM uint32_t MACLARR24;
        struct
        {
            __IOM uint32_t L3A20 : 32;
        } MACLARR24_b;
    };
    union
    {
        __IOM uint32_t MACLARR34;
        struct
        {
            __IOM uint32_t L3A30 : 32;
        } MACLARR34_b;
    };
    __IM uint8_t RESERVED32[16];
    union
    {
        __IOM uint32_t MACLCR5;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLCR5_b;
    };
    union
    {
        __IOM uint32_t MACLAR5;
        struct
        {
            __IOM uint32_t L4SP0 : 16;
            __IOM uint32_t L4DP0 : 16;
        } MACLAR5_b;
    };
    __IM uint8_t RESERVED33[8];
    union
    {
        __IOM uint32_t MACLARR05;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLARR05_b;
    };
    union
    {
        __IOM uint32_t MACLARR15;
        struct
        {
            __IOM uint32_t L3A10 : 32;
        } MACLARR15_b;
    };
    union
    {
        __IOM uint32_t MACLARR25;
        struct
        {
            __IOM uint32_t L3A20 : 32;
        } MACLARR25_b;
    };
    union
    {
        __IOM uint32_t MACLARR35;
        struct
        {
            __IOM uint32_t L3A30 : 32;
        } MACLARR35_b;
    };
    __IM uint8_t RESERVED34[16];
    union
    {
        __IOM uint32_t MACLCR6;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLCR6_b;
    };
    union
    {
        __IOM uint32_t MACLAR6;
        struct
        {
            __IOM uint32_t L4SP0 : 16;
            __IOM uint32_t L4DP0 : 16;
        } MACLAR6_b;
    };
    __IM uint8_t RESERVED35[8];
    union
    {
        __IOM uint32_t MACLARR06;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLARR06_b;
    };
    union
    {
        __IOM uint32_t MACLARR16;
        struct
        {
            __IOM uint32_t L3A10 : 32;
        } MACLARR16_b;
    };
    union
    {
        __IOM uint32_t MACLARR26;
        struct
        {
            __IOM uint32_t L3A20 : 32;
        } MACLARR26_b;
    };
    union
    {
        __IOM uint32_t MACLARR36;
        struct
        {
            __IOM uint32_t L3A30 : 32;
        } MACLARR36_b;
    };
    __IM uint8_t RESERVED36[16];
    union
    {
        __IOM uint32_t MACLCR7;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLCR7_b;
    };
    union
    {
        __IOM uint32_t MACLAR7;
        struct
        {
            __IOM uint32_t L4SP0 : 16;
            __IOM uint32_t L4DP0 : 16;
        } MACLAR7_b;
    };
    __IM uint8_t RESERVED37[8];
    union
    {
        __IOM uint32_t MACLARR07;
        struct
        {
            __IOM uint32_t L3PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L3SAM0  : 1;
            __IOM uint32_t L3SAIM0 : 1;
            __IOM uint32_t L3DAM0  : 1;
            __IOM uint32_t L3DAIM0 : 1;
            __IOM uint32_t L3HSBM0 : 5;
            __IOM uint32_t L3HDBM0 : 5;
            __IOM uint32_t L4PEN0  : 1;
            uint32_t               : 1;
            __IOM uint32_t L4SPM0  : 1;
            __IOM uint32_t L4SPIM0 : 1;
            __IOM uint32_t L4DPM0  : 1;
            __IOM uint32_t L4DPIM0 : 1;
            uint32_t               : 2;
            __IOM uint32_t DMCHN0  : 2;
            uint32_t               : 2;
            __IOM uint32_t DMCHEN0 : 1;
            uint32_t               : 3;
        } MACLARR07_b;
    };
    union
    {
        __IOM uint32_t MACLARR17;
        struct
        {
            __IOM uint32_t L3A10 : 32;
        } MACLARR17_b;
    };
    union
    {
        __IOM uint32_t MACLARR27;
        struct
        {
            __IOM uint32_t L3A20 : 32;
        } MACLARR27_b;
    };
    union
    {
        __IOM uint32_t MACLARR37;
        struct
        {
            __IOM uint32_t L3A30 : 32;
        } MACLARR37_b;
    };
    union
    {
        __IOM uint32_t MACIACR;
        struct
        {
            __IOM uint32_t OB   : 1;
            __IOM uint32_t COM  : 1;
            uint32_t            : 3;
            __IOM uint32_t AUTO : 1;
            uint32_t            : 2;
            __IOM uint32_t AOFF : 8;
            __IOM uint32_t MSEL : 4;
            uint32_t            : 12;
        } MACIACR_b;
    };
    union
    {
        union
        {
            __IOM uint32_t MACIADR;
            struct
            {
                __IOM uint32_t DATA : 32;
            } MACIADR_b;
        };
        union
        {
            __IOM uint32_t MACTRR0;
            struct
            {
                __IOM uint32_t TYP  : 16;
                uint32_t            : 3;
                __IOM uint32_t TMRQ : 1;
                __IOM uint32_t PFEX : 1;
                uint32_t            : 11;
            } MACTRR0_b;
        };
    };
    union
    {
        __IOM uint32_t MACTRR1;
        struct
        {
            __IOM uint32_t TYP  : 16;
            uint32_t            : 3;
            __IOM uint32_t TMRQ : 1;
            __IOM uint32_t PFEX : 1;
            uint32_t            : 11;
        } MACTRR1_b;
    };
    union
    {
        __IOM uint32_t MACTRR2;
        struct
        {
            __IOM uint32_t TYP  : 16;
            uint32_t            : 3;
            __IOM uint32_t TMRQ : 1;
            __IOM uint32_t PFEX : 1;
            uint32_t            : 11;
        } MACTRR2_b;
    };
    union
    {
        __IOM uint32_t MACTRR3;
        struct
        {
            __IOM uint32_t TYP  : 16;
            uint32_t            : 3;
            __IOM uint32_t TMRQ : 1;
            __IOM uint32_t PFEX : 1;
            uint32_t            : 11;
        } MACTRR3_b;
    };
    union
    {
        __IOM uint32_t MACTRR4;
        struct
        {
            __IOM uint32_t TYP  : 16;
            uint32_t            : 3;
            __IOM uint32_t TMRQ : 1;
            __IOM uint32_t PFEX : 1;
            uint32_t            : 11;
        } MACTRR4_b;
    };
    union
    {
        __IOM uint32_t MACTRR5;
        struct
        {
            __IOM uint32_t TYP  : 16;
            uint32_t            : 3;
            __IOM uint32_t TMRQ : 1;
            __IOM uint32_t PFEX : 1;
            uint32_t            : 11;
        } MACTRR5_b;
    };
    union
    {
        __IOM uint32_t MACTRR6;
        struct
        {
            __IOM uint32_t TYP  : 16;
            uint32_t            : 3;
            __IOM uint32_t TMRQ : 1;
            __IOM uint32_t PFEX : 1;
            uint32_t            : 11;
        } MACTRR6_b;
    };
    union
    {
        __IOM uint32_t MACTRR7;
        struct
        {
            __IOM uint32_t TYP  : 16;
            uint32_t            : 3;
            __IOM uint32_t TMRQ : 1;
            __IOM uint32_t PFEX : 1;
            uint32_t            : 11;
        } MACTRR7_b;
    };
    __IM uint8_t RESERVED38[108];
    union
    {
        __IOM uint32_t MACTCR;
        struct
        {
            __IOM uint32_t TSENA       : 1;
            __IOM uint32_t TSCFUPDT    : 1;
            __IOM uint32_t TSINIT      : 1;
            __IOM uint32_t TSUPDT      : 1;
            __IOM uint32_t TSTRIG      : 1;
            __IOM uint32_t TSADDREG    : 1;
            __IOM uint32_t PTGE        : 1;
            uint32_t                   : 1;
            __IOM uint32_t TSENALL     : 1;
            __IOM uint32_t TSCTRLSSR   : 1;
            __IOM uint32_t TSVER2ENA   : 1;
            __IOM uint32_t TSIPENA     : 1;
            __IOM uint32_t TSIPV6ENA   : 1;
            __IOM uint32_t TSIPV4ENA   : 1;
            __IOM uint32_t TSEVNTENA   : 1;
            __IOM uint32_t TSMSTRENA   : 1;
            __IOM uint32_t SNAPTYPSEL  : 2;
            __IOM uint32_t TSENMACADDR : 1;
            __IOM uint32_t CSC         : 1;
            uint32_t                   : 4;
            __IOM uint32_t TXTSSTSM    : 1;
            uint32_t                   : 3;
            __IOM uint32_t AV8021ASMEN : 1;
            uint32_t                   : 3;
        } MACTCR_b;
    };
    union
    {
        __IOM uint32_t MACSSIR;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t SNSINC : 8;
            __IOM uint32_t SSINC  : 8;
            uint32_t              : 8;
        } MACSSIR_b;
    };
    union
    {
        __IM uint32_t MACSTSR;
        struct
        {
            __IM uint32_t TSS : 32;
        } MACSTSR_b;
    };
    union
    {
        __IM uint32_t MACSTNR;
        struct
        {
            __IM uint32_t TSSS : 31;
            uint32_t           : 1;
        } MACSTNR_b;
    };
    union
    {
        __IOM uint32_t MACSTSUR;
        struct
        {
            __IOM uint32_t TSS : 32;
        } MACSTSUR_b;
    };
    union
    {
        __IOM uint32_t MACSTNUR;
        struct
        {
            __IOM uint32_t TSSS   : 31;
            __IOM uint32_t ADDSUB : 1;
        } MACSTNUR_b;
    };
    union
    {
        __IOM uint32_t MACTAR;
        struct
        {
            __IOM uint32_t TSAR : 32;
        } MACTAR_b;
    };
    union
    {
        __IOM uint32_t MACSTHWS;
        struct
        {
            __IOM uint32_t TSHWR : 16;
            uint32_t             : 16;
        } MACSTHWS_b;
    };
    union
    {
        __IM uint32_t MACTSR;
        struct
        {
            __IM uint32_t TSSOVF     : 1;
            __IM uint32_t TSTARGT0   : 1;
            __IM uint32_t AUXTSTRIG  : 1;
            __IM uint32_t TSTRGTERR0 : 1;
            __IM uint32_t TSTARGT1   : 1;
            __IM uint32_t TSTRGTERR1 : 1;
            __IM uint32_t TSTARGT2   : 1;
            __IM uint32_t TSTRGTERR2 : 1;
            __IM uint32_t TSTARGT3   : 1;
            __IM uint32_t TSTRGTERR3 : 1;
            uint32_t                 : 5;
            __IM uint32_t TXTSSIS    : 1;
            __IM uint32_t ATSSTN     : 4;
            uint32_t                 : 4;
            __IM uint32_t ATSSTM     : 1;
            __IM uint32_t ATSNS      : 5;
            uint32_t                 : 2;
        } MACTSR_b;
    };
    __IM uint8_t RESERVED39[12];
    union
    {
        __IM uint32_t MACTTSNR;
        struct
        {
            __IM uint32_t TXTSSLO  : 31;
            __IM uint32_t TXTSSMIS : 1;
        } MACTTSNR_b;
    };
    union
    {
        __IM uint32_t MACTTSSR;
        struct
        {
            __IM uint32_t TXTSSHI : 32;
        } MACTTSSR_b;
    };
    __IM uint8_t RESERVED40[8];
    union
    {
        __IOM uint32_t MACACR;
        struct
        {
            __IOM uint32_t ATSFC  : 1;
            uint32_t              : 3;
            __IOM uint32_t ATSEN0 : 1;
            __IOM uint32_t ATSEN1 : 1;
            __IOM uint32_t ATSEN2 : 1;
            __IOM uint32_t ATSEN3 : 1;
            uint32_t              : 24;
        } MACACR_b;
    };
    __IM uint8_t RESERVED41[4];
    union
    {
        __IM uint32_t MACATNR;
        struct
        {
            __IM uint32_t AUXTSLO : 32;
        } MACATNR_b;
    };
    union
    {
        __IM uint32_t MACATSR;
        struct
        {
            __IM uint32_t AUXTSHI : 32;
        } MACATSR_b;
    };
    union
    {
        __IOM uint32_t MACTIACR;
        struct
        {
            __IOM uint32_t OSTIAC : 32;
        } MACTIACR_b;
    };
    union
    {
        __IOM uint32_t MACTEACR;
        struct
        {
            __IOM uint32_t OSTEAC : 32;
        } MACTEACR_b;
    };
    union
    {
        __IOM uint32_t MACTICNR;
        struct
        {
            __IOM uint32_t TSIC : 32;
        } MACTICNR_b;
    };
    union
    {
        __IOM uint32_t MACTECNR;
        struct
        {
            __IOM uint32_t TSEC : 32;
        } MACTECNR_b;
    };
    union
    {
        __IOM uint32_t MACTICSR;
        struct
        {
            uint32_t               : 8;
            __IOM uint32_t TSICSNS : 8;
            uint32_t               : 16;
        } MACTICSR_b;
    };
    union
    {
        __IOM uint32_t MACTECSR;
        struct
        {
            uint32_t               : 8;
            __IOM uint32_t TSECSNS : 8;
            uint32_t               : 16;
        } MACTECSR_b;
    };
    union
    {
        __IM uint32_t MACTILR;
        struct
        {
            uint32_t             : 8;
            __IM uint32_t ITLSNS : 8;
            __IM uint32_t ITLNS  : 12;
            uint32_t             : 4;
        } MACTILR_b;
    };
    union
    {
        __IM uint32_t MACTELR;
        struct
        {
            uint32_t             : 8;
            __IM uint32_t ETLSNS : 8;
            __IM uint32_t ETLNS  : 12;
            uint32_t             : 4;
        } MACTELR_b;
    };
    union
    {
        __IOM uint32_t MACPPCR;
        struct
        {
            __IOM uint32_t PPSCTRL_PPSCMD : 4;
            __IOM uint32_t PPSEN0         : 1;
            __IOM uint32_t TRGTMODSEL0    : 2;
            __IOM uint32_t MCGREN0        : 1;
            __IOM uint32_t PPSCMD1        : 4;
            uint32_t                      : 1;
            __IOM uint32_t TRGTMODSEL1    : 2;
            __IOM uint32_t MCGREN1        : 1;
            __IOM uint32_t PPSCMD2        : 4;
            uint32_t                      : 1;
            __IOM uint32_t TRGTMODSEL2    : 2;
            __IOM uint32_t MCGREN2        : 1;
            __IOM uint32_t PPSCMD3        : 4;
            __IOM uint32_t TIMESEL        : 1;
            __IOM uint32_t TRGTMODSEL3    : 2;
            __IOM uint32_t MCGREN3        : 1;
        } MACPPCR_b;
    };
    __IM uint8_t RESERVED42[12];
    union
    {
        __IOM uint32_t MACPTTSR0;
        struct
        {
            __IOM uint32_t TSTRH0 : 32;
        } MACPTTSR0_b;
    };
    union
    {
        __IOM uint32_t MACPTTNR0;
        struct
        {
            __IOM uint32_t TTSL0     : 31;
            __IOM uint32_t TRGTBUSY0 : 1;
        } MACPTTNR0_b;
    };
    union
    {
        __IOM uint32_t MACPIR0;
        struct
        {
            __IOM uint32_t PPSINT0 : 32;
        } MACPIR0_b;
    };
    union
    {
        __IOM uint32_t MACPWR0;
        struct
        {
            __IOM uint32_t PPSWIDTH0 : 32;
        } MACPWR0_b;
    };
    union
    {
        __IOM uint32_t MACPTTSR1;
        struct
        {
            __IOM uint32_t TSTRH0 : 32;
        } MACPTTSR1_b;
    };
    union
    {
        __IOM uint32_t MACPTTNR1;
        struct
        {
            __IOM uint32_t TTSL0     : 31;
            __IOM uint32_t TRGTBUSY0 : 1;
        } MACPTTNR1_b;
    };
    union
    {
        __IOM uint32_t MACPIR1;
        struct
        {
            __IOM uint32_t PPSINT0 : 32;
        } MACPIR1_b;
    };
    union
    {
        __IOM uint32_t MACPWR1;
        struct
        {
            __IOM uint32_t PPSWIDTH0 : 32;
        } MACPWR1_b;
    };
    union
    {
        __IOM uint32_t MACPTTSR2;
        struct
        {
            __IOM uint32_t TSTRH0 : 32;
        } MACPTTSR2_b;
    };
    union
    {
        __IOM uint32_t MACPTTNR2;
        struct
        {
            __IOM uint32_t TTSL0     : 31;
            __IOM uint32_t TRGTBUSY0 : 1;
        } MACPTTNR2_b;
    };
    union
    {
        __IOM uint32_t MACPIR2;
        struct
        {
            __IOM uint32_t PPSINT0 : 32;
        } MACPIR2_b;
    };
    union
    {
        __IOM uint32_t MACPWR2;
        struct
        {
            __IOM uint32_t PPSWIDTH0 : 32;
        } MACPWR2_b;
    };
    union
    {
        __IOM uint32_t MACPTTSR3;
        struct
        {
            __IOM uint32_t TSTRH0 : 32;
        } MACPTTSR3_b;
    };
    union
    {
        __IOM uint32_t MACPTTNR3;
        struct
        {
            __IOM uint32_t TTSL0     : 31;
            __IOM uint32_t TRGTBUSY0 : 1;
        } MACPTTNR3_b;
    };
    union
    {
        __IOM uint32_t MACPIR3;
        struct
        {
            __IOM uint32_t PPSINT0 : 32;
        } MACPIR3_b;
    };
    union
    {
        __IOM uint32_t MACPWR3;
        struct
        {
            __IOM uint32_t PPSWIDTH0 : 32;
        } MACPWR3_b;
    };
    union
    {
        __IOM uint32_t MACPTCR;
        struct
        {
            __IOM uint32_t PTOEN      : 1;
            __IOM uint32_t ASYNCEN    : 1;
            __IOM uint32_t APDREQEN   : 1;
            uint32_t                  : 1;
            __IOM uint32_t ASYNCTRIG  : 1;
            __IOM uint32_t APDREQTRIG : 1;
            __IOM uint32_t DRRDIS     : 1;
            __IOM uint32_t PDRDIS     : 1;
            __IOM uint32_t DN         : 8;
            uint32_t                  : 16;
        } MACPTCR_b;
    };
    union
    {
        __IOM uint32_t MACSPI0;
        struct
        {
            __IOM uint32_t SPI0 : 32;
        } MACSPI0_b;
    };
    union
    {
        __IOM uint32_t MACSPI1;
        struct
        {
            __IOM uint32_t SPI1 : 32;
        } MACSPI1_b;
    };
    union
    {
        __IOM uint32_t MACSPI2;
        struct
        {
            __IOM uint32_t SPI2 : 16;
            uint32_t            : 16;
        } MACSPI2_b;
    };
    union
    {
        __IOM uint32_t MACLMIR;
        struct
        {
            __IOM uint32_t LSI     : 8;
            __IOM uint32_t DRSYNCR : 3;
            uint32_t               : 13;
            __IOM uint32_t LMPDRI  : 8;
        } MACLMIR_b;
    };
    __IM uint8_t RESERVED43[44];
    union
    {
        __IOM uint32_t MTLOMR;
        struct
        {
            uint32_t               : 2;
            __IOM uint32_t RAA     : 1;
            uint32_t               : 2;
            __IOM uint32_t SCHALG  : 2;
            uint32_t               : 1;
            __IOM uint32_t CNTPRST : 1;
            __IOM uint32_t CNTCLR  : 1;
            uint32_t               : 22;
        } MTLOMR_b;
    };
    __IM uint8_t RESERVED44[28];
    union
    {
        __IM uint32_t MTLTISR;
        struct
        {
            __IM uint32_t Q0IS  : 1;
            __IM uint32_t Q1IS  : 1;
            __IM uint32_t Q2IS  : 1;
            __IM uint32_t Q3IS  : 1;
            uint32_t            : 12;
            __IM uint32_t MACIS : 1;
            uint32_t            : 15;
        } MTLTISR_b;
    };
    __IM uint8_t RESERVED45[12];
    union
    {
        __IOM uint32_t MTLRDMR;
        struct
        {
            __IOM uint32_t Q0MDMACH : 2;
            uint32_t                : 2;
            __IOM uint32_t Q0DDMACH : 1;
            uint32_t                : 3;
            __IOM uint32_t Q1MDMACH : 2;
            uint32_t                : 2;
            __IOM uint32_t Q1DDMACH : 1;
            uint32_t                : 3;
            __IOM uint32_t Q2MDMACH : 2;
            uint32_t                : 2;
            __IOM uint32_t Q2DDMACH : 1;
            uint32_t                : 3;
            __IOM uint32_t Q3MDMACH : 2;
            uint32_t                : 2;
            __IOM uint32_t Q3DDMACH : 1;
            uint32_t                : 3;
        } MTLRDMR_b;
    };
    __IM uint8_t       RESERVED46[204];
    R_GBETH_MTL_Q_Type MTL_Q[4];
    __IM uint8_t       RESERVED55[512];
    union
    {
        __IOM uint32_t DMR;
        struct
        {
            __IOM uint32_t SWR  : 1;
            __IOM uint32_t DA   : 1;
            __IOM uint32_t TAA  : 3;
            uint32_t            : 3;
            __IOM uint32_t DSPW : 1;
            __IOM uint32_t ARBC : 1;
            uint32_t            : 1;
            __IOM uint32_t TXPR : 1;
            __IOM uint32_t PR   : 3;
            uint32_t            : 1;
            __IOM uint32_t INTM : 2;
            uint32_t            : 14;
        } DMR_b;
    };
    union
    {
        __IOM uint32_t DSMR;
        struct
        {
            __IOM uint32_t FB          : 1;
            __IOM uint32_t BLEN4       : 1;
            __IOM uint32_t BLEN8       : 1;
            __IOM uint32_t BLEN16      : 1;
            uint32_t                   : 6;
            __IOM uint32_t AALE        : 1;
            uint32_t                   : 1;
            __IOM uint32_t AAL         : 1;
            __IOM uint32_t ONEKBBE     : 1;
            uint32_t                   : 2;
            __IOM uint32_t RD_OSR_LMT  : 4;
            uint32_t                   : 4;
            __IOM uint32_t WR_OSR_LMT  : 4;
            uint32_t                   : 2;
            __IOM uint32_t LPI_XIT_PKT : 1;
            __IOM uint32_t EN_LPI      : 1;
        } DSMR_b;
    };
    union
    {
        __IM uint32_t DISR;
        struct
        {
            __IM uint32_t DC0IS : 1;
            __IM uint32_t DC1IS : 1;
            __IM uint32_t DC2IS : 1;
            __IM uint32_t DC3IS : 1;
            uint32_t            : 12;
            __IM uint32_t MTLIS : 1;
            __IM uint32_t MACIS : 1;
            uint32_t            : 14;
        } DISR_b;
    };
    union
    {
        __IM uint32_t DDS0;
        struct
        {
            __IM uint32_t AXWHSTS : 1;
            __IM uint32_t AXRHSTS : 1;
            uint32_t              : 6;
            __IM uint32_t RPS0    : 4;
            __IM uint32_t TPS0    : 4;
            __IM uint32_t RPS1    : 4;
            __IM uint32_t TPS1    : 4;
            __IM uint32_t RPS2    : 4;
            __IM uint32_t TPS2    : 4;
        } DDS0_b;
    };
    union
    {
        __IM uint32_t DDS1;
        struct
        {
            __IM uint32_t RPS3 : 4;
            __IM uint32_t TPS3 : 4;
            uint32_t           : 24;
        } DDS1_b;
    };
    __IM uint8_t RESERVED56[44];
    union
    {
        __IOM uint32_t ALEIR;
        struct
        {
            __IOM uint32_t LPIEI : 4;
            uint32_t             : 28;
        } ALEIR_b;
    };
    __IM uint8_t      RESERVED57[188];
    R_GBETH_DMAC_Type DMA_CH[4];
} R_GBETH_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_GBETH0_BASE    0x15C30000
#define R_GBETH1_BASE    0x15C40000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_GBETH0    ((R_GBETH_Type *) R_GBETH0_BASE)
#define R_GBETH1    ((R_GBETH_Type *) R_GBETH1_BASE)

#endif
