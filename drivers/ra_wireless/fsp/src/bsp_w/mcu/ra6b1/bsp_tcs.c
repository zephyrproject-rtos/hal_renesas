/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_tcs.h"
#include "bsp_pd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define TCS_TEMP_RENESAS_BUFFER     ((uint32_t *) 0x33100000UL)               /* Raw Renesas CS scratch buffer in CMAC RAM0. */
#define TCS_TEMP_BUFFER_CUSTOMER    ((uint32_t *) 0x33100000UL + CS_MAX_SIZE) /* Raw Customer CS scratch buffer, directly after the Renesas area. */
#define CS_START_CMD                0xA5A5A5A5
#define CS_BOOTER_VAL               0xE6000000
#define CS_MIN_FW_VAL               0xEB000000
#define CS_SDK_VAL                  0xE9000000
#define CS_REG_CONF_VAL             0xEDADAE00
#define CS_STOP_CMD                 0xDEADC0DE
#define CS_BASE_ADDRESS             (BSP_FEATURE_FLASH_NVMC_W_S_DATA_START + 0x400) /* Renesas CS lives in NVR sector. */
#define CS_CUSTOMER_BASE_ADDRESS    (BSP_FEATURE_FLASH_NVMC_W_S_DATA_START)         /* Customer CS lives at NVM offset 0. */
#define MAX_REG_ADDR                0x40800300
#define CS_SDK_VAL_GID_MASK         0x000000FF
#define CS_SDK_VAL_LEN_MASK         0x0000FF00
#define CS_SDK_VAL_SETID_MASK       0x00FF0000
#define CS_SDK_REG_CONF_LEN_MASK    0x000000FF
#define REG_NUM                     0xFF /* The maximum amount of reg pairs allowed */

#ifdef TEST_BSP_TCS
 #define TEST_STATIC                     /* TODO: This should be replaced by TESTABLE_STATIC when fixed */
#else
 #define TEST_STATIC                static
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef struct
{
    uint32_t reg_address;
    bool     trimmed;
} reg_trimmed_t;

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

static uint32_t fetch_tcs_entry(uint32_t address);

static void store_tcs(uint32_t address, uint8_t gid_len);

BSP_PLACE_CODE_IN_RAM TEST_STATIC void bsp_tcs_get_trim_values_from_cs(void);

BSP_PLACE_CODE_IN_RAM TEST_STATIC uint8_t bsp_tcs_fetch_values(void);

static uint8_t get_size_of_cs(uint16_t max_size);

static void store_cs_attributes(uint16_t size);

static void init_tcs_attributes_array(void);

static uint32_t check_valid_register_configuration(uint32_t address, uint32_t size);

static bool parse_cs_for_booter_reg_pair(uint8_t num, reg_trimmed_t * reg);

BSP_PLACE_CODE_IN_RAM static void fill_buffer_with_cs_values(uint32_t base_address, uint16_t max_size,
                                                             uint32_t * buffer);

BSP_PLACE_CODE_IN_RAM static uint8_t load_cs_to_buffer(uint32_t base_address, uint16_t max_size, uint32_t * buffer);

/***********************************************************************************************************************
 * ISR Prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Global Variables
 **********************************************************************************************************************/

/* Static allocation for tcs_data */
static bsp_tcs_reg_conf_attr_t reg_conf_attr;

/* The following values need to be preserved for CS values that need to be applied after startup */
static uint32_t * tcs_data BSP_PLACE_IN_SECTION(BSP_SECTION_NOINIT);

TEST_STATIC uint32_t __tcs_data[(CS_MAX_SIZE + CS_CUSTOMER_MAX_SIZE) / 4 + 1] BSP_PLACE_IN_SECTION(
    BSP_SECTION_NOINIT);
TEST_STATIC bsp_tcs_attr_t tcs_attributes[BSP_TCS_GID_COUNT]                        BSP_PLACE_IN_SECTION(
    BSP_SECTION_NOINIT);

/* Active raw CS source buffer used by fetch_tcs_entry() during parsing. Switched between
 * Renesas and Customer buffers as the parser progresses through both areas. */
static uint32_t * current_cs_buffer = TCS_TEMP_RENESAS_BUFFER;

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public Functions
 **********************************************************************************************************************/

