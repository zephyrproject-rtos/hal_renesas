/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_PDM_REG_H
#define R_PDM_REG_H

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief R_PDM_CH [CH] (PDM Channel-Specific Registers)
 */
typedef struct
{
    union
    {
        __OM uint32_t PDSTRTR;         /*!< (@ 0x00000000) Software Start Trigger Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 31;
            __OM uint32_t STRTRG : 1;  /*!< [0..0] Start trigger                                                      */
#else
            __OM uint32_t STRTRG : 1;  /*!< [0..0] Start trigger                                                      */
            uint32_t             : 31;
#endif
        } PDSTRTR_b;
    };

    union
    {
        __OM uint32_t PDSTPTR;         /*!< (@ 0x00000004) Software Stop Trigger Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 31;
            __OM uint32_t STPTRG : 1;  /*!< [0..0] Stop trigger                                                       */
#else
            __OM uint32_t STPTRG : 1;  /*!< [0..0] Stop trigger                                                       */
            uint32_t             : 31;
#endif
        } PDSTPTR_b;
    };

    union
    {
        __OM uint32_t PDCHGTR;         /*!< (@ 0x00000008) Software Change Trigger Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 31;
            __OM uint32_t CHGTRG : 1;  /*!< [0..0] Change trigger                                                     */
#else
            __OM uint32_t CHGTRG : 1;  /*!< [0..0] Change trigger                                                     */
            uint32_t             : 31;
#endif
        } PDCHGTR_b;
    };

    union
    {
        __IOM uint32_t PDICR;          /*!< (@ 0x0000000C) Interrupt Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 15;
            __IOM uint32_t IEDE : 1;   /*!< [16..16] Error detection interrupt enable bit                             */
            uint32_t            : 13;
            __IOM uint32_t IDRE : 1;   /*!< [2..2] Data reception interrupt enable bit                                */
            __IOM uint32_t ISDE : 1;   /*!< [1..1] Sound detection interrupt enable bit                               */
            uint32_t            : 1;
#else
            uint32_t            : 1;
            __IOM uint32_t ISDE : 1;   /*!< [1..1] Sound detection interrupt enable bit                               */
            __IOM uint32_t IDRE : 1;   /*!< [2..2] Data reception interrupt enable bit                                */
            uint32_t            : 13;
            __IOM uint32_t IEDE : 1;   /*!< [16..16] Error detection interrupt enable bit                             */
            uint32_t            : 15;
#endif
        } PDICR_b;
    };

    union
    {
        __IOM uint32_t PDSDCR;         /*!< (@ 0x00000010) Status Detection Control Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 4;
            __IOM uint32_t BFOWDE : 1; /*!< [27..27] Buffer overwriting detection enable bit                          */
            uint32_t              : 8;
            __IOM uint32_t OVUDE  : 1; /*!< [18..18] Overvoltage upper limit exceeded detection enable bit            */
            __IOM uint32_t OVLDE  : 1; /*!< [17..17] Overvoltage lower limit exceeded detection enable bit            */
            __IOM uint32_t SCDE   : 1; /*!< [16..16] Short circuit detection enable bit                               */
            uint32_t              : 14;
            __IOM uint32_t SDE    : 1; /*!< [1..1] Sound detection enable bit                                         */
            uint32_t              : 1;
#else
            uint32_t              : 1;
            __IOM uint32_t SDE    : 1; /*!< [1..1] Sound detection enable bit                                         */
            uint32_t              : 14;
            __IOM uint32_t SCDE   : 1; /*!< [16..16] Short circuit detection enable bit                               */
            __IOM uint32_t OVLDE  : 1; /*!< [17..17] Overvoltage lower limit exceeded detection enable bit            */
            __IOM uint32_t OVUDE  : 1; /*!< [18..18] Overvoltage upper limit exceeded detection enable bit            */
            uint32_t              : 8;
            __IOM uint32_t BFOWDE : 1; /*!< [27..27] Buffer overwriting detection enable bit                          */
            uint32_t              : 4;
#endif
        } PDSDCR_b;
    };

    union
    {
        __IM uint32_t PDSR;            /*!< (@ 0x00000014) Status Register                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 4;
            __IM uint32_t BFOWDF : 1;  /*!< [27..27] Buffer overwriting detection flag                                */
            uint32_t             : 8;
            __IM uint32_t OVUDF  : 1;  /*!< [18..18] Overvoltage upper limit exceeded detection flag                  */
            __IM uint32_t OVLDF  : 1;  /*!< [17..17] Overvoltage lower limit exceeded detection flag                  */
            __IM uint32_t SCDF   : 1;  /*!< [16..16] Short circuit detection flag                                     */
            uint32_t             : 13;
            __IM uint32_t DRF    : 1;  /*!< [2..2] Data reception flag                                                */
            __IM uint32_t SDF    : 1;  /*!< [1..1] Sound detection flag                                               */
            __IM uint32_t STATE  : 1;  /*!< [0..0] State                                                              */
#else
            __IM uint32_t STATE  : 1;  /*!< [0..0] State                                                              */
            __IM uint32_t SDF    : 1;  /*!< [1..1] Sound detection flag                                               */
            __IM uint32_t DRF    : 1;  /*!< [2..2] Data reception flag                                                */
            uint32_t             : 13;
            __IM uint32_t SCDF   : 1;  /*!< [16..16] Short circuit detection flag                                     */
            __IM uint32_t OVLDF  : 1;  /*!< [17..17] Overvoltage lower limit exceeded detection flag                  */
            __IM uint32_t OVUDF  : 1;  /*!< [18..18] Overvoltage upper limit exceeded detection flag                  */
            uint32_t             : 8;
            __IM uint32_t BFOWDF : 1;  /*!< [27..27] Buffer overwriting detection flag                                */
            uint32_t             : 4;
#endif
        } PDSR_b;
    };

    union
    {
        __OM uint32_t PDSCR;           /*!< (@ 0x00000018) Status Clear Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 4;
            __OM uint32_t BFOWDFC : 1; /*!< [27..27] Buffer overwriting detection flag clear                          */
            uint32_t              : 8;
            __OM uint32_t OVUDFC  : 1; /*!< [18..18] Overvoltage upper limit exceeded detection flag clear            */
            __OM uint32_t OVLDFC  : 1; /*!< [17..17] Overvoltage lower limit exceeded detection flag clear            */
            __OM uint32_t SCDFC   : 1; /*!< [16..16] Short circuit detection flag clear                               */
            uint32_t              : 14;
            __OM uint32_t SDFC    : 1; /*!< [1..1] Sound detection flag clear                                         */
            uint32_t              : 1;
#else
            uint32_t              : 1;
            __OM uint32_t SDFC    : 1; /*!< [1..1] Sound detection flag clear                                         */
            uint32_t              : 14;
            __OM uint32_t SCDFC   : 1; /*!< [16..16] Short circuit detection flag clear                               */
            __OM uint32_t OVLDFC  : 1; /*!< [17..17] Overvoltage lower limit exceeded detection flag clear            */
            __OM uint32_t OVUDFC  : 1; /*!< [18..18] Overvoltage upper limit exceeded detection flag clear            */
            uint32_t              : 8;
            __OM uint32_t BFOWDFC : 1; /*!< [27..27] Buffer overwriting detection flag clear                          */
            uint32_t              : 4;
#endif
        } PDSCR_b;
    };
    __IM uint32_t RESERVED;

    union
    {
        __IOM uint32_t PDMDSR;         /*!< (@ 0x00000020) Mode Setting Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DBIS   : 4; /*!< [31..28] Data buffer input shift setting                                  */
            uint32_t              : 2;
            __IOM uint32_t SDMAMD : 2; /*!< [25..24] Moving average mode for sound detection data                     */
            uint32_t              : 6;
            __IOM uint32_t LFIS   : 2; /*!< [17..16] Low-pass (half-band decimation) filter input shift
                                        *   setting                                                                   */
            uint32_t              : 2;
            __IOM uint32_t CFIS   : 2; /*!< [13..12] Compensation filter input shift setting                          */
            uint32_t              : 2;
            __IOM uint32_t HFIS   : 2; /*!< [9..8] High-pass filter input shift setting                               */
            uint32_t              : 1;
            __IOM uint32_t SFMD   : 3; /*!< [6..4] Sinc filter mode setting                                           */
            uint32_t              : 3;
            __IOM uint32_t INPSEL : 1; /*!< [0..0] Input data select                                                  */
#else
            __IOM uint32_t INPSEL : 1; /*!< [0..0] Input data select                                                  */
            uint32_t              : 3;
            __IOM uint32_t SFMD   : 3; /*!< [6..4] Sinc filter mode setting                                           */
            uint32_t              : 1;
            __IOM uint32_t HFIS   : 2; /*!< [9..8] High-pass filter input shift setting                               */
            uint32_t              : 2;
            __IOM uint32_t CFIS   : 2; /*!< [13..12] Compensation filter input shift setting                          */
            uint32_t              : 2;
            __IOM uint32_t LFIS   : 2; /*!< [17..16] Low-pass (half-band decimation) filter input shift
                                        *   setting                                                                   */
            uint32_t              : 6;
            __IOM uint32_t SDMAMD : 2; /*!< [25..24] Moving average mode for sound detection data                     */
            uint32_t              : 2;
            __IOM uint32_t DBIS   : 4; /*!< [31..28] Data buffer input shift setting                                  */
#endif
        } PDMDSR_b;
    };

    union
    {
        __IOM uint32_t PDSFCR;         /*!< (@ 0x00000024) Sinc filter Control Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 3;
            __IOM uint32_t SINCRNG : 5; /*!< [28..24] Sinc filter output valid range                                   */
            __IOM uint32_t SINCDEC : 8; /*!< [23..16] Sinc filter decimation ratio                                     */
            uint32_t               : 12;
            __IOM uint32_t CKDIV   : 4; /*!< [3..0] PDM_CLKn's dividend ratio to core clock                            */
#else
            __IOM uint32_t CKDIV   : 4; /*!< [3..0] PDM_CLKn's dividend ratio to core clock                            */
            uint32_t               : 12;
            __IOM uint32_t SINCDEC : 8; /*!< [23..16] Sinc filter decimation ratio                                     */
            __IOM uint32_t SINCRNG : 5; /*!< [28..24] Sinc filter output valid range                                   */
            uint32_t               : 3;
#endif
        } PDSFCR_b;
    };

    union
    {
        __IOM uint32_t PDHFCS0R;       /*!< (@ 0x00000028) High-pass filter Coefficient s(0) Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __IOM uint32_t HFS0 : 16;  /*!< [15..0] High-pass filter coefficient s(0)                                 */
#else
            __IOM uint32_t HFS0 : 16;  /*!< [15..0] High-pass filter coefficient s(0)                                 */
            uint32_t            : 16;
#endif
        } PDHFCS0R_b;
    };

    union
    {
        __IOM uint32_t PDHFCK1R;       /*!< (@ 0x0000002C) High-pass filter Coefficient k(1) Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __IOM uint32_t HFK1 : 16;  /*!< [15..0] High-pass filter coefficient k(1)                                 */
#else
            __IOM uint32_t HFK1 : 16;  /*!< [15..0] High-pass filter coefficient k(1)                                 */
            uint32_t            : 16;
#endif
        } PDHFCK1R_b;
    };

    union
    {
        __IOM uint32_t PDHFCHR[2];     /*!< (@ 0x00000030) High-pass filter Coefficient h([0..1]) Registers           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __IOM uint32_t HFHn : 16;  /*!< [15..0] High-pass filter coefficient h(n)                                 */
#else
            __IOM uint32_t HFHn : 16;  /*!< [15..0] High-pass filter coefficient h(n)                                 */
            uint32_t            : 16;
#endif
        } PDHFCHR_b[2];
    };

    union
    {
        __IOM uint32_t PDCFCHR[11];    /*!< (@ 0x00000038) Compensation filter Coefficient h([0..10]) Registers       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 19;
            __IOM uint32_t CFHn : 13;  /*!< [12..0] Compensation filter coefficient h(n)                              */
#else
            __IOM uint32_t CFHn : 13;  /*!< [12..0] Compensation filter coefficient h(n)                              */
            uint32_t            : 19;
#endif
        } PDCFCHR_b[11];
    };

    union
    {
        __IOM uint32_t PDLFCH010R;     /*!< (@ 0x00000064) Low-pass filter Coefficient h0(10) Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 19;
            __IOM uint32_t LFH010 : 13; /*!< [12..0] Low-pass (half-band decimation) filter coefficient h0(10)         */
#else
            __IOM uint32_t LFH010 : 13; /*!< [12..0] Low-pass (half-band decimation) filter coefficient h0(10)         */
            uint32_t              : 19;
#endif
        } PDLFCH010R_b;
    };

    union
    {
        __IOM uint32_t PDLFCH1R[20];   /*!< (@ 0x00000068) Low-pass filter Coefficient h1([0..19]) Registers          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 19;
            __IOM uint32_t LFH1n : 13; /*!< [12..0] Low-pass (half-band decimation) filter coefficient h1(n)          */
#else
            __IOM uint32_t LFH1n : 13; /*!< [12..0] Low-pass (half-band decimation) filter coefficient h1(n)          */
            uint32_t             : 19;
#endif
        } PDLFCH1R_b[20];
    };

    union
    {
        __IOM uint32_t PDSDLTR;        /*!< (@ 0x000000B8) Sound Detection Lower Threshold Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 12;
            __IOM uint32_t SDETL : 20; /*!< [19..0] Sound detection lower limit                                       */
#else
            __IOM uint32_t SDETL : 20; /*!< [19..0] Sound detection lower limit                                       */
            uint32_t             : 12;
#endif
        } PDSDLTR_b;
    };

    union
    {
        __IOM uint32_t PDSDUTR;        /*!< (@ 0x000000BC) Sound Detection Upper Threshold Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 12;
            __IOM uint32_t SDETU : 20; /*!< [19..0] Sound detection upper limit                                       */
#else
            __IOM uint32_t SDETU : 20; /*!< [19..0] Sound detection upper limit                                       */
            uint32_t             : 12;
#endif
        } PDSDUTR_b;
    };

    union
    {
        __IOM uint32_t PDDBCR;         /*!< (@ 0x000000C0) Data Buffer Control Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 29;
            __IOM uint32_t DATRITHR : 3; /*!< [2..0] Data reception interrupt threshold                                 */
#else
            __IOM uint32_t DATRITHR : 3; /*!< [2..0] Data reception interrupt threshold                                 */
            uint32_t                : 29;
#endif
        } PDDBCR_b;
    };

    union
    {
        __IOM uint32_t PDSCTSR;        /*!< (@ 0x000000C4) Short Circuit Threshold Setting Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 3;
            __IOM uint32_t SCDH : 13;  /*!< [28..16] Short circuit detection High Continuous detection count          */
            uint32_t            : 3;
            __IOM uint32_t SCDL : 13;  /*!< [12..0] Short circuit detection Low Continuous detection count            */
#else
            __IOM uint32_t SCDL : 13;  /*!< [12..0] Short circuit detection Low Continuous detection count            */
            uint32_t            : 3;
            __IOM uint32_t SCDH : 13;  /*!< [28..16] Short circuit detection High Continuous detection count          */
            uint32_t            : 3;
#endif
        } PDSCTSR_b;
    };

    union
    {
        __IOM uint32_t PDOVLTR;        /*!< (@ 0x000000C8) Overvoltage Lower Threshold Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 12;
            __IOM uint32_t OVDL : 20;  /*!< [19..0] Overvoltage detection lower limit                                 */
#else
            __IOM uint32_t OVDL : 20;  /*!< [19..0] Overvoltage detection lower limit                                 */
            uint32_t            : 12;
#endif
        } PDOVLTR_b;
    };

    union
    {
        __IOM uint32_t PDOVUTR;        /*!< (@ 0x000000CC) Overvoltage Upper Threshold Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 12;
            __IOM uint32_t OVDU : 20;  /*!< [19..0] Overvoltage detection upper limit                                 */
#else
            __IOM uint32_t OVDU : 20;  /*!< [19..0] Overvoltage detection upper limit                                 */
            uint32_t            : 12;
#endif
        } PDOVUTR_b;
    };
    __IM uint32_t RESERVED1[4];

    union
    {
        __IOM uint32_t PDDRCR;         /*!< (@ 0x000000E0) Data Read Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 31;
            __IOM uint32_t DATRE : 1;  /*!< [0..0] Data read enable bit                                               */
#else
            __IOM uint32_t DATRE : 1;  /*!< [0..0] Data read enable bit                                               */
            uint32_t             : 31;
#endif
        } PDDRCR_b;
    };

    union
    {
        __OM uint32_t PDDCR;           /*!< (@ 0x000000E4) Data Clear Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __OM uint32_t DATC : 1;    /*!< [0..0] Data clear                                                         */
#else
            __OM uint32_t DATC : 1;    /*!< [0..0] Data clear                                                         */
            uint32_t           : 31;
#endif
        } PDDCR_b;
    };

    union
    {
        __IM uint32_t PDDRR;           /*!< (@ 0x000000E8) Data Read Register                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 12;
            __IM uint32_t DAT : 20;    /*!< [19..0] Data                                                              */
#else
            __IM uint32_t DAT : 20;    /*!< [19..0] Data                                                              */
            uint32_t          : 12;
#endif
        } PDDRR_b;
    };

    union
    {
        __IM uint32_t PDDSR;           /*!< (@ 0x000000EC) Data Status Register                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 24;
            __IM uint32_t DATNUM : 8;  /*!< [7..0] Number of data stored in buffer                                    */
#else
            __IM uint32_t DATNUM : 8;  /*!< [7..0] Number of data stored in buffer                                    */
            uint32_t             : 24;
#endif
        } PDDSR_b;
    };
    __IM uint32_t RESERVED2[4];
} R_PDM_CH_Type;                       /*!< Size = 256 (0x100) */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_PDM                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Pulse Density Modulator Interface (R_PDM)
 */

