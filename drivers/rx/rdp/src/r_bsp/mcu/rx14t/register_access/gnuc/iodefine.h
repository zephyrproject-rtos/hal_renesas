/*
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/********************************************************************************
*
* Device     : RX/RX100/RX14T
*
* File Name  : iodefine.h
*
* Abstract   : Definition of I/O Register.
*
* History    : V0.40  (2025-02-21)  [Hardware Manual Revision : 0.40]
*            : V0.40A (2025-04-09)  [Hardware Manual Revision : 0.40]
*            : V0.40B (2025-06-11)  [Hardware Manual Revision : 0.40]
*            : V0.40C (2025-06-24)  [Hardware Manual Revision : 0.40]
*            : V0.50  (2025-07-29)  [Hardware Manual Revision : 0.50]
*
* Note       : THIS IS A TYPICAL EXAMPLE.
*
*********************************************************************************/
/********************************************************************************/
/*                                                                              */
/*  DESCRIPTION : Definition of ICU Register                                    */
/*  CPU TYPE    : RX14T                                                         */
/*                                                                              */
/*  Usage : IR,DTCER,IER,IPR of ICU Register                                    */
/*     The following IR, DTCE, IEN, IPR macro functions simplify usage.         */
/*     The bit access operation is "Bit_Name(interrupt source,name)".           */
/*     A part of the name can be omitted.                                       */
/*     for example :                                                            */
/*       IR(MTU0,TGIA0) = 0;     expands to :                                   */
/*         ICU.IR[114].BIT.IR = 0;                                              */
/*                                                                              */
/*       DTCE(ICU,IRQ0) = 1;     expands to :                                   */
/*         ICU.DTCER[64].BIT.DTCE = 1;                                          */
/*                                                                              */
/*       IEN(CMT0,CMI0) = 1;     expands to :                                   */
/*         ICU.IER[0x03].BIT.IEN4 = 1;                                          */
/*                                                                              */
/*       IPR(MTU1,TGIA1) = 2;    expands to :                                   */
/*       IPR(MTU1,TGI  ) = 2;    // TGIA1,TGIB1 share IPR level.                */
/*         ICU.IPR[121].BIT.IPR = 2;                                            */
/*                                                                              */
/*       IPR(SCI1,ERI1) = 3;     expands to :                                   */
/*       IPR(SCI1,    ) = 3;     // SCI1 uses single IPR for all sources.       */
/*         ICU.IPR[218].BIT.IPR = 3;                                            */
/*                                                                              */
/*  Usage : #pragma interrupt Function_Identifier(vect=**)                      */
/*     The number of vector is "(interrupt source, name)".                      */
/*     for example :                                                            */
/*       #pragma interrupt INT_IRQ0(vect=VECT(ICU,IRQ0))          expands to :  */
/*         #pragma interrupt INT_IRQ0(vect=64)                                  */
/*       #pragma interrupt INT_CMT0_CMI0(vect=VECT(CMT0,CMI0))    expands to :  */
/*         #pragma interrupt INT_CMT0_CMI0(vect=28)                             */
/*       #pragma interrupt INT_MTU0_TGIA0(vect=VECT(MTU0,TGIA0))  expands to :  */
/*         #pragma interrupt INT_MTU0_TGIA0(vect=114)                           */
/*                                                                              */
/*  Usage : MSTPCRA,MSTPCRB,MSTPCRC of SYSTEM Register                          */
/*     The bit access operation is "MSTP(name)".                                */
/*     The name that can be used is a macro name defined with "iodefine.h".     */
/*     for example :                                                            */
/*       MSTP(TMR2) = 0;    // TMR2,TMR3,TMR23                    expands to :  */
/*         SYSTEM.MSTPCRA.BIT.MSTPA4  = 0;                                      */
/*       MSTP(MTU4) = 0;    // MTU,MTU0,MTU1,MTU2,MTU3,MTU4,MTU5  expands to :  */
/*         SYSTEM.MSTPCRA.BIT.MSTPA9  = 0;                                      */
/*                                                                              */
/*                                                                              */
/********************************************************************************/
#ifndef __RX14TIODEFINE_HEADER__
#define __RX14TIODEFINE_HEADER__

#define	IEN_BSC_BUSERR		IEN0
#define	IEN_FCU_FRDYI		IEN7
#define	IEN_ICU_SWINT		IEN3
#define	IEN_CMT0_CMI0		IEN4
#define	IEN_CMT1_CMI1		IEN5
#define	IEN_CAC_FERRF		IEN0
#define	IEN_CAC_MENDF		IEN1
#define	IEN_CAC_OVFF		IEN2
#define	IEN_POEG_POEGGAI	IEN0
#define	IEN_GPTW0_GTCIA0	IEN0
#define	IEN_GPTW0_GTCIB0	IEN1
#define	IEN_GPTW0_GTCIC0	IEN2
#define	IEN_GPTW0_GTCID0	IEN3
#define	IEN_GPTW0_GDTE0		IEN4
#define	IEN_GPTW0_GTCIE0	IEN5
#define	IEN_GPTW0_GTCIF0	IEN6
#define	IEN_GPTW0_GTCIV0	IEN7
#define	IEN_GPTW0_GTCIU0	IEN0
#define	IEN_DOC_DOPCF		IEN1
#define	IEN_ICU_IRQ0		IEN0
#define	IEN_ICU_IRQ1		IEN1
#define	IEN_ICU_IRQ2		IEN2
#define	IEN_ICU_IRQ3		IEN3
#define	IEN_ICU_IRQ4		IEN4
#define	IEN_ICU_IRQ5		IEN5
#define	IEN_ICU_IRQ6		IEN6
#define	IEN_ICU_IRQ7		IEN7
#define	IEN_LVD_LVD1		IEN0
#define	IEN_LVD_LVD2		IEN1
#define	IEN_GPTW1_GTCIA1	IEN2
#define	IEN_GPTW1_GTCIB1	IEN3
#define	IEN_GPTW1_GTCIC1	IEN4
#define	IEN_GPTW1_GTCID1	IEN5
#define	IEN_S12AD_S12ADI	IEN6
#define	IEN_S12AD_GBADI		IEN7
#define	IEN_S12AD_GCADI		IEN0
#define	IEN_S12AD1_S12ADI1	IEN1
#define	IEN_S12AD1_GBADI1	IEN2
#define	IEN_S12AD1_GCADI1	IEN3
#define	IEN_CMPC0_CMPC0		IEN4
#define	IEN_CMPC1_CMPC1		IEN5
#define	IEN_CMPC2_CMPC2		IEN6
#define	IEN_MTU0_TGIA0		IEN2
#define	IEN_MTU0_TGIB0		IEN3
#define	IEN_MTU0_TGIC0		IEN4
#define	IEN_MTU0_TGID0		IEN5
#define	IEN_MTU0_TCIV0		IEN6
#define	IEN_MTU0_TGIE0		IEN7
#define	IEN_MTU0_TGIF0		IEN0
#define	IEN_MTU1_TGIA1		IEN1
#define	IEN_MTU1_TGIB1		IEN2
#define	IEN_MTU1_TCIV1		IEN3
#define	IEN_MTU1_TCIU1		IEN4
#define	IEN_MTU2_TGIA2		IEN5
#define	IEN_MTU2_TGIB2		IEN6
#define	IEN_MTU2_TCIV2		IEN7
#define	IEN_MTU2_TCIU2		IEN0
#define	IEN_MTU3_TGIA3		IEN1
#define	IEN_MTU3_TGIB3		IEN2
#define	IEN_MTU3_TGIC3		IEN3
#define	IEN_MTU3_TGID3		IEN4
#define	IEN_MTU3_TCIV3		IEN5
#define	IEN_MTU4_TGIA4		IEN6
#define	IEN_MTU4_TGIB4		IEN7
#define	IEN_MTU4_TGIC4		IEN0
#define	IEN_MTU4_TGID4		IEN1
#define	IEN_MTU4_TCIV4		IEN2
#define	IEN_MTU5_TGIU5		IEN3
#define	IEN_MTU5_TGIV5		IEN4
#define	IEN_MTU5_TGIW5		IEN5
#define	IEN_POE_OEI1		IEN0
#define	IEN_POE_OEI3		IEN2
#define	IEN_POE_OEI4		IEN3
#define	IEN_POE_OEI5		IEN4
#define	IEN_TMR0_CMIA0		IEN6
#define	IEN_TMR0_CMIB0		IEN7
#define	IEN_TMR0_OVI0		IEN0
#define	IEN_TMR1_CMIA1		IEN1
#define	IEN_TMR1_CMIB1		IEN2
#define	IEN_TMR1_OVI1		IEN3
#define	IEN_TMR2_CMIA2		IEN4
#define	IEN_TMR2_CMIB2		IEN5
#define	IEN_TMR2_OVI2		IEN6
#define	IEN_TMR3_CMIA3		IEN7
#define	IEN_TMR3_CMIB3		IEN0
#define	IEN_TMR3_OVI3		IEN1
#define	IEN_GPTW1_GDTE1		IEN2
#define	IEN_GPTW1_GTCIE1	IEN3
#define	IEN_GPTW1_GTCIF1	IEN4
#define	IEN_GPTW1_GTCIV1	IEN5
#define	IEN_GPTW1_GTCIU1	IEN6
#define	IEN_GPTW2_GTCIA2	IEN7
#define	IEN_GPTW2_GTCIB2	IEN0
#define	IEN_GPTW2_GTCIC2	IEN1
#define	IEN_GPTW2_GTCID2	IEN2
#define	IEN_GPTW2_GDTE2		IEN3
#define	IEN_GPTW2_GTCIE2	IEN4
#define	IEN_GPTW2_GTCIF2	IEN5
#define	IEN_GPTW2_GTCIV2	IEN6
#define	IEN_GPTW2_GTCIU2	IEN7
#define	IEN_SCI1_ERI1		IEN2
#define	IEN_SCI1_RXI1		IEN3
#define	IEN_SCI1_TXI1		IEN4
#define	IEN_SCI1_TEI1		IEN5
#define	IEN_SCI5_ERI5		IEN6
#define	IEN_SCI5_RXI5		IEN7
#define	IEN_SCI5_TXI5		IEN0
#define	IEN_SCI5_TEI5		IEN1
#define	IEN_SCI6_ERI6		IEN2
#define	IEN_SCI6_RXI6		IEN3
#define	IEN_SCI6_TXI6		IEN4
#define	IEN_SCI6_TEI6		IEN5
#define	IEN_SCI12_ERI12		IEN6
#define	IEN_SCI12_RXI12		IEN7
#define	IEN_SCI12_TXI12		IEN0
#define	IEN_SCI12_TEI12		IEN1
#define	IEN_SCI12_SCIX0		IEN2
#define	IEN_SCI12_SCIX1		IEN3
#define	IEN_SCI12_SCIX2		IEN4
#define	IEN_SCI12_SCIX3		IEN5
#define	IEN_RIIC0_EEI0		IEN6
#define	IEN_RIIC0_RXI0		IEN7
#define	IEN_RIIC0_TXI0		IEN0
#define	IEN_RIIC0_TEI0		IEN1

#define	VECT_BSC_BUSERR		16
#define	VECT_FCU_FRDYI		23
#define	VECT_ICU_SWINT		27
#define	VECT_CMT0_CMI0		28
#define	VECT_CMT1_CMI1		29
#define	VECT_CAC_FERRF		32
#define	VECT_CAC_MENDF		33
#define	VECT_CAC_OVFF		34
#define	VECT_POEG_POEGGAI	40
#define	VECT_GPTW0_GTCIA0	48
#define	VECT_GPTW0_GTCIB0	49
#define	VECT_GPTW0_GTCIC0	50
#define	VECT_GPTW0_GTCID0	51
#define	VECT_GPTW0_GDTE0	52
#define	VECT_GPTW0_GTCIE0	53
#define	VECT_GPTW0_GTCIF0	54
#define	VECT_GPTW0_GTCIV0	55
#define	VECT_GPTW0_GTCIU0	56
#define	VECT_DOC_DOPCF		57
#define	VECT_ICU_IRQ0		64
#define	VECT_ICU_IRQ1		65
#define	VECT_ICU_IRQ2		66
#define	VECT_ICU_IRQ3		67
#define	VECT_ICU_IRQ4		68
#define	VECT_ICU_IRQ5		69
#define	VECT_ICU_IRQ6		70
#define	VECT_ICU_IRQ7		71
#define	VECT_LVD_LVD1		88
#define	VECT_LVD_LVD2		89
#define	VECT_GPTW1_GTCIA1	98
#define	VECT_GPTW1_GTCIB1	99
#define	VECT_GPTW1_GTCIC1	100
#define	VECT_GPTW1_GTCID1	101
#define	VECT_S12AD_S12ADI	102
#define	VECT_S12AD_GBADI	103
#define	VECT_S12AD_GCADI	104
#define	VECT_S12AD1_S12ADI1	105
#define	VECT_S12AD1_GBADI1	106
#define	VECT_S12AD1_GCADI1	107
#define	VECT_CMPC0_CMPC0	108
#define	VECT_CMPC1_CMPC1	109
#define	VECT_CMPC2_CMPC2	110
#define	VECT_MTU0_TGIA0		114
#define	VECT_MTU0_TGIB0		115
#define	VECT_MTU0_TGIC0		116
#define	VECT_MTU0_TGID0		117
#define	VECT_MTU0_TCIV0		118
#define	VECT_MTU0_TGIE0		119
#define	VECT_MTU0_TGIF0		120
#define	VECT_MTU1_TGIA1		121
#define	VECT_MTU1_TGIB1		122
#define	VECT_MTU1_TCIV1		123
#define	VECT_MTU1_TCIU1		124
#define	VECT_MTU2_TGIA2		125
#define	VECT_MTU2_TGIB2		126
#define	VECT_MTU2_TCIV2		127
#define	VECT_MTU2_TCIU2		128
#define	VECT_MTU3_TGIA3		129
#define	VECT_MTU3_TGIB3		130
#define	VECT_MTU3_TGIC3		131
#define	VECT_MTU3_TGID3		132
#define	VECT_MTU3_TCIV3		133
#define	VECT_MTU4_TGIA4		134
#define	VECT_MTU4_TGIB4		135
#define	VECT_MTU4_TGIC4		136
#define	VECT_MTU4_TGID4		137
#define	VECT_MTU4_TCIV4		138
#define	VECT_MTU5_TGIU5		139
#define	VECT_MTU5_TGIV5		140
#define	VECT_MTU5_TGIW5		141
#define	VECT_POE_OEI1		168
#define	VECT_POE_OEI3		170
#define	VECT_POE_OEI4		171
#define	VECT_POE_OEI5		172
#define	VECT_TMR0_CMIA0		174
#define	VECT_TMR0_CMIB0		175
#define	VECT_TMR0_OVI0		176
#define	VECT_TMR1_CMIA1		177
#define	VECT_TMR1_CMIB1		178
#define	VECT_TMR1_OVI1		179
#define	VECT_TMR2_CMIA2		180
#define	VECT_TMR2_CMIB2		181
#define	VECT_TMR2_OVI2		182
#define	VECT_TMR3_CMIA3		183
#define	VECT_TMR3_CMIB3		184
#define	VECT_TMR3_OVI3		185
#define	VECT_GPTW1_GDTE1	202
#define	VECT_GPTW1_GTCIE1	203
#define	VECT_GPTW1_GTCIF1	204
#define	VECT_GPTW1_GTCIV1	205
#define	VECT_GPTW1_GTCIU1	206
#define	VECT_GPTW2_GTCIA2	207
#define	VECT_GPTW2_GTCIB2	208
#define	VECT_GPTW2_GTCIC2	209
#define	VECT_GPTW2_GTCID2	210
#define	VECT_GPTW2_GDTE2	211
#define	VECT_GPTW2_GTCIE2	212
#define	VECT_GPTW2_GTCIF2	213
#define	VECT_GPTW2_GTCIV2	214
#define	VECT_GPTW2_GTCIU2	215
#define	VECT_SCI1_ERI1		218
#define	VECT_SCI1_RXI1		219
#define	VECT_SCI1_TXI1		220
#define	VECT_SCI1_TEI1		221
#define	VECT_SCI5_ERI5		222
#define	VECT_SCI5_RXI5		223
#define	VECT_SCI5_TXI5		224
#define	VECT_SCI5_TEI5		225
#define	VECT_SCI6_ERI6		226
#define	VECT_SCI6_RXI6		227
#define	VECT_SCI6_TXI6		228
#define	VECT_SCI6_TEI6		229
#define	VECT_SCI12_ERI12	238
#define	VECT_SCI12_RXI12	239
#define	VECT_SCI12_TXI12	240
#define	VECT_SCI12_TEI12	241
#define	VECT_SCI12_SCIX0	242
#define	VECT_SCI12_SCIX1	243
#define	VECT_SCI12_SCIX2	244
#define	VECT_SCI12_SCIX3	245
#define	VECT_RIIC0_EEI0		246
#define	VECT_RIIC0_RXI0		247
#define	VECT_RIIC0_TXI0		248
#define	VECT_RIIC0_TEI0		249

#define	MSTP_DTC	SYSTEM.MSTPCRA.BIT.MSTPA28
#define	MSTP_DA		SYSTEM.MSTPCRA.BIT.MSTPA19
#define	MSTP_PGA0	SYSTEM.MSTPCRA.BIT.MSTPA17
#define	MSTP_S12AD	SYSTEM.MSTPCRA.BIT.MSTPA17
#define	MSTP_S12AD1	SYSTEM.MSTPCRA.BIT.MSTPA16
#define	MSTP_CMT0	SYSTEM.MSTPCRA.BIT.MSTPA15
#define	MSTP_CMT1	SYSTEM.MSTPCRA.BIT.MSTPA15
#define	MSTP_MTU	SYSTEM.MSTPCRA.BIT.MSTPA9
#define	MSTP_MTU0	SYSTEM.MSTPCRA.BIT.MSTPA9
#define	MSTP_MTU1	SYSTEM.MSTPCRA.BIT.MSTPA9
#define	MSTP_MTU2	SYSTEM.MSTPCRA.BIT.MSTPA9
#define	MSTP_MTU3	SYSTEM.MSTPCRA.BIT.MSTPA9
#define	MSTP_MTU4	SYSTEM.MSTPCRA.BIT.MSTPA9
#define	MSTP_MTU5	SYSTEM.MSTPCRA.BIT.MSTPA9
#define	MSTP_GPTW	SYSTEM.MSTPCRA.BIT.MSTPA7
#define	MSTP_GPTW0	SYSTEM.MSTPCRA.BIT.MSTPA7
#define	MSTP_GPTW1	SYSTEM.MSTPCRA.BIT.MSTPA7
#define	MSTP_GPTW2	SYSTEM.MSTPCRA.BIT.MSTPA7
#define	MSTP_POEG	SYSTEM.MSTPCRA.BIT.MSTPA7
#define	MSTP_TMR0	SYSTEM.MSTPCRA.BIT.MSTPA5
#define	MSTP_TMR1	SYSTEM.MSTPCRA.BIT.MSTPA5
#define	MSTP_TMR01	SYSTEM.MSTPCRA.BIT.MSTPA5
#define	MSTP_TMR2	SYSTEM.MSTPCRA.BIT.MSTPA4
#define	MSTP_TMR3	SYSTEM.MSTPCRA.BIT.MSTPA4
#define	MSTP_TMR23	SYSTEM.MSTPCRA.BIT.MSTPA4
#define	MSTP_SCI1	SYSTEM.MSTPCRB.BIT.MSTPB30
#define	MSTP_SMCI1	SYSTEM.MSTPCRB.BIT.MSTPB30
#define	MSTP_SCI5	SYSTEM.MSTPCRB.BIT.MSTPB26
#define	MSTP_SMCI5	SYSTEM.MSTPCRB.BIT.MSTPB26
#define	MSTP_SCI6	SYSTEM.MSTPCRB.BIT.MSTPB25
#define	MSTP_SMCI6	SYSTEM.MSTPCRB.BIT.MSTPB25
#define	MSTP_CRC	SYSTEM.MSTPCRB.BIT.MSTPB23
#define	MSTP_RIIC0	SYSTEM.MSTPCRB.BIT.MSTPB21
#define	MSTP_CMPC0	SYSTEM.MSTPCRB.BIT.MSTPB10
#define	MSTP_CMPC1	SYSTEM.MSTPCRB.BIT.MSTPB10
#define	MSTP_CMPC2	SYSTEM.MSTPCRB.BIT.MSTPB10
#define	MSTP_DOC	SYSTEM.MSTPCRB.BIT.MSTPB6
#define	MSTP_SCI12	SYSTEM.MSTPCRB.BIT.MSTPB4
#define	MSTP_SMCI12	SYSTEM.MSTPCRB.BIT.MSTPB4
#define	MSTP_CAC	SYSTEM.MSTPCRC.BIT.MSTPC19
#define	MSTP_RAM0	SYSTEM.MSTPCRC.BIT.MSTPC0

#define	__IR( x )		ICU.IR[ IR ## x ].BIT.IR
#define	 _IR( x )		__IR( x )
#define	  IR( x , y )	_IR( _ ## x ## _ ## y )
#define	__DTCE( x )		ICU.DTCER[ DTCE ## x ].BIT.DTCE
#define	 _DTCE( x )		__DTCE( x )
#define	  DTCE( x , y )	_DTCE( _ ## x ## _ ## y )
#define	__IEN( x )		ICU.IER[ IER ## x ].BIT.IEN ## x
#define	 _IEN( x )		__IEN( x )
#define	  IEN( x , y )	_IEN( _ ## x ## _ ## y )
#define	__IPR( x )		ICU.IPR[ IPR ## x ].BIT.IPR
#define	 _IPR( x )		__IPR( x )
#define	  IPR( x , y )	_IPR( _ ## x ## _ ## y )
#define	__VECT( x )		VECT ## x
#define	 _VECT( x )		__VECT( x )
#define	  VECT( x , y )	_VECT( _ ## x ## _ ## y )
#define	__MSTP( x )		MSTP ## x
#define	 _MSTP( x )		__MSTP( x )
#define	  MSTP( x )		_MSTP( _ ## x )

#define	BSC		(*(volatile struct st_bsc     *)0x81300)
#define	CAC		(*(volatile struct st_cac     *)0x8B000)
#define	CMPC0	(*(volatile struct st_cmpc    *)0xA0C80)
#define	CMPC1	(*(volatile struct st_cmpc    *)0xA0CA0)
#define	CMPC2	(*(volatile struct st_cmpc    *)0xA0CC0)
#define	CMT		(*(volatile struct st_cmt     *)0x88000)
#define	CMT0	(*(volatile struct st_cmt0    *)0x88002)
#define	CMT1	(*(volatile struct st_cmt0    *)0x88008)
#define	CRC		(*(volatile struct st_crc     *)0x88280)
#define	DA		(*(volatile struct st_da      *)0x880C0)
#define	DOC		(*(volatile struct st_doc     *)0x8B080)
#define	DTC		(*(volatile struct st_dtc     *)0x82400)
#define	FLASH	(*(volatile struct st_flash   *)0x7FC090)
#define	GPTW0	(*(volatile struct st_gptw    *)0x96000)
#define	GPTW1	(*(volatile struct st_gptw    *)0x96100)
#define	GPTW2	(*(volatile struct st_gptw    *)0x96200)
#define	ICU		(*(volatile struct st_icu     *)0x87000)
#define	IWDT	(*(volatile struct st_iwdt    *)0x88030)
#define	MPC		(*(volatile struct st_mpc     *)0x8C11F)
#define	MTU		(*(volatile struct st_mtu     *)0x9520A)
#define	MTU0	(*(volatile struct st_mtu0    *)0x95290)
#define	MTU1	(*(volatile struct st_mtu1    *)0x95290)
#define	MTU2	(*(volatile struct st_mtu2    *)0x95292)
#define	MTU3	(*(volatile struct st_mtu3    *)0x95200)
#define	MTU4	(*(volatile struct st_mtu4    *)0x95200)
#define	MTU5	(*(volatile struct st_mtu5    *)0x95294)
#define	OFSM	(*(volatile struct st_ofsm    *)0xFFFFFF80)
#define	PGA0	(*(volatile struct st_pga     *)0x891A0)
#define	POE		(*(volatile struct st_poe     *)0x9E400)
#define	POEG	(*(volatile struct st_poeg    *)0x9E000)
#define	PORT0	(*(volatile struct st_port0   *)0x8C000)
#define	PORT1	(*(volatile struct st_port1   *)0x8C001)
#define	PORT2	(*(volatile struct st_port2   *)0x8C002)
#define	PORT3	(*(volatile struct st_port3   *)0x8C003)
#define	PORT4	(*(volatile struct st_port4   *)0x8C004)
#define	PORT7	(*(volatile struct st_port7   *)0x8C007)
#define	PORT9	(*(volatile struct st_port9   *)0x8C009)
#define	PORTB	(*(volatile struct st_portb   *)0x8C00B)
#define	PORTD	(*(volatile struct st_portd   *)0x8C00D)
#define	PORTE	(*(volatile struct st_porte   *)0x8C04E)
#define	PORTG	(*(volatile struct st_portg   *)0x8C010)
#define	RIIC0	(*(volatile struct st_riic    *)0x88300)
#define	S12AD	(*(volatile struct st_s12ad   *)0x89000)
#define	S12AD1	(*(volatile struct st_s12ad1  *)0x89200)
#define	SCI1	(*(volatile struct st_sci1    *)0x8A020)
#define	SCI5	(*(volatile struct st_sci1    *)0x8A0A0)
#define	SCI6	(*(volatile struct st_sci1    *)0x8A0C0)
#define	SCI12	(*(volatile struct st_sci12   *)0x8B300)
#define	SMCI1	(*(volatile struct st_smci    *)0x8A020)
#define	SMCI5	(*(volatile struct st_smci    *)0x8A0A0)
#define	SMCI6	(*(volatile struct st_smci    *)0x8A0C0)
#define	SMCI12	(*(volatile struct st_smci    *)0x8B300)
#define	SYSTEM	(*(volatile struct st_system  *)0x80000)
#define	TEMPS	(*(volatile struct st_temps   *)0x7FC228)
#define	TMR0	(*(volatile struct st_tmr0    *)0x88200)
#define	TMR1	(*(volatile struct st_tmr1    *)0x88201)
#define	TMR2	(*(volatile struct st_tmr0    *)0x88210)
#define	TMR3	(*(volatile struct st_tmr1    *)0x88211)
#define	TMR01	(*(volatile struct st_tmr01   *)0x88204)
#define	TMR23	(*(volatile struct st_tmr01   *)0x88214)

