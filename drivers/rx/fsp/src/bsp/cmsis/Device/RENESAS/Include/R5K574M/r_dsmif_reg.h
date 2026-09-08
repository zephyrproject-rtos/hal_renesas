/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DSMIF_REG_H
#define R_DSMIF_REG_H

/**
 * @brief R_DSMIF0_CH_TR [TR] (Overcurrent Threshold Registers)
 */

typedef struct
{
    union
    {
        __IOM uint32_t DSOCL;          /*!< (@ 0x00000000) Overcurrent Low Threshold Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 16;
            __IOM uint32_t OCMPTBL : 16; /*!< [15..0] Overcurrent detection lower limit                                 */
#else
            __IOM uint32_t OCMPTBL : 16; /*!< [15..0] Overcurrent detection lower limit                                 */
            uint32_t               : 16;
#endif
        } DSOCL_b;
    };

    union
    {
        __IOM uint32_t DSOCH;          /*!< (@ 0x00000004) Overcurrent High Threshold Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 16;
            __IOM uint32_t OCMPTBH : 16; /*!< [15..0] Overcurrent detection upper limit                                 */
#else
            __IOM uint32_t OCMPTBH : 16; /*!< [15..0] Overcurrent detection upper limit                                 */
            uint32_t               : 16;
#endif
        } DSOCH_b;
    };
} R_DSMIF0_CH_TR_Type;                 /*!< Size = 8 (0x8)                                                         */

/**
 * @brief R_DSMIF0_CH [CH] (DSMIF Channel Control Registers)
 */

