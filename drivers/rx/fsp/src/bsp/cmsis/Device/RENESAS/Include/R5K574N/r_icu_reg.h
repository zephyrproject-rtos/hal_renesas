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
        __IOM uint8_t IR;              /*!< (@ 0x00000000) Interrupt request register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t          : 7;
            __IOM uint8_t IR : 1;      /*!< [0..0] Interrupt status flag                                              */
#else
            __IOM uint8_t IR : 1;      /*!< [0..0] Interrupt status flag                                              */
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
        __IOM uint8_t IER;             /*!< (@ 0x00000000) Interrupt request enable register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t IEN7 : 1;    /*!< [7..7] Interrupt request enable bit 7                                     */
            __IOM uint8_t IEN6 : 1;    /*!< [6..6] Interrupt request enable bit 6                                     */
            __IOM uint8_t IEN5 : 1;    /*!< [5..5] Interrupt request enable bit 5                                     */
            __IOM uint8_t IEN4 : 1;    /*!< [4..4] Interrupt request enable bit 4                                     */
            __IOM uint8_t IEN3 : 1;    /*!< [3..3] Interrupt request enable bit 3                                     */
            __IOM uint8_t IEN2 : 1;    /*!< [2..2] Interrupt request enable bit 2                                     */
            __IOM uint8_t IEN1 : 1;    /*!< [1..1] Interrupt request enable bit 1                                     */
            __IOM uint8_t IEN0 : 1;    /*!< [0..0] Interrupt request enable bit 0                                     */
#else
            __IOM uint8_t IEN0 : 1;    /*!< [0..0] Interrupt request enable bit 0                                     */
            __IOM uint8_t IEN1 : 1;    /*!< [1..1] Interrupt request enable bit 1                                     */
            __IOM uint8_t IEN2 : 1;    /*!< [2..2] Interrupt request enable bit 2                                     */
            __IOM uint8_t IEN3 : 1;    /*!< [3..3] Interrupt request enable bit 3                                     */
            __IOM uint8_t IEN4 : 1;    /*!< [4..4] Interrupt request enable bit 4                                     */
            __IOM uint8_t IEN5 : 1;    /*!< [5..5] Interrupt request enable bit 5                                     */
            __IOM uint8_t IEN6 : 1;    /*!< [6..6] Interrupt request enable bit 6                                     */
            __IOM uint8_t IEN7 : 1;    /*!< [7..7] Interrupt request enable bit 7                                     */
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
        __IOM uint8_t IPR;             /*!< (@ 0x00000000) Interrupt source priority register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 3;
            __IOM uint8_t IPR : 5;     /*!< [4..0] Interrupt priority level select bit                                */
#else
            __IOM uint8_t IPR : 5;     /*!< [4..0] Interrupt priority level select bit                                */
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
        __IOM uint8_t DTCER;           /*!< (@ 0x00000000) DTC transfer request enable register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t DTCE : 1;    /*!< [0..0] DTC transfer request enable bit                                    */
#else
            __IOM uint8_t DTCE : 1;    /*!< [0..0] DTC transfer request enable bit                                    */
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
    __IOM uint8_t DMRSR;               /*!< (@ 0x00000000) DMAC trigger select register                               */
    __IM uint8_t  RESERVED[3];
} R_ICU_DMRSR_Type;                    /*!< Size = 4 (0x4)                                                            */

/**
 * @brief R_ICU_IRQCR [IRQCR] (IRQ Control Register  [0..31])
 */
