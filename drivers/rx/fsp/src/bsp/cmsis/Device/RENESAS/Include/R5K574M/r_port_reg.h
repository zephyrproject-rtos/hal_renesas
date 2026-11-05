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

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief R_PFS_PORT_PIN [PIN] (Pin Function Selects)
 */
typedef struct
{
    union
    {
        union
        {
            __IOM uint32_t PmnPFS;     /*!< (@ 0x00000000) Pin Function Selection Register                            */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t            : 1;
                __IOM uint32_t PSEL : 7;  /*!< [30..24] Peripheral Function SelectThese bits are used to select
                                           *   a peripheral function. For the peripheral functions that
                                           *   are selectable for each pin, see the relevant tables in
                                           *   this section.                                                             */
                uint32_t             : 7;
                __IOM uint32_t PMR   : 1; /*!< [16..16] Port Mode Select                                                 */
                __IOM uint32_t ASEL  : 1; /*!< [15..15] Analog Function Select                                           */
                __IOM uint32_t ISEL  : 1; /*!< [14..14] Interrupt Input Function Select                                  */
                __IOM uint32_t EOFR  : 2; /*!< [13..12] Port Group Input Edge Detection Select                           */
                __IOM uint32_t DSCR  : 4; /*!< [11..8] Driving Ability Select                                            */
                uint32_t             : 1;
                __IOM uint32_t NCODR : 1; /*!< [6..6] N-channel Open-Drain Output Select                                 */
                uint32_t             : 1;
                __IOM uint32_t PCR   : 1; /*!< [4..4] Input Pull-up Resistor Control                                     */
                uint32_t             : 1;
                __IOM uint32_t PDR   : 1; /*!< [2..2] Port I/O Direction Select                                          */
                __IM uint32_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint32_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
#else
                __IOM uint32_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
                __IM uint32_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint32_t PDR   : 1; /*!< [2..2] Port I/O Direction Select                                          */
                uint32_t             : 1;
                __IOM uint32_t PCR   : 1; /*!< [4..4] Input Pull-up Resistor Control                                     */
                uint32_t             : 1;
                __IOM uint32_t NCODR : 1; /*!< [6..6] N-channel Open-Drain Output Select                                 */
                uint32_t             : 1;
                __IOM uint32_t DSCR  : 4; /*!< [11..8] Driving Ability Select                                            */
                __IOM uint32_t EOFR  : 2; /*!< [13..12] Port Group Input Edge Detection Select                           */
                __IOM uint32_t ISEL  : 1; /*!< [14..14] Interrupt Input Function Select                                  */
                __IOM uint32_t ASEL  : 1; /*!< [15..15] Analog Function Select                                           */
                __IOM uint32_t PMR   : 1; /*!< [16..16] Port Mode Select                                                 */
                uint32_t             : 7;
                __IOM uint32_t PSEL  : 7; /*!< [30..24] Peripheral Function SelectThese bits are used to select
                                           *   a peripheral function. For the peripheral functions that
                                           *   are selectable for each pin, see the relevant tables in
                                           *   this section.                                                             */
                uint32_t : 1;
#endif
            } PmnPFS_b;
        };

        union
        {
            __IOM uint16_t PmnPFS_HA;  /*!< (@ 0x00000000) Pin Function Selection Register                            */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IOM uint16_t ASEL  : 1; /*!< [15..15] Analog Function Select                                           */
                __IOM uint16_t ISEL  : 1; /*!< [14..14] Interrupt Input Function Select                                  */
                __IOM uint16_t EOFR  : 2; /*!< [13..12] Port Group Input Edge Detection Select                           */
                __IOM uint16_t DSCR  : 4; /*!< [11..8] Driving Ability Select                                            */
                uint16_t             : 1;
                __IOM uint16_t NCODR : 1; /*!< [6..6] N-channel Open-Drain Output Select                                 */
                uint16_t             : 1;
                __IOM uint16_t PCR   : 1; /*!< [4..4] Input Pull-up Resistor Control                                     */
                uint16_t             : 1;
                __IOM uint16_t PDR   : 1; /*!< [2..2] Port I/O Direction Select                                          */
                __IM uint16_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint16_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
#else
                __IOM uint16_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
                __IM uint16_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint16_t PDR   : 1; /*!< [2..2] Port I/O Direction Select                                          */
                uint16_t             : 1;
                __IOM uint16_t PCR   : 1; /*!< [4..4] Input Pull-up Resistor Control                                     */
                uint16_t             : 1;
                __IOM uint16_t NCODR : 1; /*!< [6..6] N-channel Open-Drain Output Select                                 */
                uint16_t             : 1;
                __IOM uint16_t DSCR  : 4; /*!< [11..8] Driving Ability Select                                            */
                __IOM uint16_t EOFR  : 2; /*!< [13..12] Port Group Input Edge Detection Select                           */
                __IOM uint16_t ISEL  : 1; /*!< [14..14] Interrupt Input Function Select                                  */
                __IOM uint16_t ASEL  : 1; /*!< [15..15] Analog Function Select                                           */
#endif
            } PmnPFS_HA_b;
        };

        union
        {
            __IOM uint8_t PmnPFS_BY;   /*!< (@ 0x00000000) Pin Function Selection Register                            */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint8_t             : 1;
                __IOM uint8_t NCODR : 1; /*!< [6..6] N-channel Open-Drain Output Select                                 */
                uint8_t             : 1;
                __IOM uint8_t PCR   : 1; /*!< [4..4] Input Pull-up Resistor Control                                     */
                uint8_t             : 1;
                __IOM uint8_t PDR   : 1; /*!< [2..2] Port I/O Direction Select                                          */
                __IM uint8_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint8_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
#else
                __IOM uint8_t PODR  : 1; /*!< [0..0] Port Output Data                                                   */
                __IM uint8_t  PIDR  : 1; /*!< [1..1] Port Input Data                                                    */
                __IOM uint8_t PDR   : 1; /*!< [2..2] Port I/O Direction Select                                          */
                uint8_t             : 1;
                __IOM uint8_t PCR   : 1; /*!< [4..4] Input Pull-up Resistor Control                                     */
                uint8_t             : 1;
                __IOM uint8_t NCODR : 1; /*!< [6..6] N-channel Open-Drain Output Select                                 */
                uint8_t             : 1;
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
    union
    {
        __IOM uint16_t PMSAR;          /*!< (@ 0x00000000) Port Security Attribute Setting Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t P015SA : 1; /*!< [15..15] P015 Security Attribute Setting                                  */
            __IOM uint16_t P014SA : 1; /*!< [14..14] P014 Security Attribute Setting                                  */
            __IOM uint16_t P013SA : 1; /*!< [13..13] P013 Security Attribute Setting                                  */
            __IOM uint16_t P012SA : 1; /*!< [12..12] P012 Security Attribute Setting                                  */
            __IOM uint16_t P011SA : 1; /*!< [11..11] P011 Security Attribute Setting                                  */
            __IOM uint16_t P010SA : 1; /*!< [10..10] P010 Security Attribute Setting                                  */
            __IOM uint16_t P009SA : 1; /*!< [9..9] P009 Security Attribute Setting                                    */
            __IOM uint16_t P008SA : 1; /*!< [8..8] P008 Security Attribute Setting                                    */
            __IOM uint16_t P007SA : 1; /*!< [7..7] P007 Security Attribute Setting                                    */
            __IOM uint16_t P006SA : 1; /*!< [6..6] P006 Security Attribute Setting                                    */
            __IOM uint16_t P005SA : 1; /*!< [5..5] P005 Security Attribute Setting                                    */
            __IOM uint16_t P004SA : 1; /*!< [4..4] P004 Security Attribute Setting                                    */
            __IOM uint16_t P003SA : 1; /*!< [3..3] P003 Security Attribute Setting                                    */
            __IOM uint16_t P002SA : 1; /*!< [2..2] P002 Security Attribute Setting                                    */
            __IOM uint16_t P001SA : 1; /*!< [1..1] P001 Security Attribute Setting                                    */
            __IOM uint16_t P000SA : 1; /*!< [0..0] P000 Security Attribute Setting                                    */
#else
            __IOM uint16_t P000SA : 1; /*!< [0..0] P000 Security Attribute Setting                                    */
            __IOM uint16_t P001SA : 1; /*!< [1..1] P001 Security Attribute Setting                                    */
            __IOM uint16_t P002SA : 1; /*!< [2..2] P002 Security Attribute Setting                                    */
            __IOM uint16_t P003SA : 1; /*!< [3..3] P003 Security Attribute Setting                                    */
            __IOM uint16_t P004SA : 1; /*!< [4..4] P004 Security Attribute Setting                                    */
            __IOM uint16_t P005SA : 1; /*!< [5..5] P005 Security Attribute Setting                                    */
            __IOM uint16_t P006SA : 1; /*!< [6..6] P006 Security Attribute Setting                                    */
            __IOM uint16_t P007SA : 1; /*!< [7..7] P007 Security Attribute Setting                                    */
            __IOM uint16_t P008SA : 1; /*!< [8..8] P008 Security Attribute Setting                                    */
            __IOM uint16_t P009SA : 1; /*!< [9..9] P009 Security Attribute Setting                                    */
            __IOM uint16_t P010SA : 1; /*!< [10..10] P010 Security Attribute Setting                                  */
            __IOM uint16_t P011SA : 1; /*!< [11..11] P011 Security Attribute Setting                                  */
            __IOM uint16_t P012SA : 1; /*!< [12..12] P012 Security Attribute Setting                                  */
            __IOM uint16_t P013SA : 1; /*!< [13..13] P013 Security Attribute Setting                                  */
            __IOM uint16_t P014SA : 1; /*!< [14..14] P014 Security Attribute Setting                                  */
            __IOM uint16_t P015SA : 1; /*!< [15..15] P015 Security Attribute Setting                                  */
#endif
        } PMSAR_b;
    };
    __IM uint16_t RESERVED;
} R_PMISC_PMSAR_Type;                  /*!< Size = 4 (0x4)                                                            */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_PORT0                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Port 0 Control (R_PORT0)
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
                __IOM uint32_t PDR  : 16; /*!< [15..0] Pmn I/O Direction Select                                          */
