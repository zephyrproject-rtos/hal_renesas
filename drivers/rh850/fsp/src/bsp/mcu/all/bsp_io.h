/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IO_H
#define BSP_IO_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_io_device.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_IO BSP I/O access
 * @brief This module provides basic read/write access to port pins.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Shift to get port in bsp_io_port_t and bsp_io_port_pin_t enums. */
#define BSP_IO_PORT_GROUP_POS              (8UL)                                                     ///< Bit position of port group field
#define BSP_IO_PORT_TYPE_POS               (16UL)                                                    ///< Bit position of port type field
#define BSP_IO_PORT_PWE_POS                (24UL)                                                    ///< Bit position of PWE (Port Write Enable) field

#define BSP_IO_PORT_PWE_MASK               (0xFF000000UL)                                            ///< Mask for PWE bits (31..24)
#define BSP_IO_PORT_TYPE_MASK              (0x00FF0000UL)                                            ///< Mask for port type bits (23..16)
#define BSP_IO_PORT_GROUP_MASK             (0x0000FF00UL)                                            ///< Mask for port group/index bits (15..8)
#define BSP_IO_PORT_PIN_MASK               (0x000000FFUL)                                            ///< Mask for port pin number bits (7..0)

#define BSP_IO_SR_MASK_POS                 (16UL)                                                    ///< Bit position used when forming SR masks
#define BSP_IO_PORT_PWE_UNSED              (0xFFUL)                                                  ///< PWE unused value (all bits set to 1)

#define BSP_IO_PORT_KEYCODE_ENABLE         0xA5A5A501U                                               ///< Keycode required to enable protected port write access
#define BSP_IO_PORT_KEYCODE_DISABLE        0xA5A5A500U                                               ///< Keycode required to disable protected port write access
#define BSP_IO_PORT_PCR_MASK               (0x5B5F117FU)                                             ///< PCR mask reserved bit

#define R_BSP_PORT                         R_PORT                                                    ///< Alias mapping BSP PORT handle to hardware PORT instance

#define BSP_IO_PORT_PINCFG_ENABLE          (1U)                                                      ///< Pin configuration enable
#define BSP_IO_PORT_PINCFG_DISABLE         (0U)                                                      ///< Pin configuration disable
#define BSP_IO_PORT_PINCFG_PSFTS_MASK      ((uint32_t) 1U << 13U)                                    ///< PSFTS value mask
#define BSP_IO_PORT_PINCFG_PSFTSE_MASK     ((uint32_t) 1U << 14U)                                    ///< PSFTSE value mask
#define BSP_IO_PORT_PINCFG_PSFTSAE_MASK    ((uint32_t) 1U << 15U) /* PRQA S 1534 # Advisory R-2.5 */ ///< PSFTSAE value mask
#define BSP_IO_PORT_PINCFG_PSFC_MASK       ((uint32_t) 1U << 21U)                                    ///< PSFC value mask
#define BSP_IO_PORT_PINCFG_PEIODC_MASK     ((uint32_t) 1U << 23U)                                    ///< PEIODC value mask

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Levels that can be set and read for individual pins */
typedef enum e_bsp_io_level             /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_IO_LEVEL_LOW = 0,               ///< Port Level Low
    BSP_IO_LEVEL_HIGH                   ///< Port Level High
} bsp_io_level_t;

/** Direction of individual pins */
typedef enum e_bsp_io_direction         /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_IO_DIRECTION_INPUT  = 1,        ///< Input
    BSP_IO_DIRECTION_OUTPUT = 0         ///< Output
} bsp_io_direction_t;                   /* PRQA S 1535 # Advisory R-2.3 */

/** Available Port type */
typedef enum e_bsp_io_port_type         /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_IO_PORT_TYPE_PORT  = 0x000000,  ///< IO port type Port
    BSP_IO_PORT_TYPE_JPORT = 0x010000,  ///< IO port type JPort
    BSP_IO_PORT_TYPE_APORT = 0x020000,  ///< IO port type APort
} bsp_io_port_type_t;                   /* PRQA S 1535 # Advisory R-2.3 */

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

extern R_PORT_Type * R_BSP_PORT_TYPE[]; /* PRQA S 3684 # Advisory R-8.11 */

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable access to the selected port registers. Unlock PWE register protect by using R_BSP_PinAccessEnable
 * before calling this function.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PortWriteEnable (bsp_io_port_t port)
{
    uint32_t pwe_pos = ((uint32_t) port & BSP_IO_PORT_PWE_MASK) >> BSP_IO_PORT_PWE_POS;

    if (BSP_IO_PORT_PWE_UNSED != pwe_pos)
    {
        R_BSP_PORT->PWE = R_BSP_PORT->PWE | ((uint32_t) 1U << pwe_pos); /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }
}

