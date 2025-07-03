/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CRYPTO_SBLIB_H
#define CRYPTO_SBLIB_H

void crypto_sblib_init(void);

int crypto_sblib_auth(void *data_ptr, size_t len, 
				const void *key_cert, unsigned int key_cert_len,
				const void *content_cert, unsigned int content_cert_len);

#endif /* CRYPTO_SBLIB_H */