typedef enum enum_ir {
IR_BSC_BUSERR=16,IR_FCU_FRDYI=23,
IR_ICU_SWINT=27,
IR_CMT0_CMI0,
IR_CMT1_CMI1,
IR_CAC_FERRF=32,IR_CAC_MENDF,IR_CAC_OVFF,
IR_POEG_POEGGAI=40,
IR_GPTW0_GTCIA0=48,IR_GPTW0_GTCIB0,IR_GPTW0_GTCIC0,IR_GPTW0_GTCID0,IR_GPTW0_GDTE0,IR_GPTW0_GTCIE0,IR_GPTW0_GTCIF0,IR_GPTW0_GTCIV0,IR_GPTW0_GTCIU0,
IR_DOC_DOPCF,
IR_ICU_IRQ0=64,IR_ICU_IRQ1,IR_ICU_IRQ2,IR_ICU_IRQ3,IR_ICU_IRQ4,IR_ICU_IRQ5,IR_ICU_IRQ6,IR_ICU_IRQ7,
IR_LVD_LVD1=88,IR_LVD_LVD2,
IR_GPTW1_GTCIA1=98,IR_GPTW1_GTCIB1,IR_GPTW1_GTCIC1,IR_GPTW1_GTCID1,
IR_S12AD_S12ADI,IR_S12AD_GBADI,IR_S12AD_GCADI,
IR_S12AD1_S12ADI1,IR_S12AD1_GBADI1,IR_S12AD1_GCADI1,
IR_CMPC0_CMPC0,
IR_CMPC1_CMPC1,
IR_CMPC2_CMPC2,
IR_MTU0_TGIA0=114,IR_MTU0_TGIB0,IR_MTU0_TGIC0,IR_MTU0_TGID0,IR_MTU0_TCIV0,IR_MTU0_TGIE0,IR_MTU0_TGIF0,
IR_MTU1_TGIA1,IR_MTU1_TGIB1,IR_MTU1_TCIV1,IR_MTU1_TCIU1,
IR_MTU2_TGIA2,IR_MTU2_TGIB2,IR_MTU2_TCIV2,IR_MTU2_TCIU2,
IR_MTU3_TGIA3,IR_MTU3_TGIB3,IR_MTU3_TGIC3,IR_MTU3_TGID3,IR_MTU3_TCIV3,
IR_MTU4_TGIA4,IR_MTU4_TGIB4,IR_MTU4_TGIC4,IR_MTU4_TGID4,IR_MTU4_TCIV4,
IR_MTU5_TGIU5,IR_MTU5_TGIV5,IR_MTU5_TGIW5,
IR_POE_OEI1=168,IR_POE_OEI3=170,IR_POE_OEI4,IR_POE_OEI5,
IR_TMR0_CMIA0=174,IR_TMR0_CMIB0,IR_TMR0_OVI0,
IR_TMR1_CMIA1,IR_TMR1_CMIB1,IR_TMR1_OVI1,
IR_TMR2_CMIA2,IR_TMR2_CMIB2,IR_TMR2_OVI2,
IR_TMR3_CMIA3,IR_TMR3_CMIB3,IR_TMR3_OVI3,
IR_GPTW1_GDTE1=202,IR_GPTW1_GTCIE1,IR_GPTW1_GTCIF1,IR_GPTW1_GTCIV1,IR_GPTW1_GTCIU1,
IR_GPTW2_GTCIA2,IR_GPTW2_GTCIB2,IR_GPTW2_GTCIC2,IR_GPTW2_GTCID2,IR_GPTW2_GDTE2,IR_GPTW2_GTCIE2,IR_GPTW2_GTCIF2,IR_GPTW2_GTCIV2,IR_GPTW2_GTCIU2,
IR_SCI1_ERI1=218,IR_SCI1_RXI1,IR_SCI1_TXI1,IR_SCI1_TEI1,
IR_SCI5_ERI5,IR_SCI5_RXI5,IR_SCI5_TXI5,IR_SCI5_TEI5,
IR_SCI6_ERI6,IR_SCI6_RXI6,IR_SCI6_TXI6,IR_SCI6_TEI6,
IR_SCI12_ERI12=238,IR_SCI12_RXI12,IR_SCI12_TXI12,IR_SCI12_TEI12,IR_SCI12_SCIX0,IR_SCI12_SCIX1,IR_SCI12_SCIX2,IR_SCI12_SCIX3,
IR_RIIC0_EEI0,IR_RIIC0_RXI0,IR_RIIC0_TXI0,IR_RIIC0_TEI0
} enum_ir_t;

typedef enum enum_dtce {
DTCE_ICU_SWINT=27,
DTCE_CMT0_CMI0,
DTCE_CMT1_CMI1,
DTCE_GPTW0_GTCIA0=48,DTCE_GPTW0_GTCIB0,DTCE_GPTW0_GTCIC0,DTCE_GPTW0_GTCID0,DTCE_GPTW0_GTCIE0=53,DTCE_GPTW0_GTCIF0,DTCE_GPTW0_GTCIV0,DTCE_GPTW0_GTCIU0,
DTCE_ICU_IRQ0=64,DTCE_ICU_IRQ1,DTCE_ICU_IRQ2,DTCE_ICU_IRQ3,DTCE_ICU_IRQ4,DTCE_ICU_IRQ5,DTCE_ICU_IRQ6,DTCE_ICU_IRQ7,
DTCE_GPTW1_GTCIA1=98,DTCE_GPTW1_GTCIB1,DTCE_GPTW1_GTCIC1,DTCE_GPTW1_GTCID1,
DTCE_S12AD_S12ADI,DTCE_S12AD_GBADI,DTCE_S12AD_GCADI,
DTCE_S12AD1_S12ADI1,DTCE_S12AD1_GBADI1,DTCE_S12AD1_GCADI1,
DTCE_CMPC0_CMPC0,
DTCE_CMPC1_CMPC1,
DTCE_CMPC2_CMPC2,
DTCE_MTU0_TGIA0=114,DTCE_MTU0_TGIB0,DTCE_MTU0_TGIC0,DTCE_MTU0_TGID0,
DTCE_MTU1_TGIA1=121,DTCE_MTU1_TGIB1,
DTCE_MTU2_TGIA2=125,DTCE_MTU2_TGIB2,
DTCE_MTU3_TGIA3=129,DTCE_MTU3_TGIB3,DTCE_MTU3_TGIC3,DTCE_MTU3_TGID3,
DTCE_MTU4_TGIA4=134,DTCE_MTU4_TGIB4,DTCE_MTU4_TGIC4,DTCE_MTU4_TGID4,DTCE_MTU4_TCIV4,
DTCE_MTU5_TGIU5,DTCE_MTU5_TGIV5,DTCE_MTU5_TGIW5,
DTCE_TMR0_CMIA0=174,DTCE_TMR0_CMIB0,
DTCE_TMR1_CMIA1=177,DTCE_TMR1_CMIB1,
DTCE_TMR2_CMIA2=180,DTCE_TMR2_CMIB2,
DTCE_TMR3_CMIA3=183,DTCE_TMR3_CMIB3,
DTCE_GPTW1_GTCIE1=203,DTCE_GPTW1_GTCIF1,DTCE_GPTW1_GTCIV1,DTCE_GPTW1_GTCIU1,
DTCE_GPTW2_GTCIA2,DTCE_GPTW2_GTCIB2,DTCE_GPTW2_GTCIC2,DTCE_GPTW2_GTCID2,DTCE_GPTW2_GTCIE2=212,DTCE_GPTW2_GTCIF2,DTCE_GPTW2_GTCIV2,DTCE_GPTW2_GTCIU2,
DTCE_SCI1_RXI1=219,DTCE_SCI1_TXI1,
DTCE_SCI5_RXI5=223,DTCE_SCI5_TXI5,
DTCE_SCI6_RXI6=227,DTCE_SCI6_TXI6,
DTCE_SCI12_RXI12=239,DTCE_SCI12_TXI12,
DTCE_RIIC0_RXI0=247,DTCE_RIIC0_TXI0
} enum_dtce_t;

typedef enum enum_ier {
IER_BSC_BUSERR=0x02,
IER_FCU_FRDYI=0x02,
IER_ICU_SWINT=0x03,
IER_CMT0_CMI0=0x03,
IER_CMT1_CMI1=0x03,
IER_CAC_FERRF=0x04,IER_CAC_MENDF=0x04,IER_CAC_OVFF=0x04,
IER_POEG_POEGGAI=0x05,
IER_GPTW0_GTCIA0=0x06,IER_GPTW0_GTCIB0=0x06,IER_GPTW0_GTCIC0=0x06,IER_GPTW0_GTCID0=0x06,
IER_GPTW0_GDTE0=0x06,IER_GPTW0_GTCIE0=0x06,IER_GPTW0_GTCIF0=0x06,IER_GPTW0_GTCIV0=0x06,IER_GPTW0_GTCIU0=0x07,
IER_DOC_DOPCF=0x07,
IER_ICU_IRQ0=0x08,IER_ICU_IRQ1=0x08,IER_ICU_IRQ2=0x08,IER_ICU_IRQ3=0x08,IER_ICU_IRQ4=0x08,IER_ICU_IRQ5=0x08,IER_ICU_IRQ6=0x08,IER_ICU_IRQ7=0x08,
IER_LVD_LVD1=0x0B,IER_LVD_LVD2=0x0B,
IER_GPTW1_GTCIA1=0x0C,IER_GPTW1_GTCIB1=0x0C,IER_GPTW1_GTCIC1=0x0C,IER_GPTW1_GTCID1=0x0C,
IER_S12AD_S12ADI=0x0C,IER_S12AD_GBADI=0x0C,IER_S12AD_GCADI=0x0D,
IER_S12AD1_S12ADI1=0x0D,IER_S12AD1_GBADI1=0x0D,IER_S12AD1_GCADI1=0x0D,
IER_CMPC0_CMPC0=0x0D,
IER_CMPC1_CMPC1=0x0D,
IER_CMPC2_CMPC2=0x0D,
IER_MTU0_TGIA0=0x0E,IER_MTU0_TGIB0=0x0E,IER_MTU0_TGIC0=0x0E,IER_MTU0_TGID0=0x0E,IER_MTU0_TCIV0=0x0E,IER_MTU0_TGIE0=0x0E,IER_MTU0_TGIF0=0x0F,
IER_MTU1_TGIA1=0x0F,IER_MTU1_TGIB1=0x0F,IER_MTU1_TCIV1=0x0F,IER_MTU1_TCIU1=0x0F,
IER_MTU2_TGIA2=0x0F,IER_MTU2_TGIB2=0x0F,IER_MTU2_TCIV2=0x0F,IER_MTU2_TCIU2=0x10,
IER_MTU3_TGIA3=0x10,IER_MTU3_TGIB3=0x10,IER_MTU3_TGIC3=0x10,IER_MTU3_TGID3=0x10,IER_MTU3_TCIV3=0x10,
IER_MTU4_TGIA4=0x10,IER_MTU4_TGIB4=0x10,IER_MTU4_TGIC4=0x11,IER_MTU4_TGID4=0x11,IER_MTU4_TCIV4=0x11,
IER_MTU5_TGIU5=0x11,IER_MTU5_TGIV5=0x11,IER_MTU5_TGIW5=0x11,
IER_POE_OEI1=0x15,IER_POE_OEI3=0x15,IER_POE_OEI4=0x15,IER_POE_OEI5=0x15,
IER_TMR0_CMIA0=0x15,IER_TMR0_CMIB0=0x15,IER_TMR0_OVI0=0x16,
IER_TMR1_CMIA1=0x16,IER_TMR1_CMIB1=0x16,IER_TMR1_OVI1=0x16,
IER_TMR2_CMIA2=0x16,IER_TMR2_CMIB2=0x16,IER_TMR2_OVI2=0x16,
IER_TMR3_CMIA3=0x16,IER_TMR3_CMIB3=0x17,IER_TMR3_OVI3=0x17,
IER_GPTW1_GDTE1=0x19,IER_GPTW1_GTCIE1=0x19,IER_GPTW1_GTCIF1=0x19,IER_GPTW1_GTCIV1=0x19,IER_GPTW1_GTCIU1=0x19,
IER_GPTW2_GTCIA2=0x19,IER_GPTW2_GTCIB2=0x1A,IER_GPTW2_GTCIC2=0x1A,IER_GPTW2_GTCID2=0x1A,
IER_GPTW2_GDTE2=0x1A,IER_GPTW2_GTCIE2=0x1A,IER_GPTW2_GTCIF2=0x1A,IER_GPTW2_GTCIV2=0x1A,IER_GPTW2_GTCIU2=0x1A,
IER_SCI1_ERI1=0x1B,IER_SCI1_RXI1=0x1B,IER_SCI1_TXI1=0x1B,IER_SCI1_TEI1=0x1B,
IER_SCI5_ERI5=0x1B,IER_SCI5_RXI5=0x1B,IER_SCI5_TXI5=0x1C,IER_SCI5_TEI5=0x1C,
IER_SCI6_ERI6=0x1C,IER_SCI6_RXI6=0x1C,IER_SCI6_TXI6=0x1C,IER_SCI6_TEI6=0x1C,
IER_SCI12_ERI12=0x1D,IER_SCI12_RXI12=0x1D,IER_SCI12_TXI12=0x1E,IER_SCI12_TEI12=0x1E,IER_SCI12_SCIX0=0x1E,IER_SCI12_SCIX1=0x1E,IER_SCI12_SCIX2=0x1E,IER_SCI12_SCIX3=0x1E,
IER_RIIC0_EEI0=0x1E,IER_RIIC0_RXI0=0x1E,IER_RIIC0_TXI0=0x1F,IER_RIIC0_TEI0=0x1F
} enum_ier_t;

typedef enum enum_ipr {
IPR_BSC_BUSERR=0,
IPR_FCU_FRDYI=2,
IPR_ICU_SWINT=3,
IPR_CMT0_CMI0=4,
IPR_CMT1_CMI1=5,
IPR_CAC_FERRF=32,IPR_CAC_MENDF=33,IPR_CAC_OVFF=34,
IPR_POEG_POEGGAI=40,
IPR_GPTW0_GTCIA0=48,IPR_GPTW0_GTCIB0=49,IPR_GPTW0_GTCIC0=50,IPR_GPTW0_GTCID0=51,
IPR_GPTW0_GDTE0=52,IPR_GPTW0_GTCIE0=53,IPR_GPTW0_GTCIF0=54,IPR_GPTW0_GTCIV0=55,IPR_GPTW0_GTCIU0=56,
IPR_DOC_DOPCF=57,
IPR_ICU_IRQ0=64,IPR_ICU_IRQ1=65,IPR_ICU_IRQ2=66,IPR_ICU_IRQ3=67,IPR_ICU_IRQ4=68,IPR_ICU_IRQ5=69,IPR_ICU_IRQ6=70,IPR_ICU_IRQ7=71,
IPR_LVD_LVD1=88,IPR_LVD_LVD2=89,
IPR_GPTW1_GTCIA1=98,IPR_GPTW1_GTCIB1=99,IPR_GPTW1_GTCIC1=100,IPR_GPTW1_GTCID1=101,
IPR_S12AD_S12ADI=102,IPR_S12AD_GBADI=103,IPR_S12AD_GCADI=104,
IPR_S12AD1_S12ADI1=105,IPR_S12AD1_GBADI1=106,IPR_S12AD1_GCADI1=107,
IPR_CMPC0_CMPC0=108,
IPR_CMPC1_CMPC1=109,
IPR_CMPC2_CMPC2=110,
IPR_MTU0_TGIA0=114,IPR_MTU0_TGIB0=114,IPR_MTU0_TGIC0=114,IPR_MTU0_TGID0=114,IPR_MTU0_TCIV0=118,IPR_MTU0_TGIE0=118,IPR_MTU0_TGIF0=118,
IPR_MTU1_TGIA1=121,IPR_MTU1_TGIB1=121,IPR_MTU1_TCIV1=123,IPR_MTU1_TCIU1=123,
IPR_MTU2_TGIA2=125,IPR_MTU2_TGIB2=125,IPR_MTU2_TCIV2=127,IPR_MTU2_TCIU2=127,
IPR_MTU3_TGIA3=129,IPR_MTU3_TGIB3=129,IPR_MTU3_TGIC3=129,IPR_MTU3_TGID3=129,IPR_MTU3_TCIV3=133,
IPR_MTU4_TGIA4=134,IPR_MTU4_TGIB4=134,IPR_MTU4_TGIC4=134,IPR_MTU4_TGID4=134,IPR_MTU4_TCIV4=138,
IPR_MTU5_TGIU5=139,IPR_MTU5_TGIV5=139,IPR_MTU5_TGIW5=139,
IPR_POE_OEI1=168,IPR_POE_OEI3=168,IPR_POE_OEI4=168,IPR_POE_OEI5=168,
IPR_TMR0_CMIA0=174,IPR_TMR0_CMIB0=174,IPR_TMR0_OVI0=174,
IPR_TMR1_CMIA1=177,IPR_TMR1_CMIB1=177,IPR_TMR1_OVI1=177,
IPR_TMR2_CMIA2=180,IPR_TMR2_CMIB2=180,IPR_TMR2_OVI2=180,
IPR_TMR3_CMIA3=183,IPR_TMR3_CMIB3=183,IPR_TMR3_OVI3=183,
IPR_GPTW1_GDTE1=202,IPR_GPTW1_GTCIE1=203,IPR_GPTW1_GTCIF1=204,IPR_GPTW1_GTCIV1=205,IPR_GPTW1_GTCIU1=206,
IPR_GPTW2_GTCIA2=207,IPR_GPTW2_GTCIB2=208,IPR_GPTW2_GTCIC2=209,IPR_GPTW2_GTCID2=210,
IPR_GPTW2_GDTE2=211,IPR_GPTW2_GTCIE2=212,IPR_GPTW2_GTCIF2=213,IPR_GPTW2_GTCIV2=214,IPR_GPTW2_GTCIU2=215,
IPR_SCI1_ERI1=218,IPR_SCI1_RXI1=218,IPR_SCI1_TXI1=218,IPR_SCI1_TEI1=218,
IPR_SCI5_ERI5=222,IPR_SCI5_RXI5=222,IPR_SCI5_TXI5=222,IPR_SCI5_TEI5=222,
IPR_SCI6_ERI6=226,IPR_SCI6_RXI6=226,IPR_SCI6_TXI6=226,IPR_SCI6_TEI6=226,
IPR_SCI12_ERI12=238,IPR_SCI12_RXI12=238,IPR_SCI12_TXI12=238,IPR_SCI12_TEI12=238,IPR_SCI12_SCIX0=242,IPR_SCI12_SCIX1=243,IPR_SCI12_SCIX2=244,IPR_SCI12_SCIX3=245,
IPR_RIIC0_EEI0=246,IPR_RIIC0_RXI0=247,IPR_RIIC0_TXI0=248,IPR_RIIC0_TEI0=249,
IPR_BSC_=0,
IPR_FCU_=2,
IPR_CMT0_=4,
IPR_CMT1_=5,
IPR_POEG_=40,
IPR_DOC_=57,
IPR_CMPC0_=108,
IPR_CMPC1_=109,
IPR_CMPC2_=110,
IPR_MTU1_TGI=121,
IPR_MTU1_TCI=123,
IPR_MTU2_TGI=125,
IPR_MTU2_TCI=127,
IPR_MTU3_TGI=129,
IPR_MTU4_TGI=134,
IPR_MTU5_=139,
IPR_MTU5_TGI=139,
IPR_POE_=168,
IPR_POE_OEI=168,
IPR_TMR0_=174,
IPR_TMR1_=177,
IPR_TMR2_=180,
IPR_TMR3_=183,
IPR_SCI1_=218,
IPR_SCI5_=222,
IPR_SCI6_=226
} enum_ipr_t;


#pragma pack(4)


typedef struct st_bsc {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char STSCLR : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char STSCLR : 1;
#endif
	} BIT;
	} BERCLR;
	char           wk0[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IGAEN : 1;
			unsigned char TOEN : 1;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char TOEN : 1;
			unsigned char IGAEN : 1;
#endif
	} BIT;
	} BEREN;
	char           wk1[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IA : 1;
			unsigned char TO : 1;
			unsigned char  : 2;
			unsigned char MST : 3;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char MST : 3;
			unsigned char  : 2;
			unsigned char TO : 1;
			unsigned char IA : 1;
#endif
	} BIT;
	} BERSR1;
	char           wk2[1];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 3;
			unsigned short ADDR : 13;
#else
			unsigned short ADDR : 13;
			unsigned short  : 3;
#endif
	} BIT;
	} BERSR2;
	char           wk3[4];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short BPRA : 2;
			unsigned short BPRO : 2;
			unsigned short BPIB : 2;
			unsigned short BPGB : 2;
			unsigned short  : 2;
			unsigned short BPFB : 2;
			unsigned short  : 4;
#else
			unsigned short  : 4;
			unsigned short BPFB : 2;
			unsigned short  : 2;
			unsigned short BPGB : 2;
			unsigned short BPIB : 2;
			unsigned short BPRO : 2;
			unsigned short BPRA : 2;
#endif
	} BIT;
	} BUSPRI;
} st_bsc_t;

typedef struct st_cac {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CFME : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char CFME : 1;
#endif
	} BIT;
	} CACR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CACREFE : 1;
			unsigned char FMCS : 3;
			unsigned char TCSS : 2;
			unsigned char EDGES : 2;
#else
			unsigned char EDGES : 2;
			unsigned char TCSS : 2;
			unsigned char FMCS : 3;
			unsigned char CACREFE : 1;
#endif
	} BIT;
	} CACR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char RPS : 1;
			unsigned char RSCS : 3;
			unsigned char RCDS : 2;
			unsigned char DFS : 2;
#else
			unsigned char DFS : 2;
			unsigned char RCDS : 2;
			unsigned char RSCS : 3;
			unsigned char RPS : 1;
#endif
	} BIT;
	} CACR2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char FERRIE : 1;
			unsigned char MENDIE : 1;
			unsigned char OVFIE : 1;
			unsigned char  : 1;
			unsigned char FERRFCL : 1;
			unsigned char MENDFCL : 1;
			unsigned char OVFFCL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char OVFFCL : 1;
			unsigned char MENDFCL : 1;
			unsigned char FERRFCL : 1;
			unsigned char  : 1;
			unsigned char OVFIE : 1;
			unsigned char MENDIE : 1;
			unsigned char FERRIE : 1;
