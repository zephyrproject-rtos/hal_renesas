/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MODULE_H
#define BSP_MODULE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZN
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Cancels the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      channel  The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/
 #define R_BSP_MODULE_START(ip, channel)    {FSP_CRITICAL_SECTION_DEFINE;                                           \
                                             FSP_CRITICAL_SECTION_ENTER;                                            \
                                             BSP_MSTP_REG_ ## ip(channel) &= ~BSP_MSTP_BIT_ ## ip(channel);         \
                                             BSP_MSTP_REG_ ## ip(channel);                                          \
                                             uint8_t dummy_read_cnt = BSP_FEATURE_BSP_MODULE_STOP_DUMMY_READ_COUNT; \
                                             while (dummy_read_cnt)                                                 \
                                             {                                                                      \
                                                 BSP_MSTP_DMY_ ## ip(channel);                                      \
                                                 dummy_read_cnt--;                                                  \
                                             }                                                                      \
                                             FSP_CRITICAL_SECTION_EXIT;}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      channel  The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/
#define R_BSP_MODULE_STOP(ip, channel)              {FSP_CRITICAL_SECTION_DEFINE;                                  \
                                                     FSP_CRITICAL_SECTION_ENTER;                                   \
                                                     BSP_MSTP_REG_ ## ip(channel) |= BSP_MSTP_BIT_ ## ip(channel); \
                                                     BSP_MSTP_REG_ ## ip(channel);                                 \
                                                     FSP_CRITICAL_SECTION_EXIT;}

/** @} (end addtogroup BSP_MCU) */
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

#define BSP_MSTP_REG_FSP_IP_BSC(channel)            R_SYSC_NS->MSTPCRA
#define BSP_MSTP_BIT_FSP_IP_BSC(channel)            (1U)
#define BSP_MSTP_DMY_FSP_IP_BSC(channel)            ((0U == channel) ? R_BSC->TOENR : bsp_assert_channel(0))

#define BSP_MSTP_REG_FSP_IP_XSPI(channel)           R_SYSC_NS->MSTPCRA
#define BSP_MSTP_BIT_FSP_IP_XSPI(channel)           (1U << (4U + channel))
#define BSP_MSTP_DMY_FSP_IP_XSPI(channel) \
    do                                    \
    {                                     \
        switch (channel)                  \
        {                                 \
            case 0:                       \
            {                             \
                R_XSPI0->WRAPCFG;         \
                break;                    \
            }                             \
            case 1:                       \
            {                             \
                R_XSPI1->WRAPCFG;         \
                break;                    \
            }                             \
            default:                      \
            {                             \
                bsp_assert_channel(0);    \
                break;                    \
            }                             \
        }                                 \
    } while (0);

#define BSP_MSTP_REG_FSP_IP_SCI(channel)            *((4U >= channel) ? &R_SYSC_NS->MSTPCRA : &R_SYSC_S->MSTPCRG)
#define BSP_MSTP_BIT_FSP_IP_SCI(channel)            ((4U >= channel) ? (1U << (8U + channel)) : (1U))
#define BSP_MSTP_DMY_FSP_IP_SCI(channel) \
    do                                   \
    {                                    \
        switch (channel)                 \
        {                                \
            case 0:                      \
            {                            \
                R_SCI0->RDR;             \
                break;                   \
            }                            \
            case 1:                      \
            {                            \
                R_SCI1->RDR;             \
                break;                   \
            }                            \
            case 2:                      \
            {                            \
                R_SCI2->RDR;             \
                break;                   \
            }                            \
            case 3:                      \
            {                            \
                R_SCI3->RDR;             \
                break;                   \
            }                            \
            case 4:                      \
            {                            \
                R_SCI4->RDR;             \
                break;                   \
            }                            \
            case 5:                      \
            {                            \
                R_SCI5->RDR;             \
                break;                   \
            }                            \
            default:                     \
            {                            \
                bsp_assert_channel(0);   \
                break;                   \
            }                            \
        }                                \
    } while (0);

