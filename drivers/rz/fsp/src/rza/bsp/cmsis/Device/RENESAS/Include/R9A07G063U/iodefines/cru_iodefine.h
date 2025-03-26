/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : cru_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for cru.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef CRU_IODEFINE_H
#define CRU_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t CRUnCTRL;
        struct
        {
            __IOM uint32_t VINSEL : 1;
            uint32_t              : 31;
        } CRUnCTRL_b;
    };
    union
    {
        __IOM uint32_t CRUnIE;
        struct
        {
            __IOM uint32_t FOE      : 1;
            __IOM uint32_t SLVEE    : 1;
            __IOM uint32_t DECEE    : 1;
            __IOM uint32_t FEOVWE   : 1;
            uint32_t                : 4;
            __IOM uint32_t SDFOE    : 1;
            __IOM uint32_t SDSLVEE  : 1;
            __IOM uint32_t SDDECEE  : 1;
            __IOM uint32_t SDFEOVWE : 1;
            uint32_t                : 4;
            __IOM uint32_t SFE      : 1;
            __IOM uint32_t EFE      : 1;
            __IOM uint32_t SIE      : 1;
            __IOM uint32_t WIE      : 1;
            uint32_t                : 12;
        } CRUnIE_b;
    };
    union
    {
        __IOM uint32_t CRUnINTS;
        struct
        {
            __IOM uint32_t FOS      : 1;
            __IOM uint32_t SLVES    : 1;
            __IOM uint32_t DECES    : 1;
            __IOM uint32_t FEOVWS   : 1;
            uint32_t                : 4;
            __IOM uint32_t SDFOS    : 1;
            __IOM uint32_t SDSLVES  : 1;
            __IOM uint32_t SDDECES  : 1;
            __IOM uint32_t SDFEOVWS : 1;
            uint32_t                : 4;
            __IOM uint32_t SFS      : 1;
            __IOM uint32_t EFS      : 1;
            __IOM uint32_t SIS      : 1;
            __IOM uint32_t WIS      : 1;
            __IOM uint32_t CES      : 1;
            uint32_t                : 11;
        } CRUnINTS_b;
    };
    union
    {
        __IOM uint32_t CRUnRST;
        struct
        {
            __IOM uint32_t VRESETN : 1;
            uint32_t               : 31;
        } CRUnRST_b;
    };
    __IM uint8_t RESERVED[112];
    union
    {
        __IOM uint32_t CRUnCOM;
        struct
        {
            __IOM uint32_t COMMON : 32;
        } CRUnCOM_b;
    };
    __IM uint8_t RESERVED1[124];
    union
    {
        __IOM uint32_t AMnMB1ADDRL;
        struct
        {
            uint32_t                : 9;
            __IOM uint32_t MB1ADDRL : 23;
        } AMnMB1ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnMB1ADDRH;
        struct
        {
            __IOM uint32_t MB1ADDRH : 2;
            uint32_t                : 30;
        } AMnMB1ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnMB2ADDRL;
        struct
        {
            uint32_t                : 9;
            __IOM uint32_t MB2ADDRL : 23;
        } AMnMB2ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnMB2ADDRH;
        struct
        {
            __IOM uint32_t MB2ADDRH : 2;
            uint32_t                : 30;
        } AMnMB2ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnMB3ADDRL;
        struct
        {
            uint32_t                : 9;
            __IOM uint32_t MB3ADDRL : 23;
        } AMnMB3ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnMB3ADDRH;
        struct
        {
            __IOM uint32_t MB3ADDRH : 2;
            uint32_t                : 30;
        } AMnMB3ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnMB4ADDRL;
        struct
        {
            uint32_t                : 9;
            __IOM uint32_t MB4ADDRL : 23;
        } AMnMB4ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnMB4ADDRH;
        struct
        {
            __IOM uint32_t MB4ADDRH : 2;
            uint32_t                : 30;
        } AMnMB4ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnMB5ADDRL;
        struct
        {
            uint32_t                : 9;
            __IOM uint32_t MB5ADDRL : 23;
        } AMnMB5ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnMB5ADDRH;
        struct
        {
            __IOM uint32_t MB5ADDRH : 2;
            uint32_t                : 30;
        } AMnMB5ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnMB6ADDRL;
        struct
        {
            uint32_t                : 9;
            __IOM uint32_t MB6ADDRL : 23;
        } AMnMB6ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnMB6ADDRH;
        struct
        {
            __IOM uint32_t MB6ADDRH : 2;
            uint32_t                : 30;
        } AMnMB6ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnMB7ADDRL;
        struct
        {
            uint32_t                : 9;
            __IOM uint32_t MB7ADDRL : 23;
        } AMnMB7ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnMB7ADDRH;
        struct
        {
            __IOM uint32_t MB7ADDRH : 2;
            uint32_t                : 30;
        } AMnMB7ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnMB8ADDRL;
        struct
        {
            uint32_t                : 9;
            __IOM uint32_t MB8ADDRL : 23;
        } AMnMB8ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnMB8ADDRH;
        struct
        {
            __IOM uint32_t MB8ADDRH : 2;
            uint32_t                : 30;
        } AMnMB8ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnUVAOFL;
        struct
        {
            uint32_t              : 9;
            __IOM uint32_t UVAOFL : 23;
        } AMnUVAOFL_b;
    };
    union
    {
        __IOM uint32_t AMnUVAOFH;
        struct
        {
            __IOM uint32_t UVAOFH : 3;
            uint32_t              : 29;
        } AMnUVAOFH_b;
    };
    union
    {
        __IOM uint32_t AMnMBVALID;
        struct
        {
            __IOM uint32_t MBVALID : 8;
            uint32_t               : 24;
        } AMnMBVALID_b;
    };
    union
    {
        __IOM uint32_t AMnMBS;
        struct
        {
            __IOM uint32_t MBSTS : 3;
            uint32_t             : 29;
        } AMnMBS_b;
    };
    __IM uint8_t RESERVED2[8];
    union
    {
        __IOM uint32_t AMnAXIATTR;
        struct
        {
            __IOM uint32_t AXILEN : 4;
            uint32_t              : 28;
        } AMnAXIATTR_b;
    };
    __IM uint8_t RESERVED3[4];
    union
    {
        __IOM uint32_t AMnFIFO;
        struct
        {
            __IOM uint32_t FIFOOVFREC : 1;
            uint32_t                  : 31;
        } AMnFIFO_b;
    };
    union
    {
        __IOM uint32_t AMnFIFOTRST;
        struct
        {
            __IOM uint32_t AXI_TRANS_START : 1;
            uint32_t                       : 31;
        } AMnFIFOTRST_b;
    };
    union
    {
        __IOM uint32_t AMnFIFOPNTR;
        struct
        {
            __IOM uint32_t FIFOWPNTR    : 8;
            uint32_t                    : 8;
            __IOM uint32_t FIFORPNTR_Y  : 8;
            __IOM uint32_t FIFORPNTR_UV : 8;
        } AMnFIFOPNTR_b;
    };
    __IM uint8_t RESERVED4[4];
    union
    {
        __IOM uint32_t AMnAXIBID;
        struct
        {
            __IOM uint32_t BIDCHK : 1;
            uint32_t              : 31;
        } AMnAXIBID_b;
    };
    union
    {
        __IOM uint32_t AMnAXISTP;
        struct
        {
            __IOM uint32_t AXI_STOP : 1;
            uint32_t                : 31;
        } AMnAXISTP_b;
    };
    union
    {
        __IOM uint32_t AMnAXISTPACK;
        struct
        {
            __IOM uint32_t AXI_STOP_ACK : 1;
            uint32_t                    : 31;
        } AMnAXISTPACK_b;
    };
    __IM uint8_t RESERVED5[20];
    union
    {
        __IOM uint32_t AMnSDMB1ADDRL;
        struct
        {
            uint32_t                  : 9;
            __IOM uint32_t SDMB1ADDRL : 23;
        } AMnSDMB1ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB1ADDRH;
        struct
        {
            __IOM uint32_t SDMB1ADDRH : 2;
            uint32_t                  : 30;
        } AMnSDMB1ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB2ADDRL;
        struct
        {
            uint32_t                  : 9;
            __IOM uint32_t SDMB2ADDRL : 23;
        } AMnSDMB2ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB2ADDRH;
        struct
        {
            __IOM uint32_t SDMB2ADDRH : 2;
            uint32_t                  : 30;
        } AMnSDMB2ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB3ADDRL;
        struct
        {
            uint32_t                  : 9;
            __IOM uint32_t SDMB3ADDRL : 23;
        } AMnSDMB3ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB3ADDRH;
        struct
        {
            __IOM uint32_t SDMB3ADDRH : 2;
            uint32_t                  : 30;
        } AMnSDMB3ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB4ADDRL;
        struct
        {
            uint32_t                  : 9;
            __IOM uint32_t SDMB4ADDRL : 23;
        } AMnSDMB4ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB4ADDRH;
        struct
        {
            __IOM uint32_t SDMB4ADDRH : 2;
            uint32_t                  : 30;
        } AMnSDMB4ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB5ADDRL;
        struct
        {
            uint32_t                  : 9;
            __IOM uint32_t SDMB5ADDRL : 23;
        } AMnSDMB5ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB5ADDRH;
        struct
        {
            __IOM uint32_t SDMB5ADDRH : 2;
            uint32_t                  : 30;
        } AMnSDMB5ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB6ADDRL;
        struct
        {
            uint32_t                  : 9;
            __IOM uint32_t SDMB6ADDRL : 23;
        } AMnSDMB6ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB6ADDRH;
        struct
        {
            __IOM uint32_t SDMB6ADDRH : 2;
            uint32_t                  : 30;
        } AMnSDMB6ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB7ADDRL;
        struct
        {
            uint32_t                  : 9;
            __IOM uint32_t SDMB7ADDRL : 23;
        } AMnSDMB7ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB7ADDRH;
        struct
        {
            __IOM uint32_t SDMB7ADDRH : 2;
            uint32_t                  : 30;
        } AMnSDMB7ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB8ADDRL;
        struct
        {
            uint32_t                  : 9;
            __IOM uint32_t SDMB8ADDRL : 23;
        } AMnSDMB8ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB8ADDRH;
        struct
        {
            __IOM uint32_t SDMB8ADDRH : 2;
            uint32_t                  : 30;
        } AMnSDMB8ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMBVALID;
        struct
        {
            __IOM uint32_t SDMBVALID : 8;
            uint32_t                 : 24;
        } AMnSDMBVALID_b;
    };
    union
    {
        __IM uint32_t AMnSDMBS;
        struct
        {
            __IM uint32_t SDMBSTS : 3;
            uint32_t              : 29;
        } AMnSDMBS_b;
    };
    union
    {
        __IOM uint32_t AMnSDAXIATTR;
        struct
        {
            __IOM uint32_t SDAXILEN : 4;
            uint32_t                : 28;
        } AMnSDAXIATTR_b;
    };
    __IM uint8_t RESERVED6[4];
    union
    {
        __IOM uint32_t AMnSDFIFO;
        struct
        {
            __IOM uint32_t SDFIFOOVFREC : 1;
            uint32_t                    : 31;
        } AMnSDFIFO_b;
    };
    union
    {
        __IOM uint32_t AMnSDFIFOTRST;
        struct
        {
            __IOM uint32_t SDAXI_TRANS_START : 1;
            uint32_t                         : 31;
        } AMnSDFIFOTRST_b;
    };
    union
    {
        __IM uint32_t AMnSDFIFOPNTR;
        struct
        {
            __IM uint32_t SDFIFOWPNTR : 5;
            uint32_t                  : 11;
            __IM uint32_t SDFIFORPNTR : 5;
            uint32_t                  : 11;
        } AMnSDFIFOPNTR_b;
    };
    __IM uint8_t RESERVED7[4];
    union
    {
        __IOM uint32_t AMnSDAXIBID;
        struct
        {
            __IOM uint32_t SDBIDCHK : 1;
            uint32_t                : 31;
        } AMnSDAXIBID_b;
    };
    union
    {
        __IOM uint32_t AMnSDAXISTP;
        struct
        {
            __IOM uint32_t SDAXI_STOP : 1;
            uint32_t                  : 31;
        } AMnSDAXISTP_b;
    };
    union
    {
        __IM uint32_t AMnSDAXISTPACK;
        struct
        {
            __IM uint32_t SDAXI_STOP_ACK : 1;
            uint32_t                     : 31;
        } AMnSDAXISTPACK_b;
    };
    __IM uint8_t RESERVED8[4];
    union
    {
        __IOM uint32_t ICnEN;
        struct
        {
            __IOM uint32_t ICEN : 1;
            uint32_t            : 31;
        } ICnEN_b;
    };
    union
    {
        __IOM uint32_t ICnREGC;
        struct
        {
            __IOM uint32_t REFEN : 1;
            uint32_t             : 31;
        } ICnREGC_b;
    };
    union
    {
        __IOM uint32_t ICnMC;
        struct
        {
            __IOM uint32_t ICTHR    : 1;
            __IOM uint32_t DECTHR   : 1;
            __IOM uint32_t CLPTHR   : 1;
            __IOM uint32_t DEMTHR   : 1;
            __IOM uint32_t LMXTHR   : 1;
            __IOM uint32_t CSCTHR   : 1;
            __IOM uint32_t LUTTHR   : 1;
            __IOM uint32_t STITHR   : 1;
            uint32_t                : 4;
            __IOM uint32_t CLP      : 2;
            __IOM uint32_t IBINSEL  : 1;
            __IOM uint32_t DES0     : 1;
            __IOM uint32_t INF      : 6;
            __IOM uint32_t VCSEL    : 2;
            __IOM uint32_t RAWSTTYP : 2;
            uint32_t                : 6;
        } ICnMC_b;
    };
    __IM uint8_t RESERVED9[4];
    union
    {
        __IOM uint32_t ICnSLPrC;
        struct
        {
            __IOM uint32_t SLPrC : 12;
            uint32_t             : 20;
        } ICnSLPrC_b;
    };
    union
    {
        __IOM uint32_t ICnELPrC;
        struct
        {
            __IOM uint32_t ELPrC : 12;
            uint32_t             : 20;
        } ICnELPrC_b;
    };
    union
    {
        __IOM uint32_t ICnSPPrC;
        struct
        {
            __IOM uint32_t SPPrC : 12;
            uint32_t             : 20;
        } ICnSPPrC_b;
    };
    union
    {
        __IOM uint32_t ICnEPPrC;
        struct
        {
            __IOM uint32_t EPPrC : 12;
            uint32_t             : 20;
        } ICnEPPrC_b;
    };
    union
    {
        __IOM uint32_t ICnSI;
        struct
        {
            __IOM uint32_t SI : 12;
            uint32_t          : 20;
        } ICnSI_b;
    };
    union
    {
        __IOM uint32_t ICnLMXOF;
        struct
        {
            __IOM uint32_t ROF : 8;
            __IOM uint32_t GOF : 8;
            __IOM uint32_t BOF : 8;
            uint32_t           : 8;
        } ICnLMXOF_b;
    };
    union
    {
        __IOM uint32_t ICnLMXRC1;
        struct
        {
            __IOM uint32_t RR : 13;
            uint32_t          : 19;
        } ICnLMXRC1_b;
    };
    union
    {
        __IOM uint32_t ICnLMXRC2;
        struct
        {
            __IOM uint32_t RG : 13;
            uint32_t          : 3;
            __IOM uint32_t RB : 13;
            uint32_t          : 3;
        } ICnLMXRC2_b;
    };
    union
    {
        __IOM uint32_t ICnLMXGC1;
        struct
        {
            __IOM uint32_t GR : 13;
            uint32_t          : 19;
        } ICnLMXGC1_b;
    };
    union
    {
        __IOM uint32_t ICnLMXGC2;
        struct
        {
            __IOM uint32_t GG : 13;
            uint32_t          : 3;
            __IOM uint32_t GB : 13;
            uint32_t          : 3;
        } ICnLMXGC2_b;
    };
    union
    {
        __IOM uint32_t ICnLMXBC1;
        struct
        {
            __IOM uint32_t BR : 13;
            uint32_t          : 19;
        } ICnLMXBC1_b;
    };
    union
    {
        __IOM uint32_t ICnLMXBC2;
        struct
        {
            __IOM uint32_t BG : 13;
            uint32_t          : 3;
            __IOM uint32_t BB : 13;
            uint32_t          : 3;
        } ICnLMXBC2_b;
    };
    union
    {
        __IOM uint32_t ICnSTIC1;
        struct
        {
            __IOM uint32_t STUNIT   : 2;
            uint32_t                : 14;
            __IOM uint32_t STSADPOS : 4;
            uint32_t                : 12;
        } ICnSTIC1_b;
    };
    union
    {
        __IOM uint32_t ICnSTIC2;
        struct
        {
            __IOM uint32_t STHPOS : 9;
            uint32_t              : 23;
        } ICnSTIC2_b;
    };
    __IM uint8_t RESERVED10[8];
    union
    {
        __IOM uint32_t ICnPIFC;
        struct
        {
            __IOM uint32_t PINF  : 4;
            uint32_t             : 4;
            __IOM uint32_t ITL   : 3;
            uint32_t             : 1;
            __IOM uint32_t EC    : 1;
            __IOM uint32_t VSPOL : 1;
            __IOM uint32_t ENPOL : 1;
            uint32_t             : 17;
        } ICnPIFC_b;
    };
    union
    {
        __IM uint32_t ICnMS;
        struct
        {
            __IM uint32_t CA : 1;
            __IM uint32_t AV : 1;
            __IM uint32_t IA : 1;
            uint32_t         : 29;
        } ICnMS_b;
    };
    union
    {
        __IOM uint32_t ICnDEC;
        struct
        {
            __IOM uint32_t FRMDEC : 4;
            uint32_t              : 28;
        } ICnDEC_b;
    };
    union
    {
        __IOM uint32_t ICnLC;
        struct
        {
            __IOM uint32_t LC : 12;
            uint32_t          : 20;
        } ICnLC_b;
    };
    union
    {
        __IOM uint32_t ICnWC;
        struct
        {
            __IOM uint32_t WCLC : 12;
            uint32_t            : 4;
            __IOM uint32_t WC   : 16;
        } ICnWC_b;
    };
    union
    {
        __IOM uint32_t ICnEWC;
        struct
        {
            __IOM uint32_t EWC : 16;
            uint32_t           : 16;
        } ICnEWC_b;
    };
    union
    {
        __IOM uint32_t ICnINTCTRL;
        struct
        {
            __IOM uint32_t DECINTE : 1;
            uint32_t               : 31;
        } ICnINTCTRL_b;
    };
    union
    {
        __IOM uint32_t ICnDMR;
        struct
        {
            __IOM uint32_t RGBMODE : 2;
            uint32_t               : 2;
            __IOM uint32_t YCMODE  : 3;
            uint32_t               : 1;
            __IOM uint32_t OBINSEL : 1;
            uint32_t               : 15;
            __IOM uint32_t A8BIT   : 8;
        } ICnDMR_b;
    };
    union
    {
        __IOM uint32_t ICnCSCC1;
        struct
        {
            __IOM uint32_t YMUL : 14;
            uint32_t            : 18;
        } ICnCSCC1_b;
    };
    union
    {
        __IOM uint32_t ICnCSCC2;
        struct
        {
            __IOM uint32_t CSUB : 12;
            uint32_t            : 4;
            __IOM uint32_t YSUB : 12;
            uint32_t            : 4;
        } ICnCSCC2_b;
    };
    union
    {
        __IOM uint32_t ICnCSCC3;
        struct
        {
            __IOM uint32_t GCRMUL : 14;
            uint32_t              : 2;
            __IOM uint32_t RCRMUL : 14;
            uint32_t              : 2;
        } ICnCSCC3_b;
    };
    union
    {
        __IOM uint32_t ICnCSCC4;
        struct
        {
            __IOM uint32_t BCBMUL : 14;
            uint32_t              : 2;
            __IOM uint32_t GCBMUL : 14;
            uint32_t              : 2;
        } ICnCSCC4_b;
    };
    union
    {
        __IOM uint32_t ICnYCCR1;
        struct
        {
            __IOM uint32_t YCLRP : 13;
            uint32_t             : 19;
        } ICnYCCR1_b;
    };
    union
    {
        __IOM uint32_t ICnYCCR2;
        struct
        {
            __IOM uint32_t YCLGP : 13;
            uint32_t             : 3;
            __IOM uint32_t YCLBP : 13;
            uint32_t             : 3;
        } ICnYCCR2_b;
    };
    union
    {
        __IOM uint32_t ICnYCCR3;
        struct
        {
            __IOM uint32_t YCLAP  : 12;
            uint32_t              : 4;
            __IOM uint32_t YCLCEN : 1;
            uint32_t              : 7;
            __IOM uint32_t YCLSFT : 5;
            uint32_t              : 2;
            __IOM uint32_t YEXPEN : 1;
        } ICnYCCR3_b;
    };
    union
    {
        __IOM uint32_t ICnCBCCR1;
        struct
        {
            __IOM uint32_t CBCLRP : 13;
            uint32_t              : 19;
        } ICnCBCCR1_b;
    };
    union
    {
        __IOM uint32_t ICnCBCCR2;
        struct
        {
            __IOM uint32_t CBCLGP : 13;
            uint32_t              : 3;
            __IOM uint32_t CBCLBP : 13;
            uint32_t              : 3;
        } ICnCBCCR2_b;
    };
    union
    {
        __IOM uint32_t ICnCBCCR3;
        struct
        {
            __IOM uint32_t CBCLAP  : 12;
            uint32_t               : 4;
            __IOM uint32_t CBCLCEN : 1;
            uint32_t               : 7;
            __IOM uint32_t CBCLSFT : 5;
            uint32_t               : 2;
            __IOM uint32_t CBEXPEN : 1;
        } ICnCBCCR3_b;
    };
    union
    {
        __IOM uint32_t ICnCRCCR1;
        struct
        {
            __IOM uint32_t CRCLRP : 13;
            uint32_t              : 19;
        } ICnCRCCR1_b;
    };
    union
    {
        __IOM uint32_t ICnCRCCR2;
        struct
        {
            __IOM uint32_t CRCLGP : 13;
            uint32_t              : 3;
            __IOM uint32_t CRCLBP : 13;
            uint32_t              : 3;
        } ICnCRCCR2_b;
    };
    union
    {
        __IOM uint32_t ICnCRCCR3;
        struct
        {
            __IOM uint32_t CRCLAP  : 12;
            uint32_t               : 4;
            __IOM uint32_t CRCLCEN : 1;
            uint32_t               : 7;
            __IOM uint32_t CRCLSFT : 5;
            uint32_t               : 2;
            __IOM uint32_t CREXPEN : 1;
        } ICnCRCCR3_b;
    };
    __IM uint8_t RESERVED11[12];
    union
    {
        __IOM uint32_t ICnLUT;
        struct
        {
            __IOM uint32_t LUTSEL : 1;
            __IOM uint32_t LUTWR  : 1;
            uint32_t              : 30;
        } ICnLUT_b;
    };
    union
    {
        __IM uint32_t ICnLUTS;
        struct
        {
            __IM uint32_t LUTREGSEL : 1;
            uint32_t                : 31;
        } ICnLUTS_b;
    };
    union
    {
        __IOM uint32_t ICnLUTP;
        struct
        {
            __IOM uint32_t LTCRPR : 10;
            __IOM uint32_t LTCBPR : 10;
            __IOM uint32_t LTYPR  : 10;
            uint32_t              : 2;
        } ICnLUTP_b;
    };
    union
    {
        __IOM uint32_t ICnLUTD;
        struct
        {
            __IOM uint32_t LTCRDT : 8;
            __IOM uint32_t LTCBDT : 8;
            __IOM uint32_t LTYDT  : 8;
            uint32_t              : 8;
        } ICnLUTD_b;
    };
    union
    {
        __IOM uint32_t ICnTICTRL1;
        struct
        {
            __IOM uint32_t TIEN    : 1;
            __IOM uint32_t TIMODE  : 1;
            uint32_t               : 2;
            __IOM uint32_t TIPTNY1 : 4;
            __IOM uint32_t TIPTNU1 : 4;
            __IOM uint32_t TIPTNV1 : 4;
            __IOM uint32_t TIRATE  : 5;
            uint32_t               : 11;
        } ICnTICTRL1_b;
    };
    union
    {
        __IOM uint32_t ICnTICTRL2;
        struct
        {
            __IOM uint32_t TIPTNY2 : 8;
            __IOM uint32_t TIPTNU2 : 8;
            __IOM uint32_t TIPTNV2 : 8;
            uint32_t               : 8;
        } ICnTICTRL2_b;
    };
    union
    {
        __IOM uint32_t ICnTISIZE1;
        struct
        {
            __IOM uint32_t TIPPL : 12;
            uint32_t             : 20;
        } ICnTISIZE1_b;
    };
    union
    {
        __IOM uint32_t ICnTISIZE2;
        struct
        {
            __IOM uint32_t TIN : 12;
            uint32_t           : 4;
            __IOM uint32_t TIM : 12;
            uint32_t           : 4;
        } ICnTISIZE2_b;
    };
    __IM uint8_t RESERVED12[304];
    union
    {
        __IM uint32_t CSI2nMCG;
        struct
        {
            __IM uint32_t VER  : 4;
            uint32_t           : 4;
            __IM uint32_t SDLN : 4;
            uint32_t           : 4;
            __IM uint32_t GSNM : 8;
            uint32_t           : 8;
        } CSI2nMCG_b;
    };
    __IM uint8_t RESERVED13[12];
    union
    {
        __IOM uint32_t CSI2nMCT0;
        struct
        {
            __IOM uint32_t VDLN   : 4;
            uint32_t              : 12;
            __IOM uint32_t ZLMD   : 1;
            __IOM uint32_t EDMD   : 1;
            uint32_t              : 1;
            __IOM uint32_t RVMD   : 1;
            uint32_t              : 4;
            __IOM uint32_t ECCV13 : 1;
            __IOM uint32_t LFSREN : 1;
            uint32_t              : 6;
        } CSI2nMCT0_b;
    };
    __IM uint8_t RESERVED14[4];
    union
    {
        __IOM uint32_t CSI2nMCT2;
        struct
        {
            __IOM uint32_t FRRCLK : 9;
            uint32_t              : 7;
            __IOM uint32_t FRRSKW : 9;
            uint32_t              : 7;
        } CSI2nMCT2_b;
    };
    union
    {
        __IOM uint32_t CSI2nMCT3;
        struct
        {
            __IOM uint32_t RXEN : 1;
            uint32_t            : 31;
        } CSI2nMCT3_b;
    };
    __IM uint8_t RESERVED15[8];
    union
    {
        __IOM uint32_t CSI2nRTCT;
        struct
        {
            __IOM uint32_t VSRST : 1;
            uint32_t             : 31;
        } CSI2nRTCT_b;
    };
    union
    {
        __IM uint32_t CSI2nRTST;
        struct
        {
            __IM uint32_t VSRSTS : 1;
            uint32_t             : 31;
        } CSI2nRTST_b;
    };
    __IM uint8_t RESERVED16[16];
    union
    {
        __IOM uint32_t CSI2nEPCT;
        struct
        {
            __IOM uint32_t SLP   : 15;
            __IOM uint32_t EPDOP : 1;
            __IOM uint32_t SSP   : 15;
            __IOM uint32_t EPDEN : 1;
        } CSI2nEPCT_b;
    };
    __IM uint8_t RESERVED17[12];
    union
    {
        __IM uint32_t CSI2nMIST;
        struct
        {
            __IM uint32_t DL0S : 1;
            __IM uint32_t DL1S : 1;
            __IM uint32_t DL2S : 1;
            __IM uint32_t DL3S : 1;
            uint32_t           : 4;
            __IM uint32_t PMS  : 1;
            __IM uint32_t GSTS : 1;
            __IM uint32_t RXS  : 1;
            uint32_t           : 5;
            __IM uint32_t VC0S : 1;
            __IM uint32_t VC1S : 1;
            __IM uint32_t VC2S : 1;
            __IM uint32_t VC3S : 1;
            uint32_t           : 12;
        } CSI2nMIST_b;
    };
    __IM uint8_t RESERVED18[12];
    union
    {
        __IOM uint32_t CSI2nDTEL;
        struct
        {
            __IM uint32_t DTEN : 32;
        } CSI2nDTEL_b;
    };
    union
    {
        __IOM uint32_t CSI2nDTEH;
        struct
        {
            __IOM uint32_t DTEN : 32;
        } CSI2nDTEH_b;
    };
    __IM uint8_t RESERVED19[8];
    union
    {
        __IM uint32_t CSI2nRXST;
        struct
        {
            __IM uint32_t FRM0    : 1;
            __IM uint32_t FRM1    : 1;
            __IM uint32_t FRM2    : 1;
            __IM uint32_t FRM3    : 1;
            uint32_t              : 12;
            __IM uint32_t RACT    : 1;
            __IM uint32_t RACTDET : 1;
            uint32_t              : 14;
        } CSI2nRXST_b;
    };
    union
    {
        __IOM uint32_t CSI2nRXSC;
        struct
        {
            uint32_t                : 17;
            __IOM uint32_t RACTDETC : 1;
            uint32_t                : 14;
        } CSI2nRXSC_b;
    };
    union
    {
        __IOM uint32_t CSI2nRXIE;
        struct
        {
            uint32_t                : 17;
            __IOM uint32_t RACTDETE : 1;
            uint32_t                : 14;
        } CSI2nRXIE_b;
    };
    __IM uint8_t RESERVED20[4];
    union
    {
        __IM uint32_t CSI2nDLST0;
        struct
        {
            __IM uint32_t ESH0 : 1;
            __IM uint32_t ESS0 : 1;
            __IM uint32_t ECT0 : 1;
            __IM uint32_t EES0 : 1;
            uint32_t           : 12;
            __IM uint32_t EUL0 : 1;
            __IM uint32_t RUL0 : 1;
            uint32_t           : 6;
            __IM uint32_t ULP0 : 1;
            uint32_t           : 7;
        } CSI2nDLST0_b;
    };
    union
    {
        __IOM uint32_t CSI2nDLSC0;
        struct
        {
            __IOM uint32_t ESHC0 : 1;
            __IOM uint32_t ESSC0 : 1;
            __IOM uint32_t ECTC0 : 1;
            __IOM uint32_t EESC0 : 1;
            uint32_t             : 12;
            __IOM uint32_t EULC0 : 1;
            __IOM uint32_t RULC0 : 1;
            uint32_t             : 14;
        } CSI2nDLSC0_b;
    };
    union
    {
        __IOM uint32_t CSI2nDLIE0;
        struct
        {
            __IOM uint32_t ESHE0 : 1;
            __IOM uint32_t ESSE0 : 1;
            __IOM uint32_t ECTE0 : 1;
            __IOM uint32_t EESE0 : 1;
            uint32_t             : 12;
            __IOM uint32_t EULE0 : 1;
            __IOM uint32_t RULE0 : 1;
            uint32_t             : 14;
        } CSI2nDLIE0_b;
    };
    __IM uint8_t RESERVED21[4];
    union
    {
        __IM uint32_t CSI2nDLST1;
        struct
        {
            __IM uint32_t ESH1 : 1;
            __IM uint32_t ESS1 : 1;
            __IM uint32_t ECT1 : 1;
            __IM uint32_t EES1 : 1;
            uint32_t           : 12;
            __IM uint32_t EUL1 : 1;
            __IM uint32_t RUL1 : 1;
            uint32_t           : 6;
            __IM uint32_t ULP1 : 1;
            uint32_t           : 7;
        } CSI2nDLST1_b;
    };
    union
    {
        __IOM uint32_t CSI2nDLSC1;
        struct
        {
            __IOM uint32_t ESHC1 : 1;
            __IOM uint32_t ESSC1 : 1;
            __IOM uint32_t ECTC1 : 1;
            __IOM uint32_t EESC1 : 1;
            uint32_t             : 12;
            __IOM uint32_t EULC1 : 1;
            __IOM uint32_t RULC1 : 1;
            uint32_t             : 14;
        } CSI2nDLSC1_b;
    };
    union
    {
        __IOM uint32_t CSI2nDLIE1;
        struct
        {
            __IOM uint32_t ESHE1 : 1;
            __IOM uint32_t ESSE1 : 1;
            __IOM uint32_t ECTE1 : 1;
            __IOM uint32_t EESE1 : 1;
            uint32_t             : 12;
            __IOM uint32_t EULE1 : 1;
            __IOM uint32_t RULE1 : 1;
            uint32_t             : 14;
        } CSI2nDLIE1_b;
    };
    __IM uint8_t RESERVED22[4];
    union
    {
        __IM uint32_t CSI2nDLST2;
        struct
        {
            __IM uint32_t ESH2 : 1;
            __IM uint32_t ESS2 : 1;
            __IM uint32_t ECT2 : 1;
            __IM uint32_t EES2 : 1;
            uint32_t           : 12;
            __IM uint32_t EUL2 : 1;
            __IM uint32_t RUL2 : 1;
            uint32_t           : 6;
            __IM uint32_t ULP2 : 1;
            uint32_t           : 7;
        } CSI2nDLST2_b;
    };
    union
    {
        __IOM uint32_t CSI2nDLSC2;
        struct
        {
            __IOM uint32_t ESHC2 : 1;
            __IOM uint32_t ESSC2 : 1;
            __IOM uint32_t ECTC2 : 1;
            __IOM uint32_t EESC2 : 1;
            uint32_t             : 12;
            __IOM uint32_t EULC2 : 1;
            __IOM uint32_t RULC2 : 1;
            uint32_t             : 14;
        } CSI2nDLSC2_b;
    };
    union
    {
        __IOM uint32_t CSI2nDLIE2;
        struct
        {
            __IOM uint32_t ESHE2 : 1;
            __IOM uint32_t ESSE2 : 1;
            __IOM uint32_t ECTE2 : 1;
            __IOM uint32_t EESE2 : 1;
            uint32_t             : 12;
            __IOM uint32_t EULE2 : 1;
            __IOM uint32_t RULE2 : 1;
            uint32_t             : 14;
        } CSI2nDLIE2_b;
    };
    __IM uint8_t RESERVED23[4];
    union
    {
        __IM uint32_t CSI2nDLST3;
        struct
        {
            __IM uint32_t ESH3 : 1;
            __IM uint32_t ESS3 : 1;
            __IM uint32_t ECT3 : 1;
            __IM uint32_t EES3 : 1;
            uint32_t           : 12;
            __IM uint32_t EUL3 : 1;
            __IM uint32_t RUL3 : 1;
            uint32_t           : 6;
            __IM uint32_t ULP3 : 1;
            uint32_t           : 7;
        } CSI2nDLST3_b;
    };
    union
    {
        __IOM uint32_t CSI2nDLSC3;
        struct
        {
            __IOM uint32_t ESHC3 : 1;
            __IOM uint32_t ESSC3 : 1;
            __IOM uint32_t ECTC3 : 1;
            __IOM uint32_t EESC3 : 1;
            uint32_t             : 12;
            __IOM uint32_t EULC3 : 1;
            __IOM uint32_t RULC3 : 1;
            uint32_t             : 14;
        } CSI2nDLSC3_b;
    };
    union
    {
        __IOM uint32_t CSI2nDLIE3;
        struct
        {
            __IOM uint32_t ESHE3 : 1;
            __IOM uint32_t ESSE3 : 1;
            __IOM uint32_t ECTE3 : 1;
            __IOM uint32_t EESE3 : 1;
            uint32_t             : 12;
            __IOM uint32_t EULE3 : 1;
            __IOM uint32_t RULE3 : 1;
            uint32_t             : 14;
        } CSI2nDLIE3_b;
    };
    __IM uint8_t RESERVED24[68];
    union
    {
        __IM uint32_t CSI2nVCST0;
        struct
        {
            __IM uint32_t MLF0 : 1;
            __IM uint32_t ECD0 : 1;
            __IM uint32_t CRC0 : 1;
            __IM uint32_t IDE0 : 1;
            __IM uint32_t WCE0 : 1;
            __IM uint32_t ECC0 : 1;
            __IM uint32_t ECN0 : 1;
            uint32_t           : 1;
            __IM uint32_t FRS0 : 1;
            __IM uint32_t FRD0 : 1;
            uint32_t           : 6;
            __IM uint32_t OVF0 : 1;
            uint32_t           : 7;
            __IM uint32_t FSR0 : 1;
            __IM uint32_t FER0 : 1;
            __IM uint32_t LSR0 : 1;
            __IM uint32_t LER0 : 1;
            uint32_t           : 4;
        } CSI2nVCST0_b;
    };
    union
    {
        __IOM uint32_t CSI2nVCSC0;
        struct
        {
            __IOM uint32_t MLFC0  : 1;
            __IOM uint32_t ECDC0  : 1;
            __IOM uint32_t CRCC0  : 1;
            __IOM uint32_t IDEC0  : 1;
            __IOM uint32_t WCEC0  : 1;
            __IOM uint32_t ECCC0  : 1;
            __IOM uint32_t ECNC0  : 1;
            uint32_t              : 1;
            __IOM uint32_t FRSC0  : 1;
            __IOM uint32_t FRDC0  : 1;
            uint32_t              : 4;
            __IOM uint32_t ANLFC0 : 1;
            __IOM uint32_t AECDC0 : 1;
            __IOM uint32_t OVFC0  : 1;
            uint32_t              : 7;
            __IOM uint32_t FSRC0  : 1;
            __IOM uint32_t FERC0  : 1;
            __IOM uint32_t LSRC0  : 1;
            __IOM uint32_t LERC0  : 1;
            uint32_t              : 4;
        } CSI2nVCSC0_b;
    };
    union
    {
        __IOM uint32_t CSI2nVCIE0;
        struct
        {
            __IOM uint32_t MLFE0 : 1;
            __IOM uint32_t ECDE0 : 1;
            __IOM uint32_t CRCE0 : 1;
            __IOM uint32_t IDEE0 : 1;
            __IOM uint32_t WCEE0 : 1;
            __IOM uint32_t ECCE0 : 1;
            __IOM uint32_t ECNE0 : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSE0 : 1;
            __IOM uint32_t FRDE0 : 1;
            uint32_t             : 6;
            __IOM uint32_t OVFE0 : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRE0 : 1;
            __IOM uint32_t FERE0 : 1;
            __IOM uint32_t LSRE0 : 1;
            __IOM uint32_t LERE0 : 1;
            uint32_t             : 4;
        } CSI2nVCIE0_b;
    };
    __IM uint8_t RESERVED25[4];
    union
    {
        __IM uint32_t CSI2nVCST1;
        struct
        {
            __IM uint32_t MLF1 : 1;
            __IM uint32_t ECD1 : 1;
            __IM uint32_t CRC1 : 1;
            __IM uint32_t IDE1 : 1;
            __IM uint32_t WCE1 : 1;
            __IM uint32_t ECC1 : 1;
            __IM uint32_t ECN1 : 1;
            uint32_t           : 1;
            __IM uint32_t FRS1 : 1;
            __IM uint32_t FRD1 : 1;
            uint32_t           : 6;
            __IM uint32_t OVF1 : 1;
            uint32_t           : 7;
            __IM uint32_t FSR1 : 1;
            __IM uint32_t FER1 : 1;
            __IM uint32_t LSR1 : 1;
            __IM uint32_t LER1 : 1;
            uint32_t           : 4;
        } CSI2nVCST1_b;
    };
    union
    {
        __IOM uint32_t CSI2nVCSC1;
        struct
        {
            __IOM uint32_t MLFC1  : 1;
            __IOM uint32_t ECDC1  : 1;
            __IOM uint32_t CRCC1  : 1;
            __IOM uint32_t IDEC1  : 1;
            __IOM uint32_t WCEC1  : 1;
            __IOM uint32_t ECCC1  : 1;
            __IOM uint32_t ECNC1  : 1;
            uint32_t              : 1;
            __IOM uint32_t FRSC1  : 1;
            __IOM uint32_t FRDC1  : 1;
            uint32_t              : 4;
            __IOM uint32_t ANLFC1 : 1;
            __IOM uint32_t AECDC1 : 1;
            __IOM uint32_t OVFC1  : 1;
            uint32_t              : 7;
            __IOM uint32_t FSRC1  : 1;
            __IOM uint32_t FERC1  : 1;
            __IOM uint32_t LSRC1  : 1;
            __IOM uint32_t LERC1  : 1;
            uint32_t              : 4;
        } CSI2nVCSC1_b;
    };
    union
    {
        __IOM uint32_t CSI2nVCIE1;
        struct
        {
            __IOM uint32_t MLFE1 : 1;
            __IOM uint32_t ECDE1 : 1;
            __IOM uint32_t CRCE1 : 1;
            __IOM uint32_t IDEE1 : 1;
            __IOM uint32_t WCEE1 : 1;
            __IOM uint32_t ECCE1 : 1;
            __IOM uint32_t ECNE1 : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSE1 : 1;
            __IOM uint32_t FRDE1 : 1;
            uint32_t             : 6;
            __IOM uint32_t OVFE1 : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRE1 : 1;
            __IOM uint32_t FERE1 : 1;
            __IOM uint32_t LSRE1 : 1;
            __IOM uint32_t LERE1 : 1;
            uint32_t             : 4;
        } CSI2nVCIE1_b;
    };
    __IM uint8_t RESERVED26[4];
    union
    {
        __IM uint32_t CSI2nVCST2;
        struct
        {
            __IM uint32_t MLF2 : 1;
            __IM uint32_t ECD2 : 1;
            __IM uint32_t CRC2 : 1;
            __IM uint32_t IDE2 : 1;
            __IM uint32_t WCE2 : 1;
            __IM uint32_t ECC2 : 1;
            __IM uint32_t ECN2 : 1;
            uint32_t           : 1;
            __IM uint32_t FRS2 : 1;
            __IM uint32_t FRD2 : 1;
            uint32_t           : 6;
            __IM uint32_t OVF2 : 1;
            uint32_t           : 7;
            __IM uint32_t FSR0 : 1;
            __IM uint32_t FER0 : 1;
            __IM uint32_t LSR0 : 1;
            __IM uint32_t LER0 : 1;
            uint32_t           : 4;
        } CSI2nVCST2_b;
    };
    union
    {
        __IOM uint32_t CSI2nVCSC2;
        struct
        {
            __IOM uint32_t MLFC2  : 1;
            __IOM uint32_t ECDC2  : 1;
            __IOM uint32_t CRCC2  : 1;
            __IOM uint32_t IDEC2  : 1;
            __IOM uint32_t WCEC2  : 1;
            __IOM uint32_t ECCC2  : 1;
            __IOM uint32_t ECNC2  : 1;
            uint32_t              : 1;
            __IOM uint32_t FRSC2  : 1;
            __IOM uint32_t FRDC2  : 1;
            uint32_t              : 4;
            __IOM uint32_t ANLFC2 : 1;
            __IOM uint32_t AECDC2 : 1;
            __IOM uint32_t OVFC2  : 1;
            uint32_t              : 7;
            __IOM uint32_t FSRC2  : 1;
            __IOM uint32_t FERC2  : 1;
            __IOM uint32_t LSRC2  : 1;
            __IOM uint32_t LERC2  : 1;
            uint32_t              : 4;
        } CSI2nVCSC2_b;
    };
    union
    {
        __IOM uint32_t CSI2nVCIE2;
        struct
        {
            __IOM uint32_t MLFE2 : 1;
            __IOM uint32_t ECDE2 : 1;
            __IOM uint32_t CRCE2 : 1;
            __IOM uint32_t IDEE2 : 1;
            __IOM uint32_t WCEE2 : 1;
            __IOM uint32_t ECCE2 : 1;
            __IOM uint32_t ECNE2 : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSE2 : 1;
            __IOM uint32_t FRDE2 : 1;
            uint32_t             : 6;
            __IOM uint32_t OVFE2 : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRE2 : 1;
            __IOM uint32_t FERE2 : 1;
            __IOM uint32_t LSRE2 : 1;
            __IOM uint32_t LERE2 : 1;
            uint32_t             : 4;
        } CSI2nVCIE2_b;
    };
    __IM uint8_t RESERVED27[4];
    union
    {
        __IM uint32_t CSI2nVCST3;
        struct
        {
            __IM uint32_t MLF3 : 1;
            __IM uint32_t ECD3 : 1;
            __IM uint32_t CRC3 : 1;
            __IM uint32_t IDE3 : 1;
            __IM uint32_t WCE3 : 1;
            __IM uint32_t ECC3 : 1;
            __IM uint32_t ECN3 : 1;
            uint32_t           : 1;
            __IM uint32_t FRS3 : 1;
            __IM uint32_t FRD3 : 1;
            uint32_t           : 6;
            __IM uint32_t OVF3 : 1;
            uint32_t           : 7;
            __IM uint32_t FSR3 : 1;
            __IM uint32_t FER3 : 1;
            __IM uint32_t LSR3 : 1;
            __IM uint32_t LER3 : 1;
            uint32_t           : 4;
        } CSI2nVCST3_b;
    };
    union
    {
        __IOM uint32_t CSI2nVCSC3;
        struct
        {
            __IOM uint32_t MLFC3  : 1;
            __IOM uint32_t ECDC3  : 1;
            __IOM uint32_t CRCC3  : 1;
            __IOM uint32_t IDEC3  : 1;
            __IOM uint32_t WCEC3  : 1;
            __IOM uint32_t ECCC3  : 1;
            __IOM uint32_t ECNC3  : 1;
            uint32_t              : 1;
            __IOM uint32_t FRSC3  : 1;
            __IOM uint32_t FRDC3  : 1;
            uint32_t              : 4;
            __IOM uint32_t ANLFC3 : 1;
            __IOM uint32_t AECDC3 : 1;
            __IOM uint32_t OVFC3  : 1;
            uint32_t              : 7;
            __IOM uint32_t FSRC3  : 1;
            __IOM uint32_t FERC3  : 1;
            __IOM uint32_t LSRC3  : 1;
            __IOM uint32_t LERC3  : 1;
            uint32_t              : 4;
        } CSI2nVCSC3_b;
    };
    union
    {
        __IOM uint32_t CSI2nVCIE3;
        struct
        {
            __IOM uint32_t MLFE3 : 1;
            __IOM uint32_t ECDE3 : 1;
            __IOM uint32_t CRCE3 : 1;
            __IOM uint32_t IDEE3 : 1;
            __IOM uint32_t WCEE3 : 1;
            __IOM uint32_t ECCE3 : 1;
            __IOM uint32_t ECNE3 : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSE3 : 1;
            __IOM uint32_t FRDE3 : 1;
            uint32_t             : 6;
            __IOM uint32_t OVFE3 : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRE3 : 1;
            __IOM uint32_t FERE3 : 1;
            __IOM uint32_t LSRE3 : 1;
            __IOM uint32_t LERE3 : 1;
            uint32_t             : 4;
        } CSI2nVCIE3_b;
    };
    __IM uint8_t RESERVED28[196];
    union
    {
        __IM uint32_t CSI2nPMST;
        struct
        {
            __IM uint32_t DSX  : 1;
            __IM uint32_t DSN  : 1;
            __IM uint32_t CSX  : 1;
            __IM uint32_t CSN  : 1;
            __IM uint32_t DUX  : 1;
            __IM uint32_t DUN  : 1;
            __IM uint32_t CUX  : 1;
            __IM uint32_t CUN  : 1;
            uint32_t           : 6;
            __IM uint32_t CLSS : 1;
            __IM uint32_t CLUL : 1;
            __IM uint32_t DLSS : 4;
            uint32_t           : 4;
            __IM uint32_t DLUL : 4;
            uint32_t           : 4;
        } CSI2nPMST_b;
    };
    union
    {
        __IOM uint32_t CSI2nPMSC;
        struct
        {
            __IOM uint32_t DSXC : 1;
            __IOM uint32_t DSNC : 1;
            __IOM uint32_t CSXC : 1;
            __IOM uint32_t CSNC : 1;
            __IOM uint32_t DUXC : 1;
            __IOM uint32_t DUNC : 1;
            __IOM uint32_t CUXC : 1;
            __IOM uint32_t CUNC : 1;
            uint32_t            : 24;
        } CSI2nPMSC_b;
    };
    union
    {
        __IOM uint32_t CSI2nPMIE;
        struct
        {
            __IOM uint32_t DSXE : 1;
            __IOM uint32_t DSNE : 1;
            __IOM uint32_t CSXE : 1;
            __IOM uint32_t CSNE : 1;
            __IOM uint32_t DUXE : 1;
            __IOM uint32_t DUNE : 1;
            __IOM uint32_t CUXE : 1;
            __IOM uint32_t CUNE : 1;
            uint32_t            : 24;
        } CSI2nPMIE_b;
    };
    __IM uint8_t RESERVED29[116];
    union
    {
        __IOM uint32_t CSI2nGSCT;
        struct
        {
            __IOM uint32_t SHITH : 7;
            uint32_t             : 9;
            __IOM uint32_t GFIF  : 1;
            uint32_t             : 15;
        } CSI2nGSCT_b;
    };
    union
    {
        __IM uint32_t CSI2nGSST;
        struct
        {
            __IM uint32_t GNE   : 1;
            __IM uint32_t GTH   : 1;
            uint32_t            : 2;
            __IM uint32_t GOV   : 1;
            uint32_t            : 3;
            __IM uint32_t PNUM  : 8;
            __IM uint32_t GCD   : 1;
            __IM uint32_t STRDS : 1;
            uint32_t            : 14;
        } CSI2nGSST_b;
    };
    union
    {
        __IOM uint32_t CSI2nGSSC;
        struct
        {
            uint32_t            : 4;
            __IOM uint32_t GOVC : 1;
            uint32_t            : 27;
        } CSI2nGSSC_b;
    };
    union
    {
        __IOM uint32_t CSI2nGSIE;
        struct
        {
            __IOM uint32_t GNEE : 1;
            __IOM uint32_t GTHE : 1;
            uint32_t            : 2;
            __IOM uint32_t GOVE : 1;
            uint32_t            : 27;
        } CSI2nGSIE_b;
    };
    union
    {
        __IM uint32_t CSI2nGSHT;
        struct
        {
            __IM uint32_t SPDT : 16;
            __IM uint32_t DTYP : 6;
            uint32_t           : 2;
            __IM uint32_t SPVC : 4;
            uint32_t           : 4;
        } CSI2nGSHT_b;
    };
    union
    {
        __IOM uint32_t CSI2nGSIU;
        struct
        {
            __IOM uint32_t FINC  : 1;
            uint32_t             : 7;
            __IOM uint32_t GFCLR : 1;
            uint32_t             : 7;
            __IOM uint32_t GFEN  : 1;
            uint32_t             : 15;
        } CSI2nGSIU_b;
    };
    __IM uint8_t RESERVED30[360];
    union
    {
        __IOM uint32_t CSIDPHYCTRL0;
        struct
        {
            __IOM uint32_t EN_BGR          : 1;
            __IOM uint32_t EN_LDO1200      : 1;
            uint32_t                       : 14;
            __IOM uint32_t CAL_EN_HSRX_OFS : 1;
            uint32_t                       : 15;
        } CSIDPHYCTRL0_b;
    };
    union
    {
        __IOM uint32_t CSIDPHYTIM0;
        struct
        {
            __IOM uint32_t T_INIT    : 19;
            uint32_t                 : 5;
            __IOM uint32_t TCLK_MISS : 8;
        } CSIDPHYTIM0_b;
    };
    union
    {
        __IOM uint32_t CSIDPHYTIM1;
        struct
        {
            __IOM uint32_t TCLK_SETTLE  : 8;
            __IOM uint32_t THS_SETTLE   : 8;
            __IOM uint32_t TCLK_PREPARE : 8;
            __IOM uint32_t THS_PREPARE  : 8;
        } CSIDPHYTIM1_b;
    };
    __IM uint8_t RESERVED31[84];
    union
    {
        __IOM uint32_t CSIDPHYSKW0;
        struct
        {
            __IOM uint32_t UTIL_DL0_SKW_ADJ : 3;
            uint32_t                        : 1;
            __IOM uint32_t UTIL_DL1_SKW_ADJ : 3;
            uint32_t                        : 1;
            __IOM uint32_t UTIL_DL2_SKW_ADJ : 3;
            uint32_t                        : 1;
            __IOM uint32_t UTIL_DL3_SKW_ADJ : 3;
            uint32_t                        : 17;
        } CSIDPHYSKW0_b;
    };
} R_CRU_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_CRU_BASE    0x10830000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_CRU    ((R_CRU_Type *) R_CRU_BASE)

#endif
