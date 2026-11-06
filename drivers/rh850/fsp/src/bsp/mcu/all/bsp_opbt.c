/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_opbt.h"                                                                                             /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_OPBT_FACI_COMMAND_FORCE_STOP                         (0xB3U)                                          ///< FACI Command Force Stop
#define BSP_OPBT_FACI_COMMAND_SWITCH_ERASURE_1ST_ACCESS          (0x87U)                                          ///< FACI Command Switch Erasure for 1st access
#define BSP_OPBT_FACI_COMMAND_SWITCH_ERASURE_2ND_ACCESS          (0xD0U)                                          ///< FACI Command Switch Erasure for 2nd access
#define BSP_OPBT_FACI_COMMAND_SWITCH_PROGRAMMING_1ST_ACCESS      (0x85U)                                          ///< FACI Command Switch Programming for 1st access
#define BSP_OPBT_FACI_COMMAND_SWITCH_PROGRAMMING_2ND_ACCESS      (0x08U)                                          ///< FACI Command Switch Programming for 2nd access
#define BSP_OPBT_FACI_COMMAND_SWITCH_PROGRAMMING_3RD_ACCESS      (0xD0U)                                          ///< FACI Command Switch Programming for 3rd access
#define BSP_OPBT_FACI_COMMAND_TAG_ERASURE_1ST_ACCESS             (0x89U)                                          ///< FACI Command TAG Erasure for 1st access
#define BSP_OPBT_FACI_COMMAND_TAG_ERASURE_2ND_ACCESS             (0xD0U)                                          ///< FACI Command TAG Erasure for 2nd access
#define BSP_OPBT_FACI_COMMAND_TAG_UPDATE_1ST_ACCESS              (0x83U)                                          ///< FACI Command TAG Update for 1st access
#define BSP_OPBT_FACI_COMMAND_TAG_UPDATE_2ND_ACCESS              (0xD0U)                                          ///< FACI Command TAG Update for 2nd access
#define BSP_OPBT_FACI_COMMAND_SHIFT_TO_READ_MODE                 (0xAA00U)                                        ///< FACI Command shift to Read mode
#define BSP_OPBT_FACI_COMMAND_SHIFT_TO_PROGRAMMING_MODE          (0xAA80U)                                        ///< FACI Command shift to Programming mode
#define BSP_OPBT_FACI_COMMAND_PROPERTY_ERASURE_1ST_ACCESS        (0x47U)                                          ///< FACI Command Property Erasure for 1st access
#define BSP_OPBT_FACI_COMMAND_PROPERTY_ERASURE_2ND_ACCESS        (0xD0U)                                          ///< FACI Command Property Erasure for 2nd access
#define BSP_OPBT_FACI_COMMAND_PROPERTY_PROGRAMMING_1ST_ACCESS    (0x45U)                                          ///< FACI Command Property Programming for 1st access
#define BSP_OPBT_FACI_COMMAND_PROPERTY_PROGRAMMING_2ND_ACCESS    (0x08U)                                          ///< FACI Command Property Programming for 2nd access
#define BSP_OPBT_FACI_COMMAND_PROPERTY_PROGRAMMING_3RD_ACCESS    (0xD0U)                                          ///< FACI Command Property Programming for 3rd access

#define BSP_OPBT_VALUE_RETURN_FROM_COMMAND_LOCK_TIMEOUT          (374U)                                           ///< Return from command lock timeout value
#define BSP_OPBT_VALUE_PROPERTY_PROGRAMMING_TIMEOUT              (1U)                                             ///< Property programming command timeout value
#define BSP_OPBT_VALUE_PROPERTY_ERASURE_TIMEOUT                  (105U)                                           ///< Property erasure command timeout value
#define BSP_OPBT_VALUE_SHIFT_TO_PROGRAM_TIMEOUT                  (105U)                                           ///< Shift to Program Mode command timeout value
#define BSP_OPBT_VALUE_SHIFT_TO_READ_TIMEOUT                     (374U)                                           ///< Shift to Read Mode timeout value
#define BSP_OPBT_VALUE_FORCE_STOP_TIMEOUT                        (28U)                                            ///< Force stop command timeout value
#define BSP_OPBT_VALUE_TAG_ERASE_TIMEOUT                         (107U)                                           ///< TAG erasure command timeout value
#define BSP_OPBT_VALUE_TAG_UPDATE_TIMEOUT                        (2U)                                             ///< TAG update command timeout value
#define BSP_OPBT_VALUE_SWITCH_PROGRAMMING_TIMEOUT                (2U)                                             ///< Switch Area programming command timeout value
#define BSP_OPBT_VALUE_SWITCH_ERASURE_TIMEOUT                    (107U)                                           ///< Switch Area erasure command timeout value

#define BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T                   *((volatile uint8_t *) ( \
                                                                       BSP_OPBT_FACI0_COMMAND_ISSUING_AREA_BASE)) ///< Macro helper performs a 1-byte access to FACI0_COMMAND_ISSUING_AREA address
#define BSP_OPBT_FACI0_COMMAND_ISSUING_UINT32_T                  *((volatile uint32_t *) ( \
                                                                       BSP_OPBT_FACI0_COMMAND_ISSUING_AREA_BASE)) ///< Macro helper performs a 4-bytes access to FACI0_COMMAND_ISSUING_AREA address