#endif
	} BIT;
	} CAICR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char FERRF : 1;
			unsigned char MENDF : 1;
			unsigned char OVFF : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char OVFF : 1;
			unsigned char MENDF : 1;
			unsigned char FERRF : 1;
#endif
	} BIT;
	} CASTR;
	char           wk0[1];
	unsigned short CAULVR;
	unsigned short CALLVR;
	unsigned short CACNTBR;
} st_cac_t;

typedef struct st_cmpc {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CINV : 1;
			unsigned char COE : 1;
			unsigned char  : 1;
			unsigned char CEG : 2;
			unsigned char NFE : 1;
			unsigned char  : 1;
			unsigned char HCMPON : 1;
#else
			unsigned char HCMPON : 1;
			unsigned char  : 1;
			unsigned char NFE : 1;
			unsigned char CEG : 2;
			unsigned char  : 1;
			unsigned char COE : 1;
			unsigned char CINV : 1;
#endif
	} BIT;
	} CMPCTL;
	char           wk0[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CMPSEL : 4;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char CMPSEL : 4;
#endif
	} BIT;
	} CMPSEL0;
	char           wk1[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CVRS : 2;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char CVRS : 2;
#endif
	} BIT;
	} CMPSEL1;
	char           wk2[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CMPMON0 : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char CMPMON0 : 1;
#endif
	} BIT;
	} CMPMON;
	char           wk3[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CPOE : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char CPOE : 1;
#endif
	} BIT;
	} CMPIOC;
	char           wk4[7];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CNFS : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char CNFS : 1;
#endif
	} BIT;
	} CMPCTL2;
	char           wk5[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFSS : 3;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char NFSS : 3;
#endif
	} BIT;
	} CMPNFS;
} st_cmpc_t;

typedef struct st_cmt {
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short STR0 : 1;
			unsigned short STR1 : 1;
			unsigned short  : 14;
#else
			unsigned short  : 14;
			unsigned short STR1 : 1;
			unsigned short STR0 : 1;
#endif
	} BIT;
	} CMSTR0;
} st_cmt_t;

typedef struct st_cmt0 {
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short CKS : 2;
			unsigned short  : 4;
			unsigned short CMIE : 1;
			unsigned short  : 9;
#else
			unsigned short  : 9;
			unsigned short CMIE : 1;
			unsigned short  : 4;
			unsigned short CKS : 2;
#endif
	} BIT;
	} CMCR;
	unsigned short CMCNT;
	unsigned short CMCOR;
} st_cmt0_t;

typedef struct st_crc {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char GPS : 3;
			unsigned char  : 3;
			unsigned char LMS : 1;
			unsigned char DORCLR : 1;
#else
			unsigned char DORCLR : 1;
			unsigned char LMS : 1;
			unsigned char  : 3;
			unsigned char GPS : 3;
#endif
	} BIT;
	} CRCCR;
	char           wk0[3];
	union {
		unsigned long LONG;
		unsigned char BYTE;
	} CRCDIR;
	union {
		unsigned long LONG;
		unsigned short WORD;
		unsigned char BYTE;
	} CRCDOR;
} st_crc_t;

typedef struct st_da {
	unsigned short DADR0;
	unsigned short DADR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 6;
			unsigned char DAOE0 : 1;
			unsigned char DAOE1 : 1;
#else
			unsigned char DAOE1 : 1;
			unsigned char DAOE0 : 1;
			unsigned char  : 6;
#endif
	} BIT;
	} DACR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char DPSEL : 1;
#else
			unsigned char DPSEL : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} DADPR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char DAADST : 1;
#else
			unsigned char DAADST : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} DAADSCR;
} st_da_t;

typedef struct st_doc {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char OMS : 2;
			unsigned char DCSEL : 1;
			unsigned char  : 1;
			unsigned char DOPCIE : 1;
			unsigned char DOPCF : 1;
			unsigned char DOPCFCL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char DOPCFCL : 1;
			unsigned char DOPCF : 1;
			unsigned char DOPCIE : 1;
			unsigned char  : 1;
			unsigned char DCSEL : 1;
			unsigned char OMS : 2;
#endif
	} BIT;
	} DOCR;
	char           wk0[1];
	unsigned short DODIR;
	unsigned short DODSR;
} st_doc_t;

typedef struct st_dtc {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 4;
			unsigned char RRS : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char RRS : 1;
			unsigned char  : 4;
#endif
	} BIT;
	} DTCCR;
	char           wk0[3];
	void          *DTCVBR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SHORT : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char SHORT : 1;
#endif
	} BIT;
	} DTCADMOD;
	char           wk1[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char DTCST : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char DTCST : 1;
#endif
	} BIT;
	} DTCST;
	char           wk2[1];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short VECN : 8;
			unsigned short  : 7;
			unsigned short ACT : 1;
#else
			unsigned short ACT : 1;
			unsigned short  : 7;
			unsigned short VECN : 8;
#endif
	} BIT;
	} DTCSTS;
	void          *DTCIBR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SQTFRL : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char SQTFRL : 1;
#endif
	} BIT;
	} DTCOR;
	char           wk3[1];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short VECN : 8;
			unsigned short  : 7;
			unsigned short ESPSEL : 1;
#else
			unsigned short ESPSEL : 1;
			unsigned short  : 7;
			unsigned short VECN : 8;
#endif
	} BIT;
	} DTCSQE;
	unsigned long  DTCDISP;
} st_dtc_t;

typedef struct st_flash {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char DFLEN : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char DFLEN : 1;
#endif
	} BIT;
	} DFLCTL;
	char           wk0[111];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 1;
			unsigned char FMS0 : 1;
			unsigned char  : 1;
			unsigned char RPDIS : 1;
			unsigned char FMS1 : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char FMS1 : 1;
			unsigned char RPDIS : 1;
			unsigned char  : 1;
			unsigned char FMS0 : 1;
			unsigned char  : 1;
#endif
	} BIT;
	} FPMCR;
	char           wk1[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char EXS : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char EXS : 1;
#endif
	} BIT;
	} FASR;
	char           wk2[3];
	unsigned short FSARL;
	char           wk3[6];
	unsigned short FSARH;
	char           wk4[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CMD : 4;
			unsigned char  : 2;
			unsigned char STOP : 1;
			unsigned char OPST : 1;
#else
			unsigned char OPST : 1;
			unsigned char STOP : 1;
			unsigned char  : 2;
			unsigned char CMD : 4;
#endif
	} BIT;
	} FCR;
	char           wk5[3];
	unsigned short FEARL;
	char           wk6[6];
	unsigned short FEARH;
	char           wk7[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char FRESET : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char FRESET : 1;
#endif
	} BIT;
	} FRESETR;
	char           wk8[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char ERERR : 1;
			unsigned char PRGERR : 1;
			unsigned char  : 1;
			unsigned char BCERR : 1;
			unsigned char ILGLERR : 1;
			unsigned char EILGLERR : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char EILGLERR : 1;
			unsigned char ILGLERR : 1;
			unsigned char BCERR : 1;
			unsigned char  : 1;
			unsigned char PRGERR : 1;
			unsigned char ERERR : 1;
#endif
	} BIT;
	} FSTATR0;
	char           wk9[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 6;
			unsigned char FRDY : 1;
			unsigned char EXRDY : 1;
#else
			unsigned char EXRDY : 1;
			unsigned char FRDY : 1;
			unsigned char  : 6;
#endif
	} BIT;
	} FSTATR1;
	char           wk10[3];
	unsigned short FWB0;
	char           wk11[6];
	unsigned short FWB1;
	char           wk12[6];
	unsigned short FWB2;
	char           wk13[2];
	unsigned short FWB3;
	char           wk14[58];
	unsigned char  FPR;
	char           wk15[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PERR : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char PERR : 1;
#endif
	} BIT;
	} FPSR;
	char           wk16[59];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 8;
			unsigned short SASMF : 1;
			unsigned short  : 5;
			unsigned short AWPR : 1;
			unsigned short  : 1;
#else
			unsigned short  : 1;
			unsigned short AWPR : 1;
			unsigned short  : 5;
			unsigned short SASMF : 1;
			unsigned short  : 8;
#endif
	} BIT;
	} FSCMR;
	char           wk17[6];
	unsigned short FAWSMR;
	char           wk18[6];
	unsigned short FAWEMR;
	char           wk19[6];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PCKA : 6;
			unsigned char SAS : 2;
#else
			unsigned char SAS : 2;
			unsigned char PCKA : 6;
#endif
	} BIT;
	} FISR;
	char           wk20[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CMD : 3;
			unsigned char  : 4;
			unsigned char OPST : 1;
#else
			unsigned char OPST : 1;
			unsigned char  : 4;
			unsigned char CMD : 3;
#endif
	} BIT;
	} FEXCR;
	char           wk21[3];
	unsigned short FEAML;
	char           wk22[6];
	unsigned short FEAMH;
	char           wk23[358];
	unsigned long  UIDR0;
	unsigned long  UIDR1;
	unsigned long  UIDR2;
	unsigned long  UIDR3;
	char           wk24[15440];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short FENTRY0 : 1;
			unsigned short  : 6;
			unsigned short FENTRYD : 1;
			unsigned short FEKEY : 8;
#else
			unsigned short FEKEY : 8;
			unsigned short FENTRYD : 1;
			unsigned short  : 6;
			unsigned short FENTRY0 : 1;
#endif
	} BIT;
	} FENTRYR;
	char           wk25[14];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short MEMWAIT : 1;
			unsigned short  : 7;
			unsigned short MEKEY : 8;
#else
			unsigned short MEKEY : 8;
			unsigned short  : 7;
			unsigned short MEMWAIT : 1;
#endif
	} BIT;
	} MEMWAITR;
} st_flash_t;

typedef struct st_gptw {
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long WP : 1;
			unsigned long STRWP : 1;
			unsigned long STPWP : 1;
			unsigned long CLRWP : 1;
			unsigned long CMNWP : 1;
			unsigned long  : 3;
			unsigned long PRKEY : 8;
			unsigned long  : 16;
#else
			unsigned long  : 16;
			unsigned long PRKEY : 8;
			unsigned long  : 3;
			unsigned long CMNWP : 1;
			unsigned long CLRWP : 1;
			unsigned long STPWP : 1;
			unsigned long STRWP : 1;
			unsigned long WP : 1;
#endif
	} BIT;
	} GTWP;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long CSTRT0 : 1;
			unsigned long CSTRT1 : 1;
			unsigned long CSTRT2 : 1;
			unsigned long  : 29;
#else
			unsigned long  : 29;
			unsigned long CSTRT2 : 1;
			unsigned long CSTRT1 : 1;
			unsigned long CSTRT0 : 1;
#endif
	} BIT;
	} GTSTR;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long CSTOP0 : 1;
			unsigned long CSTOP1 : 1;
			unsigned long CSTOP2 : 1;
			unsigned long  : 29;
#else
			unsigned long  : 29;
			unsigned long CSTOP2 : 1;
			unsigned long CSTOP1 : 1;
			unsigned long CSTOP0 : 1;
#endif
	} BIT;
	} GTSTP;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long CCLR0 : 1;
			unsigned long CCLR1 : 1;
			unsigned long CCLR2 : 1;
			unsigned long  : 29;
#else
			unsigned long  : 29;
			unsigned long CCLR2 : 1;
			unsigned long CCLR1 : 1;
			unsigned long CCLR0 : 1;
#endif
	} BIT;
	} GTCLR;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long SSGTRGAR : 1;
			unsigned long SSGTRGAF : 1;
			unsigned long  : 6;
			unsigned long SSCARBL : 1;
			unsigned long SSCARBH : 1;
			unsigned long SSCAFBL : 1;
			unsigned long SSCAFBH : 1;
			unsigned long SSCBRAL : 1;
			unsigned long SSCBRAH : 1;
			unsigned long SSCBFAL : 1;
			unsigned long SSCBFAH : 1;
			unsigned long SSMTU0 : 1;
			unsigned long SSMTU4 : 1;
			unsigned long  : 13;
			unsigned long CSTRT : 1;
#else
			unsigned long CSTRT : 1;
			unsigned long  : 13;
			unsigned long SSMTU4 : 1;
			unsigned long SSMTU0 : 1;
			unsigned long SSCBFAH : 1;
			unsigned long SSCBFAL : 1;
			unsigned long SSCBRAH : 1;
			unsigned long SSCBRAL : 1;
			unsigned long SSCAFBH : 1;
			unsigned long SSCAFBL : 1;
			unsigned long SSCARBH : 1;
			unsigned long SSCARBL : 1;
			unsigned long  : 6;
			unsigned long SSGTRGAF : 1;
			unsigned long SSGTRGAR : 1;
#endif
	} BIT;
	} GTSSR;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long PSGTRGAR : 1;
			unsigned long PSGTRGAF : 1;
			unsigned long  : 6;
			unsigned long PSCARBL : 1;
			unsigned long PSCARBH : 1;
			unsigned long PSCAFBL : 1;
			unsigned long PSCAFBH : 1;
			unsigned long PSCBRAL : 1;
			unsigned long PSCBRAH : 1;
			unsigned long PSCBFAL : 1;
			unsigned long PSCBFAH : 1;
			unsigned long  : 15;
			unsigned long CSTOP : 1;
#else
			unsigned long CSTOP : 1;
			unsigned long  : 15;
			unsigned long PSCBFAH : 1;
			unsigned long PSCBFAL : 1;
			unsigned long PSCBRAH : 1;
			unsigned long PSCBRAL : 1;
			unsigned long PSCAFBH : 1;
			unsigned long PSCAFBL : 1;
			unsigned long PSCARBH : 1;
			unsigned long PSCARBL : 1;
			unsigned long  : 6;
			unsigned long PSGTRGAF : 1;
			unsigned long PSGTRGAR : 1;
#endif
	} BIT;
	} GTPSR;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long CSGTRGAR : 1;
			unsigned long CSGTRGAF : 1;
			unsigned long  : 6;
			unsigned long CSCARBL : 1;
			unsigned long CSCARBH : 1;
			unsigned long CSCAFBL : 1;
			unsigned long CSCAFBH : 1;
			unsigned long CSCBRAL : 1;
			unsigned long CSCBRAH : 1;
			unsigned long CSCBFAL : 1;
			unsigned long CSCBFAH : 1;
			unsigned long  : 8;
			unsigned long CSCMSC : 3;
			unsigned long  : 4;
			unsigned long CCLR : 1;
#else
			unsigned long CCLR : 1;
			unsigned long  : 4;
			unsigned long CSCMSC : 3;
			unsigned long  : 8;
			unsigned long CSCBFAH : 1;
			unsigned long CSCBFAL : 1;
			unsigned long CSCBRAH : 1;
			unsigned long CSCBRAL : 1;
			unsigned long CSCAFBH : 1;
			unsigned long CSCAFBL : 1;
			unsigned long CSCARBH : 1;
			unsigned long CSCARBL : 1;
			unsigned long  : 6;
			unsigned long CSGTRGAF : 1;
			unsigned long CSGTRGAR : 1;
#endif
	} BIT;
	} GTCSR;
	char           wk0[8];
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long ASGTRGAR : 1;
			unsigned long ASGTRGAF : 1;
			unsigned long  : 6;
			unsigned long ASCARBL : 1;
			unsigned long ASCARBH : 1;
			unsigned long ASCAFBL : 1;
			unsigned long ASCAFBH : 1;
			unsigned long ASCBRAL : 1;
			unsigned long ASCBRAH : 1;
			unsigned long ASCBFAL : 1;
			unsigned long ASCBFAH : 1;
			unsigned long  : 8;
			unsigned long ASOC : 1;
			unsigned long  : 7;
#else
			unsigned long  : 7;
			unsigned long ASOC : 1;
			unsigned long  : 8;
			unsigned long ASCBFAH : 1;
			unsigned long ASCBFAL : 1;
			unsigned long ASCBRAH : 1;
			unsigned long ASCBRAL : 1;
			unsigned long ASCAFBH : 1;
			unsigned long ASCAFBL : 1;
			unsigned long ASCARBH : 1;
			unsigned long ASCARBL : 1;
			unsigned long  : 6;
			unsigned long ASGTRGAF : 1;
			unsigned long ASGTRGAR : 1;
#endif
	} BIT;
	} GTICASR;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long BSGTRGAR : 1;
			unsigned long BSGTRGAF : 1;
			unsigned long  : 6;
			unsigned long BSCARBL : 1;
			unsigned long BSCARBH : 1;
			unsigned long BSCAFBL : 1;
			unsigned long BSCAFBH : 1;
			unsigned long BSCBRAL : 1;
			unsigned long BSCBRAH : 1;
			unsigned long BSCBFAL : 1;
			unsigned long BSCBFAH : 1;
			unsigned long  : 8;
			unsigned long BSOC : 1;
			unsigned long  : 7;
#else
			unsigned long  : 7;
			unsigned long BSOC : 1;
			unsigned long  : 8;
			unsigned long BSCBFAH : 1;
			unsigned long BSCBFAL : 1;
			unsigned long BSCBRAH : 1;
			unsigned long BSCBRAL : 1;
			unsigned long BSCAFBH : 1;
			unsigned long BSCAFBL : 1;
			unsigned long BSCARBH : 1;
			unsigned long BSCARBL : 1;
			unsigned long  : 6;
			unsigned long BSGTRGAF : 1;
			unsigned long BSGTRGAR : 1;
#endif
	} BIT;
	} GTICBSR;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long CST : 1;
			unsigned long  : 3;
			unsigned long AINV : 1;
			unsigned long BINV : 1;
			unsigned long  : 2;
			unsigned long ICDS : 1;
			unsigned long SCGTIOC : 1;
			unsigned long SSCGRP : 2;
			unsigned long  : 3;
			unsigned long SSCEN : 1;
			unsigned long MD : 3;
			unsigned long  : 4;
			unsigned long TPCS : 4;
			unsigned long  : 5;
#else
			unsigned long  : 5;
			unsigned long TPCS : 4;
			unsigned long  : 4;
			unsigned long MD : 3;
			unsigned long SSCEN : 1;
			unsigned long  : 3;
			unsigned long SSCGRP : 2;
			unsigned long SCGTIOC : 1;
			unsigned long ICDS : 1;
			unsigned long  : 2;
			unsigned long BINV : 1;
			unsigned long AINV : 1;
			unsigned long  : 3;
			unsigned long CST : 1;
#endif
	} BIT;
	} GTCR;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long UD : 1;
			unsigned long UDF : 1;
			unsigned long  : 14;
			unsigned long OADTY : 2;
			unsigned long OADTYF : 1;
			unsigned long OADTYR : 1;
			unsigned long  : 4;
			unsigned long OBDTY : 2;
			unsigned long OBDTYF : 1;
			unsigned long OBDTYR : 1;
			unsigned long OABDTYT : 1;
			unsigned long  : 3;
#else
			unsigned long  : 3;
			unsigned long OABDTYT : 1;
			unsigned long OBDTYR : 1;
			unsigned long OBDTYF : 1;
			unsigned long OBDTY : 2;
			unsigned long  : 4;
			unsigned long OADTYR : 1;
			unsigned long OADTYF : 1;
			unsigned long OADTY : 2;
			unsigned long  : 14;
			unsigned long UDF : 1;
			unsigned long UD : 1;
#endif
	} BIT;
	} GTUDDTYC;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long GTIOA : 5;
			unsigned long  : 1;
			unsigned long OADFLT : 1;
			unsigned long OAHLD : 1;
			unsigned long OAE : 1;
			unsigned long OADF : 2;
			unsigned long  : 1;
			unsigned long PSYE : 1;
			unsigned long NFAEN : 1;
			unsigned long NFCSA : 2;
			unsigned long GTIOB : 5;
			unsigned long  : 1;
			unsigned long OBDFLT : 1;
			unsigned long OBHLD : 1;
			unsigned long OBE : 1;
			unsigned long OBDF : 2;
			unsigned long  : 2;
			unsigned long NFBEN : 1;
			unsigned long NFCSB : 2;
#else
			unsigned long NFCSB : 2;
			unsigned long NFBEN : 1;
			unsigned long  : 2;
			unsigned long OBDF : 2;
			unsigned long OBE : 1;
			unsigned long OBHLD : 1;
			unsigned long OBDFLT : 1;
			unsigned long  : 1;
			unsigned long GTIOB : 5;
			unsigned long NFCSA : 2;
			unsigned long NFAEN : 1;
			unsigned long PSYE : 1;
			unsigned long  : 1;
			unsigned long OADF : 2;
			unsigned long OAE : 1;
			unsigned long OAHLD : 1;
			unsigned long OADFLT : 1;
			unsigned long  : 1;
			unsigned long GTIOA : 5;
#endif
	} BIT;
	} GTIOR;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long GTINTA : 1;
			unsigned long GTINTB : 1;
			unsigned long GTINTC : 1;
			unsigned long GTINTD : 1;
			unsigned long GTINTE : 1;
			unsigned long GTINTF : 1;
			unsigned long GTINTPR : 2;
			unsigned long SCFA : 1;
			unsigned long SCFB : 1;
			unsigned long SCFC : 1;
			unsigned long SCFD : 1;
			unsigned long SCFE : 1;
			unsigned long SCFF : 1;
			unsigned long SCFPO : 1;
			unsigned long SCFPU : 1;
			unsigned long ADTRAUEN : 1;
			unsigned long ADTRADEN : 1;
			unsigned long ADTRBUEN : 1;
			unsigned long ADTRBDEN : 1;
			unsigned long  : 8;
			unsigned long GRPDTE : 1;
			unsigned long GRPABH : 1;
			unsigned long GRPABL : 1;
			unsigned long  : 1;
#else
			unsigned long  : 1;
			unsigned long GRPABL : 1;
			unsigned long GRPABH : 1;
			unsigned long GRPDTE : 1;
			unsigned long  : 8;
			unsigned long ADTRBDEN : 1;
			unsigned long ADTRBUEN : 1;
			unsigned long ADTRADEN : 1;
			unsigned long ADTRAUEN : 1;
			unsigned long SCFPU : 1;
			unsigned long SCFPO : 1;
			unsigned long SCFF : 1;
			unsigned long SCFE : 1;
			unsigned long SCFD : 1;
			unsigned long SCFC : 1;
			unsigned long SCFB : 1;
			unsigned long SCFA : 1;
			unsigned long GTINTPR : 2;
			unsigned long GTINTF : 1;
			unsigned long GTINTE : 1;
			unsigned long GTINTD : 1;
			unsigned long GTINTC : 1;
			unsigned long GTINTB : 1;
			unsigned long GTINTA : 1;
#endif
	} BIT;
	} GTINTAD;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long TCFA : 1;
			unsigned long TCFB : 1;
			unsigned long TCFC : 1;
			unsigned long TCFD : 1;
			unsigned long TCFE : 1;
			unsigned long TCFF : 1;
			unsigned long TCFPO : 1;
			unsigned long TCFPU : 1;
			unsigned long ITCNT : 3;
			unsigned long  : 4;
			unsigned long TUCF : 1;
			unsigned long ADTRAUF : 1;
			unsigned long ADTRADF : 1;
			unsigned long ADTRBUF : 1;
			unsigned long ADTRBDF : 1;
			unsigned long  : 4;
			unsigned long ODF : 1;
			unsigned long  : 3;
			unsigned long DTEF : 1;
			unsigned long OABHF : 1;
			unsigned long OABLF : 1;
			unsigned long  : 1;
#else
			unsigned long  : 1;
			unsigned long OABLF : 1;
			unsigned long OABHF : 1;
			unsigned long DTEF : 1;
			unsigned long  : 3;
			unsigned long ODF : 1;
			unsigned long  : 4;
			unsigned long ADTRBDF : 1;
			unsigned long ADTRBUF : 1;
			unsigned long ADTRADF : 1;
			unsigned long ADTRAUF : 1;
			unsigned long TUCF : 1;
			unsigned long  : 4;
			unsigned long ITCNT : 3;
			unsigned long TCFPU : 1;
			unsigned long TCFPO : 1;
			unsigned long TCFF : 1;
			unsigned long TCFE : 1;
			unsigned long TCFD : 1;
			unsigned long TCFC : 1;
			unsigned long TCFB : 1;
			unsigned long TCFA : 1;
#endif
	} BIT;
	} GTST;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long BD : 4;
			unsigned long  : 4;
			unsigned long DBRTECA : 1;
			unsigned long DBRTSCA : 1;
			unsigned long DBRTECB : 1;
			unsigned long DBRTSCB : 1;
			unsigned long DBRTEADA : 1;
			unsigned long DBRTSADA : 1;
			unsigned long DBRTEADB : 1;
			unsigned long DBRTSADB : 1;
			unsigned long CCRA : 2;
			unsigned long CCRB : 2;
			unsigned long PR : 2;
			unsigned long CCRSWT : 1;
			unsigned long  : 1;
			unsigned long ADTTA : 2;
			unsigned long ADTDA : 1;
			unsigned long  : 1;
			unsigned long ADTTB : 2;
			unsigned long ADTDB : 1;
			unsigned long  : 1;
