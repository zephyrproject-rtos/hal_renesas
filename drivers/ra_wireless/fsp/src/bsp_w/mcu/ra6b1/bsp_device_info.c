/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "../all/internal/bsp_device_definitions_internal.h"

/* #include "all/sys_man/include/sys_tcs.h" */
#ifdef UNIT_TESTING
 #include "fake_regs.h"
#endif

#if 0
 #include <stdint.h>
 #include "hw_cpm.h"
 #include "hw_clk.h"
 #include "hw_pd.h"
 #include "hw_sys.h"
 #include "hw_sys_internal.h"
 #include "hw_gpio.h"
 #include "sys_tcs.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**
 * \brief The number of register addresses to check if they are configured in CS
 *
 * \sa hw_sys_apply_default_values
 */
 #define NUM_OF_REG_ADDR_IN_CS    2
#endif

/*
 * These macros are used to match the values of the CHIP_IDx_REG registers
 * in order to detect the DEVICE_CHIP_ID.
 */
#define ASCII_3108                0x33313038 // '3' '1' '0' '8'

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*
 * The bsp_prv_device_info word contains all device's information attributes detected at runtime.
 * It is populated according to the schema described in bsp_device_definitions_internal.h.
 */
TESTABLE_STATIC bsp_device_info_t bsp_prv_device_info BSP_PLACE_IN_SECTION(BSP_SECTION_NOINIT);

#if 0
uint32_t hw_sys_pd_com_acquire_cnt;
uint32_t hw_sys_pd_periph_acquire_cnt;
#endif

#if 0
 #if (EXCEPTION_DEBUG == 1)
void hw_sys_assert_trigger_gpio (void)
{
    hw_pd_power_up_com();
    if (dg_configLP_CLK_SOURCE == LP_CLK_IS_DIGITAL)
    {
        hw_clk_configure_ext32k_pins();
    }

    DBG_SET_HIGH(EXCEPTION_DEBUG, EXCEPTIONDBG);
}

 #endif

__RETAINED_CODE void hw_sys_pd_com_enable (void)
{
    GLOBAL_INT_DISABLE();
    ASSERT_ERROR((!hw_sys_pd_com_acquire_cnt) || !REG_GETF(CRG_TOP, PMU_CTRL_REG, COM_SLEEP));
    ASSERT_ERROR((hw_sys_pd_com_acquire_cnt) || REG_GETF(CRG_TOP, PMU_CTRL_REG, COM_SLEEP));
    if (++hw_sys_pd_com_acquire_cnt == 1)
    {
        hw_pd_power_up_com();
    }

    GLOBAL_INT_RESTORE();

    ASSERT_ERROR(REG_GETF(CRG_TOP, SYS_STAT_REG, COM_IS_UP));
}

__RETAINED_CODE void hw_sys_pd_com_disable (void)
{
    ASSERT_ERROR(!REG_GETF(CRG_TOP, PMU_CTRL_REG, COM_SLEEP));

    GLOBAL_INT_DISABLE();
    ASSERT_ERROR(hw_sys_pd_com_acquire_cnt);
    if (--hw_sys_pd_com_acquire_cnt == 0)
    {
        hw_pd_power_down_com();
    }

    GLOBAL_INT_RESTORE();
}

__RETAINED_CODE void hw_sys_pd_periph_enable (void)
{
    GLOBAL_INT_DISABLE();
    if (++hw_sys_pd_periph_acquire_cnt == 1)
    {
        hw_pd_power_up_periph();
    }

    GLOBAL_INT_RESTORE();

    ASSERT_ERROR(REG_GETF(CRG_TOP, SYS_STAT_REG, PER_IS_UP));
}

__RETAINED_CODE void hw_sys_pd_periph_disable (void)
{
    ASSERT_ERROR(!REG_GETF(CRG_TOP, PMU_CTRL_REG, PERIPH_SLEEP));

    GLOBAL_INT_DISABLE();
    ASSERT_ERROR(hw_sys_pd_periph_acquire_cnt);
    if (--hw_sys_pd_periph_acquire_cnt == 0)
    {
        hw_pd_power_down_periph();
    }

    GLOBAL_INT_RESTORE();
}

void hw_sys_apply_default_values (void)
{
    const uint32_t reg_in_cs[NUM_OF_REG_ADDR_IN_CS] =
    {
        (uint32_t) &CRG_XTAL->CLK_FREQ_TRIM_REG,
        (uint32_t) &CRG_XTAL->XTAL32M_CTRL0_REG
    };

    bool is_reg_trimmed[NUM_OF_REG_ADDR_IN_CS] = {false};

    // TODO: Add this as a preferred setting
    REG_SETF(CRG_XTAL, XTALRDY_CTRL_REG, XTALRDY_CLK_SEL, 0);

    // Check for plain register entries
    if (sys_tcs_reg_pairs_in_cs(reg_in_cs, NUM_OF_REG_ADDR_IN_CS, is_reg_trimmed))
    {
        return;
    }

    if (!is_reg_trimmed[0])
    {
        REG_SETF(CRG_XTAL, CLK_FREQ_TRIM_REG, XTAL32M_TRIM, dg_configDEFAULT_CLK_FREQ_TRIM_REG__XTAL32M_TRIM__VALUE);
    }

    if (!is_reg_trimmed[1])
    {
        REG_SETF(CRG_XTAL,
                 XTAL32M_CTRL0_REG,
                 XTAL32M_CXCOMP_ENABLE,
                 dg_configDEFAULT_XTAL32M_CTRL0_REG__XTAL32M_CXCOMP_ENABLE__VALUE);
    }
}

#endif
#if 0

