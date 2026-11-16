/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_g4_fxu.h
 * @brief    FXU initialization function for RH850 G4
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#if defined(__FXU_PRESENT) && (__FXU_PRESENT == 1U)

/** @defgroup RH850_CoreAccess_FunctionInterface RH850-Core Access Functions
 * @brief Access to the dedicated core access function.
 * @{
 */

/**
 * @defgroup RH850_FXU RH850 Extended Floating-point Function (FXU)
 * @ingroup RH850_CoreAccess_FunctionInterface
 * @brief RH850 FXU API and types
 * @{
 */

#ifndef RH850_G4_FXU_H
 #define RH850_G4_FXU_H

 #include <stdint.h>

/* #######################################  FXU Types and Enumerations  ############################################# */

/**
 * @defgroup RH850_FXU_Types FXU Types and Enumerations
 * @brief FXU Types and Enumerations
 * @ingroup  RH850_FXU
 * @{
 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**
 * @brief Rounding modes for FXU (FXCFG.RM[9:8]).
 * @details
 * - 0: Round to nearest (ties to even, per device spec)
 * - 1: Round toward zero
 * - 2: Round toward +infinity
 * - 3: Round toward -infinity
 */
typedef enum e_rh850_fxu_round
{
    RH850_FXU_ROUND_NEAR  = 0x000,     /*!< Round to nearest (ties to even, per device spec) */
    RH850_FXU_ROUND_ZERO  = 0x100,     /*!< Round toward zero */
    RH850_FXU_ROUND_PLUS  = 0x200,     /*!< Round toward +infinity */
    RH850_FXU_ROUND_MINUS = 0x300      /*!< Round toward -infinity */
} rh850_fxu_round_t;

/**
 * @brief Flush mode flags for FXSR.
 * @details
 * - **FN (bit 23)**: Flush-to-nearest enable
 * - **FS (bit 17)**: Flush-to-sign enable
 * You can OR both for composite behavior.
 */
typedef enum e_rh850_fxu_flush
{
    RH850_FXU_FLUSH_NEAR = 0x00800000, /*!< Flush-to-nearest enable */
    RH850_FXU_FLUSH_SIGN = 0x00020000, /*!< Flush-to-sign enable */
    RH850_FXU_FLUSH_ALL  = 0x00820000  /*!< All */
} rh850_fxu_flush_t;

/**
 * @brief Exception-enable bits (FXCFG.XE[4:0]).
 * @details
 * - XE[0]: Inexact
 * - XE[1]: Underflow
 * - XE[2]: Overflow
 * - XE[3]: Divide-by-zero
 * - XE[4]: Invalid operation
 */
typedef enum e_rh850_fxu_irq_enable
{
    RH850_FXU_IRQ_ENABLE_OFF       = 0x00, /*!< Off */
    RH850_FXU_IRQ_ENABLE_INEXACT   = 0x01, /*!< Inexact */
    RH850_FXU_IRQ_ENABLE_UNDERFLOW = 0x02, /*!< Underflow */
    RH850_FXU_IRQ_ENABLE_OVERFLOW  = 0x04, /*!< Overflow */
    RH850_FXU_IRQ_ENABLE_ZERO      = 0x08, /*!< Divide-by-zero */
    RH850_FXU_IRQ_ENABLE_INVALID   = 0x10, /*!< Invalid operation */
    RH850_FXU_IRQ_ENABLE_ALL       = 0x1F  /*!< All */
} rh850_fxu_irq_enable_t;