#else
			unsigned long  : 1;
			unsigned long ADTDB : 1;
			unsigned long ADTTB : 2;
			unsigned long  : 1;
			unsigned long ADTDA : 1;
			unsigned long ADTTA : 2;
			unsigned long  : 1;
			unsigned long CCRSWT : 1;
			unsigned long PR : 2;
			unsigned long CCRB : 2;
			unsigned long CCRA : 2;
			unsigned long DBRTSADB : 1;
			unsigned long DBRTEADB : 1;
			unsigned long DBRTSADA : 1;
			unsigned long DBRTEADA : 1;
			unsigned long DBRTSCB : 1;
			unsigned long DBRTECB : 1;
			unsigned long DBRTSCA : 1;
			unsigned long DBRTECA : 1;
			unsigned long  : 4;
			unsigned long BD : 4;
#endif
	} BIT;
	} GTBER;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long ITLA : 1;
			unsigned long ITLB : 1;
			unsigned long ITLC : 1;
			unsigned long ITLD : 1;
			unsigned long ITLE : 1;
			unsigned long ITLF : 1;
			unsigned long IVTC : 2;
			unsigned long IVTT : 3;
			unsigned long  : 1;
			unsigned long ADTAL : 1;
			unsigned long  : 1;
			unsigned long ADTBL : 1;
			unsigned long  : 17;
#else
			unsigned long  : 17;
			unsigned long ADTBL : 1;
			unsigned long  : 1;
			unsigned long ADTAL : 1;
			unsigned long  : 1;
			unsigned long IVTT : 3;
			unsigned long IVTC : 2;
			unsigned long ITLF : 1;
			unsigned long ITLE : 1;
			unsigned long ITLD : 1;
			unsigned long ITLC : 1;
			unsigned long ITLB : 1;
			unsigned long ITLA : 1;
#endif
	} BIT;
	} GTITC;
	unsigned long  GTCNT;
	unsigned long  GTCCRA;
	unsigned long  GTCCRB;
	unsigned long  GTCCRC;
	unsigned long  GTCCRE;
	unsigned long  GTCCRD;
	unsigned long  GTCCRF;
	unsigned long  GTPR;
	unsigned long  GTPBR;
	unsigned long  GTPDBR;
	unsigned long  GTADTRA;
	unsigned long  GTADTBRA;
	unsigned long  GTADTDBRA;
	unsigned long  GTADTRB;
	unsigned long  GTADTBRB;
	unsigned long  GTADTDBRB;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long TDE : 1;
			unsigned long  : 3;
			unsigned long TDBUE : 1;
			unsigned long TDBDE : 1;
			unsigned long  : 2;
			unsigned long TDFER : 1;
			unsigned long  : 23;
#else
			unsigned long  : 23;
			unsigned long TDFER : 1;
			unsigned long  : 2;
			unsigned long TDBDE : 1;
			unsigned long TDBUE : 1;
			unsigned long  : 3;
			unsigned long TDE : 1;
#endif
	} BIT;
	} GTDTCR;
	unsigned long  GTDVU;
	unsigned long  GTDVD;
	unsigned long  GTDBU;
	unsigned long  GTDBD;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long SOS : 2;
			unsigned long  : 30;
#else
			unsigned long  : 30;
			unsigned long SOS : 2;
#endif
	} BIT;
	} GTSOS;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long SOTR : 1;
			unsigned long  : 31;
#else
			unsigned long  : 31;
			unsigned long SOTR : 1;
#endif
	} BIT;
	} GTSOTR;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long ADSMS0 : 2;
			unsigned long  : 6;
			unsigned long ADSMEN0 : 1;
			unsigned long  : 7;
			unsigned long ADSMS1 : 2;
			unsigned long  : 6;
			unsigned long ADSMEN1 : 1;
			unsigned long  : 7;
#else
			unsigned long  : 7;
			unsigned long ADSMEN1 : 1;
			unsigned long  : 6;
			unsigned long ADSMS1 : 2;
			unsigned long  : 7;
			unsigned long ADSMEN0 : 1;
			unsigned long  : 6;
			unsigned long ADSMS0 : 2;
#endif
	} BIT;
	} GTADSMR;
	char           wk1[40];
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long SECSEL0 : 1;
			unsigned long SECSEL1 : 1;
			unsigned long SECSEL2 : 1;
			unsigned long  : 29;
#else
			unsigned long  : 29;
			unsigned long SECSEL2 : 1;
			unsigned long SECSEL1 : 1;
			unsigned long SECSEL0 : 1;
#endif
	} BIT;
	} GTSECSR;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long SBDCE : 1;
			unsigned long SBDPE : 1;
			unsigned long SBDAE : 1;
			unsigned long SBDDE : 1;
			unsigned long  : 4;
			unsigned long SBDCD : 1;
			unsigned long SBDPD : 1;
			unsigned long SBDAD : 1;
			unsigned long SBDDD : 1;
			unsigned long  : 5;
			unsigned long SSCE : 1;
			unsigned long  : 7;
			unsigned long SSCD : 1;
			unsigned long  : 6;
#else
			unsigned long  : 6;
			unsigned long SSCD : 1;
			unsigned long  : 7;
			unsigned long SSCE : 1;
			unsigned long  : 5;
			unsigned long SBDDD : 1;
			unsigned long SBDAD : 1;
			unsigned long SBDPD : 1;
			unsigned long SBDCD : 1;
			unsigned long  : 4;
			unsigned long SBDDE : 1;
			unsigned long SBDAE : 1;
			unsigned long SBDPE : 1;
			unsigned long SBDCE : 1;
#endif
	} BIT;
	} GTSECR;
	char           wk2[8];
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long CCTCA : 1;
			unsigned long CCTCB : 1;
			unsigned long CCTPR : 1;
			unsigned long CCTADA : 1;
			unsigned long CCTADB : 1;
			unsigned long CCTDV : 1;
			unsigned long  : 2;
			unsigned long CMTCA : 2;
			unsigned long CMTCB : 2;
			unsigned long  : 1;
			unsigned long CMTADA : 1;
			unsigned long CMTADB : 1;
			unsigned long  : 1;
			unsigned long CPTCA : 1;
			unsigned long CPTCB : 1;
			unsigned long CPTPR : 1;
			unsigned long CPTADA : 1;
			unsigned long CPTADB : 1;
			unsigned long CPTDV : 1;
			unsigned long  : 10;
#else
			unsigned long  : 10;
			unsigned long CPTDV : 1;
			unsigned long CPTADB : 1;
			unsigned long CPTADA : 1;
			unsigned long CPTPR : 1;
			unsigned long CPTCB : 1;
			unsigned long CPTCA : 1;
			unsigned long  : 1;
			unsigned long CMTADB : 1;
			unsigned long CMTADA : 1;
			unsigned long  : 1;
			unsigned long CMTCB : 2;
			unsigned long CMTCA : 2;
			unsigned long  : 2;
			unsigned long CCTDV : 1;
			unsigned long CCTADB : 1;
			unsigned long CCTADA : 1;
			unsigned long CCTPR : 1;
			unsigned long CCTCB : 1;
			unsigned long CCTCA : 1;
#endif
	} BIT;
	} GTBER2;
	char           wk3[8];
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long ICAFA : 1;
			unsigned long ICAFB : 1;
			unsigned long ICAFC : 1;
			unsigned long ICAFD : 1;
			unsigned long ICAFE : 1;
			unsigned long ICAFF : 1;
			unsigned long ICAFPO : 1;
			unsigned long ICAFPU : 1;
			unsigned long ICACLK : 1;
			unsigned long  : 5;
			unsigned long ICAGRP : 2;
			unsigned long ICBFA : 1;
			unsigned long ICBFB : 1;
			unsigned long ICBFC : 1;
			unsigned long ICBFD : 1;
			unsigned long ICBFE : 1;
			unsigned long ICBFF : 1;
			unsigned long ICBFPO : 1;
			unsigned long ICBFPU : 1;
			unsigned long ICBCLK : 1;
			unsigned long  : 5;
			unsigned long ICBGRP : 2;
#else
			unsigned long ICBGRP : 2;
			unsigned long  : 5;
			unsigned long ICBCLK : 1;
			unsigned long ICBFPU : 1;
			unsigned long ICBFPO : 1;
			unsigned long ICBFF : 1;
			unsigned long ICBFE : 1;
			unsigned long ICBFD : 1;
			unsigned long ICBFC : 1;
			unsigned long ICBFB : 1;
			unsigned long ICBFA : 1;
			unsigned long ICAGRP : 2;
			unsigned long  : 5;
			unsigned long ICACLK : 1;
			unsigned long ICAFPU : 1;
			unsigned long ICAFPO : 1;
			unsigned long ICAFF : 1;
			unsigned long ICAFE : 1;
			unsigned long ICAFD : 1;
			unsigned long ICAFC : 1;
			unsigned long ICAFB : 1;
			unsigned long ICAFA : 1;
#endif
	} BIT;
	} GTICCR;
} st_gptw_t;

typedef struct st_icu {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IR : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char IR : 1;
#endif
	} BIT;
	} IR[256];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char DTCE : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char DTCE : 1;
#endif
	} BIT;
	} DTCER[256];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IEN0 : 1;
			unsigned char IEN1 : 1;
			unsigned char IEN2 : 1;
			unsigned char IEN3 : 1;
			unsigned char IEN4 : 1;
			unsigned char IEN5 : 1;
			unsigned char IEN6 : 1;
			unsigned char IEN7 : 1;
#else
			unsigned char IEN7 : 1;
			unsigned char IEN6 : 1;
			unsigned char IEN5 : 1;
			unsigned char IEN4 : 1;
			unsigned char IEN3 : 1;
			unsigned char IEN2 : 1;
			unsigned char IEN1 : 1;
			unsigned char IEN0 : 1;
#endif
	} BIT;
	} IER[32];
	char           wk0[192];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SWINT : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char SWINT : 1;
#endif
	} BIT;
	} SWINTR;
	char           wk1[15];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short FVCT : 8;
			unsigned short  : 7;
			unsigned short FIEN : 1;
#else
			unsigned short FIEN : 1;
			unsigned short  : 7;
			unsigned short FVCT : 8;
#endif
	} BIT;
	} FIR;
	char           wk2[14];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IPR : 4;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char IPR : 4;
#endif
	} BIT;
	} IPR[256];
	char           wk3[256];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 2;
			unsigned char IRQMD : 2;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char IRQMD : 2;
			unsigned char  : 2;
#endif
	} BIT;
	} IRQCR[8];
	char           wk4[8];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char FLTEN0 : 1;
			unsigned char FLTEN1 : 1;
			unsigned char FLTEN2 : 1;
			unsigned char FLTEN3 : 1;
			unsigned char FLTEN4 : 1;
			unsigned char FLTEN5 : 1;
			unsigned char FLTEN6 : 1;
			unsigned char FLTEN7 : 1;
#else
			unsigned char FLTEN7 : 1;
			unsigned char FLTEN6 : 1;
			unsigned char FLTEN5 : 1;
			unsigned char FLTEN4 : 1;
			unsigned char FLTEN3 : 1;
			unsigned char FLTEN2 : 1;
			unsigned char FLTEN1 : 1;
			unsigned char FLTEN0 : 1;
#endif
	} BIT;
	} IRQFLTE0;
	char           wk5[3];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short FCLKSEL0 : 2;
			unsigned short FCLKSEL1 : 2;
			unsigned short FCLKSEL2 : 2;
			unsigned short FCLKSEL3 : 2;
			unsigned short FCLKSEL4 : 2;
			unsigned short FCLKSEL5 : 2;
			unsigned short FCLKSEL6 : 2;
			unsigned short FCLKSEL7 : 2;
#else
			unsigned short FCLKSEL7 : 2;
			unsigned short FCLKSEL6 : 2;
			unsigned short FCLKSEL5 : 2;
			unsigned short FCLKSEL4 : 2;
			unsigned short FCLKSEL3 : 2;
			unsigned short FCLKSEL2 : 2;
			unsigned short FCLKSEL1 : 2;
			unsigned short FCLKSEL0 : 2;
#endif
	} BIT;
	} IRQFLTC0;
	char           wk6[106];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NMIST : 1;
			unsigned char OSTST : 1;
			unsigned char  : 1;
			unsigned char IWDTST : 1;
			unsigned char LVD1ST : 1;
			unsigned char LVD2ST : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char LVD2ST : 1;
			unsigned char LVD1ST : 1;
			unsigned char IWDTST : 1;
			unsigned char  : 1;
			unsigned char OSTST : 1;
			unsigned char NMIST : 1;
#endif
	} BIT;
	} NMISR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NMIEN : 1;
			unsigned char OSTEN : 1;
			unsigned char  : 1;
			unsigned char IWDTEN : 1;
			unsigned char LVD1EN : 1;
			unsigned char LVD2EN : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char LVD2EN : 1;
			unsigned char LVD1EN : 1;
			unsigned char IWDTEN : 1;
			unsigned char  : 1;
			unsigned char OSTEN : 1;
			unsigned char NMIEN : 1;
#endif
	} BIT;
	} NMIER;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NMICLR : 1;
			unsigned char OSTCLR : 1;
			unsigned char  : 1;
			unsigned char IWDTCLR : 1;
			unsigned char LVD1CLR : 1;
			unsigned char LVD2CLR : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char LVD2CLR : 1;
			unsigned char LVD1CLR : 1;
			unsigned char IWDTCLR : 1;
			unsigned char  : 1;
			unsigned char OSTCLR : 1;
			unsigned char NMICLR : 1;
#endif
	} BIT;
	} NMICLR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 3;
			unsigned char NMIMD : 1;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char NMIMD : 1;
			unsigned char  : 3;
#endif
	} BIT;
	} NMICR;
	char           wk7[12];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFLTEN : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char NFLTEN : 1;
#endif
	} BIT;
	} NMIFLTE;
	char           wk8[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFCLKSEL : 2;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char NFCLKSEL : 2;
#endif
	} BIT;
	} NMIFLTC;
} st_icu_t;

typedef struct st_iwdt {
	unsigned char  IWDTRR;
	char           wk0[1];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short TOPS : 2;
			unsigned short  : 2;
			unsigned short CKS : 4;
			unsigned short RPES : 2;
			unsigned short  : 2;
			unsigned short RPSS : 2;
			unsigned short  : 2;
#else
			unsigned short  : 2;
			unsigned short RPSS : 2;
			unsigned short  : 2;
			unsigned short RPES : 2;
			unsigned short CKS : 4;
			unsigned short  : 2;
			unsigned short TOPS : 2;
#endif
	} BIT;
	} IWDTCR;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short CNTVAL : 14;
			unsigned short UNDFF : 1;
			unsigned short REFEF : 1;
#else
			unsigned short REFEF : 1;
			unsigned short UNDFF : 1;
			unsigned short CNTVAL : 14;
#endif
	} BIT;
	} IWDTSR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char RSTIRQS : 1;
#else
			unsigned char RSTIRQS : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} IWDTRCR;
	char           wk1[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char SLCSTP : 1;
#else
			unsigned char SLCSTP : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} IWDTCSTPR;
} st_iwdt_t;

typedef struct st_mpc {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 6;
			unsigned char PFSWE : 1;
			unsigned char B0WI : 1;
#else
			unsigned char B0WI : 1;
			unsigned char PFSWE : 1;
			unsigned char  : 6;
#endif
	} BIT;
	} PWPR;
	char           wk0[32];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P00PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P01PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P02PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P03PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P04PFS;
	char           wk1[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P10PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P11PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 6;
			unsigned char ISEL : 1;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char ISEL : 1;
			unsigned char  : 6;
#endif
	} BIT;
	} P12PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 6;
			unsigned char ISEL : 1;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char ISEL : 1;
			unsigned char  : 6;
#endif
	} BIT;
	} P13PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P14PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} P15PFS;
	char           wk2[4];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P22PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P23PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P24PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P25PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P26PFS;
	char           wk3[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P30PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P31PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P32PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P33PFS;
	char           wk4[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P36PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P37PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} P40PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} P41PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} P42PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} P43PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 2;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char  : 2;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P44PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} P45PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 2;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char  : 2;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P46PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char ASEL : 1;
#else
			unsigned char ASEL : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} P47PFS;
	char           wk5[16];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P70PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P71PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P72PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P73PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P74PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P75PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P76PFS;
	char           wk6[9];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P90PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P91PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P92PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P93PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P94PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P95PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P96PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} P97PFS;
	char           wk7[8];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PB0PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PB1PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PB2PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PB3PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PB4PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PB5PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PB6PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PB7PFS;
	char           wk8[11];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PD3PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PD4PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PD5PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PD6PFS;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PD7PFS;
	char           wk9[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char ISEL : 1;
			unsigned char  : 1;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PE2PFS;
	char           wk10[20];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PSEL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PSEL : 5;
#endif
	} BIT;
	} PG7PFS;
} st_mpc_t;

typedef struct st_mtu {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char OE3B : 1;
			unsigned char OE4A : 1;
			unsigned char OE4B : 1;
			unsigned char OE3D : 1;
			unsigned char OE4C : 1;
			unsigned char OE4D : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char OE4D : 1;
			unsigned char OE4C : 1;
			unsigned char OE3D : 1;
			unsigned char OE4B : 1;
			unsigned char OE4A : 1;
			unsigned char OE3B : 1;
#endif
	} BIT;
	} TOERA;
	char           wk0[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char UF : 1;
			unsigned char VF : 1;
			unsigned char WF : 1;
			unsigned char FB : 1;
			unsigned char P : 1;
			unsigned char N : 1;
			unsigned char BDC : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char BDC : 1;
			unsigned char N : 1;
			unsigned char P : 1;
			unsigned char FB : 1;
			unsigned char WF : 1;
			unsigned char VF : 1;
			unsigned char UF : 1;
#endif
	} BIT;
	} TGCRA;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char OLSP : 1;
			unsigned char OLSN : 1;
			unsigned char TOCS : 1;
			unsigned char TOCL : 1;
			unsigned char  : 2;
			unsigned char PSYE : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char PSYE : 1;
			unsigned char  : 2;
			unsigned char TOCL : 1;
			unsigned char TOCS : 1;
			unsigned char OLSN : 1;
			unsigned char OLSP : 1;
#endif
	} BIT;
	} TOCR1A;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char OLS1P : 1;
			unsigned char OLS1N : 1;
			unsigned char OLS2P : 1;
			unsigned char OLS2N : 1;
			unsigned char OLS3P : 1;
			unsigned char OLS3N : 1;
			unsigned char BF : 2;
#else
			unsigned char BF : 2;
			unsigned char OLS3N : 1;
			unsigned char OLS3P : 1;
			unsigned char OLS2N : 1;
			unsigned char OLS2P : 1;
			unsigned char OLS1N : 1;
			unsigned char OLS1P : 1;
#endif
	} BIT;
	} TOCR2A;
	char           wk1[4];
	unsigned short TCDRA;
	unsigned short TDDRA;
	char           wk2[8];
	unsigned short TCNTSA;
	unsigned short TCBRA;
	char           wk3[12];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char T4VCOR : 3;
			unsigned char T4VEN : 1;
			unsigned char T3ACOR : 3;
			unsigned char T3AEN : 1;
#else
			unsigned char T3AEN : 1;
			unsigned char T3ACOR : 3;
			unsigned char T4VEN : 1;
			unsigned char T4VCOR : 3;
#endif
	} BIT;
	} TITCR1A;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char T4VCNT : 3;
			unsigned char  : 1;
			unsigned char T3ACNT : 3;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char T3ACNT : 3;
			unsigned char  : 1;
			unsigned char T4VCNT : 3;
#endif
	} BIT;
	} TITCNT1A;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char BTE : 2;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char BTE : 2;
#endif
	} BIT;
	} TBTERA;
	char           wk4[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TDER : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char TDER : 1;
#endif
	} BIT;
	} TDERA;
	char           wk5[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char OLS1P : 1;
			unsigned char OLS1N : 1;
			unsigned char OLS2P : 1;
			unsigned char OLS2N : 1;
			unsigned char OLS3P : 1;
			unsigned char OLS3N : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char OLS3N : 1;
			unsigned char OLS3P : 1;
			unsigned char OLS2N : 1;
			unsigned char OLS2P : 1;
			unsigned char OLS1N : 1;
			unsigned char OLS1P : 1;
#endif
	} BIT;
	} TOLBRA;
	char           wk6[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TITM : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char TITM : 1;
#endif
	} BIT;
	} TITMRA;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TRG4COR : 3;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char TRG4COR : 3;
#endif
	} BIT;
	} TITCR2A;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TRG4CNT : 3;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char TRG4CNT : 3;
#endif
	} BIT;
	} TITCNT2A;
	char           wk7[35];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char WRE : 1;
			unsigned char  : 6;
			unsigned char CCE : 1;
#else
			unsigned char CCE : 1;
			unsigned char  : 6;
			unsigned char WRE : 1;
#endif
	} BIT;
	} TWCRA;
	char           wk8[15];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char DRS : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char DRS : 1;
#endif
	} BIT;
	} TMDR2A;
	char           wk9[15];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CST0 : 1;
			unsigned char CST1 : 1;
			unsigned char CST2 : 1;
			unsigned char  : 3;
			unsigned char CST3 : 1;
			unsigned char CST4 : 1;
#else
			unsigned char CST4 : 1;
			unsigned char CST3 : 1;
			unsigned char  : 3;
			unsigned char CST2 : 1;
			unsigned char CST1 : 1;
			unsigned char CST0 : 1;
#endif
	} BIT;
	} TSTRA;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SYNC0 : 1;
			unsigned char SYNC1 : 1;
			unsigned char SYNC2 : 1;
			unsigned char  : 3;
			unsigned char SYNC3 : 1;
			unsigned char SYNC4 : 1;
#else
			unsigned char SYNC4 : 1;
			unsigned char SYNC3 : 1;
			unsigned char  : 3;
			unsigned char SYNC2 : 1;
			unsigned char SYNC1 : 1;
			unsigned char SYNC0 : 1;
#endif
	} BIT;
	} TSYRA;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 3;
			unsigned char SCH4 : 1;
			unsigned char SCH3 : 1;
			unsigned char SCH2 : 1;
			unsigned char SCH1 : 1;
			unsigned char SCH0 : 1;
#else
			unsigned char SCH0 : 1;
			unsigned char SCH1 : 1;
			unsigned char SCH2 : 1;
			unsigned char SCH3 : 1;
			unsigned char SCH4 : 1;
			unsigned char  : 3;
#endif
	} BIT;
	} TCSYSTR;
	char           wk10[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char RWE : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char RWE : 1;
#endif
	} BIT;
	} TRWERA;
	char           wk11[2731];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TADSTRS0 : 5;
			unsigned char  : 2;
			unsigned char TADSMEN0 : 1;
#else
			unsigned char TADSMEN0 : 1;
			unsigned char  : 2;
			unsigned char TADSTRS0 : 5;
#endif
	} BIT;
	} TADSTRGR0;
	char           wk12[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TADSTRS1 : 5;
			unsigned char  : 2;
			unsigned char TADSMEN1 : 1;
#else
			unsigned char TADSMEN1 : 1;
			unsigned char  : 2;
			unsigned char TADSTRS1 : 5;
#endif
	} BIT;
	} TADSTRGR1;
} st_mtu_t;

typedef struct st_mtu0 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFAEN : 1;
			unsigned char NFBEN : 1;
			unsigned char NFCEN : 1;
			unsigned char NFDEN : 1;
			unsigned char NFCS : 2;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char NFCS : 2;
			unsigned char NFDEN : 1;
			unsigned char NFCEN : 1;
			unsigned char NFBEN : 1;
			unsigned char NFAEN : 1;
#endif
	} BIT;
	} NFCR0;
	char           wk0[8];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFAEN : 1;
			unsigned char NFBEN : 1;
			unsigned char NFCEN : 1;
			unsigned char NFDEN : 1;
			unsigned char NFCS : 2;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char NFCS : 2;
			unsigned char NFDEN : 1;
			unsigned char NFCEN : 1;
			unsigned char NFBEN : 1;
			unsigned char NFAEN : 1;
#endif
	} BIT;
	} NFCRC;
	char           wk1[102];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC : 3;
			unsigned char CKEG : 2;
			unsigned char CCLR : 3;
