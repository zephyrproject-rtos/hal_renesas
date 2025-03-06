/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_delay.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_DELAY_UNIT_CONV_S_TO_NS     (1000000000)
#define BSP_DELAY_UNIT_CONV_US_TO_NS    (1000)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 *              Delay for at least the specified duration in units and return. This function shouldn't be used to
 *              generate an accurate delay time. A running time of the function is depending on the region of memory
 *              where the function is excuted on and a frequency of the CPU clock.
 *
 *              The loop time of bsp_prv_software_delay_loop() varies depending on the CPU clock frequency and the type
 *              of memory the program runs on.
 *              The loop time parameter is determined by measuring the actual execution time of bsp_prv_software_delay_loop().
 *              The loop time parameter of software_delay_loop() can be changed by redefining the loop time parameter,
 *              BSP_FEATURE_BSP_DELAY_LOOP_CYCLES.
 *
 * @param[in]   delay  The number of 'units' to delay.
 * @param[in]   units  The 'base' (bsp_delay_units_t) for the units specified. Valid values are:
 *              BSP_DELAY_UNITS_SECONDS, BSP_DELAY_UNITS_MILLISECONDS, BSP_DELAY_UNITS_MICROSECONDS.@n
 *              For example:@n
 *              The case described is where one execution of bsp_prv_software_delay_loop() takes approximately 500ns,
 *              in which case a 100us delay requires 100000ns / 500ns -> 200 loops.
 *
 *              The 'theoretical' maximum delay that may be obtained is determined by a full 32 bit loop count and the
 *              system clock rate.
 *              @200MHz:  ((0xFFFFFFFF loops * 500ns) = 2147 seconds.
 *
 *              Note that requests for very large delays will be affected by rounding in the calculations and the
 *              actual delay achieved may be slightly off of a setting time.
 *
 *              Note also that if the calculations result in a loop_cnt of zero, the bsp_prv_software_delay_loop()
 *              function is not called at all. In this case the requested delay is too small (nanoseconds) to be
 *              carried out by the loop itself, and the overhead associated with executing the code to just get to this
 *              point has certainly satisfied the requested delay.
 *
 * @note This function uses SystemCoreClock and therefore requires that the BSP has already initialized the variable
 *       (which it does as part of the SystemInit).
 *       Care should be taken to ensure this remains the case if in the future this function were to be called as part
 *       of the BSP initialization.
 **********************************************************************************************************************/

void R_BSP_SoftwareDelay (uint32_t delay, bsp_delay_units_t units)
{
    double   iclk_hz;
    double   cycles_requested;
    double   ns_per_cycle;
    uint32_t loops_required = 0;
    uint64_t loops_64bits   = 0;
    uint32_t total_us       = (delay * units);
    uint64_t ns_64bits;

    iclk_hz = (double) SystemCoreClock;

    /* Calculate the time per CPU clock (in nsec) */
    ns_per_cycle = (double) BSP_DELAY_UNIT_CONV_S_TO_NS / iclk_hz;

    /* Convert wait time to nsec */
    ns_64bits = (uint64_t) total_us * (uint64_t) BSP_DELAY_UNIT_CONV_US_TO_NS;

    /* Check whether the wait time overflows the maximum value of 32 bits */
    if (ns_64bits <= UINT32_MAX)
    {
        /* If the wait time does not overflow the maximum value of 32 bits */
        /* Convert wait time to CPU clock units */
        cycles_requested = ((double) ns_64bits / ns_per_cycle);

        /* Calculate the number of loop processing executions by dividing it by the number of loop processing instructions. */
        loops_required = (uint32_t) (cycles_requested / BSP_FEATURE_BSP_DELAY_LOOP_CYCLES) + 1;
    }
    else
    {
        /* If the wait time overflows the maximum value of 32 bits */
        /* Calculate the number of loop processing executions from the wait time in usec units */
        loops_64bits = (uint64_t) (total_us / (ns_per_cycle * BSP_FEATURE_BSP_DELAY_LOOP_CYCLES)) + 1;

        /* Convert the number of executions of loop processing to the number of times in nsec */
        loops_64bits *= BSP_DELAY_UNIT_CONV_US_TO_NS; // Convert to ns unit.

        /* Check whether the number of executions of loop processing overflows the maximum value of 32 bits */
        if (loops_64bits <= UINT32_MAX)
        {
            /* If it doesn't overflow */
            /* Cast the loop processing execution count to a 32bit type variable */
            loops_required = (uint32_t) loops_64bits;
        }
        else
        {
            /* If it overflow */
            /* Set the number of loop processing executions to the maximum value of 32 bits */
            loops_required = UINT32_MAX;
        }
    }

    /** Only delay if the supplied parameters constitute a delay. */
    if (loops_required > (uint32_t) 0)
    {
        bsp_prv_software_delay_loop(loops_required);
    }
}

/** @} (end addtogroup BSP_MCU) */

/*******************************************************************************************************************//**
 *        This assembly language routine performs the loops according to the number passed to R0.
 *        The 'naked' attribute  indicates that the specified function does not need prologue/epilogue sequences
 *        generated by the compiler.
 * @param[in]     loop_cnt  The number of loops to iterate.
 **********************************************************************************************************************/
BSP_ATTRIBUTE_STACKLESS void bsp_prv_software_delay_loop (__attribute__((unused)) uint32_t loop_cnt)
{
    __asm volatile ("sw_delay_loop:         \n"

#if defined(__ICCARM__) || defined(__ARMCC_VERSION)
                    "   subs r0, #1         \n"
#elif defined(__GNUC__)
                    "   sub r0, r0, #1      \n"
#endif
                    "   cmp r0, #0          \n"

                    "   bne.n sw_delay_loop \n"

                    "   bx lr               \n");
}
