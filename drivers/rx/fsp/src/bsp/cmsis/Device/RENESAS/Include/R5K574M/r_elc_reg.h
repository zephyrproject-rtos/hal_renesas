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
        __IOM uint8_t BY;              /*!< (@ 0x00000000) Software Event Generation Register                         */

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
 * @brief R_ELC_ELSR [ELSR] (Event Link Setting Register)
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
 * @brief Event Link Controller (R_ELC)
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
        __IOM uint32_t ELCSARA;        /*!< (@ 0x00000030) ELC Security Attribution Register A                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 12;
            __IOM uint32_t ELOPD   : 1; /*!< [19..19] ELOPD Security Attribution                                       */
            __IOM uint32_t ELOPC   : 1; /*!< [18..18] ELOPC Security Attribution                                       */
            __IOM uint32_t ELOPB   : 1; /*!< [17..17] ELOPB Security Attribution                                       */
            __IOM uint32_t ELOPA   : 1; /*!< [16..16] ELOPA Security Attribution                                       */
            uint32_t               : 11;
            __IOM uint32_t ELSEGR3 : 1; /*!< [4..4] ELSEGR3 Security Attribution                                       */
            __IOM uint32_t ELSEGR2 : 1; /*!< [3..3] ELSEGR2 Security Attribution                                       */
            __IOM uint32_t ELSEGR1 : 1; /*!< [2..2] ELSEGR1 Security Attribution                                       */
            __IOM uint32_t ELSEGR0 : 1; /*!< [1..1] ELSEGR0 Security Attribution                                       */
            __IOM uint32_t ELCR    : 1; /*!< [0..0] ELCR Security Attribution                                          */
#else
            __IOM uint32_t ELCR    : 1; /*!< [0..0] ELCR Security Attribution                                          */
            __IOM uint32_t ELSEGR0 : 1; /*!< [1..1] ELSEGR0 Security Attribution                                       */
            __IOM uint32_t ELSEGR1 : 1; /*!< [2..2] ELSEGR1 Security Attribution                                       */
            __IOM uint32_t ELSEGR2 : 1; /*!< [3..3] ELSEGR2 Security Attribution                                       */
            __IOM uint32_t ELSEGR3 : 1; /*!< [4..4] ELSEGR3 Security Attribution                                       */
            uint32_t               : 11;
            __IOM uint32_t ELOPA   : 1; /*!< [16..16] ELOPA Security Attribution                                       */
            __IOM uint32_t ELOPB   : 1; /*!< [17..17] ELOPB Security Attribution                                       */
            __IOM uint32_t ELOPC   : 1; /*!< [18..18] ELOPC Security Attribution                                       */
            __IOM uint32_t ELOPD   : 1; /*!< [19..19] ELOPD Security Attribution                                       */
            uint32_t               : 12;