#if BSP_FEATURE_SCIE_SUPPORTED
 #define BSP_MSTP_REG_FSP_IP_SCIE(channel)          R_SYSC_NS->MSTPCRA
 #define BSP_MSTP_BIT_FSP_IP_SCIE(channel)          (1U << (16U + channel))
 #define BSP_MSTP_DMY_FSP_IP_SCIE(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_SCIE0->RDR;              \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_SCIE1->RDR;              \
                break;                     \
            }                              \
            case 2:                        \
            {                              \
                R_SCIE2->RDR;              \
                break;                     \
            }                              \
            case 3:                        \
            {                              \
                R_SCIE3->RDR;              \
                break;                     \
            }                              \
            case 4:                        \
            {                              \
                R_SCIE4->RDR;              \
                break;                     \
            }                              \
            case 5:                        \
            {                              \
                R_SCIE5->RDR;              \
                break;                     \
            }                              \
            case 6:                        \
            {                              \
                R_SCIE6->RDR;              \
                break;                     \
            }                              \
            case 7:                        \
            {                              \
                R_SCIE7->RDR;              \
                break;                     \
            }                              \
            case 8:                        \
            {                              \
                R_SCIE8->RDR;              \
                break;                     \
            }                              \
            case 9:                        \
            {                              \
                R_SCIE9->RDR;              \
                break;                     \
            }                              \
            case 10:                       \
            {                              \
                R_SCIE10->RDR;             \
                break;                     \
            }                              \
            case 11:                       \
            {                              \
                R_SCIE11->RDR;             \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#endif

#define BSP_MSTP_REG_FSP_IP_IIC(channel)            *((1U >= channel) ? &R_SYSC_NS->MSTPCRB : &R_SYSC_S->MSTPCRG)
#define BSP_MSTP_BIT_FSP_IP_IIC(channel)            ((1U >= channel) ? (1U << (0U + channel)) : (1U << (1U)))
#define BSP_MSTP_DMY_FSP_IP_IIC(channel) \
    do                                   \
    {                                    \
        switch (channel)                 \
        {                                \
            case 0:                      \
            {                            \
                R_IIC0->ICCR1;           \
                break;                   \
            }                            \
            case 1:                      \
            {                            \
                R_IIC1->ICCR1;           \
                break;                   \
            }                            \
            case 2:                      \
            {                            \
                R_IIC2->ICCR1;           \
                break;                   \
            }                            \
            default:                     \
            {                            \
                bsp_assert_channel(0);   \
                break;                   \
            }                            \
        }                                \
    } while (0);

#define BSP_MSTP_REG_FSP_IP_SPI(channel)            *((2U >= channel) ? &R_SYSC_NS->MSTPCRB : &R_SYSC_S->MSTPCRG)
#define BSP_MSTP_BIT_FSP_IP_SPI(channel)            ((2U >= channel) ? (1U << (4U + channel)) : (1U << (2U)))
#define BSP_MSTP_DMY_FSP_IP_SPI(channel) \
    do                                   \
    {                                    \
        switch (channel)                 \
        {                                \
            case 0:                      \
            {                            \
                R_SPI0->SPCKD;           \
                break;                   \
            }                            \
            case 1:                      \
            {                            \
                R_SPI1->SPCKD;           \
                break;                   \
            }                            \
            case 2:                      \
            {                            \
                R_SPI2->SPCKD;           \
                break;                   \
            }                            \
            case 3:                      \
            {                            \
                R_SPI3->SPCKD;           \
                break;                   \
            }                            \
            default:                     \
            {                            \
                bsp_assert_channel(0);   \
                break;                   \
            }                            \
        }                                \
    } while (0);

#define BSP_MSTP_REG_FSP_IP_MTU3(channel)           R_SYSC_NS->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_MTU3(channel)           (1U)
#define BSP_MSTP_DMY_FSP_IP_MTU3(channel)           ((8U >= channel) ? R_MTU0->TCR : bsp_assert_channel(0))

#if (18 == BSP_FEATURE_GPT_CHANNEL)
 #define BSP_MSTP_REG_FSP_IP_GPT(channel)           *((13U >= channel) ? &R_SYSC_NS->MSTPCRC : &R_SYSC_S->MSTPCRG)
 #define BSP_MSTP_BIT_FSP_IP_GPT(channel)           ((6U >= channel) ? (1U << (1U)) :   \
                                                     ((13U >= channel) ? (1U << (2U)) : \
                                                      (1U << (3U))))
 #define BSP_MSTP_DMY_FSP_IP_GPT(channel)  \
    do {                                   \
        if (17U >= channel)                \
        {                                  \
            uint32_t group = channel / 7;  \
            switch (group)                 \
            {                              \
                case 0:                    \
                {                          \
                    R_GPT0->GTSTR;         \
                    break;                 \
                }                          \
                case 1:                    \
                {                          \
                    R_GPT7->GTSTR;         \
                    break;                 \
                }                          \
                case 2:                    \
                {                          \
                    R_GPT14->GTSTR;        \
                    break;                 \
                }                          \
                default:                   \
                {                          \
                    bsp_assert_channel(0); \
                    break;                 \
                }                          \
            }                              \
        }                                  \
        else                               \
        {                                  \
            bsp_assert_channel(0);         \
        }                                  \
    } while (0);
#elif (56 == BSP_FEATURE_GPT_CHANNEL)
 #define BSP_MSTP_REG_FSP_IP_GPT(channel)           *((51U >= channel) ? &R_SYSC_NS->MSTPCRC : &R_SYSC_S->MSTPCRG)
 #define BSP_MSTP_BIT_FSP_IP_GPT(channel)           ((4U >= channel) ? (1U << (1U)) :            \
                                                     ((9U >= channel) ? (1U << (2U)) :           \
                                                      ((14U >= channel) ? (1U << (16U)) :        \
                                                       ((19U >= channel) ? (1U << (17U)) :       \
                                                        ((24U >= channel) ? (1U << (18U)) :      \
                                                         ((29U >= channel) ? (1U << (19U)) :     \
                                                          ((34U >= channel) ? (1U << (20U)) :    \
                                                           ((39U >= channel) ? (1U << (21U)) :   \
                                                            ((44U >= channel) ? (1U << (22U)) :  \
                                                             ((51U >= channel) ? (1U << (23U)) : \
                                                              (1U << (3U))))))))))))
 #define BSP_MSTP_DMY_FSP_IP_GPT(channel)  \
    do {                                   \
        if (44U >= channel)                \
        {                                  \
            uint32_t group = channel / 5;  \
            switch (group)                 \
            {                              \
                case 0:                    \
                {                          \
                    R_GPT00_0->GTSTR;      \
                    break;                 \
                }                          \
                case 1:                    \
                {                          \
                    R_GPT01_0->GTSTR;      \
                    break;                 \
                }                          \
                case 2:                    \
                {                          \
                    R_GPT02_0->GTSTR;      \
                    break;                 \
                }                          \
                case 3:                    \
                {                          \
                    R_GPT03_0->GTSTR;      \
                    break;                 \
                }                          \
                case 4:                    \
                {                          \
                    R_GPT04_0->GTSTR;      \
                    break;                 \
                }                          \
                case 5:                    \
                {                          \
                    R_GPT05_0->GTSTR;      \
                    break;                 \
                }                          \
                case 6:                    \
                {                          \
                    R_GPT06_0->GTSTR;      \
                    break;                 \
                }                          \
                case 7:                    \
                {                          \
                    R_GPT07_0->GTSTR;      \
                    break;                 \
                }                          \
                case 8:                    \
                {                          \
                    R_GPT08_0->GTSTR;      \
                    break;                 \
                }                          \
                default:                   \
                {                          \
                    bsp_assert_channel(0); \
                    break;                 \
                }                          \
            }                              \
        }                                  \
        else if (51U >= channel)           \
        {                                  \
            R_GPT09_0->GTSTR;              \
        }                                  \
        else if (55U >= channel)           \
        {                                  \
            R_GPT10_0->GTSTR;              \
        }                                  \
        else                               \
        {                                  \
            bsp_assert_channel(0);         \
        }                                  \
    } while (0);

