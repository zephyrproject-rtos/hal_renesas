/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**************************************************************************//**
 * @file     rh850_version.h
 * @brief    RH850  Core Version Definitions
 * @version  V0.0.2
 * @date     01 Aug 2026
 ******************************************************************************/

/*
 * RH850-Core Version Definitions
 */

#ifndef __RH850_VERSION_H
#define __RH850_VERSION_H

/*  RH850-G4 Version definitions */
#define __G4_RH850_VERSION_MAIN    (1U)                     /*!< [31:16] RH850-G4 main version */
#define __G4_RH850_VERSION_SUB     (0U)                     /*!< [15:0]  RH850-G4 sub version */
#define __G4_RH850_VERSION         ((__G4_RH850_VERSION_MAIN << 16U) | \
                                    __G4_RH850_VERSION_SUB) /*!< RH850 G4 version number */
#endif
