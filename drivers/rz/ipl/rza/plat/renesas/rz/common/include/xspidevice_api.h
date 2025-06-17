/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _XSPIDEVICE_API_H_
#define _XSPIDEVICE_API_H_
#include <string.h>
#include <stdbool.h>

#include "xspi_api.h"

/** xSPI device information */
typedef struct st_xspidevice_info
{
	uint32_t	capacity;		/* Amount of memory */
	uint32_t	minimum_erase_size;	/* Minimum erase size (bytes) */
	char		device_vendor[32];	/* Device vendor name */
	char		device_product[32];	/* Device product name */
} xspidevice_info_t;

/** xSPI device configuration */
typedef struct st_xspidevice_cfg
{
	const xspi_instance_t * xspi;		/* Associated xSPI instance */
	void const * extend;		/* Implementation configuration */
} xspidevice_cfg_t;

/** xSPI device control block.  Allocate an implementation specific control block to pass into the xSPI API calls. */
typedef void xspidevice_ctrl_t;

/** xSPI device write status. */
typedef enum xspidevice_write_status
{
	WRITE_STATUS_OK,
	WRITE_STATUS_IN_PROGRESS,
	WRITE_STATUS_PROTECTED,
	WRITE_STATUS_FAIL,
	WRITE_STATUS_SUSPENDED,
	WRITE_STATUS_DISABLED,
} xspidevice_write_status_t;

/** Shared Interface definition for xSPI */
typedef struct st_xspidevice_api
{
	/** Prepare for communicate with SPI device
	 *
	 * @param[in, out] ctrl Control block allocated by user.
	 * @param[in]      cfg  Instance configuration parameter.
	 */
	int (* open)(xspidevice_ctrl_t * ctrl, xspidevice_cfg_t const * cfg);

	/** Clean up the xSPI control block.
	 *
	 * @param[in]  ctrl  Opened control block.
	 */
	int (* close)(xspidevice_ctrl_t * ctrl);

	/** Execute operation.
	 *
	 * @param[in, out] ctrl       Opened control block.
	 * @param[in]      op         Operation structure
	 * @param[in]      is_write   Transaction phase direction is write
	 */
	int (* exec_op)(xspidevice_ctrl_t * ctrl, xspi_op_t const * op, bool is_write);

	/** Entering in-place access mode.
	 *
	 * @param[in, out] ctrl Opened control block.
	 */
	int (* enter_xip)(xspidevice_ctrl_t * ctrl);

	/** Exiting in-place access mode.
	 *
	 * @param[in, out] ctrl Opened control block.
	 */
	int (* exit_xip)(xspidevice_ctrl_t * ctrl);

	/** Get device information.
	 *
	 * @param[in, out] ctrl Opened control block.
	 * @param[out]     info   Pointer to user-provided storage for the device information
	 */
	int (* get_info)(xspidevice_ctrl_t * ctrl, xspidevice_info_t * info);

	/** Read memory
	 *
	 * @param[in, out] ctrl Opened control block.
	 * @param[out]     buffer  Pointer to user-provided storage for the read data
	 * @param[in]      address Start address to read
	 * @param[in]      length  Bytes to read
	 */
	int (* read)(xspidevice_ctrl_t * ctrl, void * buffer, size_t address, size_t length);

	/** Write memory
	 *
	 * @param[in, out] ctrl Opened control block.
	 * @param[in]      buffer  Pointer to user-provided storage for the write data
	 * @param[in]      address Start address to write
	 * @param[in]      length  Bytes to write
	 */
	int (* write)(xspidevice_ctrl_t * ctrl, void const * buffer, size_t address, size_t length);

	/** Erase memory
	 *
	 * @param[in, out] ctrl Opened control block.
	 * @param[in]      address Start address to write
	 * @param[in]      length  Bytes to write
	 */
	int (* erase)(xspidevice_ctrl_t * ctrl, size_t address, size_t length);

	/** Get write status
	 *
	 * @param[in, out] ctrl Opened control block.
	 */
	enum xspidevice_write_status (* get_write_status)(xspidevice_ctrl_t * ctrl);

} xspidevice_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_xspidevice_instance
{
	xspidevice_ctrl_t * ctrl;	/* control structure */
	xspidevice_cfg_t const * cfg;	/* configuration structure */
	xspidevice_api_t const * api;	/* API structure */
} xspidevice_instance_t;

extern const int xspidevices_count;
extern const xspidevice_instance_t * xspidevices[];

#endif	/* _XSPIDEVICE_API_H_ */