#endif
#if (1 == BSP_FEATURE_TFU_UNIT)
 #define BSP_MSTP_REG_FSP_IP_TFU(channel)           R_SYSC_NS->MSTPCRC
 #define BSP_MSTP_BIT_FSP_IP_TFU(channel)           (1U << (5U))
 #define BSP_MSTP_DMY_FSP_IP_TFU(channel)           ((0U == channel) ? R_TFU->TRGSTS : bsp_assert_channel(0))
#elif (2 == BSP_FEATURE_TFU_UNIT)
 #define BSP_MSTP_REG_FSP_IP_TFU(channel)           R_SYSC_NS->MSTPCRC
 #define BSP_MSTP_BIT_FSP_IP_TFU(channel)           ((0U == channel) ? (1U << (5U)) :   \
                                                     ((1U >= channel) ? (1U << (24U)) : \
                                                      bsp_assert_channel(0)))
 #if (0 == BSP_FEATURE_TFU_UNIT_NUMBER)
  #define BSP_MSTP_DMY_FSP_IP_TFU(channel)          ((0U == channel) ? R_TFU0->TRGSTS : bsp_assert_channel(0))
 #elif (1 == BSP_FEATURE_TFU_UNIT_NUMBER)
  #define BSP_MSTP_DMY_FSP_IP_TFU(channel)          ((1U == channel) ? R_TFU1->TRGSTS : bsp_assert_channel(0))
 #endif
#endif

#if (2 == BSP_FEATURE_ADC_UNIT)
 #define BSP_MSTP_REG_FSP_IP_ADC12(channel)         R_SYSC_NS->MSTPCRC
 #define BSP_MSTP_BIT_FSP_IP_ADC12(channel)         (1U << (6U + channel))
 #define BSP_MSTP_DMY_FSP_IP_ADC12(channel) \
    do                                      \
    {                                       \
        switch (channel)                    \
        {                                   \
            case 0:                         \
            {                               \
                R_ADC120->ADCSR;            \
                break;                      \
            }                               \
            case 1:                         \
            {                               \
                R_ADC121->ADCSR;            \
                break;                      \
            }                               \
            default:                        \
            {                               \
                bsp_assert_channel(0);      \
                break;                      \
            }                               \
        }                                   \
    } while (0);
#elif (3 == BSP_FEATURE_ADC_UNIT)
 #define BSP_MSTP_REG_FSP_IP_ADC12(channel)         R_SYSC_NS->MSTPCRC
 #define BSP_MSTP_BIT_FSP_IP_ADC12(channel)         ((1U >= channel) ? (1U << (6U + channel)) : (1U << (25U)))
 #define BSP_MSTP_DMY_FSP_IP_ADC12(channel) \
    do                                      \
    {                                       \
        switch (channel)                    \
        {                                   \
            case 0:                         \
            {                               \
                R_ADC120->ADCSR;            \
                break;                      \
            }                               \
            case 1:                         \
            {                               \
                R_ADC121->ADCSR;            \
                break;                      \
            }                               \
            case 2:                         \
            {                               \
                R_ADC122->ADCSR;            \
                break;                      \
            }                               \
            default:                        \
            {                               \
                bsp_assert_channel(0);      \
                break;                      \
            }                               \
        }                                   \
    } while (0);
#endif

#if (2 == BSP_FEATURE_DSMIF_UNIT)
 #define BSP_MSTP_REG_FSP_IP_DSMIF(channel)         R_SYSC_NS->MSTPCRD
 #define BSP_MSTP_BIT_FSP_IP_DSMIF(channel)         (1U << (0U + channel))
 #define BSP_MSTP_DMY_FSP_IP_DSMIF(channel) \
    do                                      \
    {                                       \
        switch (channel)                    \
        {                                   \
            case 0:                         \
            {                               \
                R_DSMIF0->DSSEICR;          \
                break;                      \
            }                               \
            case 1:                         \
            {                               \
                R_DSMIF1->DSSEICR;          \
                break;                      \
            }                               \
            default:                        \
            {                               \
                bsp_assert_channel(0);      \
                break;                      \
            }                               \
        }                                    \
    } while (0);
