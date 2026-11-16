/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : bsp_common.h
 * Description  : Provides common BSP definitions, data types, macros, and utilities.
 **********************************************************************************************************************/
#ifndef BSP_COMMON_H_
#define BSP_COMMON_H_

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

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_COMMON
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Common version structure */
typedef struct st_fsp_version          /* PRQA S 1536 # Advisory R-2.4 */
{
    uint8_t code_version_minor;        ///< Code minor version
    uint8_t code_version_major;        ///< Code major version
    uint8_t api_version_minor;         ///< API minor version
    uint8_t api_version_major;         ///< API major version
} fsp_version_t;                       /* PRQA S 1535 # Advisory R-2.3 */

/** Unique ID structure */
typedef struct st_bsp_unique_id        /* PRQA S 1536 # Advisory R-2.4 */
{
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        uint32_t unique_id_words[4];   ///< Unique ID represented as four 32-bit words
        uint8_t  unique_id_bytes[16];  ///< Unique ID represented as a 16-byte array
    };                                 /* PRQA S 0660 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    /* PRQA S 0750 -- */
} bsp_unique_id_t;

/** Part number structure */
typedef struct st_bsp_part_number      /* PRQA S 1536 # Advisory R-2.4 */
{
    /* PRQA S 0750 ++ # Advisory R-19.2 */
    union
    {
        uint32_t product_name_words[3];  ///< Product name represented as three 32-bit words
        uint8_t  product_name_bytes[12]; ///< Product name represented as a 12-byte array
    } product_name;

    union
    {
        uint32_t product_number_word;     ///< Product number represented as a 32-bit value
        uint8_t  product_number_bytes[4]; ///< Product number represented as a 4-byte array
    } product_number;

    /* PRQA S 0750 -- */
} bsp_part_number_t;

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Indicates that the interrupt is disabled or unavailable. */
#define BSP_IRQ_DISABLED    (0xFFU)

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
 #if ((0 == BSP_CFG_RTOS) && (1 == BSP_NESTED_INTERRUPT))
  #define FSP_CONTEXT_SAVE       FSP_NESTED_SAVE
  #define FSP_CONTEXT_RESTORE    FSP_NESTED_RESTORE
 #else

/* PRQA S 1534 ++ # Advisory R-2.5 */
  #define FSP_CONTEXT_SAVE
  #define FSP_CONTEXT_RESTORE

/* PRQA S 1534 -- */
 #endif
#endif

/** Macro that can be defined in order to enable logging in FSP modules. */
#ifndef FSP_LOG_PRINT
 #define FSP_LOG_PRINT(X)
#endif

/** Macro to log and return error without an assertion. */
#ifndef FSP_RETURN
 #define FSP_RETURN(err)    FSP_ERROR_LOG((err)); \
    return (err);
#endif

/** This function is called before returning an error code. To stop on a runtime error, define fsp_error_log in
 * user code and do required debugging (breakpoints, stack dump, etc) in this function.*/
#if (1 == BSP_CFG_ERROR_LOG)

 #ifndef FSP_ERROR_LOG
  #define FSP_ERROR_LOG(err) \
    fsp_error_log((err), __FILE__, __LINE__); /* PRQA S 1710 # Advisory D-4.5 */
 #endif
#else

 #define FSP_ERROR_LOG(err)                   /* PRQA S 1710 # Advisory D-4.5 */
#endif

/** Default assertion calls ::FSP_ERROR_RETURN if condition "a" is false. Used to identify incorrect use of API's in FSP
 * functions. */
#if (3 == BSP_CFG_ASSERT)
 #define FSP_ASSERT(a)
#elif (2 == BSP_CFG_ASSERT)
 #define FSP_ASSERT(a)    {assert((a));}
#else
 #define FSP_ASSERT(a)    FSP_ERROR_RETURN((a), FSP_ERR_ASSERTION)
#endif

/** All FSP error codes are returned using this macro. Calls ::FSP_ERROR_LOG function if condition "a" is false. Used
 * to identify runtime errors in FSP functions. */

/* PRQA S 5209 # Advisory D-4.6 */
#define FSP_ERROR_RETURN(a, err)                        \
    {                                                   \
        if ((a))                                        \
        {                                               \
            (void) 0;                  /* Do nothing */ \
        }                                               \
        else                                            \
        {                                               \
            FSP_ERROR_LOG((err));                       \
            return (err);                               \
        }                                               \
    }

/* PRQA S 5209 -- */

/* Function-like macro used to wait for a condition to be met, most often used to wait for hardware register updates.
 * This macro can be redefined to add a timeout if necessary. */
#ifndef FSP_HARDWARE_REGISTER_WAIT
 #define FSP_HARDWARE_REGISTER_WAIT(reg, required_value)    while ((reg) != (required_value)) {__NOP(); /* Wait. */}
#endif

/** Used to signify that the requested IRQ vector is not defined in this system. */
#define FSP_INVALID_VECTOR    ((IRQn_Type) SHARED_PERIPHERAL_INTERRUPTS_MAX_ENTRIES) /* PRQA S 1534 # Advisory R-2.5 */

/***********************************************************************************************************************
 * Critical section definitions
 **********************************************************************************************************************/
#ifdef BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION
 #undef BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION                                  /* PRQA S 0847 # Advisory R-20.5 */
#endif
#define BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION    (0U)

