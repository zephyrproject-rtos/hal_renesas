/*
 * Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_LAYER3_SWITCH_CFG_H_
#define R_LAYER3_SWITCH_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define LAYER3_SWITCH_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)

#define LAYER3_SWITCH_GET_QUEUE_NUM(id, compat, prop)                                  \
		    COND_CODE_1(DT_NODE_HAS_COMPAT(id,compat),(DT_PROP(id,prop)),(0))

#define LAYER3_SWITCH_CFG_AVAILABLE_QUEUE_NUM                                          \
		    (DT_FOREACH_CHILD_SEP_VARGS(DT_NODELABEL(eswm), LAYER3_SWITCH_GET_QUEUE_NUM,   \
						(+), renesas_ra_ethernet_rmac, txq_num) +          \
		     DT_FOREACH_CHILD_SEP_VARGS(DT_NODELABEL(eswm), LAYER3_SWITCH_GET_QUEUE_NUM,   \
						(+), renesas_ra_ethernet_rmac, rxq_num))

#ifdef __cplusplus
}
#endif
#endif /* R_LAYER3_SWITCH_CFG_H_ */
