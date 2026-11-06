/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_mpu.h"                   /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */

/***********************************************************************************************************************
 * Variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * MPU region configuration table.
 *
 * Each entry in this array defines a memory region with a name, base address, size and attributes.
 *
 * Maximum of 32 regions.
 **********************************************************************************************************************/
static bsp_mpu_region_t g_bsp_mpu_regions[] =
{
    BSP_MPU_REGIONn_CONFIG(00)         /* PRQA S 1395 # DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(01)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(02)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(03)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(04)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(05)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(06)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(07)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(08)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(09)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(10)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(11)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(12)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(13)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(14)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(15)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(16)         /* PRQA S 1395, 1281 # DP_MSR_R-9.6_UC1, DP_MSR_R-7.2_UC1 */
    BSP_MPU_REGIONn_CONFIG(17)         /* PRQA S 1281, 1395 # DP_MSR_R-7.2_UC1, DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(18)         /* PRQA S 1395, 1281 # DP_MSR_R-9.6_UC1, DP_MSR_R-7.2_UC1 */
    BSP_MPU_REGIONn_CONFIG(19)         /* PRQA S 1395 # DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(20)         /* PRQA S 1395 # DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(21)         /* PRQA S 1395, 1281 # DP_MSR_R-9.6_UC1, DP_MSR_R-7.2_UC1 */
    BSP_MPU_REGIONn_CONFIG(22)         /* PRQA S 1395 # DP_MSR_R-9.6_UC1 */
    BSP_MPU_REGIONn_CONFIG(23)
#if (32U == BSP_MPU_TOTAL_REGIONS_SUPPORTED)
    BSP_MPU_REGIONn_CONFIG(24)
    BSP_MPU_REGIONn_CONFIG(25)
    BSP_MPU_REGIONn_CONFIG(26)
    BSP_MPU_REGIONn_CONFIG(27)
    BSP_MPU_REGIONn_CONFIG(28)
    BSP_MPU_REGIONn_CONFIG(29)
    BSP_MPU_REGIONn_CONFIG(30)
    BSP_MPU_REGIONn_CONFIG(31)
#endif
};

bsp_mpu_config_t g_bsp_mpu_config =    /* PRQA S 1533 # Advisory R-8.9 */
{
    .mpu_region     = g_bsp_mpu_regions,
    .num_of_regions = BSP_MPU_NUMBER_OF_REGIONS_ENABLED,
};

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * This function sets up the MPU by clearing non-configured regions and initializing all configured regions.
 * It prepares the MPU for enforcing memory access permissions based on predefined region settings.
 *
 * @param[in]  p_config              Pointer to MPU configuration structure.
 *
 * @retval  FSP_SUCCESS              Region was enabled successfully.
 * @retval  FSP_ERR_ASSERTION        Region's index exceeded max regions supported.
 *                                   p_config is NULL.
 **********************************************************************************************************************/

/* PRQA S 0292 -- */
fsp_err_t R_BSP_MPUEnable (const bsp_mpu_config_t * const p_config)
{
#if BSP_CFG_PARAM_CHECKING_ENABLE

    /* Check whether the p_config is NULL */
    FSP_ASSERT(NULL != p_config);
#endif

    fsp_err_t          err                = FSP_SUCCESS;
    uint8_t            region_num         = 0U;
    bsp_mpu_region_t * mpu_regions        = (bsp_mpu_region_t *) (p_config->mpu_region); /* PRQA S 3678 # Advisory R-8.13 */
    uint8_t            max_num_of_regions = RH850_MPU_NumberofRegionsGet();

    /* Check whether number of regions need to be configured exceed max regions supported */
    FSP_ASSERT(p_config->num_of_regions <= max_num_of_regions);

    /* Disable the MPU */
    RH850_MPU_Disable();

    for (region_num = 0U; region_num < max_num_of_regions; region_num++)
    {
        RH850_MPU_RegionSet(region_num, 0U, 0U);
        RH850_MPU_AttrSet(region_num, 0U);
    }

    /* Initialize all configured regions */
    for (region_num = 0U; region_num < p_config->num_of_regions; region_num++)
    {
        /* Check whether region's index exceed max regions supported */
        FSP_ASSERT(mpu_regions->no_of_region < max_num_of_regions);

        /* Set lower address and upper address for region */
        RH850_MPU_RegionSet(mpu_regions->no_of_region, mpu_regions->start_address, mpu_regions->size);

        /* Set attribute for region */
        RH850_MPU_AttrSet(mpu_regions->no_of_region, mpu_regions->region_attr.attribute);

        /* Process next region */
        mpu_regions++;
    }

    /* Enable the MPU */
    RH850_MPU_Enable(BSP_MPU_SV_MODE_RESTRICT_ACCESS);

    return err;
}

