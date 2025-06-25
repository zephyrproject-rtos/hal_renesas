/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>
#include <common/runtime_svc.h>
#include <common/debug.h>
#include <smccc_helpers.h>
#include <arch_helpers.h>
#include <rz_sip_svc.h>

#pragma weak rz_plat_sip_handler

uintptr_t rz_plat_sip_handler(uint32_t smc_fid,
					u_register_t x1,
					u_register_t x2,
					u_register_t x3,
					u_register_t x4,
					void *cookie,
					void *handle,
					u_register_t flags)
{
	WARN("%s: Unimplemented RZ SiP Service Call: 0x%x \n", __func__, smc_fid);
	SMC_RET1(handle, SMC_UNK);
}

/*
 * This function handles RZ defined SiP Calls
 */
static uintptr_t rz_sip_handler(unsigned int smc_fid,
			u_register_t x1,
			u_register_t x2,
			u_register_t x3,
			u_register_t x4,
			void *cookie,
			void *handle,
			u_register_t flags)
{
	return rz_plat_sip_handler(smc_fid, x1, x2, x3, x4, cookie, handle, flags);
}


/* Define a runtime service descriptor for fast SMC calls */
DECLARE_RT_SVC(
	rz_sip_svc,
	OEN_SIP_START,
	OEN_SIP_END,
	SMC_TYPE_FAST,
	NULL,
	rz_sip_handler
);
