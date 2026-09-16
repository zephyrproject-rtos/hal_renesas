/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_COMMON_H
#define BSP_COMMON_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* C99 includes. */
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

/* Different compiler support. */
#include "../../inc/api/fsp_common_api.h"
#include "bsp_compiler_support.h"

/* BSP module includes */
#include "../../src/bsp/mcu/all/bsp_sdram.h"
#if BSP_CFG_DCACHE_ENABLED
 #include "../../src/bsp/mcu/all/bsp_cache.h"
#endif

#include "bsp_cfg.h"

/* BSP module includes */
#include "../../src/bsp/mcu/all/bsp_tfu.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Used to configure the interrupt priority level into level 0 for disabling the interrupt. */
#define BSP_IRQ_DISABLED    (0)

/* Version of this module's code and API. */

#if 1 == BSP_CFG_RTOS                  /* ThreadX */
 #include "tx_user.h"
 #if defined(TX_ENABLE_EVENT_TRACE) || defined(TX_ENABLE_EXECUTION_CHANGE_NOTIFY)
  #include "tx_port.h"
  #define FSP_CONTEXT_SAVE       tx_isr_start((uint32_t) R_FSP_CurrentIrqGet());
  #define FSP_CONTEXT_RESTORE    tx_isr_end((uint32_t) R_FSP_CurrentIrqGet());
 #else
  #define FSP_CONTEXT_SAVE
  #define FSP_CONTEXT_RESTORE
 #endif

#else
 #define FSP_CONTEXT_SAVE
 #define FSP_CONTEXT_RESTORE
#endif

/** Macro that can be defined in order to enable logging in FSP modules. */
#ifndef FSP_LOG_PRINT
 #define FSP_LOG_PRINT(X)
#endif

/** Macro to log and return error without an assertion. */
#ifndef FSP_RETURN

 #define FSP_RETURN(err)    FSP_ERROR_LOG((err)); \
    return err;
#endif

/** This function is called before returning an error code. To stop on a runtime error, define fsp_error_log in
 * user code and do required debugging (breakpoints, stack dump, etc) in this function.*/
#if (1 == BSP_CFG_ASSERT)

 #ifndef FSP_ERROR_LOG
  #define FSP_ERROR_LOG(err) \
    fsp_error_log((err), __FILE__, __LINE__);
 #endif
#else

 #define FSP_ERROR_LOG(err)
#endif

/** Default assertion calls ::FSP_ERROR_RETURN if condition "a" is false. Used to identify incorrect use of API's in FSP
 * functions. */
#if (3 == BSP_CFG_ASSERT)
 #define FSP_ASSERT(a)
#elif (2 == BSP_CFG_ASSERT)
 #define FSP_ASSERT(a)    {assert(a);}
#else
 #define FSP_ASSERT(a)    FSP_ERROR_RETURN((a), FSP_ERR_ASSERTION)
#endif                                 // ifndef FSP_ASSERT

/** All FSP error codes are returned using this macro. Calls ::FSP_ERROR_LOG function if condition "a" is false. Used
 * to identify runtime errors in FSP functions. */

#define FSP_ERROR_RETURN(a, err)                        \
    {                                                   \
        if ((a))                                        \
        {                                               \
            (void) 0;                  /* Do nothing */ \
        }                                               \
        else                                            \
        {                                               \
            FSP_ERROR_LOG(err);                         \
            return err;                                 \
        }                                               \
    }

/* Function-like macro used to wait for a condition to be met, most often used to wait for hardware register updates.
 * This macro can be redefined to add a timeout if necessary. */
#ifndef FSP_HARDWARE_REGISTER_WAIT
 #define FSP_HARDWARE_REGISTER_WAIT(reg, required_value)    while (reg != required_value) { /* Wait. */}
#endif

#ifndef FSP_REGISTER_READ

/* Read a register and discard the result. */
 #if defined(__ICCRX__) || defined(__GNUC__)
  #define FSP_REGISTER_READ(A)    __asm volatile ("" : : "r" (A))
 #elif defined(__CCRX__)
  #define FSP_REGISTER_READ(A)    ((void) *(volatile uint32_t *) (A))
 #endif
#endif

/* This macro defines a variable for interrupt mask level. */
#ifndef BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION
 #define BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION    (BSP_FEATURE_PSW_MAX_IPL)
#endif

/* This macro defines a variable for saving previous mask value. */
#ifndef FSP_CRITICAL_SECTION_DEFINE

 #define FSP_CRITICAL_SECTION_DEFINE    uint32_t old_mask_level = 0U
#endif

#if (BSP_FEATURE_PSW_MAX_IPL == BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION)