typedef struct                         /*!< (@ 0x87856000) R_PDM Structure                                            */
{
    union
    {
        __OM uint32_t PDCSTRTR;        /*!< (@ 0x00000000) Channel Software Start Trigger Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 31;
            __OM uint32_t STRTRG0 : 1; /*!< [0..0] Channel 0 start trigger                                            */
#else
            __OM uint32_t STRTRG0 : 1; /*!< [0..0] Channel 0 start trigger                                            */
            uint32_t              : 31;
#endif
        } PDCSTRTR_b;
    };

    union
    {
        __OM uint32_t PDCSTPTR;        /*!< (@ 0x00000004) Channel Software Stop Trigger Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 31;
            __OM uint32_t STPTRG0 : 1; /*!< [0..0] Channel 0 stop trigger                                             */
#else
            __OM uint32_t STPTRG0 : 1; /*!< [0..0] Channel 0 stop trigger                                             */
            uint32_t              : 31;
#endif
        } PDCSTPTR_b;
    };

    union
    {
        __OM uint32_t PDCCHGTR;        /*!< (@ 0x00000008) Channel Software Change Trigger Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 31;
            __OM uint32_t CHGTRG0 : 1; /*!< [0..0] Channel 0 change trigger                                           */
#else
            __OM uint32_t CHGTRG0 : 1; /*!< [0..0] Channel 0 change trigger                                           */
            uint32_t              : 31;
#endif
        } PDCCHGTR_b;
    };

    union
    {
        __IOM uint32_t PDCICR;         /*!< (@ 0x0000000C) Channel Interrupt Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 7;
            __IOM uint32_t IEDE0 : 1;  /*!< [24..24] Channel 0 error detection interrupt enable bit                   */
            uint32_t             : 7;
            __IOM uint32_t IDRE0 : 1;  /*!< [16..16] Channel 0 data reception interrupt enable bit                    */
            uint32_t             : 7;
            __IOM uint32_t ISDE0 : 1;  /*!< [8..8] Channel 0 sound detection interrupt enable bit                     */
            uint32_t             : 8;
#else
            uint32_t             : 8;
            __IOM uint32_t ISDE0 : 1;  /*!< [8..8] Channel 0 sound detection interrupt enable bit                     */
            uint32_t             : 7;
            __IOM uint32_t IDRE0 : 1;  /*!< [16..16] Channel 0 data reception interrupt enable bit                    */
            uint32_t             : 7;
            __IOM uint32_t IEDE0 : 1;  /*!< [24..24] Channel 0 error detection interrupt enable bit                   */
            uint32_t             : 7;
#endif
        } PDCICR_b;
    };

    union
    {
        __IM uint32_t PDCSR;           /*!< (@ 0x00000010) Channel Status Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 7;
            __IM uint32_t EDF0   : 1;  /*!< [24..24] Channel 0 error detection flag                                   */
            uint32_t             : 7;
            __IM uint32_t DRF0   : 1;  /*!< [16..16] Channel 0 data reception flag                                    */
            uint32_t             : 7;
            __IM uint32_t SDF0   : 1;  /*!< [8..8] Channel 0 sound detection flag                                     */
            uint32_t             : 7;
            __IM uint32_t STATE0 : 1;  /*!< [0..0] Channel 0 state                                                    */
#else
            __IM uint32_t STATE0 : 1;  /*!< [0..0] Channel 0 state                                                    */
            uint32_t             : 7;
            __IM uint32_t SDF0   : 1;  /*!< [8..8] Channel 0 sound detection flag                                     */
            uint32_t             : 7;
            __IM uint32_t DRF0   : 1;  /*!< [16..16] Channel 0 data reception flag                                    */
            uint32_t             : 7;
            __IM uint32_t EDF0   : 1;  /*!< [24..24] Channel 0 error detection flag                                   */
            uint32_t             : 7;
#endif
        } PDCSR_b;
    };

    union
    {
        __OM uint32_t PDCSCR;          /*!< (@ 0x00000014) Channel Status Clear Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 23;
            __OM uint32_t SDFC0 : 1;   /*!< [8..8] Channel 0 sound detection flag clear                               */
            uint32_t            : 8;
#else
            uint32_t            : 8;
            __OM uint32_t SDFC0 : 1;   /*!< [8..8] Channel 0 sound detection flag clear                               */
            uint32_t            : 23;
#endif
        } PDCSCR_b;
    };
    __IM uint32_t RESERVED[2];

    union
    {
        __IOM uint32_t PDCSDCR;        /*!< (@ 0x00000020) Channel Sound Detection Control Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t SDE0 : 1;   /*!< [0..0] Channel 0 sound detection enable bit                               */
#else
            __IOM uint32_t SDE0 : 1;   /*!< [0..0] Channel 0 sound detection enable bit                               */
            uint32_t            : 31;
#endif
        } PDCSDCR_b;
    };

    union
    {
        __IOM uint32_t PDCDRCR;        /*!< (@ 0x00000024) Channel Data Read Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 31;
            __IOM uint32_t DATRE0 : 1; /*!< [0..0] Channel 0 data read enable bit                                     */
#else
            __IOM uint32_t DATRE0 : 1; /*!< [0..0] Channel 0 data read enable bit                                     */
            uint32_t              : 31;
#endif
        } PDCDRCR_b;
    };

    union
    {
        __OM uint32_t PDCDCR;          /*!< (@ 0x00000028) Channel Data Clear Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __OM uint32_t DATC0 : 1;   /*!< [0..0] Channel 0 data clear                                               */
#else
            __OM uint32_t DATC0 : 1;   /*!< [0..0] Channel 0 data clear                                               */
            uint32_t            : 31;
#endif
        } PDCDCR_b;
    };
    __IM uint32_t RESERVED1[21];

    union
    {
        __IM uint32_t PDVR;            /*!< (@ 0x00000080) Version Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 20;
            __IM uint32_t VER : 12;    /*!< [11..0] Version                                                           */
#else
            __IM uint32_t VER : 12;    /*!< [11..0] Version                                                           */
            uint32_t          : 20;
#endif
        } PDVR_b;
    };
    __IM uint32_t       RESERVED2[31];
    __IOM R_PDM_CH_Type CH[1];         /*!< (@ 0x00000100) PDM Channel-Specific Registers                            */
} R_PDM_Type;                          /*!< Size = 512 (0x200)                                                       */

#endif /* R_PDM_REG_H */
