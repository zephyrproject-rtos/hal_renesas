/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_g4_pmu.h
 * @brief    Performance Measurement Function
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#if defined(__PMU_PRESENT) && (__PMU_PRESENT == 1U)

/** @defgroup RH850_CoreAccess_FunctionInterface RH850-Core Access Functions
 * @brief Access to the dedicated core access function.
 * @{
 */

/**
 * @defgroup RH850_PMU RH850 Performance Measurement Unit (PMU)
 * @ingroup RH850_CoreAccess_FunctionInterface
 * @brief RH850 PMU API and types
 * @{
 */

#ifndef RH850_G4_PMU_H
 #define RH850_G4_PMU_H

 #include <stdint.h>

/* #######################################  PMU Types and Enumerations  ############################################# */

/**
 * @defgroup RH850_PMU_Types PMU Types and Enumerations
 * @brief PMU Types and Enumerations
 * @ingroup RH850_PMU
 * @{
 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #define RH850_PMU_COUNT_CHANNEL_0    0U /*!< Performance count channel 0 */
 #define RH850_PMU_COUNT_CHANNEL_1    1U /*!< Performance count channel 1 */
 #define RH850_PMU_COUNT_CHANNEL_2    2U /*!< Performance count channel 2 */
 #define RH850_PMU_COUNT_CHANNEL_3    3U /*!< Performance count channel 3 */
 #define RH850_PMU_COUNT_CHANNEL_4    4U /*!< Performance count channel 4 */
 #define RH850_PMU_COUNT_CHANNEL_5    5U /*!< Performance count channel 5 */
 #define RH850_PMU_COUNT_CHANNEL_6    6U /*!< Performance count channel 6 */
 #define RH850_PMU_COUNT_CHANNEL_7    7U /*!< Performance count channel 7 */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**
 * @brief User-mode access control for PMU channel.
 */
typedef enum e_rh850_pmu_user_mode_access
{
    RH850_PMU_USER_MODE_ACCESS_DISABLE = 0, /*!< Disable user-mode access */
    RH850_PMU_USER_MODE_ACCESS_ENABLE  = 1  /*!< Enable user-mode access */
} rh850_pmu_user_mode_access_t;

/**
 * @brief PMU event selector.
 */
typedef enum e_rh850_pmu_number_of_event
{
    RH850_PMU_NUMBER_OF_EVENT_ALL_CLOCK_CYCLES                  = 0x00U, /*!< PMU event: All clock cycles */
    RH850_PMU_NUMBER_OF_EVENT_ALL_INSTRUCTIONS                  = 0x10U, /*!< PMU event: All instructions */
    RH850_PMU_NUMBER_OF_EVENT_BRANCH_INSTRUCTIONS               = 0x18U, /*!< PMU event: Branch instructions */
    RH850_PMU_NUMBER_OF_EVENT_CONDITIONAL_BRANCH_EXECUTIONS     = 0x19U, /*!< PMU event: Conditional branch executions */
    RH850_PMU_NUMBER_OF_EVENT_BRANCH_PREDICTION_MISSES          = 0x1AU, /*!< PMU event: Branch prediction misses */
    RH850_PMU_NUMBER_OF_EVENT_EIINT_ACCEPTANCES                 = 0x20U, /*!< PMU event: EIINT acceptances */
    RH850_PMU_NUMBER_OF_EVENT_FEINT_ACCEPTANCES                 = 0x21U, /*!< PMU event: FEINT acceptances */
    RH850_PMU_NUMBER_OF_EVENT_TERMINATING_EXCEPTION_ACCEPTANCES = 0x22U, /*!< PMU event: Terminating exception acceptances */
    RH850_PMU_NUMBER_OF_EVENT_RESUMABLE_EXCEPTION_ACCEPTANCES   = 0x23U, /*!< PMU event: Resumable exception acceptances */
    RH850_PMU_NUMBER_OF_EVENT_NO_INTERRUPT_CLOCK_CYCLES         = 0x28U, /*!< PMU event: No interrupt clock cycles */
    RH850_PMU_NUMBER_OF_EVENT_NO_INTERRUPT_AND_DISABLED_CYCLES  = 0x29U, /*!< PMU event: No interrupt and disabled cycles */
    RH850_PMU_NUMBER_OF_EVENT_INSTRUCTION_FETCH_REQUESTS        = 0x30U, /*!< PMU event: Instruction fetch requests */
    RH850_PMU_NUMBER_OF_EVENT_INSTRUCTION_CACHE_HITS            = 0x31U, /*!< PMU event: Instruction cache hits */
    RH850_PMU_NUMBER_OF_EVENT_STALL_CYCLES             = 0x40U,          /*!< PMU event: Stall cycles */
    RH850_PMU_NUMBER_OF_EVENT_FLASH_FETCH_REQUESTS     = 0x50U,          /*!< PMU event: Flash fetch requests */
    RH850_PMU_NUMBER_OF_EVENT_FLASH_DATA_READ_REQUESTS = 0x51U           /*!< PMU event: Flash data read requests */
} rh850_pmu_number_of_event_t;

