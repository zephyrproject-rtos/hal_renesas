/*
* Copyright (C) 2014-2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/***********************************************************************************************************************
* File Name    : r_flash_rx.h
* Description  : This is a private header file used internally by the FLASH module. It should not be modified or
*                included by the user in their application.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version Description
*           12.07.2014 1.00    First Release
*           13.01.2015 1.10    Updated for RX231
*           11.02.2016 1.20    Updated for Flash Type 4
*           25.05.2016 1.30    Added FLASH_CUR_CF_BGO_READ/WRITE_LOCKBIT for flash type 3.
*           08.08.2016 2.00    Modified for BSPless operation. Added prototypes for flash_softwareLock()/Unlock().
*                              Added support for RX230.
*           18.11.2016 2.10    Added support for RX24U.
*                              Added equates FLASH_HAS_ERR_ISR and FLASH_HAS_FCU.
*           05.10.2016 3.00    Moved Flash Type 2 specific equates/declarations to r_flash_type2_if.h.
*                              Updated exported variables and functions to reflect updated r_flash_rx.c contents.
*           06.02.2017 3.10    Added support for RX65N-2M (bank/application swap).
*           19.06.2017 3.20    Moved FLASH_HAS_xxx equates to r_flash_rx_if.h
*           31.10.2017 3.30    Added extern for g_flash_lock;
*           27.02.2018 3.40    Added RX66T.
*           23.10.2018 3.50    Added RX72T.
*           19.04.2019 4.00    Removed support for flash type 2.
*           07.06.2019 4.10    Added RX23W.
*           19.07.2019 4.20    Added RX72M.
*           09.09.2019 4.30    Added RX13T.
*           27.09.2019 4.40    Added RX23E-A.
*                              Added include path for rx230.
*           18.11.2019 4.50    Added RX66N, and RX72N.
*           26.06.2020 4.60    Added prototypes for flash_InterruptRequestEnable() and flash_InterruptRequestDisable().
*           23.10.2020 4.70    Added RX671.
*           23.04.2021 4.80    Added RX140.
*           23.12.2021 4.90    Added RX660.
*           24.01.2023 5.00    Added RX26T.
*           28.02.2023 5.10    Added RX23E-B.
*           01.10.2023 5.11    Added support for Tool News R20TS0963.
*           30.07.2024 5.20    Added RX260, and RX261.
*           20.03.2025 5.22    Changed the disclaimer in program sources
***********************************************************************************************************************/

#ifndef FLASH_RX_HEADER_FILE
#define FLASH_RX_HEADER_FILE

#include <stdbool.h>
#include "r_flash_rx_if.h"

/* Memory specifics for the each MCU group */
#if   defined(MCU_RX111)
    #include "./src/targets/rx111/r_flash_rx111.h"
#elif defined(MCU_RX110)
    #include "./src/targets/rx110/r_flash_rx110.h"
#elif defined(MCU_RX113)
    #include "./src/targets/rx113/r_flash_rx113.h"
#elif defined(MCU_RX130)
    #include "./src/targets/rx130/r_flash_rx130.h"
#elif defined(MCU_RX13T)
    #include "./src/targets/rx13t/r_flash_rx13t.h"
#elif defined(MCU_RX140)
    #include "./src/targets/rx140/r_flash_rx140.h"
#elif defined(MCU_RX230)
    #include "./src/targets/rx230/r_flash_rx230.h"
#elif defined(MCU_RX231)
    #include "./src/targets/rx231/r_flash_rx231.h"
#elif defined(MCU_RX23E_A)
    #include "./src/targets/rx23e-a/r_flash_rx23e-a.h"
#elif defined(MCU_RX23E_B)
    #include "./src/targets/rx23e-b/r_flash_rx23e-b.h"
#elif defined(MCU_RX23T)
    #include "./src/targets/rx23t/r_flash_rx23t.h"
#elif defined(MCU_RX23W)
    #include "./src/targets/rx23w/r_flash_rx23w.h"
#elif defined(MCU_RX24T)
    #include "./src/targets/rx24t/r_flash_rx24t.h"
#elif defined(MCU_RX24U)
    #include "./src/targets/rx24u/r_flash_rx24u.h"
#elif defined(MCU_RX260)
    #include "./src/targets/rx260/r_flash_rx260.h"
#elif defined(MCU_RX261)
    #include "./src/targets/rx261/r_flash_rx261.h"
#elif defined(MCU_RX26T)
    #include "./src/targets/rx26t/r_flash_rx26t.h"
#elif defined(MCU_RX64M)
    #include "./src/targets/rx64m/r_flash_rx64m.h"
#elif defined(MCU_RX651) || defined(MCU_RX65N)
    #include "./src/targets/rx65n/r_flash_rx65n.h"
