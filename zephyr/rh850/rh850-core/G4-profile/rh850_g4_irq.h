/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_g4_irq.h
 * @brief    Interrupt Function for RH850 G4
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#if defined(__IRQ_PRESENT) && (__IRQ_PRESENT == 1U)

/** @defgroup RH850_CoreAccess_FunctionInterface RH850-Core Access Functions
 * @brief Access to the dedicated core access function.
 * @{
 */

/**
 * @defgroup RH850_IRQ RH850 Interrupt Function (IRQ)
 * @ingroup RH850_CoreAccess_FunctionInterface
 * @brief RH850 IRQ API and types
 * @{
 */

#ifndef RH850_G4_IRQ_H
 #define RH850_G4_IRQ_H

 #include <stdint.h>

/* #######################################  IRQ Types and Enumerations  ############################################# */

/**
 * @defgroup RH850_IRQ_Types IRQ Types and Enumerations
 * @ingroup  RH850_IRQ
 * @{
 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Determine whether IRQ belongs to INTC1 (0..31) */
 #define RH850_IRQ_IS_INTC1(_irqn)    ((int32_t) (_irqn) <= 31)

/* EEIC address for IRQn:
 * - INTC1: base + PE offset + 2*IRQn
 * - INTC2: base + 2*IRQn
 */
 #define RH850_EEIC_ADDR(_peid, _irqn)                                       \
    ((RH850_IRQ_IS_INTC1(_irqn))                                             \
     ? ((uintptr_t) (RH850_INTC1_BASE + RH850_INTC1_EEIC_OFFSET) +           \
        (uintptr_t) ((uint32_t) (_peid) * (uint32_t) (RH850_INTC1_OFFSET)) + \
        (uintptr_t) ((uint32_t) (_irqn) * 4U))                               \
     : ((uintptr_t) (RH850_INTC2_BASE + RH850_INTC2_EEIC_OFFSET) +           \
        (uintptr_t) ((uint32_t) (_irqn) * 4U)))

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**
 * @enum rh850_isr_priority_t
 * @brief Interrupt priority levels for EI interrupts on RH850.
 *
 * This enumeration defines the priority levels corresponding to the ISPR register bits.
 * @note These values map directly to ISPR bits [15:0].
 * Lower numeric values indicate higher priority. Priority 0 is the highest, and Priority 15 is the lowest.
 */
typedef enum e_rh850_isr_priority
{
    RH850_ISR_PRIORITY_0  = 0,         /*!< Priority 0 (highest) */
    RH850_ISR_PRIORITY_1  = 1,         /*!< Priority 1 */
    RH850_ISR_PRIORITY_2  = 2,         /*!< Priority 2 */
    RH850_ISR_PRIORITY_3  = 3,         /*!< Priority 3 */
    RH850_ISR_PRIORITY_4  = 4,         /*!< Priority 4 */
    RH850_ISR_PRIORITY_5  = 5,         /*!< Priority 5 */
    RH850_ISR_PRIORITY_6  = 6,         /*!< Priority 6 */
    RH850_ISR_PRIORITY_7  = 7,         /*!< Priority 7 */
    RH850_ISR_PRIORITY_8  = 8,         /*!< Priority 8 */
    RH850_ISR_PRIORITY_9  = 9,         /*!< Priority 9 */
    RH850_ISR_PRIORITY_10 = 10,        /*!< Priority 10 */
    RH850_ISR_PRIORITY_11 = 11,        /*!< Priority 11 */
    RH850_ISR_PRIORITY_12 = 12,        /*!< Priority 12 */
    RH850_ISR_PRIORITY_13 = 13,        /*!< Priority 13 */
    RH850_ISR_PRIORITY_14 = 14,        /*!< Priority 14 */
    RH850_ISR_PRIORITY_15 = 15         /*!< Priority 15 (lowest) */
} rh850_isr_priority_t;

/**
 * @enum rh850_imsr_bit_t
 * @brief IMSR bit masks for RH850 mask status.
 *
 * This enumeration defines symbolic names for the IMSR bit masks so code can
 * reference mask sources in a readable way.
 *
 * @note The values are single-bit masks of the IMSR register.
 */
typedef enum e_rh850_imsr_bit
{
    RH850_IMSR_BIT_EEIM = 0x01,        /*!< EIINT masked by ISPR.ISP/PSW.EIMASK exists */
    RH850_IMSR_BIT_EPLM = 0x02,        /*!< EINT masked by PLMR.PLM exists */
    RH850_IMSR_BIT_EID  = 0x04,        /*!< EINT masked by PSW.ID exists */
    RH850_IMSR_BIT_ENP  = 0x08,        /*!< EINT masked by PSW.NP exists */
    RH850_IMSR_BIT_FNP  = 0x10         /*!< FEINT masked by PSW.NP exists */
} rh850_imsr_bit_t;

/**
 * @enum rh850_intcfg_extended_priority_level_t
 * @brief Interrupt Priority Level extension enable (EPL).
 *
 * 0: Priority level extension function is disabled
 * 1: Priority level extension function is enabled
 */
