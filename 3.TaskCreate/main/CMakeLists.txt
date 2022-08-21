idf_component_register(SRCS "TaskCreate.c" INCLUDE_DIRS "")

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")