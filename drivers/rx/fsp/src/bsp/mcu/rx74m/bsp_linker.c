/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "bsp_api.h"

/* UNCRUSTIFY-OFF */

/* boot loaded applications cannot set ofs registers (only do so in the boot loader) */
#ifndef BSP_BOOTLOADED_APPLICATION
/** configuration register output to sections */
#if defined BSP_CFG_OPTION_SETTING_BANKSEL_NS
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_banksel_ns") g_bsp_cfg_option_setting_banksel_ns[] = {BSP_CFG_OPTION_SETTING_BANKSEL_NS};
#endif
#if defined BSP_CFG_OPTION_SETTING_BLSEL_NS
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_blsel_ns") g_bsp_cfg_option_setting_blsel_ns[] = {BSP_CFG_OPTION_SETTING_BLSEL_NS};
#endif
#if defined BSP_CFG_OPTION_SETTING_BPSD0_NS
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_bpsd0_ns") g_bsp_cfg_option_setting_bpsd0_ns[] = {BSP_CFG_OPTION_SETTING_BPSD0_NS};
#endif
#if defined BSP_CFG_OPTION_SETTING_BLKSWP_NS
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_blkswp_ns") g_bsp_cfg_option_setting_blkswp_ns[] = {BSP_CFG_OPTION_SETTING_BLKSWP_NS};
#endif
#if defined BSP_CFG_OPTION_SETTING_BPS_NS
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_bps_ns") g_bsp_cfg_option_setting_bps_ns[] = {BSP_CFG_OPTION_SETTING_BPS_NS};
#endif
#if defined BSP_CFG_OPTION_SETTING_BPS_NS_DUAL
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_bps_ns_dual") g_bsp_cfg_option_setting_bps_ns_dual[] = {BSP_CFG_OPTION_SETTING_BPS_NS_DUAL};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SOTPMS_NS
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_sotpms_ns") g_bsp_cfg_option_setting_otp_sotpms_ns[] = {BSP_CFG_OPTION_SETTING_OTP_SOTPMS_NS};
#endif
#if defined BSP_CFG_OPTION_SETTING_OFS1_NS
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_ofs1_ns") g_bsp_cfg_option_setting_ofs1_ns[] = {BSP_CFG_OPTION_SETTING_OFS1_NS};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_PBPS_NS
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_pbps_ns") g_bsp_cfg_option_setting_otp_pbps_ns[] = {BSP_CFG_OPTION_SETTING_OTP_PBPS_NS};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_PBPS_NS_DUAL
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_pbps_ns_dual") g_bsp_cfg_option_setting_otp_pbps_ns_dual[] = {BSP_CFG_OPTION_SETTING_OTP_PBPS_NS_DUAL};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_PBPSD0_NS
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_pbpsd0_ns") g_bsp_cfg_option_setting_otp_pbpsd0_ns[] = {BSP_CFG_OPTION_SETTING_OTP_PBPSD0_NS};
#endif
#if defined BSP_CFG_OPTION_SETTING_DUALSEL
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_dualsel") g_bsp_cfg_option_setting_dualsel[] = {BSP_CFG_OPTION_SETTING_DUALSEL};
#endif
#if defined BSP_CFG_OPTION_SETTING_SAS
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_sas") g_bsp_cfg_option_setting_sas[] = {BSP_CFG_OPTION_SETTING_SAS};
#endif
#if defined BSP_CFG_OPTION_SETTING_BANKSEL_S
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_banksel_s") g_bsp_cfg_option_setting_banksel_s[] = {BSP_CFG_OPTION_SETTING_BANKSEL_S};
#endif
#if defined BSP_CFG_OPTION_SETTING_BLSEL_S
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_blsel_s") g_bsp_cfg_option_setting_blsel_s[] = {BSP_CFG_OPTION_SETTING_BLSEL_S};
#endif
#if defined BSP_CFG_OPTION_SETTING_BANKSEL_SEL
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_banksel_sel") g_bsp_cfg_option_setting_banksel_sel[] = {BSP_CFG_OPTION_SETTING_BANKSEL_SEL};
#endif
#if defined BSP_CFG_OPTION_SETTING_BLSEL_SEL
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_blsel_sel") g_bsp_cfg_option_setting_blsel_sel[] = {BSP_CFG_OPTION_SETTING_BLSEL_SEL};
#endif
#if defined BSP_CFG_OPTION_SETTING_BPSD0_S
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_bpsd0_s") g_bsp_cfg_option_setting_bpsd0_s[] = {BSP_CFG_OPTION_SETTING_BPSD0_S};
#endif
#if defined BSP_CFG_OPTION_SETTING_BLKSWP_S
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_blkswp_s") g_bsp_cfg_option_setting_blkswp_s[] = {BSP_CFG_OPTION_SETTING_BLKSWP_S};
#endif
#if defined BSP_CFG_OPTION_SETTING_BPS_S
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_bps_s") g_bsp_cfg_option_setting_bps_s[] = {BSP_CFG_OPTION_SETTING_BPS_S};
#endif
#if defined BSP_CFG_OPTION_SETTING_BPS_S_DUAL
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_bps_s_dual") g_bsp_cfg_option_setting_bps_s_dual[] = {BSP_CFG_OPTION_SETTING_BPS_S_DUAL};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_FSBLCTRL0
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_fsblctrl0") g_bsp_cfg_option_setting_otp_fsblctrl0[] = {BSP_CFG_OPTION_SETTING_OTP_FSBLCTRL0};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_FSBLCTRL1
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_fsblctrl1") g_bsp_cfg_option_setting_otp_fsblctrl1[] = {BSP_CFG_OPTION_SETTING_OTP_FSBLCTRL1};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_FSBLCTRL2
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_fsblctrl2") g_bsp_cfg_option_setting_otp_fsblctrl2[] = {BSP_CFG_OPTION_SETTING_OTP_FSBLCTRL2};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SAMR
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_samr") g_bsp_cfg_option_setting_otp_samr[] = {BSP_CFG_OPTION_SETTING_OTP_SAMR};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SACC00
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_sacc00") g_bsp_cfg_option_setting_otp_sacc00[] = {BSP_CFG_OPTION_SETTING_OTP_SACC00};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SACC10
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_sacc10") g_bsp_cfg_option_setting_otp_sacc10[] = {BSP_CFG_OPTION_SETTING_OTP_SACC10};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SACC01
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_sacc01") g_bsp_cfg_option_setting_otp_sacc01[] = {BSP_CFG_OPTION_SETTING_OTP_SACC01};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SACC11
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_sacc11") g_bsp_cfg_option_setting_otp_sacc11[] = {BSP_CFG_OPTION_SETTING_OTP_SACC11};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SACC02
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_sacc02") g_bsp_cfg_option_setting_otp_sacc02[] = {BSP_CFG_OPTION_SETTING_OTP_SACC02};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SACC12
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_sacc12") g_bsp_cfg_option_setting_otp_sacc12[] = {BSP_CFG_OPTION_SETTING_OTP_SACC12};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SACC03
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_sacc03") g_bsp_cfg_option_setting_otp_sacc03[] = {BSP_CFG_OPTION_SETTING_OTP_SACC03};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SACC13
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_sacc13") g_bsp_cfg_option_setting_otp_sacc13[] = {BSP_CFG_OPTION_SETTING_OTP_SACC13};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_SOTPMS_S
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_sotpms_s") g_bsp_cfg_option_setting_otp_sotpms_s[] = {BSP_CFG_OPTION_SETTING_OTP_SOTPMS_S};
#endif
#if defined BSP_CFG_OPTION_SETTING_OFS0
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_ofs0") g_bsp_cfg_option_setting_ofs0[] = {BSP_CFG_OPTION_SETTING_OFS0};
#endif
#if defined BSP_CFG_OPTION_SETTING_OFS2
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_ofs2") g_bsp_cfg_option_setting_ofs2[] = {BSP_CFG_OPTION_SETTING_OFS2};
#endif
#if defined BSP_CFG_OPTION_SETTING_OFS1_S
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_ofs1_s") g_bsp_cfg_option_setting_ofs1_s[] = {BSP_CFG_OPTION_SETTING_OFS1_S};
#endif
#if defined BSP_CFG_OPTION_SETTING_OFS1_SEL
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_ofs1_sel") g_bsp_cfg_option_setting_ofs1_sel[] = {BSP_CFG_OPTION_SETTING_OFS1_SEL};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_PBPS_S
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_pbps_s") g_bsp_cfg_option_setting_otp_pbps_s[] = {BSP_CFG_OPTION_SETTING_OTP_PBPS_S};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_PBPS_S_DUAL
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_pbps_s_dual") g_bsp_cfg_option_setting_otp_pbps_s_dual[] = {BSP_CFG_OPTION_SETTING_OTP_PBPS_S_DUAL};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_PBPSD0_S
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_pbpsd0_s") g_bsp_cfg_option_setting_otp_pbpsd0_s[] = {BSP_CFG_OPTION_SETTING_OTP_PBPSD0_S};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_ZHUK
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_zhuk") g_bsp_cfg_option_setting_otp_zhuk[] = {BSP_CFG_OPTION_SETTING_OTP_ZHUK};
#endif
#if defined BSP_CFG_OPTION_SETTING_OTP_UMRECR
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_otp_umrecr") g_bsp_cfg_option_setting_otp_umrecr[] = {BSP_CFG_OPTION_SETTING_OTP_UMRECR};
#endif

#if defined(__BIG)
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_mde") g_bsp_cfg_option_setting_mde[] = {0xFFFFFFF8};
#else
BSP_DONT_REMOVE const uint32_t BSP_PLACE_IN_SECTION(".option_setting_mde") g_bsp_cfg_option_setting_mde[] = {0xFFFFFFFF};
#endif

#endif // BSP_BOOTLOADED_APPLICATION

/******************************/
/* the init tables are located in bsp_linker_info.h */
#define BSP_LINKER_C
#include "bsp_linker_info.h"

/* UNCRUSTIFY-ON */
