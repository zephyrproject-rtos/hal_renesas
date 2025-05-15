/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : crc_iobitmask.h
 * Version      : 1.00
 * Description  : IO bit mask file for crc.
 *********************************************************************************************************************/

#ifndef CRC_IOBITMASK_H
#define CRC_IOBITMASK_H

#define R_CRC_CRCCR0_GPS_Msk             (0x07UL)
#define R_CRC_CRCCR0_GPS_Pos             (0UL)
#define R_CRC_CRCCR0_LMS_Msk             (0x40UL)
#define R_CRC_CRCCR0_LMS_Pos             (6UL)
#define R_CRC_CRCCR0_DORCLR_Msk          (0x80UL)
#define R_CRC_CRCCR0_DORCLR_Pos          (7UL)
#define R_CRC_CRCCR1_CRCSWR_Msk          (0x40UL)
#define R_CRC_CRCCR1_CRCSWR_Pos          (6UL)
#define R_CRC_CRCCR1_CRCSEN_Msk          (0x80UL)
#define R_CRC_CRCCR1_CRCSEN_Pos          (7UL)
#define R_CRC_CRCDIR_CRCDIR_Msk          (0xFFFFFFFFUL)
#define R_CRC_CRCDIR_CRCDIR_Pos          (0UL)
#define R_CRC_CRCDIR_BY_CRCDIR_BY_Pos    (0UL)
#define R_CRC_CRCDIR_BY_CRCDIR_BY_Msk    (0xffUL)
#define R_CRC_CRCDOR_CRCDOR_Msk          (0xFFFFFFFFUL)
#define R_CRC_CRCDOR_CRCDOR_Pos          (0UL)
#define R_CRC_CRCDOR_HA_CRCDOR_HA_Pos    (0UL)
#define R_CRC_CRCDOR_HA_CRCDOR_HA_Msk    (0xffffUL)
#define R_CRC_CRCDOR_BY_CRCDOR_BY_Pos    (0UL)
#define R_CRC_CRCDOR_BY_CRCDOR_BY_Msk    (0xffUL)
#define R_CRC_CRCSAR_CRCSA_Msk           (0xFFFFUL)
#define R_CRC_CRCSAR_CRCSA_Pos           (0UL)

#endif
