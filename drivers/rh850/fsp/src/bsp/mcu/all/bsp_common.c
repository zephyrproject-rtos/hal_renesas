/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"                   /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#if defined(__CCRH__)
 #define WEAK_ERROR_ATTRIBUTE    __attribute__((weak))
 #define WEAK_INIT_ATTRIBUTE     __attribute__((weak))
#elif defined(__ICCRH850__)
 #define WEAK_ERROR_ATTRIBUTE
 #define WEAK_INIT_ATTRIBUTE
 #pragma weak fsp_error_log                            = fsp_error_log_internal
 #pragma weak bsp_init                                 = bsp_init_internal
#elif defined(__GNUC__) || defined(__ghs__)
 #define WEAK_ERROR_ATTRIBUTE    __attribute__((weak, alias("fsp_error_log_internal")))
 #define WEAK_INIT_ATTRIBUTE     __attribute__((weak, alias("bsp_init_internal")))
#endif

#define FSP_SECTION_VERSION      ".version"

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/** Prototype of initialization function called before main.  This prototype sets the weak association of this
 * function to an internal example implementation. If this function is defined in the application code, the
 * application code version is used. */

void bsp_init(void * p_args) WEAK_INIT_ATTRIBUTE;                                        /* PRQA S 2071, 3449, 3451 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-8.5_UC1, DP_MSR_R-8.5_UC1 */

#if defined(__GNUC__) || defined(__ICCRH850__) || defined(__ghs__)
void bsp_init_internal(void * p_args);                                                   /// Default initialization function

#endif

void fsp_error_log(fsp_err_t err, const char * file, int32_t line) WEAK_ERROR_ATTRIBUTE; /* PRQA S 2071, 3449, 3451 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-8.5_UC1, DP_MSR_R-8.5_UC1 */

#if defined(__GNUC__) || defined(__ICCRH850__) || defined(__ghs__)
void fsp_error_log_internal(fsp_err_t err, const char * file, int32_t line);             /// Default error logger function

#endif

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/* FSP pack version structure. */
static BSP_DONT_REMOVE const fsp_pack_version_t g_fsp_version BSP_PLACE_IN_SECTION (FSP_SECTION_VERSION) = /* PRQA S 0759, 3218, 2071 # Advisory R-19.2, Advisory R-8.9, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
{
    .version_id_b =
    {
        .minor = FSP_VERSION_MINOR,
        .major = FSP_VERSION_MAJOR,
        .build = FSP_VERSION_BUILD,
        .patch = FSP_VERSION_PATCH
    }
};

/* Public FSP version name. */
BSP_DONT_REMOVE const uint8_t g_fsp_version_string[] BSP_PLACE_IN_SECTION(FSP_SECTION_VERSION) = /* PRQA S 2071, 3408, 1502 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-8.4_UC1, Advisory R-2.8 */
                                                                                                 FSP_VERSION_STRING;

/* Unique FSP version ID. */
/* PRQA S 1502, 2071, 3408 ++ # Advisory R-2.8, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-8.4_UC1 */
BSP_DONT_REMOVE const uint8_t g_fsp_version_build_string[] BSP_PLACE_IN_SECTION(FSP_SECTION_VERSION) =
    FSP_VERSION_BUILD_STRING;

/* PRQA S 1502, 2071, 3408 -- */

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_COMMON
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Get the FSP version based on compile time macros.
 *
 * @param[out] p_version        Memory address to return version information to.
 *
 * @retval FSP_SUCCESS          Version information stored.
 * @retval FSP_ERR_ASSERTION    The parameter p_version is NULL.
 **********************************************************************************************************************/
fsp_err_t R_FSP_VersionGet (fsp_pack_version_t * const p_version) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
#if BSP_CFG_PARAM_CHECKING_ENABLE

    /** Verify parameters are valid */
    FSP_ASSERT(NULL != p_version);
#endif

    *p_version = g_fsp_version;

    return FSP_SUCCESS;
}

/** @} (end addtogroup BSP_COMMON) */

/*******************************************************************************************************************//**
 * This function is used when the application does not provide fsp_error_log().
 *
 * @param[in]  err     The error code encountered.
 * @param[in]  file    The file name in which the error code was encountered.
 * @param[in]  line    The line number at which the error code was encountered.
 **********************************************************************************************************************/
#if defined(__GNUC__) || defined(__ICCRH850__) || defined(__ghs__)
void fsp_error_log_internal (fsp_err_t err, const char * file, int32_t line)
{
    FSP_PARAMETER_NOT_USED(err);
    FSP_PARAMETER_NOT_USED(file);
    FSP_PARAMETER_NOT_USED(line);
}

#endif

/*******************************************************************************************************************//**
 * This function is used when the application does not provide bsp_init().
 **********************************************************************************************************************/
#if defined(__GNUC__) || defined(__ICCRH850__) || defined(__ghs__)
void bsp_init_internal (void * p_args)
{
    /* Do nothing. */
    FSP_PARAMETER_NOT_USED(p_args);
}

#endif
