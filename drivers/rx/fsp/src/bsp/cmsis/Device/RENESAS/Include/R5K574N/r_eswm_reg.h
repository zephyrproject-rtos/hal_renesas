/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ESWM_REG_H
#define R_ESWM_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_ESWM                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Layer 3 Ethernet Switch Module (R_ESWM)
 */

typedef struct                         /*!< (@ 0x874C8000) R_ESWM Structure                                           */
{
    union
    {
        __IOM uint32_t TPEMIMC0;       /*!< (@ 0x00000000) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 0 (TPEMIMC0)                        */

        struct
        {
            __IOM uint32_t SEIM   : 1; /*!< [0..0] SEIM                                                               */
            __IOM uint32_t SEIGM  : 1; /*!< [1..1] SEIGM                                                              */
            uint32_t              : 2;
            __IOM uint32_t SEICM  : 3; /*!< [6..4] SEICM                                                              */
            uint32_t              : 9;
            __IOM uint32_t SSIM0  : 1; /*!< [16..16] SSIM0                                                            */
            __IOM uint32_t SSIGM0 : 1; /*!< [17..17] SSIGM0                                                           */
            uint32_t              : 2;
            __IOM uint32_t SSICM0 : 3; /*!< [22..20] SSICM0                                                           */
            uint32_t              : 1;
            __IOM uint32_t SSIM1  : 1; /*!< [24..24] SSIM1                                                            */
            __IOM uint32_t SSIGM1 : 1; /*!< [25..25] SSIGM1                                                           */
            uint32_t              : 2;
            __IOM uint32_t SSICM1 : 3; /*!< [30..28] SSICM1                                                           */
            uint32_t              : 1;
        } TPEMIMC0_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC1;       /*!< (@ 0x00000004) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 1 (TPEMIMC1)                        */

        struct
        {
            __IOM uint32_t FEIM  : 1;  /*!< [0..0] FEIM                                                               */
            __IOM uint32_t FEIGM : 1;  /*!< [1..1] FEIGM                                                              */
            uint32_t             : 2;
            __IOM uint32_t FEICM : 3;  /*!< [6..4] FEICM                                                              */
            uint32_t             : 1;
            __IOM uint32_t FSIM  : 1;  /*!< [8..8] FSIM                                                               */
            __IOM uint32_t FSIGM : 1;  /*!< [9..9] FSIGM                                                              */
            uint32_t             : 2;
            __IOM uint32_t FSICM : 3;  /*!< [14..12] FSICM                                                            */
            uint32_t             : 1;
            __IOM uint32_t CEIM  : 1;  /*!< [16..16] CEIM                                                             */
            __IOM uint32_t CEIGM : 1;  /*!< [17..17] CEIGM                                                            */
            uint32_t             : 2;
            __IOM uint32_t CEICM : 3;  /*!< [22..20] CEICM                                                            */
            uint32_t             : 1;
            __IOM uint32_t CSIM  : 1;  /*!< [24..24] CSIM                                                             */
            __IOM uint32_t CSIGM : 1;  /*!< [25..25] CSIGM                                                            */
            uint32_t             : 2;
            __IOM uint32_t CSICM : 3;  /*!< [30..28] CSICM                                                            */
            uint32_t             : 1;
        } TPEMIMC1_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC2;       /*!< (@ 0x00000008) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 2 (TPEMIMC2)                        */

        struct
        {
            __IOM uint32_t GEIM0  : 1; /*!< [0..0] GEIM0                                                              */
            __IOM uint32_t GEIGM0 : 1; /*!< [1..1] GEIGM0                                                             */
            uint32_t              : 2;
            __IOM uint32_t GEICM0 : 3; /*!< [6..4] GEICM0                                                             */
            uint32_t              : 1;
            __IOM uint32_t GSIM0  : 1; /*!< [8..8] GSIM0                                                              */
            __IOM uint32_t GSIGM0 : 1; /*!< [9..9] GSIGM0                                                             */
            uint32_t              : 2;
            __IOM uint32_t GSICM0 : 3; /*!< [14..12] GSICM0                                                           */
            uint32_t              : 1;
            __IOM uint32_t GEIM1  : 1; /*!< [16..16] GEIM1                                                            */
            uint32_t              : 15;
        } TPEMIMC2_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC3;       /*!< (@ 0x0000000C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 3 (TPEMIMC3)                        */

        struct
        {
            __IOM uint32_t EEIM0  : 1; /*!< [0..0] EEIM0                                                              */
            __IOM uint32_t EEIGM0 : 1; /*!< [1..1] EEIGM0                                                             */
            uint32_t              : 2;
            __IOM uint32_t EEICM0 : 3; /*!< [6..4] EEICM0                                                             */
            uint32_t              : 1;
            __IOM uint32_t ESIM0  : 1; /*!< [8..8] ESIM0                                                              */
            __IOM uint32_t ESIGM0 : 1; /*!< [9..9] ESIGM0                                                             */
            uint32_t              : 2;
            __IOM uint32_t ESICM0 : 3; /*!< [14..12] ESICM0                                                           */
            uint32_t              : 1;
            __IOM uint32_t RSIM0  : 1; /*!< [16..16] RSIM0                                                            */
            __IOM uint32_t RSIGM0 : 1; /*!< [17..17] RSIGM0                                                           */
            uint32_t              : 2;
            __IOM uint32_t RSICM0 : 3; /*!< [22..20] RSICM0                                                           */
            uint32_t              : 9;
        } TPEMIMC3_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC4;       /*!< (@ 0x00000010) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 4 (TPEMIMC4)                        */

        struct
        {
            __IOM uint32_t EEIM1  : 1; /*!< [0..0] EEIM1                                                              */
            __IOM uint32_t EEIGM1 : 1; /*!< [1..1] EEIGM1                                                             */
            uint32_t              : 2;
            __IOM uint32_t EEICM1 : 3; /*!< [6..4] EEICM1                                                             */
            uint32_t              : 1;
            __IOM uint32_t ESIM1  : 1; /*!< [8..8] ESIM1                                                              */
            __IOM uint32_t ESIGM1 : 1; /*!< [9..9] ESIGM1                                                             */
            uint32_t              : 2;
            __IOM uint32_t ESICM1 : 3; /*!< [14..12] ESICM1                                                           */
            uint32_t              : 1;
            __IOM uint32_t RSIM1  : 1; /*!< [16..16] RSIM1                                                            */
            __IOM uint32_t RSIGM1 : 1; /*!< [17..17] RSIGM1                                                           */
            uint32_t              : 2;
            __IOM uint32_t RSICM1 : 3; /*!< [22..20] RSICM1                                                           */
            uint32_t              : 9;
        } TPEMIMC4_b;
    };
    __IM uint32_t RESERVED[27];

    union
    {
        __IOM uint32_t TPEMIMC60;       /*!< (@ 0x00000080) TOP Module Error and Monitoring Interrupt Mapping
                                         *                  Configuration Register 6t (TPEMIMC6t) (t
                                         *                  = 0, 1)                                                    */

        struct
        {
            __IOM uint32_t GTSIM0  : 1; /*!< [0..0] GTSIM0                                                             */
            __IOM uint32_t GTSICM0 : 3; /*!< [3..1] GTSICM0                                                            */
            uint32_t               : 28;
        } TPEMIMC60_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC61;       /*!< (@ 0x00000084) TOP Module Error and Monitoring Interrupt Mapping
                                         *                  Configuration Register 6t (TPEMIMC6t) (t
                                         *                  = 0, 1)                                                    */

        struct
        {
            __IOM uint32_t GTSIM0  : 1; /*!< [0..0] GTSIM0                                                             */
            __IOM uint32_t GTSICM0 : 3; /*!< [3..1] GTSICM0                                                            */
            uint32_t               : 28;
        } TPEMIMC61_b;
    };
    __IM uint32_t RESERVED1[30];

    union
    {
        __IOM uint32_t TPEMIMC70;      /*!< (@ 0x00000100) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 5;
            __IOM uint32_t GDICM1 : 3; /*!< [10..8] GDICM1                                                            */
            uint32_t              : 21;
        } TPEMIMC70_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC71;      /*!< (@ 0x00000104) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 5;
            __IOM uint32_t GDICM1 : 3; /*!< [10..8] GDICM1                                                            */
            uint32_t              : 21;
        } TPEMIMC71_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC72;      /*!< (@ 0x00000108) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 5;
            __IOM uint32_t GDICM1 : 3; /*!< [10..8] GDICM1                                                            */
            uint32_t              : 21;
        } TPEMIMC72_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC73;      /*!< (@ 0x0000010C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 5;
            __IOM uint32_t GDICM1 : 3; /*!< [10..8] GDICM1                                                            */
            uint32_t              : 21;
        } TPEMIMC73_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC74;      /*!< (@ 0x00000110) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 5;
            __IOM uint32_t GDICM1 : 3; /*!< [10..8] GDICM1                                                            */
            uint32_t              : 21;
        } TPEMIMC74_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC75;      /*!< (@ 0x00000114) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 5;
            __IOM uint32_t GDICM1 : 3; /*!< [10..8] GDICM1                                                            */
            uint32_t              : 21;
        } TPEMIMC75_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC76;      /*!< (@ 0x00000118) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 5;
            __IOM uint32_t GDICM1 : 3; /*!< [10..8] GDICM1                                                            */
            uint32_t              : 21;
        } TPEMIMC76_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC77;      /*!< (@ 0x0000011C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 5;
            __IOM uint32_t GDICM1 : 3; /*!< [10..8] GDICM1                                                            */
            uint32_t              : 21;
        } TPEMIMC77_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC78;      /*!< (@ 0x00000120) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 5;
            __IOM uint32_t GDICM1 : 3; /*!< [10..8] GDICM1                                                            */
            uint32_t              : 21;
        } TPEMIMC78_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC79;      /*!< (@ 0x00000124) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 5;
            __IOM uint32_t GDICM1 : 3; /*!< [10..8] GDICM1                                                            */
            uint32_t              : 21;
        } TPEMIMC79_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC710;     /*!< (@ 0x00000128) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC710_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC711;     /*!< (@ 0x0000012C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC711_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC712;     /*!< (@ 0x00000130) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC712_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC713;     /*!< (@ 0x00000134) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC713_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC714;     /*!< (@ 0x00000138) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC714_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC715;     /*!< (@ 0x0000013C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC715_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC716;     /*!< (@ 0x00000140) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC716_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC717;     /*!< (@ 0x00000144) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC717_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC718;     /*!< (@ 0x00000148) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC718_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC719;     /*!< (@ 0x0000014C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC719_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC720;     /*!< (@ 0x00000150) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC720_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC721;     /*!< (@ 0x00000154) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC721_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC722;     /*!< (@ 0x00000158) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC722_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC723;     /*!< (@ 0x0000015C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC723_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC724;     /*!< (@ 0x00000160) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC724_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC725;     /*!< (@ 0x00000164) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC725_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC726;     /*!< (@ 0x00000168) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC726_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC727;     /*!< (@ 0x0000016C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC727_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC728;     /*!< (@ 0x00000170) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC728_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC729;     /*!< (@ 0x00000174) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC729_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC730;     /*!< (@ 0x00000178) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC730_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC731;     /*!< (@ 0x0000017C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC731_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC732;     /*!< (@ 0x00000180) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC732_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC733;     /*!< (@ 0x00000184) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC733_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC734;     /*!< (@ 0x00000188) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC734_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC735;     /*!< (@ 0x0000018C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC735_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC736;     /*!< (@ 0x00000190) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC736_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC737;     /*!< (@ 0x00000194) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC737_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC738;     /*!< (@ 0x00000198) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC738_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC739;     /*!< (@ 0x0000019C) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC739_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC740;     /*!< (@ 0x000001A0) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC740_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC741;     /*!< (@ 0x000001A4) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC741_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC742;     /*!< (@ 0x000001A8) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC742_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC743;     /*!< (@ 0x000001AC) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC743_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC744;     /*!< (@ 0x000001B0) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC744_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC745;     /*!< (@ 0x000001B4) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC745_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC746;     /*!< (@ 0x000001B8) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC746_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC747;     /*!< (@ 0x000001BC) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC747_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC748;     /*!< (@ 0x000001C0) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC748_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC749;     /*!< (@ 0x000001C4) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC749_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC750;     /*!< (@ 0x000001C8) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC750_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC751;     /*!< (@ 0x000001CC) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC751_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC752;     /*!< (@ 0x000001D0) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC752_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC753;     /*!< (@ 0x000001D4) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC753_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC754;     /*!< (@ 0x000001D8) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC754_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC755;     /*!< (@ 0x000001DC) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC755_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC756;     /*!< (@ 0x000001E0) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC756_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC757;     /*!< (@ 0x000001E4) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC757_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC758;     /*!< (@ 0x000001E8) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC758_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC759;     /*!< (@ 0x000001EC) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC759_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC760;     /*!< (@ 0x000001F0) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC760_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC761;     /*!< (@ 0x000001F4) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC761_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC762;     /*!< (@ 0x000001F8) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC762_b;
    };

    union
    {
        __IOM uint32_t TPEMIMC763;     /*!< (@ 0x000001FC) TOP Module Error and Monitoring Interrupt Mapping
                                        *                  Configuration Register 6t (TPEMIMC7t) (t
                                        *                  = 0 to 63)                                                 */

        struct
        {
            __IOM uint32_t GDICM0 : 3; /*!< [2..0] GDICM0                                                             */
            uint32_t              : 29;
        } TPEMIMC763_b;
    };
    __IM uint32_t RESERVED2[320];

    union
    {
        __IOM uint32_t TSIM;           /*!< (@ 0x00000700) TOP Module Switch Interrupt Mirroring Register
                                        *                  (TSIM)                                                     */

        struct
        {
            __IOM uint32_t FWM  : 1;   /*!< [0..0] FWM                                                                */
            __IOM uint32_t CIM  : 1;   /*!< [1..1] CIM                                                                */
            __IOM uint32_t GIM0 : 1;   /*!< [2..2] GIM0                                                               */
            uint32_t            : 1;
            __IOM uint32_t EIM0 : 1;   /*!< [4..4] EIM0                                                               */
            __IOM uint32_t EIM1 : 1;   /*!< [5..5] EIM1                                                               */
            uint32_t            : 26;
        } TSIM_b;
    };

    union
    {
        __IOM uint32_t TFIM;             /*!< (@ 0x00000704) TOP Module Forwarding Engine Interrupt Mirroring
                                          *                  Register (TFIM)                                            */

        struct
        {
            __IOM uint32_t FWEISIM0 : 1; /*!< [0..0] FWEISIM0                                                           */
            __IOM uint32_t FWEISIM1 : 1; /*!< [1..1] FWEISIM1                                                           */
            __IOM uint32_t FWEISIM2 : 1; /*!< [2..2] FWEISIM2                                                           */
            __IOM uint32_t FWEISIM3 : 1; /*!< [3..3] FWEISIM3                                                           */
            __IOM uint32_t FWEISIM4 : 1; /*!< [4..4] FWEISIM4                                                           */
            __IOM uint32_t FWEISIM5 : 1; /*!< [5..5] FWEISIM5                                                           */
            __IOM uint32_t FWEISIM6 : 1; /*!< [6..6] FWEISIM6                                                           */
            __IOM uint32_t FWEISIM7 : 1; /*!< [7..7] FWEISIM7                                                           */
            __IOM uint32_t FWEISIM8 : 1; /*!< [8..8] FWEISIM8                                                           */
            __IOM uint32_t FWMISIM0 : 1; /*!< [9..9] FWMISIM0                                                           */
            uint32_t                : 22;
        } TFIM_b;
    };

    union
    {
        __IOM uint32_t TCIM;             /*!< (@ 0x00000708) TOP Module Common Interrupt Mirroring Register
                                          *                  (TCIM)                                                     */

        struct
        {
            __IOM uint32_t RSSISIM  : 1; /*!< [0..0] RSSISIM                                                            */
            __IOM uint32_t CAEISIM0 : 1; /*!< [1..1] CAEISIM0                                                           */
            __IOM uint32_t CAEISIM1 : 1; /*!< [2..2] CAEISIM1                                                           */
            __IOM uint32_t CAMISIM0 : 1; /*!< [3..3] CAMISIM0                                                           */
            __IOM uint32_t CAMISIM1 : 1; /*!< [4..4] CAMISIM1                                                           */
            uint32_t                : 27;
        } TCIM_b;
    };
    __IM uint32_t RESERVED3;

    union
    {
        __IOM uint32_t TGIM0;             /*!< (@ 0x00000710) TOP Module GWCA0 Interrupt Mirroring Register
                                           *                  (TGIM0)                                                    */

        struct
        {
            __IOM uint32_t GWDISIM   : 1; /*!< [0..0] GWDISIM                                                            */
            __IOM uint32_t GWTSDISIM : 1; /*!< [1..1] GWTSDISIM                                                          */
            __IOM uint32_t GWEISIM0  : 1; /*!< [2..2] GWEISIM0                                                           */
            __IOM uint32_t GWEISIM1  : 1; /*!< [3..3] GWEISIM1                                                           */
            __IOM uint32_t GWEISIM2  : 1; /*!< [4..4] GWEISIM2                                                           */
            __IOM uint32_t GWEISIM3  : 1; /*!< [5..5] GWEISIM3                                                           */
            __IOM uint32_t GWEISIM4  : 1; /*!< [6..6] GWEISIM4                                                           */
            __IOM uint32_t GWEISIM5  : 1; /*!< [7..7] GWEISIM5                                                           */
            uint32_t                 : 24;
        } TGIM0_b;
    };
    __IM uint32_t RESERVED4[3];

    union
    {
        __IOM uint32_t TEIM0;            /*!< (@ 0x00000720) TOP Module ETHA0 Interrupt Mirroring Register
                                          *                  (TEIM0)                                                    */

        struct
        {
            __IOM uint32_t EAEISIM0 : 1; /*!< [0..0] EAEISIM0                                                           */
            __IOM uint32_t EAEISIM1 : 1; /*!< [1..1] EAEISIM1                                                           */
            __IOM uint32_t EAEISIM2 : 1; /*!< [2..2] EAEISIM2                                                           */
            __IOM uint32_t MEISIM   : 1; /*!< [3..3] MEISIM                                                             */
            __IOM uint32_t MMISIM   : 1; /*!< [4..4] MMISIM                                                             */
            uint32_t                : 27;
        } TEIM0_b;
    };

    union
    {
        __IOM uint32_t TEIM1;            /*!< (@ 0x00000724) TOP Module ETHA1 Interrupt Mirroring Register
                                          *                  (TEIM1)                                                    */

        struct
        {
            __IOM uint32_t EAEISIM0 : 1; /*!< [0..0] EAEISIM0                                                           */
            __IOM uint32_t EAEISIM1 : 1; /*!< [1..1] EAEISIM1                                                           */
            __IOM uint32_t EAEISIM2 : 1; /*!< [2..2] EAEISIM2                                                           */
            __IOM uint32_t MEISIM   : 1; /*!< [3..3] MEISIM                                                             */
            __IOM uint32_t MMISIM   : 1; /*!< [4..4] MMISIM                                                             */
            uint32_t                : 27;
        } TEIM1_b;
    };
    __IM uint32_t RESERVED5[25398];

    union
    {
        __IOM uint32_t MIIRR;          /*!< (@ 0x00019400) Media Interface Reset Register                             */

        struct
        {
            __IOM uint32_t RGRST0 : 1; /*!< [0..0] RGMII Interface reset 0                                            */
            __IOM uint32_t RGRST1 : 1; /*!< [1..1] RGMII Interface reset 1                                            */
            uint32_t              : 6;
            __IOM uint32_t RMRST0 : 1; /*!< [8..8] RMII Interface reset 0                                             */
            __IOM uint32_t RMRST1 : 1; /*!< [9..9] RMII Interface reset 1                                             */
            uint32_t              : 22;
        } MIIRR_b;
    };

    union
    {
        __IOM uint32_t MIICR0;         /*!< (@ 0x00019404) Media Interface Control Register 0                         */

        struct
        {
            __IOM uint32_t MIISEL : 2; /*!< [1..0] MII select                                                         */
            uint32_t              : 6;
            __IOM uint32_t DIVSTP : 1; /*!< [8..8] Clock Divider Stop                                                 */
            uint32_t              : 3;
            __IOM uint32_t TXCIDE : 1; /*!< [12..12] TXC Internal delay enable in RGMII                               */
            uint32_t              : 19;
        } MIICR0_b;
    };

    union
    {
        __IOM uint32_t MIICR1;         /*!< (@ 0x00019408) Media Interface Control Register 1                         */

        struct
        {
            __IOM uint32_t MIISEL : 2; /*!< [1..0] MII select                                                         */
            uint32_t              : 6;
            __IOM uint32_t DIVSTP : 1; /*!< [8..8] Clock Divider Stop                                                 */
            uint32_t              : 3;
            __IOM uint32_t TXCIDE : 1; /*!< [12..12] TXC Internal delay enable in RGMII                               */
            uint32_t              : 19;
        } MIICR1_b;
    };
    __IM uint32_t RESERVED6;

    union
    {
        __IOM uint32_t MCCESR;         /*!< (@ 0x00019410) PTP Capture event select                                   */

        struct
        {
            __IOM uint32_t MCCES0 : 1; /*!< [0..0] Media clock capture event select 0                                 */
            __IOM uint32_t MCCES1 : 1; /*!< [1..1] Media clock capture event select 1                                 */
            uint32_t              : 30;
        } MCCESR_b;
    };
    __IM uint32_t RESERVED7[3];

    union
    {
        __IOM uint32_t TASSTSR;        /*!< (@ 0x00019420) TAS gate status monitor signal select register             */

        struct
        {
            __IOM uint32_t MSS0 : 5;   /*!< [4..0] Select signal to output ET_TAS_STA0 pin from race_etha0_tas_gate_state[
                                        *   :0] and race_etha1_tas_gate_state[8:0]                                    */
            uint32_t            : 3;
            __IOM uint32_t MSS1 : 5;   /*!< [12..8] Select signal to output ET_TAS_STA1 pin from race_etha0_tas_gate_state
                                        *   8:0] and race_etha1_tas_gate_state[8:0]                                   */
            uint32_t            : 3;
            __IOM uint32_t MSS2 : 5;   /*!< [20..16] Select signal to output ET_TAS_STA2 pin from race_etha0_tas_gate_stat
                                        *   [8:0] and race_etha1_tas_gate_state[8:0]                                  */
            uint32_t            : 3;
            __IOM uint32_t MSS3 : 5;   /*!< [28..24] Select signal to output ET_TAS_STA3 pin from race_etha0_tas_gate_stat
                                        *   [8:0] and race_etha1_tas_gate_state[8:0]                                  */
            uint32_t : 3;
        } TASSTSR_b;
    };
} R_ESWM_Type;                         /*!< Size = 103460 (0x19424)                                                   */

/** @} */ /* End of group Device_Peripheral_peripheralAddr */

#endif                                 /* R_ESWM_REG_H */
