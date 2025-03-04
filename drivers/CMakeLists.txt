# SPDX-License-Identifier: Apache-2.0

zephyr_library()
add_subdirectory_ifdef(CONFIG_HAS_RENESAS_RA_FSP ra)
add_subdirectory_ifdef(CONFIG_HAS_RENESAS_RX_RDP rx)
add_subdirectory_ifdef(CONFIG_HAS_RENESAS_RZ_FSP rz)
