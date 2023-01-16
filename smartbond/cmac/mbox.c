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

#include <stdint.h>
#include <string.h>
#include <DA1469xAB.h>
#include <shm.h>
#include <mbox.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

static struct cmac_shm_mbox *
mbox_src_get(uint16_t *size)
{
    *size = g_cmac_shm.config->mbox_c2s_size;

    return g_cmac_shm.mbox_c2s;
}

static struct cmac_shm_mbox *
mbox_dst_get(uint16_t *size)
{
    *size = g_cmac_shm.config->mbox_s2c_size;

    return g_cmac_shm.mbox_s2c;
}

int
cmac_mbox_has_data(void)
{
    volatile struct cmac_shm_mbox *mbox;
    uint16_t mbox_size;

    mbox = mbox_src_get(&mbox_size);

    return mbox->rd_off != mbox->wr_off;
}

int
cmac_mbox_read(void *data, uint16_t len)
{
	volatile struct cmac_shm_mbox *mbox;
	uint16_t mbox_size;
	uint8_t *mbox_buf;
	uint16_t rd_off;
	uint16_t wr_off;
	uint16_t chunk_len;
	uint16_t rem_len;

	mbox = mbox_src_get(&mbox_size);
	/* no need for volatile on data buffer */
	mbox_buf = (void *)mbox->data;

	rem_len = len;

	do {
		rd_off = mbox->rd_off;
		wr_off = mbox->wr_off;

		if (rd_off <= wr_off) {
			chunk_len = wr_off - rd_off;
		} else {
			chunk_len = mbox_size - rd_off;
		}

		chunk_len = min(chunk_len, rem_len);

		memcpy(data, &mbox_buf[rd_off], chunk_len);

		data = (uint8_t *)data + chunk_len;
		rem_len -= chunk_len;
		rd_off += chunk_len;

		mbox->rd_off = rd_off == mbox_size ? 0 : rd_off;
	} while ((mbox->rd_off != mbox->wr_off) && (rem_len > 0));

	return len - rem_len;
}

int
cmac_mbox_write(const void *data, uint16_t len)
{
    volatile struct cmac_shm_mbox *mbox;
    uint16_t mbox_size;
    uint8_t *mbox_buf;
    uint16_t rd_off;
    uint16_t wr_off;
    uint16_t max_wr;
    uint16_t chunk;

    mbox = mbox_dst_get(&mbox_size);
    /* no need for volatile on data buffer */
    mbox_buf = (void *)mbox->data;

    while (len) {
        rd_off = mbox->rd_off;
        wr_off = mbox->wr_off;

        /*
         * Calculate maximum length to write, i.e. up to end of buffer or stop
         * before rd_off to be able to detect full queue.
         */
        if (rd_off > wr_off) {
            /*
             * |0|1|2|3|4|5|6|7|
             * | | | |W| | |R| |
             *        `---^
             */
            max_wr = rd_off - wr_off - 1;
        } else if (rd_off == 0) {
            /*
             * |0|1|2|3|4|5|6|7|
             * |R| | |W| | | | |
             *        `-------^
             */
            max_wr = mbox_size - wr_off - 1;
        } else {
            /*
             * |0|1|2|3|4|5|6|7|
             * | |R| |W| | | | |
             *        `---------^
             */
            max_wr = mbox_size - wr_off;
        }

        chunk = min(len, max_wr);

        if (chunk == 0) {
            continue;
        }

        memcpy(&mbox_buf[wr_off], data, chunk);

        wr_off += chunk;
        mbox->wr_off = wr_off == mbox_size ? 0 : wr_off;

	    cmac_signal();

        len -= chunk;
        data = (uint8_t *)data + chunk;
    }

    return 0;
}
