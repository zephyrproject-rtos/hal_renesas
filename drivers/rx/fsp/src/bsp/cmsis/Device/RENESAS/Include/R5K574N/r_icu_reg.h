/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ICU_REG_H
#define R_ICU_REG_H

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief R_ICU_IR [IR] (Interrupt request register [0..255])
 */
typedef struct
{
    union
    {
        __IOM uint8_t IR;              /*!< (@ 0x00000000) Interrupt Request Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t          : 7;
            __IOM uint8_t IR : 1;      /*!< [0..0] Interrupt Status Flag                                              */
#else
            __IOM uint8_t IR : 1;      /*!< [0..0] Interrupt Status Flag                                              */
            uint8_t          : 7;
#endif
        } IR_b;
    };
} R_ICU_IR_Type;                       /*!< Size = 1 (0x1)                                                            */

/**
 * @brief R_ICU_IER [IER] (Interrupt request enable register [0..31])
 */
typedef struct
{
    union
    {
        __IOM uint8_t IER;             /*!< (@ 0x00000000) Interrupt Request Enable Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t IEN7 : 1;    /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint8_t IEN6 : 1;    /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint8_t IEN5 : 1;    /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint8_t IEN4 : 1;    /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint8_t IEN3 : 1;    /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint8_t IEN2 : 1;    /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint8_t IEN1 : 1;    /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint8_t IEN0 : 1;    /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint8_t IEN0 : 1;    /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint8_t IEN1 : 1;    /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint8_t IEN2 : 1;    /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint8_t IEN3 : 1;    /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint8_t IEN4 : 1;    /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint8_t IEN5 : 1;    /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint8_t IEN6 : 1;    /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint8_t IEN7 : 1;    /*!< [7..7] Interrupt Request Enable 7                                         */
#endif
        } IER_b;
    };
} R_ICU_IER_Type;                      /*!< Size = 1 (0x1)                                                            */

/**
 * @brief R_ICU_IPR [IPR] (Interrupt source priority register [0..255])
 */
typedef struct
{
    union
    {
        __IOM uint8_t IPR;             /*!< (@ 0x00000000) Interrupt Source Priority Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 3;
            __IOM uint8_t IPR : 5;     /*!< [4..0] Interrupt Priority Level Select                                    */
#else
            __IOM uint8_t IPR : 5;     /*!< [4..0] Interrupt Priority Level Select                                    */
            uint8_t           : 3;
#endif
        } IPR_b;
    };
} R_ICU_IPR_Type;                      /*!< Size = 1 (0x1)                                                            */

/**
 * @brief R_ICU_DTCER [DTCER] (DTC Transfer Request Enable Register [0..255])
 */
typedef struct
{
    union
    {
        __IOM uint8_t DTCER;           /*!< (@ 0x00000000) DTC Transfer Request Enable Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t DTCE : 1;    /*!< [0..0] DTC Transfer Request Enable                                        */
#else
            __IOM uint8_t DTCE : 1;    /*!< [0..0] DTC Transfer Request Enable                                        */
            uint8_t            : 7;
#endif
        } DTCER_b;
    };
} R_ICU_DTCER_Type;                    /*!< Size = 1 (0x1)                                                            */

/**
 * @brief R_ICU_DMRSR [DMRSR] (DMAC trigger select register)
 */
typedef struct
{
    __IOM uint8_t DMRSR;               /*!< (@ 0x00000000) DMAC Trigger Select Register                               */
    __IM uint8_t  RESERVED[3];
} R_ICU_DMRSR_Type;                    /*!< Size = 4 (0x4)                                                            */

/**
 * @brief R_ICU_IRQCR [IRQCR] (IRQ Control Register  [0..31])
 */
typedef struct
{
    union
    {
        __IOM uint8_t IRQCR;           /*!< (@ 0x00000000) IRQ Pin Interrupt Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t FLTEN   : 1; /*!< [7..7] IRQ Digital Noise Filter Enable                                    */
            __IOM uint8_t FCLKSEL : 3; /*!< [6..4] IRQ Digital Noise Filter Sampling Clock Select                     */
            uint8_t               : 1;
            __IOM uint8_t FLTMD   : 1; /*!< [2..2] IRQ Digital Noise Filter Operation Mode Select                     */
            __IOM uint8_t IRQMD   : 2; /*!< [1..0] IRQ Detection Select                                               */
#else
            __IOM uint8_t IRQMD   : 2; /*!< [1..0] IRQ Detection Select                                               */
            __IOM uint8_t FLTMD   : 1; /*!< [2..2] IRQ Digital Noise Filter Operation Mode Select                     */
            uint8_t               : 1;
            __IOM uint8_t FCLKSEL : 3; /*!< [6..4] IRQ Digital Noise Filter Sampling Clock Select                     */
            __IOM uint8_t FLTEN   : 1; /*!< [7..7] IRQ Digital Noise Filter Enable                                    */
#endif
        } IRQCR_b;
    };
} R_ICU_IRQCR_Type;                    /*!< Size = 1 (0x1)                                                            */

