/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TSN_REG_H
#define R_TSN_REG_H

/* =========================================================================================================================== */
/* ================                                         R_TSN_CAL                                         ================ */
/* =========================================================================================================================== */

/**
 * @brief Temperature Sensor (R_TSN_CAL)
 */

typedef struct                         /*!< (@ 0x86C12DA0) R_TSN_CAL Structure                                        */
{
    union
    {
        __IM uint32_t TSCDR;           /*!< (@ 0x00000000) Temperature Sensor 32 bit Calibration Data Register        */

        struct
        {
            __IM uint32_t TSCDR : 32;  /*!< [31..0] The 32 bit TSCDR register stores temperature sensor
                                        *   calibration converted value.                                              */
        } TSCDR_b;
    };
} R_TSN_CAL_Type;                      /*!< Size = 4 (0x4)                                                            */

/* =========================================================================================================================== */
/* ================                                          R_TSN_CTRL                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Temperature Sensor (R_TSN_CTRL)
 */

typedef struct                         /*!< (@ 0x87835000) R_TSN_CTRL Structure                                          */
{
    union
    {
        __IOM uint8_t TSCR;            /*!< (@ 0x00000000) Temperature Sensor Control Register                        */

        struct
        {
            uint8_t            : 4;
            __IOM uint8_t TSOE : 1;    /*!< [4..4] Temperature Sensor Output Enable                                   */
            uint8_t            : 2;
            __IOM uint8_t TSEN : 1;    /*!< [7..7] Temperature Sensor Enable                                          */
        } TSCR_b;
    };
} R_TSN_CTRL_Type;                     /*!< Size = 1 (0x1)                                                            */

#endif                                 /* R_TSN_REG_H */
