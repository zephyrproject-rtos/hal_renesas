/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_USB_HOST_CFG_H_
#define R_USB_HOST_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define USBH_CFG_PARAM_CHECKING_ENABLE    (BSP_CFG_PARAM_CHECKING_ENABLE)

#define USBHS_PHY_CLOCK_SOURCE_IS_XTAL    (DT_ENUM_IDX_OR(DT_INST(0, renesas_ra_usbphyc), phys_clock_src, 0))

#if USBHS_PHY_CLOCK_SOURCE_IS_XTAL
#if BSP_CFG_XTAL_HZ == 12000000
#define USBH_CFG_PHYSET_CLKSEL            (0U)
#elif BSP_CFG_XTAL_HZ == 48000000
#define USBH_CFG_PHYSET_CLKSEL            (0x1U)
#elif BSP_CFG_XTAL_HZ == 20000000
#define USBH_CFG_PHYSET_CLKSEL            (0x2U)
#elif BSP_CFG_XTAL_HZ == 24000000
#define USBH_CFG_PHYSET_CLKSEL            (0x3U)
#else
#error "Available XTAL clocks are 12-20-24-48Mhz"
#endif
#else   /* Use 48Mhz UCK as clock source for PHY clock */
#define USBH_CFG_PHYSET_CLKSEL            (-1)
#endif

#define USBH_CFG_BUS_WAIT_CYCLES          (DT_PROP_OR(DT_NODELABEL(usbhs), bus_wait_cycles, 9) - 2)

#ifdef __cplusplus
}
#endif
#endif /* R_USB_HOST_CFG_H_ */
