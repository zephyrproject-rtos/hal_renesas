/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_BUS_REG_H
#define R_BUS_REG_H

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief R_BUS_CSa [CSa] (CS Registers)
 */
typedef struct
{
    __IM uint16_t RESERVED;

    union
    {
        __IOM uint16_t MOD;            /*!< (@ 0x00000002) Mode Register                                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t PRMOD : 1;  /*!< [15..15] Page Read Access Mode Select                                     */
            uint16_t             : 5;
            __IOM uint16_t PWENB : 1;  /*!< [9..9] Page Write Access Enable                                           */
            __IOM uint16_t PRENB : 1;  /*!< [8..8] Page Read Access Enable                                            */
            uint16_t             : 4;
            __IOM uint16_t EWENB : 1;  /*!< [3..3] External Wait Enable                                               */
            uint16_t             : 2;
            __IOM uint16_t WRMOD : 1;  /*!< [0..0] Write Access Mode Select                                           */
#else
            __IOM uint16_t WRMOD : 1;  /*!< [0..0] Write Access Mode Select                                           */
            uint16_t             : 2;
            __IOM uint16_t EWENB : 1;  /*!< [3..3] External Wait Enable                                               */
            uint16_t             : 4;
            __IOM uint16_t PRENB : 1;  /*!< [8..8] Page Read Access Enable                                            */
            __IOM uint16_t PWENB : 1;  /*!< [9..9] Page Write Access Enable                                           */
            uint16_t             : 5;
            __IOM uint16_t PRMOD : 1;  /*!< [15..15] Page Read Access Mode Select                                     */
#endif
        } MOD_b;
    };

    union
    {
        __IOM uint32_t WCR1;           /*!< (@ 0x00000004) Wait Control Register 1                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 3;
            __IOM uint32_t CSRWAIT  : 5; /*!< [28..24] Normal Read Cycle Wait Select                                    */
            uint32_t                : 3;
            __IOM uint32_t CSWWAIT  : 5; /*!< [20..16] Normal Write Cycle Wait Select                                   */
            uint32_t                : 5;
            __IOM uint32_t CSPRWAIT : 3; /*!< [10..8] Page Read Cycle Wait Select                                       */
            uint32_t                : 5;
            __IOM uint32_t CSPWWAIT : 3; /*!< [2..0] Page Write Cycle Wait Select                                       */
#else
            __IOM uint32_t CSPWWAIT : 3; /*!< [2..0] Page Write Cycle Wait Select                                       */
            uint32_t                : 5;
            __IOM uint32_t CSPRWAIT : 3; /*!< [10..8] Page Read Cycle Wait Select                                       */
            uint32_t                : 5;
            __IOM uint32_t CSWWAIT  : 5; /*!< [20..16] Normal Write Cycle Wait Select                                   */
            uint32_t                : 3;
            __IOM uint32_t CSRWAIT  : 5; /*!< [28..24] Normal Read Cycle Wait Select                                    */
            uint32_t                : 3;
#endif
        } WCR1_b;
    };

    union
    {
        __IOM uint32_t WCR2;           /*!< (@ 0x00000008) Wait Control Register 2                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 1;
            __IOM uint32_t CSON   : 3; /*!< [30..28] CS Assert Wait Select                                            */
            uint32_t              : 1;
            __IOM uint32_t WDON   : 3; /*!< [26..24] Write Data Output Wait Select                                    */
            uint32_t              : 1;
            __IOM uint32_t WRON   : 3; /*!< [22..20] WR Assert Wait Select                                            */
            uint32_t              : 1;
            __IOM uint32_t RDON   : 3; /*!< [18..16] RD Assert Wait Select                                            */
            uint32_t              : 2;
            __IOM uint32_t AWAIT  : 2; /*!< [13..12] Address Cycle Wait Select                                        */
            uint32_t              : 1;
            __IOM uint32_t WDOFF  : 3; /*!< [10..8] Write Data Output Extension Cycle Select                          */
            uint32_t              : 1;
            __IOM uint32_t CSWOFF : 3; /*!< [6..4] Write-Access CS Extension Cycle Select                             */
            uint32_t              : 1;
            __IOM uint32_t CSROFF : 3; /*!< [2..0] Read-Access CS Extension Cycle Select                              */
#else
            __IOM uint32_t CSROFF : 3; /*!< [2..0] Read-Access CS Extension Cycle Select                              */
            uint32_t              : 1;
            __IOM uint32_t CSWOFF : 3; /*!< [6..4] Write-Access CS Extension Cycle Select                             */
            uint32_t              : 1;
            __IOM uint32_t WDOFF  : 3; /*!< [10..8] Write Data Output Extension Cycle Select                          */
            uint32_t              : 1;
            __IOM uint32_t AWAIT  : 2; /*!< [13..12] Address Cycle Wait Select                                        */
            uint32_t              : 2;
            __IOM uint32_t RDON   : 3; /*!< [18..16] RD Assert Wait Select                                            */
            uint32_t              : 1;
            __IOM uint32_t WRON   : 3; /*!< [22..20] WR Assert Wait Select                                            */
            uint32_t              : 1;
            __IOM uint32_t WDON   : 3; /*!< [26..24] Write Data Output Wait Select                                    */
            uint32_t              : 1;
            __IOM uint32_t CSON   : 3; /*!< [30..28] CS Assert Wait Select                                            */
            uint32_t              : 1;
#endif
        } WCR2_b;
    };
    __IM uint32_t RESERVED1;
} R_BUS_CSa_Type;                      /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_BUS_CSb [CSb] (CS Registers)
 */
