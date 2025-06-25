/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch.h>
#include <asm_macros.S>
#include <console_macros.S>

#define	SMR				(0x00)
#define	BRR				(0x02)
#define	MDDR			(0x02)
#define	SCR				(0x04)
#define FTDR			(0x06)
#define FSR				(0x08)
#define FRDR			(0x0A)
#define FCR				(0x0C)
#define FDR				(0x0E)
#define SPTR			(0x10)
#define LSR				(0x12)
#define SEMR			(0x14)
#define FTCR			(0x16)

#define SCR_CKE_MASK	(0x03)
#define SCR_CKE_INTERN	(0x00)
#define SCR_RE_ON		(0x10)
#define SCR_TE_ON		(0x20)
#define SCR_INIT		(0x00)
#define SCR_READY		(SCR_INIT | SCR_RE_ON | SCR_TE_ON)

#define FCR_RFRST_RST	(0x02)
#define FCR_TFRST_RST	(0x04)
#define FCR_BASE		(0x00)
#define FCR_RST			(FCR_BASE | FCR_RFRST_RST | FCR_TFRST_RST)
#define FCR_RUN			(FCR_BASE)

#define SMR_INIT		(0x00)

#define SEMR_NFEN_ON	(0x04)
#define SEMR_MDDRS_BRR	(0x00)
#define SEMR_MDDRS_MDDR (0x10)
#define SEMR_BRME_ON	(0x20)
//#define SEMR_BASE		(SEMR_NFEN_ON)
#define SEMR_BASE		(0x00)
#define SEMR_BRR		(SEMR_BASE | SEMR_MDDRS_BRR)
#define SEMR_MDDR		(SEMR_BASE | SEMR_MDDRS_MDDR | SEMR_BRME_ON)

#define FTCR_TTRGS		(0x0080)
#define FTCR_RTRGS		(0x8000)

#define FSR_TDFE_SHIFT	(5)
#define FSR_TEND_SHIFT	(6)
#define FSR_TEND		(1<<FSR_TEND_SHIFT)

#define BRR_C_RSHIFT	(5)
#define BRR_C_SUB		(1)

	.globl	console_rzg2l_register
	.globl	console_rzg2l_init
	.globl	console_rzg2l_putc
	.globl	console_rzg2l_flush

	/* -----------------------------------------------
	 * int console_rzg2l_register(
	 *      uintptr_t base, uint32_t clk, uint32_t baud,
	 *      console_t *console)
	 * Function to initialize and register a new console.
	 * Storage passed in for the console struct
	 * *must* be persistent (i.e. not from the stack).
	 * In: x0 - UART register base address
	 *     w1 - UART clock in Hz
	 *     w2 - Baud rate
	 *     x3 - pointer to empty console_t struct
	 * Out: return 1 on success, 0 on error
	 * Clobber list : x0, x1, x2, x6, x7, x14
	 * -----------------------------------------------
	 */
func console_rzg2l_register
	mov	x7, x30
	mov	x6, x3
	cbz	x6, register_fail
	str	x0, [x6, #CONSOLE_T_BASE]

	bl	console_rzg2l_init

	mov	x0, x6
	mov	x30, x7
	finish_console_register rzg2l, putc=1, getc=0, flush=1
	b l_ret

register_fail:
	mov x0, #0

l_ret:
	ret	x7
endfunc console_rzg2l_register

	/* -----------------------------------------------
	 * int console_rzg2l_init(unsigned long base_addr,
	 * unsigned int uart_clk, unsigned int baud_rate)
	 * Function to initialize the console without a
	 * C Runtime to print debug information. This
	 * function will be accessed by console_rzg2l_register
	 * and crash reporting.
	 * In: x0 - console base address
	 *     w1 - Uart clock in Hz
	 *     w2 - Baud rate
	 * Out: return 1 on success
	 * Clobber list : x3
	 * -----------------------------------------------
	 */
func console_rzg2l_init
	mov w3, #(SCR_INIT)
	strh w3, [x0, #SCR]

	mov w3, #(FCR_RST)
	strh w3, [x0, #FCR]

	ldrh w3, [x0, #FSR]
	ldrh w3, [x0, #LSR]
	mov w3, #0
	strh w3, [x0, #FSR]
	strh w3, [x0, #LSR]

	ldrh w3, [x0, #SCR]
	and w3, w3, #~SCR_CKE_MASK
	strh w3, [x0, #SCR]

	mov w3, #(SMR_INIT)
	strh w3, [x0, #SMR]

	mov w3, #(SEMR_BRR)
	strb w3, [x0, #SEMR]
	udiv w3, w1, w2
	lsr w3, w3, #(BRR_C_RSHIFT)
	sub w3, w3, #(BRR_C_SUB)
	strb w3, [x0, #BRR]

	add x3, x3 ,#1
	lsl x3, x3, #(BRR_C_RSHIFT + 8)
	mul x3, x3, x2
	udiv x3, x3, x1
	mov w1, #(SEMR_MDDR)
	strb w1, [x0, #SEMR]
	strb w3, [x0, #MDDR]

	/* 1-bit interval */
	mov w3, #0
1:	add w3, w3, #1
	cmp w3, #256
	bne 1b

	ldrh w3, [x0, #FTCR]
	and w3, w3, #~FTCR_TTRGS
	and w3, w3, #~FTCR_RTRGS
	strh w3, [x0, #FTCR]
	mov w3, #(FCR_RUN)
	strh w3, [x0, #FCR]

	mov w3, #(SCR_READY)
	strh w3, [x0, #SCR]

	mov	x0, #1
	ret
endfunc console_rzg2l_init

	/* --------------------------------------------------------
	 * int console_rzg2l_putc(int c, console_t *console)
	 * Function to output a character over the console. It
	 * returns the character printed on success or -1 on error.
	 * In : w0 - character to be printed
	 *      x1 - pointer to console_t structure
	 * Out : return -1 on error else return character.
	 * Clobber list : x2
	 * --------------------------------------------------------
	 */
func console_rzg2l_putc
	ldr x1, [x1, #CONSOLE_T_BASE]
	cmp w0, #0xA
	/* Prepend '\r' to '\n' */
	bne 2f
1:
	/* Check if the transmit FIFO is full */
	ldrh w2, [x1, #FDR]
	ubfx w2, w2, #8, #5
	cmp w2, #16
	bge 1b
	mov w2, #0x0D
	strb w2, [x1, #FTDR]
2:
	/* Check if the transmit FIFO is full */
	ldrh w2, [x1, #FDR]
	ubfx w2, w2, #8, #5
	cmp w2, #16
	bge 2b
	strb w0, [x1, #FTDR]

	/* Clear TEND flag */
	ldrh w2, [x1, #FSR]
	and w2, w2, #~FSR_TEND
	strh w2, [x1, #FSR]

	ret
endfunc console_rzg2l_putc

	/* ---------------------------------------------
	 * int console_rzg2l_flush(console_t *console)
	 * Function to force a write of all buffered
	 * data that hasn't been output. It returns 0
	 * upon successful completion, otherwise it
	 * returns -1.
	 * In : x0 - pointer to console_t structure
	 * Out : return 0 upon successful completion, otherwise -1
	 * Clobber list : x1
	 * ---------------------------------------------
	 */
func console_rzg2l_flush
	ldr x0, [x0, #CONSOLE_T_BASE]
1:
	/* Check TEND flag */
	ldrh w1, [x0, #FSR]
	and w1, w1, #FSR_TEND
	cmp	w1, #FSR_TEND
	bne	1b

	mov	w0, #0
	ret
endfunc console_rzg2l_flush
