/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : r_ethosu_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for NPU.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef R_ETHOSU_IODEFINE_H
#define R_ETHOSU_IODEFINE_H

/* =========================================================================================================================== */
/* ================                                           R_NPU                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Neural Processing Unit (R_NPU)
 */

typedef struct                                /*!< (@ 0x40140000) R_NPU Structure                                            */
{
    union
    {
        __IM uint32_t ID;                     /*!< (@ 0x00000000) ID register                                                */
        struct
        {
            __IM uint32_t version_status : 4; /*!< [3..0] This is the version of the product                                 */
            __IM uint32_t version_minor  : 4; /*!< [7..4] This is the n for the P-part of an RnPn release number             */
            __IM uint32_t version_major  : 4; /*!< [11..8] This is the n for the R-part of an RnPn release number            */
            __IM uint32_t product_major  : 4; /*!< [15..12] This is the X-part of the ML00X product number                   */
            __IM uint32_t arch_patch_rev : 4; /*!< [19..16] This is the patch number of the architecture version
                                               *   a.b                                                                       */
            __IM uint32_t arch_minor_rev : 8; /*!< [27..20] This is the minor architecture version number, b in
                                               *   the architecture version a.b                                              */
            __IM uint32_t arch_major_rev : 4; /*!< [31..28] This is the major architecture version number, a in
                                               *   the architecture version a.b                                              */
        } ID_b;
    };
    union
    {
        __IM uint32_t STATUS;                     /*!< (@ 0x00000004) Register describes the current operating status
                                                   *                  of the NPU                                                 */
        struct
        {
            __IM uint32_t state      : 1;         /*!< [0..0] NPU state; 0 = Stopped, 1 = Running                                */
            __IM uint32_t irq_raised : 1;         /*!< [1..1] Raw IRQ status: 0 = IRQ not raised, 1 = IRQ raised. IRQ
                                                   *   is cleared using command register bit 1.                                  */
            __IM uint32_t bus_status : 1;         /*!< [2..2] 0=OK, 1=Bus abort detected and processing halted (the
                                                   *   NPU has reached IDLE state and does not start to process
                                                   *   any more commands/AXI transactions). Can only be cleared
                                                   *   by a reset.                                                               */
            __IM uint32_t reset_status : 1;       /*!< [3..3] Reset is ongoing and only this register can be read (other
                                                   *   registers read as 0 and writes are ignored). A value of
                                                   *   0 means the NPU is not being reset and can be accessed
                                                   *   as normal.                                                                */
            __IM uint32_t cmd_parse_error : 1;    /*!< [4..4] 0=No error, 1=Command-stream parsing error detected.
                                                   *   Can only be cleared by a reset.                                           */
            __IM uint32_t cmd_end_reached : 1;    /*!< [5..5] 0=Not reached, 1=Reached. Cleared by writing QBASE or
                                                   *   QSIZE when the NPU is in stopped state.                                   */
            __IM uint32_t pmu_irq_raised : 1;     /*!< [6..6] 0=No PMU IRQ, 1=PMU IRQ raised. Cleared by using command
                                                   *   register bit 1                                                            */
            uint32_t                : 1;
            __IM uint32_t ecc_fault : 1;          /*!< [8..8] ECC state for internal RAMs: 0=no fault, 1=ECC fault
                                                   *   signalled. Can only be cleared by reset.                                  */
            uint32_t                         : 2;
            __IM uint32_t faulting_interface : 1; /*!< [11..11] Faulting interface on bus abort. 0=AXI-M0, 1=AXI-M1              */
            __IM uint32_t faulting_channel   : 4; /*!< [15..12] Faulting channel on a bus abort. Read: 0=Cmd, 1=IFM,
                                                   *   2=Weights, 3=Scale+Bias, 4=Mem2Mem; Write: 8=OFM, 9=Mem2Mem               */
            __IM uint32_t irq_history_mask : 16;  /*!< [31..16] IRQ History mask                                                 */
        } STATUS_b;
    };
    union
    {
        __IOM uint32_t CMD;                                 /*!< (@ 0x00000008) Command register, reads as last written command            */
        struct
        {
            __IOM uint32_t transition_to_running_state : 1; /*!< [0..0] Write 1 to transition the NPU to running state. Writing
                                                             * 0 has no effect                                                           */
            __IOM uint32_t clear_irq : 1;                   /*!< [1..1] Write 1 to clear the IRQ status in the STATUS register.
                                                             *   Writing 0 has no effect                                                   */
            __IOM uint32_t clock_q_enable : 1;              /*!< [2..2] Write 1 to this bit to enable clock off using the Clock
                                                             *   Q-interface and enable the main clock gate                                */
            __IOM uint32_t power_q_enable : 1;              /*!< [3..3] Write 1 to this bit to enable power off using the Power
                                                             *   Q-interface                                                               */
            uint32_t                         : 12;
            __IOM uint32_t clear_irq_history : 16;          /*!< [31..16] Clears the IRQ history mask                                      */
        } CMD_b;
    };
    union
    {
        __IOM uint32_t RESET;               /*!< (@ 0x0000000C) Request Reset and new security mode                        */
        struct
        {
            __IOM uint32_t pending_CPL : 1; /*!< [0..0] Current privilege level: 0=User, 1=Privileged                      */
            __IOM uint32_t pending_CSL : 1; /*!< [1..1] Current security level: 0=Secure, 1=Non secure                     */
            uint32_t                   : 30;
        } RESET_b;
    };
    union
    {
        __IOM uint32_t QBASE0;          /*!< (@ 0x00000010) Base address of Command-queue bits[31:0]. The
                                         *                  address is 4-byte-aligned                                  */
        struct
        {
            __IOM uint32_t QBASE0 : 32; /*!< [31..0] The 4-byte-aligned lower bytes of the base address value
                                         *   for the command stream                                                    */
        } QBASE0_b;
    };
    union
    {
        __IOM uint32_t QBASE1;          /*!< (@ 0x00000014) Address extension bits[47:32] for queue base               */
        struct
        {
            __IOM uint32_t QBASE1 : 32; /*!< [31..0] The 4-byte-aligned upper bytes of the base address value
                                         *   for the command stream                                                    */
        } QBASE1_b;
    };

    union
    {
        __IM uint32_t QREAD;           /*!< (@ 0x00000018) Read offset in the command stream in bytes. Multiples
                                        *                  of 4 in the range 0-16 MB                                  */

        struct
        {
            __IM uint32_t QREAD : 32;  /*!< [31..0] The read offset of the current command under execution            */
        } QREAD_b;
    };

    union
    {
        __IOM uint32_t QCONFIG;          /*!< (@ 0x0000001C) AXI configuration for the command stream in the
                                          *                  range 0-3. Same encoding as for REGIONCFG                  */

        struct
        {
            __IOM uint32_t QCONFIG : 32; /*!< [31..0] AXI configuration for the command stream in the range
                                          *   0-3                                                                       */
        } QCONFIG_b;
    };

    union
    {
        __IOM uint32_t QSIZE;          /*!< (@ 0x00000020) Size of the command stream in bytes. Multiples
                                        *                  of 4 in the range 0-16 MB                                  */

        struct
        {
            __IOM uint32_t QSIZE : 32; /*!< [31..0] Size of the next command stream to be executed by the
                                        *   NPU                                                                       */
        } QSIZE_b;
    };

    union
    {
        __IM uint32_t PROT;               /*!< (@ 0x00000024) Protection level configured for the NPU when
                                           *                  acting as an AXI master                                    */

        struct
        {
            __IM uint32_t active_CPL : 1; /*!< [0..0] Current privilege level: 0=User, 1=Privileged                      */
            __IM uint32_t active_CSL : 1; /*!< [1..1] Current security level: 0=Secure, 1=Non-secure                     */
            uint32_t                 : 30;
        } PROT_b;
    };

    union
    {
        __IM uint32_t CONFIG;                     /*!< (@ 0x00000028) RTL configuration                                          */

        struct
        {
            __IM uint32_t macs_per_cc : 4;        /*!< [3..0] The log2(macs/clock cycle). Valid encoding range is 5-8
                                                   *   for 32-256 MACs/clock cycle.                                              */
            __IM uint32_t cmd_stream_version : 4; /*!< [7..4] Command-stream version accepted by this NPU.                       */
            __IM uint32_t shram_size         : 8; /*!< [15..8] Size in KB of SHRAM in the range 8-48.                            */
            uint32_t                         : 11;
            __IM uint32_t custom_dma         : 1; /*!< [27..27] Custom DMA configuration                                         */
            __IM uint32_t product            : 4; /*!< [31..28] Product configuration                                            */
        } CONFIG_b;
    };

    union
    {
        __IOM uint32_t LOCK;           /*!< (@ 0x0000002C) Lock register. This register is designed for
                                        *                  driver use and does not affect NPU functionality           */

        struct
        {
            __IOM uint32_t LOCK : 32;  /*!< [31..0] 32-bit value for the LOCK configuration                           */
        } LOCK_b;
    };
    __IM uint32_t RESERVED[3];

    union
    {
        __IOM uint32_t REGIONCFG;       /*!< (@ 0x0000003C) Base pointer configuration. Bits[2*k+1:2*k] give
                                         *                  the memory type for REGION[k]                              */

        struct
        {
            __IOM uint32_t region0 : 2; /*!< [1..0] Bits for the Region0 configuration                                 */
            __IOM uint32_t region1 : 2; /*!< [3..2] Bits for the Region1 configuration                                 */
            __IOM uint32_t region2 : 2; /*!< [5..4] Bits for the Region2 configuration                                 */
            __IOM uint32_t region3 : 2; /*!< [7..6] Bits for the Region3 configuration                                 */
            __IOM uint32_t region4 : 2; /*!< [9..8] Bits for the Region4 configuration                                 */
            __IOM uint32_t region5 : 2; /*!< [11..10] Bits for the Region5 configuration                               */
            __IOM uint32_t region6 : 2; /*!< [13..12] Bits for the Region6 configuration                               */
            __IOM uint32_t region7 : 2; /*!< [15..14] Bits for the Region7 configuration                               */
            uint32_t               : 16;
        } REGIONCFG_b;
    };

    union
    {
        __IOM uint32_t AXI_LIMIT0;                       /*!< (@ 0x00000040) AXI limits for port 0 counter 0                            */

        struct
        {
            __IOM uint32_t max_beats : 2;                /*!< [1..0] Burst-split alignment: 0=64 bytes, 1=128 bytes, 2=256
                                                          *   bytes, 3=reserved                                                         */
            uint32_t                               : 2;
            __IOM uint32_t memtype                 : 4;  /*!< [7..4] Memtype                                                            */
            uint32_t                               : 8;
            __IOM uint32_t max_outstanding_read_m1 : 8;  /*!< [23..16] Maximum number of outstanding AXI read transactions
                                                          *  - 1 in range 0-31                                                         */
            __IOM uint32_t max_outstanding_write_m1 : 8; /*!< [31..24] Maximum number of outstanding AXI write transactions
                                                          * - 1 in range 0-15                                                         */
        } AXI_LIMIT0_b;
    };

    union
    {
        __IOM uint32_t AXI_LIMIT1;                       /*!< (@ 0x00000044) AXI limits for port 0 counter 1                            */

        struct
        {
            __IOM uint32_t max_beats : 2;                /*!< [1..0] Burst-split alignment: 0=64 bytes, 1=128 bytes, 2=256
                                                          *   bytes, 3=reserved                                                         */
            uint32_t                               : 2;
            __IOM uint32_t memtype                 : 4;  /*!< [7..4] Memtype                                                            */
            uint32_t                               : 8;
            __IOM uint32_t max_outstanding_read_m1 : 8;  /*!< [23..16] Maximum number of outstanding AXI read transactions
                                                          *  - 1 in range 0-31                                                         */
            __IOM uint32_t max_outstanding_write_m1 : 8; /*!< [31..24] Maximum number of outstanding AXI write transactions
                                                          * - 1 in range 0-15                                                         */
        } AXI_LIMIT1_b;
    };

    union
    {
        __IOM uint32_t AXI_LIMIT2;                       /*!< (@ 0x00000048) AXI limits for port 1 counter 2                            */

        struct
        {
            __IOM uint32_t max_beats : 2;                /*!< [1..0] Burst-split alignment: 0=64 bytes, 1=128 bytes, 2=256
                                                          *   bytes, 3=reserved                                                         */
            uint32_t                               : 2;
            __IOM uint32_t memtype                 : 4;  /*!< [7..4] Memtype                                                            */
            uint32_t                               : 8;
            __IOM uint32_t max_outstanding_read_m1 : 8;  /*!< [23..16] Maximum number of outstanding AXI read transactions
                                                          *  - 1 in range 0-31                                                         */
            __IOM uint32_t max_outstanding_write_m1 : 8; /*!< [31..24] Maximum number of outstanding AXI write transactions
                                                          * - 1 in range 0-15                                                         */
        } AXI_LIMIT2_b;
    };

    union
    {
        __IOM uint32_t AXI_LIMIT3;                       /*!< (@ 0x0000004C) AXI limits for port 1 counter 3                            */

        struct
        {
            __IOM uint32_t max_beats : 2;                /*!< [1..0] Burst-split alignment: 0=64 bytes, 1=128 bytes, 2=256
                                                          *   bytes, 3=reserved                                                         */
            uint32_t                               : 2;
            __IOM uint32_t memtype                 : 4;  /*!< [7..4] Memtype                                                            */
            uint32_t                               : 8;
            __IOM uint32_t max_outstanding_read_m1 : 8;  /*!< [23..16] Maximum number of outstanding AXI read transactions
                                                          *  - 1 in range 0-31                                                         */
            __IOM uint32_t max_outstanding_write_m1 : 8; /*!< [31..24] Maximum number of outstanding AXI write transactions
                                                          * - 1 in range 0-15                                                         */
        } AXI_LIMIT3_b;
    };
    __IM uint32_t RESERVED1[12];

    union
    {
        __IOM uint32_t BASEP0;             /*!< (@ 0x00000080) Lower 32 bits of the Base pointer for region
                                            *                  index 0                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The low word of the 64-bit address                                */
        } BASEP0_b;
    };

    union
    {
        __IOM uint32_t BASEP1;             /*!< (@ 0x00000084) Upper 32 bits of the Base pointer for region
                                            *                  index 0                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The high word of the 64-bit address                               */
        } BASEP1_b;
    };

    union
    {
        __IOM uint32_t BASEP2;             /*!< (@ 0x00000088) Lower 32 bits of the Base pointer for region
                                            *                  index 1                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The low word of the 64-bit address                                */
        } BASEP2_b;
    };

    union
    {
        __IOM uint32_t BASEP3;             /*!< (@ 0x0000008C) Upper 32 bits of the Base pointer for region
                                            *                  index 1                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The high word of the 64-bit address                               */
        } BASEP3_b;
    };

    union
    {
        __IOM uint32_t BASEP4;             /*!< (@ 0x00000090) Lower 32 bits of the Base pointer for region
                                            *                  index 2                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The low word of the 64-bit address                                */
        } BASEP4_b;
    };

    union
    {
        __IOM uint32_t BASEP5;             /*!< (@ 0x00000094) Upper 32 bits of the Base pointer for region
                                            *                  index 2                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The high word of the 64-bit address                               */
        } BASEP5_b;
    };

    union
    {
        __IOM uint32_t BASEP6;             /*!< (@ 0x00000098) Lower 32 bits of the Base pointer for region
                                            *                  index 3                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The low word of the 64-bit address                                */
        } BASEP6_b;
    };

    union
    {
        __IOM uint32_t BASEP7;             /*!< (@ 0x0000009C) Upper 32 bits of the Base pointer for region
                                            *                  index 3                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The high word of the 64-bit address                               */
        } BASEP7_b;
    };

    union
    {
        __IOM uint32_t BASEP8;             /*!< (@ 0x000000A0) Lower 32 bits of the Base pointer for region
                                            *                  index 4                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The low word of the 64-bit address                                */
        } BASEP8_b;
    };

    union
    {
        __IOM uint32_t BASEP9;             /*!< (@ 0x000000A4) Upper 32 bits of the Base pointer for region
                                            *                  index 4                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The high word of the 64-bit address                               */
        } BASEP9_b;
    };

    union
    {
        __IOM uint32_t BASEP10;            /*!< (@ 0x000000A8) Lower 32 bits of the Base pointer for region
                                            *                  index 5                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The low word of the 64-bit address                                */
        } BASEP10_b;
    };

    union
    {
        __IOM uint32_t BASEP11;            /*!< (@ 0x000000AC) Upper 32 bits of the Base pointer for region
                                            *                  index 5                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The high word of the 64-bit address                               */
        } BASEP11_b;
    };

    union
    {
        __IOM uint32_t BASEP12;            /*!< (@ 0x000000B0) Lower 32 bits of the Base pointer for region
                                            *                  index 6                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The low word of the 64-bit address                                */
        } BASEP12_b;
    };

    union
    {
        __IOM uint32_t BASEP13;            /*!< (@ 0x000000B4) Upper 32 bits of the Base pointer for region
                                            *                  index 6                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The high word of the 64-bit address                               */
        } BASEP13_b;
    };

    union
    {
        __IOM uint32_t BASEP14;            /*!< (@ 0x000000B8) Lower 32 bits of the Base pointer for region
                                            *                  index 7                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The low word of the 64-bit address                                */
        } BASEP14_b;
    };

    union
    {
        __IOM uint32_t BASEP15;            /*!< (@ 0x000000BC) Upper 32 bits of the Base pointer for region
                                            *                  index 7                                                    */

        struct
        {
            __IOM uint32_t addr_word : 32; /*!< [31..0] The high word of the 64-bit address                               */
        } BASEP15_b;
    };
    __IM uint32_t RESERVED2[48];

    union
    {
        __IOM uint32_t PMCR;                  /*!< (@ 0x00000180) PMU master control register                                */

        struct
        {
            __IOM uint32_t cnt_en        : 1; /*!< [0..0] Enable counter                                                     */
            __IOM uint32_t event_cnt_rst : 1; /*!< [1..1] Reset event counter                                                */
            __IOM uint32_t cycle_cnt_rst : 1; /*!< [2..2] Reset cycle counter                                                */
            __IOM uint32_t mask_en       : 1; /*!< [3..3] PMU can be enabled/disabled by command stream operationNPU_OP_PMU_MASK */
            uint32_t                     : 7;
            __IOM uint32_t num_event_cnt : 5; /*!< [15..11] Number of event counters available for performance
                                               *   measurement                                                               */
            uint32_t : 16;
        } PMCR_b;
    };

    union
    {
        __IOM uint32_t PMCNTENSET;          /*!< (@ 0x00000184) Count-enable set register                                  */

        struct
        {
            __IOM uint32_t EVENT_CNT_0 : 1; /*!< [0..0] Event-counter enable bit for PMU_EVCNTR0                           */
            __IOM uint32_t EVENT_CNT_1 : 1; /*!< [1..1] Event-counter enable bit for PMU_EVCNTR1                           */
            __IOM uint32_t EVENT_CNT_2 : 1; /*!< [2..2] Event-counter enable bit for PMU_EVCNTR2                           */
            __IOM uint32_t EVENT_CNT_3 : 1; /*!< [3..3] Event-counter enable bit for PMU_EVCNTR3                           */
            uint32_t                   : 27;
            __IOM uint32_t CYCLE_CNT   : 1; /*!< [31..31] PMCCNTR enable bit                                               */
        } PMCNTENSET_b;
    };

    union
    {
        __IOM uint32_t PMCNTENCLR;          /*!< (@ 0x00000188) Count-enable clear register                                */

        struct
        {
            __IOM uint32_t EVENT_CNT_0 : 1; /*!< [0..0] Event-counter disable bit for PMU_EVCNTR0                          */
            __IOM uint32_t EVENT_CNT_1 : 1; /*!< [1..1] Event-counter disable bit for PMU_EVCNTR1                          */
            __IOM uint32_t EVENT_CNT_2 : 1; /*!< [2..2] Event-counter disable bit for PMU_EVCNTR2                          */
            __IOM uint32_t EVENT_CNT_3 : 1; /*!< [3..3] Event-counter disable bit for PMU_EVCNTR3                          */
            uint32_t                   : 27;
            __IOM uint32_t CYCLE_CNT   : 1; /*!< [31..31] PMCCNTR disable bit                                              */
        } PMCNTENCLR_b;
    };

    union
    {
        __IOM uint32_t PMOVSSET;                /*!< (@ 0x0000018C) Overflow-flag status set register                          */

        struct
        {
            __IOM uint32_t EVENT_CNT_0_OVF : 1; /*!< [0..0] Event-counter overflow set bit for PMU_EVCNTR0                     */
            __IOM uint32_t EVENT_CNT_1_OVF : 1; /*!< [1..1] Event-counter overflow set bit for PMU_EVCNTR1                     */
            __IOM uint32_t EVENT_CNT_2_OVF : 1; /*!< [2..2] Event-counter overflow set bit for PMU_EVCNTR2                     */
            __IOM uint32_t EVENT_CNT_3_OVF : 1; /*!< [3..3] Event-counter overflow set bit for PMU_EVCNTR3                     */
            uint32_t                       : 27;
            __IOM uint32_t CYCLE_CNT_OVF   : 1; /*!< [31..31] PMCCNTR overflow set bit                                         */
        } PMOVSSET_b;
    };

    union
    {
        __IOM uint32_t PMOVSCLR;                /*!< (@ 0x00000190) Overflow-flag status clear register                        */

        struct
        {
            __IOM uint32_t EVENT_CNT_0_OVF : 1; /*!< [0..0] Event-counter overflow clear bit for PMU_EVCNTR0                   */
            __IOM uint32_t EVENT_CNT_1_OVF : 1; /*!< [1..1] Event-counter overflow clear bit for PMU_EVCNTR1                   */
            __IOM uint32_t EVENT_CNT_2_OVF : 1; /*!< [2..2] Event-counter overflow clear bit for PMU_EVCNTR2                   */
            __IOM uint32_t EVENT_CNT_3_OVF : 1; /*!< [3..3] Event-counter overflow clear bit for PMU_EVCNTR3                   */
            uint32_t                       : 27;
            __IOM uint32_t CYCLE_CNT_OVF   : 1; /*!< [31..31] PMCCNTR overflow clear bit                                       */
        } PMOVSCLR_b;
    };

    union
    {
        __IOM uint32_t PMINTSET;                /*!< (@ 0x00000194) Interrupt-enable set register                              */

        struct
        {
            __IOM uint32_t EVENT_CNT_0_INT : 1; /*!< [0..0] Event-counter overflow interrupt-request enable bit for
                                                 *   PMU_EVCNTR0                                                               */
            __IOM uint32_t EVENT_CNT_1_INT : 1; /*!< [1..1] Event-counter overflow interrupt-request enable bit for
                                                 *   PMU_EVCNTR1                                                               */
            __IOM uint32_t EVENT_CNT_2_INT : 1; /*!< [2..2] Event-counter overflow interrupt-request enable bit for
                                                 *   PMU_EVCNTR2                                                               */
            __IOM uint32_t EVENT_CNT_3_INT : 1; /*!< [3..3] Event-counter overflow interrupt-request enable bit for
                                                 *   PMU_EVCNTR3                                                               */
            uint32_t                     : 27;
            __IOM uint32_t CYCLE_CNT_INT : 1;   /*!< [31..31] PMCCNTR overflow interrupt-request enable bit                    */
        } PMINTSET_b;
    };

    union
    {
        __IOM uint32_t PMINTCLR;                /*!< (@ 0x00000198) Interrupt-enable clear register                            */

        struct
        {
            __IOM uint32_t EVENT_CNT_0_INT : 1; /*!< [0..0] Event-counter overflow interrupt-request disable bit
                                                 *   for PMU_EVCNTR0                                                           */
            __IOM uint32_t EVENT_CNT_1_INT : 1; /*!< [1..1] Event-counter overflow interrupt-request disable bit
                                                 *   for PMU_EVCNTR1                                                           */
            __IOM uint32_t EVENT_CNT_2_INT : 1; /*!< [2..2] Event-counter overflow interrupt-request disable bit
                                                 *   for PMU_EVCNTR2                                                           */
            __IOM uint32_t EVENT_CNT_3_INT : 1; /*!< [3..3] Event-counter overflow interrupt-request disable bit
                                                 *   for PMU_EVCNTR3                                                           */
            uint32_t                     : 27;
            __IOM uint32_t CYCLE_CNT_INT : 1;   /*!< [31..31] PMCCNTR overflow interrupt-request disable bit                   */
        } PMINTCLR_b;
    };
    __IM uint32_t RESERVED3;

    union
    {
        __IOM uint32_t PMCCNTR_LO;            /*!< (@ 0x000001A0) Performance-monitor cycle count low register               */

        struct
        {
            __IOM uint32_t CYCLE_CNT_LO : 32; /*!< [31..0] Cycle count low                                                   */
        } PMCCNTR_LO_b;
    };

    union
    {
        __IOM uint32_t PMCCNTR_HI;            /*!< (@ 0x000001A4) Performance-monitor cycle count high register              */

        struct
        {
            __IOM uint32_t CYCLE_CNT_HI : 32; /*!< [31..0] Cycle count high                                                  */
        } PMCCNTR_HI_b;
    };
    __IM uint32_t RESERVED4;

    union
    {
        __IOM uint32_t PMCAXI_CHAN;          /*!< (@ 0x000001AC) Set which AXI channel monitor                              */

        struct
        {
            __IOM uint32_t CH_SEL : 4;       /*!< [3..0] Specify the type of traffic for bandwidth or latency
                                              *   measurements (Read: 0=command traffic, 1=IFM traffic, 2=Weight
                                              *   traffic, 3=Scale+Bias, 4=Mem2Mem traffic - read direction;
                                              *   Write: 8=OFM traffic, 9=Mem2Mem traffic - write direction)                */
            uint32_t                   : 4;
            __IOM uint32_t AXI_CNT_SEL : 2;  /*!< [9..8] Select AXI counter to monitor for latency measurements
                                              *   (0=AXI0 counter0, 1=AXI0 counter1, 2=AXI1 counter 2, 3=AXI1
                                              *   counter3)                                                                 */
            __IOM uint32_t BW_CH_SEL_EN : 1; /*!< [10..10] Enable bandwidth channel selector: 0=AXI bw events
                                              *   measured for all channels, 1=AXI bw events measured for
                                              *   channel specified by CH_SEL                                               */
            uint32_t : 21;
        } PMCAXI_CHAN_b;
    };
    __IM uint32_t RESERVED5[84];

    union
    {
        __IOM uint32_t PMU_EVCNTR0;       /*!< (@ 0x00000300) Performance-monitor event counters 0                       */

        struct
        {
            __IOM uint32_t PMEVCNTR : 32; /*!< [31..0] Performance-monitor event counters.                               */
        } PMU_EVCNTR0_b;
    };

    union
    {
        __IOM uint32_t PMU_EVCNTR1;       /*!< (@ 0x00000304) Performance-monitor event counters 1                       */

        struct
        {
            __IOM uint32_t PMEVCNTR : 32; /*!< [31..0] Performance-monitor event counters.                               */
        } PMU_EVCNTR1_b;
    };

    union
    {
        __IOM uint32_t PMU_EVCNTR2;       /*!< (@ 0x00000308) Performance-monitor event counters 2                       */

        struct
        {
            __IOM uint32_t PMEVCNTR : 32; /*!< [31..0] Performance-monitor event counters.                               */
        } PMU_EVCNTR2_b;
    };

    union
    {
        __IOM uint32_t PMU_EVCNTR3;       /*!< (@ 0x0000030C) Performance-monitor event counters 3                       */

        struct
        {
            __IOM uint32_t PMEVCNTR : 32; /*!< [31..0] Performance-monitor event counters.                               */
        } PMU_EVCNTR3_b;
    };
    __IM uint32_t RESERVED6[28];

    union
    {
        __IOM uint32_t PMU_EVTYPER0;     /*!< (@ 0x00000380) Performance-monitor event-type control counters
                                          *                  0                                                          */

        struct
        {
            __IOM uint32_t EV_TYPE : 32; /*!< [31..0] Event type.                                                       */
        } PMU_EVTYPER0_b;
    };

    union
    {
        __IOM uint32_t PMU_EVTYPER1;     /*!< (@ 0x00000384) Performance-monitor event-type control counters
                                          *                  1                                                          */

        struct
        {
            __IOM uint32_t EV_TYPE : 32; /*!< [31..0] Event type.                                                       */
        } PMU_EVTYPER1_b;
    };

    union
    {
        __IOM uint32_t PMU_EVTYPER2;     /*!< (@ 0x00000388) Performance-monitor event-type control counters
                                          *                  2                                                          */

        struct
        {
            __IOM uint32_t EV_TYPE : 32; /*!< [31..0] Event type.                                                       */
        } PMU_EVTYPER2_b;
    };

    union
    {
        __IOM uint32_t PMU_EVTYPER3;     /*!< (@ 0x0000038C) Performance-monitor event-type control counters
                                          *                  3                                                          */

        struct
        {
            __IOM uint32_t EV_TYPE : 32; /*!< [31..0] Event type.                                                       */
        } PMU_EVTYPER3_b;
    };
    __IM uint32_t RESERVED7[784];

    union
    {
        __IM uint32_t PID4;            /*!< (@ 0x00000FD0) Peripheral ID byte 4 (Arm=code 4)                          */

        struct
        {
            __IM uint32_t PID4 : 32;   /*!< [31..0] Byte 4 of the Peripheral ID (Lower 8 bits valid)                  */
        } PID4_b;
    };

    union
    {
        __IM uint32_t PID5;            /*!< (@ 0x00000FD4) Peripheral ID byte 5 (reserved)                            */

        struct
        {
            __IM uint32_t PID5 : 32;   /*!< [31..0] Byte 5 of the Peripheral ID (Lower 8 bits valid)                  */
        } PID5_b;
    };

    union
    {
        __IM uint32_t PID6;            /*!< (@ 0x00000FD8) Peripheral ID byte 6 (reserved)                            */

        struct
        {
            __IM uint32_t PID6 : 32;   /*!< [31..0] Byte 6 of the Peripheral ID (Lower 8 bits valid)                  */
        } PID6_b;
    };

    union
    {
        __IM uint32_t PID7;            /*!< (@ 0x00000FDC) Peripheral ID byte 7 (reserved)                            */

        struct
        {
            __IM uint32_t PID7 : 32;   /*!< [31..0] Byte 7 of the Peripheral ID (Lower 8 bits valid)                  */
        } PID7_b;
    };

    union
    {
        __IM uint32_t PID0;            /*!< (@ 0x00000FE0) Peripheral ID byte 0. This is bits[7:0] of the
                                        *                  part number.                                               */

        struct
        {
            __IM uint32_t PID0 : 32;   /*!< [31..0] Byte 0 of the Peripheral ID (Lower 8 bits valid)                  */
        } PID0_b;
    };

    union
    {
        __IM uint32_t PID1;            /*!< (@ 0x00000FE4) Peripheral ID byte 1. This is bits[11:8] of the
                                        *                  part number in bits[3:0], and bits[3:0]
                                        *                  of the Arm ID in bits[7:4].                                */

        struct
        {
            __IM uint32_t PID1 : 32;   /*!< [31..0] Byte 1 of the Peripheral ID (Lower 8 bits valid)                  */
        } PID1_b;
    };

    union
    {
        __IM uint32_t PID2;            /*!< (@ 0x00000FE8) Peripheral ID byte 2. This is bits[6:4] of the
                                        *                  Arm ID in bits[2:0], and bit 3 indicates
                                        *                  format B.                                                  */

        struct
        {
            __IM uint32_t PID2 : 32;   /*!< [31..0] Byte 2 of the Peripheral ID (Lower 8 bits valid)                  */
        } PID2_b;
    };

    union
    {
        __IM uint32_t PID3;            /*!< (@ 0x00000FEC) Peripheral ID byte 3.                                      */

        struct
        {
            __IM uint32_t PID3 : 32;   /*!< [31..0] Byte 3 of the Peripheral ID (Lower 8 bits valid)                  */
        } PID3_b;
    };

    union
    {
        __IM uint32_t CID0;            /*!< (@ 0x00000FF0) Component ID byte 0.                                       */

        struct
        {
            __IM uint32_t CID0 : 32;   /*!< [31..0] Byte 0 of the Component ID (Lower 8 bits valid)                   */
        } CID0_b;
    };

    union
    {
        __IM uint32_t CID1;            /*!< (@ 0x00000FF4) Component ID byte 1.                                       */

        struct
        {
            __IM uint32_t CID1 : 32;   /*!< [31..0] Byte 1 of the Component ID (Lower 8 bits valid)                   */
        } CID1_b;
    };

    union
    {
        __IM uint32_t CID2;            /*!< (@ 0x00000FF8) Component ID byte 2.                                       */

        struct
        {
            __IM uint32_t CID2 : 32;   /*!< [31..0] Byte 2 of the Component ID (Lower 8 bits valid)                   */
        } CID2_b;
    };

    union
    {
        __IM uint32_t CID3;            /*!< (@ 0x00000FFC) Component ID byte 3.                                       */

        struct
        {
            __IM uint32_t CID3 : 32;   /*!< [31..0] Byte 3 of the Component ID (Lower 8 bits valid)                   */
        } CID3_b;
    };
} R_NPU_Type;                          /*!< Size = 4096 (0x1000)*/

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */
#define R_NPU_BASE    0x49C80000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */
#define R_NPU         ((R_NPU_Type *) R_NPU_BASE)

#endif                                 /* R_ETHOSU_IODEFINE_H */