typedef struct
{
    __IM uint16_t RESERVED;

    union
    {
        __IOM uint16_t CR;             /*!< (@ 0x00000002) Control Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t             : 3;
            __IOM uint16_t MPXEN : 1;  /*!< [12..12] Address/Data Multiplexed I/O Interface Select                    */
            uint16_t             : 3;
            __IOM uint16_t EMODE : 1;  /*!< [8..8] Endian Mode                                                        */
            uint16_t             : 2;
            __IOM uint16_t BSIZE : 2;  /*!< [5..4] External Bus Width Select                                          */
            uint16_t             : 3;
            __IOM uint16_t EXENB : 1;  /*!< [0..0] Operation Enable                                                   */
#else
            __IOM uint16_t EXENB : 1;  /*!< [0..0] Operation Enable                                                   */
            uint16_t             : 3;
            __IOM uint16_t BSIZE : 2;  /*!< [5..4] External Bus Width Select                                          */
            uint16_t             : 2;
            __IOM uint16_t EMODE : 1;  /*!< [8..8] Endian Mode                                                        */
            uint16_t             : 3;
            __IOM uint16_t MPXEN : 1;  /*!< [12..12] Address/Data Multiplexed I/O Interface Select                    */
            uint16_t             : 3;
#endif
        } CR_b;
    };
    __IM uint16_t RESERVED1[3];

    union
    {
        __IOM uint16_t REC;            /*!< (@ 0x0000000A) Recovery Cycle Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t            : 4;
            __IOM uint16_t WRCV : 4;   /*!< [11..8] Write Recovery                                                    */
            uint16_t            : 4;
            __IOM uint16_t RRCV : 4;   /*!< [3..0] Read Recovery                                                      */
#else
            __IOM uint16_t RRCV : 4;   /*!< [3..0] Read Recovery                                                      */
            uint16_t            : 4;
            __IOM uint16_t WRCV : 4;   /*!< [11..8] Write Recovery                                                    */
            uint16_t            : 4;
#endif
        } REC_b;
    };
    __IM uint16_t RESERVED2[2];
} R_BUS_CSb_Type;                      /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_BUS_SDRAM [SDRAM] (SDRAM Controller)
 */
