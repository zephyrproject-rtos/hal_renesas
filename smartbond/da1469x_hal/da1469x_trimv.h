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

#ifndef __DA1469X_TRIMV_H_
#define __DA1469X_TRIMV_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Check if one or more register addresses are present in the CS section in OTP. The function will parse the whole CS section
 * and update a status buffer, provided by user, indicating whether the corresponding register addresses were found or not.
 *
 * @param regs_buf    Pointer to a bufer containing the register addresses that need to be exercised.
 * @param num_entries Number of register entries in regs_buf. The value should also match the entries of status_buf.
 * @param status_buf  Pointer to a buffer that will be updated by the function, indicating whether the corresponding
 *                    register address has been found or not.
 */
void da1469x_trimv_is_reg_pairs_in_otp(const uint32_t *regs_buf, uint32_t num_entries, bool *status_buf);

void da1469x_trimv_init_from_otp(void);

uint8_t da1469x_trimv_group_num_words_get(uint8_t group);

uint8_t da1469x_trimv_group_read(uint8_t group, uint32_t *buf, uint8_t length);

#ifdef __cplusplus
}
#endif

#endif /* __DA1469X_TRIMV_H_ */
