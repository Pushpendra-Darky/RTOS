idf_component_register(SRCS "2Task_SetPriority_RR.c" INCLUDE_DIRS "")

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
