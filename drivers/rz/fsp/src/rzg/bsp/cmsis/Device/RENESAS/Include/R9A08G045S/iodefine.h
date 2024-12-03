/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : iodefine.h
 * Version      : 1.00
 * Description  : iodefine header
 *********************************************************************************************************************/

#ifndef __IODEFINE_HEADER__
#define __IODEFINE_HEADER__

#include "iodefines/adc_c_iodefine.h"
#include "iodefines/canfd_iodefine.h"
#include "iodefines/cpg_iodefine.h"
#include "iodefines/dmac_b_iodefine.h"
#include "iodefines/gpio_iodefine.h"
#include "iodefines/gpt_iodefine.h"
#include "iodefines/gtm_iodefine.h"
#include "iodefines/intc_im33_iodefine.h"
#include "iodefines/mhu_iodefine.h"
#include "iodefines/poeg_iodefine.h"
#include "iodefines/riic_iodefine.h"
#include "iodefines/rspi_iodefine.h"
#include "iodefines/scifa_iodefine.h"
#include "iodefines/ssi_iodefine.h"
#include "iodefines/sysc_iodefine.h"
#include "iodefines/tsu_iodefine.h"
#include "iodefines/tzc_iodefine.h"
#include "iodefines/wdt_iodefine.h"
#include "iodefines/xspi_iodefine.h"

#ifdef BSP_OVERRIDE_REG_HEADER_IOPORT
 #include BSP_OVERRIDE_REG_HEADER_IOPORT
#endif

#endif                                 /* __IODEFINE_HEADER__ */
