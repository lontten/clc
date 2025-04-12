set(SYS_SOURCE api.cpp
        sys_win.hpp
        sys_mac.hpp
        sys_linux.hpp
        sys_other.hpp
)
add_library(sys_lib STATIC ${SYS_SOURCE})
target_include_directories(sys_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(sys_lib PUBLIC utils_lib)
