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

#include <stdbool.h>

#include <DA1469xAB.h>
#include <rand.h>
#include <shm.h>

int
cmac_rand_is_active(void)
{
    return g_cmac_shm.rand->cmr_active;
}

int
cmac_rand_is_full(void)
{
    int next;
    bool rc;

    next = cmac_rand_get_next();
    if (next == g_cmac_shm.rand->cmr_out) {
        rc = 1;
    } else {
        rc = 0;
    }
    return rc;
}

int
cmac_rand_get_next(void)
{
    int next;

    /* If active and not full, put event on queue to get random numbers */
    next = g_cmac_shm.rand->cmr_in + 1;
    if (next == g_cmac_shm.config->rand_size) {
        next = 0;
    }
    return next;
}

void
cmac_rand_fill(uint32_t *buf, int num_words)
{
    int next;

    /* XXX: if words is 0, is it possible we could get into a state
       where we are waiting for random numbers but M33 does not know it
       has to fill any? */

    /* NOTE: we already know the buffer is not full first time through */
    next = g_cmac_shm.rand->cmr_in;
    while (num_words) {
        g_cmac_shm.rand->cmr_buf[next] = buf[0];
        next = cmac_rand_get_next();
        g_cmac_shm.rand->cmr_in = next;
        next = cmac_rand_get_next();
        if (next == g_cmac_shm.rand->cmr_out) {
            break;
        }
        --num_words;
        ++buf;
    }
}
