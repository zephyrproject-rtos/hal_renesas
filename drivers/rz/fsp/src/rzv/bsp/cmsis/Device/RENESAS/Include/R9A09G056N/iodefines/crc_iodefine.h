/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : crc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for crc.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef CRC_IODEFINE_H
#define CRC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint8_t CRCCR0;
        struct
        {
            __IOM uint8_t GPS    : 3;
            uint8_t              : 3;
            __IOM uint8_t LMS    : 1;
            __OM uint8_t  DORCLR : 1;
        } CRCCR0_b;
    };
    union
    {
        __IOM uint8_t CRCCR1;
        struct
        {
            uint8_t              : 6;
            __IOM uint8_t CRCSWR : 1;
            __IOM uint8_t CRCSEN : 1;
        } CRCCR1_b;
    };
    __IM uint8_t RESERVED[2];
    union
    {
        union
        {
            __IOM uint32_t CRCDIR;
            struct
            {
                __IOM uint32_t CRCDIR : 32;
            } CRCDIR_b;
        };
        union
        {
            __IOM uint8_t CRCDIR_BY;

            struct
            {
                __IOM uint8_t CRCDIR_BY : 8;
            } CRCDIR_BY_b;
        };
    };
    union
    {
        union
        {
            __IOM uint32_t CRCDOR;
            struct
            {
                __IOM uint32_t CRCDOR : 32;
            } CRCDOR_b;
        };
        union
        {
            __IOM uint16_t CRCDOR_HA;
            struct
            {
                __IOM uint16_t CRCDOR_HA : 16;
            } CRCDOR_HA_b;
        };
        union
        {
            __IOM uint8_t CRCDOR_BY;

            struct
            {
                __IOM uint8_t CRCDOR_BY : 8;
            } CRCDOR_BY_b;
        };
    };
    union
    {
        __IOM uint16_t CRCSAR;
        struct
        {
            __IOM uint16_t CRCSA : 16;
        } CRCSAR_b;
    };
} R_CRC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_CRC_BASE    0x43000800

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_CRC    ((R_CRC_Type *) R_CRC_BASE)

#endif
