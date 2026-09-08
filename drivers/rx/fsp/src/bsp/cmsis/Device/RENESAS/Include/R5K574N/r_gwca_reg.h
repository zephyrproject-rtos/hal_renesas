/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_GWCA_REG_H
#define R_GWCA_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_GWCA0                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Gateway CPU Agent (R_GWCA0)
 */

typedef struct                         /*!< (@ 0x874CE000) R_GWCA0 Structure                                          */
{
    union
    {
        __IOM uint32_t GWMC;           /*!< (@ 0x00000000) GWCA Mode Configuration Register (GWMC)                    */

        struct
        {
            __IOM uint32_t OPC : 2;    /*!< [1..0] OPC                                                                */
            uint32_t           : 30;
        } GWMC_b;
    };

    union
    {
        __IOM uint32_t GWMS;           /*!< (@ 0x00000004) GWCA Mode Status Register (GWMS)                           */

        struct
        {
            __IOM uint32_t OPS : 2;    /*!< [1..0] OPS                                                                */
            uint32_t           : 30;
        } GWMS_b;
    };
    __IM uint32_t RESERVED[2];

    union
    {
        __IOM uint32_t GWIRC;          /*!< (@ 0x00000010) GWCA IPV Remapping Configuration Register [802.1Q]
                                        *                  (GWIRC)                                                    */

        struct
        {
            __IOM uint32_t IPVR0 : 3;  /*!< [2..0] IPVR0                                                              */
            uint32_t             : 1;
            __IOM uint32_t IPVR1 : 3;  /*!< [6..4] IPVR1                                                              */
            uint32_t             : 1;
            __IOM uint32_t IPVR2 : 3;  /*!< [10..8] IPVR2                                                             */
            uint32_t             : 1;
            __IOM uint32_t IPVR3 : 3;  /*!< [14..12] IPVR3                                                            */
            uint32_t             : 1;
            __IOM uint32_t IPVR4 : 3;  /*!< [18..16] IPVR4                                                            */
            uint32_t             : 1;
            __IOM uint32_t IPVR5 : 3;  /*!< [22..20] IPVR5                                                            */
            uint32_t             : 1;
            __IOM uint32_t IPVR6 : 3;  /*!< [26..24] IPVR6                                                            */
            uint32_t             : 1;
            __IOM uint32_t IPVR7 : 3;  /*!< [30..28] IPVR7                                                            */
            uint32_t             : 1;
        } GWIRC_b;
    };

    union
    {
        __IOM uint32_t GWRDQSC;        /*!< (@ 0x00000014) GWCA RX Descriptor Queue Security Configuration
                                        *                  Register (GWRDQSC)                                         */

        struct
        {
            __IOM uint32_t RDQSL0 : 1; /*!< [0..0] RDQSL0                                                             */
            __IOM uint32_t RDQSL1 : 1; /*!< [1..1] RDQSL1                                                             */
            __IOM uint32_t RDQSL2 : 1; /*!< [2..2] RDQSL2                                                             */
            __IOM uint32_t RDQSL3 : 1; /*!< [3..3] RDQSL3                                                             */
            __IOM uint32_t RDQSL4 : 1; /*!< [4..4] RDQSL4                                                             */
            __IOM uint32_t RDQSL5 : 1; /*!< [5..5] RDQSL5                                                             */
            __IOM uint32_t RDQSL6 : 1; /*!< [6..6] RDQSL6                                                             */
            __IOM uint32_t RDQSL7 : 1; /*!< [7..7] RDQSL7                                                             */
            uint32_t              : 24;
        } GWRDQSC_b;
    };

    union
    {
        __IOM uint32_t GWRDQC;         /*!< (@ 0x00000018) GWCA RX Descriptor Queue Control Register (GWRDQC)         */

        struct
        {
            __IOM uint32_t RDQD0 : 1;  /*!< [0..0] RDQD0                                                              */
            __IOM uint32_t RDQD1 : 1;  /*!< [1..1] RDQD1                                                              */
            __IOM uint32_t RDQD2 : 1;  /*!< [2..2] RDQD2                                                              */
            __IOM uint32_t RDQD3 : 1;  /*!< [3..3] RDQD3                                                              */
            __IOM uint32_t RDQD4 : 1;  /*!< [4..4] RDQD4                                                              */
            __IOM uint32_t RDQD5 : 1;  /*!< [5..5] RDQD5                                                              */
            __IOM uint32_t RDQD6 : 1;  /*!< [6..6] RDQD6                                                              */
            __IOM uint32_t RDQD7 : 1;  /*!< [7..7] RDQD7                                                              */
            uint32_t             : 24;
        } GWRDQC_b;
    };

    union
    {
        __IOM uint32_t GWRDQAC;        /*!< (@ 0x0000001C) GWCA RX Descriptor Queue Arbitration Control
                                        *                  Register (GWRDQAC)                                         */

        struct
        {
            __IOM uint32_t RDQA0 : 4;  /*!< [3..0] RDQA0                                                              */
            __IOM uint32_t RDQA1 : 4;  /*!< [7..4] RDQA1                                                              */
            __IOM uint32_t RDQA2 : 4;  /*!< [11..8] RDQA2                                                             */
            __IOM uint32_t RDQA3 : 4;  /*!< [15..12] RDQA3                                                            */
            __IOM uint32_t RDQA4 : 4;  /*!< [19..16] RDQA4                                                            */
            __IOM uint32_t RDQA5 : 4;  /*!< [23..20] RDQA5                                                            */
            __IOM uint32_t RDQA6 : 4;  /*!< [27..24] RDQA6                                                            */
            __IOM uint32_t RDQA7 : 4;  /*!< [31..28] RDQA7                                                            */
        } GWRDQAC_b;
    };

    union
    {
        __IOM uint32_t GWRGC;          /*!< (@ 0x00000020) GWCA RX General Configuration Register (GWRGC)             */

        struct
        {
            __IOM uint32_t RCPT : 1;   /*!< [0..0] RCPT                                                               */
            uint32_t            : 31;
        } GWRGC_b;
    };
    __IM uint32_t RESERVED1[7];

    union
    {
        __IOM uint32_t GWRMFSC0;       /*!< (@ 0x00000040) GWCA Reception Maximum Frame Size Configuration
                                        *                  Register q (GWRMFSCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } GWRMFSC0_b;
    };

    union
    {
        __IOM uint32_t GWRMFSC1;       /*!< (@ 0x00000044) GWCA Reception Maximum Frame Size Configuration
                                        *                  Register q (GWRMFSCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } GWRMFSC1_b;
    };

    union
    {
        __IOM uint32_t GWRMFSC2;       /*!< (@ 0x00000048) GWCA Reception Maximum Frame Size Configuration
                                        *                  Register q (GWRMFSCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } GWRMFSC2_b;
    };

    union
    {
        __IOM uint32_t GWRMFSC3;       /*!< (@ 0x0000004C) GWCA Reception Maximum Frame Size Configuration
                                        *                  Register q (GWRMFSCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } GWRMFSC3_b;
    };

    union
    {
        __IOM uint32_t GWRMFSC4;       /*!< (@ 0x00000050) GWCA Reception Maximum Frame Size Configuration
                                        *                  Register q (GWRMFSCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } GWRMFSC4_b;
    };

    union
    {
        __IOM uint32_t GWRMFSC5;       /*!< (@ 0x00000054) GWCA Reception Maximum Frame Size Configuration
                                        *                  Register q (GWRMFSCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } GWRMFSC5_b;
    };

    union
    {
        __IOM uint32_t GWRMFSC6;       /*!< (@ 0x00000058) GWCA Reception Maximum Frame Size Configuration
                                        *                  Register q (GWRMFSCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } GWRMFSC6_b;
    };

    union
    {
        __IOM uint32_t GWRMFSC7;       /*!< (@ 0x0000005C) GWCA Reception Maximum Frame Size Configuration
                                        *                  Register q (GWRMFSCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } GWRMFSC7_b;
    };

    union
    {
        __IOM uint32_t GWRDQDC0;       /*!< (@ 0x00000060) GWCA Reception Descriptor Queue Depth Configuration
                                        *                  Register q (GWRDQDCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } GWRDQDC0_b;
    };

    union
    {
        __IOM uint32_t GWRDQDC1;       /*!< (@ 0x00000064) GWCA Reception Descriptor Queue Depth Configuration
                                        *                  Register q (GWRDQDCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } GWRDQDC1_b;
    };

    union
    {
        __IOM uint32_t GWRDQDC2;       /*!< (@ 0x00000068) GWCA Reception Descriptor Queue Depth Configuration
                                        *                  Register q (GWRDQDCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } GWRDQDC2_b;
    };

    union
    {
        __IOM uint32_t GWRDQDC3;       /*!< (@ 0x0000006C) GWCA Reception Descriptor Queue Depth Configuration
                                        *                  Register q (GWRDQDCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } GWRDQDC3_b;
    };

    union
    {
        __IOM uint32_t GWRDQDC4;       /*!< (@ 0x00000070) GWCA Reception Descriptor Queue Depth Configuration
                                        *                  Register q (GWRDQDCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } GWRDQDC4_b;
    };

    union
    {
        __IOM uint32_t GWRDQDC5;       /*!< (@ 0x00000074) GWCA Reception Descriptor Queue Depth Configuration
                                        *                  Register q (GWRDQDCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } GWRDQDC5_b;
    };

    union
    {
        __IOM uint32_t GWRDQDC6;       /*!< (@ 0x00000078) GWCA Reception Descriptor Queue Depth Configuration
                                        *                  Register q (GWRDQDCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } GWRDQDC6_b;
    };

    union
    {
        __IOM uint32_t GWRDQDC7;       /*!< (@ 0x0000007C) GWCA Reception Descriptor Queue Depth Configuration
                                        *                  Register q (GWRDQDCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } GWRDQDC7_b;
    };

    union
    {
        __IOM uint32_t GWRDQM0;        /*!< (@ 0x00000080) GWCA RX Descriptor Queue q Monitoring Register
                                        *                  (GWRDQMq) (q = 0 to 7)                                     */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } GWRDQM0_b;
    };

    union
    {
        __IOM uint32_t GWRDQM1;        /*!< (@ 0x00000084) GWCA RX Descriptor Queue q Monitoring Register
                                        *                  (GWRDQMq) (q = 0 to 7)                                     */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } GWRDQM1_b;
    };

    union
    {
        __IOM uint32_t GWRDQM2;        /*!< (@ 0x00000088) GWCA RX Descriptor Queue q Monitoring Register
                                        *                  (GWRDQMq) (q = 0 to 7)                                     */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } GWRDQM2_b;
    };

    union
    {
        __IOM uint32_t GWRDQM3;        /*!< (@ 0x0000008C) GWCA RX Descriptor Queue q Monitoring Register
                                        *                  (GWRDQMq) (q = 0 to 7)                                     */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } GWRDQM3_b;
    };

    union
    {
        __IOM uint32_t GWRDQM4;        /*!< (@ 0x00000090) GWCA RX Descriptor Queue q Monitoring Register
                                        *                  (GWRDQMq) (q = 0 to 7)                                     */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } GWRDQM4_b;
    };

    union
    {
        __IOM uint32_t GWRDQM5;        /*!< (@ 0x00000094) GWCA RX Descriptor Queue q Monitoring Register
                                        *                  (GWRDQMq) (q = 0 to 7)                                     */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } GWRDQM5_b;
    };

    union
    {
        __IOM uint32_t GWRDQM6;        /*!< (@ 0x00000098) GWCA RX Descriptor Queue q Monitoring Register
                                        *                  (GWRDQMq) (q = 0 to 7)                                     */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } GWRDQM6_b;
    };

    union
    {
        __IOM uint32_t GWRDQM7;        /*!< (@ 0x0000009C) GWCA RX Descriptor Queue q Monitoring Register
                                        *                  (GWRDQMq) (q = 0 to 7)                                     */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } GWRDQM7_b;
    };

    union
    {
        __IOM uint32_t GWRDQMLM0;      /*!< (@ 0x000000A0) GWCA RX Descriptor Queue q Max Level Monitoring
                                        *                  Register (GWRDQMLMq) (q = 0 to 7)                          */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } GWRDQMLM0_b;
    };

    union
    {
        __IOM uint32_t GWRDQMLM1;      /*!< (@ 0x000000A4) GWCA RX Descriptor Queue q Max Level Monitoring
                                        *                  Register (GWRDQMLMq) (q = 0 to 7)                          */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } GWRDQMLM1_b;
    };

    union
    {
        __IOM uint32_t GWRDQMLM2;      /*!< (@ 0x000000A8) GWCA RX Descriptor Queue q Max Level Monitoring
                                        *                  Register (GWRDQMLMq) (q = 0 to 7)                          */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } GWRDQMLM2_b;
    };

    union
    {
        __IOM uint32_t GWRDQMLM3;      /*!< (@ 0x000000AC) GWCA RX Descriptor Queue q Max Level Monitoring
                                        *                  Register (GWRDQMLMq) (q = 0 to 7)                          */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } GWRDQMLM3_b;
    };

    union
    {
        __IOM uint32_t GWRDQMLM4;      /*!< (@ 0x000000B0) GWCA RX Descriptor Queue q Max Level Monitoring
                                        *                  Register (GWRDQMLMq) (q = 0 to 7)                          */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } GWRDQMLM4_b;
    };

    union
    {
        __IOM uint32_t GWRDQMLM5;      /*!< (@ 0x000000B4) GWCA RX Descriptor Queue q Max Level Monitoring
                                        *                  Register (GWRDQMLMq) (q = 0 to 7)                          */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } GWRDQMLM5_b;
    };

    union
    {
        __IOM uint32_t GWRDQMLM6;      /*!< (@ 0x000000B8) GWCA RX Descriptor Queue q Max Level Monitoring
                                        *                  Register (GWRDQMLMq) (q = 0 to 7)                          */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } GWRDQMLM6_b;
    };

    union
    {
        __IOM uint32_t GWRDQMLM7;      /*!< (@ 0x000000BC) GWCA RX Descriptor Queue q Max Level Monitoring
                                        *                  Register (GWRDQMLMq) (q = 0 to 7)                          */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } GWRDQMLM7_b;
    };
    __IM uint32_t RESERVED2[16];

    union
    {
        __IOM uint32_t GWMTIRM;        /*!< (@ 0x00000100) GWCA Multicast Table Initialization Register
                                        *                  Monitoring Register (GWMTIRM)                              */

        struct
        {
            __IOM uint32_t MTIOG : 1;  /*!< [0..0] MTIOG                                                              */
            __IOM uint32_t MTR   : 1;  /*!< [1..1] MTR                                                                */
            uint32_t             : 30;
        } GWMTIRM_b;
    };

    union
    {
        __IOM uint32_t GWMSTLS;        /*!< (@ 0x00000104) GWCA Multicast Table Learning Setting Register
                                        *                  (GWMSTLS)                                                  */

        struct
        {
            __IOM uint32_t MNRCNL : 6; /*!< [5..0] MNRCNL                                                             */
            uint32_t              : 2;
            __IOM uint32_t MNL    : 3; /*!< [10..8] MNL                                                               */
            uint32_t              : 5;
            __IOM uint32_t MSENL  : 6; /*!< [21..16] MSENL                                                            */
            uint32_t              : 10;
        } GWMSTLS_b;
    };

    union
    {
        __IOM uint32_t GWMSTLR;        /*!< (@ 0x00000108) GWCA Multicast Table Learning Result Register
                                        *                  (GWMSTLR)                                                  */

        struct
        {
            __IOM uint32_t MTLF : 1;   /*!< [0..0] MTLF                                                               */
            uint32_t            : 30;
            __IOM uint32_t MTL  : 1;   /*!< [31..31] MTL                                                              */
        } GWMSTLR_b;
    };

    union
    {
        __IOM uint32_t GWMSTSS;        /*!< (@ 0x0000010C) GWCA Multicast Table Searching Setting Register
                                        *                  (GWMSTSS)                                                  */

        struct
        {
            __IOM uint32_t MSENS : 6;  /*!< [5..0] MSENS                                                              */
            uint32_t             : 26;
        } GWMSTSS_b;
    };

    union
    {
        __IOM uint32_t GWMSTSR;        /*!< (@ 0x00000110) GWCA Multicast Table Searching Result Register
                                        *                  (GWMSTSR)                                                  */

        struct
        {
            __IOM uint32_t MNRCNR : 6; /*!< [5..0] MNRCNR                                                             */
            uint32_t              : 2;
            __IOM uint32_t MNR    : 3; /*!< [10..8] MNR                                                               */
            uint32_t              : 5;
            __IOM uint32_t MTSEF  : 1; /*!< [16..16] MTSEF                                                            */
            uint32_t              : 14;
            __IOM uint32_t MTS    : 1; /*!< [31..31] MTS                                                              */
        } GWMSTSR_b;
    };
    __IM uint32_t RESERVED3[3];

    union
    {
        __IOM uint32_t GWMAC0;         /*!< (@ 0x00000120) GWCA MAC Address Configuration Register 0 (GWMAC0)         */

        struct
        {
            __IOM uint32_t MAUP : 16;  /*!< [15..0] MAUP                                                              */
            uint32_t            : 16;
        } GWMAC0_b;
    };

    union
    {
        __IOM uint32_t GWMAC1;         /*!< (@ 0x00000124) GWCA MAC Address Configuration Register 1 (GWMAC1)         */

        struct
        {
            __IOM uint32_t MADP : 32;  /*!< [31..0] MADP                                                              */
        } GWMAC1_b;
    };
    __IM uint32_t RESERVED4[2];

    union
    {
        __IOM uint32_t GWVCC;          /*!< (@ 0x00000130) GWCA VLAN Control Configuration Register (GWVCC)           */

        struct
        {
            __IOM uint32_t VIM   : 1;  /*!< [0..0] VIM                                                                */
            uint32_t             : 7;
            __IOM uint32_t CTVUM : 1;  /*!< [8..8] CTVUM                                                              */
            uint32_t             : 7;
            __IOM uint32_t VEM   : 3;  /*!< [18..16] VEM                                                              */
            uint32_t             : 13;
        } GWVCC_b;
    };

    union
    {
        __IOM uint32_t GWVTC;          /*!< (@ 0x00000134) GWCA VLAN TAG Configuration Register (GWVTC)               */

        struct
        {
            __IOM uint32_t CTV : 12;   /*!< [11..0] CTV                                                               */
            __IOM uint32_t CTP : 3;    /*!< [14..12] CTP                                                              */
            __IOM uint32_t CTD : 1;    /*!< [15..15] CTD                                                              */
            __IOM uint32_t STV : 12;   /*!< [27..16] STV                                                              */
            __IOM uint32_t STP : 3;    /*!< [30..28] STP                                                              */
            __IOM uint32_t STD : 1;    /*!< [31..31] STD                                                              */
        } GWVTC_b;
    };

    union
    {
        __IOM uint32_t GWTTFC;         /*!< (@ 0x00000138) GWCA Transmission TAG Filtering Configuration
                                        *                  Register (GWTTFC)                                          */

        struct
        {
            __IOM uint32_t NT   : 1;   /*!< [0..0] NT                                                                 */
            __IOM uint32_t RT   : 1;   /*!< [1..1] RT                                                                 */
            __IOM uint32_t CST  : 1;   /*!< [2..2] CST                                                                */
            __IOM uint32_t CSRT : 1;   /*!< [3..3] CSRT                                                               */
            __IOM uint32_t CT   : 1;   /*!< [4..4] CT                                                                 */
            __IOM uint32_t CRT  : 1;   /*!< [5..5] CRT                                                                */
            __IOM uint32_t SCT  : 1;   /*!< [6..6] SCT                                                                */
            __IOM uint32_t SCRT : 1;   /*!< [7..7] SCRT                                                               */
            __IOM uint32_t UT   : 1;   /*!< [8..8] UT                                                                 */
            uint32_t            : 23;
        } GWTTFC_b;
    };
    __IM uint32_t RESERVED5;

    union
    {
        __IOM uint32_t GWTDCAC00;       /*!< (@ 0x00000140) GWCA Timestamp Descriptor Chain Address Configuration
                                         *                  Register 0s (GWTDCAC0s) (s = 0, 1)                         */

        struct
        {
            __IOM uint32_t TSCCAUP : 8; /*!< [7..0] TSCCAUP                                                            */
            uint32_t               : 24;
        } GWTDCAC00_b;
    };

    union
    {
        __IOM uint32_t GWTDCAC01;        /*!< (@ 0x00000144) GWCA Timestamp Descriptor Chain Address Configuration
                                          *                  Register 1s (GWTDCAC1s) (s = 0, 1)                         */

        struct
        {
            __IOM uint32_t TSCCADP : 32; /*!< [31..0] TSCCADP                                                           */
        } GWTDCAC01_b;
    };

    union
    {
        __IOM uint32_t GWTDCAC10;       /*!< (@ 0x00000148) GWCA Timestamp Descriptor Chain Address Configuration
                                         *                  Register 0s (GWTDCAC0s) (s = 0, 1)                         */

        struct
        {
            __IOM uint32_t TSCCAUP : 8; /*!< [7..0] TSCCAUP                                                            */
            uint32_t               : 24;
        } GWTDCAC10_b;
    };

    union
    {
        __IOM uint32_t GWTDCAC11;        /*!< (@ 0x0000014C) GWCA Timestamp Descriptor Chain Address Configuration
                                          *                  Register 1s (GWTDCAC1s) (s = 0, 1)                         */

        struct
        {
            __IOM uint32_t TSCCADP : 32; /*!< [31..0] TSCCADP                                                           */
        } GWTDCAC11_b;
    };
    __IM uint32_t RESERVED6[4];

    union
    {
        __IOM uint32_t GWTSDCC0;       /*!< (@ 0x00000160) GWCA Timestamp Descriptor Chain Configuration
                                        *                  Register s (GWTSDCCs) (s = 0, 1)                           */

        struct
        {
            __IOM uint32_t TE   : 1;   /*!< [0..0] TE                                                                 */
            __IOM uint32_t DCS  : 2;   /*!< [2..1] DCS                                                                */
            uint32_t            : 5;
            __IOM uint32_t OSID : 3;   /*!< [10..8] OSID                                                              */
            uint32_t            : 21;
        } GWTSDCC0_b;
    };

    union
    {
        __IOM uint32_t GWTSDCC1;       /*!< (@ 0x00000164) GWCA Timestamp Descriptor Chain Configuration
                                        *                  Register s (GWTSDCCs) (s = 0, 1)                           */

        struct
        {
            __IOM uint32_t TE   : 1;   /*!< [0..0] TE                                                                 */
            __IOM uint32_t DCS  : 2;   /*!< [2..1] DCS                                                                */
            uint32_t            : 5;
            __IOM uint32_t OSID : 3;   /*!< [10..8] OSID                                                              */
            uint32_t            : 21;
        } GWTSDCC1_b;
    };
    __IM uint32_t RESERVED7[6];

    union
    {
        __IOM uint32_t GWTSNM;         /*!< (@ 0x00000180) GWCA Timestamp Number Monitoring Register (GWTSNM)         */

        struct
        {
            __IOM uint32_t TNTR : 5;   /*!< [4..0] TNTR                                                               */
            uint32_t            : 27;
        } GWTSNM_b;
    };

    union
    {
        __IOM uint32_t GWTSMNM;        /*!< (@ 0x00000184) GWCA Timestamp Maximum Number Monitoring Register
                                        *                  (GWTSMNM)                                                  */

        struct
        {
            __IOM uint32_t TMNTR : 5;  /*!< [4..0] TMNTR                                                              */
            uint32_t             : 27;
        } GWTSMNM_b;
    };
    __IM uint32_t RESERVED8[2];

    union
    {
        __IOM uint32_t GWAC;           /*!< (@ 0x00000190) GWCA AXI Control Register (GWAC)                           */

        struct
        {
            __IOM uint32_t AMPR : 1;   /*!< [0..0] AMPR                                                               */
            __IOM uint32_t AMP  : 1;   /*!< [1..1] AMP                                                                */
            uint32_t            : 30;
        } GWAC_b;
    };

    union
    {
        __IOM uint32_t GWDCBAC0;       /*!< (@ 0x00000194) GWCA Descriptor Chain Base Address Configuration
                                        *                  Register 0 (GWDCBAC0)                                      */

        struct
        {
            __IOM uint32_t DCBAUP : 8; /*!< [7..0] DCBAUP                                                             */
            uint32_t              : 24;
        } GWDCBAC0_b;
    };

    union
    {
        __IOM uint32_t GWDCBAC1;        /*!< (@ 0x00000198) GWCA Descriptor Chain Base Address Configuration
                                         *                  Register 1 (GWDCBAC1)                                      */

        struct
        {
            __IOM uint32_t DCBADP : 32; /*!< [31..0] DCBADP                                                            */
        } GWDCBAC1_b;
    };
    __IM uint32_t RESERVED9;

    union
    {
        __IOM uint32_t GWMDNC;         /*!< (@ 0x000001A0) GWCA Maximum Descriptor Number Configuration
                                        *                  Register (GWMDNC)                                          */

        struct
        {
            __IOM uint32_t RXDMN : 5;  /*!< [4..0] RXDMN                                                              */
            uint32_t             : 3;
            __IOM uint32_t TXDMN : 5;  /*!< [12..8] TXDMN                                                             */
            uint32_t             : 3;
            __IOM uint32_t TSDMN : 2;  /*!< [17..16] TSDMN                                                            */
            uint32_t             : 14;
        } GWMDNC_b;
    };
    __IM uint32_t  RESERVED10[23];
    __IOM uint32_t GWTRC0;             /*!< (@ 0x00000200) GWCA Transmission Request Configuration Register
                                        *                  i (GWTRCi) (i = 0, 1)                                      */
    __IOM uint32_t GWTRC1;             /*!< (@ 0x00000204) GWCA Transmission Request Configuration Register
                                        *                  i (GWTRCi) (i = 0, 1)                                      */
    __IM uint32_t RESERVED11[62];

    union
    {
        __IOM uint32_t GWTPC0;         /*!< (@ 0x00000300) GWCA Transmission Pause Configuration Register
                                        *                  p (GWTPCp) (p = 0, 1)                                      */

        struct
        {
            __IOM uint32_t PPPL0 : 1;  /*!< [0..0] PPPL0                                                              */
            __IOM uint32_t PPPL1 : 1;  /*!< [1..1] PPPL1                                                              */
            __IOM uint32_t PPPL2 : 1;  /*!< [2..2] PPPL2                                                              */
            __IOM uint32_t PPPL3 : 1;  /*!< [3..3] PPPL3                                                              */
            __IOM uint32_t PPPL4 : 1;  /*!< [4..4] PPPL4                                                              */
            __IOM uint32_t PPPL5 : 1;  /*!< [5..5] PPPL5                                                              */
            __IOM uint32_t PPPL6 : 1;  /*!< [6..6] PPPL6                                                              */
            __IOM uint32_t PPPL7 : 1;  /*!< [7..7] PPPL7                                                              */
            uint32_t             : 24;
        } GWTPC0_b;
    };

    union
    {
        __IOM uint32_t GWTPC1;         /*!< (@ 0x00000304) GWCA Transmission Pause Configuration Register
                                        *                  p (GWTPCp) (p = 0, 1)                                      */

        struct
        {
            __IOM uint32_t PPPL0 : 1;  /*!< [0..0] PPPL0                                                              */
            __IOM uint32_t PPPL1 : 1;  /*!< [1..1] PPPL1                                                              */
            __IOM uint32_t PPPL2 : 1;  /*!< [2..2] PPPL2                                                              */
            __IOM uint32_t PPPL3 : 1;  /*!< [3..3] PPPL3                                                              */
            __IOM uint32_t PPPL4 : 1;  /*!< [4..4] PPPL4                                                              */
            __IOM uint32_t PPPL5 : 1;  /*!< [5..5] PPPL5                                                              */
            __IOM uint32_t PPPL6 : 1;  /*!< [6..6] PPPL6                                                              */
            __IOM uint32_t PPPL7 : 1;  /*!< [7..7] PPPL7                                                              */
            uint32_t             : 24;
        } GWTPC1_b;
    };
    __IM uint32_t RESERVED12[30];

    union
    {
        __IOM uint32_t GWARIRM;        /*!< (@ 0x00000380) GWCA AXI RAM Initialization Register Monitoring
                                        *                  Register (GWARIRM)                                         */

        struct
        {
            __IOM uint32_t ARIOG : 1;  /*!< [0..0] ARIOG                                                              */
            __IOM uint32_t ARR   : 1;  /*!< [1..1] ARR                                                                */
            uint32_t             : 30;
        } GWARIRM_b;
    };
    __IM uint32_t RESERVED13[31];

    union
    {
        __IOM uint32_t GWDCC0;         /*!< (@ 0x00000400) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC0_b;
    };

    union
    {
        __IOM uint32_t GWDCC1;         /*!< (@ 0x00000404) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC1_b;
    };

    union
    {
        __IOM uint32_t GWDCC2;         /*!< (@ 0x00000408) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC2_b;
    };

    union
    {
        __IOM uint32_t GWDCC3;         /*!< (@ 0x0000040C) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC3_b;
    };

    union
    {
        __IOM uint32_t GWDCC4;         /*!< (@ 0x00000410) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC4_b;
    };

    union
    {
        __IOM uint32_t GWDCC5;         /*!< (@ 0x00000414) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC5_b;
    };

    union
    {
        __IOM uint32_t GWDCC6;         /*!< (@ 0x00000418) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC6_b;
    };

    union
    {
        __IOM uint32_t GWDCC7;         /*!< (@ 0x0000041C) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC7_b;
    };

    union
    {
        __IOM uint32_t GWDCC8;         /*!< (@ 0x00000420) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC8_b;
    };

    union
    {
        __IOM uint32_t GWDCC9;         /*!< (@ 0x00000424) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC9_b;
    };

    union
    {
        __IOM uint32_t GWDCC10;        /*!< (@ 0x00000428) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC10_b;
    };

    union
    {
        __IOM uint32_t GWDCC11;        /*!< (@ 0x0000042C) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC11_b;
    };

    union
    {
        __IOM uint32_t GWDCC12;        /*!< (@ 0x00000430) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC12_b;
    };

    union
    {
        __IOM uint32_t GWDCC13;        /*!< (@ 0x00000434) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC13_b;
    };

    union
    {
        __IOM uint32_t GWDCC14;        /*!< (@ 0x00000438) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC14_b;
    };

    union
    {
        __IOM uint32_t GWDCC15;        /*!< (@ 0x0000043C) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC15_b;
    };

    union
    {
        __IOM uint32_t GWDCC16;        /*!< (@ 0x00000440) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC16_b;
    };

    union
    {
        __IOM uint32_t GWDCC17;        /*!< (@ 0x00000444) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC17_b;
    };

    union
    {
        __IOM uint32_t GWDCC18;        /*!< (@ 0x00000448) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC18_b;
    };

    union
    {
        __IOM uint32_t GWDCC19;        /*!< (@ 0x0000044C) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC19_b;
    };

    union
    {
        __IOM uint32_t GWDCC20;        /*!< (@ 0x00000450) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC20_b;
    };

    union
    {
        __IOM uint32_t GWDCC21;        /*!< (@ 0x00000454) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC21_b;
    };

    union
    {
        __IOM uint32_t GWDCC22;        /*!< (@ 0x00000458) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC22_b;
    };

    union
    {
        __IOM uint32_t GWDCC23;        /*!< (@ 0x0000045C) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC23_b;
    };

    union
    {
        __IOM uint32_t GWDCC24;        /*!< (@ 0x00000460) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC24_b;
    };

    union
    {
        __IOM uint32_t GWDCC25;        /*!< (@ 0x00000464) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC25_b;
    };

    union
    {
        __IOM uint32_t GWDCC26;        /*!< (@ 0x00000468) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC26_b;
    };

    union
    {
        __IOM uint32_t GWDCC27;        /*!< (@ 0x0000046C) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC27_b;
    };

    union
    {
        __IOM uint32_t GWDCC28;        /*!< (@ 0x00000470) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC28_b;
    };

    union
    {
        __IOM uint32_t GWDCC29;        /*!< (@ 0x00000474) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC29_b;
    };

    union
    {
        __IOM uint32_t GWDCC30;        /*!< (@ 0x00000478) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC30_b;
    };

    union
    {
        __IOM uint32_t GWDCC31;        /*!< (@ 0x0000047C) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC31_b;
    };

    union
    {
        __IOM uint32_t GWDCC32;        /*!< (@ 0x00000480) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC32_b;
    };

    union
    {
        __IOM uint32_t GWDCC33;        /*!< (@ 0x00000484) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC33_b;
    };

    union
    {
        __IOM uint32_t GWDCC34;        /*!< (@ 0x00000488) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC34_b;
    };

    union
    {
        __IOM uint32_t GWDCC35;        /*!< (@ 0x0000048C) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC35_b;
    };

    union
    {
        __IOM uint32_t GWDCC36;        /*!< (@ 0x00000490) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC36_b;
    };

    union
    {
        __IOM uint32_t GWDCC37;        /*!< (@ 0x00000494) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC37_b;
    };

    union
    {
        __IOM uint32_t GWDCC38;        /*!< (@ 0x00000498) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC38_b;
    };

    union
    {
        __IOM uint32_t GWDCC39;        /*!< (@ 0x0000049C) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC39_b;
    };

    union
    {
        __IOM uint32_t GWDCC40;        /*!< (@ 0x000004A0) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC40_b;
    };

    union
    {
        __IOM uint32_t GWDCC41;        /*!< (@ 0x000004A4) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC41_b;
    };

    union
    {
        __IOM uint32_t GWDCC42;        /*!< (@ 0x000004A8) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC42_b;
    };

    union
    {
        __IOM uint32_t GWDCC43;        /*!< (@ 0x000004AC) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC43_b;
    };

    union
    {
        __IOM uint32_t GWDCC44;        /*!< (@ 0x000004B0) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC44_b;
    };

    union
    {
        __IOM uint32_t GWDCC45;        /*!< (@ 0x000004B4) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC45_b;
    };

    union
    {
        __IOM uint32_t GWDCC46;        /*!< (@ 0x000004B8) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC46_b;
    };

    union
    {
        __IOM uint32_t GWDCC47;        /*!< (@ 0x000004BC) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC47_b;
    };

    union
    {
        __IOM uint32_t GWDCC48;        /*!< (@ 0x000004C0) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC48_b;
    };

    union
    {
        __IOM uint32_t GWDCC49;        /*!< (@ 0x000004C4) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC49_b;
    };

    union
    {
        __IOM uint32_t GWDCC50;        /*!< (@ 0x000004C8) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC50_b;
    };

    union
    {
        __IOM uint32_t GWDCC51;        /*!< (@ 0x000004CC) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC51_b;
    };

    union
    {
        __IOM uint32_t GWDCC52;        /*!< (@ 0x000004D0) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC52_b;
    };

    union
    {
        __IOM uint32_t GWDCC53;        /*!< (@ 0x000004D4) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC53_b;
    };

    union
    {
        __IOM uint32_t GWDCC54;        /*!< (@ 0x000004D8) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC54_b;
    };

    union
    {
        __IOM uint32_t GWDCC55;        /*!< (@ 0x000004DC) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC55_b;
    };

    union
    {
        __IOM uint32_t GWDCC56;        /*!< (@ 0x000004E0) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC56_b;
    };

    union
    {
        __IOM uint32_t GWDCC57;        /*!< (@ 0x000004E4) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC57_b;
    };

    union
    {
        __IOM uint32_t GWDCC58;        /*!< (@ 0x000004E8) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC58_b;
    };

    union
    {
        __IOM uint32_t GWDCC59;        /*!< (@ 0x000004EC) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC59_b;
    };

    union
    {
        __IOM uint32_t GWDCC60;        /*!< (@ 0x000004F0) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC60_b;
    };

    union
    {
        __IOM uint32_t GWDCC61;        /*!< (@ 0x000004F4) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC61_b;
    };

    union
    {
        __IOM uint32_t GWDCC62;        /*!< (@ 0x000004F8) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC62_b;
    };

    union
    {
        __IOM uint32_t GWDCC63;        /*!< (@ 0x000004FC) GWCA Descriptor Chain Configuration Register
                                        *                  i (GWDCCi) (i = 0 to 63)                                   */

        struct
        {
            __IOM uint32_t SM   : 2;   /*!< [1..0] SM                                                                 */
            uint32_t            : 6;
            __IOM uint32_t EDE  : 1;   /*!< [8..8] EDE                                                                */
            __IOM uint32_t ETS  : 1;   /*!< [9..9] ETS                                                                */
            __IOM uint32_t SL   : 1;   /*!< [10..10] SL                                                               */
            __IOM uint32_t DQT  : 1;   /*!< [11..11] DQT                                                              */
            uint32_t            : 4;
            __IOM uint32_t DCP  : 3;   /*!< [18..16] DCP                                                              */
            uint32_t            : 5;
            __IOM uint32_t BALR : 1;   /*!< [24..24] BALR                                                             */
            uint32_t            : 3;
            __IOM uint32_t OSID : 3;   /*!< [30..28] OSID                                                             */
            uint32_t            : 1;
        } GWDCC63_b;
    };
    __IM uint32_t RESERVED14[192];

    union
    {
        __IOM uint32_t GWAARSS;        /*!< (@ 0x00000800) GWCA AXI Address RAM Searching Setting Register
                                        *                  (GWAARSS)                                                  */

        struct
        {
            __IOM uint32_t AARA : 6;   /*!< [5..0] AARA                                                               */
            uint32_t            : 26;
        } GWAARSS_b;
    };

    union
    {
        __IOM uint32_t GWAARSR0;       /*!< (@ 0x00000804) GWCA AXI Address RAM Searching Result Register
                                        *                  0 (GWAARSR0)                                               */

        struct
        {
            __IOM uint32_t ACARU  : 8; /*!< [7..0] ACARU                                                              */
            uint32_t              : 8;
            __IOM uint32_t AARSEF : 1; /*!< [16..16] AARSEF                                                           */
            __IOM uint32_t AARSSF : 1; /*!< [17..17] AARSSF                                                           */
            uint32_t              : 13;
            __IOM uint32_t AARS   : 1; /*!< [31..31] AARS                                                             */
        } GWAARSR0_b;
    };

    union
    {
        __IOM uint32_t GWAARSR1;       /*!< (@ 0x00000808) GWCA AXI Address RAM Searching Result Register
                                        *                  1 (GWAARSR1)                                               */

        struct
        {
            __IOM uint32_t ACARD : 32; /*!< [31..0] ACARD                                                             */
        } GWAARSR1_b;
    };
    __IM uint32_t RESERVED15[13];

    union
    {
        __IOM uint32_t GWIDAUAS0;       /*!< (@ 0x00000840) GWCA Incremental Data Area Used Area Size Register
                                         *                  i (GWIDAUASi) (i = 0 to 3)                                 */

        struct
        {
            __IOM uint32_t IDAUAS : 24; /*!< [23..0] IDAUAS                                                            */
            uint32_t              : 8;
        } GWIDAUAS0_b;
    };

    union
    {
        __IOM uint32_t GWIDAUAS1;       /*!< (@ 0x00000844) GWCA Incremental Data Area Used Area Size Register
                                         *                  i (GWIDAUASi) (i = 0 to 3)                                 */

        struct
        {
            __IOM uint32_t IDAUAS : 24; /*!< [23..0] IDAUAS                                                            */
            uint32_t              : 8;
        } GWIDAUAS1_b;
    };

    union
    {
        __IOM uint32_t GWIDAUAS2;       /*!< (@ 0x00000848) GWCA Incremental Data Area Used Area Size Register
                                         *                  i (GWIDAUASi) (i = 0 to 3)                                 */

        struct
        {
            __IOM uint32_t IDAUAS : 24; /*!< [23..0] IDAUAS                                                            */
            uint32_t              : 8;
        } GWIDAUAS2_b;
    };

    union
    {
        __IOM uint32_t GWIDAUAS3;       /*!< (@ 0x0000084C) GWCA Incremental Data Area Used Area Size Register
                                         *                  i (GWIDAUASi) (i = 0 to 3)                                 */

        struct
        {
            __IOM uint32_t IDAUAS : 24; /*!< [23..0] IDAUAS                                                            */
            uint32_t              : 8;
        } GWIDAUAS3_b;
    };
    __IM uint32_t RESERVED16[12];

    union
    {
        __IOM uint32_t GWIDASM0;       /*!< (@ 0x00000880) GWCA Incremental Data Area Size Monitoring Register
                                        *                  i (GWIDASMi) (i = 0 to 3)                                  */

        struct
        {
            __IOM uint32_t IDAS : 24;  /*!< [23..0] IDAS                                                              */
            uint32_t            : 8;
        } GWIDASM0_b;
    };

    union
    {
        __IOM uint32_t GWIDASM1;       /*!< (@ 0x00000884) GWCA Incremental Data Area Size Monitoring Register
                                        *                  i (GWIDASMi) (i = 0 to 3)                                  */

        struct
        {
            __IOM uint32_t IDAS : 24;  /*!< [23..0] IDAS                                                              */
            uint32_t            : 8;
        } GWIDASM1_b;
    };

    union
    {
        __IOM uint32_t GWIDASM2;       /*!< (@ 0x00000888) GWCA Incremental Data Area Size Monitoring Register
                                        *                  i (GWIDASMi) (i = 0 to 3)                                  */

        struct
        {
            __IOM uint32_t IDAS : 24;  /*!< [23..0] IDAS                                                              */
            uint32_t            : 8;
        } GWIDASM2_b;
    };

    union
    {
        __IOM uint32_t GWIDASM3;       /*!< (@ 0x0000088C) GWCA Incremental Data Area Size Monitoring Register
                                        *                  i (GWIDASMi) (i = 0 to 3)                                  */

        struct
        {
            __IOM uint32_t IDAS : 24;  /*!< [23..0] IDAS                                                              */
            uint32_t            : 8;
        } GWIDASM3_b;
    };
    __IM uint32_t RESERVED17[28];

    union
    {
        __IOM uint32_t GWIDASAM00;     /*!< (@ 0x00000900) GWCA Incremental Data Area Start Address Monitoring
                                        *                  Register 0i (GWIDASAM0i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDASAU : 8; /*!< [7..0] IDASAU                                                             */
            uint32_t              : 24;
        } GWIDASAM00_b;
    };

    union
    {
        __IOM uint32_t GWIDASAM01;      /*!< (@ 0x00000904) GWCA Incremental Data Area Start Address Monitoring
                                         *                  Register 1i (GWIDASAM1i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDASAL : 32; /*!< [31..0] IDASAL                                                            */
        } GWIDASAM01_b;
    };

    union
    {
        __IOM uint32_t GWIDASAM10;     /*!< (@ 0x00000908) GWCA Incremental Data Area Start Address Monitoring
                                        *                  Register 0i (GWIDASAM0i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDASAU : 8; /*!< [7..0] IDASAU                                                             */
            uint32_t              : 24;
        } GWIDASAM10_b;
    };

    union
    {
        __IOM uint32_t GWIDASAM11;      /*!< (@ 0x0000090C) GWCA Incremental Data Area Start Address Monitoring
                                         *                  Register 1i (GWIDASAM1i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDASAL : 32; /*!< [31..0] IDASAL                                                            */
        } GWIDASAM11_b;
    };

    union
    {
        __IOM uint32_t GWIDASAM20;     /*!< (@ 0x00000910) GWCA Incremental Data Area Start Address Monitoring
                                        *                  Register 0i (GWIDASAM0i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDASAU : 8; /*!< [7..0] IDASAU                                                             */
            uint32_t              : 24;
        } GWIDASAM20_b;
    };

    union
    {
        __IOM uint32_t GWIDASAM21;      /*!< (@ 0x00000914) GWCA Incremental Data Area Start Address Monitoring
                                         *                  Register 1i (GWIDASAM1i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDASAL : 32; /*!< [31..0] IDASAL                                                            */
        } GWIDASAM21_b;
    };

    union
    {
        __IOM uint32_t GWIDASAM30;     /*!< (@ 0x00000918) GWCA Incremental Data Area Start Address Monitoring
                                        *                  Register 0i (GWIDASAM0i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDASAU : 8; /*!< [7..0] IDASAU                                                             */
            uint32_t              : 24;
        } GWIDASAM30_b;
    };

    union
    {
        __IOM uint32_t GWIDASAM31;      /*!< (@ 0x0000091C) GWCA Incremental Data Area Start Address Monitoring
                                         *                  Register 1i (GWIDASAM1i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDASAL : 32; /*!< [31..0] IDASAL                                                            */
        } GWIDASAM31_b;
    };
    __IM uint32_t RESERVED18[24];

    union
    {
        __IOM uint32_t GWIDACAM00;     /*!< (@ 0x00000980) GWCA Incremental Data Area Current Address Monitoring
                                        *                  Register 0i (GWIDACAM0i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDACAU : 8; /*!< [7..0] IDACAU                                                             */
            uint32_t              : 24;
        } GWIDACAM00_b;
    };

    union
    {
        __IOM uint32_t GWIDACAM01;      /*!< (@ 0x00000984) GWCA Incremental Data Area Current Address Monitoring
                                         *                  Register 1i (GWIDACAM1i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDACAL : 32; /*!< [31..0] IDACAL                                                            */
        } GWIDACAM01_b;
    };

    union
    {
        __IOM uint32_t GWIDACAM10;     /*!< (@ 0x00000988) GWCA Incremental Data Area Current Address Monitoring
                                        *                  Register 0i (GWIDACAM0i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDACAU : 8; /*!< [7..0] IDACAU                                                             */
            uint32_t              : 24;
        } GWIDACAM10_b;
    };

    union
    {
        __IOM uint32_t GWIDACAM11;      /*!< (@ 0x0000098C) GWCA Incremental Data Area Current Address Monitoring
                                         *                  Register 1i (GWIDACAM1i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDACAL : 32; /*!< [31..0] IDACAL                                                            */
        } GWIDACAM11_b;
    };

    union
    {
        __IOM uint32_t GWIDACAM20;     /*!< (@ 0x00000990) GWCA Incremental Data Area Current Address Monitoring
                                        *                  Register 0i (GWIDACAM0i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDACAU : 8; /*!< [7..0] IDACAU                                                             */
            uint32_t              : 24;
        } GWIDACAM20_b;
    };

    union
    {
        __IOM uint32_t GWIDACAM21;      /*!< (@ 0x00000994) GWCA Incremental Data Area Current Address Monitoring
                                         *                  Register 1i (GWIDACAM1i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDACAL : 32; /*!< [31..0] IDACAL                                                            */
        } GWIDACAM21_b;
    };

    union
    {
        __IOM uint32_t GWIDACAM30;     /*!< (@ 0x00000998) GWCA Incremental Data Area Current Address Monitoring
                                        *                  Register 0i (GWIDACAM0i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDACAU : 8; /*!< [7..0] IDACAU                                                             */
            uint32_t              : 24;
        } GWIDACAM30_b;
    };

    union
    {
        __IOM uint32_t GWIDACAM31;      /*!< (@ 0x0000099C) GWCA Incremental Data Area Current Address Monitoring
                                         *                  Register 1i (GWIDACAM1i) (i = 0 to 3)                      */

        struct
        {
            __IOM uint32_t IDACAL : 32; /*!< [31..0] IDACAL                                                            */
        } GWIDACAM31_b;
    };
    __IM uint32_t RESERVED19[24];

    union
    {
        __IOM uint32_t GWGRLC;           /*!< (@ 0x00000A00) GWCA Global Rate Limiter Configuration Register
                                          *                  (GWGRLC)                                                   */

        struct
        {
            __IOM uint32_t GRLIV   : 16; /*!< [15..0] GRLIV                                                             */
            __IOM uint32_t GRLE    : 1;  /*!< [16..16] GRLE                                                             */
            __IOM uint32_t GRLULRS : 1;  /*!< [17..17] GRLULRS                                                          */
            uint32_t               : 14;
        } GWGRLC_b;
    };

    union
    {
        __IOM uint32_t GWGRLULC;       /*!< (@ 0x00000A04) GWCA Global Rate Limiter Upper Limit Configuration
                                        *                  Register (GWGRLULC)                                        */

        struct
        {
            __IOM uint32_t GRLUL : 24; /*!< [23..0] GRLUL                                                             */
            uint32_t             : 8;
        } GWGRLULC_b;
    };
    __IM uint32_t RESERVED20[30];

    union
    {
        __IOM uint32_t GWRLC0;         /*!< (@ 0x00000A80) GWCA Rate Limiter Configuration Register i (GWRLCi)
                                        *                  (i = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t RLIV : 12;  /*!< [11..0] RLIV                                                              */
            uint32_t            : 4;
            __IOM uint32_t RLE  : 1;   /*!< [16..16] RLE                                                              */
            uint32_t            : 15;
        } GWRLC0_b;
    };

    union
    {
        __IOM uint32_t GWRLULC0;       /*!< (@ 0x00000A84) GWCA Rate Limiter Upper Limit Configuration Register
                                        *                  i (GWRLULCi) (i = 0 to 7)                                  */

        struct
        {
            __IOM uint32_t RLUL : 24;  /*!< [23..0] RLUL                                                              */
            uint32_t            : 8;
        } GWRLULC0_b;
    };

    union
    {
        __IOM uint32_t GWRLC1;         /*!< (@ 0x00000A88) GWCA Rate Limiter Configuration Register i (GWRLCi)
                                        *                  (i = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t RLIV : 12;  /*!< [11..0] RLIV                                                              */
            uint32_t            : 4;
            __IOM uint32_t RLE  : 1;   /*!< [16..16] RLE                                                              */
            uint32_t            : 15;
        } GWRLC1_b;
    };

    union
    {
        __IOM uint32_t GWRLULC1;       /*!< (@ 0x00000A8C) GWCA Rate Limiter Upper Limit Configuration Register
                                        *                  i (GWRLULCi) (i = 0 to 7)                                  */

        struct
        {
            __IOM uint32_t RLUL : 24;  /*!< [23..0] RLUL                                                              */
            uint32_t            : 8;
        } GWRLULC1_b;
    };

    union
    {
        __IOM uint32_t GWRLC2;         /*!< (@ 0x00000A90) GWCA Rate Limiter Configuration Register i (GWRLCi)
                                        *                  (i = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t RLIV : 12;  /*!< [11..0] RLIV                                                              */
            uint32_t            : 4;
            __IOM uint32_t RLE  : 1;   /*!< [16..16] RLE                                                              */
            uint32_t            : 15;
        } GWRLC2_b;
    };

    union
    {
        __IOM uint32_t GWRLULC2;       /*!< (@ 0x00000A94) GWCA Rate Limiter Upper Limit Configuration Register
                                        *                  i (GWRLULCi) (i = 0 to 7)                                  */

        struct
        {
            __IOM uint32_t RLUL : 24;  /*!< [23..0] RLUL                                                              */
            uint32_t            : 8;
        } GWRLULC2_b;
    };

    union
    {
        __IOM uint32_t GWRLC3;         /*!< (@ 0x00000A98) GWCA Rate Limiter Configuration Register i (GWRLCi)
                                        *                  (i = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t RLIV : 12;  /*!< [11..0] RLIV                                                              */
            uint32_t            : 4;
            __IOM uint32_t RLE  : 1;   /*!< [16..16] RLE                                                              */
            uint32_t            : 15;
        } GWRLC3_b;
    };

    union
    {
        __IOM uint32_t GWRLULC3;       /*!< (@ 0x00000A9C) GWCA Rate Limiter Upper Limit Configuration Register
                                        *                  i (GWRLULCi) (i = 0 to 7)                                  */

        struct
        {
            __IOM uint32_t RLUL : 24;  /*!< [23..0] RLUL                                                              */
            uint32_t            : 8;
        } GWRLULC3_b;
    };

    union
    {
        __IOM uint32_t GWRLC4;         /*!< (@ 0x00000AA0) GWCA Rate Limiter Configuration Register i (GWRLCi)
                                        *                  (i = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t RLIV : 12;  /*!< [11..0] RLIV                                                              */
            uint32_t            : 4;
            __IOM uint32_t RLE  : 1;   /*!< [16..16] RLE                                                              */
            uint32_t            : 15;
        } GWRLC4_b;
    };

    union
    {
        __IOM uint32_t GWRLULC4;       /*!< (@ 0x00000AA4) GWCA Rate Limiter Upper Limit Configuration Register
                                        *                  i (GWRLULCi) (i = 0 to 7)                                  */

        struct
        {
            __IOM uint32_t RLUL : 24;  /*!< [23..0] RLUL                                                              */
            uint32_t            : 8;
        } GWRLULC4_b;
    };

    union
    {
        __IOM uint32_t GWRLC5;         /*!< (@ 0x00000AA8) GWCA Rate Limiter Configuration Register i (GWRLCi)
                                        *                  (i = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t RLIV : 12;  /*!< [11..0] RLIV                                                              */
            uint32_t            : 4;
            __IOM uint32_t RLE  : 1;   /*!< [16..16] RLE                                                              */
            uint32_t            : 15;
        } GWRLC5_b;
    };

    union
    {
        __IOM uint32_t GWRLULC5;       /*!< (@ 0x00000AAC) GWCA Rate Limiter Upper Limit Configuration Register
                                        *                  i (GWRLULCi) (i = 0 to 7)                                  */

        struct
        {
            __IOM uint32_t RLUL : 24;  /*!< [23..0] RLUL                                                              */
            uint32_t            : 8;
        } GWRLULC5_b;
    };

    union
    {
        __IOM uint32_t GWRLC6;         /*!< (@ 0x00000AB0) GWCA Rate Limiter Configuration Register i (GWRLCi)
                                        *                  (i = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t RLIV : 12;  /*!< [11..0] RLIV                                                              */
            uint32_t            : 4;
            __IOM uint32_t RLE  : 1;   /*!< [16..16] RLE                                                              */
            uint32_t            : 15;
        } GWRLC6_b;
    };

    union
    {
        __IOM uint32_t GWRLULC6;       /*!< (@ 0x00000AB4) GWCA Rate Limiter Upper Limit Configuration Register
                                        *                  i (GWRLULCi) (i = 0 to 7)                                  */

        struct
        {
            __IOM uint32_t RLUL : 24;  /*!< [23..0] RLUL                                                              */
            uint32_t            : 8;
        } GWRLULC6_b;
    };

    union
    {
        __IOM uint32_t GWRLC7;         /*!< (@ 0x00000AB8) GWCA Rate Limiter Configuration Register i (GWRLCi)
                                        *                  (i = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t RLIV : 12;  /*!< [11..0] RLIV                                                              */
            uint32_t            : 4;
            __IOM uint32_t RLE  : 1;   /*!< [16..16] RLE                                                              */
            uint32_t            : 15;
        } GWRLC7_b;
    };

    union
    {
        __IOM uint32_t GWRLULC7;       /*!< (@ 0x00000ABC) GWCA Rate Limiter Upper Limit Configuration Register
                                        *                  i (GWRLULCi) (i = 0 to 7)                                  */

        struct
        {
            __IOM uint32_t RLUL : 24;  /*!< [23..0] RLUL                                                              */
            uint32_t            : 8;
        } GWRLULC7_b;
    };
    __IM uint32_t RESERVED21[48];

    union
    {
        __IOM uint32_t GWIDPC;         /*!< (@ 0x00000B80) GWCA Interrupt Delay Prescaler Configuration
                                        *                  Register (GWIDPC)                                          */

        struct
        {
            __IOM uint32_t IDPV : 10;  /*!< [9..0] IDPV                                                               */
            uint32_t            : 22;
        } GWIDPC_b;
    };
    __IM uint32_t RESERVED22[31];

    union
    {
        __IOM uint32_t GWIDC0;         /*!< (@ 0x00000C00) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC0_b;
    };

    union
    {
        __IOM uint32_t GWIDC1;         /*!< (@ 0x00000C04) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC1_b;
    };

    union
    {
        __IOM uint32_t GWIDC2;         /*!< (@ 0x00000C08) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC2_b;
    };

    union
    {
        __IOM uint32_t GWIDC3;         /*!< (@ 0x00000C0C) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC3_b;
    };

    union
    {
        __IOM uint32_t GWIDC4;         /*!< (@ 0x00000C10) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC4_b;
    };

    union
    {
        __IOM uint32_t GWIDC5;         /*!< (@ 0x00000C14) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC5_b;
    };

    union
    {
        __IOM uint32_t GWIDC6;         /*!< (@ 0x00000C18) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC6_b;
    };

    union
    {
        __IOM uint32_t GWIDC7;         /*!< (@ 0x00000C1C) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC7_b;
    };

    union
    {
        __IOM uint32_t GWIDC8;         /*!< (@ 0x00000C20) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC8_b;
    };

    union
    {
        __IOM uint32_t GWIDC9;         /*!< (@ 0x00000C24) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC9_b;
    };

    union
    {
        __IOM uint32_t GWIDC10;        /*!< (@ 0x00000C28) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC10_b;
    };

    union
    {
        __IOM uint32_t GWIDC11;        /*!< (@ 0x00000C2C) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC11_b;
    };

    union
    {
        __IOM uint32_t GWIDC12;        /*!< (@ 0x00000C30) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC12_b;
    };

    union
    {
        __IOM uint32_t GWIDC13;        /*!< (@ 0x00000C34) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC13_b;
    };

    union
    {
        __IOM uint32_t GWIDC14;        /*!< (@ 0x00000C38) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC14_b;
    };

    union
    {
        __IOM uint32_t GWIDC15;        /*!< (@ 0x00000C3C) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC15_b;
    };

    union
    {
        __IOM uint32_t GWIDC16;        /*!< (@ 0x00000C40) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC16_b;
    };

    union
    {
        __IOM uint32_t GWIDC17;        /*!< (@ 0x00000C44) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC17_b;
    };

    union
    {
        __IOM uint32_t GWIDC18;        /*!< (@ 0x00000C48) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC18_b;
    };

    union
    {
        __IOM uint32_t GWIDC19;        /*!< (@ 0x00000C4C) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC19_b;
    };

    union
    {
        __IOM uint32_t GWIDC20;        /*!< (@ 0x00000C50) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC20_b;
    };

    union
    {
        __IOM uint32_t GWIDC21;        /*!< (@ 0x00000C54) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC21_b;
    };

    union
    {
        __IOM uint32_t GWIDC22;        /*!< (@ 0x00000C58) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC22_b;
    };

    union
    {
        __IOM uint32_t GWIDC23;        /*!< (@ 0x00000C5C) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC23_b;
    };

    union
    {
        __IOM uint32_t GWIDC24;        /*!< (@ 0x00000C60) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC24_b;
    };

    union
    {
        __IOM uint32_t GWIDC25;        /*!< (@ 0x00000C64) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC25_b;
    };

    union
    {
        __IOM uint32_t GWIDC26;        /*!< (@ 0x00000C68) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC26_b;
    };

    union
    {
        __IOM uint32_t GWIDC27;        /*!< (@ 0x00000C6C) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC27_b;
    };

    union
    {
        __IOM uint32_t GWIDC28;        /*!< (@ 0x00000C70) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC28_b;
    };

    union
    {
        __IOM uint32_t GWIDC29;        /*!< (@ 0x00000C74) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC29_b;
    };

    union
    {
        __IOM uint32_t GWIDC30;        /*!< (@ 0x00000C78) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC30_b;
    };

    union
    {
        __IOM uint32_t GWIDC31;        /*!< (@ 0x00000C7C) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC31_b;
    };

    union
    {
        __IOM uint32_t GWIDC32;        /*!< (@ 0x00000C80) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC32_b;
    };

    union
    {
        __IOM uint32_t GWIDC33;        /*!< (@ 0x00000C84) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC33_b;
    };

    union
    {
        __IOM uint32_t GWIDC34;        /*!< (@ 0x00000C88) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC34_b;
    };

    union
    {
        __IOM uint32_t GWIDC35;        /*!< (@ 0x00000C8C) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC35_b;
    };

    union
    {
        __IOM uint32_t GWIDC36;        /*!< (@ 0x00000C90) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC36_b;
    };

    union
    {
        __IOM uint32_t GWIDC37;        /*!< (@ 0x00000C94) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC37_b;
    };

    union
    {
        __IOM uint32_t GWIDC38;        /*!< (@ 0x00000C98) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC38_b;
    };

    union
    {
        __IOM uint32_t GWIDC39;        /*!< (@ 0x00000C9C) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC39_b;
    };

    union
    {
        __IOM uint32_t GWIDC40;        /*!< (@ 0x00000CA0) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC40_b;
    };

    union
    {
        __IOM uint32_t GWIDC41;        /*!< (@ 0x00000CA4) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC41_b;
    };

    union
    {
        __IOM uint32_t GWIDC42;        /*!< (@ 0x00000CA8) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC42_b;
    };

    union
    {
        __IOM uint32_t GWIDC43;        /*!< (@ 0x00000CAC) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC43_b;
    };

    union
    {
        __IOM uint32_t GWIDC44;        /*!< (@ 0x00000CB0) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC44_b;
    };

    union
    {
        __IOM uint32_t GWIDC45;        /*!< (@ 0x00000CB4) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC45_b;
    };

    union
    {
        __IOM uint32_t GWIDC46;        /*!< (@ 0x00000CB8) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC46_b;
    };

    union
    {
        __IOM uint32_t GWIDC47;        /*!< (@ 0x00000CBC) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC47_b;
    };

    union
    {
        __IOM uint32_t GWIDC48;        /*!< (@ 0x00000CC0) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC48_b;
    };

    union
    {
        __IOM uint32_t GWIDC49;        /*!< (@ 0x00000CC4) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC49_b;
    };

    union
    {
        __IOM uint32_t GWIDC50;        /*!< (@ 0x00000CC8) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC50_b;
    };

    union
    {
        __IOM uint32_t GWIDC51;        /*!< (@ 0x00000CCC) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC51_b;
    };

    union
    {
        __IOM uint32_t GWIDC52;        /*!< (@ 0x00000CD0) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC52_b;
    };

    union
    {
        __IOM uint32_t GWIDC53;        /*!< (@ 0x00000CD4) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC53_b;
    };

    union
    {
        __IOM uint32_t GWIDC54;        /*!< (@ 0x00000CD8) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC54_b;
    };

    union
    {
        __IOM uint32_t GWIDC55;        /*!< (@ 0x00000CDC) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC55_b;
    };

    union
    {
        __IOM uint32_t GWIDC56;        /*!< (@ 0x00000CE0) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC56_b;
    };

    union
    {
        __IOM uint32_t GWIDC57;        /*!< (@ 0x00000CE4) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC57_b;
    };

    union
    {
        __IOM uint32_t GWIDC58;        /*!< (@ 0x00000CE8) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC58_b;
    };

    union
    {
        __IOM uint32_t GWIDC59;        /*!< (@ 0x00000CEC) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC59_b;
    };

    union
    {
        __IOM uint32_t GWIDC60;        /*!< (@ 0x00000CF0) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC60_b;
    };

    union
    {
        __IOM uint32_t GWIDC61;        /*!< (@ 0x00000CF4) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC61_b;
    };

    union
    {
        __IOM uint32_t GWIDC62;        /*!< (@ 0x00000CF8) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC62_b;
    };

    union
    {
        __IOM uint32_t GWIDC63;        /*!< (@ 0x00000CFC) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC63_b;
    };

    union
    {
        __IOM uint32_t GWIDC64;        /*!< (@ 0x00000D00) GWCA Interrupt Delay Configuration Register (GWIDCi)
                                        *                  (i = 0 to 64)                                              */

        struct
        {
            __IOM uint32_t IDV : 12;   /*!< [11..0] IDV                                                               */
            uint32_t           : 20;
        } GWIDC64_b;
    };
    __IM uint32_t RESERVED23[191];

    union
    {
        __IOM uint32_t GWRDCN;         /*!< (@ 0x00001000) GWCA Received Data Counter Register (GWRDCN)               */

        struct
        {
            __IOM uint32_t RDN : 32;   /*!< [31..0] RDN                                                               */
        } GWRDCN_b;
    };

    union
    {
        __IOM uint32_t GWTDCN;         /*!< (@ 0x00001004) GWCA Transmitted Data Counter Register (GWTDCN)            */

        struct
        {
            __IOM uint32_t TDN : 32;   /*!< [31..0] TDN                                                               */
        } GWTDCN_b;
    };

    union
    {
        __IOM uint32_t GWTSCN;         /*!< (@ 0x00001008) GWCA Timestamp Counter Register (GWTSCN)                   */

        struct
        {
            __IOM uint32_t TN : 32;    /*!< [31..0] TN                                                                */
        } GWTSCN_b;
    };

    union
    {
        __IOM uint32_t GWTSOVFECN;       /*!< (@ 0x0000100C) GWCA Timestamp Overflow Error Counter Register
                                          *                  (GWTSOVFECN)                                               */

        struct
        {
            __IOM uint32_t TSOVFEN : 16; /*!< [15..0] TSOVFEN                                                           */
            uint32_t               : 16;
        } GWTSOVFECN_b;
    };

    union
    {
        __IOM uint32_t GWUSMFSECN;       /*!< (@ 0x00001010) GWCA Under Switch Minimum Frame Size Error Counter
                                          *                  Register (GWUSMFSECN)                                      */

        struct
        {
            __IOM uint32_t USMFSEN : 16; /*!< [15..0] USMFSEN                                                           */
            uint32_t               : 16;
        } GWUSMFSECN_b;
    };

    union
    {
        __IOM uint32_t GWTFECN;        /*!< (@ 0x00001014) GWCA TAG Filtering Error Counter Register (GWTFECN)        */

        struct
        {
            __IOM uint32_t TFEN : 16;  /*!< [15..0] TFEN                                                              */
            uint32_t            : 16;
        } GWTFECN_b;
    };

    union
    {
        __IOM uint32_t GWSEQECN;       /*!< (@ 0x00001018) GWCA Sequence Error Counter Register (GWSEQECN)            */

        struct
        {
            __IOM uint32_t SEQEN : 16; /*!< [15..0] SEQEN                                                             */
            uint32_t             : 16;
        } GWSEQECN_b;
    };
    __IM uint32_t RESERVED24;

    union
    {
        __IOM uint32_t GWTXDNECN;       /*!< (@ 0x00001020) GWCA TX Descriptor Number Error Counter Register
                                         *                  (GWTXDNECN)                                                */

        struct
        {
            __IOM uint32_t TXDNEN : 16; /*!< [15..0] TXDNEN                                                            */
            uint32_t              : 16;
        } GWTXDNECN_b;
    };

    union
    {
        __IOM uint32_t GWFSECN;        /*!< (@ 0x00001024) GWCA Frame Size Error Counter Register (GWFSECN)           */

        struct
        {
            __IOM uint32_t FSEN : 16;  /*!< [15..0] FSEN                                                              */
            uint32_t            : 16;
        } GWFSECN_b;
    };

    union
    {
        __IOM uint32_t GWTDFECN;       /*!< (@ 0x00001028) GWCA Timestamp Descriptor Full Error Counter
                                        *                  Register (GWTDFECN)                                        */

        struct
        {
            __IOM uint32_t TDFEN : 16; /*!< [15..0] TDFEN                                                             */
            uint32_t             : 16;
        } GWTDFECN_b;
    };

    union
    {
        __IOM uint32_t GWTSDNECN;       /*!< (@ 0x0000102C) GWCA Timestamp Descriptor Number Error Counter
                                         *                  Register (GWTSDNECN)                                       */

        struct
        {
            __IOM uint32_t TSDNEN : 16; /*!< [15..0] TSDNEN                                                            */
            uint32_t              : 16;
        } GWTSDNECN_b;
    };

    union
    {
        __IOM uint32_t GWDQOECN;       /*!< (@ 0x00001030) GWCA Descriptor Queue Overflow Error Counter
                                        *                  Register (GWDQOECN)                                        */

        struct
        {
            __IOM uint32_t DQOEN : 16; /*!< [15..0] DQOEN                                                             */
            uint32_t             : 16;
        } GWDQOECN_b;
    };

    union
    {
        __IOM uint32_t GWDQSECN;       /*!< (@ 0x00001034) GWCA Descriptor Queue Security Error Counter
                                        *                  Register (GWDQSECN)                                        */

        struct
        {
            __IOM uint32_t DQSEN : 16; /*!< [15..0] DQSEN                                                             */
            uint32_t             : 16;
        } GWDQSECN_b;
    };

    union
    {
        __IOM uint32_t GWDFECN;        /*!< (@ 0x00001038) GWCA Descriptor Full Error Counter Register (GWDFECN)      */

        struct
        {
            __IOM uint32_t DFEN : 16;  /*!< [15..0] DFEN                                                              */
            uint32_t            : 16;
        } GWDFECN_b;
    };

    union
    {
        __IOM uint32_t GWDSECN;        /*!< (@ 0x0000103C) GWCA Descriptor Security Error Counter Register
                                        *                  (GWDSECN)                                                  */

        struct
        {
            __IOM uint32_t DSEN : 16;  /*!< [15..0] DSEN                                                              */
            uint32_t            : 16;
        } GWDSECN_b;
    };

    union
    {
        __IOM uint32_t GWDSZECN;       /*!< (@ 0x00001040) GWCA Data Size Error Counter Register (GWDSZECN)           */

        struct
        {
            __IOM uint32_t DSZEN : 16; /*!< [15..0] DSZEN                                                             */
            uint32_t             : 16;
        } GWDSZECN_b;
    };

    union
    {
        __IOM uint32_t GWDCTECN;       /*!< (@ 0x00001044) GWCA Descriptor Chain Type Error Counter Register
                                        *                  (GWDCTECN)                                                 */

        struct
        {
            __IOM uint32_t DCTEN : 16; /*!< [15..0] DCTEN                                                             */
            uint32_t             : 16;
        } GWDCTECN_b;
    };

    union
    {
        __IOM uint32_t GWRXDNECN;       /*!< (@ 0x00001048) GWCA RX Descriptor Number Error Counter Register
                                         *                  (GWRXDNECN)                                                */

        struct
        {
            __IOM uint32_t RXDNEN : 16; /*!< [15..0] RXDNEN                                                            */
            uint32_t              : 16;
        } GWRXDNECN_b;
    };
    __IM uint32_t  RESERVED25[45];
    __IOM uint32_t GWDIS0;             /*!< (@ 0x00001100) GWCA Data Interrupt Status Register i (GWDISi)
                                        *                  (i = 0, 1)                                                 */
    __IOM uint32_t GWDIE0;             /*!< (@ 0x00001104) GWCA Data Interrupt Enable Register i (GWDIEi)
                                        *                  (i = 0, 1)                                                 */
    __IOM uint32_t GWDID0;             /*!< (@ 0x00001108) GWCA Data Interrupt Disable Register i (GWDIDi)
                                        *                  (i = 0, 1)                                                 */
    __IOM uint32_t GWDIDS0;            /*!< (@ 0x0000110C) GWCA Data Interrupt Delayed Status Register i
                                        *                  (GWDIDSi) (i = 0, 1)                                       */
    __IOM uint32_t GWDIS1;             /*!< (@ 0x00001110) GWCA Data Interrupt Status Register i (GWDISi)
                                        *                  (i = 0, 1)                                                 */
    __IOM uint32_t GWDIE1;             /*!< (@ 0x00001114) GWCA Data Interrupt Enable Register i (GWDIEi)
                                        *                  (i = 0, 1)                                                 */
    __IOM uint32_t GWDID1;             /*!< (@ 0x00001118) GWCA Data Interrupt Disable Register i (GWDIDi)
                                        *                  (i = 0, 1)                                                 */
    __IOM uint32_t GWDIDS1;            /*!< (@ 0x0000111C) GWCA Data Interrupt Delayed Status Register i
                                        *                  (GWDIDSi) (i = 0, 1)                                       */
    __IM uint32_t RESERVED26[24];

    union
    {
        __IOM uint32_t GWTSDIS;        /*!< (@ 0x00001180) GWCA Timestamp Data Interrupt Status Register
                                        *                  (GWTSDIS)                                                  */

        struct
        {
            __IOM uint32_t TSDIS0 : 1; /*!< [0..0] TSDIS0                                                             */
            __IOM uint32_t TSDIS1 : 1; /*!< [1..1] TSDIS1                                                             */
            uint32_t              : 30;
        } GWTSDIS_b;
    };

    union
    {
        __IOM uint32_t GWTSDIE;        /*!< (@ 0x00001184) GWCA Timestamp Data Interrupt Enable Register
                                        *                  (GWTSDIE)                                                  */

        struct
        {
            __IOM uint32_t TSDIE0 : 1; /*!< [0..0] TSDIE0                                                             */
            __IOM uint32_t TSDIE1 : 1; /*!< [1..1] TSDIE1                                                             */
            uint32_t              : 30;
        } GWTSDIE_b;
    };

    union
    {
        __IOM uint32_t GWTSDID;        /*!< (@ 0x00001188) GWCA Timestamp Data Interrupt Disable Register
                                        *                  (GWTSDID)                                                  */

        struct
        {
            __IOM uint32_t TSDID0 : 1; /*!< [0..0] TSDID0                                                             */
            __IOM uint32_t TSDID1 : 1; /*!< [1..1] TSDID1                                                             */
            uint32_t              : 30;
        } GWTSDID_b;
    };
    __IM uint32_t RESERVED27;

    union
    {
        __IOM uint32_t GWEIS0;            /*!< (@ 0x00001190) GWCA Error Interrupt Status Register 0 (GWEIS0)            */

        struct
        {
            __IOM uint32_t AES       : 1; /*!< [0..0] AES                                                                */
            __IOM uint32_t DECCES    : 1; /*!< [1..1] DECCES                                                             */
            __IOM uint32_t TECCES    : 1; /*!< [2..2] TECCES                                                             */
            __IOM uint32_t PECCES    : 1; /*!< [3..3] PECCES                                                             */
            __IOM uint32_t DSECCES   : 1; /*!< [4..4] DSECCES                                                            */
            __IOM uint32_t MECCES    : 1; /*!< [5..5] MECCES                                                             */
            __IOM uint32_t AECCES    : 1; /*!< [6..6] AECCES                                                             */
            __IOM uint32_t TSECCES   : 1; /*!< [7..7] TSECCES                                                            */
            __IOM uint32_t L23UECCES : 1; /*!< [8..8] L23UECCES                                                          */
            __IOM uint32_t TSOVFES   : 1; /*!< [9..9] TSOVFES                                                            */
            __IOM uint32_t USMFSES   : 1; /*!< [10..10] USMFSES                                                          */
            __IOM uint32_t TFES      : 1; /*!< [11..11] TFES                                                             */
            __IOM uint32_t SEQES     : 1; /*!< [12..12] SEQES                                                            */
            uint32_t                 : 1;
            __IOM uint32_t TXDNES    : 1; /*!< [14..14] TXDNES                                                           */
            __IOM uint32_t TSHES     : 1; /*!< [15..15] TSHES                                                            */
            __IOM uint32_t FSES0     : 1; /*!< [16..16] FSES0                                                            */
            __IOM uint32_t FSES1     : 1; /*!< [17..17] FSES1                                                            */
            __IOM uint32_t FSES2     : 1; /*!< [18..18] FSES2                                                            */
            __IOM uint32_t FSES3     : 1; /*!< [19..19] FSES3                                                            */
            __IOM uint32_t FSES4     : 1; /*!< [20..20] FSES4                                                            */
            __IOM uint32_t FSES5     : 1; /*!< [21..21] FSES5                                                            */
            __IOM uint32_t FSES6     : 1; /*!< [22..22] FSES6                                                            */
            __IOM uint32_t FSES7     : 1; /*!< [23..23] FSES7                                                            */
            __IOM uint32_t TDFES0    : 1; /*!< [24..24] TDFES0                                                           */
            __IOM uint32_t TDFES1    : 1; /*!< [25..25] TDFES1                                                           */
            uint32_t                 : 2;
            __IOM uint32_t TSDNES0   : 1; /*!< [28..28] TSDNES0                                                          */
            __IOM uint32_t TSDNES1   : 1; /*!< [29..29] TSDNES1                                                          */
            uint32_t                 : 2;
        } GWEIS0_b;
    };

    union
    {
        __IOM uint32_t GWEIE0;            /*!< (@ 0x00001194) GWCA Error Interrupt Enable Register 0 (GWEIE0)            */

        struct
        {
            __IOM uint32_t AEE       : 1; /*!< [0..0] AEE                                                                */
            __IOM uint32_t DECCEE    : 1; /*!< [1..1] DECCEE                                                             */
            __IOM uint32_t TECCEE    : 1; /*!< [2..2] TECCEE                                                             */
            __IOM uint32_t PECCEE    : 1; /*!< [3..3] PECCEE                                                             */
            __IOM uint32_t DSECCEE   : 1; /*!< [4..4] DSECCEE                                                            */
            __IOM uint32_t MECCEE    : 1; /*!< [5..5] MECCEE                                                             */
            __IOM uint32_t AECCEE    : 1; /*!< [6..6] AECCEE                                                             */
            __IOM uint32_t TSECCEE   : 1; /*!< [7..7] TSECCEE                                                            */
            __IOM uint32_t L23UECCEE : 1; /*!< [8..8] L23UECCEE                                                          */
            __IOM uint32_t TSOVFEE   : 1; /*!< [9..9] TSOVFEE                                                            */
            __IOM uint32_t USMFSEE   : 1; /*!< [10..10] USMFSEE                                                          */
            __IOM uint32_t TFEE      : 1; /*!< [11..11] TFEE                                                             */
            __IOM uint32_t SEQEE     : 1; /*!< [12..12] SEQEE                                                            */
            uint32_t                 : 1;
            __IOM uint32_t TXDNEE    : 1; /*!< [14..14] TXDNEE                                                           */
            __IOM uint32_t TSHEE     : 1; /*!< [15..15] TSHEE                                                            */
            __IOM uint32_t FSEE0     : 1; /*!< [16..16] FSEE0                                                            */
            __IOM uint32_t FSEE1     : 1; /*!< [17..17] FSEE1                                                            */
            __IOM uint32_t FSEE2     : 1; /*!< [18..18] FSEE2                                                            */
            __IOM uint32_t FSEE3     : 1; /*!< [19..19] FSEE3                                                            */
            __IOM uint32_t FSEE4     : 1; /*!< [20..20] FSEE4                                                            */
            __IOM uint32_t FSEE5     : 1; /*!< [21..21] FSEE5                                                            */
            __IOM uint32_t FSEE6     : 1; /*!< [22..22] FSEE6                                                            */
            __IOM uint32_t FSEE7     : 1; /*!< [23..23] FSEE7                                                            */
            __IOM uint32_t TDFEE0    : 1; /*!< [24..24] TDFEE0                                                           */
            __IOM uint32_t TDFEE1    : 1; /*!< [25..25] TDFEE1                                                           */
            uint32_t                 : 2;
            __IOM uint32_t TSDNEE0   : 1; /*!< [28..28] TSDNEE0                                                          */
            __IOM uint32_t TSDNEE1   : 1; /*!< [29..29] TSDNEE1                                                          */
            uint32_t                 : 2;
        } GWEIE0_b;
    };

    union
    {
        __IOM uint32_t GWEID0;            /*!< (@ 0x00001198) GWCA Error Interrupt Disable Register 0 (GWEID0)           */

        struct
        {
            __IOM uint32_t AED       : 1; /*!< [0..0] AED                                                                */
            __IOM uint32_t TECCED    : 1; /*!< [1..1] TECCED                                                             */
            __IOM uint32_t DECCED    : 1; /*!< [2..2] DECCED                                                             */
            __IOM uint32_t PECCED    : 1; /*!< [3..3] PECCED                                                             */
            __IOM uint32_t DSECCED   : 1; /*!< [4..4] DSECCED                                                            */
            __IOM uint32_t MECCED    : 1; /*!< [5..5] MECCED                                                             */
            __IOM uint32_t AECCED    : 1; /*!< [6..6] AECCED                                                             */
            __IOM uint32_t TSECCED   : 1; /*!< [7..7] TSECCED                                                            */
            __IOM uint32_t L23UECCED : 1; /*!< [8..8] L23UECCED                                                          */
            __IOM uint32_t TSOVFED   : 1; /*!< [9..9] TSOVFED                                                            */
            __IOM uint32_t USMFSED   : 1; /*!< [10..10] USMFSED                                                          */
            __IOM uint32_t TFED      : 1; /*!< [11..11] TFED                                                             */
            __IOM uint32_t SEQED     : 1; /*!< [12..12] SEQED                                                            */
            __IOM uint32_t IIPED     : 1; /*!< [13..13] IIPED                                                            */
            __IOM uint32_t TXDNED    : 1; /*!< [14..14] TXDNED                                                           */
            __IOM uint32_t TSHED     : 1; /*!< [15..15] TSHED                                                            */
            __IOM uint32_t FSED0     : 1; /*!< [16..16] FSED0                                                            */
            __IOM uint32_t FSED1     : 1; /*!< [17..17] FSED1                                                            */
            __IOM uint32_t FSED2     : 1; /*!< [18..18] FSED2                                                            */
            __IOM uint32_t FSED3     : 1; /*!< [19..19] FSED3                                                            */
            __IOM uint32_t FSED4     : 1; /*!< [20..20] FSED4                                                            */
            __IOM uint32_t FSED5     : 1; /*!< [21..21] FSED5                                                            */
            __IOM uint32_t FSED6     : 1; /*!< [22..22] FSED6                                                            */
            __IOM uint32_t FSED7     : 1; /*!< [23..23] FSED7                                                            */
            __IOM uint32_t TDFED0    : 1; /*!< [24..24] TDFED0                                                           */
            __IOM uint32_t TDFED1    : 1; /*!< [25..25] TDFED1                                                           */
            uint32_t                 : 2;
            __IOM uint32_t TSDNED0   : 1; /*!< [28..28] TSDNED0                                                          */
            __IOM uint32_t TSDNED1   : 1; /*!< [29..29] TSDNED1                                                          */
            uint32_t                 : 2;
        } GWEID0_b;
    };
    __IM uint32_t RESERVED28;

    union
    {
        __IOM uint32_t GWEIS1;         /*!< (@ 0x000011A0) GWCA Error Interrupt Status Register 1 (GWEIS1)            */

        struct
        {
            __IOM uint32_t DQOES0 : 1; /*!< [0..0] DQOES0                                                             */
            __IOM uint32_t DQOES1 : 1; /*!< [1..1] DQOES1                                                             */
            __IOM uint32_t DQOES2 : 1; /*!< [2..2] DQOES2                                                             */
            __IOM uint32_t DQOES3 : 1; /*!< [3..3] DQOES3                                                             */
            __IOM uint32_t DQOES4 : 1; /*!< [4..4] DQOES4                                                             */
            __IOM uint32_t DQOES5 : 1; /*!< [5..5] DQOES5                                                             */
            __IOM uint32_t DQOES6 : 1; /*!< [6..6] DQOES6                                                             */
            __IOM uint32_t DQOES7 : 1; /*!< [7..7] DQOES7                                                             */
            uint32_t              : 8;
            __IOM uint32_t DQSES0 : 1; /*!< [16..16] DQSES0                                                           */
            __IOM uint32_t DQSES1 : 1; /*!< [17..17] DQSES1                                                           */
            __IOM uint32_t DQSES2 : 1; /*!< [18..18] DQSES2                                                           */
            __IOM uint32_t DQSES3 : 1; /*!< [19..19] DQSES3                                                           */
            __IOM uint32_t DQSES4 : 1; /*!< [20..20] DQSES4                                                           */
            __IOM uint32_t DQSES5 : 1; /*!< [21..21] DQSES5                                                           */
            __IOM uint32_t DQSES6 : 1; /*!< [22..22] DQSES6                                                           */
            __IOM uint32_t DQSES7 : 1; /*!< [23..23] DQSES7                                                           */
            uint32_t              : 8;
        } GWEIS1_b;
    };

    union
    {
        __IOM uint32_t GWEIE1;         /*!< (@ 0x000011A4) GWCA Error Interrupt Enable Register 1 (GWEIE1)            */

        struct
        {
            __IOM uint32_t DQOEE0 : 1; /*!< [0..0] DQOEE0                                                             */
            __IOM uint32_t DQOEE1 : 1; /*!< [1..1] DQOEE1                                                             */
            __IOM uint32_t DQOEE2 : 1; /*!< [2..2] DQOEE2                                                             */
            __IOM uint32_t DQOEE3 : 1; /*!< [3..3] DQOEE3                                                             */
            __IOM uint32_t DQOEE4 : 1; /*!< [4..4] DQOEE4                                                             */
            __IOM uint32_t DQOEE5 : 1; /*!< [5..5] DQOEE5                                                             */
            __IOM uint32_t DQOEE6 : 1; /*!< [6..6] DQOEE6                                                             */
            __IOM uint32_t DQOEE7 : 1; /*!< [7..7] DQOEE7                                                             */
            uint32_t              : 8;
            __IOM uint32_t DQSEE0 : 1; /*!< [16..16] DQSEE0                                                           */
            __IOM uint32_t DQSEE1 : 1; /*!< [17..17] DQSEE1                                                           */
            __IOM uint32_t DQSEE2 : 1; /*!< [18..18] DQSEE2                                                           */
            __IOM uint32_t DQSEE3 : 1; /*!< [19..19] DQSEE3                                                           */
            __IOM uint32_t DQSEE4 : 1; /*!< [20..20] DQSEE4                                                           */
            __IOM uint32_t DQSEE5 : 1; /*!< [21..21] DQSEE5                                                           */
            __IOM uint32_t DQSEE6 : 1; /*!< [22..22] DQSEE6                                                           */
            __IOM uint32_t DQSEE7 : 1; /*!< [23..23] DQSEE7                                                           */
            uint32_t              : 8;
        } GWEIE1_b;
    };

    union
    {
        __IOM uint32_t GWEID1;         /*!< (@ 0x000011A8) GWCA Error Interrupt Disable Register 1 (GWEID1)           */

        struct
        {
            __IOM uint32_t DQOED0 : 1; /*!< [0..0] DQOED0                                                             */
            __IOM uint32_t DQOED1 : 1; /*!< [1..1] DQOED1                                                             */
            __IOM uint32_t DQOED2 : 1; /*!< [2..2] DQOED2                                                             */
            __IOM uint32_t DQOED3 : 1; /*!< [3..3] DQOED3                                                             */
            __IOM uint32_t DQOED4 : 1; /*!< [4..4] DQOED4                                                             */
            __IOM uint32_t DQOED5 : 1; /*!< [5..5] DQOED5                                                             */
            __IOM uint32_t DQOED6 : 1; /*!< [6..6] DQOED6                                                             */
            __IOM uint32_t DQOED7 : 1; /*!< [7..7] DQOED7                                                             */
            uint32_t              : 8;
            __IOM uint32_t DQSED0 : 1; /*!< [16..16] DQSED0                                                           */
            __IOM uint32_t DQSED1 : 1; /*!< [17..17] DQSED1                                                           */
            __IOM uint32_t DQSED2 : 1; /*!< [18..18] DQSED2                                                           */
            __IOM uint32_t DQSED3 : 1; /*!< [19..19] DQSED3                                                           */
            __IOM uint32_t DQSED4 : 1; /*!< [20..20] DQSED4                                                           */
            __IOM uint32_t DQSED5 : 1; /*!< [21..21] DQSED5                                                           */
            __IOM uint32_t DQSED6 : 1; /*!< [22..22] DQSED6                                                           */
            __IOM uint32_t DQSED7 : 1; /*!< [23..23] DQSED7                                                           */
            uint32_t              : 8;
        } GWEID1_b;
    };
    __IM uint32_t  RESERVED29[21];
    __IOM uint32_t GWEIS20;            /*!< (@ 0x00001200) GWCA Error Interrupt Status Register 2i (GWEIS2i)
                                        *                  (i = 0, 1)                                                 */
    __IOM uint32_t GWEIE20;            /*!< (@ 0x00001204) GWCA Error Interrupt Enable Register 2i (GWEIE2i)
                                        *                  (i = 0, 1)                                                 */
    __IOM uint32_t GWEID20;            /*!< (@ 0x00001208) GWCA Error Interrupt Disable Register 2i (GWEID2i)
                                        *                  (i = 0, 1)                                                 */
    __IM uint32_t  RESERVED30;
    __IOM uint32_t GWEIS21;            /*!< (@ 0x00001210) GWCA Error Interrupt Status Register 2i (GWEIS2i)
                                        *                  (i = 0, 1)                                                 */
    __IOM uint32_t GWEIE21;            /*!< (@ 0x00001214) GWCA Error Interrupt Enable Register 2i (GWEIE2i)
                                        *                  (i = 0, 1)                                                 */
    __IOM uint32_t GWEID21;            /*!< (@ 0x00001218) GWCA Error Interrupt Disable Register 2i (GWEID2i)
                                        *                  (i = 0, 1)                                                 */
    __IM uint32_t RESERVED31[25];

    union
    {
        __IOM uint32_t GWEIS3;         /*!< (@ 0x00001280) GWCA Error Interrupt Status Register 3 (GWEIS3)            */

        struct
        {
            __IOM uint32_t IAOES0 : 1; /*!< [0..0] IAOES0                                                             */
            __IOM uint32_t IAOES1 : 1; /*!< [1..1] IAOES1                                                             */
            __IOM uint32_t IAOES2 : 1; /*!< [2..2] IAOES2                                                             */
            __IOM uint32_t IAOES3 : 1; /*!< [3..3] IAOES3                                                             */
            uint32_t              : 28;
        } GWEIS3_b;
    };

    union
    {
        __IOM uint32_t GWEIE3;         /*!< (@ 0x00001284) GWCA Error Interrupt Enable Register 3 (GWEIE3)            */

        struct
        {
            __IOM uint32_t IAOEE0 : 1; /*!< [0..0] IAOEE0                                                             */
            __IOM uint32_t IAOEE1 : 1; /*!< [1..1] IAOEE1                                                             */
            __IOM uint32_t IAOEE2 : 1; /*!< [2..2] IAOEE2                                                             */
            __IOM uint32_t IAOEE3 : 1; /*!< [3..3] IAOEE3                                                             */
            uint32_t              : 28;
        } GWEIE3_b;
    };

    union
    {
        __IOM uint32_t GWEID3;         /*!< (@ 0x00001288) GWCA Error Interrupt Disable Register 3 (GWEID3)           */

        struct
        {
            __IOM uint32_t IAOED0 : 1; /*!< [0..0] IAOED0                                                             */
            __IOM uint32_t IAOED1 : 1; /*!< [1..1] IAOED1                                                             */
            __IOM uint32_t IAOED2 : 1; /*!< [2..2] IAOED2                                                             */
            __IOM uint32_t IAOED3 : 1; /*!< [3..3] IAOED3                                                             */
            uint32_t              : 28;
        } GWEID3_b;
    };
    __IM uint32_t RESERVED32;

    union
    {
        __IOM uint32_t GWEIS4;          /*!< (@ 0x00001290) GWCA Error Interrupt Status Register 4 (GWEIS4)            */

        struct
        {
            __IOM uint32_t DSSES   : 1; /*!< [0..0] DSSES                                                              */
            __IOM uint32_t DSSEIOS : 1; /*!< [1..1] DSSEIOS                                                            */
            uint32_t               : 6;
            __IOM uint32_t DSSECN  : 6; /*!< [13..8] DSSECN                                                            */
            uint32_t               : 2;
            __IOM uint32_t DSES    : 1; /*!< [16..16] DSES                                                             */
            __IOM uint32_t DSEIOS  : 1; /*!< [17..17] DSEIOS                                                           */
            uint32_t               : 6;
            __IOM uint32_t DSECN   : 6; /*!< [29..24] DSECN                                                            */
            uint32_t               : 2;
        } GWEIS4_b;
    };

    union
    {
        __IOM uint32_t GWEIE4;          /*!< (@ 0x00001294) GWCA Error Interrupt Enable Register 4 (GWEIE4)            */

        struct
        {
            __IOM uint32_t DSSEE   : 1; /*!< [0..0] DSSEE                                                              */
            __IOM uint32_t DSSEIOE : 1; /*!< [1..1] DSSEIOE                                                            */
            uint32_t               : 14;
            __IOM uint32_t DSEE    : 1; /*!< [16..16] DSEE                                                             */
            __IOM uint32_t DSEIOE  : 1; /*!< [17..17] DSEIOE                                                           */
            uint32_t               : 14;
        } GWEIE4_b;
    };

    union
    {
        __IOM uint32_t GWEID4;          /*!< (@ 0x00001298) GWCA Error Interrupt Disable Register 4 (GWEID4)           */

        struct
        {
            __IOM uint32_t DSSED   : 1; /*!< [0..0] DSSED                                                              */
            __IOM uint32_t DSSEIOD : 1; /*!< [1..1] DSSEIOD                                                            */
            uint32_t               : 14;
            __IOM uint32_t DSED    : 1; /*!< [16..16] DSED                                                             */
            __IOM uint32_t DSEIOD  : 1; /*!< [17..17] DSEIOD                                                           */
            uint32_t               : 14;
        } GWEID4_b;
    };
    __IM uint32_t RESERVED33;

    union
    {
        __IOM uint32_t GWEIS5;           /*!< (@ 0x000012A0) GWCA Error Interrupt Status Register 5 (GWEIS5)            */

        struct
        {
            __IOM uint32_t DCTES    : 1; /*!< [0..0] DCTES                                                              */
            __IOM uint32_t DCTEIOS  : 1; /*!< [1..1] DCTEIOS                                                            */
            uint32_t                : 6;
            __IOM uint32_t DCTECN   : 6; /*!< [13..8] DCTECN                                                            */
            uint32_t                : 2;
            __IOM uint32_t RXDNES   : 1; /*!< [16..16] RXDNES                                                           */
            __IOM uint32_t RXDNEIOS : 1; /*!< [17..17] RXDNEIOS                                                         */
            uint32_t                : 14;
        } GWEIS5_b;
    };

    union
    {
        __IOM uint32_t GWEIE5;           /*!< (@ 0x000012A4) GWCA Error Interrupt Enable Register 5 (GWEIE5)            */

        struct
        {
            __IOM uint32_t DCTEE    : 1; /*!< [0..0] DCTEE                                                              */
            __IOM uint32_t DCTEIOE  : 1; /*!< [1..1] DCTEIOE                                                            */
            uint32_t                : 14;
            __IOM uint32_t RXDNEE   : 1; /*!< [16..16] RXDNEE                                                           */
            __IOM uint32_t RXDNEIOE : 1; /*!< [17..17] RXDNEIOE                                                         */
            uint32_t                : 14;
        } GWEIE5_b;
    };

    union
    {
        __IOM uint32_t GWEID5;           /*!< (@ 0x000012A8) GWCA Error Interrupt Disable Register 5 (GWEID5)           */

        struct
        {
            __IOM uint32_t DCTED    : 1; /*!< [0..0] DCTED                                                              */
            __IOM uint32_t DCTEIOD  : 1; /*!< [1..1] DCTEIOD                                                            */
            uint32_t                : 13;
            __IOM uint32_t RXDNED   : 1; /*!< [15..15] RXDNED                                                           */
            __IOM uint32_t RXDNEIOD : 1; /*!< [16..16] RXDNEIOD                                                         */
            uint32_t                : 15;
        } GWEID5_b;
    };
} R_GWCA0_Type;                          /*!< Size = 4780 (0x12ac)                                                      */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif                                   /* R_GWCA_REG_H */
