/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
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
#include "fsp_common_api.h"
#include "bsp_compiler_support.h"
#include "bsp_cfg.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Used to signify that an interrupt factor is not available. */
#define BSP_IRQ_DISABLED          (0xFFU)

/* Version of this module's code and API. */
#define BSP_CODE_VERSION_MAJOR    (1U)
#define BSP_CODE_VERSION_MINOR    (0U)
#define BSP_API_VERSION_MAJOR     (1U)
#define BSP_API_VERSION_MINOR     (0U)

#define FSP_CONTEXT_SAVE
#define FSP_CONTEXT_RESTORE

/** Macro to log and return error without an assertion. */
#ifndef FSP_RETURN

 #define FSP_RETURN(err)    FSP_ERROR_LOG((err)); \
    return err;
#endif

/** This function is called before returning an error code. To stop on a runtime error, define fsp_error_log in
 * user code and do required debugging (breakpoints, stack dump, etc) in this function.*/
#if (1 == BSP_CFG_ERROR_LOG)

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
 #define FSP_REGISTER_READ(A)    __ASM volatile ("" : : "r" (A));
#endif

/** Version data structure used by error logger macro. */
extern const fsp_version_t g_bsp_version;

/****************************************************************
 *
 * This check is performed to select suitable ASM API with respect to core
 *
 * The macros __CORE__ , __ARM7EM__ and __ARM_ARCH_8M_BASE__ are undefined for GCC,
 * but defined(__IAR_SYSTEMS_ICC__) is false for GCC,
 * so the left half of the || expression evaluates to false for GCC regardless of the values of these macros. */

#if (defined(__IAR_SYSTEMS_ICC__) && ((__CORE__ == __ARM7EM__) || (__CORE__ == __ARM_ARCH_8M_BASE__))) || \
    defined(__ARM_ARCH_7EM__)          // CM4
 #ifndef BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION
  #define BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION    (0U)
 #endif
#else // CM23
 #ifdef BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION
  #undef BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION
 #endif
 #define BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION    (0U)
#endif

/* This macro defines a variable for saving previous mask value */
#ifndef FSP_CRITICAL_SECTION_DEFINE

 #define FSP_CRITICAL_SECTION_DEFINE               uint32_t old_mask_level = 0U
#endif

/* These macros abstract methods to save and restore the interrupt state for different architectures. */
#if (0 == BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION)
 #define FSP_CRITICAL_SECTION_GET_CURRENT_STATE    __get_PRIMASK
 #define FSP_CRITICAL_SECTION_SET_STATE            __set_PRIMASK
 #define FSP_CRITICAL_SECTION_IRQ_MASK_SET         (1U)
#else
 #define FSP_CRITICAL_SECTION_GET_CURRENT_STATE    __get_BASEPRI
 #define FSP_CRITICAL_SECTION_SET_STATE            __set_BASEPRI
 #define FSP_CRITICAL_SECTION_IRQ_MASK_SET         ((uint8_t) (BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION << \
                                                               (8U - __NVIC_PRIO_BITS)))
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
#define FSP_INVALID_VECTOR                      ((IRQn_Type) - 33)

/* Use the secure registers for secure projects and flat projects. */
#if !BSP_TZ_NONSECURE_BUILD && BSP_FEATURE_TZ_HAS_TRUSTZONE
 #define FSP_PRIV_TZ_USE_SECURE_REGS            (1)
#else
 #define FSP_PRIV_TZ_USE_SECURE_REGS            (0)
#endif

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

#ifndef BSP_OVERRIDE_FSP_PRIV_CLOCK_T

/* Private enum used in R_FSP_SystemClockHzGet. */
typedef enum e_fsp_priv_clock
{
    FSP_PRIV_CLOCK_ICLK = 0,           /* Cortex-A55 Clock */
    FSP_PRIV_CLOCK_I2CLK,              /* Cortex-M33 Clock */
    FSP_PRIV_CLOCK_GCLK,               /* GPU Clock */
    FSP_PRIV_CLOCK_S0CLK,              /* DDR-PHY Clock */
    FSP_PRIV_CLOCK_SPI0CLK,            /* SPI0 Clock */
    FSP_PRIV_CLOCK_SPI1CLK,            /* SPI1 Clock */
    FSP_PRIV_CLOCK_SD0CLK,             /* SDH0 Clock */
    FSP_PRIV_CLOCK_SD1CLK,             /* SDH1 Clock */
    FSP_PRIV_CLOCK_M0CLK,              /* VCP, LCDC Clock */
    FSP_PRIV_CLOCK_M1CLK,              /* MIPI-DSI, MIPI-CSI Clock */
    FSP_PRIV_CLOCK_M2CLK,              /* CRU, MIPI-DSI Clock */
    FSP_PRIV_CLOCK_M3CLK,              /* MIPI-DSI, LCDC Clock */
    FSP_PRIV_CLOCK_M4CLK,              /* MIPI-DSI Clock */
    FSP_PRIV_CLOCK_HPCLK,              /* Ethernet Clock */
    FSP_PRIV_CLOCK_TSUCLK,             /* TSU Clock */
    FSP_PRIV_CLOCK_ZTCLK,              /* JAUTH Clock */
    FSP_PRIV_CLOCK_P0CLK,              /* APB-BUS Clock */
    FSP_PRIV_CLOCK_P1CLK,              /* AXI-BUS Clock */
    FSP_PRIV_CLOCK_P2CLK,              /* P2CLK */
    FSP_PRIV_CLOCK_ATCLK,              /* ATCLK */
    FSP_PRIV_CLOCK_OSCCLK,             /* OSC Clock */
    FSP_PRIV_CLOCK_NUM,
} fsp_priv_clock_t;

#endif

typedef struct st_bsp_unique_id
{
    union
    {
        uint32_t unique_id_words[4];
        uint8_t  unique_id_bytes[16];
    };
} bsp_unique_id_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

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
    xPSR_Type xpsr_value;
    xpsr_value.w = __get_xPSR();

    return (IRQn_Type) (xpsr_value.b.ISR - FSP_PRIV_CORTEX_PROCESSOR_EXCEPTIONS);
}

/*******************************************************************************************************************//**
 * Get unique ID is not supported in this device.
 *
 * @return  A pointer to the unique identifier structure
 **********************************************************************************************************************/
__STATIC_INLINE bsp_unique_id_t const * R_BSP_UniqueIdGet ()
{
    return (bsp_unique_id_t *) NULL;
}

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
uint32_t R_FSP_SystemClockHzGet(fsp_priv_clock_t clock);
void     R_FSP_SystemClockHzSet(fsp_priv_clock_t clock, uint32_t clock_sel, uint32_t clock_div);

#if ((1 == BSP_CFG_ERROR_LOG) || (1 == BSP_CFG_ASSERT))

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

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
