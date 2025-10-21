# cmake_minimum_required(VERSION 3.14)

# add_subdirectory(bsp bsp)

# include(bsp/toolchain.cmake)

# project(fpga)

# enable_language(ASM)
# enable_language(C)
# enable_language(CXX)

# add_executable(fpga.elf)

# target_sources(fpga.elf
#   PRIVATE
#     main.c
# )

# target_include_directories(fpga.elf
#   PRIVATE
#   PUBLIC
# )

# target_link_libraries(fpga.elf
#   PRIVATE
#     -T "${BspLinkerScript}" -nostdlib
#     "${ExtraArchiveLibraries}"
#     -Wl,--start-group "${BspLibraryName}" -lc -lstdc++ -lgcc -lm -Wl,--end-group
# )

# # Create objdump from ELF.
# set(objdump fpga.elf.objdump)
# add_custom_command(
#   OUTPUT "${objdump}"
#   DEPENDS fpga.elf
#   COMMAND "${ToolchainObjdump}" "${ToolchainObjdumpFlags}" fpga.elf >
#           "${objdump}"
#   COMMENT "Creating ${objdump}."
#   VERBATIM
# )
# add_custom_target(create-objdump ALL DEPENDS "${objdump}")

# # Report space free for stack + heap. Note that the file below is never created
# # so the report is always output on build.
# set(stack_report_file fpga.elf.stack_report)
# add_custom_command(
#   OUTPUT "${stack_report_file}"
#   DEPENDS fpga.elf
#   COMMAND niosv-stack-report -p "${ToolchainPrefix}" fpga.elf
#   COMMENT "Reporting memory available for stack + heap in fpga.elf."
#   VERBATIM
# )
# add_custom_target(niosv-stack-report ALL DEPENDS "${stack_report_file}")

# # Generate HEX file(s) from fpga.elf using elf2hex tool.
# # Note : If ECC Full is enabled, width of 39 is set for NiosV TCM. Otherwise, 32.
# add_custom_command(
#   OUTPUT "niosv_ipcmem.hex"
#   DEPENDS fpga.elf
#   COMMAND elf2hex fpga.elf -o niosv_ipcmem.hex -b 0x10000000 -w 32 -e 0x1003FFFF -r 4
#   COMMENT "Creating niosv_ipcmem.hex."
#   VERBATIM
# )
# add_custom_target(create-hex ALL DEPENDS "niosv_ipcmem.hex")

cmake_minimum_required(VERSION 3.22)

include("${CMAKE_CURRENT_SOURCE_DIR}/../toolchain.cmake")

project("demofpga")
swift_build()
