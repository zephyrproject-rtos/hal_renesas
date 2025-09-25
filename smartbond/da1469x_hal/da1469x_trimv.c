/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <assert.h>
#include <string.h>
#include <DA1469xAB.h>
#include <da1469x_config.h>
#include <da1469x_trimv.h>
#include <da1469x_otp.h>

#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#define GROUP_ID_MAX            (MCU_TRIMV_GROUP_ID_MAX)

#define CS_OFFSET               (MCU_OTPM_CS_OFFSET)
#define CS_LENGTH               (MCU_OTPM_CS_LENGTH)

#define CS_WORD_START           0xa5a5a5a5
#define CS_WORD_END             0x00000000
#define CS_WORD_INVALID         0xffffffff
#define CS_WORD_TYPE_MASK       0xf0000000
#define CS_WORD_TYPE_BOOTER     0x60000000
#define CS_WORD_TYPE_TRIM       0x90000000

struct da1469x_trimv_group {
    uint8_t index;
    uint8_t num_words;
};

static struct da1469x_trimv_group g_mcu_trimv_groups[GROUP_ID_MAX + 1];

void
da1469x_trimv_is_reg_pairs_in_otp(const uint32_t *regs_buf, uint32_t num_entries, bool *status_buf)
{
    uint32_t offset_start;
    uint32_t offset_end;
    uint32_t offset;
    uint32_t ow;

    assert(regs_buf);
    assert(status_buf);

    /* Initialize the status buffer to indicate invalid entries */
    memset(status_buf, 0, num_entries);

    if (!num_entries) {
        return;
    }

    offset_start = CS_OFFSET;
    offset_end = CS_OFFSET + CS_LENGTH;
    offset = offset_start;

    da1469x_otp_read(offset, &ow, sizeof(ow));
    /* Check if there is a valid CS entry in OTP */
    if (ow != CS_WORD_START) {
        return;
    }

    offset += 4;

    /* Iterate the whole CS section  */
    while (offset < offset_end) {
        da1469x_otp_read(offset, &ow, sizeof(ow));

        offset += 4;

        /* Check if the end of the CS section has been reached */
        if (ow == CS_WORD_END || ow == CS_WORD_INVALID) {
            return;
        /* Check if the entry accommodates a TCS section and compute its size (num. of words) so it can be skipped */
        } else if ((ow & CS_WORD_TYPE_MASK) == CS_WORD_TYPE_TRIM) {
            offset += ((ow & 0x0000ff00) >> 8) << 2;
        /* Check if the entry accommodates a register-value pair and compare it with the register buffer provided */
        } else if (ow <= MEMCTRL_BASE + 0x100) {
            for (int i = 0 ; i < num_entries; i++) {
                if (ow == regs_buf[i]) {
                    status_buf[i] = true;
                    break;
                }
            }
            offset += 4; // Skip register's value
        }
    }
}

void
da1469x_trimv_init_from_otp(void)
{
    uint32_t offset_start;
    uint32_t offset_end;
    uint32_t offset;
    uint32_t ow;
    uint8_t trimv_group;
    uint8_t trimv_num_words;

    /* Clear groups if anything was previously loaded */
    memset(&g_mcu_trimv_groups, 0, sizeof(g_mcu_trimv_groups));

    /* Start of configuration script */
    offset_start = CS_OFFSET;
    offset_end = CS_OFFSET + CS_LENGTH;
    offset = offset_start;

    da1469x_otp_read(offset, &ow, sizeof(ow));
    if (ow != CS_WORD_START) {
        return;
    }

    offset += 4;

    while (offset < offset_end) {
        da1469x_otp_read(offset, &ow, sizeof(ow));

        offset += 4;

        if ((ow == CS_WORD_END) || (ow == CS_WORD_INVALID)) {
            /* End of CS or empty word */
            break;
        } else if ((ow & CS_WORD_TYPE_MASK) < CS_WORD_TYPE_BOOTER) {
            /* This is a register+value configuration, skip one more word */
            offset += 4;
        } else if ((ow & CS_WORD_TYPE_MASK) == CS_WORD_TYPE_TRIM) {
            trimv_num_words = (ow & 0x0000ff00) >> 8;
            trimv_group = ow & 0x000000ff;

            if (trimv_group <= GROUP_ID_MAX) {
                /*
                 * XXX not sure if each group can be present only once in OTP,
                 *     but our implementation requires it for now and it works
                 */
                assert(g_mcu_trimv_groups[trimv_group].num_words == 0);

                g_mcu_trimv_groups[trimv_group].index = (offset - offset_start) / 4;
                g_mcu_trimv_groups[trimv_group].num_words = trimv_num_words;
            }

            offset += trimv_num_words * 4;
        }
    }
}

uint8_t
da1469x_trimv_group_num_words_get(uint8_t group)
{
    struct da1469x_trimv_group *grp = &g_mcu_trimv_groups[group];

    if (group > GROUP_ID_MAX) {
        return 0;
    }

    return grp->num_words;
}

uint8_t
da1469x_trimv_group_read(uint8_t group, uint32_t *buf, uint8_t num_words)
{
    struct da1469x_trimv_group *grp = &g_mcu_trimv_groups[group];
    uint32_t offset;
    int rc;

    /* Silence warning if built without asserts */
    (void)rc;

    num_words = min(num_words, da1469x_trimv_group_num_words_get(group));

    if (!num_words) {
        return 0;
    }

    offset = CS_OFFSET + grp->index * 4;

    rc = da1469x_otp_read(offset, buf, num_words * 4);
    assert(rc == 0);

    return num_words;
}