#else
                __IOM uint32_t PDR  : 16; /*!< [15..0] Pmn I/O Direction Select                                          */
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
                    __IOM uint16_t PDR15 : 1; /*!< [15..15] Pm15 I/O Direction Select                                        */
                    __IOM uint16_t PDR14 : 1; /*!< [14..14] Pm14 I/O Direction Select                                        */
                    __IOM uint16_t PDR13 : 1; /*!< [13..13] Pm13 I/O Direction Select                                        */
                    __IOM uint16_t PDR12 : 1; /*!< [12..12] Pm12 I/O Direction Select                                        */
                    __IOM uint16_t PDR11 : 1; /*!< [11..11] Pm11 I/O Direction Select                                        */
                    __IOM uint16_t PDR10 : 1; /*!< [10..10] Pm10 I/O Direction Select                                        */
                    __IOM uint16_t PDR09 : 1; /*!< [9..9] Pm09 I/O Direction Select                                          */
                    __IOM uint16_t PDR08 : 1; /*!< [8..8] Pm08 I/O Direction Select                                          */
                    __IOM uint16_t PDR07 : 1; /*!< [7..7] Pm07 I/O Direction Select                                          */
                    __IOM uint16_t PDR06 : 1; /*!< [6..6] Pm06 I/O Direction Select                                          */
                    __IOM uint16_t PDR05 : 1; /*!< [5..5] Pm05 I/O Direction Select                                          */
                    __IOM uint16_t PDR04 : 1; /*!< [4..4] Pm04 I/O Direction Select                                          */
                    __IOM uint16_t PDR03 : 1; /*!< [3..3] Pm03 I/O Direction Select                                          */
                    __IOM uint16_t PDR02 : 1; /*!< [2..2] Pm02 I/O Direction Select                                          */
                    __IOM uint16_t PDR01 : 1; /*!< [1..1] Pm01 I/O Direction Select                                          */
                    __IOM uint16_t PDR00 : 1; /*!< [0..0] Pm00 I/O Direction Select                                          */
