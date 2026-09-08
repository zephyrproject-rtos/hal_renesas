/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RENESAS_TFU
#define RENESAS_TFU

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* Mathematical Functions includes. */
#ifdef __cplusplus
 #include <cmath>
#else
 #include <math.h>
 #if defined(__CCRX__)
  #include <mathf.h>
 #endif
#endif

#if defined(__ICCRX__)
 #include <intrinsics.h>
#endif

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

#if BSP_FEATURE_TFU_SUPPORTED

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
 #if defined(__CCRX__)
  #define sincosf         __sincosf
  #define atan2hypotf     __atan2hypotf
 #elif defined(__GNUC__)
  #define  sincosf        __builtin_rx_sincosf
  #define  atan2hypotf    __builtin_rx_atan2hypotf
 #elif defined(__ICCRX__)
 #endif

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Inline Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* RENESAS_TFU */
