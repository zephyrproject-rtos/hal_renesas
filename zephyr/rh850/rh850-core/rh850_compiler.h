/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**************************************************************************//**
 * @file     rh850_version.h
 * @brief    RH850 Compiler Generic Header File
 * @version  V0.0.2
 * @date     01 Aug 2026
 ******************************************************************************/

/*
 * RH850 Compiler Generic Header File
 */

#ifndef __RH850_COMPILER_H
#define __RH850_COMPILER_H

#include <stdint.h>

/*
 * CCRH Compiler
 */
#if defined(__CCRH__)
 #include "rh850_ccrh.h"

/*
 * GHS Compiler
 */
#elif (__ghs__)
 #include <v800_ghs.h>
 #include "rh850_ghs.h"

/*
 * IAR Compiler
 */
#elif defined(__ICCRH850__)
 #include <intrinsics.h>
 #include "rh850_iar.h"

/*
 * Not supported Compiler
 */
#else
 #error Unknown compiler.
#endif

#endif                                 /* __RH850_COMPILER_H */
