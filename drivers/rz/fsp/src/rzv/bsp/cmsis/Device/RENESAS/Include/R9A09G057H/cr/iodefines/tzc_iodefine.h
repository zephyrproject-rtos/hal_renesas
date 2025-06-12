/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : tzc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for tzc.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef TZC400_IODEFINE_H
#define TZC400_IODEFINE_H

typedef struct
{
    union
    {
        __IM uint32_t BUILD_CONFIG;
        struct
        {
            __IM uint32_t NOR   : 5;
            uint32_t            : 3;
            __IM uint32_t ADDRW : 6;
            uint32_t            : 10;
            __IM uint32_t NOF   : 2;
            uint32_t            : 6;
        } BUILD_CONFIG_b;
    };
    union
    {
        __IOM uint32_t ACTION;
        struct
        {
            __IOM uint32_t RV : 2;
            uint32_t          : 30;
        } ACTION_b;
    };
    union
    {
        __IOM uint32_t GATE_KEEPER;
        struct
        {
            __IOM uint32_t OR : 4;
            uint32_t          : 12;
            __IOM uint32_t OS : 4;
            uint32_t          : 12;
        } GATE_KEEPER_b;
    };
    union
    {
        __IOM uint32_t SPECULATION_CTRL;
        struct
        {
            __IOM uint32_t RSD : 1;
            __IOM uint32_t WSD : 1;
            uint32_t           : 30;
        } SPECULATION_CTRL_b;
    };
    union
    {
        __IM uint32_t INT_STATUS;
        struct
        {
            __IM uint32_t STS     : 4;
            uint32_t              : 4;
            __IM uint32_t OVERRUN : 4;
            uint32_t              : 4;
            __IM uint32_t OVERLAP : 4;
            uint32_t              : 12;
        } INT_STATUS_b;
    };
    union
    {
        __OM uint32_t INT_CLEAR;
        struct
        {
            __OM uint32_t CLEAR : 4;
            uint32_t            : 28;
        } INT_CLEAR_b;
    };
    __IM uint8_t RESERVED[8];
    union
    {
        __IM uint32_t FAIL_ADDRESS_LOW_0;
        struct
        {
            __IM uint32_t ASL : 32;
        } FAIL_ADDRESS_LOW_0_b;
    };
    union
    {
        __IM uint32_t FAIL_ADDRESS_HIGH_0;
        struct
        {
            __IM uint32_t ASH : 1;
            uint32_t          : 31;
        } FAIL_ADDRESS_HIGH_0_b;
    };
    union
    {
        __IM uint32_t FAIL_CONTROL_0;
        struct
        {
            uint32_t         : 20;
            __IM uint32_t PL : 1;
            __IM uint32_t NS : 1;
            uint32_t         : 2;
            __IM uint32_t DC : 1;
            uint32_t         : 7;
        } FAIL_CONTROL_0_b;
    };
    union
    {
        __IM uint32_t FAIL_ID_0;
        struct
        {
            __IM uint32_t ID   : 1;
            uint32_t           : 23;
            __IM uint32_t VNET : 4;
            uint32_t           : 4;
        } FAIL_ID_0_b;
    };
    union
    {
        __IM uint32_t FAIL_ADDRESS_LOW_1;
        struct
        {
            __IM uint32_t ASL : 32;
        } FAIL_ADDRESS_LOW_1_b;
    };
    union
    {
        __IM uint32_t FAIL_ADDRESS_HIGH_1;
        struct
        {
            __IM uint32_t ASH : 1;
            uint32_t          : 31;
        } FAIL_ADDRESS_HIGH_1_b;
    };
    union
    {
        __IM uint32_t FAIL_CONTROL_1;
        struct
        {
            uint32_t         : 20;
            __IM uint32_t PL : 1;
            __IM uint32_t NS : 1;
            uint32_t         : 2;
            __IM uint32_t DC : 1;
            uint32_t         : 7;
        } FAIL_CONTROL_1_b;
    };
    union
    {
        __IM uint32_t FAIL_ID_1;
        struct
        {
            __IM uint32_t ID   : 1;
            uint32_t           : 23;
            __IM uint32_t VNET : 4;
            uint32_t           : 4;
        } FAIL_ID_1_b;
    };
    union
    {
        __IM uint32_t FAIL_ADDRESS_LOW_2;
        struct
        {
            __IM uint32_t ASL : 32;
        } FAIL_ADDRESS_LOW_2_b;
    };
    union
    {
        __IM uint32_t FAIL_ADDRESS_HIGH_2;
        struct
        {
            __IM uint32_t ASH : 1;
            uint32_t          : 31;
        } FAIL_ADDRESS_HIGH_2_b;
    };
    union
    {
        __IM uint32_t FAIL_CONTROL_2;
        struct
        {
            uint32_t         : 20;
            __IM uint32_t PL : 1;
            __IM uint32_t NS : 1;
            uint32_t         : 2;
            __IM uint32_t DC : 1;
            uint32_t         : 7;
        } FAIL_CONTROL_2_b;
    };
    union
    {
        __IM uint32_t FAIL_ID_2;
        struct
        {
            __IM uint32_t ID   : 1;
            uint32_t           : 23;
            __IM uint32_t VNET : 4;
            uint32_t           : 4;
        } FAIL_ID_2_b;
    };
    union
    {
        __IM uint32_t FAIL_ADDRESS_LOW_3;
        struct
        {
            __IM uint32_t ASL : 32;
        } FAIL_ADDRESS_LOW_3_b;
    };
    union
    {
        __IM uint32_t FAIL_ADDRESS_HIGH_3;
        struct
        {
            __IM uint32_t ASH : 1;
            uint32_t          : 31;
        } FAIL_ADDRESS_HIGH_3_b;
    };
    union
    {
        __IM uint32_t FAIL_CONTROL_3;
        struct
        {
            uint32_t         : 20;
            __IM uint32_t PL : 1;
            __IM uint32_t NS : 1;
            uint32_t         : 2;
            __IM uint32_t DC : 1;
            uint32_t         : 7;
        } FAIL_CONTROL_3_b;
    };
    union
    {
        __IM uint32_t FAIL_ID_3;
        struct
        {
            __IM uint32_t ID   : 1;
            uint32_t           : 23;
            __IM uint32_t VNET : 4;
            uint32_t           : 4;
        } FAIL_ID_3_b;
    };
    __IM uint8_t RESERVED1[160];
    union
    {
        __IM uint32_t REGION_BASE_LOW_0;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t BAL : 20;
        } REGION_BASE_LOW_0_b;
    };
    union
    {
        __IM uint32_t REGION_BASE_HIGH_0;
        struct
        {
            __IM uint32_t BAH : 1;
            uint32_t          : 31;
        } REGION_BASE_HIGH_0_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_LOW_0;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t TAL : 20;
        } REGION_TOP_LOW_0_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_HIGH_0;
        struct
        {
            __IM uint32_t TAH : 1;
            uint32_t          : 31;
        } REGION_TOP_HIGH_0_b;
    };
    union
    {
        __IOM uint32_t REGION_ATTRIBUTES_0;
        struct
        {
            __IOM uint32_t FE  : 4;
            uint32_t           : 26;
            __IOM uint32_t SRE : 1;
            __IOM uint32_t SWE : 1;
        } REGION_ATTRIBUTES_0_b;
    };
    union
    {
        __IOM uint32_t REGION_ID_ACCESS_0;
        struct
        {
            __IOM uint32_t NRE : 16;
            __IOM uint32_t NWE : 16;
        } REGION_ID_ACCESS_0_b;
    };
    __IM uint8_t RESERVED2[8];
    union
    {
        __IM uint32_t REGION_BASE_LOW_1;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t BAL : 20;
        } REGION_BASE_LOW_1_b;
    };
    union
    {
        __IM uint32_t REGION_BASE_HIGH_1;
        struct
        {
            __IM uint32_t BAH : 2;
            uint32_t          : 30;
        } REGION_BASE_HIGH_1_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_LOW_1;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t TAL : 20;
        } REGION_TOP_LOW_1_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_HIGH_1;
        struct
        {
            __IM uint32_t TAH : 2;
            uint32_t          : 30;
        } REGION_TOP_HIGH_1_b;
    };
    union
    {
        __IOM uint32_t REGION_ATTRIBUTES_1;
        struct
        {
            __IOM uint32_t FE  : 4;
            uint32_t           : 26;
            __IOM uint32_t SRE : 1;
            __IOM uint32_t SWE : 1;
        } REGION_ATTRIBUTES_1_b;
    };
    union
    {
        __IOM uint32_t REGION_ID_ACCESS_1;
        struct
        {
            __IOM uint32_t NRE : 16;
            __IOM uint32_t NWE : 16;
        } REGION_ID_ACCESS_1_b;
    };
    __IM uint8_t RESERVED3[8];
    union
    {
        __IM uint32_t REGION_BASE_LOW_2;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t BAL : 20;
        } REGION_BASE_LOW_2_b;
    };
    union
    {
        __IM uint32_t REGION_BASE_HIGH_2;
        struct
        {
            __IM uint32_t BAH : 3;
            uint32_t          : 29;
        } REGION_BASE_HIGH_2_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_LOW_2;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t TAL : 20;
        } REGION_TOP_LOW_2_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_HIGH_2;
        struct
        {
            __IM uint32_t TAH : 3;
            uint32_t          : 29;
        } REGION_TOP_HIGH_2_b;
    };
    union
    {
        __IOM uint32_t REGION_ATTRIBUTES_2;
        struct
        {
            __IOM uint32_t FE  : 4;
            uint32_t           : 26;
            __IOM uint32_t SRE : 1;
            __IOM uint32_t SWE : 1;
        } REGION_ATTRIBUTES_2_b;
    };
    union
    {
        __IOM uint32_t REGION_ID_ACCESS_2;
        struct
        {
            __IOM uint32_t NRE : 16;
            __IOM uint32_t NWE : 16;
        } REGION_ID_ACCESS_2_b;
    };
    __IM uint8_t RESERVED4[8];
    union
    {
        __IM uint32_t REGION_BASE_LOW_3;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t BAL : 20;
        } REGION_BASE_LOW_3_b;
    };
    union
    {
        __IM uint32_t REGION_BASE_HIGH_3;
        struct
        {
            __IM uint32_t BAH : 4;
            uint32_t          : 28;
        } REGION_BASE_HIGH_3_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_LOW_3;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t TAL : 20;
        } REGION_TOP_LOW_3_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_HIGH_3;
        struct
        {
            __IM uint32_t TAH : 4;
            uint32_t          : 28;
        } REGION_TOP_HIGH_3_b;
    };
    union
    {
        __IOM uint32_t REGION_ATTRIBUTES_3;
        struct
        {
            __IOM uint32_t FE  : 4;
            uint32_t           : 26;
            __IOM uint32_t SRE : 1;
            __IOM uint32_t SWE : 1;
        } REGION_ATTRIBUTES_3_b;
    };
    union
    {
        __IOM uint32_t REGION_ID_ACCESS_3;
        struct
        {
            __IOM uint32_t NRE : 16;
            __IOM uint32_t NWE : 16;
        } REGION_ID_ACCESS_3_b;
    };
    __IM uint8_t RESERVED5[8];
    union
    {
        __IM uint32_t REGION_BASE_LOW_4;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t BAL : 20;
        } REGION_BASE_LOW_4_b;
    };
    union
    {
        __IM uint32_t REGION_BASE_HIGH_4;
        struct
        {
            __IM uint32_t BAH : 5;
            uint32_t          : 27;
        } REGION_BASE_HIGH_4_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_LOW_4;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t TAL : 20;
        } REGION_TOP_LOW_4_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_HIGH_4;
        struct
        {
            __IM uint32_t TAH : 5;
            uint32_t          : 27;
        } REGION_TOP_HIGH_4_b;
    };
    union
    {
        __IOM uint32_t REGION_ATTRIBUTES_4;
        struct
        {
            __IOM uint32_t FE  : 4;
            uint32_t           : 26;
            __IOM uint32_t SRE : 1;
            __IOM uint32_t SWE : 1;
        } REGION_ATTRIBUTES_4_b;
    };
    union
    {
        __IOM uint32_t REGION_ID_ACCESS_4;
        struct
        {
            __IOM uint32_t NRE : 16;
            __IOM uint32_t NWE : 16;
        } REGION_ID_ACCESS_4_b;
    };
    __IM uint8_t RESERVED6[8];
    union
    {
        __IM uint32_t REGION_BASE_LOW_5;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t BAL : 20;
        } REGION_BASE_LOW_5_b;
    };
    union
    {
        __IM uint32_t REGION_BASE_HIGH_5;
        struct
        {
            __IM uint32_t BAH : 6;
            uint32_t          : 26;
        } REGION_BASE_HIGH_5_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_LOW_5;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t TAL : 20;
        } REGION_TOP_LOW_5_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_HIGH_5;
        struct
        {
            __IM uint32_t TAH : 6;
            uint32_t          : 26;
        } REGION_TOP_HIGH_5_b;
    };
    union
    {
        __IOM uint32_t REGION_ATTRIBUTES_5;
        struct
        {
            __IOM uint32_t FE  : 4;
            uint32_t           : 26;
            __IOM uint32_t SRE : 1;
            __IOM uint32_t SWE : 1;
        } REGION_ATTRIBUTES_5_b;
    };
    union
    {
        __IOM uint32_t REGION_ID_ACCESS_5;
        struct
        {
            __IOM uint32_t NRE : 16;
            __IOM uint32_t NWE : 16;
        } REGION_ID_ACCESS_5_b;
    };
    __IM uint8_t RESERVED7[8];
    union
    {
        __IM uint32_t REGION_BASE_LOW_6;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t BAL : 20;
        } REGION_BASE_LOW_6_b;
    };
    union
    {
        __IM uint32_t REGION_BASE_HIGH_6;
        struct
        {
            __IM uint32_t BAH : 7;
            uint32_t          : 25;
        } REGION_BASE_HIGH_6_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_LOW_6;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t TAL : 20;
        } REGION_TOP_LOW_6_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_HIGH_6;
        struct
        {
            __IM uint32_t TAH : 7;
            uint32_t          : 25;
        } REGION_TOP_HIGH_6_b;
    };
    union
    {
        __IOM uint32_t REGION_ATTRIBUTES_6;
        struct
        {
            __IOM uint32_t FE  : 4;
            uint32_t           : 26;
            __IOM uint32_t SRE : 1;
            __IOM uint32_t SWE : 1;
        } REGION_ATTRIBUTES_6_b;
    };
    union
    {
        __IOM uint32_t REGION_ID_ACCESS_6;
        struct
        {
            __IOM uint32_t NRE : 16;
            __IOM uint32_t NWE : 16;
        } REGION_ID_ACCESS_6_b;
    };
    __IM uint8_t RESERVED8[8];
    union
    {
        __IM uint32_t REGION_BASE_LOW_7;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t BAL : 20;
        } REGION_BASE_LOW_7_b;
    };
    union
    {
        __IM uint32_t REGION_BASE_HIGH_7;
        struct
        {
            __IM uint32_t BAH : 8;
            uint32_t          : 24;
        } REGION_BASE_HIGH_7_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_LOW_7;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t TAL : 20;
        } REGION_TOP_LOW_7_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_HIGH_7;
        struct
        {
            __IM uint32_t TAH : 8;
            uint32_t          : 24;
        } REGION_TOP_HIGH_7_b;
    };
    union
    {
        __IOM uint32_t REGION_ATTRIBUTES_7;
        struct
        {
            __IOM uint32_t FE  : 4;
            uint32_t           : 26;
            __IOM uint32_t SRE : 1;
            __IOM uint32_t SWE : 1;
        } REGION_ATTRIBUTES_7_b;
    };
    union
    {
        __IOM uint32_t REGION_ID_ACCESS_7;
        struct
        {
            __IOM uint32_t NRE : 16;
            __IOM uint32_t NWE : 16;
        } REGION_ID_ACCESS_7_b;
    };
    __IM uint8_t RESERVED9[8];
    union
    {
        __IM uint32_t REGION_BASE_LOW_8;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t BAL : 20;
        } REGION_BASE_LOW_8_b;
    };
    union
    {
        __IM uint32_t REGION_BASE_HIGH_8;
        struct
        {
            __IM uint32_t BAH : 9;
            uint32_t          : 23;
        } REGION_BASE_HIGH_8_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_LOW_8;
        struct
        {
            uint32_t          : 12;
            __IM uint32_t TAL : 20;
        } REGION_TOP_LOW_8_b;
    };
    union
    {
        __IM uint32_t REGION_TOP_HIGH_8;
        struct
        {
            __IM uint32_t TAH : 9;
            uint32_t          : 23;
        } REGION_TOP_HIGH_8_b;
    };
    union
    {
        __IOM uint32_t REGION_ATTRIBUTES_8;
        struct
        {
            __IOM uint32_t FE  : 4;
            uint32_t           : 26;
            __IOM uint32_t SRE : 1;
            __IOM uint32_t SWE : 1;
        } REGION_ATTRIBUTES_8_b;
    };
    union
    {
        __IOM uint32_t REGION_ID_ACCESS_8;
        struct
        {
            __IOM uint32_t NRE : 16;
            __IOM uint32_t NWE : 16;
        } REGION_ID_ACCESS_8_b;
    };
    __IM uint8_t RESERVED10[3512];
    union
    {
        __IM uint32_t PID4;
        struct
        {
            __IM uint32_t JEP106 : 4;
            __IM uint32_t CNT4KB : 4;
            uint32_t             : 24;
        } PID4_b;
    };
    union
    {
        __IM uint32_t PID5;
        struct
        {
            __IM uint32_t JEP106 : 4;
            __IM uint32_t CNT4KB : 4;
            uint32_t             : 24;
        } PID5_b;
    };
    union
    {
        __IM uint32_t PID6;
        struct
        {
            __IM uint32_t JEP106 : 4;
            __IM uint32_t CNT4KB : 4;
            uint32_t             : 24;
        } PID6_b;
    };
    union
    {
        __IM uint32_t PID7;
        struct
        {
            __IM uint32_t JEP106 : 4;
            __IM uint32_t CNT4KB : 4;
            uint32_t             : 24;
        } PID7_b;
    };
    union
    {
        __IM uint32_t PID0;
        struct
        {
            __IM uint32_t JEP106 : 4;
            __IM uint32_t CNT4KB : 4;
            uint32_t             : 24;
        } PID0_b;
    };
    union
    {
        __IM uint32_t PID1;
        struct
        {
            __IM uint32_t JEP106 : 4;
            __IM uint32_t CNT4KB : 4;
            uint32_t             : 24;
        } PID1_b;
    };
    union
    {
        __IM uint32_t PID2;
        struct
        {
            __IM uint32_t JEP106 : 4;
            __IM uint32_t CNT4KB : 4;
            uint32_t             : 24;
        } PID2_b;
    };
    union
    {
        __IM uint32_t PID3;
        struct
        {
            __IM uint32_t JEP106 : 4;
            __IM uint32_t CNT4KB : 4;
            uint32_t             : 24;
        } PID3_b;
    };
    union
    {
        __IM uint32_t CID0;
        struct
        {
            __IM uint32_t CPI0 : 8;
            uint32_t           : 24;
        } CID0_b;
    };
    union
    {
        __IM uint32_t CID1;
        struct
        {
            __IM uint32_t CPI1 : 8;
            uint32_t           : 24;
        } CID1_b;
    };
    union
    {
        __IM uint32_t CID2;
        struct
        {
            __IM uint32_t CPI2 : 8;
            uint32_t           : 24;
        } CID2_b;
    };
    union
    {
        __IM uint32_t CID3;
        struct
        {
            __IM uint32_t CPI3 : 8;
            uint32_t           : 24;
        } CID3_b;
    };
} R_TZC400_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_TZC_SRAMM_BASE       0x10460000
#define R_TZC_XSPI_BASE        0x10470000
#define R_TZC_DDR00_BASE       0x13C60000
#define R_TZC_DDR01_BASE       0x13C70000
#define R_TZC_DDR10_BASE       0x13C80000
#define R_TZC_DDR11_BASE       0x13C90000
#define R_TZC_AXI_RCPU_BASE    0x13CA0000
#define R_TZC_SRAMA_BASE       0x13CB0000
#define R_TZC_PCIE_BASE        0x13CC0000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_TZC_SRAMM       ((R_TZC400_Type *) R_TZC_SRAMM_BASE)
#define R_TZC_XSPI        ((R_TZC400_Type *) R_TZC_XSPI_BASE)
#define R_TZC_DDR00       ((R_TZC400_Type *) R_TZC_DDR00_BASE)
#define R_TZC_DDR01       ((R_TZC400_Type *) R_TZC_DDR01_BASE)
#define R_TZC_DDR10       ((R_TZC400_Type *) R_TZC_DDR10_BASE)
#define R_TZC_DDR11       ((R_TZC400_Type *) R_TZC_DDR11_BASE)
#define R_TZC_AXI_RCPU    ((R_TZC400_Type *) R_TZC_AXI_RCPU_BASE)
#define R_TZC_SRAMA       ((R_TZC400_Type *) R_TZC_SRAMA_BASE)
#define R_TZC_PCIE        ((R_TZC400_Type *) R_TZC_PCIE_BASE)

#endif
