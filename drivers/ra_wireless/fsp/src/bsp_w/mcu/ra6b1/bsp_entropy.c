/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_entropy.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

fsp_err_t libentropy_generate(void);
uint8_t * libentropy_get_entropy(void);
size_t    libentropy_get_entropy_size(void);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

fsp_err_t bsp_entropy_generate (uint32_t delay)
{
    /* Reset the PDC look-up table */
    bsp_pd_ctrl_entry_reset(NULL, 0, NULL);

    /* Data in MAC RAM3 are not retained when PD_RAD is off */
    CRG_TOP->RAM_RETAIN_REG_b.RET_MACRAM3 = 0;

    // Disable the CMAC RAM
    CRG_TOP->PMU_CTRL_REG_b.RADIO_SLEEP = 1;
    while (CRG_TOP->SYS_STAT_REG_b.RAD_IS_DOWN == 0)
    {
        ;
    }

    /* Temporarily switch CMAC_CLK_SPEED for entropy harvesting. */
    CRG_TOP->CLK_RADIO_REG_b.CMAC_CLK_SPEED = 2;

    *(volatile uint32_t *) (0x401000E0) |= (1U << 3);

    // Delay to allow RAM cells to discharge.
    R_BSP_SoftwareDelay(delay, BSP_DELAY_UNITS_MILLISECONDS);

    *(volatile uint32_t *) (0x401000E0) &= ~(1U << 3);

    // enable the CMAC_RAM for harvesting entropy and making sure the CMAC RAM is ready
    CRG_TOP->PMU_CTRL_REG_b.RADIO_SLEEP = 0;
    while (CRG_TOP->SYS_STAT_REG_b.RAD_IS_UP == 0)
    {
        ;
    }

    fsp_err_t rc = libentropy_generate();

    /* Restore original clock settings */
    CRG_TOP->CLK_RADIO_REG_b.CMAC_CLK_SPEED = 0;

    return rc;
}

uint8_t * bsp_entropy_get_seed (void)
{
    return libentropy_get_entropy();
}

size_t bsp_entropy_get_seed_size (void)
{
    return libentropy_get_entropy_size();
}

#if defined(__IAR_SYSTEMS_ICC__)

/*
 * IAR links against a GCC-built entropy library that references __popcountsi2.
 * Provide this GCC runtime helper only for IAR builds.  */

__root int __popcountsi2 (unsigned int value)
{
    value = value - ((value >> 1) & 0x55555555U);
    value = (value & 0x33333333U) + ((value >> 2) & 0x33333333U);
    value = (value + (value >> 4)) & 0x0F0F0F0FU;

    return (int) ((value * 0x01010101U) >> 24);
}

#endif
