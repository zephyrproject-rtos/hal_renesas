/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_TCS_H
#define BSP_TCS_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define CS_MAX_SIZE             (1024 + 768)                       // Renesas CS (NVR) area: NVR offsets 0x0400-0x0B00 = 1792 bytes
#define CS_CUSTOMER_MAX_SIZE    (BSP_CFG_TCS_CUSTOMER_CS_MAX_SIZE) /* Total customer CS size in 32-bit words. BSP_CFG_TCS_CUSTOMER_CS_MAX_SIZE is the full buffer size; the start command word and stop command word are subtracted from this total, leaving BSP_CFG_TCS_CUSTOMER_CS_MAX_SIZE - 2 words of usable payload. */
#define GID_EMPTY               0x1FF
#define BSP_TCS_GID_COUNT       (0xE0)
#define CS_EMPTY_VAL            0xFFFFFFFF

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**
 * \enum BSP_TCS_TYPE
 * \brief custom TCS value type.
 *
 */
typedef enum
{
    BSP_TCS_TYPE_TRIM_VAL = 0,         /**< trimmed value */
    BSP_TCS_TYPE_REG_PAIR,             /**< register pair value */
    BSP_TCS_TYPE_RESERVED              /**< reserved */
} BSP_TCS_TYPE;

/**
 * \brief the configured group ids.
 *
 */
typedef enum
{
    BSP_TCS_GID_BOOT = 0x00,

    /* Power Domains Section */
    BSP_TCS_GID_PD_SYS = 0x01,              /**< PD_SYS group id */
    BSP_TCS_GID_PD_SLP = 0x02,              /**< PD_SLP group id */
    BSP_TCS_GID_PD_COM = 0x03,              /**< PD_COM group id */
    BSP_TCS_GID_PD_MEM = 0x04,              /**< PD_MEM group id */
    BSP_TCS_GID_PD_TIM = 0x05,              /**< PD_TIM group id */
    BSP_TCS_GID_PD_RAD = 0x06,              /**< PD_RAD group id */
    BSP_TCS_GID_PD_AUD = 0x07,              /**< PD_AUD group id */
    BSP_TCS_GID_PD_PER = 0x08,              /**< PD_PER group id */

    /* System Section */
    BSP_TCS_GID_BD_ADDR = 0x20,             /**< BD_ADDR group id */

    /* Analog Section */
    BSP_TCS_GID_TEMP_SENS_25C   = 0x40,     /**< TEMP_SENS_25C group id */
    BSP_TCS_GID_DCDC_TRIM       = 0x41,     /**< DCDC_TRIM group id */
    BSP_TCS_GID_ADC_SINGLE_TRIM = 0x42,     /**< ADC_SINGLE_TRIM group id */
    BSP_TCS_GID_ADC_DIFF_TRIM   = 0x43,     /**< ADC_DIFF_TRIM group id */

    /* Radio Section */
    BSP_TCS_GID_PD_RAD_MODE1   = 0x80,      /**< PD_RAD_MODE1 group id */
    BSP_TCS_GID_PD_RAD_HP_MODE = 0x81,      /**< RAD_HP_MODE group id */
    BSP_TCS_GID_PD_RAD_MODE3   = 0x82,      /**< PD_RAD_MODE3 group id */
    BSP_TCS_GID_PD_RAD_LP_MODE = 0x83,      /**< RAD_LP_MODE group id */
    BSP_TCS_GID_PD_RAD_COEFF   = 0x84,      /**< PD_RAD_COEFF group id */

    /* Production Test Section */
    BSP_TCS_GID_CHIP_ID             = 0xC0, /**< CHIP_ID group id */
    BSP_TCS_GID_PROD_INFO           = 0xC1, /**< PROD_INFO group id */
    BSP_TCS_GID_PROD_WAFER          = 0xC2, /**< PROD_WAFER group id */
    BSP_TCS_GID_TESTPROGRAM_VERSION = 0xC3, /**< TESTPROGRAM_VERSION  group id */
} bsp_tcs_gid_t;

/**
 * \struct bsp_tcs_attr_t
 * \brief attributes per custom value group id
 *
 */
typedef struct
{
    uint16_t value_type : 1;           /**< TCS entry type */
    uint16_t start      : 9;           /**< TCS entry start position  */
    uint16_t size       : 6;           /**< TCS entry type size in words */
} bsp_tcs_attr_t;

/**
 * \brief register configuration attributes
 *
 */
