/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CPSCU_REG_H
#define R_CPSCU_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_CPSCU                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief CPU System Security  Attribution Control Unit (R_CPSCU)
 */

typedef struct                         /*!< (@ 0x87018000) R_CPSCU Structure                                          */
{
    __IM uint32_t RESERVED[4];

    union
    {
        __IOM uint32_t SRAMSAR;          /*!< (@ 0x00000010) SRAM Security Attribution Register                         */

        struct
        {
            __IOM uint32_t SRAMSA0  : 1; /*!< [0..0] SRAM0-Related Register Security Attribution                        */
            __IOM uint32_t SRAMSA1  : 1; /*!< [1..1] SRAM1-Related Register Security Attribution                        */
            uint32_t                : 6;
            __IOM uint32_t SRAMWTSA : 1; /*!< [8..8] SRAMWTSC Security Attribution                                      */
            uint32_t                : 23;
        } SRAMSAR_b;
    };
    __IM uint32_t RESERVED1[7];

    union
    {
        __IOM uint32_t DTCSAR;         /*!< (@ 0x00000030) DTC Security Attribution Register                          */

        struct
        {
            __IOM uint32_t SADTC0 : 1; /*!< [0..0] DTC Security Attribution 0                                         */
            uint32_t              : 31;
        } DTCSAR_b;
    };

    union
    {
        __IOM uint32_t DMACSAR;          /*!< (@ 0x00000034) DMAC Security Attribution Register                         */

        struct
        {
            __IOM uint32_t DMASTSA0 : 1; /*!< [0..0] DMAC0 DMAST Security Attribution Setting                           */
            uint32_t                : 31;
        } DMACSAR_b;
    };

    union
    {
        __IOM uint32_t EXDMACSAR;         /*!< (@ 0x00000038) EXDMAC Security Attribution Register                       */

        struct
        {
            __IOM uint32_t DMAXSTSA0 : 1; /*!< [0..0] EXDMA EDMAST Security Attribution Setting 0                        */
            uint32_t                 : 31;
        } EXDMACSAR_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t ICUSARA;           /*!< (@ 0x00000040) ICU Security Attribution Register A                        */

        struct
        {
            __IOM uint32_t SAIRQCR0  : 1; /*!< [0..0] IRQCR0 Security Attribution                                        */
            __IOM uint32_t SAIRQCR1  : 1; /*!< [1..1] IRQCR1 Security Attribution                                        */
            __IOM uint32_t SAIRQCR2  : 1; /*!< [2..2] IRQCR2 Security Attribution                                        */
            __IOM uint32_t SAIRQCR3  : 1; /*!< [3..3] IRQCR3 Security Attribution                                        */
            __IOM uint32_t SAIRQCR4  : 1; /*!< [4..4] IRQCR4 Security Attribution                                        */
            __IOM uint32_t SAIRQCR5  : 1; /*!< [5..5] IRQCR5 Security Attribution                                        */
            __IOM uint32_t SAIRQCR6  : 1; /*!< [6..6] IRQCR6 Security Attribution                                        */
            __IOM uint32_t SAIRQCR7  : 1; /*!< [7..7] IRQCR7 Security Attribution                                        */
            __IOM uint32_t SAIRQCR8  : 1; /*!< [8..8] IRQCR8 Security Attribution                                        */
            __IOM uint32_t SAIRQCR9  : 1; /*!< [9..9] IRQCR9 Security Attribution                                        */
            __IOM uint32_t SAIRQCR10 : 1; /*!< [10..10] IRQCR10 Security Attribution                                     */
            __IOM uint32_t SAIRQCR11 : 1; /*!< [11..11] IRQCR11 Security Attribution                                     */
            __IOM uint32_t SAIRQCR12 : 1; /*!< [12..12] IRQCR12 Security Attribution                                     */
            __IOM uint32_t SAIRQCR13 : 1; /*!< [13..13] IRQCR13 Security Attribution                                     */
            __IOM uint32_t SAIRQCR14 : 1; /*!< [14..14] IRQCR14 Security Attribution                                     */
            __IOM uint32_t SAIRQCR15 : 1; /*!< [15..15] IRQCR15 Security Attribution                                     */
            __IOM uint32_t SAIRQCR16 : 1; /*!< [16..16] IRQCR16 and PIXR0.PIR0 Security Attribution                      */
            __IOM uint32_t SAIRQCR17 : 1; /*!< [17..17] IRQCR17 and PIXR0.PIR1 Security Attribution                      */
            __IOM uint32_t SAIRQCR18 : 1; /*!< [18..18] IRQCR18 and PIXR0.PIR2 Security Attribution                      */
            __IOM uint32_t SAIRQCR19 : 1; /*!< [19..19] IRQCR19 and PIXR0.PIR3 Security Attribution                      */
            __IOM uint32_t SAIRQCR20 : 1; /*!< [20..20] IRQCR20 and PIXR0.PIR4 Security Attribution                      */
            __IOM uint32_t SAIRQCR21 : 1; /*!< [21..21] IRQCR21 and PIXR0.PIR5 Security Attribution                      */
            __IOM uint32_t SAIRQCR22 : 1; /*!< [22..22] IRQCR22 and PIXR0.PIR6 Security Attribution                      */
            __IOM uint32_t SAIRQCR23 : 1; /*!< [23..23] IRQCR23 and PIXR0.PIR7 Security Attribution                      */
            __IOM uint32_t SAIRQCR24 : 1; /*!< [24..24] IRQCR24 and PIXR1.PIR0 Security Attribution                      */
            __IOM uint32_t SAIRQCR25 : 1; /*!< [25..25] IRQCR25 and PIXR1.PIR1 Security Attribution                      */
            __IOM uint32_t SAIRQCR26 : 1; /*!< [26..26] IRQCR26 and PIXR1.PIR2 Security Attribution                      */
            __IOM uint32_t SAIRQCR27 : 1; /*!< [27..27] IRQCR27 and PIXR1.PIR3 Security Attribution                      */
            __IOM uint32_t SAIRQCR28 : 1; /*!< [28..28] IRQCR28 and PIXR1.PIR4 Security Attribution                      */
            __IOM uint32_t SAIRQCR29 : 1; /*!< [29..29] IRQCR29 and PIXR1.PIR5 Security Attribution                      */
            __IOM uint32_t SAIRQCR30 : 1; /*!< [30..30] IRQCR30 and PIXR1.PIR6 Security Attribution                      */
            __IOM uint32_t SAIRQCR31 : 1; /*!< [31..31] IRQCR31 and PIXR1.PIR7 Security Attribution                      */
        } ICUSARA_b;
    };

    union
    {
        __IOM uint32_t ICUSARB;         /*!< (@ 0x00000044) ICU Security Attribution Register B                        */

        struct
        {
            __IOM uint32_t SANMICR : 1; /*!< [0..0] NMICR Security Attribution                                         */
            __IOM uint32_t SANMI0  : 1; /*!< [1..1] Non-Maskable Interrupt Security Attribution 0                      */
            uint32_t               : 30;
        } ICUSARB_b;
    };

    union
    {
        __IOM uint32_t ICUSARC;        /*!< (@ 0x00000048) ICU Security Attribution Register C                        */

        struct
        {
            uint32_t                : 1;
            __IOM uint32_t SACLPCR0 : 1; /*!< [1..1] CLPCR Security Attribution 0                                       */
            uint32_t                : 30;
        } ICUSARC_b;
    };

    union
    {
        __IOM uint32_t ICUSARD;         /*!< (@ 0x0000004C) ICU Security Attribution Register D                        */

        struct
        {
            __IOM uint32_t SADPFPU : 1; /*!< [0..0] Double-Precision Floating-Point Exception Security Attribution     */
            __IOM uint32_t SALM    : 1; /*!< [1..1] Local Memory Error Interrupt Security Attribution                  */
            __IOM uint32_t SACM    : 1; /*!< [2..2] Common Memory Error Interrupt Security Attribution                 */
            __IOM uint32_t SAHLDTO : 1; /*!< [3..3] External Bus Hold Timeout Interrupt Security Attribution           */
            uint32_t               : 4;
            __IOM uint32_t SAMCEE  : 1; /*!< [8..8] Code MRAM ECC Error Interrupt Security Attribution                 */
            __IOM uint32_t SAMEEE  : 1; /*!< [9..9] Extra MRAM ECC Error Interrupt Security Attribution                */
            __IOM uint32_t SAMCWE  : 1; /*!< [10..10] Code MRAM Write Error Interrupt Security Attribution             */
            __IOM uint32_t SAMDWE  : 1; /*!< [11..11] Data MRAM Write Error Interrupt Security Attribution             */
            __IOM uint32_t SAMEWE  : 1; /*!< [12..12] Extra MRAM Write Error Interrupt Security Attribution            */
            uint32_t               : 19;
        } ICUSARD_b;
    };
    __IM uint32_t RESERVED3[20];

    union
    {
        __IOM uint32_t ICU0SAR0;       /*!< (@ 0x000000A0) ICU Security Attribution Register 0                        */

        struct
        {
            __IOM uint32_t SAIR0  : 1; /*!< [0..0] IR0 Security Attribution                                           */
            __IOM uint32_t SAIR1  : 1; /*!< [1..1] IR1 Security Attribution                                           */
            __IOM uint32_t SAIR2  : 1; /*!< [2..2] IR2 Security Attribution                                           */
            __IOM uint32_t SAIR3  : 1; /*!< [3..3] IR3 Security Attribution                                           */
            __IOM uint32_t SAIR4  : 1; /*!< [4..4] IR4 Security Attribution                                           */
            __IOM uint32_t SAIR5  : 1; /*!< [5..5] IR5 Security Attribution                                           */
            __IOM uint32_t SAIR6  : 1; /*!< [6..6] IR6 Security Attribution                                           */
            __IOM uint32_t SAIR7  : 1; /*!< [7..7] IR7 Security Attribution                                           */
            __IOM uint32_t SAIR8  : 1; /*!< [8..8] IR8 Security Attribution                                           */
            __IOM uint32_t SAIR9  : 1; /*!< [9..9] IR9 Security Attribution                                           */
            __IOM uint32_t SAIR10 : 1; /*!< [10..10] IR10 Security Attribution                                        */
            __IOM uint32_t SAIR11 : 1; /*!< [11..11] IR11 Security Attribution                                        */
            __IOM uint32_t SAIR12 : 1; /*!< [12..12] IR12 Security Attribution                                        */
            __IOM uint32_t SAIR13 : 1; /*!< [13..13] IR13 Security Attribution                                        */
            __IOM uint32_t SAIR14 : 1; /*!< [14..14] IR14 Security Attribution                                        */
            __IOM uint32_t SAIR15 : 1; /*!< [15..15] IR15 Security Attribution                                        */
            __IOM uint32_t SAIR16 : 1; /*!< [16..16] IR16 Security Attribution                                        */
            __IOM uint32_t SAIR17 : 1; /*!< [17..17] IR17 Security Attribution                                        */
            __IOM uint32_t SAIR18 : 1; /*!< [18..18] IR18 Security Attribution                                        */
            __IOM uint32_t SAIR19 : 1; /*!< [19..19] IR19 Security Attribution                                        */
            __IOM uint32_t SAIR20 : 1; /*!< [20..20] IR20 Security Attribution                                        */
            __IOM uint32_t SAIR21 : 1; /*!< [21..21] IR21 Security Attribution                                        */
            __IOM uint32_t SAIR22 : 1; /*!< [22..22] IR22 Security Attribution                                        */
            __IOM uint32_t SAIR23 : 1; /*!< [23..23] IR23 Security Attribution                                        */
            __IOM uint32_t SAIR24 : 1; /*!< [24..24] IR24 Security Attribution                                        */
            __IOM uint32_t SAIR25 : 1; /*!< [25..25] IR25 Security Attribution                                        */
            __IOM uint32_t SAIR26 : 1; /*!< [26..26] IR26 Security Attribution                                        */
            __IOM uint32_t SAIR27 : 1; /*!< [27..27] IR27 Security Attribution                                        */
            __IOM uint32_t SAIR28 : 1; /*!< [28..28] IR28 Security Attribution                                        */
            __IOM uint32_t SAIR29 : 1; /*!< [29..29] IR29 Security Attribution                                        */
            __IOM uint32_t SAIR30 : 1; /*!< [30..30] IR30 Security Attribution                                        */
            __IOM uint32_t SAIR31 : 1; /*!< [31..31] IR31 Security Attribution                                        */
        } ICU0SAR0_b;
    };

    union
    {
        __IOM uint32_t ICU0SAR1;       /*!< (@ 0x000000A4) ICU Security Attribution Register 1                        */

        struct
        {
            __IOM uint32_t SAIR32 : 1; /*!< [0..0] IR32 Security Attribution                                          */
            __IOM uint32_t SAIR33 : 1; /*!< [1..1] IR33 Security Attribution                                          */
            __IOM uint32_t SAIR34 : 1; /*!< [2..2] IR34 Security Attribution                                          */
            __IOM uint32_t SAIR35 : 1; /*!< [3..3] IR35 Security Attribution                                          */
            __IOM uint32_t SAIR36 : 1; /*!< [4..4] IR36 Security Attribution                                          */
            __IOM uint32_t SAIR37 : 1; /*!< [5..5] IR37 Security Attribution                                          */
            __IOM uint32_t SAIR38 : 1; /*!< [6..6] IR38 Security Attribution                                          */
            __IOM uint32_t SAIR39 : 1; /*!< [7..7] IR39 Security Attribution                                          */
            __IOM uint32_t SAIR40 : 1; /*!< [8..8] IR40 Security Attribution                                          */
            __IOM uint32_t SAIR41 : 1; /*!< [9..9] IR41 Security Attribution                                          */
            __IOM uint32_t SAIR42 : 1; /*!< [10..10] IR42 Security Attribution                                        */
            __IOM uint32_t SAIR43 : 1; /*!< [11..11] IR43 Security Attribution                                        */
            __IOM uint32_t SAIR44 : 1; /*!< [12..12] IR44 Security Attribution                                        */
            __IOM uint32_t SAIR45 : 1; /*!< [13..13] IR45 Security Attribution                                        */
            __IOM uint32_t SAIR46 : 1; /*!< [14..14] IR46 Security Attribution                                        */
            __IOM uint32_t SAIR47 : 1; /*!< [15..15] IR47 Security Attribution                                        */
            __IOM uint32_t SAIR48 : 1; /*!< [16..16] IR48 Security Attribution                                        */
            __IOM uint32_t SAIR49 : 1; /*!< [17..17] IR49 Security Attribution                                        */
            __IOM uint32_t SAIR50 : 1; /*!< [18..18] IR50 Security Attribution                                        */
            __IOM uint32_t SAIR51 : 1; /*!< [19..19] IR51 Security Attribution                                        */
            __IOM uint32_t SAIR52 : 1; /*!< [20..20] IR52 Security Attribution                                        */
            __IOM uint32_t SAIR53 : 1; /*!< [21..21] IR53 Security Attribution                                        */
            __IOM uint32_t SAIR54 : 1; /*!< [22..22] IR54 Security Attribution                                        */
            __IOM uint32_t SAIR55 : 1; /*!< [23..23] IR55 Security Attribution                                        */
            __IOM uint32_t SAIR56 : 1; /*!< [24..24] IR56 Security Attribution                                        */
            __IOM uint32_t SAIR57 : 1; /*!< [25..25] IR57 Security Attribution                                        */
            __IOM uint32_t SAIR58 : 1; /*!< [26..26] IR58 Security Attribution                                        */
            __IOM uint32_t SAIR59 : 1; /*!< [27..27] IR59 Security Attribution                                        */
            __IOM uint32_t SAIR60 : 1; /*!< [28..28] IR60 Security Attribution                                        */
            __IOM uint32_t SAIR61 : 1; /*!< [29..29] IR61 Security Attribution                                        */
            __IOM uint32_t SAIR62 : 1; /*!< [30..30] IR62 Security Attribution                                        */
            __IOM uint32_t SAIR63 : 1; /*!< [31..31] IR63 Security Attribution                                        */
        } ICU0SAR1_b;
    };

    union
    {
        __IOM uint32_t ICU0SAR2;       /*!< (@ 0x000000A8) ICU Security Attribution Register 2                        */

        struct
        {
            __IOM uint32_t SAIR64 : 1; /*!< [0..0] IR64 Security Attribution                                          */
            __IOM uint32_t SAIR65 : 1; /*!< [1..1] IR65 Security Attribution                                          */
            __IOM uint32_t SAIR66 : 1; /*!< [2..2] IR66 Security Attribution                                          */
            __IOM uint32_t SAIR67 : 1; /*!< [3..3] IR67 Security Attribution                                          */
            __IOM uint32_t SAIR68 : 1; /*!< [4..4] IR68 Security Attribution                                          */
            __IOM uint32_t SAIR69 : 1; /*!< [5..5] IR69 Security Attribution                                          */
            __IOM uint32_t SAIR70 : 1; /*!< [6..6] IR70 Security Attribution                                          */
            __IOM uint32_t SAIR71 : 1; /*!< [7..7] IR71 Security Attribution                                          */
            __IOM uint32_t SAIR72 : 1; /*!< [8..8] IR72 Security Attribution                                          */
            __IOM uint32_t SAIR73 : 1; /*!< [9..9] IR73 Security Attribution                                          */
            __IOM uint32_t SAIR74 : 1; /*!< [10..10] IR74 Security Attribution                                        */
            __IOM uint32_t SAIR75 : 1; /*!< [11..11] IR75 Security Attribution                                        */
            __IOM uint32_t SAIR76 : 1; /*!< [12..12] IR76 Security Attribution                                        */
            __IOM uint32_t SAIR77 : 1; /*!< [13..13] IR77 Security Attribution                                        */
            __IOM uint32_t SAIR78 : 1; /*!< [14..14] IR78 Security Attribution                                        */
            __IOM uint32_t SAIR79 : 1; /*!< [15..15] IR79 Security Attribution                                        */
            __IOM uint32_t SAIR80 : 1; /*!< [16..16] IR80 Security Attribution                                        */
            __IOM uint32_t SAIR81 : 1; /*!< [17..17] IR81 Security Attribution                                        */
            __IOM uint32_t SAIR82 : 1; /*!< [18..18] IR82 Security Attribution                                        */
            __IOM uint32_t SAIR83 : 1; /*!< [19..19] IR83 Security Attribution                                        */
            __IOM uint32_t SAIR84 : 1; /*!< [20..20] IR84 Security Attribution                                        */
            __IOM uint32_t SAIR85 : 1; /*!< [21..21] IR85 Security Attribution                                        */
            __IOM uint32_t SAIR86 : 1; /*!< [22..22] IR86 Security Attribution                                        */
            __IOM uint32_t SAIR87 : 1; /*!< [23..23] IR87 Security Attribution                                        */
            __IOM uint32_t SAIR88 : 1; /*!< [24..24] IR88 Security Attribution                                        */
            __IOM uint32_t SAIR89 : 1; /*!< [25..25] IR89 Security Attribution                                        */
            __IOM uint32_t SAIR90 : 1; /*!< [26..26] IR90 Security Attribution                                        */
            __IOM uint32_t SAIR91 : 1; /*!< [27..27] IR91 Security Attribution                                        */
            __IOM uint32_t SAIR92 : 1; /*!< [28..28] IR92 Security Attribution                                        */
            __IOM uint32_t SAIR93 : 1; /*!< [29..29] IR93 Security Attribution                                        */
            __IOM uint32_t SAIR94 : 1; /*!< [30..30] IR94 Security Attribution                                        */
            __IOM uint32_t SAIR95 : 1; /*!< [31..31] IR95 Security Attribution                                        */
        } ICU0SAR2_b;
    };

    union
    {
        __IOM uint32_t ICU0SAR3;        /*!< (@ 0x000000AC) ICU Security Attribution Register 3                        */

        struct
        {
            __IOM uint32_t SAIR96  : 1; /*!< [0..0] IR96 Security Attribution                                          */
            __IOM uint32_t SAIR97  : 1; /*!< [1..1] IR97 Security Attribution                                          */
            __IOM uint32_t SAIR98  : 1; /*!< [2..2] IR98 Security Attribution                                          */
            __IOM uint32_t SAIR99  : 1; /*!< [3..3] IR99 Security Attribution                                          */
            __IOM uint32_t SAIR100 : 1; /*!< [4..4] IR100 Security Attribution                                         */
            __IOM uint32_t SAIR101 : 1; /*!< [5..5] IR101 Security Attribution                                         */
            __IOM uint32_t SAIR102 : 1; /*!< [6..6] IR102 Security Attribution                                         */
            __IOM uint32_t SAIR103 : 1; /*!< [7..7] IR103 Security Attribution                                         */
            __IOM uint32_t SAIR104 : 1; /*!< [8..8] IR104 Security Attribution                                         */
            __IOM uint32_t SAIR105 : 1; /*!< [9..9] IR105 Security Attribution                                         */
            __IOM uint32_t SAIR106 : 1; /*!< [10..10] IR106 Security Attribution                                       */
            __IOM uint32_t SAIR107 : 1; /*!< [11..11] IR107 Security Attribution                                       */
            __IOM uint32_t SAIR108 : 1; /*!< [12..12] IR108 Security Attribution                                       */
            __IOM uint32_t SAIR109 : 1; /*!< [13..13] IR109 Security Attribution                                       */
            __IOM uint32_t SAIR110 : 1; /*!< [14..14] IR110 Security Attribution                                       */
            __IOM uint32_t SAIR111 : 1; /*!< [15..15] IR111 Security Attribution                                       */
            __IOM uint32_t SAIR112 : 1; /*!< [16..16] IR112 Security Attribution                                       */
            __IOM uint32_t SAIR113 : 1; /*!< [17..17] IR113 Security Attribution                                       */
            __IOM uint32_t SAIR114 : 1; /*!< [18..18] IR114 Security Attribution                                       */
            __IOM uint32_t SAIR115 : 1; /*!< [19..19] IR115 Security Attribution                                       */
            __IOM uint32_t SAIR116 : 1; /*!< [20..20] IR116 Security Attribution                                       */
            __IOM uint32_t SAIR117 : 1; /*!< [21..21] IR117 Security Attribution                                       */
            __IOM uint32_t SAIR118 : 1; /*!< [22..22] IR118 Security Attribution                                       */
            __IOM uint32_t SAIR119 : 1; /*!< [23..23] IR119 Security Attribution                                       */
            __IOM uint32_t SAIR120 : 1; /*!< [24..24] IR120 Security Attribution                                       */
            __IOM uint32_t SAIR121 : 1; /*!< [25..25] IR121 Security Attribution                                       */
            __IOM uint32_t SAIR122 : 1; /*!< [26..26] IR122 Security Attribution                                       */
            __IOM uint32_t SAIR123 : 1; /*!< [27..27] IR123 Security Attribution                                       */
            __IOM uint32_t SAIR124 : 1; /*!< [28..28] IR124 Security Attribution                                       */
            __IOM uint32_t SAIR125 : 1; /*!< [29..29] IR125 Security Attribution                                       */
            __IOM uint32_t SAIR126 : 1; /*!< [30..30] IR126 Security Attribution                                       */
            __IOM uint32_t SAIR127 : 1; /*!< [31..31] IR127 Security Attribution                                       */
        } ICU0SAR3_b;
    };

    union
    {
        __IOM uint32_t ICU0SAR4;        /*!< (@ 0x000000B0) ICU Security Attribution Register 4                        */

        struct
        {
            __IOM uint32_t SAIR128 : 1; /*!< [0..0] IR128 Security Attribution                                         */
            __IOM uint32_t SAIR129 : 1; /*!< [1..1] IR129 Security Attribution                                         */
            __IOM uint32_t SAIR130 : 1; /*!< [2..2] IR130 Security Attribution                                         */
            __IOM uint32_t SAIR131 : 1; /*!< [3..3] IR131 Security Attribution                                         */
            __IOM uint32_t SAIR132 : 1; /*!< [4..4] IR132 Security Attribution                                         */
            __IOM uint32_t SAIR133 : 1; /*!< [5..5] IR133 Security Attribution                                         */
            __IOM uint32_t SAIR134 : 1; /*!< [6..6] IR134 Security Attribution                                         */
            __IOM uint32_t SAIR135 : 1; /*!< [7..7] IR135 Security Attribution                                         */
            __IOM uint32_t SAIR136 : 1; /*!< [8..8] IR136 Security Attribution                                         */
            __IOM uint32_t SAIR137 : 1; /*!< [9..9] IR137 Security Attribution                                         */
            __IOM uint32_t SAIR138 : 1; /*!< [10..10] IR138 Security Attribution                                       */
            __IOM uint32_t SAIR139 : 1; /*!< [11..11] IR139 Security Attribution                                       */
            __IOM uint32_t SAIR140 : 1; /*!< [12..12] IR140 Security Attribution                                       */
            __IOM uint32_t SAIR141 : 1; /*!< [13..13] IR141 Security Attribution                                       */
            __IOM uint32_t SAIR142 : 1; /*!< [14..14] IR142 Security Attribution                                       */
            __IOM uint32_t SAIR143 : 1; /*!< [15..15] IR143 Security Attribution                                       */
            __IOM uint32_t SAIR144 : 1; /*!< [16..16] IR144 Security Attribution                                       */
            __IOM uint32_t SAIR145 : 1; /*!< [17..17] IR145 Security Attribution                                       */
            __IOM uint32_t SAIR146 : 1; /*!< [18..18] IR146 Security Attribution                                       */
            __IOM uint32_t SAIR147 : 1; /*!< [19..19] IR147 Security Attribution                                       */
            __IOM uint32_t SAIR148 : 1; /*!< [20..20] IR148 Security Attribution                                       */
            __IOM uint32_t SAIR149 : 1; /*!< [21..21] IR149 Security Attribution                                       */
            __IOM uint32_t SAIR150 : 1; /*!< [22..22] IR150 Security Attribution                                       */
            __IOM uint32_t SAIR151 : 1; /*!< [23..23] IR151 Security Attribution                                       */
            __IOM uint32_t SAIR152 : 1; /*!< [24..24] IR152 Security Attribution                                       */
            __IOM uint32_t SAIR153 : 1; /*!< [25..25] IR153 Security Attribution                                       */
            __IOM uint32_t SAIR154 : 1; /*!< [26..26] IR154 Security Attribution                                       */
            __IOM uint32_t SAIR155 : 1; /*!< [27..27] IR155 Security Attribution                                       */
            __IOM uint32_t SAIR156 : 1; /*!< [28..28] IR156 Security Attribution                                       */
            __IOM uint32_t SAIR157 : 1; /*!< [29..29] IR157 Security Attribution                                       */
            __IOM uint32_t SAIR158 : 1; /*!< [30..30] IR158 Security Attribution                                       */
            __IOM uint32_t SAIR159 : 1; /*!< [31..31] IR159 Security Attribution                                       */
        } ICU0SAR4_b;
    };

    union
    {
        __IOM uint32_t ICU0SAR5;        /*!< (@ 0x000000B4) ICU Security Attribution Register 5                        */

        struct
        {
            __IOM uint32_t SAIR160 : 1; /*!< [0..0] IR160 Security Attribution                                         */
            __IOM uint32_t SAIR161 : 1; /*!< [1..1] IR161 Security Attribution                                         */
            __IOM uint32_t SAIR162 : 1; /*!< [2..2] IR162 Security Attribution                                         */
            __IOM uint32_t SAIR163 : 1; /*!< [3..3] IR163 Security Attribution                                         */
            __IOM uint32_t SAIR164 : 1; /*!< [4..4] IR164 Security Attribution                                         */
            __IOM uint32_t SAIR165 : 1; /*!< [5..5] IR165 Security Attribution                                         */
            __IOM uint32_t SAIR166 : 1; /*!< [6..6] IR166 Security Attribution                                         */
            __IOM uint32_t SAIR167 : 1; /*!< [7..7] IR167 Security Attribution                                         */
            __IOM uint32_t SAIR168 : 1; /*!< [8..8] IR168 Security Attribution                                         */
            __IOM uint32_t SAIR169 : 1; /*!< [9..9] IR169 Security Attribution                                         */
            __IOM uint32_t SAIR170 : 1; /*!< [10..10] IR170 Security Attribution                                       */
            __IOM uint32_t SAIR171 : 1; /*!< [11..11] IR171 Security Attribution                                       */
            __IOM uint32_t SAIR172 : 1; /*!< [12..12] IR172 Security Attribution                                       */
            __IOM uint32_t SAIR173 : 1; /*!< [13..13] IR173 Security Attribution                                       */
            __IOM uint32_t SAIR174 : 1; /*!< [14..14] IR174 Security Attribution                                       */
            __IOM uint32_t SAIR175 : 1; /*!< [15..15] IR175 Security Attribution                                       */
            __IOM uint32_t SAIR176 : 1; /*!< [16..16] IR176 Security Attribution                                       */
            __IOM uint32_t SAIR177 : 1; /*!< [17..17] IR177 Security Attribution                                       */
            __IOM uint32_t SAIR178 : 1; /*!< [18..18] IR178 Security Attribution                                       */
            __IOM uint32_t SAIR179 : 1; /*!< [19..19] IR179 Security Attribution                                       */
            __IOM uint32_t SAIR180 : 1; /*!< [20..20] IR180 Security Attribution                                       */
            __IOM uint32_t SAIR181 : 1; /*!< [21..21] IR181 Security Attribution                                       */
            __IOM uint32_t SAIR182 : 1; /*!< [22..22] IR182 Security Attribution                                       */
            __IOM uint32_t SAIR183 : 1; /*!< [23..23] IR183 Security Attribution                                       */
            __IOM uint32_t SAIR184 : 1; /*!< [24..24] IR184 Security Attribution                                       */
            __IOM uint32_t SAIR185 : 1; /*!< [25..25] IR185 Security Attribution                                       */
            __IOM uint32_t SAIR186 : 1; /*!< [26..26] IR186 Security Attribution                                       */
            __IOM uint32_t SAIR187 : 1; /*!< [27..27] IR187 Security Attribution                                       */
            __IOM uint32_t SAIR188 : 1; /*!< [28..28] IR188 Security Attribution                                       */
            __IOM uint32_t SAIR189 : 1; /*!< [29..29] IR189 Security Attribution                                       */
            __IOM uint32_t SAIR190 : 1; /*!< [30..30] IR190 Security Attribution                                       */
            __IOM uint32_t SAIR191 : 1; /*!< [31..31] IR191 Security Attribution                                       */
        } ICU0SAR5_b;
    };

    union
    {
        __IOM uint32_t ICU0SAR6;        /*!< (@ 0x000000B8) ICU Security Attribution Register 6                        */

        struct
        {
            __IOM uint32_t SAIR192 : 1; /*!< [0..0] IR192 Security Attribution                                         */
            __IOM uint32_t SAIR193 : 1; /*!< [1..1] IR193 Security Attribution                                         */
            __IOM uint32_t SAIR194 : 1; /*!< [2..2] IR194 Security Attribution                                         */
            __IOM uint32_t SAIR195 : 1; /*!< [3..3] IR195 Security Attribution                                         */
            __IOM uint32_t SAIR196 : 1; /*!< [4..4] IR196 Security Attribution                                         */
            __IOM uint32_t SAIR197 : 1; /*!< [5..5] IR197 Security Attribution                                         */
            __IOM uint32_t SAIR198 : 1; /*!< [6..6] IR198 Security Attribution                                         */
            __IOM uint32_t SAIR199 : 1; /*!< [7..7] IR199 Security Attribution                                         */
            __IOM uint32_t SAIR200 : 1; /*!< [8..8] IR200 Security Attribution                                         */
            __IOM uint32_t SAIR201 : 1; /*!< [9..9] IR201 Security Attribution                                         */
            __IOM uint32_t SAIR202 : 1; /*!< [10..10] IR202 Security Attribution                                       */
            __IOM uint32_t SAIR203 : 1; /*!< [11..11] IR203 Security Attribution                                       */
            __IOM uint32_t SAIR204 : 1; /*!< [12..12] IR204 Security Attribution                                       */
            __IOM uint32_t SAIR205 : 1; /*!< [13..13] IR205 Security Attribution                                       */
            __IOM uint32_t SAIR206 : 1; /*!< [14..14] IR206 Security Attribution                                       */
            __IOM uint32_t SAIR207 : 1; /*!< [15..15] IR207 Security Attribution                                       */
            __IOM uint32_t SAIR208 : 1; /*!< [16..16] IR208 Security Attribution                                       */
            __IOM uint32_t SAIR209 : 1; /*!< [17..17] IR209 Security Attribution                                       */
            __IOM uint32_t SAIR210 : 1; /*!< [18..18] IR210 Security Attribution                                       */
            __IOM uint32_t SAIR211 : 1; /*!< [19..19] IR211 Security Attribution                                       */
            __IOM uint32_t SAIR212 : 1; /*!< [20..20] IR212 Security Attribution                                       */
            __IOM uint32_t SAIR213 : 1; /*!< [21..21] IR213 Security Attribution                                       */
            __IOM uint32_t SAIR214 : 1; /*!< [22..22] IR214 Security Attribution                                       */
            __IOM uint32_t SAIR215 : 1; /*!< [23..23] IR215 Security Attribution                                       */
            __IOM uint32_t SAIR216 : 1; /*!< [24..24] IR216 Security Attribution                                       */
            __IOM uint32_t SAIR217 : 1; /*!< [25..25] IR217 Security Attribution                                       */
            __IOM uint32_t SAIR218 : 1; /*!< [26..26] IR218 Security Attribution                                       */
            __IOM uint32_t SAIR219 : 1; /*!< [27..27] IR219 Security Attribution                                       */
            __IOM uint32_t SAIR220 : 1; /*!< [28..28] IR220 Security Attribution                                       */
            __IOM uint32_t SAIR221 : 1; /*!< [29..29] IR221 Security Attribution                                       */
            __IOM uint32_t SAIR222 : 1; /*!< [30..30] IR222 Security Attribution                                       */
            __IOM uint32_t SAIR223 : 1; /*!< [31..31] IR223 Security Attribution                                       */
        } ICU0SAR6_b;
    };

    union
    {
        __IOM uint32_t ICU0SAR7;        /*!< (@ 0x000000BC) ICU Security Attribution Register 7                        */

        struct
        {
            __IOM uint32_t SAIR224 : 1; /*!< [0..0] IR224 Security Attribution                                         */
            __IOM uint32_t SAIR225 : 1; /*!< [1..1] IR225 Security Attribution                                         */
            __IOM uint32_t SAIR226 : 1; /*!< [2..2] IR226 Security Attribution                                         */
            __IOM uint32_t SAIR227 : 1; /*!< [3..3] IR227 Security Attribution                                         */
            __IOM uint32_t SAIR228 : 1; /*!< [4..4] IR228 Security Attribution                                         */
            __IOM uint32_t SAIR229 : 1; /*!< [5..5] IR229 Security Attribution                                         */
            __IOM uint32_t SAIR230 : 1; /*!< [6..6] IR230 Security Attribution                                         */
            __IOM uint32_t SAIR231 : 1; /*!< [7..7] IR231 Security Attribution                                         */
            __IOM uint32_t SAIR232 : 1; /*!< [8..8] IR232 Security Attribution                                         */
            __IOM uint32_t SAIR233 : 1; /*!< [9..9] IR233 Security Attribution                                         */
            __IOM uint32_t SAIR234 : 1; /*!< [10..10] IR234 Security Attribution                                       */
            __IOM uint32_t SAIR235 : 1; /*!< [11..11] IR235 Security Attribution                                       */
            __IOM uint32_t SAIR236 : 1; /*!< [12..12] IR236 Security Attribution                                       */
            __IOM uint32_t SAIR237 : 1; /*!< [13..13] IR237 Security Attribution                                       */
            __IOM uint32_t SAIR238 : 1; /*!< [14..14] IR238 Security Attribution                                       */
            __IOM uint32_t SAIR239 : 1; /*!< [15..15] IR239 Security Attribution                                       */
            __IOM uint32_t SAIR240 : 1; /*!< [16..16] IR240 Security Attribution                                       */
            __IOM uint32_t SAIR241 : 1; /*!< [17..17] IR241 Security Attribution                                       */
            __IOM uint32_t SAIR242 : 1; /*!< [18..18] IR242 Security Attribution                                       */
            __IOM uint32_t SAIR243 : 1; /*!< [19..19] IR243 Security Attribution                                       */
            __IOM uint32_t SAIR244 : 1; /*!< [20..20] IR244 Security Attribution                                       */
            __IOM uint32_t SAIR245 : 1; /*!< [21..21] IR245 Security Attribution                                       */
            __IOM uint32_t SAIR246 : 1; /*!< [22..22] IR246 Security Attribution                                       */
            __IOM uint32_t SAIR247 : 1; /*!< [23..23] IR247 Security Attribution                                       */
            __IOM uint32_t SAIR248 : 1; /*!< [24..24] IR248 Security Attribution                                       */
            __IOM uint32_t SAIR249 : 1; /*!< [25..25] IR249 Security Attribution                                       */
            __IOM uint32_t SAIR250 : 1; /*!< [26..26] IR250 Security Attribution                                       */
            __IOM uint32_t SAIR251 : 1; /*!< [27..27] IR251 Security Attribution                                       */
            __IOM uint32_t SAIR252 : 1; /*!< [28..28] IR252 Security Attribution                                       */
            __IOM uint32_t SAIR253 : 1; /*!< [29..29] IR253 Security Attribution                                       */
            __IOM uint32_t SAIR254 : 1; /*!< [30..30] IR254 Security Attribution                                       */
            __IOM uint32_t SAIR255 : 1; /*!< [31..31] IR255 Security Attribution                                       */
        } ICU0SAR7_b;
    };
    __IM uint32_t RESERVED4[16];

    union
    {
        __IOM uint32_t BUSSARA;        /*!< (@ 0x00000100) Bus Security Attribution Register A                        */

        struct
        {
            __IOM uint32_t BUSSA0 : 1; /*!< [0..0] Bus Security Attribution A0                                        */
            uint32_t              : 31;
        } BUSSARA_b;
    };

    union
    {
        __IOM uint32_t BUSSARB;        /*!< (@ 0x00000104) Bus Security Attribution Register B                        */

        struct
        {
            __IOM uint32_t BUSSB0 : 1; /*!< [0..0] Bus Security Attribution B0                                        */
            uint32_t              : 31;
        } BUSSARB_b;
    };
    __IM uint32_t RESERVED5[2];

    union
    {
        __IOM uint32_t BUSSARC;        /*!< (@ 0x00000110) Bus Security Attribution Register C                        */

        struct
        {
            __IOM uint32_t BUSSC0 : 1; /*!< [0..0] Bus Security Attribution C0                                        */
            uint32_t              : 31;
        } BUSSARC_b;
    };
    __IM uint32_t RESERVED6[8];

    union
    {
        __IOM uint32_t MMPUSARB;       /*!< (@ 0x00000134) Master Memory-Protection Unit Security Attribute
                                        *                  Register B                                                 */

        struct
        {
            uint32_t                : 8;
            __IOM uint32_t MMPUBSA8 : 1; /*!< [8..8] MMPUB8 Security Select                                             */
            uint32_t                : 23;
        } MMPUSARB_b;
    };
    __IM uint32_t RESERVED7[2];

    union
    {
        __IOM uint32_t TFUSAR;         /*!< (@ 0x00000140) TFU Security Attribution Register                          */

        struct
        {
            __IOM uint32_t TFUSA : 1;  /*!< [0..0] TFU Security Attribution                                           */
            uint32_t             : 31;
        } TFUSAR_b;
    };

    union
    {
        __IOM uint32_t IFUSAR;         /*!< (@ 0x00000144) Branch Instruction Processing Accelerator Security
                                        *                  Attribute Register                                         */

        struct
        {
            __IOM uint32_t IFUSA : 1;  /*!< [0..0] Security Attribute                                                 */
            uint32_t             : 31;
        } IFUSAR_b;
    };
    __IM uint32_t RESERVED8[21];

    union
    {
        __IOM uint32_t EXDMACCHSAR;      /*!< (@ 0x0000019C) EXDMAC channel Security Attribution Register               */

        struct
        {
            __IOM uint32_t SADMACX0 : 1; /*!< [0..0] Security Attributes of Output and Registers for EXDMAC0
                                          *   Channel Select                                                            */
            __IOM uint32_t SADMACX1 : 1; /*!< [1..1] Security Attributes of Output and Registers for EXDMAC1
                                          *   Channel Select                                                            */
            uint32_t : 30;
        } EXDMACCHSAR_b;
    };

    union
    {
        __IOM uint32_t DMACCHSAR;        /*!< (@ 0x000001A0) DMAC channel Security Attribution Register                 */

        struct
        {
            __IOM uint32_t SADMAC00 : 1; /*!< [0..0] Security Attributes of Output and Registers for DMAC00
                                          *   Channel Select                                                            */
            __IOM uint32_t SADMAC01 : 1; /*!< [1..1] Security Attributes of Output and Registers for DMAC01
                                          *   Channel Select                                                            */
            __IOM uint32_t SADMAC02 : 1; /*!< [2..2] Security Attributes of Output and Registers for DMAC02
                                          *   Channel Select                                                            */
            __IOM uint32_t SADMAC03 : 1; /*!< [3..3] Security Attributes of Output and Registers for DMAC03
                                          *   Channel Select                                                            */
            __IOM uint32_t SADMAC04 : 1; /*!< [4..4] Security Attributes of Output and Registers for DMAC04
                                          *   Channel Select                                                            */
            __IOM uint32_t SADMAC05 : 1; /*!< [5..5] Security Attributes of Output and Registers for DMAC05
                                          *   Channel Select                                                            */
            __IOM uint32_t SADMAC06 : 1; /*!< [6..6] Security Attributes of Output and Registers for DMAC06
                                          *   Channel Select                                                            */
            __IOM uint32_t SADMAC07 : 1; /*!< [7..7] Security Attributes of Output and Registers for DMAC07
                                          *   Channel Select                                                            */
            uint32_t : 24;
        } DMACCHSAR_b;
    };
    __IM uint32_t  RESERVED9[151];
    __IOM uint32_t SRAMSABAR0;         /*!< (@ 0x00000400) SRAM0 Security Attribute Boundary Address Register         */
    __IOM uint32_t SRAMSABAR1;         /*!< (@ 0x00000404) SRAM1 Security Attribute Boundary Address Register         */
    __IM uint32_t  RESERVED10[62];

    union
    {
        __IOM uint32_t CACHESAR;         /*!< (@ 0x00000500) Cache Security Attribute Register                          */

        struct
        {
            __IOM uint32_t CACHESA  : 1; /*!< [0..0] Security Attribute Setting for Control Registers                   */
            uint32_t                : 1;
            __IOM uint32_t CACHEESA : 1; /*!< [2..2] Security Attribute Setting for Error Registers                     */
            uint32_t                : 29;
        } CACHESAR_b;
    };

    union
    {
        __IOM uint32_t LRMSAR;         /*!< (@ 0x00000504) LRAM Security Attribute Setting Register                   */

        struct
        {
            __IOM uint32_t LRMSA : 1;  /*!< [0..0] Security Attribute                                                 */
            uint32_t             : 31;
        } LRMSAR_b;
    };

    union
    {
        __IOM uint32_t LRMSABAR0;      /*!< (@ 0x00000508) LRAM0 Boundary Address Setting Register                    */

        struct
        {
            uint32_t               : 13;
            __IOM uint32_t LRMSABA : 6; /*!< [18..13] Security Attribute Boundary Address                              */
            uint32_t               : 13;
        } LRMSABAR0_b;
    };

    union
    {
        __IOM uint32_t LRMSABAR1;      /*!< (@ 0x0000050C) LRAM1 Boundary Address Setting Register                    */

        struct
        {
            uint32_t               : 13;
            __IOM uint32_t LRMSABA : 6; /*!< [18..13] Security Attribute Boundary Address                              */
            uint32_t               : 13;
        } LRMSABAR1_b;
    };
    __IM uint32_t RESERVED11[60];

    union
    {
        __IOM uint32_t TEVTRCR;           /*!< (@ 0x00000600) Trusted EVenT Route Control Register                       */

        struct
        {
            __IOM uint32_t TEVTE     : 1; /*!< [0..0] ELC Trusted Event Route Control                                    */
            __IOM uint32_t TEVTEICU0 : 1; /*!< [1..1] ICU Trusted Event Route Control 0                                  */
            uint32_t                 : 30;
        } TEVTRCR_b;
    };

    union
    {
        __IOM uint32_t ICUNSACR;       /*!< (@ 0x00000604) ICU Non-Secure Access Control Register                     */

        struct
        {
            __IOM uint32_t NSACE : 1;  /*!< [0..0] PIRk Register Non-Secure Access Enable                             */
            uint32_t             : 31;
        } ICUNSACR_b;
    };
    __IM uint32_t RESERVED12[6];

    union
    {
        __IOM uint32_t PRTZCR;         /*!< (@ 0x00000620) Protect Zone Interrupt Control Register                    */

        struct
        {
            __IOM uint32_t PRTZC : 1;  /*!< [0..0] Protect Zone Control                                               */
            uint32_t             : 31;
        } PRTZCR_b;
    };
} R_CPSCU_Type;                        /*!< Size = 1572 (0x624)                                                       */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_CPSCU_REG_H */