#else
			unsigned char CCLR : 3;
			unsigned char CKEG : 2;
			unsigned char TPSC : 3;
#endif
	} BIT;
	} TCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MD : 4;
			unsigned char BFA : 1;
			unsigned char BFB : 1;
			unsigned char BFE : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char BFE : 1;
			unsigned char BFB : 1;
			unsigned char BFA : 1;
			unsigned char MD : 4;
#endif
	} BIT;
	} TMDR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOA : 4;
			unsigned char IOB : 4;
#else
			unsigned char IOB : 4;
			unsigned char IOA : 4;
#endif
	} BIT;
	} TIORH;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOC : 4;
			unsigned char IOD : 4;
#else
			unsigned char IOD : 4;
			unsigned char IOC : 4;
#endif
	} BIT;
	} TIORL;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TGIEA : 1;
			unsigned char TGIEB : 1;
			unsigned char TGIEC : 1;
			unsigned char TGIED : 1;
			unsigned char TCIEV : 1;
			unsigned char  : 2;
			unsigned char TTGE : 1;
#else
			unsigned char TTGE : 1;
			unsigned char  : 2;
			unsigned char TCIEV : 1;
			unsigned char TGIED : 1;
			unsigned char TGIEC : 1;
			unsigned char TGIEB : 1;
			unsigned char TGIEA : 1;
#endif
	} BIT;
	} TIER;
	char           wk2[1];
	unsigned short TCNT;
	unsigned short TGRA;
	unsigned short TGRB;
	unsigned short TGRC;
	unsigned short TGRD;
	char           wk3[16];
	unsigned short TGRE;
	unsigned short TGRF;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TGIEE : 1;
			unsigned char TGIEF : 1;
			unsigned char  : 5;
			unsigned char TTGE2 : 1;
#else
			unsigned char TTGE2 : 1;
			unsigned char  : 5;
			unsigned char TGIEF : 1;
			unsigned char TGIEE : 1;
#endif
	} BIT;
	} TIER2;
	char           wk4[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TTSA : 1;
			unsigned char TTSB : 1;
			unsigned char TTSE : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char TTSE : 1;
			unsigned char TTSB : 1;
			unsigned char TTSA : 1;
#endif
	} BIT;
	} TBTM;
	char           wk5[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC2 : 3;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char TPSC2 : 3;
#endif
	} BIT;
	} TCR2;
} st_mtu0_t;

typedef struct st_mtu1 {
	char           wk0[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFAEN : 1;
			unsigned char NFBEN : 1;
			unsigned char  : 2;
			unsigned char NFCS : 2;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char NFCS : 2;
			unsigned char  : 2;
			unsigned char NFBEN : 1;
			unsigned char NFAEN : 1;
#endif
	} BIT;
	} NFCR1;
	char           wk1[238];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC : 3;
			unsigned char CKEG : 2;
			unsigned char CCLR : 3;
#else
			unsigned char CCLR : 3;
			unsigned char CKEG : 2;
			unsigned char TPSC : 3;
#endif
	} BIT;
	} TCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MD : 4;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char MD : 4;
#endif
	} BIT;
	} TMDR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOA : 4;
			unsigned char IOB : 4;
#else
			unsigned char IOB : 4;
			unsigned char IOA : 4;
#endif
	} BIT;
	} TIOR;
	char           wk2[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TGIEA : 1;
			unsigned char TGIEB : 1;
			unsigned char  : 2;
			unsigned char TCIEV : 1;
			unsigned char TCIEU : 1;
			unsigned char  : 1;
			unsigned char TTGE : 1;
#else
			unsigned char TTGE : 1;
			unsigned char  : 1;
			unsigned char TCIEU : 1;
			unsigned char TCIEV : 1;
			unsigned char  : 2;
			unsigned char TGIEB : 1;
			unsigned char TGIEA : 1;
#endif
	} BIT;
	} TIER;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char TCFD : 1;
#else
			unsigned char TCFD : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} TSR;
	unsigned short TCNT;
	unsigned short TGRA;
	unsigned short TGRB;
	char           wk3[4];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char I1AE : 1;
			unsigned char I1BE : 1;
			unsigned char I2AE : 1;
			unsigned char I2BE : 1;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char I2BE : 1;
			unsigned char I2AE : 1;
			unsigned char I1BE : 1;
			unsigned char I1AE : 1;
#endif
	} BIT;
	} TICCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char LWA : 1;
			unsigned char PHCKSEL : 1;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char PHCKSEL : 1;
			unsigned char LWA : 1;
#endif
	} BIT;
	} TMDR3;
	char           wk4[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC2 : 3;
			unsigned char PCB : 2;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PCB : 2;
			unsigned char TPSC2 : 3;
#endif
	} BIT;
	} TCR2;
	char           wk5[11];
	unsigned long  TCNTLW;
	unsigned long  TGRALW;
	unsigned long  TGRBLW;
} st_mtu1_t;

typedef struct st_mtu2 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFAEN : 1;
			unsigned char NFBEN : 1;
			unsigned char  : 2;
			unsigned char NFCS : 2;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char NFCS : 2;
			unsigned char  : 2;
			unsigned char NFBEN : 1;
			unsigned char NFAEN : 1;
#endif
	} BIT;
	} NFCR2;
	char           wk0[365];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC : 3;
			unsigned char CKEG : 2;
			unsigned char CCLR : 3;
#else
			unsigned char CCLR : 3;
			unsigned char CKEG : 2;
			unsigned char TPSC : 3;
#endif
	} BIT;
	} TCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MD : 4;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char MD : 4;
#endif
	} BIT;
	} TMDR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOA : 4;
			unsigned char IOB : 4;
#else
			unsigned char IOB : 4;
			unsigned char IOA : 4;
#endif
	} BIT;
	} TIOR;
	char           wk1[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TGIEA : 1;
			unsigned char TGIEB : 1;
			unsigned char  : 2;
			unsigned char TCIEV : 1;
			unsigned char TCIEU : 1;
			unsigned char  : 1;
			unsigned char TTGE : 1;
#else
			unsigned char TTGE : 1;
			unsigned char  : 1;
			unsigned char TCIEU : 1;
			unsigned char TCIEV : 1;
			unsigned char  : 2;
			unsigned char TGIEB : 1;
			unsigned char TGIEA : 1;
#endif
	} BIT;
	} TIER;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char TCFD : 1;
#else
			unsigned char TCFD : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} TSR;
	unsigned short TCNT;
	unsigned short TGRA;
	unsigned short TGRB;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC2 : 3;
			unsigned char PCB : 2;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char PCB : 2;
			unsigned char TPSC2 : 3;
#endif
	} BIT;
	} TCR2;
} st_mtu2_t;

typedef struct st_mtu3 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC : 3;
			unsigned char CKEG : 2;
			unsigned char CCLR : 3;
#else
			unsigned char CCLR : 3;
			unsigned char CKEG : 2;
			unsigned char TPSC : 3;
#endif
	} BIT;
	} TCR;
	char           wk0[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MD : 4;
			unsigned char BFA : 1;
			unsigned char BFB : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char BFB : 1;
			unsigned char BFA : 1;
			unsigned char MD : 4;
#endif
	} BIT;
	} TMDR1;
	char           wk1[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOA : 4;
			unsigned char IOB : 4;
#else
			unsigned char IOB : 4;
			unsigned char IOA : 4;
#endif
	} BIT;
	} TIORH;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOC : 4;
			unsigned char IOD : 4;
#else
			unsigned char IOD : 4;
			unsigned char IOC : 4;
#endif
	} BIT;
	} TIORL;
	char           wk2[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TGIEA : 1;
			unsigned char TGIEB : 1;
			unsigned char TGIEC : 1;
			unsigned char TGIED : 1;
			unsigned char TCIEV : 1;
			unsigned char  : 2;
			unsigned char TTGE : 1;
#else
			unsigned char TTGE : 1;
			unsigned char  : 2;
			unsigned char TCIEV : 1;
			unsigned char TGIED : 1;
			unsigned char TGIEC : 1;
			unsigned char TGIEB : 1;
			unsigned char TGIEA : 1;
#endif
	} BIT;
	} TIER;
	char           wk3[7];
	unsigned short TCNT;
	char           wk4[6];
	unsigned short TGRA;
	unsigned short TGRB;
	char           wk5[8];
	unsigned short TGRC;
	unsigned short TGRD;
	char           wk6[4];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char TCFD : 1;
#else
			unsigned char TCFD : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} TSR;
	char           wk7[11];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TTSA : 1;
			unsigned char TTSB : 1;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char TTSB : 1;
			unsigned char TTSA : 1;
#endif
	} BIT;
	} TBTM;
	char           wk8[19];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC2 : 3;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char TPSC2 : 3;
#endif
	} BIT;
	} TCR2;
	char           wk9[37];
	unsigned short TGRE;
	char           wk10[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFAEN : 1;
			unsigned char NFBEN : 1;
			unsigned char NFCEN : 1;
			unsigned char NFDEN : 1;
			unsigned char NFCS : 2;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char NFCS : 2;
			unsigned char NFDEN : 1;
			unsigned char NFCEN : 1;
			unsigned char NFBEN : 1;
			unsigned char NFAEN : 1;
#endif
	} BIT;
	} NFCR3;
} st_mtu3_t;

typedef struct st_mtu4 {
	char           wk0[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC : 3;
			unsigned char CKEG : 2;
			unsigned char CCLR : 3;
#else
			unsigned char CCLR : 3;
			unsigned char CKEG : 2;
			unsigned char TPSC : 3;
#endif
	} BIT;
	} TCR;
	char           wk1[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MD : 4;
			unsigned char BFA : 1;
			unsigned char BFB : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char BFB : 1;
			unsigned char BFA : 1;
			unsigned char MD : 4;
#endif
	} BIT;
	} TMDR1;
	char           wk2[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOA : 4;
			unsigned char IOB : 4;
#else
			unsigned char IOB : 4;
			unsigned char IOA : 4;
#endif
	} BIT;
	} TIORH;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOC : 4;
			unsigned char IOD : 4;
#else
			unsigned char IOD : 4;
			unsigned char IOC : 4;
#endif
	} BIT;
	} TIORL;
	char           wk3[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TGIEA : 1;
			unsigned char TGIEB : 1;
			unsigned char TGIEC : 1;
			unsigned char TGIED : 1;
			unsigned char TCIEV : 1;
			unsigned char  : 1;
			unsigned char TTGE2 : 1;
			unsigned char TTGE : 1;
#else
			unsigned char TTGE : 1;
			unsigned char TTGE2 : 1;
			unsigned char  : 1;
			unsigned char TCIEV : 1;
			unsigned char TGIED : 1;
			unsigned char TGIEC : 1;
			unsigned char TGIEB : 1;
			unsigned char TGIEA : 1;
#endif
	} BIT;
	} TIER;
	char           wk4[8];
	unsigned short TCNT;
	char           wk5[8];
	unsigned short TGRA;
	unsigned short TGRB;
	char           wk6[8];
	unsigned short TGRC;
	unsigned short TGRD;
	char           wk7[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char TCFD : 1;
#else
			unsigned char TCFD : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} TSR;
	char           wk8[11];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TTSA : 1;
			unsigned char TTSB : 1;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char TTSB : 1;
			unsigned char TTSA : 1;
#endif
	} BIT;
	} TBTM;
	char           wk9[6];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short ITB4VE : 1;
			unsigned short ITB3AE : 1;
			unsigned short ITA4VE : 1;
			unsigned short ITA3AE : 1;
			unsigned short DT4BE : 1;
			unsigned short UT4BE : 1;
			unsigned short DT4AE : 1;
			unsigned short UT4AE : 1;
			unsigned short  : 6;
			unsigned short BF : 2;
#else
			unsigned short BF : 2;
			unsigned short  : 6;
			unsigned short UT4AE : 1;
			unsigned short DT4AE : 1;
			unsigned short UT4BE : 1;
			unsigned short DT4BE : 1;
			unsigned short ITA3AE : 1;
			unsigned short ITA4VE : 1;
			unsigned short ITB3AE : 1;
			unsigned short ITB4VE : 1;
#endif
	} BIT;
	} TADCR;
	char           wk10[2];
	unsigned short TADCORA;
	unsigned short TADCORB;
	unsigned short TADCOBRA;
	unsigned short TADCOBRB;
	char           wk11[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC2 : 3;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char TPSC2 : 3;
#endif
	} BIT;
	} TCR2;
	char           wk12[38];
	unsigned short TGRE;
	unsigned short TGRF;
	char           wk13[28];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFAEN : 1;
			unsigned char NFBEN : 1;
			unsigned char NFCEN : 1;
			unsigned char NFDEN : 1;
			unsigned char NFCS : 2;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char NFCS : 2;
			unsigned char NFDEN : 1;
			unsigned char NFCEN : 1;
			unsigned char NFBEN : 1;
			unsigned char NFAEN : 1;
#endif
	} BIT;
	} NFCR4;
} st_mtu4_t;

typedef struct st_mtu5 {
	char           wk0[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFUEN : 1;
			unsigned char NFVEN : 1;
			unsigned char NFWEN : 1;
			unsigned char  : 1;
			unsigned char NFCS : 2;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char NFCS : 2;
			unsigned char  : 1;
			unsigned char NFWEN : 1;
			unsigned char NFVEN : 1;
			unsigned char NFUEN : 1;
#endif
	} BIT;
	} NFCR5;
	char           wk1[490];
	unsigned short TCNTU;
	unsigned short TGRU;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC : 2;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char TPSC : 2;
#endif
	} BIT;
	} TCRU;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC2 : 3;
			unsigned char CKEG : 2;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char CKEG : 2;
			unsigned char TPSC2 : 3;
#endif
	} BIT;
	} TCR2U;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOC : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char IOC : 5;
#endif
	} BIT;
	} TIORU;
	char           wk2[9];
	unsigned short TCNTV;
	unsigned short TGRV;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC : 2;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char TPSC : 2;
#endif
	} BIT;
	} TCRV;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC2 : 3;
			unsigned char CKEG : 2;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char CKEG : 2;
			unsigned char TPSC2 : 3;
#endif
	} BIT;
	} TCR2V;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOC : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char IOC : 5;
#endif
	} BIT;
	} TIORV;
	char           wk3[9];
	unsigned short TCNTW;
	unsigned short TGRW;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC : 2;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char TPSC : 2;
#endif
	} BIT;
	} TCRW;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TPSC2 : 3;
			unsigned char CKEG : 2;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char CKEG : 2;
			unsigned char TPSC2 : 3;
#endif
	} BIT;
	} TCR2W;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IOC : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char IOC : 5;
#endif
	} BIT;
	} TIORW;
	char           wk4[11];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TGIE5W : 1;
			unsigned char TGIE5V : 1;
			unsigned char TGIE5U : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char TGIE5U : 1;
			unsigned char TGIE5V : 1;
			unsigned char TGIE5W : 1;
#endif
	} BIT;
	} TIER;
	char           wk5[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CSTW5 : 1;
			unsigned char CSTV5 : 1;
			unsigned char CSTU5 : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char CSTU5 : 1;
			unsigned char CSTV5 : 1;
			unsigned char CSTW5 : 1;
#endif
	} BIT;
	} TSTR;
	char           wk6[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CMPCLR5W : 1;
			unsigned char CMPCLR5V : 1;
			unsigned char CMPCLR5U : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char CMPCLR5U : 1;
			unsigned char CMPCLR5V : 1;
			unsigned char CMPCLR5W : 1;
#endif
	} BIT;
	} TCNTCMPCLR;
} st_mtu5_t;

typedef struct st_ofsm {
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long MDE : 3;
			unsigned long  : 29;
#else
			unsigned long  : 29;
			unsigned long MDE : 3;
#endif
	} BIT;
	} MDE;
	char           wk0[4];
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long VDSEL : 2;
			unsigned long LVDAS : 1;
			unsigned long FASTSTUP : 1;
			unsigned long  : 4;
			unsigned long HOCOEN : 1;
			unsigned long  : 3;
			unsigned long HOCOFRQ : 2;
			unsigned long  : 18;
#else
			unsigned long  : 18;
			unsigned long HOCOFRQ : 2;
			unsigned long  : 3;
			unsigned long HOCOEN : 1;
			unsigned long  : 4;
			unsigned long FASTSTUP : 1;
			unsigned long LVDAS : 1;
			unsigned long VDSEL : 2;
#endif
	} BIT;
	} OFS1;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long  : 1;
			unsigned long IWDTSTRT : 1;
			unsigned long IWDTTOPS : 2;
			unsigned long IWDTCKS : 4;
			unsigned long IWDTRPES : 2;
			unsigned long IWDTRPSS : 2;
			unsigned long IWDTRSTIRQS : 1;
			unsigned long  : 1;
			unsigned long IWDTSLCSTP : 1;
			unsigned long  : 17;
#else
			unsigned long  : 17;
			unsigned long IWDTSLCSTP : 1;
			unsigned long  : 1;
			unsigned long IWDTRSTIRQS : 1;
			unsigned long IWDTRPSS : 2;
			unsigned long IWDTRPES : 2;
			unsigned long IWDTCKS : 4;
			unsigned long IWDTTOPS : 2;
			unsigned long IWDTSTRT : 1;
			unsigned long  : 1;
#endif
	} BIT;
	} OFS0;
} st_ofsm_t;

typedef struct st_pga {
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 2;
			unsigned short PGA0EN : 1;
			unsigned short  : 3;
			unsigned short PGA1EN : 1;
			unsigned short  : 3;
			unsigned short PGA2EN : 1;
			unsigned short  : 1;
			unsigned short PGA0GND : 1;
			unsigned short PGA1GND : 1;
			unsigned short PGA2GND : 1;
			unsigned short  : 1;
#else
			unsigned short  : 1;
			unsigned short PGA2GND : 1;
			unsigned short PGA1GND : 1;
			unsigned short PGA0GND : 1;
			unsigned short  : 1;
			unsigned short PGA2EN : 1;
			unsigned short  : 3;
			unsigned short PGA1EN : 1;
			unsigned short  : 3;
			unsigned short PGA0EN : 1;
			unsigned short  : 2;
#endif
	} BIT;
	} PGACR;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short PGA0GAIN : 2;
			unsigned short  : 2;
			unsigned short PGA1GAIN : 2;
			unsigned short  : 2;
			unsigned short PGA2GAIN : 2;
			unsigned short  : 6;
#else
			unsigned short  : 6;
			unsigned short PGA2GAIN : 2;
			unsigned short  : 2;
			unsigned short PGA1GAIN : 2;
			unsigned short  : 2;
			unsigned short PGA0GAIN : 2;
#endif
	} BIT;
	} PGAGS0;
	char           wk0[60];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PGAMON : 1;
			unsigned char  : 3;
			unsigned char MONSEL : 4;
#else
			unsigned char MONSEL : 4;
			unsigned char  : 3;
			unsigned char PGAMON : 1;
#endif
	} BIT;
	} PGAMONCR;
} st_pga_t;

typedef struct st_poe {
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short POE0M : 4;
			unsigned short POE0M2 : 4;
			unsigned short PIE1 : 1;
			unsigned short  : 3;
			unsigned short POE0F : 1;
			unsigned short  : 2;
			unsigned short INV : 1;
#else
			unsigned short INV : 1;
			unsigned short  : 2;
			unsigned short POE0F : 1;
			unsigned short  : 3;
			unsigned short PIE1 : 1;
			unsigned short POE0M2 : 4;
			unsigned short POE0M : 4;
#endif
	} BIT;
	} ICSR1;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 8;
			unsigned short OIE1 : 1;
			unsigned short OCE1 : 1;
			unsigned short  : 5;
			unsigned short OSF1 : 1;
#else
			unsigned short OSF1 : 1;
			unsigned short  : 5;
			unsigned short OCE1 : 1;
			unsigned short OIE1 : 1;
			unsigned short  : 8;
#endif
	} BIT;
	} OCSR1;
	char           wk0[4];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short POE8M : 4;
			unsigned short POE8M2 : 4;
			unsigned short PIE3 : 1;
			unsigned short POE8E : 1;
			unsigned short  : 2;
			unsigned short POE8F : 1;
			unsigned short  : 2;
			unsigned short INV : 1;
#else
			unsigned short INV : 1;
			unsigned short  : 2;
			unsigned short POE8F : 1;
			unsigned short  : 2;
			unsigned short POE8E : 1;
			unsigned short PIE3 : 1;
			unsigned short POE8M2 : 4;
			unsigned short POE8M : 4;
#endif
	} BIT;
	} ICSR3;
	char           wk1[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MTU0AZE : 1;
			unsigned char MTU0BZE : 1;
			unsigned char MTU0CZE : 1;
			unsigned char MTU0DZE : 1;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char MTU0DZE : 1;
			unsigned char MTU0CZE : 1;
			unsigned char MTU0BZE : 1;
			unsigned char MTU0AZE : 1;
#endif
	} BIT;
	} POECR1;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 8;
			unsigned short MTU4BDZE : 1;
			unsigned short MTU4ACZE : 1;
			unsigned short MTU3BDZE : 1;
			unsigned short  : 5;
#else
			unsigned short  : 5;
			unsigned short MTU3BDZE : 1;
			unsigned short MTU4ACZE : 1;
			unsigned short MTU4BDZE : 1;
			unsigned short  : 8;
#endif
	} BIT;
	} POECR2;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short GPT0ABZE : 1;
			unsigned short GPT1ABZE : 1;
			unsigned short GPT2ABZE : 1;
			unsigned short  : 13;
#else
			unsigned short  : 13;
			unsigned short GPT2ABZE : 1;
			unsigned short GPT1ABZE : 1;
			unsigned short GPT0ABZE : 1;
#endif
	} BIT;
	} POECR3;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short CMADDMT34ZE : 1;
			unsigned short IC1ADDMT34ZE : 1;
			unsigned short  : 1;
			unsigned short IC3ADDMT34ZE : 1;
			unsigned short IC4ADDMT34ZE : 1;
			unsigned short IC5ADDMT34ZE : 1;
			unsigned short IC6ADDMT34ZE : 1;
			unsigned short  : 9;
#else
			unsigned short  : 9;
			unsigned short IC6ADDMT34ZE : 1;
			unsigned short IC5ADDMT34ZE : 1;
			unsigned short IC4ADDMT34ZE : 1;
			unsigned short IC3ADDMT34ZE : 1;
			unsigned short  : 1;
			unsigned short IC1ADDMT34ZE : 1;
			unsigned short CMADDMT34ZE : 1;
#endif
	} BIT;
	} POECR4;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short CMADDMT0ZE : 1;
			unsigned short IC1ADDMT0ZE : 1;
			unsigned short  : 1;
			unsigned short IC3ADDMT0ZE : 1;
			unsigned short IC4ADDMT0ZE : 1;
			unsigned short IC5ADDMT0ZE : 1;
			unsigned short IC6ADDMT0ZE : 1;
			unsigned short  : 9;
#else
			unsigned short  : 9;
			unsigned short IC6ADDMT0ZE : 1;
			unsigned short IC5ADDMT0ZE : 1;
			unsigned short IC4ADDMT0ZE : 1;
			unsigned short IC3ADDMT0ZE : 1;
			unsigned short  : 1;
			unsigned short IC1ADDMT0ZE : 1;
			unsigned short CMADDMT0ZE : 1;
#endif
	} BIT;
	} POECR5;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short CMADDGPT01ZE : 1;
			unsigned short IC1ADDGPT01ZE : 1;
			unsigned short  : 1;
			unsigned short IC3ADDGPT01ZE : 1;
			unsigned short IC4ADDGPT01ZE : 1;
			unsigned short IC5ADDGPT01ZE : 1;
			unsigned short IC6ADDGPT01ZE : 1;
			unsigned short  : 9;
#else
			unsigned short  : 9;
			unsigned short IC6ADDGPT01ZE : 1;
			unsigned short IC5ADDGPT01ZE : 1;
			unsigned short IC4ADDGPT01ZE : 1;
			unsigned short IC3ADDGPT01ZE : 1;
			unsigned short  : 1;
			unsigned short IC1ADDGPT01ZE : 1;
			unsigned short CMADDGPT01ZE : 1;
#endif
	} BIT;
	} POECR6;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short POE10M : 4;
			unsigned short POE10M2 : 4;
			unsigned short PIE4 : 1;
			unsigned short POE10E : 1;
			unsigned short  : 2;
			unsigned short POE10F : 1;
			unsigned short  : 2;
			unsigned short INV : 1;
