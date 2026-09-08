/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CMTW_POMSK_H
#define R_CMTW_POMSK_H

/* =========================================================================================================================== */
/* ================                                          R_CMTW0                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  CMWSTR  ========================================================= */
#define R_CMTW0_CMWSTR_STR_Pos         (0UL)          /*!< STR (Bit 0)                                           */
#define R_CMTW0_CMWSTR_STR_Msk         (0x1UL)        /*!< STR (Bitfield-Mask: 0x01)                             */
/* =========================================================  CMWCR  ========================================================= */
#define R_CMTW0_CMWCR_CCLR_Pos         (13UL)         /*!< CCLR (Bit 13)                                         */
#define R_CMTW0_CMWCR_CCLR_Msk         (0xe000UL)     /*!< CCLR (Bitfield-Mask: 0x07)                            */
#define R_CMTW0_CMWCR_CMS_Pos          (9UL)          /*!< CMS (Bit 9)                                           */
#define R_CMTW0_CMWCR_CMS_Msk          (0x200UL)      /*!< CMS (Bitfield-Mask: 0x01)                             */
#define R_CMTW0_CMWCR_OC1IE_Pos        (7UL)          /*!< OC1IE (Bit 7)                                         */
#define R_CMTW0_CMWCR_OC1IE_Msk        (0x80UL)       /*!< OC1IE (Bitfield-Mask: 0x01)                           */
#define R_CMTW0_CMWCR_OC0IE_Pos        (6UL)          /*!< OC0IE (Bit 6)                                         */
#define R_CMTW0_CMWCR_OC0IE_Msk        (0x40UL)       /*!< OC0IE (Bitfield-Mask: 0x01)                           */
#define R_CMTW0_CMWCR_IC1IE_Pos        (5UL)          /*!< IC1IE (Bit 5)                                         */
#define R_CMTW0_CMWCR_IC1IE_Msk        (0x20UL)       /*!< IC1IE (Bitfield-Mask: 0x01)                           */
#define R_CMTW0_CMWCR_IC0IE_Pos        (4UL)          /*!< IC0IE (Bit 4)                                         */
#define R_CMTW0_CMWCR_IC0IE_Msk        (0x10UL)       /*!< IC0IE (Bitfield-Mask: 0x01)                           */
#define R_CMTW0_CMWCR_CMWIE_Pos        (3UL)          /*!< CMWIE (Bit 3)                                         */
#define R_CMTW0_CMWCR_CMWIE_Msk        (0x8UL)        /*!< CMWIE (Bitfield-Mask: 0x01)                           */
#define R_CMTW0_CMWCR_CKS_Pos          (0UL)          /*!< CKS (Bit 0)                                           */
#define R_CMTW0_CMWCR_CKS_Msk          (0x3UL)        /*!< CKS (Bitfield-Mask: 0x03)                             */
/* ========================================================  CMWIOR  ========================================================= */
#define R_CMTW0_CMWIOR_CMWE_Pos        (15UL)         /*!< CMWE (Bit 15)                                         */
#define R_CMTW0_CMWIOR_CMWE_Msk        (0x8000UL)     /*!< CMWE (Bitfield-Mask: 0x01)                            */
#define R_CMTW0_CMWIOR_OC1E_Pos        (13UL)         /*!< OC1E (Bit 13)                                         */
#define R_CMTW0_CMWIOR_OC1E_Msk        (0x2000UL)     /*!< OC1E (Bitfield-Mask: 0x01)                            */
#define R_CMTW0_CMWIOR_OC0E_Pos        (12UL)         /*!< OC0E (Bit 12)                                         */
#define R_CMTW0_CMWIOR_OC0E_Msk        (0x1000UL)     /*!< OC0E (Bitfield-Mask: 0x01)                            */
#define R_CMTW0_CMWIOR_OC1_Pos         (10UL)         /*!< OC1 (Bit 10)                                          */
#define R_CMTW0_CMWIOR_OC1_Msk         (0xc00UL)      /*!< OC1 (Bitfield-Mask: 0x03)                             */
#define R_CMTW0_CMWIOR_OC0_Pos         (8UL)          /*!< OC0 (Bit 8)                                           */
#define R_CMTW0_CMWIOR_OC0_Msk         (0x300UL)      /*!< OC0 (Bitfield-Mask: 0x03)                             */
#define R_CMTW0_CMWIOR_IC1E_Pos        (5UL)          /*!< IC1E (Bit 5)                                          */
#define R_CMTW0_CMWIOR_IC1E_Msk        (0x20UL)       /*!< IC1E (Bitfield-Mask: 0x01)                            */
#define R_CMTW0_CMWIOR_IC0E_Pos        (4UL)          /*!< IC0E (Bit 4)                                          */
#define R_CMTW0_CMWIOR_IC0E_Msk        (0x10UL)       /*!< IC0E (Bitfield-Mask: 0x01)                            */
#define R_CMTW0_CMWIOR_IC1_Pos         (2UL)          /*!< IC1 (Bit 2)                                           */
#define R_CMTW0_CMWIOR_IC1_Msk         (0xcUL)        /*!< IC1 (Bitfield-Mask: 0x03)                             */
#define R_CMTW0_CMWIOR_IC0_Pos         (0UL)          /*!< IC0 (Bit 0)                                           */
#define R_CMTW0_CMWIOR_IC0_Msk         (0x3UL)        /*!< IC0 (Bitfield-Mask: 0x03)                             */
/* ========================================================  CMWCNT  ========================================================= */
#define R_CMTW0_CMWCNT_CMWCNT_Pos      (0UL)          /*!< CMWCNT (Bit 0)                                        */
#define R_CMTW0_CMWCNT_CMWCNT_Msk      (0xffffffffUL) /*!< CMWCNT (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  CMWCOR  ========================================================= */
#define R_CMTW0_CMWCOR_CMWCOR_Pos      (0UL)          /*!< CMWCOR (Bit 0)                                        */
#define R_CMTW0_CMWCOR_CMWCOR_Msk      (0xffffffffUL) /*!< CMWCOR (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  CMWICR0  ======================================================== */
#define R_CMTW0_CMWICR0_CMWICR0_Pos    (0UL)          /*!< CMWICR0 (Bit 0)                                       */
#define R_CMTW0_CMWICR0_CMWICR0_Msk    (0xffffffffUL) /*!< CMWICR0 (Bitfield-Mask: 0xffffffff)                   */
/* ========================================================  CMWICR1  ======================================================== */
#define R_CMTW0_CMWICR1_CMWICR1_Pos    (0UL)          /*!< CMWICR1 (Bit 0)                                       */
#define R_CMTW0_CMWICR1_CMWICR1_Msk    (0xffffffffUL) /*!< CMWICR1 (Bitfield-Mask: 0xffffffff)                   */
/* ========================================================  CMWOCR0  ======================================================== */
#define R_CMTW0_CMWOCR0_CMWOCR0_Pos    (0UL)          /*!< CMWOCR0 (Bit 0)                                       */
#define R_CMTW0_CMWOCR0_CMWOCR0_Msk    (0xffffffffUL) /*!< CMWOCR0 (Bitfield-Mask: 0xffffffff)                   */
/* ========================================================  CMWOCR1  ======================================================== */
#define R_CMTW0_CMWOCR1_CMWOCR1_Pos    (0UL)          /*!< CMWOCR1 (Bit 0)                                       */
#define R_CMTW0_CMWOCR1_CMWOCR1_Msk    (0xffffffffUL) /*!< CMWOCR1 (Bitfield-Mask: 0xffffffff)                   */

#endif /* R_CMTW_POMSK_H */