/* These macros abstract methods to save and restore the interrupt state for different architectures. */
 #define FSP_CRITICAL_SECTION_GET_CURRENT_STATE    R_BSP_GetCurrentIFlagState
 #define FSP_CRITICAL_SECTION_SET_STATE            R_BSP_SetIFlagState
 #define FSP_CRITICAL_SECTION_IRQ_MASK_SET         (0U)
#else

/* These macros abstract methods to save and restore the interrupt state for different architectures. */
 #define FSP_CRITICAL_SECTION_GET_CURRENT_STATE    R_BSP_GetCurrentIpl
 #define FSP_CRITICAL_SECTION_SET_STATE            R_BSP_SetIpl
 #define FSP_CRITICAL_SECTION_IRQ_MASK_SET         (uint32_t) BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION
#endif

/** This macro temporarily saves the current interrupt state and disables interrupts. */
#ifndef FSP_CRITICAL_SECTION_ENTER
 #define FSP_CRITICAL_SECTION_ENTER                            \
    old_mask_level = FSP_CRITICAL_SECTION_GET_CURRENT_STATE(); \
    FSP_CRITICAL_SECTION_SET_STATE(FSP_CRITICAL_SECTION_IRQ_MASK_SET)
#endif

/** This macro restores the previously saved interrupt state, reenabling interrupts. */
#ifndef FSP_CRITICAL_SECTION_EXIT
 #define FSP_CRITICAL_SECTION_EXIT              FSP_CRITICAL_SECTION_SET_STATE(old_mask_level)

#endif

/* Number of Cortex processor exceptions, used as an offset from XPSR value for the IRQn_Type macro. */
#define FSP_PRIV_CORTEX_PROCESSOR_EXCEPTIONS    (16U)

/** Used to signify that the requested IRQ vector is not defined in this system. */
#define FSP_INVALID_VECTOR                      ((IRQn_Type) 0xFFFFFFFF)

/* Private definition used in bsp_clocks and R_FSP_SystemClockHzGet. Each bitfield in SCKDIVCR is up to 4 bits wide. */
#define FSP_PRV_SCKDIVCR_DIV_MASK               (0xFU)

/* Use the secure registers for secure projects and flat projects. */
#if ((!BSP_PZ_NONSECURE_BUILD) && BSP_FEATURE_PZ_HAS_PROTECTZONE)
 #define FSP_PRIV_PZ_USE_SECURE_REGS            (1)
#else
 #define FSP_PRIV_PZ_USE_SECURE_REGS            (0)
#endif

/* Put certain BSP variables in uninitialized RAM when initializing BSP early. */
#if BSP_CFG_EARLY_INIT
 #define BSP_SECTION_EARLY_INIT                 BSP_PLACE_IN_SECTION(BSP_SECTION_NOINIT)
#else
 #define BSP_SECTION_EARLY_INIT
#endif

/*
 * If the STYPE3 register's security attribution is set to secure, the non-secure application must read the register
 * from the secure application using the provided non-secure callable functions.
 */
#define FSP_STYPE3_REG8_READ(X, S)     (X)
#define FSP_STYPE3_REG16_READ(X, S)    (X)
#define FSP_STYPE3_REG32_READ(X, S)    (X)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Different warm start entry locations in the BSP. */
typedef enum e_bsp_warm_start_event
{
    BSP_WARM_START_RESET = 0,          ///< Called almost immediately after reset. No C runtime environment, clocks, or IRQs.
    BSP_WARM_START_POST_CLOCK,         ///< Called after clock initialization. No C runtime environment or IRQs.
    BSP_WARM_START_POST_C              ///< Called after clocks and C runtime environment have been set up
} bsp_warm_start_event_t;

/* Private enum used in R_FSP_SystemClockHzGet.  Maps clock name to base bit in SCKDIVCR. */
typedef enum e_fsp_priv_clock
{
    FSP_PRIV_CLOCK_PCLKD  = 0,
    FSP_PRIV_CLOCK_PCLKC  = 4,
    FSP_PRIV_CLOCK_PCLKB  = 8,
    FSP_PRIV_CLOCK_PCLKA  = 12,
    FSP_PRIV_CLOCK_BCLK   = 16,
    FSP_PRIV_CLOCK_PCLKE  = 20,
    FSP_PRIV_CLOCK_ICLK   = 24,
    FSP_PRIV_CLOCK_MRPCLK = 28,
    FSP_PRIV_CLOCK_CPUCLK = 32,
    FSP_PRIV_CLOCK_UNUSED = 255,       ///< Sentinel value for unused clock
} fsp_priv_clock_t;

