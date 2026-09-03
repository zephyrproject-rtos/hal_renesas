/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MFWD_REG_H
#define R_MFWD_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_MFWD                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Forwarding engine (R_MFWD)
 */

typedef struct                         /*!< (@ 0x874C0000) R_MFWD Structure                                           */
{
    union
    {
        __IOM uint32_t FWGC;           /*!< (@ 0x00000000) Forwarding Engine General Configuration Register
                                        *                  (FWGC)                                                     */

        struct
        {
            __IOM uint32_t SVM : 2;    /*!< [1..0] SVM                                                                */
            uint32_t           : 30;
        } FWGC_b;
    };
    __IM uint32_t RESERVED[3];

    union
    {
        __IOM uint32_t FWTTC0;         /*!< (@ 0x00000010) Forwarding Engine TAG TPID Configuration Register
                                        *                  0 (FWTTC0)                                                 */

        struct
        {
            __IOM uint32_t CTT : 16;   /*!< [15..0] CTT                                                               */
            __IOM uint32_t STT : 16;   /*!< [31..16] STT                                                              */
        } FWTTC0_b;
    };

    union
    {
        __IOM uint32_t FWTTC1;         /*!< (@ 0x00000014) Forwarding Engine TAG TPID Configuration Register
                                        *                  1 (FWTTC1)                                                 */

        struct
        {
            __IOM uint32_t RTT : 16;   /*!< [15..0] RTT                                                               */
            uint32_t           : 16;
        } FWTTC1_b;
    };
    __IM uint32_t RESERVED1[2];

    union
    {
        __IOM uint32_t FWCEPTC;        /*!< (@ 0x00000020) Forwarding Engine CPU Exceptional Path Target
                                        *                  Configuration Register (FWCEPTC)                           */

        struct
        {
            __IOM uint32_t EPCSD : 6;  /*!< [5..0] EPCSD                                                              */
            uint32_t             : 6;
            __IOM uint32_t EPIPV : 3;  /*!< [14..12] EPIPV                                                            */
            uint32_t             : 1;
            __IOM uint32_t EPCS  : 1;  /*!< [16..16] EPCS                                                             */
            uint32_t             : 7;
            __IOM uint32_t EPSL  : 1;  /*!< [24..24] EPSL                                                             */
            uint32_t             : 7;
        } FWCEPTC_b;
    };

    union
    {
        __IOM uint32_t FWCEPRC0;         /*!< (@ 0x00000024) Forwarding Engine CPU Exceptional Path Reason
                                          *                  Configuration Register 0 (FWCEPRC0)                        */

        struct
        {
            __IOM uint32_t EPHYEEF  : 1; /*!< [0..0] EPHYEEF                                                            */
            __IOM uint32_t EPCRCEEF : 1; /*!< [1..1] EPCRCEEF                                                           */
            __IOM uint32_t ENIBEEF  : 1; /*!< [2..2] ENIBEEF                                                            */
            __IOM uint32_t EFCSEEF  : 1; /*!< [3..3] EFCSEEF                                                            */
            __IOM uint32_t EFFMEEF  : 1; /*!< [4..4] EFFMEEF                                                            */
            __IOM uint32_t ECFSEEF  : 1; /*!< [5..5] ECFSEEF                                                            */
            __IOM uint32_t ECFFCEEF : 1; /*!< [6..6] ECFFCEEF                                                           */
            __IOM uint32_t ERFFEF   : 1; /*!< [7..7] ERFFEF                                                             */
            __IOM uint32_t ERPOOEF  : 1; /*!< [8..8] ERPOOEF                                                            */
            __IOM uint32_t EBOEEF   : 1; /*!< [9..9] EBOEEF                                                             */
            __IOM uint32_t EUEEF    : 1; /*!< [10..10] EUEEF                                                            */
            __IOM uint32_t EOEEF    : 1; /*!< [11..11] EOEEF                                                            */
            __IOM uint32_t ETFEF    : 1; /*!< [12..12] ETFEF                                                            */
            uint32_t                : 3;
            __IOM uint32_t GAREEEF  : 1; /*!< [16..16] GAREEEF                                                          */
            uint32_t                : 1;
            __IOM uint32_t GAXEEF   : 1; /*!< [18..18] GAXEEF                                                           */
            uint32_t                : 1;
            __IOM uint32_t GTFEF    : 1; /*!< [20..20] GTFEF                                                            */
            __IOM uint32_t GDNEEF   : 1; /*!< [21..21] GDNEEF                                                           */
            uint32_t                : 2;
            __IOM uint32_t DDEEF    : 1; /*!< [24..24] DDEEF                                                            */
            uint32_t                : 1;
            __IOM uint32_t DDFSFEF  : 1; /*!< [26..26] DDFSFEF                                                          */
            uint32_t                : 5;
        } FWCEPRC0_b;
    };

    union
    {
        __IOM uint32_t FWCEPRC1;         /*!< (@ 0x00000028) Forwarding Engine CPU Exceptional Path Reason
                                          *                  Configuration Register 1 (FWCEPRC1)                        */

        struct
        {
            __IOM uint32_t FMSDUFEF : 1; /*!< [0..0] FMSDUFEF                                                           */
            uint32_t                : 1;
            __IOM uint32_t FMTRFEF  : 1; /*!< [2..2] FMTRFEF                                                            */
            uint32_t                : 5;
            __IOM uint32_t FIFFEF   : 1; /*!< [8..8] FIFFEF                                                             */
            __IOM uint32_t FSFFEF   : 1; /*!< [9..9] FSFFEF                                                             */
            uint32_t                : 22;
        } FWCEPRC1_b;
    };

    union
    {
        __IOM uint32_t FWCEPRC2;           /*!< (@ 0x0000002C) Forwarding Engine CPU Exceptional Path Reason
                                            *                  Configuration Register 2 (FWCEPRC2)                        */

        struct
        {
            __IOM uint32_t FLTHUFEF   : 1; /*!< [0..0] FLTHUFEF                                                           */
            uint32_t                  : 2;
            __IOM uint32_t FDMACUFEF  : 1; /*!< [3..3] FDMACUFEF                                                          */
            __IOM uint32_t FSMACUFEF  : 1; /*!< [4..4] FSMACUFEF                                                          */
            __IOM uint32_t FVLANUFEF  : 1; /*!< [5..5] FVLANUFEF                                                          */
            uint32_t                  : 2;
            __IOM uint32_t FDDNTFEF   : 1; /*!< [8..8] FDDNTFEF                                                           */
            __IOM uint32_t FLTHNTFEF  : 1; /*!< [9..9] FLTHNTFEF                                                          */
            uint32_t                  : 1;
            __IOM uint32_t FLTWNTFEF  : 1; /*!< [11..11] FLTWNTFEF                                                        */
            __IOM uint32_t FPBNTFEF   : 1; /*!< [12..12] FPBNTFEF                                                         */
            uint32_t                  : 3;
            __IOM uint32_t FLTHSLFEF  : 1; /*!< [16..16] FLTHSLFEF                                                        */
            uint32_t                  : 2;
            __IOM uint32_t FDMACSLFEF : 1; /*!< [19..19] FDMACSLFEF                                                       */
            __IOM uint32_t FSMACSLFEF : 1; /*!< [20..20] FSMACSLFEF                                                       */
            __IOM uint32_t FVLANSLFEF : 1; /*!< [21..21] FVLANSLFEF                                                       */
            uint32_t                  : 4;
            __IOM uint32_t FWMFEF     : 1; /*!< [26..26] FWMFEF                                                           */
            uint32_t                  : 5;
        } FWCEPRC2_b;
    };

    union
    {
        __IOM uint32_t FWCLPTC;        /*!< (@ 0x00000030) Forwarding Engine CPU Learning Path Target Configuration
                                        *                  Register (FWCLPTC)                                         */

        struct
        {
            __IOM uint32_t LPCSD : 6;  /*!< [5..0] LPCSD                                                              */
            uint32_t             : 6;
            __IOM uint32_t LPIPV : 3;  /*!< [14..12] LPIPV                                                            */
            uint32_t             : 1;
            __IOM uint32_t LPCS  : 1;  /*!< [16..16] LPCS                                                             */
            uint32_t             : 7;
            __IOM uint32_t LPSL  : 1;  /*!< [24..24] LPSL                                                             */
            uint32_t             : 7;
        } FWCLPTC_b;
    };

    union
    {
        __IOM uint32_t FWCLPRC;          /*!< (@ 0x00000034) Forwarding Engine CPU Learning Path Reason Configuration
                                          *                  Register (FWCLPRC)                                         */

        struct
        {
            __IOM uint32_t USIDLF   : 1; /*!< [0..0] USIDLF                                                             */
            uint32_t                : 3;
            __IOM uint32_t UDMACLF  : 1; /*!< [4..4] UDMACLF                                                            */
            __IOM uint32_t USMACLF  : 1; /*!< [5..5] USMACLF                                                            */
            __IOM uint32_t UPSMACLF : 1; /*!< [6..6] UPSMACLF                                                           */
            __IOM uint32_t UVLANLF  : 1; /*!< [7..7] UVLANLF                                                            */
            uint32_t                : 24;
        } FWCLPRC_b;
    };
    __IM uint32_t RESERVED2[2];

    union
    {
        __IOM uint32_t FWCMPTC;        /*!< (@ 0x00000040) Forwarding Engine CPU Mirroring Path Target Configuration
                                        *                  Register (FWCMPTC)                                         */

        struct
        {
            __IOM uint32_t CMPCSD : 6; /*!< [5..0] CMPCSD                                                             */
            uint32_t              : 6;
            __IOM uint32_t CMPIPV : 3; /*!< [14..12] CMPIPV                                                           */
            __IOM uint32_t CMPIPU : 1; /*!< [15..15] CMPIPU                                                           */
            __IOM uint32_t CMPCS  : 1; /*!< [16..16] CMPCS                                                            */
            uint32_t              : 7;
            __IOM uint32_t CMPSL  : 1; /*!< [24..24] CMPSL                                                            */
            uint32_t              : 7;
        } FWCMPTC_b;
    };

    union
    {
        __IOM uint32_t FWEMPTC;        /*!< (@ 0x00000044) Forwarding Engine Ethernet Mirroring Path Target
                                        *                  Configuration Register (FWEMPTC)                           */

        struct
        {
            uint32_t              : 12;
            __IOM uint32_t EMPIPV : 3; /*!< [14..12] EMPIPV                                                           */
            __IOM uint32_t EMPIPU : 1; /*!< [15..15] EMPIPU                                                           */
            __IOM uint32_t EMPPS  : 1; /*!< [16..16] EMPPS                                                            */
            uint32_t              : 7;
            __IOM uint32_t EMPSL  : 1; /*!< [24..24] EMPSL                                                            */
            uint32_t              : 7;
        } FWEMPTC_b;
    };
    __IM uint32_t RESERVED3[2];

    union
    {
        __IOM uint32_t FWSDMPTC;        /*!< (@ 0x00000050) Forwarding Engine Source-Destination Mirroring
                                         *                  Path Target Configuration Register (FWSDMPTC)              */

        struct
        {
            __IOM uint32_t SDMPCSD : 6; /*!< [5..0] SDMPCSD                                                            */
            uint32_t               : 6;
            __IOM uint32_t SDMPIPV : 3; /*!< [14..12] SDMPIPV                                                          */
            __IOM uint32_t SDMPIPU : 1; /*!< [15..15] SDMPIPU                                                          */
            __IOM uint32_t SDMPPS  : 2; /*!< [17..16] SDMPPS                                                           */
            uint32_t               : 6;
            __IOM uint32_t SDMPSL  : 1; /*!< [24..24] SDMPSL                                                           */
            uint32_t               : 7;
        } FWSDMPTC_b;
    };

    union
    {
        __IOM uint32_t FWSDMPVC;       /*!< (@ 0x00000054) Forwarding Engine Source-Destination Mirroring
                                        *                  Path Vector Configuration Register (FWSDMPVC)              */

        struct
        {
            __IOM uint32_t SDMDV : 3;  /*!< [2..0] SDMDV                                                              */
            uint32_t             : 13;
            __IOM uint32_t SDMSV : 3;  /*!< [18..16] SDMSV                                                            */
            uint32_t             : 13;
        } FWSDMPVC_b;
    };
    __IM uint32_t RESERVED4[10];

    union
    {
        __IOM uint32_t FWLBWMC0;         /*!< (@ 0x00000080) Forwarding Engine Level Based Watermark Configuration
                                          *                  Register i (FWLBWMCi) (i = 0 to 2)                         */

        struct
        {
            __IOM uint32_t WMCLPR0  : 1; /*!< [0..0] WMCLPR0                                                            */
            __IOM uint32_t WMCLPR1  : 1; /*!< [1..1] WMCLPR1                                                            */
            __IOM uint32_t WMCLPR2  : 1; /*!< [2..2] WMCLPR2                                                            */
            __IOM uint32_t WMCLPR3  : 1; /*!< [3..3] WMCLPR3                                                            */
            __IOM uint32_t WMCLPR4  : 1; /*!< [4..4] WMCLPR4                                                            */
            __IOM uint32_t WMCLPR5  : 1; /*!< [5..5] WMCLPR5                                                            */
            __IOM uint32_t WMCLPR6  : 1; /*!< [6..6] WMCLPR6                                                            */
            __IOM uint32_t WMCLPR7  : 1; /*!< [7..7] WMCLPR7                                                            */
            __IOM uint32_t WMCLPR8  : 1; /*!< [8..8] WMCLPR8                                                            */
            __IOM uint32_t WMCLPR9  : 1; /*!< [9..9] WMCLPR9                                                            */
            __IOM uint32_t WMCLPR10 : 1; /*!< [10..10] WMCLPR10                                                         */
            __IOM uint32_t WMCLPR11 : 1; /*!< [11..11] WMCLPR11                                                         */
            __IOM uint32_t WMCLPR12 : 1; /*!< [12..12] WMCLPR12                                                         */
            __IOM uint32_t WMCLPR13 : 1; /*!< [13..13] WMCLPR13                                                         */
            __IOM uint32_t WMCLPR14 : 1; /*!< [14..14] WMCLPR14                                                         */
            __IOM uint32_t WMCLPR15 : 1; /*!< [15..15] WMCLPR15                                                         */
            __IOM uint32_t WMFLPR0  : 1; /*!< [16..16] WMFLPR0                                                          */
            __IOM uint32_t WMFLPR1  : 1; /*!< [17..17] WMFLPR1                                                          */
            __IOM uint32_t WMFLPR2  : 1; /*!< [18..18] WMFLPR2                                                          */
            __IOM uint32_t WMFLPR3  : 1; /*!< [19..19] WMFLPR3                                                          */
            __IOM uint32_t WMFLPR4  : 1; /*!< [20..20] WMFLPR4                                                          */
            __IOM uint32_t WMFLPR5  : 1; /*!< [21..21] WMFLPR5                                                          */
            __IOM uint32_t WMFLPR6  : 1; /*!< [22..22] WMFLPR6                                                          */
            __IOM uint32_t WMFLPR7  : 1; /*!< [23..23] WMFLPR7                                                          */
            __IOM uint32_t WMFLPR8  : 1; /*!< [24..24] WMFLPR8                                                          */
            __IOM uint32_t WMFLPR9  : 1; /*!< [25..25] WMFLPR9                                                          */
            __IOM uint32_t WMFLPR10 : 1; /*!< [26..26] WMFLPR10                                                         */
            __IOM uint32_t WMFLPR11 : 1; /*!< [27..27] WMFLPR11                                                         */
            __IOM uint32_t WMFLPR12 : 1; /*!< [28..28] WMFLPR12                                                         */
            __IOM uint32_t WMFLPR13 : 1; /*!< [29..29] WMFLPR13                                                         */
            __IOM uint32_t WMFLPR14 : 1; /*!< [30..30] WMFLPR14                                                         */
            __IOM uint32_t WMFLPR15 : 1; /*!< [31..31] WMFLPR15                                                         */
        } FWLBWMC0_b;
    };

    union
    {
        __IOM uint32_t FWLBWMC1;         /*!< (@ 0x00000084) Forwarding Engine Level Based Watermark Configuration
                                          *                  Register i (FWLBWMCi) (i = 0 to 2)                         */

        struct
        {
            __IOM uint32_t WMCLPR0  : 1; /*!< [0..0] WMCLPR0                                                            */
            __IOM uint32_t WMCLPR1  : 1; /*!< [1..1] WMCLPR1                                                            */
            __IOM uint32_t WMCLPR2  : 1; /*!< [2..2] WMCLPR2                                                            */
            __IOM uint32_t WMCLPR3  : 1; /*!< [3..3] WMCLPR3                                                            */
            __IOM uint32_t WMCLPR4  : 1; /*!< [4..4] WMCLPR4                                                            */
            __IOM uint32_t WMCLPR5  : 1; /*!< [5..5] WMCLPR5                                                            */
            __IOM uint32_t WMCLPR6  : 1; /*!< [6..6] WMCLPR6                                                            */
            __IOM uint32_t WMCLPR7  : 1; /*!< [7..7] WMCLPR7                                                            */
            __IOM uint32_t WMCLPR8  : 1; /*!< [8..8] WMCLPR8                                                            */
            __IOM uint32_t WMCLPR9  : 1; /*!< [9..9] WMCLPR9                                                            */
            __IOM uint32_t WMCLPR10 : 1; /*!< [10..10] WMCLPR10                                                         */
            __IOM uint32_t WMCLPR11 : 1; /*!< [11..11] WMCLPR11                                                         */
            __IOM uint32_t WMCLPR12 : 1; /*!< [12..12] WMCLPR12                                                         */
            __IOM uint32_t WMCLPR13 : 1; /*!< [13..13] WMCLPR13                                                         */
            __IOM uint32_t WMCLPR14 : 1; /*!< [14..14] WMCLPR14                                                         */
            __IOM uint32_t WMCLPR15 : 1; /*!< [15..15] WMCLPR15                                                         */
            __IOM uint32_t WMFLPR0  : 1; /*!< [16..16] WMFLPR0                                                          */
            __IOM uint32_t WMFLPR1  : 1; /*!< [17..17] WMFLPR1                                                          */
            __IOM uint32_t WMFLPR2  : 1; /*!< [18..18] WMFLPR2                                                          */
            __IOM uint32_t WMFLPR3  : 1; /*!< [19..19] WMFLPR3                                                          */
            __IOM uint32_t WMFLPR4  : 1; /*!< [20..20] WMFLPR4                                                          */
            __IOM uint32_t WMFLPR5  : 1; /*!< [21..21] WMFLPR5                                                          */
            __IOM uint32_t WMFLPR6  : 1; /*!< [22..22] WMFLPR6                                                          */
            __IOM uint32_t WMFLPR7  : 1; /*!< [23..23] WMFLPR7                                                          */
            __IOM uint32_t WMFLPR8  : 1; /*!< [24..24] WMFLPR8                                                          */
            __IOM uint32_t WMFLPR9  : 1; /*!< [25..25] WMFLPR9                                                          */
            __IOM uint32_t WMFLPR10 : 1; /*!< [26..26] WMFLPR10                                                         */
            __IOM uint32_t WMFLPR11 : 1; /*!< [27..27] WMFLPR11                                                         */
            __IOM uint32_t WMFLPR12 : 1; /*!< [28..28] WMFLPR12                                                         */
            __IOM uint32_t WMFLPR13 : 1; /*!< [29..29] WMFLPR13                                                         */
            __IOM uint32_t WMFLPR14 : 1; /*!< [30..30] WMFLPR14                                                         */
            __IOM uint32_t WMFLPR15 : 1; /*!< [31..31] WMFLPR15                                                         */
        } FWLBWMC1_b;
    };

    union
    {
        __IOM uint32_t FWLBWMC2;         /*!< (@ 0x00000088) Forwarding Engine Level Based Watermark Configuration
                                          *                  Register i (FWLBWMCi) (i = 0 to 2)                         */

        struct
        {
            __IOM uint32_t WMCLPR0  : 1; /*!< [0..0] WMCLPR0                                                            */
            __IOM uint32_t WMCLPR1  : 1; /*!< [1..1] WMCLPR1                                                            */
            __IOM uint32_t WMCLPR2  : 1; /*!< [2..2] WMCLPR2                                                            */
            __IOM uint32_t WMCLPR3  : 1; /*!< [3..3] WMCLPR3                                                            */
            __IOM uint32_t WMCLPR4  : 1; /*!< [4..4] WMCLPR4                                                            */
            __IOM uint32_t WMCLPR5  : 1; /*!< [5..5] WMCLPR5                                                            */
            __IOM uint32_t WMCLPR6  : 1; /*!< [6..6] WMCLPR6                                                            */
            __IOM uint32_t WMCLPR7  : 1; /*!< [7..7] WMCLPR7                                                            */
            __IOM uint32_t WMCLPR8  : 1; /*!< [8..8] WMCLPR8                                                            */
            __IOM uint32_t WMCLPR9  : 1; /*!< [9..9] WMCLPR9                                                            */
            __IOM uint32_t WMCLPR10 : 1; /*!< [10..10] WMCLPR10                                                         */
            __IOM uint32_t WMCLPR11 : 1; /*!< [11..11] WMCLPR11                                                         */
            __IOM uint32_t WMCLPR12 : 1; /*!< [12..12] WMCLPR12                                                         */
            __IOM uint32_t WMCLPR13 : 1; /*!< [13..13] WMCLPR13                                                         */
            __IOM uint32_t WMCLPR14 : 1; /*!< [14..14] WMCLPR14                                                         */
            __IOM uint32_t WMCLPR15 : 1; /*!< [15..15] WMCLPR15                                                         */
            __IOM uint32_t WMFLPR0  : 1; /*!< [16..16] WMFLPR0                                                          */
            __IOM uint32_t WMFLPR1  : 1; /*!< [17..17] WMFLPR1                                                          */
            __IOM uint32_t WMFLPR2  : 1; /*!< [18..18] WMFLPR2                                                          */
            __IOM uint32_t WMFLPR3  : 1; /*!< [19..19] WMFLPR3                                                          */
            __IOM uint32_t WMFLPR4  : 1; /*!< [20..20] WMFLPR4                                                          */
            __IOM uint32_t WMFLPR5  : 1; /*!< [21..21] WMFLPR5                                                          */
            __IOM uint32_t WMFLPR6  : 1; /*!< [22..22] WMFLPR6                                                          */
            __IOM uint32_t WMFLPR7  : 1; /*!< [23..23] WMFLPR7                                                          */
            __IOM uint32_t WMFLPR8  : 1; /*!< [24..24] WMFLPR8                                                          */
            __IOM uint32_t WMFLPR9  : 1; /*!< [25..25] WMFLPR9                                                          */
            __IOM uint32_t WMFLPR10 : 1; /*!< [26..26] WMFLPR10                                                         */
            __IOM uint32_t WMFLPR11 : 1; /*!< [27..27] WMFLPR11                                                         */
            __IOM uint32_t WMFLPR12 : 1; /*!< [28..28] WMFLPR12                                                         */
            __IOM uint32_t WMFLPR13 : 1; /*!< [29..29] WMFLPR13                                                         */
            __IOM uint32_t WMFLPR14 : 1; /*!< [30..30] WMFLPR14                                                         */
            __IOM uint32_t WMFLPR15 : 1; /*!< [31..31] WMFLPR15                                                         */
        } FWLBWMC2_b;
    };
    __IM uint32_t RESERVED5[29];

    union
    {
        __IOM uint32_t FWPC00;           /*!< (@ 0x00000100) Forwarding Engine Port Configuration Register
                                          *                  0i (FWPC0i) (i = 0 to 2)                                   */

        struct
        {
            __IOM uint32_t LTHTA    : 1; /*!< [0..0] LTHTA                                                              */
            __IOM uint32_t LTHRUS   : 1; /*!< [1..1] LTHRUS                                                             */
            __IOM uint32_t LTHRUSS  : 1; /*!< [2..2] LTHRUSS                                                            */
            __IOM uint32_t IP4UE    : 1; /*!< [3..3] IP4UE                                                              */
            __IOM uint32_t IP4TE    : 1; /*!< [4..4] IP4TE                                                              */
            __IOM uint32_t IP4OE    : 1; /*!< [5..5] IP4OE                                                              */
            __IOM uint32_t IP6UE    : 1; /*!< [6..6] IP6UE                                                              */
            __IOM uint32_t IP6TE    : 1; /*!< [7..7] IP6TE                                                              */
            __IOM uint32_t IP6OE    : 1; /*!< [8..8] IP6OE                                                              */
            __IOM uint32_t L2SE     : 1; /*!< [9..9] L2SE                                                               */
            uint32_t                : 10;
            __IOM uint32_t MACDSA   : 1; /*!< [20..20] MACDSA                                                           */
            __IOM uint32_t MACRUDA  : 1; /*!< [21..21] MACRUDA                                                          */
            __IOM uint32_t MACRUDSA : 1; /*!< [22..22] MACRUDSA                                                         */
            __IOM uint32_t MACSSA   : 1; /*!< [23..23] MACSSA                                                           */
            __IOM uint32_t MACRUSA  : 1; /*!< [24..24] MACRUSA                                                          */
            __IOM uint32_t MACRUSSA : 1; /*!< [25..25] MACRUSSA                                                         */
            __IOM uint32_t MACHLA   : 1; /*!< [26..26] MACHLA                                                           */
            __IOM uint32_t MACHMA   : 1; /*!< [27..27] MACHMA                                                           */
            __IOM uint32_t VLANSA   : 1; /*!< [28..28] VLANSA                                                           */
            __IOM uint32_t VLANRU   : 1; /*!< [29..29] VLANRU                                                           */
            __IOM uint32_t VLANRUS  : 1; /*!< [30..30] VLANRUS                                                          */
            uint32_t                : 1;
        } FWPC00_b;
    };

    union
    {
        __IOM uint32_t FWPC01;         /*!< (@ 0x00000104) Forwarding Engine Port Configuration Register
                                        *                  1i (FWPC1i) (i = 0 to 2)                                   */

        struct
        {
            __IOM uint32_t DDE    : 1; /*!< [0..0] DDE                                                                */
            __IOM uint32_t DDSL   : 1; /*!< [1..1] DDSL                                                               */
            uint32_t              : 14;
            __IOM uint32_t LTHFM0 : 1; /*!< [16..16] LTHFM0                                                           */
            __IOM uint32_t LTHFM1 : 1; /*!< [17..17] LTHFM1                                                           */
            __IOM uint32_t LTHFM2 : 1; /*!< [18..18] LTHFM2                                                           */
            uint32_t              : 13;
        } FWPC01_b;
    };

    union
    {
        __IOM uint32_t FWPC02;         /*!< (@ 0x00000108) Forwarding Engine Port Configuration Register
                                        *                  2i (FWPC2i) (i = 0 to 2)                                   */

        struct
        {
            uint32_t              : 16;
            __IOM uint32_t LTWFM0 : 1; /*!< [16..16] LTWFM0                                                           */
            __IOM uint32_t LTWFM1 : 1; /*!< [17..17] LTWFM1                                                           */
            __IOM uint32_t LTWFM2 : 1; /*!< [18..18] LTWFM2                                                           */
            uint32_t              : 13;
        } FWPC02_b;
    };
    __IM uint32_t RESERVED6;

    union
    {
        __IOM uint32_t FWPC10;           /*!< (@ 0x00000110) Forwarding Engine Port Configuration Register
                                          *                  0i (FWPC0i) (i = 0 to 2)                                   */

        struct
        {
            __IOM uint32_t LTHTA    : 1; /*!< [0..0] LTHTA                                                              */
            __IOM uint32_t LTHRUS   : 1; /*!< [1..1] LTHRUS                                                             */
            __IOM uint32_t LTHRUSS  : 1; /*!< [2..2] LTHRUSS                                                            */
            __IOM uint32_t IP4UE    : 1; /*!< [3..3] IP4UE                                                              */
            __IOM uint32_t IP4TE    : 1; /*!< [4..4] IP4TE                                                              */
            __IOM uint32_t IP4OE    : 1; /*!< [5..5] IP4OE                                                              */
            __IOM uint32_t IP6UE    : 1; /*!< [6..6] IP6UE                                                              */
            __IOM uint32_t IP6TE    : 1; /*!< [7..7] IP6TE                                                              */
            __IOM uint32_t IP6OE    : 1; /*!< [8..8] IP6OE                                                              */
            __IOM uint32_t L2SE     : 1; /*!< [9..9] L2SE                                                               */
            uint32_t                : 10;
            __IOM uint32_t MACDSA   : 1; /*!< [20..20] MACDSA                                                           */
            __IOM uint32_t MACRUDA  : 1; /*!< [21..21] MACRUDA                                                          */
            __IOM uint32_t MACRUDSA : 1; /*!< [22..22] MACRUDSA                                                         */
            __IOM uint32_t MACSSA   : 1; /*!< [23..23] MACSSA                                                           */
            __IOM uint32_t MACRUSA  : 1; /*!< [24..24] MACRUSA                                                          */
            __IOM uint32_t MACRUSSA : 1; /*!< [25..25] MACRUSSA                                                         */
            __IOM uint32_t MACHLA   : 1; /*!< [26..26] MACHLA                                                           */
            __IOM uint32_t MACHMA   : 1; /*!< [27..27] MACHMA                                                           */
            __IOM uint32_t VLANSA   : 1; /*!< [28..28] VLANSA                                                           */
            __IOM uint32_t VLANRU   : 1; /*!< [29..29] VLANRU                                                           */
            __IOM uint32_t VLANRUS  : 1; /*!< [30..30] VLANRUS                                                          */
            uint32_t                : 1;
        } FWPC10_b;
    };

    union
    {
        __IOM uint32_t FWPC11;         /*!< (@ 0x00000114) Forwarding Engine Port Configuration Register
                                        *                  1i (FWPC1i) (i = 0 to 2)                                   */

        struct
        {
            __IOM uint32_t DDE    : 1; /*!< [0..0] DDE                                                                */
            __IOM uint32_t DDSL   : 1; /*!< [1..1] DDSL                                                               */
            uint32_t              : 14;
            __IOM uint32_t LTHFM0 : 1; /*!< [16..16] LTHFM0                                                           */
            __IOM uint32_t LTHFM1 : 1; /*!< [17..17] LTHFM1                                                           */
            __IOM uint32_t LTHFM2 : 1; /*!< [18..18] LTHFM2                                                           */
            uint32_t              : 13;
        } FWPC11_b;
    };

    union
    {
        __IOM uint32_t FWPC12;         /*!< (@ 0x00000118) Forwarding Engine Port Configuration Register
                                        *                  2i (FWPC2i) (i = 0 to 2)                                   */

        struct
        {
            uint32_t              : 16;
            __IOM uint32_t LTWFM0 : 1; /*!< [16..16] LTWFM0                                                           */
            __IOM uint32_t LTWFM1 : 1; /*!< [17..17] LTWFM1                                                           */
            __IOM uint32_t LTWFM2 : 1; /*!< [18..18] LTWFM2                                                           */
            uint32_t              : 13;
        } FWPC12_b;
    };
    __IM uint32_t RESERVED7;

    union
    {
        __IOM uint32_t FWPC20;           /*!< (@ 0x00000120) Forwarding Engine Port Configuration Register
                                          *                  0i (FWPC0i) (i = 0 to 2)                                   */

        struct
        {
            __IOM uint32_t LTHTA    : 1; /*!< [0..0] LTHTA                                                              */
            __IOM uint32_t LTHRUS   : 1; /*!< [1..1] LTHRUS                                                             */
            __IOM uint32_t LTHRUSS  : 1; /*!< [2..2] LTHRUSS                                                            */
            __IOM uint32_t IP4UE    : 1; /*!< [3..3] IP4UE                                                              */
            __IOM uint32_t IP4TE    : 1; /*!< [4..4] IP4TE                                                              */
            __IOM uint32_t IP4OE    : 1; /*!< [5..5] IP4OE                                                              */
            __IOM uint32_t IP6UE    : 1; /*!< [6..6] IP6UE                                                              */
            __IOM uint32_t IP6TE    : 1; /*!< [7..7] IP6TE                                                              */
            __IOM uint32_t IP6OE    : 1; /*!< [8..8] IP6OE                                                              */
            __IOM uint32_t L2SE     : 1; /*!< [9..9] L2SE                                                               */
            uint32_t                : 10;
            __IOM uint32_t MACDSA   : 1; /*!< [20..20] MACDSA                                                           */
            __IOM uint32_t MACRUDA  : 1; /*!< [21..21] MACRUDA                                                          */
            __IOM uint32_t MACRUDSA : 1; /*!< [22..22] MACRUDSA                                                         */
            __IOM uint32_t MACSSA   : 1; /*!< [23..23] MACSSA                                                           */
            __IOM uint32_t MACRUSA  : 1; /*!< [24..24] MACRUSA                                                          */
            __IOM uint32_t MACRUSSA : 1; /*!< [25..25] MACRUSSA                                                         */
            __IOM uint32_t MACHLA   : 1; /*!< [26..26] MACHLA                                                           */
            __IOM uint32_t MACHMA   : 1; /*!< [27..27] MACHMA                                                           */
            __IOM uint32_t VLANSA   : 1; /*!< [28..28] VLANSA                                                           */
            __IOM uint32_t VLANRU   : 1; /*!< [29..29] VLANRU                                                           */
            __IOM uint32_t VLANRUS  : 1; /*!< [30..30] VLANRUS                                                          */
            uint32_t                : 1;
        } FWPC20_b;
    };

    union
    {
        __IOM uint32_t FWPC21;         /*!< (@ 0x00000124) Forwarding Engine Port Configuration Register
                                        *                  1i (FWPC1i) (i = 0 to 2)                                   */

        struct
        {
            __IOM uint32_t DDE    : 1; /*!< [0..0] DDE                                                                */
            __IOM uint32_t DDSL   : 1; /*!< [1..1] DDSL                                                               */
            uint32_t              : 14;
            __IOM uint32_t LTHFM0 : 1; /*!< [16..16] LTHFM0                                                           */
            __IOM uint32_t LTHFM1 : 1; /*!< [17..17] LTHFM1                                                           */
            __IOM uint32_t LTHFM2 : 1; /*!< [18..18] LTHFM2                                                           */
            uint32_t              : 13;
        } FWPC21_b;
    };

    union
    {
        __IOM uint32_t FWPC22;         /*!< (@ 0x00000128) Forwarding Engine Port Configuration Register
                                        *                  2i (FWPC2i) (i = 0 to 2)                                   */

        struct
        {
            uint32_t              : 16;
            __IOM uint32_t LTWFM0 : 1; /*!< [16..16] LTWFM0                                                           */
            __IOM uint32_t LTWFM1 : 1; /*!< [17..17] LTWFM1                                                           */
            __IOM uint32_t LTWFM2 : 1; /*!< [18..18] LTWFM2                                                           */
            uint32_t              : 13;
        } FWPC22_b;
    };
    __IM uint32_t RESERVED8[181];

    union
    {
        __IOM uint32_t FWCTGC00;        /*!< (@ 0x00000400) Forwarding Engine Cut-Through General Configuration
                                         *                  Register 0i (FWCTGC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMDE   : 1; /*!< [0..0] CTMDE                                                              */
            __IOM uint32_t CTMSE   : 1; /*!< [1..1] CTMSE                                                              */
            __IOM uint32_t CTCVE   : 1; /*!< [2..2] CTCVE                                                              */
            __IOM uint32_t CTCPE   : 1; /*!< [3..3] CTCPE                                                              */
            __IOM uint32_t CTCDE   : 1; /*!< [4..4] CTCDE                                                              */
            __IOM uint32_t CTSVE   : 1; /*!< [5..5] CTSVE                                                              */
            __IOM uint32_t CTSPE   : 1; /*!< [6..6] CTSPE                                                              */
            __IOM uint32_t CTSDE   : 1; /*!< [7..7] CTSDE                                                              */
            __IOM uint32_t CTETE   : 1; /*!< [8..8] CTETE                                                              */
            uint32_t               : 2;
            __IOM uint32_t CTFI    : 1; /*!< [11..11] CTFI                                                             */
            __IOM uint32_t CTVCTRL : 2; /*!< [13..12] CTVCTRL                                                          */
            __IOM uint32_t CTRTGI  : 1; /*!< [14..14] CTRTGI                                                           */
            uint32_t               : 17;
        } FWCTGC00_b;
    };

    union
    {
        __IOM uint32_t FWCTGC01;       /*!< (@ 0x00000404) Forwarding Engine Cut-Through General Configuration
                                        *                  Register 1i (FWCTGC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMT : 26;  /*!< [25..0] CTMT                                                              */
            uint32_t            : 6;
        } FWCTGC01_b;
    };

    union
    {
        __IOM uint32_t FWCTTC00;       /*!< (@ 0x00000408) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 0i (FWCTTC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDV   : 3; /*!< [2..0] CTDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t CTDFM0 : 1; /*!< [16..16] CTDFM0                                                           */
            __IOM uint32_t CTDFM1 : 1; /*!< [17..17] CTDFM1                                                           */
            uint32_t              : 14;
        } FWCTTC00_b;
    };

    union
    {
        __IOM uint32_t FWCTTC01;       /*!< (@ 0x0000040C) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 1i (FWCTTC1i) (i = 0 to 7)                        */

        struct
        {
            uint32_t             : 12;
            __IOM uint32_t CTIPV : 3;  /*!< [14..12] CTIPV                                                            */
            __IOM uint32_t CTIPU : 1;  /*!< [15..15] CTIPU                                                            */
            __IOM uint32_t CTCME : 1;  /*!< [16..16] CTCME                                                            */
            __IOM uint32_t CTEME : 1;  /*!< [17..17] CTEME                                                            */
            uint32_t             : 14;
        } FWCTTC01_b;
    };

    union
    {
        __IOM uint32_t FWCTTC020;      /*!< (@ 0x00000410) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 20i (FWCTTC20i) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t CTCSD : 6;  /*!< [5..0] CTCSD                                                              */
            uint32_t             : 26;
        } FWCTTC020_b;
    };
    __IM uint32_t RESERVED9[3];

    union
    {
        __IOM uint32_t FWCTSC00;        /*!< (@ 0x00000420) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 0i (FWCTSC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDMAU : 32; /*!< [31..0] CTDMAU                                                            */
        } FWCTSC00_b;
    };

    union
    {
        __IOM uint32_t FWCTSC01;        /*!< (@ 0x00000424) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 1i (FWCTSC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAU : 16; /*!< [15..0] CTSMAU                                                            */
            __IOM uint32_t CTDMAL : 16; /*!< [31..16] CTDMAL                                                           */
        } FWCTSC01_b;
    };

    union
    {
        __IOM uint32_t FWCTSC02;        /*!< (@ 0x00000428) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 2i (FWCTSC2i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAL : 32; /*!< [31..0] CTSMAL                                                            */
        } FWCTSC02_b;
    };

    union
    {
        __IOM uint32_t FWCTSC03;       /*!< (@ 0x0000042C) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 3i (FWCTSC3i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTCV : 12;  /*!< [11..0] CTCV                                                              */
            __IOM uint32_t CTCP : 3;   /*!< [14..12] CTCP                                                             */
            __IOM uint32_t CTCD : 1;   /*!< [15..15] CTCD                                                             */
            __IOM uint32_t CTSV : 12;  /*!< [27..16] CTSV                                                             */
            __IOM uint32_t CTSP : 3;   /*!< [30..28] CTSP                                                             */
            __IOM uint32_t CTSD : 1;   /*!< [31..31] CTSD                                                             */
        } FWCTSC03_b;
    };

    union
    {
        __IOM uint32_t FWCTSC04;       /*!< (@ 0x00000430) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 4i (FWCTSC4i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTET  : 16; /*!< [15..0] CTET                                                              */
            __IOM uint32_t CTSPN : 1;  /*!< [16..16] CTSPN                                                            */
            uint32_t             : 15;
        } FWCTSC04_b;
    };
    __IM uint32_t RESERVED10[3];

    union
    {
        __IOM uint32_t FWCTGC10;        /*!< (@ 0x00000440) Forwarding Engine Cut-Through General Configuration
                                         *                  Register 0i (FWCTGC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMDE   : 1; /*!< [0..0] CTMDE                                                              */
            __IOM uint32_t CTMSE   : 1; /*!< [1..1] CTMSE                                                              */
            __IOM uint32_t CTCVE   : 1; /*!< [2..2] CTCVE                                                              */
            __IOM uint32_t CTCPE   : 1; /*!< [3..3] CTCPE                                                              */
            __IOM uint32_t CTCDE   : 1; /*!< [4..4] CTCDE                                                              */
            __IOM uint32_t CTSVE   : 1; /*!< [5..5] CTSVE                                                              */
            __IOM uint32_t CTSPE   : 1; /*!< [6..6] CTSPE                                                              */
            __IOM uint32_t CTSDE   : 1; /*!< [7..7] CTSDE                                                              */
            __IOM uint32_t CTETE   : 1; /*!< [8..8] CTETE                                                              */
            uint32_t               : 2;
            __IOM uint32_t CTFI    : 1; /*!< [11..11] CTFI                                                             */
            __IOM uint32_t CTVCTRL : 2; /*!< [13..12] CTVCTRL                                                          */
            __IOM uint32_t CTRTGI  : 1; /*!< [14..14] CTRTGI                                                           */
            uint32_t               : 17;
        } FWCTGC10_b;
    };

    union
    {
        __IOM uint32_t FWCTGC11;       /*!< (@ 0x00000444) Forwarding Engine Cut-Through General Configuration
                                        *                  Register 1i (FWCTGC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMT : 26;  /*!< [25..0] CTMT                                                              */
            uint32_t            : 6;
        } FWCTGC11_b;
    };

    union
    {
        __IOM uint32_t FWCTTC10;       /*!< (@ 0x00000448) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 0i (FWCTTC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDV   : 3; /*!< [2..0] CTDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t CTDFM0 : 1; /*!< [16..16] CTDFM0                                                           */
            __IOM uint32_t CTDFM1 : 1; /*!< [17..17] CTDFM1                                                           */
            uint32_t              : 14;
        } FWCTTC10_b;
    };

    union
    {
        __IOM uint32_t FWCTTC11;       /*!< (@ 0x0000044C) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 1i (FWCTTC1i) (i = 0 to 7)                        */

        struct
        {
            uint32_t             : 12;
            __IOM uint32_t CTIPV : 3;  /*!< [14..12] CTIPV                                                            */
            __IOM uint32_t CTIPU : 1;  /*!< [15..15] CTIPU                                                            */
            __IOM uint32_t CTCME : 1;  /*!< [16..16] CTCME                                                            */
            __IOM uint32_t CTEME : 1;  /*!< [17..17] CTEME                                                            */
            uint32_t             : 14;
        } FWCTTC11_b;
    };

    union
    {
        __IOM uint32_t FWCTTC120;      /*!< (@ 0x00000450) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 20i (FWCTTC20i) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t CTCSD : 6;  /*!< [5..0] CTCSD                                                              */
            uint32_t             : 26;
        } FWCTTC120_b;
    };
    __IM uint32_t RESERVED11[3];

    union
    {
        __IOM uint32_t FWCTSC10;        /*!< (@ 0x00000460) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 0i (FWCTSC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDMAU : 32; /*!< [31..0] CTDMAU                                                            */
        } FWCTSC10_b;
    };

    union
    {
        __IOM uint32_t FWCTSC11;        /*!< (@ 0x00000464) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 1i (FWCTSC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAU : 16; /*!< [15..0] CTSMAU                                                            */
            __IOM uint32_t CTDMAL : 16; /*!< [31..16] CTDMAL                                                           */
        } FWCTSC11_b;
    };

    union
    {
        __IOM uint32_t FWCTSC12;        /*!< (@ 0x00000468) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 2i (FWCTSC2i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAL : 32; /*!< [31..0] CTSMAL                                                            */
        } FWCTSC12_b;
    };

    union
    {
        __IOM uint32_t FWCTSC13;       /*!< (@ 0x0000046C) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 3i (FWCTSC3i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTCV : 12;  /*!< [11..0] CTCV                                                              */
            __IOM uint32_t CTCP : 3;   /*!< [14..12] CTCP                                                             */
            __IOM uint32_t CTCD : 1;   /*!< [15..15] CTCD                                                             */
            __IOM uint32_t CTSV : 12;  /*!< [27..16] CTSV                                                             */
            __IOM uint32_t CTSP : 3;   /*!< [30..28] CTSP                                                             */
            __IOM uint32_t CTSD : 1;   /*!< [31..31] CTSD                                                             */
        } FWCTSC13_b;
    };

    union
    {
        __IOM uint32_t FWCTSC14;       /*!< (@ 0x00000470) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 4i (FWCTSC4i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTET  : 16; /*!< [15..0] CTET                                                              */
            __IOM uint32_t CTSPN : 1;  /*!< [16..16] CTSPN                                                            */
            uint32_t             : 15;
        } FWCTSC14_b;
    };
    __IM uint32_t RESERVED12[3];

    union
    {
        __IOM uint32_t FWCTGC20;        /*!< (@ 0x00000480) Forwarding Engine Cut-Through General Configuration
                                         *                  Register 0i (FWCTGC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMDE   : 1; /*!< [0..0] CTMDE                                                              */
            __IOM uint32_t CTMSE   : 1; /*!< [1..1] CTMSE                                                              */
            __IOM uint32_t CTCVE   : 1; /*!< [2..2] CTCVE                                                              */
            __IOM uint32_t CTCPE   : 1; /*!< [3..3] CTCPE                                                              */
            __IOM uint32_t CTCDE   : 1; /*!< [4..4] CTCDE                                                              */
            __IOM uint32_t CTSVE   : 1; /*!< [5..5] CTSVE                                                              */
            __IOM uint32_t CTSPE   : 1; /*!< [6..6] CTSPE                                                              */
            __IOM uint32_t CTSDE   : 1; /*!< [7..7] CTSDE                                                              */
            __IOM uint32_t CTETE   : 1; /*!< [8..8] CTETE                                                              */
            uint32_t               : 2;
            __IOM uint32_t CTFI    : 1; /*!< [11..11] CTFI                                                             */
            __IOM uint32_t CTVCTRL : 2; /*!< [13..12] CTVCTRL                                                          */
            __IOM uint32_t CTRTGI  : 1; /*!< [14..14] CTRTGI                                                           */
            uint32_t               : 17;
        } FWCTGC20_b;
    };

    union
    {
        __IOM uint32_t FWCTGC21;       /*!< (@ 0x00000484) Forwarding Engine Cut-Through General Configuration
                                        *                  Register 1i (FWCTGC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMT : 26;  /*!< [25..0] CTMT                                                              */
            uint32_t            : 6;
        } FWCTGC21_b;
    };

    union
    {
        __IOM uint32_t FWCTTC20;       /*!< (@ 0x00000488) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 0i (FWCTTC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDV   : 3; /*!< [2..0] CTDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t CTDFM0 : 1; /*!< [16..16] CTDFM0                                                           */
            __IOM uint32_t CTDFM1 : 1; /*!< [17..17] CTDFM1                                                           */
            uint32_t              : 14;
        } FWCTTC20_b;
    };

    union
    {
        __IOM uint32_t FWCTTC21;       /*!< (@ 0x0000048C) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 1i (FWCTTC1i) (i = 0 to 7)                        */

        struct
        {
            uint32_t             : 12;
            __IOM uint32_t CTIPV : 3;  /*!< [14..12] CTIPV                                                            */
            __IOM uint32_t CTIPU : 1;  /*!< [15..15] CTIPU                                                            */
            __IOM uint32_t CTCME : 1;  /*!< [16..16] CTCME                                                            */
            __IOM uint32_t CTEME : 1;  /*!< [17..17] CTEME                                                            */
            uint32_t             : 14;
        } FWCTTC21_b;
    };

    union
    {
        __IOM uint32_t FWCTTC220;      /*!< (@ 0x00000490) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 20i (FWCTTC20i) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t CTCSD : 6;  /*!< [5..0] CTCSD                                                              */
            uint32_t             : 26;
        } FWCTTC220_b;
    };
    __IM uint32_t RESERVED13[3];

    union
    {
        __IOM uint32_t FWCTSC20;        /*!< (@ 0x000004A0) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 0i (FWCTSC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDMAU : 32; /*!< [31..0] CTDMAU                                                            */
        } FWCTSC20_b;
    };

    union
    {
        __IOM uint32_t FWCTSC21;        /*!< (@ 0x000004A4) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 1i (FWCTSC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAU : 16; /*!< [15..0] CTSMAU                                                            */
            __IOM uint32_t CTDMAL : 16; /*!< [31..16] CTDMAL                                                           */
        } FWCTSC21_b;
    };

    union
    {
        __IOM uint32_t FWCTSC22;        /*!< (@ 0x000004A8) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 2i (FWCTSC2i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAL : 32; /*!< [31..0] CTSMAL                                                            */
        } FWCTSC22_b;
    };

    union
    {
        __IOM uint32_t FWCTSC23;       /*!< (@ 0x000004AC) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 3i (FWCTSC3i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTCV : 12;  /*!< [11..0] CTCV                                                              */
            __IOM uint32_t CTCP : 3;   /*!< [14..12] CTCP                                                             */
            __IOM uint32_t CTCD : 1;   /*!< [15..15] CTCD                                                             */
            __IOM uint32_t CTSV : 12;  /*!< [27..16] CTSV                                                             */
            __IOM uint32_t CTSP : 3;   /*!< [30..28] CTSP                                                             */
            __IOM uint32_t CTSD : 1;   /*!< [31..31] CTSD                                                             */
        } FWCTSC23_b;
    };

    union
    {
        __IOM uint32_t FWCTSC24;       /*!< (@ 0x000004B0) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 4i (FWCTSC4i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTET  : 16; /*!< [15..0] CTET                                                              */
            __IOM uint32_t CTSPN : 1;  /*!< [16..16] CTSPN                                                            */
            uint32_t             : 15;
        } FWCTSC24_b;
    };
    __IM uint32_t RESERVED14[3];

    union
    {
        __IOM uint32_t FWCTGC30;        /*!< (@ 0x000004C0) Forwarding Engine Cut-Through General Configuration
                                         *                  Register 0i (FWCTGC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMDE   : 1; /*!< [0..0] CTMDE                                                              */
            __IOM uint32_t CTMSE   : 1; /*!< [1..1] CTMSE                                                              */
            __IOM uint32_t CTCVE   : 1; /*!< [2..2] CTCVE                                                              */
            __IOM uint32_t CTCPE   : 1; /*!< [3..3] CTCPE                                                              */
            __IOM uint32_t CTCDE   : 1; /*!< [4..4] CTCDE                                                              */
            __IOM uint32_t CTSVE   : 1; /*!< [5..5] CTSVE                                                              */
            __IOM uint32_t CTSPE   : 1; /*!< [6..6] CTSPE                                                              */
            __IOM uint32_t CTSDE   : 1; /*!< [7..7] CTSDE                                                              */
            __IOM uint32_t CTETE   : 1; /*!< [8..8] CTETE                                                              */
            uint32_t               : 2;
            __IOM uint32_t CTFI    : 1; /*!< [11..11] CTFI                                                             */
            __IOM uint32_t CTVCTRL : 2; /*!< [13..12] CTVCTRL                                                          */
            __IOM uint32_t CTRTGI  : 1; /*!< [14..14] CTRTGI                                                           */
            uint32_t               : 17;
        } FWCTGC30_b;
    };

    union
    {
        __IOM uint32_t FWCTGC31;       /*!< (@ 0x000004C4) Forwarding Engine Cut-Through General Configuration
                                        *                  Register 1i (FWCTGC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMT : 26;  /*!< [25..0] CTMT                                                              */
            uint32_t            : 6;
        } FWCTGC31_b;
    };

    union
    {
        __IOM uint32_t FWCTTC30;       /*!< (@ 0x000004C8) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 0i (FWCTTC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDV   : 3; /*!< [2..0] CTDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t CTDFM0 : 1; /*!< [16..16] CTDFM0                                                           */
            __IOM uint32_t CTDFM1 : 1; /*!< [17..17] CTDFM1                                                           */
            uint32_t              : 14;
        } FWCTTC30_b;
    };

    union
    {
        __IOM uint32_t FWCTTC31;       /*!< (@ 0x000004CC) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 1i (FWCTTC1i) (i = 0 to 7)                        */

        struct
        {
            uint32_t             : 12;
            __IOM uint32_t CTIPV : 3;  /*!< [14..12] CTIPV                                                            */
            __IOM uint32_t CTIPU : 1;  /*!< [15..15] CTIPU                                                            */
            __IOM uint32_t CTCME : 1;  /*!< [16..16] CTCME                                                            */
            __IOM uint32_t CTEME : 1;  /*!< [17..17] CTEME                                                            */
            uint32_t             : 14;
        } FWCTTC31_b;
    };

    union
    {
        __IOM uint32_t FWCTTC320;      /*!< (@ 0x000004D0) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 20i (FWCTTC20i) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t CTCSD : 6;  /*!< [5..0] CTCSD                                                              */
            uint32_t             : 26;
        } FWCTTC320_b;
    };
    __IM uint32_t RESERVED15[3];

    union
    {
        __IOM uint32_t FWCTSC30;        /*!< (@ 0x000004E0) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 0i (FWCTSC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDMAU : 32; /*!< [31..0] CTDMAU                                                            */
        } FWCTSC30_b;
    };

    union
    {
        __IOM uint32_t FWCTSC31;        /*!< (@ 0x000004E4) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 1i (FWCTSC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAU : 16; /*!< [15..0] CTSMAU                                                            */
            __IOM uint32_t CTDMAL : 16; /*!< [31..16] CTDMAL                                                           */
        } FWCTSC31_b;
    };

    union
    {
        __IOM uint32_t FWCTSC32;        /*!< (@ 0x000004E8) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 2i (FWCTSC2i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAL : 32; /*!< [31..0] CTSMAL                                                            */
        } FWCTSC32_b;
    };

    union
    {
        __IOM uint32_t FWCTSC33;       /*!< (@ 0x000004EC) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 3i (FWCTSC3i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTCV : 12;  /*!< [11..0] CTCV                                                              */
            __IOM uint32_t CTCP : 3;   /*!< [14..12] CTCP                                                             */
            __IOM uint32_t CTCD : 1;   /*!< [15..15] CTCD                                                             */
            __IOM uint32_t CTSV : 12;  /*!< [27..16] CTSV                                                             */
            __IOM uint32_t CTSP : 3;   /*!< [30..28] CTSP                                                             */
            __IOM uint32_t CTSD : 1;   /*!< [31..31] CTSD                                                             */
        } FWCTSC33_b;
    };

    union
    {
        __IOM uint32_t FWCTSC34;       /*!< (@ 0x000004F0) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 4i (FWCTSC4i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTET  : 16; /*!< [15..0] CTET                                                              */
            __IOM uint32_t CTSPN : 1;  /*!< [16..16] CTSPN                                                            */
            uint32_t             : 15;
        } FWCTSC34_b;
    };
    __IM uint32_t RESERVED16[3];

    union
    {
        __IOM uint32_t FWCTGC40;        /*!< (@ 0x00000500) Forwarding Engine Cut-Through General Configuration
                                         *                  Register 0i (FWCTGC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMDE   : 1; /*!< [0..0] CTMDE                                                              */
            __IOM uint32_t CTMSE   : 1; /*!< [1..1] CTMSE                                                              */
            __IOM uint32_t CTCVE   : 1; /*!< [2..2] CTCVE                                                              */
            __IOM uint32_t CTCPE   : 1; /*!< [3..3] CTCPE                                                              */
            __IOM uint32_t CTCDE   : 1; /*!< [4..4] CTCDE                                                              */
            __IOM uint32_t CTSVE   : 1; /*!< [5..5] CTSVE                                                              */
            __IOM uint32_t CTSPE   : 1; /*!< [6..6] CTSPE                                                              */
            __IOM uint32_t CTSDE   : 1; /*!< [7..7] CTSDE                                                              */
            __IOM uint32_t CTETE   : 1; /*!< [8..8] CTETE                                                              */
            uint32_t               : 2;
            __IOM uint32_t CTFI    : 1; /*!< [11..11] CTFI                                                             */
            __IOM uint32_t CTVCTRL : 2; /*!< [13..12] CTVCTRL                                                          */
            __IOM uint32_t CTRTGI  : 1; /*!< [14..14] CTRTGI                                                           */
            uint32_t               : 17;
        } FWCTGC40_b;
    };

    union
    {
        __IOM uint32_t FWCTGC41;       /*!< (@ 0x00000504) Forwarding Engine Cut-Through General Configuration
                                        *                  Register 1i (FWCTGC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMT : 26;  /*!< [25..0] CTMT                                                              */
            uint32_t            : 6;
        } FWCTGC41_b;
    };

    union
    {
        __IOM uint32_t FWCTTC40;       /*!< (@ 0x00000508) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 0i (FWCTTC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDV   : 3; /*!< [2..0] CTDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t CTDFM0 : 1; /*!< [16..16] CTDFM0                                                           */
            __IOM uint32_t CTDFM1 : 1; /*!< [17..17] CTDFM1                                                           */
            uint32_t              : 14;
        } FWCTTC40_b;
    };

    union
    {
        __IOM uint32_t FWCTTC41;       /*!< (@ 0x0000050C) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 1i (FWCTTC1i) (i = 0 to 7)                        */

        struct
        {
            uint32_t             : 12;
            __IOM uint32_t CTIPV : 3;  /*!< [14..12] CTIPV                                                            */
            __IOM uint32_t CTIPU : 1;  /*!< [15..15] CTIPU                                                            */
            __IOM uint32_t CTCME : 1;  /*!< [16..16] CTCME                                                            */
            __IOM uint32_t CTEME : 1;  /*!< [17..17] CTEME                                                            */
            uint32_t             : 14;
        } FWCTTC41_b;
    };

    union
    {
        __IOM uint32_t FWCTTC420;      /*!< (@ 0x00000510) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 20i (FWCTTC20i) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t CTCSD : 6;  /*!< [5..0] CTCSD                                                              */
            uint32_t             : 26;
        } FWCTTC420_b;
    };
    __IM uint32_t RESERVED17[3];

    union
    {
        __IOM uint32_t FWCTSC40;        /*!< (@ 0x00000520) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 0i (FWCTSC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDMAU : 32; /*!< [31..0] CTDMAU                                                            */
        } FWCTSC40_b;
    };

    union
    {
        __IOM uint32_t FWCTSC41;        /*!< (@ 0x00000524) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 1i (FWCTSC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAU : 16; /*!< [15..0] CTSMAU                                                            */
            __IOM uint32_t CTDMAL : 16; /*!< [31..16] CTDMAL                                                           */
        } FWCTSC41_b;
    };

    union
    {
        __IOM uint32_t FWCTSC42;        /*!< (@ 0x00000528) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 2i (FWCTSC2i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAL : 32; /*!< [31..0] CTSMAL                                                            */
        } FWCTSC42_b;
    };

    union
    {
        __IOM uint32_t FWCTSC43;       /*!< (@ 0x0000052C) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 3i (FWCTSC3i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTCV : 12;  /*!< [11..0] CTCV                                                              */
            __IOM uint32_t CTCP : 3;   /*!< [14..12] CTCP                                                             */
            __IOM uint32_t CTCD : 1;   /*!< [15..15] CTCD                                                             */
            __IOM uint32_t CTSV : 12;  /*!< [27..16] CTSV                                                             */
            __IOM uint32_t CTSP : 3;   /*!< [30..28] CTSP                                                             */
            __IOM uint32_t CTSD : 1;   /*!< [31..31] CTSD                                                             */
        } FWCTSC43_b;
    };

    union
    {
        __IOM uint32_t FWCTSC44;       /*!< (@ 0x00000530) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 4i (FWCTSC4i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTET  : 16; /*!< [15..0] CTET                                                              */
            __IOM uint32_t CTSPN : 1;  /*!< [16..16] CTSPN                                                            */
            uint32_t             : 15;
        } FWCTSC44_b;
    };
    __IM uint32_t RESERVED18[3];

    union
    {
        __IOM uint32_t FWCTGC50;        /*!< (@ 0x00000540) Forwarding Engine Cut-Through General Configuration
                                         *                  Register 0i (FWCTGC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMDE   : 1; /*!< [0..0] CTMDE                                                              */
            __IOM uint32_t CTMSE   : 1; /*!< [1..1] CTMSE                                                              */
            __IOM uint32_t CTCVE   : 1; /*!< [2..2] CTCVE                                                              */
            __IOM uint32_t CTCPE   : 1; /*!< [3..3] CTCPE                                                              */
            __IOM uint32_t CTCDE   : 1; /*!< [4..4] CTCDE                                                              */
            __IOM uint32_t CTSVE   : 1; /*!< [5..5] CTSVE                                                              */
            __IOM uint32_t CTSPE   : 1; /*!< [6..6] CTSPE                                                              */
            __IOM uint32_t CTSDE   : 1; /*!< [7..7] CTSDE                                                              */
            __IOM uint32_t CTETE   : 1; /*!< [8..8] CTETE                                                              */
            uint32_t               : 2;
            __IOM uint32_t CTFI    : 1; /*!< [11..11] CTFI                                                             */
            __IOM uint32_t CTVCTRL : 2; /*!< [13..12] CTVCTRL                                                          */
            __IOM uint32_t CTRTGI  : 1; /*!< [14..14] CTRTGI                                                           */
            uint32_t               : 17;
        } FWCTGC50_b;
    };

    union
    {
        __IOM uint32_t FWCTGC51;       /*!< (@ 0x00000544) Forwarding Engine Cut-Through General Configuration
                                        *                  Register 1i (FWCTGC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMT : 26;  /*!< [25..0] CTMT                                                              */
            uint32_t            : 6;
        } FWCTGC51_b;
    };

    union
    {
        __IOM uint32_t FWCTTC50;       /*!< (@ 0x00000548) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 0i (FWCTTC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDV   : 3; /*!< [2..0] CTDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t CTDFM0 : 1; /*!< [16..16] CTDFM0                                                           */
            __IOM uint32_t CTDFM1 : 1; /*!< [17..17] CTDFM1                                                           */
            uint32_t              : 14;
        } FWCTTC50_b;
    };

    union
    {
        __IOM uint32_t FWCTTC51;       /*!< (@ 0x0000054C) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 1i (FWCTTC1i) (i = 0 to 7)                        */

        struct
        {
            uint32_t             : 12;
            __IOM uint32_t CTIPV : 3;  /*!< [14..12] CTIPV                                                            */
            __IOM uint32_t CTIPU : 1;  /*!< [15..15] CTIPU                                                            */
            __IOM uint32_t CTCME : 1;  /*!< [16..16] CTCME                                                            */
            __IOM uint32_t CTEME : 1;  /*!< [17..17] CTEME                                                            */
            uint32_t             : 14;
        } FWCTTC51_b;
    };

    union
    {
        __IOM uint32_t FWCTTC520;      /*!< (@ 0x00000550) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 20i (FWCTTC20i) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t CTCSD : 6;  /*!< [5..0] CTCSD                                                              */
            uint32_t             : 26;
        } FWCTTC520_b;
    };
    __IM uint32_t RESERVED19[3];

    union
    {
        __IOM uint32_t FWCTSC50;        /*!< (@ 0x00000560) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 0i (FWCTSC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDMAU : 32; /*!< [31..0] CTDMAU                                                            */
        } FWCTSC50_b;
    };

    union
    {
        __IOM uint32_t FWCTSC51;        /*!< (@ 0x00000564) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 1i (FWCTSC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAU : 16; /*!< [15..0] CTSMAU                                                            */
            __IOM uint32_t CTDMAL : 16; /*!< [31..16] CTDMAL                                                           */
        } FWCTSC51_b;
    };

    union
    {
        __IOM uint32_t FWCTSC52;        /*!< (@ 0x00000568) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 2i (FWCTSC2i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAL : 32; /*!< [31..0] CTSMAL                                                            */
        } FWCTSC52_b;
    };

    union
    {
        __IOM uint32_t FWCTSC53;       /*!< (@ 0x0000056C) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 3i (FWCTSC3i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTCV : 12;  /*!< [11..0] CTCV                                                              */
            __IOM uint32_t CTCP : 3;   /*!< [14..12] CTCP                                                             */
            __IOM uint32_t CTCD : 1;   /*!< [15..15] CTCD                                                             */
            __IOM uint32_t CTSV : 12;  /*!< [27..16] CTSV                                                             */
            __IOM uint32_t CTSP : 3;   /*!< [30..28] CTSP                                                             */
            __IOM uint32_t CTSD : 1;   /*!< [31..31] CTSD                                                             */
        } FWCTSC53_b;
    };

    union
    {
        __IOM uint32_t FWCTSC54;       /*!< (@ 0x00000570) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 4i (FWCTSC4i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTET  : 16; /*!< [15..0] CTET                                                              */
            __IOM uint32_t CTSPN : 1;  /*!< [16..16] CTSPN                                                            */
            uint32_t             : 15;
        } FWCTSC54_b;
    };
    __IM uint32_t RESERVED20[3];

    union
    {
        __IOM uint32_t FWCTGC60;        /*!< (@ 0x00000580) Forwarding Engine Cut-Through General Configuration
                                         *                  Register 0i (FWCTGC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMDE   : 1; /*!< [0..0] CTMDE                                                              */
            __IOM uint32_t CTMSE   : 1; /*!< [1..1] CTMSE                                                              */
            __IOM uint32_t CTCVE   : 1; /*!< [2..2] CTCVE                                                              */
            __IOM uint32_t CTCPE   : 1; /*!< [3..3] CTCPE                                                              */
            __IOM uint32_t CTCDE   : 1; /*!< [4..4] CTCDE                                                              */
            __IOM uint32_t CTSVE   : 1; /*!< [5..5] CTSVE                                                              */
            __IOM uint32_t CTSPE   : 1; /*!< [6..6] CTSPE                                                              */
            __IOM uint32_t CTSDE   : 1; /*!< [7..7] CTSDE                                                              */
            __IOM uint32_t CTETE   : 1; /*!< [8..8] CTETE                                                              */
            uint32_t               : 2;
            __IOM uint32_t CTFI    : 1; /*!< [11..11] CTFI                                                             */
            __IOM uint32_t CTVCTRL : 2; /*!< [13..12] CTVCTRL                                                          */
            __IOM uint32_t CTRTGI  : 1; /*!< [14..14] CTRTGI                                                           */
            uint32_t               : 17;
        } FWCTGC60_b;
    };

    union
    {
        __IOM uint32_t FWCTGC61;       /*!< (@ 0x00000584) Forwarding Engine Cut-Through General Configuration
                                        *                  Register 1i (FWCTGC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMT : 26;  /*!< [25..0] CTMT                                                              */
            uint32_t            : 6;
        } FWCTGC61_b;
    };

    union
    {
        __IOM uint32_t FWCTTC60;       /*!< (@ 0x00000588) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 0i (FWCTTC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDV   : 3; /*!< [2..0] CTDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t CTDFM0 : 1; /*!< [16..16] CTDFM0                                                           */
            __IOM uint32_t CTDFM1 : 1; /*!< [17..17] CTDFM1                                                           */
            uint32_t              : 14;
        } FWCTTC60_b;
    };

    union
    {
        __IOM uint32_t FWCTTC61;       /*!< (@ 0x0000058C) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 1i (FWCTTC1i) (i = 0 to 7)                        */

        struct
        {
            uint32_t             : 12;
            __IOM uint32_t CTIPV : 3;  /*!< [14..12] CTIPV                                                            */
            __IOM uint32_t CTIPU : 1;  /*!< [15..15] CTIPU                                                            */
            __IOM uint32_t CTCME : 1;  /*!< [16..16] CTCME                                                            */
            __IOM uint32_t CTEME : 1;  /*!< [17..17] CTEME                                                            */
            uint32_t             : 14;
        } FWCTTC61_b;
    };

    union
    {
        __IOM uint32_t FWCTTC620;      /*!< (@ 0x00000590) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 20i (FWCTTC20i) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t CTCSD : 6;  /*!< [5..0] CTCSD                                                              */
            uint32_t             : 26;
        } FWCTTC620_b;
    };
    __IM uint32_t RESERVED21[3];

    union
    {
        __IOM uint32_t FWCTSC60;        /*!< (@ 0x000005A0) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 0i (FWCTSC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDMAU : 32; /*!< [31..0] CTDMAU                                                            */
        } FWCTSC60_b;
    };

    union
    {
        __IOM uint32_t FWCTSC61;        /*!< (@ 0x000005A4) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 1i (FWCTSC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAU : 16; /*!< [15..0] CTSMAU                                                            */
            __IOM uint32_t CTDMAL : 16; /*!< [31..16] CTDMAL                                                           */
        } FWCTSC61_b;
    };

    union
    {
        __IOM uint32_t FWCTSC62;        /*!< (@ 0x000005A8) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 2i (FWCTSC2i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAL : 32; /*!< [31..0] CTSMAL                                                            */
        } FWCTSC62_b;
    };

    union
    {
        __IOM uint32_t FWCTSC63;       /*!< (@ 0x000005AC) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 3i (FWCTSC3i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTCV : 12;  /*!< [11..0] CTCV                                                              */
            __IOM uint32_t CTCP : 3;   /*!< [14..12] CTCP                                                             */
            __IOM uint32_t CTCD : 1;   /*!< [15..15] CTCD                                                             */
            __IOM uint32_t CTSV : 12;  /*!< [27..16] CTSV                                                             */
            __IOM uint32_t CTSP : 3;   /*!< [30..28] CTSP                                                             */
            __IOM uint32_t CTSD : 1;   /*!< [31..31] CTSD                                                             */
        } FWCTSC63_b;
    };

    union
    {
        __IOM uint32_t FWCTSC64;       /*!< (@ 0x000005B0) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 4i (FWCTSC4i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTET  : 16; /*!< [15..0] CTET                                                              */
            __IOM uint32_t CTSPN : 1;  /*!< [16..16] CTSPN                                                            */
            uint32_t             : 15;
        } FWCTSC64_b;
    };
    __IM uint32_t RESERVED22[3];

    union
    {
        __IOM uint32_t FWCTGC70;        /*!< (@ 0x000005C0) Forwarding Engine Cut-Through General Configuration
                                         *                  Register 0i (FWCTGC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMDE   : 1; /*!< [0..0] CTMDE                                                              */
            __IOM uint32_t CTMSE   : 1; /*!< [1..1] CTMSE                                                              */
            __IOM uint32_t CTCVE   : 1; /*!< [2..2] CTCVE                                                              */
            __IOM uint32_t CTCPE   : 1; /*!< [3..3] CTCPE                                                              */
            __IOM uint32_t CTCDE   : 1; /*!< [4..4] CTCDE                                                              */
            __IOM uint32_t CTSVE   : 1; /*!< [5..5] CTSVE                                                              */
            __IOM uint32_t CTSPE   : 1; /*!< [6..6] CTSPE                                                              */
            __IOM uint32_t CTSDE   : 1; /*!< [7..7] CTSDE                                                              */
            __IOM uint32_t CTETE   : 1; /*!< [8..8] CTETE                                                              */
            uint32_t               : 2;
            __IOM uint32_t CTFI    : 1; /*!< [11..11] CTFI                                                             */
            __IOM uint32_t CTVCTRL : 2; /*!< [13..12] CTVCTRL                                                          */
            __IOM uint32_t CTRTGI  : 1; /*!< [14..14] CTRTGI                                                           */
            uint32_t               : 17;
        } FWCTGC70_b;
    };

    union
    {
        __IOM uint32_t FWCTGC71;       /*!< (@ 0x000005C4) Forwarding Engine Cut-Through General Configuration
                                        *                  Register 1i (FWCTGC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTMT : 26;  /*!< [25..0] CTMT                                                              */
            uint32_t            : 6;
        } FWCTGC71_b;
    };

    union
    {
        __IOM uint32_t FWCTTC70;       /*!< (@ 0x000005C8) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 0i (FWCTTC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDV   : 3; /*!< [2..0] CTDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t CTDFM0 : 1; /*!< [16..16] CTDFM0                                                           */
            __IOM uint32_t CTDFM1 : 1; /*!< [17..17] CTDFM1                                                           */
            uint32_t              : 14;
        } FWCTTC70_b;
    };

    union
    {
        __IOM uint32_t FWCTTC71;       /*!< (@ 0x000005CC) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 1i (FWCTTC1i) (i = 0 to 7)                        */

        struct
        {
            uint32_t             : 12;
            __IOM uint32_t CTIPV : 3;  /*!< [14..12] CTIPV                                                            */
            __IOM uint32_t CTIPU : 1;  /*!< [15..15] CTIPU                                                            */
            __IOM uint32_t CTCME : 1;  /*!< [16..16] CTCME                                                            */
            __IOM uint32_t CTEME : 1;  /*!< [17..17] CTEME                                                            */
            uint32_t             : 14;
        } FWCTTC71_b;
    };

    union
    {
        __IOM uint32_t FWCTTC720;      /*!< (@ 0x000005D0) Forwarding Engine Cut-Through Target Configuration
                                        *                  Register 20i (FWCTTC20i) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t CTCSD : 6;  /*!< [5..0] CTCSD                                                              */
            uint32_t             : 26;
        } FWCTTC720_b;
    };
    __IM uint32_t RESERVED23[3];

    union
    {
        __IOM uint32_t FWCTSC70;        /*!< (@ 0x000005E0) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 0i (FWCTSC0i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTDMAU : 32; /*!< [31..0] CTDMAU                                                            */
        } FWCTSC70_b;
    };

    union
    {
        __IOM uint32_t FWCTSC71;        /*!< (@ 0x000005E4) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 1i (FWCTSC1i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAU : 16; /*!< [15..0] CTSMAU                                                            */
            __IOM uint32_t CTDMAL : 16; /*!< [31..16] CTDMAL                                                           */
        } FWCTSC71_b;
    };

    union
    {
        __IOM uint32_t FWCTSC72;        /*!< (@ 0x000005E8) Forwarding Engine Cut-Through Separation Configuration
                                         *                  Register 2i (FWCTSC2i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTSMAL : 32; /*!< [31..0] CTSMAL                                                            */
        } FWCTSC72_b;
    };

    union
    {
        __IOM uint32_t FWCTSC73;       /*!< (@ 0x000005EC) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 3i (FWCTSC3i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTCV : 12;  /*!< [11..0] CTCV                                                              */
            __IOM uint32_t CTCP : 3;   /*!< [14..12] CTCP                                                             */
            __IOM uint32_t CTCD : 1;   /*!< [15..15] CTCD                                                             */
            __IOM uint32_t CTSV : 12;  /*!< [27..16] CTSV                                                             */
            __IOM uint32_t CTSP : 3;   /*!< [30..28] CTSP                                                             */
            __IOM uint32_t CTSD : 1;   /*!< [31..31] CTSD                                                             */
        } FWCTSC73_b;
    };

    union
    {
        __IOM uint32_t FWCTSC74;       /*!< (@ 0x000005F0) Forwarding Engine Cut-Through Separation Configuration
                                        *                  Register 4i (FWCTSC4i) (i = 0 to 7)                        */

        struct
        {
            __IOM uint32_t CTET  : 16; /*!< [15..0] CTET                                                              */
            __IOM uint32_t CTSPN : 1;  /*!< [16..16] CTSPN                                                            */
            uint32_t             : 15;
        } FWCTSC74_b;
    };
    __IM uint32_t RESERVED24[643];

    union
    {
        __IOM uint32_t FWTWBFC0;       /*!< (@ 0x00001000) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC0_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC0;       /*!< (@ 0x00001004) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC0_b;
    };
    __IM uint32_t RESERVED25[2];

    union
    {
        __IOM uint32_t FWTWBFC1;       /*!< (@ 0x00001010) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC1_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC1;       /*!< (@ 0x00001014) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC1_b;
    };
    __IM uint32_t RESERVED26[2];

    union
    {
        __IOM uint32_t FWTWBFC2;       /*!< (@ 0x00001020) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC2_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC2;       /*!< (@ 0x00001024) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC2_b;
    };
    __IM uint32_t RESERVED27[2];

    union
    {
        __IOM uint32_t FWTWBFC3;       /*!< (@ 0x00001030) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC3_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC3;       /*!< (@ 0x00001034) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC3_b;
    };
    __IM uint32_t RESERVED28[2];

    union
    {
        __IOM uint32_t FWTWBFC4;       /*!< (@ 0x00001040) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC4_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC4;       /*!< (@ 0x00001044) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC4_b;
    };
    __IM uint32_t RESERVED29[2];

    union
    {
        __IOM uint32_t FWTWBFC5;       /*!< (@ 0x00001050) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC5_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC5;       /*!< (@ 0x00001054) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC5_b;
    };
    __IM uint32_t RESERVED30[2];

    union
    {
        __IOM uint32_t FWTWBFC6;       /*!< (@ 0x00001060) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC6_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC6;       /*!< (@ 0x00001064) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC6_b;
    };
    __IM uint32_t RESERVED31[2];

    union
    {
        __IOM uint32_t FWTWBFC7;       /*!< (@ 0x00001070) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC7_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC7;       /*!< (@ 0x00001074) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC7_b;
    };
    __IM uint32_t RESERVED32[2];

    union
    {
        __IOM uint32_t FWTWBFC8;       /*!< (@ 0x00001080) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC8_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC8;       /*!< (@ 0x00001084) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC8_b;
    };
    __IM uint32_t RESERVED33[2];

    union
    {
        __IOM uint32_t FWTWBFC9;       /*!< (@ 0x00001090) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC9_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC9;       /*!< (@ 0x00001094) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC9_b;
    };
    __IM uint32_t RESERVED34[2];

    union
    {
        __IOM uint32_t FWTWBFC10;      /*!< (@ 0x000010A0) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC10_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC10;      /*!< (@ 0x000010A4) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC10_b;
    };
    __IM uint32_t RESERVED35[2];

    union
    {
        __IOM uint32_t FWTWBFC11;      /*!< (@ 0x000010B0) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC11_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC11;      /*!< (@ 0x000010B4) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC11_b;
    };
    __IM uint32_t RESERVED36[2];

    union
    {
        __IOM uint32_t FWTWBFC12;      /*!< (@ 0x000010C0) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC12_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC12;      /*!< (@ 0x000010C4) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC12_b;
    };
    __IM uint32_t RESERVED37[2];

    union
    {
        __IOM uint32_t FWTWBFC13;      /*!< (@ 0x000010D0) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC13_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC13;      /*!< (@ 0x000010D4) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC13_b;
    };
    __IM uint32_t RESERVED38[2];

    union
    {
        __IOM uint32_t FWTWBFC14;      /*!< (@ 0x000010E0) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC14_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC14;      /*!< (@ 0x000010E4) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC14_b;
    };
    __IM uint32_t RESERVED39[2];

    union
    {
        __IOM uint32_t FWTWBFC15;      /*!< (@ 0x000010F0) Forwarding Engine Two Byte Filter Configuration
                                        *                  Register i (FWTWBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t TWBFUM : 2; /*!< [1..0] TWBFUM                                                             */
            uint32_t              : 6;
            __IOM uint32_t TWBFM  : 1; /*!< [8..8] TWBFM                                                              */
            uint32_t              : 7;
            __IOM uint32_t TWBFOV : 8; /*!< [23..16] TWBFOV                                                           */
            uint32_t              : 8;
        } FWTWBFC15_b;
    };

    union
    {
        __IOM uint32_t FWTWBFVC15;      /*!< (@ 0x000010F4) Forwarding Engine Two Byte Filter Value Configuration
                                         *                  Register i (FWTWBFVCi) (i = 0 to 15)                       */

        struct
        {
            __IOM uint32_t TWBFV0 : 16; /*!< [15..0] TWBFV0                                                            */
            __IOM uint32_t TWBFV1 : 16; /*!< [31..16] TWBFV1                                                           */
        } FWTWBFVC15_b;
    };
    __IM uint32_t RESERVED40[194];

    union
    {
        __IOM uint32_t FWTHBFC0;       /*!< (@ 0x00001400) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC0_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C0;      /*!< (@ 0x00001404) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C0_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C0;      /*!< (@ 0x00001408) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C0_b;
    };
    __IM uint32_t RESERVED41;

    union
    {
        __IOM uint32_t FWTHBFC1;       /*!< (@ 0x00001410) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC1_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C1;      /*!< (@ 0x00001414) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C1_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C1;      /*!< (@ 0x00001418) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C1_b;
    };
    __IM uint32_t RESERVED42;

    union
    {
        __IOM uint32_t FWTHBFC2;       /*!< (@ 0x00001420) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC2_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C2;      /*!< (@ 0x00001424) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C2_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C2;      /*!< (@ 0x00001428) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C2_b;
    };
    __IM uint32_t RESERVED43;

    union
    {
        __IOM uint32_t FWTHBFC3;       /*!< (@ 0x00001430) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC3_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C3;      /*!< (@ 0x00001434) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C3_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C3;      /*!< (@ 0x00001438) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C3_b;
    };
    __IM uint32_t RESERVED44;

    union
    {
        __IOM uint32_t FWTHBFC4;       /*!< (@ 0x00001440) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC4_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C4;      /*!< (@ 0x00001444) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C4_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C4;      /*!< (@ 0x00001448) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C4_b;
    };
    __IM uint32_t RESERVED45;

    union
    {
        __IOM uint32_t FWTHBFC5;       /*!< (@ 0x00001450) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC5_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C5;      /*!< (@ 0x00001454) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C5_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C5;      /*!< (@ 0x00001458) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C5_b;
    };
    __IM uint32_t RESERVED46;

    union
    {
        __IOM uint32_t FWTHBFC6;       /*!< (@ 0x00001460) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC6_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C6;      /*!< (@ 0x00001464) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C6_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C6;      /*!< (@ 0x00001468) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C6_b;
    };
    __IM uint32_t RESERVED47;

    union
    {
        __IOM uint32_t FWTHBFC7;       /*!< (@ 0x00001470) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC7_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C7;      /*!< (@ 0x00001474) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C7_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C7;      /*!< (@ 0x00001478) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C7_b;
    };
    __IM uint32_t RESERVED48;

    union
    {
        __IOM uint32_t FWTHBFC8;       /*!< (@ 0x00001480) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC8_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C8;      /*!< (@ 0x00001484) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C8_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C8;      /*!< (@ 0x00001488) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C8_b;
    };
    __IM uint32_t RESERVED49;

    union
    {
        __IOM uint32_t FWTHBFC9;       /*!< (@ 0x00001490) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC9_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C9;      /*!< (@ 0x00001494) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C9_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C9;      /*!< (@ 0x00001498) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C9_b;
    };
    __IM uint32_t RESERVED50;

    union
    {
        __IOM uint32_t FWTHBFC10;      /*!< (@ 0x000014A0) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC10_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C10;     /*!< (@ 0x000014A4) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C10_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C10;     /*!< (@ 0x000014A8) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C10_b;
    };
    __IM uint32_t RESERVED51;

    union
    {
        __IOM uint32_t FWTHBFC11;      /*!< (@ 0x000014B0) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC11_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C11;     /*!< (@ 0x000014B4) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C11_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C11;     /*!< (@ 0x000014B8) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C11_b;
    };
    __IM uint32_t RESERVED52;

    union
    {
        __IOM uint32_t FWTHBFC12;      /*!< (@ 0x000014C0) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC12_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C12;     /*!< (@ 0x000014C4) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C12_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C12;     /*!< (@ 0x000014C8) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C12_b;
    };
    __IM uint32_t RESERVED53;

    union
    {
        __IOM uint32_t FWTHBFC13;      /*!< (@ 0x000014D0) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC13_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C13;     /*!< (@ 0x000014D4) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C13_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C13;     /*!< (@ 0x000014D8) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C13_b;
    };
    __IM uint32_t RESERVED54;

    union
    {
        __IOM uint32_t FWTHBFC14;      /*!< (@ 0x000014E0) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC14_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C14;     /*!< (@ 0x000014E4) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C14_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C14;     /*!< (@ 0x000014E8) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C14_b;
    };
    __IM uint32_t RESERVED55;

    union
    {
        __IOM uint32_t FWTHBFC15;      /*!< (@ 0x000014F0) Forwarding Engine Three Byte Filter Configuration
                                        *                  Register i (FWTHBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t THBFUM : 2; /*!< [1..0] THBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t THBFOV : 8; /*!< [23..16] THBFOV                                                           */
            uint32_t              : 8;
        } FWTHBFC15_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV0C15;     /*!< (@ 0x000014F4) Forwarding Engine Three Byte Filter Value 0 Configuration
                                         *                  Register i (FWTHBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV0 : 24; /*!< [23..0] THBFV0                                                            */
            uint32_t              : 8;
        } FWTHBFV0C15_b;
    };

    union
    {
        __IOM uint32_t FWTHBFV1C15;     /*!< (@ 0x000014F8) Forwarding Engine Three Byte Filter Value 1 Configuration
                                         *                  Register i (FWTHBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t THBFV1 : 24; /*!< [23..0] THBFV1                                                            */
            uint32_t              : 8;
        } FWTHBFV1C15_b;
    };
    __IM uint32_t RESERVED56[193];

    union
    {
        __IOM uint32_t FWFOBFC0;       /*!< (@ 0x00001800) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC0_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C0;      /*!< (@ 0x00001804) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C0_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C0;      /*!< (@ 0x00001808) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C0_b;
    };
    __IM uint32_t RESERVED57;

    union
    {
        __IOM uint32_t FWFOBFC1;       /*!< (@ 0x00001810) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC1_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C1;      /*!< (@ 0x00001814) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C1_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C1;      /*!< (@ 0x00001818) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C1_b;
    };
    __IM uint32_t RESERVED58;

    union
    {
        __IOM uint32_t FWFOBFC2;       /*!< (@ 0x00001820) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC2_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C2;      /*!< (@ 0x00001824) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C2_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C2;      /*!< (@ 0x00001828) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C2_b;
    };
    __IM uint32_t RESERVED59;

    union
    {
        __IOM uint32_t FWFOBFC3;       /*!< (@ 0x00001830) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC3_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C3;      /*!< (@ 0x00001834) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C3_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C3;      /*!< (@ 0x00001838) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C3_b;
    };
    __IM uint32_t RESERVED60;

    union
    {
        __IOM uint32_t FWFOBFC4;       /*!< (@ 0x00001840) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC4_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C4;      /*!< (@ 0x00001844) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C4_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C4;      /*!< (@ 0x00001848) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C4_b;
    };
    __IM uint32_t RESERVED61;

    union
    {
        __IOM uint32_t FWFOBFC5;       /*!< (@ 0x00001850) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC5_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C5;      /*!< (@ 0x00001854) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C5_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C5;      /*!< (@ 0x00001858) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C5_b;
    };
    __IM uint32_t RESERVED62;

    union
    {
        __IOM uint32_t FWFOBFC6;       /*!< (@ 0x00001860) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC6_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C6;      /*!< (@ 0x00001864) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C6_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C6;      /*!< (@ 0x00001868) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C6_b;
    };
    __IM uint32_t RESERVED63;

    union
    {
        __IOM uint32_t FWFOBFC7;       /*!< (@ 0x00001870) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC7_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C7;      /*!< (@ 0x00001874) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C7_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C7;      /*!< (@ 0x00001878) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C7_b;
    };
    __IM uint32_t RESERVED64;

    union
    {
        __IOM uint32_t FWFOBFC8;       /*!< (@ 0x00001880) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC8_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C8;      /*!< (@ 0x00001884) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C8_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C8;      /*!< (@ 0x00001888) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C8_b;
    };
    __IM uint32_t RESERVED65;

    union
    {
        __IOM uint32_t FWFOBFC9;       /*!< (@ 0x00001890) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC9_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C9;      /*!< (@ 0x00001894) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C9_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C9;      /*!< (@ 0x00001898) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C9_b;
    };
    __IM uint32_t RESERVED66;

    union
    {
        __IOM uint32_t FWFOBFC10;      /*!< (@ 0x000018A0) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC10_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C10;     /*!< (@ 0x000018A4) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C10_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C10;     /*!< (@ 0x000018A8) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C10_b;
    };
    __IM uint32_t RESERVED67;

    union
    {
        __IOM uint32_t FWFOBFC11;      /*!< (@ 0x000018B0) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC11_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C11;     /*!< (@ 0x000018B4) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C11_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C11;     /*!< (@ 0x000018B8) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C11_b;
    };
    __IM uint32_t RESERVED68;

    union
    {
        __IOM uint32_t FWFOBFC12;      /*!< (@ 0x000018C0) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC12_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C12;     /*!< (@ 0x000018C4) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C12_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C12;     /*!< (@ 0x000018C8) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C12_b;
    };
    __IM uint32_t RESERVED69;

    union
    {
        __IOM uint32_t FWFOBFC13;      /*!< (@ 0x000018D0) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC13_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C13;     /*!< (@ 0x000018D4) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C13_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C13;     /*!< (@ 0x000018D8) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C13_b;
    };
    __IM uint32_t RESERVED70;

    union
    {
        __IOM uint32_t FWFOBFC14;      /*!< (@ 0x000018E0) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC14_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C14;     /*!< (@ 0x000018E4) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C14_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C14;     /*!< (@ 0x000018E8) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C14_b;
    };
    __IM uint32_t RESERVED71;

    union
    {
        __IOM uint32_t FWFOBFC15;      /*!< (@ 0x000018F0) Forwarding Engine Four Byte Filter Configuration
                                        *                  Register i (FWFOBFCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t FOBFUM : 2; /*!< [1..0] FOBFUM                                                             */
            uint32_t              : 14;
            __IOM uint32_t FOBFOV : 8; /*!< [23..16] FOBFOV                                                           */
            uint32_t              : 8;
        } FWFOBFC15_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV0C15;     /*!< (@ 0x000018F4) Forwarding Engine Four Byte Filter Value 0 Configuration
                                         *                  Register i (FWFOBFV0Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV0 : 32; /*!< [31..0] FOBFV0                                                            */
        } FWFOBFV0C15_b;
    };

    union
    {
        __IOM uint32_t FWFOBFV1C15;     /*!< (@ 0x000018F8) Forwarding Engine Four Byte Filter Value 1 Configuration
                                         *                  Register i (FWFOBFV1Ci) (i = 0 to 15)                      */

        struct
        {
            __IOM uint32_t FOBFV1 : 32; /*!< [31..0] FOBFV1                                                            */
        } FWFOBFV1C15_b;
    };
    __IM uint32_t RESERVED72[193];

    union
    {
        __IOM uint32_t FWRFC0;         /*!< (@ 0x00001C00) Forwarding Engine Range Filter Configuration
                                        *                  Register i (FWRFCi) (i = 0, 1)                             */

        struct
        {
            uint32_t            : 8;
            __IOM uint32_t RFM  : 1;   /*!< [8..8] RFM                                                                */
            uint32_t            : 7;
            __IOM uint32_t RFOV : 8;   /*!< [23..16] RFOV                                                             */
            uint32_t            : 8;
        } FWRFC0_b;
    };

    union
    {
        __IOM uint32_t FWRFVC0;        /*!< (@ 0x00001C04) Forwarding Engine Range Filter Value Configuration
                                        *                  Register i (FWRFVCi) (i = 0, 1)                            */

        struct
        {
            __IOM uint32_t RFSV0 : 8;  /*!< [7..0] RFSV0                                                              */
            __IOM uint32_t RFSV1 : 8;  /*!< [15..8] RFSV1                                                             */
            __IOM uint32_t RFRV  : 4;  /*!< [19..16] RFRV                                                             */
            uint32_t             : 12;
        } FWRFVC0_b;
    };
    __IM uint32_t RESERVED73[2];

    union
    {
        __IOM uint32_t FWRFC1;         /*!< (@ 0x00001C10) Forwarding Engine Range Filter Configuration
                                        *                  Register i (FWRFCi) (i = 0, 1)                             */

        struct
        {
            uint32_t            : 8;
            __IOM uint32_t RFM  : 1;   /*!< [8..8] RFM                                                                */
            uint32_t            : 7;
            __IOM uint32_t RFOV : 8;   /*!< [23..16] RFOV                                                             */
            uint32_t            : 8;
        } FWRFC1_b;
    };

    union
    {
        __IOM uint32_t FWRFVC1;        /*!< (@ 0x00001C14) Forwarding Engine Range Filter Value Configuration
                                        *                  Register i (FWRFVCi) (i = 0, 1)                            */

        struct
        {
            __IOM uint32_t RFSV0 : 8;  /*!< [7..0] RFSV0                                                              */
            __IOM uint32_t RFSV1 : 8;  /*!< [15..8] RFSV1                                                             */
            __IOM uint32_t RFRV  : 4;  /*!< [19..16] RFRV                                                             */
            uint32_t             : 12;
        } FWRFVC1_b;
    };
    __IM uint32_t RESERVED74[250];

    union
    {
        __IOM uint32_t FWCFC0;          /*!< (@ 0x00002000) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC0_b;
    };

    union
    {
        __IOM uint32_t FWCFMC00;       /*!< (@ 0x00002004) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC00_b;
    };

    union
    {
        __IOM uint32_t FWCFMC01;       /*!< (@ 0x00002008) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC01_b;
    };

    union
    {
        __IOM uint32_t FWCFMC02;       /*!< (@ 0x0000200C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC02_b;
    };

    union
    {
        __IOM uint32_t FWCFMC03;       /*!< (@ 0x00002010) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC03_b;
    };

    union
    {
        __IOM uint32_t FWCFMC04;       /*!< (@ 0x00002014) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC04_b;
    };

    union
    {
        __IOM uint32_t FWCFMC05;       /*!< (@ 0x00002018) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC05_b;
    };

    union
    {
        __IOM uint32_t FWCFMC06;       /*!< (@ 0x0000201C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC06_b;
    };
    __IM uint32_t RESERVED75[8];

    union
    {
        __IOM uint32_t FWCFC1;          /*!< (@ 0x00002040) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC1_b;
    };

    union
    {
        __IOM uint32_t FWCFMC10;       /*!< (@ 0x00002044) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC10_b;
    };

    union
    {
        __IOM uint32_t FWCFMC11;       /*!< (@ 0x00002048) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC11_b;
    };

    union
    {
        __IOM uint32_t FWCFMC12;       /*!< (@ 0x0000204C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC12_b;
    };

    union
    {
        __IOM uint32_t FWCFMC13;       /*!< (@ 0x00002050) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC13_b;
    };

    union
    {
        __IOM uint32_t FWCFMC14;       /*!< (@ 0x00002054) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC14_b;
    };

    union
    {
        __IOM uint32_t FWCFMC15;       /*!< (@ 0x00002058) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC15_b;
    };

    union
    {
        __IOM uint32_t FWCFMC16;       /*!< (@ 0x0000205C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC16_b;
    };
    __IM uint32_t RESERVED76[8];

    union
    {
        __IOM uint32_t FWCFC2;          /*!< (@ 0x00002080) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC2_b;
    };

    union
    {
        __IOM uint32_t FWCFMC20;       /*!< (@ 0x00002084) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC20_b;
    };

    union
    {
        __IOM uint32_t FWCFMC21;       /*!< (@ 0x00002088) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC21_b;
    };

    union
    {
        __IOM uint32_t FWCFMC22;       /*!< (@ 0x0000208C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC22_b;
    };

    union
    {
        __IOM uint32_t FWCFMC23;       /*!< (@ 0x00002090) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC23_b;
    };

    union
    {
        __IOM uint32_t FWCFMC24;       /*!< (@ 0x00002094) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC24_b;
    };

    union
    {
        __IOM uint32_t FWCFMC25;       /*!< (@ 0x00002098) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC25_b;
    };

    union
    {
        __IOM uint32_t FWCFMC26;       /*!< (@ 0x0000209C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC26_b;
    };
    __IM uint32_t RESERVED77[8];

    union
    {
        __IOM uint32_t FWCFC3;          /*!< (@ 0x000020C0) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC3_b;
    };

    union
    {
        __IOM uint32_t FWCFMC30;       /*!< (@ 0x000020C4) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC30_b;
    };

    union
    {
        __IOM uint32_t FWCFMC31;       /*!< (@ 0x000020C8) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC31_b;
    };

    union
    {
        __IOM uint32_t FWCFMC32;       /*!< (@ 0x000020CC) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC32_b;
    };

    union
    {
        __IOM uint32_t FWCFMC33;       /*!< (@ 0x000020D0) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC33_b;
    };

    union
    {
        __IOM uint32_t FWCFMC34;       /*!< (@ 0x000020D4) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC34_b;
    };

    union
    {
        __IOM uint32_t FWCFMC35;       /*!< (@ 0x000020D8) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC35_b;
    };

    union
    {
        __IOM uint32_t FWCFMC36;       /*!< (@ 0x000020DC) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC36_b;
    };
    __IM uint32_t RESERVED78[8];

    union
    {
        __IOM uint32_t FWCFC4;          /*!< (@ 0x00002100) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC4_b;
    };

    union
    {
        __IOM uint32_t FWCFMC40;       /*!< (@ 0x00002104) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC40_b;
    };

    union
    {
        __IOM uint32_t FWCFMC41;       /*!< (@ 0x00002108) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC41_b;
    };

    union
    {
        __IOM uint32_t FWCFMC42;       /*!< (@ 0x0000210C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC42_b;
    };

    union
    {
        __IOM uint32_t FWCFMC43;       /*!< (@ 0x00002110) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC43_b;
    };

    union
    {
        __IOM uint32_t FWCFMC44;       /*!< (@ 0x00002114) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC44_b;
    };

    union
    {
        __IOM uint32_t FWCFMC45;       /*!< (@ 0x00002118) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC45_b;
    };

    union
    {
        __IOM uint32_t FWCFMC46;       /*!< (@ 0x0000211C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC46_b;
    };
    __IM uint32_t RESERVED79[8];

    union
    {
        __IOM uint32_t FWCFC5;          /*!< (@ 0x00002140) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC5_b;
    };

    union
    {
        __IOM uint32_t FWCFMC50;       /*!< (@ 0x00002144) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC50_b;
    };

    union
    {
        __IOM uint32_t FWCFMC51;       /*!< (@ 0x00002148) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC51_b;
    };

    union
    {
        __IOM uint32_t FWCFMC52;       /*!< (@ 0x0000214C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC52_b;
    };

    union
    {
        __IOM uint32_t FWCFMC53;       /*!< (@ 0x00002150) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC53_b;
    };

    union
    {
        __IOM uint32_t FWCFMC54;       /*!< (@ 0x00002154) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC54_b;
    };

    union
    {
        __IOM uint32_t FWCFMC55;       /*!< (@ 0x00002158) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC55_b;
    };

    union
    {
        __IOM uint32_t FWCFMC56;       /*!< (@ 0x0000215C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC56_b;
    };
    __IM uint32_t RESERVED80[8];

    union
    {
        __IOM uint32_t FWCFC6;          /*!< (@ 0x00002180) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC6_b;
    };

    union
    {
        __IOM uint32_t FWCFMC60;       /*!< (@ 0x00002184) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC60_b;
    };

    union
    {
        __IOM uint32_t FWCFMC61;       /*!< (@ 0x00002188) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC61_b;
    };

    union
    {
        __IOM uint32_t FWCFMC62;       /*!< (@ 0x0000218C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC62_b;
    };

    union
    {
        __IOM uint32_t FWCFMC63;       /*!< (@ 0x00002190) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC63_b;
    };

    union
    {
        __IOM uint32_t FWCFMC64;       /*!< (@ 0x00002194) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC64_b;
    };

    union
    {
        __IOM uint32_t FWCFMC65;       /*!< (@ 0x00002198) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC65_b;
    };

    union
    {
        __IOM uint32_t FWCFMC66;       /*!< (@ 0x0000219C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC66_b;
    };
    __IM uint32_t RESERVED81[8];

    union
    {
        __IOM uint32_t FWCFC7;          /*!< (@ 0x000021C0) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC7_b;
    };

    union
    {
        __IOM uint32_t FWCFMC70;       /*!< (@ 0x000021C4) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC70_b;
    };

    union
    {
        __IOM uint32_t FWCFMC71;       /*!< (@ 0x000021C8) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC71_b;
    };

    union
    {
        __IOM uint32_t FWCFMC72;       /*!< (@ 0x000021CC) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC72_b;
    };

    union
    {
        __IOM uint32_t FWCFMC73;       /*!< (@ 0x000021D0) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC73_b;
    };

    union
    {
        __IOM uint32_t FWCFMC74;       /*!< (@ 0x000021D4) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC74_b;
    };

    union
    {
        __IOM uint32_t FWCFMC75;       /*!< (@ 0x000021D8) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC75_b;
    };

    union
    {
        __IOM uint32_t FWCFMC76;       /*!< (@ 0x000021DC) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC76_b;
    };
    __IM uint32_t RESERVED82[8];

    union
    {
        __IOM uint32_t FWCFC8;          /*!< (@ 0x00002200) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC8_b;
    };

    union
    {
        __IOM uint32_t FWCFMC80;       /*!< (@ 0x00002204) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC80_b;
    };

    union
    {
        __IOM uint32_t FWCFMC81;       /*!< (@ 0x00002208) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC81_b;
    };

    union
    {
        __IOM uint32_t FWCFMC82;       /*!< (@ 0x0000220C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC82_b;
    };

    union
    {
        __IOM uint32_t FWCFMC83;       /*!< (@ 0x00002210) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC83_b;
    };

    union
    {
        __IOM uint32_t FWCFMC84;       /*!< (@ 0x00002214) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC84_b;
    };

    union
    {
        __IOM uint32_t FWCFMC85;       /*!< (@ 0x00002218) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC85_b;
    };

    union
    {
        __IOM uint32_t FWCFMC86;       /*!< (@ 0x0000221C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC86_b;
    };
    __IM uint32_t RESERVED83[8];

    union
    {
        __IOM uint32_t FWCFC9;          /*!< (@ 0x00002240) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC9_b;
    };

    union
    {
        __IOM uint32_t FWCFMC90;       /*!< (@ 0x00002244) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC90_b;
    };

    union
    {
        __IOM uint32_t FWCFMC91;       /*!< (@ 0x00002248) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC91_b;
    };

    union
    {
        __IOM uint32_t FWCFMC92;       /*!< (@ 0x0000224C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC92_b;
    };

    union
    {
        __IOM uint32_t FWCFMC93;       /*!< (@ 0x00002250) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC93_b;
    };

    union
    {
        __IOM uint32_t FWCFMC94;       /*!< (@ 0x00002254) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC94_b;
    };

    union
    {
        __IOM uint32_t FWCFMC95;       /*!< (@ 0x00002258) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC95_b;
    };

    union
    {
        __IOM uint32_t FWCFMC96;       /*!< (@ 0x0000225C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC96_b;
    };
    __IM uint32_t RESERVED84[8];

    union
    {
        __IOM uint32_t FWCFC10;         /*!< (@ 0x00002280) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC10_b;
    };

    union
    {
        __IOM uint32_t FWCFMC100;      /*!< (@ 0x00002284) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC100_b;
    };

    union
    {
        __IOM uint32_t FWCFMC101;      /*!< (@ 0x00002288) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC101_b;
    };

    union
    {
        __IOM uint32_t FWCFMC102;      /*!< (@ 0x0000228C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC102_b;
    };

    union
    {
        __IOM uint32_t FWCFMC103;      /*!< (@ 0x00002290) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC103_b;
    };

    union
    {
        __IOM uint32_t FWCFMC104;      /*!< (@ 0x00002294) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC104_b;
    };

    union
    {
        __IOM uint32_t FWCFMC105;      /*!< (@ 0x00002298) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC105_b;
    };

    union
    {
        __IOM uint32_t FWCFMC106;      /*!< (@ 0x0000229C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC106_b;
    };
    __IM uint32_t RESERVED85[8];

    union
    {
        __IOM uint32_t FWCFC11;         /*!< (@ 0x000022C0) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC11_b;
    };

    union
    {
        __IOM uint32_t FWCFMC110;      /*!< (@ 0x000022C4) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC110_b;
    };

    union
    {
        __IOM uint32_t FWCFMC111;      /*!< (@ 0x000022C8) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC111_b;
    };

    union
    {
        __IOM uint32_t FWCFMC112;      /*!< (@ 0x000022CC) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC112_b;
    };

    union
    {
        __IOM uint32_t FWCFMC113;      /*!< (@ 0x000022D0) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC113_b;
    };

    union
    {
        __IOM uint32_t FWCFMC114;      /*!< (@ 0x000022D4) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC114_b;
    };

    union
    {
        __IOM uint32_t FWCFMC115;      /*!< (@ 0x000022D8) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC115_b;
    };

    union
    {
        __IOM uint32_t FWCFMC116;      /*!< (@ 0x000022DC) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC116_b;
    };
    __IM uint32_t RESERVED86[8];

    union
    {
        __IOM uint32_t FWCFC12;         /*!< (@ 0x00002300) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC12_b;
    };

    union
    {
        __IOM uint32_t FWCFMC120;      /*!< (@ 0x00002304) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC120_b;
    };

    union
    {
        __IOM uint32_t FWCFMC121;      /*!< (@ 0x00002308) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC121_b;
    };

    union
    {
        __IOM uint32_t FWCFMC122;      /*!< (@ 0x0000230C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC122_b;
    };

    union
    {
        __IOM uint32_t FWCFMC123;      /*!< (@ 0x00002310) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC123_b;
    };

    union
    {
        __IOM uint32_t FWCFMC124;      /*!< (@ 0x00002314) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC124_b;
    };

    union
    {
        __IOM uint32_t FWCFMC125;      /*!< (@ 0x00002318) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC125_b;
    };

    union
    {
        __IOM uint32_t FWCFMC126;      /*!< (@ 0x0000231C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC126_b;
    };
    __IM uint32_t RESERVED87[8];

    union
    {
        __IOM uint32_t FWCFC13;         /*!< (@ 0x00002340) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC13_b;
    };

    union
    {
        __IOM uint32_t FWCFMC130;      /*!< (@ 0x00002344) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC130_b;
    };

    union
    {
        __IOM uint32_t FWCFMC131;      /*!< (@ 0x00002348) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC131_b;
    };

    union
    {
        __IOM uint32_t FWCFMC132;      /*!< (@ 0x0000234C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC132_b;
    };

    union
    {
        __IOM uint32_t FWCFMC133;      /*!< (@ 0x00002350) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC133_b;
    };

    union
    {
        __IOM uint32_t FWCFMC134;      /*!< (@ 0x00002354) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC134_b;
    };

    union
    {
        __IOM uint32_t FWCFMC135;      /*!< (@ 0x00002358) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC135_b;
    };

    union
    {
        __IOM uint32_t FWCFMC136;      /*!< (@ 0x0000235C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC136_b;
    };
    __IM uint32_t RESERVED88[8];

    union
    {
        __IOM uint32_t FWCFC14;         /*!< (@ 0x00002380) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC14_b;
    };

    union
    {
        __IOM uint32_t FWCFMC140;      /*!< (@ 0x00002384) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC140_b;
    };

    union
    {
        __IOM uint32_t FWCFMC141;      /*!< (@ 0x00002388) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC141_b;
    };

    union
    {
        __IOM uint32_t FWCFMC142;      /*!< (@ 0x0000238C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC142_b;
    };

    union
    {
        __IOM uint32_t FWCFMC143;      /*!< (@ 0x00002390) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC143_b;
    };

    union
    {
        __IOM uint32_t FWCFMC144;      /*!< (@ 0x00002394) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC144_b;
    };

    union
    {
        __IOM uint32_t FWCFMC145;      /*!< (@ 0x00002398) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC145_b;
    };

    union
    {
        __IOM uint32_t FWCFMC146;      /*!< (@ 0x0000239C) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC146_b;
    };
    __IM uint32_t RESERVED89[8];

    union
    {
        __IOM uint32_t FWCFC15;         /*!< (@ 0x000023C0) Forwarding Engine Cascade Filter Configuration
                                         *                  Register i (FWCFCi) (i = 0 to 15)                          */

        struct
        {
            __IOM uint32_t CFEFFV0 : 1; /*!< [0..0] CFEFFV0                                                            */
            __IOM uint32_t CFEFFV1 : 1; /*!< [1..1] CFEFFV1                                                            */
            __IOM uint32_t CFEFFV2 : 1; /*!< [2..2] CFEFFV2                                                            */
            uint32_t               : 13;
            __IOM uint32_t CFPFFV0 : 1; /*!< [16..16] CFPFFV0                                                          */
            __IOM uint32_t CFPFFV1 : 1; /*!< [17..17] CFPFFV1                                                          */
            uint32_t               : 14;
        } FWCFC15_b;
    };

    union
    {
        __IOM uint32_t FWCFMC150;      /*!< (@ 0x000023C4) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC150_b;
    };

    union
    {
        __IOM uint32_t FWCFMC151;      /*!< (@ 0x000023C8) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC151_b;
    };

    union
    {
        __IOM uint32_t FWCFMC152;      /*!< (@ 0x000023CC) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC152_b;
    };

    union
    {
        __IOM uint32_t FWCFMC153;      /*!< (@ 0x000023D0) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC153_b;
    };

    union
    {
        __IOM uint32_t FWCFMC154;      /*!< (@ 0x000023D4) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC154_b;
    };

    union
    {
        __IOM uint32_t FWCFMC155;      /*!< (@ 0x000023D8) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC155_b;
    };

    union
    {
        __IOM uint32_t FWCFMC156;      /*!< (@ 0x000023DC) Forwarding Engine Cascade Filter Mapping Configuration
                                        *                  Register ij (FWCFMCij) (i = 0 to 15) (j
                                        *                  = 0 to 6)                                                  */

        struct
        {
            __IOM uint32_t CFFN : 7;   /*!< [6..0] CFFN                                                               */
            uint32_t            : 8;
            __IOM uint32_t CFFV : 1;   /*!< [15..15] CFFV                                                             */
            uint32_t            : 16;
        } FWCFMC156_b;
    };
    __IM uint32_t RESERVED90[1802];

    union
    {
        __IOM uint32_t FWIP4SC;          /*!< (@ 0x00004008) Forwarding Engine IPv4 Stream Configuration Register
                                          *                  (FWIP4SC)                                                  */

        struct
        {
            __IOM uint32_t IP4IMDH  : 1; /*!< [0..0] IP4IMDH                                                            */
            __IOM uint32_t IP4IMSH  : 1; /*!< [1..1] IP4IMSH                                                            */
            __IOM uint32_t IP4ISVH  : 1; /*!< [2..2] IP4ISVH                                                            */
            __IOM uint32_t IP4ISPH  : 1; /*!< [3..3] IP4ISPH                                                            */
            __IOM uint32_t IP4ISDH  : 1; /*!< [4..4] IP4ISDH                                                            */
            __IOM uint32_t IP4ICVH  : 1; /*!< [5..5] IP4ICVH                                                            */
            __IOM uint32_t IP4ICPH  : 1; /*!< [6..6] IP4ICPH                                                            */
            __IOM uint32_t IP4ICDH  : 1; /*!< [7..7] IP4ICDH                                                            */
            __IOM uint32_t IP4IISH  : 1; /*!< [8..8] IP4IISH                                                            */
            __IOM uint32_t IP4IIDH  : 1; /*!< [9..9] IP4IIDH                                                            */
            __IOM uint32_t IP4IPH   : 1; /*!< [10..10] IP4IPH                                                           */
            __IOM uint32_t IP4ISPTH : 1; /*!< [11..11] IP4ISPTH                                                         */
            __IOM uint32_t IP4IDPTH : 1; /*!< [12..12] IP4IDPTH                                                         */
            uint32_t                : 3;
            __IOM uint32_t IP4ISVS  : 1; /*!< [16..16] IP4ISVS                                                          */
            __IOM uint32_t IP4ISPS  : 1; /*!< [17..17] IP4ISPS                                                          */
            __IOM uint32_t IP4ISDS  : 1; /*!< [18..18] IP4ISDS                                                          */
            __IOM uint32_t IP4ICVS  : 1; /*!< [19..19] IP4ICVS                                                          */
            __IOM uint32_t IP4ICPS  : 1; /*!< [20..20] IP4ICPS                                                          */
            __IOM uint32_t IP4ICDS  : 1; /*!< [21..21] IP4ICDS                                                          */
            __IOM uint32_t IP4IISS  : 1; /*!< [22..22] IP4IISS                                                          */
            __IOM uint32_t IP4IIDS  : 1; /*!< [23..23] IP4IIDS                                                          */
            __IOM uint32_t IP4IDPTS : 1; /*!< [24..24] IP4IDPTS                                                         */
            uint32_t                : 7;
        } FWIP4SC_b;
    };
    __IM uint32_t RESERVED91[3];

    union
    {
        __IOM uint32_t FWIP6SC;          /*!< (@ 0x00004018) Forwarding Engine IPv6 Stream Configuration Register
                                          *                  (FWIP6SC)                                                  */

        struct
        {
            __IOM uint32_t IP6IMDH  : 1; /*!< [0..0] IP6IMDH                                                            */
            __IOM uint32_t IP6IMSH  : 1; /*!< [1..1] IP6IMSH                                                            */
            __IOM uint32_t IP6ISVH  : 1; /*!< [2..2] IP6ISVH                                                            */
            __IOM uint32_t IP6ISPH  : 1; /*!< [3..3] IP6ISPH                                                            */
            __IOM uint32_t IP6ISDH  : 1; /*!< [4..4] IP6ISDH                                                            */
            __IOM uint32_t IP6ICVH  : 1; /*!< [5..5] IP6ICVH                                                            */
            __IOM uint32_t IP6ICPH  : 1; /*!< [6..6] IP6ICPH                                                            */
            __IOM uint32_t IP6ICDH  : 1; /*!< [7..7] IP6ICDH                                                            */
            __IOM uint32_t IP6IISH  : 1; /*!< [8..8] IP6IISH                                                            */
            __IOM uint32_t IP6IIDH  : 1; /*!< [9..9] IP6IIDH                                                            */
            __IOM uint32_t IP6IPH   : 1; /*!< [10..10] IP6IPH                                                           */
            __IOM uint32_t IP6ISPTH : 1; /*!< [11..11] IP6ISPTH                                                         */
            __IOM uint32_t IP6IDPTH : 1; /*!< [12..12] IP6IDPTH                                                         */
            uint32_t                : 3;
            __IOM uint32_t IP6ISVS  : 1; /*!< [16..16] IP6ISVS                                                          */
            __IOM uint32_t IP6ISPS  : 1; /*!< [17..17] IP6ISPS                                                          */
            __IOM uint32_t IP6ISDS  : 1; /*!< [18..18] IP6ISDS                                                          */
            __IOM uint32_t IP6ICVS  : 1; /*!< [19..19] IP6ICVS                                                          */
            __IOM uint32_t IP6ICPS  : 1; /*!< [20..20] IP6ICPS                                                          */
            __IOM uint32_t IP6ICDS  : 1; /*!< [21..21] IP6ICDS                                                          */
            __IOM uint32_t IP6II0S  : 1; /*!< [22..22] IP6II0S                                                          */
            __IOM uint32_t IP6II1S  : 1; /*!< [23..23] IP6II1S                                                          */
            __IOM uint32_t IP6IDPTS : 1; /*!< [24..24] IP6IDPTS                                                         */
            uint32_t                : 7;
        } FWIP6SC_b;
    };

    union
    {
        __IOM uint32_t FWIP6OC;          /*!< (@ 0x0000401C) Forwarding Engine IPv6 Offset Configuration Register
                                          *                  (FWIP6OC)                                                  */

        struct
        {
            __IOM uint32_t IP6IPOM0 : 1; /*!< [0..0] IP6IPOM0                                                           */
            uint32_t                : 3;
            __IOM uint32_t IP6IPO0  : 4; /*!< [7..4] IP6IPO0                                                            */
            uint32_t                : 8;
            __IOM uint32_t IP6IPOM1 : 1; /*!< [16..16] IP6IPOM1                                                         */
            uint32_t                : 3;
            __IOM uint32_t IP6IPO1  : 4; /*!< [23..20] IP6IPO1                                                          */
            uint32_t                : 8;
        } FWIP6OC_b;
    };

    union
    {
        __IOM uint32_t FWL2SC;         /*!< (@ 0x00004020) Forwarding Engine Layer 2 Stream Configuration
                                        *                  Register (FWL2SC)                                          */

        struct
        {
            __IOM uint32_t L2IMDS : 1; /*!< [0..0] L2IMDS                                                             */
            __IOM uint32_t L2IMSS : 1; /*!< [1..1] L2IMSS                                                             */
            __IOM uint32_t L2ISVS : 1; /*!< [2..2] L2ISVS                                                             */
            __IOM uint32_t L2ISPS : 1; /*!< [3..3] L2ISPS                                                             */
            __IOM uint32_t L2ISDS : 1; /*!< [4..4] L2ISDS                                                             */
            __IOM uint32_t L2ICVS : 1; /*!< [5..5] L2ICVS                                                             */
            __IOM uint32_t L2ICPS : 1; /*!< [6..6] L2ICPS                                                             */
            __IOM uint32_t L2ICDS : 1; /*!< [7..7] L2ICDS                                                             */
            uint32_t              : 24;
        } FWL2SC_b;
    };
    __IM uint32_t RESERVED92[3];

    union
    {
        __IOM uint32_t FWSFHEC;         /*!< (@ 0x00004030) Forwarding Engine Stream Filter Hash Equation
                                         *                  Configuration Register (FWSFHEC)                           */

        struct
        {
            __IOM uint32_t IP4HE0  : 1; /*!< [0..0] IP4HE0                                                             */
            __IOM uint32_t IP4HE1  : 1; /*!< [1..1] IP4HE1                                                             */
            __IOM uint32_t IP4HE2  : 1; /*!< [2..2] IP4HE2                                                             */
            __IOM uint32_t IP4HE3  : 1; /*!< [3..3] IP4HE3                                                             */
            __IOM uint32_t IP4HE4  : 1; /*!< [4..4] IP4HE4                                                             */
            __IOM uint32_t IP4HE5  : 1; /*!< [5..5] IP4HE5                                                             */
            __IOM uint32_t IP4HE6  : 1; /*!< [6..6] IP4HE6                                                             */
            __IOM uint32_t IP4HE7  : 1; /*!< [7..7] IP4HE7                                                             */
            __IOM uint32_t IP4HE8  : 1; /*!< [8..8] IP4HE8                                                             */
            __IOM uint32_t IP4HE9  : 1; /*!< [9..9] IP4HE9                                                             */
            __IOM uint32_t IP4HE10 : 1; /*!< [10..10] IP4HE10                                                          */
            __IOM uint32_t IP4HE11 : 1; /*!< [11..11] IP4HE11                                                          */
            __IOM uint32_t IP4HE12 : 1; /*!< [12..12] IP4HE12                                                          */
            __IOM uint32_t IP4HE13 : 1; /*!< [13..13] IP4HE13                                                          */
            __IOM uint32_t IP4HE14 : 1; /*!< [14..14] IP4HE14                                                          */
            __IOM uint32_t IP4HE15 : 1; /*!< [15..15] IP4HE15                                                          */
            __IOM uint32_t IP6HE0  : 1; /*!< [16..16] IP6HE0                                                           */
            __IOM uint32_t IP6HE1  : 1; /*!< [17..17] IP6HE1                                                           */
            __IOM uint32_t IP6HE2  : 1; /*!< [18..18] IP6HE2                                                           */
            __IOM uint32_t IP6HE3  : 1; /*!< [19..19] IP6HE3                                                           */
            __IOM uint32_t IP6HE4  : 1; /*!< [20..20] IP6HE4                                                           */
            __IOM uint32_t IP6HE5  : 1; /*!< [21..21] IP6HE5                                                           */
            __IOM uint32_t IP6HE6  : 1; /*!< [22..22] IP6HE6                                                           */
            __IOM uint32_t IP6HE7  : 1; /*!< [23..23] IP6HE7                                                           */
            __IOM uint32_t IP6HE8  : 1; /*!< [24..24] IP6HE8                                                           */
            __IOM uint32_t IP6HE9  : 1; /*!< [25..25] IP6HE9                                                           */
            __IOM uint32_t IP6HE10 : 1; /*!< [26..26] IP6HE10                                                          */
            __IOM uint32_t IP6HE11 : 1; /*!< [27..27] IP6HE11                                                          */
            __IOM uint32_t IP6HE12 : 1; /*!< [28..28] IP6HE12                                                          */
            __IOM uint32_t IP6HE13 : 1; /*!< [29..29] IP6HE13                                                          */
            __IOM uint32_t IP6HE14 : 1; /*!< [30..30] IP6HE14                                                          */
            __IOM uint32_t IP6HE15 : 1; /*!< [31..31] IP6HE15                                                          */
        } FWSFHEC_b;
    };
    __IM uint32_t RESERVED93[3];

    union
    {
        __IOM uint32_t FWSHCR0;          /*!< (@ 0x00004040) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 0 (FWSHCR0)                                       */

        struct
        {
            __IOM uint32_t SHCMDP0 : 32; /*!< [31..0] SHCMDP0                                                           */
        } FWSHCR0_b;
    };

    union
    {
        __IOM uint32_t FWSHCR1;          /*!< (@ 0x00004044) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 1 (FWSHCR1)                                       */

        struct
        {
            __IOM uint32_t SHCMSP0 : 16; /*!< [15..0] SHCMSP0                                                           */
            __IOM uint32_t SHCMDP1 : 16; /*!< [31..16] SHCMDP1                                                          */
        } FWSHCR1_b;
    };

    union
    {
        __IOM uint32_t FWSHCR2;          /*!< (@ 0x00004048) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 2 (FWSHCR2)                                       */

        struct
        {
            __IOM uint32_t SHCMSP1 : 32; /*!< [31..0] SHCMSP1                                                           */
        } FWSHCR2_b;
    };

    union
    {
        __IOM uint32_t FWSHCR3;        /*!< (@ 0x0000404C) Forwarding Engine Software Hash Calculation Request
                                        *                  Register 3 (FWSHCR3)                                       */

        struct
        {
            __IOM uint32_t SHCCV : 12; /*!< [11..0] SHCCV                                                             */
            __IOM uint32_t SHCCD : 1;  /*!< [12..12] SHCCD                                                            */
            __IOM uint32_t SHCCP : 3;  /*!< [15..13] SHCCP                                                            */
            __IOM uint32_t SHCSV : 12; /*!< [27..16] SHCSV                                                            */
            __IOM uint32_t SHCSD : 1;  /*!< [28..28] SHCSD                                                            */
            __IOM uint32_t SHCSP : 3;  /*!< [31..29] SHCSP                                                            */
        } FWSHCR3_b;
    };

    union
    {
        __IOM uint32_t FWSHCR4;        /*!< (@ 0x00004050) Forwarding Engine Software Hash Calculation Request
                                        *                  Register 4 (FWSHCR4)                                       */

        struct
        {
            __IOM uint32_t SHCP  : 8;  /*!< [7..0] SHCP                                                               */
            uint32_t             : 8;
            __IOM uint32_t SHCFF : 1;  /*!< [16..16] SHCFF                                                            */
            uint32_t             : 15;
        } FWSHCR4_b;
    };

    union
    {
        __IOM uint32_t FWSHCR5;          /*!< (@ 0x00004054) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 5 (FWSHCR5)                                       */

        struct
        {
            __IOM uint32_t SHCISP0 : 32; /*!< [31..0] SHCISP0                                                           */
        } FWSHCR5_b;
    };

    union
    {
        __IOM uint32_t FWSHCR6;          /*!< (@ 0x00004058) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 6 (FWSHCR6)                                       */

        struct
        {
            __IOM uint32_t SHCISP1 : 32; /*!< [31..0] SHCISP1                                                           */
        } FWSHCR6_b;
    };

    union
    {
        __IOM uint32_t FWSHCR7;          /*!< (@ 0x0000405C) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 7 (FWSHCR7)                                       */

        struct
        {
            __IOM uint32_t SHCISP2 : 32; /*!< [31..0] SHCISP2                                                           */
        } FWSHCR7_b;
    };

    union
    {
        __IOM uint32_t FWSHCR8;          /*!< (@ 0x00004060) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 8 (FWSHCR8)                                       */

        struct
        {
            __IOM uint32_t SHCISP3 : 32; /*!< [31..0] SHCISP3                                                           */
        } FWSHCR8_b;
    };

    union
    {
        __IOM uint32_t FWSHCR9;          /*!< (@ 0x00004064) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 9 (FWSHCR9)                                       */

        struct
        {
            __IOM uint32_t SHCIDP0 : 32; /*!< [31..0] SHCIDP0                                                           */
        } FWSHCR9_b;
    };

    union
    {
        __IOM uint32_t FWSHCR10;         /*!< (@ 0x00004068) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 10 (FWSHCR10)                                     */

        struct
        {
            __IOM uint32_t SHCIDP1 : 32; /*!< [31..0] SHCIDP1                                                           */
        } FWSHCR10_b;
    };

    union
    {
        __IOM uint32_t FWSHCR11;         /*!< (@ 0x0000406C) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 11 (FWSHCR11)                                     */

        struct
        {
            __IOM uint32_t SHCIDP2 : 32; /*!< [31..0] SHCIDP2                                                           */
        } FWSHCR11_b;
    };

    union
    {
        __IOM uint32_t FWSHCR12;         /*!< (@ 0x00004070) Forwarding Engine Software Hash Calculation Request
                                          *                  Register 12 (FWSHCR12)                                     */

        struct
        {
            __IOM uint32_t SHCIDP3 : 32; /*!< [31..0] SHCIDP3                                                           */
        } FWSHCR12_b;
    };

    union
    {
        __IOM uint32_t FWSHCR13;       /*!< (@ 0x00004074) Forwarding Engine Software Hash Calculation Request
                                        *                  Register 13 (FWSHCR13)                                     */

        struct
        {
            __IOM uint32_t SHCDP : 16; /*!< [15..0] SHCDP                                                             */
            __IOM uint32_t SHCSP : 16; /*!< [31..16] SHCSP                                                            */
        } FWSHCR13_b;
    };

    union
    {
        __IOM uint32_t FWSHCRR;        /*!< (@ 0x00004078) Forwarding Engine Software Hash Calculation Request
                                        *                  Result Register (FWSHCRR)                                  */

        struct
        {
            __IOM uint32_t SHCR : 16;  /*!< [15..0] SHCR                                                              */
            uint32_t            : 15;
            __IOM uint32_t SHC  : 1;   /*!< [31..31] SHC                                                              */
        } FWSHCRR_b;
    };
    __IM uint32_t RESERVED94[5];

    union
    {
        __IOM uint32_t FWLTHHEC;        /*!< (@ 0x00004090) Forwarding Engine L3 Hash Entry Configuration
                                         *                  Register (FWLTHHEC)                                        */

        struct
        {
            __IOM uint32_t LTHHMC  : 8; /*!< [7..0] LTHHMC                                                             */
            uint32_t               : 8;
            __IOM uint32_t LTHHMUE : 9; /*!< [24..16] LTHHMUE                                                          */
            uint32_t               : 7;
        } FWLTHHEC_b;
    };

    union
    {
        __IOM uint32_t FWLTHHC;        /*!< (@ 0x00004094) Forwarding Engine L3 Hash Configuration Register
                                        *                  (FWLTHHC)                                                  */

        struct
        {
            __IOM uint32_t LTHHE0 : 1; /*!< [0..0] LTHHE0                                                             */
            __IOM uint32_t LTHHE1 : 1; /*!< [1..1] LTHHE1                                                             */
            __IOM uint32_t LTHHE2 : 1; /*!< [2..2] LTHHE2                                                             */
            __IOM uint32_t LTHHE3 : 1; /*!< [3..3] LTHHE3                                                             */
            __IOM uint32_t LTHHE4 : 1; /*!< [4..4] LTHHE4                                                             */
            __IOM uint32_t LTHHE5 : 1; /*!< [5..5] LTHHE5                                                             */
            __IOM uint32_t LTHHE6 : 1; /*!< [6..6] LTHHE6                                                             */
            __IOM uint32_t LTHHE7 : 1; /*!< [7..7] LTHHE7                                                             */
            uint32_t              : 24;
        } FWLTHHC_b;
    };
    __IM uint32_t RESERVED95[2];

    union
    {
        __IOM uint32_t FWLTHTL0;        /*!< (@ 0x000040A0) Forwarding Engine L3 Table Learn Register 0 (FWLTHTL0)     */

        struct
        {
            __IOM uint32_t LTHSLP0 : 3; /*!< [2..0] LTHSLP0                                                            */
            uint32_t               : 5;
            __IOM uint32_t LTHSLL  : 1; /*!< [8..8] LTHSLL                                                             */
            uint32_t               : 7;
            __IOM uint32_t LTHED   : 1; /*!< [16..16] LTHED                                                            */
            uint32_t               : 15;
        } FWLTHTL0_b;
    };

    union
    {
        __IOM uint32_t FWLTHTL1;         /*!< (@ 0x000040A4) Forwarding Engine L3 Table Learn Register 1 (FWLTHTL1)     */

        struct
        {
            __IOM uint32_t LTHSLP1 : 32; /*!< [31..0] LTHSLP1                                                           */
        } FWLTHTL1_b;
    };

    union
    {
        __IOM uint32_t FWLTHTL2;         /*!< (@ 0x000040A8) Forwarding Engine L3 Table Learn Register 2 (FWLTHTL2)     */

        struct
        {
            __IOM uint32_t LTHSLP2 : 32; /*!< [31..0] LTHSLP2                                                           */
        } FWLTHTL2_b;
    };

    union
    {
        __IOM uint32_t FWLTHTL3;         /*!< (@ 0x000040AC) Forwarding Engine L3 Table Learn Register 3 (FWLTHTL3)     */

        struct
        {
            __IOM uint32_t LTHSLP3 : 32; /*!< [31..0] LTHSLP3                                                           */
        } FWLTHTL3_b;
    };

    union
    {
        __IOM uint32_t FWLTHTL4;         /*!< (@ 0x000040B0) Forwarding Engine L3 Table Learn Register 4 (FWLTHTL4)     */

        struct
        {
            __IOM uint32_t LTHSLP4 : 32; /*!< [31..0] LTHSLP4                                                           */
        } FWLTHTL4_b;
    };

    union
    {
        __IOM uint32_t FWLTHTL5;       /*!< (@ 0x000040B4) Forwarding Engine L3 Table Learn Register 5 (FWLTHTL5)     */

        struct
        {
            uint32_t                 : 16;
            __IOM uint32_t LTHMSDUNL : 4; /*!< [19..16] LTHMSDUNL                                                        */
            uint32_t                 : 11;
            __IOM uint32_t LTHMSDUVL : 1; /*!< [31..31] LTHMSDUVL                                                        */
        } FWLTHTL5_b;
    };

    union
    {
        __IOM uint32_t FWLTHTL6;          /*!< (@ 0x000040B8) Forwarding Engine L3 Table Learn Register 6 (FWLTHTL6)     */

        struct
        {
            __IOM uint32_t LTHFRERNL : 7; /*!< [6..0] LTHFRERNL                                                          */
            uint32_t                 : 8;
            __IOM uint32_t LTHFRERVL : 1; /*!< [15..15] LTHFRERVL                                                        */
            __IOM uint32_t LTHMTRNL  : 5; /*!< [20..16] LTHMTRNL                                                         */
            uint32_t                 : 10;
            __IOM uint32_t LTHMTRVL  : 1; /*!< [31..31] LTHMTRVL                                                         */
        } FWLTHTL6_b;
    };

    union
    {
        __IOM uint32_t FWLTHTL7;        /*!< (@ 0x000040BC) Forwarding Engine L3 Table Learn Register 7 (FWLTHTL7)     */

        struct
        {
            __IOM uint32_t LTHRNL  : 8; /*!< [7..0] LTHRNL                                                             */
            uint32_t               : 7;
            __IOM uint32_t LTHRVL  : 1; /*!< [15..15] LTHRVL                                                           */
            __IOM uint32_t LTHSLVL : 3; /*!< [18..16] LTHSLVL                                                          */
            uint32_t               : 13;
        } FWLTHTL7_b;
    };

    union
    {
        __IOM uint32_t FWLTHTL80;       /*!< (@ 0x000040C0) Forwarding Engine L3 Table Learn Register 80
                                         *                  (FWLTHTL80)                                                */

        struct
        {
            __IOM uint32_t LTHCSDL : 6; /*!< [5..0] LTHCSDL                                                            */
            uint32_t               : 26;
        } FWLTHTL80_b;
    };
    __IM uint32_t RESERVED96[3];

    union
    {
        __IOM uint32_t FWLTHTL9;        /*!< (@ 0x000040D0) Forwarding Engine L3 Table Learn Register 9 (FWLTHTL9)     */

        struct
        {
            __IOM uint32_t LTHDVL  : 3; /*!< [2..0] LTHDVL                                                             */
            uint32_t               : 13;
            __IOM uint32_t LTHIPVL : 3; /*!< [18..16] LTHIPVL                                                          */
            __IOM uint32_t LTHIPUL : 1; /*!< [19..19] LTHIPUL                                                          */
            __IOM uint32_t LTHEMEL : 1; /*!< [20..20] LTHEMEL                                                          */
            __IOM uint32_t LTHCMEL : 1; /*!< [21..21] LTHCMEL                                                          */
            uint32_t               : 10;
        } FWLTHTL9_b;
    };

    union
    {
        __IOM uint32_t FWLTHTLR;       /*!< (@ 0x000040D4) Forwarding Engine L3 Table Learn Result Register
                                        *                  (FWLTHTLR)                                                 */

        struct
        {
            __IOM uint32_t LTHLF  : 1; /*!< [0..0] LTHLF                                                              */
            __IOM uint32_t LTHLSF : 1; /*!< [1..1] LTHLSF                                                             */
            __IOM uint32_t LTHLEF : 1; /*!< [2..2] LTHLEF                                                             */
            __IOM uint32_t LTHLO  : 1; /*!< [3..3] LTHLO                                                              */
            uint32_t              : 12;
            __IOM uint32_t LTHLCN : 8; /*!< [23..16] LTHLCN                                                           */
            uint32_t              : 7;
            __IOM uint32_t LTHTL  : 1; /*!< [31..31] LTHTL                                                            */
        } FWLTHTLR_b;
    };
    __IM uint32_t RESERVED97[2];

    union
    {
        __IOM uint32_t FWLTHTIM;        /*!< (@ 0x000040E0) Forwarding Engine L3 Table Initialization Monitoring
                                         *                  Register (FWLTHTIM)                                        */

        struct
        {
            __IOM uint32_t LTHTIOG : 1; /*!< [0..0] LTHTIOG                                                            */
            __IOM uint32_t LTHTR   : 1; /*!< [1..1] LTHTR                                                              */
            uint32_t               : 30;
        } FWLTHTIM_b;
    };

    union
    {
        __IOM uint32_t FWLTHTEM;        /*!< (@ 0x000040E4) Forwarding Engine L3 Table Entry Monitoring Register
                                         *                  (FWLTHTEM)                                                 */

        struct
        {
            __IOM uint32_t LTHTEN  : 9; /*!< [8..0] LTHTEN                                                             */
            uint32_t               : 7;
            __IOM uint32_t LTHTUEN : 9; /*!< [24..16] LTHTUEN                                                          */
            uint32_t               : 7;
        } FWLTHTEM_b;
    };
    __IM uint32_t RESERVED98[6];

    union
    {
        __IOM uint32_t FWLTHTS0;        /*!< (@ 0x00004100) Forwarding Engine L3 Table Search Register 0
                                         *                  (FWLTHTS0)                                                 */

        struct
        {
            __IOM uint32_t LTHSSP0 : 3; /*!< [2..0] LTHSSP0                                                            */
            uint32_t               : 29;
        } FWLTHTS0_b;
    };

    union
    {
        __IOM uint32_t FWLTHTS1;         /*!< (@ 0x00004104) Forwarding Engine L3 Table Search Register 1
                                          *                  (FWLTHTS1)                                                 */

        struct
        {
            __IOM uint32_t LTHSSP1 : 32; /*!< [31..0] LTHSSP1                                                           */
        } FWLTHTS1_b;
    };

    union
    {
        __IOM uint32_t FWLTHTS2;         /*!< (@ 0x00004108) Forwarding Engine L3 Table Search Register 2
                                          *                  (FWLTHTS2)                                                 */

        struct
        {
            __IOM uint32_t LTHSSP2 : 32; /*!< [31..0] LTHSSP2                                                           */
        } FWLTHTS2_b;
    };

    union
    {
        __IOM uint32_t FWLTHTS3;         /*!< (@ 0x0000410C) Forwarding Engine L3 Table Search Register 3
                                          *                  (FWLTHTS3)                                                 */

        struct
        {
            __IOM uint32_t LTHSSP3 : 32; /*!< [31..0] LTHSSP3                                                           */
        } FWLTHTS3_b;
    };

    union
    {
        __IOM uint32_t FWLTHTS4;         /*!< (@ 0x00004110) Forwarding Engine L3 Table Search Register 4
                                          *                  (FWLTHTS4)                                                 */

        struct
        {
            __IOM uint32_t LTHSSP4 : 32; /*!< [31..0] LTHSSP4                                                           */
        } FWLTHTS4_b;
    };
    __IM uint32_t RESERVED99[3];

    union
    {
        __IOM uint32_t FWLTHTSR0;      /*!< (@ 0x00004120) Forwarding Engine L3 Table Search Result Register
                                        *                  0 (FWLTHTSR0)                                              */

        struct
        {
            __IOM uint32_t LTHSEF : 1; /*!< [0..0] LTHSEF                                                             */
            __IOM uint32_t LTHSNF : 1; /*!< [1..1] LTHSNF                                                             */
            uint32_t              : 6;
            __IOM uint32_t LTHSLS : 1; /*!< [8..8] LTHSLS                                                             */
            uint32_t              : 7;
            __IOM uint32_t LTHSCN : 8; /*!< [23..16] LTHSCN                                                           */
            uint32_t              : 7;
            __IOM uint32_t LTHTS  : 1; /*!< [31..31] LTHTS                                                            */
        } FWLTHTSR0_b;
    };

    union
    {
        __IOM uint32_t FWLTHTSR1;      /*!< (@ 0x00004124) Forwarding Engine L3 Table Search Result Register
                                        *                  1 (FWLTHTSR1)                                              */

        struct
        {
            uint32_t                 : 16;
            __IOM uint32_t LTHMSDUNS : 4; /*!< [19..16] LTHMSDUNS                                                        */
            uint32_t                 : 11;
            __IOM uint32_t LTHMSDUVS : 1; /*!< [31..31] LTHMSDUVS                                                        */
        } FWLTHTSR1_b;
    };

    union
    {
        __IOM uint32_t FWLTHTSR2;         /*!< (@ 0x00004128) Forwarding Engine L3 Table Search Result Register
                                           *                  2 (FWLTHTSR2)                                              */

        struct
        {
            __IOM uint32_t LTHFRERNS : 7; /*!< [6..0] LTHFRERNS                                                          */
            uint32_t                 : 8;
            __IOM uint32_t LTHFRERVS : 1; /*!< [15..15] LTHFRERVS                                                        */
            __IOM uint32_t LTHMTRNS  : 5; /*!< [20..16] LTHMTRNS                                                         */
            uint32_t                 : 10;
            __IOM uint32_t LTHMTRVS  : 1; /*!< [31..31] LTHMTRVS                                                         */
        } FWLTHTSR2_b;
    };

    union
    {
        __IOM uint32_t FWLTHTSR3;       /*!< (@ 0x0000412C) Forwarding Engine L3 Table Search Result Register
                                         *                  3 (FWLTHTSR3)                                              */

        struct
        {
            __IOM uint32_t LTHRNS  : 8; /*!< [7..0] LTHRNS                                                             */
            uint32_t               : 7;
            __IOM uint32_t LTHRVS  : 1; /*!< [15..15] LTHRVS                                                           */
            __IOM uint32_t LTHSLVS : 3; /*!< [18..16] LTHSLVS                                                          */
            uint32_t               : 13;
        } FWLTHTSR3_b;
    };

    union
    {
        __IOM uint32_t FWLTHTSR40;      /*!< (@ 0x00004130) Forwarding Engine L3 Table Search Result Register
                                         *                  40 (FWLTHTSR40)                                            */

        struct
        {
            __IOM uint32_t LTHCSDS : 6; /*!< [5..0] LTHCSDS                                                            */
            uint32_t               : 26;
        } FWLTHTSR40_b;
    };
    __IM uint32_t RESERVED100[3];

    union
    {
        __IOM uint32_t FWLTHTSR5;       /*!< (@ 0x00004140) Forwarding Engine L3 Table Search Result Register
                                         *                  5 (FWLTHTSR5)                                              */

        struct
        {
            __IOM uint32_t LTHDVS  : 3; /*!< [2..0] LTHDVS                                                             */
            uint32_t               : 13;
            __IOM uint32_t LTHIPVS : 3; /*!< [18..16] LTHIPVS                                                          */
            __IOM uint32_t LTHIPUS : 1; /*!< [19..19] LTHIPUS                                                          */
            __IOM uint32_t LTHEMES : 1; /*!< [20..20] LTHEMES                                                          */
            __IOM uint32_t LTHCMES : 1; /*!< [21..21] LTHCMES                                                          */
            uint32_t               : 10;
        } FWLTHTSR5_b;
    };
    __IM uint32_t RESERVED101[3];

    union
    {
        __IOM uint32_t FWLTHTR;        /*!< (@ 0x00004150) Forwarding Engine L3 Table Read Register (FWLTHTR)         */

        struct
        {
            __IOM uint32_t LTHAR : 8;  /*!< [7..0] LTHAR                                                              */
            uint32_t             : 24;
        } FWLTHTR_b;
    };

    union
    {
        __IOM uint32_t FWLTHTRR0;      /*!< (@ 0x00004154) Forwarding Engine L3 Table Read Result Register
                                        *                  0 (FWLTHTRR0)                                              */

        struct
        {
            __IOM uint32_t LTHREF : 1; /*!< [0..0] LTHREF                                                             */
            __IOM uint32_t LTHEVR : 1; /*!< [1..1] LTHEVR                                                             */
            uint32_t              : 29;
            __IOM uint32_t LTHTR  : 1; /*!< [31..31] LTHTR                                                            */
        } FWLTHTRR0_b;
    };

    union
    {
        __IOM uint32_t FWLTHTRR1;       /*!< (@ 0x00004158) Forwarding Engine L3 Table Read Result Register
                                         *                  1 (FWLTHTRR1)                                              */

        struct
        {
            __IOM uint32_t LTHSRP0 : 3; /*!< [2..0] LTHSRP0                                                            */
            uint32_t               : 5;
            __IOM uint32_t LTHSLR  : 1; /*!< [8..8] LTHSLR                                                             */
            uint32_t               : 23;
        } FWLTHTRR1_b;
    };

    union
    {
        __IOM uint32_t FWLTHTRR2;        /*!< (@ 0x0000415C) Forwarding Engine L3 Table Read Result Register
                                          *                  2 (FWLTHTRR2)                                              */

        struct
        {
            __IOM uint32_t LTHSRP1 : 32; /*!< [31..0] LTHSRP1                                                           */
        } FWLTHTRR2_b;
    };

    union
    {
        __IOM uint32_t FWLTHTRR3;        /*!< (@ 0x00004160) Forwarding Engine L3 Table Read Result Register
                                          *                  3 (FWLTHTRR3)                                              */

        struct
        {
            __IOM uint32_t LTHSRP2 : 32; /*!< [31..0] LTHSRP2                                                           */
        } FWLTHTRR3_b;
    };

    union
    {
        __IOM uint32_t FWLTHTRR4;        /*!< (@ 0x00004164) Forwarding Engine L3 Table Read Result Register
                                          *                  4 (FWLTHTRR4)                                              */

        struct
        {
            __IOM uint32_t LTHSRP3 : 32; /*!< [31..0] LTHSRP3                                                           */
        } FWLTHTRR4_b;
    };

    union
    {
        __IOM uint32_t FWLTHTRR5;        /*!< (@ 0x00004168) Forwarding Engine L3 Table Read Result Register
                                          *                  5 (FWLTHTRR5)                                              */

        struct
        {
            __IOM uint32_t LTHSRP4 : 32; /*!< [31..0] LTHSRP4                                                           */
        } FWLTHTRR5_b;
    };

    union
    {
        __IOM uint32_t FWLTHTRR6;      /*!< (@ 0x0000416C) Forwarding Engine L3 Table Read Result Register
                                        *                  6 (FWLTHTRR6)                                              */

        struct
        {
            uint32_t                 : 16;
            __IOM uint32_t LTHMSDUNR : 4; /*!< [19..16] LTHMSDUNR                                                        */
            uint32_t                 : 11;
            __IOM uint32_t LTHMSDUVR : 1; /*!< [31..31] LTHMSDUVR                                                        */
        } FWLTHTRR6_b;
    };

    union
    {
        __IOM uint32_t FWLTHTRR7;         /*!< (@ 0x00004170) Forwarding Engine L3 Table Read Result Register
                                           *                  7 (FWLTHTRR7)                                              */

        struct
        {
            __IOM uint32_t LTHFRERNR : 7; /*!< [6..0] LTHFRERNR                                                          */
            uint32_t                 : 8;
            __IOM uint32_t LTHFRERVR : 1; /*!< [15..15] LTHFRERVR                                                        */
            __IOM uint32_t LTHMTRNR  : 5; /*!< [20..16] LTHMTRNR                                                         */
            uint32_t                 : 10;
            __IOM uint32_t LTHMTRVR  : 1; /*!< [31..31] LTHMTRVR                                                         */
        } FWLTHTRR7_b;
    };

    union
    {
        __IOM uint32_t FWLTHTRR8;       /*!< (@ 0x00004174) Forwarding Engine L3 Table Read Result Register
                                         *                  8 (FWLTHTRR8)                                              */

        struct
        {
            __IOM uint32_t LTHRNR  : 8; /*!< [7..0] LTHRNR                                                             */
            uint32_t               : 7;
            __IOM uint32_t LTHRVR  : 1; /*!< [15..15] LTHRVR                                                           */
            __IOM uint32_t LTHSLVR : 3; /*!< [18..16] LTHSLVR                                                          */
            uint32_t               : 13;
        } FWLTHTRR8_b;
    };
    __IM uint32_t RESERVED102[2];

    union
    {
        __IOM uint32_t FWLTHTRR90;      /*!< (@ 0x00004180) Forwarding Engine L3 Table Read Result Register
                                         *                  90 (FWLTHTRR90)                                            */

        struct
        {
            __IOM uint32_t LTHCSDR : 6; /*!< [5..0] LTHCSDR                                                            */
            uint32_t               : 26;
        } FWLTHTRR90_b;
    };
    __IM uint32_t RESERVED103[3];

    union
    {
        __IOM uint32_t FWLTHTRR10;      /*!< (@ 0x00004190) Forwarding Engine L3 Table Read Result Register
                                         *                  10 (FWLTHTRR10)                                            */

        struct
        {
            __IOM uint32_t LTHDVR  : 3; /*!< [2..0] LTHDVR                                                             */
            uint32_t               : 13;
            __IOM uint32_t LTHIPVR : 3; /*!< [18..16] LTHIPVR                                                          */
            __IOM uint32_t LTHIPUR : 1; /*!< [19..19] LTHIPUR                                                          */
            __IOM uint32_t LTHEMER : 1; /*!< [20..20] LTHEMER                                                          */
            __IOM uint32_t LTHCMER : 1; /*!< [21..21] LTHCMER                                                          */
            uint32_t               : 10;
        } FWLTHTRR10_b;
    };
    __IM uint32_t RESERVED104[291];

    union
    {
        __IOM uint32_t FWMACHEC;         /*!< (@ 0x00004620) Forwarding Engine MAC Hash Entry Configuration
                                          *                  Register (FWMACHEC)                                        */

        struct
        {
            __IOM uint32_t MACHMC  : 11; /*!< [10..0] MACHMC                                                            */
            uint32_t               : 5;
            __IOM uint32_t MACHMUE : 12; /*!< [27..16] MACHMUE                                                          */
            uint32_t               : 4;
        } FWMACHEC_b;
    };

    union
    {
        __IOM uint32_t FWMACHC;         /*!< (@ 0x00004624) Forwarding Engine MAC Hash Configuration Register
                                         *                  (FWMACHC)                                                  */

        struct
        {
            __IOM uint32_t MACHE0  : 1; /*!< [0..0] MACHE0                                                             */
            __IOM uint32_t MACHE1  : 1; /*!< [1..1] MACHE1                                                             */
            __IOM uint32_t MACHE2  : 1; /*!< [2..2] MACHE2                                                             */
            __IOM uint32_t MACHE3  : 1; /*!< [3..3] MACHE3                                                             */
            __IOM uint32_t MACHE4  : 1; /*!< [4..4] MACHE4                                                             */
            __IOM uint32_t MACHE5  : 1; /*!< [5..5] MACHE5                                                             */
            __IOM uint32_t MACHE6  : 1; /*!< [6..6] MACHE6                                                             */
            __IOM uint32_t MACHE7  : 1; /*!< [7..7] MACHE7                                                             */
            __IOM uint32_t MACHE8  : 1; /*!< [8..8] MACHE8                                                             */
            __IOM uint32_t MACHE9  : 1; /*!< [9..9] MACHE9                                                             */
            __IOM uint32_t MACHE10 : 1; /*!< [10..10] MACHE10                                                          */
            uint32_t               : 21;
        } FWMACHC_b;
    };
    __IM uint32_t RESERVED105[2];

    union
    {
        __IOM uint32_t FWMACTL0;       /*!< (@ 0x00004630) Forwarding Engine MAC Table Learn Register 0
                                        *                  (FWMACTL0)                                                 */

        struct
        {
            uint32_t               : 8;
            __IOM uint32_t MACSLL  : 1; /*!< [8..8] MACSLL                                                             */
            __IOM uint32_t MACDEL  : 1; /*!< [9..9] MACDEL                                                             */
            __IOM uint32_t MACHLDL : 1; /*!< [10..10] MACHLDL                                                          */
            uint32_t               : 5;
            __IOM uint32_t MACED   : 1; /*!< [16..16] MACED                                                            */
            uint32_t               : 15;
        } FWMACTL0_b;
    };

    union
    {
        __IOM uint32_t FWMACTL1;          /*!< (@ 0x00004634) Forwarding Engine MAC Table Learn Register 1
                                           *                  (FWMACTL1)                                                 */

        struct
        {
            __IOM uint32_t MACMALP0 : 16; /*!< [15..0] MACMALP0                                                          */
            uint32_t                : 16;
        } FWMACTL1_b;
    };

    union
    {
        __IOM uint32_t FWMACTL2;          /*!< (@ 0x00004638) Forwarding Engine MAC Table Learn Register 2
                                           *                  (FWMACTL2)                                                 */

        struct
        {
            __IOM uint32_t MACMALP1 : 32; /*!< [31..0] MACMALP1                                                          */
        } FWMACTL2_b;
    };

    union
    {
        __IOM uint32_t FWMACTL3;         /*!< (@ 0x0000463C) Forwarding Engine MAC Table Learn Register 3
                                          *                  (FWMACTL3)                                                 */

        struct
        {
            __IOM uint32_t MACSSLVL : 3; /*!< [2..0] MACSSLVL                                                           */
            uint32_t                : 13;
            __IOM uint32_t MACDSLVL : 3; /*!< [18..16] MACDSLVL                                                         */
            uint32_t                : 13;
        } FWMACTL3_b;
    };

    union
    {
        __IOM uint32_t FWMACTL40;       /*!< (@ 0x00004640) Forwarding Engine MAC Table Learn Register 40
                                         *                  (FWMACTL40)                                                */

        struct
        {
            __IOM uint32_t MACCSDL : 6; /*!< [5..0] MACCSDL                                                            */
            uint32_t               : 26;
        } FWMACTL40_b;
    };
    __IM uint32_t RESERVED106[3];

    union
    {
        __IOM uint32_t FWMACTL5;        /*!< (@ 0x00004650) Forwarding Engine MAC Table Learn Register 5
                                         *                  (FWMACTL5)                                                 */

        struct
        {
            __IOM uint32_t MACDVL  : 3; /*!< [2..0] MACDVL                                                             */
            uint32_t               : 13;
            __IOM uint32_t MACIPVL : 3; /*!< [18..16] MACIPVL                                                          */
            __IOM uint32_t MACIPUL : 1; /*!< [19..19] MACIPUL                                                          */
            __IOM uint32_t MACEMEL : 1; /*!< [20..20] MACEMEL                                                          */
            __IOM uint32_t MACCMEL : 1; /*!< [21..21] MACCMEL                                                          */
            uint32_t               : 10;
        } FWMACTL5_b;
    };

    union
    {
        __IOM uint32_t FWMACTLR;        /*!< (@ 0x00004654) Forwarding Engine MAC Table Learn Result Register
                                         *                  (FWMACTLR)                                                 */

        struct
        {
            __IOM uint32_t MACLF  : 1;  /*!< [0..0] MACLF                                                              */
            __IOM uint32_t MACLSF : 1;  /*!< [1..1] MACLSF                                                             */
            __IOM uint32_t MACLEF : 1;  /*!< [2..2] MACLEF                                                             */
            __IOM uint32_t MACLO  : 1;  /*!< [3..3] MACLO                                                              */
            uint32_t              : 12;
            __IOM uint32_t MACLCN : 11; /*!< [26..16] MACLCN                                                           */
            uint32_t              : 4;
            __IOM uint32_t MACTL  : 1;  /*!< [31..31] MACTL                                                            */
        } FWMACTLR_b;
    };
    __IM uint32_t RESERVED107[2];

    union
    {
        __IOM uint32_t FWMACTIM;        /*!< (@ 0x00004660) Forwarding Engine MAC Table Initialization Monitoring
                                         *                  Register (FWMACTIM)                                        */

        struct
        {
            __IOM uint32_t MACTIOG : 1; /*!< [0..0] MACTIOG                                                            */
            __IOM uint32_t MACTR   : 1; /*!< [1..1] MACTR                                                              */
            uint32_t               : 30;
        } FWMACTIM_b;
    };

    union
    {
        __IOM uint32_t FWMACTEM;         /*!< (@ 0x00004664) Forwarding Engine MAC Table Entry Monitoring
                                          *                  Register (FWMACTEM)                                        */

        struct
        {
            __IOM uint32_t MACTEN  : 12; /*!< [11..0] MACTEN                                                            */
            uint32_t               : 4;
            __IOM uint32_t MACTUEN : 12; /*!< [27..16] MACTUEN                                                          */
            uint32_t               : 4;
        } FWMACTEM_b;
    };
    __IM uint32_t RESERVED108[2];

    union
    {
        __IOM uint32_t FWMACTS0;          /*!< (@ 0x00004670) Forwarding Engine MAC Table Search Register 0
                                           *                  (FWMACTS0)                                                 */

        struct
        {
            __IOM uint32_t MACMASP0 : 16; /*!< [15..0] MACMASP0                                                          */
            uint32_t                : 16;
        } FWMACTS0_b;
    };

    union
    {
        __IOM uint32_t FWMACTS1;          /*!< (@ 0x00004674) Forwarding Engine MAC Table Search Register 1
                                           *                  (FWMACTS1)                                                 */

        struct
        {
            __IOM uint32_t MACMASP1 : 32; /*!< [31..0] MACMASP1                                                          */
        } FWMACTS1_b;
    };

    union
    {
        __IOM uint32_t FWMACTSR0;        /*!< (@ 0x00004678) Forwarding Engine MAC Table Search Result Register
                                          *                  0 (FWMACTSR0)                                              */

        struct
        {
            __IOM uint32_t MACSEF  : 1;  /*!< [0..0] MACSEF                                                             */
            __IOM uint32_t MACSNF  : 1;  /*!< [1..1] MACSNF                                                             */
            uint32_t               : 6;
            __IOM uint32_t MACSLS  : 1;  /*!< [8..8] MACSLS                                                             */
            __IOM uint32_t MACDES  : 1;  /*!< [9..9] MACDES                                                             */
            __IOM uint32_t MACHLDS : 1;  /*!< [10..10] MACHLDS                                                          */
            uint32_t               : 5;
            __IOM uint32_t MACSCN  : 11; /*!< [26..16] MACSCN                                                           */
            uint32_t               : 4;
            __IOM uint32_t MACTS   : 1;  /*!< [31..31] MACTS                                                            */
        } FWMACTSR0_b;
    };

    union
    {
        __IOM uint32_t FWMACTSR1;        /*!< (@ 0x0000467C) Forwarding Engine MAC Table Search Result Register
                                          *                  1 (FWMACTSR1)                                              */

        struct
        {
            __IOM uint32_t MACSSLVS : 3; /*!< [2..0] MACSSLVS                                                           */
            uint32_t                : 13;
            __IOM uint32_t MACDSLVS : 3; /*!< [18..16] MACDSLVS                                                         */
            uint32_t                : 13;
        } FWMACTSR1_b;
    };

    union
    {
        __IOM uint32_t FWMACTSR20;      /*!< (@ 0x00004680) Forwarding Engine MAC Table Search Result Register
                                         *                  20 (FWMACTSR20)                                            */

        struct
        {
            __IOM uint32_t MACCSDS : 6; /*!< [5..0] MACCSDS                                                            */
            uint32_t               : 26;
        } FWMACTSR20_b;
    };
    __IM uint32_t RESERVED109[3];

    union
    {
        __IOM uint32_t FWMACTSR3;       /*!< (@ 0x00004690) Forwarding Engine MAC Table Search Result Register
                                         *                  3 (FWMACTSR3)                                              */

        struct
        {
            __IOM uint32_t MACDVS  : 3; /*!< [2..0] MACDVS                                                             */
            uint32_t               : 13;
            __IOM uint32_t MACIPVS : 3; /*!< [18..16] MACIPVS                                                          */
            __IOM uint32_t MACIPUS : 1; /*!< [19..19] MACIPUS                                                          */
            __IOM uint32_t MACEMES : 1; /*!< [20..20] MACEMES                                                          */
            __IOM uint32_t MACCMES : 1; /*!< [21..21] MACCMES                                                          */
            uint32_t               : 10;
        } FWMACTSR3_b;
    };
    __IM uint32_t RESERVED110[3];

    union
    {
        __IOM uint32_t FWMACTR;        /*!< (@ 0x000046A0) Forwarding Engine MAC Table Read Register (FWMACTR)        */

        struct
        {
            __IOM uint32_t MACAR : 11; /*!< [10..0] MACAR                                                             */
            uint32_t             : 21;
        } FWMACTR_b;
    };

    union
    {
        __IOM uint32_t FWMACTRR0;      /*!< (@ 0x000046A4) Forwarding Engine MAC Table Read Result Register
                                        *                  0 (FWMACTRR0)                                              */

        struct
        {
            __IOM uint32_t MACEVR : 1; /*!< [0..0] MACEVR                                                             */
            __IOM uint32_t MACREF : 1; /*!< [1..1] MACREF                                                             */
            uint32_t              : 29;
            __IOM uint32_t MACTR  : 1; /*!< [31..31] MACTR                                                            */
        } FWMACTRR0_b;
    };

    union
    {
        __IOM uint32_t FWMACTRR1;      /*!< (@ 0x000046A8) Forwarding Engine MAC Table Read Result Register
                                        *                  1 (FWMACTRR1)                                              */

        struct
        {
            uint32_t               : 8;
            __IOM uint32_t MACSLR  : 1; /*!< [8..8] MACSLR                                                             */
            __IOM uint32_t MACDER  : 1; /*!< [9..9] MACDER                                                             */
            __IOM uint32_t MACHLDR : 1; /*!< [10..10] MACHLDR                                                          */
            __IOM uint32_t MACABR  : 1; /*!< [11..11] MACABR                                                           */
            uint32_t               : 20;
        } FWMACTRR1_b;
    };

    union
    {
        __IOM uint32_t FWMACTRR2;         /*!< (@ 0x000046AC) Forwarding Engine MAC Table Read Result Register
                                           *                  2 (FWMACTRR2)                                              */

        struct
        {
            __IOM uint32_t MACMARP0 : 16; /*!< [15..0] MACMARP0                                                          */
            uint32_t                : 16;
        } FWMACTRR2_b;
    };

    union
    {
        __IOM uint32_t FWMACTRR3;         /*!< (@ 0x000046B0) Forwarding Engine MAC Table Read Result Register
                                           *                  3 (FWMACTRR3)                                              */

        struct
        {
            __IOM uint32_t MACMARP1 : 32; /*!< [31..0] MACMARP1                                                          */
        } FWMACTRR3_b;
    };

    union
    {
        __IOM uint32_t FWMACTRR4;        /*!< (@ 0x000046B4) Forwarding Engine MAC Table Read Result Register
                                          *                  6 (FWMACTRR4)                                              */

        struct
        {
            __IOM uint32_t MACSSLVR : 3; /*!< [2..0] MACSSLVR                                                           */
            uint32_t                : 13;
            __IOM uint32_t MACDSLVR : 3; /*!< [18..16] MACDSLVR                                                         */
            uint32_t                : 13;
        } FWMACTRR4_b;
    };
    __IM uint32_t RESERVED111[2];

    union
    {
        __IOM uint32_t FWMACTRR50;      /*!< (@ 0x000046C0) Forwarding Engine MAC Table Read Result Register
                                         *                  50 (FWMACTRR50)                                            */

        struct
        {
            __IOM uint32_t MACCSDR : 6; /*!< [5..0] MACCSDR                                                            */
            uint32_t               : 26;
        } FWMACTRR50_b;
    };
    __IM uint32_t RESERVED112[3];

    union
    {
        __IOM uint32_t FWMACTRR6;       /*!< (@ 0x000046D0) Forwarding Engine MAC Table Read Result Register
                                         *                  6 (FWMACTRR6)                                              */

        struct
        {
            __IOM uint32_t MACDVR  : 3; /*!< [2..0] MACDVR                                                             */
            uint32_t               : 13;
            __IOM uint32_t MACIPVR : 3; /*!< [18..16] MACIPVR                                                          */
            __IOM uint32_t MACIPUR : 1; /*!< [19..19] MACIPUR                                                          */
            __IOM uint32_t MACEMER : 1; /*!< [20..20] MACEMER                                                          */
            __IOM uint32_t MACCMER : 1; /*!< [21..21] MACCMER                                                          */
            uint32_t               : 10;
        } FWMACTRR6_b;
    };
    __IM uint32_t RESERVED113[107];

    union
    {
        __IOM uint32_t FWMACAGUSPC;       /*!< (@ 0x00004880) Forwarding Engine MAC Aging US Prescaler Configuration
                                           *                  Register (FWMACAGUSPC)                                     */

        struct
        {
            __IOM uint32_t MACAGUSP : 10; /*!< [9..0] MACAGUSP                                                           */
            uint32_t                : 22;
        } FWMACAGUSPC_b;
    };

    union
    {
        __IOM uint32_t FWMACAGC;          /*!< (@ 0x00004884) Forwarding Engine MAC Aging Configuration Register
                                           *                  (FWMACAGC)                                                 */

        struct
        {
            __IOM uint32_t MACAGT   : 16; /*!< [15..0] MACAGT                                                            */
            __IOM uint32_t MACAGE   : 1;  /*!< [16..16] MACAGE                                                           */
            __IOM uint32_t MACAGSL  : 1;  /*!< [17..17] MACAGSL                                                          */
            __IOM uint32_t MACAGPM  : 1;  /*!< [18..18] MACAGPM                                                          */
            uint32_t                : 5;
            __IOM uint32_t MACDES   : 1;  /*!< [24..24] MACDES                                                           */
            uint32_t                : 3;
            __IOM uint32_t MACAGOG  : 1;  /*!< [28..28] MACAGOG                                                          */
            __IOM uint32_t MACDESOG : 1;  /*!< [29..29] MACDESOG                                                         */
            uint32_t                : 2;
        } FWMACAGC_b;
    };

    union
    {
        __IOM uint32_t FWMACAGM0;         /*!< (@ 0x00004888) Forwarding Engine MAC Aging Monitoring Register
                                           *                  0 (FWMACAGM0)                                              */

        struct
        {
            __IOM uint32_t AGMACAP0 : 16; /*!< [15..0] AGMACAP0                                                          */
            uint32_t                : 16;
        } FWMACAGM0_b;
    };

    union
    {
        __IOM uint32_t FWMACAGM1;         /*!< (@ 0x0000488C) Forwarding Engine MAC Aging Monitoring Register
                                           *                  1 (FWMACAGM1)                                              */

        struct
        {
            __IOM uint32_t AGMACAP1 : 32; /*!< [31..0] AGMACAP1                                                          */
        } FWMACAGM1_b;
    };
    __IM uint32_t RESERVED114[28];

    union
    {
        __IOM uint32_t FWVLANTEC;      /*!< (@ 0x00004900) Forwarding Engine VLAN Table Entry Configuration
                                        *                  Register (FWVLANTEC)                                       */

        struct
        {
            uint32_t                : 16;
            __IOM uint32_t VLANTMUE : 13; /*!< [28..16] VLANTMUE                                                         */
            uint32_t                : 3;
        } FWVLANTEC_b;
    };
    __IM uint32_t RESERVED115[3];

    union
    {
        __IOM uint32_t FWVLANTL0;      /*!< (@ 0x00004910) Forwarding Engine VLAN Table Learn Register 0
                                        *                  (FWVLANTL0)                                                */

        struct
        {
            uint32_t                : 8;
            __IOM uint32_t VLANSLL  : 1; /*!< [8..8] VLANSLL                                                            */
            uint32_t                : 1;
            __IOM uint32_t VLANHLDL : 1; /*!< [10..10] VLANHLDL                                                         */
            uint32_t                : 5;
            __IOM uint32_t VLANED   : 1; /*!< [16..16] VLANED                                                           */
            uint32_t                : 15;
        } FWVLANTL0_b;
    };

    union
    {
        __IOM uint32_t FWVLANTL1;         /*!< (@ 0x00004914) Forwarding Engine VLAN Table Learn Register 1
                                           *                  (FWVLANTL1)                                                */

        struct
        {
            __IOM uint32_t VLANVIDL : 12; /*!< [11..0] VLANVIDL                                                          */
            uint32_t                : 20;
        } FWVLANTL1_b;
    };

    union
    {
        __IOM uint32_t FWVLANTL2;        /*!< (@ 0x00004918) Forwarding Engine VLAN Table Learn Register 2
                                          *                  (FWVLANTL2)                                                */

        struct
        {
            __IOM uint32_t VLANSLVL : 3; /*!< [2..0] VLANSLVL                                                           */
            uint32_t                : 29;
        } FWVLANTL2_b;
    };
    __IM uint32_t RESERVED116;

    union
    {
        __IOM uint32_t FWVLANTL30;       /*!< (@ 0x00004920) Forwarding Engine VLAN Table Learn Register 30
                                          *                  (FWVLANTL30)                                               */

        struct
        {
            __IOM uint32_t VLANCSDL : 6; /*!< [5..0] VLANCSDL                                                           */
            uint32_t                : 26;
        } FWVLANTL30_b;
    };
    __IM uint32_t RESERVED117[3];

    union
    {
        __IOM uint32_t FWVLANTL4;        /*!< (@ 0x00004930) Forwarding Engine VLAN Table Learn Register 4
                                          *                  (FWVLANTL4)                                                */

        struct
        {
            __IOM uint32_t VLANDVL  : 3; /*!< [2..0] VLANDVL                                                            */
            uint32_t                : 13;
            __IOM uint32_t VLANIPVL : 3; /*!< [18..16] VLANIPVL                                                         */
            __IOM uint32_t VLANIPUL : 1; /*!< [19..19] VLANIPUL                                                         */
            __IOM uint32_t VLANEMEL : 1; /*!< [20..20] VLANEMEL                                                         */
            __IOM uint32_t VLANCMEL : 1; /*!< [21..21] VLANCMEL                                                         */
            uint32_t                : 10;
        } FWVLANTL4_b;
    };

    union
    {
        __IOM uint32_t FWVLANTLR;       /*!< (@ 0x00004934) Forwarding Engine VLAN Table Learn Result Register
                                         *                  (FWVLANTLR)                                                */

        struct
        {
            __IOM uint32_t VLANLF  : 1; /*!< [0..0] VLANLF                                                             */
            __IOM uint32_t VLANLSF : 1; /*!< [1..1] VLANLSF                                                            */
            __IOM uint32_t VLANLEF : 1; /*!< [2..2] VLANLEF                                                            */
            __IOM uint32_t VLANLO  : 1; /*!< [3..3] VLANLO                                                             */
            uint32_t               : 27;
            __IOM uint32_t VLANTL  : 1; /*!< [31..31] VLANTL                                                           */
        } FWVLANTLR_b;
    };
    __IM uint32_t RESERVED118[2];

    union
    {
        __IOM uint32_t FWVLANTIM;        /*!< (@ 0x00004940) Forwarding Engine VLAN Table Initialization Monitoring
                                          *                  Register (FWVLANTIM)                                       */

        struct
        {
            __IOM uint32_t VLANTIOG : 1; /*!< [0..0] VLANTIOG                                                           */
            __IOM uint32_t VLANTR   : 1; /*!< [1..1] VLANTR                                                             */
            uint32_t                : 30;
        } FWVLANTIM_b;
    };

    union
    {
        __IOM uint32_t FWVLANTEM;         /*!< (@ 0x00004944) Forwarding Engine VLAN Table Entry Monitoring
                                           *                  Register (FWVLANTEM)                                       */

        struct
        {
            __IOM uint32_t VLANTEN  : 13; /*!< [12..0] VLANTEN                                                           */
            uint32_t                : 3;
            __IOM uint32_t VLANTUEN : 13; /*!< [28..16] VLANTUEN                                                         */
            uint32_t                : 3;
        } FWVLANTEM_b;
    };
    __IM uint32_t RESERVED119[2];

    union
    {
        __IOM uint32_t FWVLANTS;          /*!< (@ 0x00004950) Forwarding Engine VLAN Table Search Register
                                           *                  (FWVLANTS)                                                 */

        struct
        {
            __IOM uint32_t VLANVIDS : 12; /*!< [11..0] VLANVIDS                                                          */
            uint32_t                : 20;
        } FWVLANTS_b;
    };

    union
    {
        __IOM uint32_t FWVLANTSR0;       /*!< (@ 0x00004954) Forwarding Engine VLAN Table Search Result Register
                                          *                  0 (FWVLANTSR0)                                             */

        struct
        {
            __IOM uint32_t VLANSEF  : 1; /*!< [0..0] VLANSEF                                                            */
            __IOM uint32_t VLANSNF  : 1; /*!< [1..1] VLANSNF                                                            */
            uint32_t                : 6;
            __IOM uint32_t VLANSLS  : 1; /*!< [8..8] VLANSLS                                                            */
            uint32_t                : 1;
            __IOM uint32_t VLANHLDS : 1; /*!< [10..10] VLANHLDS                                                         */
            uint32_t                : 20;
            __IOM uint32_t VLANTS   : 1; /*!< [31..31] VLANTS                                                           */
        } FWVLANTSR0_b;
    };

    union
    {
        __IOM uint32_t FWVLANTSR1;       /*!< (@ 0x00004958) Forwarding Engine VLAN Table Search Result Register
                                          *                  1 (FWVLANTSR1)                                             */

        struct
        {
            __IOM uint32_t VLANSLVS : 3; /*!< [2..0] VLANSLVS                                                           */
            uint32_t                : 29;
        } FWVLANTSR1_b;
    };
    __IM uint32_t RESERVED120;

    union
    {
        __IOM uint32_t FWVLANTSR20;      /*!< (@ 0x00004960) Forwarding Engine VLAN Table Search Result Register
                                          *                  20 (FWVLANTSR20)                                           */

        struct
        {
            __IOM uint32_t VLANCSDS : 6; /*!< [5..0] VLANCSDS                                                           */
            uint32_t                : 26;
        } FWVLANTSR20_b;
    };
    __IM uint32_t RESERVED121[3];

    union
    {
        __IOM uint32_t FWVLANTSR3;       /*!< (@ 0x00004970) Forwarding Engine VLAN Table Search Result Register
                                          *                  3 (FWVLANTSR3)                                             */

        struct
        {
            __IOM uint32_t VLANDVS  : 3; /*!< [2..0] VLANDVS                                                            */
            uint32_t                : 13;
            __IOM uint32_t VLANIPVS : 3; /*!< [18..16] VLANIPVS                                                         */
            __IOM uint32_t VLANIPUS : 1; /*!< [19..19] VLANIPUS                                                         */
            __IOM uint32_t VLANEMES : 1; /*!< [20..20] VLANEMES                                                         */
            __IOM uint32_t VLANCMES : 1; /*!< [21..21] VLANCMES                                                         */
            uint32_t                : 10;
        } FWVLANTSR3_b;
    };
    __IM uint32_t RESERVED122[35];

    union
    {
        __IOM uint32_t FWPBFC0;        /*!< (@ 0x00004A00) Forwarding Engine Port Based Forwarding Configuration
                                        *                  Register i (FWPBFCi) (i = 0 to 2)                          */

        struct
        {
            __IOM uint32_t PBDV   : 3; /*!< [2..0] PBDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t PBIPV  : 3; /*!< [18..16] PBIPV                                                            */
            __IOM uint32_t PBIPU  : 1; /*!< [19..19] PBIPU                                                            */
            __IOM uint32_t PBEME  : 1; /*!< [20..20] PBEME                                                            */
            __IOM uint32_t PBCME  : 1; /*!< [21..21] PBCME                                                            */
            __IOM uint32_t PBSL   : 1; /*!< [22..22] PBSL                                                             */
            __IOM uint32_t IP4PDE : 1; /*!< [23..23] IP4PDE                                                           */
            __IOM uint32_t IP4PDM : 1; /*!< [24..24] IP4PDM                                                           */
            __IOM uint32_t IP6PDE : 1; /*!< [25..25] IP6PDE                                                           */
            __IOM uint32_t FAIFP  : 1; /*!< [26..26] FAIFP                                                            */
            uint32_t              : 5;
        } FWPBFC0_b;
    };

    union
    {
        __IOM uint32_t FWPBFCSDC00;    /*!< (@ 0x00004A04) Forwarding Engine Port Based Forwarding CSD Configuration
                                        *                  Register 0i (FWPBFCSDC0i) (i = 0 to 2)                     */

        struct
        {
            __IOM uint32_t PBCSD : 6;  /*!< [5..0] PBCSD                                                              */
            uint32_t             : 26;
        } FWPBFCSDC00_b;
    };
    __IM uint32_t RESERVED123[2];

    union
    {
        __IOM uint32_t FWPBFC1;        /*!< (@ 0x00004A10) Forwarding Engine Port Based Forwarding Configuration
                                        *                  Register i (FWPBFCi) (i = 0 to 2)                          */

        struct
        {
            __IOM uint32_t PBDV   : 3; /*!< [2..0] PBDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t PBIPV  : 3; /*!< [18..16] PBIPV                                                            */
            __IOM uint32_t PBIPU  : 1; /*!< [19..19] PBIPU                                                            */
            __IOM uint32_t PBEME  : 1; /*!< [20..20] PBEME                                                            */
            __IOM uint32_t PBCME  : 1; /*!< [21..21] PBCME                                                            */
            __IOM uint32_t PBSL   : 1; /*!< [22..22] PBSL                                                             */
            __IOM uint32_t IP4PDE : 1; /*!< [23..23] IP4PDE                                                           */
            __IOM uint32_t IP4PDM : 1; /*!< [24..24] IP4PDM                                                           */
            __IOM uint32_t IP6PDE : 1; /*!< [25..25] IP6PDE                                                           */
            __IOM uint32_t FAIFP  : 1; /*!< [26..26] FAIFP                                                            */
            uint32_t              : 5;
        } FWPBFC1_b;
    };

    union
    {
        __IOM uint32_t FWPBFCSDC10;    /*!< (@ 0x00004A14) Forwarding Engine Port Based Forwarding CSD Configuration
                                        *                  Register 0i (FWPBFCSDC0i) (i = 0 to 2)                     */

        struct
        {
            __IOM uint32_t PBCSD : 6;  /*!< [5..0] PBCSD                                                              */
            uint32_t             : 26;
        } FWPBFCSDC10_b;
    };
    __IM uint32_t RESERVED124[2];

    union
    {
        __IOM uint32_t FWPBFC2;        /*!< (@ 0x00004A20) Forwarding Engine Port Based Forwarding Configuration
                                        *                  Register i (FWPBFCi) (i = 0 to 2)                          */

        struct
        {
            __IOM uint32_t PBDV   : 3; /*!< [2..0] PBDV                                                               */
            uint32_t              : 13;
            __IOM uint32_t PBIPV  : 3; /*!< [18..16] PBIPV                                                            */
            __IOM uint32_t PBIPU  : 1; /*!< [19..19] PBIPU                                                            */
            __IOM uint32_t PBEME  : 1; /*!< [20..20] PBEME                                                            */
            __IOM uint32_t PBCME  : 1; /*!< [21..21] PBCME                                                            */
            __IOM uint32_t PBSL   : 1; /*!< [22..22] PBSL                                                             */
            __IOM uint32_t IP4PDE : 1; /*!< [23..23] IP4PDE                                                           */
            __IOM uint32_t IP4PDM : 1; /*!< [24..24] IP4PDM                                                           */
            __IOM uint32_t IP6PDE : 1; /*!< [25..25] IP6PDE                                                           */
            __IOM uint32_t FAIFP  : 1; /*!< [26..26] FAIFP                                                            */
            uint32_t              : 5;
        } FWPBFC2_b;
    };

    union
    {
        __IOM uint32_t FWPBFCSDC20;    /*!< (@ 0x00004A24) Forwarding Engine Port Based Forwarding CSD Configuration
                                        *                  Register 0i (FWPBFCSDC0i) (i = 0 to 2)                     */

        struct
        {
            __IOM uint32_t PBCSD : 6;  /*!< [5..0] PBCSD                                                              */
            uint32_t             : 26;
        } FWPBFCSDC20_b;
    };
    __IM uint32_t RESERVED125[246];

    union
    {
        __IOM uint32_t FWL23URL0;        /*!< (@ 0x00004E00) Forwarding Engine Layer2/Layer3 Update Rule Learn
                                          *                  Register 0 (FWL23URL0)                                     */

        struct
        {
            __IOM uint32_t L23URNL  : 8; /*!< [7..0] L23URNL                                                            */
            uint32_t                : 8;
            __IOM uint32_t L23URPVL : 3; /*!< [18..16] L23URPVL                                                         */
            uint32_t                : 13;
        } FWL23URL0_b;
    };

    union
    {
        __IOM uint32_t FWL23URL1;           /*!< (@ 0x00004E04) Forwarding Engine Layer2/Layer3 Update Rule Learn
                                             *                  Register 1 (FWL23URL1)                                     */

        struct
        {
            __IOM uint32_t L23UMDALP0 : 16; /*!< [15..0] L23UMDALP0                                                        */
            __IOM uint32_t L23UTTLUL  : 1;  /*!< [16..16] L23UTTLUL                                                        */
            __IOM uint32_t L23UMDAUL  : 1;  /*!< [17..17] L23UMDAUL                                                        */
            __IOM uint32_t L23UMSAUL  : 1;  /*!< [18..18] L23UMSAUL                                                        */
            __IOM uint32_t L23UCVIDUL : 1;  /*!< [19..19] L23UCVIDUL                                                       */
            __IOM uint32_t L23UCPCPUL : 1;  /*!< [20..20] L23UCPCPUL                                                       */
            __IOM uint32_t L23UCDEIUL : 1;  /*!< [21..21] L23UCDEIUL                                                       */
            __IOM uint32_t L23USVIDUL : 1;  /*!< [22..22] L23USVIDUL                                                       */
            __IOM uint32_t L23USPCPUL : 1;  /*!< [23..23] L23USPCPUL                                                       */
            __IOM uint32_t L23USDEIUL : 1;  /*!< [24..24] L23USDEIUL                                                       */
            __IOM uint32_t L23URTUL   : 2;  /*!< [26..25] L23URTUL                                                         */
            uint32_t                  : 5;
        } FWL23URL1_b;
    };

    union
    {
        __IOM uint32_t FWL23URL2;           /*!< (@ 0x00004E08) Forwarding Engine Layer2/Layer3 Update Rule Learn
                                             *                  Register 2 (FWL23URL2)                                     */

        struct
        {
            __IOM uint32_t L23UMDALP1 : 32; /*!< [31..0] L23UMDALP1                                                        */
        } FWL23URL2_b;
    };

    union
    {
        __IOM uint32_t FWL23URL3;          /*!< (@ 0x00004E0C) Forwarding Engine Layer2/Layer3 Update Rule Learn
                                            *                  Register 3 (FWL23URL3)                                     */

        struct
        {
            __IOM uint32_t L23UCVIDL : 12; /*!< [11..0] L23UCVIDL                                                         */
            __IOM uint32_t L23UCPCPL : 3;  /*!< [14..12] L23UCPCPL                                                        */
            __IOM uint32_t L23UCDEIL : 1;  /*!< [15..15] L23UCDEIL                                                        */
            __IOM uint32_t L23USVIDL : 12; /*!< [27..16] L23USVIDL                                                        */
            __IOM uint32_t L23USPCPL : 3;  /*!< [30..28] L23USPCPL                                                        */
            __IOM uint32_t L23USDEIL : 1;  /*!< [31..31] L23USDEIL                                                        */
        } FWL23URL3_b;
    };

    union
    {
        __IOM uint32_t FWL23URLR;      /*!< (@ 0x00004E10) Forwarding Engine Layer2/Layer3 Update Rule Learn
                                        *                  Result Register (FWL23URLR)                                */

        struct
        {
            __IOM uint32_t L23ULF : 1; /*!< [0..0] L23ULF                                                             */
            uint32_t              : 30;
            __IOM uint32_t L23URL : 1; /*!< [31..31] L23URL                                                           */
        } FWL23URLR_b;
    };
    __IM uint32_t RESERVED126[3];

    union
    {
        __IOM uint32_t FWL23UTIM;        /*!< (@ 0x00004E20) Forwarding Engine Layer2/Layer3 Update Table
                                          *                  Initialization Monitoring Register (FWL23UTIM)             */

        struct
        {
            __IOM uint32_t L23UTIOG : 1; /*!< [0..0] L23UTIOG                                                           */
            __IOM uint32_t L23UTR   : 1; /*!< [1..1] L23UTR                                                             */
            uint32_t                : 30;
        } FWL23UTIM_b;
    };
    __IM uint32_t RESERVED127[3];

    union
    {
        __IOM uint32_t FWL23URR;       /*!< (@ 0x00004E30) Forwarding Engine Layer2/Layer3 Update Rule Read
                                        *                  Register (FWL23URR)                                        */

        struct
        {
            __IOM uint32_t L23RNR : 8; /*!< [7..0] L23RNR                                                             */
            uint32_t              : 24;
        } FWL23URR_b;
    };

    union
    {
        __IOM uint32_t FWL23URRR0;       /*!< (@ 0x00004E34) Forwarding Engine Layer2/Layer3 Update Rule Read
                                          *                  Result Register 0 (FWL23URRR0)                             */

        struct
        {
            __IOM uint32_t L23URPVR : 3; /*!< [2..0] L23URPVR                                                           */
            uint32_t                : 13;
            __IOM uint32_t L23UREF  : 1; /*!< [16..16] L23UREF                                                          */
            uint32_t                : 14;
            __IOM uint32_t L23URR   : 1; /*!< [31..31] L23URR                                                           */
        } FWL23URRR0_b;
    };

    union
    {
        __IOM uint32_t FWL23URRR1;          /*!< (@ 0x00004E38) Forwarding Engine Layer2/Layer3 Update Rule Read
                                             *                  Result Register 1 (FWL23URRR1)                             */

        struct
        {
            __IOM uint32_t L23UMDARP0 : 16; /*!< [15..0] L23UMDARP0                                                        */
            __IOM uint32_t L23UTTLUR  : 1;  /*!< [16..16] L23UTTLUR                                                        */
            __IOM uint32_t L23UMDAUR  : 1;  /*!< [17..17] L23UMDAUR                                                        */
            __IOM uint32_t L23UMSAUR  : 1;  /*!< [18..18] L23UMSAUR                                                        */
            __IOM uint32_t L23UCVIDUR : 1;  /*!< [19..19] L23UCVIDUR                                                       */
            __IOM uint32_t L23UCPCPUR : 1;  /*!< [20..20] L23UCPCPUR                                                       */
            __IOM uint32_t L23UCDEIUR : 1;  /*!< [21..21] L23UCDEIUR                                                       */
            __IOM uint32_t L23USVIDUR : 1;  /*!< [22..22] L23USVIDUR                                                       */
            __IOM uint32_t L23USPCPUR : 1;  /*!< [23..23] L23USPCPUR                                                       */
            __IOM uint32_t L23USDEIUR : 1;  /*!< [24..24] L23USDEIUR                                                       */
            __IOM uint32_t L23URTUR   : 2;  /*!< [26..25] L23URTUR                                                         */
            uint32_t                  : 5;
        } FWL23URRR1_b;
    };

    union
    {
        __IOM uint32_t FWL23URRR2;          /*!< (@ 0x00004E3C) Forwarding Engine Layer2/Layer3 Update Rule Read
                                             *                  Result Register 2 (FWL23URRR2)                             */

        struct
        {
            __IOM uint32_t L23UMDARP1 : 32; /*!< [31..0] L23UMDARP1                                                        */
        } FWL23URRR2_b;
    };

    union
    {
        __IOM uint32_t FWL23URRR3;         /*!< (@ 0x00004E40) Forwarding Engine Layer2/Layer3 Update Rule Read
                                            *                  Result Register 3 (FWL23URRR3)                             */

        struct
        {
            __IOM uint32_t L23UCVIDR : 12; /*!< [11..0] L23UCVIDR                                                         */
            __IOM uint32_t L23UCPCPR : 3;  /*!< [14..12] L23UCPCPR                                                        */
            __IOM uint32_t L23UCDEIR : 1;  /*!< [15..15] L23UCDEIR                                                        */
            __IOM uint32_t L23USVIDR : 12; /*!< [27..16] L23USVIDR                                                        */
            __IOM uint32_t L23USPCPR : 3;  /*!< [30..28] L23USPCPR                                                        */
            __IOM uint32_t L23USDEIR : 1;  /*!< [31..31] L23USDEIR                                                        */
        } FWL23URRR3_b;
    };
    __IM uint32_t RESERVED128[47];

    union
    {
        __IOM uint32_t FWL23URMC0;     /*!< (@ 0x00004F00) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC0_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC1;     /*!< (@ 0x00004F04) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC1_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC2;     /*!< (@ 0x00004F08) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC2_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC3;     /*!< (@ 0x00004F0C) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC3_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC4;     /*!< (@ 0x00004F10) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC4_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC5;     /*!< (@ 0x00004F14) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC5_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC6;     /*!< (@ 0x00004F18) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC6_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC7;     /*!< (@ 0x00004F1C) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC7_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC8;     /*!< (@ 0x00004F20) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC8_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC9;     /*!< (@ 0x00004F24) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC9_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC10;    /*!< (@ 0x00004F28) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC10_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC11;    /*!< (@ 0x00004F2C) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC11_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC12;    /*!< (@ 0x00004F30) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC12_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC13;    /*!< (@ 0x00004F34) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC13_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC14;    /*!< (@ 0x00004F38) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC14_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC15;    /*!< (@ 0x00004F3C) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC15_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC16;    /*!< (@ 0x00004F40) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC16_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC17;    /*!< (@ 0x00004F44) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC17_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC18;    /*!< (@ 0x00004F48) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC18_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC19;    /*!< (@ 0x00004F4C) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC19_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC20;    /*!< (@ 0x00004F50) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC20_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC21;    /*!< (@ 0x00004F54) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC21_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC22;    /*!< (@ 0x00004F58) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC22_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC23;    /*!< (@ 0x00004F5C) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC23_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC24;    /*!< (@ 0x00004F60) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC24_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC25;    /*!< (@ 0x00004F64) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC25_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC26;    /*!< (@ 0x00004F68) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC26_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC27;    /*!< (@ 0x00004F6C) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC27_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC28;    /*!< (@ 0x00004F70) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC28_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC29;    /*!< (@ 0x00004F74) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC29_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC30;    /*!< (@ 0x00004F78) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC30_b;
    };

    union
    {
        __IOM uint32_t FWL23URMC31;    /*!< (@ 0x00004F7C) Forwarding Engine Layer2/Layer3 Update Remapping
                                        *                  Configuration Register i (FWL23URMCi) (i
                                        *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t RMRN  : 8;  /*!< [7..0] RMRN                                                               */
            uint32_t             : 4;
            __IOM uint32_t RMDPN : 2;  /*!< [13..12] RMDPN                                                            */
            uint32_t             : 2;
            __IOM uint32_t RMNRN : 8;  /*!< [23..16] RMNRN                                                            */
            uint32_t             : 4;
            __IOM uint32_t RME   : 1;  /*!< [28..28] RME                                                              */
            uint32_t             : 3;
        } FWL23URMC31_b;
    };
    __IM uint32_t RESERVED129[32];

    union
    {
        __IOM uint32_t FWPMFGC0;       /*!< (@ 0x00005000) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC0_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC1;       /*!< (@ 0x00005004) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC1_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC2;       /*!< (@ 0x00005008) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC2_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC3;       /*!< (@ 0x0000500C) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC3_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC4;       /*!< (@ 0x00005010) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC4_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC5;       /*!< (@ 0x00005014) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC5_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC6;       /*!< (@ 0x00005018) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC6_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC7;       /*!< (@ 0x0000501C) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC7_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC8;       /*!< (@ 0x00005020) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC8_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC9;       /*!< (@ 0x00005024) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC9_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC10;      /*!< (@ 0x00005028) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC10_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC11;      /*!< (@ 0x0000502C) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC11_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC12;      /*!< (@ 0x00005030) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC12_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC13;      /*!< (@ 0x00005034) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC13_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC14;      /*!< (@ 0x00005038) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC14_b;
    };

    union
    {
        __IOM uint32_t FWPMFGC15;      /*!< (@ 0x0000503C) Forwarding Engine PSFP MSDU Filter Global Configuration
                                        *                  Register i (FWPMFGCi) (i = 0 to 15)                        */

        struct
        {
            __IOM uint32_t MSDUV : 16; /*!< [15..0] MSDUV                                                             */
            uint32_t             : 15;
            __IOM uint32_t MFM   : 1;  /*!< [31..31] MFM                                                              */
        } FWPMFGC15_b;
    };
    __IM uint32_t RESERVED130[368];

    union
    {
        __IOM uint32_t FWPMTRFC0;       /*!< (@ 0x00005600) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC0_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC0;    /*!< (@ 0x00005604) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC0_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC0;    /*!< (@ 0x00005608) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC0_b;
    };

    union
    {
        __IOM uint32_t FWPMTREBSC0;    /*!< (@ 0x0000560C) Forwarding Engine PSFP Meter EBS Configuration
                                        *                  Register i (FWPMTREBSCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EBS : 18;   /*!< [17..0] EBS                                                               */
            uint32_t           : 14;
        } FWPMTREBSC0_b;
    };

    union
    {
        __IOM uint32_t FWPMTREIRC0;    /*!< (@ 0x00005610) Forwarding Engine PSFP Meter EIR Configuration
                                        *                  Register i (FWPMTREIRCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EIR : 20;   /*!< [19..0] EIR                                                               */
            uint32_t           : 12;
        } FWPMTREIRC0_b;
    };

    union
    {
        __IOM uint32_t FWPMTRFM0;         /*!< (@ 0x00005614) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM0_b;
    };
    __IM uint32_t RESERVED131[2];

    union
    {
        __IOM uint32_t FWPMTRFC1;       /*!< (@ 0x00005620) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC1_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC1;    /*!< (@ 0x00005624) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC1_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC1;    /*!< (@ 0x00005628) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC1_b;
    };

    union
    {
        __IOM uint32_t FWPMTREBSC1;    /*!< (@ 0x0000562C) Forwarding Engine PSFP Meter EBS Configuration
                                        *                  Register i (FWPMTREBSCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EBS : 18;   /*!< [17..0] EBS                                                               */
            uint32_t           : 14;
        } FWPMTREBSC1_b;
    };

    union
    {
        __IOM uint32_t FWPMTREIRC1;    /*!< (@ 0x00005630) Forwarding Engine PSFP Meter EIR Configuration
                                        *                  Register i (FWPMTREIRCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EIR : 20;   /*!< [19..0] EIR                                                               */
            uint32_t           : 12;
        } FWPMTREIRC1_b;
    };

    union
    {
        __IOM uint32_t FWPMTRFM1;         /*!< (@ 0x00005634) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM1_b;
    };
    __IM uint32_t RESERVED132[2];

    union
    {
        __IOM uint32_t FWPMTRFC2;       /*!< (@ 0x00005640) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC2_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC2;    /*!< (@ 0x00005644) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC2_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC2;    /*!< (@ 0x00005648) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC2_b;
    };

    union
    {
        __IOM uint32_t FWPMTREBSC2;    /*!< (@ 0x0000564C) Forwarding Engine PSFP Meter EBS Configuration
                                        *                  Register i (FWPMTREBSCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EBS : 18;   /*!< [17..0] EBS                                                               */
            uint32_t           : 14;
        } FWPMTREBSC2_b;
    };

    union
    {
        __IOM uint32_t FWPMTREIRC2;    /*!< (@ 0x00005650) Forwarding Engine PSFP Meter EIR Configuration
                                        *                  Register i (FWPMTREIRCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EIR : 20;   /*!< [19..0] EIR                                                               */
            uint32_t           : 12;
        } FWPMTREIRC2_b;
    };

    union
    {
        __IOM uint32_t FWPMTRFM2;         /*!< (@ 0x00005654) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM2_b;
    };
    __IM uint32_t RESERVED133[2];

    union
    {
        __IOM uint32_t FWPMTRFC3;       /*!< (@ 0x00005660) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC3_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC3;    /*!< (@ 0x00005664) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC3_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC3;    /*!< (@ 0x00005668) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC3_b;
    };

    union
    {
        __IOM uint32_t FWPMTREBSC3;    /*!< (@ 0x0000566C) Forwarding Engine PSFP Meter EBS Configuration
                                        *                  Register i (FWPMTREBSCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EBS : 18;   /*!< [17..0] EBS                                                               */
            uint32_t           : 14;
        } FWPMTREBSC3_b;
    };

    union
    {
        __IOM uint32_t FWPMTREIRC3;    /*!< (@ 0x00005670) Forwarding Engine PSFP Meter EIR Configuration
                                        *                  Register i (FWPMTREIRCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EIR : 20;   /*!< [19..0] EIR                                                               */
            uint32_t           : 12;
        } FWPMTREIRC3_b;
    };

    union
    {
        __IOM uint32_t FWPMTRFM3;         /*!< (@ 0x00005674) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM3_b;
    };
    __IM uint32_t RESERVED134[2];

    union
    {
        __IOM uint32_t FWPMTRFC4;       /*!< (@ 0x00005680) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC4_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC4;    /*!< (@ 0x00005684) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC4_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC4;    /*!< (@ 0x00005688) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC4_b;
    };

    union
    {
        __IOM uint32_t FWPMTREBSC4;    /*!< (@ 0x0000568C) Forwarding Engine PSFP Meter EBS Configuration
                                        *                  Register i (FWPMTREBSCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EBS : 18;   /*!< [17..0] EBS                                                               */
            uint32_t           : 14;
        } FWPMTREBSC4_b;
    };

    union
    {
        __IOM uint32_t FWPMTREIRC4;    /*!< (@ 0x00005690) Forwarding Engine PSFP Meter EIR Configuration
                                        *                  Register i (FWPMTREIRCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EIR : 20;   /*!< [19..0] EIR                                                               */
            uint32_t           : 12;
        } FWPMTREIRC4_b;
    };

    union
    {
        __IOM uint32_t FWPMTRFM4;         /*!< (@ 0x00005694) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM4_b;
    };
    __IM uint32_t RESERVED135[2];

    union
    {
        __IOM uint32_t FWPMTRFC5;       /*!< (@ 0x000056A0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC5_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC5;    /*!< (@ 0x000056A4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC5_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC5;    /*!< (@ 0x000056A8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC5_b;
    };

    union
    {
        __IOM uint32_t FWPMTREBSC5;    /*!< (@ 0x000056AC) Forwarding Engine PSFP Meter EBS Configuration
                                        *                  Register i (FWPMTREBSCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EBS : 18;   /*!< [17..0] EBS                                                               */
            uint32_t           : 14;
        } FWPMTREBSC5_b;
    };

    union
    {
        __IOM uint32_t FWPMTREIRC5;    /*!< (@ 0x000056B0) Forwarding Engine PSFP Meter EIR Configuration
                                        *                  Register i (FWPMTREIRCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EIR : 20;   /*!< [19..0] EIR                                                               */
            uint32_t           : 12;
        } FWPMTREIRC5_b;
    };

    union
    {
        __IOM uint32_t FWPMTRFM5;         /*!< (@ 0x000056B4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM5_b;
    };
    __IM uint32_t RESERVED136[2];

    union
    {
        __IOM uint32_t FWPMTRFC6;       /*!< (@ 0x000056C0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC6_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC6;    /*!< (@ 0x000056C4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC6_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC6;    /*!< (@ 0x000056C8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC6_b;
    };

    union
    {
        __IOM uint32_t FWPMTREBSC6;    /*!< (@ 0x000056CC) Forwarding Engine PSFP Meter EBS Configuration
                                        *                  Register i (FWPMTREBSCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EBS : 18;   /*!< [17..0] EBS                                                               */
            uint32_t           : 14;
        } FWPMTREBSC6_b;
    };

    union
    {
        __IOM uint32_t FWPMTREIRC6;    /*!< (@ 0x000056D0) Forwarding Engine PSFP Meter EIR Configuration
                                        *                  Register i (FWPMTREIRCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EIR : 20;   /*!< [19..0] EIR                                                               */
            uint32_t           : 12;
        } FWPMTREIRC6_b;
    };

    union
    {
        __IOM uint32_t FWPMTRFM6;         /*!< (@ 0x000056D4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM6_b;
    };
    __IM uint32_t RESERVED137[2];

    union
    {
        __IOM uint32_t FWPMTRFC7;       /*!< (@ 0x000056E0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC7_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC7;    /*!< (@ 0x000056E4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC7_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC7;    /*!< (@ 0x000056E8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC7_b;
    };

    union
    {
        __IOM uint32_t FWPMTREBSC7;    /*!< (@ 0x000056EC) Forwarding Engine PSFP Meter EBS Configuration
                                        *                  Register i (FWPMTREBSCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EBS : 18;   /*!< [17..0] EBS                                                               */
            uint32_t           : 14;
        } FWPMTREBSC7_b;
    };

    union
    {
        __IOM uint32_t FWPMTREIRC7;    /*!< (@ 0x000056F0) Forwarding Engine PSFP Meter EIR Configuration
                                        *                  Register i (FWPMTREIRCi) (i = 0 to 7)                      */

        struct
        {
            __IOM uint32_t EIR : 20;   /*!< [19..0] EIR                                                               */
            uint32_t           : 12;
        } FWPMTREIRC7_b;
    };

    union
    {
        __IOM uint32_t FWPMTRFM7;         /*!< (@ 0x000056F4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM7_b;
    };
    __IM uint32_t RESERVED138[2];

    union
    {
        __IOM uint32_t FWPMTRFC8;       /*!< (@ 0x00005700) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC8_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC8;    /*!< (@ 0x00005704) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC8_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC8;    /*!< (@ 0x00005708) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC8_b;
    };
    __IM uint32_t RESERVED139[2];

    union
    {
        __IOM uint32_t FWPMTRFM8;         /*!< (@ 0x00005714) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM8_b;
    };
    __IM uint32_t RESERVED140[2];

    union
    {
        __IOM uint32_t FWPMTRFC9;       /*!< (@ 0x00005720) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC9_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC9;    /*!< (@ 0x00005724) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC9_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC9;    /*!< (@ 0x00005728) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC9_b;
    };
    __IM uint32_t RESERVED141[2];

    union
    {
        __IOM uint32_t FWPMTRFM9;         /*!< (@ 0x00005734) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM9_b;
    };
    __IM uint32_t RESERVED142[2];

    union
    {
        __IOM uint32_t FWPMTRFC10;      /*!< (@ 0x00005740) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC10_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC10;   /*!< (@ 0x00005744) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC10_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC10;   /*!< (@ 0x00005748) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC10_b;
    };
    __IM uint32_t RESERVED143[2];

    union
    {
        __IOM uint32_t FWPMTRFM10;        /*!< (@ 0x00005754) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM10_b;
    };
    __IM uint32_t RESERVED144[2];

    union
    {
        __IOM uint32_t FWPMTRFC11;      /*!< (@ 0x00005760) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC11_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC11;   /*!< (@ 0x00005764) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC11_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC11;   /*!< (@ 0x00005768) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC11_b;
    };
    __IM uint32_t RESERVED145[2];

    union
    {
        __IOM uint32_t FWPMTRFM11;        /*!< (@ 0x00005774) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM11_b;
    };
    __IM uint32_t RESERVED146[2];

    union
    {
        __IOM uint32_t FWPMTRFC12;      /*!< (@ 0x00005780) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC12_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC12;   /*!< (@ 0x00005784) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC12_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC12;   /*!< (@ 0x00005788) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC12_b;
    };
    __IM uint32_t RESERVED147[2];

    union
    {
        __IOM uint32_t FWPMTRFM12;        /*!< (@ 0x00005794) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM12_b;
    };
    __IM uint32_t RESERVED148[2];

    union
    {
        __IOM uint32_t FWPMTRFC13;      /*!< (@ 0x000057A0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC13_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC13;   /*!< (@ 0x000057A4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC13_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC13;   /*!< (@ 0x000057A8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC13_b;
    };
    __IM uint32_t RESERVED149[2];

    union
    {
        __IOM uint32_t FWPMTRFM13;        /*!< (@ 0x000057B4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM13_b;
    };
    __IM uint32_t RESERVED150[2];

    union
    {
        __IOM uint32_t FWPMTRFC14;      /*!< (@ 0x000057C0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC14_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC14;   /*!< (@ 0x000057C4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC14_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC14;   /*!< (@ 0x000057C8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC14_b;
    };
    __IM uint32_t RESERVED151[2];

    union
    {
        __IOM uint32_t FWPMTRFM14;        /*!< (@ 0x000057D4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM14_b;
    };
    __IM uint32_t RESERVED152[2];

    union
    {
        __IOM uint32_t FWPMTRFC15;      /*!< (@ 0x000057E0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC15_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC15;   /*!< (@ 0x000057E4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC15_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC15;   /*!< (@ 0x000057E8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC15_b;
    };
    __IM uint32_t RESERVED153[2];

    union
    {
        __IOM uint32_t FWPMTRFM15;        /*!< (@ 0x000057F4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM15_b;
    };
    __IM uint32_t RESERVED154[2];

    union
    {
        __IOM uint32_t FWPMTRFC16;      /*!< (@ 0x00005800) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC16_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC16;   /*!< (@ 0x00005804) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC16_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC16;   /*!< (@ 0x00005808) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC16_b;
    };
    __IM uint32_t RESERVED155[2];

    union
    {
        __IOM uint32_t FWPMTRFM16;        /*!< (@ 0x00005814) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM16_b;
    };
    __IM uint32_t RESERVED156[2];

    union
    {
        __IOM uint32_t FWPMTRFC17;      /*!< (@ 0x00005820) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC17_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC17;   /*!< (@ 0x00005824) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC17_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC17;   /*!< (@ 0x00005828) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC17_b;
    };
    __IM uint32_t RESERVED157[2];

    union
    {
        __IOM uint32_t FWPMTRFM17;        /*!< (@ 0x00005834) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM17_b;
    };
    __IM uint32_t RESERVED158[2];

    union
    {
        __IOM uint32_t FWPMTRFC18;      /*!< (@ 0x00005840) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC18_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC18;   /*!< (@ 0x00005844) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC18_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC18;   /*!< (@ 0x00005848) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC18_b;
    };
    __IM uint32_t RESERVED159[2];

    union
    {
        __IOM uint32_t FWPMTRFM18;        /*!< (@ 0x00005854) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM18_b;
    };
    __IM uint32_t RESERVED160[2];

    union
    {
        __IOM uint32_t FWPMTRFC19;      /*!< (@ 0x00005860) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC19_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC19;   /*!< (@ 0x00005864) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC19_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC19;   /*!< (@ 0x00005868) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC19_b;
    };
    __IM uint32_t RESERVED161[2];

    union
    {
        __IOM uint32_t FWPMTRFM19;        /*!< (@ 0x00005874) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM19_b;
    };
    __IM uint32_t RESERVED162[2];

    union
    {
        __IOM uint32_t FWPMTRFC20;      /*!< (@ 0x00005880) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC20_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC20;   /*!< (@ 0x00005884) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC20_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC20;   /*!< (@ 0x00005888) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC20_b;
    };
    __IM uint32_t RESERVED163[2];

    union
    {
        __IOM uint32_t FWPMTRFM20;        /*!< (@ 0x00005894) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM20_b;
    };
    __IM uint32_t RESERVED164[2];

    union
    {
        __IOM uint32_t FWPMTRFC21;      /*!< (@ 0x000058A0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC21_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC21;   /*!< (@ 0x000058A4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC21_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC21;   /*!< (@ 0x000058A8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC21_b;
    };
    __IM uint32_t RESERVED165[2];

    union
    {
        __IOM uint32_t FWPMTRFM21;        /*!< (@ 0x000058B4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM21_b;
    };
    __IM uint32_t RESERVED166[2];

    union
    {
        __IOM uint32_t FWPMTRFC22;      /*!< (@ 0x000058C0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC22_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC22;   /*!< (@ 0x000058C4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC22_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC22;   /*!< (@ 0x000058C8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC22_b;
    };
    __IM uint32_t RESERVED167[2];

    union
    {
        __IOM uint32_t FWPMTRFM22;        /*!< (@ 0x000058D4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM22_b;
    };
    __IM uint32_t RESERVED168[2];

    union
    {
        __IOM uint32_t FWPMTRFC23;      /*!< (@ 0x000058E0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC23_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC23;   /*!< (@ 0x000058E4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC23_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC23;   /*!< (@ 0x000058E8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC23_b;
    };
    __IM uint32_t RESERVED169[2];

    union
    {
        __IOM uint32_t FWPMTRFM23;        /*!< (@ 0x000058F4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM23_b;
    };
    __IM uint32_t RESERVED170[2];

    union
    {
        __IOM uint32_t FWPMTRFC24;      /*!< (@ 0x00005900) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC24_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC24;   /*!< (@ 0x00005904) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC24_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC24;   /*!< (@ 0x00005908) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC24_b;
    };
    __IM uint32_t RESERVED171[2];

    union
    {
        __IOM uint32_t FWPMTRFM24;        /*!< (@ 0x00005914) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM24_b;
    };
    __IM uint32_t RESERVED172[2];

    union
    {
        __IOM uint32_t FWPMTRFC25;      /*!< (@ 0x00005920) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC25_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC25;   /*!< (@ 0x00005924) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC25_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC25;   /*!< (@ 0x00005928) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC25_b;
    };
    __IM uint32_t RESERVED173[2];

    union
    {
        __IOM uint32_t FWPMTRFM25;        /*!< (@ 0x00005934) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM25_b;
    };
    __IM uint32_t RESERVED174[2];

    union
    {
        __IOM uint32_t FWPMTRFC26;      /*!< (@ 0x00005940) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC26_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC26;   /*!< (@ 0x00005944) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC26_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC26;   /*!< (@ 0x00005948) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC26_b;
    };
    __IM uint32_t RESERVED175[2];

    union
    {
        __IOM uint32_t FWPMTRFM26;        /*!< (@ 0x00005954) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM26_b;
    };
    __IM uint32_t RESERVED176[2];

    union
    {
        __IOM uint32_t FWPMTRFC27;      /*!< (@ 0x00005960) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC27_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC27;   /*!< (@ 0x00005964) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC27_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC27;   /*!< (@ 0x00005968) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC27_b;
    };
    __IM uint32_t RESERVED177[2];

    union
    {
        __IOM uint32_t FWPMTRFM27;        /*!< (@ 0x00005974) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM27_b;
    };
    __IM uint32_t RESERVED178[2];

    union
    {
        __IOM uint32_t FWPMTRFC28;      /*!< (@ 0x00005980) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC28_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC28;   /*!< (@ 0x00005984) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC28_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC28;   /*!< (@ 0x00005988) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC28_b;
    };
    __IM uint32_t RESERVED179[2];

    union
    {
        __IOM uint32_t FWPMTRFM28;        /*!< (@ 0x00005994) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM28_b;
    };
    __IM uint32_t RESERVED180[2];

    union
    {
        __IOM uint32_t FWPMTRFC29;      /*!< (@ 0x000059A0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC29_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC29;   /*!< (@ 0x000059A4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC29_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC29;   /*!< (@ 0x000059A8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC29_b;
    };
    __IM uint32_t RESERVED181[2];

    union
    {
        __IOM uint32_t FWPMTRFM29;        /*!< (@ 0x000059B4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM29_b;
    };
    __IM uint32_t RESERVED182[2];

    union
    {
        __IOM uint32_t FWPMTRFC30;      /*!< (@ 0x000059C0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC30_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC30;   /*!< (@ 0x000059C4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC30_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC30;   /*!< (@ 0x000059C8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC30_b;
    };
    __IM uint32_t RESERVED183[2];

    union
    {
        __IOM uint32_t FWPMTRFM30;        /*!< (@ 0x000059D4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM30_b;
    };
    __IM uint32_t RESERVED184[2];

    union
    {
        __IOM uint32_t FWPMTRFC31;      /*!< (@ 0x000059E0) Forwarding Engine PSFP Meter Filter Configuration
                                         *                  Register i (FWPMTRFCi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRFE   : 1; /*!< [0..0] MTRFE                                                              */
            __IOM uint32_t MTRFM   : 2; /*!< [2..1] MTRFM                                                              */
            __IOM uint32_t MTRFRFD : 1; /*!< [3..3] MTRFRFD                                                            */
            __IOM uint32_t MTRCF   : 1; /*!< [4..4] MTRCF                                                              */
            uint32_t               : 11;
            __IOM uint32_t MTRCM0  : 1; /*!< [16..16] MTRCM0                                                           */
            __IOM uint32_t MTRCM1  : 1; /*!< [17..17] MTRCM1                                                           */
            __IOM uint32_t MTRCM2  : 1; /*!< [18..18] MTRCM2                                                           */
            __IOM uint32_t MTRCM3  : 1; /*!< [19..19] MTRCM3                                                           */
            __IOM uint32_t MTRCM4  : 1; /*!< [20..20] MTRCM4                                                           */
            __IOM uint32_t MTRCM5  : 1; /*!< [21..21] MTRCM5                                                           */
            __IOM uint32_t MTRCM6  : 1; /*!< [22..22] MTRCM6                                                           */
            __IOM uint32_t MTRCM7  : 1; /*!< [23..23] MTRCM7                                                           */
            __IOM uint32_t MTRCM8  : 1; /*!< [24..24] MTRCM8                                                           */
            __IOM uint32_t MTRCM9  : 1; /*!< [25..25] MTRCM9                                                           */
            __IOM uint32_t MTRCM10 : 1; /*!< [26..26] MTRCM10                                                          */
            __IOM uint32_t MTRCM11 : 1; /*!< [27..27] MTRCM11                                                          */
            __IOM uint32_t MTRCM12 : 1; /*!< [28..28] MTRCM12                                                          */
            __IOM uint32_t MTRCM13 : 1; /*!< [29..29] MTRCM13                                                          */
            __IOM uint32_t MTRCM14 : 1; /*!< [30..30] MTRCM14                                                          */
            __IOM uint32_t MTRCM15 : 1; /*!< [31..31] MTRCM15                                                          */
        } FWPMTRFC31_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCBSC31;   /*!< (@ 0x000059E4) Forwarding Engine PSFP Meter CBS Configuration
                                        *                  Register i (FWPMTRCBSCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CBS : 18;   /*!< [17..0] CBS                                                               */
            uint32_t           : 14;
        } FWPMTRCBSC31_b;
    };

    union
    {
        __IOM uint32_t FWPMTRCIRC31;   /*!< (@ 0x000059E8) Forwarding Engine PSFP Meter CIR Configuration
                                        *                  Register i (FWPMTRCIRCi) (i = 0 to 31)                     */

        struct
        {
            __IOM uint32_t CIR : 20;   /*!< [19..0] CIR                                                               */
            uint32_t           : 12;
        } FWPMTRCIRC31_b;
    };
    __IM uint32_t RESERVED185[2];

    union
    {
        __IOM uint32_t FWPMTRFM31;        /*!< (@ 0x000059F4) Forwarding Engine PSFP Meter Filter Monitoring
                                           *                  Register i (FWPMTRFMi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t MTRARDN   : 5; /*!< [4..0] MTRARDN                                                            */
            uint32_t                 : 11;
            __IOM uint32_t MTRARDNMN : 5; /*!< [20..16] MTRARDNMN                                                        */
            uint32_t                 : 11;
        } FWPMTRFM31_b;
    };
    __IM uint32_t RESERVED186[386];

    union
    {
        __IOM uint32_t FWFTL0;         /*!< (@ 0x00006000) Forwarding Engine FRER Table Learn Register 0
                                        *                  (FWFTL0)                                                   */

        struct
        {
            __IOM uint32_t FEAL  : 7;  /*!< [6..0] FEAL                                                               */
            uint32_t             : 9;
            __IOM uint32_t FSRPL : 7;  /*!< [22..16] FSRPL                                                            */
            uint32_t             : 9;
        } FWFTL0_b;
    };

    union
    {
        __IOM uint32_t FWFTL1;          /*!< (@ 0x00006004) Forwarding Engine FRER Table Learn Register 1
                                         *                  (FWFTL1)                                                   */

        struct
        {
            __IOM uint32_t FSHLL  : 4;  /*!< [3..0] FSHLL                                                              */
            uint32_t              : 4;
            __IOM uint32_t FTNSL  : 1;  /*!< [8..8] FTNSL                                                              */
            __IOM uint32_t FSRPVL : 1;  /*!< [9..9] FSRPVL                                                             */
            uint32_t              : 6;
            __IOM uint32_t FSRRTL : 10; /*!< [25..16] FSRRTL                                                           */
            uint32_t              : 6;
        } FWFTL1_b;
    };

    union
    {
        __IOM uint32_t FWFTLR;         /*!< (@ 0x00006008) Forwarding Engine FRER Table Learn Result Register
                                        *                  (FWFTLR)                                                   */

        struct
        {
            __IOM uint32_t FLF : 1;    /*!< [0..0] FLF                                                                */
            uint32_t           : 30;
            __IOM uint32_t FTL : 1;    /*!< [31..31] FTL                                                              */
        } FWFTLR_b;
    };
    __IM uint32_t RESERVED187;

    union
    {
        __IOM uint32_t FWFTOC;         /*!< (@ 0x00006010) Forwarding Engine FRER Timeout Configuration
                                        *                  Register (FWFTOC)                                          */

        struct
        {
            __IOM uint32_t TOT  : 16;  /*!< [15..0] TOT                                                               */
            __IOM uint32_t TOCE : 1;   /*!< [16..16] TOCE                                                             */
            __IOM uint32_t TOOG : 1;   /*!< [17..17] TOOG                                                             */
            uint32_t            : 14;
        } FWFTOC_b;
    };

    union
    {
        __IOM uint32_t FWFTOPC;        /*!< (@ 0x00006014) Forwarding Engine FRER Timeout Prescaler Configuration
                                        *                  Register 0 (FWFTOPC)                                       */

        struct
        {
            __IOM uint32_t USP : 10;   /*!< [9..0] USP                                                                */
            uint32_t           : 22;
        } FWFTOPC_b;
    };
    __IM uint32_t RESERVED188[2];

    union
    {
        __IOM uint32_t FWFTIM;         /*!< (@ 0x00006020) Forwarding Engine FRER Table Initialization Monitoring
                                        *                  Register (FWFTIM)                                          */

        struct
        {
            __IOM uint32_t FTIOG : 1;  /*!< [0..0] FTIOG                                                              */
            __IOM uint32_t FTR   : 1;  /*!< [1..1] FTR                                                                */
            uint32_t             : 30;
        } FWFTIM_b;
    };
    __IM uint32_t RESERVED189[3];

    union
    {
        __IOM uint32_t FWFTR;          /*!< (@ 0x00006030) Forwarding Engine FRER Table Read Register (FWFTR)         */

        struct
        {
            __IOM uint32_t FEAR : 7;   /*!< [6..0] FEAR                                                               */
            uint32_t            : 25;
        } FWFTR_b;
    };

    union
    {
        __IOM uint32_t FWFTRR0;         /*!< (@ 0x00006034) Forwarding Engine FRER Table Read Result Register
                                         *                  0 (FWFTRR0)                                                */

        struct
        {
            __IOM uint32_t FSHLR  : 4;  /*!< [3..0] FSHLR                                                              */
            uint32_t              : 4;
            __IOM uint32_t FTNSR  : 1;  /*!< [8..8] FTNSR                                                              */
            __IOM uint32_t FSRPVR : 1;  /*!< [9..9] FSRPVR                                                             */
            uint32_t              : 6;
            __IOM uint32_t FSRRTR : 10; /*!< [25..16] FSRRTR                                                           */
            uint32_t              : 4;
            __IOM uint32_t FTREF  : 1;  /*!< [30..30] FTREF                                                            */
            __IOM uint32_t FTR    : 1;  /*!< [31..31] FTR                                                              */
        } FWFTRR0_b;
    };

    union
    {
        __IOM uint32_t FWFTRR1;        /*!< (@ 0x00006038) Forwarding Engine FRER Table Read Result Register
                                        *                  1 (FWFTRR1)                                                */

        struct
        {
            __IOM uint32_t FSHR  : 15; /*!< [14..0] FSHR                                                              */
            uint32_t             : 1;
            __IOM uint32_t FSRPR : 7;  /*!< [22..16] FSRPR                                                            */
            uint32_t             : 9;
        } FWFTRR1_b;
    };

    union
    {
        __IOM uint32_t FWFTRR2;        /*!< (@ 0x0000603C) Forwarding Engine FRER Table Read Result Register
                                        *                  2 (FWFTRR2)                                                */

        struct
        {
            __IOM uint32_t FRSNR : 16; /*!< [15..0] FRSNR                                                             */
            __IOM uint32_t FRRTR : 10; /*!< [25..16] FRRTR                                                            */
            uint32_t             : 6;
        } FWFTRR2_b;
    };
    __IM uint32_t RESERVED190[48];

    union
    {
        __IOM uint32_t FWSEQNGC0;       /*!< (@ 0x00006100) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC0_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM0;      /*!< (@ 0x00006104) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM0_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC1;       /*!< (@ 0x00006108) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC1_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM1;      /*!< (@ 0x0000610C) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM1_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC2;       /*!< (@ 0x00006110) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC2_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM2;      /*!< (@ 0x00006114) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM2_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC3;       /*!< (@ 0x00006118) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC3_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM3;      /*!< (@ 0x0000611C) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM3_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC4;       /*!< (@ 0x00006120) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC4_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM4;      /*!< (@ 0x00006124) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM4_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC5;       /*!< (@ 0x00006128) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC5_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM5;      /*!< (@ 0x0000612C) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM5_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC6;       /*!< (@ 0x00006130) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC6_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM6;      /*!< (@ 0x00006134) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM6_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC7;       /*!< (@ 0x00006138) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC7_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM7;      /*!< (@ 0x0000613C) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM7_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC8;       /*!< (@ 0x00006140) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC8_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM8;      /*!< (@ 0x00006144) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM8_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC9;       /*!< (@ 0x00006148) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC9_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM9;      /*!< (@ 0x0000614C) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM9_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC10;      /*!< (@ 0x00006150) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC10_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM10;     /*!< (@ 0x00006154) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM10_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC11;      /*!< (@ 0x00006158) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC11_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM11;     /*!< (@ 0x0000615C) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM11_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC12;      /*!< (@ 0x00006160) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC12_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM12;     /*!< (@ 0x00006164) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM12_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC13;      /*!< (@ 0x00006168) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC13_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM13;     /*!< (@ 0x0000616C) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM13_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC14;      /*!< (@ 0x00006170) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC14_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM14;     /*!< (@ 0x00006174) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM14_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC15;      /*!< (@ 0x00006178) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC15_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM15;     /*!< (@ 0x0000617C) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM15_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC16;      /*!< (@ 0x00006180) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC16_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM16;     /*!< (@ 0x00006184) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM16_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC17;      /*!< (@ 0x00006188) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC17_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM17;     /*!< (@ 0x0000618C) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM17_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC18;      /*!< (@ 0x00006190) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC18_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM18;     /*!< (@ 0x00006194) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM18_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC19;      /*!< (@ 0x00006198) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC19_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM19;     /*!< (@ 0x0000619C) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM19_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC20;      /*!< (@ 0x000061A0) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC20_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM20;     /*!< (@ 0x000061A4) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM20_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC21;      /*!< (@ 0x000061A8) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC21_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM21;     /*!< (@ 0x000061AC) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM21_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC22;      /*!< (@ 0x000061B0) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC22_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM22;     /*!< (@ 0x000061B4) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM22_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC23;      /*!< (@ 0x000061B8) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC23_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM23;     /*!< (@ 0x000061BC) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM23_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC24;      /*!< (@ 0x000061C0) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC24_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM24;     /*!< (@ 0x000061C4) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM24_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC25;      /*!< (@ 0x000061C8) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC25_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM25;     /*!< (@ 0x000061CC) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM25_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC26;      /*!< (@ 0x000061D0) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC26_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM26;     /*!< (@ 0x000061D4) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM26_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC27;      /*!< (@ 0x000061D8) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC27_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM27;     /*!< (@ 0x000061DC) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM27_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC28;      /*!< (@ 0x000061E0) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC28_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM28;     /*!< (@ 0x000061E4) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM28_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC29;      /*!< (@ 0x000061E8) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC29_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM29;     /*!< (@ 0x000061EC) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM29_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC30;      /*!< (@ 0x000061F0) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC30_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM30;     /*!< (@ 0x000061F4) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM30_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGC31;      /*!< (@ 0x000061F8) Forwarding Engine Sequence Number Generation
                                         *                  Configuration Register i (FWSEQNGCi) (i
                                         *                  = 0 to 31)                                                 */

        struct
        {
            __IOM uint32_t SEQNGRN : 8; /*!< [7..0] SEQNGRN                                                            */
            uint32_t               : 8;
            __IOM uint32_t SEQNGE  : 1; /*!< [16..16] SEQNGE                                                           */
            uint32_t               : 15;
        } FWSEQNGC31_b;
    };

    union
    {
        __IOM uint32_t FWSEQNGM31;     /*!< (@ 0x000061FC) Forwarding Engine Sequence Number Generation
                                        *                  Monitoring Register i (FWSEQNGMi) (i = 0
                                        *                  to 31)                                                     */

        struct
        {
            __IOM uint32_t SEQN : 16;  /*!< [15..0] SEQN                                                              */
            uint32_t            : 16;
        } FWSEQNGM31_b;
    };

    union
    {
        __IOM uint32_t FWSEQNRC;        /*!< (@ 0x00006200) Forwarding Engine Sequence Number Reset Configuration
                                         *                  Register (FWSEQNRC)                                        */

        struct
        {
            __IOM uint32_t SEQNR0  : 1; /*!< [0..0] SEQNR0                                                             */
            __IOM uint32_t SEQNR1  : 1; /*!< [1..1] SEQNR1                                                             */
            __IOM uint32_t SEQNR2  : 1; /*!< [2..2] SEQNR2                                                             */
            __IOM uint32_t SEQNR3  : 1; /*!< [3..3] SEQNR3                                                             */
            __IOM uint32_t SEQNR4  : 1; /*!< [4..4] SEQNR4                                                             */
            __IOM uint32_t SEQNR5  : 1; /*!< [5..5] SEQNR5                                                             */
            __IOM uint32_t SEQNR6  : 1; /*!< [6..6] SEQNR6                                                             */
            __IOM uint32_t SEQNR7  : 1; /*!< [7..7] SEQNR7                                                             */
            __IOM uint32_t SEQNR8  : 1; /*!< [8..8] SEQNR8                                                             */
            __IOM uint32_t SEQNR9  : 1; /*!< [9..9] SEQNR9                                                             */
            __IOM uint32_t SEQNR10 : 1; /*!< [10..10] SEQNR10                                                          */
            __IOM uint32_t SEQNR11 : 1; /*!< [11..11] SEQNR11                                                          */
            __IOM uint32_t SEQNR12 : 1; /*!< [12..12] SEQNR12                                                          */
            __IOM uint32_t SEQNR13 : 1; /*!< [13..13] SEQNR13                                                          */
            __IOM uint32_t SEQNR14 : 1; /*!< [14..14] SEQNR14                                                          */
            __IOM uint32_t SEQNR15 : 1; /*!< [15..15] SEQNR15                                                          */
            __IOM uint32_t SEQNR16 : 1; /*!< [16..16] SEQNR16                                                          */
            __IOM uint32_t SEQNR17 : 1; /*!< [17..17] SEQNR17                                                          */
            __IOM uint32_t SEQNR18 : 1; /*!< [18..18] SEQNR18                                                          */
            __IOM uint32_t SEQNR19 : 1; /*!< [19..19] SEQNR19                                                          */
            __IOM uint32_t SEQNR20 : 1; /*!< [20..20] SEQNR20                                                          */
            __IOM uint32_t SEQNR21 : 1; /*!< [21..21] SEQNR21                                                          */
            __IOM uint32_t SEQNR22 : 1; /*!< [22..22] SEQNR22                                                          */
            __IOM uint32_t SEQNR23 : 1; /*!< [23..23] SEQNR23                                                          */
            __IOM uint32_t SEQNR24 : 1; /*!< [24..24] SEQNR24                                                          */
            __IOM uint32_t SEQNR25 : 1; /*!< [25..25] SEQNR25                                                          */
            __IOM uint32_t SEQNR26 : 1; /*!< [26..26] SEQNR26                                                          */
            __IOM uint32_t SEQNR27 : 1; /*!< [27..27] SEQNR27                                                          */
            __IOM uint32_t SEQNR28 : 1; /*!< [28..28] SEQNR28                                                          */
            __IOM uint32_t SEQNR29 : 1; /*!< [29..29] SEQNR29                                                          */
            __IOM uint32_t SEQNR30 : 1; /*!< [30..30] SEQNR30                                                          */
            __IOM uint32_t SEQNR31 : 1; /*!< [31..31] SEQNR31                                                          */
        } FWSEQNRC_b;
    };
    __IM uint32_t RESERVED191[63];

    union
    {
        __IOM uint32_t FWCTFDCN0;      /*!< (@ 0x00006300) Forwarding Engine Cut-Through Forwarded Descriptor
                                        *                  Counter Register i (FWCTFDCNi) (i = 0, 1)                  */

        struct
        {
            __IOM uint32_t CTFDN : 32; /*!< [31..0] CTFDN                                                             */
        } FWCTFDCN0_b;
    };

    union
    {
        __IOM uint32_t FWLTHFDCN0;      /*!< (@ 0x00006304) Forwarding Engine Layer 3 Forwarded Descriptor
                                         *                  Counter Register i (FWLTHFDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTHFDN : 32; /*!< [31..0] LTHFDN                                                            */
        } FWLTHFDCN0_b;
    };
    __IM uint32_t RESERVED192;

    union
    {
        __IOM uint32_t FWLTWFDCN0;      /*!< (@ 0x0000630C) Forwarding Engine Layer 2 Forwarded Descriptor
                                         *                  Counter Register i (FWLTWFDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTWFDN : 32; /*!< [31..0] LTWFDN                                                            */
        } FWLTWFDCN0_b;
    };

    union
    {
        __IOM uint32_t FWPBFDCN0;      /*!< (@ 0x00006310) Forwarding Engine Port Based Forwarded Descriptor
                                        *                  Counter Register i (FWPBFDCNi) (i = 0 to
                                        *                  2)                                                         */

        struct
        {
            __IOM uint32_t PBFDN : 32; /*!< [31..0] PBFDN                                                             */
        } FWPBFDCN0_b;
    };

    union
    {
        __IOM uint32_t FWMHLCN0;       /*!< (@ 0x00006314) Forwarding Engine MAC Hardware Learn Counter
                                        *                  Register i (FWMHLCNi) (i = 0 to 2)                         */

        struct
        {
            __IOM uint32_t MHLN : 32;  /*!< [31..0] MHLN                                                              */
        } FWMHLCN0_b;
    };
    __IM uint32_t RESERVED193[2];

    union
    {
        __IOM uint32_t FWCTFDCN1;      /*!< (@ 0x00006320) Forwarding Engine Cut-Through Forwarded Descriptor
                                        *                  Counter Register i (FWCTFDCNi) (i = 0, 1)                  */

        struct
        {
            __IOM uint32_t CTFDN : 32; /*!< [31..0] CTFDN                                                             */
        } FWCTFDCN1_b;
    };

    union
    {
        __IOM uint32_t FWLTHFDCN1;      /*!< (@ 0x00006324) Forwarding Engine Layer 3 Forwarded Descriptor
                                         *                  Counter Register i (FWLTHFDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTHFDN : 32; /*!< [31..0] LTHFDN                                                            */
        } FWLTHFDCN1_b;
    };
    __IM uint32_t RESERVED194;

    union
    {
        __IOM uint32_t FWLTWFDCN1;      /*!< (@ 0x0000632C) Forwarding Engine Layer 2 Forwarded Descriptor
                                         *                  Counter Register i (FWLTWFDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTWFDN : 32; /*!< [31..0] LTWFDN                                                            */
        } FWLTWFDCN1_b;
    };

    union
    {
        __IOM uint32_t FWPBFDCN1;      /*!< (@ 0x00006330) Forwarding Engine Port Based Forwarded Descriptor
                                        *                  Counter Register i (FWPBFDCNi) (i = 0 to
                                        *                  2)                                                         */

        struct
        {
            __IOM uint32_t PBFDN : 32; /*!< [31..0] PBFDN                                                             */
        } FWPBFDCN1_b;
    };

    union
    {
        __IOM uint32_t FWMHLCN1;       /*!< (@ 0x00006334) Forwarding Engine MAC Hardware Learn Counter
                                        *                  Register i (FWMHLCNi) (i = 0 to 2)                         */

        struct
        {
            __IOM uint32_t MHLN : 32;  /*!< [31..0] MHLN                                                              */
        } FWMHLCN1_b;
    };
    __IM uint32_t RESERVED195[2];

    union
    {
        __IOM uint32_t FWDDFDCN2;      /*!< (@ 0x00006340) Forwarding Engine Direct Descriptor Forwarded
                                        *                  Descriptor Counter Register 0 (FWDDFDCN0)                  */

        struct
        {
            __IOM uint32_t DDFDN : 32; /*!< [31..0] DDFDN                                                             */
        } FWDDFDCN2_b;
    };

    union
    {
        __IOM uint32_t FWLTHFDCN2;      /*!< (@ 0x00006344) Forwarding Engine Layer 3 Forwarded Descriptor
                                         *                  Counter Register i (FWLTHFDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTHFDN : 32; /*!< [31..0] LTHFDN                                                            */
        } FWLTHFDCN2_b;
    };
    __IM uint32_t RESERVED196;

    union
    {
        __IOM uint32_t FWLTWFDCN2;      /*!< (@ 0x0000634C) Forwarding Engine Layer 2 Forwarded Descriptor
                                         *                  Counter Register i (FWLTWFDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTWFDN : 32; /*!< [31..0] LTWFDN                                                            */
        } FWLTWFDCN2_b;
    };

    union
    {
        __IOM uint32_t FWPBFDCN2;      /*!< (@ 0x00006350) Forwarding Engine Port Based Forwarded Descriptor
                                        *                  Counter Register i (FWPBFDCNi) (i = 0 to
                                        *                  2)                                                         */

        struct
        {
            __IOM uint32_t PBFDN : 32; /*!< [31..0] PBFDN                                                             */
        } FWPBFDCN2_b;
    };

    union
    {
        __IOM uint32_t FWMHLCN2;       /*!< (@ 0x00006354) Forwarding Engine MAC Hardware Learn Counter
                                        *                  Register i (FWMHLCNi) (i = 0 to 2)                         */

        struct
        {
            __IOM uint32_t MHLN : 32;  /*!< [31..0] MHLN                                                              */
        } FWMHLCN2_b;
    };
    __IM uint32_t RESERVED197[107];

    union
    {
        __IOM uint32_t FWWMRDCN0;      /*!< (@ 0x00006504) Forwarding Engine Watermark Rejected Descriptor
                                        *                  Counter Register i (FWWMRDCNi) (i = 0 to
                                        *                  2)                                                         */

        struct
        {
            __IOM uint32_t WMRDN : 16; /*!< [15..0] WMRDN                                                             */
            uint32_t             : 16;
        } FWWMRDCN0_b;
    };

    union
    {
        __IOM uint32_t FWCTRDCN0;      /*!< (@ 0x00006508) Forwarding Engine Cut-Through Rejected Descriptor
                                        *                  Counter Register i (FWCTRDCNi) (i = 0, 1)                  */

        struct
        {
            __IOM uint32_t CTRDN : 16; /*!< [15..0] CTRDN                                                             */
            uint32_t             : 16;
        } FWCTRDCN0_b;
    };

    union
    {
        __IOM uint32_t FWLTHRDCN0;      /*!< (@ 0x0000650C) Forwarding Engine Layer 3 Rejected Descriptor
                                         *                  Counter Register i (FWLTHRDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTHRDN : 16; /*!< [15..0] LTHRDN                                                            */
            uint32_t              : 16;
        } FWLTHRDCN0_b;
    };
    __IM uint32_t RESERVED198;

    union
    {
        __IOM uint32_t FWLTWRDCN0;      /*!< (@ 0x00006514) Forwarding Engine Layer 2 Rejected Descriptor
                                         *                  Counter Register i (FWLTWRDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTWRDN : 16; /*!< [15..0] LTWRDN                                                            */
            uint32_t              : 16;
        } FWLTWRDCN0_b;
    };

    union
    {
        __IOM uint32_t FWPBRDCN0;      /*!< (@ 0x00006518) Forwarding Engine Port Based Rejected Descriptor
                                        *                  Counter Register i (FWPBRDCNi) (i = 0 to
                                        *                  2)                                                         */

        struct
        {
            __IOM uint32_t PBRDN : 16; /*!< [15..0] PBRDN                                                             */
            uint32_t             : 16;
        } FWPBRDCN0_b;
    };
    __IM uint32_t RESERVED199[2];

    union
    {
        __IOM uint32_t FWWMRDCN1;      /*!< (@ 0x00006524) Forwarding Engine Watermark Rejected Descriptor
                                        *                  Counter Register i (FWWMRDCNi) (i = 0 to
                                        *                  2)                                                         */

        struct
        {
            __IOM uint32_t WMRDN : 16; /*!< [15..0] WMRDN                                                             */
            uint32_t             : 16;
        } FWWMRDCN1_b;
    };

    union
    {
        __IOM uint32_t FWCTRDCN1;      /*!< (@ 0x00006528) Forwarding Engine Cut-Through Rejected Descriptor
                                        *                  Counter Register i (FWCTRDCNi) (i = 0, 1)                  */

        struct
        {
            __IOM uint32_t CTRDN : 16; /*!< [15..0] CTRDN                                                             */
            uint32_t             : 16;
        } FWCTRDCN1_b;
    };

    union
    {
        __IOM uint32_t FWLTHRDCN1;      /*!< (@ 0x0000652C) Forwarding Engine Layer 3 Rejected Descriptor
                                         *                  Counter Register i (FWLTHRDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTHRDN : 16; /*!< [15..0] LTHRDN                                                            */
            uint32_t              : 16;
        } FWLTHRDCN1_b;
    };
    __IM uint32_t RESERVED200;

    union
    {
        __IOM uint32_t FWLTWRDCN1;      /*!< (@ 0x00006534) Forwarding Engine Layer 2 Rejected Descriptor
                                         *                  Counter Register i (FWLTWRDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTWRDN : 16; /*!< [15..0] LTWRDN                                                            */
            uint32_t              : 16;
        } FWLTWRDCN1_b;
    };

    union
    {
        __IOM uint32_t FWPBRDCN1;      /*!< (@ 0x00006538) Forwarding Engine Port Based Rejected Descriptor
                                        *                  Counter Register i (FWPBRDCNi) (i = 0 to
                                        *                  2)                                                         */

        struct
        {
            __IOM uint32_t PBRDN : 16; /*!< [15..0] PBRDN                                                             */
            uint32_t             : 16;
        } FWPBRDCN1_b;
    };
    __IM uint32_t RESERVED201[2];

    union
    {
        __IOM uint32_t FWWMRDCN2;      /*!< (@ 0x00006544) Forwarding Engine Watermark Rejected Descriptor
                                        *                  Counter Register i (FWWMRDCNi) (i = 0 to
                                        *                  2)                                                         */

        struct
        {
            __IOM uint32_t WMRDN : 16; /*!< [15..0] WMRDN                                                             */
            uint32_t             : 16;
        } FWWMRDCN2_b;
    };

    union
    {
        __IOM uint32_t FWDDRDCN2;      /*!< (@ 0x00006548) Forwarding Engine Direct Descriptor Rejected
                                        *                  Descriptor Counter Register 0 (FWDDRDCN0)                  */

        struct
        {
            __IOM uint32_t DDRDN : 16; /*!< [15..0] DDRDN                                                             */
            uint32_t             : 16;
        } FWDDRDCN2_b;
    };

    union
    {
        __IOM uint32_t FWLTHRDCN2;      /*!< (@ 0x0000654C) Forwarding Engine Layer 3 Rejected Descriptor
                                         *                  Counter Register i (FWLTHRDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTHRDN : 16; /*!< [15..0] LTHRDN                                                            */
            uint32_t              : 16;
        } FWLTHRDCN2_b;
    };
    __IM uint32_t RESERVED202;

    union
    {
        __IOM uint32_t FWLTWRDCN2;      /*!< (@ 0x00006554) Forwarding Engine Layer 2 Rejected Descriptor
                                         *                  Counter Register i (FWLTWRDCNi) (i = 0 to
                                         *                  2)                                                         */

        struct
        {
            __IOM uint32_t LTWRDN : 16; /*!< [15..0] LTWRDN                                                            */
            uint32_t              : 16;
        } FWLTWRDCN2_b;
    };

    union
    {
        __IOM uint32_t FWPBRDCN2;      /*!< (@ 0x00006558) Forwarding Engine Port Based Rejected Descriptor
                                        *                  Counter Register i (FWPBRDCNi) (i = 0 to
                                        *                  2)                                                         */

        struct
        {
            __IOM uint32_t PBRDN : 16; /*!< [15..0] PBRDN                                                             */
            uint32_t             : 16;
        } FWPBRDCN2_b;
    };
    __IM uint32_t RESERVED203[105];

    union
    {
        __IOM uint32_t FWPMFDCN0;      /*!< (@ 0x00006700) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN0_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN1;      /*!< (@ 0x00006704) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN1_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN2;      /*!< (@ 0x00006708) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN2_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN3;      /*!< (@ 0x0000670C) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN3_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN4;      /*!< (@ 0x00006710) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN4_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN5;      /*!< (@ 0x00006714) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN5_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN6;      /*!< (@ 0x00006718) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN6_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN7;      /*!< (@ 0x0000671C) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN7_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN8;      /*!< (@ 0x00006720) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN8_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN9;      /*!< (@ 0x00006724) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN9_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN10;     /*!< (@ 0x00006728) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN10_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN11;     /*!< (@ 0x0000672C) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN11_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN12;     /*!< (@ 0x00006730) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN12_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN13;     /*!< (@ 0x00006734) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN13_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN14;     /*!< (@ 0x00006738) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN14_b;
    };

    union
    {
        __IOM uint32_t FWPMFDCN15;     /*!< (@ 0x0000673C) Forwarding Engine PSFP MSDU Filtered Descriptor
                                        *                  Counter Register i (FWPMFDCNi) (i = 0 to
                                        *                  15)                                                        */

        struct
        {
            __IOM uint32_t PMFDN : 16; /*!< [15..0] PMFDN                                                             */
            uint32_t             : 16;
        } FWPMFDCN15_b;
    };
    __IM uint32_t RESERVED204[48];

    union
    {
        __IOM uint32_t FWPMGDCN0;      /*!< (@ 0x00006800) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN0_b;
    };

    union
    {
        __IOM uint32_t FWPMYDCN0;      /*!< (@ 0x00006804) Forwarding Engine PSFP Meter Yellow Descriptor
                                        *                  Counter Register i (FWPMYDCNi) (i = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t PMYDN : 16; /*!< [15..0] PMYDN                                                             */
            uint32_t             : 16;
        } FWPMYDCN0_b;
    };

    union
    {
        __IOM uint32_t FWPMRDCN0;      /*!< (@ 0x00006808) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN0_b;
    };
    __IM uint32_t RESERVED205;

    union
    {
        __IOM uint32_t FWPMGDCN1;      /*!< (@ 0x00006810) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN1_b;
    };

    union
    {
        __IOM uint32_t FWPMYDCN1;      /*!< (@ 0x00006814) Forwarding Engine PSFP Meter Yellow Descriptor
                                        *                  Counter Register i (FWPMYDCNi) (i = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t PMYDN : 16; /*!< [15..0] PMYDN                                                             */
            uint32_t             : 16;
        } FWPMYDCN1_b;
    };

    union
    {
        __IOM uint32_t FWPMRDCN1;      /*!< (@ 0x00006818) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN1_b;
    };
    __IM uint32_t RESERVED206;

    union
    {
        __IOM uint32_t FWPMGDCN2;      /*!< (@ 0x00006820) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN2_b;
    };

    union
    {
        __IOM uint32_t FWPMYDCN2;      /*!< (@ 0x00006824) Forwarding Engine PSFP Meter Yellow Descriptor
                                        *                  Counter Register i (FWPMYDCNi) (i = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t PMYDN : 16; /*!< [15..0] PMYDN                                                             */
            uint32_t             : 16;
        } FWPMYDCN2_b;
    };

    union
    {
        __IOM uint32_t FWPMRDCN2;      /*!< (@ 0x00006828) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN2_b;
    };
    __IM uint32_t RESERVED207;

    union
    {
        __IOM uint32_t FWPMGDCN3;      /*!< (@ 0x00006830) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN3_b;
    };

    union
    {
        __IOM uint32_t FWPMYDCN3;      /*!< (@ 0x00006834) Forwarding Engine PSFP Meter Yellow Descriptor
                                        *                  Counter Register i (FWPMYDCNi) (i = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t PMYDN : 16; /*!< [15..0] PMYDN                                                             */
            uint32_t             : 16;
        } FWPMYDCN3_b;
    };

    union
    {
        __IOM uint32_t FWPMRDCN3;      /*!< (@ 0x00006838) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN3_b;
    };
    __IM uint32_t RESERVED208;

    union
    {
        __IOM uint32_t FWPMGDCN4;      /*!< (@ 0x00006840) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN4_b;
    };

    union
    {
        __IOM uint32_t FWPMYDCN4;      /*!< (@ 0x00006844) Forwarding Engine PSFP Meter Yellow Descriptor
                                        *                  Counter Register i (FWPMYDCNi) (i = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t PMYDN : 16; /*!< [15..0] PMYDN                                                             */
            uint32_t             : 16;
        } FWPMYDCN4_b;
    };

    union
    {
        __IOM uint32_t FWPMRDCN4;      /*!< (@ 0x00006848) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN4_b;
    };
    __IM uint32_t RESERVED209;

    union
    {
        __IOM uint32_t FWPMGDCN5;      /*!< (@ 0x00006850) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN5_b;
    };

    union
    {
        __IOM uint32_t FWPMYDCN5;      /*!< (@ 0x00006854) Forwarding Engine PSFP Meter Yellow Descriptor
                                        *                  Counter Register i (FWPMYDCNi) (i = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t PMYDN : 16; /*!< [15..0] PMYDN                                                             */
            uint32_t             : 16;
        } FWPMYDCN5_b;
    };

    union
    {
        __IOM uint32_t FWPMRDCN5;      /*!< (@ 0x00006858) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN5_b;
    };
    __IM uint32_t RESERVED210;

    union
    {
        __IOM uint32_t FWPMGDCN6;      /*!< (@ 0x00006860) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN6_b;
    };

    union
    {
        __IOM uint32_t FWPMYDCN6;      /*!< (@ 0x00006864) Forwarding Engine PSFP Meter Yellow Descriptor
                                        *                  Counter Register i (FWPMYDCNi) (i = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t PMYDN : 16; /*!< [15..0] PMYDN                                                             */
            uint32_t             : 16;
        } FWPMYDCN6_b;
    };

    union
    {
        __IOM uint32_t FWPMRDCN6;      /*!< (@ 0x00006868) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN6_b;
    };
    __IM uint32_t RESERVED211;

    union
    {
        __IOM uint32_t FWPMGDCN7;      /*!< (@ 0x00006870) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN7_b;
    };

    union
    {
        __IOM uint32_t FWPMYDCN7;      /*!< (@ 0x00006874) Forwarding Engine PSFP Meter Yellow Descriptor
                                        *                  Counter Register i (FWPMYDCNi) (i = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t PMYDN : 16; /*!< [15..0] PMYDN                                                             */
            uint32_t             : 16;
        } FWPMYDCN7_b;
    };

    union
    {
        __IOM uint32_t FWPMRDCN7;      /*!< (@ 0x00006878) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN7_b;
    };
    __IM uint32_t RESERVED212;

    union
    {
        __IOM uint32_t FWPMGDCN8;      /*!< (@ 0x00006880) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN8_b;
    };
    __IM uint32_t RESERVED213;

    union
    {
        __IOM uint32_t FWPMRDCN8;      /*!< (@ 0x00006888) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN8_b;
    };
    __IM uint32_t RESERVED214;

    union
    {
        __IOM uint32_t FWPMGDCN9;      /*!< (@ 0x00006890) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN9_b;
    };
    __IM uint32_t RESERVED215;

    union
    {
        __IOM uint32_t FWPMRDCN9;      /*!< (@ 0x00006898) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN9_b;
    };
    __IM uint32_t RESERVED216;

    union
    {
        __IOM uint32_t FWPMGDCN10;     /*!< (@ 0x000068A0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN10_b;
    };
    __IM uint32_t RESERVED217;

    union
    {
        __IOM uint32_t FWPMRDCN10;     /*!< (@ 0x000068A8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN10_b;
    };
    __IM uint32_t RESERVED218;

    union
    {
        __IOM uint32_t FWPMGDCN11;     /*!< (@ 0x000068B0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN11_b;
    };
    __IM uint32_t RESERVED219;

    union
    {
        __IOM uint32_t FWPMRDCN11;     /*!< (@ 0x000068B8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN11_b;
    };
    __IM uint32_t RESERVED220;

    union
    {
        __IOM uint32_t FWPMGDCN12;     /*!< (@ 0x000068C0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN12_b;
    };
    __IM uint32_t RESERVED221;

    union
    {
        __IOM uint32_t FWPMRDCN12;     /*!< (@ 0x000068C8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN12_b;
    };
    __IM uint32_t RESERVED222;

    union
    {
        __IOM uint32_t FWPMGDCN13;     /*!< (@ 0x000068D0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN13_b;
    };
    __IM uint32_t RESERVED223;

    union
    {
        __IOM uint32_t FWPMRDCN13;     /*!< (@ 0x000068D8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN13_b;
    };
    __IM uint32_t RESERVED224;

    union
    {
        __IOM uint32_t FWPMGDCN14;     /*!< (@ 0x000068E0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN14_b;
    };
    __IM uint32_t RESERVED225;

    union
    {
        __IOM uint32_t FWPMRDCN14;     /*!< (@ 0x000068E8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN14_b;
    };
    __IM uint32_t RESERVED226;

    union
    {
        __IOM uint32_t FWPMGDCN15;     /*!< (@ 0x000068F0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN15_b;
    };
    __IM uint32_t RESERVED227;

    union
    {
        __IOM uint32_t FWPMRDCN15;     /*!< (@ 0x000068F8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN15_b;
    };
    __IM uint32_t RESERVED228;

    union
    {
        __IOM uint32_t FWPMGDCN16;     /*!< (@ 0x00006900) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN16_b;
    };
    __IM uint32_t RESERVED229;

    union
    {
        __IOM uint32_t FWPMRDCN16;     /*!< (@ 0x00006908) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN16_b;
    };
    __IM uint32_t RESERVED230;

    union
    {
        __IOM uint32_t FWPMGDCN17;     /*!< (@ 0x00006910) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN17_b;
    };
    __IM uint32_t RESERVED231;

    union
    {
        __IOM uint32_t FWPMRDCN17;     /*!< (@ 0x00006918) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN17_b;
    };
    __IM uint32_t RESERVED232;

    union
    {
        __IOM uint32_t FWPMGDCN18;     /*!< (@ 0x00006920) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN18_b;
    };
    __IM uint32_t RESERVED233;

    union
    {
        __IOM uint32_t FWPMRDCN18;     /*!< (@ 0x00006928) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN18_b;
    };
    __IM uint32_t RESERVED234;

    union
    {
        __IOM uint32_t FWPMGDCN19;     /*!< (@ 0x00006930) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN19_b;
    };
    __IM uint32_t RESERVED235;

    union
    {
        __IOM uint32_t FWPMRDCN19;     /*!< (@ 0x00006938) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN19_b;
    };
    __IM uint32_t RESERVED236;

    union
    {
        __IOM uint32_t FWPMGDCN20;     /*!< (@ 0x00006940) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN20_b;
    };
    __IM uint32_t RESERVED237;

    union
    {
        __IOM uint32_t FWPMRDCN20;     /*!< (@ 0x00006948) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN20_b;
    };
    __IM uint32_t RESERVED238;

    union
    {
        __IOM uint32_t FWPMGDCN21;     /*!< (@ 0x00006950) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN21_b;
    };
    __IM uint32_t RESERVED239;

    union
    {
        __IOM uint32_t FWPMRDCN21;     /*!< (@ 0x00006958) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN21_b;
    };
    __IM uint32_t RESERVED240;

    union
    {
        __IOM uint32_t FWPMGDCN22;     /*!< (@ 0x00006960) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN22_b;
    };
    __IM uint32_t RESERVED241;

    union
    {
        __IOM uint32_t FWPMRDCN22;     /*!< (@ 0x00006968) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN22_b;
    };
    __IM uint32_t RESERVED242;

    union
    {
        __IOM uint32_t FWPMGDCN23;     /*!< (@ 0x00006970) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN23_b;
    };
    __IM uint32_t RESERVED243;

    union
    {
        __IOM uint32_t FWPMRDCN23;     /*!< (@ 0x00006978) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN23_b;
    };
    __IM uint32_t RESERVED244;

    union
    {
        __IOM uint32_t FWPMGDCN24;     /*!< (@ 0x00006980) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN24_b;
    };
    __IM uint32_t RESERVED245;

    union
    {
        __IOM uint32_t FWPMRDCN24;     /*!< (@ 0x00006988) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN24_b;
    };
    __IM uint32_t RESERVED246;

    union
    {
        __IOM uint32_t FWPMGDCN25;     /*!< (@ 0x00006990) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN25_b;
    };
    __IM uint32_t RESERVED247;

    union
    {
        __IOM uint32_t FWPMRDCN25;     /*!< (@ 0x00006998) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN25_b;
    };
    __IM uint32_t RESERVED248;

    union
    {
        __IOM uint32_t FWPMGDCN26;     /*!< (@ 0x000069A0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN26_b;
    };
    __IM uint32_t RESERVED249;

    union
    {
        __IOM uint32_t FWPMRDCN26;     /*!< (@ 0x000069A8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN26_b;
    };
    __IM uint32_t RESERVED250;

    union
    {
        __IOM uint32_t FWPMGDCN27;     /*!< (@ 0x000069B0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN27_b;
    };
    __IM uint32_t RESERVED251;

    union
    {
        __IOM uint32_t FWPMRDCN27;     /*!< (@ 0x000069B8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN27_b;
    };
    __IM uint32_t RESERVED252;

    union
    {
        __IOM uint32_t FWPMGDCN28;     /*!< (@ 0x000069C0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN28_b;
    };
    __IM uint32_t RESERVED253;

    union
    {
        __IOM uint32_t FWPMRDCN28;     /*!< (@ 0x000069C8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN28_b;
    };
    __IM uint32_t RESERVED254;

    union
    {
        __IOM uint32_t FWPMGDCN29;     /*!< (@ 0x000069D0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN29_b;
    };
    __IM uint32_t RESERVED255;

    union
    {
        __IOM uint32_t FWPMRDCN29;     /*!< (@ 0x000069D8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN29_b;
    };
    __IM uint32_t RESERVED256;

    union
    {
        __IOM uint32_t FWPMGDCN30;     /*!< (@ 0x000069E0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN30_b;
    };
    __IM uint32_t RESERVED257;

    union
    {
        __IOM uint32_t FWPMRDCN30;     /*!< (@ 0x000069E8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN30_b;
    };
    __IM uint32_t RESERVED258;

    union
    {
        __IOM uint32_t FWPMGDCN31;     /*!< (@ 0x000069F0) Forwarding Engine PSFP Meter Green Descriptor
                                        *                  Counter Register i (FWPMGDCNi) (i = 0 to
                                        *                  31)                                                        */

        struct
        {
            __IOM uint32_t PMGDN : 16; /*!< [15..0] PMGDN                                                             */
            uint32_t             : 16;
        } FWPMGDCN31_b;
    };
    __IM uint32_t RESERVED259;

    union
    {
        __IOM uint32_t FWPMRDCN31;     /*!< (@ 0x000069F8) Forwarding Engine PSFP Meter Red Descriptor Counter
                                        *                  Register i (FWPMRDCNi) (i = 0 to 31)                       */

        struct
        {
            __IOM uint32_t PMRDN : 16; /*!< [15..0] PMRDN                                                             */
            uint32_t             : 16;
        } FWPMRDCN31_b;
    };
    __IM uint32_t RESERVED260;

    union
    {
        __IOM uint32_t FWFRPPCN0;      /*!< (@ 0x00006A00) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN0_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN0;      /*!< (@ 0x00006A04) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN0_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN1;      /*!< (@ 0x00006A08) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN1_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN1;      /*!< (@ 0x00006A0C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN1_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN2;      /*!< (@ 0x00006A10) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN2_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN2;      /*!< (@ 0x00006A14) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN2_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN3;      /*!< (@ 0x00006A18) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN3_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN3;      /*!< (@ 0x00006A1C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN3_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN4;      /*!< (@ 0x00006A20) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN4_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN4;      /*!< (@ 0x00006A24) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN4_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN5;      /*!< (@ 0x00006A28) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN5_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN5;      /*!< (@ 0x00006A2C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN5_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN6;      /*!< (@ 0x00006A30) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN6_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN6;      /*!< (@ 0x00006A34) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN6_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN7;      /*!< (@ 0x00006A38) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN7_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN7;      /*!< (@ 0x00006A3C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN7_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN8;      /*!< (@ 0x00006A40) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN8_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN8;      /*!< (@ 0x00006A44) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN8_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN9;      /*!< (@ 0x00006A48) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN9_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN9;      /*!< (@ 0x00006A4C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN9_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN10;     /*!< (@ 0x00006A50) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN10_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN10;     /*!< (@ 0x00006A54) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN10_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN11;     /*!< (@ 0x00006A58) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN11_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN11;     /*!< (@ 0x00006A5C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN11_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN12;     /*!< (@ 0x00006A60) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN12_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN12;     /*!< (@ 0x00006A64) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN12_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN13;     /*!< (@ 0x00006A68) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN13_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN13;     /*!< (@ 0x00006A6C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN13_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN14;     /*!< (@ 0x00006A70) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN14_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN14;     /*!< (@ 0x00006A74) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN14_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN15;     /*!< (@ 0x00006A78) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN15_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN15;     /*!< (@ 0x00006A7C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN15_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN16;     /*!< (@ 0x00006A80) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN16_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN16;     /*!< (@ 0x00006A84) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN16_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN17;     /*!< (@ 0x00006A88) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN17_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN17;     /*!< (@ 0x00006A8C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN17_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN18;     /*!< (@ 0x00006A90) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN18_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN18;     /*!< (@ 0x00006A94) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN18_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN19;     /*!< (@ 0x00006A98) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN19_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN19;     /*!< (@ 0x00006A9C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN19_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN20;     /*!< (@ 0x00006AA0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN20_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN20;     /*!< (@ 0x00006AA4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN20_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN21;     /*!< (@ 0x00006AA8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN21_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN21;     /*!< (@ 0x00006AAC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN21_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN22;     /*!< (@ 0x00006AB0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN22_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN22;     /*!< (@ 0x00006AB4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN22_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN23;     /*!< (@ 0x00006AB8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN23_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN23;     /*!< (@ 0x00006ABC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN23_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN24;     /*!< (@ 0x00006AC0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN24_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN24;     /*!< (@ 0x00006AC4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN24_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN25;     /*!< (@ 0x00006AC8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN25_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN25;     /*!< (@ 0x00006ACC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN25_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN26;     /*!< (@ 0x00006AD0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN26_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN26;     /*!< (@ 0x00006AD4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN26_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN27;     /*!< (@ 0x00006AD8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN27_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN27;     /*!< (@ 0x00006ADC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN27_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN28;     /*!< (@ 0x00006AE0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN28_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN28;     /*!< (@ 0x00006AE4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN28_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN29;     /*!< (@ 0x00006AE8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN29_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN29;     /*!< (@ 0x00006AEC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN29_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN30;     /*!< (@ 0x00006AF0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN30_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN30;     /*!< (@ 0x00006AF4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN30_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN31;     /*!< (@ 0x00006AF8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN31_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN31;     /*!< (@ 0x00006AFC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN31_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN32;     /*!< (@ 0x00006B00) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN32_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN32;     /*!< (@ 0x00006B04) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN32_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN33;     /*!< (@ 0x00006B08) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN33_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN33;     /*!< (@ 0x00006B0C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN33_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN34;     /*!< (@ 0x00006B10) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN34_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN34;     /*!< (@ 0x00006B14) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN34_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN35;     /*!< (@ 0x00006B18) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN35_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN35;     /*!< (@ 0x00006B1C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN35_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN36;     /*!< (@ 0x00006B20) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN36_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN36;     /*!< (@ 0x00006B24) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN36_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN37;     /*!< (@ 0x00006B28) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN37_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN37;     /*!< (@ 0x00006B2C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN37_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN38;     /*!< (@ 0x00006B30) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN38_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN38;     /*!< (@ 0x00006B34) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN38_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN39;     /*!< (@ 0x00006B38) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN39_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN39;     /*!< (@ 0x00006B3C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN39_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN40;     /*!< (@ 0x00006B40) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN40_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN40;     /*!< (@ 0x00006B44) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN40_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN41;     /*!< (@ 0x00006B48) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN41_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN41;     /*!< (@ 0x00006B4C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN41_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN42;     /*!< (@ 0x00006B50) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN42_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN42;     /*!< (@ 0x00006B54) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN42_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN43;     /*!< (@ 0x00006B58) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN43_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN43;     /*!< (@ 0x00006B5C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN43_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN44;     /*!< (@ 0x00006B60) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN44_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN44;     /*!< (@ 0x00006B64) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN44_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN45;     /*!< (@ 0x00006B68) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN45_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN45;     /*!< (@ 0x00006B6C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN45_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN46;     /*!< (@ 0x00006B70) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN46_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN46;     /*!< (@ 0x00006B74) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN46_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN47;     /*!< (@ 0x00006B78) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN47_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN47;     /*!< (@ 0x00006B7C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN47_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN48;     /*!< (@ 0x00006B80) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN48_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN48;     /*!< (@ 0x00006B84) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN48_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN49;     /*!< (@ 0x00006B88) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN49_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN49;     /*!< (@ 0x00006B8C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN49_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN50;     /*!< (@ 0x00006B90) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN50_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN50;     /*!< (@ 0x00006B94) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN50_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN51;     /*!< (@ 0x00006B98) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN51_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN51;     /*!< (@ 0x00006B9C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN51_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN52;     /*!< (@ 0x00006BA0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN52_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN52;     /*!< (@ 0x00006BA4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN52_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN53;     /*!< (@ 0x00006BA8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN53_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN53;     /*!< (@ 0x00006BAC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN53_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN54;     /*!< (@ 0x00006BB0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN54_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN54;     /*!< (@ 0x00006BB4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN54_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN55;     /*!< (@ 0x00006BB8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN55_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN55;     /*!< (@ 0x00006BBC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN55_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN56;     /*!< (@ 0x00006BC0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN56_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN56;     /*!< (@ 0x00006BC4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN56_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN57;     /*!< (@ 0x00006BC8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN57_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN57;     /*!< (@ 0x00006BCC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN57_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN58;     /*!< (@ 0x00006BD0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN58_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN58;     /*!< (@ 0x00006BD4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN58_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN59;     /*!< (@ 0x00006BD8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN59_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN59;     /*!< (@ 0x00006BDC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN59_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN60;     /*!< (@ 0x00006BE0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN60_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN60;     /*!< (@ 0x00006BE4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN60_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN61;     /*!< (@ 0x00006BE8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN61_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN61;     /*!< (@ 0x00006BEC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN61_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN62;     /*!< (@ 0x00006BF0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN62_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN62;     /*!< (@ 0x00006BF4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN62_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN63;     /*!< (@ 0x00006BF8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN63_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN63;     /*!< (@ 0x00006BFC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN63_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN64;     /*!< (@ 0x00006C00) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN64_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN64;     /*!< (@ 0x00006C04) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN64_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN65;     /*!< (@ 0x00006C08) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN65_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN65;     /*!< (@ 0x00006C0C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN65_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN66;     /*!< (@ 0x00006C10) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN66_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN66;     /*!< (@ 0x00006C14) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN66_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN67;     /*!< (@ 0x00006C18) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN67_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN67;     /*!< (@ 0x00006C1C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN67_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN68;     /*!< (@ 0x00006C20) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN68_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN68;     /*!< (@ 0x00006C24) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN68_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN69;     /*!< (@ 0x00006C28) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN69_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN69;     /*!< (@ 0x00006C2C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN69_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN70;     /*!< (@ 0x00006C30) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN70_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN70;     /*!< (@ 0x00006C34) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN70_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN71;     /*!< (@ 0x00006C38) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN71_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN71;     /*!< (@ 0x00006C3C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN71_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN72;     /*!< (@ 0x00006C40) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN72_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN72;     /*!< (@ 0x00006C44) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN72_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN73;     /*!< (@ 0x00006C48) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN73_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN73;     /*!< (@ 0x00006C4C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN73_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN74;     /*!< (@ 0x00006C50) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN74_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN74;     /*!< (@ 0x00006C54) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN74_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN75;     /*!< (@ 0x00006C58) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN75_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN75;     /*!< (@ 0x00006C5C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN75_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN76;     /*!< (@ 0x00006C60) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN76_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN76;     /*!< (@ 0x00006C64) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN76_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN77;     /*!< (@ 0x00006C68) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN77_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN77;     /*!< (@ 0x00006C6C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN77_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN78;     /*!< (@ 0x00006C70) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN78_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN78;     /*!< (@ 0x00006C74) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN78_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN79;     /*!< (@ 0x00006C78) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN79_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN79;     /*!< (@ 0x00006C7C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN79_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN80;     /*!< (@ 0x00006C80) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN80_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN80;     /*!< (@ 0x00006C84) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN80_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN81;     /*!< (@ 0x00006C88) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN81_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN81;     /*!< (@ 0x00006C8C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN81_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN82;     /*!< (@ 0x00006C90) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN82_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN82;     /*!< (@ 0x00006C94) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN82_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN83;     /*!< (@ 0x00006C98) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN83_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN83;     /*!< (@ 0x00006C9C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN83_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN84;     /*!< (@ 0x00006CA0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN84_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN84;     /*!< (@ 0x00006CA4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN84_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN85;     /*!< (@ 0x00006CA8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN85_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN85;     /*!< (@ 0x00006CAC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN85_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN86;     /*!< (@ 0x00006CB0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN86_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN86;     /*!< (@ 0x00006CB4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN86_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN87;     /*!< (@ 0x00006CB8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN87_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN87;     /*!< (@ 0x00006CBC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN87_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN88;     /*!< (@ 0x00006CC0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN88_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN88;     /*!< (@ 0x00006CC4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN88_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN89;     /*!< (@ 0x00006CC8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN89_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN89;     /*!< (@ 0x00006CCC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN89_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN90;     /*!< (@ 0x00006CD0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN90_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN90;     /*!< (@ 0x00006CD4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN90_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN91;     /*!< (@ 0x00006CD8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN91_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN91;     /*!< (@ 0x00006CDC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN91_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN92;     /*!< (@ 0x00006CE0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN92_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN92;     /*!< (@ 0x00006CE4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN92_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN93;     /*!< (@ 0x00006CE8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN93_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN93;     /*!< (@ 0x00006CEC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN93_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN94;     /*!< (@ 0x00006CF0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN94_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN94;     /*!< (@ 0x00006CF4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN94_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN95;     /*!< (@ 0x00006CF8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN95_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN95;     /*!< (@ 0x00006CFC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN95_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN96;     /*!< (@ 0x00006D00) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN96_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN96;     /*!< (@ 0x00006D04) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN96_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN97;     /*!< (@ 0x00006D08) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN97_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN97;     /*!< (@ 0x00006D0C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN97_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN98;     /*!< (@ 0x00006D10) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN98_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN98;     /*!< (@ 0x00006D14) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN98_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN99;     /*!< (@ 0x00006D18) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN99_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN99;     /*!< (@ 0x00006D1C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN99_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN100;    /*!< (@ 0x00006D20) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN100_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN100;    /*!< (@ 0x00006D24) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN100_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN101;    /*!< (@ 0x00006D28) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN101_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN101;    /*!< (@ 0x00006D2C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN101_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN102;    /*!< (@ 0x00006D30) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN102_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN102;    /*!< (@ 0x00006D34) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN102_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN103;    /*!< (@ 0x00006D38) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN103_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN103;    /*!< (@ 0x00006D3C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN103_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN104;    /*!< (@ 0x00006D40) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN104_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN104;    /*!< (@ 0x00006D44) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN104_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN105;    /*!< (@ 0x00006D48) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN105_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN105;    /*!< (@ 0x00006D4C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN105_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN106;    /*!< (@ 0x00006D50) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN106_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN106;    /*!< (@ 0x00006D54) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN106_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN107;    /*!< (@ 0x00006D58) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN107_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN107;    /*!< (@ 0x00006D5C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN107_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN108;    /*!< (@ 0x00006D60) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN108_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN108;    /*!< (@ 0x00006D64) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN108_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN109;    /*!< (@ 0x00006D68) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN109_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN109;    /*!< (@ 0x00006D6C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN109_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN110;    /*!< (@ 0x00006D70) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN110_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN110;    /*!< (@ 0x00006D74) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN110_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN111;    /*!< (@ 0x00006D78) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN111_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN111;    /*!< (@ 0x00006D7C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN111_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN112;    /*!< (@ 0x00006D80) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN112_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN112;    /*!< (@ 0x00006D84) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN112_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN113;    /*!< (@ 0x00006D88) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN113_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN113;    /*!< (@ 0x00006D8C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN113_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN114;    /*!< (@ 0x00006D90) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN114_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN114;    /*!< (@ 0x00006D94) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN114_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN115;    /*!< (@ 0x00006D98) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN115_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN115;    /*!< (@ 0x00006D9C) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN115_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN116;    /*!< (@ 0x00006DA0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN116_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN116;    /*!< (@ 0x00006DA4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN116_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN117;    /*!< (@ 0x00006DA8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN117_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN117;    /*!< (@ 0x00006DAC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN117_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN118;    /*!< (@ 0x00006DB0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN118_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN118;    /*!< (@ 0x00006DB4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN118_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN119;    /*!< (@ 0x00006DB8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN119_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN119;    /*!< (@ 0x00006DBC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN119_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN120;    /*!< (@ 0x00006DC0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN120_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN120;    /*!< (@ 0x00006DC4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN120_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN121;    /*!< (@ 0x00006DC8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN121_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN121;    /*!< (@ 0x00006DCC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN121_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN122;    /*!< (@ 0x00006DD0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN122_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN122;    /*!< (@ 0x00006DD4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN122_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN123;    /*!< (@ 0x00006DD8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN123_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN123;    /*!< (@ 0x00006DDC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN123_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN124;    /*!< (@ 0x00006DE0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN124_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN124;    /*!< (@ 0x00006DE4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN124_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN125;    /*!< (@ 0x00006DE8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN125_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN125;    /*!< (@ 0x00006DEC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN125_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN126;    /*!< (@ 0x00006DF0) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN126_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN126;    /*!< (@ 0x00006DF4) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN126_b;
    };

    union
    {
        __IOM uint32_t FWFRPPCN127;    /*!< (@ 0x00006DF8) Forwarding Engine FRER Passed Packet Counter
                                        *                  Register i (FWFRPPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t PPC : 16;   /*!< [15..0] PPC                                                               */
            uint32_t           : 16;
        } FWFRPPCN127_b;
    };

    union
    {
        __IOM uint32_t FWFRDPCN127;    /*!< (@ 0x00006DFC) Forwarding Engine FRER Discarded Packet Counter
                                        *                  Register i (FWFRDPCNi) (i = 0 to 127)                      */

        struct
        {
            __IOM uint32_t DPC : 16;   /*!< [15..0] DPC                                                               */
            uint32_t           : 16;
        } FWFRDPCN127_b;
    };
    __IM uint32_t RESERVED261[704];

    union
    {
        __IOM uint32_t FWEIS00;          /*!< (@ 0x00007900) Forwarding Engine Error Interrupt Status Register
                                          *                  0i (FWEIS0i) (i = 0 to 2)                                  */

        struct
        {
            __IOM uint32_t LTHSPFS  : 1; /*!< [0..0] LTHSPFS                                                            */
            uint32_t                : 1;
            __IOM uint32_t LTHNTFS  : 1; /*!< [2..2] LTHNTFS                                                            */
            __IOM uint32_t LTHUFS   : 1; /*!< [3..3] LTHUFS                                                             */
            uint32_t                : 6;
            __IOM uint32_t LTWDSPFS : 1; /*!< [10..10] LTWDSPFS                                                         */
            __IOM uint32_t LTWSSPFS : 1; /*!< [11..11] LTWSSPFS                                                         */
            __IOM uint32_t LTWVSPFS : 1; /*!< [12..12] LTWVSPFS                                                         */
            __IOM uint32_t LTWNTFS  : 1; /*!< [13..13] LTWNTFS                                                          */
            __IOM uint32_t LTWSUFS  : 1; /*!< [14..14] LTWSUFS                                                          */
            __IOM uint32_t LTWDUFS  : 1; /*!< [15..15] LTWDUFS                                                          */
            __IOM uint32_t LTWVUFS  : 1; /*!< [16..16] LTWVUFS                                                          */
            __IOM uint32_t PBNTFS   : 1; /*!< [17..17] PBNTFS                                                           */
            __IOM uint32_t SMHLFS   : 1; /*!< [18..18] SMHLFS                                                           */
            __IOM uint32_t SMHMFS   : 1; /*!< [19..19] SMHMFS                                                           */
            uint32_t                : 2;
            __IOM uint32_t WMCFS    : 1; /*!< [22..22] WMCFS                                                            */
            __IOM uint32_t WMFFS    : 1; /*!< [23..23] WMFFS                                                            */
            __IOM uint32_t WMISFS   : 1; /*!< [24..24] WMISFS                                                           */
            __IOM uint32_t WMIUFS   : 1; /*!< [25..25] WMIUFS                                                           */
            __IOM uint32_t DDES     : 1; /*!< [26..26] DDES                                                             */
            uint32_t                : 1;
            __IOM uint32_t DDSES    : 1; /*!< [28..28] DDSES                                                            */
            __IOM uint32_t DDNTFS   : 1; /*!< [29..29] DDNTFS                                                           */
            uint32_t                : 2;
        } FWEIS00_b;
    };

    union
    {
        __IOM uint32_t FWEIE00;          /*!< (@ 0x00007904) Forwarding Engine Error Interrupt Enable Register
                                          *                  0i (FWEIE0i) (i = 0 to 2)                                  */

        struct
        {
            __IOM uint32_t LTHSPFE  : 1; /*!< [0..0] LTHSPFE                                                            */
            uint32_t                : 1;
            __IOM uint32_t LTHNTFE  : 1; /*!< [2..2] LTHNTFE                                                            */
            __IOM uint32_t LTHUFE   : 1; /*!< [3..3] LTHUFE                                                             */
            uint32_t                : 6;
            __IOM uint32_t LTWDSPFE : 1; /*!< [10..10] LTWDSPFE                                                         */
            __IOM uint32_t LTWSSPFE : 1; /*!< [11..11] LTWSSPFE                                                         */
            __IOM uint32_t LTWVSPFE : 1; /*!< [12..12] LTWVSPFE                                                         */
            __IOM uint32_t LTWNTFE  : 1; /*!< [13..13] LTWNTFE                                                          */
            __IOM uint32_t LTWSUFE  : 1; /*!< [14..14] LTWSUFE                                                          */
            __IOM uint32_t LTWDUFE  : 1; /*!< [15..15] LTWDUFE                                                          */
            __IOM uint32_t LTWVUFE  : 1; /*!< [16..16] LTWVUFE                                                          */
            __IOM uint32_t PBNTFE   : 1; /*!< [17..17] PBNTFE                                                           */
            __IOM uint32_t SMHLFE   : 1; /*!< [18..18] SMHLFE                                                           */
            __IOM uint32_t SMHMFE   : 1; /*!< [19..19] SMHMFE                                                           */
            uint32_t                : 2;
            __IOM uint32_t WMCFE    : 1; /*!< [22..22] WMCFE                                                            */
            __IOM uint32_t WMFFE    : 1; /*!< [23..23] WMFFE                                                            */
            __IOM uint32_t WMISFE   : 1; /*!< [24..24] WMISFE                                                           */
            __IOM uint32_t WMIUFE   : 1; /*!< [25..25] WMIUFE                                                           */
            __IOM uint32_t DDEE     : 1; /*!< [26..26] DDEE                                                             */
            __IOM uint32_t DDFEE    : 1; /*!< [27..27] DDFEE                                                            */
            __IOM uint32_t DDSEE    : 1; /*!< [28..28] DDSEE                                                            */
            __IOM uint32_t DDNTFE   : 1; /*!< [29..29] DDNTFE                                                           */
            uint32_t                : 2;
        } FWEIE00_b;
    };

    union
    {
        __IOM uint32_t FWEID00;          /*!< (@ 0x00007908) Forwarding Engine Error Interrupt Disable Register
                                          *                  0i (FWEID0i) (i = 0 to 2)                                  */

        struct
        {
            __IOM uint32_t LTHSPFD  : 1; /*!< [0..0] LTHSPFD                                                            */
            uint32_t                : 1;
            __IOM uint32_t LTHNTFD  : 1; /*!< [2..2] LTHNTFD                                                            */
            __IOM uint32_t LTHUFD   : 1; /*!< [3..3] LTHUFD                                                             */
            uint32_t                : 6;
            __IOM uint32_t LTWDSPFD : 1; /*!< [10..10] LTWDSPFD                                                         */
            __IOM uint32_t LTWSSPFD : 1; /*!< [11..11] LTWSSPFD                                                         */
            __IOM uint32_t LTWVSPFD : 1; /*!< [12..12] LTWVSPFD                                                         */
            __IOM uint32_t LTWNTFD  : 1; /*!< [13..13] LTWNTFD                                                          */
            __IOM uint32_t LTWSUFD  : 1; /*!< [14..14] LTWSUFD                                                          */
            __IOM uint32_t LTWDUFD  : 1; /*!< [15..15] LTWDUFD                                                          */
            __IOM uint32_t LTWVUFD  : 1; /*!< [16..16] LTWVUFD                                                          */
            __IOM uint32_t PBNTFD   : 1; /*!< [17..17] PBNTFD                                                           */
            __IOM uint32_t SMHLFD   : 1; /*!< [18..18] SMHLFD                                                           */
            __IOM uint32_t SMHMFD   : 1; /*!< [19..19] SMHMFD                                                           */
            uint32_t                : 2;
            __IOM uint32_t WMCFD    : 1; /*!< [22..22] WMCFD                                                            */
            __IOM uint32_t WMFFD    : 1; /*!< [23..23] WMFFD                                                            */
            __IOM uint32_t WMISFD   : 1; /*!< [24..24] WMISFD                                                           */
            __IOM uint32_t WMIUFD   : 1; /*!< [25..25] WMIUFD                                                           */
            __IOM uint32_t DDED     : 1; /*!< [26..26] DDED                                                             */
            __IOM uint32_t DDFED    : 1; /*!< [27..27] DDFED                                                            */
            __IOM uint32_t DDSED    : 1; /*!< [28..28] DDSED                                                            */
            __IOM uint32_t DDNTFD   : 1; /*!< [29..29] DDNTFD                                                           */
            uint32_t                : 2;
        } FWEID00_b;
    };
    __IM uint32_t RESERVED262;

    union
    {
        __IOM uint32_t FWEIS01;          /*!< (@ 0x00007910) Forwarding Engine Error Interrupt Status Register
                                          *                  0i (FWEIS0i) (i = 0 to 2)                                  */

        struct
        {
            __IOM uint32_t LTHSPFS  : 1; /*!< [0..0] LTHSPFS                                                            */
            uint32_t                : 1;
            __IOM uint32_t LTHNTFS  : 1; /*!< [2..2] LTHNTFS                                                            */
            __IOM uint32_t LTHUFS   : 1; /*!< [3..3] LTHUFS                                                             */
            uint32_t                : 6;
            __IOM uint32_t LTWDSPFS : 1; /*!< [10..10] LTWDSPFS                                                         */
            __IOM uint32_t LTWSSPFS : 1; /*!< [11..11] LTWSSPFS                                                         */
            __IOM uint32_t LTWVSPFS : 1; /*!< [12..12] LTWVSPFS                                                         */
            __IOM uint32_t LTWNTFS  : 1; /*!< [13..13] LTWNTFS                                                          */
            __IOM uint32_t LTWSUFS  : 1; /*!< [14..14] LTWSUFS                                                          */
            __IOM uint32_t LTWDUFS  : 1; /*!< [15..15] LTWDUFS                                                          */
            __IOM uint32_t LTWVUFS  : 1; /*!< [16..16] LTWVUFS                                                          */
            __IOM uint32_t PBNTFS   : 1; /*!< [17..17] PBNTFS                                                           */
            __IOM uint32_t SMHLFS   : 1; /*!< [18..18] SMHLFS                                                           */
            __IOM uint32_t SMHMFS   : 1; /*!< [19..19] SMHMFS                                                           */
            uint32_t                : 2;
            __IOM uint32_t WMCFS    : 1; /*!< [22..22] WMCFS                                                            */
            __IOM uint32_t WMFFS    : 1; /*!< [23..23] WMFFS                                                            */
            __IOM uint32_t WMISFS   : 1; /*!< [24..24] WMISFS                                                           */
            __IOM uint32_t WMIUFS   : 1; /*!< [25..25] WMIUFS                                                           */
            __IOM uint32_t DDES     : 1; /*!< [26..26] DDES                                                             */
            uint32_t                : 1;
            __IOM uint32_t DDSES    : 1; /*!< [28..28] DDSES                                                            */
            __IOM uint32_t DDNTFS   : 1; /*!< [29..29] DDNTFS                                                           */
            uint32_t                : 2;
        } FWEIS01_b;
    };

    union
    {
        __IOM uint32_t FWEIE01;          /*!< (@ 0x00007914) Forwarding Engine Error Interrupt Enable Register
                                          *                  0i (FWEIE0i) (i = 0 to 2)                                  */

        struct
        {
            __IOM uint32_t LTHSPFE  : 1; /*!< [0..0] LTHSPFE                                                            */
            uint32_t                : 1;
            __IOM uint32_t LTHNTFE  : 1; /*!< [2..2] LTHNTFE                                                            */
            __IOM uint32_t LTHUFE   : 1; /*!< [3..3] LTHUFE                                                             */
            uint32_t                : 6;
            __IOM uint32_t LTWDSPFE : 1; /*!< [10..10] LTWDSPFE                                                         */
            __IOM uint32_t LTWSSPFE : 1; /*!< [11..11] LTWSSPFE                                                         */
            __IOM uint32_t LTWVSPFE : 1; /*!< [12..12] LTWVSPFE                                                         */
            __IOM uint32_t LTWNTFE  : 1; /*!< [13..13] LTWNTFE                                                          */
            __IOM uint32_t LTWSUFE  : 1; /*!< [14..14] LTWSUFE                                                          */
            __IOM uint32_t LTWDUFE  : 1; /*!< [15..15] LTWDUFE                                                          */
            __IOM uint32_t LTWVUFE  : 1; /*!< [16..16] LTWVUFE                                                          */
            __IOM uint32_t PBNTFE   : 1; /*!< [17..17] PBNTFE                                                           */
            __IOM uint32_t SMHLFE   : 1; /*!< [18..18] SMHLFE                                                           */
            __IOM uint32_t SMHMFE   : 1; /*!< [19..19] SMHMFE                                                           */
            uint32_t                : 2;
            __IOM uint32_t WMCFE    : 1; /*!< [22..22] WMCFE                                                            */
            __IOM uint32_t WMFFE    : 1; /*!< [23..23] WMFFE                                                            */
            __IOM uint32_t WMISFE   : 1; /*!< [24..24] WMISFE                                                           */
            __IOM uint32_t WMIUFE   : 1; /*!< [25..25] WMIUFE                                                           */
            __IOM uint32_t DDEE     : 1; /*!< [26..26] DDEE                                                             */
            __IOM uint32_t DDFEE    : 1; /*!< [27..27] DDFEE                                                            */
            __IOM uint32_t DDSEE    : 1; /*!< [28..28] DDSEE                                                            */
            __IOM uint32_t DDNTFE   : 1; /*!< [29..29] DDNTFE                                                           */
            uint32_t                : 2;
        } FWEIE01_b;
    };

    union
    {
        __IOM uint32_t FWEID01;          /*!< (@ 0x00007918) Forwarding Engine Error Interrupt Disable Register
                                          *                  0i (FWEID0i) (i = 0 to 2)                                  */

        struct
        {
            __IOM uint32_t LTHSPFD  : 1; /*!< [0..0] LTHSPFD                                                            */
            uint32_t                : 1;
            __IOM uint32_t LTHNTFD  : 1; /*!< [2..2] LTHNTFD                                                            */
            __IOM uint32_t LTHUFD   : 1; /*!< [3..3] LTHUFD                                                             */
            uint32_t                : 6;
            __IOM uint32_t LTWDSPFD : 1; /*!< [10..10] LTWDSPFD                                                         */
            __IOM uint32_t LTWSSPFD : 1; /*!< [11..11] LTWSSPFD                                                         */
            __IOM uint32_t LTWVSPFD : 1; /*!< [12..12] LTWVSPFD                                                         */
            __IOM uint32_t LTWNTFD  : 1; /*!< [13..13] LTWNTFD                                                          */
            __IOM uint32_t LTWSUFD  : 1; /*!< [14..14] LTWSUFD                                                          */
            __IOM uint32_t LTWDUFD  : 1; /*!< [15..15] LTWDUFD                                                          */
            __IOM uint32_t LTWVUFD  : 1; /*!< [16..16] LTWVUFD                                                          */
            __IOM uint32_t PBNTFD   : 1; /*!< [17..17] PBNTFD                                                           */
            __IOM uint32_t SMHLFD   : 1; /*!< [18..18] SMHLFD                                                           */
            __IOM uint32_t SMHMFD   : 1; /*!< [19..19] SMHMFD                                                           */
            uint32_t                : 2;
            __IOM uint32_t WMCFD    : 1; /*!< [22..22] WMCFD                                                            */
            __IOM uint32_t WMFFD    : 1; /*!< [23..23] WMFFD                                                            */
            __IOM uint32_t WMISFD   : 1; /*!< [24..24] WMISFD                                                           */
            __IOM uint32_t WMIUFD   : 1; /*!< [25..25] WMIUFD                                                           */
            __IOM uint32_t DDED     : 1; /*!< [26..26] DDED                                                             */
            __IOM uint32_t DDFED    : 1; /*!< [27..27] DDFED                                                            */
            __IOM uint32_t DDSED    : 1; /*!< [28..28] DDSED                                                            */
            __IOM uint32_t DDNTFD   : 1; /*!< [29..29] DDNTFD                                                           */
            uint32_t                : 2;
        } FWEID01_b;
    };
    __IM uint32_t RESERVED263;

    union
    {
        __IOM uint32_t FWEIS02;          /*!< (@ 0x00007920) Forwarding Engine Error Interrupt Status Register
                                          *                  0i (FWEIS0i) (i = 0 to 2)                                  */

        struct
        {
            __IOM uint32_t LTHSPFS  : 1; /*!< [0..0] LTHSPFS                                                            */
            uint32_t                : 1;
            __IOM uint32_t LTHNTFS  : 1; /*!< [2..2] LTHNTFS                                                            */
            __IOM uint32_t LTHUFS   : 1; /*!< [3..3] LTHUFS                                                             */
            uint32_t                : 6;
            __IOM uint32_t LTWDSPFS : 1; /*!< [10..10] LTWDSPFS                                                         */
            __IOM uint32_t LTWSSPFS : 1; /*!< [11..11] LTWSSPFS                                                         */
            __IOM uint32_t LTWVSPFS : 1; /*!< [12..12] LTWVSPFS                                                         */
            __IOM uint32_t LTWNTFS  : 1; /*!< [13..13] LTWNTFS                                                          */
            __IOM uint32_t LTWSUFS  : 1; /*!< [14..14] LTWSUFS                                                          */
            __IOM uint32_t LTWDUFS  : 1; /*!< [15..15] LTWDUFS                                                          */
            __IOM uint32_t LTWVUFS  : 1; /*!< [16..16] LTWVUFS                                                          */
            __IOM uint32_t PBNTFS   : 1; /*!< [17..17] PBNTFS                                                           */
            __IOM uint32_t SMHLFS   : 1; /*!< [18..18] SMHLFS                                                           */
            __IOM uint32_t SMHMFS   : 1; /*!< [19..19] SMHMFS                                                           */
            uint32_t                : 2;
            __IOM uint32_t WMCFS    : 1; /*!< [22..22] WMCFS                                                            */
            __IOM uint32_t WMFFS    : 1; /*!< [23..23] WMFFS                                                            */
            __IOM uint32_t WMISFS   : 1; /*!< [24..24] WMISFS                                                           */
            __IOM uint32_t WMIUFS   : 1; /*!< [25..25] WMIUFS                                                           */
            __IOM uint32_t DDES     : 1; /*!< [26..26] DDES                                                             */
            uint32_t                : 1;
            __IOM uint32_t DDSES    : 1; /*!< [28..28] DDSES                                                            */
            __IOM uint32_t DDNTFS   : 1; /*!< [29..29] DDNTFS                                                           */
            uint32_t                : 2;
        } FWEIS02_b;
    };

    union
    {
        __IOM uint32_t FWEIE02;          /*!< (@ 0x00007924) Forwarding Engine Error Interrupt Enable Register
                                          *                  0i (FWEIE0i) (i = 0 to 2)                                  */

        struct
        {
            __IOM uint32_t LTHSPFE  : 1; /*!< [0..0] LTHSPFE                                                            */
            uint32_t                : 1;
            __IOM uint32_t LTHNTFE  : 1; /*!< [2..2] LTHNTFE                                                            */
            __IOM uint32_t LTHUFE   : 1; /*!< [3..3] LTHUFE                                                             */
            uint32_t                : 6;
            __IOM uint32_t LTWDSPFE : 1; /*!< [10..10] LTWDSPFE                                                         */
            __IOM uint32_t LTWSSPFE : 1; /*!< [11..11] LTWSSPFE                                                         */
            __IOM uint32_t LTWVSPFE : 1; /*!< [12..12] LTWVSPFE                                                         */
            __IOM uint32_t LTWNTFE  : 1; /*!< [13..13] LTWNTFE                                                          */
            __IOM uint32_t LTWSUFE  : 1; /*!< [14..14] LTWSUFE                                                          */
            __IOM uint32_t LTWDUFE  : 1; /*!< [15..15] LTWDUFE                                                          */
            __IOM uint32_t LTWVUFE  : 1; /*!< [16..16] LTWVUFE                                                          */
            __IOM uint32_t PBNTFE   : 1; /*!< [17..17] PBNTFE                                                           */
            __IOM uint32_t SMHLFE   : 1; /*!< [18..18] SMHLFE                                                           */
            __IOM uint32_t SMHMFE   : 1; /*!< [19..19] SMHMFE                                                           */
            uint32_t                : 2;
            __IOM uint32_t WMCFE    : 1; /*!< [22..22] WMCFE                                                            */
            __IOM uint32_t WMFFE    : 1; /*!< [23..23] WMFFE                                                            */
            __IOM uint32_t WMISFE   : 1; /*!< [24..24] WMISFE                                                           */
            __IOM uint32_t WMIUFE   : 1; /*!< [25..25] WMIUFE                                                           */
            __IOM uint32_t DDEE     : 1; /*!< [26..26] DDEE                                                             */
            __IOM uint32_t DDFEE    : 1; /*!< [27..27] DDFEE                                                            */
            __IOM uint32_t DDSEE    : 1; /*!< [28..28] DDSEE                                                            */
            __IOM uint32_t DDNTFE   : 1; /*!< [29..29] DDNTFE                                                           */
            uint32_t                : 2;
        } FWEIE02_b;
    };

    union
    {
        __IOM uint32_t FWEID02;          /*!< (@ 0x00007928) Forwarding Engine Error Interrupt Disable Register
                                          *                  0i (FWEID0i) (i = 0 to 2)                                  */

        struct
        {
            __IOM uint32_t LTHSPFD  : 1; /*!< [0..0] LTHSPFD                                                            */
            uint32_t                : 1;
            __IOM uint32_t LTHNTFD  : 1; /*!< [2..2] LTHNTFD                                                            */
            __IOM uint32_t LTHUFD   : 1; /*!< [3..3] LTHUFD                                                             */
            uint32_t                : 6;
            __IOM uint32_t LTWDSPFD : 1; /*!< [10..10] LTWDSPFD                                                         */
            __IOM uint32_t LTWSSPFD : 1; /*!< [11..11] LTWSSPFD                                                         */
            __IOM uint32_t LTWVSPFD : 1; /*!< [12..12] LTWVSPFD                                                         */
            __IOM uint32_t LTWNTFD  : 1; /*!< [13..13] LTWNTFD                                                          */
            __IOM uint32_t LTWSUFD  : 1; /*!< [14..14] LTWSUFD                                                          */
            __IOM uint32_t LTWDUFD  : 1; /*!< [15..15] LTWDUFD                                                          */
            __IOM uint32_t LTWVUFD  : 1; /*!< [16..16] LTWVUFD                                                          */
            __IOM uint32_t PBNTFD   : 1; /*!< [17..17] PBNTFD                                                           */
            __IOM uint32_t SMHLFD   : 1; /*!< [18..18] SMHLFD                                                           */
            __IOM uint32_t SMHMFD   : 1; /*!< [19..19] SMHMFD                                                           */
            uint32_t                : 2;
            __IOM uint32_t WMCFD    : 1; /*!< [22..22] WMCFD                                                            */
            __IOM uint32_t WMFFD    : 1; /*!< [23..23] WMFFD                                                            */
            __IOM uint32_t WMISFD   : 1; /*!< [24..24] WMISFD                                                           */
            __IOM uint32_t WMIUFD   : 1; /*!< [25..25] WMIUFD                                                           */
            __IOM uint32_t DDED     : 1; /*!< [26..26] DDED                                                             */
            __IOM uint32_t DDFED    : 1; /*!< [27..27] DDFED                                                            */
            __IOM uint32_t DDSED    : 1; /*!< [28..28] DDSED                                                            */
            __IOM uint32_t DDNTFD   : 1; /*!< [29..29] DDNTFD                                                           */
            uint32_t                : 2;
        } FWEID02_b;
    };
    __IM uint32_t RESERVED264[53];

    union
    {
        __IOM uint32_t FWEIS1;           /*!< (@ 0x00007A00) Forwarding Engine Error Interrupt Status Register
                                          *                  1 (FWEIS1)                                                 */

        struct
        {
            __IOM uint32_t LTHTEES  : 1; /*!< [0..0] LTHTEES                                                            */
            __IOM uint32_t LTHTSES  : 1; /*!< [1..1] LTHTSES                                                            */
            uint32_t                : 2;
            __IOM uint32_t MACTEES  : 1; /*!< [4..4] MACTEES                                                            */
            __IOM uint32_t MACTSES  : 1; /*!< [5..5] MACTSES                                                            */
            __IOM uint32_t VLANTEES : 1; /*!< [6..6] VLANTEES                                                           */
            __IOM uint32_t VLANTSES : 1; /*!< [7..7] VLANTSES                                                           */
            __IOM uint32_t L23UEES  : 1; /*!< [8..8] L23UEES                                                            */
            uint32_t                : 7;
            __IOM uint32_t AREES    : 1; /*!< [16..16] AREES                                                            */
            __IOM uint32_t FTEES    : 1; /*!< [17..17] FTEES                                                            */
            uint32_t                : 14;
        } FWEIS1_b;
    };

    union
    {
        __IOM uint32_t FWEIE1;           /*!< (@ 0x00007A04) Forwarding Engine Error Interrupt Enable Register
                                          *                  1 (FWEIE1)                                                 */

        struct
        {
            __IOM uint32_t LTHTEEE  : 1; /*!< [0..0] LTHTEEE                                                            */
            __IOM uint32_t LTHTSEE  : 1; /*!< [1..1] LTHTSEE                                                            */
            uint32_t                : 2;
            __IOM uint32_t MACTEEE  : 1; /*!< [4..4] MACTEEE                                                            */
            __IOM uint32_t MACTSEE  : 1; /*!< [5..5] MACTSEE                                                            */
            __IOM uint32_t VLANTEEE : 1; /*!< [6..6] VLANTEEE                                                           */
            __IOM uint32_t VLANTSEE : 1; /*!< [7..7] VLANTSEE                                                           */
            __IOM uint32_t L23UEEE  : 1; /*!< [8..8] L23UEEE                                                            */
            uint32_t                : 7;
            __IOM uint32_t AREEE    : 1; /*!< [16..16] AREEE                                                            */
            __IOM uint32_t FTEEE    : 1; /*!< [17..17] FTEEE                                                            */
            uint32_t                : 14;
        } FWEIE1_b;
    };

    union
    {
        __IOM uint32_t FWEID1;           /*!< (@ 0x00007A08) Forwarding Engine Error Interrupt Disable Register
                                          *                  1 (FWEID1)                                                 */

        struct
        {
            __IOM uint32_t LTHTEED  : 1; /*!< [0..0] LTHTEED                                                            */
            __IOM uint32_t LTHTSED  : 1; /*!< [1..1] LTHTSED                                                            */
            uint32_t                : 2;
            __IOM uint32_t MACTEED  : 1; /*!< [4..4] MACTEED                                                            */
            __IOM uint32_t MACTSED  : 1; /*!< [5..5] MACTSED                                                            */
            __IOM uint32_t VLANTEED : 1; /*!< [6..6] VLANTEED                                                           */
            __IOM uint32_t VLANTSED : 1; /*!< [7..7] VLANTSED                                                           */
            __IOM uint32_t L23UEED  : 1; /*!< [8..8] L23UEED                                                            */
            uint32_t                : 7;
            __IOM uint32_t AREED    : 1; /*!< [16..16] AREED                                                            */
            __IOM uint32_t FTEED    : 1; /*!< [17..17] FTEED                                                            */
            uint32_t                : 14;
        } FWEID1_b;
    };
    __IM uint32_t RESERVED265;

    union
    {
        __IOM uint32_t FWEIS2;         /*!< (@ 0x00007A10) Forwarding Engine Error Interrupt Status Register
                                        *                  2 (FWEIS2)                                                 */

        struct
        {
            __IOM uint32_t PMFS0  : 1; /*!< [0..0] PMFS0                                                              */
            __IOM uint32_t PMFS1  : 1; /*!< [1..1] PMFS1                                                              */
            __IOM uint32_t PMFS2  : 1; /*!< [2..2] PMFS2                                                              */
            __IOM uint32_t PMFS3  : 1; /*!< [3..3] PMFS3                                                              */
            __IOM uint32_t PMFS4  : 1; /*!< [4..4] PMFS4                                                              */
            __IOM uint32_t PMFS5  : 1; /*!< [5..5] PMFS5                                                              */
            __IOM uint32_t PMFS6  : 1; /*!< [6..6] PMFS6                                                              */
            __IOM uint32_t PMFS7  : 1; /*!< [7..7] PMFS7                                                              */
            __IOM uint32_t PMFS8  : 1; /*!< [8..8] PMFS8                                                              */
            __IOM uint32_t PMFS9  : 1; /*!< [9..9] PMFS9                                                              */
            __IOM uint32_t PMFS10 : 1; /*!< [10..10] PMFS10                                                           */
            __IOM uint32_t PMFS11 : 1; /*!< [11..11] PMFS11                                                           */
            __IOM uint32_t PMFS12 : 1; /*!< [12..12] PMFS12                                                           */
            __IOM uint32_t PMFS13 : 1; /*!< [13..13] PMFS13                                                           */
            __IOM uint32_t PMFS14 : 1; /*!< [14..14] PMFS14                                                           */
            __IOM uint32_t PMFS15 : 1; /*!< [15..15] PMFS15                                                           */
            uint32_t              : 16;
        } FWEIS2_b;
    };

    union
    {
        __IOM uint32_t FWEIE2;         /*!< (@ 0x00007A14) Forwarding Engine Error Enable Status Register
                                        *                  2 (FWEIE2)                                                 */

        struct
        {
            __IOM uint32_t PMFE0  : 1; /*!< [0..0] PMFE0                                                              */
            __IOM uint32_t PMFE1  : 1; /*!< [1..1] PMFE1                                                              */
            __IOM uint32_t PMFE2  : 1; /*!< [2..2] PMFE2                                                              */
            __IOM uint32_t PMFE3  : 1; /*!< [3..3] PMFE3                                                              */
            __IOM uint32_t PMFE4  : 1; /*!< [4..4] PMFE4                                                              */
            __IOM uint32_t PMFE5  : 1; /*!< [5..5] PMFE5                                                              */
            __IOM uint32_t PMFE6  : 1; /*!< [6..6] PMFE6                                                              */
            __IOM uint32_t PMFE7  : 1; /*!< [7..7] PMFE7                                                              */
            __IOM uint32_t PMFE8  : 1; /*!< [8..8] PMFE8                                                              */
            __IOM uint32_t PMFE9  : 1; /*!< [9..9] PMFE9                                                              */
            __IOM uint32_t PMFE10 : 1; /*!< [10..10] PMFE10                                                           */
            __IOM uint32_t PMFE11 : 1; /*!< [11..11] PMFE11                                                           */
            __IOM uint32_t PMFE12 : 1; /*!< [12..12] PMFE12                                                           */
            __IOM uint32_t PMFE13 : 1; /*!< [13..13] PMFE13                                                           */
            __IOM uint32_t PMFE14 : 1; /*!< [14..14] PMFE14                                                           */
            __IOM uint32_t PMFE15 : 1; /*!< [15..15] PMFE15                                                           */
            uint32_t              : 16;
        } FWEIE2_b;
    };

    union
    {
        __IOM uint32_t FWEID2;         /*!< (@ 0x00007A18) Forwarding Engine Error Disable Status Register
                                        *                  2 (FWEID2)                                                 */

        struct
        {
            __IOM uint32_t PMFD0  : 1; /*!< [0..0] PMFD0                                                              */
            __IOM uint32_t PMFD1  : 1; /*!< [1..1] PMFD1                                                              */
            __IOM uint32_t PMFD2  : 1; /*!< [2..2] PMFD2                                                              */
            __IOM uint32_t PMFD3  : 1; /*!< [3..3] PMFD3                                                              */
            __IOM uint32_t PMFD4  : 1; /*!< [4..4] PMFD4                                                              */
            __IOM uint32_t PMFD5  : 1; /*!< [5..5] PMFD5                                                              */
            __IOM uint32_t PMFD6  : 1; /*!< [6..6] PMFD6                                                              */
            __IOM uint32_t PMFD7  : 1; /*!< [7..7] PMFD7                                                              */
            __IOM uint32_t PMFD8  : 1; /*!< [8..8] PMFD8                                                              */
            __IOM uint32_t PMFD9  : 1; /*!< [9..9] PMFD9                                                              */
            __IOM uint32_t PMFD10 : 1; /*!< [10..10] PMFD10                                                           */
            __IOM uint32_t PMFD11 : 1; /*!< [11..11] PMFD11                                                           */
            __IOM uint32_t PMFD12 : 1; /*!< [12..12] PMFD12                                                           */
            __IOM uint32_t PMFD13 : 1; /*!< [13..13] PMFD13                                                           */
            __IOM uint32_t PMFD14 : 1; /*!< [14..14] PMFD14                                                           */
            __IOM uint32_t PMFD15 : 1; /*!< [15..15] PMFD15                                                           */
            uint32_t              : 16;
        } FWEID2_b;
    };
    __IM uint32_t RESERVED266[9];

    union
    {
        __IOM uint32_t FWEIS5;          /*!< (@ 0x00007A40) Forwarding Engine Error Interrupt Status Register
                                         *                  5 (FWEIS5)                                                 */

        struct
        {
            __IOM uint32_t PMRFS0  : 1; /*!< [0..0] PMRFS0                                                             */
            __IOM uint32_t PMRFS1  : 1; /*!< [1..1] PMRFS1                                                             */
            __IOM uint32_t PMRFS2  : 1; /*!< [2..2] PMRFS2                                                             */
            __IOM uint32_t PMRFS3  : 1; /*!< [3..3] PMRFS3                                                             */
            __IOM uint32_t PMRFS4  : 1; /*!< [4..4] PMRFS4                                                             */
            __IOM uint32_t PMRFS5  : 1; /*!< [5..5] PMRFS5                                                             */
            __IOM uint32_t PMRFS6  : 1; /*!< [6..6] PMRFS6                                                             */
            __IOM uint32_t PMRFS7  : 1; /*!< [7..7] PMRFS7                                                             */
            __IOM uint32_t PMRFS8  : 1; /*!< [8..8] PMRFS8                                                             */
            __IOM uint32_t PMRFS9  : 1; /*!< [9..9] PMRFS9                                                             */
            __IOM uint32_t PMRFS10 : 1; /*!< [10..10] PMRFS10                                                          */
            __IOM uint32_t PMRFS11 : 1; /*!< [11..11] PMRFS11                                                          */
            __IOM uint32_t PMRFS12 : 1; /*!< [12..12] PMRFS12                                                          */
            __IOM uint32_t PMRFS13 : 1; /*!< [13..13] PMRFS13                                                          */
            __IOM uint32_t PMRFS14 : 1; /*!< [14..14] PMRFS14                                                          */
            __IOM uint32_t PMRFS15 : 1; /*!< [15..15] PMRFS15                                                          */
            __IOM uint32_t PMRFS16 : 1; /*!< [16..16] PMRFS16                                                          */
            __IOM uint32_t PMRFS17 : 1; /*!< [17..17] PMRFS17                                                          */
            __IOM uint32_t PMRFS18 : 1; /*!< [18..18] PMRFS18                                                          */
            __IOM uint32_t PMRFS19 : 1; /*!< [19..19] PMRFS19                                                          */
            __IOM uint32_t PMRFS20 : 1; /*!< [20..20] PMRFS20                                                          */
            __IOM uint32_t PMRFS21 : 1; /*!< [21..21] PMRFS21                                                          */
            __IOM uint32_t PMRFS22 : 1; /*!< [22..22] PMRFS22                                                          */
            __IOM uint32_t PMRFS23 : 1; /*!< [23..23] PMRFS23                                                          */
            __IOM uint32_t PMRFS24 : 1; /*!< [24..24] PMRFS24                                                          */
            __IOM uint32_t PMRFS25 : 1; /*!< [25..25] PMRFS25                                                          */
            __IOM uint32_t PMRFS26 : 1; /*!< [26..26] PMRFS26                                                          */
            __IOM uint32_t PMRFS27 : 1; /*!< [27..27] PMRFS27                                                          */
            __IOM uint32_t PMRFS28 : 1; /*!< [28..28] PMRFS28                                                          */
            __IOM uint32_t PMRFS29 : 1; /*!< [29..29] PMRFS29                                                          */
            __IOM uint32_t PMRFS30 : 1; /*!< [30..30] PMRFS30                                                          */
            __IOM uint32_t PMRFS31 : 1; /*!< [31..31] PMRFS31                                                          */
        } FWEIS5_b;
    };

    union
    {
        __IOM uint32_t FWEIE5;          /*!< (@ 0x00007A44) Forwarding Engine Error Enable Status Register
                                         *                  5 (FWEIE5)                                                 */

        struct
        {
            __IOM uint32_t PMRFE0  : 1; /*!< [0..0] PMRFE0                                                             */
            __IOM uint32_t PMRFE1  : 1; /*!< [1..1] PMRFE1                                                             */
            __IOM uint32_t PMRFE2  : 1; /*!< [2..2] PMRFE2                                                             */
            __IOM uint32_t PMRFE3  : 1; /*!< [3..3] PMRFE3                                                             */
            __IOM uint32_t PMRFE4  : 1; /*!< [4..4] PMRFE4                                                             */
            __IOM uint32_t PMRFE5  : 1; /*!< [5..5] PMRFE5                                                             */
            __IOM uint32_t PMRFE6  : 1; /*!< [6..6] PMRFE6                                                             */
            __IOM uint32_t PMRFE7  : 1; /*!< [7..7] PMRFE7                                                             */
            __IOM uint32_t PMRFE8  : 1; /*!< [8..8] PMRFE8                                                             */
            __IOM uint32_t PMRFE9  : 1; /*!< [9..9] PMRFE9                                                             */
            __IOM uint32_t PMRFE10 : 1; /*!< [10..10] PMRFE10                                                          */
            __IOM uint32_t PMRFE11 : 1; /*!< [11..11] PMRFE11                                                          */
            __IOM uint32_t PMRFE12 : 1; /*!< [12..12] PMRFE12                                                          */
            __IOM uint32_t PMRFE13 : 1; /*!< [13..13] PMRFE13                                                          */
            __IOM uint32_t PMRFE14 : 1; /*!< [14..14] PMRFE14                                                          */
            __IOM uint32_t PMRFE15 : 1; /*!< [15..15] PMRFE15                                                          */
            __IOM uint32_t PMRFE16 : 1; /*!< [16..16] PMRFE16                                                          */
            __IOM uint32_t PMRFE17 : 1; /*!< [17..17] PMRFE17                                                          */
            __IOM uint32_t PMRFE18 : 1; /*!< [18..18] PMRFE18                                                          */
            __IOM uint32_t PMRFE19 : 1; /*!< [19..19] PMRFE19                                                          */
            __IOM uint32_t PMRFE20 : 1; /*!< [20..20] PMRFE20                                                          */
            __IOM uint32_t PMRFE21 : 1; /*!< [21..21] PMRFE21                                                          */
            __IOM uint32_t PMRFE22 : 1; /*!< [22..22] PMRFE22                                                          */
            __IOM uint32_t PMRFE23 : 1; /*!< [23..23] PMRFE23                                                          */
            __IOM uint32_t PMRFE24 : 1; /*!< [24..24] PMRFE24                                                          */
            __IOM uint32_t PMRFE25 : 1; /*!< [25..25] PMRFE25                                                          */
            __IOM uint32_t PMRFE26 : 1; /*!< [26..26] PMRFE26                                                          */
            __IOM uint32_t PMRFE27 : 1; /*!< [27..27] PMRFE27                                                          */
            __IOM uint32_t PMRFE28 : 1; /*!< [28..28] PMRFE28                                                          */
            __IOM uint32_t PMRFE29 : 1; /*!< [29..29] PMRFE29                                                          */
            __IOM uint32_t PMRFE30 : 1; /*!< [30..30] PMRFE30                                                          */
            __IOM uint32_t PMRFE31 : 1; /*!< [31..31] PMRFE31                                                          */
        } FWEIE5_b;
    };

    union
    {
        __IOM uint32_t FWEID5;          /*!< (@ 0x00007A48) Forwarding Engine Error Disable Status Register
                                         *                  5 (FWEID5)                                                 */

        struct
        {
            __IOM uint32_t PMRFD0  : 1; /*!< [0..0] PMRFD0                                                             */
            __IOM uint32_t PMRFD1  : 1; /*!< [1..1] PMRFD1                                                             */
            __IOM uint32_t PMRFD2  : 1; /*!< [2..2] PMRFD2                                                             */
            __IOM uint32_t PMRFD3  : 1; /*!< [3..3] PMRFD3                                                             */
            __IOM uint32_t PMRFD4  : 1; /*!< [4..4] PMRFD4                                                             */
            __IOM uint32_t PMRFD5  : 1; /*!< [5..5] PMRFD5                                                             */
            __IOM uint32_t PMRFD6  : 1; /*!< [6..6] PMRFD6                                                             */
            __IOM uint32_t PMRFD7  : 1; /*!< [7..7] PMRFD7                                                             */
            __IOM uint32_t PMRFD8  : 1; /*!< [8..8] PMRFD8                                                             */
            __IOM uint32_t PMRFD9  : 1; /*!< [9..9] PMRFD9                                                             */
            __IOM uint32_t PMRFD10 : 1; /*!< [10..10] PMRFD10                                                          */
            __IOM uint32_t PMRFD11 : 1; /*!< [11..11] PMRFD11                                                          */
            __IOM uint32_t PMRFD12 : 1; /*!< [12..12] PMRFD12                                                          */
            __IOM uint32_t PMRFD13 : 1; /*!< [13..13] PMRFD13                                                          */
            __IOM uint32_t PMRFD14 : 1; /*!< [14..14] PMRFD14                                                          */
            __IOM uint32_t PMRFD15 : 1; /*!< [15..15] PMRFD15                                                          */
            __IOM uint32_t PMRFD16 : 1; /*!< [16..16] PMRFD16                                                          */
            __IOM uint32_t PMRFD17 : 1; /*!< [17..17] PMRFD17                                                          */
            __IOM uint32_t PMRFD18 : 1; /*!< [18..18] PMRFD18                                                          */
            __IOM uint32_t PMRFD19 : 1; /*!< [19..19] PMRFD19                                                          */
            __IOM uint32_t PMRFD20 : 1; /*!< [20..20] PMRFD20                                                          */
            __IOM uint32_t PMRFD21 : 1; /*!< [21..21] PMRFD21                                                          */
            __IOM uint32_t PMRFD22 : 1; /*!< [22..22] PMRFD22                                                          */
            __IOM uint32_t PMRFD23 : 1; /*!< [23..23] PMRFD23                                                          */
            __IOM uint32_t PMRFD24 : 1; /*!< [24..24] PMRFD24                                                          */
            __IOM uint32_t PMRFD25 : 1; /*!< [25..25] PMRFD25                                                          */
            __IOM uint32_t PMRFD26 : 1; /*!< [26..26] PMRFD26                                                          */
            __IOM uint32_t PMRFD27 : 1; /*!< [27..27] PMRFD27                                                          */
            __IOM uint32_t PMRFD28 : 1; /*!< [28..28] PMRFD28                                                          */
            __IOM uint32_t PMRFD29 : 1; /*!< [29..29] PMRFD29                                                          */
            __IOM uint32_t PMRFD30 : 1; /*!< [30..30] PMRFD30                                                          */
            __IOM uint32_t PMRFD31 : 1; /*!< [31..31] PMRFD31                                                          */
        } FWEID5_b;
    };
    __IM uint32_t RESERVED267;

    union
    {
        __IOM uint32_t FWEIS60;        /*!< (@ 0x00007A50) Forwarding Engine Error Interrupt Status Register
                                        *                  60 (FWEIS60)                                               */

        struct
        {
            __IOM uint32_t FFS96  : 1; /*!< [0..0] FFS96                                                              */
            __IOM uint32_t FFS97  : 1; /*!< [1..1] FFS97                                                              */
            __IOM uint32_t FFS98  : 1; /*!< [2..2] FFS98                                                              */
            __IOM uint32_t FFS99  : 1; /*!< [3..3] FFS99                                                              */
            __IOM uint32_t FFS100 : 1; /*!< [4..4] FFS100                                                             */
            __IOM uint32_t FFS101 : 1; /*!< [5..5] FFS101                                                             */
            __IOM uint32_t FFS102 : 1; /*!< [6..6] FFS102                                                             */
            __IOM uint32_t FFS103 : 1; /*!< [7..7] FFS103                                                             */
            __IOM uint32_t FFS104 : 1; /*!< [8..8] FFS104                                                             */
            __IOM uint32_t FFS105 : 1; /*!< [9..9] FFS105                                                             */
            __IOM uint32_t FFS106 : 1; /*!< [10..10] FFS106                                                           */
            __IOM uint32_t FFS107 : 1; /*!< [11..11] FFS107                                                           */
            __IOM uint32_t FFS108 : 1; /*!< [12..12] FFS108                                                           */
            __IOM uint32_t FFS109 : 1; /*!< [13..13] FFS109                                                           */
            __IOM uint32_t FFS110 : 1; /*!< [14..14] FFS110                                                           */
            __IOM uint32_t FFS111 : 1; /*!< [15..15] FFS111                                                           */
            __IOM uint32_t FFS112 : 1; /*!< [16..16] FFS112                                                           */
            __IOM uint32_t FFS113 : 1; /*!< [17..17] FFS113                                                           */
            __IOM uint32_t FFS114 : 1; /*!< [18..18] FFS114                                                           */
            __IOM uint32_t FFS115 : 1; /*!< [19..19] FFS115                                                           */
            __IOM uint32_t FFS116 : 1; /*!< [20..20] FFS116                                                           */
            __IOM uint32_t FFS117 : 1; /*!< [21..21] FFS117                                                           */
            __IOM uint32_t FFS118 : 1; /*!< [22..22] FFS118                                                           */
            __IOM uint32_t FFS119 : 1; /*!< [23..23] FFS119                                                           */
            __IOM uint32_t FFS120 : 1; /*!< [24..24] FFS120                                                           */
            __IOM uint32_t FFS121 : 1; /*!< [25..25] FFS121                                                           */
            __IOM uint32_t FFS122 : 1; /*!< [26..26] FFS122                                                           */
            __IOM uint32_t FFS123 : 1; /*!< [27..27] FFS123                                                           */
            __IOM uint32_t FFS124 : 1; /*!< [28..28] FFS124                                                           */
            __IOM uint32_t FFS125 : 1; /*!< [29..29] FFS125                                                           */
            __IOM uint32_t FFS126 : 1; /*!< [30..30] FFS126                                                           */
            __IOM uint32_t FFS127 : 1; /*!< [31..31] FFS127                                                           */
        } FWEIS60_b;
    };

    union
    {
        __IOM uint32_t FWEIE60;        /*!< (@ 0x00007A54) Forwarding Engine Error Interrupt Enable Register
                                        *                  60 (FWEIE60)                                               */

        struct
        {
            __IOM uint32_t FFE96  : 1; /*!< [0..0] FFE96                                                              */
            __IOM uint32_t FFE97  : 1; /*!< [1..1] FFE97                                                              */
            __IOM uint32_t FFE98  : 1; /*!< [2..2] FFE98                                                              */
            __IOM uint32_t FFE99  : 1; /*!< [3..3] FFE99                                                              */
            __IOM uint32_t FFE100 : 1; /*!< [4..4] FFE100                                                             */
            __IOM uint32_t FFE101 : 1; /*!< [5..5] FFE101                                                             */
            __IOM uint32_t FFE102 : 1; /*!< [6..6] FFE102                                                             */
            __IOM uint32_t FFE103 : 1; /*!< [7..7] FFE103                                                             */
            __IOM uint32_t FFE104 : 1; /*!< [8..8] FFE104                                                             */
            __IOM uint32_t FFE105 : 1; /*!< [9..9] FFE105                                                             */
            __IOM uint32_t FFE106 : 1; /*!< [10..10] FFE106                                                           */
            __IOM uint32_t FFE107 : 1; /*!< [11..11] FFE107                                                           */
            __IOM uint32_t FFE108 : 1; /*!< [12..12] FFE108                                                           */
            __IOM uint32_t FFE109 : 1; /*!< [13..13] FFE109                                                           */
            __IOM uint32_t FFE110 : 1; /*!< [14..14] FFE110                                                           */
            __IOM uint32_t FFE111 : 1; /*!< [15..15] FFE111                                                           */
            __IOM uint32_t FFE112 : 1; /*!< [16..16] FFE112                                                           */
            __IOM uint32_t FFE113 : 1; /*!< [17..17] FFE113                                                           */
            __IOM uint32_t FFE114 : 1; /*!< [18..18] FFE114                                                           */
            __IOM uint32_t FFE115 : 1; /*!< [19..19] FFE115                                                           */
            __IOM uint32_t FFE116 : 1; /*!< [20..20] FFE116                                                           */
            __IOM uint32_t FFE117 : 1; /*!< [21..21] FFE117                                                           */
            __IOM uint32_t FFE118 : 1; /*!< [22..22] FFE118                                                           */
            __IOM uint32_t FFE119 : 1; /*!< [23..23] FFE119                                                           */
            __IOM uint32_t FFE120 : 1; /*!< [24..24] FFE120                                                           */
            __IOM uint32_t FFE121 : 1; /*!< [25..25] FFE121                                                           */
            __IOM uint32_t FFE122 : 1; /*!< [26..26] FFE122                                                           */
            __IOM uint32_t FFE123 : 1; /*!< [27..27] FFE123                                                           */
            __IOM uint32_t FFE124 : 1; /*!< [28..28] FFE124                                                           */
            __IOM uint32_t FFE125 : 1; /*!< [29..29] FFE125                                                           */
            __IOM uint32_t FFE126 : 1; /*!< [30..30] FFE126                                                           */
            __IOM uint32_t FFE127 : 1; /*!< [31..31] FFE127                                                           */
        } FWEIE60_b;
    };

    union
    {
        __IOM uint32_t FWEID60;        /*!< (@ 0x00007A58) Forwarding Engine Error Interrupt Disable Register
                                        *                  60 (FWEID60)                                               */

        struct
        {
            __IOM uint32_t FFD96  : 1; /*!< [0..0] FFD96                                                              */
            __IOM uint32_t FFD97  : 1; /*!< [1..1] FFD97                                                              */
            __IOM uint32_t FFD98  : 1; /*!< [2..2] FFD98                                                              */
            __IOM uint32_t FFD99  : 1; /*!< [3..3] FFD99                                                              */
            __IOM uint32_t FFD100 : 1; /*!< [4..4] FFD100                                                             */
            __IOM uint32_t FFD101 : 1; /*!< [5..5] FFD101                                                             */
            __IOM uint32_t FFD102 : 1; /*!< [6..6] FFD102                                                             */
            __IOM uint32_t FFD103 : 1; /*!< [7..7] FFD103                                                             */
            __IOM uint32_t FFD104 : 1; /*!< [8..8] FFD104                                                             */
            __IOM uint32_t FFD105 : 1; /*!< [9..9] FFD105                                                             */
            __IOM uint32_t FFD106 : 1; /*!< [10..10] FFD106                                                           */
            __IOM uint32_t FFD107 : 1; /*!< [11..11] FFD107                                                           */
            __IOM uint32_t FFD108 : 1; /*!< [12..12] FFD108                                                           */
            __IOM uint32_t FFD109 : 1; /*!< [13..13] FFD109                                                           */
            __IOM uint32_t FFD110 : 1; /*!< [14..14] FFD110                                                           */
            __IOM uint32_t FFD111 : 1; /*!< [15..15] FFD111                                                           */
            __IOM uint32_t FFD112 : 1; /*!< [16..16] FFD112                                                           */
            __IOM uint32_t FFD113 : 1; /*!< [17..17] FFD113                                                           */
            __IOM uint32_t FFD114 : 1; /*!< [18..18] FFD114                                                           */
            __IOM uint32_t FFD115 : 1; /*!< [19..19] FFD115                                                           */
            __IOM uint32_t FFD116 : 1; /*!< [20..20] FFD116                                                           */
            __IOM uint32_t FFD117 : 1; /*!< [21..21] FFD117                                                           */
            __IOM uint32_t FFD118 : 1; /*!< [22..22] FFD118                                                           */
            __IOM uint32_t FFD119 : 1; /*!< [23..23] FFD119                                                           */
            __IOM uint32_t FFD120 : 1; /*!< [24..24] FFD120                                                           */
            __IOM uint32_t FFD121 : 1; /*!< [25..25] FFD121                                                           */
            __IOM uint32_t FFD122 : 1; /*!< [26..26] FFD122                                                           */
            __IOM uint32_t FFD123 : 1; /*!< [27..27] FFD123                                                           */
            __IOM uint32_t FFD124 : 1; /*!< [28..28] FFD124                                                           */
            __IOM uint32_t FFD125 : 1; /*!< [29..29] FFD125                                                           */
            __IOM uint32_t FFD126 : 1; /*!< [30..30] FFD126                                                           */
            __IOM uint32_t FFD127 : 1; /*!< [31..31] FFD127                                                           */
        } FWEID60_b;
    };
    __IM uint32_t RESERVED268;

    union
    {
        __IOM uint32_t FWEIS61;        /*!< (@ 0x00007A60) Forwarding Engine Error Interrupt Status Register
                                        *                  61 (FWEIS61)                                               */

        struct
        {
            __IOM uint32_t FFS64 : 1;  /*!< [0..0] FFS64                                                              */
            __IOM uint32_t FFS65 : 1;  /*!< [1..1] FFS65                                                              */
            __IOM uint32_t FFS66 : 1;  /*!< [2..2] FFS66                                                              */
            __IOM uint32_t FFS67 : 1;  /*!< [3..3] FFS67                                                              */
            __IOM uint32_t FFS68 : 1;  /*!< [4..4] FFS68                                                              */
            __IOM uint32_t FFS69 : 1;  /*!< [5..5] FFS69                                                              */
            __IOM uint32_t FFS70 : 1;  /*!< [6..6] FFS70                                                              */
            __IOM uint32_t FFS71 : 1;  /*!< [7..7] FFS71                                                              */
            __IOM uint32_t FFS72 : 1;  /*!< [8..8] FFS72                                                              */
            __IOM uint32_t FFS73 : 1;  /*!< [9..9] FFS73                                                              */
            __IOM uint32_t FFS74 : 1;  /*!< [10..10] FFS74                                                            */
            __IOM uint32_t FFS75 : 1;  /*!< [11..11] FFS75                                                            */
            __IOM uint32_t FFS76 : 1;  /*!< [12..12] FFS76                                                            */
            __IOM uint32_t FFS77 : 1;  /*!< [13..13] FFS77                                                            */
            __IOM uint32_t FFS78 : 1;  /*!< [14..14] FFS78                                                            */
            __IOM uint32_t FFS79 : 1;  /*!< [15..15] FFS79                                                            */
            __IOM uint32_t FFS80 : 1;  /*!< [16..16] FFS80                                                            */
            __IOM uint32_t FFS81 : 1;  /*!< [17..17] FFS81                                                            */
            __IOM uint32_t FFS82 : 1;  /*!< [18..18] FFS82                                                            */
            __IOM uint32_t FFS83 : 1;  /*!< [19..19] FFS83                                                            */
            __IOM uint32_t FFS84 : 1;  /*!< [20..20] FFS84                                                            */
            __IOM uint32_t FFS85 : 1;  /*!< [21..21] FFS85                                                            */
            __IOM uint32_t FFS86 : 1;  /*!< [22..22] FFS86                                                            */
            __IOM uint32_t FFS87 : 1;  /*!< [23..23] FFS87                                                            */
            __IOM uint32_t FFS88 : 1;  /*!< [24..24] FFS88                                                            */
            __IOM uint32_t FFS89 : 1;  /*!< [25..25] FFS89                                                            */
            __IOM uint32_t FFS90 : 1;  /*!< [26..26] FFS90                                                            */
            __IOM uint32_t FFS91 : 1;  /*!< [27..27] FFS91                                                            */
            __IOM uint32_t FFS92 : 1;  /*!< [28..28] FFS92                                                            */
            __IOM uint32_t FFS93 : 1;  /*!< [29..29] FFS93                                                            */
            __IOM uint32_t FFS94 : 1;  /*!< [30..30] FFS94                                                            */
            __IOM uint32_t FFS95 : 1;  /*!< [31..31] FFS95                                                            */
        } FWEIS61_b;
    };

    union
    {
        __IOM uint32_t FWEIE61;        /*!< (@ 0x00007A64) Forwarding Engine Error Interrupt Enable Register
                                        *                  61 (FWEIE61)                                               */

        struct
        {
            __IOM uint32_t FFE64 : 1;  /*!< [0..0] FFE64                                                              */
            __IOM uint32_t FFE65 : 1;  /*!< [1..1] FFE65                                                              */
            __IOM uint32_t FFE66 : 1;  /*!< [2..2] FFE66                                                              */
            __IOM uint32_t FFE67 : 1;  /*!< [3..3] FFE67                                                              */
            __IOM uint32_t FFE68 : 1;  /*!< [4..4] FFE68                                                              */
            __IOM uint32_t FFE69 : 1;  /*!< [5..5] FFE69                                                              */
            __IOM uint32_t FFE70 : 1;  /*!< [6..6] FFE70                                                              */
            __IOM uint32_t FFE71 : 1;  /*!< [7..7] FFE71                                                              */
            __IOM uint32_t FFE72 : 1;  /*!< [8..8] FFE72                                                              */
            __IOM uint32_t FFE73 : 1;  /*!< [9..9] FFE73                                                              */
            __IOM uint32_t FFE74 : 1;  /*!< [10..10] FFE74                                                            */
            __IOM uint32_t FFE75 : 1;  /*!< [11..11] FFE75                                                            */
            __IOM uint32_t FFE76 : 1;  /*!< [12..12] FFE76                                                            */
            __IOM uint32_t FFE77 : 1;  /*!< [13..13] FFE77                                                            */
            __IOM uint32_t FFE78 : 1;  /*!< [14..14] FFE78                                                            */
            __IOM uint32_t FFE79 : 1;  /*!< [15..15] FFE79                                                            */
            __IOM uint32_t FFE80 : 1;  /*!< [16..16] FFE80                                                            */
            __IOM uint32_t FFE81 : 1;  /*!< [17..17] FFE81                                                            */
            __IOM uint32_t FFE82 : 1;  /*!< [18..18] FFE82                                                            */
            __IOM uint32_t FFE83 : 1;  /*!< [19..19] FFE83                                                            */
            __IOM uint32_t FFE84 : 1;  /*!< [20..20] FFE84                                                            */
            __IOM uint32_t FFE85 : 1;  /*!< [21..21] FFE85                                                            */
            __IOM uint32_t FFE86 : 1;  /*!< [22..22] FFE86                                                            */
            __IOM uint32_t FFE87 : 1;  /*!< [23..23] FFE87                                                            */
            __IOM uint32_t FFE88 : 1;  /*!< [24..24] FFE88                                                            */
            __IOM uint32_t FFE89 : 1;  /*!< [25..25] FFE89                                                            */
            __IOM uint32_t FFE90 : 1;  /*!< [26..26] FFE90                                                            */
            __IOM uint32_t FFE91 : 1;  /*!< [27..27] FFE91                                                            */
            __IOM uint32_t FFE92 : 1;  /*!< [28..28] FFE92                                                            */
            __IOM uint32_t FFE93 : 1;  /*!< [29..29] FFE93                                                            */
            __IOM uint32_t FFE94 : 1;  /*!< [30..30] FFE94                                                            */
            __IOM uint32_t FFE95 : 1;  /*!< [31..31] FFE95                                                            */
        } FWEIE61_b;
    };

    union
    {
        __IOM uint32_t FWEID61;        /*!< (@ 0x00007A68) Forwarding Engine Error Interrupt Disable Register
                                        *                  61 (FWEID61)                                               */

        struct
        {
            __IOM uint32_t FFD64 : 1;  /*!< [0..0] FFD64                                                              */
            __IOM uint32_t FFD65 : 1;  /*!< [1..1] FFD65                                                              */
            __IOM uint32_t FFD66 : 1;  /*!< [2..2] FFD66                                                              */
            __IOM uint32_t FFD67 : 1;  /*!< [3..3] FFD67                                                              */
            __IOM uint32_t FFD68 : 1;  /*!< [4..4] FFD68                                                              */
            __IOM uint32_t FFD69 : 1;  /*!< [5..5] FFD69                                                              */
            __IOM uint32_t FFD70 : 1;  /*!< [6..6] FFD70                                                              */
            __IOM uint32_t FFD71 : 1;  /*!< [7..7] FFD71                                                              */
            __IOM uint32_t FFD72 : 1;  /*!< [8..8] FFD72                                                              */
            __IOM uint32_t FFD73 : 1;  /*!< [9..9] FFD73                                                              */
            __IOM uint32_t FFD74 : 1;  /*!< [10..10] FFD74                                                            */
            __IOM uint32_t FFD75 : 1;  /*!< [11..11] FFD75                                                            */
            __IOM uint32_t FFD76 : 1;  /*!< [12..12] FFD76                                                            */
            __IOM uint32_t FFD77 : 1;  /*!< [13..13] FFD77                                                            */
            __IOM uint32_t FFD78 : 1;  /*!< [14..14] FFD78                                                            */
            __IOM uint32_t FFD79 : 1;  /*!< [15..15] FFD79                                                            */
            __IOM uint32_t FFD80 : 1;  /*!< [16..16] FFD80                                                            */
            __IOM uint32_t FFD81 : 1;  /*!< [17..17] FFD81                                                            */
            __IOM uint32_t FFD82 : 1;  /*!< [18..18] FFD82                                                            */
            __IOM uint32_t FFD83 : 1;  /*!< [19..19] FFD83                                                            */
            __IOM uint32_t FFD84 : 1;  /*!< [20..20] FFD84                                                            */
            __IOM uint32_t FFD85 : 1;  /*!< [21..21] FFD85                                                            */
            __IOM uint32_t FFD86 : 1;  /*!< [22..22] FFD86                                                            */
            __IOM uint32_t FFD87 : 1;  /*!< [23..23] FFD87                                                            */
            __IOM uint32_t FFD88 : 1;  /*!< [24..24] FFD88                                                            */
            __IOM uint32_t FFD89 : 1;  /*!< [25..25] FFD89                                                            */
            __IOM uint32_t FFD90 : 1;  /*!< [26..26] FFD90                                                            */
            __IOM uint32_t FFD91 : 1;  /*!< [27..27] FFD91                                                            */
            __IOM uint32_t FFD92 : 1;  /*!< [28..28] FFD92                                                            */
            __IOM uint32_t FFD93 : 1;  /*!< [29..29] FFD93                                                            */
            __IOM uint32_t FFD94 : 1;  /*!< [30..30] FFD94                                                            */
            __IOM uint32_t FFD95 : 1;  /*!< [31..31] FFD95                                                            */
        } FWEID61_b;
    };
    __IM uint32_t RESERVED269;

    union
    {
        __IOM uint32_t FWEIS62;        /*!< (@ 0x00007A70) Forwarding Engine Error Interrupt Status Register
                                        *                  62 (FWEIS62)                                               */

        struct
        {
            __IOM uint32_t FFS32 : 1;  /*!< [0..0] FFS32                                                              */
            __IOM uint32_t FFS33 : 1;  /*!< [1..1] FFS33                                                              */
            __IOM uint32_t FFS34 : 1;  /*!< [2..2] FFS34                                                              */
            __IOM uint32_t FFS35 : 1;  /*!< [3..3] FFS35                                                              */
            __IOM uint32_t FFS36 : 1;  /*!< [4..4] FFS36                                                              */
            __IOM uint32_t FFS37 : 1;  /*!< [5..5] FFS37                                                              */
            __IOM uint32_t FFS38 : 1;  /*!< [6..6] FFS38                                                              */
            __IOM uint32_t FFS39 : 1;  /*!< [7..7] FFS39                                                              */
            __IOM uint32_t FFS40 : 1;  /*!< [8..8] FFS40                                                              */
            __IOM uint32_t FFS41 : 1;  /*!< [9..9] FFS41                                                              */
            __IOM uint32_t FFS42 : 1;  /*!< [10..10] FFS42                                                            */
            __IOM uint32_t FFS43 : 1;  /*!< [11..11] FFS43                                                            */
            __IOM uint32_t FFS44 : 1;  /*!< [12..12] FFS44                                                            */
            __IOM uint32_t FFS45 : 1;  /*!< [13..13] FFS45                                                            */
            __IOM uint32_t FFS46 : 1;  /*!< [14..14] FFS46                                                            */
            __IOM uint32_t FFS47 : 1;  /*!< [15..15] FFS47                                                            */
            __IOM uint32_t FFS48 : 1;  /*!< [16..16] FFS48                                                            */
            __IOM uint32_t FFS49 : 1;  /*!< [17..17] FFS49                                                            */
            __IOM uint32_t FFS50 : 1;  /*!< [18..18] FFS50                                                            */
            __IOM uint32_t FFS51 : 1;  /*!< [19..19] FFS51                                                            */
            __IOM uint32_t FFS52 : 1;  /*!< [20..20] FFS52                                                            */
            __IOM uint32_t FFS53 : 1;  /*!< [21..21] FFS53                                                            */
            __IOM uint32_t FFS54 : 1;  /*!< [22..22] FFS54                                                            */
            __IOM uint32_t FFS55 : 1;  /*!< [23..23] FFS55                                                            */
            __IOM uint32_t FFS56 : 1;  /*!< [24..24] FFS56                                                            */
            __IOM uint32_t FFS57 : 1;  /*!< [25..25] FFS57                                                            */
            __IOM uint32_t FFS58 : 1;  /*!< [26..26] FFS58                                                            */
            __IOM uint32_t FFS59 : 1;  /*!< [27..27] FFS59                                                            */
            __IOM uint32_t FFS60 : 1;  /*!< [28..28] FFS60                                                            */
            __IOM uint32_t FFS61 : 1;  /*!< [29..29] FFS61                                                            */
            __IOM uint32_t FFS62 : 1;  /*!< [30..30] FFS62                                                            */
            __IOM uint32_t FFS63 : 1;  /*!< [31..31] FFS63                                                            */
        } FWEIS62_b;
    };

    union
    {
        __IOM uint32_t FWEIE62;        /*!< (@ 0x00007A74) Forwarding Engine Error Interrupt Enable Register
                                        *                  62 (FWEIE62)                                               */

        struct
        {
            __IOM uint32_t FFE32 : 1;  /*!< [0..0] FFE32                                                              */
            __IOM uint32_t FFE33 : 1;  /*!< [1..1] FFE33                                                              */
            __IOM uint32_t FFE34 : 1;  /*!< [2..2] FFE34                                                              */
            __IOM uint32_t FFE35 : 1;  /*!< [3..3] FFE35                                                              */
            __IOM uint32_t FFE36 : 1;  /*!< [4..4] FFE36                                                              */
            __IOM uint32_t FFE37 : 1;  /*!< [5..5] FFE37                                                              */
            __IOM uint32_t FFE38 : 1;  /*!< [6..6] FFE38                                                              */
            __IOM uint32_t FFE39 : 1;  /*!< [7..7] FFE39                                                              */
            __IOM uint32_t FFE40 : 1;  /*!< [8..8] FFE40                                                              */
            __IOM uint32_t FFE41 : 1;  /*!< [9..9] FFE41                                                              */
            __IOM uint32_t FFE42 : 1;  /*!< [10..10] FFE42                                                            */
            __IOM uint32_t FFE43 : 1;  /*!< [11..11] FFE43                                                            */
            __IOM uint32_t FFE44 : 1;  /*!< [12..12] FFE44                                                            */
            __IOM uint32_t FFE45 : 1;  /*!< [13..13] FFE45                                                            */
            __IOM uint32_t FFE46 : 1;  /*!< [14..14] FFE46                                                            */
            __IOM uint32_t FFE47 : 1;  /*!< [15..15] FFE47                                                            */
            __IOM uint32_t FFE48 : 1;  /*!< [16..16] FFE48                                                            */
            __IOM uint32_t FFE49 : 1;  /*!< [17..17] FFE49                                                            */
            __IOM uint32_t FFE50 : 1;  /*!< [18..18] FFE50                                                            */
            __IOM uint32_t FFE51 : 1;  /*!< [19..19] FFE51                                                            */
            __IOM uint32_t FFE52 : 1;  /*!< [20..20] FFE52                                                            */
            __IOM uint32_t FFE53 : 1;  /*!< [21..21] FFE53                                                            */
            __IOM uint32_t FFE54 : 1;  /*!< [22..22] FFE54                                                            */
            __IOM uint32_t FFE55 : 1;  /*!< [23..23] FFE55                                                            */
            __IOM uint32_t FFE56 : 1;  /*!< [24..24] FFE56                                                            */
            __IOM uint32_t FFE57 : 1;  /*!< [25..25] FFE57                                                            */
            __IOM uint32_t FFE58 : 1;  /*!< [26..26] FFE58                                                            */
            __IOM uint32_t FFE59 : 1;  /*!< [27..27] FFE59                                                            */
            __IOM uint32_t FFE60 : 1;  /*!< [28..28] FFE60                                                            */
            __IOM uint32_t FFE61 : 1;  /*!< [29..29] FFE61                                                            */
            __IOM uint32_t FFE62 : 1;  /*!< [30..30] FFE62                                                            */
            __IOM uint32_t FFE63 : 1;  /*!< [31..31] FFE63                                                            */
        } FWEIE62_b;
    };

    union
    {
        __IOM uint32_t FWEID62;        /*!< (@ 0x00007A78) Forwarding Engine Error Interrupt Disable Register
                                        *                  62 (FWEID62)                                               */

        struct
        {
            __IOM uint32_t FFD32 : 1;  /*!< [0..0] FFD32                                                              */
            __IOM uint32_t FFD33 : 1;  /*!< [1..1] FFD33                                                              */
            __IOM uint32_t FFD34 : 1;  /*!< [2..2] FFD34                                                              */
            __IOM uint32_t FFD35 : 1;  /*!< [3..3] FFD35                                                              */
            __IOM uint32_t FFD36 : 1;  /*!< [4..4] FFD36                                                              */
            __IOM uint32_t FFD37 : 1;  /*!< [5..5] FFD37                                                              */
            __IOM uint32_t FFD38 : 1;  /*!< [6..6] FFD38                                                              */
            __IOM uint32_t FFD39 : 1;  /*!< [7..7] FFD39                                                              */
            __IOM uint32_t FFD40 : 1;  /*!< [8..8] FFD40                                                              */
            __IOM uint32_t FFD41 : 1;  /*!< [9..9] FFD41                                                              */
            __IOM uint32_t FFD42 : 1;  /*!< [10..10] FFD42                                                            */
            __IOM uint32_t FFD43 : 1;  /*!< [11..11] FFD43                                                            */
            __IOM uint32_t FFD44 : 1;  /*!< [12..12] FFD44                                                            */
            __IOM uint32_t FFD45 : 1;  /*!< [13..13] FFD45                                                            */
            __IOM uint32_t FFD46 : 1;  /*!< [14..14] FFD46                                                            */
            __IOM uint32_t FFD47 : 1;  /*!< [15..15] FFD47                                                            */
            __IOM uint32_t FFD48 : 1;  /*!< [16..16] FFD48                                                            */
            __IOM uint32_t FFD49 : 1;  /*!< [17..17] FFD49                                                            */
            __IOM uint32_t FFD50 : 1;  /*!< [18..18] FFD50                                                            */
            __IOM uint32_t FFD51 : 1;  /*!< [19..19] FFD51                                                            */
            __IOM uint32_t FFD52 : 1;  /*!< [20..20] FFD52                                                            */
            __IOM uint32_t FFD53 : 1;  /*!< [21..21] FFD53                                                            */
            __IOM uint32_t FFD54 : 1;  /*!< [22..22] FFD54                                                            */
            __IOM uint32_t FFD55 : 1;  /*!< [23..23] FFD55                                                            */
            __IOM uint32_t FFD56 : 1;  /*!< [24..24] FFD56                                                            */
            __IOM uint32_t FFD57 : 1;  /*!< [25..25] FFD57                                                            */
            __IOM uint32_t FFD58 : 1;  /*!< [26..26] FFD58                                                            */
            __IOM uint32_t FFD59 : 1;  /*!< [27..27] FFD59                                                            */
            __IOM uint32_t FFD60 : 1;  /*!< [28..28] FFD60                                                            */
            __IOM uint32_t FFD61 : 1;  /*!< [29..29] FFD61                                                            */
            __IOM uint32_t FFD62 : 1;  /*!< [30..30] FFD62                                                            */
            __IOM uint32_t FFD63 : 1;  /*!< [31..31] FFD63                                                            */
        } FWEID62_b;
    };
    __IM uint32_t RESERVED270;

    union
    {
        __IOM uint32_t FWEIS63;        /*!< (@ 0x00007A80) Forwarding Engine Error Interrupt Status Register
                                        *                  63 (FWEIS63)                                               */

        struct
        {
            __IOM uint32_t FFS0  : 1;  /*!< [0..0] FFS0                                                               */
            __IOM uint32_t FFS1  : 1;  /*!< [1..1] FFS1                                                               */
            __IOM uint32_t FFS2  : 1;  /*!< [2..2] FFS2                                                               */
            __IOM uint32_t FFS3  : 1;  /*!< [3..3] FFS3                                                               */
            __IOM uint32_t FFS4  : 1;  /*!< [4..4] FFS4                                                               */
            __IOM uint32_t FFS5  : 1;  /*!< [5..5] FFS5                                                               */
            __IOM uint32_t FFS6  : 1;  /*!< [6..6] FFS6                                                               */
            __IOM uint32_t FFS7  : 1;  /*!< [7..7] FFS7                                                               */
            __IOM uint32_t FFS8  : 1;  /*!< [8..8] FFS8                                                               */
            __IOM uint32_t FFS9  : 1;  /*!< [9..9] FFS9                                                               */
            __IOM uint32_t FFS10 : 1;  /*!< [10..10] FFS10                                                            */
            __IOM uint32_t FFS11 : 1;  /*!< [11..11] FFS11                                                            */
            __IOM uint32_t FFS12 : 1;  /*!< [12..12] FFS12                                                            */
            __IOM uint32_t FFS13 : 1;  /*!< [13..13] FFS13                                                            */
            __IOM uint32_t FFS14 : 1;  /*!< [14..14] FFS14                                                            */
            __IOM uint32_t FFS15 : 1;  /*!< [15..15] FFS15                                                            */
            __IOM uint32_t FFS16 : 1;  /*!< [16..16] FFS16                                                            */
            __IOM uint32_t FFS17 : 1;  /*!< [17..17] FFS17                                                            */
            __IOM uint32_t FFS18 : 1;  /*!< [18..18] FFS18                                                            */
            __IOM uint32_t FFS19 : 1;  /*!< [19..19] FFS19                                                            */
            __IOM uint32_t FFS20 : 1;  /*!< [20..20] FFS20                                                            */
            __IOM uint32_t FFS21 : 1;  /*!< [21..21] FFS21                                                            */
            __IOM uint32_t FFS22 : 1;  /*!< [22..22] FFS22                                                            */
            __IOM uint32_t FFS23 : 1;  /*!< [23..23] FFS23                                                            */
            __IOM uint32_t FFS24 : 1;  /*!< [24..24] FFS24                                                            */
            __IOM uint32_t FFS25 : 1;  /*!< [25..25] FFS25                                                            */
            __IOM uint32_t FFS26 : 1;  /*!< [26..26] FFS26                                                            */
            __IOM uint32_t FFS27 : 1;  /*!< [27..27] FFS27                                                            */
            __IOM uint32_t FFS28 : 1;  /*!< [28..28] FFS28                                                            */
            __IOM uint32_t FFS29 : 1;  /*!< [29..29] FFS29                                                            */
            __IOM uint32_t FFS30 : 1;  /*!< [30..30] FFS30                                                            */
            __IOM uint32_t FFS31 : 1;  /*!< [31..31] FFS31                                                            */
        } FWEIS63_b;
    };

    union
    {
        __IOM uint32_t FWEIE63;        /*!< (@ 0x00007A84) Forwarding Engine Error Interrupt Enable Register
                                        *                  63 (FWEIE63)                                               */

        struct
        {
            __IOM uint32_t FFE0  : 1;  /*!< [0..0] FFE0                                                               */
            __IOM uint32_t FFE1  : 1;  /*!< [1..1] FFE1                                                               */
            __IOM uint32_t FFE2  : 1;  /*!< [2..2] FFE2                                                               */
            __IOM uint32_t FFE3  : 1;  /*!< [3..3] FFE3                                                               */
            __IOM uint32_t FFE4  : 1;  /*!< [4..4] FFE4                                                               */
            __IOM uint32_t FFE5  : 1;  /*!< [5..5] FFE5                                                               */
            __IOM uint32_t FFE6  : 1;  /*!< [6..6] FFE6                                                               */
            __IOM uint32_t FFE7  : 1;  /*!< [7..7] FFE7                                                               */
            __IOM uint32_t FFE8  : 1;  /*!< [8..8] FFE8                                                               */
            __IOM uint32_t FFE9  : 1;  /*!< [9..9] FFE9                                                               */
            __IOM uint32_t FFE10 : 1;  /*!< [10..10] FFE10                                                            */
            __IOM uint32_t FFE11 : 1;  /*!< [11..11] FFE11                                                            */
            __IOM uint32_t FFE12 : 1;  /*!< [12..12] FFE12                                                            */
            __IOM uint32_t FFE13 : 1;  /*!< [13..13] FFE13                                                            */
            __IOM uint32_t FFE14 : 1;  /*!< [14..14] FFE14                                                            */
            __IOM uint32_t FFE15 : 1;  /*!< [15..15] FFE15                                                            */
            __IOM uint32_t FFE16 : 1;  /*!< [16..16] FFE16                                                            */
            __IOM uint32_t FFE17 : 1;  /*!< [17..17] FFE17                                                            */
            __IOM uint32_t FFE18 : 1;  /*!< [18..18] FFE18                                                            */
            __IOM uint32_t FFE19 : 1;  /*!< [19..19] FFE19                                                            */
            __IOM uint32_t FFE20 : 1;  /*!< [20..20] FFE20                                                            */
            __IOM uint32_t FFE21 : 1;  /*!< [21..21] FFE21                                                            */
            __IOM uint32_t FFE22 : 1;  /*!< [22..22] FFE22                                                            */
            __IOM uint32_t FFE23 : 1;  /*!< [23..23] FFE23                                                            */
            __IOM uint32_t FFE24 : 1;  /*!< [24..24] FFE24                                                            */
            __IOM uint32_t FFE25 : 1;  /*!< [25..25] FFE25                                                            */
            __IOM uint32_t FFE26 : 1;  /*!< [26..26] FFE26                                                            */
            __IOM uint32_t FFE27 : 1;  /*!< [27..27] FFE27                                                            */
            __IOM uint32_t FFE28 : 1;  /*!< [28..28] FFE28                                                            */
            __IOM uint32_t FFE29 : 1;  /*!< [29..29] FFE29                                                            */
            __IOM uint32_t FFE30 : 1;  /*!< [30..30] FFE30                                                            */
            __IOM uint32_t FFE31 : 1;  /*!< [31..31] FFE31                                                            */
        } FWEIE63_b;
    };

    union
    {
        __IOM uint32_t FWEID63;        /*!< (@ 0x00007A88) Forwarding Engine Error Interrupt Disable Register
                                        *                  63 (FWEID63)                                               */

        struct
        {
            __IOM uint32_t FFD0  : 1;  /*!< [0..0] FFD0                                                               */
            __IOM uint32_t FFD1  : 1;  /*!< [1..1] FFD1                                                               */
            __IOM uint32_t FFD2  : 1;  /*!< [2..2] FFD2                                                               */
            __IOM uint32_t FFD3  : 1;  /*!< [3..3] FFD3                                                               */
            __IOM uint32_t FFD4  : 1;  /*!< [4..4] FFD4                                                               */
            __IOM uint32_t FFD5  : 1;  /*!< [5..5] FFD5                                                               */
            __IOM uint32_t FFD6  : 1;  /*!< [6..6] FFD6                                                               */
            __IOM uint32_t FFD7  : 1;  /*!< [7..7] FFD7                                                               */
            __IOM uint32_t FFD8  : 1;  /*!< [8..8] FFD8                                                               */
            __IOM uint32_t FFD9  : 1;  /*!< [9..9] FFD9                                                               */
            __IOM uint32_t FFD10 : 1;  /*!< [10..10] FFD10                                                            */
            __IOM uint32_t FFD11 : 1;  /*!< [11..11] FFD11                                                            */
            __IOM uint32_t FFD12 : 1;  /*!< [12..12] FFD12                                                            */
            __IOM uint32_t FFD13 : 1;  /*!< [13..13] FFD13                                                            */
            __IOM uint32_t FFD14 : 1;  /*!< [14..14] FFD14                                                            */
            __IOM uint32_t FFD15 : 1;  /*!< [15..15] FFD15                                                            */
            __IOM uint32_t FFD16 : 1;  /*!< [16..16] FFD16                                                            */
            __IOM uint32_t FFD17 : 1;  /*!< [17..17] FFD17                                                            */
            __IOM uint32_t FFD18 : 1;  /*!< [18..18] FFD18                                                            */
            __IOM uint32_t FFD19 : 1;  /*!< [19..19] FFD19                                                            */
            __IOM uint32_t FFD20 : 1;  /*!< [20..20] FFD20                                                            */
            __IOM uint32_t FFD21 : 1;  /*!< [21..21] FFD21                                                            */
            __IOM uint32_t FFD22 : 1;  /*!< [22..22] FFD22                                                            */
            __IOM uint32_t FFD23 : 1;  /*!< [23..23] FFD23                                                            */
            __IOM uint32_t FFD24 : 1;  /*!< [24..24] FFD24                                                            */
            __IOM uint32_t FFD25 : 1;  /*!< [25..25] FFD25                                                            */
            __IOM uint32_t FFD26 : 1;  /*!< [26..26] FFD26                                                            */
            __IOM uint32_t FFD27 : 1;  /*!< [27..27] FFD27                                                            */
            __IOM uint32_t FFD28 : 1;  /*!< [28..28] FFD28                                                            */
            __IOM uint32_t FFD29 : 1;  /*!< [29..29] FFD29                                                            */
            __IOM uint32_t FFD30 : 1;  /*!< [30..30] FFD30                                                            */
            __IOM uint32_t FFD31 : 1;  /*!< [31..31] FFD31                                                            */
        } FWEID63_b;
    };
    __IM uint32_t RESERVED271;

    union
    {
        __IOM uint32_t FWEIS70;          /*!< (@ 0x00007A90) Forwarding Engine Error Interrupt Status Register
                                          *                  70 (FWEIS70)                                               */

        struct
        {
            __IOM uint32_t FOORS96  : 1; /*!< [0..0] FOORS96                                                            */
            __IOM uint32_t FOORS97  : 1; /*!< [1..1] FOORS97                                                            */
            __IOM uint32_t FOORS98  : 1; /*!< [2..2] FOORS98                                                            */
            __IOM uint32_t FOORS99  : 1; /*!< [3..3] FOORS99                                                            */
            __IOM uint32_t FOORS100 : 1; /*!< [4..4] FOORS100                                                           */
            __IOM uint32_t FOORS101 : 1; /*!< [5..5] FOORS101                                                           */
            __IOM uint32_t FOORS102 : 1; /*!< [6..6] FOORS102                                                           */
            __IOM uint32_t FOORS103 : 1; /*!< [7..7] FOORS103                                                           */
            __IOM uint32_t FOORS104 : 1; /*!< [8..8] FOORS104                                                           */
            __IOM uint32_t FOORS105 : 1; /*!< [9..9] FOORS105                                                           */
            __IOM uint32_t FOORS106 : 1; /*!< [10..10] FOORS106                                                         */
            __IOM uint32_t FOORS107 : 1; /*!< [11..11] FOORS107                                                         */
            __IOM uint32_t FOORS108 : 1; /*!< [12..12] FOORS108                                                         */
            __IOM uint32_t FOORS109 : 1; /*!< [13..13] FOORS109                                                         */
            __IOM uint32_t FOORS110 : 1; /*!< [14..14] FOORS110                                                         */
            __IOM uint32_t FOORS111 : 1; /*!< [15..15] FOORS111                                                         */
            __IOM uint32_t FOORS112 : 1; /*!< [16..16] FOORS112                                                         */
            __IOM uint32_t FOORS113 : 1; /*!< [17..17] FOORS113                                                         */
            __IOM uint32_t FOORS114 : 1; /*!< [18..18] FOORS114                                                         */
            __IOM uint32_t FOORS115 : 1; /*!< [19..19] FOORS115                                                         */
            __IOM uint32_t FOORS116 : 1; /*!< [20..20] FOORS116                                                         */
            __IOM uint32_t FOORS117 : 1; /*!< [21..21] FOORS117                                                         */
            __IOM uint32_t FOORS118 : 1; /*!< [22..22] FOORS118                                                         */
            __IOM uint32_t FOORS119 : 1; /*!< [23..23] FOORS119                                                         */
            __IOM uint32_t FOORS120 : 1; /*!< [24..24] FOORS120                                                         */
            __IOM uint32_t FOORS121 : 1; /*!< [25..25] FOORS121                                                         */
            __IOM uint32_t FOORS122 : 1; /*!< [26..26] FOORS122                                                         */
            __IOM uint32_t FOORS123 : 1; /*!< [27..27] FOORS123                                                         */
            __IOM uint32_t FOORS124 : 1; /*!< [28..28] FOORS124                                                         */
            __IOM uint32_t FOORS125 : 1; /*!< [29..29] FOORS125                                                         */
            __IOM uint32_t FOORS126 : 1; /*!< [30..30] FOORS126                                                         */
            __IOM uint32_t FOORS127 : 1; /*!< [31..31] FOORS127                                                         */
        } FWEIS70_b;
    };

    union
    {
        __IOM uint32_t FWEIE70;          /*!< (@ 0x00007A94) Forwarding Engine Error Interrupt Enable Register
                                          *                  70 (FWEIE70)                                               */

        struct
        {
            __IOM uint32_t FOORE96  : 1; /*!< [0..0] FOORE96                                                            */
            __IOM uint32_t FOORE97  : 1; /*!< [1..1] FOORE97                                                            */
            __IOM uint32_t FOORE98  : 1; /*!< [2..2] FOORE98                                                            */
            __IOM uint32_t FOORE99  : 1; /*!< [3..3] FOORE99                                                            */
            __IOM uint32_t FOORE100 : 1; /*!< [4..4] FOORE100                                                           */
            __IOM uint32_t FOORE101 : 1; /*!< [5..5] FOORE101                                                           */
            __IOM uint32_t FOORE102 : 1; /*!< [6..6] FOORE102                                                           */
            __IOM uint32_t FOORE103 : 1; /*!< [7..7] FOORE103                                                           */
            __IOM uint32_t FOORE104 : 1; /*!< [8..8] FOORE104                                                           */
            __IOM uint32_t FOORE105 : 1; /*!< [9..9] FOORE105                                                           */
            __IOM uint32_t FOORE106 : 1; /*!< [10..10] FOORE106                                                         */
            __IOM uint32_t FOORE107 : 1; /*!< [11..11] FOORE107                                                         */
            __IOM uint32_t FOORE108 : 1; /*!< [12..12] FOORE108                                                         */
            __IOM uint32_t FOORE109 : 1; /*!< [13..13] FOORE109                                                         */
            __IOM uint32_t FOORE110 : 1; /*!< [14..14] FOORE110                                                         */
            __IOM uint32_t FOORE111 : 1; /*!< [15..15] FOORE111                                                         */
            __IOM uint32_t FOORE112 : 1; /*!< [16..16] FOORE112                                                         */
            __IOM uint32_t FOORE113 : 1; /*!< [17..17] FOORE113                                                         */
            __IOM uint32_t FOORE114 : 1; /*!< [18..18] FOORE114                                                         */
            __IOM uint32_t FOORE115 : 1; /*!< [19..19] FOORE115                                                         */
            __IOM uint32_t FOORE116 : 1; /*!< [20..20] FOORE116                                                         */
            __IOM uint32_t FOORE117 : 1; /*!< [21..21] FOORE117                                                         */
            __IOM uint32_t FOORE118 : 1; /*!< [22..22] FOORE118                                                         */
            __IOM uint32_t FOORE119 : 1; /*!< [23..23] FOORE119                                                         */
            __IOM uint32_t FOORE120 : 1; /*!< [24..24] FOORE120                                                         */
            __IOM uint32_t FOORE121 : 1; /*!< [25..25] FOORE121                                                         */
            __IOM uint32_t FOORE122 : 1; /*!< [26..26] FOORE122                                                         */
            __IOM uint32_t FOORE123 : 1; /*!< [27..27] FOORE123                                                         */
            __IOM uint32_t FOORE124 : 1; /*!< [28..28] FOORE124                                                         */
            __IOM uint32_t FOORE125 : 1; /*!< [29..29] FOORE125                                                         */
            __IOM uint32_t FOORE126 : 1; /*!< [30..30] FOORE126                                                         */
            __IOM uint32_t FOORE127 : 1; /*!< [31..31] FOORE127                                                         */
        } FWEIE70_b;
    };

    union
    {
        __IOM uint32_t FWEID70;          /*!< (@ 0x00007A98) Forwarding Engine Error Interrupt Disable Register
                                          *                  70 (FWEID70)                                               */

        struct
        {
            __IOM uint32_t FOORD96  : 1; /*!< [0..0] FOORD96                                                            */
            __IOM uint32_t FOORD97  : 1; /*!< [1..1] FOORD97                                                            */
            __IOM uint32_t FOORD98  : 1; /*!< [2..2] FOORD98                                                            */
            __IOM uint32_t FOORD99  : 1; /*!< [3..3] FOORD99                                                            */
            __IOM uint32_t FOORD100 : 1; /*!< [4..4] FOORD100                                                           */
            __IOM uint32_t FOORD101 : 1; /*!< [5..5] FOORD101                                                           */
            __IOM uint32_t FOORD102 : 1; /*!< [6..6] FOORD102                                                           */
            __IOM uint32_t FOORD103 : 1; /*!< [7..7] FOORD103                                                           */
            __IOM uint32_t FOORD104 : 1; /*!< [8..8] FOORD104                                                           */
            __IOM uint32_t FOORD105 : 1; /*!< [9..9] FOORD105                                                           */
            __IOM uint32_t FOORD106 : 1; /*!< [10..10] FOORD106                                                         */
            __IOM uint32_t FOORD107 : 1; /*!< [11..11] FOORD107                                                         */
            __IOM uint32_t FOORD108 : 1; /*!< [12..12] FOORD108                                                         */
            __IOM uint32_t FOORD109 : 1; /*!< [13..13] FOORD109                                                         */
            __IOM uint32_t FOORD110 : 1; /*!< [14..14] FOORD110                                                         */
            __IOM uint32_t FOORD111 : 1; /*!< [15..15] FOORD111                                                         */
            __IOM uint32_t FOORD112 : 1; /*!< [16..16] FOORD112                                                         */
            __IOM uint32_t FOORD113 : 1; /*!< [17..17] FOORD113                                                         */
            __IOM uint32_t FOORD114 : 1; /*!< [18..18] FOORD114                                                         */
            __IOM uint32_t FOORD115 : 1; /*!< [19..19] FOORD115                                                         */
            __IOM uint32_t FOORD116 : 1; /*!< [20..20] FOORD116                                                         */
            __IOM uint32_t FOORD117 : 1; /*!< [21..21] FOORD117                                                         */
            __IOM uint32_t FOORD118 : 1; /*!< [22..22] FOORD118                                                         */
            __IOM uint32_t FOORD119 : 1; /*!< [23..23] FOORD119                                                         */
            __IOM uint32_t FOORD120 : 1; /*!< [24..24] FOORD120                                                         */
            __IOM uint32_t FOORD121 : 1; /*!< [25..25] FOORD121                                                         */
            __IOM uint32_t FOORD122 : 1; /*!< [26..26] FOORD122                                                         */
            __IOM uint32_t FOORD123 : 1; /*!< [27..27] FOORD123                                                         */
            __IOM uint32_t FOORD124 : 1; /*!< [28..28] FOORD124                                                         */
            __IOM uint32_t FOORD125 : 1; /*!< [29..29] FOORD125                                                         */
            __IOM uint32_t FOORD126 : 1; /*!< [30..30] FOORD126                                                         */
            __IOM uint32_t FOORD127 : 1; /*!< [31..31] FOORD127                                                         */
        } FWEID70_b;
    };
    __IM uint32_t RESERVED272;

    union
    {
        __IOM uint32_t FWEIS71;         /*!< (@ 0x00007AA0) Forwarding Engine Error Interrupt Status Register
                                         *                  71 (FWEIS71)                                               */

        struct
        {
            __IOM uint32_t FOORS64 : 1; /*!< [0..0] FOORS64                                                            */
            __IOM uint32_t FOORS65 : 1; /*!< [1..1] FOORS65                                                            */
            __IOM uint32_t FOORS66 : 1; /*!< [2..2] FOORS66                                                            */
            __IOM uint32_t FOORS67 : 1; /*!< [3..3] FOORS67                                                            */
            __IOM uint32_t FOORS68 : 1; /*!< [4..4] FOORS68                                                            */
            __IOM uint32_t FOORS69 : 1; /*!< [5..5] FOORS69                                                            */
            __IOM uint32_t FOORS70 : 1; /*!< [6..6] FOORS70                                                            */
            __IOM uint32_t FOORS71 : 1; /*!< [7..7] FOORS71                                                            */
            __IOM uint32_t FOORS72 : 1; /*!< [8..8] FOORS72                                                            */
            __IOM uint32_t FOORS73 : 1; /*!< [9..9] FOORS73                                                            */
            __IOM uint32_t FOORS74 : 1; /*!< [10..10] FOORS74                                                          */
            __IOM uint32_t FOORS75 : 1; /*!< [11..11] FOORS75                                                          */
            __IOM uint32_t FOORS76 : 1; /*!< [12..12] FOORS76                                                          */
            __IOM uint32_t FOORS77 : 1; /*!< [13..13] FOORS77                                                          */
            __IOM uint32_t FOORS78 : 1; /*!< [14..14] FOORS78                                                          */
            __IOM uint32_t FOORS79 : 1; /*!< [15..15] FOORS79                                                          */
            __IOM uint32_t FOORS80 : 1; /*!< [16..16] FOORS80                                                          */
            __IOM uint32_t FOORS81 : 1; /*!< [17..17] FOORS81                                                          */
            __IOM uint32_t FOORS82 : 1; /*!< [18..18] FOORS82                                                          */
            __IOM uint32_t FOORS83 : 1; /*!< [19..19] FOORS83                                                          */
            __IOM uint32_t FOORS84 : 1; /*!< [20..20] FOORS84                                                          */
            __IOM uint32_t FOORS85 : 1; /*!< [21..21] FOORS85                                                          */
            __IOM uint32_t FOORS86 : 1; /*!< [22..22] FOORS86                                                          */
            __IOM uint32_t FOORS87 : 1; /*!< [23..23] FOORS87                                                          */
            __IOM uint32_t FOORS88 : 1; /*!< [24..24] FOORS88                                                          */
            __IOM uint32_t FOORS89 : 1; /*!< [25..25] FOORS89                                                          */
            __IOM uint32_t FOORS90 : 1; /*!< [26..26] FOORS90                                                          */
            __IOM uint32_t FOORS91 : 1; /*!< [27..27] FOORS91                                                          */
            __IOM uint32_t FOORS92 : 1; /*!< [28..28] FOORS92                                                          */
            __IOM uint32_t FOORS93 : 1; /*!< [29..29] FOORS93                                                          */
            __IOM uint32_t FOORS94 : 1; /*!< [30..30] FOORS94                                                          */
            __IOM uint32_t FOORS95 : 1; /*!< [31..31] FOORS95                                                          */
        } FWEIS71_b;
    };

    union
    {
        __IOM uint32_t FWEIE71;         /*!< (@ 0x00007AA4) Forwarding Engine Error Interrupt Enable Register
                                         *                  71 (FWEIE71)                                               */

        struct
        {
            __IOM uint32_t FOORE64 : 1; /*!< [0..0] FOORE64                                                            */
            __IOM uint32_t FOORE65 : 1; /*!< [1..1] FOORE65                                                            */
            __IOM uint32_t FOORE66 : 1; /*!< [2..2] FOORE66                                                            */
            __IOM uint32_t FOORE67 : 1; /*!< [3..3] FOORE67                                                            */
            __IOM uint32_t FOORE68 : 1; /*!< [4..4] FOORE68                                                            */
            __IOM uint32_t FOORE69 : 1; /*!< [5..5] FOORE69                                                            */
            __IOM uint32_t FOORE70 : 1; /*!< [6..6] FOORE70                                                            */
            __IOM uint32_t FOORE71 : 1; /*!< [7..7] FOORE71                                                            */
            __IOM uint32_t FOORE72 : 1; /*!< [8..8] FOORE72                                                            */
            __IOM uint32_t FOORE73 : 1; /*!< [9..9] FOORE73                                                            */
            __IOM uint32_t FOORE74 : 1; /*!< [10..10] FOORE74                                                          */
            __IOM uint32_t FOORE75 : 1; /*!< [11..11] FOORE75                                                          */
            __IOM uint32_t FOORE76 : 1; /*!< [12..12] FOORE76                                                          */
            __IOM uint32_t FOORE77 : 1; /*!< [13..13] FOORE77                                                          */
            __IOM uint32_t FOORE78 : 1; /*!< [14..14] FOORE78                                                          */
            __IOM uint32_t FOORE79 : 1; /*!< [15..15] FOORE79                                                          */
            __IOM uint32_t FOORE80 : 1; /*!< [16..16] FOORE80                                                          */
            __IOM uint32_t FOORE81 : 1; /*!< [17..17] FOORE81                                                          */
            __IOM uint32_t FOORE82 : 1; /*!< [18..18] FOORE82                                                          */
            __IOM uint32_t FOORE83 : 1; /*!< [19..19] FOORE83                                                          */
            __IOM uint32_t FOORE84 : 1; /*!< [20..20] FOORE84                                                          */
            __IOM uint32_t FOORE85 : 1; /*!< [21..21] FOORE85                                                          */
            __IOM uint32_t FOORE86 : 1; /*!< [22..22] FOORE86                                                          */
            __IOM uint32_t FOORE87 : 1; /*!< [23..23] FOORE87                                                          */
            __IOM uint32_t FOORE88 : 1; /*!< [24..24] FOORE88                                                          */
            __IOM uint32_t FOORE89 : 1; /*!< [25..25] FOORE89                                                          */
            __IOM uint32_t FOORE90 : 1; /*!< [26..26] FOORE90                                                          */
            __IOM uint32_t FOORE91 : 1; /*!< [27..27] FOORE91                                                          */
            __IOM uint32_t FOORE92 : 1; /*!< [28..28] FOORE92                                                          */
            __IOM uint32_t FOORE93 : 1; /*!< [29..29] FOORE93                                                          */
            __IOM uint32_t FOORE94 : 1; /*!< [30..30] FOORE94                                                          */
            __IOM uint32_t FOORE95 : 1; /*!< [31..31] FOORE95                                                          */
        } FWEIE71_b;
    };

    union
    {
        __IOM uint32_t FWEID71;         /*!< (@ 0x00007AA8) Forwarding Engine Error Interrupt Disable Register
                                         *                  71 (FWEID71)                                               */

        struct
        {
            __IOM uint32_t FOORD64 : 1; /*!< [0..0] FOORD64                                                            */
            __IOM uint32_t FOORD65 : 1; /*!< [1..1] FOORD65                                                            */
            __IOM uint32_t FOORD66 : 1; /*!< [2..2] FOORD66                                                            */
            __IOM uint32_t FOORD67 : 1; /*!< [3..3] FOORD67                                                            */
            __IOM uint32_t FOORD68 : 1; /*!< [4..4] FOORD68                                                            */
            __IOM uint32_t FOORD69 : 1; /*!< [5..5] FOORD69                                                            */
            __IOM uint32_t FOORD70 : 1; /*!< [6..6] FOORD70                                                            */
            __IOM uint32_t FOORD71 : 1; /*!< [7..7] FOORD71                                                            */
            __IOM uint32_t FOORD72 : 1; /*!< [8..8] FOORD72                                                            */
            __IOM uint32_t FOORD73 : 1; /*!< [9..9] FOORD73                                                            */
            __IOM uint32_t FOORD74 : 1; /*!< [10..10] FOORD74                                                          */
            __IOM uint32_t FOORD75 : 1; /*!< [11..11] FOORD75                                                          */
            __IOM uint32_t FOORD76 : 1; /*!< [12..12] FOORD76                                                          */
            __IOM uint32_t FOORD77 : 1; /*!< [13..13] FOORD77                                                          */
            __IOM uint32_t FOORD78 : 1; /*!< [14..14] FOORD78                                                          */
            __IOM uint32_t FOORD79 : 1; /*!< [15..15] FOORD79                                                          */
            __IOM uint32_t FOORD80 : 1; /*!< [16..16] FOORD80                                                          */
            __IOM uint32_t FOORD81 : 1; /*!< [17..17] FOORD81                                                          */
            __IOM uint32_t FOORD82 : 1; /*!< [18..18] FOORD82                                                          */
            __IOM uint32_t FOORD83 : 1; /*!< [19..19] FOORD83                                                          */
            __IOM uint32_t FOORD84 : 1; /*!< [20..20] FOORD84                                                          */
            __IOM uint32_t FOORD85 : 1; /*!< [21..21] FOORD85                                                          */
            __IOM uint32_t FOORD86 : 1; /*!< [22..22] FOORD86                                                          */
            __IOM uint32_t FOORD87 : 1; /*!< [23..23] FOORD87                                                          */
            __IOM uint32_t FOORD88 : 1; /*!< [24..24] FOORD88                                                          */
            __IOM uint32_t FOORD89 : 1; /*!< [25..25] FOORD89                                                          */
            __IOM uint32_t FOORD90 : 1; /*!< [26..26] FOORD90                                                          */
            __IOM uint32_t FOORD91 : 1; /*!< [27..27] FOORD91                                                          */
            __IOM uint32_t FOORD92 : 1; /*!< [28..28] FOORD92                                                          */
            __IOM uint32_t FOORD93 : 1; /*!< [29..29] FOORD93                                                          */
            __IOM uint32_t FOORD94 : 1; /*!< [30..30] FOORD94                                                          */
            __IOM uint32_t FOORD95 : 1; /*!< [31..31] FOORD95                                                          */
        } FWEID71_b;
    };
    __IM uint32_t RESERVED273;

    union
    {
        __IOM uint32_t FWEIS72;         /*!< (@ 0x00007AB0) Forwarding Engine Error Interrupt Status Register
                                         *                  72 (FWEIS72)                                               */

        struct
        {
            __IOM uint32_t FOORS32 : 1; /*!< [0..0] FOORS32                                                            */
            __IOM uint32_t FOORS33 : 1; /*!< [1..1] FOORS33                                                            */
            __IOM uint32_t FOORS34 : 1; /*!< [2..2] FOORS34                                                            */
            __IOM uint32_t FOORS35 : 1; /*!< [3..3] FOORS35                                                            */
            __IOM uint32_t FOORS36 : 1; /*!< [4..4] FOORS36                                                            */
            __IOM uint32_t FOORS37 : 1; /*!< [5..5] FOORS37                                                            */
            __IOM uint32_t FOORS38 : 1; /*!< [6..6] FOORS38                                                            */
            __IOM uint32_t FOORS39 : 1; /*!< [7..7] FOORS39                                                            */
            __IOM uint32_t FOORS40 : 1; /*!< [8..8] FOORS40                                                            */
            __IOM uint32_t FOORS41 : 1; /*!< [9..9] FOORS41                                                            */
            __IOM uint32_t FOORS42 : 1; /*!< [10..10] FOORS42                                                          */
            __IOM uint32_t FOORS43 : 1; /*!< [11..11] FOORS43                                                          */
            __IOM uint32_t FOORS44 : 1; /*!< [12..12] FOORS44                                                          */
            __IOM uint32_t FOORS45 : 1; /*!< [13..13] FOORS45                                                          */
            __IOM uint32_t FOORS46 : 1; /*!< [14..14] FOORS46                                                          */
            __IOM uint32_t FOORS47 : 1; /*!< [15..15] FOORS47                                                          */
            __IOM uint32_t FOORS48 : 1; /*!< [16..16] FOORS48                                                          */
            __IOM uint32_t FOORS49 : 1; /*!< [17..17] FOORS49                                                          */
            __IOM uint32_t FOORS50 : 1; /*!< [18..18] FOORS50                                                          */
            __IOM uint32_t FOORS51 : 1; /*!< [19..19] FOORS51                                                          */
            __IOM uint32_t FOORS52 : 1; /*!< [20..20] FOORS52                                                          */
            __IOM uint32_t FOORS53 : 1; /*!< [21..21] FOORS53                                                          */
            __IOM uint32_t FOORS54 : 1; /*!< [22..22] FOORS54                                                          */
            __IOM uint32_t FOORS55 : 1; /*!< [23..23] FOORS55                                                          */
            __IOM uint32_t FOORS56 : 1; /*!< [24..24] FOORS56                                                          */
            __IOM uint32_t FOORS57 : 1; /*!< [25..25] FOORS57                                                          */
            __IOM uint32_t FOORS58 : 1; /*!< [26..26] FOORS58                                                          */
            __IOM uint32_t FOORS59 : 1; /*!< [27..27] FOORS59                                                          */
            __IOM uint32_t FOORS60 : 1; /*!< [28..28] FOORS60                                                          */
            __IOM uint32_t FOORS61 : 1; /*!< [29..29] FOORS61                                                          */
            __IOM uint32_t FOORS62 : 1; /*!< [30..30] FOORS62                                                          */
            __IOM uint32_t FOORS63 : 1; /*!< [31..31] FOORS63                                                          */
        } FWEIS72_b;
    };

    union
    {
        __IOM uint32_t FWEIE72;         /*!< (@ 0x00007AB4) Forwarding Engine Error Interrupt Enable Register
                                         *                  72 (FWEIE72)                                               */

        struct
        {
            __IOM uint32_t FOORE32 : 1; /*!< [0..0] FOORE32                                                            */
            __IOM uint32_t FOORE33 : 1; /*!< [1..1] FOORE33                                                            */
            __IOM uint32_t FOORE34 : 1; /*!< [2..2] FOORE34                                                            */
            __IOM uint32_t FOORE35 : 1; /*!< [3..3] FOORE35                                                            */
            __IOM uint32_t FOORE36 : 1; /*!< [4..4] FOORE36                                                            */
            __IOM uint32_t FOORE37 : 1; /*!< [5..5] FOORE37                                                            */
            __IOM uint32_t FOORE38 : 1; /*!< [6..6] FOORE38                                                            */
            __IOM uint32_t FOORE39 : 1; /*!< [7..7] FOORE39                                                            */
            __IOM uint32_t FOORE40 : 1; /*!< [8..8] FOORE40                                                            */
            __IOM uint32_t FOORE41 : 1; /*!< [9..9] FOORE41                                                            */
            __IOM uint32_t FOORE42 : 1; /*!< [10..10] FOORE42                                                          */
            __IOM uint32_t FOORE43 : 1; /*!< [11..11] FOORE43                                                          */
            __IOM uint32_t FOORE44 : 1; /*!< [12..12] FOORE44                                                          */
            __IOM uint32_t FOORE45 : 1; /*!< [13..13] FOORE45                                                          */
            __IOM uint32_t FOORE46 : 1; /*!< [14..14] FOORE46                                                          */
            __IOM uint32_t FOORE47 : 1; /*!< [15..15] FOORE47                                                          */
            __IOM uint32_t FOORE48 : 1; /*!< [16..16] FOORE48                                                          */
            __IOM uint32_t FOORE49 : 1; /*!< [17..17] FOORE49                                                          */
            __IOM uint32_t FOORE50 : 1; /*!< [18..18] FOORE50                                                          */
            __IOM uint32_t FOORE51 : 1; /*!< [19..19] FOORE51                                                          */
            __IOM uint32_t FOORE52 : 1; /*!< [20..20] FOORE52                                                          */
            __IOM uint32_t FOORE53 : 1; /*!< [21..21] FOORE53                                                          */
            __IOM uint32_t FOORE54 : 1; /*!< [22..22] FOORE54                                                          */
            __IOM uint32_t FOORE55 : 1; /*!< [23..23] FOORE55                                                          */
            __IOM uint32_t FOORE56 : 1; /*!< [24..24] FOORE56                                                          */
            __IOM uint32_t FOORE57 : 1; /*!< [25..25] FOORE57                                                          */
            __IOM uint32_t FOORE58 : 1; /*!< [26..26] FOORE58                                                          */
            __IOM uint32_t FOORE59 : 1; /*!< [27..27] FOORE59                                                          */
            __IOM uint32_t FOORE60 : 1; /*!< [28..28] FOORE60                                                          */
            __IOM uint32_t FOORE61 : 1; /*!< [29..29] FOORE61                                                          */
            __IOM uint32_t FOORE62 : 1; /*!< [30..30] FOORE62                                                          */
            __IOM uint32_t FOORE63 : 1; /*!< [31..31] FOORE63                                                          */
        } FWEIE72_b;
    };

    union
    {
        __IOM uint32_t FWEID72;         /*!< (@ 0x00007AB8) Forwarding Engine Error Interrupt Disable Register
                                         *                  72 (FWEID72)                                               */

        struct
        {
            __IOM uint32_t FOORD32 : 1; /*!< [0..0] FOORD32                                                            */
            __IOM uint32_t FOORD33 : 1; /*!< [1..1] FOORD33                                                            */
            __IOM uint32_t FOORD34 : 1; /*!< [2..2] FOORD34                                                            */
            __IOM uint32_t FOORD35 : 1; /*!< [3..3] FOORD35                                                            */
            __IOM uint32_t FOORD36 : 1; /*!< [4..4] FOORD36                                                            */
            __IOM uint32_t FOORD37 : 1; /*!< [5..5] FOORD37                                                            */
            __IOM uint32_t FOORD38 : 1; /*!< [6..6] FOORD38                                                            */
            __IOM uint32_t FOORD39 : 1; /*!< [7..7] FOORD39                                                            */
            __IOM uint32_t FOORD40 : 1; /*!< [8..8] FOORD40                                                            */
            __IOM uint32_t FOORD41 : 1; /*!< [9..9] FOORD41                                                            */
            __IOM uint32_t FOORD42 : 1; /*!< [10..10] FOORD42                                                          */
            __IOM uint32_t FOORD43 : 1; /*!< [11..11] FOORD43                                                          */
            __IOM uint32_t FOORD44 : 1; /*!< [12..12] FOORD44                                                          */
            __IOM uint32_t FOORD45 : 1; /*!< [13..13] FOORD45                                                          */
            __IOM uint32_t FOORD46 : 1; /*!< [14..14] FOORD46                                                          */
            __IOM uint32_t FOORD47 : 1; /*!< [15..15] FOORD47                                                          */
            __IOM uint32_t FOORD48 : 1; /*!< [16..16] FOORD48                                                          */
            __IOM uint32_t FOORD49 : 1; /*!< [17..17] FOORD49                                                          */
            __IOM uint32_t FOORD50 : 1; /*!< [18..18] FOORD50                                                          */
            __IOM uint32_t FOORD51 : 1; /*!< [19..19] FOORD51                                                          */
            __IOM uint32_t FOORD52 : 1; /*!< [20..20] FOORD52                                                          */
            __IOM uint32_t FOORD53 : 1; /*!< [21..21] FOORD53                                                          */
            __IOM uint32_t FOORD54 : 1; /*!< [22..22] FOORD54                                                          */
            __IOM uint32_t FOORD55 : 1; /*!< [23..23] FOORD55                                                          */
            __IOM uint32_t FOORD56 : 1; /*!< [24..24] FOORD56                                                          */
            __IOM uint32_t FOORD57 : 1; /*!< [25..25] FOORD57                                                          */
            __IOM uint32_t FOORD58 : 1; /*!< [26..26] FOORD58                                                          */
            __IOM uint32_t FOORD59 : 1; /*!< [27..27] FOORD59                                                          */
            __IOM uint32_t FOORD60 : 1; /*!< [28..28] FOORD60                                                          */
            __IOM uint32_t FOORD61 : 1; /*!< [29..29] FOORD61                                                          */
            __IOM uint32_t FOORD62 : 1; /*!< [30..30] FOORD62                                                          */
            __IOM uint32_t FOORD63 : 1; /*!< [31..31] FOORD63                                                          */
        } FWEID72_b;
    };
    __IM uint32_t RESERVED274;

    union
    {
        __IOM uint32_t FWEIS73;         /*!< (@ 0x00007AC0) Forwarding Engine Error Interrupt Status Register
                                         *                  73 (FWEIS73)                                               */

        struct
        {
            __IOM uint32_t FOORS0  : 1; /*!< [0..0] FOORS0                                                             */
            __IOM uint32_t FOORS1  : 1; /*!< [1..1] FOORS1                                                             */
            __IOM uint32_t FOORS2  : 1; /*!< [2..2] FOORS2                                                             */
            __IOM uint32_t FOORS3  : 1; /*!< [3..3] FOORS3                                                             */
            __IOM uint32_t FOORS4  : 1; /*!< [4..4] FOORS4                                                             */
            __IOM uint32_t FOORS5  : 1; /*!< [5..5] FOORS5                                                             */
            __IOM uint32_t FOORS6  : 1; /*!< [6..6] FOORS6                                                             */
            __IOM uint32_t FOORS7  : 1; /*!< [7..7] FOORS7                                                             */
            __IOM uint32_t FOORS8  : 1; /*!< [8..8] FOORS8                                                             */
            __IOM uint32_t FOORS9  : 1; /*!< [9..9] FOORS9                                                             */
            __IOM uint32_t FOORS10 : 1; /*!< [10..10] FOORS10                                                          */
            __IOM uint32_t FOORS11 : 1; /*!< [11..11] FOORS11                                                          */
            __IOM uint32_t FOORS12 : 1; /*!< [12..12] FOORS12                                                          */
            __IOM uint32_t FOORS13 : 1; /*!< [13..13] FOORS13                                                          */
            __IOM uint32_t FOORS14 : 1; /*!< [14..14] FOORS14                                                          */
            __IOM uint32_t FOORS15 : 1; /*!< [15..15] FOORS15                                                          */
            __IOM uint32_t FOORS16 : 1; /*!< [16..16] FOORS16                                                          */
            __IOM uint32_t FOORS17 : 1; /*!< [17..17] FOORS17                                                          */
            __IOM uint32_t FOORS18 : 1; /*!< [18..18] FOORS18                                                          */
            __IOM uint32_t FOORS19 : 1; /*!< [19..19] FOORS19                                                          */
            __IOM uint32_t FOORS20 : 1; /*!< [20..20] FOORS20                                                          */
            __IOM uint32_t FOORS21 : 1; /*!< [21..21] FOORS21                                                          */
            __IOM uint32_t FOORS22 : 1; /*!< [22..22] FOORS22                                                          */
            __IOM uint32_t FOORS23 : 1; /*!< [23..23] FOORS23                                                          */
            __IOM uint32_t FOORS24 : 1; /*!< [24..24] FOORS24                                                          */
            __IOM uint32_t FOORS25 : 1; /*!< [25..25] FOORS25                                                          */
            __IOM uint32_t FOORS26 : 1; /*!< [26..26] FOORS26                                                          */
            __IOM uint32_t FOORS27 : 1; /*!< [27..27] FOORS27                                                          */
            __IOM uint32_t FOORS28 : 1; /*!< [28..28] FOORS28                                                          */
            __IOM uint32_t FOORS29 : 1; /*!< [29..29] FOORS29                                                          */
            __IOM uint32_t FOORS30 : 1; /*!< [30..30] FOORS30                                                          */
            __IOM uint32_t FOORS31 : 1; /*!< [31..31] FOORS31                                                          */
        } FWEIS73_b;
    };

    union
    {
        __IOM uint32_t FWEIE73;         /*!< (@ 0x00007AC4) Forwarding Engine Error Interrupt Enable Register
                                         *                  73 (FWEIE73)                                               */

        struct
        {
            __IOM uint32_t FOORE0  : 1; /*!< [0..0] FOORE0                                                             */
            __IOM uint32_t FOORE1  : 1; /*!< [1..1] FOORE1                                                             */
            __IOM uint32_t FOORE2  : 1; /*!< [2..2] FOORE2                                                             */
            __IOM uint32_t FOORE3  : 1; /*!< [3..3] FOORE3                                                             */
            __IOM uint32_t FOORE4  : 1; /*!< [4..4] FOORE4                                                             */
            __IOM uint32_t FOORE5  : 1; /*!< [5..5] FOORE5                                                             */
            __IOM uint32_t FOORE6  : 1; /*!< [6..6] FOORE6                                                             */
            __IOM uint32_t FOORE7  : 1; /*!< [7..7] FOORE7                                                             */
            __IOM uint32_t FOORE8  : 1; /*!< [8..8] FOORE8                                                             */
            __IOM uint32_t FOORE9  : 1; /*!< [9..9] FOORE9                                                             */
            __IOM uint32_t FOORE10 : 1; /*!< [10..10] FOORE10                                                          */
            __IOM uint32_t FOORE11 : 1; /*!< [11..11] FOORE11                                                          */
            __IOM uint32_t FOORE12 : 1; /*!< [12..12] FOORE12                                                          */
            __IOM uint32_t FOORE13 : 1; /*!< [13..13] FOORE13                                                          */
            __IOM uint32_t FOORE14 : 1; /*!< [14..14] FOORE14                                                          */
            __IOM uint32_t FOORE15 : 1; /*!< [15..15] FOORE15                                                          */
            __IOM uint32_t FOORE16 : 1; /*!< [16..16] FOORE16                                                          */
            __IOM uint32_t FOORE17 : 1; /*!< [17..17] FOORE17                                                          */
            __IOM uint32_t FOORE18 : 1; /*!< [18..18] FOORE18                                                          */
            __IOM uint32_t FOORE19 : 1; /*!< [19..19] FOORE19                                                          */
            __IOM uint32_t FOORE20 : 1; /*!< [20..20] FOORE20                                                          */
            __IOM uint32_t FOORE21 : 1; /*!< [21..21] FOORE21                                                          */
            __IOM uint32_t FOORE22 : 1; /*!< [22..22] FOORE22                                                          */
            __IOM uint32_t FOORE23 : 1; /*!< [23..23] FOORE23                                                          */
            __IOM uint32_t FOORE24 : 1; /*!< [24..24] FOORE24                                                          */
            __IOM uint32_t FOORE25 : 1; /*!< [25..25] FOORE25                                                          */
            __IOM uint32_t FOORE26 : 1; /*!< [26..26] FOORE26                                                          */
            __IOM uint32_t FOORE27 : 1; /*!< [27..27] FOORE27                                                          */
            __IOM uint32_t FOORE28 : 1; /*!< [28..28] FOORE28                                                          */
            __IOM uint32_t FOORE29 : 1; /*!< [29..29] FOORE29                                                          */
            __IOM uint32_t FOORE30 : 1; /*!< [30..30] FOORE30                                                          */
            __IOM uint32_t FOORE31 : 1; /*!< [31..31] FOORE31                                                          */
        } FWEIE73_b;
    };

    union
    {
        __IOM uint32_t FWEID73;         /*!< (@ 0x00007AC8) Forwarding Engine Error Interrupt Disable Register
                                         *                  73 (FWEID73)                                               */

        struct
        {
            __IOM uint32_t FOORD0  : 1; /*!< [0..0] FOORD0                                                             */
            __IOM uint32_t FOORD1  : 1; /*!< [1..1] FOORD1                                                             */
            __IOM uint32_t FOORD2  : 1; /*!< [2..2] FOORD2                                                             */
            __IOM uint32_t FOORD3  : 1; /*!< [3..3] FOORD3                                                             */
            __IOM uint32_t FOORD4  : 1; /*!< [4..4] FOORD4                                                             */
            __IOM uint32_t FOORD5  : 1; /*!< [5..5] FOORD5                                                             */
            __IOM uint32_t FOORD6  : 1; /*!< [6..6] FOORD6                                                             */
            __IOM uint32_t FOORD7  : 1; /*!< [7..7] FOORD7                                                             */
            __IOM uint32_t FOORD8  : 1; /*!< [8..8] FOORD8                                                             */
            __IOM uint32_t FOORD9  : 1; /*!< [9..9] FOORD9                                                             */
            __IOM uint32_t FOORD10 : 1; /*!< [10..10] FOORD10                                                          */
            __IOM uint32_t FOORD11 : 1; /*!< [11..11] FOORD11                                                          */
            __IOM uint32_t FOORD12 : 1; /*!< [12..12] FOORD12                                                          */
            __IOM uint32_t FOORD13 : 1; /*!< [13..13] FOORD13                                                          */
            __IOM uint32_t FOORD14 : 1; /*!< [14..14] FOORD14                                                          */
            __IOM uint32_t FOORD15 : 1; /*!< [15..15] FOORD15                                                          */
            __IOM uint32_t FOORD16 : 1; /*!< [16..16] FOORD16                                                          */
            __IOM uint32_t FOORD17 : 1; /*!< [17..17] FOORD17                                                          */
            __IOM uint32_t FOORD18 : 1; /*!< [18..18] FOORD18                                                          */
            __IOM uint32_t FOORD19 : 1; /*!< [19..19] FOORD19                                                          */
            __IOM uint32_t FOORD20 : 1; /*!< [20..20] FOORD20                                                          */
            __IOM uint32_t FOORD21 : 1; /*!< [21..21] FOORD21                                                          */
            __IOM uint32_t FOORD22 : 1; /*!< [22..22] FOORD22                                                          */
            __IOM uint32_t FOORD23 : 1; /*!< [23..23] FOORD23                                                          */
            __IOM uint32_t FOORD24 : 1; /*!< [24..24] FOORD24                                                          */
            __IOM uint32_t FOORD25 : 1; /*!< [25..25] FOORD25                                                          */
            __IOM uint32_t FOORD26 : 1; /*!< [26..26] FOORD26                                                          */
            __IOM uint32_t FOORD27 : 1; /*!< [27..27] FOORD27                                                          */
            __IOM uint32_t FOORD28 : 1; /*!< [28..28] FOORD28                                                          */
            __IOM uint32_t FOORD29 : 1; /*!< [29..29] FOORD29                                                          */
            __IOM uint32_t FOORD30 : 1; /*!< [30..30] FOORD30                                                          */
            __IOM uint32_t FOORD31 : 1; /*!< [31..31] FOORD31                                                          */
        } FWEID73_b;
    };
    __IM uint32_t RESERVED275;

    union
    {
        __IOM uint32_t FWEIS80;        /*!< (@ 0x00007AD0) Forwarding Engine Error Interrupt Status Register
                                        *                  80 (FWEIS80)                                               */

        struct
        {
            __IOM uint32_t TOS96  : 1; /*!< [0..0] TOS96                                                              */
            __IOM uint32_t TOS97  : 1; /*!< [1..1] TOS97                                                              */
            __IOM uint32_t TOS98  : 1; /*!< [2..2] TOS98                                                              */
            __IOM uint32_t TOS99  : 1; /*!< [3..3] TOS99                                                              */
            __IOM uint32_t TOS100 : 1; /*!< [4..4] TOS100                                                             */
            __IOM uint32_t TOS101 : 1; /*!< [5..5] TOS101                                                             */
            __IOM uint32_t TOS102 : 1; /*!< [6..6] TOS102                                                             */
            __IOM uint32_t TOS103 : 1; /*!< [7..7] TOS103                                                             */
            __IOM uint32_t TOS104 : 1; /*!< [8..8] TOS104                                                             */
            __IOM uint32_t TOS105 : 1; /*!< [9..9] TOS105                                                             */
            __IOM uint32_t TOS106 : 1; /*!< [10..10] TOS106                                                           */
            __IOM uint32_t TOS107 : 1; /*!< [11..11] TOS107                                                           */
            __IOM uint32_t TOS108 : 1; /*!< [12..12] TOS108                                                           */
            __IOM uint32_t TOS109 : 1; /*!< [13..13] TOS109                                                           */
            __IOM uint32_t TOS110 : 1; /*!< [14..14] TOS110                                                           */
            __IOM uint32_t TOS111 : 1; /*!< [15..15] TOS111                                                           */
            __IOM uint32_t TOS112 : 1; /*!< [16..16] TOS112                                                           */
            __IOM uint32_t TOS113 : 1; /*!< [17..17] TOS113                                                           */
            __IOM uint32_t TOS114 : 1; /*!< [18..18] TOS114                                                           */
            __IOM uint32_t TOS115 : 1; /*!< [19..19] TOS115                                                           */
            __IOM uint32_t TOS116 : 1; /*!< [20..20] TOS116                                                           */
            __IOM uint32_t TOS117 : 1; /*!< [21..21] TOS117                                                           */
            __IOM uint32_t TOS118 : 1; /*!< [22..22] TOS118                                                           */
            __IOM uint32_t TOS119 : 1; /*!< [23..23] TOS119                                                           */
            __IOM uint32_t TOS120 : 1; /*!< [24..24] TOS120                                                           */
            __IOM uint32_t TOS121 : 1; /*!< [25..25] TOS121                                                           */
            __IOM uint32_t TOS122 : 1; /*!< [26..26] TOS122                                                           */
            __IOM uint32_t TOS123 : 1; /*!< [27..27] TOS123                                                           */
            __IOM uint32_t TOS124 : 1; /*!< [28..28] TOS124                                                           */
            __IOM uint32_t TOS125 : 1; /*!< [29..29] TOS125                                                           */
            __IOM uint32_t TOS126 : 1; /*!< [30..30] TOS126                                                           */
            __IOM uint32_t TOS127 : 1; /*!< [31..31] TOS127                                                           */
        } FWEIS80_b;
    };

    union
    {
        __IOM uint32_t FWEIE80;        /*!< (@ 0x00007AD4) Forwarding Engine Error Interrupt Enable Register
                                        *                  80 (FWEIE80)                                               */

        struct
        {
            __IOM uint32_t TOE96  : 1; /*!< [0..0] TOE96                                                              */
            __IOM uint32_t TOE97  : 1; /*!< [1..1] TOE97                                                              */
            __IOM uint32_t TOE98  : 1; /*!< [2..2] TOE98                                                              */
            __IOM uint32_t TOE99  : 1; /*!< [3..3] TOE99                                                              */
            __IOM uint32_t TOE100 : 1; /*!< [4..4] TOE100                                                             */
            __IOM uint32_t TOE101 : 1; /*!< [5..5] TOE101                                                             */
            __IOM uint32_t TOE102 : 1; /*!< [6..6] TOE102                                                             */
            __IOM uint32_t TOE103 : 1; /*!< [7..7] TOE103                                                             */
            __IOM uint32_t TOE104 : 1; /*!< [8..8] TOE104                                                             */
            __IOM uint32_t TOE105 : 1; /*!< [9..9] TOE105                                                             */
            __IOM uint32_t TOE106 : 1; /*!< [10..10] TOE106                                                           */
            __IOM uint32_t TOE107 : 1; /*!< [11..11] TOE107                                                           */
            __IOM uint32_t TOE108 : 1; /*!< [12..12] TOE108                                                           */
            __IOM uint32_t TOE109 : 1; /*!< [13..13] TOE109                                                           */
            __IOM uint32_t TOE110 : 1; /*!< [14..14] TOE110                                                           */
            __IOM uint32_t TOE111 : 1; /*!< [15..15] TOE111                                                           */
            __IOM uint32_t TOE112 : 1; /*!< [16..16] TOE112                                                           */
            __IOM uint32_t TOE113 : 1; /*!< [17..17] TOE113                                                           */
            __IOM uint32_t TOE114 : 1; /*!< [18..18] TOE114                                                           */
            __IOM uint32_t TOE115 : 1; /*!< [19..19] TOE115                                                           */
            __IOM uint32_t TOE116 : 1; /*!< [20..20] TOE116                                                           */
            __IOM uint32_t TOE117 : 1; /*!< [21..21] TOE117                                                           */
            __IOM uint32_t TOE118 : 1; /*!< [22..22] TOE118                                                           */
            __IOM uint32_t TOE119 : 1; /*!< [23..23] TOE119                                                           */
            __IOM uint32_t TOE120 : 1; /*!< [24..24] TOE120                                                           */
            __IOM uint32_t TOE121 : 1; /*!< [25..25] TOE121                                                           */
            __IOM uint32_t TOE122 : 1; /*!< [26..26] TOE122                                                           */
            __IOM uint32_t TOE123 : 1; /*!< [27..27] TOE123                                                           */
            __IOM uint32_t TOE124 : 1; /*!< [28..28] TOE124                                                           */
            __IOM uint32_t TOE125 : 1; /*!< [29..29] TOE125                                                           */
            __IOM uint32_t TOE126 : 1; /*!< [30..30] TOE126                                                           */
            __IOM uint32_t TOE127 : 1; /*!< [31..31] TOE127                                                           */
        } FWEIE80_b;
    };

    union
    {
        __IOM uint32_t FWEID80;        /*!< (@ 0x00007AD8) Forwarding Engine Error Interrupt Disable Register
                                        *                  80 (FWEID80)                                               */

        struct
        {
            __IOM uint32_t TOD96  : 1; /*!< [0..0] TOD96                                                              */
            __IOM uint32_t TOD97  : 1; /*!< [1..1] TOD97                                                              */
            __IOM uint32_t TOD98  : 1; /*!< [2..2] TOD98                                                              */
            __IOM uint32_t TOD99  : 1; /*!< [3..3] TOD99                                                              */
            __IOM uint32_t TOD100 : 1; /*!< [4..4] TOD100                                                             */
            __IOM uint32_t TOD101 : 1; /*!< [5..5] TOD101                                                             */
            __IOM uint32_t TOD102 : 1; /*!< [6..6] TOD102                                                             */
            __IOM uint32_t TOD103 : 1; /*!< [7..7] TOD103                                                             */
            __IOM uint32_t TOD104 : 1; /*!< [8..8] TOD104                                                             */
            __IOM uint32_t TOD105 : 1; /*!< [9..9] TOD105                                                             */
            __IOM uint32_t TOD106 : 1; /*!< [10..10] TOD106                                                           */
            __IOM uint32_t TOD107 : 1; /*!< [11..11] TOD107                                                           */
            __IOM uint32_t TOD108 : 1; /*!< [12..12] TOD108                                                           */
            __IOM uint32_t TOD109 : 1; /*!< [13..13] TOD109                                                           */
            __IOM uint32_t TOD110 : 1; /*!< [14..14] TOD110                                                           */
            __IOM uint32_t TOD111 : 1; /*!< [15..15] TOD111                                                           */
            __IOM uint32_t TOD112 : 1; /*!< [16..16] TOD112                                                           */
            __IOM uint32_t TOD113 : 1; /*!< [17..17] TOD113                                                           */
            __IOM uint32_t TOD114 : 1; /*!< [18..18] TOD114                                                           */
            __IOM uint32_t TOD115 : 1; /*!< [19..19] TOD115                                                           */
            __IOM uint32_t TOD116 : 1; /*!< [20..20] TOD116                                                           */
            __IOM uint32_t TOD117 : 1; /*!< [21..21] TOD117                                                           */
            __IOM uint32_t TOD118 : 1; /*!< [22..22] TOD118                                                           */
            __IOM uint32_t TOD119 : 1; /*!< [23..23] TOD119                                                           */
            __IOM uint32_t TOD120 : 1; /*!< [24..24] TOD120                                                           */
            __IOM uint32_t TOD121 : 1; /*!< [25..25] TOD121                                                           */
            __IOM uint32_t TOD122 : 1; /*!< [26..26] TOD122                                                           */
            __IOM uint32_t TOD123 : 1; /*!< [27..27] TOD123                                                           */
            __IOM uint32_t TOD124 : 1; /*!< [28..28] TOD124                                                           */
            __IOM uint32_t TOD125 : 1; /*!< [29..29] TOD125                                                           */
            __IOM uint32_t TOD126 : 1; /*!< [30..30] TOD126                                                           */
            __IOM uint32_t TOD127 : 1; /*!< [31..31] TOD127                                                           */
        } FWEID80_b;
    };
    __IM uint32_t RESERVED276;

    union
    {
        __IOM uint32_t FWEIS81;        /*!< (@ 0x00007AE0) Forwarding Engine Error Interrupt Status Register
                                        *                  81 (FWEIS81)                                               */

        struct
        {
            __IOM uint32_t TOS64 : 1;  /*!< [0..0] TOS64                                                              */
            __IOM uint32_t TOS65 : 1;  /*!< [1..1] TOS65                                                              */
            __IOM uint32_t TOS66 : 1;  /*!< [2..2] TOS66                                                              */
            __IOM uint32_t TOS67 : 1;  /*!< [3..3] TOS67                                                              */
            __IOM uint32_t TOS68 : 1;  /*!< [4..4] TOS68                                                              */
            __IOM uint32_t TOS69 : 1;  /*!< [5..5] TOS69                                                              */
            __IOM uint32_t TOS70 : 1;  /*!< [6..6] TOS70                                                              */
            __IOM uint32_t TOS71 : 1;  /*!< [7..7] TOS71                                                              */
            __IOM uint32_t TOS72 : 1;  /*!< [8..8] TOS72                                                              */
            __IOM uint32_t TOS73 : 1;  /*!< [9..9] TOS73                                                              */
            __IOM uint32_t TOS74 : 1;  /*!< [10..10] TOS74                                                            */
            __IOM uint32_t TOS75 : 1;  /*!< [11..11] TOS75                                                            */
            __IOM uint32_t TOS76 : 1;  /*!< [12..12] TOS76                                                            */
            __IOM uint32_t TOS77 : 1;  /*!< [13..13] TOS77                                                            */
            __IOM uint32_t TOS78 : 1;  /*!< [14..14] TOS78                                                            */
            __IOM uint32_t TOS79 : 1;  /*!< [15..15] TOS79                                                            */
            __IOM uint32_t TOS80 : 1;  /*!< [16..16] TOS80                                                            */
            __IOM uint32_t TOS81 : 1;  /*!< [17..17] TOS81                                                            */
            __IOM uint32_t TOS82 : 1;  /*!< [18..18] TOS82                                                            */
            __IOM uint32_t TOS83 : 1;  /*!< [19..19] TOS83                                                            */
            __IOM uint32_t TOS84 : 1;  /*!< [20..20] TOS84                                                            */
            __IOM uint32_t TOS85 : 1;  /*!< [21..21] TOS85                                                            */
            __IOM uint32_t TOS86 : 1;  /*!< [22..22] TOS86                                                            */
            __IOM uint32_t TOS87 : 1;  /*!< [23..23] TOS87                                                            */
            __IOM uint32_t TOS88 : 1;  /*!< [24..24] TOS88                                                            */
            __IOM uint32_t TOS89 : 1;  /*!< [25..25] TOS89                                                            */
            __IOM uint32_t TOS90 : 1;  /*!< [26..26] TOS90                                                            */
            __IOM uint32_t TOS91 : 1;  /*!< [27..27] TOS91                                                            */
            __IOM uint32_t TOS92 : 1;  /*!< [28..28] TOS92                                                            */
            __IOM uint32_t TOS93 : 1;  /*!< [29..29] TOS93                                                            */
            __IOM uint32_t TOS94 : 1;  /*!< [30..30] TOS94                                                            */
            __IOM uint32_t TOS95 : 1;  /*!< [31..31] TOS95                                                            */
        } FWEIS81_b;
    };

    union
    {
        __IOM uint32_t FWEIE81;        /*!< (@ 0x00007AE4) Forwarding Engine Error Interrupt Enable Register
                                        *                  81 (FWEIE81)                                               */

        struct
        {
            __IOM uint32_t TOE64 : 1;  /*!< [0..0] TOE64                                                              */
            __IOM uint32_t TOE65 : 1;  /*!< [1..1] TOE65                                                              */
            __IOM uint32_t TOE66 : 1;  /*!< [2..2] TOE66                                                              */
            __IOM uint32_t TOE67 : 1;  /*!< [3..3] TOE67                                                              */
            __IOM uint32_t TOE68 : 1;  /*!< [4..4] TOE68                                                              */
            __IOM uint32_t TOE69 : 1;  /*!< [5..5] TOE69                                                              */
            __IOM uint32_t TOE70 : 1;  /*!< [6..6] TOE70                                                              */
            __IOM uint32_t TOE71 : 1;  /*!< [7..7] TOE71                                                              */
            __IOM uint32_t TOE72 : 1;  /*!< [8..8] TOE72                                                              */
            __IOM uint32_t TOE73 : 1;  /*!< [9..9] TOE73                                                              */
            __IOM uint32_t TOE74 : 1;  /*!< [10..10] TOE74                                                            */
            __IOM uint32_t TOE75 : 1;  /*!< [11..11] TOE75                                                            */
            __IOM uint32_t TOE76 : 1;  /*!< [12..12] TOE76                                                            */
            __IOM uint32_t TOE77 : 1;  /*!< [13..13] TOE77                                                            */
            __IOM uint32_t TOE78 : 1;  /*!< [14..14] TOE78                                                            */
            __IOM uint32_t TOE79 : 1;  /*!< [15..15] TOE79                                                            */
            __IOM uint32_t TOE80 : 1;  /*!< [16..16] TOE80                                                            */
            __IOM uint32_t TOE81 : 1;  /*!< [17..17] TOE81                                                            */
            __IOM uint32_t TOE82 : 1;  /*!< [18..18] TOE82                                                            */
            __IOM uint32_t TOE83 : 1;  /*!< [19..19] TOE83                                                            */
            __IOM uint32_t TOE84 : 1;  /*!< [20..20] TOE84                                                            */
            __IOM uint32_t TOE85 : 1;  /*!< [21..21] TOE85                                                            */
            __IOM uint32_t TOE86 : 1;  /*!< [22..22] TOE86                                                            */
            __IOM uint32_t TOE87 : 1;  /*!< [23..23] TOE87                                                            */
            __IOM uint32_t TOE88 : 1;  /*!< [24..24] TOE88                                                            */
            __IOM uint32_t TOE89 : 1;  /*!< [25..25] TOE89                                                            */
            __IOM uint32_t TOE90 : 1;  /*!< [26..26] TOE90                                                            */
            __IOM uint32_t TOE91 : 1;  /*!< [27..27] TOE91                                                            */
            __IOM uint32_t TOE92 : 1;  /*!< [28..28] TOE92                                                            */
            __IOM uint32_t TOE93 : 1;  /*!< [29..29] TOE93                                                            */
            __IOM uint32_t TOE94 : 1;  /*!< [30..30] TOE94                                                            */
            __IOM uint32_t TOE95 : 1;  /*!< [31..31] TOE95                                                            */
        } FWEIE81_b;
    };

    union
    {
        __IOM uint32_t FWEID81;        /*!< (@ 0x00007AE8) Forwarding Engine Error Interrupt Disable Register
                                        *                  81 (FWEID81)                                               */

        struct
        {
            __IOM uint32_t TOD64 : 1;  /*!< [0..0] TOD64                                                              */
            __IOM uint32_t TOD65 : 1;  /*!< [1..1] TOD65                                                              */
            __IOM uint32_t TOD66 : 1;  /*!< [2..2] TOD66                                                              */
            __IOM uint32_t TOD67 : 1;  /*!< [3..3] TOD67                                                              */
            __IOM uint32_t TOD68 : 1;  /*!< [4..4] TOD68                                                              */
            __IOM uint32_t TOD69 : 1;  /*!< [5..5] TOD69                                                              */
            __IOM uint32_t TOD70 : 1;  /*!< [6..6] TOD70                                                              */
            __IOM uint32_t TOD71 : 1;  /*!< [7..7] TOD71                                                              */
            __IOM uint32_t TOD72 : 1;  /*!< [8..8] TOD72                                                              */
            __IOM uint32_t TOD73 : 1;  /*!< [9..9] TOD73                                                              */
            __IOM uint32_t TOD74 : 1;  /*!< [10..10] TOD74                                                            */
            __IOM uint32_t TOD75 : 1;  /*!< [11..11] TOD75                                                            */
            __IOM uint32_t TOD76 : 1;  /*!< [12..12] TOD76                                                            */
            __IOM uint32_t TOD77 : 1;  /*!< [13..13] TOD77                                                            */
            __IOM uint32_t TOD78 : 1;  /*!< [14..14] TOD78                                                            */
            __IOM uint32_t TOD79 : 1;  /*!< [15..15] TOD79                                                            */
            __IOM uint32_t TOD80 : 1;  /*!< [16..16] TOD80                                                            */
            __IOM uint32_t TOD81 : 1;  /*!< [17..17] TOD81                                                            */
            __IOM uint32_t TOD82 : 1;  /*!< [18..18] TOD82                                                            */
            __IOM uint32_t TOD83 : 1;  /*!< [19..19] TOD83                                                            */
            __IOM uint32_t TOD84 : 1;  /*!< [20..20] TOD84                                                            */
            __IOM uint32_t TOD85 : 1;  /*!< [21..21] TOD85                                                            */
            __IOM uint32_t TOD86 : 1;  /*!< [22..22] TOD86                                                            */
            __IOM uint32_t TOD87 : 1;  /*!< [23..23] TOD87                                                            */
            __IOM uint32_t TOD88 : 1;  /*!< [24..24] TOD88                                                            */
            __IOM uint32_t TOD89 : 1;  /*!< [25..25] TOD89                                                            */
            __IOM uint32_t TOD90 : 1;  /*!< [26..26] TOD90                                                            */
            __IOM uint32_t TOD91 : 1;  /*!< [27..27] TOD91                                                            */
            __IOM uint32_t TOD92 : 1;  /*!< [28..28] TOD92                                                            */
            __IOM uint32_t TOD93 : 1;  /*!< [29..29] TOD93                                                            */
            __IOM uint32_t TOD94 : 1;  /*!< [30..30] TOD94                                                            */
            __IOM uint32_t TOD95 : 1;  /*!< [31..31] TOD95                                                            */
        } FWEID81_b;
    };
    __IM uint32_t RESERVED277;

    union
    {
        __IOM uint32_t FWEIS82;        /*!< (@ 0x00007AF0) Forwarding Engine Error Interrupt Status Register
                                        *                  82 (FWEIS82)                                               */

        struct
        {
            __IOM uint32_t TOS32 : 1;  /*!< [0..0] TOS32                                                              */
            __IOM uint32_t TOS33 : 1;  /*!< [1..1] TOS33                                                              */
            __IOM uint32_t TOS34 : 1;  /*!< [2..2] TOS34                                                              */
            __IOM uint32_t TOS35 : 1;  /*!< [3..3] TOS35                                                              */
            __IOM uint32_t TOS36 : 1;  /*!< [4..4] TOS36                                                              */
            __IOM uint32_t TOS37 : 1;  /*!< [5..5] TOS37                                                              */
            __IOM uint32_t TOS38 : 1;  /*!< [6..6] TOS38                                                              */
            __IOM uint32_t TOS39 : 1;  /*!< [7..7] TOS39                                                              */
            __IOM uint32_t TOS40 : 1;  /*!< [8..8] TOS40                                                              */
            __IOM uint32_t TOS41 : 1;  /*!< [9..9] TOS41                                                              */
            __IOM uint32_t TOS42 : 1;  /*!< [10..10] TOS42                                                            */
            __IOM uint32_t TOS43 : 1;  /*!< [11..11] TOS43                                                            */
            __IOM uint32_t TOS44 : 1;  /*!< [12..12] TOS44                                                            */
            __IOM uint32_t TOS45 : 1;  /*!< [13..13] TOS45                                                            */
            __IOM uint32_t TOS46 : 1;  /*!< [14..14] TOS46                                                            */
            __IOM uint32_t TOS47 : 1;  /*!< [15..15] TOS47                                                            */
            __IOM uint32_t TOS48 : 1;  /*!< [16..16] TOS48                                                            */
            __IOM uint32_t TOS49 : 1;  /*!< [17..17] TOS49                                                            */
            __IOM uint32_t TOS50 : 1;  /*!< [18..18] TOS50                                                            */
            __IOM uint32_t TOS51 : 1;  /*!< [19..19] TOS51                                                            */
            __IOM uint32_t TOS52 : 1;  /*!< [20..20] TOS52                                                            */
            __IOM uint32_t TOS53 : 1;  /*!< [21..21] TOS53                                                            */
            __IOM uint32_t TOS54 : 1;  /*!< [22..22] TOS54                                                            */
            __IOM uint32_t TOS55 : 1;  /*!< [23..23] TOS55                                                            */
            __IOM uint32_t TOS56 : 1;  /*!< [24..24] TOS56                                                            */
            __IOM uint32_t TOS57 : 1;  /*!< [25..25] TOS57                                                            */
            __IOM uint32_t TOS58 : 1;  /*!< [26..26] TOS58                                                            */
            __IOM uint32_t TOS59 : 1;  /*!< [27..27] TOS59                                                            */
            __IOM uint32_t TOS60 : 1;  /*!< [28..28] TOS60                                                            */
            __IOM uint32_t TOS61 : 1;  /*!< [29..29] TOS61                                                            */
            __IOM uint32_t TOS62 : 1;  /*!< [30..30] TOS62                                                            */
            __IOM uint32_t TOS63 : 1;  /*!< [31..31] TOS63                                                            */
        } FWEIS82_b;
    };

    union
    {
        __IOM uint32_t FWEIE82;        /*!< (@ 0x00007AF4) Forwarding Engine Error Interrupt Enable Register
                                        *                  82 (FWEIE82)                                               */

        struct
        {
            __IOM uint32_t TOE32 : 1;  /*!< [0..0] TOE32                                                              */
            __IOM uint32_t TOE33 : 1;  /*!< [1..1] TOE33                                                              */
            __IOM uint32_t TOE34 : 1;  /*!< [2..2] TOE34                                                              */
            __IOM uint32_t TOE35 : 1;  /*!< [3..3] TOE35                                                              */
            __IOM uint32_t TOE36 : 1;  /*!< [4..4] TOE36                                                              */
            __IOM uint32_t TOE37 : 1;  /*!< [5..5] TOE37                                                              */
            __IOM uint32_t TOE38 : 1;  /*!< [6..6] TOE38                                                              */
            __IOM uint32_t TOE39 : 1;  /*!< [7..7] TOE39                                                              */
            __IOM uint32_t TOE40 : 1;  /*!< [8..8] TOE40                                                              */
            __IOM uint32_t TOE41 : 1;  /*!< [9..9] TOE41                                                              */
            __IOM uint32_t TOE42 : 1;  /*!< [10..10] TOE42                                                            */
            __IOM uint32_t TOE43 : 1;  /*!< [11..11] TOE43                                                            */
            __IOM uint32_t TOE44 : 1;  /*!< [12..12] TOE44                                                            */
            __IOM uint32_t TOE45 : 1;  /*!< [13..13] TOE45                                                            */
            __IOM uint32_t TOE46 : 1;  /*!< [14..14] TOE46                                                            */
            __IOM uint32_t TOE47 : 1;  /*!< [15..15] TOE47                                                            */
            __IOM uint32_t TOE48 : 1;  /*!< [16..16] TOE48                                                            */
            __IOM uint32_t TOE49 : 1;  /*!< [17..17] TOE49                                                            */
            __IOM uint32_t TOE50 : 1;  /*!< [18..18] TOE50                                                            */
            __IOM uint32_t TOE51 : 1;  /*!< [19..19] TOE51                                                            */
            __IOM uint32_t TOE52 : 1;  /*!< [20..20] TOE52                                                            */
            __IOM uint32_t TOE53 : 1;  /*!< [21..21] TOE53                                                            */
            __IOM uint32_t TOE54 : 1;  /*!< [22..22] TOE54                                                            */
            __IOM uint32_t TOE55 : 1;  /*!< [23..23] TOE55                                                            */
            __IOM uint32_t TOE56 : 1;  /*!< [24..24] TOE56                                                            */
            __IOM uint32_t TOE57 : 1;  /*!< [25..25] TOE57                                                            */
            __IOM uint32_t TOE58 : 1;  /*!< [26..26] TOE58                                                            */
            __IOM uint32_t TOE59 : 1;  /*!< [27..27] TOE59                                                            */
            __IOM uint32_t TOE60 : 1;  /*!< [28..28] TOE60                                                            */
            __IOM uint32_t TOE61 : 1;  /*!< [29..29] TOE61                                                            */
            __IOM uint32_t TOE62 : 1;  /*!< [30..30] TOE62                                                            */
            __IOM uint32_t TOE63 : 1;  /*!< [31..31] TOE63                                                            */
        } FWEIE82_b;
    };

    union
    {
        __IOM uint32_t FWEID82;        /*!< (@ 0x00007AF8) Forwarding Engine Error Interrupt Disable Register
                                        *                  82 (FWEID82)                                               */

        struct
        {
            __IOM uint32_t TOD32 : 1;  /*!< [0..0] TOD32                                                              */
            __IOM uint32_t TOD33 : 1;  /*!< [1..1] TOD33                                                              */
            __IOM uint32_t TOD34 : 1;  /*!< [2..2] TOD34                                                              */
            __IOM uint32_t TOD35 : 1;  /*!< [3..3] TOD35                                                              */
            __IOM uint32_t TOD36 : 1;  /*!< [4..4] TOD36                                                              */
            __IOM uint32_t TOD37 : 1;  /*!< [5..5] TOD37                                                              */
            __IOM uint32_t TOD38 : 1;  /*!< [6..6] TOD38                                                              */
            __IOM uint32_t TOD39 : 1;  /*!< [7..7] TOD39                                                              */
            __IOM uint32_t TOD40 : 1;  /*!< [8..8] TOD40                                                              */
            __IOM uint32_t TOD41 : 1;  /*!< [9..9] TOD41                                                              */
            __IOM uint32_t TOD42 : 1;  /*!< [10..10] TOD42                                                            */
            __IOM uint32_t TOD43 : 1;  /*!< [11..11] TOD43                                                            */
            __IOM uint32_t TOD44 : 1;  /*!< [12..12] TOD44                                                            */
            __IOM uint32_t TOD45 : 1;  /*!< [13..13] TOD45                                                            */
            __IOM uint32_t TOD46 : 1;  /*!< [14..14] TOD46                                                            */
            __IOM uint32_t TOD47 : 1;  /*!< [15..15] TOD47                                                            */
            __IOM uint32_t TOD48 : 1;  /*!< [16..16] TOD48                                                            */
            __IOM uint32_t TOD49 : 1;  /*!< [17..17] TOD49                                                            */
            __IOM uint32_t TOD50 : 1;  /*!< [18..18] TOD50                                                            */
            __IOM uint32_t TOD51 : 1;  /*!< [19..19] TOD51                                                            */
            __IOM uint32_t TOD52 : 1;  /*!< [20..20] TOD52                                                            */
            __IOM uint32_t TOD53 : 1;  /*!< [21..21] TOD53                                                            */
            __IOM uint32_t TOD54 : 1;  /*!< [22..22] TOD54                                                            */
            __IOM uint32_t TOD55 : 1;  /*!< [23..23] TOD55                                                            */
            __IOM uint32_t TOD56 : 1;  /*!< [24..24] TOD56                                                            */
            __IOM uint32_t TOD57 : 1;  /*!< [25..25] TOD57                                                            */
            __IOM uint32_t TOD58 : 1;  /*!< [26..26] TOD58                                                            */
            __IOM uint32_t TOD59 : 1;  /*!< [27..27] TOD59                                                            */
            __IOM uint32_t TOD60 : 1;  /*!< [28..28] TOD60                                                            */
            __IOM uint32_t TOD61 : 1;  /*!< [29..29] TOD61                                                            */
            __IOM uint32_t TOD62 : 1;  /*!< [30..30] TOD62                                                            */
            __IOM uint32_t TOD63 : 1;  /*!< [31..31] TOD63                                                            */
        } FWEID82_b;
    };
    __IM uint32_t RESERVED278;

    union
    {
        __IOM uint32_t FWEIS83;        /*!< (@ 0x00007B00) Forwarding Engine Error Interrupt Status Register
                                        *                  83 (FWEIS83)                                               */

        struct
        {
            __IOM uint32_t TOS0  : 1;  /*!< [0..0] TOS0                                                               */
            __IOM uint32_t TOS1  : 1;  /*!< [1..1] TOS1                                                               */
            __IOM uint32_t TOS2  : 1;  /*!< [2..2] TOS2                                                               */
            __IOM uint32_t TOS3  : 1;  /*!< [3..3] TOS3                                                               */
            __IOM uint32_t TOS4  : 1;  /*!< [4..4] TOS4                                                               */
            __IOM uint32_t TOS5  : 1;  /*!< [5..5] TOS5                                                               */
            __IOM uint32_t TOS6  : 1;  /*!< [6..6] TOS6                                                               */
            __IOM uint32_t TOS7  : 1;  /*!< [7..7] TOS7                                                               */
            __IOM uint32_t TOS8  : 1;  /*!< [8..8] TOS8                                                               */
            __IOM uint32_t TOS9  : 1;  /*!< [9..9] TOS9                                                               */
            __IOM uint32_t TOS10 : 1;  /*!< [10..10] TOS10                                                            */
            __IOM uint32_t TOS11 : 1;  /*!< [11..11] TOS11                                                            */
            __IOM uint32_t TOS12 : 1;  /*!< [12..12] TOS12                                                            */
            __IOM uint32_t TOS13 : 1;  /*!< [13..13] TOS13                                                            */
            __IOM uint32_t TOS14 : 1;  /*!< [14..14] TOS14                                                            */
            __IOM uint32_t TOS15 : 1;  /*!< [15..15] TOS15                                                            */
            __IOM uint32_t TOS16 : 1;  /*!< [16..16] TOS16                                                            */
            __IOM uint32_t TOS17 : 1;  /*!< [17..17] TOS17                                                            */
            __IOM uint32_t TOS18 : 1;  /*!< [18..18] TOS18                                                            */
            __IOM uint32_t TOS19 : 1;  /*!< [19..19] TOS19                                                            */
            __IOM uint32_t TOS20 : 1;  /*!< [20..20] TOS20                                                            */
            __IOM uint32_t TOS21 : 1;  /*!< [21..21] TOS21                                                            */
            __IOM uint32_t TOS22 : 1;  /*!< [22..22] TOS22                                                            */
            __IOM uint32_t TOS23 : 1;  /*!< [23..23] TOS23                                                            */
            __IOM uint32_t TOS24 : 1;  /*!< [24..24] TOS24                                                            */
            __IOM uint32_t TOS25 : 1;  /*!< [25..25] TOS25                                                            */
            __IOM uint32_t TOS26 : 1;  /*!< [26..26] TOS26                                                            */
            __IOM uint32_t TOS27 : 1;  /*!< [27..27] TOS27                                                            */
            __IOM uint32_t TOS28 : 1;  /*!< [28..28] TOS28                                                            */
            __IOM uint32_t TOS29 : 1;  /*!< [29..29] TOS29                                                            */
            __IOM uint32_t TOS30 : 1;  /*!< [30..30] TOS30                                                            */
            __IOM uint32_t TOS31 : 1;  /*!< [31..31] TOS31                                                            */
        } FWEIS83_b;
    };

    union
    {
        __IOM uint32_t FWEIE83;        /*!< (@ 0x00007B04) Forwarding Engine Error Interrupt Enable Register
                                        *                  83 (FWEIE83)                                               */

        struct
        {
            __IOM uint32_t TOE0  : 1;  /*!< [0..0] TOE0                                                               */
            __IOM uint32_t TOE1  : 1;  /*!< [1..1] TOE1                                                               */
            __IOM uint32_t TOE2  : 1;  /*!< [2..2] TOE2                                                               */
            __IOM uint32_t TOE3  : 1;  /*!< [3..3] TOE3                                                               */
            __IOM uint32_t TOE4  : 1;  /*!< [4..4] TOE4                                                               */
            __IOM uint32_t TOE5  : 1;  /*!< [5..5] TOE5                                                               */
            __IOM uint32_t TOE6  : 1;  /*!< [6..6] TOE6                                                               */
            __IOM uint32_t TOE7  : 1;  /*!< [7..7] TOE7                                                               */
            __IOM uint32_t TOE8  : 1;  /*!< [8..8] TOE8                                                               */
            __IOM uint32_t TOE9  : 1;  /*!< [9..9] TOE9                                                               */
            __IOM uint32_t TOE10 : 1;  /*!< [10..10] TOE10                                                            */
            __IOM uint32_t TOE11 : 1;  /*!< [11..11] TOE11                                                            */
            __IOM uint32_t TOE12 : 1;  /*!< [12..12] TOE12                                                            */
            __IOM uint32_t TOE13 : 1;  /*!< [13..13] TOE13                                                            */
            __IOM uint32_t TOE14 : 1;  /*!< [14..14] TOE14                                                            */
            __IOM uint32_t TOE15 : 1;  /*!< [15..15] TOE15                                                            */
            __IOM uint32_t TOE16 : 1;  /*!< [16..16] TOE16                                                            */
            __IOM uint32_t TOE17 : 1;  /*!< [17..17] TOE17                                                            */
            __IOM uint32_t TOE18 : 1;  /*!< [18..18] TOE18                                                            */
            __IOM uint32_t TOE19 : 1;  /*!< [19..19] TOE19                                                            */
            __IOM uint32_t TOE20 : 1;  /*!< [20..20] TOE20                                                            */
            __IOM uint32_t TOE21 : 1;  /*!< [21..21] TOE21                                                            */
            __IOM uint32_t TOE22 : 1;  /*!< [22..22] TOE22                                                            */
            __IOM uint32_t TOE23 : 1;  /*!< [23..23] TOE23                                                            */
            __IOM uint32_t TOE24 : 1;  /*!< [24..24] TOE24                                                            */
            __IOM uint32_t TOE25 : 1;  /*!< [25..25] TOE25                                                            */
            __IOM uint32_t TOE26 : 1;  /*!< [26..26] TOE26                                                            */
            __IOM uint32_t TOE27 : 1;  /*!< [27..27] TOE27                                                            */
            __IOM uint32_t TOE28 : 1;  /*!< [28..28] TOE28                                                            */
            __IOM uint32_t TOE29 : 1;  /*!< [29..29] TOE29                                                            */
            __IOM uint32_t TOE30 : 1;  /*!< [30..30] TOE30                                                            */
            __IOM uint32_t TOE31 : 1;  /*!< [31..31] TOE31                                                            */
        } FWEIE83_b;
    };

    union
    {
        __IOM uint32_t FWEID83;        /*!< (@ 0x00007B08) Forwarding Engine Error Interrupt Disable Register
                                        *                  83 (FWEID83)                                               */

        struct
        {
            __IOM uint32_t TOD0  : 1;  /*!< [0..0] TOD0                                                               */
            __IOM uint32_t TOD1  : 1;  /*!< [1..1] TOD1                                                               */
            __IOM uint32_t TOD2  : 1;  /*!< [2..2] TOD2                                                               */
            __IOM uint32_t TOD3  : 1;  /*!< [3..3] TOD3                                                               */
            __IOM uint32_t TOD4  : 1;  /*!< [4..4] TOD4                                                               */
            __IOM uint32_t TOD5  : 1;  /*!< [5..5] TOD5                                                               */
            __IOM uint32_t TOD6  : 1;  /*!< [6..6] TOD6                                                               */
            __IOM uint32_t TOD7  : 1;  /*!< [7..7] TOD7                                                               */
            __IOM uint32_t TOD8  : 1;  /*!< [8..8] TOD8                                                               */
            __IOM uint32_t TOD9  : 1;  /*!< [9..9] TOD9                                                               */
            __IOM uint32_t TOD10 : 1;  /*!< [10..10] TOD10                                                            */
            __IOM uint32_t TOD11 : 1;  /*!< [11..11] TOD11                                                            */
            __IOM uint32_t TOD12 : 1;  /*!< [12..12] TOD12                                                            */
            __IOM uint32_t TOD13 : 1;  /*!< [13..13] TOD13                                                            */
            __IOM uint32_t TOD14 : 1;  /*!< [14..14] TOD14                                                            */
            __IOM uint32_t TOD15 : 1;  /*!< [15..15] TOD15                                                            */
            __IOM uint32_t TOD16 : 1;  /*!< [16..16] TOD16                                                            */
            __IOM uint32_t TOD17 : 1;  /*!< [17..17] TOD17                                                            */
            __IOM uint32_t TOD18 : 1;  /*!< [18..18] TOD18                                                            */
            __IOM uint32_t TOD19 : 1;  /*!< [19..19] TOD19                                                            */
            __IOM uint32_t TOD20 : 1;  /*!< [20..20] TOD20                                                            */
            __IOM uint32_t TOD21 : 1;  /*!< [21..21] TOD21                                                            */
            __IOM uint32_t TOD22 : 1;  /*!< [22..22] TOD22                                                            */
            __IOM uint32_t TOD23 : 1;  /*!< [23..23] TOD23                                                            */
            __IOM uint32_t TOD24 : 1;  /*!< [24..24] TOD24                                                            */
            __IOM uint32_t TOD25 : 1;  /*!< [25..25] TOD25                                                            */
            __IOM uint32_t TOD26 : 1;  /*!< [26..26] TOD26                                                            */
            __IOM uint32_t TOD27 : 1;  /*!< [27..27] TOD27                                                            */
            __IOM uint32_t TOD28 : 1;  /*!< [28..28] TOD28                                                            */
            __IOM uint32_t TOD29 : 1;  /*!< [29..29] TOD29                                                            */
            __IOM uint32_t TOD30 : 1;  /*!< [30..30] TOD30                                                            */
            __IOM uint32_t TOD31 : 1;  /*!< [31..31] TOD31                                                            */
        } FWEID83_b;
    };
    __IM uint32_t RESERVED279[61];

    union
    {
        __IOM uint32_t FWMIS0;          /*!< (@ 0x00007C00) Forwarding Engine Monitoring Interrupt Status
                                         *                  Register 0 (FWMIS0)                                        */

        struct
        {
            __IOM uint32_t LTHTFS  : 1; /*!< [0..0] LTHTFS                                                             */
            uint32_t               : 1;
            __IOM uint32_t MACTFS  : 1; /*!< [2..2] MACTFS                                                             */
            __IOM uint32_t VLANTFS : 1; /*!< [3..3] VLANTFS                                                            */
            uint32_t               : 13;
            __IOM uint32_t MACADAS : 1; /*!< [17..17] MACADAS                                                          */
            uint32_t               : 14;
        } FWMIS0_b;
    };

    union
    {
        __IOM uint32_t FWMIE0;          /*!< (@ 0x00007C04) Forwarding Engine Monitoring Interrupt Enable
                                         *                  Register 1 (FWMIE0)                                        */

        struct
        {
            __IOM uint32_t LTHTFE  : 1; /*!< [0..0] LTHTFE                                                             */
            uint32_t               : 1;
            __IOM uint32_t MACTFE  : 1; /*!< [2..2] MACTFE                                                             */
            __IOM uint32_t VLANTFE : 1; /*!< [3..3] VLANTFE                                                            */
            uint32_t               : 13;
            __IOM uint32_t MACADAE : 1; /*!< [17..17] MACADAE                                                          */
            uint32_t               : 14;
        } FWMIE0_b;
    };

    union
    {
        __IOM uint32_t FWMID0;          /*!< (@ 0x00007C08) Forwarding Engine Monitoring Interrupt Disable
                                         *                  Register 0 (FWMID0)                                        */

        struct
        {
            __IOM uint32_t LTHTFD  : 1; /*!< [0..0] LTHTFD                                                             */
            uint32_t               : 1;
            __IOM uint32_t MACTFD  : 1; /*!< [2..2] MACTFD                                                             */
            __IOM uint32_t VLANTFD : 1; /*!< [3..3] VLANTFD                                                            */
            uint32_t               : 13;
            __IOM uint32_t MACADAD : 1; /*!< [17..17] MACADAD                                                          */
            uint32_t               : 14;
        } FWMID0_b;
    };
} R_MFWD_Type;                          /*!< Size = 31756 (0x7c0c)                                                     */

#endif                                  /* R_MFWD_REG_H */