typedef enum e_rh850_intcfg_extended_priority_level
{
    RH850_INTCFG_EXTENDED_PRIORITY_LEVEL_DISABLED = 0, /*!< Function disabled */
    RH850_INTCFG_EXTENDED_PRIORITY_LEVEL_ENABLED  = 1  /*!< Function enabled  */
} rh850_intcfg_extended_priority_level_t;

/**
 * @enum rh850_intcfg_update_ispc_t
 * @brief ISPR write control (ISPC).
 *
 * 0: ISPR is auto-updated. LDSR updates are ignored.
 * 1: ISPR is not auto-updated. LDSR updates are performed (software priority control).
 *
 * @note In normal cases, ISPC should be cleared to 0. Set 1 only when software-based
 *       priority control is required.
 */
typedef enum e_rh850_intcfg_update_ispc
{
    RH850_INTCFG_UPDATE_ISPC_AUTO    = 0, /*!< Auto-update ISPR; ignore LDSR writes */
    RH850_INTCFG_UPDATE_ISPC_PROGRAM = 1  /*!< Program-driven ISPR updates via LDSR   */
} rh850_intcfg_update_ispc_t;

/**
 * @enum rh850_imsr_eiint_eplm_mask_t
 * @brief Represents the state of EIINTn priority masking by PLMR register.
 *
 * This enumeration defines whether an EIINTn interrupt whose acceptance is masked
 * by PLMR.PLM exists. It maps to IMSR bit EPLM:
 *   - 0: EIINT masked by PLMR.PLM does not exist
 *   - 1: EIINT masked by PLMR.PLM exists
 *
 * @note For details, see Section, Interrupt Exception Priority and Priority Masking.
 */
typedef enum e_rh850_imsr_eiint_eplm_mask
{
    RH850_IMSR_EIINT_EPLM_MASK_DOES_NOT_EXIST = 0, /*!< EIINT masked by PLMR.PLM does not exist */
    RH850_IMSR_EIINT_EPLM_MASK_EXISTS         = 1  /*!< EIINT masked by PLMR.PLM exists */
} rh850_imsr_eiint_eplm_mask_t;

/**
 * @enum rh850_imsr_mask_t
 * @brief Represents the state of an interrupt mask in IMSR.
 *
 * This enumeration defines whether a specific IMSR mask condition exists.
 * Each IMSR bit uses these states:
 *   - 0: Mask does not exist
 *   - 1: Mask exists
 */
typedef enum e_rh850_imsr_mask
{
    RH850_IMSR_MASK_NOT_EXIST = 0,     /*!< Mask does not exist (bit = 0U) */
    RH850_IMSR_MASK_EXISTS    = 1      /*!< Mask exists (bit = 1) */
} rh850_imsr_mask_t;

/**
 * @enum rh850_plmr_priority_mask_level_t
 * @brief Priority mask level for EIINTn on RH850 (PLMR.PLM = 0..63).
 *
 * Masking rule:
 *  - PLM = 0: All priorities are not acceptable (priority 0..63).
 *  - PLM = N: Mask interrupts with priority <= N.
 *  - Priority 63: Always masked (priority 0..63).
 *
 * @note Enum values map directly to PLMR.PLM (0..63).
 */