/** Macro helper for checking status */
#define BSP_OPBT_BREAK_IF_ERROR(_status)    if (BSP_OPBT_STATUS_SUCCESS != (_status)) {break;}

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void              r_bsp_issue_force_stop_command(void);
static bsp_opbt_status_t r_bsp_issue_switch_erasure_command(void);
static bsp_opbt_status_t r_bsp_issue_switch_programming_command(void);
static bsp_opbt_status_t r_bsp_issue_tag_check_flag(void);
static bsp_opbt_status_t r_bsp_issue_tag_erase_command(void);
static bsp_opbt_status_t r_bsp_issue_tag_update_command(void);
static bsp_opbt_status_t r_bsp_shift_to_read_mode(void);
static bsp_opbt_status_t r_bsp_shift_to_programming_mode(void);
static bsp_opbt_status_t r_bsp_configuration_setting_erase(void);
static bsp_opbt_status_t r_bsp_configuration_setting_flash(const uint32_t * p_src,
                                                           const uint32_t   nums_of_regs,
                                                           const uint32_t   base_address);
static bsp_opbt_status_t r_bsp_shift_to_program_erase_flash(void);
static bsp_opbt_status_t r_bsp_exit_program_erase_flash(void);

static void              r_bsp_opbt_read(uint32_t base_address, uint32_t offset, uint32_t * p_dest, uint32_t length); /* PRQA S 1710 # Advisory D-4.5 */
static bsp_opbt_status_t r_bsp_opbt_switch_area(void);
static bsp_opbt_status_t r_bsp_opbt_programming(void);
static bsp_opbt_status_t bsp_opbt_wait_flash_ready(volatile uint32_t timeout_ms);
static void              r_bsp_return_from_command_lock_state(void);

/** Array contains the OPT value of the valid side */
static uint32_t g_otp_buff[BSP_OPBT_NUMBER_OF_OTP_REGS];

/** Array contains the OPBT value of the valid side */
static uint32_t g_opbt_buff[BSP_OPBT_NUMBER_OF_OPBT_REGS];

/** Variable contains the CVA value */
static uint32_t g_cva_value;

/** Variable contains the SVA value */
static uint32_t g_sva_value;

/** Variable contains the BVA0 value */
static uint32_t g_bva0_value;

#if (BSP_FEATURE_OPBT_BVA1_AREA_IS_AVAILABLE)

/** Variable contains the BVA1 value */
static uint32_t g_bva1_value;
#endif

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * This function changes the valid bank of the devices when in double map mode. In single map mode, this function
 * has no effect.
 *
 * @param[in]  bank_select                          .
 *
 * @retval  BSP_OPBT_STATUS_SUCCESS                 The Switch Area operation was success.
 * @retval  BSP_OPBT_STATUS_TIMEOUT                 One of the command was timeout.
 * @retval  BSP_OPBT_STATUS_FAIL                    The Switch Area operation was fail.
 * @retval  BSP_OPBT_STATUS_AREA_NOT_PROGRAMMED     One of the Area was not programmed correctly.
 * @retval  BSP_OPBT_STATUS_VERIFY_MISMATCH         The OPBT values don't match the input data.
 **********************************************************************************************************************/

/* PRQA S 0292 -- */
bsp_opbt_status_t R_BSP_DoubleMapValidBankSelect (bsp_opbt_double_map_valid_area_select_t bank_select) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    bsp_opbt_status_t status = BSP_OPBT_STATUS_SUCCESS;

    /* Read the registers' value from offset 0x200 to 0x21C of Configuration Setting Area */
    r_bsp_opbt_read(BSP_OPBT_CSAF_BASE, BSP_OPBT_OTP_SETTING_OFFSET, g_otp_buff, BSP_OPBT_NUMBER_OF_OTP_REGS);

    /* Read OPBT value from the valid side */
    r_bsp_opbt_read(BSP_OPBT_CSAF_BASE,
                    BSP_OPBT_SOFTWARE_CONFIGURATION_OPTION_BYTE_OFFSET,
                    g_opbt_buff,
                    BSP_OPBT_NUMBER_OF_OPBT_REGS);

    /* Disable Instruction Cache to make sure the value will be written correctly */
    R_BSP_InstructionCacheDisable();

    /* Change the valid bank in OPBT13 */
    if (1U == (((uint8_t) bank_select) % 2U))
    {
        g_opbt_buff[13U + BSP_OPBT_REGISTER_OFFSET] = (g_opbt_buff[13U + BSP_OPBT_REGISTER_OFFSET]) |
                                                      ((uint32_t) 1U << (((uint8_t) bank_select) / 2U));
    }
    else
    {
        g_opbt_buff[13U + BSP_OPBT_REGISTER_OFFSET] = (g_opbt_buff[13U + BSP_OPBT_REGISTER_OFFSET]) &
                                                      ~((uint32_t) 1U << (((uint8_t) bank_select) / 2U));
    }

    do                                 /* PRQA S 0771 # Advisory R-15.4 */
    {
        /* Enter Program/ Erase Mode for flash memory */
        status = r_bsp_shift_to_program_erase_flash();

        /* Verify that the MCU has entered the Programming Mode */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Perform OPBT Program */
        status = r_bsp_opbt_programming();

        /* Verify that OPBT Programming command was success */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Issue OPBT switch area */
        status = r_bsp_opbt_switch_area();

        /* Verify that OPBT Switch Area command was success */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Exit Program/ Erase Mode for flash memory */
        status = r_bsp_exit_program_erase_flash();
    } while (0);

    /* Enable Instruction Cache again*/
    R_BSP_InstructionCacheEnable();

    return status;
}

