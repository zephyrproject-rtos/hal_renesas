/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : src_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for src.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef SRC_IODEFINE_H
#define SRC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint16_t SRCID_H;
        struct
        {
            __IOM uint16_t SRCID : 16;
        } SRCID_H_b;
    };
    union
    {
        __IOM uint16_t SRCID_L;
        struct
        {
            __IOM uint16_t SRCID : 16;
        } SRCID_L_b;
    };
    union
    {
        __IM uint16_t SRCOD_H;
        struct
        {
            __IM uint16_t SRCOD : 16;
        } SRCOD_H_b;
    };
    union
    {
        __IM uint16_t SRCOD_L;
        struct
        {
            __IM uint16_t SRCOD : 16;
        } SRCOD_L_b;
    };
    union
    {
        __IOM uint16_t SRCIDCTRL;
        struct
        {
            __IOM uint16_t IFTRG : 2;
            uint16_t             : 6;
            __IOM uint16_t IEN   : 1;
            __IOM uint16_t IED   : 1;
            uint16_t             : 6;
        } SRCIDCTRL_b;
    };
    union
    {
        __IOM uint16_t SRCODCTRL;
        struct
        {
            __IOM uint16_t OFTRG : 2;
            uint16_t             : 6;
            __IOM uint16_t OEN   : 1;
            __IOM uint16_t OED   : 1;
            __IOM uint16_t OCH   : 1;
            uint16_t             : 5;
        } SRCODCTRL_b;
    };
    union
    {
        __IOM uint16_t SRCCTRL;
        struct
        {
            __IOM uint16_t OFS    : 3;
            uint16_t              : 1;
            __IOM uint16_t IFS    : 4;
            __IOM uint16_t CL     : 1;
            __IOM uint16_t FL     : 1;
            __IOM uint16_t OVEN   : 1;
            __IOM uint16_t UDEN   : 1;
            __IOM uint16_t SRCEN  : 1;
            __IOM uint16_t CEEN   : 1;
            uint16_t              : 1;
            __IOM uint16_t FICRAE : 1;
        } SRCCTRL_b;
    };
    union
    {
        __IOM uint16_t SRCSTAT;
        struct
        {
            __IOM uint16_t OINT : 1;
            __IOM uint16_t IINT : 1;
            __IOM uint16_t OVF  : 1;
            __IOM uint16_t UDF  : 1;
            __IM uint16_t  FLF  : 1;
            __IOM uint16_t CEF  : 1;
            uint16_t            : 1;
            __IM uint16_t IFDN  : 4;
            __IM uint16_t OFDN  : 5;
        } SRCSTAT_b;
    };
} R_SRC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_SRC_BASE    0x10047000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_SRC    ((R_SRC_Type *) R_SRC_BASE)

#endif