typedef enum e_rh850_plmr_priority_mask_level
{
    RH850_PLMR_PRIORITY_MASK_LEVEL_0  = 0,  /*!< All priorities are not acceptable */
    RH850_PLMR_PRIORITY_MASK_LEVEL_1  = 1,  /*!< Acceptable of priority 0 only */
    RH850_PLMR_PRIORITY_MASK_LEVEL_2  = 2,  /*!< Acceptable priority is 0 to 1 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_3  = 3,  /*!< Acceptable priority is 0 to 2 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_4  = 4,  /*!< Acceptable priority is 0 to 3 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_5  = 5,  /*!< Acceptable priority is 0 to 4 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_6  = 6,  /*!< Acceptable priority is 0 to 5 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_7  = 7,  /*!< Acceptable priority is 0 to 6 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_8  = 8,  /*!< Acceptable priority is 0 to 7 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_9  = 9,  /*!< Acceptable priority is 0 to 8 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_10 = 10, /*!< Acceptable priority is 0 to 9 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_11 = 11, /*!< Acceptable priority is 0 to 10 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_12 = 12, /*!< Acceptable priority is 0 to 11 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_13 = 13, /*!< Acceptable priority is 0 to 12 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_14 = 14, /*!< Acceptable priority is 0 to 13  */
    RH850_PLMR_PRIORITY_MASK_LEVEL_15 = 15, /*!< Acceptable priority is 0 to 14 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_16 = 16, /*!< Acceptable priority is 0 to 15 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_17 = 17, /*!< Acceptable priority is 0 to 16 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_18 = 18, /*!< Acceptable priority is 0 to 17 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_19 = 19, /*!< Acceptable priority is 0 to 18 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_20 = 20, /*!< Acceptable priority is 0 to 19 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_21 = 21, /*!< Acceptable priority is 0 to 20 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_22 = 22, /*!< Acceptable priority is 0 to 21 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_23 = 23, /*!< Acceptable priority is 0 to 22 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_24 = 24, /*!< Acceptable priority is 0 to 23 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_25 = 25, /*!< Acceptable priority is 0 to 24 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_26 = 26, /*!< Acceptable priority is 0 to 25 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_27 = 27, /*!< Acceptable priority is 0 to 26 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_28 = 28, /*!< Acceptable priority is 0 to 27 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_29 = 29, /*!< Acceptable priority is 0 to 28 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_30 = 30, /*!< Acceptable priority is 0 to 29 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_31 = 31, /*!< Acceptable priority is 0 to 30 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_32 = 32, /*!< Acceptable priority is 0 to 31 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_33 = 33, /*!< Acceptable priority is 0 to 32 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_34 = 34, /*!< Acceptable priority is 0 to 33 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_35 = 35, /*!< Acceptable priority is 0 to 34 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_36 = 36, /*!< Acceptable priority is 0 to 35 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_37 = 37, /*!< Acceptable priority is 0 to 36 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_38 = 38, /*!< Acceptable priority is 0 to 37 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_39 = 39, /*!< Acceptable priority is 0 to 38 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_40 = 40, /*!< Acceptable priority is 0 to 39 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_41 = 41, /*!< Acceptable priority is 0 to 40 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_42 = 42, /*!< Acceptable priority is 0 to 41 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_43 = 43, /*!< Acceptable priority is 0 to 42 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_44 = 44, /*!< Acceptable priority is 0 to 43 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_45 = 45, /*!< Acceptable priority is 0 to 44 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_46 = 46, /*!< Acceptable priority is 0 to 45 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_47 = 47, /*!< Acceptable priority is 0 to 46 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_48 = 48, /*!< Acceptable priority is 0 to 47 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_49 = 49, /*!< Acceptable priority is 0 to 48 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_50 = 50, /*!< Acceptable priority is 0 to 49 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_51 = 51, /*!< Acceptable priority is 0 to 50 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_52 = 52, /*!< Acceptable priority is 0 to 51 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_53 = 53, /*!< Acceptable priority is 0 to 52 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_54 = 54, /*!< Acceptable priority is 0 to 53 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_55 = 55, /*!< Acceptable priority is 0 to 54 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_56 = 56, /*!< Acceptable priority is 0 to 55 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_57 = 57, /*!< Acceptable priority is 0 to 56 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_58 = 58, /*!< Acceptable priority is 0 to 57 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_59 = 59, /*!< Acceptable priority is 0 to 58 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_60 = 60, /*!< Acceptable priority is 0 to 59 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_61 = 61, /*!< Acceptable priority is 0 to 60 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_62 = 62, /*!< Acceptable priority is 0 to 61 */
    RH850_PLMR_PRIORITY_MASK_LEVEL_63 = 63  /*!< Acceptable priority is 0 to 62 */
} rh850_plmr_priority_mask_level_t;

/** @} */ /* end of RH850_IRQ_Types */

/* ###########################################  IRQ API Functions  ################################################## */

/**
 * @defgroup RH850_IRQ_API IRQ API Functions
 * @ingroup RH850_IRQ
 * @{
 */

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* ##########################################  IRQ System Register  ################################################# */

/**
 * @brief Get the highest-priority EI interrupt currently being serviced.
 *
 * This function reads the ISPR register and returns the highest priority level
 * (lowest numeric value) that is currently active.
 *
 * @return rh850_isr_priority_t Priority level [0..15].
 */

__STATIC_INLINE rh850_isr_priority_t __RH850_IRQ_InterruptPriorityGet (void)
{
    return (rh850_isr_priority_t) (__get_ISPR() & R_IRQ_ISPR_ISP_Msk);
}

 #if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   Get the current mask state for a specific IMSR bit (mask source).
 *
 * This function reads the CPU's **IMSR (Interrupt Mask Status Register)** and
 * evaluates a particular bit (e.g., EEIM, EPLM, EID, ENP, FNP) specified by @p LenMaskBit.
 * The return value indicates whether the corresponding mask condition **exists** (bit = 1)
 * or **does not exist** (bit = 0U).
 *
 * @param[in]   LenMaskBit
 *          Bit selector for IMSR (e.g., a mask with one of the IMSR bits set).
 *          Typical values correspond to the IMSR mask sources:
 *          - EEIM: EIINT masked by ISPR.ISP or PSW.EIMASK
 *          - EPLM: EINT masked by PLMR.PLM
 *          - EID : EINT masked by PSW.ID
 *          - ENP : EINT masked by PSW.NP
 *          - FNP : FEINT masked by PSW.NP
 *
 * @return  rh850_imsr_mask_t
 *          - RH850_IMSR_MASK_NOT_EXIST (0U): no mask condition present for the selected bit
 *          - RH850_IMSR_MASK_EXISTS    (1U): mask condition present for the selected bit
 */