/*******************************************************************************************************************//**
 * This function disable the MPU by clearing all the regions.
 *
 * @retval None
 **********************************************************************************************************************/
void R_BSP_MPUDisable (void)           /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    uint8_t index;
    uint8_t max_num_of_regions = RH850_MPU_NumberofRegionsGet();

    /* Disable the MPU */
    RH850_MPU_Disable();

    /* Clear all MPID register */
    for (index = 0U; index < BSP_MPU_MAX_MPID_NUMBER; index++)
    {
        R_BSP_MPUSetMPIDx(index, 0);
    }

    /* Clear all regions */
    for (index = 0U; index < max_num_of_regions; index++)
    {
        RH850_MPU_RegionSet(index, 0, 0);
        RH850_MPU_AttrSet(index, 0);
    }
}

/*******************************************************************************************************************//**
 * This function return the number of regions enabled
 *
 * @retval Number of regions enabled
 **********************************************************************************************************************/
uint8_t R_BSP_MPURegionCountGet (void) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    uint8_t  region_num;
    uint8_t  region_count = 0U;
    uint32_t region_attr;
    uint8_t  max_num_of_regions = RH850_MPU_NumberofRegionsGet();

    for (region_num = 0U; region_num < max_num_of_regions; region_num++)
    {
        /* Get attribute for specific region */
        region_attr = RH850_MPU_AttrGet(region_num);
        if (0U != (region_attr & BSP_MPU_REGION_ENABLE))
        {
            region_count++;
        }
    }

    return region_count;
}

/*******************************************************************************************************************//**
 * This function set value for specific MPIDx register (x = 0 to 7)
 *
 * @param[in]  no_of_reg            MPID register's number
 * @param[in]  value                Value to be set
 *
 * @retval None
 **********************************************************************************************************************/
void R_BSP_MPUSetMPIDx (uint8_t no_of_reg, uint8_t value)
{
    value &= BSP_MPU_MPID_MASK;        /* PRQA S 1338 # Advisory R-17.8 */

    /* Set value for specific MPID register */
    RH850_MPU_MpidSet(no_of_reg, value);
}

/*******************************************************************************************************************//**
 * This function enables a specific region.
 *
 * @param[in]  p_region                Pointer to specific region configuration structure.
 *
 * @retval  FSP_SUCCESS              Region was enabled successfully.
 * @retval  FSP_ERR_ASSERTION        r_index exceeded max region supported.
 *                                   p_region is NULL.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MPURegionEnable (bsp_mpu_region_t * const p_region) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    fsp_err_t err = FSP_SUCCESS;
    uint32_t  attr_value;
    uint8_t   max_num_of_regions = RH850_MPU_NumberofRegionsGet();

#if BSP_CFG_PARAM_CHECKING_ENABLE

    /* Check whether the p_region is NULL */
    FSP_ASSERT(NULL != p_region);
#endif

    /* Check whether region's index exceed max regions supported */
    FSP_ASSERT(p_region->no_of_region < max_num_of_regions);

    /* Get attribute */
    attr_value = RH850_MPU_AttrGet(p_region->no_of_region);

    /* Enable region (set bit 7 in attribute value to 1) */
    attr_value |= BSP_MPU_REGION_ENABLE;

    /* Set attribute value for region again */
    RH850_MPU_AttrSet(p_region->no_of_region, attr_value);

    p_region->region_attr.attribute_b.region_enable = 1U;

    return err;
}

/*******************************************************************************************************************//**
 * This function disables a specific region.
 *
 * @param[in]  p_region                Pointer to specific region configuration structure.
 *
 * @retval  FSP_SUCCESS              Region was disabled successfully.
 * @retval  FSP_ERR_ASSERTION        r_index exceeded max region supported.
 *                                   p_region is NULL.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MPURegionDisable (bsp_mpu_region_t * const p_region) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    fsp_err_t err = FSP_SUCCESS;
    uint32_t  attr_value;
    uint8_t   max_num_of_regions = RH850_MPU_NumberofRegionsGet();

#if BSP_CFG_PARAM_CHECKING_ENABLE

    /* Check whether the p_region is NULL */
    FSP_ASSERT(NULL != p_region);