#elif (10 == BSP_FEATURE_DSMIF_UNIT)
 #define BSP_MSTP_REG_FSP_IP_DSMIF(channel)         R_SYSC_NS->MSTPCRD
 #define BSP_MSTP_BIT_FSP_IP_DSMIF(channel)         ((1U >= channel) ? (1U << (0U + channel)) : \
                                                     (1U << (14U + channel)))
 #define BSP_MSTP_DMY_FSP_IP_DSMIF(channel) \
    do                                      \
    {                                       \
        switch (channel)                    \
        {                                   \
            case 0:                         \
            {                               \
                R_DSMIF0->DSSEICR;          \
                break;                      \
            }                               \
            case 1:                         \
            {                               \
                R_DSMIF1->DSSEICR;          \
                break;                      \
            }                               \
            case 2:                         \
            {                               \
                R_DSMIF2->DSSEICR;          \
                break;                      \
            }                               \
            case 3:                         \
            {                               \
                R_DSMIF3->DSSEICR;          \
                break;                      \
            }                               \
            case 4:                         \
            {                               \
                R_DSMIF4->DSSEICR;          \
                break;                      \
            }                               \
            case 5:                         \
            {                               \
                R_DSMIF5->DSSEICR;          \
                break;                      \
            }                               \
            case 6:                         \
            {                               \
                R_DSMIF6->DSSEICR;          \
                break;                      \
            }                               \
            case 7:                         \
            {                               \
                R_DSMIF7->DSSEICR;          \
                break;                      \
            }                               \
            case 8:                         \
            {                               \
                R_DSMIF8->DSSEICR;          \
                break;                      \
            }                               \
            case 9:                         \
            {                               \
                R_DSMIF9->DSSEICR;          \
                break;                      \
            }                               \
            default:                        \
            {                               \
                bsp_assert_channel(0);      \
                break;                      \
            }                               \
        }                                   \
    } while (0);
#endif

#define BSP_MSTP_REG_FSP_IP_CMT(channel)            R_SYSC_NS->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_CMT(channel)            (1U << (2U + channel))
#define BSP_MSTP_DMY_FSP_IP_CMT(channel) \
    do                                   \
    {                                    \
        switch (channel)                 \
        {                                \
            case 0:                      \
            {                            \
                R_CMT->UNT[0].CMSTR0;    \
                break;                   \
            }                            \
            case 1:                      \
            {                            \
                R_CMT->UNT[1].CMSTR0;    \
                break;                   \
            }                            \
            case 2:                      \
            {                            \
                R_CMT->UNT[2].CMSTR0;    \
                break;                   \
            }                            \
            default:                     \
            {                            \
                bsp_assert_channel(0);   \
                break;                   \
            }                            \
        }                                \
    } while (0);

#define BSP_MSTP_REG_FSP_IP_CMTW(channel)           R_SYSC_NS->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_CMTW(channel)           (1U << (5U + channel))
#define BSP_MSTP_DMY_FSP_IP_CMTW(channel) \
    do                                    \
    {                                     \
        switch (channel)                  \
        {                                 \
            case 0:                       \
            {                             \
                R_CMTW0->CMWSTR;          \
                break;                    \
            }                             \
            case 1:                       \
            {                             \
                R_CMTW1->CMWSTR;          \
                break;                    \
            }                             \
            default:                      \
            {                             \
                bsp_assert_channel(0);    \
                break;                    \
            }                             \
        }                                 \
    } while (0);

#define BSP_MSTP_REG_FSP_IP_TSU(channel)            R_SYSC_NS->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_TSU(channel)            (1U << (7U))
#if (1 == BSP_FEATURE_TSU_VERSION)
 #define BSP_MSTP_DMY_FSP_IP_TSU(channel)           ((0U == channel) ? R_TSU->TSUSS : bsp_assert_channel(0))
#else
 #define BSP_MSTP_DMY_FSP_IP_TSU(channel)           ((0U == channel) ? R_TSU_B0->SSR : bsp_assert_channel(0))
#endif

#define BSP_MSTP_REG_FSP_IP_DOC(channel)            R_SYSC_NS->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_DOC(channel)            (1U << (8U))
#define BSP_MSTP_DMY_FSP_IP_DOC(channel)            ((0U == channel) ? R_DOC->DOCR : bsp_assert_channel(0))

#define BSP_MSTP_REG_FSP_IP_CRC(channel)            *((0U == channel) ? &R_SYSC_NS->MSTPCRD : &R_SYSC_S->MSTPCRG)
#define BSP_MSTP_BIT_FSP_IP_CRC(channel)            ((0U == channel) ? (1U << (9U)) : (1U << (4U)))
#define BSP_MSTP_DMY_FSP_IP_CRC(channel) \
    do                                   \
    {                                    \
        switch (channel)                 \
        {                                \
            case 0:                      \
            {                            \
                R_CRC0->CRCDIR;          \
                break;                   \
            }                            \
            case 1:                      \
            {                            \
                R_CRC1->CRCDIR;          \
                break;                   \
            }                            \
            default:                     \
            {                            \
                bsp_assert_channel(0);   \
                break;                   \
            }                            \
        }                                \
    } while (0);

#define BSP_MSTP_REG_FSP_IP_CANFD(channel)          R_SYSC_NS->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_CANFD(channel)          (1U << (10U))
#define BSP_MSTP_DMY_FSP_IP_CANFD(channel)          ((1U >= channel) ? R_CANFD->CFDGIPV : bsp_assert_channel(0))

#define BSP_MSTP_REG_FSP_IP_CKIO(channel)           R_SYSC_NS->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_CKIO(channel)           (1U << (11U))
#define BSP_MSTP_DMY_FSP_IP_CKIO(channel)           ((0U == channel) ? R_BSC->TOENR : bsp_assert_channel(0))

#if (1 == BSP_FEATURE_GMAC_UNIT)
 #define BSP_MSTP_REG_FSP_IP_GMAC(channel)          R_SYSC_NS->MSTPCRE
 #define BSP_MSTP_BIT_FSP_IP_GMAC(channel)          (1U)
 #define BSP_MSTP_DMY_FSP_IP_GMAC(channel)          ((0U == channel) ? R_GMAC->MAC_Configuration : \
                                                      bsp_assert_channel(0))