/**
 * @brief R_ICU_PIXR [PIXR] (IRQ pin interrupt request register [0..1])
 */
typedef struct
{
    union
    {
        __IOM uint8_t PIXR;            /*!< (@ 0x00000000) Software Configurable Interrupt Request Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t PIR7 : 1;    /*!< [7..7] Software Configurable Interrupt Status flag 7                      */
            __IOM uint8_t PIR6 : 1;    /*!< [6..6] Software Configurable Interrupt Status flag 6                      */
            __IOM uint8_t PIR5 : 1;    /*!< [5..5] Software Configurable Interrupt Status flag 5                      */
            __IOM uint8_t PIR4 : 1;    /*!< [4..4] Software Configurable Interrupt Status flag 4                      */
            __IOM uint8_t PIR3 : 1;    /*!< [3..3] Software Configurable Interrupt Status flag 3                      */
            __IOM uint8_t PIR2 : 1;    /*!< [2..2] Software Configurable Interrupt Status flag 2                      */
            __IOM uint8_t PIR1 : 1;    /*!< [1..1] Software Configurable Interrupt Status flag 1                      */
            __IOM uint8_t PIR0 : 1;    /*!< [0..0] Software Configurable Interrupt Status flag 0                      */
#else
            __IOM uint8_t PIR0 : 1;    /*!< [0..0] Software Configurable Interrupt Status flag 0                      */
            __IOM uint8_t PIR1 : 1;    /*!< [1..1] Software Configurable Interrupt Status flag 1                      */
            __IOM uint8_t PIR2 : 1;    /*!< [2..2] Software Configurable Interrupt Status flag 2                      */
            __IOM uint8_t PIR3 : 1;    /*!< [3..3] Software Configurable Interrupt Status flag 3                      */
            __IOM uint8_t PIR4 : 1;    /*!< [4..4] Software Configurable Interrupt Status flag 4                      */
            __IOM uint8_t PIR5 : 1;    /*!< [5..5] Software Configurable Interrupt Status flag 5                      */
            __IOM uint8_t PIR6 : 1;    /*!< [6..6] Software Configurable Interrupt Status flag 6                      */
            __IOM uint8_t PIR7 : 1;    /*!< [7..7] Software Configurable Interrupt Status flag 7                      */
#endif
        } PIXR_b;
    };
} R_ICU_PIXR_Type;                     /*!< Size = 1 (0x1)                                                            */

/**
 * @brief R_ICU_PIR [PIR] (Software Configurable Interrupt A/B Request Register [0..127])
 */
typedef struct
{
    union
    {
        __IOM uint8_t PIR;             /*!< (@ 0x00000000) Software Configurable Interrupt Request Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t PIR7 : 1;    /*!< [7..7] Software Configurable Interrupt Status Flag 7                      */
            __IOM uint8_t PIR6 : 1;    /*!< [6..6] Software Configurable Interrupt Status Flag 6                      */
            __IOM uint8_t PIR5 : 1;    /*!< [5..5] Software Configurable Interrupt Status Flag 5                      */
            __IOM uint8_t PIR4 : 1;    /*!< [4..4] Software Configurable Interrupt Status Flag 4                      */
            __IOM uint8_t PIR3 : 1;    /*!< [3..3] Software Configurable Interrupt Status Flag 3                      */
            __IOM uint8_t PIR2 : 1;    /*!< [2..2] Software Configurable Interrupt Status Flag 2                      */
            __IOM uint8_t PIR1 : 1;    /*!< [1..1] Software Configurable Interrupt Status Flag 1                      */
            __IOM uint8_t PIR0 : 1;    /*!< [0..0] Software Configurable Interrupt Status Flag 0                      */
#else
            __IOM uint8_t PIR0 : 1;    /*!< [0..0] Software Configurable Interrupt Status Flag 0                      */
            __IOM uint8_t PIR1 : 1;    /*!< [1..1] Software Configurable Interrupt Status Flag 1                      */
            __IOM uint8_t PIR2 : 1;    /*!< [2..2] Software Configurable Interrupt Status Flag 2                      */
            __IOM uint8_t PIR3 : 1;    /*!< [3..3] Software Configurable Interrupt Status Flag 3                      */
            __IOM uint8_t PIR4 : 1;    /*!< [4..4] Software Configurable Interrupt Status Flag 4                      */
            __IOM uint8_t PIR5 : 1;    /*!< [5..5] Software Configurable Interrupt Status Flag 5                      */
            __IOM uint8_t PIR6 : 1;    /*!< [6..6] Software Configurable Interrupt Status Flag 6                      */
            __IOM uint8_t PIR7 : 1;    /*!< [7..7] Software Configurable Interrupt Status Flag 7                      */
#endif
        } PIR_b;
    };
} R_ICU_PIR_Type;                      /*!< Size = 1 (0x1)                                                            */

