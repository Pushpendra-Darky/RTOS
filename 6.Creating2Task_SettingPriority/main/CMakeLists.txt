idf_component_register(SRCS "2Task_SetPriority.c" INCLUDE_DIRS "")

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
