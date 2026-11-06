/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_g4_tsc.h
 * @brief    RH850 Time-Stamp Counter (TSC) control
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#if defined(__TSC_PRESENT) && (__TSC_PRESENT == 1U)

/** @defgroup RH850_CoreAccess_FunctionInterface RH850-Core Access Functions
 * @brief Access to the dedicated core access function.
 * @{
 */

/**
 * @defgroup RH850_TSC RH850 Time-Stamp Counter (TSC)
 * @ingroup RH850_CoreAccess_FunctionInterface
 * @brief    TSC API and data types
 * @{
 */

#ifndef RH850_G4_TSC_H
 #define RH850_G4_TSC_H

 #include <stdint.h>

/* #######################################  TSC Types and Enumerations  ############################################# */

/**
 * @defgroup RH850_TSC_Types TSC Types and Enumerations
 * @brief TSC Types and Enumerations
 * @ingroup  RH850_TSC
 * @{
 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**
 * @brief TSC enable state.
 */
typedef enum e_rh850_tsc_enable
{
    RH850_TSC_ENABLE_OFF = 0x0U,       /*!< Counter is disabled */
    RH850_TSC_ENABLE_ON  = 0x1U        /*!< Counter is enabled */
} rh850_tsc_enable_t;

/** @} */ /* end of RH850_TSC_Types */

/* ###########################################  TSC API Functions  ################################################## */

/**
 * @defgroup RH850_TSC_API TSC API Functions
 * @brief TSC API Functions
 * @ingroup  RH850_TSC
 * @{
 */

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/**
 * @brief   Enable the TSC counter (set TSCTRL.CEN).
 */
__STATIC_INLINE void __RH850_TSC_Enable (void)
{
    uint32_t LulTsctrlRegValue;

    /* Read current control register */
    LulTsctrlRegValue = __get_TSCTRL();

    /* Set CEN bit to enable counting */
    LulTsctrlRegValue |= R_TSC_TSCTRL_CEN_Msk;

    /* Write back updated control value */
    __set_TSCTRL(LulTsctrlRegValue);
}

/**
 * @brief   Disable the TSC counter (clear TSCTRL.CEN).
 */
__STATIC_INLINE void __RH850_TSC_Disable (void)
{
    uint32_t LulTsctrlRegValue;

    /* Read current control register */
    LulTsctrlRegValue = __get_TSCTRL();

    /* Clear CEN bit to disable counting */
    LulTsctrlRegValue &= (~R_TSC_TSCTRL_CEN_Msk);

    /* Write back updated control value */
    __set_TSCTRL(LulTsctrlRegValue);
}

/**
 * @brief   Clear the TSC overflow flag (clear TSCTRL.OVF).
 */
__STATIC_INLINE void __RH850_TSC_OverflowClear (void)
{
    uint32_t LulTsctrlRegValue;

    /* Read current control register */
    LulTsctrlRegValue = __get_TSCTRL();

    /* Clear OVF status bit */
    LulTsctrlRegValue &= (~R_TSC_TSCTRL_OVF_Msk);

    /* Write back updated control value */
    __set_TSCTRL(LulTsctrlRegValue);
}

/**
 * @brief Read overflow flag (OVF) of the TSC.
 * @return uint8_t 1 if overflow occurred; 0 otherwise.
 */
__STATIC_INLINE uint8_t __RH850_TSC_OverflowGet (void)
{
    uint32_t LulTsctrlRegValue;
    uint8_t  LucReturnValue;

    /* Read current control register */
    LulTsctrlRegValue = __get_TSCTRL();

    /* Extract OVF status bit */
    LucReturnValue = (uint8_t) ((LulTsctrlRegValue & R_TSC_TSCTRL_OVF_Msk) >> R_TSC_TSCTRL_OVF_Pos);

    /* Return the value of OVF bit */
    return LucReturnValue;
}

/**
 * @brief   Get the current enable state of the TSC (Get the current state of TSCTRL.CEN).
 * @details
 *  Returns an enumerated state based on the CEN bit.
 * @return  RH850_TSC_ENABLE_ON/RH850_TSC_ENABLE_OFF  if enabled/disabled
 */
