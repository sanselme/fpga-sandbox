# Set up cross-compilation environment
set(CMAKE_SYSTEM_NAME Generic)

# Skip compiler tests since we're cross-compiling
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)

# Define BUILD_TYPE variable, defaulting to debug if not set
set(BUILD_TYPE $ENV{BUILD_TYPE})
if(NOT BUILD_TYPE)
  set(BUILD_TYPE "debug")
endif()

# Set VERBOSE variable from environment or default to OFF
set(VERBOSE $ENV{VERBOSE})
if(NOT VERBOSE)
  set(VERBOSE OFF)
endif()

# Function to build Swift
function(swift_build)
  # Custom target to build using swift build
  add_custom_target(
    ${PROJECT_NAME} ALL
    COMMAND
      swift "build"
        $<$<BOOL:${VERBOSE}>:-v>
        --package-path ${CMAKE_CURRENT_SOURCE_DIR}
        --configuration ${BUILD_TYPE}
        --toolset $ENV{TOOLSET}
        --triple $ENV{TARGET}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building ${PROJECT_NAME} with swiftc"
  )

  # Strip symbols for release builds
  # if(BUILD_TYPE STREQUAL "release")
  #   swift_build_strip()
  # endif()
endfunction()

# Function to strip symbols from Swift build
function(swift_build_strip)
  add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND llvm-strip "${CMAKE_CURRENT_SOURCE_DIR}/.build/${BUILD_TYPE}/lib${PROJECT_NAME}.a"
    COMMENT "Stripping symbols from ${PROJECT_NAME} static library for release build"
  )
endfunction()