/**
 * @brief R_ICU_SLIXR [SLIXR] (Software Configurable Interrupt A/B/IRQ source select register [0..15])
 */
typedef struct
{
    __IOM uint16_t SLIXR;              /*!< (@ 0x00000000) Software Configurable Interrupt Source Select
                                        *                  Register                                                   */
} R_ICU_SLIXR_Type;                    /*!< Size = 2 (0x2)                                                            */

/**
 * @brief R_ICU_SLIR [SLIR] (Software Configurable Interrupt A/B source select register [0..111])
 */
typedef struct
{
    __IOM uint16_t SLIR;               /*!< (@ 0x00000000) Software Configurable Interrupt Source Select
                                        *                  Register                                                   */
} R_ICU_SLIR_Type;                     /*!< Size = 2 (0x2)                                                            */

/**
 * @brief R_ICU_SELEXDR [SELEXDR] (EXDMAC trigger select register for [0..1])
 */
typedef struct
{
    union
    {
        __IOM uint32_t SELEXDR;        /*!< (@ 0x00000000) EXDMAC Trigger Select Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 11;
            __IOM uint32_t SLIRQ : 5;  /*!< [20..16] External Pin Interrupt Select                                    */
            __IOM uint32_t SLI   : 16; /*!< [15..0] Interrupt Source Select                                           */
#else
            __IOM uint32_t SLI   : 16; /*!< [15..0] Interrupt Source Select                                           */
            __IOM uint32_t SLIRQ : 5;  /*!< [20..16] External Pin Interrupt Select                                    */
            uint32_t             : 11;
#endif
        } SELEXDR_b;
    };
} R_ICU_SELEXDR_Type;                  /*!< Size = 4 (0x4)                                                            */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_ICU                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Interrupt Controller (R_ICU)
 */