__STATIC_INLINE rh850_imsr_mask_t __RH850_IRQ_InterruptMaskStatusGet (rh850_imsr_bit_t LenMaskBit)
{
    return (0U != (__get_IMSR() & (uint32_t) LenMaskBit)) ? RH850_IMSR_MASK_EXISTS : RH850_IMSR_MASK_NOT_EXIST;
}

 #endif                                /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief   Report whether any EIINT currently matches the PLMR-based mask condition (ICSR.PMEI status).
 *
 * This function reads the **ICSR (Interrupt Control Status Register)** and returns
 * whether a masked EIINT (due to **PLMR.PLM**) **exists** according to the PMEI flag.
 *
 * @return  rh850_imsr_eiint_eplm_mask_t
 */
__STATIC_INLINE rh850_imsr_eiint_eplm_mask_t __RH850_IRQ_InterruptControlStatusGet (void)
{
    return (0U != (__get_ICSR() & R_IRQ_ICSR_PMEI_Msk)) ?
           RH850_IMSR_EIINT_EPLM_MASK_EXISTS : RH850_IMSR_EIINT_EPLM_MASK_DOES_NOT_EXIST;
}

/**
 * @brief Get EPL bit (Interrupt priority level extension enable).
 * @return rh850_intcfg_extended_priority_level_t Current EPL state.
 */
__STATIC_INLINE rh850_intcfg_extended_priority_level_t __RH850_IRQ_PriorityExtensionGet (void)
{
    return (rh850_intcfg_extended_priority_level_t) ((__get_INTCFG() & R_IRQ_INTCFG_EPL_Msk) >> R_IRQ_INTCFG_EPL_Pos);
}

/**
 * @brief Set EPL bit (enable/disable priority level extension).
 * @param LenMode RH850_INTCFG_EXTENDED_PRIORITY_LEVEL_ENABLED or RH850_INTCFG_EXTENDED_PRIORITY_LEVEL_DISABLED.
 *
 * @details When enabled, device supports extended priority levels (e.g., up to 64),
 *          affecting ISPR/IMSR/ISPC interactions per manual (see priority mask sections).
 */
__STATIC_INLINE void __RH850_IRQ_PriorityExtensionSet (rh850_intcfg_extended_priority_level_t LenMode)
{
    uint32_t LulIntcfgRegVal;

    /* Read the INTCFG value and clear the EPL bit */
    LulIntcfgRegVal  = __get_INTCFG();
    LulIntcfgRegVal &= (~R_IRQ_INTCFG_EPL_Msk);

    /* Set the new EPL value */
    LulIntcfgRegVal |= (((uint32_t) LenMode << R_IRQ_INTCFG_EPL_Pos) & R_IRQ_INTCFG_EPL_Msk);

    /* Write back */
    __set_INTCFG(LulIntcfgRegVal);
}

/**
 * @brief Get the current ISPR update mode.
 *
 * @return rh850_intcfg_update_ispc_t
 *         - RH850_INTCFG_UPDATE_ISPC_AUTO    : ISPR auto-updated by hardware
 *         - RH850_INTCFG_UPDATE_ISPC_PROGRAM : ISPR updated by program (LDSR)
 */
__STATIC_INLINE rh850_intcfg_update_ispc_t __RH850_IRQ_IsprUpdateModeGet (void)
{
    return (rh850_intcfg_update_ispc_t) ((__get_INTCFG() & R_IRQ_INTCFG_ISPC_Msk) >> R_IRQ_INTCFG_ISPC_Pos);
}

/**
 * @brief Set the ISPR update mode.
 * @param[in] LenMode RH850_INTCFG_UPDATE_ISPC_AUTO or RH850_INTCFG_UPDATE_ISPC_PROGRAM.
 * @note Use AUTO (0U) for normal operation. Use PROGRAM (1) for software-based
 *       priority control where ISPR is updated via LDSR instruction.
 */
__STATIC_INLINE void __RH850_IRQ_IsprUpdateModeSet (rh850_intcfg_update_ispc_t LenMode)
{
    uint32_t LulIntcfgRegVal;

    /* Read the INTCFG value and mask for ISPC bit */
    LulIntcfgRegVal  = __get_INTCFG();
    LulIntcfgRegVal &= (~R_IRQ_INTCFG_ISPC_Msk);

    /* Set mode */
    LulIntcfgRegVal |= (((uint32_t) LenMode << R_IRQ_INTCFG_ISPC_Pos) & R_IRQ_INTCFG_ISPC_Msk);

    /* Write back */
    __set_INTCFG(LulIntcfgRegVal);
}

/**
 * @brief Get the maximum allowed register bank number (ULNR).
 * @return uint32_t ULNR value (0..63). Defines upper limit for register bank usage.
 * @note If RBNR.BN > ULNR or equals 63, and EIINTn uses register bank, SYSERR occurs.
 */
__STATIC_INLINE uint32_t __RH850_IRQ_RegisterBankLimitGet (void)
{
    return (uint32_t) ((__get_INTCFG() & R_IRQ_INTCFG_ULNR_Msk) >> R_IRQ_INTCFG_ULNR_Pos);
}

