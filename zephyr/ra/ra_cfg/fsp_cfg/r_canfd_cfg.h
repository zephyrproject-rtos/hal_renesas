/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CANFD_CFG_H_
#define R_CANFD_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define CANFD_CFG_PARAM_CHECKING_ENABLE ((BSP_CFG_PARAM_CHECKING_ENABLE))

#define CANFD_CFG_AFL_CH0_RULE_NUM  (DT_PROP_OR(DT_NODELABEL(canfd0), rx_max_filters, 0))
#define CANFD_CFG_AFL_CH1_RULE_NUM  (DT_PROP_OR(DT_NODELABEL(canfd1), rx_max_filters, 0))

#define CANFD_CFG_GLOBAL_ERROR_CH   (DT_PROP(DT_INST(0, renesas_ra_canfd), channel))

#define CANFD_CFG_FD_PROTOCOL_EXCEPTION (0)

#define VECTOR_NUMBER_CAN_GLERR     DT_IRQ_BY_NAME(DT_COMPAT_GET_ANY_STATUS_OKAY(renesas_ra_canfd_global), glerr, irq)
#define CANFD_CFG_GLOBAL_ERR_IPL    DT_IRQ_BY_NAME(DT_COMPAT_GET_ANY_STATUS_OKAY(renesas_ra_canfd_global), glerr, priority)
#define VECTOR_NUMBER_CAN_RXF       DT_IRQ_BY_NAME(DT_COMPAT_GET_ANY_STATUS_OKAY(renesas_ra_canfd_global), rxf, irq)
#define CANFD_CFG_RX_FIFO_IPL       DT_IRQ_BY_NAME(DT_COMPAT_GET_ANY_STATUS_OKAY(renesas_ra_canfd_global), rxf, priority)

#ifdef __cplusplus
}
#endif
#endif /* R_CANFD_CFG_H_ */
