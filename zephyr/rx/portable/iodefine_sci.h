/*
* Copyright (c) 2015(2017-2025) Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef __IODEFINESCI_HEADER__
#define __IODEFINESCI_HEADER__

struct st_sci {
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
			unsigned char ITE : 1;
			unsigned char BRME : 1;
			unsigned char ABCSE : 1;
			unsigned char ABCS : 1;
			unsigned char NFEN : 1;
			unsigned char BGDM : 1;
			unsigned char RXDESEL : 1;
#else
			unsigned char RXDESEL : 1;
			unsigned char BGDM : 1;
			unsigned char NFEN : 1;
			unsigned char ABCS : 1;
			unsigned char ABCSE : 1;
			unsigned char BRME : 1;
			unsigned char ITE : 1;
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

    /* SCIk only */
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char DCMF : 1;
			unsigned char  : 2;
			unsigned char DPER : 1;
			unsigned char DFER : 1;
			unsigned char  : 1;
			unsigned char IDSEL : 1;
			unsigned char DCME : 1;
#else
			unsigned char DCME : 1;
			unsigned char IDSEL : 1;
			unsigned char  : 1;
			unsigned char DFER : 1;
			unsigned char DPER : 1;
			unsigned char  : 2;
			unsigned char DCMF : 1;
#endif
	    } BIT;
	} DCCR;
	char           wk0[6];
	union {
		unsigned short WORD;
		struct {
			unsigned char H;
			unsigned char L;
		} BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned short CMPD : 9;
			unsigned short  : 7;
#else
			unsigned short  : 7;
			unsigned short CMPD : 9;
#endif
	    } BIT;
	} CDR;
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char RXDMON : 1;
			unsigned char SPB2DT : 1;
			unsigned char SPB2IO : 1;
			unsigned char  : 1;
			unsigned char RINV : 1;
			unsigned char TINV : 1;
			unsigned char RTADJ : 1;
			unsigned char TTADJ : 1;
#else
			unsigned char TTADJ : 1;
			unsigned char RTADJ : 1;
			unsigned char TINV : 1;
			unsigned char RINV : 1;
			unsigned char  : 1;
			unsigned char SPB2IO : 1;
			unsigned char SPB2DT : 1;
			unsigned char RXDMON : 1;
#endif
	    } BIT;
	} SPTR;
    
	union {
		unsigned char BYTE;
		struct {
			
#ifdef __RX_LITTLE_ENDIAN__
			unsigned char RTMG : 4;
			unsigned char TTMG : 4;
#else
			unsigned char TTMG : 4;
			unsigned char RTMG : 4;
#endif
	    } BIT;
	} TMGR;
	char           wk1[2];

    /* SCIh only */
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
};

#endif /* __IODEFINESCI_HEADER__ */
