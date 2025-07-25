/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <common/debug.h>
#include "../../../include/drivers/auth/auth_common.h"
#include <drivers/auth/img_parser_mod.h>
#include <lib/utils_def.h>

#include "sblib_api_private.h"

#define LIB_NAME	"Renesas SB-Lib"

#define KEY_CERT_HEADER_MAGIC_NUMBER		(0x6b657963)
#define CONTENT_CERT_HEADER_MAGIC_NUMBER	(0x636f6463)

/*
 * Clear all static temporary variables.
 */
static void clear_temp_vars(void)
{
#define ZERO_AND_CLEAN(x)					\
	do {							\
		zeromem(&x, sizeof(x));				\
		clean_dcache_range((uintptr_t)&x, sizeof(x));	\
	} while (0);

#undef ZERO_AND_CLEAN
}

static int key_cert_parse(void *img, unsigned int img_len)
{
	return IMG_PARSER_OK;
}

static int content_cert_parse(void *img, unsigned int img_len)
{
	return IMG_PARSER_OK;
}

/* Exported functions */

static void init(void)
{
	/* Do Nothing */
}

/*
 * Wrapper for cert_parse() that clears the static variables used by it in case
 * of an error.
 */
static int check_integrity(void *img, unsigned int img_len)
{
	int rc;
	uint32_t magic;

	if(SB_MANIFEST_LEN_MIN > img_len)
		return IMG_PARSER_ERR_FORMAT;

	magic = *(uint32_t *)img;

	switch(magic)
	{
		case KEY_CERT_HEADER_MAGIC_NUMBER:
			rc = key_cert_parse(img, img_len);
			break;
		case CONTENT_CERT_HEADER_MAGIC_NUMBER:
			rc = content_cert_parse(img, img_len);
			break;
		default:
			rc = IMG_PARSER_ERR_FORMAT;
			break;
	}

	if (rc != IMG_PARSER_OK)
		clear_temp_vars();

	return rc;
}

/*
 * Extract an authentication parameter from an SBLib Manifest
 */
static int get_auth_param(const auth_param_type_desc_t *type_desc,
		void *img, unsigned int img_len,
		void **param, unsigned int *param_len)
{
	int rc = IMG_PARSER_OK;

	switch (type_desc->type) {
	case AUTH_PARAM_RAW_DATA:
		*param = (void *)img;
		*param_len = (unsigned int)img_len;
		break;
	default:
		rc = IMG_PARSER_ERR_NOT_FOUND;
		break;
	}

	return rc;
}

REGISTER_IMG_PARSER_LIB(IMG_PLAT, LIB_NAME, init, \
			   check_integrity, get_auth_param);