#if (BSP_OPBT_API_USED_ENABLE)

/*******************************************************************************************************************//**
 * This function programms the custom OPBT values to invalid side of Configuration Setting Area.
 *
 * @param[in]  p_src       Pointer to array containing OPBT value need to be programmed.
 *
 * @retval  BSP_OPBT_STATUS_SUCCESS                 The OPBT Program operation was success.
 * @retval  BSP_OPBT_STATUS_TIMEOUT                 One of the command was timeout.
 * @retval  BSP_OPBT_STATUS_FAIL                    The OPBT Program operation was fail.
 **********************************************************************************************************************/
bsp_opbt_status_t R_BSP_OPBTProgram (const uint32_t * p_src)
{
 #if BSP_CFG_PARAM_CHECKING_ENABLE
    if (NULL == p_src)
    {
        return BSP_OPBT_STATUS_FAIL;
    }
 #endif

    bsp_opbt_status_t status = BSP_OPBT_STATUS_SUCCESS;

    /* Read the registers' value from offset 0x200 to 0x21C of Configuration Setting Area */
    r_bsp_opbt_read(BSP_OPBT_CSAF_BASE, BSP_OPBT_OTP_SETTING_OFFSET, g_otp_buff, BSP_OPBT_NUMBER_OF_OTP_REGS);

    /* Read the input data and store it into g_opbt_buff */
    uint32_t reg_idx;
    for (reg_idx = 0U; reg_idx < BSP_OPBT_NUMBER_OF_OPBT_REGS; reg_idx++)
    {
        g_opbt_buff[reg_idx] = p_src[reg_idx];
    }

    /* Disable Instruction Cache to make sure the value will be written correctly */
    R_BSP_InstructionCacheDisable();

    do
    {
        /* Enter Program/ Erase Mode for flash memory */
        status = r_bsp_shift_to_program_erase_flash();

        /* Verify that the MCU has entered the Programming Mode */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Perform OPBT Program */
        status = r_bsp_opbt_programming();

        /* Verify that OPBT Programming command was success */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Issue OPBT switch area */
        status = r_bsp_opbt_switch_area();

        /* Verify that OPBT Switch Area command was success */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Exit Program/ Erase Mode for flash memory */
        status = r_bsp_exit_program_erase_flash();
    } while (0);

    /* Enable Instruction Cache again*/
    R_BSP_InstructionCacheEnable();

    return status;
}

#endif

/*******************************************************************************************************************//**
 * This function reads the valid side of Configuration Setting Area.
 *
 * @retval  None
 **********************************************************************************************************************/
void R_BSP_OPBTRead (uint32_t * p_dest, uint32_t length) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    r_bsp_opbt_read(BSP_OPBT_CSAF_BASE, BSP_OPBT_SOFTWARE_CONFIGURATION_OPTION_BYTE_OFFSET, p_dest, length);
}

/*******************************************************************************************************************//**
 * This function verifies the OPBT values on the valid side with the input data.
 *
 * This function reads the specified Software Configuration Option Byte (OPBT)
 * from the valid configuration area and compares it with the expected value.
 *
 * @param[in]  configuration_name   Software configuration OPBT identifier.
 *                                  This value specifies which OPBT index to verify.
 *
 * @param[in]  expected_value       Expected value of the specified OPBT.
 *
 * @retval  BSP_OPBT_STATUS_VERIFY_OK                 The OPBT values match the input data.
 * @retval  BSP_OPBT_STATUS_VERIFY_MISMATCH           The OPBT values don't match the input data.
 **********************************************************************************************************************/
bsp_opbt_status_t R_BSP_OPBTVerify (bsp_configuration_area_t configuration_name, uint32_t expected_value) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    uint32_t opbt_index;
    uint32_t actual_value;

    /* Convert configuration identifier to OPBT index */
    opbt_index = (uint32_t) configuration_name;

    /* Read OPBT value from valid configuration area */
    actual_value = *(volatile uint32_t *) /* PRQA S 0303 # Advisory R-11.4 */
                   (BSP_OPBT_CSAF_BASE + BSP_OPBT_SOFTWARE_CONFIGURATION_OPTION_BYTE_OFFSET + (4U * opbt_index));

    if (actual_value != expected_value)
    {
        return BSP_OPBT_STATUS_VERIFY_MISMATCH;
    }

    return BSP_OPBT_STATUS_VERIFY_OK;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Execute the Forced Stop Command. The Forced Stop Command is used to abort the command being processed by the
 * flash sequencer.
 **********************************************************************************************************************/