/**
 * @brief FXU status bits (FXST).
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
typedef enum e_rh850_fxu_status
{
    RH850_FXU_STATUS_NONE              = 0x0000, /*!< None */
    RH850_FXU_STATUS_INEXACT           = 0x0001, /*!< Inexact */
    RH850_FXU_STATUS_UNDERFLOW         = 0x0002, /*!< Underflow */
    RH850_FXU_STATUS_OVERFLOW          = 0x0004, /*!< Overflow */
    RH850_FXU_STATUS_ZERO              = 0x0008, /*!< Divide-by-zero */
    RH850_FXU_STATUS_INVALID           = 0x0010, /*!< Invalid operation */
    RH850_FXU_STATUS_FLUSH             = 0x0020, /*!< Flush occurred */
    RH850_FXU_STATUS_IRQ_INEXACT       = 0x0100, /*!< IRQ Inexact */
    RH850_FXU_STATUS_IRQ_UNDERFLOW     = 0x0200, /*!< IRQ Underflow */
    RH850_FXU_STATUS_IRQ_OVERFLOW      = 0x0400, /*!< IRQ Overflow */
    RH850_FXU_STATUS_IRQ_ZERO          = 0x0800, /*!< IRQ Divide-by-zero */
    RH850_FXU_STATUS_IRQ_INVALID       = 0x1000, /*!< IRQ Invalid */
    RH850_FXU_STATUS_IRQ_UNIMPLEMENTED = 0x2000, /*!< IRQ Unimplemented operation */
    RH850_FXU_STATUS_ALL               = 0x3F3F  /*!< All */
} rh850_fxu_status_t;

/**
 * @brief  XC (Cause Bit) selector for extended floating-point operation ways.
 * @details This enumeration defines the XC bit groups in the FXXC register that indicate
 *          the cause of floating-point exceptions for each operation way. Each group
 *          corresponds to a specific SIMD operation lane (way) and contains multiple
 *          bits representing IEEE754-defined exception causes such as Invalid Operation,
 *          Divide-by-Zero, Overflow, Underflow, and Inexact.
 *
 * @note    XC bits are set when exceptions occur during floating-point operations.
 *          Multiple bits may be set if multiple exceptions are detected in the same
 *          instruction. Writing to FXXC does not affect the XC bits in FXS register.
 *
 * @enum rh850_fxu_xc_operation_way_t
 */
typedef enum e_rh850_fxu_xc_operation_way
{
    RH850_FXU_XC_OPERATION_WAY_0 = 0,  /*!< Cause bits for operation way 0 (E0, V0, Z0, O0, U0, I0) */
    RH850_FXU_XC_OPERATION_WAY_1 = 1,  /*!< Cause bits for operation way 1 (E1, V1, Z1, O1, U1, I1) */
    RH850_FXU_XC_OPERATION_WAY_2 = 2,  /*!< Cause bits for operation way 2 (E2, V2, Z2, O2, U2, I2) */
    RH850_FXU_XC_OPERATION_WAY_3 = 3   /*!< Cause bits for operation way 3 (E3, V3, Z3, O3, U3, I3) */
} rh850_fxu_xc_operation_way_t;

/**
 * @brief  XP (Preservation) bit group selector for each operation way.
 * @details This enumeration selects the preservation bit group in the FXXP register
 *          for a specific SIMD operation way:
 *          - XPn: Vn, Zn, On, Un, In
 *
 * @note    XP bits indicate "preservation" behavior for IEEE754 exceptions: when set,
 *          the operation result is preserved even if the corresponding exception occurs.
 */
typedef enum e_rh850_fxu_xp_operation_way
{
    RH850_FXU_XP_OPERATION_WAY_0 = 0,  /*!< Preservation bits for operation way 0 (V0, Z0, O0, U0, I0) */
    RH850_FXU_XP_OPERATION_WAY_1 = 1,  /*!< Preservation bits for operation way 1 (V1, Z1, O1, U1, I1) */
    RH850_FXU_XP_OPERATION_WAY_2 = 2,  /*!< Preservation bits for operation way 2 (V2, Z2, O2, U2, I2) */
    RH850_FXU_XP_OPERATION_WAY_3 = 3   /*!< Preservation bits for operation way 3 (V3, Z3, O3, U3, I3) */
} rh850_fxu_xp_operation_way_t;

/**
 * @brief  XC cause bits (operation way n) in the FXXC register.
 * @details This structure models the six IEEE754-related exception cause flags for
 *          operation way 0 (lane 0). Each field corresponds to a specific exception
 *          cause bit in the XC0 group:
 *          - E : Unimplemented operation (software emulation required)
 *          - V : Invalid operation
 *          - Z : Divide-by-zero
 *          - O : Overflow
 *          - U : Underflow
 *          - I : Inexact
 *
 * @note    Multiple bits can be set simultaneously if multiple exceptions were detected
 *          for the same instruction. This struct is a logical representation; actual bit
 *          positions reside in the FXXC register as defined by the hardware manual.
 */