#else
                    __IOM uint16_t PDR00 : 1; /*!< [0..0] Pm00 I/O Direction Select                                          */
                    __IOM uint16_t PDR01 : 1; /*!< [1..1] Pm01 I/O Direction Select                                          */
                    __IOM uint16_t PDR02 : 1; /*!< [2..2] Pm02 I/O Direction Select                                          */
                    __IOM uint16_t PDR03 : 1; /*!< [3..3] Pm03 I/O Direction Select                                          */
                    __IOM uint16_t PDR04 : 1; /*!< [4..4] Pm04 I/O Direction Select                                          */
                    __IOM uint16_t PDR05 : 1; /*!< [5..5] Pm05 I/O Direction Select                                          */
                    __IOM uint16_t PDR06 : 1; /*!< [6..6] Pm06 I/O Direction Select                                          */
                    __IOM uint16_t PDR07 : 1; /*!< [7..7] Pm07 I/O Direction Select                                          */
                    __IOM uint16_t PDR08 : 1; /*!< [8..8] Pm08 I/O Direction Select                                          */
                    __IOM uint16_t PDR09 : 1; /*!< [9..9] Pm09 I/O Direction Select                                          */
                    __IOM uint16_t PDR10 : 1; /*!< [10..10] Pm10 I/O Direction Select                                        */
                    __IOM uint16_t PDR11 : 1; /*!< [11..11] Pm11 I/O Direction Select                                        */
                    __IOM uint16_t PDR12 : 1; /*!< [12..12] Pm12 I/O Direction Select                                        */
                    __IOM uint16_t PDR13 : 1; /*!< [13..13] Pm13 I/O Direction Select                                        */
                    __IOM uint16_t PDR14 : 1; /*!< [14..14] Pm14 I/O Direction Select                                        */
                    __IOM uint16_t PDR15 : 1; /*!< [15..15] Pm15 I/O Direction Select                                        */
