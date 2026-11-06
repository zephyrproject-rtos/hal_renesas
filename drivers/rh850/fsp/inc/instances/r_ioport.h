/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup IOPORT
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

#ifndef R_IOPORT_H
#define R_IOPORT_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#include "r_ioport_api.h"
#include "r_ioport_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "PORT" in ASCII, used to determine if the module is open */
#define IOPORT_OPEN                   (0x504F5254U)
#define IOPORT_CLOSED                 (0x00000000U)

#define IOPORT_PINCFG_PSFTS_MASK      (1UL << 13UL)
#define IOPORT_PINCFG_PSFTSE_MASK     (1UL << 14UL)
#define IOPORT_PINCFG_PSFTSAE_MASK    (1UL << 15UL)
#define IOPORT_PINCFG_PSFC_MASK       (1UL << 21UL)
#define IOPORT_PINCFG_PEIODC_MASK     (1UL << 23UL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Superset ALT mode functions.  */
typedef enum e_ioport_alt                                                                             /* PRQA S 1536 # Advisory R-2.4 */
{
    IOPORT_ALT_IN1  = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x00U << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 1
    IOPORT_ALT_IN2  = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x01U << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 2
    IOPORT_ALT_IN3  = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x02U << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 3
    IOPORT_ALT_IN4  = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x03U << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 4
    IOPORT_ALT_IN5  = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x04U << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 5
    IOPORT_ALT_IN6  = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x05U << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 6
    IOPORT_ALT_IN7  = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x06U << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 7
    IOPORT_ALT_IN8  = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x07U << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 8
    IOPORT_ALT_IN9  = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x08U << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 9
    IOPORT_ALT_IN10 = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x09U << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 10
    IOPORT_ALT_IN11 = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0aU << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 11
    IOPORT_ALT_IN12 = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0bU << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 12
    IOPORT_ALT_IN13 = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0cU << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 13
    IOPORT_ALT_IN14 = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0dU << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 14
    IOPORT_ALT_IN15 = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0eU << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 15
    IOPORT_ALT_IN16 = (1U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0fU << R_PORT_PCRn_m_PCR_PFC_Pos),        ///< Alternative input 16

    IOPORT_ALT_OUT1  = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x00U << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 1
    IOPORT_ALT_OUT2  = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x01U << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 2
    IOPORT_ALT_OUT3  = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x02U << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 3
    IOPORT_ALT_OUT4  = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x03U << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 4
    IOPORT_ALT_OUT5  = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x04U << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 5
    IOPORT_ALT_OUT6  = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x05U << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 6
    IOPORT_ALT_OUT7  = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x06U << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 7
    IOPORT_ALT_OUT8  = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x07U << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 8
    IOPORT_ALT_OUT9  = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x08U << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 9
    IOPORT_ALT_OUT10 = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x09U << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 10
    IOPORT_ALT_OUT11 = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0aU << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 11
    IOPORT_ALT_OUT12 = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0bU << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 12
    IOPORT_ALT_OUT13 = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0cU << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 13
    IOPORT_ALT_OUT14 = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0dU << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 14
    IOPORT_ALT_OUT15 = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0eU << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 15
    IOPORT_ALT_OUT16 = (0U << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0fU << R_PORT_PCRn_m_PCR_PFC_Pos),       ///< Alternative output 16
} ioport_alt_t;                                                                                       /* PRQA S 1535 # Advisory R-2.3 */

