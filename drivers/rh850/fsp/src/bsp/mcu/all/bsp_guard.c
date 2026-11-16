/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"                   /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */
#include "bsp_guard.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void bsp_guard_channel_setting(const bsp_pbg_group_t pbg_group,
                                      const uint32_t        pbg_channels,
                                      const bool            pgb_enable);
static void bsp_guard_write_enable(const bsp_pbg_group_t pbg_group);
static void bsp_guard_write_disable(const bsp_pbg_group_t pbg_group);
static void bsp_peg_protection_setting(const bsp_guard_protection_setting_t * p_setting);
static void bsp_crg_protection_setting(const bsp_guard_protection_setting_t * p_setting);
static void bsp_intc2_guard_protection_setting(const bsp_guard_protection_setting_t * p_setting);
static void bsp_dts_guard_protection_setting(const bsp_guard_protection_setting_t * p_setting);
static void bsp_dmac_guard_protection_setting(const bsp_guard_protection_setting_t * p_setting);
static void bsp_ibg_protection_setting(const bsp_guard_protection_setting_t * p_setting);
static void bsp_pbg_protection_setting(const bsp_guard_protection_setting_t * p_setting);
static void bsp_peg_protection_status(bsp_guard_protection_status_t * p_status);
static void bsp_crg_protection_status(bsp_guard_protection_status_t * p_status);
static void bsp_intc2_guard_protection_status(bsp_guard_protection_status_t * p_status);
static void bsp_dts_guard_protection_status(bsp_guard_protection_status_t * p_status);
static void bsp_dmac_guard_protection_status(bsp_guard_protection_status_t * p_status);
static void bsp_ibg_protection_status(bsp_guard_protection_status_t * p_status);
static void bsp_pbg_protection_status(bsp_guard_protection_status_t * p_status);
static void bsp_guard_protection_status(void * p_cap_reg, bsp_protection_status_t * p_status);

#if (BSP_FEATURE_DFP_IS_AVAILABLE == 1 || BSP_FEATURE_DFA_IS_AVAILABLE == 1)
static void bsp_dataflow_guard_protection_setting(const bsp_guard_protection_setting_t * p_setting);
static void bsp_dataflow_guard_protection_status(bsp_guard_protection_status_t * p_status);

#endif

/** Guard protection setting configuration function table */
static const bsp_protection_setting guard_protection_setting[BSP_GUARD_TYPE_NUM] = /* PRQA S 3218 # Advisory R-8.9 */
{
    [BSP_GUARD_TYPE_PE_GUARD]    = &bsp_peg_protection_setting,
    [BSP_GUARD_TYPE_CRAM_GUARD]  = &bsp_crg_protection_setting,
    [BSP_GUARD_TYPE_IBUS_GUARD]  = &bsp_ibg_protection_setting,
    [BSP_GUARD_TYPE_PBUS_GUARD]  = &bsp_pbg_protection_setting,
    [BSP_GUARD_TYPE_INTC2_GUARD] = &bsp_intc2_guard_protection_setting,
    [BSP_GUARD_TYPE_DTS_GUARD]   = &bsp_dts_guard_protection_setting,
    [BSP_GUARD_TYPE_DMAC_GUARD]  = &bsp_dmac_guard_protection_setting,
#if (BSP_FEATURE_DFP_IS_AVAILABLE == 1)
    [BSP_GUARD_TYPE_DFP_GUARD] = &bsp_dataflow_guard_protection_setting,
#elif (BSP_FEATURE_DFA_IS_AVAILABLE == 1)
    [BSP_GUARD_TYPE_DFA_GUARD] = &bsp_dataflow_guard_protection_setting,
#endif
};

/** Guard protection status function table */
static const bsp_protection_status guard_protection_status[BSP_GUARD_TYPE_NUM] = /* PRQA S 3218 # Advisory R-8.9 */
{
    [BSP_GUARD_TYPE_PE_GUARD]    = &bsp_peg_protection_status,
    [BSP_GUARD_TYPE_CRAM_GUARD]  = &bsp_crg_protection_status,
    [BSP_GUARD_TYPE_IBUS_GUARD]  = &bsp_ibg_protection_status,
    [BSP_GUARD_TYPE_PBUS_GUARD]  = &bsp_pbg_protection_status,
    [BSP_GUARD_TYPE_INTC2_GUARD] = &bsp_intc2_guard_protection_status,
    [BSP_GUARD_TYPE_DTS_GUARD]   = &bsp_dts_guard_protection_status,
    [BSP_GUARD_TYPE_DMAC_GUARD]  = &bsp_dmac_guard_protection_status,
#if (BSP_FEATURE_DFP_IS_AVAILABLE == 1)
    [BSP_GUARD_TYPE_DFP_GUARD] = &bsp_dataflow_guard_protection_status,
#elif (BSP_FEATURE_DFA_IS_AVAILABLE == 1)
    [BSP_GUARD_TYPE_DFA_GUARD] = &bsp_dataflow_guard_protection_status,
#endif
};

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/******************************************************************************************************************//**
 * @addtogroup BSP_GUARD
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/*******************************************************************************************************************//**
 * Enable Write Access of all configured region that is enabled access on BSP MDF.
 **********************************************************************************************************************/
