/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <syc.h>

unsigned int plat_get_syscnt_freq2(void)
{
	return syc_get_freq();
}