typedef struct
{
    union
    {
        __IOM uint32_t DSICR;          /*!< (@ 0x00000000) Interrupt Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 12;
            __IOM uint32_t OWNE3 : 1;  /*!< [19..19] Overcurrent detection window notification 3 output
                                        *   enable                                                                    */
            __IOM uint32_t OWNE2 : 1;  /*!< [18..18] Overcurrent detection window notification 2 output
                                        *   enable                                                                    */
            __IOM uint32_t OWNE1 : 1;  /*!< [17..17] Overcurrent detection window notification 1 output
                                        *   enable                                                                    */
            __IOM uint32_t OWNE0 : 1;  /*!< [16..16] Overcurrent detection window notification 0 output
                                        *   enable                                                                    */
            uint32_t             : 2;
            __IOM uint32_t IOEH2 : 1;  /*!< [13..13] Overcurrent upper limit exceeded detection interrupt
                                        *   2                                                                         */
            __IOM uint32_t IOEL2 : 1;  /*!< [12..12] Overcurrent lower limit detection interrupt 2                    */
            __IOM uint32_t IOEH1 : 1;  /*!< [11..11] Overcurrent upper limit exceeded detection interrupt
                                        *   1                                                                         */
            __IOM uint32_t IOEL1 : 1;  /*!< [10..10] Overcurrent lower limit detection interrupt 1                    */
            __IOM uint32_t IOEH0 : 1;  /*!< [9..9] Overcurrent upper limit exceeded detection interrupt
                                        *   0                                                                         */
            __IOM uint32_t IOEL0 : 1;  /*!< [8..8] Overcurrent lower limit detection interrupt 0                      */
            uint32_t             : 4;
            __IOM uint32_t ISE   : 1;  /*!< [3..3] Short circuit detection error interrupt enable bit                 */
            __IOM uint32_t IBUE  : 1;  /*!< [2..2] Capture current data register B update interrupt enable            */
            __IOM uint32_t IAUE  : 1;  /*!< [1..1] Capture current data register A update interrupt enable            */
            __IOM uint32_t IUE   : 1;  /*!< [0..0] Current data register update interrupt enable                      */
#else
            __IOM uint32_t IUE   : 1;  /*!< [0..0] Current data register update interrupt enable                      */
            __IOM uint32_t IAUE  : 1;  /*!< [1..1] Capture current data register A update interrupt enable            */
            __IOM uint32_t IBUE  : 1;  /*!< [2..2] Capture current data register B update interrupt enable            */
            __IOM uint32_t ISE   : 1;  /*!< [3..3] Short circuit detection error interrupt enable bit                 */
            uint32_t             : 4;
            __IOM uint32_t IOEL0 : 1;  /*!< [8..8] Overcurrent lower limit detection interrupt 0                      */
            __IOM uint32_t IOEH0 : 1;  /*!< [9..9] Overcurrent upper limit exceeded detection interrupt
                                        *   0                                                                         */
            __IOM uint32_t IOEL1 : 1;  /*!< [10..10] Overcurrent lower limit detection interrupt 1                    */
            __IOM uint32_t IOEH1 : 1;  /*!< [11..11] Overcurrent upper limit exceeded detection interrupt
                                        *   1                                                                         */
            __IOM uint32_t IOEL2 : 1;  /*!< [12..12] Overcurrent lower limit detection interrupt 2                    */
            __IOM uint32_t IOEH2 : 1;  /*!< [13..13] Overcurrent upper limit exceeded detection interrupt
                                        *   2                                                                         */
            uint32_t             : 2;
            __IOM uint32_t OWNE0 : 1;  /*!< [16..16] Overcurrent detection window notification 0 output
                                        *   enable                                                                    */
            __IOM uint32_t OWNE1 : 1;  /*!< [17..17] Overcurrent detection window notification 1 output
                                        *   enable                                                                    */
            __IOM uint32_t OWNE2 : 1;  /*!< [18..18] Overcurrent detection window notification 2 output
                                        *   enable                                                                    */
            __IOM uint32_t OWNE3 : 1;  /*!< [19..19] Overcurrent detection window notification 3 output
                                        *   enable                                                                    */
            uint32_t : 12;
#endif
        } DSICR_b;
    };

    union
    {
        __IOM uint32_t DSCMCCR;        /*!< (@ 0x00000004) Current Measurement Clock Control Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 18;
            __IOM uint32_t CKDIV : 6;  /*!< [13..8] A/D conversion clock division ratio                               */
            __IOM uint32_t SEDGE : 1;  /*!< [7..7] Sampling edge selection                                            */
            uint32_t             : 6;
            __IOM uint32_t CKDIR : 1;  /*!< [0..0] A/D conversion clock master/slave switching                        */
#else
            __IOM uint32_t CKDIR : 1;  /*!< [0..0] A/D conversion clock master/slave switching                        */
            uint32_t             : 6;
            __IOM uint32_t SEDGE : 1;  /*!< [7..7] Sampling edge selection                                            */
            __IOM uint32_t CKDIV : 6;  /*!< [13..8] A/D conversion clock division ratio                               */
            uint32_t             : 18;
#endif
        } DSCMCCR_b;
    };

    union
    {
        __IOM uint32_t DSCMFCR;        /*!< (@ 0x00000008) Current Measurement Filter Control Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IOM uint32_t CMSH   : 5; /*!< [20..16] Data shift setting for current measurement                       */
            __IOM uint32_t CMDEC  : 8; /*!< [15..8] Decimation ratio selection for current measurement                */
            uint32_t              : 6;
            __IOM uint32_t CMSINC : 2; /*!< [1..0] Current measurement filter order setting                           */
#else
            __IOM uint32_t CMSINC : 2; /*!< [1..0] Current measurement filter order setting                           */
            uint32_t              : 6;
            __IOM uint32_t CMDEC  : 8; /*!< [15..8] Decimation ratio selection for current measurement                */
            __IOM uint32_t CMSH   : 5; /*!< [20..16] Data shift setting for current measurement                       */
            uint32_t              : 11;
#endif
        } DSCMFCR_b;
    };

    union
    {
        __IOM uint32_t DSCMCTCR;       /*!< (@ 0x0000000C) Current Measurement Capture Trigger Control Register       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 8;
            __IOM uint32_t DEDGE : 1;  /*!< [23..23] Current measurement filter initialization trigger for
                                        *   division counter for decimation edge selection bit. The
                                        *   trigger from ELC is usually used positive edge. Change
                                        *   from the initial value if necessary.                                      */
            uint32_t              : 5;
            __IOM uint32_t DITSEL : 2; /*!< [17..16] Current measurement filter initialization trigger selection
                                        *   bit for frequency division counter for decimation                         */
            uint32_t              : 5;
            __IOM uint32_t CTSELB : 3; /*!< [10..8] Current capture trigger B selection bit                           */
            uint32_t              : 5;
            __IOM uint32_t CTSELA : 3; /*!< [2..0] Current capture trigger A selection bit                            */
#else
            __IOM uint32_t CTSELA : 3; /*!< [2..0] Current capture trigger A selection bit                            */
            uint32_t              : 5;
            __IOM uint32_t CTSELB : 3; /*!< [10..8] Current capture trigger B selection bit                           */
            uint32_t              : 5;
            __IOM uint32_t DITSEL : 2; /*!< [17..16] Current measurement filter initialization trigger selection
                                        *   bit for frequency division counter for decimation                         */
            uint32_t             : 5;
            __IOM uint32_t DEDGE : 1;  /*!< [23..23] Current measurement filter initialization trigger for
                                        *   division counter for decimation edge selection bit. The
                                        *   trigger from ELC is usually used positive edge. Change
                                        *   from the initial value if necessary.                                      */
            uint32_t : 8;
#endif
        } DSCMCTCR_b;
    };
    __IM uint32_t RESERVED[4];

    union
    {
        __IOM uint32_t DSEDCR;         /*!< (@ 0x00000020) Error Detect Control Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __IOM uint32_t SDE : 1;    /*!< [0..0] Short circuit detection enable bit                                 */
#else
            __IOM uint32_t SDE : 1;    /*!< [0..0] Short circuit detection enable bit                                 */
            uint32_t           : 31;
#endif
        } DSEDCR_b;
    };

    union
    {
        __IOM uint32_t DSSCTSR;        /*!< (@ 0x00000024) Short Circuit Threshold Setting Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 3;
            __IOM uint32_t SCNTH : 13; /*!< [28..16] Short circuit detection high continuous detection count          */
            uint32_t             : 3;
            __IOM uint32_t SCNTL : 13; /*!< [12..0] Short circuit detection low continuous detection count            */
#else
            __IOM uint32_t SCNTL : 13; /*!< [12..0] Short circuit detection low continuous detection count            */
            uint32_t             : 3;
            __IOM uint32_t SCNTH : 13; /*!< [28..16] Short circuit detection high continuous detection count          */
            uint32_t             : 3;
#endif
        } DSSCTSR_b;
    };
    __IM uint32_t RESERVED1[2];

    union
    {
        __IOM uint32_t DSOCFCR;        /*!< (@ 0x00000030) Overcurrent Detect Filter Control Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IOM uint32_t OCSH   : 5; /*!< [20..16] Data shift setting for overcurrent detection                     */
            __IOM uint32_t OCDEC  : 8; /*!< [15..8] Decimation ratio selection for overcurrent detection              */
            uint32_t              : 6;
            __IOM uint32_t OCSINC : 2; /*!< [1..0] Overcurrent detection filter order setting                         */
#else
            __IOM uint32_t OCSINC : 2; /*!< [1..0] Overcurrent detection filter order setting                         */
            uint32_t              : 6;
            __IOM uint32_t OCDEC  : 8; /*!< [15..8] Decimation ratio selection for overcurrent detection              */
            __IOM uint32_t OCSH   : 5; /*!< [20..16] Data shift setting for overcurrent detection                     */
            uint32_t              : 11;
#endif
        } DSOCFCR_b;
    };
    union
    {
        __IOM uint32_t DSODCR;         /*!< (@ 0x00000034) Overcurrent Detect Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 13;
            __IOM uint32_t OWFEN2 : 1; /*!< [18..18] Overcurrent Detection Window Notification 2 Suppression
                                        *   Filter Enable                                                             */
            __IOM uint32_t OWFEN1 : 1; /*!< [17..17] Overcurrent Detection Window Notification 1Suppression
                                        *   Filter Enable                                                             */
            __IOM uint32_t OWFEN0 : 1; /*!< [16..16] Overcurrent Detection Window Notification 0Suppression
                                        *   Filter Enable                                                             */
            uint32_t             : 4;
            __IOM uint32_t OWFE3 : 1;  /*!< [11..11] Overcurrent lower limit detection interrupt 3                    */
            __IOM uint32_t OWFE2 : 1;  /*!< [10..10] Overcurrent lower limit detection interrupt 2                    */
            __IOM uint32_t OWFE1 : 1;  /*!< [9..9] Overcurrent lower limit detection interrupt 1                      */
            __IOM uint32_t OWFE0 : 1;  /*!< [8..8] Overcurrent lower limit detection interrupt 0                      */
            uint32_t             : 2;
            __IOM uint32_t ODEH2 : 1;  /*!< [5..5] Overcurrent upper limit exceeded detection 2 enable                */
            __IOM uint32_t ODEL2 : 1;  /*!< [4..4] Overcurrent lower limit detection 2 enable                         */
            __IOM uint32_t ODEH1 : 1;  /*!< [3..3] Overcurrent upper limit exceeded detection 1 enable                */
            __IOM uint32_t ODEL1 : 1;  /*!< [2..2] Overcurrent lower limit detection 1 enable                         */
            __IOM uint32_t ODEH0 : 1;  /*!< [1..1] Overcurrent upper limit exceeded detection 0 enable                */
            __IOM uint32_t ODEL0 : 1;  /*!< [0..0] Overcurrent lower limit detection 0 enable                         */
#else
            __IOM uint32_t ODEL0  : 1; /*!< [0..0] Overcurrent lower limit detection 0 enable                         */
            __IOM uint32_t ODEH0  : 1; /*!< [1..1] Overcurrent upper limit exceeded detection 0 enable                */
            __IOM uint32_t ODEL1  : 1; /*!< [2..2] Overcurrent lower limit detection 1 enable                         */
            __IOM uint32_t ODEH1  : 1; /*!< [3..3] Overcurrent upper limit exceeded detection 1 enable                */
            __IOM uint32_t ODEL2  : 1; /*!< [4..4] Overcurrent lower limit detection 2 enable                         */
            __IOM uint32_t ODEH2  : 1; /*!< [5..5] Overcurrent upper limit exceeded detection 2 enable                */
            uint32_t              : 2;
            __IOM uint32_t OWFE0  : 1; /*!< [8..8] Overcurrent lower limit detection interrupt 0                      */
            __IOM uint32_t OWFE1  : 1; /*!< [9..9] Overcurrent lower limit detection interrupt 1                      */
            __IOM uint32_t OWFE2  : 1; /*!< [10..10] Overcurrent lower limit detection interrupt 2                    */
            __IOM uint32_t OWFE3  : 1; /*!< [11..11] Overcurrent lower limit detection interrupt 3                    */
            uint32_t              : 4;
            __IOM uint32_t OWFEN0 : 1; /*!< [16..16] Overcurrent Detection Window Notification 0Suppression
                                        *   Filter Enable                                                             */
            __IOM uint32_t OWFEN1 : 1; /*!< [17..17] Overcurrent Detection Window Notification 1Suppression
                                        *   Filter Enable                                                             */
            __IOM uint32_t OWFEN2 : 1; /*!< [18..18] Overcurrent Detection Window Notification 2 Suppression
                                        *   Filter Enable                                                             */
            uint32_t : 13;
#endif
        } DSODCR_b;
    };

    union
    {
        __IOM uint32_t DSODWCR;        /*!< (@ 0x00000038) Overcurrent Detect Window Control Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 17;
            __IOM uint32_t OWNHCD2 : 1; /*!< [14..14] Channel n Overcurrent Detection Window Notification
                                         *   2 Hard Clear Disable                                                      */
            __IOM uint32_t OWNHCD1 : 1; /*!< [13..13] Channel n Overcurrent Detection Window Notification
                                         *   2 Hard Clear Disable                                                      */
            __IOM uint32_t OWNHCD0 : 1; /*!< [12..12] Channel n Overcurrent Detection Window Notification
                                         *   1 Hard Clear Disable                                                      */
            uint32_t              : 1;
            __IOM uint32_t OWNM21 : 1;  /*!< [10..10] Channel n Overcurrent Detection Window Notification
                                         *   2H Mode Select                                                            */
            __IOM uint32_t OWNM11 : 1;  /*!< [9..9] Channel n Overcurrent Detection Window Notification 1H
                                         *   Mode Select                                                               */
            __IOM uint32_t OWNM01 : 1;  /*!< [8..8] Channel n Overcurrent Detection Window Notification 0H
                                         *   Mode Select                                                               */
            uint32_t             : 1;
            __IOM uint32_t OWNM3 : 4;   /*!< [6..3] Channel n overcurrent detection window notification 3
                                         *   mode select                                                               */
            __IOM uint32_t OWNM20 : 1;  /*!< [2..2] Channel n overcurrent detection window notification 2
                                         *   mode select                                                               */
            __IOM uint32_t OWNM10 : 1;  /*!< [1..1] Channel n overcurrent detection window notification 1
                                         *   mode select                                                               */
            __IOM uint32_t OWNM00 : 1;  /*!< [0..0] Channel n overcurrent detection window notification 0
                                         *   mode select                                                               */
#else
            __IOM uint32_t OWNM00 : 1;  /*!< [0..0] Channel n overcurrent detection window notification 0
                                         *   mode select                                                               */
            __IOM uint32_t OWNM10 : 1;  /*!< [1..1] Channel n overcurrent detection window notification 1
                                         *   mode select                                                               */
            __IOM uint32_t OWNM20 : 1;  /*!< [2..2] Channel n overcurrent detection window notification 2
                                         *   mode select                                                               */
            __IOM uint32_t OWNM3 : 4;   /*!< [6..3] Channel n overcurrent detection window notification 3
                                         *   mode select                                                               */
            uint32_t              : 1;
            __IOM uint32_t OWNM01 : 1;  /*!< [8..8] Channel n Overcurrent Detection Window Notification 0H
                                         *   Mode Select                                                               */
            __IOM uint32_t OWNM11 : 1;  /*!< [9..9] Channel n Overcurrent Detection Window Notification 1H
                                         *   Mode Select                                                               */
            __IOM uint32_t OWNM21 : 1;  /*!< [10..10] Channel n Overcurrent Detection Window Notification
                                         *   2H Mode Select                                                            */
            uint32_t               : 1;
            __IOM uint32_t OWNHCD0 : 1; /*!< [12..12] Channel n Overcurrent Detection Window Notification
                                         *   1 Hard Clear Disable                                                      */
            __IOM uint32_t OWNHCD1 : 1; /*!< [13..13] Channel n Overcurrent Detection Window Notification
                                         *   2 Hard Clear Disable                                                      */
            __IOM uint32_t OWNHCD2 : 1; /*!< [14..14] Channel n Overcurrent Detection Window Notification
                                         *   2 Hard Clear Disable                                                      */
            uint32_t : 17;
#endif
        } DSODWCR_b;
    };

    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t DSODWN0FCR;     /*!< (@ 0x00000040) Overcurrent Detect Window Notification 0 Suppression
                                        *                  Filter Control Register Channel 0                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t OWFINT0 : 1; /*!< [31..31] Channel n Overcurrent Detection Window Notification
                                         *   0 Suppression Filter Initialization                                       */
            uint32_t             : 10;
            __IOM uint32_t OWDR0 : 5;   /*!< [20..16] Channel n Overcurrent Detection Window Notification
                                         *   0 Division Ratio setting                                                  */
            uint32_t             : 3;
            __IOM uint32_t OWTH0 : 5;   /*!< [12..8] Channel n Overcurrent Detection Window Notification
                                         *   0 Threshold setting                                                       */
            uint32_t             : 3;
            __IOM uint32_t OWSN0 : 5;   /*!< [4..0] Channel n Overcurrent Detection Window Notification 0
                                         *   Shift register stages Number setting                                      */
#else
            __IOM uint32_t OWSN0 : 5;   /*!< [4..0] Channel n Overcurrent Detection Window Notification 0
                                         *   Shift register stages Number setting                                      */
            uint32_t             : 3;
            __IOM uint32_t OWTH0 : 5;   /*!< [12..8] Channel n Overcurrent Detection Window Notification
                                         *   0 Threshold setting                                                       */
            uint32_t             : 3;
            __IOM uint32_t OWDR0 : 5;   /*!< [20..16] Channel n Overcurrent Detection Window Notification
                                         *   0 Division Ratio setting                                                  */
            uint32_t               : 10;
            __IOM uint32_t OWFINT0 : 1; /*!< [31..31] Channel n Overcurrent Detection Window Notification
                                         *   0 Suppression Filter Initialization                                       */