/* Get device variant ID as stored in TCS. */
static uint32_t get_device_variant (void)
{
    uint32_t * variant = NULL;
    uint8_t    size    = 0;

    bsp_tcs_trim_values_get(BSP_TCS_GID_CHIP_ID, &variant, &size);

    if ((size == 1) && (variant != NULL))
    {

        /* The Device Variant entry has been successfully retrieved */
        return MAKE_DEVICE_VARIANT_ENCODING(variant[0]);
    }

    return 0;
}

#endif

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup BSP_MCU_PRV Internal BSP Documentation
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

/**
 * @brief       Populate bsp_sys_device_info_data with device information retrieved from the
 *              corresponding chip registers (Family, Device Chip ID, Revision and Step)
 *
 * @return      True, if the retrieved information is valid, otherwise false.
 */
bool bsp_device_info_init (void)
{
    union
    {
        uint8_t  arr[4];
        uint32_t value;
    } device_chip_id;

    // XXX: The device revision and step fields are stored in ASCII format in the CHIP_VERSION
    // XXX: registers. To update bsp_prv_device_info, using the device information
    // XXX: attribute macros, they must be converted to numerical values. i.e. the 'A' value has
    // XXX: to be subtracted from them.
    uint32_t revision = MAKE_DEVICE_REVISION_ENCODING(CHIP_VERSION->CHIP_REVISION_REG_b.CHIP_REVISION - 'A');
    uint32_t step     = MAKE_DEVICE_STEP_ENCODING(CHIP_VERSION->CHIP_TEST1_REG_b.CHIP_LAYOUT_REVISION - 'A');

    device_chip_id.arr[3] = CHIP_VERSION->CHIP_ID1_REG_b.CHIP_ID1;
    device_chip_id.arr[2] = CHIP_VERSION->CHIP_ID2_REG_b.CHIP_ID2;
    device_chip_id.arr[1] = CHIP_VERSION->CHIP_ID3_REG_b.CHIP_ID3;
    device_chip_id.arr[0] = CHIP_VERSION->CHIP_ID4_REG_b.CHIP_ID4;

    switch (device_chip_id.value)
    {
        case ASCII_3108:
        {
            device_chip_id.value = DEVICE_CHIP_ID_3108;
            break;
        }

        default:

            return false;
    }

    bsp_prv_device_info.value = RRQ431XX | device_chip_id.value | revision | step;

    return true;
}

/**
 * @brief       Populate bsp_prv_device_info with the device variant information retrieved from the
 *              corresponding TCS entry.
 *
 * @return      True, if the retrieved information is valid, otherwise false.
 */
bool bsp_device_variant_detect (void)
{
#if 0
    uint32_t variant = get_device_variant();

    if (0 == variant)
    {
        return false;
    }
    bsp_prv_device_info.value |= variant;
#endif

    return true;
}

/**
 * @brief       Check if a specific device information aspect matches the one of the target device.
 *
 * Use this function to check if a device information attribute equals to specific value using as input
 * arguments the public macros (not prefixed with underscore) defined in "bsp_device_definitions_internal.h".
 *
 * @param[in]   mask The device information attribute mask to be checked.
 * @param[in]   attribute The device information attribute value to compare with.
 *
 * @return      The result of comparison.
 *
 * Examples:
 *
 * @code
 * bool check;
 *
 * check = bsp_device_info_check(DEVICE_FAMILY_MASK, DA1468X);
 * check = bsp_device_info_check(DEVICE_FAMILY_MASK, DA1469X);
 *
 * check = bsp_device_info_check(DEVICE_VARIANT_MASK, DA14695);
 * check = bsp_device_info_check(DEVICE_VARIANT_MASK, DA14699);
 *
 * check = bsp_device_info_check(DEVICE_CHIP_ID_MASK, DEVICE_CHIP_ID_2522);
 * check = bsp_device_info_check(DEVICE_CHIP_ID_MASK, DEVICE_CHIP_ID_3080);
 *
 * check = bsp_device_info_check(DEVICE_REVISION_MASK, DEVICE_REV_A);
 * check = bsp_device_info_check(DEVICE_REVISION_MASK, DEVICE_REV_B);
 *
 * check = bsp_device_info_check(DEVICE_SWC_MASK, DEVICE_SWC_0);
 * check = bsp_device_info_check(DEVICE_SWC_MASK, DEVICE_SWC_1);
 *
 * check = bsp_device_info_check(DEVICE_STEP_MASK, DEVICE_STEP_A);
 * check = bsp_device_info_check(DEVICE_STEP_MASK, DEVICE_STEP_B);
 * check = bsp_device_info_check(DEVICE_STEP_MASK, DEVICE_STEP_C);
 * @endcode
 */
bool bsp_device_info_check (uint32_t mask, uint32_t attribute)
{
    uint32_t attribute_masked           = attribute & mask;
    uint32_t bsp_prv_device_info_masked = bsp_prv_device_info.value & mask;

    return bsp_prv_device_info_masked == attribute_masked;
}

/**
 * @brief       Get all the device information attributes that are populated.
 *
 * @return      hw_sys_device_info_data
 */
uint32_t bsp_device_info_get (void)
{
    return bsp_prv_device_info.value;
}

/**
 * @brief       Check that the firmware is compatible with the chip that it is running on.
 *
 * @return      True, if the chip version is compatible, otherwise false.
 */
bool bsp_device_info_compatibility_check (void)
{
    return true;

#if 0
    if (bsp_device_info_check(DEVICE_CHIP_ID_MASK, DEVICE_CHIP_ID_3108))
    {
        if (bsp_device_info_check(DEVICE_REVISION_MASK, DEVICE_REV_A) &&
            bsp_device_info_check(DEVICE_STEP_MASK, DEVICE_STEP_A))
        {
            return true;
        }
    }
    return false;
#endif
}

/** @} (end addtogroup BSP_MCU_PRV) */