/** Options to configure pin functions  */
typedef enum e_ioport_cfg_options                                                                     /* PRQA S 1536 # Advisory R-2.4 */
{
    IOPORT_CFG_PORT_DIRECTION_INPUT  = (uint32_t)(1U << R_PORT_PCRn_m_PCR_PM_Pos),                    ///< Sets the pin direction to input (default)
    IOPORT_CFG_PORT_DIRECTION_OUTPUT = (uint32_t)(0U << R_PORT_PCRn_m_PCR_PM_Pos),                    ///< Sets the pin direction to output
    IOPORT_CFG_INPUT_BUFFER_NONE     = (uint32_t)(0UL << R_PORT_PCRn_m_PCR_PIBC_Pos),                 ///< Disable input buffer on pin
    IOPORT_CFG_INPUT_BUFFER_SHMT1    = (uint32_t)((1UL << R_PORT_PCRn_m_PCR_PIBC_Pos) |
                                                  (0UL << R_PORT_PCRn_m_PCR_PIS_Pos)),                ///< Select input buffer type SHMT1
    IOPORT_CFG_INPUT_BUFFER_SHMT4 = (uint32_t)((1UL << R_PORT_PCRn_m_PCR_PIBC_Pos) |
                                               (1UL << R_PORT_PCRn_m_PCR_PIS_Pos)),                   ///< Select input buffer type SHMT4
    IOPORT_CFG_INPUT_BUFFER_TTL = (uint32_t)((1UL << R_PORT_PCRn_m_PCR_PIBC_Pos) |
                                             (4UL << R_PORT_PCRn_m_PCR_PIS_Pos)),                     ///< Select input buffer type TTL
    IOPORT_CFG_INPUT_BUFFER_SHMTMSC = (uint32_t)((1UL << R_PORT_PCRn_m_PCR_PIBC_Pos) |
                                                 (5UL << R_PORT_PCRn_m_PCR_PIS_Pos)),                 ///< Select input buffer type SHMTMSC
    IOPORT_CFG_BIDIRECTIONAL_ENABLE  = (uint32_t)(1UL << R_PORT_PCRn_m_PCR_PBDC_Pos),                 ///< Enable Pin Bidirectional
    IOPORT_CFG_BIDIRECTIONAL_DISABLE = (uint32_t)(0UL << R_PORT_PCRn_m_PCR_PBDC_Pos),                 ///< Disable Pin Bidirectional
    IOPORT_CFG_PORT_DIO_MODE         = (uint32_t)(0UL << R_PORT_PCRn_m_PCR_PMC_Pos),                  ///< Set pin mode to IO mode
    IOPORT_CFG_PERIPHERAL_PIN        = (uint32_t)(1UL << R_PORT_PCRn_m_PCR_PMC_Pos),                  ///< Set pin mode to Alternative mode
    IOPORT_CFG_PIPC_SOFTWARE         = (uint32_t)(0UL << R_PORT_PCRn_m_PCR_PIPC_Pos),                 ///< Set pin mode to alternative Software Control
    IOPORT_CFG_PIPC_PERIPHERAL       = (uint32_t)(1UL << R_PORT_PCRn_m_PCR_PIPC_Pos),                 ///< Set pin mode to Alternative Direct Control
    IOPORT_CFG_PULLUP                = (uint32_t)(1UL << R_PORT_PCRn_m_PCR_PU_Pos),                   ///< Enable the pin's internal pull-up
    IOPORT_CFG_PULLDOWN              = (uint32_t)(1UL << R_PORT_PCRn_m_PCR_PD_Pos),                   ///< Enable the pin's internal pull-down
    IOPORT_CFG_P_CH_OPEN_DRAIN       = (uint32_t)(3UL << R_PORT_PCRn_m_PCR_PODCE_Pos),                ///< Select output buffer open drain Emulated P-channel Open Drain
    IOPORT_CFG_N_CH_OPEN_DRAIN       = (uint32_t)(2UL << R_PORT_PCRn_m_PCR_PODCE_Pos),                ///< Select output buffer open drain Emulated N-channel Open Drain
    IOPORT_CFG_PUSHPULL              = (uint32_t)(0UL << R_PORT_PCRn_m_PCR_PODCE_Pos),                ///< Select output buffer push-pull
    IOPORT_CFG_DRIVE_HIGH            = (uint32_t)(3UL << R_PORT_PCRn_m_PCR_PDSC_Pos),                 ///< Select port drive strength high
    IOPORT_CFG_DRIVE_VERY_HIGH       = (uint32_t)(3UL << R_PORT_PCRn_m_PCR_PDSC_Pos),                 ///< Select port drive strength very high
    IOPORT_CFG_DRIVE_MEDIUM          = (uint32_t)(2UL << R_PORT_PCRn_m_PCR_PDSC_Pos),                 ///< Select port drive strength medium
    IOPORT_CFG_DRIVE_LOW             = (uint32_t)(1UL << R_PORT_PCRn_m_PCR_PDSC_Pos),                 ///< Select port drive strength low
    IOPORT_CFG_DRIVE_VERY_LOW        = (uint32_t)(0UL << R_PORT_PCRn_m_PCR_PDSC_Pos),                 ///< Select port drive strength very low
    IOPORT_CFG_PORT_OUTPUT_LOW       = (uint32_t)(0UL << R_PORT_PCRn_m_PCR_P_Pos),                    ///< Sets pin level to low
    IOPORT_CFG_PORT_OUTPUT_HIGH      = (uint32_t)(1UL << R_PORT_PCRn_m_PCR_P_Pos),                    ///< Set pin level to high
    IOPORT_CFG_OUTPUT_INVERT         = (uint32_t)(1UL << R_PORT_PCRn_m_PCR_PINV_Pos)                  ///< Set Inverted Output
} ioport_cfg_options_t;                                                                               /* PRQA S 1535 # Advisory R-2.3 */

