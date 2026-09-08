/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#if defined(__GNUC__) || defined(__CCRX__)
#include "bsp_api.h"

#if defined(__GNUC__)

 #include <sys/types.h>
#endif
#include <errno.h>

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#if defined(__GNUC__)
 #define BSP_SBRK_RET_TYPE    caddr_t
 #define BSP_SBRK_ARG_TYPE    int
 #define BSP_SBRK_ARG_VAR     incr

#else
 #define BSP_SBRK_RET_TYPE    char *
 #define BSP_SBRK_ARG_TYPE    size_t
 #define BSP_SBRK_ARG_VAR     size

#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
BSP_SBRK_RET_TYPE sbrk(BSP_SBRK_ARG_TYPE BSP_SBRK_ARG_VAR);

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/
volatile char * current_block_address_test;

/*******************************************************************************************************************//**
 * FSP implementation of the standard library _sbrk() function.
 * @param[in]   inc  The number of bytes being asked for by malloc().
 *
 * @note This function overrides the _sbrk version that exists in the newlib library that is linked with.
 *       That version improperly relies on the SP as part of it's allocation strategy. This is bad in general and
 *       worse in an RTOS environment. This version insures that we allocate the byte pool requested by malloc()
 *       only from our allocated HEAP area. Also note that newlib is pre-built and forces the pagesize used by
 *       malloc() to be 4096. That requires that we have a HEAP of at least 4096 if we are to support malloc().
 * @retval        Address of allocated area if successful, -1 otherwise.
 **********************************************************************************************************************/
BSP_SBRK_RET_TYPE sbrk (BSP_SBRK_ARG_TYPE BSP_SBRK_ARG_VAR)
{
#if (BSP_CFG_HEAP_BYTES > 0)
    extern uint8_t  g_heap[BSP_CFG_HEAP_BYTES];
    static uint32_t current_block_offset = 0;

    /* The returned address must be aligned to a word boundary to prevent hard faults on cores that do not support
     * unaligned access. The heap starts on a word boundary, and the required size BSP_SBRK_ARG_VAR is also aligned in malloc(). */

    if (current_block_offset + (uint32_t) BSP_SBRK_ARG_VAR > BSP_CFG_HEAP_BYTES)
    {
        /** Heap has overflowed */
        errno = ENOMEM;

        return (BSP_SBRK_RET_TYPE) -1;
    }

    char * current_block_address = (char *) &g_heap[current_block_offset];
    current_block_offset += (uint32_t) BSP_SBRK_ARG_VAR;

    return (BSP_SBRK_RET_TYPE) current_block_address;
#else
    FSP_PARAMETER_NOT_USED(BSP_SBRK_ARG_VAR);

    /** Heap not allocated!!! */
    errno = ENOMEM;

    return (BSP_SBRK_RET_TYPE) -1;
#endif
}

#endif

/******************************************************************************************************************//**
 * @} (end addtogroup BSP_MCU)
 *********************************************************************************************************************/
