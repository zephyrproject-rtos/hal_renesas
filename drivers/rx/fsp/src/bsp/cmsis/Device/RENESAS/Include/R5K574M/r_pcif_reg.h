/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_PCIF_REG_H
#define R_PCIF_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_PCIF0                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Phase Counting Interface 0 (R_PCIF0)
 */

typedef struct                         /*!< (@ 0x87827000) R_PCIF0 Structure                                          */
{
    union
    {
        __IOM uint32_t CLKER;          /*!< (@ 0x00000000) PCIF Clock Enable Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 31;
            __IOM uint32_t CLKEN : 1;  /*!< [0..0] Division clock enable                                              */
#else
            __IOM uint32_t CLKEN : 1;  /*!< [0..0] Division clock enable                                              */
            uint32_t             : 31;
#endif
        } CLKER_b;
    };

    union
    {
        __IM uint32_t CLKSR;           /*!< (@ 0x00000004) PCIF Clock Status Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __IM uint32_t CLKS : 1;    /*!< [0..0] Division clock status                                              */
#else
            __IM uint32_t CLKS : 1;    /*!< [0..0] Division clock status                                              */
            uint32_t           : 31;
#endif
        } CLKSR_b;
    };

    union
    {
        __IOM uint32_t CLKCR;          /*!< (@ 0x00000008) PCIF Clock Control Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 19;
            __IOM uint32_t DIVR   : 5; /*!< [12..8] Division clock ratio select                                       */
            uint32_t              : 7;
            __IOM uint32_t CLKSEL : 1; /*!< [0..0] CCLK clock source select                                           */
#else
            __IOM uint32_t CLKSEL : 1; /*!< [0..0] CCLK clock source select                                           */
            uint32_t              : 7;
            __IOM uint32_t DIVR   : 5; /*!< [12..8] Division clock ratio select                                       */
            uint32_t              : 19;
#endif
        } CLKCR_b;
    };

    union
    {
        __IOM uint32_t CTLR;           /*!< (@ 0x0000000C) PCIF Control Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 21;
            __IOM uint32_t ZPOL   : 1; /*!< [10..10] Z-phase polarity select                                          */
            __IOM uint32_t BPOL   : 1; /*!< [9..9] B-phase polarity select                                            */
            __IOM uint32_t APOL   : 1; /*!< [8..8] A-phase polarity select                                            */
            uint32_t              : 7;
            __IOM uint32_t PCIFMD : 1; /*!< [0..0] PCIF mode select                                                   */
#else
            __IOM uint32_t PCIFMD : 1; /*!< [0..0] PCIF mode select                                                   */
            uint32_t              : 7;
            __IOM uint32_t APOL   : 1; /*!< [8..8] A-phase polarity select                                            */
            __IOM uint32_t BPOL   : 1; /*!< [9..9] B-phase polarity select                                            */
            __IOM uint32_t ZPOL   : 1; /*!< [10..10] Z-phase polarity select                                          */
            uint32_t              : 21;
#endif
        } CTLR_b;
    };

    union
    {
        __IOM uint32_t POSMAXR;        /*!< (@ 0x00000010) PCIF Position Maximum number setting Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t POSMAX : 16; /*!< [15..0] Position maximum number setting                                   */
#else
            __IOM uint32_t POSMAX : 16; /*!< [15..0] Position maximum number setting                                   */
            uint32_t              : 16;
#endif
        } POSMAXR_b;
    };

    union
    {
        __IOM uint32_t TRGR;           /*!< (@ 0x00000014) PCIF start/stop Trigger Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 7;
            __IOM uint32_t PHCSTPT  : 1; /*!< [24..24] Phase counting mode stop trigger                                 */
            uint32_t                : 7;
            __IOM uint32_t PCIFSTPT : 1; /*!< [16..16] PCIF stop trigger                                                */
            uint32_t                : 15;
            __IOM uint32_t PCIFSTRT : 1; /*!< [0..0] PCIF start trigger                                                 */
#else
            __IOM uint32_t PCIFSTRT : 1; /*!< [0..0] PCIF start trigger                                                 */
            uint32_t                : 15;
            __IOM uint32_t PCIFSTPT : 1; /*!< [16..16] PCIF stop trigger                                                */
            uint32_t                : 7;
            __IOM uint32_t PHCSTPT  : 1; /*!< [24..24] Phase counting mode stop trigger                                 */
            uint32_t                : 7;
#endif
        } TRGR_b;
    };

    union
    {
        __IM uint32_t SR;              /*!< (@ 0x00000018) PCIF Status Register                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 31;
            __IM uint32_t PCIFPS : 1;  /*!< [0..0] PCIF processing status                                             */
#else
            __IM uint32_t PCIFPS : 1;  /*!< [0..0] PCIF processing status                                             */
            uint32_t             : 31;
#endif
        } SR_b;
    };
    __IM uint32_t RESERVED;

    union
    {
        __IOM uint32_t PHCCTLR;        /*!< (@ 0x00000020) PCIF Phase Counting mode Control Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 7;
            __IOM uint32_t PHCECACMD : 1; /*!< [24..24] Phase counting mode edge count number auto-clear mode
                                           *   select                                                                    */
            uint32_t                 : 7;
            __IOM uint32_t PHCCEDAMD : 1; /*!< [16..16] Phase counting mode carrier period event difference
                                           *   adjustment mode select                                                    */
            uint32_t              : 12;
            __IOM uint32_t PHCZOS : 1;    /*!< [3..3] Phase counting mode Z-phase output to synchronize phase
                                           *   select                                                                    */
            __IOM uint32_t PHCZW : 3;     /*!< [2..0] Phase counting mode Z-phase width select                           */
#else
            __IOM uint32_t PHCZW  : 3;    /*!< [2..0] Phase counting mode Z-phase width select                           */
            __IOM uint32_t PHCZOS : 1;    /*!< [3..3] Phase counting mode Z-phase output to synchronize phase
                                           *   select                                                                    */
            uint32_t                 : 12;
            __IOM uint32_t PHCCEDAMD : 1; /*!< [16..16] Phase counting mode carrier period event difference
                                           *   adjustment mode select                                                    */
            uint32_t                 : 7;
            __IOM uint32_t PHCECACMD : 1; /*!< [24..24] Phase counting mode edge count number auto-clear mode
                                           *   select                                                                    */
            uint32_t : 7;
#endif
        } PHCCTLR_b;
    };

    union
    {
        __IOM uint32_t PHCCEDTHR;      /*!< (@ 0x00000024) PCIF Phase Counting mode Carrier period Event
                                        *                  Difference Threshold select Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 16;
            __IOM uint32_t PHCCEDTH : 16; /*!< [15..0] Phase counting mode carrier period event difference
                                           *   threshold                                                                 */
#else
            __IOM uint32_t PHCCEDTH : 16; /*!< [15..0] Phase counting mode carrier period event difference
                                           *   threshold                                                                 */
            uint32_t : 16;
#endif
        } PHCCEDTHR_b;
    };

    union
    {
        __IOM uint32_t PHCPERIODR;     /*!< (@ 0x00000028) PCIF Phase Counting mode carrier Period setting
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 16;
            __IOM uint32_t PHCPERIOD : 16; /*!< [15..0] Phase counting mode carrier period setting                        */
#else
            __IOM uint32_t PHCPERIOD : 16; /*!< [15..0] Phase counting mode carrier period setting                        */
            uint32_t                 : 16;
#endif
        } PHCPERIODR_b;
    };

    union
    {
        __IOM uint32_t PHCECR;         /*!< (@ 0x0000002C) PCIF Phase Counting mode Edge Count number setting
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 16;
            __IOM uint32_t PHCEDGCNT : 16; /*!< [15..0] Phase counting mode edge count number setting                     */
#else
            __IOM uint32_t PHCEDGCNT : 16; /*!< [15..0] Phase counting mode edge count number setting                     */
            uint32_t                 : 16;
#endif
        } PHCECR_b;
    };

    union
    {
        __IM uint32_t PHCPCMR;         /*!< (@ 0x00000030) PCIF Phase Counting mode Position Count number
                                        *                  Monitor Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 16;
            __IM uint32_t PHCPOSCNTM : 16; /*!< [15..0] Phase counting mode position count number monitor                 */
#else
            __IM uint32_t PHCPOSCNTM : 16; /*!< [15..0] Phase counting mode position count number monitor                 */
            uint32_t                 : 16;
#endif
        } PHCPCMR_b;
    };

    union
    {
        __IOM uint32_t PHCPCWDR;       /*!< (@ 0x00000034) PCIF Phase Counting mode Position Count number
                                        *                  Write Data Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                   : 16;
            __IOM uint32_t PHCPOSCNTWD : 16; /*!< [15..0] Phase counting mode position count number write data              */
#else
            __IOM uint32_t PHCPOSCNTWD : 16; /*!< [15..0] Phase counting mode position count number write data              */
            uint32_t                   : 16;
#endif
        } PHCPCWDR_b;
    };

    union
    {
        __IM uint32_t PHCSR;           /*!< (@ 0x00000038) PCIF Phase Counting mode Status Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 12;
            __IM uint32_t PHCOECUES : 1; /*!< [19..19] Phase counting mode old edge count number using error
                                          *   status                                                                    */
            __IM uint32_t PHCIECOES : 1; /*!< [18..18] Phase counting mode internal edge count number overflow
                                          *   error status                                                              */
            __IM uint32_t PHCIECES : 1;  /*!< [17..17] Phase counting mode internal edge count number error
                                          *   status                                                                    */
            __IM uint32_t PHCCEES : 1;   /*!< [16..16] Phase counting mode carrier period event error status            */
            uint32_t              : 6;
            __IM uint32_t PHCECUS : 1;   /*!< [9..9] Phase counting mode edge count number using capable status         */
            __IM uint32_t PHCPCUS : 1;   /*!< [8..8] Phase counting mode position count number using capable
                                          *   status                                                                    */
            uint32_t              : 7;
            __IM uint32_t PHCOENS : 1;   /*!< [0..0] Phase counting mode output edge number status                      */
#else
            __IM uint32_t PHCOENS : 1;   /*!< [0..0] Phase counting mode output edge number status                      */
            uint32_t              : 7;
            __IM uint32_t PHCPCUS : 1;   /*!< [8..8] Phase counting mode position count number using capable
                                          *   status                                                                    */
            __IM uint32_t PHCECUS  : 1;  /*!< [9..9] Phase counting mode edge count number using capable status         */
            uint32_t               : 6;
            __IM uint32_t PHCCEES  : 1;  /*!< [16..16] Phase counting mode carrier period event error status            */
            __IM uint32_t PHCIECES : 1;  /*!< [17..17] Phase counting mode internal edge count number error
                                          *   status                                                                    */
            __IM uint32_t PHCIECOES : 1; /*!< [18..18] Phase counting mode internal edge count number overflow
                                          *   error status                                                              */
            __IM uint32_t PHCOECUES : 1; /*!< [19..19] Phase counting mode old edge count number using error
                                          *   status                                                                    */
            uint32_t : 12;
#endif
        } PHCSR_b;
    };

    union
    {
        __IOM uint32_t PHCSCR;         /*!< (@ 0x0000003C) PCIF Phase Counting mode Status Clear Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                  : 12;
            __IOM uint32_t PHCOECUESC : 1; /*!< [19..19] Phase counting mode old edge count number using error
                                            *   status clear                                                              */
            __IOM uint32_t PHCIECOESC : 1; /*!< [18..18] Phase counting mode internal edge count number overflow
                                            *   error status clear                                                        */
            __IOM uint32_t PHCIECESC : 1;  /*!< [17..17] Phase counting mode internal edge count number error
                                            *   status clear                                                              */
            __IOM uint32_t PHCCEESC : 1;   /*!< [16..16] Phase counting mode carrier period event error status
                                            *   clear                                                                     */
            uint32_t : 16;
#else
            uint32_t                : 16;
            __IOM uint32_t PHCCEESC : 1;   /*!< [16..16] Phase counting mode carrier period event error status
                                            *   clear                                                                     */
            __IOM uint32_t PHCIECESC : 1;  /*!< [17..17] Phase counting mode internal edge count number error
                                            *   status clear                                                              */
            __IOM uint32_t PHCIECOESC : 1; /*!< [18..18] Phase counting mode internal edge count number overflow
                                            *   error status clear                                                        */
            __IOM uint32_t PHCOECUESC : 1; /*!< [19..19] Phase counting mode old edge count number using error
                                            *   status clear                                                              */
            uint32_t : 12;
#endif
        } PHCSCR_b;
    };

    union
    {
        __IOM uint32_t PHCSER;         /*!< (@ 0x00000040) PCIF Phase Counting mode Status Enable Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                  : 12;
            __IOM uint32_t PHCOECUESE : 1; /*!< [19..19] Phase counting mode old edge count number using error
                                            *   status enable                                                             */
            __IOM uint32_t PHCIECOESE : 1; /*!< [18..18] Phase counting mode internal edge count number overflow
                                            *   error status enable                                                       */
            __IOM uint32_t PHCIECESE : 1;  /*!< [17..17] Phase counting mode internal edge count number status
                                            *   error enable                                                              */
            __IOM uint32_t PHCCEESE : 1;   /*!< [16..16] Phase counting mode carrier period event error status
                                            *   enable                                                                    */
            uint32_t : 16;
#else
            uint32_t                : 16;
            __IOM uint32_t PHCCEESE : 1;   /*!< [16..16] Phase counting mode carrier period event error status
                                            *   enable                                                                    */
            __IOM uint32_t PHCIECESE : 1;  /*!< [17..17] Phase counting mode internal edge count number status
                                            *   error enable                                                              */
            __IOM uint32_t PHCIECOESE : 1; /*!< [18..18] Phase counting mode internal edge count number overflow
                                            *   error status enable                                                       */
            __IOM uint32_t PHCOECUESE : 1; /*!< [19..19] Phase counting mode old edge count number using error
                                            *   status enable                                                             */
            uint32_t : 12;
#endif
        } PHCSER_b;
    };
    __IM uint32_t RESERVED1[3];

    union
    {
        __IOM uint32_t INCCTLR;        /*!< (@ 0x00000050) PCIF Incremental mode Control Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 2;
            __IOM uint32_t INCRSL   : 6; /*!< [29..24] Incremental mode resolution ratio select                         */
            __IOM uint32_t INCZOMIN : 8; /*!< [23..16] Incremental mode Z-phase output minimum cycle set                */
            uint32_t                : 10;
            __IOM uint32_t INCZOS   : 2; /*!< [5..4] Incremental mode Z-phase output to synchronize phase
                                          *   select                                                                    */
            uint32_t              : 1;
            __IOM uint32_t INCOMD : 1;   /*!< [2..2] Incremental mode ABZ-phase output mode select                      */
            __IOM uint32_t INCIMD : 2;   /*!< [1..0] Incremental mode ABZ-phase input mode select                       */
#else
            __IOM uint32_t INCIMD : 2;   /*!< [1..0] Incremental mode ABZ-phase input mode select                       */
            __IOM uint32_t INCOMD : 1;   /*!< [2..2] Incremental mode ABZ-phase output mode select                      */
            uint32_t              : 1;
            __IOM uint32_t INCZOS : 2;   /*!< [5..4] Incremental mode Z-phase output to synchronize phase
                                          *   select                                                                    */
            uint32_t                : 10;
            __IOM uint32_t INCZOMIN : 8; /*!< [23..16] Incremental mode Z-phase output minimum cycle set                */
            __IOM uint32_t INCRSL   : 6; /*!< [29..24] Incremental mode resolution ratio select                         */
            uint32_t                : 2;
#endif
        } INCCTLR_b;
    };

    union
    {
        __IOM uint32_t INCZGCTLR;      /*!< (@ 0x00000054) PCIF Incremental mode Z-phase Generate Control
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 27;
            __IOM uint32_t INCSWZGE : 1; /*!< [4..4] Incremental mode software trigger Z generate enable                */
            __IOM uint32_t INCVIZGE : 1; /*!< [3..3] Incremental mode valley input Z generate enable                    */
            __IOM uint32_t INCPIZGE : 1; /*!< [2..2] Incremental mode peak input Z generate enable                      */
            __IOM uint32_t INCZIZGE : 1; /*!< [1..1] Incremental mode Z input Z generate enable                         */
            __IOM uint32_t INCZAGE  : 1; /*!< [0..0] Incremental mode Z-phase auto-generate enable                      */
#else
            __IOM uint32_t INCZAGE  : 1; /*!< [0..0] Incremental mode Z-phase auto-generate enable                      */
            __IOM uint32_t INCZIZGE : 1; /*!< [1..1] Incremental mode Z input Z generate enable                         */
            __IOM uint32_t INCPIZGE : 1; /*!< [2..2] Incremental mode peak input Z generate enable                      */
            __IOM uint32_t INCVIZGE : 1; /*!< [3..3] Incremental mode valley input Z generate enable                    */
            __IOM uint32_t INCSWZGE : 1; /*!< [4..4] Incremental mode software trigger Z generate enable                */
            uint32_t                : 27;
#endif
        } INCZGCTLR_b;
    };

    union
    {
        __IOM uint32_t INCPCCER;       /*!< (@ 0x00000058) PCIF Incremental mode Position Counter Clear
                                        *                  Enable Register                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 27;
            __IOM uint32_t INCSWCLRE : 1; /*!< [4..4] Incremental mode software trigger position counter clear
                                           *   enable                                                                    */
            __IOM uint32_t INCVICLRE : 1; /*!< [3..3] Incremental mode valley input position counter clear
                                           *   enable                                                                    */
            __IOM uint32_t INCPICLRE : 1; /*!< [2..2] Incremental mode peak input position counter clear enable          */
            __IOM uint32_t INCZICLRE : 1; /*!< [1..1] Incremental mode Z input position counter clear enable             */
            uint32_t                 : 1;
#else
            uint32_t                 : 1;
            __IOM uint32_t INCZICLRE : 1; /*!< [1..1] Incremental mode Z input position counter clear enable             */
            __IOM uint32_t INCPICLRE : 1; /*!< [2..2] Incremental mode peak input position counter clear enable          */
            __IOM uint32_t INCVICLRE : 1; /*!< [3..3] Incremental mode valley input position counter clear
                                           *   enable                                                                    */
            __IOM uint32_t INCSWCLRE : 1; /*!< [4..4] Incremental mode software trigger position counter clear
                                           *   enable                                                                    */
            uint32_t : 27;
#endif
        } INCPCCER_b;
    };

    union
    {
        __IOM uint32_t INCSWTRGR;      /*!< (@ 0x0000005C) PCIF Incremental mode Software Trigger Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 31;
            __IOM uint32_t INCSWT : 1; /*!< [0..0] Incremental mode software trigger                                  */
#else
            __IOM uint32_t INCSWT : 1; /*!< [0..0] Incremental mode software trigger                                  */
            uint32_t              : 31;
#endif
        } INCSWTRGR_b;
    };

    union
    {
        __IM uint32_t INCPCMR;         /*!< (@ 0x00000060) PCIF Incremental mode Position Counter Monitor
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t INCROTM  : 1;  /*!< [31..31] Incremental mode Rotation direction monitor                      */
            uint32_t               : 1;
            __IM uint32_t INCICNTM : 6;  /*!< [29..24] Incremental mode input position counter (pre-scaler)
                                          *   monitor                                                                   */
            uint32_t               : 8;
            __IM uint32_t INCOCNTM : 16; /*!< [15..0] Incremental mode output position counter monitor                  */
#else
            __IM uint32_t INCOCNTM : 16; /*!< [15..0] Incremental mode output position counter monitor                  */
            uint32_t               : 8;
            __IM uint32_t INCICNTM : 6;  /*!< [29..24] Incremental mode input position counter (pre-scaler)
                                          *   monitor                                                                   */
            uint32_t              : 1;
            __IM uint32_t INCROTM : 1;   /*!< [31..31] Incremental mode Rotation direction monitor                      */
#endif
        } INCPCMR_b;
    };
    __IM uint32_t RESERVED2[3];

    union
    {
        __IOM uint32_t SWRSTR;         /*!< (@ 0x00000070) PCIF Software Reset Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 31;
            __IOM uint32_t SWRST : 1;  /*!< [0..0] Software reset                                                     */
#else
            __IOM uint32_t SWRST : 1;  /*!< [0..0] Software reset                                                     */
            uint32_t             : 31;
#endif
        } SWRSTR_b;
    };
} R_PCIF0_Type;                        /*!< Size = 116 (0x74)                                                          */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif                                 /* R_PCIF_REG_H */
