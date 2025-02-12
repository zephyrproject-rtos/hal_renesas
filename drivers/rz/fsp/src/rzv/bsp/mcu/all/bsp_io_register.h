/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IO_REGISTER_H
#define BSP_IO_REGISTER_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_IO_NONMASK_ACCESS_32    (0xFFFFFFFFUL)
#define BSP_IO_NONMASK_ACCESS_16    (0xFFFFUL)
#define BSP_IO_NONMASK_ACCESS_8     (0xFFUL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * IO register 8-bit write
 *
 * @param[in]   * ioreg            IO register for writing
 * @param[in]   write_value        Write value for the IO register
 * @param[in]   shift              The number of left shifts to the target bit
 * @param[in]   mask               Mask value for the IO register (Target bit : "1")
 *********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IoRegWrite8 (volatile uint8_t * ioreg, uint8_t write_value, uint8_t shift, uint8_t mask)
{
    uint8_t reg_value;

    if (BSP_IO_NONMASK_ACCESS_8 != mask)
    {
        /* Read from register */
        reg_value = *ioreg;

        /* Modify value */
        reg_value = (uint8_t) ((reg_value & (~mask)) | (write_value << shift));
    }
    else
    {
        reg_value = write_value << shift;
    }

    /* Write to register */
    *ioreg = reg_value;
}

/**********************************************************************************************************************
 * IO register 8-bit read
 *
 * @param[in]   * ioreg            IO register for reading
 * @param[in]   shift              The number of right shifts to the target bit
 * @param[in]   mask               Mask value for the IO register (Target bit : "1")
 *
 * @retval   value         Register value
 *********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_IoRegRead8 (volatile uint8_t * ioreg, uint8_t shift, uint8_t mask)
{
    uint8_t reg_value;

    /* Read from register */
    reg_value = *ioreg;

    /* Clear other bit and Bit shift */
    reg_value = (uint8_t) ((reg_value & mask) >> shift);

    return reg_value;
}

/**********************************************************************************************************************
 * IO register 16-bit write
 *
 * @param[in]   * ioreg            IO register for writing
 * @param[in]   write_value        Write value for the IO register
 * @param[in]   shift              The number of left shifts to the target bit
 * @param[in]   mask               Mask value for the IO register (Target bit : "1")
 *********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IoRegWrite16 (volatile uint16_t * ioreg, uint16_t write_value, uint16_t shift, uint16_t mask)
{
    uint16_t reg_value;

    if (BSP_IO_NONMASK_ACCESS_16 != mask)
    {
        /* Read from register */
        reg_value = *ioreg;

        /* Modify value */
        reg_value = (uint16_t) ((reg_value & (~mask)) | (write_value << shift));
    }
    else
    {
        reg_value = write_value << shift;
    }

    /* Write to register */
    *ioreg = reg_value;
}

/**********************************************************************************************************************
 * IO register 16-bit read
 *
 * @param[in]   * ioreg            IO register for reading
 * @param[in]   shift              The number of right shifts to the target bit
 * @param[in]   mask               Mask value for the IO register (Target bit : "1")
 *
 * @retval   value         Register value
 *********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_IoRegRead16 (volatile uint16_t * ioreg, uint16_t shift, uint16_t mask)
{
    uint16_t reg_value;

    /* Read from register */
    reg_value = *ioreg;

    /* Clear other bit and Bit shift */
    reg_value = (uint16_t) ((reg_value & mask) >> shift);

    return reg_value;
}

/**********************************************************************************************************************
 * IO register 32-bit write
 *
 * @param[in]   * ioreg            IO register for writing
 * @param[in]   write_value        Write value for the IO register
 * @param[in]   shift              The number of left shifts to the target bit
 * @param[in]   mask               Mask value for the IO register (Target bit : "1")
 *********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IoRegWrite32 (volatile uint32_t * ioreg, uint32_t write_value, uint32_t shift, uint32_t mask)
{
    uint32_t reg_value;

    if (BSP_IO_NONMASK_ACCESS_32 != mask)
    {
        /* Read from register */
        reg_value = *ioreg;

        /* Modify value */
        reg_value = (uint32_t) ((reg_value & (~mask)) | (write_value << shift));
    }
    else
    {
        reg_value = write_value << shift;
    }

    /* Write to register */
    *ioreg = reg_value;
}

/**********************************************************************************************************************
 * IO register 32-bit read
 *
 * @param[in]   * ioreg            IO register for reading
 * @param[in]   shift              The number of right shifts to the target bit
 * @param[in]   mask               Mask value for the IO register (Target bit : "1")
 *
 * @retval   value         Register value
 *********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_IoRegRead32 (volatile uint32_t * ioreg, uint32_t shift, uint32_t mask)
{
    uint32_t reg_value;

    /* Read from register */
    reg_value = *ioreg;

    /* Clear other bit and Bit shift */
    reg_value = (uint32_t) ((reg_value & mask) >> shift);

    return reg_value;
}

/** @} (end addtogroup BSP_MCU_PRV) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
