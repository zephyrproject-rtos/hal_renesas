/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>
#include "bsp_api.h"
#include "r_ioport.h"
#include "r_ioport_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "PORT" in ASCII, used to determine if the module is open */
#define IOPORT_OPEN                       (0x504F5254U)
#define IOPORT_CLOSED                     (0x00000000U)

/* Shift to get pin 0 on a package in extended data. */
#define IOPORT_PRV_EXISTS_B0_SHIFT        (16UL)

/* Mask to determine if any pins on port exist on this package. */
#define IOPORT_PRV_PORT_EXISTS_MASK       (0xFFFF0000U)

/* Shift to get port in bsp_io_port_t and bsp_io_port_pin_t enums. */
#define IOPORT_PRV_PORT_OFFSET            (8U)

#define IOPORT_PRV_PORT_BITS              (0xFF00U)
#define IOPORT_PRV_PIN_BITS               (0x00FFU)

/* Macro definition for generating the values to set for each register from the ioport_cfg_options_t enums. */
#define IOPORT_PRV_P_OFFSET               (0U)
#define IOPORT_PRV_PM_OFFSET              (2U)
#define IOPORT_PRV_PUPD_OFFSET            (4U)
#define IOPORT_PRV_IOLH_OFFSET            (10U)
#define IOPORT_PRV_ISEL_OFFSET            (14U)
#define IOPORT_PRV_PMC_OFFSET             (16U)
#define IOPORT_PRV_SR_OFFSET              (17U)
#define IOPORT_PRV_IEN_OFFSET             (18U)
#define IOPORT_PRV_FILONOFF_OFFSET        (19U)
#define IOPORT_PRV_FILNUM_OFFSET          (20U)
#define IOPORT_PRV_FILCLKSEL_OFFSET       (22U)
#define IOPORT_PRV_PFC_OFFSET             (24U)

#define IOPORT_PRV_ELC_PEL_MASK           (0x80)
#define IOOPRT_PRV_ELC_PGC_MASK           (0x88)
#define IOPORT_PRV_ELC_PEL_PSM_HIGH       (0x20)

#define IOPORT_PRV_PERIPHERAL_FUNCTION    (1U << 16)

#define IOPORT_PRV_2BIT_MASK              (0x3U)
#define IOPORT_PRV_8BIT_MASK              (0xFFU)

#define IOPORT_PRV_BITFIELD_1BIT          (1U)
#define IOPORT_PRV_BITFIELD_2BIT          (3U)
#define IOPORT_PRV_BITFIELD_3BIT          (7U)

#define IOPORT_PRV_POS_ALIGN_2BIT         (2U)
#define IOPORT_PRV_POS_ALIGN_4BIT         (4U)
#define IOPORT_PRV_POS_ALIGN_8BIT         (8U)

#define IOPORT_PRV_SET_PWPR_PFSWE         (0x40U)
#define IOPORT_PRV_SET_PWPR_BOWI          (0x80U)

#define IOPORT_PRV_NONMASK_ACCESS         (0xFFFFFFFFUL)

#define IOPORT_PRV_P_REG_BASE_SET(base)                     IOPORT_PRV_P_REG_BASE(base)
#define IOPORT_PRV_P_REG_BASE(base)                         (&R_GPIO->P ## base)
#define IOPORT_PRV_PM_REG_BASE_SET(base)                    IOPORT_PRV_PM_REG_BASE(base)
#define IOPORT_PRV_PM_REG_BASE(base)                        (&R_GPIO->PM ## base)
#define IOPORT_PRV_PMC_REG_BASE_SET(base)                   IOPORT_PRV_PMC_REG_BASE(base)
#define IOPORT_PRV_PMC_REG_BASE(base)                       (&R_GPIO->PMC ## base)
#define IOPORT_PRV_PFC_REG_BASE_SET(base)                   IOPORT_PRV_PFC_REG_BASE(base)
#define IOPORT_PRV_PFC_REG_BASE(base)                       (&R_GPIO->PFC ## base)
#define IOPORT_PRV_PIN_REG_BASE_SET(base)                   IOPORT_PRV_PIN_REG_BASE(base)
#define IOPORT_PRV_PIN_REG_BASE(base)                       (&R_GPIO->PIN ## base)
#define IOPORT_PRV_IEN_REG_BASE_SET(base, postfix)          IOPORT_PRV_IEN_REG_BASE(base, postfix)
#define IOPORT_PRV_IEN_REG_BASE(base, postfix)              (&R_GPIO->IEN ## base ## postfix)
#define IOPORT_PRV_ISEL_REG_BASE_SET(base, postfix)         IOPORT_PRV_ISEL_REG_BASE(base, postfix)
#define IOPORT_PRV_ISEL_REG_BASE(base, postfix)             (&R_GPIO->ISEL ## base ## postfix)
#define IOPORT_PRV_IOLH_REG_BASE_SET(base, postfix)         IOPORT_PRV_IOLH_REG_BASE(base, postfix)
#define IOPORT_PRV_IOLH_REG_BASE(base, postfix)             (&R_GPIO->IOLH ## base ## postfix)
#define IOPORT_PRV_SR_REG_BASE_SET(base, postfix)           IOPORT_PRV_SR_REG_BASE(base, postfix)
#define IOPORT_PRV_SR_REG_BASE(base, postfix)               (&R_GPIO->SR ## base ## postfix)
#define IOPORT_PRV_PUPD_REG_BASE_SET(base, postfix)         IOPORT_PRV_PUPD_REG_BASE(base, postfix)
#define IOPORT_PRV_PUPD_REG_BASE(base, postfix)             (&R_GPIO->PUPD ## base ## postfix)
#define IOPORT_PRV_FILONOFF_REG_BASE_SET(base, postfix)     IOPORT_PRV_FILONOFF_REG_BASE(base, postfix)
#define IOPORT_PRV_FILONOFF_REG_BASE(base, postfix)         (&R_GPIO->FILONOFF ## base ## postfix)
#define IOPORT_PRV_FILNUM_REG_BASE_SET(base, postfix)       IOPORT_PRV_FILNUM_REG_BASE(base, postfix)
#define IOPORT_PRV_FILNUM_REG_BASE(base, postfix)           (&R_GPIO->FILNUM ## base ## postfix)
#define IOPORT_PRV_FILCLKSEL_REG_BASE_SET(base, postfix)    IOPORT_PRV_FILCLKSEL_REG_BASE(base, postfix)
#define IOPORT_PRV_FILCLKSEL_REG_BASE(base, postfix)        (&R_GPIO->FILCLKSEL ## base ## postfix)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* IOPort Implementation of IOPort Driver  */
const ioport_api_t g_ioport_on_ioport =
{
    .open                 = R_IOPORT_Open,
    .close                = R_IOPORT_Close,
    .pinsCfg              = R_IOPORT_PinsCfg,
    .pinCfg               = R_IOPORT_PinCfg,
    .pinEventInputRead    = R_IOPORT_PinEventInputRead,
    .pinEventOutputWrite  = R_IOPORT_PinEventOutputWrite,
    .pinRead              = R_IOPORT_PinRead,
    .pinWrite             = R_IOPORT_PinWrite,
    .portDirectionSet     = R_IOPORT_PortDirectionSet,
    .portEventInputRead   = R_IOPORT_PortEventInputRead,
    .portEventOutputWrite = R_IOPORT_PortEventOutputWrite,
    .portRead             = R_IOPORT_PortRead,
    .portWrite            = R_IOPORT_PortWrite,
};

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_ioport_pins_config(const ioport_cfg_t * p_cfg);

