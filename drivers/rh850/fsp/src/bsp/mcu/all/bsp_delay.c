/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"                             /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */
#include "bsp_delay.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_DELAY_NS_PER_US        (1000U)       ///< Number of nanoseconds in one microsecond
#define BSP_DELAY_NS_PER_SECOND    (1000000000U) ///< Number of nanoseconds in one second

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void bsp_prv_software_delay_loop(volatile uint32_t loop_cnt);
static void bsp_software_delay_loop(uint64_t loop_cnt);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_COMMON
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/******************************************************************************************************************//**
 *              Delay for at least the specified duration in units and return.
 * @param[in]   delay  The number of 'units' to delay.
 * @param[in]   units  The 'base' (bsp_delay_units_t) for the units specified. Valid values are:
 *              BSP_DELAY_UNITS_SECONDS, BSP_DELAY_UNITS_MILLISECONDS, BSP_DELAY_UNITS_MICROSECONDS.@n
 *              For example:@n
 *              At 200 MHz one cycle takes 1/200 microsecond or 5 nanoseconds.@n
 *              At 800 MHz one cycle takes 1/800 microsecond or 1.25 nanoseconds.@n
 *              Therefore one run through bsp_prv_software_delay_loop() takes:
 *              ~ (1.25 * BSP_DELAY_LOOP_CYCLES) or 500 ns.
 *              A delay of 2 us therefore requires 2000ns/500ns or 4 loops.
 *
 *              The 'theoretical' maximum delay that may be obtained is determined by a full 64 bit loop count and the
 *              system clock rate.
 *              @200MHz:  ((0xFFFFFFFFFFFFFFFF loops * 4 cycles /loop) / 200000000) = 102481911 hours.
 *              @800MHz:  ((0xFFFFFFFFFFFFFFFF loops * 4 cycles /loop) / 800000000) = 25620477  hours.
 *
 *              Note that requests for very large delays will be affected by rounding in the calculations and the
 *              actual delay achieved may be slightly longer. @200 MHz, for example, a request for 85 seconds will be
 *              closer to 86 seconds.
 *
 *              Note also that if the calculations result in a loop_cnt of zero, the bsp_prv_software_delay_loop()
 *              function is not called at all. In this case the requested delay is too small (nanoseconds) to be
 *              carried out by the loop itself, and the overhead associated with executing the code to just get
 *              to this point has certainly satisfied the requested delay.
 *
 *
 * @note This function calls bsp_cpu_clock_get() which ultimately calls R_FSP_SystemClockHzGet() and therefore requires
 *       that the BSP has already initialized the CGC (which it does as part of the Sysinit).
 *       Care should be taken to ensure this remains the case if in the future this function were to be called as part
 *       of the BSP initialization.
 *********************************************************************************************************************/
void R_BSP_SoftwareDelay (uint32_t delay, bsp_delay_units_t units)
{
    /* Get the system clock frequency in Hz. */
    uint32_t cpu_hz = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_CLK_CPU);

    if (0U == cpu_hz)
    {
        return;
    }

    /* Get the # of nanoseconds/cycle. */
    uint32_t ns_per_cycle = BSP_DELAY_NS_PER_SECOND / cpu_hz;
    uint64_t total_ns     = 0;

    /* Check if the result of multiplication will overflow*/
    if (delay > (UINT64_MAX / ((uint64_t) units * BSP_DELAY_NS_PER_US)))
    {
        total_ns = (uint64_t) UINT64_MAX;
    }
    else
    {
        /* Convert the requested time to nanoseconds. */
        total_ns = (uint64_t) delay * (uint64_t) units * BSP_DELAY_NS_PER_US;
    }

    /* Calculate the number of cycles and loops required.*/
    uint64_t cycles_requested = total_ns / ns_per_cycle;
    uint64_t loops_required   = cycles_requested / (uint64_t) BSP_DELAY_LOOP_CYCLES;

    /* Only delay if the supplied parameters constitute a delay. */
    if (loops_required > (uint64_t) 0)
    {
        bsp_software_delay_loop(loops_required);
    }
}

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_COMMON)
 **********************************************************************************************************************/

/********************************************************************************************************************
 * Software delay support 64 bits parameters
 * @param[in]   loop_cnt  The number of 'units' to delay.
 * @retval: void
 * *****************************************************************************************************************/
static void bsp_software_delay_loop (uint64_t loop_cnt)
{
    /* Split the 64-bit loop counter into upper and lower 32-bit parts, get upper part */
    uint32_t upper_part = (uint32_t) (loop_cnt >> 32);

    /* Outer loop: Iterate over the upper 32 bits */
    while (upper_part > 0U)
    {
        /* Call the assembly function with the 32-bit loop counter*/
        bsp_prv_software_delay_loop(0xFFFFFFFFU);

        /* Decrement the upper part of the loop counter */
        upper_part--;
    }

    uint32_t lower_part = (uint32_t) loop_cnt;
    if (0U != lower_part)
    {
        bsp_prv_software_delay_loop(lower_part);
    }
}

/********************************************************************************************************************
 * 1 cycle as CPUCLKD
 * LOOP cycle: 4 When the updated reg1 != 0 \ 2 When the updated reg1 = 0
 * NOP cycle: 1 to cover 2 cycles when reg1 of LOOP cycle == 0
 * Total cycle = (loop_cnt * 4)
 *
 * @param[in]   loop_cnt  The number of 'units' to delay.
 * @retval: void
 * *****************************************************************************************************************/
#if defined(__CCRH__)

 #pragma inline_asm bsp_prv_software_delay_loop
static void bsp_prv_software_delay_loop (volatile uint32_t loop_cnt) /* PRQA S 1006 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 & DP_MSR_D-4.2_UC1 */
{
    .local loop_label
loop_label:
    nop
    nop
    loop r6, loop_label
}

#elif defined(__ghs__) || defined(__ICCRH850__)

static void bsp_prv_software_delay_loop (volatile uint32_t loop_cnt)
{
    __asm__ volatile (
        "loop_label:             \n"
        "    nop                 \n"
        "    nop                 \n"
        "loop %0, loop_label       "
         : "+r" (loop_cnt)
         :
         : "memory"
    );
}

#elif defined(__GNUC__)

static void bsp_prv_software_delay_loop (volatile uint32_t loop_cnt)
{
    __asm__ volatile (
        "loop_label%=:             \n"
        "    nop                 \n"
        "    nop                 \n"
        "loop %0, loop_label%=      "
         : "+r" (loop_cnt)
         :
         : "memory"
    );
}

#endif