__STATIC_INLINE rh850_tsc_enable_t __RH850_TSC_EnableGet (void)
{
    /* Extract CEN bit, translate into enumeration */
    return (0U != (__get_TSCTRL() & R_TSC_TSCTRL_CEN_Msk)) ? RH850_TSC_ENABLE_ON : RH850_TSC_ENABLE_OFF;
}

/**
 * @brief   Read the upper 32 bits of the TSC (Read the TSCOUNTH register).
 * @details
 *  Returns the high word of the 64-bit counter.
 * @return  Upper 32 bits of the counter.
 */
__STATIC_INLINE uint32_t __RH850_TSC_CounterHighGet (void)
{
    /* Read of the high word */
    return (uint32_t) __get_TSCOUNTH();
}

/**
 * @brief   Read the lower 32 bits of the TSC (Read the TSCOUNTL register).
 * @details
 *  Returns the low word of the 64-bit counter.
 * @return  Lower 32 bits of the counter.
 */
__STATIC_INLINE uint32_t __RH850_TSC_CounterLowGet (void)
{
    /* Read of the low word */
    return (uint32_t) __get_TSCOUNTL();
}

/**
 * @brief   Read the TSC control register (Read the TSCTRL register).
 * @details
 *  Provides raw access to the control/status register.
 * @return  Value of the TSCTRL register.
 */
__STATIC_INLINE uint32_t __RH850_TSC_ControlRead (void)
{
    /* Return current TSCTRL register value */
    return (uint32_t) __get_TSCTRL();
}

/**
 * @brief   Write the upper 32 bits of the TSC (Write to the TSCOUNTH register).
 * @details
 *  Programs the high word of the counter.
 * @param   LulValue Value to write.
 */
__STATIC_INLINE void __RH850_TSC_CounterHighSet (uint32_t LulValue)
{
    /* Program high word of the counter */
    __set_TSCOUNTH(LulValue);
}

/**
 * @brief   Write the lower 32 bits of the TSC (Write to the TSCOUNTL register).
 * @details
 *  Programs the low word of the counter.
 * @param   LulValue Value to write.
 */
__STATIC_INLINE void __RH850_TSC_CounterLowSet (uint32_t LulValue)
{
    /* Program low word of the counter */
    __set_TSCOUNTL(LulValue);
}

/**
 * @brief   Write the TSC control register (write to the TSCTRL register).
 * @details
 *  Writes the raw control value to TSCTRL.
 * @param   LulValue Value to write to TSCTRL.
 */
__STATIC_INLINE void __RH850_TSC_ControlSet (uint32_t LulValue)
{
    /* Write of control/status register */
    __set_TSCTRL(LulValue);
}

/**
 * @brief   Read the full 64-bit TSC value in a stable way.
 * @details
 *  Implements the high-low-high read scheme:
 *   1) Read high (H1),
 *   2) Read low (L),
 *   3) Read high (H2).
 *  If H1 != H2, the value is re-read by the loop to avoid tearing
 *  across rollover. This yields a coherent 64-bit counter value.
 * @return  64-bit TSC value.
 */
__STATIC_INLINE uint64_t __RH850_TSC_CounterFullGet (void)
{
    uint32_t LulHigh1Value;
    uint32_t LulLowValue;
    uint32_t LulHigh2Value;

    /* Perform a coherent 64-bit read */
    do
    {
        LulHigh1Value = __get_TSCOUNTH();     /* first high read  */
        LulLowValue   = __get_TSCOUNTL();     /* low read         */
        LulHigh2Value = __get_TSCOUNTH();     /* second high read */
    } while (LulHigh1Value != LulHigh2Value); /* retry if rollover occurred between reads */

    /* Compose 64-bit value from stable high and low parts */
    return ((uint64_t) LulHigh2Value << 32) | (uint64_t) LulLowValue;
}

/** @} */ /* end of RH850_TSC_API */

#endif                                 /* RH850_G4_TSC_H */

/** @} */ /* end of RH850_TSC */
/** @} */ /* end of RH850_CoreAccess_FunctionInterface */

#endif                                 /* #if defined(__TSC_PRESENT) && (__TSC_PRESENT == 1U) */
