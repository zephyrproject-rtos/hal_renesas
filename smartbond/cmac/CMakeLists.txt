# SPDX-License-Identifier: Apache-2.0

zephyr_library_sources(
  mbox.c
  rand.c
  shm.c
)

zephyr_linker_sources(
        NOINIT
        libcmac/cmac_ram.ld
)
zephyr_linker_sources(
        RODATA
        libcmac/cmac_img.ld
)
zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/../../zephyr/blobs/smartbond/cmac/libcmac/libcmac.a)
