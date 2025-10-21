cmake_minimum_required(VERSION 3.22)

project(demo LANGUAGES C Swift)

add_compile_options(
  "$<$<AND:$<COMPILE_LANGUAGE:Swift>,$<CONFIG:Debug>>:SHELL:-v>"
  "$<$<AND:$<COMPILE_LANGUAGE:Swift>,$<CONFIG:Release>>:SHELL:-wmo -O>"
  "$<$<AND:$<COMPILE_LANGUAGE:Swift>,$<NOT:$<CONFIG:Release>>>:SHELL:-wmo -g -Onone>"
  "$<$<COMPILE_LANGUAGE:Swift>:SHELL:-enable-experimental-feature Embedded>"
  "$<$<COMPILE_LANGUAGE:Swift>:SHELL:-enable-experimental-feature Extern>"
  "$<$<COMPILE_LANGUAGE:Swift>:SHELL:-target $ENV{TARGET}>"
  "$<$<COMPILE_LANGUAGE:Swift>:SHELL:-Xfrontend -function-sections>"
)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")

include_directories(${INCLUDE_DIR})

add_subdirectory(${LIB_DIR}/demo-sys)
add_subdirectory(${LIB_DIR}/demo)

add_subdirectory(${SRC_DIR})