#endif
        } DSODWN0FCR_b;
    };

    union
    {
        __IOM uint32_t DSODWN1FCR;     /*!< (@ 0x00000044) Overcurrent Detect Window Notification 1 Suppression
                                        *                  Filter Control Register Channel 0                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t OWFINT1 : 1; /*!< [31..31] Channel n Overcurrent Detection Window Notification
                                         *   1Suppression Filter Initialization                                        */
            uint32_t             : 10;
            __IOM uint32_t OWDR1 : 5;   /*!< [20..16] Channel n Overcurrent Detection Window Notification
                                         *   1 Division Ratio setting                                                  */
            uint32_t             : 3;
            __IOM uint32_t OWTH1 : 5;   /*!< [12..8] Channel n Overcurrent Detection Window Notification
                                         *   1 Threshold setting                                                       */
            uint32_t             : 3;
            __IOM uint32_t OWSN1 : 5;   /*!< [4..0] Channel n Overcurrent Detection Window Notification 1
                                         *   Shift register stages Number setting                                      */
#else
            __IOM uint32_t OWSN1 : 5;   /*!< [4..0] Channel n Overcurrent Detection Window Notification 1
                                         *   Shift register stages Number setting                                      */
            uint32_t             : 3;
            __IOM uint32_t OWTH1 : 5;   /*!< [12..8] Channel n Overcurrent Detection Window Notification
                                         *   1 Threshold setting                                                       */
            uint32_t             : 3;
            __IOM uint32_t OWDR1 : 5;   /*!< [20..16] Channel n Overcurrent Detection Window Notification
                                         *   1 Division Ratio setting                                                  */
            uint32_t               : 10;
            __IOM uint32_t OWFINT1 : 1; /*!< [31..31] Channel n Overcurrent Detection Window Notification
                                         *   1Suppression Filter Initialization                                        */
#endif
        } DSODWN1FCR_b;
    };

    union
    {
        __IOM uint32_t DSODWN2FCR;     /*!< (@ 0x00000048) Overcurrent Detect Window Notification 2 Suppression
                                        *                  Filter Control Register Channel 0                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t OWFINT2 : 1; /*!< [31..31] Channel n Overcurrent Detection Window Notification
                                         *   2Suppression Filter Initialization                                        */
            uint32_t             : 10;
            __IOM uint32_t OWDR2 : 5;   /*!< [20..16] Channel n Overcurrent Detection Window Notification
                                         *   2 Division Ratio setting                                                  */
            uint32_t             : 3;
            __IOM uint32_t OWTH2 : 5;   /*!< [12..8] Channel n Overcurrent Detection Window Notification
                                         *   2 Threshold setting                                                       */
            uint32_t             : 3;
            __IOM uint32_t OWSN2 : 5;   /*!< [4..0] Channel n Overcurrent Detection Window Notification 2
                                         *   Shift register stages Number setting                                      */
#else
            __IOM uint32_t OWSN2 : 5;   /*!< [4..0] Channel n Overcurrent Detection Window Notification 2
                                         *   Shift register stages Number setting                                      */
            uint32_t             : 3;
            __IOM uint32_t OWTH2 : 5;   /*!< [12..8] Channel n Overcurrent Detection Window Notification
                                         *   2 Threshold setting                                                       */
            uint32_t             : 3;
            __IOM uint32_t OWDR2 : 5;   /*!< [20..16] Channel n Overcurrent Detection Window Notification
                                         *   2 Division Ratio setting                                                  */
            uint32_t               : 10;
            __IOM uint32_t OWFINT2 : 1; /*!< [31..31] Channel n Overcurrent Detection Window Notification
                                         *   2Suppression Filter Initialization                                        */
#endif
        } DSODWN2FCR_b;
    };

    __IM uint32_t RESERVED3;

    union
    {
        __IOM uint32_t DSCLOCK;        /*!< (@ 0x00000050) Channel Lock Register Channel 0                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 31;
            __IOM uint32_t WNFCRL : 1; /*!< [0..0] Overcurrent Detect Window Notification Filter Control
                                        *   Register Lock                                                             */
#else
            __IOM uint32_t WNFCRL : 1; /*!< [0..0] Overcurrent Detect Window Notification Filter Control
                                        *   Register Lock                                                             */
            uint32_t : 31;
#endif
        } DSCLOCK_b;
    };

    __IM uint32_t RESERVED4[19];

    __IOM R_DSMIF0_CH_TR_Type TR[3];   /*!< (@ 0x000000A0) Overcurrent Threshold Registers                            */

    __IM uint32_t RESERVED5[10];

    union
    {
        __IOM uint32_t DSCSTRTR;       /*!< (@ 0x000000E0) Software Start Trigger Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 31;
            __IOM uint32_t STRTRG : 1; /*!< [0..0] Channel start trigger                                              */
#else
            __IOM uint32_t STRTRG : 1; /*!< [0..0] Channel start trigger                                              */
            uint32_t              : 31;
#endif
        } DSCSTRTR_b;
    };

    union
    {
        __IOM uint32_t DSCSTPTR;       /*!< (@ 0x000000E4) Software Stop Trigger Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 31;
            __IOM uint32_t STPTRG : 1; /*!< [0..0] Channel stop trigger                                               */
#else
            __IOM uint32_t STPTRG : 1; /*!< [0..0] Channel stop trigger                                               */
            uint32_t              : 31;
#endif
        } DSCSTPTR_b;
    };
    __IM uint32_t RESERVED6[2];

    union
    {
        __IM uint32_t DSCDR;           /*!< (@ 0x000000F0) Current Data Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 16;
            __IM uint32_t ADDR : 16;   /*!< [15..0] Current data                                                      */
#else
            __IM uint32_t ADDR : 16;   /*!< [15..0] Current data                                                      */
            uint32_t           : 16;
#endif
        } DSCDR_b;
    };

    union
    {
        __IM uint32_t DSCCDRA;         /*!< (@ 0x000000F4) Capture Current Data Register A                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 16;
            __IM uint32_t CDRA : 16;   /*!< [15..0] Capture current data A                                            */
#else
            __IM uint32_t CDRA : 16;   /*!< [15..0] Capture current data A                                            */
            uint32_t           : 16;
#endif
        } DSCCDRA_b;
    };

    union
    {
        __IM uint32_t DSCCDRB;         /*!< (@ 0x000000F8) Capture Current Data Register B                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 16;
            __IM uint32_t CDRB : 16;   /*!< [15..0] Capture current data B                                            */
#else
            __IM uint32_t CDRB : 16;   /*!< [15..0] Capture current data B                                            */
            uint32_t           : 16;
#endif
        } DSCCDRB_b;
    };

    union
    {
        __IM uint32_t DSOCDR;          /*!< (@ 0x000003FC) Overcurrent Data Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 16;
            __IM uint32_t ODR : 16;    /*!< [15..0] Overcurrent data                                                  */
#else
            __IM uint32_t ODR : 16;    /*!< [15..0] Overcurrent data                                                  */
            uint32_t          : 16;
#endif
        } DSOCDR_b;
    };

    union
    {
        __IM uint32_t DSCOCDR[3];      /*!< (@ 0x00000100) Capture Overcurrent Data Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 16;
            __IM uint32_t CODR : 16;   /*!< [15..0] Capture overcurrent data                                          */
#else
            __IM uint32_t CODR : 16;   /*!< [15..0] Capture overcurrent data                                          */
            uint32_t           : 16;
#endif
        } DSCOCDR_b[3];
    };
    __IM uint32_t RESERVED7[5];

    union
    {
        __IM uint32_t DSCSR;           /*!< (@ 0x00000120) Status Register                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 2;
            __IM uint32_t OC2CMPH : 1; /*!< [29..29] Channel n overcurrent detect 2 upper limit compare
                                        *   result                                                                    */
            __IM uint32_t OC2CMPL : 1; /*!< [28..28] Channel n overcurrent detect 2 lower limit compare
                                        *   result                                                                    */
            __IM uint32_t OC1CMPH : 1; /*!< [27..27] Channel n overcurrent detect 1 upper limit compare
                                        *   result                                                                    */
            __IM uint32_t OC1CMPL : 1; /*!< [26..26] Channel n overcurrent detect 1 lower limit compare
                                        *   result                                                                    */
            __IM uint32_t OC0CMPH : 1; /*!< [25..25] Channel n overcurrent detect 0 upper limit compare
                                        *   result                                                                    */
            __IM uint32_t OC0CMPL : 1; /*!< [24..24] Channel n overcurrent detect 0 lower limit compare
                                        *   result                                                                    */
            uint32_t            : 4;
            __IM uint32_t OWD3N : 1;   /*!< [19..19] Channel n overcurrent detection window notification
                                        *   3                                                                         */
            __IM uint32_t OWD2N : 1;   /*!< [18..18] Channel n overcurrent detection window notification
                                        *   2                                                                         */
            __IM uint32_t OWD1N : 1;   /*!< [17..17] Channel n overcurrent detection window notification
                                        *   1                                                                         */
            __IM uint32_t OWD0N : 1;   /*!< [16..16] Channel n overcurrent detection window notification
                                        *   0                                                                         */
            uint32_t              : 2;
            __IM uint32_t OC2FH   : 1; /*!< [13..13] Channel n overcurrent upper limit exceeded 2 flag                */
            __IM uint32_t OC2FL   : 1; /*!< [12..12] Channel n overcurrent lower limit detection 2 flag               */
            __IM uint32_t OC1FH   : 1; /*!< [11..11] Channel n overcurrent upper limit exceeded 1 flag                */
            __IM uint32_t OC1FL   : 1; /*!< [10..10] Channel n overcurrent lower limit detection 1 flag               */
            __IM uint32_t OC0FH   : 1; /*!< [9..9] Channel n overcurrent upper limit exceeded 0 flag                  */
            __IM uint32_t OC0FL   : 1; /*!< [8..8] Channel n overcurrent lower limit detection 0 flag                 */
            __IM uint32_t CHSTATE : 1; /*!< [7..7] Channel n state                                                    */
            uint32_t              : 3;
            __IM uint32_t SCF     : 1; /*!< [3..3] Channel n short circuit detection flag                             */
            __IM uint32_t CBUF    : 1; /*!< [2..2] Channel n capture data B update flag                               */
            __IM uint32_t CAUF    : 1; /*!< [1..1] Channel n capture data A update flag                               */
            __IM uint32_t DUF     : 1; /*!< [0..0] Channel n data update flag                                         */
#else
            __IM uint32_t DUF     : 1; /*!< [0..0] Channel n data update flag                                         */
            __IM uint32_t CAUF    : 1; /*!< [1..1] Channel n capture data A update flag                               */
            __IM uint32_t CBUF    : 1; /*!< [2..2] Channel n capture data B update flag                               */
            __IM uint32_t SCF     : 1; /*!< [3..3] Channel n short circuit detection flag                             */
            uint32_t              : 3;
            __IM uint32_t CHSTATE : 1; /*!< [7..7] Channel n state                                                    */
            __IM uint32_t OC0FL   : 1; /*!< [8..8] Channel n overcurrent lower limit detection 0 flag                 */
            __IM uint32_t OC0FH   : 1; /*!< [9..9] Channel n overcurrent upper limit exceeded 0 flag                  */
            __IM uint32_t OC1FL   : 1; /*!< [10..10] Channel n overcurrent lower limit detection 1 flag               */
            __IM uint32_t OC1FH   : 1; /*!< [11..11] Channel n overcurrent upper limit exceeded 1 flag                */
            __IM uint32_t OC2FL   : 1; /*!< [12..12] Channel n overcurrent lower limit detection 2 flag               */
            __IM uint32_t OC2FH   : 1; /*!< [13..13] Channel n overcurrent upper limit exceeded 2 flag                */
            uint32_t              : 2;
            __IM uint32_t OWD0N   : 1; /*!< [16..16] Channel n overcurrent detection window notification
                                        *   0                                                                         */
            __IM uint32_t OWD1N : 1;   /*!< [17..17] Channel n overcurrent detection window notification
                                        *   1                                                                         */
            __IM uint32_t OWD2N : 1;   /*!< [18..18] Channel n overcurrent detection window notification
                                        *   2                                                                         */
            __IM uint32_t OWD3N : 1;   /*!< [19..19] Channel n overcurrent detection window notification
                                        *   3                                                                         */
            uint32_t              : 4;
            __IM uint32_t OC0CMPL : 1; /*!< [24..24] Channel n overcurrent detect 0 lower limit compare
                                        *   result                                                                    */
            __IM uint32_t OC0CMPH : 1; /*!< [25..25] Channel n overcurrent detect 0 upper limit compare
                                        *   result                                                                    */
            __IM uint32_t OC1CMPL : 1; /*!< [26..26] Channel n overcurrent detect 1 lower limit compare
                                        *   result                                                                    */
            __IM uint32_t OC1CMPH : 1; /*!< [27..27] Channel n overcurrent detect 1 upper limit compare
                                        *   result                                                                    */
            __IM uint32_t OC2CMPL : 1; /*!< [28..28] Channel n overcurrent detect 2 lower limit compare
                                        *   result                                                                    */
            __IM uint32_t OC2CMPH : 1; /*!< [29..29] Channel n overcurrent detect 2 upper limit compare
                                        *   result                                                                    */
            uint32_t : 2;
#endif
        } DSCSR_b;
    };
    __IM uint32_t RESERVED8[3];

    union
    {
        __OM uint32_t DSCSCR;          /*!< (@ 0x00000130) Status Clear Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 12;
            __OM uint32_t CLROWD3N : 1; /*!< [19..19] Channel n overcurrent detection window notification
                                         *   3 flag clear                                                              */
            __OM uint32_t CLROWD2N : 1; /*!< [18..18] Channel n overcurrent detection window notification
                                         *   2 flag clear                                                              */
            __OM uint32_t CLROWD1N : 1; /*!< [17..17] Channel n overcurrent detection window notification
                                         *   1 flag clear                                                              */
            __OM uint32_t CLROWD0N : 1; /*!< [16..16] Channel n overcurrent detection window notification
                                         *   0 flag clear                                                              */
            uint32_t               : 2;
            __OM uint32_t CLROC2FH : 1; /*!< [13..13] Channel n overcurrent upper limit exceeded flag 2 clear          */
            __OM uint32_t CLROC2FL : 1; /*!< [12..12] Channel n overcurrent lower limit detection flag 2
                                         *   clear                                                                     */
            __OM uint32_t CLROC1FH : 1; /*!< [11..11] Channel n overcurrent upper limit exceeded flag 1 clear          */
            __OM uint32_t CLROC1FL : 1; /*!< [10..10] Channel n overcurrent lower limit detection flag 1
                                         *   clear                                                                     */
            __OM uint32_t CLROC0FH : 1; /*!< [9..9] Channel n overcurrent upper limit exceeded flag 0 clear            */
            __OM uint32_t CLROC0FL : 1; /*!< [8..8] Channel n overcurrent lower limit detection flag 0 clear           */
            uint32_t               : 4;
            __OM uint32_t CLRSCF   : 1; /*!< [3..3] Channel n short circuit detection flag clear                       */
            __OM uint32_t CLRCBUF  : 1; /*!< [2..2] Channel n capture data B update flag clear                         */
            __OM uint32_t CLRCAUF  : 1; /*!< [1..1] Channel n capture data A update flag clear                         */
            __OM uint32_t CLRDUF   : 1; /*!< [0..0] Channel n data update flag clear                                   */
#else
            __OM uint32_t CLRDUF   : 1; /*!< [0..0] Channel n data update flag clear                                   */
            __OM uint32_t CLRCAUF  : 1; /*!< [1..1] Channel n capture data A update flag clear                         */
            __OM uint32_t CLRCBUF  : 1; /*!< [2..2] Channel n capture data B update flag clear                         */
            __OM uint32_t CLRSCF   : 1; /*!< [3..3] Channel n short circuit detection flag clear                       */
            uint32_t               : 4;
            __OM uint32_t CLROC0FL : 1; /*!< [8..8] Channel n overcurrent lower limit detection flag 0 clear           */
            __OM uint32_t CLROC0FH : 1; /*!< [9..9] Channel n overcurrent upper limit exceeded flag 0 clear            */
            __OM uint32_t CLROC1FL : 1; /*!< [10..10] Channel n overcurrent lower limit detection flag 1
                                         *   clear                                                                     */
            __OM uint32_t CLROC1FH : 1; /*!< [11..11] Channel n overcurrent upper limit exceeded flag 1 clear          */
            __OM uint32_t CLROC2FL : 1; /*!< [12..12] Channel n overcurrent lower limit detection flag 2
                                         *   clear                                                                     */
            __OM uint32_t CLROC2FH : 1; /*!< [13..13] Channel n overcurrent upper limit exceeded flag 2 clear          */
            uint32_t               : 2;
            __OM uint32_t CLROWD0N : 1; /*!< [16..16] Channel n overcurrent detection window notification
                                         *   0 flag clear                                                              */
            __OM uint32_t CLROWD1N : 1; /*!< [17..17] Channel n overcurrent detection window notification
                                         *   1 flag clear                                                              */
            __OM uint32_t CLROWD2N : 1; /*!< [18..18] Channel n overcurrent detection window notification
                                         *   2 flag clear                                                              */
            __OM uint32_t CLROWD3N : 1; /*!< [19..19] Channel n overcurrent detection window notification
                                         *   3 flag clear                                                              */
            uint32_t : 12;
#endif
        } DSCSCR_b;
    };

    __IM uint32_t RESERVED9[3];
} R_DSMIF0_CH_Type;                    /*!< Size = 320 (0x140)                                                        */

