/*
 * Copyright (c) 2015-2020, ARM Limited and Contributors. All rights reserved.
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <stdint.h>
#include <string.h>

#include <platform_def.h>
#include <common/debug.h>
#include <common/tbbr/cot_def.h>
#include "../../include/drivers/auth/auth_common.h"
#include <drivers/auth/auth_mod.h>
#include "../../include/drivers/auth/sblib/crypto_sblib.h"
#include <drivers/auth/img_parser_mod.h>
#include <plat/common/platform.h>

#define return_if_error(rc) \
	do { \
		if (rc != 0) { \
			return rc; \
		} \
	} while (0)

#define TBBR_COT_GETTER(id) __extension__ ({	\
	assert((id) < cot_desc_size);		\
	cot_desc_ptr[id];			\
})

static int cmp_auth_param_type_desc(const auth_param_type_desc_t *a,
		const auth_param_type_desc_t *b)
{
	if ((a->type == b->type) && (a->cookie == b->cookie)) {
		return 0;
	}
	return 1;
}

/*
 * This function obtains the requested authentication parameter data from the
 * information extracted from the parent image after its authentication.
 */
static int auth_get_param(const auth_param_type_desc_t *param_type_desc,
			  const auth_img_desc_t *img_desc,
			  void **param, unsigned int *len)
{
	int i;

	if (img_desc->authenticated_data == NULL)
		return 1;

	for (i = 0 ; i < COT_MAX_VERIFIED_PARAMS ; i++) {
		if (0 == cmp_auth_param_type_desc(param_type_desc,
				img_desc->authenticated_data[i].type_desc)) {
			*param = img_desc->authenticated_data[i].data.ptr;
			*len = img_desc->authenticated_data[i].data.len;
			return 0;
		}
	}

	return 1;
}

/*
 * Authenticate an image using Renesas SB-Lib
 *
 * This function implements 'AUTH_METHOD_SBLIB'. To authenticate an image using
 * this method, the image must contain:
 *
 *   - Data to calculate the hash from
 *     or
 *   - Data to be signed
 *
 * The parent image must contain:
 *
 *   - Key Certificate
 *   - Content Certificate
 *
 * Key certificate contains the signature and public key to verify itself,
 * and the hash value of the public key in the content certificate.
 * Content certificate contains the signature and public key to verify itself,
 * and an algorithm to authenticate an image. If the image is authenticated
 * by matching the hash, content certificate contains the hash of the image.
 * If the image is authenticated by digital signature, content certificate
 * signature is used to authenticate the certificate and image together.
 *
 * Renesas SB-Lib authenticates the key certificate, content certificate and
 * image together.
 *
 * Crypto Module is not used because it does not fit the SB-Lib interface.
 *
 * Return:
 *   0 = success, Otherwise = error
 */
static int auth_sblib(const auth_method_param_sblib_t *param,
             const auth_img_desc_t *img_desc,
             void *img, unsigned int img_len)
{
	const auth_img_desc_t *key_cert_desc, *content_cert_desc;
	void *data_ptr, *key_cert_ptr, *content_cert_ptr;
	unsigned int data_len, key_cert_len, content_cert_len;
	int rc = 0;

	/* Get the content certificate that is the parent of the image */
	content_cert_desc = img_desc->parent;
	rc = auth_get_param(param->key_cert, content_cert_desc,
			&content_cert_ptr, &content_cert_len);
	return_if_error(rc);

	/* Get the key certificate that is the parent of the content certificate */
	key_cert_desc = content_cert_desc->parent;
	rc = auth_get_param(param->content_cert, key_cert_desc,
			&key_cert_ptr, &key_cert_len);
	return_if_error(rc);

	/* Get the data to authenticate from the current image */
	rc = img_parser_get_auth_param(img_desc->img_type, param->data,
			img, img_len, &data_ptr, &data_len);
	return_if_error(rc);

	/* Ask Renesas SB-Lib to authenticate this image */
	rc = crypto_sblib_auth(data_ptr, data_len, key_cert_ptr, key_cert_len,
				content_cert_ptr, content_cert_len);

	return rc;
}

/*
 * Return the parent id in the output parameter '*parent_id'
 *
 * Return value:
 *   0 = Image has parent, 1 = Image has no parent or parent is authenticated
 */
int auth_mod_get_parent_id(unsigned int img_id, unsigned int *parent_id)
{
	const auth_img_desc_t *img_desc = NULL;

	assert(parent_id != NULL);
	/* Get the image descriptor */
	img_desc = TBBR_COT_GETTER(img_id);

	/* Check if the image has no parent (ROT) */
	if (img_desc->parent == NULL) {
		*parent_id = 0;
		return 1;
	}

	/* Check if the parent has already been authenticated */
	if (auth_img_flags[img_desc->parent->img_id] & IMG_FLAG_AUTHENTICATED) {
		*parent_id = 0;
		return 1;
	}

	*parent_id = img_desc->parent->img_id;
	return 0;
}

/*
 * Initialize the different modules in the authentication framework
 */
void auth_mod_init(void)
{
	/* Check we have a valid CoT registered */
	assert(cot_desc_ptr != NULL);

	/* Renesas SB-Lib */
	crypto_sblib_init();

	/* Image parser module */
	img_parser_init();
}

/*
 * Authenticate a certificate/image
 *
 * Return: 0 = success, Otherwise = error
 */
int auth_mod_verify_img(unsigned int img_id,
			void *img_ptr,
			unsigned int img_len)
{
	const auth_img_desc_t *img_desc = NULL;
	const auth_method_desc_t *auth_method = NULL;
	void *param_ptr;
	unsigned int param_len;
	int rc, i;

	/* Get the image descriptor from the chain of trust */
	img_desc = TBBR_COT_GETTER(img_id);

	/* Ask the parser to check the image integrity */
	rc = img_parser_check_integrity(img_desc->img_type, img_ptr, img_len);
	return_if_error(rc);

	/* Authenticate the image using the methods indicated in the image
	 * descriptor. */
	if (img_desc->img_auth_methods == NULL)
		return 1;
	for (i = 0 ; i < AUTH_METHOD_NUM ; i++) {
		auth_method = &img_desc->img_auth_methods[i];
		switch (auth_method->type) {
		case AUTH_METHOD_NONE:
			rc = 0;
			break;
		case AUTH_METHOD_SBLIB:
			rc = auth_sblib(&auth_method->param.sblib,
					img_desc, img_ptr, img_len);
			break;
		default:
			/* Unknown authentication method */
			rc = 1;
			break;
		}
		return_if_error(rc);
	}

	/* Extract the parameters indicated in the image descriptor to
	 * authenticate the children images. */
	if (img_desc->authenticated_data != NULL) {
		for (i = 0 ; i < COT_MAX_VERIFIED_PARAMS ; i++) {
			if (img_desc->authenticated_data[i].type_desc == NULL) {
				continue;
			}

			/* Get the parameter from the image parser module */
			rc = img_parser_get_auth_param(img_desc->img_type,
					img_desc->authenticated_data[i].type_desc,
					img_ptr, img_len, &param_ptr, &param_len);
			return_if_error(rc);

			/* Check parameter size */
			if (param_len > img_desc->authenticated_data[i].data.len) {
				return 1;
			}

			/* Copy the parameter for later use */
			memcpy((void *)img_desc->authenticated_data[i].data.ptr,
					(void *)param_ptr, param_len);
		}
	}

	/* Mark image as authenticated */
	auth_img_flags[img_desc->img_id] |= IMG_FLAG_AUTHENTICATED;

	return 0;
}
