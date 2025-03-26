/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : tsu_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for tsu.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef TSU_IODEFINE_H
#define TSU_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t TSU_SM;
        struct
        {
            __IOM uint32_t EN_TS     : 1;
            __IOM uint32_t ADC_EN_TS : 1;
            uint32_t                 : 30;
        } TSU_SM_b;
    };
    union
    {
        __IOM uint32_t TSU_ST;
        struct
        {
            __IOM uint32_t START : 1;
            __IOM uint32_t RSV   : 1;
            uint32_t             : 30;
        } TSU_ST_b;
    };
    __IM uint8_t RESERVED[4];
    union
    {
        __IM uint32_t TSU_SAD;
        struct
        {
            __IM uint32_t OUT_12BIT_TS : 12;
            uint32_t                   : 20;
        } TSU_SAD_b;
    };
    union
    {
        __IM uint32_t TSU_SS;
        struct
        {
            __IM uint32_t CONV : 1;
            uint32_t           : 31;
        } TSU_SS_b;
    };
    __IM uint8_t RESERVED1[4];
    union
    {
        __IM uint32_t OTPTSUTRIM0_REG;
        struct
        {
            __IM uint32_t OTPTSUTRIM0    : 12;
            uint32_t                     : 19;
            __IM uint32_t OTPTSUTRIM0_EN : 1;
        } OTPTSUTRIM0_REG_b;
    };
    union
    {
        __IM uint32_t OTPTSUTRIM1_REG;
        struct
        {
            __IM uint32_t OTPTSUTRIM1    : 12;
            uint32_t                     : 19;
            __IM uint32_t OTPTSUTRIM1_EN : 1;
        } OTPTSUTRIM1_REG_b;
    };
} R_TSU_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_TSU_BASE    0x10059400

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_TSU    ((R_TSU_Type *) R_TSU_BASE)

#endif
