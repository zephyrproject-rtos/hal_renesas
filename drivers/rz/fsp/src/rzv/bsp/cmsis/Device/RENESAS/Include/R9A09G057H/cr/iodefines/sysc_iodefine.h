/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : sysc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for sysc.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef SYSC_IODEFINE_H
#define SYSC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t SYS_MSTACCCTL0;
        struct
        {
            __IOM uint32_t SXMDMC_AWPU    : 1;
            __IOM uint32_t SXMDMC_AWNS    : 1;
            uint32_t                      : 1;
            __IOM uint32_t SXMDMC_AWSEL   : 1;
            __IOM uint32_t SXMDMC_ARPU    : 1;
            __IOM uint32_t SXMDMC_ARNS    : 1;
            uint32_t                      : 1;
            __IOM uint32_t SXMDMC_ARSEL   : 1;
            __IOM uint32_t SXADMC00_AWPU  : 1;
            __IOM uint32_t SXADMC00_AWNS  : 1;
            uint32_t                      : 1;
            __IOM uint32_t SXADMC00_AWSEL : 1;
            __IOM uint32_t SXADMC00_ARPU  : 1;
            __IOM uint32_t SXADMC00_ARNS  : 1;
            uint32_t                      : 1;
            __IOM uint32_t SXADMC00_ARSEL : 1;
            __IOM uint32_t SXADMC1_AWPU   : 1;
            __IOM uint32_t SXADMC1_AWNS   : 1;
            uint32_t                      : 1;
            __IOM uint32_t SXADMC1_AWSEL  : 1;
            __IOM uint32_t SXADMC1_ARPU   : 1;
            __IOM uint32_t SXADMC1_ARNS   : 1;
            uint32_t                      : 1;
            __IOM uint32_t SXADMC1_ARSEL  : 1;
            __IOM uint32_t SXRDMC0_AWPU   : 1;
            __IOM uint32_t SXRDMC0_AWNS   : 1;
            uint32_t                      : 1;
            __IOM uint32_t SXRDMC0_AWSEL  : 1;
            __IOM uint32_t SXRDMC0_ARPU   : 1;
            __IOM uint32_t SXRDMC0_ARNS   : 1;
            uint32_t                      : 1;
            __IOM uint32_t SXRDMC0_ARSEL  : 1;
        } SYS_MSTACCCTL0_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL1;
        struct
        {
            __IOM uint32_t SXMDMC1_AWPU  : 1;
            __IOM uint32_t SXMDMC1_AWNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t SXMDMC1_AWSEL : 1;
            __IOM uint32_t SXMDMC1_ARPU  : 1;
            __IOM uint32_t SXMDMC1_ARNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t SXMDMC1_ARSEL : 1;
            uint32_t                     : 24;
        } SYS_MSTACCCTL1_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL2;
        struct
        {
            __IOM uint32_t SXR80_AWPU  : 1;
            __IOM uint32_t SXR80_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXR80_AWSEL : 1;
            __IOM uint32_t SXR80_ARPU  : 1;
            __IOM uint32_t SXR80_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXR80_ARSEL : 1;
            __IOM uint32_t SXR81_AWPU  : 1;
            __IOM uint32_t SXR81_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXR81_AWSEL : 1;
            __IOM uint32_t SXR81_ARPU  : 1;
            __IOM uint32_t SXR81_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXR81_ARSEL : 1;
            __IOM uint32_t SXR8L_AWPU  : 1;
            __IOM uint32_t SXR8L_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXR8L_AWSEL : 1;
            __IOM uint32_t SXR8L_ARPU  : 1;
            __IOM uint32_t SXR8L_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXR8L_ARSEL : 1;
            uint32_t                   : 8;
        } SYS_MSTACCCTL2_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL3;
        struct
        {
            __IOM uint32_t SXSD0_AWPU  : 1;
            __IOM uint32_t SXSD0_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXSD0_AWSEL : 1;
            __IOM uint32_t SXSD0_ARPU  : 1;
            __IOM uint32_t SXSD0_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXSD0_ARSEL : 1;
            __IOM uint32_t SXSD1_AWPU  : 1;
            __IOM uint32_t SXSD1_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXSD1_AWSEL : 1;
            __IOM uint32_t SXSD1_ARPU  : 1;
            __IOM uint32_t SXSD1_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXSD1_ARSEL : 1;
            __IOM uint32_t SXSD2_AWPU  : 1;
            __IOM uint32_t SXSD2_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXSD2_AWSEL : 1;
            __IOM uint32_t SXSD2_ARPU  : 1;
            __IOM uint32_t SXSD2_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXSD2_ARSEL : 1;
            uint32_t                   : 8;
        } SYS_MSTACCCTL3_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL4;
        struct
        {
            __IOM uint32_t SXU3H0_AWPU  : 1;
            __IOM uint32_t SXU3H0_AWNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXU3H0_AWSEL : 1;
            __IOM uint32_t SXU3H0_ARPU  : 1;
            __IOM uint32_t SXU3H0_ARNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXU3H0_ARSEL : 1;
            __IOM uint32_t SXU3H1_AWPU  : 1;
            __IOM uint32_t SXU3H1_AWNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXU3H1_AWSEL : 1;
            __IOM uint32_t SXU3H1_ARPU  : 1;
            __IOM uint32_t SXU3H1_ARNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXU3H1_ARSEL : 1;
            uint32_t                    : 16;
        } SYS_MSTACCCTL4_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL5;
        struct
        {
            __IOM uint32_t SHU2H0_P0_AWPU   : 1;
            __IOM uint32_t SXHU2H0_P0_AWNS  : 1;
            uint32_t                        : 1;
            __IOM uint32_t SXHU2H0_P0_AWSEL : 1;
            __IOM uint32_t SXHU2H0_P0_ARPU  : 1;
            __IOM uint32_t SXHU2H0_P0_ARNS  : 1;
            uint32_t                        : 1;
            __IOM uint32_t SXHU2H0_P0_ARSEL : 1;
            __IOM uint32_t SXHU2H1_P1_AWPU  : 1;
            __IOM uint32_t SXHU2H1_P1_AWNS  : 1;
            uint32_t                        : 1;
            __IOM uint32_t SXHU2H1_P1_AWSEL : 1;
            __IOM uint32_t SXHU2H1_P1_ARPU  : 1;
            __IOM uint32_t SXHU2H1_P1_ARNS  : 1;
            uint32_t                        : 1;
            __IOM uint32_t SXHU2H1_P1_ARSEL : 1;
            __IOM uint32_t SHU2F_AWPU       : 1;
            __IOM uint32_t SHU2F_AWNS       : 1;
            uint32_t                        : 1;
            __IOM uint32_t SHU2F_AWSEL      : 1;
            __IOM uint32_t SHU2F_ARPU       : 1;
            __IOM uint32_t SHU2F_ARNS       : 1;
            uint32_t                        : 1;
            __IOM uint32_t SHU2F_ARSEL      : 1;
            uint32_t                        : 8;
        } SYS_MSTACCCTL5_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL6;
        struct
        {
            __IOM uint32_t SXGBE0_AWPU  : 1;
            __IOM uint32_t SXGBE0_AWNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXGBE0_AWSEL : 1;
            __IOM uint32_t SXGBE0_ARPU  : 1;
            __IOM uint32_t SXGBE0_ARNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXGBE0_ARSEL : 1;
            __IOM uint32_t SXGBE1_AWPU  : 1;
            __IOM uint32_t SXGBE1_AWNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXGBE1_AWSEL : 1;
            __IOM uint32_t SXGBE1_ARPU  : 1;
            __IOM uint32_t SXGBE1_ARNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXGBE1_ARSEL : 1;
            uint32_t                    : 16;
        } SYS_MSTACCCTL6_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL7;
        struct
        {
            __IOM uint32_t SXPCI0_AWPU  : 1;
            __IOM uint32_t SXPCI0_AWNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXPCI0_AWSEL : 1;
            __IOM uint32_t SXPCI0_ARPU  : 1;
            __IOM uint32_t SXPCI0_ARNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXPCI0_ARSEL : 1;
            __IOM uint32_t SXPCI1_AWPU  : 1;
            __IOM uint32_t SXPCI1_AWNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXPCI1_AWSEL : 1;
            __IOM uint32_t SXPCI1_ARPU  : 1;
            __IOM uint32_t SXPCI1_ARNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXPCI1_ARSEL : 1;
            uint32_t                    : 16;
        } SYS_MSTACCCTL7_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL8;
        struct
        {
            __IOM uint32_t SXCRV0_AWPU : 1;
            __IOM uint32_t SXCRV0_AWNS : 1;
            uint32_t                   : 6;
            __IOM uint32_t SXCRS0_AWPU : 1;
            __IOM uint32_t SXCRS0_AWNS : 1;
            uint32_t                   : 6;
            __IOM uint32_t SXCRV1_AWPU : 1;
            __IOM uint32_t SXCRV1_AWNS : 1;
            uint32_t                   : 6;
            __IOM uint32_t SXCRS1_AWPU : 1;
            __IOM uint32_t SXCRS1_AWNS : 1;
            uint32_t                   : 6;
        } SYS_MSTACCCTL8_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL9;
        struct
        {
            __IOM uint32_t SXCRV2_AWPU : 1;
            __IOM uint32_t SXCRV2_AWNS : 1;
            uint32_t                   : 6;
            __IOM uint32_t SXCRV3_AWPU : 1;
            __IOM uint32_t SXCRV3_AWNS : 1;
            uint32_t                   : 22;
        } SYS_MSTACCCTL9_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL10;
        struct
        {
            __IOM uint32_t SXISF_AWPU : 1;
            __IOM uint32_t SXISF_AWNS : 1;
            uint32_t                  : 6;
            __IOM uint32_t SXIST_AWPU : 1;
            __IOM uint32_t SXIST_AWNS : 1;
            uint32_t                  : 2;
            __IOM uint32_t SXIST_ARPU : 1;
            __IOM uint32_t SXIST_ARNS : 1;
            uint32_t                  : 6;
            __IOM uint32_t SXISV_ARPU : 1;
            __IOM uint32_t SXISV_ARNS : 1;
            uint32_t                  : 10;
        } SYS_MSTACCCTL10_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL11;
        struct
        {
            __IOM uint32_t SXISU_AWPU : 1;
            __IOM uint32_t SXISU_AWNS : 1;
            uint32_t                  : 2;
            __IOM uint32_t SXISU_ARPU : 1;
            __IOM uint32_t SXISU_ARNS : 1;
            uint32_t                  : 26;
        } SYS_MSTACCCTL11_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL12;
        struct
        {
            __IOM uint32_t SXDSI_AWPU  : 1;
            __IOM uint32_t SXDSI_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXDSI_AWSEL : 1;
            __IOM uint32_t SXDSI_ARPU  : 1;
            __IOM uint32_t SXDSI_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXDSI_ARSEL : 1;
            uint32_t                   : 24;
        } SYS_MSTACCCTL12_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL13;
        struct
        {
            __IOM uint32_t SXLCD_AWPU  : 1;
            __IOM uint32_t SXLCD_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXLCD_AWSEL : 1;
            __IOM uint32_t SXLCD_ARPU  : 1;
            __IOM uint32_t SXLCD_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXLCD_ARSEL : 1;
            uint32_t                   : 24;
        } SYS_MSTACCCTL13_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL14;
        struct
        {
            __IOM uint32_t SXGPU_AWPU  : 1;
            __IOM uint32_t SXGPU_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXGPU_AWSEL : 1;
            __IOM uint32_t SXGPU_ARPU  : 1;
            __IOM uint32_t SXGPU_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXGPU_ARSEL : 1;
            uint32_t                   : 24;
        } SYS_MSTACCCTL14_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL15;
        struct
        {
            __IOM uint32_t SXVCP_AWPU  : 1;
            __IOM uint32_t SXVCP_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXVCP_AWSEL : 1;
            __IOM uint32_t SXVCP_ARPU  : 1;
            __IOM uint32_t SXVCP_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXVCP_ARSEL : 1;
            uint32_t                   : 24;
        } SYS_MSTACCCTL15_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL16;
        struct
        {
            __IOM uint32_t SXDRP_AWPU  : 1;
            __IOM uint32_t SXDRP_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXDRP_AWSEL : 1;
            __IOM uint32_t SXDRP_ARPU  : 1;
            __IOM uint32_t SXDRP_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXDRP_ARSEL : 1;
            uint32_t                   : 24;
        } SYS_MSTACCCTL16_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL17;
        struct
        {
            __IOM uint32_t SXDRA_AWPU  : 1;
            __IOM uint32_t SXDRA_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXDRA_AWSEL : 1;
            __IOM uint32_t SXDRA_ARPU  : 1;
            __IOM uint32_t SXDRA_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SXDRA_ARSEL : 1;
            uint32_t                   : 24;
        } SYS_MSTACCCTL17_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL18;
        struct
        {
            __IOM uint32_t SXDRM0_AWPU  : 1;
            __IOM uint32_t SXDRM0_AWNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXDRM0_AWSEL : 1;
            __IOM uint32_t SXDRM0_ARPU  : 1;
            __IOM uint32_t SXDRM0_ARNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXDRM0_ARSEL : 1;
            __IOM uint32_t SXDRM1_AWPU  : 1;
            __IOM uint32_t SXDRM1_AWNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXDRM1_AWSEL : 1;
            __IOM uint32_t SXDRM1_ARPU  : 1;
            __IOM uint32_t SXDRM1_ARNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXDRM1_ARSEL : 1;
            uint32_t                    : 4;
            __IOM uint32_t SXDRW0_ARPU  : 1;
            __IOM uint32_t SXDRW0_ARNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXDRW0_ARSEL : 1;
            uint32_t                    : 4;
            __IOM uint32_t SXDRW1_ARPU  : 1;
            __IOM uint32_t SXDRW1_ARNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t SXDRW1_ARSEL : 1;
        } SYS_MSTACCCTL18_b;
    };
    __IM uint8_t RESERVED[180];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL0;
        struct
        {
            __IOM uint32_t MPCPG_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL0_b;
    };
    union
    {
        __IM uint32_t SYS_SLVACCCTL1;
        struct
        {
            __IM uint32_t MPSYS_SL : 2;
            uint32_t               : 30;
        } SYS_SLVACCCTL1_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL2;
        struct
        {
            __IOM uint32_t MPICU0_SL : 2;
            __IOM uint32_t MPICU1_SL : 2;
            uint32_t                 : 28;
        } SYS_SLVACCCTL2_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL3;
        struct
        {
            __IOM uint32_t MXMDMC_SL : 2;
            uint32_t                 : 30;
        } SYS_SLVACCCTL3_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL4;
        struct
        {
            __IOM uint32_t MPMSRM0_SL : 2;
            __IOM uint32_t MPMSRM1_SL : 2;
            uint32_t                  : 28;
        } SYS_SLVACCCTL4_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL5;
        struct
        {
            __IOM uint32_t MPCST_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL5_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL6;
        struct
        {
            __IOM uint32_t MPMHU_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL6_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL7;
        struct
        {
            __IOM uint32_t MOMCMT0_SL : 2;
            __IOM uint32_t MOMCMT1_SL : 2;
            __IOM uint32_t MOMCMT2_SL : 2;
            __IOM uint32_t MOMCMT3_SL : 2;
            __IOM uint32_t MPMOST0_SL : 2;
            __IOM uint32_t MPMOST1_SL : 2;
            uint32_t                  : 20;
        } SYS_SLVACCCTL7_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL8;
        struct
        {
            __IOM uint32_t MOMWDT_SL : 2;
            uint32_t                 : 30;
        } SYS_SLVACCCTL8_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL9;
        struct
        {
            __IOM uint32_t MORTC_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL9_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL10;
        struct
        {
            __IOM uint32_t MORTR_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL10_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL11;
        struct
        {
            __IOM uint32_t SPI_REG_SL : 2;
            uint32_t                  : 30;
        } SYS_SLVACCCTL11_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL12;
        struct
        {
            __IOM uint32_t MHGPO_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL12_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL13;
        struct
        {
            __IOM uint32_t MPPDM0_SL : 2;
            __IOM uint32_t MPPDM1_SL : 2;
            uint32_t                 : 28;
        } SYS_SLVACCCTL13_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL14;
        struct
        {
            __IOM uint32_t MOADC_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL14_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL15;
        struct
        {
            __IOM uint32_t MPMTSU0_SL : 2;
            uint32_t                  : 30;
        } SYS_SLVACCCTL15_b;
    };
    __IM uint8_t RESERVED1[4];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL17;
        struct
        {
            __IOM uint32_t MPCMA_SL : 2;
            __IOM uint32_t MPCMO_SL : 2;
            uint32_t                : 28;
        } SYS_SLVACCCTL17_b;
    };
    __IM uint8_t RESERVED2[4];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL19;
        struct
        {
            __IOM uint32_t MOSCF_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL19_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL20;
        struct
        {
            __IOM uint32_t MOMI2C_SL : 2;
            uint32_t                 : 30;
        } SYS_SLVACCCTL20_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL21;
        struct
        {
            __IOM uint32_t MPTSPI_SL : 2;
            __IOM uint32_t MPTM33_SL : 2;
            uint32_t                 : 28;
        } SYS_SLVACCCTL21_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL22;
        struct
        {
            __IOM uint32_t MXMGPV_SL         : 2;
            __IOM uint32_t MCPU_SYS_GPV_SL   : 2;
            __IOM uint32_t MCPU_PERI0_GPV_SL : 2;
            __IOM uint32_t MCPU_PERI1_GPV_SL : 2;
            __IOM uint32_t MCPU_PERI2_GPV_SL : 2;
            uint32_t                         : 22;
        } SYS_SLVACCCTL22_b;
    };
    __IM uint8_t RESERVED4[36];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL32;
        struct
        {
            __IOM uint32_t MXADMC0_SL : 2;
            __IOM uint32_t MXADMC1_SL : 2;
            uint32_t                  : 28;
        } SYS_SLVACCCTL32_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL33;
        struct
        {
            __IOM uint32_t MPASRM_SL  : 2;
            uint32_t                  : 4;
            __IOM uint32_t MPDSRM0_SL : 2;
            __IOM uint32_t MPDSRM1_SL : 2;
            __IOM uint32_t MPDSRM2_SL : 2;
            __IOM uint32_t MPDSRM3_SL : 2;
            __IOM uint32_t MPDSRM4_SL : 2;
            __IOM uint32_t MPDSRM5_SL : 2;
            __IOM uint32_t MPDSRM6_SL : 2;
            __IOM uint32_t MPDSRM7_SL : 2;
            uint32_t                  : 10;
        } SYS_SLVACCCTL33_b;
    };
    __IM uint8_t RESERVED5[4];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL35;
        struct
        {
            __IOM uint32_t MPSYC_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL35_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL36;
        struct
        {
            __IOM uint32_t MPAOST0_SL : 2;
            __IOM uint32_t MPAOST1_SL : 2;
            uint32_t                  : 28;
        } SYS_SLVACCCTL36_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL37;
        struct
        {
            __IOM uint32_t MOAWDT_SL : 2;
            uint32_t                 : 30;
        } SYS_SLVACCCTL37_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL38;
        struct
        {
            __IOM uint32_t MOAI2C0_SL : 2;
            __IOM uint32_t MOAI2C1_SL : 2;
            __IOM uint32_t MOAI2C2_SL : 2;
            __IOM uint32_t MOAI2C3_SL : 2;
            __IOM uint32_t MOAI2C4_SL : 2;
            __IOM uint32_t MOAI2C5_SL : 2;
            __IOM uint32_t MOAI2C6_SL : 2;
            __IOM uint32_t MOAI2C7_SL : 2;
            uint32_t                  : 16;
        } SYS_SLVACCCTL38_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL39;
        struct
        {
            __IOM uint32_t MXSD0_SL : 2;
            __IOM uint32_t MXSD1_SL : 2;
            __IOM uint32_t MXSD2_SL : 2;
            uint32_t                : 26;
        } SYS_SLVACCCTL39_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL40;
        struct
        {
            __IOM uint32_t MXU3H0_SL : 2;
            __IOM uint32_t MXU3H1_SL : 2;
            __IOM uint32_t MPU3P0_SL : 2;
            __IOM uint32_t MPU3P1_SL : 2;
            __IOM uint32_t MHU2H0_SL : 2;
            __IOM uint32_t MHU2H1_SL : 2;
            __IOM uint32_t MPU2P0_SL : 2;
            __IOM uint32_t MPU2P1_SL : 2;
            uint32_t                 : 16;
        } SYS_SLVACCCTL40_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL41;
        struct
        {
            __IOM uint32_t MXGBE0_SL : 2;
            __IOM uint32_t MXGBE1_SL : 2;
            uint32_t                 : 28;
        } SYS_SLVACCCTL41_b;
    };
    __IM uint8_t RESERVED6[4];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL43;
        struct
        {
            __IOM uint32_t MPDDM0_SL : 2;
            __IOM uint32_t MPDDM1_SL : 2;
            __IOM uint32_t MPDDP0_SL : 2;
            __IOM uint32_t MPDDP1_SL : 2;
            uint32_t                 : 24;
        } SYS_SLVACCCTL43_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL44;
        struct
        {
            __IOM uint32_t MPCRU0_SL : 2;
            __IOM uint32_t MPCRU1_SL : 2;
            __IOM uint32_t MPCRU2_SL : 2;
            __IOM uint32_t MPCRU3_SL : 2;
            uint32_t                 : 24;
        } SYS_SLVACCCTL44_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL45;
        struct
        {
            __IOM uint32_t MPISP_SL : 2;
            __IOM uint32_t MXISP_SL : 2;
            uint32_t                : 28;
        } SYS_SLVACCCTL45_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL46;
        struct
        {
            __IOM uint32_t MPISU_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL46_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL47;
        struct
        {
            __IOM uint32_t MPDSD_SL : 2;
            __IOM uint32_t MPDSL_SL : 2;
            uint32_t                : 28;
        } SYS_SLVACCCTL47_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL48;
        struct
        {
            __IOM uint32_t MPLCD_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL48_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL49;
        struct
        {
            __IOM uint32_t MXGPU_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL49_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL50;
        struct
        {
            __IOM uint32_t MPVCC_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL50_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL51;
        struct
        {
            __IOM uint32_t MPSSIU_SL    : 2;
            __IOM uint32_t MPSSIUDMC_SL : 2;
            __IOM uint32_t MPADMC_SL    : 2;
            uint32_t                    : 26;
        } SYS_SLVACCCTL51_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL52;
        struct
        {
            __IOM uint32_t MOSPD0_SL : 2;
            __IOM uint32_t MOSPD1_SL : 2;
            __IOM uint32_t MOSPD2_SL : 2;
            uint32_t                 : 26;
        } SYS_SLVACCCTL52_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL53;
        struct
        {
            __IOM uint32_t MPSCU_SL    : 2;
            __IOM uint32_t MPSCUDMC_SL : 2;
            __IOM uint32_t MPADG_SL    : 2;
            uint32_t                   : 26;
        } SYS_SLVACCCTL53_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL54;
        struct
        {
            __IOM uint32_t MXDRP_SL : 2;
            __IOM uint32_t MXDRA_SL : 2;
            __IOM uint32_t MXDRS_SL : 2;
            uint32_t                : 26;
        } SYS_SLVACCCTL54_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL55;
        struct
        {
            __IOM uint32_t MXGIC_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL55_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL56;
        struct
        {
            __IOM uint32_t MPMTSU1_SL : 2;
            uint32_t                  : 30;
        } SYS_SLVACCCTL56_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL57;
        struct
        {
            __IOM uint32_t MPTA55_SL  : 2;
            __IOM uint32_t MPTR8_SL   : 2;
            __IOM uint32_t MPTDD00_SL : 2;
            __IOM uint32_t MPTDD01_SL : 2;
            __IOM uint32_t MPTDD10_SL : 2;
            __IOM uint32_t MPTDD11_SL : 2;
            __IOM uint32_t MPTPCI_SL  : 2;
            uint32_t                  : 18;
        } SYS_SLVACCCTL57_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL58;
        struct
        {
            __IOM uint32_t MXV0GPV_SL        : 2;
            __IOM uint32_t MXV1GPV_SL        : 2;
            __IOM uint32_t MXDPGPV_SL        : 2;
            __IOM uint32_t MXCMGPV_SL        : 2;
            __IOM uint32_t MXACGPV_SL        : 2;
            __IOM uint32_t ACPU_PERI0_GPV_SL : 2;
            __IOM uint32_t ACPU_PERI1_GPV_SL : 2;
            __IOM uint32_t MXACR0GPV_SL      : 2;
            __IOM uint32_t MXACR1GPV_SL      : 2;
            __IOM uint32_t ACPU_REG2_GPV_SL  : 2;
            uint32_t                         : 12;
        } SYS_SLVACCCTL58_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL59;
        struct
        {
            __IOM uint32_t ACPU_PERIVIDEO0_GPV_SL : 2;
            __IOM uint32_t ACPU_PERIVIDEO1_GPV_SL : 2;
            __IOM uint32_t ACPU_PERIDRP0_GPV_SL   : 2;
            __IOM uint32_t ACPU_PERIDRP1_GPV_SL   : 2;
            __IOM uint32_t ACPU_PERICOM0_GPV_SL   : 2;
            __IOM uint32_t ACPU_PERICOM1_GPV_SL   : 2;
            __IOM uint32_t ACPU_PERIDDR_GPV_SL    : 2;
            __IOM uint32_t MXCMSGPV_SL            : 2;
            __IOM uint32_t ACPU_PERICOM2_GPV_SL   : 2;
            uint32_t                              : 14;
        } SYS_SLVACCCTL59_b;
    };
    __IM uint8_t RESERVED8[16];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL64;
        struct
        {
            __IOM uint32_t MOCRC_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL64_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL65;
        struct
        {
            __IOM uint32_t MOGPT0_SL : 2;
            __IOM uint32_t MOGPT1_SL : 2;
            uint32_t                 : 28;
        } SYS_SLVACCCTL65_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL66;
        struct
        {
            __IOM uint32_t MOPOE0_SL : 2;
            __IOM uint32_t MOPOE1_SL : 2;
            __IOM uint32_t MOPOE2_SL : 2;
            __IOM uint32_t MOPOE3_SL : 2;
            __IOM uint32_t MOPOE4_SL : 2;
            __IOM uint32_t MOPOE5_SL : 2;
            __IOM uint32_t MOPOE6_SL : 2;
            __IOM uint32_t MOPOE7_SL : 2;
            uint32_t                 : 16;
        } SYS_SLVACCCTL66_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL67;
        struct
        {
            __IOM uint32_t MORCMT0_SL : 2;
            __IOM uint32_t MORCMT1_SL : 2;
            __IOM uint32_t MORCMT2_SL : 2;
            __IOM uint32_t MORCMT3_SL : 2;
            uint32_t                  : 24;
        } SYS_SLVACCCTL67_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL68;
        struct
        {
            __IOM uint32_t MORWDT0_SL : 2;
            __IOM uint32_t MORWDT1_SL : 2;
            uint32_t                  : 28;
        } SYS_SLVACCCTL68_b;
    };
    __IM uint8_t RESERVED9[44];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL80;
        struct
        {
            __IOM uint32_t I3C_SL : 2;
            uint32_t              : 30;
        } SYS_SLVACCCTL80_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL81;
        struct
        {
            __IOM uint32_t CANFD_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL81_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL82;
        struct
        {
            __IOM uint32_t RCPU_SRAM_SL : 2;
            uint32_t                    : 30;
        } SYS_SLVACCCTL82_b;
    };
    __IM uint8_t RESERVED10[20];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL88;
        struct
        {
            __IOM uint32_t RCPU_SL : 2;
            uint32_t               : 30;
        } SYS_SLVACCCTL88_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL89;
        struct
        {
            __IOM uint32_t MCPU_SL : 2;
            uint32_t               : 30;
        } SYS_SLVACCCTL89_b;
    };
    __IM uint8_t RESERVED11[4];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL91;
        struct
        {
            __IOM uint32_t LSI_SL : 2;
            uint32_t              : 30;
        } SYS_SLVACCCTL91_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL92;
        struct
        {
            __IOM uint32_t AOF_SL : 2;
            uint32_t              : 30;
        } SYS_SLVACCCTL92_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL93;
        struct
        {
            __IOM uint32_t GPREG_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL93_b;
    };
    __IM uint8_t RESERVED12[136];
    union
    {
        __IM uint32_t SYS_LSI_MODE;
        struct
        {
            __IM uint32_t STAT_MD_BOOT      : 3;
            uint32_t                        : 6;
            __IM uint32_t STAT_DEBUGEN      : 1;
            __IM uint32_t STAT_BOOTSELECTER : 1;
            __IM uint32_t STAT_BOOTPLLCA55  : 2;
            __IM uint32_t STAT_MD_CLKS      : 1;
            uint32_t                        : 18;
        } SYS_LSI_MODE_b;
    };
    union
    {
        __IM uint32_t SYS_LSI_DEVID;
        struct
        {
            __IM uint32_t DEV_ID : 32;
        } SYS_LSI_DEVID_b;
    };
    union
    {
        __IM uint32_t SYS_LSI_PRR;
        struct
        {
            __IM uint32_t GPU_DIS : 1;
            uint32_t              : 3;
            __IM uint32_t ISP_DIS : 1;
            uint32_t              : 27;
        } SYS_LSI_PRR_b;
    };
    __IM uint8_t RESERVED13[20];
    union
    {
        __IM uint32_t SYS_LSI_OTPTSU0TRMVAL0;
        struct
        {
            __IM uint32_t TSU0_TRMVAL0 : 32;
        } SYS_LSI_OTPTSU0TRMVAL0_b;
    };
    union
    {
        __IM uint32_t SYS_LSI_OTPTSU0TRMVAL1;
        struct
        {
            __IM uint32_t TSU0_TRMVAL1 : 32;
        } SYS_LSI_OTPTSU0TRMVAL1_b;
    };
    __IM uint8_t RESERVED14[8];
    union
    {
        __IM uint32_t SYS_LSI_OTPTSU1TRMVAL0;
        struct
        {
            __IM uint32_t TSU1_TRMVAL0 : 32;
        } SYS_LSI_OTPTSU1TRMVAL0_b;
    };
    union
    {
        __IM uint32_t SYS_LSI_OTPTSU1TRMVAL1;
        struct
        {
            __IM uint32_t TSU1_TRMVAL1 : 32;
        } SYS_LSI_OTPTSU1TRMVAL1_b;
    };
    __IM uint8_t RESERVED15[456];
    union
    {
        __IOM uint32_t SYS_AOF0;
        struct
        {
            __IOM uint32_t OFS00_0 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS01_0 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS10_0 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS11_0 : 6;
            uint32_t               : 2;
        } SYS_AOF0_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF1;
        struct
        {
            __IOM uint32_t OFS00_1 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS01_1 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS10_1 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS11_1 : 6;
            uint32_t               : 2;
        } SYS_AOF1_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF2;
        struct
        {
            __IOM uint32_t OFS00_2 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS01_2 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS10_2 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS11_2 : 6;
            uint32_t               : 2;
        } SYS_AOF2_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF3;
        struct
        {
            __IOM uint32_t OFS00_3 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS01_3 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS10_3 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS11_3 : 6;
            uint32_t               : 2;
        } SYS_AOF3_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF4;
        struct
        {
            __IOM uint32_t OFS00_4 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS01_4 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS10_4 : 6;
            uint32_t               : 2;
            __IOM uint32_t OFS11_4 : 6;
            uint32_t               : 2;
        } SYS_AOF4_b;
    };
    __IM uint8_t RESERVED16[44];
    union
    {
        __IOM uint32_t SYS_AOF16;
        struct
        {
            __IOM uint32_t OFS00_16 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_16 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_16 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_16 : 6;
            uint32_t                : 2;
        } SYS_AOF16_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF17;
        struct
        {
            __IOM uint32_t OFS00_17 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_17 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_17 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_17 : 6;
            uint32_t                : 2;
        } SYS_AOF17_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF18;
        struct
        {
            __IOM uint32_t OFS00_18 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_18 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_18 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_18 : 6;
            uint32_t                : 2;
        } SYS_AOF18_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF19;
        struct
        {
            __IOM uint32_t OFS00_19 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_19 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_19 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_19 : 6;
            uint32_t                : 2;
        } SYS_AOF19_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF20;
        struct
        {
            __IOM uint32_t OFS00_20 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_20 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_20 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_20 : 6;
            uint32_t                : 2;
        } SYS_AOF20_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF21;
        struct
        {
            __IOM uint32_t OFS00_21 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_21 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_21 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_21 : 6;
            uint32_t                : 2;
        } SYS_AOF21_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF22;
        struct
        {
            __IOM uint32_t OFS00_22 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_22 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_22 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_22 : 6;
            uint32_t                : 2;
        } SYS_AOF22_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF23;
        struct
        {
            __IOM uint32_t OFS00_23 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_23 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_23 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_23 : 6;
            uint32_t                : 2;
        } SYS_AOF23_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF24;
        struct
        {
            __IOM uint32_t OFS00_24 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_24 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_24 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_24 : 6;
            uint32_t                : 2;
        } SYS_AOF24_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF25;
        struct
        {
            __IOM uint32_t OFS00_25 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_25 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_25 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_25 : 6;
            uint32_t                : 2;
        } SYS_AOF25_b;
    };
    __IM uint8_t RESERVED17[24];
    union
    {
        __IOM uint32_t SYS_AOF32;
        struct
        {
            __IOM uint32_t OFS0011_MCPUS : 8;
            __IOM uint32_t OFS0100_MCPUS : 8;
            uint32_t                     : 16;
        } SYS_AOF32_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF33;
        struct
        {
            __IOM uint32_t OFS00_33 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_33 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_33 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_33 : 6;
            uint32_t                : 2;
        } SYS_AOF33_b;
    };
    __IM uint8_t RESERVED18[24];
    union
    {
        __IOM uint32_t SYS_AOF40;
        struct
        {
            __IOM uint32_t OFS00_40 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_40 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_40 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_40 : 6;
            uint32_t                : 2;
        } SYS_AOF40_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF41;
        struct
        {
            __IOM uint32_t OFS00_41 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_41 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_41 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_41 : 6;
            uint32_t                : 2;
        } SYS_AOF41_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF42;
        struct
        {
            __IOM uint32_t OFS00_42 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_42 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_42 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_42 : 6;
            uint32_t                : 2;
        } SYS_AOF42_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF43;
        struct
        {
            __IOM uint32_t OFS00_43 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_43 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_43 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_43 : 6;
            uint32_t                : 2;
        } SYS_AOF43_b;
    };
    __IM uint8_t RESERVED19[16];
    union
    {
        __IOM uint32_t SYS_AOF48;
        struct
        {
            __IOM uint32_t OFS00_48 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_48 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_48 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_48 : 6;
            uint32_t                : 2;
        } SYS_AOF48_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF49;
        struct
        {
            __IOM uint32_t OFS00_49 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS01_49 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS10_49 : 6;
            uint32_t                : 2;
            __IOM uint32_t OFS11_49 : 6;
            uint32_t                : 2;
        } SYS_AOF49_b;
    };
    __IM uint8_t RESERVED20[56];
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_SMPL;
        struct
        {
            __IOM uint32_t ASTARTMPL : 8;
            uint32_t                 : 24;
        } SYS_ACPU_CFG_SMPL_b;
    };
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_SMPH;
        struct
        {
            uint32_t                 : 20;
            __IOM uint32_t ASTARTMPH : 12;
        } SYS_ACPU_CFG_SMPH_b;
    };
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_EMPL;
        struct
        {
            uint32_t                  : 20;
            __IOM uint32_t AENDMPLMPL : 12;
        } SYS_ACPU_CFG_EMPL_b;
    };
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_EMPH;
        struct
        {
            __IOM uint32_t AENDMPH : 8;
            uint32_t               : 24;
        } SYS_ACPU_CFG_EMPH_b;
    };
    __IM uint8_t RESERVED21[20];
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_RVAL0;
        struct
        {
            uint32_t                   : 2;
            __IOM uint32_t RVBARADDRL0 : 30;
        } SYS_ACPU_CFG_RVAL0_b;
    };
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_RVAH0;
        struct
        {
            __IOM uint32_t RVBARADDRH0 : 8;
            uint32_t                   : 24;
        } SYS_ACPU_CFG_RVAH0_b;
    };
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_RVAL1;
        struct
        {
            uint32_t                   : 2;
            __IOM uint32_t RVBARADDRL1 : 30;
        } SYS_ACPU_CFG_RVAL1_b;
    };
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_RVAH1;
        struct
        {
            __IOM uint32_t RVBARADDRH1 : 8;
            uint32_t                   : 24;
        } SYS_ACPU_CFG_RVAH1_b;
    };
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_RVAL2;
        struct
        {
            uint32_t                   : 2;
            __IOM uint32_t RVBARADDRL2 : 30;
        } SYS_ACPU_CFG_RVAL2_b;
    };
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_RVAH2;
        struct
        {
            __IOM uint32_t RVBARADDRH2 : 8;
            uint32_t                   : 24;
        } SYS_ACPU_CFG_RVAH2_b;
    };
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_RVAL3;
        struct
        {
            uint32_t                   : 2;
            __IOM uint32_t RVBARADDRL3 : 30;
        } SYS_ACPU_CFG_RVAL3_b;
    };
    union
    {
        __IOM uint32_t SYS_ACPU_CFG_RVAH3;
        struct
        {
            __IOM uint32_t RVBARADDRH3 : 8;
            uint32_t                   : 24;
        } SYS_ACPU_CFG_RVAH3_b;
    };
    __IM uint8_t RESERVED22[192];
    union
    {
        __IOM uint32_t SYS_RCPU_CONFIG1;
        struct
        {
            uint32_t                 : 2;
            __IOM uint32_t MFILTEREN : 1;
            __IOM uint32_t ITCMECCEN : 1;
            uint32_t                 : 28;
        } SYS_RCPU_CONFIG1_b;
    };
    union
    {
        __IOM uint32_t SYS_RCPU_CONFIG2;
        struct
        {
            __IOM uint32_t MFILTERSTART : 12;
            uint32_t                    : 4;
            __IOM uint32_t MFILTEREND   : 12;
            uint32_t                    : 4;
        } SYS_RCPU_CONFIG2_b;
    };
    union
    {
        __IOM uint32_t SYS_RCPU_CONFIG3;
        struct
        {
            uint32_t                  : 13;
            __IOM uint32_t PERIPHBASE : 19;
        } SYS_RCPU_CONFIG3_b;
    };
    union
    {
        __IOM uint32_t SYS_RCPU_CONFIG4;
        struct
        {
            __IOM uint32_t PFILTERSTART : 12;
            uint32_t                    : 4;
            __IOM uint32_t PFILTEREND   : 12;
            uint32_t                    : 4;
        } SYS_RCPU_CONFIG4_b;
    };
    __IM uint8_t RESERVED23[8];
    union
    {
        __IM uint32_t SYS_RCPU_CORESTATUS;
        struct
        {
            __IM uint32_t SMPnAMP  : 2;
            uint32_t               : 6;
            __IM uint32_t PMUPRIV  : 2;
            uint32_t               : 10;
            __IM uint32_t PWRCTLO0 : 2;
            __IM uint32_t PWRCTLO1 : 2;
            __IM uint32_t SCUIDLE  : 1;
            uint32_t               : 7;
        } SYS_RCPU_CORESTATUS_b;
    };
    __IM uint8_t RESERVED24[236];
    union
    {
        __IOM uint32_t SYS_MCPU_CFG2;
        struct
        {
            uint32_t                 : 7;
            __IOM uint32_t INITSVTOR : 25;
        } SYS_MCPU_CFG2_b;
    };
    union
    {
        __IOM uint32_t SYS_MCPU_CFG3;
        struct
        {
            uint32_t                  : 7;
            __IOM uint32_t INITNSVTOR : 25;
        } SYS_MCPU_CFG3_b;
    };
    union
    {
        __IOM uint32_t SYS_MCPU_CFG4;
        struct
        {
            __IOM uint32_t IDAUZERONS : 1;
            uint32_t                  : 31;
        } SYS_MCPU_CFG4_b;
    };
    union
    {
        __IOM uint32_t SYS_MCPU_CFG5;
        struct
        {
            __IOM uint32_t LOCKSVTAIRCR : 1;
            __IOM uint32_t LOCKNSVTOR   : 1;
            uint32_t                    : 30;
        } SYS_MCPU_CFG5_b;
    };
    __IM uint8_t RESERVED25[228];
    union
    {
        __IM uint32_t SYS_SPI_STAADDCS0;
        struct
        {
            __IM uint32_t XSPI_STARTADDRCS0 : 32;
        } SYS_SPI_STAADDCS0_b;
    };
    union
    {
        __IM uint32_t SYS_SPI_ENDADDCS0;
        struct
        {
            __IM uint32_t XSPI_ENDADDRCS0 : 32;
        } SYS_SPI_ENDADDCS0_b;
    };
    union
    {
        __IM uint32_t SYS_SPI_STAADDCS1;
        struct
        {
            __IM uint32_t XSPI_STARTADDRCS1 : 32;
        } SYS_SPI_STAADDCS1_b;
    };
    union
    {
        __IM uint32_t SYS_SPI_ENDADDCS1;
        struct
        {
            __IM uint32_t XSPI_ENDADDRCS1 : 32;
        } SYS_SPI_ENDADDCS1_b;
    };
    __IM uint8_t RESERVED26[496];
    union
    {
        __IOM uint32_t SYS_SRAM0_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM0_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM0_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM0_EN_b;
    };
    __IM uint8_t RESERVED27[12];
    union
    {
        __IOM uint32_t SYS_SRAM1_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM1_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM1_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM1_EN_b;
    };
    __IM uint8_t RESERVED28[12];
    union
    {
        __IOM uint32_t SYS_SRAM2_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM2_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM2_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM2_EN_b;
    };
    __IM uint8_t RESERVED29[12];
    union
    {
        __IOM uint32_t SYS_SRAM3_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM3_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM3_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM3_EN_b;
    };
    __IM uint8_t RESERVED30[12];
    union
    {
        __IOM uint32_t SYS_SRAM4_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM4_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM4_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM4_EN_b;
    };
    __IM uint8_t RESERVED31[12];
    union
    {
        __IOM uint32_t SYS_SRAM5_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM5_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM5_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM5_EN_b;
    };
    __IM uint8_t RESERVED32[12];
    union
    {
        __IOM uint32_t SYS_SRAM6_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM6_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM6_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM6_EN_b;
    };
    __IM uint8_t RESERVED33[12];
    union
    {
        __IOM uint32_t SYS_SRAM7_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM7_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM7_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM7_EN_b;
    };
    __IM uint8_t RESERVED34[12];
    union
    {
        __IOM uint32_t SYS_SRAM8_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM8_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM8_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM8_EN_b;
    };
    __IM uint8_t RESERVED35[12];
    union
    {
        __IOM uint32_t SYS_SRAM9_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM9_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM9_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM9_EN_b;
    };
    __IM uint8_t RESERVED36[12];
    union
    {
        __IOM uint32_t SYS_SRAM10_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM10_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM10_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM10_EN_b;
    };
    __IM uint8_t RESERVED37[12];
    union
    {
        __IOM uint32_t SYS_SRAM11_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_SRAM11_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_SRAM11_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_SRAM11_EN_b;
    };
    __IM uint8_t RESERVED38[28];
    union
    {
        __IOM uint32_t SYS_WDT0_CTRL;
        struct
        {
            __IOM uint32_t bp_halted   : 1;
            uint32_t                   : 15;
            __IOM uint32_t WDTSTOPMASK : 1;
            uint32_t                   : 15;
        } SYS_WDT0_CTRL_b;
    };
    union
    {
        __IOM uint32_t SYS_WDT2_CTRL;
        struct
        {
            __IOM uint32_t bp_halted   : 1;
            uint32_t                   : 15;
            __IOM uint32_t WDTSTOPMASK : 1;
            uint32_t                   : 15;
        } SYS_WDT2_CTRL_b;
    };
    union
    {
        __IOM uint32_t SYS_WDT3_CTRL;
        struct
        {
            __IOM uint32_t bp_halted   : 1;
            uint32_t                   : 15;
            __IOM uint32_t WDTSTOPMASK : 1;
            uint32_t                   : 15;
        } SYS_WDT3_CTRL_b;
    };
    union
    {
        __IOM uint32_t SYS_WDT1_CTRL;
        struct
        {
            __IOM uint32_t bp_halted   : 1;
            uint32_t                   : 15;
            __IOM uint32_t WDTSTOPMASK : 1;
            uint32_t                   : 15;
        } SYS_WDT1_CTRL_b;
    };
    __IM uint8_t RESERVED39[752];
    union
    {
        __IOM uint32_t SYS_GBETH0_CFG;
        struct
        {
            __IM uint32_t MAC_SPEED      : 2;
            uint32_t                     : 14;
            __IOM uint32_t PHY_INTF_TYPE : 3;
            uint32_t                     : 13;
        } SYS_GBETH0_CFG_b;
    };
    union
    {
        __IOM uint32_t SYS_GBETH1_CFG;
        struct
        {
            __IM uint32_t MAC_SPEED      : 2;
            uint32_t                     : 14;
            __IOM uint32_t PHY_INTF_TYPE : 3;
            uint32_t                     : 13;
        } SYS_GBETH1_CFG_b;
    };
    __IM uint8_t RESERVED40[248];
    union
    {
        __IOM uint32_t SYS_PCIE_INTX_CH0;
        struct
        {
            __IOM uint32_t INTX_EP_F0 : 1;
            __IOM uint32_t INTX_EP_F1 : 1;
            uint32_t                  : 30;
        } SYS_PCIE_INTX_CH0_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MSI1_CH0;
        struct
        {
            __IOM uint32_t UI_EXTMSI_VAL0 : 1;
            __IOM uint32_t UI_EXTMSI_VAL1 : 1;
            __IOM uint32_t UI_EXTMSI_VAL2 : 1;
            __IOM uint32_t UI_EXTMSI_VAL3 : 1;
            __IOM uint32_t UI_EXTMSI_VAL4 : 1;
            uint32_t                      : 27;
        } SYS_PCIE_MSI1_CH0_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MSI2_CH0;
        struct
        {
            __IOM uint32_t UI_EXTMSI_VEC0 : 5;
            uint32_t                      : 3;
            __IOM uint32_t UI_EXTMSI_VEC1 : 5;
            uint32_t                      : 3;
            __IOM uint32_t UI_EXTMSI_VEC2 : 5;
            uint32_t                      : 3;
            __IOM uint32_t UI_EXTMSI_VEC3 : 5;
            uint32_t                      : 3;
        } SYS_PCIE_MSI2_CH0_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MSI3_CH0;
        struct
        {
            __IOM uint32_t UI_EXTMSI_VEC : 5;
            uint32_t                     : 27;
        } SYS_PCIE_MSI3_CH0_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MSI4_CH0;
        struct
        {
            __IOM uint32_t UI_EXTMSI_FUNC0 : 3;
            uint32_t                       : 5;
            __IOM uint32_t UI_EXTMSI_FUNC1 : 3;
            uint32_t                       : 5;
            __IOM uint32_t UI_EXTMSI_FUNC2 : 3;
            uint32_t                       : 5;
            __IOM uint32_t UI_EXTMSI_FUNC3 : 3;
            uint32_t                       : 5;
        } SYS_PCIE_MSI4_CH0_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MSI5_CH0;
        struct
        {
            __IOM uint32_t UI_EXTMSI_FUNC4 : 3;
            uint32_t                       : 29;
        } SYS_PCIE_MSI5_CH0_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_PME_CH0;
        struct
        {
            __IOM uint32_t PME_TIM                 : 1;
            uint32_t                               : 7;
            __IOM uint32_t CFG_PMCSR_PME_STATUS_F0 : 1;
            __IOM uint32_t CFG_PMCSR_PME_STATUS_F1 : 1;
            uint32_t                               : 22;
        } SYS_PCIE_PME_CH0_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_ACK_CH0;
        struct
        {
            __IOM uint32_t TURN_OFF_EVENT_ACK : 1;
            uint32_t                          : 7;
            __IOM uint32_t D3_ECENT_ACK_F0    : 1;
            __IOM uint32_t D3_ECENT_ACK_F1    : 1;
            uint32_t                          : 22;
        } SYS_PCIE_ACK_CH0_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MISC_CH0;
        struct
        {
            __IOM uint32_t ALLOW_ENTER_L1 : 1;
            uint32_t                      : 15;
            __IOM uint32_t FLR_RESET      : 2;
            __IM uint32_t  FLR_REQ        : 2;
            uint32_t                      : 12;
        } SYS_PCIE_MISC_CH0_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MODE_CH0;
        struct
        {
            __IOM uint32_t MODE_PORT : 1;
            uint32_t                 : 31;
        } SYS_PCIE_MODE_CH0_b;
    };
    __IM uint8_t RESERVED41[8];
    union
    {
        __IOM uint32_t SYS_PCIE_INTX_CH1;
        struct
        {
            __IOM uint32_t INTX_EP_F0 : 1;
            __IOM uint32_t INTX_EP_F1 : 1;
            uint32_t                  : 30;
        } SYS_PCIE_INTX_CH1_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MSI1_CH1;
        struct
        {
            __IOM uint32_t UI_EXTMSI_VAL0 : 1;
            __IOM uint32_t UI_EXTMSI_VAL1 : 1;
            __IOM uint32_t UI_EXTMSI_VAL2 : 1;
            __IOM uint32_t UI_EXTMSI_VAL3 : 1;
            __IOM uint32_t UI_EXTMSI_VAL4 : 1;
            uint32_t                      : 27;
        } SYS_PCIE_MSI1_CH1_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MSI2_CH1;
        struct
        {
            __IOM uint32_t UI_EXTMSI_VEC0 : 5;
            uint32_t                      : 3;
            __IOM uint32_t UI_EXTMSI_VEC1 : 5;
            uint32_t                      : 3;
            __IOM uint32_t UI_EXTMSI_VEC2 : 5;
            uint32_t                      : 3;
            __IOM uint32_t UI_EXTMSI_VEC3 : 5;
            uint32_t                      : 3;
        } SYS_PCIE_MSI2_CH1_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MSI3_CH1;
        struct
        {
            __IOM uint32_t UI_EXTMSI_VEC4 : 5;
            uint32_t                      : 27;
        } SYS_PCIE_MSI3_CH1_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MSI4_CH1;
        struct
        {
            __IOM uint32_t UI_EXTMSI_FUNC0 : 3;
            uint32_t                       : 5;
            __IOM uint32_t UI_EXTMSI_FUNC1 : 3;
            uint32_t                       : 5;
            __IOM uint32_t UI_EXTMSI_FUNC2 : 3;
            uint32_t                       : 5;
            __IOM uint32_t UI_EXTMSI_FUNC3 : 3;
            uint32_t                       : 5;
        } SYS_PCIE_MSI4_CH1_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MSI5_CH1;
        struct
        {
            __IOM uint32_t UI_EXTMSI_FUNC40 : 1;
            __IOM uint32_t UI_EXTMSI_FUNC4  : 2;
            uint32_t                        : 29;
        } SYS_PCIE_MSI5_CH1_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_PME_CH1;
        struct
        {
            __IOM uint32_t PME_TIM                 : 1;
            uint32_t                               : 7;
            __IOM uint32_t CFG_PMCSR_PME_STATUS_F0 : 1;
            __IOM uint32_t CFG_PMCSR_PME_STATUS_F1 : 1;
            uint32_t                               : 22;
        } SYS_PCIE_PME_CH1_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_ACK_CH1;
        struct
        {
            __IOM uint32_t TURN_OFF_EVENT_ACK : 1;
            uint32_t                          : 7;
            __IOM uint32_t D3_ECENT_ACK_F0    : 1;
            __IOM uint32_t D3_ECENT_ACK_F1    : 1;
            uint32_t                          : 22;
        } SYS_PCIE_ACK_CH1_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MISC_CH1;
        struct
        {
            __IOM uint32_t ALLOW_ENTER_L1 : 1;
            uint32_t                      : 15;
            __IOM uint32_t FLR_RESET      : 2;
            __IM uint32_t  FLR_REQ        : 2;
            uint32_t                      : 12;
        } SYS_PCIE_MISC_CH1_b;
    };
    union
    {
        __IOM uint32_t SYS_PCIE_MODE_CH1;
        struct
        {
            __IOM uint32_t MODE_PORT   : 1;
            uint32_t                   : 7;
            __IOM uint32_t LINK_MASTER : 2;
            uint32_t                   : 22;
        } SYS_PCIE_MODE_CH1_b;
    };
    __IM uint8_t RESERVED42[8];
    union
    {
        __IOM uint32_t SYS_PCIE_MODE;
        struct
        {
            uint32_t                   : 8;
            __IOM uint32_t LINK_MASTER : 2;
            uint32_t                   : 22;
        } SYS_PCIE_MODE_b;
    };
    __IM uint8_t RESERVED43[1436];
    union
    {
        __IOM uint32_t SYS_ADC_CFG;
        struct
        {
            __IOM uint32_t sy_mstp_ada : 1;
            uint32_t                   : 31;
        } SYS_ADC_CFG_b;
    };
    __IM uint8_t RESERVED44[252];
    union
    {
        __IOM uint32_t SYS_GPREG_0;
        struct
        {
            __IOM uint32_t CPREG0 : 32;
        } SYS_GPREG_0_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_1;
        struct
        {
            __IOM uint32_t CPREG1 : 32;
        } SYS_GPREG_1_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_2;
        struct
        {
            __IOM uint32_t CPREG2 : 32;
        } SYS_GPREG_2_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_3;
        struct
        {
            __IOM uint32_t CPREG3 : 32;
        } SYS_GPREG_3_b;
    };
} R_SYSC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_SYSC_BASE    0x10430000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_SYSC    ((R_SYSC_Type *) R_SYSC_BASE)

#endif
