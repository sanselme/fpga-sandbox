cmake_minimum_required(VERSION 3.22)

include("${CMAKE_CURRENT_SOURCE_DIR}/../toolchain.cmake")

project("demo")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/demo-sys)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/demo)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app)
