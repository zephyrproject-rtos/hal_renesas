/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef SYSTEM_RENESAS_ARM_H
 #define SYSTEM_RENESAS_ARM_H

 #ifdef __cplusplus
extern "C" {
 #endif

 #include <stdint.h>

extern uint32_t SystemCoreClock;       /** System Clock Frequency (Core Clock)  */

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system(Secure).
 *         Initialize the System.
 */
extern void SystemInit_S(void);

/**
 * Warm reset
 *
 * @param  none
 * @return none
 *
 * @brief  Warm reset(Secure).
 *
 */
__attribute__((naked)) extern void Warm_Reset_S(void);

/**
 * Entry function
 *
 * @param  none
 * @return none
 *
 * @brief  Entry function for debugger(Secure).
 *
 */
__attribute__((naked)) extern void Entry_Function_S(void);

/**
 * XSPI boot entry
 *
 * @param  none
 * @return none
 *
 * @brief  Entry functon of XSPI boot mode(Secure).
 *
 */
__attribute__((naked)) extern void XSPI_Boot_Entry(void);

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit(void);

/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate(void);

 #ifdef __cplusplus
}
 #endif

#endif                                 /* SYSTEM_RENESAS_ARM_H */
