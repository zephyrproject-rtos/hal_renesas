/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : eccram_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for eccram.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef ECCRAM_IODEFINE_H
#define ECCRAM_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM0_CTL_0;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM0_CTL_0_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM0_EAD0_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD0_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD1_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD1_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD2_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD2_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD3_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD3_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD4_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD4_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD5_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD5_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD6_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD6_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD7_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD7_0_b;
    };
} R_ECCRAM0_0_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM0_CTL_1;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM0_CTL_1_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM0_EAD0_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD0_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD1_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD1_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD2_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD2_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD3_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD3_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD4_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD4_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD5_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD5_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD6_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD6_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD7_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD7_1_b;
    };
} R_ECCRAM0_1_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM0_CTL_2;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM0_CTL_2_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM0_EAD0_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD0_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD1_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD1_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD2_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD2_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD3_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD3_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD4_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD4_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD5_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD5_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD6_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD6_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD7_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD7_2_b;
    };
} R_ECCRAM0_2_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM0_CTL_3;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM0_CTL_3_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM0_EAD0_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD0_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD1_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD1_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD2_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD2_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD3_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD3_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD4_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD4_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD5_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD5_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD6_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD6_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD7_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD7_3_b;
    };
} R_ECCRAM0_3_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM0_CTL_4;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM0_CTL_4_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM0_EAD0_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD0_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD1_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD1_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD2_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD2_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD3_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD3_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD4_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD4_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD5_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD5_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD6_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD6_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD7_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD7_4_b;
    };
} R_ECCRAM0_4_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM0_CTL_5;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM0_CTL_5_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM0_EAD0_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD0_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD1_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD1_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD2_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD2_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD3_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD3_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD4_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD4_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD5_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD5_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD6_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD6_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD7_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD7_5_b;
    };
} R_ECCRAM0_5_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM0_CTL_6;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM0_CTL_6_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM0_EAD0_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD0_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD1_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD1_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD2_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD2_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD3_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD3_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD4_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD4_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD5_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD5_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD6_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD6_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD7_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD7_6_b;
    };
} R_ECCRAM0_6_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM0_CTL_7;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM0_CTL_7_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM0_EAD0_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD0_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD1_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD1_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD2_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD2_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD3_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD3_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD4_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD4_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD5_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD5_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD6_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD6_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM0_EAD7_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM0_EAD7_7_b;
    };
} R_ECCRAM0_7_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM1_CTL_0;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM1_CTL_0_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM1_EAD0_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD0_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD1_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD1_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD2_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD2_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD3_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD3_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD4_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD4_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD5_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD5_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD6_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD6_0_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD7_0;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD7_0_b;
    };
} R_ECCRAM1_0_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM1_CTL_1;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM1_CTL_1_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM1_EAD0_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD0_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD1_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD1_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD2_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD2_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD3_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD3_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD4_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD4_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD5_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD5_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD6_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD6_1_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD7_1;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD7_1_b;
    };
} R_ECCRAM1_1_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM1_CTL_2;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM1_CTL_2_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM1_EAD0_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD0_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD1_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD1_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD2_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD2_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD3_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD3_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD4_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD4_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD5_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD5_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD6_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD6_2_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD7_2;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD7_2_b;
    };
} R_ECCRAM1_2_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM1_CTL_3;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM1_CTL_3_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM1_EAD0_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD0_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD1_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD1_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD2_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD2_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD3_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD3_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD4_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD4_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD5_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD5_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD6_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD6_3_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD7_3;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD7_3_b;
    };
} R_ECCRAM1_3_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM1_CTL_4;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM1_CTL_4_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM1_EAD0_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD0_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD1_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD1_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD2_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD2_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD3_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD3_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD4_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD4_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD5_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD5_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD6_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD6_4_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD7_4;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD7_4_b;
    };
} R_ECCRAM1_4_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM1_CTL_5;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM1_CTL_5_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM1_EAD0_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD0_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD1_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD1_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD2_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD2_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD3_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD3_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD4_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD4_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD5_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD5_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD6_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD6_5_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD7_5;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD7_5_b;
    };
} R_ECCRAM1_5_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM1_CTL_6;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM1_CTL_6_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM1_EAD0_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD0_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD1_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD1_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD2_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD2_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD3_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD3_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD4_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD4_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD5_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD5_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD6_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD6_6_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD7_6;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD7_6_b;
    };
} R_ECCRAM1_6_Type;