typedef struct                         /*!< (@ 0x87006000) R_ICU Structure                                            */
{
    __IOM R_ICU_IR_Type    IR[256];    /*!< (@ 0x00000000) Interrupt request register [0..255]                        */
    __IOM R_ICU_DTCER_Type DTCER[256]; /*!< (@ 0x00000100) DTC Transfer Request Enable Register [0..255]              */
    __IOM R_ICU_IER_Type   IER[32];    /*!< (@ 0x00000200) Interrupt request enable register [0..31]                  */
    __IM uint32_t          RESERVED[48];

    union
    {
        __IOM uint8_t SWINTR;          /*!< (@ 0x000002E0) Software Interrupt Generation Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t SWINT : 1;   /*!< [0..0] Software Interrupt Generation                                      */
#else
            __IOM uint8_t SWINT : 1;   /*!< [0..0] Software Interrupt Generation                                      */
            uint8_t             : 7;
#endif
        } SWINTR_b;
    };

    union
    {
        __IOM uint8_t SWINT2R;         /*!< (@ 0x000002E1) Software Interrupt 2 Generation Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IOM uint8_t SWINT2 : 1;  /*!< [0..0] Software Interrupt 2 Generation                                    */
#else
            __IOM uint8_t SWINT2 : 1;  /*!< [0..0] Software Interrupt 2 Generation                                    */
            uint8_t              : 7;
#endif
        } SWINT2R_b;
    };
    __IM uint16_t RESERVED1;
    __IM uint32_t RESERVED2[3];

    union
    {
        __IOM uint16_t FIR;            /*!< (@ 0x000002F0) Fast Interrupt Set Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t FIEN : 1;   /*!< [15..15] Fast Interrupt Enable                                            */
            uint16_t            : 7;
            __IOM uint16_t FVCT : 8;   /*!< [7..0] Fast Interrupt Vector Number                                       */
#else
            __IOM uint16_t FVCT : 8;   /*!< [7..0] Fast Interrupt Vector Number                                       */
            uint16_t            : 7;
            __IOM uint16_t FIEN : 1;   /*!< [15..15] Fast Interrupt Enable                                            */
#endif
        } FIR_b;
    };
    __IM uint16_t          RESERVED3;
    __IM uint32_t          RESERVED4[3];
    __IOM R_ICU_IPR_Type   IPR[256];   /*!< (@ 0x00000300) Interrupt source priority register [0..255]                */
    __IOM R_ICU_DMRSR_Type DMRSR[8];   /*!< (@ 0x00000400) DMAC trigger select register                               */
    __IM uint32_t          RESERVED5[64];
    __IOM R_ICU_PIXR_Type  PIXR[2];    /*!< (@ 0x00000520) IRQ pin interrupt request register [0..1]                  */
    __IM uint16_t          RESERVED6;
    __IM uint32_t          RESERVED7[7];

    union
    {
        __IM uint32_t GRPIL0_NS;       /*!< (@ 0x00000540) Group IL0 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPIL0_NS_b;
    };

    union
    {
        __IM uint32_t GRPIL1_NS;       /*!< (@ 0x00000544) Group IL1 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPIL1_NS_b;
    };
    __IM uint32_t RESERVED8[2];

    union
    {
        __IM uint32_t GRPIL0_S;        /*!< (@ 0x00000550) Group IL0 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPIL0_S_b;
    };

    union
    {
        __IM uint32_t GRPIL1_S;        /*!< (@ 0x00000554) Group IL1 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPIL1_S_b;
    };
    __IM uint32_t RESERVED9[2];

    union
    {
        __IOM uint32_t GENIL0_NS;      /*!< (@ 0x00000560) Group IL0 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENIL0_NS_b;
    };

    union
    {
        __IOM uint32_t GENIL1_NS;      /*!< (@ 0x00000564) Group IL1 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENIL1_NS_b;
    };
    __IM uint32_t RESERVED10[2];

    union
    {
        __IOM uint32_t GENIL0_S;       /*!< (@ 0x00000570) Group IL0 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENIL0_S_b;
    };

    union
    {
        __IOM uint32_t GENIL1_S;       /*!< (@ 0x00000574) Group IL1 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENIL1_S_b;
    };
    __IM uint32_t RESERVED11[2];

    union
    {
        __IM uint32_t NMISR;           /*!< (@ 0x00000580) Non-Maskable Interrupt Status Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 13;
            __IM uint32_t MRERDST : 1; /*!< [18..18] Extra MRAM Read Access Error Interrupt Status Flag               */
            __IM uint32_t MRCRDST : 1; /*!< [17..17] Code MRAM Read Access Error Interrupt Status Flag                */
            __IM uint32_t DPFPUST : 1; /*!< [16..16] Double-Precision Floating-Point Exception Status Flag            */
            uint32_t              : 1;
            __IM uint32_t LMST    : 1; /*!< [14..14] Local Memory Error Interrupt Status Flag                         */
            __IM uint32_t CMST    : 1; /*!< [13..13] Common Memory Error Interrupt Status Flag                        */
            __IM uint32_t BUSST   : 1; /*!< [12..12] Bus Error Interrupt Status Flag                                  */
            uint32_t              : 4;
            __IM uint32_t NMIST   : 1; /*!< [7..7] NMI Pin Interrupt Status Flag                                      */
            __IM uint32_t OSTST   : 1; /*!< [6..6] Main Clock Oscillation Stop Detection Interrupt Status
                                        *   Flag                                                                      */
            __IM uint32_t SOSTST : 1;  /*!< [5..5] Sub-Clock Oscillation Stop Detection Interrupt Status
                                        *   Flag                                                                      */
            uint32_t             : 1;
            __IM uint32_t PVD2ST : 1;  /*!< [3..3] Voltage Monitoring 2 Interrupt Status Flag                         */
            __IM uint32_t PVD1ST : 1;  /*!< [2..2] Voltage Monitoring 1 Interrupt Status Flag                         */
            __IM uint32_t WDTST  : 1;  /*!< [1..1] WDT Underflow/Refresh Error Status Flag                            */
            __IM uint32_t IWDTST : 1;  /*!< [0..0] IWDT Underflow/Refresh Error Status Flag                           */
#else
            __IM uint32_t IWDTST : 1;  /*!< [0..0] IWDT Underflow/Refresh Error Status Flag                           */
            __IM uint32_t WDTST  : 1;  /*!< [1..1] WDT Underflow/Refresh Error Status Flag                            */
            __IM uint32_t PVD1ST : 1;  /*!< [2..2] Voltage Monitoring 1 Interrupt Status Flag                         */
            __IM uint32_t PVD2ST : 1;  /*!< [3..3] Voltage Monitoring 2 Interrupt Status Flag                         */
            uint32_t             : 1;
            __IM uint32_t SOSTST : 1;  /*!< [5..5] Sub-Clock Oscillation Stop Detection Interrupt Status
                                        *   Flag                                                                      */
            __IM uint32_t OSTST : 1;   /*!< [6..6] Main Clock Oscillation Stop Detection Interrupt Status
                                        *   Flag                                                                      */
            __IM uint32_t NMIST   : 1; /*!< [7..7] NMI Pin Interrupt Status Flag                                      */
            uint32_t              : 4;
            __IM uint32_t BUSST   : 1; /*!< [12..12] Bus Error Interrupt Status Flag                                  */
            __IM uint32_t CMST    : 1; /*!< [13..13] Common Memory Error Interrupt Status Flag                        */
            __IM uint32_t LMST    : 1; /*!< [14..14] Local Memory Error Interrupt Status Flag                         */
            uint32_t              : 1;
            __IM uint32_t DPFPUST : 1; /*!< [16..16] Double-Precision Floating-Point Exception Status Flag            */
            __IM uint32_t MRCRDST : 1; /*!< [17..17] Code MRAM Read Access Error Interrupt Status Flag                */
            __IM uint32_t MRERDST : 1; /*!< [18..18] Extra MRAM Read Access Error Interrupt Status Flag               */
            uint32_t              : 13;
#endif
        } NMISR_b;
    };

    union
    {
        __IOM uint32_t NMIER;          /*!< (@ 0x00000584) Non-Maskable Interrupt Enable Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 13;
            __IOM uint32_t MRERDEN : 1; /*!< [18..18] Local MRAM Read Access Error Interrupt Enable                    */
            __IOM uint32_t MRCRDEN : 1; /*!< [17..17] Code MRAM Read Access Error Interrupt Enable                     */
            __IOM uint32_t DPFPUEN : 1; /*!< [16..16] Double-Precision Floating-Point Exception Enable                 */
            uint32_t               : 1;
            __IOM uint32_t LMEN    : 1; /*!< [14..14] Local Memory Error Interrupt Enable                              */
            __IOM uint32_t CMEN    : 1; /*!< [13..13] Common Memory Error Interrupt Enable                             */
            __IOM uint32_t BUSEN   : 1; /*!< [12..12] Bus Error Interrupt Enable                                       */
            uint32_t               : 4;
            __IOM uint32_t NMIEN   : 1; /*!< [7..7] NMI Pin Interrupt Enable                                           */
            __IOM uint32_t OSTEN   : 1; /*!< [6..6] Main Clock Oscillation Stop Detection Interrupt Enable             */
            __IOM uint32_t SOSTEN  : 1; /*!< [5..5] Sub-Clock Oscillation Stop Detection Interrupt Enable              */
            uint32_t               : 1;
            __IOM uint32_t PVD2EN  : 1; /*!< [3..3] Voltage Monitoring 2 Interrupt Enable                              */
            __IOM uint32_t PVD1EN  : 1; /*!< [2..2] Voltage Monitoring 1 Interrupt Enable                              */
            __IOM uint32_t WDTEN   : 1; /*!< [1..1] WDT Underflow/Refresh Error Enable                                 */
            __IOM uint32_t IWDTEN  : 1; /*!< [0..0] IWDT Underflow/Refresh Error Enable                                */
#else
            __IOM uint32_t IWDTEN  : 1; /*!< [0..0] IWDT Underflow/Refresh Error Enable                                */
            __IOM uint32_t WDTEN   : 1; /*!< [1..1] WDT Underflow/Refresh Error Enable                                 */
            __IOM uint32_t PVD1EN  : 1; /*!< [2..2] Voltage Monitoring 1 Interrupt Enable                              */
            __IOM uint32_t PVD2EN  : 1; /*!< [3..3] Voltage Monitoring 2 Interrupt Enable                              */
            uint32_t               : 1;
            __IOM uint32_t SOSTEN  : 1; /*!< [5..5] Sub-Clock Oscillation Stop Detection Interrupt Enable              */
            __IOM uint32_t OSTEN   : 1; /*!< [6..6] Main Clock Oscillation Stop Detection Interrupt Enable             */
            __IOM uint32_t NMIEN   : 1; /*!< [7..7] NMI Pin Interrupt Enable                                           */
            uint32_t               : 4;
            __IOM uint32_t BUSEN   : 1; /*!< [12..12] Bus Error Interrupt Enable                                       */
            __IOM uint32_t CMEN    : 1; /*!< [13..13] Common Memory Error Interrupt Enable                             */
            __IOM uint32_t LMEN    : 1; /*!< [14..14] Local Memory Error Interrupt Enable                              */
            uint32_t               : 1;
            __IOM uint32_t DPFPUEN : 1; /*!< [16..16] Double-Precision Floating-Point Exception Enable                 */
            __IOM uint32_t MRCRDEN : 1; /*!< [17..17] Code MRAM Read Access Error Interrupt Enable                     */
            __IOM uint32_t MRERDEN : 1; /*!< [18..18] Local MRAM Read Access Error Interrupt Enable                    */
            uint32_t               : 13;
#endif
        } NMIER_b;
    };

    union
    {
        __IOM uint32_t NMICLR;         /*!< (@ 0x00000588) Non-Maskable Interrupt Status Clear Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 24;
            __IOM uint32_t NMICLR  : 1; /*!< [7..7] NMI Clear                                                          */
            __IOM uint32_t OSTCLR  : 1; /*!< [6..6] OST Clear                                                          */
            __IOM uint32_t SOSTCLR : 1; /*!< [5..5] SOST Clear                                                         */
            uint32_t               : 1;
            __IOM uint32_t PVD2CLR : 1; /*!< [3..3] PVD2 Clear                                                         */
            __IOM uint32_t PVD1CLR : 1; /*!< [2..2] PVD1 Clear                                                         */
            __IOM uint32_t WDTCLR  : 1; /*!< [1..1] WDT Clear                                                          */
            __IOM uint32_t IWDTCLR : 1; /*!< [0..0] IWDT Clear                                                         */
#else
            __IOM uint32_t IWDTCLR : 1; /*!< [0..0] IWDT Clear                                                         */
            __IOM uint32_t WDTCLR  : 1; /*!< [1..1] WDT Clear                                                          */
            __IOM uint32_t PVD1CLR : 1; /*!< [2..2] PVD1 Clear                                                         */
            __IOM uint32_t PVD2CLR : 1; /*!< [3..3] PVD2 Clear                                                         */
            uint32_t               : 1;
            __IOM uint32_t SOSTCLR : 1; /*!< [5..5] SOST Clear                                                         */
            __IOM uint32_t OSTCLR  : 1; /*!< [6..6] OST Clear                                                          */
            __IOM uint32_t NMICLR  : 1; /*!< [7..7] NMI Clear                                                          */
            uint32_t               : 24;
#endif
        } NMICLR_b;
    };
    __IM uint32_t RESERVED12[29];

    union
    {
        __IM uint32_t GRPBL0_NS;       /*!< (@ 0x00000600) Group BL0 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPBL0_NS_b;
    };

    union
    {
        __IM uint32_t GRPBL1_NS;       /*!< (@ 0x00000604) Group BL1 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPBL1_NS_b;
    };
    __IM uint32_t RESERVED13[14];

    union
    {
        __IM uint32_t GRPBL0_S;        /*!< (@ 0x00000640) Group BL0 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPBL0_S_b;
    };

    union
    {
        __IM uint32_t GRPBL1_S;        /*!< (@ 0x00000644) Group BL1 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPBL1_S_b;
    };
    __IM uint32_t RESERVED14[14];

    union
    {
        __IOM uint32_t GENBL0_NS;      /*!< (@ 0x00000680) Group BL0 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENBL0_NS_b;
    };

    union
    {
        __IOM uint32_t GENBL1_NS;      /*!< (@ 0x00000684) Group BL1 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENBL1_NS_b;
    };
    __IM uint32_t RESERVED15[14];

    union
    {
        __IOM uint32_t GENBL0_S;       /*!< (@ 0x000006C0) Group BL0 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENBL0_S_b;
    };

    union
    {
        __IOM uint32_t GENBL1_S;       /*!< (@ 0x000006C4) Group BL1 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENBL1_S_b;
    };
    __IM uint32_t RESERVED16[14];

    union
    {
        __IM uint32_t GRPAL0_NS;       /*!< (@ 0x00000700) Group AL0 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL0_NS_b;
    };

    union
    {
        __IM uint32_t GRPAL1_NS;       /*!< (@ 0x00000704) Group AL1 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL1_NS_b;
    };

    union
    {
        __IM uint32_t GRPAL2_NS;       /*!< (@ 0x00000708) Group AL2 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL2_NS_b;
    };

    union
    {
        __IM uint32_t GRPAL3_NS;       /*!< (@ 0x0000070C) Group AL3 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL3_NS_b;
    };

    union
    {
        __IM uint32_t GRPAL4_NS;       /*!< (@ 0x00000710) Group AL4 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL4_NS_b;
    };

    union
    {
        __IM uint32_t GRPAL5_NS;       /*!< (@ 0x00000714) Group AL5 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL5_NS_b;
    };

    union
    {
        __IM uint32_t GRPAL6_NS;       /*!< (@ 0x00000718) Group AL6 Non-Secure Interrupt Request Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL6_NS_b;
    };
    __IM uint32_t RESERVED17[9];

    union
    {
        __IM uint32_t GRPAL0_S;        /*!< (@ 0x00000740) Group AL0 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL0_S_b;
    };

    union
    {
        __IM uint32_t GRPAL1_S;        /*!< (@ 0x00000744) Group AL1 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL1_S_b;
    };

    union
    {
        __IM uint32_t GRPAL2_S;        /*!< (@ 0x00000748) Group AL2 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL2_S_b;
    };

    union
    {
        __IM uint32_t GRPAL3_S;        /*!< (@ 0x0000074C) Group AL3 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL3_S_b;
    };

    union
    {
        __IM uint32_t GRPAL4_S;        /*!< (@ 0x00000750) Group AL4 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL4_S_b;
    };

    union
    {
        __IM uint32_t GRPAL5_S;        /*!< (@ 0x00000754) Group AL5 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL5_S_b;
    };

    union
    {
        __IM uint32_t GRPAL6_S;        /*!< (@ 0x00000758) Group AL6 Secure Interrupt Request Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] Interrupt Status Flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] Interrupt Status Flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] Interrupt Status Flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] Interrupt Status Flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] Interrupt Status Flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] Interrupt Status Flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] Interrupt Status Flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] Interrupt Status Flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] Interrupt Status Flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] Interrupt Status Flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] Interrupt Status Flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] Interrupt Status Flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] Interrupt Status Flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] Interrupt Status Flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] Interrupt Status Flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] Interrupt Status Flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] Interrupt Status Flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] Interrupt Status Flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] Interrupt Status Flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] Interrupt Status Flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] Interrupt Status Flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] Interrupt Status Flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] Interrupt Status Flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] Interrupt Status Flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] Interrupt Status Flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] Interrupt Status Flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] Interrupt Status Flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] Interrupt Status Flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] Interrupt Status Flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] Interrupt Status Flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] Interrupt Status Flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] Interrupt Status Flag 31                                         */
#endif
        } GRPAL6_S_b;
    };
    __IM uint32_t RESERVED18[9];

    union
    {
        __IOM uint32_t GENAL0_NS;      /*!< (@ 0x00000780) Group AL0 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL0_NS_b;
    };

    union
    {
        __IOM uint32_t GENAL1_NS;      /*!< (@ 0x00000784) Group AL1 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL1_NS_b;
    };

    union
    {
        __IOM uint32_t GENAL2_NS;      /*!< (@ 0x00000788) Group AL2 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL2_NS_b;
    };

    union
    {
        __IOM uint32_t GENAL3_NS;      /*!< (@ 0x0000078C) Group AL3 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL3_NS_b;
    };

    union
    {
        __IOM uint32_t GENAL4_NS;      /*!< (@ 0x00000790) Group AL4 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL4_NS_b;
    };

    union
    {
        __IOM uint32_t GENAL5_NS;      /*!< (@ 0x00000794) Group AL5 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL5_NS_b;
    };

    union
    {
        __IOM uint32_t GENAL6_NS;      /*!< (@ 0x00000798) Group AL6 Non-Secure Interrupt Request Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL6_NS_b;
    };
    __IM uint32_t RESERVED19[9];

    union
    {
        __IOM uint32_t GENAL0_S;       /*!< (@ 0x000007C0) Group AL0 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL0_S_b;
    };

    union
    {
        __IOM uint32_t GENAL1_S;       /*!< (@ 0x000007C4) Group AL1 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL1_S_b;
    };

    union
    {
        __IOM uint32_t GENAL2_S;       /*!< (@ 0x000007C8) Group AL2 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL2_S_b;
    };

    union
    {
        __IOM uint32_t GENAL3_S;       /*!< (@ 0x000007CC) Group AL3 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL3_S_b;
    };

    union
    {
        __IOM uint32_t GENAL4_S;       /*!< (@ 0x000007D0) Group AL4 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL4_S_b;
    };

    union
    {
        __IOM uint32_t GENAL5_S;       /*!< (@ 0x000007D4) Group AL5 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL5_S_b;
    };

    union
    {
        __IOM uint32_t GENAL6_S;       /*!< (@ 0x000007D8) Group AL6 Secure Interrupt Request Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Interrupt Request Enable 0                                         */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Interrupt Request Enable 1                                         */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Interrupt Request Enable 2                                         */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Interrupt Request Enable 3                                         */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Interrupt Request Enable 4                                         */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Interrupt Request Enable 5                                         */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Interrupt Request Enable 6                                         */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Interrupt Request Enable 7                                         */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Interrupt Request Enable 8                                         */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Interrupt Request Enable 9                                         */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Interrupt Request Enable 10                                      */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Interrupt Request Enable 11                                      */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Interrupt Request Enable 12                                      */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Interrupt Request Enable 13                                      */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Interrupt Request Enable 14                                      */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Interrupt Request Enable 15                                      */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Interrupt Request Enable 16                                      */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Interrupt Request Enable 17                                      */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Interrupt Request Enable 18                                      */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Interrupt Request Enable 19                                      */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Interrupt Request Enable 20                                      */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Interrupt Request Enable 21                                      */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Interrupt Request Enable 22                                      */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Interrupt Request Enable 23                                      */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Interrupt Request Enable 24                                      */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Interrupt Request Enable 25                                      */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Interrupt Request Enable 26                                      */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Interrupt Request Enable 27                                      */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Interrupt Request Enable 28                                      */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Interrupt Request Enable 29                                      */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Interrupt Request Enable 30                                      */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Interrupt Request Enable 31                                      */
#endif
        } GENAL6_S_b;
    };
    __IM uint32_t        RESERVED20[9];
    __IOM R_ICU_PIR_Type PIR[128];     /*!< (@ 0x00000800) Software Configurable Interrupt A/B Request Register
                                        *                  [0..127]                                                   */
    __IM uint32_t          RESERVED21[32];
    __IOM R_ICU_SLIXR_Type SLIXR[16];  /*!< (@ 0x00000900) Software Configurable Interrupt A/B/IRQ source
                                        *                  select register [0..15]                                    */
    __IOM R_ICU_SLIR_Type SLIR[112];   /*!< (@ 0x00000920) Software Configurable Interrupt A/B source select
                                        *                  register [0..111]                                          */

    union
    {
        __IOM uint8_t SLIPRCR_NS;      /*!< (@ 0x00000A00) Non-Secure Software Configurable Interrupt Source
                                        *                  Select Register Write Protect Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t WPRC : 1;    /*!< [0..0] Software Configurable Interrupt Source Select Register
                                        *   Write Protect                                                             */
#else
            __IOM uint8_t WPRC : 1;    /*!< [0..0] Software Configurable Interrupt Source Select Register
                                        *   Write Protect                                                             */
            uint8_t : 7;
#endif
        } SLIPRCR_NS_b;
    };
    __IM uint8_t  RESERVED22;
    __IM uint16_t RESERVED23;

    union
    {
        __IOM uint8_t SLIPRCR_S;       /*!< (@ 0x00000A04) Secure Software Configurable Interrupt Source
                                        *                  Select Register Write Protect Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t WPRC : 1;    /*!< [0..0] Software Configurable Interrupt Source Select Register
                                        *   Write Protect                                                             */
#else
            __IOM uint8_t WPRC : 1;    /*!< [0..0] Software Configurable Interrupt Source Select Register
                                        *   Write Protect                                                             */
            uint8_t : 7;
#endif
        } SLIPRCR_S_b;
    };
    __IM uint8_t  RESERVED24;
    __IM uint16_t RESERVED25;
    __IM uint32_t RESERVED26[125];

    union
    {
        __IOM uint8_t CLPCR;           /*!< (@ 0x00000BFC) CPU Low Power Control Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 7;
            __IOM uint8_t DEEPSLEEP : 1; /*!< [0..0] Deep Sleep Select                                                  */
#else
            __IOM uint8_t DEEPSLEEP : 1; /*!< [0..0] Deep Sleep Select                                                  */
            uint8_t                 : 7;
#endif
        } CLPCR_b;
    };
    __IM uint8_t  RESERVED27;
    __IM uint16_t RESERVED28;
    __IM uint32_t RESERVED29[3];

    union
    {
        __IOM uint8_t NMICR;           /*!< (@ 0x00000C0C) NMI Pin Interrupt Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t NFLTEN   : 1; /*!< [7..7] NMI Digital Noise Filter Enable                                    */
            __IOM uint8_t NFCLKSEL : 3; /*!< [6..4] NMI Digital Noise Filter Sampling Clock                            */
            uint8_t                : 1;
            __IOM uint8_t NFLTMD   : 1; /*!< [2..2] NMI Digital Noise Filter Operation Mode Select                     */
            uint8_t                : 1;
            __IOM uint8_t NMIMD    : 1; /*!< [0..0] NMI Detection Select                                               */
#else
            __IOM uint8_t NMIMD    : 1; /*!< [0..0] NMI Detection Select                                               */
            uint8_t                : 1;
            __IOM uint8_t NFLTMD   : 1; /*!< [2..2] NMI Digital Noise Filter Operation Mode Select                     */
            uint8_t                : 1;
            __IOM uint8_t NFCLKSEL : 3; /*!< [6..4] NMI Digital Noise Filter Sampling Clock                            */
            __IOM uint8_t NFLTEN   : 1; /*!< [7..7] NMI Digital Noise Filter Enable                                    */
#endif
        } NMICR_b;
    };
    __IM uint8_t             RESERVED30;
    __IM uint16_t            RESERVED31;
    __IM uint32_t            RESERVED32[4];
    __IOM R_ICU_IRQCR_Type   IRQCR[32];  /*!< (@ 0x00000C20) IRQ Control Register [0..31]                               */
    __IOM R_ICU_SELEXDR_Type SELEXDR[2]; /*!< (@ 0x00000C40) EXDMAC trigger select register for [0..1]                  */
} R_ICU_Type;                            /*!< Size = 3144 (0xc48)                                                       */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_ICU_REG_H */