/**
 * @brief Channel operation state.
 */
typedef enum e_rh850_channel_operation_state
{
    RH850_CHANNEL_OPERATION_STATE_DISABLE = 0, /*!< Channel disabled */
    RH850_CHANNEL_OPERATION_STATE_ENABLE  = 1  /*!< Channel enabled */
} rh850_channel_operation_state_t;

/** @} */ /* end of RH850_PMU_Types */

/* ###########################################  PMU API Functions  ################################################## */

/**
 * @defgroup RH850_PMU_API PMU API Functions
 * @brief PMU API Functions
 * @ingroup RH850_PMU
 * @{
 */

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* ##########################################  PMU Function Access  ################################################# */

/**
 * @brief       Read PMCTRL register of a PMU channel.
 * @param[in]   LucChannel   PMU channel index (0..7).
 * @return      uint32_t  Raw PMCTRLn value of the selected channel.
 * @note        Valid range for @p LucChannel is implementation-defined (typically 0..7).
 */
__STATIC_INLINE uint32_t __get_PMCTRL (uint8_t LucChannel)
{
    uint32_t LulReturnValue = 0U;

    /* PMU channel index */
    switch (LucChannel)
    {
        case (RH850_PMU_COUNT_CHANNEL_0):
        {
            LulReturnValue = __get_PMCTRL0();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_1):
        {
            LulReturnValue = __get_PMCTRL1();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_2):
        {
            LulReturnValue = __get_PMCTRL2();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_3):
        {
            LulReturnValue = __get_PMCTRL3();
            break;
        }

 #if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
        case (RH850_PMU_COUNT_CHANNEL_4):
        {
            LulReturnValue = __get_PMCTRL4();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_5):
        {
            LulReturnValue = __get_PMCTRL5();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_6):
        {
            LulReturnValue = __get_PMCTRL6();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_7):
        {
            LulReturnValue = __get_PMCTRL7();
            break;
        }
 #endif                                /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

        default:
        {
            break;
        }
    }

    /* Return value */
    return LulReturnValue;
}

/**
 * @brief       Write PMCTRL register of a PMU channel.
 * @param[in]   LucChannel   PMU channel index (0..7).
 * @param[in]   LulValue     Value to write into PMCTRLn.
 */