/**
 * @brief Set the maximum allowed register bank number (ULNR).
 * @param LulLimit ULNR value (0..63). See device manual for valid range.
 * @details ULNR prevents illegal register bank usage during EIINTn handling.
 *          Incorrect settings may cause SYSERR and interrupt rejection.
 */
__STATIC_INLINE void __RH850_IRQ_RegisterBankLimitSet (uint32_t LulLimit)
{
    uint32_t LulIntcfgRegVal;

    /* Read the INTCFG value and clear the ULNR field */
    LulIntcfgRegVal  = __get_INTCFG();
    LulIntcfgRegVal &= (~R_IRQ_INTCFG_ULNR_Msk);

    /* Set the limit */
    LulIntcfgRegVal |= ((LulLimit << R_IRQ_INTCFG_ULNR_Pos) & R_IRQ_INTCFG_ULNR_Msk);

    /* Write back */
    __set_INTCFG(LulIntcfgRegVal);
}

/**
 * @brief Get the current PLMR mask level (PLM).
 * @return rh850_plmr_priority_mask_level_t PLM value (0..63).
 */
__STATIC_INLINE rh850_plmr_priority_mask_level_t __RH850_IRQ_PriorityMaskLevelGet (void)
{
    return (rh850_plmr_priority_mask_level_t) (__get_PLMR() & R_IRQ_PLMR_PLM_Msk);
}

/**
 * @brief Set the PLMR mask level (PLM).
 * @param LenLevel rh850_plmr_priority_mask_level_t (0..63).
 * @details Masks all EIINTn with priority <= @p LenLevel.
 *          PLM=0 masks all; priority 63 is always masked.
 */
__STATIC_INLINE void __RH850_IRQ_PriorityMaskLevelSet (rh850_plmr_priority_mask_level_t LenLevel)
{
    __set_PLMR((uint32_t) LenLevel);
}

/**
 * @brief   Get Interrupt Mask
 * @details Returns the current state of the interrupt mask bit from the Interrupt Mask Register.
 * @return  Interrupt Mask value
 */
__STATIC_INLINE uint32_t __RH850_IRQ_IntMaskGet (void)
{
    return (uint32_t) ((__get_PSW() & R_SYS_PSW_ID_Msk) >> R_SYS_PSW_ID_Pos);
}

/**
 * @brief   Set Interrupt Mask
 * @details Assigns the given value to the Interrupt Mask Register.
 * @param [in]    priMask  Interrupt Mask
 */
__STATIC_INLINE void __RH850_IRQ_IntMaskSet (uint32_t priMask)
{
    if (0U != priMask)
    {
        __disable_irq();
    }
    else
    {
        __enable_irq();
    }
}

/* ##########################################  IRQ EEIC (INTC1/INTC2) Register  ##################################### */

/**
 * @brief   Enable Interrupt
 * @details Enables a device specific interrupt in the EIC interrupt controller.
 * @param [in]      IRQn  Device specific interrupt number.
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE void __RH850_IRQ_EnableIRQ (uint32_t IRQn)
{
    uint8_t LucCoreID = (uint8_t) __get_PEID();
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(LucCoreID, IRQn);

    /* Clear mask bit */
    RH850_EEIC_INTC->EEIC_b.EIMK = 0U;

    /* Dummy read & SYNCP */
    (void) RH850_EEIC_INTC->EEIC;
    __SYNCP();
}

/**
 * @brief   Enable Interrupt by PEn
 * @details Enables a device specific interrupt in the EIC interrupt controller for specific core ID (INTC1 Only).
 * @param [in]      CoreID  PEID of the INTC1 interrupt.
 * @param [in]      IRQn  Device specific interrupt number (INTC1).
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE void __RH850_IRQ_EnableIRQByPE (uint8_t CoreID, uint32_t IRQn)
{
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(CoreID, IRQn);

    /* Clear mask bit */
    RH850_EEIC_INTC->EEIC_b.EIMK = 0U;

    /* Dummy read & SYNCP */
    (void) RH850_EEIC_INTC->EEIC;
    __SYNCP();
}

/**
 * @brief   Disable Interrupt
 * @details Disable a device specific interrupt in the EIC interrupt controller.
 * @param [in]      IRQn  Device specific interrupt number.
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE void __RH850_IRQ_DisableIRQ (uint32_t IRQn)
{
    uint8_t LucCoreID = (uint8_t) __get_PEID();
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(LucCoreID, IRQn);

    /* Set mask bit */
    RH850_EEIC_INTC->EEIC_b.EIMK = 1U;

    /* Dummy read & SYNCP */
    (void) RH850_EEIC_INTC->EEIC;
    __SYNCP();
}

/**
 * @brief   Disable Interrupt by PEn
 * @details Disables a device specific interrupt in the EIC interrupt controller for specific core ID (INTC1 Only).
 * @param [in]      CoreID  PEID of the INTC1 interrupt.
 * @param [in]      IRQn  Device specific interrupt number (INTC1).
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE void __RH850_IRQ_DisableIRQByPE (uint8_t CoreID, uint32_t IRQn)
{
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(CoreID, IRQn);

    /* Set mask bit */
    RH850_EEIC_INTC->EEIC_b.EIMK = 1U;

    /* Dummy read & SYNCP */
    (void) RH850_EEIC_INTC->EEIC;
    __SYNCP();
}

