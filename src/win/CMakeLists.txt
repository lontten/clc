set(WIN_SOURCE api.cpp
        win_win.hpp
        win_mac.hpp
        win_linux.hpp
        win_other.hpp
)
add_library(win_lib ${WIN_SOURCE})