typedef struct
{
    union
    {
        __IOM uint8_t SDCCR;           /*!< (@ 0x00000000) SDC Control Register                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 2;
            __IOM uint8_t BSIZE : 2;   /*!< [5..4] SDRAM Bus Width Select                                             */
            uint8_t             : 3;
            __IOM uint8_t EXENB : 1;   /*!< [0..0] Operation Enable                                                   */
#else
            __IOM uint8_t EXENB : 1;   /*!< [0..0] Operation Enable                                                   */
            uint8_t             : 3;
            __IOM uint8_t BSIZE : 2;   /*!< [5..4] SDRAM Bus Width Select                                             */
            uint8_t             : 2;
#endif
        } SDCCR_b;
    };

    union
    {
        __IOM uint8_t SDCMOD;          /*!< (@ 0x00000001) SDC Mode Register                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t EMODE : 1;   /*!< [0..0] Endian Mode                                                        */
#else
            __IOM uint8_t EMODE : 1;   /*!< [0..0] Endian Mode                                                        */
            uint8_t             : 7;
#endif
        } SDCMOD_b;
    };

    union
    {
        __IOM uint8_t SDAMOD;          /*!< (@ 0x00000002) SDRAM Access Mode Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t          : 7;
            __IOM uint8_t BE : 1;      /*!< [0..0] Continuous Access Enable                                           */
#else
            __IOM uint8_t BE : 1;      /*!< [0..0] Continuous Access Enable                                           */
            uint8_t          : 7;
#endif
        } SDAMOD_b;
    };
    __IM uint8_t  RESERVED;
    __IM uint32_t RESERVED1[3];

    union
    {
        __IOM uint8_t SDSELF;          /*!< (@ 0x00000010) SDRAM Self-Refresh Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t SFEN : 1;    /*!< [0..0] SDRAM Self-Refresh Enable                                          */
#else
            __IOM uint8_t SFEN : 1;    /*!< [0..0] SDRAM Self-Refresh Enable                                          */
            uint8_t            : 7;
#endif
        } SDSELF_b;
    };
    __IM uint8_t  RESERVED2;
    __IM uint16_t RESERVED3;

    union
    {
        __IOM uint16_t SDRFCR;         /*!< (@ 0x00000014) SDRAM Refresh Control Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t REFW : 4;   /*!< [15..12] Auto-Refresh Cycle/ Self-Refresh Clearing Cycle Count
                                        *   Setting                                                                   */
            __IOM uint16_t RFC : 12;   /*!< [11..0] Auto-Refresh Request Interval Setting                             */
#else
            __IOM uint16_t RFC  : 12;  /*!< [11..0] Auto-Refresh Request Interval Setting                             */
            __IOM uint16_t REFW : 4;   /*!< [15..12] Auto-Refresh Cycle/ Self-Refresh Clearing Cycle Count
                                        *   Setting                                                                   */
#endif
        } SDRFCR_b;
    };

    union
    {
        __IOM uint8_t SDRFEN;          /*!< (@ 0x00000016) SDRAM Auto-Refresh Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t RFEN : 1;    /*!< [0..0] Auto-Refresh Operation Enable                                      */
#else
            __IOM uint8_t RFEN : 1;    /*!< [0..0] Auto-Refresh Operation Enable                                      */
            uint8_t            : 7;
#endif
        } SDRFEN_b;
    };
    __IM uint8_t  RESERVED4;
    __IM uint32_t RESERVED5[2];

    union
    {
        __IOM uint8_t SDICR;           /*!< (@ 0x00000020) SDRAM Initialization Sequence Control Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t INIRQ : 1;   /*!< [0..0] Initialization Sequence Start                                      */
#else
            __IOM uint8_t INIRQ : 1;   /*!< [0..0] Initialization Sequence Start                                      */
            uint8_t             : 7;
#endif
        } SDICR_b;
    };
    __IM uint8_t  RESERVED6;
    __IM uint16_t RESERVED7;

    union
    {
        __IOM uint16_t SDIR;           /*!< (@ 0x00000024) SDRAM Initialization Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t            : 5;
            __IOM uint16_t PRC  : 3;   /*!< [10..8] Initialization Precharge Cycle Count                              */
            __IOM uint16_t ARFC : 4;   /*!< [7..4] Initialization Auto-Refresh Count                                  */
            __IOM uint16_t ARFI : 4;   /*!< [3..0] Initialization Auto-Refresh Interval                               */
#else
            __IOM uint16_t ARFI : 4;   /*!< [3..0] Initialization Auto-Refresh Interval                               */
            __IOM uint16_t ARFC : 4;   /*!< [7..4] Initialization Auto-Refresh Count                                  */
            __IOM uint16_t PRC  : 3;   /*!< [10..8] Initialization Precharge Cycle Count                              */
            uint16_t            : 5;
#endif
        } SDIR_b;
    };
    __IM uint16_t RESERVED8;
    __IM uint32_t RESERVED9[6];

    union
    {
        __IOM uint8_t SDADR;           /*!< (@ 0x00000040) SDRAM Address Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 6;
            __IOM uint8_t MXC : 2;     /*!< [1..0] Address Multiplex Select                                           */
#else
            __IOM uint8_t MXC : 2;     /*!< [1..0] Address Multiplex Select                                           */
            uint8_t           : 6;
#endif
        } SDADR_b;
    };
    __IM uint8_t  RESERVED10;
    __IM uint16_t RESERVED11;

    union
    {
        __IOM uint32_t SDTR;           /*!< (@ 0x00000044) SDRAM Timing Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 13;
            __IOM uint32_t RAI : 3;    /*!< [18..16] Row Active Interval                                              */
            uint32_t           : 2;
            __IOM uint32_t RCD : 2;    /*!< [13..12] Row Column Latency                                               */
            __IOM uint32_t RP  : 3;    /*!< [11..9] Row Precharge Interval                                            */
            __IOM uint32_t WR  : 1;    /*!< [8..8] Write Recovery Interval                                            */
            uint32_t           : 5;
            __IOM uint32_t CL  : 3;    /*!< [2..0] SDRAMC Column Latency                                              */
#else
            __IOM uint32_t CL  : 3;    /*!< [2..0] SDRAMC Column Latency                                              */
            uint32_t           : 5;
            __IOM uint32_t WR  : 1;    /*!< [8..8] Write Recovery Interval                                            */
            __IOM uint32_t RP  : 3;    /*!< [11..9] Row Precharge Interval                                            */
            __IOM uint32_t RCD : 2;    /*!< [13..12] Row Column Latency                                               */
            uint32_t           : 2;
            __IOM uint32_t RAI : 3;    /*!< [18..16] Row Active Interval                                              */
            uint32_t           : 13;
#endif
        } SDTR_b;
    };

    union
    {
        __IOM uint16_t SDMOD;          /*!< (@ 0x00000048) SDRAM Mode Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t          : 1;
            __IOM uint16_t MR : 15;    /*!< [14..0] Mode Register Setting                                             */
#else
            __IOM uint16_t MR : 15;    /*!< [14..0] Mode Register Setting                                             */
            uint16_t          : 1;
#endif
        } SDMOD_b;
    };
    __IM uint16_t RESERVED12;
    __IM uint32_t RESERVED13;

    union
    {
        __IM uint8_t SDSR;             /*!< (@ 0x00000050) SDRAM Status Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 3;
            __IM uint8_t SRFST : 1;    /*!< [4..4] Self-Refresh Transition/Recovery Status                            */
            __IM uint8_t INIST : 1;    /*!< [3..3] Initialization Status                                              */
            uint8_t            : 2;
            __IM uint8_t MRSST : 1;    /*!< [0..0] Mode Register Setting Status                                       */
#else
            __IM uint8_t MRSST : 1;    /*!< [0..0] Mode Register Setting Status                                       */
            uint8_t            : 2;
            __IM uint8_t INIST : 1;    /*!< [3..3] Initialization Status                                              */
            __IM uint8_t SRFST : 1;    /*!< [4..4] Self-Refresh Transition/Recovery Status                            */
            uint8_t            : 3;
#endif
        } SDSR_b;
    };
    __IM uint8_t  RESERVED14;
    __IM uint16_t RESERVED15;
} R_BUS_SDRAM_Type;                    /*!< Size = 84 (0x54)                                                          */

