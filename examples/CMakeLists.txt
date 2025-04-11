option(CLC_BUILD_EXAMPLES "Build clc example projects" ON)

if (CLC_BUILD_EXAMPLES)
    add_subdirectory(hello)
    add_subdirectory(sys_info)
endif ()