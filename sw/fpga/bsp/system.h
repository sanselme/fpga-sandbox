/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'controller_hart0' in SOPC Builder design 'soc_system'
 * SOPC Builder design path: /home/schubert/workspace/hack/DE10_Standard_GHRD/niosv.sopcinfo
 *
 * Generated: Mon Oct 06 07:38:28 EDT 2025
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "intel_niosv_c"
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_DATA_ADDR_WIDTH 0x20
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HAS_CSR_SUPPORT 0
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x20
#define ALT_CPU_NAME "controller_hart0"
#define ALT_CPU_NIOSV_CORE_VARIANT 4
#define ALT_CPU_NUM_GPR 32
#define ALT_CPU_RESET_ADDR 0x00040000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOSVSMALLCORE_CPU_FREQ 50000000u
#define NIOSVSMALLCORE_DATA_ADDR_WIDTH 0x20
#define NIOSVSMALLCORE_DCACHE_LINE_SIZE 0
#define NIOSVSMALLCORE_DCACHE_LINE_SIZE_LOG2 0
#define NIOSVSMALLCORE_DCACHE_SIZE 0
#define NIOSVSMALLCORE_HAS_CSR_SUPPORT 0
#define NIOSVSMALLCORE_ICACHE_LINE_SIZE 0
#define NIOSVSMALLCORE_ICACHE_LINE_SIZE_LOG2 0
#define NIOSVSMALLCORE_ICACHE_SIZE 0
#define NIOSVSMALLCORE_INST_ADDR_WIDTH 0x20
#define NIOSVSMALLCORE_NIOSV_CORE_VARIANT 4
#define NIOSVSMALLCORE_NUM_GPR 32
#define NIOSVSMALLCORE_RESET_ADDR 0x00040000


/*
 * DEBUG configuration
 *
 */

#define ALT_MODULE_CLASS_DEBUG altera_avalon_jtag_uart
#define DEBUG_BASE 0x10080138
#define DEBUG_IRQ -1
#define DEBUG_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DEBUG_NAME "/dev/DEBUG"
#define DEBUG_READ_DEPTH 64
#define DEBUG_READ_THRESHOLD 8
#define DEBUG_SPAN 8
#define DEBUG_TYPE "altera_avalon_jtag_uart"
#define DEBUG_WRITE_DEPTH 64
#define DEBUG_WRITE_THRESHOLD 8


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_MAILBOX_SIMPLE
#define __ALTERA_AVALON_MUTEX
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __INTEL_NIOSV_C
#define __INTERRUPT_LATENCY_COUNTER


/*
 * ILC configuration
 *
 */

#define ALT_MODULE_CLASS_ILC interrupt_latency_counter
#define ILC_BASE 0x10080000
#define ILC_IRQ -1
#define ILC_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ILC_NAME "/dev/ILC"
#define ILC_SPAN 256
#define ILC_TYPE "interrupt_latency_counter"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/DEBUG"
#define ALT_LOG_PORT_BASE 0x10080138
#define ALT_LOG_PORT_DEV DEBUG
#define ALT_LOG_PORT_IS_JTAG_UART
#define ALT_LOG_PORT_PRESENT
#define ALT_LOG_PORT_TYPE ALTERA_AVALON_JTAG_UART
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERRUPT_CONTROLLERS 0
#define ALT_STDERR "/dev/DEBUG"
#define ALT_STDERR_BASE 0x10080138
#define ALT_STDERR_DEV DEBUG
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/DEBUG"
#define ALT_STDIN_BASE 0x10080138
#define ALT_STDIN_DEV DEBUG
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/DEBUG"
#define ALT_STDOUT_BASE 0x10080138
#define ALT_STDOUT_DEV DEBUG
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSID_BASE SYSID_BASE
#define ALT_SYSID_ID SYSID_ID
#define ALT_SYSTEM_NAME "soc_system"
#define ALT_SYS_CLK_TICKS_PER_SEC CONTROLLER_TIMER_TICKS_PER_SEC
#define ALT_TIMESTAMP_CLK_TIMER_DEVICE_TYPE CONTROLLER_TIMER_TIMER_DEVICE_TYPE


/*
 * btnpio configuration
 *
 */

#define ALT_MODULE_CLASS_btnpio altera_avalon_pio
#define BTNPIO_BASE 0x10080120
#define BTNPIO_BIT_CLEARING_EDGE_REGISTER 1
#define BTNPIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BTNPIO_CAPTURE 1
#define BTNPIO_DATA_WIDTH 4
#define BTNPIO_DO_TEST_BENCH_WIRING 0
#define BTNPIO_DRIVEN_SIM_VALUE 0
#define BTNPIO_EDGE_TYPE "FALLING"
#define BTNPIO_FREQ 50000000
#define BTNPIO_HAS_IN 1
#define BTNPIO_HAS_OUT 0
#define BTNPIO_HAS_TRI 0
#define BTNPIO_IRQ -1
#define BTNPIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BTNPIO_IRQ_TYPE "EDGE"
#define BTNPIO_NAME "/dev/btnpio"
#define BTNPIO_RESET_VALUE 0
#define BTNPIO_SPAN 16
#define BTNPIO_TYPE "altera_avalon_pio"


