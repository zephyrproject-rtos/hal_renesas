/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_SYSTEM_INTERFACES
 * @defgroup IOPORT_API I/O Port Interface
 * @brief Interface  for accessing I/O ports and configuring I/O functionality.
 *
 * @section IOPORT_API_SUMMARY Summary
 * The IOPort shared interface provides the ability to access the IOPorts of a device at both bit and port level.
 * Port and pin direction can be changed.
 *
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

#ifndef BSP_OVERRIDE_IOPORT_FILTER_SIGNAL_T

/** Filter signal */
typedef enum e_ioport_filter_signal
{
    IOPORT_FILTER_SIGNAL_RLIN30RX = 0, ///< Select Enable Noise Filter RLIN30RX
    IOPORT_FILTER_SIGNAL_RLIN31RX,     ///< Select Enable Noise Filter RLIN31RX
    IOPORT_FILTER_SIGNAL_CAN0RX,       ///< Select Enable Noise Filter CAN0RX
    IOPORT_FILTER_SIGNAL_CAN1RX,       ///< Select Enable Noise Filter CAN1RX
    IOPORT_FILTER_SIGNAL_FLXA0RXDA,    ///< Select Enable Noise Filter FLXA0RXDA

    IOPORT_FILTER_SIGNAL_SENT0RX,      ///< Select Enable Noise Filter SENT0RX
    IOPORT_FILTER_SIGNAL_SENT1RX,      ///< Select Enable Noise Filter SENT1RX
    IOPORT_FILTER_SIGNAL_SENT2RX,      ///< Select Enable Noise Filter SENT2RX
    IOPORT_FILTER_SIGNAL_SENT3RX,      ///< Select Enable Noise Filter SENT3RX
    IOPORT_FILTER_SIGNAL_SENT4RX,      ///< Select Enable Noise Filter SENT4RX
    IOPORT_FILTER_SIGNAL_SENT5RX,      ///< Select Enable Noise Filter SENT5RX
    IOPORT_FILTER_SIGNAL_SENT6RX,      ///< Select Enable Noise Filter SENT6RX
    IOPORT_FILTER_SIGNAL_SENT7RX,      ///< Select Enable Noise Filter SENT7RX

    IOPORT_FILTER_SIGNAL_TAUD3I0,      ///< Select Enable Noise Filter TAUD3I0
    IOPORT_FILTER_SIGNAL_TAUD3I1,      ///< Select Enable Noise Filter TAUD3I1
    IOPORT_FILTER_SIGNAL_TAUD3I2,      ///< Select Enable Noise Filter TAUD3I2
    IOPORT_FILTER_SIGNAL_TAUD3I3,      ///< Select Enable Noise Filter TAUD3I3
    IOPORT_FILTER_SIGNAL_TAUD3I4,      ///< Select Enable Noise Filter TAUD3I4
    IOPORT_FILTER_SIGNAL_TAUD3I5,      ///< Select Enable Noise Filter TAUD3I5
    IOPORT_FILTER_SIGNAL_TAUD3I6,      ///< Select Enable Noise Filter TAUD3I6
    IOPORT_FILTER_SIGNAL_TAUD3I7,      ///< Select Enable Noise Filter TAUD3I7
    IOPORT_FILTER_SIGNAL_TAUD3I8,      ///< Select Enable Noise Filter TAUD3I8
    IOPORT_FILTER_SIGNAL_TAUD3I9,      ///< Select Enable Noise Filter TAUD3I9
    IOPORT_FILTER_SIGNAL_TAUD3I10,     ///< Select Enable Noise Filter TAUD3I10
    IOPORT_FILTER_SIGNAL_TAUD3I11,     ///< Select Enable Noise Filter TAUD3I11
    IOPORT_FILTER_SIGNAL_TAUD3I12,     ///< Select Enable Noise Filter TAUD3I12
    IOPORT_FILTER_SIGNAL_TAUD3I13,     ///< Select Enable Noise Filter TAUD3I13
    IOPORT_FILTER_SIGNAL_TAUD3I14,     ///< Select Enable Noise Filter TAUD3I14
    IOPORT_FILTER_SIGNAL_TAUD3I15,     ///< Select Enable Noise Filter TAUD3I15

    IOPORT_FILTER_SIGNAL_TSG30PTSI0,   ///< Select Enable Noise Filter TSG30PTSI0_ENCA0E0
    IOPORT_FILTER_SIGNAL_TSG30PTSI1,   ///< Select Enable Noise Filter TSG30PTSI1_ENCA0E1
    IOPORT_FILTER_SIGNAL_TSG30PTSI2,   ///< Select Enable Noise Filter TSG30PTSI2_ENCA0EC
    IOPORT_FILTER_SIGNAL_TSG30CLKI,    ///< Select Enable Noise Filter TSG30CLKI
    IOPORT_FILTER_SIGNAL_TSG31PTSI0,   ///< Select Enable Noise Filter TSG31PTSI0_ENCA1E0
    IOPORT_FILTER_SIGNAL_TSG31PTSI1,   ///< Select Enable Noise Filter TSG31PTSI1_ENCA1E1
    IOPORT_FILTER_SIGNAL_TSG31PTSI2,   ///< Select Enable Noise Filter TSG31PTSI2_ENCA1EC
    IOPORT_FILTER_SIGNAL_TSG31CLKI,    ///< Select Enable Noise Filter TSG31CLKI
    IOPORT_FILTER_SIGNAL_TSG32CLKI,    ///< Select Enable Noise Filter TSG32CLKI

    IOPORT_FILTER_SIGNAL_IRQ0,         ///< Select Enable Noise Filter IRQ0
    IOPORT_FILTER_SIGNAL_IRQ1,         ///< Select Enable Noise Filter IRQ1
    IOPORT_FILTER_SIGNAL_IRQ2,         ///< Select Enable Noise Filter IRQ2
    IOPORT_FILTER_SIGNAL_IRQ3,         ///< Select Enable Noise Filter IRQ3
    IOPORT_FILTER_SIGNAL_IRQ4,         ///< Select Enable Noise Filter IRQ4

    IOPORT_FILTER_SIGNAL_ESR0_IRQ0,    ///< Select Enable Noise Filter Interrupt
    IOPORT_FILTER_SIGNAL_ESR0_NMI,     ///< Select Enable Noise Filter Interrupt
    IOPORT_FILTER_SIGNAL_ESR1_NMI,     ///< Select Enable Noise Filter Interrupt

    IOPORT_FILTER_SIGNAL_ERRORIN0,     ///< Select Enable Noise Filter ERRORIN0
    IOPORT_FILTER_SIGNAL_ERRORIN1,     ///< Select Enable Noise Filter ERRORIN1
    IOPORT_FILTER_SIGNAL_ERRORIN2,     ///< Select Enable Noise Filter ERRORIN2
    IOPORT_FILTER_SIGNAL_ERRORIN3,     ///< Select Enable Noise Filter ERRORIN3
    IOPORT_FILTER_SIGNAL_ERRORIN4,     ///< Select Enable Noise Filter ERRORIN4
    IOPORT_FILTER_SIGNAL_ERRORIN5,     ///< Select Enable Noise Filter ERRORIN5
    IOPORT_FILTER_SIGNAL_ERRORIN6,     ///< Select Enable Noise Filter ERRORIN6
    IOPORT_FILTER_SIGNAL_ERRORIN7,     ///< Select Enable Noise Filter ERRORIN7

    IOPORT_FILTER_SIGNAL_TAUJ0I0,      ///< Select Enable Noise Filter TAUJ0I0
    IOPORT_FILTER_SIGNAL_TAUJ0I1,      ///< Select Enable Noise Filter TAUJ0I1
    IOPORT_FILTER_SIGNAL_TAUJ0I2,      ///< Select Enable Noise Filter TAUJ0I2
    IOPORT_FILTER_SIGNAL_TAUJ0I3,      ///< Select Enable Noise Filter TAUJ0I3

    IOPORT_FILTER_SIGNAL_TAUJ1I0,      ///< Select Enable Noise Filter TAUJ1I0
    IOPORT_FILTER_SIGNAL_TAUJ1I1,      ///< Select Enable Noise Filter TAUJ1I1
    IOPORT_FILTER_SIGNAL_TAUJ1I2,      ///< Select Enable Noise Filter TAUJ1I2
    IOPORT_FILTER_SIGNAL_TAUJ1I3,      ///< Select Enable Noise Filter TAUJ1I3

    IOPORT_FILTER_SIGNAL_TAUJ2I0,      ///< Select Enable Noise Filter TAUJ2I0
    IOPORT_FILTER_SIGNAL_TAUJ2I1,      ///< Select Enable Noise Filter TAUJ2I1
    IOPORT_FILTER_SIGNAL_TAUJ2I2,      ///< Select Enable Noise Filter TAUJ2I2
    IOPORT_FILTER_SIGNAL_TAUJ2I3,      ///< Select Enable Noise Filter TAUJ2I3

    IOPORT_FILTER_SIGNAL_TAUJ3I0,      ///< Select Enable Noise Filter TAUJ3I0
    IOPORT_FILTER_SIGNAL_TAUJ3I1,      ///< Select Enable Noise Filter TAUJ3I1
    IOPORT_FILTER_SIGNAL_TAUJ3I2,      ///< Select Enable Noise Filter TAUJ3I2
    IOPORT_FILTER_SIGNAL_TAUJ3I3,      ///< Select Enable Noise Filter TAUJ3I3

    IOPORT_FILTER_SIGNAL_TSGTRG,       ///< Select Enable Noise Filter TSGTRG

    IOPORT_FILTER_SIGNAL_EM00_IN_A,    ///< Select Enable Noise Filter EM00_IN_A
    IOPORT_FILTER_SIGNAL_EM00_IN_B,    ///< Select Enable Noise Filter EM00_IN_B
    IOPORT_FILTER_SIGNAL_EM00_IN_Z,    ///< Select Enable Noise Filter EM00_IN_Z
    IOPORT_FILTER_SIGNAL_EM10_IN_A,    ///< Select Enable Noise Filter EM10_IN_A
    IOPORT_FILTER_SIGNAL_EM10_IN_B,    ///< Select Enable Noise Filter EM10_IN_B
    IOPORT_FILTER_SIGNAL_EM10_IN_Z,    ///< Select Enable Noise Filter EM10_IN_Z
    IOPORT_FILTER_SIGNAL_SSIF0BCK,     ///< Select Enable Noise Filter SSIF0BCK
    IOPORT_FILTER_SIGNAL_SSIF0LRCK_FS, ///< Select Enable Noise Filter SSIF0LRCK_FS
    IOPORT_FILTER_SIGNAL_SSIF0RXD,     ///< Select Enable Noise Filter SSIF0RXD
    IOPORT_FILTER_SIGNAL_SSIFACK,      ///< Select Enable Noise Filter SSIFACK
    IOPORT_FILTER_SIGNAL_SSIF1BCK,     ///< Select Enable Noise Filter SSIF1BCK
    IOPORT_FILTER_SIGNAL_SSIF1LRCK_FS, ///< Select Enable Noise Filter SSIF1LRCK_FS
    IOPORT_FILTER_SIGNAL_SSIF1RXD,     ///< Select Enable Noise Filter SSIF1RXD

    IOPORT_FILTER_SIGNAL_OSPI0INT0,    ///< Select Enable Noise Filter OSPI0INT0
    IOPORT_FILTER_SIGNAL_OSPI0INT1,    ///< Select Enable Noise Filter OSPI0INT1
    IOPORT_FILTER_SIGNAL_OSPI0ECS0,    ///< Select Enable Noise Filter OSPI0ECS0
    IOPORT_FILTER_SIGNAL_OSPI0ECS1    ///< Select Enable Noise Filter OSPI0ECS1
} ioport_filter_signal_t;
#endif