void R_BSP_GuardEnableAccessAll (void) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    uint32_t          channels;
    uint32_t          channel_num;
    bsp_pbg_group_t   pbg_grp;
    bsp_ibg_control_t ibg_target;
    bsp_peg_control_t peg_target;
    bsp_crg_control_t crg_target;

    uint8_t control_type;
    uint8_t module_count;
    uint8_t local_ram_count;
    uint8_t cluster_ram_count;
    uint8_t element_count;
    uint8_t max_element_count;
    uint8_t dmac_unit_count;
    uint8_t initial_cfg_value;

    /* Initialize all protection configuration to all zeros */
    bsp_guard_protection_setting_t pbg_setting = {.slave_guard_protection.pbusgrd_setting.group = BSP_PBG_GROUP_PBG00};
    bsp_guard_protection_setting_t ibg_setting =
    {
        .slave_guard_protection.ibusgrd_setting.control = BSP_IBG_CONTROL_IPIR_Rn
    };
    bsp_guard_protection_setting_t peg_setting = {.slave_guard_protection.pegrd_setting.control = BSP_PEG_CONTROL_PE0};
    bsp_guard_protection_setting_t crg_setting =
    {
        .slave_guard_protection.cramgrd_setting.control = BSP_CRG_CONTROL_CRAM0
    };
    bsp_guard_protection_setting_t intc2g_setting =
    {
        .slave_guard_protection.intc2grd_setting.control = BSP_INTC2G_CONTROL_EIBD_I2EIBG
    };
    bsp_guard_protection_setting_t dmag_setting =
    {
        .slave_guard_protection.dmagrd_setting.control = BSP_DMAG_CONTROL_GLOBAL_REG
    };
    bsp_guard_protection_setting_t dtsg_setting =
    {
        .slave_guard_protection.dtsgrd_setting.control = BSP_DTSG_CONTROL_COMMON_REG
    };

    /* PBG (Peripheral Bus Guard) & HBG (H-Bus Guard) Initialization */
    for (module_count = 0U; module_count < (uint8_t) BSP_MODULE_PBG_TOTAL_INDEX_END; module_count++)
    {
        initial_cfg_value = g_bsp_module_pbg_info_table[module_count].initial_cfg_value;

        if (1U == initial_cfg_value)
        {
            /* Get the number of elements (properties) for this PBG/HBG module */
            max_element_count = g_bsp_module_pbg_info_table[module_count].no_of_element;

            for (element_count = 0U; element_count < max_element_count; element_count++)
            {
                /* Get PBG group and channel information from configuration table */
                pbg_grp  = g_bsp_module_pbg_info_table[module_count].properties[element_count].pbg_group;
                channels = g_bsp_module_pbg_info_table[module_count].properties[element_count].pbg_channel;

                /* Enable full read/write access for all specified channels */
                while (0U != channels)
                {
                    /* Get the next channel to configure */
                    channel_num = (uint8_t) BSP_GUARD_GET_BIT(channels);                                              /* PRQA S 3469, 3432 # Advisory D-4.9, DP_MSR_R-20.7_UC1 */

                    pbg_setting.slave_guard_protection.pbusgrd_setting.group           = pbg_grp;
                    pbg_setting.slave_guard_protection.pbusgrd_setting.channel         = (uint8_t) channel_num;
                    pbg_setting.slave_guard_protection.pbusgrd_setting.protect_setting = BSP_GUARD_READ_WRITE_ACCESS; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

                    bsp_pbg_protection_setting(&pbg_setting);

                    /* Set this channel is configured */
                    channels &= ~((uint32_t) 1U << channel_num);
                }
            }
        }
    }

    /* IBG (Internal Bus Guard) Initialization */
    for (module_count = 0U; module_count < (uint8_t) BSP_MODULE_IBG_TOTAL_INDEX_END; module_count++)
    {
        initial_cfg_value = g_bsp_module_ibg_info_table[module_count].initial_cfg_value;

        if (1U == initial_cfg_value)
        {
            /* Get the number of protection targets for this IBG module */
            max_element_count = g_bsp_module_ibg_info_table[module_count].no_of_element;

            for (element_count = 0U; element_count < max_element_count; element_count++)
            {
                /* Get IBG target type (IPIR/BarrierSync/TPTM) and channel from configuration table */
                ibg_target = g_bsp_module_ibg_info_table[module_count].properties[element_count].ibg_control;
                channels   = g_bsp_module_ibg_info_table[module_count].properties[element_count].ibg_channel;

                /* Enable full read/write access for all specified channels */
                while (0U != channels)
                {
                    /* Get the next channel to configure */
                    channel_num = (uint8_t) BSP_GUARD_GET_BIT(channels);                                              /* PRQA S 3469, 3432 # Advisory D-4.9, DP_MSR_R-20.7_UC1 */

                    ibg_setting.slave_guard_protection.ibusgrd_setting.control         = ibg_target;
                    ibg_setting.slave_guard_protection.ibusgrd_setting.channel         = (uint8_t) channel_num;
                    ibg_setting.slave_guard_protection.ibusgrd_setting.protect_setting = BSP_GUARD_READ_WRITE_ACCESS; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

                    bsp_ibg_protection_setting(&ibg_setting);

                    /* Set this channel is configured */
                    channels &= ~((uint32_t) 1U << channel_num);
                }
            }
        }
    }

    /* PEG (PE Guard) Initialization - INTC1 & Local RAM Protection */
    for (local_ram_count = 0U; local_ram_count < (uint8_t) BSP_PEG_CONTROL_NUM; local_ram_count++)
    {
        initial_cfg_value = g_bsp_intc1_lram_info_table[local_ram_count].initial_cfg_value;

        if (1U == initial_cfg_value)
        {
            /* Get the PEG target for this Local RAM from configuration table */
            peg_target = g_bsp_intc1_lram_info_table[local_ram_count].lram_peg;

            peg_setting.slave_guard_protection.pegrd_setting.control = peg_target;

            /* Set base address for Local RAM protection region */
            peg_setting.slave_guard_protection.pegrd_setting.base_address = g_peg_lram_baseaddress[local_ram_count];

            /* Set protection size MAX to protect entire Local RAM and INTC1 area for this PE */
            peg_setting.slave_guard_protection.pegrd_setting.valid_address = (uint32_t) BSP_PEG_REGION_SIZE_MAX;

            peg_setting.slave_guard_protection.pegrd_setting.channel = BSP_GUARD_CHANNEL_DEFAULT;

            /* Enable full read/write access */
            peg_setting.slave_guard_protection.pegrd_setting.protect_setting = BSP_GUARD_READ_WRITE_ACCESS; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

            /* Apply protection setting for INTC1 and Local RAM on region */
            bsp_peg_protection_setting(&peg_setting);
        }
    }

    /* CRG (Cluster RAM Guard) Initialization */
    for (cluster_ram_count = 0U; cluster_ram_count < (uint8_t) BSP_CRG_CONTROL_NUM; cluster_ram_count++)
    {
        /* Check if this Cluster RAM target requires initial configuration */
        initial_cfg_value = g_bsp_cram_info_table[cluster_ram_count].initial_cfg_value;

        /* Get the CRG target for this Cluster RAM from configuration table */
        crg_target = g_bsp_cram_info_table[cluster_ram_count].cram_crg;

        if (1U == initial_cfg_value)
        {
            crg_setting.slave_guard_protection.cramgrd_setting.control = crg_target;

            /* Set base address for Cluster RAM protection region */
            crg_setting.slave_guard_protection.cramgrd_setting.base_address = g_crg_cram_baseaddress[cluster_ram_count];

            /* Set protection size 512 KB to protect entire Cluster RAM region */
            crg_setting.slave_guard_protection.cramgrd_setting.valid_address = (uint32_t) BSP_CRG_REGION_SIZE_512KB;

            crg_setting.slave_guard_protection.cramgrd_setting.channel = BSP_GUARD_CHANNEL_DEFAULT;

            /* Enable full read/write access */
            crg_setting.slave_guard_protection.cramgrd_setting.protect_setting = BSP_GUARD_READ_WRITE_ACCESS; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

            /* Apply protection setting for Cluster RAM on region */
            bsp_crg_protection_setting(&crg_setting);
        }
    }

    /* Check if DMA access protection is enabled in configuration */
    if (BSP_GUARD_DMA_WRITE_PROTECTION == 1)                                                              /* PRQA S 2741 # DP_MSR_R-14.3_UC1 */
    {
        /* Enable full read/write access */
        dmag_setting.slave_guard_protection.dmagrd_setting.protect_setting = BSP_GUARD_READ_WRITE_ACCESS; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        for (dmac_unit_count = (uint8_t) BSP_DMAG_UNIT_0;
             dmac_unit_count < (uint8_t) BSP_DMAG_UNIT_NUM;
             dmac_unit_count++)
        {
            dmag_setting.slave_guard_protection.dmagrd_setting.unit =
                (bsp_dmag_unit_t) dmac_unit_count; /* PRQA S 4342 # Advisory R-10.5 */

            /* Configure protect DMAC common registers */
            for (control_type = 0U; control_type < (uint8_t) BSP_DMAG_CONTROL_CHANNEL_REG; control_type++)
            {
                dmag_setting.slave_guard_protection.dmagrd_setting.control =
                    (bsp_dmag_control_t) control_type; /* PRQA S 4342 # Advisory R-10.5 */

                bsp_dmac_guard_protection_setting(&dmag_setting);
            }

            /* Configure protect DMAC channel registers */
            for (channels = 0; channels < BSP_FEATURE_DMAC_GUARD_MAX_CHANNEL; channels++)
            {
                dmag_setting.slave_guard_protection.dmagrd_setting.control = BSP_DMAG_CONTROL_CHANNEL_REG;
                dmag_setting.slave_guard_protection.dmagrd_setting.channel = (uint16_t) channels;

                bsp_dmac_guard_protection_setting(&dmag_setting);
            }
        }
    }

    /* Check if DTS write protection is enabled in configuration */
    if (BSP_GUARD_DTS_WRITE_PROTECTION == 1) /* PRQA S 2741 # DP_MSR_R-14.3_UC1 */
    {
        dtsg_setting.slave_guard_protection.dtsgrd_setting.control = BSP_DTSG_CONTROL_COMMON_REG;

        /* Enable full read/write access for DTS */
        dtsg_setting.slave_guard_protection.dtsgrd_setting.protect_setting = BSP_GUARD_READ_WRITE_ACCESS; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Configure protect DTS common registers */
        bsp_dts_guard_protection_setting(&dtsg_setting);

        /* Configure protect DTS all channel registers */
        for (channels = 0; channels < BSP_FEATURE_DTS_GUARD_MAX_CHANNEL; channels++)
        {
            dtsg_setting.slave_guard_protection.dtsgrd_setting.control = BSP_DTSG_CONTROL_CHANNEL_REG;
            dtsg_setting.slave_guard_protection.dtsgrd_setting.channel = (uint16_t) channels;

            bsp_dts_guard_protection_setting(&dtsg_setting);
        }
    }

