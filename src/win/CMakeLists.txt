set(WIN_SOURCE api.cpp
        win_win.hpp
        win_mac.hpp
        win_linux.hpp
        win_other.hpp
)
add_library(win_lib ${WIN_SOURCE})
target_include_directories(win_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(win_lib PUBLIC utils_lib)
