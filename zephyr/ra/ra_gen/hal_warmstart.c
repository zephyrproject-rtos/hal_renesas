/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <bsp_api.h>
#if BSP_CFG_VBATT_MANUAL_CONFIGURATION
#include <bsp_reset.h>
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */

#if BSP_CFG_VBATT_MANUAL_CONFIGURATION
#if BSP_CFG_VBATT_ENABLE
#define BSP_PRV_VCC_DROP_DETECTION_STABILIZATION_WAIT_TIME_US 20
#define BSP_PRV_VBTBPCR2_VDETLVL_LEVEL_SELECT                                  \
  DT_ENUM_IDX(DT_NODELABEL(battery_backup), switch_threshold)
#else
#define BSP_PRV_VBTBPCR2_VDETLVL_SETTING_NOT_USED 0x6
#endif /* BSP_CFG_VBATT_ENABLE */

uint8_t vbtbpsr_state_at_boot BSP_SECTION_EARLY_INIT;
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
#if BSP_CFG_VBATT_MANUAL_CONFIGURATION
#if BSP_CFG_VBATT_ENABLE
static void R_BSP_BackupDomainEnableInit(void);
#else
static void R_BSP_BackupDomainDisableInit(void);
#endif /* BSP_CFG_VBATT_ENABLE */
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */
FSP_CPP_FOOTER

/*******************************************************************************************************************/
/**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 ********************************************************************************************************************
 **/
void R_BSP_WarmStart(bsp_warm_start_event_t event) {
  if (BSP_WARM_START_RESET == event) {
#if BSP_CFG_VBATT_MANUAL_CONFIGURATION
#if !BSP_CFG_VBATT_ENABLE
    R_BSP_BackupDomainDisableInit();
#endif /* BSP_CFG_VBATT_ENABLE */
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */
  }

  if (BSP_WARM_START_POST_CLOCK == event) {
#if BSP_CFG_VBATT_MANUAL_CONFIGURATION
#if BSP_CFG_VBATT_ENABLE
    R_BSP_BackupDomainEnableInit();
#endif /* BSP_CFG_VBATT_ENABLE */
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */
  }
}

#if BSP_CFG_VBATT_MANUAL_CONFIGURATION
#if BSP_CFG_VBATT_ENABLE
/*******************************************************************************************************************//**
 * Initialization when using Battery Backup Domain
 **********************************************************************************************************************/
static void R_BSP_BackupDomainEnableInit(void) {
  if (R_BSP_ResetStatusGet() == BSP_RESET_TYPE_POR) {
    /*  Check VBPORM bit. If VBPORM flag is 0, wait until it changes to 1 */
    FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->VBTBPSR_b.VBPORM, 1);
    vbtbpsr_state_at_boot = R_SYSTEM->VBTBPSR;
    if (R_SYSTEM->VBTBPSR_b.VBPORF == 1) {
      R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_OM_LPC_BATT);
      R_SYSTEM->VBTBPSR_b.VBPORF = 0;
      R_SYSTEM->VBTBPCR2_b.VDETLVL = BSP_PRV_VBTBPCR2_VDETLVL_LEVEL_SELECT;
      R_BSP_SoftwareDelay(BSP_PRV_VCC_DROP_DETECTION_STABILIZATION_WAIT_TIME_US,
                          BSP_DELAY_UNITS_MICROSECONDS);
      R_SYSTEM->VBTBPCR2_b.VDETE = 1;
      R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_OM_LPC_BATT);
    }
  }
}
#else
/*******************************************************************************************************************//**
 * Initialization when not using Battery Backup Domain
 **********************************************************************************************************************/
static void R_BSP_BackupDomainDisableInit(void) {
  /*  Set the BPWSWSTP bit to 1. The power supply switch is stopped */
  R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_OM_LPC_BATT);
  R_SYSTEM->VBTBPCR1_b.BPWSWSTP = 1;

  /* Check VBPORM flag. If VBPORM flag is 0, wait until it changes to 1 */
  FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->VBTBPSR_b.VBPORM, 1);
  vbtbpsr_state_at_boot = R_SYSTEM->VBTBPSR;
  R_SYSTEM->VBTBPSR_b.VBPORF = 0;
  R_SYSTEM->VBTBPCR2_b.VDETE = 0;
  R_SYSTEM->VBTBPCR2_b.VDETLVL = BSP_PRV_VBTBPCR2_VDETLVL_SETTING_NOT_USED;
  R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_OM_LPC_BATT);

  /* Set the SOSTP bit to 1 regardless of its value. Stop Sub-Clock Oscillator
   */
  R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_CGC);
  R_SYSTEM->SOSCCR_b.SOSTP = 1;
  R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_CGC);
}
#endif /* BSP_CFG_VBATT_ENABLE */
#endif /* BSP_CFG_VBATT_MANUAL_CONFIGURATION */
