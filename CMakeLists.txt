# SPDX-License-Identifier: Apache-2.0

if(CONFIG_HAS_RENESAS_RA_FSP OR CONFIG_HAS_RENESAS_RZ_FSP OR
   CONFIG_HAS_RENESAS_RAFW_FSP OR CONFIG_SOC_FAMILY_RENESAS_SMARTBOND)
     zephyr_library()
endif()

add_subdirectory_ifdef(CONFIG_SOC_FAMILY_RENESAS_SMARTBOND smartbond)
add_subdirectory_ifdef(CONFIG_BT_DA1453X da1453x)
add_subdirectory(zephyr)
add_subdirectory(drivers)