/* Private enum used in R_FSP_SciSpiClockHzGe.  Maps clock name to base bit in SCISPICKCR. */
typedef enum e_fsp_priv_source_clock
{
    FSP_PRIV_CLOCK_HOCO     = 0,       ///< The high speed on chip oscillator
    FSP_PRIV_CLOCK_MOCO     = 1,       ///< The middle speed on chip oscillator
    FSP_PRIV_CLOCK_LOCO     = 2,       ///< The low speed on chip oscillator
    FSP_PRIV_CLOCK_MAIN_OSC = 3,       ///< The main oscillator
    FSP_PRIV_CLOCK_SUBCLOCK = 4,       ///< The subclock oscillator
    FSP_PRIV_CLOCK_PLL      = 5,       ///< The PLL output
    FSP_PRIV_CLOCK_PLL1P    = 5,       ///< The PLL1P output
    FSP_PRIV_CLOCK_PLL2     = 6,       ///< The PLL2 output
    FSP_PRIV_CLOCK_PLL2P    = 6,       ///< The PLL2P output
    FSP_PRIV_CLOCK_PLL1Q    = 7,       ///< The PLL1Q output
    FSP_PRIV_CLOCK_PLL1R    = 8,       ///< The PLL1R output
    FSP_PRIV_CLOCK_PLL2Q    = 9,       ///< The PLL2Q output
    FSP_PRIV_CLOCK_PLL2R    = 10,      ///< The PLL2R output
} fsp_priv_source_clock_t;

typedef struct st_bsp_unique_id
{
    union
    {
        uint32_t unique_id_words[4];
        uint8_t  unique_id_bytes[16];
    };
} bsp_unique_id_t;

typedef struct st_bsp_part_number
{
    union
    {
        uint32_t part_number_words[4];
        uint8_t  part_number_bytes[16];
    };
} bsp_part_number_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
uint32_t R_BSP_SourceClockHzGet(fsp_priv_source_clock_t clock);

/***********************************************************************************************************************
 * Global variables (defined in other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Inline Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Return active interrupt vector number value
 *
 * @return     Active interrupt vector number value
 **********************************************************************************************************************/
__STATIC_INLINE IRQn_Type R_FSP_CurrentIrqGet (void)
{
    extern uint32_t g_current_isr_number;

    return (IRQn_Type) g_current_isr_number;
}

/*******************************************************************************************************************//**
 * Gets the frequency of a system clock.
 *
 * @return     Frequency of requested clock in Hertz.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_FSP_SystemClockHzGet (fsp_priv_clock_t clock)
{
    uint32_t sckdivcr  = R_SYSTEM->SCKDIVCR;
    uint32_t clock_div = (sckdivcr >> clock) & FSP_PRV_SCKDIVCR_DIV_MASK;

    if (FSP_PRIV_CLOCK_CPUCLK == clock)
    {
        return SystemCoreClock;
    }

    /* Get CPUCLK divisor */
    uint32_t cpuclk_div = (uint32_t) (R_SYSTEM->SCKDIVCR2 & FSP_PRV_SCKDIVCR_DIV_MASK);

    /* Determine if either divisor is a multiple of 3 */
    if ((cpuclk_div | clock_div) & 8U)
    {
        /* Convert divisor settings to their actual values */
        cpuclk_div = (cpuclk_div & 8U) ? (3U << (cpuclk_div & 7U)) : (1U << cpuclk_div);
        clock_div  = (clock_div & 8U) ? (3U << (clock_div & 7U)) : (1U << clock_div);

        /* Calculate clock with multiplication and division instead of shifting */
        return (SystemCoreClock * cpuclk_div) / clock_div;
    }
    else
    {
        return (SystemCoreClock << cpuclk_div) >> clock_div;
    }
}

/*******************************************************************************************************************//**
 * Converts a clock's CKDIVCR register value to a clock divider (Eg: SPICKDIVCR).
 *
 * @return     Clock Divider
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_FSP_ClockDividerGet (uint32_t ckdivcr)
{
    if (2U >= ckdivcr)
    {
        /* clock_div:
         * - Clock Divided by 1: 0
         * - Clock Divided by 2: 1
         * - Clock Divided by 4: 2
         */
        return (uint32_t) (1U << ckdivcr);
    }
    else if (3U == ckdivcr)
    {
        /* Clock Divided by 6 */
        return 6U;
    }
    else if (4U == ckdivcr)
    {
        /* Clock Divided by 8 */
        return 8U;
    }
    else if (5U == ckdivcr)
    {
        /* Clock Divided by 3 */
        return 3U;
    }
    else if (6U == ckdivcr)
    {
        /* Clock Divided by 5 */
        return 5U;
    }
    else if (7U == ckdivcr)
    {
        /* Clock Divided by 10 */
        return 10U;
    }
    else if (8U == ckdivcr)
    {
        /* Clock Divided by 16 */
        return 16U;
    }
    else
    {
        /* The remaining case is ckdivcr = 9 which divides the clock by 32. */
    }

    /* Clock Divided by 32 */
    return 32U;
}