#if (BSP_FEATURE_DFP_IS_AVAILABLE == 1 || BSP_FEATURE_DFA_IS_AVAILABLE == 1)

    /* Check if Data Flow Processor/Architecture) write protection is enabled in configuration */
    if (BSP_GUARD_DATAFLOW_WRITE_PROTECTION == 1) /* PRQA S 2741 # DP_MSR_R-14.3_UC1 */
    {
        bsp_guard_protection_setting_t dataflow_setting = {.slave_guard_protection.dataflowgrd_setting = {0}};

        dataflow_setting.slave_guard_protection.dataflowgrd_setting.channel = BSP_GUARD_CHANNEL_DEFAULT;

        /* Set base address for Data Flow protection region */
        dataflow_setting.slave_guard_protection.dataflowgrd_setting.base_address = BSP_GUARD_DATAFLOW_BASE_ADDRESS;

        /* Set valid bit mask to 0 to protect entire Data Flow region */
        dataflow_setting.slave_guard_protection.dataflowgrd_setting.valid_address = (uint32_t) BSP_PEG_REGION_SIZE_MAX;

        /* Set protection control to enable access for all bus masters to Data Flow resources */
        dataflow_setting.slave_guard_protection.dataflowgrd_setting.protect_setting = BSP_GUARD_READ_WRITE_ACCESS; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Apply protection setting to Data Flow Guard region to control read/write access */
        bsp_dataflow_guard_protection_setting(&dataflow_setting);
    }
#endif

    /* Check if INTC2 guard protection is enabled in configuration */
    if (BSP_GUARD_INTC2_WRITE_PROTECTION == 1)                                                                /* PRQA S 2741 # DP_MSR_R-14.3_UC1 */
    {
        /* Enable full read/write access */
        intc2g_setting.slave_guard_protection.intc2grd_setting.protect_setting = BSP_GUARD_READ_WRITE_ACCESS; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Configure INTC2 common registers (EIBG/I2EIBG/IMR) */
        for (control_type = 0U; control_type < (uint8_t) BSP_INTC2G_CONTROL_EIC_EEIC; control_type++)
        {
            intc2g_setting.slave_guard_protection.intc2grd_setting.control =
                (bsp_intc2g_control_t) control_type; /* PRQA S 4342 # Advisory R-10.5 */
            bsp_intc2_guard_protection_setting(&intc2g_setting);
        }

        /* Configure INTC2 channel registers (EIC/EEIC) */
        for (channels = BSP_FEATURE_INTC2_GUARD_MIN_CHANNEL; channels < BSP_FEATURE_INTC2_GUARD_MAX_CHANNEL; channels++)
        {
            intc2g_setting.slave_guard_protection.intc2grd_setting.control = BSP_INTC2G_CONTROL_EIC_EEIC;
            intc2g_setting.slave_guard_protection.intc2grd_setting.channel = (uint16_t) channels;
            bsp_intc2_guard_protection_setting(&intc2g_setting);
        }
    }
}

/*******************************************************************************************************************//**
 * Enable Write access to guarded region. Region that are guarded cannot be written to. Register guard is
 * control by Peripheral Guard (PBG) and H-Peripheral Guard (HBG).
 *
 * @param[in] pbg_group      Guard group index to enable
 * @param[in] pbg_channels   Guard channel index to enable
 **********************************************************************************************************************/
void R_BSP_GuardAccessEnable (const bsp_pbg_group_t pbg_group, const uint32_t pbg_channels) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    /* Enable Write access to guarded region */
    bsp_guard_channel_setting(pbg_group, pbg_channels, true);
}

/*******************************************************************************************************************//**
 * Disable Write access guarded region. Region that are guarded cannot be written to. Register guard is
 * control by Peripheral Guard (PBG) and H-Peripheral Guard (HBG).
 *
 * @param[in] pbg_group      Guard group index to enable
 * @param[in] pbg_channels   Guard channel index to enable
 **********************************************************************************************************************/
void R_BSP_GuardAccessDisable (const bsp_pbg_group_t pbg_group, const uint32_t pbg_channels) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    /* Disable Write access to guarded region */
    bsp_guard_channel_setting(pbg_group, pbg_channels, false);
}

/*******************************************************************************************************************//**
 * @brief Configures access protection for resources managed by the specified guard module.
 *
 * This API provides a common interface to configure all guard types in the system.
 * Guards control access to protected resources from bus masters. If a guard detects illegal access,
 * guard error notification is signaled to ECM.
 *
 * Supported guard types:
 * - BSP_GUARD_TYPE_PE_GUARD    : Protects PE Local RAM and INTC1 registers
 * - BSP_GUARD_TYPE_CRAM_GUARD  : Protects Cluster RAM area
 * - BSP_GUARD_TYPE_IBUS_GUARD  : Protects I-Bus modules (IPIR, BarrierSync, TPTM)
 * - BSP_GUARD_TYPE_PBUS_GUARD  : Protects Peripheral Bus (PBG/HBG) groups
 * - BSP_GUARD_TYPE_INTC2_GUARD : Protects INTC2 registers
 * - BSP_GUARD_TYPE_DTS_GUARD   : Protects DTS registers
 * - BSP_GUARD_TYPE_DMAC_GUARD  : Protects sDMAC registers
 * - BSP_GUARD_TYPE_DFP_GUARD   : Protects DFP resources (if supported by device)
 * - BSP_GUARD_TYPE_DFA_GUARD   : Protects DFA resources (if supported by device)
 *
 *
 * @param[in] guard_type        Type of guard module to configure
 * @param[in] p_guard_setting   Pointer to the configuration structure containing guard settings.
 *
 * @note The required fields and configuration options within the structure may vary depending on the specific guard type.
 *
 * @note For PE Guard, Cluster RAM Guard, and DFP/DFA Guard (if device supports): Regions not covered
 *       by any protection setting will deny access by default when at least one channel has guard protection enabled.
 **********************************************************************************************************************/
void R_BSP_GuardProtectionSetting (const bsp_guard_type_t                 guard_type, /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
                                   const bsp_guard_protection_setting_t * p_guard_setting)
{
    if ((NULL == p_guard_setting) || (guard_type >= BSP_GUARD_TYPE_NUM))
    {
        return;
    }

    bsp_guard_type_t type;
    const bsp_guard_protection_setting_t * p_setting;

    /** Get guard type */
    type = (bsp_guard_type_t) guard_type;

    /** Get pointer to protection settings */
    p_setting = (const bsp_guard_protection_setting_t *) p_guard_setting;

    /** Call the appropriate guard configuration handler if valid */
    if (NULL != guard_protection_setting[type])
    {
        guard_protection_setting[type](p_setting);
    }

    /** Sync to ensure protection setting is effective */
    __SYNCP();                                                                                                       /* PRQA S 3469 # Advisory D-4.9 */
}

/*******************************************************************************************************************//**
 * @brief Retrieves protection status for the specified guard module.
 *
 * Guards control access to protected resources from bus masters. This API retrieves the current
 * protection status and error information for the specified guard type.
 *
 * Supported guard types:
 * - BSP_GUARD_TYPE_PE_GUARD    : Status of PE Local RAM and INTC1 registers protection
 * - BSP_GUARD_TYPE_CRAM_GUARD  : Status of Cluster RAM area protection
 * - BSP_GUARD_TYPE_IBUS_GUARD  : Status of I-Bus modules (IPIR, BarrierSync, TPTM) protection
 * - BSP_GUARD_TYPE_PBUS_GUARD  : Status of Peripheral Bus (PBG/HBG) groups protection
 * - BSP_GUARD_TYPE_INTC2_GUARD : Status of INTC2 registers protection
 * - BSP_GUARD_TYPE_DTS_GUARD   : Status of DTS registers protection
 * - BSP_GUARD_TYPE_DMAC_GUARD  : Status of sDMAC registers protection
 * - BSP_GUARD_TYPE_DFP_GUARD   : Status of DFP resources protection (if supported by device)
 * - BSP_GUARD_TYPE_DFA_GUARD   : Status of DFA resources protection (if supported by device)
 *
 * @param[in]  guard_type     Type of guard module to query
 * @param[out] p_guard_status Pointer to structure where protection status will be stored
 *
 * @note Error information includes:
 *       - Error status         : Normal, error occurred, or overflow
 *       - Error address        : Address that caused the guard error
 *       - Error attributes     : Access type (SEC, DBG, UM, SPID, WRITE/READ)
 *       - Error SPID status    : SPID bitmap showing which SPID caused the access error
 *
 * @note The availability and granularity of these details may vary depending on the specific guard type.
 *
 * @note All error flags are cleared automatically after reading to prepare for next error detection.
 *
 **********************************************************************************************************************/
