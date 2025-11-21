/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_TSU_B_H
#define BSP_TSU_B_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * @addtogroup BSP_MPU_RZG3E
 * @{
 *********************************************************************************************************************/
#define TSU_B_CALIBRAION_DATA_MASK               (0xFFFU)

/* Read calibration data */
#define R_BSP_TSU_B_Read_CalibrationData(unit, data1, data2)                                             \
    do                                                                                                   \
    {                                                                                                    \
        static volatile uint32_t * const gp_calibration_low_temparature[] =                              \
        {                                                                                                \
            [1] = (uint32_t *) &R_SYSC->SYS_LSI_OTPTSU1TRMVAL0,                                          \
        };                                                                                               \
                                                                                                         \
        static uint32_t volatile * const gp_calibration_high_temparature[] =                             \
        {                                                                                                \
            [1] = (uint32_t *) &R_SYSC->SYS_LSI_OTPTSU1TRMVAL1,                                          \
        };                                                                                               \
                                                                                                         \
        *(data1) = (uint32_t)(*gp_calibration_low_temparature[unit] & TSU_B_CALIBRAION_DATA_MASK);       \
        *(data2) = (uint32_t)(*gp_calibration_high_temparature[unit] & TSU_B_CALIBRAION_DATA_MASK);      \
    } while (0)

/** @} (end addtogroup BSP_MPU_RZG3E) */

#endif                                 /* BSP_TSU_B_H */
