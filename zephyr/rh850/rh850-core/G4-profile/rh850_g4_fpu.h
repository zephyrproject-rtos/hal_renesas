/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_g4_fpu.h
 * @brief    FPU initialization function for RH850 G4
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#if defined(__FPU_PRESENT) && (__FPU_PRESENT == 1U)

/** @defgroup RH850_CoreAccess_FunctionInterface RH850-Core Access Functions
 * @brief Access to the dedicated core access function.
 * @{
 */

/**
 * @defgroup RH850_FPU RH850 Floating-point Function (FPU)
 * @ingroup RH850_CoreAccess_FunctionInterface
 * @brief RH850 FPU API and types
 * @{
 */

#ifndef RH850_G4_FPU_H
 #define RH850_G4_FPU_H

 #include <stdint.h>

/* #######################################  FPU Types and Enumerations  ############################################# */

/**
 * @defgroup RH850_FPU_Types FPU Types and Enumerations
 * @brief FPU Types and Enumerations
 * @ingroup  RH850_FPU
 * @{
 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**
 * @brief Rounding modes for FPU (FPCFG.RM[9:8]).
 * @details
 * - 0: Round to nearest (ties to even, per device spec)
 * - 1: Round toward zero
 * - 2: Round toward +infinity
 * - 3: Round toward -infinity
 */
typedef enum e_rh850_fpu_round
{
    RH850_FPU_ROUND_NEAR  = 0x000,     /*!< Round to nearest (ties to even, per device spec) */
    RH850_FPU_ROUND_ZERO  = 0x100,     /*!< Round toward zero */
    RH850_FPU_ROUND_PLUS  = 0x200,     /*!< Round toward +infinity */
    RH850_FPU_ROUND_MINUS = 0x300      /*!< Round toward -infinity */
} rh850_fpu_round_t;

/**
 * @brief Flush mode flags for FPSR.
 * @details
 * - **FN (bit 23)**: Flush-to-nearest enable
 * - **FS (bit 17)**: Flush-to-sign enable
 * You can OR both for composite behavior.
 */
typedef enum e_rh850_fpu_flush
{
    RH850_FPU_FLUSH_NEAR = 0x00800000, /*!< Flush-to-nearest enable */
    RH850_FPU_FLUSH_SIGN = 0x00020000, /*!< Flush-to-sign enable */
    RH850_FPU_FLUSH_ALL  = 0x00820000  /*!< All */
} rh850_fpu_flush_t;

/**
 * @brief Exception-enable bits (FPCFG.XE[4:0]).
 * @details
 * - XE[0]: Inexact
 * - XE[1]: Underflow
 * - XE[2]: Overflow
 * - XE[3]: Divide-by-zero
 * - XE[4]: Invalid operation
 */
typedef enum e_rh850_fpu_irq_enable
{
    RH850_FPU_IRQ_ENABLE_OFF       = 0x00, /*!< None */
    RH850_FPU_IRQ_ENABLE_INEXACT   = 0x01, /*!< Inexact */
    RH850_FPU_IRQ_ENABLE_UNDERFLOW = 0x02, /*!< Underflow */
    RH850_FPU_IRQ_ENABLE_OVERFLOW  = 0x04, /*!< Overflow */
    RH850_FPU_IRQ_ENABLE_ZERO      = 0x08, /*!< Divide-by-zero */
    RH850_FPU_IRQ_ENABLE_INVALID   = 0x10, /*!< Invalid operation */
    RH850_FPU_IRQ_ENABLE_ALL       = 0x1F  /*!< All */
} rh850_fpu_irq_enable_t;

/**
 * @brief FPU status bits (FPST).
 * @details
 * **Low status (sticky) flags:**
 * - 0x0001: Inexact
 * - 0x0002: Underflow
 * - 0x0004: Overflow
 * - 0x0008: Divide-by-zero
 * - 0x0010: Invalid operation
 * - 0x0020: Flush occurred
 *
 * **IRQ request flags:**
 * - 0x0100: IRQ Inexact
 * - 0x0200: IRQ Underflow
 * - 0x0400: IRQ Overflow
 * - 0x0800: IRQ Divide-by-zero
 * - 0x1000: IRQ Invalid
 * - 0x2000: IRQ Unimplemented operation
 */
