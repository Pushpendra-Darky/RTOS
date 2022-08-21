idf_component_register(SRCS "TaskRTState_Exp.c" INCLUDE_DIRS "")

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