__STATIC_INLINE void __set_PMCTRL (uint8_t LucChannel, uint32_t LulValue)
{
    /* PMU channel index */
    switch (LucChannel)
    {
        case (RH850_PMU_COUNT_CHANNEL_0):
        {
            __set_PMCTRL0(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_1):
        {
            __set_PMCTRL1(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_2):
        {
            __set_PMCTRL2(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_3):
        {
            __set_PMCTRL3(LulValue);
            break;
        }

 #if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
        case (RH850_PMU_COUNT_CHANNEL_4):
        {
            __set_PMCTRL4(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_5):
        {
            __set_PMCTRL5(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_6):
        {
            __set_PMCTRL6(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_7):
        {
            __set_PMCTRL7(LulValue);
            break;
        }
 #endif                                /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

        default:
        {
            break;
        }
    }
}

/**
 * @brief       Write PMCOUNT register of a PMU channel.
 * @param[in]   LucChannel   PMU channel index (0..7).
 * @param[in]   LulValue     Initial count to load into PMCOUNTn.
 */
__STATIC_INLINE void __set_PMCOUNT (uint8_t LucChannel, uint32_t LulValue)
{
    /* PMU channel index */
    switch (LucChannel)
    {
        case (RH850_PMU_COUNT_CHANNEL_0):
        {
            __set_PMCOUNT0(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_1):
        {
            __set_PMCOUNT1(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_2):
        {
            __set_PMCOUNT2(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_3):
        {
            __set_PMCOUNT3(LulValue);
            break;
        }

 #if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
        case (RH850_PMU_COUNT_CHANNEL_4):
        {
            __set_PMCOUNT4(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_5):
        {
            __set_PMCOUNT5(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_6):
        {
            __set_PMCOUNT6(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_7):
        {
            __set_PMCOUNT7(LulValue);
            break;
        }
 #endif                                /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

        default:
        {
            break;
        }
    }
}

/**
 * @brief       Read PMCOUNT register of a PMU channel.
 * @param[in]   LucChannel   PMU channel index (0..7).
 * @return      uint32_t  Current PMCOUNTn value.
 */
__STATIC_INLINE uint32_t __get_PMCOUNT (uint8_t LucChannel)
{
    uint32_t LulReturnValue = 0U;

    /* PMU channel index */
    switch (LucChannel)
    {
        case (RH850_PMU_COUNT_CHANNEL_0):
        {
            LulReturnValue = __get_PMCOUNT0();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_1):
        {
            LulReturnValue = __get_PMCOUNT1();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_2):
        {
            LulReturnValue = __get_PMCOUNT2();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_3):
        {
            LulReturnValue = __get_PMCOUNT3();
            break;
        }

 #if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
        case (RH850_PMU_COUNT_CHANNEL_4):
        {
            LulReturnValue = __get_PMCOUNT4();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_5):
        {
            LulReturnValue = __get_PMCOUNT5();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_6):
        {
            LulReturnValue = __get_PMCOUNT6();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_7):
        {
            LulReturnValue = __get_PMCOUNT7();
            break;
        }
 #endif                                /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

        default:
        {
            break;
        }
    }

    /* Return value */
    return LulReturnValue;
}

 #if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief       Read PMSUBCND register of a PMU channel.
 * @param[in]   LucChannel   PMU channel index (0..7).
 * @return      uint32_t  Raw PMSUBCNDn value.
 * @details     Reads PMSUBCNDn (SRn, bank 15). The meaning of SUBCND depends on PMCTRLn.CND.
 */
__STATIC_INLINE uint32_t __get_PMSUBCND (uint8_t LucChannel)
{
    uint32_t LulReturnValue = 0U;

    /* PMU channel index */
    switch (LucChannel)
    {
        case (RH850_PMU_COUNT_CHANNEL_0):
        {
            LulReturnValue = __get_PMSUBCND0();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_1):
        {
            LulReturnValue = __get_PMSUBCND1();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_2):
        {
            LulReturnValue = __get_PMSUBCND2();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_3):
        {
            LulReturnValue = __get_PMSUBCND3();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_4):
        {
            LulReturnValue = __get_PMSUBCND4();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_5):
        {
            LulReturnValue = __get_PMSUBCND5();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_6):
        {
            LulReturnValue = __get_PMSUBCND6();
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_7):
        {
            LulReturnValue = __get_PMSUBCND7();
            break;
        }

        default:
        {
            break;
        }
    }

    /* Return value */
    return LulReturnValue;
}

 #endif                                /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

 #if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief       Write PMSUBCND register of a PMU channel.
 * @param[in]   LucChannel   PMU channel index (0..7).
 * @param[in]   LulValue     SUBCND value to program.
 * @details     Writes PMSUBCNDn (SRn, bank 15). Only effective for event numbers that
 *              define a sub-condition; otherwise the value has no effect on counting.
 */
__STATIC_INLINE void __set_PMSUBCND (uint8_t LucChannel, uint32_t LulValue)
{
    /* PMU channel index */
    switch (LucChannel)
    {
        case (RH850_PMU_COUNT_CHANNEL_0):
        {
            __set_PMSUBCND0(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_1):
        {
            __set_PMSUBCND1(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_2):
        {
            __set_PMSUBCND2(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_3):
        {
            __set_PMSUBCND3(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_4):
        {
            __set_PMSUBCND4(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_5):
        {
            __set_PMSUBCND5(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_6):
        {
            __set_PMSUBCND6(LulValue);
            break;
        }

        case (RH850_PMU_COUNT_CHANNEL_7):
        {
            __set_PMSUBCND7(LulValue);
            break;
        }

        default:
        {
            break;
        }
    }
}

 #endif                                /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief Enable counting (CEN=1) for a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @details Sets PMCTRLn.CEN to 1.
 */
__STATIC_INLINE void __RH850_PMU_ChannelEnable (uint8_t LucChannel)
{
    uint32_t LulPmctrlRegValue;

    /* Read current PMCTRL value for the channel */
    LulPmctrlRegValue = __get_PMCTRL(LucChannel);

    /* Set CEN value to 1 */
    LulPmctrlRegValue |= (R_PMU_PMCTRL0_CEN_Msk);

    /* Write back updated PMCTRL */
    __set_PMCTRL(LucChannel, LulPmctrlRegValue);
}

/**
 * @brief Disable counting (CEN=0) for a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @details Clears PMCTRLn.CEN.
 */
__STATIC_INLINE void __RH850_PMU_ChannelDisable (uint8_t LucChannel)
{
    uint32_t LulPmctrlRegValue;

    /* Read current PMCTRL value for the channel */
    LulPmctrlRegValue = __get_PMCTRL(LucChannel);

    /* Set CEN value to 0 */
    LulPmctrlRegValue &= (~R_PMU_PMCTRL0_CEN_Msk);

    /* Write back updated PMCTRL */
    __set_PMCTRL(LucChannel, LulPmctrlRegValue);
}

/**
 * @brief Enable or disable user-mode access for a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @param[in] LenMode RH850_PMU_USER_MODE_ACCESS_DISABLE/ENABLE.
 * @details Performs read-modify-write on PMUMCTRL to set/clear PMUE[channel].
 */
__STATIC_INLINE void __RH850_PMU_ModeSet (uint8_t LucChannel, rh850_pmu_user_mode_access_t LenMode)
{
    uint32_t LulPmumctrlRegValue;

    /* Read current PMUMCTRL value */
    LulPmumctrlRegValue = __get_PMUMCTRL();

    /* Clear the target PMUE[channel] bit before setting new value */
    LulPmumctrlRegValue &= (~(1UL << LucChannel) & R_PMU_PMUMCTRL_PMUE_Msk);

    /* Set new PMUE[channel] value */
    LulPmumctrlRegValue |= (((uint32_t) LenMode << LucChannel) & R_PMU_PMUMCTRL_PMUE_Msk);

    /* Write back updated PMUMCTRL */
    __set_PMUMCTRL(LulPmumctrlRegValue);
}

/**
 * @brief Set event number (CND) for a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @param[in] LenCndBits Event selector (see rh850_pmu_number_of_event_t).
 * @details Updates PMCTRLn.CND.
 */
__STATIC_INLINE void __RH850_PMU_ControlSet (uint8_t LucChannel, rh850_pmu_number_of_event_t LenCndBits)
{
    uint32_t LulPmctrlRegValue;

    /* Read current PMCTRL value for the channel */
    LulPmctrlRegValue = __get_PMCTRL(LucChannel);

    /* Clear the CND field before setting new value */
    LulPmctrlRegValue &= (~R_PMU_PMCTRL0_CND_Msk);

    /* Set new CND value */
    LulPmctrlRegValue |= (((uint32_t) LenCndBits << R_PMU_PMCTRL0_CND_Pos) & R_PMU_PMCTRL0_CND_Msk);

    /* Write back updated PMCTRL */
    __set_PMCTRL(LucChannel, LulPmctrlRegValue);
}

/**
 * @brief Get enable state (CEN) of a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @details Reads PMCTRLn and extracts the CEN bit.
 * @return RH850_CHANNEL_OPERATION_STATE_DISABLE/RH850_CHANNEL_OPERATION_STATE_ENABLE
 * (CEN=0 - counting disabled/ CEN=1 - counting enabled).
 */
__STATIC_INLINE rh850_channel_operation_state_t __RH850_PMU_StatusGet (uint8_t LucChannel)
{
    uint32_t LulPmctrlRegValue;
    rh850_channel_operation_state_t LenReturnValue;

    /* Read current PMCTRL value for the channel */
    LulPmctrlRegValue = __get_PMCTRL(LucChannel);

    /* Get CEN value */
    LenReturnValue =
        (rh850_channel_operation_state_t) ((LulPmctrlRegValue & R_PMU_PMCTRL0_CEN_Msk) >> R_PMU_PMCTRL0_CEN_Pos);

    /* Return the value of CEN bit */
    return LenReturnValue;
}

/**
 * @brief Read overflow flag (OVF) of a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @return uint8_t 1 if overflow occurred; 0 otherwise.
 * @details Extracts PMCTRLn.OVF. Hardware sets OVF when PMCOUNTn wraps from 0xFFFFFFFF to 0.
 */
__STATIC_INLINE uint8_t __RH850_PMU_OverflowGet (uint8_t LucChannel)
{
    uint32_t LulPmctrlRegValue;
    uint8_t  LucReturnValue;

    /* Read current PMCTRL value for the channel */
    LulPmctrlRegValue = __get_PMCTRL(LucChannel);

    /* Get OVF value */
    LucReturnValue = (uint8_t) ((LulPmctrlRegValue & R_PMU_PMCTRL0_OVF_Msk) >> R_PMU_PMCTRL0_OVF_Pos);

    /* Return the value of OVF bit */
    return LucReturnValue;
}

/**
 * @brief Clear overflow flag (OVF) of a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @details Clears PMCTRLn.OVF by writing 0 to the bit using read-modify-write.
 */
__STATIC_INLINE void __RH850_PMU_OverflowClear (uint8_t LucChannel)
{
    uint32_t LulPmctrlRegValue;

    /* Read current PMCTRL value for the channel */
    LulPmctrlRegValue = __get_PMCTRL(LucChannel);

    /* Clear OVF bit */
    LulPmctrlRegValue &= (~R_PMU_PMCTRL0_OVF_Msk);

    /* Write back updated PMCTRL */
    __set_PMCTRL(LucChannel, LulPmctrlRegValue);
}

/**
 * @brief Set the PMCOUNT of a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @param[in] LulCount Initial count value to write.
 * @details Writes PMCOUNTn. The counter can be primed before enabling counting.
 */
__STATIC_INLINE void __RH850_PMU_CounterSet (uint8_t LucChannel, uint32_t LulCount)
{
    /* Write back updated PMCOUNT */
    __set_PMCOUNT(LucChannel, LulCount);
}

/**
 * @brief Get the PMCOUNT of a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @return uint32_t Current PMCOUNTn value.
 * @details Reads PMCOUNTn irrespective of CEN state.
 */
__STATIC_INLINE uint32_t __RH850_PMU_CounterGet (uint8_t LucChannel)
{
    /* Return the value of PMCOUNT */
    return __get_PMCOUNT(LucChannel);
}

 #if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set the PMSUBCND of a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @param[in] LulCount SUBCND value to write.
 * @details Programs PMSUBCNDn.
 */
__STATIC_INLINE void __RH850_PMU_SubCountSet (uint8_t LucChannel, uint32_t LulCount)
{
    /* Write back updated PMSUBCND */
    __set_PMSUBCND(LucChannel, LulCount);
}

 #endif                                /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

 #if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get the PMSUBCND of a PMU channel.
 * @param[in] LucChannel PMU channel index (0..7).
 * @return uint32_t Current PMSUBCNDn value.
 * @details Reads PMSUBCNDn.
 */
__STATIC_INLINE uint32_t __RH850_PMU_SubCountGet (uint8_t LucChannel)
{
    /* Return the value of PMSUBCND */
    return __get_PMSUBCND(LucChannel);
}

 #endif                                /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/** @} */ /* end of RH850_PMU_API */

#endif                                 /* RH850_G4_PMU_H */

/** @} */ /* end of RH850_PMU */
/** @} */ /* end of RH850_CoreAccess_FunctionInterface */

#endif                                 /* #if defined(__PMU_PRESENT) && (__PMU_PRESENT == 1U) */
