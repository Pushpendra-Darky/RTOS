idf_component_register(SRCS "EventGroup_or.c" INCLUDE_DIRS "")

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