typedef union u_rh850_fxu_xc
{
    uint8_t XC;
    struct
    {
        uint8_t E : 1;                 /*!< Unimplemented operation cause */
        uint8_t V : 1;                 /*!< Invalid operation cause */
        uint8_t Z : 1;                 /*!< Divide-by-zero cause */
        uint8_t O : 1;                 /*!< Overflow cause */
        uint8_t U : 1;                 /*!< Underflow cause */
        uint8_t I : 1;                 /*!< Inexact cause */
        uint8_t   : 2;                 /*!< Reserved to complete a byte (not used) */
    } XC_b;
} rh850_fxu_xc_t;

/**
 * @brief  XPn preservation bits for operation way n.
 * @details This union represents the preservation status bits in the FXXP register
 *          for operation way n. These bits indicate whether the corresponding IEEE754
 *          exception conditions (Invalid, Divide-by-Zero, Overflow, Underflow, Inexact)
 *          should preserve the result instead of triggering an exception.
 *
 * @note    XP bits are used to control exception behavior for SIMD operations. When set,
 *          the result is preserved even if the exception occurs.
 *
 * Fields:
 * - V : Preservation for Invalid Operation
 * - Z : Preservation for Divide-by-Zero
 * - O : Preservation for Overflow
 * - U : Preservation for Underflow
 * - I : Preservation for Inexact
 */

typedef union u_rh850_fxu_xp
{
    uint8_t XP;
    struct
    {
        uint8_t V : 1;                 /*!< Preservation for Invalid Operation */
        uint8_t Z : 1;                 /*!< Preservation for Divide-by-Zero */
        uint8_t O : 1;                 /*!< Preservation for Overflow */
        uint8_t U : 1;                 /*!< Preservation for Underflow */
        uint8_t I : 1;                 /*!< Preservation for Inexact */
        uint8_t   : 3;                 /*!< Reserved to complete a byte */
    } XP_b;
} rh850_fxu_xp_t;

/** @} */ /* end of RH850_FXU_Types */

/* ###########################################  FXU API Functions  ################################################## */

/**
 * @defgroup RH850_FXU_API FXU API Functions
 * @brief FXU API Functions
 * @ingroup RH850_FXU
 * @{
 */

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/**
 * @brief  Get the flush status of input operands in floating-point operations.
 * @details This function retrieves the status bit that indicates information about the flushing of input operands.
 *
 * @return bool
 *         - true  : At least one operand was flushed.
 *         - false : No operand flushing occurred.
 */
__STATIC_INLINE bool __RH850_FXU_FxsrIfBitGet (void)
{
    return (bool) (((__get_FXSR() & R_FXU_FXSR_IF_Msk)) >> R_FXU_FXSR_IF_Pos);
}

/**
 * @brief Configure FXU flush behavior (FXSR.FN/FS).
 * @details
 * Reads **FXSR (SR6)**, clears FN/FS via mask, ORs provided "LenMode" bits, and writes back.
 *
 * **Bit fields:**
 * - FXSR.FN (23): Flush-to-nearest enable
 * - FXSR.FS (17): Flush-to-sign enable
 *
 * @param[in] LenMode Bitmask of @ref rh850_fxu_flush_t.
 */
__STATIC_INLINE void __RH850_FXU_ModeFlushSet (rh850_fxu_flush_t LenMode)
{
    uint32_t LulFxsrRegValue;

    /* Read current FXSR register and clears FN/FS via mask */
    LulFxsrRegValue  = __get_FXSR();
    LulFxsrRegValue &= ((~R_FXU_FXSR_FN_Msk) & (~R_FXU_FXSR_FS_Msk));

    /* Update the flush mode */
    LulFxsrRegValue |= (uint32_t) (LenMode & (R_FXU_FXSR_FN_Msk | R_FXU_FXSR_FS_Msk));

    /* Update FN/FS bits */
    __set_FXSR(LulFxsrRegValue);
}

/**
 * @brief  Check if the 4-way SIMD arithmetic unit is provided.
 * @details This function reads the NFPU status bit to determine whether the processor
 *          includes a 4-way SIMD arithmetic unit for floating-point operations.
 *
 * @return bool
 *         - true  : SIMD arithmetic unit is available.
 *         - false : SIMD arithmetic unit is not available.
 *
 * @note   The NFPU bit is read-only and reflects hardware capability.
 */
