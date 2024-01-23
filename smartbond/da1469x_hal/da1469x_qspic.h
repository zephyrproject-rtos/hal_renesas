/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <DA1469xAB.h>
#include <stdbool.h>
#include <stdlib.h>

#define QSPIC_TYPE  QSPIC_Type *
#define QSPIC_ID  	((QSPIC_TYPE)QSPIC_BASE)
#define QSPIC2_ID 	((QSPIC_TYPE)QSPIC2_BASE)

typedef enum qspi_bus_mode {
    QSPI_BUS_MODE_SINGLE = 0x1,
    QSPI_BUS_MODE_DUAL = 0x2,
    QSPI_BUS_MODE_QUAD = 0x4
} qspi_bus_mode_t;

typedef __PACKED_STRUCT qspi_memory_id {
    uint8_t id;
    uint8_t type;
    uint8_t density;
} qspi_memory_id_t;

/**
 * QSPICx enable and set read pipe delay.
 *
 * Calling this routine will enable the read pipe clock delay which introduces a delay
 * in the sampling clock. The delay is relative to the falling edge of the clock signal.
 *
 * @param qspic_id   ID to designate the QSPIC for which the delay will be applied to.
 *                   Valid values are QSPIC_ID and QSPIC2_ID.
 * @param delay      The read pipe delay (should not exceed 7).
 *
 * @note As per the datasheet, when VDD is 0.9V the pipe delay should be assigned to 2 whereas
 *       when VDD is 1.2V the pipe delay should be updated to 7.
 *
 */
void
da1469x_qspi_set_read_pipe_delay(QSPIC_TYPE qspi_id, uint8_t delay);

/**
 * QSPIC2 enable and set Tcem seting.
 *
 * Calling this routine will enable the Tcem value which defines the max. time the #CS
 * line can stay activated in a burst transaction. This max. value is required by a
 * RAM memory device as its auto-refresh mechanism, if supported, usually takes place when
 * the device is inactive.
 *
 * @param sys_clock_freq   Curreny system clock frequency.
 * @param tcem_us          Tcem value in microsends.
 *
 * @note This property is valid for QSPIC2_ID and when the latter is configured to drive
 *       PSRAM memory devices only.
 *
 * @note This property has effect when the controller operates in auto mode.
 *
 */
void
da1469x_qspi_set_tcem(uint32_t sys_clock_freq, uint32_t tcem_us);

/**
 * QSPICx set various #CS timing parameters
 *
 * Calling this routine will configure various timings related to #CS activation.
 *
 * @param qspic_id        ID to designate the QSPIC for which the timing settings will be applied to.
 *                        Valid values are QSPIC_ID and QSPIC2_ID.
 * @param sys_clock_freq  Current system clock frequency.
 * @param read_delay_ns   Min. time, in nanoseconds, the #CS line should remain inactive between
 *                        the transmission of different instructions e.g. write followed by a read
 *                        memory access.
 * @param erase_delay_ns  Min. time, in nanoseconds, the #CS line should remain inactive after the
 *                        execution of a write enable, erase, erase resume or erase suspend instruction.
 *
 * @note This property has effect when the controller operates in auto mode.
 *
 */
void
da1469x_qspi_set_cs_delay(QSPIC_TYPE qspi_id, uint32_t sys_clock_freq,
                                    uint32_t read_delay_ns, uint32_t erase_delay_ns);

/**
 * QSPICx set bus mode
 *
 * Calling this routine will configure the target bus mode used for write/read operations.
 *
 * @param qspic_id        ID to designate the QSPIC for which the bus mode will be applied to.
 *                        Valid values are QSPIC_ID and QSPIC2_ID.
 * @param mode            The selected bus mode
 *
 * @warning This API should be called onlu when the controller is in manual mode. Otherwise, an
 *          assertion will be thrown.
 *
 * @note This API should be called prior to swithcing to the auto mode and when the quad bus mode
 *       is selected. Otherwise, data will not be written/read correctly.
 */
void
da1469x_qspi_set_bus_mode(QSPIC_TYPE qspi_id, qspi_bus_mode_t mode);

/**
 * Reset memory device based on the JEDEC protocol.
 *
 * Calling this routine will initiate a reset sequence using JEDEC op codes.
 *
 * @param qspic_id        ID to designate the QSPIC for which the memory device is connected to.
 *                        Valid values are QSPIC_ID and QSPIC2_ID.
 *
 * @warning This API should be called onlu when the controller is in manual mode. Otherwise, an
 *          assertion will be thrown.
 *
 * @note Typically, after reset, a time interval should be elapsed before the memory can accept
 *       further commands. Programmer is responsible to add the necessary delay based on
 *       manufacturer's datasheet.
 *
 */
void
da1469x_qspi_memory_jedec_reset(QSPIC_TYPE qspi_id);

/**
 * Read memory device ID based on the JEDEC protocol
 *
 * Calling this routine will initiate a device read ID sequence using JEDEC op codes.
 * The programmer should then compare the returned ID sub-fields with the ones provided
 * by manufacturer's datasheet.
 *
 * @param qspic_id        ID to designate the QSPIC for which the memory device is connected to.
 *                        Valid values are QSPIC_ID and QSPIC2_ID.
 * @param id              Pointer to a structure where the ID value should be stored to
 *
 * @warning This API should be called only when the controller is in manual mode. Otherwise, an
 *          assertion will be thrown.
 *
 */
void
da1469x_qspi_memory_jedec_read_id(QSPIC_TYPE qspi_id, qspi_memory_id_t *id);

/**
 * Enter/exit memory device QPI mode
 *
 * Calling this routine will initiate the process to enter/exit the QPI mode, if supported by
 * the underlying memory device. Bus mode will be selected autimatically based on \p enter.
 *
 * @param qspic_id        ID to designate the QSPIC for which the memory device is connected to.
 *                        Valid values are QSPIC_ID and QSPIC2_ID.
 * @param enter           True if the device should enter the QPI mode, false if the device should
 *                        exit the QPI mode.
 * @param cmd             Op code to be sent for the device to enter/exit the QPI mode.
 *
 * @warning This API should be called only when the controller is in manual mode. Otherwise, an
 *          assertion will be thrown.
 *
 */
void
da1469x_qspi_enter_exit_qpi_mode(QSPIC_TYPE qspi_id, bool enter, uint8_t cmd);
