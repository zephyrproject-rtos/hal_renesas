/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#if defined(__ghs__)
#include "bsp_api.h"
#include <errno.h>

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

void * sbrk(intptr_t incr);

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/*******************************************************************************************************************//**
 * FSP implementation of the standard library _sbrk() function.
 * @param[in]   incr  The number of bytes being asked for by malloc().
 *
 * @note This function overrides the _sbrk version that exists in the newlib library that is linked with.
 *       That version improperly relies on the SP as part of it's allocation strategy. This is bad in general and
 *       worse in an RTOS environment. This version insures that we allocate the byte pool requested by malloc()
 *       only from our allocated HEAP area. Also note that newlib is pre-built and forces the pagesize used by
 *       malloc() to be 2048. That requires that we have a HEAP of at least 2048 if we are to support malloc().
 * @retval        Address of allocated area if successful, -1 otherwise.
 **********************************************************************************************************************/
void * sbrk (intptr_t incr)
{
    extern char _Heap_Begin __asm("__HeapBase");  ///< Defined by the linker.

    extern char _Heap_Limit __asm("__HeapLimit"); ///< Defined by the linker.

    uint32_t      bytes            = (uint32_t) incr;
    static char * current_heap_end = 0;
    char        * current_block_address;

    if (current_heap_end == 0)
    {
        current_heap_end = &_Heap_Begin;
    }

    current_block_address = current_heap_end;

    /* The returned address must be aligned to a word boundary to prevent hard faults on cores that do not support
     * unaligned access. We assume the heap starts on a word boundary and make sure all allocations are a multiple
     * of 4. */
    bytes = (bytes + 3U) & (~3U);
    if (current_heap_end + bytes > &_Heap_Limit)
    {
        /** Heap has overflowed */
        errno = ENOMEM;

        return (void *) -1;
    }

    current_heap_end += bytes;

    return (void *) current_block_address;
}

#endif

/******************************************************************************************************************//**
 * @} (end addtogroup BSP_MCU)
 *********************************************************************************************************************/