__STATIC_INLINE bool __RH850_FXU_SimdUnitCheck (void)
{
    return (bool) ((__get_FXINFO() & R_FXU_FXINFO_NFPU_Msk) >> R_FXU_FXINFO_NFPU_Pos);
}

/**
 * @brief  Check if 32 128-bit vector registers are provided.
 * @details This function reads the RSIZE status bit to determine whether the processor
 *          supports 32 vector registers of 128 bits each for SIMD operations.
 *
 * @return bool
 *         - true  : 32 128-bit vector registers are available.
 *         - false : Vector register configuration is not supported.
 *
 * @note   The RSIZE bit is read-only and reflects hardware capability.
 */
__STATIC_INLINE bool __RH850_FXU_VectorRegisterCheck (void)
{
    return (bool) ((__get_FXINFO() & R_FXU_FXINFO_RSIZE_Msk) >> R_FXU_FXINFO_RSIZE_Pos);
}

/**
 * @brief Set FXU rounding mode (FXCFG.RM[9:8]).
 * @details
 * Reads **FXCFG (SR10)**, clears RM[9:8] with mask, then inserts "LenMode" and writes back.
 *
 * **Bit fields:**
 * - FXCFG.RM[9:8]: rounding mode control (see @ref rh850_fxu_round_t).
 *
 * @param[in] LenMode Rounding mode value.
 */
__STATIC_INLINE void __RH850_FXU_ModeRoundingSet (rh850_fxu_round_t LenMode)
{
    uint32_t LulFxcfgRegValue;

    /* Read current FXCFG register and clear the FXCFG.RM[9:8] with mask */
    LulFxcfgRegValue  = __get_FXCFG();
    LulFxcfgRegValue &= (~R_FXU_FXCFG_RM_Msk);

    /* Update the rounding mode */
    LulFxcfgRegValue |= (uint32_t) (LenMode & R_FXU_FXCFG_RM_Msk);

    /* Update rounding configuration */
    __set_FXCFG(LulFxcfgRegValue);
}

/**
 * @brief Enable FXU exceptions (FXCFG: XE[4:0]).
 * @details
 * Reads **FXCFG (SR10)**, clears XE mask, ORs desired bits from r6, and writes back.
 * This helper currently sets **all** bits (XE[4:0]) enabled.
 *
 * @param[in] LenIrqEna FXU exceptions enable/disable of @ref rh850_fxu_irq_enable_t.
 */
__STATIC_INLINE void __RH850_FXU_ExceptionEnableSet (rh850_fxu_irq_enable_t LenIrqEna)
{
    uint32_t LulFxcfgRegValue;

    /* Read current FXCFG register and clear the FXCFG: XE[4:0] Exception enable with mask */
    LulFxcfgRegValue  = __get_FXCFG();
    LulFxcfgRegValue &= (~R_FXU_FXCFG_XE_Msk);

    /* Update the exception enable bits */
    LulFxcfgRegValue |= (uint32_t) (LenIrqEna & R_FXU_FXCFG_XE_Msk);

    /* Update XE bits */
    __set_FXCFG(LulFxcfgRegValue);
}

/**
 * @brief  Get the cause bits for a specific operation way from the FXXC register.
 * @details This function reads the FXXC register and returns the cause bits (XC) associated
 *          with the specified operation way. Cause bits indicate which floating-point
 *          exceptions occurred during operations for that way (e.g., Invalid Operation,
 *          Divide-by-Zero, Overflow, Underflow, Inexact).
 *
 * @param  LenOperationWay  Enumeration value of type rh850_fxu_xc_operation_way_t specifying the operation way.
 *
 * @return rh850_fxu_xc_t
 *         Bitmask representing the cause bits for the selected operation way.
 */
__STATIC_INLINE rh850_fxu_xc_t __RH850_FXU_CauseBitsGet (rh850_fxu_xc_operation_way_t LenOperationWay)
{
    rh850_fxu_xc_t LstReturnValue;
    uint32_t       LulShift;

    /* Each operation way occupies 8 bits within the FXXC register */
    LulShift = ((uint32_t) LenOperationWay * 8U);

    /* Get the cause bits for a specific operation way */
    LstReturnValue.XC = (uint8_t) ((__get_FXXC() & (R_FXU_FXXC_XC0_Msk << LulShift)) >> LulShift);

    return LstReturnValue;
}