/** Options to enable the NF function */
typedef enum e_ioport_filter_dnfaen                                                                   /* PRQA S 1536 # Advisory R-2.4 */
{
    IOPORT_FILTER_DNFENL_0 = (uint16_t)(1UL << 0UL),                                                  ///< Enable NFENL0
    IOPORT_FILTER_DNFENL_1 = (uint16_t)(1UL << 1UL),                                                  ///< Enable NFENL1
    IOPORT_FILTER_DNFENL_2 = (uint16_t)(1UL << 2UL),                                                  ///< Enable NFENL2
    IOPORT_FILTER_DNFENL_3 = (uint16_t)(1UL << 3UL),                                                  ///< Enable NFENL3
    IOPORT_FILTER_DNFENL_4 = (uint16_t)(1UL << 4UL),                                                  ///< Enable NFENL4
    IOPORT_FILTER_DNFENL_5 = (uint16_t)(1UL << 5UL),                                                  ///< Enable NFENL5
    IOPORT_FILTER_DNFENL_6 = (uint16_t)(1UL << 6UL),                                                  ///< Enable NFENL6
    IOPORT_FILTER_DNFENL_7 = (uint16_t)(1UL << 7UL),                                                  ///< Enable NFENL7
    IOPORT_FILTER_DNFENH_0 = (uint16_t)(1UL << 8UL),                                                  ///< Enable NFENH0
    IOPORT_FILTER_DNFENH_1 = (uint16_t)(1UL << 9UL),                                                  ///< Enable NFENH1
    IOPORT_FILTER_DNFENH_2 = (uint16_t)(1UL << 10UL),                                                 ///< Enable NFENH2
    IOPORT_FILTER_DNFENH_3 = (uint16_t)(1UL << 11UL),                                                 ///< Enable NFENH3
    IOPORT_FILTER_DNFENH_4 = (uint16_t)(1UL << 12UL),                                                 ///< Enable NFENH4
    IOPORT_FILTER_DNFENH_5 = (uint16_t)(1UL << 13UL),                                                 ///< Enable NFENH5
    IOPORT_FILTER_DNFENH_6 = (uint16_t)(1UL << 14UL),                                                 ///< Enable NFENH6
    IOPORT_FILTER_DNFENH_7 = (uint16_t)(1UL << 15UL)                                                  ///< Enable NFENH7
} ioport_filter_dnfen_t;                                                                              /* PRQA S 1535 # Advisory R-2.3 */

/** Options to configuration the Port ERRORIN Open-drain function */
typedef enum e_ioport_cfg_errorin                                                                     /* PRQA S 1536 # Advisory R-2.4 */
{
    IOPORT_CFG_ERRORIN_HI_Z            = (uint32_t) 0U,                                               ///< Disable Port Safe State Function
    IOPORT_CFG_ERRORIN_N_CH_OPEN_DRAIN = (uint32_t)(1UL << 23UL)                                      ///< Enable Port Safe State Function
} ioport_cfg_errorin_t;                                                                               /* PRQA S 1535 # Advisory R-2.3 */

