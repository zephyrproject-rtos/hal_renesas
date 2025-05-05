/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : pdm_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for pdm.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef PDM_IODEFINE_H
#define PDM_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t PDCSTRTR;
        struct
        {
            __IOM uint32_t STRTRG : 3;
            uint32_t              : 29;
        } PDCSTRTR_b;
    };
    union
    {
        __IOM uint32_t PDCSTPTR;
        struct
        {
            __IOM uint32_t STPTRG : 3;
            uint32_t              : 29;
        } PDCSTPTR_b;
    };
    union
    {
        __IOM uint32_t PDCCHGTR;
        struct
        {
            __IOM uint32_t CHGTRG : 3;
            uint32_t              : 29;
        } PDCCHGTR_b;
    };
    union
    {
        __IOM uint32_t PDCICR;
        struct
        {
            uint32_t            : 8;
            __IOM uint32_t ISDE : 3;
            uint32_t            : 5;
            __IOM uint32_t IDRE : 3;
            uint32_t            : 5;
            __IOM uint32_t IEDE : 3;
            uint32_t            : 5;
        } PDCICR_b;
    };
    union
    {
        __IM uint32_t PDCSR;
        struct
        {
            __IM uint32_t STATE : 3;
            uint32_t            : 5;
            __IM uint32_t SDF   : 3;
            uint32_t            : 5;
            __IM uint32_t DRF   : 3;
            uint32_t            : 5;
            __IM uint32_t EDF   : 3;
            uint32_t            : 5;
        } PDCSR_b;
    };
    union
    {
        __IOM uint32_t PDCSCR;
        struct
        {
            uint32_t            : 8;
            __IOM uint32_t SDFC : 3;
            uint32_t            : 21;
        } PDCSCR_b;
    };
    __IM uint8_t RESERVED[8];
    union
    {
        __IOM uint32_t PDCSDCR;
        struct
        {
            __IOM uint32_t SDE : 3;
            uint32_t           : 29;
        } PDCSDCR_b;
    };
    union
    {
        __IOM uint32_t PDCDRCR;
        struct
        {
            __IOM uint32_t DATRE : 3;
            uint32_t             : 29;
        } PDCDRCR_b;
    };
    union
    {
        __IOM uint32_t PDCDCR;
        struct
        {
            __IOM uint32_t DATC : 3;
            uint32_t            : 29;
        } PDCDCR_b;
    };
    __IM uint8_t RESERVED1[84];
    union
    {
        __IM uint32_t PDVR;
        struct
        {
            __IM uint32_t VER : 12;
            uint32_t          : 20;
        } PDVR_b;
    };
    __IM uint8_t RESERVED2[124];
    union
    {
        __IOM uint32_t PDSTRTRCH0;
        struct
        {
            __IOM uint32_t STRTRG : 1;
            uint32_t              : 31;
        } PDSTRTRCH0_b;
    };
    union
    {
        __IOM uint32_t PDSTPTRCH0;
        struct
        {
            __IOM uint32_t STPTRG : 1;
            uint32_t              : 31;
        } PDSTPTRCH0_b;
    };
    union
    {
        __IOM uint32_t PDCHGTRCH0;
        struct
        {
            __IOM uint32_t CHGTRG : 1;
            uint32_t              : 31;
        } PDCHGTRCH0_b;
    };
    union
    {
        __IOM uint32_t PDICRCH0;
        struct
        {
            uint32_t            : 1;
            __IOM uint32_t ISDE : 1;
            __IOM uint32_t IDRE : 1;
            uint32_t            : 13;
            __IOM uint32_t IEDE : 1;
            uint32_t            : 15;
        } PDICRCH0_b;
    };
    union
    {
        __IOM uint32_t PDSDCRCH0;
        struct
        {
            uint32_t              : 1;
            __IOM uint32_t SDE    : 1;
            uint32_t              : 14;
            __IOM uint32_t SCDE   : 1;
            __IOM uint32_t OVLDE  : 1;
            __IOM uint32_t OVUDE  : 1;
            uint32_t              : 8;
            __IOM uint32_t BFOWDE : 1;
            uint32_t              : 4;
        } PDSDCRCH0_b;
    };
    union
    {
        __IM uint32_t PDSRCH0;
        struct
        {
            __IM uint32_t STATE  : 1;
            __IM uint32_t SDF    : 1;
            __IM uint32_t DRF    : 1;
            uint32_t             : 13;
            __IM uint32_t SCDF   : 1;
            __IM uint32_t OVLDF  : 1;
            __IM uint32_t OVUDF  : 1;
            uint32_t             : 8;
            __IM uint32_t BFOWDF : 1;
            uint32_t             : 4;
        } PDSRCH0_b;
    };
    union
    {
        __IOM uint32_t PDSCRCH0;
        struct
        {
            uint32_t               : 1;
            __IOM uint32_t SDFC    : 1;
            uint32_t               : 14;
            __IOM uint32_t SCDFC   : 1;
            __IOM uint32_t OVLDFC  : 1;
            __IOM uint32_t OVUDFC  : 1;
            uint32_t               : 8;
            __IOM uint32_t BFOWDFC : 1;
            uint32_t               : 4;
        } PDSCRCH0_b;
    };
    __IM uint8_t RESERVED3[4];
    union
    {
        __IOM uint32_t PDMDSRCH0;
        struct
        {
            __IOM uint32_t INPSEL : 1;
            uint32_t              : 3;
            __IOM uint32_t SFMD   : 3;
            uint32_t              : 1;
            __IOM uint32_t HFIS   : 2;
            uint32_t              : 2;
            __IOM uint32_t CFIS   : 2;
            uint32_t              : 2;
            __IOM uint32_t LFIS   : 2;
            uint32_t              : 6;
            __IOM uint32_t SDMAMD : 2;
            uint32_t              : 2;
            __IOM uint32_t DBIS   : 4;
        } PDMDSRCH0_b;
    };
    union
    {
        __IOM uint32_t PDSFCRCH0;
        struct
        {
            __IOM uint32_t CKDIV   : 4;
            uint32_t               : 12;
            __IOM uint32_t SINCDEC : 8;
            __IOM uint32_t SINCRNG : 5;
            uint32_t               : 3;
        } PDSFCRCH0_b;
    };
    union
    {
        __IOM uint32_t PDHFCS0RCH0;
        struct
        {
            __IOM uint32_t HFSm : 16;
            uint32_t            : 16;
        } PDHFCS0RCH0_b;
    };
    union
    {
        __IOM uint32_t PDHFCK1RCH0;
        struct
        {
            __IOM uint32_t HFKm : 16;
            uint32_t            : 16;
        } PDHFCK1RCH0_b;
    };
    union
    {
        __IOM uint32_t PDHFCH0RCH0;
        struct
        {
            __IOM uint32_t HFH0 : 16;
            uint32_t            : 16;
        } PDHFCH0RCH0_b;
    };
    union
    {
        __IOM uint32_t PDHFCH1RCH0;
        struct
        {
            __IOM uint32_t HFH1 : 16;
            uint32_t            : 16;
        } PDHFCH1RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH00RCH0;
        struct
        {
            __IOM uint32_t CFH00 : 13;
            uint32_t             : 19;
        } PDCFCH00RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH01RCH0;
        struct
        {
            __IOM uint32_t CFH01 : 13;
            uint32_t             : 19;
        } PDCFCH01RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH02RCH0;
        struct
        {
            __IOM uint32_t CFH02 : 13;
            uint32_t             : 19;
        } PDCFCH02RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH03RCH0;
        struct
        {
            __IOM uint32_t CFH03 : 13;
            uint32_t             : 19;
        } PDCFCH03RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH04RCH0;
        struct
        {
            __IOM uint32_t CFH04 : 13;
            uint32_t             : 19;
        } PDCFCH04RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH05RCH0;
        struct
        {
            __IOM uint32_t CFH05 : 13;
            uint32_t             : 19;
        } PDCFCH05RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH06RCH0;
        struct
        {
            __IOM uint32_t CFH06 : 13;
            uint32_t             : 19;
        } PDCFCH06RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH07RCH0;
        struct
        {
            __IOM uint32_t CFH07 : 13;
            uint32_t             : 19;
        } PDCFCH07RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH08RCH0;
        struct
        {
            __IOM uint32_t CFH08 : 13;
            uint32_t             : 19;
        } PDCFCH08RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH09RCH0;
        struct
        {
            __IOM uint32_t CFH09 : 13;
            uint32_t             : 19;
        } PDCFCH09RCH0_b;
    };
    union
    {
        __IOM uint32_t PDCFCH10RCH0;
        struct
        {
            __IOM uint32_t CFH10 : 13;
            uint32_t             : 19;
        } PDCFCH10RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH010RCH0;
        struct
        {
            __IOM uint32_t LFH010 : 13;
            uint32_t              : 19;
        } PDLFCH010RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH100RCH0;
        struct
        {
            __IOM uint32_t LFH100 : 13;
            uint32_t              : 19;
        } PDLFCH100RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH101RCH0;
        struct
        {
            __IOM uint32_t LFH101 : 13;
            uint32_t              : 19;
        } PDLFCH101RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH102RCH0;
        struct
        {
            __IOM uint32_t LFH102 : 13;
            uint32_t              : 19;
        } PDLFCH102RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH103RCH0;
        struct
        {
            __IOM uint32_t LFH103 : 13;
            uint32_t              : 19;
        } PDLFCH103RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH104RCH0;
        struct
        {
            __IOM uint32_t LFH104 : 13;
            uint32_t              : 19;
        } PDLFCH104RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH105RCH0;
        struct
        {
            __IOM uint32_t LFH105 : 13;
            uint32_t              : 19;
        } PDLFCH105RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH106RCH0;
        struct
        {
            __IOM uint32_t LFH106 : 13;
            uint32_t              : 19;
        } PDLFCH106RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH107RCH0;
        struct
        {
            __IOM uint32_t LFH107 : 13;
            uint32_t              : 19;
        } PDLFCH107RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH108RCH0;
        struct
        {
            __IOM uint32_t LFH108 : 13;
            uint32_t              : 19;
        } PDLFCH108RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH109RCH0;
        struct
        {
            __IOM uint32_t LFH109 : 13;
            uint32_t              : 19;
        } PDLFCH109RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH110RCH0;
        struct
        {
            __IOM uint32_t LFH110 : 13;
            uint32_t              : 19;
        } PDLFCH110RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH111RCH0;
        struct
        {
            __IOM uint32_t LFH111 : 13;
            uint32_t              : 19;
        } PDLFCH111RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH112RCH0;
        struct
        {
            __IOM uint32_t LFH112 : 13;
            uint32_t              : 19;
        } PDLFCH112RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH113RCH0;
        struct
        {
            __IOM uint32_t LFH113 : 13;
            uint32_t              : 19;
        } PDLFCH113RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH114RCH0;
        struct
        {
            __IOM uint32_t LFH114 : 13;
            uint32_t              : 19;
        } PDLFCH114RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH115RCH0;
        struct
        {
            __IOM uint32_t LFH115 : 13;
            uint32_t              : 19;
        } PDLFCH115RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH116RCH0;
        struct
        {
            __IOM uint32_t LFH116 : 13;
            uint32_t              : 19;
        } PDLFCH116RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH117RCH0;
        struct
        {
            __IOM uint32_t LFH117 : 13;
            uint32_t              : 19;
        } PDLFCH117RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH118RCH0;
        struct
        {
            __IOM uint32_t LFH118 : 13;
            uint32_t              : 19;
        } PDLFCH118RCH0_b;
    };
    union
    {
        __IOM uint32_t PDLFCH119RCH0;
        struct
        {
            __IOM uint32_t LFH119 : 13;
            uint32_t              : 19;
        } PDLFCH119RCH0_b;
    };
    union
    {
        __IOM uint32_t PDSDLTRCH0;
        struct
        {
            __IOM uint32_t SDETL : 20;
            uint32_t             : 12;
        } PDSDLTRCH0_b;
    };
    union
    {
        __IOM uint32_t PDSDUTRCH0;
        struct
        {
            __IOM uint32_t SDETU : 20;
            uint32_t             : 12;
        } PDSDUTRCH0_b;
    };
    union
    {
        __IOM uint32_t PDDBCRCH0;
        struct
        {
            __IOM uint32_t DATRITHR : 3;
            uint32_t                : 29;
        } PDDBCRCH0_b;
    };
    union
    {
        __IOM uint32_t PDSCTSRCH0;
        struct
        {
            __IOM uint32_t SCDL : 13;
            uint32_t            : 3;
            __IOM uint32_t SCDH : 13;
            uint32_t            : 3;
        } PDSCTSRCH0_b;
    };
    union
    {
        __IOM uint32_t PDOVLTRCH0;
        struct
        {
            __IOM uint32_t OVDL : 20;
            uint32_t            : 12;
        } PDOVLTRCH0_b;
    };
    union
    {
        __IOM uint32_t PDOVUTRCH0;
        struct
        {
            __IOM uint32_t OVDU : 20;
            uint32_t            : 12;
        } PDOVUTRCH0_b;
    };
    __IM uint8_t RESERVED4[16];
    union
    {
        __IOM uint32_t PDDRCRCH0;
        struct
        {
            __IOM uint32_t DATRE : 1;
            uint32_t             : 31;
        } PDDRCRCH0_b;
    };
    union
    {
        __IOM uint32_t PDDCRCH0;
        struct
        {
            __IOM uint32_t DATC : 1;
            uint32_t            : 31;
        } PDDCRCH0_b;
    };
    union
    {
        __IM uint32_t PDDRRCH0;
        struct
        {
            __IM uint32_t DAT : 20;
            uint32_t          : 12;
        } PDDRRCH0_b;
    };
    union
    {
        __IM uint32_t PDDSRCH0;
        struct
        {
            __IM uint32_t DATNUM : 8;
            uint32_t             : 24;
        } PDDSRCH0_b;
    };
    __IM uint8_t RESERVED5[16];
    union
    {
        __IOM uint32_t PDSTRTRCH1;
        struct
        {
            __IOM uint32_t STRTRG : 1;
            uint32_t              : 31;
        } PDSTRTRCH1_b;
    };
    union
    {
        __IOM uint32_t PDSTPTRCH1;
        struct
        {
            __IOM uint32_t STPTRG : 1;
            uint32_t              : 31;
        } PDSTPTRCH1_b;
    };
    union
    {
        __IOM uint32_t PDCHGTRCH1;
        struct
        {
            __IOM uint32_t CHGTRG : 1;
            uint32_t              : 31;
        } PDCHGTRCH1_b;
    };
    union
    {
        __IOM uint32_t PDICRCH1;
        struct
        {
            uint32_t            : 1;
            __IOM uint32_t ISDE : 1;
            __IOM uint32_t IDRE : 1;
            uint32_t            : 13;
            __IOM uint32_t IEDE : 1;
            uint32_t            : 15;
        } PDICRCH1_b;
    };
    union
    {
        __IOM uint32_t PDSDCRCH1;
        struct
        {
            uint32_t              : 1;
            __IOM uint32_t SDE    : 1;
            uint32_t              : 14;
            __IOM uint32_t SCDE   : 1;
            __IOM uint32_t OVLDE  : 1;
            __IOM uint32_t OVUDE  : 1;
            uint32_t              : 8;
            __IOM uint32_t BFOWDE : 1;
            uint32_t              : 4;
        } PDSDCRCH1_b;
    };
    union
    {
        __IM uint32_t PDSRCH1;
        struct
        {
            __IM uint32_t STATE  : 1;
            __IM uint32_t SDF    : 1;
            __IM uint32_t DRF    : 1;
            uint32_t             : 13;
            __IM uint32_t SCDF   : 1;
            __IM uint32_t OVLDF  : 1;
            __IM uint32_t OVUDF  : 1;
            uint32_t             : 8;
            __IM uint32_t BFOWDF : 1;
            uint32_t             : 4;
        } PDSRCH1_b;
    };
    union
    {
        __IOM uint32_t PDSCRCH1;
        struct
        {
            uint32_t               : 1;
            __IOM uint32_t SDFC    : 1;
            uint32_t               : 14;
            __IOM uint32_t SCDFC   : 1;
            __IOM uint32_t OVLDFC  : 1;
            __IOM uint32_t OVUDFC  : 1;
            uint32_t               : 8;
            __IOM uint32_t BFOWDFC : 1;
            uint32_t               : 4;
        } PDSCRCH1_b;
    };
    __IM uint8_t RESERVED6[4];
    union
    {
        __IOM uint32_t PDMDSRCH1;
        struct
        {
            __IOM uint32_t INPSEL : 1;
            uint32_t              : 3;
            __IOM uint32_t SFMD   : 3;
            uint32_t              : 1;
            __IOM uint32_t HFIS   : 2;
            uint32_t              : 2;
            __IOM uint32_t CFIS   : 2;
            uint32_t              : 2;
            __IOM uint32_t LFIS   : 2;
            uint32_t              : 6;
            __IOM uint32_t SDMAMD : 2;
            uint32_t              : 2;
            __IOM uint32_t DBIS   : 4;
        } PDMDSRCH1_b;
    };
    union
    {
        __IOM uint32_t PDSFCRCH1;
        struct
        {
            __IOM uint32_t CKDIV   : 4;
            uint32_t               : 12;
            __IOM uint32_t SINCDEC : 8;
            __IOM uint32_t SINCRNG : 5;
            uint32_t               : 3;
        } PDSFCRCH1_b;
    };
    union
    {
        __IOM uint32_t PDHFCS0RCH1;
        struct
        {
            __IOM uint32_t HFSm : 16;
            uint32_t            : 16;
        } PDHFCS0RCH1_b;
    };
    union
    {
        __IOM uint32_t PDHFCK1RCH1;
        struct
        {
            __IOM uint32_t HFKm : 16;
            uint32_t            : 16;
        } PDHFCK1RCH1_b;
    };
    union
    {
        __IOM uint32_t PDHFCH0RCH1;
        struct
        {
            __IOM uint32_t HFH0 : 16;
            uint32_t            : 16;
        } PDHFCH0RCH1_b;
    };
    union
    {
        __IOM uint32_t PDHFCH1RCH1;
        struct
        {
            __IOM uint32_t HFH1 : 16;
            uint32_t            : 16;
        } PDHFCH1RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH00RCH1;
        struct
        {
            __IOM uint32_t CFH00 : 13;
            uint32_t             : 19;
        } PDCFCH00RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH01RCH1;
        struct
        {
            __IOM uint32_t CFH01 : 13;
            uint32_t             : 19;
        } PDCFCH01RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH02RCH1;
        struct
        {
            __IOM uint32_t CFH02 : 13;
            uint32_t             : 19;
        } PDCFCH02RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH03RCH1;
        struct
        {
            __IOM uint32_t CFH03 : 13;
            uint32_t             : 19;
        } PDCFCH03RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH04RCH1;
        struct
        {
            __IOM uint32_t CFH04 : 13;
            uint32_t             : 19;
        } PDCFCH04RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH05RCH1;
        struct
        {
            __IOM uint32_t CFH05 : 13;
            uint32_t             : 19;
        } PDCFCH05RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH06RCH1;
        struct
        {
            __IOM uint32_t CFH06 : 13;
            uint32_t             : 19;
        } PDCFCH06RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH07RCH1;
        struct
        {
            __IOM uint32_t CFH07 : 13;
            uint32_t             : 19;
        } PDCFCH07RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH08RCH1;
        struct
        {
            __IOM uint32_t CFH08 : 13;
            uint32_t             : 19;
        } PDCFCH08RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH09RCH1;
        struct
        {
            __IOM uint32_t CFH09 : 13;
            uint32_t             : 19;
        } PDCFCH09RCH1_b;
    };
    union
    {
        __IOM uint32_t PDCFCH10RCH1;
        struct
        {
            __IOM uint32_t CFH10 : 13;
            uint32_t             : 19;
        } PDCFCH10RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH010RCH1;
        struct
        {
            __IOM uint32_t LFH010 : 13;
            uint32_t              : 19;
        } PDLFCH010RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH100RCH1;
        struct
        {
            __IOM uint32_t LFH100 : 13;
            uint32_t              : 19;
        } PDLFCH100RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH101RCH1;
        struct
        {
            __IOM uint32_t LFH101 : 13;
            uint32_t              : 19;
        } PDLFCH101RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH102RCH1;
        struct
        {
            __IOM uint32_t LFH102 : 13;
            uint32_t              : 19;
        } PDLFCH102RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH103RCH1;
        struct
        {
            __IOM uint32_t LFH103 : 13;
            uint32_t              : 19;
        } PDLFCH103RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH104RCH1;
        struct
        {
            __IOM uint32_t LFH104 : 13;
            uint32_t              : 19;
        } PDLFCH104RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH105RCH1;
        struct
        {
            __IOM uint32_t LFH105 : 13;
            uint32_t              : 19;
        } PDLFCH105RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH106RCH1;
        struct
        {
            __IOM uint32_t LFH106 : 13;
            uint32_t              : 19;
        } PDLFCH106RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH107RCH1;
        struct
        {
            __IOM uint32_t LFH107 : 13;
            uint32_t              : 19;
        } PDLFCH107RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH108RCH1;
        struct
        {
            __IOM uint32_t LFH108 : 13;
            uint32_t              : 19;
        } PDLFCH108RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH109RCH1;
        struct
        {
            __IOM uint32_t LFH109 : 13;
            uint32_t              : 19;
        } PDLFCH109RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH110RCH1;
        struct
        {
            __IOM uint32_t LFH110 : 13;
            uint32_t              : 19;
        } PDLFCH110RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH111RCH1;
        struct
        {
            __IOM uint32_t LFH111 : 13;
            uint32_t              : 19;
        } PDLFCH111RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH112RCH1;
        struct
        {
            __IOM uint32_t LFH112 : 13;
            uint32_t              : 19;
        } PDLFCH112RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH113RCH1;
        struct
        {
            __IOM uint32_t LFH113 : 13;
            uint32_t              : 19;
        } PDLFCH113RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH114RCH1;
        struct
        {
            __IOM uint32_t LFH114 : 13;
            uint32_t              : 19;
        } PDLFCH114RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH115RCH1;
        struct
        {
            __IOM uint32_t LFH115 : 13;
            uint32_t              : 19;
        } PDLFCH115RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH116RCH1;
        struct
        {
            __IOM uint32_t LFH116 : 13;
            uint32_t              : 19;
        } PDLFCH116RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH117RCH1;
        struct
        {
            __IOM uint32_t LFH117 : 13;
            uint32_t              : 19;
        } PDLFCH117RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH118RCH1;
        struct
        {
            __IOM uint32_t LFH118 : 13;
            uint32_t              : 19;
        } PDLFCH118RCH1_b;
    };
    union
    {
        __IOM uint32_t PDLFCH119RCH1;
        struct
        {
            __IOM uint32_t LFH119 : 13;
            uint32_t              : 19;
        } PDLFCH119RCH1_b;
    };
    union
    {
        __IOM uint32_t PDSDLTRCH1;
        struct
        {
            __IOM uint32_t SDETL : 20;
            uint32_t             : 12;
        } PDSDLTRCH1_b;
    };
    union
    {
        __IOM uint32_t PDSDUTRCH1;
        struct
        {
            __IOM uint32_t SDETU : 20;
            uint32_t             : 12;
        } PDSDUTRCH1_b;
    };
    union
    {
        __IOM uint32_t PDDBCRCH1;
        struct
        {
            __IOM uint32_t DATRITHR : 3;
            uint32_t                : 29;
        } PDDBCRCH1_b;
    };
    union
    {
        __IOM uint32_t PDSCTSRCH1;
        struct
        {
            __IOM uint32_t SCDL : 13;
            uint32_t            : 3;
            __IOM uint32_t SCDH : 13;
            uint32_t            : 3;
        } PDSCTSRCH1_b;
    };
    union
    {
        __IOM uint32_t PDOVLTRCH1;
        struct
        {
            __IOM uint32_t OVDL : 20;
            uint32_t            : 12;
        } PDOVLTRCH1_b;
    };
    union
    {
        __IOM uint32_t PDOVUTRCH1;
        struct
        {
            __IOM uint32_t OVDU : 20;
            uint32_t            : 12;
        } PDOVUTRCH1_b;
    };
    __IM uint8_t RESERVED7[16];
    union
    {
        __IOM uint32_t PDDRCRCH1;
        struct
        {
            __IOM uint32_t DATRE : 1;
            uint32_t             : 31;
        } PDDRCRCH1_b;
    };
    union
    {
        __IOM uint32_t PDDCRCH1;
        struct
        {
            __IOM uint32_t DATC : 1;
            uint32_t            : 31;
        } PDDCRCH1_b;
    };
    union
    {
        __IM uint32_t PDDRRCH1;
        struct
        {
            __IM uint32_t DAT : 20;
            uint32_t          : 12;
        } PDDRRCH1_b;
    };
    union
    {
        __IM uint32_t PDDSRCH1;
        struct
        {
            __IM uint32_t DATNUM : 8;
            uint32_t             : 24;
        } PDDSRCH1_b;
    };
    __IM uint8_t RESERVED8[16];
    union
    {
        __IOM uint32_t PDSTRTRCH2;
        struct
        {
            __IOM uint32_t STRTRG : 1;
            uint32_t              : 31;
        } PDSTRTRCH2_b;
    };
    union
    {
        __IOM uint32_t PDSTPTRCH2;
        struct
        {
            __IOM uint32_t STPTRG : 1;
            uint32_t              : 31;
        } PDSTPTRCH2_b;
    };
    union
    {
        __IOM uint32_t PDCHGTRCH2;
        struct
        {
            __IOM uint32_t CHGTRG : 1;
            uint32_t              : 31;
        } PDCHGTRCH2_b;
    };
    union
    {
        __IOM uint32_t PDICRCH2;
        struct
        {
            uint32_t            : 1;
            __IOM uint32_t ISDE : 1;
            __IOM uint32_t IDRE : 1;
            uint32_t            : 13;
            __IOM uint32_t IEDE : 1;
            uint32_t            : 15;
        } PDICRCH2_b;
    };
    union
    {
        __IOM uint32_t PDSDCRCH2;
        struct
        {
            uint32_t              : 1;
            __IOM uint32_t SDE    : 1;
            uint32_t              : 14;
            __IOM uint32_t SCDE   : 1;
            __IOM uint32_t OVLDE  : 1;
            __IOM uint32_t OVUDE  : 1;
            uint32_t              : 8;
            __IOM uint32_t BFOWDE : 1;
            uint32_t              : 4;
        } PDSDCRCH2_b;
    };
    union
    {
        __IM uint32_t PDSRCH2;
        struct
        {
            __IM uint32_t STATE  : 1;
            __IM uint32_t SDF    : 1;
            __IM uint32_t DRF    : 1;
            uint32_t             : 13;
            __IM uint32_t SCDF   : 1;
            __IM uint32_t OVLDF  : 1;
            __IM uint32_t OVUDF  : 1;
            uint32_t             : 8;
            __IM uint32_t BFOWDF : 1;
            uint32_t             : 4;
        } PDSRCH2_b;
    };
    union
    {
        __IOM uint32_t PDSCRCH2;
        struct
        {
            uint32_t               : 1;
            __IOM uint32_t SDFC    : 1;
            uint32_t               : 14;
            __IOM uint32_t SCDFC   : 1;
            __IOM uint32_t OVLDFC  : 1;
            __IOM uint32_t OVUDFC  : 1;
            uint32_t               : 8;
            __IOM uint32_t BFOWDFC : 1;
            uint32_t               : 4;
        } PDSCRCH2_b;
    };
    __IM uint8_t RESERVED9[4];
    union
    {
        __IOM uint32_t PDMDSRCH2;
        struct
        {
            __IOM uint32_t INPSEL : 1;
            uint32_t              : 3;
            __IOM uint32_t SFMD   : 3;
            uint32_t              : 1;
            __IOM uint32_t HFIS   : 2;
            uint32_t              : 2;
            __IOM uint32_t CFIS   : 2;
            uint32_t              : 2;
            __IOM uint32_t LFIS   : 2;
            uint32_t              : 6;
            __IOM uint32_t SDMAMD : 2;
            uint32_t              : 2;
            __IOM uint32_t DBIS   : 4;
        } PDMDSRCH2_b;
    };
    union
    {
        __IOM uint32_t PDSFCRCH2;
        struct
        {
            __IOM uint32_t CKDIV   : 4;
            uint32_t               : 12;
            __IOM uint32_t SINCDEC : 8;
            __IOM uint32_t SINCRNG : 5;
            uint32_t               : 3;
        } PDSFCRCH2_b;
    };
    union
    {
        __IOM uint32_t PDHFCS0RCH2;
        struct
        {
            __IOM uint32_t HFSm : 16;
            uint32_t            : 16;
        } PDHFCS0RCH2_b;
    };
    union
    {
        __IOM uint32_t PDHFCK1RCH2;
        struct
        {
            __IOM uint32_t HFKm : 16;
            uint32_t            : 16;
        } PDHFCK1RCH2_b;
    };
    union
    {
        __IOM uint32_t PDHFCH0RCH2;
        struct
        {
            __IOM uint32_t HFH0 : 16;
            uint32_t            : 16;
        } PDHFCH0RCH2_b;
    };
    union
    {
        __IOM uint32_t PDHFCH1RCH2;
        struct
        {
            __IOM uint32_t HFH1 : 16;
            uint32_t            : 16;
        } PDHFCH1RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH00RCH2;
        struct
        {
            __IOM uint32_t CFH00 : 13;
            uint32_t             : 19;
        } PDCFCH00RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH01RCH2;
        struct
        {
            __IOM uint32_t CFH01 : 13;
            uint32_t             : 19;
        } PDCFCH01RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH02RCH2;
        struct
        {
            __IOM uint32_t CFH02 : 13;
            uint32_t             : 19;
        } PDCFCH02RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH03RCH2;
        struct
        {
            __IOM uint32_t CFH03 : 13;
            uint32_t             : 19;
        } PDCFCH03RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH04RCH2;
        struct
        {
            __IOM uint32_t CFH04 : 13;
            uint32_t             : 19;
        } PDCFCH04RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH05RCH2;
        struct
        {
            __IOM uint32_t CFH05 : 13;
            uint32_t             : 19;
        } PDCFCH05RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH06RCH2;
        struct
        {
            __IOM uint32_t CFH06 : 13;
            uint32_t             : 19;
        } PDCFCH06RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH07RCH2;
        struct
        {
            __IOM uint32_t CFH07 : 13;
            uint32_t             : 19;
        } PDCFCH07RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH08RCH2;
        struct
        {
            __IOM uint32_t CFH08 : 13;
            uint32_t             : 19;
        } PDCFCH08RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH09RCH2;
        struct
        {
            __IOM uint32_t CFH09 : 13;
            uint32_t             : 19;
        } PDCFCH09RCH2_b;
    };
    union
    {
        __IOM uint32_t PDCFCH10RCH2;
        struct
        {
            __IOM uint32_t CFH10 : 13;
            uint32_t             : 19;
        } PDCFCH10RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH010RCH2;
        struct
        {
            __IOM uint32_t LFH010 : 13;
            uint32_t              : 19;
        } PDLFCH010RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH100RCH2;
        struct
        {
            __IOM uint32_t LFH100 : 13;
            uint32_t              : 19;
        } PDLFCH100RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH101RCH2;
        struct
        {
            __IOM uint32_t LFH101 : 13;
            uint32_t              : 19;
        } PDLFCH101RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH102RCH2;
        struct
        {
            __IOM uint32_t LFH102 : 13;
            uint32_t              : 19;
        } PDLFCH102RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH103RCH2;
        struct
        {
            __IOM uint32_t LFH103 : 13;
            uint32_t              : 19;
        } PDLFCH103RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH104RCH2;
        struct
        {
            __IOM uint32_t LFH104 : 13;
            uint32_t              : 19;
        } PDLFCH104RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH105RCH2;
        struct
        {
            __IOM uint32_t LFH105 : 13;
            uint32_t              : 19;
        } PDLFCH105RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH106RCH2;
        struct
        {
            __IOM uint32_t LFH106 : 13;
            uint32_t              : 19;
        } PDLFCH106RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH107RCH2;
        struct
        {
            __IOM uint32_t LFH107 : 13;
            uint32_t              : 19;
        } PDLFCH107RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH108RCH2;
        struct
        {
            __IOM uint32_t LFH108 : 13;
            uint32_t              : 19;
        } PDLFCH108RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH109RCH2;
        struct
        {
            __IOM uint32_t LFH109 : 13;
            uint32_t              : 19;
        } PDLFCH109RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH110RCH2;
        struct
        {
            __IOM uint32_t LFH110 : 13;
            uint32_t              : 19;
        } PDLFCH110RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH111RCH2;
        struct
        {
            __IOM uint32_t LFH111 : 13;
            uint32_t              : 19;
        } PDLFCH111RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH112RCH2;
        struct
        {
            __IOM uint32_t LFH112 : 13;
            uint32_t              : 19;
        } PDLFCH112RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH113RCH2;
        struct
        {
            __IOM uint32_t LFH113 : 13;
            uint32_t              : 19;
        } PDLFCH113RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH114RCH2;
        struct
        {
            __IOM uint32_t LFH114 : 13;
            uint32_t              : 19;
        } PDLFCH114RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH115RCH2;
        struct
        {
            __IOM uint32_t LFH115 : 13;
            uint32_t              : 19;
        } PDLFCH115RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH116RCH2;
        struct
        {
            __IOM uint32_t LFH116 : 13;
            uint32_t              : 19;
        } PDLFCH116RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH117RCH2;
        struct
        {
            __IOM uint32_t LFH117 : 13;
            uint32_t              : 19;
        } PDLFCH117RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH118RCH2;
        struct
        {
            __IOM uint32_t LFH118 : 13;
            uint32_t              : 19;
        } PDLFCH118RCH2_b;
    };
    union
    {
        __IOM uint32_t PDLFCH119RCH2;
        struct
        {
            __IOM uint32_t LFH119 : 13;
            uint32_t              : 19;
        } PDLFCH119RCH2_b;
    };
    union
    {
        __IOM uint32_t PDSDLTRCH2;
        struct
        {
            __IOM uint32_t SDETL : 20;
            uint32_t             : 12;
        } PDSDLTRCH2_b;
    };
    union
    {
        __IOM uint32_t PDSDUTRCH2;
        struct
        {
            __IOM uint32_t SDETU : 20;
            uint32_t             : 12;
        } PDSDUTRCH2_b;
    };
    union
    {
        __IOM uint32_t PDDBCRCH2;
        struct
        {
            __IOM uint32_t DATRITHR : 3;
            uint32_t                : 29;
        } PDDBCRCH2_b;
    };
    union
    {
        __IOM uint32_t PDSCTSRCH2;
        struct
        {
            __IOM uint32_t SCDL : 13;
            uint32_t            : 3;
            __IOM uint32_t SCDH : 13;
            uint32_t            : 3;
        } PDSCTSRCH2_b;
    };
    union
    {
        __IOM uint32_t PDOVLTRCH2;
        struct
        {
            __IOM uint32_t OVDL : 20;
            uint32_t            : 12;
        } PDOVLTRCH2_b;
    };
    union
    {
        __IOM uint32_t PDOVUTRCH2;
        struct
        {
            __IOM uint32_t OVDU : 20;
            uint32_t            : 12;
        } PDOVUTRCH2_b;
    };
    __IM uint8_t RESERVED10[16];
    union
    {
        __IOM uint32_t PDDRCRCH2;
        struct
        {
            __IOM uint32_t DATRE : 1;
            uint32_t             : 31;
        } PDDRCRCH2_b;
    };
    union
    {
        __IOM uint32_t PDDCRCH2;
        struct
        {
            __IOM uint32_t DATC : 1;
            uint32_t            : 31;
        } PDDCRCH2_b;
    };
    union
    {
        __IM uint32_t PDDRRCH2;
        struct
        {
            __IM uint32_t DAT : 20;
            uint32_t          : 12;
        } PDDRRCH2_b;
    };
    union
    {
        __IM uint32_t PDDSRCH2;
        struct
        {
            __IM uint32_t DATNUM : 8;
            uint32_t             : 24;
        } PDDSRCH2_b;
    };
} R_PDM0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_PDM0_BASE    0x41040000
#define R_PDM1_BASE    0x41050000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_PDM0    ((R_PDM0_Type *) R_PDM0_BASE)
#define R_PDM1    ((R_PDM0_Type *) R_PDM1_BASE)

#endif
