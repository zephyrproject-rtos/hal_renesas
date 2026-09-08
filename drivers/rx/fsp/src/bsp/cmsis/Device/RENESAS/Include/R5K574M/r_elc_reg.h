/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ELC_REG_H
#define R_ELC_REG_H

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief R_ELC_ELSEGR [ELSEGR] (Event Link Software Event Generation Register)
 */
typedef struct
{
    union
    {
        __IOM uint8_t BY;              /*!< (@ 0x00000000) Event Link Software Event Generation Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint8_t  WI : 1;      /*!< [7..7] ELSEGR Register Write Disable                                      */
            __IOM uint8_t WE : 1;      /*!< [6..6] SEG Bit Write Enable                                               */
            uint8_t          : 5;
            __OM uint8_t SEG : 1;      /*!< [0..0] Software Event Generation                                          */
#else
            __OM uint8_t SEG : 1;      /*!< [0..0] Software Event Generation                                          */
            uint8_t          : 5;
            __IOM uint8_t WE : 1;      /*!< [6..6] SEG Bit Write Enable                                               */
            __OM uint8_t  WI : 1;      /*!< [7..7] ELSEGR Register Write Disable                                      */
#endif
        } BY_b;
    };
    __IM uint8_t RESERVED[3];
} R_ELC_ELSEGR_Type;                   /*!< Size = 4 (0x4)                                                            */

/**
 * @brief R_ELC_ELSR [ELSR] (Event Link Setting Register [0..91])
 */
typedef struct
{
    union
    {
        __IOM uint16_t HA;             /*!< (@ 0x00000000) Event Link Setting Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t           : 6;
            __IOM uint16_t ELS : 10;   /*!< [9..0] Event Link Select                                                  */
#else
            __IOM uint16_t ELS : 10;   /*!< [9..0] Event Link Select                                                  */
            uint16_t           : 6;
#endif
        } HA_b;
    };
    __IM uint16_t RESERVED;
} R_ELC_ELSR_Type;                     /*!< Size = 4 (0x4)                                                            */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_ELC                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief event link controller (R_ELC)
 */