#else
			unsigned short INV : 1;
			unsigned short  : 2;
			unsigned short POE10F : 1;
			unsigned short  : 2;
			unsigned short POE10E : 1;
			unsigned short PIE4 : 1;
			unsigned short POE10M2 : 4;
			unsigned short POE10M : 4;
#endif
	} BIT;
	} ICSR4;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short POE11M : 4;
			unsigned short POE11M2 : 4;
			unsigned short PIE5 : 1;
			unsigned short POE11E : 1;
			unsigned short  : 2;
			unsigned short POE11F : 1;
			unsigned short  : 2;
			unsigned short INV : 1;
#else
			unsigned short INV : 1;
			unsigned short  : 2;
			unsigned short POE11F : 1;
			unsigned short  : 2;
			unsigned short POE11E : 1;
			unsigned short PIE5 : 1;
			unsigned short POE11M2 : 4;
			unsigned short POE11M : 4;
#endif
	} BIT;
	} ICSR5;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short OLSG0A : 1;
			unsigned short OLSG0B : 1;
			unsigned short OLSG1A : 1;
			unsigned short OLSG1B : 1;
			unsigned short OLSG2A : 1;
			unsigned short OLSG2B : 1;
			unsigned short  : 1;
			unsigned short OLSEN : 1;
			unsigned short  : 8;
#else
			unsigned short  : 8;
			unsigned short OLSEN : 1;
			unsigned short  : 1;
			unsigned short OLSG2B : 1;
			unsigned short OLSG2A : 1;
			unsigned short OLSG1B : 1;
			unsigned short OLSG1A : 1;
			unsigned short OLSG0B : 1;
			unsigned short OLSG0A : 1;
#endif
	} BIT;
	} ALR1;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 9;
			unsigned short OSTSTE : 1;
			unsigned short  : 2;
			unsigned short OSTSTF : 1;
			unsigned short  : 3;
#else
			unsigned short  : 3;
			unsigned short OSTSTF : 1;
			unsigned short  : 2;
			unsigned short OSTSTE : 1;
			unsigned short  : 9;
#endif
	} BIT;
	} ICSR6;
	char           wk2[2];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short POE12M : 4;
			unsigned short POE12M2 : 4;
			unsigned short PIE7 : 1;
			unsigned short POE12E : 1;
			unsigned short  : 2;
			unsigned short POE12F : 1;
			unsigned short  : 2;
			unsigned short INV : 1;
#else
			unsigned short INV : 1;
			unsigned short  : 2;
			unsigned short POE12F : 1;
			unsigned short  : 2;
			unsigned short POE12E : 1;
			unsigned short PIE7 : 1;
			unsigned short POE12M2 : 4;
			unsigned short POE12M : 4;
#endif
	} BIT;
	} ICSR7;
	char           wk3[4];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short C0FLAG : 1;
			unsigned short C1FLAG : 1;
			unsigned short C2FLAG : 1;
			unsigned short  : 13;
#else
			unsigned short  : 13;
			unsigned short C2FLAG : 1;
			unsigned short C1FLAG : 1;
			unsigned short C0FLAG : 1;
#endif
	} BIT;
	} POECMPFR;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short POEREQ0 : 1;
			unsigned short POEREQ1 : 1;
			unsigned short POEREQ2 : 1;
			unsigned short  : 13;
#else
			unsigned short  : 13;
			unsigned short POEREQ2 : 1;
			unsigned short POEREQ1 : 1;
			unsigned short POEREQ0 : 1;
#endif
	} BIT;
	} POECMPSEL;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 8;
			unsigned short OIE3 : 1;
			unsigned short OCE3 : 1;
			unsigned short  : 5;
			unsigned short OSF3 : 1;
#else
			unsigned short OSF3 : 1;
			unsigned short  : 5;
			unsigned short OCE3 : 1;
			unsigned short OIE3 : 1;
			unsigned short  : 8;
#endif
	} BIT;
	} OCSR3;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short OLSG0A : 1;
			unsigned short OLSG0B : 1;
			unsigned short OLSG1A : 1;
			unsigned short OLSG1B : 1;
			unsigned short OLSG2A : 1;
			unsigned short OLSG2B : 1;
			unsigned short  : 1;
			unsigned short OLSEN : 1;
			unsigned short  : 8;
#else
			unsigned short  : 8;
			unsigned short OLSEN : 1;
			unsigned short  : 1;
			unsigned short OLSG2B : 1;
			unsigned short OLSG2A : 1;
			unsigned short OLSG1B : 1;
			unsigned short OLSG1A : 1;
			unsigned short OLSG0B : 1;
			unsigned short OLSG0A : 1;
#endif
	} BIT;
	} ALR3;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short MTUCH34HIZ : 1;
			unsigned short  : 1;
			unsigned short MTUCH0HIZ : 1;
			unsigned short GPT01HIZ : 1;
			unsigned short GPT23HIZ : 1;
			unsigned short  : 3;
			unsigned short GPT02HIZ : 1;
			unsigned short  : 7;
#else
			unsigned short  : 7;
			unsigned short GPT02HIZ : 1;
			unsigned short  : 3;
			unsigned short GPT23HIZ : 1;
			unsigned short GPT01HIZ : 1;
			unsigned short MTUCH0HIZ : 1;
			unsigned short  : 1;
			unsigned short MTUCH34HIZ : 1;
#endif
	} BIT;
	} SPOER;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short MTU0AME : 1;
			unsigned short MTU0BME : 1;
			unsigned short MTU0CME : 1;
			unsigned short MTU0DME : 1;
			unsigned short  : 12;
#else
			unsigned short  : 12;
			unsigned short MTU0DME : 1;
			unsigned short MTU0CME : 1;
			unsigned short MTU0BME : 1;
			unsigned short MTU0AME : 1;
#endif
	} BIT;
	} PMMCR0;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 8;
			unsigned short MTU4BME : 1;
			unsigned short MTU4AME : 1;
			unsigned short MTU3BME : 1;
			unsigned short MTU4DME : 1;
			unsigned short MTU4CME : 1;
			unsigned short MTU3DME : 1;
			unsigned short  : 2;
#else
			unsigned short  : 2;
			unsigned short MTU3DME : 1;
			unsigned short MTU4CME : 1;
			unsigned short MTU4DME : 1;
			unsigned short MTU3BME : 1;
			unsigned short MTU4AME : 1;
			unsigned short MTU4BME : 1;
			unsigned short  : 8;
#endif
	} BIT;
	} PMMCR1;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short GPT0AME : 1;
			unsigned short GPT0BME : 1;
			unsigned short GPT1AME : 1;
			unsigned short GPT1BME : 1;
			unsigned short GPT2AME : 1;
			unsigned short GPT2BME : 1;
			unsigned short  : 10;
#else
			unsigned short  : 10;
			unsigned short GPT2BME : 1;
			unsigned short GPT2AME : 1;
			unsigned short GPT1BME : 1;
			unsigned short GPT1AME : 1;
			unsigned short GPT0BME : 1;
			unsigned short GPT0AME : 1;
#endif
	} BIT;
	} PMMCR2;
	char           wk4[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char POEREQ0 : 1;
			unsigned char POEREQ1 : 1;
			unsigned char POEREQ2 : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char POEREQ2 : 1;
			unsigned char POEREQ1 : 1;
			unsigned char POEREQ0 : 1;
#endif
	} BIT;
	} POECMPEX0;
	char           wk5[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char POEREQ0 : 1;
			unsigned char POEREQ1 : 1;
			unsigned char POEREQ2 : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char POEREQ2 : 1;
			unsigned char POEREQ1 : 1;
			unsigned char POEREQ0 : 1;
#endif
	} BIT;
	} POECMPEX2;
	char           wk6[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char POEREQ0 : 1;
			unsigned char POEREQ1 : 1;
			unsigned char POEREQ2 : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char POEREQ2 : 1;
			unsigned char POEREQ1 : 1;
			unsigned char POEREQ0 : 1;
#endif
	} BIT;
	} POECMPEX4;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char POEREQ0 : 1;
			unsigned char POEREQ1 : 1;
			unsigned char POEREQ2 : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char POEREQ2 : 1;
			unsigned char POEREQ1 : 1;
			unsigned char POEREQ0 : 1;
#endif
	} BIT;
	} POECMPEX5;
	char           wk7[18];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short CMADDGPT23ZE : 1;
			unsigned short IC1ADDGPT23ZE : 1;
			unsigned short  : 1;
			unsigned short IC3ADDGPT23ZE : 1;
			unsigned short IC4ADDGPT23ZE : 1;
			unsigned short IC5ADDGPT23ZE : 1;
			unsigned short IC6ADDGPT23ZE : 1;
			unsigned short  : 9;
#else
			unsigned short  : 9;
			unsigned short IC6ADDGPT23ZE : 1;
			unsigned short IC5ADDGPT23ZE : 1;
			unsigned short IC4ADDGPT23ZE : 1;
			unsigned short IC3ADDGPT23ZE : 1;
			unsigned short  : 1;
			unsigned short IC1ADDGPT23ZE : 1;
			unsigned short CMADDGPT23ZE : 1;
#endif
	} BIT;
	} POECR6B;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short CMADDGPT02ZE : 1;
			unsigned short IC1ADDGPT02ZE : 1;
			unsigned short  : 1;
			unsigned short IC3ADDGPT02ZE : 1;
			unsigned short IC4ADDGPT02ZE : 1;
			unsigned short IC5ADDGPT02ZE : 1;
			unsigned short IC6ADDGPT02ZE : 1;
			unsigned short  : 9;
#else
			unsigned short  : 9;
			unsigned short IC6ADDGPT02ZE : 1;
			unsigned short IC5ADDGPT02ZE : 1;
			unsigned short IC4ADDGPT02ZE : 1;
			unsigned short IC3ADDGPT02ZE : 1;
			unsigned short  : 1;
			unsigned short IC1ADDGPT02ZE : 1;
			unsigned short CMADDGPT02ZE : 1;
#endif
	} BIT;
	} POECR9;
	char           wk8[4];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char POEREQ0 : 1;
			unsigned char POEREQ1 : 1;
			unsigned char POEREQ2 : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char POEREQ2 : 1;
			unsigned char POEREQ1 : 1;
			unsigned char POEREQ0 : 1;
#endif
	} BIT;
	} POECMPEX6;
	char           wk9[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char POE0MS : 6;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char POE0MS : 6;
#endif
	} BIT;
	} IMCR0;
	char           wk10[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char POE8MS : 6;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char POE8MS : 6;
#endif
	} BIT;
	} IMCR2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char POE10MS : 6;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char POE10MS : 6;
#endif
	} BIT;
	} IMCR3;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char M0ASEL : 4;
			unsigned char M0BSEL : 4;
#else
			unsigned char M0BSEL : 4;
			unsigned char M0ASEL : 4;
#endif
	} BIT;
	} M0SELR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char M0CSEL : 4;
			unsigned char M0DSEL : 4;
#else
			unsigned char M0DSEL : 4;
			unsigned char M0CSEL : 4;
#endif
	} BIT;
	} M0SELR2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char M3BSEL : 4;
			unsigned char M3DSEL : 4;
#else
			unsigned char M3DSEL : 4;
			unsigned char M3BSEL : 4;
#endif
	} BIT;
	} M3SELR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char M4ASEL : 4;
			unsigned char M4CSEL : 4;
#else
			unsigned char M4CSEL : 4;
			unsigned char M4ASEL : 4;
#endif
	} BIT;
	} M4SELR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char M4BSEL : 4;
			unsigned char M4DSEL : 4;
#else
			unsigned char M4DSEL : 4;
			unsigned char M4BSEL : 4;
#endif
	} BIT;
	} M4SELR2;
	char           wk11[5];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char G0ASEL : 4;
			unsigned char G0BSEL : 4;
#else
			unsigned char G0BSEL : 4;
			unsigned char G0ASEL : 4;
#endif
	} BIT;
	} G0SELR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char G1ASEL : 4;
			unsigned char G1BSEL : 4;
#else
			unsigned char G1BSEL : 4;
			unsigned char G1ASEL : 4;
#endif
	} BIT;
	} G1SELR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char G2ASEL : 4;
			unsigned char G2BSEL : 4;
#else
			unsigned char G2BSEL : 4;
			unsigned char G2ASEL : 4;
#endif
	} BIT;
	} G2SELR;
	char           wk12[7];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char POE11MS : 6;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char POE11MS : 6;
#endif
	} BIT;
	} IMCR4;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char POE12MS : 6;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char POE12MS : 6;
#endif
	} BIT;
	} IMCR5;
	char           wk13[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CMP0MS : 6;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char CMP0MS : 6;
#endif
	} BIT;
	} IMCR9;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CMP1MS : 6;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char CMP1MS : 6;
#endif
	} BIT;
	} IMCR10;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CMP2MS : 6;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char CMP2MS : 6;
#endif
	} BIT;
	} IMCR11;
} st_poe_t;

typedef struct st_poeg {
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long PIDF : 1;
			unsigned long IOCF : 1;
			unsigned long OSTPF : 1;
			unsigned long SSF : 1;
			unsigned long PIDE : 1;
			unsigned long IOCE : 1;
			unsigned long OSTPE : 1;
			unsigned long  : 1;
			unsigned long CDRE0 : 1;
			unsigned long CDRE1 : 1;
			unsigned long CDRE2 : 1;
			unsigned long  : 5;
			unsigned long ST : 1;
			unsigned long  : 7;
			unsigned long NFPSC : 1;
			unsigned long ELSEL : 1;
			unsigned long NFSN : 2;
			unsigned long INV : 1;
			unsigned long NFEN : 1;
			unsigned long NFCS : 2;
#else
			unsigned long NFCS : 2;
			unsigned long NFEN : 1;
			unsigned long INV : 1;
			unsigned long NFSN : 2;
			unsigned long ELSEL : 1;
			unsigned long NFPSC : 1;
			unsigned long  : 7;
			unsigned long ST : 1;
			unsigned long  : 5;
			unsigned long CDRE2 : 1;
			unsigned long CDRE1 : 1;
			unsigned long CDRE0 : 1;
			unsigned long  : 1;
			unsigned long OSTPE : 1;
			unsigned long IOCE : 1;
			unsigned long PIDE : 1;
			unsigned long SSF : 1;
			unsigned long OSTPF : 1;
			unsigned long IOCF : 1;
			unsigned long PIDF : 1;
#endif
	} BIT;
	} POEGGA;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long MSEL : 5;
			unsigned long  : 27;
#else
			unsigned long  : 27;
			unsigned long MSEL : 5;
#endif
	} BIT;
	} POEGICRA;
	char           wk0[56];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short WP : 1;
			unsigned short  : 7;
			unsigned short PRKEY : 8;
#else
			unsigned short PRKEY : 8;
			unsigned short  : 7;
			unsigned short WP : 1;
#endif
	} BIT;
	} GTONCWPA;
	char           wk1[2];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short NE : 1;
			unsigned short  : 3;
			unsigned short NFS : 4;
			unsigned short NFV : 1;
			unsigned short  : 2;
			unsigned short MSEL : 5;
#else
			unsigned short MSEL : 5;
			unsigned short  : 2;
			unsigned short NFV : 1;
			unsigned short NFS : 4;
			unsigned short  : 3;
			unsigned short NE : 1;
#endif
	} BIT;
	} GTONCCRA;
} st_poeg_t;

typedef struct st_port0 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PODR;
	char           wk1[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PIDR;
	char           wk2[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PMR;
	char           wk3[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR1;
	char           wk4[62];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PCR;
} st_port0_t;

typedef struct st_port1 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PODR;
	char           wk1[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PIDR;
	char           wk2[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PMR;
	char           wk3[32];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR0;
	char           wk4[62];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PCR;
} st_port1_t;

typedef struct st_port2 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 2;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char  : 2;
#endif
	} BIT;
	} PDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 2;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char  : 2;
#endif
	} BIT;
	} PODR;
	char           wk1[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 2;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char  : 2;
#endif
	} BIT;
	} PIDR;
	char           wk2[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 2;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char  : 2;
#endif
	} BIT;
	} PMR;
	char           wk3[33];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 4;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 4;
#endif
	} BIT;
	} ODR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR1;
	char           wk4[60];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 2;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char  : 2;
#endif
	} BIT;
	} PCR;
} st_port2_t;

typedef struct st_port3 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char  : 2;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char  : 2;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char  : 2;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char  : 2;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PODR;
	char           wk1[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char  : 2;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char  : 2;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PIDR;
	char           wk2[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char  : 2;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char  : 2;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PMR;
	char           wk3[34];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 4;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 4;
#endif
	} BIT;
	} ODR1;
	char           wk4[59];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char  : 2;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char  : 2;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PCR;
} st_port3_t;

typedef struct st_port4 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PODR;
	char           wk1[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PIDR;
	char           wk2[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PMR;
	char           wk3[95];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PCR;
} st_port4_t;

typedef struct st_port7 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PODR;
	char           wk1[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PIDR;
	char           wk2[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PMR;
	char           wk3[38];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR1;
	char           wk4[55];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PCR;
} st_port7_t;

typedef struct st_port9 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PODR;
	char           wk1[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PIDR;
	char           wk2[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PMR;
	char           wk3[40];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR1;
	char           wk4[53];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PCR;
} st_port9_t;

typedef struct st_portb {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PODR;
	char           wk1[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PIDR;
	char           wk2[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PMR;
	char           wk3[42];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR1;
	char           wk4[51];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char B1 : 1;
			unsigned char B2 : 1;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char B2 : 1;
			unsigned char B1 : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} PCR;
} st_portb_t;

typedef struct st_portd {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 3;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char  : 3;
#endif
	} BIT;
	} PDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 3;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char  : 3;
#endif
	} BIT;
	} PODR;
	char           wk1[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 3;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char  : 3;
#endif
	} BIT;
	} PIDR;
	char           wk2[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 3;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char  : 3;
#endif
	} BIT;
	} PMR;
	char           wk3[44];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 6;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 6;
#endif
	} BIT;
	} ODR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char B0 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 1;
			unsigned char B4 : 1;
			unsigned char  : 1;
			unsigned char B2 : 1;
			unsigned char  : 1;
			unsigned char B0 : 1;
#endif
	} BIT;
	} ODR1;
	char           wk4[49];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 3;
			unsigned char B3 : 1;
			unsigned char B4 : 1;
			unsigned char B5 : 1;
			unsigned char B6 : 1;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char B6 : 1;
			unsigned char B5 : 1;
			unsigned char B4 : 1;
			unsigned char B3 : 1;
			unsigned char  : 3;
#endif
	} BIT;
	} PCR;
} st_portd_t;

typedef struct st_porte {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 2;
			unsigned char B2 : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char B2 : 1;
			unsigned char  : 2;
#endif
	} BIT;
	} PIDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 2;
			unsigned char B2 : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char B2 : 1;
			unsigned char  : 2;
#endif
	} BIT;
	} PMR;
} st_porte_t;

typedef struct st_portg {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} PDR;
	char           wk0[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} PODR;
	char           wk1[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} PIDR;
	char           wk2[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} PMR;
	char           wk3[48];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 6;
			unsigned char B6 : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char B6 : 1;
			unsigned char  : 6;
#endif
	} BIT;
	} ODR1;
	char           wk4[46];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 7;
			unsigned char B7 : 1;
#else
			unsigned char B7 : 1;
			unsigned char  : 7;
#endif
	} BIT;
	} PCR;
} st_portg_t;

typedef struct st_riic {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SDAI : 1;
			unsigned char SCLI : 1;
			unsigned char SDAO : 1;
			unsigned char SCLO : 1;
			unsigned char SOWP : 1;
			unsigned char CLO : 1;
			unsigned char IICRST : 1;
			unsigned char ICE : 1;
#else
			unsigned char ICE : 1;
			unsigned char IICRST : 1;
			unsigned char CLO : 1;
			unsigned char SOWP : 1;
			unsigned char SCLO : 1;
			unsigned char SDAO : 1;
			unsigned char SCLI : 1;
			unsigned char SDAI : 1;
#endif
	} BIT;
	} ICCR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 1;
			unsigned char ST : 1;
			unsigned char RS : 1;
			unsigned char SP : 1;
			unsigned char  : 1;
			unsigned char TRS : 1;
			unsigned char MST : 1;
			unsigned char BBSY : 1;
#else
			unsigned char BBSY : 1;
			unsigned char MST : 1;
			unsigned char TRS : 1;
			unsigned char  : 1;
			unsigned char SP : 1;
			unsigned char RS : 1;
			unsigned char ST : 1;
			unsigned char  : 1;
#endif
	} BIT;
	} ICCR2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char BC : 3;
			unsigned char BCWP : 1;
			unsigned char CKS : 3;
			unsigned char MTWP : 1;
#else
			unsigned char MTWP : 1;
			unsigned char CKS : 3;
			unsigned char BCWP : 1;
			unsigned char BC : 3;
#endif
	} BIT;
	} ICMR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TMOS : 1;
			unsigned char TMOL : 1;
			unsigned char TMOH : 1;
			unsigned char  : 1;
			unsigned char SDDL : 3;
			unsigned char DLCS : 1;
#else
			unsigned char DLCS : 1;
			unsigned char SDDL : 3;
			unsigned char  : 1;
			unsigned char TMOH : 1;
			unsigned char TMOL : 1;
			unsigned char TMOS : 1;
#endif
	} BIT;
	} ICMR2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NF : 2;
			unsigned char ACKBR : 1;
			unsigned char ACKBT : 1;
			unsigned char ACKWP : 1;
			unsigned char RDRFS : 1;
			unsigned char WAIT : 1;
			unsigned char SMBS : 1;
#else
			unsigned char SMBS : 1;
			unsigned char WAIT : 1;
			unsigned char RDRFS : 1;
			unsigned char ACKWP : 1;
			unsigned char ACKBT : 1;
			unsigned char ACKBR : 1;
			unsigned char NF : 2;
#endif
	} BIT;
	} ICMR3;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TMOE : 1;
			unsigned char MALE : 1;
			unsigned char NALE : 1;
			unsigned char SALE : 1;
			unsigned char NACKE : 1;
			unsigned char NFE : 1;
			unsigned char SCLE : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char SCLE : 1;
			unsigned char NFE : 1;
			unsigned char NACKE : 1;
			unsigned char SALE : 1;
			unsigned char NALE : 1;
			unsigned char MALE : 1;
			unsigned char TMOE : 1;
#endif
	} BIT;
	} ICFER;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SAR0E : 1;
			unsigned char SAR1E : 1;
			unsigned char SAR2E : 1;
			unsigned char GCAE : 1;
			unsigned char  : 1;
			unsigned char DIDE : 1;
			unsigned char  : 1;
			unsigned char HOAE : 1;
#else
			unsigned char HOAE : 1;
			unsigned char  : 1;
			unsigned char DIDE : 1;
			unsigned char  : 1;
			unsigned char GCAE : 1;
			unsigned char SAR2E : 1;
			unsigned char SAR1E : 1;
			unsigned char SAR0E : 1;
#endif
	} BIT;
	} ICSER;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TMOIE : 1;
			unsigned char ALIE : 1;
			unsigned char STIE : 1;
			unsigned char SPIE : 1;
			unsigned char NAKIE : 1;
			unsigned char RIE : 1;
			unsigned char TEIE : 1;
			unsigned char TIE : 1;
#else
			unsigned char TIE : 1;
			unsigned char TEIE : 1;
			unsigned char RIE : 1;
			unsigned char NAKIE : 1;
			unsigned char SPIE : 1;
			unsigned char STIE : 1;
			unsigned char ALIE : 1;
			unsigned char TMOIE : 1;
#endif
	} BIT;
	} ICIER;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char AAS0 : 1;
			unsigned char AAS1 : 1;
			unsigned char AAS2 : 1;
			unsigned char GCA : 1;
			unsigned char  : 1;
			unsigned char DID : 1;
			unsigned char  : 1;
			unsigned char HOA : 1;
#else
			unsigned char HOA : 1;
			unsigned char  : 1;
			unsigned char DID : 1;
			unsigned char  : 1;
			unsigned char GCA : 1;
			unsigned char AAS2 : 1;
			unsigned char AAS1 : 1;
			unsigned char AAS0 : 1;
#endif
	} BIT;
	} ICSR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TMOF : 1;
			unsigned char AL : 1;
			unsigned char START : 1;
			unsigned char STOP : 1;
			unsigned char NACKF : 1;
			unsigned char RDRF : 1;
			unsigned char TEND : 1;
			unsigned char TDRE : 1;
#else
			unsigned char TDRE : 1;
			unsigned char TEND : 1;
			unsigned char RDRF : 1;
			unsigned char NACKF : 1;
			unsigned char STOP : 1;
			unsigned char START : 1;
			unsigned char AL : 1;
			unsigned char TMOF : 1;