#if BSP_FEATURE_BSP_HAS_SPI_CLOCK

/*******************************************************************************************************************//**
 * Gets the frequency of a SPI clock.
 *
 * @return     Frequency of requested clock in Hertz.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_FSP_SpiClockHzGet (void)
{
    uint32_t                spidivcr  = R_SYSTEM->SPICKDIVCR;
    uint32_t                clock_div = R_FSP_ClockDividerGet(spidivcr & FSP_PRV_SCKDIVCR_DIV_MASK);
    fsp_priv_source_clock_t spicksel  =
        (fsp_priv_source_clock_t) ((R_SYSTEM->SPICKCR & R_SYSTEM_SPICKCR_SPICKSEL_Msk) >>
                                   R_SYSTEM_SPICKCR_SPICKSEL_Pos);

    return R_BSP_SourceClockHzGet(spicksel) / clock_div;
}

#endif
#if BSP_FEATURE_BSP_HAS_SCI_CLOCK

/*******************************************************************************************************************//**
 * Gets the frequency of a SCI clock.
 *
 * @return     Frequency of requested clock in Hertz.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_FSP_SciClockHzGet (void)
{
    uint32_t                scidivcr  = R_SYSTEM->SCICKDIVCR;
    uint32_t                clock_div = R_FSP_ClockDividerGet(scidivcr & FSP_PRV_SCKDIVCR_DIV_MASK);
    fsp_priv_source_clock_t scicksel  =
        (fsp_priv_source_clock_t) ((R_SYSTEM->SCICKCR & R_SYSTEM_SCICKCR_SCICKSEL_Msk) >>
                                   R_SYSTEM_SCICKCR_SCICKSEL_Pos);

    return R_BSP_SourceClockHzGet(scicksel) / clock_div;
}

#endif

/*******************************************************************************************************************//**
 * Get unique ID for this device.
 *
 * @return  A pointer to the unique identifier structure
 **********************************************************************************************************************/
__STATIC_INLINE bsp_unique_id_t const * R_BSP_UniqueIdGet (void)
{
    return (bsp_unique_id_t *) BSP_FEATURE_BSP_UNIQUE_ID_POINTER;
}

/*******************************************************************************************************************//**
 * Get part number for this device.
 *
 * @param[out] p_part_number    Memory address to return MCU's part number to.
 *
 * @retval FSP_SUCCESS          Part number information stored.
 * @retval FSP_ERR_ASSERTION    The parameter p_part_number is NULL.
 * @retval FSP_ERR_NOT_FOUND    An error occurred when retrieving data from part number register.
 **********************************************************************************************************************/
__STATIC_INLINE fsp_err_t R_BSP_PartNumberGet (bsp_part_number_t * const p_part_number)
{
#if BSP_CFG_PARAM_CHECKING_ENABLE

    /** Verify parameters are valid */
    if (NULL == p_part_number)
    {
        return FSP_ERR_ASSERTION;
    }
#endif

    /* Pointer to Part Numbering Register PNR */
    volatile bsp_part_number_t * p_pnr = (bsp_part_number_t *) BSP_FEATURE_BSP_PART_NUMBER_POINTER;

    /* In case part number is following the right order
     * for example: R 5 K 5 7 4 M C A 4 F C_ _ _ */
    if ((uint8_t) (p_pnr->part_number_words[0] & 0xff) == 'R')
    {
        memcpy(p_part_number, (void *) p_pnr, sizeof(bsp_part_number_t));
    }
    else
    {
        return FSP_ERR_NOT_FOUND;
    }

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
#if (1 == BSP_CFG_ASSERT)

/** Prototype of default function called before errors are returned in FSP code if BSP_CFG_LOG_ERRORS is set to 1. */
void fsp_error_log(fsp_err_t err, const char * file, int32_t line);

#endif

/** In the event of an unrecoverable error the BSP will by default call the __BKPT() intrinsic function which will
 *  alert the user of the error. The user can override this default behavior by defining their own
 *  BSP_CFG_HANDLE_UNRECOVERABLE_ERROR macro.
 */
#if !defined(BSP_CFG_HANDLE_UNRECOVERABLE_ERROR)

 #define BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(x)    __BKPT((x))
#endif

#if !defined(BSP_CFG_HANDLE_BREAK_EVENT_HOOK)

 #define BSP_CFG_HANDLE_BREAK_EVENT_HOOK(x)
#endif

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
