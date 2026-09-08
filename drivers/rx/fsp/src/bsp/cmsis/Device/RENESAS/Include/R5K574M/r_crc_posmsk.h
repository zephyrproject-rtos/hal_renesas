/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CRC_POSMSK_H
#define R_CRC_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           R_CRC                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  CRCCR  ========================================================= */
#define R_CRC_CRCCR0_DORCLR_Pos          (7UL)          /*!< DORCLR (Bit 7)                                        */
#define R_CRC_CRCCR0_DORCLR_Msk          (0x80UL)       /*!< DORCLR (Bitfield-Mask: 0x01)                          */
#define R_CRC_CRCCR0_LMS_Pos             (6UL)          /*!< LMS (Bit 6)                                           */
#define R_CRC_CRCCR0_LMS_Msk             (0x40UL)       /*!< LMS (Bitfield-Mask: 0x01)                             */
#define R_CRC_CRCCR0_GPS_Pos             (0UL)          /*!< GPS (Bit 0)                                           */
#define R_CRC_CRCCR0_GPS_Msk             (0x7UL)        /*!< GPS (Bitfield-Mask: 0x07)                             */
/* ========================================================  CRCDIR  ========================================================= */
#define R_CRC_CRCDIR_CRCDIR_Pos          (0UL)          /*!< CRCDIR (Bit 0)                                        */
#define R_CRC_CRCDIR_CRCDIR_Msk          (0xffffffffUL) /*!< CRCDIR (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  CRCDIR_BY  ======================================================= */
#define R_CRC_CRCDIR_BY_CRCDIR_BY_Pos    (0UL)          /*!< CRCDIR_BY (Bit 0)                                     */
#define R_CRC_CRCDIR_BY_CRCDIR_BY_Msk    (0xffUL)       /*!< CRCDIR_BY (Bitfield-Mask: 0xff)                       */
/* ========================================================  CRCDOR  ========================================================= */
#define R_CRC_CRCDOR_CRCDOR_Pos          (0UL)          /*!< CRCDOR (Bit 0)                                        */
#define R_CRC_CRCDOR_CRCDOR_Msk          (0xffffffffUL) /*!< CRCDOR (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  CRCDOR_HA  ======================================================= */
#define R_CRC_CRCDOR_HA_CRCDOR_HA_Pos    (0UL)          /*!< CRCDOR_HA (Bit 0)                                     */
#define R_CRC_CRCDOR_HA_CRCDOR_HA_Msk    (0xffffUL)     /*!< CRCDOR_HA (Bitfield-Mask: 0xffff)                     */
/* =======================================================  CRCDOR_BY  ======================================================= */
#define R_CRC_CRCDOR_BY_CRCDOR_BY_Pos    (0UL)          /*!< CRCDOR_BY (Bit 0)                                     */
#define R_CRC_CRCDOR_BY_CRCDOR_BY_Msk    (0xffUL)       /*!< CRCDOR_BY (Bitfield-Mask: 0xff)                       */

#endif /* R_CRC_POSMSK_H */
