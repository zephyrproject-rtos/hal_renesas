/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_g4_mpu.h
 * @brief    MPU operation functions for RH850 G4
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#if defined(__MPU_PRESENT) && (__MPU_PRESENT == 1U)

/** @defgroup RH850_CoreAccess_FunctionInterface RH850-Core Access Functions
 * @brief Access to the dedicated core access function.
 * @{
 */

/**
 * @defgroup RH850_MPU RH850 Memory protection (MPU)
 * @ingroup RH850_CoreAccess_FunctionInterface
 * @brief    MPU API and data types
 * @{
 */

#ifndef RH850_G4_MPU_H
 #define RH850_G4_MPU_H

 #include <stdint.h>

/* #######################################  MPU Types and Enumerations  ############################################# */

/**
 * @defgroup RH850_MPU_Types MPU Types and Enumerations
 * @brief MPU Types and Enumerations
 * @ingroup  RH850_MPU
 * @{
 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* MPUID Index */
 #define RH850_MPU_MPID_0                       (0U)
 #define RH850_MPU_MPID_1                       (1U)
 #define RH850_MPU_MPID_2                       (2U)
 #define RH850_MPU_MPID_3                       (3U)
 #define RH850_MPU_MPID_4                       (4U)
 #define RH850_MPU_MPID_5                       (5U)
 #define RH850_MPU_MPID_6                       (6U)
 #define RH850_MPU_MPID_7                       (7U)

 #define RH850_MPU_MPM_ENABLE                   (0x01U)                             ///< Enable MPU
 #define RH850_MPU_MPAT_REGION_ENABLE           (0x80U)                             ///< Enable specific region in MPU

 #define RH850_MPU_PRIV_MODE_ACCESS_ALL         (RH850_MPU_SV_MODE_ACCESS_ENABLE)   ///< Enable all accesses in Privilege mode
 #define RH850_MPU_PRIV_MODE_RESTRICT_ACCESS    (RH850_MPU_SV_MODE_ACCESS_RESTRICT) ///< Restrict access according to the SX, SW, and SR bits in SV mode

 #define RH850_MPU_MPAT_WMPID_VALUE(spid)    ((uint32_t) (spid) << 24)
 #define RH850_MPU_MPAT_RMPID_VALUE(spid)    ((uint32_t) (spid) << 16)
 #define RH850_MPU_MPAT_UR_EN                   (1U << 0)                           ///< Reading is enabled for user mode
 #define RH850_MPU_MPAT_UW_EN                   (1U << 1)                           ///< Writing is enabled for user mode
 #define RH850_MPU_MPAT_UX_EN                   (1U << 2)                           ///< Executing is enabled for user mode
 #define RH850_MPU_MPAT_SR_EN                   (1U << 3)                           ///< Reading is enabled for supervisor mode
 #define RH850_MPU_MPAT_SW_EN                   (1U << 4)                           ///< Writing is enabled for supervisor mode
 #define RH850_MPU_MPAT_SX_EN                   (1U << 5)                           ///< Executing is enabled for supervisor mode

/** Execution and reading by any SPID is enabled regardless of the settings MPIDn */
 #define RH850_MPU_MPAT_RG_EN                   (1U << 14)

/** Writing by any SPID is enabled regardless of the settings MPIDn */
 #define RH850_MPU_MPAT_WG_EN                   (1U << 15)

 #define RH850_MPU_PERMISSION_ENABLE            (1U)
 #define RH850_MPU_PERMISSION_DISABLE           (0U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**
 * @enum rh850_mpu_sv_mode_access_t
 * @brief Controls access behavior in Supervisor (SV) mode when PSW.UM = 0.
 *
 * In SV mode, this bit determines whether memory accesses are unrestricted
 * or restricted according to the MPAT register's protection bits (SX, SW, SR)
 * for each protection area.
 *
 * - 0: Enable all accesses in SV mode (no restriction).
 * - 1: Restrict access according to SX, SW, and SR bits in SV mode.
 *
 * @note This setting applies only when PSW.UM = 0 (SV mode).
 */