static void r_ioport_pfs_write(bsp_io_port_pin_t pin, uint32_t value);

static void r_ioport_dedicated_port_cfg(bsp_io_port_pin_t pin, uint32_t value);
static void r_ioport_peri_mode_pin_config(bsp_io_port_pin_t pin, uint32_t value);
static void r_ioport_port_mode_pin_config(bsp_io_port_pin_t pin, uint32_t value);
static void r_ioport_make_port_pin_num(bsp_io_port_pin_t pin, uint8_t * p_port_number, uint8_t * p_pin_number);
static void r_ioport_regwrite_8(volatile uint8_t * ioreg, uint8_t write_value, uint8_t shift, uint8_t mask);
static void r_ioport_regwrite_16(volatile uint16_t * ioreg, uint16_t write_value, uint16_t shift, uint16_t mask);
static void r_ioport_regwrite_32(volatile uint32_t * ioreg, uint32_t write_value, uint32_t shift, uint32_t mask);

static void r_ioport_event_config(const ioport_extend_cfg_t * p_extend_cfg_data);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup IOPORT
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes internal driver data, then calls pin configuration function to configure pins.
 *
 * @retval FSP_SUCCESS                  Pin configuration data written to PFS register(s)
 * @retval FSP_ERR_ASSERTION            NULL pointer
 * @retval FSP_ERR_ALREADY_OPEN         Module is already open.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_Open (ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg)
{
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;

#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_pin_cfg_data || 0 == p_cfg->number_of_pins);
    FSP_ERROR_RETURN(IOPORT_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Set driver status to open */
    p_instance_ctrl->open = IOPORT_OPEN;

    p_instance_ctrl->p_cfg = p_cfg;

    r_ioport_pins_config(p_cfg);

    r_ioport_event_config(p_cfg->p_extend);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Resets IOPORT registers. Implements @ref ioport_api_t::close
 *
 * @retval FSP_SUCCESS             The IOPORT was successfully uninitialized
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_Close (ioport_ctrl_t * const p_ctrl)
{
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;

#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Set state to closed */
    p_instance_ctrl->open = IOPORT_CLOSED;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configures the functions of multiple pins by loading configuration data into each registers.
 * Implements @ref ioport_api_t::pinsCfg.
 *
 * This function initializes the supplied list of each registers with the supplied values. This data define in
 * pin_data.c. Different pin configurations can be loaded for different situations such as low power modes and testing.
 *
 * @retval FSP_SUCCESS             Pin configuration data written to each registers
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 * @retval FSP_ERR_ASSERTION       NULL pointer
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinsCfg (ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_pin_cfg_data);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    r_ioport_pins_config(p_cfg);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configures the settings of a pin. Implements @ref ioport_api_t::pinCfg.
 *
 * @retval FSP_SUCCESS             Pin configured
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 * @retval FSP_ERR_ASSERTION       NULL pointer
 *
 * @note This function is re-entrant for different pins.
 * This function will change the configuration of the pin with the new configuration. For example it is not possible
 * with this function to change the drive strength of a pin while leaving all the other pin settings unchanged. To
 * achieve this the original settings with the required change will need to be written using this function.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinCfg (ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, uint32_t cfg)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    R_BSP_PinAccessEnable();

    r_ioport_pfs_write(pin, cfg);

    R_BSP_PinAccessDisable();

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads the level on a pin. Implements @ref ioport_api_t::pinRead.
 *
 * @retval FSP_SUCCESS             Pin read
 * @retval FSP_ERR_ASSERTION       NULL pointer
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 * @note This function is re-entrant for different pins.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinRead (ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_value)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_pin_value);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    *p_pin_value = (bsp_io_level_t) R_BSP_PinRead(pin);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads the value on an IO port. Implements @ref ioport_api_t::portRead.
 *
 * The specified port will be read, and the levels for all the pins will be returned.
 * Each bit in the returned value corresponds to a pin on the port. For example, bit 4 corresponds
 * to pin 4, bit 3 to pin 3, and so on.
 *
 * @retval FSP_SUCCESS             Port read
 * @retval FSP_ERR_ASSERTION       NULL pointer
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 * @note This function is re-entrant for different ports.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PortRead (ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_port_value)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_port_value);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Get the port address */
    volatile const uint8_t * p_ioport_regs;
    p_ioport_regs = IOPORT_PRV_PIN_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM);
    p_ioport_regs = &p_ioport_regs[port >> IOPORT_PRV_PORT_OFFSET];

    /* Read current value of PIN register for the specified port */
    *p_port_value = *p_ioport_regs;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Writes to multiple pins on a port. Implements @ref ioport_api_t::portWrite.
 *
 * The input value will be written to the specified port. Each bit in the value parameter corresponds to a bit
 * on the port. For example, bit 4 corresponds to pin 4, bit 3 to pin 3, and so on.
 * Each bit in the mask parameter corresponds to a pin on the port.
 *
 * Only the bits with the corresponding bit in the mask value set will be updated.
 * For example, value = 0xFFFF, mask = 0x0003 results in only bits 0 and 1 being updated.
 *
 * @retval FSP_SUCCESS                  Port written to
 * @retval FSP_ERR_INVALID_ARGUMENT     The port and/or mask not valid
 * @retval FSP_ERR_NOT_OPEN             The module has not been opened
 * @retval FSP_ERR_ASSERTION            NULL pointerd
 *
 * @note This function is re-entrant for different ports.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PortWrite (ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t value, ioport_size_t mask)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(mask > (ioport_size_t) 0, FSP_ERR_INVALID_ARGUMENT);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Get the port address */
    volatile uint8_t * p_ioport_regs;
    p_ioport_regs = IOPORT_PRV_P_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM);
    p_ioport_regs = &p_ioport_regs[port >> IOPORT_PRV_PORT_OFFSET];

    /* Set the port level to P register */
    r_ioport_regwrite_8(p_ioport_regs, (uint8_t) value, 0, (uint8_t) mask);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets a pin's output either high or low. Implements @ref ioport_api_t::pinWrite.
 *
 * @retval FSP_SUCCESS                  Pin written to
 * @retval FSP_ERR_INVALID_ARGUMENT     The pin and/or level not valid
 * @retval FSP_ERR_NOT_OPEN             The module has not been opened
 * @retval FSP_ERR_ASSERTION            NULL pointer
 *
 * @note This function is re-entrant for different pins.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinWrite (ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t level)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(level <= BSP_IO_LEVEL_HIGH, FSP_ERR_INVALID_ARGUMENT);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    bsp_io_port_t port     = (bsp_io_port_t) (IOPORT_PRV_PORT_BITS & (ioport_size_t) pin);
    ioport_size_t shift    = IOPORT_PRV_PIN_BITS & (ioport_size_t) pin;
    ioport_size_t pin_mask = (ioport_size_t) (1U << shift);

    /* Get the port address */
    volatile uint8_t * p_ioport_regs;
    p_ioport_regs = IOPORT_PRV_P_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM);
    p_ioport_regs = &p_ioport_regs[port >> IOPORT_PRV_PORT_OFFSET];

    /* Set the pin level to P register */
    r_ioport_regwrite_8(p_ioport_regs, (uint8_t) level, (uint8_t) shift, (uint8_t) pin_mask);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets the direction of individual pins on a port. Implements @ref ioport_api_t::portDirectionSet().
 *
 * Multiple pins on a port can be set to inputs or outputs at once.
 * Each bit in the mask parameter corresponds to a pin on the port. For example, bit[9:8] corresponds to pin 4,
 * bit[7:6] to pin 3, and so on.
 * If bits are set to b'11 then the corresponding pin will be changed to an input or an output or Hi-Z as specified by
 * the direction values. If a mask bits are set to b'00 then the direction of the pin will not be changed.
 *
 * @retval FSP_SUCCESS                 Port direction updated
 * @retval FSP_ERR_INVALID_ARGUMENT    The port and/or mask not valid
 * @retval FSP_ERR_NOT_OPEN            The module has not been opened
 * @retval FSP_ERR_ASSERTION           NULL pointer
 *
 * @note This function is re-entrant for different ports.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PortDirectionSet (ioport_ctrl_t * const p_ctrl,
                                     bsp_io_port_t         port,
                                     ioport_size_t         direction_values,
                                     ioport_size_t         mask)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(mask > (ioport_size_t) 0, FSP_ERR_INVALID_ARGUMENT);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Get the port address */
    volatile uint16_t * p_ioport_regs;
    p_ioport_regs = IOPORT_PRV_PM_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM);
    p_ioport_regs = &p_ioport_regs[port >> IOPORT_PRV_PORT_OFFSET];

    /* Set the port direction to PM register */
    r_ioport_regwrite_16(p_ioport_regs, direction_values, 0, mask);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads the value of the event input data. Implements @ref ioport_api_t::portEventInputRead().
 *
 * The event input data for the port will be read. Each bit in the returned value corresponds to a pin on the port.
 * For example, bit 7 corresponds to pin 7, bit 6 to pin 6, and so on.
 *
 * The port event data is captured in response to a trigger from the ELC. This function enables this data to be read.
 * Using the event system allows the captured data to be stored when it occurs and then read back at a later time.
 *
 * @retval FSP_SUCCESS              Port read
 * @retval FSP_ERR_INVALID_ARGUMENT Port not a valid ELC port
 * @retval FSP_ERR_ASSERTION        NULL pointer
 * @retval FSP_ERR_NOT_OPEN         The module has not been opened
 * @retval FSP_ERR_UNSUPPORTED      The function is not supported on the device which doesn't support ELC.
 *
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PortEventInputRead (ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_event_data)
{
#if !(BSP_FEATURE_BSP_HAS_ELC)
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(port);
    FSP_PARAMETER_NOT_USED(p_event_data);

    return FSP_ERR_UNSUPPORTED;
#else
    uint8_t portgroup = 0U;
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;

 #if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_event_data);
    FSP_ERROR_RETURN((port == BSP_FEATURE_IOPORT_GROUP1_PORT) || (port == BSP_FEATURE_IOPORT_GROUP2_PORT),
                     FSP_ERR_INVALID_ARGUMENT);
 #else
    FSP_PARAMETER_NOT_USED(p_ctrl);
 #endif

    const ioport_extend_cfg_t * elc_cfg = p_instance_ctrl->p_cfg->p_extend;

    /* Get register address */
    R_GPIO_Type * p_ioport_regs = R_GPIO;

    /* Get port group number for the specified port */
    if (BSP_FEATURE_IOPORT_GROUP1_PORT == port)
    {
        portgroup = 0U;
    }
    else if (BSP_FEATURE_IOPORT_GROUP2_PORT == port)
    {
        portgroup = 1U;
    }
    else
    {
        /* Do Nothing */
    }

    /* Read current value of buffer value from ELC_PDBF register for the specified port group */
    *p_event_data =
        (uint16_t) (p_ioport_regs->PDBF[portgroup].ELC_PDBF & elc_cfg->p_port_group_input_cfg[portgroup].pin_select);

    return FSP_SUCCESS;
#endif
}