/** Options to select the error trigger source for Port Safe State function */
typedef enum e_ioport_cfg_error_trigger                                                               /* PRQA S 1536 # Advisory R-2.4 */
{
    IOPORT_CFG_ERROR_TRIGGER_DISABLE = (uint32_t) 0U,                                                 ///< Port Safe State function is disabled
    IOPORT_CFG_ERROR_TRIGGER_0       = (uint32_t)IOPORT_PINCFG_PSFC_MASK,                             ///< Error Trigger 0 is selected for Port Safe State function.
    IOPORT_CFG_ERROR_TRIGGER_1       = (uint32_t)IOPORT_PINCFG_PSFC_MASK | IOPORT_PINCFG_PSFTS_MASK,  ///< Error Trigger 1 is selected for Port Safe State function.
    IOPORT_CFG_ERROR_TRIGGER_2       = (uint32_t)IOPORT_PINCFG_PSFC_MASK | IOPORT_PINCFG_PSFTSE_MASK, ///< Error Trigger 2 is selected for Port Safe State function.
    IOPORT_CFG_ERROR_TRIGGER_3       = (uint32_t)IOPORT_PINCFG_PSFC_MASK | IOPORT_PINCFG_PSFTSE_MASK |
                                       IOPORT_PINCFG_PSFTS_MASK,                                      ///< Error Trigger 3 is selected for Port Safe State function.
    IOPORT_CFG_ERROR_TRIGGER_4 = (uint32_t)IOPORT_PINCFG_PSFC_MASK | IOPORT_PINCFG_PSFTSAE_MASK,      ///< Error Trigger 4 is selected for Port Safe State function.
    IOPORT_CFG_ERROR_TRIGGER_5 = (uint32_t)IOPORT_PINCFG_PSFC_MASK | IOPORT_PINCFG_PSFTSAE_MASK |
                                 IOPORT_PINCFG_PSFTS_MASK,                                            ///< Error Trigger 5 is selected for Port Safe State function.
    IOPORT_CFG_ERROR_TRIGGER_6 = (uint32_t)IOPORT_PINCFG_PSFC_MASK | IOPORT_PINCFG_PSFTSAE_MASK |
                                 IOPORT_PINCFG_PSFTSE_MASK,                                           ///< Error Trigger 6 is selected for Port Safe State function.
    IOPORT_CFG_ERROR_TRIGGER_7 = (uint32_t)IOPORT_PINCFG_PSFC_MASK | IOPORT_PINCFG_PSFTSAE_MASK |
                                 IOPORT_PINCFG_PSFTSE_MASK | IOPORT_PINCFG_PSFTS_MASK                 ///< Error Trigger 7 is selected for Port Safe State function.
} ioport_cfg_error_trigger_t;                                                                         /* PRQA S 1535 # Advisory R-2.3 */

/** Options to select the PULVSEL5 function */
typedef enum e_ioport_pulvsel5                                                                        /* PRQA S 1536 # Advisory R-2.4 */
{
    IOPORT_PULVSEL5_0 = (uint16_t)(1U << 0UL),                                                        ///< Enable PULVSEL5_0
    IOPORT_PULVSEL5_1 = (uint16_t)(1U << 1UL),                                                        ///< Enable PULVSEL5_1
    IOPORT_PULVSEL5_2 = (uint16_t)(1U << 2UL),                                                        ///< Enable PULVSEL5_2
    IOPORT_PULVSEL5_3 = (uint16_t)(1U << 3UL),                                                        ///< Enable PULVSEL5_3
    IOPORT_PULVSEL5_4 = (uint16_t)(1U << 4UL),                                                        ///< Enable PULVSEL5_4
    IOPORT_PULVSEL5_5 = (uint16_t)(1U << 5UL),                                                        ///< Enable PULVSEL5_5
    IOPORT_PULVSEL5_6 = (uint16_t)(1U << 6UL),                                                        ///< Enable PULVSEL5_6
    IOPORT_PULVSEL5_7 = (uint16_t)(1U << 7UL),                                                        ///< Enable PULVSEL5_7
} ioport_pulvsel5_t;                                                                                  /* PRQA S 1535 # Advisory R-2.3 */

/** IOPORT NF Enable configuration
 */