void R_BSP_GuardProtectionStatus (const bsp_guard_type_t guard_type, bsp_guard_protection_status_t * p_guard_status) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    bsp_guard_type_t                type;
    bsp_guard_protection_status_t * p_status;

    /** Get guard type */
    type = (bsp_guard_type_t) guard_type;

    /* Get pointer to protection status structure */
    p_status = (bsp_guard_protection_status_t *) p_guard_status;

    if ((NULL == p_status) || (BSP_GUARD_TYPE_NUM <= guard_type))
    {
        return;
    }

    /* Call the appropriate guard status handler if valid */
    if (NULL != guard_protection_status[type])
    {
        guard_protection_status[type](p_status);
    }
}

/*******************************************************************************************************************//**
 * @brief Configures access protection for Local RAM area and INTC1 registers using the selected PE Guard (PEG).
 *
 * When all guards are disabled, all masters can access both the Local RAM area and INTC1 registers.
 * When at least one channel is enabled, access is restricted according to the specified settings.
 * Any unauthorized access will trigger an error notification to the ECM.
 *
 * @param[in] p_setting     Protection settings and access configuration.
 *
 * @note Regions not covered by any protection setting will deny access by default (when at least one channel enable guard protect setting).
 *
 **********************************************************************************************************************/
static void bsp_peg_protection_setting (const bsp_guard_protection_setting_t * p_setting)
{
    uint8_t           channel;
    bsp_peg_control_t peg_control;
    const bsp_peg_protection_setting_t * p_peg_setting;
    R_GUARD_PE0_Type * p_peg_protect_setting;

    /* Get pointer to PEG-specific settings from the guard configuration */
    p_peg_setting = (const bsp_peg_protection_setting_t *) (&p_setting->slave_guard_protection.pegrd_setting);

    /* Get PE target and channel number from protection settings */
    peg_control = p_peg_setting->control;
    channel     = p_peg_setting->channel;

    /* Get the base address of the PEG protection control register */
    p_peg_protect_setting = (R_GUARD_PE0_Type *) g_peg_baseaddress[peg_control];                                      /* PRQA S 0306 # Advisory R-11.4 */

    /* Enable write access to protected PEG registers using keycode 0xA5A5A501 */
    p_peg_protect_setting->PEGKCPROT = BSP_PRV_KEYCODE_ENABLE;                                                        /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Write protection configuration settings for SPID, base address, size protection, and protection attributes */
    p_peg_protect_setting->PEG_CTR[channel].SPID = p_peg_setting->spid;                                               /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    p_peg_protect_setting->PEG_CTR[channel].BAD  = p_peg_setting->base_address;                                       /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    p_peg_protect_setting->PEG_CTR[channel].ADV  = (p_peg_setting->valid_address << R_GUARD_PE0_PEG_CTR_ADV_ADV_Pos); /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    p_peg_protect_setting->PEG_CTR[channel].PROT = p_peg_setting->protect_setting;                                    /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Disable write access to protected PEG registers using keycode 0xA5A5A500 */
    p_peg_protect_setting->PEGKCPROT = BSP_PRV_KEYCODE_DISABLE;                                                       /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * @brief Retrieves the protection status and error information from PEG capture modules for the specified PE.
 *
 * This function reads error status from both PEGCAP_S (INTC1 register & LRAM) and PEGCAP_M (Load LRAM from PEx) capture modules.
 * It checks for overflow errors, captures error addresses, access attributes, and SPID error flags.
 *
 * @param[out] p_status       Pointer to structure that will receive the protection status and error details.
 *
 **********************************************************************************************************************/
static void bsp_peg_protection_status (bsp_guard_protection_status_t * p_status)
{
    bsp_peg_control_t             peg_control;
    bsp_peg_protection_status_t * p_peg_status;
    bsp_protection_status_t     * p_guard_status;
    R_PEGCAP_S_PE0CL0_Type      * p_pegcap_reg;

    uint8_t index_access;

    /* Get the base address of PEGCAP_S register for the specified PE */
    p_peg_status = (bsp_peg_protection_status_t *) &p_status->pegrd_status;        /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    peg_control  = p_peg_status->control;
    p_pegcap_reg = (R_PEGCAP_S_PE0CL0_Type *) g_pegcap_s_baseaddress[peg_control]; /* PRQA S 0306 # Advisory R-11.4 */

    /* Loop through all capture modules: PEGCAP_S and PEGCAP_M for each PE */
    for (index_access = 0; index_access < BSP_FEATURE_PE_GUARD_STATUS_MAX; index_access++)
    {
        /* Get pointer to the status structure for PEG capture module */
        p_guard_status = &p_peg_status->peg_status[index_access];

        /* Retrieve error status from current capture module */
        bsp_guard_protection_status(p_pegcap_reg, p_guard_status);

#if (BSP_FEATURE_PEGCAP_M_IS_AVAILABLE == 1)
        if (sizeof(g_pegcap_m_baseaddress) / sizeof(uint32_t) > index_access) {
            /* Move to the next capture module (PEGCAP_M for PE0, PE1, PE2, PE3), Not available in U2Cx device  */
            p_pegcap_reg = (R_PEGCAP_S_PE0CL0_Type *) g_pegcap_m_baseaddress[index_access]; /* PRQA S 0306 # Advisory R-11.4 */
        }
#endif
    }
}

/*******************************************************************************************************************//**
 * @brief Configures access protection for Cluster RAM using the selected Cluster RAM Guard (CRG).
 *
 * When all guards are disabled, all bus masters can access Cluster RAM freely.
 * When at least one channel is enabled, access is restricted according to the specified settings.
 * Any unauthorized access will trigger an error notification to the ECM.
 *
 * @param[in] p_setting     Protection settings and access configuration.
 *
 * @note Regions not covered by any protection setting will deny access by default (when at least one channel enable guard protect setting).
 *
 **********************************************************************************************************************/
static void bsp_crg_protection_setting (const bsp_guard_protection_setting_t * p_setting)
{
    uint8_t           channel;
    bsp_crg_control_t crg_control;
    const bsp_crg_protection_setting_t * p_crg_setting;
    R_GUARD_CRAMCRG0_Type              * p_crg_protect_setting;

    /* Get pointer to CRG-specific settings from the guard configuration */
    p_crg_setting = (const bsp_crg_protection_setting_t *) (&p_setting->slave_guard_protection.cramgrd_setting);

    /* Get Cluster RAM target and channel number from settings */
    crg_control = p_crg_setting->control;
    channel     = p_crg_setting->channel;

    /* Get the base address of the CRG protection control register */
    p_crg_protect_setting = (R_GUARD_CRAMCRG0_Type *) g_crg_baseaddress[crg_control]; /* PRQA S 0306 # Advisory R-11.4 */

    /* Enable write access to protected CRG registers using keycode 0xA5A5A501*/
    p_crg_protect_setting->CRGKCPROT = BSP_PRV_KEYCODE_ENABLE;                        /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Write protection configuration settings for SPID, base address, size protection, and protection attributes */
    p_crg_protect_setting->CRG_CTR[channel].SPID = p_crg_setting->spid;               /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    p_crg_protect_setting->CRG_CTR[channel].BAD  = p_crg_setting->base_address;       /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    p_crg_protect_setting->CRG_CTR[channel].ADV  =                                    /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                                   (p_crg_setting->valid_address <<
                                                   R_GUARD_CRAMCRG0_CRG_CTR_ADV_ADV_Pos);
    p_crg_protect_setting->CRG_CTR[channel].PROT = p_crg_setting->protect_setting;    /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Disable write access to protected CRG registers using keycode 0xA5A5A500*/
    p_crg_protect_setting->CRGKCPROT = BSP_PRV_KEYCODE_DISABLE;                       /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * @brief Retrieves the protection status and error information from CRG capture modules for the specified Cluster RAM.
 *
 * This function reads error status from multiple CRG capture modules including CRAMH/CRAML (Store requests),
 * SX2MBH/SX2MBL (Load/Fetch from non-PEs), and PEx (Load from each PE).
 * It checks for overflow errors, captures error addresses, access attributes, and SPID error flags.
 *
 * @param[out] p_status       Pointer to structure that will receive the protection status and error details.
 *
 **********************************************************************************************************************/
static void bsp_crg_protection_status (bsp_guard_protection_status_t * p_status)
{
    bsp_crg_control_t             crg_control;
    bsp_crg_protection_status_t * p_crg_status;
    bsp_protection_status_t     * p_guard_status;
    R_CRGCAP_CRAMHCL0_Type      * p_crgcap_reg;

    uint8_t index_access;

    /* Get pointer to status structure */
    p_crg_status = (bsp_crg_protection_status_t *) &p_status->cramgrd_status; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    crg_control  = p_crg_status->control;

    /* Loop through all CRG capture modules for the selected Cluster RAM */
    for (index_access = 0; index_access < BSP_FEATURE_CRAM_GUARD_STATUS_MAX; index_access++)
    {
        /* Get pointer to the status structure for CRG capture module */
        p_crgcap_reg = (R_CRGCAP_CRAMHCL0_Type *) g_crgcap_baseaddress[crg_control][index_access]; /* PRQA S 0306 # Advisory R-11.4 */

        /* Get pointer to the status structure for CRG capture module */
        p_guard_status = &p_crg_status->crg_status[index_access];

        /* Retrieve error status from current capture module */
        bsp_guard_protection_status(p_crgcap_reg, p_guard_status);
    }
}

/*******************************************************************************************************************//**
 * @brief Configures access protection for INTC2 registers using the selected INTC2 Guard.
 *
 * INTC2 Guard is one of the slave guards used to control the access to INTC2 registers.
 * INTC2 Guard can protect respectively the read and write access against INTC2 registers of each channel.
 * If INTC2 Guard detects illegal access, guard error notification is signaled to ECM.
 *
 * @param[in] p_setting    Protection settings and access configuration.
 *
 **********************************************************************************************************************/
static void bsp_intc2_guard_protection_setting (const bsp_guard_protection_setting_t * p_setting)
{
    uint16_t             channel;
    bsp_intc2g_control_t intc2_guard_control;
    const bsp_intc2g_protection_setting_t * p_intc2_guard_setting;
    R_GUARD_INTC2_Type * p_intc2_guard_protect_setting;

    /* Get pointer to INTC2 Guard-specific settings from the guard configuration */
    p_intc2_guard_setting =
        (const bsp_intc2g_protection_setting_t *) (&p_setting->slave_guard_protection.intc2grd_setting);

    /* Get the base address of the INTC2 protection control register */
    p_intc2_guard_protect_setting = (R_GUARD_INTC2_Type *) R_GUARD_INTC2_BASE; /* PRQA S 0306 # Advisory R-11.4 */

    /* Get INTC2 Group register target and channel number for EIC/EEIC (if have) protection from settings */
    channel             = p_intc2_guard_setting->channel;
    intc2_guard_control = p_intc2_guard_setting->control;

    /* Enable write access to protected INTC2 Guard registers using keycode 0xA5A5A501 */
    p_intc2_guard_protect_setting->INTC2GKCPROT = BSP_PRV_KEYCODE_ENABLE; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Write SPID values to MPID Setting Registers */
    for (uint8_t index = 0U; index < 8U; index++)
    {
        p_intc2_guard_protect_setting->INTC2GMPID[index] = p_intc2_guard_setting->spid[index]; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }

    /* Write protection control register to protect read/write access for the selected INTC2 register group */
    if (BSP_INTC2G_CONTROL_EIC_EEIC == intc2_guard_control)
    {
        p_intc2_guard_protect_setting->INTC2GPROT_CH[channel] = p_intc2_guard_setting->protect_setting;                 /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }
    else
    {
        p_intc2_guard_protect_setting->INTC2GPROT_GR_IMR[intc2_guard_control] = p_intc2_guard_setting->protect_setting; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }

    /* Disable write access to protected INTC2 Guard registers using keycode 0xA5A5A500 */
    p_intc2_guard_protect_setting->INTC2GKCPROT = BSP_PRV_KEYCODE_DISABLE;                                              /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * @brief Retrieves the protection status and error information from INTC2 Guard for INTC2 registers.
 *
 * This function reads error status from the INTC2 Guard module. It checks for overflow errors,
 * captures error addresses, access attributes, and SPID error flags.
 *
 * @param[out] p_status    Pointer to structure that will receive the protection status and error details.
 *
 **********************************************************************************************************************/
static void bsp_intc2_guard_protection_status (bsp_guard_protection_status_t * p_status)
{
    R_GUARD_INTC2_Type      * p_intc2cap_reg;
    bsp_protection_status_t * p_intc2g_status;

    /* Get the base address of INTC2 Guard register */
    p_intc2cap_reg = (R_GUARD_INTC2_Type *) R_GUARD_INTC2_BASE;               /* PRQA S 0306 # Advisory R-11.4 */

    /* Get pointer to the status structure for INTC2 Guard capture module */
    p_intc2g_status = (bsp_protection_status_t *) &p_status->intc2grd_status; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Retrieve error status from current capture module */
    bsp_guard_protection_status(p_intc2cap_reg, p_intc2g_status);
}

/*******************************************************************************************************************//**
 * @brief Configures access protection for DTS registers using the selected DTS Guard.
 *
 * DTS Guard is one of the slave guards used to control the access to the registers for DTS transfer.
 * DTS Guard can prevent read and write access to the DTS registers of each channel.
 * If DTS Guard detects illegal access, guard error notification is signaled to ECM.
 *
 * @param[in] p_setting    Protection settings and access configuration.
 *
 **********************************************************************************************************************/
static void bsp_dts_guard_protection_setting (const bsp_guard_protection_setting_t * p_setting)
{
    uint16_t channel;
    const bsp_dtsg_protection_setting_t * p_dts_guard_setting;
    bsp_dtsg_control_t dts_guard_control;
    R_GUARD_DTS_Type * p_dtsg_protect_setting;

    /* Get pointer to DTS Guard-specific settings from the guard configuration */
    p_dts_guard_setting = (const bsp_dtsg_protection_setting_t *) (&p_setting->slave_guard_protection.dtsgrd_setting);

    /* Get the base address of the DTS guard protection control register */
    p_dtsg_protect_setting = (R_GUARD_DTS_Type *) R_GUARD_DTS_BASE; /* PRQA S 0306 # Advisory R-11.4 */

    /* Get DTS Group register target and channel number for CH specific register (if have) protection from settings */
    channel           = p_dts_guard_setting->channel;
    dts_guard_control = p_dts_guard_setting->control;

    /* Enable write access to protected DTS Guard registers using keycode 0xA5A5A501*/
    p_dtsg_protect_setting->DTSGKCPROT = BSP_PRV_KEYCODE_ENABLE; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Write SPID values to MPID Setting Registers */
    for (uint8_t index = 0U; index < 8U; index++)
    {
        p_dtsg_protect_setting->DTSGMPID[index] = p_dts_guard_setting->spid[index]; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }

    /* Write protection control register to protect read/write access for the selected DTS register group */
    if (BSP_DTSG_CONTROL_CHANNEL_REG == dts_guard_control)
    {
        p_dtsg_protect_setting->DTSGPROT_CH[channel] = p_dts_guard_setting->protect_setting; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }
    else
    {
        p_dtsg_protect_setting->DTSGPROT_GR = p_dts_guard_setting->protect_setting;          /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }

    /* Disable write access to protected DTS Guard registers using keycode 0xA5A5A500 */
    p_dtsg_protect_setting->DTSGKCPROT = BSP_PRV_KEYCODE_DISABLE;                            /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * @brief Retrieves the protection status and error information from DTS Guard for DTS registers.
 *
 * This function reads error status from the DTS Guard module. It checks for overflow errors,
 * captures error addresses, access attributes, and SPID error flags.
 *
 * @param[out] p_status    Pointer to structure that will receive the protection status and error details.
 *
 **********************************************************************************************************************/
static void bsp_dts_guard_protection_status (bsp_guard_protection_status_t * p_status)
{
    R_GUARD_DTS_Type        * p_dtsgcap_reg;
    bsp_protection_status_t * p_dtsg_status;

    /* Get the base address of DTS Guard register */
    p_dtsgcap_reg = (R_GUARD_DTS_Type *) R_GUARD_DTS_BASE;                /* PRQA S 0306 # Advisory R-11.4 */

    /* Get pointer to the status structure for DTS Guard capture module */
    p_dtsg_status = (bsp_protection_status_t *) &p_status->dtsgrd_status; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Retrieve error status from current capture module */
    bsp_guard_protection_status(p_dtsgcap_reg, p_dtsg_status);
}

/*******************************************************************************************************************//**
 * @brief Configures access protection for sDMAC registers using the selected sDMAC Guard.
 *
 * sDMAC Guard is one of the slave guards used to control the access to the registers for sDMAC transfer.
 * sDMAC Guard can prevent read and write access to the sDMAC registers of each channel.
 * If sDMAC Guard detects illegal access, guard error notification is signaled to ECM.
 *
 * @param[in] p_setting    Protection settings and access configuration.
 *
 **********************************************************************************************************************/
static void bsp_dmac_guard_protection_setting (const bsp_guard_protection_setting_t * p_setting)
{
    bsp_dmag_unit_t    dma_guard_unit;
    bsp_dmag_control_t dma_guard_control;
    const bsp_dmag_protection_setting_t * p_dmac_guard_setting;
    uint16_t             channel;
    R_GUARD_DMAC0_Type * dmacg_protect_setting;

    /* Get pointer to DMAC Guard-specific settings from the guard configuration */
    p_dmac_guard_setting = (const bsp_dmag_protection_setting_t *) (&p_setting->slave_guard_protection.dmagrd_setting);

    /* Get DTM Unit ,Group register target and channel number for CH specific register (if have) protection from settings */
    dma_guard_unit    = p_dmac_guard_setting->unit;
    dma_guard_control = p_dmac_guard_setting->control;
    channel           = p_dmac_guard_setting->channel;

    /* Get the base address of the DMA guard protection control register */
    dmacg_protect_setting = (R_GUARD_DMAC0_Type *) g_dmacg_baseaddress[dma_guard_unit]; /* PRQA S 0306 # Advisory R-11.4 */

    /* Enable write access to protected DMAC Guard registers using keycode 0xA5A5A501 */
    dmacg_protect_setting->DMAGKCPROT = BSP_PRV_KEYCODE_ENABLE;                         /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Write SPID values to MPID Setting */
    for (uint8_t index = 0U; index < 8U; index++)
    {
        dmacg_protect_setting->DMAGMPID[index] = p_dmac_guard_setting->spid[index]; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }

    /* Write protection control register to protect access for the selected DMAC register group */
    if (BSP_DMAG_CONTROL_CHANNEL_REG == dma_guard_control)
    {
        dmacg_protect_setting->DMAGPROT_CH[channel] = p_dmac_guard_setting->protect_setting;                     /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }
    else
    {
        dmacg_protect_setting->DMAGPROT_GR_DP_CR_CTR[dma_guard_control] = p_dmac_guard_setting->protect_setting; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }

    /* Disable write access to protected DMAC Guard registers using keycode 0xA5A5A500 */
    dmacg_protect_setting->DMAGKCPROT = BSP_PRV_KEYCODE_DISABLE;                                                 /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * @brief Retrieves the protection status and error information from sDMAC Guard for sDMAC registers.
 *
 * This function reads error status from the sDMAC Guard capture module. It checks for overflow errors,
 * captures error addresses, access attributes, and SPID error flags.
 *
 * @param[out] p_status       Pointer to structure that will receive the protection status and error details.
 *
 **********************************************************************************************************************/
static void bsp_dmac_guard_protection_status (bsp_guard_protection_status_t * p_status)
{
    bsp_dmag_unit_t dma_guard_unit;
    bsp_dmac_guard_protection_status_t * p_dmag_protect_status;
    bsp_protection_status_t            * p_dmacg_status;
    R_GUARD_DMAC0_Type                 * p_dmaccap_reg;

    /* Get pointer to the status structure for DMA Guard capture module */
    p_dmag_protect_status = (bsp_dmac_guard_protection_status_t *) &p_status->dmagrd_status; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    dma_guard_unit = p_dmag_protect_status->dma_guard_unit;

    p_dmacg_status = (bsp_protection_status_t *) &p_dmag_protect_status->status;

    /* Get the base address of sDMAC Guard register */
    p_dmaccap_reg = (R_GUARD_DMAC0_Type *) g_dmacg_baseaddress[dma_guard_unit]; /* PRQA S 0306 # Advisory R-11.4 */

    /* Retrieve error status from current capture module */
    bsp_guard_protection_status(p_dmaccap_reg, p_dmacg_status);
}

/*******************************************************************************************************************//**
 * @brief Configures access protection for I-Bus module registers using the selected IBG.
 *
 * I-Bus Guard (IBG) is one of the slave guards used to control the access to I-Bus modules (IPIR, BarrierSync, TPTM).
 * IBG can prevent read and write access to the registers of each module.
 * If IBG detects illegal access, guard error notification is signaled to ECM.
 *
 * @param[in] p_setting     Protection settings and access configuration.
 *
 **********************************************************************************************************************/
static void bsp_ibg_protection_setting (const bsp_guard_protection_setting_t * p_setting)
{
    bsp_ibg_control_t ibg_control;
    const bsp_ibg_protection_setting_t * p_ibg_setting;
    volatile uint32_t * p_ibgprot;
    volatile uint32_t * p_ibgkcprot;
    bool                use_channel;
    uint8_t             channels;
    uint8_t             prot_channel_offset;

    /* Get pointer to IBus Guard-specific settings from the guard configuration */
    p_ibg_setting = (const bsp_ibg_protection_setting_t *) (&p_setting->slave_guard_protection.ibusgrd_setting);

    /* Get IBUS module Group register target protection from settings */
    ibg_control = p_ibg_setting->control;

    /* Determine if the selected control target uses channel indexing */
    use_channel = ((BSP_IBG_CONTROL_IPIR_4 != ibg_control) &&
                   (BSP_IBG_CONTROL_BARR_16 != ibg_control) &&
                   (BSP_IBG_CONTROL_TPTM_U8 != ibg_control) &&
                   (BSP_IBG_CONTROL_TPTM_U9 != ibg_control));

    /* Calculate register offset based on control type */
    prot_channel_offset = ((BSP_IBG_CONTROL_IPIR_Rn == ibg_control) ||
                           (BSP_IBG_CONTROL_IPIR_Tn == ibg_control)) ?
                          BSP_IBG_IPIR_PROT_CHANNEL_OFFSET :
                          (use_channel ? BSP_IBG_BARR_TPTM_PROT_CHANNEL_OFFSET : 0x00U);

    /* Set channel number for channel-based targets, otherwise 0 */
    channels = use_channel ? p_ibg_setting->channel : 0x00U;

    /* Get the base address of the Key Code Protection Register */
    p_ibgkcprot = (volatile uint32_t *) (g_ibg_baseaddress[ibg_control] + /* PRQA S 0303 # Advisory R-11.4 */
                                         BSP_GUARD_KCPROT_ADDRESS_OFFSET);

    /* Calculate address of Protection Control Register for the target and channel */
    p_ibgprot =
        (volatile uint32_t *) (g_ibgprot_baseaddress[ibg_control] + /* PRQA S 0303 # Advisory R-11.4 */
                               ((uint32_t) channels * (uint32_t) prot_channel_offset));

    /* Enable write access to protected IBG registers using keycode 0xA5A5A501 */
    (*p_ibgkcprot) = BSP_PRV_KEYCODE_ENABLE;

    /* Write protection control settings to protect read/write access for the selected IBG target */
    p_ibgprot[BSP_GUARD_REG_PROT] = p_ibg_setting->protect_setting; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Write SPID bitmap to specify which SPIDs are permitted access */
    p_ibgprot[BSP_GUARD_REG_SPID] = p_ibg_setting->spid;

    /* Disable write access to protected IBG registers using keycode 0xA5A5A500 */
    (*p_ibgkcprot) = BSP_PRV_KEYCODE_DISABLE;
}

/*******************************************************************************************************************//**
 * @brief Retrieves the protection status and error information from IBG for I-Bus module registers.
 *
 * This function reads error status from the IBG module. It checks for overflow errors,
 * captures error addresses, access attributes, and SPID error flags.
 *
 * @param[out] p_status   Pointer to structure that will receive the protection status and error details.
 *
 **********************************************************************************************************************/
static void bsp_ibg_protection_status (bsp_guard_protection_status_t * p_status)
{
    bsp_module_ibg_id_t           ibg_module;
    bsp_ibg_protection_status_t * p_ibg_protect_status;
    bsp_protection_status_t     * p_ibg_status;
    R_GUARD_IBG_IPIR_Type       * p_ibgcap_reg;

    p_ibg_protect_status = (bsp_ibg_protection_status_t *) &p_status->ibusgrd_status; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    ibg_module = p_ibg_protect_status->module;

    /* Get the base address of IBG Guard module */
    p_ibgcap_reg = (R_GUARD_IBG_IPIR_Type *) g_ibg_module_baseaddress[ibg_module]; /* PRQA S 0306 # Advisory R-11.4 */

    /* Get pointer to the status structure for IBG capture module */
    p_ibg_status = (bsp_protection_status_t *) &p_ibg_protect_status->status;

    /* Retrieve error status from current capture module */
    bsp_guard_protection_status(p_ibgcap_reg, p_ibg_status);
}

/*******************************************************************************************************************//**
 * @brief Configures access protection for the specified PBG group and channel, or HBG group.
 *
 * When all guards are disabled, all bus masters can access these registers freely. When enabled, access is restricted
 * according to the specified settings.
 *
 * @param[in] p_setting   Protection settings and access configuration.
 *
 **********************************************************************************************************************/
static void bsp_pbg_protection_setting (const bsp_guard_protection_setting_t * p_setting)
{
    bsp_pbg_group_t pbg_group;
    const bsp_pbg_protection_setting_t * p_pbg_setting;
    volatile uint32_t * p_pbg_prot;
    volatile uint32_t * p_pbg_kcprot;
    uint8_t             channels;

    /* Get pointer to PBG Guard-specific settings from the guard configuration */
    p_pbg_setting = (const bsp_pbg_protection_setting_t *) (&p_setting->slave_guard_protection.pbusgrd_setting);

    /* Get PBus Group register target and channel number for protection from settings */
    pbg_group = p_pbg_setting->group;
    channels  = p_pbg_setting->channel;

    /* Get address of Key Code Protection Register */
    p_pbg_kcprot = (volatile uint32_t *) (g_pbgkcprot_baseaddress[pbg_group] + /* PRQA S 0303 # Advisory R-11.4 */
                                          BSP_GUARD_KCPROT_ADDRESS_OFFSET);

    /* Calculate address of Protection Control Register for the target and channel */
    p_pbg_prot =
        (volatile uint32_t *) (g_pbgprot_baseaddress[pbg_group] + ((uint32_t) channels * /* PRQA S 0303 # Advisory R-11.4 */
                                                                   (uint32_t) BSP_PBG_CHANNEL_ADDRESS_OFFSET));

    /* Apply the protection setting to the specified PBus Group */
    (*p_pbg_kcprot) = BSP_PRV_KEYCODE_ENABLE;

    p_pbg_prot[BSP_GUARD_REG_PROT] = p_pbg_setting->protect_setting; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    p_pbg_prot[BSP_GUARD_REG_SPID] = p_pbg_setting->spid;

    (*p_pbg_kcprot) = BSP_PRV_KEYCODE_DISABLE;
}

/*******************************************************************************************************************//**
 * @brief Retrieves the protection status and error information from the specified PBG or HBG group.
 *
 * This function reads error status from the PBG/HBG module. It checks for overflow errors,
 * captures error addresses, access attributes, and SPID error flags.
 *
 * @param[out] p_status   Pointer to structure that will receive the protection status and error details.
 *
 **********************************************************************************************************************/
static void bsp_pbg_protection_status (bsp_guard_protection_status_t * p_status)
{
    bsp_pbg_group_t               pbg_group;
    bsp_pbg_protection_status_t * p_pbg_protect_status;
    R_PBGERRSLV00_Type          * p_pbgcap_reg;
    bsp_protection_status_t     * p_pbg_status;

    /* Get pointer to the status structure for PBG capture module */
    p_pbg_protect_status = (bsp_pbg_protection_status_t *) &p_status->pbusgrd_status; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    pbg_group = p_pbg_protect_status->group;

    p_pbg_status = &p_pbg_protect_status->status;

    /* Get the base address of IBG Guard module */
    p_pbgcap_reg = (R_PBGERRSLV00_Type *) g_pbgkcprot_baseaddress[pbg_group]; /* PRQA S 0306 # Advisory R-11.4 */

    /* Retrieve error status from current capture module */
    bsp_guard_protection_status(p_pbgcap_reg, p_pbg_status);
}

#if (BSP_FEATURE_DFP_IS_AVAILABLE == 1 || BSP_FEATURE_DFA_IS_AVAILABLE == 1)

/*******************************************************************************************************************//**
 * @brief Configures access protection for Data Flow Processor/Architecture (DFP/DFA) resources using Data Flow Guard.
 *
 * Data Flow Guard controls access to Data flow from other bus masters via their bus context for up to eight regions.
 * If Data Flow Guard detects illegal access, guard error is reported to ECM.
 *
 * @param[in] p_setting    Protection settings and access configuration for Data Flow resources.
 *
 * @note Regions not covered by any protection setting will deny access by default (when at least one channel enable guard protect setting).
 *
 **********************************************************************************************************************/
static void bsp_dataflow_guard_protection_setting (const bsp_guard_protection_setting_t * p_setting)
{
    uint8_t channel;
    const bsp_dataflowgrd_protection_setting_t * p_dataflow_guard_setting;
    R_DFPGRD_Type * dataflowgrd_protect_setting;

    /* Get pointer to DFP Guard-specific settings from the guard configuration */
    p_dataflow_guard_setting =
        (const bsp_dataflowgrd_protection_setting_t *) (&p_setting->slave_guard_protection.dataflowgrd_setting);

    /* Specifies the channel number used for region protection */
    channel = p_dataflow_guard_setting->channel;

    /* Get the base address of the Data flow protection control register */
    dataflowgrd_protect_setting = (R_DFPGRD_Type *) R_DFPGRD_BASE;                                  /* PRQA S 0306 # Advisory R-11.4 */

    /* Enable write access to protected PEG registers using keycode 0xA5A5A501 */
    dataflowgrd_protect_setting->DFPF_AXGKCPROT = BSP_PRV_KEYCODE_ENABLE;                           /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Write protection configuration settings for SPID, base address, size protection, and protection attributes */
    dataflowgrd_protect_setting->DFP_CTR[channel].SPID = p_dataflow_guard_setting->spid;            /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    dataflowgrd_protect_setting->DFP_CTR[channel].BAD  = p_dataflow_guard_setting->base_address;    /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    dataflowgrd_protect_setting->DFP_CTR[channel].ADV  = p_dataflow_guard_setting->valid_address;   /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    dataflowgrd_protect_setting->DFP_CTR[channel].PROT = p_dataflow_guard_setting->protect_setting; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Disable write access to protected PEG registers using keycode 0xA5A5A500 */
    dataflowgrd_protect_setting->DFPF_AXGKCPROT = BSP_PRV_KEYCODE_DISABLE;                          /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * @brief Retrieves the protection status and error information from Data flow Guard.
 *
 * This function reads error status from the Data flow Guard module. It checks for overflow errors,
 * captures error addresses, access attributes, and SPID error flags.
 * *
 * @param[out] p_status    Pointer to structure that will receive the protection status and error details.
 *
 **********************************************************************************************************************/
static void bsp_dataflow_guard_protection_status (bsp_guard_protection_status_t * p_status)
{
    volatile R_DFPGRD_Type  * p_dfpg_reg;                                             /* PRQA S 3678 # Advisory R-8.13 */
    bsp_protection_status_t * p_dfpg_status;

    /* Get the base address of DFP Guard register */
    p_dfpg_reg    = (volatile R_DFPGRD_Type *) R_DFPGRD_BASE;                         /* PRQA S 0303 # Advisory R-11.4 */
    p_dfpg_status = (bsp_protection_status_t *) &p_status->dataflowgrd_status;        /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Get the base address of the guard capture register */
    bsp_guard_protection_status((void *) &p_dfpg_reg->DFPF_AXGOVFCLR, p_dfpg_status); /* PRQA S 0312, 0662 # DP_MSR_R-11.8_UC1, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable/Disable Write access to guarded region. Region that are guarded cannot be written to. Register guard is
 * control by Peripheral Guard (PBG) and H-Peripheral Guard (HBG).
 *
 * @param[in] pbg_group      Guard group index to enable
 * @param[in] pbg_channels   Guard channel index to enable
 * @param[in] pgb_enable     Enable/Disable Write access to guarded region
 **********************************************************************************************************************/
static void bsp_guard_channel_setting (const bsp_pbg_group_t pbg_group,
                                       const uint32_t        pbg_channels,
                                       const bool            pgb_enable)
{
    volatile uint32_t * p_pbgprot_address;
    uint32_t            channels;
    uint32_t            channel_num;

    /* Assign the value of pbg_channels to channels */
    channels = pbg_channels;

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* Enable Write access protection and Guard control */
    bsp_guard_write_enable(pbg_group);

    /* Initialize all PBG channels that assigned for module */
    while (channels != 0U)
    {
        /* Get the next channel to configure */
        channel_num = (uint32_t) BSP_GUARD_GET_BIT(channels);         /* PRQA S 3469, 3432 # Advisory D-4.9, DP_MSR_R-20.7_UC1 */

        /* Get the PBG address */
        p_pbgprot_address =
            (volatile uint32_t *) (g_pbgprot_baseaddress[pbg_group] + /* PRQA S 0303 # Advisory R-11.4 */
                                   (channel_num * BSP_PBG_CHANNEL_ADDRESS_OFFSET));

        if (pgb_enable)
        {
            /* Enable Read, Write access PBG.WG and PBG.RG bits */
            *p_pbgprot_address = (*p_pbgprot_address) | (uint32_t) BSP_PRV_PBG_WRITE_ENABLE;
        }
        else
        {
            /* Disable Write access - PBG.WG bit */
            *p_pbgprot_address = (*p_pbgprot_address) & ~((uint32_t) BSP_PRV_PBG_WRITE_ENABLE);
        }

        /* Set this channel is configured */
        channels &= ~((uint32_t) 1U << channel_num);
    }

    /* Disable Write access protection after the PBG initialization completed */
    bsp_guard_write_disable(pbg_group);

    FSP_CRITICAL_SECTION_EXIT;
}

/*******************************************************************************************************************//**
 * Enable write access to all protected register of guard
 *
 * @param[in] pbg_group      Guard group index to enable
 **********************************************************************************************************************/
static void bsp_guard_write_enable (const bsp_pbg_group_t pbg_group)
{
    volatile uint32_t * p_pbgprot_address;
    volatile uint32_t * p_pbgkcprot_address;

    /* Get the PBGKCPROT address */
    p_pbgkcprot_address =
        (volatile uint32_t *) (g_pbgkcprot_baseaddress[pbg_group] + BSP_PBG_KCPROT_ADDRESS_OFFSET); /* PRQA S 0303 # Advisory R-11.4 */

    /* Enable write access to protected registers */
    *p_pbgkcprot_address = (uint32_t) BSP_PRV_KEYCODE_ENABLE;

    /* Get the PBGPROT0_m channel 0 address */
    p_pbgprot_address =
        (volatile uint32_t *) (g_pbgprot_control_baseaddress[pbg_group]); /* PRQA S 0303 # Advisory R-11.4 */

    /* Enable Read, Write access for channel 0*/
    *p_pbgprot_address = (*p_pbgprot_address) | (uint32_t) BSP_PRV_PBG_WRITE_ENABLE;
}

/*******************************************************************************************************************//**
 * Disable write access to all protected register of guard
 *
 * @param[in] pbg_group      Guard group index to enable
 **********************************************************************************************************************/
static void bsp_guard_write_disable (const bsp_pbg_group_t pbg_group)
{
    volatile uint32_t * p_pbgkcprot_address;

    /* Get the PBGKCPROT address */
    p_pbgkcprot_address =
        (volatile uint32_t *) (g_pbgkcprot_baseaddress[pbg_group] + BSP_PBG_KCPROT_ADDRESS_OFFSET); /* PRQA S 0303 # Advisory R-11.4 */

    /* Disable write access to protected registers */
    *p_pbgkcprot_address = (uint32_t) BSP_PRV_KEYCODE_DISABLE;
}

/*******************************************************************************************************************//**
 * Get the status of Guard Protection.
 *
 * @param[in]  p_cap_reg   Pointer to the base address of the capture module.
 * @param[out] p_status    Pointer to store the error status information.
 **********************************************************************************************************************/
static void bsp_guard_protection_status (void * p_cap_reg, bsp_protection_status_t * p_status)
{
    R_PEGCAP_S_PE0CL0_Type  * p_guardcap_reg;
    bsp_protection_status_t * p_guard_status;

    uint32_t err_status_flag;

    /* Get the base address of sDMAC Guard register */
    p_guardcap_reg = (R_PEGCAP_S_PE0CL0_Type *) p_cap_reg; /* PRQA S 0316 # Advisory R-11.5 */
    p_guard_status = (bsp_protection_status_t *) p_status;

    /* Initialize status structure with default values */
    p_guard_status->errstatus          = BSP_PROTECTION_STATUS_ERROR_NONE;
    p_guard_status->err_access_address = 0U;
    p_guard_status->err_attribute      = 0U;          /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    p_guard_status->spid_error_status  = 0U;

    /* Get the SPID error flag from all channels */
    err_status_flag = p_guardcap_reg->PEGSPIDERRSTAT; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* If there are any errors that occurred */
    if (0U != err_status_flag)
    {
        p_guard_status->errstatus = BSP_PROTECTION_STATUS_ERROR_DETECTED;

        /* Capture the illegal access address when error occurred */
        p_guard_status->err_access_address = p_guardcap_reg->PEGERRADDR; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Capture the access attributes */
        p_guard_status->err_attribute = p_guardcap_reg->PEGERRTYPE;      /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Capture the illegal SPID access address when error occurred */
        p_guard_status->spid_error_status = err_status_flag;

        /* Clear all the SPID error flags */
        p_guardcap_reg->PEGSPIDERRCLR = BSP_GUARD_MAX_32BITS; /* PRQA S 0662, 1257 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.3_UC1 */

        /* Check if overflow error occurred */
        if (1U == p_guardcap_reg->PEGOVFSTAT_b.OVF)           /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
        {
            /* Set the status to error overflow */
            p_guard_status->errstatus = BSP_PROTECTION_STATUS_ERROR_OVERFLOW;

            /* Clear the overflow status */
            p_guardcap_reg->PEGOVFCLR_b.CLRO = 1U; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
        }
    }
}

/** @} (end addtogroup BSP_GUARD) */