/**
 * @brief R_BUS_BUSERRb [BUSERRb] (Bus Error Registers)
 */
typedef struct
{
    union
    {
        __IM uint8_t STAT;             /*!< (@ 0x00000000) Bus Error Status Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 2;
            __IM uint8_t MSERRSTAT : 1; /*!< [5..5] Master Security Attribution Unit Error Status                      */
            __IM uint8_t ILERRSTAT : 1; /*!< [4..4] Illegal Address Access Error Status                                */
            __IM uint8_t MMERRSTAT : 1; /*!< [3..3] Bus Master MPU Error Status                                        */
            uint8_t                : 2;
            __IM uint8_t SLERRSTAT : 1; /*!< [0..0] Slave Bus Error Status                                             */
#else
            __IM uint8_t SLERRSTAT : 1; /*!< [0..0] Slave Bus Error Status                                             */
            uint8_t                : 2;
            __IM uint8_t MMERRSTAT : 1; /*!< [3..3] Bus Master MPU Error Status                                        */
            __IM uint8_t ILERRSTAT : 1; /*!< [4..4] Illegal Address Access Error Status                                */
            __IM uint8_t MSERRSTAT : 1; /*!< [5..5] Master Security Attribution Unit Error Status                      */
            uint8_t                : 2;
#endif
        } STAT_b;
    };
    __IM uint8_t RESERVED[3];

    union
    {
        __IOM uint8_t CLR;             /*!< (@ 0x00000004) Bus Error Clear Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 2;
            __IOM uint8_t MSERRCLR : 1; /*!< [5..5] Master Security Attribution Unit Error Clear                       */
            __IOM uint8_t ILERRCLR : 1; /*!< [4..4] Illegal Address Access Error Clear                                 */
            __IOM uint8_t MMERRCLR : 1; /*!< [3..3] Bus Master MPU Error Clear                                         */
            uint8_t                : 2;
            __IOM uint8_t SLERRCLR : 1; /*!< [0..0] Slave Bus Error Clear                                              */
#else
            __IOM uint8_t SLERRCLR : 1; /*!< [0..0] Slave Bus Error Clear                                              */
            uint8_t                : 2;
            __IOM uint8_t MMERRCLR : 1; /*!< [3..3] Bus Master MPU Error Clear                                         */
            __IOM uint8_t ILERRCLR : 1; /*!< [4..4] Illegal Address Access Error Clear                                 */
            __IOM uint8_t MSERRCLR : 1; /*!< [5..5] Master Security Attribution Unit Error Clear                       */
            uint8_t                : 2;
#endif
        } CLR_b;
    };
    __IM uint8_t RESERVED1[3];

    union
    {
        __IOM uint8_t INTEN;           /*!< (@ 0x00000008) Bus Error Interrupt Enable Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t          : 7;
            __IOM uint8_t EN : 1;      /*!< [0..0] Bus Error Interrupt Request Enable                                 */
#else
            __IOM uint8_t EN : 1;      /*!< [0..0] Bus Error Interrupt Request Enable                                 */
            uint8_t          : 7;
#endif
        } INTEN_b;
    };
    __IM uint8_t RESERVED2[7];
} R_BUS_BUSERRb_Type;                  /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_BUS_BUSSABT0 [BUSSABT0] (Bus Slave Arbitration Control 0 Registers)
 */