#elif (3 == BSP_FEATURE_GMAC_UNIT)
 #define BSP_MSTP_REG_FSP_IP_GMAC(channel)          R_SYSC_NS->MSTPCRE
 #define BSP_MSTP_BIT_FSP_IP_GMAC(channel)          ((0U == channel) ? (1U) : (1U << (15U + channel)))
 #define BSP_MSTP_DMY_FSP_IP_GMAC(channel)  \
    do                                      \
    {                                       \
        switch (channel)                    \
        {                                   \
            case 0:                         \
            {                               \
                R_GMAC0->MAC_Configuration; \
                break;                      \
            }                               \
            case 1:                         \
            {                               \
                R_GMAC1->MAC_Configuration; \
                break;                      \
            }                               \
            case 2:                         \
            {                               \
                R_GMAC2->MAC_Configuration; \
                break;                      \
            }                               \
            default:                        \
            {                               \
                bsp_assert_channel(0);      \
                break;                      \
            }                               \
        }                                   \
    } while (0);
#endif

#define BSP_MSTP_REG_FSP_IP_ETHSW(channel)          R_SYSC_NS->MSTPCRE
#define BSP_MSTP_BIT_FSP_IP_ETHSW(channel)          (1U << (1U))
#define BSP_MSTP_DMY_FSP_IP_ETHSW(channel)          ((0U == channel) ? R_ETHSW->REVISION : bsp_assert_channel(0))

#define BSP_MSTP_REG_FSP_IP_ESC(channel)            R_SYSC_NS->MSTPCRE
#define BSP_MSTP_BIT_FSP_IP_ESC(channel)            (1U << (2U))
#define BSP_MSTP_DMY_FSP_IP_ESC(channel)            ((0U == channel) ? R_ESC->TYPE : bsp_assert_channel(0))

#define BSP_MSTP_REG_FSP_IP_ETHSS(channel)          R_SYSC_NS->MSTPCRE
#define BSP_MSTP_BIT_FSP_IP_ETHSS(channel)          (1U << (3U))
#define BSP_MSTP_DMY_FSP_IP_ETHSS(channel)          ((0U == channel) ? R_ETHSS->PRCMD : bsp_assert_channel(0))

#define BSP_MSTP_REG_FSP_IP_USBHS(channel)          R_SYSC_NS->MSTPCRE
#define BSP_MSTP_BIT_FSP_IP_USBHS(channel)          (1U << (8U))
#define BSP_MSTP_DMY_FSP_IP_USBHS(channel)          ((0U == channel) ? R_USBHC->HCREVISION : bsp_assert_channel(0))

#if BSP_FEATURE_BSP_TRACE_CLOCK_SUPPORTED
 #define BSP_MSTP_REG_FSP_IP_TRACECLOCK(channel)    R_SYSC_S->MSTPCRF
 #define BSP_MSTP_BIT_FSP_IP_TRACECLOCK(channel)    (1U << (0U))
 #define BSP_MSTP_DMY_FSP_IP_TRACECLOCK(channel) /* No dummy read is required after module stop. */

#endif

#define BSP_MSTP_REG_FSP_IP_RTC(channel)            R_SYSC_S->MSTPCRG
#define BSP_MSTP_BIT_FSP_IP_RTC(channel)            (1U << (5U))
#define BSP_MSTP_DMY_FSP_IP_RTC(channel) /* After module stop release, the waiting process is performed by the driver, \
                                          * so this macro does not define a register for dummy read. */
