/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SPIBSC_PRIVATE_H
#define R_SPIBSC_PRIVATE_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Data picker utility macros */
#define PICK_LL(a)                                ((a) % 256U)
#define PICK_LH(a)                                (((a) >> 8) % 256U)
#define PICK_HL(a)                                (((a) >> 16) % 256U)
#define PICK_HH(a)                                (((a) >> 24) % 256U)

/* Clear and Set utility macros */
#define MMIO_WRITE_32(_reg, _value)               _reg = _value
#define MMIO_WRITE_16(_reg, _value)               _reg = _value
#define MMIO_WRITE_8(_reg, _value)                _reg = _value
#define MMIO_READ_32(_reg)                        _reg
#define MMIO_CLRSETBITS_32(_reg, _clear, _set)    _reg = ((_reg) & (uint32_t) ~(_clear)) | (uint32_t) (_set)
#define MMIO_CLRBITS_32(_reg, _clear)             _reg = (_reg) & (uint32_t) ~(_clear)
#define MMIO_SETBITS_32(_reg, _set)               _reg = (_reg) | (uint32_t) (_set)

/* CMNCR field */
#define SPIBSC_CMNCR_IO_LOW           (0U)
#define SPIBSC_CMNCR_IO_HIGH          (1U)
#define SPIBSC_CMNCR_IO_KEEP          (2U)
#define SPIBSC_CMNCR_IO_HIZ           (3U)
#define SPIBSC_CMNCR_BSZ_SINGLE       (0U)
#define SPIBSC_CMNCR_BSZ_DUAL         (1U)
#define SPIBSC_CMNCR_BSZ_OCTA         (1U)
#define SPIBSC_CMNCR_BSZ_HYPER        (1U)

/* DRENR field */
#define SPIBSC_DRENR_DB_4BIT          (2U)
#define SPIBSC_DRENR_DB_1BIT          (0U)
#define SPIBSC_DRENR_ADE_3BYTE        (7U)
#define SPIBSC_DRENR_ADE_4BYTE        (15U)
#define SPIBSC_DRENR_ADE_OPI          (12U)
#define SPIBSC_DRENR_ADE_HYPER        (4U)
#define SPIBSC_DRENR_ADE_NONE         (0U)
#define SPIBSC_DRENR_OPDE_NONE        (0U)
#define SPIBSC_DRENR_OPDE_1BYTE       (8U)
#define SPIBSC_DRENR_OPDE_2BYTE       (12U)
#define SPIBSC_DRENR_OPDE_3BYTE       (14U)
#define SPIBSC_DRENR_OPDE_4BYTE       (15U)
#define DRENR_FORM111                 (                       \
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_CDB_Pos |      \
            SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_OCDB_Pos | \
            SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_ADB_Pos |  \
            SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_OPDB_Pos | \
            SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_DRDB_Pos)
#define DRENR_FORM114                 (                       \
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_CDB_Pos |      \
            SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_OCDB_Pos | \
            SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_ADB_Pos |  \
            SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_OPDB_Pos | \
            SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_DRDB_Pos)
#define DRENR_FORM144                 (                       \
        SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_CDB_Pos |      \
            SPIBSC_DRENR_DB_1BIT << R_SPIBSC_DRENR_OCDB_Pos | \
            SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_ADB_Pos |  \
            SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_OPDB_Pos | \
            SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_DRDB_Pos)
#define DRENR_FORM444                 (                       \
        SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_CDB_Pos |      \
            SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_OCDB_Pos | \
            SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_ADB_Pos |  \
            SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_OPDB_Pos | \
            SPIBSC_DRENR_DB_4BIT << R_SPIBSC_DRENR_DRDB_Pos)