typedef struct
{
    __IM uint32_t RESERVED[4];

    union
    {
        __IOM uint32_t MRE0BI;         /*!< (@ 0x00000010) Bus Slave Arbitration Control Register 0 MRE0              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } MRE0BI_b;
    };
    __IM uint32_t RESERVED1[3];

    union
    {
        __IOM uint32_t S0BI;           /*!< (@ 0x00000020) Bus Slave Arbitration Control Register 0 S0BI              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } S0BI_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t S1BI;           /*!< (@ 0x00000028) Bus Slave Arbitration Control Register 0 S1BI              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } S1BI_b;
    };
    __IM uint32_t RESERVED3[9];

    union
    {
        __IOM uint32_t ECBI;           /*!< (@ 0x00000050) Bus Slave Arbitration Control Register 0 ECBI              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } ECBI_b;
    };
    __IM uint32_t RESERVED4;

    union
    {
        __IOM uint32_t XSPI0BI;        /*!< (@ 0x00000058) Bus Slave Arbitration Control Register 0 XSPI0             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } XSPI0BI_b;
    };
    __IM uint32_t RESERVED5;

    union
    {
        __IOM uint32_t XSPI1BI;        /*!< (@ 0x00000060) Bus Slave Arbitration Control Register 0 XSPI1             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } XSPI1BI_b;
    };
    __IM uint32_t RESERVED6[5];

    union
    {
        __IOM uint32_t PBBI;           /*!< (@ 0x00000078) Bus Slave Arbitration Control Register 0 PBBI              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } PBBI_b;
    };
    __IM uint32_t RESERVED7;

    union
    {
        __IOM uint32_t PABI;           /*!< (@ 0x00000080) Bus Slave Arbitration Control Register 0 PABI              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } PABI_b;
    };
    __IM uint32_t RESERVED8;

    union
    {
        __IOM uint32_t PIBI;           /*!< (@ 0x00000088) Bus Slave Arbitration Control Register 0 PIBI              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } PIBI_b;
    };
    __IM uint32_t RESERVED9;

    union
    {
        __IOM uint32_t PSBI;           /*!< (@ 0x00000090) Bus Slave Arbitration Control Register 0 PSBI              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } PSBI_b;
    };
    __IM uint32_t RESERVED10;

    union
    {
        __IOM uint32_t PS0BI;          /*!< (@ 0x00000098) Bus Slave Arbitration Control Register 0 PS0BI             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 31;
#endif
        } PS0BI_b;
    };
} R_BUS_BUSSABT0_Type;                 /*!< Size = 156 (0x9c)                                                         */

/**
 * @brief R_BUS_MBWERR [MBWERR] (Master Bufferable Write Error Registers)
 */
typedef struct
{
    union
    {
        __IM uint32_t STAT;            /*!< (@ 0x00000000) Master Bufferable Write Error Status Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 12;
            __IM uint32_t MBWERR19 : 1; /*!< [19..19] Master Bufferable Write Error 19 Flag                            */
            __IM uint32_t MBWERR18 : 1; /*!< [18..18] Master Bufferable Write Error 18 Flag                            */
            __IM uint32_t MBWERR17 : 1; /*!< [17..17] Master Bufferable Write Error 17 Flag                            */
            __IM uint32_t MBWERR16 : 1; /*!< [16..16] Master Bufferable Write Error 16 Flag                            */
            uint32_t               : 7;
            __IM uint32_t MBWERR8  : 1; /*!< [8..8] Master Bufferable Write Error 8 Flag                               */
            uint32_t               : 7;
            __IM uint32_t MBWERR0  : 1; /*!< [0..0] Master Bufferable Write Error 0 Flag                               */
#else
            __IM uint32_t MBWERR0  : 1; /*!< [0..0] Master Bufferable Write Error 0 Flag                               */
            uint32_t               : 7;
            __IM uint32_t MBWERR8  : 1; /*!< [8..8] Master Bufferable Write Error 8 Flag                               */
            uint32_t               : 7;
            __IM uint32_t MBWERR16 : 1; /*!< [16..16] Master Bufferable Write Error 16 Flag                            */
            __IM uint32_t MBWERR17 : 1; /*!< [17..17] Master Bufferable Write Error 17 Flag                            */
            __IM uint32_t MBWERR18 : 1; /*!< [18..18] Master Bufferable Write Error 18 Flag                            */
            __IM uint32_t MBWERR19 : 1; /*!< [19..19] Master Bufferable Write Error 19 Flag                            */
            uint32_t               : 12;
#endif
        } STAT_b;
    };
    __IM uint32_t RESERVED;

    union
    {
        __IOM uint32_t CLR;            /*!< (@ 0x00000008) Master Bufferable Write Error Clear Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 12;
            __IOM uint32_t MBWECLR19 : 1; /*!< [19..19] Master Bufferable Write Error 19 Flag Clear                      */
            __IOM uint32_t MBWECLR18 : 1; /*!< [18..18] Master Bufferable Write Error 18 Flag Clear                      */
            __IOM uint32_t MBWECLR17 : 1; /*!< [17..17] Master Bufferable Write Error 17 Flag Clear                      */
            __IOM uint32_t MBWECLR16 : 1; /*!< [16..16] Master Bufferable Write Error 16 Flag Clear                      */
            uint32_t                 : 7;
            __IOM uint32_t MBWECLR8  : 1; /*!< [8..8] Master Bufferable Write Error 8 Flag Clear                         */
            uint32_t                 : 7;
            __IOM uint32_t MBWECLR0  : 1; /*!< [0..0] Master Bufferable Write Error 0 Flag Clear                         */
#else
            __IOM uint32_t MBWECLR0  : 1; /*!< [0..0] Master Bufferable Write Error 0 Flag Clear                         */
            uint32_t                 : 7;
            __IOM uint32_t MBWECLR8  : 1; /*!< [8..8] Master Bufferable Write Error 8 Flag Clear                         */
            uint32_t                 : 7;
            __IOM uint32_t MBWECLR16 : 1; /*!< [16..16] Master Bufferable Write Error 16 Flag Clear                      */
            __IOM uint32_t MBWECLR17 : 1; /*!< [17..17] Master Bufferable Write Error 17 Flag Clear                      */
            __IOM uint32_t MBWECLR18 : 1; /*!< [18..18] Master Bufferable Write Error 18 Flag Clear                      */
            __IOM uint32_t MBWECLR19 : 1; /*!< [19..19] Master Bufferable Write Error 19 Flag Clear                      */
            uint32_t                 : 12;
#endif
        } CLR_b;
    };
} R_BUS_MBWERR_Type;                   /*!< Size = 12 (0xc)                                                           */

