/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef FSP_VERSION_H
 #define FSP_VERSION_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Includes board and MPU related header files. */
 #include "bsp_api.h"

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZA
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_RENESAS_COMMON
 * @{
 **********************************************************************************************************************/

 #ifdef __cplusplus
extern "C" {
 #endif

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** FSP pack major version. */
 #define FSP_VERSION_MAJOR (4U)

/** FSP pack minor version. */
 #define FSP_VERSION_MINOR (2U)

/** FSP pack patch version. */
 #define FSP_VERSION_PATCH (0U)

/** FSP pack version build number (currently unused). */
 #define FSP_VERSION_BUILD           (0U)

/** Public FSP version name. */
 #define FSP_VERSION_STRING          ("4.2.0")

/** Unique FSP version ID. */
 #define FSP_VERSION_BUILD_STRING    ("Built with RZ/A Flexible Software Package version 4.2.0")

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** FSP Pack version structure */
union st_fsp_pack_version
{
    /** Version id */
    uint32_t version_id;

    /**
     * Code version parameters, little endian order.
     */
    struct version_id_b_s
    {
        uint8_t build;                 ///< Build version of FSP Pack
        uint8_t patch;                 ///< Patch version of FSP Pack
        uint8_t minor;                 ///< Minor version of FSP Pack
        uint8_t major;                 ///< Major version of FSP Pack
    } version_id_b;
};

/** FSP Pack version structure. Please refer to the struct st_fsp_pack_version. */
typedef union st_fsp_pack_version fsp_pack_version_t;

 #ifdef __cplusplus
}
 #endif

/** @} */

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

#endif
