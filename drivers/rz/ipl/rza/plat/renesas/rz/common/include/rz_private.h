/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __RZ_PRIVATE_H__
#define __RZ_PRIVATE_H__

#include <common/bl_common.h>

/* plat_gic.c */
void plat_gic_driver_init(void);
void plat_gic_init(void);
void plat_gic_cpuif_enable(void);
void plat_gic_cpuif_disable(void);
void plat_gic_pcpu_init(void);

/* plat_security.c */
void plat_tzc400_setup(uintptr_t tzc_base);

/* plat_storage.c */
void rz_io_setup(void);

/* plat_image_load.c */
#if (APPLOAD == RZ_NOFIP)
void rza_load_fsp(void);
#endif /* (APPLOAD == RZ_NOFIP) */
void rza_print_descs(void);

#if RZ_TEST
void rz_run_tests(void);
#define RZ_RUN_TESTS() rz_run_tests()
#else
#define RZ_RUN_TESTS() /* dummy */
#endif /* RZ_FLASH_TEST */

typedef struct bl2_to_bl31_params_mem {
	entry_point_info_t bl32_ep_info;
	entry_point_info_t bl33_ep_info;
} bl2_to_bl31_params_mem_t;

#endif	/* __RZ_PRIVATE_H__ */