/** Number of samples */
typedef enum e_ioport_filter_sample
{
    IOPORT_FILTER_SAMPLE_2 = 0x0,      ///< Select 2 Number Samples
    IOPORT_FILTER_SAMPLE_3 = 0x1,      ///< Select 3 Number Samples
    IOPORT_FILTER_SAMPLE_4 = 0x2,      ///< Select 4 Number Samples
    IOPORT_FILTER_SAMPLE_5 = 0x3       ///< Select 5 Number Samples
} ioport_filter_sample_t;

/** Sampling clock Frequency */
typedef enum e_ioport_filter_clock_div
{
    IOPORT_FILTER_CLOCK_DIV_1   = 0x0, ///< Sampling Clock Supply Divide 1
    IOPORT_FILTER_CLOCK_DIV_2   = 0x1, ///< Sampling Clock Supply Divide 2
    IOPORT_FILTER_CLOCK_DIV_4   = 0x2, ///< Sampling Clock Supply Divide 4
    IOPORT_FILTER_CLOCK_DIV_8   = 0x3, ///< Sampling Clock Supply Divide 8
    IOPORT_FILTER_CLOCK_DIV_16  = 0x4, ///< Sampling Clock Supply Divide 16
    IOPORT_FILTER_CLOCK_DIV_32  = 0x5, ///< Sampling Clock Supply Divide 32
    IOPORT_FILTER_CLOCK_DIV_64  = 0x6, ///< Sampling Clock Supply Divide 64
    IOPORT_FILTER_CLOCK_DIV_128 = 0x7  ///< Sampling Clock Supply Divide 128
} ioport_filter_clock_div_t;