/**
 * @brief  Get the preservation (XP) bitfield for a specific operation way.
 * @details Reads the FXXP register and returns the XP bit group associated with
 *        @p LenOperationWay (XP0..XP3). The returned value is a bitmask composed of
 *          rh850_fxu_xp_t flags (V, Z, O, U, I).
 *
 * @param  LenOperationWay   XP group selector.
 *
 * @return rh850_fxu_xp_t
 *         Bitmask of preservation flags for the selected way.
 *
 * @note   Writing FXXP does not affect the XP bits of the FXSR register. XP bits indicate
 *         whether results are preserved under IEEE754 exceptions in the selected lane.
 */
__STATIC_INLINE rh850_fxu_xp_t __RH850_FXU_PreservationBitsGet (rh850_fxu_xp_operation_way_t LenOperationWay)
{
    rh850_fxu_xp_t LstReturnValue;
    uint32_t       LulShift;

    /* Each operation way occupies 8 bits within the FXXP register */
    LulShift = ((uint32_t) LenOperationWay * 8U);

    /* Get the preservation (XP) bitfield for a specific operation way */
    LstReturnValue.XP = (uint8_t) ((__get_FXXP() & (R_FXU_FXXP_XP0_Msk << LulShift)) >> LulShift);

    return LstReturnValue;
}

/**
 * @brief Read FXU status (FXST).
 * @details
 * Reads **FXST (SR8)**.
 *
 * @return Bitmask of @ref rh850_fxu_status_t.
 */
__STATIC_INLINE rh850_fxu_status_t __RH850_FXU_StatusGet (void)
{
    return (rh850_fxu_status_t) __get_FXST();
}

/**
 * @brief Clear selected FXU status bits (FXST).
 * @details
 * Reads **FXST (SR8)**, clears targeted bits using "LulFxuStatus" mask, then writes back.
 *
 * @param[in] LulFxuStatus Bitmask of status to clear (see @ref rh850_fxu_status_t).
 */
__STATIC_INLINE void __RH850_FXU_StatusClear (rh850_fxu_status_t LulFxuStatus)
{
    uint32_t LulFxstRegValue;

    /* Read the FXST value */
    LulFxstRegValue = __get_FXST();

    /* Clear requested bits (only within the writable status fields) */
    LulFxstRegValue &= ~((uint32_t) LulFxuStatus & (R_FXU_FXST_XC_Msk | R_FXU_FXST_IF_Msk | R_FXU_FXST_XP_Msk));

    /* Write back */
    __set_FXST(LulFxstRegValue);
}

/**
 * @brief Enable the FXU (set PSW.CU1).
 * @details
 * Reads **PSW (SR5)**, enable the FXU by setting bit PSW.CU1 to 1.
 */
__STATIC_INLINE void __RH850_FXU_Enable (void)
{
    uint32_t LulPswRegValue;

    /* Read the value of PSW and set the PSW.CU1 to 1 */
    LulPswRegValue  = __get_PSW();
    LulPswRegValue |= (R_SYS_PSW_CU1_Msk);

    /* Write back to the PSW */
    __set_PSW(LulPswRegValue);
}

/**
 * @brief Disable the FXU (clear PSW.CU1).
 * @details
 * Reads **PSW (SR5)**, clears CU1 by AND with inverted mask, and writes back to **PSW (SR5)**.
 */
__STATIC_INLINE void __RH850_FXU_Disable (void)
{
    uint32_t LulPswRegValue;

    /* Read the value of PSW and clear the PSW.CU1 to 0 */
    LulPswRegValue  = __get_PSW();
    LulPswRegValue &= (~R_SYS_PSW_CU1_Msk);

    /* Write back to the PSW */
    __set_PSW(LulPswRegValue);
}

/** @} */ /* end of RH850_FXU_API */

#endif                                 /* RH850_G4_FXU_H */

/** @} */ /* end of RH850_FXU */
/** @} */ /* end of RH850_CoreAccess_FunctionInterface */

#endif                                 /* #if defined(__FXU_PRESENT) && (__FXU_PRESENT == 1U) */
