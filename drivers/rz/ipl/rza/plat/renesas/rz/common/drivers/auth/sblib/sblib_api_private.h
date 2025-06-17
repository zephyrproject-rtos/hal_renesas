/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!*****************************************************************************
* \file             : sblib_api_private.h
* \par version      : 1.00
* \par Product Name : Renesas-SB-Lib
* \par Device(s)    : Does not depend on specific hardware
* \par Description  : This file defines the public macros, types and
*                   : declarations in used the SB-Lib.
*******************************************************************************/

#ifndef SBLIB_API_PRIVATE_H
#define SBLIB_API_PRIVATE_H

/** SB-Lib return value definition */
/**\addtogroup group_return_code Return code */
/*! \{*/

/** API succeeded */
#define SB_RET_SUCCESS							((sb_ret_t)0x55555555UL)

/** An image of the same version as the current version is input
	(verification completed successfully) */
#define SB_RET_SAME_IMAGE_VERSION				((sb_ret_t)0x55005501UL)

/** A internal failure */
#define SB_RET_ERR_INTERNAL_FAIL				((sb_ret_t)0xAAAA0000UL)

/** An invalid argument was entered */
#define SB_RET_ERR_INVALID_ARG					((sb_ret_t)0xAAAA0001UL)

/** Unsupported function executed */
#define SB_RET_ERR_UNSUPPORTED_FUNCTION			((sb_ret_t)0xAAAA0002UL)

/** Data entered with incorrect alignment */
#define SB_RET_ERR_INVALID_ALIGNMENT			((sb_ret_t)0xAAAA0003UL)

/** An invalid magic number is set */
#define SB_RET_ERR_MANI_INVALID_MAGIC			((sb_ret_t)0xAAAA0100UL)

/** Unsupported version is set */
#define SB_RET_ERR_MANI_UNSUPPORTED_VERSION		((sb_ret_t)0xAAAA0101UL)

/** Out of range TLV Length is set */
#define SB_RET_ERR_MANI_OUT_OF_RANGE_LEN		((sb_ret_t)0xAAAA0102UL)

/** Missing required TLV field */
#define SB_RET_ERR_MANI_TLV_FIELD_ERR			((sb_ret_t)0xAAAA0103UL)

/** The length exceeding the end of the manifest is specified in Length
	of the TLV field */
#define SB_RET_ERR_MANI_TLV_INVALID_LEN			((sb_ret_t)0xAAAA0104UL)

/** An invalid image length is set */
#define SB_RET_ERR_MANI_INVALID_IMAGE_LEN		((sb_ret_t)0xAAAA0105UL)

/** There is a wrong combination of signature algorithms */
#define SB_RET_ERR_MANI_MISMATCH_SIGN_ALGORITHM ((sb_ret_t)0xAAAA0106UL)

/** An algorithm was specified that the manifest does not support */
#define SB_RET_ERR_MANI_UNSUPPORTED_ALGORITHM	((sb_ret_t)0xAAAA0107UL)

/** Cryptographic processing failure */
#define SB_RET_ERR_CRYPTO_FAIL					((sb_ret_t)0xAAAA0200UL)

/** Verification failed */
#define SB_RET_ERR_CRYPTO_AUTH_FAIL				((sb_ret_t)0xAAAA0201UL)

/** Unsupported algorithm */
#define SB_RET_ERR_CRYPTO_UNSUPPORTED_ALGORITHM ((sb_ret_t)0xAAAA0202UL)

/** Other resorece is using CryptoIP. */
#define SB_RET_ERR_CRYPTO_RESOURCE_CONFLICT		((sb_ret_t)0xAAAA0203UL)

/** Parameter error */
#define SB_RET_ERR_CRYPTO_PARAM_ERR				((sb_ret_t)0xAAAA0204UL)

/** CRC mismatch */
#define SB_RET_ERR_CRC_MISMATCH					((sb_ret_t)0xAAAA0300UL)

/** Unsupported polynominal */
#define SB_RET_ERR_CRC_UNSUPPORTED_POLYNOMIAL	((sb_ret_t)0xAAAA0301UL)

/** Image version lower than the current image version is installed */
#define SB_RET_ERR_LOWER_IMAGE_VERSION			((sb_ret_t)0xAAAA0400UL)

/*! \}*/

/** Manifest size definition */
/**\addtogroup group_manifest_size Manifest size */
/*! \{*/
#define SB_MANIFEST_LEN_MIN	  (36UL)	  /**< Minimum manifest length */
#define SB_MANIFEST_LEN_MAX	  (10240UL)	  /**< Maximum manifest length */
/*! \}*/

/** Reserved WORD size definition */
/**\addtogroup group_unused_area Reserved WORD size */
/*! \{*/

/** Key Certificate header reserved WORD size */
#define SB_KEY_CERT_RESERVED_WORD_SIZE	 (5U)

/*! \}*/

/** SB-Lib return type */
typedef uint32_t sb_ret_t;

/** SB-Lib Secure Boot API pointer type */
typedef sb_ret_t (* sb_secure_boot_api_t)(
				const uint8_t* const p_key_cert,
				const uint32_t key_cert_len_max,
				const uint8_t* const p_code_cert,
				const uint32_t code_cert_len_max,
				const uint8_t* const p_mac_tlv);

/*!*********************************************************
 * \addtogroup	SBLIBManifestTypes
 * \{*******************************************************/
/** Key Certificate header structure */
typedef struct
{
	/** Magic number unique to KeyCertificate */
	uint32_t	magic;

	/** Manifest version */
	uint32_t	manifest_version;

	/** KeyCertificate flag (Unused in V.1.00) */
	uint32_t	flags;

	/** Unused area */
	uint32_t	reserved[SB_KEY_CERT_RESERVED_WORD_SIZE];
} st_sb_key_cert_header_t;

/** Code Certificate header structure */
typedef struct
{
	/** Magic number unique to CodeCertificate */
	uint32_t	magic;

	/** Manifest version */
	uint32_t	manifest_version;

	/** CodeCertificate flag */
	uint32_t	flags;

	/** Image storage address */
	uint32_t	load_addr;

	/** Image expansion destination address */
	uint32_t	dest_addr;

	/** Image byte size */
	uint32_t	img_len;

	/** Image version */
	uint32_t	img_version;

	/** Image build number */
	uint32_t	build_num;
} st_sb_code_cert_header_t;
/*! \}*/

#endif /* SBLIB_API_PRIVATE_H */
