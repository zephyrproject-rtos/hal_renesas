/*
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_i3c.h"
#include "r_i3c_cfg.h"
#include "rp_i3c.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Bitfield definitions for Command Descriptor fields. */
#define R_I3C0_DATBAS0_DVDYAD_Parity_Msk             (1U << 23)

/*******************************************************************************************************************//**
 * Configure an entry in the master device table. This function is called in master mode in order to configure
 * the devices on the I3C bus. It may also be called in slave mode when the slave receives the DEFSVLS command.
 *
 * @retval FSP_SUCCESS                    Open successful.
 * @retval FSP_ERR_ASSERTION              An argument was NULL.
 * @retval FSP_ERR_NOT_OPEN               This instance has not been opened yet.
 * @retval FSP_ERR_UNSUPPORTED            Mastership requests must be rejected is slave support is disabled.
 **********************************************************************************************************************/
fsp_err_t R_I3C_MasterDeviceTableGet (i3c_ctrl_t * const                   p_api_ctrl,
                                      uint32_t                             device_index,
                                      i3c_device_table_cfg_t * const p_device_table_cfg)
{
#if I3C_CFG_MASTER_SUPPORT
    i3c_instance_ctrl_t * p_ctrl = (i3c_instance_ctrl_t *) p_api_ctrl;

    uint32_t volatile * p_datbasn_reg = NULL;
    uint32_t            datbasn       = 0;

    if (I3C_DEVICE_INDEX_EXTENDED_DEVICE == device_index)
    {
        p_datbasn_reg = &p_ctrl->p_reg->EXDATBAS;
    }
    else
    {
        /* Compute the address of the DATBASn register. */
        uint32_t address_offset = (uint32_t) (&p_ctrl->p_reg->DATBAS1 - &p_ctrl->p_reg->DATBAS0);
        p_datbasn_reg = (uint32_t *) (&p_ctrl->p_reg->DATBAS0 + device_index * address_offset);
    }

    datbasn = *((uint32_t *)p_datbasn_reg);

    if (I3C_DEVICE_INDEX_EXTENDED_DEVICE != device_index)
    {
        p_device_table_cfg->ibi_payload = (uint8_t) ((datbasn & R_I3C0_DATBAS0_DVIBIPL_Msk) >> R_I3C0_DATBAS0_DVIBIPL_Pos);
        p_device_table_cfg->ibi_accept = (uint8_t) !((datbasn & R_I3C0_DATBAS0_DVSIRRJ_Msk) >> R_I3C0_DATBAS0_DVSIRRJ_Pos);
        p_device_table_cfg->master_request_accept = (uint8_t) !((datbasn & R_I3C0_DATBAS0_DVMRRJ_Msk) >> R_I3C0_DATBAS0_DVMRRJ_Pos);
    }

    p_device_table_cfg->static_address = (uint8_t) (datbasn & R_I3C0_DATBAS0_DVSTAD_Msk) >> R_I3C0_DATBAS0_DVSTAD_Pos;
    p_device_table_cfg->dynamic_address = (uint8_t) ((datbasn & R_I3C0_DATBAS0_DVDYAD_Msk & (~R_I3C0_DATBAS0_DVDYAD_Parity_Msk)) >> R_I3C0_DATBAS0_DVDYAD_Pos);

    uint32_t dvtyp = (datbasn & R_I3C0_DATBAS0_DVTYP_Msk) >> R_I3C0_DATBAS0_DVTYP_Pos;

    if (dvtyp)
    {
        p_device_table_cfg->device_protocol = I3C_DEVICE_PROTOCOL_I2C;
    }
    else
    {
        p_device_table_cfg->device_protocol = I3C_DEVICE_PROTOCOL_I3C;
    }

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(device_index);
    FSP_PARAMETER_NOT_USED(p_device_table_cfg);

    return FSP_ERR_UNSUPPORTED;
#endif
}

fsp_err_t R_I3C_MasterDeviceTableReset (i3c_ctrl_t * const                   p_api_ctrl,
                                      uint32_t                             device_index)
{
#if I3C_CFG_MASTER_SUPPORT
    i3c_instance_ctrl_t * p_ctrl = (i3c_instance_ctrl_t *) p_api_ctrl;

    uint32_t volatile * p_datbasn_reg = NULL;

    if (I3C_DEVICE_INDEX_EXTENDED_DEVICE == device_index)
    {
        p_datbasn_reg = &p_ctrl->p_reg->EXDATBAS;
    }
    else
    {
        /* Compute the address of the DATBASn register. */
        uint32_t address_offset = (uint32_t) (&p_ctrl->p_reg->DATBAS1 - &p_ctrl->p_reg->DATBAS0);
        p_datbasn_reg = (uint32_t *) (&p_ctrl->p_reg->DATBAS0 + device_index * address_offset);
    }

    /* Reset the DATBASn register. */
    *p_datbasn_reg = (uint32_t) 0U;

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(device_index);

    return FSP_ERR_UNSUPPORTED;
#endif
}
