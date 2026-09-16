/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/** @} (end addtogroup BSP_MCU) */

#ifndef BSP_EXCEPTIONS_H
 #define BSP_EXCEPTIONS_H

 #ifdef __cplusplus
extern "C" {
 #endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* This list includes only RX exceptions. Renesas interrupts are defined in vector_data.h. */
typedef enum IRQn
{
    SecureFault_IRQn                           = -30,
    World_NonMaskableInt_IRQn                  = -26,
    PrivilegedInstructionException_IRQn        = -12,
    AccessException_IRQn                       = -11,
    UndefinedInstruction_IRQn                  = -9,
    AddressException_IRQn                      = -8,
    SinglePrecisionFloatingPointException_IRQn = -7,
    NonMaskableInt_IRQn                        = -2,
} IRQn_Type;

 #ifdef __cplusplus
}
 #endif

#endif