typedef struct                         /*!< (@ 0x87801000) R_ELC Structure                                            */
{
    union
    {
        __IOM uint8_t ELCR;            /*!< (@ 0x00000000) Event Link Controller Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t ELCON : 1;   /*!< [7..7] All Event Link Enable                                              */
            uint8_t             : 7;
#else
            uint8_t             : 7;
            __IOM uint8_t ELCON : 1;   /*!< [7..7] All Event Link Enable                                              */
#endif
        } ELCR_b;
    };
    __IM uint8_t            RESERVED;
    __IM uint16_t           RESERVED1;
    __IOM R_ELC_ELSEGR_Type ELSEGR[4]; /*!< (@ 0x00000004) Event Link Software Event Generation Register              */
    __IM uint32_t           RESERVED2[7];

    union
    {
        __IOM uint32_t ELCSARA;        /*!< (@ 0x00000030) Event Link Controller Security Attribution Register
                                        *                  A                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 12;
            __IOM uint32_t ELOPD : 1;   /*!< [19..19] Event Link Option Setting Register D Security Attribution
                                         *   Target register: ELOPD                                                    */
            __IOM uint32_t ELOPC : 1;   /*!< [18..18] Event Link Option Setting Register C Security Attribution
                                         *   Target register: ELOPC                                                    */
            __IOM uint32_t ELOPB : 1;   /*!< [17..17] Event Link Option Setting Register B Security AttributionTarget
                                         *   register: ELOPB                                                           */
            __IOM uint32_t ELOPA : 1;   /*!< [16..16] Event Link Option Setting Register A Security Attribution
                                         *   Target register: ELOPA                                                    */
            uint32_t               : 11;
            __IOM uint32_t ELSEGR3 : 1; /*!< [4..4] Event Link Software Event Generation Register 3 Security
                                         *   Attribution Target register: ELSEGR3                                      */
            __IOM uint32_t ELSEGR2 : 1; /*!< [3..3] Event Link Software Event Generation Register 2 Security
                                         *   Attribution Target register: ELSEGR2                                      */
            __IOM uint32_t ELSEGR1 : 1; /*!< [2..2] Event Link Software Event Generation Register 1 Security
                                         *   Attribution Target register: ELSEGR1                                      */
            __IOM uint32_t ELSEGR0 : 1; /*!< [1..1] Event Link Software Event Generation Register 0 Security
                                         *   Attribution Target register: ELSEGR0                                      */
            __IOM uint32_t ELCR : 1;    /*!< [0..0] Event Link Controller Register Security Attribution Target
                                         *   register: ELCR                                                            */
#else
            __IOM uint32_t ELCR : 1;    /*!< [0..0] Event Link Controller Register Security Attribution Target
                                         *   register: ELCR                                                            */
            __IOM uint32_t ELSEGR0 : 1; /*!< [1..1] Event Link Software Event Generation Register 0 Security
                                         *   Attribution Target register: ELSEGR0                                      */
            __IOM uint32_t ELSEGR1 : 1; /*!< [2..2] Event Link Software Event Generation Register 1 Security
                                         *   Attribution Target register: ELSEGR1                                      */
            __IOM uint32_t ELSEGR2 : 1; /*!< [3..3] Event Link Software Event Generation Register 2 Security
                                         *   Attribution Target register: ELSEGR2                                      */
            __IOM uint32_t ELSEGR3 : 1; /*!< [4..4] Event Link Software Event Generation Register 3 Security
                                         *   Attribution Target register: ELSEGR3                                      */
            uint32_t             : 11;
            __IOM uint32_t ELOPA : 1;   /*!< [16..16] Event Link Option Setting Register A Security Attribution
                                         *   Target register: ELOPA                                                    */
            __IOM uint32_t ELOPB : 1;   /*!< [17..17] Event Link Option Setting Register B Security AttributionTarget
                                         *   register: ELOPB                                                           */
            __IOM uint32_t ELOPC : 1;   /*!< [18..18] Event Link Option Setting Register C Security Attribution
                                         *   Target register: ELOPC                                                    */
            __IOM uint32_t ELOPD : 1;   /*!< [19..19] Event Link Option Setting Register D Security Attribution
                                         *   Target register: ELOPD                                                    */
            uint32_t : 12;
#endif
        } ELCSARA_b;
    };

    union
    {
        __IOM uint32_t ELCSARB;        /*!< (@ 0x00000034) Event Link Controller Security Attribution Register
                                        *                  B                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 5;
            __IOM uint32_t ELSR26 : 1; /*!< [26..26] Event Link Setting Register 26 Security Attribution
                                        *   Target register: ELSR26                                                   */
            __IOM uint32_t ELSR25 : 1; /*!< [25..25] Event Link Setting Register 25 Security Attribution
                                        *   Target register: ELSR25                                                   */
            __IOM uint32_t ELSR24 : 1; /*!< [24..24] Event Link Setting Register 24 Security Attribution
                                        *   Target register: ELSR24                                                   */
            __IOM uint32_t ELSR23 : 1; /*!< [23..23] Event Link Setting Register 23 Security Attribution
                                        *   Target register: ELSR23                                                   */
            __IOM uint32_t ELSR22 : 1; /*!< [22..22] Event Link Setting Register 22 Security Attribution
                                        *   Target register: ELSR22                                                   */
            __IOM uint32_t ELSR21 : 1; /*!< [21..21] Event Link Setting Register 21 Security Attribution
                                        *   Target register: ELSR21                                                   */
            __IOM uint32_t ELSR20 : 1; /*!< [20..20] Event Link Setting Register 20 Security Attribution
                                        *   Target register: ELSR20                                                   */
            __IOM uint32_t ELSR19 : 1; /*!< [19..19] Event Link Setting Register 19 Security Attribution
                                        *   Target register: ELSR19                                                   */
            __IOM uint32_t ELSR18 : 1; /*!< [18..18] Event Link Setting Register 18 Security Attribution
                                        *   Target register: ELSR18                                                   */
            __IOM uint32_t ELSR17 : 1; /*!< [17..17] Event Link Setting Register 17 Security Attribution
                                        *   Target register: ELSR17                                                   */
            __IOM uint32_t ELSR16 : 1; /*!< [16..16] Event Link Setting Register 16 Security Attribution
                                        *   Target register: ELSR16                                                   */
            __IOM uint32_t ELSR15 : 1; /*!< [15..15] Event Link Setting Register 15 Security Attribution
                                        *   Target register: ELSR15                                                   */
            __IOM uint32_t ELSR14 : 1; /*!< [14..14] Event Link Setting Register 14 Security Attribution
                                        *   Target register: ELSR14                                                   */
            __IOM uint32_t ELSR13 : 1; /*!< [13..13] Event Link Setting Register 13 Security Attribution
                                        *   Target register: ELSR13                                                   */
            __IOM uint32_t ELSR12 : 1; /*!< [12..12] Event Link Setting Register 12 Security Attribution
                                        *   Target register: ELSR12                                                   */
            __IOM uint32_t ELSR11 : 1; /*!< [11..11] Event Link Setting Register 11 Security Attribution
                                        *   Target register: ELSR11                                                   */
            __IOM uint32_t ELSR10 : 1; /*!< [10..10] Event Link Setting Register 10 Security Attribution
                                        *   Target register: ELSR10                                                   */
            __IOM uint32_t ELSR9 : 1;  /*!< [9..9] Event Link Setting Register 9 Security Attribution Target
                                        *   register: ELSR9                                                           */
            __IOM uint32_t ELSR8 : 1;  /*!< [8..8] Event Link Setting Register 8 Security Attribution Target
                                        *   register: ELSR8                                                           */
            __IOM uint32_t ELSR7 : 1;  /*!< [7..7] Event Link Setting Register 7 Security Attribution Target
                                        *   register: ELSR7                                                           */
            __IOM uint32_t ELSR6 : 1;  /*!< [6..6] Event Link Setting Register 6 Security Attribution Target
                                        *   register: ELSR6                                                           */
            __IOM uint32_t ELSR5 : 1;  /*!< [5..5] Event Link Setting Register 5 Security Attribution Target
                                        *   register: ELSR5                                                           */
            __IOM uint32_t ELSR4 : 1;  /*!< [4..4] Event Link Setting Register 4 Security Attribution Target
                                        *   register: ELSR4                                                           */
            __IOM uint32_t ELSR3 : 1;  /*!< [3..3] Event Link Setting Register 3 Security Attribution Target
                                        *   register: ELSR3                                                           */
            __IOM uint32_t ELSR2 : 1;  /*!< [2..2] Event Link Setting Register 2 Security Attribution Target
                                        *   register: ELSR2                                                           */
            __IOM uint32_t ELSR1 : 1;  /*!< [1..1] Event Link Setting Register 1 Security Attribution Target
                                        *   register: ELSR1                                                           */
            __IOM uint32_t ELSR0 : 1;  /*!< [0..0] Event Link Setting Register 0 Security Attribution Target
                                        *   register: ELSR0                                                           */
#else
            __IOM uint32_t ELSR0 : 1;  /*!< [0..0] Event Link Setting Register 0 Security Attribution Target
                                        *   register: ELSR0                                                           */
            __IOM uint32_t ELSR1 : 1;  /*!< [1..1] Event Link Setting Register 1 Security Attribution Target
                                        *   register: ELSR1                                                           */
            __IOM uint32_t ELSR2 : 1;  /*!< [2..2] Event Link Setting Register 2 Security Attribution Target
                                        *   register: ELSR2                                                           */
            __IOM uint32_t ELSR3 : 1;  /*!< [3..3] Event Link Setting Register 3 Security Attribution Target
                                        *   register: ELSR3                                                           */
            __IOM uint32_t ELSR4 : 1;  /*!< [4..4] Event Link Setting Register 4 Security Attribution Target
                                        *   register: ELSR4                                                           */
            __IOM uint32_t ELSR5 : 1;  /*!< [5..5] Event Link Setting Register 5 Security Attribution Target
                                        *   register: ELSR5                                                           */
            __IOM uint32_t ELSR6 : 1;  /*!< [6..6] Event Link Setting Register 6 Security Attribution Target
                                        *   register: ELSR6                                                           */
            __IOM uint32_t ELSR7 : 1;  /*!< [7..7] Event Link Setting Register 7 Security Attribution Target
                                        *   register: ELSR7                                                           */
            __IOM uint32_t ELSR8 : 1;  /*!< [8..8] Event Link Setting Register 8 Security Attribution Target
                                        *   register: ELSR8                                                           */
            __IOM uint32_t ELSR9 : 1;  /*!< [9..9] Event Link Setting Register 9 Security Attribution Target
                                        *   register: ELSR9                                                           */
            __IOM uint32_t ELSR10 : 1; /*!< [10..10] Event Link Setting Register 10 Security Attribution
                                        *   Target register: ELSR10                                                   */
            __IOM uint32_t ELSR11 : 1; /*!< [11..11] Event Link Setting Register 11 Security Attribution
                                        *   Target register: ELSR11                                                   */
            __IOM uint32_t ELSR12 : 1; /*!< [12..12] Event Link Setting Register 12 Security Attribution
                                        *   Target register: ELSR12                                                   */
            __IOM uint32_t ELSR13 : 1; /*!< [13..13] Event Link Setting Register 13 Security Attribution
                                        *   Target register: ELSR13                                                   */
            __IOM uint32_t ELSR14 : 1; /*!< [14..14] Event Link Setting Register 14 Security Attribution
                                        *   Target register: ELSR14                                                   */
            __IOM uint32_t ELSR15 : 1; /*!< [15..15] Event Link Setting Register 15 Security Attribution
                                        *   Target register: ELSR15                                                   */
            __IOM uint32_t ELSR16 : 1; /*!< [16..16] Event Link Setting Register 16 Security Attribution
                                        *   Target register: ELSR16                                                   */
            __IOM uint32_t ELSR17 : 1; /*!< [17..17] Event Link Setting Register 17 Security Attribution
                                        *   Target register: ELSR17                                                   */
            __IOM uint32_t ELSR18 : 1; /*!< [18..18] Event Link Setting Register 18 Security Attribution
                                        *   Target register: ELSR18                                                   */
            __IOM uint32_t ELSR19 : 1; /*!< [19..19] Event Link Setting Register 19 Security Attribution
                                        *   Target register: ELSR19                                                   */
            __IOM uint32_t ELSR20 : 1; /*!< [20..20] Event Link Setting Register 20 Security Attribution
                                        *   Target register: ELSR20                                                   */
            __IOM uint32_t ELSR21 : 1; /*!< [21..21] Event Link Setting Register 21 Security Attribution
                                        *   Target register: ELSR21                                                   */
            __IOM uint32_t ELSR22 : 1; /*!< [22..22] Event Link Setting Register 22 Security Attribution
                                        *   Target register: ELSR22                                                   */
            __IOM uint32_t ELSR23 : 1; /*!< [23..23] Event Link Setting Register 23 Security Attribution
                                        *   Target register: ELSR23                                                   */
            __IOM uint32_t ELSR24 : 1; /*!< [24..24] Event Link Setting Register 24 Security Attribution
                                        *   Target register: ELSR24                                                   */
            __IOM uint32_t ELSR25 : 1; /*!< [25..25] Event Link Setting Register 25 Security Attribution
                                        *   Target register: ELSR25                                                   */
            __IOM uint32_t ELSR26 : 1; /*!< [26..26] Event Link Setting Register 26 Security Attribution
                                        *   Target register: ELSR26                                                   */
            uint32_t : 5;
#endif
        } ELCSARB_b;
    };

    union
    {
        __IOM uint32_t ELCSARC;        /*!< (@ 0x00000038) Event Link Controller Security Attribution Register
                                        *                  C                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ELSR63 : 1; /*!< [31..31] Event Link Setting Register 63 Security Attribution
                                        *   Target register: ELSR63                                                   */
            __IOM uint32_t ELSR62 : 1; /*!< [30..30] Event Link Setting Register 62 Security Attribution
                                        *   Target register: ELSR62                                                   */
            __IOM uint32_t ELSR61 : 1; /*!< [29..29] Event Link Setting Register 61 Security Attribution
                                        *   Target register: ELSR61                                                   */
            __IOM uint32_t ELSR60 : 1; /*!< [28..28] Event Link Setting Register 60 Security Attribution
                                        *   Target register: ELSR60                                                   */
            __IOM uint32_t ELSR59 : 1; /*!< [27..27] Event Link Setting Register 59 Security Attribution
                                        *   Target register: ELSR59                                                   */
            __IOM uint32_t ELSR58 : 1; /*!< [26..26] Event Link Setting Register 58 Security Attribution
                                        *   Target register: ELSR58                                                   */
            __IOM uint32_t ELSR57 : 1; /*!< [25..25] Event Link Setting Register 57 Security Attribution
                                        *   Target register: ELSR57                                                   */
            __IOM uint32_t ELSR56 : 1; /*!< [24..24] Event Link Setting Register 56 Security Attribution
                                        *   Target register: ELSR56                                                   */
            __IOM uint32_t ELSR55 : 1; /*!< [23..23] Event Link Setting Register 55 Security Attribution
                                        *   Target register: ELSR55                                                   */
            __IOM uint32_t ELSR54 : 1; /*!< [22..22] Event Link Setting Register 54 Security Attribution
                                        *   Target register: ELSR54                                                   */
            __IOM uint32_t ELSR53 : 1; /*!< [21..21] Event Link Setting Register 53 Security Attribution
                                        *   Target register: ELSR53                                                   */
            __IOM uint32_t ELSR52 : 1; /*!< [20..20] Event Link Setting Register 52 Security Attribution
                                        *   Target register: ELSR52                                                   */
            __IOM uint32_t ELSR51 : 1; /*!< [19..19] Event Link Setting Register 51 Security Attribution
                                        *   Target register: ELSR51                                                   */
            __IOM uint32_t ELSR50 : 1; /*!< [18..18] Event Link Setting Register 50 Security Attribution
                                        *   Target register: ELSR50                                                   */
            uint32_t              : 2;
            __IOM uint32_t ELSR47 : 1; /*!< [15..15] Event Link Setting Register 15 Security Attribution
                                        *   Target register: ELSR47                                                   */
            __IOM uint32_t ELSR46 : 1; /*!< [14..14] Event Link Setting Register 14 Security Attribution
                                        *   Target register: ELSR46                                                   */
            uint32_t : 14;
#else
            uint32_t              : 14;
            __IOM uint32_t ELSR46 : 1; /*!< [14..14] Event Link Setting Register 14 Security Attribution
                                        *   Target register: ELSR46                                                   */
            __IOM uint32_t ELSR47 : 1; /*!< [15..15] Event Link Setting Register 15 Security Attribution
                                        *   Target register: ELSR47                                                   */
            uint32_t              : 2;
            __IOM uint32_t ELSR50 : 1; /*!< [18..18] Event Link Setting Register 50 Security Attribution
                                        *   Target register: ELSR50                                                   */
            __IOM uint32_t ELSR51 : 1; /*!< [19..19] Event Link Setting Register 51 Security Attribution
                                        *   Target register: ELSR51                                                   */
            __IOM uint32_t ELSR52 : 1; /*!< [20..20] Event Link Setting Register 52 Security Attribution
                                        *   Target register: ELSR52                                                   */
            __IOM uint32_t ELSR53 : 1; /*!< [21..21] Event Link Setting Register 53 Security Attribution
                                        *   Target register: ELSR53                                                   */
            __IOM uint32_t ELSR54 : 1; /*!< [22..22] Event Link Setting Register 54 Security Attribution
                                        *   Target register: ELSR54                                                   */
            __IOM uint32_t ELSR55 : 1; /*!< [23..23] Event Link Setting Register 55 Security Attribution
                                        *   Target register: ELSR55                                                   */
            __IOM uint32_t ELSR56 : 1; /*!< [24..24] Event Link Setting Register 56 Security Attribution
                                        *   Target register: ELSR56                                                   */
            __IOM uint32_t ELSR57 : 1; /*!< [25..25] Event Link Setting Register 57 Security Attribution
                                        *   Target register: ELSR57                                                   */
            __IOM uint32_t ELSR58 : 1; /*!< [26..26] Event Link Setting Register 58 Security Attribution
                                        *   Target register: ELSR58                                                   */
            __IOM uint32_t ELSR59 : 1; /*!< [27..27] Event Link Setting Register 59 Security Attribution
                                        *   Target register: ELSR59                                                   */
            __IOM uint32_t ELSR60 : 1; /*!< [28..28] Event Link Setting Register 60 Security Attribution
                                        *   Target register: ELSR60                                                   */
            __IOM uint32_t ELSR61 : 1; /*!< [29..29] Event Link Setting Register 61 Security Attribution
                                        *   Target register: ELSR61                                                   */
            __IOM uint32_t ELSR62 : 1; /*!< [30..30] Event Link Setting Register 62 Security Attribution
                                        *   Target register: ELSR62                                                   */
            __IOM uint32_t ELSR63 : 1; /*!< [31..31] Event Link Setting Register 63 Security Attribution
                                        *   Target register: ELSR63                                                   */
#endif
        } ELCSARC_b;
    };

    union
    {
        __IOM uint32_t ELCSARD;        /*!< (@ 0x0000003C) Event Link Controller Security Attribution Register
                                        *                  D                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 4;
            __IOM uint32_t ELSR91 : 1; /*!< [27..27] Event Link Setting Register 91 Security Attribution
                                        *   Target register: ELSR91                                                   */
            __IOM uint32_t ELSR90 : 1; /*!< [26..26] Event Link Setting Register 90 Security Attribution
                                        *   Target register: ELSR90                                                   */
            __IOM uint32_t ELSR89 : 1; /*!< [25..25] Event Link Setting Register 89 Security Attribution
                                        *   Target register: ELSR89                                                   */
            __IOM uint32_t ELSR88 : 1; /*!< [24..24] Event Link Setting Register 88 Security Attribution
                                        *   Target register: ELSR88                                                   */
            uint32_t              : 9;
            __IOM uint32_t ELSR78 : 1; /*!< [14..14] Event Link Setting Register 78 Security Attribution
                                        *   Target register: ELSR78                                                   */
            __IOM uint32_t ELSR77 : 1; /*!< [13..13] Event Link Setting Register 77 Security Attribution
                                        *   Target register: ELSR77                                                   */
            __IOM uint32_t ELSR76 : 1; /*!< [12..12] Event Link Setting Register 76 Security Attribution
                                        *   Target register: ELSR76                                                   */
            __IOM uint32_t ELSR75 : 1; /*!< [11..11] Event Link Setting Register 75 Security Attribution
                                        *   Target register: ELSR75                                                   */
            __IOM uint32_t ELSR74 : 1; /*!< [10..10] Event Link Setting Register 74 Security Attribution
                                        *   Target register: ELSR74                                                   */
            __IOM uint32_t ELSR73 : 1; /*!< [9..9] Event Link Setting Register 73 Security Attribution Target
                                        *   register: ELSR73                                                          */
            __IOM uint32_t ELSR72 : 1; /*!< [8..8] Event Link Setting Register 72 Security Attribution Target
                                        *   register: ELSR72                                                          */
            __IOM uint32_t ELSR71 : 1; /*!< [7..7] Event Link Setting Register 71 Security Attribution Target
                                        *   register: ELSR71                                                          */
            __IOM uint32_t ELSR70 : 1; /*!< [6..6] Event Link Setting Register 70 Security Attribution Target
                                        *   register: ELSR70                                                          */
            __IOM uint32_t ELSR69 : 1; /*!< [5..5] Event Link Setting Register 69 Security Attribution Target
                                        *   register: ELSR69                                                          */
            __IOM uint32_t ELSR68 : 1; /*!< [4..4] Event Link Setting Register 68 Security Attribution Target
                                        *   register: ELSR68                                                          */
            __IOM uint32_t ELSR67 : 1; /*!< [3..3] Event Link Setting Register 67 Security Attribution Target
                                        *   register: ELSR67                                                          */
            __IOM uint32_t ELSR66 : 1; /*!< [2..2] Event Link Setting Register 66 Security Attribution Target
                                        *   register: ELSR66                                                          */
            __IOM uint32_t ELSR65 : 1; /*!< [1..1] Event Link Setting Register 65 Security Attribution Target
                                        *   register: ELSR65                                                          */
            __IOM uint32_t ELSR64 : 1; /*!< [0..0] Event Link Setting Register 64 Security Attribution Target
                                        *   register: ELSR64                                                          */
#else
            __IOM uint32_t ELSR64 : 1; /*!< [0..0] Event Link Setting Register 64 Security Attribution Target
                                        *   register: ELSR64                                                          */
            __IOM uint32_t ELSR65 : 1; /*!< [1..1] Event Link Setting Register 65 Security Attribution Target
                                        *   register: ELSR65                                                          */
            __IOM uint32_t ELSR66 : 1; /*!< [2..2] Event Link Setting Register 66 Security Attribution Target
                                        *   register: ELSR66                                                          */
            __IOM uint32_t ELSR67 : 1; /*!< [3..3] Event Link Setting Register 67 Security Attribution Target
                                        *   register: ELSR67                                                          */
            __IOM uint32_t ELSR68 : 1; /*!< [4..4] Event Link Setting Register 68 Security Attribution Target
                                        *   register: ELSR68                                                          */
            __IOM uint32_t ELSR69 : 1; /*!< [5..5] Event Link Setting Register 69 Security Attribution Target
                                        *   register: ELSR69                                                          */
            __IOM uint32_t ELSR70 : 1; /*!< [6..6] Event Link Setting Register 70 Security Attribution Target
                                        *   register: ELSR70                                                          */
            __IOM uint32_t ELSR71 : 1; /*!< [7..7] Event Link Setting Register 71 Security Attribution Target
                                        *   register: ELSR71                                                          */
            __IOM uint32_t ELSR72 : 1; /*!< [8..8] Event Link Setting Register 72 Security Attribution Target
                                        *   register: ELSR72                                                          */
            __IOM uint32_t ELSR73 : 1; /*!< [9..9] Event Link Setting Register 73 Security Attribution Target
                                        *   register: ELSR73                                                          */
            __IOM uint32_t ELSR74 : 1; /*!< [10..10] Event Link Setting Register 74 Security Attribution
                                        *   Target register: ELSR74                                                   */
            __IOM uint32_t ELSR75 : 1; /*!< [11..11] Event Link Setting Register 75 Security Attribution
                                        *   Target register: ELSR75                                                   */
            __IOM uint32_t ELSR76 : 1; /*!< [12..12] Event Link Setting Register 76 Security Attribution
                                        *   Target register: ELSR76                                                   */
            __IOM uint32_t ELSR77 : 1; /*!< [13..13] Event Link Setting Register 77 Security Attribution
                                        *   Target register: ELSR77                                                   */
            __IOM uint32_t ELSR78 : 1; /*!< [14..14] Event Link Setting Register 78 Security Attribution
                                        *   Target register: ELSR78                                                   */
            uint32_t              : 9;
            __IOM uint32_t ELSR88 : 1; /*!< [24..24] Event Link Setting Register 88 Security Attribution
                                        *   Target register: ELSR88                                                   */
            __IOM uint32_t ELSR89 : 1; /*!< [25..25] Event Link Setting Register 89 Security Attribution
                                        *   Target register: ELSR89                                                   */
            __IOM uint32_t ELSR90 : 1; /*!< [26..26] Event Link Setting Register 90 Security Attribution
                                        *   Target register: ELSR90                                                   */
            __IOM uint32_t ELSR91 : 1; /*!< [27..27] Event Link Setting Register 91 Security Attribution
                                        *   Target register: ELSR91                                                   */
            uint32_t : 4;
#endif
        } ELCSARD_b;
    };
    __IM uint32_t RESERVED3[20];

    union
    {
        __IOM uint8_t ELOPA;           /*!< (@ 0x00000090) Event Link Option Setting Register A                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 4;
            __IOM uint8_t CMT1MD : 2;  /*!< [3..2] CMT1 Operation Select                                              */
            uint8_t              : 2;
#else
            uint8_t              : 2;
            __IOM uint8_t CMT1MD : 2;  /*!< [3..2] CMT1 Operation Select                                              */
            uint8_t              : 4;
#endif
        } ELOPA_b;
    };
    __IM uint8_t  RESERVED4;
    __IM uint16_t RESERVED5;

    union
    {
        __IOM uint8_t ELOPB;           /*!< (@ 0x00000094) Event Link Option Setting Register B                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 6;
            __IOM uint8_t CMTW0MD : 2; /*!< [1..0] CMTW0 Operation Select                                             */
#else
            __IOM uint8_t CMTW0MD : 2; /*!< [1..0] CMTW0 Operation Select                                             */
            uint8_t               : 6;
#endif
        } ELOPB_b;
    };
    __IM uint8_t  RESERVED6;
    __IM uint16_t RESERVED7;

    union
    {
        __IOM uint8_t ELOPC;           /*!< (@ 0x00000098) Event Link Option Setting Register C                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 4;
            __IOM uint8_t TMR1MD : 2;  /*!< [3..2] TMR1 Operation Select                                              */
            __IOM uint8_t TMR0MD : 2;  /*!< [1..0] TMR0 Operation Select                                              */
#else
            __IOM uint8_t TMR0MD : 2;  /*!< [1..0] TMR0 Operation Select                                              */
            __IOM uint8_t TMR1MD : 2;  /*!< [3..2] TMR1 Operation Select                                              */
            uint8_t              : 4;
#endif
        } ELOPC_b;
    };
    __IM uint8_t  RESERVED8;
    __IM uint16_t RESERVED9;

    union
    {
        __IOM uint8_t ELOPD;           /*!< (@ 0x0000009C) Event Link Option Setting Register D                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 4;
            __IOM uint8_t TMR3MD : 2;  /*!< [3..2] TMR3 Operation Select                                              */
            __IOM uint8_t TMR2MD : 2;  /*!< [1..0] TMR2 Operation Select                                              */
#else
            __IOM uint8_t TMR2MD : 2;  /*!< [1..0] TMR2 Operation Select                                              */
            __IOM uint8_t TMR3MD : 2;  /*!< [3..2] TMR3 Operation Select                                              */
            uint8_t              : 4;
#endif
        } ELOPD_b;
    };
    __IM uint8_t  RESERVED10;
    __IM uint16_t RESERVED11;
    __IM uint32_t RESERVED12[24];

    __IOM R_ELC_ELSR_Type ELSR[92];    /*!< (@ 0x00000100) Event Link Setting Register [0..91]                        */
} R_ELC_Type;                          /*!< Size = 440 (0x1b8)                                                        */

#endif /* R_ELC_REG_H */
