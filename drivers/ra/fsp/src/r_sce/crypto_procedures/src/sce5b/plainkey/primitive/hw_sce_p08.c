/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 05.10.2020 1.00        First Release.
 *         : 02.12.2020 1.01        Added new functions such as the Brainpool curve.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "r_sce_if.h"
#include "hw_sce_ra_private.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Imported global variables and functions (from other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/

fsp_err_t HW_SCE_GenerateAes256RandomKeyIndexSub(uint32_t *OutData_KeyIndex)
{
    uint32_t iLoop    = 0U;
    uint32_t iLoop1   = 0U;
    uint32_t iLoop2   = 0U;
    int32_t  jLoop    = 0U;
    uint32_t kLoop    = 0U;
    uint32_t oLoop    = 0U;
    uint32_t oLoop1   = 0U;
    uint32_t oLoop2   = 0U;
    uint32_t dummy    = 0U;
    uint32_t KEY_ADR  = 0U;
    uint32_t OFS_ADR  = 0U;
    uint32_t MAX_CNT2 = 0U;
    (void)iLoop;
    (void)iLoop1;
    (void)iLoop2;
    (void)jLoop;
    (void)kLoop;
    (void)oLoop;
    (void)oLoop1;
    (void)oLoop2;
    (void)dummy;
    (void)KEY_ADR;
    (void)OFS_ADR;
    (void)MAX_CNT2;
    if (0x0U != (SCE->REG_1BCH & 0x1fU))
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }
    SCE->REG_84H = 0x00000801U;
    SCE->REG_108H = 0x00000000U;
    HW_SCE_func100(0x41e2219fU, 0xdee8e98aU, 0x716722d1U, 0x871e6277U);
    HW_SCE_func103();
    SCE->REG_104H = 0x00000051U;
    SCE->REG_A4H = 0x01000e84U;
    /* WAIT_LOOP */
    while (1U != SCE->REG_104H_b.B31)
    {
        /* waiting */
    }
    SCE->REG_100H = change_endian_long(0x00000000U);
    SCE->REG_E0H = 0x80010000U;
    SCE->REG_00H = 0x00008107U;
    /* WAIT_LOOP */
    while (0U != SCE->REG_00H_b.B25)
    {
        /* waiting */
    }
    SCE->REG_1CH = 0x00001800U;
    SCE->REG_00H = 0x0000010fU;
    /* WAIT_LOOP */
    while (0U != SCE->REG_00H_b.B25)
    {
        /* waiting */
    }
    SCE->REG_1CH = 0x00001800U;
    SCE->REG_ECH = 0x000008c6U;
    SCE->REG_ECH = 0x00003c06U;
    SCE->REG_ECH = 0x000034a0U;
    SCE->REG_104H = 0x00000058U;
    SCE->REG_E0H = 0x800100c0U;
    /* WAIT_LOOP */
    while (1U != SCE->REG_104H_b.B31)
    {
        /* waiting */
    }
    SCE->REG_100H = change_endian_long(0x00000008U);
    HW_SCE_func101(0xf65b5673U, 0x358a875eU, 0x89e67e8eU, 0x8bf1961eU);
    HW_SCE_func043();
    HW_SCE_func100(0xf32c623fU, 0xf5b53008U, 0x0502e7bcU, 0xf4d0ac1eU);
    SCE->REG_ECH = 0x0000b4a0U;
    SCE->REG_ECH = 0x00000007U;
    HW_SCE_func044();
    HW_SCE_func100(0xfc4af10eU, 0xfc10a41eU, 0x1fdefea3U, 0x54f31369U);
    SCE->REG_ECH = 0x0000b4c0U;
    SCE->REG_ECH = 0x00000004U;
    SCE->REG_ECH = 0x00003ce6U;
    HW_SCE_func103();
    HW_SCE_func100(0xcb9657f5U, 0x59de8f06U, 0x16039595U, 0x78a87d3aU);
    SCE->REG_104H = 0x00000051U;
    SCE->REG_A4H = 0x01000e84U;
    /* WAIT_LOOP */
    while (1U != SCE->REG_104H_b.B31)
    {
        /* waiting */
    }
    SCE->REG_100H = change_endian_long(0x00000000U);
    SCE->REG_E0H = 0x80080000U;
    SCE->REG_00H = 0x00008113U;
    /* WAIT_LOOP */
    while (0U != SCE->REG_00H_b.B25)
    {
        /* waiting */
    }
    SCE->REG_1CH = 0x00001800U;
    HW_SCE_func103();
    HW_SCE_func100(0x5c80cb8eU, 0xf607f9afU, 0x2a8c54b6U, 0x6e0254e9U);
    SCE->REG_104H = 0x00000051U;
    SCE->REG_A4H = 0x01000e84U;
    /* WAIT_LOOP */
    while (1U != SCE->REG_104H_b.B31)
    {
        /* waiting */
    }
    SCE->REG_100H = change_endian_long(0x00000000U);
    SCE->REG_00H = 0x00008113U;
    /* WAIT_LOOP */
    while (0U != SCE->REG_00H_b.B25)
    {
        /* waiting */
    }
    SCE->REG_1CH = 0x00001800U;
    SCE->REG_B0H = 0x00000100U;
    SCE->REG_A4H = 0x02e4a6bfU;
    SCE->REG_E0H = 0x81080000U;
    SCE->REG_00H = 0x00001823U;
    /* WAIT_LOOP */
    while (0U != SCE->REG_00H_b.B25)
    {
        /* waiting */
    }
    SCE->REG_1CH = 0x00001800U;
    SCE->REG_104H = 0x00000351U;
    SCE->REG_A4H = 0x000029cdU;
    /* WAIT_LOOP */
    while (1U != SCE->REG_104H_b.B31)
    {
        /* waiting */
    }
    SCE->REG_100H = change_endian_long(0x00000000U);
    SCE->REG_100H = change_endian_long(0x00000000U);
    SCE->REG_100H = change_endian_long(0x00000000U);
    SCE->REG_100H = change_endian_long(0x00000002U);
    SCE->REG_04H = 0x00000132U;
    /* WAIT_LOOP */
    while (1U != SCE->REG_04H_b.B30)
    {
        /* waiting */
    }
    OutData_KeyIndex[1] = SCE->REG_100H;
    OutData_KeyIndex[2] = SCE->REG_100H;
    OutData_KeyIndex[3] = SCE->REG_100H;
    OutData_KeyIndex[4] = SCE->REG_100H;
    /* WAIT_LOOP */
    while (1U != SCE->REG_04H_b.B30)
    {
        /* waiting */
    }
    OutData_KeyIndex[5] = SCE->REG_100H;
    OutData_KeyIndex[6] = SCE->REG_100H;
    OutData_KeyIndex[7] = SCE->REG_100H;
    OutData_KeyIndex[8] = SCE->REG_100H;
    /* WAIT_LOOP */
    while (1U != SCE->REG_04H_b.B30)
    {
        /* waiting */
    }
    OutData_KeyIndex[9] = SCE->REG_100H;
    OutData_KeyIndex[10] = SCE->REG_100H;
    OutData_KeyIndex[11] = SCE->REG_100H;
    OutData_KeyIndex[12] = SCE->REG_100H;
    HW_SCE_func100(0xc6805bfeU, 0xfc4fa925U, 0x19827e83U, 0xed1f6d56U);
    SCE->REG_ECH = 0x0000b4c0U;
    SCE->REG_ECH = 0x00000004U;
    SCE->REG_ECH = 0x000038e6U;
    SCE->REG_ECH = 0x000008c6U;
    SCE->REG_E0H = 0x81810006U;
    SCE->REG_04H = 0x00000606U;
    /* WAIT_LOOP */
    while (1U != SCE->REG_04H_b.B30)
    {
        /* waiting */
    }
    OutData_KeyIndex[0] = SCE->REG_100H;
    HW_SCE_func102(0x32421bb5U, 0x68279c58U, 0x5db6772dU, 0xe2a185c7U);
    SCE->REG_1BCH = 0x00000040U;
    /* WAIT_LOOP */
    while (0U != SCE->REG_18H_b.B12)
    {
        /* waiting */
    }
    return FSP_SUCCESS;
}

/***********************************************************************************************************************
End of function ./input_dir/RA6T_Boot/200821/HW_SCE/Cryptographic/HW_SCE_p08.prc
***********************************************************************************************************************/
