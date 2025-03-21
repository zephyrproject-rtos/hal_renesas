# SPDX-License-Identifier: Apache-2.0

if(CONFIG_HAS_RENESAS_RA_FSP OR CONFIG_HAS_RENESAS_RZ_FSP OR CONFIG_SOC_FAMILY_RENESAS_SMARTBOND)
  zephyr_library()
endif()

add_subdirectory_ifdef(CONFIG_SOC_FAMILY_RENESAS_SMARTBOND smartbond)
add_subdirectory(zephyr)
add_subdirectory(drivers)
