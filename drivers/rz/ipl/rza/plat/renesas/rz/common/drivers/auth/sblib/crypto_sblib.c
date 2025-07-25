/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <assert.h>
#include <stddef.h>
#include <string.h>

#include <common/debug.h>
#include <drivers/auth/crypto_mod.h>
#include "../../../include/drivers/auth/sblib/crypto_sblib.h"

#include "sblib_api_private.h"

#define SECURE_BOOT_API_ADDR		(0x000007F00)

static sb_secure_boot_api_t secure_boot_api;

int crypto_sblib_auth(void *data_ptr, size_t len,
				const void *key_cert, unsigned int key_cert_len,
				const void *content_cert, unsigned int content_cert_len)
{
	sb_ret_t rc;

	assert(secure_boot_api != NULL);

	rc = secure_boot_api(key_cert, key_cert_len, content_cert,
						 content_cert_len, NULL);
	if(SB_RET_SUCCESS != rc)
		return CRYPTO_ERR_UNKNOWN;

	return CRYPTO_SUCCESS;
}

void crypto_sblib_init(void)
{
	secure_boot_api = (sb_secure_boot_api_t)SECURE_BOOT_API_ADDR;
}

