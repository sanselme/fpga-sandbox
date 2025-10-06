cmake_minimum_required(VERSION 3.22)

project(demo LANGUAGES C Swift)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")

include_directories(${INCLUDE_DIR})

add_subdirectory(${LIB_DIR}/demo-sys)
add_subdirectory(${LIB_DIR}/demo)

add_subdirectory(${SRC_DIR})