/* This macro defines a variable for saving previous mask value */
#ifndef FSP_CRITICAL_SECTION_DEFINE
 #define FSP_CRITICAL_SECTION_DEFINE                   uint32_t old_mask_level = 0U
#endif

/* These macros abstract methods to save and restore the interrupt state for different architectures. */
#if (0 == BSP_CFG_IRQ_MASK_LEVEL_FOR_CRITICAL_SECTION)
 #define FSP_CRITICAL_SECTION_GET_CURRENT_STATE        __RH850_IRQ_IntMaskGet
 #define FSP_CRITICAL_SECTION_SET_STATE                __RH850_IRQ_IntMaskSet
 #define FSP_CRITICAL_SECTION_IRQ_MASK_SET             (1U)
#endif

/** This macro temporarily saves the current interrupt state and disables interrupts. */
#ifndef FSP_CRITICAL_SECTION_ENTER
 #define FSP_CRITICAL_SECTION_ENTER                            \
    old_mask_level = FSP_CRITICAL_SECTION_GET_CURRENT_STATE(); \
    FSP_CRITICAL_SECTION_SET_STATE(FSP_CRITICAL_SECTION_IRQ_MASK_SET)
#endif

/** This macro restores the previously saved interrupt state, re-enabling interrupts. */
#ifndef FSP_CRITICAL_SECTION_EXIT
 #define FSP_CRITICAL_SECTION_EXIT    FSP_CRITICAL_SECTION_SET_STATE(old_mask_level)
#endif

/** This macro for saving and restoring exception cause code in nested interrupt handling. */
#if ((0 == BSP_CFG_RTOS) && (1 == BSP_NESTED_INTERRUPT))
 #define FSP_NESTED_SAVE                                   \
    volatile uint16_t eiic_val = __STSR(SR_EIWR, SL_EIWR); \
    __LDSR(SR_EIWR, SL_EIWR, __STSR(SR_EIIC, SL_EIIC));    \
    __EI();

 #define FSP_NESTED_RESTORE             \
    __DI();                             \
    __LDSR(SR_EIIC, SL_EIIC, eiic_val); \
    __LDSR(SR_EIWR, SL_EIWR, eiic_val);
#endif

/* Put certain BSP variables in uninitialized RAM when initializing BSP early. */
#if BSP_CFG_EARLY_INIT                 /* PRQA S 3332 # DP_MSR_R-20.9_UC1 */
 #define BSP_SECTION_EARLY_INIT    BSP_PLACE_IN_SECTION(BSP_SECTION_NOINIT)
#else
 #define BSP_SECTION_EARLY_INIT        /* PRQA S 1534 # Advisory R-2.5 */
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Different warm start entry locations in the BSP. */
typedef enum e_bsp_warm_start_event    /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_WARM_START_RESET = 0,          ///< Called almost immediately after reset. No C runtime environment, clocks, or IRQs.
    BSP_WARM_START_POST_CLOCK,         ///< Called after clock initialization. No C runtime environment or IRQs.
    BSP_WARM_START_POST_C              ///< Called after clocks and C runtime environment have been set up
} bsp_warm_start_event_t;

/***********************************************************************************************************************
 * Inline Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Get unique ID for this device.
 *
 * @return  A pointer to the unique identifier structure
 **********************************************************************************************************************/
__STATIC_INLINE bsp_unique_id_t const * R_BSP_UniqueIdGet (void)
{
    return (bsp_unique_id_t *) BSP_FEATURE_BSP_UNIQUE_ID_POINTER; /* PRQA S 0306 # Advisory R-11.4 */
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

    /* Pointer to the first letter of Product Name register */
    uint8_t const * p_data = (uint8_t const *) BSP_FEATURE_BSP_PRODUCT_NAME_POINTER; /* PRQA S 0306 # Advisory R-11.4 */

    /* Check whether the first letter was 'R' */
    if ((uint8_t) 'R' == *p_data)
    {
        /* Get the Product Name of this device */
        (void) memcpy((uint8_t *) &p_part_number->product_name,
                      (uint8_t *) BSP_FEATURE_BSP_PRODUCT_NAME_POINTER, /* PRQA S 0306 # Advisory R-11.4 */
                      sizeof(p_part_number->product_name));
    }
    else
    {
        return FSP_ERR_NOT_FOUND;
    }

    /* Get the Product Number of this device */
    (void) memcpy((uint8_t *) &p_part_number->product_number,
                  (uint8_t *) BSP_FEATURE_BSP_PRODUCT_NUMBER_POINTER, /* PRQA S 0306 # Advisory R-11.4 */
                  sizeof(p_part_number->product_number));

    if ((0x00U == p_part_number->product_number.product_number_word) ||
        (0xFFFFFFFFU == p_part_number->product_number.product_number_word))
    {
        return FSP_ERR_NOT_FOUND;
    }

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
#if ((1 == BSP_CFG_ERROR_LOG) || (1 == BSP_CFG_ASSERT))

/** Prototype of default function called before errors are returned in FSP code if BSP_CFG_LOG_ERRORS is set to 1. */
void fsp_error_log(fsp_err_t err, const char * file, int32_t line); /* PRQA S 3449, 3451, 1753 # DP_MSR_R-8.5_UC1, DP_MSR_R-8.5_UC1, DP_MSR_R-8.6_UC1 */

#endif

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
