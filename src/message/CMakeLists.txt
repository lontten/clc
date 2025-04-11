set(MESSAGE_SOURCE api.cpp
        message_win.hpp
        message_mac.hpp
        message_linux.hpp
        message_other.hpp
)
add_library(message_lib STATIC ${MESSAGE_SOURCE})
target_include_directories(message_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(message_lib PUBLIC utils_lib)