static void r_bsp_issue_force_stop_command (void)
{
    volatile uint8_t timeout_us;

    do
    {
        timeout_us = BSP_OPBT_VALUE_FORCE_STOP_TIMEOUT;

        /* Issue Force Stop Command */
        BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T = BSP_OPBT_FACI_COMMAND_FORCE_STOP; /* PRQA S 0303 # Advisory R-11.4 */

        /* Wait for FRDY bit in FSTATR_0 register set */
        while ((0U == (BSP_OPBT_FSTATR_0 & BSP_OPBT_FSTATR_0_FRDY_BIT_MSK)) &&     /* PRQA S 0303 # Advisory R-11.4 */
               (0U != timeout_us))                                                 /* PRQA S 3415 # DP_MSR_R-13.5_UC1 */
        {
            R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);
            timeout_us--;                                                          /* PRQA S 3387 # Advisory R-13.3 */
        }
    } while (0U != (BSP_OPBT_FASTAT_0 & BSP_OPBT_FASTAT_0_CMDLK_BIT_MSK));         /* PRQA S 0303 # Advisory R-11.4 */
}

/*******************************************************************************************************************//**
 * Execute the Switch Erasure Command. The Switch Erasure Command is used to erase the back side (invalid) of Switch
 * Area.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_issue_switch_erasure_command (void)
{
    bsp_opbt_status_t status;

    /* Set the start address of Switch Area */
    BSP_OPBT_FSADDR_0 = (BSP_OPBT_SWAB_BASE + BSP_OPBT_CVA_OFFSET); /* PRQA S 0303 # Advisory R-11.4 */

    /* Issue the Switch Erasure Command */
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                        /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_SWITCH_ERASURE_1ST_ACCESS;
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                        /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_SWITCH_ERASURE_2ND_ACCESS;

    status = bsp_opbt_wait_flash_ready(BSP_OPBT_VALUE_SWITCH_ERASURE_TIMEOUT);

    return status;
}

/*******************************************************************************************************************//**
 * Execute the Switch Programming Command. The Switch Programming Command is used to write to the back side (invalid)
 * of Switch Area. This function only changes the CVA flag to execute the switch operation of Configration Setting Area.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_issue_switch_programming_command (void)
{
    bsp_opbt_status_t status;
    uint8_t           repetition_count;

    /* Set the start address of Switch Area */
    BSP_OPBT_FSADDR_0 = (BSP_OPBT_SWAB_BASE + BSP_OPBT_CVA_OFFSET); /* PRQA S 0303 # Advisory R-11.4 */

    /* Issue the Switch Programming Command */
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                        /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_SWITCH_PROGRAMMING_1ST_ACCESS;
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                        /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_SWITCH_PROGRAMMING_2ND_ACCESS;

    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT32_T = g_cva_value;          /* PRQA S 0303 # Advisory R-11.4 */
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT32_T = g_sva_value;          /* PRQA S 0303 # Advisory R-11.4 */
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT32_T = g_bva0_value;         /* PRQA S 0303 # Advisory R-11.4 */

#if (BSP_FEATURE_OPBT_BVA1_AREA_IS_AVAILABLE)
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT32_T = g_bva1_value;         /* PRQA S 0303 # Advisory R-11.4 */
#else
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT32_T = 0xFFFFFFFFU;          /* PRQA S 0303 # Advisory R-11.4 */
#endif
    for (repetition_count = 0U; repetition_count < 4U; repetition_count++)
    {
        BSP_OPBT_FACI0_COMMAND_ISSUING_UINT32_T = 0xFFFFFFFFU;      /* PRQA S 0303 # Advisory R-11.4 */
    }

    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                        /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_SWITCH_PROGRAMMING_3RD_ACCESS;

    status = bsp_opbt_wait_flash_ready(BSP_OPBT_VALUE_SWITCH_PROGRAMMING_TIMEOUT);

    return status;
}

