/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_clocks_setup.c
 * Version      : 1.00
 * Description  : bsp_clocks_setup source
 *********************************************************************************************************************/

#include "../all/bsp_clocks.h"

void bsp_clock_off (void)
{
    uint8_t channel;

    /* Stop unnecessary clocks to reduce power consumption. */
    for (channel = 0; BSP_FEATURE_GTM_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_GTM, channel);
    }

    R_BSP_MODULE_CLKOFF(FSP_IP_MTU3, 0);

    R_BSP_MODULE_CLKOFF(FSP_IP_POE3, 0);

    for (channel = 0; BSP_FEATURE_WDT_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_WDT, channel);
    }

    for (channel = 0; BSP_FEATURE_SDHI_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_SDHI, channel);
    }

    for (channel = 0; BSP_FEATURE_ISU_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_ISU, channel);
    }

    for (channel = 0; BSP_FEATURE_CRU_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_CRU, channel);
    }

    for (channel = 0; BSP_FEATURE_LCDC_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_LCDC, channel);
    }

    for (channel = 0; BSP_FEATURE_SSI_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_SSI, channel);
    }

    R_BSP_MODULE_CLKOFF(FSP_IP_USB0, 0);
    R_BSP_MODULE_CLKOFF(FSP_IP_USB1, 0);
    R_BSP_MODULE_CLKOFF(FSP_IP_USBPHY, 0);

    for (channel = 0; BSP_FEATURE_GETHER_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_ETHER, channel);
    }

    for (channel = 0; BSP_FEATURE_RIIC_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_RIIC, channel);
    }

    for (channel = 0; BSP_FEATURE_SCIF_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_SCIF, channel);
    }

    for (channel = 0; BSP_FEATURE_SCI_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_SCI, channel);
    }

    for (channel = 0; BSP_FEATURE_IRDA_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_IRDA, channel);
    }

    for (channel = 0; BSP_FEATURE_RSPI_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_RSPI, channel);
    }

    R_BSP_MODULE_CLKOFF(FSP_IP_CANFD, 0);

    R_BSP_MODULE_CLKOFF(FSP_IP_ADC, 0);

    for (channel = 0; BSP_FEATURE_TSU_MAX_CHANNELS > channel; channel++)
    {
        R_BSP_MODULE_CLKOFF(FSP_IP_TSU, channel);
    }
}
