/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_PORT_REG_H
#define R_PORT_REG_H

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/**
 * @brief R_PFS_PORT_PIN [PIN] (Pin Function Selects)
 */
typedef struct
{
    union
    {
        union
        {
            __IOM uint32_t PmnPFS;     /*!< (@ 0x00000000) Pin Function Control Register                              */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t            : 1;  /*!< [31..31] */
                __IOM uint32_t PSEL : 7;  /*!< [30..24] Port Function SelectThese bits select the peripheral
                                           *   function. For individual pin functions, see the MPC table                 */
                uint32_t             : 7; /*!< [23..17] */
                __IOM uint32_t PMR   : 1; /*!< [16..16] Port Mode Control                                                */
                __IOM uint32_t ASEL  : 1; /*!< [15..15] Analog Input enable                                              */
                __IOM uint32_t ISEL  : 1; /*!< [14..14] IRQ input enable                                                 */
                __IOM uint32_t EOFR  : 2; /*!< [13..12] Event on Falling/Event on Rising.                                */
                __IOM uint32_t DSCR  : 4; /*!< [11..8] Drive Strength Control Register                                  */
                uint32_t             : 1; /*!< [7..7] */
                __IOM uint32_t NCODR : 1; /*!< [6..6] N-Channel Open Drain Control                                       */
                uint32_t             : 1; /*!< [5..5] */
                __IOM uint32_t PCR   : 1; /*!< [4..4] Pull-up Control                                                    */
                uint32_t             : 1; /*!< [3..3] */
                __IOM uint32_t PDR   : 1; /*!< [2..2] Port Direction                                                     */
                __IM uint32_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint32_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
#else
                __IOM uint32_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
                __IM uint32_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint32_t PDR   : 1; /*!< [2..2] Port Direction                                                     */
                uint32_t             : 1; /*!< [3..3] */
                __IOM uint32_t PCR   : 1; /*!< [4..4] Pull-up Control                                                    */
                uint32_t             : 1; /*!< [5..5] */
                __IOM uint32_t NCODR : 1; /*!< [6..6] N-Channel Open Drain Control                                       */
                uint32_t             : 1; /*!< [7..7] */
                __IOM uint32_t DSCR  : 4; /*!< [11..8] Drive Strength Control Register                                  */
                __IOM uint32_t EOFR  : 2; /*!< [13..12] Event on Falling/Event on Rising.                                */
                __IOM uint32_t ISEL  : 1; /*!< [14..14] IRQ input enable                                                 */
                __IOM uint32_t ASEL  : 1; /*!< [15..15] Analog Input enable                                              */
                __IOM uint32_t PMR   : 1; /*!< [16..16] Port Mode Control                                                */
                uint32_t             : 7; /*!< [23..17] */
                __IOM uint32_t PSEL  : 7; /*!< [30..24] Port Function SelectThese bits select the peripheral
                                           *   function. For individual pin functions, see the MPC table                 */
                uint32_t : 1;             /*!< [31..31] */
#endif
            } PmnPFS_b;
        };

        union
        {
            __IOM uint16_t PmnPFS_HA;  /*!< (@ 0x00000000) Pin Function Control Register                              */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IOM uint16_t ASEL  : 1; /*!< [15..15] Analog Input enable                                              */
                __IOM uint16_t ISEL  : 1; /*!< [14..14] IRQ input enable                                                 */
                __IOM uint16_t EOFR  : 2; /*!< [13..12] Event on Falling/Event on Rising.                                */
                __IOM uint16_t DSCR  : 4; /*!< [11..8] Drive Strength Control Register                                  */
                uint16_t             : 1; /*!< [7..7] */
                __IOM uint16_t NCODR : 1; /*!< [6..6] N-Channel Open Drain Control                                       */
                uint16_t             : 1; /*!< [5..5] */
                __IOM uint16_t PCR   : 1; /*!< [4..4] Pull-up Control                                                    */
                uint16_t             : 1; /*!< [3..3] */
                __IOM uint16_t PDR   : 1; /*!< [2..2] Port Direction                                                     */
                __IM uint16_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint16_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
#else
                __IOM uint16_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
                __IM uint16_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint16_t PDR   : 1; /*!< [2..2] Port Direction                                                     */
                uint16_t             : 1; /*!< [3..3] */
                __IOM uint16_t PCR   : 1; /*!< [4..4] Pull-up Control                                                    */
                uint16_t             : 1; /*!< [5..5] */
                __IOM uint16_t NCODR : 1; /*!< [6..6] N-Channel Open Drain Control                                       */
                uint16_t             : 1; /*!< [7..7] */
                __IOM uint16_t DSCR  : 4; /*!< [11..8] Drive Strength Control Register                                  */
                __IOM uint16_t EOFR  : 2; /*!< [13..12] Event on Falling/Event on Rising.                                */
                __IOM uint16_t ISEL  : 1; /*!< [14..14] IRQ input enable                                                 */
                __IOM uint16_t ASEL  : 1; /*!< [15..15] Analog Input enable                                              */
#endif
            } PmnPFS_HA_b;
        };

        union
        {
            __IOM uint8_t PmnPFS_BY;   /*!< (@ 0x00000000) Pin Function Control Register                              */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint8_t             : 1; /*!< [7..7] */
                __IOM uint8_t NCODR : 1; /*!< [6..6] N-Channel Open Drain Control                                       */
                uint8_t             : 1; /*!< [5..5] */
                __IOM uint8_t PCR   : 1; /*!< [4..4] Pull-up Control                                                    */
                uint8_t             : 1; /*!< [3..3] */
                __IOM uint8_t PDR   : 1; /*!< [2..2] Port Direction                                                     */
                __IM uint8_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint8_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
#else
                __IOM uint8_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
                __IM uint8_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint8_t PDR   : 1; /*!< [2..2] Port Direction                                                     */
                uint8_t             : 1; /*!< [3..3] */
                __IOM uint8_t PCR   : 1; /*!< [4..4] Pull-up Control                                                    */
                uint8_t             : 1; /*!< [5..5] */
                __IOM uint8_t NCODR : 1; /*!< [6..6] N-Channel Open Drain Control                                       */
                uint8_t             : 1; /*!< [7..7] */
#endif
            } PmnPFS_BY_b;
        };
    };
} R_PFS_PORT_PIN_Type;                 /*!< Size = 4 (0x4)                                                            */