/*******************************************************************************************************************//**
 * Reads the value of the event input data of a specific pin. Implements @ref ioport_api_t::pinEventInputRead.
 *
 * The pin event data is captured in response to a trigger from the ELC. This function enables this data to be read.
 * Using the event system allows the captured data to be stored when it occurs and then read back at a later time.
 *
 * @retval FSP_SUCCESS                  Pin read
 * @retval FSP_ERR_ASSERTION            NULL pointer
 * @retval FSP_ERR_NOT_OPEN             The module has not been opened
 * @retval FSP_ERR_INVALID_ARGUMENT     Port is not valid ELC PORT.
 * @retval FSP_ERR_UNSUPPORTED          The function is not supported on the device which doesn't support ELC.
 *
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinEventInputRead (ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_event)
{
#if !(BSP_FEATURE_BSP_HAS_ELC)
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(pin);
    FSP_PARAMETER_NOT_USED(p_pin_event);

    return FSP_ERR_UNSUPPORTED;
#else
    uint8_t portgroup = 0U;
    uint8_t portvalue;
    uint8_t mask;

 #if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_pin_event);
    uint32_t port_number = pin >> IOPORT_PRV_PORT_OFFSET;
    FSP_ERROR_RETURN((port_number == BSP_FEATURE_IOPORT_GROUP1_PORT >> IOPORT_PRV_PORT_OFFSET) ||
                     (port_number == BSP_FEATURE_IOPORT_GROUP2_PORT >> IOPORT_PRV_PORT_OFFSET),
                     FSP_ERR_INVALID_ARGUMENT);
 #else
    FSP_PARAMETER_NOT_USED(p_ctrl);
 #endif

    /* Get port and pin number */
    uint32_t port_num = (IOPORT_PRV_PORT_BITS & (ioport_size_t) pin);
    uint32_t pin_num  = (IOPORT_PRV_PIN_BITS & (ioport_size_t) pin);

    /* Get register address */
    R_GPIO_Type * p_ioport_regs = R_GPIO;

    /* Get port group number for the specified port */
    if (BSP_FEATURE_IOPORT_GROUP1_PORT == port_num)
    {
        portgroup = 0U;
    }
    else if (BSP_FEATURE_IOPORT_GROUP2_PORT == port_num)
    {
        portgroup = 1U;
    }
    else
    {
        /* Do Nothing */
    }

    /* Read current value of buffer value from ELC_PDBF register for the specified port group */
    portvalue = p_ioport_regs->PDBF[portgroup].ELC_PDBF;
    mask      = (uint8_t) (1U << pin_num);

    if ((portvalue & mask) == mask)
    {
        *p_pin_event = BSP_IO_LEVEL_HIGH;
    }
    else
    {
        *p_pin_event = BSP_IO_LEVEL_LOW;
    }
    return FSP_SUCCESS;
