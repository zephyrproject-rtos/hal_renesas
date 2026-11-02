/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_I3C_ENDIAN_OVERRIDE_H
#define BSP_I3C_ENDIAN_OVERRIDE_H

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_OVERRIDE_I3C_SLAVE_INFO_T

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Device characteristics that define the I3C capabilities of a slave. */
typedef struct s_i3c_slave_info
{
    uint8_t pid[6];                    ///< Provisional ID.

    union
    {
        uint8_t bcr;                   ///< Bus Characteristics Register.

        struct
        {
#if defined(__BIG) && defined(__GNUC__)

            /**
             * Device Role:
             * - 0: I3C Slave.
             * - 1: I3C Master (Device acting as the main master will set this to 1).
             * - 2: Reserved.
             * - 3: Reserved.
             */
            uint8_t device_role : 2;

            /**
             * HDR Capable:
             * - 0: Not Capable.
             * - 1: Capable.
             */
            uint8_t hdr_capable : 1;

            /**
             * Bridge Identifier:
             * - 0: Not a Bridge Device.
             * - 1: Is a Bridge Device.
             */
            uint8_t bridge_identifier : 1;

            /**
             * Offline Capable:
             * - 0: Not Capable.
             * - 1: Capable.
             */
            uint8_t offline_capable : 1;

            /**
             * IBI Payload:
             * - 0: No data byte follows the accepted IBI
             * - 1: Mandatory one or more data bytes follow the accepted IBI.
             */
            uint8_t ibi_payload : 1;

            /**
             * IBI Request Capable
             * - 0: Not Capable.
             * - 1: Capable.
             */
            uint8_t ibi_request_capable : 1;

            /**
             * Max Data Speed Limitation:
             * - No limitation.
             * - Limitation (If this is set, the master shall get the Max Data Speed using the GETMXDS command).
             */
            uint8_t max_data_speed_limitation : 1;
#else

            /**
             * Max Data Speed Limitation:
             * - No limitation.
             * - Limitation (If this is set, the master shall get the Max Data Speed using the GETMXDS command).
             */
            uint8_t max_data_speed_limitation : 1;

            /**
             * IBI Request Capable
             * - 0: Not Capable.
             * - 1: Capable.
             */
            uint8_t ibi_request_capable : 1;

            /**
             * IBI Payload:
             * - 0: No data byte follows the accepted IBI
             * - 1: Mandatory one or more data bytes follow the accepted IBI.
             */
            uint8_t ibi_payload : 1;

            /**
             * Offline Capable:
             * - 0: Not Capable.
             * - 1: Capable.
             */
            uint8_t offline_capable : 1;

            /**
             * Bridge Identifier:
             * - 0: Not a Bridge Device.
             * - 1: Is a Bridge Device.
             */
            uint8_t bridge_identifier : 1;

            /**
             * HDR Capable:
             * - 0: Not Capable.
             * - 1: Capable.
             */
            uint8_t hdr_capable : 1;

            /**
             * Device Role:
             * - 0: I3C Slave.
             * - 1: I3C Master (Device acting as the main master will set this to 1).
             * - 2: Reserved.
             * - 3: Reserved.
             */
            uint8_t device_role : 2;
#endif
        } bcr_b;
    } bcr_u;

    uint8_t dcr;                       ///< Device Characteristics Register.
} i3c_slave_info_t;

#endif
