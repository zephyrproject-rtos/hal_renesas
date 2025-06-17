#
# Copyright (c) 2024, Renesas Electronics Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
_XSPI_DEVICE:=qspiflash_mx25l25645g
RZ_XSPI_SOURCES:=$(RZ_XSPI_SOURCES) plat/renesas/rz/common/drivers/xspidevice/$(_XSPI_DEVICE)/$(_XSPI_DEVICE).c
PLAT_INCLUDES+=-Iplat/renesas/rz/common/drivers/xspidevice/$(_XSPI_DEVICE)
RZ_XSPI_HEADERS:=$(RZ_XSPI_HEADERS) $(_XSPI_DEVICE)_api.h