#endif

    /* Check whether region's index exceed max regions supported */
    FSP_ASSERT(p_region->no_of_region < max_num_of_regions);

    /* Get attribute */
    attr_value = RH850_MPU_AttrGet(p_region->no_of_region);

    /* Disable region (clear bit 7 in attribute value) */
    attr_value &= (uint32_t) ~BSP_MPU_REGION_ENABLE;

    /* Set attribute value for region again */
    RH850_MPU_AttrSet(p_region->no_of_region, attr_value);

    p_region->region_attr.attribute_b.region_enable = 0U;

    return err;
}

/*******************************************************************************************************************//**
 * This function sets up the access rules for a specific region.
 *
 * @param[in]  p_region                Pointer to specific region configuration structure.
 *
 * @retval  FSP_SUCCESS              Region was configured successfully.
 * @retval  FSP_ERR_ASSERTION        r_index exceeded max region supported.
 *                                   p_region is NULL.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MPURegionSet (bsp_mpu_region_t * const p_region) /* PRQA S 1503, 3673 # DP_MSR_R-2.1_UC1, Advisory R-8.13 */
{
    fsp_err_t err                = FSP_SUCCESS;
    uint8_t   max_num_of_regions = RH850_MPU_NumberofRegionsGet();

#if BSP_CFG_PARAM_CHECKING_ENABLE

    /* Check whether the p_region is NULL */
    FSP_ASSERT(NULL != p_region);
#endif

    /* Check whether region's index exceed max regions supported */
    FSP_ASSERT(p_region->no_of_region < max_num_of_regions);

    /* Set lower address and upper address for region */
    RH850_MPU_RegionSet(p_region->no_of_region, p_region->start_address, p_region->size);

    /* Set attribute for region */
    RH850_MPU_AttrSet(p_region->no_of_region, (p_region->region_attr.attribute));

    return err;
}

/*******************************************************************************************************************//**
 * This function gets the current settings for a specific region and store it in the passing argument.
 *
 * @param[in]  p_region_data           Pointer to specific region configuration structure.
 * @param[in]  r_index                 Index of specific region that user want to get setting.
 *
 * @retval  FSP_SUCCESS              Get region successfully.
 * @retval  FSP_ERR_ASSERTION        r_index exceeded max region supported.
 *                                   p_region_data is NULL.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MPURegionGet (bsp_mpu_region_t * const p_region_data, uint8_t r_index) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    fsp_err_t err = FSP_SUCCESS;
    uint32_t  attr_value;
    uint8_t   max_num_of_regions = RH850_MPU_NumberofRegionsGet();

#if BSP_CFG_PARAM_CHECKING_ENABLE

    /* Check whether the p_region_data is NULL */
    FSP_ASSERT(NULL != p_region_data);
#endif

    /* Check whether region's index exceed max regions supported */
    FSP_ASSERT(r_index < max_num_of_regions);

    p_region_data->start_address = RH850_MPU_LowerAddressGet(r_index);
    p_region_data->size          = RH850_MPU_UpperAddressGet(r_index) - p_region_data->start_address;
    attr_value = RH850_MPU_AttrGet(r_index);
    p_region_data->region_attr.attribute = attr_value;
    p_region_data->no_of_region          = r_index;

    return err;
}

/*******************************************************************************************************************//**
 * This function executes memory protection check for a SPID's specified address area. Checking range is from
 * "lower_add" to "lower_add" + "size" - 1.
 * (Value of SPID for each CPU can be read via register SR0, 1)
 *
 * @param[in]  spid                                System protection identifier.
 * @param[in]  lower_add                           Value for MPLA register.
 * @param[in]  size                                Size of region.
 * @param[out]  p_status                           Pointer to the variable that stores the status result.
 **********************************************************************************************************************/
void R_BSP_MPUExecuteMemProtectionCheck (uint8_t                      spid, /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
                                         uint32_t                     lower_add,
                                         uint32_t                     size, /* PRQA S 1710 # Advisory D-4.5 */
                                         bsp_mpu_mem_check_status_t * p_status)
{
    rh850_mpu_mem_status_t mem_check_status;

#if BSP_CFG_PARAM_CHECKING_ENABLE
    if (NULL == p_status)
    {
        return;
    }
#endif

    RH850_MPU_ExecMemProtectCheck(spid, lower_add, size, &mem_check_status);
    p_status->mpu_status.mem_check_status = mem_check_status.mpu_status.status;
}