typedef enum e_rh850_mpu_sv_mode_access
{
    RH850_MPU_SV_MODE_ACCESS_ENABLE   = 0x00, /*!< Enable all accesses in SV mode (no restriction) */
    RH850_MPU_SV_MODE_ACCESS_RESTRICT = 0x02  /*!< Restrict access according to SX, SW, and SR bits in SV mode */
} rh850_mpu_sv_mode_access_t;

/**
 * @enum rh850_mpu_state_t
 * @brief MPU function control bit (RH850).
 *
 * This bit selects/indicates whether the Memory Protection Unit (MPU) is enabled.
 *
 * - 0: Disable
 * - 1: Enable
 */
typedef enum e_rh850_mpu_state
{
    RH850_MPU_STATE_DISABLE = 0U,      /*!< Disable MPU function */
    RH850_MPU_STATE_ENABLE  = 1U       /*!< Enable MPU function. */
} rh850_mpu_state_t;

/** Region definition data structure */
typedef struct st_rh850_mpu_region
{
    const char * name;                               /*!< Region's name */
    uint32_t     start_address;                      /*!< Region's start address */
    uint32_t     size;                               /*!< Region's size */
    union
    {
        uint32_t attribute;                          /*!< Region's attribute */
        struct
        {
            uint32_t user_mode_permission       : 3; /*!< User mode permission */
            uint32_t supervisor_mode_permission : 3; /*!< Supervisor mode permission */
            uint32_t                            : 1; /*!< Reserved bit */
            uint32_t region_enable              : 1; /*!< Region enable */
            uint32_t                            : 6; /*!< Reserved bits */
            uint32_t rg_bit                     : 1; /*!< Bit indicates the execution and read permissions for any SPID */
            uint32_t wg_bit                     : 1; /*!< Bit indicates the write permissions for any SPID */
            uint32_t rmpid                      : 8; /*!< Indicates the execution and read permissions for the SPID specified in the MPIDn register */
            uint32_t wmpid                      : 8; /*!< Indicates the write for the SPID specified in the MPIDn register */
        } attribute_b;
    }       region_attr;
    uint8_t no_of_region;                            /*!< Region's index in MPU */
} rh850_mpu_region_t;

/** MPU Memory checking status */
typedef struct st_rh850_mpu_mem_status
{
    union
    {
        uint32_t status;
        struct
        {
            uint32_t usr_rd_en  : 1;   /*!< User mode read permission */
            uint32_t usr_wr_en  : 1;   /*!< User mode write permission */
            uint32_t usr_exe_en : 1;   /*!< User mode execute permission */
            uint32_t sup_rd_en  : 1;   /*!< Supervisor mode read permission */
            uint32_t sup_wr_en  : 1;   /*!< Supervisor mode write permission */
            uint32_t sup_exe_en : 1;   /*!< Supervisor mode execute permission */
            uint32_t            : 2;   /*!< Reserved bits */
            uint32_t ov_bit     : 1;   /*!< Bit indicates the specified area includes 0000 0000H or 7FFF FFFFH */
            uint32_t            : 23;  /*!< Reserved bits */
        } status_b;
    } mpu_status;
} rh850_mpu_mem_status_t;

/** @} */ /* end of RH850_MPU_Types */

/* ############################################  MPU API Functions  ################################################# */

/**
 * @defgroup RH850_MPU_API MPU API Functions
 * @brief MPU API Functions
 * @ingroup  RH850_MPU
 * @{
 */

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/**
 * @brief Enable the MPU.
 * @details Enables the Memory Protection Unit by setting the appropriate bits in the MPM register.
 * @param[in] LenSvAccessControl    Access type for Privileged mode.
 */