typedef enum e_rh850_fpu_status
{
    RH850_FPU_STATUS_NONE              = 0x0000, /*!< None */
    RH850_FPU_STATUS_INEXACT           = 0x0001, /*!< Inexact */
    RH850_FPU_STATUS_UNDERFLOW         = 0x0002, /*!< Underflow */
    RH850_FPU_STATUS_OVERFLOW          = 0x0004, /*!< Overflow */
    RH850_FPU_STATUS_ZERO              = 0x0008, /*!< Divide-by-zero */
    RH850_FPU_STATUS_INVALID           = 0x0010, /*!< Invalid operation */
    RH850_FPU_STATUS_FLUSH             = 0x0020, /*!< Flush occurred */
    RH850_FPU_STATUS_IRQ_INEXACT       = 0x0100, /*!< IRQ Inexact */
    RH850_FPU_STATUS_IRQ_UNDERFLOW     = 0x0200, /*!< IRQ Underflow */
    RH850_FPU_STATUS_IRQ_OVERFLOW      = 0x0400, /*!< IRQ Overflow */
    RH850_FPU_STATUS_IRQ_ZERO          = 0x0800, /*!< IRQ Divide-by-zero */
    RH850_FPU_STATUS_IRQ_INVALID       = 0x1000, /*!< IRQ Invalid */
    RH850_FPU_STATUS_IRQ_UNIMPLEMENTED = 0x2000, /*!< IRQ Unimplemented operation */
    RH850_FPU_STATUS_ALL               = 0x3F3F  /*!< All */
} rh850_fpu_status_t;

/**
 * @brief  Floating-point Condition Code (CC) bit selector.
 * @details This enumeration defines the CC bit positions (CC0..CC7) used in the FPSR register
 *          for floating-point comparison results. Each CC bit corresponds to one of the eight
 *          condition code fields located in bits [31:24] of FPSR.
 *
 * @note    CC bits store the result of floating-point comparison instructions:
 *          - 0: Comparison result is FALSE
 *          - 1: Comparison result is TRUE
 *
 * @enum rh850_fpu_fcbit_cc_t
 */

typedef enum e_rh850_fpu_fcbit_cc
{
    RH850_FPU_FCBIT_CC_0 = 0,          /*!< CC0: bit 24 in FPSR */
    RH850_FPU_FCBIT_CC_1 = 1,          /*!< CC1: bit 25 */
    RH850_FPU_FCBIT_CC_2 = 2,          /*!< CC2: bit 26 */
    RH850_FPU_FCBIT_CC_3 = 3,          /*!< CC3: bit 27 */
    RH850_FPU_FCBIT_CC_4 = 4,          /*!< CC4: bit 28 */
    RH850_FPU_FCBIT_CC_5 = 5,          /*!< CC5: bit 29 */
    RH850_FPU_FCBIT_CC_6 = 6,          /*!< CC6: bit 30 */
    RH850_FPU_FCBIT_CC_7 = 7           /*!< CC7: bit 31 */
} rh850_fpu_fcbit_cc_t;

/**
 * @brief FPU enable state.
 */
typedef enum e_rh850_fpu_status_enable
{
    RH850_FPU_STATUS_ENABLE_OFF = 0x0U, /*!< FPU is disabled */
    RH850_FPU_STATUS_ENABLE_ON  = 0x1U  /*!< FPU is enabled */
} rh850_fpu_status_enable_t;

/** @} */ /* end of RH850_FPU_Types */

/* ###########################################  FPU API Functions  ################################################## */

/**
 * @defgroup RH850_FPU_API FPU API Functions
 * @brief FPU API Functions
 * @ingroup RH850_FPU
 * @{
 */

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/**
 * @brief  Get the floating-point comparison result from FPSR.
 * @details This function reads the FPSR register and checks the condition code (CC) bit
 *          specified by @p LenFcbit. If the CC bit is set, the comparison result is TRUE;
 *          otherwise, it is FALSE.
 *
 * @param  LenFcbit  CC bit position (0-7) corresponding to the floating-point comparison result.
 *
 * @return bool
 *         - true  : Comparison condition is satisfied.
 *         - false : Comparison condition is not satisfied.
 *
 * @note   The CC bits (CC7..CC0) in FPSR are only modified by floating-point comparison
 *         instructions and LDSR instructions.
 */