typedef struct
{
    union
    {
        __IOM uint32_t ECCRAM1_CTL_7;
        struct
        {
            uint32_t               : 1;
            __IM uint32_t  ECER1F  : 1;
            __IM uint32_t  ECER2F  : 1;
            __IOM uint32_t EC1EDIC : 1;
            __IOM uint32_t EC2EDIC : 1;
            __IOM uint32_t EC1ECP  : 1;
            __IOM uint32_t ECERVF  : 1;
            uint32_t               : 2;
            __IOM uint32_t ECER1C  : 1;
            __IOM uint32_t ECER2C  : 1;
            __IM uint32_t  ECOVFF  : 1;
            uint32_t               : 2;
            __IOM uint32_t EMCA    : 2;
            __IM uint32_t  ECSEDF0 : 1;
            __IM uint32_t  ECDEDF0 : 1;
            __IM uint32_t  ECSEDF1 : 1;
            __IM uint32_t  ECDEDF1 : 1;
            __IM uint32_t  ECSEDF2 : 1;
            __IM uint32_t  ECDEDF2 : 1;
            __IM uint32_t  ECSEDF3 : 1;
            __IM uint32_t  ECDEDF3 : 1;
            __IM uint32_t  ECSEDF4 : 1;
            __IM uint32_t  ECDEDF4 : 1;
            __IM uint32_t  ECSEDF5 : 1;
            __IM uint32_t  ECDEDF5 : 1;
            __IM uint32_t  ECSEDF6 : 1;
            __IM uint32_t  ECDEDF6 : 1;
            __IM uint32_t  ECSEDF7 : 1;
            __IM uint32_t  ECDEDF7 : 1;
        } ECCRAM1_CTL_7_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t ECCRAM1_EAD0_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD0_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD1_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD1_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD2_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD2_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD3_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD3_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD4_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD4_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD5_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD5_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD6_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD6_7_b;
    };
    union
    {
        __IM uint32_t ECCRAM1_EAD7_7;
        struct
        {
            __IM uint32_t ECEAD0 : 32;
        } ECCRAM1_EAD7_7_b;
    };
} R_ECCRAM1_7_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_ECCRAM0_0_BASE    0x11080000
#define R_ECCRAM0_1_BASE    0x11080040
#define R_ECCRAM0_2_BASE    0x11080080
#define R_ECCRAM0_3_BASE    0x110800C0
#define R_ECCRAM0_4_BASE    0x11080100
#define R_ECCRAM0_5_BASE    0x11080140
#define R_ECCRAM0_6_BASE    0x11080180
#define R_ECCRAM0_7_BASE    0x110801C0
#define R_ECCRAM1_0_BASE    0x11090000
#define R_ECCRAM1_1_BASE    0x11090040
#define R_ECCRAM1_2_BASE    0x11090080
#define R_ECCRAM1_3_BASE    0x110900C0
#define R_ECCRAM1_4_BASE    0x11090100
#define R_ECCRAM1_5_BASE    0x11090140
#define R_ECCRAM1_6_BASE    0x11090180
#define R_ECCRAM1_7_BASE    0x110901C0

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_ECCRAM0_0    ((R_ECCRAM0_0_Type *) R_ECCRAM0_0_BASE)
#define R_ECCRAM0_1    ((R_ECCRAM0_1_Type *) R_ECCRAM0_1_BASE)
#define R_ECCRAM0_2    ((R_ECCRAM0_2_Type *) R_ECCRAM0_2_BASE)
#define R_ECCRAM0_3    ((R_ECCRAM0_3_Type *) R_ECCRAM0_3_BASE)
#define R_ECCRAM0_4    ((R_ECCRAM0_4_Type *) R_ECCRAM0_4_BASE)
#define R_ECCRAM0_5    ((R_ECCRAM0_5_Type *) R_ECCRAM0_5_BASE)
#define R_ECCRAM0_6    ((R_ECCRAM0_6_Type *) R_ECCRAM0_6_BASE)
#define R_ECCRAM0_7    ((R_ECCRAM0_7_Type *) R_ECCRAM0_7_BASE)
#define R_ECCRAM1_0    ((R_ECCRAM1_0_Type *) R_ECCRAM1_0_BASE)
#define R_ECCRAM1_1    ((R_ECCRAM1_1_Type *) R_ECCRAM1_1_BASE)
#define R_ECCRAM1_2    ((R_ECCRAM1_2_Type *) R_ECCRAM1_2_BASE)
#define R_ECCRAM1_3    ((R_ECCRAM1_3_Type *) R_ECCRAM1_3_BASE)
#define R_ECCRAM1_4    ((R_ECCRAM1_4_Type *) R_ECCRAM1_4_BASE)
#define R_ECCRAM1_5    ((R_ECCRAM1_5_Type *) R_ECCRAM1_5_BASE)
#define R_ECCRAM1_6    ((R_ECCRAM1_6_Type *) R_ECCRAM1_6_BASE)
#define R_ECCRAM1_7    ((R_ECCRAM1_7_Type *) R_ECCRAM1_7_BASE)

#endif
