/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ESC_REG_H
#define R_ESC_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_ESC                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief EtherCAT Slave Controller (R_ESC)
 */

typedef struct                         /*!< (@ 0x874A0000) R_ESC Structure                                            */
{
    __IM uint8_t  TYPE;                /*!< (@ 0x00000000) Type Register                                              */
    __IM uint8_t  REVISION;            /*!< (@ 0x00000001) Revision Register                                          */
    __IM uint16_t BUILD;               /*!< (@ 0x00000002) Build Register                                             */
    __IM uint8_t  FMMUNUM;             /*!< (@ 0x00000004) FMMU Supported Channel Number Register                     */
    __IM uint8_t  SMNUM;               /*!< (@ 0x00000005) SyncManager Supported Channel Number Register              */
    __IM uint8_t  RAMSIZE;             /*!< (@ 0x00000006) Process Data RAM Size Register                             */

    union
    {
        __IM uint8_t PORTDESC;         /*!< (@ 0x00000007) Port Descriptor Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t P3 : 2;       /*!< [7..6] Port 3 Configuration                                               */
            __IM uint8_t P2 : 2;       /*!< [5..4] Port 2 Configuration                                               */
            __IM uint8_t P1 : 2;       /*!< [3..2] Port 1 Configuration                                               */
            __IM uint8_t P0 : 2;       /*!< [1..0] Port 0 Configuration                                               */
#else
            __IM uint8_t P0 : 2;       /*!< [1..0] Port 0 Configuration                                               */
            __IM uint8_t P1 : 2;       /*!< [3..2] Port 1 Configuration                                               */
            __IM uint8_t P2 : 2;       /*!< [5..4] Port 2 Configuration                                               */
            __IM uint8_t P3 : 2;       /*!< [7..6] Port 3 Configuration                                               */
#endif
        } PORTDESC_b;
    };

    union
    {
        __IM uint16_t FEATURE;         /*!< (@ 0x00000008) ESC Supported Features Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t                 : 4;
            __IM uint16_t FSCONFIG   : 1; /*!< [11..11] FMMU/SyncManager Configuration                                   */
            __IM uint16_t RWSUPP     : 1; /*!< [10..10] Read/Write Command Support                                       */
            __IM uint16_t LRW        : 1; /*!< [9..9] LRW Command Support                                                */
            __IM uint16_t DCSYNC     : 1; /*!< [8..8] Enhanced DC SYNC Activation                                        */
            __IM uint16_t FCS        : 1; /*!< [7..7] Separate Handling of FCS Errors                                    */
            __IM uint16_t LINKDETMII : 1; /*!< [6..6] Enhanced Link Detection MII                                        */
            uint16_t                 : 2;
            __IM uint16_t DCWID      : 1; /*!< [3..3] Distributed Clock Width                                            */
            __IM uint16_t DC         : 1; /*!< [2..2] Distributed Clock                                                  */
            uint16_t                 : 1;
            __IM uint16_t FMMU       : 1; /*!< [0..0] FMMU Operation                                                     */
#else
            __IM uint16_t FMMU       : 1; /*!< [0..0] FMMU Operation                                                     */
            uint16_t                 : 1;
            __IM uint16_t DC         : 1; /*!< [2..2] Distributed Clock                                                  */
            __IM uint16_t DCWID      : 1; /*!< [3..3] Distributed Clock Width                                            */
            uint16_t                 : 2;
            __IM uint16_t LINKDETMII : 1; /*!< [6..6] Enhanced Link Detection MII                                        */
            __IM uint16_t FCS        : 1; /*!< [7..7] Separate Handling of FCS Errors                                    */
            __IM uint16_t DCSYNC     : 1; /*!< [8..8] Enhanced DC SYNC Activation                                        */
            __IM uint16_t LRW        : 1; /*!< [9..9] LRW Command Support                                                */
            __IM uint16_t RWSUPP     : 1; /*!< [10..10] Read/Write Command Support                                       */
            __IM uint16_t FSCONFIG   : 1; /*!< [11..11] FMMU/SyncManager Configuration                                   */
            uint16_t                 : 4;
#endif
        } FEATURE_b;
    };
    __IM uint16_t  RESERVED;
    __IM uint32_t  RESERVED1;
    __IM uint16_t  STATIONADR;         /*!< (@ 0x00000010) Configured Station Address Register                        */
    __IOM uint16_t STATIONALIAS;       /*!< (@ 0x00000012) Configured Station Alias Register                          */
    __IM uint32_t  RESERVED2[3];

    union
    {
        __IM uint8_t REGWRENABLE;      /*!< (@ 0x00000020) Register Write Enable Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IM uint8_t ENABLE : 1;   /*!< [0..0] Register Write Enable                                              */
#else
            __IM uint8_t ENABLE : 1;   /*!< [0..0] Register Write Enable                                              */
            uint8_t             : 7;
#endif
        } REGWRENABLE_b;
    };

    union
    {
        __IM uint8_t REGWRPROTECT;     /*!< (@ 0x00000021) Register Write Protection Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IM uint8_t PROTECT : 1;  /*!< [0..0] Register Write Protection                                          */
#else
            __IM uint8_t PROTECT : 1;  /*!< [0..0] Register Write Protection                                          */
            uint8_t              : 7;
#endif
        } REGWRPROTECT_b;
    };
    __IM uint16_t RESERVED3;
    __IM uint32_t RESERVED4[3];

    union
    {
        __IM uint8_t ESCWRENABLE;      /*!< (@ 0x00000030) ESC Write Enable Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IM uint8_t ENABLE : 1;   /*!< [0..0] Register/Memory Write Enable                                       */
#else
            __IM uint8_t ENABLE : 1;   /*!< [0..0] Register/Memory Write Enable                                       */
            uint8_t             : 7;
#endif
        } ESCWRENABLE_b;
    };

    union
    {
        __IM uint8_t ESCWRPROTECT;     /*!< (@ 0x00000031) ESC Write Protection Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IM uint8_t PROTECT : 1;  /*!< [0..0] Register/Memory Write Protection                                   */
#else
            __IM uint8_t PROTECT : 1;  /*!< [0..0] Register/Memory Write Protection                                   */
            uint8_t              : 7;
#endif
        } ESCWRPROTECT_b;
    };
    __IM uint16_t RESERVED5;
    __IM uint32_t RESERVED6[3];

    union
    {
        __IM uint8_t ESCRESETECAT;     /*!< (@ 0x00000040) ESC Reset ECAT Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 6;
            __IM uint8_t RESETECAT : 2; /*!< [1..0] Reset Progress Status                                              */
#else
            __IM uint8_t RESETECAT : 2; /*!< [1..0] Reset Progress Status                                              */
            uint8_t                : 6;
#endif
        } ESCRESETECAT_b;
    };

    union
    {
        __IOM uint8_t ESCRESETPDI;     /*!< (@ 0x00000041) ESC Reset PDI Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 6;
            __IOM uint8_t RESETPDI : 2; /*!< [1..0] Reset Progress Status                                              */
#else
            __IOM uint8_t RESETPDI : 2; /*!< [1..0] Reset Progress Status                                              */
            uint8_t                : 6;
#endif
        } ESCRESETPDI_b;
    };
    __IM uint16_t RESERVED7;
    __IM uint32_t RESERVED8[47];

    union
    {
        __IM uint32_t ESCDLCONTROL;    /*!< (@ 0x00000100) ESC DL Control Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 7;
            __IM uint32_t STAALIAS : 1; /*!< [24..24] Station Alias                                                    */
            uint32_t               : 5;
            __IM uint32_t RXFIFO   : 3; /*!< [18..16] Receive FIFO Size                                                */
            __IM uint32_t LP3      : 2; /*!< [15..14] Loop Port 3 Configuration                                        */
            __IM uint32_t LP2      : 2; /*!< [13..12] Loop Port 2 Configuration                                        */
            __IM uint32_t LP1      : 2; /*!< [11..10] Loop Port 1 Configuration                                        */
            __IM uint32_t LP0      : 2; /*!< [9..8] Loop Port 0 Configuration                                          */
            uint32_t               : 6;
            __IM uint32_t TEMPUSE  : 1; /*!< [1..1] Temporary Use of Bits 15 to 8                                      */
            __IM uint32_t FWDRULE  : 1; /*!< [0..0] Forwarding Rule                                                    */
#else
            __IM uint32_t FWDRULE  : 1; /*!< [0..0] Forwarding Rule                                                    */
            __IM uint32_t TEMPUSE  : 1; /*!< [1..1] Temporary Use of Bits 15 to 8                                      */
            uint32_t               : 6;
            __IM uint32_t LP0      : 2; /*!< [9..8] Loop Port 0 Configuration                                          */
            __IM uint32_t LP1      : 2; /*!< [11..10] Loop Port 1 Configuration                                        */
            __IM uint32_t LP2      : 2; /*!< [13..12] Loop Port 2 Configuration                                        */
            __IM uint32_t LP3      : 2; /*!< [15..14] Loop Port 3 Configuration                                        */
            __IM uint32_t RXFIFO   : 3; /*!< [18..16] Receive FIFO Size                                                */
            uint32_t               : 5;
            __IM uint32_t STAALIAS : 1; /*!< [24..24] Station Alias                                                    */
            uint32_t               : 7;
#endif
        } ESCDLCONTROL_b;
    };
    __IM uint32_t RESERVED9;
    __IM uint16_t PHYSICALRWOFST;      /*!< (@ 0x00000108) Physical Read/Write Offset Register                        */
    __IM uint16_t RESERVED10;
    __IM uint32_t RESERVED11;

    union
    {
        __IM uint16_t ESCDLSTATUS;     /*!< (@ 0x00000110) ESC DL Status Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint16_t COMP3    : 1; /*!< [15..15] Port 3 Communication Status Flag                                 */
            __IM uint16_t LP3      : 1; /*!< [14..14] Loop Port 3 Status Flag                                          */
            __IM uint16_t COMP2    : 1; /*!< [13..13] Port 2 Communication Status Flag                                 */
            __IM uint16_t LP2      : 1; /*!< [12..12] Loop Port 2 Status Flag                                          */
            __IM uint16_t COMP1    : 1; /*!< [11..11] Port 1 Communication Status Flag                                 */
            __IM uint16_t LP1      : 1; /*!< [10..10] Loop Port 1 Status Flag                                          */
            __IM uint16_t COMP0    : 1; /*!< [9..9] Port 0 Communication Status Flag                                   */
            __IM uint16_t LP0      : 1; /*!< [8..8] Loop Port 0 Status Flag                                            */
            __IM uint16_t PHYP3    : 1; /*!< [7..7] Port 3 Link Status Flag                                            */
            __IM uint16_t PHYP2    : 1; /*!< [6..6] Port 2 Link Status Flag                                            */
            __IM uint16_t PHYP1    : 1; /*!< [5..5] Port 1 Link Status Flag                                            */
            __IM uint16_t PHYP0    : 1; /*!< [4..4] Port 0 Link Status Flag                                            */
            uint16_t               : 1;
            __IM uint16_t ENHLINKD : 1; /*!< [2..2] Enhanced Link Detection Indication Flag                            */
            __IM uint16_t PDIWDST  : 1; /*!< [1..1] PDI Watchdog Status Flag                                           */
            __IM uint16_t PDIOPE   : 1; /*!< [0..0] PDI Operational/EEPROM Load Status Flag                            */
#else
            __IM uint16_t PDIOPE   : 1; /*!< [0..0] PDI Operational/EEPROM Load Status Flag                            */
            __IM uint16_t PDIWDST  : 1; /*!< [1..1] PDI Watchdog Status Flag                                           */
            __IM uint16_t ENHLINKD : 1; /*!< [2..2] Enhanced Link Detection Indication Flag                            */
            uint16_t               : 1;
            __IM uint16_t PHYP0    : 1; /*!< [4..4] Port 0 Link Status Flag                                            */
            __IM uint16_t PHYP1    : 1; /*!< [5..5] Port 1 Link Status Flag                                            */
            __IM uint16_t PHYP2    : 1; /*!< [6..6] Port 2 Link Status Flag                                            */
            __IM uint16_t PHYP3    : 1; /*!< [7..7] Port 3 Link Status Flag                                            */
            __IM uint16_t LP0      : 1; /*!< [8..8] Loop Port 0 Status Flag                                            */
            __IM uint16_t COMP0    : 1; /*!< [9..9] Port 0 Communication Status Flag                                   */
            __IM uint16_t LP1      : 1; /*!< [10..10] Loop Port 1 Status Flag                                          */
            __IM uint16_t COMP1    : 1; /*!< [11..11] Port 1 Communication Status Flag                                 */
            __IM uint16_t LP2      : 1; /*!< [12..12] Loop Port 2 Status Flag                                          */
            __IM uint16_t COMP2    : 1; /*!< [13..13] Port 2 Communication Status Flag                                 */
            __IM uint16_t LP3      : 1; /*!< [14..14] Loop Port 3 Status Flag                                          */
            __IM uint16_t COMP3    : 1; /*!< [15..15] Port 3 Communication Status Flag                                 */
#endif
        } ESCDLSTATUS_b;
    };
    __IM uint16_t RESERVED12;
    __IM uint32_t RESERVED13[3];

    union
    {
        __IM uint16_t ALCONTROL;       /*!< (@ 0x00000120) AL Control Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t                : 10;
            __IM uint16_t DEVICEID  : 1; /*!< [5..5] Device ID Request                                                  */
            __IM uint16_t ERRINDACK : 1; /*!< [4..4] Error Indication Acknowledge                                       */
            __IM uint16_t INISTATE  : 4; /*!< [3..0] State Machine State Transition Initiation                          */
#else
            __IM uint16_t INISTATE  : 4; /*!< [3..0] State Machine State Transition Initiation                          */
            __IM uint16_t ERRINDACK : 1; /*!< [4..4] Error Indication Acknowledge                                       */
            __IM uint16_t DEVICEID  : 1; /*!< [5..5] Device ID Request                                                  */
            uint16_t                : 10;
#endif
        } ALCONTROL_b;
    };
    __IM uint16_t RESERVED14;
    __IM uint32_t RESERVED15[3];

    union
    {
        __IOM uint16_t ALSTATUS;       /*!< (@ 0x00000130) AL Status Register                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t                : 10;
            __IOM uint16_t DEVICEID : 1; /*!< [5..5] Device ID Load Flag                                                */
            __IOM uint16_t ERR      : 1; /*!< [4..4] Error Flag                                                         */
            __IOM uint16_t ACTSTATE : 4; /*!< [3..0] State Machine Actual State Flag                                    */
#else
            __IOM uint16_t ACTSTATE : 4; /*!< [3..0] State Machine Actual State Flag                                    */
            __IOM uint16_t ERR      : 1; /*!< [4..4] Error Flag                                                         */
            __IOM uint16_t DEVICEID : 1; /*!< [5..5] Device ID Load Flag                                                */
            uint16_t                : 10;
#endif
        } ALSTATUS_b;
    };
    __IM uint16_t  RESERVED16;
    __IOM uint16_t ALSTATUSCODE;       /*!< (@ 0x00000134) AL Status Code Register                                    */
    __IM uint16_t  RESERVED17;

    union
    {
        __IOM uint8_t RUNLEDOVERRIDE;  /*!< (@ 0x00000138) RUN LED Override Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                  : 3;
            __IOM uint8_t OVERRIDEEN : 1; /*!< [4..4] Override Setting                                                   */
            __IOM uint8_t LEDCODE    : 4; /*!< [3..0] LED Code Indication                                                */
#else
            __IOM uint8_t LEDCODE    : 4; /*!< [3..0] LED Code Indication                                                */
            __IOM uint8_t OVERRIDEEN : 1; /*!< [4..4] Override Setting                                                   */
            uint8_t                  : 3;
#endif
        } RUNLEDOVERRIDE_b;
    };

    union
    {
        __IOM uint8_t ERRLEDOVERRIDE;  /*!< (@ 0x00000139) ERR LED Override Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                  : 3;
            __IOM uint8_t OVERRIDEEN : 1; /*!< [4..4] Override Setting                                                   */
            __IOM uint8_t LEDCODE    : 4; /*!< [3..0] LED Code Indication                                                */
#else
            __IOM uint8_t LEDCODE    : 4; /*!< [3..0] LED Code Indication                                                */
            __IOM uint8_t OVERRIDEEN : 1; /*!< [4..4] Override Setting                                                   */
            uint8_t                  : 3;
#endif
        } ERRLEDOVERRIDE_b;
    };
    __IM uint16_t RESERVED18;
    __IM uint32_t RESERVED19;
    __IM uint8_t  PDICONTROL;          /*!< (@ 0x00000140) PDI Control Register                                       */

    union
    {
        __IM uint8_t ESCCONFIG;        /*!< (@ 0x00000141) ESC Configuration Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t ENLP3   : 1;  /*!< [7..7] Port 3 Enhanced Link Detection Setting                             */
            __IM uint8_t ENLP2   : 1;  /*!< [6..6] Port 2 Enhanced Link Detection Setting                             */
            __IM uint8_t ENLP1   : 1;  /*!< [5..5] Port 1 Enhanced Link Detection Setting                             */
            __IM uint8_t ENLP0   : 1;  /*!< [4..4] Port 0 Enhanced Link Detection Setting                             */
            __IM uint8_t DCLATCH : 1;  /*!< [3..3] Latch Input Unit Setting                                           */
            __IM uint8_t DCSYNC  : 1;  /*!< [2..2] SYNC Output Unit State Indication                                  */
            __IM uint8_t ENLALLP : 1;  /*!< [1..1] All Ports Enhanced Link Detection Setting                          */
            __IM uint8_t DEVEMU  : 1;  /*!< [0..0] Device Emulation Setting                                           */
#else
            __IM uint8_t DEVEMU  : 1;  /*!< [0..0] Device Emulation Setting                                           */
            __IM uint8_t ENLALLP : 1;  /*!< [1..1] All Ports Enhanced Link Detection Setting                          */
            __IM uint8_t DCSYNC  : 1;  /*!< [2..2] SYNC Output Unit State Indication                                  */
            __IM uint8_t DCLATCH : 1;  /*!< [3..3] Latch Input Unit Setting                                           */
            __IM uint8_t ENLP0   : 1;  /*!< [4..4] Port 0 Enhanced Link Detection Setting                             */
            __IM uint8_t ENLP1   : 1;  /*!< [5..5] Port 1 Enhanced Link Detection Setting                             */
            __IM uint8_t ENLP2   : 1;  /*!< [6..6] Port 2 Enhanced Link Detection Setting                             */
            __IM uint8_t ENLP3   : 1;  /*!< [7..7] Port 3 Enhanced Link Detection Setting                             */
#endif
        } ESCCONFIG_b;
    };
    __IM uint16_t RESERVED20;
    __IM uint32_t RESERVED21[3];

    union
    {
        __IM uint8_t PDICONFIG;        /*!< (@ 0x00000150) PDI Configuration Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t ONCHIPBUS    : 3; /*!< [7..5] On-Chip Bus Type Indication                                        */
            __IM uint8_t ONCHIPBUSCLK : 5; /*!< [4..0] On-Chip Bus Clock Indication                                       */
#else
            __IM uint8_t ONCHIPBUSCLK : 5; /*!< [4..0] On-Chip Bus Clock Indication                                       */
            __IM uint8_t ONCHIPBUS    : 3; /*!< [7..5] On-Chip Bus Type Indication                                        */
#endif
        } PDICONFIG_b;
    };

    union
    {
        __IM uint8_t SYNCLATCHCONFIG;  /*!< (@ 0x00000151) SYNC/LATCH PDI Configuration Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t SYNC1MAP : 1; /*!< [7..7] SYNC1 State Mapping Indication                                     */
            __IM uint8_t SYNCLAT1 : 1; /*!< [6..6] SYNC1/LATCH1 Configuration Indication                              */
            __IM uint8_t SYNC1OUT : 2; /*!< [5..4] SYNC1 Output Driver/Polarity Indication                            */
            __IM uint8_t SYNC0MAP : 1; /*!< [3..3] SYNC0 State Mapping Indication                                     */
            __IM uint8_t SYNCLAT0 : 1; /*!< [2..2] SYNC0/LATCH0 Configuration Indication                              */
            __IM uint8_t SYNC0OUT : 2; /*!< [1..0] SYNC0 Output Driver/ Polarity Indication                           */
#else
            __IM uint8_t SYNC0OUT : 2; /*!< [1..0] SYNC0 Output Driver/ Polarity Indication                           */
            __IM uint8_t SYNCLAT0 : 1; /*!< [2..2] SYNC0/LATCH0 Configuration Indication                              */
            __IM uint8_t SYNC0MAP : 1; /*!< [3..3] SYNC0 State Mapping Indication                                     */
            __IM uint8_t SYNC1OUT : 2; /*!< [5..4] SYNC1 Output Driver/Polarity Indication                            */
            __IM uint8_t SYNCLAT1 : 1; /*!< [6..6] SYNC1/LATCH1 Configuration Indication                              */
            __IM uint8_t SYNC1MAP : 1; /*!< [7..7] SYNC1 State Mapping Indication                                     */
#endif
        } SYNCLATCHCONFIG_b;
    };

    union
    {
        __IM uint16_t EXTPDICONFIG;    /*!< (@ 0x00000152) Extended PDI Configuration Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t                 : 14;
            __IM uint16_t DATABUSWID : 2; /*!< [1..0] PDI Data Bus Width Indication                                      */
#else
            __IM uint16_t DATABUSWID : 2; /*!< [1..0] PDI Data Bus Width Indication                                      */
            uint16_t                 : 14;
#endif
        } EXTPDICONFIG_b;
    };
    __IM uint32_t  RESERVED22[43];
    __IM uint16_t  ECATEVENTMASK;      /*!< (@ 0x00000200) ECAT Event Mask Register                                   */
    __IM uint16_t  RESERVED23;
    __IOM uint32_t ALEVENTMASK;        /*!< (@ 0x00000204) AL Event Mask Register                                     */
    __IM uint32_t  RESERVED24[2];

    union
    {
        __IM uint16_t ECATEVENTREQ;    /*!< (@ 0x00000210) ECAT Event Request Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t              : 4;
            __IM uint16_t SMSTA7  : 1; /*!< [11..11] SyncManager 7 Status Flag                                        */
            __IM uint16_t SMSTA6  : 1; /*!< [10..10] SyncManager 6 Status Flag                                        */
            __IM uint16_t SMSTA5  : 1; /*!< [9..9] SyncManager 5 Status Flag                                          */
            __IM uint16_t SMSTA4  : 1; /*!< [8..8] SyncManager 4 Status Flag                                          */
            __IM uint16_t SMSTA3  : 1; /*!< [7..7] SyncManager 3 Status Flag                                          */
            __IM uint16_t SMSTA2  : 1; /*!< [6..6] SyncManager 2 Status Flag                                          */
            __IM uint16_t SMSTA1  : 1; /*!< [5..5] SyncManager 1 Status Flag                                          */
            __IM uint16_t SMSTA0  : 1; /*!< [4..4] SyncManager 0 Status Flag                                          */
            __IM uint16_t ALSTA   : 1; /*!< [3..3] AL Status Event Flag                                               */
            __IM uint16_t DLSTA   : 1; /*!< [2..2] DL Status Event Flag                                               */
            uint16_t              : 1;
            __IM uint16_t DCLATCH : 1; /*!< [0..0] DC Latch Event Flag                                                */
#else
            __IM uint16_t DCLATCH : 1; /*!< [0..0] DC Latch Event Flag                                                */
            uint16_t              : 1;
            __IM uint16_t DLSTA   : 1; /*!< [2..2] DL Status Event Flag                                               */
            __IM uint16_t ALSTA   : 1; /*!< [3..3] AL Status Event Flag                                               */
            __IM uint16_t SMSTA0  : 1; /*!< [4..4] SyncManager 0 Status Flag                                          */
            __IM uint16_t SMSTA1  : 1; /*!< [5..5] SyncManager 1 Status Flag                                          */
            __IM uint16_t SMSTA2  : 1; /*!< [6..6] SyncManager 2 Status Flag                                          */
            __IM uint16_t SMSTA3  : 1; /*!< [7..7] SyncManager 3 Status Flag                                          */
            __IM uint16_t SMSTA4  : 1; /*!< [8..8] SyncManager 4 Status Flag                                          */
            __IM uint16_t SMSTA5  : 1; /*!< [9..9] SyncManager 5 Status Flag                                          */
            __IM uint16_t SMSTA6  : 1; /*!< [10..10] SyncManager 6 Status Flag                                        */
            __IM uint16_t SMSTA7  : 1; /*!< [11..11] SyncManager 7 Status Flag                                        */
            uint16_t              : 4;
#endif
        } ECATEVENTREQ_b;
    };
    __IM uint16_t RESERVED25;
    __IM uint32_t RESERVED26[3];

    union
    {
        __IM uint32_t ALEVENTREQ;      /*!< (@ 0x00000220) AL Event Request Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 16;
            __IM uint32_t SMINT7     : 1; /*!< [15..15] SyncManager 7 Interrupt Status Flag                              */
            __IM uint32_t SMINT6     : 1; /*!< [14..14] SyncManager 6 Interrupt Status Flag                              */
            __IM uint32_t SMINT5     : 1; /*!< [13..13] SyncManager 5 Interrupt Status Flag                              */
            __IM uint32_t SMINT4     : 1; /*!< [12..12] SyncManager 4 Interrupt Status Flag                              */
            __IM uint32_t SMINT3     : 1; /*!< [11..11] SyncManager 3 Interrupt Status Flag                              */
            __IM uint32_t SMINT2     : 1; /*!< [10..10] SyncManager 2 Interrupt Status Flag                              */
            __IM uint32_t SMINT1     : 1; /*!< [9..9] SyncManager 1 Interrupt Status Flag                                */
            __IM uint32_t SMINT0     : 1; /*!< [8..8] SyncManager 0 Interrupt Status Flag                                */
            uint32_t                 : 1;
            __IM uint32_t WDPD       : 1; /*!< [6..6] Process Data Watchdog Indication Flag                              */
            uint32_t                 : 1;
            __IM uint32_t SYNCACT    : 1; /*!< [4..4] SyncManager Activation Indication Flag                             */
            __IM uint32_t DCSYNC1STA : 1; /*!< [3..3] DC SYNC1 Status Flag State of DC SYNC1                             */
            __IM uint32_t DCSYNC0STA : 1; /*!< [2..2] DC SYNC0 Status Flag State of DC SYNC0                             */
            __IM uint32_t DCLATCH    : 1; /*!< [1..1] DC Latch Event Status Flag                                         */
            __IM uint32_t ALCTRL     : 1; /*!< [0..0] AL Control Event Status Flag                                       */
#else
            __IM uint32_t ALCTRL     : 1; /*!< [0..0] AL Control Event Status Flag                                       */
            __IM uint32_t DCLATCH    : 1; /*!< [1..1] DC Latch Event Status Flag                                         */
            __IM uint32_t DCSYNC0STA : 1; /*!< [2..2] DC SYNC0 Status Flag State of DC SYNC0                             */
            __IM uint32_t DCSYNC1STA : 1; /*!< [3..3] DC SYNC1 Status Flag State of DC SYNC1                             */
            __IM uint32_t SYNCACT    : 1; /*!< [4..4] SyncManager Activation Indication Flag                             */
            uint32_t                 : 1;
            __IM uint32_t WDPD       : 1; /*!< [6..6] Process Data Watchdog Indication Flag                              */
            uint32_t                 : 1;
            __IM uint32_t SMINT0     : 1; /*!< [8..8] SyncManager 0 Interrupt Status Flag                                */
            __IM uint32_t SMINT1     : 1; /*!< [9..9] SyncManager 1 Interrupt Status Flag                                */
            __IM uint32_t SMINT2     : 1; /*!< [10..10] SyncManager 2 Interrupt Status Flag                              */
            __IM uint32_t SMINT3     : 1; /*!< [11..11] SyncManager 3 Interrupt Status Flag                              */
            __IM uint32_t SMINT4     : 1; /*!< [12..12] SyncManager 4 Interrupt Status Flag                              */
            __IM uint32_t SMINT5     : 1; /*!< [13..13] SyncManager 5 Interrupt Status Flag                              */
            __IM uint32_t SMINT6     : 1; /*!< [14..14] SyncManager 6 Interrupt Status Flag                              */
            __IM uint32_t SMINT7     : 1; /*!< [15..15] SyncManager 7 Interrupt Status Flag                              */
            uint32_t                 : 16;
#endif
        } ALEVENTREQ_b;
    };
    __IM uint32_t RESERVED27[55];

    union
    {
        __IM uint16_t RXERRCOUNT0;     /*!< (@ 0x00000300) Port 0 RX Error Count Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint16_t RXERRCNT  : 8; /*!< [15..8] RX Error Counter Value Indication Flag                            */
            __IM uint16_t INVFRMCNT : 8; /*!< [7..0] Invalid Frame Counter Value Indication Flag                        */
#else
            __IM uint16_t INVFRMCNT : 8; /*!< [7..0] Invalid Frame Counter Value Indication Flag                        */
            __IM uint16_t RXERRCNT  : 8; /*!< [15..8] RX Error Counter Value Indication Flag                            */
#endif
        } RXERRCOUNT0_b;
    };

    union
    {
        __IM uint16_t RXERRCOUNT1;     /*!< (@ 0x00000302) Port 1 RX Error Count Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint16_t RXERRCNT  : 8; /*!< [15..8] RX Error Counter Value Indication Flag                            */
            __IM uint16_t INVFRMCNT : 8; /*!< [7..0] Invalid Frame Counter Value Indication Flag                        */
#else
            __IM uint16_t INVFRMCNT : 8; /*!< [7..0] Invalid Frame Counter Value Indication Flag                        */
            __IM uint16_t RXERRCNT  : 8; /*!< [15..8] RX Error Counter Value Indication Flag                            */
#endif
        } RXERRCOUNT1_b;
    };
    __IM uint32_t RESERVED28;
    __IM uint8_t  FWDRXERRCOUNT0;      /*!< (@ 0x00000308) Port 0 Forwarded RX Error Count Register                   */
    __IM uint8_t  FWDRXERRCOUNT1;      /*!< (@ 0x00000309) Port 1 Forwarded RX Error Count Register                   */
    __IM uint16_t RESERVED29;
    __IM uint8_t  EPUERRCOUNT;         /*!< (@ 0x0000030C) ECAT Processing Unit Error Count Register                  */
    __IM uint8_t  PDIERRCOUNT;         /*!< (@ 0x0000030D) PDI Error Count Register                                   */
    __IM uint16_t RESERVED30;
    __IM uint8_t  LOSTLINKCOUNT0;      /*!< (@ 0x00000310) Port 0 Lost Link Count Register                            */
    __IM uint8_t  LOSTLINKCOUNT1;      /*!< (@ 0x00000311) Port 1 Lost Link Count Register                            */
    __IM uint16_t RESERVED31;
    __IM uint32_t RESERVED32[59];
    __IM uint16_t WDDIVIDE;            /*!< (@ 0x00000400) Watchdog Divider Register                                  */
    __IM uint16_t RESERVED33;
    __IM uint32_t RESERVED34[3];
    __IM uint16_t WDTPDI;              /*!< (@ 0x00000410) PDI Watchdog Time Register                                 */
    __IM uint16_t RESERVED35;
    __IM uint32_t RESERVED36[3];
    __IM uint16_t WDTDATA;             /*!< (@ 0x00000420) Process Data Watchdog Time Register                        */
    __IM uint16_t RESERVED37;
    __IM uint32_t RESERVED38[7];

    union
    {
        __IM uint16_t WDSDATA;         /*!< (@ 0x00000440) Process Data Watchdog Status Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t              : 15;
            __IM uint16_t WDSTAPD : 1; /*!< [0..0] Watchdog Status Flag                                               */
#else
            __IM uint16_t WDSTAPD : 1; /*!< [0..0] Watchdog Status Flag                                               */
            uint16_t              : 15;
#endif
        } WDSDATA_b;
    };
    __IM uint8_t  WDCDATA;             /*!< (@ 0x00000442) Process Data Watchdog Counter Register                     */
    __IM uint8_t  WDCPDI;              /*!< (@ 0x00000443) PDI Watchdog Counter Register                              */
    __IM uint32_t RESERVED39[47];

    union
    {
        __IM uint8_t EEPCONF;          /*!< (@ 0x00000500) EEPROM Configuration Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 6;
            __IM uint8_t FORCEECAT : 1; /*!< [1..1] EEPROM Access Right Change                                         */
            __IM uint8_t CTRLPDI   : 1; /*!< [0..0] EEPROM Control                                                     */
#else
            __IM uint8_t CTRLPDI   : 1; /*!< [0..0] EEPROM Control                                                     */
            __IM uint8_t FORCEECAT : 1; /*!< [1..1] EEPROM Access Right Change                                         */
            uint8_t                : 6;
#endif
        } EEPCONF_b;
    };

    union
    {
        __IOM uint8_t EEPSTATE;        /*!< (@ 0x00000501) EEPROM PDI Access State Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 7;
            __IOM uint8_t PDIACCESS : 1; /*!< [0..0] EEPROM Access Right Setting                                        */
#else
            __IOM uint8_t PDIACCESS : 1; /*!< [0..0] EEPROM Access Right Setting                                        */
            uint8_t                 : 7;
#endif
        } EEPSTATE_b;
    };

    union
    {
        __IOM uint16_t EEPCONTSTAT;    /*!< (@ 0x00000502) EEPROM Control/Status Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint16_t  BUSY      : 1; /*!< [15..15] EEPROM Interface Status Flag                                     */
            __IM uint16_t  WRENERR   : 1; /*!< [14..14] Write Enable Error Flag                                          */
            __IM uint16_t  ACKCMDERR : 1; /*!< [13..13] Acknowledge/Command Error Flag                                   */
            __IM uint16_t  LOADSTA   : 1; /*!< [12..12] EEPROM Loading Status Flag                                       */
            __IM uint16_t  CKSUMERR  : 1; /*!< [11..11] Checksum Error Indication Flag                                   */
            __IOM uint16_t COMMAND   : 3; /*!< [10..8] Command Setting/Indication                                        */
            __IM uint16_t  PROMSIZE  : 1; /*!< [7..7] EEPROM Algorithm Indication                                        */
            __IM uint16_t  READBYTE  : 1; /*!< [6..6] EEPROM Read Byte Indication                                        */
            uint16_t                 : 5;
            __IM uint16_t ECATWREN   : 1; /*!< [0..0] ECAT Write Enable                                                  */
#else
            __IM uint16_t ECATWREN   : 1; /*!< [0..0] ECAT Write Enable                                                  */
            uint16_t                 : 5;
            __IM uint16_t  READBYTE  : 1; /*!< [6..6] EEPROM Read Byte Indication                                        */
            __IM uint16_t  PROMSIZE  : 1; /*!< [7..7] EEPROM Algorithm Indication                                        */
            __IOM uint16_t COMMAND   : 3; /*!< [10..8] Command Setting/Indication                                        */
            __IM uint16_t  CKSUMERR  : 1; /*!< [11..11] Checksum Error Indication Flag                                   */
            __IM uint16_t  LOADSTA   : 1; /*!< [12..12] EEPROM Loading Status Flag                                       */
            __IM uint16_t  ACKCMDERR : 1; /*!< [13..13] Acknowledge/Command Error Flag                                   */
            __IM uint16_t  WRENERR   : 1; /*!< [14..14] Write Enable Error Flag                                          */
            __IM uint16_t  BUSY      : 1; /*!< [15..15] EEPROM Interface Status Flag                                     */
#endif
        } EEPCONTSTAT_b;
    };
    __IOM uint32_t EEPADR;                /*!< (@ 0x00000504) EEPROM Address Register                                    */

    union
    {
        __IOM uint32_t EEPDATA;           /*!< (@ 0x00000508) EEPROM Data Register                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t  HIDATA : 16; /*!< [31..16] EEPROM Read Data Indication                                      */
            __IOM uint32_t LODATA : 16; /*!< [15..0] EEPROM Write Data Setting                                         */
#else
            __IOM uint32_t LODATA : 16; /*!< [15..0] EEPROM Write Data Setting                                         */
            __IM uint32_t  HIDATA : 16; /*!< [31..16] EEPROM Read Data Indication                                      */
#endif
        } EEPDATA_b;
    };
    __IM uint32_t RESERVED40;

    union
    {
        __IOM uint16_t MIICONTSTAT;    /*!< (@ 0x00000510) MII Management Control/Status Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint16_t BUSY       : 1; /*!< [15..15] MII Management Status Flag                                       */
            __IM uint16_t CMDERR     : 1; /*!< [14..14] Command Error Flag                                               */
            __IM uint16_t READERR    : 1; /*!< [13..13] Read Error Flag                                                  */
            uint16_t                 : 3;
            __IOM uint16_t COMMAND   : 2; /*!< [9..8] Command                                                            */
            __IM uint16_t  PHYOFFSET : 5; /*!< [7..3] PHY Address Offset Indication                                      */
            __IM uint16_t  MILINK    : 1; /*!< [2..2] MI Link Detection Availability Indication                          */
            __IM uint16_t  PDICTRL   : 1; /*!< [1..1] PDI Control Indication                                             */
            __IM uint16_t  WREN      : 1; /*!< [0..0] Write Enable                                                       */
#else
            __IM uint16_t  WREN      : 1; /*!< [0..0] Write Enable                                                       */
            __IM uint16_t  PDICTRL   : 1; /*!< [1..1] PDI Control Indication                                             */
            __IM uint16_t  MILINK    : 1; /*!< [2..2] MI Link Detection Availability Indication                          */
            __IM uint16_t  PHYOFFSET : 5; /*!< [7..3] PHY Address Offset Indication                                      */
            __IOM uint16_t COMMAND   : 2; /*!< [9..8] Command                                                            */
            uint16_t                 : 3;
            __IM uint16_t READERR    : 1; /*!< [13..13] Read Error Flag                                                  */
            __IM uint16_t CMDERR     : 1; /*!< [14..14] Command Error Flag                                               */
            __IM uint16_t BUSY       : 1; /*!< [15..15] MII Management Status Flag                                       */
#endif
        } MIICONTSTAT_b;
    };

    union
    {
        __IOM uint8_t PHYADR;          /*!< (@ 0x00000512) PHY Address Register                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 3;
            __IOM uint8_t PHYADDR : 5; /*!< [4..0] PHY Address Setting                                                */
#else
            __IOM uint8_t PHYADDR : 5; /*!< [4..0] PHY Address Setting                                                */
            uint8_t               : 3;
#endif
        } PHYADR_b;
    };

    union
    {
        __IOM uint8_t PHYREGADR;       /*!< (@ 0x00000513) PHY Register Address Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                  : 3;
            __IOM uint8_t PHYREGADDR : 5; /*!< [4..0] PHY Address Setting                                                */
#else
            __IOM uint8_t PHYREGADDR : 5; /*!< [4..0] PHY Address Setting                                                */
            uint8_t                  : 3;
#endif
        } PHYREGADR_b;
    };
    __IOM uint16_t PHYDATA;            /*!< (@ 0x00000514) PHY Data Register                                          */

    union
    {
        __IM uint8_t MIIECATACSSTAT;   /*!< (@ 0x00000516) MII Management ECAT Access State Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IM uint8_t ACSMII : 1;   /*!< [0..0] MII Management Interface Access Right Setting                      */
#else
            __IM uint8_t ACSMII : 1;   /*!< [0..0] MII Management Interface Access Right Setting                      */
            uint8_t             : 7;
#endif
        } MIIECATACSSTAT_b;
    };

    union
    {
        __IOM uint8_t MIIPDIACSSTAT;   /*!< (@ 0x00000517) MII Management PDI Access State Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 6;
            __IM uint8_t  FORPDI : 1;  /*!< [1..1] PDI Access State Change                                            */
            __IOM uint8_t ACSMII : 1;  /*!< [0..0] MII Management Interface Access Right Change                       */
#else
            __IOM uint8_t ACSMII : 1;  /*!< [0..0] MII Management Interface Access Right Change                       */
            __IM uint8_t  FORPDI : 1;  /*!< [1..1] PDI Access State Change                                            */
            uint8_t              : 6;
#endif
        } MIIPDIACSSTAT_b;
    };
    __IM uint32_t RESERVED41[58];
    __IM uint32_t FMMU0LSTARTADR;      /*!< (@ 0x00000600) FMMU Logical Start Address Register 0                      */
    __IM uint16_t FMMU0LEN;            /*!< (@ 0x00000604) FMMU Length Register 0                                     */

    union
    {
        __IM uint8_t FMMU0LSTARTBIT;   /*!< (@ 0x00000606) FMMU Logical Start Bit Register 0                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU0LSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU0LSTOPBIT;    /*!< (@ 0x00000607) FMMU Logical Stop Bit Register 0                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU0LSTOPBIT_b;
    };
    __IM uint16_t FMMU0PSTARTADR;      /*!< (@ 0x00000608) FMMU Physical Start Address Register 0                     */

    union
    {
        __IM uint8_t FMMU0PSTARTBIT;   /*!< (@ 0x0000060A) FMMU Physical Start Bit Register 0                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 5;
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
#else
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
            uint8_t                : 5;
#endif
        } FMMU0PSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU0TYPE;        /*!< (@ 0x0000060B) FMMU Type Register 0                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 6;
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
#else
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            uint8_t            : 6;
#endif
        } FMMU0TYPE_b;
    };

    union
    {
        __IM uint8_t FMMU0ACT;         /*!< (@ 0x0000060C) FMMU Activate Register 0                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
#else
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
            uint8_t               : 7;
#endif
        } FMMU0ACT_b;
    };
    __IM uint8_t  RESERVED42;
    __IM uint16_t RESERVED43;
    __IM uint32_t FMMU1LSTARTADR;      /*!< (@ 0x00000610) FMMU Logical Start Address Register 1                      */
    __IM uint16_t FMMU1LEN;            /*!< (@ 0x00000614) FMMU Length Register 1                                     */

    union
    {
        __IM uint8_t FMMU1LSTARTBIT;   /*!< (@ 0x00000616) FMMU Logical Start Bit Register 1                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU1LSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU1LSTOPBIT;    /*!< (@ 0x00000617) FMMU Logical Stop Bit Register 1                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU1LSTOPBIT_b;
    };
    __IM uint16_t FMMU1PSTARTADR;      /*!< (@ 0x00000618) FMMU Physical Start Address Register 1                     */

    union
    {
        __IM uint8_t FMMU1PSTARTBIT;   /*!< (@ 0x0000061A) FMMU Physical Start Bit Register 1                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 5;
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
#else
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
            uint8_t                : 5;
#endif
        } FMMU1PSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU1TYPE;        /*!< (@ 0x0000061B) FMMU Type Register 1                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 6;
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
#else
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            uint8_t            : 6;
#endif
        } FMMU1TYPE_b;
    };

    union
    {
        __IM uint8_t FMMU1ACT;         /*!< (@ 0x0000061C) FMMU Activate Register 1                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
#else
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
            uint8_t               : 7;
#endif
        } FMMU1ACT_b;
    };
    __IM uint8_t  RESERVED44;
    __IM uint16_t RESERVED45;
    __IM uint32_t FMMU2LSTARTADR;      /*!< (@ 0x00000620) FMMU Logical Start Address Register 2                      */
    __IM uint16_t FMMU2LEN;            /*!< (@ 0x00000624) FMMU Length Register 2                                     */

    union
    {
        __IM uint8_t FMMU2LSTARTBIT;   /*!< (@ 0x00000626) FMMU Logical Start Bit Register 2                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU2LSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU2LSTOPBIT;    /*!< (@ 0x00000627) FMMU Logical Stop Bit Register 2                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU2LSTOPBIT_b;
    };
    __IM uint16_t FMMU2PSTARTADR;      /*!< (@ 0x00000628) FMMU Physical Start Address Register 2                     */

    union
    {
        __IM uint8_t FMMU2PSTARTBIT;   /*!< (@ 0x0000062A) FMMU Physical Start Bit Register 2                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 5;
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
#else
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
            uint8_t                : 5;
#endif
        } FMMU2PSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU2TYPE;        /*!< (@ 0x0000062B) FMMU Type Register 2                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 6;
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
#else
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            uint8_t            : 6;
#endif
        } FMMU2TYPE_b;
    };

    union
    {
        __IM uint8_t FMMU2ACT;         /*!< (@ 0x0000062C) FMMU Activate Register 2                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
#else
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
            uint8_t               : 7;
#endif
        } FMMU2ACT_b;
    };
    __IM uint8_t  RESERVED46;
    __IM uint16_t RESERVED47;
    __IM uint32_t FMMU3LSTARTADR;      /*!< (@ 0x00000630) FMMU Logical Start Address Register 3                      */
    __IM uint16_t FMMU3LEN;            /*!< (@ 0x00000634) FMMU Length Register 3                                     */

    union
    {
        __IM uint8_t FMMU3LSTARTBIT;   /*!< (@ 0x00000636) FMMU Logical Start Bit Register 3                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU3LSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU3LSTOPBIT;    /*!< (@ 0x00000637) FMMU Logical Stop Bit Register 3                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU3LSTOPBIT_b;
    };
    __IM uint16_t FMMU3PSTARTADR;      /*!< (@ 0x00000638) FMMU Physical Start Address Register 3                     */

    union
    {
        __IM uint8_t FMMU3PSTARTBIT;   /*!< (@ 0x0000063A) FMMU Physical Start Bit Register 3                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 5;
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
#else
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
            uint8_t                : 5;
#endif
        } FMMU3PSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU3TYPE;        /*!< (@ 0x0000063B) FMMU Type Register 3                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 6;
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
#else
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            uint8_t            : 6;
#endif
        } FMMU3TYPE_b;
    };

    union
    {
        __IM uint8_t FMMU3ACT;         /*!< (@ 0x0000063C) FMMU Activate Register 3                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
#else
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
            uint8_t               : 7;
#endif
        } FMMU3ACT_b;
    };
    __IM uint8_t  RESERVED48;
    __IM uint16_t RESERVED49;
    __IM uint32_t FMMU4LSTARTADR;      /*!< (@ 0x00000640) FMMU Logical Start Address Register 4                      */
    __IM uint16_t FMMU4LEN;            /*!< (@ 0x00000644) FMMU Length Register 4                                     */

    union
    {
        __IM uint8_t FMMU4LSTARTBIT;   /*!< (@ 0x00000646) FMMU Logical Start Bit Register 4                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU4LSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU4LSTOPBIT;    /*!< (@ 0x00000647) FMMU Logical Stop Bit Register 4                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU4LSTOPBIT_b;
    };
    __IM uint16_t FMMU4PSTARTADR;      /*!< (@ 0x00000648) FMMU Physical Start Address Register 4                     */

    union
    {
        __IM uint8_t FMMU4PSTARTBIT;   /*!< (@ 0x0000064A) FMMU Physical Start Bit Register 4                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 5;
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
#else
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
            uint8_t                : 5;
#endif
        } FMMU4PSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU4TYPE;        /*!< (@ 0x0000064B) FMMU Type Register 4                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 6;
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
#else
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            uint8_t            : 6;
#endif
        } FMMU4TYPE_b;
    };

    union
    {
        __IM uint8_t FMMU4ACT;         /*!< (@ 0x0000064C) FMMU Activate Register 4                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
#else
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
            uint8_t               : 7;
#endif
        } FMMU4ACT_b;
    };
    __IM uint8_t  RESERVED50;
    __IM uint16_t RESERVED51;
    __IM uint32_t FMMU5LSTARTADR;      /*!< (@ 0x00000650) FMMU Logical Start Address Register 5                      */
    __IM uint16_t FMMU5LEN;            /*!< (@ 0x00000654) FMMU Length Register 5                                     */

    union
    {
        __IM uint8_t FMMU5LSTARTBIT;   /*!< (@ 0x00000656) FMMU Logical Start Bit Register 5                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU5LSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU5LSTOPBIT;    /*!< (@ 0x00000657) FMMU Logical Stop Bit Register 5                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU5LSTOPBIT_b;
    };
    __IM uint16_t FMMU5PSTARTADR;      /*!< (@ 0x00000658) FMMU Physical Start Address Register 5                     */

    union
    {
        __IM uint8_t FMMU5PSTARTBIT;   /*!< (@ 0x0000065A) FMMU Physical Start Bit Register 5                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 5;
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
#else
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
            uint8_t                : 5;
#endif
        } FMMU5PSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU5TYPE;        /*!< (@ 0x0000065B) FMMU Type Register 5                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 6;
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
#else
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            uint8_t            : 6;
#endif
        } FMMU5TYPE_b;
    };

    union
    {
        __IM uint8_t FMMU5ACT;         /*!< (@ 0x0000065C) FMMU Activate Register 5                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
#else
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
            uint8_t               : 7;
#endif
        } FMMU5ACT_b;
    };
    __IM uint8_t  RESERVED52;
    __IM uint16_t RESERVED53;
    __IM uint32_t FMMU6LSTARTADR;      /*!< (@ 0x00000660) FMMU Logical Start Address Register 6                      */
    __IM uint16_t FMMU6LEN;            /*!< (@ 0x00000664) FMMU Length Register 6                                     */

    union
    {
        __IM uint8_t FMMU6LSTARTBIT;   /*!< (@ 0x00000666) FMMU Logical Start Bit Register 6                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU6LSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU6LSTOPBIT;    /*!< (@ 0x00000667) FMMU Logical Stop Bit Register 6                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU6LSTOPBIT_b;
    };
    __IM uint16_t FMMU6PSTARTADR;      /*!< (@ 0x00000668) FMMU Physical Start Address Register 6                     */

    union
    {
        __IM uint8_t FMMU6PSTARTBIT;   /*!< (@ 0x0000066A) FMMU Physical Start Bit Register 6                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 5;
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
#else
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
            uint8_t                : 5;
#endif
        } FMMU6PSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU6TYPE;        /*!< (@ 0x0000066B) FMMU Type Register 6                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 6;
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
#else
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            uint8_t            : 6;
#endif
        } FMMU6TYPE_b;
    };

    union
    {
        __IM uint8_t FMMU6ACT;         /*!< (@ 0x0000066C) FMMU Activate Register 6                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
#else
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
            uint8_t               : 7;
#endif
        } FMMU6ACT_b;
    };
    __IM uint8_t  RESERVED54;
    __IM uint16_t RESERVED55;
    __IM uint32_t FMMU7LSTARTADR;      /*!< (@ 0x00000670) FMMU Logical Start Address Register 7                      */
    __IM uint16_t FMMU7LEN;            /*!< (@ 0x00000674) FMMU Length Register 7                                     */

    union
    {
        __IM uint8_t FMMU7LSTARTBIT;   /*!< (@ 0x00000676) FMMU Logical Start Bit Register 7                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU7LSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU7LSTOPBIT;    /*!< (@ 0x00000677) FMMU Logical Stop Bit Register 7                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
#else
            __IM uint8_t LSTABIT : 3;  /*!< [2..0] Start Bit Setting                                                  */
            uint8_t              : 5;
#endif
        } FMMU7LSTOPBIT_b;
    };
    __IM uint16_t FMMU7PSTARTADR;      /*!< (@ 0x00000678) FMMU Physical Start Address Register 7                     */

    union
    {
        __IM uint8_t FMMU7PSTARTBIT;   /*!< (@ 0x0000067A) FMMU Physical Start Bit Register 7                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 5;
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
#else
            __IM uint8_t PHYSTABIT : 3; /*!< [2..0] Physical Start Bit Setting                                         */
            uint8_t                : 5;
#endif
        } FMMU7PSTARTBIT_b;
    };

    union
    {
        __IM uint8_t FMMU7TYPE;        /*!< (@ 0x0000067B) FMMU Type Register 7                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 6;
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
#else
            __IM uint8_t READ  : 1;    /*!< [0..0] Read Access Mapping Setting                                        */
            __IM uint8_t WRITE : 1;    /*!< [1..1] Write Access Mapping Setting                                       */
            uint8_t            : 6;
#endif
        } FMMU7TYPE_b;
    };

    union
    {
        __IM uint8_t FMMU7ACT;         /*!< (@ 0x0000067C) FMMU Activate Register 7                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
#else
            __IM uint8_t ACTIVATE : 1; /*!< [0..0] FMMU Enable/Disable                                                */
            uint8_t               : 7;
#endif
        } FMMU7ACT_b;
    };
    __IM uint8_t  RESERVED56;
    __IM uint16_t RESERVED57;
    __IM uint32_t RESERVED58[96];
    __IM uint16_t SM0PSTARTADR;        /*!< (@ 0x00000800) SyncManager Physical Start Address Register 0              */
    __IM uint16_t SM0LEN;              /*!< (@ 0x00000802) SyncManager Length Register 0                              */

    union
    {
        __IM uint8_t SM0CONTROL;       /*!< (@ 0x00000804) SyncManager Control Register 0                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 1;
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
#else
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            uint8_t              : 1;
#endif
        } SM0CONTROL_b;
    };

    union
    {
        __IM uint8_t SM0STATUS;        /*!< (@ 0x00000805) SyncManager Status Register 0                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            uint8_t               : 1;
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
#else
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            uint8_t               : 1;
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
#endif
        } SM0STATUS_b;
    };

    union
    {
        __IM uint8_t SM0ACT;           /*!< (@ 0x00000806) SyncManager Activate Register 0                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            uint8_t                : 4;
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
#else
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            uint8_t                : 4;
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
#endif
        } SM0ACT_b;
    };

    union
    {
        __IOM uint8_t SM0PDICONT;      /*!< (@ 0x00000807) SyncManager PDI Control Register 0                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 6;
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
#else
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            uint8_t                 : 6;
#endif
        } SM0PDICONT_b;
    };
    __IM uint16_t SM1PSTARTADR;        /*!< (@ 0x00000808) SyncManager Physical Start Address Register 1              */
    __IM uint16_t SM1LEN;              /*!< (@ 0x0000080A) SyncManager Length Register 1                              */

    union
    {
        __IM uint8_t SM1CONTROL;       /*!< (@ 0x0000080C) SyncManager Control Register 1                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 1;
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
#else
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            uint8_t              : 1;
#endif
        } SM1CONTROL_b;
    };

    union
    {
        __IM uint8_t SM1STATUS;        /*!< (@ 0x0000080D) SyncManager Status Register 1                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            uint8_t               : 1;
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
#else
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            uint8_t               : 1;
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
#endif
        } SM1STATUS_b;
    };

    union
    {
        __IM uint8_t SM1ACT;           /*!< (@ 0x0000080E) SyncManager Activate Register 1                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            uint8_t                : 4;
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
#else
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            uint8_t                : 4;
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
#endif
        } SM1ACT_b;
    };

    union
    {
        __IOM uint8_t SM1PDICONT;      /*!< (@ 0x0000080F) SyncManager PDI Control Register 1                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 6;
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
#else
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            uint8_t                 : 6;
#endif
        } SM1PDICONT_b;
    };
    __IM uint16_t SM2PSTARTADR;        /*!< (@ 0x00000810) SyncManager Physical Start Address Register 2              */
    __IM uint16_t SM2LEN;              /*!< (@ 0x00000812) SyncManager Length Register 2                              */

    union
    {
        __IM uint8_t SM2CONTROL;       /*!< (@ 0x00000814) SyncManager Control Register 2                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 1;
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
#else
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            uint8_t              : 1;
#endif
        } SM2CONTROL_b;
    };

    union
    {
        __IM uint8_t SM2STATUS;        /*!< (@ 0x00000815) SyncManager Status Register 2                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            uint8_t               : 1;
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
#else
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            uint8_t               : 1;
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
#endif
        } SM2STATUS_b;
    };

    union
    {
        __IM uint8_t SM2ACT;           /*!< (@ 0x00000816) SyncManager Activate Register 2                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            uint8_t                : 4;
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
#else
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            uint8_t                : 4;
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
#endif
        } SM2ACT_b;
    };

    union
    {
        __IOM uint8_t SM2PDICONT;      /*!< (@ 0x00000817) SyncManager PDI Control Register 2                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 6;
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
#else
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            uint8_t                 : 6;
#endif
        } SM2PDICONT_b;
    };
    __IM uint16_t SM3PSTARTADR;        /*!< (@ 0x00000818) SyncManager Physical Start Address Register 3              */
    __IM uint16_t SM3LEN;              /*!< (@ 0x0000081A) SyncManager Length Register 3                              */

    union
    {
        __IM uint8_t SM3CONTROL;       /*!< (@ 0x0000081C) SyncManager Control Register 3                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 1;
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
#else
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            uint8_t              : 1;
#endif
        } SM3CONTROL_b;
    };

    union
    {
        __IM uint8_t SM3STATUS;        /*!< (@ 0x0000081D) SyncManager Status Register 3                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            uint8_t               : 1;
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
#else
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            uint8_t               : 1;
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
#endif
        } SM3STATUS_b;
    };

    union
    {
        __IM uint8_t SM3ACT;           /*!< (@ 0x0000081E) SyncManager Activate Register 3                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            uint8_t                : 4;
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
#else
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            uint8_t                : 4;
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
#endif
        } SM3ACT_b;
    };

    union
    {
        __IOM uint8_t SM3PDICONT;      /*!< (@ 0x0000081F) SyncManager PDI Control Register 3                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 6;
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
#else
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            uint8_t                 : 6;
#endif
        } SM3PDICONT_b;
    };
    __IM uint16_t SM4PSTARTADR;        /*!< (@ 0x00000820) SyncManager Physical Start Address Register 4              */
    __IM uint16_t SM4LEN;              /*!< (@ 0x00000822) SyncManager Length Register 4                              */

    union
    {
        __IM uint8_t SM4CONTROL;       /*!< (@ 0x00000824) SyncManager Control Register 4                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 1;
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
#else
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            uint8_t              : 1;
#endif
        } SM4CONTROL_b;
    };

    union
    {
        __IM uint8_t SM4STATUS;        /*!< (@ 0x00000825) SyncManager Status Register 4                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            uint8_t               : 1;
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
#else
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            uint8_t               : 1;
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
#endif
        } SM4STATUS_b;
    };

    union
    {
        __IM uint8_t SM4ACT;           /*!< (@ 0x00000826) SyncManager Activate Register 4                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            uint8_t                : 4;
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
#else
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            uint8_t                : 4;
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
#endif
        } SM4ACT_b;
    };

    union
    {
        __IOM uint8_t SM4PDICONT;      /*!< (@ 0x00000827) SyncManager PDI Control Register 4                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 6;
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
#else
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            uint8_t                 : 6;
#endif
        } SM4PDICONT_b;
    };
    __IM uint16_t SM5PSTARTADR;        /*!< (@ 0x00000828) SyncManager Physical Start Address Register 5              */
    __IM uint16_t SM5LEN;              /*!< (@ 0x0000082A) SyncManager Length Register 5                              */

    union
    {
        __IM uint8_t SM5CONTROL;       /*!< (@ 0x0000082C) SyncManager Control Register 5                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 1;
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
#else
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            uint8_t              : 1;
#endif
        } SM5CONTROL_b;
    };

    union
    {
        __IM uint8_t SM5STATUS;        /*!< (@ 0x0000082D) SyncManager Status Register 5                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            uint8_t               : 1;
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
#else
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            uint8_t               : 1;
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
#endif
        } SM5STATUS_b;
    };

    union
    {
        __IM uint8_t SM5ACT;           /*!< (@ 0x0000082E) SyncManager Activate Register 5                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            uint8_t                : 4;
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
#else
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            uint8_t                : 4;
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
#endif
        } SM5ACT_b;
    };

    union
    {
        __IOM uint8_t SM5PDICONT;      /*!< (@ 0x0000082F) SyncManager PDI Control Register 5                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 6;
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
#else
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            uint8_t                 : 6;
#endif
        } SM5PDICONT_b;
    };
    __IM uint16_t SM6PSTARTADR;        /*!< (@ 0x00000830) SyncManager Physical Start Address Register 6              */
    __IM uint16_t SM6LEN;              /*!< (@ 0x00000832) SyncManager Length Register 6                              */

    union
    {
        __IM uint8_t SM6CONTROL;       /*!< (@ 0x00000834) SyncManager Control Register 6                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 1;
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
#else
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            uint8_t              : 1;
#endif
        } SM6CONTROL_b;
    };

    union
    {
        __IM uint8_t SM6STATUS;        /*!< (@ 0x00000835) SyncManager Status Register 6                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            uint8_t               : 1;
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
#else
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            uint8_t               : 1;
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
#endif
        } SM6STATUS_b;
    };

    union
    {
        __IM uint8_t SM6ACT;           /*!< (@ 0x00000836) SyncManager Activate Register 6                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            uint8_t                : 4;
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
#else
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            uint8_t                : 4;
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
#endif
        } SM6ACT_b;
    };

    union
    {
        __IOM uint8_t SM6PDICONT;      /*!< (@ 0x00000837) SyncManager PDI Control Register 6                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 6;
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
#else
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            uint8_t                 : 6;
#endif
        } SM6PDICONT_b;
    };
    __IM uint16_t SM7PSTARTADR;        /*!< (@ 0x00000838) SyncManager Physical Start Address Register 7              */
    __IM uint16_t SM7LEN;              /*!< (@ 0x0000083A) SyncManager Length Register 7                              */

    union
    {
        __IM uint8_t SM7CONTROL;       /*!< (@ 0x0000083C) SyncManager Control Register 7                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 1;
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
#else
            __IM uint8_t OPEMODE : 2;  /*!< [1..0] Operating Mode Setting                                             */
            __IM uint8_t DIR     : 2;  /*!< [3..2] Transfer Direction Setting                                         */
            __IM uint8_t IRQECAT : 1;  /*!< [4..4] ECAT Event Interrupt Enable                                        */
            __IM uint8_t IRQPDI  : 1;  /*!< [5..5] AL Event Interrupt Enable                                          */
            __IM uint8_t WDTRGEN : 1;  /*!< [6..6] Watchdog Trigger Enable                                            */
            uint8_t              : 1;
#endif
        } SM7CONTROL_b;
    };

    union
    {
        __IM uint8_t SM7STATUS;        /*!< (@ 0x0000083D) SyncManager Status Register 7                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            uint8_t               : 1;
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
#else
            __IM uint8_t INTWR    : 1; /*!< [0..0] Write Complete Interrupt Status Flag                               */
            __IM uint8_t INTRD    : 1; /*!< [1..1] Read Complete Interrupt Status Flag                                */
            uint8_t               : 1;
            __IM uint8_t MAILBOX  : 1; /*!< [3..3] Mailbox Status Flag                                                */
            __IM uint8_t BUFFERED : 2; /*!< [5..4] Buffer Status Flag                                                 */
            __IM uint8_t RDBUF    : 1; /*!< [6..6] Read Status Flag                                                   */
            __IM uint8_t WRBUF    : 1; /*!< [7..7] Write Status Flag                                                  */
#endif
        } SM7STATUS_b;
    };

    union
    {
        __IM uint8_t SM7ACT;           /*!< (@ 0x0000083E) SyncManager Activate Register 7                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            uint8_t                : 4;
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
#else
            __IM uint8_t SMEN      : 1; /*!< [0..0] SyncManager Enable/Disable                                         */
            __IM uint8_t REPEATREQ : 1; /*!< [1..1] Repeat Request                                                     */
            uint8_t                : 4;
            __IM uint8_t LATCHECAT : 1; /*!< [6..6] ECAT Latch Event Specification                                     */
            __IM uint8_t LATCHPDI  : 1; /*!< [7..7] PDI Latch Event Specification                                      */
#endif
        } SM7ACT_b;
    };

    union
    {
        __IOM uint8_t SM7PDICONT;      /*!< (@ 0x0000083F) SyncManager PDI Control Register 7                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 6;
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
#else
            __IOM uint8_t DEACTIVE  : 1; /*!< [0..0] SyncManager Operation Indication/Setting                           */
            __IOM uint8_t REPEATACK : 1; /*!< [1..1] Repeat Acknowledge                                                 */
            uint8_t                 : 6;
#endif
        } SM7PDICONT_b;
    };
    __IM uint32_t RESERVED59[48];
    __IM uint32_t DCRCVTIMEPORT0;      /*!< (@ 0x00000900) Port 0 Receive Time Register                               */
    __IM uint32_t DCRCVTIMEPORT1;      /*!< (@ 0x00000904) Port 1 Receive Time Register                               */
    __IM uint32_t RESERVED60[2];
    __IM uint32_t DCSYSTIME_L;         /*!< (@ 0x00000910) System Time Register                                       */
    __IM uint32_t DCSYSTIME_H;         /*!< (@ 0x00000914) System Time Register                                       */
    __IM uint32_t DCRCVTIMEEPU_L;      /*!< (@ 0x00000918) Receive Time ECAT Processing Unit Register                 */
    __IM uint32_t DCRCVTIMEEPU_H;      /*!< (@ 0x0000091C) Receive Time ECAT Processing Unit Register                 */
    __IM uint32_t DCSYSTIMEOFFSET_L;   /*!< (@ 0x00000920) System Time Offset Register                                */
    __IM uint32_t DCSYSTIMEOFFSET_H;   /*!< (@ 0x00000924) System Time Offset Register                                */
    __IM uint32_t DCSYSTIMEDELAY;      /*!< (@ 0x00000928) System Time Delay Register                                 */

    union
    {
        __IM uint32_t DCSYSTIMEDIFF;   /*!< (@ 0x0000092C) System Time Difference Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t LOCALCOPY : 1;  /*!< [31..31] System Time Greater/Less Indication                              */
            __IM uint32_t DIFF      : 31; /*!< [30..0] System Time Mean Difference Indication                            */
#else
            __IM uint32_t DIFF      : 31; /*!< [30..0] System Time Mean Difference Indication                            */
            __IM uint32_t LOCALCOPY : 1;  /*!< [31..31] System Time Greater/Less Indication                              */
#endif
        } DCSYSTIMEDIFF_b;
    };

    union
    {
        __IM uint16_t DCSCSTART;       /*!< (@ 0x00000930) Speed Counter Start Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t              : 1;
            __IM uint16_t SCSTART : 15; /*!< [14..0] Drift Correction Bandwidth Setting                                */
#else
            __IM uint16_t SCSTART : 15; /*!< [14..0] Drift Correction Bandwidth Setting                                */
            uint16_t              : 1;
#endif
        } DCSCSTART_b;
    };
    __IM uint16_t DCSCDIFF;            /*!< (@ 0x00000932) Speed Counter Difference Register                          */

    union
    {
        __IM uint8_t DCSYSTIMEFILDP;   /*!< (@ 0x00000934) System Time Difference Filter Depth Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 4;
            __IM uint8_t FILDP : 4;    /*!< [3..0] Filter Depth Setting                                               */
#else
            __IM uint8_t FILDP : 4;    /*!< [3..0] Filter Depth Setting                                               */
            uint8_t            : 4;
#endif
        } DCSYSTIMEFILDP_b;
    };

    union
    {
        __IM uint8_t DCSCFILDP;        /*!< (@ 0x00000935) Speed Counter Filter Depth Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 4;
            __IM uint8_t FILDP : 4;    /*!< [3..0] Filter Depth Setting                                               */
#else
            __IM uint8_t FILDP : 4;    /*!< [3..0] Filter Depth Setting                                               */
            uint8_t            : 4;
#endif
        } DCSCFILDP_b;
    };
    __IM uint16_t RESERVED61;
    __IM uint32_t RESERVED62[18];

    union
    {
        __IM uint8_t DCCYCCONT;        /*!< (@ 0x00000980) Cyclic Unit Control Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 2;
            __IM uint8_t LATCH1  : 1;  /*!< [5..5] Latch Input Unit 1 Control Setting                                 */
            __IM uint8_t LATCH0  : 1;  /*!< [4..4] Latch Input Unit 0 Control Setting                                 */
            uint8_t              : 3;
            __IM uint8_t SYNCOUT : 1;  /*!< [0..0] SYNC Output Unit Control Setting                                   */
#else
            __IM uint8_t SYNCOUT : 1;  /*!< [0..0] SYNC Output Unit Control Setting                                   */
            uint8_t              : 3;
            __IM uint8_t LATCH0  : 1;  /*!< [4..4] Latch Input Unit 0 Control Setting                                 */
            __IM uint8_t LATCH1  : 1;  /*!< [5..5] Latch Input Unit 1 Control Setting                                 */
            uint8_t              : 2;
#endif
        } DCCYCCONT_b;
    };

    union
    {
        __IOM uint8_t DCACT;           /*!< (@ 0x00000981) Activation Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DBGPULSE     : 1; /*!< [7..7] Debug Pulse Setting                                                */
            __IOM uint8_t NEARFUTURE   : 1; /*!< [6..6] Near Future Configuration                                          */
            __IOM uint8_t STARTTIME    : 1; /*!< [5..5] Start Time Plausibility Check                                      */
            __IOM uint8_t EXTSTARTTIME : 1; /*!< [4..4] Start Time Cyclic Operation Extension                              */
            __IOM uint8_t AUTOACT      : 1; /*!< [3..3] Auto Activation                                                    */
            __IOM uint8_t SYNC1        : 1; /*!< [2..2] SYNC1 Output Setting                                               */
            __IOM uint8_t SYNC0        : 1; /*!< [1..1] SYNC0 Output Setting                                               */
            __IOM uint8_t SYNCACT      : 1; /*!< [0..0] SYNC Output Unit Activation                                        */
#else
            __IOM uint8_t SYNCACT      : 1; /*!< [0..0] SYNC Output Unit Activation                                        */
            __IOM uint8_t SYNC0        : 1; /*!< [1..1] SYNC0 Output Setting                                               */
            __IOM uint8_t SYNC1        : 1; /*!< [2..2] SYNC1 Output Setting                                               */
            __IOM uint8_t AUTOACT      : 1; /*!< [3..3] Auto Activation                                                    */
            __IOM uint8_t EXTSTARTTIME : 1; /*!< [4..4] Start Time Cyclic Operation Extension                              */
            __IOM uint8_t STARTTIME    : 1; /*!< [5..5] Start Time Plausibility Check                                      */
            __IOM uint8_t NEARFUTURE   : 1; /*!< [6..6] Near Future Configuration                                          */
            __IOM uint8_t DBGPULSE     : 1; /*!< [7..7] Debug Pulse Setting                                                */
#endif
        } DCACT_b;
    };
    __IM uint16_t DCPULSELEN;               /*!< (@ 0x00000982) SYNC Signal Pulse Length Register                          */

    union
    {
        __IM uint8_t DCACTSTAT;             /*!< (@ 0x00000984) Activation Status Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 5;
            __IM uint8_t STARTTIME : 1; /*!< [2..2] Plausibility Result Indication Flag                                */
            __IM uint8_t SYNC1ACT  : 1; /*!< [1..1] SYNC1 Status Flag                                                  */
            __IM uint8_t SYNC0ACT  : 1; /*!< [0..0] SYNC0 Status Flag                                                  */
#else
            __IM uint8_t SYNC0ACT  : 1; /*!< [0..0] SYNC0 Status Flag                                                  */
            __IM uint8_t SYNC1ACT  : 1; /*!< [1..1] SYNC1 Status Flag                                                  */
            __IM uint8_t STARTTIME : 1; /*!< [2..2] Plausibility Result Indication Flag                                */
            uint8_t                : 5;
#endif
        } DCACTSTAT_b;
    };
    __IM uint8_t  RESERVED63;
    __IM uint16_t RESERVED64;
    __IM uint32_t RESERVED65;
    __IM uint16_t RESERVED66;

    union
    {
        __IM uint8_t DCSYNC0STAT;      /*!< (@ 0x0000098E) SYNC0 Status Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IM uint8_t SYNC0STA : 1; /*!< [0..0] SYNC0 Status Flag                                                  */
#else
            __IM uint8_t SYNC0STA : 1; /*!< [0..0] SYNC0 Status Flag                                                  */
            uint8_t               : 7;
#endif
        } DCSYNC0STAT_b;
    };

    union
    {
        __IM uint8_t DCSYNC1STAT;      /*!< (@ 0x0000098F) SYNC1 Status Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IM uint8_t SYNC1STA : 1; /*!< [0..0] SYNC1 Status Flag                                                  */
#else
            __IM uint8_t SYNC1STA : 1; /*!< [0..0] SYNC1 Status Flag                                                  */
            uint8_t               : 7;
#endif
        } DCSYNC1STAT_b;
    };
    __IOM uint32_t DCCYCSTARTTIME_L;   /*!< (@ 0x00000990) Start Time Cyclic Operation/Next SYNC0 Pulse
                                        *                  Register                                                   */
    __IOM uint32_t DCCYCSTARTTIME_H;   /*!< (@ 0x00000994) Start Time Cyclic Operation/Next SYNC0 Pulse
                                        *                  Register                                                   */
    __IM uint32_t  DCNEXTSYNC1_L;      /*!< (@ 0x00000998) Next SYNC1 Pulse Register                                  */
    __IM uint32_t  DCNEXTSYNC1_H;      /*!< (@ 0x0000099C) Next SYNC1 Pulse Register                                  */
    __IOM uint32_t DCSYNC0CYCTIME;     /*!< (@ 0x000009A0) SYNC0 Cycle Time Register                                  */
    __IOM uint32_t DCSYNC1CYCTIME;     /*!< (@ 0x000009A4) SYNC1 Cycle Time Register                                  */

    union
    {
        __IOM uint8_t DCLATCH0CONT;    /*!< (@ 0x000009A8) Latch 0 Control Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 6;
            __IOM uint8_t NEGEDGE : 1; /*!< [1..1] LATCH0 Negative Edge Function Setting                              */
            __IOM uint8_t POSEDGE : 1; /*!< [0..0] LATCH0 Positive Edge Function Setting                              */
#else
            __IOM uint8_t POSEDGE : 1; /*!< [0..0] LATCH0 Positive Edge Function Setting                              */
            __IOM uint8_t NEGEDGE : 1; /*!< [1..1] LATCH0 Negative Edge Function Setting                              */
            uint8_t               : 6;
#endif
        } DCLATCH0CONT_b;
    };

    union
    {
        __IOM uint8_t DCLATCH1CONT;    /*!< (@ 0x000009A9) Latch 1 Control Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 6;
            __IOM uint8_t NEGEDGE : 1; /*!< [1..1] LATCH1 Negative Edge Function Setting                              */
            __IOM uint8_t POSEDGE : 1; /*!< [0..0] LATCH1 Positive Edge Function Setting                              */
#else
            __IOM uint8_t POSEDGE : 1; /*!< [0..0] LATCH1 Positive Edge Function Setting                              */
            __IOM uint8_t NEGEDGE : 1; /*!< [1..1] LATCH1 Negative Edge Function Setting                              */
            uint8_t               : 6;
#endif
        } DCLATCH1CONT_b;
    };
    __IM uint16_t RESERVED67[2];

    union
    {
        __IM uint8_t DCLATCH0STAT;     /*!< (@ 0x000009AE) Latch 0 Status Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 5;
            __IM uint8_t PINSTATE : 1; /*!< [2..2] LATCH0 Pin Status Flag                                             */
            __IM uint8_t EVENTNEG : 1; /*!< [1..1] LATCH0 Negative Edge Event Indication Flag                         */
            __IM uint8_t EVENTPOS : 1; /*!< [0..0] LATCH0 Positive Edge Event Indication Flag                         */
#else
            __IM uint8_t EVENTPOS : 1; /*!< [0..0] LATCH0 Positive Edge Event Indication Flag                         */
            __IM uint8_t EVENTNEG : 1; /*!< [1..1] LATCH0 Negative Edge Event Indication Flag                         */
            __IM uint8_t PINSTATE : 1; /*!< [2..2] LATCH0 Pin Status Flag                                             */
            uint8_t               : 5;
#endif
        } DCLATCH0STAT_b;
    };

    union
    {
        __IM uint8_t DCLATCH1STAT;     /*!< (@ 0x000009AF) Latch 1 Status Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 5;
            __IM uint8_t PINSTATE : 1; /*!< [2..2] LATCH1 Pin Status Flag                                             */
            __IM uint8_t EVENTNEG : 1; /*!< [1..1] LATCH1 Negative Edge Event Indication Flag                         */
            __IM uint8_t EVENTPOS : 1; /*!< [0..0] LATCH1 Positive Edge Event Indication Flag                         */
#else
            __IM uint8_t EVENTPOS : 1; /*!< [0..0] LATCH1 Positive Edge Event Indication Flag                         */
            __IM uint8_t EVENTNEG : 1; /*!< [1..1] LATCH1 Negative Edge Event Indication Flag                         */
            __IM uint8_t PINSTATE : 1; /*!< [2..2] LATCH1 Pin Status Flag                                             */
            uint8_t               : 5;
#endif
        } DCLATCH1STAT_b;
    };
    __IM uint32_t DCLATCH0TIMEPOS_L;   /*!< (@ 0x000009B0) Latch 0 Time Positive Edge Register                        */
    __IM uint32_t DCLATCH0TIMEPOS_H;   /*!< (@ 0x000009B4) Latch 0 Time Positive Edge Register                        */
    __IM uint32_t DCLATCH0TIMENEG_L;   /*!< (@ 0x000009B8) Latch 0 Time Negative Edge Register                        */
    __IM uint32_t DCLATCH0TIMENEG_H;   /*!< (@ 0x000009BC) Latch 0 Time Negative Edge Register                        */
    __IM uint32_t DCLATCH1TIMEPOS_L;   /*!< (@ 0x000009C0) Latch 1 Time Positive Edge Register                        */
    __IM uint32_t DCLATCH1TIMEPOS_H;   /*!< (@ 0x000009C4) Latch 1 Time Positive Edge Register                        */
    __IM uint32_t DCLATCH1TIMENEG_L;   /*!< (@ 0x000009C8) Latch 1 Time Negative Edge Register                        */
    __IM uint32_t DCLATCH1TIMENEG_H;   /*!< (@ 0x000009CC) Latch 1 Time Negative Edge Register                        */
    __IM uint32_t RESERVED68[8];
    __IM uint32_t DCECATCHGTIME;       /*!< (@ 0x000009F0) Buffer Change Event Time Register                          */
    __IM uint32_t RESERVED69;
    __IM uint32_t DCPDISTARTTIME;      /*!< (@ 0x000009F8) PDI Buffer Start Event Time Register                       */
    __IM uint32_t DCPDICHGTIME;        /*!< (@ 0x000009FC) PDI Buffer Change Event Time Register                      */
    __IM uint32_t RESERVED70[256];
    __IM uint32_t PRODUCTID_L;         /*!< (@ 0x00000E00) Product ID Register                                        */
    __IM uint32_t PRODUCTID_H;         /*!< (@ 0x00000E04) Product ID Register                                        */
    __IM uint32_t VENDORID_L;          /*!< (@ 0x00000E08) Vendor ID Register                                         */
    __IM uint32_t VENDORID_H;          /*!< (@ 0x00000E0C) Vendor ID Register                                         */
    __IM uint32_t RESERVED71[92];
    __IOM uint8_t USERRAM[128];        /*!< (@ 0x00000F80) User RAM                                                   */
    __IOM uint8_t DATARAM[8192];       /*!< (@ 0x00001000) Process Data RAM                                           */
    __IM uint32_t RESERVED72[1024];

    union
    {
        __IOM uint32_t ESCRST;         /*!< (@ 0x00004000) ESC Reset Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 29;
            __IOM uint32_t MIIRST : 1; /*!< [2..2] MII/RMII Converter Reset                                           */
            __IOM uint32_t PHYRST : 1; /*!< [1..1] PHY Reset                                                          */
            __IOM uint32_t ESCRST : 1; /*!< [0..0] ESC Reset                                                          */
#else
            __IOM uint32_t ESCRST : 1; /*!< [0..0] ESC Reset                                                          */
            __IOM uint32_t PHYRST : 1; /*!< [1..1] PHY Reset                                                          */
            __IOM uint32_t MIIRST : 1; /*!< [2..2] MII/RMII Converter Reset                                           */
            uint32_t              : 29;
#endif
        } ESCRST_b;
    };

    union
    {
        __IOM uint32_t MIICR0;         /*!< (@ 0x00004004) Port 0 MII/RMII Converter Control Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 27;
            __IOM uint32_t MODE : 5;   /*!< [4..0] Operating Mode Select                                              */
#else
            __IOM uint32_t MODE : 5;   /*!< [4..0] Operating Mode Select                                              */
            uint32_t            : 27;
#endif
        } MIICR0_b;
    };

    union
    {
        __IOM uint32_t MIICR1;         /*!< (@ 0x00004008) Port 1 MII/RMII Converter Control Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 27;
            __IOM uint32_t MODE : 5;   /*!< [4..0] Operating Mode Select                                              */
#else
            __IOM uint32_t MODE : 5;   /*!< [4..0] Operating Mode Select                                              */
            uint32_t            : 27;
#endif
        } MIICR1_b;
    };
    __IM uint32_t RESERVED73;

    union
    {
        __IOM uint32_t PHYLINK;        /*!< (@ 0x00004010) PHY LINK Polarity Setting Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 30;
            __IOM uint32_t LINKPOL1 : 1; /*!< [1..1] CAT1_LINKSTA Pin Polarity                                          */
            __IOM uint32_t LINKPOL0 : 1; /*!< [0..0] CAT0_LINKSTA Pin Polarity                                          */
#else
            __IOM uint32_t LINKPOL0 : 1; /*!< [0..0] CAT0_LINKSTA Pin Polarity                                          */
            __IOM uint32_t LINKPOL1 : 1; /*!< [1..1] CAT1_LINKSTA Pin Polarity                                          */
            uint32_t                : 30;
#endif
        } PHYLINK_b;
    };

    union
    {
        __IOM uint32_t ESCICR;         /*!< (@ 0x00004014) ESC Interrupt Control Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 29;
            __IOM uint32_t ESCIC  : 1; /*!< [2..2] ESCI Interrupt Generating Condition Setting                        */
            __IOM uint32_t SYNC1C : 1; /*!< [1..1] SYNC1 Interrupt Generating Condition Setting                       */
            __IOM uint32_t SYNC0C : 1; /*!< [0..0] SYNC0 Interrupt Generating Condition Setting                       */
#else
            __IOM uint32_t SYNC0C : 1; /*!< [0..0] SYNC0 Interrupt Generating Condition Setting                       */
            __IOM uint32_t SYNC1C : 1; /*!< [1..1] SYNC1 Interrupt Generating Condition Setting                       */
            __IOM uint32_t ESCIC  : 1; /*!< [2..2] ESCI Interrupt Generating Condition Setting                        */
            uint32_t              : 29;
#endif
        } ESCICR_b;
    };

    union
    {
        __IOM uint32_t PHYOFF;         /*!< (@ 0x00004018) PHY Address Offset Setting Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 27;
            __IOM uint32_t OFFSET : 5; /*!< [4..0] PHY Address Offset Setting                                         */
#else
            __IOM uint32_t OFFSET : 5; /*!< [4..0] PHY Address Offset Setting                                         */
            uint32_t              : 27;
#endif
        } PHYOFF_b;
    };

    union
    {
        __IOM uint32_t ESCMR;          /*!< (@ 0x0000401C) ESC Operating Mode Setting Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 31;
            __IOM uint32_t PROMSIZE : 1; /*!< [0..0] EEPROM Size Setting                                                */
#else
            __IOM uint32_t PROMSIZE : 1; /*!< [0..0] EEPROM Size Setting                                                */
            uint32_t                : 31;
#endif
        } ESCMR_b;
    };

    union
    {
        __IOM uint32_t TXSFTR;         /*!< (@ 0x00004020) TX Shift Configuration Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 28;
            __IOM uint32_t TXSFT1 : 2; /*!< [3..2] Port 1 TX Signal Delay Setting                                     */
            __IOM uint32_t TXSFT0 : 2; /*!< [1..0] Port 0 TX Signal Delay Setting                                     */
#else
            __IOM uint32_t TXSFT0 : 2; /*!< [1..0] Port 0 TX Signal Delay Setting                                     */
            __IOM uint32_t TXSFT1 : 2; /*!< [3..2] Port 1 TX Signal Delay Setting                                     */
            uint32_t              : 28;
#endif
        } TXSFTR_b;
    };
} R_ESC_Type;                          /*!< Size = 16420 (0x4024)                                                     */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif                                 /* R_ESC_REG_H */