/**
 * @brief R_PFS_PORT [PORT] (Port [0..16])
 */
typedef struct
{
    __IOM R_PFS_PORT_PIN_Type PIN[16]; /*!< (@ 0x00000000) Pin Function Selects                                       */
} R_PFS_PORT_Type;                     /*!< Size = 64 (0x40)                                                          */

/**
 * @brief R_PMISC_PMSAR [PMSAR] (Port Security Attribution Register)
 */
typedef struct
{
    __IOM uint16_t PMSAR;              /*!< (@ 0x00000000) Port Security Attribution Register                         */
    __IM uint16_t  RESERVED;
} R_PMISC_PMSAR_Type;                  /*!< Size = 4 (0x4)                                                            */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                          R_PORT0                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief I/O Ports (R_PORT0)
 */

typedef struct                         /*!< (@ 0x87C00000) R_PORT0 Structure                                          */
{
    union
    {
        union
        {
            __IOM uint32_t PCNTR1;     /*!< (@ 0x00000000) Port Control Register 1                                    */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IOM uint32_t PODR : 16; /*!< [31..16] Pmn Output Data                                                  */
                __IOM uint32_t PDR  : 16; /*!< [15..0] Pmn Direction                                                     */
#else
                __IOM uint32_t PDR  : 16; /*!< [15..0] Pmn Direction                                                     */
                __IOM uint32_t PODR : 16; /*!< [31..16] Pmn Output Data                                                  */
#endif
            } PCNTR1_b;
        };

        struct
        {
            union
            {
                __IOM uint16_t PDR;    /*!< (@ 0x00000000) Data direction register                                    */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    __IOM uint16_t PDR15 : 1; /*!< [15..15] Pmn Direction                                                    */
                    __IOM uint16_t PDR14 : 1; /*!< [14..14] Pmn Direction                                                    */
                    __IOM uint16_t PDR13 : 1; /*!< [13..13] Pmn Direction                                                    */
                    __IOM uint16_t PDR12 : 1; /*!< [12..12] Pmn Direction                                                    */
                    __IOM uint16_t PDR11 : 1; /*!< [11..11] Pmn Direction                                                    */
                    __IOM uint16_t PDR10 : 1; /*!< [10..10] Pmn Direction                                                    */
                    __IOM uint16_t PDR9  : 1; /*!< [9..9] Pmn Direction                                                      */
                    __IOM uint16_t PDR8  : 1; /*!< [8..8] Pmn Direction                                                      */
                    __IOM uint16_t PDR7  : 1; /*!< [7..7] Pmn Direction                                                      */
                    __IOM uint16_t PDR6  : 1; /*!< [6..6] Pmn Direction                                                      */
                    __IOM uint16_t PDR5  : 1; /*!< [5..5] Pmn Direction                                                      */
                    __IOM uint16_t PDR4  : 1; /*!< [4..4] Pmn Direction                                                      */
                    __IOM uint16_t PDR3  : 1; /*!< [3..3] Pmn Direction                                                      */
                    __IOM uint16_t PDR2  : 1; /*!< [2..2] Pmn Direction                                                      */
                    __IOM uint16_t PDR1  : 1; /*!< [1..1] Pmn Direction                                                      */
                    __IOM uint16_t PDR0  : 1; /*!< [0..0] Pmn Direction                                                      */
#else
                    __IOM uint16_t PDR0  : 1; /*!< [0..0] Pmn Direction                                                      */
                    __IOM uint16_t PDR1  : 1; /*!< [1..1] Pmn Direction                                                      */
                    __IOM uint16_t PDR2  : 1; /*!< [2..2] Pmn Direction                                                      */
                    __IOM uint16_t PDR3  : 1; /*!< [3..3] Pmn Direction                                                      */
                    __IOM uint16_t PDR4  : 1; /*!< [4..4] Pmn Direction                                                      */
                    __IOM uint16_t PDR5  : 1; /*!< [5..5] Pmn Direction                                                      */
                    __IOM uint16_t PDR6  : 1; /*!< [6..6] Pmn Direction                                                      */
                    __IOM uint16_t PDR7  : 1; /*!< [7..7] Pmn Direction                                                      */
                    __IOM uint16_t PDR8  : 1; /*!< [8..8] Pmn Direction                                                      */
                    __IOM uint16_t PDR9  : 1; /*!< [9..9] Pmn Direction                                                      */
                    __IOM uint16_t PDR10 : 1; /*!< [10..10] Pmn Direction                                                    */
                    __IOM uint16_t PDR11 : 1; /*!< [11..11] Pmn Direction                                                    */
                    __IOM uint16_t PDR12 : 1; /*!< [12..12] Pmn Direction                                                    */
                    __IOM uint16_t PDR13 : 1; /*!< [13..13] Pmn Direction                                                    */
                    __IOM uint16_t PDR14 : 1; /*!< [14..14] Pmn Direction                                                    */
                    __IOM uint16_t PDR15 : 1; /*!< [15..15] Pmn Direction                                                    */
#endif
                } PDR_b;
            };

            union
            {
                __IOM uint16_t PODR;   /*!< (@ 0x00000002) Output data register                                       */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    __IOM uint16_t PODR15 : 1; /*!< [15..15] Pmn Output Data                                                  */
                    __IOM uint16_t PODR14 : 1; /*!< [14..14] Pmn Output Data                                                  */
                    __IOM uint16_t PODR13 : 1; /*!< [13..13] Pmn Output Data                                                  */
                    __IOM uint16_t PODR12 : 1; /*!< [12..12] Pmn Output Data                                                  */
                    __IOM uint16_t PODR11 : 1; /*!< [11..11] Pmn Output Data                                                  */
                    __IOM uint16_t PODR10 : 1; /*!< [10..10] Pmn Output Data                                                  */
                    __IOM uint16_t PODR9  : 1; /*!< [9..9] Pmn Output Data                                                    */
                    __IOM uint16_t PODR8  : 1; /*!< [8..8] Pmn Output Data                                                    */
                    __IOM uint16_t PODR7  : 1; /*!< [7..7] Pmn Output Data                                                    */
                    __IOM uint16_t PODR6  : 1; /*!< [6..6] Pmn Output Data                                                    */
                    __IOM uint16_t PODR5  : 1; /*!< [5..5] Pmn Output Data                                                    */
                    __IOM uint16_t PODR4  : 1; /*!< [4..4] Pmn Output Data                                                    */
                    __IOM uint16_t PODR3  : 1; /*!< [3..3] Pmn Output Data                                                    */
                    __IOM uint16_t PODR2  : 1; /*!< [2..2] Pmn Output Data                                                    */
                    __IOM uint16_t PODR1  : 1; /*!< [1..1] Pmn Output Data                                                    */
                    __IOM uint16_t PODR0  : 1; /*!< [0..0] Pmn Output Data                                                    */
#else
                    __IOM uint16_t PODR0  : 1; /*!< [0..0] Pmn Output Data                                                    */
                    __IOM uint16_t PODR1  : 1; /*!< [1..1] Pmn Output Data                                                    */
                    __IOM uint16_t PODR2  : 1; /*!< [2..2] Pmn Output Data                                                    */
                    __IOM uint16_t PODR3  : 1; /*!< [3..3] Pmn Output Data                                                    */
                    __IOM uint16_t PODR4  : 1; /*!< [4..4] Pmn Output Data                                                    */
                    __IOM uint16_t PODR5  : 1; /*!< [5..5] Pmn Output Data                                                    */
                    __IOM uint16_t PODR6  : 1; /*!< [6..6] Pmn Output Data                                                    */
                    __IOM uint16_t PODR7  : 1; /*!< [7..7] Pmn Output Data                                                    */
                    __IOM uint16_t PODR8  : 1; /*!< [8..8] Pmn Output Data                                                    */
                    __IOM uint16_t PODR9  : 1; /*!< [9..9] Pmn Output Data                                                    */
                    __IOM uint16_t PODR10 : 1; /*!< [10..10] Pmn Output Data                                                  */
                    __IOM uint16_t PODR11 : 1; /*!< [11..11] Pmn Output Data                                                  */
                    __IOM uint16_t PODR12 : 1; /*!< [12..12] Pmn Output Data                                                  */
                    __IOM uint16_t PODR13 : 1; /*!< [13..13] Pmn Output Data                                                  */
                    __IOM uint16_t PODR14 : 1; /*!< [14..14] Pmn Output Data                                                  */
                    __IOM uint16_t PODR15 : 1; /*!< [15..15] Pmn Output Data                                                  */
#endif
                } PODR_b;
            };
        };
    };

    union
    {
        union
        {
            __IM uint32_t PCNTR2;      /*!< (@ 0x00000004) Port Control Register 2                                    */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IM uint32_t EIDR : 16; /*!< [31..16] Pmn Event Input Data                                             */
                __IM uint32_t PIDR : 16; /*!< [15..0] Pmn Input Data                                                    */
#else
                __IM uint32_t PIDR : 16; /*!< [15..0] Pmn Input Data                                                    */
                __IM uint32_t EIDR : 16; /*!< [31..16] Pmn Event Input Data                                             */
#endif
            } PCNTR2_b;
        };

        struct
        {
            union
            {
                __IM uint16_t PIDR;    /*!< (@ 0x00000004) Input data register                                        */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    __IM uint16_t PIDR15 : 1; /*!< [15..15] Pmn Input Data                                                   */
                    __IM uint16_t PIDR14 : 1; /*!< [14..14] Pmn Input Data                                                   */
                    __IM uint16_t PIDR13 : 1; /*!< [13..13] Pmn Input Data                                                   */
                    __IM uint16_t PIDR12 : 1; /*!< [12..12] Pmn Input Data                                                   */
                    __IM uint16_t PIDR11 : 1; /*!< [11..11] Pmn Input Data                                                   */
                    __IM uint16_t PIDR10 : 1; /*!< [10..10] Pmn Input Data                                                   */
                    __IM uint16_t PIDR9  : 1; /*!< [9..9] Pmn Input Data                                                     */
                    __IM uint16_t PIDR8  : 1; /*!< [8..8] Pmn Input Data                                                     */
                    __IM uint16_t PIDR7  : 1; /*!< [7..7] Pmn Input Data                                                     */
                    __IM uint16_t PIDR6  : 1; /*!< [6..6] Pmn Input Data                                                     */
                    __IM uint16_t PIDR5  : 1; /*!< [5..5] Pmn Input Data                                                     */
                    __IM uint16_t PIDR4  : 1; /*!< [4..4] Pmn Input Data                                                     */
                    __IM uint16_t PIDR3  : 1; /*!< [3..3] Pmn Input Data                                                     */
                    __IM uint16_t PIDR2  : 1; /*!< [2..2] Pmn Input Data                                                     */
                    __IM uint16_t PIDR1  : 1; /*!< [1..1] Pmn Input Data                                                     */
                    __IM uint16_t PIDR0  : 1; /*!< [0..0] Pmn Input Data                                                     */
#else
                    __IM uint16_t PIDR0  : 1; /*!< [0..0] Pmn Input Data                                                     */
                    __IM uint16_t PIDR1  : 1; /*!< [1..1] Pmn Input Data                                                     */
                    __IM uint16_t PIDR2  : 1; /*!< [2..2] Pmn Input Data                                                     */
                    __IM uint16_t PIDR3  : 1; /*!< [3..3] Pmn Input Data                                                     */
                    __IM uint16_t PIDR4  : 1; /*!< [4..4] Pmn Input Data                                                     */
                    __IM uint16_t PIDR5  : 1; /*!< [5..5] Pmn Input Data                                                     */
                    __IM uint16_t PIDR6  : 1; /*!< [6..6] Pmn Input Data                                                     */
                    __IM uint16_t PIDR7  : 1; /*!< [7..7] Pmn Input Data                                                     */
                    __IM uint16_t PIDR8  : 1; /*!< [8..8] Pmn Input Data                                                     */
                    __IM uint16_t PIDR9  : 1; /*!< [9..9] Pmn Input Data                                                     */
                    __IM uint16_t PIDR10 : 1; /*!< [10..10] Pmn Input Data                                                   */
                    __IM uint16_t PIDR11 : 1; /*!< [11..11] Pmn Input Data                                                   */
                    __IM uint16_t PIDR12 : 1; /*!< [12..12] Pmn Input Data                                                   */
                    __IM uint16_t PIDR13 : 1; /*!< [13..13] Pmn Input Data                                                   */
                    __IM uint16_t PIDR14 : 1; /*!< [14..14] Pmn Input Data                                                   */
                    __IM uint16_t PIDR15 : 1; /*!< [15..15] Pmn Input Data                                                   */
#endif
                } PIDR_b;
            };

            union
            {
                __IM uint16_t EIDR;    /*!< (@ 0x00000006) Event input data register                                  */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    uint16_t            : 8; /*!< [15..8] reserved                                             */
                    __IM uint16_t EIDR7 : 1; /*!< [7..7] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR6 : 1; /*!< [6..6] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR5 : 1; /*!< [5..5] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR4 : 1; /*!< [4..4] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR3 : 1; /*!< [3..3] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR2 : 1; /*!< [2..2] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR1 : 1; /*!< [1..1] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR0 : 1; /*!< [0..0] Pmn Event Input Data                                               */
#else
                    __IM uint16_t EIDR0 : 1; /*!< [0..0] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR1 : 1; /*!< [1..1] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR2 : 1; /*!< [2..2] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR3 : 1; /*!< [3..3] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR4 : 1; /*!< [4..4] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR5 : 1; /*!< [5..5] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR6 : 1; /*!< [6..6] Pmn Event Input Data                                               */
                    __IM uint16_t EIDR7 : 1; /*!< [7..7] Pmn Event Input Data                                               */
                    uint16_t            : 8; /*!< [15..8] reserved                                             */
#endif
                } EIDR_b;
            };
        };
    };

    union
    {
        union
        {
            __OM uint32_t PCNTR3;      /*!< (@ 0x00000008) Port Control Register 3                                    */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __OM uint32_t PORR : 16; /*!< [31..16] Pmn Output Reset                                                 */
                __OM uint32_t POSR : 16; /*!< [15..0] Pmn Output Set                                                    */
#else
                __OM uint32_t POSR : 16; /*!< [15..0] Pmn Output Set                                                    */
                __OM uint32_t PORR : 16; /*!< [31..16] Pmn Output Reset                                                 */
#endif
            } PCNTR3_b;
        };

        struct
        {
            union
            {
                __OM uint16_t POSR;    /*!< (@ 0x00000008) Output reset register                                      */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    __OM uint16_t POSR15 : 1; /*!< [15..15] Pmn Output Set                                                   */
                    __OM uint16_t POSR14 : 1; /*!< [14..14] Pmn Output Set                                                   */
                    __OM uint16_t POSR13 : 1; /*!< [13..13] Pmn Output Set                                                   */
                    __OM uint16_t POSR12 : 1; /*!< [12..12] Pmn Output Set                                                   */
                    __OM uint16_t POSR11 : 1; /*!< [11..11] Pmn Output Set                                                   */
                    __OM uint16_t POSR10 : 1; /*!< [10..10] Pmn Output Set                                                   */
                    __OM uint16_t POSR9  : 1; /*!< [9..9] Pmn Output Set                                                     */
                    __OM uint16_t POSR8  : 1; /*!< [8..8] Pmn Output Set                                                     */
                    __OM uint16_t POSR7  : 1; /*!< [7..7] Pmn Output Set                                                     */
                    __OM uint16_t POSR6  : 1; /*!< [6..6] Pmn Output Set                                                     */
                    __OM uint16_t POSR5  : 1; /*!< [5..5] Pmn Output Set                                                     */
                    __OM uint16_t POSR4  : 1; /*!< [4..4] Pmn Output Set                                                     */
                    __OM uint16_t POSR3  : 1; /*!< [3..3] Pmn Output Set                                                     */
                    __OM uint16_t POSR2  : 1; /*!< [2..2] Pmn Output Set                                                     */
                    __OM uint16_t POSR1  : 1; /*!< [1..1] Pmn Output Set                                                     */
                    __OM uint16_t POSR0  : 1; /*!< [0..0] Pmn Output Set                                                     */
#else
                    __OM uint16_t POSR0  : 1; /*!< [0..0] Pmn Output Set                                                     */
                    __OM uint16_t POSR1  : 1; /*!< [1..1] Pmn Output Set                                                     */
                    __OM uint16_t POSR2  : 1; /*!< [2..2] Pmn Output Set                                                     */
                    __OM uint16_t POSR3  : 1; /*!< [3..3] Pmn Output Set                                                     */
                    __OM uint16_t POSR4  : 1; /*!< [4..4] Pmn Output Set                                                     */
                    __OM uint16_t POSR5  : 1; /*!< [5..5] Pmn Output Set                                                     */
                    __OM uint16_t POSR6  : 1; /*!< [6..6] Pmn Output Set                                                     */
                    __OM uint16_t POSR7  : 1; /*!< [7..7] Pmn Output Set                                                     */
                    __OM uint16_t POSR8  : 1; /*!< [8..8] Pmn Output Set                                                     */
                    __OM uint16_t POSR9  : 1; /*!< [9..9] Pmn Output Set                                                     */
                    __OM uint16_t POSR10 : 1; /*!< [10..10] Pmn Output Set                                                   */
                    __OM uint16_t POSR11 : 1; /*!< [11..11] Pmn Output Set                                                   */
                    __OM uint16_t POSR12 : 1; /*!< [12..12] Pmn Output Set                                                   */
                    __OM uint16_t POSR13 : 1; /*!< [13..13] Pmn Output Set                                                   */
                    __OM uint16_t POSR14 : 1; /*!< [14..14] Pmn Output Set                                                   */
                    __OM uint16_t POSR15 : 1; /*!< [15..15] Pmn Output Set                                                   */
#endif
                } POSR_b;
            };

            union
            {
                __OM uint16_t PORR;    /*!< (@ 0x0000000A) Output set register                                        */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    __OM uint16_t PORR15 : 1; /*!< [15..15] Pmn Output Reset                                                 */
                    __OM uint16_t PORR14 : 1; /*!< [14..14] Pmn Output Reset                                                 */
                    __OM uint16_t PORR13 : 1; /*!< [13..13] Pmn Output Reset                                                 */
                    __OM uint16_t PORR12 : 1; /*!< [12..12] Pmn Output Reset                                                 */
                    __OM uint16_t PORR11 : 1; /*!< [11..11] Pmn Output Reset                                                 */
                    __OM uint16_t PORR10 : 1; /*!< [10..10] Pmn Output Reset                                                 */
                    __OM uint16_t PORR9  : 1; /*!< [9..9] Pmn Output Reset                                                   */
                    __OM uint16_t PORR8  : 1; /*!< [8..8] Pmn Output Reset                                                   */
                    __OM uint16_t PORR7  : 1; /*!< [7..7] Pmn Output Reset                                                   */
                    __OM uint16_t PORR6  : 1; /*!< [6..6] Pmn Output Reset                                                   */
                    __OM uint16_t PORR5  : 1; /*!< [5..5] Pmn Output Reset                                                   */
                    __OM uint16_t PORR4  : 1; /*!< [4..4] Pmn Output Reset                                                   */
                    __OM uint16_t PORR3  : 1; /*!< [3..3] Pmn Output Reset                                                   */
                    __OM uint16_t PORR2  : 1; /*!< [2..2] Pmn Output Reset                                                   */
                    __OM uint16_t PORR1  : 1; /*!< [1..1] Pmn Output Reset                                                   */
                    __OM uint16_t PORR0  : 1; /*!< [0..0] Pmn Output Reset                                                   */
#else
                    __OM uint16_t PORR0  : 1; /*!< [0..0] Pmn Output Reset                                                   */
                    __OM uint16_t PORR1  : 1; /*!< [1..1] Pmn Output Reset                                                   */
                    __OM uint16_t PORR2  : 1; /*!< [2..2] Pmn Output Reset                                                   */
                    __OM uint16_t PORR3  : 1; /*!< [3..3] Pmn Output Reset                                                   */
                    __OM uint16_t PORR4  : 1; /*!< [4..4] Pmn Output Reset                                                   */
                    __OM uint16_t PORR5  : 1; /*!< [5..5] Pmn Output Reset                                                   */
                    __OM uint16_t PORR6  : 1; /*!< [6..6] Pmn Output Reset                                                   */
                    __OM uint16_t PORR7  : 1; /*!< [7..7] Pmn Output Reset                                                   */
                    __OM uint16_t PORR8  : 1; /*!< [8..8] Pmn Output Reset                                                   */
                    __OM uint16_t PORR9  : 1; /*!< [9..9] Pmn Output Reset                                                   */
                    __OM uint16_t PORR10 : 1; /*!< [10..10] Pmn Output Reset                                                 */
                    __OM uint16_t PORR11 : 1; /*!< [11..11] Pmn Output Reset                                                 */
                    __OM uint16_t PORR12 : 1; /*!< [12..12] Pmn Output Reset                                                 */
                    __OM uint16_t PORR13 : 1; /*!< [13..13] Pmn Output Reset                                                 */
                    __OM uint16_t PORR14 : 1; /*!< [14..14] Pmn Output Reset                                                 */
                    __OM uint16_t PORR15 : 1; /*!< [15..15] Pmn Output Reset                                                 */
#endif
                } PORR_b;
            };
        };
    };

    union
    {
        union
        {
            __IOM uint32_t PCNTR4;     /*!< (@ 0x0000000C) Port Control Register 4                                    */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IOM uint32_t EORR : 16; /*!< [31..16] Pmn Event Output Reset                                           */
                __IOM uint32_t EOSR : 16; /*!< [15..0] Pmn Event Output Set                                              */
#else
                __IOM uint32_t EOSR : 16; /*!< [15..0] Pmn Event Output Set                                              */
                __IOM uint32_t EORR : 16; /*!< [31..16] Pmn Event Output Reset                                           */
#endif
            } PCNTR4_b;
        };

        struct
        {
            union
            {
                __IOM uint16_t EOSR;   /*!< (@ 0x0000000C) Event output reset register                                */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    uint16_t             : 8; /*!< [15..8]                                               */
                    __IOM uint16_t EOSR7 : 1; /*!< [7..7] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR6 : 1; /*!< [6..6] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR5 : 1; /*!< [5..5] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR4 : 1; /*!< [4..4] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR3 : 1; /*!< [3..3] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR2 : 1; /*!< [2..2] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR1 : 1; /*!< [1..1] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR0 : 1; /*!< [0..0] Pmn Event Output Set                                               */
#else
                    __IOM uint16_t EOSR0 : 1; /*!< [0..0] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR1 : 1; /*!< [1..1] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR2 : 1; /*!< [2..2] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR3 : 1; /*!< [3..3] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR4 : 1; /*!< [4..4] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR5 : 1; /*!< [5..5] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR6 : 1; /*!< [6..6] Pmn Event Output Set                                               */
                    __IOM uint16_t EOSR7 : 1; /*!< [7..7] Pmn Event Output Set                                               */
                    uint16_t             : 8; /*!< [15..8]                                               */
#endif
                } EOSR_b;
            };

            union
            {
                __IOM uint16_t EORR;   /*!< (@ 0x0000000E) Event output set register                                  */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    uint16_t             : 8; /*!< [15..8]                                              */
                    __IOM uint16_t EORR7 : 1; /*!< [7..7] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR6 : 1; /*!< [6..6] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR5 : 1; /*!< [5..5] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR4 : 1; /*!< [4..4] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR3 : 1; /*!< [3..3] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR2 : 1; /*!< [2..2] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR1 : 1; /*!< [1..1] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR0 : 1; /*!< [0..0] Pmn Event Output Reset                                             */
#else
                    __IOM uint16_t EORR0 : 1; /*!< [0..0] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR1 : 1; /*!< [1..1] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR2 : 1; /*!< [2..2] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR3 : 1; /*!< [3..3] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR4 : 1; /*!< [4..4] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR5 : 1; /*!< [5..5] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR6 : 1; /*!< [6..6] Pmn Event Output Reset                                             */
                    __IOM uint16_t EORR7 : 1; /*!< [7..7] Pmn Event Output Reset                                             */
                    uint16_t             : 8; /*!< [15..8]                                              */
#endif
                } EORR_b;
            };
        };
    };
} R_PORT0_Type;                        /*!< Size = 16 (0x10)                                                          */

