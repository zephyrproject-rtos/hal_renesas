# SPDX-License-Identifier: Apache-2.0

if(CONFIG_BUILD_WITH_RZA_IPL)
  set(rza_ipl_binary_dir ${CMAKE_BINARY_DIR}/rza_ipl)

  file(MAKE_DIRECTORY ${rza_ipl_binary_dir})

  include(ExternalProject)

  set(rza_ipl_image_info MAP "name: rza_ipl, source-dir: ${CMAKE_CURRENT_SOURCE_DIR}")
  build_info(images VALUE ${rza_ipl_image_info})

  if(CONFIG_RZA_IPL_BUILD_DEBUG)
    set(ipl_build_debug "1")
  else()
    set(ipl_build_debug "0")
  endif()

  ExternalProject_Add(
    rza_ipl
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    BINARY_DIR ${rza_ipl_binary_dir}
    CONFIGURE_COMMAND ""
    BUILD_COMMAND make -C ${CMAKE_CURRENT_SOURCE_DIR}
                  DEBUG=${ipl_build_debug}
                  CROSS_COMPILE=${CROSS_COMPILE}
                  BUILD_BASE=${rza_ipl_binary_dir}
                  PLAT=${RZA_PLAT} BOARD=${RZA_BOARD} all
    INSTALL_COMMAND ""
    BUILD_ALWAYS True
    USES_TERMINAL_BUILD True
  )
endif()