#endif
                } PDR_b;
            };

            union
            {
                __IOM uint16_t PODR;   /*!< (@ 0x00000002) Port Output Data Register                                  */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    __IOM uint16_t PODR15 : 1; /*!< [15..15] Pm15 Output Data                                                 */
                    __IOM uint16_t PODR14 : 1; /*!< [14..14] Pm14 Output Data                                                 */
                    __IOM uint16_t PODR13 : 1; /*!< [13..13] Pm13 Output Data                                                 */
                    __IOM uint16_t PODR12 : 1; /*!< [12..12] Pm12 Output Data                                                 */
                    __IOM uint16_t PODR11 : 1; /*!< [11..11] Pm11 Output Data                                                 */
                    __IOM uint16_t PODR10 : 1; /*!< [10..10] Pm10 Output Data                                                 */
                    __IOM uint16_t PODR09 : 1; /*!< [9..9] Pm09 Output Data                                                   */
                    __IOM uint16_t PODR08 : 1; /*!< [8..8] Pm08 Output Data                                                   */
                    __IOM uint16_t PODR07 : 1; /*!< [7..7] Pm07 Output Data                                                   */
                    __IOM uint16_t PODR06 : 1; /*!< [6..6] Pm06 Output Data                                                   */
                    __IOM uint16_t PODR05 : 1; /*!< [5..5] Pm05 Output Data                                                   */
                    __IOM uint16_t PODR04 : 1; /*!< [4..4] Pm04 Output Data                                                   */
                    __IOM uint16_t PODR03 : 1; /*!< [3..3] Pm03 Output Data                                                   */
                    __IOM uint16_t PODR02 : 1; /*!< [2..2] Pm02 Output Data                                                   */
                    __IOM uint16_t PODR01 : 1; /*!< [1..1] Pm01 Output Data                                                   */
                    __IOM uint16_t PODR00 : 1; /*!< [0..0] Pm00 Output Data                                                   */
#else
                    __IOM uint16_t PODR00 : 1; /*!< [0..0] Pm00 Output Data                                                   */
                    __IOM uint16_t PODR01 : 1; /*!< [1..1] Pm01 Output Data                                                   */
                    __IOM uint16_t PODR02 : 1; /*!< [2..2] Pm02 Output Data                                                   */
                    __IOM uint16_t PODR03 : 1; /*!< [3..3] Pm03 Output Data                                                   */
                    __IOM uint16_t PODR04 : 1; /*!< [4..4] Pm04 Output Data                                                   */
                    __IOM uint16_t PODR05 : 1; /*!< [5..5] Pm05 Output Data                                                   */
                    __IOM uint16_t PODR06 : 1; /*!< [6..6] Pm06 Output Data                                                   */
                    __IOM uint16_t PODR07 : 1; /*!< [7..7] Pm07 Output Data                                                   */
                    __IOM uint16_t PODR08 : 1; /*!< [8..8] Pm08 Output Data                                                   */
                    __IOM uint16_t PODR09 : 1; /*!< [9..9] Pm09 Output Data                                                   */
                    __IOM uint16_t PODR10 : 1; /*!< [10..10] Pm10 Output Data                                                 */
                    __IOM uint16_t PODR11 : 1; /*!< [11..11] Pm11 Output Data                                                 */
                    __IOM uint16_t PODR12 : 1; /*!< [12..12] Pm12 Output Data                                                 */
                    __IOM uint16_t PODR13 : 1; /*!< [13..13] Pm13 Output Data                                                 */
                    __IOM uint16_t PODR14 : 1; /*!< [14..14] Pm14 Output Data                                                 */
                    __IOM uint16_t PODR15 : 1; /*!< [15..15] Pm15 Output Data                                                 */
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
                uint32_t           : 8;
                __IM uint32_t EIDR : 8;  /*!< [23..16] Port Event Input Data 07When an ELC_PORTm event has
                                          *   occurred:                                                                 */
                __IM uint32_t PIDR : 16; /*!< [15..0] Pmn Input Data                                                    */
#else
                __IM uint32_t PIDR : 16; /*!< [15..0] Pmn Input Data                                                    */
                __IM uint32_t EIDR : 8;  /*!< [23..16] Port Event Input Data 07When an ELC_PORTm event has
                                          *   occurred:                                                                 */
                uint32_t : 8;
#endif
            } PCNTR2_b;
        };

        struct
        {
            union
            {
                __IM uint16_t PIDR;    /*!< (@ 0x00000004) Port Input Data Register                                   */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    __IM uint16_t PIDR15 : 1; /*!< [15..15] Pm15 Input Data                                                  */
                    __IM uint16_t PIDR14 : 1; /*!< [14..14] Pm14 Input Data                                                  */
                    __IM uint16_t PIDR13 : 1; /*!< [13..13] Pm13 Input Data                                                  */
                    __IM uint16_t PIDR12 : 1; /*!< [12..12] Pm12 Input Data                                                  */
                    __IM uint16_t PIDR11 : 1; /*!< [11..11] Pm11 Input Data                                                  */
                    __IM uint16_t PIDR10 : 1; /*!< [10..10] Pm10 Input Data                                                  */
                    __IM uint16_t PIDR09 : 1; /*!< [9..9] Pm09 Input Data                                                    */
                    __IM uint16_t PIDR08 : 1; /*!< [8..8] Pm08 Input Data                                                    */
                    __IM uint16_t PIDR07 : 1; /*!< [7..7] Pm07 Input Data                                                    */
                    __IM uint16_t PIDR06 : 1; /*!< [6..6] Pm06 Input Data                                                    */
                    __IM uint16_t PIDR05 : 1; /*!< [5..5] Pm05 Input Data                                                    */
                    __IM uint16_t PIDR04 : 1; /*!< [4..4] Pm04 Input Data                                                    */
                    __IM uint16_t PIDR03 : 1; /*!< [3..3] Pm03 Input Data                                                    */
                    __IM uint16_t PIDR02 : 1; /*!< [2..2] Pm02 Input Data                                                    */
                    __IM uint16_t PIDR01 : 1; /*!< [1..1] Pm01 Input Data                                                    */
                    __IM uint16_t PIDR00 : 1; /*!< [0..0] Pm00 Input Data                                                    */
#else
                    __IM uint16_t PIDR00 : 1; /*!< [0..0] Pm00 Input Data                                                    */
                    __IM uint16_t PIDR01 : 1; /*!< [1..1] Pm01 Input Data                                                    */
                    __IM uint16_t PIDR02 : 1; /*!< [2..2] Pm02 Input Data                                                    */
                    __IM uint16_t PIDR03 : 1; /*!< [3..3] Pm03 Input Data                                                    */
                    __IM uint16_t PIDR04 : 1; /*!< [4..4] Pm04 Input Data                                                    */
                    __IM uint16_t PIDR05 : 1; /*!< [5..5] Pm05 Input Data                                                    */
                    __IM uint16_t PIDR06 : 1; /*!< [6..6] Pm06 Input Data                                                    */
                    __IM uint16_t PIDR07 : 1; /*!< [7..7] Pm07 Input Data                                                    */
                    __IM uint16_t PIDR08 : 1; /*!< [8..8] Pm08 Input Data                                                    */
                    __IM uint16_t PIDR09 : 1; /*!< [9..9] Pm09 Input Data                                                    */
                    __IM uint16_t PIDR10 : 1; /*!< [10..10] Pm10 Input Data                                                  */
                    __IM uint16_t PIDR11 : 1; /*!< [11..11] Pm11 Input Data                                                  */
                    __IM uint16_t PIDR12 : 1; /*!< [12..12] Pm12 Input Data                                                  */
                    __IM uint16_t PIDR13 : 1; /*!< [13..13] Pm13 Input Data                                                  */
                    __IM uint16_t PIDR14 : 1; /*!< [14..14] Pm14 Input Data                                                  */
                    __IM uint16_t PIDR15 : 1; /*!< [15..15] Pm15 Input Data                                                  */
#endif
                } PIDR_b;
            };

            union
            {
                __IM uint16_t EIDR;    /*!< (@ 0x00000006) Port Event Input Data Register                             */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    uint16_t             : 8;
                    __IM uint16_t EIDR07 : 1; /*!< [7..7] Port Event Input Data 07When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR06 : 1; /*!< [6..6] Port Event Input Data 06When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR05 : 1; /*!< [5..5] Port Event Input Data 05When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR04 : 1; /*!< [4..4] Port Event Input Data 04When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR03 : 1; /*!< [3..3] Port Event Input Data 03When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR02 : 1; /*!< [2..2] Port Event Input Data 02When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR01 : 1; /*!< [1..1] Port Event Input Data 01When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR00 : 1; /*!< [0..0] Port Event Input Data 00When an ELC_PORTm event has occurred:      */
#else
                    __IM uint16_t EIDR00 : 1; /*!< [0..0] Port Event Input Data 00When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR01 : 1; /*!< [1..1] Port Event Input Data 01When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR02 : 1; /*!< [2..2] Port Event Input Data 02When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR03 : 1; /*!< [3..3] Port Event Input Data 03When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR04 : 1; /*!< [4..4] Port Event Input Data 04When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR05 : 1; /*!< [5..5] Port Event Input Data 05When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR06 : 1; /*!< [6..6] Port Event Input Data 06When an ELC_PORTm event has occurred:      */
                    __IM uint16_t EIDR07 : 1; /*!< [7..7] Port Event Input Data 07When an ELC_PORTm event has occurred:      */
                    uint16_t             : 8;
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
                __OM uint16_t POSR;    /*!< (@ 0x00000008) Port Output Set Register                                   */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    __OM uint16_t POSR15 : 1; /*!< [15..15] Pm15 Output Set                                                  */
                    __OM uint16_t POSR14 : 1; /*!< [14..14] Pm14 Output Set                                                  */
                    __OM uint16_t POSR13 : 1; /*!< [13..13] Pm13 Output Set                                                  */
                    __OM uint16_t POSR12 : 1; /*!< [12..12] Pm12 Output Set                                                  */
                    __OM uint16_t POSR11 : 1; /*!< [11..11] Pm11 Output Set                                                  */
                    __OM uint16_t POSR10 : 1; /*!< [10..10] Pm10 Output Set                                                  */
                    __OM uint16_t POSR09 : 1; /*!< [9..9] Pm09 Output Set                                                    */
                    __OM uint16_t POSR08 : 1; /*!< [8..8] Pm08 Output Set                                                    */
                    __OM uint16_t POSR07 : 1; /*!< [7..7] Pm07 Output Set                                                    */
                    __OM uint16_t POSR06 : 1; /*!< [6..6] Pm06 Output Set                                                    */
                    __OM uint16_t POSR05 : 1; /*!< [5..5] Pm05 Output Set                                                    */
                    __OM uint16_t POSR04 : 1; /*!< [4..4] Pm04 Output Set                                                    */
                    __OM uint16_t POSR03 : 1; /*!< [3..3] Pm03 Output Set                                                    */
                    __OM uint16_t POSR02 : 1; /*!< [2..2] Pm02 Output Set                                                    */
                    __OM uint16_t POSR01 : 1; /*!< [1..1] Pm01 Output Set                                                    */
                    __OM uint16_t POSR00 : 1; /*!< [0..0] Pm00 Output Set                                                    */
#else
                    __OM uint16_t POSR00 : 1; /*!< [0..0] Pm00 Output Set                                                    */
                    __OM uint16_t POSR01 : 1; /*!< [1..1] Pm01 Output Set                                                    */
                    __OM uint16_t POSR02 : 1; /*!< [2..2] Pm02 Output Set                                                    */
                    __OM uint16_t POSR03 : 1; /*!< [3..3] Pm03 Output Set                                                    */
                    __OM uint16_t POSR04 : 1; /*!< [4..4] Pm04 Output Set                                                    */
                    __OM uint16_t POSR05 : 1; /*!< [5..5] Pm05 Output Set                                                    */
                    __OM uint16_t POSR06 : 1; /*!< [6..6] Pm06 Output Set                                                    */
                    __OM uint16_t POSR07 : 1; /*!< [7..7] Pm07 Output Set                                                    */
                    __OM uint16_t POSR08 : 1; /*!< [8..8] Pm08 Output Set                                                    */
                    __OM uint16_t POSR09 : 1; /*!< [9..9] Pm09 Output Set                                                    */
                    __OM uint16_t POSR10 : 1; /*!< [10..10] Pm10 Output Set                                                  */
                    __OM uint16_t POSR11 : 1; /*!< [11..11] Pm11 Output Set                                                  */
                    __OM uint16_t POSR12 : 1; /*!< [12..12] Pm12 Output Set                                                  */
                    __OM uint16_t POSR13 : 1; /*!< [13..13] Pm13 Output Set                                                  */
                    __OM uint16_t POSR14 : 1; /*!< [14..14] Pm14 Output Set                                                  */
                    __OM uint16_t POSR15 : 1; /*!< [15..15] Pm15 Output Set                                                  */
#endif
                } POSR_b;
            };

            union
            {
                __OM uint16_t PORR;    /*!< (@ 0x0000000A) Port Output Reset Register                                 */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    __OM uint16_t PORR15 : 1; /*!< [15..15] Pm15 Output Reset                                                */
                    __OM uint16_t PORR14 : 1; /*!< [14..14] Pm14 Output Reset                                                */
                    __OM uint16_t PORR13 : 1; /*!< [13..13] Pm13 Output Reset                                                */
                    __OM uint16_t PORR12 : 1; /*!< [12..12] Pm12 Output Reset                                                */
                    __OM uint16_t PORR11 : 1; /*!< [11..11] Pm11 Output Reset                                                */
                    __OM uint16_t PORR10 : 1; /*!< [10..10] Pm10 Output Reset                                                */
                    __OM uint16_t PORR09 : 1; /*!< [9..9] Pm09 Output Reset                                                  */
                    __OM uint16_t PORR08 : 1; /*!< [8..8] Pm08 Output Reset                                                  */
                    __OM uint16_t PORR07 : 1; /*!< [7..7] Pm07 Output Reset                                                  */
                    __OM uint16_t PORR06 : 1; /*!< [6..6] Pm06 Output Reset                                                  */
                    __OM uint16_t PORR05 : 1; /*!< [5..5] Pm05 Output Reset                                                  */
                    __OM uint16_t PORR04 : 1; /*!< [4..4] Pm04 Output Reset                                                  */
                    __OM uint16_t PORR03 : 1; /*!< [3..3] Pm03 Output Reset                                                  */
                    __OM uint16_t PORR02 : 1; /*!< [2..2] Pm02 Output Reset                                                  */
                    __OM uint16_t PORR01 : 1; /*!< [1..1] Pm01 Output Reset                                                  */
                    __OM uint16_t PORR00 : 1; /*!< [0..0] Pm00 Output Reset                                                  */
#else
                    __OM uint16_t PORR00 : 1; /*!< [0..0] Pm00 Output Reset                                                  */
                    __OM uint16_t PORR01 : 1; /*!< [1..1] Pm01 Output Reset                                                  */
                    __OM uint16_t PORR02 : 1; /*!< [2..2] Pm02 Output Reset                                                  */
                    __OM uint16_t PORR03 : 1; /*!< [3..3] Pm03 Output Reset                                                  */
                    __OM uint16_t PORR04 : 1; /*!< [4..4] Pm04 Output Reset                                                  */
                    __OM uint16_t PORR05 : 1; /*!< [5..5] Pm05 Output Reset                                                  */
                    __OM uint16_t PORR06 : 1; /*!< [6..6] Pm06 Output Reset                                                  */
                    __OM uint16_t PORR07 : 1; /*!< [7..7] Pm07 Output Reset                                                  */
                    __OM uint16_t PORR08 : 1; /*!< [8..8] Pm08 Output Reset                                                  */
                    __OM uint16_t PORR09 : 1; /*!< [9..9] Pm09 Output Reset                                                  */
                    __OM uint16_t PORR10 : 1; /*!< [10..10] Pm10 Output Reset                                                */
                    __OM uint16_t PORR11 : 1; /*!< [11..11] Pm11 Output Reset                                                */
                    __OM uint16_t PORR12 : 1; /*!< [12..12] Pm12 Output Reset                                                */
                    __OM uint16_t PORR13 : 1; /*!< [13..13] Pm13 Output Reset                                                */
                    __OM uint16_t PORR14 : 1; /*!< [14..14] Pm14 Output Reset                                                */
                    __OM uint16_t PORR15 : 1; /*!< [15..15] Pm15 Output Reset                                                */
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
                uint32_t            : 8;
                __IOM uint32_t EORR : 8; /*!< [23..16] Pmn Event Output ResetWhen an ELC_PORTm event has occurred:      */
                uint32_t            : 8;
                __IOM uint32_t EOSR : 8; /*!< [7..0] Pmn Event Output SetWhen an ELC_PORTm event has occurred:          */
#else
                __IOM uint32_t EOSR : 8; /*!< [7..0] Pmn Event Output SetWhen an ELC_PORTm event has occurred:          */
                uint32_t            : 8;
                __IOM uint32_t EORR : 8; /*!< [23..16] Pmn Event Output ResetWhen an ELC_PORTm event has occurred:      */
                uint32_t            : 8;
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
                    uint16_t              : 8;
                    __IOM uint16_t EOSR07 : 1; /*!< [7..7] Pm07 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR06 : 1; /*!< [6..6] Pm06 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR05 : 1; /*!< [5..5] Pm05 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR04 : 1; /*!< [4..4] Pm04 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR03 : 1; /*!< [3..3] Pm03 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR02 : 1; /*!< [2..2] Pm02 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR01 : 1; /*!< [1..1] Pm01 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR00 : 1; /*!< [0..0] Pm00 Event Output SetWhen an ELC_PORTm event has occurred:         */
#else
                    __IOM uint16_t EOSR00 : 1; /*!< [0..0] Pm00 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR01 : 1; /*!< [1..1] Pm01 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR02 : 1; /*!< [2..2] Pm02 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR03 : 1; /*!< [3..3] Pm03 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR04 : 1; /*!< [4..4] Pm04 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR05 : 1; /*!< [5..5] Pm05 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR06 : 1; /*!< [6..6] Pm06 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    __IOM uint16_t EOSR07 : 1; /*!< [7..7] Pm07 Event Output SetWhen an ELC_PORTm event has occurred:         */
                    uint16_t              : 8;
#endif
                } EOSR_b;
            };

            union
            {
                __IOM uint16_t EORR;   /*!< (@ 0x0000000E) Event output set register                                  */

                struct
                {
#if defined(__BIG) && defined(__GNUC__)
                    uint16_t              : 8;
                    __IOM uint16_t EORR07 : 1; /*!< [7..7] Pm07 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR06 : 1; /*!< [6..6] Pm06 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR05 : 1; /*!< [5..5] Pm05 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR04 : 1; /*!< [4..4] Pm04 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR03 : 1; /*!< [3..3] Pm03 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR02 : 1; /*!< [2..2] Pm02 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR01 : 1; /*!< [1..1] Pm01 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR00 : 1; /*!< [0..0] Pm00 Event Output ResetWhen an ELC_PORTm event has occurred:       */
#else
                    __IOM uint16_t EORR00 : 1; /*!< [0..0] Pm00 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR01 : 1; /*!< [1..1] Pm01 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR02 : 1; /*!< [2..2] Pm02 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR03 : 1; /*!< [3..3] Pm03 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR04 : 1; /*!< [4..4] Pm04 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR05 : 1; /*!< [5..5] Pm05 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR06 : 1; /*!< [6..6] Pm06 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    __IOM uint16_t EORR07 : 1; /*!< [7..7] Pm07 Event Output ResetWhen an ELC_PORTm event has occurred:       */
                    uint16_t              : 8;
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
 * @brief Pmn Pin Function Control (R_PFS)
 */

typedef struct                         /*!< (@ 0x87C00800) R_PFS Structure                                            */
{
    __IOM R_PFS_PORT_Type PORT[17];    /*!< (@ 0x00000000) Port [0..16]                                               */
} R_PFS_Type;                          /*!< Size = 1088 (0x440)                                                       */

/* =========================================================================================================================== */
/* ================                                          R_PMISC                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Pmn Pin Function Control (R_PMISC)
 */

typedef struct                         /*!< (@ 0x87C00D00) R_PMISC Structure                                          */
{
    __IM uint16_t RESERVED[6];

    union
    {
        __IOM uint8_t PWPR_NS;         /*!< (@ 0x0000000C) Non-secure World Write Protection Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t B0WI  : 1;   /*!< [7..7] PFSWE Bit Write Disable                                            */
            __IOM uint8_t PFSWE : 1;   /*!< [6..6] PmnPFS Register Write Enable                                       */
            uint8_t             : 6;
#else
            uint8_t             : 6;
            __IOM uint8_t PFSWE : 1;   /*!< [6..6] PmnPFS Register Write Enable                                       */
            __IOM uint8_t B0WI  : 1;   /*!< [7..7] PFSWE Bit Write Disable                                            */
#endif
        } PWPR_NS_b;
    };
    __IM uint8_t  RESERVED1;
    __IM uint16_t RESERVED2[3];

    union
    {
        __IOM uint8_t PWPR_S;          /*!< (@ 0x00000014) Secure World Write Protection Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t B0WI  : 1;   /*!< [7..7] PFSWE Bit Write Disable                                            */
            __IOM uint8_t PFSWE : 1;   /*!< [6..6] PmnPFS Register Write Enable                                       */
            uint8_t             : 6;
#else
            uint8_t             : 6;
            __IOM uint8_t PFSWE : 1;   /*!< [6..6] PmnPFS Register Write Enable                                       */
            __IOM uint8_t B0WI  : 1;   /*!< [7..7] PFSWE Bit Write Disable                                            */
#endif
        } PWPR_S_b;
    };
    __IM uint8_t             RESERVED3;
    __IM uint16_t            RESERVED4[13];
    __IOM R_PMISC_PMSAR_Type PMSAR[17]; /*!< (@ 0x00000030) Port Security Attribution Register                         */
} R_PMISC_Type;                         /*!< Size = 116 (0x74)                                                         */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_PORT_REG_H */