#elif defined(MCU_RX660)
    #include "./src/targets/rx660/r_flash_rx660.h"
#elif defined(MCU_RX66T)
    #include "./src/targets/rx66t/r_flash_rx66t.h"
#elif defined(MCU_RX66N)
    #include "./src/targets/rx66n/r_flash_rx66n.h"
#elif defined(MCU_RX671)
    #include "./src/targets/rx671/r_flash_rx671.h"
#elif defined(MCU_RX71M)
    #include "./src/targets/rx71m/r_flash_rx71m.h"
#elif defined(MCU_RX72T)
    #include "./src/targets/rx72t/r_flash_rx72t.h"
#elif defined(MCU_RX72M)
    #include "./src/targets/rx72m/r_flash_rx72m.h"
#elif defined(MCU_RX72N)
    #include "./src/targets/rx72n/r_flash_rx72n.h"
#else
    #error "!!! No 'targets' folder for this MCU Group !!!"
#endif


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define FCU_COMMAND_AREA                (0x007E0000)


/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
/* These typedefs are used for guaranteeing correct accesses to memory. When
   working with the FCU sometimes byte or word accesses are required. */
typedef R_BSP_VOLATILE_EVENACCESS uint8_t  * FCU_BYTE_PTR;
typedef R_BSP_VOLATILE_EVENACCESS uint16_t * FCU_WORD_PTR;
typedef R_BSP_VOLATILE_EVENACCESS uint32_t * FCU_LONG_PTR;


typedef enum
{
    FLASH_UNINITIALIZED = 0,
    FLASH_INITIALIZATION,
    FLASH_READY,
    FLASH_WRITING,
    FLASH_ERASING,
    FLASH_BLANKCHECK,
    FLASH_GETSTATUS,
    FLASH_LOCK_BIT
} flash_states_t;


typedef enum current
{
    FLASH_CUR_INVALID,
    FLASH_CUR_IDLE,
    FLASH_CUR_DF_ERASE,
    FLASH_CUR_DF_BGO_ERASE,
    FLASH_CUR_DF_BLANKCHECK,
    FLASH_CUR_DF_BGO_BLANKCHECK,
    FLASH_CUR_DF_WRITE,
    FLASH_CUR_DF_BGO_WRITE,
    FLASH_CUR_CF_ERASE,
    FLASH_CUR_CF_BGO_ERASE,
    FLASH_CUR_CF_BLANKCHECK,
    FLASH_CUR_CF_BGO_BLANKCHECK,
    FLASH_CUR_CF_WRITE,
    FLASH_CUR_CF_BGO_WRITE,
    FLASH_CUR_CF_TOGGLE_STARTUPAREA,
    FLASH_CUR_CF_ACCESSWINDOW,
    FLASH_CUR_CF_BGO_READ_LOCKBIT,
    FLASH_CUR_CF_BGO_WRITE_LOCKBIT,
    FLASH_CUR_FCU_INIT,
    FLASH_CUR_LOCKBIT_SET,
    FLASH_CUR_CF_TOGGLE_BANK,
    FLASH_CUR_STOP
} flash_cur_t;


typedef struct _current_parameters
{
    uint32_t    src_addr;               /* Source address for operation in progress */
    uint32_t    dest_addr;              /* Destination address for operation in progress */
    uint32_t    total_count;            /* Total number of bytes to write/erase */
    uint32_t    current_count;          /* Bytes of total completed */
    flash_cur_t current_operation;      /* Operation in progress, ie. FLASH_CUR_CF_ERASE */
    uint16_t    fcu_min_write_cnt;      /* Num 2-byte writes needed for min write size; differs for CF and DF */
    uint32_t    wait_cnt;               /* Worst case wait time for operation completion */
    bool        bgo_enabled_df;
    bool        bgo_enabled_cf;
} current_param_t;


typedef enum
{
    FLASH_LOCKBIT_MODE_NORMAL,
    FLASH_LOCKBIT_MODE_OVERRIDE,
    FLASH_LOCKBIT_MODE_END_ENUM
} lkbit_mode_t;


/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/
extern int32_t g_flash_lock;
extern volatile flash_states_t g_flash_state;
extern FCU_BYTE_PTR g_pfcu_cmd_area;


/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/
extern flash_err_t flash_lock_state(flash_states_t new_state);
extern void flash_release_state(void);
extern bool flash_softwareLock (int32_t * const plock);
extern bool flash_softwareUnlock (int32_t * const plock);
extern void flash_InterruptRequestEnable (uint32_t vector);
extern void flash_InterruptRequestDisable (uint32_t vector);


#endif /* FLASH_RX_HEADER_FILE */

/* end of file */