#endif
}

/*******************************************************************************************************************//**
 * This function writes the set and reset event output data for a port. Implements
 * @ref ioport_api_t::portEventOutputWrite.
 *
 * Using the event system enables a port state to be stored by this function in advance of being output on the port.
 * The output to the port will occur when the ELC event occurs.
 *
 * The input value will be written to the specified port when an ELC event configured for that port occurs.
 * Each bit in the value parameter corresponds to a bit on the port. For example, bit 7 corresponds to pin 7,
 * bit 6 to pin 6, and so on. Each bit in the mask parameter corresponds to a pin on the port.
 *
 * @retval FSP_SUCCESS                Port event data written
 * @retval FSP_ERR_INVALID_ARGUMENT   Port or Mask not valid
 * @retval FSP_ERR_NOT_OPEN           The module has not been opened
 * @retval FSP_ERR_ASSERTION          NULL pointer
 * @retval FSP_ERR_UNSUPPORTED        The function is not supported on the device which doesn't support ELC.
 *
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PortEventOutputWrite (ioport_ctrl_t * const p_ctrl,
                                         bsp_io_port_t         port,
                                         ioport_size_t         event_data,
                                         ioport_size_t         mask_value)
{
#if !(BSP_FEATURE_BSP_HAS_ELC)
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(port);
    FSP_PARAMETER_NOT_USED(event_data);
    FSP_PARAMETER_NOT_USED(mask_value);

    return FSP_ERR_UNSUPPORTED;
#else
    uint8_t       portgroup = 0U;
    ioport_size_t temp_value;

 #if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(mask_value > (ioport_size_t) 0, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((port == BSP_FEATURE_IOPORT_GROUP1_PORT) || (port == BSP_FEATURE_IOPORT_GROUP2_PORT),
                     FSP_ERR_INVALID_ARGUMENT);
 #else
    FSP_PARAMETER_NOT_USED(p_ctrl);
 #endif

    /* Get register address */
    R_GPIO_Type * p_ioport_regs = R_GPIO;

    /* Get port group number for the specified port */
    if (BSP_FEATURE_IOPORT_GROUP1_PORT == port)
    {
        portgroup = 0U;
    }
    else if (BSP_FEATURE_IOPORT_GROUP2_PORT == port)
    {
        portgroup = 1U;
    }
    else
    {
        /* Do Nothing */
    }

    temp_value  = p_ioport_regs->PDBF[portgroup].ELC_PDBF;
    temp_value &= (ioport_size_t) (~mask_value);

    p_ioport_regs->PDBF[portgroup].ELC_PDBF = (uint8_t) (temp_value | event_data);

    return FSP_SUCCESS;
#endif
}

/*******************************************************************************************************************//**
 * This function writes the event output data value to a pin. Implements @ref ioport_api_t::pinEventOutputWrite.
 *
 * Using the event system enables a pin state to be stored by this function in advance of being output on the pin.
 * The output to the pin will occur when the ELC event occurs.
 *
 * @retval FSP_SUCCESS               Pin event data written
 * @retval FSP_ERR_INVALID_ARGUMENT  Port or Pin or value not valid
 * @retval FSP_ERR_NOT_OPEN          The module has not been opened
 * @retval FSP_ERR_ASSERTION         NULL pointer
 * @retval FSP_ERR_UNSUPPORTED       The function is not supported on the device which doesn't support ELC.
 *
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinEventOutputWrite (ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t pin_value)
{
#if !(BSP_FEATURE_BSP_HAS_ELC)
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(pin);
    FSP_PARAMETER_NOT_USED(pin_value);

    return FSP_ERR_UNSUPPORTED;
#else
    uint8_t singleport = 0U;
    uint8_t cnt;
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;

 #if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((pin_value == BSP_IO_LEVEL_HIGH) || (pin_value == BSP_IO_LEVEL_LOW), FSP_ERR_INVALID_ARGUMENT);
    uint32_t port_number = pin >> IOPORT_PRV_PORT_OFFSET;
    FSP_ERROR_RETURN((port_number == BSP_FEATURE_IOPORT_GROUP1_PORT >> IOPORT_PRV_PORT_OFFSET) ||
                     (port_number == BSP_FEATURE_IOPORT_GROUP2_PORT >> IOPORT_PRV_PORT_OFFSET),
                     FSP_ERR_INVALID_ARGUMENT);
 #endif

    const ioport_extend_cfg_t * elc_cfg = p_instance_ctrl->p_cfg->p_extend;

    /* Get register address */
    R_GPIO_Type * p_ioport_regs = R_GPIO;

    for (cnt = 0; cnt < BSP_FEATURE_IOPORT_SINGLE_PORT_NUM; cnt++)
    {
        if ((bsp_io_port_pin_t) elc_cfg->p_single_port_cfg[cnt].port_num == pin)
        {
            singleport = cnt;
        }
    }

    if (BSP_IO_LEVEL_HIGH == pin_value)
    {
        p_ioport_regs->ELC_PEL[singleport] |= (uint8_t) IOPORT_PRV_ELC_PEL_PSM_HIGH;
    }
    else
    {
        p_ioport_regs->ELC_PEL[singleport] &= (uint8_t) (~IOPORT_PRV_ELC_PEL_PSM_HIGH);
    }
    return FSP_SUCCESS;
#endif
}

/*******************************************************************************************************************//**
 * @} (end addtogroup IOPORT)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configures pins.
 *
 * @param[in]    p_cfg          Pin configuration data
 **********************************************************************************************************************/