#endif
	} BIT;
	} ICSR2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SVA0 : 1;
			unsigned char SVA : 7;
#else
			unsigned char SVA : 7;
			unsigned char SVA0 : 1;
#endif
	} BIT;
	} SARL0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char FS : 1;
			unsigned char SVA : 2;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char SVA : 2;
			unsigned char FS : 1;
#endif
	} BIT;
	} SARU0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SVA0 : 1;
			unsigned char SVA : 7;
#else
			unsigned char SVA : 7;
			unsigned char SVA0 : 1;
#endif
	} BIT;
	} SARL1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char FS : 1;
			unsigned char SVA : 2;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char SVA : 2;
			unsigned char FS : 1;
#endif
	} BIT;
	} SARU1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SVA0 : 1;
			unsigned char SVA : 7;
#else
			unsigned char SVA : 7;
			unsigned char SVA0 : 1;
#endif
	} BIT;
	} SARL2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char FS : 1;
			unsigned char SVA : 2;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char SVA : 2;
			unsigned char FS : 1;
#endif
	} BIT;
	} SARU2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char BRL : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char BRL : 5;
#endif
	} BIT;
	} ICBRL;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char BRH : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char BRH : 5;
#endif
	} BIT;
	} ICBRH;
	unsigned char  ICDRT;
	unsigned char  ICDRR;
} st_riic_t;

typedef struct st_s12ad {
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short DBLANS : 5;
			unsigned short  : 1;
			unsigned short GBADIE : 1;
			unsigned short DBLE : 1;
			unsigned short EXTRG : 1;
			unsigned short TRGE : 1;
			unsigned short  : 2;
			unsigned short ADIE : 1;
			unsigned short ADCS : 2;
			unsigned short ADST : 1;
#else
			unsigned short ADST : 1;
			unsigned short ADCS : 2;
			unsigned short ADIE : 1;
			unsigned short  : 2;
			unsigned short TRGE : 1;
			unsigned short EXTRG : 1;
			unsigned short DBLE : 1;
			unsigned short GBADIE : 1;
			unsigned short  : 1;
			unsigned short DBLANS : 5;
#endif
	} BIT;
	} ADCSR;
	char           wk0[2];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short ANSA000 : 1;
			unsigned short ANSA001 : 1;
			unsigned short ANSA002 : 1;
			unsigned short ANSA003 : 1;
			unsigned short ANSA004 : 1;
			unsigned short ANSA005 : 1;
			unsigned short ANSA006 : 1;
			unsigned short ANSA007 : 1;
			unsigned short  : 8;
#else
			unsigned short  : 8;
			unsigned short ANSA007 : 1;
			unsigned short ANSA006 : 1;
			unsigned short ANSA005 : 1;
			unsigned short ANSA004 : 1;
			unsigned short ANSA003 : 1;
			unsigned short ANSA002 : 1;
			unsigned short ANSA001 : 1;
			unsigned short ANSA000 : 1;
#endif
	} BIT;
	} ADANSA0;
	char           wk1[2];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short ADS000 : 1;
			unsigned short ADS001 : 1;
			unsigned short ADS002 : 1;
			unsigned short ADS003 : 1;
			unsigned short ADS004 : 1;
			unsigned short ADS005 : 1;
			unsigned short ADS006 : 1;
			unsigned short ADS007 : 1;
			unsigned short  : 8;
#else
			unsigned short  : 8;
			unsigned short ADS007 : 1;
			unsigned short ADS006 : 1;
			unsigned short ADS005 : 1;
			unsigned short ADS004 : 1;
			unsigned short ADS003 : 1;
			unsigned short ADS002 : 1;
			unsigned short ADS001 : 1;
			unsigned short ADS000 : 1;
#endif
	} BIT;
	} ADADS0;
	char           wk2[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char ADC : 3;
			unsigned char  : 4;
			unsigned char AVEE : 1;
#else
			unsigned char AVEE : 1;
			unsigned char  : 4;
			unsigned char ADC : 3;
#endif
	} BIT;
	} ADADC;
	char           wk3[1];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 5;
			unsigned short ACE : 1;
			unsigned short  : 2;
			unsigned short DIAGVAL : 2;
			unsigned short DIAGLD : 1;
			unsigned short DIAGM : 1;
			unsigned short  : 3;
			unsigned short ADRFMT : 1;
#else
			unsigned short ADRFMT : 1;
			unsigned short  : 3;
			unsigned short DIAGM : 1;
			unsigned short DIAGLD : 1;
			unsigned short DIAGVAL : 2;
			unsigned short  : 2;
			unsigned short ACE : 1;
			unsigned short  : 5;
#endif
	} BIT;
	} ADCER;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short TRSB : 6;
			unsigned short  : 2;
			unsigned short TRSA : 6;
			unsigned short  : 2;
#else
			unsigned short  : 2;
			unsigned short TRSA : 6;
			unsigned short  : 2;
			unsigned short TRSB : 6;
#endif
	} BIT;
	} ADSTRGR;
	char           wk4[2];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short ANSB000 : 1;
			unsigned short ANSB001 : 1;
			unsigned short ANSB002 : 1;
			unsigned short ANSB003 : 1;
			unsigned short ANSB004 : 1;
			unsigned short ANSB005 : 1;
			unsigned short ANSB006 : 1;
			unsigned short ANSB007 : 1;
			unsigned short  : 8;
#else
			unsigned short  : 8;
			unsigned short ANSB007 : 1;
			unsigned short ANSB006 : 1;
			unsigned short ANSB005 : 1;
			unsigned short ANSB004 : 1;
			unsigned short ANSB003 : 1;
			unsigned short ANSB002 : 1;
			unsigned short ANSB001 : 1;
			unsigned short ANSB000 : 1;
#endif
	} BIT;
	} ADANSB0;
	char           wk5[2];
	unsigned short ADDBLDR;
	char           wk6[4];
	union {
		unsigned short WORD;
		union {
			struct {
				
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short AD : 12;
			unsigned short  : 2;
			unsigned short DIAGST : 2;
#else
			unsigned short DIAGST : 2;
			unsigned short  : 2;
			unsigned short AD : 12;
#endif
	} RIGHT;
			struct {
				
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short DIAGST : 2;
			unsigned short  : 2;
			unsigned short AD : 12;
#else
			unsigned short AD : 12;
			unsigned short  : 2;
			unsigned short DIAGST : 2;
#endif
	} LEFT;
		} BIT;
	} ADRD;
	unsigned short ADDR0;
	unsigned short ADDR1;
	unsigned short ADDR2;
	unsigned short ADDR3;
	unsigned short ADDR4;
	unsigned short ADDR5;
	unsigned short ADDR6;
	unsigned short ADDR7;
	char           wk7[74];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char ADNDIS : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char ADNDIS : 5;
#endif
	} BIT;
	} ADDISCR;
	char           wk8[5];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short PGS : 1;
			unsigned short GBRSCN : 1;
			unsigned short  : 12;
			unsigned short LGRRS : 1;
			unsigned short GBRP : 1;
#else
			unsigned short GBRP : 1;
			unsigned short LGRRS : 1;
			unsigned short  : 12;
			unsigned short GBRSCN : 1;
			unsigned short PGS : 1;
#endif
	} BIT;
	} ADGSPCR;
	char           wk9[2];
	unsigned short ADDBLDRA;
	unsigned short ADDBLDRB;
	char           wk10[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char HVSEL : 2;
			unsigned char  : 2;
			unsigned char LVSEL : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char LVSEL : 1;
			unsigned char  : 2;
			unsigned char HVSEL : 2;
#endif
	} BIT;
	} ADHVREFCNT;
	char           wk11[73];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short ANSC000 : 1;
			unsigned short ANSC001 : 1;
			unsigned short ANSC002 : 1;
			unsigned short ANSC003 : 1;
			unsigned short ANSC004 : 1;
			unsigned short ANSC005 : 1;
			unsigned short ANSC006 : 1;
			unsigned short ANSC007 : 1;
			unsigned short  : 8;
#else
			unsigned short  : 8;
			unsigned short ANSC007 : 1;
			unsigned short ANSC006 : 1;
			unsigned short ANSC005 : 1;
			unsigned short ANSC004 : 1;
			unsigned short ANSC003 : 1;
			unsigned short ANSC002 : 1;
			unsigned short ANSC001 : 1;
			unsigned short ANSC000 : 1;
#endif
	} BIT;
	} ADANSC0;
	char           wk12[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TRSC : 6;
			unsigned char GCADIE : 1;
			unsigned char GRCE : 1;
#else
			unsigned char GRCE : 1;
			unsigned char GCADIE : 1;
			unsigned char TRSC : 6;
#endif
	} BIT;
	} ADGCTRGR;
	char           wk13[6];
	unsigned char  ADSSTR0;
	unsigned char  ADSSTR1;
	unsigned char  ADSSTR2;
	unsigned char  ADSSTR3;
	unsigned char  ADSSTR4;
	unsigned char  ADSSTR5;
	unsigned char  ADSSTR6;
	unsigned char  ADSSTR7;
} st_s12ad_t;

typedef struct st_s12ad1 {
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short DBLANS : 5;
			unsigned short  : 1;
			unsigned short GBADIE : 1;
			unsigned short DBLE : 1;
			unsigned short EXTRG : 1;
			unsigned short TRGE : 1;
			unsigned short  : 2;
			unsigned short ADIE : 1;
			unsigned short ADCS : 2;
			unsigned short ADST : 1;
#else
			unsigned short ADST : 1;
			unsigned short ADCS : 2;
			unsigned short ADIE : 1;
			unsigned short  : 2;
			unsigned short TRGE : 1;
			unsigned short EXTRG : 1;
			unsigned short DBLE : 1;
			unsigned short GBADIE : 1;
			unsigned short  : 1;
			unsigned short DBLANS : 5;
#endif
	} BIT;
	} ADCSR;
	char           wk0[2];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short ANSA000 : 1;
			unsigned short ANSA001 : 1;
			unsigned short ANSA002 : 1;
			unsigned short ANSA003 : 1;
			unsigned short ANSA004 : 1;
			unsigned short ANSA005 : 1;
			unsigned short ANSA006 : 1;
			unsigned short ANSA007 : 1;
			unsigned short  : 8;
#else
			unsigned short  : 8;
			unsigned short ANSA007 : 1;
			unsigned short ANSA006 : 1;
			unsigned short ANSA005 : 1;
			unsigned short ANSA004 : 1;
			unsigned short ANSA003 : 1;
			unsigned short ANSA002 : 1;
			unsigned short ANSA001 : 1;
			unsigned short ANSA000 : 1;
#endif
	} BIT;
	} ADANSA0;
	char           wk1[2];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short ADS000 : 1;
			unsigned short ADS001 : 1;
			unsigned short ADS002 : 1;
			unsigned short ADS003 : 1;
			unsigned short ADS004 : 1;
			unsigned short ADS005 : 1;
			unsigned short ADS006 : 1;
			unsigned short ADS007 : 1;
			unsigned short  : 8;
#else
			unsigned short  : 8;
			unsigned short ADS007 : 1;
			unsigned short ADS006 : 1;
			unsigned short ADS005 : 1;
			unsigned short ADS004 : 1;
			unsigned short ADS003 : 1;
			unsigned short ADS002 : 1;
			unsigned short ADS001 : 1;
			unsigned short ADS000 : 1;
#endif
	} BIT;
	} ADADS0;
	char           wk2[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char ADC : 3;
			unsigned char  : 4;
			unsigned char AVEE : 1;
#else
			unsigned char AVEE : 1;
			unsigned char  : 4;
			unsigned char ADC : 3;
#endif
	} BIT;
	} ADADC;
	char           wk3[1];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 5;
			unsigned short ACE : 1;
			unsigned short  : 2;
			unsigned short DIAGVAL : 2;
			unsigned short DIAGLD : 1;
			unsigned short DIAGM : 1;
			unsigned short  : 3;
			unsigned short ADRFMT : 1;
#else
			unsigned short ADRFMT : 1;
			unsigned short  : 3;
			unsigned short DIAGM : 1;
			unsigned short DIAGLD : 1;
			unsigned short DIAGVAL : 2;
			unsigned short  : 2;
			unsigned short ACE : 1;
			unsigned short  : 5;
#endif
	} BIT;
	} ADCER;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short TRSB : 6;
			unsigned short  : 2;
			unsigned short TRSA : 6;
			unsigned short  : 2;
#else
			unsigned short  : 2;
			unsigned short TRSA : 6;
			unsigned short  : 2;
			unsigned short TRSB : 6;
#endif
	} BIT;
	} ADSTRGR;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short TSSAD : 1;
			unsigned short OCSAD : 1;
			unsigned short  : 6;
			unsigned short TSSA : 1;
			unsigned short OCSA : 1;
			unsigned short  : 6;
#else
			unsigned short  : 6;
			unsigned short OCSA : 1;
			unsigned short TSSA : 1;
			unsigned short  : 6;
			unsigned short OCSAD : 1;
			unsigned short TSSAD : 1;
#endif
	} BIT;
	} ADEXICR;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short ANSB000 : 1;
			unsigned short ANSB001 : 1;
			unsigned short ANSB002 : 1;
			unsigned short ANSB003 : 1;
			unsigned short ANSB004 : 1;
			unsigned short ANSB005 : 1;
			unsigned short ANSB006 : 1;
			unsigned short ANSB007 : 1;
			unsigned short  : 8;
#else
			unsigned short  : 8;
			unsigned short ANSB007 : 1;
			unsigned short ANSB006 : 1;
			unsigned short ANSB005 : 1;
			unsigned short ANSB004 : 1;
			unsigned short ANSB003 : 1;
			unsigned short ANSB002 : 1;
			unsigned short ANSB001 : 1;
			unsigned short ANSB000 : 1;
#endif
	} BIT;
	} ADANSB0;
	char           wk4[2];
	unsigned short ADDBLDR;
	unsigned short ADTSDR;
	unsigned short ADOCDR;
	union {
		unsigned short WORD;
		union {
			struct {
				
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short AD : 12;
			unsigned short  : 2;
			unsigned short DIAGST : 2;
#else
			unsigned short DIAGST : 2;
			unsigned short  : 2;
			unsigned short AD : 12;
#endif
	} RIGHT;
			struct {
				
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short DIAGST : 2;
			unsigned short  : 2;
			unsigned short AD : 12;
#else
			unsigned short AD : 12;
			unsigned short  : 2;
			unsigned short DIAGST : 2;
#endif
	} LEFT;
		} BIT;
	} ADRD;
	unsigned short ADDR0;
	unsigned short ADDR1;
	unsigned short ADDR2;
	unsigned short ADDR3;
	unsigned short ADDR4;
	unsigned short ADDR5;
	unsigned short ADDR6;
	unsigned short ADDR7;
	char           wk5[74];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char ADNDIS : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char ADNDIS : 5;
#endif
	} BIT;
	} ADDISCR;
	char           wk6[5];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short PGS : 1;
			unsigned short GBRSCN : 1;
			unsigned short  : 12;
			unsigned short LGRRS : 1;
			unsigned short GBRP : 1;
#else
			unsigned short GBRP : 1;
			unsigned short LGRRS : 1;
			unsigned short  : 12;
			unsigned short GBRSCN : 1;
			unsigned short PGS : 1;
#endif
	} BIT;
	} ADGSPCR;
	char           wk7[2];
	unsigned short ADDBLDRA;
	unsigned short ADDBLDRB;
	char           wk8[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char HVSEL : 2;
			unsigned char  : 2;
			unsigned char LVSEL : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char LVSEL : 1;
			unsigned char  : 2;
			unsigned char HVSEL : 2;
#endif
	} BIT;
	} ADHVREFCNT;
	char           wk9[73];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short ANSC000 : 1;
			unsigned short ANSC001 : 1;
			unsigned short ANSC002 : 1;
			unsigned short ANSC003 : 1;
			unsigned short ANSC004 : 1;
			unsigned short ANSC005 : 1;
			unsigned short ANSC006 : 1;
			unsigned short ANSC007 : 1;
			unsigned short  : 8;
#else
			unsigned short  : 8;
			unsigned short ANSC007 : 1;
			unsigned short ANSC006 : 1;
			unsigned short ANSC005 : 1;
			unsigned short ANSC004 : 1;
			unsigned short ANSC003 : 1;
			unsigned short ANSC002 : 1;
			unsigned short ANSC001 : 1;
			unsigned short ANSC000 : 1;
#endif
	} BIT;
	} ADANSC0;
	char           wk10[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TRSC : 6;
			unsigned char GCADIE : 1;
			unsigned char GRCE : 1;
#else
			unsigned char GRCE : 1;
			unsigned char GCADIE : 1;
			unsigned char TRSC : 6;
#endif
	} BIT;
	} ADGCTRGR;
	char           wk11[4];
	unsigned char  ADSSTRT;
	unsigned char  ADSSTRO;
	unsigned char  ADSSTR0;
	unsigned char  ADSSTR1;
	unsigned char  ADSSTR2;
	unsigned char  ADSSTR3;
	unsigned char  ADSSTR4;
	unsigned char  ADSSTR5;
	unsigned char  ADSSTR6;
	unsigned char  ADSSTR7;
} st_s12ad1_t;

typedef struct st_sci1 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CKS : 2;
			unsigned char MP : 1;
			unsigned char STOP : 1;
			unsigned char PM : 1;
			unsigned char PE : 1;
			unsigned char CHR : 1;
			unsigned char CM : 1;
#else
			unsigned char CM : 1;
			unsigned char CHR : 1;
			unsigned char PE : 1;
			unsigned char PM : 1;
			unsigned char STOP : 1;
			unsigned char MP : 1;
			unsigned char CKS : 2;
#endif
	} BIT;
	} SMR;
	unsigned char  BRR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CKE : 2;
			unsigned char TEIE : 1;
			unsigned char MPIE : 1;
			unsigned char RE : 1;
			unsigned char TE : 1;
			unsigned char RIE : 1;
			unsigned char TIE : 1;
#else
			unsigned char TIE : 1;
			unsigned char RIE : 1;
			unsigned char TE : 1;
			unsigned char RE : 1;
			unsigned char MPIE : 1;
			unsigned char TEIE : 1;
			unsigned char CKE : 2;
#endif
	} BIT;
	} SCR;
	unsigned char  TDR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MPBT : 1;
			unsigned char MPB : 1;
			unsigned char TEND : 1;
			unsigned char PER : 1;
			unsigned char FER : 1;
			unsigned char ORER : 1;
			unsigned char RDRF : 1;
			unsigned char TDRE : 1;
#else
			unsigned char TDRE : 1;
			unsigned char RDRF : 1;
			unsigned char ORER : 1;
			unsigned char FER : 1;
			unsigned char PER : 1;
			unsigned char TEND : 1;
			unsigned char MPB : 1;
			unsigned char MPBT : 1;
#endif
	} BIT;
	} SSR;
	unsigned char  RDR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SMIF : 1;
			unsigned char  : 1;
			unsigned char SINV : 1;
			unsigned char SDIR : 1;
			unsigned char CHR1 : 1;
			unsigned char  : 2;
			unsigned char BCP2 : 1;
#else
			unsigned char BCP2 : 1;
			unsigned char  : 2;
			unsigned char CHR1 : 1;
			unsigned char SDIR : 1;
			unsigned char SINV : 1;
			unsigned char  : 1;
			unsigned char SMIF : 1;
#endif
	} BIT;
	} SCMR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char ACS0 : 1;
			unsigned char  : 1;
			unsigned char BRME : 1;
			unsigned char  : 1;
			unsigned char ABCS : 1;
			unsigned char NFEN : 1;
			unsigned char BGDM : 1;
			unsigned char RXDESEL : 1;
#else
			unsigned char RXDESEL : 1;
			unsigned char BGDM : 1;
			unsigned char NFEN : 1;
			unsigned char ABCS : 1;
			unsigned char  : 1;
			unsigned char BRME : 1;
			unsigned char  : 1;
			unsigned char ACS0 : 1;
#endif
	} BIT;
	} SEMR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFCS : 3;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char NFCS : 3;
#endif
	} BIT;
	} SNFR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IICM : 1;
			unsigned char  : 2;
			unsigned char IICDL : 5;
#else
			unsigned char IICDL : 5;
			unsigned char  : 2;
			unsigned char IICM : 1;
#endif
	} BIT;
	} SIMR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IICINTM : 1;
			unsigned char IICCSC : 1;
			unsigned char  : 3;
			unsigned char IICACKT : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char IICACKT : 1;
			unsigned char  : 3;
			unsigned char IICCSC : 1;
			unsigned char IICINTM : 1;
#endif
	} BIT;
	} SIMR2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IICSTAREQ : 1;
			unsigned char IICRSTAREQ : 1;
			unsigned char IICSTPREQ : 1;
			unsigned char IICSTIF : 1;
			unsigned char IICSDAS : 2;
			unsigned char IICSCLS : 2;
#else
			unsigned char IICSCLS : 2;
			unsigned char IICSDAS : 2;
			unsigned char IICSTIF : 1;
			unsigned char IICSTPREQ : 1;
			unsigned char IICRSTAREQ : 1;
			unsigned char IICSTAREQ : 1;
#endif
	} BIT;
	} SIMR3;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IICACKR : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char IICACKR : 1;
#endif
	} BIT;
	} SISR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SSE : 1;
			unsigned char CTSE : 1;
			unsigned char MSS : 1;
			unsigned char  : 1;
			unsigned char MFF : 1;
			unsigned char  : 1;
			unsigned char CKPOL : 1;
			unsigned char CKPH : 1;
#else
			unsigned char CKPH : 1;
			unsigned char CKPOL : 1;
			unsigned char  : 1;
			unsigned char MFF : 1;
			unsigned char  : 1;
			unsigned char MSS : 1;
			unsigned char CTSE : 1;
			unsigned char SSE : 1;
#endif
	} BIT;
	} SPMR;
	union {
		unsigned short WORD;
		struct {
			unsigned char TDRH;
			unsigned char TDRL;
		} BYTE;
	} TDRHL;
	union {
		unsigned short WORD;
		struct {
			unsigned char RDRH;
			unsigned char RDRL;
		} BYTE;
	} RDRHL;
	unsigned char  MDDR;
} st_sci1_t;

typedef struct st_sci12 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CKS : 2;
			unsigned char MP : 1;
			unsigned char STOP : 1;
			unsigned char PM : 1;
			unsigned char PE : 1;
			unsigned char CHR : 1;
			unsigned char CM : 1;
#else
			unsigned char CM : 1;
			unsigned char CHR : 1;
			unsigned char PE : 1;
			unsigned char PM : 1;
			unsigned char STOP : 1;
			unsigned char MP : 1;
			unsigned char CKS : 2;
#endif
	} BIT;
	} SMR;
	unsigned char  BRR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CKE : 2;
			unsigned char TEIE : 1;
			unsigned char MPIE : 1;
			unsigned char RE : 1;
			unsigned char TE : 1;
			unsigned char RIE : 1;
			unsigned char TIE : 1;
#else
			unsigned char TIE : 1;
			unsigned char RIE : 1;
			unsigned char TE : 1;
			unsigned char RE : 1;
			unsigned char MPIE : 1;
			unsigned char TEIE : 1;
			unsigned char CKE : 2;
#endif
	} BIT;
	} SCR;
	unsigned char  TDR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MPBT : 1;
			unsigned char MPB : 1;
			unsigned char TEND : 1;
			unsigned char PER : 1;
			unsigned char FER : 1;
			unsigned char ORER : 1;
			unsigned char RDRF : 1;
			unsigned char TDRE : 1;
#else
			unsigned char TDRE : 1;
			unsigned char RDRF : 1;
			unsigned char ORER : 1;
			unsigned char FER : 1;
			unsigned char PER : 1;
			unsigned char TEND : 1;
			unsigned char MPB : 1;
			unsigned char MPBT : 1;
#endif
	} BIT;
	} SSR;
	unsigned char  RDR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SMIF : 1;
			unsigned char  : 1;
			unsigned char SINV : 1;
			unsigned char SDIR : 1;
			unsigned char CHR1 : 1;
			unsigned char  : 2;
			unsigned char BCP2 : 1;
#else
			unsigned char BCP2 : 1;
			unsigned char  : 2;
			unsigned char CHR1 : 1;
			unsigned char SDIR : 1;
			unsigned char SINV : 1;
			unsigned char  : 1;
			unsigned char SMIF : 1;
