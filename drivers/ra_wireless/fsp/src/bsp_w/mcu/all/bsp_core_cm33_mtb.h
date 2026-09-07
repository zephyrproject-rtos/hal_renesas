/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef __CORE_CM33_H_MTB
 #define __CORE_CM33_H_MTB

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
 #include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

 #ifdef __cplusplus
extern "C" {
 #endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef struct
{
    __IOM uint32_t MTB_POSITION_REG;
    __IOM uint32_t MTB_MASTER_REG;
    __IOM uint32_t MTB_FLOW_REG;
    __IM uint32_t  MTB_BASE_REG;
    __IOM uint32_t MTB_TSTART_REG;
    __IOM uint32_t MTB_TSTOP_REG;
    uint32_t       RESERVED1;            /* SECURE Trace Control Register MTB_SECURE_REG 0xE0043018  */
    uint32_t       RESERVED2;
    uint32_t       RESERVED3[952U];      /* Reserved UNK/SBZP */
    uint32_t       RESERVED4[47U];       /* RES0 */
    __IM uint32_t  CORESIGHT_BASE[0U];   /* CoreSight block start */
    __IM uint32_t  CORESIGHT_REGS1[3U];  /* Various CoreSight registers */
    __IM uint32_t  DEVID;
    __IM uint32_t  CORESIGHT_REGS2[12U]; /* Various CoreSight registers */
} MTB_Type_t;

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* MTB_POSITION_REG */

 #define MTB_MTB_POSITION_REG_WRAP_Pos       (2UL)
 #define MTB_MTB_POSITION_REG_WRAP_Msk       (1UL << MTB_MTB_POSITION_REG_WRAP_Pos)
 #define MTB_MTB_POSITION_REG_POINTER_Pos    (3UL)
 #define MTB_MTB_POSITION_REG_POINTER_Msk    (0x1FFFFFFFUL << MTB_MTB_POSITION_REG_POINTER_Pos)

/* MTB_MASTER_REG */

 #define MTB_MTB_MASTER_REG_MASK_Pos         (0UL)
 #define MTB_MTB_MASTER_REG_MASK_Msk         (0x1FUL << MTB_MTB_MASTER_REG_MASK_Pos)
 #define MTB_MTB_MASTER_REG_TSTARTEN_Pos     (5UL)
 #define MTB_MTB_MASTER_REG_TSTARTEN_Msk     (0x1UL << MTB_MTB_MASTER_REG_TSTARTEN_Pos)
 #define MTB_MTB_MASTER_REG_TSTOPEN_Pos      (6UL)
 #define MTB_MTB_MASTER_REG_TSTOPEN_Msk      (0x1UL << MTB_MTB_MASTER_REG_TSTOPEN_Pos)
 #define MTB_MTB_MASTER_REG_RAMPRIV_Pos      (8UL)
 #define MTB_MTB_MASTER_REG_RAMPRIV_Msk      (0x1UL << MTB_MTB_MASTER_REG_RAMPRIV_Pos)
 #define MTB_MTB_MASTER_REG_HALTREQ_Pos      (9UL)
 #define MTB_MTB_MASTER_REG_HALTREQ_Msk      (0x1UL << MTB_MTB_MASTER_REG_HALTREQ_Pos)
 #define MTB_MTB_MASTER_REG_NSEN_Pos         (30UL)
 #define MTB_MTB_MASTER_REG_NSEN_Msk         (0x1UL << MTB_MTB_MASTER_REG_NSEN_Pos)
 #define MTB_MTB_MASTER_REG_EN_Pos           (31UL)
 #define MTB_MTB_MASTER_REG_EN_Msk           (0x1UL << MTB_MTB_MASTER_REG_EN_Pos)

/* MTB_FLOW_REG */

 #define MTB_MTB_FLOW_REG_AUTOSTOP_Pos       (0UL)
 #define MTB_MTB_FLOW_REG_AUTOSTOP_Msk       (1UL << MTB_MTB_FLOW_REG_AUTOSTOP_Pos)
 #define MTB_MTB_FLOW_REG_AUTOHALT_Pos       (1UL)
 #define MTB_MTB_FLOW_REG_AUTOHALT_Msk       (1UL << MTB_MTB_FLOW_REG_AUTOHALT_Pos)
 #define MTB_MTB_FLOW_REG_WATERMARK_Pos      (3UL)
 #define MTB_MTB_FLOW_REG_WATERMARK_Msk      (0x1FFFFFFFUL << MTB_MTB_FLOW_REG_WATERMARK_Pos)

/* MTB_BASE_REG */

 #define MTB_MTB_BASE_REG_BASE_Pos           (5UL)
 #define MTB_MTB_BASE_REG_BASE_Msk           (0x7FFFFFFUL << MTB_MTB_BASE_REG_BASE_Pos)

/* MTB_TSTART_REG */

 #define MTB_MTB_TSTART_REG_CMPMATCH0_Pos    (0UL)
 #define MTB_MTB_TSTART_REG_CMPMATCH0_Msk    (0x3UL << MTB_MTB_TSTART_REG_CMPMATCH0_Pos)
 #define MTB_MTB_TSTART_REG_CMPMATCH1_Pos    (2UL)
 #define MTB_MTB_TSTART_REG_CMPMATCH1_Msk    (0x3UL << MTB_MTB_TSTART_REG_CMPMATCH1_Pos)

/* MTB_TSTOP_REG */

 #define MTB_MTB_TSTOP_REG_CMPMATCH0_Pos     (0UL)
 #define MTB_MTB_TSTOP_REG_CMPMATCH0_Msk     (0x3UL << MTB_MTB_TSTOP_REG_CMPMATCH0_Pos)
 #define MTB_MTB_TSTOP_REG_CMPMATCH1_Pos     (2UL)
 #define MTB_MTB_TSTOP_REG_CMPMATCH1_Msk     (0x3UL << MTB_MTB_TSTOP_REG_CMPMATCH1_Pos)

/* DEVID */

 #define MTB_DEVID_MTBANDWIDTH_Pos           (0UL)
 #define MTB_DEVID_MTBANDWIDTH_Msk           (0x1FUL << MTB_DEVID_MTBANDWIDTH_Pos)

/* Memory mappings */

 #define MTB_BASE                            (0xE0043000UL)
 #define MTB                                 ((MTB_Type_t *) MTB_BASE)

 #ifdef __cplusplus
}
 #endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* __CORE_CM33_H_MTB */
