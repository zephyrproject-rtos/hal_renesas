/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SPI_B_POSMSK_H
#define R_SPI_B_POSMSK_H

/* =========================================================================================================================== */
/* ================                                         R_SPI_B0                                          ================ */
/* =========================================================================================================================== */

/* =========================================================  SPDR  ========================================================== */
/* =========================================================  SPCKD  ========================================================= */
#define R_SPI_B0_SPCKD_SCKDL_Pos        (0UL)          /*!< SCKDL (Bit 0)                                         */
#define R_SPI_B0_SPCKD_SCKDL_Msk        (0x7UL)        /*!< SCKDL (Bitfield-Mask: 0x07)                           */
/* =========================================================  SSLND  ========================================================= */
#define R_SPI_B0_SSLND_SLNDL_Pos        (0UL)          /*!< SLNDL (Bit 0)                                         */
#define R_SPI_B0_SSLND_SLNDL_Msk        (0x7UL)        /*!< SLNDL (Bitfield-Mask: 0x07)                           */
/* =========================================================  SPND  ========================================================== */
#define R_SPI_B0_SPND_SPNDL_Pos         (0UL)          /*!< SPNDL (Bit 0)                                         */
#define R_SPI_B0_SPND_SPNDL_Msk         (0x7UL)        /*!< SPNDL (Bitfield-Mask: 0x07)                           */
/* =========================================================  SPCR  ========================================================== */
#define R_SPI_B0_SPCR_SYNDIS_Pos        (31UL)         /*!< SYNDIS (Bit 31)                                       */
#define R_SPI_B0_SPCR_SYNDIS_Msk        (0x80000000UL) /*!< SYNDIS (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCR_MSTR_Pos          (30UL)         /*!< MSTR (Bit 30)                                         */
#define R_SPI_B0_SPCR_MSTR_Msk          (0x40000000UL) /*!< MSTR (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCR_CMMD_Pos          (28UL)         /*!< CMMD (Bit 28)                                         */
#define R_SPI_B0_SPCR_CMMD_Msk          (0x30000000UL) /*!< CMMD (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPCR_FRFS_Pos          (25UL)         /*!< FRFS (Bit 25)                                         */
#define R_SPI_B0_SPCR_FRFS_Msk          (0x2000000UL)  /*!< FRFS (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCR_SPMS_Pos          (24UL)         /*!< SPMS (Bit 24)                                         */
#define R_SPI_B0_SPCR_SPMS_Msk          (0x1000000UL)  /*!< SPMS (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCR_SPCIE_Pos         (21UL)         /*!< SPCIE (Bit 21)                                        */
#define R_SPI_B0_SPCR_SPCIE_Msk         (0x200000UL)   /*!< SPCIE (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCR_SPTIE_Pos         (20UL)         /*!< SPTIE (Bit 20)                                        */
#define R_SPI_B0_SPCR_SPTIE_Msk         (0x100000UL)   /*!< SPTIE (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCR_RDRIS_Pos         (19UL)         /*!< RDRIS (Bit 19)                                        */
#define R_SPI_B0_SPCR_RDRIS_Msk         (0x80000UL)    /*!< RDRIS (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCR_SPIIE_Pos         (18UL)         /*!< SPIIE (Bit 18)                                        */
#define R_SPI_B0_SPCR_SPIIE_Msk         (0x40000UL)    /*!< SPIIE (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCR_SPRIE_Pos         (17UL)         /*!< SPRIE (Bit 17)                                        */
#define R_SPI_B0_SPCR_SPRIE_Msk         (0x20000UL)    /*!< SPRIE (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCR_SPEIE_Pos         (16UL)         /*!< SPEIE (Bit 16)                                        */
#define R_SPI_B0_SPCR_SPEIE_Msk         (0x10000UL)    /*!< SPEIE (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCR_MODFEN_Pos        (14UL)         /*!< MODFEN (Bit 14)                                       */
#define R_SPI_B0_SPCR_MODFEN_Msk        (0x4000UL)     /*!< MODFEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCR_SCKDDIS_Pos       (13UL)         /*!< SCKDDIS (Bit 13)                                      */
#define R_SPI_B0_SPCR_SCKDDIS_Msk       (0x2000UL)     /*!< SCKDDIS (Bitfield-Mask: 0x01)                         */
#define R_SPI_B0_SPCR_SCKASE_Pos        (12UL)         /*!< SCKASE (Bit 12)                                       */
#define R_SPI_B0_SPCR_SCKASE_Msk        (0x1000UL)     /*!< SCKASE (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCR_PTE_Pos           (11UL)         /*!< PTE (Bit 11)                                          */
#define R_SPI_B0_SPCR_PTE_Msk           (0x800UL)      /*!< PTE (Bitfield-Mask: 0x01)                             */
#define R_SPI_B0_SPCR_SPOE_Pos          (9UL)          /*!< SPOE (Bit 9)                                          */
#define R_SPI_B0_SPCR_SPOE_Msk          (0x200UL)      /*!< SPOE (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCR_SPPE_Pos          (8UL)          /*!< SPPE (Bit 8)                                          */
#define R_SPI_B0_SPCR_SPPE_Msk          (0x100UL)      /*!< SPPE (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCR_SPE_Pos           (0UL)          /*!< SPE (Bit 0)                                           */
#define R_SPI_B0_SPCR_SPE_Msk           (0x1UL)        /*!< SPE (Bitfield-Mask: 0x01)                             */
/* ========================================================  SPRMCR  ========================================================= */
#define R_SPI_B0_SPRMCR_START_Pos       (7UL)          /*!< START (Bit 7)                                         */
#define R_SPI_B0_SPRMCR_START_Msk       (0x80UL)       /*!< START (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPRMCR_TERM_Pos        (6UL)          /*!< TERM (Bit 6)                                          */
#define R_SPI_B0_SPRMCR_TERM_Msk        (0x40UL)       /*!< TERM (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPRMCR_RFC_Pos         (0UL)          /*!< RFC (Bit 0)                                           */
#define R_SPI_B0_SPRMCR_RFC_Msk         (0x1fUL)       /*!< RFC (Bitfield-Mask: 0x1f)                             */
/* ========================================================  SPDRCSR  ======================================================== */
#define R_SPI_B0_SPDRCSR_SPDRCSR_Pos    (0UL)          /*!< SPDRCSR (Bit 0)                                       */
#define R_SPI_B0_SPDRCSR_SPDRCSR_Msk    (0xffUL)       /*!< SPDRCSR (Bitfield-Mask: 0xff)                         */
/* =========================================================  SPPCR  ========================================================= */
#define R_SPI_B0_SPPCR_MOIFE_Pos        (5UL)          /*!< MOIFE (Bit 5)                                         */
#define R_SPI_B0_SPPCR_MOIFE_Msk        (0x20UL)       /*!< MOIFE (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPPCR_MOIFV_Pos        (4UL)          /*!< MOIFV (Bit 4)                                         */
#define R_SPI_B0_SPPCR_MOIFV_Msk        (0x10UL)       /*!< MOIFV (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPPCR_SPLP2_Pos        (1UL)          /*!< SPLP2 (Bit 1)                                         */
#define R_SPI_B0_SPPCR_SPLP2_Msk        (0x2UL)        /*!< SPLP2 (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPPCR_SPLP_Pos         (0UL)          /*!< SPLP (Bit 0)                                          */
#define R_SPI_B0_SPPCR_SPLP_Msk         (0x1UL)        /*!< SPLP (Bitfield-Mask: 0x01)                            */
/* =========================================================  SSLP  ========================================================== */
#define R_SPI_B0_SSLP_SSL3P_Pos         (3UL)          /*!< SSL3P (Bit 3)                                         */
#define R_SPI_B0_SSLP_SSL3P_Msk         (0x8UL)        /*!< SSL3P (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SSLP_SSL2P_Pos         (2UL)          /*!< SSL2P (Bit 2)                                         */
#define R_SPI_B0_SSLP_SSL2P_Msk         (0x4UL)        /*!< SSL2P (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SSLP_SSL1P_Pos         (1UL)          /*!< SSL1P (Bit 1)                                         */
#define R_SPI_B0_SSLP_SSL1P_Msk         (0x2UL)        /*!< SSL1P (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SSLP_SSL0P_Pos         (0UL)          /*!< SSL0P (Bit 0)                                         */
#define R_SPI_B0_SSLP_SSL0P_Msk         (0x1UL)        /*!< SSL0P (Bitfield-Mask: 0x01)                           */
/* =========================================================  SPBR  ========================================================== */
#define R_SPI_B0_SPBR_SPBR_Pos          (0UL)          /*!< SPBR (Bit 0)                                          */
#define R_SPI_B0_SPBR_SPBR_Msk          (0xffUL)       /*!< SPBR (Bitfield-Mask: 0xff)                            */
/* =========================================================  SPSCR  ========================================================= */
#define R_SPI_B0_SPSCR_SPSLN_Pos        (0UL)          /*!< SPSLN (Bit 0)                                         */
#define R_SPI_B0_SPSCR_SPSLN_Msk        (0x7UL)        /*!< SPSLN (Bitfield-Mask: 0x07)                           */
/* ========================================================  SPCMD0  ========================================================= */
#define R_SPI_B0_SPCMD0_CPHA_Pos        (0UL)          /*!< CPHA (Bit 0)                                          */
#define R_SPI_B0_SPCMD0_CPHA_Msk        (0x1UL)        /*!< CPHA (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD0_CPOL_Pos        (1UL)          /*!< CPOL (Bit 1)                                          */
#define R_SPI_B0_SPCMD0_CPOL_Msk        (0x2UL)        /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD0_BRDV_Pos        (2UL)          /*!< BRDV (Bit 2)                                          */
#define R_SPI_B0_SPCMD0_BRDV_Msk        (0xcUL)        /*!< BRDV (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPCMD0_SSLKP_Pos       (7UL)          /*!< SSLKP (Bit 7)                                         */
#define R_SPI_B0_SPCMD0_SSLKP_Msk       (0x80UL)       /*!< SSLKP (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCMD0_LSBF_Pos        (12UL)         /*!< LSBF (Bit 12)                                         */
#define R_SPI_B0_SPCMD0_LSBF_Msk        (0x1000UL)     /*!< LSBF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD0_SPNDEN_Pos      (13UL)         /*!< SPNDEN (Bit 13)                                       */
#define R_SPI_B0_SPCMD0_SPNDEN_Msk      (0x2000UL)     /*!< SPNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD0_SLNDEN_Pos      (14UL)         /*!< SLNDEN (Bit 14)                                       */
#define R_SPI_B0_SPCMD0_SLNDEN_Msk      (0x4000UL)     /*!< SLNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD0_SCKDEN_Pos      (15UL)         /*!< SCKDEN (Bit 15)                                       */
#define R_SPI_B0_SPCMD0_SCKDEN_Msk      (0x8000UL)     /*!< SCKDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD0_SPB_Pos         (16UL)         /*!< SPB (Bit 16)                                          */
#define R_SPI_B0_SPCMD0_SPB_Msk         (0x1f0000UL)   /*!< SPB (Bitfield-Mask: 0x1f)                             */
#define R_SPI_B0_SPCMD0_SSLA_Pos        (24UL)         /*!< SSLA (Bit 24)                                         */
#define R_SPI_B0_SPCMD0_SSLA_Msk        (0x7000000UL)  /*!< SSLA (Bitfield-Mask: 0x07)                            */
/* ========================================================  SPCMD1  ========================================================= */
#define R_SPI_B0_SPCMD1_CPHA_Pos        (0UL)          /*!< CPHA (Bit 0)                                          */
#define R_SPI_B0_SPCMD1_CPHA_Msk        (0x1UL)        /*!< CPHA (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD1_CPOL_Pos        (1UL)          /*!< CPOL (Bit 1)                                          */
#define R_SPI_B0_SPCMD1_CPOL_Msk        (0x2UL)        /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD1_BRDV_Pos        (2UL)          /*!< BRDV (Bit 2)                                          */
#define R_SPI_B0_SPCMD1_BRDV_Msk        (0xcUL)        /*!< BRDV (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPCMD1_SSLKP_Pos       (7UL)          /*!< SSLKP (Bit 7)                                         */
#define R_SPI_B0_SPCMD1_SSLKP_Msk       (0x80UL)       /*!< SSLKP (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCMD1_LSBF_Pos        (12UL)         /*!< LSBF (Bit 12)                                         */
#define R_SPI_B0_SPCMD1_LSBF_Msk        (0x1000UL)     /*!< LSBF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD1_SPNDEN_Pos      (13UL)         /*!< SPNDEN (Bit 13)                                       */
#define R_SPI_B0_SPCMD1_SPNDEN_Msk      (0x2000UL)     /*!< SPNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD1_SLNDEN_Pos      (14UL)         /*!< SLNDEN (Bit 14)                                       */
#define R_SPI_B0_SPCMD1_SLNDEN_Msk      (0x4000UL)     /*!< SLNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD1_SCKDEN_Pos      (15UL)         /*!< SCKDEN (Bit 15)                                       */
#define R_SPI_B0_SPCMD1_SCKDEN_Msk      (0x8000UL)     /*!< SCKDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD1_SPB_Pos         (16UL)         /*!< SPB (Bit 16)                                          */
#define R_SPI_B0_SPCMD1_SPB_Msk         (0x1f0000UL)   /*!< SPB (Bitfield-Mask: 0x1f)                             */
#define R_SPI_B0_SPCMD1_SSLA_Pos        (24UL)         /*!< SSLA (Bit 24)                                         */
#define R_SPI_B0_SPCMD1_SSLA_Msk        (0x7000000UL)  /*!< SSLA (Bitfield-Mask: 0x07)                            */
/* ========================================================  SPCMD2  ========================================================= */
#define R_SPI_B0_SPCMD2_CPHA_Pos        (0UL)          /*!< CPHA (Bit 0)                                          */
#define R_SPI_B0_SPCMD2_CPHA_Msk        (0x1UL)        /*!< CPHA (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD2_CPOL_Pos        (1UL)          /*!< CPOL (Bit 1)                                          */
#define R_SPI_B0_SPCMD2_CPOL_Msk        (0x2UL)        /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD2_BRDV_Pos        (2UL)          /*!< BRDV (Bit 2)                                          */
#define R_SPI_B0_SPCMD2_BRDV_Msk        (0xcUL)        /*!< BRDV (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPCMD2_SSLKP_Pos       (7UL)          /*!< SSLKP (Bit 7)                                         */
#define R_SPI_B0_SPCMD2_SSLKP_Msk       (0x80UL)       /*!< SSLKP (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCMD2_LSBF_Pos        (12UL)         /*!< LSBF (Bit 12)                                         */
#define R_SPI_B0_SPCMD2_LSBF_Msk        (0x1000UL)     /*!< LSBF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD2_SPNDEN_Pos      (13UL)         /*!< SPNDEN (Bit 13)                                       */
#define R_SPI_B0_SPCMD2_SPNDEN_Msk      (0x2000UL)     /*!< SPNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD2_SLNDEN_Pos      (14UL)         /*!< SLNDEN (Bit 14)                                       */
#define R_SPI_B0_SPCMD2_SLNDEN_Msk      (0x4000UL)     /*!< SLNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD2_SCKDEN_Pos      (15UL)         /*!< SCKDEN (Bit 15)                                       */
#define R_SPI_B0_SPCMD2_SCKDEN_Msk      (0x8000UL)     /*!< SCKDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD2_SPB_Pos         (16UL)         /*!< SPB (Bit 16)                                          */
#define R_SPI_B0_SPCMD2_SPB_Msk         (0x1f0000UL)   /*!< SPB (Bitfield-Mask: 0x1f)                             */
#define R_SPI_B0_SPCMD2_SSLA_Pos        (24UL)         /*!< SSLA (Bit 24)                                         */
#define R_SPI_B0_SPCMD2_SSLA_Msk        (0x7000000UL)  /*!< SSLA (Bitfield-Mask: 0x07)                            */
/* ========================================================  SPCMD3  ========================================================= */
#define R_SPI_B0_SPCMD3_CPHA_Pos        (0UL)          /*!< CPHA (Bit 0)                                          */
#define R_SPI_B0_SPCMD3_CPHA_Msk        (0x1UL)        /*!< CPHA (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD3_CPOL_Pos        (1UL)          /*!< CPOL (Bit 1)                                          */
#define R_SPI_B0_SPCMD3_CPOL_Msk        (0x2UL)        /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD3_BRDV_Pos        (2UL)          /*!< BRDV (Bit 2)                                          */
#define R_SPI_B0_SPCMD3_BRDV_Msk        (0xcUL)        /*!< BRDV (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPCMD3_SSLKP_Pos       (7UL)          /*!< SSLKP (Bit 7)                                         */
#define R_SPI_B0_SPCMD3_SSLKP_Msk       (0x80UL)       /*!< SSLKP (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCMD3_LSBF_Pos        (12UL)         /*!< LSBF (Bit 12)                                         */
#define R_SPI_B0_SPCMD3_LSBF_Msk        (0x1000UL)     /*!< LSBF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD3_SPNDEN_Pos      (13UL)         /*!< SPNDEN (Bit 13)                                       */
#define R_SPI_B0_SPCMD3_SPNDEN_Msk      (0x2000UL)     /*!< SPNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD3_SLNDEN_Pos      (14UL)         /*!< SLNDEN (Bit 14)                                       */
#define R_SPI_B0_SPCMD3_SLNDEN_Msk      (0x4000UL)     /*!< SLNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD3_SCKDEN_Pos      (15UL)         /*!< SCKDEN (Bit 15)                                       */
#define R_SPI_B0_SPCMD3_SCKDEN_Msk      (0x8000UL)     /*!< SCKDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD3_SPB_Pos         (16UL)         /*!< SPB (Bit 16)                                          */
#define R_SPI_B0_SPCMD3_SPB_Msk         (0x1f0000UL)   /*!< SPB (Bitfield-Mask: 0x1f)                             */
#define R_SPI_B0_SPCMD3_SSLA_Pos        (24UL)         /*!< SSLA (Bit 24)                                         */
#define R_SPI_B0_SPCMD3_SSLA_Msk        (0x7000000UL)  /*!< SSLA (Bitfield-Mask: 0x07)                            */
/* ========================================================  SPCMD4  ========================================================= */
#define R_SPI_B0_SPCMD4_CPHA_Pos        (0UL)          /*!< CPHA (Bit 0)                                          */
#define R_SPI_B0_SPCMD4_CPHA_Msk        (0x1UL)        /*!< CPHA (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD4_CPOL_Pos        (1UL)          /*!< CPOL (Bit 1)                                          */
#define R_SPI_B0_SPCMD4_CPOL_Msk        (0x2UL)        /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD4_BRDV_Pos        (2UL)          /*!< BRDV (Bit 2)                                          */
#define R_SPI_B0_SPCMD4_BRDV_Msk        (0xcUL)        /*!< BRDV (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPCMD4_SSLKP_Pos       (7UL)          /*!< SSLKP (Bit 7)                                         */
#define R_SPI_B0_SPCMD4_SSLKP_Msk       (0x80UL)       /*!< SSLKP (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCMD4_LSBF_Pos        (12UL)         /*!< LSBF (Bit 12)                                         */
#define R_SPI_B0_SPCMD4_LSBF_Msk        (0x1000UL)     /*!< LSBF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD4_SPNDEN_Pos      (13UL)         /*!< SPNDEN (Bit 13)                                       */
#define R_SPI_B0_SPCMD4_SPNDEN_Msk      (0x2000UL)     /*!< SPNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD4_SLNDEN_Pos      (14UL)         /*!< SLNDEN (Bit 14)                                       */
#define R_SPI_B0_SPCMD4_SLNDEN_Msk      (0x4000UL)     /*!< SLNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD4_SCKDEN_Pos      (15UL)         /*!< SCKDEN (Bit 15)                                       */
#define R_SPI_B0_SPCMD4_SCKDEN_Msk      (0x8000UL)     /*!< SCKDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD4_SPB_Pos         (16UL)         /*!< SPB (Bit 16)                                          */
#define R_SPI_B0_SPCMD4_SPB_Msk         (0x1f0000UL)   /*!< SPB (Bitfield-Mask: 0x1f)                             */
#define R_SPI_B0_SPCMD4_SSLA_Pos        (24UL)         /*!< SSLA (Bit 24)                                         */
#define R_SPI_B0_SPCMD4_SSLA_Msk        (0x7000000UL)  /*!< SSLA (Bitfield-Mask: 0x07)                            */
/* ========================================================  SPCMD5  ========================================================= */
#define R_SPI_B0_SPCMD5_CPHA_Pos        (0UL)          /*!< CPHA (Bit 0)                                          */
#define R_SPI_B0_SPCMD5_CPHA_Msk        (0x1UL)        /*!< CPHA (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD5_CPOL_Pos        (1UL)          /*!< CPOL (Bit 1)                                          */
#define R_SPI_B0_SPCMD5_CPOL_Msk        (0x2UL)        /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD5_BRDV_Pos        (2UL)          /*!< BRDV (Bit 2)                                          */
#define R_SPI_B0_SPCMD5_BRDV_Msk        (0xcUL)        /*!< BRDV (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPCMD5_SSLKP_Pos       (7UL)          /*!< SSLKP (Bit 7)                                         */
#define R_SPI_B0_SPCMD5_SSLKP_Msk       (0x80UL)       /*!< SSLKP (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCMD5_LSBF_Pos        (12UL)         /*!< LSBF (Bit 12)                                         */
#define R_SPI_B0_SPCMD5_LSBF_Msk        (0x1000UL)     /*!< LSBF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD5_SPNDEN_Pos      (13UL)         /*!< SPNDEN (Bit 13)                                       */
#define R_SPI_B0_SPCMD5_SPNDEN_Msk      (0x2000UL)     /*!< SPNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD5_SLNDEN_Pos      (14UL)         /*!< SLNDEN (Bit 14)                                       */
#define R_SPI_B0_SPCMD5_SLNDEN_Msk      (0x4000UL)     /*!< SLNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD5_SCKDEN_Pos      (15UL)         /*!< SCKDEN (Bit 15)                                       */
#define R_SPI_B0_SPCMD5_SCKDEN_Msk      (0x8000UL)     /*!< SCKDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD5_SPB_Pos         (16UL)         /*!< SPB (Bit 16)                                          */
#define R_SPI_B0_SPCMD5_SPB_Msk         (0x1f0000UL)   /*!< SPB (Bitfield-Mask: 0x1f)                             */
#define R_SPI_B0_SPCMD5_SSLA_Pos        (24UL)         /*!< SSLA (Bit 24)                                         */
#define R_SPI_B0_SPCMD5_SSLA_Msk        (0x7000000UL)  /*!< SSLA (Bitfield-Mask: 0x07)                            */
/* ========================================================  SPCMD6  ========================================================= */
#define R_SPI_B0_SPCMD6_CPHA_Pos        (0UL)          /*!< CPHA (Bit 0)                                          */
#define R_SPI_B0_SPCMD6_CPHA_Msk        (0x1UL)        /*!< CPHA (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD6_CPOL_Pos        (1UL)          /*!< CPOL (Bit 1)                                          */
#define R_SPI_B0_SPCMD6_CPOL_Msk        (0x2UL)        /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD6_BRDV_Pos        (2UL)          /*!< BRDV (Bit 2)                                          */
#define R_SPI_B0_SPCMD6_BRDV_Msk        (0xcUL)        /*!< BRDV (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPCMD6_SSLKP_Pos       (7UL)          /*!< SSLKP (Bit 7)                                         */
#define R_SPI_B0_SPCMD6_SSLKP_Msk       (0x80UL)       /*!< SSLKP (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCMD6_LSBF_Pos        (12UL)         /*!< LSBF (Bit 12)                                         */
#define R_SPI_B0_SPCMD6_LSBF_Msk        (0x1000UL)     /*!< LSBF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD6_SPNDEN_Pos      (13UL)         /*!< SPNDEN (Bit 13)                                       */
#define R_SPI_B0_SPCMD6_SPNDEN_Msk      (0x2000UL)     /*!< SPNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD6_SLNDEN_Pos      (14UL)         /*!< SLNDEN (Bit 14)                                       */
#define R_SPI_B0_SPCMD6_SLNDEN_Msk      (0x4000UL)     /*!< SLNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD6_SCKDEN_Pos      (15UL)         /*!< SCKDEN (Bit 15)                                       */
#define R_SPI_B0_SPCMD6_SCKDEN_Msk      (0x8000UL)     /*!< SCKDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD6_SPB_Pos         (16UL)         /*!< SPB (Bit 16)                                          */
#define R_SPI_B0_SPCMD6_SPB_Msk         (0x1f0000UL)   /*!< SPB (Bitfield-Mask: 0x1f)                             */
#define R_SPI_B0_SPCMD6_SSLA_Pos        (24UL)         /*!< SSLA (Bit 24)                                         */
#define R_SPI_B0_SPCMD6_SSLA_Msk        (0x7000000UL)  /*!< SSLA (Bitfield-Mask: 0x07)                            */
/* ========================================================  SPCMD7  ========================================================= */
#define R_SPI_B0_SPCMD7_CPHA_Pos        (0UL)          /*!< CPHA (Bit 0)                                          */
#define R_SPI_B0_SPCMD7_CPHA_Msk        (0x1UL)        /*!< CPHA (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD7_CPOL_Pos        (1UL)          /*!< CPOL (Bit 1)                                          */
#define R_SPI_B0_SPCMD7_CPOL_Msk        (0x2UL)        /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD7_BRDV_Pos        (2UL)          /*!< BRDV (Bit 2)                                          */
#define R_SPI_B0_SPCMD7_BRDV_Msk        (0xcUL)        /*!< BRDV (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPCMD7_SSLKP_Pos       (7UL)          /*!< SSLKP (Bit 7)                                         */
#define R_SPI_B0_SPCMD7_SSLKP_Msk       (0x80UL)       /*!< SSLKP (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPCMD7_LSBF_Pos        (12UL)         /*!< LSBF (Bit 12)                                         */
#define R_SPI_B0_SPCMD7_LSBF_Msk        (0x1000UL)     /*!< LSBF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPCMD7_SPNDEN_Pos      (13UL)         /*!< SPNDEN (Bit 13)                                       */
#define R_SPI_B0_SPCMD7_SPNDEN_Msk      (0x2000UL)     /*!< SPNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD7_SLNDEN_Pos      (14UL)         /*!< SLNDEN (Bit 14)                                       */
#define R_SPI_B0_SPCMD7_SLNDEN_Msk      (0x4000UL)     /*!< SLNDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD7_SCKDEN_Pos      (15UL)         /*!< SCKDEN (Bit 15)                                       */
#define R_SPI_B0_SPCMD7_SCKDEN_Msk      (0x8000UL)     /*!< SCKDEN (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPCMD7_SPB_Pos         (16UL)         /*!< SPB (Bit 16)                                          */
#define R_SPI_B0_SPCMD7_SPB_Msk         (0x1f0000UL)   /*!< SPB (Bitfield-Mask: 0x1f)                             */
#define R_SPI_B0_SPCMD7_SSLA_Pos        (24UL)         /*!< SSLA (Bit 24)                                         */
#define R_SPI_B0_SPCMD7_SSLA_Msk        (0x7000000UL)  /*!< SSLA (Bitfield-Mask: 0x07)                            */
/* =========================================================  SPDCR  ========================================================= */
#define R_SPI_B0_SPDCR_SPFC_Pos         (8UL)          /*!< SPFC (Bit 8)                                          */
#define R_SPI_B0_SPDCR_SPFC_Msk         (0x300UL)      /*!< SPFC (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPDCR_DINV_Pos         (4UL)          /*!< DINV (Bit 4)                                          */
#define R_SPI_B0_SPDCR_DINV_Msk         (0x10UL)       /*!< DINV (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPDCR_SPRDTD_Pos       (3UL)          /*!< SPRDTD (Bit 3)                                        */
#define R_SPI_B0_SPDCR_SPRDTD_Msk       (0x8UL)        /*!< SPRDTD (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPDCR_BYSW_Pos         (0UL)          /*!< BYSW (Bit 0)                                          */
#define R_SPI_B0_SPDCR_BYSW_Msk         (0x1UL)        /*!< BYSW (Bitfield-Mask: 0x01)                            */
/* =========================================================  SPFCR  ========================================================= */
#define R_SPI_B0_SPFCR_TTRG_Pos         (8UL)          /*!< TTRG (Bit 8)                                          */
#define R_SPI_B0_SPFCR_TTRG_Msk         (0x300UL)      /*!< TTRG (Bitfield-Mask: 0x03)                            */
#define R_SPI_B0_SPFCR_RTRG_Pos         (0UL)          /*!< RTRG (Bit 0)                                          */
#define R_SPI_B0_SPFCR_RTRG_Msk         (0x3UL)        /*!< RTRG (Bitfield-Mask: 0x03)                            */
/* =========================================================  SPSSR  ========================================================= */
#define R_SPI_B0_SPSSR_SPECM_Pos        (4UL)          /*!< SPECM (Bit 4)                                         */
#define R_SPI_B0_SPSSR_SPECM_Msk        (0x70UL)       /*!< SPECM (Bitfield-Mask: 0x07)                           */
#define R_SPI_B0_SPSSR_SPCP_Pos         (0UL)          /*!< SPCP (Bit 0)                                          */
#define R_SPI_B0_SPSSR_SPCP_Msk         (0x7UL)        /*!< SPCP (Bitfield-Mask: 0x07)                            */
/* =========================================================  SPSR  ========================================================== */
#define R_SPI_B0_SPSR_SPRF_Pos          (15UL)         /*!< SPRF (Bit 15)                                         */
#define R_SPI_B0_SPSR_SPRF_Msk          (0x8000UL)     /*!< SPRF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPSR_SPCF_Pos          (14UL)         /*!< SPCF (Bit 14)                                         */
#define R_SPI_B0_SPSR_SPCF_Msk          (0x4000UL)     /*!< SPCF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPSR_SPTEF_Pos         (13UL)         /*!< SPTEF (Bit 13)                                        */
#define R_SPI_B0_SPSR_SPTEF_Msk         (0x2000UL)     /*!< SPTEF (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPSR_UDRF_Pos          (12UL)         /*!< UDRF (Bit 12)                                         */
#define R_SPI_B0_SPSR_UDRF_Msk          (0x1000UL)     /*!< UDRF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPSR_PERF_Pos          (11UL)         /*!< PERF (Bit 11)                                         */
#define R_SPI_B0_SPSR_PERF_Msk          (0x800UL)      /*!< PERF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPSR_MODF_Pos          (10UL)         /*!< MODF (Bit 10)                                         */
#define R_SPI_B0_SPSR_MODF_Msk          (0x400UL)      /*!< MODF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPSR_IDLNF_Pos         (9UL)          /*!< IDLNF (Bit 9)                                         */
#define R_SPI_B0_SPSR_IDLNF_Msk         (0x200UL)      /*!< IDLNF (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPSR_OVRF_Pos          (8UL)          /*!< OVRF (Bit 8)                                          */
#define R_SPI_B0_SPSR_OVRF_Msk          (0x100UL)      /*!< OVRF (Bitfield-Mask: 0x01)                            */
#define R_SPI_B0_SPSR_RRDYF_Pos         (7UL)          /*!< RRDYF (Bit 7)                                         */
#define R_SPI_B0_SPSR_RRDYF_Msk         (0x80UL)       /*!< RRDYF (Bitfield-Mask: 0x01)                           */
/* ========================================================  SPTFSR  ========================================================= */
#define R_SPI_B0_SPTFSR_FREE_Pos        (0UL)          /*!< FREE (Bit 0)                                          */
#define R_SPI_B0_SPTFSR_FREE_Msk        (0x7UL)        /*!< FREE (Bitfield-Mask: 0x07)                            */
/* ========================================================  SPRFSR  ========================================================= */
#define R_SPI_B0_SPRFSR_FILL_Pos        (0UL)          /*!< FILL (Bit 0)                                          */
#define R_SPI_B0_SPRFSR_FILL_Msk        (0x7UL)        /*!< FILL (Bitfield-Mask: 0x07)                            */
/* =========================================================  SPPSR  ========================================================= */
#define R_RSPIA2_SPPSR_SPEPS_Pos        (0UL)          /*!< SPEPS (Bit 0)                                         */
#define R_RSPIA2_SPPSR_SPEPS_Msk        (0x1UL)        /*!< SPEPS (Bitfield-Mask: 0x01)                           */
/* ========================================================  SPSCLR  ========================================================= */
#define R_SPI_B0_SPSCLR_SPRFC_Pos       (15UL)         /*!< SPRFC (Bit 15)                                        */
#define R_SPI_B0_SPSCLR_SPRFC_Msk       (0x8000UL)     /*!< SPRFC (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPSCLR_SPCFC_Pos       (14UL)         /*!< SPCFC (Bit 14)                                        */
#define R_SPI_B0_SPSCLR_SPCFC_Msk       (0x4000UL)     /*!< SPCFC (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPSCLR_SPTEFC_Pos      (13UL)         /*!< SPTEFC (Bit 13)                                       */
#define R_SPI_B0_SPSCLR_SPTEFC_Msk      (0x2000UL)     /*!< SPTEFC (Bitfield-Mask: 0x01)                          */
#define R_SPI_B0_SPSCLR_UDRFC_Pos       (12UL)         /*!< UDRFC (Bit 12)                                        */
#define R_SPI_B0_SPSCLR_UDRFC_Msk       (0x1000UL)     /*!< UDRFC (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPSCLR_PERFC_Pos       (11UL)         /*!< PERFC (Bit 11)                                        */
#define R_SPI_B0_SPSCLR_PERFC_Msk       (0x800UL)      /*!< PERFC (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPSCLR_MODFC_Pos       (10UL)         /*!< MODFC (Bit 10)                                        */
#define R_SPI_B0_SPSCLR_MODFC_Msk       (0x400UL)      /*!< MODFC (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPSCLR_OVRFC_Pos       (8UL)          /*!< OVRFC (Bit 8)                                         */
#define R_SPI_B0_SPSCLR_OVRFC_Msk       (0x100UL)      /*!< OVRFC (Bitfield-Mask: 0x01)                           */
#define R_SPI_B0_SPSCLR_RRDYFC_Pos      (7UL)          /*!< RRDYFC (Bit 7)                                        */
#define R_SPI_B0_SPSCLR_RRDYFC_Msk      (0x80UL)       /*!< RRDYFC (Bitfield-Mask: 0x01)                          */
/* ========================================================  SPFCLR  ========================================================= */
#define R_SPI_B0_SPFCLR_FCLR_Pos        (0UL)          /*!< FCLR (Bit 0)                                          */
#define R_SPI_B0_SPFCLR_FCLR_Msk        (0x1UL)        /*!< FCLR (Bitfield-Mask: 0x01)                            */

#endif /* R_SPI_B_POSMSK_H */
