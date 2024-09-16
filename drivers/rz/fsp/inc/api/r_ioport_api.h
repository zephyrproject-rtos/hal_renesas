/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_INTERFACES
 * @defgroup IOPORT_API I/O Port Interface
 * @brief Interface  for accessing I/O ports and configuring I/O functionality.
 *
 * @section IOPORT_API_SUMMARY Summary
 * The IOPort shared interface provides the ability to access the IOPorts of a device at both bit and port level.
 * Port and pin direction can be changed.
 *
 * IOPORT Interface description: @ref IOPORT
 *
 * @{
 **********************************************************************************************************************/

#ifndef R_IOPORT_API_H
#define R_IOPORT_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Common error codes and definitions. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** IO port type used with ports */
typedef uint16_t ioport_size_t;        ///< IO port size on this device

/** PFS writing enable/disable. */
typedef enum e_ioport_pwpr
{
    IOPORT_PFS_WRITE_DISABLE = 0,      ///< Disable PFS write access
    IOPORT_PFS_WRITE_ENABLE  = 1       ///< Enable PFS write access
} ioport_pwpr_t;

/** Pin identifier and Pin Function Setting (PFS) value */
typedef struct st_ioport_pin_cfg
{
    uint32_t          pin_cfg;         ///< Pin PFS configuration - Use ioport_cfg_options_t parameters to configure
    bsp_io_port_pin_t pin;             ///< Pin identifier
} ioport_pin_cfg_t;

/** Multiple pin configuration data for loading into each GPIO register by R_IOPORT_Init()  */
typedef struct st_ioport_cfg
{
    uint16_t                 number_of_pins; ///< Number of pins for which there is configuration data
    ioport_pin_cfg_t const * p_pin_cfg_data; ///< Pin configuration data
    const void             * p_extend;       ///< Pointer to hardware extend configuration
} ioport_cfg_t;

/** IOPORT control block.  Allocate an instance specific control block to pass into the IOPORT API calls.
 * @par Implemented as
 * - ioport_instance_ctrl_t
 */
typedef void ioport_ctrl_t;

/** IOPort driver structure. IOPort functions implemented at the HAL layer will follow this API. */
typedef struct st_ioport_api
{
    /** Initialize internal driver data and initial pin configurations.  Called during startup.  Do
     * not call this API during runtime.  Use @ref ioport_api_t::pinsCfg for runtime reconfiguration of
     * multiple pins.
     * @par Implemented as
     * - @ref R_IOPORT_Open()
     * @param[in]  p_cfg                Pointer to pin configuration data array.
     */
    fsp_err_t (* open)(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);

    /** Close the API.
     * @par Implemented as
     * - @ref R_IOPORT_Close()
     *
     * @param[in]   p_ctrl  Pointer to control structure.
     **/
    fsp_err_t (* close)(ioport_ctrl_t * const p_ctrl);

    /** Configure multiple pins.
     * @par Implemented as
     * - @ref R_IOPORT_PinsCfg()
     * @param[in]  p_cfg                Pointer to pin configuration data array.
     */
    fsp_err_t (* pinsCfg)(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);

    /** Configure settings for an individual pin.
     * @par Implemented as
     * - @ref R_IOPORT_PinCfg()
     * @param[in]  pin                  Pin to be read.
     * @param[in]  cfg                  Configuration options for the pin.
     */
    fsp_err_t (* pinCfg)(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, uint32_t cfg);

    /** Read the event input data of the specified pin and return the level.
     * @par Implemented as
     * - @ref R_IOPORT_PinEventInputRead()
     * @param[in]  pin                  Pin to be read.
     * @param[in]  p_pin_event         Pointer to return the event data.
     */
    fsp_err_t (* pinEventInputRead)(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_event);

    /** Write pin event data.
     * @par Implemented as
     * - @ref R_IOPORT_PinEventOutputWrite()
     * @param[in]  pin                  Pin event data is to be written to.
     * @param[in]  pin_value            Level to be written to pin output event.
     */
    fsp_err_t (* pinEventOutputWrite)(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t pin_value);

    /** Read level of a pin.
     * @par Implemented as
     * - @ref R_IOPORT_PinRead()
     * @param[in]  pin                  Pin to be read.
     * @param[in]  p_pin_value          Pointer to return the pin level.
     */
    fsp_err_t (* pinRead)(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_value);

    /** Write specified level to a pin.
     * @par Implemented as
     * - @ref R_IOPORT_PinWrite()
     * @param[in]  pin                  Pin to be written to.
     * @param[in]  level                State to be written to the pin.
     */
    fsp_err_t (* pinWrite)(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t level);

    /** Set the direction of one or more pins on a port.
     * @par Implemented as
     * - @ref R_IOPORT_PortDirectionSet()
     * @param[in]  port                 Port being configured.
     * @param[in]  direction_values     Value controlling direction of pins on port
     *                                  (3 - output (input enable), 2 - output (input disable), 1 input, 0 - Hi-Z).
     * @param[in]  mask                 Mask controlling which pins on the port are to be configured.
     */
    fsp_err_t (* portDirectionSet)(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t direction_values,
                                   ioport_size_t mask);

    /** Read captured event data for a port.
     * @par Implemented as
     * - @ref R_IOPORT_PortEventInputRead()
     * @param[in]  port                 Port to be read.
     * @param[in]  p_event_data         Pointer to return the event data.
     */
    fsp_err_t (* portEventInputRead)(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_event_data);

    /** Write event output data for a port.
     * @par Implemented as
     * - @ref R_IOPORT_PortEventOutputWrite()
     * @param[in]  port                 Port event data will be written to.
     * @param[in]  event_data           Data to be written as event data to specified port.
     * @param[in]  mask_value           Each bit set to 1 in the mask corresponds to that bit's value in event data.
     * being written to port.
     */
    fsp_err_t (* portEventOutputWrite)(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t event_data,
                                       ioport_size_t mask_value);

    /** Read states of pins on the specified port.
     * @par Implemented as
     * - @ref R_IOPORT_PortRead()
     * @param[in]  port                 Port to be read.
     * @param[in]  p_port_value         Pointer to return the port value.
     */
    fsp_err_t (* portRead)(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_port_value);

    /** Write to multiple pins on a port.
     * @par Implemented as
     * - @ref R_IOPORT_PortWrite()
     * @param[in]  port                 Port to be written to.
     * @param[in]  value                Value to be written to the port.
     * @param[in]  mask                 Mask controlling which pins on the port are written to.
     */
    fsp_err_t (* portWrite)(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t value, ioport_size_t mask);
} ioport_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_ioport_instance
{
    ioport_ctrl_t      * p_ctrl;       ///< Pointer to the control structure for this instance
    ioport_cfg_t const * p_cfg;        ///< Pointer to the configuration structure for this instance
    ioport_api_t const * p_api;        ///< Pointer to the API structure for this instance
} ioport_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup IOPORT_API)
 **********************************************************************************************************************/
