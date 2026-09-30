/*
* Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CANFDG_CFG_H_
#define R_CANFDG_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define CANFDG_CFG_PARAM_CHECKING_ENABLE ((BSP_CFG_PARAM_CHECKING_ENABLE))

#define CANFDG_CFG_AFL_CH0_RULE_NUM (32)
#define CANFDG_CFG_AFL_CH1_RULE_NUM (0)

#define CANFDG_CFG_GLOBAL_ERROR_CH ((0U))

#define CANFDG_CFG_FD_PROTOCOL_EXCEPTION ((0))
#define CANFDG_CFG_GLOBAL_ERR_IPL ((2))
#define CANFDG_CFG_RX_FIFO_IPL ((2))
#define CANFDG_CFG_GLOBAL_ERR_SOURCES (0x3)
#define CANFDG_CFG_TX_PRIORITY ((R_CANFDG_GCFG_TPRI_Msk))
#define CANFDG_CFG_DLC_CHECK ((0))
#define CANFDG_CFG_FD_OVERFLOW ((0))
#define CANFDG_CFG_RXMB_NUMBER (0)
#define CANFDG_CFG_RXMB_SIZE ((0))
#define CANFDG_CFG_RXFIFO0_INT_THRESHOLD ((3U))
#define CANFDG_CFG_RXFIFO0_DEPTH ((3))
#define CANFDG_CFG_RXFIFO0_PAYLOAD ((0))
#define CANFDG_CFG_RXFIFO0_INT_MODE                                            \
  ((R_CANFDG_RFCR_RFIE_Msk | R_CANFDG_RFCR_RFIM_Msk))
#define CANFDG_CFG_RXFIFO0_ENABLE ((1))

#define CANFDG_CFG_RXFIFO1_INT_THRESHOLD ((3U))
#define CANFDG_CFG_RXFIFO1_DEPTH ((3))
#define CANFDG_CFG_RXFIFO1_PAYLOAD ((0))
#define CANFDG_CFG_RXFIFO1_INT_MODE                                            \
  ((R_CANFDG_RFCR_RFIE_Msk | R_CANFDG_RFCR_RFIM_Msk))
#define CANFDG_CFG_RXFIFO1_ENABLE ((0))

#define CANFDG_CFG_RXFIFO2_INT_THRESHOLD ((3U))
#define CANFDG_CFG_RXFIFO2_DEPTH ((3))
#define CANFDG_CFG_RXFIFO2_PAYLOAD ((0))
#define CANFDG_CFG_RXFIFO2_INT_MODE                                            \
  ((R_CANFDG_RFCR_RFIE_Msk | R_CANFDG_RFCR_RFIM_Msk))
#define CANFDG_CFG_RXFIFO2_ENABLE ((0))

#define CANFDG_CFG_RXFIFO3_INT_THRESHOLD ((3U))
#define CANFDG_CFG_RXFIFO3_DEPTH ((3))
#define CANFDG_CFG_RXFIFO3_PAYLOAD ((0))
#define CANFDG_CFG_RXFIFO3_INT_MODE                                            \
  ((R_CANFDG_RFCR_RFIE_Msk | R_CANFDG_RFCR_RFIM_Msk))
#define CANFDG_CFG_RXFIFO3_ENABLE ((0))

#define CANFDG_CFG_RXFIFO4_INT_THRESHOLD ((3U))
#define CANFDG_CFG_RXFIFO4_DEPTH ((3))
#define CANFDG_CFG_RXFIFO4_PAYLOAD ((0))
#define CANFDG_CFG_RXFIFO4_INT_MODE                                            \
  ((R_CANFDG_RFCR_RFIE_Msk | R_CANFDG_RFCR_RFIM_Msk))
#define CANFDG_CFG_RXFIFO4_ENABLE ((0))

#define CANFDG_CFG_RXFIFO5_INT_THRESHOLD ((3U))
#define CANFDG_CFG_RXFIFO5_DEPTH ((3))
#define CANFDG_CFG_RXFIFO5_PAYLOAD ((0))
#define CANFDG_CFG_RXFIFO5_INT_MODE                                            \
  ((R_CANFDG_RFCR_RFIE_Msk | R_CANFDG_RFCR_RFIM_Msk))
#define CANFDG_CFG_RXFIFO5_ENABLE ((0))

#define CANFDG_CFG_RXFIFO6_INT_THRESHOLD ((3U))
#define CANFDG_CFG_RXFIFO6_DEPTH ((3))
#define CANFDG_CFG_RXFIFO6_PAYLOAD ((0))
#define CANFDG_CFG_RXFIFO6_INT_MODE                                            \
  ((R_CANFDG_RFCR_RFIE_Msk | R_CANFDG_RFCR_RFIM_Msk))
#define CANFDG_CFG_RXFIFO6_ENABLE ((0))

#define CANFDG_CFG_RXFIFO7_INT_THRESHOLD ((3U))
#define CANFDG_CFG_RXFIFO7_DEPTH ((3))
#define CANFDG_CFG_RXFIFO7_PAYLOAD ((0))
#define CANFDG_CFG_RXFIFO7_INT_MODE                                            \
  ((R_CANFDG_RFCR_RFIE_Msk | R_CANFDG_RFCR_RFIM_Msk))
#define CANFDG_CFG_RXFIFO7_ENABLE ((0))

#define CANFDG_CFG_COMMONFIFO0                                                 \
  (((0) << R_CANFDG_CFCR_CFE_Pos) | ((0) << R_CANFDG_CFCR_CFRIE_Pos) |         \
   ((0) << R_CANFDG_CFCR_CFTIE_Pos) | ((0) << R_CANFDG_CFCR_PLS_Pos) |         \
   ((0) << R_CANFDG_CFCR_MODE_Pos) | ((0) << R_CANFDG_CFCR_ITCS_Pos) |         \
   ((0) << R_CANFDG_CFCR_ITR_Pos) | ((0) << R_CANFDG_CFCR_CFIM_Pos) |          \
   ((3U) << R_CANFDG_CFCR_CFITH_Pos) | ((0) << R_CANFDG_CFCR_LTM_Pos) |        \
   ((3) << R_CANFDG_CFCR_FDS_Pos) | (0 << R_CANFDG_CFCR_TINT_Pos))

#define CANFDG_CFG_COMMONFIFO1                                                 \
  (((0) << R_CANFDG_CFCR_CFE_Pos) | ((0) << R_CANFDG_CFCR_CFRIE_Pos) |         \
   ((0) << R_CANFDG_CFCR_CFTIE_Pos) | ((0) << R_CANFDG_CFCR_PLS_Pos) |         \
   ((0) << R_CANFDG_CFCR_MODE_Pos) | ((0) << R_CANFDG_CFCR_ITCS_Pos) |         \
   ((0) << R_CANFDG_CFCR_ITR_Pos) | ((0) << R_CANFDG_CFCR_CFIM_Pos) |          \
   ((3U) << R_CANFDG_CFCR_CFITH_Pos) | ((0) << R_CANFDG_CFCR_LTM_Pos) |        \
   ((3) << R_CANFDG_CFCR_FDS_Pos) | (0 << R_CANFDG_CFCR_TINT_Pos))

#define CANFDG_CFG_COMMONFIFO2                                                 \
  (((0) << R_CANFDG_CFCR_CFE_Pos) | ((0) << R_CANFDG_CFCR_CFRIE_Pos) |         \
   ((0) << R_CANFDG_CFCR_CFTIE_Pos) | ((0) << R_CANFDG_CFCR_PLS_Pos) |         \
   ((0) << R_CANFDG_CFCR_MODE_Pos) | ((0) << R_CANFDG_CFCR_ITCS_Pos) |         \
   ((0) << R_CANFDG_CFCR_ITR_Pos) | ((0) << R_CANFDG_CFCR_CFIM_Pos) |          \
   ((3U) << R_CANFDG_CFCR_CFITH_Pos) | ((0) << R_CANFDG_CFCR_LTM_Pos) |        \
   ((3) << R_CANFDG_CFCR_FDS_Pos) | (0 << R_CANFDG_CFCR_TINT_Pos))

#define CANFDG_CFG_COMMONFIFO3                                                 \
  (((0) << R_CANFDG_CFCR_CFE_Pos) | ((0) << R_CANFDG_CFCR_CFRIE_Pos) |         \
   ((0) << R_CANFDG_CFCR_CFTIE_Pos) | ((0) << R_CANFDG_CFCR_PLS_Pos) |         \
   ((0) << R_CANFDG_CFCR_MODE_Pos) | ((0) << R_CANFDG_CFCR_ITCS_Pos) |         \
   ((0) << R_CANFDG_CFCR_ITR_Pos) | ((0) << R_CANFDG_CFCR_CFIM_Pos) |          \
   ((3U) << R_CANFDG_CFCR_CFITH_Pos) | ((0) << R_CANFDG_CFCR_LTM_Pos) |        \
   ((3) << R_CANFDG_CFCR_FDS_Pos) | (0 << R_CANFDG_CFCR_TINT_Pos))

#define CANFDG_CFG_COMMONFIFO4                                                 \
  (((0) << R_CANFDG_CFCR_CFE_Pos) | ((0) << R_CANFDG_CFCR_CFRIE_Pos) |         \
   ((0) << R_CANFDG_CFCR_CFTIE_Pos) | ((0) << R_CANFDG_CFCR_PLS_Pos) |         \
   ((0) << R_CANFDG_CFCR_MODE_Pos) | ((0) << R_CANFDG_CFCR_ITCS_Pos) |         \
   ((0) << R_CANFDG_CFCR_ITR_Pos) | ((0) << R_CANFDG_CFCR_CFIM_Pos) |          \
   ((3U) << R_CANFDG_CFCR_CFITH_Pos) | ((0) << R_CANFDG_CFCR_LTM_Pos) |        \
   ((3) << R_CANFDG_CFCR_FDS_Pos) | (0 << R_CANFDG_CFCR_TINT_Pos))

#define CANFDG_CFG_COMMONFIFO5                                                 \
  (((0) << R_CANFDG_CFCR_CFE_Pos) | ((0) << R_CANFDG_CFCR_CFRIE_Pos) |         \
   ((0) << R_CANFDG_CFCR_CFTIE_Pos) | ((0) << R_CANFDG_CFCR_PLS_Pos) |         \
   ((0) << R_CANFDG_CFCR_MODE_Pos) | ((0) << R_CANFDG_CFCR_ITCS_Pos) |         \
   ((0) << R_CANFDG_CFCR_ITR_Pos) | ((0) << R_CANFDG_CFCR_CFIM_Pos) |          \
   ((3U) << R_CANFDG_CFCR_CFITH_Pos) | ((0) << R_CANFDG_CFCR_LTM_Pos) |        \
   ((3) << R_CANFDG_CFCR_FDS_Pos) | (0 << R_CANFDG_CFCR_TINT_Pos))

#define CANFDG_GROUP_IRQ DT_IRQ(DT_NODELABEL(group_irq_al2), irq)

/* Global interrupt */
#define CANFDG0_RFRI DT_IRQ_BY_NAME(DT_NODELABEL(canfdg_global), rfri, irq)
#define CANFDG0_GLEI DT_IRQ_BY_NAME(DT_NODELABEL(canfdg_global), glei, irq)

#define VECTOR_NUMBER_CANFDG0_RFRI                                             \
  ((IRQn_Type)(CANFDG0_RFRI << 8U | CANFDG_GROUP_IRQ))
#define VECTOR_NUMBER_CANFDG0_GLEI                                             \
  ((IRQn_Type)(CANFDG0_GLEI << 8U | CANFDG_GROUP_IRQ))
#ifdef __cplusplus
}
#endif
#endif /* R_CANFDG_CFG_H_ */