__STATIC_INLINE void __RH850_MPU_Enable (rh850_mpu_sv_mode_access_t LenSvAccessControl)
{
    /* Setting for SVP and enable for MPE bit */
    __set_MPM((uint32_t) LenSvAccessControl | R_MPU_MPM_MPE_Msk);
}

/**
 * @brief Disable the MPU.
 * @details Disables the Memory Protection Unit by clearing enable bits in the MPM register.
 */
__STATIC_INLINE void __RH850_MPU_Disable (void)
{
    uint32_t LulMpmRegValue;

    /* Read the MPM register */
    LulMpmRegValue  = __get_MPM();
    LulMpmRegValue &= (~R_MPU_MPM_MPE_Msk);

    /* Write back */
    __set_MPM(LulMpmRegValue);
}

/**
 * @brief Get the current MPU state.
 * @return rh850_mpu_state_t Current MPU state (enabled or disabled).
 */
__STATIC_INLINE rh850_mpu_state_t __RH850_MPU_StateGet (void)
{
    return (0U != (__get_MPM() & R_MPU_MPM_MPE_Msk)) ? RH850_MPU_STATE_ENABLE : RH850_MPU_STATE_DISABLE;
}

/**
 * @brief Get the current MPU state in SV mode.
 * @return rh850_mpu_sv_mode_access_t Current MPU state (enabled or disabled).
 */
__STATIC_INLINE rh850_mpu_sv_mode_access_t __RH850_MPU_SvStateGet (void)
{
    return (rh850_mpu_sv_mode_access_t) (__get_MPM() & R_MPU_MPM_SVP_Msk);
}

/**
 * @brief Get the total number of MPU regions supported for this core.
 * @details Reads SR2,5 and calculates the number of supported MPU regions.
 * @return Total number of MPU regions.
 */
__STATIC_INLINE uint8_t __RH850_MPU_NumberofRegionsGet (void)
{
    uint8_t LucNumOfRegions;

    /* Check if MPU is supported on MCU */
    if (0U != (__get_PID() & R_MPU_PID_MPU_Msk))
    {
        LucNumOfRegions = (uint8_t) ((__get_MPCFG() & R_MPU_MPCFG_NMPUE_Msk) + 1U);
    }
    else
    {
        LucNumOfRegions = 0U;
    }

    return LucNumOfRegions;
}

/**
 * @brief  Get the number of MPU banks configured in the CPU.
 * @details Reads the NBK field from the MPU configuration register. The NBK field indicates
 *          "number of banks - 1" for the MPU. For example, if NBK = 0, the CPU has one MPU bank.
 *
 * @return uint8_t
 *         - Value representing (number of banks - 1).
 *
 * @note   For this CPU, NBK typically reads as 0, meaning one MPU bank is present.
 */
__STATIC_INLINE uint8_t __RH850_MPU_NumberOfBanksGet (void)
{
    return (uint8_t) ((__get_MPCFG() & R_MPU_MPCFG_NBK_Msk) >> R_MPU_MPCFG_NBK_Pos);
}

/**
 * @brief  Get the MPU architecture specification version.
 * @details Reads the ARCH field from the MPU configuration register. This field indicates
 *          the version of the MPU architecture implemented by the CPU.
 *
 * @return uint8_t
 *         - Value representing the MPU architecture version (e.g., 2 for this CPU).
 *
 * @note   The ARCH field is read-only and reflects the hardware MPU specification level.
 */
__STATIC_INLINE uint8_t __RH850_MPU_ArchitectureVersionGet (void)
{
    return (uint8_t) ((__get_MPCFG() & R_MPU_MPCFG_ARCH_Msk) >> R_MPU_MPCFG_ARCH_Pos);
}

/**
 * @brief Execute memory protection checking.
 * @details Performs memory protection check using MCA, MCS, MCI, MCC, and returns the result via MCR.
 * @param[in]  LulSpid      System protection identifier.
 * @param[in]  LulLowerAddr Value for MCA register.
 * @param[in]  LulSize      Size of region.
 * @param[out] LpStatus     Pointer to the variable that stores the status result.
 */
