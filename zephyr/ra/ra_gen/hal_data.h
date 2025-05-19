/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include "bsp_api.h"
#include "rm_touch.h"
FSP_HEADER

#define CTSU_WRITE_IRQn                                                        \
  (DT_IRQ_BY_NAME(DT_INST(0, renesas_ra_ctsu), ctsuwr, irq))
#define CTSU_READ_IRQn                                                         \
  (DT_IRQ_BY_NAME(DT_INST(0, renesas_ra_ctsu), ctsurd, irq))
#define CTSU_END_IRQn (DT_IRQ_BY_NAME(DT_INST(0, renesas_ra_ctsu), ctsufn, irq))

FSP_FOOTER
#endif /* HAL_DATA_H_ */
