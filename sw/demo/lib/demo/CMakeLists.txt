add_library(demoswift STATIC demo.swift)
set_target_properties(demoswift PROPERTIES Swift_MODULE_NAME "DemoSwift")
target_compile_options(demoswift PUBLIC
  "$<$<COMPILE_LANGUAGE:Swift>:-cxx-interoperability-mode=default>")
target_link_libraries(demoswift PUBLIC demosys)