/*******************************************************************************************************************//**
 * Perform AnPC, BSP_OPBT_CSAVOFCn flag checking.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_issue_tag_check_flag (void)
{
    bsp_opbt_status_t status = BSP_OPBT_STATUS_SUCCESS;

    /* Check whether Switch Area is programmed */
    if (BSP_OPBT_SWITCH_AREA_IS_PROGRAMMED == BSP_OPBT_A0PC_B)                   /* PRQA S 0303 # Advisory R-11.4 */
    {
        if (BSP_OPBT_BSP_CONFIGURATION_SETTING_AREA_1_VALID ==
            BSP_OPBT_CVA_INVALID_SIDE)                                           /* PRQA S 0303 # Advisory R-11.4 */
        {
            /* Check whether the Switch Area value is valid */
            if (0U == (BSP_OPBT_FSWASTAT_0 & BSP_OPBT_FSWASTAT_0_CFGVA_BIT_MSK)) /* PRQA S 0303 # Advisory R-11.4 */
            {
                /* Check BSP_OPBT_CSAVOFCn (n = 0, 8 to 19). If one of these register is not programmed, issue Switch Erasure Command */
                if (BSP_OPBT_SWITCH_AREA_IS_PROGRAMMED != BSP_OPBT_CSAVOFCn(0U)) /* PRQA S 0303, 3432 # Advisory R-11.4, DP_MSR_R-20.7_UC1 */
                {
                    (void) r_bsp_issue_switch_erasure_command();

                    status = BSP_OPBT_STATUS_AREA_NOT_PROGRAMMED;
                }
                else
                {
                    uint8_t not_programmed_flag = 0U;
                    uint8_t reg_index;
                    for (reg_index = 8U; reg_index <= 19U; reg_index++)
                    {
                        if (BSP_OPBT_SWITCH_AREA_IS_PROGRAMMED != BSP_OPBT_CSAVOFCn(reg_index)) /* PRQA S 0303, 3432, 4391 # Advisory R-11.4, DP_MSR_R-20.7_UC1, DP_MSR_R-10.8_UC1 */
                        {
                            not_programmed_flag = 1U;
                            break;
                        }
                    }

                    if (1U == not_programmed_flag)
                    {
                        status = r_bsp_issue_switch_erasure_command();

                        if (BSP_OPBT_STATUS_SUCCESS != status)
                        {
                            return status;
                        }
                    }
                }
            }
        }
        else if (BSP_OPBT_BSP_CONFIGURATION_SETTING_AREA_0_VALID ==
                 BSP_OPBT_CVA_INVALID_SIDE)                                      /* PRQA S 0303 # Advisory R-11.4 */
        {
            /* Check whether the Switch Area value is valid */
            if (0U != (BSP_OPBT_FSWASTAT_0 & BSP_OPBT_FSWASTAT_0_CFGVA_BIT_MSK)) /* PRQA S 0303 # Advisory R-11.4 */
            {
                /* Check BSP_OPBT_CSAVOFCn (n = 0, 8 to 19). If one of these register is not programmed, issue Switch Erasure Command */
                if (BSP_OPBT_SWITCH_AREA_IS_PROGRAMMED != BSP_OPBT_CSAVOFCn(0U)) /* PRQA S 0303, 3432 # Advisory R-11.4, DP_MSR_R-20.7_UC1 */
                {
                    (void) r_bsp_issue_switch_erasure_command();

                    status = BSP_OPBT_STATUS_AREA_NOT_PROGRAMMED;
                }
                else
                {
                    uint8_t not_programmed_flag = 0U;
                    uint8_t reg_index;
                    for (reg_index = 8U; reg_index <= 19U; reg_index++)
                    {
                        if (BSP_OPBT_SWITCH_AREA_IS_PROGRAMMED != BSP_OPBT_CSAVOFCn(reg_index)) /* PRQA S 0303, 3432, 4391 # Advisory R-11.4, DP_MSR_R-20.7_UC1, DP_MSR_R-10.8_UC1 */
                        {
                            not_programmed_flag = 1U;
                            break;
                        }
                    }

                    if (1U == not_programmed_flag)
                    {
                        (void) r_bsp_issue_switch_erasure_command();

                        status = BSP_OPBT_STATUS_AREA_NOT_PROGRAMMED;
                    }
                }
            }
        }
        else
        {
            /* If CVA is neither Area 0 nor Area 1, issue Switch Erasure Command */
            (void) r_bsp_issue_switch_erasure_command();

            status = BSP_OPBT_STATUS_AREA_NOT_PROGRAMMED;
        }
    }
    else
    {
        /* If AnPC is not programmed, issue Switch Erasure Command */
        (void) r_bsp_issue_switch_erasure_command();

        status = BSP_OPBT_STATUS_AREA_NOT_PROGRAMMED;
    }

    return status;
}

/*******************************************************************************************************************//**
 * Execute the TAG Erasure Command. The TAG Erasure Command and TAG Update Command are used for the change of the
 * data in TAG Area.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_issue_tag_erase_command (void)
{
    bsp_opbt_status_t status;

    /* Set the start address of TAG Area */
    BSP_OPBT_FSADDR_0 = (BSP_OPBT_TAG_BASE + BSP_OPBT_VAF_OFFSET); /* PRQA S 0303 # Advisory R-11.4 */

    /* Issue the TAG Erasure Command */
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                       /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_TAG_ERASURE_1ST_ACCESS;
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                       /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_TAG_ERASURE_2ND_ACCESS;

    status = bsp_opbt_wait_flash_ready(BSP_OPBT_VALUE_TAG_ERASE_TIMEOUT);

    return status;
}

/*******************************************************************************************************************//**
 * Execute the TAG Update Command. The TAG Erasure Command and TAG Update Command are used for the change of the
 * data in TAG Area.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_issue_tag_update_command (void)
{
    bsp_opbt_status_t status;

    /* Set the start address of TAG Area */
    BSP_OPBT_FSADDR_0 = (BSP_OPBT_TAG_BASE + BSP_OPBT_VAF_OFFSET); /* PRQA S 0303 # Advisory R-11.4 */

    /* Issue the TAG Update Command */
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                       /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_TAG_UPDATE_1ST_ACCESS;
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                       /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_TAG_UPDATE_2ND_ACCESS;

    status = bsp_opbt_wait_flash_ready(BSP_OPBT_VALUE_TAG_UPDATE_TIMEOUT);

    return status;
}