/* =========================================================================================================================== */
/* ================                                         R_DSMIF0                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Delta-Sigma Modulators 0 (R_DSMIF0)
 */

typedef struct                         /*!< (@ 0x8742A000) R_DSMIF0 Structure                                         */
{
    union
    {
        __IOM uint32_t DSCCSCR;        /*!< (@ 0x00000000) Core Clock Selection Control Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 30;
            __IOM uint32_t CLKSEL : 2; /*!< [1..0] Selection of core clock                                            */
#else
            __IOM uint32_t CLKSEL : 2; /*!< [1..0] Selection of core clock                                            */
            uint32_t              : 30;
#endif
        } DSCCSCR_b;
    };
    __IM uint32_t RESERVED[31];

    union
    {
        __IOM uint32_t DSSEICR;        /*!< (@ 0x00000080) Overcurrent Sum Error detect Interrupt Control
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 30;
            __IOM uint32_t ISEH : 1;   /*!< [1..1] Overcurrent sum error upper limit detection interrupt
                                        *   enable bit                                                                */
            __IOM uint32_t ISEL : 1;   /*!< [0..0] Overcurrent sum error lower limit detection interrupt
                                        *   enable bit                                                                */
#else
            __IOM uint32_t ISEL : 1;   /*!< [0..0] Overcurrent sum error lower limit detection interrupt
                                        *   enable bit                                                                */
            __IOM uint32_t ISEH : 1;   /*!< [1..1] Overcurrent sum error upper limit detection interrupt
                                        *   enable bit                                                                */
            uint32_t : 30;
#endif
        } DSSEICR_b;
    };

    union
    {
        __IOM uint32_t DSSECSR;        /*!< (@ 0x00000084) Overcurrent Sum Error detect Channel Setting
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 29;
            __IOM uint32_t SEDM : 3;   /*!< [2..0] Overcurrent sum error detect mode setting bit                      */
#else
            __IOM uint32_t SEDM : 3;   /*!< [2..0] Overcurrent sum error detect mode setting bit                      */
            uint32_t            : 29;
#endif
        } DSSECSR_b;
    };

    union
    {
        __IOM uint32_t DSSELTR;        /*!< (@ 0x00000088) Overcurrent Sum Error detect Low Threshold Register        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 14;
            __IOM uint32_t SCMPTBL : 18; /*!< [17..0] Overcurrent sum error detect lower limit                          */
#else
            __IOM uint32_t SCMPTBL : 18; /*!< [17..0] Overcurrent sum error detect lower limit                          */
            uint32_t               : 14;
#endif
        } DSSELTR_b;
    };

    union
    {
        __IOM uint32_t DSSEHTR;        /*!< (@ 0x0000008C) Overcurrent Sum Error detect High Threshold Register       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 14;
            __IOM uint32_t SCMPTBH : 18; /*!< [17..0] Overcurrent sum error detect upper limit                          */
#else
            __IOM uint32_t SCMPTBH : 18; /*!< [17..0] Overcurrent sum error detect upper limit                          */
            uint32_t               : 14;
#endif
        } DSSEHTR_b;
    };

    union
    {
        __IOM uint32_t DSSECR;         /*!< (@ 0x00000090) Overcurrent Sum Error detect Control Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 30;
            __IOM uint32_t SEEH : 1;   /*!< [1..1] Overcurrent sum error upper limit detection enable bit             */
            __IOM uint32_t SEEL : 1;   /*!< [0..0] Overcurrent sum error lower limit detection enable bit             */
#else
            __IOM uint32_t SEEL : 1;   /*!< [0..0] Overcurrent sum error lower limit detection enable bit             */
            __IOM uint32_t SEEH : 1;   /*!< [1..1] Overcurrent sum error upper limit detection enable bit             */
            uint32_t            : 30;
#endif
        } DSSECR_b;
    };
    __IM uint32_t RESERVED1[3];

    union
    {
        __IOM uint32_t DSSECDR[3];     /*!< (@ 0x000000A0) Overcurrent Sum Error Detect Capture Data Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 16;
            __IOM uint32_t SECDR : 16; /*!< [15..0] Overcurrent sum error detect capture data                         */
#else
            __IOM uint32_t SECDR : 16; /*!< [15..0] Overcurrent sum error detect capture data                         */
            uint32_t             : 16;
#endif
        } DSSECDR_b[3];
    };
    __IM uint32_t RESERVED2[5];

    union
    {
        __IOM uint32_t DSCMSR;         /*!< (@ 0x000000C0) Common mode setting Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 29;
            __IOM uint32_t CISM : 2;   /*!< [2..1] Common Interrupt Synchronous channel Mode setting bit              */
            __IOM uint32_t DFS  : 1;   /*!< [0..0] Data Format select bit                                             */
#else
            __IOM uint32_t DFS  : 1;   /*!< [0..0] Data Format select bit                                             */
            __IOM uint32_t CISM : 2;   /*!< [2..1] Common Interrupt Synchronous channel Mode setting bit              */
            uint32_t            : 29;
#endif
        } DSCMSR_b;
    };

    union
    {
        __IOM uint32_t DSCICR;         /*!< (@ 0x000000C4) Common Interrupt Control Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 29;
            __IOM uint32_t IBUCE : 1;  /*!< [2..2] Capture current data register B update channel common
                                        *   interrupt enable                                                          */
            __IOM uint32_t IAUCE : 1;  /*!< [1..1] Capture current data register A update channel common
                                        *   interrupt enable                                                          */
            __IOM uint32_t IUCE : 1;   /*!< [0..0] Current data register update channel common interrupt
                                        *   enable                                                                    */
#else
            __IOM uint32_t IUCE : 1;   /*!< [0..0] Current data register update channel common interrupt
                                        *   enable                                                                    */
            __IOM uint32_t IAUCE : 1;  /*!< [1..1] Capture current data register A update channel common
                                        *   interrupt enable                                                          */
            __IOM uint32_t IBUCE : 1;  /*!< [2..2] Capture current data register B update channel common
                                        *   interrupt enable                                                          */
            uint32_t : 29;
#endif
        } DSCICR_b;
    };
    __IM uint32_t RESERVED3[78];

    union
    {
        __OM uint32_t DSCSTRTR;        /*!< (@ 0x00000200) Channel software start trigger register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 29;
            __OM uint32_t STRTRG2 : 1; /*!< [2..2] Channel 2 start trigger                                            */
            __OM uint32_t STRTRG1 : 1; /*!< [1..1] Channel 1 start trigger                                            */
            __OM uint32_t STRTRG0 : 1; /*!< [0..0] Channel 0 start trigger                                            */
#else
            __OM uint32_t STRTRG0 : 1; /*!< [0..0] Channel 0 start trigger                                            */
            __OM uint32_t STRTRG1 : 1; /*!< [1..1] Channel 1 start trigger                                            */
            __OM uint32_t STRTRG2 : 1; /*!< [2..2] Channel 2 start trigger                                            */
            uint32_t              : 29;
#endif
        } DSCSTRTR_b;
    };

    union
    {
        __OM uint32_t DSCSTPTR;        /*!< (@ 0x00000204) Channel software stop trigger register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 29;
            __OM uint32_t STPTRG2 : 1; /*!< [2..2] Channel 2 Stop trigger                                             */
            __OM uint32_t STPTRG1 : 1; /*!< [1..1] Channel 1 Stop trigger                                             */
            __OM uint32_t STPTRG0 : 1; /*!< [0..0] Channel 0 Stop trigger                                             */
#else
            __OM uint32_t STPTRG0 : 1; /*!< [0..0] Channel 0 Stop trigger                                             */
            __OM uint32_t STPTRG1 : 1; /*!< [1..1] Channel 1 Stop trigger                                             */
            __OM uint32_t STPTRG2 : 1; /*!< [2..2] Channel 2 Stop trigger                                             */
            uint32_t              : 29;
#endif
        } DSCSTPTR_b;
    };
    __IM uint32_t RESERVED4[6];

    union
    {
        __IM uint32_t DSCESR;          /*!< (@ 0x00000220) Channel Error Status register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 14;
            __IM uint32_t SUMERRH : 1; /*!< [17..17] Overcurrent sum error upper limit detection Flag                 */
            __IM uint32_t SUMERRL : 1; /*!< [16..16] Overcurrent sum error lower limit detection Flag                 */
            uint32_t              : 13;
            __IM uint32_t SCF2    : 1; /*!< [2..2] Channel 2 short circuit detection flag                             */
            __IM uint32_t SCF1    : 1; /*!< [1..1] Channel 1 short circuit detection flag                             */
            __IM uint32_t SCF0    : 1; /*!< [0..0] Channel 0 short circuit detection flag                             */
#else
            __IM uint32_t SCF0    : 1; /*!< [0..0] Channel 0 short circuit detection flag                             */
            __IM uint32_t SCF1    : 1; /*!< [1..1] Channel 1 short circuit detection flag                             */
            __IM uint32_t SCF2    : 1; /*!< [2..2] Channel 2 short circuit detection flag                             */
            uint32_t              : 13;
            __IM uint32_t SUMERRL : 1; /*!< [16..16] Overcurrent sum error lower limit detection Flag                 */
            __IM uint32_t SUMERRH : 1; /*!< [17..17] Overcurrent sum error upper limit detection Flag                 */
            uint32_t              : 14;
#endif
        } DSCESR_b;
    };

    union
    {
        __IM uint32_t DSCOCESR;        /*!< (@ 0x00000224) Channel Overcurrent Error Status register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 9;
            __IM uint32_t OC2FH2 : 1;  /*!< [22..22] Channel 2 overcurrent upper limit exceeded 2 flag                */
            __IM uint32_t OC2FH1 : 1;  /*!< [21..21] Channel 1 overcurrent upper limit exceeded 2 flag                */
            __IM uint32_t OC2FH0 : 1;  /*!< [20..20] Channel 0 overcurrent upper limit exceeded 2 flag                */
            uint32_t             : 1;
            __IM uint32_t OC2FL2 : 1;  /*!< [18..18] Channel 2 overcurrent lower limit detection 2 flag               */
            __IM uint32_t OC2FL1 : 1;  /*!< [17..17] Channel 1 overcurrent lower limit detection 2 flag               */
            __IM uint32_t OC2FL0 : 1;  /*!< [16..16] Channel 0 overcurrent lower limit detection 2 flag               */
            uint32_t             : 1;
            __IM uint32_t OC1FH2 : 1;  /*!< [14..14] Channel 2 overcurrent upper limit exceeded 1 flag                */
            __IM uint32_t OC1FH1 : 1;  /*!< [13..13] Channel 1 overcurrent upper limit exceeded 1 flag                */
            __IM uint32_t OC1FH0 : 1;  /*!< [12..12] Channel 0 overcurrent upper limit exceeded 1 flag                */
            uint32_t             : 1;
            __IM uint32_t OC1FL2 : 1;  /*!< [10..10] Channel 2 overcurrent lower limit detection 1 flag               */
            __IM uint32_t OC1FL1 : 1;  /*!< [9..9] Channel 1 overcurrent lower limit detection 1 flag                 */
            __IM uint32_t OC1FL0 : 1;  /*!< [8..8] Channel 0 overcurrent lower limit detection 1 flag                 */
            uint32_t             : 1;
            __IM uint32_t OC0FH2 : 1;  /*!< [6..6] Channel 2 overcurrent upper limit exceeded 0 flag                  */
            __IM uint32_t OC0FH1 : 1;  /*!< [5..5] Channel 1 overcurrent upper limit exceeded 0 flag                  */
            __IM uint32_t OC0FH0 : 1;  /*!< [4..4] Channel 0 overcurrent upper limit exceeded 0 flag                  */
            uint32_t             : 1;
            __IM uint32_t OC0FL2 : 1;  /*!< [2..2] Channel 2 overcurrent lower limit detection 0 flag                 */
            __IM uint32_t OC0FL1 : 1;  /*!< [1..1] Channel 1 overcurrent lower limit detection 0 flag                 */
            __IM uint32_t OC0FL0 : 1;  /*!< [0..0] Channel 0 overcurrent lower limit detection 0 flag                 */
#else
            __IM uint32_t OC0FL0 : 1;  /*!< [0..0] Channel 0 overcurrent lower limit detection 0 flag                 */
            __IM uint32_t OC0FL1 : 1;  /*!< [1..1] Channel 1 overcurrent lower limit detection 0 flag                 */
            __IM uint32_t OC0FL2 : 1;  /*!< [2..2] Channel 2 overcurrent lower limit detection 0 flag                 */
            uint32_t             : 1;
            __IM uint32_t OC0FH0 : 1;  /*!< [4..4] Channel 0 overcurrent upper limit exceeded 0 flag                  */
            __IM uint32_t OC0FH1 : 1;  /*!< [5..5] Channel 1 overcurrent upper limit exceeded 0 flag                  */
            __IM uint32_t OC0FH2 : 1;  /*!< [6..6] Channel 2 overcurrent upper limit exceeded 0 flag                  */
            uint32_t             : 1;
            __IM uint32_t OC1FL0 : 1;  /*!< [8..8] Channel 0 overcurrent lower limit detection 1 flag                 */
            __IM uint32_t OC1FL1 : 1;  /*!< [9..9] Channel 1 overcurrent lower limit detection 1 flag                 */
            __IM uint32_t OC1FL2 : 1;  /*!< [10..10] Channel 2 overcurrent lower limit detection 1 flag               */
            uint32_t             : 1;
            __IM uint32_t OC1FH0 : 1;  /*!< [12..12] Channel 0 overcurrent upper limit exceeded 1 flag                */
            __IM uint32_t OC1FH1 : 1;  /*!< [13..13] Channel 1 overcurrent upper limit exceeded 1 flag                */
            __IM uint32_t OC1FH2 : 1;  /*!< [14..14] Channel 2 overcurrent upper limit exceeded 1 flag                */
            uint32_t             : 1;
            __IM uint32_t OC2FL0 : 1;  /*!< [16..16] Channel 0 overcurrent lower limit detection 2 flag               */
            __IM uint32_t OC2FL1 : 1;  /*!< [17..17] Channel 1 overcurrent lower limit detection 2 flag               */
            __IM uint32_t OC2FL2 : 1;  /*!< [18..18] Channel 2 overcurrent lower limit detection 2 flag               */
            uint32_t             : 1;
            __IM uint32_t OC2FH0 : 1;  /*!< [20..20] Channel 0 overcurrent upper limit exceeded 2 flag                */
            __IM uint32_t OC2FH1 : 1;  /*!< [21..21] Channel 1 overcurrent upper limit exceeded 2 flag                */
            __IM uint32_t OC2FH2 : 1;  /*!< [22..22] Channel 2 overcurrent upper limit exceeded 2 flag                */
            uint32_t             : 9;
#endif
        } DSCOCESR_b;
    };

    union
    {
        __IM uint32_t DSCOCNSR;        /*!< (@ 0x00000228) Channel Overcurrent Notification Status register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 17;
            __IM uint32_t OWD3N2 : 1;  /*!< [14..14] Channel 2 overcurrent detection window notification
                                        *   3 flag                                                                    */
            __IM uint32_t OWD3N1 : 1;  /*!< [13..13] Channel 1 overcurrent detection window notification
                                        *   3 flag                                                                    */
            __IM uint32_t OWD3N0 : 1;  /*!< [12..12] Channel 0 overcurrent detection window notification
                                        *   3 flag                                                                    */
            uint32_t             : 1;
            __IM uint32_t OWD2N2 : 1;  /*!< [10..10] Channel 2 overcurrent detection window notification
                                        *   2 flag                                                                    */
            __IM uint32_t OWD2N1 : 1;  /*!< [9..9] Channel 1 overcurrent detection window notification 2
                                        *   flag                                                                      */
            __IM uint32_t OWD2N0 : 1;  /*!< [8..8] Channel 0 overcurrent detection window notification 2
                                        *   flag                                                                      */
            uint32_t             : 1;
            __IM uint32_t OWD1N2 : 1;  /*!< [6..6] Channel 2 overcurrent detection window notification 1
                                        *   flag                                                                      */
            __IM uint32_t OWD1N1 : 1;  /*!< [5..5] Channel 1 overcurrent detection window notification 1
                                        *   flag                                                                      */
            __IM uint32_t OWD1N0 : 1;  /*!< [4..4] Channel 0 overcurrent detection window notification 1
                                        *   flag                                                                      */
            uint32_t             : 1;
            __IM uint32_t OWD0N2 : 1;  /*!< [2..2] Channel 2 overcurrent detection window notification 0
                                        *   flag                                                                      */
            __IM uint32_t OWD0N1 : 1;  /*!< [1..1] Channel 1 overcurrent detection window notification 0
                                        *   flag                                                                      */
            __IM uint32_t OWD0N0 : 1;  /*!< [0..0] Channel 0 overcurrent detection window notification 0
                                        *   flag                                                                      */
#else
            __IM uint32_t OWD0N0 : 1;  /*!< [0..0] Channel 0 overcurrent detection window notification 0
                                        *   flag                                                                      */
            __IM uint32_t OWD0N1 : 1;  /*!< [1..1] Channel 1 overcurrent detection window notification 0
                                        *   flag                                                                      */
            __IM uint32_t OWD0N2 : 1;  /*!< [2..2] Channel 2 overcurrent detection window notification 0
                                        *   flag                                                                      */
            uint32_t             : 1;
            __IM uint32_t OWD1N0 : 1;  /*!< [4..4] Channel 0 overcurrent detection window notification 1
                                        *   flag                                                                      */
            __IM uint32_t OWD1N1 : 1;  /*!< [5..5] Channel 1 overcurrent detection window notification 1
                                        *   flag                                                                      */
            __IM uint32_t OWD1N2 : 1;  /*!< [6..6] Channel 2 overcurrent detection window notification 1
                                        *   flag                                                                      */
            uint32_t             : 1;
            __IM uint32_t OWD2N0 : 1;  /*!< [8..8] Channel 0 overcurrent detection window notification 2
                                        *   flag                                                                      */
            __IM uint32_t OWD2N1 : 1;  /*!< [9..9] Channel 1 overcurrent detection window notification 2
                                        *   flag                                                                      */
            __IM uint32_t OWD2N2 : 1;  /*!< [10..10] Channel 2 overcurrent detection window notification
                                        *   2 flag                                                                    */
            uint32_t             : 1;
            __IM uint32_t OWD3N0 : 1;  /*!< [12..12] Channel 0 overcurrent detection window notification
                                        *   3 flag                                                                    */
            __IM uint32_t OWD3N1 : 1;  /*!< [13..13] Channel 1 overcurrent detection window notification
                                        *   3 flag                                                                    */
            __IM uint32_t OWD3N2 : 1;  /*!< [14..14] Channel 2 overcurrent detection window notification
                                        *   3 flag                                                                    */
            uint32_t : 17;
#endif
        } DSCOCNSR_b;
    };

    union
    {
        __IM uint32_t DSCOCRMR;        /*!< (@ 0x0000022C) Channel Overcurrent Comparator Result Monitor
                                        *                  register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 9;
            __IM uint32_t OC2CMPH2 : 1; /*!< [22..22] Channel 2 Overcurrent Detect 2 Upper limit compare
                                         *   result                                                                    */
            __IM uint32_t OC2CMPH1 : 1; /*!< [21..21] Channel 1 Overcurrent Detect 2 Upper limit compare
                                         *   result                                                                    */
            __IM uint32_t OC2CMPH0 : 1; /*!< [20..20] Channel 0 Overcurrent Detect 2 Upper limit compare
                                         *   result                                                                    */
            uint32_t               : 1;
            __IM uint32_t OC2CMPL2 : 1; /*!< [18..18] Channel 2 Overcurrent detect 2 Lower limit compare
                                         *   result                                                                    */
            __IM uint32_t OC2CMPL1 : 1; /*!< [17..17] Channel 1 Overcurrent detect 2 Lower limit compare
                                         *   result                                                                    */
            __IM uint32_t OC2CMPL0 : 1; /*!< [16..16] Channel 0 Overcurrent detect 2 Lower limit compare
                                         *   result                                                                    */
            uint32_t               : 1;
            __IM uint32_t OC1CMPH2 : 1; /*!< [14..14] Channel 2 Overcurrent Detect 1 Upper limit compare
                                         *   result                                                                    */
            __IM uint32_t OC1CMPH1 : 1; /*!< [13..13] Channel 1 Overcurrent Detect 1 Upper limit compare
                                         *   result                                                                    */
            __IM uint32_t OC1CMPH0 : 1; /*!< [12..12] Channel 0 Overcurrent Detect 1 Upper limit compare
                                         *   result                                                                    */
            uint32_t               : 1;
            __IM uint32_t OC1CMPL2 : 1; /*!< [10..10] Channel 2 Overcurrent Detect 1 Lower limit compare
                                         *   result                                                                    */
            __IM uint32_t OC1CMPL1 : 1; /*!< [9..9] Channel 1 Overcurrent Detect 1 Lower limit compare result          */
            __IM uint32_t OC1CMPL0 : 1; /*!< [8..8] Channel 0 Overcurrent Detect 1 Lower limit compare result          */
            uint32_t               : 1;
            __IM uint32_t OC0CMPH2 : 1; /*!< [6..6] Channel 2 Overcurrent Detect 0 Upper limit compare result          */
            __IM uint32_t OC0CMPH1 : 1; /*!< [5..5] Channel 1 Overcurrent Detect 0 Upper limit compare result          */
            __IM uint32_t OC0CMPH0 : 1; /*!< [4..4] Channel 0 Overcurrent Detect 0 Upper limit compare result          */
            uint32_t               : 1;
            __IM uint32_t OC0CMPL2 : 1; /*!< [2..2] Channel 2 Overcurrent Detect 0 Lower limit compare result          */
            __IM uint32_t OC0CMPL1 : 1; /*!< [1..1] Channel 1 Overcurrent Detect 0 Lower limit compare result          */
            __IM uint32_t OC0CMPL0 : 1; /*!< [0..0] Channel 0 Overcurrent Detect 0 Lower limit compare result          */
#else
            __IM uint32_t OC0CMPL0 : 1; /*!< [0..0] Channel 0 Overcurrent Detect 0 Lower limit compare result          */
            __IM uint32_t OC0CMPL1 : 1; /*!< [1..1] Channel 1 Overcurrent Detect 0 Lower limit compare result          */
            __IM uint32_t OC0CMPL2 : 1; /*!< [2..2] Channel 2 Overcurrent Detect 0 Lower limit compare result          */
            uint32_t               : 1;
            __IM uint32_t OC0CMPH0 : 1; /*!< [4..4] Channel 0 Overcurrent Detect 0 Upper limit compare result          */
            __IM uint32_t OC0CMPH1 : 1; /*!< [5..5] Channel 1 Overcurrent Detect 0 Upper limit compare result          */
            __IM uint32_t OC0CMPH2 : 1; /*!< [6..6] Channel 2 Overcurrent Detect 0 Upper limit compare result          */
            uint32_t               : 1;
            __IM uint32_t OC1CMPL0 : 1; /*!< [8..8] Channel 0 Overcurrent Detect 1 Lower limit compare result          */
            __IM uint32_t OC1CMPL1 : 1; /*!< [9..9] Channel 1 Overcurrent Detect 1 Lower limit compare result          */
            __IM uint32_t OC1CMPL2 : 1; /*!< [10..10] Channel 2 Overcurrent Detect 1 Lower limit compare
                                         *   result                                                                    */
            uint32_t               : 1;
            __IM uint32_t OC1CMPH0 : 1; /*!< [12..12] Channel 0 Overcurrent Detect 1 Upper limit compare
                                         *   result                                                                    */
            __IM uint32_t OC1CMPH1 : 1; /*!< [13..13] Channel 1 Overcurrent Detect 1 Upper limit compare
                                         *   result                                                                    */
            __IM uint32_t OC1CMPH2 : 1; /*!< [14..14] Channel 2 Overcurrent Detect 1 Upper limit compare
                                         *   result                                                                    */
            uint32_t               : 1;
            __IM uint32_t OC2CMPL0 : 1; /*!< [16..16] Channel 0 Overcurrent detect 2 Lower limit compare
                                         *   result                                                                    */
            __IM uint32_t OC2CMPL1 : 1; /*!< [17..17] Channel 1 Overcurrent detect 2 Lower limit compare
                                         *   result                                                                    */
            __IM uint32_t OC2CMPL2 : 1; /*!< [18..18] Channel 2 Overcurrent detect 2 Lower limit compare
                                         *   result                                                                    */
            uint32_t               : 1;
            __IM uint32_t OC2CMPH0 : 1; /*!< [20..20] Channel 0 Overcurrent Detect 2 Upper limit compare
                                         *   result                                                                    */
            __IM uint32_t OC2CMPH1 : 1; /*!< [21..21] Channel 1 Overcurrent Detect 2 Upper limit compare
                                         *   result                                                                    */
            __IM uint32_t OC2CMPH2 : 1; /*!< [22..22] Channel 2 Overcurrent Detect 2 Upper limit compare
                                         *   result                                                                    */
            uint32_t : 9;
#endif
        } DSCOCRMR_b;
    };
    __IM uint32_t RESERVED5[4];

    union
    {
        __IM uint32_t DSCSR;           /*!< (@ 0x00000240) Channel Status register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 21;
            __IM uint32_t CBUF2 : 1;   /*!< [10..10] Channel 2 Capture data B update flag                             */
            __IM uint32_t CBUF1 : 1;   /*!< [9..9] Channel 1 Capture data B update flag                               */
            __IM uint32_t CBUF0 : 1;   /*!< [8..8] Channel 0 Capture data B update flag                               */
            uint32_t            : 1;
            __IM uint32_t CAUF2 : 1;   /*!< [6..6] Channel 2 Capture data A update flag                               */
            __IM uint32_t CAUF1 : 1;   /*!< [5..5] Channel 1 Capture data A update flag                               */
            __IM uint32_t CAUF0 : 1;   /*!< [4..4] Channel 0 Capture data A update flag                               */
            uint32_t            : 1;
            __IM uint32_t DUF2  : 1;   /*!< [2..2] Channel 2 data update flag                                         */
            __IM uint32_t DUF1  : 1;   /*!< [1..1] Channel 1 data update flag                                         */
            __IM uint32_t DUF0  : 1;   /*!< [0..0] Channel 0 data update flag                                         */
#else
            __IM uint32_t DUF0  : 1;   /*!< [0..0] Channel 0 data update flag                                         */
            __IM uint32_t DUF1  : 1;   /*!< [1..1] Channel 1 data update flag                                         */
            __IM uint32_t DUF2  : 1;   /*!< [2..2] Channel 2 data update flag                                         */
            uint32_t            : 1;
            __IM uint32_t CAUF0 : 1;   /*!< [4..4] Channel 0 Capture data A update flag                               */
            __IM uint32_t CAUF1 : 1;   /*!< [5..5] Channel 1 Capture data A update flag                               */
            __IM uint32_t CAUF2 : 1;   /*!< [6..6] Channel 2 Capture data A update flag                               */
            uint32_t            : 1;
            __IM uint32_t CBUF0 : 1;   /*!< [8..8] Channel 0 Capture data B update flag                               */
            __IM uint32_t CBUF1 : 1;   /*!< [9..9] Channel 1 Capture data B update flag                               */
            __IM uint32_t CBUF2 : 1;   /*!< [10..10] Channel 2 Capture data B update flag                             */
            uint32_t            : 21;
#endif
        } DSCSR_b;
    };

    union
    {
        __IM uint32_t DSCSSR;          /*!< (@ 0x00000244) Channel state status register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IM uint32_t CHSTATE2 : 1; /*!< [8..8] Channel 2 state                                                    */
            uint32_t               : 3;
            __IM uint32_t CHSTATE1 : 1; /*!< [4..4] Channel 1 state                                                    */
            uint32_t               : 3;
            __IM uint32_t CHSTATE0 : 1; /*!< [0..0] Channel 0 state                                                    */
#else
            __IM uint32_t CHSTATE0 : 1; /*!< [0..0] Channel 0 state                                                    */
            uint32_t               : 3;
            __IM uint32_t CHSTATE1 : 1; /*!< [4..4] Channel 1 state                                                    */
            uint32_t               : 3;
            __IM uint32_t CHSTATE2 : 1; /*!< [8..8] Channel 2 state                                                    */
            uint32_t               : 23;
#endif
        } DSCSSR_b;
    };
    __IM uint32_t RESERVED6[6];

    union
    {
        __OM uint32_t DSCESCR;         /*!< (@ 0x00000260) Channel Error Status Clear register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 14;
            __OM uint32_t CLRSUMERRH : 1; /*!< [17..17] Overcurrent sum error upper limit detection flag clear           */
            __OM uint32_t CLRSUMERRL : 1; /*!< [16..16] Overcurrent sum error lower limit detection flag clear           */
            uint32_t                 : 13;
            __OM uint32_t CLRSCF2    : 1; /*!< [2..2] Channel 2 short circuit detection flag clear                       */
            __OM uint32_t CLRSCF1    : 1; /*!< [1..1] Channel 1 short circuit detection flag clear                       */
            __OM uint32_t CLRSCF0    : 1; /*!< [0..0] Channel 0 short circuit detection flag clear                       */
#else
            __OM uint32_t CLRSCF0    : 1; /*!< [0..0] Channel 0 short circuit detection flag clear                       */
            __OM uint32_t CLRSCF1    : 1; /*!< [1..1] Channel 1 short circuit detection flag clear                       */
            __OM uint32_t CLRSCF2    : 1; /*!< [2..2] Channel 2 short circuit detection flag clear                       */
            uint32_t                 : 13;
            __OM uint32_t CLRSUMERRL : 1; /*!< [16..16] Overcurrent sum error lower limit detection flag clear           */
            __OM uint32_t CLRSUMERRH : 1; /*!< [17..17] Overcurrent sum error upper limit detection flag clear           */
            uint32_t                 : 14;
#endif
        } DSCESCR_b;
    };

    union
    {
        __OM uint32_t DSCOCESCR;       /*!< (@ 0x00000264) Channel Overcurrent Error Status Clear register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 9;
            __OM uint32_t CLROC2FH2 : 1; /*!< [22..22] Channel 2 overcurrent upper limit exceeded 2 flag clear          */
            __OM uint32_t CLROC2FH1 : 1; /*!< [21..21] Channel 1 overcurrent upper limit exceeded 2 flag clear          */
            __OM uint32_t CLROC2FH0 : 1; /*!< [20..20] Channel 0 overcurrent upper limit exceeded 2 flag clear          */
            uint32_t                : 1;
            __OM uint32_t CLROC2FL2 : 1; /*!< [18..18] Channel 2 overcurrent lower limit detection 2 flag
                                          *   clear                                                                     */
            __OM uint32_t CLROC2FL1 : 1; /*!< [17..17] Channel 1 overcurrent lower limit detection 2 flag
                                          *   clear                                                                     */
            __OM uint32_t CLROC2FL0 : 1; /*!< [16..16] Channel 0 overcurrent lower limit detection 2 flag
                                          *   clear                                                                     */
            uint32_t                : 1;
            __OM uint32_t CLROC1FH2 : 1; /*!< [14..14] Channel 2 overcurrent upper limit exceeded 1 flag clear          */
            __OM uint32_t CLROC1FH1 : 1; /*!< [13..13] Channel 1 overcurrent upper limit exceeded 1 flag clear          */
            __OM uint32_t CLROC1FH0 : 1; /*!< [12..12] Channel 0 overcurrent upper limit exceeded 1 flag clear          */
            uint32_t                : 1;
            __OM uint32_t CLROC1FL2 : 1; /*!< [10..10] Channel 2 overcurrent lower limit detection 1 flag
                                          *   clear                                                                     */
            __OM uint32_t CLROC1FL1 : 1; /*!< [9..9] Channel 1 overcurrent lower limit detection 1 flag clear           */
            __OM uint32_t CLROC1FL0 : 1; /*!< [8..8] Channel 0 overcurrent lower limit detection 1 flag clear           */
            uint32_t                : 1;
            __OM uint32_t CLROC0FH2 : 1; /*!< [6..6] Channel 2 overcurrent upper limit exceeded 0 flag clear            */
            __OM uint32_t CLROC0FH1 : 1; /*!< [5..5] Channel 1 overcurrent upper limit exceeded 0 flag clear            */
            __OM uint32_t CLROC0FH0 : 1; /*!< [4..4] Channel 0 overcurrent upper limit exceeded 0 flag clear            */
            uint32_t                : 1;
            __OM uint32_t CLROC0FL2 : 1; /*!< [2..2] Channel 2 overcurrent lower limit detection 0 flag clear           */
            __OM uint32_t CLROC0FL1 : 1; /*!< [1..1] Channel 1 overcurrent lower limit detection 0 flag clear           */
            __OM uint32_t CLROC0FL0 : 1; /*!< [0..0] Channel 0 overcurrent lower limit detection 0 flag clear           */
#else
            __OM uint32_t CLROC0FL0 : 1; /*!< [0..0] Channel 0 overcurrent lower limit detection 0 flag clear           */
            __OM uint32_t CLROC0FL1 : 1; /*!< [1..1] Channel 1 overcurrent lower limit detection 0 flag clear           */
            __OM uint32_t CLROC0FL2 : 1; /*!< [2..2] Channel 2 overcurrent lower limit detection 0 flag clear           */
            uint32_t                : 1;
            __OM uint32_t CLROC0FH0 : 1; /*!< [4..4] Channel 0 overcurrent upper limit exceeded 0 flag clear            */
            __OM uint32_t CLROC0FH1 : 1; /*!< [5..5] Channel 1 overcurrent upper limit exceeded 0 flag clear            */
            __OM uint32_t CLROC0FH2 : 1; /*!< [6..6] Channel 2 overcurrent upper limit exceeded 0 flag clear            */
            uint32_t                : 1;
            __OM uint32_t CLROC1FL0 : 1; /*!< [8..8] Channel 0 overcurrent lower limit detection 1 flag clear           */
            __OM uint32_t CLROC1FL1 : 1; /*!< [9..9] Channel 1 overcurrent lower limit detection 1 flag clear           */
            __OM uint32_t CLROC1FL2 : 1; /*!< [10..10] Channel 2 overcurrent lower limit detection 1 flag
                                          *   clear                                                                     */
            uint32_t                : 1;
            __OM uint32_t CLROC1FH0 : 1; /*!< [12..12] Channel 0 overcurrent upper limit exceeded 1 flag clear          */
            __OM uint32_t CLROC1FH1 : 1; /*!< [13..13] Channel 1 overcurrent upper limit exceeded 1 flag clear          */
            __OM uint32_t CLROC1FH2 : 1; /*!< [14..14] Channel 2 overcurrent upper limit exceeded 1 flag clear          */
            uint32_t                : 1;
            __OM uint32_t CLROC2FL0 : 1; /*!< [16..16] Channel 0 overcurrent lower limit detection 2 flag
                                          *   clear                                                                     */
            __OM uint32_t CLROC2FL1 : 1; /*!< [17..17] Channel 1 overcurrent lower limit detection 2 flag
                                          *   clear                                                                     */
            __OM uint32_t CLROC2FL2 : 1; /*!< [18..18] Channel 2 overcurrent lower limit detection 2 flag
                                          *   clear                                                                     */
            uint32_t                : 1;
            __OM uint32_t CLROC2FH0 : 1; /*!< [20..20] Channel 0 overcurrent upper limit exceeded 2 flag clear          */
            __OM uint32_t CLROC2FH1 : 1; /*!< [21..21] Channel 1 overcurrent upper limit exceeded 2 flag clear          */
            __OM uint32_t CLROC2FH2 : 1; /*!< [22..22] Channel 2 overcurrent upper limit exceeded 2 flag clear          */
            uint32_t                : 9;
#endif
        } DSCOCESCR_b;
    };

    union
    {
        __OM uint32_t DSCOCNSCR;       /*!< (@ 0x00000268) Channel Overcurrent Notification Status Clear
                                        *                  register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 17;
            __OM uint32_t CLROWD3N2 : 1; /*!< [14..14] Channel 2 overcurrent detection window notification
                                          *   3 flag clear                                                              */
            __OM uint32_t CLROWD3N1 : 1; /*!< [13..13] Channel 1 overcurrent detection window notification
                                          *   3 flag clear                                                              */
            __OM uint32_t CLROWD3N0 : 1; /*!< [12..12] Channel 0 overcurrent detection window notification
                                          *   3 flag clear                                                              */
            uint32_t                : 1;
            __OM uint32_t CLROWD2N2 : 1; /*!< [10..10] Channel 2 overcurrent detection window notification
                                          *   2 flag clear                                                              */
            __OM uint32_t CLROWD2N1 : 1; /*!< [9..9] Channel 1 overcurrent detection window notification 2
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD2N0 : 1; /*!< [8..8] Channel 0 overcurrent detection window notification 2
                                          *   flag clear                                                                */
            uint32_t                : 1;
            __OM uint32_t CLROWD1N2 : 1; /*!< [6..6] Channel 2 overcurrent detection window notification 1
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD1N1 : 1; /*!< [5..5] Channel 1 overcurrent detection window notification 1
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD1N0 : 1; /*!< [4..4] Channel 0 overcurrent detection window notification 1
                                          *   flag clear                                                                */
            uint32_t                : 1;
            __OM uint32_t CLROWD0N2 : 1; /*!< [2..2] Channel 2 overcurrent detection window notification 0
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD0N1 : 1; /*!< [1..1] Channel 1 overcurrent detection window notification 0
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD0N0 : 1; /*!< [0..0] Channel 0 overcurrent detection window notification 0
                                          *   flag clear                                                                */
#else
            __OM uint32_t CLROWD0N0 : 1; /*!< [0..0] Channel 0 overcurrent detection window notification 0
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD0N1 : 1; /*!< [1..1] Channel 1 overcurrent detection window notification 0
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD0N2 : 1; /*!< [2..2] Channel 2 overcurrent detection window notification 0
                                          *   flag clear                                                                */
            uint32_t                : 1;
            __OM uint32_t CLROWD1N0 : 1; /*!< [4..4] Channel 0 overcurrent detection window notification 1
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD1N1 : 1; /*!< [5..5] Channel 1 overcurrent detection window notification 1
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD1N2 : 1; /*!< [6..6] Channel 2 overcurrent detection window notification 1
                                          *   flag clear                                                                */
            uint32_t                : 1;
            __OM uint32_t CLROWD2N0 : 1; /*!< [8..8] Channel 0 overcurrent detection window notification 2
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD2N1 : 1; /*!< [9..9] Channel 1 overcurrent detection window notification 2
                                          *   flag clear                                                                */
            __OM uint32_t CLROWD2N2 : 1; /*!< [10..10] Channel 2 overcurrent detection window notification
                                          *   2 flag clear                                                              */
            uint32_t                : 1;
            __OM uint32_t CLROWD3N0 : 1; /*!< [12..12] Channel 0 overcurrent detection window notification
                                          *   3 flag clear                                                              */
            __OM uint32_t CLROWD3N1 : 1; /*!< [13..13] Channel 1 overcurrent detection window notification
                                          *   3 flag clear                                                              */
            __OM uint32_t CLROWD3N2 : 1; /*!< [14..14] Channel 2 overcurrent detection window notification
                                          *   3 flag clear                                                              */
            uint32_t : 17;
#endif
        } DSCOCNSCR_b;
    };
    __IM uint32_t RESERVED7[5];

    union
    {
        __OM uint32_t DSCSCR;          /*!< (@ 0x00000280) Channel Status Clear register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 21;
            __OM uint32_t CLRCBUF2 : 1; /*!< [10..10] Channel 2 Capture data B update flag clear                       */
            __OM uint32_t CLRCBUF1 : 1; /*!< [9..9] Channel 1 Capture data B update flag clear                         */
            __OM uint32_t CLRCBUF0 : 1; /*!< [8..8] Channel 0 Capture data B update flag clear                         */
            uint32_t               : 1;
            __OM uint32_t CLRCAUF2 : 1; /*!< [6..6] Channel 2 Capture data A update flag clear                         */
            __OM uint32_t CLRCAUF1 : 1; /*!< [5..5] Channel 1 Capture data A update flag clear                         */
            __OM uint32_t CLRCAUF0 : 1; /*!< [4..4] Channel 0 Capture data A update flag clear                         */
            uint32_t               : 1;
            __OM uint32_t CLRDUF2  : 1; /*!< [2..2] Channel 2 data update flag clear                                   */
            __OM uint32_t CLRDUF1  : 1; /*!< [1..1] Channel 1 data update flag clear                                   */
            __OM uint32_t CLRDUF0  : 1; /*!< [0..0] Channel 0 data update flag clear                                   */
#else
            __OM uint32_t CLRDUF0  : 1; /*!< [0..0] Channel 0 data update flag clear                                   */
            __OM uint32_t CLRDUF1  : 1; /*!< [1..1] Channel 1 data update flag clear                                   */
            __OM uint32_t CLRDUF2  : 1; /*!< [2..2] Channel 2 data update flag clear                                   */
            uint32_t               : 1;
            __OM uint32_t CLRCAUF0 : 1; /*!< [4..4] Channel 0 Capture data A update flag clear                         */
            __OM uint32_t CLRCAUF1 : 1; /*!< [5..5] Channel 1 Capture data A update flag clear                         */
            __OM uint32_t CLRCAUF2 : 1; /*!< [6..6] Channel 2 Capture data A update flag clear                         */
            uint32_t               : 1;
            __OM uint32_t CLRCBUF0 : 1; /*!< [8..8] Channel 0 Capture data B update flag clear                         */
            __OM uint32_t CLRCBUF1 : 1; /*!< [9..9] Channel 1 Capture data B update flag clear                         */
            __OM uint32_t CLRCBUF2 : 1; /*!< [10..10] Channel 2 Capture data B update flag clear                       */
            uint32_t               : 21;
#endif
        } DSCSCR_b;
    };
    __IM uint32_t          RESERVED8[31];
    __IOM R_DSMIF0_CH_Type CH[3];      /*!< (@ 0x00000300) DSMIF Channel Control Registers                             */
} R_DSMIF0_Type;                       /*!< Size = 1716 (0x6b4)                                                       */

#endif /* R_DSMIF_REG_H */
