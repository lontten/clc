set(MESSAGE_SOURCE api.cpp
        message_win.hpp
        message_mac.hpp
        message_linux.hpp
        message_other.hpp
)
add_library(message_lib ${MESSAGE_SOURCE})
target_link_libraries(message_lib PUBLIC utils_lib)