typedef struct
{
    union
    {
        __IOM uint8_t IRQCR;           /*!< (@ 0x00000000) IRQ Control Register                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t FLTEN   : 1; /*!< [7..7] Digital filter enable bit                                          */
            __IOM uint8_t FCLKSEL : 3; /*!< [6..4] Digital filter sampling clock select bit                           */
            uint8_t               : 1;
            __IOM uint8_t FLTMD   : 1; /*!< [2..2] Digital filter mode select bit                                     */
            __IOM uint8_t IRQMD   : 2; /*!< [1..0] IRQ detection select bit                                           */
#else
            __IOM uint8_t IRQMD   : 2; /*!< [1..0] IRQ detection select bit                                           */
            __IOM uint8_t FLTMD   : 1; /*!< [2..2] Digital filter mode select bit                                     */
            uint8_t               : 1;
            __IOM uint8_t FCLKSEL : 3; /*!< [6..4] Digital filter sampling clock select bit                           */
            __IOM uint8_t FLTEN   : 1; /*!< [7..7] Digital filter enable bit                                          */
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
        __IOM uint8_t PIXR;            /*!< (@ 0x00000000) IRQ pin interrupt request register                         */

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
        __IOM uint8_t PIR;             /*!< (@ 0x00000000) Software configurable interrupt A/B statsu flag            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t PIR7 : 1;    /*!< [7..7] Software configurable interrupt status flag 7                      */
            __IOM uint8_t PIR6 : 1;    /*!< [6..6] Software configurable interrupt status flag 6                      */
            __IOM uint8_t PIR5 : 1;    /*!< [5..5] Software configurable interrupt status flag 5                      */
            __IOM uint8_t PIR4 : 1;    /*!< [4..4] Software configurable interrupt status flag 4                      */
            __IOM uint8_t PIR3 : 1;    /*!< [3..3] Software configurable interrupt status flag 3                      */
            __IOM uint8_t PIR2 : 1;    /*!< [2..2] Software configurable interrupt status flag 2                      */
            __IOM uint8_t PIR1 : 1;    /*!< [1..1] Software configurable interrupt status flag 1                      */
            __IOM uint8_t PIR0 : 1;    /*!< [0..0] Software configurable interrupt status flag 0                      */
#else
            __IOM uint8_t PIR0 : 1;    /*!< [0..0] Software configurable interrupt status flag 0                      */
            __IOM uint8_t PIR1 : 1;    /*!< [1..1] Software configurable interrupt status flag 1                      */
            __IOM uint8_t PIR2 : 1;    /*!< [2..2] Software configurable interrupt status flag 2                      */
            __IOM uint8_t PIR3 : 1;    /*!< [3..3] Software configurable interrupt status flag 3                      */
            __IOM uint8_t PIR4 : 1;    /*!< [4..4] Software configurable interrupt status flag 4                      */
            __IOM uint8_t PIR5 : 1;    /*!< [5..5] Software configurable interrupt status flag 5                      */
            __IOM uint8_t PIR6 : 1;    /*!< [6..6] Software configurable interrupt status flag 6                      */
            __IOM uint8_t PIR7 : 1;    /*!< [7..7] Software configurable interrupt status flag 7                      */
#endif
        } PIR_b;
    };
} R_ICU_PIR_Type;                      /*!< Size = 1 (0x1)                                                            */

/**
 * @brief R_ICU_SLIXR [SLIXR] (Software Configurable Interrupt A/B/IRQ source select register [0..15])
 */
typedef struct
{
    __IOM uint16_t SLIXR;              /*!< (@ 0x00000000) Software Configurable Interrupt A/B/IRQ source
                                        *                  select register                                            */
} R_ICU_SLIXR_Type;                    /*!< Size = 2 (0x2)                                                            */

/**
 * @brief R_ICU_SLIR [SLIR] (Software Configurable Interrupt A/B source select register [0..111])
 */
typedef struct
{
    __IOM uint16_t SLIR;               /*!< (@ 0x00000000) Software Configurable Interrupt A/B source select
                                        *                  register                                                   */
} R_ICU_SLIR_Type;                     /*!< Size = 2 (0x2)                                                            */

/**
 * @brief R_ICU_SELEXDR [SELEXDR] (EXDMAC trigger select register for [0..1])
 */