/*******************************************************************************************************************//**
 * Shift the MCU to read mode to read the flash memory.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_shift_to_read_mode (void)
{
    bsp_opbt_status_t status     = BSP_OPBT_STATUS_SUCCESS;
    volatile uint16_t timeout_ms = BSP_OPBT_VALUE_SHIFT_TO_READ_TIMEOUT;

    /* Write 0xAA00 to BSP_OPBT_FENTRYR_0 register */
    BSP_OPBT_FENTRYR_0 = BSP_OPBT_FACI_COMMAND_SHIFT_TO_READ_MODE;              /* PRQA S 0303 # Advisory R-11.4 */

    /* Wait for FENTRYD bit to be cleared */
    while ((0U != (BSP_OPBT_FENTRYR_0 & BSP_OPBT_FENTRYR_0_FENTRYD_BIT_MSK)) && /* PRQA S 0303 # Advisory R-11.4 */
           (0U != timeout_ms))                                                  /* PRQA S 3415 # DP_MSR_R-13.5_UC1 */
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);
        timeout_ms--;                                                           /* PRQA S 3387 # Advisory R-13.3 */
    }

    if (0U == timeout_ms)
    {
        status = BSP_OPBT_STATUS_TIMEOUT;
    }

    return status;
}

/*******************************************************************************************************************//**
 * Shift the MCU to data flash programming mode to execute operations related to Data Flash erase/program, Switch
 * erase/program and TAG earse/update.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_shift_to_programming_mode (void)
{
    bsp_opbt_status_t status     = BSP_OPBT_STATUS_SUCCESS;
    volatile uint16_t timeout_ms = BSP_OPBT_VALUE_SHIFT_TO_PROGRAM_TIMEOUT;

    /* Write 0xAA80 to BSP_OPBT_FENTRYR_0 register */
    BSP_OPBT_FENTRYR_0 = BSP_OPBT_FACI_COMMAND_SHIFT_TO_PROGRAMMING_MODE;       /* PRQA S 0303 # Advisory R-11.4 */

    /* Wait for FENTRYD bit to be set */
    while ((0U == (BSP_OPBT_FENTRYR_0 & BSP_OPBT_FENTRYR_0_FENTRYD_BIT_MSK)) && /* PRQA S 0303 # Advisory R-11.4 */
           (0U != timeout_ms))                                                  /* PRQA S 3415 # DP_MSR_R-13.5_UC1 */
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);
        timeout_ms--;                                                           /* PRQA S 3387 # Advisory R-13.3 */
    }

    if ((0U == timeout_ms) &&
        (0U == (BSP_OPBT_FENTRYR_0 & BSP_OPBT_FENTRYR_0_FENTRYD_BIT_MSK)))      /* PRQA S 0303 # Advisory R-11.4 */
    {
        status = BSP_OPBT_STATUS_TIMEOUT;

        /* If it's timeout, shift to read mode */
        (void) r_bsp_shift_to_read_mode();
    }

    return status;
}

/*******************************************************************************************************************//**
 * Perform the Configuration Setting Area erase.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_configuration_setting_erase (void)
{
    bsp_opbt_status_t status;

    /* Set the start address of Configuration Setting Area */
    BSP_OPBT_FSADDR_0 = (BSP_OPBT_CSAB_BASE + BSP_OPBT_OTP_SETTING_OFFSET); /* PRQA S 0303 # Advisory R-11.4 */

    /* Issue the Configuration Setting Area Erasure Command */
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                                /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_PROPERTY_ERASURE_1ST_ACCESS;
    BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                                /* PRQA S 0303 # Advisory R-11.4 */
                                             BSP_OPBT_FACI_COMMAND_PROPERTY_ERASURE_2ND_ACCESS;

    status = bsp_opbt_wait_flash_ready(BSP_OPBT_VALUE_PROPERTY_ERASURE_TIMEOUT);

    return status;
}

/*******************************************************************************************************************//**
 * Perform the Configuration Setting Area programming.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_configuration_setting_flash (const uint32_t * p_src,
                                                            const uint32_t   nums_of_regs,
                                                            const uint32_t   base_address)
{
    uint8_t           repetition_count;
    uint8_t           byte_count;
    bsp_opbt_status_t status = BSP_OPBT_STATUS_SUCCESS;

    /* Issue the Configuration Setting Area programming. Can only program 32 bytes / command */
    for (repetition_count = 0U; repetition_count < (nums_of_regs / 8U); repetition_count++)
    {
        BSP_OPBT_FSADDR_0 = base_address + ((uint32_t) repetition_count * 32U); /* PRQA S 0303 # Advisory R-11.4 */

        /* Issue the Configuration Setting Area programming command */
        BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                                /* PRQA S 0303 # Advisory R-11.4 */
                                                 BSP_OPBT_FACI_COMMAND_PROPERTY_PROGRAMMING_1ST_ACCESS;
        BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                                /* PRQA S 0303 # Advisory R-11.4 */
                                                 BSP_OPBT_FACI_COMMAND_PROPERTY_PROGRAMMING_2ND_ACCESS;

        for (byte_count = 0U; byte_count < 8U; byte_count++)
        {
            /* Write the value from the source to the Configuration Setting Area */
            uint32_t write_value = *p_src++;                                  /* PRQA S 1338, 3440 # Advisory R-17.8, Advisory R-13.3 */
            *(volatile uint32_t *) BSP_OPBT_FACI0_COMMAND_ISSUING_AREA_BASE = /* PRQA S 0303 # Advisory R-11.4 */
                                                                              write_value;
        }

        BSP_OPBT_FACI0_COMMAND_ISSUING_UINT8_T =                              /* PRQA S 0303 # Advisory R-11.4 */
                                                 BSP_OPBT_FACI_COMMAND_PROPERTY_PROGRAMMING_3RD_ACCESS;

        status = bsp_opbt_wait_flash_ready(BSP_OPBT_VALUE_PROPERTY_PROGRAMMING_TIMEOUT);

        if (BSP_OPBT_STATUS_SUCCESS != status)
        {
            break;
        }
    }

    return status;
}

