/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_SECURITY_H
#define BSP_SECURITY_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void R_BSP_NonSecureEnter(void);
void R_BSP_RegisterProtectDisable (bsp_reg_protect_t regs_to_unprotect);
void R_BSP_RegisterProtectEnable (bsp_reg_protect_t regs_to_protect);

/*******************************************************************************************************************//**
 * Initialize security features for TrustZone.
 *
 * This function initializes ARM security register and Renesas SAR registers for secure projects.
 *
 * @note IDAU settings must be configured to match project settings with a separate configuration tool.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_SecurityInit (void)
{
#if FSP_PRIV_TZ_USE_SECURE_REGS
	/* Disable protection using PRCR register. */
	R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SAR);

	/* Initialize peripherals to secure mode for flat projects */
	R_PSCU->PSARB = 0;
	R_PSCU->PSARC = 0;
	R_PSCU->PSARD = 0;
	R_PSCU->PSARE = 0;

	R_CPSCU->ICUSARG = 0;
	R_CPSCU->ICUSARH = 0;
	R_CPSCU->ICUSARI = 0;

	/* Enable protection using PRCR register. */
	R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SAR);
#endif
}

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
