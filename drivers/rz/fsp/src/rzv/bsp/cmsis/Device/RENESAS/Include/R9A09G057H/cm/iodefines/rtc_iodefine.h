/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : rtc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for rtc.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef RTC_IODEFINE_H
#define RTC_IODEFINE_H

typedef struct
{
    union
    {
        __IM uint8_t R64CNT;
        struct
        {
            __IM uint8_t F64HZ : 1;
            __IM uint8_t F32HZ : 1;
            __IM uint8_t F16HZ : 1;
            __IM uint8_t F8HZ  : 1;
            __IM uint8_t F4HZ  : 1;
            __IM uint8_t F2HZ  : 1;
            __IM uint8_t F1HZ  : 1;
            uint8_t            : 1;
        } R64CNT_b;
    };
    __IM uint8_t RESERVED[1];
    union
    {
        union
        {
            __IOM uint8_t RSECCNT;
            struct
            {
                __IOM uint8_t SEC1  : 4;
                __IOM uint8_t SEC10 : 3;
                uint8_t             : 1;
            } RSECCNT_b;
        };
        union
        {
            __IOM uint8_t BCNT0;
            struct
            {
                __IOM uint8_t BCNT : 8;
            } BCNT0_b;
        };
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        union
        {
            __IOM uint8_t RMINCNT;
            struct
            {
                __IOM uint8_t MIN1  : 4;
                __IOM uint8_t MIN10 : 3;
                uint8_t             : 1;
            } RMINCNT_b;
        };
        union
        {
            __IOM uint8_t BCNT1;
            struct
            {
                __IOM uint8_t BCNT : 8;
            } BCNT1_b;
        };
    };
    __IM uint8_t RESERVED2[1];
    union
    {
        union
        {
            __IOM uint8_t RHRCNT;
            struct
            {
                __IOM uint8_t HR1  : 4;
                __IOM uint8_t HR10 : 2;
                __IOM uint8_t PM   : 1;
                uint8_t            : 1;
            } RHRCNT_b;
        };
        union
        {
            __IOM uint8_t BCNT2;
            struct
            {
                __IOM uint8_t BCNT : 8;
            } BCNT2_b;
        };
    };
    __IM uint8_t RESERVED3[1];
    union
    {
        union
        {
            __IOM uint8_t RWKCNT;
            struct
            {
                __IOM uint8_t DAYW : 3;
                uint8_t            : 5;
            } RWKCNT_b;
        };
        union
        {
            __IOM uint8_t BCNT3;
            struct
            {
                __IOM uint8_t BCNT : 8;
            } BCNT3_b;
        };
    };
    __IM uint8_t RESERVED4[1];
    union
    {
        __IOM uint8_t RDAYCNT;
        struct
        {
            __IOM uint8_t DATE1  : 4;
            __IOM uint8_t DATE10 : 2;
            uint8_t              : 2;
        } RDAYCNT_b;
    };
    __IM uint8_t RESERVED5[1];
    union
    {
        __IOM uint8_t RMONCNT;
        struct
        {
            __IOM uint8_t MON1  : 4;
            __IOM uint8_t MON10 : 1;
            uint8_t             : 3;
        } RMONCNT_b;
    };
    __IM uint8_t RESERVED6[1];
    union
    {
        __IOM uint16_t RYRCNT;
        struct
        {
            __IOM uint16_t YR1  : 4;
            __IOM uint16_t YR10 : 4;
            uint16_t            : 8;
        } RYRCNT_b;
    };
    union
    {
        union
        {
            __IOM uint8_t RSECAR;
            struct
            {
                __IOM uint8_t SEC1  : 4;
                __IOM uint8_t SEC10 : 3;
                __IOM uint8_t ENB   : 1;
            } RSECAR_b;
        };
        union
        {
            __IOM uint8_t BCNT0AR;
            struct
            {
                __IOM uint8_t BCNTAR : 8;
            } BCNT0AR_b;
        };
    };
    __IM uint8_t RESERVED7[1];
    union
    {
        union
        {
            __IOM uint8_t RMINAR;
            struct
            {
                __IOM uint8_t MIN1  : 4;
                __IOM uint8_t MIN10 : 3;
                __IOM uint8_t ENB   : 1;
            } RMINAR_b;
        };
        union
        {
            __IOM uint8_t BCNT1AR;
            struct
            {
                __IOM uint8_t BCNTAR : 8;
            } BCNT1AR_b;
        };
    };
    __IM uint8_t RESERVED8[1];
    union
    {
        union
        {
            __IOM uint8_t RHRAR;
            struct
            {
                __IOM uint8_t HR1  : 4;
                __IOM uint8_t HR10 : 2;
                __IOM uint8_t PM   : 1;
                __IOM uint8_t ENB  : 1;
            } RHRAR_b;
        };
        union
        {
            __IOM uint8_t BCNT2AR;
            struct
            {
                __IOM uint8_t BCNTAR : 8;
            } BCNT2AR_b;
        };
    };
    __IM uint8_t RESERVED9[1];
    union
    {
        union
        {
            __IOM uint8_t RWKAR;
            struct
            {
                __IOM uint8_t DAYW : 3;
                uint8_t            : 4;
                __IOM uint8_t ENB  : 1;
            } RWKAR_b;
        };
        union
        {
            __IOM uint8_t BCNT3AR;
            struct
            {
                __IOM uint8_t BCNTAR : 8;
            } BCNT3AR_b;
        };
    };
    __IM uint8_t RESERVED10[1];
    union
    {
        union
        {
            __IOM uint8_t RDAYAR;
            struct
            {
                __IOM uint8_t DATE1  : 4;
                __IOM uint8_t DATE10 : 2;
                uint8_t              : 1;
                __IOM uint8_t ENB    : 1;
            } RDAYAR_b;
        };
        union
        {
            __IOM uint8_t BCNT0AER;
            struct
            {
                __IOM uint8_t ENB : 8;
            } BCNT0AER_b;
        };
    };
    __IM uint8_t RESERVED11[1];
    union
    {
        union
        {
            __IOM uint8_t RMONAR;
            struct
            {
                __IOM uint8_t MON1  : 4;
                __IOM uint8_t MON10 : 1;
                uint8_t             : 2;
                __IOM uint8_t ENB   : 1;
            } RMONAR_b;
        };
        union
        {
            __IOM uint8_t BCNT1AER;
            struct
            {
                __IOM uint8_t ENB : 8;
            } BCNT1AER_b;
        };
    };
    __IM uint8_t RESERVED12[1];
    union
    {
        union
        {
            __IOM uint16_t RYRAR;
            struct
            {
                __IOM uint16_t YR1  : 4;
                __IOM uint16_t YR10 : 4;
                uint16_t            : 8;
            } RYRAR_b;
        };
        union
        {
            __IOM uint16_t BCNT2AER;
            struct
            {
                __IOM uint16_t ENB : 8;
                uint16_t           : 8;
            } BCNT2AER_b;
        };
    };
    union
    {
        union
        {
            __IOM uint8_t RYRAREN;
            struct
            {
                uint8_t           : 7;
                __IOM uint8_t ENB : 1;
            } RYRAREN_b;
        };
        union
        {
            __IOM uint8_t BCNT3AER;
            struct
            {
                __IOM uint8_t ENB : 8;
            } BCNT3AER_b;
        };
    };
    __IM uint8_t RESERVED13[1];
    union
    {
        __IOM uint8_t RSR;
        struct
        {
            __IOM uint8_t AF : 1;
            __IOM uint8_t CF : 1;
            __IOM uint8_t PF : 1;
            uint8_t          : 5;
        } RSR_b;
    };
    __IM uint8_t RESERVED14[1];
    union
    {
        __IOM uint8_t RCR1;
        struct
        {
            __IOM uint8_t AIE : 1;
            __IOM uint8_t CIE : 1;
            __IOM uint8_t PIE : 1;
            uint8_t           : 1;
            __IOM uint8_t PES : 4;
        } RCR1_b;
    };
    __IM uint8_t RESERVED15[1];
    union
    {
        __IOM uint8_t RCR2;
        struct
        {
            __IOM uint8_t START : 1;
            __IOM uint8_t RESET : 1;
            __IOM uint8_t ADJ30 : 1;
            uint8_t             : 1;
            __IOM uint8_t AADJE : 1;
            __IOM uint8_t AADJP : 1;
            __IOM uint8_t HR24  : 1;
            __IOM uint8_t CNTMD : 1;
        } RCR2_b;
    };
    __IM uint8_t RESERVED16[9];
    union
    {
        __IOM uint8_t RADJ;
        struct
        {
            __IOM uint8_t ADJ   : 6;
            __IOM uint8_t PMADJ : 2;
        } RADJ_b;
    };
} R_RTC_Type;