/*******************************************************************************************************************//**
 * Enter Program / Erase Data Flash Mode.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_shift_to_program_erase_flash (void)
{
    bsp_opbt_status_t status;

    BSP_OPBT_FHVE3FP_0  |= 1U;         /* PRQA S 0303 # Advisory R-11.4 */
    BSP_OPBT_FHVE15FP_0 |= 1U;         /* PRQA S 0303 # Advisory R-11.4 */

    status = r_bsp_shift_to_programming_mode();

    return status;
}

/*******************************************************************************************************************//**
 * Exit Program / Erase Data Flash Mode.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_exit_program_erase_flash (void)
{
    bsp_opbt_status_t status;
    status = r_bsp_shift_to_read_mode();

    BSP_OPBT_FHVE3FP_0  &= ~1U;        /* PRQA S 0303 # Advisory R-11.4 */
    BSP_OPBT_FHVE15FP_0 &= ~1U;        /* PRQA S 0303 # Advisory R-11.4 */

    return status;
}

/*******************************************************************************************************************//**
 * Perform reading operation from (base_address + offset) to (base_address + offset + legth * 4U).
 **********************************************************************************************************************/
static void r_bsp_opbt_read (uint32_t base_address, uint32_t offset, uint32_t * p_dest, uint32_t length)
{
    uint32_t reg_index;

    for (reg_index = 0U; reg_index < length; reg_index++)
    {
        p_dest[reg_index] =
            *(volatile uint32_t *) (base_address + offset + (4U * reg_index)); /* PRQA S 0303 # Advisory R-11.4 */
    }
}

/*******************************************************************************************************************//**
 * Issue Switch Area command.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_opbt_switch_area (void)
{
    bsp_opbt_status_t status = BSP_OPBT_STATUS_SUCCESS;

    do                                 /* PRQA S 0771 # Advisory R-15.4 */
    {
        /* Switch the CVA value */
        if (BSP_OPBT_VAF ==            /* PRQA S 0303 # Advisory R-11.4 */
            BSP_OPBT_BSP_CONFIGURATION_SETTING_AREA_0_VALID)
        {
            g_cva_value = BSP_OPBT_BSP_CONFIGURATION_SETTING_AREA_1_VALID;
        }
        else
        {
            g_cva_value = BSP_OPBT_BSP_CONFIGURATION_SETTING_AREA_0_VALID;
        }

        /* Read value of SVA, BVAn of the valid side */
        g_sva_value  = BSP_OPBT_SVA_F;  /* PRQA S 0303 # Advisory R-11.4 */
        g_bva0_value = BSP_OPBT_BVA0_F; /* PRQA S 0303 # Advisory R-11.4 */

#if (BSP_FEATURE_OPBT_BVA1_AREA_IS_AVAILABLE)
        g_bva1_value = BSP_OPBT_BVA1_F; /* PRQA S 0303 # Advisory R-11.4 */
#endif

        if (BSP_OPBT_VAPC ==            /* PRQA S 0303 # Advisory R-11.4 */
            BSP_OPBT_SWITCH_AREA_IS_PROGRAMMED)
        {
            /* Perform Switch Erasure Command for Switch Area */
            status = r_bsp_issue_switch_erasure_command();

            /* Verify the Erasure Command for Switch Area was success */
            BSP_OPBT_BREAK_IF_ERROR(status);

            /* Perform Switch Programming Command for Switch Area*/
            status = r_bsp_issue_switch_programming_command();

            /* Verify the Switch Programming Command for Switch Area was success */
            BSP_OPBT_BREAK_IF_ERROR(status);
        }

        /* Perform flag checking for TAG Area */
        status = r_bsp_issue_tag_check_flag();

        /* Verify the flag checking for TAG Area was success */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Perform TAG Erasure Command for TAG Area*/
        status = r_bsp_issue_tag_erase_command();

        /* Verify the Perform TAG Erasure Command for TAG Area was success */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Perform flag checking for TAG Area */
        status = r_bsp_issue_tag_check_flag();

        /* Verify the flag checking for TAG Area was success */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Perform TAG Update Command for TAG Area*/
        status = r_bsp_issue_tag_update_command();

        /* Verify the Perform TAG Update Command for TAG Area was success */
        BSP_OPBT_BREAK_IF_ERROR(status);
    } while (0);

    return status;
}

/*******************************************************************************************************************//**
 * Issue Configuration Setting Area Program command.
 **********************************************************************************************************************/
