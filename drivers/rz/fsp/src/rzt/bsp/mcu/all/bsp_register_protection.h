/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_REGISTER_PROTECTION_H
#define BSP_REGISTER_PROTECTION_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Key code for writing PRCR register. */
#define BSP_REG_PROTECT_PRCR_KEY          (0xA500U)

#define BSP_REG_PROTECT_PRCR_CGC          (0x0001U)
#define BSP_REG_PROTECT_PRCR_LPC_RESET    (0x0002U)
#define BSP_REG_PROTECT_PRCR_GPIO         (0x0004U)
#define BSP_REG_PROTECT_PRCR_SYSTEM       (0x0008U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZT
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_BSP_MCU
 * @{
 **********************************************************************************************************************/

/** The different types of registers that can be protected. */
typedef enum e_bsp_reg_protect
{
    /** Enables writing to the registers related to the clock generation circuit. */
    BSP_REG_PROTECT_CGC = 0,

    /** Enables writing to the registers related to low power consumption and reset. */
    BSP_REG_PROTECT_LPC_RESET,

    /** Enables writing to the registers related to GPIO. */
    BSP_REG_PROTECT_GPIO,

    /** Enables writing to the registers related to Non-Safety reg. */
    BSP_REG_PROTECT_SYSTEM,
} bsp_reg_protect_t;

/** @} (end addtogroup BSP_MCU) */
#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* Public functions defined in bsp.h */
void bsp_register_protect_open(void);  // Used internally by BSP

void bsp_regiser_protect_semaphore_take(uint16_t prcr_masks);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
