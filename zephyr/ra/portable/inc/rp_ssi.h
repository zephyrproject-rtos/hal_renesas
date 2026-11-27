/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup SSI
 * @{
 **********************************************************************************************************************/

#ifndef RP_SSI_H
#define RP_SSI_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_i2s_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Audio format of the SSIE frame */
typedef enum e_rp_ssi_audio_format
{
    RP_SSI_AUDIO_FORMAT_I2S                  = 0, ///< I2S format, two words per frame
    RP_SSI_AUDIO_FORMAT_MONAURAL_SHORT_FRAME = 1, ///< Monaural format, one word per frame, one-cycle frame sync
    RP_SSI_AUDIO_FORMAT_MONAURAL_LONG_FRAME  = 2, ///< Monaural format, one word per frame, two-cycle frame sync
} rp_ssi_audio_format_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Prototypes
 **********************************************************************************************************************/

fsp_err_t RP_SSI_Open(i2s_ctrl_t * const p_ctrl, i2s_cfg_t const * const p_cfg, rp_ssi_audio_format_t format);
fsp_err_t RP_SSI_Write(i2s_ctrl_t * const p_ctrl, void const * const p_src, uint32_t const bytes);
fsp_err_t RP_SSI_Read(i2s_ctrl_t * const p_ctrl, void * const p_dest, uint32_t const bytes);
fsp_err_t RP_SSI_WriteRead(i2s_ctrl_t * const p_ctrl,
                           void const * const p_src,
                           void * const       p_dest,
                           uint32_t const     bytes);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // RP_SSI_H

/*******************************************************************************************************************//**
 * @} (end defgroup SSI)
 **********************************************************************************************************************/