#define DRENR_COMMAND_DISABLE         (0U << R_SPIBSC_DRENR_CDE_Pos)                       ///< Command = disable
#define DRENR_COMMAND_ENABLE          (1U << R_SPIBSC_DRENR_CDE_Pos)                       ///< Command = enable
#define DRENR_OCOMMAND_DISABLE        (0U << R_SPIBSC_DRENR_OCDE_Pos)                      ///< Optional Command = disable
#define DRENR_OCOMMAND_ENABLE         (1U << R_SPIBSC_DRENR_OCDE_Pos)                      ///< Optional Command = enable
#define DRENR_ADR3BYTE                (SPIBSC_DRENR_ADE_3BYTE << R_SPIBSC_DRENR_ADE_Pos)   ///< Address = 3-byte
#define DRENR_ADR4BYTE                (SPIBSC_DRENR_ADE_4BYTE << R_SPIBSC_DRENR_ADE_Pos)   ///< Address = 4-byte
#define DRENR_ODATA_DISABLE           (SPIBSC_DRENR_OPDE_NONE << R_SPIBSC_DRENR_OPDE_Pos)  ///< Optional Data = disable
#define DRENR_ODATA_ENABLE            (SPIBSC_DRENR_OPDE_1BYTE << R_SPIBSC_DRENR_OPDE_Pos) ///< Optional Data = enable
#define DRENR_DUMMY_DISABLE           (0U << R_SPIBSC_DRENR_DME_Pos)                       ///< Dummy = disable
#define DRENR_DUMMY_ENABLE            (1U << R_SPIBSC_DRENR_DME_Pos)                       ///< Dummy = enable

/* SMENR field */
#define SPIBSC_SMENR_DB_4BIT          (2U)
#define SPIBSC_SMENR_DB_1BIT          (0U)
#define SPIBSC_SMENR_ADE_3BYTE        (7U)
#define SPIBSC_SMENR_ADE_4BYTE        (15U)
#define SPIBSC_SMENR_ADE_OPI          (12U)
#define SPIBSC_SMENR_ADE_HYPER        (4U)
#define SPIBSC_SMENR_ADE_NONE         (0U)
#define SPIBSC_SMENR_OPDE_NONE        (0U)
#define SPIBSC_SMENR_OPDE_1BYTE       (8U)
#define SPIBSC_SMENR_OPDE_2BYTE       (12U)
#define SPIBSC_SMENR_OPDE_3BYTE       (14U)
#define SPIBSC_SMENR_OPDE_4BYTE       (15U)
#define SPIBSC_SMENR_SPIDE_NONE       (0U)
#define SPIBSC_SMENR_SPIDE_BYTE       (8U)
#define SPIBSC_SMENR_SPIDE_WORD       (12U)
#define SPIBSC_SMENR_SPIDE_LONG       (15U)

/* DRDRENR field */
#define SPIBSC_DRDRENR_SPI            (0U)
#define SPIBSC_DRDRENR_DDR            (5U)
#define SPIBSC_DRDRENR_OCTADDR        (4U)

/* SMDRENR field */
#define SPIBSCSSCC_SMDRENR_SPI        (0U)
#define SPIBSCSSCC_SMDRENR_DDR        (5U)
#define SPIBSCSSCC_SMDRENR_OCTADDR    (4U)

/* PHYCNT field */
#define SPIBSC_PHYCNT_OCTA_DDR_ALT    (1U)
#define SPIBSC_PHYCNT_OCTA_DDR_SEQ    (2U)
#define SPIBSC_PHYCNT_SDR             (0U)
#define SPIBSC_PHYCNT_DDR             (1U)
#define SPIBSC_PHYCNT_HYPER           (3U)

/* PHYOFFSET1 field */
#define SPIBSC_PHYOFFSET1_DDR         (2U)
#define SPIBSC_PHYOFFSET1_SDR         (3U)

/* PHYOFFSET2 field */
#define SPIBSC_PHYOFFSET2_SPI         (4U)
#define SPIBSC_PHYOFFSET2_HYPER       (4U)
#define SPIBSC_PHYOFFSET2_SPI_WBUF    (0U)
#define SPIBSC_PHYOFFSET2_OPI         (3U)

/* Misc constants */
#define SPIBSC_BUFFER_SIZE            (256)

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup SPIBSC)
 **********************************************************************************************************************/