#if (4 == BSP_FEATURE_CGC_CLMA_UNIT)
 #define BSP_MSTP_REG_FSP_IP_CLMA(channel)          R_SYSC_S->MSTPCRG
 #define BSP_MSTP_BIT_FSP_IP_CLMA(channel)          ((2U >= channel) ? (1U << (9U + channel)) : (1U << (8U)))
 #define BSP_MSTP_DMY_FSP_IP_CLMA(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_CLMA0->CTL0;             \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_CLMA1->CTL0;             \
                break;                     \
            }                              \
            case 2:                        \
            {                              \
                R_CLMA2->CTL0;             \
                break;                     \
            }                              \
            case 3:                        \
            {                              \
                R_CLMA3->CTL0;             \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#elif (7 == BSP_FEATURE_CGC_CLMA_UNIT)
 #define BSP_MSTP_REG_FSP_IP_CLMA(channel)          R_SYSC_S->MSTPCRG
 #define BSP_MSTP_BIT_FSP_IP_CLMA(channel)          ((5U >= channel) ? \
                                                     (1U << (9U + channel)) : (1U << (8U)))
 #define BSP_MSTP_DMY_FSP_IP_CLMA(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_CLMA0->CTL0;             \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_CLMA1->CTL0;             \
                break;                     \
            }                              \
            case 2:                        \
            {                              \
                R_CLMA2->CTL0;             \
                break;                     \
            }                              \
            case 3:                        \
            {                              \
                R_CLMA3->CTL0;             \
                break;                     \
            }                              \
            case 4:                        \
            {                              \
                R_CLMA4->CTL0;             \
                break;                     \
            }                              \
            case 5:                        \
            {                              \
                R_CLMA5->CTL0;             \
                break;                     \
            }                              \
            case 6:                        \
            {                              \
                R_CLMA6->CTL0;             \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#endif

#if BSP_FEATURE_BSP_SHOSTIF_SUPPORTED
 #define BSP_MSTP_REG_FSP_IP_SHOSTIF(channel)       R_SYSC_S->MSTPCRI
 #define BSP_MSTP_BIT_FSP_IP_SHOSTIF(channel)       (1U << (1U))
 #define BSP_MSTP_DMY_FSP_IP_SHOSTIF(channel)       ((0U == channel) ? R_SHOSTIF->CTRLR0 : bsp_assert_channel(0))
#endif

#if BSP_FEATURE_BSP_PHOSTIF_SUPPORTED
 #define BSP_MSTP_REG_FSP_IP_PHOSTIF(channel)       R_SYSC_S->MSTPCRI
 #define BSP_MSTP_BIT_FSP_IP_PHOSTIF(channel)       (1U << (0U))
 #define BSP_MSTP_DMY_FSP_IP_PHOSTIF(channel)       ((0U == channel) ? R_PHOSTIF->HIFBCC : bsp_assert_channel(0))
#endif

#if (2U == BSP_FEATURE_BSP_AFMT_UNIT)
 #define BSP_MSTP_REG_FSP_IP_AFMT(channel)          *((0U == channel) ? &R_SYSC_NS->MSTPCRJ : &R_SYSC_NS->MSTPCRK)
 #define BSP_MSTP_BIT_FSP_IP_AFMT(channel)          (1U << (0U))
 #define BSP_MSTP_DMY_FSP_IP_AFMT(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_AFMT0->ENC1RXDATA0;      \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_AFMT1->ENC1RXDATA0;      \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#elif (14U == BSP_FEATURE_BSP_AFMT_UNIT)
 #define BSP_MSTP_REG_FSP_IP_AFMT(channel)          *((7U >= channel) ? &R_SYSC_NS->MSTPCRJ : &R_SYSC_NS->MSTPCRK)
 #define BSP_MSTP_BIT_FSP_IP_AFMT(channel)          ((7U >= channel) ? (1U << (channel * 4U)) : \
                                                     (1U << ((channel - 8U) * 4U)))
 #define BSP_MSTP_DMY_FSP_IP_AFMT(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_AFMT0->ENC1RXDATA0;      \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_AFMT1->ENC1RXDATA0;      \
                break;                     \
            }                              \
            case 2:                        \
            {                              \
                R_AFMT2->ENC1RXDATA0;      \
                break;                     \
            }                              \
            case 3:                        \
            {                              \
                R_AFMT3->ENC1RXDATA0;      \
                break;                     \
            }                              \
            case 4:                        \
            {                              \
                R_AFMT4->ENC1RXDATA0;      \
                break;                     \
            }                              \
            case 5:                        \
            {                              \
                R_AFMT5->ENC1RXDATA0;      \
                break;                     \
            }                              \
            case 6:                        \
            {                              \
                R_AFMT6->ENC1RXDATA0;      \
                break;                     \
            }                              \
            case 7:                        \
            {                              \
                R_AFMT7->ENC1RXDATA0;      \
                break;                     \
            }                              \
            case 9:                        \
            {                              \
                R_AFMT9->ENC1RXDATA0;      \
                break;                     \
            }                              \
            case 10:                       \
            {                              \
                R_AFMT10->ENC1RXDATA0;     \
                break;                     \
            }                              \
            case 11:                       \
            {                              \
                R_AFMT11->ENC1RXDATA0;     \
                break;                     \
            }                              \
            case 12:                       \
            {                              \
                R_AFMT12->ENC1RXDATA0;     \
                break;                     \
            }                              \
            case 13:                       \
            {                              \
                R_AFMT13->ENC1RXDATA0;     \
                break;                     \
            }                              \
            case 14:                       \
            {                              \
                R_AFMT14->ENC1RXDATA0;     \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#endif

#if (2 == BSP_FEATURE_BSP_HDSL_UNIT)
 #define BSP_MSTP_REG_FSP_IP_HDSL(channel)          *((0U == channel) ? &R_SYSC_NS->MSTPCRJ : &R_SYSC_NS->MSTPCRK)
 #define BSP_MSTP_BIT_FSP_IP_HDSL(channel)          (1U << (1U))
 #define BSP_MSTP_DMY_FSP_IP_HDSL(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_HDSLD0->SYS_CTRL;        \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_HDSLD1->SYS_CTRL;        \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#elif (14 == BSP_FEATURE_BSP_HDSL_UNIT)
 #define BSP_MSTP_REG_FSP_IP_HDSL(channel)          *((7U >= channel) ? &R_SYSC_NS->MSTPCRJ : &R_SYSC_NS->MSTPCRK)
 #define BSP_MSTP_BIT_FSP_IP_HDSL(channel)          ((7U >= channel) ? (1U << ((channel * 4U) + 1U)) : \
                                                     (1U << (((channel - 8U) * 4U) + 1U)))
 #define BSP_MSTP_DMY_FSP_IP_HDSL(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_HDSLD0->SYS_CTRL;        \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_HDSLD1->SYS_CTRL;        \
                break;                     \
            }                              \
            case 2:                        \
            {                              \
                R_HDSLD2->SYS_CTRL;        \
                break;                     \
            }                              \
            case 3:                        \
            {                              \
                R_HDSLD3->SYS_CTRL;        \
                break;                     \
            }                              \
            case 4:                        \
            {                              \
                R_HDSLD4->SYS_CTRL;        \
                break;                     \
            }                              \
            case 5:                        \
            {                              \
                R_HDSLD5->SYS_CTRL;        \
                break;                     \
            }                              \
            case 6:                        \
            {                              \
                R_HDSLD6->SYS_CTRL;        \
                break;                     \
            }                              \
            case 7:                        \
            {                              \
                R_HDSLD7->SYS_CTRL;        \
                break;                     \
            }                              \
            case 9:                        \
            {                              \
                R_HDSLD9->SYS_CTRL;        \
                break;                     \
            }                              \
            case 10:                       \
            {                              \
                R_HDSLD10->SYS_CTRL;       \
                break;                     \
            }                              \
            case 11:                       \
            {                              \
                R_HDSLD11->SYS_CTRL;       \
                break;                     \
            }                              \
            case 12:                       \
            {                              \
                R_HDSLD12->SYS_CTRL;       \
                break;                     \
            }                              \
            case 13:                       \
            {                              \
                R_HDSLD13->SYS_CTRL;       \
                break;                     \
            }                              \
            case 14:                       \
            {                              \
                R_HDSLD14->SYS_CTRL;       \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#endif

#if (2 == BSP_FEATURE_BSP_BISS_UNIT)
 #define BSP_MSTP_REG_FSP_IP_BISS(channel)          *((0U == channel) ? &R_SYSC_NS->MSTPCRJ : &R_SYSC_NS->MSTPCRK)
 #define BSP_MSTP_BIT_FSP_IP_BISS(channel)          (1U << (2U))
 #define BSP_MSTP_DMY_FSP_IP_BISS(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_BISS0->SCDATA[0].L;      \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_BISS1->SCDATA[0].L;      \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#elif (14 == BSP_FEATURE_BSP_BISS_UNIT)
 #define BSP_MSTP_REG_FSP_IP_BISS(channel)          *((7U >= channel) ? &R_SYSC_NS->MSTPCRJ : &R_SYSC_NS->MSTPCRK)
 #define BSP_MSTP_BIT_FSP_IP_BISS(channel)          ((7U >= channel) ? (1U << ((channel * 4U) + 2U)) : \
                                                     (1U << (((channel - 8U) * 4U) + 2U)))
 #define BSP_MSTP_DMY_FSP_IP_BISS(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_BISS0->SCDATA[0].L;      \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_BISS1->SCDATA[0].L;      \
                break;                     \
            }                              \
            case 2:                        \
            {                              \
                R_BISS2->SCDATA[0].L;      \
                break;                     \
            }                              \
            case 3:                        \
            {                              \
                R_BISS3->SCDATA[0].L;      \
                break;                     \
            }                              \
            case 4:                        \
            {                              \
                R_BISS4->SCDATA[0].L;      \
                break;                     \
            }                              \
            case 5:                        \
            {                              \
                R_BISS5->SCDATA[0].L;      \
                break;                     \
            }                              \
            case 6:                        \
            {                              \
                R_BISS6->SCDATA[0].L;      \
                break;                     \
            }                              \
            case 7:                        \
            {                              \
                R_BISS7->SCDATA[0].L;      \
                break;                     \
            }                              \
            case 9:                        \
            {                              \
                R_BISS9->SCDATA[0].L;      \
                break;                     \
            }                              \
            case 10:                       \
            {                              \
                R_BISS10->SCDATA[0].L;     \
                break;                     \
            }                              \
            case 11:                       \
            {                              \
                R_BISS11->SCDATA[0].L;     \
                break;                     \
            }                              \
            case 12:                       \
            {                              \
                R_BISS12->SCDATA[0].L;     \
                break;                     \
            }                              \
            case 13:                       \
            {                              \
                R_BISS13->SCDATA[0].L;     \
                break;                     \
            }                              \
            case 14:                       \
            {                              \
                R_BISS14->SCDATA[0].L;     \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#endif

#if (2 == BSP_FEATURE_BSP_ENDAT_UNIT)
 #define BSP_MSTP_REG_FSP_IP_ENDAT(channel)         *((0U == channel) ? &R_SYSC_NS->MSTPCRJ : &R_SYSC_NS->MSTPCRK)
 #define BSP_MSTP_BIT_FSP_IP_ENDAT(channel)         (1U << (3U))
 #define BSP_MSTP_DMY_FSP_IP_ENDAT(channel) \
    do                                      \
    {                                       \
        switch (channel)                    \
        {                                   \
            case 0:                         \
            {                               \
                R_ENDAT0->SEND;             \
                break;                      \
            }                               \
            case 1:                         \
            {                               \
                R_ENDAT1->SEND;             \
                break;                      \
            }                               \
            default:                        \
            {                               \
                bsp_assert_channel(0);      \
                break;                      \
            }                               \
        }                                   \
    } while (0);
#elif (14 == BSP_FEATURE_BSP_ENDAT_UNIT)
 #define BSP_MSTP_REG_FSP_IP_ENDAT(channel)         *((7U >= channel) ? &R_SYSC_NS->MSTPCRJ : &R_SYSC_NS->MSTPCRK)
 #define BSP_MSTP_BIT_FSP_IP_ENDAT(channel)         ((7U >= channel) ? (1U << ((channel * 4U) + 3U)) : \
                                                     (1U << (((channel - 8U) * 4U) + 3U)))
 #define BSP_MSTP_DMY_FSP_IP_ENDAT(channel) \
    do                                      \
    {                                       \
        switch (channel)                    \
        {                                   \
            case 0:                         \
            {                               \
                R_ENDAT0->SEND;             \
                break;                      \
            }                               \
            case 1:                         \
            {                               \
                R_ENDAT1->SEND;             \
                break;                      \
            }                               \
            case 2:                         \
            {                               \
                R_ENDAT2->SEND;             \
                break;                      \
            }                               \
            case 3:                         \
            {                               \
                R_ENDAT3->SEND;             \
                break;                      \
            }                               \
            case 4:                         \
            {                               \
                R_ENDAT4->SEND;             \
                break;                      \
            }                               \
            case 5:                         \
            {                               \
                R_ENDAT5->SEND;             \
                break;                      \
            }                               \
            case 6:                         \
            {                               \
                R_ENDAT6->SEND;             \
                break;                      \
            }                               \
            case 7:                         \
            {                               \
                R_ENDAT7->SEND;             \
                break;                      \
            }                               \
            case 9:                         \
            {                               \
                R_ENDAT9->SEND;             \
                break;                      \
            }                               \
            case 10:                        \
            {                               \
                R_ENDAT10->SEND;            \
                break;                      \
            }                               \
            case 11:                        \
            {                               \
                R_ENDAT11->SEND;            \
                break;                      \
            }                               \
            case 12:                        \
            {                               \
                R_ENDAT12->SEND;            \
                break;                      \
            }                               \
            case 13:                        \
            {                               \
                R_ENDAT13->SEND;            \
                break;                      \
            }                               \
            case 14:                        \
            {                               \
                R_ENDAT14->SEND;            \
                break;                      \
            }                               \
            default:                        \
            {                               \
                bsp_assert_channel(0);      \
                break;                      \
            }                               \
        }                                   \
    } while (0);