/**
 * @brief   Get Interrupt Enable status
 * @details Returns a device specific interrupt enable status from the EIC interrupt controller.
 * @param [in]      IRQn  Device specific interrupt number.
 * \return             0  Interrupt is not enabled.
 * \return             1  Interrupt is enabled.
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE uint8_t __RH850_IRQ_GetEnableIRQ (uint32_t IRQn)
{
    uint8_t LucCoreID = (uint8_t) __get_PEID();
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(LucCoreID, IRQn);

    return (uint8_t) ((0U == RH850_EEIC_INTC->EEIC_b.EIMK) ? 1U : 0U);
}

/**
 * @brief   Get Interrupt Enable status by PEn
 * @details Returns a device specific interrupt enable status from the EIC interrupt controller
 * for specific core ID (INTC1 Only).
 * @param [in]      CoreID  PEID of the INTC1 interrupt.
 * @param [in]      IRQn  Device specific interrupt number (INTC1).
 * \return             0  Interrupt is not enabled.
 * \return             1  Interrupt is enabled.
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE uint8_t __RH850_IRQ_GetEnableIRQByPE (uint8_t CoreID, uint32_t IRQn)
{
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(CoreID, IRQn);

    return (uint8_t) ((0U == RH850_EEIC_INTC->EEIC_b.EIMK) ? 1U : 0U);
}

/**
 * @brief   Get Pending Interrupt
 * @details Reads the EIC pending register and returns the pending bit for the specified device specific interrupt.
 * @param [in]      IRQn  Device specific interrupt number.
 * \return             0  Interrupt status is not pending.
 * \return             1  Interrupt status is pending.
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE uint8_t __RH850_IRQ_GetPendingIRQ (uint32_t IRQn)
{
    uint8_t LucCoreID = (uint8_t) __get_PEID();
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(LucCoreID, IRQn);

    return (uint8_t) RH850_EEIC_INTC->EEIC_b.EIRF;
}

/**
 * @brief   Get Pending Interrupt
 * @details Reads the EIC pending register and returns the pending bit for the specified device specific interrupt
 * for specific core ID (INTC1 Only).
 * @param [in]      CoreID  PEID of the INTC1 interrupt.
 * @param [in]      IRQn  Device specific interrupt number (INTC1).
 * \return             0  Interrupt status is not pending.
 * \return             1  Interrupt status is pending.
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE uint8_t __RH850_IRQ_GetPendingIRQByPE (uint8_t CoreID, uint32_t IRQn)
{
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(CoreID, IRQn);

    return (uint8_t) RH850_EEIC_INTC->EEIC_b.EIRF;
}

/**
 * @brief   Clear Pending Interrupt
 * @details Clears the pending bit of a device specific interrupt in the EIC pending register.
 * @param [in]      IRQn  Device specific interrupt number.
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE void __RH850_IRQ_ClearPendingIRQ (uint32_t IRQn)
{
    uint8_t LucCoreID = (uint8_t) __get_PEID();
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(LucCoreID, IRQn);

    /* Detection of the edge */
    if (0U == RH850_EEIC_INTC->EEIC_b.EICT)
    {
        /* Clear the pending interrupt flag */
        RH850_EEIC_INTC->EEIC_b.EIRF = 0U;

        /* Dummy read & SYNCP */
        (void) RH850_EEIC_INTC->EEIC;
        __SYNCP();
    }
}

/**
 * @brief   Clear Pending Interrupt
 * @details Clears the pending bit of a device specific interrupt in the EIC pending register
 * for specific core ID (INTC1 Only).
 * @param [in]      CoreID  PEID of the INTC1 interrupt.
 * @param [in]      IRQn  Device specific interrupt number (INTC1).
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE void __RH850_IRQ_ClearPendingIRQByPE (uint8_t CoreID, uint32_t IRQn)
{
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(CoreID, IRQn);

    /* Detection of the edge */
    if (0U == RH850_EEIC_INTC->EEIC_b.EICT)
    {
        /* Clear the pending interrupt flag */
        RH850_EEIC_INTC->EEIC_b.EIRF = 0U;

        /* Dummy read & SYNCP */
        (void) RH850_EEIC_INTC->EEIC;
        __SYNCP();
    }
}

/**
 * @brief   Set Interrupt Priority
 * @details Sets the priority of a device specific interrupt or a processor exception.
 *         The interrupt number can be positive to specify a device specific interrupt,
 *         or negative to specify a processor exception.
 * @param [in]      IRQn  Interrupt number.
 * @param [in]  priority  Priority to set.
 * @note    The priority cannot be set for every processor exception.
 */
__STATIC_INLINE void __RH850_IRQ_SetPriority (uint32_t IRQn, uint32_t priority)
{
    uint8_t LucCoreID = (uint8_t) __get_PEID();
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(LucCoreID, IRQn);

    /* Set the interrupt priority */
    RH850_EEIC_INTC->EEIC_b.EIP = priority;

    /* Dummy read & SYNCP */
    (void) RH850_EEIC_INTC->EEIC;
    __SYNCP();
}