BSP_PLACE_CODE_IN_RAM void bsp_prv_tcs_init (void)
{
    tcs_data = NULL;
    memset(__tcs_data, 0, sizeof(__tcs_data));
    memset(tcs_attributes, 0, sizeof(tcs_attributes));

    /* Fetch values from NVR */
    bsp_tcs_fetch_values();

    /* Create settings structure table */
    bsp_tcs_get_trim_values_from_cs();

    /*
     * Apply tcs settings.
     * They need to be re-applied whenever these power domains are powered off.
     */
    bsp_tcs_apply_reg_pairs(BSP_TCS_GID_PD_SYS);
    bsp_tcs_apply_reg_pairs(BSP_TCS_GID_PD_MEM);
}

bsp_tcs_attr_t * bsp_tcs_get_tcs_attributes_ptr (void)
{
    return tcs_attributes;
}

uint32_t * bsp_tcs_get_tcs_data_ptr (void)
{
    return tcs_data;
}

bool bsp_tcs_reg_pairs_in_cs (const uint32_t * reg_address, uint8_t num, bool * trimmed_reg)
{
    bool          ret = false;
    reg_trimmed_t regs[REG_NUM];
    if ((reg_conf_attr.size == 0) || (num == 0)) // No register configuration has been found
    {
        return false;
    }

    for (uint8_t i = 0; i < num; i++)
    {
        regs[i].reg_address = reg_address[i];
        regs[i].trimmed     = trimmed_reg[i];
    }

    ret = parse_cs_for_booter_reg_pair(num, regs);
    for (uint8_t i = 0; i < num; i++)
    {
        trimmed_reg[i] = regs[i].trimmed;
    }

    return ret;
}

void bsp_tcs_apply_reg_pairs (bsp_tcs_gid_t gid)
{
    if (tcs_data == NULL)
    {
        return;
    }

    uint32_t start = tcs_attributes[gid].start;
    int      size  = (int) tcs_attributes[gid].size;

    while (size > 0)
    {
        *(uint32_t *) tcs_data[start] = tcs_data[start + 1];
        size  -= 2;
        start += 2;
    }
}

/**
 * @brief Get the number of entries stored in the internal TCS data structure.
 *
 * \return  The number of stored TCS entries. Each entry is 32-bit.
 */

uint8_t bsp_tcs_get_size (bsp_tcs_gid_t gid)
{
    return tcs_attributes[gid].size;
}

BSP_TCS_TYPE bsp_tcs_get_value_type (bsp_tcs_gid_t gid)
{
    return (BSP_TCS_TYPE) tcs_attributes[gid].value_type;
}

void bsp_tcs_get_custom_values (bsp_tcs_gid_t gid, uint32_t ** values, uint8_t * size)
{
    if (tcs_data == NULL)
    {

        // TCS is not initialize
        return;
    }

    if (size == NULL)
    {

        // size is mandatory
        return;
    }

    if (tcs_attributes[gid].start == GID_EMPTY)
    {
        *size = 0;
    }
    else
    {
        *size = tcs_attributes[gid].size;
    }

    if (values)
    {
        if (*size == 0)
        {
            *values = NULL;
        }
        else
        {
            /*if size is not zero then start is different than GID_EMPTY for this GID
             * so CS parsing for TCS data is done and tcs_data is valid */
            *values = &tcs_data[tcs_attributes[gid].start];
        }
    }
}

void bsp_tcs_apply_custom_values (bsp_tcs_gid_t gid, bsp_tcs_custom_values_cb cb, void * user_data)
{
    uint32_t * values = NULL;
    uint8_t    size   = 0;
    if (cb)
    {
        bsp_tcs_get_custom_values(gid, &values, &size);
        if (size != 0)
        {
            cb(gid, user_data, values, size);
        }
    }
}

void bsp_tcs_get_reg_pairs (bsp_tcs_gid_t gid, uint32_t ** values, uint8_t * size)
{
    if (tcs_data == NULL)
    {

        // TCS is not initialized
        return;
    }

    if (size == NULL)
    {

        // size is mandatory
        return;
    }

    *size = tcs_attributes[gid].size;

    if (values)
    {
        if (*size == 0)
        {
            *values = NULL;
        }
        else
        {
            /*if size is not zero for register pair entry
             * CS parsing for TCS data is done and tcs_data is valid */
            *values = &tcs_data[tcs_attributes[gid].start];
        }
    }
}