typedef struct st_ioport_nf_enable_cfg                                                                /* PRQA S 1536 # Advisory R-2.4 */
{
    uint16_t noise_filter_enable_rlin;                                                                ///< Set Enable Noise Filter RLIN
    uint16_t noise_filter_enable_rscan;                                                               ///< Set Enable Noise Filter RSCAN
    uint16_t noise_filter_enable_flxa;                                                                ///< Set Enable Noise Filter FLXA
    uint16_t noise_filter_enable_sent0;                                                               ///< Set Enable Noise Filter SENT2
    uint16_t noise_filter_enable_sent1;                                                               ///< Set Enable Noise Filter SENT1
    uint16_t noise_filter_enable_psi5;                                                                ///< Set Enable Noise Filter PSI5
    uint16_t noise_filter_enable_pic_tapa;                                                            ///< Set Enable Noise Filter TAPA
    uint16_t noise_filter_enable_adcj0;                                                               ///< Set Enable Noise Filter ACKJ0
    uint16_t noise_filter_enable_adcj1;                                                               ///< Set Enable Noise Filter ACKJ1
    uint16_t noise_filter_enable_adcj2;                                                               ///< Set Enable Noise Filter ACKJ2
    uint16_t noise_filter_enable_adck0;                                                               ///< Set Enable Noise Filter ADCK0
    uint16_t noise_filter_enable_adck1;                                                               ///< Set Enable Noise Filter ADCK1
    uint16_t noise_filter_enable_adck2;                                                               ///< Set Enable Noise Filter ADCK2
    uint16_t noise_filter_enable_adck3;                                                               ///< Set Enable Noise Filter ADCK3
    uint16_t noise_filter_enable_adcka;                                                               ///< Set Enable Noise Filter ADCKA
    uint16_t noise_filter_enable_rhsb;                                                                ///< Set Enable Noise Filter RHSB
    uint16_t noise_filter_enable_enca;                                                                ///< Set Enable Noise Filter ENCA
    uint16_t noise_filter_enable_taud0;                                                               ///< Set Enable Noise Filter TAUD0
    uint16_t noise_filter_enable_taud1;                                                               ///< Set Enable Noise Filter TAUD1
    uint16_t noise_filter_enable_taud2;                                                               ///< Set Enable Noise Filter TAUD2
    uint16_t noise_filter_enable_taud3;                                                               ///< Set Enable Noise Filter TAUD3
    uint16_t noise_filter_enable_tsg3;                                                                ///< Set Enable Noise Filter TSG3
    uint16_t noise_filter_enable_ecm;                                                                 ///< Set Enable Noise Filter ECM
    uint16_t noise_filter_enable_tauj0;                                                               ///< Set Enable Noise Filter TAUJ0
    uint16_t noise_filter_enable_tauj1;                                                               ///< Set Enable Noise Filter TAUJ1
    uint16_t noise_filter_enable_tauj2;                                                               ///< Set Enable Noise Filter TAUJ2
    uint16_t noise_filter_enable_tauj3;                                                               ///< Set Enable Noise Filter TAUJ3
    uint16_t noise_filter_enable_pic_tsg;                                                             ///< Set Enable Noise Filter PIC(TSG)
    uint16_t noise_filter_enable_emu;                                                                 ///< Set Enable Noise Filter EMU
    uint16_t noise_filter_enable_ssif;                                                                ///< Set Enable Noise Filter SSIF
    uint16_t noise_filter_enable_ospi0;                                                               ///< Set Enable Noise Filter OSPI0
    uint16_t noise_filter_enable_esr0_irq0;                                                           ///< Set Enable Noise Filter ESR0_IRQ0
    uint16_t noise_filter_enable_esr0_nmi;                                                            ///< Set Enable Noise Filter ESR0_NMI
    uint16_t noise_filter_enable_esr1_nmi;                                                            ///< Set Enable Noise Filter ESR1_NMI
} ioport_nf_enable_cfg_t;

/** IOPORT NF extend configuration
 */
typedef struct st_ioport_nf_cfg                                                                       /* PRQA S 1536 # Advisory R-2.4 */
{
    ioport_nf_enable_cfg_t nf_enable_cfg;
    ioport_filter_cfg_t    nf_filter_cfg[IOPORT_FILTER_SIGNAL_MAX];
} ioport_nf_cfg_t;

/** IOPORT LVDS configuration
 */