__STATIC_INLINE bool __RH850_FPU_FpsrCcBitGet (rh850_fpu_fcbit_cc_t LenFcbit)
{
    bool     LblReturnValue;
    uint32_t LulCcBitMask;

    /* Initialize for LblReturnValue */
    LblReturnValue = false;

    /* Build the single-bit mask for the requested CCn bit (FPSR bit = CC_Pos + n) */
    LulCcBitMask = (1UL << (R_FPU_FPSR_CC_Pos + (uint32_t) LenFcbit));

    /* Get the comparison result at the specific CC bit */
    if (0U != (__get_FPSR() & LulCcBitMask))
    {
        LblReturnValue = true;
    }

    /* Return value */
    return LblReturnValue;
}

/**
 * @brief  Set the floating-point comparison result (CCn) in FPSR.
 * @details Writes the specified comparison result value to the condition code (CC) bit
 *          selected by @p LenFcbit within the FPSR register. The CC bits (CC7..CC0)
 *          store the outcome of floating-point comparison instructions (0 = false,
 *          1 = true) and can also be updated via software by writing FPSR.
 *
 * @param  LenFcbit  CC bit selector (0-7) that identifies which CCn bit to update.
 *                   The value corresponds to CC0..CC7 (mapped to FPSR bits 24..31).
 * @param  LblValue  Comparison result to set:
 *                   - false : condition not satisfied (0)
 *                   - true  : condition satisfied (1)
 *
 * @note   CC bits in FPSR are only modified by floating-point comparison instructions
 *         and by software writes (e.g., LDSR / __set_FPSR()). Writing CC bits via
 *         software does not perform a comparison nor raise an exception.
 */
__STATIC_INLINE void __RH850_FPU_FpsrCcBitSet (rh850_fpu_fcbit_cc_t LenFcbit, bool LblValue)
{
    uint32_t LulFpsrRegValue;
    uint32_t LulCcBitMask;

    /* Build the single-bit mask for the requested CCn bit (FPSR bit = CC_Pos + n) */
    LulCcBitMask = (1UL << (R_FPU_FPSR_CC_Pos + (uint32_t) LenFcbit));

    /* Get the FPSR value and clear the target CCn bit only (keep the other bits) */
    LulFpsrRegValue  = __get_FPSR();
    LulFpsrRegValue &= (~LulCcBitMask);

    /* Set the new value for the CCn bit */
    if (false != LblValue)
    {
        LulFpsrRegValue |= LulCcBitMask;
    }

    /* Write back */
    __set_FPSR(LulFpsrRegValue);
}

/**
 * @brief  Get the flush status of input operands in floating-point operations.
 * @details This function retrieves the status bit that indicates information about the flushing of input operands.
 *
 * @return bool
 *         - true  : At least one operand was flushed.
 *         - false : No operand flushing occurred.
 */
__STATIC_INLINE bool __RH850_FPU_FpsrIfBitGet (void)
{
    return (bool) (((__get_FPSR() & R_FPU_FPSR_IF_Msk)) >> R_FPU_FPSR_IF_Pos);
}

/**
 * @brief Configure FPU flush behavior (FPSR.FN/FS).
 * @details
 * Reads **FPSR (SR6)**, clears FN/FS via mask, ORs provided "LenMode" bits, and writes back.
 *
 * **Bit fields:**
 * - FPSR.FN (23): Flush-to-nearest enable
 * - FPSR.FS (17): Flush-to-sign enable
 *
 * @param[in] LenMode Bitmask of @ref rh850_fpu_flush_t.
 */
__STATIC_INLINE void __RH850_FPU_ModeFlushSet (rh850_fpu_flush_t LenMode)
{
    uint32_t LulFpsrRegValue;

    /* Read current FPSR register and clears FN/FS via mask */
    LulFpsrRegValue  = __get_FPSR();
    LulFpsrRegValue &= ((~R_FPU_FPSR_FN_Msk) & (~R_FPU_FPSR_FS_Msk));

    /* Update the flush mode */
    LulFpsrRegValue |= (uint32_t) (LenMode & (R_FPU_FPSR_FN_Msk | R_FPU_FPSR_FS_Msk));

    /* Update FN/FS bits */
    __set_FPSR(LulFpsrRegValue);
}

