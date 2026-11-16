/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef _ALLOCA_H
#define _ALLOCA_H

/* Provide RH850 alloca implementation in case compiler does not support */

#if defined(__ICCRH850__)
#define alloca(_Size)       NULL

#endif

#endif /* _ALLOCA_H */