__STATIC_INLINE void __RH850_MPU_ExecMemProtectCheck (uint8_t                  LulSpid,
                                                      uint32_t                 LulLowerAddr,
                                                      uint32_t                 LulSize,
                                                      rh850_mpu_mem_status_t * LpStatus)
{
    uint32_t LulDummyValue;

    LulDummyValue = 0U;

    /* Set parameter LulLowerAddr to SR8, 5 MCA */
    __set_MCA(LulLowerAddr);

    /* Set parameter LulSize to SR9, 5 MCS */
    __set_MCS(LulSize);

    /* Set parameter LulSpid to SR12, 5 MCI */
    __set_MCI(LulSpid);

    /* Start checking with SR10, 5 MCC by writing any value */
    __set_MCC(LulDummyValue);

    /* Get the results from SR11, 5 MCR */
    LpStatus->mpu_status.status = __get_MCR();
}

/**
 * @brief Set the current Memory Protection entry index (MPIDX).
 * @note This value dictates which entry will be addressed by the next
 *       MPLA/MPUA/MPAT access using LDSR/STSR.
 */
__STATIC_INLINE void __RH850_MPU_MpuIdSet (uint8_t LucRegion)
{
    __set_MPIDX(LucRegion);
}

/**
 * @brief Get the currently selected MPU bank (MPBK).
 *
 * Returns the BK field indicating which MPU bank is currently used for memory protection,
 * the memory protection setting check function, and the LDM.MP / STM.MP instructions.
 * Registers of non-selected banks have no effect and cannot be operated via LDSR/STSR.
 *
 * @return The current BK value (typically 0 for MPU bank 0; other values are prohibited).
 *
 * @note The returned BK dictates which bank's configuration is active for protection and
 *       for MP-related load/store instructions.
 */
__STATIC_INLINE uint8_t __RH850_MPU_BankGet (void)
{
    return (uint8_t) (__get_MPBK() & R_MPU_MPBK_BK_Msk);
}

/**
 * @brief Set the memory attribute encoding.
 * @details Configures the attribute for a specific MPU region.
 * @param[in] LucRegion The region number to be set [0-31].
 * @param[in] LulAttr The attribute value to be set.
 */
__STATIC_INLINE void __RH850_MPU_AttrSet (uint8_t LucRegion, uint32_t LulAttr)
{
    /* Set register SR16, 5 MPIDX to LucRegion value */
    __set_MPIDX(LucRegion);

    /* Set register SR22, 5 MPAT to LulAttr value */
    __set_MPAT(LulAttr);
}

/**
 * @brief Get the memory attribute encoding.
 * @details Reads the attribute value for a specific MPU region.
 * @param[in] LucRegion The region number to be set [0-31].
 * @return Attribute value of the region.
 */
__STATIC_INLINE uint32_t __RH850_MPU_AttrGet (uint8_t LucRegion)
{
    /* Set parameter LucRegion to register SR16, 5 MPIDX */
    __set_MPIDX(LucRegion);

    /* Get attribute */
    return (uint32_t) __get_MPAT();
}

/**
 * @brief Clear and disable the given MPU region.
 * @details Clears all registers for the specified region and disables it.
 * @param[in] LucRegion Region number to be cleared.
 */
__STATIC_INLINE void __RH850_MPU_RegionClear (uint8_t LucRegion)
{
    /* Set parameter LucRegion to register SR16, 5 MPIDX */
    __set_MPIDX(LucRegion);

    /* Clear register SR20, 5 MPLA
     * Clear register SR21, 5 MPUA
     * Clear register SR22, 5 MPAT */
    __set_MPLA(0);
    __set_MPUA(0);
    __set_MPAT(0);
}

/**
 * @brief Configure the given MPU region.
 * @details Sets lower and upper address for the region based on size.
 * @param[in] LucRegion Region number to be configured.
 * @param[in] LulLowerAddr Value for MPLA register.
 * @param[in] LulSize Size of region.
 */