/*
 * controller_ocmem configuration
 *
 */

#define ALT_MODULE_CLASS_controller_ocmem altera_avalon_onchip_memory2
#define CONTROLLER_OCMEM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define CONTROLLER_OCMEM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define CONTROLLER_OCMEM_BASE 0x40000
#define CONTROLLER_OCMEM_CONTENTS_INFO ""
#define CONTROLLER_OCMEM_DUAL_PORT 0
#define CONTROLLER_OCMEM_GUI_RAM_BLOCK_TYPE "AUTO"
#define CONTROLLER_OCMEM_INIT_CONTENTS_FILE "soc_system_controller_ocmem"
#define CONTROLLER_OCMEM_INIT_MEM_CONTENT 1
#define CONTROLLER_OCMEM_INSTANCE_ID "NONE"
#define CONTROLLER_OCMEM_IRQ -1
#define CONTROLLER_OCMEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CONTROLLER_OCMEM_NAME "/dev/controller_ocmem"
#define CONTROLLER_OCMEM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define CONTROLLER_OCMEM_RAM_BLOCK_TYPE "AUTO"
#define CONTROLLER_OCMEM_READ_DURING_WRITE_MODE "DONT_CARE"
#define CONTROLLER_OCMEM_SINGLE_CLOCK_OP 0
#define CONTROLLER_OCMEM_SIZE_MULTIPLE 1
#define CONTROLLER_OCMEM_SIZE_VALUE 262144
#define CONTROLLER_OCMEM_SPAN 262144
#define CONTROLLER_OCMEM_TYPE "altera_avalon_onchip_memory2"
#define CONTROLLER_OCMEM_WRITABLE 0


/*
 * controller_timer configuration
 *
 */

#define ALT_MODULE_CLASS_controller_timer altera_avalon_timer
#define CONTROLLER_TIMER_ALWAYS_RUN 0
#define CONTROLLER_TIMER_BASE 0x0
#define CONTROLLER_TIMER_COUNTER_SIZE 32
#define CONTROLLER_TIMER_FIXED_PERIOD 0
#define CONTROLLER_TIMER_FREQ 50000000
#define CONTROLLER_TIMER_IRQ -1
#define CONTROLLER_TIMER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CONTROLLER_TIMER_LOAD_VALUE 49999
#define CONTROLLER_TIMER_MULT 0.001
#define CONTROLLER_TIMER_NAME "/dev/controller_timer"
#define CONTROLLER_TIMER_PERIOD 1
#define CONTROLLER_TIMER_PERIOD_UNITS "ms"
#define CONTROLLER_TIMER_RESET_OUTPUT 0
#define CONTROLLER_TIMER_SNAPSHOT 1
#define CONTROLLER_TIMER_SPAN 32
#define CONTROLLER_TIMER_TICKS_PER_SEC 1000
#define CONTROLLER_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define CONTROLLER_TIMER_TIMER_DEVICE_TYPE 1
#define CONTROLLER_TIMER_TYPE "altera_avalon_timer"


/*
 * hal2 configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK CONTROLLER_TIMER
#define ALT_TIMESTAMP_CLK CONTROLLER_TIMER
#define INTEL_FPGA_DFL_START_ADDRESS 0xffffffffffffffff
#define INTEL_FPGA_USE_DFL_WALKER 0


/*
 * ledpio configuration
 *
 */

#define ALT_MODULE_CLASS_ledpio altera_avalon_pio
#define LEDPIO_BASE 0x10080100
#define LEDPIO_BIT_CLEARING_EDGE_REGISTER 0
#define LEDPIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDPIO_CAPTURE 0
#define LEDPIO_DATA_WIDTH 10
#define LEDPIO_DO_TEST_BENCH_WIRING 0
#define LEDPIO_DRIVEN_SIM_VALUE 0
#define LEDPIO_EDGE_TYPE "NONE"
#define LEDPIO_FREQ 50000000
#define LEDPIO_HAS_IN 0
#define LEDPIO_HAS_OUT 1
#define LEDPIO_HAS_TRI 0
#define LEDPIO_IRQ -1
#define LEDPIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDPIO_IRQ_TYPE "NONE"
#define LEDPIO_NAME "/dev/ledpio"
#define LEDPIO_RESET_VALUE 0
#define LEDPIO_SPAN 16
#define LEDPIO_TYPE "altera_avalon_pio"


/*
 * niosv_ipcmem configuration
 *
 */