/**
 * @brief Get the current configuration of FPU flush behavior (FPSR.FN/FS).
 * @details
 * Reads **FPSR (SR6)** with FN/FS bits
 *
 * @return rh850_fpu_flush_t
 * - FPSR.FN (23): Flush-to-nearest enable
 * - FPSR.FS (17): Flush-to-sign enable
 */
__STATIC_INLINE rh850_fpu_flush_t __RH850_FPU_ModeFlushGet (void)
{
    return (rh850_fpu_flush_t) (__get_FPSR() & (R_FPU_FPSR_FN_Msk | R_FPU_FPSR_FS_Msk));
}

/**
 * @brief Set FPU rounding mode (FPCFG.RM[9:8]).
 * @details
 * Reads **FPCFG (SR10)**, clears RM[9:8] with mask, then inserts "LenMode" and writes back.
 *
 * **Bit fields:**
 * - FPCFG.RM[9:8]: rounding mode control (see @ref rh850_fpu_round_t).
 *
 * @param[in] LenMode Rounding mode value.
 */
__STATIC_INLINE void __RH850_FPU_ModeRoundingSet (rh850_fpu_round_t LenMode)
{
    uint32_t LulFpcfgRegValue;

    /* Read current FPCFG register and clear the FPCFG.RM[9:8] with mask */
    LulFpcfgRegValue  = __get_FPCFG();
    LulFpcfgRegValue &= (~R_FPU_FPCFG_RM_Msk);

    /* Update the rounding mode */
    LulFpcfgRegValue |= (uint32_t) (LenMode & R_FPU_FPCFG_RM_Msk);

    /* Update rounding configuration */
    __set_FPCFG(LulFpcfgRegValue);
}

/**
 * @brief Get FPU rounding mode (FPCFG.RM[9:8]).
 * @details
 * Reads **FPCFG (SR10)** for RM[9:8] bits, then return the Rounding Mode.
 *
 * @return rh850_fpu_round_t
 * - FPCFG.RM[9:8]: rounding mode control (see @ref rh850_fpu_round_t).
 */
__STATIC_INLINE rh850_fpu_round_t __RH850_FPU_ModeRoundingGet (void)
{
    return (rh850_fpu_round_t) (__get_FPCFG() & R_FPU_FPCFG_RM_Msk);
}

/**
 * @brief Enable FPU exceptions (FPCFG: XE[4:0]).
 * @details
 * Reads **FPCFG (SR10)**, clears XE mask, ORs desired bits from r6, and writes back.
 * This helper currently sets **all** bits (XE[4:0]) enabled.
 *
 * @param[in] LenIrqEna FPU exceptions enable/disable of @ref rh850_fpu_irq_enable_t.
 */
__STATIC_INLINE void __RH850_FPU_ExceptionEnableSet (rh850_fpu_irq_enable_t LenIrqEna)
{
    uint32_t LulFpcfgRegValue;

    /* Read current FPCFG register and clear the FPCFG: XE[4:0] Exception enable with mask */
    LulFpcfgRegValue  = __get_FPCFG();
    LulFpcfgRegValue &= (~R_FPU_FPCFG_XE_Msk);

    /* Update the rounding mode */
    LulFpcfgRegValue |= (uint32_t) (LenIrqEna & R_FPU_FPCFG_XE_Msk);

    /* Update XE bits */
    __set_FPCFG(LulFpcfgRegValue);
}

/**
 * @brief Get the enable FPU exceptions (FPCFG: XE[4:0]).
 * @details
 * Reads **FPCFG (SR10)** for bits (XE[4:0]).
 *
 * @return rh850_fpu_irq_enable_t
 * - FPCFG.XE[4:0]: FPU exceptions (see @ref rh850_fpu_irq_enable_t).
 */
__STATIC_INLINE rh850_fpu_irq_enable_t __RH850_FPU_ExceptionEnableGet (void)
{
    return (rh850_fpu_irq_enable_t) (__get_FPCFG() & R_FPU_FPCFG_XE_Msk);
}

