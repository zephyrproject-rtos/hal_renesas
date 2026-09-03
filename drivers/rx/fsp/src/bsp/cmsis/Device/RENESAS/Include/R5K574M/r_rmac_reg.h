/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RMAC_REG_H
#define R_RMAC_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_RMAC0                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Ethernet MAC (R_RMAC0)
 */

typedef struct                         /*!< (@ 0x874CB000) R_RMAC0 Structure                                          */
{
    union
    {
        __IOM uint32_t MPSM;           /*!< (@ 0x00000000) MAC PHY Station Management Register (MPSM)                 */

        struct
        {
            __IOM uint32_t PSME : 1;   /*!< [0..0] PSME                                                               */
            uint32_t            : 1;
            __IOM uint32_t MFF  : 1;   /*!< [2..2] MFF                                                                */
            __IOM uint32_t PDA  : 5;   /*!< [7..3] PDA                                                                */
            __IOM uint32_t PRA  : 5;   /*!< [12..8] PRA                                                               */
            __IOM uint32_t POP  : 2;   /*!< [14..13] POP                                                              */
            uint32_t            : 1;
            __IOM uint32_t PRD  : 16;  /*!< [31..16] PRD                                                              */
        } MPSM_b;
    };

    union
    {
        __IOM uint32_t MPIC;           /*!< (@ 0x00000004) MAC PHY Interfaces Configuration Register (MPIC)           */

        struct
        {
            __IOM uint32_t PIS   : 3;  /*!< [2..0] PIS                                                                */
            __IOM uint32_t LSC   : 3;  /*!< [5..3] LSC                                                                */
            uint32_t             : 2;
            __IOM uint32_t PIP   : 1;  /*!< [8..8] PIP                                                                */
            __IOM uint32_t PIPP  : 1;  /*!< [9..9] PIPP                                                               */
            __IOM uint32_t PLSPP : 1;  /*!< [10..10] PLSPP                                                            */
            uint32_t             : 5;
            __IOM uint32_t PSMCS : 7;  /*!< [22..16] PSMCS                                                            */
            __IOM uint32_t PSMDP : 1;  /*!< [23..23] PSMDP                                                            */
            __IOM uint32_t PSMHT : 3;  /*!< [26..24] PSMHT                                                            */
            uint32_t             : 1;
            __IOM uint32_t PSMCT : 3;  /*!< [30..28] PSMCT                                                            */
            uint32_t             : 1;
        } MPIC_b;
    };

    union
    {
        __IOM uint32_t MPIM;           /*!< (@ 0x00000008) MAC PHY Interfaces Monitoring Register (MPIM)              */

        struct
        {
            __IOM uint32_t PLS  : 1;   /*!< [0..0] PLS                                                                */
            __IOM uint32_t LPIA : 1;   /*!< [1..1] LPIA                                                               */
            uint32_t            : 30;
        } MPIM_b;
    };
    __IM uint32_t RESERVED;

    union
    {
        __IOM uint32_t MIOC;           /*!< (@ 0x00000010) RMAC IO Configuration Registers Register (MIOC)            */

        struct
        {
            __IOM uint32_t MIOC : 32;  /*!< [31..0] MIOC                                                              */
        } MIOC_b;
    };
    __IM uint32_t RESERVED1[3];

    union
    {
        __IOM uint32_t MTFFC;          /*!< (@ 0x00000020) MAC Transmission Frame Format Configuration Register
                                        *                  (MTFFC)                                                    */

        struct
        {
            __IOM uint32_t DPAD : 1;   /*!< [0..0] DPAD                                                               */
            __IOM uint32_t FCM  : 1;   /*!< [1..1] FCM                                                                */
            uint32_t            : 30;
        } MTFFC_b;
    };

    union
    {
        __IOM uint32_t MTPFC;          /*!< (@ 0x00000024) MAC Transmission Pause or PFC Frame Configuration
                                        *                  Register (MTPFC)                                           */

        struct
        {
            __IOM uint32_t PT    : 16; /*!< [15..0] PT                                                                */
            __IOM uint32_t PFRT  : 8;  /*!< [23..16] PFRT                                                             */
            uint32_t             : 2;
            __IOM uint32_t PFM   : 1;  /*!< [26..26] PFM                                                              */
            __IOM uint32_t PFRLV : 5;  /*!< [31..27] PFRLV                                                            */
        } MTPFC_b;
    };

    union
    {
        __IOM uint32_t MTPFC2;          /*!< (@ 0x00000028) MAC Transmission Pause or PFC Frame configuration2
                                         *                  Register (MTPFC2)                                          */

        struct
        {
            __IOM uint32_t PFCTTZ  : 2; /*!< [1..0] PFCTTZ                                                             */
            uint32_t               : 6;
            __IOM uint32_t MPFCFR0 : 1; /*!< [8..8] MPFCFR0                                                            */
            __IOM uint32_t MPFCFR1 : 1; /*!< [9..9] MPFCFR1                                                            */
            uint32_t               : 6;
            __IOM uint32_t PFTTZ   : 1; /*!< [16..16] PFTTZ                                                            */
            __IOM uint32_t MPFR    : 1; /*!< [17..17] MPFR                                                             */
            uint32_t               : 14;
        } MTPFC2_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t MTPFC30;        /*!< (@ 0x00000030) MAC Transmission Pause or PFC Frame Configuration
                                        *                  Register 3 (MTPFC3t) (t = 0, 1)                            */

        struct
        {
            __IOM uint32_t PFCPG : 8;  /*!< [7..0] PFCPG                                                              */
            uint32_t             : 24;
        } MTPFC30_b;
    };

    union
    {
        __IOM uint32_t MTPFC31;        /*!< (@ 0x00000034) MAC Transmission Pause or PFC Frame Configuration
                                        *                  Register 3 (MTPFC3t) (t = 0, 1)                            */

        struct
        {
            __IOM uint32_t PFCPG : 8;  /*!< [7..0] PFCPG                                                              */
            uint32_t             : 24;
        } MTPFC31_b;
    };
    __IM uint32_t RESERVED3[6];

    union
    {
        __IOM uint32_t MTATC0;         /*!< (@ 0x00000050) MAC Transmission Automatic Timestamp Configuration
                                        *                  Register (MTATCt) (t = 0, 1)                               */

        struct
        {
            __IOM uint32_t TRTP : 8;   /*!< [7..0] TRTP                                                               */
            __IOM uint32_t TRTL : 3;   /*!< [10..8] TRTL                                                              */
            uint32_t            : 21;
        } MTATC0_b;
    };

    union
    {
        __IOM uint32_t MTATC1;         /*!< (@ 0x00000054) MAC Transmission Automatic Timestamp Configuration
                                        *                  Register (MTATCt) (t = 0, 1)                               */

        struct
        {
            __IOM uint32_t TRTP : 8;   /*!< [7..0] TRTP                                                               */
            __IOM uint32_t TRTL : 3;   /*!< [10..8] TRTL                                                              */
            uint32_t            : 21;
        } MTATC1_b;
    };
    __IM uint32_t RESERVED4[2];

    union
    {
        __IOM uint32_t MTIM;           /*!< (@ 0x00000060) MAC Transmission Interfaces Monitoring Register
                                        *                  (MTIM)                                                     */

        struct
        {
            __IOM uint32_t TS : 1;     /*!< [0..0] TS                                                                 */
            uint32_t          : 31;
        } MTIM_b;
    };
    __IM uint32_t RESERVED5[7];

    union
    {
        __IOM uint32_t MRGC;           /*!< (@ 0x00000080) MAC Reception General Configuration Register
                                        *                  (MRGC)                                                     */

        struct
        {
            __IOM uint32_t RCPT  : 1;  /*!< [0..0] RCPT                                                               */
            __IOM uint32_t PFRC  : 1;  /*!< [1..1] PFRC                                                               */
            __IOM uint32_t PFRTZ : 1;  /*!< [2..2] PFRTZ                                                              */
            __IOM uint32_t MPDE  : 1;  /*!< [3..3] MPDE                                                               */
            __IOM uint32_t RFCFE : 1;  /*!< [4..4] RFCFE                                                              */
            uint32_t             : 11;
            __IOM uint32_t PFCRC : 8;  /*!< [23..16] PFCRC                                                            */
            uint32_t             : 8;
        } MRGC_b;
    };

    union
    {
        __IOM uint32_t MRMAC0;         /*!< (@ 0x00000084) MAC Reception MAC Address Configuration Register
                                        *                  0 (MRMAC0)                                                 */

        struct
        {
            __IOM uint32_t MAU : 16;   /*!< [15..0] MAU                                                               */
            uint32_t           : 16;
        } MRMAC0_b;
    };

    union
    {
        __IOM uint32_t MRMAC1;         /*!< (@ 0x00000088) MAC Reception MAC Address Configuration Register
                                        *                  1 (MRMAC1)                                                 */

        struct
        {
            __IOM uint32_t MAL : 32;   /*!< [31..0] MAL                                                               */
        } MRMAC1_b;
    };

    union
    {
        __IOM uint32_t MRAFC;           /*!< (@ 0x0000008C) MAC Reception Address Filter Configuration Register
                                         *                  (MRAFC)                                                    */

        struct
        {
            __IOM uint32_t UCENE   : 1; /*!< [0..0] UCENE                                                              */
            __IOM uint32_t MCENE   : 1; /*!< [1..1] MCENE                                                              */
            __IOM uint32_t BCENE   : 1; /*!< [2..2] BCENE                                                              */
            __IOM uint32_t MSTENE  : 1; /*!< [3..3] MSTENE                                                             */
            __IOM uint32_t BSTENE  : 1; /*!< [4..4] BSTENE                                                             */
            __IOM uint32_t MCACE   : 1; /*!< [5..5] MCACE                                                              */
            __IOM uint32_t BCACE   : 1; /*!< [6..6] BCACE                                                              */
            __IOM uint32_t NDAREE  : 1; /*!< [7..7] NDAREE                                                             */
            __IOM uint32_t SDSFREE : 1; /*!< [8..8] SDSFREE                                                            */
            __IOM uint32_t NSAREE  : 1; /*!< [9..9] NSAREE                                                             */
            __IOM uint32_t MSAREE  : 1; /*!< [10..10] MSAREE                                                           */
            uint32_t               : 5;
            __IOM uint32_t UCENP   : 1; /*!< [16..16] UCENP                                                            */
            __IOM uint32_t MCENP   : 1; /*!< [17..17] MCENP                                                            */
            __IOM uint32_t BCENP   : 1; /*!< [18..18] BCENP                                                            */
            __IOM uint32_t MSTENP  : 1; /*!< [19..19] MSTENP                                                           */
            __IOM uint32_t BSTENP  : 1; /*!< [20..20] BSTENP                                                           */
            __IOM uint32_t MCACP   : 1; /*!< [21..21] MCACP                                                            */
            __IOM uint32_t BCACP   : 1; /*!< [22..22] BCACP                                                            */
            __IOM uint32_t NDAREP  : 1; /*!< [23..23] NDAREP                                                           */
            __IOM uint32_t SDSFREP : 1; /*!< [24..24] SDSFREP                                                          */
            __IOM uint32_t NSAREP  : 1; /*!< [25..25] NSAREP                                                           */
            __IOM uint32_t MSAREP  : 1; /*!< [26..26] MSAREP                                                           */
            uint32_t               : 5;
        } MRAFC_b;
    };

    union
    {
        __IOM uint32_t MRSCE;          /*!< (@ 0x00000090) MAC Reception Storm Configuration for e-Frames
                                        *                  Register (MRSCE)                                           */

        struct
        {
            __IOM uint32_t CMFE : 16;  /*!< [15..0] CMFE                                                              */
            __IOM uint32_t CBFE : 16;  /*!< [31..16] CBFE                                                             */
        } MRSCE_b;
    };

    union
    {
        __IOM uint32_t MRSCP;          /*!< (@ 0x00000094) MAC Reception Storm Configuration for p-Frames
                                        *                  Register (MRSCP)                                           */

        struct
        {
            __IOM uint32_t CMFP : 16;  /*!< [15..0] CMFP                                                              */
            __IOM uint32_t CBFP : 16;  /*!< [31..16] CBFP                                                             */
        } MRSCP_b;
    };

    union
    {
        __IOM uint32_t MRSCC;          /*!< (@ 0x00000098) MAC Reception Storm Counter Configuration Register
                                        *                  (MRSCC)                                                    */

        struct
        {
            __IOM uint32_t MSCCE : 1;  /*!< [0..0] MSCCE                                                              */
            __IOM uint32_t BSCCE : 1;  /*!< [1..1] BSCCE                                                              */
            uint32_t             : 14;
            __IOM uint32_t MSCCP : 1;  /*!< [16..16] MSCCP                                                            */
            __IOM uint32_t BSCCP : 1;  /*!< [17..17] BSCCP                                                            */
            uint32_t             : 14;
        } MRSCC_b;
    };

    union
    {
        __IOM uint32_t MRFSCE;         /*!< (@ 0x0000009C) MAC Reception Frame Size Configuration for e-Frames
                                        *                  Register (MRFSCE)                                          */

        struct
        {
            __IOM uint32_t EMXS : 16;  /*!< [15..0] EMXS                                                              */
            __IOM uint32_t EMNS : 16;  /*!< [31..16] EMNS                                                             */
        } MRFSCE_b;
    };

    union
    {
        __IOM uint32_t MRFSCP;         /*!< (@ 0x000000A0) MAC Reception Frame Size Configuration for p-Frames
                                        *                  Register (MRFSCP)                                          */

        struct
        {
            __IOM uint32_t PMXS : 16;  /*!< [15..0] PMXS                                                              */
            __IOM uint32_t PMNS : 16;  /*!< [31..16] PMNS                                                             */
        } MRFSCP_b;
    };

    union
    {
        __IOM uint32_t MTRC;            /*!< (@ 0x000000A4) MAC Timestamp Reception Configuration Register
                                         *                  (MTRC)                                                     */

        struct
        {
            __IOM uint32_t TRHFME0 : 1; /*!< [0..0] TRHFME0                                                            */
            __IOM uint32_t TRHFME1 : 1; /*!< [1..1] TRHFME1                                                            */
            uint32_t               : 22;
            __IOM uint32_t TRDDE   : 1; /*!< [24..24] TRDDE                                                            */
            __IOM uint32_t TRDDP   : 1; /*!< [25..25] TRDDP                                                            */
            __IOM uint32_t TCTSE   : 1; /*!< [26..26] TCTSE                                                            */
            __IOM uint32_t TCTSP   : 1; /*!< [27..27] TCTSP                                                            */
            __IOM uint32_t DTN     : 1; /*!< [28..28] DTN                                                              */
            uint32_t               : 3;
        } MTRC_b;
    };
    __IM uint32_t RESERVED6;

    union
    {
        __IOM uint32_t MRPFM;          /*!< (@ 0x000000AC) MAC Reception Pause or PFC Frame Monitoring Register
                                        *                  (MRPFM)                                                    */

        struct
        {
            __IOM uint32_t PTCA   : 1; /*!< [0..0] PTCA                                                               */
            uint32_t              : 15;
            __IOM uint32_t PFCTCA : 8; /*!< [23..16] PFCTCA                                                           */
            uint32_t              : 8;
        } MRPFM_b;
    };
    __IM uint32_t RESERVED7[20];

    union
    {
        __IOM uint32_t MPFC0;          /*!< (@ 0x00000100) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC0_b;
    };

    union
    {
        __IOM uint32_t MPFC1;          /*!< (@ 0x00000104) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC1_b;
    };

    union
    {
        __IOM uint32_t MPFC2;          /*!< (@ 0x00000108) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC2_b;
    };

    union
    {
        __IOM uint32_t MPFC3;          /*!< (@ 0x0000010C) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC3_b;
    };

    union
    {
        __IOM uint32_t MPFC4;          /*!< (@ 0x00000110) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC4_b;
    };

    union
    {
        __IOM uint32_t MPFC5;          /*!< (@ 0x00000114) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC5_b;
    };

    union
    {
        __IOM uint32_t MPFC6;          /*!< (@ 0x00000118) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC6_b;
    };

    union
    {
        __IOM uint32_t MPFC7;          /*!< (@ 0x0000011C) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC7_b;
    };

    union
    {
        __IOM uint32_t MPFC8;          /*!< (@ 0x00000120) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC8_b;
    };

    union
    {
        __IOM uint32_t MPFC9;          /*!< (@ 0x00000124) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC9_b;
    };

    union
    {
        __IOM uint32_t MPFC10;         /*!< (@ 0x00000128) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC10_b;
    };

    union
    {
        __IOM uint32_t MPFC11;         /*!< (@ 0x0000012C) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC11_b;
    };

    union
    {
        __IOM uint32_t MPFC12;         /*!< (@ 0x00000130) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC12_b;
    };

    union
    {
        __IOM uint32_t MPFC13;         /*!< (@ 0x00000134) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC13_b;
    };

    union
    {
        __IOM uint32_t MPFC14;         /*!< (@ 0x00000138) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC14_b;
    };

    union
    {
        __IOM uint32_t MPFC15;         /*!< (@ 0x0000013C) MAC PTP Filtering Register Configuration Register
                                        *                  t (MPFCt) (t = 0 to 15)                                    */

        struct
        {
            __IOM uint32_t PFBN : 8;   /*!< [7..0] PFBN                                                               */
            __IOM uint32_t PFBV : 8;   /*!< [15..8] PFBV                                                              */
            __IOM uint32_t TEF0 : 1;   /*!< [16..16] TEF0                                                             */
            __IOM uint32_t TEF1 : 1;   /*!< [17..17] TEF1                                                             */
            uint32_t            : 14;
        } MPFC15_b;
    };
    __IM uint32_t RESERVED8[16];

    union
    {
        __IOM uint32_t MLVC;           /*!< (@ 0x00000180) MAC Link Verification Configuration Register
                                        *                  (MLVC)                                                     */

        struct
        {
            __IOM uint32_t LVT  : 7;   /*!< [6..0] LVT                                                                */
            uint32_t            : 1;
            __IOM uint32_t PASE : 1;   /*!< [8..8] PASE                                                               */
            uint32_t            : 7;
            __IOM uint32_t PLV  : 1;   /*!< [16..16] PLV                                                              */
            uint32_t            : 15;
        } MLVC_b;
    };

    union
    {
        __IOM uint32_t MEEEC;          /*!< (@ 0x00000184) MAC Energy Efficient Ethernet Configuration Register
                                        *                  (MEEEC)                                                    */

        struct
        {
            __IOM uint32_t LPITR : 1;  /*!< [0..0] LPITR                                                              */
            uint32_t             : 31;
        } MEEEC_b;
    };

    union
    {
        __IOM uint32_t MLBC;           /*!< (@ 0x00000188) MAC Loopback Configuration Register (MLBC)                 */

        struct
        {
            __IOM uint32_t LBME : 1;   /*!< [0..0] LBME                                                               */
            uint32_t            : 31;
        } MLBC_b;
    };
    __IM uint32_t RESERVED9;

    union
    {
        __IOM uint32_t MXGMIIC;            /*!< (@ 0x00000190) XGMII Configuration Register (MXGMIIC)                     */

        struct
        {
            __IOM uint32_t LFS_TXRFS  : 1; /*!< [0..0] LFS_TXRFS                                                          */
            __IOM uint32_t LFS_TXIDLE : 1; /*!< [1..1] LFS_TXIDLE                                                         */
            uint32_t                  : 30;
        } MXGMIIC_b;
    };

    union
    {
        __IOM uint32_t MPCH;                /*!< (@ 0x00000194) XGMII PCH Configuration Register (MPCH)                    */

        struct
        {
            __IOM uint32_t TXPCH_M     : 1; /*!< [0..0] TXPCH_M                                                            */
            uint32_t                   : 1;
            __IOM uint32_t TXPCH_ETYPE : 2; /*!< [3..2] TXPCH_ETYPE                                                        */
            __IOM uint32_t TXPCH_PID   : 4; /*!< [7..4] TXPCH_PID                                                          */
            __IOM uint32_t IETPTE      : 1; /*!< [8..8] IETPTE                                                             */
            __IOM uint32_t CTPTE       : 1; /*!< [9..9] CTPTE                                                              */
            __IOM uint32_t IETRIOD     : 1; /*!< [10..10] IETRIOD                                                          */
            __IOM uint32_t CTRIOD      : 1; /*!< [11..11] CTRIOD                                                           */
            uint32_t                   : 4;
            __IOM uint32_t RXPCH_TSM   : 1; /*!< [16..16] RXPCH_TSM                                                        */
            __IOM uint32_t RPHCRCD     : 1; /*!< [17..17] RPHCRCD                                                          */
            uint32_t                   : 14;
        } MPCH_b;
    };
    __IM uint32_t RESERVED10;

    union
    {
        __IOM uint32_t MANM;               /*!< (@ 0x0000019C) Auto-Negotiation Message Register (MANM)                   */

        struct
        {
            __IOM uint32_t RX_AN_MES : 16; /*!< [15..0] RX_AN_MES                                                         */
            uint32_t                 : 16;
        } MANM_b;
    };
    __IM uint32_t RESERVED11[24];

    union
    {
        __IOM uint32_t MEIS;           /*!< (@ 0x00000200) MAC Error Interrupt Status Register (MEIS)                 */

        struct
        {
            __IOM uint32_t TSLS   : 1; /*!< [0..0] TSLS                                                               */
            __IOM uint32_t TIES   : 1; /*!< [1..1] TIES                                                               */
            __IOM uint32_t PRES   : 1; /*!< [2..2] PRES                                                               */
            __IOM uint32_t PFRROS : 1; /*!< [3..3] PFRROS                                                             */
            __IOM uint32_t FCDS   : 1; /*!< [4..4] FCDS                                                               */
            __IOM uint32_t TCES   : 1; /*!< [5..5] TCES                                                               */
            __IOM uint32_t TBCIS  : 1; /*!< [6..6] TBCIS                                                              */
            __IOM uint32_t BFES   : 1; /*!< [7..7] BFES                                                               */
            __IOM uint32_t FCES   : 1; /*!< [8..8] FCES                                                               */
            __IOM uint32_t REOES  : 1; /*!< [9..9] REOES                                                              */
            __IOM uint32_t RPOES  : 1; /*!< [10..10] RPOES                                                            */
            __IOM uint32_t RPCRES : 1; /*!< [11..11] RPCRES                                                           */
            __IOM uint32_t CTLES0 : 1; /*!< [12..12] CTLES0                                                           */
            __IOM uint32_t CTLES1 : 1; /*!< [13..13] CTLES1                                                           */
            uint32_t              : 6;
            __IOM uint32_t PDES   : 1; /*!< [20..20] PDES                                                             */
            __IOM uint32_t PNAES  : 1; /*!< [21..21] PNAES                                                            */
            __IOM uint32_t FCMCES : 1; /*!< [22..22] FCMCES                                                           */
            __IOM uint32_t FFMES  : 1; /*!< [23..23] FFMES                                                            */
            __IOM uint32_t CFCES  : 1; /*!< [24..24] CFCES                                                            */
            __IOM uint32_t FRCES  : 1; /*!< [25..25] FRCES                                                            */
            __IOM uint32_t RPOOMS : 1; /*!< [26..26] RPOOMS                                                           */
            __IOM uint32_t FFS    : 1; /*!< [27..27] FFS                                                              */
            __IOM uint32_t FUES   : 1; /*!< [28..28] FUES                                                             */
            __IOM uint32_t FOES   : 1; /*!< [29..29] FOES                                                             */
            uint32_t              : 2;
        } MEIS_b;
    };

    union
    {
        __IOM uint32_t MEIE;           /*!< (@ 0x00000204) MAC Error Interrupt Enable Register (MEIE)                 */

        struct
        {
            __IOM uint32_t TSLE   : 1; /*!< [0..0] TSLE                                                               */
            __IOM uint32_t TIEE   : 1; /*!< [1..1] TIEE                                                               */
            __IOM uint32_t PMSEE  : 1; /*!< [2..2] PMSEE                                                              */
            __IOM uint32_t PFRROE : 1; /*!< [3..3] PFRROE                                                             */
            __IOM uint32_t FCDE   : 1; /*!< [4..4] FCDE                                                               */
            __IOM uint32_t TCEE   : 1; /*!< [5..5] TCEE                                                               */
            __IOM uint32_t TBCIE  : 1; /*!< [6..6] TBCIE                                                              */
            __IOM uint32_t BFEE   : 1; /*!< [7..7] BFEE                                                               */
            __IOM uint32_t FCEE   : 1; /*!< [8..8] FCEE                                                               */
            __IOM uint32_t REOEE  : 1; /*!< [9..9] REOEE                                                              */
            __IOM uint32_t RPOEE  : 1; /*!< [10..10] RPOEE                                                            */
            __IOM uint32_t RPCREE : 1; /*!< [11..11] RPCREE                                                           */
            __IOM uint32_t CTLEE0 : 1; /*!< [12..12] CTLEE0                                                           */
            __IOM uint32_t CTLEE1 : 1; /*!< [13..13] CTLEE1                                                           */
            uint32_t              : 6;
            __IOM uint32_t PDEE   : 1; /*!< [20..20] PDEE                                                             */
            __IOM uint32_t PNAEE  : 1; /*!< [21..21] PNAEE                                                            */
            __IOM uint32_t FCMCEE : 1; /*!< [22..22] FCMCEE                                                           */
            __IOM uint32_t FFMEE  : 1; /*!< [23..23] FFMEE                                                            */
            __IOM uint32_t CFCEE  : 1; /*!< [24..24] CFCEE                                                            */
            __IOM uint32_t FRCEE  : 1; /*!< [25..25] FRCEE                                                            */
            __IOM uint32_t RPOOME : 1; /*!< [26..26] RPOOME                                                           */
            __IOM uint32_t FFE    : 1; /*!< [27..27] FFE                                                              */
            __IOM uint32_t FUEE   : 1; /*!< [28..28] FUEE                                                             */
            __IOM uint32_t FOEE   : 1; /*!< [29..29] FOEE                                                             */
            uint32_t              : 2;
        } MEIE_b;
    };

    union
    {
        __IOM uint32_t MEID;           /*!< (@ 0x00000208) MAC Error Interrupt Disable Register (MEID)                */

        struct
        {
            __IOM uint32_t TSLD   : 1; /*!< [0..0] TSLD                                                               */
            __IOM uint32_t TIED   : 1; /*!< [1..1] TIED                                                               */
            __IOM uint32_t PRED   : 1; /*!< [2..2] PRED                                                               */
            __IOM uint32_t PFRROD : 1; /*!< [3..3] PFRROD                                                             */
            __IOM uint32_t FCDD   : 1; /*!< [4..4] FCDD                                                               */
            __IOM uint32_t TCED   : 1; /*!< [5..5] TCED                                                               */
            __IOM uint32_t TBCID  : 1; /*!< [6..6] TBCID                                                              */
            __IOM uint32_t BFED   : 1; /*!< [7..7] BFED                                                               */
            __IOM uint32_t FCED   : 1; /*!< [8..8] FCED                                                               */
            __IOM uint32_t REOED  : 1; /*!< [9..9] REOED                                                              */
            __IOM uint32_t RPOED  : 1; /*!< [10..10] RPOED                                                            */
            __IOM uint32_t RPCRED : 1; /*!< [11..11] RPCRED                                                           */
            __IOM uint32_t CTLED0 : 1; /*!< [12..12] CTLED0                                                           */
            __IOM uint32_t CTLED1 : 1; /*!< [13..13] CTLED1                                                           */
            uint32_t              : 6;
            __IOM uint32_t PDED   : 1; /*!< [20..20] PDED                                                             */
            __IOM uint32_t PNAED  : 1; /*!< [21..21] PNAED                                                            */
            __IOM uint32_t FCMCED : 1; /*!< [22..22] FCMCED                                                           */
            __IOM uint32_t FFMED  : 1; /*!< [23..23] FFMED                                                            */
            __IOM uint32_t CFCED  : 1; /*!< [24..24] CFCED                                                            */
            __IOM uint32_t FRCED  : 1; /*!< [25..25] FRCED                                                            */
            __IOM uint32_t RPOOMD : 1; /*!< [26..26] RPOOMD                                                           */
            __IOM uint32_t FFD    : 1; /*!< [27..27] FFD                                                              */
            __IOM uint32_t FUED   : 1; /*!< [28..28] FUED                                                             */
            __IOM uint32_t FOED   : 1; /*!< [29..29] FOED                                                             */
            uint32_t              : 2;
        } MEID_b;
    };
    __IM uint32_t RESERVED12;

    union
    {
        __IOM uint32_t MMIS0;          /*!< (@ 0x00000210) MAC Monitoring Interrupt Status Register 0 (MMIS0)         */

        struct
        {
            __IOM uint32_t PLSCS  : 1; /*!< [0..0] PLSCS                                                              */
            __IOM uint32_t PIDS   : 1; /*!< [1..1] PIDS                                                               */
            __IOM uint32_t LVSS   : 1; /*!< [2..2] LVSS                                                               */
            __IOM uint32_t LVFS   : 1; /*!< [3..3] LVFS                                                               */
            __IOM uint32_t VFRS   : 1; /*!< [4..4] VFRS                                                               */
            uint32_t              : 1;
            __IOM uint32_t ANDETS : 1; /*!< [6..6] ANDETS                                                             */
            uint32_t              : 1;
            __IOM uint32_t XLFDS  : 1; /*!< [8..8] XLFDS                                                              */
            __IOM uint32_t XLFES  : 1; /*!< [9..9] XLFES                                                              */
            __IOM uint32_t XLFSDS : 1; /*!< [10..10] XLFSDS                                                           */
            __IOM uint32_t XRFSDS : 1; /*!< [11..11] XRFSDS                                                           */
            __IOM uint32_t XLISDS : 1; /*!< [12..12] XLISDS                                                           */
            uint32_t              : 19;
        } MMIS0_b;
    };

    union
    {
        __IOM uint32_t MMIE0;          /*!< (@ 0x00000214) MAC Monitoring Interrupt Enable Register 0 (MMIE0)         */

        struct
        {
            __IOM uint32_t PLSCE  : 1; /*!< [0..0] PLSCE                                                              */
            __IOM uint32_t PIDE   : 1; /*!< [1..1] PIDE                                                               */
            __IOM uint32_t LVSE   : 1; /*!< [2..2] LVSE                                                               */
            __IOM uint32_t LVFE   : 1; /*!< [3..3] LVFE                                                               */
            __IOM uint32_t VFRE   : 1; /*!< [4..4] VFRE                                                               */
            uint32_t              : 1;
            __IOM uint32_t ANDETE : 1; /*!< [6..6] ANDETE                                                             */
            uint32_t              : 1;
            __IOM uint32_t XLFDE  : 1; /*!< [8..8] XLFDE                                                              */
            __IOM uint32_t XLFEE  : 1; /*!< [9..9] XLFEE                                                              */
            __IOM uint32_t XLFSDE : 1; /*!< [10..10] XLFSDE                                                           */
            __IOM uint32_t XRFSDE : 1; /*!< [11..11] XRFSDE                                                           */
            __IOM uint32_t XLISDE : 1; /*!< [12..12] XLISDE                                                           */
            uint32_t              : 19;
        } MMIE0_b;
    };

    union
    {
        __IOM uint32_t MMID0;          /*!< (@ 0x00000218) MAC Monitoring Interrupt Disable Register 0 (MMID0)        */

        struct
        {
            __IOM uint32_t PLSCD  : 1; /*!< [0..0] PLSCD                                                              */
            __IOM uint32_t PIDD   : 1; /*!< [1..1] PIDD                                                               */
            __IOM uint32_t LVSD   : 1; /*!< [2..2] LVSD                                                               */
            __IOM uint32_t LVFD   : 1; /*!< [3..3] LVFD                                                               */
            __IOM uint32_t VFRD   : 1; /*!< [4..4] VFRD                                                               */
            uint32_t              : 1;
            __IOM uint32_t ANDETD : 1; /*!< [6..6] ANDETD                                                             */
            uint32_t              : 1;
            __IOM uint32_t XLFDD  : 1; /*!< [8..8] XLFDD                                                              */
            __IOM uint32_t XLFED  : 1; /*!< [9..9] XLFED                                                              */
            __IOM uint32_t XLFSDD : 1; /*!< [10..10] XLFSDD                                                           */
            __IOM uint32_t XRFSDD : 1; /*!< [11..11] XRFSDD                                                           */
            __IOM uint32_t XLISDD : 1; /*!< [12..12] XLISDD                                                           */
            uint32_t              : 19;
        } MMID0_b;
    };
    __IM uint32_t RESERVED13;

    union
    {
        __IOM uint32_t MMIS1;          /*!< (@ 0x00000220) MAC Monitoring Interrupt Status Register 1 (MMIS1)         */

        struct
        {
            __IOM uint32_t PRACS  : 1; /*!< [0..0] PRACS                                                              */
            __IOM uint32_t PWACS  : 1; /*!< [1..1] PWACS                                                              */
            __IOM uint32_t PAACS  : 1; /*!< [2..2] PAACS                                                              */
            __IOM uint32_t PPRACS : 1; /*!< [3..3] PPRACS                                                             */
            uint32_t              : 28;
        } MMIS1_b;
    };

    union
    {
        __IOM uint32_t MMIE1;          /*!< (@ 0x00000224) MAC Monitoring Interrupt Enable Register 1 (MMIE1)         */

        struct
        {
            __IOM uint32_t PRACE  : 1; /*!< [0..0] PRACE                                                              */
            __IOM uint32_t PWACE  : 1; /*!< [1..1] PWACE                                                              */
            __IOM uint32_t PAACE  : 1; /*!< [2..2] PAACE                                                              */
            __IOM uint32_t PPRACE : 1; /*!< [3..3] PPRACE                                                             */
            uint32_t              : 28;
        } MMIE1_b;
    };

    union
    {
        __IOM uint32_t MMID1;          /*!< (@ 0x00000228) MAC Monitoring Interrupt Disable Register 1 (MMID1)        */

        struct
        {
            __IOM uint32_t PRACD  : 1; /*!< [0..0] PRACD                                                              */
            __IOM uint32_t PWACD  : 1; /*!< [1..1] PWACD                                                              */
            __IOM uint32_t PAACD  : 1; /*!< [2..2] PAACD                                                              */
            __IOM uint32_t PPRACD : 1; /*!< [3..3] PPRACD                                                             */
            uint32_t              : 28;
        } MMID1_b;
    };
    __IM uint32_t RESERVED14;

    union
    {
        __IOM uint32_t MMIS2;          /*!< (@ 0x00000230) MAC Monitoring Interrupt Status Register 2 (MMIS2)         */

        struct
        {
            __IOM uint32_t MPDIS  : 1; /*!< [0..0] MPDIS                                                              */
            __IOM uint32_t LPIAIS : 1; /*!< [1..1] LPIAIS                                                             */
            __IOM uint32_t LPIDIS : 1; /*!< [2..2] LPIDIS                                                             */
            uint32_t              : 29;
        } MMIS2_b;
    };

    union
    {
        __IOM uint32_t MMIE2;          /*!< (@ 0x00000234) MAC Monitoring Interrupt Enable Register 2 (MMIE2)         */

        struct
        {
            __IOM uint32_t MPDIE  : 1; /*!< [0..0] MPDIE                                                              */
            __IOM uint32_t LPIAIE : 1; /*!< [1..1] LPIAIE                                                             */
            __IOM uint32_t LPIDIE : 1; /*!< [2..2] LPIDIE                                                             */
            uint32_t              : 29;
        } MMIE2_b;
    };

    union
    {
        __IOM uint32_t MMID2;          /*!< (@ 0x00000238) MAC Monitoring Interrupt Disable Register 2 (MMID2)        */

        struct
        {
            __IOM uint32_t MPDID  : 1; /*!< [0..0] MPDID                                                              */
            __IOM uint32_t LPIAID : 1; /*!< [1..1] LPIAID                                                             */
            __IOM uint32_t LPIDID : 1; /*!< [2..2] LPIDID                                                             */
            uint32_t              : 29;
        } MMID2_b;
    };
    __IM uint32_t RESERVED15[49];

    union
    {
        __IOM uint32_t MMPFTCT;        /*!< (@ 0x00000300) MAC Manual Pause Frame Transmit Counter Register
                                        *                  (MMPFTCT)                                                  */

        struct
        {
            __IOM uint32_t MPFTC : 16; /*!< [15..0] MPFTC                                                             */
            uint32_t             : 16;
        } MMPFTCT_b;
    };

    union
    {
        __IOM uint32_t MAPFTCT;        /*!< (@ 0x00000304) MAC Automatic Pause Frame Transmit Counter Register
                                        *                  (MAPFTCT)                                                  */

        struct
        {
            __IOM uint32_t APFTC : 16; /*!< [15..0] APFTC                                                             */
            uint32_t             : 16;
        } MAPFTCT_b;
    };

    union
    {
        __IOM uint32_t MPFRCT;         /*!< (@ 0x00000308) MAC Pause Frame Receive Counter Register (MPFRCT)          */

        struct
        {
            __IOM uint32_t PFRC : 16;  /*!< [15..0] PFRC                                                              */
            uint32_t            : 16;
        } MPFRCT_b;
    };

    union
    {
        __IOM uint32_t MFCICT;         /*!< (@ 0x0000030C) MAC False Carrier Indication Counter Register
                                        *                  (MFCICT)                                                   */

        struct
        {
            __IOM uint32_t FCIC : 16;  /*!< [15..0] FCIC                                                              */
            uint32_t            : 16;
        } MFCICT_b;
    };

    union
    {
        __IOM uint32_t MEEECT;         /*!< (@ 0x00000310) MAC Energy Efficient Ethernet Counter Register
                                        *                  (MEEECT)                                                   */

        struct
        {
            __IOM uint32_t EEERC : 16; /*!< [15..0] EEERC                                                             */
            uint32_t             : 16;
        } MEEECT_b;
    };
    __IM uint32_t RESERVED16[3];

    union
    {
        __IOM uint32_t MMPCFTCT0;        /*!< (@ 0x00000320) MAC Manual PFC Frame Transmit Counter Register
                                          *                  (MMPCFTCTt) (t = 0, 1)                                     */

        struct
        {
            __IOM uint32_t MPCFCTC : 16; /*!< [15..0] MPCFCTC                                                           */
            uint32_t               : 16;
        } MMPCFTCT0_b;
    };

    union
    {
        __IOM uint32_t MMPCFTCT1;        /*!< (@ 0x00000324) MAC Manual PFC Frame Transmit Counter Register
                                          *                  (MMPCFTCTt) (t = 0, 1)                                     */

        struct
        {
            __IOM uint32_t MPCFCTC : 16; /*!< [15..0] MPCFCTC                                                           */
            uint32_t               : 16;
        } MMPCFTCT1_b;
    };
    __IM uint32_t RESERVED17[2];

    union
    {
        __IOM uint32_t MAPCFTCT0;        /*!< (@ 0x00000330) MAC Automatic PFC Frame Transmit Counter Register
                                          *                  (MAPCFTCTt) (t = 0, 1)                                     */

        struct
        {
            __IOM uint32_t APCFCTC : 16; /*!< [15..0] APCFCTC                                                           */
            uint32_t               : 16;
        } MAPCFTCT0_b;
    };

    union
    {
        __IOM uint32_t MAPCFTCT1;        /*!< (@ 0x00000334) MAC Automatic PFC Frame Transmit Counter Register
                                          *                  (MAPCFTCTt) (t = 0, 1)                                     */

        struct
        {
            __IOM uint32_t APCFCTC : 16; /*!< [15..0] APCFCTC                                                           */
            uint32_t               : 16;
        } MAPCFTCT1_b;
    };
    __IM uint32_t RESERVED18[2];

    union
    {
        __IOM uint32_t MPCFRCT0;        /*!< (@ 0x00000340) Bit Symbol Bit Name Description R/W                        */

        struct
        {
            __IOM uint32_t PCFCRC : 16; /*!< [15..0] PCFCRC                                                            */
            uint32_t              : 16;
        } MPCFRCT0_b;
    };

    union
    {
        __IOM uint32_t MPCFRCT1;        /*!< (@ 0x00000344) Bit Symbol Bit Name Description R/W                        */

        struct
        {
            __IOM uint32_t PCFCRC : 16; /*!< [15..0] PCFCRC                                                            */
            uint32_t              : 16;
        } MPCFRCT1_b;
    };

    union
    {
        __IOM uint32_t MPCFRCT2;        /*!< (@ 0x00000348) Bit Symbol Bit Name Description R/W                        */

        struct
        {
            __IOM uint32_t PCFCRC : 16; /*!< [15..0] PCFCRC                                                            */
            uint32_t              : 16;
        } MPCFRCT2_b;
    };

    union
    {
        __IOM uint32_t MPCFRCT3;        /*!< (@ 0x0000034C) Bit Symbol Bit Name Description R/W                        */

        struct
        {
            __IOM uint32_t PCFCRC : 16; /*!< [15..0] PCFCRC                                                            */
            uint32_t              : 16;
        } MPCFRCT3_b;
    };

    union
    {
        __IOM uint32_t MPCFRCT4;        /*!< (@ 0x00000350) Bit Symbol Bit Name Description R/W                        */

        struct
        {
            __IOM uint32_t PCFCRC : 16; /*!< [15..0] PCFCRC                                                            */
            uint32_t              : 16;
        } MPCFRCT4_b;
    };

    union
    {
        __IOM uint32_t MPCFRCT5;        /*!< (@ 0x00000354) Bit Symbol Bit Name Description R/W                        */

        struct
        {
            __IOM uint32_t PCFCRC : 16; /*!< [15..0] PCFCRC                                                            */
            uint32_t              : 16;
        } MPCFRCT5_b;
    };

    union
    {
        __IOM uint32_t MPCFRCT6;        /*!< (@ 0x00000358) Bit Symbol Bit Name Description R/W                        */

        struct
        {
            __IOM uint32_t PCFCRC : 16; /*!< [15..0] PCFCRC                                                            */
            uint32_t              : 16;
        } MPCFRCT6_b;
    };

    union
    {
        __IOM uint32_t MPCFRCT7;        /*!< (@ 0x0000035C) Bit Symbol Bit Name Description R/W                        */

        struct
        {
            __IOM uint32_t PCFCRC : 16; /*!< [15..0] PCFCRC                                                            */
            uint32_t              : 16;
        } MPCFRCT7_b;
    };

    union
    {
        __IOM uint32_t MROVFC;         /*!< (@ 0x00000360) Receive Overflow Counter Register (MROVFC)                 */

        struct
        {
            __IOM uint32_t ROVFC : 32; /*!< [31..0] ROVFC                                                             */
        } MROVFC_b;
    };

    union
    {
        __IOM uint32_t MRHCRCEC;         /*!< (@ 0x00000364) Reception Header-CRC(PCH CRC) Error Counter Register
                                          *                  (MRHCRCEC)                                                 */

        struct
        {
            __IOM uint32_t RHCRCEC : 16; /*!< [15..0] RHCRCEC                                                           */
            uint32_t               : 16;
        } MRHCRCEC_b;
    };
    __IM uint32_t RESERVED19[40];

    union
    {
        __IOM uint32_t MRGFCE;         /*!< (@ 0x00000408) RMAC Received Good Frame Counter E-Frames Register
                                        *                  (MRGFCE)                                                   */

        struct
        {
            __IOM uint32_t RGFNE : 32; /*!< [31..0] RGFNE                                                             */
        } MRGFCE_b;
    };

    union
    {
        __IOM uint32_t MRGFCP;         /*!< (@ 0x0000040C) RMAC Received Good Frame Counter P-Frames Register
                                        *                  (MRGFCP)                                                   */

        struct
        {
            __IOM uint32_t RGFNP : 32; /*!< [31..0] RGFNP                                                             */
        } MRGFCP_b;
    };

    union
    {
        __IOM uint32_t MRBFC;          /*!< (@ 0x00000410) Register (MRBFC)                                           */

        struct
        {
            __IOM uint32_t RBFN : 32;  /*!< [31..0] RBFN                                                              */
        } MRBFC_b;
    };

    union
    {
        __IOM uint32_t MRMFC;          /*!< (@ 0x00000414) RMAC Received Good Multicast Frame Counter Register
                                        *                  (MRMFC)                                                    */

        struct
        {
            __IOM uint32_t RMFN : 32;  /*!< [31..0] RMFN                                                              */
        } MRMFC_b;
    };

    union
    {
        __IOM uint32_t MRUFC;          /*!< (@ 0x00000418) RMAC Received Good Unicast Frame Counter Register
                                        *                  (MRUFC)                                                    */

        struct
        {
            __IOM uint32_t RUFN : 32;  /*!< [31..0] RUFN                                                              */
        } MRUFC_b;
    };

    union
    {
        __IOM uint32_t MRPEFC;         /*!< (@ 0x0000041C) Register (MRPEFC)                                          */

        struct
        {
            __IOM uint32_t RPEFN : 16; /*!< [15..0] RPEFN                                                             */
            uint32_t             : 16;
        } MRPEFC_b;
    };

    union
    {
        __IOM uint32_t MRNEFC;         /*!< (@ 0x00000420) Register (MRNEFC)                                          */

        struct
        {
            __IOM uint32_t RNEFN : 16; /*!< [15..0] RNEFN                                                             */
            uint32_t             : 16;
        } MRNEFC_b;
    };

    union
    {
        __IOM uint32_t MRFMEFC;         /*!< (@ 0x00000424) Register (MRFMEFC)                                         */

        struct
        {
            __IOM uint32_t RFMEFN : 32; /*!< [31..0] RFMEFN                                                            */
        } MRFMEFC_b;
    };

    union
    {
        __IOM uint32_t MRFFMEFC;         /*!< (@ 0x00000428) Register (MRFFMEFC)                                        */

        struct
        {
            __IOM uint32_t RFFMEFN : 16; /*!< [15..0] RFFMEFN                                                           */
            uint32_t               : 16;
        } MRFFMEFC_b;
    };

    union
    {
        __IOM uint32_t MRCFCEFC;         /*!< (@ 0x0000042C) Register (MRCFCEFC)                                        */

        struct
        {
            __IOM uint32_t RCFCEFN : 16; /*!< [15..0] RCFCEFN                                                           */
            uint32_t               : 16;
        } MRCFCEFC_b;
    };

    union
    {
        __IOM uint32_t MRFCEFC;         /*!< (@ 0x00000430) Register (MRFCEFC)                                         */

        struct
        {
            __IOM uint32_t RFCEFN : 16; /*!< [15..0] RFCEFN                                                            */
            uint32_t              : 16;
        } MRFCEFC_b;
    };

    union
    {
        __IOM uint32_t MRRCFEFC;         /*!< (@ 0x00000434) Register (MRRCFEFC)                                        */

        struct
        {
            __IOM uint32_t RRCFEFN : 16; /*!< [15..0] RRCFEFN                                                           */
            uint32_t               : 16;
        } MRRCFEFC_b;
    };

    union
    {
        __IOM uint32_t MRFC;           /*!< (@ 0x00000438) Register (MRFC)                                            */

        struct
        {
            __IOM uint32_t RFN : 32;   /*!< [31..0] RFN                                                               */
        } MRFC_b;
    };

    union
    {
        __IOM uint32_t MRGUEFC;        /*!< (@ 0x0000043C) RMAC Received Good Undersize Error Frame Count
                                        *                  Register (MRGUEFC)                                         */

        struct
        {
            __IOM uint32_t RUEFN : 32; /*!< [31..0] RUEFN                                                             */
        } MRGUEFC_b;
    };

    union
    {
        __IOM uint32_t MRBUEFC;        /*!< (@ 0x00000440) RMAC Received bad Undersize Error Frame Count
                                        *                  Register (MRBUEFC)                                         */

        struct
        {
            __IOM uint32_t RUEFN : 32; /*!< [31..0] RUEFN                                                             */
        } MRBUEFC_b;
    };

    union
    {
        __IOM uint32_t MRGOEFC;         /*!< (@ 0x00000444) Register (MRGOEFC)                                         */

        struct
        {
            __IOM uint32_t RGOEFN : 32; /*!< [31..0] RGOEFN                                                            */
        } MRGOEFC_b;
    };

    union
    {
        __IOM uint32_t MRBOEFC;         /*!< (@ 0x00000448) Register (MRBOEFC)                                         */

        struct
        {
            __IOM uint32_t RBOEFN : 32; /*!< [31..0] RBOEFN                                                            */
        } MRBOEFC_b;
    };

    union
    {
        __IOM uint32_t MRXBCEU;        /*!< (@ 0x0000044C) Register (MRXBCEU)                                         */

        struct
        {
            __IOM uint32_t RBNEU : 32; /*!< [31..0] RBNEU                                                             */
        } MRXBCEU_b;
    };

    union
    {
        __IOM uint32_t MRXBCEL;        /*!< (@ 0x00000450) Register (MRXBCEL)                                         */

        struct
        {
            __IOM uint32_t RBNEL : 32; /*!< [31..0] RBNEL                                                             */
        } MRXBCEL_b;
    };

    union
    {
        __IOM uint32_t MRXBCPU;        /*!< (@ 0x00000454) Register (MRXBCPU)                                         */

        struct
        {
            __IOM uint32_t RBNPU : 32; /*!< [31..0] RBNPU                                                             */
        } MRXBCPU_b;
    };

    union
    {
        __IOM uint32_t MRXBCPL;        /*!< (@ 0x00000458) Register (MRXBCPL)                                         */

        struct
        {
            __IOM uint32_t RBNPL : 32; /*!< [31..0] RBNPL                                                             */
        } MRXBCPL_b;
    };
    __IM uint32_t RESERVED20[43];

    union
    {
        __IOM uint32_t MTGFCE;         /*!< (@ 0x00000508) RMAC Transmitted Good Frame Counter E-Frames
                                        *                  Register (MTGFCE)                                          */

        struct
        {
            __IOM uint32_t TGFNE : 32; /*!< [31..0] TGFNE                                                             */
        } MTGFCE_b;
    };

    union
    {
        __IOM uint32_t MTGFCP;         /*!< (@ 0x0000050C) RMAC Transmitted Good Frame Counter P-Frames
                                        *                  Register (MTGFCP)                                          */

        struct
        {
            __IOM uint32_t TGFNP : 32; /*!< [31..0] TGFNP                                                             */
        } MTGFCP_b;
    };

    union
    {
        __IOM uint32_t MTBFC;          /*!< (@ 0x00000510) Register (MTBFC)                                           */

        struct
        {
            __IOM uint32_t TBFN : 32;  /*!< [31..0] TBFN                                                              */
        } MTBFC_b;
    };

    union
    {
        __IOM uint32_t MTMFC;          /*!< (@ 0x00000514) RMAC Transmitted Multicast Frame Counter Register
                                        *                  (MTMFC)                                                    */

        struct
        {
            __IOM uint32_t TMFN : 32;  /*!< [31..0] TMFN                                                              */
        } MTMFC_b;
    };

    union
    {
        __IOM uint32_t MTUFC;          /*!< (@ 0x00000518) Register (MTUFC)                                           */

        struct
        {
            __IOM uint32_t TUFN : 32;  /*!< [31..0] TUFN                                                              */
        } MTUFC_b;
    };

    union
    {
        __IOM uint32_t MTEFC;          /*!< (@ 0x0000051C) Register (MTEFC)                                           */

        struct
        {
            __IOM uint32_t TEFN : 16;  /*!< [15..0] TEFN                                                              */
            uint32_t            : 16;
        } MTEFC_b;
    };

    union
    {
        __IOM uint32_t MTXBCEU;        /*!< (@ 0x00000520) Register (MTXBCEU)                                         */

        struct
        {
            __IOM uint32_t TBNEU : 32; /*!< [31..0] TBNEU                                                             */
        } MTXBCEU_b;
    };

    union
    {
        __IOM uint32_t MTXBCEL;        /*!< (@ 0x00000524) Register (MTXBCEL)                                         */

        struct
        {
            __IOM uint32_t TBNEL : 32; /*!< [31..0] TBNEL                                                             */
        } MTXBCEL_b;
    };

    union
    {
        __IOM uint32_t MTXBCPU;        /*!< (@ 0x00000528) RMAC Transmitted Byte Counter P-Frames Upper
                                        *                  Side Register (MTXBCPU)                                    */

        struct
        {
            __IOM uint32_t TBNPU : 32; /*!< [31..0] TBNPU                                                             */
        } MTXBCPU_b;
    };

    union
    {
        __IOM uint32_t MTXBCPL;        /*!< (@ 0x0000052C) RMAC Transmitted Byte Counter P-Frames Lower
                                        *                  Side Register (MTXBCPL)                                    */

        struct
        {
            __IOM uint32_t TBNPL : 32; /*!< [31..0] TBNPL                                                             */
        } MTXBCPL_b;
    };
} R_RMAC0_Type;                        /*!< Size = 1328 (0x530)                                                       */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif                                 /* R_RMAC_REG_H */
