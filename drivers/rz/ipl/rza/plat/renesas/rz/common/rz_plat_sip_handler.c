/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>
#include <lib/mmio.h>
#include <common/runtime_svc.h>
#include <common/debug.h>
#include <smccc_helpers.h>
#include <arch_helpers.h>
#include <rzg2l_def.h>
#include <rz_sip_svc.h>

#define RZ_OTP_BASE_DEVID	(RZG2L_OTP_BASE + 0x1178)
#define RZ_OTP_BASE_CHIPID	(RZG2L_OTP_BASE + 0x1140)

static uintptr_t rz_otp_handler_devid(void *handle, u_register_t x1)
{
	uint32_t devid = mmio_read_32(RZ_OTP_BASE_DEVID);
	SMC_RET1(handle, devid);
}

static uintptr_t rz_otp_handler_chipid(void *handle, u_register_t x1, u_register_t flags)
{
	uint32_t chipid[4];

#if (PROTECTED_CHIPID == 1)
	uint32_t ns = is_caller_non_secure(flags);
	if (ns) {
		WARN("%s: Unauthorized service call from non-secure\n", __func__);
		SMC_RET1(handle, SMC_UNK);
	}
#endif

	chipid[0] = mmio_read_32(RZ_OTP_BASE_CHIPID + 0x0);
	chipid[1] = mmio_read_32(RZ_OTP_BASE_CHIPID + 0x4);
	chipid[2] = mmio_read_32(RZ_OTP_BASE_CHIPID + 0x8);
	chipid[3] = mmio_read_32(RZ_OTP_BASE_CHIPID + 0xC);

	SMC_RET4(handle, chipid[0], chipid[1], chipid[2], chipid[3]);
}

uintptr_t rz_plat_sip_handler(uint32_t smc_fid,
					u_register_t x1,
					u_register_t x2,
					u_register_t x3,
					u_register_t x4,
					void *cookie,
					void *handle,
					u_register_t flags)
{
	switch (smc_fid) {

		case RZ_SIP_SVC_GET_DEVID:
			return rz_otp_handler_devid(handle, x1);
		case RZ_SIP_SVC_GET_CHIPID:
			return rz_otp_handler_chipid(handle, x1, flags);
		default:
			WARN("%s: Unimplemented RZ SiP Service Call: 0x%x \n", __func__, smc_fid);
			SMC_RET1(handle, SMC_UNK);
	}
}