/*******************************************************************************************************************//**
 * Disable writing to the PWE registers. Unlock PWE register protect by using R_BSP_PinAccessEnable
 * before calling this function.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PortWriteDisable (bsp_io_port_t port)
{
    uint32_t pwe_pos = ((uint32_t) port & BSP_IO_PORT_PWE_MASK) >> BSP_IO_PORT_PWE_POS;

    if (BSP_IO_PORT_PWE_UNSED != pwe_pos)
    {
        R_BSP_PORT->PWE = R_BSP_PORT->PWE & ~((uint32_t) 1U << pwe_pos); /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }
}

/*******************************************************************************************************************//**
 * Enable access to the PWE registers.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinAccessEnable (void)
{
    R_BSP_PORT->PKCPROT = BSP_IO_PORT_KEYCODE_ENABLE; /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * Disable access to the PWE registers.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinAccessDisable (void)
{
    R_BSP_PORT->PKCPROT = BSP_IO_PORT_KEYCODE_DISABLE; /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * Read the current input level of the pin. Pin must be a valid pin before calling this function
 *
 * @param[in]  pin             The pin
 *
 * @retval     Current input level
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_PinRead (bsp_io_port_pin_t pin)
{
    uint32_t level      = 0U;
    uint32_t port_type  = ((uint32_t) pin & BSP_IO_PORT_TYPE_MASK) >> BSP_IO_PORT_TYPE_POS;
    uint32_t port_group = ((uint32_t) pin & BSP_IO_PORT_GROUP_MASK);
    uint32_t port_pin   = (uint32_t) pin & BSP_IO_PORT_PIN_MASK;

    if ((port_type < BSP_IO_PORT_TYPE_MAX) && (NULL != R_BSP_PORT_TYPE[port_type]))
    {
        level = R_BSP_PORT_TYPE[port_type]->PCRn_m[port_group >> BSP_IO_PORT_GROUP_POS].PCR_b[port_pin].PPR; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }

    return level;
}

/*******************************************************************************************************************//**
 * Set the output level to the level provided. Disable port write
 * protection using R_BSP_PortWriteEnable() before calling this function.
 *
 * @param[in]  pin      The pin to write
 * @param[in]  level    The level
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinWrite (bsp_io_port_pin_t pin, bsp_io_level_t level)
{
    uint32_t port_type  = ((uint32_t) pin & BSP_IO_PORT_TYPE_MASK) >> BSP_IO_PORT_TYPE_POS;
    uint32_t port_group = (uint32_t) pin & BSP_IO_PORT_GROUP_MASK;
    uint32_t port_pin   = (uint32_t) pin & BSP_IO_PORT_PIN_MASK;

    if (port_type >= BSP_IO_PORT_TYPE_MAX)
    {
        return;
    }

    if (NULL != R_BSP_PORT_TYPE[port_type])
    {
        R_BSP_PORT_TYPE[port_type]->PORT_CTR[port_group >>
                                             BSP_IO_PORT_GROUP_POS].PSR = /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                          ((uint32_t) 1U <<
                                                                           (BSP_IO_SR_MASK_POS + port_pin)) |
                                                                          ((uint32_t) level << port_pin);
    }
}

/*******************************************************************************************************************//**
 * Toggle the level of the provided pin. Disable port write
 * protection using R_BSP_PortWriteEnable() before calling this function.
 *
 * @param[in]  pin      The pin to write
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinToggle (bsp_io_port_pin_t pin)
{
    uint32_t port_type  = ((uint32_t) pin & BSP_IO_PORT_TYPE_MASK) >> BSP_IO_PORT_TYPE_POS;
    uint32_t port_group = (uint32_t) pin & BSP_IO_PORT_GROUP_MASK;
    uint32_t port_pin   = (uint32_t) pin & BSP_IO_PORT_PIN_MASK;

    if (port_type >= BSP_IO_PORT_TYPE_MAX)
    {
        return;
    }

    if (NULL != R_BSP_PORT_TYPE[port_type])
    {
        R_BSP_PORT_TYPE[port_type]->PORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PNOT = ((uint16_t) 1U << port_pin); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }
}

/*******************************************************************************************************************//**
 * Configure a pin. Disable port write protection by using R_BSP_PortWriteEnable() before calling
 * this function.
 *
 * @param[in]  pin      The pin to be configured
 * @param[in]  cfg      Configuration for the pin (PCRm_n register setting)
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinCfg (bsp_io_port_pin_t pin, uint32_t cfg)
{
    uint32_t port_type  = ((uint32_t) pin & BSP_IO_PORT_TYPE_MASK) >> BSP_IO_PORT_TYPE_POS;
    uint32_t port_group = (uint32_t) pin & BSP_IO_PORT_GROUP_MASK;
    uint32_t port_pin   = (uint32_t) pin & BSP_IO_PORT_PIN_MASK;

    if (port_type >= BSP_IO_PORT_TYPE_MAX)
    {
        return;
    }

    if (NULL != R_BSP_PORT_TYPE[port_type])
    {
        R_BSP_PORT_TYPE[port_type]->PCRn_m[port_group >>
                                           BSP_IO_PORT_GROUP_POS].PCR[port_pin] = (cfg & BSP_IO_PORT_PCR_MASK); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* If Port Safe State Enable */
        if (BSP_IO_PORT_PINCFG_DISABLE != (cfg & BSP_IO_PORT_PINCFG_PSFC_MASK))
        {
            if (0U != (cfg & BSP_IO_PORT_PINCFG_PSFTS_MASK))
            {
                /* Write 1 to PSFTSn_m */
                R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                     BSP_IO_PORT_GROUP_POS].PSFTS |= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                     ((uint16_t)
                                                                                      BSP_IO_PORT_PINCFG_ENABLE <<
                                                                                      port_pin);
            }
            else
            {
                /* Write 0 to PSFTSn_m */
                R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                     BSP_IO_PORT_GROUP_POS].PSFTS &= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                     ~((uint16_t)
                                                                                       BSP_IO_PORT_PINCFG_ENABLE <<
                                                                                       port_pin);
            }

            if (0U != (cfg & BSP_IO_PORT_PINCFG_PSFTSE_MASK))
            {
                /* Write 1 to PSFTSEn_m */
                R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                     BSP_IO_PORT_GROUP_POS].PSFTSE |= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                      ((uint16_t)
                                                                                       BSP_IO_PORT_PINCFG_ENABLE <<
                                                                                       port_pin);
            }
            else
            {
                /* Write 0 to PSFTSEn_m */
                R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                     BSP_IO_PORT_GROUP_POS].PSFTSE &= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                      ~((uint16_t)
                                                                                        BSP_IO_PORT_PINCFG_ENABLE <<
                                                                                        port_pin);
            }