typedef struct st_ioport_lvds_cfg        /* PRQA S 1536 # Advisory R-2.4 */
{
    uint32_t lvdsctrl_a;                 ///< Set configuration for LVDS control A register
    uint32_t lvdsctrl_b;                 ///< Set configuration for LVDS control B register
    uint32_t lvdsctrl_c;                 ///< Set configuration for LVDS control C register
    uint32_t lvdsctrl_d;                 ///< Set configuration for LVDS control D register
    uint32_t lvdsctrl_e;                 ///< Set configuration for LVDS control E register
    uint32_t lvdsctrl_f;                 ///< Set configuration for LVDS control F register
} ioport_lvds_cfg_t;

/** IOPORT extended configuration
 */
typedef struct st_ioport_extend_cfg      /* PRQA S 1536 # Advisory R-2.4 */
{
    ioport_nf_cfg_t   nf_cfg;            ///< Set configuration for DNF
    ioport_lvds_cfg_t lvds_cfg;          ///< Set configuration for LVDS
    uint16_t          pulvsel5_cfg;      ///< Set configuration for PULVSEL5
} ioport_extend_cfg_t;

/** IOPORT DNF Struct */
typedef struct st_ioport_nf_table_cfg    /* PRQA S 1536 # Advisory R-2.4 */
{
    volatile uint16_t * p_reg_dnfa_en;   ///< Base register for Digital Noise Elimination Enable.
    uint16_t            bit;             ///< Bit offset.
    volatile uint8_t  * p_reg_dnfa_ctrl; ///< Base register for Digital Noise Elimination Control.
    volatile uint8_t  * p_reg_fcla_ctrl; ///< Base register for Filter Control.
} ioport_nf_table_cfg_t;

/** IOPORT private control block. DO NOT MODIFY. Initialization occurs when R_IOPORT_Open() is called. */
typedef struct st_ioport_instance_ctrl   /* PRQA S 1536 # Advisory R-2.4 */
{
    uint32_t             open;
    const ioport_cfg_t * p_cfg;          ///< Pointer to initial configurations.
    R_DNFACTL_Type     * p_reg;          ///< Base register for Digital Noise Elimination.
    void const         * p_context;
} ioport_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const ioport_api_t        g_ioport_on_ioport;
extern const ioport_extend_cfg_t g_ioport_cfg_extend; /* PRQA S 1752, 3449, 3451 # DP_MSR_R-8.6_UC1, DP_MSR_R-8.5_UC1 */

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

fsp_err_t R_IOPORT_Open(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);
fsp_err_t R_IOPORT_Close(ioport_ctrl_t * const p_ctrl);
fsp_err_t R_IOPORT_PinsCfg(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);

/* PRQA S 1510 ++ # DP_MSR_R-1.3_UC1 */
fsp_err_t R_IOPORT_PinCfg(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, uint32_t cfg);
fsp_err_t R_IOPORT_PinEventInputRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_event);
fsp_err_t R_IOPORT_PinEventOutputWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t pin_value);
fsp_err_t R_IOPORT_PinRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_value);
fsp_err_t R_IOPORT_PinWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t level);
fsp_err_t R_IOPORT_PortDirectionSet(ioport_ctrl_t * const p_ctrl,
                                    bsp_io_port_t         port,
                                    ioport_size_t         direction_values,
                                    ioport_size_t         mask);
fsp_err_t R_IOPORT_PortEventInputRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_event_data);
fsp_err_t R_IOPORT_PortEventOutputWrite(ioport_ctrl_t * const p_ctrl,
                                        bsp_io_port_t         port,
                                        ioport_size_t         event_data,
                                        ioport_size_t         mask_value);
fsp_err_t R_IOPORT_PortRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_port_value);
fsp_err_t R_IOPORT_PortWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t value, ioport_size_t mask);

/* PRQA S 1510 -- */
fsp_err_t R_IOPORT_NoiseFilterEnable(ioport_ctrl_t * const p_ctrl, ioport_filter_signal_t filter_signal);
fsp_err_t R_IOPORT_NoiseFilterDisable(ioport_ctrl_t * const p_ctrl, ioport_filter_signal_t filter_signal);
fsp_err_t R_IOPORT_NoiseFilterCfg(ioport_ctrl_t * const       p_ctrl,
                                  ioport_filter_signal_t      filter_signal,
                                  const ioport_filter_cfg_t * p_filter_cfg);

/*******************************************************************************************************************//**
 * @} (end defgroup IOPORT)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_IOPORT_H