/**
 * @brief   Set Interrupt Priority
 * @details Sets the priority of a device specific interrupt or a processor exception.
 *         The interrupt number can be positive to specify a device specific interrupt,
 *         or negative to specify a processor exception for specific core ID (INTC1 Only).
 * @param [in]      CoreID  PEID of the INTC1 interrupt.
 * @param [in]      IRQn  Interrupt number (INTC1).
 * @param [in]  priority  Priority to set.
 * @note    The priority cannot be set for every processor exception.
 */
__STATIC_INLINE void __RH850_IRQ_SetPriorityByPE (uint8_t CoreID, uint32_t IRQn, uint32_t priority)
{
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(CoreID, IRQn);

    /* Set the interrupt priority */
    RH850_EEIC_INTC->EEIC_b.EIP = priority;

    /* Dummy read & SYNCP */
    (void) RH850_EEIC_INTC->EEIC;
    __SYNCP();
}

/**
 * @brief   Get Interrupt Priority
 * @details Reads the priority of a device specific interrupt or a processor exception.
 *         The interrupt number can be positive to specify a device specific interrupt,
 *         or negative to specify a processor exception.
 * @param [in]   IRQn  Interrupt number.
 * \return             Interrupt Priority.
 *                    Value is aligned automatically to the implemented priority bits of the microcontroller.
 */
__STATIC_INLINE uint32_t __RH850_IRQ_GetPriority (uint32_t IRQn)
{
    uint8_t LucCoreID = (uint8_t) __get_PEID();
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(LucCoreID, IRQn);

    /* Get the interrupt priority */
    return RH850_EEIC_INTC->EEIC_b.EIP;
}

/**
 * @brief   Get Interrupt Priority
 * @details Reads the priority of a device specific interrupt or a processor exception.
 *         The interrupt number can be positive to specify a device specific interrupt,
 *         or negative to specify a processor exception for specific core ID (INTC1 Only).
 * @param [in]   CoreID  PEID of the INTC1 interrupt.
 * @param [in]   IRQn  Interrupt number (INTC1).
 * \return             Interrupt Priority.
 *                    Value is aligned automatically to the implemented priority bits of the microcontroller.
 */
__STATIC_INLINE uint32_t __RH850_IRQ_GetPriorityByPE (uint8_t CoreID, uint32_t IRQn)
{
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(CoreID, IRQn);

    /* Get the interrupt priority */
    return RH850_EEIC_INTC->EEIC_b.EIP;
}

/**
 * @brief   Set the interrupt vector method
 * @details Sets the interrupt vector method specific for RH850 processor.
 * @param [in]      IRQn  Interrupt number.
 * @param [in]  vector_method  Interrupt Vector Method (0: Direct Vector Method/ 1: Table Reference Method)
 */
__STATIC_INLINE void __RH850_IRQ_SetIRQMethod (uint32_t IRQn, uint32_t vector_method)
{
    uint8_t LucCoreID = (uint8_t) __get_PEID();
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(LucCoreID, IRQn);

    /* Set the interrupt vector method */
    RH850_EEIC_INTC->EEIC_b.EITB = vector_method;

    /* Dummy read & SYNCP */
    (void) RH850_EEIC_INTC->EEIC;
    __SYNCP();
}

/**
 * @brief   Set the interrupt vector method
 * @details Sets the interrupt vector method specific for RH850 processor for specific core ID (INTC1 Only).
 * @param [in]  CoreID         PEID of the INTC1 interrupt.
 * @param [in]  IRQn           Interrupt number (INTC1).
 * @param [in]  vector_method  Interrupt Vector Method (0: Direct Vector Method/ 1: Table Reference Method)
 */
__STATIC_INLINE void __RH850_IRQ_SetIRQMethodByPE (uint8_t CoreID, uint32_t IRQn, uint32_t vector_method)
{
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(CoreID, IRQn);

    /* Set the interrupt vector method */
    RH850_EEIC_INTC->EEIC_b.EITB = vector_method;

    /* Dummy read & SYNCP */
    (void) RH850_EEIC_INTC->EEIC;
    __SYNCP();
}

/**
 * @brief   Get the interrupt vector method
 * @details Gets the interrupt vector method specific for RH850 processor.
 * @param [in]      IRQn  Interrupt number.
 * \return  Interrupt Vector Method (0: Direct Vector Method/ 1: Table Reference Method)
 */
__STATIC_INLINE uint8_t __RH850_IRQ_GetIRQMethod (uint32_t IRQn)
{
    uint8_t LucCoreID = (uint8_t) __get_PEID();
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(LucCoreID, IRQn);

    /* Return the interrupt vector method */
    return (uint8_t) RH850_EEIC_INTC->EEIC_b.EITB;
}

/**
 * @brief   Get the interrupt vector method
 * @details Gets the interrupt vector method specific for RH850 processor for specific core ID (INTC1 Only).
 * @param [in]      CoreID  PEID of the INTC1 interrupt.
 * @param [in]      IRQn  Interrupt number (INTC1).
 * \return  Interrupt Vector Method (0: Direct Vector Method/ 1: Table Reference Method)
 */
