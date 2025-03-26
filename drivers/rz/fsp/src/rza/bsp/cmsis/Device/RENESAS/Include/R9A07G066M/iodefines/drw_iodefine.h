/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : drw_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for drw.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef DRW_IODEFINE_H
#define DRW_IODEFINE_H

typedef struct
{
    union
    {
        union
        {
            __OM uint32_t CONTROL;
            struct
            {
                __OM uint16_t L;
                __OM uint16_t H;
            } CONTROL_hword;
            struct
            {
                __OM uint8_t LL;
                __OM uint8_t LH;
                __OM uint8_t HL;
                __OM uint8_t HH;
            } CONTROL_byte;
            struct
            {
                __OM uint8_t LIM1ENABLE:1;
                __OM uint8_t LIM2ENABLE:1;
                __OM uint8_t LIM3ENABLE:1;
                __OM uint8_t LIM4ENABLE:1;
                __OM uint8_t LIM5ENABLE:1;
                __OM uint8_t LIM6ENABLE:1;
                __OM uint8_t QUAD1ENABLE:1;
                __OM uint8_t QUAD2ENABLE:1;
                __OM uint8_t QUAD3ENABLE:1;
                __OM uint8_t LIM1THRESHOLD:1;
                __OM uint8_t LIM2THRESHOLD:1;
                __OM uint8_t LIM3THRESHOLD:1;
                __OM uint8_t LIM4THRESHOLD:1;
                __OM uint8_t LIM5THRESHOLD:1;
                __OM uint8_t LIM6THRESHOLD:1;
                __OM uint8_t BAND1ENABLE:1;
                __OM uint8_t BAND2ENABLE:1;
                __OM uint8_t UNION12:1;
                __OM uint8_t UNION34:1;
                __OM uint8_t UNION56:1;
                __OM uint8_t UNIONAB:1;
                __OM uint8_t UNIONCD:1;
                __OM uint8_t SPANABORT:1;
                __OM uint8_t SPANSTORE:1;
                uint8_t :8;
            } CONTROL_b;
        };
        union
        {
            __OM uint32_t STATUS;
            struct
            {
                __OM uint16_t L;
                __OM uint16_t H;
            } STATUS_hword;
            struct
            {
                __OM uint8_t LL;
                __OM uint8_t LH;
                __OM uint8_t HL;
                __OM uint8_t HH;
            } STATUS_byte;
            struct
            {
                __OM uint8_t BUSYENUM:1;
                __OM uint8_t BUSYWRITE:1;
                __OM uint8_t CACHEDIRTY:1;
                __OM uint8_t DLISTACTIVE:1;
                __OM uint8_t ENUMIRQ:1;
                __OM uint8_t DLISTIRQ:1;
                __OM uint8_t BUSIRQ:1;
                uint8_t :1;
                __OM uint8_t BUSERRMFB:1;
                __OM uint8_t BUSERRMTXMRL:1;
                __OM uint8_t BUSERRMDL:1;
                uint8_t :5;
                uint8_t :8;
                uint8_t :8;
            } STATUS_b;
        };
    };
    union
    {
        union
        {
            __OM uint32_t CONTROL2;
            struct
            {
                __OM uint16_t L;
                __OM uint16_t H;
            } CONTROL2_hword;
            struct
            {
                __OM uint8_t LL;
                __OM uint8_t LH;
                __OM uint8_t HL;
                __OM uint8_t HH;
            } CONTROL2_byte;
            struct
            {
                __OM uint8_t PATTERNENABLE:1;
                __OM uint8_t TEXTUREENABLE:1;
                __OM uint8_t PATTERNSOURCEL5:1;
                __OM uint8_t USEACB:1;
                __OM uint8_t READFORMAT_3_2:2;
                __OM uint8_t BSFA:1;
                __OM uint8_t BDFA:1;
                __OM uint8_t WRITEFORMAT_2:1;
                __OM uint8_t BSF:1;
                __OM uint8_t BDF:1;
                __OM uint8_t BSI:1;
                __OM uint8_t BDI:1;
                __OM uint8_t BC2:1;
                __OM uint8_t TEXTURECLAMPX:1;
                __OM uint8_t TEXTURECLAMPY:1;
                __OM uint8_t TEXTUREFILTERX:1;
                __OM uint8_t TEXTUREFILTERY:1;
                __OM uint8_t READFORMAT_1_0:2;
                __OM uint8_t WRITEFORMAT_1_0:2;
                __OM uint8_t WRITEALPHA:2;
                __OM uint8_t RLEENABLE:1;
                __OM uint8_t CLUTENABLE:1;
                __OM uint8_t COLKEYENABLE:1;
                __OM uint8_t CLUTFORMAT:1;
                __OM uint8_t BSIA:1;
                __OM uint8_t BDIA:1;
                __OM uint8_t RLEPIXELWIDTH:2;
            } CONTROL2_b;
        };
        union
        {
            __IM uint32_t HWREVISION;
            struct
            {
                __IM uint16_t L;
                __IM uint16_t H;
            } HWREVISION_hword;
            struct
            {
                __IM uint8_t LL;
                __IM uint8_t LH;
                __IM uint8_t HL;
                __IM uint8_t HH;
            } HWREVISION_byte;
            struct
            {
                __IM uint32_t REV:12;
                uint32_t :4;
                uint32_t :1;
                __IM uint32_t DLR:1;
                __IM uint32_t FBCACHE:1;
                __IM uint32_t TXCACHE:1;
                __IM uint32_t PERFCOUNT:1;
                __IM uint32_t TEXCLU:1;
                uint32_t :1;
                __IM uint32_t RLEUNIT:1;
                __IM uint32_t TEXCLUT256:1;
                __IM uint32_t COLORKEY:1;
                uint32_t :1;
                __IM uint32_t ACBLEND:1;
                uint32_t :4;
            } HWREVISION_b;
        };
    };
    __IM uint8_t        RESERVED[8];
    union
    {
        __OM uint32_t L1START;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L1START_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L1START_byte;
        struct
        {
            __OM uint32_t LSTART:32;
        } L1START_b;
    };
    union
    {
        __OM uint32_t L2START;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L2START_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L2START_byte;
        struct
        {
            __OM uint32_t LSTART:32;
        } L2START_b;
    };
    union
    {
        __OM uint32_t L3START;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L3START_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L3START_byte;
        struct
        {
            __OM uint32_t LSTART:32;
        } L3START_b;
    };
    union
    {
        __OM uint32_t L4START;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L4START_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L4START_byte;
        struct
        {
            __OM uint32_t LSTART:32;
        } L4START_b;
    };
    union
    {
        __OM uint32_t L5START;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L5START_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L5START_byte;
        struct
        {
            __OM uint32_t LSTART:32;
        } L5START_b;
    };
    union
    {
        __OM uint32_t L6START;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L6START_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L6START_byte;
        struct
        {
            __OM uint32_t LSTART:32;
        } L6START_b;
    };
    union
    {
        __OM uint32_t L1XADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L1XADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L1XADD_byte;
        struct
        {
            __OM uint32_t LXADD:32;
        } L1XADD_b;
    };
    union
    {
        __OM uint32_t L2XADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L2XADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L2XADD_byte;
        struct
        {
            __OM uint32_t LXADD:32;
        } L2XADD_b;
    };
    union
    {
        __OM uint32_t L3XADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L3XADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L3XADD_byte;
        struct
        {
            __OM uint32_t LXADD:32;
        } L3XADD_b;
    };
    union
    {
        __OM uint32_t L4XADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L4XADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L4XADD_byte;
        struct
        {
            __OM uint32_t LXADD:32;
        } L4XADD_b;
    };
    union
    {
        __OM uint32_t L5XADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L5XADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L5XADD_byte;
        struct
        {
            __OM uint32_t LXADD:32;
        } L5XADD_b;
    };
    union
    {
        __OM uint32_t L6XADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L6XADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L6XADD_byte;
        struct
        {
            __OM uint32_t LXADD:32;
        } L6XADD_b;
    };
    union
    {
        __OM uint32_t L1YADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L1YADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L1YADD_byte;
        struct
        {
            __OM uint32_t LYADD:32;
        } L1YADD_b;
    };
    union
    {
        __OM uint32_t L2YADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L2YADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L2YADD_byte;
        struct
        {
            __OM uint32_t LYADD:32;
        } L2YADD_b;
    };
    union
    {
        __OM uint32_t L3YADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L3YADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L3YADD_byte;
        struct
        {
            __OM uint32_t LYADD:32;
        } L3YADD_b;
    };
    union
    {
        __OM uint32_t L4YADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L4YADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L4YADD_byte;
        struct
        {
            __OM uint32_t LYADD:32;
        } L4YADD_b;
    };
    union
    {
        __OM uint32_t L5YADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L5YADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L5YADD_byte;
        struct
        {
            __OM uint32_t LYADD:32;
        } L5YADD_b;
    };
    union
    {
        __OM uint32_t L6YADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L6YADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L6YADD_byte;
        struct
        {
            __OM uint32_t LYADD:32;
        } L6YADD_b;
    };
    union
    {
        __OM uint32_t L1BAND;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L1BAND_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L1BAND_byte;
        struct
        {
            __OM uint32_t LBAND:32;
        } L1BAND_b;
    };
    union
    {
        __OM uint32_t L2BAND;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } L2BAND_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } L2BAND_byte;
        struct
        {
            __OM uint32_t LBAND:32;
        } L2BAND_b;
    };
    __IM uint8_t        RESERVED1[4];
    union
    {
        __OM uint32_t COLOR1;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } COLOR1_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } COLOR1_byte;
        struct
        {
            __OM uint8_t COLOR1B:8;
            __OM uint8_t COLOR1G:8;
            __OM uint8_t COLOR1R:8;
            __OM uint8_t COLOR1A:8;
        } COLOR1_b;
    };
    union
    {
        __OM uint32_t COLOR2;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } COLOR2_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } COLOR2_byte;
        struct
        {
            __OM uint8_t COLOR2B:8;
            __OM uint8_t COLOR2G:8;
            __OM uint8_t COLOR2R:8;
            __OM uint8_t COLOR2A:8;
        } COLOR2_b;
    };
    __IM uint8_t        RESERVED2[8];
    union
    {
        __OM uint32_t PATTERN;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } PATTERN_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } PATTERN_byte;
        struct
        {
            __OM uint8_t PATTERN:8;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } PATTERN_b;
    };
    union
    {
        __OM uint32_t SIZE;
        struct
        {
            __OM uint16_t SIZEX;
            __OM uint16_t SIZEY;
        } SIZE_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } SIZE_byte;
    };
    union
    {
        __OM uint32_t PITCH;
        struct
        {
            __OM uint16_t PITCH;
            __OM uint16_t SSD;
        } PITCH_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } PITCH_byte;
    };
    union
    {
        __OM uint32_t ORIGIN;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } ORIGIN_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } ORIGIN_byte;
        struct
        {
            __OM uint32_t ORIGIN:32;
        } ORIGIN_b;
    };
    __IM uint8_t        RESERVED3[12];
    union
    {
        __OM uint32_t LUSTART;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } LUSTART_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } LUSTART_byte;
        struct
        {
            __OM uint32_t LUSTART:32;
        } LUSTART_b;
    };
    union
    {
        __OM uint32_t LUXADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } LUXADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } LUXADD_byte;
        struct
        {
            __OM uint32_t LUXADD:32;
        } LUXADD_b;
    };
    union
    {
        __OM uint32_t LUYADD;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } LUYADD_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } LUYADD_byte;
        struct
        {
            __OM uint32_t LUYADD:32;
        } LUYADD_b;
    };
    union
    {
        __OM uint32_t LVSTARTI;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } LVSTARTI_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } LVSTARTI_byte;
        struct
        {
            __OM uint32_t LVSTARTI:32;
        } LVSTARTI_b;
    };
    union
    {
        __OM uint32_t LVSTARTF;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } LVSTARTF_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } LVSTARTF_byte;
        struct
        {
            __OM uint32_t LVSTARTF:16;
            uint32_t :16;
        } LVSTARTF_b;
    };
    union
    {
        __OM uint32_t LVXADDI;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } LVXADDI_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } LVXADDI_byte;
        struct
        {
            __OM uint32_t LVXADDI:32;
        } LVXADDI_b;
    };
    union
    {
        __OM uint32_t LVYADDI;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } LVYADDI_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } LVYADDI_byte;
        struct
        {
            __OM uint32_t LVYADDI:32;
        } LVYADDI_b;
    };
    union
    {
        __OM uint32_t LVYXADDF;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } LVYXADDF_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } LVYXADDF_byte;
        struct
        {
            __OM uint32_t LVXADDF:32;
        } LVYXADDF_b;
    };
    __IM uint8_t        RESERVED4[4];
    union
    {
        __OM uint32_t TEXPITCH;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } TEXPITCH_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } TEXPITCH_byte;
        struct
        {
            __OM uint32_t TEXPITCH:11;
            uint32_t :5;
            uint32_t :16;
        } TEXPITCH_b;
    };
    union
    {
        __OM uint32_t TEXMASK;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } TEXMASK_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } TEXMASK_byte;
        struct
        {
            __OM uint32_t TEXUMASK:11;
            __OM uint32_t TEXVMASK:21;
        } TEXMASK_b;
    };
    union
    {
        __OM uint32_t TEXORIGIN;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } TEXORIGIN_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } TEXORIGIN_byte;
        struct
        {
            __OM uint32_t TEXORIGIN:32;
        } TEXORIGIN_b;
    };
    union
    {
        __OM uint32_t IRQCTL;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } IRQCTL_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } IRQCTL_byte;
        struct
        {
            __OM uint8_t ENUMIRQEN:1;
            __OM uint8_t DLISTIRQEN:1;
            __OM uint8_t ENUMIRQCLR:1;
            __OM uint8_t DLISTIRQCLR:1;
            __OM uint8_t BUSIRQEN:1;
            __OM uint8_t BUSIRQCLR:1;
            uint8_t :2;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } IRQCTL_b;
    };
    union
    {
        __OM uint32_t CACHECTL;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } CACHECTL_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } CACHECTL_byte;
        struct
        {
            __OM uint8_t CENABLEFX:1;
            __OM uint8_t CFLUSHFX:1;
            __OM uint8_t CENABLETX:1;
            __OM uint8_t CFLUSHTX:1;
            uint8_t :4;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } CACHECTL_b;
    };
    union
    {
        __OM uint32_t DLISTSTART;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } DLISTSTART_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } DLISTSTART_byte;
        struct
        {
            __OM uint32_t DLISTSTART:32;
        } DLISTSTART_b;
    };
    union
    {
        __IOM uint32_t PERFCOUNT1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PERFCOUNT1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PERFCOUNT1_byte;
        struct
        {
            __IOM uint32_t PERFCOUNT:32;
        } PERFCOUNT1_b;
    };
    union
    {
        __IOM uint32_t PERFCOUNT2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PERFCOUNT2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PERFCOUNT2_byte;
        struct
        {
            __IOM uint32_t PERFCOUNT:32;
        } PERFCOUNT2_b;
    };
    union
    {
        __OM uint32_t PERFTRIGGER;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } PERFTRIGGER_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } PERFTRIGGER_byte;
        struct
        {
            __OM uint8_t PERFTRIGGER1:5;
            uint8_t :3;
            uint8_t :8;
            __OM uint8_t PERFTRIGGER2:5;
            uint8_t :3;
            uint8_t :8;
        } PERFTRIGGER_b;
    };
    __IM uint8_t        RESERVED5[4];
    union
    {
        __OM uint32_t TEXCLADDR;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } TEXCLADDR_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } TEXCLADDR_byte;
        struct
        {
            __OM uint8_t CLADDR:8;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } TEXCLADDR_b;
    };
    union
    {
        __OM uint32_t TEXCLDATA;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } TEXCLDATA_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } TEXCLDATA_byte;
        struct
        {
            __OM uint32_t CLDATA:32;
        } TEXCLDATA_b;
    };
    union
    {
        __OM uint32_t TEXCLOFFSET;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } TEXCLOFFSET_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } TEXCLOFFSET_byte;
        struct
        {
            __OM uint8_t CLOFFSET:8;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } TEXCLOFFSET_b;
    };
    union
    {
        __OM uint32_t COLKEY;
        struct
        {
            __OM uint16_t L;
            __OM uint16_t H;
        } COLKEY_hword;
        struct
        {
            __OM uint8_t LL;
            __OM uint8_t LH;
            __OM uint8_t HL;
            __OM uint8_t HH;
        } COLKEY_byte;
        struct
        {
            __OM uint8_t COLKEYB:8;
            __OM uint8_t COLKEYG:8;
            __OM uint8_t COLKEYR:8;
            uint8_t :8;
        } COLKEY_b;
    };
} R_DRW_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_DRW_BASE     0x11C8A000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_DRW     ((R_DRW_Type     *) R_DRW_BASE)

#endif