uint32_t bsp_tcs_get_reg_conf_size (void)
{
    return reg_conf_attr.size;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
BSP_PLACE_CODE_IN_RAM TEST_STATIC uint8_t bsp_tcs_fetch_values (void)
{
    uint8_t ret = 0;

    /* CMAC RAM at 0x33100000 is only accessible when PD_RAD is powered on. */
    BSP_CHECK_FATAL(bsp_pd_is_up_check(BSP_PD_RAD));

    __disable_irq();

    /* Read Renesas CS from NVR (NVM_NVR_SECTOR = 1).
     * load_cs_to_buffer and fill_buffer_with_cs_values must be in RAM (BSP_PLACE_CODE_IN_RAM)
     * because when NVM_NVR_SECTOR = 1 the NVM address space is remapped to the NVR sector.
     * Any function call that targets a flash address will fault because that address
     * no longer resolves to the expected instruction — the NVR remapping makes it
     * out-of-bounds from the CPU's perspective. */
    NVMC->NVMC_CTRL_REG_b.NVM_MODE = 0x1; // standby mode
    FSP_HARDWARE_REGISTER_WAIT(NVMC->NVMC_STAT_REG_b.NVM_STANDBY_MODE, 1);

    NVMC->NVMC_CTRL_REG_b.NVM_NVR_SECTOR = 0x1;
    FSP_HARDWARE_REGISTER_WAIT(NVMC->NVMC_STAT_REG_b.NVM_STANDBY_MODE, 1);

    ret = load_cs_to_buffer(CS_BASE_ADDRESS, CS_MAX_SIZE, TCS_TEMP_RENESAS_BUFFER);

    NVMC->NVMC_CTRL_REG_b.NVM_MODE = 0x1; // standby mode
    FSP_HARDWARE_REGISTER_WAIT(NVMC->NVMC_STAT_REG_b.NVM_STANDBY_MODE, 1);

    NVMC->NVMC_CTRL_REG_b.NVM_NVR_SECTOR = 0x0;
    FSP_HARDWARE_REGISTER_WAIT(NVMC->NVMC_STAT_REG_b.NVM_STANDBY_MODE, 1);

    __enable_irq();

    /* Read Customer CS from NVM main array (NVM_NVR_SECTOR = 0, default). */
    /* If the customer area has never been programmed it reads as 0xFFFFFFFF, the */
    /* start-command check below ensures we silently skip parsing in that case.   */
    load_cs_to_buffer(CS_CUSTOMER_BASE_ADDRESS, CS_CUSTOMER_MAX_SIZE, TCS_TEMP_BUFFER_CUSTOMER);

    return ret;
}

BSP_PLACE_CODE_IN_RAM TEST_STATIC void bsp_tcs_get_trim_values_from_cs (void)
{
    uint16_t renesas_size                  = 0;
    uint16_t customer_size                 = 0;
    uint16_t size_table[BSP_TCS_GID_COUNT] = {0};
    bool     has_renesas  = false;
    bool     has_customer = false;

    init_tcs_attributes_array();

    /* Phase 1: accumulate per-GID sizes from Renesas CS. */
    current_cs_buffer = TCS_TEMP_RENESAS_BUFFER;
    if (fetch_tcs_entry(0) == CS_START_CMD)
    {
        has_renesas  = true;
        renesas_size = get_size_of_cs(CS_MAX_SIZE);
    }

    /* Phase 2: accumulate per-GID sizes from Customer CS. For REG_PAIR the
     * customer entries extend the GID's allocation; for TRIM_VAL the customer size
     * (last seen) replaces the Renesas size, matching the existing last-write-wins rule. */
    current_cs_buffer = TCS_TEMP_BUFFER_CUSTOMER;
    if (fetch_tcs_entry(0) == CS_START_CMD)
    {
        has_customer  = true;
        customer_size = get_size_of_cs(CS_CUSTOMER_MAX_SIZE);
    }

    if (!has_renesas && !has_customer)
    {
        return;
    }

    if (!((renesas_size + customer_size) < (CS_MAX_SIZE + CS_CUSTOMER_MAX_SIZE)))
    {
        return;
    }

    /* Static allocation for tcs_data */
    tcs_data = __tcs_data;

    /* Compute per-GID offsets in __tcs_data based on combined Renesas + Customer sizes,
     * so the green area concatenates seamlessly with the red area in __tcs_data. */
    uint8_t gid_offset = 0;
    for (uint16_t gid = 0; gid < BSP_TCS_GID_COUNT; gid++)
    {
        if (tcs_attributes[gid].size != 0)
        {
            tcs_attributes[gid].start = gid_offset;
            gid_offset               += tcs_attributes[gid].size;
        }
    }

    // reuse the sizes table as index table
    memset(size_table, 0, sizeof(size_table));

    /* Phase 3: store Renesas CS entries into __tcs_data. */
    if (has_renesas)
    {
        current_cs_buffer = TCS_TEMP_RENESAS_BUFFER;
        store_cs_attributes(CS_MAX_SIZE);
    }

    /* Phase 4: store Customer CS entries. REG_PAIR entries append into the GID's
     * allocation; TRIM_VAL entries overwrite (last-write-wins). */
    if (has_customer)
    {
        current_cs_buffer = TCS_TEMP_BUFFER_CUSTOMER;
        store_cs_attributes(CS_CUSTOMER_MAX_SIZE);
    }
}

static uint32_t check_valid_register_configuration (uint32_t address, uint32_t size)
{
    uint32_t value;
    uint32_t address_skips = 0;
    address += 1;                      /* Skip the 0xEDADAEXX identifier*/
    for ( ; address_skips < (size) * 2; address_skips += 2)
    {
        value = fetch_tcs_entry(address + address_skips);
        if (value > MAX_REG_ADDR)
        {
            return 0;
        }
    }

    return address_skips;
}

static uint32_t fetch_tcs_entry (uint32_t address)
{
    uint32_t cs_value = 0xFFFFFFFF;
    cs_value = current_cs_buffer[address];

    return cs_value;
}

static void store_tcs (uint32_t address, uint8_t gid_len)
{
    int      i = 0;
    uint16_t index;

    // address --> GID header
    uint32_t      value = fetch_tcs_entry(address);
    bsp_tcs_gid_t gid   = (bsp_tcs_gid_t) (value & CS_SDK_VAL_GID_MASK);

    if (gid >= BSP_TCS_GID_COUNT)
    {
        return;
    }

    BSP_TCS_TYPE type = bsp_tcs_get_value_type(gid);

    if (type == BSP_TCS_TYPE_TRIM_VAL)
    {
        // BSP_TCS_TYPE_TRIM_VAL could have different sizes during parsing
        // it is acceptable multiple instances with same GID to have different sizes,
        // only the newest will be finally stored. We cannot identify the newest but
        // at least the ones that fit will be stored until the newest is parsed
        if (gid_len != tcs_attributes[gid].size)
        {
            return;
        }
    }

    /* start of storing TCS entries */

    index = tcs_attributes[gid].start;

    // for BSP_TCS_TYPE_REG_PAIR search tcs_data to find empty slot
    // for BSP_TCS_TYPE_TRIM_VAL fragmentation is not supported and always the newest entries are stored
    if (type == BSP_TCS_TYPE_REG_PAIR)
    {
        uint16_t gid_start = index;
        uint8_t  gid_size  = tcs_attributes[gid].size;

        // search tcs_data to find empty slot
        while (tcs_data[index] != 0)
        {
            /* check if the index is inside the allocated space in tcs_data[] for this GID */
            if (index >= (gid_start + gid_size))
            {
                return;
            }

            // go to next register address
            index += 2;
        }
    }

    while (i < gid_len)                // 4 bytes entries
    {
        address        += 1;
        tcs_data[index] = fetch_tcs_entry(address);
        index++;
        i++;
    }
}

/* The calculated size in bytes, that is the number
 * of entries * sizeof(int)
 */
static uint8_t get_size_of_cs (uint16_t max_size)
{
    uint32_t address = 0;
    uint8_t  size    = 0;
    uint32_t value   = fetch_tcs_entry(address);

    if (value != CS_START_CMD)
    {
        return 0;
    }

    // check next entry
    address += 1;
    while (address < max_size)
    {
        value = fetch_tcs_entry(address);

        if ((value == CS_STOP_CMD) || (value == CS_EMPTY_VAL))
        {
            break;                                                     // End of CS
        }
        else if (value <= MAX_REG_ADDR)                                // address value pair parsed by bootrom, skip this value
        {
            address += 1;
        }
        else if ((value == CS_BOOTER_VAL) || (value == CS_MIN_FW_VAL)) // skip booter value and minimun FW version value
        {
            address += 1;
        }
        else if ((value & 0xFF000000) == CS_SDK_VAL)                   // SDK value
        {
            uint8_t       tcs_len = (value & CS_SDK_VAL_LEN_MASK) >> 8;
            bsp_tcs_gid_t gid     = (bsp_tcs_gid_t) (value & CS_SDK_VAL_GID_MASK);
            uint8_t       setid   = (value & CS_SDK_VAL_SETID_MASK) >> 16;
            address += tcs_len;        // skip next tcs values.

            if ((gid >= BSP_TCS_GID_COUNT) || (setid != 0x00))
            {
                address += 1;          // skip this entry
                continue;
            }

            if (bsp_tcs_get_value_type(gid) == BSP_TCS_TYPE_TRIM_VAL)
            {
                /*always keep the last found size */
                if (tcs_attributes[gid].size != tcs_len)
                {
                    /* update with new size */
                    size -= 1 * tcs_attributes[gid].size;
                    size += 1 * tcs_len;
                    tcs_attributes[gid].size = (unsigned) (tcs_len & 0x3F);
                }
            }
            else
            {
                // check that BSP_TCS_TYPE_REG_PAIR values are of an even number
                if (bsp_tcs_get_value_type(gid) == BSP_TCS_TYPE_REG_PAIR)
                {
                    if (!(tcs_len & 0x01) == 0)
                    {
                        return 0;
                    }
                }

                size += (uint8_t) (4 * tcs_len); // size should be in bytes
                tcs_attributes[gid].size += (unsigned) (tcs_len & 0x3F);
            }
        }

        // go to next word this value is not related to TCS
        address += 1;
    }

    return size;
}

static void store_cs_attributes (uint16_t size)
{
    uint32_t address = 1;              // skip CS_START_CMD

    while (address < size)
    {
        uint32_t value = fetch_tcs_entry(address);

        if ((value == CS_STOP_CMD) || (value == CS_EMPTY_VAL))
        {
            break;                                                     // End of CS
        }
        else if ((value == CS_BOOTER_VAL) || (value == CS_MIN_FW_VAL)) // skip booter value and minimun FW version value
        {
            address += 1;
        }
        else if (((value & 0xFFFFFF00) == CS_REG_CONF_VAL))            // Register Configuration section
        {
            uint32_t ret_size     = value & CS_SDK_REG_CONF_LEN_MASK;
            uint32_t address_skip = 0;
            if (size == 0)
            {
                continue;
            }

            address_skip = check_valid_register_configuration(address, ret_size);
            if (address_skip > 0)
            {
                reg_conf_attr.reg_conf_start_address = address;
                reg_conf_attr.size = ret_size;
            }

            address     += address_skip;
            address_skip = 0;
        }
        else if (value <= MAX_REG_ADDR)              // register that is not part of the configuration, this should not happen
        {
            address += 1;
        }
        else if ((value & 0xFF000000) == CS_SDK_VAL) // SDK value
        {
            uint8_t gid_len = (value & CS_SDK_VAL_LEN_MASK) >> 8;
            uint8_t setid   = (value & CS_SDK_VAL_SETID_MASK) >> 16;

            /* store entries with SET ID 0x00 */
            if (setid == 0x00)
            {
                store_tcs(address, gid_len);
            }

            address += gid_len;        // skip next tcs values.
        }

        address += 1;
    }
}

static void init_tcs_attributes_array (void)
{
    uint8_t reg_pair_gids[] =
    {
        BSP_TCS_GID_BOOT,              /* BSP_TCS_GROUP_PD_BOOT         (0x00) */
        BSP_TCS_GID_PD_SYS,            /* BSP_TCS_GROUP_PD_SYS          (0x01) */
        BSP_TCS_GID_PD_SLP,            /* BSP_TCS_GROUP_PD_SLP          (0x02) */
        BSP_TCS_GID_PD_COM,            /* BSP_TCS_GROUP_PD_COM          (0x03) */
        BSP_TCS_GID_PD_MEM,            /* BSP_TCS_GROUP_PD_MEM          (0x04) */
        BSP_TCS_GID_PD_TIM,            /* BSP_TCS_GROUP_PD_TIM          (0x05) */
        BSP_TCS_GID_PD_RAD,            /* BSP_TCS_GROUP_PD_RAD          (0x06) */
        BSP_TCS_GID_PD_AUD,            /* BSP_TCS_GROUP_PD_AUD          (0x07) */
        BSP_TCS_GID_PD_PER,            /* BSP_TCS_GROUP_PD_PER          (0x08) */
        BSP_TCS_GID_PD_RAD_MODE1,      /* BSP_TCS_GROUP_PD_RAD_MODE1    (0x80) */
        BSP_TCS_GID_PD_RAD_MODE3,      /* BSP_TCS_GROUP_PD_RAD_MODE3    (0x82) */
        BSP_TCS_GID_PD_RAD_LP_MODE,    /* BSP_TCS_GROUP_PD_RAD_LP_MODE  (0x83) */
    };
    uint32_t i = 0;
    for (i = 0; i < BSP_TCS_GID_COUNT; i++)
    {
        // Initialize start to point to not configured GID
        tcs_attributes[i].start = GID_EMPTY;
        tcs_attributes[i].size  = 0;
    }

    for (i = 0; i < sizeof(reg_pair_gids); i++)
    {
        // configure register address value pair type.
        tcs_attributes[reg_pair_gids[i]].value_type = BSP_TCS_TYPE_REG_PAIR;
    }
}

static bool parse_cs_for_booter_reg_pair (uint8_t num, reg_trimmed_t * reg)
{
    bool       found_conf   = false;
    uint32_t * buffers[2]   = {TCS_TEMP_RENESAS_BUFFER, TCS_TEMP_BUFFER_CUSTOMER};
    uint16_t   max_sizes[2] = {CS_MAX_SIZE, CS_CUSTOMER_MAX_SIZE};

    for (uint8_t b = 0; b < 2; b++)
    {
        current_cs_buffer = buffers[b];

        /* Customer CS is optional; skip if not present. */
        if ((b == 1) && (fetch_tcs_entry(0) != CS_START_CMD))
        {
            continue;
        }

        uint32_t address = 1;
        while (address < max_sizes[b])
        {
            uint32_t value = fetch_tcs_entry(address);
            if ((value == CS_STOP_CMD) || (value == CS_EMPTY_VAL))
            {
                break;
            }

            if ((value & 0xFFFFFF00) == CS_REG_CONF_VAL)
            {
                uint32_t size = value & CS_SDK_REG_CONF_LEN_MASK;
                found_conf = true;
                for (uint8_t i = 0; i < num; i++)
                {
                    reg[i].trimmed = false;
                    for (uint32_t j = 1; j < size * 2; j += 2)
                    {
                        if (fetch_tcs_entry(address + j) == reg[i].reg_address)
                        {
                            reg[i].trimmed = true;
                            break;
                        }
                    }
                }

                break;
            }

            address++;
        }
    }

    if (!found_conf)
    {
        return false;
    }

    for (uint8_t i = 0; i < num; i++)
    {
        if (!reg[i].trimmed)
        {
            return false;
        }
    }

    return true;
}

BSP_PLACE_CODE_IN_RAM static void fill_buffer_with_cs_values (uint32_t   base_address,
                                                              uint16_t   max_size,
                                                              uint32_t * buffer)
{
    buffer[0] = CS_START_CMD;          // already verified by caller
    for (uint16_t i = 1; i < max_size; i++)
    {
        buffer[i] = *(uint32_t *) (base_address + 4 * i);
        if (buffer[i] == CS_STOP_CMD)
        {
            break;
        }
    }
}

BSP_PLACE_CODE_IN_RAM static uint8_t load_cs_to_buffer (uint32_t base_address, uint16_t max_size, uint32_t * buffer)
{
    if (*(uint32_t *) (base_address) != CS_START_CMD)
    {
        buffer[0] = CS_EMPTY_VAL;

        return 1;
    }

    fill_buffer_with_cs_values(base_address, max_size, buffer);

    return 0;
}

/***********************************************************************************************************************
 * Interrupt Service Routines
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU) */
