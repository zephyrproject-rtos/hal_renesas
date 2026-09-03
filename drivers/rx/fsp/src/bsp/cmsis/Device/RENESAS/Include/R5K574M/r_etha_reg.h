/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ETHA_REG_H
#define R_ETHA_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_ETHA0                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Ethernet Agent (R_ETHA0)
 */

typedef struct                         /*!< (@ 0x874CA000) R_ETHA0 Structure                                          */
{
    union
    {
        __IOM uint32_t EAMC;           /*!< (@ 0x00000000) Ethernet Agent Mode Configuration Register (EAMC)          */

        struct
        {
            __IOM uint32_t OPC : 2;    /*!< [1..0] OPC                                                                */
            uint32_t           : 30;
        } EAMC_b;
    };

    union
    {
        __IOM uint32_t EAMS;           /*!< (@ 0x00000004) Ethernet Agent Mode Status Register (EAMS)                 */

        struct
        {
            __IOM uint32_t OPS : 2;    /*!< [1..0] OPS                                                                */
            uint32_t           : 30;
        } EAMS_b;
    };
    __IM uint32_t RESERVED[2];

    union
    {
        __IOM uint32_t EAIRC;          /*!< (@ 0x00000010) Ethernet Agent IPV Remapping Configuration Register
                                        *                  [802.1Q] (EAIRC)                                           */

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
        } EAIRC_b;
    };

    union
    {
        __IOM uint32_t EATDQSC;        /*!< (@ 0x00000014) Ethernet Agent TX Descriptor Queue Security Configuration
                                        *                  Register (EATDQSC)                                         */

        struct
        {
            __IOM uint32_t TDQSL0 : 1; /*!< [0..0] TDQSL0                                                             */
            __IOM uint32_t TDQSL1 : 1; /*!< [1..1] TDQSL1                                                             */
            __IOM uint32_t TDQSL2 : 1; /*!< [2..2] TDQSL2                                                             */
            __IOM uint32_t TDQSL3 : 1; /*!< [3..3] TDQSL3                                                             */
            __IOM uint32_t TDQSL4 : 1; /*!< [4..4] TDQSL4                                                             */
            __IOM uint32_t TDQSL5 : 1; /*!< [5..5] TDQSL5                                                             */
            __IOM uint32_t TDQSL6 : 1; /*!< [6..6] TDQSL6                                                             */
            __IOM uint32_t TDQSL7 : 1; /*!< [7..7] TDQSL7                                                             */
            uint32_t              : 24;
        } EATDQSC_b;
    };

    union
    {
        __IOM uint32_t EATDQC;         /*!< (@ 0x00000018) Ethernet Agent TX Descriptor Queue Configuration
                                        *                  Register (EATDQC)                                          */

        struct
        {
            __IOM uint32_t TDQD0  : 1; /*!< [0..0] TDQD0                                                              */
            __IOM uint32_t TDQD1  : 1; /*!< [1..1] TDQD1                                                              */
            __IOM uint32_t TDQD2  : 1; /*!< [2..2] TDQD2                                                              */
            __IOM uint32_t TDQD3  : 1; /*!< [3..3] TDQD3                                                              */
            __IOM uint32_t TDQD4  : 1; /*!< [4..4] TDQD4                                                              */
            __IOM uint32_t TDQD5  : 1; /*!< [5..5] TDQD5                                                              */
            __IOM uint32_t TDQD6  : 1; /*!< [6..6] TDQD6                                                              */
            __IOM uint32_t TDQD7  : 1; /*!< [7..7] TDQD7                                                              */
            __IOM uint32_t TCTDQD : 1; /*!< [8..8] TCTDQD                                                             */
            uint32_t              : 7;
            __IOM uint32_t TDQP0  : 1; /*!< [16..16] TDQP0                                                            */
            __IOM uint32_t TDQP1  : 1; /*!< [17..17] TDQP1                                                            */
            __IOM uint32_t TDQP2  : 1; /*!< [18..18] TDQP2                                                            */
            __IOM uint32_t TDQP3  : 1; /*!< [19..19] TDQP3                                                            */
            __IOM uint32_t TDQP4  : 1; /*!< [20..20] TDQP4                                                            */
            __IOM uint32_t TDQP5  : 1; /*!< [21..21] TDQP5                                                            */
            __IOM uint32_t TDQP6  : 1; /*!< [22..22] TDQP6                                                            */
            __IOM uint32_t TDQP7  : 1; /*!< [23..23] TDQP7                                                            */
            uint32_t              : 8;
        } EATDQC_b;
    };

    union
    {
        __IOM uint32_t EATDQAC;        /*!< (@ 0x0000001C) Ethernet Agent TX Descriptor Queue Arbitration
                                        *                  Configuration Register (EATDQAC)                           */

        struct
        {
            __IOM uint32_t TDQA0 : 4;  /*!< [3..0] TDQA0                                                              */
            __IOM uint32_t TDQA1 : 4;  /*!< [7..4] TDQA1                                                              */
            __IOM uint32_t TDQA2 : 4;  /*!< [11..8] TDQA2                                                             */
            __IOM uint32_t TDQA3 : 4;  /*!< [15..12] TDQA3                                                            */
            __IOM uint32_t TDQA4 : 4;  /*!< [19..16] TDQA4                                                            */
            __IOM uint32_t TDQA5 : 4;  /*!< [23..20] TDQA5                                                            */
            __IOM uint32_t TDQA6 : 4;  /*!< [27..24] TDQA6                                                            */
            __IOM uint32_t TDQA7 : 4;  /*!< [31..28] TDQA7                                                            */
        } EATDQAC_b;
    };

    union
    {
        __IOM uint32_t EATPEC;         /*!< (@ 0x00000020) Ethernet Agent TX Pre-Emption Configuration Register
                                        *                  (EATPEC)                                                   */

        struct
        {
            __IOM uint32_t TTQ0 : 1;   /*!< [0..0] TTQ0                                                               */
            __IOM uint32_t TTQ1 : 1;   /*!< [1..1] TTQ1                                                               */
            __IOM uint32_t TTQ2 : 1;   /*!< [2..2] TTQ2                                                               */
            __IOM uint32_t TTQ3 : 1;   /*!< [3..3] TTQ3                                                               */
            __IOM uint32_t TTQ4 : 1;   /*!< [4..4] TTQ4                                                               */
            __IOM uint32_t TTQ5 : 1;   /*!< [5..5] TTQ5                                                               */
            __IOM uint32_t TTQ6 : 1;   /*!< [6..6] TTQ6                                                               */
            __IOM uint32_t TTQ7 : 1;   /*!< [7..7] TTQ7                                                               */
            __IOM uint32_t TTQ8 : 1;   /*!< [8..8] TTQ8                                                               */
            __IOM uint32_t TTQ9 : 1;   /*!< [9..9] TTQ9                                                               */
            uint32_t            : 6;
            __IOM uint32_t AFS  : 2;   /*!< [17..16] AFS                                                              */
            uint32_t            : 14;
        } EATPEC_b;
    };
    __IM uint32_t RESERVED1[7];

    union
    {
        __IOM uint32_t EATMFSC0;       /*!< (@ 0x00000040) Ethernet Agent Transmission Maximum Frame Size
                                        *                  Configuration Register q (EATMFSCq) (q =
                                        *                  0 to 7)                                                    */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } EATMFSC0_b;
    };

    union
    {
        __IOM uint32_t EATMFSC1;       /*!< (@ 0x00000044) Ethernet Agent Transmission Maximum Frame Size
                                        *                  Configuration Register q (EATMFSCq) (q =
                                        *                  0 to 7)                                                    */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } EATMFSC1_b;
    };

    union
    {
        __IOM uint32_t EATMFSC2;       /*!< (@ 0x00000048) Ethernet Agent Transmission Maximum Frame Size
                                        *                  Configuration Register q (EATMFSCq) (q =
                                        *                  0 to 7)                                                    */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } EATMFSC2_b;
    };

    union
    {
        __IOM uint32_t EATMFSC3;       /*!< (@ 0x0000004C) Ethernet Agent Transmission Maximum Frame Size
                                        *                  Configuration Register q (EATMFSCq) (q =
                                        *                  0 to 7)                                                    */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } EATMFSC3_b;
    };

    union
    {
        __IOM uint32_t EATMFSC4;       /*!< (@ 0x00000050) Ethernet Agent Transmission Maximum Frame Size
                                        *                  Configuration Register q (EATMFSCq) (q =
                                        *                  0 to 7)                                                    */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } EATMFSC4_b;
    };

    union
    {
        __IOM uint32_t EATMFSC5;       /*!< (@ 0x00000054) Ethernet Agent Transmission Maximum Frame Size
                                        *                  Configuration Register q (EATMFSCq) (q =
                                        *                  0 to 7)                                                    */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } EATMFSC5_b;
    };

    union
    {
        __IOM uint32_t EATMFSC6;       /*!< (@ 0x00000058) Ethernet Agent Transmission Maximum Frame Size
                                        *                  Configuration Register q (EATMFSCq) (q =
                                        *                  0 to 7)                                                    */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } EATMFSC6_b;
    };

    union
    {
        __IOM uint32_t EATMFSC7;       /*!< (@ 0x0000005C) Ethernet Agent Transmission Maximum Frame Size
                                        *                  Configuration Register q (EATMFSCq) (q =
                                        *                  0 to 7)                                                    */

        struct
        {
            __IOM uint32_t MFS : 16;   /*!< [15..0] MFS                                                               */
            uint32_t           : 16;
        } EATMFSC7_b;
    };

    union
    {
        __IOM uint32_t EATDQDC0;       /*!< (@ 0x00000060) Ethernet Agent Transmission Descriptor Queue
                                        *                  Depth Configuration Register q (EATDQDCq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } EATDQDC0_b;
    };

    union
    {
        __IOM uint32_t EATDQDC1;       /*!< (@ 0x00000064) Ethernet Agent Transmission Descriptor Queue
                                        *                  Depth Configuration Register q (EATDQDCq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } EATDQDC1_b;
    };

    union
    {
        __IOM uint32_t EATDQDC2;       /*!< (@ 0x00000068) Ethernet Agent Transmission Descriptor Queue
                                        *                  Depth Configuration Register q (EATDQDCq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } EATDQDC2_b;
    };

    union
    {
        __IOM uint32_t EATDQDC3;       /*!< (@ 0x0000006C) Ethernet Agent Transmission Descriptor Queue
                                        *                  Depth Configuration Register q (EATDQDCq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } EATDQDC3_b;
    };

    union
    {
        __IOM uint32_t EATDQDC4;       /*!< (@ 0x00000070) Ethernet Agent Transmission Descriptor Queue
                                        *                  Depth Configuration Register q (EATDQDCq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } EATDQDC4_b;
    };

    union
    {
        __IOM uint32_t EATDQDC5;       /*!< (@ 0x00000074) Ethernet Agent Transmission Descriptor Queue
                                        *                  Depth Configuration Register q (EATDQDCq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } EATDQDC5_b;
    };

    union
    {
        __IOM uint32_t EATDQDC6;       /*!< (@ 0x00000078) Ethernet Agent Transmission Descriptor Queue
                                        *                  Depth Configuration Register q (EATDQDCq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } EATDQDC6_b;
    };

    union
    {
        __IOM uint32_t EATDQDC7;       /*!< (@ 0x0000007C) Ethernet Agent Transmission Descriptor Queue
                                        *                  Depth Configuration Register q (EATDQDCq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DQD : 10;   /*!< [9..0] DQD                                                                */
            uint32_t           : 22;
        } EATDQDC7_b;
    };

    union
    {
        __IOM uint32_t EATDQM0;        /*!< (@ 0x00000080) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Monitoring Register (EATDQMq) (q = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } EATDQM0_b;
    };

    union
    {
        __IOM uint32_t EATDQM1;        /*!< (@ 0x00000084) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Monitoring Register (EATDQMq) (q = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } EATDQM1_b;
    };

    union
    {
        __IOM uint32_t EATDQM2;        /*!< (@ 0x00000088) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Monitoring Register (EATDQMq) (q = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } EATDQM2_b;
    };

    union
    {
        __IOM uint32_t EATDQM3;        /*!< (@ 0x0000008C) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Monitoring Register (EATDQMq) (q = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } EATDQM3_b;
    };

    union
    {
        __IOM uint32_t EATDQM4;        /*!< (@ 0x00000090) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Monitoring Register (EATDQMq) (q = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } EATDQM4_b;
    };

    union
    {
        __IOM uint32_t EATDQM5;        /*!< (@ 0x00000094) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Monitoring Register (EATDQMq) (q = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } EATDQM5_b;
    };

    union
    {
        __IOM uint32_t EATDQM6;        /*!< (@ 0x00000098) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Monitoring Register (EATDQMq) (q = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } EATDQM6_b;
    };

    union
    {
        __IOM uint32_t EATDQM7;        /*!< (@ 0x0000009C) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Monitoring Register (EATDQMq) (q = 0 to
                                        *                  7)                                                         */

        struct
        {
            __IOM uint32_t DNQ : 10;   /*!< [9..0] DNQ                                                                */
            uint32_t           : 22;
        } EATDQM7_b;
    };

    union
    {
        __IOM uint32_t EATDQMLM0;      /*!< (@ 0x000000A0) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Max Level Monitoring Register (EATDQMLMq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } EATDQMLM0_b;
    };

    union
    {
        __IOM uint32_t EATDQMLM1;      /*!< (@ 0x000000A4) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Max Level Monitoring Register (EATDQMLMq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } EATDQMLM1_b;
    };

    union
    {
        __IOM uint32_t EATDQMLM2;      /*!< (@ 0x000000A8) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Max Level Monitoring Register (EATDQMLMq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } EATDQMLM2_b;
    };

    union
    {
        __IOM uint32_t EATDQMLM3;      /*!< (@ 0x000000AC) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Max Level Monitoring Register (EATDQMLMq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } EATDQMLM3_b;
    };

    union
    {
        __IOM uint32_t EATDQMLM4;      /*!< (@ 0x000000B0) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Max Level Monitoring Register (EATDQMLMq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } EATDQMLM4_b;
    };

    union
    {
        __IOM uint32_t EATDQMLM5;      /*!< (@ 0x000000B4) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Max Level Monitoring Register (EATDQMLMq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } EATDQMLM5_b;
    };

    union
    {
        __IOM uint32_t EATDQMLM6;      /*!< (@ 0x000000B8) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Max Level Monitoring Register (EATDQMLMq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } EATDQMLM6_b;
    };

    union
    {
        __IOM uint32_t EATDQMLM7;      /*!< (@ 0x000000BC) Ethernet Agent Transmission Descriptor Queue
                                        *                  q Max Level Monitoring Register (EATDQMLMq)
                                        *                  (q = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t DMLQ : 10;  /*!< [9..0] DMLQ                                                               */
            uint32_t            : 22;
        } EATDQMLM7_b;
    };
    __IM uint32_t RESERVED2[16];

    union
    {
        __IOM uint32_t EACTQC;         /*!< (@ 0x00000100) Ethernet Agent Cut-Through Queue Configuration
                                        *                  Register (EACTQC)                                          */

        struct
        {
            __IOM uint32_t CTQD : 16;  /*!< [15..0] CTQD                                                              */
            uint32_t            : 16;
        } EACTQC_b;
    };

    union
    {
        __IOM uint32_t EACTDQDC;       /*!< (@ 0x00000104) Ethernet Agent Cut-Through Descriptor Queue Depth
                                        *                  Configuration Register (EACTDQDC)                          */

        struct
        {
            __IOM uint32_t CTDQD : 3;  /*!< [2..0] CTDQD                                                              */
            uint32_t             : 29;
        } EACTDQDC_b;
    };

    union
    {
        __IOM uint32_t EACTDQM;        /*!< (@ 0x00000108) Ethernet Agent Cut-Through Descriptor Queue Monitoring
                                        *                  Register (EACTDQM)                                         */

        struct
        {
            __IOM uint32_t CTQDN : 10; /*!< [9..0] CTQDN                                                              */
            uint32_t             : 22;
        } EACTDQM_b;
    };

    union
    {
        __IOM uint32_t EACTDQMLM;      /*!< (@ 0x0000010C) Ethernet Agent Cut-Through Descriptor Queue Max
                                        *                  Level Monitoring Register (EACTDQMLM)                      */

        struct
        {
            __IOM uint32_t CTDMLQ : 3; /*!< [2..0] CTDMLQ                                                             */
            uint32_t              : 29;
        } EACTDQMLM_b;
    };
    __IM uint32_t RESERVED3[8];

    union
    {
        __IOM uint32_t EAVCC;          /*!< (@ 0x00000130) Ethernet Agent VLAN Control Configuration Register
                                        *                  (EAVCC)                                                    */

        struct
        {
            __IOM uint32_t VIM : 1;    /*!< [0..0] VIM                                                                */
            uint32_t           : 15;
            __IOM uint32_t VEM : 3;    /*!< [18..16] VEM                                                              */
            uint32_t           : 13;
        } EAVCC_b;
    };

    union
    {
        __IOM uint32_t EAVTC;          /*!< (@ 0x00000134) Ethernet Agent VLAN TAG Configuration Register
                                        *                  (EAVTC)                                                    */

        struct
        {
            __IOM uint32_t CTV : 12;   /*!< [11..0] CTV                                                               */
            __IOM uint32_t CTP : 3;    /*!< [14..12] CTP                                                              */
            __IOM uint32_t CTD : 1;    /*!< [15..15] CTD                                                              */
            __IOM uint32_t STV : 12;   /*!< [27..16] STV                                                              */
            __IOM uint32_t STP : 3;    /*!< [30..28] STP                                                              */
            __IOM uint32_t STD : 1;    /*!< [31..31] STD                                                              */
        } EAVTC_b;
    };

    union
    {
        __IOM uint32_t EARTFC;         /*!< (@ 0x00000138) Ethernet Agent Reception TAG Filtering Configuration
                                        *                  Register (EARTFC)                                          */

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
        } EARTFC_b;
    };
    __IM uint32_t RESERVED4[49];

    union
    {
        __IOM uint32_t EACAEC;         /*!< (@ 0x00000200) Ethernet Agent CBS Admin Enable Configuration
                                        *                  Register (EACAEC)                                          */

        struct
        {
            __IOM uint32_t CE0 : 1;    /*!< [0..0] CE0                                                                */
            __IOM uint32_t CE1 : 1;    /*!< [1..1] CE1                                                                */
            __IOM uint32_t CE2 : 1;    /*!< [2..2] CE2                                                                */
            __IOM uint32_t CE3 : 1;    /*!< [3..3] CE3                                                                */
            __IOM uint32_t CE4 : 1;    /*!< [4..4] CE4                                                                */
            __IOM uint32_t CE5 : 1;    /*!< [5..5] CE5                                                                */
            __IOM uint32_t CE6 : 1;    /*!< [6..6] CE6                                                                */
            __IOM uint32_t CE7 : 1;    /*!< [7..7] CE7                                                                */
            uint32_t           : 24;
        } EACAEC_b;
    };

    union
    {
        __IOM uint32_t EACC;           /*!< (@ 0x00000204) Ethernet Agent CBS Configuration Register (EACC)           */

        struct
        {
            __IOM uint32_t CC0 : 1;    /*!< [0..0] CC0                                                                */
            __IOM uint32_t CC1 : 1;    /*!< [1..1] CC1                                                                */
            __IOM uint32_t CC2 : 1;    /*!< [2..2] CC2                                                                */
            __IOM uint32_t CC3 : 1;    /*!< [3..3] CC3                                                                */
            __IOM uint32_t CC4 : 1;    /*!< [4..4] CC4                                                                */
            __IOM uint32_t CC5 : 1;    /*!< [5..5] CC5                                                                */
            __IOM uint32_t CC6 : 1;    /*!< [6..6] CC6                                                                */
            __IOM uint32_t CC7 : 1;    /*!< [7..7] CC7                                                                */
            uint32_t           : 24;
        } EACC_b;
    };
    __IM uint32_t RESERVED5[6];

    union
    {
        __IOM uint32_t EACAIVC0;       /*!< (@ 0x00000220) Ethernet Agent CBS Admin Increment Value Configuration
                                        *                  Register q (EACAIVCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACAIVC0_b;
    };

    union
    {
        __IOM uint32_t EACAIVC1;       /*!< (@ 0x00000224) Ethernet Agent CBS Admin Increment Value Configuration
                                        *                  Register q (EACAIVCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACAIVC1_b;
    };

    union
    {
        __IOM uint32_t EACAIVC2;       /*!< (@ 0x00000228) Ethernet Agent CBS Admin Increment Value Configuration
                                        *                  Register q (EACAIVCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACAIVC2_b;
    };

    union
    {
        __IOM uint32_t EACAIVC3;       /*!< (@ 0x0000022C) Ethernet Agent CBS Admin Increment Value Configuration
                                        *                  Register q (EACAIVCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACAIVC3_b;
    };

    union
    {
        __IOM uint32_t EACAIVC4;       /*!< (@ 0x00000230) Ethernet Agent CBS Admin Increment Value Configuration
                                        *                  Register q (EACAIVCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACAIVC4_b;
    };

    union
    {
        __IOM uint32_t EACAIVC5;       /*!< (@ 0x00000234) Ethernet Agent CBS Admin Increment Value Configuration
                                        *                  Register q (EACAIVCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACAIVC5_b;
    };

    union
    {
        __IOM uint32_t EACAIVC6;       /*!< (@ 0x00000238) Ethernet Agent CBS Admin Increment Value Configuration
                                        *                  Register q (EACAIVCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACAIVC6_b;
    };

    union
    {
        __IOM uint32_t EACAIVC7;       /*!< (@ 0x0000023C) Ethernet Agent CBS Admin Increment Value Configuration
                                        *                  Register q (EACAIVCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACAIVC7_b;
    };

    union
    {
        __IOM uint32_t EACAULC0;       /*!< (@ 0x00000240) Ethernet Agent CBS Admin Upper Limit Configuration
                                        *                  Register q (EACAULCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACAULC0_b;
    };

    union
    {
        __IOM uint32_t EACAULC1;       /*!< (@ 0x00000244) Ethernet Agent CBS Admin Upper Limit Configuration
                                        *                  Register q (EACAULCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACAULC1_b;
    };

    union
    {
        __IOM uint32_t EACAULC2;       /*!< (@ 0x00000248) Ethernet Agent CBS Admin Upper Limit Configuration
                                        *                  Register q (EACAULCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACAULC2_b;
    };

    union
    {
        __IOM uint32_t EACAULC3;       /*!< (@ 0x0000024C) Ethernet Agent CBS Admin Upper Limit Configuration
                                        *                  Register q (EACAULCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACAULC3_b;
    };

    union
    {
        __IOM uint32_t EACAULC4;       /*!< (@ 0x00000250) Ethernet Agent CBS Admin Upper Limit Configuration
                                        *                  Register q (EACAULCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACAULC4_b;
    };

    union
    {
        __IOM uint32_t EACAULC5;       /*!< (@ 0x00000254) Ethernet Agent CBS Admin Upper Limit Configuration
                                        *                  Register q (EACAULCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACAULC5_b;
    };

    union
    {
        __IOM uint32_t EACAULC6;       /*!< (@ 0x00000258) Ethernet Agent CBS Admin Upper Limit Configuration
                                        *                  Register q (EACAULCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACAULC6_b;
    };

    union
    {
        __IOM uint32_t EACAULC7;       /*!< (@ 0x0000025C) Ethernet Agent CBS Admin Upper Limit Configuration
                                        *                  Register q (EACAULCq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACAULC7_b;
    };

    union
    {
        __IOM uint32_t EACOEM;         /*!< (@ 0x00000260) Ethernet Agent CBS Oper Enable Monitoring Register
                                        *                  (EACOEM)                                                   */

        struct
        {
            __IOM uint32_t CE0 : 1;    /*!< [0..0] CE0                                                                */
            __IOM uint32_t CE1 : 1;    /*!< [1..1] CE1                                                                */
            __IOM uint32_t CE2 : 1;    /*!< [2..2] CE2                                                                */
            __IOM uint32_t CE3 : 1;    /*!< [3..3] CE3                                                                */
            __IOM uint32_t CE4 : 1;    /*!< [4..4] CE4                                                                */
            __IOM uint32_t CE5 : 1;    /*!< [5..5] CE5                                                                */
            __IOM uint32_t CE6 : 1;    /*!< [6..6] CE6                                                                */
            __IOM uint32_t CE7 : 1;    /*!< [7..7] CE7                                                                */
            uint32_t           : 24;
        } EACOEM_b;
    };
    __IM uint32_t RESERVED6[7];

    union
    {
        __IOM uint32_t EACOIVM0;       /*!< (@ 0x00000280) Ethernet Agent CBS Oper Increment Value Monitoring
                                        *                  Register q (EACOIVMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACOIVM0_b;
    };

    union
    {
        __IOM uint32_t EACOIVM1;       /*!< (@ 0x00000284) Ethernet Agent CBS Oper Increment Value Monitoring
                                        *                  Register q (EACOIVMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACOIVM1_b;
    };

    union
    {
        __IOM uint32_t EACOIVM2;       /*!< (@ 0x00000288) Ethernet Agent CBS Oper Increment Value Monitoring
                                        *                  Register q (EACOIVMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACOIVM2_b;
    };

    union
    {
        __IOM uint32_t EACOIVM3;       /*!< (@ 0x0000028C) Ethernet Agent CBS Oper Increment Value Monitoring
                                        *                  Register q (EACOIVMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACOIVM3_b;
    };

    union
    {
        __IOM uint32_t EACOIVM4;       /*!< (@ 0x00000290) Ethernet Agent CBS Oper Increment Value Monitoring
                                        *                  Register q (EACOIVMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACOIVM4_b;
    };

    union
    {
        __IOM uint32_t EACOIVM5;       /*!< (@ 0x00000294) Ethernet Agent CBS Oper Increment Value Monitoring
                                        *                  Register q (EACOIVMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACOIVM5_b;
    };

    union
    {
        __IOM uint32_t EACOIVM6;       /*!< (@ 0x00000298) Ethernet Agent CBS Oper Increment Value Monitoring
                                        *                  Register q (EACOIVMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACOIVM6_b;
    };

    union
    {
        __IOM uint32_t EACOIVM7;       /*!< (@ 0x0000029C) Ethernet Agent CBS Oper Increment Value Monitoring
                                        *                  Register q (EACOIVMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CIV : 20;   /*!< [19..0] CIV                                                               */
            uint32_t           : 12;
        } EACOIVM7_b;
    };

    union
    {
        __IOM uint32_t EACOULM0;       /*!< (@ 0x000002A0) Ethernet Agent CBS Oper Upper Limit Monitoring
                                        *                  Register q (EACOULMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACOULM0_b;
    };

    union
    {
        __IOM uint32_t EACOULM1;       /*!< (@ 0x000002A4) Ethernet Agent CBS Oper Upper Limit Monitoring
                                        *                  Register q (EACOULMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACOULM1_b;
    };

    union
    {
        __IOM uint32_t EACOULM2;       /*!< (@ 0x000002A8) Ethernet Agent CBS Oper Upper Limit Monitoring
                                        *                  Register q (EACOULMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACOULM2_b;
    };

    union
    {
        __IOM uint32_t EACOULM3;       /*!< (@ 0x000002AC) Ethernet Agent CBS Oper Upper Limit Monitoring
                                        *                  Register q (EACOULMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACOULM3_b;
    };

    union
    {
        __IOM uint32_t EACOULM4;       /*!< (@ 0x000002B0) Ethernet Agent CBS Oper Upper Limit Monitoring
                                        *                  Register q (EACOULMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACOULM4_b;
    };

    union
    {
        __IOM uint32_t EACOULM5;       /*!< (@ 0x000002B4) Ethernet Agent CBS Oper Upper Limit Monitoring
                                        *                  Register q (EACOULMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACOULM5_b;
    };

    union
    {
        __IOM uint32_t EACOULM6;       /*!< (@ 0x000002B8) Ethernet Agent CBS Oper Upper Limit Monitoring
                                        *                  Register q (EACOULMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACOULM6_b;
    };

    union
    {
        __IOM uint32_t EACOULM7;       /*!< (@ 0x000002BC) Ethernet Agent CBS Oper Upper Limit Monitoring
                                        *                  Register q (EACOULMq) (q = 0 to 7)                         */

        struct
        {
            __IOM uint32_t CUL : 31;   /*!< [30..0] CUL                                                               */
            uint32_t           : 1;
        } EACOULM7_b;
    };

    union
    {
        __IOM uint32_t EACGSM;         /*!< (@ 0x000002C0) Ethernet Agent CBS Gate State Monitoring Register
                                        *                  (EACGSM)                                                   */

        struct
        {
            __IOM uint32_t CGS0 : 1;   /*!< [0..0] CGS0                                                               */
            __IOM uint32_t CGS1 : 1;   /*!< [1..1] CGS1                                                               */
            __IOM uint32_t CGS2 : 1;   /*!< [2..2] CGS2                                                               */
            __IOM uint32_t CGS3 : 1;   /*!< [3..3] CGS3                                                               */
            __IOM uint32_t CGS4 : 1;   /*!< [4..4] CGS4                                                               */
            __IOM uint32_t CGS5 : 1;   /*!< [5..5] CGS5                                                               */
            __IOM uint32_t CGS6 : 1;   /*!< [6..6] CGS6                                                               */
            __IOM uint32_t CGS7 : 1;   /*!< [7..7] CGS7                                                               */
            uint32_t            : 24;
        } EACGSM_b;
    };
    __IM uint32_t RESERVED7[15];

    union
    {
        __IOM uint32_t EATASC;         /*!< (@ 0x00000300) Ethernet Agent TAS Configuration Register (EATASC)         */

        struct
        {
            __IOM uint32_t TASE  : 1;  /*!< [0..0] TASE                                                               */
            __IOM uint32_t TASCC : 1;  /*!< [1..1] TASCC                                                              */
            __IOM uint32_t TASCI : 1;  /*!< [2..2] TASCI                                                              */
            uint32_t             : 5;
            __IOM uint32_t TASTS : 1;  /*!< [8..8] TASTS                                                              */
            uint32_t             : 7;
            __IOM uint32_t TASCA : 8;  /*!< [23..16] TASCA                                                            */
            uint32_t             : 8;
        } EATASC_b;
    };

    union
    {
        __IOM uint32_t EATASIGSC;        /*!< (@ 0x00000304) Ethernet Agent TAS Initial Gate State Configuration
                                          *                  Register (EATASIGSC)                                       */

        struct
        {
            __IOM uint32_t TASIGS0  : 1; /*!< [0..0] TASIGS0                                                            */
            __IOM uint32_t TASIGS1  : 1; /*!< [1..1] TASIGS1                                                            */
            __IOM uint32_t TASIGS2  : 1; /*!< [2..2] TASIGS2                                                            */
            __IOM uint32_t TASIGS3  : 1; /*!< [3..3] TASIGS3                                                            */
            __IOM uint32_t TASIGS4  : 1; /*!< [4..4] TASIGS4                                                            */
            __IOM uint32_t TASIGS5  : 1; /*!< [5..5] TASIGS5                                                            */
            __IOM uint32_t TASIGS6  : 1; /*!< [6..6] TASIGS6                                                            */
            __IOM uint32_t TASIGS7  : 1; /*!< [7..7] TASIGS7                                                            */
            __IOM uint32_t TASCTIGS : 1; /*!< [8..8] TASCTIGS                                                           */
            uint32_t                : 23;
        } EATASIGSC_b;
    };
    __IM uint32_t RESERVED8[6];

    union
    {
        __IOM uint32_t EATASENC0;      /*!< (@ 0x00000320) Ethernet Agent TAS Entry Number Configuration
                                        *                  Register i (EATASENCi) (i = 0 to 8)                        */

        struct
        {
            __IOM uint32_t TASAEN : 9; /*!< [8..0] TASAEN                                                             */
            uint32_t              : 23;
        } EATASENC0_b;
    };

    union
    {
        __IOM uint32_t EATASENC1;      /*!< (@ 0x00000324) Ethernet Agent TAS Entry Number Configuration
                                        *                  Register i (EATASENCi) (i = 0 to 8)                        */

        struct
        {
            __IOM uint32_t TASAEN : 9; /*!< [8..0] TASAEN                                                             */
            uint32_t              : 23;
        } EATASENC1_b;
    };

    union
    {
        __IOM uint32_t EATASENC2;      /*!< (@ 0x00000328) Ethernet Agent TAS Entry Number Configuration
                                        *                  Register i (EATASENCi) (i = 0 to 8)                        */

        struct
        {
            __IOM uint32_t TASAEN : 9; /*!< [8..0] TASAEN                                                             */
            uint32_t              : 23;
        } EATASENC2_b;
    };

    union
    {
        __IOM uint32_t EATASENC3;      /*!< (@ 0x0000032C) Ethernet Agent TAS Entry Number Configuration
                                        *                  Register i (EATASENCi) (i = 0 to 8)                        */

        struct
        {
            __IOM uint32_t TASAEN : 9; /*!< [8..0] TASAEN                                                             */
            uint32_t              : 23;
        } EATASENC3_b;
    };

    union
    {
        __IOM uint32_t EATASENC4;      /*!< (@ 0x00000330) Ethernet Agent TAS Entry Number Configuration
                                        *                  Register i (EATASENCi) (i = 0 to 8)                        */

        struct
        {
            __IOM uint32_t TASAEN : 9; /*!< [8..0] TASAEN                                                             */
            uint32_t              : 23;
        } EATASENC4_b;
    };

    union
    {
        __IOM uint32_t EATASENC5;      /*!< (@ 0x00000334) Ethernet Agent TAS Entry Number Configuration
                                        *                  Register i (EATASENCi) (i = 0 to 8)                        */

        struct
        {
            __IOM uint32_t TASAEN : 9; /*!< [8..0] TASAEN                                                             */
            uint32_t              : 23;
        } EATASENC5_b;
    };

    union
    {
        __IOM uint32_t EATASENC6;      /*!< (@ 0x00000338) Ethernet Agent TAS Entry Number Configuration
                                        *                  Register i (EATASENCi) (i = 0 to 8)                        */

        struct
        {
            __IOM uint32_t TASAEN : 9; /*!< [8..0] TASAEN                                                             */
            uint32_t              : 23;
        } EATASENC6_b;
    };

    union
    {
        __IOM uint32_t EATASENC7;      /*!< (@ 0x0000033C) Ethernet Agent TAS Entry Number Configuration
                                        *                  Register i (EATASENCi) (i = 0 to 8)                        */

        struct
        {
            __IOM uint32_t TASAEN : 9; /*!< [8..0] TASAEN                                                             */
            uint32_t              : 23;
        } EATASENC7_b;
    };

    union
    {
        __IOM uint32_t EATASCTENC;       /*!< (@ 0x00000340) Ethernet Agent TAS Cut-Through Entry Number Configuration
                                          *                  Register (EATASCTENC)                                      */

        struct
        {
            __IOM uint32_t TASCTAEN : 9; /*!< [8..0] TASCTAEN                                                           */
            uint32_t                : 23;
        } EATASCTENC_b;
    };
    __IM uint32_t RESERVED9[7];

    union
    {
        __IOM uint32_t EATASENM0;      /*!< (@ 0x00000360) Ethernet Agent TAS Entry Number Monitoring Register
                                        *                  i (EATASENMi) (i = 0 to 8)                                 */

        struct
        {
            __IOM uint32_t TASOEN : 9; /*!< [8..0] TASOEN                                                             */
            uint32_t              : 23;
        } EATASENM0_b;
    };

    union
    {
        __IOM uint32_t EATASENM1;      /*!< (@ 0x00000364) Ethernet Agent TAS Entry Number Monitoring Register
                                        *                  i (EATASENMi) (i = 0 to 8)                                 */

        struct
        {
            __IOM uint32_t TASOEN : 9; /*!< [8..0] TASOEN                                                             */
            uint32_t              : 23;
        } EATASENM1_b;
    };

    union
    {
        __IOM uint32_t EATASENM2;      /*!< (@ 0x00000368) Ethernet Agent TAS Entry Number Monitoring Register
                                        *                  i (EATASENMi) (i = 0 to 8)                                 */

        struct
        {
            __IOM uint32_t TASOEN : 9; /*!< [8..0] TASOEN                                                             */
            uint32_t              : 23;
        } EATASENM2_b;
    };

    union
    {
        __IOM uint32_t EATASENM3;      /*!< (@ 0x0000036C) Ethernet Agent TAS Entry Number Monitoring Register
                                        *                  i (EATASENMi) (i = 0 to 8)                                 */

        struct
        {
            __IOM uint32_t TASOEN : 9; /*!< [8..0] TASOEN                                                             */
            uint32_t              : 23;
        } EATASENM3_b;
    };

    union
    {
        __IOM uint32_t EATASENM4;      /*!< (@ 0x00000370) Ethernet Agent TAS Entry Number Monitoring Register
                                        *                  i (EATASENMi) (i = 0 to 8)                                 */

        struct
        {
            __IOM uint32_t TASOEN : 9; /*!< [8..0] TASOEN                                                             */
            uint32_t              : 23;
        } EATASENM4_b;
    };

    union
    {
        __IOM uint32_t EATASENM5;      /*!< (@ 0x00000374) Ethernet Agent TAS Entry Number Monitoring Register
                                        *                  i (EATASENMi) (i = 0 to 8)                                 */

        struct
        {
            __IOM uint32_t TASOEN : 9; /*!< [8..0] TASOEN                                                             */
            uint32_t              : 23;
        } EATASENM5_b;
    };

    union
    {
        __IOM uint32_t EATASENM6;      /*!< (@ 0x00000378) Ethernet Agent TAS Entry Number Monitoring Register
                                        *                  i (EATASENMi) (i = 0 to 8)                                 */

        struct
        {
            __IOM uint32_t TASOEN : 9; /*!< [8..0] TASOEN                                                             */
            uint32_t              : 23;
        } EATASENM6_b;
    };

    union
    {
        __IOM uint32_t EATASENM7;      /*!< (@ 0x0000037C) Ethernet Agent TAS Entry Number Monitoring Register
                                        *                  i (EATASENMi) (i = 0 to 8)                                 */

        struct
        {
            __IOM uint32_t TASOEN : 9; /*!< [8..0] TASOEN                                                             */
            uint32_t              : 23;
        } EATASENM7_b;
    };

    union
    {
        __IOM uint32_t EATASCTENM;       /*!< (@ 0x00000380) Ethernet Agent TAS Cut-Through Entry Number Monitoring
                                          *                  Register (EATASCTENM)                                      */

        struct
        {
            __IOM uint32_t TASCTOEN : 9; /*!< [8..0] TASCTOEN                                                           */
            uint32_t                : 23;
        } EATASCTENM_b;
    };
    __IM uint32_t RESERVED10[7];

    union
    {
        __IOM uint32_t EATASCSTC0;         /*!< (@ 0x000003A0) Ethernet Agent TAS Cycle Start Time Configuration
                                            *                  Register 0 (EATASCSTC0)                                    */

        struct
        {
            __IOM uint32_t TASACSTP0 : 32; /*!< [31..0] TASACSTP0                                                         */
        } EATASCSTC0_b;
    };

    union
    {
        __IOM uint32_t EATASCSTC1;         /*!< (@ 0x000003A4) Ethernet Agent TAS Cycle Start Time Configuration
                                            *                  Register 1 (EATASCSTC1)                                    */

        struct
        {
            __IOM uint32_t TASACSTP1 : 32; /*!< [31..0] TASACSTP1                                                         */
        } EATASCSTC1_b;
    };

    union
    {
        __IOM uint32_t EATASCSTM0;         /*!< (@ 0x000003A8) Ethernet Agent TAS Cycle Start Time Monitoring
                                            *                  Register 0 (EATASCSTM0)                                    */

        struct
        {
            __IOM uint32_t TASOCSTP0 : 32; /*!< [31..0] TASOCSTP0                                                         */
        } EATASCSTM0_b;
    };

    union
    {
        __IOM uint32_t EATASCSTM1;         /*!< (@ 0x000003AC) Ethernet Agent TAS Cycle Start Time Monitoring
                                            *                  Register 1 (EATASCSTM1)                                    */

        struct
        {
            __IOM uint32_t TASOCSTP1 : 32; /*!< [31..0] TASOCSTP1                                                         */
        } EATASCSTM1_b;
    };

    union
    {
        __IOM uint32_t EATASCTC;        /*!< (@ 0x000003B0) Ethernet Agent TAS Cycle Time Configuration Register
                                         *                  (EATASCTC)                                                 */

        struct
        {
            __IOM uint32_t TASACT : 32; /*!< [31..0] TASACT                                                            */
        } EATASCTC_b;
    };

    union
    {
        __IOM uint32_t EATASCTM;        /*!< (@ 0x000003B4) Ethernet Agent TAS Cycle Time Monitoring Register
                                         *                  (EATASCTM)                                                 */

        struct
        {
            __IOM uint32_t TASOCT : 32; /*!< [31..0] TASOCT                                                            */
        } EATASCTM_b;
    };
    __IM uint32_t RESERVED11[2];

    union
    {
        __IOM uint32_t EATASGL0;       /*!< (@ 0x000003C0) Ethernet Agent TAS Gate Learn Register 0 (EATASGL0)        */

        struct
        {
            __IOM uint32_t TASGAL : 8; /*!< [7..0] TASGAL                                                             */
            uint32_t              : 24;
        } EATASGL0_b;
    };

    union
    {
        __IOM uint32_t EATASGL1;        /*!< (@ 0x000003C4) Ethernet Agent TAS Gate Learn Register 1 (EATASGL1)        */

        struct
        {
            __IOM uint32_t TASGTL : 28; /*!< [27..0] TASGTL                                                            */
            __IOM uint32_t TASGSL : 1;  /*!< [28..28] TASGSL                                                           */
            uint32_t              : 3;
        } EATASGL1_b;
    };

    union
    {
        __IOM uint32_t EATASGLR;       /*!< (@ 0x000003C8) Ethernet Agent TAS Gate Learn Result Register
                                        *                  (EATASGLR)                                                 */

        struct
        {
            uint32_t          : 31;
            __IOM uint32_t GL : 1;     /*!< [31..31] GL                                                               */
        } EATASGLR_b;
    };
    __IM uint32_t RESERVED12;

    union
    {
        __IOM uint32_t EATASGR;        /*!< (@ 0x000003D0) Ethernet Agent TAS Gate Read Register (EATASGR)            */

        struct
        {
            __IOM uint32_t TASGAR : 8; /*!< [7..0] TASGAR                                                             */
            uint32_t              : 24;
        } EATASGR_b;
    };

    union
    {
        __IOM uint32_t EATASGRR;        /*!< (@ 0x000003D4) Ethernet Agent TAS Gate Read Result Register
                                         *                  (EATASGRR)                                                 */

        struct
        {
            __IOM uint32_t TASGTR : 28; /*!< [27..0] TASGTR                                                            */
            __IOM uint32_t TASGSR : 1;  /*!< [28..28] TASGSR                                                           */
            __IOM uint32_t TASREF : 1;  /*!< [29..29] TASREF                                                           */
            uint32_t              : 1;
            __IOM uint32_t GR     : 1;  /*!< [31..31] GR                                                               */
        } EATASGRR_b;
    };
    __IM uint32_t RESERVED13[2];

    union
    {
        __IOM uint32_t EATASHCC;       /*!< (@ 0x000003E0) Ethernet Agent TAS Hardware Calibration Configuration
                                        *                  Register (EATASHCC)                                        */

        struct
        {
            __IOM uint32_t TASJ : 16;  /*!< [15..0] TASJ                                                              */
            uint32_t            : 16;
        } EATASHCC_b;
    };

    union
    {
        __IOM uint32_t EATASRIRM;       /*!< (@ 0x000003E4) Ethernet Agent TAS RAM Initialization Register
                                         *                  Monitoring Register (EATASRIRM)                            */

        struct
        {
            __IOM uint32_t TASRIOG : 1; /*!< [0..0] TASRIOG                                                            */
            __IOM uint32_t TASRR   : 1; /*!< [1..1] TASRR                                                              */
            uint32_t               : 30;
        } EATASRIRM_b;
    };

    union
    {
        __IOM uint32_t EATASSM;         /*!< (@ 0x000003E8) Ethernet Agent TAS Status Monitoring Register
                                         *                  (EATASSM)                                                  */

        struct
        {
            __IOM uint32_t TASGS0  : 1; /*!< [0..0] TASGS0                                                             */
            __IOM uint32_t TASGS1  : 1; /*!< [1..1] TASGS1                                                             */
            __IOM uint32_t TASGS2  : 1; /*!< [2..2] TASGS2                                                             */
            __IOM uint32_t TASGS3  : 1; /*!< [3..3] TASGS3                                                             */
            __IOM uint32_t TASGS4  : 1; /*!< [4..4] TASGS4                                                             */
            __IOM uint32_t TASGS5  : 1; /*!< [5..5] TASGS5                                                             */
            __IOM uint32_t TASGS6  : 1; /*!< [6..6] TASGS6                                                             */
            __IOM uint32_t TASGS7  : 1; /*!< [7..7] TASGS7                                                             */
            __IOM uint32_t TASCTGS : 1; /*!< [8..8] TASCTGS                                                            */
            uint32_t               : 7;
            __IOM uint32_t TASSO   : 1; /*!< [16..16] TASSO                                                            */
            uint32_t               : 15;
        } EATASSM_b;
    };
    __IM uint32_t RESERVED14[5];

    union
    {
        __IOM uint32_t EAUSMFSECN;       /*!< (@ 0x00000400) Ethernet Agent Switch Minimum Frame Size Error
                                          *                  Counter Register (EAUSMFSECN)                              */

        struct
        {
            __IOM uint32_t USMFSEN : 16; /*!< [15..0] USMFSEN                                                           */
            uint32_t               : 16;
        } EAUSMFSECN_b;
    };

    union
    {
        __IOM uint32_t EATFECN;        /*!< (@ 0x00000404) Ethernet Agent TAG Filtering Error Counter Register
                                        *                  (EATFECN)                                                  */

        struct
        {
            __IOM uint32_t TFEN : 16;  /*!< [15..0] TFEN                                                              */
            uint32_t            : 16;
        } EATFECN_b;
    };

    union
    {
        __IOM uint32_t EAFSECN;        /*!< (@ 0x00000408) Ethernet Agent Frame Size Error Counter Register
                                        *                  (EAFSECN)                                                  */

        struct
        {
            __IOM uint32_t FSEN : 16;  /*!< [15..0] FSEN                                                              */
            uint32_t            : 16;
        } EAFSECN_b;
    };

    union
    {
        __IOM uint32_t EADQOECN;       /*!< (@ 0x0000040C) Ethernet Agent Descriptor Queue Overflow Error
                                        *                  Counter Register (EADQOECN)                                */

        struct
        {
            __IOM uint32_t DQOEN : 16; /*!< [15..0] DQOEN                                                             */
            uint32_t             : 16;
        } EADQOECN_b;
    };

    union
    {
        __IOM uint32_t EADQSECN;       /*!< (@ 0x00000410) Ethernet Agent Descriptor Queue Security Error
                                        *                  Counter Register (EADQSECN)                                */

        struct
        {
            __IOM uint32_t DQSEN : 16; /*!< [15..0] DQSEN                                                             */
            uint32_t             : 16;
        } EADQSECN_b;
    };
    __IM uint32_t RESERVED15[59];

    union
    {
        __IOM uint32_t EAEIS0;            /*!< (@ 0x00000500) Ethernet Agent Error Interrupt Status Register
                                           *                  0 (EAEIS0)                                                 */

        struct
        {
            __IOM uint32_t DECCES    : 1; /*!< [0..0] DECCES                                                             */
            __IOM uint32_t TECCES    : 1; /*!< [1..1] TECCES                                                             */
            __IOM uint32_t PECCES    : 1; /*!< [2..2] PECCES                                                             */
            __IOM uint32_t DSECCES   : 1; /*!< [3..3] DSECCES                                                            */
            __IOM uint32_t L23UECCES : 1; /*!< [4..4] L23UECCES                                                          */
            __IOM uint32_t USMFSES   : 1; /*!< [5..5] USMFSES                                                            */
            __IOM uint32_t TFES      : 1; /*!< [6..6] TFES                                                               */
            uint32_t                 : 1;
            __IOM uint32_t FSES0     : 1; /*!< [8..8] FSES0                                                              */
            __IOM uint32_t FSES1     : 1; /*!< [9..9] FSES1                                                              */
            __IOM uint32_t FSES2     : 1; /*!< [10..10] FSES2                                                            */
            __IOM uint32_t FSES3     : 1; /*!< [11..11] FSES3                                                            */
            __IOM uint32_t FSES4     : 1; /*!< [12..12] FSES4                                                            */
            __IOM uint32_t FSES5     : 1; /*!< [13..13] FSES5                                                            */
            __IOM uint32_t FSES6     : 1; /*!< [14..14] FSES6                                                            */
            __IOM uint32_t FSES7     : 1; /*!< [15..15] FSES7                                                            */
            __IOM uint32_t TASGEES0  : 1; /*!< [16..16] TASGEES0                                                         */
            __IOM uint32_t TASGEES1  : 1; /*!< [17..17] TASGEES1                                                         */
            __IOM uint32_t TASGEES2  : 1; /*!< [18..18] TASGEES2                                                         */
            __IOM uint32_t TASGEES3  : 1; /*!< [19..19] TASGEES3                                                         */
            __IOM uint32_t TASGEES4  : 1; /*!< [20..20] TASGEES4                                                         */
            __IOM uint32_t TASGEES5  : 1; /*!< [21..21] TASGEES5                                                         */
            __IOM uint32_t TASGEES6  : 1; /*!< [22..22] TASGEES6                                                         */
            __IOM uint32_t TASGEES7  : 1; /*!< [23..23] TASGEES7                                                         */
            __IOM uint32_t TASCTGEES : 1; /*!< [24..24] TASCTGEES                                                        */
            uint32_t                 : 7;
        } EAEIS0_b;
    };

    union
    {
        __IOM uint32_t EAEIE0;            /*!< (@ 0x00000504) Ethernet Agent Error Interrupt Enable Register
                                           *                  0 (EAEIE0)                                                 */

        struct
        {
            __IOM uint32_t DECCEE    : 1; /*!< [0..0] DECCEE                                                             */
            __IOM uint32_t TECCEE    : 1; /*!< [1..1] TECCEE                                                             */
            __IOM uint32_t PECCEE    : 1; /*!< [2..2] PECCEE                                                             */
            __IOM uint32_t DSECCEE   : 1; /*!< [3..3] DSECCEE                                                            */
            __IOM uint32_t L23UECCEE : 1; /*!< [4..4] L23UECCEE                                                          */
            __IOM uint32_t USMFSEE   : 1; /*!< [5..5] USMFSEE                                                            */
            __IOM uint32_t TFEE      : 1; /*!< [6..6] TFEE                                                               */
            uint32_t                 : 1;
            __IOM uint32_t FSEE0     : 1; /*!< [8..8] FSEE0                                                              */
            __IOM uint32_t FSEE1     : 1; /*!< [9..9] FSEE1                                                              */
            __IOM uint32_t FSEE2     : 1; /*!< [10..10] FSEE2                                                            */
            __IOM uint32_t FSEE3     : 1; /*!< [11..11] FSEE3                                                            */
            __IOM uint32_t FSEE4     : 1; /*!< [12..12] FSEE4                                                            */
            __IOM uint32_t FSEE5     : 1; /*!< [13..13] FSEE5                                                            */
            __IOM uint32_t FSEE6     : 1; /*!< [14..14] FSEE6                                                            */
            __IOM uint32_t FSEE7     : 1; /*!< [15..15] FSEE7                                                            */
            __IOM uint32_t TASGEEE0  : 1; /*!< [16..16] TASGEEE0                                                         */
            __IOM uint32_t TASGEEE1  : 1; /*!< [17..17] TASGEEE1                                                         */
            __IOM uint32_t TASGEEE2  : 1; /*!< [18..18] TASGEEE2                                                         */
            __IOM uint32_t TASGEEE3  : 1; /*!< [19..19] TASGEEE3                                                         */
            __IOM uint32_t TASGEEE4  : 1; /*!< [20..20] TASGEEE4                                                         */
            __IOM uint32_t TASGEEE5  : 1; /*!< [21..21] TASGEEE5                                                         */
            __IOM uint32_t TASGEEE6  : 1; /*!< [22..22] TASGEEE6                                                         */
            __IOM uint32_t TASGEEE7  : 1; /*!< [23..23] TASGEEE7                                                         */
            __IOM uint32_t TASCTGEEE : 1; /*!< [24..24] TASCTGEEE                                                        */
            uint32_t                 : 7;
        } EAEIE0_b;
    };

    union
    {
        __IOM uint32_t EAEID0;            /*!< (@ 0x00000508) Ethernet Agent Error Interrupt Disable Register
                                           *                  0 (EAEID0)                                                 */

        struct
        {
            __IOM uint32_t DECCED    : 1; /*!< [0..0] DECCED                                                             */
            __IOM uint32_t TECCED    : 1; /*!< [1..1] TECCED                                                             */
            __IOM uint32_t PECCED    : 1; /*!< [2..2] PECCED                                                             */
            __IOM uint32_t DSECCED   : 1; /*!< [3..3] DSECCED                                                            */
            __IOM uint32_t L23UECCED : 1; /*!< [4..4] L23UECCED                                                          */
            __IOM uint32_t USMFSED   : 1; /*!< [5..5] USMFSED                                                            */
            __IOM uint32_t TFED      : 1; /*!< [6..6] TFED                                                               */
            uint32_t                 : 1;
            __IOM uint32_t FSED0     : 1; /*!< [8..8] FSED0                                                              */
            __IOM uint32_t FSED1     : 1; /*!< [9..9] FSED1                                                              */
            __IOM uint32_t FSED2     : 1; /*!< [10..10] FSED2                                                            */
            __IOM uint32_t FSED3     : 1; /*!< [11..11] FSED3                                                            */
            __IOM uint32_t FSED4     : 1; /*!< [12..12] FSED4                                                            */
            __IOM uint32_t FSED5     : 1; /*!< [13..13] FSED5                                                            */
            __IOM uint32_t FSED6     : 1; /*!< [14..14] FSED6                                                            */
            __IOM uint32_t FSED7     : 1; /*!< [15..15] FSED7                                                            */
            __IOM uint32_t TASGEED0  : 1; /*!< [16..16] TASGEED0                                                         */
            __IOM uint32_t TASGEED1  : 1; /*!< [17..17] TASGEED1                                                         */
            __IOM uint32_t TASGEED2  : 1; /*!< [18..18] TASGEED2                                                         */
            __IOM uint32_t TASGEED3  : 1; /*!< [19..19] TASGEED3                                                         */
            __IOM uint32_t TASGEED4  : 1; /*!< [20..20] TASGEED4                                                         */
            __IOM uint32_t TASGEED5  : 1; /*!< [21..21] TASGEED5                                                         */
            __IOM uint32_t TASGEED6  : 1; /*!< [22..22] TASGEED6                                                         */
            __IOM uint32_t TASGEED7  : 1; /*!< [23..23] TASGEED7                                                         */
            __IOM uint32_t TASCTGEED : 1; /*!< [24..24] TASCTGEED                                                        */
            uint32_t                 : 7;
        } EAEID0_b;
    };
    __IM uint32_t RESERVED16;

    union
    {
        __IOM uint32_t EAEIS1;           /*!< (@ 0x00000510) Ethernet Agent Error Interrupt Status Register
                                          *                  1 (EAEIS1)                                                 */

        struct
        {
            __IOM uint32_t CULES0   : 1; /*!< [0..0] CULES0                                                             */
            __IOM uint32_t CULES1   : 1; /*!< [1..1] CULES1                                                             */
            __IOM uint32_t CULES2   : 1; /*!< [2..2] CULES2                                                             */
            __IOM uint32_t CULES3   : 1; /*!< [3..3] CULES3                                                             */
            __IOM uint32_t CULES4   : 1; /*!< [4..4] CULES4                                                             */
            __IOM uint32_t CULES5   : 1; /*!< [5..5] CULES5                                                             */
            __IOM uint32_t CULES6   : 1; /*!< [6..6] CULES6                                                             */
            __IOM uint32_t CULES7   : 1; /*!< [7..7] CULES7                                                             */
            uint32_t                : 8;
            __IOM uint32_t TASGES0  : 1; /*!< [16..16] TASGES0                                                          */
            __IOM uint32_t TASGES1  : 1; /*!< [17..17] TASGES1                                                          */
            __IOM uint32_t TASGES2  : 1; /*!< [18..18] TASGES2                                                          */
            __IOM uint32_t TASGES3  : 1; /*!< [19..19] TASGES3                                                          */
            __IOM uint32_t TASGES4  : 1; /*!< [20..20] TASGES4                                                          */
            __IOM uint32_t TASGES5  : 1; /*!< [21..21] TASGES5                                                          */
            __IOM uint32_t TASGES6  : 1; /*!< [22..22] TASGES6                                                          */
            __IOM uint32_t TASGES7  : 1; /*!< [23..23] TASGES7                                                          */
            __IOM uint32_t TASCTGES : 1; /*!< [24..24] TASCTGES                                                         */
            uint32_t                : 7;
        } EAEIS1_b;
    };

    union
    {
        __IOM uint32_t EAEIE1;           /*!< (@ 0x00000514) Ethernet Agent Error Interrupt Enable Register
                                          *                  1 (EAEIE1)                                                 */

        struct
        {
            __IOM uint32_t CULEE0   : 1; /*!< [0..0] CULEE0                                                             */
            __IOM uint32_t CULEE1   : 1; /*!< [1..1] CULEE1                                                             */
            __IOM uint32_t CULEE2   : 1; /*!< [2..2] CULEE2                                                             */
            __IOM uint32_t CULEE3   : 1; /*!< [3..3] CULEE3                                                             */
            __IOM uint32_t CULEE4   : 1; /*!< [4..4] CULEE4                                                             */
            __IOM uint32_t CULEE5   : 1; /*!< [5..5] CULEE5                                                             */
            __IOM uint32_t CULEE6   : 1; /*!< [6..6] CULEE6                                                             */
            __IOM uint32_t CULEE7   : 1; /*!< [7..7] CULEE7                                                             */
            uint32_t                : 8;
            __IOM uint32_t TASGEE0  : 1; /*!< [16..16] TASGEE0                                                          */
            __IOM uint32_t TASGEE1  : 1; /*!< [17..17] TASGEE1                                                          */
            __IOM uint32_t TASGEE2  : 1; /*!< [18..18] TASGEE2                                                          */
            __IOM uint32_t TASGEE3  : 1; /*!< [19..19] TASGEE3                                                          */
            __IOM uint32_t TASGEE4  : 1; /*!< [20..20] TASGEE4                                                          */
            __IOM uint32_t TASGEE5  : 1; /*!< [21..21] TASGEE5                                                          */
            __IOM uint32_t TASGEE6  : 1; /*!< [22..22] TASGEE6                                                          */
            __IOM uint32_t TASGEE7  : 1; /*!< [23..23] TASGEE7                                                          */
            __IOM uint32_t TASCTGEE : 1; /*!< [24..24] TASCTGEE                                                         */
            uint32_t                : 7;
        } EAEIE1_b;
    };

    union
    {
        __IOM uint32_t EAEID1;           /*!< (@ 0x00000518) Ethernet Agent Error Interrupt Disable Register
                                          *                  1 (EAEID1)                                                 */

        struct
        {
            __IOM uint32_t CULED0   : 1; /*!< [0..0] CULED0                                                             */
            __IOM uint32_t CULED1   : 1; /*!< [1..1] CULED1                                                             */
            __IOM uint32_t CULED2   : 1; /*!< [2..2] CULED2                                                             */
            __IOM uint32_t CULED3   : 1; /*!< [3..3] CULED3                                                             */
            __IOM uint32_t CULED4   : 1; /*!< [4..4] CULED4                                                             */
            __IOM uint32_t CULED5   : 1; /*!< [5..5] CULED5                                                             */
            __IOM uint32_t CULED6   : 1; /*!< [6..6] CULED6                                                             */
            __IOM uint32_t CULED7   : 1; /*!< [7..7] CULED7                                                             */
            uint32_t                : 8;
            __IOM uint32_t TASGED0  : 1; /*!< [16..16] TASGED0                                                          */
            __IOM uint32_t TASGED1  : 1; /*!< [17..17] TASGED1                                                          */
            __IOM uint32_t TASGED2  : 1; /*!< [18..18] TASGED2                                                          */
            __IOM uint32_t TASGED3  : 1; /*!< [19..19] TASGED3                                                          */
            __IOM uint32_t TASGED4  : 1; /*!< [20..20] TASGED4                                                          */
            __IOM uint32_t TASGED5  : 1; /*!< [21..21] TASGED5                                                          */
            __IOM uint32_t TASGED6  : 1; /*!< [22..22] TASGED6                                                          */
            __IOM uint32_t TASGED7  : 1; /*!< [23..23] TASGED7                                                          */
            __IOM uint32_t TASCTGED : 1; /*!< [24..24] TASCTGED                                                         */
            uint32_t                : 7;
        } EAEID1_b;
    };
    __IM uint32_t RESERVED17;

    union
    {
        __IOM uint32_t EAEIS2;          /*!< (@ 0x00000520) Ethernet Agent Error Interrupt Status Register
                                         *                  2 (EAEIS2)                                                 */

        struct
        {
            __IOM uint32_t DQOES0  : 1; /*!< [0..0] DQOES0                                                             */
            __IOM uint32_t DQOES1  : 1; /*!< [1..1] DQOES1                                                             */
            __IOM uint32_t DQOES2  : 1; /*!< [2..2] DQOES2                                                             */
            __IOM uint32_t DQOES3  : 1; /*!< [3..3] DQOES3                                                             */
            __IOM uint32_t DQOES4  : 1; /*!< [4..4] DQOES4                                                             */
            __IOM uint32_t DQOES5  : 1; /*!< [5..5] DQOES5                                                             */
            __IOM uint32_t DQOES6  : 1; /*!< [6..6] DQOES6                                                             */
            __IOM uint32_t DQOES7  : 1; /*!< [7..7] DQOES7                                                             */
            __IOM uint32_t CTDQOES : 1; /*!< [8..8] CTDQOES                                                            */
            uint32_t               : 7;
            __IOM uint32_t DQSES0  : 1; /*!< [16..16] DQSES0                                                           */
            __IOM uint32_t DQSES1  : 1; /*!< [17..17] DQSES1                                                           */
            __IOM uint32_t DQSES2  : 1; /*!< [18..18] DQSES2                                                           */
            __IOM uint32_t DQSES3  : 1; /*!< [19..19] DQSES3                                                           */
            __IOM uint32_t DQSES4  : 1; /*!< [20..20] DQSES4                                                           */
            __IOM uint32_t DQSES5  : 1; /*!< [21..21] DQSES5                                                           */
            __IOM uint32_t DQSES6  : 1; /*!< [22..22] DQSES6                                                           */
            __IOM uint32_t DQSES7  : 1; /*!< [23..23] DQSES7                                                           */
            uint32_t               : 8;
        } EAEIS2_b;
    };

    union
    {
        __IOM uint32_t EAEIE2;          /*!< (@ 0x00000524) Ethernet Agent Error Interrupt Enable Register
                                         *                  2 (EAEIE2)                                                 */

        struct
        {
            __IOM uint32_t DQOEE0  : 1; /*!< [0..0] DQOEE0                                                             */
            __IOM uint32_t DQOEE1  : 1; /*!< [1..1] DQOEE1                                                             */
            __IOM uint32_t DQOEE2  : 1; /*!< [2..2] DQOEE2                                                             */
            __IOM uint32_t DQOEE3  : 1; /*!< [3..3] DQOEE3                                                             */
            __IOM uint32_t DQOEE4  : 1; /*!< [4..4] DQOEE4                                                             */
            __IOM uint32_t DQOEE5  : 1; /*!< [5..5] DQOEE5                                                             */
            __IOM uint32_t DQOEE6  : 1; /*!< [6..6] DQOEE6                                                             */
            __IOM uint32_t DQOEE7  : 1; /*!< [7..7] DQOEE7                                                             */
            __IOM uint32_t CTDQOEE : 1; /*!< [8..8] CTDQOEE                                                            */
            uint32_t               : 7;
            __IOM uint32_t DQSEE0  : 1; /*!< [16..16] DQSEE0                                                           */
            __IOM uint32_t DQSEE1  : 1; /*!< [17..17] DQSEE1                                                           */
            __IOM uint32_t DQSEE2  : 1; /*!< [18..18] DQSEE2                                                           */
            __IOM uint32_t DQSEE3  : 1; /*!< [19..19] DQSEE3                                                           */
            __IOM uint32_t DQSEE4  : 1; /*!< [20..20] DQSEE4                                                           */
            __IOM uint32_t DQSEE5  : 1; /*!< [21..21] DQSEE5                                                           */
            __IOM uint32_t DQSEE6  : 1; /*!< [22..22] DQSEE6                                                           */
            __IOM uint32_t DQSEE7  : 1; /*!< [23..23] DQSEE7                                                           */
            uint32_t               : 8;
        } EAEIE2_b;
    };

    union
    {
        __IOM uint32_t EAEID2;          /*!< (@ 0x00000528) Ethernet Agent Error Interrupt Disable Register
                                         *                  2 (EAEID2)                                                 */

        struct
        {
            __IOM uint32_t DQOED0  : 1; /*!< [0..0] DQOED0                                                             */
            __IOM uint32_t DQOED1  : 1; /*!< [1..1] DQOED1                                                             */
            __IOM uint32_t DQOED2  : 1; /*!< [2..2] DQOED2                                                             */
            __IOM uint32_t DQOED3  : 1; /*!< [3..3] DQOED3                                                             */
            __IOM uint32_t DQOED4  : 1; /*!< [4..4] DQOED4                                                             */
            __IOM uint32_t DQOED5  : 1; /*!< [5..5] DQOED5                                                             */
            __IOM uint32_t DQOED6  : 1; /*!< [6..6] DQOED6                                                             */
            __IOM uint32_t DQOED7  : 1; /*!< [7..7] DQOED7                                                             */
            __IOM uint32_t CTDQOED : 1; /*!< [8..8] CTDQOED                                                            */
            uint32_t               : 7;
            __IOM uint32_t DQSED0  : 1; /*!< [16..16] DQSED0                                                           */
            __IOM uint32_t DQSED1  : 1; /*!< [17..17] DQSED1                                                           */
            __IOM uint32_t DQSED2  : 1; /*!< [18..18] DQSED2                                                           */
            __IOM uint32_t DQSED3  : 1; /*!< [19..19] DQSED3                                                           */
            __IOM uint32_t DQSED4  : 1; /*!< [20..20] DQSED4                                                           */
            __IOM uint32_t DQSED5  : 1; /*!< [21..21] DQSED5                                                           */
            __IOM uint32_t DQSED6  : 1; /*!< [22..22] DQSED6                                                           */
            __IOM uint32_t DQSED7  : 1; /*!< [23..23] DQSED7                                                           */
            uint32_t               : 8;
        } EAEID2_b;
    };
    __IM uint32_t RESERVED18[21];

    union
    {
        __IOM uint32_t EASCR;          /*!< (@ 0x00000580) Ethernet Agent Security Configuration Register
                                        *                  (EASCR)                                                    */

        struct
        {
            __IOM uint32_t MRSL   : 1; /*!< [0..0] MRSL                                                               */
            __IOM uint32_t TRSL   : 1; /*!< [1..1] TRSL                                                               */
            __IOM uint32_t MCRSL  : 1; /*!< [2..2] MCRSL                                                              */
            __IOM uint32_t TGRSL  : 1; /*!< [3..3] TGRSL                                                              */
            __IOM uint32_t TASRSL : 1; /*!< [4..4] TASRSL                                                             */
            __IOM uint32_t EIRSL  : 1; /*!< [5..5] EIRSL                                                              */
            __IOM uint32_t CRSL   : 1; /*!< [6..6] CRSL                                                               */
            uint32_t              : 9;
            __IOM uint32_t DQRSL0 : 1; /*!< [16..16] DQRSL0                                                           */
            __IOM uint32_t DQRSL1 : 1; /*!< [17..17] DQRSL1                                                           */
            __IOM uint32_t DQRSL2 : 1; /*!< [18..18] DQRSL2                                                           */
            __IOM uint32_t DQRSL3 : 1; /*!< [19..19] DQRSL3                                                           */
            __IOM uint32_t DQRSL4 : 1; /*!< [20..20] DQRSL4                                                           */
            __IOM uint32_t DQRSL5 : 1; /*!< [21..21] DQRSL5                                                           */
            __IOM uint32_t DQRSL6 : 1; /*!< [22..22] DQRSL6                                                           */
            __IOM uint32_t DQRSL7 : 1; /*!< [23..23] DQRSL7                                                           */
            uint32_t              : 8;
        } EASCR_b;
    };
} R_ETHA0_Type;                        /*!< Size = 1412 (0x584)                                                       */

/** @} */ /* End of group Device_Peripheral_peripheralAddr */

#endif                                 /* R_ETHA_REG_H */