/** Sampling clock Frequency */
typedef enum e_ioport_filter_detection
{
    IOPORT_FILTER_DETECTION_DISABLE_EDGE                 = 0x0, ///< Disable edge detection
    IOPORT_FILTER_DETECTION_RISING_EDGE                  = 0x1, ///< Rising edge detection
    IOPORT_FILTER_DETECTION_FALLING_EDGE                 = 0x2, ///< Falling edge detection
    IOPORT_FILTER_DETECTION_BOTH_RISING_AND_FALLING_EDGE = 0x3, ///< Both rising and falling edge detection
    IOPORT_FILTER_DETECTION_LOW_LEVEL  = 0x4,                   ///< Low level detection
    IOPORT_FILTER_DETECTION_HIGH_LEVEL = 0x5                    ///< High level detection
} ioport_filter_detection_t;

/** Bypass mode selection */
typedef enum e_ioport_filter_select
{
    IOPORT_FILTER_SELECT_SIGNAL        = 0x0, ///< Select filter signal
    IOPORT_FILTER_SELECT_BYPASS_SIGNAL = 0x1  ///< Select filter-bypass signal
} ioport_filter_select_t;

/** IOPORT DNF extend configuration
 */
typedef struct st_ioport_filter_cfg
{
    ioport_filter_sample_t    number_sample;  ///< Number of samples
    ioport_filter_clock_div_t sampling_clock; ///< Sampling clock Frequency
    ioport_filter_detection_t detection_mode; ///< Sampling clock Frequency
    ioport_filter_select_t    bypass_mode;    ///< Bypass mode selection
} ioport_filter_cfg_t;