static bsp_opbt_status_t r_bsp_opbt_programming (void)
{
    bsp_opbt_status_t status = BSP_OPBT_STATUS_SUCCESS;

    do                                 /* PRQA S 0771 # Advisory R-15.4 */
    {
        /* Force Stop */
        r_bsp_issue_force_stop_command();

        /* Perform Erasure Command for Configuration Setting Area */
        status = r_bsp_configuration_setting_erase();

        /* Verify the Erase the Configuration Setting Area was success */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Flash the OPT area */
        status =
            r_bsp_configuration_setting_flash((const uint32_t *) g_otp_buff, BSP_OPBT_NUMBER_OF_OTP_REGS,
                                              (BSP_OPBT_CSAB_BASE + BSP_OPBT_OTP_SETTING_OFFSET));

        /* Verify the Flash the OPT area was success */
        BSP_OPBT_BREAK_IF_ERROR(status);

        /* Force Stop */
        r_bsp_issue_force_stop_command();

        /* Flash the OPBT area */
        status =
            r_bsp_configuration_setting_flash((const uint32_t *) g_opbt_buff,
                                              BSP_OPBT_NUMBER_OF_OPBT_REGS,
                                              (BSP_OPBT_CSAB_BASE +
                                               BSP_OPBT_SOFTWARE_CONFIGURATION_OPTION_BYTE_OFFSET));

        /* Verify the Flash the OPBT area was success */
        BSP_OPBT_BREAK_IF_ERROR(status);
    } while (0);

    return status;
}

/*******************************************************************************************************************//**
 * Wait for the FACI command processing.
 **********************************************************************************************************************/
static bsp_opbt_status_t bsp_opbt_wait_flash_ready (volatile uint32_t timeout_ms)
{
    while (0U == (BSP_OPBT_FSTATR_0 & BSP_OPBT_FSTATR_0_FRDY_BIT_MSK)) /* PRQA S 0303 # Advisory R-11.4 */
    {
        if (0U == timeout_ms)
        {
            /* Timeout -> Abort current operation */
            r_bsp_issue_force_stop_command();

            return BSP_OPBT_STATUS_TIMEOUT;
        }

        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);

        timeout_ms--;                                                /* PRQA S 1338, 3387 # Advisory R-17.8, Advisory R-13.3 */
    }

    /* FRDY == 1 -> Sequencer idle */
    if (0U != (BSP_OPBT_FASTAT_0 & BSP_OPBT_FASTAT_0_CMDLK_BIT_MSK)) /* PRQA S 0303 # Advisory R-11.4 */
    {
        r_bsp_return_from_command_lock_state();

        return BSP_OPBT_STATUS_FAIL;
    }

    return BSP_OPBT_STATUS_SUCCESS;
}

/*******************************************************************************************************************//**
 * Release the command lock state.
 **********************************************************************************************************************/
static void r_bsp_return_from_command_lock_state (void)
{
    volatile uint16_t timeout_ms = BSP_OPBT_VALUE_RETURN_FROM_COMMAND_LOCK_TIMEOUT;

    /* Wait for FRDY bit in FSTATR_0 register set */
    while ((0U == (BSP_OPBT_FSTATR_0 & BSP_OPBT_FSTATR_0_FRDY_BIT_MSK)) && /* PRQA S 0303 # Advisory R-11.4 */
           (0U != timeout_ms))                                             /* PRQA S 3415 # DP_MSR_R-13.5_UC1 */
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);
        timeout_ms--;                                                      /* PRQA S 3387 # Advisory R-13.3 */
    }

    /* If FRDY bit is not set, issue force stop */
    if ((0U == timeout_ms) &&
        (0U == (BSP_OPBT_FSTATR_0 & BSP_OPBT_FSTATR_0_FRDY_BIT_MSK)))           /* PRQA S 0303 # Advisory R-11.4 */
    {
        r_bsp_issue_force_stop_command();
    }
    else if (0U != (BSP_OPBT_FSTATR_0 & BSP_OPBT_FSTATR_0_FRDY_BIT_MSK))        /* PRQA S 0303 # Advisory R-11.4 */
    {
        /* Check ILGLERR bit */
        if (0U == (BSP_OPBT_FSTATR_0 & BSP_OPBT_FSTATR_0_ILGLERR_BIT_MSK))      /* PRQA S 0303 # Advisory R-11.4 */
        {
            if ((0U != (BSP_OPBT_FASTAT_0 & BSP_OPBT_FASTAT_0_CFAE_BIT_MSK)) || /* PRQA S 0303 # Advisory R-11.4 */
                (0U != (BSP_OPBT_FASTAT_0 & BSP_OPBT_FASTAT_0_DFAE_BIT_MSK)))   /* PRQA S 0303 # Advisory R-11.4 */
            {
                BSP_OPBT_FASTAT_0 &=                                            /* PRQA S 0303 # Advisory R-11.4 */
                                     ~(BSP_OPBT_FASTAT_0_CFAE_BIT_MSK | BSP_OPBT_FASTAT_0_DFAE_BIT_MSK);
            }
        }

        r_bsp_issue_force_stop_command();
    }
    else
    {
        /* Do nothing */
    }
}