__STATIC_INLINE void __RH850_MPU_RegionSet (uint8_t LucRegion, uint32_t LulLowerAddr, uint32_t LulSize)
{
    /* Set parameter LucRegion to register SR16, 5 MPIDX */
    __set_MPIDX(LucRegion);

    /* Set parameter LulLowerAddr to register SR20, 5 MPLA */
    __set_MPLA(LulLowerAddr);

    /* Set upper address to register SR21, 5 MPUA */
    __set_MPUA((uint32_t) (LulLowerAddr + LulSize));
}

/**
 * @brief Get the lower address of specific region.
 * @details Reads MPLA register for the given region.
 * @param[in] LucRegion The region number to be set [0-31].
 * @return Lower address of the region.
 */
__STATIC_INLINE uint32_t __RH850_MPU_LowerAddressGet (uint8_t LucRegion)
{
    /* Set parameter LucRegion to register SR16, 5 MPIDX */
    __set_MPIDX(LucRegion);

    /* Get value of SR20, 5 MPLA */
    return (uint32_t) __get_MPLA();
}

/**
 * @brief Get the upper address of specific region.
 * @details Reads MPUA register for the given region.
 * @param[in] LucRegion The region number to be set [0-31].
 * @return Upper address of the region.
 */
__STATIC_INLINE uint32_t __RH850_MPU_UpperAddressGet (uint8_t LucRegion)
{
    /* Set parameter LucRegion to register SR16, 5 MPIDX */
    __set_MPIDX(LucRegion);

    /* Get value of SR21, 5 MPUA */
    return (uint32_t) __get_MPUA();
}

/** This function sets value for MPIDx register (x = 0 to 7).
 * @param LucMpid No of MPID register.
 * @param LucValue     Value for MPID register.
 */
__STATIC_INLINE void __RH850_MPU_MpidSet (uint8_t LucMpid, uint8_t LucValue)
{
    /* No of MPID register */
    switch (LucMpid)
    {
        case RH850_MPU_MPID_0:
        {
            /* Load r7 into MPID0 (SR24, select = 5) */
            __set_MPID0(LucValue);
            break;
        }

        case RH850_MPU_MPID_1:
        {
            /* Load r7 into MPID1 (SR25, select = 5) */
            __set_MPID1(LucValue);
            break;
        }

        case RH850_MPU_MPID_2:
        {
            /* Load r7 into MPID2 (SR26, select = 5) */
            __set_MPID2(LucValue);
            break;
        }

        case RH850_MPU_MPID_3:
        {
            /* Load r7 into MPID3 (SR27, select = 5) */
            __set_MPID3(LucValue);
            break;
        }

        case RH850_MPU_MPID_4:
        {
            /* Load r7 into MPID4 (SR28, select = 5) */
            __set_MPID4(LucValue);
            break;
        }

        case RH850_MPU_MPID_5:
        {
            /* Load r7 into MPID5 (SR29, select = 5) */
            __set_MPID5(LucValue);
            break;
        }

        case RH850_MPU_MPID_6:
        {
            /* Load r7 into MPID6 (SR30, select = 5) */
            __set_MPID6(LucValue);
            break;
        }

        case RH850_MPU_MPID_7:
        {
            /* Load r7 into MPID7 (SR31, select = 5) */
            __set_MPID7(LucValue);
            break;
        }

        default:
        {
            /* No operation for out-of-range MPID index */
            break;
        }
    }

    /* Synchronization barrier to ensure system register write completes */
    __SYNCP();
}

/** @} */ /* end of RH850_MPU_API */

#endif                                 /* RH850_G4_MPU_H */

/** @} */ /* end of RH850_MPU */
/** @} */ /* end of RH850_CoreAccess_FunctionInterface */

#endif                                 /* #if defined(__MPU_PRESENT) && (__MPU_PRESENT == 1U) */