typedef struct
{
    union
    {
        __IM uint8_t R64CNT;
        struct
        {
            __IM uint8_t F64HZ : 1;
            __IM uint8_t F32HZ : 1;
            __IM uint8_t F16HZ : 1;
            __IM uint8_t F8HZ  : 1;
            __IM uint8_t F4HZ  : 1;
            __IM uint8_t F2HZ  : 1;
            __IM uint8_t F1HZ  : 1;
            uint8_t            : 1;
        } R64CNT_b;
    };
    __IM uint8_t RESERVED[1];
    union
    {
        union
        {
            __IM uint8_t RSECCNT;
            struct
            {
                __IM uint8_t SEC1  : 4;
                __IM uint8_t SEC10 : 3;
                uint8_t            : 1;
            } RSECCNT_b;
        };
        union
        {
            __IM uint8_t BCNT0;
            struct
            {
                __IM uint8_t BCNT : 8;
            } BCNT0_b;
        };
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        union
        {
            __IM uint8_t RMINCNT;
            struct
            {
                __IM uint8_t MIN1  : 4;
                __IM uint8_t MIN10 : 3;
                uint8_t            : 1;
            } RMINCNT_b;
        };
        union
        {
            __IM uint8_t BCNT1;
            struct
            {
                __IM uint8_t BCNT : 8;
            } BCNT1_b;
        };
    };
    __IM uint8_t RESERVED2[1];
    union
    {
        union
        {
            __IM uint8_t RHRCNT;
            struct
            {
                __IM uint8_t HR1  : 4;
                __IM uint8_t HR10 : 2;
                __IM uint8_t PM   : 1;
                uint8_t           : 1;
            } RHRCNT_b;
        };
        union
        {
            __IM uint8_t BCNT2;
            struct
            {
                __IM uint8_t BCNT : 8;
            } BCNT2_b;
        };
    };
    __IM uint8_t RESERVED3[1];
    union
    {
        union
        {
            __IM uint8_t RWKCNT;
            struct
            {
                __IM uint8_t DAYW : 3;
                uint8_t           : 5;
            } RWKCNT_b;
        };
        union
        {
            __IM uint8_t BCNT3;
            struct
            {
                __IM uint8_t BCNT : 8;
            } BCNT3_b;
        };
    };
    __IM uint8_t RESERVED4[1];
    union
    {
        __IM uint8_t RDAYCNT;
        struct
        {
            __IM uint8_t DATE1  : 4;
            __IM uint8_t DATE10 : 2;
            uint8_t             : 2;
        } RDAYCNT_b;
    };
    __IM uint8_t RESERVED5[1];
    union
    {
        __IM uint8_t RMONCNT;
        struct
        {
            __IM uint8_t MON1  : 4;
            __IM uint8_t MON10 : 1;
            uint8_t            : 3;
        } RMONCNT_b;
    };
    __IM uint8_t RESERVED6[1];
    union
    {
        __IM uint16_t RYRCNT;
        struct
        {
            __IM uint16_t YR1  : 4;
            __IM uint16_t YR10 : 4;
            uint16_t           : 8;
        } RYRCNT_b;
    };
} R_RTC_RO_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_RTC_BASE       0x41C00800
#define R_RTC_RO_BASE    0x41C00C00

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_RTC       ((R_RTC_Type *) R_RTC_BASE)
#define R_RTC_RO    ((R_RTC_RO_Type *) R_RTC_RO_BASE)

#endif