static void r_ioport_pins_config (const ioport_cfg_t * p_cfg)
{
    uint16_t       pin_count;
    ioport_cfg_t * p_pin_data;

    p_pin_data = (ioport_cfg_t *) p_cfg;

    R_BSP_PinAccessEnable();           // Protect PWPR from re-entrancy

    for (pin_count = 0U; pin_count < p_pin_data->number_of_pins; pin_count++)
    {
        r_ioport_pfs_write(p_pin_data->p_pin_cfg_data[pin_count].pin, p_pin_data->p_pin_cfg_data[pin_count].pin_cfg);
    }

    R_BSP_PinAccessDisable();
}

/**********************************************************************************************************************
 * End of function r_ioport_pins_config
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Writes to the specified pin's PFS register
 *
 * @param[in]    pin        Pin to write PFS data for
 * @param[in]    value      Value to be written to the PFS register
 *
 **********************************************************************************************************************/
static void r_ioport_pfs_write (bsp_io_port_pin_t pin, uint32_t value)
{
    if (0 != (pin & IOPORT_PRV_PORT_EXISTS_MASK))
    {
        r_ioport_dedicated_port_cfg(pin, value);
    }
    else if ((value & IOPORT_PRV_PERIPHERAL_FUNCTION) > 0)
    {
        r_ioport_peri_mode_pin_config(pin, value);
    }
    else
    {
        r_ioport_port_mode_pin_config(pin, value);
    }
}

/*******************************************************************************************************************//**
 * Writes to the specified pin's each registers for dedicated pin's
 *
 * @param[in]    pin        Pin to write pin function setting data for
 * @param[in]    value      Value to be written to the each registers
 *
 **********************************************************************************************************************/