#endif
	} BIT;
	} SCMR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char ACS0 : 1;
			unsigned char  : 1;
			unsigned char BRME : 1;
			unsigned char  : 1;
			unsigned char ABCS : 1;
			unsigned char NFEN : 1;
			unsigned char BGDM : 1;
			unsigned char RXDESEL : 1;
#else
			unsigned char RXDESEL : 1;
			unsigned char BGDM : 1;
			unsigned char NFEN : 1;
			unsigned char ABCS : 1;
			unsigned char  : 1;
			unsigned char BRME : 1;
			unsigned char  : 1;
			unsigned char ACS0 : 1;
#endif
	} BIT;
	} SEMR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char NFCS : 3;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char NFCS : 3;
#endif
	} BIT;
	} SNFR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IICM : 1;
			unsigned char  : 2;
			unsigned char IICDL : 5;
#else
			unsigned char IICDL : 5;
			unsigned char  : 2;
			unsigned char IICM : 1;
#endif
	} BIT;
	} SIMR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IICINTM : 1;
			unsigned char IICCSC : 1;
			unsigned char  : 3;
			unsigned char IICACKT : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char IICACKT : 1;
			unsigned char  : 3;
			unsigned char IICCSC : 1;
			unsigned char IICINTM : 1;
#endif
	} BIT;
	} SIMR2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IICSTAREQ : 1;
			unsigned char IICRSTAREQ : 1;
			unsigned char IICSTPREQ : 1;
			unsigned char IICSTIF : 1;
			unsigned char IICSDAS : 2;
			unsigned char IICSCLS : 2;
#else
			unsigned char IICSCLS : 2;
			unsigned char IICSDAS : 2;
			unsigned char IICSTIF : 1;
			unsigned char IICSTPREQ : 1;
			unsigned char IICRSTAREQ : 1;
			unsigned char IICSTAREQ : 1;
#endif
	} BIT;
	} SIMR3;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IICACKR : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char IICACKR : 1;
#endif
	} BIT;
	} SISR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SSE : 1;
			unsigned char CTSE : 1;
			unsigned char MSS : 1;
			unsigned char  : 1;
			unsigned char MFF : 1;
			unsigned char  : 1;
			unsigned char CKPOL : 1;
			unsigned char CKPH : 1;
#else
			unsigned char CKPH : 1;
			unsigned char CKPOL : 1;
			unsigned char  : 1;
			unsigned char MFF : 1;
			unsigned char  : 1;
			unsigned char MSS : 1;
			unsigned char CTSE : 1;
			unsigned char SSE : 1;
#endif
	} BIT;
	} SPMR;
	union {
		unsigned short WORD;
		struct {
			unsigned char TDRH;
			unsigned char TDRL;
		} BYTE;
	} TDRHL;
	union {
		unsigned short WORD;
		struct {
			unsigned char RDRH;
			unsigned char RDRL;
		} BYTE;
	} RDRHL;
	unsigned char  MDDR;
	char           wk0[13];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char ESME : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char ESME : 1;
#endif
	} BIT;
	} ESMER;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 1;
			unsigned char SFSF : 1;
			unsigned char RXDSF : 1;
			unsigned char BRME : 1;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char BRME : 1;
			unsigned char RXDSF : 1;
			unsigned char SFSF : 1;
			unsigned char  : 1;
#endif
	} BIT;
	} CR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char BFE : 1;
			unsigned char CF0RE : 1;
			unsigned char CF1DS : 2;
			unsigned char PIBE : 1;
			unsigned char PIBS : 3;
#else
			unsigned char PIBS : 3;
			unsigned char PIBE : 1;
			unsigned char CF1DS : 2;
			unsigned char CF0RE : 1;
			unsigned char BFE : 1;
#endif
	} BIT;
	} CR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char DFCS : 3;
			unsigned char  : 1;
			unsigned char BCCS : 2;
			unsigned char RTS : 2;
#else
			unsigned char RTS : 2;
			unsigned char BCCS : 2;
			unsigned char  : 1;
			unsigned char DFCS : 3;
#endif
	} BIT;
	} CR2;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SDST : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char SDST : 1;
#endif
	} BIT;
	} CR3;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TXDXPS : 1;
			unsigned char RXDXPS : 1;
			unsigned char  : 2;
			unsigned char SHARPS : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char SHARPS : 1;
			unsigned char  : 2;
			unsigned char RXDXPS : 1;
			unsigned char TXDXPS : 1;
#endif
	} BIT;
	} PCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char BFDIE : 1;
			unsigned char CF0MIE : 1;
			unsigned char CF1MIE : 1;
			unsigned char PIBDIE : 1;
			unsigned char BCDIE : 1;
			unsigned char AEDIE : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char AEDIE : 1;
			unsigned char BCDIE : 1;
			unsigned char PIBDIE : 1;
			unsigned char CF1MIE : 1;
			unsigned char CF0MIE : 1;
			unsigned char BFDIE : 1;
#endif
	} BIT;
	} ICR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char BFDF : 1;
			unsigned char CF0MF : 1;
			unsigned char CF1MF : 1;
			unsigned char PIBDF : 1;
			unsigned char BCDF : 1;
			unsigned char AEDF : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char AEDF : 1;
			unsigned char BCDF : 1;
			unsigned char PIBDF : 1;
			unsigned char CF1MF : 1;
			unsigned char CF0MF : 1;
			unsigned char BFDF : 1;
#endif
	} BIT;
	} STR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char BFDCL : 1;
			unsigned char CF0MCL : 1;
			unsigned char CF1MCL : 1;
			unsigned char PIBDCL : 1;
			unsigned char BCDCL : 1;
			unsigned char AEDCL : 1;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char AEDCL : 1;
			unsigned char BCDCL : 1;
			unsigned char PIBDCL : 1;
			unsigned char CF1MCL : 1;
			unsigned char CF0MCL : 1;
			unsigned char BFDCL : 1;
#endif
	} BIT;
	} STCR;
	unsigned char  CF0DR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CF0CE0 : 1;
			unsigned char CF0CE1 : 1;
			unsigned char CF0CE2 : 1;
			unsigned char CF0CE3 : 1;
			unsigned char CF0CE4 : 1;
			unsigned char CF0CE5 : 1;
			unsigned char CF0CE6 : 1;
			unsigned char CF0CE7 : 1;
#else
			unsigned char CF0CE7 : 1;
			unsigned char CF0CE6 : 1;
			unsigned char CF0CE5 : 1;
			unsigned char CF0CE4 : 1;
			unsigned char CF0CE3 : 1;
			unsigned char CF0CE2 : 1;
			unsigned char CF0CE1 : 1;
			unsigned char CF0CE0 : 1;
#endif
	} BIT;
	} CF0CR;
	unsigned char  CF0RR;
	unsigned char  PCF1DR;
	unsigned char  SCF1DR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CF1CE0 : 1;
			unsigned char CF1CE1 : 1;
			unsigned char CF1CE2 : 1;
			unsigned char CF1CE3 : 1;
			unsigned char CF1CE4 : 1;
			unsigned char CF1CE5 : 1;
			unsigned char CF1CE6 : 1;
			unsigned char CF1CE7 : 1;
#else
			unsigned char CF1CE7 : 1;
			unsigned char CF1CE6 : 1;
			unsigned char CF1CE5 : 1;
			unsigned char CF1CE4 : 1;
			unsigned char CF1CE3 : 1;
			unsigned char CF1CE2 : 1;
			unsigned char CF1CE1 : 1;
			unsigned char CF1CE0 : 1;
#endif
	} BIT;
	} CF1CR;
	unsigned char  CF1RR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TCST : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char TCST : 1;
#endif
	} BIT;
	} TCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char TOMS : 2;
			unsigned char  : 1;
			unsigned char TWRC : 1;
			unsigned char TCSS : 3;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char TCSS : 3;
			unsigned char TWRC : 1;
			unsigned char  : 1;
			unsigned char TOMS : 2;
#endif
	} BIT;
	} TMR;
	unsigned char  TPRE;
	unsigned char  TCNT;
} st_sci12_t;

typedef struct st_smci {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CKS : 2;
			unsigned char BCP : 2;
			unsigned char PM : 1;
			unsigned char PE : 1;
			unsigned char BLK : 1;
			unsigned char GM : 1;
#else
			unsigned char GM : 1;
			unsigned char BLK : 1;
			unsigned char PE : 1;
			unsigned char PM : 1;
			unsigned char BCP : 2;
			unsigned char CKS : 2;
#endif
	} BIT;
	} SMR;
	unsigned char  BRR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CKE : 2;
			unsigned char TEIE : 1;
			unsigned char MPIE : 1;
			unsigned char RE : 1;
			unsigned char TE : 1;
			unsigned char RIE : 1;
			unsigned char TIE : 1;
#else
			unsigned char TIE : 1;
			unsigned char RIE : 1;
			unsigned char TE : 1;
			unsigned char RE : 1;
			unsigned char MPIE : 1;
			unsigned char TEIE : 1;
			unsigned char CKE : 2;
#endif
	} BIT;
	} SCR;
	unsigned char  TDR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MPBT : 1;
			unsigned char MPB : 1;
			unsigned char TEND : 1;
			unsigned char PER : 1;
			unsigned char ERS : 1;
			unsigned char ORER : 1;
			unsigned char RDRF : 1;
			unsigned char TDRE : 1;
#else
			unsigned char TDRE : 1;
			unsigned char RDRF : 1;
			unsigned char ORER : 1;
			unsigned char ERS : 1;
			unsigned char PER : 1;
			unsigned char TEND : 1;
			unsigned char MPB : 1;
			unsigned char MPBT : 1;
#endif
	} BIT;
	} SSR;
	unsigned char  RDR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char SMIF : 1;
			unsigned char  : 1;
			unsigned char SINV : 1;
			unsigned char SDIR : 1;
			unsigned char CHR1 : 1;
			unsigned char  : 2;
			unsigned char BCP2 : 1;
#else
			unsigned char BCP2 : 1;
			unsigned char  : 2;
			unsigned char CHR1 : 1;
			unsigned char SDIR : 1;
			unsigned char SINV : 1;
			unsigned char  : 1;
			unsigned char SMIF : 1;
#endif
	} BIT;
	} SCMR;
	char           wk0[7];
	union {
		unsigned short WORD;
		struct {
			unsigned char TDRH;
			unsigned char TDRL;
		} BYTE;
	} TDRHL;
	union {
		unsigned short WORD;
		struct {
			unsigned char RDRH;
			unsigned char RDRL;
		} BYTE;
	} RDRHL;
	unsigned char  MDDR;
} st_smci_t;

typedef struct st_system {
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short MD : 1;
			unsigned short  : 15;
#else
			unsigned short  : 15;
			unsigned short MD : 1;
#endif
	} BIT;
	} MDMONR;
	char           wk0[6];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short RAME : 1;
			unsigned short  : 15;
#else
			unsigned short  : 15;
			unsigned short RAME : 1;
#endif
	} BIT;
	} SYSCR1;
	char           wk1[2];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 15;
			unsigned short SSBY : 1;
#else
			unsigned short SSBY : 1;
			unsigned short  : 15;
#endif
	} BIT;
	} SBYCR;
	char           wk2[2];
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long  : 4;
			unsigned long MSTPA4 : 1;
			unsigned long MSTPA5 : 1;
			unsigned long  : 1;
			unsigned long MSTPA7 : 1;
			unsigned long  : 1;
			unsigned long MSTPA9 : 1;
			unsigned long  : 5;
			unsigned long MSTPA15 : 1;
			unsigned long MSTPA16 : 1;
			unsigned long MSTPA17 : 1;
			unsigned long  : 1;
			unsigned long MSTPA19 : 1;
			unsigned long  : 8;
			unsigned long MSTPA28 : 1;
			unsigned long  : 3;
#else
			unsigned long  : 3;
			unsigned long MSTPA28 : 1;
			unsigned long  : 8;
			unsigned long MSTPA19 : 1;
			unsigned long  : 1;
			unsigned long MSTPA17 : 1;
			unsigned long MSTPA16 : 1;
			unsigned long MSTPA15 : 1;
			unsigned long  : 5;
			unsigned long MSTPA9 : 1;
			unsigned long  : 1;
			unsigned long MSTPA7 : 1;
			unsigned long  : 1;
			unsigned long MSTPA5 : 1;
			unsigned long MSTPA4 : 1;
			unsigned long  : 4;
#endif
	} BIT;
	} MSTPCRA;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long  : 4;
			unsigned long MSTPB4 : 1;
			unsigned long  : 1;
			unsigned long MSTPB6 : 1;
			unsigned long  : 3;
			unsigned long MSTPB10 : 1;
			unsigned long  : 10;
			unsigned long MSTPB21 : 1;
			unsigned long  : 1;
			unsigned long MSTPB23 : 1;
			unsigned long  : 1;
			unsigned long MSTPB25 : 1;
			unsigned long MSTPB26 : 1;
			unsigned long  : 3;
			unsigned long MSTPB30 : 1;
			unsigned long  : 1;
#else
			unsigned long  : 1;
			unsigned long MSTPB30 : 1;
			unsigned long  : 3;
			unsigned long MSTPB26 : 1;
			unsigned long MSTPB25 : 1;
			unsigned long  : 1;
			unsigned long MSTPB23 : 1;
			unsigned long  : 1;
			unsigned long MSTPB21 : 1;
			unsigned long  : 10;
			unsigned long MSTPB10 : 1;
			unsigned long  : 3;
			unsigned long MSTPB6 : 1;
			unsigned long  : 1;
			unsigned long MSTPB4 : 1;
			unsigned long  : 4;
#endif
	} BIT;
	} MSTPCRB;
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long MSTPC0 : 1;
			unsigned long  : 18;
			unsigned long MSTPC19 : 1;
			unsigned long  : 11;
			unsigned long DSLPE : 1;
#else
			unsigned long DSLPE : 1;
			unsigned long  : 11;
			unsigned long MSTPC19 : 1;
			unsigned long  : 18;
			unsigned long MSTPC0 : 1;
#endif
	} BIT;
	} MSTPCRC;
	char           wk3[4];
	union {
		unsigned long LONG;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned long PCKD : 4;
			unsigned long  : 4;
			unsigned long PCKB : 4;
			unsigned long  : 12;
			unsigned long ICK : 4;
			unsigned long FCK : 4;
#else
			unsigned long FCK : 4;
			unsigned long ICK : 4;
			unsigned long  : 12;
			unsigned long PCKB : 4;
			unsigned long  : 4;
			unsigned long PCKD : 4;
#endif
	} BIT;
	} SCKCR;
	char           wk4[2];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 8;
			unsigned short CKSEL : 3;
			unsigned short  : 5;
#else
			unsigned short  : 5;
			unsigned short CKSEL : 3;
			unsigned short  : 8;
#endif
	} BIT;
	} SCKCR3;
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short PLIDIV : 2;
			unsigned short PLLSRCSEL : 1;
			unsigned short  : 5;
			unsigned short STC : 6;
			unsigned short  : 2;
#else
			unsigned short  : 2;
			unsigned short STC : 6;
			unsigned short  : 5;
			unsigned short PLLSRCSEL : 1;
			unsigned short PLIDIV : 2;
#endif
	} BIT;
	} PLLCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PLLEN : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char PLLEN : 1;
#endif
	} BIT;
	} PLLCR2;
	char           wk5[7];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MOSTP : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char MOSTP : 1;
#endif
	} BIT;
	} MOSCCR;
	char           wk6[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char LCSTP : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char LCSTP : 1;
#endif
	} BIT;
	} LOCOCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char ILCSTP : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char ILCSTP : 1;
#endif
	} BIT;
	} ILOCOCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char HCSTP : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char HCSTP : 1;
#endif
	} BIT;
	} HOCOCR;
	char           wk7[5];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MOOVF : 1;
			unsigned char  : 1;
			unsigned char PLOVF : 1;
			unsigned char HCOVF : 1;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char HCOVF : 1;
			unsigned char PLOVF : 1;
			unsigned char  : 1;
			unsigned char MOOVF : 1;
#endif
	} BIT;
	} OSCOVFSR;
	char           wk8[1];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short  : 8;
			unsigned short CKOSEL : 4;
			unsigned short CKODIV : 3;
			unsigned short CKOSTP : 1;
#else
			unsigned short CKOSTP : 1;
			unsigned short CKODIV : 3;
			unsigned short CKOSEL : 4;
			unsigned short  : 8;
#endif
	} BIT;
	} CKOCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char OSTDIE : 1;
			unsigned char  : 6;
			unsigned char OSTDE : 1;
#else
			unsigned char OSTDE : 1;
			unsigned char  : 6;
			unsigned char OSTDIE : 1;
#endif
	} BIT;
	} OSTDCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char OSTDF : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char OSTDF : 1;
#endif
	} BIT;
	} OSTDSR;
	char           wk9[31];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char LOCOTRD2 : 8;
#else
			unsigned char LOCOTRD2 : 8;
#endif
	} BIT;
	} LOCOTRR2;
	char           wk10[2];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char ILOCOTRD : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char ILOCOTRD : 5;
#endif
	} BIT;
	} ILOCOTRR;
	char           wk11[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char HOCOTRD : 6;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char HOCOTRD : 6;
#endif
	} BIT;
	} HOCOTRR0;
	char           wk12[55];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char OPCM : 3;
			unsigned char  : 1;
			unsigned char OPCMTSF : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char OPCMTSF : 1;
			unsigned char  : 1;
			unsigned char OPCM : 3;
#endif
	} BIT;
	} OPCCR;
	char           wk13[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char MSTS : 5;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char MSTS : 5;
#endif
	} BIT;
	} MOSCWTCR;
	char           wk14[29];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char IWDTRF : 1;
			unsigned char  : 1;
			unsigned char SWRF : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char SWRF : 1;
			unsigned char  : 1;
			unsigned char IWDTRF : 1;
#endif
	} BIT;
	} RSTSR2;
	char           wk15[1];
	unsigned short SWRR;
	char           wk16[28];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char LVD1IDTSEL : 2;
			unsigned char LVD1IRQSEL : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char LVD1IRQSEL : 1;
			unsigned char LVD1IDTSEL : 2;
#endif
	} BIT;
	} LVD1CR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char LVD1DET : 1;
			unsigned char LVD1MON : 1;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char LVD1MON : 1;
			unsigned char LVD1DET : 1;
#endif
	} BIT;
	} LVD1SR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char LVD2IDTSEL : 2;
			unsigned char LVD2IRQSEL : 1;
			unsigned char  : 5;
#else
			unsigned char  : 5;
			unsigned char LVD2IRQSEL : 1;
			unsigned char LVD2IDTSEL : 2;
#endif
	} BIT;
	} LVD2CR1;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char LVD2DET : 1;
			unsigned char LVD2MON : 1;
			unsigned char  : 6;
#else
			unsigned char  : 6;
			unsigned char LVD2MON : 1;
			unsigned char LVD2DET : 1;
#endif
	} BIT;
	} LVD2SR;
	char           wk17[794];
	union {
		unsigned short WORD;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short PRC0 : 1;
			unsigned short PRC1 : 1;
			unsigned short  : 1;
			unsigned short PRC3 : 1;
			unsigned short  : 4;
			unsigned short PRKEY : 8;
#else
			unsigned short PRKEY : 8;
			unsigned short  : 4;
			unsigned short PRC3 : 1;
			unsigned short  : 1;
			unsigned short PRC1 : 1;
			unsigned short PRC0 : 1;
#endif
	} BIT;
	} PRCR;
	char           wk18[48784];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char PORF : 1;
			unsigned char LVD0RF : 1;
			unsigned char LVD1RF : 1;
			unsigned char LVD2RF : 1;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char LVD2RF : 1;
			unsigned char LVD1RF : 1;
			unsigned char LVD0RF : 1;
			unsigned char PORF : 1;
#endif
	} BIT;
	} RSTSR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CWSF : 1;
			unsigned char  : 7;
#else
			unsigned char  : 7;
			unsigned char CWSF : 1;
#endif
	} BIT;
	} RSTSR1;
	char           wk19[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 5;
			unsigned char MODRV21 : 1;
			unsigned char MOSEL : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char MOSEL : 1;
			unsigned char MODRV21 : 1;
			unsigned char  : 5;
#endif
	} BIT;
	} MOFCR;
	char           wk20[3];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 5;
			unsigned char LVD1E : 1;
			unsigned char LVD2E : 1;
			unsigned char  : 1;
#else
			unsigned char  : 1;
			unsigned char LVD2E : 1;
			unsigned char LVD1E : 1;
			unsigned char  : 5;
#endif
	} BIT;
	} LVCMPCR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char LVD1LVL : 4;
			unsigned char LVD2LVL : 2;
			unsigned char  : 2;
#else
			unsigned char  : 2;
			unsigned char LVD2LVL : 2;
			unsigned char LVD1LVL : 4;
#endif
	} BIT;
	} LVDLVLR;
	char           wk21[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char LVD1RIE : 1;
			unsigned char  : 1;
			unsigned char LVD1CMPE : 1;
			unsigned char  : 3;
			unsigned char LVD1RI : 1;
			unsigned char LVD1RN : 1;
#else
			unsigned char LVD1RN : 1;
			unsigned char LVD1RI : 1;
			unsigned char  : 3;
			unsigned char LVD1CMPE : 1;
			unsigned char  : 1;
			unsigned char LVD1RIE : 1;
#endif
	} BIT;
	} LVD1CR0;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char LVD2RIE : 1;
			unsigned char  : 1;
			unsigned char LVD2CMPE : 1;
			unsigned char  : 3;
			unsigned char LVD2RI : 1;
			unsigned char LVD2RN : 1;
#else
			unsigned char LVD2RN : 1;
			unsigned char LVD2RI : 1;
			unsigned char  : 3;
			unsigned char LVD2CMPE : 1;
			unsigned char  : 1;
			unsigned char LVD2RIE : 1;
#endif
	} BIT;
	} LVD2CR0;
} st_system_t;

typedef struct st_temps {
	unsigned short TSCDR;
} st_temps_t;

typedef struct st_tmr0 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 3;
			unsigned char CCLR : 2;
			unsigned char OVIE : 1;
			unsigned char CMIEA : 1;
			unsigned char CMIEB : 1;
#else
			unsigned char CMIEB : 1;
			unsigned char CMIEA : 1;
			unsigned char OVIE : 1;
			unsigned char CCLR : 2;
			unsigned char  : 3;
#endif
	} BIT;
	} TCR;
	char           wk0[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char OSA : 2;
			unsigned char OSB : 2;
			unsigned char ADTE : 1;
			unsigned char  : 3;
#else
			unsigned char  : 3;
			unsigned char ADTE : 1;
			unsigned char OSB : 2;
			unsigned char OSA : 2;
#endif
	} BIT;
	} TCSR;
	char           wk1[1];
	unsigned char  TCORA;
	char           wk2[1];
	unsigned char  TCORB;
	char           wk3[1];
	unsigned char  TCNT;
	char           wk4[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CKS : 3;
			unsigned char CSS : 2;
			unsigned char  : 2;
			unsigned char TMRIS : 1;
#else
			unsigned char TMRIS : 1;
			unsigned char  : 2;
			unsigned char CSS : 2;
			unsigned char CKS : 3;
#endif
	} BIT;
	} TCCR;
} st_tmr0_t;

typedef struct st_tmr1 {
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char  : 3;
			unsigned char CCLR : 2;
			unsigned char OVIE : 1;
			unsigned char CMIEA : 1;
			unsigned char CMIEB : 1;
#else
			unsigned char CMIEB : 1;
			unsigned char CMIEA : 1;
			unsigned char OVIE : 1;
			unsigned char CCLR : 2;
			unsigned char  : 3;
#endif
	} BIT;
	} TCR;
	char           wk0[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char OSA : 2;
			unsigned char OSB : 2;
			unsigned char  : 4;
#else
			unsigned char  : 4;
			unsigned char OSB : 2;
			unsigned char OSA : 2;
#endif
	} BIT;
	} TCSR;
	char           wk1[1];
	unsigned char  TCORA;
	char           wk2[1];
	unsigned char  TCORB;
	char           wk3[1];
	unsigned char  TCNT;
	char           wk4[1];
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char CKS : 3;
			unsigned char CSS : 2;
			unsigned char  : 2;
			unsigned char TMRIS : 1;
#else
			unsigned char TMRIS : 1;
			unsigned char  : 2;
			unsigned char CSS : 2;
			unsigned char CKS : 3;
#endif
	} BIT;
	} TCCR;
} st_tmr1_t;

typedef struct st_tmr01 {
	unsigned short TCORA;
	unsigned short TCORB;
	unsigned short TCNT;
	unsigned short TCCR;
} st_tmr01_t;


#pragma pack()

#endif