/* =========================================================================================================================== */
/* ================                                           R_PFS                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief I/O Ports-PFS (R_PFS)
 */

typedef struct                         /*!< (@ 0x87C0_0800) R_PFS Structure                                            */
{
    __IOM R_PFS_PORT_Type PORT[17];    /*!< (@ 0x00000000) Port [0..16]                                               */
} R_PFS_Type;                          /*!< Size = 960 (0x3c0)                                                        */

/* =========================================================================================================================== */
/* ================                                          R_PMISC                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief I/O Ports-MISC (R_PMISC)
 */

typedef struct                         /*!< (@ 0x86C00D00) R_PMISC Structure                                          */
{
    union
    {
        __IOM uint8_t PFENET;          /*!< (@ 0x00000000) Ethernet Control Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 3;
            __IOM uint8_t PHYMODE0 : 1; /*!< [4..4] Ethernet Mode Setting ch0                                          */
            uint8_t                : 4;
#else
            uint8_t                : 4;
            __IOM uint8_t PHYMODE0 : 1; /*!< [4..4] Ethernet Mode Setting ch0                                          */
            uint8_t                : 3;
#endif
        } PFENET_b;
    };
    __IM uint8_t  RESERVED;
    __IM uint16_t RESERVED1[5];

    union
    {
        __IOM uint8_t PWPR;            /*!< (@ 0x0000000C) Write-Protect Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t B0WI  : 1;   /*!< [7..7] PFSWE Bit Write Disable                                            */
            __IOM uint8_t PFSWE : 1;   /*!< [6..6] PmnPFS Register Write                                              */
            uint8_t             : 6;
#else
            uint8_t             : 6;
            __IOM uint8_t PFSWE : 1;   /*!< [6..6] PmnPFS Register Write                                              */
            __IOM uint8_t B0WI  : 1;   /*!< [7..7] PFSWE Bit Write Disable                                            */
#endif
        } PWPR_b;
    };
    __IM uint8_t  RESERVED2;
    __IM uint16_t RESERVED3[3];

    union
    {
        __IOM uint8_t PWPRS;           /*!< (@ 0x00000014) Write-Protect Register for Secure                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t B0WI  : 1;   /*!< [7..7] PFSWE Bit Write Disable                                            */
            __IOM uint8_t PFSWE : 1;   /*!< [6..6] PmnPFS Register Write                                              */
            uint8_t             : 6;
#else
            uint8_t             : 6;
            __IOM uint8_t PFSWE : 1;   /*!< [6..6] PmnPFS Register Write                                              */
            __IOM uint8_t B0WI  : 1;   /*!< [7..7] PFSWE Bit Write Disable                                            */
#endif
        } PWPRS_b;
    };
    __IM uint8_t             RESERVED4;
    __IM uint16_t            RESERVED5[13];
    __IOM R_PMISC_PMSAR_Type PMSAR[17]; /*!< (@ 0x00000030) Port Security Attribution Register                         */
} R_PMISC_Type;                         /*!< Size = 108 (0x6c)                                                         */

#endif /* R_PORT_REG_H */
