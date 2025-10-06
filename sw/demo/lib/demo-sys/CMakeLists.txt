add_library(demosys STATIC demosys.swift runtime.c)
set_target_properties(demosys PROPERTIES Swift_MODULE_NAME "DemoSys")
