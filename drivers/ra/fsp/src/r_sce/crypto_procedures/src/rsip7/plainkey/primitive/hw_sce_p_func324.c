/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_ra_private.h"

void HW_SCE_p_func324 (void)
{
    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    WR1_PROG(REG_1400H, 0x00030005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x03430005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1404H, 0x1dc80000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    WR1_PROG(REG_1400H, 0x00030005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x03430005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1014H, 0x00000878U);
    WR1_PROG(REG_1018H, 0x00000fd8U);
    WR1_PROG(REG_1020H, 0x00000dc0U);

    WR1_PROG(REG_1004H, 0x4141000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_143CH, 0x00a10000U);

    HW_SCE_p_func100(0x9ddddac3U, 0x31cc798dU, 0xd2e56d96U, 0x2a485ddfU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0x62771655U, 0x95d937b1U, 0x712329d0U, 0xbbb2a5d2U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000878U);

            WR1_PROG(REG_1004H, 0x4141000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            HW_SCE_p_func101(0x0b752807U, 0x596abd4bU, 0x8facf44eU, 0xb1e99db8U);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000878U);

            WR1_PROG(REG_1004H, 0x41410009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            HW_SCE_p_func101(0xccbb9198U, 0x23d0be03U, 0x16d979c7U, 0x668b5e65U);
        }
    }
    else
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0xb524ec4aU, 0xac968864U, 0x5956f30dU, 0xad25b580U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000fd8U);
            WR1_PROG(REG_1018H, 0x00000878U);
            WR1_PROG(REG_1020H, 0x00000878U);

            WR1_PROG(REG_1004H, 0x4141000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            HW_SCE_p_func101(0x3b625de4U, 0x4720371bU, 0x61a93e89U, 0xc144b6e2U);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000878U);

            WR1_PROG(REG_1004H, 0x41410009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            HW_SCE_p_func101(0x527fb058U, 0x52e081d0U, 0xf5fc7b67U, 0x21df4a79U);
        }
    }

    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    WR1_PROG(REG_1400H, 0x00c00005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x00c90005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