__STATIC_INLINE uint8_t __RH850_IRQ_GetIRQMethodByPE (uint8_t CoreID, uint32_t IRQn)
{
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(CoreID, IRQn);

    /* Return the interrupt vector method */
    return (uint8_t) RH850_EEIC_INTC->EEIC_b.EITB;
}

/**
 * @brief   Get Active Interrupt
 * @details Reads the active register in the EEIC and returns the active bit for the device specific interrupt.
 * @param [in]      IRQn  Device specific interrupt number.
 * @return             0  Interrupt status is not active.
 * @return             1  Interrupt status is active.
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t __RH850_IRQ_GetActive (uint32_t IRQn)
{
    uint8_t LucCoreID = (uint8_t) __get_PEID();
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(LucCoreID, IRQn);

    return (uint32_t) RH850_EEIC_INTC->EEIC_b.EIRF;
}

/**
 * @brief   Get Active Interrupt
 * @details Reads the active register in the EEIC and returns the active bit for the device specific interrupt
 * for specific core ID (INTC1 Only).
 * @param [in]      CoreID  PEID of the INTC1 interrupt.
 * @param [in]      IRQn  Device specific interrupt number (INTC1).
 * @return             0  Interrupt status is not active.
 * @return             1  Interrupt status is active.
 * @note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t __RH850_IRQ_GetActiveByPE (uint8_t CoreID, uint32_t IRQn)
{
    volatile RH850_IRQ_EEIC_Type * RH850_EEIC_INTC;

    /* Get the address of the specific EIC */
    RH850_EEIC_INTC = (volatile RH850_IRQ_EEIC_Type *) RH850_EEIC_ADDR(CoreID, IRQn);

    return (uint32_t) RH850_EEIC_INTC->EEIC_b.EIRF;
}

/**
 * @brief   Set the specify the interrupt bind (request) destination.
 * @details Sets the specify the interrupt bind (request) destination.
 * @param [in]      CoreID  The target PE for the interrupt to be bound.
 * @param [in]      IRQn  Interrupt number.
 */
__STATIC_INLINE void __RH850_IRQ_SetIRQBoundToPE (uint8_t CoreID, uint32_t IRQn)
{
    volatile RH850_IRQ_EIBD_INTC2_Type * RH850_EIBD_INTC;

    /* INTC2 */
    if (!RH850_IRQ_IS_INTC1(IRQn))
    {
        RH850_EIBD_INTC =
            (volatile RH850_IRQ_EIBD_INTC2_Type *) (RH850_INTC2_BASE + (4U * IRQn) + RH850_INTC2_EIBD_OFFSET);

        /* Specify the interrupt bind (request) destination */
        RH850_EIBD_INTC->EIBD_b.PEID = CoreID;

        /* Dummy read & SYNCP */
        (void) RH850_EIBD_INTC->EIBD;
        __SYNCP();
    }
}

/**
 * @brief   Get the specify the interrupt bind (request) destination.
 * @details Gets the specify the interrupt bind (request) destination.
 * @param [in]      CoreID  PEID of the INTC1 interrupt.
 * @param [in]      IRQn  Interrupt number.
 * \return  The specify the interrupt bind (request) destination.
 */
__STATIC_INLINE uint32_t __RH850_IRQ_GetIRQBoundToPE (uint8_t CoreID, uint32_t IRQn)
{
    volatile RH850_IRQ_EIBD_INTC1_Type * RH850_EIBD_INTC1;
    volatile RH850_IRQ_EIBD_INTC2_Type * RH850_EIBD_INTC2;
    uint32_t LulReturnValue;

    /* INTC1 */
    if (RH850_IRQ_IS_INTC1(IRQn))
    {
        RH850_EIBD_INTC1 = (volatile RH850_IRQ_EIBD_INTC1_Type *) (RH850_INTC1_BASE + RH850_INTC1_EIBD_OFFSET +
                                                                   ((uint32_t) CoreID * RH850_INTC1_OFFSET) +
                                                                   (4U * IRQn));

        /* Return the specify the interrupt bind (request) destination */
        LulReturnValue = RH850_EIBD_INTC1->EIBD_b.PEID;
    }
    else
    {
        RH850_EIBD_INTC2 = (volatile RH850_IRQ_EIBD_INTC2_Type *) (RH850_INTC2_BASE + RH850_INTC2_EIBD_OFFSET +
                                                                   (4U * IRQn));

        /* Return the specify the interrupt bind (request) destination */
        LulReturnValue = RH850_EIBD_INTC2->EIBD_b.PEID;
    }

    return LulReturnValue;
}

/** @} */ /* end of RH850_IRQ_API */

#endif                                 /* RH850_G4_IRQ_H */

/** @} */ /* end of RH850_IRQ */
/** @} */ /* end of RH850_CoreAccess_FunctionInterface */

#endif                                 /* #if defined(__IRQ_PRESENT) && (__IRQ_PRESENT == 1U) */