/**
 * @brief R_BUS_OAD [OAD] (Bus Operation After Detection Registers)
 */
typedef struct
{
    union
    {
        __IOM uint16_t BUSOAD;         /*!< (@ 0x00000000) Bus Operation after Detection Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t                : 13;
            __IOM uint16_t BWERROAD : 1; /*!< [2..2] Bufferable Write Error Operation After Detection                   */
            __IOM uint16_t SLERROAD : 1; /*!< [1..1] Slave Bus Error Operation After Detection                          */
            __IOM uint16_t ILERROAD : 1; /*!< [0..0] Illegal Address Access Error Operation After Detection             */
#else
            __IOM uint16_t ILERROAD : 1; /*!< [0..0] Illegal Address Access Error Operation After Detection             */
            __IOM uint16_t SLERROAD : 1; /*!< [1..1] Slave Bus Error Operation After Detection                          */
            __IOM uint16_t BWERROAD : 1; /*!< [2..2] Bufferable Write Error Operation After Detection                   */
            uint16_t                : 13;
#endif
        } BUSOAD_b;
    };
    __IM uint16_t RESERVED;

    union
    {
        __IOM uint16_t BUSOADPT;       /*!< (@ 0x00000004) Bus Operation after Detection Protect Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint16_t KEY      : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 7;
            __IOM uint16_t PROTECT : 1; /*!< [0..0] Protection of Register                                             */
#else
            __IOM uint16_t PROTECT : 1; /*!< [0..0] Protection of Register                                             */
            uint16_t               : 7;
            __OM uint16_t KEY      : 8; /*!< [15..8] Key Code                                                          */
#endif
        } BUSOADPT_b;
    };
    __IM uint16_t RESERVED1[5];

    union
    {
        __IOM uint16_t MSAOAD;         /*!< (@ 0x00000010) Master Security Attribution Operation-After-Detection
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint16_t KEY  : 8;    /*!< [15..8] Key code                                                          */
            uint16_t           : 7;
            __IOM uint16_t OAD : 1;    /*!< [0..0] Operation after access violation detection                         */
#else
            __IOM uint16_t OAD : 1;    /*!< [0..0] Operation after access violation detection                         */
            uint16_t           : 7;
            __OM uint16_t KEY  : 8;    /*!< [15..8] Key code                                                          */
#endif
        } MSAOAD_b;
    };
    __IM uint16_t RESERVED2;

    union
    {
        __IOM uint16_t MSAPT;          /*!< (@ 0x00000014) Master Security Attribution Protect Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint16_t KEY      : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 7;
            __IOM uint16_t PROTECT : 1; /*!< [0..0] Register Write Protection                                          */
#else
            __IOM uint16_t PROTECT : 1; /*!< [0..0] Register Write Protection                                          */
            uint16_t               : 7;
            __OM uint16_t KEY      : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MSAPT_b;
    };
} R_BUS_OAD_Type;                       /*!< Size = 22 (0x16)                                                          */

/**
 * @brief R_BUS_BUSSABT1 [BUSSABT1] (Bus Slave Arbitration Control 1 Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t MRC0BI;         /*!< (@ 0x00000000) Bus Slave Arbitration Control Register 1 MRC0BI            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 30;
            __IOM uint32_t ARBS : 2;   /*!< [1..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 2;   /*!< [1..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 30;
#endif
        } MRC0BI_b;
    };
    __IM uint32_t RESERVED;

    union
    {
        __IOM uint32_t MRC1BI;         /*!< (@ 0x00000008) Bus Slave Arbitration Control Register 1 MRC1BI            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 30;
            __IOM uint32_t ARBS : 2;   /*!< [1..0] Arbitration Select for Each Slave Bus Interface                    */
#else
            __IOM uint32_t ARBS : 2;   /*!< [1..0] Arbitration Select for Each Slave Bus Interface                    */
            uint32_t            : 30;
#endif
        } MRC1BI_b;
    };
} R_BUS_BUSSABT1_Type;                 /*!< Size = 12 (0xc)                                                           */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_BUS                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Buses (R_BUS)
 */