#endif

#if BSP_FEATURE_BSP_ENCOUT_SUPPORTED
 #define BSP_MSTP_REG_FSP_IP_ENCOUT(channel)        R_SYSC_NS->MSTPCRL
 #define BSP_MSTP_BIT_FSP_IP_ENCOUT(channel)        (1U << (0U))
 #define BSP_MSTP_DMY_FSP_IP_ENCOUT(channel)        ((0U == channel) ? R_ENCOUT->CTL : bsp_assert_channel(0))
#endif

#if BSP_FEATURE_BSP_DDRSS_SUPPORTED
 #define BSP_MSTP_REG_FSP_IP_DDRSS(channel)         R_SYSC_NS->MSTPCRM
 #define BSP_MSTP_BIT_FSP_IP_DDRSS(channel)         (1U << (0U))
 #define BSP_MSTP_DMY_FSP_IP_DDRSS(channel)         ((0U == channel) ? R_DDRSS->DDR_MEMC_DENALI_CTL_00 : \
                                                      bsp_assert_channel(0))
#endif

#if BSP_FEATURE_BSP_LCDC_SUPPORTED
 #define BSP_MSTP_REG_FSP_IP_LCDC(channel)          R_SYSC_NS->MSTPCRM
 #define BSP_MSTP_BIT_FSP_IP_LCDC(channel)          (1U << (4U))
 #define BSP_MSTP_DMY_FSP_IP_LCDC(channel) /* After module stop release, the waiting process is performed by the driver, \
                                            * so this macro does not define a register for dummy read. */

