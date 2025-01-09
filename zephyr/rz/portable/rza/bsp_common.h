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

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#include "bsp_cfg.h"

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Used to signify that an ELC event is not able to be used as an interrupt. */
#define BSP_IRQ_DISABLED    (0xFFU)

/* Version of this module's code and API. */

#if 1 == BSP_CFG_RTOS                  /* ThreadX */
 #include "tx_user.h"
 #if defined(TX_ENABLE_EVENT_TRACE) || defined(TX_ENABLE_EXECUTION_CHANGE_NOTIFY)
  #include "tx_port.h"
  #define FSP_CONTEXT_SAVE       tx_isr_start((uint32_t) irq);
  #define FSP_CONTEXT_RESTORE    tx_isr_end((uint32_t) irq);
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
 #define FSP_REGISTER_READ(A)    __asm__ volatile ("" : : "r" (A));
#endif

/****************************************************************
 *
 * This check is performed to select suitable ASM API with respect to core
 *
 ***************************************************************/

/* This macro defines a variable for saving previous mask value */
#ifndef FSP_CRITICAL_SECTION_DEFINE

 #define FSP_CRITICAL_SECTION_DEFINE              uint64_t old_mask_level = 0U
#endif

/* These macros abstract methods to save and restore the interrupt state for different architectures. */
#define FSP_CRITICAL_SECTION_GET_CURRENT_STATE    R_BSP_GICC_GetMaskLevel
#define FSP_CRITICAL_SECTION_SET_STATE            R_BSP_GICC_SetMaskLevel
#define FSP_CRITICAL_SECTION_IRQ_MASK_SET         (0x0U)

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

/* Put certain BSP variables in uninitialized RAM when initializing BSP early. */
#if BSP_CFG_EARLY_INIT
 #define BSP_SECTION_EARLY_INIT                 BSP_PLACE_IN_SECTION(BSP_SECTION_NOINIT)
#else
 #define BSP_SECTION_EARLY_INIT
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

/* Private enum used in R_FSP_SystemClockHzGet. */
typedef enum e_fsp_priv_clock
{
    FSP_PRIV_CLOCK_ICLK = 0,           /* Cortex-A55 Clock */
    FSP_PRIV_CLOCK_I2CLK,              /* Cortex-M33 Clock */
    FSP_PRIV_CLOCK_S0CLK,              /* DDR-PHY Clock */
    FSP_PRIV_CLOCK_SPI0CLK,            /* SPI0 Clock */
    FSP_PRIV_CLOCK_SPI1CLK,            /* SPI1 Clock */
    FSP_PRIV_CLOCK_OC0CLK,             /* Octa0 Clock */
    FSP_PRIV_CLOCK_OC1CLK,             /* Octa1 Clock */
    FSP_PRIV_CLOCK_SD0CLK,             /* SDH0 Clock */
    FSP_PRIV_CLOCK_SD1CLK,             /* SDH1 Clock */
    FSP_PRIV_CLOCK_M0CLK,              /* VCP, LCDC Clock */
    FSP_PRIV_CLOCK_M2CLK,              /* CRU, MIPI-DSI Clock */
    FSP_PRIV_CLOCK_M3CLK,              /* MIPI-DSI, LCDC Clock */
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

#ifndef BSP_OVERRIDE_FSP_PRIV_CLOCK_DIVIDER_T

/* Private enum used in R_BSP_ClockDividerSet. */
typedef enum e_fsp_priv_clock_divider
{
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL1 = 0,
    FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_LPCLK,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_A,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_A,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_B,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_C,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_CLK200FIX,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_F,
    FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_A,
    FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_B,
    FSP_PRIV_CLOCK_DIVIDER_DIV_GPU,
    FSP_PRIV_CLOCK_DIVIDER_NUM,
} fsp_priv_clock_divider_t;

#endif

#ifndef BSP_OVERRIDE_FSP_PRIV_CLOCK_SELECTOR_T

/* Private enum used in R_BSP_ClockSelectorSet. */
typedef enum e_fsp_priv_clock_selector
{
    FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI0 = 0,
    FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI1,
    FSP_PRIV_CLOCK_SELECTOR_SEL_PLL3_3,
    FSP_PRIV_CLOCK_SELECTOR_SEL_PLL3_5,
    FSP_PRIV_CLOCK_SELECTOR_SEL_PLL4,
    FSP_PRIV_CLOCK_SELECTOR_SEL_PLL6_2,
    FSP_PRIV_CLOCK_SELECTOR_SEL_PLL_GPU2,
    FSP_PRIV_CLOCK_SELECTOR_NUM,
} fsp_priv_clock_selector_t;

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
__STATIC_INLINE fsp_err_t R_FSP_CurrentIrqGet (void)
{
    return (fsp_err_t) FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Get unique ID is not supported for this RZ MCU.
 *
 * @return  A pointer to the unique identifier structure
 **********************************************************************************************************************/
__STATIC_INLINE fsp_err_t R_BSP_UniqueIdGet ()
{
    return (fsp_err_t) FSP_ERR_UNSUPPORTED;
}

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
uint32_t  R_FSP_SystemClockHzGet(fsp_priv_clock_t clock);
void      R_FSP_SystemClockHzSet(fsp_priv_clock_t clock, uint32_t clock_sel, uint32_t clock_div);
fsp_err_t R_BSP_ClockSelectorSet(fsp_priv_clock_selector_t selector, uint32_t clock_sel);
fsp_err_t R_BSP_ClockDividerSet(fsp_priv_clock_divider_t divider, uint32_t clock_div);

#if ((1 == BSP_CFG_ERROR_LOG) || (1 == BSP_CFG_ASSERT))

/** Prototype of default function called before errors are returned in FSP code if BSP_CFG_LOG_ERRORS is set to 1. */
void fsp_error_log(fsp_err_t err, const char * file, int32_t line);

#endif

/** In the event of an unrecoverable error the BSP will by default call the __BKPT() intrinsic function which will
 *  alert the user of the error. The user can override this default behavior by defining their own
 *  BSP_CFG_HANDLE_UNRECOVERABLE_ERROR macro.
 */
#if !defined(BSP_CFG_HANDLE_UNRECOVERABLE_ERROR)

 #define BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(x)    __asm__ volatile ("brk 0x0\n")
#endif

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