#endif
        } ELCSARA_b;
    };

    union
    {
        __IOM uint32_t ELCSARB;        /*!< (@ 0x00000034) ELC Security Attribution Register B                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 5;
            __IOM uint32_t ELSR26 : 1; /*!< [26..26] ELSR26 Security Attribution                                      */
            __IOM uint32_t ELSR25 : 1; /*!< [25..25] ELSR25 Security Attribution                                      */
            __IOM uint32_t ELSR24 : 1; /*!< [24..24] ELSR24 Security Attribution                                      */
            __IOM uint32_t ELSR23 : 1; /*!< [23..23] ELSR23 Security Attribution                                      */
            __IOM uint32_t ELSR22 : 1; /*!< [22..22] ELSR22 Security Attribution                                      */
            __IOM uint32_t ELSR21 : 1; /*!< [21..21] ELSR21 Security Attribution                                      */
            __IOM uint32_t ELSR20 : 1; /*!< [20..20] ELSR20 Security Attribution                                      */
            __IOM uint32_t ELSR19 : 1; /*!< [19..19] ELSR19 Security Attribution                                      */
            __IOM uint32_t ELSR18 : 1; /*!< [18..18] ELSR18 Security Attribution                                      */
            __IOM uint32_t ELSR17 : 1; /*!< [17..17] ELSR17 Security Attribution                                      */
            __IOM uint32_t ELSR16 : 1; /*!< [16..16] ELSR16 Security Attribution                                      */
            __IOM uint32_t ELSR15 : 1; /*!< [15..15] ELSR15 Security Attribution                                      */
            __IOM uint32_t ELSR14 : 1; /*!< [14..14] ELSR14 Security Attribution                                      */
            __IOM uint32_t ELSR13 : 1; /*!< [13..13] ELSR13 Security Attribution                                      */
            __IOM uint32_t ELSR12 : 1; /*!< [12..12] ELSR12 Security Attribution                                      */
            __IOM uint32_t ELSR11 : 1; /*!< [11..11] ELSR11 Security Attribution                                      */
            __IOM uint32_t ELSR10 : 1; /*!< [10..10] ELSR10 Security Attribution                                      */
            __IOM uint32_t ELSR9  : 1; /*!< [9..9] ELSR9 Security Attribution                                         */
            __IOM uint32_t ELSR8  : 1; /*!< [8..8] ELSR8 Security Attribution                                         */
            __IOM uint32_t ELSR7  : 1; /*!< [7..7] ELSR7 Security Attribution                                         */
            __IOM uint32_t ELSR6  : 1; /*!< [6..6] ELSR6 Security Attribution                                         */
            __IOM uint32_t ELSR5  : 1; /*!< [5..5] ELSR5 Security Attribution                                         */
            __IOM uint32_t ELSR4  : 1; /*!< [4..4] ELSR4 Security Attribution                                         */
            __IOM uint32_t ELSR3  : 1; /*!< [3..3] ELSR3 Security Attribution                                         */
            __IOM uint32_t ELSR2  : 1; /*!< [2..2] ELSR2 Security Attribution                                         */
            __IOM uint32_t ELSR1  : 1; /*!< [1..1] ELSR1 Security Attribution                                         */
            __IOM uint32_t ELSR0  : 1; /*!< [0..0] ELSR0 Security Attribution                                         */
#else
            __IOM uint32_t ELSR0  : 1; /*!< [0..0] ELSR0 Security Attribution                                         */
            __IOM uint32_t ELSR1  : 1; /*!< [1..1] ELSR1 Security Attribution                                         */
            __IOM uint32_t ELSR2  : 1; /*!< [2..2] ELSR2 Security Attribution                                         */
            __IOM uint32_t ELSR3  : 1; /*!< [3..3] ELSR3 Security Attribution                                         */
            __IOM uint32_t ELSR4  : 1; /*!< [4..4] ELSR4 Security Attribution                                         */
            __IOM uint32_t ELSR5  : 1; /*!< [5..5] ELSR5 Security Attribution                                         */
            __IOM uint32_t ELSR6  : 1; /*!< [6..6] ELSR6 Security Attribution                                         */
            __IOM uint32_t ELSR7  : 1; /*!< [7..7] ELSR7 Security Attribution                                         */
            __IOM uint32_t ELSR8  : 1; /*!< [8..8] ELSR8 Security Attribution                                         */
            __IOM uint32_t ELSR9  : 1; /*!< [9..9] ELSR9 Security Attribution                                         */
            __IOM uint32_t ELSR10 : 1; /*!< [10..10] ELSR10 Security Attribution                                      */
            __IOM uint32_t ELSR11 : 1; /*!< [11..11] ELSR11 Security Attribution                                      */
            __IOM uint32_t ELSR12 : 1; /*!< [12..12] ELSR12 Security Attribution                                      */
            __IOM uint32_t ELSR13 : 1; /*!< [13..13] ELSR13 Security Attribution                                      */
            __IOM uint32_t ELSR14 : 1; /*!< [14..14] ELSR14 Security Attribution                                      */
            __IOM uint32_t ELSR15 : 1; /*!< [15..15] ELSR15 Security Attribution                                      */
            __IOM uint32_t ELSR16 : 1; /*!< [16..16] ELSR16 Security Attribution                                      */
            __IOM uint32_t ELSR17 : 1; /*!< [17..17] ELSR17 Security Attribution                                      */
            __IOM uint32_t ELSR18 : 1; /*!< [18..18] ELSR18 Security Attribution                                      */
            __IOM uint32_t ELSR19 : 1; /*!< [19..19] ELSR19 Security Attribution                                      */
            __IOM uint32_t ELSR20 : 1; /*!< [20..20] ELSR20 Security Attribution                                      */
            __IOM uint32_t ELSR21 : 1; /*!< [21..21] ELSR21 Security Attribution                                      */
            __IOM uint32_t ELSR22 : 1; /*!< [22..22] ELSR22 Security Attribution                                      */
            __IOM uint32_t ELSR23 : 1; /*!< [23..23] ELSR23 Security Attribution                                      */
            __IOM uint32_t ELSR24 : 1; /*!< [24..24] ELSR24 Security Attribution                                      */
            __IOM uint32_t ELSR25 : 1; /*!< [25..25] ELSR25 Security Attribution                                      */
            __IOM uint32_t ELSR26 : 1; /*!< [26..26] ELSR26 Security Attribution                                      */
            uint32_t              : 5;
#endif
        } ELCSARB_b;
    };

    union
    {
        __IOM uint32_t ELCSARC;        /*!< (@ 0x00000038) ELC Security Attribution Register C                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ELSR63 : 1; /*!< [31..31] ELSR63 Security Attribution                                      */
            __IOM uint32_t ELSR62 : 1; /*!< [30..30] ELSR62 Security Attribution                                      */
            __IOM uint32_t ELSR61 : 1; /*!< [29..29] ELSR61 Security Attribution                                      */
            __IOM uint32_t ELSR60 : 1; /*!< [28..28] ELSR60 Security Attribution                                      */
            __IOM uint32_t ELSR59 : 1; /*!< [27..27] ELSR59 Security Attribution                                      */
            __IOM uint32_t ELSR58 : 1; /*!< [26..26] ELSR58 Security Attribution                                      */
            __IOM uint32_t ELSR57 : 1; /*!< [25..25] ELSR57 Security Attribution                                      */
            __IOM uint32_t ELSR56 : 1; /*!< [24..24] ELSR56 Security Attribution                                      */
            __IOM uint32_t ELSR55 : 1; /*!< [23..23] ELSR55 Security Attribution                                      */
            __IOM uint32_t ELSR54 : 1; /*!< [22..22] ELSR54 Security Attribution                                      */
            __IOM uint32_t ELSR53 : 1; /*!< [21..21] ELSR53 Security Attribution                                      */
            __IOM uint32_t ELSR52 : 1; /*!< [20..20] ELSR52 Security Attribution                                      */
            __IOM uint32_t ELSR51 : 1; /*!< [19..19] ELSR51 Security Attribution                                      */
            __IOM uint32_t ELSR50 : 1; /*!< [18..18] ELSR50 Security Attribution                                      */
            uint32_t              : 2;
            __IOM uint32_t ELSR47 : 1; /*!< [15..15] ELSR47 Security Attribution                                      */
            __IOM uint32_t ELSR46 : 1; /*!< [14..14] ELSR46 Security Attribution                                      */
            uint32_t              : 14;
#else
            uint32_t              : 14;
            __IOM uint32_t ELSR46 : 1; /*!< [14..14] ELSR46 Security Attribution                                      */
            __IOM uint32_t ELSR47 : 1; /*!< [15..15] ELSR47 Security Attribution                                      */
            uint32_t              : 2;
            __IOM uint32_t ELSR50 : 1; /*!< [18..18] ELSR50 Security Attribution                                      */
            __IOM uint32_t ELSR51 : 1; /*!< [19..19] ELSR51 Security Attribution                                      */
            __IOM uint32_t ELSR52 : 1; /*!< [20..20] ELSR52 Security Attribution                                      */
            __IOM uint32_t ELSR53 : 1; /*!< [21..21] ELSR53 Security Attribution                                      */
            __IOM uint32_t ELSR54 : 1; /*!< [22..22] ELSR54 Security Attribution                                      */
            __IOM uint32_t ELSR55 : 1; /*!< [23..23] ELSR55 Security Attribution                                      */
            __IOM uint32_t ELSR56 : 1; /*!< [24..24] ELSR56 Security Attribution                                      */
            __IOM uint32_t ELSR57 : 1; /*!< [25..25] ELSR57 Security Attribution                                      */
            __IOM uint32_t ELSR58 : 1; /*!< [26..26] ELSR58 Security Attribution                                      */
            __IOM uint32_t ELSR59 : 1; /*!< [27..27] ELSR59 Security Attribution                                      */
            __IOM uint32_t ELSR60 : 1; /*!< [28..28] ELSR60 Security Attribution                                      */
            __IOM uint32_t ELSR61 : 1; /*!< [29..29] ELSR61 Security Attribution                                      */
            __IOM uint32_t ELSR62 : 1; /*!< [30..30] ELSR62 Security Attribution                                      */
            __IOM uint32_t ELSR63 : 1; /*!< [31..31] ELSR63 Security Attribution                                      */
#endif
        } ELCSARC_b;
    };

    union
    {
        __IOM uint32_t ELCSARD;        /*!< (@ 0x0000003C) ELC Security Attribution Register D                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 4;
            __IOM uint32_t ELSR91 : 1; /*!< [27..27] ELSR91 Security Attribution                                      */
            __IOM uint32_t ELSR90 : 1; /*!< [26..26] ELSR90 Security Attribution                                      */
            __IOM uint32_t ELSR89 : 1; /*!< [25..25] ELSR89 Security Attribution                                      */
            __IOM uint32_t ELSR88 : 1; /*!< [24..24] ELSR88 Security Attribution                                      */
            uint32_t              : 9;
            __IOM uint32_t ELSR78 : 1; /*!< [14..14] ELSR78 Security Attribution                                      */
            __IOM uint32_t ELSR77 : 1; /*!< [13..13] ELSR77 Security Attribution                                      */
            __IOM uint32_t ELSR76 : 1; /*!< [12..12] ELSR76 Security Attribution                                      */
            __IOM uint32_t ELSR75 : 1; /*!< [11..11] ELSR75 Security Attribution                                      */
            __IOM uint32_t ELSR74 : 1; /*!< [10..10] ELSR74 Security Attribution                                      */
            __IOM uint32_t ELSR73 : 1; /*!< [9..9] ELSR73 Security Attribution                                        */
            __IOM uint32_t ELSR72 : 1; /*!< [8..8] ELSR72 Security Attribution                                        */
            __IOM uint32_t ELSR71 : 1; /*!< [7..7] ELSR71 Security Attribution                                        */
            __IOM uint32_t ELSR70 : 1; /*!< [6..6] ELSR70 Security Attribution                                        */
            __IOM uint32_t ELSR69 : 1; /*!< [5..5] ELSR69 Security Attribution                                        */
            __IOM uint32_t ELSR68 : 1; /*!< [4..4] ELSR68 Security Attribution                                        */
            __IOM uint32_t ELSR67 : 1; /*!< [3..3] ELSR67 Security Attribution                                        */
            __IOM uint32_t ELSR66 : 1; /*!< [2..2] ELSR66 Security Attribution                                        */
            __IOM uint32_t ELSR65 : 1; /*!< [1..1] ELSR65 Security Attribution                                        */
            __IOM uint32_t ELSR64 : 1; /*!< [0..0] ELSR64 Security Attribution                                        */
#else
            __IOM uint32_t ELSR64 : 1; /*!< [0..0] ELSR64 Security Attribution                                        */
            __IOM uint32_t ELSR65 : 1; /*!< [1..1] ELSR65 Security Attribution                                        */
            __IOM uint32_t ELSR66 : 1; /*!< [2..2] ELSR66 Security Attribution                                        */
            __IOM uint32_t ELSR67 : 1; /*!< [3..3] ELSR67 Security Attribution                                        */
            __IOM uint32_t ELSR68 : 1; /*!< [4..4] ELSR68 Security Attribution                                        */
            __IOM uint32_t ELSR69 : 1; /*!< [5..5] ELSR69 Security Attribution                                        */
            __IOM uint32_t ELSR70 : 1; /*!< [6..6] ELSR70 Security Attribution                                        */
            __IOM uint32_t ELSR71 : 1; /*!< [7..7] ELSR71 Security Attribution                                        */
            __IOM uint32_t ELSR72 : 1; /*!< [8..8] ELSR72 Security Attribution                                        */
            __IOM uint32_t ELSR73 : 1; /*!< [9..9] ELSR73 Security Attribution                                        */
            __IOM uint32_t ELSR74 : 1; /*!< [10..10] ELSR74 Security Attribution                                      */
            __IOM uint32_t ELSR75 : 1; /*!< [11..11] ELSR75 Security Attribution                                      */
            __IOM uint32_t ELSR76 : 1; /*!< [12..12] ELSR76 Security Attribution                                      */
            __IOM uint32_t ELSR77 : 1; /*!< [13..13] ELSR77 Security Attribution                                      */
            __IOM uint32_t ELSR78 : 1; /*!< [14..14] ELSR78 Security Attribution                                      */
            uint32_t              : 9;
            __IOM uint32_t ELSR88 : 1; /*!< [24..24] ELSR88 Security Attribution                                      */
            __IOM uint32_t ELSR89 : 1; /*!< [25..25] ELSR89 Security Attribution                                      */
            __IOM uint32_t ELSR90 : 1; /*!< [26..26] ELSR90 Security Attribution                                      */
            __IOM uint32_t ELSR91 : 1; /*!< [27..27] ELSR91 Security Attribution                                      */
            uint32_t              : 4;
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
    __IM uint8_t          RESERVED10;
    __IM uint16_t         RESERVED11;
    __IM uint32_t         RESERVED12[24];
    __IOM R_ELC_ELSR_Type ELSR[92];    /*!< (@ 0x00000100) Event Link Setting Register                                */
} R_ELC_Type;                          /*!< Size = 624 (0x270)                                                        */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_ELC_REG_H */
