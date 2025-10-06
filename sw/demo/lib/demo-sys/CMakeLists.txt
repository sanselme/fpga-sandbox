add_library(demosys STATIC demosys.swift)
set_target_properties(demosys PROPERTIES Swift_MODULE_NAME "DemoSys")
target_compile_options(demosys PUBLIC
  "$<$<COMPILE_LANGUAGE:Swift>:-cxx-interoperability-mode=default>")
