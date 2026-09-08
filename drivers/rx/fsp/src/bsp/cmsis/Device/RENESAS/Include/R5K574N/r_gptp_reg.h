/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_GPTP_REG_H
#define R_GPTP_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_GPTP                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Generic PTP Timer (R_GPTP)
 */

typedef struct                         /*!< (@ 0x874E0000) R_GPTP Structure                                           */
{
    union
    {
        __IOM uint32_t PTPIPV;         /*!< (@ 0x00000000) IP Version Register (PTPIPV)                               */

        struct
        {
            __IOM uint32_t IPV : 32;   /*!< [31..0] IPV                                                               */
        } PTPIPV_b;
    };

    __IM uint32_t RESERVED[3];

    union
    {
        __IOM uint32_t PTPTMEC;        /*!< (@ 0x00000010) Timer Enable Configuration Register (PTPTMEC)              */

        struct
        {
            __IOM uint32_t TE0 : 1;    /*!< [0..0] TE0                                                                */
            __IOM uint32_t TE1 : 1;    /*!< [1..1] TE1                                                                */
            uint32_t           : 30;
        } PTPTMEC_b;
    };

    union
    {
        __IOM uint32_t PTPTMDC;        /*!< (@ 0x00000014) Timer Disable Configuration Register (PTPTMDC)             */

        struct
        {
            __IOM uint32_t TD0 : 1;    /*!< [0..0] TD0                                                                */
            __IOM uint32_t TD1 : 1;    /*!< [1..1] TD1                                                                */
            uint32_t           : 30;
        } PTPTMDC_b;
    };

    __IM uint32_t RESERVED1[2];

    union
    {
        __IOM uint32_t PTPTIVC0;       /*!< (@ 0x00000020) Timer Increment Value Configuration Register
                                        *                  t (PTPTIVCt) (t = 0, 1)                                    */

        struct
        {
            __IOM uint32_t TIV : 32;   /*!< [31..0] TIV                                                               */
        } PTPTIVC0_b;
    };

    __IM uint32_t RESERVED2[3];

    union
    {
        __IOM uint32_t PTPTOVC0L;      /*!< (@ 0x00000030) Timer Offset Value Configuration Register Lt
                                        *                  (PTPTOVCLt) (t = 0, 1)                                     */

        struct
        {
            __IOM uint32_t TOVPL : 30; /*!< [29..0] TOVPL                                                             */
            uint32_t             : 2;
        } PTPTOVC0L_b;
    };

    union
    {
        __IOM uint32_t PTPTOVC0M;      /*!< (@ 0x00000034) Timer Offset Value Configuration Register Mt
                                        *                  (PTPTOVCMt) (t = 0, 1)                                     */

        struct
        {
            __IOM uint32_t TOVPM : 32; /*!< [31..0] TOVPM                                                             */
        } PTPTOVC0M_b;
    };

    union
    {
        __IOM uint32_t PTPTOVC0U;      /*!< (@ 0x00000038) Timer Offset Value Configuration Register Ut
                                        *                  (PTPTOVCUt) (t = 0, 1)                                     */

        struct
        {
            __IOM uint32_t TOVPU : 16; /*!< [15..0] TOVPU                                                             */
            uint32_t             : 16;
        } PTPTOVC0U_b;
    };

    __IM uint32_t RESERVED3;

    union
    {
        __IOM uint32_t PTPAVTPTM0L;    /*!< (@ 0x00000040) AVTP Timer Monitoring Register Lt (PTPAVTPTMLt)
                                        *                  (t = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t AVTPL : 32; /*!< [31..0] AVTPL                                                             */
        } PTPAVTPTM0L_b;
    };

    union
    {
        __IOM uint32_t PTPAVTPTM0U;    /*!< (@ 0x00000044) AVTP Timer Monitoring Register Ut (PTPAVTPTMUt)
                                        *                  (t = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t AVTPU : 32; /*!< [31..0] AVTPU                                                             */
        } PTPAVTPTM0U_b;
    };

    __IM uint32_t RESERVED4[2];

    union
    {
        __IOM uint32_t PTPGPTPTM0L;    /*!< (@ 0x00000050) gPTP Timer Monitoring Register Lt (PTPGPTPTMLt)
                                        *                  (t = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t GPTPL : 30; /*!< [29..0] GPTPL                                                             */
            uint32_t             : 2;
        } PTPGPTPTM0L_b;
    };

    union
    {
        __IOM uint32_t PTPGPTPTM0M;    /*!< (@ 0x00000054) gPTP Timer Monitoring Register Mt (PTPGPTPTMMt)
                                        *                  (t = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t GPTPM : 32; /*!< [31..0] GPTPM                                                             */
        } PTPGPTPTM0M_b;
    };

    union
    {
        __IOM uint32_t PTPGPTPTM0U;    /*!< (@ 0x00000058) gPTP Timer Monitoring Register Ut (PTPGPTPTMUt)
                                        *                  (t = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t GPTPU : 16; /*!< [15..0] GPTPU                                                             */
            uint32_t             : 16;
        } PTPGPTPTM0U_b;
    };

    __IM uint32_t RESERVED5;

    union
    {
        __IOM uint32_t PTPTIVC1;       /*!< (@ 0x00000060) Timer Increment Value Configuration Register
                                        *                  t (PTPTIVCt) (t = 0, 1)                                    */

        struct
        {
            __IOM uint32_t TIV : 32;   /*!< [31..0] TIV                                                               */
        } PTPTIVC1_b;
    };

    __IM uint32_t RESERVED6[3];

    union
    {
        __IOM uint32_t PTPTOVC1L;      /*!< (@ 0x00000070) Timer Offset Value Configuration Register Lt
                                        *                  (PTPTOVCLt) (t = 0, 1)                                     */

        struct
        {
            __IOM uint32_t TOVPL : 30; /*!< [29..0] TOVPL                                                             */
            uint32_t             : 2;
        } PTPTOVC1L_b;
    };

    union
    {
        __IOM uint32_t PTPTOVC1M;      /*!< (@ 0x00000074) Timer Offset Value Configuration Register Mt
                                        *                  (PTPTOVCMt) (t = 0, 1)                                     */

        struct
        {
            __IOM uint32_t TOVPM : 32; /*!< [31..0] TOVPM                                                             */
        } PTPTOVC1M_b;
    };

    union
    {
        __IOM uint32_t PTPTOVC1U;      /*!< (@ 0x00000078) Timer Offset Value Configuration Register Ut
                                        *                  (PTPTOVCUt) (t = 0, 1)                                     */

        struct
        {
            __IOM uint32_t TOVPU : 16; /*!< [15..0] TOVPU                                                             */
            uint32_t             : 16;
        } PTPTOVC1U_b;
    };

    __IM uint32_t RESERVED7;

    union
    {
        __IOM uint32_t PTPAVTPTM1L;    /*!< (@ 0x00000080) AVTP Timer Monitoring Register Lt (PTPAVTPTMLt)
                                        *                  (t = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t AVTPL : 32; /*!< [31..0] AVTPL                                                             */
        } PTPAVTPTM1L_b;
    };

    union
    {
        __IOM uint32_t PTPAVTPTM1U;    /*!< (@ 0x00000084) AVTP Timer Monitoring Register Ut (PTPAVTPTMUt)
                                        *                  (t = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t AVTPU : 32; /*!< [31..0] AVTPU                                                             */
        } PTPAVTPTM1U_b;
    };

    __IM uint32_t RESERVED8[2];

    union
    {
        __IOM uint32_t PTPGPTPTM1L;    /*!< (@ 0x00000090) gPTP Timer Monitoring Register Lt (PTPGPTPTMLt)
                                        *                  (t = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t GPTPL : 30; /*!< [29..0] GPTPL                                                             */
            uint32_t             : 2;
        } PTPGPTPTM1L_b;
    };

    union
    {
        __IOM uint32_t PTPGPTPTM1M;    /*!< (@ 0x00000094) gPTP Timer Monitoring Register Mt (PTPGPTPTMMt)
                                        *                  (t = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t GPTPM : 32; /*!< [31..0] GPTPM                                                             */
        } PTPGPTPTM1M_b;
    };

    union
    {
        __IOM uint32_t PTPGPTPTM1U;    /*!< (@ 0x00000098) gPTP Timer Monitoring Register Ut (PTPGPTPTMUt)
                                        *                  (t = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t GPTPU : 16; /*!< [15..0] GPTPU                                                             */
            uint32_t             : 16;
        } PTPGPTPTM1U_b;
    };

    __IM uint32_t RESERVED9[89];

    union
    {
        __IOM uint32_t PTPMCCC0;       /*!< (@ 0x00000200) Media Clock Capture Configuration Register m
                                        *                  (PTPMCCCm) (m = 0, 1)                                      */

        struct
        {
            __IOM uint32_t MCPEE : 1;  /*!< [0..0] MCPEE                                                              */
            __IOM uint32_t MCNEE : 1;  /*!< [1..1] MCNEE                                                              */
            __IOM uint32_t MCTTS : 1;  /*!< [2..2] MCTTS                                                              */
            __IOM uint32_t MCTNS : 1;  /*!< [3..3] MCTNS                                                              */
            uint32_t             : 12;
            __IOM uint32_t MCCR  : 1;  /*!< [16..16] MCCR                                                             */
            uint32_t             : 15;
        } PTPMCCC0_b;
    };

    union
    {
        __IOM uint32_t PTPMCCM0L;        /*!< (@ 0x00000204) Media Clock Capture Monitoring Register Lm (PTPMCCMLm)
                                          *                  (m = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t MCCTVP0 : 32; /*!< [31..0] MCCTVP0                                                           */
        } PTPMCCM0L_b;
    };

    union
    {
        __IOM uint32_t PTPMCCM0M;       /*!< (@ 0x00000208) Media Clock Capture Monitoring Register Mm (PTPMCCMMm)
                                         *                  (m = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t MCCTVM : 32; /*!< [31..0] MCCTVM                                                            */
        } PTPMCCM0M_b;
    };

    union
    {
        __IOM uint32_t PTPMCCM0U;       /*!< (@ 0x0000020C) Media Clock Capture Monitoring Register Um (PTPMCCMUm)
                                         *                  (m = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t MCCTVU : 16; /*!< [15..0] MCCTVU                                                            */
            __IOM uint32_t MCPEC  : 1;  /*!< [16..16] MCPEC                                                            */
            __IOM uint32_t MCNEC  : 1;  /*!< [17..17] MCNEC                                                            */
            __IOM uint32_t MCSWC  : 1;  /*!< [18..18] MCSWC                                                            */
            uint32_t              : 5;
            __IOM uint32_t MCCN   : 2;  /*!< [25..24] MCCN                                                             */
            uint32_t              : 6;
        } PTPMCCM0U_b;
    };

    union
    {
        __IOM uint32_t PTPMCCC1;       /*!< (@ 0x00000210) Media Clock Capture Configuration Register m
                                        *                  (PTPMCCCm) (m = 0, 1)                                      */

        struct
        {
            __IOM uint32_t MCPEE : 1;  /*!< [0..0] MCPEE                                                              */
            __IOM uint32_t MCNEE : 1;  /*!< [1..1] MCNEE                                                              */
            __IOM uint32_t MCTTS : 1;  /*!< [2..2] MCTTS                                                              */
            __IOM uint32_t MCTNS : 1;  /*!< [3..3] MCTNS                                                              */
            uint32_t             : 12;
            __IOM uint32_t MCCR  : 1;  /*!< [16..16] MCCR                                                             */
            uint32_t             : 15;
        } PTPMCCC1_b;
    };

    union
    {
        __IOM uint32_t PTPMCCM1L;       /*!< (@ 0x00000214) Media Clock Capture Monitoring Register Lm (PTPMCCMLm)
                                         *                  (m = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t MCCTVL : 32; /*!< [31..0] MCCTVL                                                            */
        } PTPMCCM1L_b;
    };

    union
    {
        __IOM uint32_t PTPMCCM1M;       /*!< (@ 0x00000218) Media Clock Capture Monitoring Register Mm (PTPMCCMMm)
                                         *                  (m = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t MCCTVM : 32; /*!< [31..0] MCCTVM                                                            */
        } PTPMCCM1M_b;
    };

    union
    {
        __IOM uint32_t PTPMCCM1U;       /*!< (@ 0x0000021C) Media Clock Capture Monitoring Register Um (PTPMCCMUm)
                                         *                  (m = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t MCCTVU : 16; /*!< [15..0] MCCTVU                                                            */
            __IOM uint32_t MCPEC  : 1;  /*!< [16..16] MCPEC                                                            */
            __IOM uint32_t MCNEC  : 1;  /*!< [17..17] MCNEC                                                            */
            __IOM uint32_t MCSWC  : 1;  /*!< [18..18] MCSWC                                                            */
            uint32_t              : 5;
            __IOM uint32_t MCCN   : 2;  /*!< [25..24] MCCN                                                             */
            uint32_t              : 6;
        } PTPMCCM1U_b;
    };

    __IM uint32_t RESERVED10[56];

    union
    {
        __IOM uint32_t PTPMCRC0;       /*!< (@ 0x00000300) Media Clock Recovery Configuration Register m
                                        *                  (PTPMCRCm) (m = 0, 1)                                      */

        struct
        {
            __IOM uint32_t MRTTS : 1;  /*!< [0..0] MRTTS                                                              */
            __IOM uint32_t MRAMS : 1;  /*!< [1..1] MRAMS                                                              */
            __IOM uint32_t MRTNS : 1;  /*!< [2..2] MRTNS                                                              */
            uint32_t             : 13;
            __IOM uint32_t MRPL  : 16; /*!< [31..16] MRPL                                                             */
        } PTPMCRC0_b;
    };

    union
    {
        __IOM uint32_t PTPMCRTC0L;     /*!< (@ 0x00000304) Media Clock Recovery Time Configuration Register
                                        *                  Lm (PTPMCRTCLm) (m = 0, 1)                                 */

        struct
        {
            __IOM uint32_t MRTVL : 32; /*!< [31..0] MRTVL                                                             */
        } PTPMCRTC0L_b;
    };

    union
    {
        __IOM uint32_t PTPMCRTC0M;     /*!< (@ 0x00000308) Media Clock Recovery Time Configuration Register
                                        *                  Mm (PTPMCRTCMm) (m = 0, 1)                                 */

        struct
        {
            __IOM uint32_t MRTVM : 32; /*!< [31..0] MRTVM                                                             */
        } PTPMCRTC0M_b;
    };

    union
    {
        __IOM uint32_t PTPMCRTC0U;      /*!< (@ 0x0000030C) Media Clock Recovery Time Configuration Register
                                         *                  Um (PTPMCRTCUm) (m = 0, 1)                                 */

        struct
        {
            __IOM uint32_t MCCTVU : 16; /*!< [15..0] MCCTVU                                                            */
            __IOM uint32_t MRTT   : 2;  /*!< [17..16] MRTT                                                             */
            __IOM uint32_t MCRN   : 3;  /*!< [20..18] MCRN                                                             */
            uint32_t              : 10;
            __IOM uint32_t MRBCR  : 1;  /*!< [31..31] MRBCR                                                            */
        } PTPMCRTC0U_b;
    };

    union
    {
        __IOM uint32_t PTPMCRC1;       /*!< (@ 0x00000310) Media Clock Recovery Configuration Register m
                                        *                  (PTPMCRCm) (m = 0, 1)                                      */

        struct
        {
            __IOM uint32_t MRTTS : 1;  /*!< [0..0] MRTTS                                                              */
            __IOM uint32_t MRAMS : 1;  /*!< [1..1] MRAMS                                                              */
            __IOM uint32_t MRTNS : 1;  /*!< [2..2] MRTNS                                                              */
            uint32_t             : 13;
            __IOM uint32_t MRPL  : 16; /*!< [31..16] MRPL                                                             */
        } PTPMCRC1_b;
    };

    union
    {
        __IOM uint32_t PTPMCRTC1L;     /*!< (@ 0x00000314) Media Clock Recovery Time Configuration Register
                                        *                  Lm (PTPMCRTCLm) (m = 0, 1)                                 */

        struct
        {
            __IOM uint32_t MRTVL : 32; /*!< [31..0] MRTVL                                                             */
        } PTPMCRTC1L_b;
    };

    union
    {
        __IOM uint32_t PTPMCRTC1M;     /*!< (@ 0x00000318) Media Clock Recovery Time Configuration Register
                                        *                  Mm (PTPMCRTCMm) (m = 0, 1)                                 */

        struct
        {
            __IOM uint32_t MRTVM : 32; /*!< [31..0] MRTVM                                                             */
        } PTPMCRTC1M_b;
    };

    union
    {
        __IOM uint32_t PTPMCRTC1U;      /*!< (@ 0x0000031C) Media Clock Recovery Time Configuration Register
                                         *                  Um (PTPMCRTCUm) (m = 0, 1)                                 */

        struct
        {
            __IOM uint32_t MCCTVU : 16; /*!< [15..0] MCCTVU                                                            */
            __IOM uint32_t MRTT   : 2;  /*!< [17..16] MRTT                                                             */
            __IOM uint32_t MCRN   : 3;  /*!< [20..18] MCRN                                                             */
            uint32_t              : 10;
            __IOM uint32_t MRBCR  : 1;  /*!< [31..31] MRBCR                                                            */
        } PTPMCRTC1U_b;
    };

    __IM uint32_t RESERVED11[56];

    union
    {
        __IOM uint32_t PTPMCPC0;       /*!< (@ 0x00000400) Media Clock Pin Configuration Register m (PTPMCPCm)
                                        *                  (m = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t PE  : 1;    /*!< [0..0] PE                                                                 */
            __IOM uint32_t MRS : 1;    /*!< [1..1] MRS                                                                */
            uint32_t           : 30;
        } PTPMCPC0_b;
    };

    union
    {
        __IOM uint32_t PTPMCPC1;       /*!< (@ 0x00000404) Media Clock Pin Configuration Register m (PTPMCPCm)
                                        *                  (m = 0, 1)                                                 */

        struct
        {
            __IOM uint32_t PE  : 1;    /*!< [0..0] PE                                                                 */
            __IOM uint32_t MRS : 1;    /*!< [1..1] MRS                                                                */
            uint32_t           : 30;
        } PTPMCPC1_b;
    };

    __IM uint32_t RESERVED12[62];

    union
    {
        __IOM uint32_t PTPCCC00;       /*!< (@ 0x00000500) Cyclic Compare Configuration Register 0c (PTPCCC0c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCTNS : 1;  /*!< [0..0] CCTNS                                                              */
            uint32_t             : 3;
            __IOM uint32_t CCOPS : 1;  /*!< [4..4] CCOPS                                                              */
            uint32_t             : 27;
        } PTPCCC00_b;
    };

    union
    {
        __IOM uint32_t PTPCCC01;       /*!< (@ 0x00000504) Cyclic Compare Configuration Register 1c (PTPCCC1c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCV : 32;   /*!< [31..0] CCV                                                               */
        } PTPCCC01_b;
    };

    union
    {
        __IOM uint32_t PTPCCC10;       /*!< (@ 0x00000508) Cyclic Compare Configuration Register 0c (PTPCCC0c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCTNS : 1;  /*!< [0..0] CCTNS                                                              */
            uint32_t             : 3;
            __IOM uint32_t CCOPS : 1;  /*!< [4..4] CCOPS                                                              */
            uint32_t             : 27;
        } PTPCCC10_b;
    };

    union
    {
        __IOM uint32_t PTPCCC11;       /*!< (@ 0x0000050C) Cyclic Compare Configuration Register 1c (PTPCCC1c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCV : 32;   /*!< [31..0] CCV                                                               */
        } PTPCCC11_b;
    };

    union
    {
        __IOM uint32_t PTPCCC20;       /*!< (@ 0x00000510) Cyclic Compare Configuration Register 0c (PTPCCC0c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCTNS : 1;  /*!< [0..0] CCTNS                                                              */
            uint32_t             : 3;
            __IOM uint32_t CCOPS : 1;  /*!< [4..4] CCOPS                                                              */
            uint32_t             : 27;
        } PTPCCC20_b;
    };

    union
    {
        __IOM uint32_t PTPCCC21;       /*!< (@ 0x00000514) Cyclic Compare Configuration Register 1c (PTPCCC1c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCV : 32;   /*!< [31..0] CCV                                                               */
        } PTPCCC21_b;
    };

    union
    {
        __IOM uint32_t PTPCCC30;       /*!< (@ 0x00000518) Cyclic Compare Configuration Register 0c (PTPCCC0c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCTNS : 1;  /*!< [0..0] CCTNS                                                              */
            uint32_t             : 3;
            __IOM uint32_t CCOPS : 1;  /*!< [4..4] CCOPS                                                              */
            uint32_t             : 27;
        } PTPCCC30_b;
    };

    union
    {
        __IOM uint32_t PTPCCC31;       /*!< (@ 0x0000051C) Cyclic Compare Configuration Register 1c (PTPCCC1c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCV : 32;   /*!< [31..0] CCV                                                               */
        } PTPCCC31_b;
    };

    union
    {
        __IOM uint32_t PTPCCC40;       /*!< (@ 0x00000520) Cyclic Compare Configuration Register 0c (PTPCCC0c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCTNS : 1;  /*!< [0..0] CCTNS                                                              */
            uint32_t             : 3;
            __IOM uint32_t CCOPS : 1;  /*!< [4..4] CCOPS                                                              */
            uint32_t             : 27;
        } PTPCCC40_b;
    };

    union
    {
        __IOM uint32_t PTPCCC41;       /*!< (@ 0x00000524) Cyclic Compare Configuration Register 1c (PTPCCC1c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCV : 32;   /*!< [31..0] CCV                                                               */
        } PTPCCC41_b;
    };

    union
    {
        __IOM uint32_t PTPCCC50;       /*!< (@ 0x00000528) Cyclic Compare Configuration Register 0c (PTPCCC0c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCTNS : 1;  /*!< [0..0] CCTNS                                                              */
            uint32_t             : 3;
            __IOM uint32_t CCOPS : 1;  /*!< [4..4] CCOPS                                                              */
            uint32_t             : 27;
        } PTPCCC50_b;
    };

    union
    {
        __IOM uint32_t PTPCCC51;       /*!< (@ 0x0000052C) Cyclic Compare Configuration Register 1c (PTPCCC1c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCV : 32;   /*!< [31..0] CCV                                                               */
        } PTPCCC51_b;
    };

    union
    {
        __IOM uint32_t PTPCCC60;       /*!< (@ 0x00000530) Cyclic Compare Configuration Register 0c (PTPCCC0c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCTNS : 1;  /*!< [0..0] CCTNS                                                              */
            uint32_t             : 3;
            __IOM uint32_t CCOPS : 1;  /*!< [4..4] CCOPS                                                              */
            uint32_t             : 27;
        } PTPCCC60_b;
    };

    union
    {
        __IOM uint32_t PTPCCC61;       /*!< (@ 0x00000534) Cyclic Compare Configuration Register 1c (PTPCCC1c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCV : 32;   /*!< [31..0] CCV                                                               */
        } PTPCCC61_b;
    };

    union
    {
        __IOM uint32_t PTPCCC70;       /*!< (@ 0x00000538) Cyclic Compare Configuration Register 0c (PTPCCC0c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCTNS : 1;  /*!< [0..0] CCTNS                                                              */
            uint32_t             : 3;
            __IOM uint32_t CCOPS : 1;  /*!< [4..4] CCOPS                                                              */
            uint32_t             : 27;
        } PTPCCC70_b;
    };

    union
    {
        __IOM uint32_t PTPCCC71;       /*!< (@ 0x0000053C) Cyclic Compare Configuration Register 1c (PTPCCC1c)
                                        *                  (c = 0 to 7)                                               */

        struct
        {
            __IOM uint32_t CCV : 32;   /*!< [31..0] CCV                                                               */
        } PTPCCC71_b;
    };

    __IM uint32_t RESERVED13[112];

    union
    {
        __IOM uint32_t PTPIS0;          /*!< (@ 0x00000700) Interrupt Status Register 0 (PTPIS0)                       */

        struct
        {
            __IOM uint32_t MCCS0   : 1; /*!< [0..0] MCCS0                                                              */
            __IOM uint32_t MCCS1   : 1; /*!< [1..1] MCCS1                                                              */
            uint32_t               : 14;
            __IOM uint32_t MCCOES0 : 1; /*!< [16..16] MCCOES0                                                          */
            uint32_t               : 15;
        } PTPIS0_b;
    };

    union
    {
        __IOM uint32_t PTPIE0;          /*!< (@ 0x00000704) Interrupt Enable Register 0 (PTPIE0)                       */

        struct
        {
            __IOM uint32_t MCCE0   : 1; /*!< [0..0] MCCE0                                                              */
            __IOM uint32_t MCCE1   : 1; /*!< [1..1] MCCE1                                                              */
            uint32_t               : 14;
            __IOM uint32_t MCCOEE0 : 1; /*!< [16..16] MCCOEE0                                                          */
            uint32_t               : 15;
        } PTPIE0_b;
    };

    union
    {
        __IOM uint32_t PTPID0;          /*!< (@ 0x00000708) Interrupt Disable Register 0 (PTPID0)                      */

        struct
        {
            __IOM uint32_t MCCD0   : 1; /*!< [0..0] MCCD0                                                              */
            __IOM uint32_t MCCD1   : 1; /*!< [1..1] MCCD1                                                              */
            uint32_t               : 14;
            __IOM uint32_t MCCOED0 : 1; /*!< [16..16] MCCOED0                                                          */
            uint32_t               : 15;
        } PTPID0_b;
    };

    __IM uint32_t RESERVED14;

    union
    {
        __IOM uint32_t PTPIS1;         /*!< (@ 0x00000710) Interrupt Status Register 1 (PTPIS1)                       */

        struct
        {
            __IOM uint32_t MCRMS0 : 1; /*!< [0..0] MCRMS0                                                             */
            __IOM uint32_t MCRMS1 : 1; /*!< [1..1] MCRMS1                                                             */
            uint32_t              : 30;
        } PTPIS1_b;
    };

    union
    {
        __IOM uint32_t PTPIE1;         /*!< (@ 0x00000714) Interrupt Enable Register 1 (PTPIE1)                       */

        struct
        {
            __IOM uint32_t MCRME0 : 1; /*!< [0..0] MCRME0                                                             */
            __IOM uint32_t MCRME1 : 1; /*!< [1..1] MCRME1                                                             */
            uint32_t              : 30;
        } PTPIE1_b;
    };

    union
    {
        __IOM uint32_t PTPID1;         /*!< (@ 0x00000718) Interrupt Disable Register 1 (PTPID1)                      */

        struct
        {
            __IOM uint32_t MCRMD0 : 1; /*!< [0..0] MCRMD0                                                             */
            __IOM uint32_t MCRMD1 : 1; /*!< [1..1] MCRMD1                                                             */
            uint32_t              : 30;
        } PTPID1_b;
    };

    __IM uint32_t RESERVED15[25];

    union
    {
        __IOM uint32_t PTPSCR0;        /*!< (@ 0x00000780) Security Configuration Register 0 (PTPSCR0)                */

        struct
        {
            __IOM uint32_t TRSL0  : 1; /*!< [0..0] TRSL0                                                              */
            __IOM uint32_t TRSL1  : 1; /*!< [1..1] TRSL1                                                              */
            uint32_t              : 14;
            __IOM uint32_t MCRSL0 : 1; /*!< [16..16] MCRSL0                                                           */
            __IOM uint32_t MCRSL1 : 1; /*!< [17..17] MCRSL1                                                           */
            uint32_t              : 14;
        } PTPSCR0_b;
    };

    union
    {
        __IOM uint32_t PTPSCR1;         /*!< (@ 0x00000784) Security Configuration Register 1 (PTPSCR1)                */

        struct
        {
            __IOM uint32_t MRRSL0  : 1; /*!< [0..0] MRRSL0                                                             */
            __IOM uint32_t MRRSL1  : 1; /*!< [1..1] MRRSL1                                                             */
            uint32_t               : 14;
            __IOM uint32_t MRRRSL0 : 1; /*!< [16..16] MRRRSL0                                                          */
            __IOM uint32_t MRRRSL1 : 1; /*!< [17..17] MRRRSL1                                                          */
            uint32_t               : 14;
        } PTPSCR1_b;
    };

    union
    {
        __IOM uint32_t PTPSCR2;        /*!< (@ 0x00000788) Security Configuration Register 2 (PTPSCR2)                */

        struct
        {
            __IOM uint32_t CCRSL0 : 1; /*!< [0..0] CCRSL0                                                             */
            __IOM uint32_t CCRSL1 : 1; /*!< [1..1] CCRSL1                                                             */
            uint32_t              : 14;
            __IOM uint32_t VRSL   : 1; /*!< [16..16] VRSL                                                             */
            uint32_t              : 15;
        } PTPSCR2_b;
    };

    __IM uint32_t RESERVED16[541];

    union
    {
        __IOM uint32_t POTCFGR;        /*!< (@ 0x00001000) Pulse Output Timer Configuration Register                  */

        struct
        {
            __IOM uint32_t REFSEL : 1; /*!< [0..0] Reference Timer Select                                             */
            uint32_t              : 31;
        } POTCFGR_b;
    };

    union
    {
        __IOM uint32_t POTCR0;         /*!< (@ 0x00001004) Pulse Output Control Register 0                            */

        struct
        {
            __IOM uint32_t START : 1;  /*!< [0..0] Timer Start                                                        */
            uint32_t             : 31;
        } POTCR0_b;
    };

    __IOM uint32_t POTSTR0U;           /*!< (@ 0x00001008) Pulse Output Start Time Setting Register U0                */
    __IOM uint32_t POTSTR0M;           /*!< (@ 0x0000100C) Pulse Output Start Time Setting Register M0                */
    __IOM uint32_t POTSTR0L;           /*!< (@ 0x00001010) Pulse Output Start Time Setting Register L0                */
    __IOM uint32_t POTPER0U;           /*!< (@ 0x00001014) Period Setting Regsiter U0                                 */
    __IOM uint32_t POTPER0M;           /*!< (@ 0x00001018) Period Setting Regsiter M0                                 */
    __IOM uint32_t POTPER0L;           /*!< (@ 0x0000101C) Period Setting Regsiter L0                                 */
    __IOM uint32_t POTPWR0;            /*!< (@ 0x00001020) Pulse Width Setting Regsiter 0                             */
    __IM uint32_t  RESERVED17;
    __IOM uint32_t POTCPR0U;           /*!< (@ 0x00001028) Time Capture Register U0                                   */
    __IOM uint32_t POTCPR0M;           /*!< (@ 0x0000102C) Time Capture Register M0                                   */
    __IOM uint32_t POTCPR0L;           /*!< (@ 0x00001030) Time Capture Register L0                                   */

    union
    {
        __IOM uint32_t POTCR1;         /*!< (@ 0x00001034) Pulse Output Control Register 1                            */

        struct
        {
            __IOM uint32_t START : 1;  /*!< [0..0] Timer Start                                                        */
            uint32_t             : 31;
        } POTCR1_b;
    };

    __IOM uint32_t POTSTR1U;           /*!< (@ 0x00001038) Pulse Output Start Time Setting Register U1                */
    __IOM uint32_t POTSTR1M;           /*!< (@ 0x0000103C) Pulse Output Start Time Setting Register M1                */
    __IOM uint32_t POTSTR1L;           /*!< (@ 0x00001040) Pulse Output Start Time Setting Register L1                */
    __IOM uint32_t POTPER1U;           /*!< (@ 0x00001044) Period Setting Regsiter U1                                 */
    __IOM uint32_t POTPER1M;           /*!< (@ 0x00001048) Period Setting Regsiter M1                                 */
    __IOM uint32_t POTPER1L;           /*!< (@ 0x0000104C) Period Setting Regsiter L1                                 */
    __IOM uint32_t POTPWR1;            /*!< (@ 0x00001050) Pulse Width Setting Regsiter 1                             */
    __IM uint32_t  RESERVED18;
    __IOM uint32_t POTCPR1U;           /*!< (@ 0x00001058) Time Capture Register U1                                   */
    __IOM uint32_t POTCPR1M;           /*!< (@ 0x0000105C) Time Capture Register M1                                   */
    __IOM uint32_t POTCPR1L;           /*!< (@ 0x00001060) Time Capture Register L1                                   */

    union
    {
        __IOM uint32_t POTCR2;         /*!< (@ 0x00001064) Pulse Output Control Register 2                            */

        struct
        {
            __IOM uint32_t START : 1;  /*!< [0..0] Timer Start                                                        */
            uint32_t             : 31;
        } POTCR2_b;
    };

    __IOM uint32_t POTSTR2U;           /*!< (@ 0x00001068) Pulse Output Start Time Setting Register U2                */
    __IOM uint32_t POTSTR2M;           /*!< (@ 0x0000106C) Pulse Output Start Time Setting Register M2                */
    __IOM uint32_t POTSTR2L;           /*!< (@ 0x00001070) Pulse Output Start Time Setting Register L2                */
    __IOM uint32_t POTPER2U;           /*!< (@ 0x00001074) Period Setting Regsiter U2                                 */
    __IOM uint32_t POTPER2M;           /*!< (@ 0x00001078) Period Setting Regsiter M2                                 */
    __IOM uint32_t POTPER2L;           /*!< (@ 0x0000107C) Period Setting Regsiter L2                                 */
    __IOM uint32_t POTPWR2;            /*!< (@ 0x00001080) Pulse Width Setting Regsiter 2                             */
    __IM uint32_t  RESERVED19;
    __IOM uint32_t POTCPR2U;           /*!< (@ 0x00001088) Time Capture Register U2                                   */
    __IOM uint32_t POTCPR2M;           /*!< (@ 0x0000108C) Time Capture Register M2                                   */
    __IOM uint32_t POTCPR2L;           /*!< (@ 0x00001090) Time Capture Register L2                                   */

    union
    {
        __IOM uint32_t POTCR3;         /*!< (@ 0x00001094) Pulse Output Control Register 3                            */

        struct
        {
            __IOM uint32_t START : 1;  /*!< [0..0] Timer Start                                                        */
            uint32_t             : 31;
        } POTCR3_b;
    };

    __IOM uint32_t POTSTR3U;           /*!< (@ 0x00001098) Pulse Output Start Time Setting Register U3                */
    __IOM uint32_t POTSTR3M;           /*!< (@ 0x0000109C) Pulse Output Start Time Setting Register M3                */
    __IOM uint32_t POTSTR3L;           /*!< (@ 0x000010A0) Pulse Output Start Time Setting Register L3                */
    __IOM uint32_t POTPER3U;           /*!< (@ 0x000010A4) Period Setting Regsiter U3                                 */
    __IOM uint32_t POTPER3M;           /*!< (@ 0x000010A8) Period Setting Regsiter M3                                 */
    __IOM uint32_t POTPER3L;           /*!< (@ 0x000010AC) Period Setting Regsiter L3                                 */
    __IOM uint32_t POTPWR3;            /*!< (@ 0x000010B0) Pulse Width Setting Regsiter 3                             */
    __IM uint32_t  RESERVED20;
    __IOM uint32_t POTCPR3U;           /*!< (@ 0x000010B8) Time Capture Register U3                                   */
    __IOM uint32_t POTCPR3M;           /*!< (@ 0x000010BC) Time Capture Register M3                                   */
    __IOM uint32_t POTCPR3L;           /*!< (@ 0x000010C0) Time Capture Register L3                                   */
} R_GPTP_Type;                         /*!< Size = 4292 (0x10c4)                                                      */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif                                 /* R_GPTP_REG_H */