/**
 * @brief  Get the Program Counter (PC) of the floating-point instruction that caused an exception.
 * @details This function returns the value of the FPEPC register, which holds the PC of the
 *          floating-point instruction that triggered an enabled floating-point operation exception.
 *          The value is read using the intrinsic __get_FPEPC().
 *
 * @return uint32_t Current value of the FPEPC register (Program Counter of the faulting instruction).
 */
__STATIC_INLINE uint32_t __RH850_FPU_FpepcGet (void)
{
    return (uint32_t) (__get_FPEPC());
}

/**
 * @brief Enable the FPU (set PSW.CU0).
 * @details
 * Reads **PSW (SR5)** to r10, sets CU0 bit via logical OR, then writes r10 back to **PSW (SR5)** using "ldsr".
 * After enabling, floating-point instructions are permitted.
 */
__STATIC_INLINE void __RH850_FPU_Enable (void)
{
    uint32_t LulPswRegValue;

    /* Read the PSW and set the PSW.CU0 to 1 to enable for FPU */
    LulPswRegValue  = __get_PSW();
    LulPswRegValue |= (R_SYS_PSW_CU0_Msk);

    /* Write back to PSW register */
    __set_PSW(LulPswRegValue);
}

/**
 * @brief Disable the FPU (clear PSW.CU0)
 * @details
 * Reads **PSW (SR5)**, clears CU0 by AND with inverted mask, and writes back to **PSW (SR5)**.
 */
__STATIC_INLINE void __RH850_FPU_Disable (void)
{
    uint32_t LulPswRegValue;

    /* Read the PSW and clear the PSW.CU0 to 0 to disable for FPU */
    LulPswRegValue  = __get_PSW();
    LulPswRegValue &= (~R_SYS_PSW_CU0_Msk);

    /* Write back to PSW register */
    __set_PSW(LulPswRegValue);
}

/**
 * @brief   Get the current enable state of the FPU (Get the current state of PSW.CU0).
 * @details
 *  Returns an enumerated state based on the CU0 bit.
 * @return  RH850_FPU_STATUS_ENABLE_ON/RH850_FPU_STATUS_ENABLE_OFF  if enabled/disabled
 */
__STATIC_INLINE rh850_fpu_status_enable_t __RH850_FPU_EnableGet (void)
{
    /* Extract CU0 bit, translate into enumeration */
    return (0U != (__get_PSW() & R_SYS_PSW_CU0_Msk)) ? RH850_FPU_STATUS_ENABLE_ON : RH850_FPU_STATUS_ENABLE_OFF;
}

/**
 * @brief Read FPU status (FPST).
 * @details
 * Reads **FPST (SR8)**.
 *
 * @return Bitmask of @ref rh850_fpu_status_t.
 */
__STATIC_INLINE rh850_fpu_status_t __RH850_FPU_StatusGet (void)
{
    return (rh850_fpu_status_t) __get_FPST();
}

/**
 * @brief Clear selected FPU status bits (FPST).
 * @details
 * Reads **FPST (SR8)**, clears targeted bits using "LulFpuStatus" mask, then writes back.
 *
 * @param[in] LulFpuStatus Bitmask of status to clear (see @ref rh850_fpu_status_t).
 */
__STATIC_INLINE void __RH850_FPU_StatusClear (rh850_fpu_status_t LulFpuStatus)
{
    uint32_t LulFpstRegValue;

    /* Read the FPST value */
    LulFpstRegValue = __get_FPST();

    /* Clear requested bits */
    LulFpstRegValue &= ~((uint32_t) LulFpuStatus & (R_FPU_FPST_XC_Msk | R_FPU_FPST_IF_Msk | R_FPU_FPST_XP_Msk));

    /* Write back */
    __set_FPST(LulFpstRegValue);
}

/** @} */ /* end of RH850_FPU_API */

#endif                                 /* RH850_G4_FPU_H */

/** @} */ /* end of RH850_FPU */
/** @} */ /* end of RH850_CoreAccess_FunctionInterface */

#endif                                 /* #if defined(__FPU_PRESENT) && (__FPU_PRESENT == 1U) */