typedef struct
{
    union
    {
        __IOM uint32_t SELEXDR;        /*!< (@ 0x00000000) EXDMAC trigger select register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 11;
            __IOM uint32_t SLIRQ : 5;  /*!< [20..16] IRQ pin select bit                                               */
            __IOM uint32_t SLI   : 16; /*!< [15..0] EXDMACch n trigger select bit Interrupt number assigned
                                        *   to start EXDMAC channel n                                                 */
#else
            __IOM uint32_t SLI : 16;   /*!< [15..0] EXDMACch n trigger select bit Interrupt number assigned
                                        *   to start EXDMAC channel n                                                 */
            __IOM uint32_t SLIRQ : 5;  /*!< [20..16] IRQ pin select bit                                               */
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
 * @brief ICU Control (R_ICU)
 */

typedef struct                         /*!< (@ 0x87006000) R_ICU Structure                                            */
{
    __IOM R_ICU_IR_Type    IR[256];    /*!< (@ 0x00000000) Interrupt request register [0..255]                        */
    __IOM R_ICU_DTCER_Type DTCER[256]; /*!< (@ 0x00000100) DTC Transfer Request Enable Register [0..255]              */
    __IOM R_ICU_IER_Type   IER[32];    /*!< (@ 0x00000200) Interrupt request enable register [0..31]                  */
    __IM uint32_t          RESERVED[48];

    union
    {
        __IOM uint8_t SWINTR;          /*!< (@ 0x000002E0) Software interrupt generation register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t SWINT : 1;   /*!< [0..0] Software interrupt generation bit                                  */
#else
            __IOM uint8_t SWINT : 1;   /*!< [0..0] Software interrupt generation bit                                  */
            uint8_t             : 7;
#endif
        } SWINTR_b;
    };

    union
    {
        __IOM uint8_t SWINT2R;         /*!< (@ 0x000002E1) Software interrupt 2 generation register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IOM uint8_t SWINT2 : 1;  /*!< [0..0] Software interrupt 2 generation bit                                */
#else
            __IOM uint8_t SWINT2 : 1;  /*!< [0..0] Software interrupt 2 generation bit                                */
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
            __IOM uint16_t FIEN : 1;   /*!< [15..15] Fast interrupt enable bit                                        */
            uint16_t            : 7;
            __IOM uint16_t FVCT : 8;   /*!< [7..0] Fast interrupt vector number bit Specify vector number
                                        *   for fast interrupt                                                        */
#else
            __IOM uint16_t FVCT : 8;   /*!< [7..0] Fast interrupt vector number bit Specify vector number
                                        *   for fast interrupt                                                        */
            uint16_t            : 7;
            __IOM uint16_t FIEN : 1;   /*!< [15..15] Fast interrupt enable bit                                        */
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
    __IM uint32_t          RESERVED7[11];

    union
    {
        __IM uint32_t GRPIL0;          /*!< (@ 0x00000550) Group IL0 Secure interrupt request register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
#endif
        } GRPIL0_b;
    };
    __IM uint32_t RESERVED8[7];

    union
    {
        __IOM uint32_t GENIL0;         /*!< (@ 0x00000570) Group IL0 Secure interrupt request enable register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
#endif
        } GENIL0_b;
    };
    __IM uint32_t RESERVED9[3];

    union
    {
        __IM uint32_t NMISR;           /*!< (@ 0x00000580) Non-maskable interrupt status register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 13;
            __IM uint32_t MRERDST : 1; /*!< [18..18] MRAM MRE Read Error Interrupt Status Flag                        */
            __IM uint32_t MRCRDST : 1; /*!< [17..17] MRAM MRC Read Error Interrupt Status Flag                        */
            __IM uint32_t DPFPUST : 1; /*!< [16..16] FPU exception status flag                                        */
            uint32_t              : 1;
            __IM uint32_t LMST    : 1; /*!< [14..14] Local memory error interrupt status flag                         */
            __IM uint32_t CMST    : 1; /*!< [13..13] Common memory error interrupt status flag                        */
            __IM uint32_t BUSST   : 1; /*!< [12..12] Bus error interrupt status flag                                  */
            uint32_t              : 4;
            __IM uint32_t NMIST   : 1; /*!< [7..7] NMI status flag                                                    */
            __IM uint32_t OSTST   : 1; /*!< [6..6] Oscillation stop detection interrupt status flag                   */
            __IM uint32_t SOSTST  : 1; /*!< [5..5] Sub oscillation stop detection interrupt status flag               */
            uint32_t              : 1;
            __IM uint32_t PVD2ST  : 1; /*!< [3..3] PVD2 interrupt status flag                                         */
            __IM uint32_t PVD1ST  : 1; /*!< [2..2] PVD1 interrupt status flag                                         */
            __IM uint32_t WDTST   : 1; /*!< [1..1] WDT underflow/refresh error status flag                            */
            __IM uint32_t IWDTST  : 1; /*!< [0..0] IWDT underflow/refresh error status flag                           */
#else
            __IM uint32_t IWDTST  : 1; /*!< [0..0] IWDT underflow/refresh error status flag                           */
            __IM uint32_t WDTST   : 1; /*!< [1..1] WDT underflow/refresh error status flag                            */
            __IM uint32_t PVD1ST  : 1; /*!< [2..2] PVD1 interrupt status flag                                         */
            __IM uint32_t PVD2ST  : 1; /*!< [3..3] PVD2 interrupt status flag                                         */
            uint32_t              : 1;
            __IM uint32_t SOSTST  : 1; /*!< [5..5] Sub oscillation stop detection interrupt status flag               */
            __IM uint32_t OSTST   : 1; /*!< [6..6] Oscillation stop detection interrupt status flag                   */
            __IM uint32_t NMIST   : 1; /*!< [7..7] NMI status flag                                                    */
            uint32_t              : 4;
            __IM uint32_t BUSST   : 1; /*!< [12..12] Bus error interrupt status flag                                  */
            __IM uint32_t CMST    : 1; /*!< [13..13] Common memory error interrupt status flag                        */
            __IM uint32_t LMST    : 1; /*!< [14..14] Local memory error interrupt status flag                         */
            uint32_t              : 1;
            __IM uint32_t DPFPUST : 1; /*!< [16..16] FPU exception status flag                                        */
            __IM uint32_t MRCRDST : 1; /*!< [17..17] MRAM MRC Read Error Interrupt Status Flag                        */
            __IM uint32_t MRERDST : 1; /*!< [18..18] MRAM MRE Read Error Interrupt Status Flag                        */
            uint32_t              : 13;
#endif
        } NMISR_b;
    };

    union
    {
        __IOM uint32_t NMIER;          /*!< (@ 0x00000584) Non-maskable interrupt enable register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 13;
            __IOM uint32_t MRERDEN : 1; /*!< [18..18] MRAM MRE Read Error interrupt enable                             */
            __IOM uint32_t MRCRDEN : 1; /*!< [17..17] MRAM MRC Read Error interrupt enable                             */
            __IOM uint32_t DPFPUEN : 1; /*!< [16..16] FPU exception enable                                             */
            uint32_t               : 1;
            __IOM uint32_t LMEN    : 1; /*!< [14..14] Local memory error interrupt enable                              */
            __IOM uint32_t CMEN    : 1; /*!< [13..13] Common memory error interrupt enable                             */
            __IOM uint32_t BUSEN   : 1; /*!< [12..12] Bus error interrupt enable                                       */
            uint32_t               : 4;
            __IOM uint32_t NMIEN   : 1; /*!< [7..7] NMI pin interrupt enable                                           */
            __IOM uint32_t OSTEN   : 1; /*!< [6..6] Oscillation stop detection interrupt enable                        */
            __IOM uint32_t SOSTEN  : 1; /*!< [5..5] Sub oscillation stop detection interrupt enable                    */
            uint32_t               : 1;
            __IOM uint32_t PVD2EN  : 1; /*!< [3..3] PVD2 interrupt enable                                              */
            __IOM uint32_t PVD1EN  : 1; /*!< [2..2] PVD1 interrupt enable                                              */
            __IOM uint32_t WDTEN   : 1; /*!< [1..1] WDT underflow/refresh error enable                                 */
            __IOM uint32_t IWDTEN  : 1; /*!< [0..0] IWDT underflow/refresh error enable                                */
#else
            __IOM uint32_t IWDTEN  : 1; /*!< [0..0] IWDT underflow/refresh error enable                                */
            __IOM uint32_t WDTEN   : 1; /*!< [1..1] WDT underflow/refresh error enable                                 */
            __IOM uint32_t PVD1EN  : 1; /*!< [2..2] PVD1 interrupt enable                                              */
            __IOM uint32_t PVD2EN  : 1; /*!< [3..3] PVD2 interrupt enable                                              */
            uint32_t               : 1;
            __IOM uint32_t SOSTEN  : 1; /*!< [5..5] Sub oscillation stop detection interrupt enable                    */
            __IOM uint32_t OSTEN   : 1; /*!< [6..6] Oscillation stop detection interrupt enable                        */
            __IOM uint32_t NMIEN   : 1; /*!< [7..7] NMI pin interrupt enable                                           */
            uint32_t               : 4;
            __IOM uint32_t BUSEN   : 1; /*!< [12..12] Bus error interrupt enable                                       */
            __IOM uint32_t CMEN    : 1; /*!< [13..13] Common memory error interrupt enable                             */
            __IOM uint32_t LMEN    : 1; /*!< [14..14] Local memory error interrupt enable                              */
            uint32_t               : 1;
            __IOM uint32_t DPFPUEN : 1; /*!< [16..16] FPU exception enable                                             */
            __IOM uint32_t MRCRDEN : 1; /*!< [17..17] MRAM MRC Read Error interrupt enable                             */
            __IOM uint32_t MRERDEN : 1; /*!< [18..18] MRAM MRE Read Error interrupt enable                             */
            uint32_t               : 13;
#endif
        } NMIER_b;
    };

    union
    {
        __IOM uint32_t NMICLR;         /*!< (@ 0x00000588) Non-maskable interrupt status clear register               */

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
    __IM uint32_t RESERVED10[45];

    union
    {
        __IM uint32_t GRPBL0;          /*!< (@ 0x00000640) Group BLm Secure interrupt request register for
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
#endif
        } GRPBL0_b;
    };

    union
    {
        __IM uint32_t GRPBL1;          /*!< (@ 0x00000644) Group BLm Secure interrupt request register for
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
#endif
        } GRPBL1_b;
    };
    __IM uint32_t RESERVED11[30];

    union
    {
        __IOM uint32_t GENBL0;         /*!< (@ 0x000006C0) Group BLm Secure interrupt request enable register
                                        *                  for 0                                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
#endif
        } GENBL0_b;
    };

    union
    {
        __IOM uint32_t GENBL1;         /*!< (@ 0x000006C4) Group BLm Secure interrupt request enable register
                                        *                  for 1                                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
#endif
        } GENBL1_b;
    };
    __IM uint32_t RESERVED12[30];

    union
    {
        __IM uint32_t GRPAL0;          /*!< (@ 0x00000740) Group ALm Secure interrupt request register for
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
#endif
        } GRPAL0_b;
    };

    union
    {
        __IM uint32_t GRPAL1;          /*!< (@ 0x00000744) Group ALm Secure interrupt request register for
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
#endif
        } GRPAL1_b;
    };

    union
    {
        __IM uint32_t GRPAL2;          /*!< (@ 0x00000748) Group ALm Secure interrupt request register for
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
#endif
        } GRPAL2_b;
    };

    union
    {
        __IM uint32_t GRPAL3;          /*!< (@ 0x0000074C) Group ALm Secure interrupt request register for
                                        *                  3                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
#endif
        } GRPAL3_b;
    };

    union
    {
        __IM uint32_t GRPAL4;          /*!< (@ 0x00000750) Group ALm Secure interrupt request register for
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
#endif
        } GRPAL4_b;
    };

    union
    {
        __IM uint32_t GRPAL5;          /*!< (@ 0x00000754) Group ALm Secure interrupt request register for
                                        *                  5                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
#endif
        } GRPAL5_b;
    };

    union
    {
        __IM uint32_t GRPAL6;          /*!< (@ 0x00000758) Group ALm Secure interrupt request register for
                                        *                  6                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
#else
            __IM uint32_t IS0  : 1;    /*!< [0..0] interrupt status flag 0                                            */
            __IM uint32_t IS1  : 1;    /*!< [1..1] interrupt status flag 1                                            */
            __IM uint32_t IS2  : 1;    /*!< [2..2] interrupt status flag 2                                            */
            __IM uint32_t IS3  : 1;    /*!< [3..3] interrupt status flag 3                                            */
            __IM uint32_t IS4  : 1;    /*!< [4..4] interrupt status flag 4                                            */
            __IM uint32_t IS5  : 1;    /*!< [5..5] interrupt status flag 5                                            */
            __IM uint32_t IS6  : 1;    /*!< [6..6] interrupt status flag 6                                            */
            __IM uint32_t IS7  : 1;    /*!< [7..7] interrupt status flag 7                                            */
            __IM uint32_t IS8  : 1;    /*!< [8..8] interrupt status flag 8                                            */
            __IM uint32_t IS9  : 1;    /*!< [9..9] interrupt status flag 9                                            */
            __IM uint32_t IS10 : 1;    /*!< [10..10] interrupt status flag 10                                         */
            __IM uint32_t IS11 : 1;    /*!< [11..11] interrupt status flag 11                                         */
            __IM uint32_t IS12 : 1;    /*!< [12..12] interrupt status flag 12                                         */
            __IM uint32_t IS13 : 1;    /*!< [13..13] interrupt status flag 13                                         */
            __IM uint32_t IS14 : 1;    /*!< [14..14] interrupt status flag 14                                         */
            __IM uint32_t IS15 : 1;    /*!< [15..15] interrupt status flag 15                                         */
            __IM uint32_t IS16 : 1;    /*!< [16..16] interrupt status flag 16                                         */
            __IM uint32_t IS17 : 1;    /*!< [17..17] interrupt status flag 17                                         */
            __IM uint32_t IS18 : 1;    /*!< [18..18] interrupt status flag 18                                         */
            __IM uint32_t IS19 : 1;    /*!< [19..19] interrupt status flag 19                                         */
            __IM uint32_t IS20 : 1;    /*!< [20..20] interrupt status flag 20                                         */
            __IM uint32_t IS21 : 1;    /*!< [21..21] interrupt status flag 21                                         */
            __IM uint32_t IS22 : 1;    /*!< [22..22] interrupt status flag 22                                         */
            __IM uint32_t IS23 : 1;    /*!< [23..23] interrupt status flag 23                                         */
            __IM uint32_t IS24 : 1;    /*!< [24..24] interrupt status flag 24                                         */
            __IM uint32_t IS25 : 1;    /*!< [25..25] interrupt status flag 25                                         */
            __IM uint32_t IS26 : 1;    /*!< [26..26] interrupt status flag 26                                         */
            __IM uint32_t IS27 : 1;    /*!< [27..27] interrupt status flag 27                                         */
            __IM uint32_t IS28 : 1;    /*!< [28..28] interrupt status flag 28                                         */
            __IM uint32_t IS29 : 1;    /*!< [29..29] interrupt status flag 29                                         */
            __IM uint32_t IS30 : 1;    /*!< [30..30] interrupt status flag 30                                         */
            __IM uint32_t IS31 : 1;    /*!< [31..31] interrupt status flag 31                                         */
#endif
        } GRPAL6_b;
    };
    __IM uint32_t RESERVED13[25];

    union
    {
        __IOM uint32_t GENAL0;         /*!< (@ 0x000007C0) Group ALm Secure interrupt request enable register
                                        *                  for 0                                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
#endif
        } GENAL0_b;
    };

    union
    {
        __IOM uint32_t GENAL1;         /*!< (@ 0x000007C4) Group ALm Secure interrupt request enable register
                                        *                  for 1                                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
#endif
        } GENAL1_b;
    };

    union
    {
        __IOM uint32_t GENAL2;         /*!< (@ 0x000007C8) Group ALm Secure interrupt request enable register
                                        *                  for 2                                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
#endif
        } GENAL2_b;
    };

    union
    {
        __IOM uint32_t GENAL3;         /*!< (@ 0x000007CC) Group ALm Secure interrupt request enable register
                                        *                  for 3                                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
#endif
        } GENAL3_b;
    };

    union
    {
        __IOM uint32_t GENAL4;         /*!< (@ 0x000007D0) Group ALm Secure interrupt request enable register
                                        *                  for 4                                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
#endif
        } GENAL4_b;
    };

    union
    {
        __IOM uint32_t GENAL5;         /*!< (@ 0x000007D4) Group ALm Secure interrupt request enable register
                                        *                  for 5                                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
#endif
        } GENAL5_b;
    };

    union
    {
        __IOM uint32_t GENAL6;         /*!< (@ 0x000007D8) Group ALm Secure interrupt request enable register
                                        *                  for 6                                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
#else
            __IOM uint32_t EN0  : 1;   /*!< [0..0] Secure interrupt request enable bit 0                              */
            __IOM uint32_t EN1  : 1;   /*!< [1..1] Secure interrupt request enable bit 1                              */
            __IOM uint32_t EN2  : 1;   /*!< [2..2] Secure interrupt request enable bit 2                              */
            __IOM uint32_t EN3  : 1;   /*!< [3..3] Secure interrupt request enable bit 3                              */
            __IOM uint32_t EN4  : 1;   /*!< [4..4] Secure interrupt request enable bit 4                              */
            __IOM uint32_t EN5  : 1;   /*!< [5..5] Secure interrupt request enable bit 5                              */
            __IOM uint32_t EN6  : 1;   /*!< [6..6] Secure interrupt request enable bit 6                              */
            __IOM uint32_t EN7  : 1;   /*!< [7..7] Secure interrupt request enable bit 7                              */
            __IOM uint32_t EN8  : 1;   /*!< [8..8] Secure interrupt request enable bit 8                              */
            __IOM uint32_t EN9  : 1;   /*!< [9..9] Secure interrupt request enable bit 9                              */
            __IOM uint32_t EN10 : 1;   /*!< [10..10] Secure interrupt request enable bit 10                           */
            __IOM uint32_t EN11 : 1;   /*!< [11..11] Secure interrupt request enable bit 11                           */
            __IOM uint32_t EN12 : 1;   /*!< [12..12] Secure interrupt request enable bit 12                           */
            __IOM uint32_t EN13 : 1;   /*!< [13..13] Secure interrupt request enable bit 13                           */
            __IOM uint32_t EN14 : 1;   /*!< [14..14] Secure interrupt request enable bit 14                           */
            __IOM uint32_t EN15 : 1;   /*!< [15..15] Secure interrupt request enable bit 15                           */
            __IOM uint32_t EN16 : 1;   /*!< [16..16] Secure interrupt request enable bit 16                           */
            __IOM uint32_t EN17 : 1;   /*!< [17..17] Secure interrupt request enable bit 17                           */
            __IOM uint32_t EN18 : 1;   /*!< [18..18] Secure interrupt request enable bit 18                           */
            __IOM uint32_t EN19 : 1;   /*!< [19..19] Secure interrupt request enable bit 19                           */
            __IOM uint32_t EN20 : 1;   /*!< [20..20] Secure interrupt request enable bit 20                           */
            __IOM uint32_t EN21 : 1;   /*!< [21..21] Secure interrupt request enable bit 21                           */
            __IOM uint32_t EN22 : 1;   /*!< [22..22] Secure interrupt request enable bit 22                           */
            __IOM uint32_t EN23 : 1;   /*!< [23..23] Secure interrupt request enable bit 23                           */
            __IOM uint32_t EN24 : 1;   /*!< [24..24] Secure interrupt request enable bit 24                           */
            __IOM uint32_t EN25 : 1;   /*!< [25..25] Secure interrupt request enable bit 25                           */
            __IOM uint32_t EN26 : 1;   /*!< [26..26] Secure interrupt request enable bit 26                           */
            __IOM uint32_t EN27 : 1;   /*!< [27..27] Secure interrupt request enable bit 27                           */
            __IOM uint32_t EN28 : 1;   /*!< [28..28] Secure interrupt request enable bit 28                           */
            __IOM uint32_t EN29 : 1;   /*!< [29..29] Secure interrupt request enable bit 29                           */
            __IOM uint32_t EN30 : 1;   /*!< [30..30] Secure interrupt request enable bit 30                           */
            __IOM uint32_t EN31 : 1;   /*!< [31..31] Secure interrupt request enable bit 31                           */
#endif
        } GENAL6_b;
    };
    __IM uint32_t        RESERVED14[9];
    __IOM R_ICU_PIR_Type PIR[128];     /*!< (@ 0x00000800) Software Configurable Interrupt A/B Request Register
                                        *                  [0..127]                                                   */
    __IM uint32_t          RESERVED15[32];
    __IOM R_ICU_SLIXR_Type SLIXR[16];  /*!< (@ 0x00000900) Software Configurable Interrupt A/B/IRQ source
                                        *                  select register [0..15]                                    */
    __IOM R_ICU_SLIR_Type SLIR[112];   /*!< (@ 0x00000920) Software Configurable Interrupt A/B source select
                                        *                  register [0..111]                                          */
    __IM uint32_t RESERVED16;

    union
    {
        __IOM uint8_t SLIPRCR;         /*!< (@ 0x00000A04) Secure Software Configuration Interrupt Source
                                        *                  Select Register Write Protect Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t WPRC : 1;    /*!< [0..0] Software configurable interrupt source select register
                                        *   write protect bit Set whether to enable or disable writing
                                        *   to SLIXRn and SLIRn.                                                      */
#else
            __IOM uint8_t WPRC : 1;    /*!< [0..0] Software configurable interrupt source select register
                                        *   write protect bit Set whether to enable or disable writing
                                        *   to SLIXRn and SLIRn.                                                      */
            uint8_t : 7;
#endif
        } SLIPRCR_b;
    };
    __IM uint8_t  RESERVED17;
    __IM uint16_t RESERVED18;
    __IM uint32_t RESERVED19[125];

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
    __IM uint8_t  RESERVED20;
    __IM uint16_t RESERVED21;
    __IM uint32_t RESERVED22[3];

    union
    {
        __IOM uint8_t NMICR;           /*!< (@ 0x00000C0C) NMI pin interrupt control register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t NFLTEN   : 1; /*!< [7..7] Digital filter enable bit                                          */
            __IOM uint8_t NFCLKSEL : 3; /*!< [6..4] Digital filter sampling Clock select bit                           */
            uint8_t                : 1;
            __IOM uint8_t NFLTMD   : 1; /*!< [2..2] Digital filter mode select bit                                     */
            uint8_t                : 1;
            __IOM uint8_t NMIMD    : 1; /*!< [0..0] NMI detection select bit                                           */
#else
            __IOM uint8_t NMIMD    : 1; /*!< [0..0] NMI detection select bit                                           */
            uint8_t                : 1;
            __IOM uint8_t NFLTMD   : 1; /*!< [2..2] Digital filter mode select bit                                     */
            uint8_t                : 1;
            __IOM uint8_t NFCLKSEL : 3; /*!< [6..4] Digital filter sampling Clock select bit                           */
            __IOM uint8_t NFLTEN   : 1; /*!< [7..7] Digital filter enable bit                                          */
#endif
        } NMICR_b;
    };
    __IM uint8_t             RESERVED23;
    __IM uint16_t            RESERVED24;
    __IM uint32_t            RESERVED25[4];
    __IOM R_ICU_IRQCR_Type   IRQCR[32];  /*!< (@ 0x00000C20) IRQ Control Register [0..31]                               */
    __IOM R_ICU_SELEXDR_Type SELEXDR[2]; /*!< (@ 0x00000C40) EXDMAC trigger select register for [0..1]                  */
} R_ICU_Type;                            /*!< Size = 3144 (0xc48)                                                       */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_ICU_REG_H */
