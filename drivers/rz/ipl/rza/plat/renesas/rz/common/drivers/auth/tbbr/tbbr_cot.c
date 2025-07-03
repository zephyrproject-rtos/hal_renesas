/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stddef.h>

#include <platform_def.h>
#include "../../../include/drivers/auth/auth_common.h"
#include <drivers/auth/auth_mod.h>
#if USE_TBBR_DEFS
#include <tools_share/tbbr_oid.h>
#else
#include <platform_oid.h>
#endif

#define KEY_CERT_LEN			(256)
#define CONTENT_CERT_LEN		(512)

#ifdef IMAGE_BL2

static unsigned char soc_fw_key_cert_buf[KEY_CERT_LEN];
static unsigned char soc_fw_content_cert_buf[CONTENT_CERT_LEN];

static unsigned char tos_fw_key_cert_buf[KEY_CERT_LEN];
static unsigned char tos_fw_content_cert_buf[CONTENT_CERT_LEN];

static unsigned char nt_fw_key_cert_buf[KEY_CERT_LEN];
static unsigned char nt_fw_content_cert_buf[CONTENT_CERT_LEN];


static auth_param_type_desc_t key_cert = AUTH_PARAM_TYPE_DESC(
		AUTH_PARAM_RAW_DATA, 0);
static auth_param_type_desc_t content_cert = AUTH_PARAM_TYPE_DESC(
		AUTH_PARAM_RAW_DATA, 0);
static auth_param_type_desc_t raw_data = AUTH_PARAM_TYPE_DESC(
		AUTH_PARAM_RAW_DATA, 0);

/*
 * SoC Firmware
 */
static const auth_img_desc_t soc_fw_key_cert = {
	.img_id = SOC_FW_KEY_CERT_ID,
	.img_type = IMG_PLAT,
	.parent = NULL,
	.img_auth_methods = (const auth_method_desc_t[AUTH_METHOD_NUM]) {
		[0] = {
			.type = AUTH_METHOD_NONE
		},
	},
	.authenticated_data = (const auth_param_desc_t[COT_MAX_VERIFIED_PARAMS]) {
		[0] = {
			.type_desc = &key_cert,
			.data = {
				.ptr = (void *)soc_fw_key_cert_buf,
				.len = (unsigned int)KEY_CERT_LEN
			}
		}
	}
};

static const auth_img_desc_t soc_fw_content_cert = {
	.img_id = SOC_FW_CONTENT_CERT_ID,
	.img_type = IMG_PLAT,
	.parent = &soc_fw_key_cert,
	.img_auth_methods = (const auth_method_desc_t[AUTH_METHOD_NUM]) {
		[0] = {
			.type = AUTH_METHOD_NONE
		},
	},
	.authenticated_data = (const auth_param_desc_t[COT_MAX_VERIFIED_PARAMS]) {
		[0] = {
			.type_desc = &content_cert,
			.data = {
				.ptr = (void *)soc_fw_content_cert_buf,
				.len = (unsigned int)CONTENT_CERT_LEN
			}
		}
	}
};

/*
 * BL31
 */
static const auth_img_desc_t bl31_image = {
	.img_id = BL31_IMAGE_ID,
	.img_type = IMG_RAW,
	.parent = &soc_fw_content_cert,
	.img_auth_methods = (const auth_method_desc_t[AUTH_METHOD_NUM]) {
		[0] = {
			.type = AUTH_METHOD_SBLIB,
			.param.sblib = {
				.data = &raw_data,
				.key_cert = &key_cert,
				.content_cert = &content_cert
			}
		}
	}
};

/*
 * Trusted OS Firmware
 */
static const auth_img_desc_t trusted_os_fw_key_cert = {
	.img_id = TRUSTED_OS_FW_KEY_CERT_ID,
	.img_type = IMG_PLAT,
	.parent = NULL,
	.img_auth_methods = (const auth_method_desc_t[AUTH_METHOD_NUM]) {
		[0] = {
			.type = AUTH_METHOD_NONE
		},
	},
	.authenticated_data = (const auth_param_desc_t[COT_MAX_VERIFIED_PARAMS]) {
		[0] = {
			.type_desc = &key_cert,
			.data = {
				.ptr = (void *)tos_fw_key_cert_buf,
				.len = (unsigned int)KEY_CERT_LEN
			}
		}
	}
};

