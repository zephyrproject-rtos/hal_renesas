/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SSI_REG_H
#define R_SSI_REG_H

/* =========================================================================================================================== */
/* ================                                          R_SSI0                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Serial Sound Interface 0 (R_SSI0)
 */

typedef struct                         /*!< (@ 0x8785D000) R_SSI0 Structure                                           */
{
    union
    {
        __IOM uint32_t SSICR;          /*!< (@ 0x00000000) Control Register                                           */

        struct
        {
            __IOM uint32_t REN   : 1;  /*!< [0..0] Reception Enable                                                   */
            __IOM uint32_t TEN   : 1;  /*!< [1..1] Transmission Enable                                                */
            uint32_t             : 1;
            __IOM uint32_t MUEN  : 1;  /*!< [3..3] Mute                                                               */
            __IOM uint32_t CKDV  : 4;  /*!< [7..4] Bit Clock Division Ratio Select                                    */
            __IOM uint32_t DEL   : 1;  /*!< [8..8] Serial Data Delay Select                                           */
            __IOM uint32_t PDTA  : 1;  /*!< [9..9] Data Alignment Select                                              */
            __IOM uint32_t SDTA  : 1;  /*!< [10..10] Serial Data Alignment Select                                     */
            __IOM uint32_t SPDP  : 1;  /*!< [11..11] Padding Data Select                                              */
            __IOM uint32_t LRCKP : 1;  /*!< [12..12] LR Clock Polarity Select                                         */
            __IOM uint32_t BCKP  : 1;  /*!< [13..13] Bit Clock Polarity Select                                        */
            __IOM uint32_t MST   : 1;  /*!< [14..14] Master Mode                                                      */
            uint32_t             : 1;
            __IOM uint32_t SWL   : 3;  /*!< [18..16] System Word Length Select                                        */
            __IOM uint32_t DWL   : 3;  /*!< [21..19] Data Word Length Select                                          */
            __IOM uint32_t FRM   : 2;  /*!< [23..22] Frame Word Length Select                                         */
            uint32_t             : 1;
            __IOM uint32_t IIEN  : 1;  /*!< [25..25] Idle Mode Interrupt Enable                                       */
            __IOM uint32_t ROIEN : 1;  /*!< [26..26] Receive Overflow Interrupt Enable                                */
            __IOM uint32_t RUIEN : 1;  /*!< [27..27] Receive Underflow Interrupt Enable                               */
            __IOM uint32_t TOIEN : 1;  /*!< [28..28] Transmit Overflow Interrupt Enable                               */
            __IOM uint32_t TUIEN : 1;  /*!< [29..29] Transmit Underflow Interrupt Enable                              */
            __IOM uint32_t CKS   : 1;  /*!< [30..30] Master Mode Audio Clock Select                                   */
            uint32_t             : 1;
        } SSICR_b;
    };

    union
    {
        __IOM uint32_t SSISR;          /*!< (@ 0x00000004) Status Register                                            */

        struct
        {
            uint32_t             : 25;
            __IM uint32_t  IIRQ  : 1;  /*!< [25..25] Idle State Flag                                                  */
            __IOM uint32_t ROIRQ : 1;  /*!< [26..26] Receive Overflow Flag                                            */
            __IOM uint32_t RUIRQ : 1;  /*!< [27..27] Receive Underflow Flag                                           */
            __IOM uint32_t TOIRQ : 1;  /*!< [28..28] Transmit Overflow Flag                                           */
            __IOM uint32_t TUIRQ : 1;  /*!< [29..29] Transmit Underflow Flag                                          */
            uint32_t             : 2;
        } SSISR_b;
    };
    __IM uint32_t RESERVED[2];

    union
    {
        __IOM uint32_t SSIFCR;         /*!< (@ 0x00000010) FIFO Control Register                                      */

        struct
        {
            __IOM uint32_t RFRST  : 1; /*!< [0..0] Receive FIFO Reset                                                 */
            __IOM uint32_t TFRST  : 1; /*!< [1..1] Transmit FIFO Reset                                                */
            __IOM uint32_t RIE    : 1; /*!< [2..2] Receive Data Full Interrupt Enable                                 */
            __IOM uint32_t TIE    : 1; /*!< [3..3] Transmit Data Empty Interrupt Enable                               */
            uint32_t              : 7;
            __IOM uint32_t BSW    : 1; /*!< [11..11] Byte Swap                                                        */
            uint32_t              : 4;
            __IOM uint32_t SSIRST : 1; /*!< [16..16] Software Reset                                                   */
            uint32_t              : 14;
            __IOM uint32_t AUCKE  : 1; /*!< [31..31] MCK Supply Enable                                                */
        } SSIFCR_b;
    };

    union
    {
        __IOM uint32_t SSIFSR;         /*!< (@ 0x00000014) FIFO Status Register                                       */

        struct
        {
            __IOM uint32_t RDF : 1;    /*!< [0..0] Receive Data Full Flag                                             */
            uint32_t           : 7;
            __IM uint32_t RDC  : 6;    /*!< [13..8] Receive FIFO Data Count                                           */
            uint32_t           : 2;
            __IOM uint32_t TDE : 1;    /*!< [16..16] Transmit Data Empty Flag                                         */
            uint32_t           : 7;
            __IM uint32_t TDC  : 6;    /*!< [29..24] Transmit FIFO Data Count                                         */
            uint32_t           : 2;
        } SSIFSR_b;
    };

    union
    {
        __OM uint32_t SSIFTDR;         /*!< (@ 0x00000018) Transmit FIFO Data Register                                */
        __OM uint16_t SSIFTDR16;       /*!< (@ 0x00000018) Transmit FIFO Data Register                                */
        __OM uint8_t  SSIFTDR8;        /*!< (@ 0x00000018) Transmit FIFO Data Register                                */
    };

    union
    {
        __IM uint32_t SSIFRDR;         /*!< (@ 0x0000001C) Receive FIFO Data Register                                 */
        __IM uint16_t SSIFRDR16;       /*!< (@ 0x0000001C) Receive FIFO Data Register                                 */
        __IM uint8_t  SSIFRDR8;        /*!< (@ 0x0000001C) Receive FIFO Data Register                                 */
    };

    union
    {
        __IOM uint32_t SSIOFR;          /*!< (@ 0x00000020) Audio Format Register                                      */

        struct
        {
            __IOM uint32_t OMOD    : 2; /*!< [1..0] Data Format Select                                                 */
            uint32_t               : 6;
            __IOM uint32_t LRCONT  : 1; /*!< [8..8] LRCK Continuous Output Enable                                      */
            __IOM uint32_t BCKASTP : 1; /*!< [9..9] BCK Continuous Output Disable                                      */
            uint32_t               : 22;
        } SSIOFR_b;
    };

    union
    {
        __IOM uint32_t SSISCR;         /*!< (@ 0x00000024) FIFO Status Control Register                               */

        struct
        {
            __IOM uint32_t RDFS : 5;   /*!< [4..0] Receive Data Full Condition Setting Specifies the condition
                                        *   for setting the RDF flag to 1.                                            */
            uint32_t            : 3;
            __IOM uint32_t TDES : 5;   /*!< [12..8] Transmit Data Empty Condition Setting Specifies the
                                        *   condition for setting the TDE flag to 1.                                  */
            uint32_t : 19;
        } SSISCR_b;
    };
} R_SSI0_Type;                         /*!< Size = 40 (0x28)                                                          */

#endif /* R_SSI_REG_H */