#define ALT_MODULE_CLASS_niosv_ipcmem altera_avalon_onchip_memory2
#define NIOSV_IPCMEM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define NIOSV_IPCMEM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define NIOSV_IPCMEM_BASE 0x10000000
#define NIOSV_IPCMEM_CONTENTS_INFO ""
#define NIOSV_IPCMEM_DUAL_PORT 1
#define NIOSV_IPCMEM_GUI_RAM_BLOCK_TYPE "AUTO"
#define NIOSV_IPCMEM_INIT_CONTENTS_FILE "soc_system_niosv_ipcmem"
#define NIOSV_IPCMEM_INIT_MEM_CONTENT 1
#define NIOSV_IPCMEM_INSTANCE_ID "NONE"
#define NIOSV_IPCMEM_IRQ -1
#define NIOSV_IPCMEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOSV_IPCMEM_NAME "/dev/niosv_ipcmem"
#define NIOSV_IPCMEM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define NIOSV_IPCMEM_RAM_BLOCK_TYPE "AUTO"
#define NIOSV_IPCMEM_READ_DURING_WRITE_MODE "DONT_CARE"
#define NIOSV_IPCMEM_SINGLE_CLOCK_OP 0
#define NIOSV_IPCMEM_SIZE_MULTIPLE 1
#define NIOSV_IPCMEM_SIZE_VALUE 262144
#define NIOSV_IPCMEM_SPAN 262144
#define NIOSV_IPCMEM_TYPE "altera_avalon_onchip_memory2"
#define NIOSV_IPCMEM_WRITABLE 1


/*
 * niosv_mbox_avmm_msg_receiver configuration
 *
 */

#define ALT_MODULE_CLASS_niosv_mbox_avmm_msg_receiver altera_avalon_mailbox_simple
#define NIOSV_MBOX_AVMM_MSG_RECEIVER_BASE 0x10040000
#define NIOSV_MBOX_AVMM_MSG_RECEIVER_IRQ -1
#define NIOSV_MBOX_AVMM_MSG_RECEIVER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOSV_MBOX_AVMM_MSG_RECEIVER_NAME "/dev/niosv_mbox_avmm_msg_receiver"
#define NIOSV_MBOX_AVMM_MSG_RECEIVER_SPAN 16
#define NIOSV_MBOX_AVMM_MSG_RECEIVER_TYPE "altera_avalon_mailbox_simple"


/*
 * niosv_mbox_avmm_msg_sender configuration
 *
 */

#define ALT_MODULE_CLASS_niosv_mbox_avmm_msg_sender altera_avalon_mailbox_simple
#define NIOSV_MBOX_AVMM_MSG_SENDER_BASE 0x10040010
#define NIOSV_MBOX_AVMM_MSG_SENDER_IRQ -1
#define NIOSV_MBOX_AVMM_MSG_SENDER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOSV_MBOX_AVMM_MSG_SENDER_NAME "/dev/niosv_mbox_avmm_msg_sender"
#define NIOSV_MBOX_AVMM_MSG_SENDER_SPAN 16
#define NIOSV_MBOX_AVMM_MSG_SENDER_TYPE "altera_avalon_mailbox_simple"


/*
 * niosv_mutex configuration
 *
 */

#define ALT_MODULE_CLASS_niosv_mutex altera_avalon_mutex
#define NIOSV_MUTEX_BASE 0x10040020
#define NIOSV_MUTEX_IRQ -1
#define NIOSV_MUTEX_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOSV_MUTEX_NAME "/dev/niosv_mutex"
#define NIOSV_MUTEX_OWNER_INIT 0
#define NIOSV_MUTEX_OWNER_WIDTH 16
#define NIOSV_MUTEX_SPAN 8
#define NIOSV_MUTEX_TYPE "altera_avalon_mutex"
#define NIOSV_MUTEX_VALUE_INIT 0
#define NIOSV_MUTEX_VALUE_WIDTH 16


/*
 * swpio configuration
 *
 */

#define ALT_MODULE_CLASS_swpio altera_avalon_pio
#define SWPIO_BASE 0x10080110
#define SWPIO_BIT_CLEARING_EDGE_REGISTER 1
#define SWPIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWPIO_CAPTURE 1
#define SWPIO_DATA_WIDTH 10
#define SWPIO_DO_TEST_BENCH_WIRING 0
#define SWPIO_DRIVEN_SIM_VALUE 0
#define SWPIO_EDGE_TYPE "ANY"
#define SWPIO_FREQ 50000000
#define SWPIO_HAS_IN 1
#define SWPIO_HAS_OUT 0
#define SWPIO_HAS_TRI 0
#define SWPIO_IRQ -1
#define SWPIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SWPIO_IRQ_TYPE "EDGE"
#define SWPIO_NAME "/dev/swpio"
#define SWPIO_RESET_VALUE 0
#define SWPIO_SPAN 16
#define SWPIO_TYPE "altera_avalon_pio"


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x10080130
#define SYSID_ID -1395322110
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1759523148
#define SYSID_TYPE "altera_avalon_sysid_qsys"

#endif /* __SYSTEM_H_ */
