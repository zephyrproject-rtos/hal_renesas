/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <common/desc_image_load.h>
#include <plat/common/platform.h>
#include <rzg2l_def.h>

#if (RZG2L_BL33_EXECUTION_EL == 0)
#define BL33_MODE MODE_EL1
#else
#define BL33_MODE MODE_EL2
#endif

static bl_mem_params_node_t bl2_mem_params_descs[] = {
#if (APPLOAD == RZ_NOFIP)
	{
		.image_id = MAX_IMAGE_IDS,

		SET_STATIC_PARAM_HEAD(ep_info, PARAM_EP, VERSION_2,
			entry_point_info_t, SECURE | EXECUTABLE | EP_FIRST_EXE),
		.ep_info.spsr = SPSR_64(MODE_EL3,
			MODE_SP_ELX, DISABLE_ALL_EXCEPTIONS),
		.ep_info.pc = BSP_BASE,
		.ep_info.args.arg0 = (uintptr_t)PARAMS_BASE,

		SET_STATIC_PARAM_HEAD(image_info, PARAM_EP, VERSION_2,
			image_info_t, IMAGE_ATTRIB_PLAT_SETUP | IMAGE_ATTRIB_SKIP_LOADING),

		.next_handoff_image_id = INVALID_IMAGE_ID,
	}
#else
	{
#if RZA3
		.image_id = BL31_IMAGE_ID,

		SET_STATIC_PARAM_HEAD(ep_info, PARAM_EP, VERSION_2,
			entry_point_info_t, SECURE | EXECUTABLE | EP_FIRST_EXE),
		.ep_info.spsr = SPSR_64(MODE_EL3,
			MODE_SP_ELX, DISABLE_ALL_EXCEPTIONS),
		.ep_info.pc = BSP_BASE,
		.ep_info.args.arg0 = (uintptr_t)PARAMS_BASE,

		SET_STATIC_PARAM_HEAD(image_info, PARAM_EP, VERSION_2,
			image_info_t, IMAGE_ATTRIB_PLAT_SETUP | IMAGE_ATTRIB_SKIP_LOADING),
		.image_info.image_max_size = BSP_LIMIT - BSP_BASE,
		.image_info.image_base = BSP_BASE,

		.next_handoff_image_id = INVALID_IMAGE_ID,
#else
		.image_id = BL31_IMAGE_ID,

		SET_STATIC_PARAM_HEAD(ep_info, PARAM_EP, VERSION_2,
			entry_point_info_t, SECURE | EXECUTABLE | EP_FIRST_EXE),
		.ep_info.spsr = SPSR_64(MODE_EL3,
			MODE_SP_ELX, DISABLE_ALL_EXCEPTIONS),
		.ep_info.pc = BL31_BASE,
		.ep_info.args.arg0 = (uintptr_t)PARAMS_BASE,

		SET_STATIC_PARAM_HEAD(image_info, PARAM_EP, VERSION_2,
			image_info_t, IMAGE_ATTRIB_PLAT_SETUP),
		.image_info.image_max_size = BL31_LIMIT - BL31_BASE,
		.image_info.image_base = BL31_BASE,
	

# ifdef BL32_BASE
		.next_handoff_image_id = BL32_IMAGE_ID,
# else
		.next_handoff_image_id = BL33_IMAGE_ID,
# endif /* BL32_BASE */
	},
# ifdef BL32_BASE
	{
		.image_id = BL32_IMAGE_ID,

		SET_STATIC_PARAM_HEAD(ep_info, PARAM_EP, VERSION_2,
			entry_point_info_t, SECURE | EXECUTABLE),
		.ep_info.pc = BL32_BASE,
		.ep_info.spsr = 0,

		SET_STATIC_PARAM_HEAD(image_info, PARAM_EP, VERSION_2,
			image_info_t, 0),
		.image_info.image_max_size = BL32_LIMIT - BL32_BASE,
		.image_info.image_base = BL32_BASE,

		.next_handoff_image_id = BL33_IMAGE_ID,
	},
# endif /* BL32_BASE */
	{
		.image_id = BL33_IMAGE_ID,

		SET_STATIC_PARAM_HEAD(ep_info, PARAM_EP, VERSION_2,
			entry_point_info_t, NON_SECURE | EXECUTABLE),
		.ep_info.spsr = SPSR_64(BL33_MODE, MODE_SP_ELX,
			DISABLE_ALL_EXCEPTIONS),
		.ep_info.pc = BL33_BASE,

		SET_STATIC_PARAM_HEAD(image_info, PARAM_EP, VERSION_2,
			image_info_t, 0),
		.image_info.image_max_size =
				(uint32_t) (BL33_LIMIT - BL33_BASE),
		.image_info.image_base = BL33_BASE,

		.next_handoff_image_id = INVALID_IMAGE_ID,
#endif /* RZA3 */
	}
#endif /* (APPLOAD == RZ_NOFIP) */
};

REGISTER_BL_IMAGE_DESCS(bl2_mem_params_descs)