#endif

#if BSP_FEATURE_BSP_PCIE_SUPPORTED
 #define BSP_MSTP_REG_FSP_IP_PCIE(channel)          R_SYSC_NS->MSTPCRM
 #define BSP_MSTP_BIT_FSP_IP_PCIE(channel)          (1U << (8U))
 #define BSP_MSTP_DMY_FSP_IP_PCIE(channel)          ((0U == channel) ? R_PCIE_LNK->PCIE_LINKMODE : \
                                                      bsp_assert_channel(0))
#endif

#if BSP_FEATURE_BSP_SDHI_SUPPORTED
 #define BSP_MSTP_REG_FSP_IP_SDHI(channel)          R_SYSC_NS->MSTPCRM
 #define BSP_MSTP_BIT_FSP_IP_SDHI(channel)          (1U << (12U + channel))
 #define BSP_MSTP_DMY_FSP_IP_SDHI(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_SDHI0->SD_CMD;           \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_SDHI1->SD_CMD;           \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#endif

#if BSP_FEATURE_BSP_MSTP_CR52_CPU1_HAS_MSTPCRH
 #define BSP_MSTP_REG_FSP_IP_CPU1(channel)          R_SYSC_S->MSTPCRH
 #define BSP_MSTP_BIT_FSP_IP_CPU1(channel)          (1U << (1U))
 #define BSP_MSTP_DMY_FSP_IP_CPU1(channel) /* No dummy read is required after module stop. */

#endif

#if BSP_FEATURE_BSP_MSTP_CR52_HAS_MSTPCRN
 #define BSP_MSTP_REG_FSP_IP_CR52(channel)          R_SYSC_S->MSTPCRN
 #define BSP_MSTP_BIT_FSP_IP_CR52(channel)          (1U << (channel))
 #define BSP_MSTP_DMY_FSP_IP_CR52(channel) \
    do                                     \
    {                                      \
        switch (channel)                   \
        {                                  \
            case 0:                        \
            {                              \
                R_TCMAW->CPU0WAIT;         \
                break;                     \
            }                              \
            case 1:                        \
            {                              \
                R_TCMAW->CPU1WAIT;         \
                break;                     \
            }                              \
            default:                       \
            {                              \
                bsp_assert_channel(0);     \
                break;                     \
            }                              \
        }                                  \
    } while (0);
#endif

#if BSP_FEATURE_BSP_MSTP_CA55_HAS_MSTPCRN
 #define BSP_MSTP_REG_FSP_IP_CA55(channel)          R_SYSC_S->MSTPCRN
 #define BSP_MSTP_BIT_FSP_IP_CA55(channel)          (1U << (channel + 2U))
 #define BSP_MSTP_DMY_FSP_IP_CA55(channel)          ((3U >= channel) ? R_CA55->RVBA[channel].L : \
                                                     bsp_assert_channel(0))
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

static inline fsp_err_t bsp_assert_channel(bool cond);

/***********************************************************************************************************************
 * Private functions
 **********************************************************************************************************************/

static inline fsp_err_t bsp_assert_channel (bool cond)
{
    assert(cond);

    return cond ? FSP_SUCCESS : FSP_ERR_ASSERTION;
}

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
