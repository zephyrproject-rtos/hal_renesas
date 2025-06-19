/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _RZA_PRINTF_H_
#define _RZA_PRINTF_H_

#include <stdio.h>

/* This header file defines printf that outputs logs with RZ/A3UL. */

#define RZ_UNUSED_PARAM(param)	(void)(param)
#define STRING(str)		#str

#if (RZA3 == 1)
#if (DEBUG == 1)
#define RZA_PRINTF_VERBOSE(...)	printf(__VA_ARGS__)
#else
#define RZA_PRINTF_VERBOSE(...)
#endif /* DEBUG == 1 */

#define RZA_PRINTF(...)		printf(__VA_ARGS__)
#define RZA_PRINTF_NOTICE(...)	RZA_PRINTF_VERBOSE(__VA_ARGS__)
#define RZA_PRINTF_ERROR(...)	RZA_PRINTF_VERBOSE(__VA_ARGS__)
#define RZA_PRINTF_WARN(...)	RZA_PRINTF_VERBOSE(__VA_ARGS__)
#define RZA_PRINTF_INFO(...)	RZA_PRINTF_VERBOSE(__VA_ARGS__)
#else

#define RZA_PRINTF_VERBOSE(...)
#define RZA_PRINTF(...)
#define RZA_PRINTF_NOTICE(...)	NOTICE(__VA_ARGS__)
#define RZA_PRINTF_ERROR(...)	ERROR(__VA_ARGS__)
#define RZA_PRINTF_WARN(...)	WARN(__VA_ARGS__)
#define RZA_PRINTF_INFO(...)	INFO(__VA_ARGS__)

#endif /* RZA3 == 1 */

#endif  /* _RZA_PRINTF_H_ */
