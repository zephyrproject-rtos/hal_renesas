/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/** @addtogroup Renesas
 * @{
 */

/** @addtogroup R5K574M
 * @{
 */

#ifndef R5K574M_H
 #define R5K574M_H

 #ifdef __cplusplus
extern "C" {
 #endif

/** @addtogroup Configuration_of_RX
 * @{
 */

/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ==================================  Configuration of the Processor and Core Peripherals  ================================== */
 #define __MPU_PRESENT       1         /*!< MPU present                                                               */
 #define __FPU_PRESENT       1         /*!< FPU present                                                               */
 #define __FPU_DP            1         /*!< Double Precision FPU                                                      */
 #define __DSP_PRESENT       1         /*!< DSP extension present                                                     */
 #define __ICACHE_PRESENT    1         /*!< Instruction Cache present                                                 */
 #define __DCACHE_PRESENT    1         /*!< Data Cache present                                                        */

/** @} */ /* End of group Configuration_of_RX */

 #include "system.h"                   /*!< R5K574M System                                                            */

 #ifndef __IM                          /*!< Fallback for older CMSIS versions                                         */
  #define __IM     __I
 #endif
 #ifndef __OM                          /*!< Fallback for older CMSIS versions                                         */
  #define __OM     __O
 #endif
 #ifndef __IOM                         /*!< Fallback for older CMSIS versions                                         */
  #define __IOM    __IO
 #endif

/** @addtogroup Device_Peripheral_clusters
 * @{
 */
 #include "R5K574M/r_adc_b_reg.h"
 #include "R5K574M/r_bus_reg.h"
 #include "R5K574M/r_cac_reg.h"
 #include "R5K574M/r_cache_reg.h"
 #include "R5K574M/r_canfd_reg.h"
 #include "R5K574M/r_canfdg_reg.h"
 #include "R5K574M/r_cmt_reg.h"
 #include "R5K574M/r_cmtw_reg.h"
 #include "R5K574M/r_coma_reg.h"
 #include "R5K574M/r_cpscu_reg.h"
 #include "R5K574M/r_crc_reg.h"
 #include "R5K574M/r_dac_b_reg.h"
 #include "R5K574M/r_dma_reg.h"
 #include "R5K574M/r_dmac_reg.h"
 #include "R5K574M/r_doc_reg.h"
 #include "R5K574M/r_dotf_reg.h"
 #include "R5K574M/r_dsmif_reg.h"
 #include "R5K574M/r_dtc_reg.h"
 #include "R5K574M/r_elc_reg.h"
 #include "R5K574M/r_esc_reg.h"
 #include "R5K574M/r_eswm_reg.h"
 #include "R5K574M/r_etha_reg.h"
 #include "R5K574M/r_exdma_reg.h"
 #include "R5K574M/r_exdmac_reg.h"
 #include "R5K574M/r_gpt_reg.h"
 #include "R5K574M/r_gptp_reg.h"
 #include "R5K574M/r_gwca_reg.h"
 #include "R5K574M/r_i3c_reg.h"
 #include "R5K574M/r_icu_reg.h"
 #include "R5K574M/r_iwdt_reg.h"
 #include "R5K574M/r_mfwd_reg.h"
 #include "R5K574M/r_mpu_reg.h"
 #include "R5K574M/r_mpu_mmpu_reg.h"
 #include "R5K574M/r_mram_reg.h"
 #include "R5K574M/r_pcif_reg.h"
 #include "R5K574M/r_pdc_reg.h"
 #include "R5K574M/r_pdm_reg.h"
 #include "R5K574M/r_poeg_reg.h"
 #include "R5K574M/r_port_reg.h"
 #include "R5K574M/r_pscu_reg.h"
 #include "R5K574M/r_rmac_reg.h"
 #include "R5K574M/r_rtc_reg.h"
 #include "R5K574M/r_sau_reg.h"
 #include "R5K574M/r_sci_b_reg.h"
 #include "R5K574M/r_sdhi_reg.h"
 #include "R5K574M/r_spi_b_reg.h"
 #include "R5K574M/r_sram_reg.h"
 #include "R5K574M/r_ssi_reg.h"
 #include "R5K574M/r_system_reg.h"
 #include "R5K574M/r_tmr_reg.h"
 #include "R5K574M/r_tsn_reg.h"
 #include "R5K574M/r_usb_basic_reg.h"
 #include "R5K574M/r_wdt_reg.h"
 #include "R5K574M/r_xspi_reg.h"
 #include "R5K574M/r_xspi_target_reg.h"

/** @} */ /* End of group Device_Peripheral_clusters */

/** @addtogroup Device_Peripheral_peripheralAddr
 * @{
 */

 #if defined(_RX_PZ_NONSECURE)
  #define BASE_NS_OFFSET        (-BSP_FEATURE_PZ_S_OFFSET)
 #else
  #define BASE_NS_OFFSET        0U
 #endif

 #define R_ADC_B0_BASE          (0x87438000UL + BASE_NS_OFFSET)
 #define R_BUS_BASE             (0x8701D000UL + BASE_NS_OFFSET)
 #define R_CAC_BASE             (0x87802400UL + BASE_NS_OFFSET)
 #define R_CAC1_BASE            (0x87802480UL + BASE_NS_OFFSET)
 #define R_CAC2_BASE            (0x87802500UL + BASE_NS_OFFSET)
 #define R_CACHE_BASE           (0x81010000UL + BASE_NS_OFFSET)
 #define R_CANFD_BASE           (0x87470000UL + BASE_NS_OFFSET)
 #define R_CANFDG_BASE          (0x87480000UL + BASE_NS_OFFSET)
 #define R_CMT_BASE             (0x87826000UL + BASE_NS_OFFSET)
 #define R_CMTW0_BASE           (0x87826100UL + BASE_NS_OFFSET)
 #define R_CMTW1_BASE           (0x87826140UL + BASE_NS_OFFSET)
 #define R_COMA_BASE            (0x874C9000UL + BASE_NS_OFFSET)
 #define R_CPSCU_BASE           (0x87018000UL + BASE_NS_OFFSET)
 #define R_CRC_BASE             (0x87410000UL + BASE_NS_OFFSET)
 #define R_DAC_B0_BASE          (0x87833000UL + BASE_NS_OFFSET)
 #define R_DAC_B1_BASE          (0x87833100UL + BASE_NS_OFFSET)
 #define R_DMA_BASE             (0x87007800UL + BASE_NS_OFFSET)
 #define R_DMAC0_BASE           (0x87007000UL + BASE_NS_OFFSET)
 #define R_DMAC1_BASE           (0x87007040UL + BASE_NS_OFFSET)
 #define R_DMAC2_BASE           (0x87007080UL + BASE_NS_OFFSET)
 #define R_DMAC3_BASE           (0x870070C0UL + BASE_NS_OFFSET)
 #define R_DMAC4_BASE           (0x87007100UL + BASE_NS_OFFSET)
 #define R_DMAC5_BASE           (0x87007140UL + BASE_NS_OFFSET)
 #define R_DMAC6_BASE           (0x87007180UL + BASE_NS_OFFSET)
 #define R_DMAC7_BASE           (0x870071C0UL + BASE_NS_OFFSET)
 #define R_DOC_B_BASE           (0x87411000UL + BASE_NS_OFFSET)
 #define R_DOTF0_BASE           (0x87868800UL + BASE_NS_OFFSET)
 #define R_DOTF1_BASE           (0x87868900UL + BASE_NS_OFFSET)
 #define R_DSMIF0_BASE          (0x8742A000UL + BASE_NS_OFFSET)
 #define R_DSMIF1_BASE          (0x8742A800UL + BASE_NS_OFFSET)
 #define R_DTC_BASE             (0x87007C00UL + BASE_NS_OFFSET)
 #define R_ELC_BASE             (0x87801000UL + BASE_NS_OFFSET)
 #define R_ESC_BASE             (0x874A0000UL + BASE_NS_OFFSET)
 #define R_ESWM_BASE            (0x874C8000UL + BASE_NS_OFFSET)
 #define R_ETHA0_BASE           (0x874CA000UL + BASE_NS_OFFSET)
 #define R_ETHA1_BASE           (0x874CC000UL + BASE_NS_OFFSET)
 #define R_EXDMA_BASE           (0x8701A800UL + BASE_NS_OFFSET)
 #define R_EXDMAC0_BASE         (0x8701A000UL + BASE_NS_OFFSET)
 #define R_EXDMAC1_BASE         (0x8701A040UL + BASE_NS_OFFSET)
 #define R_GPT0_BASE            (0x8742C000UL + BASE_NS_OFFSET)
 #define R_GPT1_BASE            (0x8742C100UL + BASE_NS_OFFSET)
 #define R_GPT2_BASE            (0x8742C200UL + BASE_NS_OFFSET)
 #define R_GPT3_BASE            (0x8742C300UL + BASE_NS_OFFSET)
 #define R_GPT4_BASE            (0x8742C400UL + BASE_NS_OFFSET)
 #define R_GPT5_BASE            (0x8742C500UL + BASE_NS_OFFSET)
 #define R_GPT6_BASE            (0x8742C600UL + BASE_NS_OFFSET)
 #define R_GPT7_BASE            (0x8742C700UL + BASE_NS_OFFSET)
 #define R_GPT8_BASE            (0x8742C800UL + BASE_NS_OFFSET)
 #define R_GPT9_BASE            (0x8742C900UL + BASE_NS_OFFSET)
 #define R_GPT10_BASE           (0x8742CA00UL + BASE_NS_OFFSET)
 #define R_GPT11_BASE           (0x8742CB00UL + BASE_NS_OFFSET)
 #define R_GPT12_BASE           (0x8742CC00UL + BASE_NS_OFFSET)
 #define R_GPT13_BASE           (0x8742CD00UL + BASE_NS_OFFSET)
 #define R_GPT14_BASE           (0x8742CE00UL + BASE_NS_OFFSET)
 #define R_GPT15_BASE           (0x8742CF00UL + BASE_NS_OFFSET)
 #define R_GPT_GTCLK_BASE       (0x8742BF10UL + BASE_NS_OFFSET)
 #define R_GPT_HRPWM_BASE       (0x87424000UL + BASE_NS_OFFSET)
 #define R_GPT_OPS_BASE         (0x8742BF00UL + BASE_NS_OFFSET)
 #define R_GPT_POEG0_BASE       (0x87412000UL + BASE_NS_OFFSET)
 #define R_GPT_POEG1_BASE       (0x87412100UL + BASE_NS_OFFSET)
 #define R_GPT_POEG2_BASE       (0x87412200UL + BASE_NS_OFFSET)
 #define R_GPT_POEG3_BASE       (0x87412300UL + BASE_NS_OFFSET)
 #define R_GPTP_BASE            (0x874E0000UL + BASE_NS_OFFSET)
 #define R_GWCA0_BASE           (0x874CE000UL + BASE_NS_OFFSET)
 #define R_I3C0_BASE            (0x8745F000UL + BASE_NS_OFFSET)
 #define R_I3C1_BASE            (0x8745F400UL + BASE_NS_OFFSET)
 #define R_I3C2_BASE            (0x8745F800UL + BASE_NS_OFFSET)
 #define R_ICU_BASE             (0x87006000UL + BASE_NS_OFFSET)
 #define R_IWDT_BASE            (0x87802200UL + BASE_NS_OFFSET)
 #define R_MFWD_BASE            (0x874C0000UL + BASE_NS_OFFSET)
 #define R_MRAM_BASE            (0x8709C000UL + BASE_NS_OFFSET)
 #define R_MSTP_BASE            (0x87803000UL + BASE_NS_OFFSET)
 #define R_PCIF0_BASE           (0x87827000UL + BASE_NS_OFFSET)
 #define R_PCIF1_BASE           (0x87827080UL + BASE_NS_OFFSET)
 #define R_MPU_BASE             (0x81000800UL + BASE_NS_OFFSET)
 #define R_MPU_MMPU_BASE        (0x87010000UL + BASE_NS_OFFSET)
 #define R_PDC_BASE             (0x87841000UL + BASE_NS_OFFSET)
 #define R_PDM_BASE             (0x87856000UL + BASE_NS_OFFSET)
 #define R_PFS_BASE             (0x87C00800UL + BASE_NS_OFFSET)
 #define R_PMISC_BASE           (0x87C00D00UL + BASE_NS_OFFSET)
 #define R_PORT0_BASE           (0x87C00000UL + BASE_NS_OFFSET)
 #define R_PORT1_BASE           (0x87C00020UL + BASE_NS_OFFSET)
 #define R_PORT2_BASE           (0x87C00040UL + BASE_NS_OFFSET)
 #define R_PORT3_BASE           (0x87C00060UL + BASE_NS_OFFSET)
 #define R_PORT4_BASE           (0x87C00080UL + BASE_NS_OFFSET)
 #define R_PORT5_BASE           (0x87C000A0UL + BASE_NS_OFFSET)
 #define R_PORT6_BASE           (0x87C000C0UL + BASE_NS_OFFSET)
 #define R_PORT7_BASE           (0x87C000E0UL + BASE_NS_OFFSET)
 #define R_PORT8_BASE           (0x87C00100UL + BASE_NS_OFFSET)
 #define R_PORT9_BASE           (0x87C00120UL + BASE_NS_OFFSET)
 #define R_PORT10_BASE          (0x87C00140UL + BASE_NS_OFFSET)
 #define R_PORT11_BASE          (0x87C00160UL + BASE_NS_OFFSET)
 #define R_PORT12_BASE          (0x87C00180UL + BASE_NS_OFFSET)
 #define R_PORT13_BASE          (0x87C001A0UL + BASE_NS_OFFSET)
 #define R_PORT14_BASE          (0x87C001C0UL + BASE_NS_OFFSET)
 #define R_PORT15_BASE          (0x87C001E0UL + BASE_NS_OFFSET)
 #define R_PORT16_BASE          (0x87C00200UL + BASE_NS_OFFSET)
 #define R_PSCU_BASE            (0x87804000UL + BASE_NS_OFFSET)
 #define R_RMAC0_BASE           (0x874CB000UL + BASE_NS_OFFSET)
 #define R_RMAC1_BASE           (0x874CD000UL + BASE_NS_OFFSET)
 #define R_RTC_BASE             (0x87802000UL + BASE_NS_OFFSET)
 #define R_SAU_BASE             0x81000400UL
 #define R_SCI_B0_BASE          (0x87458000UL + BASE_NS_OFFSET)
 #define R_SCI_B1_BASE          (0x87458100UL + BASE_NS_OFFSET)
 #define R_SCI_B2_BASE          (0x87458200UL + BASE_NS_OFFSET)
 #define R_SCI_B3_BASE          (0x87458300UL + BASE_NS_OFFSET)
 #define R_SCI_B4_BASE          (0x87458400UL + BASE_NS_OFFSET)
 #define R_SCI_B5_BASE          (0x87458500UL + BASE_NS_OFFSET)
 #define R_SCI_B6_BASE          (0x87458600UL + BASE_NS_OFFSET)
 #define R_SCI_B7_BASE          (0x87458700UL + BASE_NS_OFFSET)
 #define R_SCI_B8_BASE          (0x87458800UL + BASE_NS_OFFSET)
 #define R_SCI_B9_BASE          (0x87458900UL + BASE_NS_OFFSET)
 #define R_SCI_B10_BASE         (0x87458A00UL + BASE_NS_OFFSET)
 #define R_SCI_B11_BASE         (0x87458B00UL + BASE_NS_OFFSET)
 #define R_SCI_B12_BASE         (0x87458C00UL + BASE_NS_OFFSET)
 #define R_SDHI0_BASE           (0x87852000UL + BASE_NS_OFFSET)
 #define R_SPI_B0_BASE          (0x8745C000UL + BASE_NS_OFFSET)
 #define R_SPI_B1_BASE          (0x8745C100UL + BASE_NS_OFFSET)
 #define R_SPI_B2_BASE          (0x8745C200UL + BASE_NS_OFFSET)
 #define R_SRAM_BASE            0x8701C000UL
 #define R_SRAM_NS_BASE         0x0701C000UL
 #define R_SSI0_BASE            (0x8785D000UL + BASE_NS_OFFSET)
 #define R_SSI1_BASE            (0x8785D100UL + BASE_NS_OFFSET)
 #define R_SYSTEM_BASE          (0x87019000UL + BASE_NS_OFFSET)
 #define R_TMR01_BASE           (0x87825000UL + BASE_NS_OFFSET)
 #define R_TMR23_BASE           (0x87825010UL + BASE_NS_OFFSET)
 #define R_TSN_CAL_BASE         (0x86C12DA0UL + BASE_NS_OFFSET)
 #define R_TSN_CTRL_BASE        (0x87835000UL + BASE_NS_OFFSET)
 #define R_USB_FS0_BASE         (0x87850000UL + BASE_NS_OFFSET)
 #define R_USB_HS0_BASE         (0x87451000UL + BASE_NS_OFFSET)
 #define R_WDT_BASE             (0x87802600UL + BASE_NS_OFFSET)
 #define R_XSPI0_BASE           (0x87868000UL + BASE_NS_OFFSET)
 #define R_XSPI1_BASE           (0x87868400UL + BASE_NS_OFFSET)
 #define R_XSPI_TARGET0_BASE    (0x87867000UL + BASE_NS_OFFSET)
 #define R_XSPI_TARGET1_BASE    (0x87867400UL + BASE_NS_OFFSET)

/** @} */ /* End of group Device_Peripheral_peripheralAddr */

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_declaration
 * @{
 */

 #define R_ADC_B           ((R_ADC_B0_Type *) R_ADC_B0_BASE)
 #define R_BUS             ((R_BUS_Type *) R_BUS_BASE)
 #define R_CAC             ((R_CAC_Type *) R_CAC_BASE)
 #define R_CAC1            ((R_CAC_Type *) R_CAC1_BASE)
 #define R_CAC2            ((R_CAC_Type *) R_CAC2_BASE)
 #define R_CACHE           ((R_CACHE_Type *) R_CACHE_BASE)
 #define R_CANFD           ((R_CANFD_Type *) R_CANFD_BASE)
 #define R_CANFDG          ((R_CANFDG_Type *) R_CANFDG_BASE)
 #define R_CMT             ((R_CMT_Type *) R_CMT_BASE)
 #define R_CMTW0           ((R_CMTW0_Type *) R_CMTW0_BASE)
 #define R_CMTW1           ((R_CMTW0_Type *) R_CMTW1_BASE)
 #define R_COMA            ((R_COMA_Type *) R_COMA_BASE)
 #define R_CPSCU           ((R_CPSCU_Type *) R_CPSCU_BASE)
 #define R_CRC             ((R_CRC_Type *) R_CRC_BASE)
 #define R_DAC_B0          ((R_DAC_B0_Type *) R_DAC_B0_BASE)
 #define R_DAC_B1          ((R_DAC_B0_Type *) R_DAC_B1_BASE)
 #define R_DMA             ((R_DMA_Type *) R_DMA_BASE)
 #define R_DMAC0           ((R_DMAC0_Type *) R_DMAC0_BASE)
 #define R_DMAC1           ((R_DMAC0_Type *) R_DMAC1_BASE)
 #define R_DMAC2           ((R_DMAC0_Type *) R_DMAC2_BASE)
 #define R_DMAC3           ((R_DMAC0_Type *) R_DMAC3_BASE)
 #define R_DMAC4           ((R_DMAC0_Type *) R_DMAC4_BASE)
 #define R_DMAC5           ((R_DMAC0_Type *) R_DMAC5_BASE)
 #define R_DMAC6           ((R_DMAC0_Type *) R_DMAC6_BASE)
 #define R_DMAC7           ((R_DMAC0_Type *) R_DMAC7_BASE)
 #define R_DOC_B           ((R_DOC_B_Type *) R_DOC_B_BASE)
 #define R_DOTF0           ((R_DOTF0_Type *) R_DOTF0_BASE)
 #define R_DOTF1           ((R_DOTF0_Type *) R_DOTF1_BASE)
 #define R_DSMIF0          ((R_DSMIF0_Type *) R_DSMIF0_BASE)
 #define R_DSMIF1          ((R_DSMIF0_Type *) R_DSMIF1_BASE)
 #define R_DTC             ((R_DTC_Type *) R_DTC_BASE)
 #define R_ELC             ((R_ELC_Type *) R_ELC_BASE)
 #define R_ESC             ((R_ESC_Type *) R_ESC_BASE)
 #define R_ESWM            ((R_ESWM_Type *) R_ESWM_BASE)
 #define R_ETHA0           ((R_ETHA0_Type *) R_ETHA0_BASE)
 #define R_ETHA1           ((R_ETHA0_Type *) R_ETHA1_BASE)
 #define R_EXDMA           ((R_EXDMA_Type *) R_EXDMA_BASE)
 #define R_EXDMAC0         ((R_EXDMAC0_Type *) R_EXDMAC0_BASE)
 #define R_EXDMAC1         ((R_EXDMAC0_Type *) R_EXDMAC1_BASE)
 #define R_GPT0            ((R_GPT0_Type *) R_GPT0_BASE)
 #define R_GPT1            ((R_GPT0_Type *) R_GPT1_BASE)
 #define R_GPT2            ((R_GPT0_Type *) R_GPT2_BASE)
 #define R_GPT3            ((R_GPT0_Type *) R_GPT3_BASE)
 #define R_GPT4            ((R_GPT0_Type *) R_GPT4_BASE)
 #define R_GPT5            ((R_GPT0_Type *) R_GPT5_BASE)
 #define R_GPT6            ((R_GPT0_Type *) R_GPT6_BASE)
 #define R_GPT7            ((R_GPT0_Type *) R_GPT7_BASE)
 #define R_GPT8            ((R_GPT0_Type *) R_GPT8_BASE)
 #define R_GPT9            ((R_GPT0_Type *) R_GPT9_BASE)
 #define R_GPT10           ((R_GPT0_Type *) R_GPT10_BASE)
 #define R_GPT11           ((R_GPT0_Type *) R_GPT11_BASE)
 #define R_GPT12           ((R_GPT0_Type *) R_GPT12_BASE)
 #define R_GPT13           ((R_GPT0_Type *) R_GPT13_BASE)
 #define R_GPT14           ((R_GPT0_Type *) R_GPT14_BASE)
 #define R_GPT15           ((R_GPT0_Type *) R_GPT15_BASE)
 #define R_GPT_GTCLK       ((R_GPT_GTCLK_Type *) R_GPT_GTCLK_BASE)
 #define R_GPT_HRPWM       ((R_GPT_HRPWM_Type *) R_GPT_HRPWM_BASE)
 #define R_GPT_OPS         ((R_GPT_OPS_Type *) R_GPT_OPS_BASE)
 #define R_GPT_POEG0       ((R_GPT_POEG0_Type *) R_GPT_POEG0_BASE)
 #define R_GPT_POEG1       ((R_GPT_POEG0_Type *) R_GPT_POEG1_BASE)
 #define R_GPT_POEG2       ((R_GPT_POEG0_Type *) R_GPT_POEG2_BASE)
 #define R_GPT_POEG3       ((R_GPT_POEG0_Type *) R_GPT_POEG3_BASE)
 #define R_GPTP            ((R_GPTP_Type *) R_GPTP_BASE)
 #define R_GWCA0           ((R_GWCA0_Type *) R_GWCA0_BASE)
 #define R_I3C0            ((R_I3C0_Type *) R_I3C0_BASE)
 #define R_I3C1            ((R_I3C0_Type *) R_I3C1_BASE)
 #define R_I3C2            ((R_I3C0_Type *) R_I3C2_BASE)
 #define R_ICU             ((R_ICU_Type *) R_ICU_BASE)
 #define R_IWDT            ((R_IWDT_Type *) R_IWDT_BASE)
 #define R_MFWD            ((R_MFWD_Type *) R_MFWD_BASE)
 #define R_MPU             ((R_MPU_Type *) R_MPU_BASE)
 #define R_MPU_MMPU        ((R_MPU_MMPU_Type *) R_MPU_MMPU_BASE)
 #define R_MRAM            ((R_MRAM_Type *) R_MRAM_BASE)
 #define R_MSTP            ((R_MSTP_Type *) R_MSTP_BASE)
 #define R_PCIF0           ((R_PCIF0_Type *) R_PCIF0_BASE)
 #define R_PCIF1           ((R_PCIF0_Type *) R_PCIF1_BASE)
 #define R_PDC             ((R_PDC_Type *) R_PDC_BASE)
 #define R_PDM             ((R_PDM_Type *) R_PDM_BASE)
 #define R_PFS             ((R_PFS_Type *) R_PFS_BASE)
 #define R_PMISC           ((R_PMISC_Type *) R_PMISC_BASE)
 #define R_PORT0           ((R_PORT0_Type *) R_PORT0_BASE)
 #define R_PORT1           ((R_PORT0_Type *) R_PORT1_BASE)
 #define R_PORT2           ((R_PORT0_Type *) R_PORT2_BASE)
 #define R_PORT3           ((R_PORT0_Type *) R_PORT3_BASE)
 #define R_PORT4           ((R_PORT0_Type *) R_PORT4_BASE)
 #define R_PORT5           ((R_PORT0_Type *) R_PORT5_BASE)
 #define R_PORT6           ((R_PORT0_Type *) R_PORT6_BASE)
 #define R_PORT7           ((R_PORT0_Type *) R_PORT7_BASE)
 #define R_PORT8           ((R_PORT0_Type *) R_PORT8_BASE)
 #define R_PORT9           ((R_PORT0_Type *) R_PORT9_BASE)
 #define R_PORT10          ((R_PORT0_Type *) R_PORT10_BASE)
 #define R_PORT11          ((R_PORT0_Type *) R_PORT11_BASE)
 #define R_PORT12          ((R_PORT0_Type *) R_PORT12_BASE)
 #define R_PORT13          ((R_PORT0_Type *) R_PORT13_BASE)
 #define R_PORT14          ((R_PORT0_Type *) R_PORT14_BASE)
 #define R_PORT15          ((R_PORT0_Type *) R_PORT15_BASE)
 #define R_PORT16          ((R_PORT0_Type *) R_PORT16_BASE)
 #define R_PSCU            ((R_PSCU_Type *) R_PSCU_BASE)
 #define R_RMAC0           ((R_RMAC0_Type *) R_RMAC0_BASE)
 #define R_RMAC1           ((R_RMAC0_Type *) R_RMAC1_BASE)
 #define R_RTC             ((R_RTC_Type *) R_RTC_BASE)
 #define R_SAU             ((R_SAU_Type *) R_SAU_BASE)
 #define R_SCI_B0          ((R_SCI_B0_Type *) R_SCI_B0_BASE)
 #define R_SCI_B1          ((R_SCI_B0_Type *) R_SCI_B1_BASE)
 #define R_SCI_B2          ((R_SCI_B0_Type *) R_SCI_B2_BASE)
 #define R_SCI_B3          ((R_SCI_B0_Type *) R_SCI_B3_BASE)
 #define R_SCI_B4          ((R_SCI_B0_Type *) R_SCI_B4_BASE)
 #define R_SCI_B5          ((R_SCI_B0_Type *) R_SCI_B5_BASE)
 #define R_SCI_B6          ((R_SCI_B0_Type *) R_SCI_B6_BASE)
 #define R_SCI_B7          ((R_SCI_B0_Type *) R_SCI_B7_BASE)
 #define R_SCI_B8          ((R_SCI_B0_Type *) R_SCI_B8_BASE)
 #define R_SCI_B9          ((R_SCI_B0_Type *) R_SCI_B9_BASE)
 #define R_SCI_B10         ((R_SCI_B0_Type *) R_SCI_B10_BASE)
 #define R_SCI_B11         ((R_SCI_B0_Type *) R_SCI_B11_BASE)
 #define R_SCI_B12         ((R_SCI_B0_Type *) R_SCI_B12_BASE)
 #define R_SDHI0           ((R_SDHI0_Type *) R_SDHI0_BASE)
 #define R_SPI_B0          ((R_SPI_B0_Type *) R_SPI_B0_BASE)
 #define R_SPI_B1          ((R_SPI_B0_Type *) R_SPI_B1_BASE)
 #define R_SPI_B2          ((R_SPI_B0_Type *) R_SPI_B2_BASE)
 #define R_SRAM            ((R_SRAM_Type *) R_SRAM_BASE)
 #define R_SRAM_NS         ((R_SRAM_NS_Type *) R_SRAM_NS_BASE)
 #define R_SSI0            ((R_SSI0_Type *) R_SSI0_BASE)
 #define R_SSI1            ((R_SSI0_Type *) R_SSI1_BASE)
 #define R_SYSTEM          ((R_SYSTEM_Type *) R_SYSTEM_BASE)
 #define R_TMR01           ((R_TMR_Type *) R_TMR01_BASE)
 #define R_TMR23           ((R_TMR_Type *) R_TMR23_BASE)
 #define R_TSN_CAL         ((R_TSN_CAL_Type *) R_TSN_CAL_BASE)
 #define R_TSN_CTRL        ((R_TSN_CTRL_Type *) R_TSN_CTRL_BASE)
 #define R_USB_FS0         ((R_USB_FS0_Type *) R_USB_FS0_BASE)
 #define R_USB_HS0         ((R_USB_HS0_Type *) R_USB_HS0_BASE)
 #define R_WDT             ((R_WDT_Type *) R_WDT_BASE)
 #define R_XSPI0           ((R_XSPI0_Type *) R_XSPI0_BASE)
 #define R_XSPI1           ((R_XSPI0_Type *) R_XSPI1_BASE)
 #define R_XSPI_TARGET0    ((R_XSPI_TARGET0_Type *) R_XSPI_TARGET0_BASE)
 #define R_XSPI_TARGET1    ((R_XSPI_TARGET0_Type *) R_XSPI_TARGET1_BASE)

/** @} */ /* End of group Device_Peripheral_declaration */

/* =========================================================================================================================== */
/* ================                                 Pos/Mask Cluster Section                                  ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_clusters
 * @{
 */
 #include "R5K574M/r_adc_b_posmsk.h"
 #include "R5K574M/r_bus_posmsk.h"
 #include "R5K574M/r_cac_posmsk.h"
 #include "R5K574M/r_cache_posmsk.h"
 #include "R5K574M/r_canfd_posmsk.h"
 #include "R5K574M/r_canfdg_posmsk.h"
 #include "R5K574M/r_cmt_posmsk.h"
 #include "R5K574M/r_cmtw_posmsk.h"
 #include "R5K574M/r_coma_posmsk.h"
 #include "R5K574M/r_cpscu_posmsk.h"
 #include "R5K574M/r_crc_posmsk.h"
 #include "R5K574M/r_dac_b_posmsk.h"
 #include "R5K574M/r_dma_posmsk.h"
 #include "R5K574M/r_dmac_posmsk.h"
 #include "R5K574M/r_doc_posmsk.h"
 #include "R5K574M/r_dotf_posmsk.h"
 #include "R5K574M/r_dsmif_posmsk.h"
 #include "R5K574M/r_dtc_posmsk.h"
 #include "R5K574M/r_elc_posmsk.h"
 #include "R5K574M/r_esc_posmsk.h"
 #include "R5K574M/r_eswm_posmsk.h"
 #include "R5K574M/r_etha_posmsk.h"
 #include "R5K574M/r_exdma_posmsk.h"
 #include "R5K574M/r_exdmac_posmsk.h"
 #include "R5K574M/r_gpt_posmsk.h"
 #include "R5K574M/r_gptp_posmsk.h"
 #include "R5K574M/r_gwca_posmsk.h"
 #include "R5K574M/r_i3c_posmsk.h"
 #include "R5K574M/r_icu_posmsk.h"
 #include "R5K574M/r_iwdt_posmsk.h"
 #include "R5K574M/r_mfwd_posmsk.h"
 #include "R5K574M/r_mpu_posmsk.h"
 #include "R5K574M/r_mpu_mmpu_posmsk.h"
 #include "R5K574M/r_mram_posmsk.h"
 #include "R5K574M/r_pcif_posmsk.h"
 #include "R5K574M/r_pdc_posmsk.h"
 #include "R5K574M/r_pdm_posmsk.h"
 #include "R5K574M/r_poeg_posmsk.h"
 #include "R5K574M/r_port_posmsk.h"
 #include "R5K574M/r_pscu_posmsk.h"
 #include "R5K574M/r_rmac_posmsk.h"
 #include "R5K574M/r_rtc_posmsk.h"
 #include "R5K574M/r_sau_posmsk.h"
 #include "R5K574M/r_sci_b_posmsk.h"
 #include "R5K574M/r_sdhi_posmsk.h"
 #include "R5K574M/r_spi_b_posmsk.h"
 #include "R5K574M/r_sram_posmsk.h"
 #include "R5K574M/r_ssi_posmsk.h"
 #include "R5K574M/r_system_posmsk.h"
 #include "R5K574M/r_tmr_posmsk.h"
 #include "R5K574M/r_tsn_posmsk.h"
 #include "R5K574M/r_usb_basic_posmsk.h"
 #include "R5K574M/r_wdt_posmsk.h"
 #include "R5K574M/r_xspi_posmsk.h"
 #include "R5K574M/r_xspi_target_posmsk.h"

/** @} */ /* End of group PosMask_peripherals */

 #ifdef __cplusplus
}
 #endif

#endif                                 /* R5K574M_H */

/** @} */ /* End of group R5K574M */

/** @} */ /* End of group Renesas Electronics Corporation */