typedef struct                         /*!< (@ 0x8701D000) R_BUS Structure                                            */
{
    __IOM R_BUS_CSa_Type CSa[8];       /*!< (@ 0x00000000) CS Registers                                               */
    __IM uint32_t        RESERVED[480];
    __IOM R_BUS_CSb_Type CSb[8];       /*!< (@ 0x00000800) CS Registers                                               */

    union
    {
        __IOM uint16_t CSRECEN;        /*!< (@ 0x00000880) CS Recovery Cycle Insertion Enable Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t RCVENM7 : 1; /*!< [15..15] Multiplexed Bus Recovery Cycle Insertion Enable 7                */
            __IOM uint16_t RCVENM6 : 1; /*!< [14..14] Multiplexed Bus Recovery Cycle Insertion Enable 6                */
            __IOM uint16_t RCVENM5 : 1; /*!< [13..13] Multiplexed Bus Recovery Cycle Insertion Enable 5                */
            __IOM uint16_t RCVENM4 : 1; /*!< [12..12] Multiplexed Bus Recovery Cycle Insertion Enable 4                */
            __IOM uint16_t RCVENM3 : 1; /*!< [11..11] Multiplexed Bus Recovery Cycle Insertion Enable 3                */
            __IOM uint16_t RCVENM2 : 1; /*!< [10..10] Multiplexed Bus Recovery Cycle Insertion Enable 2                */
            __IOM uint16_t RCVENM1 : 1; /*!< [9..9] Multiplexed Bus Recovery Cycle Insertion Enable 1                  */
            __IOM uint16_t RCVENM0 : 1; /*!< [8..8] Multiplexed Bus Recovery Cycle Insertion Enable 0                  */
            __IOM uint16_t RCVEN7  : 1; /*!< [7..7] Separate Bus Recovery Cycle Insertion Enable 7                     */
            __IOM uint16_t RCVEN6  : 1; /*!< [6..6] Separate Bus Recovery Cycle Insertion Enable 6                     */
            __IOM uint16_t RCVEN5  : 1; /*!< [5..5] Separate Bus Recovery Cycle Insertion Enable 5                     */
            __IOM uint16_t RCVEN4  : 1; /*!< [4..4] Separate Bus Recovery Cycle Insertion Enable 4                     */
            __IOM uint16_t RCVEN3  : 1; /*!< [3..3] Separate Bus Recovery Cycle Insertion Enable 3                     */
            __IOM uint16_t RCVEN2  : 1; /*!< [2..2] Separate Bus Recovery Cycle Insertion Enable 2                     */
            __IOM uint16_t RCVEN1  : 1; /*!< [1..1] Separate Bus Recovery Cycle Insertion Enable 1                     */
            __IOM uint16_t RCVEN0  : 1; /*!< [0..0] Separate Bus Recovery Cycle Insertion Enable 0                     */
#else
            __IOM uint16_t RCVEN0  : 1; /*!< [0..0] Separate Bus Recovery Cycle Insertion Enable 0                     */
            __IOM uint16_t RCVEN1  : 1; /*!< [1..1] Separate Bus Recovery Cycle Insertion Enable 1                     */
            __IOM uint16_t RCVEN2  : 1; /*!< [2..2] Separate Bus Recovery Cycle Insertion Enable 2                     */
            __IOM uint16_t RCVEN3  : 1; /*!< [3..3] Separate Bus Recovery Cycle Insertion Enable 3                     */
            __IOM uint16_t RCVEN4  : 1; /*!< [4..4] Separate Bus Recovery Cycle Insertion Enable 4                     */
            __IOM uint16_t RCVEN5  : 1; /*!< [5..5] Separate Bus Recovery Cycle Insertion Enable 5                     */
            __IOM uint16_t RCVEN6  : 1; /*!< [6..6] Separate Bus Recovery Cycle Insertion Enable 6                     */
            __IOM uint16_t RCVEN7  : 1; /*!< [7..7] Separate Bus Recovery Cycle Insertion Enable 7                     */
            __IOM uint16_t RCVENM0 : 1; /*!< [8..8] Multiplexed Bus Recovery Cycle Insertion Enable 0                  */
            __IOM uint16_t RCVENM1 : 1; /*!< [9..9] Multiplexed Bus Recovery Cycle Insertion Enable 1                  */
            __IOM uint16_t RCVENM2 : 1; /*!< [10..10] Multiplexed Bus Recovery Cycle Insertion Enable 2                */
            __IOM uint16_t RCVENM3 : 1; /*!< [11..11] Multiplexed Bus Recovery Cycle Insertion Enable 3                */
            __IOM uint16_t RCVENM4 : 1; /*!< [12..12] Multiplexed Bus Recovery Cycle Insertion Enable 4                */
            __IOM uint16_t RCVENM5 : 1; /*!< [13..13] Multiplexed Bus Recovery Cycle Insertion Enable 5                */
            __IOM uint16_t RCVENM6 : 1; /*!< [14..14] Multiplexed Bus Recovery Cycle Insertion Enable 6                */
            __IOM uint16_t RCVENM7 : 1; /*!< [15..15] Multiplexed Bus Recovery Cycle Insertion Enable 7                */
#endif
        } CSRECEN_b;
    };
    __IM uint16_t RESERVED1;
    __IM uint32_t RESERVED2[7];

    union
    {
        __IM uint8_t EXBERR;           /*!< (@ 0x000008A0) EXBUS Error Status Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 5;
            __IM uint8_t BCAN  : 1;    /*!< [2..2] Bus Access Cancel Error Status Flag                                */
            __IM uint8_t HLDTO : 1;    /*!< [1..1] External Bus Hold Timeout Error Status Flag                        */
            __IM uint8_t TO    : 1;    /*!< [0..0] External Wait Timeout Error Status Flag                            */
#else
            __IM uint8_t TO    : 1;    /*!< [0..0] External Wait Timeout Error Status Flag                            */
            __IM uint8_t HLDTO : 1;    /*!< [1..1] External Bus Hold Timeout Error Status Flag                        */
            __IM uint8_t BCAN  : 1;    /*!< [2..2] Bus Access Cancel Error Status Flag                                */
            uint8_t            : 5;
#endif
        } EXBERR_b;
    };
    __IM uint8_t  RESERVED3;
    __IM uint16_t RESERVED4;

    union
    {
        __IOM uint8_t EXBEREN;         /*!< (@ 0x000008A4) EXBUS Error Enable Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t TOEN : 1;    /*!< [0..0] External bus Timeout Detection Enable                              */
#else
            __IOM uint8_t TOEN : 1;    /*!< [0..0] External bus Timeout Detection Enable                              */
            uint8_t            : 7;
#endif
        } EXBEREN_b;
    };
    __IM uint8_t  RESERVED5;
    __IM uint16_t RESERVED6;

    union
    {
        __IOM uint8_t EXBECLR;         /*!< (@ 0x000008A8) EXBUS Error Status Clear Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 5;
            __IOM uint8_t BCANCLR  : 1; /*!< [2..2] Bus Access Cancel Error Status Clear                               */
            __IOM uint8_t HLDTOCLR : 1; /*!< [1..1] External Bus Hold Timeout Error Status Clear                       */
            __IOM uint8_t TOCLR    : 1; /*!< [0..0] External Bus Wait Timeout Error Status Clear                       */
#else
            __IOM uint8_t TOCLR    : 1; /*!< [0..0] External Bus Wait Timeout Error Status Clear                       */
            __IOM uint8_t HLDTOCLR : 1; /*!< [1..1] External Bus Hold Timeout Error Status Clear                       */
            __IOM uint8_t BCANCLR  : 1; /*!< [2..2] Bus Access Cancel Error Status Clear                               */
            uint8_t                : 5;
#endif
        } EXBECLR_b;
    };
    __IM uint8_t  RESERVED7;
    __IM uint16_t RESERVED8;

    union
    {
        __IM uint32_t EXBEAD;          /*!< (@ 0x000008AC) EXBUS Error Address Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t EADDR : 13;  /*!< [31..19] EXBUS Error Address                                              */
            uint32_t            : 19;
#else
            uint32_t            : 19;
            __IM uint32_t EADDR : 13;  /*!< [31..19] EXBUS Error Address                                              */
#endif
        } EXBEAD_b;
    };
    __IM uint32_t RESERVED9;

    union
    {
        __IOM uint8_t EXHLDEN;         /*!< (@ 0x000008B4) EXBUS Hold Enable Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t HLDEN : 1;   /*!< [0..0] External Bus Hold Enable                                           */
#else
            __IOM uint8_t HLDEN : 1;   /*!< [0..0] External Bus Hold Enable                                           */
            uint8_t             : 7;
#endif
        } EXHLDEN_b;
    };

    __IM uint8_t           RESERVED10;
    __IM uint16_t          RESERVED11;
    __IM uint32_t          RESERVED12[210];
    __IOM R_BUS_SDRAM_Type SDRAM;      /*!< (@ 0x00000C00) SDRAM Controller                                           */
    __IM uint32_t          RESERVED13[235];
    __IOM R_BUS_OAD_Type   OAD;        /*!< (@ 0x00001000) Bus Operation After Detection Registers                    */
    __IM uint16_t          RESERVED14;
    __IM uint32_t          RESERVED15[58];

    union
    {
        __IOM uint32_t BUSMABTXSPIMBI; /*!< (@ 0x00001100) Bus Master Arbitration Control Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for XSPIMBI                                     */
#else
            __IOM uint32_t ARBS : 1;   /*!< [0..0] Arbitration Select for XSPIMBI                                     */
            uint32_t            : 31;
#endif
        } BUSMABTXSPIMBI_b;
    };
    __IM uint32_t RESERVED16[63];

    union
    {
        __IOM R_BUS_BUSSABT0_Type BUSSABT0; /*!< (@ 0x00001200) Bus Slave Arbitration Control 0 Registers                  */
        __IOM R_BUS_BUSSABT1_Type BUSSABT1; /*!< (@ 0x00001200) Bus Slave Arbitration Control 1 Registers                  */
    };
    __IM uint32_t            RESERVED17[345];
    __IOM R_BUS_BUSERRb_Type BUSERRb[7];    /*!< (@ 0x00001800) Bus Error Registers                                        */
    __IM uint32_t            RESERVED18[164];
    __IOM R_BUS_MBWERR_Type  MBWERR;        /*!< (@ 0x00001B00) Master Bufferable Write Error Registers                    */
} R_BUS_Type;                               /*!< Size = 6924 (0x1b0c)                                                      */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_BUS_REG_H */
