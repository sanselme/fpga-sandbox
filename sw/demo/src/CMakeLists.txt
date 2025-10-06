add_executable(app main.swift)
target_link_libraries(app PRIVATE demoswift demosys)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  add_custom_command(TARGET app POST_BUILD
    COMMAND llvm-strip $<TARGET_FILE:app>
    COMMENT "Stripping symbols from Release binary"
  )
endif()
