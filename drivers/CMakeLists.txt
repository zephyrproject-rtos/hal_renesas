# SPDX-License-Identifier: Apache-2.0

add_subdirectory_ifdef(CONFIG_HAS_RENESAS_RA_FSP ra)
add_subdirectory_ifdef(CONFIG_HAS_RENESAS_RZ_FSP rz)

if(CONFIG_HAS_RENESAS_RX_RDP OR CONFIG_HAS_RENESAS_RX_FSP)
  add_subdirectory(rx)
endif()

zephyr_include_directories_ifdef(CONFIG_LV_USE_DRAW_DAVE2D tes/dave2d/inc)
