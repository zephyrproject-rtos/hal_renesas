/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_EXDMAC_REG_H
#define R_EXDMAC_REG_H

/* =========================================================================================================================== */
/* ================                                         R_EXDMAC0                                         ================ */
/* =========================================================================================================================== */

/**
 * @brief EXDMA Controller 0 (R_EXDMAC0)
 */

typedef struct                         /*!< (@ 0x8701A000) R_EXDMAC0 Structure                                        */
{
    __IOM uint32_t EDMSAR;             /*!< (@ 0x00000000) EXDMA Source Address Register                              */
    __IOM uint32_t EDMDAR;             /*!< (@ 0x00000004) EXDMA Destination Address Register                         */

    union
    {
        __IOM uint32_t EDMCRA;         /*!< (@ 0x00000008) EXDMA Transfer Count Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 6;
            __IOM uint32_t EDMCRAH : 10; /*!< [25..16] Upper bits of transfer count                                     */
            __IOM uint32_t EDMCRAL : 16; /*!< [15..0] Lower bits of transfer count                                      */
#else
            __IOM uint32_t EDMCRAL : 16; /*!< [15..0] Lower bits of transfer count                                      */
            __IOM uint32_t EDMCRAH : 10; /*!< [25..16] Upper bits of transfer count                                     */
            uint32_t               : 6;
#endif
        } EDMCRA_b;
    };

    union
    {
        __IOM uint32_t EDMCRB;         /*!< (@ 0x0000000C) EXDMA Block Transfer Count Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EDMCRBH : 16; /*!< [31..16] Specifies the number of blocks, repeat or repeat-block
                                          *   transfer operations.                                                      */
            __IOM uint32_t EDMCRBL : 16; /*!< [15..0] Functions as the number of blocks, repeat or repeat-block
                                          *   transfer counter.                                                         */
#else
            __IOM uint32_t EDMCRBL : 16; /*!< [15..0] Functions as the number of blocks, repeat or repeat-block
                                          *   transfer counter.                                                         */
            __IOM uint32_t EDMCRBH : 16; /*!< [31..16] Specifies the number of blocks, repeat or repeat-block
                                          *   transfer operations.                                                      */
#endif
        } EDMCRB_b;
    };

    union
    {
        __IOM uint16_t EDMTMD;         /*!< (@ 0x00000010) EXDMA Transfer Mode Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t MD   : 2;   /*!< [15..14] Transfer Mode Select                                             */
            __IOM uint16_t DTS  : 2;   /*!< [13..12] Repeat Area Select                                               */
            uint16_t            : 1;
            __IOM uint16_t TKP  : 1;   /*!< [10..10] Transfer Keeping                                                 */
            __IOM uint16_t SZ   : 2;   /*!< [9..8] Transfer Data Size Select                                          */
            uint16_t            : 6;
            __IOM uint16_t DCTG : 2;   /*!< [1..0] Transfer Request Source Select                                     */
#else
            __IOM uint16_t DCTG : 2;   /*!< [1..0] Transfer Request Source Select                                     */
            uint16_t            : 6;
            __IOM uint16_t SZ   : 2;   /*!< [9..8] Transfer Data Size Select                                          */
            __IOM uint16_t TKP  : 1;   /*!< [10..10] Transfer Keeping                                                 */
            uint16_t            : 1;
            __IOM uint16_t DTS  : 2;   /*!< [13..12] Repeat Area Select                                               */
            __IOM uint16_t MD   : 2;   /*!< [15..14] Transfer Mode Select                                             */
#endif
        } EDMTMD_b;
    };
    __IM uint8_t RESERVED;

    union
    {
        __IOM uint8_t EDMINT;          /*!< (@ 0x00000013) EXDMA Interrupt Setting Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 3;
            __IOM uint8_t DTIE  : 1;   /*!< [4..4] Transfer End Interrupt Enable                                      */
            __IOM uint8_t ESIE  : 1;   /*!< [3..3] Transfer Escape End Interrupt Enable                               */
            __IOM uint8_t RPTIE : 1;   /*!< [2..2] Repeat Size End Interrupt Enable                                   */
            __IOM uint8_t SARIE : 1;   /*!< [1..1] Source Address Extended Repeat Area Overflow Interrupt
                                        *   Enable                                                                    */
            __IOM uint8_t DARIE : 1;   /*!< [0..0] Destination Address Extended Repeat Area Overflow Interrupt
                                        *   Enable                                                                    */
#else
            __IOM uint8_t DARIE : 1;   /*!< [0..0] Destination Address Extended Repeat Area Overflow Interrupt
                                        *   Enable                                                                    */
            __IOM uint8_t SARIE : 1;   /*!< [1..1] Source Address Extended Repeat Area Overflow Interrupt
                                        *   Enable                                                                    */
            __IOM uint8_t RPTIE : 1;   /*!< [2..2] Repeat Size End Interrupt Enable                                   */
            __IOM uint8_t ESIE  : 1;   /*!< [3..3] Transfer Escape End Interrupt Enable                               */
            __IOM uint8_t DTIE  : 1;   /*!< [4..4] Transfer End Interrupt Enable                                      */
            uint8_t             : 3;
#endif
        } EDMINT_b;
    };

    union
    {
        __IOM uint16_t EDMAMD;         /*!< (@ 0x00000014) EXDMA Address Mode Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t SM   : 2;   /*!< [15..14] Source Address Update Mode                                       */
            __IOM uint16_t SADR : 1;   /*!< [13..13] Source Address Update Select After Reload                        */
            __IOM uint16_t SARA : 5;   /*!< [12..8] Source Address Extended Repeat Area Specifies the extended
                                        *   repeat area on the source address.                                        */
            __IOM uint16_t DM   : 2;   /*!< [7..6] Destination Address Update Mode                                    */
            __IOM uint16_t DADR : 1;   /*!< [5..5] Destination Address Update Select After Reload                     */
            __IOM uint16_t DARA : 5;   /*!< [4..0] Destination Address Extended Repeat Area Specifies the
                                        *   extended repeat area on the destination address.                          */
#else
            __IOM uint16_t DARA : 5;   /*!< [4..0] Destination Address Extended Repeat Area Specifies the
                                        *   extended repeat area on the destination address.                          */
            __IOM uint16_t DADR : 1;   /*!< [5..5] Destination Address Update Select After Reload                     */
            __IOM uint16_t DM   : 2;   /*!< [7..6] Destination Address Update Mode                                    */
            __IOM uint16_t SARA : 5;   /*!< [12..8] Source Address Extended Repeat Area Specifies the extended
                                        *   repeat area on the source address.                                        */
            __IOM uint16_t SADR : 1;   /*!< [13..13] Source Address Update Select After Reload                        */
            __IOM uint16_t SM   : 2;   /*!< [15..14] Source Address Update Mode                                       */
#endif
        } EDMAMD_b;
    };
    __IM uint16_t  RESERVED1;
    __IOM uint32_t EDMOFR;             /*!< (@ 0x00000018) EXDMA Offset Register                                      */

    union
    {
        __IOM uint8_t EDMCNT;          /*!< (@ 0x0000001C) EXDMA Transfer Enable Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 7;
            __IOM uint8_t DTE : 1;     /*!< [0..0] DMA Transfer Enable                                                */
#else
            __IOM uint8_t DTE : 1;     /*!< [0..0] DMA Transfer Enable                                                */
            uint8_t           : 7;
#endif
        } EDMCNT_b;
    };

    union
    {
        __IOM uint8_t EDMREQ;          /*!< (@ 0x0000001D) EXDMA Software Start Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 3;
            __IOM uint8_t CLRS  : 1;   /*!< [4..4] DMA Software Start Bit Auto Clear Select                           */
            uint8_t             : 3;
            __IOM uint8_t SWREQ : 1;   /*!< [0..0] DMA Software Start                                                 */
#else
            __IOM uint8_t SWREQ : 1;   /*!< [0..0] DMA Software Start                                                 */
            uint8_t             : 3;
            __IOM uint8_t CLRS  : 1;   /*!< [4..4] DMA Software Start Bit Auto Clear Select                           */
            uint8_t             : 3;
#endif
        } EDMREQ_b;
    };

    union
    {
        __IOM uint8_t EDMSTS;          /*!< (@ 0x0000001E) EXDMA Status Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t ACT   : 1;    /*!< [7..7] DMA Active Flag                                                    */
            uint8_t            : 2;
            __IOM uint8_t DTIF : 1;    /*!< [4..4] Transfer End Interrupt Flag                                        */
            uint8_t            : 3;
            __IOM uint8_t ESIF : 1;    /*!< [0..0] Transfer Escape End Interrupt Flag                                 */
#else
            __IOM uint8_t ESIF : 1;    /*!< [0..0] Transfer Escape End Interrupt Flag                                 */
            uint8_t            : 3;
            __IOM uint8_t DTIF : 1;    /*!< [4..4] Transfer End Interrupt Flag                                        */
            uint8_t            : 2;
            __IM uint8_t ACT   : 1;    /*!< [7..7] DMA Active Flag                                                    */
#endif
        } EDMSTS_b;
    };
    __IM uint8_t   RESERVED2;
    __IOM uint32_t EDMSRR;             /*!< (@ 0x00000020) EXDMA Source Reload Address Register                       */
    __IOM uint32_t EDMDRR;             /*!< (@ 0x00000024) EXDMA Destination Reload Address Register                  */

    union
    {
        __IOM uint32_t EDMSBS;         /*!< (@ 0x00000028) EXDMA Source Buffer Size Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EDMSBSH : 16; /*!< [31..16] Specifies the repeat-area size in repeat block transfer
                                          *   mode.                                                                     */
            __IOM uint32_t EDMSBSL : 16; /*!< [15..0] Functions as data transfer counter in repeat block transfer
                                          *   mode.                                                                     */
#else
            __IOM uint32_t EDMSBSL : 16; /*!< [15..0] Functions as data transfer counter in repeat block transfer
                                          *   mode.                                                                     */
            __IOM uint32_t EDMSBSH : 16; /*!< [31..16] Specifies the repeat-area size in repeat block transfer
                                          *   mode.                                                                     */
#endif
        } EDMSBS_b;
    };

    union
    {
        __IOM uint32_t EDMDBS;         /*!< (@ 0x0000002C) EXDMA Source Buffer Size Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t EDMDBSH : 16; /*!< [31..16] Specifies the repeat-area size in repeat block transfer
                                          *   mode.                                                                     */
            __IOM uint32_t EDMDBSL : 16; /*!< [15..0] Functions as data transfer counter in repeat block transfer
                                          *   mode.                                                                     */
#else
            __IOM uint32_t EDMDBSL : 16; /*!< [15..0] Functions as data transfer counter in repeat block transfer
                                          *   mode.                                                                     */
            __IOM uint32_t EDMDBSH : 16; /*!< [31..16] Specifies the repeat-area size in repeat block transfer
                                          *   mode.                                                                     */
#endif
        } EDMDBS_b;
    };

    union
    {
        __IOM uint8_t EDMBWR;          /*!< (@ 0x00000030) EXDMA Bufferable Write Enable Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 7;
            __IOM uint8_t BWE : 1;     /*!< [0..0] Bufferable Write Enable                                            */
#else
            __IOM uint8_t BWE : 1;     /*!< [0..0] Bufferable Write Enable                                            */
            uint8_t           : 7;
#endif
        } EDMBWR_b;
    };
    __IM uint8_t  RESERVED3;
    __IM uint16_t RESERVED4;
    __IM uint32_t RESERVED5[2];
    __IM uint16_t RESERVED6;

    union
    {
        __IOM uint8_t EDMPRF;          /*!< (@ 0x0000003E) EXDMAC Peripheral Request Flag Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t PREQ : 1;    /*!< [0..0] Periphearal Module Request Flag                                    */
#else
            __IOM uint8_t PREQ : 1;    /*!< [0..0] Periphearal Module Request Flag                                    */
            uint8_t            : 7;
#endif
        } EDMPRF_b;
    };
    __IM uint8_t RESERVED7;
} R_EXDMAC0_Type;                      /*!< Size = 64 (0x40)                                                          */

#endif /* R_EXDMAC_REG_H */
