/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/* MICRON MT25QU512ABB	*/
#ifndef _SPI_MULTI_REG_VALUES_H_
#define _SPI_MULTI_REG_VALUES_H_
/*
 * Selectable definitions
 */
/* In the case of addr width 24bit						*/
#define SET_DRENR_ADE_VALUE  DRENR_ADE_ADD23_OUT
#define SET_DREAR_EAC_VALUE  DREAR_EAC_EXADDR24
/* In the case of addr width 32bit						*/
/* #define SET_DRENR_ADE_VALUE     DRENR_ADE_ADD31_OUT	*/
/* #define SET_DREAR_EAC_VALUE     DREAR_EAC_EXADDR25 	*/

/* In the case of bit width 1-1-1 and addr width 24bit				*/
/* #define SET_DRCMR_CMD_VALUE  DRCMR_CMD_FAST_READ_3B				*/
/* #define SET_DRENR_ADB_VALUE  DRENR_ADB_1BIT						*/
/* #define SET_DRENR_DRDB_VALUE DRENR_DRDB_1BIT						*/
/* In the case of bit width 1-1-4 and addr width 24bit 				*/
/* #define SET_DRCMR_CMD_VALUE  DRCMR_CMD_QUAD_OUTPUT_FAST_READ_3B 	*/
/* #define SET_DRENR_ADB_VALUE  DRENR_ADB_1BIT						*/
/* #define SET_DRENR_DRDB_VALUE DRENR_DRDB_4BIT						*/
/* In the case of bit width 1-4-4 and addr width 24bit 				*/
#define SET_DRCMR_CMD_VALUE  DRCMR_CMD_QUAD_INPUT_OUTPUT_FAST_READ_3B
#define SET_DRENR_ADB_VALUE  DRENR_ADB_4BIT
#define SET_DRENR_DRDB_VALUE DRENR_DRDB_4BIT

/* In the case of bit width 1-1-1 and addr width 32bit					*/
/* #define SET_DRCMR_CMD_VALUE  DRCMR_CMD_FAST_READ_4B					*/
/* #define SET_DRENR_ADB_VALUE  DRENR_ADB_1BIT							*/
/* #define SET_DRENR_DRDB_VALUE DRENR_DRDB_1BIT							*/
/* In the case of bit width 1-1-4 and addr width 32bit					*/
/* #define SET_DRCMR_CMD_VALUE  DRCMR_CMD_QUAD_OUTPUT_FAST_READ_4B		*/
/* #define SET_DRENR_ADB_VALUE  DRENR_ADB_1BIT							*/
/* #define SET_DRENR_DRDB_VALUE DRENR_DRDB_4BIT							*/
/* In the case of bit width 1-4-4 and addr width 32bit					*/
/* #define SET_DRCMR_CMD_VALUE  DRCMR_CMD_QUAD_INPUT_OUTPUT_FAST_READ_4B*/
/* #define SET_DRENR_ADB_VALUE  DRENR_ADB_4BIT							*/
/* #define SET_DRENR_DRDB_VALUE DRENR_DRDB_4BIT							*/

/* dummy cycle SPI_MULTI_DUMMY_1CYCLE - SPI_MULTI_DUMMY_20CYCLE */
#define SET_DRDMCR_VALUE     SPI_MULTI_DUMMY_10CYCLE

/* SDR mode serial flash settings */
#define SPIM_PHYCNT_SET_VALUE (PHYCNT_DEF_DATA | PHYCNT_PHYMEM_SDR_MODE |					\
                                PHYCNT_WBUF_NOT_USED | PHYCNT_WBUF2_NOT_USED |				\
                                PHYCNT_CKSEL_SLOW | PHYCNT_HS_OTHER_MODE |					\
                                PHYCNT_OCT_OTHER_MODE | PHYCNT_EXDS_NOT_USED |				\
                                PHYCNT_OCTA_HYPER_FLASH | PHYCNT_ALT_ALIGN_NOT_SUPPORTED |	\
                                PHYCNT_CAL_NOT_PERFOMED)
#define SPIM_PHYCNT_SDR_TIM_ADJ_SET_VALUE (SPIM_PHYCNT_SET_VALUE | PHYCNT_CKSEL_FAST)