#ifndef BSP_OVERRIDE_IOPORT_SIZE_T

/** IO port type used with ports */
typedef uint16_t ioport_size_t;        ///< IO port size
#endif

/** Pin identifier and pin configuration value */
typedef struct st_ioport_pin_cfg
{
    uint32_t          pin_cfg;         ///< Pin configuration - Use ioport_cfg_options_t parameters to configure
    bsp_io_port_pin_t pin;             ///< Pin identifier
} ioport_pin_cfg_t;

/** Multiple pin configuration data for loading into registers by R_IOPORT_Open() */
typedef struct st_ioport_cfg
{
    uint16_t                 number_of_pins; ///< Number of pins for which there is configuration data
    ioport_pin_cfg_t const * p_pin_cfg_data; ///< Pin configuration data
    const void             * p_extend;       ///< Pointer to hardware extend configuration
} ioport_cfg_t;

/** IOPORT control block.  Allocate an instance specific control block to pass into the IOPORT API calls.
 */
typedef void ioport_ctrl_t;

/** IOPort driver structure. IOPort functions implemented at the HAL layer will follow this API. */
typedef struct st_ioport_api
{
    /** Initialize internal driver data and initial pin configurations.  Called during startup.  Do
     * not call this API during runtime.  Use @ref ioport_api_t::pinsCfg for runtime reconfiguration of
     * multiple pins.
     *
     * @param[in]      p_ctrl     Pointer to control structure. Must be declared by user. Elements set here.
     * @param[in]      p_cfg      Pointer to pin configuration data array.
     */
    fsp_err_t (* open)(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);

    /**
     *
     * @param[in]      p_ctrl            Pointer to control structure. Must be declared by user. Elements set here.
     * @param[in]      filter_signal     Index of filter signal.
     */
    fsp_err_t (* noiseFilterEnable)(ioport_ctrl_t * const p_ctrl, ioport_filter_signal_t filter_signal);

    /**
     *
     * @param[in]      p_ctrl            Pointer to control structure. Must be declared by user. Elements set here.
     * @param[in]      filter_signal     Index of filter signal.
     */
    fsp_err_t (* noiseFilterDisable)(ioport_ctrl_t * const p_ctrl, ioport_filter_signal_t filter_signal);

    /**
     *
     * @param[in]      p_ctrl            Pointer to control structure. Must be declared by user. Elements set here.
     * @param[in]      filter_signal     Index of filter signal.
     * @param[in]      p_filter_cfg      Pointer to pin configuration data array.
     */
    fsp_err_t (* noiseFilterCfg)(ioport_ctrl_t * const p_ctrl, ioport_filter_signal_t filter_signal,
                                 const ioport_filter_cfg_t * p_filter_cfg);

    /** Close the API.
     *
     * @param[in]   p_ctrl  Pointer to control structure.
     **/
    fsp_err_t (* close)(ioport_ctrl_t * const p_ctrl);

    /** Configure multiple pins.
     *
     * @param[in]  p_ctrl     Pointer to control structure.
     * @param[in]  p_cfg      Pointer to pin configuration data array.
     */
    fsp_err_t (* pinsCfg)(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);

    /** Configure settings for an individual pin.
     *
     * @param[in]  p_ctrl               Pointer to control structure.
     * @param[in]  pin                  Pin to be read.
     * @param[in]  cfg                  Configuration options for the pin.
     */
    fsp_err_t (* pinCfg)(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, uint32_t cfg);

    /** Read the event input data of the specified pin and return the level.
     *
     * @param[in]  p_ctrl              Pointer to control structure.
     * @param[in]  pin                 Pin to be read.
     * @param[in]  p_pin_event         Pointer to return the event data.
     */
    fsp_err_t (* pinEventInputRead)(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_event);

    /** Write pin event data.
     *
     * @param[in]  p_ctrl               Pointer to control structure.
     * @param[in]  pin                  Pin event data is to be written to.
     * @param[in]  pin_value            Level to be written to pin output event.
     */
    fsp_err_t (* pinEventOutputWrite)(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t pin_value);

    /** Read level of a pin.
     *
     * @param[in]  p_ctrl               Pointer to control structure.
     * @param[in]  pin                  Pin to be read.
     * @param[in]  p_pin_value          Pointer to return the pin level.
     */
    fsp_err_t (* pinRead)(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_value);

    /** Write specified level to a pin.
     *
     * @param[in]  p_ctrl               Pointer to control structure.
     * @param[in]  pin                  Pin to be written to.
     * @param[in]  level                State to be written to the pin.
     */
    fsp_err_t (* pinWrite)(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t level);

    /** Set the direction of one or more pins on a port.
     *
     * @param[in]  p_ctrl               Pointer to control structure.
     * @param[in]  port                 Port being configured.
     * @param[in]  direction_values     Value controlling direction of pins on port.
     * @param[in]  mask                 Mask controlling which pins on the port are to be configured.
     */
    fsp_err_t (* portDirectionSet)(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t direction_values,
                                   ioport_size_t mask);

    /** Read captured event data for a port.
     *
     * @param[in]  p_ctrl               Pointer to control structure.
     * @param[in]  port                 Port to be read.
     * @param[in]  p_event_data         Pointer to return the event data.
     */
    fsp_err_t (* portEventInputRead)(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_event_data);

    /** Write event output data for a port.
     *
     * @param[in]  p_ctrl               Pointer to control structure.
     * @param[in]  port                 Port event data will be written to.
     * @param[in]  event_data           Data to be written as event data to specified port.
     * @param[in]  mask_value           Each bit set to 1 in the mask corresponds to that bit's value in event data.
     * being written to port.
     */
    fsp_err_t (* portEventOutputWrite)(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t event_data,
                                       ioport_size_t mask_value);

    /** Read states of pins on the specified port.
     *
     * @param[in]  p_ctrl               Pointer to control structure.
     * @param[in]  port                 Port to be read.
     * @param[in]  p_port_value         Pointer to return the port value.
     */
    fsp_err_t (* portRead)(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_port_value);

    /** Write to multiple pins on a port.
     *
     * @param[in]  p_ctrl               Pointer to control structure.
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