static void r_ioport_dedicated_port_cfg (bsp_io_port_pin_t pin, uint32_t value)
{
    uint8_t             u_port;
    uint8_t             u_pin;
    uint32_t            bitpos_align;
    uint8_t             adr_offset;
    volatile uint32_t * p_ien;
    volatile uint32_t * p_iolh;
    volatile uint32_t * p_filonoff;
    volatile uint32_t * p_filnum;
    volatile uint32_t * p_filclksel;
    uint32_t            mask_ien;
    uint32_t            mask_iolh;
    uint32_t            mask_filonoff;
    uint32_t            mask_filnum;
    uint32_t            mask_filclksel;
    uint32_t            value_ien;
    uint32_t            value_iolh;
    uint32_t            value_filonoff;
    uint32_t            value_filnum;
    uint32_t            value_filclksel;
#if BSP_FEATURE_IOPORT_SUPPORT_PUPD_SP
    uint8_t             adr_offset_pupd;
    volatile uint32_t * p_pupd;
    uint32_t            mask_pupd;
    uint32_t            value_pupd;
#endif

    r_ioport_make_port_pin_num(pin, &u_port, &u_pin);
    bitpos_align = (u_pin & IOPORT_PRV_2BIT_MASK) * IOPORT_PRV_POS_ALIGN_8BIT;

    adr_offset = (uint8_t) (((u_port - BSP_FEATURE_IOPORT_SP_REG_BASE_NUM) * 2) + (u_pin >> 2));

    p_ien  = IOPORT_PRV_IEN_REG_BASE_SET(BSP_FEATURE_IOPORT_IEN_SP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_iolh =
        IOPORT_PRV_IOLH_REG_BASE_SET(BSP_FEATURE_IOPORT_IOLH_SP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_filonoff = IOPORT_PRV_FILONOFF_REG_BASE_SET(BSP_FEATURE_IOPORT_FIL_SP_REG_BASE_NUM,
                                                  BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_filnum = IOPORT_PRV_FILNUM_REG_BASE_SET(BSP_FEATURE_IOPORT_FIL_SP_REG_BASE_NUM,
                                              BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_filclksel = IOPORT_PRV_FILCLKSEL_REG_BASE_SET(BSP_FEATURE_IOPORT_FIL_SP_REG_BASE_NUM,
                                                    BSP_FEATURE_IOPORT_REG_POSTFIX_L);

    mask_ien       = IOPORT_PRV_BITFIELD_1BIT << bitpos_align;
    mask_iolh      = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
    mask_filonoff  = IOPORT_PRV_BITFIELD_1BIT << bitpos_align;
    mask_filnum    = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
    mask_filclksel = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;

    value_ien       = (value >> IOPORT_PRV_IEN_OFFSET) & IOPORT_PRV_BITFIELD_1BIT;
    value_iolh      = (value >> IOPORT_PRV_IOLH_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;
    value_filonoff  = (value >> IOPORT_PRV_FILONOFF_OFFSET) & IOPORT_PRV_BITFIELD_1BIT;
    value_filnum    = (value >> IOPORT_PRV_FILNUM_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;
    value_filclksel = (value >> IOPORT_PRV_FILCLKSEL_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;

#if BSP_FEATURE_IOPORT_SUPPORT_PUPD_SP
    adr_offset_pupd = (uint8_t) (((u_port - BSP_FEATURE_IOPORT_PUPD_SP_REG_BASE_NUM) * 2) + (u_pin >> 2));
    p_pupd          =
        IOPORT_PRV_PUPD_REG_BASE_SET(BSP_FEATURE_IOPORT_PUPD_SP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    mask_pupd  = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
    value_pupd = (value >> IOPORT_PRV_PUPD_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;

    /* Configure of PUPD Register */
    r_ioport_regwrite_32(&p_pupd[adr_offset_pupd], value_pupd, bitpos_align, mask_pupd);
#endif

    /* Configure of IEN Register, IOLH Register, SR Register and PUPD Register */
    r_ioport_regwrite_32(&p_ien[adr_offset], value_ien, bitpos_align, mask_ien);
    r_ioport_regwrite_32(&p_iolh[adr_offset], value_iolh, bitpos_align, mask_iolh);

    /* When use NMI pin, configure FILONOFF, FILNUM, FILCLKSEL register. */
    if (((BSP_IO_NMI & IOPORT_PRV_PORT_BITS) >> IOPORT_PRV_PORT_OFFSET) == u_port)
    {
        r_ioport_regwrite_32(p_filonoff, value_filonoff, bitpos_align, mask_filonoff);
        r_ioport_regwrite_32(p_filnum, value_filnum, bitpos_align, mask_filnum);
        r_ioport_regwrite_32(p_filclksel, value_filclksel, bitpos_align, mask_filclksel);
    }
}

/*******************************************************************************************************************//**
 * Writes to the specified pin's each registers for peripheral pin's
 *
 * @param[in]    pin        Pin to write pin function setting data for
 * @param[in]    value      Value to be written to the each registers
 *
 **********************************************************************************************************************/
static void r_ioport_peri_mode_pin_config (bsp_io_port_pin_t pin, uint32_t value)
{
    uint8_t             u_port;
    uint8_t             u_pin;
    uint32_t            bitpos_align;
    uint8_t             adr_offset;
    volatile uint8_t  * p_pmc;
    volatile uint32_t * p_iolh;
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    volatile uint32_t * p_sr;
#endif
    volatile uint32_t * p_pupd;
    volatile uint32_t * p_filonoff;
    volatile uint32_t * p_filnum;
    volatile uint32_t * p_filclksel;
    volatile uint32_t * p_pfc;
    uint8_t             mask_pmc;
    uint32_t            mask_iolh;
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    uint32_t mask_sr;
#endif
    uint32_t mask_pupd;
    uint32_t mask_filonoff;
    uint32_t mask_filnum;
    uint32_t mask_filclksel;
    uint32_t mask_pfc;
    uint8_t  value_pmc;
    uint32_t value_iolh;
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    uint32_t value_sr;
#endif
    uint32_t value_pupd;
    uint32_t value_filonoff;
    uint32_t value_filnum;
    uint32_t value_filclksel;
    uint32_t value_pfc;
#if (BSP_FEATURE_IOPORT_SUPPORT_IEN_GP)
    uint8_t             adr_offset_ien;
    volatile uint32_t * p_ien;
    uint32_t            mask_ien;
    uint32_t            value_ien;
#endif

    r_ioport_make_port_pin_num(pin, &u_port, &u_pin);
    bitpos_align = (u_pin & IOPORT_PRV_2BIT_MASK) * IOPORT_PRV_POS_ALIGN_8BIT;

    adr_offset = (uint8_t) ((u_port * 2) + (u_pin >> 2));

    p_pmc  = IOPORT_PRV_PMC_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM);
    p_iolh = IOPORT_PRV_IOLH_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    p_sr = IOPORT_PRV_SR_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
#endif
    p_pupd     = IOPORT_PRV_PUPD_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_filonoff =
        IOPORT_PRV_FILONOFF_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_filnum    = IOPORT_PRV_FILNUM_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_filclksel =
        IOPORT_PRV_FILCLKSEL_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_pfc = IOPORT_PRV_PFC_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM);

    mask_pmc  = (uint8_t) (IOPORT_PRV_BITFIELD_1BIT << u_pin);
    mask_iolh = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    mask_sr = IOPORT_PRV_BITFIELD_1BIT << bitpos_align;
#endif
    mask_pupd      = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
    mask_filonoff  = IOPORT_PRV_BITFIELD_1BIT << bitpos_align;
    mask_filnum    = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
    mask_filclksel = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
    mask_pfc       = IOPORT_PRV_BITFIELD_3BIT << (u_pin * IOPORT_PRV_POS_ALIGN_4BIT);

    value_pmc  = (uint8_t) ((value >> IOPORT_PRV_PMC_OFFSET) & IOPORT_PRV_BITFIELD_1BIT);
    value_iolh = (value >> IOPORT_PRV_IOLH_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    value_sr = (value >> IOPORT_PRV_SR_OFFSET) & IOPORT_PRV_BITFIELD_1BIT;
#endif
    value_pupd      = (value >> IOPORT_PRV_PUPD_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;
    value_filonoff  = (value >> IOPORT_PRV_FILONOFF_OFFSET) & IOPORT_PRV_BITFIELD_1BIT;
    value_filnum    = (value >> IOPORT_PRV_FILNUM_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;
    value_filclksel = (value >> IOPORT_PRV_FILCLKSEL_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;
    value_pfc       = ((value >> IOPORT_PRV_PFC_OFFSET) & IOPORT_PRV_BITFIELD_3BIT);

    r_ioport_regwrite_8(&p_pmc[u_port], value_pmc, u_pin, mask_pmc);

    /* Configure of IOLH Register, SR Register, PUPD Register */
    r_ioport_regwrite_32(&p_iolh[adr_offset], value_iolh, bitpos_align, mask_iolh);
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    r_ioport_regwrite_32(&p_sr[adr_offset], value_sr, bitpos_align, mask_sr);
#endif
    r_ioport_regwrite_32(&p_pupd[adr_offset], value_pupd, bitpos_align, mask_pupd);

#if (BSP_FEATURE_IOPORT_SUPPORT_IEN_GP)
    adr_offset_ien =
        (uint8_t) (((u_port - BSP_FEATURE_IOPORT_IEN_GP_REG_BASE_NUM + BSP_FEATURE_IOPORT_GP_REG_BASE_NUM) * 2) +
                   (u_pin >> 2));
    p_ien     = IOPORT_PRV_IEN_REG_BASE_SET(BSP_FEATURE_IOPORT_IEN_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    mask_ien  = IOPORT_PRV_BITFIELD_1BIT << bitpos_align;
    value_ien = (value >> IOPORT_PRV_IEN_OFFSET) & IOPORT_PRV_BITFIELD_1BIT;

    /* Configure of IEN Register */
    r_ioport_regwrite_32(&p_ien[adr_offset_ien], value_ien, bitpos_align, mask_ien);
#endif

    r_ioport_regwrite_32(&p_filonoff[adr_offset], value_filonoff, bitpos_align, mask_filonoff);
    r_ioport_regwrite_32(&p_filnum[adr_offset], value_filnum, bitpos_align, mask_filnum);
    r_ioport_regwrite_32(&p_filclksel[adr_offset], value_filclksel, bitpos_align, mask_filclksel);

    r_ioport_regwrite_32(&p_pfc[u_port], value_pfc, (uint32_t) (u_pin * IOPORT_PRV_POS_ALIGN_4BIT), mask_pfc);
}

/*******************************************************************************************************************//**
 * Writes to the specified pin's each registers for general purpose pin's
 *
 * @param[in]    pin        Pin to write pin function setting data for
 * @param[in]    value      Value to be written to the each registers
 *
 **********************************************************************************************************************/
static void r_ioport_port_mode_pin_config (bsp_io_port_pin_t pin, uint32_t value)
{
    uint8_t             u_port;
    uint8_t             u_pin;
    uint32_t            bitpos_align;
    uint8_t             adr_offset;
    volatile uint8_t  * p_pmc;
    volatile uint32_t * p_iolh;
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    volatile uint32_t * p_sr;
#endif
    volatile uint32_t * p_pupd;
    volatile uint32_t * p_isel;
    volatile uint32_t * p_filonoff;
    volatile uint32_t * p_filnum;
    volatile uint32_t * p_filclksel;
    volatile uint16_t * p_pm;
    volatile uint8_t  * p_p;
    uint8_t             mask_pmc;
    uint32_t            mask_iolh;
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    uint32_t mask_sr;
#endif
    uint32_t mask_pupd;
    uint32_t mask_isel;
    uint32_t mask_filonoff;
    uint32_t mask_filnum;
    uint32_t mask_filclksel;
    uint16_t mask_pm;
    uint8_t  mask_p;
    uint8_t  value_pmc;
    uint32_t value_iolh;
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    uint32_t value_sr;
#endif
    uint32_t value_pupd;
    uint32_t value_isel;
    uint32_t value_filonoff;
    uint32_t value_filnum;
    uint32_t value_filclksel;
    uint16_t value_pm;
    uint8_t  value_p;

    r_ioport_make_port_pin_num(pin, &u_port, &u_pin);
    bitpos_align = (u_pin & IOPORT_PRV_2BIT_MASK) * IOPORT_PRV_POS_ALIGN_8BIT;

    adr_offset = (uint8_t) ((u_port * 2) + (u_pin >> 2));

    p_pmc  = IOPORT_PRV_PMC_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM);
    p_iolh = IOPORT_PRV_IOLH_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    p_sr = IOPORT_PRV_SR_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
#endif
    p_pupd     = IOPORT_PRV_PUPD_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_isel     = IOPORT_PRV_ISEL_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_filonoff =
        IOPORT_PRV_FILONOFF_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_filnum    = IOPORT_PRV_FILNUM_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_filclksel =
        IOPORT_PRV_FILCLKSEL_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM, BSP_FEATURE_IOPORT_REG_POSTFIX_L);
    p_pm = IOPORT_PRV_PM_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM);
    p_p  = IOPORT_PRV_P_REG_BASE_SET(BSP_FEATURE_IOPORT_GP_REG_BASE_NUM);

    mask_pmc  = (uint8_t) (IOPORT_PRV_BITFIELD_1BIT << u_pin);
    mask_pm   = (uint16_t) (IOPORT_PRV_BITFIELD_2BIT << (u_pin * IOPORT_PRV_POS_ALIGN_2BIT));
    mask_iolh = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    mask_sr = IOPORT_PRV_BITFIELD_1BIT << bitpos_align;
#endif
    mask_pupd      = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
    mask_isel      = IOPORT_PRV_BITFIELD_1BIT << bitpos_align;
    mask_filonoff  = IOPORT_PRV_BITFIELD_1BIT << bitpos_align;
    mask_filnum    = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
    mask_filclksel = IOPORT_PRV_BITFIELD_2BIT << bitpos_align;
    mask_p         = (uint8_t) (IOPORT_PRV_BITFIELD_1BIT << u_pin);

    value_pmc  = (uint8_t) ((value >> IOPORT_PRV_PMC_OFFSET) & IOPORT_PRV_BITFIELD_1BIT);
    value_iolh = (value >> IOPORT_PRV_IOLH_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    value_sr = (value >> IOPORT_PRV_SR_OFFSET) & IOPORT_PRV_BITFIELD_1BIT;
#endif
    value_pupd      = (value >> IOPORT_PRV_PUPD_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;
    value_isel      = (value >> IOPORT_PRV_ISEL_OFFSET) & IOPORT_PRV_BITFIELD_1BIT;
    value_filonoff  = (value >> IOPORT_PRV_FILONOFF_OFFSET) & IOPORT_PRV_BITFIELD_1BIT;
    value_filnum    = (value >> IOPORT_PRV_FILNUM_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;
    value_filclksel = (value >> IOPORT_PRV_FILCLKSEL_OFFSET) & IOPORT_PRV_BITFIELD_2BIT;
    value_pm        = (uint16_t) ((value >> IOPORT_PRV_PM_OFFSET) & IOPORT_PRV_BITFIELD_2BIT);
    value_p         = (uint8_t) ((value >> IOPORT_PRV_P_OFFSET) & IOPORT_PRV_BITFIELD_1BIT);

    /* Write configuration */
    r_ioport_regwrite_8(&p_pmc[u_port], value_pmc, u_pin, mask_pmc);

    r_ioport_regwrite_32(&p_iolh[adr_offset], value_iolh, bitpos_align, mask_iolh);
#if (BSP_FEATURE_IOPORT_SUPPORT_SR_REG)
    r_ioport_regwrite_32(&p_sr[adr_offset], value_sr, bitpos_align, mask_sr);
#endif
    r_ioport_regwrite_32(&p_pupd[adr_offset], value_pupd, bitpos_align, mask_pupd);

    /* When setting the interrupt input using the GPIO input pin, set the ISEL register to "1". */
    r_ioport_regwrite_32(&p_isel[adr_offset], value_isel, bitpos_align, mask_isel);

    r_ioport_regwrite_32(&p_filonoff[adr_offset], value_filonoff, bitpos_align, mask_filonoff);
    r_ioport_regwrite_32(&p_filnum[adr_offset], value_filnum, bitpos_align, mask_filnum);
    r_ioport_regwrite_32(&p_filclksel[adr_offset], value_filclksel, bitpos_align, mask_filclksel);

    r_ioport_regwrite_16(&p_pm[u_port], value_pm, (uint16_t) (u_pin * IOPORT_PRV_POS_ALIGN_2BIT), mask_pm);
    r_ioport_regwrite_8(&p_p[u_port], value_p, u_pin, mask_p);
}

/*******************************************************************************************************************//**
 * Make pin and port number
 *
 * @param[in]    pin             Pin and port number
 * @param[out]   p_port_number   Port number
 * @param[out]   p_pin_number    Pin number
 *
 **********************************************************************************************************************/
static void r_ioport_make_port_pin_num (bsp_io_port_pin_t pin, uint8_t * p_port_number, uint8_t * p_pin_number)
{
    *p_port_number = (uint8_t) ((pin & IOPORT_PRV_PORT_BITS) >> IOPORT_PRV_PORT_OFFSET);
    *p_pin_number  = (uint8_t) (pin & IOPORT_PRV_PIN_BITS);
}

/**********************************************************************************************************************
 * IO register 8-bit write
 *
 * @param[in]   ioreg          IO register for writing
 *                             Use register definition name of the iodefine.h
 * @param[in]   write_value    Write value for the IO register
 * @param[in]   shift          The number of left shifts to the target bit
 * @param[in]   mask           Mask value for the IO register (Target bit : "1")
 *
 *********************************************************************************************************************/
static void r_ioport_regwrite_8 (volatile uint8_t * ioreg, uint8_t write_value, uint8_t shift, uint8_t mask)
{
    uint8_t reg_value;

    if ((uint8_t) IOPORT_PRV_NONMASK_ACCESS != mask)
    {
        /* Read from register */
        reg_value = *ioreg;

        /* Modify value */
        reg_value = (uint8_t) ((reg_value & (~mask)) | (write_value << shift));
    }
    else
    {
        reg_value = write_value;
    }

    /* Write to register */
    *ioreg = reg_value;
}

/**********************************************************************************************************************
 * IO register 16-bit write
 *
 * @param[in]   ioreg          IO register for writing
 *                             Use register definition name of the iodefine.h
 * @param[in]   write_value    Write value for the IO register
 * @param[in]   shift          The number of left shifts to the target bit
 * @param[in]   mask           Mask value for the IO register (Target bit : "1")
 *
 *********************************************************************************************************************/
static void r_ioport_regwrite_16 (volatile uint16_t * ioreg, uint16_t write_value, uint16_t shift, uint16_t mask)
{
    uint16_t reg_value;

    if ((uint16_t) IOPORT_PRV_NONMASK_ACCESS != mask)
    {
        /* Read from register */
        reg_value = *ioreg;

        /* Modify value */
        reg_value = (uint16_t) ((reg_value & (~mask)) | (write_value << shift));
    }
    else
    {
        reg_value = write_value;
    }

    /* Write to register */
    *ioreg = reg_value;
}

/**********************************************************************************************************************
 * IO register 32-bit write
 *
 * @param[in]   ioreg          IO register for writing
 *                             Use register definition name of the iodefine.h
 * @param[in]   write_value    Write value for the IO register
 * @param[in]   shift          The number of left shifts to the target bit
 * @param[in]   mask           Mask value for the IO register (Target bit : "1")
 *
 *********************************************************************************************************************/
static void r_ioport_regwrite_32 (volatile uint32_t * ioreg, uint32_t write_value, uint32_t shift, uint32_t mask)
{
    uint32_t reg_value;

    if (IOPORT_PRV_NONMASK_ACCESS != mask)
    {
        /* Read from register */
        reg_value = *ioreg;

        /* Modify value */
        reg_value = (uint32_t) ((reg_value & (~mask)) | (write_value << shift));
    }
    else
    {
        reg_value = write_value;
    }

    /* Write to register */
    *ioreg = reg_value;
}

/*******************************************************************************************************************//**
 * Writes to the specified pin's multiple registers to generate event link function
 *
 * @param[in]    p_extend_cfg_data Value to be written to the multiple registers
 *
 **********************************************************************************************************************/
static void r_ioport_event_config (const ioport_extend_cfg_t * p_extend_cfg_data)
{
#if !(BSP_FEATURE_BSP_HAS_ELC)
    FSP_PARAMETER_NOT_USED(p_extend_cfg_data);
#else
    uint8_t               event_num;
    uint8_t               temp_value    = 0x00;
    uint8_t               single_enable = 0x00;
    uint8_t               group_enable  = 0x00;
    R_GPIO_Type         * p_ioport_regs;
    ioport_extend_cfg_t * ex_cfg;

    ex_cfg = (ioport_extend_cfg_t *) p_extend_cfg_data;

    R_BSP_PinAccessEnable();           // Unlock Register Write Protection

    /* Get register address */
    p_ioport_regs = R_GPIO;

    /* Single port configuration */
    for (event_num = 0U; event_num < BSP_FEATURE_IOPORT_SINGLE_PORT_NUM; event_num++)
    {
        uint8_t port =
            (uint8_t) ((ex_cfg->p_single_port_cfg[event_num].port_num & IOPORT_PRV_PORT_BITS) >>
                       IOPORT_PRV_PORT_OFFSET);
        uint8_t pin_num = (uint8_t) ex_cfg->p_single_port_cfg[event_num].port_num & IOPORT_PRV_PIN_BITS;

        temp_value = p_ioport_regs->ELC_PEL[event_num] & IOPORT_PRV_ELC_PEL_MASK;

        /* Port selection */
        if ((BSP_FEATURE_IOPORT_GROUP1_PORT >> IOPORT_PRV_PORT_OFFSET) == port)
        {
            temp_value |= 1U << R_GPIO_ELC_PEL_PSP_Pos;
        }
        else if ((BSP_FEATURE_IOPORT_GROUP2_PORT >> IOPORT_PRV_PORT_OFFSET) == port)
        {
            temp_value |= 1U << (R_GPIO_ELC_PEL_PSP_Pos + 1);
        }
        else
        {
            /* Do Nothing */
        }

        temp_value |= pin_num;         // Pin number setting

        /* When the pin specified as single input port, Set edge detection */
        /* When the pin specified as single output port, Set output operation */
        if (IOPORT_EVENT_DIRECTION_INPUT == ex_cfg->p_single_port_cfg[event_num].direction)
        {
            temp_value |= (uint8_t) (ex_cfg->p_single_port_cfg[event_num].edge_detection << R_GPIO_ELC_PEL_PSM_Pos); // Edge detection

            /* Edge detection enable */
            p_ioport_regs->ELC_DPTC |= (uint8_t) (1U << event_num);
        }
        else
        {
            temp_value |= (uint8_t) (ex_cfg->p_single_port_cfg[event_num].operation << R_GPIO_ELC_PEL_PSM_Pos); // Output operation
        }

        /* Set to ELC port setting register */
        p_ioport_regs->ELC_PEL[event_num] = temp_value;

        /* Single port event link function enable */
        if (IOPORT_EVENT_CONTROL_ENABLE == ex_cfg->p_single_port_cfg[event_num].event_control)
        {
            single_enable |= (uint8_t) (1U << event_num);
        }
    }

    /* Port group configuration */
    for (event_num = 0U; event_num < BSP_FEATURE_IOPORT_PORT_GROUP_NUM; event_num++)
    {
        /* Pin selection */
        uint8_t group_pin = ex_cfg->p_port_group_input_cfg[event_num].pin_select |
                            ex_cfg->p_port_group_output_cfg[event_num].pin_select;
        p_ioport_regs->ELC_PGR[event_num] = group_pin;

        if (IOPORT_EVENT_CONTROL_ENABLE == ex_cfg->p_port_group_input_cfg[event_num].event_control)
        {
            /* Input port group control */
            temp_value  = p_ioport_regs->ELC_PGC[event_num] & IOOPRT_PRV_ELC_PGC_MASK;
            temp_value |= ex_cfg->p_port_group_input_cfg[event_num].edge_detection;                                   // Edge detection
            temp_value |=
                (uint8_t) (ex_cfg->p_port_group_input_cfg[event_num].overwrite_control << R_GPIO_ELC_PGC_PGCOVE_Pos); // Overwrite setting

            /* Buffer register initialization */
            p_ioport_regs->PDBF[event_num].ELC_PDBF = ex_cfg->p_port_group_input_cfg[event_num].buffer_init_value;

            /* Input port group event link function enable */
            group_enable |= (uint8_t) (1U << event_num);
        }

        /* Output port group operation */
        temp_value |= (uint8_t) (ex_cfg->p_port_group_output_cfg[event_num].operation << R_GPIO_ELC_PGC_PGCO_Pos);

        /* Set to port group control register */
        p_ioport_regs->ELC_PGC[event_num] = temp_value;
    }

    /* Set to ELC port event control register */
    p_ioport_regs->PFC_ELC_ELSR2 =
        (uint8_t) ((single_enable << R_GPIO_PFC_ELC_ELSR2_PES_Pos) | (group_enable << R_GPIO_PFC_ELC_ELSR2_PEG_Pos));

    R_BSP_PinAccessDisable();          // lock Register Write Protection
#endif
}
