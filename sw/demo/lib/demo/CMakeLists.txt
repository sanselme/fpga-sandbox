add_library(demoswift STATIC demo.swift)

set_target_properties(demoswift PROPERTIES Swift_MODULE_NAME "DemoSwift")
target_link_libraries(demoswift PUBLIC demosys)

target_compile_options(demoswift PRIVATE
  -parse-as-library
)