static const auth_img_desc_t trusted_os_fw_content_cert = {
	.img_id = TRUSTED_OS_FW_CONTENT_CERT_ID,
	.img_type = IMG_PLAT,
	.parent = &trusted_os_fw_key_cert,
	.img_auth_methods = (const auth_method_desc_t[AUTH_METHOD_NUM]) {
		[0] = {
			.type = AUTH_METHOD_NONE
		},
	},
	.authenticated_data = (const auth_param_desc_t[COT_MAX_VERIFIED_PARAMS]) {
		[0] = {
			.type_desc = &content_cert,
			.data = {
				.ptr = (void *)tos_fw_content_cert_buf,
				.len = (unsigned int)CONTENT_CERT_LEN
			}
		}
	}
};

/*
 * BL32
 */
static const auth_img_desc_t bl32_image = {
	.img_id = BL32_IMAGE_ID,
	.img_type = IMG_RAW,
	.parent = &trusted_os_fw_content_cert,
	.img_auth_methods = (const auth_method_desc_t[AUTH_METHOD_NUM]) {
		[0] = {
			.type = AUTH_METHOD_SBLIB,
			.param.sblib = {
				.data = &raw_data,
				.key_cert = &key_cert,
				.content_cert = &content_cert
			}
		}
	}
};

/*
 * Non-Trusted Firmware
 */
static const auth_img_desc_t non_trusted_fw_key_cert = {
	.img_id = NON_TRUSTED_FW_KEY_CERT_ID,
	.img_type = IMG_PLAT,
	.parent = NULL,
	.img_auth_methods = (const auth_method_desc_t[AUTH_METHOD_NUM]) {
		[0] = {
			.type = AUTH_METHOD_NONE
		},
	},
	.authenticated_data = (const auth_param_desc_t[COT_MAX_VERIFIED_PARAMS]) {
		[0] = {
			.type_desc = &key_cert,
			.data = {
				.ptr = (void *)nt_fw_key_cert_buf,
				.len = (unsigned int)KEY_CERT_LEN
			}
		}
	}
};

static const auth_img_desc_t non_trusted_fw_content_cert = {
	.img_id = NON_TRUSTED_FW_CONTENT_CERT_ID,
	.img_type = IMG_PLAT,
	.parent = &non_trusted_fw_key_cert,
	.img_auth_methods = (const auth_method_desc_t[AUTH_METHOD_NUM]) {
		[0] = {
			.type = AUTH_METHOD_NONE
		},
	},
	.authenticated_data = (const auth_param_desc_t[COT_MAX_VERIFIED_PARAMS]) {
		[0] = {
			.type_desc = &content_cert,
			.data = {
				.ptr = (void *)nt_fw_content_cert_buf,
				.len = (unsigned int)CONTENT_CERT_LEN
			}
		}
	}
};

/*
 * BL33
 */
static const auth_img_desc_t bl33_image = {
	.img_id = BL33_IMAGE_ID,
	.img_type = IMG_RAW,
	.parent = &non_trusted_fw_content_cert,
	.img_auth_methods = (const auth_method_desc_t[AUTH_METHOD_NUM]) {
		[0] = {
			.type = AUTH_METHOD_SBLIB,
			.param.sblib = {
				.data = &raw_data,
				.key_cert = &key_cert,
				.content_cert = &content_cert
			}
		}
	}
};

static const auth_img_desc_t * const cot_desc[] = {
	[SOC_FW_KEY_CERT_ID]				=	&soc_fw_key_cert,
	[SOC_FW_CONTENT_CERT_ID]			=	&soc_fw_content_cert,
	[BL31_IMAGE_ID]						=	&bl31_image,
	[TRUSTED_OS_FW_KEY_CERT_ID]			=	&trusted_os_fw_key_cert,
	[TRUSTED_OS_FW_CONTENT_CERT_ID]		=	&trusted_os_fw_content_cert,
	[BL32_IMAGE_ID]						=	&bl32_image,
	[NON_TRUSTED_FW_KEY_CERT_ID]		=	&non_trusted_fw_key_cert,
	[NON_TRUSTED_FW_CONTENT_CERT_ID]	=	&non_trusted_fw_content_cert,
	[BL33_IMAGE_ID]						=	&bl33_image,
};

/* Register the CoT in the authentication module */
REGISTER_COT(cot_desc);

#endif /* IMAGE_BL2 */
