/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_RSIP
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define NVR_ADDR_INSTALL_KEY_RING_INDEX    ((volatile uint32_t *) (0x240003F0U))
#define NVR_ADDR_SHARED_KEY_NUM            ((volatile uint32_t *) (0x24000BE0U))

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
BSP_PLACE_CODE_IN_RAM static void bsp_prv_nvmc_select_nvr(void);
BSP_PLACE_CODE_IN_RAM static void bsp_prv_nvmc_select_nvm(void);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Global Variables
 **********************************************************************************************************************/
BSP_PLACE_IN_SECTION(BSP_SECTION_NOINIT) volatile uint32_t rsip_install_key_ring_index;
BSP_PLACE_IN_SECTION(BSP_SECTION_NOINIT) volatile uint32_t rsip_SharedKeyIndex;

/***********************************************************************************************************************
 * Public Functions
 **********************************************************************************************************************/
BSP_PLACE_CODE_IN_RAM void bsp_prv_rsip_fetch_KeyIndex (void)
{
    rsip_install_key_ring_index = 0xffffffff;
    rsip_SharedKeyIndex         = 0xffffffff;

    __disable_irq();

    bsp_prv_nvmc_select_nvr();

    rsip_install_key_ring_index = (uint32_t) (*NVR_ADDR_INSTALL_KEY_RING_INDEX) & 0x0000000f;
    rsip_SharedKeyIndex         = (uint32_t) (*NVR_ADDR_SHARED_KEY_NUM) & 0x0000000f;

    bsp_prv_nvmc_select_nvm();

    __enable_irq();
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*
 * Select NVR
 */
BSP_PLACE_CODE_IN_RAM static void bsp_prv_nvmc_select_nvr (void)
{
    /* standby mode */
    NVMC->NVMC_CTRL_REG_b.NVM_MODE = 0x1;
    FSP_HARDWARE_REGISTER_WAIT(NVMC->NVMC_STAT_REG_b.NVM_STANDBY_MODE, 1)

    /* Select NVR */
    NVMC->NVMC_CTRL_REG_b.NVM_NVR_SECTOR = 0x1;
    FSP_HARDWARE_REGISTER_WAIT(NVMC->NVMC_STAT_REG_b.NVM_STANDBY_MODE, 1)
}

/*
 * Select NVM
 */
BSP_PLACE_CODE_IN_RAM static void bsp_prv_nvmc_select_nvm (void)
{
    /* Standby mode */
    NVMC->NVMC_CTRL_REG_b.NVM_MODE = 0x1;
    FSP_HARDWARE_REGISTER_WAIT(NVMC->NVMC_STAT_REG_b.NVM_STANDBY_MODE, 1)

    /* Select NVM */
    NVMC->NVMC_CTRL_REG_b.NVM_NVR_SECTOR = 0x0;
    FSP_HARDWARE_REGISTER_WAIT(NVMC->NVMC_STAT_REG_b.NVM_STANDBY_MODE, 1)
}

/** @} (end addtogroup BSP_RSIP) */