typedef struct
{
    uint32_t reg_conf_start_address;
    uint32_t size;
} bsp_tcs_reg_conf_attr_t;

/**
 * \brief shared tcs configuration properties
 *
 */
typedef struct
{
    uint32_t       * tcs_data_ptr;        /*!< Pointer to TCS data as read by the TCS parser */
    uint32_t         tcs_data_size;       /*!< Number of words in the tcs_data */
    bsp_tcs_attr_t * tcs_attributes_ptr;  /*!< Pointer to TCS attributes */
    uint32_t         tcs_attributes_size; /*!< Number of entries in atrributes table */
    uint32_t         cs_program_version;  /*!< The version of the CS as described by the TCS_GROUP_TESTPROGRAM_VERSION attribute*/
} bsp_tcs_shared_t;

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Function Prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * ISR Prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Global Variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public Functions
 **********************************************************************************************************************/

/**
 * \brief TCS custom trim values callback
 *
 * \param [in] values_group the TCS group id custom trim values belong to
 * \param [in] user_data user specific data
 * \param [in] values custom trim values
 * \param [in] size the number of the custom trim values
 *
 */
typedef void (* bsp_tcs_custom_values_cb)(bsp_tcs_gid_t values_group, void * user_data, uint32_t * values,
                                          uint8_t size);

/**
 * \brief Initialize all CS values.
 */

BSP_PLACE_CODE_IN_RAM void bsp_prv_tcs_init(void);

/**
 * \brief check if the register addresses included in reg_address are configured in CS
 * \param [in] reg_address pointer to array containing the register addresses
 * \param [in] num number of register addresses
 * \param [out] trimmed_reg pointer to array containing information whether the corresponding
 * register is included in CS or not
 *
 * \return true if all register addresses are included in CS
 *
 * \warning search register values in OTP only, OTP should be already enabled.
 */
bool bsp_tcs_reg_pairs_in_cs(const uint32_t * reg_address, uint8_t num, bool * trimmed_reg);

/**
 * \brief get the pointer to tcs_attributes lookup table
 *
 */
bsp_tcs_attr_t * bsp_tcs_get_tcs_attributes_ptr(void);

/**
 * \brief get the pointer to tcs_data memory block
 */
uint32_t * bsp_tcs_get_tcs_data_ptr(void);

/**
 * \brief get the number of the register pair values or custom values per gid
 *
 * \param [in] gid the TCS group id
 *
 * \return the number of trim values per group id
 */
uint8_t bsp_tcs_get_size(bsp_tcs_gid_t gid);

/**
 * \brief get value type, register pair values or custom values per gid
 *
 * \param [in] gid the TCS group id
 *
 * \return the type of trim value per group id
 */
BSP_TCS_TYPE bsp_tcs_get_value_type(bsp_tcs_gid_t gid);

/**
 * \brief get the custom_trim_values per gid
 *
 * \param [in] gid the TCS group id of the requested custom trim values
 * \param [out] values the pointer to the start of the custom trim values
 * \param [out] size the number of the custom trim values
 *
 * \warning if size is zero then there are no custom trim values for this gid,
 *  values points to invalid data. size should have been initialized to zero
 */
void bsp_tcs_get_custom_values(bsp_tcs_gid_t gid, uint32_t ** values, uint8_t * size);

/**
 * \brief handles the custom_trim_values per gid according to callback
 *
 * \param [in] gid the TCS group id of custom trim values to apply
 * \param [in] cb the callback that applies the custom trim values
 * \param [in] user_data the argument to callback function
 *
 * \warning callback is called only if custom trim values are configured
 */
void bsp_tcs_apply_custom_values(bsp_tcs_gid_t gid, bsp_tcs_custom_values_cb cb, void * user_data);

/**
 * \brief Get register value pairs contained in a group id of the TCS array
 * \param [in] gid the group id
 * \param [out] values the pointer to the start of the register pair values
 * \param [out] size the number of the register pair values
 *
 * \warning if size is zero then values is not a valid pointer. size should have been
 * initialized to zero
 */
void bsp_tcs_get_reg_pairs(bsp_tcs_gid_t gid, uint32_t ** values, uint8_t * size);

/**
 * \brief Apply the register value pairs contained in a group id of the TCS array.
 * \param [in] gid the group id
 *
 */

void bsp_tcs_apply_reg_pairs(bsp_tcs_gid_t gid);

uint32_t bsp_tcs_get_reg_conf_size(void);

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of t
 * his file. */
FSP_FOOTER

#endif