/* Read timing setting */
#define SPIM_PHYOFFSET1_SET_VALUE (PHYOFFSET1_DEF_DATA | PHYOFFSET1_DDRTMG_SPIDRE_0)
#define SPIM_PHYOFFSET2_SET_VALUE (PHYOFFSET2_DEF_DATA | PHYOFFSET2_OCTTMG_HYPER_FLASH)

/* Set the QSPIn_SSL setting value */
#define SPIM_CMNCR_EXTREAD_SET_VALUE (CMNCR_IO0FV_OUT_PREV | CMNCR_IO2FV_OUT_PREV |	\
					CMNCR_IO3FV_OUT_PREV | CMNCR_MOIIO0_OUT1 |						\
					CMNCR_MOIIO1_OUT1    | CMNCR_MOIIO2_OUT1 |						\
					CMNCR_MOIIO3_OUT1    | CMNCR_DEF_DATA    |						\
					CMNCR_MD_EXT_READ)

#define SPIM_CMNCR_MANUAL_SET_VALUE (CMNCR_IO0FV_OUT_PREV | CMNCR_IO2FV_OUT_PREV |	\
					CMNCR_IO3FV_OUT_PREV | CMNCR_MOIIO0_OUT1 |						\
					CMNCR_MOIIO1_OUT1    | CMNCR_MOIIO2_OUT1 |						\
					CMNCR_MOIIO3_OUT1    | CMNCR_DEF_DATA |							\
					CMNCR_MD_MANUAL)
/* Set SSL delay setting value */
#define SPIM_SSLDR_SET_VALUE (SSLDR_SCKDL_4_5 | SSLDR_SLNDL_4QSPIn | SSLDR_SPNDL_4QSPIn)

/* Set the RBE bit and RCF bit and RBURST */
#define SPIM_DRCR_SET_VALUE (DRCR_RBE | DRCR_RCF | DRCR_RBURST_32_DATALEN)

/* Set the data read command */
#define SPIM_DRCMR_SET_VALUE (SET_DRCMR_CMD_VALUE)

/* Extended external address setting */
#define SPIM_DREAR_SET_VALUE (SET_DREAR_EAC_VALUE)

/* Set the bit width of command and address output to 1 bit and	*/
/* the address size to 4 byte									*/
#define SPIM_DRENR_SET_VALUE (DRENR_CDB_1BIT | DRENR_OCDB_1BIT | SET_DRENR_ADB_VALUE |	\
				DRENR_OPDB_1BIT | SET_DRENR_DRDB_VALUE | DRENR_CDE | DRENR_DME | 		\
				SET_DRENR_ADE_VALUE | DRENR_OPDE_NO_OUT)
/* Dummy cycle setting */
#define SPIM_DRDMCR_SET_VALUE (SET_DRDMCR_VALUE)

/* Change to SPI flash mode */
#define SPIM_DRDRENR_SET_VALUE (DRDRENR_DRDRE_SDR | DRDRENR_OPDRE_SDR |	\
				DRDRENR_ADDRE_SDR | DRDRENR_HYPE_SPI)
/* Set the SDR transfer & SPI flash mode */
#define SPIM_SMDRENR_SET_VALUE (SMDRENR_HYPE_SPI_FLASH)
/* Manual Command */
#define SMCMR_CMD_READ_STATUS_REGISTER   (0x05)
#define SMCMR_CMD_BIT_SHIFT                (16)
#define SMWDR0_1BYTE_DATA_BIT_SHIFT        (24)

/* Manual Command  Configure Length */
#define SPI_MANUAL_COMMAND_SIZE_0      SMENR_SPIDE_NO_SEND
#define SPI_MANUAL_COMMAND_SIZE_8_BIT  SMENR_SPIDE_8BIT_SEND
#define SPI_MANUAL_COMMAND_SIZE_16_BIT SMENR_SPIDE_16BIT_SEND
#define SPI_MANUAL_COMMAND_SIZE_32_BIT SMENR_SPIDE_32BIT_SEND

#endif /* _SPI_MULTI_REG_VALUES_H_ */
