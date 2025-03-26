/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : mstp_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for mstp.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef MSTP_IODEFINE_H
#define MSTP_IODEFINE_H

typedef struct                              /*!< (@ 0x11010B60) R_MSTP Structure                                           */
{
    union
    {
        __IOM uint32_t ACPU;                /*!< (@ 0x11010B60) ACPU Register */

        struct
        {
            __IOM uint32_t MXSRAM_A    : 1; /*!< [ 0.. 0] Module Stop of MXSRAM_A  */
            uint32_t                   : 15;
            __IOM uint32_t MXSRAM_A_WE : 1; /*!< [16..16] Write Enable of MXSRAM_A */
            uint32_t                   : 15;
        } ACPU_b;
    };

    union
    {
        __IOM uint32_t MCPU1;               /*!< (@ 0x11010B64) MCPU1 Register */

        struct
        {
            __IOM uint32_t MXSRAM_M    : 1; /*!< [ 0.. 0] Module Stop of MXSRAM_M    */
            __IOM uint32_t MHSPI       : 1; /*!< [ 1.. 1] Module Stop of MHSPI       */
            __IOM uint32_t MHMTU3A     : 1; /*!< [ 2.. 2] Module Stop of MHMTU3A     */
            __IOM uint32_t MHSRC       : 1; /*!< [ 3.. 3] Module Stop of MHSRC       */
            uint32_t                   : 5;
            __IOM uint32_t MHPOE3      : 1; /*!< [ 9.. 9] Module Stop of MHPOE3      */
            __IOM uint32_t MHSSIF0     : 1; /*!< [10..10] Module Stop of MHSSIF0     */
            uint32_t                   : 3;
            __IOM uint32_t MHRSPI0     : 1; /*!< [14..14] Module Stop of MHRSPI0     */
            __IOM uint32_t MHRSPI1     : 1; /*!< [15..15] Module Stop of MHRSPI1     */
            __IOM uint32_t MXSRAM_M_WE : 1; /*!< [16..16] Write Enable of MXSRAM_M   */
            __IOM uint32_t MHSPI_WE    : 1; /*!< [17..17] Write Enable of MHSPI      */
            __IOM uint32_t MHMTU3A_WE  : 1; /*!< [18..18] Write Enable of MHMTU3A    */
            __IOM uint32_t MHSRC_WE    : 1; /*!< [19..19] Write Enable of MHSRC      */
            uint32_t                   : 5;
            __IOM uint32_t MHPOE3_WE   : 1; /*!< [25..25] Write Enable of MHPOE3     */
            __IOM uint32_t MHSSIF0_WE  : 1; /*!< [26..26] Write Enable of MHSSIF0    */
            uint32_t                   : 3;
            __IOM uint32_t MHRSPI0_WE  : 1; /*!< [30..30] Write Enable of MHRSPI0    */
            __IOM uint32_t MHRSPI1_WE  : 1; /*!< [31..31] Write Enable of MHRSPI1    */
        } MCPU1_b;
    };

    union
    {
        __IOM uint32_t MCPU2;              /*!< (@ 0x11010B68) MCPU2 Register */

        struct
        {
            uint32_t                  : 1;
            __IOM uint32_t MHSCIF0    : 1; /*!< [ 1.. 1] Module Stop of MHSCIF0  */
            __IOM uint32_t MHSCIF1    : 1; /*!< [ 2.. 2] Module Stop of MHSCIF1  */
            __IOM uint32_t MHSCIF2    : 1; /*!< [ 3.. 3] Module Stop of MHSCIF2  */
            __IOM uint32_t MHSCIF3    : 1; /*!< [ 4.. 4] Module Stop of MHSCIF3  */
            __IOM uint32_t MHSCIF4    : 1; /*!< [ 5.. 5] Module Stop of MHSCIF4  */
            __IOM uint32_t MHIRDA     : 1; /*!< [ 6.. 6] Module Stop of MHIRDA   */
            __IOM uint32_t MHSCI0     : 1; /*!< [ 7.. 7] Module Stop of MHSCI0   */
            __IOM uint32_t MHSCI1     : 1; /*!< [ 8.. 8] Module Stop of MHSCI1   */
            uint32_t                  : 1;
            __IOM uint32_t MPI2C0     : 1; /*!< [10..10] Module Stop of MPI2C0   */
            __IOM uint32_t MPI2C1     : 1; /*!< [11..11] Module Stop of MPI2C1   */
            uint32_t                  : 3;
            __IOM uint32_t MPTSU      : 1; /*!< [15..15] Module Stop of MPTSU    */
            uint32_t                  : 1;
            __IOM uint32_t MHSCIF0_WE : 1; /*!< [17..17] Write Enable of MHSCIF0 */
            __IOM uint32_t MHSCIF1_WE : 1; /*!< [18..18] Write Enable of MHSCIF1 */
            __IOM uint32_t MHSCIF2_WE : 1; /*!< [19..19] Write Enable of MHSCIF2 */
            __IOM uint32_t MHSCIF3_WE : 1; /*!< [20..20] Write Enable of MHSCIF3 */
            __IOM uint32_t MHSCIF4_WE : 1; /*!< [21..21] Write Enable of MHSCIF4 */
            __IOM uint32_t MHIRDA_WE  : 1; /*!< [22..22] Write Enable of MHIRDA  */
            __IOM uint32_t MHSCI0_WE  : 1; /*!< [23..23] Write Enable of MHSCI0  */
            __IOM uint32_t MHSCI1_WE  : 1; /*!< [24..24] Write Enable of MHSCI1  */
            uint32_t                  : 1;
            __IOM uint32_t MPI2C0_WE  : 1; /*!< [26..26] Write Enable of MPI2C0  */
            __IOM uint32_t MPI2C1_WE  : 1; /*!< [27..27] Write Enable of MPI2C1  */
            uint32_t                  : 3;
            __IOM uint32_t MPTSU_WE   : 1; /*!< [31..31] Write Enable of MPTSU   */
        } MCPU2_b;
    };

    union
    {
        __IOM uint32_t PERI_COM;           /*!< (@ 0x11010B6C) PERI_COM Register */

        struct
        {
            __IOM uint32_t MXSDHI0    : 1; /*!< [ 0.. 0] Module Stop of MXSDHI0  */
            uint32_t                  : 3;
            __IOM uint32_t MPUSBT     : 1; /*!< [ 4.. 4] Module Stop of MPUSBT   */
            __IOM uint32_t MHUSB2H    : 1; /*!< [ 5.. 5] Module Stop of MHUSB2H  */
            __IOM uint32_t MHUSB2F    : 1; /*!< [ 6.. 6] Module Stop of MHUSB2F  */
            uint32_t                  : 1;            
            __IOM uint32_t MXCOM8     : 1; /*!< [ 8.. 8] Module Stop of MXCOM8   */
            __IOM uint32_t MXCOM9     : 1; /*!< [ 9.. 9] Module Stop of MXCOM9   */
            uint32_t                  : 6;
            __IOM uint32_t MXSDHI0_WE : 1; /*!< [16..16] Write Enable of MXSDHI0 */
            uint32_t                  : 3;
            __IOM uint32_t MPUSBT_WE  : 1; /*!< [20..20] Write Enable of MPUSBT  */
            __IOM uint32_t MHUSB2H_WE : 1; /*!< [21..21] Write Enable of MHUSB2H */
            __IOM uint32_t MHUSB2F_WE : 1; /*!< [22..22] Write Enable of MHUSB2F */
            uint32_t                  : 1;             
            __IOM uint32_t MXCOM8_WE  : 1; /*!< [24..24] Write Enable of MXCOM8  */
            __IOM uint32_t MXCOM9_WE  : 1; /*!< [25..25] Write Enable of MXCOM9  */
            uint32_t                  : 6;
        } PERI_COM_b;
    };

    union
    {
        __IOM uint32_t PERI_CPU;            /*!< (@ 0x11010B70) PERI_CPU Register */

        struct
        {
            __IOM uint32_t MXMCPU      : 1; /*!< [ 0.. 0] Module Stop of MXMCPU    */
            __IOM uint32_t MXACPU      : 1; /*!< [ 1.. 1] Module Stop of MXACPU    */
            __IOM uint32_t MPCST       : 1; /*!< [ 2.. 2] Module Stop of MPCST     */
            __IOM uint32_t MPSYC       : 1; /*!< [ 3.. 3] Module Stop of MPSYC     */
            __IOM uint32_t MPCPG       : 1; /*!< [ 4.. 4] Module Stop of MPCPG     */
            uint32_t                   : 1;
            __IOM uint32_t MHGPIO      : 1; /*!< [ 6.. 6] Module Stop of MHGPIO    */
            uint32_t                   : 4;
            __IOM uint32_t MPSRAM_A    : 1; /*!< [11..11] Module Stop of MPSRAM_A  */
            __IOM uint32_t MPSRAM_M    : 1; /*!< [12..12] Module Stop of MPSRAM_M  */
            __IOM uint32_t MPIA55      : 1; /*!< [13..13] Module Stop of MPIA55    */
            uint32_t                   : 1;
            __IOM uint32_t MXREG0      : 1; /*!< [15..15] Module Stop of MXREG0    */
            __IOM uint32_t MXMCPU_WE   : 1; /*!< [16..16] Write Enable of MXMCPU   */
            __IOM uint32_t MXACPU_WE   : 1; /*!< [17..17] Write Enable of MXACPU   */
            __IOM uint32_t MPCST_WE    : 1; /*!< [18..18] Write Enable of MPCST    */
            __IOM uint32_t MPSYC_WE    : 1; /*!< [19..19] Write Enable of MPSYC    */
            __IOM uint32_t MPCPG_WE    : 1; /*!< [20..20] Write Enable of MPCPG    */
            uint32_t                   : 1;
            __IOM uint32_t MHGPIO_WE   : 1; /*!< [22..22] Write Enable of MHGPIO   */
            uint32_t                   : 4;
            __IOM uint32_t MPSRAM_A_WE : 1; /*!< [27..27] Write Enable of MPSRAM_A */
            __IOM uint32_t MPSRAM_M_WE : 1; /*!< [28..28] Write Enable of MPSRAM_M */
            __IOM uint32_t MPIA55_WE   : 1; /*!< [29..29] Write Enable of MPIA55   */
            uint32_t                   : 1;
            __IOM uint32_t MXREG0_WE   : 1; /*!< [31..31] Write Enable of MXREG0   */
        } PERI_CPU_b;
    };

    union
    {
        __IOM uint32_t PERI_DDR;              /*!< (@ 0x11010B74) PERI_DDR Register */

        struct
        {
            __IOM uint32_t MPPHY         : 1; /*!< [ 0.. 0] Module Stop of MPPHY       */
            __IOM uint32_t MXMEMC_REG    : 1; /*!< [ 1.. 1] Module Stop of MXMEMC_REG  */
            uint32_t                     : 14;
            __IOM uint32_t MPPHY_WE      : 1; /*!< [16..16] Write Enable of MPPHY      */
            __IOM uint32_t MXMEMC_REG_WE : 1; /*!< [17..17] Write Enable of MXMEMC_REG */
            uint32_t                     : 14;
        } PERI_DDR_b;
    };

    union
    {
        __IOM uint32_t PERI_VIDEO;     /*!< (@ 0x11010B78) PERI_VIDEO Register */

        struct
        {
            uint32_t                  : 5;
            __IOM uint32_t MPDSIPHY   : 1; /*!< [ 5.. 5] Module Stop of MPDSIPHY   */
            __IOM uint32_t MPDSIL     : 1; /*!< [ 6.. 6] Module Stop of MPDSIL     */
            __IOM uint32_t MPVSPD     : 1; /*!< [ 7.. 7] Module Stop of MPVSPD     */
            __IOM uint32_t MPCPVD     : 1; /*!< [ 8.. 8] Module Stop of MPCPVD     */
            __IOM uint32_t MPDU       : 1; /*!< [ 9.. 9] Module Stop of MPDU       */
            __IOM uint32_t MXVIDEO    : 1; /*!< [10..10] Module Stop of MXVIDEO    */
            uint32_t                  : 10;
            __IOM uint32_t MPDSIPHY_WE: 1; /*!< [21..21] Write Enable of MPDSIPHY  */
            __IOM uint32_t MPDSIL_WE  : 1; /*!< [22..22] Write Enable of MPDSIL    */  
            __IOM uint32_t MPVSPD_WE  : 1; /*!< [23..23] Write Enable of MPVSPD    */
            __IOM uint32_t MPCPVD_WE  : 1; /*!< [24..24] Write Enable of MPCPVD    */
            __IOM uint32_t MPDU_WE    : 1; /*!< [25..25] Write Enable of MPDU      */
            __IOM uint32_t MXVIDEO_WE : 1; /*!< [26..26] Write Enable of MXVIDEO   */
            uint32_t                  : 5;
        } PERI_VIDEO_b;
    };

    union
    {
        __IOM uint32_t REG0;           /*!< (@ 0x11010B7C) REG0 Register */

        struct
        {
            uint32_t                  : 2;
            __IOM uint32_t MPWDT0     : 1; /*!< [ 2.. 2] Module Stop of MPWDT0   */
            uint32_t                  : 1;
            __IOM uint32_t MPOSTM0    : 1; /*!< [ 4.. 4] Module Stop of MPOSTM0  */
            __IOM uint32_t MPOSTM1    : 1; /*!< [ 5.. 5] Module Stop of MPOSTM1  */
            __IOM uint32_t MPOSTM2    : 1; /*!< [ 6.. 6] Module Stop of MPOSTM2  */
            uint32_t                  : 11;
            __IOM uint32_t MPWDT0_WE  : 1; /*!< [18..18] Write Enable of MPWDT0  */
            uint32_t                  : 1;
            __IOM uint32_t MPOSTM0_WE : 1; /*!< [20..20] Write Enable of MPOSTM0 */
            __IOM uint32_t MPOSTM1_WE : 1; /*!< [21..21] Write Enable of MPOSTM1 */
            __IOM uint32_t MPOSTM2_WE : 1; /*!< [22..22] Write Enable of MPOSTM2 */
            uint32_t                  : 9;
        } REG0_b;
    };

    union
    {
        __IOM uint32_t REG1;                 /*!< (@ 0x11010B80) REG1 Register */

        struct
        {
            __IOM uint32_t MXDMAC_S     : 1; /*!< [ 0.. 0] Module Stop of MXDMAC_S     */
            __IOM uint32_t MPDMAC_S     : 1; /*!< [ 1.. 1] Module Stop of MPDMAC_S     */
            __IOM uint32_t MXDMAC_NS    : 1; /*!< [ 2.. 2] Module Stop of MXDMAC_NS    */
            __IOM uint32_t MPDMAC_NS    : 1; /*!< [ 3.. 3] Module Stop of MPDMAC_NS    */
            uint32_t                    : 3;
            __IOM uint32_t MXGIC        : 1; /*!< [ 7.. 7] Module Stop of MXGIC        */
            uint32_t                    : 8;
            __IOM uint32_t MXDMAC_S_WE  : 1; /*!< [16..16] Write Enable of MXDMAC_S    */
            __IOM uint32_t MPDMAC_S_WE  : 1; /*!< [17..17] Write Enable of MPDMAC_S    */
            __IOM uint32_t MXDMAC_NS_WE : 1; /*!< [18..18] Write Enable of MXDMAC_NS   */
            __IOM uint32_t MPDMAC_NS_WE : 1; /*!< [19..19] Write Enable of MPDMAC_NS   */
            uint32_t                    : 3;
            __IOM uint32_t MXGIC_WE     : 1; /*!< [23..23] Write Enable of MXGIC       */
            uint32_t                    : 8;
        } REG1_b;
    };
} R_MSTOP_Type;                            /*!< Size = 44 (0x2C)                                                          */

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_MSTP_BASE    0x11010B60      /* Module Stop Control   */

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_MSTP    ((R_MSTOP_Type *) R_MSTP_BASE)

#endif                                 /* MSTP_IODEFINE_H */