#if BSP_FEATURE_IOPORT_PST > 3
            if (0U != (cfg & BSP_IO_PORT_PINCFG_PSFTSAE_MASK))
            {
                /* Write 1 to PSFTSAEn_m */
                R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                     BSP_IO_PORT_GROUP_POS].PSFTSAE |= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                       ((uint16_t)
                                                                                        BSP_IO_PORT_PINCFG_ENABLE <<
                                                                                        port_pin);
            }
            else
            {
                /* Write 0 to PSFTSAEn_m */
                R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                     BSP_IO_PORT_GROUP_POS].PSFTSAE &= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                       ~((uint16_t)
                                                                                         BSP_IO_PORT_PINCFG_ENABLE <<
                                                                                         port_pin);
            }
#endif

            if (0U != (cfg & BSP_IO_PORT_PINCFG_PSFC_MASK))
            {
                /* Write 1 to PSFCn_m */
                R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                     BSP_IO_PORT_GROUP_POS].PSFC |= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                    ((uint16_t)
                                                                                     BSP_IO_PORT_PINCFG_ENABLE <<
                                                                                     port_pin);
            }
            else
            {
                /* Write 0 to PSFCn_m */
                R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                     BSP_IO_PORT_GROUP_POS].PSFC &= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                    ~((uint16_t)
                                                                                      BSP_IO_PORT_PINCFG_ENABLE <<
                                                                                      port_pin);
            }

#if BSP_FEATURE_IOPORT_PEIODC
            if ((0U != (cfg & BSP_IO_PORT_PINCFG_PEIODC_MASK)) && (0U != (cfg & BSP_IO_PORT_PINCFG_PSFC_MASK)))
            {
                /* Write 1 to PEIODCn_m */
                R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                     BSP_IO_PORT_GROUP_POS].PEIODC |= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                      ((uint16_t)
                                                                                       BSP_IO_PORT_PINCFG_ENABLE <<
                                                                                       port_pin);
            }
            else
            {
                /* Write 0 to PEIODCn_m */
                R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                     BSP_IO_PORT_GROUP_POS].PEIODC &= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                      ~((uint16_t)
                                                                                        BSP_IO_PORT_PINCFG_ENABLE <<
                                                                                        port_pin);
            }
#endif
        }
        else
        {
            /* Disable Port Safe State */
            R_BSP_PORT_TYPE[port_type]->PORT_SFT[port_group >>
                                                 BSP_IO_PORT_GROUP_POS].PSFC &= /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                                                ~((uint16_t) BSP_IO_PORT_PINCFG_ENABLE
                                                                                  <<
                                                                                  port_pin);
        }
    }
}

/** @} (end addtogroup BSP_IO) */

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_IO_H */
