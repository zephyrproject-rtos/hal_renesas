# SPDX-License-Identifier: Apache-2.0

add_subdirectory(ra_cfg)
zephyr_include_directories(
    portable
    portable/inc)

zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_AGT
    portable/src/rp_agt/rp_agt.c)
